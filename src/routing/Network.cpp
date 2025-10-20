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

// the number of the day is 7781 and 239.255.77.81

// Uncomment to see super spammy read/write trace logging
//#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE

#include "routing/Network.h"
#include "routing/Routing.h"
#include "routing/Network.pb.h"

#include "asio.hpp"
#include "spdlog/spdlog.h"

#include <queue>
#include <map>
#include <atomic>
#include <optional>

// TODO: Unit tests
// TODO: Leader (later work, get internal networking done first):
//	-- leader gets PAT from router
//	-- only leader will have the external IP in hosts
//	-- does leader need to be an explicitly configured option? maybe can detect external IPs in hosts?
//	-- need to handle multiple peers trying to assume leadership
//	-- unknown IPs in not-leaders should all go to leader

using asio::ip::tcp;
using namespace mq;

class NetworkSession;
using InternalMessageHandler = std::function<void(const peernetwork::Header&, NetworkSession*, std::unique_ptr<uint8_t[]>&&, uint32_t)>;

template <typename T>
class LockedQueue
{
public:
	void Push(T value)
	{
		std::unique_lock<std::mutex> lock(m_mutex);
		m_queue.push(std::move(value));
	}

	T Pop()
	{
		std::unique_lock<std::mutex> lock(m_mutex);
		T value;
		std::swap(value, m_queue.front());
		m_queue.pop();
		return value;
	}

	bool Empty()
	{
		std::unique_lock<std::mutex> lock(m_mutex);
		return m_queue.empty();
	}

private:
	std::mutex m_mutex;
	std::queue<T> m_queue;
};

class NetworkMessage
{
public:
	// outgoing message
	NetworkMessage(peernetwork::Header&& header, std::unique_ptr<uint8_t[]>&& payload, uint32_t length)
		: m_parsedHeader(std::move(header))
		, m_length(length)
		, m_payload(std::move(payload))
	{
		InitHeader();
	}

	// incoming message
	NetworkMessage()
		: m_headerLength(0)
		, m_headerLengthNetwork(0)
		, m_length(0)
	{}

	NetworkMessage(const NetworkMessage&) = delete;
	NetworkMessage(NetworkMessage&&) = delete;
	NetworkMessage& operator=(const NetworkMessage&) = delete;
	NetworkMessage& operator=(NetworkMessage&&) = delete;

	~NetworkMessage() = default;

	void InitHeader()
	{
		m_parsedHeader.set_length(m_length);
		m_headerLength = static_cast<uint32_t>(m_parsedHeader.ByteSizeLong());
		m_headerLengthNetwork = htonl(m_headerLength);

		AllocateHeader();
		m_parsedHeader.SerializeToArray(m_header.get(), static_cast<int>(m_headerLength));
	}

	void AllocateHeader()
	{
		m_header = std::make_unique<uint8_t[]>(m_headerLength);
	}

	void Init()
	{
		m_parsedHeader.ParseFromArray(m_header.get(), static_cast<int>(m_headerLength));
		m_length = m_parsedHeader.length();

		if (m_length > 0)
			m_payload = std::make_unique<uint8_t[]>(m_length);
	}

	std::vector<asio::const_buffer> Buffers() const
	{
		// This assumes a header will always exist, ensure that the asio read assumes that as well!
		std::vector<asio::const_buffer> buffers{
			asio::buffer(&m_headerLengthNetwork, sizeof(uint32_t)),
			asio::buffer(m_header.get(), m_headerLength)
		};

		if (m_payload && m_length > 0)
			buffers.emplace_back(asio::buffer(m_payload.get(), m_length));

		return buffers;
	}

	void Receive(NetworkSession* session, const InternalMessageHandler& handler)
	{
		handler(m_parsedHeader, session, std::move(m_payload), m_length);
	}

	void Relay(uint16_t port);

	uint32_t& HeaderLength() { return m_headerLength; }
	uint32_t& HeaderLengthNetwork() { return m_headerLengthNetwork; }
	uint8_t* Header() const { return m_header.get(); }
	const peernetwork::Header& ParsedHeader() { return m_parsedHeader; }

	uint32_t& Length() { return m_length; }
	uint8_t* Payload() const { return m_payload.get(); }

	void Reset()
	{
		m_headerLength = 0;
		m_headerLengthNetwork = 0;
		m_header.reset();

		m_parsedHeader.Clear();

		m_length = 0;
		m_payload.reset();
	}

private:
	uint32_t m_headerLength;
	uint32_t m_headerLengthNetwork;
	std::unique_ptr<uint8_t[]> m_header;

	peernetwork::Header m_parsedHeader;

	uint32_t m_length;
	std::unique_ptr<uint8_t[]> m_payload;
};

class NetworkSession
{
public:
	NetworkSession(uint16_t peer_port, tcp::socket&& socket, InternalMessageHandler receiveHandler)
		: m_socket(std::move(socket))
		, m_peerPort(peer_port)
		, m_address({m_socket.remote_endpoint().address().to_string(), m_socket.remote_endpoint().port()})
		, m_knownAddress(m_address)
		, m_active(true)
		, m_messageBuffer(std::make_unique<NetworkMessage>())
		, m_receiveHandler(std::move(receiveHandler))
	{
		SPDLOG_TRACE("{}: Session created ({}:{})", m_peerPort, m_knownAddress.IP, m_knownAddress.Port);
	}

