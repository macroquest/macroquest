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

#include "routing/PostOffice.h"
#include "loader/PostOffice.h"

#include "loader/ImGui.h"
#include "loader/MacroQuest.h"
#include "routing/NamedPipes.h"
#include "routing/ProtoPipes.h"

#include <shellapi.h>

static std::optional<std::string> s_iniLocation;
static LauncherPostOffice* s_postOffice = nullptr;

// pipe specific statics
static std::optional<GetCrashpadPipe> s_crashpadCallback;
static std::optional<std::function<void()>> s_triggerProcess;
static std::optional<RequestFocusCallback> s_requestFocusCallback;

//-----------------------------------------------------------------------------

void SetPostOfficeIni(std::string_view ini)
{
	s_iniLocation = ini;
}

void SetCrashpadCallback(const GetCrashpadPipe& getCrashpad)
{
	s_crashpadCallback = getCrashpad;
}

void SetTriggerPostOffice(const std::function<void()>& triggerProcess)
{
	s_triggerProcess = triggerProcess;
}

void SetRequestFocusCallback(const RequestFocusCallback& requestFocus)
{
	s_requestFocusCallback = requestFocus;
}

//-----------------------------------------------------------------------------

LauncherPostOffice::LauncherPostOffice()
	: ServerPostOffice("launcher", mq::MQ_PIPE_SERVER_PATH)
{
	InitializePostOfficeImGui();
}

LauncherPostOffice::~LauncherPostOffice()
{
	ShutdownPostOfficeImGui();
}

void LauncherPostOffice::AddConfiguredHosts()
{
	// it does not make sense for this port to be 0 since we are trying to connect to a peer with
	// a live port, so assume 0 means connect to the same port as this
	const uint16_t default_port = GetPeerPort();

	if (s_iniLocation)
	{
		for (const auto& [address, port_raw] : GetPrivateProfileKeyValues("NetworkPeers", *s_iniLocation))
		{
			const uint16_t port = static_cast<uint16_t>(GetUIntFromString(port_raw, 0));
			AddNetworkHost(address, port > 0 ? port : default_port);
		}
	}
}

void LauncherPostOffice::OnIncomingMessage(mq::postoffice::LocalConnection* connection, mq::PipeMessagePtr message)
{
	switch (message->GetMessageId())  // NOLINT(clang-diagnostic-switch-enum)
	{
	case mq::MQMessageId::MSG_MAIN_PROCESS_UNLOADED:
		break;

	case mq::MQMessageId::MSG_MAIN_PROCESS_LOADED:
		if (auto pipeServer = connection->GetPipeServer())
		{
			MQMessageProcessLoadedResponse response;
			response.processId = GetCurrentProcessId();

			pipeServer->SendMessage(message->GetConnectionId(), mq::MQMessageId::MSG_MAIN_PROCESS_LOADED,
				&response, sizeof(response));
		}
		break;

	case mq::MQMessageId::MSG_MAIN_FOCUS_REQUEST:
		if (message->size() >= sizeof(MQMessageFocusRequest) && s_requestFocusCallback)
		{
			(*s_requestFocusCallback)(message->get<MQMessageFocusRequest>());
		}
		break;

	case mq::MQMessageId::MSG_MAIN_MESSAGEBOX:
		if (const auto notification = ProtoMessage::Parse<proto::routing::Notification>(message);
			notification.has_message())
		{
			LauncherImGui::OpenMessageBox(nullptr, notification.message(), notification.title());
		}
		else
		{
			LauncherImGui::OpenMessageBox(nullptr, notification.title(), notification.title());
		}

		break;

	case mq::MQMessageId::MSG_MAIN_TRAY_NOTIFY:
	{
		const auto notification = ProtoMessage::Parse<proto::routing::Notification>(message);
		NOTIFYICONDATAA notify;
		notify.cbSize = sizeof(NOTIFYICONDATAA);
		notify.uID = WM_USER_SYSTRAY;
		notify.hWnd = hMainWnd;
		notify.uFlags = NIF_INFO;

		strcpy_s(notify.szInfoTitle, notification.title().c_str());
		if (notification.has_message())
			strcpy_s(notify.szInfo, notification.message().c_str());
		else
			strcpy_s(notify.szInfo, notification.title().c_str());

		if (notification.has_level())
		{
			switch (notification.level())
			{
			case proto::routing::NotifyLevel::Info:
				notify.dwInfoFlags = NIIF_INFO;
				break;
			case proto::routing::NotifyLevel::Warning:
				notify.dwInfoFlags = NIIF_WARNING;
				break;
			case proto::routing::NotifyLevel::Error:
				notify.dwInfoFlags = NIIF_ERROR;
				break;
			default:
				notify.dwInfoFlags = NIIF_INFO;
				break;
			}
		}
		else
			notify.dwInfoFlags = NIIF_INFO;

		Shell_NotifyIconA(NIM_MODIFY, &notify);
		break;
	}

	default: break;
	}
}

void LauncherPostOffice::OnRequestProcessEvents(mq::postoffice::LocalConnection* connection)
{
	if (s_triggerProcess)
	{
		(*s_triggerProcess)();
	}
}

void LauncherPostOffice::OnIncomingConnection(mq::postoffice::LocalConnection* connection, int connectionId, int processId)
{
	if (auto pipeServer = connection->GetPipeServer())
	{
		const std::string namedPipe = s_crashpadCallback ? (*s_crashpadCallback)() : "";

		// send the name of the named pipe to the connected client. If crashpad isn't
		// enabled, or shared is disabled, this will send an empty string, which basically
		// tells the process that its on its own.
		pipeServer->SendMessage(connectionId,
			mq::MakeSimpleMessageV0(MQMessageId::MSG_MAIN_CRASHPAD_CONFIG,
				namedPipe.c_str(), static_cast<uint32_t>(namedPipe.length()) + 1));
	}
}
//----------------------------------------------------------------------------

bool SendSetForegroundWindow(HWND hWnd, uint32_t processID)
{
	if (s_postOffice && processID != 0)
	{
		if (auto pipeConnection = s_postOffice->GetConnectionForProcessId(processID))
		{
			MQMessageActivateWnd message;
			message.hWnd = hWnd;

			s_postOffice->SendPipeMessage(pipeConnection->GetConnectionId(),
				mq::MQMessageId::MSG_MAIN_FOCUS_ACTIVATE_WND, &message, sizeof(message));
		}
	}
	
	return false;
}

void SendUnloadAllCommand()
{
	if (s_postOffice)
	{
		SPDLOG_INFO("LauncherPostOffice: Requesting to unload all instances");

		s_postOffice->BroadcastPipeMessage(mq::MQMessageId::MSG_MAIN_REQ_UNLOAD, nullptr, 0);
	}
}

void SendForceUnloadAllCommand()
{
	if (s_postOffice)
	{
		SPDLOG_INFO("LauncherPostOffice: Requesting to FORCE unload all instances");

		s_postOffice->BroadcastPipeMessage(mq::MQMessageId::MSG_MAIN_REQ_FORCEUNLOAD, nullptr, 0);
	}
}

void InitializePostOffice()
{
	if (s_postOffice == nullptr)
	{
		s_postOffice = new LauncherPostOffice();
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

LauncherPostOffice& GetPostOffice()
{
	assert(s_postOffice != nullptr);

	return *s_postOffice;
}

//----------------------------------------------------------------------------
