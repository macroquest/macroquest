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

#include "routing/PostOffice.h"
#include "routing/ProtoPipes.h"
#include "loader/PostOffice.h"
#include "main/MQPostOffice.h"

#include "mq/base/String.h"

#include "fmt/format.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/wincolor_sink.h"
#include "spdlog/sinks/msvc_sink.h"

#include <cstdio>
#include <utility>

#include <windows.h>

using mq::postoffice::ClientPostOffice;
using mq::postoffice::ServerPostOffice;
using mq::postoffice::PostOffice;
using mq::postoffice::ActorIdentification;
using mq::postoffice::ActorContainer;

//-----------------------------------------------------------------------------
class TestClientPostOffice final : public ClientPostOffice
{
public:
	struct Config
	{
		uint32_t Index = 0;
		std::string Name = "MQPostOffice"; // useful for debugging
		std::string PipeName = mq::MQ_PIPE_SERVER_PATH;

		std::optional<std::string> AccountOverride;
		std::optional<std::string> ServerOverride;
		std::optional<std::string> CharacterOverride;
	};

	static ActorIdentification::Client GetCurrentClient(const Config& config)
	{
		ActorIdentification::Client client;

		if (config.AccountOverride)
			client.account = *config.AccountOverride;

		if (config.ServerOverride)
			client.server = *config.ServerOverride;

		if (config.CharacterOverride)
			client.character = *config.CharacterOverride;

		return client;
	}

	//-------------------------------------------------------------------------

	TestClientPostOffice(const Config& config)
		: ClientPostOffice(config.Name, config.PipeName,
			ActorIdentification(
				ActorContainer(ActorContainer::CurrentProcess, mq::CreateUUID()),
				GetCurrentClient(config)))
		, m_config(config)
	{
	}

	const Config& GetConfig() const { return m_config; }

	virtual ActorIdentification::Client GetCurrentClient() const override
	{
		return GetCurrentClient(m_config);
	}

private:
	Config m_config;
};

template <typename T>
struct PostOfficeData
{
	using PostOfficeType = T;
	using ConfigType = typename PostOfficeType::Config;

	std::unordered_map<uint32_t, ConfigType> configs;
	std::unordered_map<uint32_t, PostOfficeType> postOffices;
};
PostOfficeData<TestClientPostOffice> client;

//-----------------------------------------------------------------------------

class TestServerPostOffice final : public ServerPostOffice
{
public:
	struct Config
	{
		uint32_t Index = 0;
		std::string Name = "PostOffice"; // useful for debugging
		std::string PipeName = mq::MQ_PIPE_SERVER_PATH;
		std::optional<std::vector<std::pair<std::string, uint16_t>>> Peers;
	};

	TestServerPostOffice(const Config& config)
		: ServerPostOffice(config.Name, config.PipeName, 0 /* auto-select port */)
		, m_config(config)
	{
	}

	const Config& GetConfig() const { return m_config; }

	virtual void AddConfiguredHosts() override
	{
		const uint16_t default_port = GetPeerPort();

		if (m_config.Peers)
		{
			for (const auto& [address, port] : *m_config.Peers)
			{
				AddNetworkHost(address, port > 0 ? port : default_port);
			}
		}
		else
		{
			ServerPostOffice::AddConfiguredHosts();
		}
	}

private:
	Config m_config;
};

PostOfficeData<TestServerPostOffice> server;

//-----------------------------------------------------------------------------

template <typename T>
static void SetPostOfficeConfig(PostOfficeData<T>& data, const typename PostOfficeData<T>::ConfigType& config)
{
	data.configs[config.Index] = config;
}

template <typename T>
static void DropPostOfficeConfig(T& data, uint32_t index)
{
	data.configs.erase(index);
}

template <typename T>
static typename T::ConfigType GetPostOfficeConfig(T& data, uint32_t index)
{
	const auto config = data.configs.find(index);
	if (config != data.configs.end())
	{
		return config->second;
	}

	return {};
}

