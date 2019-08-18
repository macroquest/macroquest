/*
 * MacroQuest2: The extension platform for EverQuest
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

// The "old" chat plugin
#include "../MQ2Plugin.h"

PreSetup("MQ2Chat");

PLUGIN_API void InitializePlugin()
{
	DebugSpewAlways("Initializing MQ2Chat");
}

PLUGIN_API void ShutdownPlugin()
{
	DebugSpewAlways("Shutting down MQ2Chat");

	// Remove commands, macro parameters, hooks, etc.
}

PLUGIN_API DWORD OnWriteChatColor(PCHAR Line, DWORD Color, DWORD Filter)
{
	// This is called every time WriteChatColor is called by MQ2Main or any plugin,
	// IGNORING FILTERS, IF YOU NEED THEM MAKE SURE TO IMPLEMENT THEM. IF YOU DONT
	// CALL CEverQuest::dsp_chat MAKE SURE TO IMPLEMENT EVENTS HERE

	CHAR Stripped[MAX_STRING];
	StripMQChat(Line, Stripped);

	if (gFilterMacro == FILTERMACRO_NONE) return 0;
	if (!ppEverQuest) return 0;
	if (gGameState != GAMESTATE_INGAME) return 0;

	if (!pEverQuest)
		return 0;

	dsp_chat_no_events(Stripped, Color, 1);
	return 0;
}

