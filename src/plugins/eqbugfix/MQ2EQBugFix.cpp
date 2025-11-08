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

#include <mq/Plugin.h>

PreSetup("MQ2EQBugFix");

static bool s_unloaded = false;

PLUGIN_API void OnPulse()
{
	if (!s_unloaded)
	{
		WriteChatf("\arMQ2EQBugFix is deprecated and can be safely unloaded");
		EzCommand("/plugin eqbugfix unload");

		s_unloaded = true;
	}
}
