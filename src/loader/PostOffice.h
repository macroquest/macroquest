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

#include "routing/NamedPipesProtocol.h"
#include "loader/Network.h"

using GetCrashpadPipe = std::function<std::string()>;
using RequestFocusCallback = std::function<void(const mq::MQMessageFocusRequest*)>;

// setting these configs is to allow testing without spoofing config files
struct PostOfficeConfig
{
	std::optional<uint16_t> PeerPort;
	std::optional<std::string> PipeName;
	std::optional<std::vector<std::pair<std::string, uint16_t>>> Peers;
};

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
void ProcessPostOffice(uint32_t index = 0);
void InitializePostOffice(uint32_t index = 0);
void ShutdownPostOffice(uint32_t index = 0);

namespace postoffice {
class LauncherPostOffice;

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
	virtual bool SendMessage(const Network& peer, PipeMessagePtr&& message, const PipeMessageResponseCb& callback) = 0;
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

	LocalConnection(LauncherPostOffice* postOffice, uint32_t index);
	~LocalConnection();
	void Process() override;

	bool SendMessage(
		uint32_t pid,
		PipeMessagePtr&& message,
		const PipeMessageResponseCb& callback) override;

	bool SendMessage(
		const Network& peer,
		PipeMessagePtr&& message,
		const PipeMessageResponseCb& callback) override;

	void BroadcastMessage(PipeMessagePtr&& message) override;
	void RouteFromPipe(PipeMessagePtr&& message);
	void RouteToPipe(int connectionId, PipeMessagePtr&& message);
	void DropProcessId(uint32_t processId) const;

	bool SendSetForegroundWindow(HWND hWnd, uint32_t processID);
	void SendUnloadAllCommand();
	void SendForceUnloadAllCommand();
	
private:
	mq::ProtoPipeServer m_pipeServer;
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
	PeerConnection(LauncherPostOffice* postOffice, uint32_t index);
	~PeerConnection() override;

	// This does nothing now, but if we ever have timed maintenance tasks, they would go here
	void Process() override {}

	bool SendMessage(uint32_t pid, PipeMessagePtr&& message, const PipeMessageResponseCb& callback) override;
	bool SendMessage(const Network& peer, PipeMessagePtr&& message, const PipeMessageResponseCb& callback) override;
	void BroadcastMessage(PipeMessagePtr&& message) override;

	// TODO: need add_connection/remove_connection callbacks in NetworkAPI

private:
	NetworkPeerAPI m_network;

	static proto::routing::NetworkMessage Translate(const PipeMessagePtr& message);
};

} // namespace postoffice
