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

#pragma once

#include "routing/PostOffice.h"
#include "routing/Network.h"

#include <chrono>
#include <string>
#include <vector>

#if defined(SendMessage)
#undef SendMessage
#endif

namespace mq
{
	enum class MQMessageId : uint16_t;
	class ProtoPipeServer;
	class PipeConnection;
	class NetworkPeerAPI;

	class PipeMessage;
	using PipeMessagePtr = std::unique_ptr<PipeMessage>;

	class PipeConnection;
	using PipeConnectionPtr = std::shared_ptr<PipeConnection>;
} // namespace mq

namespace mq::postoffice {

//=============================================================================

template <typename T>
struct ConnectionTypeMap;

class LocalConnection;
class PeerConnection;

template <> struct ConnectionTypeMap<ActorContainer::Process> { using Type = LocalConnection; };
template <> struct ConnectionTypeMap<ActorContainer::Network> { using Type = PeerConnection; };

struct ActorStats
{
	ActorIdentification Identity;
	std::vector<std::chrono::system_clock::time_point> Received;
	std::vector<std::chrono::system_clock::time_point> Sent;
};

using IdentitiesMap = std::unordered_map<std::string, ActorIdentification>;

//-----------------------------------------------------------------------------

class ServerPostOffice : public postoffice::PostOffice
{
	friend class LocalConnectionPipeEventsHandler;

public:
	ServerPostOffice(const std::string& name, const std::string& pipeName,
		uint16_t defaultPort = mq::DEFAULT_NETWORK_PEER_PORT);
	virtual ~ServerPostOffice() override;

	const std::string& GetName() const { return m_name; }

	void AddNetworkHost(const std::string& address, uint16_t port) const;
	void RemoveNetworkHost(const std::string& address, uint16_t port) const;
	uint16_t GetPeerPort() const { return m_peerPort; }
	const std::string& GetPipeName() const { return m_pipeName; }

	bool IsRecipient(const proto::routing::Address& address, const ActorIdentification& id);

	// This is called when a dropbox registered to this pipe server attempts to send a message (an _outbound_ message)
	virtual void RouteMessage(MessagePtr message) override;
	virtual void OnDeliver(const std::string& localAddress, MessagePtr& message) override;

	// This is called when a message is received over a connection (an _inbound_ message)
	void RouteFromConnection(MessagePtr message);

	void AddIdentity(const ActorIdentification& id);
	void DropIdentity(const ActorIdentification& id);
	void DropContainer(const ActorContainer& container);
	void SendIdentities(const ActorContainer& requester);

	// add this for testing
	uint32_t GetIdentityCount() const { return static_cast<uint32_t>(m_identities.size()); }
	std::vector<const ActorStats*> GetStats(); // uuid is internal, so just turn this into a vector to return it
	void SetStatLookback(uint32_t seconds) { m_statsLookbackSeconds = seconds; }
	uint32_t GetStatLookback() { return m_statsLookbackSeconds; }

	void Initialize();
	void Shutdown();
	void RequestProcessEvents();

	template <typename I, typename C = typename ConnectionTypeMap<I>::Type>
	const std::unique_ptr<C>& GetConnection();

	// find connection on local pipe server
	PipeConnectionPtr GetConnectionForProcessId(uint32_t processID) const;

	// Send messages over the local connection
	void SendPipeMessage(int connectionId, MQMessageId messageId, const void* data, size_t dataLength);
	void SendPipeMessage(int connectionId, PipeMessagePtr message);

	void BroadcastPipeMessage(MQMessageId messageId, const void* data, size_t dataLength);
	void BroadcastPipeMessage(PipeMessagePtr message);

protected:
	// Forwarded pipe events from local connections
	virtual void OnIncomingMessage(LocalConnection* connection, mq::PipeMessagePtr message);
	virtual void OnRequestProcessEvents(LocalConnection* connection);
	virtual void OnIncomingConnection(LocalConnection* connection, int connectionId, int processId);
	virtual void OnConnectionClosed(LocalConnection* connection, int connectionId, int processId);
	virtual void OnClientConnected(LocalConnection* connection);

private:
	void HandleIncomingMessage(LocalConnection* connection, mq::PipeMessagePtr message);

	void ThreadProc();

	IdentitiesMap::iterator FindIdentity(const proto::routing::Address& address, IdentitiesMap::iterator from)
	{
		return std::find_if(from, m_identities.end(),
			[&address, this](const std::pair<std::string, ActorIdentification>& pair)
		{
			return IsRecipient(address, pair.second);
		});
	}

protected:
	uint16_t m_peerPort;
	std::string m_name;
	std::string m_pipeName;
	std::chrono::seconds m_heartBeatDuuration{ 2 };

	IdentitiesMap m_identities;

	const std::unique_ptr<LocalConnection> m_localConnection;
	const std::unique_ptr<PeerConnection> m_peerConnection;

	std::vector<NetworkAddress> m_reconnectingHosts;

	std::vector<MessagePtr> m_outgoingMessages;
	std::mutex m_outgoingMutex;

	enum class IdentityAction
	{
		Add,
		MassAdd,
		Drop,
		MassDrop
	};
	std::vector<std::pair<IdentityAction, ActorIdentification>> m_identityActions;
	std::mutex m_identityMutex;

	bool m_running = false;
	std::thread m_thread;
	std::thread::id m_threadId;

	bool m_hasMessages = false;
	std::mutex m_processMutex;
	std::condition_variable m_needsProcessing;

	// maintain some statistics for displaying
	std::unordered_map<std::string, ActorStats> m_stats;
	uint32_t m_statsLookbackSeconds = 60;

