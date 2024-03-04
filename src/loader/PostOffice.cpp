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

#include "loader/MacroQuest.h"
#include "loader/PostOffice.h"
#include "loader/Crashpad.h"
#include "loader/LoaderAutoLogin.h"
#include "routing/PostOffice.h"

#include <date/date.h>
#include <fmt/format.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/wincolor_sink.h>
#include <spdlog/sinks/basic_file_sink.h>


using namespace postoffice;
class LauncherPostOffice : public PostOffice
{
private:
	struct ClientIdentification
	{
		uint32_t pid;
		std::string account;
		std::string server;
		std::string character;
	};

	std::unordered_map<uint32_t, ClientIdentification> m_identities;
	ci_unordered::map<std::string, uint32_t> m_names;
	bool m_processing = false;
	bool m_needsProcessing = false;

	class PipeEventsHandler : public NamedPipeEvents
	{
	public:
		PipeEventsHandler(LauncherPostOffice* postOffice) : m_postOffice(postOffice) {}

		virtual void OnIncomingMessage(PipeMessagePtr&& message) override
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
			{
				auto envelope = ProtoMessage::Parse<proto::routing::Envelope>(message);
				const auto& address = envelope.address();
				if ((address.has_pid() && address.pid() == GetCurrentProcessId()) || (address.has_name() && ci_equals(address.name(), "launcher")))
				{
					auto routing_failed = [&envelope](int status, PipeMessagePtr&& message)
						{
							RoutingFailed(envelope, status, std::move(message), nullptr);
						};

					if (address.has_mailbox())
					{
						// this is a local message
						m_postOffice->DeliverTo(address.mailbox(), std::move(message), routing_failed);
					}
					else
					{
						// This is a failsafe action, we shouldn't expect to be here often. For this code to
						// be reached, we would have to have a client that packages a message in an envelope
						// that is intended to be parsed directly by the server and not routed anywhere (so
						// no mailbox routing information is included), rather than just send the message
						m_postOffice->DeliverTo("pipe_server", std::move(message), routing_failed);
					}
				}
				else
				{
					// all we have to do here is route, this is the same as if an internal mailbox is
					// attempting to route a message
					m_postOffice->RouteMessage(std::move(message));
				}
				break;
			}

			case mq::MQMessageId::MSG_IDENTIFICATION:
				if (message->GetHeader()->messageLength > 0)
				{
					bool added = false;

					// if there is a payload, then we are getting a notification of ID
					auto id = ProtoMessage::Parse<proto::routing::Identification>(message);
					if (id.has_name())
					{
						m_postOffice->m_names.insert_or_assign(id.name(), id.pid());
						SPDLOG_INFO("Got name-based identification from {}: {}", id.pid(), id.name());
					}
					else
					{
						auto result = m_postOffice->m_identities.insert_or_assign(id.pid(), ClientIdentification{
							id.pid(),
							id.has_account() ? id.account() : "",
							id.has_server() ? id.server() : "",
							id.has_character() ? id.character() : ""
						});
						added = result.second;

						// only include the PID here, otherwise it's pseudonym-identifiable information from the logs
						SPDLOG_INFO("Got identification from {}", id.pid());
					}

					// we also need to update all the clients
					m_postOffice->m_pipeServer.BroadcastProtoMessage(mq::MQMessageId::MSG_IDENTIFICATION, id);

					if (added)
					{
						proto::login::IdentifyMissive announce;
						Post(id.pid(), proto::login::Identify, announce);
					}
				}
				else
				{
					// we are getting a request to send all IDs, do so sequentially and asynchronously
					for (const auto& [_, client] : m_postOffice->m_identities)
					{
						proto::routing::Identification id;
						id.set_pid(client.pid);

						if (!client.account.empty())
							id.set_account(client.account);

						if (!client.server.empty())
							id.set_server(client.server);

						if (!client.character.empty())
							id.set_character(client.character);
						
						m_postOffice->m_pipeServer.SendProtoMessage(
							message->GetConnectionId(),
							MQMessageId::MSG_IDENTIFICATION,
							id);
					}

					for (const auto& [name, pid] : m_postOffice->m_names)
					{
						proto::routing::Identification id;
						id.set_pid(pid);
						id.set_name(name);
						
						m_postOffice->m_pipeServer.SendProtoMessage(
							message->GetConnectionId(),
							MQMessageId::MSG_IDENTIFICATION,
							id);
					}
				}
				break;

