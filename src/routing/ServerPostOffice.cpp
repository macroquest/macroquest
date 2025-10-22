/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-present MacroQuest Authors
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

#include "routing/ServerPostOffice.h"
#include "routing/NamedPipes.h"
#include "routing/ProtoPipes.h"
#include "mq/base/String.h"

#include "spdlog/spdlog.h"

namespace mq::postoffice {

//=============================================================================

static void SetThreadName(const wchar_t* threadName)
{
	using fSetThreadDescription = HRESULT(WINAPI*)(HANDLE, PCWSTR);

	fSetThreadDescription SetThreadDescription = reinterpret_cast<fSetThreadDescription>(GetProcAddress(
		GetModuleHandleA("kernel32.dll"), "SetThreadDescription"));

	if (SetThreadDescription)
	{
		SetThreadDescription(GetCurrentThread(), threadName);
	}
}

ServerPostOffice::ServerPostOffice(const std::string& name, const std::string& pipeName, uint16_t defaultPort)
	: PostOffice(ActorIdentification(ActorContainer(ActorContainer::CurrentProcess, CreateUUID()), "launcher"))
	, m_peerPort(defaultPort)
	, m_pipeName(pipeName)
	, m_localConnection(std::make_unique<LocalConnection>(this))
	, m_peerConnection(std::make_unique<PeerConnection>(this))
{
	// Port will be selected by connection
	m_peerPort = m_peerConnection->GetPort();

	m_name = fmt::format("{} [{}]", name, m_peerPort);

	SPDLOG_INFO("PostOffice {{{}}}: Starting Post Office on pipe {} and port {}", m_name, m_pipeName, m_peerPort);

	m_thread = std::thread([this] { ThreadProc(); });
}

ServerPostOffice::~ServerPostOffice()
{
	SPDLOG_TRACE("PostOffice {{{}}}: Removing post office", m_name);
}

void ServerPostOffice::Initialize()
{
	// request IDs from all pre-existing connections
	// we could theoretically just ask a single peer but this will guarantee we have all
	// potential addresses

	for (const auto& [_, id] : m_identities)
	{
		if (!m_id.IsDuplicate(id))
			RequestIdentities(id.container);
	}
}

void ServerPostOffice::Shutdown()
{
	if (!m_running)
		return;

	SPDLOG_INFO("PostOffice {{{}}}: Shutting down post office", GetName());

	m_running = false;
	m_needsProcessing.notify_one();
	m_thread.join();
}

void ServerPostOffice::RequestProcessEvents()
{
	{
		std::unique_lock lock(m_processMutex);
		m_hasMessages = true;
	}

	m_needsProcessing.notify_one();
}

void ServerPostOffice::ThreadProc()
{
	SetThreadName(L"PostOffice");

	m_stats.emplace(m_id.container.uuid, ActorStats{ m_id });
	m_identities.emplace(m_id.container.uuid, m_id);

	AddConfiguredHosts();

	m_running = true;
	m_threadId = std::this_thread::get_id();

	StartConnections();

	while (m_running)
	{
		{
			std::unique_lock lock(m_processMutex);
			m_needsProcessing.wait_for(lock, m_heartBeatDuuration,
				[this] { return m_hasMessages || !m_running; });

			// set this before we process to allow for processes to request additional processing
			m_hasMessages = false;
		}

		//SPDLOG_TRACE("PostOffice {{{}}}: Processing events", GetName());

		ProcessIdentities(); // handles all identification maintenance

		ProcessOutgoing(); // handles any messages posted from the internal dropbox

		// It's important that this call is the only trigger for the connections incoming messages
		// that get handed off to RouteFromConnections. For local connections, it's OnIncomingMessage
		// and for network connections its the receive callback specified during construction
		// of the connection
		ProcessConnections(); // handles all incoming messages from connections

		ProcessReconnects();

		Process(10); // processes the messages waiting in the internal dropbox (shouldn't happen often)
	}

	StopConnections();
}

//-----------------------------------------------------------------------------

bool ServerPostOffice::IsRecipient(const proto::routing::Address& address, const ActorIdentification& id)
{
	SPDLOG_TRACE("PostOffice {{{}}}: Testing address [{}] against id [{}]",
		GetName(), address.ShortDebugString(), id.ToString());

	const std::string& uuid = address.uuid();

	return std::visit(overload{
		[&address, &uuid, &c = id.container](const ActorContainer::Process& proc)
		{
			if (!uuid.empty() && c.uuid != uuid)
				return false;

			if (!address.has_peer() && !address.has_process())
				return true;

			return (address.has_process() && address.process().pid() == proc.PID);
		},
		[&address, &uuid, &c = id.container](const ActorContainer::Network& network)
		{
			if (!uuid.empty() && c.uuid != uuid)
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

			return (address.has_name() && mq::ci_equals(name, address.name()));
		},
		[&address](const ActorIdentification::Client& client)
		{
			if (!address.has_name() && !address.has_client())
				return true;

			return address.has_client()
				&& (!address.client().has_account() || mq::ci_equals(client.account, address.client().account()))
				&& (!address.client().has_server() || mq::ci_equals(client.server, address.client().server()))
				&& (!address.client().has_character() || mq::ci_equals(client.character, address.client().character()));
		}
	}, id.address);
}

static MessagePtr FillAddress(MessagePtr message, const ActorIdentification& identity)
{
	proto::routing::Address& address = *message->mutable_address();
	identity.BuildAddress(address);

	return message;
}

// This is called when a dropbox registered to this post office attempts to send a message
void ServerPostOffice::RouteMessage(MessagePtr message)
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

void ServerPostOffice::ProcessOutgoing()
{
	std::unique_lock lock(m_outgoingMutex);

	if (!m_outgoingMessages.empty())
	{
		std::vector<MessagePtr> outgoing;
		std::swap(outgoing, m_outgoingMessages);

		lock.unlock();

		for (auto& message : outgoing)
		{
			ProcessOutgoingMessage(std::move(message));
		}
	}
}

void ServerPostOffice::ProcessOutgoingMessage(MessagePtr message)
{
	SPDLOG_TRACE("PostOffice {{{}}}: Routing message to=[{}] seq={}",
		GetName(), message->address().ShortDebugString(), message->sequence());

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
			SendMessage(identity->second.container, std::move(message));
	}
	else
	{
		// we don't have a PID or a name and this is not an RPC, so we will send this message to 
		// all clients that match the address -- it's important to copy these messages
		for (const auto& [_, identity] : m_identities)
		{
			if (IsRecipient(message->address(), identity))
			{
				SendMessage(identity.container, FillAddress(std::make_unique<proto::routing::Envelope>(*message), identity));
			}
		}
	}
}