	template <size_t I = 0> void StartConnections();
	template <size_t I = 0> void StopConnections();
	template <size_t I = 0> void ProcessConnections();
	template <size_t I = 0> void BroadcastMessage(MessagePtr message);
	bool SendMessage(const ActorContainer& ident, MessagePtr message);
	void SendIdentification(const ActorContainer& target, const ActorIdentification& id);
	void DropIdentification(const ActorContainer& target, const ActorIdentification& id);
	void RequestIdentities(const ActorContainer& from);

	void AddSendStat(const std::string& uuid);
	void AddReceiveStat(const std::string& uuid);

	void ProcessOutgoing();
	void ProcessOutgoingMessage(MessagePtr);

	void ProcessIdentities();
	void ProcessAddIdentity(const ActorIdentification& id);
	void ProcessDropIdentity(const ActorIdentification& id);
	void ProcessDropContainer(const ActorContainer& container);
	void ProcessSendIdentities(const ActorContainer& requester);

	void ProcessReconnects();

	void FillAndSend(MessagePtr message, const std::function<bool(const ActorIdentification&)>& predicate);
	virtual void AddConfiguredHosts() {}
};

//=============================================================================

class Connection
{
public:
	explicit Connection(ServerPostOffice* postOffice);
	virtual ~Connection() = default;

	Connection(const Connection&) = delete;
	Connection& operator=(const Connection&) = delete;
	Connection(Connection&&) = delete;
	Connection& operator=(Connection&&) = delete;

	virtual void Process() = 0;

	virtual bool SendMessage(const ActorContainer& process, MessagePtr message) = 0;
	virtual void BroadcastMessage(MessagePtr message) = 0;

	virtual void SendIdentification(const ActorContainer& process, const ActorIdentification& identity) const = 0;
	virtual void DropIdentification(const ActorContainer& process, const ActorIdentification& identity) const = 0;
	virtual void RequestIdentities(const ActorContainer& process) const = 0;

	virtual void Start() = 0;
	virtual void Stop() = 0;

	void RequestProcessEvents();

	ServerPostOffice* GetPostOffice() const { return m_postOffice; }

protected:
	ServerPostOffice* m_postOffice;
};

//-----------------------------------------------------------------------------

class LocalConnection final : public Connection
{
	friend class LocalConnectionPipeEventsHandler;

public:
	LocalConnection(ServerPostOffice* postOffice);
	virtual ~LocalConnection() override;

	LocalConnection(const LocalConnection&) = delete;
	LocalConnection& operator=(const LocalConnection&) = delete;
	LocalConnection(LocalConnection&&) = delete;
	LocalConnection& operator=(LocalConnection&&) = delete;

	virtual void Process() override;

	virtual bool SendMessage(const ActorContainer& process, MessagePtr message) override;
	virtual void BroadcastMessage(MessagePtr message) override;

	virtual void SendIdentification(const ActorContainer& process, const ActorIdentification& identity) const override;
	virtual void DropIdentification(const ActorContainer& process, const ActorIdentification& identity) const override;
	virtual void RequestIdentities(const ActorContainer& process) const override;

	virtual void Start() override;
	virtual void Stop() override;

	void RouteFromPipe(MessagePtr message);
	void DropProcess(const ActorContainer& process) const;

	mq::ProtoPipeServer* GetPipeServer() { return m_pipeServer.get(); }

	int GetConnectionID(const std::string& uuid) const;
	std::string GetConnectionUUID(int connectionID) const;
	void UpdateConnection(const std::string& uuid, int connectionID);
	void DropConnection(const std::string& uuid);

private:
	std::shared_ptr<mq::PipeConnection> GetConnection(const std::string& uuid) const;

	std::unique_ptr<mq::ProtoPipeServer> m_pipeServer;
	std::unordered_map<std::string, int> m_connections;
	const std::string m_uuid; // this is the same as the postoffice uuid, memoize for quicker reference
};

//-----------------------------------------------------------------------------

class PeerConnection final : public Connection
{
public:
	PeerConnection(ServerPostOffice* postOffice);
	virtual ~PeerConnection() override;

	PeerConnection(const PeerConnection&) = delete;
	PeerConnection& operator=(const PeerConnection&) = delete;
	PeerConnection(PeerConnection&&) = delete;
	PeerConnection& operator=(PeerConnection&&) = delete;

	// This does nothing now, but if we ever have timed maintenance tasks, they would go here
	virtual void Process() override;

	virtual bool SendMessage(const ActorContainer& peer, MessagePtr message) override;
	virtual void BroadcastMessage(MessagePtr message) override;

	virtual void SendIdentification(const ActorContainer& peer, const ActorIdentification& identity) const override;
	virtual void DropIdentification(const ActorContainer& peer, const ActorIdentification& identity) const override;
	virtual void RequestIdentities(const ActorContainer& peer) const override;

	virtual void Start() override;
	virtual void Stop() override;

	void AddHost(const std::string& address, uint16_t port) const;
	void RemoveHost(const std::string& address, uint16_t port) const;
	bool HasHost(const std::string& address, uint16_t port) const;

	uint16_t GetPort() const;

	NetworkAddress GetConnectionAddress(const std::string& uuid) const;
	std::string GetConnectionUUID(const NetworkAddress& address) const;
	void UpdateConnection(const std::string& uuid, NetworkAddress address);
	void DropConnection(const std::string& uuid);

protected:
	void PeerMessageHandler(const NetworkAddress& address, NetworkMessagePtr message);
	void OnSessionConnectedHandler(const NetworkAddress& address);
	void OnSessionDisconnectedHandler(const NetworkAddress& address);
	void OnRequestProcessHandler();

private:
	std::unique_ptr<mq::NetworkPeerAPI> m_network;
	std::unordered_map<std::string, NetworkAddress> m_connections;
};

//=============================================================================

} // namespace mq::postoffice