	NetworkSession() = delete;
	NetworkSession(const NetworkSession&) = delete;
	NetworkSession(NetworkSession&&) = delete;
	NetworkSession& operator=(const NetworkSession&) = delete;
	NetworkSession& operator=(NetworkSession&&) = delete;

	~NetworkSession()
	{
		SPDLOG_TRACE("{}: Session destroyed {}:{} ({}:{})", m_peerPort, m_address.IP, m_address.Port, m_knownAddress.IP, m_knownAddress.Port);

		// this should have already shut down gracefully but in the case we had an issue then call cancel to force it to close
		if (m_socket.is_open())
		{
			SPDLOG_WARN("{}: session did not close gracefully, canceling the socket {}:{} ({})", m_peerPort, m_address.IP, m_address.Port, m_knownAddress.Port);
			m_socket.cancel();
		}
	}

	void Shutdown()
	{
		if (m_active)
		{
			SPDLOG_TRACE("{}: Shutting down connection {}:{} ({}:{})", m_peerPort, m_address.IP, m_address.Port, m_knownAddress.IP, m_knownAddress.Port);
			std::error_code ec;

			// only shutdown writes. shutting down both will cause forced socket closures on the other end
			(void)m_socket.shutdown(asio::socket_base::shutdown_send, ec);
			if (ec)
				SPDLOG_WARN("{}: Received error while shutting down socket {}: {}", m_peerPort, ec.value(), ec.message());
			m_active = false;
		}
	}

	void Close()
	{
		if (m_socket.is_open() && !m_reading && !m_writing)
		{
			std::error_code ec;
			m_socket.close(ec);
			if (ec)
				SPDLOG_WARN("{}: Received error when closing down socket {}: {}", m_peerPort, ec.value(), ec.message());
		}
	}

	void Receive()
	{
		SPDLOG_TRACE("{}: Session receiving", m_peerPort);
		m_reading = true; // we only start reading once, set it here
		Read();
	}

	void Write(peernetwork::Header&& header, std::unique_ptr<uint8_t[]> payload, uint32_t length)
	{
		// don't start writes on sessions that are closing down
		if (m_active)
		{
			// this function should only ever get called from the ASIO thread
			// to ensure that we don't have multiple write loops happening at
			// once
			m_outgoing.Push(std::make_unique<NetworkMessage>(std::move(header), std::move(payload), length));

			// kick off the loop if it's not running and there are messages
			if (!m_writing)
			{
				InternalWrite();
			}
		}
	}

	bool IsActive() const { return m_active; }
	bool IsOpen() const { return m_socket.is_open(); }
	tcp::endpoint Endpoint() const { return m_socket.remote_endpoint(); }
	const NetworkAddress& Address() const { return m_address; }
	const NetworkAddress& KnownAddress() const { return m_knownAddress; }

	bool IsInitializing() const { return m_peerUuid.empty(); }
	const void UpdateFromHandshake(const NetworkAddress& knownAddress, const std::string& uuid)
	{
		m_knownAddress = knownAddress;
		m_peerUuid = uuid;
	}

	const std::string& UUID() { return m_peerUuid; }

private:
	void CloseWithMessage(const std::error_code& ec, std::string_view step)
	{
		// see if the EC is a normal operation that shouldn't throw an error message
		// if the EC is a continuable error, just warn
		if (ec == asio::error::connection_reset || // this is if the socket is force closed remotely (when the peer is destroyed)
			ec == asio::error::shut_down || // this is when we shut down the socket locally
			ec == asio::error::connection_aborted) // this is when we shutdown the entire peer
			SPDLOG_WARN("{}:{} ({}); {} error {}: {}", m_knownAddress.IP, m_knownAddress.Port, m_peerPort, step, ec.value(), ec.message());
		else if (ec != asio::error::eof) // this is when the connection was closed remotely, and is the only graceful shutdown condition
			SPDLOG_ERROR("{}:{} ({}): {} error {}: {}", m_knownAddress.IP, m_knownAddress.Port, m_peerPort, step, ec.value(), ec.message());

		Close();
	}

	void Read()
	{
		// ASIO is designed around either shared pointers or some externally controlled pointer
		// the simpler solution is a shared_ptr but it would reduce overhead (by how much?)
		// to use an external buffer. Using a reset method means we don't have to allocate for each
		// message as well.
		m_messageBuffer->Reset();
		asio::async_read(
			m_socket,
			asio::buffer(&m_messageBuffer->HeaderLengthNetwork(), sizeof(uint32_t)),
			asio::transfer_exactly(sizeof(uint32_t)),
			[this](const std::error_code& ec, size_t)
			{
				SPDLOG_TRACE("{}: reading message from socket {}", m_peerPort, m_socket.local_endpoint().port());
				if (!ec)
					ReadHeader();
				else
				{
					m_reading = false;
					CloseWithMessage(ec, "Header length read");
				}
			});
	}

