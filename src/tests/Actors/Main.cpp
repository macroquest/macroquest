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

#include <windows.h>

#include "routing/PostOffice.h"

#include "loader/PostOffice.h"
//#include "main/MQPostOffice.h"

#include <spdlog/spdlog.h>
#include <fmt/format.h>

#include <cstdio>
#include <utility>

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
			std::cout << envelope.payload() << "\n";
		});

	auto dropbox1 = mq::postoffice::GetPostOffice(1).RegisterAddress("test1", [](mq::ProtoMessagePtr&&) {});

	mq::proto::routing::Address addr;
	addr.set_name("launcher");
	addr.set_mailbox("test0");
	dropbox1.Post(addr, std::string("This is a test"));

	std::this_thread::sleep_for(std::chrono::seconds(2));

	ClearPostOfficeConfigs();
	ClearPostOffices();
}

int main(int argc, TCHAR* argv[])
{
	spdlog::set_level(spdlog::level::trace);

	TestBasicNetworkPeerSetup();

	return 0;
}

