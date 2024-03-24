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

using asio::ip::tcp;

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
	NetworkMessage()
		: m_headerLength(0)
		, m_length(0)
	{}

	// empty message, just a header
	explicit NetworkMessage(peernetwork::Header header)
		: m_parsedHeader(std::move(header))
		, m_length(0)
	{
		InitHeader();
	}

	// full message
	template <typename T>
	NetworkMessage(peernetwork::Header header, const T& data)
		: m_parsedHeader(std::move(header))
		, m_length(data.ByteSizeLong())
	{
		InitHeader();

		if (m_length > 0)
		{
			m_payload = std::make_unique<uint8_t[]>(m_length);
			data.SerializeToArray(m_payload.get(), static_cast<int>(m_length));
		}
	}

	NetworkMessage(const NetworkMessage&) = delete;
	NetworkMessage(NetworkMessage&&) = delete;
	NetworkMessage& operator=(const NetworkMessage&) = delete;
	NetworkMessage& operator=(NetworkMessage&&) = delete;

	~NetworkMessage() = default;

	void InitHeader()
	{
		m_parsedHeader.set_length(static_cast<uint32_t>(m_length));
		m_headerLength = m_parsedHeader.ByteSizeLong();

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
			asio::buffer(&m_headerLength, sizeof(size_t)),
			asio::buffer(m_header.get(), m_headerLength)
		};

		if (m_payload && m_length > 0)
			buffers.emplace_back(asio::buffer(m_payload.get(), m_length));

		return buffers;
	}

	template <typename T>
	T Parse()
	{
		T obj;
		if (m_payload && m_length > 0)
			obj.ParseFromArray(m_payload.get(), static_cast<int>(m_length));

		return obj;
	}

	size_t& HeaderLength() { return m_headerLength; }
	uint8_t* Header() const { return m_header.get(); }
	peernetwork::Header ParsedHeader() { return m_parsedHeader; }

	size_t Length() const { return m_length; }
	uint8_t* Payload() const { return m_payload.get(); }

private:
	size_t m_headerLength;
	std::unique_ptr<uint8_t[]> m_header;

	peernetwork::Header m_parsedHeader;

	size_t m_length;
	std::unique_ptr<uint8_t[]> m_payload;
};

class NetworkSession
{
public:
	NetworkSession(tcp::socket socket, NetworkPeer& peer, const std::function<void(const peernetwork::Header&, uint8_t*)>& receiveHandler)
		: m_peer(peer)
		, m_socket(std::move(socket))
		, m_active(true)
		, m_uuid(NetworkPeer::CreateUUID())
		, m_receiveHandler(receiveHandler)
	{}

	NetworkSession(const NetworkSession&) = delete;
	NetworkSession(NetworkSession&&) = delete;
	NetworkSession& operator=(const NetworkSession&) = delete;
	NetworkSession& operator=(NetworkSession&&) = delete;

	~NetworkSession()
	{
		SPDLOG_DEBUG("Session destroyed ({})", m_uuid);
		Close();
	}

	void Shutdown()
	{
		if (m_active)
		{
			SPDLOG_DEBUG("Shutting down connection ({})", m_uuid);
			std::error_code ec;
			(void)m_socket.shutdown(asio::socket_base::shutdown_both, ec);
			if (ec)
				SPDLOG_ERROR("Received error while shutting down socket {}: {}", ec.value(), ec.message());
			m_active = false;
		}
	}