template <typename T>
static void ClearPostOfficeConfigs(T& data)
{
	data.configs.clear();
}

template <typename T>
static typename T::PostOfficeType& GetPostOffice(T& data, uint32_t index)
{
	auto it = data.postOffices.find(index);
	if (it == data.postOffices.end())
	{
		it = data.postOffices.emplace(index, typename T::ConfigType(GetPostOfficeConfig(data, index))).first;
	}

	return it->second;
}

template <typename T>
static void RemovePostOffice(T& data, uint32_t index)
{
	data.postOffices.erase(index);
}

template <typename T>
static void InitializePostOffice(T& data, uint32_t index)
{
	GetPostOffice(data, index).Initialize();
}

template <typename T>
static void ShutdownPostOffice(T& data, uint32_t index)
{
	GetPostOffice(data, index).Shutdown();
}

template <typename T>
static void PulsePostOffices(T& data)
{
	for (auto& [_, postOffice] : data.postOffices)
	{
		postOffice.ProcessPipeClient();
	}
}

template <typename T>
static void ClearPostOffices(T& data)
{
	if constexpr (std::is_same_v<T, PostOfficeData<TestClientPostOffice>>)
	{
		for (auto& [_, postOffice] : data.postOffices)
			postOffice.Shutdown();
	}
	else
	{
		std::vector<uint32_t> indexes;
		for (const auto& [index, _] : data.postOffices)
			indexes.push_back(index);

		for (uint32_t index : indexes)
		{
			GetPostOffice(data, index).Shutdown();
			RemovePostOffice(data, index);
		}
	}

	data.postOffices.clear();
}

template <typename T>
static void PulsePostOffices(T& data, uint32_t index)
{
	GetPostOffice(data, index).ProcessPipeClient();
}

//----------------------------------------------------------------------------

// this test is low level, and we want to test high level APIs
//void Test()
//{
//	const auto peer1 = mq::NetworkPeerAPI::GetOrCreate(7781,
//		[](const mq::NetworkAddress& address, std::unique_ptr<uint8_t[]>&& message, const uint32_t length)
//		{
//			SPDLOG_DEBUG("Received message in peer1 of length {}: {}", length, std::string_view(reinterpret_cast<char*>(message.get()), length));
//		}, [](const auto&) {}, [](const auto&) {});
//
//	const auto peer2 = mq::NetworkPeerAPI::GetOrCreate(8177,
//		[](const mq::NetworkAddress& address, std::unique_ptr<uint8_t[]>&& message, const uint32_t length)
//		{
//			SPDLOG_DEBUG("Received message in peer2 of length {}: {}", length, std::string_view(reinterpret_cast<char*>(message.get()), length));
//		}, [](const auto&) {}, [](const auto&) {});
//
//	std::this_thread::sleep_for(std::chrono::seconds(2));
//
//	peer1.AddHost("127.0.0.1", 8177);
//	peer2.AddHost("127.0.0.1", 7781);
//	std::this_thread::sleep_for(std::chrono::seconds(5));
//
//	const std::string s("This is a test");
//	auto t = std::make_unique<uint8_t[]>(s.length());
//	memcpy(t.get(), s.data(), s.length());
//	peer1.Send("127.0.0.1", 8177, std::move(t), s.length());
//
//	std::this_thread::sleep_for(std::chrono::seconds(2));
//}


std::pair<std::string, uint16_t> NetPeer(std::string_view addr, uint16_t port)
{
	return std::make_pair(std::string(addr), port);
}

