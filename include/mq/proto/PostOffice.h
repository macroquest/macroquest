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

#pragma once

#include "ProtoPipes.h"
#include "Routing.pb.h"

#include <string>
#include <unordered_map>
#include <queue>
#include <memory>

namespace mq {
namespace postoffice {

// we should assume that everything lives inside an Envelope here. All mail must be
// in an envelope, no postcards (yet), but we open the Envelope to create ProtoMessages
// when we put them on the queue
class PostOffice
{
public:
	using ReceiveCallback = std::function<void(ProtoMessagePtr&&)>;
	using PostCallback = std::function<void(const std::string&)>;

public:
	class Mailbox
	{
		friend class PostOffice;

	public:
		Mailbox(
			std::string_view localAddress,
			ReceiveCallback&& receive,
			PostCallback&& post
		)
			: m_localAddress(localAddress)
			, m_receive(receive)
			, m_post(std::move(post))
		{}

		template <typename ID, typename T>
		void Post(const proto::Address& address, ID messageId, const T& obj)
		{
			m_post(Stuff(address, messageId, obj));
		}

		template <typename ID, typename T>
		void PostReply(ProtoMessagePtr&& message, ID messageId, const T& obj, uint8_t status = 0)
		{
			if (auto returnAddress = message->GetSender())
			{
				PostReply(std::move(message), *returnAddress, messageId, obj, status);
			}
			else
			{
				message->SendProtoReply(messageId, obj, status);
			}
		}

		template <typename ID, typename T>
		void PostReply(PipeMessagePtr&& message, const proto::Address& returnAddress, ID messageId, const T& obj, uint8_t status = 0)
		{
			proto::Envelope envelope;
			*envelope.mutable_address() = returnAddress;

			envelope.set_message_id(static_cast<uint32_t>(messageId));

			std::string payload = obj.SerializeAsString();
			envelope.set_payload(payload);

			std::string data = envelope.SerializeAsString();
			message->SendReply(MQMessageId::MSG_ROUTE, &data[0], data.size(), status);
		}

		const std::string& GetAddress() const { return m_localAddress; }

	private:
		void Deliver(PipeMessagePtr&& message) const
		{
			// Don't do anything if this isn't wrapped in an envelope
			if (message->GetMessageId() == MQMessageId::MSG_ROUTE)
			{
				m_receiveQueue.push(Open(ProtoMessage::Parse<proto::Envelope>(message), *message->GetHeader()));
			}
		}

		void Process(size_t howMany) const
		{
			if (howMany > 0 && !m_receiveQueue.empty())
			{
				m_receive(std::move(m_receiveQueue.front()));
				m_receiveQueue.pop();

				Process(howMany - 1);
			}
		}

		ProtoMessagePtr Open(proto::Envelope&& envelope, const MQMessageHeader& header) const
		{
			auto unwrapped = envelope.has_payload() ?
				std::make_unique<ProtoMessage>(header, &envelope.payload()[0], envelope.payload().size()) :
				std::make_unique<ProtoMessage>(header, nullptr, 0);

			if (envelope.has_message_id())
				unwrapped->GetHeader()->messageId = static_cast<MQMessageId>(envelope.message_id());

			if (envelope.has_return_address())
				unwrapped->SetSender(envelope.return_address());

			return unwrapped;
		}

		template <typename ID, typename T>
		std::string Stuff(const proto::Address& address, ID messageId, const T& obj)
		{
			return Stuff(address, messageId, obj.SerializeAsString());
		}

		template <typename ID>
		std::string Stuff(const proto::Address& address, ID messageId, const std::string& data)
		{
			proto::Envelope envelope;
			*envelope.mutable_address() = address;

			envelope.set_message_id(static_cast<uint32_t>(messageId));

			proto::Address& ret = *envelope.mutable_return_address();
			ret.set_pid(GetCurrentProcessId());
			ret.set_mailbox(m_localAddress);

			envelope.set_payload(data);

			return envelope.SerializeAsString();
		}

	private:
		const std::string m_localAddress;
		ReceiveCallback m_receive;
		PostCallback m_post;

		mutable std::queue<ProtoMessagePtr> m_receiveQueue;
	};

public:

	virtual void RouteMessage(PipeMessagePtr&& message) = 0;
	virtual void RouteMessage(const void* data, size_t length) = 0;
	void RouteMessage(const std::string& data)
	{
		RouteMessage(&data[0], data.size());
	}

	std::shared_ptr<Mailbox> CreateMailbox(const std::string& localAddress, ReceiveCallback&& receive)
	{
		return std::make_shared<Mailbox>(localAddress, std::move(receive), [this](const std::string& data) { RouteMessage(data); });
	}

	bool AddMailbox(const std::shared_ptr<Mailbox>& mailbox)
	{
		auto [_, added] = m_mailboxes.emplace(mailbox->GetAddress(), mailbox);
		return added;
	}

	std::shared_ptr<Mailbox> CreateAndAddMailbox(const std::string& localAddress, ReceiveCallback&& receive)
	{
		auto mailbox = CreateMailbox(localAddress, std::move(receive));
		if (mailbox && AddMailbox(mailbox))
			return mailbox;

		return {};
	}

	bool RemoveMailbox(const std::string& localAddress)
	{
		return m_mailboxes.erase(localAddress) == 1;
	}

	// no reason to have a default reply for routing failures because we would need to handle the failure in
	// the derived PostOffice anyway. Let those PostOffice implementations create a failure function callback.
	bool DeliverTo(const std::string& localAddress, PipeMessagePtr&& message, const std::function<void(PipeMessagePtr&&)>& failed = [](const auto&) {})
	{
		auto mailbox_it = m_mailboxes.find(localAddress);
		if (mailbox_it != m_mailboxes.end())
		{
			if (auto ptr = mailbox_it->second.lock())
			{
				ptr->Deliver(std::move(message));
				return true;
			}

			m_mailboxes.erase(mailbox_it);
		}

		failed(std::move(message));
		return false;
	}

	void Process(size_t howMany)
	{
		size_t messages_per_mailbox = std::max(1, (int)std::round(howMany / m_mailboxes.size()));
		for (auto it = m_mailboxes.begin(); it != m_mailboxes.end();)
		{
			if (auto ptr = it->second.lock())
			{
				ptr->Process(messages_per_mailbox);
				++it;
			}
			else
			{
				it = m_mailboxes.erase(it);
			}
		}
	}

private:
	std::unordered_map<std::string, std::weak_ptr<Mailbox>> m_mailboxes;
};

MQLIB_OBJECT PostOffice& GetPostOffice();

} // namespace postoffice

} // namespace mq
