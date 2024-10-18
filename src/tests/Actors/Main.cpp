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

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE

#include <windows.h>

#include "routing/PostOffice.h"

#include "loader/PostOffice.h"
//#include "main/MQPostOffice.h"

#include <fmt/format.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/wincolor_sink.h>
#include <spdlog/sinks/msvc_sink.h>

#include <cstdio>
#include <utility>


// stub some things because the local connection takes care of some legacy operations in the launcher that doesn't need testing
HWND hMainWnd;

struct ImGuiViewport;
namespace LauncherImGui {
	void OpenMessageBox(ImGuiViewport* viewport, const std::string& message, const std::string& title) {}
}

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

// this test is low level, and we want to test high level APIs -- if we want the low level tests
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

class TestDropbox
{
public:
	TestDropbox(uint32_t index, const std::string& name)
		: m_name(name)
		, m_dropbox(mq::postoffice::GetPostOffice(index).RegisterAddress(name,
			[this](mq::postoffice::MessagePtr message)
			{
				SPDLOG_DEBUG("{}: received {}", m_name, message->payload());

				if (message->payload() == "Please respond")
				{
					auto response = fmt::format("{}: responding to message {}", m_name, message->payload());
					PostReply(std::move(message), response, 1);
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

private:
	std::string m_name;
	mq::postoffice::Dropbox m_dropbox;
};

void TestBasicNetworkPeerSetup()
{
	SetPostOfficeConfig(0, PostOfficeConfig{ "7781", 7781, R"(\\.\pipe\mqpipe0)",std::vector{
		NetPeer("127.0.0.1", 8177),
	}});

	SetPostOfficeConfig(1, PostOfficeConfig{ "8177", 8177, R"(\\.\pipe\mqpipe1)", std::vector{
		NetPeer("127.0.0.1", 7781),
	}});

	InitializePostOffice(0);
	InitializePostOffice(1);

	auto dropbox0 = TestDropbox(0, "test7781");
	auto dropbox1 = TestDropbox(1, "test8177");

	// allow both post offices to set up, otherwise messages will just get dropped with no destination
	std::this_thread::sleep_for(std::chrono::seconds(2));

	{
		mq::proto::routing::Address addr;
		addr.set_name("launcher");
		addr.set_mailbox("test7781");
		dropbox1.Post(addr, std::string("This is a test"));
	}


	{
		// this should fail with -4 because there are 2 launchers
		mq::proto::routing::Address addr;
		addr.set_name("launcher");
		addr.set_mailbox("test8177");
		dropbox0.Post(addr, std::string("Please respond"),
			[](int status, mq::postoffice::MessagePtr message)
			{
				SPDLOG_DEBUG("Received status {} and response: {}", message->status(), message->payload());
			});
	}


	{
		// this should succeed
		mq::proto::routing::Address addr;
		mq::proto::routing::Peer& peer = *addr.mutable_peer();
		peer.set_ip("127.0.0.1");
		peer.set_port(8177);
		addr.set_name("launcher");
		addr.set_mailbox("test8177");
		dropbox0.Post(addr, std::string("Please respond"),
			[](int status, mq::postoffice::MessagePtr message)
			{
				SPDLOG_DEBUG("Received status {} and response: {}", message->status(), message->payload());
			});
	}

	std::this_thread::sleep_for(std::chrono::seconds(2));

	ClearPostOfficeConfigs();
	ClearPostOffices();
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

	//Test();
	TestBasicNetworkPeerSetup();

	return 0;
}