			case mq::MQMessageId::MSG_MAIN_PROCESS_UNLOADED:
				break;

			case mq::MQMessageId::MSG_MAIN_PROCESS_LOADED:
			{
				MQMessageProcessLoadedResponse response;
				response.processId = GetCurrentProcessId();

				m_postOffice->m_pipeServer.SendMessage(message->GetConnectionId(), mq::MQMessageId::MSG_MAIN_PROCESS_LOADED,
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
			m_postOffice->m_pipeServer.SendMessage(connectionId,
				mq::MakeSimpleMessageV0(MQMessageId::MSG_MAIN_CRASHPAD_CONFIG,
					namedPipe.c_str(), (uint32_t)namedPipe.length() + 1));
		}

		virtual void OnConnectionClosed(int connectionId, int processId) override
		{
			// we need to make sure not to send to the connection that is closing
			auto broadcast = [&pipe = m_postOffice->m_pipeServer, connectionId](proto::routing::Identification&& id)
				{
					std::string data = id.SerializeAsString();
					for (auto conn : pipe.GetConnectionIds())
					{
						if (conn != connectionId)
							pipe.SendMessage(conn, mq::MQMessageId::MSG_DROPPED, &data[0], data.size());
					}
				};

			for (auto name_it = m_postOffice->m_names.begin(); name_it != m_postOffice->m_names.end();)
			{
				if (name_it->second == processId)
				{
					proto::routing::Identification id;
					id.set_pid(name_it->second);
					id.set_name(name_it->first);

					SPDLOG_INFO("Disconnection detected, dropping name from {}: {}", id.pid(), id.name());
					broadcast(std::move(id));

					name_it = m_postOffice->m_names.erase(name_it);
				}
				else
					++name_it;
			}

			auto ident_it = m_postOffice->m_identities.find(processId);
			if (ident_it != m_postOffice->m_identities.end())
			{
				proto::routing::Identification id;
				id.set_pid(ident_it->first);

				if (!ident_it->second.account.empty())
					id.set_account(ident_it->second.account);

				if (!ident_it->second.server.empty())
					id.set_server(ident_it->second.server);

				if (!ident_it->second.character.empty())
					id.set_character(ident_it->second.character);

				// only include the PID here, otherwise it's pseudonym-identifiable information from the logs
				SPDLOG_INFO("Disconnection detected, dropping ID from {}", id.pid());

				broadcast(std::move(id));

				m_postOffice->m_identities.erase(ident_it);
			}
		}

		private:
			LauncherPostOffice* m_postOffice;
	};

public:
	LauncherPostOffice() : m_pipeServer{ mq::MQ2_PIPE_SERVER_PATH }
	{
		m_names.emplace("launcher", GetCurrentProcessId());
	}

	static void RoutingFailed(
		const proto::routing::Envelope& envelope,
		int status,
		PipeMessagePtr&& message,
		const PipeMessageResponseCb& callback)
	{
		// we can't assume that the mailbox exists here, so manually create the reply
		proto::routing::Envelope outbound;
		*outbound.mutable_address() = envelope.return_address();
		outbound.set_payload(envelope.address().SerializeAsString());

		std::string data = outbound.SerializeAsString();
		if (callback == nullptr)
			message->SendReply(MQMessageId::MSG_ROUTE, &data[0], data.size(), status);
		else
			callback(status, std::make_unique<PipeMessage>(MQMessageId::MSG_ROUTE, &data[0], data.size()));
	}

	static bool IsRecipient(const proto::routing::Address& address, const ClientIdentification& id)
	{
		return (!address.has_account() || ci_equals(address.account(), id.account)) &&
			(!address.has_server() || ci_equals(address.server(), id.server)) &&
			(!address.has_character() || ci_equals(address.character(), id.character));
	}

	auto FindIdentity(
		const proto::routing::Address& address,
		const std::unordered_map<uint32_t, ClientIdentification>::iterator& from)
	{
		return std::find_if(from, m_identities.end(),
			[&address](const std::pair<uint32_t, ClientIdentification>& pair)
			{ return IsRecipient(address, pair.second); });
	}

