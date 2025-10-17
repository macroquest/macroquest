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

#include "routing/PostOffice.h"
#include "loader/PostOffice.h"
#include "loader/MacroQuest.h"

#include <date/date.h>
#include <fmt/format.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/wincolor_sink.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <shellapi.h>

#include <variant>

static std::unordered_map<uint32_t, PostOfficeConfig> s_postOfficeConfigs;

static std::optional<std::string> s_iniLocation;

void SetPostOfficeIni(std::string_view ini)
{
	s_iniLocation = ini;
}

void RemovePostOffice(uint32_t index);

namespace mq::postoffice {

bool LauncherPostOffice::IsRecipient(const proto::routing::Address& address, const ActorIdentification& id)
{
	SPDLOG_TRACE("{}: Testing address [{}] against id [{}]", GetName(), address.ShortDebugString(), id.ToString());

	std::string uuid = address.uuid();
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
	const std::unordered_map<std::string, ActorIdentification>::iterator& from)
{
	return std::find_if(from, m_identities.end(),
		[&address, this](const std::pair<std::string, ActorIdentification>& pair)
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
	SPDLOG_TRACE("{}: Routing message to=[{}] seq={}", GetName(), message->address().ShortDebugString(), message->sequence());

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
				SendMessage(identity.container, FillAddress(std::make_unique<proto::routing::Envelope>(*message), identity));
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

// It's worthwhile to note for these next few functions that the identity.address == m_id.address
// check is the detection mechanism for only sending identity updates to peers that can actually
// use them. The assumption is that all routing peers will have the same name ("launcher" nominally)
void LauncherPostOffice::AddIdentity(const ActorIdentification& id)
{
	SPDLOG_TRACE("{}: Requesting Add Identity {}", GetName(), id);
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
	SPDLOG_TRACE("{}: Processing Add Identity {}", GetName(), id);
	// test for duplicates, update if different
	bool send_updates = true;
	auto ident_it = m_identities.find(id.container.uuid);
	if (ident_it != m_identities.end())
	{
		if (ident_it->second != id)
		{
			SPDLOG_TRACE("{}: Got Updated identification new=[{}] old=[{}]", GetName(), id, ident_it->second);

			auto stat_it = m_stats.find(id.container.uuid);
			if (stat_it == m_stats.end())
				m_stats.emplace(id.container.uuid, ActorStats{ id });
			else
				stat_it->second.Identity = id;

			ident_it->second = id;
		}
		else
		{
			SPDLOG_TRACE("{}: Got duplicate identification from {}, doing nothing", GetName(), id);
			send_updates = false;
		}
	}
	else
	{
		SPDLOG_TRACE("{}: Got New identification from [{}]", GetName(), id);
		m_stats.emplace(id.container.uuid, ActorStats{ id });
		m_identities.emplace(id.container.uuid, id);
	}

	if (send_updates && id.container.IsLocal())
	{
		for (const auto& [uuid, identity] : m_identities)
			if (identity.address == m_id.address && uuid != m_id.container.uuid && uuid != id.container.uuid)
				SendIdentification(identity.container, id);
	}
}

void LauncherPostOffice::DropIdentity(const ActorIdentification& id)
{
	SPDLOG_TRACE("{}: Requesting Drop Identity {}", GetName(), id);
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
		{
			std::unique_lock lock(m_identityMutex);
			m_identityActions.emplace_back(IdentityAction::Drop, id);
		}

		RequestProcessEvents();
	}
}

void LauncherPostOffice::ProcessDropIdentity(const ActorIdentification& id)
{
	SPDLOG_TRACE("{}: Processing Drop Identity {}", GetName(), id);
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
			if (identity.address == m_id.address && uuid != m_id.container.uuid)
				DropIdentification(identity.container, id);
	}
}

void LauncherPostOffice::DropContainer(const ActorContainer& container)
{
	SPDLOG_TRACE("{}: Requesting Drop Container {}", GetName(), container);
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
	SPDLOG_TRACE("{}: Processing Drop Container {}", GetName(), container);
	if (container.IsLocal())
	{
		std::vector<ActorIdentification> to_erase;
		auto it = std::find_if(m_identities.begin(), m_identities.end(),
			[&container](const std::pair<std::string, ActorIdentification>& pair)
			{ return pair.second.container.IsIn(container); });

		while (it != m_identities.end())
		{
			to_erase.emplace_back(std::move(it->second));
			it = std::find_if(m_identities.erase(it), m_identities.end(),
				[&container](const std::pair<std::string, ActorIdentification>& pair)
				{ return pair.second.container.IsIn(container); });
		}

		for (const auto& [uuid, identity] : m_identities)
			if (identity.address == m_id.address && uuid != m_id.container.uuid)
				for (const auto& dropped : to_erase)
					DropIdentification(identity.container, dropped);
	}

	// always remove explicit drops from identities
	auto iter = m_identities.find(container.uuid);
	if (iter != m_identities.end())
		m_identities.erase(iter);

	std::visit(overload{
		[this](const ActorContainer::Process&) {},
		[this](const ActorContainer::Network& net)
		{
			std::unique_lock lock(m_processMutex);
			m_reconnectingHosts.emplace_back(NetworkAddress{net.IP, net.Port});
		}
	}, container.value);
}

void LauncherPostOffice::SendIdentities(const ActorContainer& requester)
{
	SPDLOG_TRACE("{}: Requesting Send Identities from {}", GetName(), requester);
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
	SPDLOG_TRACE("{}: Processing Send Identities from {}", GetName(), requester);
	for (const auto& [_, client] : m_identities)
		if (client.container.IsLocal())
			SendIdentification(requester, client);
}

void LauncherPostOffice::ProcessReconnects()
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

void LauncherPostOffice::FillAndSend(MessagePtr message, const std::function<bool(const ActorIdentification&)>& predicate)
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

