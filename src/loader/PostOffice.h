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

#pragma once

#include <string>
#include <optional>
#include <vector>

#include "routing/PostOffice.h"

#if defined(SendMessage)
#undef SendMessage
#endif

namespace mq {
struct MQMessageFocusRequest;
class ProtoPipeServer;
class PipeConnection;
class NetworkPeerAPI;
} // namespace mq

using GetCrashpadPipe = std::function<std::string()>;
using RequestFocusCallback = std::function<void(const mq::MQMessageFocusRequest*)>;

// setting these configs is to allow testing without spoofing config files
struct PostOfficeConfig
{
	uint32_t Index;
	std::string Name; // useful for debugging
	uint16_t PeerPort = mq::DEFAULT_NETWORK_PEER_PORT;
	std::string PipeName = mq::MQ_PIPE_SERVER_PATH;
	std::optional<std::vector<std::pair<std::string, uint16_t>>> Peers;
};

const PostOfficeConfig& GetPostOfficeConfig(uint32_t index);
void SetPostOfficeConfig(const PostOfficeConfig& config);
void DropPostOfficeConfig(uint32_t index);
void ClearPostOfficeConfigs();
void ClearPostOffices();

bool SendSetForegroundWindow(HWND hWnd, uint32_t processID);
void SendUnloadAllCommand();
void SendForceUnloadAllCommand();

void SetPostOfficeIni(std::string_view ini);
void SetCrashpadCallback(const GetCrashpadPipe& getCrashpad);
void SetRequestFocusCallback(const RequestFocusCallback& requestFocus);
void SetTriggerPostOffice(const std::function<void()>& triggerProcess);
void InitializePostOffice(uint32_t index = 0);
void ShutdownPostOffice(uint32_t index = 0);

namespace mq::postoffice {

// ----------------------------- Post Office ----------------------------------

template <typename T>
struct ConnectionTypeMap;

class LocalConnection;
class PeerConnection;

template <> struct ConnectionTypeMap<ActorContainer::Process> { using Type = LocalConnection; };
template <> struct ConnectionTypeMap<ActorContainer::Network> { using Type = PeerConnection; };

class LauncherPostOffice final : public PostOffice
{
public:
	LauncherPostOffice() = delete;
	LauncherPostOffice(const LauncherPostOffice&) = delete;
	LauncherPostOffice(LauncherPostOffice&&) = delete;
	LauncherPostOffice& operator=(const LauncherPostOffice&) = delete;
	LauncherPostOffice& operator=(LauncherPostOffice&&) = delete;

	explicit LauncherPostOffice(const PostOfficeConfig& config);
	~LauncherPostOffice() override;

	const PostOfficeConfig& GetConfig() const { return m_config; }
	const std::string& GetName() const { return m_name; }

	bool IsRecipient(const proto::routing::Address& address, const ActorIdentification& id);

	auto FindIdentity(
		const proto::routing::Address& address,
		const std::unordered_multimap<ActorContainer, ActorIdentification>::iterator& from);

	// This is called when a dropbox registered to this pipe server attempts to send a message (an _outbound_ message)
	void RouteMessage(MessagePtr message) override;
	void OnDeliver(const std::string& localAddress, MessagePtr& message) override;

	// This is called when a message is received over a connection (an _inbound_ message)
	void RouteFromConnection(MessagePtr message);

	void AddNetworkHost(const std::string& address, uint16_t port) const;
	void RemoveNetworkHost(const std::string& address, uint16_t port) const;
	uint16_t GetPeerPort() const;

	void AddIdentity(const ActorIdentification& id);
	void DropIdentity(const ActorIdentification& id);
	void DropContainer(const ActorContainer& container);
	void SendIdentities(const ActorContainer& requester);

	void Initialize();
	void Shutdown();
	void RequestProcessEvents();

	template <typename I, typename C = typename ConnectionTypeMap<I>::Type>
	const std::unique_ptr<C>& GetConnection()
	{
		static_assert(std::is_same_v<I, C>, "Type does not point to a valid connection.");
	}

private:
	PostOfficeConfig m_config;
	std::string m_name;

	std::unordered_multimap<ActorContainer, ActorIdentification> m_identities;

	const std::unique_ptr<LocalConnection> m_localConnection;
	const std::unique_ptr<PeerConnection> m_peerConnection;

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

