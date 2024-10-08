// the number of the day is 7781 and 239.255.77.81

#pragma comment(lib, "rpcrt4.lib")

#include <queue>
#include <map>
#include <atomic>
#include <optional>

#include <rpc.h>

#include <spdlog/spdlog.h>

#include "Network.h"

// for settings
#include "MacroQuest.h"

#include "asio.hpp"

#include "Network.pb.h"

// TODO: Unit tests
// TODO: Leader test (later work, get internal networking done first):
//	-- leader gets PAT from router
//	-- only leader will have the external IP in hosts
//	-- does leader need to be an explicitly configured option? maybe can detect external IPs in hosts?
//	-- need to handle multiple peers trying to assume leadership
//	-- unknown IPs in not-leaders should all go to leader

// TODO: default sessions to use the same port as the peer

using asio::ip::tcp;

namespace mq {

using InternalMessageHandler = std::function<void(const peernetwork::Header&, const std::string&, uint16_t, std::unique_ptr<uint8_t[]>&&, size_t)>;

} // namespace mq

namespace mq {

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
	NetworkMessage(peernetwork::Header&& header, std::unique_ptr<uint8_t[]>&& payload, size_t length)
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
		m_parsedHeader.set_length(static_cast<uint32_t>(m_length));
		m_headerLength = m_parsedHeader.ByteSizeLong();
		m_headerLengthNetwork = static_cast<size_t>(htonll(m_headerLength));

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
		// This also assumes that size_t is the same on all systems, we can remove this assumption by using a proto for length
		std::vector<asio::const_buffer> buffers{
			asio::buffer(&m_headerLengthNetwork, sizeof(size_t)),
			asio::buffer(m_header.get(), m_headerLength)
		};

		if (m_payload && m_length > 0)
			buffers.emplace_back(asio::buffer(m_payload.get(), m_length));

		return buffers;
	}

	void Receive(const NetworkAddress& address, const InternalMessageHandler& handler)
	{
		handler(m_parsedHeader, address.IP, address.Port, std::move(m_payload), m_length);
	}

	void Relay(uint16_t port);

	size_t& HeaderLength() { return m_headerLength; }
	size_t& HeaderLengthNetwork() { return m_headerLengthNetwork; }
	uint8_t* Header() const { return m_header.get(); }
	const peernetwork::Header& ParsedHeader() const { return m_parsedHeader; }

	size_t& Length() { return m_length; }
	uint8_t* Payload() const { return m_payload.get(); }

private:
	size_t m_headerLength;
	size_t m_headerLengthNetwork;
	std::unique_ptr<uint8_t[]> m_header;

	peernetwork::Header m_parsedHeader;

	size_t m_length;
	std::unique_ptr<uint8_t[]> m_payload;
};

class NetworkSession
{
public:
	NetworkSession(uint16_t peer_port, tcp::socket&& socket, InternalMessageHandler receiveHandler)
		: m_socket(std::move(socket))
		, m_peerPort(peer_port)
		, m_address({m_socket.remote_endpoint().address().to_string(), m_socket.remote_endpoint().port()})
		, m_active(true)
		, m_receiveHandler(std::move(receiveHandler))
	{}

	NetworkSession() = delete;
	NetworkSession(const NetworkSession&) = delete;
	NetworkSession(NetworkSession&&) = delete;
	NetworkSession& operator=(const NetworkSession&) = delete;
	NetworkSession& operator=(NetworkSession&&) = delete;

	~NetworkSession()
	{
		SPDLOG_DEBUG("Session destroyed ({}:{})", m_address.IP, m_address.Port);

		Close();
	}

