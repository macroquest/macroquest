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
#include "MQ2PostOffice.h"
#include "CrashHandler.h"

#include "MQ2Main.h"

#include <mq/proto/Routing.h>

namespace mq {

ProtoPipeClient gPipeClient{ mq::MQ2_PIPE_SERVER_PATH };
mailbox::PostOffice s_postOffice{ [](const std::string& data) { pipeclient::RouteMessage(data); } };
std::shared_ptr<mailbox::PostOffice::Mailbox> s_clientMailbox;
DWORD dwLauncherProcessID = 0;

// MQModule forward declarations
namespace pipeclient {
static void SetGameStatePostOffice(DWORD);
}

// we can't use a MQModule here for init/shutdown because initialization order matters.
static MQModule s_PostOfficeModule = {
	"PostOffice",
	false,
	nullptr,                                   // Initialize
	nullptr,                                   // Shutdown
	nullptr,                                   // Pulse
	pipeclient::SetGameStatePostOffice,        // SetGameState
	nullptr,                                   // UpdateImGui
	nullptr,                                   // Zoned
	nullptr,                                   // WriteChatColor
	nullptr,                                   // SpawnAdded
	nullptr,                                   // SpawnRemoved
	nullptr,                                   // BeginZone
	nullptr,                                   // EndZone
	nullptr,                                   // LoadPlugin
	nullptr                                    // UnloadPlugin
};
MQModule* GetPostOfficeModule() { return &s_PostOfficeModule; }

class PipeEventsHandler : public NamedPipeEvents
{
public:
	virtual void OnIncomingMessage(std::shared_ptr<PipeMessage> message) override
	{
		switch (message->GetMessageId())
		{
		case MQMessageId::MSG_ROUTE:
		{
			auto envelope = ProtoMessage::Parse<proto::Envelope>(message);
			const auto& address = envelope.address();
			// either this message is coming off the pipe, so assume it was routed correctly by the server,
			// or it was routed internally after checking to make sure that the destination of the message
			// was within the client. In either case, we can safely assume that we should route it to an
			// internal mailbox
			if (address.has_mailbox())
			{
				s_postOffice.DeliverTo(address.mailbox(), message);
			}
			else
			{
				// This is a failsafe action, we shouldn't expect to be here often. For this code to
				// be reached, we would have to have a client that packages a message in an envelope
				// that is intended to be parsed directly by the server and not routed anywhere (so
				// no mailbox routing information is included), rather than just send the message
				s_postOffice.DeliverTo("pipe_client", message);
			}

			break;
		}

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
		
		pipeclient::SetGameStatePostOffice(0);
	}
};

namespace pipeclient {

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

void SetGameStatePostOffice(DWORD GameState)
{
	proto::Identification id;
	id.set_pid(GetCurrentProcessId()); // we should always have a pid

	const char* login = GetLoginName();
	if (login != nullptr)
		id.set_account(login);

	if (pEverQuestInfo != nullptr)
	{
		const char* server = GetServerShortName();
		if (server != nullptr)
			id.set_server(server);
	}

	if (pLocalPC != nullptr && pLocalPC->Name != nullptr)
	{
		id.set_character(pLocalPC->Name);
	}

	gPipeClient.SendProtoMessage(MQMessageId::MSG_IDENTIFICATION, id);
}

std::shared_ptr<mailbox::PostOffice::Mailbox> AddMailbox(const std::string& localAddress, mailbox::PostOffice::ReceiveCallback receive)
{
	auto mailbox = s_postOffice.CreateMailbox(localAddress, receive);
	if (mailbox && s_postOffice.AddMailbox(localAddress, mailbox))
		return mailbox;

	return {};
}

bool RemoveMailbox(const std::string& localAddress)
{
	return s_postOffice.RemoveMailbox(localAddress);
}

void RouteMessage(const PipeMessagePtr& message)
{
	if (message->GetMessageId() == MQMessageId::MSG_ROUTE)
	{
		auto envelope = ProtoMessage::Parse<proto::Envelope>(message);
		if (envelope.has_address())
		{
			auto address = envelope.address();
			if ((address.has_pid() && address.pid() != GetCurrentProcessId()) || address.has_name() || address.has_account() || address.has_server() || address.has_character())
			{
				// we can't assume that even if we match the address (account/server/character) that this
				// client is the only one that does. We need to route it through the server to ensure that
				// it gets to all clients that match
				gPipeClient.SendMessage(message);
			}
			else if (address.has_mailbox())
			{
				s_postOffice.DeliverTo(address.mailbox(), message);
			}
			else
			{
				s_postOffice.DeliverTo("pipe_client", message);
			}
		}
		else
		{
			s_postOffice.DeliverTo("pipe_client", message);
		}
	}
	else
	{
		// not a route, just send it to the server
		gPipeClient.SendMessage(message);
	}
}

void RouteMessage(MQMessageId messageId, const void* data, size_t length)
{
	RouteMessage(std::make_shared<PipeMessage>(messageId, data, length));
}

void RouteMessage(MQMessageId messageId, const std::string& data)
{
	RouteMessage(messageId, &data[0], data.size());
}

void RouteMessage(const std::string& data)
{
	RouteMessage(MQMessageId::MSG_ROUTE, data);
}

} // namespace pipeclient

void InitializePipeClient()
{
	gPipeClient.SetHandler(std::make_shared<PipeEventsHandler>());
	gPipeClient.Start();
	::atexit([]() { gPipeClient.Stop(); });

	s_clientMailbox = pipeclient::AddMailbox("pipe_client",
		[](const ProtoMessagePtr& message)
		{
			gPipeClient.DispatchMessage(message);
		});
}

void ShutdownPipeClient()
{
	pipeclient::RemoveMailbox("pipe_client");
	s_clientMailbox.reset();

	gPipeClient.Stop();
}

} // namespace mq
