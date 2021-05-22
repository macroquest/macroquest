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

#pragma once

#include "LauncherInterface.h"
#include <common/Common.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/wincolor_sink.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/msvc_sink.h>

using namespace launcher;

#define PLUGIN_API extern "C" __declspec(dllexport)

extern char ConfigFileName[MAX_STRING];
extern LauncherInterface* Launcher;
extern LauncherPlugin* Plugin;

namespace launcherplugin {

extern const char* PluginName;
extern HMODULE PluginHandle;

LauncherInterface* GetLauncherInterface()
{
	HMODULE hexe = GetModuleHandleA(NULL);
	if (hexe != NULL)
	{
		auto getter = reinterpret_cast<LauncherInterface* (*)()>(GetProcAddress(hexe, "GetLauncherInterface"));
		if (getter != NULL) return getter();
	}
	return nullptr;
}

DWORD WINAPI PluginStart(LPVOID lParam)
{
	UNREFERENCED_PARAMETER(lParam);

	// get launcher
	Launcher = GetLauncherInterface();

	// create plugin
	sprintf_s(ConfigFileName, "%s\\%s.ini", Launcher->ConfigPath(), launcherplugin::PluginName);
	auto Plugin = CreatePlugin();

	// send plugin to launcher
	char this_name[2048];
	GetModuleFileNameA(PluginHandle, this_name, 2048);
	Launcher->Register(this_name, Plugin);
	SPDLOG_INFO("{} Module Loaded", launcherplugin::PluginName);
}

DWORD WINAPI PluginStop(LPVOID lParam)
{
	UNREFERENCED_PARAMETER(lParam);

	DestroyPlugin(Plugin);
	SPDLOG_INFO("{} Module Unloaded", launcherplugin::PluginName); \
}

//bool PluginMain(HMODULE hModule, DWORD dwReason, void* lpReserved)
//{
//	if (dwReason == DLL_PROCESS_ATTACH)
//	{
//		launcherplugin::PluginHandle = hModule;
//		CreateThread(NULL, 0, PluginStart, NULL, 0, NULL);
//	}
//	else if (dwReason == DLL_PROCESS_DETACH)
//	{
//		SPDLOG_INFO("{} Module Unloaded", launcherplugin::PluginName);
//	}
//
//	return true;
//}

} // namespace launcherplugin

#define PreSetup(pluginName) \
	class pluginName; \
	const char* launcherplugin::PluginName = #pluginName; \
	char ConfigFileName[MAX_STRING] = { 0 }; \
	launcher::LauncherInterface* Launcher = nullptr; \
	launcher::LauncherPlugin* Plugin = nullptr; \
	LauncherPlugin* CreatePlugin() { return launcher::LauncherPlugin::Create<pluginName>(); } \
	void DestroyPlugin(LauncherPlugin* plugin) { launcher::LauncherPlugin::Destroy<pluginName>(plugin); } \
	BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, void* lpReserved) \
	{ \
		if (dwReason == DLL_PROCESS_ATTACH) \
		{ \
			launcherplugin::PluginHandle = hModule; \
			CreateThread(NULL, 0, launcherplugin::PluginStart, NULL, 0, NULL); \
		} \
		else if (dwReason == DLL_PROCESS_DETACH) \
			CreateThread(NULL, 0, launcherplugin::PluginStop, NULL, 0, NULL); \
		return true; \
	}

#define PLUGIN_VERSION(Version) \
	extern __declspec(dllexport) float MQ2Version = static_cast<float>(Version);
