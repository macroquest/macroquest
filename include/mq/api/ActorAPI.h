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

#pragma once

#include <memory>
#include <optional>
#include <string>

namespace mq {

namespace proto::routing {
	class Envelope;
} // namespace proto::routing

namespace postoffice {

class Dropbox;

/**
 * Status codes for routing reply
 */
enum class ResponseStatus : int8_t
{
	ConnectionClosed        = -1,                  // connection was closed
	NoConnection            = -2,                  // no connection established
	RoutingFailed           = -3,                  // message routing failed
	AmbiguousRecipient      = -4,                  // RPC message couldn't determine single recipient
};


/**
 * A network peer addressing struct for use in messages that get sent over the network
 */
struct Peer
{
	/** The IP of the peer, this must be specified if a peer is specified */
	std::string IP;

	/** The port of the peer, if excluded then it will use the default actor port in the launcher */
	std::optional<uint16_t> Port;
};

/**
 * An address shim to be used to fill out the address on the envelope in the MQ post office.
 */
struct Address
{
	/** The UUID of the target, an absolute address location */
	std::optional<std::string> UUID;

	/** The PID of the target */
	std::optional<uint32_t> PID;

	/** The network peer of the target */
	std::optional<Peer> Peer;

	/** The name of the target, used for addressing external applications */
	std::optional<std::string> Name;

	/** The mailbox of the target, if this is fully qualified then make sure to set AbsoluteMailbox */
	std::optional<std::string> Mailbox;

	/** The account of the target post office */
	std::optional<std::string> Account;

	/** The server of the target post office */
	std::optional<std::string> Server;

	/** The character of the target post office */
	std::optional<std::string> Character;

	/** Used to specify if the mailbox is fully qualified (default to false) */
	bool AbsoluteMailbox = false;
};

/**
 * A message shim used to store the original message while allowing parsing without needing the routing library.
 */
class Message
{
public:
	// the original message is used internally for setting sequence ID on reply.
	// this won't be usable by plugins unless they link against routing
	proto::routing::Envelope* Original;

	/** The address of the sender of the message in case message handling requires this */
	std::optional<Address> Sender;

	/** The data of the message to be parsed by the message handler */
	std::optional<std::string> Payload;
};

using ReceiveCallbackAPI = std::function<void(const std::shared_ptr<Message>&)>;
using ResponseCallbackAPI = std::function<void(int, const std::shared_ptr<Message>&)>;

/**
 * A dropbox shim used to store a reference to the actual dropbox and provide functions to interact with it
 */
struct DropboxAPI
{
	// the actual dropbox is used internally for routing
	// this won't be usable by plugins unless they link against routing
	Dropbox* Dropbox;

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
	void Post(const Address& address, const T& obj, const ResponseCallbackAPI& callback = nullptr) const
	{
		Post(address, obj.SerializeAsString(), callback);
	}

	/**
	 * Sends a message to an address
	 *
	 * @param address the address to send the message
	 * @param data the message (as a data string)
	 * @param callback optional callback for an expected response
	 */
	void Post(const Address& address, const std::string& data, const ResponseCallbackAPI& callback = nullptr) const;

	/**
	 * Sends a reply to the sender of a message
	 *
	 * @tparam T the message being sent, usually some kind of proto
	 *
	 * @param message the original message to reply to (contains the sender address)
	 * @param obj the message (as an object)
	 * @param status a return status, sometimes used by reply handling logic
	 */
	template <typename T>
	void PostReply(const std::shared_ptr<Message>& message, const T& obj, uint8_t status = 0) const
	{
		PostReply(message, obj.SerializeAsString(), status);
	}

	/**
	 * Sends a reply to the sender of a message
	 *
	 * @param message the original message to reply to (contains the sender address)
	 * @param data the message (as a data string)
	 * @param status a return status, sometimes used by reply handling logic
	 */
	void PostReply(const std::shared_ptr<Message>& message, const std::string& data, uint8_t status = 0) const;

	/**
	 * Removes the mailbox with the same name from the post office
	 */
	void Remove();
};

/**
 * Creates and registers a mailbox with the post office
 *
 * @param receive a callback rvalue that will process messages as they are received in this mailbox
 * @return an dropbox that the creator can use to send addressed messages. will be invalid if it failed to add
 */
DropboxAPI AddActor(ReceiveCallbackAPI&& receive);

/**
 * Creates and registers a mailbox with the post office
 *
 * @param localAddress the string address to create the address at
 * @param receive a callback rvalue that will process messages as they are received in this mailbox
 * @return an dropbox that the creator can use to send addressed messages. will be invalid if it failed to add
 */
DropboxAPI AddActor(const char* localAddress, ReceiveCallbackAPI&& receive);

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
void SendToActor(const Address& address, const T& obj, const ResponseCallbackAPI& callback = nullptr)
{
	SendToActor(address, obj.SerializeAsString(), callback);
}

/**
 * Sends a message to an address
 *
 * @param address the address to send the message
 * @param data the message (as a data string)
 * @param callback optional callback for an expected response
 */
void SendToActor(const Address& address, const std::string& data, const ResponseCallbackAPI& callback = nullptr);

} // namespace postoffice

} // namespace mq
