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
namespace mailbox {

// we should assume that everything lives inside an Envelope here. All mail must be
// in an envelope, no postcards (yet), but we open the Envelope to create ProtoMessages
// when we put them on the queue
class PostOffice
{
public:
	using ReceiveCallback = void(*)(ProtoMessagePtr);

public:
	class Mailbox
	{
		friend class PostOffice;

	public:
		Mailbox(
			std::string_view localAddress,
			ReceiveCallback receive,
			void(*postCallback)(const std::string&)
		)
			: m_localAddress(localAddress)
			, m_receive(receive)
			, m_post(postCallback)
		{}

		template <typename T>
		void Post(const proto::Address& address, MQMessageId messageId, const T& obj)
		{
			m_post(Stuff(address, messageId, obj));
		}

		template <typename T>
		void PostReply(ProtoMessagePtr message, MQMessageId messageId, const T& obj, uint8_t status = 0)
		{
			if (auto returnAddress = message->GetReturn())
			{
				PostReply(message, *returnAddress, messageId, obj, status);
			}
			else
			{
				message->SendProtoReply(messageId, obj, status);
			}
		}

		template <typename T>
		void PostReply(PipeMessagePtr message, const proto::Address& returnAddress, MQMessageId messageId, const T& obj, uint8_t status = 0)
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
		void Deliver(PipeMessagePtr message) const
		{
			// Don't do anything if this isn't wrapped in an envelope
			if (message->GetMessageId() == MQMessageId::MSG_ROUTE)
			{
				auto envelope = ProtoMessage::Parse<proto::Envelope>(message);
				m_receiveQueue.push(Open(envelope, *message->GetHeader()));
			}
		}

		void Process(size_t howMany) const
		{
			if (howMany > 0 && !m_receiveQueue.empty())
			{
				m_receive(m_receiveQueue.front());
				m_receiveQueue.pop();

				Process(howMany - 1);
			}
		}

		ProtoMessagePtr Open(const proto::Envelope& envelope, const MQMessageHeader& header) const
		{
			auto unwrapped = envelope.has_payload() ?
				std::make_shared<ProtoMessage>(header, &envelope.payload()[0], envelope.payload().size()) :
				std::make_shared<ProtoMessage>(header, nullptr, 0);

			if (envelope.has_message_id())
				unwrapped->GetHeader()->messageId = static_cast<MQMessageId>(envelope.message_id());

			if (envelope.has_return_address())
				unwrapped->SetReturn(envelope.return_address());

			return unwrapped;
		}

		template <typename T>
		std::string Stuff(const proto::Address& address, MQMessageId messageId, const T& obj)
		{
			return Stuff(address, messageId, obj.SerializeAsString());
		}

		template <>
		std::string Stuff(const proto::Address& address, MQMessageId messageId, const std::string& data)
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
		void(*m_post)(const std::string&);
		const std::string m_localAddress;
		const ReceiveCallback m_receive;

		mutable std::queue<ProtoMessagePtr> m_receiveQueue;
	};

public:
	PostOffice(void(*postAction)(const std::string&))
		: m_post(postAction)
	{}

	std::shared_ptr<Mailbox> CreateMailbox(const std::string& localAddress, ReceiveCallback receive)
	{
		return std::make_shared<Mailbox>(localAddress, receive, m_post);
	}

	bool AddMailbox(const std::string& localAddress, std::shared_ptr<Mailbox> mailbox)
	{
		auto [_, added] = m_mailboxes.emplace(mailbox->GetAddress(), mailbox);
		return added;
	}

	bool RemoveMailbox(const std::string& localAddress)
	{
		return m_mailboxes.erase(localAddress) == 1;
	}

	bool DeliverTo(const std::string& localAddress, PipeMessagePtr message)
	{
		auto mailbox_it = m_mailboxes.find(localAddress);
		if (mailbox_it != m_mailboxes.end())
		{
			if (auto ptr = mailbox_it->second.lock())
			{
				ptr->Deliver(message);
				return true;
			}

			m_mailboxes.erase(mailbox_it);
		}

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
	void(*m_post)(const std::string&);
};

} // namespace mailbox

} // namespace mq
