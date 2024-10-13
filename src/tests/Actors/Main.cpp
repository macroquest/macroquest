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
#include "loader/Network.h"
//#include "main/MQPostOffice.h"

#include <fmt/format.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/wincolor_sink.h>
#include <spdlog/sinks/msvc_sink.h>

#include <cstdio>
#include <utility>

HWND hMainWnd;

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

void Test()
{
	const auto peer1 = mq::NetworkPeerAPI::GetOrCreate(7781,
		[](const mq::NetworkAddress& address, std::unique_ptr<uint8_t[]>&& message, const uint32_t length)
		{
			SPDLOG_DEBUG("Received message in peer1 of length {}: {}", length, std::string_view(reinterpret_cast<char*>(message.get()), length));
		}, [](const auto&) {}, [](const auto&) {});

	const auto peer2 = mq::NetworkPeerAPI::GetOrCreate(8177,
		[](const mq::NetworkAddress& address, std::unique_ptr<uint8_t[]>&& message, const uint32_t length)
		{
			SPDLOG_DEBUG("Received message in peer2 of length {}: {}", length, std::string_view(reinterpret_cast<char*>(message.get()), length));
		}, [](const auto&) {}, [](const auto&) {});

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

	auto dropbox0 = mq::postoffice::GetPostOffice(0).RegisterAddress("test7781", [](mq::ProtoMessagePtr&& message)
		{
			const auto envelope = message->Parse<mq::proto::routing::Envelope>();
			SPDLOG_DEBUG("test7781 received {}", envelope.payload());
		});

	auto dropbox1 = mq::postoffice::GetPostOffice(1).RegisterAddress("test8177", [](mq::ProtoMessagePtr&& message)
		{
			const auto envelope = message->Parse<mq::proto::routing::Envelope>();
			SPDLOG_DEBUG("test8177 received {}", envelope.payload());
		});

	// allow both post offices to set up, otherwise messages will just get dropped with no destination
	std::this_thread::sleep_for(std::chrono::seconds(2));

	mq::proto::routing::Address addr;
	addr.set_name("launcher");
	addr.set_mailbox("test0");
	dropbox1.Post(addr, std::string("This is a test"));

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

