/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2024 MacroQuest Authors
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
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE

#pragma comment(lib, "rpcrt4.lib")

#include <queue>
#include <map>
#include <atomic>
#include <optional>

#include <rpc.h>

#include <spdlog/spdlog.h>

#include "Network.h"

#include "asio.hpp"

#include "Network.pb.h"

// TODO: Unit tests
// TODO: Leader test (later work, get internal networking done first):
//	-- leader gets PAT from router
//	-- only leader will have the external IP in hosts
//	-- does leader need to be an explicitly configured option? maybe can detect external IPs in hosts?
//	-- need to handle multiple peers trying to assume leadership
//	-- unknown IPs in not-leaders should all go to leader

// TODO: write networking RPC

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
	NetworkMessage() : m_headerLength(0), m_headerLengthNetwork(0), m_length(0) {}

	NetworkMessage(const NetworkMessage&) = delete;
	NetworkMessage(NetworkMessage&&) = delete;
	NetworkMessage& operator=(const NetworkMessage&) = delete;
	NetworkMessage& operator=(NetworkMessage&&) = delete;

	~NetworkMessage() = default;

	void InitHeader()
	{
		m_parsedHeader.set_length(m_length);
		m_headerLength = m_parsedHeader.ByteSizeLong();
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
	const peernetwork::Header& ParsedHeader() const { return m_parsedHeader; }

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
	{}

	NetworkSession() = delete;
	NetworkSession(const NetworkSession&) = delete;
	NetworkSession(NetworkSession&&) = delete;
	NetworkSession& operator=(const NetworkSession&) = delete;
	NetworkSession& operator=(NetworkSession&&) = delete;

	~NetworkSession()
	{
		SPDLOG_DEBUG("{}: Session destroyed ({}:{})", m_peerPort, m_address.IP, m_address.Port);

		Close();
	}

	void Shutdown()
	{
		if (m_active)
		{
			SPDLOG_DEBUG("{}: Shutting down connection ({}:{})", m_peerPort, m_address.IP, m_address.Port);
			std::error_code ec;
			(void)m_socket.shutdown(asio::socket_base::shutdown_both, ec);
			if (ec)
				SPDLOG_ERROR("{}: Received error while shutting down socket {}: {}", m_peerPort, ec.value(), ec.message());
			m_active = false;
		}
	}

	void Close()
	{
		if (m_active)
			m_active = false;

		if (m_socket.is_open())
			m_socket.close();
	}

	void Receive()
	{
		SPDLOG_TRACE("{}: Session receiving", m_peerPort);
		Read();
	}

	void Write(std::unique_ptr<NetworkMessage> message)
	{
		std::unique_lock lock(m_writeMutex);
		m_outgoing.Push(std::move(message));

		// kick off the loop if it's not running
		if (!m_writing)
		{
			// InternalWrite will attempt to lock
			lock.unlock();
			InternalWrite(std::error_code());
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
	void Read()
	{
		// ASIO is designed around either shared pointers or some externally controlled pointer
		// the simpler solution for now is a shared_ptr but it would reduce overhead (by how much?)
		// to use an external buffer. Using a reset method means we don't have to allocate for each
		// message as well.
		m_messageBuffer->Reset();
		asio::async_read(
			m_socket,
			asio::buffer(&m_messageBuffer->HeaderLengthNetwork(), sizeof(uint32_t)),
			[this](const std::error_code& ec, size_t)
			{
				// TODO: Handle other connection errors with reconnect attempts
				// TODO: Write a function that handles this the same way every time (error checking)
				// TODO: check the size of the length also, should be sizeof(uint32_t)
				if (ec != asio::error::eof && // this is when the connection was closed remotely
					ec != asio::error::connection_reset && // this is if the socket is force closed remotely (when the peer is destroyed)
					ec != asio::error::shut_down) // this is when we shut down the socket locally
				{
					m_messageBuffer->HeaderLength() = ntohl(m_messageBuffer->HeaderLengthNetwork());
					SPDLOG_TRACE("{}: Detected message ({} header length)",
						m_peerPort, m_messageBuffer->HeaderLength());

					ReadHeaderLength(ec);
				}
				else Close();
			});
	}

	void ReadHeaderLength(const std::error_code& ec)
	{
		if (ec)
		{
			SPDLOG_ERROR("{}: Header length read error {}: {}", m_peerPort, ec.value(), ec.message());
			Shutdown();
		}
		else if (m_messageBuffer->HeaderLength() == 0)
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
				[this](const std::error_code& ec, size_t) { ReadHeader(ec); });
		}
	}

	void ReadHeader(const std::error_code& ec)
	{
		if (ec)
		{
			SPDLOG_ERROR("{}: Header read error {}: {}", m_peerPort, ec.value(), ec.message());
			Shutdown();
		}
		else
		{
			m_messageBuffer->Init();

			if (m_messageBuffer->ParsedHeader().has_address())
			{
				// this is a redirect
				// TODO: this should be RPC'able because we can look up the source in the actor infra and respond back to that -- test this assumption
				// TODO: how does this even work? We don't re-call Read() -- this needs to be thought about... is it even needed?
				m_messageBuffer->Relay(m_peerPort);
			}
			if (m_messageBuffer->Length() > 0)
			{
				asio::async_read(
					m_socket,
					asio::buffer(m_messageBuffer->Payload(), m_messageBuffer->Length()),
					[this](const std::error_code& ec, size_t) { ReadPayload(ec); });
			}
			else
			{
				// if there is no length, no need to read from the wire
				ReadPayload(ec);
			}
		}
	}

	void ReadPayload(const std::error_code& ec)
	{
		if (ec)
		{
			SPDLOG_ERROR("{}: Payload read error {}: {}", m_peerPort, ec.value(), ec.message());
			Shutdown();
		}
		else
		{
			SPDLOG_TRACE("{}: Received message from {}:{} ({} bytes)",
				m_peerPort, m_knownAddress.IP, m_knownAddress.Port, m_messageBuffer->Length());

			if (m_receiveHandler != nullptr)
			{
				m_messageBuffer->Receive(this, m_receiveHandler);
			}

			Read();
		}
	}

	void InternalWrite(const std::error_code& ec)
	{
		if (ec)
		{
			SPDLOG_ERROR("{}: Message write error {}: {}", m_peerPort, ec.value(), ec.message());
			Shutdown();
		}
		else
		{
			std::unique_lock lock(m_writeMutex);
			if (m_outgoing.Empty())
			{
				m_writing = false;
			}
			else
			{
				m_writing = true;
				const std::unique_ptr message(m_outgoing.Pop());

				// explicitly unlock before we start the next async_write
				lock.unlock();
				asio::async_write(
					m_socket,
					message->Buffers(),
					[this](const std::error_code& ec, size_t) { InternalWrite(ec); });
			}
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

	// we need to make sure async_write doesn't get called while its running
	std::mutex m_writeMutex;
	bool m_writing = false;
};

static std::string CreateUUID()
{
	UUID uuid;
	::UuidCreate(&uuid);
	char* uuid_str;
	::UuidToStringA(&uuid, reinterpret_cast<RPC_CSTR*>(&uuid_str));
	std::string return_uuid(uuid_str);
	::RpcStringFreeA(reinterpret_cast<RPC_CSTR*>(&uuid_str));
	return return_uuid;
}

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
		OnSessionDisconnectedHandler disconnectedHandler)
		: m_acceptor(m_ioContext, tcp::endpoint(tcp::v4(), port))
		, m_port(port)
		, m_uuid(CreateUUID())
		, m_receiveHandler(std::move(receiveHandler))
		, m_sessionConnectedHandler(std::move(connectedHandler))
		, m_sessionDisconnectedHandler(std::move(disconnectedHandler))
	{
		SPDLOG_INFO("{}: Initializing peer", port);

		m_acceptor.listen();
		Accept();
	}

	~NetworkPeer()
	{
		SPDLOG_INFO("{}: Removing peer", m_port);

		if (m_thread.joinable())
		{
			m_ioContext.stop();
			m_thread.join();
		}
	}

	void Run()
	{
		m_thread = std::thread([this]()
			{
				try
				{
					SPDLOG_TRACE("{}: Starting peer thread", m_port);
					while (m_ioContext.run_one())
					{
						PruneSessions();
					}

					SPDLOG_TRACE("{}: Peer thread stopping normally", m_port);
				}
				catch (std::exception& e)
				{
					SPDLOG_ERROR("{}: Peer failed with exception {}", m_port, e.what());
				}
			});
	}

	void Connect(const std::string& address, uint16_t port)
	{
		auto socket = std::make_shared<tcp::socket>(m_acceptor.get_executor());
		auto timer = std::make_shared<asio::steady_timer>(m_ioContext);
		const tcp::endpoint endpoint(asio::ip::address::from_string(address), port);

		socket->async_connect(
			endpoint,
			[this, address, port, socket, timer](const std::error_code& ec)
			{
				SPDLOG_TRACE("{}: Connect attempt with local endpoint {}:{} and remote endpoint {}:{}",
					m_port,
					socket->local_endpoint().address().to_string(), socket->local_endpoint().port(),
					socket->remote_endpoint().address().to_string(), socket->remote_endpoint().port());

				// pass off the connection to the session, if the session has failed then retry
				if (!AddSession(ec, std::move(*socket)))
				{
					// TODO: make retry time configurable
					timer->expires_from_now(std::chrono::seconds(2));
					timer->async_wait(
						[this, address, port](const std::error_code& ec) { Connect(address, port); });
				}
			});
	}

	// TODO: This needs to also handle sending to peers that are leaders for other networks (possibly improve the map?)
	void Send(peernetwork::MessageType message_type, const NetworkAddress& address, std::unique_ptr<uint8_t[]>&& payload, uint32_t length)
	{
		peernetwork::Header header;
		header.set_type(message_type);

		SPDLOG_TRACE("{}: Sending message to {}:{} ({} bytes)",
			m_port, address.IP, address.Port, length);

		if (auto session = m_connectingSessions.find(address); session != m_connectingSessions.end())
		{
			session->second->Write(std::make_unique<NetworkMessage>(std::move(header), std::move(payload), length));
		}
		else if (auto session = m_sessions.find(address); session != m_sessions.end())
		{
			session->second->Write(std::make_unique<NetworkMessage>(std::move(header), std::move(payload), length));
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
					session->second->Write(std::make_unique<NetworkMessage>(std::move(header), std::move(payload), length));
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

	void Broadcast(peernetwork::MessageType message_type, std::unique_ptr<uint8_t[]>&& payload, uint32_t length)
	{
		for (const auto& [_, session] : m_sessions)
		{
			peernetwork::Header header;
			header.set_type(message_type);

			auto payload_copy = std::make_unique<uint8_t[]>(length);
			memcpy(payload_copy.get(), payload.get(), length);

			session->Write(std::make_unique<NetworkMessage>(std::move(header), std::move(payload_copy), length));
		}
	}

	void AddHost(const NetworkAddress& address)
	{
		std::unique_lock lock(m_hostMutex);
		if (m_knownHosts.insert(address).second)
			Connect(address.IP, address.Port);
	}

	void RemoveHost(const NetworkAddress& address)
	{
		std::unique_lock lock(m_hostMutex);
		m_knownHosts.erase(address);
		const auto session = m_sessions.find(address);
		if (session != m_sessions.end())
		{
			// This will prune the session gracefully
			session->second->Shutdown();
		}
	}

	bool HasHost(const NetworkAddress& address)
	{
		return m_knownHosts.find(address) != m_knownHosts.end();
	}

private:

	void Accept()
	{
		m_acceptor.async_accept(
			[this](const std::error_code& ec, tcp::socket socket)
			{
				SPDLOG_TRACE("{}: Accepting connection with local endpoint {}:{} and remote endpoint {}:{}",
					m_port,
					socket.local_endpoint().address().to_string(), socket.local_endpoint().port(),
					socket.remote_endpoint().address().to_string(), socket.remote_endpoint().port());

				// pass off the connection to the session
				AddSession(ec, std::move(socket));

				// we always want to continue to listen, regardless of the condition of the session spawned
				Accept();
			});
	}

	bool AddSession(const std::error_code& ec, tcp::socket&& socket)
	{
		if (!ec)
		{
			auto session = std::make_unique<NetworkSession>(m_port, std::move(socket),
				[this](
					const peernetwork::Header& header,
					NetworkSession* session,
					std::unique_ptr<uint8_t[]>&& payload,
					uint32_t length)
				{
					switch (header.type())
					{
					case peernetwork::Route:
						// handler is only called when the message is routed
						m_receiveHandler(session->KnownAddress(), std::move(payload), length);
						break;
					case peernetwork::Leader:
						// set the leader here (for when the session lookup fails)
						m_leaderAddress = session->KnownAddress();
						break;
					case peernetwork::Handshake:
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
				});

			auto [session_it, _] = m_connectingSessions.emplace(
				session->Address(),
				std::move(session)
			);

			session_it->second->Receive();

			const auto endpoint = session_it->second->Endpoint();
			SPDLOG_INFO("{}: Adding connection to endpoint {}:{} (total sessions {})",
				m_port, endpoint.address().to_string(), endpoint.port(),
				m_sessions.size());

			peernetwork::Identity id;
			id.set_uuid(m_uuid);
			id.set_port(m_port);

			auto payload = std::make_unique<uint8_t[]>(id.ByteSizeLong());
			id.SerializeToArray(payload.get(), id.ByteSizeLong());

			Send(peernetwork::MessageType::Handshake, session_it->second->Address(), std::move(payload), id.ByteSizeLong());
		}
		else
		{
			SPDLOG_ERROR("{}: Connection failed with ERR {}: {}", m_port, ec.value(), ec.message());
			// make sure to close the socket on failure
			if (socket.is_open()) socket.close();
		}

		return !ec;
	}

	void ResolveHandshake(const NetworkAddress& fromAddress, const std::string& peerUuid, uint16_t peerPort)
	{
		// we always want the remote peer's configured port to be in the known host set, but depending on
		// the order of connection, we could have a connection with a generated port as the remote so
		// we have to map the session to the _remote_ port, and we need to deterministically choose which
		// shared session is the correct one

		SPDLOG_TRACE("{}: Received a handshake from {}:{} ({})", m_port, fromAddress.IP, peerPort, peerUuid);
		// the session we receive the handshake from should always be stored in this map
		auto peer_it = m_connectingSessions.find(fromAddress);
		// we need to find the session with the remote endpoint that matches 
		if (peer_it != m_connectingSessions.end())
		{
			NetworkAddress known_host{ fromAddress.IP, peerPort }; // this is the address we want to expose (with the configured port)
			peer_it->second->UpdateFromHandshake(known_host, peerUuid);

			{
				std::unique_lock lock(m_hostMutex);
				m_knownHosts.emplace(known_host);
			}

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
				SPDLOG_INFO("{}: Duplicate connection found, removing {}:{}", m_port, peer_it->second->Address().IP, peer_it->second->Address().Port);
				peer_it->second->Shutdown();
				m_duplicateSessions.emplace_back(std::move(peer_it->second));
			}
			else
			{
				// this is normal operation -- just put the session into the map
				m_sessions.emplace(known_host, std::move(peer_it->second));
			}

			m_connectingSessions.erase(peer_it);
			m_sessionConnectedHandler(known_host);
		}
		else
		{
			// we should be guaranteed that the session exists because this message is the result of an active session
			SPDLOG_WARN("{}: Got handshake from unknown session: {}:{} (peerPort: {})", m_port, fromAddress.IP, fromAddress.Port, peerPort);
		}
	}

	void PruneSessions()
	{
		m_duplicateSessions.erase(std::remove_if(m_duplicateSessions.begin(), m_duplicateSessions.end(),
			[](std::unique_ptr<NetworkSession>& session)
			{ return !session->IsOpen(); }),
			m_duplicateSessions.end());

		for (auto it = m_closingSessions.begin(); it != m_closingSessions.end();)
		{
			if (!it->second->IsOpen())
			{
				m_sessionDisconnectedHandler(it->first);
				it = m_closingSessions.erase(it);
			}
			else
				++it;
		}

		// clear out any sessions that are no longer active
		for (auto it = m_sessions.begin(); it != m_sessions.end();)
		{
			if (!it->second->IsActive())
			{
				m_closingSessions.emplace(it->first, std::move(it->second));
				it = m_sessions.erase(it);
			}
			else
				++it;
		}

		//SPDLOG_DEBUG("RunOne() pending sessions: {} active sessions: {}", m_pendingSessions.size(), m_sessions.size());
	}

	asio::io_context m_ioContext{};
	tcp::acceptor m_acceptor;

	const uint16_t m_port;
	const std::string m_uuid;

	std::unordered_set<NetworkAddress> m_knownHosts;
	std::mutex m_hostMutex; // we need to prevent situations where we try to connect to already discovered hosts

	std::unordered_map<NetworkAddress, std::unique_ptr<NetworkSession>> m_sessions;
	std::unordered_map<NetworkAddress, std::unique_ptr<NetworkSession>> m_closingSessions;
	std::unordered_map<NetworkAddress, std::unique_ptr<NetworkSession>> m_connectingSessions;
	std::vector<std::unique_ptr<NetworkSession>> m_duplicateSessions;

	//std::unordered_map<uint32_t, MessageResponseCallback> m_rpcRequests;

	// TODO: need to revisit the leader logic
	std::optional<NetworkAddress> m_leaderAddress; // the leader is for communicating across networks

	std::thread m_thread;

	PeerMessageHandler m_receiveHandler;
	OnSessionConnectedHandler m_sessionConnectedHandler;
	OnSessionDisconnectedHandler m_sessionDisconnectedHandler;
};

// map of port -> peer
static std::unordered_map<uint16_t, std::unique_ptr<NetworkPeer>> s_peers;

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

NetworkPeerAPI NetworkPeerAPI::GetOrCreate(uint16_t port, PeerMessageHandler receive, OnSessionConnectedHandler connected, OnSessionDisconnectedHandler disconnected)
{
	auto peer_it = s_peers.find(port);
	if (peer_it == s_peers.end())
	{
		// TODO: the receiver needs to forward to internal peers here (the map likely needs to be improved to handle network topography)
		peer_it = s_peers.emplace(port, std::make_unique<NetworkPeer>(
			port, std::move(receive), std::move(connected), std::move(disconnected))).first;

		peer_it->second->Run();
	}

	return NetworkPeerAPI(port);
}

void NetworkPeerAPI::Send(const std::string& address, uint16_t port, std::unique_ptr<uint8_t[]>&& payload, uint32_t length) const
{
	// this lookup is O(1), and is done this way to decouple the implementation from the API
	const auto peer = s_peers.find(m_port);
	if (peer != s_peers.end())
	{
		peer->second->Send(peernetwork::Route, NetworkAddress{ address, port }, std::move(payload), length);
	}
	else
	{
		SPDLOG_WARN("{}: Attempting to send message with an uninitialized peer", m_port);
	}
}

void NetworkPeerAPI::Broadcast(std::unique_ptr<uint8_t[]>&& payload, uint32_t length) const
{
	SPDLOG_TRACE("{}: Attempting to broadcast message with peer", m_port);
	const auto peer = s_peers.find(m_port);
	if (peer != s_peers.end())
	{
		peer->second->Broadcast(peernetwork::Route, std::move(payload), length);
	}
	else
	{
		SPDLOG_WARN("{}: Attempting to broadcast message with an uninitialized peer", m_port);
	}
}

void NetworkPeerAPI::Shutdown() const
{
	const auto peer = s_peers.find(m_port);
	if (peer != s_peers.end())
		s_peers.erase(peer);
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
