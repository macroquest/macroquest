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

#include "PostOffice.h"

#include "spdlog/spdlog.h"

#include <rpc.h>
#pragma comment(lib, "rpcrt4.lib")

namespace mq {

std::string CreateUUID()
{
	UUID uuid;
	::UuidCreate(&uuid);
	char* uuid_str;
	::UuidToStringA(&uuid, reinterpret_cast<RPC_CSTR*>(&uuid_str));
	std::string return_uuid(uuid_str);
	::RpcStringFreeA(reinterpret_cast<RPC_CSTR*>(&uuid_str));
	return return_uuid;
}

namespace postoffice {

// Static helper for creating an ActorContainer::Process representing the current process
ActorContainer::Process ActorContainer::CurrentProcess{ ::GetCurrentProcessId() };

void Mailbox::Deliver(MessagePtr message) const
{
	SPDLOG_TRACE("Mailbox {{{}}}: Delivering message to address {}",
		m_localAddress, message->address().ShortDebugString());

	m_receiveQueue.push(std::move(message));
}

void Mailbox::Process(size_t howMany) const
{
	if (howMany > 0 && !m_receiveQueue.empty())
	{
		SPDLOG_TRACE("Mailbox {{{}}}: Processing queue", m_localAddress);

		m_receive(std::move(m_receiveQueue.front()));
		m_receiveQueue.pop();

		Process(howMany - 1);
	}
}

Dropbox::Dropbox(std::string localAddress, PostCallback&& post, DropboxDropper&& unregister)
	: m_localAddress(localAddress)
	, m_post(post)
	, m_unregister(unregister)
	, m_valid(true)
{
}

Dropbox::Dropbox(const Dropbox& other)
	: m_localAddress(other.m_localAddress)
	, m_post(other.m_post)
	, m_unregister(other.m_unregister)
	, m_valid(other.m_valid)
{
}

Dropbox::Dropbox(Dropbox&& other) noexcept
	: m_localAddress(std::move(other.m_localAddress))
	, m_post(std::move(other.m_post))
	, m_unregister(std::move(other.m_unregister))
	, m_valid(other.m_valid)
{
}

Dropbox& Dropbox::operator=(Dropbox other) noexcept
{
	m_localAddress = std::move(other.m_localAddress);
	m_post = std::move(other.m_post);
	m_unregister = std::move(other.m_unregister);
	m_valid = other.m_valid;
	return *this;
}

void Dropbox::PostReply(MessagePtr message, const std::string& data, int status)
{
	if (IsValid() && message->has_return_address())
	{
		MessagePtr reply = Stuff(message->return_address(), data);
		reply->set_sequence(message->sequence());
		reply->set_status(status);
		reply->set_mode(static_cast<uint32_t>(MQRequestMode::MessageReply));

		m_post(std::move(reply), nullptr);
	}
}

void Dropbox::Remove()
{
	if (m_valid)
		m_unregister(m_localAddress);
	
	m_valid = false;
}

MessagePtr Dropbox::Stuff(const proto::routing::Address& address, const std::string& data)
{
	auto envelope = std::make_unique<proto::routing::Envelope>();
	*envelope->mutable_address() = address;
	envelope->set_payload(data);

	return envelope;
}

PostOffice::PostOffice(ActorIdentification id)
	: m_id(id)
{
	m_dropbox = RegisterAddress("post_office",
		[this](MessagePtr message)
	{
		// if we've gotten here, then something is delivering a message to this
		// post office ("post_office"), we don't have any logic to do here so
		// all messages will just get dropped
	});
}

PostOffice::~PostOffice()
{
	for (const auto& [sequenceId, request] : m_rpcRequests)
	{
		auto msg = std::make_unique<proto::routing::Envelope>();
		msg->set_status(MsgError_ConnectionClosed);
		msg->set_sequence(request.sequenceId);
		m_id.BuildAddress(*msg->mutable_address());
		m_id.BuildAddress(*msg->mutable_return_address());

		request.callback(MsgError_ConnectionClosed, std::move(msg));
	}

	m_rpcRequests.clear();

	// after the mailbox is removed from the post office, it won't get any more messages, and let's
	// make sure all remaining messages get discarded by dropping the last reference, so we stop
	// processing
	m_dropbox.Remove();
}

void PostOffice::RouteMessage(const proto::routing::Address& address, const std::string& data)
{
	auto envelope = std::make_unique<proto::routing::Envelope>();
	*envelope->mutable_address() = address;

	m_id.BuildAddress(*envelope->mutable_return_address());

	envelope->set_payload(data);

	RouteMessage(std::move(envelope));
}

void PostOffice::RoutingFailed(int status, MessagePtr message, std::string_view what)
{
	// don't do anything if this isn't an RPC, nothing else will expect a response
	if (message->mode() == static_cast<uint32_t>(MQRequestMode::CallAndResponse))
	{
		auto data = fmt::format("{} at address {}", what, message->address().ShortDebugString());
		m_dropbox.PostReply(std::move(message), std::move(data), status);
	}
}

Dropbox PostOffice::RegisterAddress(const std::string& localAddress, ReceiveCallback&& receive)
{
	auto [mailbox, added] = m_mailboxes.emplace(
		localAddress, std::make_unique<Mailbox>(localAddress,
			[receive = std::move(receive), this](MessagePtr message)
			{
				SPDLOG_TRACE("Mailbox {{{}}}: Received message at address {}",
					m_id, message->address().ShortDebugString());

				if (message->mode() == static_cast<uint32_t>(MQRequestMode::MessageReply))
				{
					// we are receiving a reply, find the associated RPC and call the callback
					auto request = m_rpcRequests.find(message->sequence());
					if (request != m_rpcRequests.end())
					{
						int status = message->status();
						request->second.callback(status, std::move(message));

						m_rpcRequests.erase(request);
					}
					else
					{
						SPDLOG_WARN("Mailbox {{{}}}: Failed to find RPC seq={} in post office on message reply at address {}",
							m_id, message->sequence(), message->address().ShortDebugString());
					}
				}
				else
				{
					receive(std::move(message));
				}
			}));

	if (added)
	{
		return Dropbox(
			localAddress,
			[this, localAddress](MessagePtr message, const MessageResponseCallback& callback)
			{
				// the post callback -- this will always be called on the generation side of messages so we need
				// to set initial values
				if (message->sequence() == 0)
					message->set_sequence(++m_nextSequence);

				// set the specific return address
				proto::routing::Address& ret = *message->mutable_return_address();
				m_id.BuildAddress(ret);
				ret.set_mailbox(localAddress);

				SPDLOG_TRACE("Dropbox {{{}}}}: posting message to address {} seq={}",
					m_id, message->address().ShortDebugString(), message->sequence());

				if (callback != nullptr)
				{
					// we are posting an RPC, store the request here so it gets handled on the response
					// TODO: handle timeouts so we don't grow this map without bound
					message->set_mode(static_cast<uint32_t>(MQRequestMode::CallAndResponse));
					m_rpcRequests.emplace(message->sequence(),
						RpcRequest<MessageResponseCallback>{
						callback,
							message->sequence(),
							std::chrono::steady_clock::now()
					});
				}

				RouteMessage(std::move(message));
			},
			[this](const std::string& localAddress)
			{
				RemoveMailbox(localAddress);
			});
	}

	return Dropbox();
}

bool PostOffice::RemoveMailbox(const std::string& localAddress)
{
	return m_mailboxes.erase(localAddress) == 1;
}

bool PostOffice::DeliverTo(const std::string& localAddress, MessagePtr message)
{
	auto mailbox_it = m_mailboxes.find(localAddress);
	if (mailbox_it != m_mailboxes.end())
	{
		OnDeliver(localAddress, message);
		mailbox_it->second->Deliver(std::move(message));
		return true;
	}

	RoutingFailed(MsgError_RoutingFailed, std::move(message), "Cannot find mailbox to receive");
	return false;
}

void PostOffice::Process(size_t howMany)
{
	size_t messages_per_mailbox = std::max(1, (int)std::round(howMany / m_mailboxes.size()));
	for (const auto& [_, mailbox] : m_mailboxes)
	{
		mailbox->Process(messages_per_mailbox);
	}
}

} // namespace postoffice
} // namespace mq