class TestDropbox
{
public:
	template <typename T>
	TestDropbox(T& data, uint32_t index, const std::string& name, const std::unordered_map<std::string, int>& responseMap = {})
		: m_name(name)
		, m_responseMap(responseMap)
		, m_dropbox(GetPostOffice(data, index).RegisterAddress(name,
			[this](mq::postoffice::MessagePtr message)
			{
				SPDLOG_TRACE("{}: received {}", m_name, message->payload());
				m_received.push_back(message->payload());

				auto it = m_responseMap.find(message->payload());
				if (it != m_responseMap.end())
				{
					auto response = fmt::format("{}: responding to message {}", m_name, message->payload());
					PostReply(std::move(message), response, it->second);
				}
			}))
	{}

	void Post(const mq::proto::routing::Address& addr, const std::string& obj,
		const mq::postoffice::MessageResponseCallback& callback = nullptr)
	{
		m_dropbox.Post(addr, obj, callback);
	}

	void PostReply(mq::postoffice::MessagePtr message, const std::string& data, int status)
	{
		m_dropbox.PostReply(std::move(message), data, status);
	}

	bool HasReceived(const std::string& payload)
	{
		return ReceivedCount(payload) > 0;
	}

	size_t ReceivedCount(const std::string& payload)
	{
		return std::count_if(m_received.begin(), m_received.end(),
			[&payload](const std::string & received)
			{ return mq::ci_equals(received, payload); });
	}

private:
	std::string m_name;
	std::unordered_map<std::string, int> m_responseMap;
	mq::postoffice::Dropbox m_dropbox;

	std::vector<std::string> m_received;
};

void PulsePostOffices()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(100));

	for (auto i : { 0, 1, 2, 3 })
	{
		PulsePostOffices(client, i);
	}

	std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void InitPostOffices()
{
	SPDLOG_INFO("================== Initializing Post Offices ==================");
	constexpr const char* pipe0 = R"(\\.\pipe\mqpipe0)";
	constexpr const char* pipe1 = R"(\\.\pipe\mqpipe1)";

	/* launcher post offices */
	SetPostOfficeConfig(server, { 0, "Launcher", pipe0 });
	SetPostOfficeConfig(server, { 1, "Launcher", pipe1 });

	uint16_t port0 = GetPostOffice(server, 0).GetPeerPort();
	uint16_t port1 = GetPostOffice(server, 1).GetPeerPort();

	GetPostOffice(server, 0).AddNetworkHost("127.0.0.1", port1);
	GetPostOffice(server, 1).AddNetworkHost("127.0.0.1", port0);

	InitializePostOffice(server, 0);
	InitializePostOffice(server, 1);
	/* end launcher post offices */

	// wait here so the pipe connections get made otherwise we'd have to wait 5 seconds for the clients to retry
	std::this_thread::sleep_for(std::chrono::seconds(2));

	/* client post offices */
	SetPostOfficeConfig(client, { 0, "clientA", pipe0, "accountA", "serverA", "characterA" });
	SetPostOfficeConfig(client, { 2, "clientB", pipe0, "accountB", "serverB", "characterB" });

	SetPostOfficeConfig(client, { 1, "clientC", pipe1, "accountC", "serverC", "characterC" });
	SetPostOfficeConfig(client, { 3, "clientD", pipe1, "accountD", "serverD", "characterD" });

	InitializePostOffice(client, 0);
	InitializePostOffice(client, 2);

	InitializePostOffice(client, 1);
	InitializePostOffice(client, 3);
	/* end client post offices */

	// allow both post offices to set up, otherwise messages will just get dropped with no destination
	PulsePostOffices();

	SPDLOG_INFO("Post Offices Initialized");
}

void ShutdownPostOffices()
{
	SPDLOG_INFO("================== Shutting Down Post Offices ==================");

	ClearPostOfficeConfigs(client);
	ClearPostOffices(client);

	ClearPostOfficeConfigs(server);
	ClearPostOffices(server);

	SPDLOG_INFO("Post Offices Shutdown");
}

