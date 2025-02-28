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

namespace mq::postoffice {

using ReceiveCallback = std::function<void(ProtoMessagePtr&&)>;
using PostCallback = std::function<void(const std::string&, const PipeMessageResponseCb&)>;
using DropboxDropper = std::function<void(const std::string&)>;

class Mailbox
{
public:
	Mailbox(std::string localAddress, ReceiveCallback&& receive)
		: m_localAddress(localAddress)
		, m_receive(std::move(receive))
	{}

	~Mailbox() {}

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
	void Deliver(PipeMessagePtr&& message) const;

	/**
	 * Process some messages that have been delivered
	 *
	 * @param howMany how many messages to process off the queue
	 */
	void Process(size_t howMany) const;

private:
	static ProtoMessagePtr Open(proto::routing::Envelope&& envelope, const PipeMessagePtr& header);

	const std::string m_localAddress;
	const ReceiveCallback m_receive;

	mutable std::queue<ProtoMessagePtr> m_receiveQueue;
};

class Dropbox
{
	friend class PostOffice;

public:
	Dropbox()
		: m_valid(false)
	{}

	~Dropbox() {}

	Dropbox(std::string localAddress, PostCallback&& post, DropboxDropper&& unregister);
	Dropbox(const Dropbox& other);
	Dropbox(Dropbox&& other) noexcept;
	//Dropbox& operator=(const Dropbox& other);
	Dropbox& operator=(Dropbox other) noexcept;

	/**
	 * Sends a message to an address
	 *
	 * @tparam T the message being sent, usually some kind of proto
	 *
	 * @param address the address to send the message
	 * @param obj the message (as an object)
	 * @param callback optional callback for an expected response
	 */
	template <typename T>
	void Post(const proto::routing::Address& address, const T& obj, const PipeMessageResponseCb& callback = nullptr)
	{
		if (IsValid()) m_post(Stuff(address, obj), callback);
	}

	/**
	 * Sends an empty message to an address
	 *
	 * @param address the address to send the message
	 * @param callback optional callback for an expected response
	 */
	void Post(const proto::routing::Address& address, const PipeMessageResponseCb& callback = nullptr)
	{
		if (IsValid()) m_post(Stuff(address, std::string()), callback);
	}

	/**
	 * Sends a reply to the sender of a message -- the message can be anything
	 * because we make no assumption about what is wrapped in the envelope
	 *
	 * @tparam T the message being sent, usually some kind of proto
	 *
	 * @param message the original message to reply to
	 * @param obj the message (as an object)
	 * @param status a return status, sometimes used by reply handling logic
	 */
	template <typename T>
	void PostReply(PipeMessagePtr&& message, const T& obj, uint8_t status = 0)
	{
		if (IsValid())
		{
			std::string data(Data(obj));
			message->SendReply(message->GetMessageId(), &data[0], data.size(), status);
		}
	}

	/**
	 * Sends a reply to the sender of a message -- the message can be anything
	 * because we make no assumption about what is wrapped in the envelope
	 *
	 * @param message the original message to reply to
	 * @param obj the message (as an object)
	 * @param status a return status, sometimes used by reply handling logic
	 */
	template <typename T>
	void PostReply(ProtoMessagePtr&& message, const T& obj, uint8_t status = 0)
	{
		if (IsValid())
		{
			if (auto sender = message->GetSender())
			{
				std::string data(Stuff(*sender, obj));
				message->SendReply(MQMessageId::MSG_ROUTE, &data[0], data.size(), status);
			}
			else
			{
				std::string data(Data(obj));
				message->SendReply(message->GetMessageId(), &data[0], data.size(), status);
			}
		}
	}

	/**
	 * Checks if the dropbox has a post callback and an address
	 *
	 * @return this dropbox is valid and will send messages
	 */
	bool IsValid() { return m_valid; }

	/**
	 * Removes the mailbox with the same name from the post office
	 */
	void Remove();

private:
	template <typename T>
	std::string Data(const T& obj)
	{
		return obj.SerializeAsString();
	}

	std::string Data(const std::string& obj)
	{
		return obj;
	}

	template <typename T>
	std::string Stuff(const proto::routing::Address& address, const T& obj)
	{
		return Stuff(address, obj.SerializeAsString());
	}

	std::string Stuff(const proto::routing::Address& address, const std::string& data)
	{
		proto::routing::Envelope envelope;
		*envelope.mutable_address() = address;

		proto::routing::Address& ret = *envelope.mutable_return_address();
		ret.set_pid(GetCurrentProcessId());
		ret.set_mailbox(m_localAddress);

		envelope.set_payload(data);

		return envelope.SerializeAsString();
	}

