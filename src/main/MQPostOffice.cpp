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

#include "MacroQuest.h"
#include "ModuleSystem.h"
#include "MQMain.h"

#include "routing/PostOffice.h"

#ifdef SendMessage
#undef SendMessage
#endif

using namespace eqlib;
using namespace mq::postoffice;

namespace mq {

//============================================================================

// Module representing the "Post Office" - a hub for named pipe communications with the
// launcher. Maintains a baseline level of integration with the launcher for things like
// focus tracking and state management.

class MQPostOffice : public PostOffice,
	public MQModule,
	public NamedPipeEvents
{
	class PipeEventsHandler;

public:
	MQPostOffice();
	virtual ~MQPostOffice() override;

	void SendMessage(MQMessageId messageId, const void* data, size_t dataLength);
	bool IsConnected() const;

	// MQModule
	virtual void Initialize() override;
	virtual void Shutdown() override;
	virtual void OnGameStateChanged(int GameState) override;
	virtual void OnProcessFrame() override;

	// PostOffice
	virtual void RouteMessage(PipeMessagePtr message, const PipeMessageResponseCb& callback) override;

	// NamedPipeEvents
	virtual void OnIncomingMessage(PipeMessagePtr message) override;
	virtual void OnClientConnected() override;

private:
	auto FindMailbox(
		const proto::routing::Address& address,
		const std::unordered_map<const std::string, std::unique_ptr<postoffice::Mailbox>>::iterator& from)
	{
		if (!address.has_mailbox())
			return m_mailboxes.end();

		return std::find_if(from, m_mailboxes.end(),
			[&address](const std::pair<const std::string, std::unique_ptr<postoffice::Mailbox>>& pair)
			{ return ci_ends_with(pair.first, address.mailbox()); });
	}

	void SendIdentification();
	void NotifyIsForegroundWindow(bool isForeground);

	ProtoPipeClient m_pipeClient;
	Dropbox m_clientDropbox;
	uint32_t m_launcherProcessID = 0;
	bool m_loggedIn = false;
	bool m_lastInForeground = false;

	struct ClientIdentification
	{
		uint32_t pid;
		std::string account;
		std::string server;
		std::string character;
	};

	std::unordered_map<uint32_t, ClientIdentification> m_identities;
	ci_unordered::map<std::string, uint32_t> m_names;
};

static MQPostOffice* s_postOffice = nullptr;

PostOffice* postoffice::GetPostOffice()
{
	return s_postOffice;
}

DECLARE_MODULE_FACTORY(MQPostOffice);

//============================================================================

class MQPostOffice::PipeEventsHandler : public NamedPipeEvents
{
public:
	PipeEventsHandler(MQPostOffice* postOffice)
		: m_postOffice(postOffice)
	{
	}

	virtual void OnIncomingMessage(PipeMessagePtr message) override
	{
		m_postOffice->OnIncomingMessage(std::move(message));
	}

