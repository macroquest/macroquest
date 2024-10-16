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
class NetworkPeerAPI;
} // namespace mq

using GetCrashpadPipe = std::function<std::string()>;
using RequestFocusCallback = std::function<void(const mq::MQMessageFocusRequest*)>;

// setting these configs is to allow testing without spoofing config files
struct PostOfficeConfig
{
	std::string Name; // useful for debugging
	std::optional<uint16_t> PeerPort;
	std::optional<std::string> PipeName;
	std::optional<std::vector<std::pair<std::string, uint16_t>>> Peers;
};

const PostOfficeConfig& GetPostOfficeConfig(uint32_t index);
void SetPostOfficeConfig(uint32_t index, const PostOfficeConfig& config);
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

template <> struct ConnectionTypeMap<uint32_t> { using Type = LocalConnection; };
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
	const std::string& GetName() const { return m_config.Name; }

	bool IsRecipient(const proto::routing::Address& address, const ActorIdentification& id);

	auto FindIdentity(
		const proto::routing::Address& address,
		const std::unordered_multimap<ActorContainer, ActorIdentification>::iterator& from);

	// This is called when a dropbox registered to this pipe server attempts to send a message (an _outbound_ message)
	void RouteMessage(proto::routing::Envelope&& message, const MessageResponseCallback& callback) override;
	void OnDeliver(const std::string& localAddress, proto::routing::Envelope& message) override;

	// This is called when a message is received over a connection (an _inbound_ message)
	void RouteFromConnection(proto::routing::Envelope&& message);

	void RoutingFailed(int status, proto::routing::Envelope&& message, const MessageResponseCallback& callback);

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
	const PostOfficeConfig m_config;

	std::unordered_multimap<ActorContainer, ActorIdentification> m_identities;

	Dropbox m_serverDropbox;
	const std::unique_ptr<LocalConnection> m_localConnection;
	const std::unique_ptr<PeerConnection> m_peerConnection;

	bool m_running = false;
	std::thread m_thread;
	std::thread::id m_threadId;

	bool m_hasMessages = false;
	std::mutex m_processMutex;
	std::condition_variable m_needsProcessing;

	template <size_t I = 0> void ProcessConnections();
	template <size_t I = 0> void BroadcastMessage(proto::routing::Envelope&& message);
	bool SendMessage(const ActorContainer& ident, proto::routing::Envelope&& message, const MessageResponseCallback& callback);
	void SendIdentification(const ActorContainer& target, const ActorIdentification& id);
	void DropIdentification(const ActorContainer& target, const ActorIdentification& id);
	void RequestIdentities(const ActorContainer& from);
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

	virtual void BroadcastMessage(proto::routing::Envelope&& message) = 0;

	virtual void Start() = 0;
	virtual void Stop() = 0;
	void RequestProcessEvents(); // TODO: the network connection never calls this, does it need to?

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

	bool SendMessage(
		uint32_t pid,
		proto::routing::Envelope&& message,
		const MessageResponseCallback& callback);

	void SendIdentification(uint32_t pid, const ActorIdentification& identity) const;
	void DropIdentification(uint32_t pid, const ActorIdentification& identity) const;
	void RequestIdentities(uint32_t pid) const;

	void BroadcastMessage(proto::routing::Envelope&& message) override;
	void RouteFromPipe(proto::routing::Envelope&& message);
	void DropProcessId(uint32_t processId) const;

	void Start() override;
	void Stop() override;

	bool SendSetForegroundWindow(HWND hWnd, uint32_t processID);
	void SendUnloadAllCommand();
	void SendForceUnloadAllCommand();

	mq::ProtoPipeServer* GetPipeServer() { return m_pipeServer.get(); }
	
private:
	std::unique_ptr<mq::ProtoPipeServer> m_pipeServer;

	std::unordered_map<uint32_t, MessageResponseCallback> m_rpcs;
};

class PeerConnection final : public Connection
{
public:
	PeerConnection() = delete;
	PeerConnection(const PeerConnection&) = delete;
	PeerConnection(PeerConnection&&) = delete;
	PeerConnection& operator=(const PeerConnection&) = delete;
	PeerConnection& operator=(PeerConnection&&) = delete;

	// TODO: make the port configurable (default to 7781)
	PeerConnection(LauncherPostOffice* postOffice);
	~PeerConnection() override;
	void AddConfiguredHosts();

	// This does nothing now, but if we ever have timed maintenance tasks, they would go here
	void Process() override {}

	bool SendMessage(
		const ActorContainer::Network& peer,
		proto::routing::Envelope&& message,
		const MessageResponseCallback& callback);

	void SendIdentification(const ActorContainer::Network& peer, const ActorIdentification& identity) const;
	void DropIdentification(const ActorContainer::Network& peer, const ActorIdentification& identity) const;
	void RequestIdentities(const ActorContainer::Network& peer) const;

	void BroadcastMessage(proto::routing::Envelope&& message) override;

	void Start() override;
	void Stop() override;

	void AddHost(const std::string& address, uint16_t port) const;
	void RemoveHost(const std::string& address, uint16_t port) const;

	uint16_t GetPort() const;

private:
	std::unique_ptr<mq::NetworkPeerAPI> m_network;
};

} // namespace postoffice
