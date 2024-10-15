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

// helper function to respond back for RPC messages with < 0 status
void RoutingFailed(
	int status,
	const PipeMessagePtr& message,
	const PipeMessageResponseCb& callback)
{
	// we can't assume that the mailbox exists here, so manually create the reply
	const auto envelope = ProtoMessage::Parse<proto::routing::Envelope>(message);
	proto::routing::Envelope outbound;
	*outbound.mutable_address() = envelope.return_address();
	outbound.set_payload(envelope.address().SerializeAsString());

	std::string data = outbound.SerializeAsString();
	if (callback == nullptr)
		message->SendReply(MQMessageId::MSG_ROUTE, data.data(), data.size(), static_cast<uint8_t>(status));
	else
		callback(status, std::make_unique<PipeMessage>(MQMessageId::MSG_ROUTE, data.data(), data.size()));
}

bool LauncherPostOffice::IsRecipient(const proto::routing::Address& address, const ActorIdentification& id)
{
	//SPDLOG_TRACE("{}: Testing address {} against id {}", GetName(), address.DebugString(), id.ToString());

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

// This is called when a dropbox registered to this pipe server attempts to send a message
void LauncherPostOffice::RouteMessage(PipeMessagePtr&& message, const PipeMessageResponseCb& callback)
{
	const auto envelope = ProtoMessage::Parse<proto::routing::Envelope>(message);
	const auto& address = envelope.address();

	// if we have a PID here, we could still have multiple names on the same PID, so we can't
	// avoid the loop
	if (message->GetRequestMode() == MQRequestMode::CallAndResponse || callback != nullptr)
	{
		const auto identity = FindIdentity(envelope.address(), m_identities.begin());

		if (identity == m_identities.end())
			RoutingFailed(MsgError_RoutingFailed, message, callback);
		else if (FindIdentity(envelope.address(), std::next(identity)) != m_identities.end())
			RoutingFailed(MsgError_AmbiguousRecipient, message, callback);
		else
		{
			message->SetRequestMode(MQRequestMode::CallAndResponse);
			SendMessage(identity->first, std::move(message), callback);
		}
	}
	else
	{
		// we don't have a PID or a name and this is not an RPC, so we will send this message to 
		// all clients that match the address -- it's important to copy these messages
		for (const auto& identity : m_identities)
		{
			if (IsRecipient(address, identity.second))
			{
				SendMessage(
					identity.first,
					std::make_unique<PipeMessage>(*message->GetHeader(), message->get(), message->size()),
					callback);
			}
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

	// TODO: this should probably be a property of this
	ActorIdentification self(GetCurrentProcessId(), "launcher");

	// TODO: this is maybe too aggressive? not sure how else to make identities idempotent
	// we also need to update all the clients
	for (const auto& identity : m_identities)
	{
		if (!identity.second.IsDuplicate(id) && !identity.second.IsDuplicate(self))
		{
			SendMessage(identity.first, MQMessageId::MSG_IDENTIFICATION, id.GetProto(), nullptr);
		}
	}
}

void LauncherPostOffice::DropIdentity(const ActorIdentification& id)
{
	for (auto ident_it = m_identities.begin(); ident_it != m_identities.end();)
	{
		if (ident_it->second.IsDuplicate(id))
		{
			BroadcastMessage(MQMessageId::MSG_DROPPED, ident_it->second.GetProto());
			ident_it = m_identities.erase(ident_it);
		}
		else
			++ident_it;
	}
}

void LauncherPostOffice::DropContainer(const ActorContainer& container)
{
	const auto range = m_identities.equal_range(container);
	for (auto it = range.first; it != range.second; ++it)
	{
		// TODO: does this need to exclude the dropped container?
		BroadcastMessage(MQMessageId::MSG_DROPPED, it->second.GetProto());
	}

	m_identities.erase(container);
}

void LauncherPostOffice::SendIdentities(const ActorContainer& requester)
{
	for (const auto& [_, client] : m_identities)
	{
		proto::routing::Identification id = client.GetProto();

		const auto payload = std::make_unique<uint8_t[]>(id.ByteSizeLong());
		id.SerializeToArray(payload.get(), static_cast<int>(id.ByteSizeLong()));

		SendMessage(requester,
			std::make_unique<PipeMessage>(MQMessageId::MSG_IDENTIFICATION, payload.get(), id.ByteSizeLong()),
			nullptr);
	}
}

// TODO: routing needs a responsibility chain (ie, internal messages route out and in, but external messages only route in? think about this)
// TODO: add callback handling to this as well
void LauncherPostOffice::RouteFromConnection(const proto::routing::Envelope& message)
{
	SPDLOG_TRACE("{}: Routing received message: to={} from={}", GetName(),
		message.address().has_name() ? message.address().name() : message.address().client().character(),
		message.has_return_address() ? (message.return_address().has_name() ? message.return_address().name() : message.return_address().client().character()) : "unk");

	const auto& address = message.address();

	auto make_message = [&message, &address](const ActorIdentification& identity)
		{
			proto::routing::Envelope e;
			proto::routing::Address& explicit_address = *e.mutable_address();

			explicit_address.set_mailbox(address.mailbox()); // first copy the mailbox
			identity.BuildAddress(explicit_address); // then set the identity's address

			if (message.has_payload()) e.set_payload(message.payload());
			if (message.has_return_address()) *e.mutable_return_address() = message.return_address();

			const auto payload = std::make_unique<uint8_t[]>(e.ByteSizeLong());
			e.SerializeToArray(payload.get(), static_cast<int>(e.ByteSizeLong()));

			return std::make_unique<PipeMessage>(mq::MQMessageId::MSG_ROUTE,
				payload.get(), message.ByteSizeLong());
		};

	// curry out the callback in the failure helper
	auto routing_failed = [](int status, PipeMessagePtr&& message)
		{ RoutingFailed(status, message, nullptr); };

	// break this routing out explicitly to make it easier to read -- there will be some duplicated routes
	if (address.has_pid() && address.pid() == GetCurrentProcessId())
	{
		// we are explicitly sending to this PID, so route entirely internally
		const auto mailbox = address.has_mailbox() ? address.mailbox() : "post_office";
		SPDLOG_TRACE("{}: Internal pipe message received, routing to mailbox {}", GetName(), mailbox);
		DeliverTo(mailbox, make_message(ActorIdentification(GetCurrentProcessId(), mailbox)), routing_failed);
	}
	else if (address.has_peer() && address.peer().ip() == "127.0.0.1" && address.peer().port() == m_peerConnection->GetPort())
	{
		// this message is intended to be routed locally and not relayed to external peers
		// TODO: handle RPC here (it should fail here if we have more than one recipient)
		SPDLOG_TRACE("{}: Routing message to local connections ({})", GetName(), address.has_name() ? address.name() : address.client().character());
		proto::routing::Address local_address;
		local_address.set_mailbox(address.mailbox());
		if (address.has_name())
			local_address.set_name(address.name());
		else if (address.has_client())
			*local_address.mutable_client() = address.client();

		for (const auto& identity : m_identities)
		{
			if (identity.first.IsLocal() && IsRecipient(local_address, identity.second))
			{
				RouteMessage(make_message(identity.second), nullptr);
			}
		}
	}
	else
	{
		// This message isn't addressed specifically to this launcher, so find all identities that
		// should receive this message and send to each one
		// TODO: handle RPC here (it should fail here if we have more than one recipient)
		SPDLOG_TRACE("{}: Routing message to {}", GetName(), address.has_name() ? address.name() : address.client().character());
		for (const auto& identity : m_identities)
		{
			if (IsRecipient(address, identity.second))
			{
				RouteMessage(make_message(identity.second), nullptr);
			}
		}
	}

	{
		std::lock_guard<std::mutex> lock(m_processMutex);
		m_hasMessages = true;
	}

	m_needsProcessing.notify_one();
}

void LauncherPostOffice::OnDeliver(const std::string& localAddress, PipeMessagePtr& message)
{
	{
		std::lock_guard<std::mutex> lock(m_processMutex);
		m_hasMessages = true;
	}

	m_needsProcessing.notify_one();
}

void LauncherPostOffice::Initialize()
{
	m_serverDropbox = RegisterAddress("post_office",
		[this](ProtoMessagePtr&& message)
		{
			// if we've gotten here, then something is delivering a message to this
			// post office ("post_office"), so handle messages directly
		});

	// request IDs from all pre-existing connections
	// we could theoretically just ask a single peer but this will guarantee we have all
	// potential addresses
	BroadcastMessage(std::make_unique<PipeMessage>(MQMessageId::MSG_IDENTIFICATION, nullptr, 0));
}

void LauncherPostOffice::Shutdown()
{
	// after the mailbox is removed from the post office, it won't get any more messages, and let's
	// make sure all remaining messages get discarded by dropping the last reference, so we stop
	// processing
	m_serverDropbox.Remove();
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
	: m_config(config)
	, m_localConnection(std::make_unique<LocalConnection>(this))
	, m_peerConnection(std::make_unique<PeerConnection>(this))
{
	ActorIdentification id(GetCurrentProcessId(), "launcher");
	m_identities.emplace(id.container, id);

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
void LauncherPostOffice::BroadcastMessage(PipeMessagePtr&& message)
{
	using V = std::remove_const_t<decltype(ActorContainer::value)>;
	if constexpr (I < std::variant_size_v<V>)
	{
		// copy the message for broadcasting on each connection
		GetConnection<std::variant_alternative_t<I, V>>()->BroadcastMessage(
			std::make_unique<PipeMessage>(*message->GetHeader(), message->get(), message->size()));
		BroadcastMessage<I + 1>(std::move(message));
	}
}

template <typename T>
void LauncherPostOffice::BroadcastMessage(const MQMessageId& id, const T& proto)
{
	const auto payload = std::make_unique<uint8_t[]>(proto.ByteSizeLong());
	proto.SerializeToArray(payload.get(), static_cast<int>(proto.ByteSizeLong()));

	BroadcastMessage(std::make_unique<PipeMessage>(id, payload.get(), proto.ByteSizeLong()));
}

bool LauncherPostOffice::SendMessage(
	const ActorContainer& ident,
	PipeMessagePtr&& message,
	const PipeMessageResponseCb& callback)
{
	SPDLOG_TRACE("{}: Sending message to {}", GetName(), ident);
	return std::visit([this, message = std::move(message), &callback](const auto& c) mutable
		{
			return GetConnection<std::remove_const_t<std::remove_reference_t<decltype(c)>>>()->SendMessage(c, std::move(message), callback);
		}, ident.value);
}


template<typename T>
bool LauncherPostOffice::SendMessage(const ActorContainer& ident, const MQMessageId& id, const T& proto, const PipeMessageResponseCb& callback)
{
	const auto payload = std::make_unique<uint8_t[]>(proto.ByteSizeLong());
	proto.SerializeToArray(payload.get(), static_cast<int>(proto.ByteSizeLong()));

	return SendMessage(ident, std::make_unique<PipeMessage>(id, payload.get(), proto.ByteSizeLong()), callback);
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

