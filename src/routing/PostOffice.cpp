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

namespace mq::postoffice {

void Mailbox::Deliver(PipeMessagePtr&& message) const
{
	// Don't do anything if this isn't wrapped in an envelope
	if (message->GetMessageId() == MQMessageId::MSG_ROUTE)
	{
		m_receiveQueue.push(Open(ProtoMessage::Parse<proto::routing::Envelope>(message), message));
	}
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

ProtoMessagePtr Mailbox::Open(proto::routing::Envelope&& envelope, const PipeMessagePtr& message)
{
	ProtoMessagePtr unwrapped;

	const void* data = nullptr;
	size_t length = 0;
	if (envelope.has_payload())
	{
		data = &envelope.payload()[0];
		length = envelope.payload().size();
	}

	if (message != nullptr) // this resets the m_replied member, but it couldn't have become true before this anyway
		unwrapped = std::make_unique<ProtoMessage>(*message, data, length);
	else
		unwrapped = std::make_unique<ProtoMessage>(MQMessageId::MSG_NULL, data, length);

	if (envelope.has_return_address())
		unwrapped->SetSender(envelope.return_address());

	return unwrapped;
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

void Dropbox::Remove()
{
	if (m_valid)
		m_unregister(m_localAddress);
	
	m_valid = false;
}

void PostOffice::RouteMessage(const void* data, size_t length, const PipeMessageResponseCb& callback)
{
	RouteMessage(std::make_unique<PipeMessage>(MQMessageId::MSG_ROUTE, data, length), callback);
}

void PostOffice::RouteMessage(const std::string& data, const PipeMessageResponseCb& callback)
{
	RouteMessage(&data[0], data.size(), callback);
}

Dropbox PostOffice::RegisterAddress(const std::string& localAddress, ReceiveCallback&& receive)
{
	auto [mailbox, added] = m_mailboxes.emplace(localAddress, std::make_unique<Mailbox>(localAddress, std::move(receive)));
	if (added)
	{
		return Dropbox(
			localAddress,
			[this](const std::string& data, const PipeMessageResponseCb& callback) { RouteMessage(data, callback); },
			[this](const std::string& localAddress) { RemoveMailbox(localAddress); });
	}

	return Dropbox();
}

bool PostOffice::RemoveMailbox(const std::string& localAddress)
{
	return m_mailboxes.erase(localAddress) == 1;
}

bool PostOffice::DeliverTo(const std::string& localAddress, PipeMessagePtr&& message, const std::function<void(int, PipeMessagePtr&&)>& failed)
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

void PostOffice::DeliverAll(PipeMessagePtr& message, std::optional<std::string_view> fromAddress)
{
	for (const auto& [name, mailbox] : m_mailboxes)
	{
		if (fromAddress && name != *fromAddress)
		{
			OnDeliver(name, message);
			mailbox->Deliver(
				std::make_unique<PipeMessage>(*message->GetHeader(), message->get(), message->size())
			);
		}
	}
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