	void ReadHeader()
	{
		m_messageBuffer->HeaderLength() = ntohl(m_messageBuffer->HeaderLengthNetwork());
		SPDLOG_TRACE("{}: Detected message ({} header length)", m_peerPort, m_messageBuffer->HeaderLength());

		if (m_messageBuffer->HeaderLength() == 0)
		{
			SPDLOG_WARN("{}: Got zero length header, dropping message", m_peerPort);
			Read();
		}
		else
		{
			m_messageBuffer->AllocateHeader();
			asio::async_read(
				m_socket,
				asio::buffer(m_messageBuffer->Header(), m_messageBuffer->HeaderLength()),
				asio::transfer_exactly(m_messageBuffer->HeaderLength()),
				[this](const std::error_code& ec, size_t)
				{
					if (!ec)
						ReadPayload();
					else
					{
						m_reading = false;
						CloseWithMessage(ec, "Header read");
					}
				});
		}
	}

	void ReadPayload()
	{
		m_messageBuffer->Init();

		if (m_messageBuffer->ParsedHeader().has_address())
		{
			// this is a redirect
			// TODO: this likely doesn't work, but revisit when adding leader logic
			m_messageBuffer->Relay(m_peerPort);
		}
		if (m_messageBuffer->Length() > 0)
		{
			asio::async_read(
				m_socket,
				asio::buffer(m_messageBuffer->Payload(), m_messageBuffer->Length()),
				asio::transfer_exactly(m_messageBuffer->Length()),
				[this](const std::error_code& ec, size_t)
				{
					if (!ec)
						ReceiveMessage();
					else
					{
						m_reading = false;
						CloseWithMessage(ec, "Payload read");
					}
				});
		}
		else
		{
			// if there is no length, no need to read from the wire
			ReceiveMessage();
		}
	}

	void ReceiveMessage()
	{
		SPDLOG_TRACE("{}: Received message from {}:{} ({} bytes)",
			m_peerPort, m_knownAddress.IP, m_knownAddress.Port, m_messageBuffer->Length());

		if (m_receiveHandler != nullptr)
		{
			m_messageBuffer->Receive(this, m_receiveHandler);
		}
		else
			SPDLOG_ERROR("{}: Receive handler is null in network", m_peerPort);

		Read();
	}

	void InternalWrite()
	{
		if (m_outgoing.Empty())
		{
			m_writing = false;
		}
		else
		{
			m_writing = true;
			m_currentOutgoing = m_outgoing.Pop();

			SPDLOG_TRACE("{}: writing message to socket {}", m_peerPort, m_socket.remote_endpoint().port());

			asio::async_write(
				m_socket,
				m_currentOutgoing->Buffers(),
				[this](const std::error_code& ec, size_t size)
				{
					SPDLOG_TRACE("{}: Writing message of size {} to {}:{}",
						m_peerPort, size, m_socket.remote_endpoint().address().to_string(), m_socket.remote_endpoint().port());

					// always reset the pointer, error or not
					m_currentOutgoing.reset();

					if (!ec)
						InternalWrite();
					else
					{
						m_writing = false;
						CloseWithMessage(ec, "Message write");
					}
				});
		}
	}

private:
	tcp::socket m_socket;
	const uint16_t m_peerPort;
	const NetworkAddress m_address;
	NetworkAddress m_knownAddress; // this is what the user will "know" the connection address as
	std::string m_peerUuid;
	bool m_active;

	const std::unique_ptr<NetworkMessage> m_messageBuffer;

	InternalMessageHandler m_receiveHandler;
	LockedQueue<std::unique_ptr<NetworkMessage>> m_outgoing;
	std::unique_ptr<NetworkMessage> m_currentOutgoing;

	bool m_writing = false;
	bool m_reading = false;
};

class NetworkPeer
{
public:
	NetworkPeer() = delete;
	NetworkPeer(const NetworkPeer&) = delete;
	NetworkPeer(NetworkPeer&&) = delete;
	NetworkPeer& operator=(const NetworkPeer&) = delete;
	NetworkPeer& operator=(NetworkPeer&&) = delete;

	NetworkPeer(
		uint16_t port,
		PeerMessageHandler receiveHandler,
		OnSessionConnectedHandler connectedHandler,
		OnSessionDisconnectedHandler disconnectedHandler,
		OnRequestProcessHandler requestProcessHandler)
		: m_acceptor(m_ioContext, tcp::endpoint(tcp::v4(), port))
		, m_port(m_acceptor.local_endpoint().port())
		, m_uuid(CreateUUID())
		, m_receiveHandler(std::move(receiveHandler))
		, m_sessionConnectedHandler(std::move(connectedHandler))
		, m_sessionDisconnectedHandler(std::move(disconnectedHandler))
		, m_requestProcessHandler(std::move(requestProcessHandler))
	{
	}

	~NetworkPeer()
	{
		SPDLOG_TRACE("{}: Removing peer", m_port);
	}

