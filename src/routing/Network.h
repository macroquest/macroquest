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

#include "Network.pb.h"

#include "spdlog/spdlog.h"

#include <functional>
#include <memory>

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

	bool operator!=(const NetworkAddress& other) const
	{
		return !(*this == other);
	}
};

using NetworkMessagePtr = std::unique_ptr<peernetwork::NetworkMessage>;

// this serves as the signature for sending and receiving messages
using PeerMessageHandler = std::function<void(const NetworkAddress&, NetworkMessagePtr)>;

// this is the signature for onconnected callbacks
using OnSessionConnectedHandler = std::function<void(const NetworkAddress&)>;
using OnSessionDisconnectedHandler = std::function<void(const NetworkAddress&)>;
using OnRequestProcessHandler = std::function<void()>;

class NetworkPeerAPI
{
	explicit NetworkPeerAPI(uint16_t port);

public:
	static NetworkPeerAPI GetOrCreate(
		uint16_t port,
		PeerMessageHandler receive,
		OnSessionConnectedHandler connected,
		OnSessionDisconnectedHandler disconnected,
		OnRequestProcessHandler process);

	~NetworkPeerAPI() = default;

	NetworkPeerAPI(const NetworkPeerAPI&) = default;
	NetworkPeerAPI& operator=(const NetworkPeerAPI&) = default;
	NetworkPeerAPI(NetworkPeerAPI&&) = default;
	NetworkPeerAPI& operator=(NetworkPeerAPI&&) = default;

	void Send(const std::string& address, uint16_t port, NetworkMessagePtr message) const;
	void Broadcast(NetworkMessagePtr message) const;
	void Process() const;

	void Shutdown() const;

	void AddHost(const std::string& address, uint16_t port) const;
	void RemoveHost(const std::string& address, uint16_t port) const;
	bool HasHost(const std::string& address, uint16_t port) const;

	uint16_t GetPort() const { return m_port; }

private:
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

