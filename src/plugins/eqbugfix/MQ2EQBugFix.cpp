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

#include <mq/Plugin.h>

PreSetup("MQ2EQBugFix");

class CDisplay_Hook
{
public:
	int is_3dON_Trampoline();
	int is_3dON_Detour()
	{
		if (!this)
		{
			DebugSpew("MQ2EQBugFix::Crash avoided!");
			return 0;
		}
		return is_3dON_Trampoline();
	}
};
DETOUR_TRAMPOLINE_EMPTY(int CDisplay_Hook::is_3dON_Trampoline());

PLUGIN_API void InitializePlugin()
{
	DebugSpewAlways("Initializing MQ2EQBugFix");

	EzDetour(CDisplay__is3dON, &CDisplay_Hook::is_3dON_Detour, &CDisplay_Hook::is_3dON_Trampoline);
}

PLUGIN_API void ShutdownPlugin()
{
	DebugSpewAlways("Shutting down MQ2EQBugFix");

	RemoveDetour(CDisplay__is3dON);
}