	void Run()
	{
		bool running = false;
		if (m_running.compare_exchange_weak(running, true))
		{
			m_thread = std::thread([this]()
				{
					try
					{
						using fSetThreadDescription = HRESULT(WINAPI*)(HANDLE, PCWSTR);
						fSetThreadDescription SetThreadDescription = nullptr;
						if (auto kernel = GetModuleHandleA("kernel32.dll"))
							SetThreadDescription = (fSetThreadDescription)GetProcAddress(kernel, "SetThreadDescription");

						if (SetThreadDescription)
							SetThreadDescription(GetCurrentThread(), L"Network ASIO");

						SPDLOG_TRACE("{}: Initializing peer", m_port);

						m_acceptor.listen();
						Accept();

						SPDLOG_TRACE("{}: Starting peer thread", m_port);
						while (m_ioContext.run_one())
						{
							PruneSessions();
						}

						SPDLOG_TRACE("{}: Peer thread stopping normally", m_port);
					}
					catch (std::exception& e)
					{
						m_running = false;

						// we can be indelicate here since everything has already failed
						m_acceptor.cancel();
						DrainSessions();

						SPDLOG_ERROR("{}: Peer failed with exception {}", m_port, e.what());
					}
				});
		}
		else
			SPDLOG_WARN("{}: Attempted to run the peer thread while it was already running", m_port);
	}

	void Send(
		peernetwork::MessageType message_type,
		const NetworkAddress& address,
		std::unique_ptr<uint8_t[]> payload,
		uint32_t length)
	{
		if (m_running)
		{
			std::unique_lock lock(m_processMutex);

			m_writeQueue.emplace_back(message_type, address, std::move(payload), length);
			m_ioContext.post([this] { ProcessWrites(); });
		}
	}

	// the thread this function runs on is externally controlled because this is where we run the
	// callbacks provided from the external network construction, so we don't want to use io.post()
	void Process()
	{
		std::unique_lock lock(m_processMutex);

		if (m_running && (!m_processQueue.empty() || !m_receiveQueue.empty()))
		{
			std::vector<std::function<void()>> processes;
			std::swap(processes, m_processQueue);

			std::vector<std::pair<NetworkAddress, NetworkMessagePtr>> receives;
			std::swap(receives, m_receiveQueue);

			// unlock here so we aren't holding up the ASIO thread
			lock.unlock();

			// handle any connection bookeeping processes before doing any receiving
			for (const auto& process : processes)
				process();

			for (auto& [addr, msg] : receives)
				m_receiveHandler(addr, std::move(msg));
		}
	}

	void Broadcast(peernetwork::MessageType message_type, std::unique_ptr<uint8_t[]> payload, uint32_t length)
	{
		if (m_running)
		{
			std::unique_lock lock(m_processMutex);

			m_broadcastQueue.emplace_back(message_type, std::move(payload), length);
			m_ioContext.post([this] { ProcessBroadcasts(); });
		}
	}

	void AddHost(const NetworkAddress& address)
	{
		if (m_running)
		{
			std::unique_lock lock(m_hostMutex);
			m_queuedConnects.push_back(address);
			m_knownHosts.insert(address);

			m_ioContext.post([this] { AddConnections(); });
		}
	}

	void RemoveHost(const NetworkAddress& address)
	{
		std::unique_lock lock(m_hostMutex);
		m_knownHosts.erase(address);
		m_ioContext.post([this, address]
			{
				const auto session = m_sessions.find(address);
				if (session != m_sessions.end())
				{
					// This will prune the session gracefully
					session->second->Shutdown();
				}
			});
	}

	void Shutdown()
	{
		bool running = true;
		if (m_running.compare_exchange_weak(running, false))
		{
			SPDLOG_TRACE("{}: Shutting down peer with {} sessions and {} pending sessions", m_port, m_sessions.size(), m_connectingSessions.size());
			// the acceptor needs to be signaled immediately to close or it could accept a connection after m_running
			// is set to false, causing the session to never drain
			m_acceptor.close();
			m_ioContext.post([this] { DrainSessions(); });
		}
		else
			SPDLOG_WARN("{}: Attempting to shutdown an inactive peer", m_port);

		m_thread.join();
	}

	bool HasHost(const NetworkAddress& address)
	{
		return m_running && m_knownHosts.find(address) != m_knownHosts.end();
	}

	uint16_t GetPort()
	{
		return m_port;
	}

private:

	void Handshake(peernetwork::MessageType messageType, NetworkSession* session, const NetworkAddress& address)
	{
		peernetwork::Header header;
		header.set_type(messageType);

		peernetwork::Identity id;
		id.set_uuid(m_uuid);
		id.set_port(m_port);

		auto payload = std::make_unique<uint8_t[]>(id.ByteSizeLong());
		id.SerializeToArray(payload.get(), static_cast<uint32_t>(id.ByteSizeLong()));

		session->Write(std::move(header), std::move(payload), static_cast<uint32_t>(id.ByteSizeLong()));
	}