	virtual void OnClientConnected() override
	{
		m_postOffice->OnClientConnected();
	}

private:
	MQPostOffice* m_postOffice;
};

//----------------------------------------------------------------------------

MQPostOffice::MQPostOffice()
	: MQModule("PostOffice")
	, m_pipeClient{ mq::MQ2_PIPE_SERVER_PATH }
{
	m_clientDropbox = RegisterAddress("pipe_client",
		[this](ProtoMessagePtr message)
		{
			// if we've gotten here, then something is delivering a message to this
			// post office ("pipe_client"), so handle messages directly
			// TODO: add message handling to request IDs (note that we can't use proto without
			//       requiring that all plugins start linking the same proto compile, so let's
			//       try to avoid that with some simple object casts, assuming this will always
			//       be local.
		});

	s_postOffice = this;
}

MQPostOffice::~MQPostOffice()
{
	s_postOffice = nullptr;
}

void MQPostOffice::Initialize()
{
	m_pipeClient.SetHandler(std::make_shared<PipeEventsHandler>(this));
	m_pipeClient.Start();
}

void MQPostOffice::Shutdown()
{
	// after the mailbox is removed from the post office, it won't get any more messages, and lets
	// make sure all remaining messages get discarded by dropping the last reference so we stop
	// processing
	m_clientDropbox.Remove();

	// we don't need to worry about sending messages after we stop because the pipe client will log
	// and handle this situation.
	m_pipeClient.Stop();
}

void MQPostOffice::OnGameStateChanged(int GameState)
{
	// Should these be part of actors or post office?

	// 0 is sent from init
	assert(GameState != 0);

	if (m_loggedIn && GameState != GAMESTATE_LOGGINGIN && GameState != GAMESTATE_INGAME)
	{
		m_loggedIn = false;

		proto::routing::Identification id;
		id.set_pid(GetCurrentProcessId());

		m_pipeClient.SendProtoMessage(MQMessageId::MSG_IDENTIFICATION, id);
	}
	else if (!m_loggedIn && (GameState == GAMESTATE_LOGGINGIN || GameState == GAMESTATE_INGAME))
	{
		m_loggedIn = true;

		proto::routing::Identification id;
		id.set_pid(GetCurrentProcessId());
		id.set_account(GetLoginName());
		id.set_server(GetServerShortName());
		id.set_character(pLocalPC->Name);

		m_pipeClient.SendProtoMessage(MQMessageId::MSG_IDENTIFICATION, id);
	}
}

void MQPostOffice::OnProcessFrame()
{
	if (mq::test_and_set(m_lastInForeground, gbInForeground))
	{
		NotifyIsForegroundWindow(m_lastInForeground);
	}

	m_pipeClient.Process();

	Process(1000); // make this large just to prevent overflows
}

static void RoutingFailed(
	const proto::routing::Envelope& envelope,
	uint8_t status,
	const PipeMessagePtr& message,
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

void MQPostOffice::RouteMessage(PipeMessagePtr message, const PipeMessageResponseCb& callback)
{
	if (message->GetMessageId() == MQMessageId::MSG_ROUTE)
	{
		proto::routing::Envelope envelope = ProtoMessage::Parse<proto::routing::Envelope>(message);

		// always enrich the return address if in game
		if (pLocalPC)
		{
			envelope.mutable_return_address()->set_account(GetLoginName());
			envelope.mutable_return_address()->set_server(GetServerShortName());
			envelope.mutable_return_address()->set_character(pLocalPC->Name);

			std::string data(envelope.SerializeAsString());
			message = std::make_unique<PipeMessage>(*message->GetHeader(), &data[0], data.size());
		}

		if (envelope.has_address())
		{
			auto address = envelope.address();
			if ((address.has_pid() && address.pid() != GetCurrentProcessId()) ||
				address.has_name() ||
				address.has_account() ||
				address.has_server() ||
				address.has_character() ||
				address.has_mailbox())
			{
				// we can't assume that even if we match the address (account/server/character) that this
				// client is the only one that does. We need to route it through the server to ensure that
				// it gets to all clients that match
				if (callback == nullptr) // no response
					m_pipeClient.SendMessage(std::move(message));
				else
					m_pipeClient.SendMessageWithResponse(std::move(message), callback);
			}
			else if (address.has_pid() && address.pid() == GetCurrentProcessId() && callback != nullptr)
			{
				// special handling for local RPC messages
				auto mailbox = FindMailbox(address, m_mailboxes.begin());

				// need to set the request mode here to ensure that failed messages get returned
				message->SetRequestMode(MQRequestMode::CallAndResponse);

				if (mailbox == m_mailboxes.end()) // no addresses
					RoutingFailed(envelope, MsgError_RoutingFailed, message, callback);
				else if (FindMailbox(address, std::next(mailbox)) != m_mailboxes.end()) // multiple addresses
					RoutingFailed(envelope, MsgError_AmbiguousRecipient, message, callback);
				else // we have exactly one recipient, this is valid
					m_pipeClient.SendMessageWithResponse(std::move(message), callback);
			}
			else // address.has_pid() && address.pid() == GetCurrentProcessId() && callback == nullptr
			{
				m_pipeClient.DispatchMessage(std::move(message));
			}
		}
		else // no address, just dispatch
		{
			m_pipeClient.DispatchMessage(std::move(message));
		}
	}
	else
	{
		// not a route, just send it to the server (single recipient guaranteed)
		if (callback == nullptr)
			m_pipeClient.SendMessage(std::move(message));
		else
			m_pipeClient.SendMessageWithResponse(std::move(message), callback);
	}
}

void MQPostOffice::OnIncomingMessage(PipeMessagePtr message)
{
	switch (message->GetMessageId())  // NOLINT(clang-diagnostic-switch-enum)
	{
	case MQMessageId::MSG_ROUTE:
	{
		proto::routing::Envelope envelope = ProtoMessage::Parse<proto::routing::Envelope>(message);
		std::optional<proto::routing::Address> address = envelope.has_address()
			? std::make_optional(envelope.address()) : std::nullopt;

		// either this message is coming off the pipe, so assume it was routed correctly by the server,
		// or it was routed internally after checking to make sure that the destination of the message
		// was within the client. In either case, we can safely assume that we should route it to an
		// internal mailbox
		if (address && address->has_mailbox())
		{
			// we need to loop all mailboxes and deliver to all of them that end with the address
			// if this is an RPC message, then we need to ensure that we have only one
			if (message->GetRequestMode() == MQRequestMode::CallAndResponse)
			{
				auto mailbox = FindMailbox(*address, m_mailboxes.begin());

				if (mailbox == m_mailboxes.end()) // no addresses
					RoutingFailed(envelope, MsgError_RoutingFailed, message, nullptr);
				else if (FindMailbox(*address, std::next(mailbox)) != m_mailboxes.end()) // multiple addresses
					RoutingFailed(envelope, MsgError_AmbiguousRecipient, message, nullptr);
				else // we have exactly one recipient, this is valid
					DeliverTo(address->mailbox(), std::move(message));
			}
			else
			{
				// in any other case, just route the message
				DeliverTo(address->mailbox(), std::move(message));
			}
		}
		else
		{
			// This is a failsafe action, we shouldn't expect to be here often. For this code to
			// be reached, we would have to have a client that packages a message in an envelope
			// that is intended to be parsed directly by the server and not routed anywhere (so
			// no mailbox routing information is included), rather than just send the message
			DeliverTo("pipe_client", std::move(message));
		}

		break;
	}

	case MQMessageId::MSG_IDENTIFICATION:
		if (message->GetHeader()->messageLength > 0)
		{
			// this is a message from the server to update or add an ID
			auto id = ProtoMessage::Parse<proto::routing::Identification>(message);
			if (id.has_name())
			{
				m_names.insert_or_assign(id.name(), id.pid());
				SPDLOG_INFO("Got name-based identification from {}: {}", id.pid(), id.name());
			}
			else
			{
				m_identities.insert_or_assign(id.pid(),
					ClientIdentification{
						id.pid(),
						id.has_account() ? id.account() : "",
						id.has_server() ? id.server() : "",
						id.has_character() ? id.character() : ""
					});

				// only include the PID here, otherwise it's pseudonym-identifiable information from the logs
				SPDLOG_INFO("Got identification from {}", id.pid());
			}

			// TODO: forward new ID to all mailboxes here
		}
		else
		{
			// this is a message from the server to identify self (as a handshake)
			// so resend the init
			SendIdentification();
		}
		break;

	case MQMessageId::MSG_DROPPED:
	{
		auto id = ProtoMessage::Parse<proto::routing::Identification>(message);
		if (id.has_name())
		{
			m_names.erase(id.name());
		}
		else
		{
			m_identities.erase(id.pid());
		}

		// TODO: forward the message to all mailboxes
		break;
	}

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

			SPDLOG_DEBUG("Launcher process ID: {}", m_launcherProcessID);
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
		g_mq->HandlePipeMessage(std::move(message));
		break;
	}
}

void MQPostOffice::OnClientConnected()
{
	SPDLOG_DEBUG("Connection to named pipe created, Sending process loaded message.");

	MQMessageProcessLoadedFromMQ msg;
	msg.processId = GetCurrentProcessId();
	m_pipeClient.SendMessage(MQMessageId::MSG_MAIN_PROCESS_LOADED, &msg, sizeof(msg));

	// send a self-identification
	SendIdentification();

	// and then ask for the list of all ID's
	m_pipeClient.SendMessage(MQMessageId::MSG_IDENTIFICATION, nullptr, 0);
}

void MQPostOffice::SendIdentification()
{
	proto::routing::Identification id;
	id.set_pid(GetCurrentProcessId());

	if (pLocalPC)
	{
		m_loggedIn = true;
		id.set_account(GetLoginName());
		id.set_server(GetServerShortName());
		id.set_character(pLocalPC->Name);
	}

	m_pipeClient.SendProtoMessage(MQMessageId::MSG_IDENTIFICATION, id);
}

void MQPostOffice::NotifyIsForegroundWindow(bool isForeground)
{
	MQMessageFocusRequest request;
	request.focusMode = MQMessageFocusRequest::FocusMode::HasFocus;
	request.state = isForeground;
	request.processId = GetCurrentProcessId();

	m_pipeClient.SendMessage(MQMessageId::MSG_MAIN_FOCUS_REQUEST, &request, sizeof(request));
}

void MQPostOffice::SendMessage(MQMessageId messageId, const void* data, size_t dataLength)
{
	m_pipeClient.SendMessage(messageId, data, dataLength);
}

bool MQPostOffice::IsConnected() const
{
	return m_pipeClient.IsConnected();
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

	SPDLOG_ERROR("Attempt to send message on named pipe without PostOffice module loaded");
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