	void RouteMessage(PipeMessagePtr&& message, const PipeMessageResponseCb& callback) override
	{
		if (callback == nullptr) // simple message, just route it
			RouteMessage(std::move(message));
		else // routing will fail here if there are too many recipients
		{
			auto envelope = ProtoMessage::Parse<proto::routing::Envelope>(message);
			const auto& address = envelope.address();

			auto routing_failed = [&envelope, callback](int status, PipeMessagePtr&& message)
				{
					RoutingFailed(envelope, status, std::move(message), callback);
				};

			auto single_send = [callback](const PipeConnectionPtr& connection, PipeMessagePtr&& message)
				{
					connection->SendMessageWithResponse(std::move(message), callback);
				};

			if (address.has_pid())
			{
				SendMessageToPID(address.pid(), std::move(message), single_send, routing_failed);
			}
			else if (address.has_name())
			{
				auto pid_it = m_names.find(address.name());
				if (pid_it == m_names.end())
				{
					routing_failed(MsgError_RoutingFailed, std::move(message));
				}
				else
				{
					SendMessageToPID(pid_it->second, std::move(message), single_send, routing_failed);
				}
			}
			else
			{
				auto identity = FindIdentity(envelope.address(), m_identities.begin());

				if (identity == m_identities.end())
					RoutingFailed(envelope, MsgError_RoutingFailed, std::move(message), callback);
				else if (FindIdentity(envelope.address(), std::next(identity)) != m_identities.end())
					RoutingFailed(envelope, MsgError_AmbiguousRecipient, std::move(message), callback);
				else
				{
					message->SetRequestMode(MQRequestMode::CallAndResponse);
					SendMessageToPID(identity->first, std::move(message), single_send, routing_failed);
				}
			}
		}
	}

	void RouteMessage(
		PipeMessagePtr&& message)
	{
		auto envelope = ProtoMessage::Parse<proto::routing::Envelope>(message);
		const auto& address = envelope.address();
		auto routing_failed = [&envelope](int status, PipeMessagePtr&& message)
			{
				RoutingFailed(envelope, status, std::move(message), nullptr);
			};

		auto single_send = [](const PipeConnectionPtr& connection, PipeMessagePtr&& message)
			{
				connection->SendMessage(std::move(message));
			};

		if (address.has_pid())
		{
			// a PID is necessarily a singular identifier, avoid the loop
			SendMessageToPID(address.pid(), std::move(message), single_send, routing_failed);
		}
		else if (address.has_name())
		{
			// a name is also a singular identifier, avoid the loop here too
			// route the message to a registered (named) client
			auto pid_it = m_names.find(address.name());
			if (pid_it == m_names.end())
			{
				routing_failed(MsgError_RoutingFailed, std::move(message));
			}
			else
			{
				SendMessageToPID(pid_it->second, std::move(message), single_send, routing_failed);
			}
		}
		else if (message->GetRequestMode() == MQRequestMode::CallAndResponse)
		{
			// ensure that we have a singular target for an RPC message
			auto identity = FindIdentity(envelope.address(), m_identities.begin());

			if (identity == m_identities.end())
				RoutingFailed(envelope, MsgError_RoutingFailed, std::move(message), nullptr);
			else if (FindIdentity(envelope.address(), std::next(identity)) != m_identities.end())
				RoutingFailed(envelope, MsgError_AmbiguousRecipient, std::move(message), nullptr);
			else
				SendMessageToPID(identity->first, std::move(message), single_send, routing_failed);
		}
		else
		{
			// we don't have a PID or a name and this is not an RPC, so we will send this message to 
			// all clients that match the address -- it's important to copy these messages
			for (const auto& identity : m_identities)
			{
				if (IsRecipient(address, identity.second))
				{
					SendMessageToPID(
						identity.first,
						std::make_unique<PipeMessage>(*message->GetHeader(), message->get(), message->size()),
						single_send,
						routing_failed);
				}
			}
		}
	}

	void ProcessPipeServer()
	{
		if (m_processing)
		{
			m_needsProcessing = true;
			return;
		}

		m_processing = true;

		m_pipeServer.Process();
		Process(10);

		m_processing = false;

		if (m_needsProcessing)
		{
			m_needsProcessing = false;
			PostMessageA(hMainWnd, WM_USER_CALLBACK, 0, 0);
		}
	}