	if (message->has_return_address() && message->return_address().has_uuid())
		AddReceiveStat(message->return_address().uuid());

	const auto& address = message->address();

	std::string uuid = address.uuid();
	if ((!uuid.empty() && uuid == m_id.container.uuid) ||
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

void LauncherPostOffice::AddNetworkHost(const std::string& address, uint16_t port) const
{
	m_peerConnection->AddHost(address, port);
}

void LauncherPostOffice::RemoveNetworkHost(const std::string& address, uint16_t port) const
{
	m_peerConnection->RemoveHost(address, port);
}

void LauncherPostOffice::AddConfiguredHosts()
{
	// it does not make sense for this port to be 0 since we are trying to connect to a peer with
	// a live port, so assume 0 means connect to the same port as this
	const uint16_t default_port = GetPeerPort();

	if (m_config.Peers)
	{
		for (const auto& [address, port] : *m_config.Peers)
		{
			AddNetworkHost(address, port > 0 ? port : default_port);
		}
	}
	else if (s_iniLocation)
	{
		for (const auto& [address, port_raw] : GetPrivateProfileKeyValues("NetworkPeers", *s_iniLocation))
		{
			const uint16_t port = static_cast<uint16_t>(GetUIntFromString(port_raw, 0));
			AddNetworkHost(address, port > 0 ? port : default_port);
		}
	}
}

uint16_t LauncherPostOffice::GetPeerPort() const
{
	return m_config.PeerPort;
}

void LauncherPostOffice::OnDeliver(const std::string& localAddress, MessagePtr& message)
{
	RequestProcessEvents();
}

uint32_t LauncherPostOffice::GetIdentityCount()
{
	return (uint32_t)m_identities.size();
}

std::vector<const ActorStats*> LauncherPostOffice::GetStats()
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

void LauncherPostOffice::Initialize()
{
	// request IDs from all pre-existing connections
	// we could theoretically just ask a single peer but this will guarantee we have all
	// potential addresses
	for (const auto& [_, id] : m_identities)
		if (!m_id.IsDuplicate(id)) RequestIdentities(id.container);
}

void LauncherPostOffice::Shutdown()
{
	if (!m_running)
		return;

	SPDLOG_INFO("{}: Shutting down post office", GetName());
	m_running = false;
	m_needsProcessing.notify_one();
	m_thread.join();

	RemovePostOffice(m_config.Index);
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
	: PostOffice(ActorIdentification(ActorContainer(ActorContainer::Process{ GetCurrentProcessId() }, CreateUUID()), "launcher"))
	, m_config(config)
	, m_localConnection(std::make_unique<LocalConnection>(this))
	, m_peerConnection(std::make_unique<PeerConnection>(this))
{
	m_config.PeerPort = m_peerConnection->GetPort();
	SPDLOG_INFO("{}: Starting Post Office on pipe {} and port {}", GetName(), m_config.PipeName, m_config.PeerPort);

	m_name = fmt::format("{} [{}]", m_config.Name, m_config.PeerPort);

	m_thread = std::thread(
		[this]
		{
			m_stats.emplace(m_id.container.uuid, ActorStats{ m_id });
			m_identities.emplace(m_id.container.uuid, m_id);

			AddConfiguredHosts();

			using fSetThreadDescription = HRESULT(WINAPI*)(HANDLE, PCWSTR);
			fSetThreadDescription SetThreadDescription = nullptr;
			if (auto kernel = GetModuleHandleA("kernel32.dll"))
				SetThreadDescription = (fSetThreadDescription)GetProcAddress(kernel, "SetThreadDescription");

			if (SetThreadDescription)
				SetThreadDescription(GetCurrentThread(), L"PostOffice");

			m_running = true;
			m_threadId = std::this_thread::get_id();

			StartConnections();

			InitializePostOfficeImgui();

			do
			{
				{
					std::unique_lock<std::mutex> lock(m_processMutex);
					m_needsProcessing.wait_for(lock,
						std::chrono::seconds(m_config.HeartbeatSeconds),
						[this] { return m_hasMessages || !m_running; });
					
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

				ProcessReconnects();

				Process(10); // processes the messages waiting in the internal dropbox (shouldn't happen often)
			} while (m_running);

			ShutdownPostOfficeImgui();

			StopConnections();
		}
	);
}

LauncherPostOffice::~LauncherPostOffice()
{
	SPDLOG_TRACE("{}: Removing post office", GetName());
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

bool LauncherPostOffice::SendMessage(const ActorContainer& ident, MessagePtr message)
{
	SPDLOG_TRACE("{}: Sending message to {} seq={}", GetName(), ident, message->sequence());
	AddSendStat(ident.uuid);
	return std::visit([this, message = std::move(message), &ident](const auto& c) mutable
		{
			return GetConnection<std::remove_const_t<std::remove_reference_t<decltype(c)>>>()->SendMessage(ident, std::move(message));
		}, ident.value);
}

void LauncherPostOffice::SendIdentification(const ActorContainer& target, const ActorIdentification& id)
{
	SPDLOG_TRACE("{}: Sending identification {} to {}", GetName(), id, target);
	return std::visit([this, &id, &target](const auto& c) mutable
		{
			return GetConnection<std::remove_const_t<std::remove_reference_t<decltype(c)>>>()->SendIdentification(target, id);
		}, target.value);
}

void LauncherPostOffice::DropIdentification(const ActorContainer& target, const ActorIdentification& id)
{
	SPDLOG_TRACE("{}: Dropping identification {} from {}", GetName(), id, target);
	return std::visit([this, &id, &target](const auto& c) mutable
		{
			return GetConnection<std::remove_const_t<std::remove_reference_t<decltype(c)>>>()->DropIdentification(target, id);
		}, target.value);
}

void LauncherPostOffice::RequestIdentities(const ActorContainer& from)
{
	SPDLOG_TRACE("{}: Requesting identities from {}", GetName(), from);
	return std::visit([this, &from](const auto& c) mutable
		{
			return GetConnection<std::remove_const_t<std::remove_reference_t<decltype(c)>>>()->RequestIdentities(from);
		}, from.value);
}

void LauncherPostOffice::AddSendStat(const std::string& uuid)
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

void LauncherPostOffice::AddReceiveStat(const std::string& uuid)
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
	using namespace postoffice;

	std::vector<uint32_t> indexes;
	for (const auto& [index, _] : s_postOffices)
		indexes.push_back(index);

	for (auto index : indexes)
		GetPostOffice<LauncherPostOffice>(index).Shutdown();
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
}

void RemovePostOffice(uint32_t index)
{
	s_postOffices.erase(index);
}

//----------------------------------------------------------------------------