void TestLauncherBehavior()
{
	SPDLOG_INFO("================== Testing Launcher Behavior ==================");

	auto dropbox0 = TestDropbox(server, 0, "test7781");
	auto dropbox1 = TestDropbox(server, 1, "test8177", {{"Please respond", 1}});

	// basic message routing
	{
		mq::proto::routing::Address addr;
		addr.set_name("launcher");
		addr.set_mailbox("test7781");
		dropbox1.Post(addr, std::string("This is a test"));
	}

	// failed RPC (ambiguous recipient)
	int failed_status = 0;
	{
		// this should fail with -4 because there are 2 launchers
		mq::proto::routing::Address addr;
		addr.set_name("launcher");
		addr.set_mailbox("test8177");
		dropbox0.Post(addr, std::string("Please respond"),
			[&failed_status](int status, mq::postoffice::MessagePtr message)
			{
				SPDLOG_TRACE("Received status {} and response: {}", message->status(), message->payload());
				failed_status = message->status();
			});
	}

	// successful RPC
	int success_status = 2;
	{
		// this should succeed
		mq::proto::routing::Address addr;
		mq::proto::routing::Peer& peer = *addr.mutable_peer();
		peer.set_ip("127.0.0.1");
		peer.set_port(GetPostOffice(server, 1).GetPeerPort());
		addr.set_name("launcher");
		addr.set_mailbox("test8177");
		dropbox0.Post(addr, std::string("Please respond"),
			[&success_status](int status, mq::postoffice::MessagePtr message)
			{
				SPDLOG_TRACE("Received status {} and response: {}", message->status(), message->payload());
				success_status = message->status();
			});
	}

	std::this_thread::sleep_for(std::chrono::seconds(2));

	if (!dropbox0.HasReceived("This is a test"))
		SPDLOG_ERROR("TestLauncherBehavior: Failed to send basic message");

	if (auto count = dropbox1.ReceivedCount("Please respond"); count != 1)
		SPDLOG_ERROR("TestLauncherBehavior: Received {} response requests instead of 1", count);

	if (failed_status != -4)
		SPDLOG_ERROR("TestLauncherBehavior: Received {} status from bad response attempt instead of -4", failed_status);

	if (success_status != 1)
		SPDLOG_ERROR("TestLauncherBehavior: Received {} status from good response attempt instead of 1", success_status);

	SPDLOG_INFO("TestLauncherBehavior: Tests Complete");
}

