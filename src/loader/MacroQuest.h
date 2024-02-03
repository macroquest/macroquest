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

#pragma once

#define MQ_NO_EXPORTS

#include "../common/Common.h"
#include "../common/HotKeys.h"

#include <cstdint>
#include <cstdio>
#include <ctime>

#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <string_view>

#include <windows.h>
#include <Windowsx.h>

#define _WIN32_DCOM
#include <comdef.h>
#include <Wbemidl.h>
#include <Tlhelp32.h>
#include <Psapi.h>
#include <shlobj.h>
#include <Commctrl.h>
#include <dbghelp.h>
#include <strsafe.h>
#include <windef.h>
#include <wincrypt.h>
#include <filesystem>

using namespace mq;

// Constants

#define WinClassName "__MacroQuestTray"
#define KEYLENGTH  0x00800000
#define ENCRYPT_ALGORITHM CALG_RC4
#define ENCRYPT_BLOCK_SIZE 8

// message types received over the named pipe server
constexpr int MSG_LOGINCHAR                 = 1;
constexpr int MSG_LOADED                    = 2;
constexpr int MSG_UNLOADED                  = 3;
constexpr int MSG_MQ2UNLOAD                 = 4;
constexpr int MSG_CLASSLVL                  = 5;

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


//----------------------------------------------------------------------------

// mirrors the implementation in mq2main. This could possibly be shared code
// between them.
namespace internal_paths
{
	extern std::string MQRoot;
	extern std::string Config;
	extern std::string MQini;
	extern std::string Macros;
	extern std::string Logs;
	extern std::string CrashDumps;
	extern std::string Plugins;
	extern std::string Resources;
}; // namespace internal_paths

//----------------------------------------------------------------------------

// Forward decls

extern HMENU hMenu;
extern HWND hMainWnd;
extern HINSTANCE g_hInst;

extern char gszMQVersion[64];

extern bool gEnableCrashpad;
extern bool gEnableSharedCrashpad;
extern bool gEnableSilentCrashpad;
extern bool gEnableCrashSubmissions;
extern bool gEnableRateLimit;

HWND LocateHotkeyWindow(WORD modkey, WORD hotkey);
void RegisterGlobalHotkey(HWND hWnd, std::string_view hotkeyString);
void UnregisterGlobalHotkey(std::string_view hotkeyString);
void UnregisterGlobalHotkey(HWND hWnd);

// ProcessList
HMODULE GetEQGameModuleByPID(DWORD processId);
uint8_t* GetMQ2MainBaseAddress(DWORD processId);
std::vector<HWND> GetEQWindowHandles();
bool IsEQGameProcessId(DWORD processId);
bool IsInjected(DWORD processId);
void Inject(uint32_t PID, std::chrono::milliseconds delay = std::chrono::milliseconds(0));
std::vector<DWORD> GetAllEqGameSessions();
bool ForceRemoteUnload();
HWND GetEQWindowHandleForProcessId(DWORD processId);
bool InitializeInjector(bool injectOnce);
void RefreshInjections();
void ShutdownInjector();
std::string GetInjecteePath();


// Utility
std::string GetVersionStringLocal(const std::filesystem::path& filePath);
std::string GetVersionStringRemote(const std::string& versionURL);
void ShowWarningBlocking(const std::string& Message);
void ShowErrorBlocking(const std::string& Message);
void ThreadedMessage(const std::string& Message, int MessageType);
void SetFocusWindowPID(uint32_t pid, bool state);
void SetForegroundWindowInternal(HWND hWnd);

// RemoteOps
HMODULE WINAPI GetRemoteModuleHandle(HANDLE hProcess, LPCSTR lpModuleName);
FARPROC WINAPI GetRemoteProcAddress(HANDLE hProcess, HMODULE hModule, LPCSTR lpProcName, UINT Ordinal = 0, BOOL UseOrdinal = FALSE);

// Get the name of the player in the process specified by the pid.
std::string GetLocalPlayer(DWORD pid);

// AutoLogin
extern HWND hEditProfileWnd;
void InitializeAutoLogin();
void ShutdownAutoLogin();
void AutoLoginRemoveProcess(DWORD processId);
bool HandleAutoLoginWindowMessage(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, LRESULT* result);
