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

#include "NamedPipesProtocol.h"

#include <wil/resource.h>
#include <atomic>
#include <deque>
#include <functional>
#include <memory>
#include <mutex>
#include <thread>
#include <vector>

#include <windows.h>

#if defined(DispatchMessage)
#undef DispatchMessage
#endif
#if defined(SendMessage)
#undef SendMessage
#endif

namespace mq {

class NamedPipeEndpointBase;
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

using PipeMessageResponseCb = std::function<void(int status, PipeMessagePtr&& message)>;

// Create a v0 simple message
PipeMessagePtr MakeSimpleMessageV0(MQMessageId messageId, const void* data, size_t dataLength);

// Create a v0 rpc message
PipeMessagePtr MakeCallResponseMessageV0(MQMessageId messageId, const void* data, size_t dataLength);

// Create a v0 rpc response
PipeMessagePtr MakeCallResponseReplyV0(MQMessageId messageId, const void* data, size_t dataLength,
	uint32_t sequenceId, uint8_t status = 0);

//============================================================================
// Represents an established connetion to a named pipe.
class PipeConnection
	: public std::enable_shared_from_this<PipeConnection>
{
	friend class NamedPipeEndpointBase;
	friend class NamedPipeServer;
	friend class NamedPipeClient;

	static int s_nextConnectionId;

public:
	PipeConnection(NamedPipeEndpointBase* parent, wil::unique_hfile hPipe);
	~PipeConnection();

	uint32_t GetProcessId() const { return m_processId; }
	int GetConnectionId() const { return m_connectionId; }
	OVERLAPPED* GetOverlapped() { return &m_overlapped; }
	const OVERLAPPED* GetOverlapped() const { return &m_overlapped; }

	void StartRead() { InternalBeginRead(); }
	HANDLE GetNamedPipe() { return m_hPipe.get(); }
	bool IsNamedPipeOpen() const { return m_hPipe.is_valid(); }

	//----------------------------------------------------------------------------
	// Send message variants

	// Send a simple message
	void SendMessage(MQMessageId messageId, const void* data, size_t dataLength);
	void SendMessage(PipeMessagePtr message);

	// Send a call-and-response message to the server
	void SendMessageWithResponse(MQMessageId messageId, const void* data, size_t dataLength,
		const PipeMessageResponseCb& response);
	void SendMessageWithResponse(PipeMessagePtr message,
		const PipeMessageResponseCb& response);

	void Close();
private:
	// Queued outgoing writes
	struct QueuedOp
	{
		OVERLAPPED overlapped;
		std::shared_ptr<PipeConnection> ref;
		std::unique_ptr<PipeMessage> message;
	};

	// After a read is completed, start a write.
	void HandleWriteComplete(QueuedOp* op, uint32_t dwErrorCode, uint32_t dwNumBytes);

	// After a write is completed, start a read.
	void HandleReadComplete(uint32_t dwErrorCode, uint32_t dwNumBytes);

	// This sends the message to the named pipe. It expects to be called from the named pipe thread.
	void InternalSendMessage(PipeMessagePtr message,
		const PipeMessageResponseCb& response = nullptr);

	void InternalReceiveMessage(PipeMessagePtr message);

	void InternalBeginRead();
	void ProcessBuffers();
	void InternalBeginSend();

	bool InternalClose(bool disconnect);

private:
	wil::unique_hfile m_hPipe;
	NamedPipeEndpointBase* m_parent = nullptr;
	uint32_t m_processId = 0;
	bool m_pending = false;
	int m_connectionId = -1;
	uint32_t m_nextSequenceId = 1;
	bool m_connected = false;

	// data used for reading
	OVERLAPPED m_overlapped;              // used for reading only
	std::unique_ptr<uint8_t[]> m_readBuffer;
	std::vector<std::pair<std::unique_ptr<uint8_t[]>, size_t>> m_readBuffers;
	size_t m_readBufferSize = 0;
	std::shared_ptr<PipeConnection> m_self;

	// data used for writing
	std::deque<std::unique_ptr<QueuedOp>> m_writeQueue;
	bool m_pendingWrite = false;

	// mapping of sequence id to callbacks
	std::unordered_map<uint32_t, RpcRequest<PipeMessageResponseCb>> m_rpcRequests;
};
using PipeConnectionPtr = std::shared_ptr<PipeConnection>;

class NamedPipeEvents
{
public:
	virtual ~NamedPipeEvents() {}

	// (required) Handle an incoming message
	virtual void OnIncomingMessage(PipeMessagePtr message) = 0;

	// (optional) Handle a request to process events immediately. Called from the
	// named pipe thread.
	virtual void OnRequestProcessEvents() {}

