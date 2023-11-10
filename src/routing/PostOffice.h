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

#include "Routing.h"

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
	public:
		Mailbox(std::string_view localAddress, ReceiveCallback&& receive)
			: m_localAddress(localAddress)
			, m_receive(std::move(receive))
		{}

		/**
		 * Gets the address of this mailbox
		 * 
		 * @return the local address of this mailbox
		 */
		const std::string& GetAddress() const { return m_localAddress; }

		/**
		 * Delivers a message to this mailbox to be handled by the receive callback
		 * 
		 * @param message the message to deliver
		 */
		void Deliver(PipeMessagePtr&& message) const
		{
			// Don't do anything if this isn't wrapped in an envelope
			if (message->GetMessageId() == MQMessageId::MSG_ROUTE)
			{
				m_receiveQueue.push(Open(ProtoMessage::Parse<proto::Envelope>(message), *message->GetHeader()));
			}
		}

		/**
		 * Process some messages that have been delivered
		 * 
		 * @param howMany how many messages to process off the queue
		 */
		void Process(size_t howMany) const
		{
			if (howMany > 0 && !m_receiveQueue.empty())
			{
				m_receive(std::move(m_receiveQueue.front()));
				m_receiveQueue.pop();

				Process(howMany - 1);
			}
		}

	private:
		static ProtoMessagePtr Open(proto::Envelope&& envelope, const MQMessageHeader& header)
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

		const std::string m_localAddress;
		const ReceiveCallback m_receive;

		mutable std::queue<ProtoMessagePtr> m_receiveQueue;
	};

	class Dropbox
	{
		friend class PostOffice;

	public:
		Dropbox()
			: m_post(nullptr)
		{}

		Dropbox(std::string_view localAddress, PostCallback&& post)
			: m_localAddress(localAddress)
			, m_post(std::move(post))
		{}

		Dropbox(const Dropbox& other)
			: m_localAddress(other.m_localAddress)
			, m_post(other.m_post)
		{}

		Dropbox(Dropbox&& other) noexcept
			: m_localAddress(std::move(other.m_localAddress))
			, m_post(std::exchange(other.m_post, nullptr))
		{}

		Dropbox& operator=(const Dropbox& other)
		{
			return *this = Dropbox(other);
		}

		Dropbox& operator=(Dropbox&& other) noexcept
		{
			using std::swap;
			swap(m_localAddress, other.m_localAddress);
			swap(m_post, other.m_post);
			return *this;
		}

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
			if (IsValid()) m_post(Stuff(address, messageId, obj));
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
			if (IsValid()) m_post(StuffData(address, messageId, ""));
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
			if (IsValid())
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
			if (IsValid())
			{
				std::string data = Stuff(returnAddress, messageId, obj);
				message->SendReply(MQMessageId::MSG_ROUTE, &data[0], data.size(), status);
			}
		}

		/**
		 * Checks if the dropbox has a post callback and an address
		 * 
		 * @return this dropbox is valid and will send messages
		 */
		bool IsValid() { return m_post != nullptr && !m_localAddress.empty(); }

	private:
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

		std::string m_localAddress;
		PostCallback m_post;
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
	 * Creates and registers a mailbox with the post office
	 * 
	 * @param localAddress the string address to create the address at
	 * @param receive a callback rvalue that will process messages as they are received in this mailbox
	 * @return an dropbox that the creator can use to send addressed messages. will be invalid if it failed to add
	 */
	Dropbox CreateAndAddMailbox(const std::string& localAddress, ReceiveCallback&& receive)
	{
		auto [mailbox, added] = m_mailboxes.emplace(localAddress, std::make_unique<Mailbox>(localAddress, std::move(receive)));
		if (added)
		{
			return Dropbox(localAddress, [this](const std::string& data) { RouteMessage(data); });
		}

		return Dropbox();
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
			mailbox_it->second->Deliver(std::move(message));
			return true;
		}

		failed(std::move(message));
		return false;
	}

	/**
	 * Delivers a message to all local mailboxes, optionally excluding self
	 * 
	 * @param message the message to send -- only the message ID and the payload is used (the header is rebuilt per message)
	 * @param fromAddress the address to exclude from the delivery
	 */
	void DeliverAll(PipeMessagePtr& message, std::optional<std::string_view> fromAddress = {})
	{
		for (const auto& [name, mailbox] : m_mailboxes)
		{
			if (fromAddress && name != *fromAddress)
			{
				mailbox->Deliver(
					std::make_unique<PipeMessage>(*message->GetHeader(), message->get(), message->size())
				);
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
		for (const auto& [_, mailbox] : m_mailboxes)
		{
			mailbox->Process(messages_per_mailbox);
		}
	}

private:
	std::unordered_map<std::string, std::unique_ptr<Mailbox>> m_mailboxes;
};

/**
 * Returns this application's post office singleton
 * 
 * @return the single post office that is used in this application
 */
MQLIB_OBJECT PostOffice& GetPostOffice();

} // namespace postoffice

} // namespace mq