void ServerPostOffice::ProcessIdentities()
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

// It's worthwhile to note for these next few functions that the identity.address == m_id.address
// check is the detection mechanism for only sending identity updates to peers that can actually
// use them. The assumption is that all routing peers will have the same name ("launcher" nominally)
void ServerPostOffice::AddIdentity(const ActorIdentification& id)
{
	if (std::this_thread::get_id() == m_threadId)
	{
		ProcessAddIdentity(id);
	}
	else
	{
		SPDLOG_TRACE("PostOffice {{{}}}: Requesting Add Identity {}", GetName(), id);

		{
			std::unique_lock lock(m_identityMutex);
			m_identityActions.emplace_back(IdentityAction::Add, id);
		}

		RequestProcessEvents();
	}
}

void ServerPostOffice::ProcessAddIdentity(const ActorIdentification& id)
{
	SPDLOG_TRACE("PostOffice {{{}}}: Processing Add Identity {}", GetName(), id);

	// test for duplicates, update if different
	bool send_updates = true;
	auto ident_it = m_identities.find(id.container.uuid);
	if (ident_it != m_identities.end())
	{
		if (ident_it->second != id)
		{
			SPDLOG_TRACE("PostOffice {{{}}}: Got Updated identification new=[{}] old=[{}]",
				GetName(), id, ident_it->second);

			auto stat_it = m_stats.find(id.container.uuid);
			if (stat_it == m_stats.end())
				m_stats.emplace(id.container.uuid, ActorStats{ id });
			else
				stat_it->second.Identity = id;

			ident_it->second = id;
		}
		else
		{
			SPDLOG_TRACE("PostOffice {{{}}}: Got duplicate identification from {}, doing nothing", GetName(), id);

			send_updates = false;
		}
	}
	else
	{
		SPDLOG_TRACE("PostOffice {{{}}}: Got New identification from [{}]", GetName(), id);

		m_stats.emplace(id.container.uuid, ActorStats{ id });
		m_identities.emplace(id.container.uuid, id);
	}

	if (send_updates && id.container.IsLocal())
	{
		for (const auto& [uuid, identity] : m_identities)
		{
			if (identity.address == m_id.address
				&& uuid != m_id.container.uuid
				&& uuid != id.container.uuid)
			{
				SendIdentification(identity.container, id);
			}
		}
	}
}

