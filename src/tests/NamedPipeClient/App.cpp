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

#include "routing/NamedPipes.h"
#include "routing/Routing.h"

#include <spdlog/spdlog.h>
#include <fmt/format.h>

#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>

#include <vector>
#include <thread>
#include <ppl.h>

int main(int argc, TCHAR* argv[])
{
	spdlog::set_level(spdlog::level::trace);

	mq::NamedPipeClient client(mq::MQ_PIPE_SERVER_PATH);
	client.Start();

	while (!client.IsConnected())
	{
		::Sleep(1000);
	}

	bool sendMessage = true;
	int count = 0;
	const int limit = 1;
	int inFlight = 0;

	while (count < 10)
	{
		while (client.IsConnected() && inFlight < limit)
		{
			std::string message = fmt::format("Test Message {0}", count++);
			++inFlight;

			sendMessage = false;
			SPDLOG_INFO("Sending ECHO request: message={0} length={1}", message, message.length());

			client.SendMessageWithResponse(mq::MQMessageId::MSG_ECHO, message.c_str(), (uint32_t)message.length() + 1,
				[&](int result, mq::PipeMessagePtr&& response)
				{
					--inFlight;
					if (response)
						SPDLOG_INFO("Received ECHO reply: length={1}", response->get<const char>(), response->size());
					else
						SPDLOG_ERROR("ECHO reply failed: status={0}", result);

				});
		}

		client.Process();
		::Sleep(1);
	}

	return 0;
}

