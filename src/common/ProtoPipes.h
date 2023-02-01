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

#include <memory>

namespace mq {

class ProtoPipeMessage
{
public:
	ProtoPipeMessage(std::shared_ptr<PipeMessage> message) : m_message(message) {}

	template <typename T>
	T Parse()
	{
		T obj;
		obj.ParseFromArray(m_message->get<void>(), (int)m_message->size());
		return obj;
	}

	template <typename T>
	void SendProtoReply(MQMessageId messageId, const T& obj, uint8_t status = 0)
	{
		size_t size = obj.ByteSizeLong();
		std::unique_ptr<uint8_t[]> data(new uint8_t[size]);
		obj.SerializeToArray(&data[0], static_cast<int>(size));

		m_message->SendReply(messageId, &data[0], size, status);
	}

private:
	std::shared_ptr<PipeMessage> m_message;
};

class ProtoPipeServer : public NamedPipeServer
{
public:
	ProtoPipeServer(const char* pipeName) : NamedPipeServer(pipeName) {}

	template <typename T>
	void SendProtoMessage(int connectionId, MQMessageId messageId, const T& obj)
	{
		size_t size = obj.ByteSizeLong();
		std::unique_ptr<uint8_t[]> data(new uint8_t[size]);
		obj.SerializeToArray(&data[0], static_cast<int>(size));

		SendMessage(connectionId, messageId, &data[0], size);
	}

	template <typename T>
	void BroadcastProtoMessage(MQMessageId messageId, const T& obj)
	{
		size_t size = obj.ByteSizeLong();
		std::unique_ptr<uint8_t[]> data(new uint8_t[size]);
		obj.SerializeToArray(&data[0], static_cast<int>(size));

		BroadcastMessage(messageId, &data[0], size);
	}
};

class ProtoPipeClient : public NamedPipeClient
{
public:
	ProtoPipeClient(const char* pipeName) : NamedPipeClient(pipeName) {}

	template <typename T>
	void SendProtoMessage(MQMessageId messageId, const T& obj)
	{
		size_t size = obj.ByteSizeLong();
		std::unique_ptr<uint8_t[]> data(new uint8_t[size]);
		obj.SerializeToArray(&data[0], static_cast<int>(size));

		SendMessage(messageId, &data[0], size);
	}

	template <typename T>
	void SendProtoMessageWithResponse(MQMessageId messageId, const T& obj,
		const PipeMessageResponseCb& response)
	{
		size_t size = obj.ByteSizeLong();
		std::unique_ptr<uint8_t[]> data(new uint8_t[size]);
		obj.SerializeToArray(&data[0], static_cast<int>(size));

		SendMessageWithResponse(messageId, &data[0], size, response);
	}
};

} // namespace mq