	bool SendSetForegroundWindow(HWND hWnd, uint32_t processID)
	{
		if (processID != 0)
		{
			if (auto connection = m_pipeServer.GetConnectionForProcessId(processID))
			{
				MQMessageActivateWnd message;
				message.hWnd = hWnd;

				m_pipeServer.SendMessage(connection->GetConnectionId(),
					mq::MQMessageId::MSG_MAIN_FOCUS_ACTIVATE_WND, &message, sizeof(message));

				return true;
			}
		}

		return false;
	}

	void SendUnloadAllCommand()
	{
		SPDLOG_DEBUG("Requesting to unload all instances");
		m_pipeServer.BroadcastMessage(mq::MQMessageId::MSG_MAIN_REQ_UNLOAD, nullptr, 0);
	}

	void SendForceUnloadAllCommand()
	{
		SPDLOG_DEBUG("Requesting to FORCE unload all instances");
		m_pipeServer.BroadcastMessage(mq::MQMessageId::MSG_MAIN_REQ_FORCEUNLOAD, nullptr, 0);
	}

	void Initialize()
	{
		m_pipeServer.SetHandler(std::make_shared<PipeEventsHandler>(this));
		m_pipeServer.Start();

		m_serverDropbox = RegisterAddress("pipe_server",
			[this](ProtoMessagePtr&& message)
			{
				// if we've gotten here, then something is delivering a message to this
				// post office ("pipe_server"), so handle messages directly
			});

		// request ID from all pre-existing connections
		m_pipeServer.BroadcastMessage(mq::MQMessageId::MSG_IDENTIFICATION, nullptr, 0);
	}

	void Shutdown()
	{
		// after the mailbox is removed from the post office, it won't get any more messages, and lets
		// make sure all remaining messages get discarded by dropping the last reference so we stop
		// processing
		m_serverDropbox.Remove();

		// we don't need to worry about sending messages after we stop because the pipe client will log
		// and handle this situation.
		m_pipeServer.Stop();
	}

private:
	mq::ProtoPipeServer m_pipeServer;
	Dropbox m_serverDropbox;

	bool SendMessageToPID(
		uint32_t pid,
		PipeMessagePtr&& message,
		const std::function<void(const PipeConnectionPtr&, PipeMessagePtr&&)> send,
		const std::function<void(int, PipeMessagePtr&&)>& failed)
	{
		if (pid == GetCurrentProcessId())
		{
			// send to self, dispatch directly to the handler
			m_pipeServer.DispatchMessage(std::move(message));
			return true;
		}
		else if (auto connection = m_pipeServer.GetConnectionForProcessId(pid))
		{
			// found a connection to send it over
			send(connection, std::move(message));
			return true;
		}

		SPDLOG_WARN("Unable to get connection for PID {}, message route failed.", pid);
		failed(MsgError_NoConnection, std::move(message));
		return false;
	}
};

std::unique_ptr<LauncherPostOffice> s_postOffice;

PostOffice& postoffice::GetPostOffice()
{
	static LauncherPostOffice s_postOffice;
	return s_postOffice;
}

//----------------------------------------------------------------------------
// HELPER FUNCTIONS -- try to minimize refactoring
//----------------------------------------------------------------------------

bool SendSetForegroundWindow(HWND hWnd, uint32_t processID)
{
	return static_cast<LauncherPostOffice&>(GetPostOffice()).SendSetForegroundWindow(hWnd, processID);
}

void SendUnloadAllCommand()
{
	static_cast<LauncherPostOffice&>(GetPostOffice()).SendUnloadAllCommand();
}

void SendForceUnloadAllCommand()
{
	static_cast<LauncherPostOffice&>(GetPostOffice()).SendForceUnloadAllCommand();
}

void ProcessPipeServer()
{
	static_cast<LauncherPostOffice&>(GetPostOffice()).ProcessPipeServer();
}

void InitializeNamedPipeServer()
{
	static_cast<LauncherPostOffice&>(GetPostOffice()).Initialize();
}

void ShutdownNamedPipeServer()
{
	static_cast<LauncherPostOffice&>(GetPostOffice()).Shutdown();
}

//----------------------------------------------------------------------------

