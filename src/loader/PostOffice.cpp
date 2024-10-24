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
//#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE

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

void RemovePostOffice(uint32_t index);

namespace mq::postoffice {

bool LauncherPostOffice::IsRecipient(const proto::routing::Address& address, const ActorIdentification& id)
{
	SPDLOG_TRACE("{}: Testing address [{}] against id [{}]", GetName(), address.ShortDebugString(), id.ToString());

	std::string uuid;
	if (address.has_process())
		uuid = address.process().uuid();
	else if (address.has_peer())
		uuid = address.peer().uuid();

	return std::visit(overload{
		[&address, &uuid](const ActorContainer::Process& proc)
		{
			if (!uuid.empty() && proc.UUID != uuid)
				return false;

			if (!address.has_peer() && !address.has_process())
				return true;

			return (address.has_process() && address.process().pid() == proc.PID);
		},
		[&address, &uuid](const ActorContainer::Network& network)
		{
			if (!uuid.empty() && network.UUID != uuid)
				return false;

			if (!address.has_peer() && !address.has_process())
				return true;

			return (address.has_peer() && address.peer().ip() == network.IP && address.peer().port() == network.Port);
		}
	}, id.container.value) && std::visit(overload{
		[&address](const std::string& name)
		{
			if (!address.has_name() && !address.has_client())
				return true;

			return (address.has_name() && ci_equals(name, address.name()));
		},
		[&address](const ActorIdentification::Client& client)
		{
			if (!address.has_name() && !address.has_client())
				return true;

			return (address.has_client() &&
				(!address.client().has_account() || ci_equals(client.account, address.client().account())) &&
				(!address.client().has_server() || ci_equals(client.server, address.client().server())) &&
				(!address.client().has_character() || ci_equals(client.character, address.client().character())));
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

MessagePtr FillAddress(MessagePtr message, const ActorIdentification& identity)
{
	proto::routing::Address& address = *message->mutable_address();
	identity.BuildAddress(address);

	return message;
}

// This is called when a dropbox registered to this post office attempts to send a message
void LauncherPostOffice::RouteMessage(MessagePtr message)
{
	if (std::this_thread::get_id() == m_threadId)
	{
		ProcessOutgoingMessage(std::move(message));
	}
	else
	{
		{
			std::unique_lock lock(m_outgoingMutex);
			m_outgoingMessages.push_back(std::move(message));
		}

		RequestProcessEvents();
	}
}

void LauncherPostOffice::ProcessOutgoing()
{
	std::unique_lock lock(m_outgoingMutex);

	if (!m_outgoingMessages.empty())
	{
		std::vector<MessagePtr> outgoing;
		std::swap(outgoing, m_outgoingMessages);

		lock.unlock();

		for (auto& message : outgoing)
			ProcessOutgoingMessage(std::move(message));
	}
}

void LauncherPostOffice::ProcessOutgoingMessage(MessagePtr message)
{
	SPDLOG_TRACE("{}: Routing message to {} seq={}", GetName(), message->address().ShortDebugString(), message->sequence());

	// if we have a PID here, we could still have multiple names on the same PID, so we can't
	// avoid the loop
	if (message->mode() == static_cast<uint32_t>(MQRequestMode::CallAndResponse))
	{
		const auto identity = FindIdentity(message->address(), m_identities.begin());

		if (identity == m_identities.end())
			RoutingFailed(MsgError_RoutingFailed, std::move(message), "Failed to find identity in post office");
		else if (FindIdentity(message->address(), std::next(identity)) != m_identities.end())
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
			if (IsRecipient(message->address(), identity.second))
				SendMessage(identity.first, FillAddress(std::make_unique<proto::routing::Envelope>(*message), identity.second));
		}
	}
}

void LauncherPostOffice::ProcessIdentities()
{
	std::unique_lock lock(m_identityMutex);

	if (!m_identityActions.empty())
	{
		std::vector<std::pair<IdentityAction, ActorIdentification>> actions;
		std::swap(actions, m_identityActions);

		lock.unlock();

		for (auto& [action, id] : actions)
		{
			switch (action)
			{
			case IdentityAction::Add:
				ProcessAddIdentity(id);
				break;

			case IdentityAction::MassAdd:
				ProcessSendIdentities(id.container);
				break;

			case IdentityAction::Drop:
				ProcessDropIdentity(id);
				break;

			case IdentityAction::MassDrop:
				ProcessDropContainer(id.container);
				break;

			default: break;
			}
		}
	}
}

void LauncherPostOffice::AddIdentity(const ActorIdentification& id)
{
	if (std::this_thread::get_id() == m_threadId)
	{
		ProcessAddIdentity(id);
	}
	else
	{
		{
			std::unique_lock lock(m_identityMutex);
			m_identityActions.emplace_back(IdentityAction::Add, id);
		}

		RequestProcessEvents();
	}
}

void LauncherPostOffice::ProcessAddIdentity(const ActorIdentification& id)
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
	// we also need to update all the clients, but only if this was received from a local connection
	if (id.container.IsLocal())
	{
		for (const auto& [container, identity] : m_identities)
			if (!identity.IsDuplicate(id) && !identity.IsDuplicate(m_id))
				SendIdentification(container, id);
	}
}

void LauncherPostOffice::DropIdentity(const ActorIdentification& id)
{
	if (std::this_thread::get_id() == m_threadId)
	{
		ProcessDropIdentity(id);
	}
	else
	{
		{
			std::unique_lock lock(m_identityMutex);
			m_identityActions.emplace_back(IdentityAction::Drop, id);
		}

		RequestProcessEvents();
	}
}

void LauncherPostOffice::ProcessDropIdentity(const ActorIdentification& id)
{
	for (auto ident_it = m_identities.begin(); ident_it != m_identities.end();)
	{
		if (ident_it->second.IsDuplicate(id))
			ident_it = m_identities.erase(ident_it);
		else
			++ident_it;
	}

	for (const auto& [container, identity] : m_identities)
		if (!identity.IsDuplicate(m_id))
			DropIdentification(container, id);
}

void LauncherPostOffice::DropContainer(const ActorContainer& container)
{
	if (std::this_thread::get_id() == m_threadId)
	{
		ProcessDropContainer(container);
	}
	else
	{
		{
			std::unique_lock lock(m_identityMutex);
			m_identityActions.emplace_back(IdentityAction::MassDrop, ActorIdentification{container, ""});
		}

		RequestProcessEvents();
	}
}

void LauncherPostOffice::ProcessDropContainer(const ActorContainer& container)
{
	std::vector<ActorIdentification> to_erase;
	const auto range = m_identities.equal_range(container);
	for (auto it = range.first; it != range.second; ++it)
		to_erase.emplace_back(std::move(it->second));

	m_identities.erase(container);

	for (const auto& [container, identity] : m_identities)
		if (!identity.IsDuplicate(m_id))
			for (const auto& dropped : to_erase)
				DropIdentification(container, dropped);
}

void LauncherPostOffice::SendIdentities(const ActorContainer& requester)
{
	if (std::this_thread::get_id() == m_threadId)
	{
		ProcessSendIdentities(requester);
	}
	else
	{
		{
			std::unique_lock lock(m_identityMutex);
			m_identityActions.emplace_back(IdentityAction::MassAdd, ActorIdentification{requester, ""});
		}

		RequestProcessEvents();
	}
}

void LauncherPostOffice::ProcessSendIdentities(const ActorContainer& requester)
{
	for (const auto& [_, client] : m_identities)
		SendIdentification(requester, client);
}

void LauncherPostOffice::FillAndSend(MessagePtr message, std::function<bool(const ActorIdentification&)> predicate)
{
	std::vector<const ActorIdentification*> identities;
	for (const auto& [_, identity] : m_identities)
	{
		if (predicate(identity))
			identities.emplace_back(&identity);
	}

	if (message->mode() == static_cast<uint32_t>(MQRequestMode::CallAndResponse) && identities.size() != 1)
	{
		if (identities.size() > 1)
			RoutingFailed(MsgError_AmbiguousRecipient, std::move(message), "Multiple recipients match identity");
		else
			RoutingFailed(MsgError_RoutingFailed, std::move(message), "No recipients match identity");
	}
	else if (identities.size() == 1)
	{
		// minor optimization, this lets us move
		auto identity = identities.front();
		SendMessage(identity->container, FillAddress(std::move(message), *identity));
	}
	else
	{
		for (auto identity : identities)
			SendMessage(identity->container, FillAddress(std::make_unique<proto::routing::Envelope>(*message), *identity));
	}
}

void LauncherPostOffice::RouteFromConnection(MessagePtr message)
{
	// it's safe to assume that any RPC requests will get routed back to the originating connection, so there is no
	// need to handle callbacks here, we can just allow the connections to handle them when the reply is sent back
	// over the connection (via route). What we _do_ need here is early detection of multiple recipients if the
	// message is an RPC and sending it back if it's ambiguous

	SPDLOG_TRACE("{}: Routing received message: to=[{}] from=[{}] seq={}", GetName(),
		message->address().ShortDebugString(), message->return_address().ShortDebugString(), message->sequence());

	const auto& address = message->address();

	std::string uuid;
	if (address.has_process())
		uuid = address.process().uuid();
	else if (address.has_peer())
		uuid = address.peer().uuid();

	if ((!uuid.empty() && uuid == m_id.container.GetUUID()) ||
		uuid.empty() && address.has_process() && address.process().pid() == GetCurrentProcessId() && address.has_name() && address.name() == "launcher")
	{
		// we are explicitly sending to this launcher, so route entirely internally
		const auto mailbox = address.has_mailbox() ? address.mailbox() : "post_office";
		SPDLOG_TRACE("{}: Internal pipe message received in launcher, routing to mailbox {} seq={}", GetName(), mailbox, message->sequence());

		// This is already an explicit address, so just package up the envelope into a message and deliver it
		DeliverTo(mailbox, std::move(message));
	}
	else if (address.has_process() || (address.has_peer() && address.peer().ip() == "127.0.0.1" && address.peer().port() == m_peerConnection->GetPort()))
	{
		// this message is intended to be routed locally and not relayed to external peers
		SPDLOG_TRACE("{}: Routing message to local connections ({}) seq={}", GetName(), address.ShortDebugString(), message->sequence());
		proto::routing::Address local_address;
		local_address.set_mailbox(address.mailbox());
		if (address.has_name())
			local_address.set_name(address.name());
		else if (address.has_client())
			*local_address.mutable_client() = address.client();

		FillAndSend(std::move(message),
			[&local_address, this](const auto& identity)
			{ return identity.container.IsLocal() && IsRecipient(local_address, identity); });
	}
	else
	{
		// This message isn't addressed specifically to a container, so find all identities that
		// should receive this message and send to each one
		SPDLOG_TRACE("{}: Routing message to [{}] seq={}", GetName(), address.ShortDebugString(), message->sequence());

		FillAndSend(std::move(message),
			[&address, this](const auto& identity)
			{ return IsRecipient(address, identity); });
	}

	RequestProcessEvents();
}

void LauncherPostOffice::OnDeliver(const std::string& localAddress, MessagePtr& message)
{
	RequestProcessEvents();
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
	m_running = false;
}

void LauncherPostOffice::RequestProcessEvents()
{
	{
		std::unique_lock<std::mutex> lock(m_processMutex);
		m_hasMessages = true;
	}

	m_needsProcessing.notify_one();
}

LauncherPostOffice::LauncherPostOffice(const PostOfficeConfig& config)
	: PostOffice(ActorIdentification(ActorContainer::Process{ GetCurrentProcessId(), CreateUUID() }, "launcher"))
	, m_config(config)
	, m_localConnection(std::make_unique<LocalConnection>(this))
	, m_peerConnection(std::make_unique<PeerConnection>(this))
{
	m_thread = std::thread(
		[this]
		{
			m_identities.emplace(m_id.container, m_id);

			m_peerConnection->AddConfiguredHosts();

			using fSetThreadDescription = HRESULT(WINAPI*)(HANDLE, PCWSTR);
			fSetThreadDescription SetThreadDescription = nullptr;
			if (auto kernel = GetModuleHandleA("kernel32.dll"))
				SetThreadDescription = (fSetThreadDescription)GetProcAddress(kernel, "SetThreadDescription");

			if (SetThreadDescription)
				SetThreadDescription(GetCurrentThread(), L"PostOffice");

			m_running = true;
			m_threadId = std::this_thread::get_id();

			StartConnections();

			do
			{
				{
					std::unique_lock<std::mutex> lock(m_processMutex);
					m_needsProcessing.wait(lock, [this] { return  m_hasMessages || !m_running; });
					
					// set this before we process to allow for processes to request additional processing
					m_hasMessages = false;
				}

				SPDLOG_TRACE("{}: Found needs processing", GetName());

				ProcessIdentities(); // handles all identification maintenance

				ProcessOutgoing(); // handles any messages posted from the internal dropbox

				// It's important that this call is the only trigger for the connections incoming messages
				// that get handed off to RouteFromConnections. For local connections, it's OnIncomingMessage
				// and for network connections its the receive callback specified during construction
				// of the connection
				ProcessConnections(); // handles all incoming messages from connections

				Process(10); // processes the messages waiting in the internal dropbox (shouldn't happen often)
			} while (m_running);

			StopConnections();
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
const std::unique_ptr<LocalConnection>& LauncherPostOffice::GetConnection<ActorContainer::Process>()
{
	return m_localConnection;
}

template <>
const std::unique_ptr<PeerConnection>& LauncherPostOffice::GetConnection<ActorContainer::Network>()
{
	return m_peerConnection;
}

template <size_t I>
void LauncherPostOffice::StartConnections()
{
	using V = std::remove_const_t<decltype(ActorContainer::value)>;
	if constexpr (I < std::variant_size_v<V>)
	{
		GetConnection<std::variant_alternative_t<I, V>>()->Start();
		StartConnections<I + 1>();
	}
}

template <size_t I>
void LauncherPostOffice::StopConnections()
{
	using V = std::remove_const_t<decltype(ActorContainer::value)>;
	if constexpr (I < std::variant_size_v<V>)
	{
		GetConnection<std::variant_alternative_t<I, V>>()->Stop();
		StopConnections<I + 1>();
	}
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
void LauncherPostOffice::BroadcastMessage(MessagePtr message)
{
	using V = std::remove_const_t<decltype(ActorContainer::value)>;
	if constexpr (I < std::variant_size_v<V>)
	{
		// copy the message for broadcasting on each connection
		GetConnection<std::variant_alternative_t<I, V>>()->BroadcastMessage(message);
		BroadcastMessage<I + 1>(std::move(message));
	}
}

bool LauncherPostOffice::SendMessage(const ActorContainer& ident, MessagePtr message)
{
	SPDLOG_TRACE("{}: Sending message to {} seq={}", GetName(), ident, message->sequence());
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
	return GetPostOffice<LauncherPostOffice>().GetConnection<ActorContainer::Process>()->SendSetForegroundWindow(hWnd, processID);
}

void SendUnloadAllCommand()
{
	using namespace postoffice;
	GetPostOffice<LauncherPostOffice>().GetConnection<ActorContainer::Process>()->SendUnloadAllCommand();
}

void SendForceUnloadAllCommand()
{
	using namespace postoffice;
	GetPostOffice<LauncherPostOffice>().GetConnection<ActorContainer::Process>()->SendForceUnloadAllCommand();
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

void SetPostOfficeConfig(const PostOfficeConfig& config)
{
	s_postOfficeConfigs[config.Index] = config;
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

void RemovePostOffice(uint32_t index)
{
	s_postOffices.erase(index);
}

//----------------------------------------------------------------------------

