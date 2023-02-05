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

#include "NamedPipes.h"
#include "common/proto/Shared.pb.h"

#include <memory>
#include <optional>

namespace mq {

class ProtoPipeMessage
{
public:
	ProtoPipeMessage(std::shared_ptr<PipeMessage> message) : m_message(message) {}
	
	template <typename T>
	T Parse()
	{
		T obj;
		obj.ParseFromArray(m_message->get<void>(), static_cast<int>(m_message->size()));
		return obj;
	}

	template <typename T>
	T& Parse(T& obj)
	{
		obj.ParseFromArray(m_message->get<void>(), static_cast<int>(m_message->size()));
		return obj;
	}

	template <typename T>
	void SendProtoReply(MQMessageId messageId, const T& obj, uint8_t status = 0)
	{
		std::string data = obj.SerializeAsString();
		m_message->SendReply(messageId, &data[0], data.size(), status);
	}

private:
	std::shared_ptr<PipeMessage> m_message;
};

class PipePacker
{
public:
	PipePacker(std::string_view homeMailbox)
		: m_mailbox(homeMailbox)
	{}

	template <typename T>
	std::string Envelope(const proto::Address& address, const std::string& mailbox, MQMessageId messageId, const T& obj)
	{
		return Envelope(address, mailbox, messageId, obj.SerializeAsString());
	}

	template <>
	std::string Envelope(const proto::Address& address, const std::string& mailbox, MQMessageId messageId, const std::string& data)
	{
		proto::Envelope envelope;
		*envelope.mutable_address() = address;

		envelope.set_message_id(static_cast<uint32_t>(messageId));

		proto::Address& ret = *envelope.mutable_return_address();
		ret.set_pid(GetCurrentProcessId());
		ret.set_mailbox(m_mailbox);

		envelope.set_payload(data);

		return envelope.SerializeAsString();
	}

private:
	std::string m_mailbox;
};

class ProtoPipeServer : public NamedPipeServer
{
public:
	using NamedPipeServer::NamedPipeServer;

	template <typename T>
	void SendProtoMessage(int connectionId, MQMessageId messageId, const T& obj)
	{
		std::string data = obj.SerializeAsString();
		SendMessage(connectionId, messageId, &data[0], data.size());
	}

	template <typename T>
	void BroadcastProtoMessage(MQMessageId messageId, const T& obj)
	{
		std::string data = obj.SerializeAsString();
		BroadcastMessage(messageId, &data[0], data.size());
	}
};

class ProtoPipeClient : public NamedPipeClient
{
public:
	using NamedPipeClient::NamedPipeClient;

	template <typename T>
	void SendProtoMessage(MQMessageId messageId, const T& obj)
	{
		std::string data = obj.SerializeAsString();
		SendMessage(messageId, &data[0], data.size());
	}

	template <typename T>
	void SendProtoMessageWithResponse(MQMessageId messageId, const T& obj,
		const PipeMessageResponseCb& response)
	{
		std::string data = obj.SerializeAsString();
		SendMessageWithResponse(messageId, &data[0], data.size(), response);
	}
};

} // namespace mq
