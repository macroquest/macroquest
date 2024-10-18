/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2022 MacroQuest Authors
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2, as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

// Uncomment to see super spammy read/write trace logging
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE

#include "loader/MacroQuest.h"
#include "loader/PostOffice.h"
#include "routing/PostOffice.h"

#include <date/date.h>
#include <fmt/format.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/wincolor_sink.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <shellapi.h>

#include <variant>

 // TODO: callbacks can likely be simplified to just making sure we carry the sequence ID back to the source, which will do the callback lookup there

static std::unordered_map<uint32_t, PostOfficeConfig> s_postOfficeConfigs;

namespace mq::postoffice {

bool LauncherPostOffice::IsRecipient(const proto::routing::Address& address, const ActorIdentification& id)
{
	SPDLOG_TRACE("{}: Testing address {} against id {}", GetName(), address.ShortDebugString(), id.ToString());

	return std::visit(overload{
		[&address](uint32_t pid)
		{
			return (address.has_pid() && address.pid() == pid) ||
				(!address.has_peer() && !address.has_pid());
		},
		[&address](const ActorContainer::Network& network)
		{
			return (address.has_peer() && address.peer().ip() == network.IP && address.peer().port() == network.Port) ||
				(!address.has_peer() && !address.has_pid());
		}
		}, id.container.value) && std::visit(overload{
		[&address](const std::string& name) { return address.has_name() && ci_equals(name, address.name()); },
		[&address](const ActorIdentification::Client& client)
		{
			return address.has_client() &&
				(!address.client().has_account() || ci_equals(client.account, address.client().account())) &&
				(!address.client().has_server() || ci_equals(client.server, address.client().server())) &&
				(!address.client().has_character() || ci_equals(client.character, address.client().character()));
		}
		}, id.address);
}

auto LauncherPostOffice::FindIdentity(
	const proto::routing::Address& address,
	const std::unordered_multimap<ActorContainer, ActorIdentification>::iterator& from)
{
	return std::find_if(from, m_identities.end(),
		[&address, this](const std::pair<ActorContainer, ActorIdentification>& pair)
		{ return IsRecipient(address, pair.second); });
}

proto::routing::Envelope FillAddress(const proto::routing::Envelope& message, const ActorIdentification& identity)
{
	proto::routing::Envelope e(message);
	proto::routing::Address& address = *e.mutable_address();
	identity.BuildAddress(address); // then set the identity's address

	return e;
}

// This is called when a dropbox registered to this post office attempts to send a message
void LauncherPostOffice::RouteMessage(proto::routing::Envelope&& message)
{
	const auto& address = message.address();

	SPDLOG_TRACE("{}: Routing message to {} seq={}", GetName(), address.ShortDebugString(), message.sequence());

	// if we have a PID here, we could still have multiple names on the same PID, so we can't
	// avoid the loop
	if (message.mode() == static_cast<uint32_t>(MQRequestMode::CallAndResponse))
	{
		const auto identity = FindIdentity(message.address(), m_identities.begin());

		if (identity == m_identities.end())
			RoutingFailed(MsgError_RoutingFailed, std::move(message), "Failed to find identity in post office");
		else if (FindIdentity(message.address(), std::next(identity)) != m_identities.end())
			RoutingFailed(MsgError_AmbiguousRecipient, std::move(message), "Multiple recipients match identity");
		else
			SendMessage(identity->first, std::move(message));
	}
	else
	{
		// we don't have a PID or a name and this is not an RPC, so we will send this message to 
		// all clients that match the address -- it's important to copy these messages
		for (const auto& identity : m_identities)
		{
			if (IsRecipient(address, identity.second))
				SendMessage(identity.first, FillAddress(message, identity.second));
		}
	}
}

void LauncherPostOffice::AddIdentity(const ActorIdentification& id)
{
	// make sure we remove any duplicates without broadcasting
	for (auto ident_it = m_identities.begin(); ident_it != m_identities.end();)
	{
		if (ident_it->second.IsDuplicate(id))
			ident_it = m_identities.erase(ident_it);
		else
			++ident_it;
	}

	m_identities.emplace(id.container, id);
	SPDLOG_INFO("{}: Got identification from {}", GetName(), id);

	// TODO: this is maybe too aggressive? not sure how else to make identities idempotent
	// we also need to update all the clients
	for (const auto& identity : m_identities)
	{
		if (!identity.second.IsDuplicate(id) && !identity.second.IsDuplicate(m_id))
			SendIdentification(identity.first, id);
	}
}

void LauncherPostOffice::DropIdentity(const ActorIdentification& id)
{
	for (auto ident_it = m_identities.begin(); ident_it != m_identities.end();)
	{
		if (ident_it->second.IsDuplicate(id))
			ident_it = m_identities.erase(ident_it);
		else
			++ident_it;
	}

	for (const auto& identity : m_identities)
		DropIdentification(identity.first, id);
}

void LauncherPostOffice::DropContainer(const ActorContainer& container)
{
	std::vector<ActorIdentification> to_erase;
	const auto range = m_identities.equal_range(container);
	for (auto it = range.first; it != range.second; ++it)
		to_erase.emplace_back(std::move(it->second));

	m_identities.erase(container);

	for (const auto& [container, _] : m_identities)
		for (const auto &dropped : to_erase)
			DropIdentification(container, dropped);
}

void LauncherPostOffice::SendIdentities(const ActorContainer& requester)
{
	for (const auto& [_, client] : m_identities)
		SendIdentification(requester, client);
}

// TODO: add callback handling to this as well
void LauncherPostOffice::RouteFromConnection(proto::routing::Envelope&& message)
{
	// it's safe to assume that any RPC requests will get routed back to the originating connection, so there is no
	// need to handle callbacks here, we can just allow the connections to handle them when the reply is sent back
	// over the connection (via route). What we _do_ need here is early detection of multiple recipients if the
	// message is an RPC and sending it back if it's ambiguous

	SPDLOG_TRACE("{}: Routing received message: to={} from={} seq={}", GetName(),
		message.address().has_name() ? message.address().name() : message.address().client().character(),
		message.has_return_address() ? (message.return_address().has_name() ? message.return_address().name() : message.return_address().client().character()) : "unk",
		message.sequence());

	const auto& address = message.address();

	if (address.has_pid() && address.pid() == GetCurrentProcessId() && address.has_name() && address.name() == "launcher")
	{
		// we are explicitly sending to this launcher, so route entirely internally
		const auto mailbox = address.has_mailbox() ? address.mailbox() : "post_office";
		SPDLOG_TRACE("{}: Internal pipe message received in launcher, routing to mailbox {} seq={}", GetName(), mailbox, message.sequence());

		// This is already an explicit address, so just package up the envelope into a message and deliver it
		DeliverTo(mailbox, std::move(message));
	}
	else if (address.has_pid() || (address.has_peer() && address.peer().ip() == "127.0.0.1" && address.peer().port() == m_peerConnection->GetPort()))
	{
		// this message is intended to be routed locally and not relayed to external peers
		SPDLOG_TRACE("{}: Routing message to local connections ({}) seq={}", GetName(), address.has_name() ? address.name() : address.client().character(), message.sequence());
		proto::routing::Address local_address;
		local_address.set_mailbox(address.mailbox());
		if (address.has_name())
			local_address.set_name(address.name());
		else if (address.has_client())
			*local_address.mutable_client() = address.client();

		if (message.mode() == static_cast<uint32_t>(MQRequestMode::CallAndResponse) && std::count_if(m_identities.begin(), m_identities.end(),
			[&local_address, this](const std::pair<ActorContainer, ActorIdentification>& identity)
			{ return identity.first.IsLocal() && IsRecipient(local_address, identity.second); }) > 1)
		{
			RoutingFailed(MsgError_AmbiguousRecipient, std::move(message), "Multiple recipients match identity");
		}
		else
		{
			for (const auto& identity : m_identities)
			{
				if (identity.first.IsLocal() && IsRecipient(local_address, identity.second))
				{
					RouteMessage(FillAddress(message, identity.second));
				}
			}
		}
	}
	else
	{
		// This message isn't addressed specifically to a container, so find all identities that
		// should receive this message and send to each one
		SPDLOG_TRACE("{}: Routing message to {} seq={}", GetName(), address.has_name() ? address.name() : address.client().character(), message.sequence());
		if (message.mode() == static_cast<uint32_t>(MQRequestMode::CallAndResponse) && std::count_if(m_identities.begin(), m_identities.end(),
			[&address, this](const std::pair<ActorContainer, ActorIdentification>& identity)
			{ return IsRecipient(address, identity.second); }) > 1)
		{
			RoutingFailed(MsgError_AmbiguousRecipient, std::move(message), "Multiple recipients match identity");
		}
		else
		{
			for (const auto& identity : m_identities)
			{
				if (IsRecipient(address, identity.second))
				{
					RouteMessage(FillAddress(message, identity.second));
				}
			}
		}
	}

	{
		std::lock_guard<std::mutex> lock(m_processMutex);
		m_hasMessages = true;
	}

	m_needsProcessing.notify_one();
}

void LauncherPostOffice::OnDeliver(const std::string& localAddress, proto::routing::Envelope& message)
{
	{
		std::lock_guard<std::mutex> lock(m_processMutex);
		m_hasMessages = true;
	}

	m_needsProcessing.notify_one();
}

void LauncherPostOffice::Initialize()
{
	// request IDs from all pre-existing connections
	// we could theoretically just ask a single peer but this will guarantee we have all
	// potential addresses
	for (const auto& [container, id] : m_identities)
		if (!m_id.IsDuplicate(id)) RequestIdentities(container);
}

void LauncherPostOffice::Shutdown()
{
}

void LauncherPostOffice::RequestProcessEvents()
{
	{
		std::lock_guard<std::mutex> lock(m_processMutex);
		m_hasMessages = true;
	}

	m_needsProcessing.notify_one();
}


LauncherPostOffice::LauncherPostOffice(const PostOfficeConfig& config)
	: PostOffice(ActorIdentification(GetCurrentProcessId(), "launcher"))
	, m_config(config)
	, m_localConnection(std::make_unique<LocalConnection>(this))
	, m_peerConnection(std::make_unique<PeerConnection>(this))
{
	m_identities.emplace(m_id.container, m_id);

	m_peerConnection->AddConfiguredHosts();

	m_thread = std::thread(
		[this]
		{

			using fSetThreadDescription = HRESULT(WINAPI*)(HANDLE, PCWSTR);
			auto SetThreadDescription = (fSetThreadDescription)GetProcAddress(GetModuleHandleA("kernel32.dll"), "SetThreadDescription");
			if (SetThreadDescription)
				SetThreadDescription(GetCurrentThread(), L"PostOffice");

			m_running = true;
			m_threadId = std::this_thread::get_id();

			m_localConnection->Start();
			m_peerConnection->Start();

			do
			{
				{
					std::unique_lock<std::mutex> lock(m_processMutex);
					m_needsProcessing.wait(lock, [this] { return m_hasMessages || !m_running; });
				}

				if (!m_running)
					break;

				m_localConnection->Process();
				m_peerConnection->Process();

				// OnIncomingMessage is only called from this thread. If we ever have another source of messages
				// (ie, network messages) then we will need to be careful about making sure Deliver and Process
				// are always called from the same thread to avoid race conditions
				Process(10);

				{
					std::unique_lock<std::mutex> lock(m_processMutex);
					m_hasMessages = false;
				}
			} while (m_running);

			m_localConnection->Stop();
			m_peerConnection->Stop();
		}
	);
}

LauncherPostOffice::~LauncherPostOffice()
{
	// we don't need to worry about sending messages after we stop because the connections should log
	// and handle this situation.
	m_running = false;
	m_needsProcessing.notify_one();
	m_thread.join();
}

template <>
const std::unique_ptr<LocalConnection>& LauncherPostOffice::GetConnection<uint32_t>()
{
	return m_localConnection;
}

template <>
const std::unique_ptr<PeerConnection>& LauncherPostOffice::GetConnection<ActorContainer::Network>()
{
	return m_peerConnection;
}

template <size_t I>
void LauncherPostOffice::ProcessConnections()
{
	using V = std::remove_const_t<decltype(ActorContainer::value)>;
	if constexpr (I < std::variant_size_v<V>)
	{
		GetConnection<std::variant_alternative_t<I, V>>()->Process();
		ProcessConnections<I + 1>();
	}
}

template <size_t I>
void LauncherPostOffice::BroadcastMessage(proto::routing::Envelope&& message)
{
	using V = std::remove_const_t<decltype(ActorContainer::value)>;
	if constexpr (I < std::variant_size_v<V>)
	{
		// copy the message for broadcasting on each connection
		GetConnection<std::variant_alternative_t<I, V>>()->BroadcastMessage(message);
		BroadcastMessage<I + 1>(std::move(message));
	}
}

bool LauncherPostOffice::SendMessage(const ActorContainer& ident, proto::routing::Envelope&& message)
{
	SPDLOG_TRACE("{}: Sending message to {} seq={}", GetName(), ident, message.sequence());
	return std::visit([this, message = std::move(message)](const auto& c) mutable
		{
			return GetConnection<std::remove_const_t<std::remove_reference_t<decltype(c)>>>()->SendMessage(c, std::move(message));
		}, ident.value);
}

void LauncherPostOffice::SendIdentification(const ActorContainer& target, const ActorIdentification& id)
{
	SPDLOG_TRACE("{}: Sending identification {} to {}", GetName(), id, target);
	return std::visit([this, &id](const auto& c) mutable
		{
			return GetConnection<std::remove_const_t<std::remove_reference_t<decltype(c)>>>()->SendIdentification(c, id);
		}, target.value);
}

void LauncherPostOffice::DropIdentification(const ActorContainer& target, const ActorIdentification& id)
{
	SPDLOG_TRACE("{}: Dropping identification {} from {}", GetName(), id, target);
	return std::visit([this, &id](const auto& c) mutable
		{
			return GetConnection<std::remove_const_t<std::remove_reference_t<decltype(c)>>>()->DropIdentification(c, id);
		}, target.value);
}

void LauncherPostOffice::RequestIdentities(const ActorContainer& from)
{
	SPDLOG_TRACE("{}: Requesting identities from {}", GetName(), from);
	return std::visit([this](const auto& c) mutable
		{
			return GetConnection<std::remove_const_t<std::remove_reference_t<decltype(c)>>>()->RequestIdentities(c);
		}, from.value);
}

void Connection::RequestProcessEvents()
{
	m_postOffice->RequestProcessEvents();
}

} // namespace mq::postoffice