	void Shutdown()
	{
		if (m_active)
		{
			SPDLOG_DEBUG("Shutting down connection ({}:{})", m_address.IP, m_address.Port);
			std::error_code ec;
			(void)m_socket.shutdown(asio::socket_base::shutdown_both, ec);
			if (ec)
				SPDLOG_ERROR("Received error while shutting down socket {}: {}", ec.value(), ec.message());
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
		//SPDLOG_DEBUG("Session receiving");
		Read();
	}

	void Read()
	{
		auto message = std::make_shared<NetworkMessage>();
		asio::async_read(
			m_socket,
			asio::buffer(&message->HeaderLengthNetwork(), sizeof(size_t)),
			[this, message](const std::error_code& ec, size_t)
			{
				// TODO: Handle other connection errors with reconnect attempts
				// TODO: Write a function that handles this the same way every time (error checking)
				// TODO: check the size of the length also, should be sizeof(size_t)
				if (ec != asio::error::eof && // this is when the connection was closed remotely
					ec != asio::error::connection_reset && // this is if the socket is force closed remotely (when the peer is destroyed)
					ec != asio::error::shut_down) // this is when we shut down the socket locally
				{
					message->HeaderLength() = static_cast<size_t>(ntohll(message->HeaderLengthNetwork()));
					ReadHeaderLength(ec, message);
				}
				else Close();
			});
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

private:
	void ReadHeaderLength(const std::error_code& ec, const std::shared_ptr<NetworkMessage>& message)
	{
		if (ec)
		{
			SPDLOG_ERROR("Header length read error {}: {}", ec.value(), ec.message());
			Shutdown();
		}
		else if (message->HeaderLength() == 0)
		{
			SPDLOG_WARN("Got zero length header");
		}
		else
		{
			message->AllocateHeader();
			asio::async_read(
				m_socket,
				asio::buffer(message->Header(), message->HeaderLength()),
				[this, message](const std::error_code& ec, size_t) { ReadHeader(ec, message); });
		}
	}

	void ReadHeader(const std::error_code& ec, const std::shared_ptr<NetworkMessage>& message)
	{
		if (ec)
		{
			SPDLOG_ERROR("Header read error {}: {}", ec.value(), ec.message());
			Shutdown();
		}
		else
		{
			message->Init();

			if (message->ParsedHeader().has_address())
			{
				// this is a redirect
				// TODO: this should be RPC'able because we can look up the source in the actor infra and respond back to that -- test this assumption
				message->Relay(m_peerPort);
			}
			if (message->Length() > 0)
			{
				asio::async_read(
					m_socket,
					asio::buffer(message->Payload(), message->Length()),
					[this, message](const std::error_code& ec, size_t) { ReadPayload(ec, message); });
			}
			else
			{
				// if there is no length, no need to read from the wire
				ReadPayload(ec, message);
			}
		}
	}

	void ReadPayload(const std::error_code& ec, const std::shared_ptr<NetworkMessage>& message)
	{
		if (ec)
		{
			SPDLOG_ERROR("Payload read error {}: {}", ec.value(), ec.message());
			Shutdown();
		}
		else
		{
			if (m_receiveHandler != nullptr)
			{
				message->Receive(m_address, m_receiveHandler);
			}

			Read();
		}
	}

	void InternalWrite(const std::error_code& ec)
	{
		if (ec)
		{
			SPDLOG_ERROR("Message write error {}: {}", ec.value(), ec.message());
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
	bool m_active;

	InternalMessageHandler m_receiveHandler;
	LockedQueue<std::unique_ptr<NetworkMessage>> m_outgoing;

	// we need to make sure async_write doesn't get called while its running
	std::mutex m_writeMutex;
	bool m_writing = false;
};

class NetworkPeer
{
public:
	NetworkPeer() = delete;
	NetworkPeer(const NetworkPeer&) = delete;
	NetworkPeer(NetworkPeer&&) = delete;
	NetworkPeer& operator=(const NetworkPeer&) = delete;
	NetworkPeer& operator=(NetworkPeer&&) = delete;

	NetworkPeer(uint16_t port, PeerMessageHandler receiveHandler)
		: m_acceptor(m_ioContext, tcp::endpoint(tcp::v4(), port))
		, m_port(port)
		, m_receiveHandler(std::move(receiveHandler))
	{
		SPDLOG_INFO("Initializing peer on port {}", port);

		m_acceptor.listen();
		Accept();
	}

	~NetworkPeer()
	{
		SPDLOG_INFO("Removing peer on port {}", m_port);

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
					//SPDLOG_DEBUG("Starting peer thread");
					while (m_ioContext.run_one())
					{
						PruneSessions();
					}

					//SPDLOG_DEBUG("Peer thread stopping normally ({}:{})", m_address, m_port);
				}
				catch (std::exception& e)
				{
					SPDLOG_ERROR("Peer failed with exception (port {}): {}", m_port, e.what());
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
			[this, &address, port, socket, timer](const std::error_code& ec)
			{
				// pass off the connection to the session, if the session has failed then retry
				if (!AddSession(ec, std::move(*socket)))
				{
					// TODO: make retry time configurable
					timer->expires_from_now(std::chrono::seconds(2));
					timer->async_wait(
						[this, &address, port](const std::error_code& ec) { Connect(address, port); });
				}
			});
	}

	// TODO: This needs to also handle sending to peers that are leaders for other networks (possibly improve the map?)
	void Send(peernetwork::MessageType message_type, const NetworkAddress& address, std::unique_ptr<uint8_t[]>&& payload, size_t length)
	{
		peernetwork::Header header;
		header.set_type(message_type);

		auto session = m_sessions.find(address);
		if (session != m_sessions.end() && session->second)
		{
			session->second->Write(std::make_unique<NetworkMessage>(std::move(header), std::move(payload), length));
		}
		else
		{
			if (m_leaderAddress)
			{
				session = m_sessions.find(*m_leaderAddress);
				if (session != m_sessions.end() && session->second)
				{
					header.set_address(address.IP);
					header.set_port(address.Port);
					session->second->Write(std::make_unique<NetworkMessage>(std::move(header), std::move(payload), length));
				}
				else
				{
					SPDLOG_WARN("Attempted to send message to unknown leader: {}:{}", m_leaderAddress->IP, m_leaderAddress->Port);
				}
			}

			SPDLOG_WARN("Attempted to send message to unknown peer: {}:{}", address.IP, address.Port);
		}
	}

	void Broadcast(peernetwork::MessageType message_type, std::unique_ptr<uint8_t[]>&& payload, size_t length)
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
		if (m_knownHosts.insert(address).second)
			Connect(address.IP, address.Port);
	}

	void RemoveHost(const NetworkAddress& address)
	{
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
			// address().to_string() generically handles ipv4 vs ipv6, everything is agnostic to that
			auto session = std::make_unique<NetworkSession>(m_port, std::move(socket),
				[this](
					const peernetwork::Header& header,
					const std::string& address,
					uint16_t port,
					std::unique_ptr<uint8_t[]>&& payload,
					size_t length)
				{
					switch (header.type())
					{
					case peernetwork::Route:
						// handler is only called when the message is routed
						m_receiveHandler(address, port, std::move(payload), length);
						break;
					case peernetwork::Leader:
						// set the leader here (for when the session lookup fails)
						m_leaderAddress = NetworkAddress{ address, port };
						break;
					default:
						SPDLOG_WARN("Got unreconized header type {}", static_cast<uint32_t>(header.type()));
						break;
					}
				});

			auto [session_it, _] = m_sessions.emplace(
				session->Address(),
				std::move(session)
			);

			session_it->second->Receive();

			const auto endpoint = session_it->second->Endpoint();
			SPDLOG_INFO("Adding connection to endpoint {}:{} (total sessions {})",
				endpoint.address().to_string(), endpoint.port(),
				m_sessions.size());
		}
		else
		{
			SPDLOG_ERROR("Connection failed with ERR {}: {}", ec.value(), ec.message());
			// make sure to close the socket on failure
			if (socket.is_open()) socket.close();
		}

		return !ec;
	}

	void PruneSessions()
	{
		for (auto it = m_closingSessions.begin(); it != m_closingSessions.end();)
		{
			if (!it->second->IsOpen())
			{
				// always try to reconnect to hosts unless they have been removed
				if (m_knownHosts.find(it->first) != m_knownHosts.end())
					Connect(it->first.IP, it->first.Port);

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

	std::unordered_set<NetworkAddress> m_knownHosts;
	std::unordered_map<NetworkAddress, std::unique_ptr<NetworkSession>> m_sessions;
	std::unordered_map<NetworkAddress, std::unique_ptr<NetworkSession>> m_closingSessions;
	std::optional<NetworkAddress> m_leaderAddress;

	std::thread m_thread;

	PeerMessageHandler m_receiveHandler;
};

} // namespace mq

// map of port -> peer
static std::unordered_map<uint16_t, std::unique_ptr<NetworkPeer>> s_peers;

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

NetworkPeerAPI NetworkPeerAPI::GetOrCreate(uint16_t port, PeerMessageHandler receive)
{
	auto peer_it = s_peers.find(port);
	if (peer_it == s_peers.end())
	{
		// TODO: the receiver needs to forward to internal peers here (the map likely needs to be improved to handle network topography)
		peer_it = s_peers.emplace(port, std::make_unique<NetworkPeer>(
			port, [receive = std::move(receive)]
			(const std::string& address, uint16_t port, std::unique_ptr<uint8_t[]>&& payload, const size_t length)
			{ receive(address, port, std::move(payload), length); })).first;

		peer_it->second->Run();
	}

	return NetworkPeerAPI(port);
}

void NetworkPeerAPI::Send(const std::string& address, uint16_t port, std::unique_ptr<uint8_t[]>&& payload, size_t length) const
{
	// this lookup is O(1), and is done this way to decouple the implementation from the API
	const auto peer = s_peers.find(m_port);
	if (peer != s_peers.end())
	{
		peer->second->Send(peernetwork::Route, NetworkAddress{ address, port }, std::move(payload), length);
	}
	else
	{
		SPDLOG_WARN("Attempting to send message with an uninitialized peer on port {}", m_port);
	}
}

void NetworkPeerAPI::Broadcast(std::unique_ptr<uint8_t[]>&& payload, size_t length) const
{
	const auto peer = s_peers.find(m_port);
	if (peer != s_peers.end())
	{
		peer->second->Broadcast(peernetwork::Route, std::move(payload), length);
	}
	else
	{
		SPDLOG_WARN("Attempting to broadcast message with an uninitialized peer on port {}", m_port);
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

void Test()
{
	const auto peer1 = NetworkPeerAPI::GetOrCreate(7781,
		[](const std::string& address, uint16_t port, std::unique_ptr<uint8_t[]>&& message, const size_t length)
		{
			SPDLOG_DEBUG("Received message in peer1 of length {}: {}", length, std::string_view(reinterpret_cast<char*>(message.get()), length));
		});

	const auto peer2 = NetworkPeerAPI::GetOrCreate(8177,
		[](const std::string& address, uint16_t port, std::unique_ptr<uint8_t[]>&& message, const size_t length)
		{
			SPDLOG_DEBUG("Received message in peer2 of length {}: {}", length, std::string_view(reinterpret_cast<char*>(message.get()), length));
		});

	std::this_thread::sleep_for(std::chrono::seconds(2));

	peer1.AddHost("127.0.0.1", 8177);
	peer2.AddHost("127.0.0.1", 7781);
	std::this_thread::sleep_for(std::chrono::seconds(5));

	const std::string s("This is a test");
	auto t = std::make_unique<uint8_t[]>(s.length());
	memcpy(t.get(), s.data(), s.length());
	peer1.Send("127.0.0.1", 8177, std::move(t), s.length());

	std::this_thread::sleep_for(std::chrono::seconds(2));
}