	void Close()
	{

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
			asio::buffer(&message->HeaderLength(), sizeof(size_t)),
			[this, message](const std::error_code& ec, size_t size)
			{
				// TODO: Handle other connection errors with reconnect attempts
				// TODO: Write a function that handles this the same way every time (error checking)
				if (ec != asio::error::eof && // this is when the connection was closed remotely
					ec != asio::error::connection_reset && // this is if the socket is force closed remotely (when the peer is destroyed)
					ec != asio::error::shut_down) // this is when we shut down the socket locally
					ReadHeaderLength(ec, message);
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
	const std::string& UUID() { return m_uuid; }

	void SetPeerID(const peernetwork::Identification& id) { m_peerId = id; }

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
			SPDLOG_WARN("Got zero Length Header");
		}
		else
		{
			message->AllocateHeader();

			asio::async_read(
				m_socket,
				asio::buffer(message->Header(), message->HeaderLength()),
				[this, message](const std::error_code& ec, size_t)
				{ ReadHeader(ec, message); });
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
			// header length and header data read, init the payload
			message->Init();

			if (message->Length() > 0)
			{
				asio::async_read(
					m_socket,
					asio::buffer(message->Payload(), message->Length()),
					[this, message](const std::error_code& ec, size_t) { ReadPayload(ec, message); });
			}
			else
			{
				// if there is no length, there is no need to read from the wire
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
			// special case the UUID handshake
			if (message->ParsedHeader().type() == peernetwork::ID)
			{
				m_peer.ReceiveUUID(m_uuid, m_socket.local_endpoint().port(), message->Parse<peernetwork::Identification>());
			}
			else if (m_receiveHandler != nullptr)
			{
				m_receiveHandler(message->ParsedHeader(), message->Payload());
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
	NetworkPeer& m_peer;
	tcp::socket m_socket;
	bool m_active;
	std::string m_uuid;

	peernetwork::Identification m_peerId;

	std::function<void(const peernetwork::Header&, uint8_t*)> m_receiveHandler;
	LockedQueue<std::unique_ptr<NetworkMessage>> m_outgoing;

	// we need to make sure async_write doesn't get called while its running
	std::mutex m_writeMutex;
	bool m_writing = false;
};

NetworkPeer::NetworkPeer(const std::string& address, uint16_t port, const std::function<void(const peernetwork::Header&, uint8_t*)>& handler)
	: m_acceptor(m_ioContext, tcp::endpoint(tcp::v4(), port))
	, m_address(address)
	, m_port(port)
	, m_uuid(CreateUUID())
	, m_receiveHandler(handler)
{
	SPDLOG_INFO("Initializing peer at {}:{} with UUID {}", address, port, m_uuid);

	m_acceptor.listen();
	Accept();
}

NetworkPeer::~NetworkPeer()
{
	SPDLOG_INFO("Removing peer {}:{}", m_address, m_port);

	if (m_thread.joinable())
	{
		m_ioContext.stop();
		m_thread.join();
	}
}

void NetworkPeer::TestSend(const std::string& message)
{
	peernetwork::Header header;
	header.set_type(peernetwork::Route);

	peernetwork::RoutedMessage routed;
	routed.set_header(""); // testing doesn't require a header here
	routed.set_payload(message);

	for (auto& [_, session] : m_sessions)
	{
		auto msg = std::make_unique<NetworkMessage>(header, routed);
		session->Write(std::move(msg));
	}
}

void NetworkPeer::Run()
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
				SPDLOG_ERROR("Peer failed with exception ({}:{}): {}", m_address, m_port, e.what());
			}
		});
}

void NetworkPeer::Connect(const std::string& address, uint16_t port)
{
	// TODO: when a disconnect happens and we should reconnect, trigger a move from sessions into pendingHosts
	//       and then call Connect
	auto socket = std::make_shared<tcp::socket>(m_acceptor.get_executor());
	auto timer = std::make_shared<asio::steady_timer>(m_ioContext);
	const tcp::endpoint endpoint(asio::ip::address::from_string(address), port);

	socket->async_connect(
		endpoint,
		[this, &address, port, socket, timer](const std::error_code& ec)
		{
			// pass off the connection to the session, if the session has failed then retry
			if (!StageSession(ec, std::move(*socket)))
			{
				// TODO: make retry time configurable
				timer->expires_from_now(std::chrono::seconds(2));
				timer->async_wait(
					[this, &address, port](const std::error_code& ec) { Connect(address, port); });
			}
		});
}

void NetworkPeer::Accept()
{
	m_acceptor.async_accept(
		[this](const std::error_code& ec, tcp::socket socket)
		{
			// pass off the connection to the session
			StageSession(ec, std::move(socket));

			// we always want to continue to listen, regardless of the condition of the session spawned
			Accept();
		});
}

bool NetworkPeer::StageSession(const std::error_code& ec, tcp::socket&& socket)
{
	if (!ec)
	{
		auto session = std::make_unique<NetworkSession>(std::move(socket), *this, m_receiveHandler);
		const std::string& uuid = session->UUID();
		auto [session_it, _] = m_pendingSessions.emplace(uuid, std::move(session));

		session_it->second->Receive();
		SendUUID(session_it->second);

		const auto endpoint = session_it->second->Endpoint();
		SPDLOG_INFO("Staging connection to endpoint {}:{} (total staged {}) {}",
			endpoint.address().to_string(), endpoint.port(),
			m_pendingSessions.size(), uuid);
	}
	else
	{
		SPDLOG_ERROR("Connection failed with ERR {}: {}", ec.value(), ec.message());
		// make sure to close the socket on failure
		if (socket.is_open()) socket.close();
	}

	// TODO: some error conditions shouldn't warrant a retry
	return !ec;
}