// this map is exclusively to allow testing by standing up multiple post offices
static std::unordered_map<uint32_t, postoffice::LauncherPostOffice> s_postOffices;
template <>
postoffice::LauncherPostOffice& postoffice::GetPostOffice<postoffice::LauncherPostOffice>(uint32_t index)
{
	auto it = s_postOffices.find(index);
	if (it == s_postOffices.end())
		it = s_postOffices.emplace(index, GetPostOfficeConfig(index)).first;

	return it->second;
}

template <>
postoffice::PostOffice& postoffice::GetPostOffice<postoffice::PostOffice>(uint32_t index)
{
	return postoffice::GetPostOffice<postoffice::LauncherPostOffice>(index);
}

//----------------------------------------------------------------------------
// HELPER FUNCTIONS -- try to minimize refactoring
//----------------------------------------------------------------------------

bool SendSetForegroundWindow(HWND hWnd, uint32_t processID)
{
	using namespace postoffice;
	return GetPostOffice<LauncherPostOffice>().GetConnection<uint32_t>()->SendSetForegroundWindow(hWnd, processID);
}

void SendUnloadAllCommand()
{
	using namespace postoffice;
	GetPostOffice<LauncherPostOffice>().GetConnection<uint32_t>()->SendUnloadAllCommand();
}