void ServerPostOffice::DropIdentity(const ActorIdentification& id)
{
	if (id.address == m_id.address)
	{
		// if this is dropping another launcher, then everything it routes also needs to be dropped
		DropContainer(id.container);
	}
	else if (std::this_thread::get_id() == m_threadId)
	{
		ProcessDropIdentity(id);
	}
	else
	{
		SPDLOG_TRACE("PostOffice {{{}}}: Requesting Drop Identity {}", GetName(), id);

		{
			std::unique_lock lock(m_identityMutex);
			m_identityActions.emplace_back(IdentityAction::Drop, id);
		}

		RequestProcessEvents();
	}
}

void ServerPostOffice::ProcessDropIdentity(const ActorIdentification& id)
{
	SPDLOG_TRACE("PostOffice {{{}}}: Processing Drop Identity {}", GetName(), id);

	for (auto ident_it = m_identities.begin(); ident_it != m_identities.end();)
	{
		if (ident_it->second.IsDuplicate(id))
			ident_it = m_identities.erase(ident_it);
		else
			++ident_it;
	}

	if (id.container.IsLocal())
	{
		for (const auto& [uuid, identity] : m_identities)
		{
			if (identity.address == m_id.address && uuid != m_id.container.uuid)
				DropIdentification(identity.container, id);
		}
	}
}

void ServerPostOffice::DropContainer(const ActorContainer& container)
{
	if (std::this_thread::get_id() == m_threadId)
	{
		ProcessDropContainer(container);
	}
	else
	{
		SPDLOG_TRACE("PostOffice {{{}}}: Requesting Drop Container {}", GetName(), container);

		{
			std::unique_lock lock(m_identityMutex);
			m_identityActions.emplace_back(IdentityAction::MassDrop, ActorIdentification{ container, "" });
		}

		RequestProcessEvents();
	}
}

void ServerPostOffice::ProcessDropContainer(const ActorContainer& container)
{
	SPDLOG_TRACE("PostOffice {{{}}}: Processing Drop Container {}", GetName(), container);

	if (container.IsLocal())
	{
		std::vector<ActorIdentification> to_erase;

		auto it = std::find_if(m_identities.begin(), m_identities.end(),
			[&container](const std::pair<std::string, ActorIdentification>& pair)
		{
			return pair.second.container.IsIn(container);
		});

		while (it != m_identities.end())
		{
			to_erase.emplace_back(std::move(it->second));

			it = std::find_if(m_identities.erase(it), m_identities.end(),
				[&container](const std::pair<std::string, ActorIdentification>& pair)
			{
				return pair.second.container.IsIn(container);
			});
		}

		for (const auto& [uuid, identity] : m_identities)
		{
			if (identity.address == m_id.address && uuid != m_id.container.uuid)
			{
				for (const auto& dropped : to_erase)
					DropIdentification(identity.container, dropped);
			}
		}
	}

	// always remove explicit drops from identities
	auto iter = m_identities.find(container.uuid);
	if (iter != m_identities.end())
		m_identities.erase(iter);

	std::visit(overload{
		[this](const ActorContainer::Process&)
		{
		},
		[this](const ActorContainer::Network& net)
		{
			std::unique_lock lock(m_processMutex);
			m_reconnectingHosts.emplace_back(NetworkAddress{net.IP, net.Port});
		}
	}, container.value);
}

