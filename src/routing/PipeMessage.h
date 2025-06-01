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

#include "routing/NamedPipesProtocol.h"

#include <memory>
#include <vector>

namespace mq {

	class PipeConnection;

//============================================================================
// message sent to/from the named pipe server

// Note: If we want to be able to send a message to multiple clients, we need
// to separate the header from the message, since different clients are going
// to have different headers (maybe..?)

class PipeMessage
{
	friend class PipeConnection;

public:
	PipeMessage() = default;
	PipeMessage(MQMessageId messageId, const void* data, size_t length);
	PipeMessage(const MQMessageHeader& header, const void* data, size_t length);
	PipeMessage(const PipeMessage& message, const void* data, size_t length);

	virtual ~PipeMessage();

	// parse an existing message buffer into a message. Returns false if this is not a
	// properly formatted message.
	bool Parse(std::unique_ptr<uint8_t[]> buffer, size_t length);
	bool Parse(const std::vector<std::pair<std::unique_ptr<uint8_t[]>, size_t>>& buffers);

	void Init(const void* data, size_t length);
	void Init(MQMessageId messageId, const void* data, size_t length);
	void Init(const MQMessageHeader& header, const void* data, size_t length);

	bool IsValid() const { return m_valid; }

	MQMessageHeader* GetHeader() { return m_header; }
	const MQMessageHeader* GetHeader() const { return m_header; }
	MQMessageId GetMessageId() const
	{
		if (!m_header)
			return MQMessageId::MSG_NULL;

		return m_header->messageId;
	}

	MQRequestMode GetRequestMode() const
	{
		if (!m_header)
			return MQRequestMode::SimpleMessage;

		return m_header->mode;
	}

	bool SetRequestMode(MQRequestMode mode)
	{
		if (!m_header)
			return false;

		m_header->mode = mode;
		return true;
	}

	template <typename T = void>
	const T* get() const { return reinterpret_cast<T*>(m_buffer.get() + m_dataOffset); }

	size_t size() const { return m_header ? m_header->messageLength : 0; }

	uint32_t GetSequenceId() const { return m_header ? m_header->sequenceId : 0; }
	void SetSequenceId(uint32_t sequenceId) { if (m_header) m_header->sequenceId = sequenceId; }

	int GetConnectionId() const;

	// A simple helper to acknowledge a call-and-response message.
	void SendReply(uint8_t status = 0);

	// A more thorough message reply
	void SendReply(MQMessageId messageId, void* data, size_t length, uint8_t status = 0);

private:
	void SetConnection(std::shared_ptr<PipeConnection> connection) { m_connection = connection; }

	const uint8_t* buffer() const { return m_buffer.get(); }
	size_t buffer_size() const { return m_bufferLength; }

private:
	std::unique_ptr<uint8_t[]> m_buffer;
	size_t m_bufferLength = 0;
	MQMessageHeader* m_header = nullptr;
	size_t m_dataOffset = 0;
	bool m_valid = false;
	bool m_replied = false;

	std::weak_ptr<PipeConnection> m_connection;
};
using PipeMessagePtr = std::unique_ptr<PipeMessage>;

} // namespace mq
