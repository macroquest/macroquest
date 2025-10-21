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

#include "ClientPostOffice.h"

#include "mq/base/Base.h"
#include "mq/base/String.h"
#include "spdlog/spdlog.h"

namespace mq::postoffice {

//=============================================================================

class PostOfficePipeHandler : public NamedPipeEvents
{
public:
	PostOfficePipeHandler(ClientPostOffice* postOffice)
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
	ClientPostOffice* m_postOffice;
};

//-----------------------------------------------------------------------------

ClientPostOffice::ClientPostOffice(const std::string& name, const std::string& pipeName, ActorIdentification id)
	: PostOffice(std::move(id))
	, m_name(name)
	, m_pipeClient(pipeName.c_str())
{
	m_clientDropbox = RegisterAddress("pipe_client", [this](MessagePtr message)
	{
		// if we've gotten here, then something is delivering a message to this
		// post office ("pipe_client"), so handle messages directly

		UNUSED(message);
	});

	m_pipeClient.SetHandler(std::make_shared<PostOfficePipeHandler>(this));
}

ClientPostOffice::~ClientPostOffice()
{
}

void ClientPostOffice::RouteMessage(MessagePtr message)
{
	// dropbox.Post(Reply) was called, so route the message out

	// always enrich the return address
	*message->mutable_return_address()->mutable_client() = GetCurrentClient().GetProto();

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

void ClientPostOffice::Initialize()
{
	if (!m_initialized)
	{
		SPDLOG_TRACE("PostOffice {{{}}}: Initializing", GetName());

		m_pipeClient.Start();

		m_initialized = true;
	}
}

void ClientPostOffice::Shutdown()
{
	if (m_initialized)
	{
		SPDLOG_TRACE("PostOffice {{{}}}: Shutting down", GetName());

		// after the mailbox is removed from the post office, it won't get any more messages, and lets
		// make sure all remaining messages get discarded by dropping the last reference so we stop
		// processing
		m_clientDropbox.Remove();

		// we don't need to worry about sending messages after we stop because the pipe client will log
		// and handle this situation.
		m_pipeClient.Stop();

		m_initialized = false;
	}
}

void ClientPostOffice::ProcessPipeClient()
{
	m_pipeClient.Process();
	Process(1000); // make this large just to prevent overflows
}

void ClientPostOffice::OnIncomingMessage(PipeMessagePtr message)
{
	switch (message->GetMessageId())  // NOLINT(clang-diagnostic-switch-enum)
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
		SPDLOG_TRACE("PostOffice {{{}}}: Received routed message in MQ to=[{}]", GetName(), address ? address->ShortDebugString() : "no address");
		if (address && address->has_mailbox())
		{
			// we need to loop all mailboxes and deliver to all of them that end with the address
			// if this is an RPC message, then we need to ensure that we have only one
			if (envelope->mode() == static_cast<uint32_t>(MQRequestMode::CallAndResponse))
			{
				auto mailbox = FindMailbox(*address, m_mailboxes.begin());

				if (mailbox == m_mailboxes.end()) // no addresses
					RoutingFailed(MsgError_RoutingFailed, std::move(envelope), "No mailbox found");
				else if (FindMailbox(*address, std::next(mailbox)) != m_mailboxes.end())
					RoutingFailed(MsgError_AmbiguousRecipient, std::move(envelope), "Multiple mailboxes found");
				else // we have exactly one recipient, this is valid
					DeliverTo(address->mailbox(), std::move(envelope));
			}
			else
			{
				// in any other case, just route the message
				DeliverTo(address->mailbox(), std::move(envelope));
			}
		}
		else
		{
			// This is a failsafe action, we shouldn't expect to be here often. For this code to
			// be reached, we would have to have a client that packages a message in an envelope
			// that is intended to be parsed directly by the server and not routed anywhere (so
			// no mailbox routing information is included), rather than just send the message
			DeliverTo("pipe_client", std::move(envelope));
		}

		break;
	}
	default: break;
	}
}

void ClientPostOffice::OnClientConnected()
{
	SPDLOG_TRACE("PostOffice {{{}}}: Connection to named pipe created, Sending process loaded message.", GetName());

	// Send our identification
	SendSelfIdentification();

	// and then ask for the list of all ID's
	m_pipeClient.SendMessage(MQMessageId::MSG_IDENTIFICATION, nullptr, 0);
}

void ClientPostOffice::SendSelfIdentification()
{
	// Update identity
	SPDLOG_TRACE("PostOffice {{{}}}: Updating identity", GetName());
	m_id.address = GetCurrentClient();

	m_pipeClient.SendProtoMessage(MQMessageId::MSG_IDENTIFICATION, m_id.GetProto());
}

//-----------------------------------------------------------------------------

MailboxMap::iterator ClientPostOffice::FindMailbox(const proto::routing::Address& address,
	MailboxMap::iterator from)
{
	if (!address.has_mailbox())
		return m_mailboxes.end();

	return std::find_if(from, m_mailboxes.end(),
		[&address](const MailboxMap::value_type& pair)
		{ return mq::ci_ends_with(pair.first, address.mailbox()); });
}

MailboxMap::const_iterator ClientPostOffice::FindMailbox(const proto::routing::Address& address,
	MailboxMap::const_iterator from) const
{
	if (!address.has_mailbox())
		return m_mailboxes.end();

	return std::find_if(from, m_mailboxes.end(),
		[&address](const MailboxMap::value_type& pair)
		{ return mq::ci_ends_with(pair.first, address.mailbox()); });
}

//=============================================================================

} // namespace mq::postoffice