void ServerPostOffice::SendIdentities(const ActorContainer& requester)
{
	SPDLOG_TRACE("PostOffice {{{}}}: Requesting Send Identities from {}", GetName(), requester);

	if (std::this_thread::get_id() == m_threadId)
	{
		ProcessSendIdentities(requester);
	}
	else
	{
		{
			std::unique_lock lock(m_identityMutex);
			m_identityActions.emplace_back(IdentityAction::MassAdd, ActorIdentification{ requester, "" });
		}

		RequestProcessEvents();
	}
}

void ServerPostOffice::ProcessSendIdentities(const ActorContainer& requester)
{
	SPDLOG_TRACE("PostOffice {{{}}}: Processing Send Identities from {}", GetName(), requester);

	for (const auto& [_, client] : m_identities)
	{
		if (client.container.IsLocal())
			SendIdentification(requester, client);
	}
}

void ServerPostOffice::ProcessReconnects()
{
	std::unique_lock lock(m_processMutex);

	if (!m_reconnectingHosts.empty())
	{
		std::vector<NetworkAddress> hosts;
		std::swap(hosts, m_reconnectingHosts);

		lock.unlock();

		for (const auto& host : hosts)
		{
			AddNetworkHost(host.IP, host.Port);
		}
	}
}

void ServerPostOffice::FillAndSend(MessagePtr message, const std::function<bool(const ActorIdentification&)>& predicate)
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
		{
			SendMessage(identity->container, FillAddress(std::make_unique<proto::routing::Envelope>(*message), *identity));
		}
	}
}

void ServerPostOffice::RouteFromConnection(MessagePtr message)
{
	// it's safe to assume that any RPC requests will get routed back to the originating connection, so there is no
	// need to handle callbacks here, we can just allow the connections to handle them when the reply is sent back
	// over the connection (via route). What we _do_ need here is early detection of multiple recipients if the
	// message is an RPC and sending it back if it's ambiguous

	SPDLOG_TRACE("PostOffice {{{}}}: Routing received message: to=[{}] from=[{}] seq={}", GetName(),
		message->address().ShortDebugString(), message->return_address().ShortDebugString(), message->sequence());

	if (message->has_return_address() && message->return_address().has_uuid())
		AddReceiveStat(message->return_address().uuid());

	const auto& address = message->address();
	std::string uuid = address.uuid();

	if ((!uuid.empty() && uuid == m_id.container.uuid)
		|| uuid.empty() && address.has_process()
		&& address.process().pid() == GetCurrentProcessId()
		&& address.has_name() && address.name() == "launcher")
	{
		// we are explicitly sending to this launcher, so route entirely internally
		const auto mailbox = address.has_mailbox() ? address.mailbox() : "post_office";

		SPDLOG_TRACE("PostOffice {{{}}}: Internal pipe message received, routing to mailbox {} seq={}",
			GetName(), mailbox, message->sequence());

		// This is already an explicit address, so just package up the envelope into a message and deliver it
		DeliverTo(mailbox, std::move(message));
	}
	else if (address.has_process()
		|| (address.has_peer() && address.peer().ip() == "127.0.0.1"
			&& address.peer().port() == m_peerConnection->GetPort()))
	{
		// this message is intended to be routed locally and not relayed to external peers
		SPDLOG_TRACE("PostOffice {{{}}}: Routing message to local connections ({}) seq={}",
			GetName(), address.ShortDebugString(), message->sequence());

		proto::routing::Address local_address;
		local_address.set_mailbox(address.mailbox());

		if (address.has_name())
			local_address.set_name(address.name());
		else if (address.has_client())
			*local_address.mutable_client() = address.client();

		FillAndSend(std::move(message),
			[&local_address, this](const auto& identity)
		{
			return identity.container.IsLocal() && IsRecipient(local_address, identity);
		});
	}
	else
	{
		// This message isn't addressed specifically to a container, so find all identities that
		// should receive this message and send to each one
		SPDLOG_TRACE("PostOffice {{{}}}: Routing message to [{}] seq={}", GetName(), address.ShortDebugString(), message->sequence());

		FillAndSend(std::move(message),
			[&address, this](const auto& identity)
		{
			return IsRecipient(address, identity);
		});
	}

	RequestProcessEvents();
}