	// (optional) For NamedPipeServer: notification of an incoming connection.
	virtual void OnIncomingConnection(int connectionId, int processId) {}

	// (optional) For NamedPipeServer: notification of a closing connection
	virtual void OnConnectionClosed(int connectionId, int processId) {}

	// (optional) For NamedPipeClient: Called when connection is established
	virtual void OnClientConnected() {}
};

//============================================================================

class NamedPipeEndpointBase
{
	friend class PipeConnection;

public:
	NamedPipeEndpointBase(std::string threadName, std::string pipeName);
	virtual ~NamedPipeEndpointBase();

	inline bool IsRunning() const { return m_running; }
	void SetHandler(std::shared_ptr<NamedPipeEvents> handler) { m_handler = handler; };

	virtual void Process();
	virtual void Start();
	virtual void Stop();

	// Handle sending work to the main thread
	virtual void PostToMainThread(std::function<void()>&& callback);

	// Handle sending work to the named pipe thread
	virtual void PostToPipeThread(std::function<void()>&& callback);

	// dispatches a message to be handled by the client.
	void DispatchMessage(PipeMessagePtr message);

protected:
	virtual void NamedPipeThread() = 0;
	virtual void CloseConnection(PipeConnection* connection) = 0;

	void ProcessMainThreadQueue();
	void ProcessPipeThreadQueue();

	std::thread::id pipe_thread_id() const { return m_pipeThreadId; }
	std::thread::id main_thread_id() const { return m_mainThreadId; }

protected:
	std::string m_pipeName;
	wil::unique_event m_interruptEvent;
	std::shared_ptr<NamedPipeEvents> m_handler;

private:
	std::string m_threadName;
	std::thread m_thread;
	std::thread::id m_mainThreadId;
	std::thread::id m_pipeThreadId;
	std::atomic_bool m_running{ false };

	// for passing events to the pipe thread
	std::vector<std::function<void()>> m_threadQueue;
	std::mutex m_threadQueueMutex;
	std::atomic_bool m_threadQueueDirty{ false };

	// for passing events to the main thread
	std::vector<std::function<void()>> m_mainQueue;
	std::mutex m_mainQueueMutex;
	std::atomic_bool m_mainQueueDirty{ false };
};

//============================================================================

class NamedPipeServer : public NamedPipeEndpointBase
{
public:
	friend class PipeConnection;
	friend class PipeMessage;

public:
	NamedPipeServer(const char* pipeName);
	~NamedPipeServer();

	std::shared_ptr<PipeConnection> GetConnection(int connectionId) const;
	std::vector<int> GetConnectionIds() const;

	std::shared_ptr<PipeConnection> GetConnectionForProcessId(uint32_t processId) const;

	virtual void PostToMainThread(std::function<void()>&& callback) override;

	void SendMessage(int connectionId, PipeMessagePtr message);
	void SendMessage(int connectionId, MQMessageId messageId, const void* data, size_t dataLength);

	void BroadcastMessage(const PipeMessagePtr& message);
	void BroadcastMessage(MQMessageId messageId, const void* data, size_t dataLength);

private:
	void NamedPipeThread() override;

	// This function creates a pipe instance and connect to the client. If it returns
	// true, then the connection operation is pending. Otherwise returns false.
	bool CreateAndConnect();

	// clean up a connection
	void CloseConnection(PipeConnection* connection) override;

	int GetConnectionCount() const;

private:
	wil::unique_event m_connectEvent;
	OVERLAPPED m_oConnect;
	wil::unique_hfile m_hPipe;
	std::vector<std::shared_ptr<PipeConnection>> m_connections;
	mutable std::mutex m_mutex;
};

//============================================================================

class NamedPipeClient : public NamedPipeEndpointBase
{
public:
	NamedPipeClient(const char* pipeName);
	~NamedPipeClient();

	// Send a simple message to the server
	void SendMessage(PipeMessagePtr message);
	void SendMessage(MQMessageId messageId, const void* data, size_t dataLength);

	// Send a call-and-response message to the server
	void SendMessageWithResponse(PipeMessagePtr message, const PipeMessageResponseCb& response);
	void SendMessageWithResponse(MQMessageId messageId, const void* data, size_t dataLength,
		const PipeMessageResponseCb& response);

	// Checks if we're connected
	bool IsConnected() const;

	PipeConnectionPtr GetConnection() const { return m_connection; }

private:
	virtual void NamedPipeThread() override;
	virtual void CloseConnection(PipeConnection* connection) override;

private:
	std::shared_ptr<PipeConnection> m_connection;
};

} // namespace mq
