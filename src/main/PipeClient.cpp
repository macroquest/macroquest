/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2023 MacroQuest Authors
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

#include "pch.h"
#include "PipeClient.h"
#include "CrashHandler.h"

#include "MQ2Main.h"
#include "common/NamedPipes.h"

namespace mq {

NamedPipeClient gPipeClient{ mq::MQ2_PIPE_SERVER_PATH };
DWORD dwLauncherProcessID = 0;

// we can't use a MQModule here (at least not for init/shutdown) because initialization order matters.

class PipeEventsHandler : public NamedPipeEvents
{
public:
	virtual void OnIncomingMessage(std::shared_ptr<PipeMessage> message) override
	{
		switch (message->GetMessageId())
		{
		case MQMessageId::MSG_MAIN_CRASHPAD_CONFIG:
			// Message needs to at least have some substance...
			if (message->size() > 0)
			{
				std::string pipeName{ message->get<const char>() };

				if (pipeName.empty())
				{
					InitializeCrashpad();
				}
				else
				{
					InitializeCrashpadPipe(pipeName);
				}
			}
			break;

		case MQMessageId::MSG_MAIN_REQ_UNLOAD:
			HideDoCommand(pLocalPlayer, "/unload", true);
			break;

		case MQMessageId::MSG_MAIN_REQ_FORCEUNLOAD:
			HideDoCommand(pLocalPlayer, "/unload force", true);
			break;

		case MQMessageId::MSG_MAIN_PROCESS_LOADED: {
			// This is the response to our connection message below.
			if (message->size() >= sizeof(MQMessageProcessLoadedResponse))
			{
				const MQMessageProcessLoadedResponse* response = message->get<MQMessageProcessLoadedResponse>();
				dwLauncherProcessID = response->processId;

				SPDLOG_DEBUG("Launcher process ID: {}", dwLauncherProcessID);
			}
			break;
		}

		case MQMessageId::MSG_MAIN_FOCUS_ACTIVATE_WND:
			if (message->size() >= sizeof(MQMessageActivateWnd))
			{
				const MQMessageActivateWnd* request = message->get<MQMessageActivateWnd>();

				pipeclient::RequestActivateWindow((HWND)request->hWnd, false);
			}
			break;

		default: break;
		}
	}

	virtual void OnClientConnected() override
	{
		//SPDLOG_DEBUG("Connection to named pipe created, Sending process loaded message.");

		MQMessageProcessLoadedFromMQ msg;
		msg.processId = GetCurrentProcessId();
		gPipeClient.SendMessage(MQMessageId::MSG_MAIN_PROCESS_LOADED, &msg, sizeof(msg));
	}
};

namespace pipeclient {

// mq::MQMessageId::MSG_AUTOLOGIN_PROFILE_LOADED:
// mq::MQMessageId::MSG_AUTOLOGIN_PROFILE_UNLOADED:
// mq::MQMessageId::MSG_AUTOLOGIN_PROFILE_CHARINFO:
// mq::MQMessageId::MSG_AUTOLOGIN_START_INSTANCE:

// This serialization is dead simple. Just separate fields with a colon. Assume no colons in the
// source data. If this needs to be performant in any way, then we will need to write actual
// serialization of binary data (with the bonus that it's not all strings).

// profile:account:server:char:pid
void NotifyCharacterLoad(const char* Profile, const char* Account, const char* Server, const char* Character)
{
	auto data = fmt::format("{}:{}:{}:{}:{}", Profile, Account, Server, Character, GetCurrentProcessId());
	gPipeClient.SendMessage(MQMessageId::MSG_AUTOLOGIN_PROFILE_LOADED, data.c_str(), data.length());
}

// profile:account:server:char:pid
void NotifyCharacterUnload(const char* Profile, const char* Account, const char* Server, const char* Character)
{
	auto data = fmt::format("{}:{}:{}:{}:{}", Profile, Account, Server, Character, GetCurrentProcessId());
	gPipeClient.SendMessage(MQMessageId::MSG_AUTOLOGIN_PROFILE_UNLOADED, data.c_str(), data.length());
}

// pid:class:level
void NotifyCharacterUpdate(int Class, int Level)
{
	auto data = fmt::format("{}:{}:{}", GetCurrentProcessId(), Class, Level);
	gPipeClient.SendMessage(MQMessageId::MSG_AUTOLOGIN_PROFILE_CHARINFO, data.c_str(), data.length());
}

void LoginServer(const char* Login, const char* Pass, const char* Server)
{
	auto data = fmt::format("s:{}:{}:{}", Login, Pass, Server);
	gPipeClient.SendMessage(MQMessageId::MSG_AUTOLOGIN_START_INSTANCE, data.c_str(), data.length());
}

void LoginCharacter(const char* Login, const char* Pass, const char* Server, const char* Character)
{
	auto data = fmt::format("c:{}:{}:{}:{}", Login, Pass, Server, Character);
	gPipeClient.SendMessage(MQMessageId::MSG_AUTOLOGIN_START_INSTANCE, data.c_str(), data.length());
}

void LoginProfile(const char* Profile, const char* Server, const char* Character)
{
	auto data = fmt::format("p:{}:{}:{}", Profile, Server, Character);
	gPipeClient.SendMessage(MQMessageId::MSG_AUTOLOGIN_START_INSTANCE, data.c_str(), data.length());
}

uint32_t GetLauncherProcessID()
{
	if (gPipeClient.IsConnected())
		return dwLauncherProcessID;

	return 0;
}

void NotifyIsForegroundWindow(bool isForeground)
{
	MQMessageFocusRequest request;
	request.focusMode = MQMessageFocusRequest::FocusMode::HasFocus;
	request.state = isForeground;
	request.processId = GetCurrentProcessId();

	gPipeClient.SendMessage(MQMessageId::MSG_MAIN_FOCUS_REQUEST, &request, sizeof(request));
}

void RequestActivateWindow(HWND hWnd, bool sendMessage)
{
	if (IsIconic(hWnd))
	{
		ShowWindow(hWnd, SW_RESTORE);
	}

	if (::SetForegroundWindow(hWnd))
		return;

	if (sendMessage && gPipeClient.IsConnected())
	{
		MQMessageFocusRequest request;
		request.focusMode = MQMessageFocusRequest::FocusMode::WantFocus;
		request.hWnd = hWnd;

		gPipeClient.SendMessage(MQMessageId::MSG_MAIN_FOCUS_REQUEST, &request, sizeof(request));
		return;
	}

	ShowWindow(hWnd, SW_MINIMIZE);
	ShowWindow(hWnd, SW_RESTORE);
}

} // namespace pipeclient

void InitializePipeClient()
{
	gPipeClient.SetHandler(std::make_shared<PipeEventsHandler>());
	gPipeClient.Start();
	::atexit([]() { gPipeClient.Stop(); });
}

void ShutdownPipeClient()
{
	gPipeClient.Stop();
}

} // namespace mq
