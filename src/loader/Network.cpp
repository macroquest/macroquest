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

// TODO: remove proto altogether, unless we need to serialize length in a proto (which we can do later)
#include "Network.pb.h"

using asio::ip::tcp;

namespace mq {

// create an address type for use in keying and lookup
struct NetworkAddress
{
	std::string IP; // always use IP here, if we ever allow host names, make sure to resolve to IP first
	uint16_t Port;

	bool operator==(const NetworkAddress& other) const
	{
		// exact match on IP, can just use string == override
		return IP == other.IP && Port == other.Port;
	}
};
} // namespace mq

// provide the hash function for the address outside the mq namespace
template<> struct std::hash<mq::NetworkAddress>
{
	size_t operator()(const mq::NetworkAddress& address) const noexcept
	{
		return std::hash<std::string>{}(address.IP) ^ std::hash<uint16_t>{}(address.Port) << 1;
	}
};

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
	template <typename T>
	NetworkMessage(const T& data)
		: m_length(data.ByteSizeLong())
	{
		if (m_length > 0)
		{
			m_payload = std::make_unique<uint8_t[]>(m_length);
			data.SerializeToArray(m_payload.get(), static_cast<int>(m_length));
		}
	}

	// incoming message
	NetworkMessage() : m_length(0) {}

	NetworkMessage(const NetworkMessage&) = delete;
	NetworkMessage(NetworkMessage&&) = delete;
	NetworkMessage& operator=(const NetworkMessage&) = delete;
	NetworkMessage& operator=(NetworkMessage&&) = delete;

	~NetworkMessage() = default;

	void Init()
	{
		if (m_length > 0)
			m_payload = std::make_unique<uint8_t[]>(m_length);
	}

	std::vector<asio::const_buffer> Buffers() const
	{
		// This assumes a header will always exist, ensure that the asio read assumes that as well!
		// This also assumes that size_t is the same on all systems, we can remove this assumption by using a proto for length
		std::vector<asio::const_buffer> buffers{
			asio::buffer(&m_length, sizeof(size_t))
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

	size_t& Length() { return m_length; }
	uint8_t* Payload() const { return m_payload.get(); }

private:
	std::unique_ptr<uint8_t[]> m_payload;
	size_t m_length;
};

class NetworkSession
{
public:
	NetworkSession(tcp::socket&& socket, const std::function<void(uint8_t*, size_t)>& receiveHandler)
		: m_socket(std::move(socket))
		, m_address({m_socket.remote_endpoint().address().to_string(), m_socket.remote_endpoint().port()})
		, m_active(true)
		, m_receiveHandler(receiveHandler)
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
			asio::buffer(&message->Length(), sizeof(size_t)),
			[this, message](const std::error_code& ec, size_t size)
			{
				// TODO: Handle other connection errors with reconnect attempts
				// TODO: Write a function that handles this the same way every time (error checking)
				if (ec != asio::error::eof && // this is when the connection was closed remotely
					ec != asio::error::connection_reset && // this is if the socket is force closed remotely (when the peer is destroyed)
					ec != asio::error::shut_down) // this is when we shut down the socket locally
					ReadLength(ec, message);
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
	void ReadLength(const std::error_code& ec, const std::shared_ptr<NetworkMessage>& message)
	{
		if (ec)
		{
			SPDLOG_ERROR("Message length read error {}: {}", ec.value(), ec.message());
			Shutdown();
		}
		else if (message->Length() == 0)
		{
			SPDLOG_WARN("Got zero length message");
		}
		else
		{
			message->Init();
			asio::async_read(
				m_socket,
				asio::buffer(message->Payload(), message->Length()),
				[this, message](const std::error_code& ec, size_t) { ReadPayload(ec, message); });
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
				m_receiveHandler(message->Payload(), message->Length());
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
	const NetworkAddress m_address;
	bool m_active;

	std::function<void(uint8_t*, size_t)> m_receiveHandler;
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

	NetworkPeer(const std::string& address, uint16_t port, const std::function<void(uint8_t*, size_t)>& handler)
		: m_acceptor(m_ioContext, tcp::endpoint(tcp::v4(), port))
		, m_address(address)
		, m_port(port)
		, m_receiveHandler(handler)
	{
		SPDLOG_INFO("Initializing peer at {}:{}", address, port);

		m_acceptor.listen();
		Accept();
	}

	~NetworkPeer()
	{
		SPDLOG_INFO("Removing peer {}:{}", m_address, m_port);

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
					SPDLOG_ERROR("Peer failed with exception ({}:{}): {}", m_address, m_port, e.what());
				}
			});
	}

	void Connect(const std::string& address, uint16_t port)
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
				if (!AddSession(ec, std::move(*socket)))
				{
					// TODO: make retry time configurable
					timer->expires_from_now(std::chrono::seconds(2));
					timer->async_wait(
						[this, &address, port](const std::error_code& ec) { Connect(address, port); });
				}
			});
	}

	template <typename T>
	void Send(const NetworkAddress& address, const T& data)
	{
		const auto sess = m_sessions.find(address);
		if (sess != m_sessions.end() && sess->second)
		{
			sess->second->Write(std::make_unique<NetworkMessage>(data));
		}
		else
		{
			SPDLOG_WARN("Attempted to send message to unknown peer {}:{}", address.IP, address.Port);
		}
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
			auto session = std::make_unique<NetworkSession>(std::move(socket), m_receiveHandler);
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

		// TODO: some error conditions shouldn't warrant a retry
		return !ec;
	}

	void PruneSessions()
	{
		m_closingSessions.remove_if([](const std::unique_ptr<NetworkSession>& session) { return !session->IsOpen(); });

		// clear out any sessions that are no longer active
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

	asio::io_context m_ioContext{};
	tcp::acceptor m_acceptor;

	std::string m_address;
	uint16_t m_port = 0;

	// TODO: Need to create a list of known hosts to try to connect to

	std::unordered_map<NetworkAddress, std::unique_ptr<NetworkSession>> m_sessions;
	std::list<std::unique_ptr<NetworkSession>> m_closingSessions;

	std::thread m_thread;

	std::function<void(uint8_t*, size_t)> m_receiveHandler;
};

} // namespace mq

