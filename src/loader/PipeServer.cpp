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
#include "Crashpad.h"

#include <mq/proto/Routing.h>

#include <date/date.h>
#include <fmt/format.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/wincolor_sink.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/msvc_sink.h>

mq::ProtoPipeServer s_pipeServer{ mq::MQ2_PIPE_SERVER_PATH };
mailbox::PostOffice s_postOffice{ &RouteMessage };
std::shared_ptr<mailbox::PostOffice::Mailbox> s_serverMailbox;

struct ClientIdentification
{
	uint32_t pid;
	std::string account;
	std::string server;
	std::string character;
};
std::unordered_map<uint32_t, ClientIdentification> s_identities;
ci_unordered::map<std::string, uint32_t> s_names;

bool SendMessageToPID(uint32_t pid, const PipeMessagePtr& message)
{
	auto connection = s_pipeServer.GetConnectionForProcessId(pid);
	if (connection != nullptr)
	{
		connection->SendMessage(message);
	}
	else
	{
		SPDLOG_WARN("Unable to get connection for PID {}, message route failed.", pid);
	}

	return connection != nullptr;
}

void RouteMessage(PipeMessagePtr message)
{
	auto envelope = ProtoMessage::Parse<proto::Envelope>(message);
	const auto& address = envelope.address();
	auto routing_failed = [&message, &envelope, &address]()
	{
		if (envelope.has_return_address())
			s_serverMailbox->PostReply(message, envelope.return_address(), MQMessageId::MSG_NULL, address, MsgError_RoutingFailed);
	};

	if (address.has_pid() && address.pid() != GetCurrentProcessId())
	{
		// a PID is necessarily a singular identifier, avoid the loop
		if (!SendMessageToPID(address.pid(), message) && envelope.has_return_address())
		{
			routing_failed();
		}
	}
	else if (address.has_name() && !ci_equals(address.name(), "launcher"))
	{
		// a name is also a singular identifier, avoid the loop here too
		// route the message to a registered (named) client
		auto pid_it = s_names.find(address.name());
		if (pid_it == s_names.end() || !SendMessageToPID(pid_it->second, message))
		{
			routing_failed();
		}
	}
	else if ((address.has_pid() && address.pid() == GetCurrentProcessId()) || (address.has_name() && ci_equals(address.name(), "launcher")))
	{
		if (address.has_mailbox())
		{
			// this is a local message
			SPDLOG_INFO("Routing message to mailbox: {}", address.mailbox());
			if (!s_postOffice.DeliverTo(address.mailbox(), message))
			{
				routing_failed();
			}
		}
		else
		{
			// This is a failsafe action, we shouldn't expect to be here often. For this code to
			// be reached, we would have to have a client that packages a message in an envelope
			// that is intended to be parsed directly by the server and not routed anywhere (so
			// no mailbox routing information is included), rather than just send the message
			if (!s_postOffice.DeliverTo("pipe_server", message))
			{
				routing_failed();
			}
		}
	}
	else
	{
		// we don't have a PID or a name, so we will send this message to all clients that match the address
		for (const auto& identity : s_identities)
		{
			if (
				(!address.has_account() || ci_equals(address.account(), identity.second.account)) &&
				(!address.has_server() || ci_equals(address.server(), identity.second.server)) &&
				(!address.has_character() || ci_equals(address.character(), identity.second.character))
				)
			{
				if (!SendMessageToPID(identity.first, message))
				{
					routing_failed();
				}
			}
		}
	}
}

class MQ2NamedPipeEvents : public NamedPipeEvents
{
public:
	virtual void OnIncomingMessage(std::shared_ptr<PipeMessage> message) override
	{
		using namespace mq::proto;
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

		case mq::MQMessageId::MSG_ROUTE:
			// all we have to do here is route, this is the same as if an internal mailbox is
			// attempting to route a message
			RouteMessage(message);
			break;

		case mq::MQMessageId::MSG_IDENTIFICATION:
		{
			auto id = ProtoMessage::Parse<proto::Identification>(message);
			if (id.has_name())
			{
				s_names.insert_or_assign(id.name(), id.pid());
				SPDLOG_INFO("Got name-based identification from {}: {}", id.pid(), id.name());
			}
			else
			{
				s_identities.insert_or_assign(id.pid(), ClientIdentification{
					id.pid(),
					id.has_account() ? id.account() : "",
					id.has_server() ? id.server() : "",
					id.has_character() ? id.character() : ""
					});

				// only include the PID here, otherwise it's pseudonym-identifiable information from the logs
				SPDLOG_INFO("Got identification from {}", id.pid());
			}
			break;
		}

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
	s_postOffice.Process(10);
}

//----------------------------------------------------------------------------

void InitializeNamedPipeServer()
{
	s_pipeServer.SetHandler(std::make_shared<MQ2NamedPipeEvents>());
	s_pipeServer.Start();

	s_serverMailbox = AddMailbox("pipe_server",
		[](ProtoMessagePtr message)
		{
			s_pipeServer.DispatchMessage(message);
		});
}

void ShutdownNamedPipeServer()
{
	RemoveMailbox("pipe_server");
	s_serverMailbox.reset();
	s_pipeServer.Stop();
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