	template <size_t I = 0> void StartConnections();
	template <size_t I = 0> void StopConnections();
	template <size_t I = 0> void ProcessConnections();
	template <size_t I = 0> void BroadcastMessage(MessagePtr message);
	bool SendMessage(const ActorContainer& ident, MessagePtr message);
	void SendIdentification(const ActorContainer& target, const ActorIdentification& id);
	void DropIdentification(const ActorContainer& target, const ActorIdentification& id);
	void RequestIdentities(const ActorContainer& from);

	void ProcessOutgoing();
	void ProcessOutgoingMessage(MessagePtr);

	void ProcessIdentities();
	void ProcessAddIdentity(const ActorIdentification& id);
	void ProcessDropIdentity(const ActorIdentification& id);
	void ProcessDropContainer(const ActorContainer& container);
	void ProcessSendIdentities(const ActorContainer& requester);

	void FillAndSend(MessagePtr message, std::function<bool(const ActorIdentification&)> predicate);
};

// ----------------------------- Connection -----------------------------------

class Connection
{
public:
	Connection() = delete;
	Connection(const Connection&) = delete;
	Connection(Connection&&) = delete;
	Connection& operator=(const Connection&) = delete;
	Connection& operator=(Connection&&) = delete;

	virtual ~Connection() = default;

	explicit Connection(LauncherPostOffice* postOffice)
		: m_postOffice(postOffice)
	{}

	virtual void Process() = 0;

	virtual void BroadcastMessage(MessagePtr message) = 0;

	virtual void Start() = 0;
	virtual void Stop() = 0;
	void RequestProcessEvents();

	LauncherPostOffice* GetPostOffice() const { return m_postOffice; }

protected:
	LauncherPostOffice* m_postOffice;
};

class LocalConnection final : public Connection
{
public:
	LocalConnection() = delete;
	LocalConnection(const LocalConnection&) = delete;
	LocalConnection(LocalConnection&&) = delete;
	LocalConnection& operator=(const LocalConnection&) = delete;
	LocalConnection& operator=(LocalConnection&&) = delete;

	LocalConnection(LauncherPostOffice* postOffice);
	~LocalConnection();
	void Process() override;

	bool SendMessage(const ActorContainer::Process& process, MessagePtr message);

	void SendIdentification(const ActorContainer::Process& process, const ActorIdentification& identity) const;
	void DropIdentification(const ActorContainer::Process& process, const ActorIdentification& identity) const;
	void RequestIdentities(const ActorContainer::Process& process) const;

	void BroadcastMessage(MessagePtr message) override;
	void RouteFromPipe(MessagePtr message);
	void DropProcess(const ActorContainer::Process& process) const;

	void Start() override;
	void Stop() override;

	bool SendSetForegroundWindow(HWND hWnd, uint32_t processID);
	void SendUnloadAllCommand();
	void SendForceUnloadAllCommand();

	mq::ProtoPipeServer* GetPipeServer() { return m_pipeServer.get(); }

	int GetConnectionID(const std::string& uuid) const;
	std::string GetConnectionUUID(int connectionID) const;
	void UpdateConnection(const std::string& uuid, int connectionID);
	
private:
	std::shared_ptr<mq::PipeConnection> GetConnection(const std::string& uuid) const;

	std::unique_ptr<mq::ProtoPipeServer> m_pipeServer;
	std::unordered_map<std::string, int> m_connections;
	const std::string m_uuid; // this is the same as the postoffice uuid, memoize for quicker reference

};

class PeerConnection final : public Connection
{
public:
	PeerConnection() = delete;
	PeerConnection(const PeerConnection&) = delete;
	PeerConnection(PeerConnection&&) = delete;
	PeerConnection& operator=(const PeerConnection&) = delete;
	PeerConnection& operator=(PeerConnection&&) = delete;

	PeerConnection(LauncherPostOffice* postOffice);
	~PeerConnection() override;
	void AddConfiguredHosts();

	// This does nothing now, but if we ever have timed maintenance tasks, they would go here
	void Process() override;

	bool SendMessage(const ActorContainer::Network& peer, MessagePtr message);

	void SendIdentification(const ActorContainer::Network& peer, const ActorIdentification& identity) const;
	void DropIdentification(const ActorContainer::Network& peer, const ActorIdentification& identity) const;
	void RequestIdentities(const ActorContainer::Network& peer) const;

	void BroadcastMessage(MessagePtr message) override;

	void Start() override;
	void Stop() override;

	void AddHost(const std::string& address, uint16_t port) const;
	void RemoveHost(const std::string& address, uint16_t port) const;

	uint16_t GetPort() const;

private:
	std::unique_ptr<mq::NetworkPeerAPI> m_network;
};

} // namespace postoffice
