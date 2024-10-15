#pragma once

#include <spdlog/spdlog.h>

#include <memory>
#include <functional>

namespace mq {

constexpr uint16_t DEFAULT_NETWORK_PEER_PORT = 7781;

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

	bool operator!=(const NetworkAddress& other) const
	{
		return !(*this == other);
	}
};

// this serves as the signature for sending and receiving messages
// the signature is address, port, payload, length
using PeerMessageHandler = std::function<void(const NetworkAddress&, std::unique_ptr<uint8_t[]>&&, size_t)>;

// this is the signature for onconnected callbacks
using OnSessionConnectedHandler = std::function<void(const NetworkAddress& address)>;
using OnSessionDisconnectedHandler = std::function<void(const NetworkAddress& address)>;

class NetworkPeerAPI
{
public:
	NetworkPeerAPI() = delete;
	NetworkPeerAPI(const NetworkPeerAPI&) = default;
	NetworkPeerAPI(NetworkPeerAPI&&) = default;
	NetworkPeerAPI& operator=(const NetworkPeerAPI&) = default;
	NetworkPeerAPI& operator=(NetworkPeerAPI&&) = default;
	~NetworkPeerAPI() = default;

	void Send(const std::string& address, uint16_t port, std::unique_ptr<uint8_t[]>&& payload, uint32_t length) const;

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
			Send(address, port, nullptr, 0);
		}
	}

	void Broadcast(std::unique_ptr<uint8_t[]>&& payload, uint32_t length) const;

	template <typename T>
	void Broadcast(const T& data) const
	{
		const size_t length = data.ByteSizeLong();
		if (length > 0)
		{
			auto payload = std::make_unique<uint8_t[]>(length);
			data.SerializeToArray(payload.get(), static_cast<int>(length));
			Broadcast(std::move(payload), length);
		}
		else
		{
			Broadcast(nullptr, 0);
		}
	}

	static NetworkPeerAPI GetOrCreate(uint16_t port, PeerMessageHandler receive, OnSessionConnectedHandler connected, OnSessionDisconnectedHandler disconnected);
	void Shutdown() const;

	void AddHost(const std::string& address, uint16_t port) const;
	void RemoveHost(const std::string& address, uint16_t port) const;
	bool HasHost(const std::string& address, uint16_t port) const;

	uint16_t GetPort() const { return m_port; }

private:
	explicit NetworkPeerAPI(uint16_t port);

	uint16_t m_port;
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

