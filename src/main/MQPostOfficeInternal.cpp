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

// Uncomment to see super spammy read/write trace logging
//#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE

#include "MQPostOffice.h"

#include "routing/PostOffice.h"
#include "routing/ProtoPipes.h" // pipe connection

#include "mq/base/String.h"
#include "Logging.h"

#include <windows.h>

namespace mq {
using namespace postoffice;

// forward declarations that need to be defined externally
void DoCommand(const char* szLine, bool delayed);
bool InitializeCrashpad();
void InitializeCrashpadPipe(const std::string& pipeName);
ActorIdentification::Client GetDefaultClient();
bool ShouldUpdateIdentity(int GameState, bool& logged_in);

static std::unordered_map<uint32_t, MQPostOfficeConfig> s_postOfficeConfigs;

MQPostOfficeConfig GetPostOfficeConfig(uint32_t index)
{
	const auto config = s_postOfficeConfigs.find(index);
	if (config != s_postOfficeConfigs.end())
		return config->second;

	return {};
}

ActorIdentification::Client GetCurrentClient(const MQPostOfficeConfig& config)
{
	ActorIdentification::Client client = GetDefaultClient();

	if (config.AccountOverride)
		client.account = *config.AccountOverride;

	if (config.ServerOverride)
		client.server = *config.ServerOverride;

	if (config.CharacterOverride)
		client.character = *config.CharacterOverride;

	return std::move(client);
}

void MQPostOffice::PipeEventsHandler::OnIncomingMessage(PipeMessagePtr message)
{
	switch (message->GetMessageId())
	{
	case MQMessageId::MSG_ROUTE:
	{
		// this is an incoming routed message, so we can assume that we need to dispatch the message
		// from here to a mailbox in this client

		auto envelope = std::make_unique<proto::routing::Envelope>(ProtoMessage::Parse<proto::routing::Envelope>(message));
		auto address = envelope->has_address() ? std::make_optional(envelope->address()) : std::nullopt;
		// either this message is coming off the pipe, so assume it was routed correctly by the server,
		// or it was routed internally after checking to make sure that the destination of the message
		// was within the client. In either case, we can safely assume that we should route it to an
		// internal mailbox
		LOG_TRACE("{}: Received routed message in MQ to=[{}]", m_postOffice->GetName(), address ? address->ShortDebugString() : "no address");
		if (address && address->has_mailbox())
		{
			// we need to loop all mailboxes and deliver to all of them that end with the address
			// if this is an RPC message, then we need to ensure that we have only one
			if (envelope->mode() == static_cast<uint32_t>(MQRequestMode::CallAndResponse))
			{
				auto mailbox = m_postOffice->FindMailbox(*address, m_postOffice->m_mailboxes.begin());

				if (mailbox == m_postOffice->m_mailboxes.end()) // no addresses
					m_postOffice->RoutingFailed(MsgError_RoutingFailed, std::move(envelope), "No mailbox found");
				else if (m_postOffice->FindMailbox(*address, std::next(mailbox)) != m_postOffice->m_mailboxes.end())
					m_postOffice->RoutingFailed(MsgError_AmbiguousRecipient, std::move(envelope), "Multiple mailboxes found");
				else // we have exactly one recipient, this is valid
					m_postOffice->DeliverTo(address->mailbox(), std::move(envelope));
			}
			else
			{
				// in any other case, just route the message
				m_postOffice->DeliverTo(address->mailbox(), std::move(envelope));
			}
		}
		else
		{
			// This is a failsafe action, we shouldn't expect to be here often. For this code to
			// be reached, we would have to have a client that packages a message in an envelope
			// that is intended to be parsed directly by the server and not routed anywhere (so
			// no mailbox routing information is included), rather than just send the message
			m_postOffice->DeliverTo("pipe_client", std::move(envelope));
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
			m_postOffice->m_launcherProcessID = response->processId;

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

	default: break;
	}
}

void MQPostOffice::PipeEventsHandler::OnClientConnected()
{
	LOG_TRACE("{}: Connection to named pipe created, Sending process loaded message.", m_postOffice->GetName());

	MQMessageProcessLoadedFromMQ msg;
	msg.processId = GetCurrentProcessId();
	m_postOffice->m_pipeClient.SendMessage(MQMessageId::MSG_MAIN_PROCESS_LOADED, &msg, sizeof(msg));

	// send a self-identification
	m_postOffice->SetGameStatePostOffice(0);

	// and then ask for the list of all ID's
	m_postOffice->m_pipeClient.SendMessage(MQMessageId::MSG_IDENTIFICATION, nullptr, 0);
}

MQPostOffice::MQPostOffice(const MQPostOfficeConfig& config)
	: PostOffice(ActorIdentification(ActorContainer(ActorContainer::Process{ GetCurrentProcessId() }, CreateUUID()), GetCurrentClient(config)))
	, m_config(config)
	, m_pipeClient{ config.PipeName.c_str() }
	, m_launcherProcessID(0)
{
	m_clientDropbox = RegisterAddress("pipe_client",
		[this](MessagePtr message)
		{
			// if we've gotten here, then something is delivering a message to this
			// post office ("pipe_client"), so handle messages directly
		});
}

std::unordered_map<const std::string, std::unique_ptr<postoffice::Mailbox>>::iterator MQPostOffice::FindMailbox(
	const proto::routing::Address& address,
	const std::unordered_map<const std::string, std::unique_ptr<postoffice::Mailbox>>::iterator& from)
{
	if (!address.has_mailbox())
		return m_mailboxes.end();

	return std::find_if(from, m_mailboxes.end(),
		[&address](const std::pair<const std::string, std::unique_ptr<postoffice::Mailbox>>& pair)
		{ return ci_ends_with(pair.first, address.mailbox()); });
}

void MQPostOffice::RouteMessage(MessagePtr message)
{
	// dropbox.Post(Reply) was called, so route the message out

	// always enrich the return address
	*message->mutable_return_address()->mutable_client() = GetCurrentClient(m_config).GetProto();

	// no matter what, we need to route this message over the pipe
	auto payload = std::make_unique<uint8_t[]>(message->ByteSizeLong());
	message->SerializeToArray(payload.get(), static_cast<int>(message->ByteSizeLong()));

	auto msg = std::make_unique<PipeMessage>(MQMessageId::MSG_ROUTE, payload.get(), message->ByteSizeLong());

	if (message->has_address())
	{
		const auto& address = message->address();
		auto uuid = address.uuid();
		
		if (uuid.empty() || uuid != m_id.container.uuid) // either ambiguous clients, or explicitly not this client
			m_pipeClient.SendMessage(std::move(msg));
		else // uuid matches this client
			m_pipeClient.DispatchMessage(std::move(msg));
	}
	else // no address, just dispatch
	{
		m_pipeClient.DispatchMessage(std::move(msg));
	}
}

void MQPostOffice::ProcessPipeClient()
{
	m_pipeClient.Process();
	Process(1000); // make this large just to prevent overflows
}

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

void MQPostOffice::SetGameStatePostOffice(int GameState)
{
	static bool logged_in = false;

	if (ShouldUpdateIdentity(GameState, logged_in))
	{
		LOG_TRACE("{}: Updating identity", GetName());
		m_id.address = GetCurrentClient(m_config);
		m_pipeClient.SendProtoMessage(MQMessageId::MSG_IDENTIFICATION, m_id.GetProto());
	}
}

void MQPostOffice::Initialize()
{
	LOG_TRACE("{}: Initializing", GetName());
	m_pipeClient.SetHandler(std::make_shared<PipeEventsHandler>(this));
	m_pipeClient.Start();
	::atexit(StopPipeClient);
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

void MQPostOffice::StopPipeClient()
{
	GetPostOffice<MQPostOffice>().m_pipeClient.Stop();
}

static std::unordered_map<uint32_t, MQPostOffice> s_postOffices;
template <>
MQPostOffice& postoffice::GetPostOffice<MQPostOffice>(uint32_t index)
{
	auto it = s_postOffices.find(index);
	if (it == s_postOffices.end())
		it = s_postOffices.emplace(index, GetPostOfficeConfig(index)).first;

	return it->second;
}

void SetPostOfficeConfig(const MQPostOfficeConfig& config)
{
	s_postOfficeConfigs[config.Index] = config;
}

void DropPostOfficeConfig(uint32_t index)
{
	s_postOfficeConfigs.erase(index);
}

void ClearPostOfficeConfigs()
{
	s_postOfficeConfigs.clear();
}

void ClearPostOffices()
{
	for (auto& [_, post_office] : s_postOffices)
		post_office.Shutdown();

	s_postOffices.clear();
}

void InitializePostOffice(uint32_t index)
{
	GetPostOffice<MQPostOffice>(index).Initialize();
}

void ShutdownPostOffice(uint32_t index)
{
	GetPostOffice<MQPostOffice>(index).Shutdown();
	s_postOffices.erase(index);
}

void PulsePostOffice(uint32_t index)
{
	GetPostOffice<MQPostOffice>(index).ProcessPipeClient();
}

void SetGameStatePostOffice(int GameState, uint32_t index)
{
	GetPostOffice<MQPostOffice>(index).SetGameStatePostOffice(GameState);
}

} // namespace mq