void TestBasicClientSetup()
{
	SPDLOG_INFO("================== Testing Basic Client Setup ==================");

	// pipe0
	auto dropboxA1 = TestDropbox(client, 0, "A1", {{"Please respond", 1}});
	auto dropboxB1 = TestDropbox(client, 2, "B1");

	// pipe1
	auto dropboxC1 = TestDropbox(client, 1, "C1");
	auto dropboxD1 = TestDropbox(client, 3, "D1", {{"Please respond", 1}});

	// internal route
	{
		mq::proto::routing::Address addr;
		addr.set_mailbox("B1");
		dropboxA1.Post(addr, "This is from A1");
	}

	// external route
	{
		mq::proto::routing::Address addr;
		addr.set_mailbox("C1");
		dropboxA1.Post(addr, "This is from A1");
	}

	// internal failed RPC
	int failed_status_int = 0;
	{
		mq::proto::routing::Address addr;
		addr.set_mailbox("D1");
		dropboxC1.Post(addr, std::string("Please respond"),
			[&failed_status_int](int status, mq::postoffice::MessagePtr message)
			{
				SPDLOG_TRACE("Received status {} and response: {}", message->status(), message->payload());
				failed_status_int = message->status();
			});
	}

	// external failed RPC
	int failed_status_ext = 0;
	{
		mq::proto::routing::Address addr;
		addr.set_mailbox("A1");
		dropboxC1.Post(addr, std::string("Please respond"),
			[&failed_status_ext](int status, mq::postoffice::MessagePtr message)
			{
				SPDLOG_TRACE("Received status {} and response: {}", message->status(), message->payload());
				failed_status_ext = message->status();
			});
	}

	// internal successful RPC
	int success_status_int = 2;
	{
		mq::proto::routing::Address addr;
		addr.set_mailbox("D1");
		addr.mutable_client()->set_character("characterD");
		dropboxC1.Post(addr, std::string("Please respond"),
			[&success_status_int](int status, mq::postoffice::MessagePtr message)
			{
				SPDLOG_TRACE("Received status {} and response: {}", message->status(), message->payload());
				success_status_int = message->status();
			});
	}

	// external failed RPC
	int success_status_ext = 2;
	{
		mq::proto::routing::Address addr;
		addr.set_mailbox("A1");
		addr.mutable_client()->set_character("characterA");
		dropboxC1.Post(addr, std::string("Please respond"),
			[&success_status_ext](int status, mq::postoffice::MessagePtr message)
			{
				SPDLOG_TRACE("Received status {} and response: {}", message->status(), message->payload());
				success_status_ext = message->status();
			});
	}

	PulsePostOffices();

	if (!dropboxB1.HasReceived("This is from A1"))
		SPDLOG_ERROR("TestBasicClientSetup: Failed to route internally");

	if (!dropboxC1.HasReceived("This is from A1"))
		SPDLOG_ERROR("TestBasicClientSetup: Failed to route externally");

	if (auto count = dropboxD1.ReceivedCount("Please respond"); count != 1)
		SPDLOG_ERROR("TestBasicClientSetup: D1 Received {} response requests instead of 1", count);

	if (auto count = dropboxA1.ReceivedCount("Please respond"); count != 1)
		SPDLOG_ERROR("TestBasicClientSetup: A1 Received {} response requests instead of 1", count);

	if (failed_status_int != -4)
		SPDLOG_ERROR("TestBasicClientSetup: C1 Received {} status from bad internal response attempt instead of -4", failed_status_int);

	if (failed_status_ext != -4)
		SPDLOG_ERROR("TestBasicClientSetup: C1 Received {} status from bad external response attempt instead of -4", failed_status_ext);

	// need another pulse for the response to get sent back
	PulsePostOffices();

	if (success_status_int != 1)
		SPDLOG_ERROR("TestBasicClientSetup: C1 Received {} status from good internal response attempt instead of 1", success_status_int);

	if (success_status_ext != 1)
		SPDLOG_ERROR("TestBasicClientSetup: C1 Received {} status from good external response attempt instead of 1", success_status_ext);

	SPDLOG_INFO("TestBasicClientSetup: Tests Complete");
}

void TestReconnect()
{
	SPDLOG_INFO("================== Testing Reconnect ==================");

	// we already have 2 post offices, just set one more up
	SetPostOfficeConfig(server, { 2, "Launcher", R"(\\.\pipe\mqpipe2)" });

	auto& po2 = GetPostOffice(server, 2);
	auto port = po2.GetPeerPort();

	std::this_thread::sleep_for(std::chrono::seconds(1));

	auto& po0 = GetPostOffice(server, 0);
	auto& po1 = GetPostOffice(server, 1);

	po0.AddNetworkHost("127.0.0.1", port);
	po1.AddNetworkHost("127.0.0.1", port);

	std::this_thread::sleep_for(std::chrono::seconds(1));

	// This can give an "already shut down" error, which is fine
	po2.RemoveNetworkHost("127.0.0.1", po0.GetPeerPort());

	std::this_thread::sleep_for(std::chrono::seconds(1));

	if (po2.GetIdentityCount() != 7)
		SPDLOG_ERROR("TestReconnect: {} had {} identities instead of 7", po2.GetPeerPort(), po2.GetIdentityCount());

	SPDLOG_INFO("TestReconnect: Tests Complete");
}

