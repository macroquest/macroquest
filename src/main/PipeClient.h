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

#include "MQ2MainBase.h"

namespace mq {

void InitializePipeClient();
void ShutdownPipeClient();

namespace pipeclient {

MQLIB_API void NotifyCharacterLoad(const char* Profile, const char* Account, const char* Server, const char* Character);
MQLIB_API void NotifyCharacterUnload(const char* Profile, const char* Account, const char* Server, const char* Character);
MQLIB_API void NotifyCharacterUpdate(int Class, int Level);
MQLIB_API void LoginServer(const char* Login, const char* Pass, const char* Server);
MQLIB_API void LoginCharacter(const char* Login, const char* Pass, const char* Server, const char* Character);
MQLIB_API void LoginProfile(const char* Profile, const char* Server, const char* Character);

MQLIB_API uint32_t GetLauncherProcessID();

void NotifyIsForegroundWindow(bool isForeground);
void RequestActivateWindow(HWND hWnd, bool sendMessage = true);

} // namespace pipeclient

namespace mailbox {

class PostOffice
{
public:
	using DeliverCallback = void(*)(const void*, size_t);

	template <typename MessageType>
	using ReceiveCallback = void(*)(const MessageType&);

public:
	class MailboxConcept
	{
	public:
		virtual void Deliver(const void* data, size_t length) const = 0;
		virtual void Process(size_t howMany) const = 0;
		virtual const std::string& Address() const = 0;
	};

private:
	template <typename MessageType>
	class Mailbox : public MailboxConcept
	{
	public:
		Mailbox(std::string_view localAddress, DeliverCallback deliver, ReceiveCallback<MessageType> receive)
			: m_localAddress(localAddress)
			, m_deliver(deliver)
			, m_receive(receive)
		{
		}

		// This function is called from an external source to deliver a raw message
		// to this mailbox. The function will verify that `data` is a message in a
		// format understood by the mailbox and then put it on the queue to be 
		// handled by Receive. This method could potentially also Forward to other
		// mailboxes during preprocessing, instead of adding to the receive queue.
		void Deliver(const void* data, size_t length) const override { m_deliver(data, length); }

		// This function is called by whatever process does the determination of how
		// much message processing to do. The intention is that since we don't need
		// to create threads to do this, we can have a single processor act on a
		// single thread dynamically determine throttling per actor.
		void Process(size_t howMany) const override
		{
			if (howMany <= 0 || m_receiveQueue.empty())
				return;

			Receive(m_receiveQueue.front());
			m_receiveQueue.pop();

			Process(howMany - 1);
		}

		const std::string& Address() const override { return m_localAddress; }

	private:

		// Individual message handling will be defined by the owner of the mailbox
		// by overriding this, Deliver will have transformed raw data into the correct
		// message format.
		void Receive(const MessageType& message) const { m_receive(message); }

	private:
		const std::string m_localAddress;
		mutable std::queue<MessageType> m_receiveQueue;
		const DeliverCallback m_deliver;
		const ReceiveCallback<MessageType> m_receive;

	};

public:
	template <typename MessageType>
	static bool AddMailbox(const std::string& localAddress, DeliverCallback deliver, ReceiveCallback<MessageType> receive)
	{
		bool can_add = CanAddMailbox(localAddress);
		if (can_add)
			AddMailboxConcept(std::make_unique<Mailbox<MessageType>>(localAddress, deliver, receive));

		return can_add;
	}

	MQLIB_OBJECT static bool RemoveMailbox(const std::string& localAddress);
	MQLIB_OBJECT static bool DeliverTo(const std::string& localAddress, const void* data, size_t length);
	MQLIB_OBJECT static void Process(size_t howMany);

private:
	MQLIB_OBJECT static bool CanAddMailbox(const std::string& localAddress);
	MQLIB_OBJECT static void AddMailboxConcept(std::unique_ptr<MailboxConcept>&& mailbox);

};

} // namespace mailbox

} // namespace mq