	void Connect(const NetworkAddress& address)
	{
		auto socket = std::make_shared<tcp::socket>(m_acceptor.get_executor());
		const tcp::endpoint endpoint(asio::ip::address::from_string(address.IP), address.Port);

		{
			//m_pendingConnects.emplace_back(address);
		}

		SPDLOG_TRACE("{}: Initiating connection to {}:{}", m_port, address.IP, address.Port);

		socket->async_connect(
			endpoint,
			[this, address = address, socket](const std::error_code& ec)
			{
				if (m_running && !ec)
				{
					SPDLOG_TRACE("{}: Connect attempt with local endpoint {}:{} and remote endpoint {}:{}",
						m_port,
						socket->local_endpoint().address().to_string(), socket->local_endpoint().port(),
						socket->remote_endpoint().address().to_string(), socket->remote_endpoint().port());

					// pass off the connection to the session
					auto session = AddSession(std::move(*socket));
					if (session != nullptr)
						Handshake(peernetwork::MessageType::Handshake, session, address);
				}
				else
				{
					// connection refused is when the peer is not available, don't throw an error for that
					if (m_running && ec != asio::error::connection_refused)
						SPDLOG_ERROR("{}: Connect failed with ERR {}: {}", m_port, ec.value(), ec.message());

					// make sure to close the socket on failure
					if (socket->is_open()) socket->close();

					// if the session has failed then let the user handle it
					m_sessionDisconnectedHandler(address);
				}

				// no matter the outcome, remove one instance of this address from pending connects
				{
					auto pending_it = m_pendingConnects.find(address);
					if (pending_it != m_pendingConnects.end())
						m_pendingConnects.erase(pending_it);
				}
			});
	}

	void Accept()
	{
		m_acceptor.async_accept(
			[this](const std::error_code& ec, tcp::socket socket)
			{
				if (m_running && !ec)
				{
					SPDLOG_TRACE("{}: Accepting connection with local endpoint {}:{} and remote endpoint {}:{}",
						m_port,
						socket.local_endpoint().address().to_string(), socket.local_endpoint().port(),
						socket.remote_endpoint().address().to_string(), socket.remote_endpoint().port());

					// pass off the connection to the session
					AddSession(std::move(socket));

					// we always want to continue to listen, regardless of the condition of the session spawned
					Accept();
				}
				else
				{
					if (!m_running)
						SPDLOG_TRACE("{}: Connection attempted while peer was not running", m_port);

					// operation_aborted comes from closing the acceptor, we don't want to error for that
					if (m_running && ec != asio::error::operation_aborted)
						SPDLOG_ERROR("{}: Accept failed with ERR {}: {}", m_port, ec.value(), ec.message());

					// make sure to close the socket on failure
					if (socket.is_open()) socket.close();
				}
			});
	}

	NetworkSession* AddSession(tcp::socket&& socket)
	{
		auto session = std::make_unique<NetworkSession>(m_port, std::move(socket),
			[this](
				const peernetwork::Header& header,
				NetworkSession* session,
				std::unique_ptr<uint8_t[]>&& payload,
				uint32_t length)
			{
				if (m_running)
				{
					switch (header.type())
					{
					case peernetwork::Route:
					{
						auto msg = std::make_unique<peernetwork::NetworkMessage>();
						msg->ParseFromArray(payload.get(), length);

						AddProcess(session->KnownAddress(), std::move(msg));
						break;
					}
					case peernetwork::Leader:
						// set the leader here (for when the session lookup fails)
						m_leaderAddress = session->KnownAddress();
						break;
					case peernetwork::Handshake:
					{
						peernetwork::Identity id;
						id.ParseFromArray(payload.get(), length);
						ResolveHandshake(session->Address(), id.uuid(), id.port());
						Handshake(peernetwork::MessageType::Response, session, NetworkAddress{ session->Address().IP, static_cast<uint16_t>(id.port()) });
						break;
					}
					case peernetwork::Response:
					{
						peernetwork::Identity id;
						id.ParseFromArray(payload.get(), length);
						ResolveHandshake(session->Address(), id.uuid(), id.port());
						break;
					}
					default:
						SPDLOG_WARN("{}: Got unreconized header type {}", m_port, static_cast<uint32_t>(header.type()));
						break;
					}
				}
			});

		// this is guaranteed to be unique because no handshake has happened yet so we will always insert here
		auto connecting_addr = session->Address();
		if (m_connectingSessions.find(connecting_addr) == m_connectingSessions.end())
		{

			auto [session_it, _] = m_connectingSessions.emplace(connecting_addr, std::move(session));
			session_it->second->Receive();

			const auto endpoint = session_it->second->Endpoint();
			SPDLOG_TRACE("{}: Adding connection to endpoint {}:{} (connected sessions {}, connecting sessions {})",
				m_port, endpoint.address().to_string(), endpoint.port(),
				m_sessions.size(), m_connectingSessions.size());

			return session_it->second.get();
		}

		SPDLOG_ERROR("{}: attempting to connect to the same address twice: {}:{}", m_port, connecting_addr.IP, connecting_addr.Port);
		session->Shutdown();
		m_closingSessions.emplace(connecting_addr, std::move(session));

		return nullptr;
	}