void TestLargeNetwork()
{
	SPDLOG_INFO("================== Testing Large Network ==================");

	constexpr uint32_t n_network = 100;

	for (uint32_t i = 2; i < n_network; ++i)
		SetPostOfficeConfig(server, { i, "Launcher", fmt::format(R"(\\.\pipe\mqpipe{})", i) });

	// this will set up the hosts first
	std::vector<uint16_t> ports;
	for (uint32_t i = 0; i < n_network; ++i)
		ports.push_back(GetPostOffice(server, i).GetPeerPort());

	std::this_thread::sleep_for(std::chrono::seconds(2));

	for (uint32_t i = 0; i < n_network; ++i)
	{
		auto& po = GetPostOffice(server, i);
		auto i_port = po.GetPeerPort();

		for (auto port : ports)
		{
			if (port != i_port)
				po.AddNetworkHost("127.0.0.1", port);
		}
	}

	std::this_thread::sleep_for(std::chrono::seconds(std::max(2, static_cast<int>(n_network * n_network / 400))));

	for (uint32_t i = 0; i < n_network; ++i)
	{
		auto& po = GetPostOffice(server, i);

		// test the number of identities to ensure that all clients connected
		if (po.GetIdentityCount() != n_network + 4)
		{
			SPDLOG_ERROR("TestLargeNetwork: {} had {} identities instead of {}", po.GetPeerPort(), po.GetIdentityCount(), n_network + 4);
		}
	}

	std::this_thread::sleep_for(std::chrono::seconds(2));

	for (uint32_t i = n_network - 1; i > 1; --i)
	{
		auto& po = GetPostOffice(server, i);

		po.Shutdown();
		DropPostOfficeConfig(server, i);
	}

	// this just resets the persistent PO's
	auto& po0 = GetPostOffice(server, 0);
	auto& po1 = GetPostOffice(server, 1);
	for (auto port : ports)
	{
		if (port != po0.GetPeerPort() && port != po1.GetPeerPort())
		{
			po0.RemoveNetworkHost("127.0.0.1", port);
			po1.RemoveNetworkHost("127.0.0.1", port);
		}
	}

	SPDLOG_INFO("TestLargeNetwork: Tests Complete");
}

void TestLargeData()
{
	SPDLOG_INFO("================== Testing Large Data ==================");

	// data -- generate at runtime (once) to avoid extra compile times
	constexpr size_t data_size = 1024ull * 1024ull; // 1MB
	static const std::string data(data_size, 'A');

	// pipe0
	auto dropbox0 = TestDropbox(client, 0, "large0");

	// pipe1
	auto dropbox1 = TestDropbox(client, 1, "large1");

	for (int i = 1; i <= 100; ++i)
	{
		// external route
		{
			mq::proto::routing::Address addr;
			addr.set_mailbox("large1");
			dropbox0.Post(addr, data);
		}

		PulsePostOffices();

		if (dropbox1.ReceivedCount(data) != i)
			SPDLOG_ERROR("TestLargeData: Failed to route {}.", i);
	}

	SPDLOG_INFO("TestLargeData: Tests Complete");
}

void InitializeLogging()
{
	// create color multi threaded logger
	auto logger = spdlog::create<spdlog::sinks::wincolor_stdout_sink_mt>("ActorTest");
	spdlog::set_default_logger(logger);
	spdlog::flush_on(spdlog::level::trace);
	spdlog::set_level(spdlog::level::trace);

	if (IsDebuggerPresent())
	{
		logger->sinks().push_back(std::make_shared<spdlog::sinks::msvc_sink_mt>());
	}

	SPDLOG_DEBUG("Logging Initialized");
}

int main(int argc, TCHAR* argv[])
{
	InitializeLogging();
	InitPostOffices();

	//Test();

	TestLauncherBehavior();
	TestBasicClientSetup();
	TestReconnect();
	TestLargeNetwork();
	TestLargeData();

	std::this_thread::sleep_for(std::chrono::seconds(2));

	ShutdownPostOffices();

	return 0;
}

