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

PLUGIN_API void InitializePlugin()
{
	DebugSpewAlways("Initializing MQ2Chat");
}

PLUGIN_API void ShutdownPlugin()
{
	DebugSpewAlways("Shutting down MQ2Chat");

	// Remove commands, macro parameters, hooks, etc.
}

PLUGIN_API DWORD OnWriteChatColor(char* Line, DWORD Color, DWORD Filter)
{
	// This is called every time WriteChatColor is called by MQ2Main or any plugin,
	// IGNORING FILTERS, IF YOU NEED THEM MAKE SURE TO IMPLEMENT THEM. IF YOU DONT
	// CALL CEverQuest::dsp_chat MAKE SURE TO IMPLEMENT EVENTS HERE

	char Stripped[MAX_STRING];
	StripMQChat(Line, Stripped);

	if (gFilterMacro == FILTERMACRO_NONE) return 0;
	if (!pEverQuest) return 0;
	if (gGameState != GAMESTATE_INGAME) return 0;

	if (!pEverQuest)
		return 0;

	auto output = DebugHeader + Stripped;
	if (output.size() > MAX_STRING)
		output.erase(MAX_STRING - 1);

	dsp_chat_no_events(output.c_str(), Color, 1);
	return 0;
}

