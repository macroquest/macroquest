/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2019 MacroQuest Authors
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

#include "pch.h"
#include "MQ2Main.h"
#include "CrashHandler.h"

#include "common/NamedPipes.h"

namespace mq {
NamedPipeClient gPipeClient{ mq::MQ2_PIPE_SERVER_PATH };

// we can't use a MQModule here (at least not for init/shutdown) because initialization order matters.

class PipeEventsHandler : public NamedPipeEvents
{
public:
	virtual void OnIncomingMessage(std::shared_ptr<PipeMessage> message) override
	{
		switch (message->GetMessageId())
		{
		case MQMessageId::MSG_MAIN_CRASHPAD_CONFIG:
			// Message needs to at least have some substance...
			if (message->size() > 0)
			{
				std::string pipeName{ message->get<const char>() };

				if (pipeName.empty())
				{
					InitializeCrashpad();
				}
				else
				{
					InitializeCrashpadPipe(message->get<const char>());
				}
			}
			break;

		case MQMessageId::MSG_MAIN_REQ_UNLOAD:
			EzCommand("/unload");
			break;
		}
	}
};

namespace pipeclient {
// mq::MQMessageId::MSG_AUTOLOGIN_PROFILE_LOADED:
// mq::MQMessageId::MSG_AUTOLOGIN_PROFILE_UNLOADED:
// mq::MQMessageId::MSG_AUTOLOGIN_PROFILE_CHARINFO:
// mq::MQMessageId::MSG_AUTOLOGIN_START_INSTANCE:

// This serialization is dead simple. Just separate fields with a colon. Assume no colons in the
// source data. If this needs to be performant in any way, then we will need to write actual
// serialization of binary data (with the bonus that it's not all strings).

// profile:account:server:char:pid
void NotifyCharacterLoad(const char* Profile, const char* Account, const char* Server, const char* Character)
{
	auto data = fmt::format("{}:{}:{}:{}:{}", Profile, Account, Server, Character, GetCurrentProcessId());
	gPipeClient.SendMessage(MQMessageId::MSG_AUTOLOGIN_PROFILE_LOADED, data.c_str(), data.length());
}

// profile:account:server:char:pid
void NotifyCharacterUnload(const char* Profile, const char* Account, const char* Server, const char* Character)
{
	auto data = fmt::format("{}:{}:{}:{}:{}", Profile, Account, Server, Character, GetCurrentProcessId());
	gPipeClient.SendMessage(MQMessageId::MSG_AUTOLOGIN_PROFILE_UNLOADED, data.c_str(), data.length());
}

// pid:class:level
void NotifyCharacterUpdate(const char* Class, const char* Level)
{
	auto data = fmt::format("{}:{}:{}", GetCurrentProcessId(), Class, Level);
	gPipeClient.SendMessage(MQMessageId::MSG_AUTOLOGIN_PROFILE_CHARINFO, data.c_str(), data.length());
}

void LoginServer(const char* Login, const char* Pass, const char* Server)
{
	auto data = fmt::format("s:{}:{}:{}", Login, Pass, Server);
	gPipeClient.SendMessage(MQMessageId::MSG_AUTOLOGIN_START_INSTANCE, data.c_str(), data.length());
}

void LoginCharacter(const char* Login, const char* Pass, const char* Server, const char* Character)
{
	auto data = fmt::format("c:{}:{}:{}:{}", Login, Pass, Server, Character);
	gPipeClient.SendMessage(MQMessageId::MSG_AUTOLOGIN_START_INSTANCE, data.c_str(), data.length());
}

void LoginProfile(const char* Profile, const char* Server, const char* Character)
{
	auto data = fmt::format("p:{}:{}:{}", Profile, Server, Character);
	gPipeClient.SendMessage(MQMessageId::MSG_AUTOLOGIN_START_INSTANCE, data.c_str(), data.length());
}
}

void InitializeMQ2PipeClient()
{
	gPipeClient.SetHandler(std::make_shared<PipeEventsHandler>());
	gPipeClient.Start();
	::atexit([]() { gPipeClient.Stop(); });
}

void ShutdownMQ2PipeClient()
{
	gPipeClient.Stop();
}
}