void Test()
{
	//auto hosts = []()
	//	{
	//		auto hosts_enabled = GetPrivateProfileKeyValues("NetworkHosts", internal_paths::MQini);
	//		hosts_enabled.erase(std::remove_if(hosts_enabled.begin(), hosts_enabled.end(),
	//			[](const std::pair<std::string, std::string>& pair) { return !ci_equals("1", pair.second); }),
	//			hosts_enabled.end());

	//		std::vector<std::string> hosts(hosts_enabled.size());
	//		std::transform(hosts_enabled.begin(), hosts_enabled.end(), std::back_inserter(hosts),
	//			[](const std::pair<std::string, std::string>& pair) { return pair.first; });

	//		return hosts;
	//	}();

	NetworkPeer peer1("0.0.0.0", 7781, [](const uint8_t* message, const size_t length)
		{
			peernetwork::TestString s;
			s.ParseFromArray(message, static_cast<int>(length));
			SPDLOG_DEBUG("Received message in peer1 of length {}: {}", length, s.message());
		});

	NetworkPeer peer2("0.0.0.0", 8177, [](const uint8_t* message, const size_t length)
		{
			peernetwork::TestString s;
			s.ParseFromArray(message, static_cast<int>(length));
			SPDLOG_DEBUG("Received message in peer2 of length {}: {}", length, s.message());
		});

	peer1.Run();
	peer2.Run();
	std::this_thread::sleep_for(std::chrono::seconds(2));

	peer1.Connect("127.0.0.1", 8177);
	peer2.Connect("127.0.0.1", 7781);
	std::this_thread::sleep_for(std::chrono::seconds(5));

	peernetwork::TestString s;
	s.set_message("This is a test");
	peer1.Send(NetworkAddress{ "127.0.0.1", 8177 }, s);

	std::this_thread::sleep_for(std::chrono::seconds(2));
}
