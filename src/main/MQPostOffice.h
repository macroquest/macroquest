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

#if !defined(MQ2MAIN_IMPL) && !defined(__clang__)
#error This header should only be included from the MQ2Main project
#endif

#include "routing/PostOffice.h"
#include "routing/ProtoPipes.h"

#include <string>
#include <optional>

namespace mq {

struct MQPostOfficeConfig
{
	uint32_t Index = 0;
	std::string Name = "MQPostOffice"; // useful for debugging
	std::string PipeName = mq::MQ_PIPE_SERVER_PATH;
	std::optional<std::string> AccountOverride;
	std::optional<std::string> ServerOverride;
	std::optional<std::string> CharacterOverride;
};

// this post office has exactly one connection, the pipe connection that connects to the launcher for routing. With
// that in mind, this is going to couple the post office and the connection because there's no intention of creating
// more types of connections in main
class MQPostOffice : public postoffice::PostOffice
{
private:

	class PipeEventsHandler : public NamedPipeEvents
	{
	public:
		PipeEventsHandler(MQPostOffice* postOffice) : m_postOffice(postOffice) {}
		virtual void OnIncomingMessage(PipeMessagePtr message) override;
		virtual void OnClientConnected() override;

	private:
		MQPostOffice* m_postOffice;
	};

public:

	explicit MQPostOffice(const MQPostOfficeConfig& config);

	const MQPostOfficeConfig& GetConfig() const { return m_config; }
	const std::string& GetName() const { return m_config.Name; }

	std::unordered_map<const std::string, std::unique_ptr<postoffice::Mailbox>>::iterator FindMailbox(
		const proto::routing::Address& address,
		const std::unordered_map<const std::string, std::unique_ptr<postoffice::Mailbox>>::iterator& from);

	void RouteMessage(postoffice::MessagePtr message) override;

	void ProcessPipeClient();
	void NotifyIsForegroundWindow(bool isForeground);
	void RequestActivateWindow(HWND hWnd, bool sendMessage);
	void SendNotification(const std::string& message, const std::string& title);

	void SetGameStatePostOffice(int GameState);
	void Initialize();
	void Shutdown();

private:
	MQPostOfficeConfig m_config;

	ProtoPipeClient m_pipeClient;
	postoffice::Dropbox m_clientDropbox;
	DWORD m_launcherProcessID;

	static void StopPipeClient();
};

// setting these configs is to allow testing without spoofing config files
MQPostOfficeConfig GetPostOfficeConfig(uint32_t index);
void SetPostOfficeConfig(const MQPostOfficeConfig& config);
void DropPostOfficeConfig(uint32_t index);
void ClearPostOfficeConfigs();
void ClearPostOffices();

void InitializePostOffice(uint32_t index = 0);
void ShutdownPostOffice(uint32_t index = 0);
void PulsePostOffice(uint32_t index = 0);
void SetGameStatePostOffice(int GameState, uint32_t index = 0);

namespace pipeclient {
// this namespace is for interfaces that directly send messages over the pipe, without the
// need for a post office. The only reason they are here is because the post office handles
// the pipe connection

void NotifyIsForegroundWindow(bool isForeground);
void RequestActivateWindow(HWND hWnd, bool sendMessage = true);
void SendNotification(const std::string& message, const std::string& title);

} // namespace pipeclient

} // namespace mq