	void ResolveHandshake(const NetworkAddress& fromAddress, const std::string& peerUuid, uint16_t peerPort)
	{
		// we always want the remote peer's configured port to be in the known host set, but depending on
		// the order of connection, we could have a connection with a generated port as the remote so
		// we have to map the session to the _remote_ port, and we need to deterministically choose which
		// shared session is the correct one

		SPDLOG_TRACE("{}: Received a handshake from {}:{} ({}) [{}]", m_port, fromAddress.IP, fromAddress.Port, peerPort, peerUuid);

		// the session we receive the handshake from should always be stored in this map
		// we can also have a situation where we connect and accept from the same peer without getting a handshake
		// in between, so we need to make sure we're selecting the correct peer for this handshake (which will later
		// deduplicate) -- we need to do this to ensure that this peer and the remote peer are in synced states
		// furthermore, since the keys are identical (and the remote will provide the same UUID), it doesn't actually
		// matter _which_ duplicate we pick here, so we can just find the first one

		NetworkAddress known_host{ fromAddress.IP, peerPort }; // this is the address we want to expose (with the configured port)
		// TODO: this will retain any host that attempts to connect and try to keep the connection alive, it should be optional
		{
			std::unique_lock lock(m_hostMutex);
			m_knownHosts.emplace(known_host);
		}

		auto peer_it = m_connectingSessions.find(fromAddress);
		if (peer_it != m_connectingSessions.end())
		{
			peer_it->second->UpdateFromHandshake(known_host, peerUuid);

			// find a session to the same peer if it exists
			auto duplicate_it = std::find_if(m_sessions.begin(), m_sessions.end(),
				[&peerUuid](const std::pair<const NetworkAddress, std::unique_ptr<NetworkSession>>& pair)
				{ return peerUuid == pair.second->UUID(); });

			if (duplicate_it != m_sessions.end())
			{
				// this can happen when we get 2 simultaneous connect calls from both peers, so we need to choose
				// one session to close deterministically

				if (m_uuid == peerUuid)
				{
					// not sure what to do here since the chance is vanishingly small, so just show an error
					SPDLOG_ERROR("{}: UUID collision, connection resolution won't work correctly! {}", m_port, m_uuid);
				}

				// there is a duplicate, so we need to deterministically decide which session is closed (and who closes it)
				if (m_uuid < peerUuid)
				{
					// choose this condition as the "owner" of this transaction, and take the address we connected to as truth
					// one of the iterators we have _must_ be the one this connection connected to, and it must be the same as
					// known_host
					if (duplicate_it->second->Address() != known_host)
					{
						std::swap(peer_it->second, duplicate_it->second);
					}
				}
				else
				{
					// otherwise, we aren't the owner and if the current session is the known host session, then we
					// want to replace it with the new one and transfer it to a drain
					if (duplicate_it->second->Address() == known_host)
					{
						std::swap(peer_it->second, duplicate_it->second);
					}
				}

				// we've either swapped into peer_it->second or it's the one we wanted to remove
				SPDLOG_TRACE("{}: Duplicate connection found, removing {}:{} ({})", m_port, peer_it->second->Address().IP, peer_it->second->Address().Port, peerPort);
				peer_it->second->Shutdown();
				m_duplicateSessions.emplace_back(std::move(peer_it->second));
			}
			else
			{
				// this is normal operation -- just put the session into the map
				m_sessions.emplace(known_host, std::move(peer_it->second));
			}

			// no matter what, remove the session from connectingSessions
			m_connectingSessions.erase(peer_it);
			AddProcess([this, known_host = std::move(known_host)]()
				{
					m_sessionConnectedHandler(known_host);
				});
		}
		else
		{
			// This can happen with congested network traffic, we end up receiving the same handshake twice (TCP is at-least-once)
			SPDLOG_WARN("{}: Got handshake from unknown session: {}:{} (peerPort: {})", m_port, fromAddress.IP, fromAddress.Port, peerPort);
		}
	}

	void PruneSessions()
	{
		auto do_disco = [this](NetworkAddress addr)
			{
				AddProcess([this, addr = std::move(addr)]
				{
					m_sessionDisconnectedHandler(addr);
				});
			};

		m_duplicateSessions.erase(std::remove_if(m_duplicateSessions.begin(), m_duplicateSessions.end(),
			[](std::unique_ptr<NetworkSession>& session)
			{
				if (session->IsOpen())
				{
					if (session->IsActive())
						session->Shutdown();
					else
						session->Close();

					return false;
				}

				return true;
			}),
			m_duplicateSessions.end());

		for (auto it = m_closingSessions.begin(); it != m_closingSessions.end();)
		{
			if (!it->second->IsOpen())
			{
				auto addr = it->first;
				it = m_closingSessions.erase(it);
				do_disco(addr);
			}
			else
			{
				if (it->second->IsActive())
					it->second->Shutdown();
				else
					it->second->Close();

				++it;
			}
		}

		// clear out any sessions that are no longer active
		for (auto it = m_sessions.begin(); it != m_sessions.end();)
		{
			if (!it->second->IsOpen())
			{
				auto addr = it->first;
				it = m_sessions.erase(it);
				do_disco(addr);
			}
			else if (!it->second->IsActive())
			{
				m_closingSessions.emplace(it->first, std::move(it->second));
				it = m_sessions.erase(it);
			}
			else
				++it;
		}

		for (auto it = m_connectingSessions.begin(); it != m_connectingSessions.end();)
		{
			if (!it->second->IsOpen())
			{
				auto addr = it->first;
				it = m_connectingSessions.erase(it);
				do_disco(addr);
			}
			else if (!it->second->IsActive())
			{
				m_closingSessions.emplace(it->first, std::move(it->second));
				it = m_connectingSessions.erase(it);
			}
			else
				++it;
		}

		//SPDLOG_DEBUG("RunOne() pending sessions: {} active sessions: {}", m_pendingSessions.size(), m_sessions.size());
	}

