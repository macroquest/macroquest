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

#include "routing/NamedPipes.h"
#include "routing/PostOffice.h"
#include "loader/Network.h"

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
constexpr uint16_t DEFAULT_ACTOR_PEER_PORT = 7781;

void RoutingFailed(
	int status,
	const PipeMessagePtr& message,
	const PipeMessageResponseCb& callback);

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
	~LauncherPostOffice() override = default;

	const PostOfficeConfig& GetConfig() const { return m_config; }
	const std::string& GetName() const { return m_config.Name; }

	// TODO: This isn't right, it's only checking the address and not the container
	static bool IsRecipient(const proto::routing::Address& address, const ActorIdentification& id);

	auto FindIdentity(
		const proto::routing::Address& address,
		const std::unordered_multimap<ActorContainer, ActorIdentification>::iterator& from);

	// This is called when a dropbox registered to this pipe server attempts to send a message (an _outbound_ message)
	void RouteMessage(PipeMessagePtr&& message, const PipeMessageResponseCb& callback) override;
	void OnDeliver(const std::string& localAddress, PipeMessagePtr& message) override;

	// This is called when a message is received over a connection (an _inbound_ message)
	void RouteFromConnection(const proto::routing::Envelope& message);

	void AddIdentity(const ActorIdentification& id);
	void DropIdentity(const ActorIdentification& id);
	void DropContainer(const ActorContainer& container);
	void SendIdentities(const ActorContainer& requester);

	void Initialize();
	void Shutdown();

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

	template <size_t I = 0> void ProcessConnections();
	template <size_t I = 0> void BroadcastMessage(PipeMessagePtr&& message);
	template <typename T> void BroadcastMessage(const MQMessageId& id, const T& proto);
	bool SendMessage(const ActorContainer& ident, PipeMessagePtr&& message, const PipeMessageResponseCb& callback);
	template <typename T> bool SendMessage(const ActorContainer& ident, const MQMessageId& id, const T& proto, const PipeMessageResponseCb& callback);
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

	// TODO: this can be a single templated function that will fail to compile if there are any calls to sending to the wrong kind of container
	virtual bool SendMessage(uint32_t pid, PipeMessagePtr&& message, const PipeMessageResponseCb& callback) = 0;
	virtual bool SendMessage(const ActorContainer::Network& peer, PipeMessagePtr&& message, const PipeMessageResponseCb& callback) = 0;
	virtual void BroadcastMessage(PipeMessagePtr&& message) = 0;

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
	void RequestProcessEvents();

	bool SendMessage(
		uint32_t pid,
		PipeMessagePtr&& message,
		const PipeMessageResponseCb& callback) override;

	bool SendMessage(
		const ActorContainer::Network& peer,
		PipeMessagePtr&& message,
		const PipeMessageResponseCb& callback) override;

	void BroadcastMessage(PipeMessagePtr&& message) override;
	void RouteFromPipe(PipeMessagePtr&& message);
	void RouteToPipe(int connectionId, PipeMessagePtr&& message);
	void DropProcessId(uint32_t processId) const;

	void OnDeliver(const std::string& localAddress, PipeMessagePtr& message);

	bool SendSetForegroundWindow(HWND hWnd, uint32_t processID);
	void SendUnloadAllCommand();
	void SendForceUnloadAllCommand();
	
private:
	mq::ProtoPipeServer m_pipeServer;

	bool m_running = false;
	std::thread m_thread;
	std::thread::id m_threadId;

	bool m_hasMessages = false;
	std::mutex m_processMutex;
	std::condition_variable m_needsProcessing;
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

	bool SendMessage(uint32_t pid, PipeMessagePtr&& message, const PipeMessageResponseCb& callback) override;
	bool SendMessage(const ActorContainer::Network& peer, PipeMessagePtr&& message, const PipeMessageResponseCb& callback) override;
	void BroadcastMessage(PipeMessagePtr&& message) override;

	void AddHost(const std::string& address, uint16_t port) const;
	void RemoveHost(const std::string& address, uint16_t port) const;

private:
	NetworkPeerAPI m_network;

	proto::routing::NetworkMessage Translate(const PipeMessagePtr& message);
};

} // namespace postoffice
