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

// The "old" chat plugin
#include <mq/Plugin.h>

PreSetup("MQ2Chat");

static const std::string DebugHeader("[MQ2] ");

//=================================================================================================

class ChatPlugin : public PLUGIN_MODULE_BASE
{
public:
	PLUGIN_MODULE_CONSTRUCTOR(ChatPlugin) : PLUGIN_MODULE_BASE_CALL("Chat")
	{
	}

	virtual void Initialize() override
	{
		DebugSpewAlways("Initializing MQ2Chat");
	}

	virtual void Shutdown() override
	{
		DebugSpewAlways("Shutting down MQ2Chat");
	}

	virtual void OnWriteChatColor(const char* message, int color, int filter) override
	{
		// This is called every time WriteChatColor is called by MQ2Main or any plugin,
		// IGNORING FILTERS, IF YOU NEED THEM MAKE SURE TO IMPLEMENT THEM. IF YOU DONT
		// CALL CEverQuest::dsp_chat MAKE SURE TO IMPLEMENT EVENTS HERE

		char Stripped[MAX_STRING];
		StripMQChat(message, Stripped);

		if (gFilterMacro == FILTERMACRO_NONE) return;
		if (!pEverQuest) return;
		if (gGameState != GAMESTATE_INGAME) return;

		auto output = DebugHeader + Stripped;
		if (output.size() > MAX_STRING)
			output.erase(MAX_STRING - 1);

		dsp_chat_no_events(output.c_str(), color);
	}
};

DECLARE_PLUGIN_MODULE(ChatPlugin);
