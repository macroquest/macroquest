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

//#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE

#include "routing/PostOffice.h"
#include "routing/ProtoPipes.h"

#include "loader/PostOffice.h"
#include "main/MQPostOffice.h"

#include "mq/base/String.h"

#include <fmt/format.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/wincolor_sink.h>
#include <spdlog/sinks/msvc_sink.h>

#include <cstdio>
#include <utility>

#include <windows.h>


// stub some things because the local connection takes care of some legacy operations in the launcher that doesn't need testing
HWND hMainWnd;

// and define/stub things to mock the client
namespace mq {
void DoCommand(const char* szLine, bool delayed) {}
bool InitializeCrashpad() { return true; }
void InitializeCrashpadPipe(const std::string& pipeName) {}
mq::postoffice::ActorIdentification::Client GetDefaultClient() { return {}; }
bool ShouldUpdateIdentity(int GameState, bool& logged_in) { return true; }
namespace pipeclient {
void RequestActivateWindow(HWND hWnd, bool sendMessage) {}
} // namespace pipeclient
} // namespace mq

struct ImGuiViewport;
struct ImVec2;
namespace LauncherImGui {
	void OpenMessageBox(ImGuiViewport* viewport, const std::string& message, const std::string& title, const ImVec2& size) {}
}

void InitializePostOfficeImgui() {}
void ShutdownPostOfficeImgui() {}

// mirrors the implementation in mq2main. This could possibly be shared code
// between them.
namespace internal_paths
{
	extern std::string MQRoot;
	extern std::string Config;
	extern std::string MQini;
	extern std::string Macros;
	extern std::string Logs;
	extern std::string CrashDumps;
	extern std::string Plugins;
	extern std::string Resources;
}; // namespace internal_paths

std::string internal_paths::MQRoot = ".";
std::string internal_paths::Config = "Config";
std::string internal_paths::MQini = internal_paths::Config + "\\MacroQuest.ini";
std::string internal_paths::Macros = "Macros";
std::string internal_paths::Logs = "Logs";
std::string internal_paths::CrashDumps = internal_paths::Logs + "\\Dumps";
std::string internal_paths::Plugins = "Plugins";
std::string internal_paths::Resources = "Resources";

std::pair<std::string, uint16_t> NetPeer(std::string_view addr, uint16_t port)
{
	return std::make_pair(std::string(addr), port);
}

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

