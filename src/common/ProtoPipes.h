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

class ProtoMessage : public PipeMessage
{
public:
	using PipeMessage::PipeMessage;
	
	template <typename T>
	T Parse()
	{
		T obj;
		return Parse(shared_from_this(), obj);
	}

	template <typename T>
	T& Parse(T& obj)
	{
		return Parse(shared_from_this(), obj);
	}

	template <typename T>
	static T Parse(PipeMessagePtr message)
	{
		T obj;
		return Parse(message, obj);
	}

	template <typename T>
	static T& Parse(PipeMessagePtr message, T& obj)
	{
		obj.ParseFromArray(message->get<void>(), static_cast<int>(message->size()));
		return obj;
	}

	template <typename T>
	void SendProtoReply(MQMessageId messageId, const T& obj, uint8_t status = 0)
	{
		SendProtoReply(shared_from_this(), messageId, obj, status);
	}

	template <typename T>
	static void SendProtoReply(PipeMessagePtr message, MQMessageId messageId, const T& obj, uint8_t status = 0)
	{
		std::string data = obj.SerializeAsString();
		message->SendReply(messageId, &data[0], data.size(), status);
	}

	const std::optional<proto::Address>& GetReturn() { return m_returnAddress; }
	void SetReturn(const proto::Address& address) { m_returnAddress = address; }

private:
	std::optional<proto::Address> m_returnAddress;
};
using ProtoMessagePtr = std::shared_ptr<ProtoMessage>;

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
