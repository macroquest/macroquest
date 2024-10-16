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

#define MQLIB_OBJECT
#include "PostOffice.h"

#include <windows.h> // this is needed for GetCurrentProcessId

namespace mq::postoffice {

void Mailbox::Deliver(proto::routing::Envelope&& message) const
{
	m_receiveQueue.push(std::move(message));
}

void Mailbox::Process(size_t howMany) const
{
	if (howMany > 0 && !m_receiveQueue.empty())
	{
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
{}

Dropbox::Dropbox(const Dropbox& other)
	: m_localAddress(other.m_localAddress)
	, m_post(other.m_post)
	, m_unregister(other.m_unregister)
	, m_valid(other.m_valid)
{}

Dropbox::Dropbox(Dropbox&& other) noexcept
	: m_localAddress(std::move(other.m_localAddress))
	, m_post(std::move(other.m_post))
	, m_unregister(std::move(other.m_unregister))
	, m_valid(other.m_valid)
{}

Dropbox& Dropbox::operator=(Dropbox other) noexcept
{
	m_localAddress = std::move(other.m_localAddress);
	m_post = std::move(other.m_post);
	m_unregister = std::move(other.m_unregister);
	m_valid = other.m_valid;
	return *this;
}

void Dropbox::PostReply(proto::routing::Envelope&& message, const std::string& data, int status)
{
	if (IsValid() && message.has_return_address())
	{
		proto::routing::Envelope reply = Stuff(message.return_address(), data);
		reply.set_sequence(message.sequence());
		reply.set_status(status);
		reply.set_mode(static_cast<uint32_t>(MQRequestMode::MessageReply));

		m_post(std::move(reply), nullptr);
	}
}

void Dropbox::Remove()
{
	if (m_valid)
		m_unregister(m_localAddress);
	
	m_valid = false;
}

proto::routing::Envelope Dropbox::Stuff(const proto::routing::Address& address, const std::string& data)
{
	proto::routing::Envelope envelope;
	*envelope.mutable_address() = address;
	envelope.set_payload(data);

	return envelope;
}

PostOffice::PostOffice(ActorIdentification&& id)
	: m_id(std::move(id))
{}

PostOffice::~PostOffice()
{
	for (const auto& [sequenceId, request] : m_rpcRequests)
	{
		request.callback(MsgError_ConnectionClosed, {});
	}

	m_rpcRequests.clear();
}

void PostOffice::RouteMessage(const proto::routing::Address& address, const std::string& data, const MessageResponseCallback& callback)
{
	proto::routing::Envelope envelope;
	*envelope.mutable_address() = address;

	proto::routing::Address& ret = *envelope.mutable_return_address();
	ret.set_pid(GetCurrentProcessId());

	envelope.set_payload(data);

	RouteMessage(std::move(envelope), callback);
}

Dropbox PostOffice::RegisterAddress(const std::string& localAddress, ReceiveCallback&& receive)
{
	auto [mailbox, added] = m_mailboxes.emplace(
		localAddress, std::make_unique<Mailbox>(localAddress,
			[receive = std::move(receive), this](proto::routing::Envelope&& message)
			{
				if (message.mode() == static_cast<uint32_t>(MQRequestMode::MessageReply))
				{
					// we are receiving a reply, find the associated RPC and call the callback
					auto request = m_rpcRequests.find(message.sequence());
					if (request != m_rpcRequests.end())
					{
						int status = message.status();
						request->second.callback(status, std::move(message));

						m_rpcRequests.erase(request);
					}
				}
				else
				{
					// if we are receiving a request for a reply, store the request so we get one-time guarantees
						// TODO: handle timeouts so we don't grow this set without bound
					if (message.mode() == static_cast<uint32_t>(MQRequestMode::CallAndResponse))
						m_rpcReceived.insert(message.sequence());

					receive(std::move(message));
				}
			}));

	if (added)
	{
		return Dropbox(
			localAddress,
			[this](proto::routing::Envelope&& message, const MessageResponseCallback& callback)
			{
				// the post callback -- this will always be called on the generation side of messages so we need
				// to set initial values

				// set the specific return address
				proto::routing::Address& ret = *message.mutable_return_address();
				m_id.BuildAddress(ret);

				if (message.mode() == static_cast<uint32_t>(MQRequestMode::MessageReply))
				{
					// assume a reply always has a sequence set
					// we are trying to reply to an RPC, make sure it's valid and gets replied to exactly once
					auto seq_it = m_rpcReceived.find(message.sequence());
					if (seq_it != m_rpcReceived.end())
					{
						m_rpcReceived.erase(seq_it);
						RouteMessage(std::move(message), callback);
					}
				}
				else
				{
					if (message.sequence() == 0)
						message.set_sequence(++m_nextSequence);

					if (callback != nullptr)
					{
						// we are posting an RPC, store the request here so it gets handled on the response
						// TODO: handle timeouts so we don't grow this map without bound
						message.set_mode(static_cast<uint32_t>(MQRequestMode::CallAndResponse));
						m_rpcRequests.emplace(message.sequence(),
							RPCRequest{
								callback,
								message.sequence(),
								std::chrono::steady_clock::now()
							});
					}

					RouteMessage(std::move(message), callback);
				}
			},
			[this](const std::string& localAddress)
			{ RemoveMailbox(localAddress); });
	}

	return Dropbox();
}

bool PostOffice::RemoveMailbox(const std::string& localAddress)
{
	return m_mailboxes.erase(localAddress) == 1;
}

bool PostOffice::DeliverTo(const std::string& localAddress, proto::routing::Envelope&& message, const MessageResponseCallback& failed)
{
	auto mailbox_it = m_mailboxes.find(localAddress);
	if (mailbox_it != m_mailboxes.end())
	{
		OnDeliver(localAddress, message);
		mailbox_it->second->Deliver(std::move(message));
		return true;
	}

	failed(MsgError_RoutingFailed, std::move(message));
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

} // namespace mq::postoffice