void ServerPostOffice::OnDeliver(const std::string& localAddress, MessagePtr& message)
{
	RequestProcessEvents();
}

std::vector<const ActorStats*> ServerPostOffice::GetStats()
{
	auto now = std::chrono::system_clock::now();
	auto lookback = now - std::chrono::seconds(m_statsLookbackSeconds);

	std::vector<const ActorStats*> stats;
	stats.reserve(m_stats.size());

	for (auto& [_, stat] : m_stats)
	{
		stat.Sent.erase(std::remove_if(stat.Sent.begin(), stat.Sent.end(),
			[&lookback](const std::chrono::system_clock::time_point& t) { return t < lookback; }),
			stat.Sent.end());

		stat.Received.erase(std::remove_if(stat.Received.begin(), stat.Received.end(),
			[&lookback](const std::chrono::system_clock::time_point& t) { return t < lookback; }),
			stat.Received.end());

		stats.push_back(&stat);
	}

	return stats;
}

//-----------------------------------------------------------------------------

template <>
const std::unique_ptr<LocalConnection>& ServerPostOffice::GetConnection<ActorContainer::Process>()
{
	return m_localConnection;
}

template <>
const std::unique_ptr<PeerConnection>& ServerPostOffice::GetConnection<ActorContainer::Network>()
{
	return m_peerConnection;
}

template <size_t I>
void ServerPostOffice::StartConnections()
{
	using V = std::remove_const_t<decltype(ActorContainer::value)>;
	if constexpr (I < std::variant_size_v<V>)
	{
		GetConnection<std::variant_alternative_t<I, V>>()->Start();
		StartConnections<I + 1>();
	}
}

template <size_t I>
void ServerPostOffice::StopConnections()
{
	using V = std::remove_const_t<decltype(ActorContainer::value)>;
	if constexpr (I < std::variant_size_v<V>)
	{
		GetConnection<std::variant_alternative_t<I, V>>()->Stop();
		StopConnections<I + 1>();
	}
}

template <size_t I>
void ServerPostOffice::ProcessConnections()
{
	using V = std::remove_const_t<decltype(ActorContainer::value)>;
	if constexpr (I < std::variant_size_v<V>)
	{
		GetConnection<std::variant_alternative_t<I, V>>()->Process();
		ProcessConnections<I + 1>();
	}
}

template <size_t I>
void ServerPostOffice::BroadcastMessage(MessagePtr message)
{
	for (const auto& [uuid, _] : m_identities)
		AddSendStat(uuid);

	using V = std::remove_const_t<decltype(ActorContainer::value)>;
	if constexpr (I < std::variant_size_v<V>)
	{
		// copy the message for broadcasting on each connection
		GetConnection<std::variant_alternative_t<I, V>>()->BroadcastMessage(message);
		BroadcastMessage<I + 1>(std::move(message));
	}
}

bool ServerPostOffice::SendMessage(const ActorContainer& ident, MessagePtr message)
{
	SPDLOG_TRACE("PostOffice {{{}}}: Sending message to {} seq={}", GetName(), ident, message->sequence());
	AddSendStat(ident.uuid);

	return std::visit([this, message = std::move(message), &ident](const auto& c) mutable
		{
			return GetConnection<std::remove_const_t<std::remove_reference_t<decltype(c)>>>()->SendMessage(ident, std::move(message));
		}, ident.value);
}

