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

#include "routing/Routing.h"

#include <string>
#include <unordered_map>
#include <queue>
#include <memory>

namespace mq {
namespace postoffice {

/**
 * Abstract post office class for handling routing of messages
 * 
 * Each application's post office (for instance, MQ and Launcher) will need to implement
 * this class, specifying how to route proto messages. They will also need to define the
 * singleton that the application can use to get the post office to do things like create
 * mailboxes or send mail to other actors (nominally through the launcher).
 * 
 * we should assume that everything lives inside an Envelope here. All mail must be
 * in an envelope, no postcards (yet), but we open the Envelope to create ProtoMessages
 * when we put them on the queue
 */
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
			, m_receive(std::move(receive))
			, m_post(std::move(post))
		{}

		/**
		 * Sends a message to an address
		 * 
		 * @tparam ID an identifier to be used by the receiver, must cast to uint32_t
		 * @tparam T the message being sent, usually some kind of proto
		 * 
		 * @param address the address to send the message
		 * @param messageId a message ID used to route the message at the receiver
		 * @param obj the message (as an object)
		 */
		template <typename ID, typename T>
		void Post(const proto::Address& address, ID messageId, const T& obj)
		{
			m_post(Stuff(address, messageId, obj));
		}

		/**
		 * Sends an empty message to an address
		 * 
		 * @tparam ID an identifier to be used by the receiver, must cast to uint32_t
		 * 
		 * @param address the address to send the message
		 * @param messageId a message ID used to route the message at the receiver
		 */
		template <typename ID>
		void Post(const proto::Address& address, ID messageId)
		{
			m_post(StuffData(address, messageId, ""));
		}

		/**
		 * Sends a reply to the sender of a message
		 * 
		 * @tparam ID an identifier to be used by the receiver, must cast to uint32_t
		 * @tparam T the message being sent, usually some kind of proto
		 * 
		 * @param message the original message to reply to (contains the sender address)
		 * @param messageId a message ID used to rout the message at the receiver
		 * @param obj the message (as an object)
		 * @param status a return status, sometimes used by reply handling logic
		 */
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

		/**
		 * Sends a reply to the sender of a message -- the message can be anything
		 * because we make no assumption about what is wrapped in the envelope
		 * 
		 * @tparam ID an identifier to be used by the receiver, must cast to uint32_t
		 * @tparam T the message being sent, usually some kind of proto
		 * 
		 * @param message the original message to reply to
		 * @param returnAddress the address to reply to
		 * @param messageId a message ID used to rout the message at the receiver
		 * @param obj the message (as an object)
		 * @param status a return status, sometimes used by reply handling logic
		 */
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

		/**
		 * Gets the address of this mailbox
		 * 
		 * @return the local address of this mailbox
		 */
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
			return StuffData(address, messageId, obj.SerializeAsString());
		}

		template <typename ID>
		std::string StuffData(const proto::Address& address, ID messageId, const std::string& data)
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

	/**
	 * The interface to route a message, to be implemented in the post office instantiation
	 * 
	 * @param message the message to route -- it should be in an envelope and have the ID of ROUTE
	 */
	virtual void RouteMessage(PipeMessagePtr&& message) = 0;

	/**
	 * The interface to route a message, to be implemented in the post office instantiation
	 * 
	 * @param data the data buffer of the message to route 
	 * @param length the length of the data buffer
	 */
	virtual void RouteMessage(const void* data, size_t length) = 0;

	/**
	 * A helper interface to route a message
	 * 
	 * @param data a string of data (which embeds its length)
	 */
	void RouteMessage(const std::string& data)
	{
		RouteMessage(&data[0], data.size());
	}

	/**
	 * Create a mailbox and return the pointer
	 * 
	 * @param localAddress the string address to create the address at
	 * @param receive a callback rvalue that will process messages as they are received in this mailbox
	 * @return a shared_ptr of the newly created mailbox
	 */
	std::shared_ptr<Mailbox> CreateMailbox(const std::string& localAddress, ReceiveCallback&& receive)
	{
		return std::make_shared<Mailbox>(localAddress, std::move(receive), [this](const std::string& data) { RouteMessage(data); });
	}

	/**
	 * Register an already created mailbox with the post office
	 * 
	 * @param mailbox the shared_ptr ref of an already created mailbox
	 * @return true if the mailbox was able to be placed into the post office (with a unique address)
	 */
	bool AddMailbox(const std::shared_ptr<Mailbox>& mailbox)
	{
		auto [_, added] = m_mailboxes.emplace(mailbox->GetAddress(), mailbox);
		return added;
	}

	/**
	 * Creates and registers a mailbox with the post office
	 * 
	 * @param localAddress the string address to create the address at
	 * @param receive a callback rvalue that will process messages as they are received in this mailbox
	 * @return a shared_ptr of the newly created mailbox, or nullptr if it wasn't able to be added at the address
	 */
	std::shared_ptr<Mailbox> CreateAndAddMailbox(const std::string& localAddress, ReceiveCallback&& receive)
	{
		auto mailbox = CreateMailbox(localAddress, std::move(receive));
		if (mailbox && AddMailbox(mailbox))
			return mailbox;

		return {};
	}

	/**
	 * Removes a mailbox from the post office
	 * 
	 * @param localAddress the string address that identifies the mailbox to be removed
	 * @return true if the mailbox was removed
	 */
	bool RemoveMailbox(const std::string& localAddress)
	{
		return m_mailboxes.erase(localAddress) == 1;
	}

	/**
	 * Delivers a message to a local mailbox
	 * 
	 * @param localAddress the local address to deliver the message to
	 * @param message the message to send
	 * @param failed a callback for failure (since message is moved)
	 * @return true if routing was successful
	 */
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

	/**
	 * Delivers a message to all local mailboxes from a particular mailbox
	 * 
	 * @param message the message to send -- only the message ID and the payload is used (the header is rebuilt per message)
	 * @param the mailbox from where to send the messages -- important because this is the return address
	 */
	void DeliverAll(PipeMessagePtr&& message, const std::shared_ptr<Mailbox>& from)
	{
		// the actual address doesn't matter here, we are delivering directly to the mailboxes
		// we can also discard the header, it doesn't matter since these are all local deliveries
		auto envelope = from->StuffData(
			proto::Address{},
			message->GetMessageId(),
			std::string(message->get<char>(), message->size())
		);

		for (auto mailbox_it = m_mailboxes.begin(); mailbox_it != m_mailboxes.end();)
		{
			if (mailbox_it->first != from->GetAddress())
			{
				if (auto ptr = mailbox_it->second.lock())
				{
					ptr->Deliver(
						std::make_unique<PipeMessage>(MQMessageId::MSG_ROUTE, &envelope[0], envelope.size())
					);

					++mailbox_it;
				}
				else
				{
					mailbox_it = m_mailboxes.erase(mailbox_it);
				}
			}
			else
			{
				++mailbox_it;
			}
		}
	}

	/**
	 * Processes messages waiting in the queue
	 * 
	 * @param howMany how many messages to process (up to)
	 */
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

/**
 * Returns this application's post office singleton
 * 
 * @return the single post office that is used in this application
 */
MQLIB_OBJECT PostOffice& GetPostOffice();

} // namespace postoffice

} // namespace mq
