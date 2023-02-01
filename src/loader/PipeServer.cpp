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

#include "MacroQuest.h"
#include "PipeServer.h"
#include "AutoLogin.h"
#include "Crashpad.h"
#include "common/NamedPipes.h"
#include "common/proto/Shared.pb.h"

#include <date/date.h>
#include <fmt/format.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/wincolor_sink.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/msvc_sink.h>

mq::NamedPipeServer s_pipeServer{ mq::MQ2_PIPE_SERVER_PATH };

struct ClientIdentification
{
	uint32_t pid;
	std::string account;
	std::string server;
	std::string character;
};
std::unordered_map<uint32_t, ClientIdentification> s_identities;

class MQ2NamedPipeEvents : public NamedPipeEvents
{
public:
	// Handle messages from NamedPipeServer
	// Need messages to handle routing from client to another client
	// Need address system rethinking (use a struct with PID, and some client-internal address)
	// First, create a mailbox where you specify the address, register it with the _client_
	// This mailbox must have: an address (specify local address, chain up to PID for full address)
	//                         a callback to handle incoming messages
	//                         a FIFO queue for messages
	//                         we should be able to validate messages upon receipt (to provide guarantees)
	virtual void OnIncomingMessage(std::shared_ptr<PipeMessage> message) override
	{
		SPDLOG_TRACE("Received message: id={} length={} connectionId={}", message->GetMessageId(),
			message->size(), message->GetConnectionId());

		switch (message->GetMessageId())
		{
		case mq::MQMessageId::MSG_ECHO:
		{
			std::string str(message->get<const char>(), message->size() - 1);
			message->SendReply(MQMessageId::MSG_ECHO, str.data(), (uint32_t)str.length() + 1, 0);
			SPDLOG_INFO("Handling echo request: {}", str);
			break;
		}

		case mq::MQMessageId::MSG_IDENTIFICATION:
		{
			auto id = message->fill<mq::messages::Identification>();
			s_identities.insert_or_assign(id.pid(), ClientIdentification{
				id.pid(),
				id.has_account() ? id.account() : "",
				id.has_server() ? id.server() : "",
				id.has_character() ? id.character() : ""
			});

			SPDLOG_INFO("Got identification from {}: {} {} {}",
				id.pid(),
				id.has_account() ? id.account() : "N/A",
				id.has_server() ? id.server() : "N/A",
				id.has_character() ? id.character() : "N/A");
			break;
		}

		case mq::MQMessageId::MSG_AUTOLOGIN_PROFILE_LOADED:
			HandleAutoLoginProfileLoaded(std::string(message->get<const char>(), message->size()));
			break;

		case mq::MQMessageId::MSG_AUTOLOGIN_PROFILE_UNLOADED:
			HandleAutoLoginProfileUnloaded(std::string(message->get<const char>(), message->size()));
			break;

		case mq::MQMessageId::MSG_AUTOLOGIN_PROFILE_CHARINFO:
			HandleAutoLoginUpdateCharacterDetails(std::string(message->get<const char>(), message->size()));
			break;

		case mq::MQMessageId::MSG_AUTOLOGIN_START_INSTANCE:
			HandleAutoLoginStartInstance(std::string(message->get<const char>(), message->size()));
			break;

		case mq::MQMessageId::MSG_MAIN_PROCESS_UNLOADED:
			break;

		case mq::MQMessageId::MSG_MAIN_PROCESS_LOADED:
		{
			MQMessageProcessLoadedResponse response;
			response.processId = GetCurrentProcessId();

			s_pipeServer.SendMessage(message->GetConnectionId(), mq::MQMessageId::MSG_MAIN_PROCESS_LOADED,
				&response, sizeof(response));
			break;
		}

		case mq::MQMessageId::MSG_MAIN_FOCUS_REQUEST: {
			if (message->size() >= sizeof(MQMessageFocusRequest))
			{
				const MQMessageFocusRequest* request = message->get<MQMessageFocusRequest>();
				if (request->focusMode == MQMessageFocusRequest::FocusMode::HasFocus)
				{
					SetFocusWindowPID(request->processId, request->state);
				}
				else if (request->focusMode == MQMessageFocusRequest::FocusMode::WantFocus)
				{
					SetForegroundWindowInternal((HWND)request->hWnd);
				}
			}
			break;
		}

		default: break;
		}
	}

	virtual void OnRequestProcessEvents() override
	{
		PostMessageA(hMainWnd, WM_USER_CALLBACK, 0, 0);
	}

	virtual void OnIncomingConnection(int connectionId, int processid) override
	{
		std::string namedPipe;

		if (IsCrashpadInitialized() && gEnableSharedCrashpad)
		{
			namedPipe = GetHandlerIPCPipe();
		}

		// send the name of the named pipe to the connected client. If crashpad isn't
		// enabled, or shared is disabled, this will send an empty string, which basically
		// tells the process that its on its own.
		s_pipeServer.SendMessage(connectionId,
			mq::MakeSimpleMessageV0(MQMessageId::MSG_MAIN_CRASHPAD_CONFIG,
				namedPipe.c_str(), (uint32_t)namedPipe.length() + 1));
	}

	virtual void OnConnectionClosed(int connectionId, int processId) override
	{
		s_identities.erase(processId);
	}
};

//----------------------------------------------------------------------------
// HELPER FUNCTIONS -- try to minimize refactoring
//----------------------------------------------------------------------------

bool SendSetForegroundWindow(HWND hWnd, uint32_t processID)
{
	if (processID != 0)
	{
		if (auto connection = s_pipeServer.GetConnectionForProcessId(processID))
		{
			MQMessageActivateWnd message;
			message.hWnd = hWnd;

			s_pipeServer.SendMessage(connection->GetConnectionId(),
				mq::MQMessageId::MSG_MAIN_FOCUS_ACTIVATE_WND, &message, sizeof(message));

			return true;
		}
	}

	return false;
}

void SendUnloadAllCommand()
{
	SPDLOG_DEBUG("Requesting to unload all instances");
	s_pipeServer.BroadcastMessage(mq::MQMessageId::MSG_MAIN_REQ_UNLOAD, nullptr, 0);
}

void SendForceUnloadAllCommand()
{
	SPDLOG_DEBUG("Requesting to FORCE unload all instances");
	s_pipeServer.BroadcastMessage(mq::MQMessageId::MSG_MAIN_REQ_FORCEUNLOAD, nullptr, 0);
}

void ProcessPipeServer()
{
	s_pipeServer.Process();
}

//----------------------------------------------------------------------------

void InitializeNamedPipeServer()
{
	s_pipeServer.SetHandler(std::make_shared<MQ2NamedPipeEvents>());
	s_pipeServer.Start();
}

void ShutdownNamedPipeServer()
{
	s_pipeServer.Stop();
}