void ServerPostOffice::SendIdentification(const ActorContainer& target, const ActorIdentification& id)
{
	SPDLOG_TRACE("PostOffice {{{}}}: Sending identification {} to {}", GetName(), id, target);

	return std::visit([this, &id, &target](const auto& c) mutable
		{
			return GetConnection<std::remove_const_t<std::remove_reference_t<decltype(c)>>>()->SendIdentification(target, id);
		}, target.value);
}

void ServerPostOffice::DropIdentification(const ActorContainer& target, const ActorIdentification& id)
{
	SPDLOG_TRACE("PostOffice {{{}}}: Dropping identification {} from {}", GetName(), id, target);

	return std::visit([this, &id, &target](const auto& c) mutable
		{
			return GetConnection<std::remove_const_t<std::remove_reference_t<decltype(c)>>>()->DropIdentification(target, id);
		}, target.value);
}

void ServerPostOffice::RequestIdentities(const ActorContainer& from)
{
	SPDLOG_TRACE("PostOffice {{{}}}: Requesting identities from {}", GetName(), from);

	return std::visit([this, &from](const auto& c) mutable
		{
			return GetConnection<std::remove_const_t<std::remove_reference_t<decltype(c)>>>()->RequestIdentities(from);
		}, from.value);
}

void ServerPostOffice::AddSendStat(const std::string& uuid)
{
	auto stat_it = m_stats.find(uuid);
	if (stat_it == m_stats.end())
	{
		auto id_it = m_identities.find(uuid);
		if (id_it != m_identities.end())
		{
			auto [result, _] = m_stats.emplace(uuid, ActorStats{ id_it->second });
			stat_it = result;
		}
	}

	if (stat_it != m_stats.end())
	{
		auto now = std::chrono::system_clock::now();
		stat_it->second.Sent.emplace_back(now);

		auto lookback = now - std::chrono::seconds(m_statsLookbackSeconds);
		stat_it->second.Sent.erase(std::remove_if(stat_it->second.Sent.begin(), stat_it->second.Sent.end(),
			[&lookback](const std::chrono::system_clock::time_point& t) { return t < lookback; }),
			stat_it->second.Sent.end());
	}
}

void ServerPostOffice::AddReceiveStat(const std::string& uuid)
{
	auto stat_it = m_stats.find(uuid);
	if (stat_it == m_stats.end())
	{
		auto id_it = m_identities.find(uuid);
		if (id_it != m_identities.end())
		{
			auto [result, _] = m_stats.emplace(uuid, ActorStats{ id_it->second });
			stat_it = result;
		}
	}

	if (stat_it != m_stats.end())
	{
		auto now = std::chrono::system_clock::now();
		stat_it->second.Received.emplace_back(now);

		auto lookback = now - std::chrono::seconds(m_statsLookbackSeconds);
		stat_it->second.Received.erase(std::remove_if(stat_it->second.Received.begin(), stat_it->second.Received.end(),
			[&lookback](const std::chrono::system_clock::time_point& t) { return t < lookback; }),
			stat_it->second.Received.end());
	}
}

void ServerPostOffice::AddNetworkHost(const std::string& address, uint16_t port) const
{
	m_peerConnection->AddHost(address, port);
}

void ServerPostOffice::RemoveNetworkHost(const std::string& address, uint16_t port) const
{
	m_peerConnection->RemoveHost(address, port);
}

PipeConnectionPtr ServerPostOffice::GetConnectionForProcessId(uint32_t processID) const
{
	return m_localConnection->GetPipeServer()->GetConnectionForProcessId(processID);
}

void ServerPostOffice::SendPipeMessage(int connectionId, mq::MQMessageId messageId, const void* data, size_t dataLength)
{
	m_localConnection->GetPipeServer()->SendMessage(connectionId, messageId, data, dataLength);
}