template <typename PO>
class TestDropbox
{
public:
	TestDropbox(uint32_t index, const std::string& name, const std::unordered_map<std::string, int>& responseMap = {})
		: m_name(name)
		, m_responseMap(responseMap)
		, m_dropbox(mq::postoffice::GetPostOffice<PO>(index).RegisterAddress(name,
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

	void Post(const mq::proto::routing::Address& addr, const std::string& obj, const mq::postoffice::MessageResponseCallback& callback = nullptr)
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
		mq::PulsePostOffice(i);
	}

	std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void InitPostOffices()
{
	constexpr const char* pipe0 = R"(\\.\pipe\mqpipe0)";
	constexpr const char* pipe1 = R"(\\.\pipe\mqpipe1)";

	/* launcher post offices */
	SetPostOfficeConfig(PostOfficeConfig{ 0, "Launcher", 0, pipe0 });
	SetPostOfficeConfig(PostOfficeConfig{ 1, "Launcher", 0, pipe1 });

	uint16_t port0 = mq::postoffice::GetPostOffice<mq::postoffice::LauncherPostOffice>(0).GetPeerPort();
	uint16_t port1 = mq::postoffice::GetPostOffice<mq::postoffice::LauncherPostOffice>(1).GetPeerPort();

	mq::postoffice::GetPostOffice<mq::postoffice::LauncherPostOffice>(0).AddNetworkHost("127.0.0.1", port1);
	mq::postoffice::GetPostOffice<mq::postoffice::LauncherPostOffice>(1).AddNetworkHost("127.0.0.1", port0);

	InitializePostOffice(0);
	InitializePostOffice(1);
	/* end launcher post offices */

	// wait here so the pipe connections get made otherwise we'd have to wait 5 seconds for the clients to retry
	std::this_thread::sleep_for(std::chrono::seconds(2));

	/* client post offices */
	SetPostOfficeConfig(mq::MQPostOfficeConfig{ 0, "clientA", pipe0, "accountA", "serverA", "characterA" });
	SetPostOfficeConfig(mq::MQPostOfficeConfig{ 2, "clientB", pipe0, "accountB", "serverB", "characterB" });

	SetPostOfficeConfig(mq::MQPostOfficeConfig{ 1, "clientC", pipe1, "accountC", "serverC", "characterC" });
	SetPostOfficeConfig(mq::MQPostOfficeConfig{ 3, "clientD", pipe1, "accountD", "serverD", "characterD" });

	mq::InitializePostOffice(0);
	mq::InitializePostOffice(2);

	mq::InitializePostOffice(1);
	mq::InitializePostOffice(3);
	/* end client post offices */

	// allow both post offices to set up, otherwise messages will just get dropped with no destination
	PulsePostOffices();
	SPDLOG_INFO("Post Offices Initialized");
}

void ShutdownPostOffices()
{
	mq::ClearPostOfficeConfigs();
	mq::ClearPostOffices();

	ClearPostOfficeConfigs();
	ClearPostOffices();
	SPDLOG_INFO("Post Offices Shutdown");
}

void TestLauncherBehavior()
{
	auto dropbox0 = TestDropbox<mq::postoffice::LauncherPostOffice>(0, "test7781");
	auto dropbox1 = TestDropbox<mq::postoffice::LauncherPostOffice>(1, "test8177", {{"Please respond", 1}});

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
		peer.set_port(mq::postoffice::GetPostOffice<mq::postoffice::LauncherPostOffice>(1).GetPeerPort());
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
	// pipe0
	auto dropboxA1 = TestDropbox<mq::MQPostOffice>(0, "A1", {{"Please respond", 1}});
	auto dropboxB1 = TestDropbox<mq::MQPostOffice>(2, "B1");

	// pipe1
	auto dropboxC1 = TestDropbox<mq::MQPostOffice>(1, "C1");
	auto dropboxD1 = TestDropbox<mq::MQPostOffice>(3, "D1", {{"Please respond", 1}});

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
	// we already have 2 post offices, just set one more up
	SetPostOfficeConfig(PostOfficeConfig{ 2, "Launcher", 0, R"(\\.\pipe\mqpipe2)" });

	auto& po2 = mq::postoffice::GetPostOffice<mq::postoffice::LauncherPostOffice>(2);
	auto port = po2.GetPeerPort();

	std::this_thread::sleep_for(std::chrono::seconds(1));

	auto& po0 = mq::postoffice::GetPostOffice<mq::postoffice::LauncherPostOffice>(0);
	auto& po1 = mq::postoffice::GetPostOffice<mq::postoffice::LauncherPostOffice>(1);

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
	constexpr uint32_t n_network = 100;

	for (uint32_t i = 2; i < n_network; ++i)
		SetPostOfficeConfig(PostOfficeConfig{ i, "Launcher", 0, fmt::format(R"(\\.\pipe\mqpipe{})", i) });

	// this will set up the hosts first
	std::vector<uint16_t> ports;
	for (uint32_t i = 0; i < n_network; ++i)
		ports.push_back(mq::postoffice::GetPostOffice<mq::postoffice::LauncherPostOffice>(i).GetPeerPort());

	std::this_thread::sleep_for(std::chrono::seconds(2));

	for (uint32_t i = 0; i < n_network; ++i)
	{
		auto& po = mq::postoffice::GetPostOffice<mq::postoffice::LauncherPostOffice>(i);
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
		auto& po = mq::postoffice::GetPostOffice<mq::postoffice::LauncherPostOffice>(i);
		// test the number of identities to ensure that all clients connected
		if (po.GetIdentityCount() != n_network + 4)
			SPDLOG_ERROR("TestLargeNetwork: {} had {} identities instead of {}", po.GetPeerPort(), po.GetIdentityCount(), n_network + 4);
	}

	std::this_thread::sleep_for(std::chrono::seconds(2));

	for (uint32_t i = n_network - 1; i > 1; --i)
	{
		auto& po = mq::postoffice::GetPostOffice<mq::postoffice::LauncherPostOffice>(i);

		po.Shutdown();
		DropPostOfficeConfig(i);
	}

	// this just resets the persistent PO's
	auto& po0 = mq::postoffice::GetPostOffice<mq::postoffice::LauncherPostOffice>(0);
	auto& po1 = mq::postoffice::GetPostOffice<mq::postoffice::LauncherPostOffice>(1);
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
	// data -- generate at runtime (once) to avoid extra compile times
	constexpr size_t data_size = 1024ull * 1024ull; // 1MB
	static const std::string data(data_size, 'A');

	// pipe0
	auto dropbox0 = TestDropbox<mq::MQPostOffice>(0, "large0");

	// pipe1
	auto dropbox1 = TestDropbox<mq::MQPostOffice>(1, "large1");

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

