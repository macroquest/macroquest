#pragma once

#include <spdlog/spdlog.h>

#include <memory>
#include <functional>

// this serves as the signature for sending and receiving messages
// the signature is address, port, payload, length
using PeerMessageHandler = std::function<void(const std::string&, uint16_t, std::unique_ptr<uint8_t[]>&&, size_t)>;

class NetworkPeerAPI
{
public:
	NetworkPeerAPI() = delete;
	NetworkPeerAPI(const NetworkPeerAPI&) = delete;
	NetworkPeerAPI(NetworkPeerAPI&&) = delete;
	NetworkPeerAPI& operator=(const NetworkPeerAPI&) = delete;
	NetworkPeerAPI& operator=(NetworkPeerAPI&&) = delete;
	~NetworkPeerAPI() = default;

	void Send(const std::string& address, uint16_t port, std::unique_ptr<uint8_t[]>&& payload, size_t length) const;

	// templated helper functions to assist with the common use case of protobuf
	template <typename T>
	void Send(const std::string& address, uint16_t port, const T& data) const
	{
		const size_t length = data.ByteSizeLong();
		if (length > 0)
		{
			auto payload = std::make_unique<uint8_t[]>(length);
			data.SerializeToArray(payload.get(), static_cast<int>(length));
			Send(address, port, std::move(payload), length);
		}
		else
		{
			Send(address, port, nullptr, length);
		}
	}

	static NetworkPeerAPI Register(uint16_t port, PeerMessageHandler receive);
	void Unregister() const;

private:
	explicit NetworkPeerAPI(uint16_t port);

	uint16_t m_port;
};

void Test();