	void DrainSessions()
	{
		if (!m_sessions.empty() || !m_connectingSessions.empty() || !m_closingSessions.empty() || !m_duplicateSessions.empty())
		{
			for (const auto& [_, session] : m_connectingSessions)
				session->Shutdown();

			for (const auto& [_, session] : m_sessions)
				session->Shutdown();

			PruneSessions();
			auto timer = asio::steady_timer(m_ioContext);
			timer.expires_from_now(std::chrono::milliseconds(50));
			timer.async_wait([this](const std::error_code&) { DrainSessions(); });
		}
		else
			m_ioContext.stop();
	}

	void AddConnections()
	{
		std::unique_lock lock(m_hostMutex);

		if (!m_queuedConnects.empty())
		{
			// note that there is no unlock here because we are adding things to known hosts this entire loop
			for (const auto& address : m_queuedConnects)
			{
				if (m_sessions.find(address) == m_sessions.end() &&
					m_connectingSessions.find(address) == m_connectingSessions.end() &&
					m_pendingConnects.insert(address).second)
					Connect(address);
			}

			m_queuedConnects.clear();
		}
	}

	// TODO: leader logic will need to handle sending to peers that are leaders for other networks
	void ProcessWrites()
	{
		std::unique_lock lock(m_processMutex);

		if (!m_writeQueue.empty())
		{
			std::vector<std::tuple<peernetwork::MessageType, NetworkAddress, std::unique_ptr<uint8_t[]>, uint32_t>> writes;
			std::swap(writes, m_writeQueue);

			lock.unlock();

			for (auto& [message_type, address, payload, length] : writes)
			{
				peernetwork::Header header;
				header.set_type(message_type);

				SPDLOG_TRACE("{}: Sending message to {}:{} ({} bytes)",
					m_port, address.IP, address.Port, length);

				if (auto session = m_connectingSessions.find(address); session != m_connectingSessions.end())
				{
					session->second->Write(std::move(header), std::move(payload), length);
				}
				else if (auto session = m_sessions.find(address); session != m_sessions.end())
				{
					session->second->Write(std::move(header), std::move(payload), length);
				}
				else
				{
					if (m_leaderAddress)
					{
						auto session = m_sessions.find(*m_leaderAddress);
						if (session != m_sessions.end() && session->second)
						{
							header.set_address(address.IP);
							header.set_port(address.Port);
							session->second->Write(std::move(header), std::move(payload), length);
						}
						else
						{
							SPDLOG_WARN("{}: Attempted to send message to unknown leader: {}:{}", m_port, m_leaderAddress->IP, m_leaderAddress->Port);
						}
					}
					else
					{
						SPDLOG_WARN("{}: Attempted to send message to unknown peer: {}:{}", m_port, address.IP, address.Port);
					}
				}
			}
		}
	}

	void ProcessBroadcasts()
	{
		std::unique_lock lock(m_processMutex);

		if (!m_broadcastQueue.empty())
		{
			std::vector<std::tuple<peernetwork::MessageType, std::unique_ptr<uint8_t[]>, uint32_t>> broadcasts;
			std::swap(broadcasts, m_broadcastQueue);

			lock.unlock();

			for (auto& [message_type, payload, length] : broadcasts)
			{
				for (const auto& [_, session] : m_sessions)
				{
					peernetwork::Header header;
					header.set_type(message_type);

					auto payload_copy = std::make_unique<uint8_t[]>(length);
					memcpy(payload_copy.get(), payload.get(), length);

					session->Write(std::move(header), std::move(payload_copy), length);
				}
			}
		}
	}

	void AddProcess(std::function<void()>&& process)
	{
		std::unique_lock lock(m_processMutex);
		m_processQueue.push_back(std::move(process));

		m_requestProcessHandler();
	}
	
	void AddProcess(const NetworkAddress& address, NetworkMessagePtr message)
	{
		std::unique_lock lock(m_processMutex);
		m_receiveQueue.emplace_back(address, std::move(message));

		m_requestProcessHandler();
	}

	asio::io_context m_ioContext{};
	tcp::acceptor m_acceptor;
	std::atomic_bool m_running{ false };

	const uint16_t m_port;
	const std::string m_uuid;

	std::vector<NetworkAddress> m_queuedConnects;
	std::unordered_set<NetworkAddress> m_pendingConnects;
	std::unordered_set<NetworkAddress> m_knownHosts;
	std::mutex m_hostMutex; // we need to prevent situations where we try to connect to already discovered hosts

	std::unordered_map<NetworkAddress, std::unique_ptr<NetworkSession>> m_sessions;
	std::unordered_map<NetworkAddress, std::unique_ptr<NetworkSession>> m_closingSessions;
	std::unordered_map<NetworkAddress, std::unique_ptr<NetworkSession>> m_connectingSessions;
	std::vector<std::unique_ptr<NetworkSession>> m_duplicateSessions;
	std::mutex m_sessionMutex; // ensure we block while testing for duplicate sessions

