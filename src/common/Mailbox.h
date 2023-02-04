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

#include <string>
#include <unordered_map>
#include <queue>
#include <memory>

namespace mq {
namespace mailbox {

// a post office can only handle a single type of input message (like, a PipeMessage)
// but it can output any type that the mailboxes need
template <typename RawMessage>
class PostOffice
{
public:
	template <typename ParsedMessage>
	using ParseCallback = ParsedMessage(*)(const RawMessage&);

	template <typename ParsedMessage>
	using ReceiveCallback = void(*)(const ParsedMessage&);

public:
	class MailboxConcept
	{
	public:
		virtual void Push(const RawMessage& message) const = 0;
		virtual void Process(size_t howMany) const = 0;
		virtual const std::string& Address() const = 0;
	};

private:
	template <typename ParsedMessage>
	class Mailbox : public MailboxConcept
	{
	public:
		Mailbox(std::string_view localAddress, ParseCallback<ParsedMessage> parse, ReceiveCallback<ParsedMessage> receive)
			: m_localAddress(localAddress)
			, m_parse(parse)
			, m_receive(receive)
		{
		}

		// This function is called from an external source to deliver a raw message
		// to this mailbox. The function will verify that `data` is a message in a
		// format understood by the mailbox and then put it on the queue to be 
		// handled by Receive. This method could potentially also Forward to other
		// mailboxes during preprocessing, instead of adding to the receive queue.
		void Push(const RawMessage& message) const override
		{
			m_receiveQueue.push(m_parse(message));
		}

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
		void Receive(const ParsedMessage& message) const { m_receive(message); }

	private:
		const std::string m_localAddress;
		mutable std::queue<ParsedMessage> m_receiveQueue;
		const ParseCallback<ParsedMessage> m_parse;
		const ReceiveCallback<ParsedMessage> m_receive;

	};

public:
	template <typename ParsedMessage>
	static std::unique_ptr<MailboxConcept> CreateMailbox(
		const std::string& localAddress,
		ParseCallback<ParsedMessage> parse,
		ReceiveCallback<ParsedMessage> receive)
	{
		return std::make_unique<Mailbox<ParsedMessage>>(localAddress, parse, receive);
	}

	bool AddMailbox(const std::string& localAddress, std::unique_ptr<MailboxConcept>&& mailbox)
	{
		auto [_, added] = m_mailboxes.emplace(mailbox->Address(), std::move(mailbox));
		return added;
	}

	bool RemoveMailbox(const std::string& localAddress)
	{
		return m_mailboxes.erase(localAddress) == 1;
	}

	bool DeliverTo(const std::string& localAddress, const RawMessage& message)
	{
		auto mailbox_it = m_mailboxes.find(localAddress);
		if (mailbox_it != m_mailboxes.end())
			mailbox_it->second->Push(message);

		return mailbox_it != m_mailboxes.end();
	}

	void Process(size_t howMany)
	{
		size_t messages_per_mailbox = std::max(1, (int)std::round(howMany / m_mailboxes.size()));
		for (const auto& [_, mailbox] : m_mailboxes)
		{
			mailbox->Process(messages_per_mailbox);
		}
	}

private:
	std::unordered_map<std::string, std::unique_ptr<MailboxConcept>> m_mailboxes;
};

} // namespace mailbox

} // namespace mq