void SendForceUnloadAllCommand()
{
	using namespace postoffice;
	GetPostOffice<LauncherPostOffice>().GetConnection<uint32_t>()->SendForceUnloadAllCommand();
}

//----------------------------------------------------------------------------

const PostOfficeConfig& GetPostOfficeConfig(uint32_t index)
{
	const auto config = s_postOfficeConfigs.find(index);
	if (config != s_postOfficeConfigs.end())
		return config->second;

	static PostOfficeConfig s_defaultPostOfficeConfig;
	return s_defaultPostOfficeConfig;
}

void SetPostOfficeConfig(uint32_t index, const PostOfficeConfig& config)
{
	s_postOfficeConfigs[index] = config;
}

void DropPostOfficeConfig(uint32_t index)
{
	s_postOfficeConfigs.erase(index);
}

void ClearPostOfficeConfigs()
{
	s_postOfficeConfigs.clear();
}

void ClearPostOffices()
{
	for (auto& [_, post_office] : s_postOffices)
		post_office.Shutdown();

	s_postOffices.clear();
}

void InitializePostOffice(uint32_t index)
{
	using namespace postoffice;
	GetPostOffice<LauncherPostOffice>(index).Initialize();
}

void ShutdownPostOffice(uint32_t index)
{
	using namespace postoffice;
	GetPostOffice<LauncherPostOffice>(index).Shutdown();
	s_postOffices.erase(index);
}

//----------------------------------------------------------------------------

