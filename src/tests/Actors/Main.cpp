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

void TestBasicNetworkPeerSetup()
{
	SetPostOfficeConfig(0, PostOfficeConfig{ 7781, R"(\\.\pipe\mqpipe0)",std::vector{
		NetPeer("127.0.0.1", 8177),
	}});

	SetPostOfficeConfig(1, PostOfficeConfig{ 8177, R"(\\.\pipe\mqpipe1)", std::vector{
		NetPeer("127.0.0.1", 7781),
	}});

	InitializePostOffice(0);
	InitializePostOffice(1);

	auto dropbox0 = mq::postoffice::GetPostOffice(0).RegisterAddress("test0", [](mq::ProtoMessagePtr&& message)
		{
			const auto envelope = message->Parse<mq::proto::routing::Envelope>();
			std::cout << "test0 received: " << envelope.payload() << "\n";
		});

	auto dropbox1 = mq::postoffice::GetPostOffice(1).RegisterAddress("test1", [](mq::ProtoMessagePtr&& message)
		{
			const auto envelope = message->Parse<mq::proto::routing::Envelope>();
			std::cout << "test1 received: " << envelope.payload() << "\n";
		});

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

	TestBasicNetworkPeerSetup();

	return 0;
}