void ServerPostOffice::SendPipeMessage(int connectionId, PipeMessagePtr message)
{
	m_localConnection->GetPipeServer()->SendMessage(connectionId, std::move(message));
}

void ServerPostOffice::BroadcastPipeMessage(MQMessageId messageId, const void* data, size_t dataLength)
{
	m_localConnection->GetPipeServer()->BroadcastMessage(messageId, data, dataLength);
}

void ServerPostOffice::BroadcastPipeMessage(PipeMessagePtr message)
{
	m_localConnection->GetPipeServer()->BroadcastMessage(std::move(message));
}

void ServerPostOffice::HandleIncomingMessage(LocalConnection* connection, mq::PipeMessagePtr message)
{
	SPDLOG_TRACE("PostOffice {{{}}}: Received message id={} length={} connectionId={}", GetName(),
		static_cast<int>(message->GetMessageId()), message->size(), message->GetConnectionId());

	switch (message->GetMessageId())  // NOLINT(clang-diagnostic-switch-enum)
	{
	case mq::MQMessageId::MSG_ECHO:
	{
		std::string str(message->get<const char>(), message->size() - 1);
		message->SendReply(MQMessageId::MSG_ECHO, str.data(), static_cast<uint32_t>(str.length()) + 1, 0);
		SPDLOG_INFO("PostOffice {{{}}}: Handling echo request: {}", GetName(), str);
		break;
	}

	case mq::MQMessageId::MSG_ROUTE:
	{
		connection->RouteFromPipe(std::make_unique<proto::routing::Envelope>(ProtoMessage::Parse<proto::routing::Envelope>(message)));
		break;
	}

	case mq::MQMessageId::MSG_IDENTIFICATION:
	{
		if (message->GetHeader()->messageLength > 0)
		{
			// if there is a payload, then we are getting a notification of ID
			auto id = ProtoMessage::Parse<proto::routing::Identification>(message);
			connection->UpdateConnection(id.uuid(), message->GetConnectionId());

			// send this to the post office to process in the launcher dropbox
			AddIdentity(ActorIdentification(std::move(id)));
		}
		else if (auto pipeServer = connection->GetPipeServer())
		{
			if (const auto& conn = pipeServer->GetConnection(message->GetConnectionId()))
			{
				// TODO: This technically isn't correct because it doesn't use the information contained in the
				// proto -- this should have a message ID

				// we are getting a request to send all IDs, do so sequentially and asynchronously
				// send this to the post office to process in the launcher dropbox
				auto uuid = connection->GetConnectionUUID(message->GetConnectionId());
				SendIdentities(ActorContainer(ActorContainer::Process{ conn->GetProcessId() }, uuid));
			}
		}

		break;
	}

	case mq::MQMessageId::MSG_DROPPED:
	{
		auto id = ProtoMessage::Parse<proto::routing::Identification>(message);
		connection->DropConnection(id.uuid());

		DropIdentity(ActorIdentification(std::move(id)));
		break;
	}

	default:
		OnIncomingMessage(connection, std::move(message));
		break;
	}
}

void ServerPostOffice::OnIncomingMessage(LocalConnection* connection, mq::PipeMessagePtr message)
{
}

void ServerPostOffice::OnRequestProcessEvents(LocalConnection* connection)
{
}

void ServerPostOffice::OnIncomingConnection(LocalConnection* connection, int connectionId, int processId)
{
}

void ServerPostOffice::OnConnectionClosed(LocalConnection* connection, int connectionId, int processId)
{
	auto uuid = connection->GetConnectionUUID(connectionId);
	connection->DropConnection(uuid);
	connection->DropProcess(ActorContainer(ActorContainer::Process{ static_cast<uint32_t>(processId) }, uuid));
}

void ServerPostOffice::OnClientConnected(LocalConnection* connection)
{
}

//=============================================================================

} // namespace mq::postoffice
