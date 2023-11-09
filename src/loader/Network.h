#pragma once

#include "asio.hpp"
#include "Network.pb.h"

using asio::ip::tcp;

namespace mq {

class NetworkSession;
class NetworkPeer
{
	friend class NetworkSession;

public:
	NetworkPeer(const std::string& address, uint16_t port, const std::function<void(const peernetwork::Header&, uint8_t*)>& handler);
	~NetworkPeer();

	void TestSend(const std::string& message);

	void Run();
	void Connect(const std::string& address, uint16_t port);

private:
	NetworkPeer() = delete;
	NetworkPeer(const NetworkPeer&) = delete;

	void Accept();

	bool StageSession(const std::error_code& ec, tcp::socket&& socket);
	void PruneSessions();

	void SendUUID(const std::unique_ptr<NetworkSession>& session);
	void ReceiveUUID(const std::string& pending_id, uint16_t local_port, const peernetwork::Identification& id);
	static std::string CreateUUID();

	asio::io_context m_ioContext{};
	tcp::acceptor m_acceptor;

	std::string m_address;
	uint16_t m_port = 0;
	std::string m_uuid;

	// TODO: Need to create a list of known hosts to try to connect to

	std::unordered_map<std::string, std::unique_ptr<NetworkSession>> m_pendingSessions;
	std::unordered_map<std::string, std::unique_ptr<NetworkSession>> m_sessions;
	std::list<std::unique_ptr<NetworkSession>> m_closingSessions;

	std::thread m_thread;

	std::function<void(const peernetwork::Header&, uint8_t*)> m_receiveHandler;
};

void Test();

} // namespace mq
