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

#include "NamedPipes.h"
#include "Routing.pb.h"

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
		Parse(obj);
		return obj;
	}

	template <typename T>
	T& Parse(T& obj)
	{
		obj.ParseFromArray(get(), static_cast<int>(size()));
		return obj;
	}

	template <typename T>
	static T Parse(const PipeMessagePtr& message)
	{
		T obj;
		Parse(message, obj);
		return obj;
	}

	template <typename T>
	static T& Parse(const PipeMessagePtr& message, T& obj)
	{
		obj.ParseFromArray(message->get<void>(), static_cast<int>(message->size()));
		return obj;
	}

	const std::optional<proto::routing::Address>& GetSender() { return m_returnAddress; }
	void SetSender(const proto::routing::Address& address) { m_returnAddress = address; }

private:
	std::optional<proto::routing::Address> m_returnAddress;
};
using ProtoMessagePtr = std::unique_ptr<ProtoMessage>;

class ProtoPipeServer : public NamedPipeServer
{
public:
	using NamedPipeServer::NamedPipeServer;

	template <typename ID, typename T>
	void SendProtoMessage(int connectionId, ID messageId, const T& obj)
	{
		std::string data = obj.SerializeAsString();
		SendMessage(connectionId, static_cast<MQMessageId>(messageId), &data[0], data.size());
	}

	template <typename ID, typename T>
	void BroadcastProtoMessage(ID messageId, const T& obj)
	{
		std::string data = obj.SerializeAsString();
		BroadcastMessage(static_cast<MQMessageId>(messageId), &data[0], data.size());
	}
};

class ProtoPipeClient : public NamedPipeClient
{
public:
	using NamedPipeClient::NamedPipeClient;

	template <typename ID, typename T>
	void SendProtoMessage(ID messageId, const T& obj)
	{
		std::string data = obj.SerializeAsString();
		SendMessage(static_cast<MQMessageId>(messageId), &data[0], data.size());
	}

	template <typename ID, typename T>
	void SendProtoMessageWithResponse(ID messageId, const T& obj,
		const PipeMessageResponseCb& response)
	{
		std::string data = obj.SerializeAsString();
		SendMessageWithResponse(static_cast<MQMessageId>(messageId), &data[0], data.size(), response);
	}
};

} // namespace mq
