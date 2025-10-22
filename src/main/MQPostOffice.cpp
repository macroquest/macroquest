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
#include "MQPostOffice.h"

#include "routing/ClientPostOffice.h"

#include "Logging.h"
#include "ModuleSystem.h"
#include "MQMain.h"

namespace mq {

using namespace eqlib;
using namespace postoffice;

bool InitializeCrashpad();
void InitializeCrashpadPipe(const std::string& pipeName);

//============================================================================

// Module representing the "Post Office" - a hub for named pipe communications with the
// launcher. Maintains a baseline level of integration with the launcher for things like
// focus tracking and state management.

class MQPostOffice final : public postoffice::ClientPostOffice,
	public MQModule
{
public:
	MQPostOffice();
	virtual ~MQPostOffice() override;

	// MQModule
	virtual void Initialize() override;
	virtual void Shutdown() override;
	virtual void OnGameStateChanged(int GameState) override;
	virtual void OnProcessFrame() override;

	void NotifyIsForegroundWindow(bool isForeground);
	void RequestActivateWindow(HWND hWnd, bool sendMessage);
	void SendNotification(const std::string& message, const std::string& title);

	void SendMessage(MQMessageId messageId, const void* data, size_t dataLength)
	{
		m_pipeClient.SendMessage(messageId, data, dataLength);
	}

	bool IsConnected() const
	{
		return m_pipeClient.IsConnected();
	}

private:
	virtual void OnIncomingMessage(PipeMessagePtr message) override;
	virtual void OnClientConnected() override;

	virtual void SendSelfIdentification() override;

	virtual postoffice::ActorIdentification::Client GetCurrentClient() const override;

	bool m_loggedIn = false;
	bool m_lastInForeground = false;
};

static MQPostOffice* s_postOffice = nullptr;

PostOffice& GetPostOffice()
{
	assert(s_postOffice != nullptr);
	return *s_postOffice;
}

DECLARE_MODULE_FACTORY(MQPostOffice);

//-----------------------------------------------------------------------------

static ActorIdentification::Client GetClientIdentification()
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
	, MQModule("PostOffice")
{
	s_postOffice = this;
}

MQPostOffice::~MQPostOffice()
{
	s_postOffice = nullptr;
}

void MQPostOffice::Initialize()
{
	ClientPostOffice::Initialize();
}

void MQPostOffice::Shutdown()
{
	ClientPostOffice::Shutdown();
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
	OnGameStateChanged(0);
}

void MQPostOffice::OnGameStateChanged(int GameState)
{
	if (ShouldUpdateIdentity(GameState, m_loggedIn))
	{
		postoffice::ClientPostOffice::SendSelfIdentification();
	}
}

void MQPostOffice::OnProcessFrame()
{
	if (mq::test_and_set(m_lastInForeground, gbInForeground))
	{
		NotifyIsForegroundWindow(m_lastInForeground);
	}

	ClientPostOffice::ProcessPipeClient();
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

		// FIXME:
		//g_mq->HandlePipeMessage(std::move(message));
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

bool IsConnected()
{
	if (s_postOffice)
	{
		return s_postOffice->IsConnected();
	}

	return false;
}

void SendPipeMessage(MQMessageId messageId, const void* data, size_t dataLength)
{
	if (s_postOffice)
	{
		s_postOffice->SendMessage(messageId, data, dataLength);
		return;
	}

	LOG_ERROR("Attempt to send message on named pipe without PostOffice module loaded");
}

bool RequestActivateWindow(HWND hWnd, bool sendMessage)
{
	if (sendMessage && IsConnected())
	{
		MQMessageFocusRequest request;
		request.focusMode = MQMessageFocusRequest::FocusMode::WantFocus;
		request.hWnd = hWnd;

		SendPipeMessage(MQMessageId::MSG_MAIN_FOCUS_REQUEST, &request, sizeof(request));
		return true;
	}

	ShowWindow(hWnd, SW_MINIMIZE);
	ShowWindow(hWnd, SW_RESTORE);
	return false;
}

bool SendTrayNotification(const std::string& title, const std::string& message)
{
	if (IsConnected())
	{
		proto::routing::Notification notification;

		notification.set_title(title);
		if (!message.empty())
		{
			notification.set_message(message);
		}

		std::string data = notification.SerializeAsString();
		SendPipeMessage(MQMessageId::MSG_MAIN_TRAY_NOTIFY, data.data(), data.size());

		return true;
	}

	return false;
}

} // namespace pipeclient
} // namespace mq
