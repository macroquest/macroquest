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

#include "pch.h"

#include "Logging.h"
#include "MQPostOffice.h"
#include "MQ2Main.h"

namespace mq {

using namespace postoffice;

static void InitializePostOffice();
static void ShutdownPostOffice();
static void PulsePostOffice();
static void SetGameStatePostOffice(int GameState);

bool InitializeCrashpad();
void InitializeCrashpadPipe(const std::string& pipeName);

static MQModule s_PostOfficeModule = {
	"PostOffice",
	false,
	InitializePostOffice,                                       // Initialize
	ShutdownPostOffice,                                         // Shutdown
	PulsePostOffice,                                            // Pulse
	SetGameStatePostOffice,                                     // SetGameState
	nullptr,                                                    // UpdateImGui
	nullptr,                                                    // Zoned
	nullptr,                                                    // WriteChatColor
	nullptr,                                                    // SpawnAdded
	nullptr,                                                    // SpawnRemoved
	nullptr,                                                    // BeginZone
	nullptr,                                                    // EndZone
	nullptr,                                                    // LoadPlugin
	nullptr                                                     // UnloadPlugin
};
MQModule* GetPostOfficeModule() { return &s_PostOfficeModule; }

static MQPostOffice* s_postOffice = nullptr;

//-----------------------------------------------------------------------------

ActorIdentification::Client GetClientIdentification()
{
	ActorIdentification::Client client;
	if (__LoginName)
	{
		client.account = (char*)__LoginName;
	}

	if (pEverQuestInfo->WorldServerShortname[0] != 0)
	{
		client.server = pEverQuestInfo->WorldServerShortname;
	}

	if (pLocalPC)
	{
		client.character = pLocalPC->Name;
	}

	return client;
}

//-----------------------------------------------------------------------------

MQPostOffice::MQPostOffice()
	: ClientPostOffice("MQPostOffice", mq::MQ_PIPE_SERVER_PATH, ActorIdentification(ActorContainer(
		ActorContainer::CurrentProcess, CreateUUID()), GetClientIdentification()))
{
}

MQPostOffice::~MQPostOffice()
{
}

//-----------------------------------------------------------------------------

void MQPostOffice::NotifyIsForegroundWindow(bool isForeground)
{
	MQMessageFocusRequest request;
	request.focusMode = MQMessageFocusRequest::FocusMode::HasFocus;
	request.state = isForeground;
	request.processId = GetCurrentProcessId();

	m_pipeClient.SendMessage(MQMessageId::MSG_MAIN_FOCUS_REQUEST, &request, sizeof(request));
}

void MQPostOffice::RequestActivateWindow(HWND hWnd, bool sendMessage)
{
	if (IsIconic(hWnd))
	{
		ShowWindow(hWnd, SW_RESTORE);
	}

	if (::SetForegroundWindow(hWnd))
		return;

	if (sendMessage && m_pipeClient.IsConnected())
	{
		MQMessageFocusRequest request;
		request.focusMode = MQMessageFocusRequest::FocusMode::WantFocus;
		request.hWnd = hWnd;

		m_pipeClient.SendMessage(MQMessageId::MSG_MAIN_FOCUS_REQUEST, &request, sizeof(request));
		return;
	}

	ShowWindow(hWnd, SW_MINIMIZE);
	ShowWindow(hWnd, SW_RESTORE);
}

void MQPostOffice::SendNotification(const std::string& message, const std::string& title)
{
	if (m_pipeClient.IsConnected())
	{
		proto::routing::Notification notification;
		notification.set_title(title);
		if (!message.empty())
			notification.set_message(message);

		m_pipeClient.SendProtoMessage(MQMessageId::MSG_MAIN_TRAY_NOTIFY, notification);
	}
}

static bool ShouldUpdateIdentity(int GameState, bool& logged_in)
{
	// 0 is sent from init
	if (GameState == 0)
	{
		if (pLocalPC)
			logged_in = true;

		return true;
	}

	if (logged_in && GameState != GAMESTATE_LOGGINGIN && GameState != GAMESTATE_INGAME)
	{
		// this is used only when we are changing characters
		logged_in = false;
		return true;
	}

	if (!logged_in && (GameState == GAMESTATE_LOGGINGIN || GameState == GAMESTATE_INGAME))
	{
		logged_in = true;
		return true;
	}

	return false;
}

void MQPostOffice::SendSelfIdentification()
{
	SetGameState(0);
}

void MQPostOffice::SetGameState(int GameState)
{
	if (ShouldUpdateIdentity(GameState, m_loggedIn))
	{
		postoffice::ClientPostOffice::SendSelfIdentification();
	}
}

//-----------------------------------------------------------------------------

void MQPostOffice::OnIncomingMessage(PipeMessagePtr message)
{
	switch (message->GetMessageId())  // NOLINT(clang-diagnostic-switch-enum)
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
		DoCommand("/unload", true);
		break;

	case MQMessageId::MSG_MAIN_REQ_FORCEUNLOAD:
		DoCommand("/unload force", true);
		break;

	case MQMessageId::MSG_MAIN_PROCESS_LOADED: {
		// This is the response to our connection message below.
		if (message->size() >= sizeof(MQMessageProcessLoadedResponse))
		{
			const MQMessageProcessLoadedResponse* response = message->get<MQMessageProcessLoadedResponse>();
			m_launcherProcessID = response->processId;

			LOG_TRACE("Launcher process ID: {}", m_postOffice->m_launcherProcessID);
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

	default:
		ClientPostOffice::OnIncomingMessage(std::move(message));
		break;
	}
}

void MQPostOffice::OnClientConnected()
{
	ClientPostOffice::OnClientConnected();

	MQMessageProcessLoadedFromMQ msg;
	msg.processId = GetCurrentProcessId();
	m_pipeClient.SendMessage(MQMessageId::MSG_MAIN_PROCESS_LOADED, &msg, sizeof(msg));
}

postoffice::ActorIdentification::Client MQPostOffice::GetCurrentClient() const
{
	return GetClientIdentification();
}

namespace pipeclient {

void NotifyIsForegroundWindow(bool isForeground)
{
	if (s_postOffice)
	{
		s_postOffice->NotifyIsForegroundWindow(isForeground);
	}
}

void RequestActivateWindow(HWND hWnd, bool sendMessage)
{
	if (s_postOffice)
	{
		s_postOffice->RequestActivateWindow(hWnd, sendMessage);
	}
}

void SendNotification(const std::string& message, const std::string& title)
{
	if (s_postOffice)
	{
		s_postOffice->SendNotification(message, title);
	}
}

} // namespace pipeclient

void InitializePostOffice()
{
	if (s_postOffice == nullptr)
	{
		s_postOffice = new MQPostOffice();
		s_postOffice->Initialize();
	}
}

void ShutdownPostOffice()
{
	if (s_postOffice != nullptr)
	{
		s_postOffice->Shutdown();

		delete s_postOffice;
		s_postOffice = nullptr;
	}
}

void PulsePostOffice()
{
	if (s_postOffice)
	{
		s_postOffice->ProcessPipeClient();
	}
}

void SetGameStatePostOffice(int GameState)
{
	if (s_postOffice)
	{
		s_postOffice->SetGameState(GameState);
	}
}

MQPostOffice& GetPostOffice()
{
	assert(s_postOffice != nullptr);
	return *s_postOffice;
}

} // namespace mq
