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

#include <windows.h>

// custom window message types
constexpr int WM_USER_SHELLNOTIFY_CALLBACK  = (WM_USER + 1);
constexpr int WM_USER_SYSTRAY               = (WM_USER + 2);
constexpr int WM_USER_REGISTER_HK           = (WM_USER + 3);
constexpr int WM_USER_UNREGISTER_HK         = (WM_USER + 4);
constexpr int WM_USER_RESETLOADED           = (WM_USER + 5);
constexpr int WM_USER_SETLOADED             = (WM_USER + 6);
constexpr int WM_USER_UPDATECLASS           = (WM_USER + 7);
constexpr int WM_USER_UPDATELEVEL           = (WM_USER + 8);
constexpr int WM_USER_PROCESS_ADDED         = (WM_USER + 9);
constexpr int WM_USER_PROCESS_REMOVED       = (WM_USER + 10);
constexpr int WM_USER_CALLBACK              = (WM_USER + 11);

namespace launcher {

class LauncherPlugin
{
public:
	const char* PluginName;

	virtual void InitializePlugin() const = 0;
	virtual void ShutdownPlugin() const = 0;
	virtual bool OnWndProc(HWND hWnd, UINT MSG, WPARAM wParam, LPARAM lParam, LRESULT* plResult) const { return false; }

	LauncherPlugin(const char* name) : PluginName(name) {}

	// specialize this for your class creation
	template <typename T>
	static LauncherPlugin* Create()
	{
		static_assert(false, "You must specialize the Create() function like `template<> static LauncherPlugin* Create<PluginName>() {...}`");
	}

	template <typename T>
	static void Destroy(LauncherPlugin* plugin)
	{
		// specialize this template if you need to do extra work before deleting the plugin
		delete plugin;
	}
};

class LauncherInterface
{
public:
	virtual const char* ConfigPath() const = 0;
	virtual void Register(const char* name, LauncherPlugin* plugin) = 0;
	virtual LRESULT SendMessageToMain(UINT Msg, WPARAM wParam, LPARAM lParam) const = 0;
	virtual void RegisterHotkey(DWORD pid, const char* hotkey) const = 0;
	virtual void UnregisterHotkey(const char* hotkey) const = 0;
	virtual bool IsEQGameProcessId(DWORD processId) const = 0;
};

} // namespace launcher