void NetworkPeer::PruneSessions()
{
	m_closingSessions.remove_if([](const std::unique_ptr<NetworkSession>& session) { return !session->IsOpen(); });

	// clear out any sessions that are no longer active
	for (auto it = m_pendingSessions.begin(); it != m_pendingSessions.end();)
	{
		if (!it->second->IsActive())
		{
			m_closingSessions.emplace_back(std::move(it->second));
			it = m_pendingSessions.erase(it);
		}
		else
			++it;
	}

	for (auto it = m_sessions.begin(); it != m_sessions.end();)
	{
		if (!it->second->IsActive())
		{
			m_closingSessions.emplace_back(std::move(it->second));
			it = m_sessions.erase(it);
		}
		else
			++it;
	}

	//SPDLOG_DEBUG("RunOne() pending sessions: {} active sessions: {}", m_pendingSessions.size(), m_sessions.size());
}

void NetworkPeer::SendUUID(const std::unique_ptr<NetworkSession>& session)
{
	peernetwork::Header header;
	header.set_type(peernetwork::ID);

	peernetwork::Identification id;
	id.set_uuid(m_uuid);
	id.set_host(m_address);
	id.set_port(m_port);

	auto msg = std::make_unique<NetworkMessage>(header, id);

	session->Write(std::move(msg));
}

void NetworkPeer::ReceiveUUID(const std::string& pending_id, uint16_t local_port, const peernetwork::Identification& id)
{
	// if we are no longer pending, don't worry about it (not sure whether this should happen though)
	const auto pending_it = m_pendingSessions.find(pending_id);
	if (pending_it != m_pendingSessions.end())
	{
		pending_it->second->SetPeerID(id);

		// we can use port to differentiate here. If we connected, we would have opened a new port
		const auto existing_it = m_sessions.find(id.uuid());
		if ((id.uuid() < m_uuid && local_port == m_port) ||
			(id.uuid() > m_uuid && local_port != m_port))
		{
			if (existing_it != m_sessions.end())
			{
				//SPDLOG_DEBUG("Removing existing duplicate connection ({}) {} < {}", pending_id, uuid, m_uuid);
				// if we don't erase this here, the read loop continues after we lose the ref to the pointer
				existing_it->second->Shutdown();
				m_closingSessions.emplace_back(std::move(existing_it->second));
				m_sessions.erase(existing_it);
			}

			m_sessions.emplace(id.uuid(), std::move(pending_it->second));
		}
		else if (existing_it == m_sessions.end())
		{
			m_sessions.emplace(id.uuid(), std::move(pending_it->second));
		}
		else
		{
			//SPDLOG_DEBUG("Removing new duplicate connection ({}) {} < {}", pending_id, uuid, m_uuid);
			pending_it->second->Shutdown();
			m_closingSessions.emplace_back(std::move(pending_it->second));
		}

		// erase this no matter what
		m_pendingSessions.erase(pending_it);
	}
}

std::string NetworkPeer::CreateUUID()
{
	UUID uuid;
	::UuidCreate(&uuid);
	char* uuid_str;
	::UuidToStringA(&uuid, reinterpret_cast<RPC_CSTR*>(&uuid_str));
	std::string return_uuid(uuid_str);
	::RpcStringFreeA(reinterpret_cast<RPC_CSTR*>(&uuid_str));
	return return_uuid;
}

void Test()
{
	auto hosts = []()
		{
			auto hosts_enabled = GetPrivateProfileKeyValues("NetworkHosts", internal_paths::MQini);
			hosts_enabled.erase(std::remove_if(hosts_enabled.begin(), hosts_enabled.end(),
				[](const std::pair<std::string, std::string>& pair) { return !ci_equals("1", pair.second); }),
				hosts_enabled.end());

			std::vector<std::string> hosts(hosts_enabled.size());
			std::transform(hosts_enabled.begin(), hosts_enabled.end(), std::back_inserter(hosts),
				[](const std::pair<std::string, std::string>& pair) { return pair.first; });

			return hosts;
		}();

	NetworkPeer peer1("127.0.0.1", 7781, [](const peernetwork::Header& header, const uint8_t* message)
		{
			peernetwork::RoutedMessage data;
			data.ParseFromArray(message, static_cast<int>(header.length()));
			SPDLOG_DEBUG("Received message in peer1 of length {}: {}", header.length(), data.payload());
		});

	NetworkPeer peer2("127.0.0.1", 8177, [](const peernetwork::Header& header, const uint8_t* message)
		{
			peernetwork::RoutedMessage data;
			data.ParseFromArray(message, static_cast<int>(header.length()));
			SPDLOG_DEBUG("Received message in peer2 of length {}: {}", header.length(), data.payload());
		});

	peer1.Run();
	peer2.Run();
	std::this_thread::sleep_for(std::chrono::seconds(2));

	peer1.Connect("127.0.0.1", 8177);
	peer2.Connect("127.0.0.1", 7781);
	std::this_thread::sleep_for(std::chrono::seconds(5));

	peer1.TestSend("This is a test");

	std::this_thread::sleep_for(std::chrono::seconds(2));
}

} // namespace mq