	std::string m_localAddress;
	PostCallback m_post;
	DropboxDropper m_unregister;
	bool m_valid;
};


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
	~PostOffice() {}

	/**
	 * The interface to route a message, to be implemented in the post office instantiation
	 *
	 * @param message the message to route -- it should be in an envelope and have the ID of ROUTE
	 * @param callback an optional callback for RPC responses
	 */
	virtual void RouteMessage(PipeMessagePtr&& message, const PipeMessageResponseCb& callback) = 0;

	/**
	 * The interface to route a message, to be implemented in the post office instantiation
	 *
	 * @param data the data buffer of the message to route
	 * @param length the length of the data buffer
	 * @param callback an optional callback for RPC responses
	 */
	void RouteMessage(const void* data, size_t length, const PipeMessageResponseCb& callback);

	/**
	 * A helper interface to route a message directly
	 *
	 * @param address the address to send the message to
	 * @param obj a protobuf object to route
	 * @param callback an optional callback for RPC responses
	 */
	template <typename T>
	void RouteMessage(const proto::routing::Address& address, const T& obj, const PipeMessageResponseCb& callback)
	{
		RouteMessage(address, obj.SerializeAsString(), callback);
	}

	/**
	 * A helper interface to route a message directly
	 *
	 * @param address the address to send the message to
	 * @param data a string of data (which embeds its length)
	 * @param callback an optional callback for RPC responses
	 */
	void RouteMessage(const proto::routing::Address& address, const std::string& data, const PipeMessageResponseCb& callback)
	{
		proto::routing::Envelope envelope;
		*envelope.mutable_address() = address;

		proto::routing::Address& ret = *envelope.mutable_return_address();
		ret.set_pid(GetCurrentProcessId());

		envelope.set_payload(data);

		RouteMessage(envelope, callback);
	}

	/**
	 * A helper interface to route a message
	 *
	 * @param obj a protobuf object to route
	 * @param callback an optional callback for RPC responses
	 */
	template <typename T>
	void RouteMessage(const T& obj, const PipeMessageResponseCb& callback)
	{
		RouteMessage(obj.SerializeAsString(), callback);
	}

	/**
	 * A helper interface to route a message
	 *
	 * @param data a string of data (which embeds its length)
	 * @param callback an optional callback for RPC responses
	 */
	void RouteMessage(const std::string& data, const PipeMessageResponseCb& callback);

	/**
	 * Creates and registers a mailbox with the post office
	 *
	 * @param localAddress the string address to create the address at
	 * @param receive a callback rvalue that will process messages as they are received in this mailbox
	 * @return an dropbox that the creator can use to send addressed messages. will be invalid if it failed to add
	 */
	Dropbox RegisterAddress(const std::string& localAddress, ReceiveCallback&& receive);

	/**
	 * Removes a mailbox from the post office
	 *
	 * @param localAddress the string address that identifies the mailbox to be removed
	 * @return true if the mailbox was removed
	 */
	bool RemoveMailbox(const std::string& localAddress);

	/**
	 * Callback for when a message is delivered to a mailbox, called before the delivery happens
	 *
	 * @param localAddress the local address the message will be delivered to
	 * @param message the message that is being sent
	 */
	virtual void OnDeliver(const std::string& localAddress, PipeMessagePtr& message) {}

	/**
	 * Delivers a message to a local mailbox
	 *
	 * @param localAddress the local address to deliver the message to
	 * @param message the message to send
	 * @param failed a callback for failure (since message is moved)
	 * @return true if routing was successful
	 */
	bool DeliverTo(const std::string& localAddress, PipeMessagePtr&& message, const std::function<void(int, PipeMessagePtr&&)>& failed = [](int, const auto&) {});

	/**
	 * Delivers a message to all local mailboxes, optionally excluding self
	 *
	 * @param message the message to send -- only the message ID and the payload is used (the header is rebuilt per message)
	 * @param fromAddress the address to exclude from the delivery
	 */
	void DeliverAll(PipeMessagePtr& message, std::optional<std::string_view> fromAddress = {});

	/**
	 * Processes messages waiting in the queue
	 *
	 * @param howMany how many messages to process (up to)
	 */
	void Process(size_t howMany);

protected:
	std::unordered_map<std::string, std::unique_ptr<Mailbox>> m_mailboxes;
};

/**
 * Returns this application's post office singleton
 *
 * @return the single post office that is used in this application
 */
PostOffice& GetPostOffice();

} // namespace mq::postoffice
