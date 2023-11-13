/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2023 MacroQuest Authors
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

namespace mq {

class ProtoMessage;
using ProtoMessagePtr = std::unique_ptr<ProtoMessage>;

namespace postoffice {
	class Dropbox;

	/**
	 * An address shim to be used to fill out the address on the envelope in the MQ post office.
	 */
	struct Address
	{
		/** The PID of the target. If this is specified, all other addressing will be ignored. */
		std::optional<uint32_t> PID;

		/** The name of the target, used for addressing external applications. */
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
	struct Message
	{
		// the original message is used internally for setting sequence ID on reply.
		// this won't be usable by plugins unless they link against routing
		ProtoMessagePtr Original;

		/** The address of the sender of the message in case message handling requires this */
		std::optional<Address> Sender;

		/** The data of the message to be parsed by the message handler */
		std::optional<std::string> Payload;
	};

	using ReceiveCallbackAPI = std::function<void(Message&&)>;

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
		 * @tparam ID an identifier to be used by the receiver, must cast to uint32_t
		 * @tparam T the message being sent, usually some kind of proto
		 *
		 * @param address the address to send the message
		 * @param messageId a message ID used to route the message at the receiver
		 * @param obj the message (as an object)
		 */
		template <typename ID, typename T>
		void Post(const Address& address, ID messageId, const T& obj)
		{
			Post(address, static_cast<uint16_t>(messageId), obj.SerializeAsString());
		}

		/**
		 * Sends a message to an address
		 *
		 * @tparam ID an identifier to be used by the receiver, must cast to uint32_t
		 *
		 * @param address the address to send the message
		 * @param messageId a message ID used to route the message at the receiver
		 * @param data the message (as a data string)
		 */
		template <typename ID>
		void Post(const Address& address, ID messageId, const std::string& data)
		{
			Post(address, static_cast<uint16_t>(messageId), data);
		}


		/**
		 * Sends a message to an address
		 *
		 * @param address the address to send the message
		 * @param messageId a message ID used to route the message at the receiver
		 * @param data the message (as a data string)
		 */
		void Post(const Address& address, uint16_t messageId, const std::string& data);

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
		void PostReply(Message&& message, ID messageId, const T& obj, uint8_t status = 0)
		{
			PostReply(std::move(message), static_cast<uint16_t>(messageId), obj.SerializeAsString(), status);
		}

		/**
		 * Sends a reply to the sender of a message
		 *
		 * @tparam ID an identifier to be used by the receiver, must cast to uint32_t
		 *
		 * @param message the original message to reply to (contains the sender address)
		 * @param messageId a message ID used to rout the message at the receiver
		 * @param obj the message (as a data string)
		 * @param status a return status, sometimes used by reply handling logic
		 */
		template <typename ID>
		void PostReply(Message&& message, ID messageId, const std::string& data, uint8_t status = 0)
		{
			PostReply(std::move(message), static_cast<uint16_t>(messageId), data, status);
		}

		/**
		 * Sends a reply to the sender of a message
		 *
		 * @param message the original message to reply to (contains the sender address)
		 * @param messageId a message ID used to rout the message at the receiver
		 * @param obj the message (as a data string)
		 * @param status a return status, sometimes used by reply handling logic
		 */
		void PostReply(Message&& message, uint16_t messageId, const std::string& data, uint8_t status = 0);

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

} // namespace postoffice

} // namespace mq