	// TODO: need to revisit the leader logic
	std::optional<NetworkAddress> m_leaderAddress; // the leader is for communicating across networks

	std::thread m_thread;

	PeerMessageHandler m_receiveHandler;
	OnSessionConnectedHandler m_sessionConnectedHandler;
	OnSessionDisconnectedHandler m_sessionDisconnectedHandler;
	OnRequestProcessHandler m_requestProcessHandler;

	std::vector<std::function<void()>> m_processQueue;
	std::vector<std::pair<NetworkAddress, NetworkMessagePtr>> m_receiveQueue;
	std::vector<std::tuple<peernetwork::MessageType, NetworkAddress, std::unique_ptr<uint8_t[]>, uint32_t>> m_writeQueue;
	std::vector<std::tuple<peernetwork::MessageType, std::unique_ptr<uint8_t[]>, uint32_t>> m_broadcastQueue;
	std::mutex m_processMutex;
};

// map of port -> peer
static std::unordered_map<uint16_t, std::unique_ptr<NetworkPeer>> s_peers;

// This is for the leader logic
void NetworkMessage::Relay(uint16_t port)
{
	const auto peer = s_peers.find(port);
	if (peer != s_peers.end())
	{
		peer->second->Send(
			m_parsedHeader.type(),
			NetworkAddress{
				m_parsedHeader.address(),
				static_cast<uint16_t>(m_parsedHeader.port())
			},
			std::move(m_payload),
			m_length
		);
	}
	else
	{
		SPDLOG_WARN("Attempting to relay message with an uninitialized peer on port {}", port);
	}
}

NetworkPeerAPI::NetworkPeerAPI(uint16_t port)
	: m_port(port)
{}

NetworkPeerAPI NetworkPeerAPI::GetOrCreate(
	uint16_t port,
	PeerMessageHandler receive,
	OnSessionConnectedHandler connected,
	OnSessionDisconnectedHandler disconnected,
	OnRequestProcessHandler process)
{
	auto peer_it = s_peers.find(port);
	if (peer_it == s_peers.end())
	{
		// TODO: when leader logic is implemented, the relay to other peers would happen as a wrapper to these callbacks
		auto peer = std::make_unique<NetworkPeer>(
			port, std::move(receive), std::move(connected), std::move(disconnected), std::move(process));
		auto peer_port = peer->GetPort();
		peer_it = s_peers.emplace(peer_port, std::move(peer)).first;

		peer_it->second->Run();

		return NetworkPeerAPI(peer_port);
	}

	return NetworkPeerAPI(port);
}

void NetworkPeerAPI::Send(const std::string& address, uint16_t port, NetworkMessagePtr message) const
{
	// this lookup is O(1), and is done this way to decouple the implementation from the API
	const auto peer = s_peers.find(m_port);
	if (peer != s_peers.end())
	{
		auto payload = std::make_unique<uint8_t[]>(message->ByteSizeLong());
		message->SerializeToArray(payload.get(), static_cast<int>(message->ByteSizeLong()));
		peer->second->Send(
			peernetwork::Route,
			NetworkAddress{ address, port },
			std::move(payload),
			static_cast<uint32_t>(message->ByteSizeLong()));
	}
	else
	{
		SPDLOG_WARN("{}: Attempting to send message with an uninitialized peer", m_port);
	}
}

void NetworkPeerAPI::Broadcast(NetworkMessagePtr message) const
{
	SPDLOG_TRACE("{}: Attempting to broadcast message with peer", m_port);
	const auto peer = s_peers.find(m_port);
	if (peer != s_peers.end())
	{
		auto payload = std::make_unique<uint8_t[]>(message->ByteSizeLong());
		message->SerializeToArray(payload.get(), static_cast<int>(message->ByteSizeLong()));
		peer->second->Broadcast(peernetwork::Route, std::move(payload), static_cast<uint32_t>(message->ByteSizeLong()));
	}
	else
	{
		SPDLOG_WARN("{}: Attempting to broadcast message with an uninitialized peer", m_port);
	}
}

void mq::NetworkPeerAPI::Process() const
{
	const auto peer = s_peers.find(m_port);
	if (peer != s_peers.end())
		peer->second->Process();
}

void NetworkPeerAPI::Shutdown() const
{
	const auto peer = s_peers.find(m_port);
	if (peer != s_peers.end())
	{
		peer->second->Shutdown();
		s_peers.erase(peer);
	}
}

void NetworkPeerAPI::AddHost(const std::string& address, uint16_t port) const
{
	const auto peer = s_peers.find(m_port);
	if (peer != s_peers.end())
		peer->second->AddHost(NetworkAddress{ address, port });
}

void NetworkPeerAPI::RemoveHost(const std::string& address, uint16_t port) const
{
	const auto peer = s_peers.find(m_port);
	if (peer != s_peers.end())
		peer->second->RemoveHost(NetworkAddress{ address, port });
}

bool NetworkPeerAPI::HasHost(const std::string& address, uint16_t port) const
{
	const auto peer = s_peers.find(m_port);
	return peer != s_peers.end() && peer->second->HasHost(NetworkAddress{ address, port });
}
