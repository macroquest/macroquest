/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2020 MacroQuest Authors
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

// The mqplugin namespace contains all shared code that is linked into a plugin. It does
// not reside within MQ2Main.

#include "../../src/main/MQ2Main.h"

#define PLUGIN_API extern "C" __declspec(dllexport)

// The name of the plugin.
extern char INIFileName[MAX_STRING];

namespace mqplugin {

extern const char* PluginName;
extern HINSTANCE ghPluginModule;

bool PluginMain(HINSTANCE hModule, DWORD dwReason, void* lpReserved);

} // namespace mqplugin

#define PreSetup(pluginName) \
	const char* mqplugin::PluginName = pluginName; \
	BOOL APIENTRY DllMain(HINSTANCE hModule, DWORD dwReason, void* lpReserved) \
	{ return mqplugin::PluginMain(hModule, dwReason, lpReserved); }

#define PLUGIN_VERSION(Version) \
	extern __declspec(dllexport) float MQ2Version = static_cast<float>(Version);


#if __has_include("../../../src/private/pluginapi-private.h")
#include "../../../src/private/pluginapi-private.h"
#endif

