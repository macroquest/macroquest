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

// Uncomment to see super spammy read/write trace logging
//#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE

#include "NamedPipes.h"
#include "common/Common.h"
#include "mq/base/WString.h"

#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <strsafe.h>
#include <time.h>
#include <fmt/os.h>
#include <spdlog/spdlog.h>
#include <spdlog/fmt/bin_to_hex.h>
#include <wil/resource.h>
#include <sddl.h>

using namespace std::chrono_literals;

namespace mq {

constexpr int BUFFER_SIZE = 4096;
constexpr int PIPE_TIMEOUT = 5000;

//============================================================================
// PipeMessage
//============================================================================

PipeMessage::PipeMessage(MQMessageId messageId, const void* data, size_t length)
{
	Init(messageId, data, length);
}

PipeMessage::PipeMessage(const MQMessageHeader& header, const void* data, size_t length)
{
	Init(header, data, length);
}

PipeMessage::PipeMessage(const PipeMessage& message, const void* data, size_t length)
{
	if (message.m_header)
		Init(*message.m_header, data, length);
	else
		Init(message.GetMessageId(), data, length);

	SetConnection(message.m_connection.lock());
}

PipeMessage::~PipeMessage()
{
}

bool PipeMessage::Parse(std::unique_ptr<uint8_t[]> buffer, size_t length)
{
	if (length == 0)
		return false;

	auto version = static_cast<MQProtoVersion>(buffer[0]);

	// only version we support so far
	if (version == MQProtoVersion::V0)
	{
		m_dataOffset = sizeof(MQMessageHeader);
		m_bufferLength = length;

		if (m_dataOffset > length)
			return false;

		length -= m_dataOffset;

		m_header = reinterpret_cast<MQMessageHeader*>(buffer.get());

		// data length should match whats in the header
		if (m_header->messageLength != length)
			return false;

		m_buffer = std::move(buffer);
		m_valid = true;
		return true;
	}

	return false;
}

bool PipeMessage::Parse(const std::vector<std::pair<std::unique_ptr<uint8_t[]>, size_t>>& buffers)
{
	// calculate length
	size_t length = std::accumulate(std::begin(buffers), std::end(buffers),
		static_cast<size_t>(0), [](size_t v, const auto& p) { return v + p.second; });
	if (length == 0)
		return false;

	// allocate buffer and combine buffers into single.
	auto buffer = std::make_unique<uint8_t[]>(length);
	uint8_t* pos = buffer.get();

	for (auto& [buffer, size] : buffers)
	{
		memcpy(pos, buffer.get(), size);
		pos += size;
	}

	return Parse(std::move(buffer), length);
}

void PipeMessage::Init(const void* data, size_t length)
{
	m_dataOffset = sizeof(MQMessageHeader);
	m_bufferLength = length + m_dataOffset;

	// initialize buffer and header
	m_buffer = std::make_unique<uint8_t[]>(m_bufferLength);
	m_header = reinterpret_cast<MQMessageHeader*>(m_buffer.get());

	if (data && length > 0)
	{
		// copy data from buffer
		memcpy(m_buffer.get() + m_dataOffset, data, length);
	}
}

void PipeMessage::Init(MQMessageId messageId, const void* data, size_t length)
{
	Init(data, length);
	memset(m_header, 0, sizeof(MQMessageHeader));

	m_header->messageLength = static_cast<uint32_t>(length);
	m_header->protoVersion = MQProtoVersion::V0;
	m_header->messageId = messageId;
	m_valid = true;
}

void PipeMessage::Init(const MQMessageHeader& header, const void* data, size_t length)
{
	Init(data, length);
	memcpy(m_header, &header, sizeof(MQMessageHeader));

	m_header->messageLength = static_cast<uint32_t>(length);
	m_header->protoVersion = MQProtoVersion::V0;
	m_valid = true;
}

int PipeMessage::GetConnectionId() const
{
	if (auto connection = m_connection.lock())
	{
		return connection->GetConnectionId();
	}

	return 0;
}

void PipeMessage::SendReply(uint8_t status /*=0*/)
{
	if (m_header && m_header->mode == MQRequestMode::CallAndResponse && !m_replied)
	{
		auto message = MakeCallResponseReplyV0(MQMessageId::MSG_NULL, nullptr, 0, m_header->sequenceId, status);
		if (auto connection = m_connection.lock())
		{
			connection->SendMessage(std::move(message));
		}
	}
}

void PipeMessage::SendReply(MQMessageId messageId, void* data, size_t length, uint8_t status)
{
	if (m_header && m_header->mode == MQRequestMode::CallAndResponse && !m_replied)
	{
		auto message = MakeCallResponseReplyV0(messageId, data, length, m_header->sequenceId, status);
		if (auto connection = m_connection.lock())
		{
			connection->SendMessage(std::move(message));
		}
	}
}

//============================================================================

mq::PipeMessagePtr MakeSimpleMessageV0(MQMessageId messageId, const void* data, size_t dataLength)
{
	auto message = std::make_unique<PipeMessage>(messageId, data, dataLength);
	message->GetHeader()->mode = MQRequestMode::SimpleMessage;
	return message;
}

mq::PipeMessagePtr MakeCallResponseMessageV0(MQMessageId messageId, const void* data, size_t dataLength)
{
	auto message = std::make_unique<PipeMessage>(messageId, data, dataLength);
	message->GetHeader()->mode = MQRequestMode::CallAndResponse;
	return message;
}

mq::PipeMessagePtr MakeCallResponseReplyV0(MQMessageId messageId, const void* data, size_t dataLength,
	uint32_t sequenceId, uint8_t status /*= 0*/)
{
	auto message = std::make_unique<PipeMessage>(messageId, data, dataLength);
	message->GetHeader()->mode = MQRequestMode::MessageReply;
	message->GetHeader()->status = status;
	message->GetHeader()->sequenceId = sequenceId;
	return message;
}

//============================================================================
// PipeConnection
//============================================================================

int PipeConnection::s_nextConnectionId = 1;

PipeConnection::PipeConnection(NamedPipeEndpointBase* parent, wil::unique_hfile hPipe)
	: m_hPipe(std::move(hPipe))
	, m_connectionId(s_nextConnectionId++)
	, m_parent(parent)
{
	LPOVERLAPPED pOverlapped = GetOverlapped();
	ZeroMemory(pOverlapped, sizeof(OVERLAPPED));
	pOverlapped->hEvent = reinterpret_cast<HANDLE>(this);

	GetNamedPipeClientProcessId(m_hPipe.get(), (PULONG)&m_processId);

	SPDLOG_DEBUG("Created PipeConnection: connectionId={} pid={}", m_connectionId, m_processId);
}

PipeConnection::~PipeConnection()
{
	Close();

	SPDLOG_DEBUG("Destroyed PipeConnection: connectionId={} pid={}", m_connectionId, m_processId);
}

void PipeConnection::InternalBeginRead()
{
	// this function *must* be called on the named pipe server thread
	assert(std::this_thread::get_id() == m_parent->pipe_thread_id());

	// This keeps the PipeConnection object alive while the ReadFileEx call is waiting.
	m_self = shared_from_this();

	// We can use the hEvent field to store a reference to this connection, that we can
	// use to read the response.
	ZeroMemory(&m_overlapped, sizeof(OVERLAPPED));
	m_overlapped.hEvent = reinterpret_cast<HANDLE>(this);

	if (!m_readBuffer)
	{
		m_readBuffer = std::make_unique<uint8_t[]>(BUFFER_SIZE);
		m_readBufferSize = BUFFER_SIZE;
	}

	// Start the read operation
	bool readStarted = ::ReadFileEx(m_hPipe.get(), m_readBuffer.get(), static_cast<DWORD>(m_readBufferSize), &m_overlapped,
		[](DWORD dwErrorCode, DWORD dwNumberOfBytesTransferred, LPOVERLAPPED lpOverlapped)
	{
		PipeConnection* connection = reinterpret_cast<PipeConnection*>(lpOverlapped->hEvent);

		// extract self from the call. This will allow our connection to safely go out of scope when this
		// callback completes.

		// FIXME: Needs to be stored with request. Two requests = needs to be 2 ref count.
		std::shared_ptr<PipeConnection> self = std::move(connection->m_self);
		self->HandleReadComplete(dwErrorCode, dwNumberOfBytesTransferred);
	});

	if (!readStarted)
	{
		auto error = GetLastError();
		if(error != ERROR_MORE_DATA) {
			SPDLOG_ERROR("{} connectionId={}",
				fmt::windows_error(error, "Failed at ::ReadFileEx").what(), m_connectionId);
			m_parent->CloseConnection(this);
		}
	}
}

void PipeConnection::ProcessBuffers()
{
	// Check if we've got any buffers.
	if (!m_readBuffers.empty())
	{
		size_t size = 0;
		for (const auto& p : m_readBuffers)
			size += p.second;

		auto message = std::make_unique<PipeMessage>();
		if (message->Parse(m_readBuffers))
		{
			InternalReceiveMessage(std::move(message));
		}
		else
		{
			SPDLOG_WARN("PipeConnection::HandleReadComplete: Failed to parse incoming message: connectionId={}",
				m_connectionId);
		}

		// Reclaim a buffer
		m_readBuffer = std::move(m_readBuffers[0].first);
		m_readBufferSize = m_readBuffers[0].second;

		m_readBuffers.clear();
	}
}

void PipeConnection::HandleReadComplete(uint32_t errorCode, uint32_t bytesRead)
{
	// this function *must* be called on the named pipe server thread
	assert(std::this_thread::get_id() == m_parent->pipe_thread_id());

	DWORD dwBytesRead;
	::GetOverlappedResult(m_hPipe.get(), &m_overlapped, &dwBytesRead, FALSE);
	bool moreData = ::GetLastError() == ERROR_MORE_DATA;

	SPDLOG_TRACE("PipeConnection::HandleReadComplete: errorCode={} bytesRead={} moreData={} connectionId={}",
		errorCode, bytesRead, moreData, m_connectionId);

	::SetLastError(ERROR_SUCCESS);

	switch (errorCode)
	{
	case ERROR_BROKEN_PIPE:
		// The pipe was closed. Abandon the request.
		SPDLOG_DEBUG("PipeConnection::HandleReadComplete: pipe closed. connectionId={}", m_connectionId);
		Close();
		return;

	case ERROR_OPERATION_ABORTED:
		// The request has been canceled. Abandon the request.
		SPDLOG_DEBUG("PipeConnection::HandleReadComplete: operation canceled. connectionId={}", m_connectionId);
		Close();
		return;

	case ERROR_INSUFFICIENT_BUFFER:
	case ERROR_SUCCESS:
	case ERROR_MORE_DATA:
		// Store the data in our buffers, and try to read more. If we've got all the
		// data we need we can process it right after the next call to ReadFileEx.
		m_readBuffers.emplace_back(std::move(m_readBuffer), bytesRead);

		if (!moreData && errorCode != ERROR_MORE_DATA)
		{
			ProcessBuffers();
		}

		// Start the next read
		InternalBeginRead();
		break;

	default: // Some other error occurred.
		SPDLOG_ERROR("PipeConnection::HandleReadComplete: Unexpected error. connectionId={} error={}",
			m_connectionId,
			fmt::windows_error(errorCode, "Failed to complete read operation").what());
		m_readBuffers.clear(); // just in case we had some buffers already
		Close();
	}
}

void PipeConnection::SendMessage(MQMessageId messageId, const void* data, size_t dataLength)
{
	SendMessage(MakeSimpleMessageV0(messageId, data, dataLength));
}

void PipeConnection::SendMessage(PipeMessagePtr&& message)
{
	std::weak_ptr<PipeConnection> weakPtr = shared_from_this();

	m_parent->PostToPipeThread([message = message.release(), weakPtr]() mutable
		{
			auto msg = std::unique_ptr<PipeMessage>(message);
			if (auto ptr = weakPtr.lock())
			{
				ptr->InternalSendMessage(std::move(msg));
			}
		});
}

void PipeConnection::SendMessageWithResponse(MQMessageId messageId, const void* data, size_t dataLength,
	const PipeMessageResponseCb& response)
{
	SendMessageWithResponse(MakeCallResponseMessageV0(messageId, data, dataLength), response);
}

void PipeConnection::SendMessageWithResponse(PipeMessagePtr&& message,
	const PipeMessageResponseCb& callback)
{
	std::weak_ptr<PipeConnection> weakPtr = shared_from_this();
	auto parent = m_parent;

	m_parent->PostToPipeThread([message = message.release(), callback, weakPtr, parent]() mutable
		{
			if (auto ptr = weakPtr.lock())
			{
				auto msg = std::unique_ptr<PipeMessage>(message);
				msg->SetRequestMode(MQRequestMode::CallAndResponse);
				ptr->InternalSendMessage(std::move(msg), callback);
			}
			else
			{
				parent->PostToMainThread(
					[callback]() { callback(MsgError_ConnectionClosed, nullptr); });
			}
		});
}

void PipeConnection::Close()
{
	m_parent->CloseConnection(this);
}

void PipeConnection::InternalSendMessage(PipeMessagePtr&& message,
	const PipeMessageResponseCb& callback /* = nullptr */)
{
	// this function *must* be called on the named pipe server thread
	assert(std::this_thread::get_id() == m_parent->pipe_thread_id());

	// If we're not connected anymore, bail out early
	if (!m_hPipe)
	{
		SPDLOG_WARN("Tried to send a message but the pipe was closed. connectionId={}",
			m_connectionId);
		m_parent->CloseConnection(this);

		if (callback)
		{
			m_parent->PostToMainThread(
				[callback]() { callback(MsgError_NoConnection, nullptr); });
		}
		return;
	}

	if (message->GetSequenceId() == 0)
		message->SetSequenceId(m_nextSequenceId++);
	message->SetConnection(shared_from_this());

	if (message->GetHeader()->mode == MQRequestMode::CallAndResponse
		&& callback != nullptr)
	{
		// If we have a callback, create a request object to track the response.
		RpcRequest request;
		request.callback = callback;
		request.sequenceId = message->GetSequenceId();
		request.sendTime = std::chrono::steady_clock::now();
		m_rpcRequests.emplace(request.sequenceId, std::move(request));
	}

	auto queuedOp = std::make_unique<QueuedOp>();
	queuedOp->message = std::move(message);

	m_writeQueue.push_back(std::move(queuedOp));
	InternalBeginSend();
}

void PipeConnection::InternalBeginSend()
{
	// Only allow one write to be processed at a time.
	if (m_pendingWrite)
		return;
	if (m_writeQueue.empty())
		return;

	QueuedOp* op = m_writeQueue[0].get();
	op->ref = shared_from_this();
	ZeroMemory(&op->overlapped, sizeof(OVERLAPPED));
	op->overlapped.hEvent = reinterpret_cast<HANDLE>(op);
	m_pendingWrite = true;

	bool writeStarted = ::WriteFileEx(m_hPipe.get(), op->message->buffer(), static_cast<DWORD>(op->message->buffer_size()), &op->overlapped,
		[](DWORD dwErrorCode, DWORD dwNumberOfBytesTransferred, LPOVERLAPPED lpOverlapped)
	{
		QueuedOp* op = reinterpret_cast<QueuedOp*>(lpOverlapped->hEvent);

		// FIXME: Needs to be stored with request. Two requests = needs to be 2 ref count.
		std::shared_ptr<PipeConnection> self = std::move(op->ref);
		self->HandleWriteComplete(op, dwErrorCode, dwNumberOfBytesTransferred);
	});

	if (!writeStarted)
	{
		SPDLOG_ERROR("{}",
			fmt::windows_error(GetLastError(), "Failed at PipeConnection::InternalBeginSend").what());

		m_parent->CloseConnection(this);
		m_pendingWrite = false;
	}
}

void PipeConnection::HandleWriteComplete(QueuedOp* op, uint32_t dwErrorCode, uint32_t dwNumBytes)
{
	// this function *must* be called on the named pipe server thread
	assert(std::this_thread::get_id() == m_parent->pipe_thread_id());

	// Remove the op from the queue.
	assert(op == m_writeQueue[0].get());

	const auto& reply = op->message;
	size_t bytesWritten = reply->buffer_size();

	// this will delete the op
	m_writeQueue.pop_front();
	m_pendingWrite = false;

	if (dwErrorCode == ERROR_OPERATION_ABORTED)
	{
		SPDLOG_INFO("PipeConnection::HandleWriteComplete: operation canceled");

		m_parent->CloseConnection(this);
		return;
	}

	SPDLOG_TRACE("PipeConnection::HandleWriteComplete: dwErrorCode={} dwNumBytes={} connectionId={}",
		dwErrorCode, dwNumBytes, m_connectionId);

	InternalBeginSend();
}

bool PipeConnection::InternalClose(bool disconnect)
{
	if (!m_hPipe)
		return false;

	SPDLOG_TRACE("PipeConnection::Close: connectionId={} processId={}",
		m_connectionId, m_processId);

	::CancelIoEx(m_hPipe.get(), &m_overlapped);

	for (const auto& [sequenceId, rpcRequest] : m_rpcRequests)
	{
		rpcRequest.callback(MsgError_ConnectionClosed, nullptr);
	}

	if (disconnect)
	{
		if (!::DisconnectNamedPipe(m_hPipe.get()))
		{
			SPDLOG_ERROR("PipeConnection::InternalClose: {}",
				fmt::windows_error(GetLastError(), "Failed at DisconnectNamePipe").what());
		}
	}

	m_rpcRequests.clear();
	m_hPipe.reset();
	return true;
}

void PipeConnection::InternalReceiveMessage(PipeMessagePtr&& message)
{
	message->SetConnection(shared_from_this());

	if (message->GetRequestMode() == MQRequestMode::MessageReply)
	{
		// Check if sequence id is in our map
		auto iter = m_rpcRequests.find(message->GetHeader()->sequenceId);
		if (iter != m_rpcRequests.end())
		{
			// We found a request handler.
			auto callback = iter->second.callback;
			m_rpcRequests.erase(iter);

			m_parent->PostToMainThread([callback, message = message.release()]() mutable
				{
					callback(static_cast<int8_t>(message->GetHeader()->status), std::unique_ptr<PipeMessage>(message));
				});

			return;
		}
	}

	// if we get here with a reply, we didn't have a callback -- so it needs to be routed
	m_parent->DispatchMessage(std::move(message));
}

//============================================================================
// NamedPipeThreadBase
//============================================================================

NamedPipeEndpointBase::NamedPipeEndpointBase(std::string threadName, std::string pipeName)
	: m_threadName(std::move(threadName))
	, m_pipeName(std::move(pipeName))
{
	m_interruptEvent.create();
}

NamedPipeEndpointBase::~NamedPipeEndpointBase()
{
	Stop();
}

void NamedPipeEndpointBase::Process()
{
	ProcessMainThreadQueue();
}

void NamedPipeEndpointBase::Start()
{
	if (m_running)
		return;

	m_mainThreadId = std::this_thread::get_id();
	SPDLOG_INFO("Starting {} thread for {}", m_threadName, m_pipeName);

	m_running = true;
	m_thread = std::thread(
		[this]()
		{
			// SetThreadDescription only available on Windows 10 1607+
			using fSetThreadDescription = HRESULT(WINAPI*)(HANDLE, PCWSTR);
			auto SetThreadDescription = (fSetThreadDescription)GetProcAddress(GetModuleHandle("kernel32.dll"), "SetThreadDescription");
			if (SetThreadDescription)
			{
				SetThreadDescription(GetCurrentThread(), utf8_to_wstring(m_threadName).c_str());
			}

			m_pipeThreadId = std::this_thread::get_id();

			do
			{
				try
				{
					NamedPipeThread();
				}
				catch (const std::exception & error)
				{
					SPDLOG_ERROR("{} thread aborted: {}", error.what());
				}
			} while (m_running);
		}
	);
}

void NamedPipeEndpointBase::Stop()
{
	if (!m_running)
		return;

	SPDLOG_INFO("Stopping {} thread for {}", m_threadName, m_pipeName);

	m_running = false;
	m_interruptEvent.SetEvent();
	m_thread.join();
}

void NamedPipeEndpointBase::DispatchMessage(PipeMessagePtr&& message)
{
	PostToMainThread([message = message.release(), this]() mutable
		{
			auto msg = std::unique_ptr<PipeMessage>(message);
			if (m_handler)
			{
				m_handler->OnIncomingMessage(std::move(msg));
			}
		});
}

static inline void ProcessQueuedCallbacks(std::mutex& mutex, std::atomic_bool& dirty, std::vector<std::function<void()>>& callbacks)
{
	bool expected = true;
	if (!dirty.compare_exchange_weak(expected, false))
		return;

	std::unique_lock<std::mutex> lock(mutex);
	if (callbacks.empty())
		return;

	std::vector<std::function<void()>> temp;
	std::swap(temp, callbacks);

	lock.unlock();

	for (const auto& cb : temp)
		cb();
}

void NamedPipeEndpointBase::PostToPipeThread(std::function<void()>&& callback)
{
	if (std::this_thread::get_id() == m_pipeThreadId)
	{
		callback();
	}
	else
	{
		{
			std::scoped_lock lock(m_threadQueueMutex);
			m_threadQueue.push_back(std::move(callback));
			m_threadQueueDirty = true;
		}
		m_interruptEvent.SetEvent();
	}
}

void NamedPipeEndpointBase::ProcessPipeThreadQueue()
{
	assert(std::this_thread::get_id() == m_pipeThreadId);

	ProcessQueuedCallbacks(m_threadQueueMutex, m_threadQueueDirty, m_threadQueue);
}

void NamedPipeEndpointBase::PostToMainThread(std::function<void()>&& callback)
{
	if (std::this_thread::get_id() == m_mainThreadId)
	{
		callback();
	}
	else
	{
		{
			std::scoped_lock lock(m_mainQueueMutex);
			m_mainQueue.push_back(std::move(callback));
			m_mainQueueDirty = true;
		}

		if (m_handler)
		{
			m_handler->OnRequestProcessEvents();
		}
	}
}

void NamedPipeEndpointBase::ProcessMainThreadQueue()
{
	assert(std::this_thread::get_id() == m_mainThreadId);

	ProcessQueuedCallbacks(m_mainQueueMutex, m_mainQueueDirty, m_mainQueue);
}

//============================================================================
// NamedPipeServer
//============================================================================

NamedPipeServer::NamedPipeServer(const char* pipeName)
	: NamedPipeEndpointBase("NamedPipeServer", pipeName)
{
	m_connectEvent.create(wil::EventOptions::ManualReset | wil::EventOptions::Signaled);

	ZeroMemory(&m_oConnect, sizeof(m_oConnect));
	m_oConnect.hEvent = m_connectEvent.get();
}

NamedPipeServer::~NamedPipeServer()
{
	Stop();
}

void NamedPipeServer::NamedPipeThread()
{
	HANDLE waitEvents[2] =
	{
		m_connectEvent.get(),
		m_interruptEvent.get(),
	};

	// initiate by creating the pipe
	bool bPending = CreateAndConnect();

	while (IsRunning())
	{
		// Waiting here will result in three things:
		// 1. A connection event (a new incoming connection)
		// 2. A stop event (server shutting down)
		// 3. A background task being completed and executed while we wait.
		DWORD dwWait = WaitForMultipleObjectsEx(2, waitEvents, FALSE, INFINITE, TRUE);

		switch (dwWait)
		{
		case 0: // connect event
			SPDLOG_TRACE("NamedPipeServer::NamedPipeThread: woke up on connect event");

			// If an operation is pending, get the result of the connect operation.
			if (bPending)
			{
				DWORD bytesRead = 0;
				BOOL success = GetOverlappedResult(
					m_hPipe.get(),      // pipe handle
					&m_oConnect,        // OVERLAPPED structure
					&bytesRead,         // bytes transferred (unused)
					FALSE);             // do not wait
				if (!success)
					throw fmt::windows_error(GetLastError(), "Failed to get overlapped result while connecting");
			}

			{
				// create new connection object and pass the pipe off to it.
				auto connection = std::make_shared<PipeConnection>(this, std::move(m_hPipe));
				connection->StartRead();

				std::scoped_lock<std::mutex> lock(m_mutex);
				m_connections.push_back(connection);

				PostToMainThread(
					[connectionId = connection->GetConnectionId(),
					processId = connection->GetProcessId(), this]()
				{
					if (m_handler)
					{
						m_handler->OnIncomingConnection(connectionId, processId);
					}
				});
			}

			// Start listening again.
			bPending = CreateAndConnect();
			break;

		case 1: // interrupt event
			//SPDLOG_TRACE("NamedPipeServer::NamedPipeThread: woke up on interrupt event");
			ProcessPipeThreadQueue();
			break;

		case WAIT_IO_COMPLETION:
			//SPDLOG_TRACE("NamedPipeServer::server_thread: woke up on io completion");

			// The wait is satisfied by a completed read or write operation.
			// This allows the system to execute the completion routine.
			break;

		default:
			throw fmt::windows_error(GetLastError(), "Failed in WaitForMultipleObjectsEx");
		}
	}

	{
		std::unique_lock<std::mutex> lock(m_mutex);
		if (!m_connections.empty())
		{
			SPDLOG_INFO("Starting to cancel {} connections...", m_connections.size());

			// close all the pipes
			for (auto& connection : m_connections)
			{
				SPDLOG_INFO("Canceling connection {}", connection->GetConnectionId());
				connection->InternalClose(true);
			}
		}
	}

	if (m_hPipe)
	{
		SPDLOG_INFO("Canceling pending connect requests");
		::CancelIoEx(m_hPipe.get(), &m_oConnect);

		if (!::DisconnectNamedPipe(m_hPipe.get()))
		{
			SPDLOG_ERROR("NamedPipeServer::NamedPipeThread: {}",
				fmt::windows_error(GetLastError(), "Failed at DisconnectNamePipe").what());
		}
	}

	auto startTime = std::chrono::steady_clock::now();

	while (GetConnectionCount() > 0)
	{
		// Wait for remaining queued tasks to resolve
		SleepEx(100, TRUE);

		SPDLOG_TRACE("Connections left: {}", GetConnectionCount());

		// abort after 10 seconds of waiting
		if (std::chrono::steady_clock::now() - startTime > 10s)
			break;
	}
}

bool NamedPipeServer::CreateAndConnect()
{
	// the pipe should have been moved out by now...
	m_hPipe.reset();

	SECURITY_ATTRIBUTES sa;
	sa.nLength = sizeof(sa);
	sa.bInheritHandle = false;

	wil::unique_any<PSECURITY_DESCRIPTOR, decltype(&::LocalFree), LocalFree> saCleanup;
	PSECURITY_ATTRIBUTES pSA = nullptr;

	// Create a security descriptor that allows everyone access
	if (!::ConvertStringSecurityDescriptorToSecurityDescriptorW(L"D:(A;OICI;GA;;;WD)",
		SDDL_REVISION_1, saCleanup.addressof(), nullptr))
	{
		SPDLOG_ERROR("Failed to create security descriptor. Other processes may not be able to access the named pipe!");
	}
	else
	{
		sa.lpSecurityDescriptor = saCleanup.get();
		pSA = &sa;
	}

	wil::unique_hfile hPipe(::CreateNamedPipeW(
		mq::utf8_to_wstring(m_pipeName).c_str(), // pipe name
		PIPE_ACCESS_DUPLEX |                     // read/write access
		    FILE_FLAG_OVERLAPPED,                // overlapped mode
		PIPE_TYPE_MESSAGE |                      // message-type pipe
		    PIPE_READMODE_MESSAGE |              // message read mode
		    PIPE_WAIT,                           // blocking mode
		PIPE_UNLIMITED_INSTANCES,                // unlimited instances,
		BUFFER_SIZE,                             // output buffer size,
		BUFFER_SIZE,                             // input buffer size
		PIPE_TIMEOUT,                            // client timeout
		pSA));                                   // default security attributes
	if (!hPipe.is_valid()) {
		throw fmt::windows_error(::GetLastError(), "Failed to create named pipe on {}", m_pipeName);
	}

	// Start an overlapped connection for this pipe instance.
	::ConnectNamedPipe(hPipe.get(), &m_oConnect);

	DWORD lastErr = GetLastError();
	bool pendingIO = false;

	switch (lastErr)
	{
	case ERROR_IO_PENDING: // the overlapped connection is in progress
		pendingIO = true;
		break;

	case ERROR_PIPE_CONNECTED: // the pipe is already connected, so signal an event
		m_connectEvent.SetEvent();
		break;

	default:
		throw fmt::windows_error(::GetLastError(), "Failed to connect to named pipe");
	}

	m_hPipe = std::move(hPipe);
	return pendingIO;
}

void NamedPipeServer::CloseConnection(PipeConnection* connection)
{
	PostToMainThread(
		[connectionId = connection->GetConnectionId(),
		processId = connection->GetProcessId(), this]()
	{
		if (m_handler)
		{
			m_handler->OnConnectionClosed(connectionId, processId);
		}
	});

	// close the connection
	if (connection->InternalClose(true))
	{
		SPDLOG_DEBUG("Closing connection. connectionId={0}", connection->GetConnectionId());
	}

	std::scoped_lock<std::mutex> lock(m_mutex);

	// erase from the list
	m_connections.erase(
		std::remove_if(m_connections.begin(), m_connections.end(),
			[connection](const auto& conn) { return conn.get() == connection; }),
		m_connections.end());
}

int NamedPipeServer::GetConnectionCount() const
{
	std::scoped_lock<std::mutex> lock(m_mutex);
	return static_cast<int>(m_connections.size());
}

std::shared_ptr<PipeConnection> NamedPipeServer::GetConnection(int connectionId) const
{
	std::scoped_lock<std::mutex> lock(m_mutex);

	auto iter = std::find_if(
		std::begin(m_connections), std::end(m_connections),
		[connectionId](const std::shared_ptr<PipeConnection>& ptr) { return ptr->GetConnectionId() == connectionId; });
	if (iter == std::end(m_connections))
		return nullptr;

	return *iter;
}

std::vector<int> NamedPipeServer::GetConnectionIds() const
{
	std::vector<int> connIds;

	{
		std::scoped_lock<std::mutex> lock(m_mutex);
		connIds.reserve(m_connections.size());

		for (const auto& conn : m_connections)
		{
			connIds.push_back(conn->GetConnectionId());
		}
	}

	return connIds;
}

std::shared_ptr<PipeConnection> NamedPipeServer::GetConnectionForProcessId(uint32_t processId) const
{
	std::scoped_lock<std::mutex> lock(m_mutex);

	for (const auto& conn : m_connections)
	{
		if (conn->GetProcessId() == processId)
			return conn;
	}

	return nullptr;
}

void NamedPipeServer::PostToMainThread(std::function<void()>&& callback)
{
	NamedPipeEndpointBase::PostToMainThread(std::move(callback));

	if (m_handler)
	{
		m_handler->OnRequestProcessEvents();
	}
}

void NamedPipeServer::SendMessage(int connectionId, PipeMessagePtr&& message)
{
	auto connection = GetConnection(connectionId);

	if (connection)
	{
		connection->SendMessage(std::move(message));
	}
	else
	{
		SPDLOG_WARN("Tried to send message on closed connection: connectionId={} sequenceId={}",
			connectionId, message->GetSequenceId());
	}
}

void NamedPipeServer::SendMessage(int connectionId, MQMessageId messageId, const void* data, size_t dataLength)
{
	auto connection = GetConnection(connectionId);

	if (connection)
	{
		connection->SendMessage(messageId, data, dataLength);
	}
	else
	{
		SPDLOG_WARN("Tried to send message on closed connection: connectionId={} messageId={}", connectionId, static_cast<int>(messageId));
	}
}

void NamedPipeServer::BroadcastMessage(PipeMessagePtr&& message)
{
	for (const auto& connection : m_connections)
	{
		// force the copy here instead of downstream (because we only want to do this in broadcast)
		connection->SendMessage(
			std::make_unique<PipeMessage>(*message->GetHeader(), message->get(), message->size())
		);
	}
}

void NamedPipeServer::BroadcastMessage(MQMessageId messageId, const void* data, size_t dataLength)
{
	BroadcastMessage(MakeSimpleMessageV0(messageId, data, dataLength));
}

//============================================================================
//============================================================================

NamedPipeClient::NamedPipeClient(const char* pipeName)
	: NamedPipeEndpointBase("NamedPipeClient", pipeName)
{
}

NamedPipeClient::~NamedPipeClient()
{
}

void NamedPipeClient::NamedPipeThread()
{
	HANDLE waitEvents[1] = {
		m_interruptEvent.get(),
	};

	while (IsRunning())
	{
		bool showMessage = true;

		// First loop will try to establish a connection
		while (!m_connection && IsRunning())
		{
			SPDLOG_TRACE("Attempting to connect to named pipe: {}", m_pipeName);

			// If we're not connected to the server, we'll try to connect.
			wil::unique_hfile hPipe(::CreateFileA(
				m_pipeName.c_str(),                      // pipe name
				GENERIC_READ | GENERIC_WRITE,            // need read and write access
				0,                                       // no sharing
				nullptr,                                 // default security attributes
				OPEN_EXISTING,                           // open an existing named pipe
				FILE_FLAG_OVERLAPPED,                    // enabled overlapped i/o
				nullptr                                  // no template file
			));

			// If the pipe handle is valid, we're ready to roll.
			if (hPipe.is_valid())
			{
				SPDLOG_INFO("Connected to named pipe server.", m_pipeName);

				// Switch pipe to message mode.
				DWORD dwMessageMode = PIPE_READMODE_MESSAGE;
				if (!::SetNamedPipeHandleState(hPipe.get(), &dwMessageMode, nullptr, nullptr))
				{
					SPDLOG_ERROR("{}",
						fmt::windows_error(GetLastError(), "Failed to set message mode on named pipe!").what());
				}
				else
				{
					m_connection = std::make_shared<PipeConnection>(this, std::move(hPipe));
					m_connection->StartRead();

					if (m_handler)
					{
						m_handler->OnClientConnected();
					}
					break;
				}
			}

			bool wait = true;
			DWORD lastError = GetLastError();
			switch (lastError)
			{
			case ERROR_FILE_NOT_FOUND:
				// named pipe has not been created
				SPDLOG_TRACE("Named pipe not found, waiting for it to be created...");
				break;

			case ERROR_ACCESS_DENIED:
				// named pipe exists but is not accessible
				if (showMessage)
				{
					showMessage = false;
					SPDLOG_ERROR("Named pipe exists but is not accessible!");
				}
				break;

			case ERROR_PIPE_BUSY:
				SPDLOG_TRACE("Named pipe is busy, waiting for it to not be busy...");
				wait = false;

				// pipe is busy, likely due to another client connecting. Wait for a moment
				// and try again.
				if (!::WaitNamedPipe(m_pipeName.c_str(), 5000))
				{
					lastError = GetLastError();
					if (lastError == ERROR_SEM_TIMEOUT)
					{
						SPDLOG_TRACE("Timed out waiting for named pipe server to become unbusy. Starting over...");
					}
					else
					{
						SPDLOG_TRACE("{}",
							fmt::windows_error(lastError, "Unexpected error occurred while waiting for named pipe").what());
						wait = true;
					}
				}
				break;

			default:
				SPDLOG_TRACE("{}",
					fmt::windows_error(lastError, "Unexpected error occurred trying to open named pipe").what());
				break;
			}

			if (wait)
			{
				// Wait 5 seconds and try again.
				DWORD dwResult = WaitForSingleObject(m_interruptEvent.get(), 5000);
				if (dwResult == WAIT_OBJECT_0)
				{
					ProcessPipeThreadQueue();
					//SPDLOG_TRACE("Woke up to interrupt event");
					break;
				}
			}
		}

		// Second loop will try to process events on the connection
		while (m_connection && IsRunning())
		{
			DWORD dwWait = WaitForMultipleObjectsEx(static_cast<DWORD>(lengthof(waitEvents)), waitEvents, FALSE, INFINITE, TRUE);

			switch (dwWait)
			{
			case 0: // interrupt event
				//SPDLOG_TRACE("Woke up to interrupt event");
				ProcessPipeThreadQueue();
				break;

			case WAIT_IO_COMPLETION:
				break;

			default:
				throw fmt::windows_error(GetLastError(), "Failed in WaitForMultipleObjectsEx");
			}
		}
	}

	// If we're here and we're still connected we need to close the connection
	if (m_connection)
	{
		m_connection->Close();
	}
}

bool NamedPipeClient::IsConnected() const
{
	return m_connection != nullptr;
}

void NamedPipeClient::CloseConnection(PipeConnection* connection)
{
	SPDLOG_DEBUG("Closing connection. connectionId={0}", connection->GetConnectionId());

	// close the connection
	connection->InternalClose(false);

	// can this even not be true?
	if (connection == m_connection.get())
	{
		m_connection.reset();

		// Trigger interrupt to reboot the connection loop.
		m_interruptEvent.SetEvent();
	}
}

void NamedPipeClient::SendMessage(PipeMessagePtr&& message)
{
	if (m_connection)
	{
		m_connection->SendMessage(std::move(message));
	}
	else
	{
		SPDLOG_WARN("Tried to send a message with id {0} on a null connection.", static_cast<int>(message->GetMessageId()));
	}
}

void NamedPipeClient::SendMessage(MQMessageId messageId, const void* data, size_t dataLength)
{
	if (m_connection)
	{
		m_connection->SendMessage(messageId, data, dataLength);
	}
	else
	{
		SPDLOG_WARN("Tried to send a message with id {0} on a null connection.", static_cast<int>(messageId));
	}
}

void NamedPipeClient::SendMessageWithResponse(PipeMessagePtr&& message, const PipeMessageResponseCb& response)
{
	if (m_connection)
	{
		m_connection->SendMessageWithResponse(std::move(message), response);
	}
	else
	{
		SPDLOG_WARN("Tried to send a message with id {0} on a null connection.", static_cast<int>(message->GetMessageId()));
	}
}

void NamedPipeClient::SendMessageWithResponse(MQMessageId messageId, const void* data, size_t dataLength,
	const PipeMessageResponseCb& response)
{
	if (m_connection)
	{
		m_connection->SendMessageWithResponse(messageId, data, dataLength, response);
	}
	else
	{
		SPDLOG_WARN("Tried to send a message with id {0} on a null connection.", static_cast<int>(messageId));
	}
}

//============================================================================
//============================================================================

} // namespace mq
