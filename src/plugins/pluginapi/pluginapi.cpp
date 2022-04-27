/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2022 MacroQuest Authors
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

#include <mq/plugin/pluginapi.h>

char INIFileName[MAX_STRING] = { 0 };

namespace mqplugin {

HINSTANCE ghPluginModule = nullptr;

bool PluginMain(HINSTANCE hModule, DWORD dwReason, void* lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		ghPluginModule = hModule;
		mq::DebugSpewAlways("%s Module Loaded", mqplugin::PluginName);
		sprintf_s(INIFileName, "%s\\%s.ini", mq::gPathConfig, mqplugin::PluginName);
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		mq::DebugSpewAlways("%s Module Unloaded", mqplugin::PluginName);
	}

	return true;
}

// This is a sentinel that is used to identify a plugin as being built with the
// mqnext codebase.
PLUGIN_API bool IsBuiltForNext = true;

PLUGIN_API const char EverQuestVersion[] = __ExpectedVersionDate " " __ExpectedVersionTime;

} // namespace mqplugin

#if __has_include("../../private/pluginapi-private.cpp")
#include "../../private/pluginapi-private.cpp"
#endif
