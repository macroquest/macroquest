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

#include "MacroQuest.h"
#include "ProcessMonitor.h"
#include "Crashpad.h"
#include "PostOffice.h"
#include "ImGui.h"

#include "imgui/fonts/IconsFontAwesome.h"
#include "imgui/ImGuiUtils.h"

#include "resource.h"

#include <date/date.h>
#include <fmt/format.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/wincolor_sink.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/msvc_sink.h>
#include <extras/wil/Constants.h>
#include <wil/registry.h>
#include <wil/resource.h>

#include <filesystem>
#include <tuple>

#include <shellapi.h>
#include <fcntl.h>

#include <mq/utils/Naming.h>
#include <mq/utils/OS.h>
#include <mq/base/BuildInfo.h>

#include "AutoLogin.h"

#pragma comment(lib, "Psapi.lib")
#pragma comment(lib, "Crypt32.lib")
#pragma comment(lib, "dbghelp.lib")
#pragma comment(lib, "wbemuuid.lib")
#pragma comment(lib, "comctl32.lib")

namespace fs = std::filesystem;
using namespace std::chrono_literals;

HWND hMainWnd;

PROCESS_INFORMATION pInfo = { 0 };
STARTUPINFO sInfo = { 0 };
NOTIFYICONDATA NID = { 0 };
PAINTSTRUCT PS;

std::string ServerType;
char WinDir[_MAX_PATH] = { 0 };

uint32_t gNextWindowHotKey = 0;
uint32_t gPrevWindowHotKey = 0;
uint32_t gBossModeHotKey = 0;

bool gbAllEQWindowsHidden = false;
DWORD gLastEQGameSwitchedTo = 0;
HINSTANCE g_hInst = nullptr;

char gszWinClassName[64] = { 0 };
char gszWinName[64] = { 0 };

const int HOTKEY_EQWIN_PREVIOUS = 1;
const int HOTKEY_EQWIN_NEXT = 2;
const int HOTKEY_EQWIN_BOSSKEY = 3;

bool gbConsoleVisible = false;
bool gbConsoleCreated = false;
bool gCrashPadInitialized = false;

std::map<std::tuple<uint16_t, uint16_t>, HWND> hotkeyMap;
uint32_t gFocusProcessID = 0;

static uint32_t s_taskbarRestart = 0;

//----------------------------------------------------------------------------

#pragma region Console & Logging

void InitializeConsole()
{
	if (gbConsoleCreated)
		return;
	if (!AllocConsole())
		return;

	// std::cout, std::clog, std::cerr, std::cin
	FILE* fDummy;
	freopen_s(&fDummy, "CONOUT$", "w", stdout);
	freopen_s(&fDummy, "CONOUT$", "w", stderr);
	freopen_s(&fDummy, "CONIN$", "r", stdin);
	std::cout.clear();
	std::clog.clear();
	std::cerr.clear();
	std::cin.clear();

	SetConsoleCtrlHandler(nullptr, true);

	// set the screen buffer to be big enough to let us scroll text
	CONSOLE_SCREEN_BUFFER_INFO coninfo;
	::GetConsoleScreenBufferInfo(::GetStdHandle(STD_OUTPUT_HANDLE), &coninfo);
	coninfo.dwSize.Y = 500;
	::SetConsoleScreenBufferSize(::GetStdHandle(STD_OUTPUT_HANDLE), coninfo.dwSize);

	SetConsoleTitle("Debug Console");

	gbConsoleVisible = true;
	gbConsoleCreated = true;
}

void ShutdownConsole()
{
	if (!gbConsoleCreated)
		return;

	FreeConsole();

	gbConsoleVisible = false;
	gbConsoleCreated = false;
}

void HideConsole()
{
	if (gbConsoleCreated)
		ShowWindow(GetConsoleWindow(), SW_HIDE);
}

void ShowConsole()
{
	if (!gbConsoleCreated)
		InitializeConsole();
	else
		ShowWindow(GetConsoleWindow(), SW_SHOW);
}

void UpdateShowConsole(bool showConsole, bool updateIni)
{
	if (showConsole != gbConsoleVisible)
	{
		if (showConsole)
			ShowConsole();
		else
			HideConsole();

		gbConsoleVisible = showConsole;

		if (updateIni)
			WritePrivateProfileBool("MacroQuest", "ShowLoaderConsole", showConsole, internal_paths::MQini);
	}
}

void InitializeLogging()
{
	fs::path loggingPath = internal_paths::Logs;
	std::string filename = (loggingPath / fmt::format("MacroQuest-Launcher-{}.log",
		date::format("%Y%m%dT%H%M%SZ", date::floor<std::chrono::microseconds>(
			std::chrono::system_clock::now())))).string();

	// create color multi threaded logger

	auto logger = spdlog::create<spdlog::sinks::wincolor_stdout_sink_mt>("MQ");
	if (IsDebuggerPresent())
	{
		logger->sinks().push_back(std::make_shared<spdlog::sinks::msvc_sink_mt>());
	}

	auto fileSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(filename, true);
	logger->sinks().push_back(fileSink);

	spdlog::set_default_logger(logger);
	fileSink->set_pattern("%^%L %Y-%m-%d %T.%f%$ [%n] %v (%@)");
	spdlog::flush_on(spdlog::level::trace);
	spdlog::set_level(spdlog::level::trace);

	SPDLOG_DEBUG("Logging Initialized");
}

#pragma endregion

#pragma region Paths and Configuration

std::string internal_paths::MQRoot = ".";
std::string internal_paths::Config = "Config";
std::string internal_paths::MQini = internal_paths::Config + "\\MacroQuest.ini";
std::string internal_paths::Macros = "Macros";
std::string internal_paths::Logs = "Logs";
std::string internal_paths::CrashDumps = internal_paths::Logs + "\\Dumps";
std::string internal_paths::Plugins = "Plugins";
std::string internal_paths::Resources = "Resources";

bool InitializeDirectory(std::string& strPathToInit,
	const std::string& iniKey, const std::string& iniFile,
	const fs::path& appendPathIfRelative = internal_paths::MQRoot)
{
	fs::path pathToInit =
		GetPrivateProfileString("MacroQuest", iniKey, strPathToInit, iniFile);

	if (pathToInit.is_relative())
	{
		pathToInit = fs::absolute(appendPathIfRelative / pathToInit);
	}

	strPathToInit = pathToInit.string();

	std::error_code ec_fs;

	if (fs::exists(pathToInit, ec_fs) || fs::create_directories(pathToInit, ec_fs))
	{
		return true;
	}

	const std::string strTemp = "Could not find or create " + iniKey + " path: " + strPathToInit;
	MessageBox(nullptr, strTemp.c_str(), "MacroQuest", MB_OK);
	return false;
}

bool InitializePaths()
{
	// Get path right to the exe and then strip off the filename.
	char szFileName[_MAX_PATH] = { 0 };
	::GetModuleFileNameA(nullptr, szFileName, _MAX_PATH);

	char* szProcessName = strrchr(szFileName, '\\');
	*szProcessName = 0;

	internal_paths::MQRoot = szFileName;

	// Initialize the MacroQuest.ini and read in paths preferences, if any

	fs::path pathMQRoot = internal_paths::MQRoot;

	// If we still have a relative path to the MQ2 directory, make it absolute.
	if (pathMQRoot.is_relative())
	{
		pathMQRoot = fs::absolute(pathMQRoot).string();
	}

	internal_paths::MQRoot = pathMQRoot.string();
	std::error_code ec;

	// If the path to MQ2 doesn't exist none of our relative paths are going to work.
	if (fs::exists(pathMQRoot, ec))
	{
		internal_paths::MQini = GetCreateMacroQuestIni(pathMQRoot, internal_paths::Config, internal_paths::MQini);

		// Init the Config directory based on the ini we found.
		if (InitializeDirectory(internal_paths::Config, "ConfigPath", internal_paths::MQini, internal_paths::MQRoot))
		{
			// Initialize the rest
			if (InitializeDirectory(internal_paths::Macros, "MacroPath", internal_paths::MQini, internal_paths::MQRoot)
				&& InitializeDirectory(internal_paths::Logs, "LogPath", internal_paths::MQini, internal_paths::MQRoot)
				&& InitializeDirectory(internal_paths::CrashDumps, "CrashDumpPath", internal_paths::MQini, internal_paths::MQRoot)
				&& InitializeDirectory(internal_paths::Plugins, "PluginPath", internal_paths::MQini, internal_paths::MQRoot)
				&& InitializeDirectory(internal_paths::Resources, "ResourcePath", internal_paths::MQini, internal_paths::MQRoot))
			{
				return true;
			}
		}
	}

	return false;
}

#pragma endregion

//----------------------------------------------------------------------------

void SetFocusWindowPID(uint32_t pid, bool state)
{
	if (state)
	{
		gFocusProcessID = pid;
		SPDLOG_TRACE("Process has focus: {}", gFocusProcessID);
	}
	else if (pid == gFocusProcessID)
	{
		SPDLOG_TRACE("Process no longer has focus: {}", gFocusProcessID);
		gFocusProcessID = 0;
	}
}

void SetForegroundWindowInternal(HWND hWnd)
{
	if (IsWindow(hWnd))
	{
		if (IsIconic(hWnd))
			ShowWindow(hWnd, SW_RESTORE);

		if (!::SetForegroundWindow(hWnd) && !SendSetForegroundWindow(hWnd, gFocusProcessID))
		{
			SPDLOG_DEBUG("Failed to set foreground window. Doing it with min/restore.");

			ShowWindow(hWnd, SW_MINIMIZE);
			ShowWindow(hWnd, SW_RESTORE);
		}
	}
}

LRESULT HandleHotkey(WPARAM wParam, LPARAM lParam)
{
	if ((wParam == HOTKEY_EQWIN_NEXT && lParam == gNextWindowHotKey) ||
		(wParam == HOTKEY_EQWIN_PREVIOUS && lParam == gPrevWindowHotKey))
	{
		HWND hWindow = nullptr;
		int retryCount = 0;

		do
		{
			// Switch to the next or previous EQ window
			auto eqGames = GetAllEqGameSessions();
			if (eqGames.empty())
			{
				gLastEQGameSwitchedTo = 0;
				return 0;
			}

			if (gLastEQGameSwitchedTo == 0)
			{
				gLastEQGameSwitchedTo = eqGames[0];
			}
			else
			{
				// find what the next EQWindow should be
				if (wParam == HOTKEY_EQWIN_PREVIOUS)
					std::reverse(std::begin(eqGames), std::end(eqGames));

				// Find the current window
				auto iter = std::find(std::begin(eqGames), std::end(eqGames), gLastEQGameSwitchedTo);
				if (iter != std::end(eqGames))
					iter++;
				if (iter == std::end(eqGames))
				{
					iter = std::begin(eqGames);
				}

				gLastEQGameSwitchedTo = *iter;
			}

			hWindow = GetEQWindowHandleForProcessId(gLastEQGameSwitchedTo);
		} while (hWindow == nullptr && retryCount++ < 3); // If window isn't found for process, try again.

		if (hWindow != nullptr)
		{
			SetForegroundWindowInternal(hWindow);
		}
	}
	else if (wParam == HOTKEY_EQWIN_BOSSKEY)
	{
		if (lParam == gBossModeHotKey)
		{
			gbAllEQWindowsHidden = !gbAllEQWindowsHidden;

			auto eqWnds = GetEQWindowHandles();
			for (HWND hWnd : eqWnds)
			{
				ShowWindow(hWnd, gbAllEQWindowsHidden ? SW_HIDE : SW_SHOW);
			}
		}
	}
	else
	{
		// check if it is a profile hotkey.
		HWND hWndFG = GetForegroundWindow();

		if (HWND hWndHotkey = LocateHotkeyWindow(LOWORD(lParam), HIWORD(lParam)))
		{
			if (hWndHotkey != hWndFG)
				SetForegroundWindowInternal(hWndHotkey);
		}
	}

	return 0;
}

void CheckMQ2MainUpdate(bool alwaysDisplay = false)
{
#ifdef MQ_UPDATE_URL
	const std::string local_version = GetVersionStringLocal("./MQ2Main.dll");
	const std::string remote_version = GetVersionStringRemote(MQ_UPDATE_URL);
	std::string strMessage = "No updates available.\n\nCurrent Version: ";
	int iMessageType = MB_OK;
	// If the return is FAILED or contains a web page (account for cloudflare outages)
	if (remote_version == "FAILED" || remote_version.find('<') != std::string::npos || remote_version.find('>') != std::string::npos)
	{
		strMessage = "Failed to retrieve remote version information";
		iMessageType |= MB_ICONERROR;
	}
	else if (local_version == "FAILED")
	{
		strMessage = "Failed to retrieve local version information";
		iMessageType |= MB_ICONERROR;
	}
	else if (remote_version == local_version)
	{
		strMessage.append(local_version);
		iMessageType |= MB_ICONINFORMATION;
	}
	else
	{
		strMessage = "UPDATE AVAILABLE!\n\nYou are running version: ";
		strMessage.append(local_version);
		strMessage.append("\n\nCurrent latest version: ");
		strMessage.append(remote_version);
		iMessageType |= MB_ICONWARNING;
	}
	if (alwaysDisplay || !(iMessageType & MB_ICONINFORMATION))
	{
		ThreadedMessage(strMessage,  iMessageType);
	}
#endif
}

// https://docs.microsoft.com/en-us/windows/win32/api/wow64apiset/nf-wow64apiset-iswow64process
bool IsWow64()
{
	typedef BOOL (WINAPI* LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);
	BOOL bIsWow64 = false;

    //IsWow64Process is not available on all supported versions of Windows.
    //Use GetModuleHandle to get a handle to the DLL that contains the function
    //and GetProcAddress to get a pointer to the function if available.

    const LPFN_ISWOW64PROCESS fnIsWow64Process = (LPFN_ISWOW64PROCESS)GetProcAddress(GetModuleHandle(TEXT("kernel32")), "IsWow64Process");

    if(nullptr != fnIsWow64Process)
    {
        if (!fnIsWow64Process(GetCurrentProcess(), &bIsWow64))
        {
            //handle error (but I'm not going to)
        }
    }
    return bIsWow64;
}

enum AppCompatFlagReturn {
	SUCCESS = 0,
	ERROR_GENERAL = -1,
	ERROR_NOLAYERS = -2,
	ERROR_ENUMERATION = -3,
};

int CheckAppCompatFlags(HKEY RegBase, const std::vector<std::string>& SearchItems, bool crossCheck = false)
{
	// if there are no search items, there is nothing to search.
	if (SearchItems.empty())
	{
		return AppCompatFlagReturn::SUCCESS;
	}

	HKEY hRegKey;

	int retVal = AppCompatFlagReturn::ERROR_GENERAL;
	// Check the parent registry key first, if this is missing there's an issue (permissions, manual intervention)
	// crossCheck should actually flip archs, but since we always build in 32 bit there's no reason to do it the other direction
	if (RegOpenKeyEx(RegBase, "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\AppCompatFlags", 0, crossCheck ? KEY_READ|KEY_WOW64_64KEY : KEY_READ, &hRegKey) == ERROR_SUCCESS)
	{
		// Now we can check the full key
		if (RegOpenKeyEx(RegBase, "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\AppCompatFlags\\Layers", 0, crossCheck ? KEY_READ | KEY_WOW64_64KEY : KEY_READ, &hRegKey) != ERROR_SUCCESS)
		{
			retVal = AppCompatFlagReturn::ERROR_NOLAYERS;
		}
		else
		{
			DWORD n = 0;
			if (RegQueryInfoKey(hRegKey, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, &n, nullptr, nullptr, nullptr, nullptr) == ERROR_SUCCESS)
			{
				retVal = AppCompatFlagReturn::SUCCESS;
				for (DWORD i = 0; i < n; ++i)
				{
					char value[wil::max_registry_value_name_length + 1] = { 0 };
					DWORD valueSize = wil::max_registry_value_name_length;
					// We know we're done on the first error since they're sequential
					if (const int res = RegEnumValue(hRegKey, i, value, &valueSize, nullptr, nullptr, nullptr, nullptr) != ERROR_SUCCESS)
					{
						if (res != ERROR_NO_MORE_ITEMS)
						{
							retVal = AppCompatFlagReturn::ERROR_ENUMERATION;
						}
						break;
					}

					for (const std::string& searchItem : SearchItems)
					{
						// If it's in the name value, we don't need to check the data (only valid for exe, but it's fast)
						if (ci_find_substr(value, searchItem) != -1)
						{
							retVal++;
						}
						else
						{
							char data[wil::max_registry_value_name_length + 1] = { 0 };
							DWORD dataSize = wil::max_registry_value_name_length;
							if (RegGetValue(hRegKey, nullptr, value, RRF_RT_REG_SZ, nullptr, data, &dataSize) == ERROR_SUCCESS)
							{
								if (ci_find_substr(value, searchItem) != -1)
								{
									retVal++;
								}
							}
						}
					}
				}
			}
			RegCloseKey(hRegKey);
		}
	}
	return retVal;
}

void CheckAppCompat(bool alwaysDisplay = false)
{
	std::string searchPaths[] = { internal_paths::MQRoot, internal_paths::Plugins };
	std::string searchExtensions[] = { ".dll" };

	std::vector<std::string> checkFor;

	std::error_code ec;
	for (const std::string& searchPath : searchPaths)
	{
		if (std::filesystem::exists(searchPath, ec))
		{
			for (const auto& file : std::filesystem::directory_iterator(searchPath))
			{
				if (is_regular_file(file, ec) && file.path().has_extension())
				{
					std::filesystem::path filePath =  file.path();
					for (const std::string& searchExtension : searchExtensions)
					{
						if (ci_equals(filePath.extension().string(), searchExtension))
						{
							checkFor.push_back(filePath.filename().string());
						}
					}
				}
			}
		}
	}

	int iMessageType = MB_OK;

	std::string strMessage = "No Application Compatibility Layer issues found.";

	bool crossCheck = IsWow64();
	int foundHKLM = CheckAppCompatFlags(HKEY_LOCAL_MACHINE, checkFor);
	if (foundHKLM == AppCompatFlagReturn::SUCCESS && crossCheck)
	{
		foundHKLM = CheckAppCompatFlags(HKEY_LOCAL_MACHINE, checkFor, true);
	}

	int foundHKCU = CheckAppCompatFlags(HKEY_CURRENT_USER, checkFor);
	if (foundHKCU == AppCompatFlagReturn::SUCCESS && crossCheck)
	{
		foundHKCU = CheckAppCompatFlags(HKEY_CURRENT_USER, checkFor, true);
	}

	// For now, ignore issues with the NO_LAYERS return.  Future work might be to include it and have an option to display it based on verbosity or check the actual returns to determine what to display here
	if (foundHKLM != AppCompatFlagReturn::SUCCESS && foundHKLM != AppCompatFlagReturn::ERROR_NOLAYERS || foundHKCU != AppCompatFlagReturn::SUCCESS && foundHKCU != AppCompatFlagReturn::ERROR_NOLAYERS)
	{
		strMessage = "Application Compatibility Layer issues found:\n";
		iMessageType |= MB_ICONWARNING;

		if (foundHKLM < 0)
		{
			strMessage += fmt::format("\nError accessing values in HKEY_LOCAL_MACHINE: {}", foundHKLM);
			iMessageType = MB_OK | MB_ICONERROR;
		}
		else if (foundHKLM > 0)
		{
			strMessage += fmt::format("\nFound {} issue{} in HKEY_LOCAL_MACHINE.", foundHKLM, foundHKLM > 1 ? "s" : "");
		}

		if (foundHKCU < 0)
		{
			strMessage += fmt::format("\nError accessing values in HKEY_CURRENT_USER: {}", foundHKCU);
		}
		else if (foundHKCU > 0)
		{
			strMessage += fmt::format("\nFound {} issue{} in HKEY_CURRENT_USER.", foundHKCU, foundHKCU > 1 ? "s" : "");
			iMessageType = MB_OK | MB_ICONERROR;
		}
	}
	else
	{
		iMessageType |= MB_ICONINFORMATION;
	}

	if (alwaysDisplay || !(iMessageType & MB_ICONINFORMATION))
	{
		ThreadedMessage(strMessage, iMessageType);
	}
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT MSG, WPARAM wParam, LPARAM lParam)
{
	if (LauncherImGui::HandleWndProc(hWnd, MSG, wParam, lParam))
		return true;

	switch (MSG)
	{
	case WM_HOTKEY:
		return HandleHotkey(wParam, lParam);

	case WM_WINDOWPOSCHANGING:
		Shell_NotifyIcon(NIM_ADD, &NID); //Add the systray icon.
		break;

	case WM_SIZE:
		Shell_NotifyIcon(NIM_ADD, &NID); //Add the systray icon.
		break;

	case WM_SYSCOMMAND:
		switch (LOWORD(wParam)) // We capture the 'X' button
		{
		case SC_CLOSE:
			Shell_NotifyIcon(NIM_ADD, &NID);
			return 0;

		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		}
		break;

	case WM_USER_PROCESS_ADDED:
		Inject((DWORD)wParam, 1s);
		break;

	case WM_USER_PROCESS_REMOVED:
		AutoLoginRemoveProcess((DWORD)wParam);
		break;

	case WM_USER_CALLBACK:
		break;

	default:
		if (MSG == NID.uCallbackMessage) // This is where we get our SysTray Icon notifications.
		{
			switch (lParam)
			{
			case WM_LBUTTONUP:
				LauncherImGui::OpenMainWindow();
				break;

			case WM_RBUTTONUP:
				LauncherImGui::OpenContextMenu();
				break;
			}
			break;
		}
		if (MSG == s_taskbarRestart)
		{
			Shell_NotifyIcon(NIM_ADD, &NID);
		}
	}

	return DefWindowProc(hWnd, MSG, wParam, lParam);
}

void ShowMacroQuestInfo()
{
	auto link = [](const std::string& label, const std::string& url)
		{
			auto add_underline = [](ImColor color)
				{
					ImVec2 min = ImGui::GetItemRectMin();
					ImVec2 max = ImGui::GetItemRectMax();
					min.y = max.y;
					ImGui::GetWindowDrawList()->AddLine(min, max, color, 1.f);
				};

			ImGui::PushStyleColor(ImGuiCol_Text, ImGui::GetStyle().Colors[ImGuiCol_ButtonHovered]);
			ImGui::Text(label.c_str());
			ImGui::PopStyleColor();

			if (ImGui::IsItemHovered())
			{
				if (ImGui::IsMouseClicked(ImGuiMouseButton_Left))
				{
					ShellExecuteA(nullptr, "open", url.c_str(), nullptr, nullptr, SW_SHOW);
				}
				add_underline(ImGui::GetStyle().Colors[ImGuiCol_ButtonHovered]);
				ImGui::SetTooltip(ICON_FA_LINK " Open in default browser\n%s", url.c_str());
			}
			else
			{
				add_underline(ImGui::GetStyle().Colors[ImGuiCol_Button]);
			}
		};

	ImGui::Spacing();
	if (mq::imgui::LargeTextFont != nullptr) ImGui::PushFont(mq::imgui::LargeTextFont);
	ImGui::Text("MacroQuest Useful Links");
	if (mq::imgui::LargeTextFont != nullptr) ImGui::PopFont();
	ImGui::Separator();
	ImGui::Spacing();

	ImGui::Bullet(); link("MacroQuest Website", "https://macroquest.org");
	ImGui::Bullet(); link("MacroQuest Documentation", "https://docs.macroquest.org/");
	ImGui::Bullet(); link("MacroQuest on Github", "https://github.com/macroquest/macroquest");
}

void ShowMacroQuestMenu()
{
	if (ImGui::BeginMenu("Open Folder"))
	{
		if (ImGui::MenuItem("MacroQuest Root"))
			ShellExecuteA(nullptr, "explore", internal_paths::MQRoot.c_str(), nullptr, nullptr, SW_SHOW);
		if (ImGui::MenuItem("Config"))
			ShellExecuteA(nullptr, "explore", internal_paths::Config.c_str(), nullptr, nullptr, SW_SHOW);
		if (ImGui::MenuItem("Macros"))
			ShellExecuteA(nullptr, "explore", internal_paths::Macros.c_str(), nullptr, nullptr, SW_SHOW);
		if (ImGui::MenuItem("Resources"))
			ShellExecuteA(nullptr, "explore", internal_paths::Resources.c_str(), nullptr, nullptr, SW_SHOW);
		if (ImGui::MenuItem("Logs"))
			ShellExecuteA(nullptr, "explore", internal_paths::Logs.c_str(), nullptr, nullptr, SW_SHOW);
		if (ImGui::MenuItem("Crash Dumps"))
			ShellExecuteA(nullptr, "explore", internal_paths::CrashDumps.c_str(), nullptr, nullptr, SW_SHOW);

		ImGui::EndMenu();
	}

	if (ImGui::BeginMenu("MQ Sites"))
	{
		if (ImGui::MenuItem("GitHub"))
			ShellExecuteA(nullptr, "open", "https://github.com/macroquest/macroquest", nullptr, nullptr, SW_SHOW);
		if (ImGui::MenuItem("Issue Tracker"))
			ShellExecuteA(nullptr, "open", "https://github.com/macroquest/macroquest/issues", nullptr, nullptr, SW_SHOW);

		ImGui::Separator();

		if (ImGui::MenuItem("Website"))
			ShellExecuteA(nullptr, "open", "https://macroquest.org", nullptr, nullptr, SW_SHOW);
		if (ImGui::MenuItem("Forums"))
			ShellExecuteA(nullptr, "open", "https://macroquest.org/phpBB3", nullptr, nullptr, SW_SHOW);
		if (ImGui::MenuItem("Wiki"))
			ShellExecuteA(nullptr, "open", "https://docs.macroquest.org", nullptr, nullptr, SW_SHOW);

		ImGui::EndMenu();
	}

	if (ImGui::MenuItem("Change Log"))
	{
		// NOTE: This change log search logic is duplicated in the news feed in MQ2Main.cpp
		// This is one of the few places we want to hardcode the path since if the user redirects their resources we would not have distributed that file and they would always have old news.
		const std::filesystem::path pathMQRootChangeLog = std::filesystem::path(internal_paths::MQRoot) / "resources" / "CHANGELOG.md";
		const std::filesystem::path pathResourceChangeLog = std::filesystem::path(internal_paths::Resources) / "CHANGELOG.md";
		// Default to the one in the resource path.
		std::filesystem::path pathChangeLog = pathResourceChangeLog;

		std::error_code ec;
		// If the paths are different, and the Resource Change Log doesn't exist or is older than the Root\Resource changelog
		if (pathMQRootChangeLog != pathResourceChangeLog
			&& (!exists(pathResourceChangeLog, ec)
				|| last_write_time(pathMQRootChangeLog, ec) > last_write_time(pathResourceChangeLog, ec)))
		{
			pathChangeLog = pathMQRootChangeLog;
		}
		// END Duplicate logic

		if (exists(pathChangeLog))
		{
			ShellExecuteA(nullptr, "open", pathChangeLog.string().c_str(), nullptr, nullptr, SW_SHOW);
		}
		else
		{
			LauncherImGui::OpenMessageBox(nullptr, fmt::format("Could not find CHANGELOG.md: {}", pathChangeLog.string()), "View Changelog");
		}
	}

	if (ImGui::MenuItem("INI File"))
		ShellExecuteA(nullptr, "open", internal_paths::MQini.c_str(), nullptr, internal_paths::MQRoot.c_str(), SW_SHOW);
}

void ShowEQBCMenu()
{
	if (ImGui::MenuItem("Start EQBC Server"))
	{
		if (IsProcessRunning("eqbcs.exe"))
		{
			LauncherImGui::OpenMessageBox(nullptr, "EQBCS is already running.", "EQBCS Launcher");
		}
		else
		{
			std::string strCommandLine = fmt::format("{}\\eqbcs.exe", internal_paths::MQRoot);
			std::error_code ec;
			if (std::filesystem::exists(strCommandLine, ec))
			{
				ShellExecuteA(nullptr, "open", strCommandLine.c_str(), nullptr, internal_paths::MQRoot.c_str(), SW_SHOW);
			}
			else
			{
				LauncherImGui::OpenMessageBox(nullptr, fmt::format("EQBCS could not be found: {}", strCommandLine), "EQBCS Launcher");
			}
		}
	}
}

void ShowAdvancedMenu()
{
	if (ImGui::BeginMenu("Advanced"))
	{
		if (ImGui::MenuItem("Toggle Debug Console"))
			UpdateShowConsole(!gbConsoleVisible, true);

		if (ImGui::MenuItem("Unload All Instances"))
			SendUnloadAllCommand();

		if (ImGui::MenuItem("Unload All Instances (Forced)"))
			SendForceUnloadAllCommand();

		if (ImGui::MenuItem("Check App Compatibility"))
			CheckAppCompat(true);

		ImGui::EndMenu();
	}

	if (ImGui::MenuItem("Refresh Injections"))
		RefreshInjections();
}

void InitializeWindows()
{
	WNDCLASS wc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	wc.hIcon = LoadIcon(g_hInst, MAKEINTRESOURCE(IDI_ICON1));
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.lpszClassName = gszWinClassName;
	wc.lpszMenuName = nullptr;
	wc.hInstance = g_hInst;
	RegisterClass(&wc);

	hMainWnd = ::CreateWindowA(gszWinClassName, gszWinName, WS_OVERLAPPEDWINDOW, 0, 0,
		GetSystemMetrics(SM_CXFULLSCREEN), GetSystemMetrics(SM_CYFULLSCREEN),
		nullptr, nullptr, g_hInst, nullptr);

	::SendMessageA(hMainWnd, WM_SETICON, ICON_SMALL, (LPARAM)::LoadIconA(g_hInst, MAKEINTRESOURCE(IDI_ICON1)));

	NID.cbSize = sizeof(NID);
	NID.hIcon = LoadIcon(g_hInst, MAKEINTRESOURCE(IDI_ICON1));
	NID.uCallbackMessage = WM_USER_SHELLNOTIFY_CALLBACK;
	NID.hWnd = hMainWnd;
	NID.uID = WM_USER_SYSTRAY;
	NID.uFlags = NIF_TIP | NIF_ICON | NIF_MESSAGE;
	Shell_NotifyIcon(NIM_ADD, &NID);

	s_taskbarRestart = ::RegisterWindowMessageW(L"TaskbarCreated");

	LauncherImGui::AddMainPanel("MacroQuest Info", ShowMacroQuestInfo);
	LauncherImGui::AddContextGroup("##MacroQuest", ShowMacroQuestMenu);
}

class MQ2ProcessMonitorEvents : public ProcessMonitorEvents
{
public:
	virtual void HandleProcessCreation(uint32_t processId) override
	{
		SPDLOG_INFO("New process detected: {}", processId);
		::SendMessageA(hMainWnd, WM_USER_PROCESS_ADDED, processId, 0);
	}

	virtual void HandleProcessDestruction(uint32_t processId) override
	{
		SPDLOG_DEBUG("Process closed: {}", processId);
		::SendMessageA(hMainWnd, WM_USER_PROCESS_REMOVED, processId, 0);
	}
};

void InitializeVersionInfo()
{
	std::string injectee = GetInjecteePath();
	SPDLOG_INFO("MQ2Main Path: {0}", injectee);

	wil::unique_hmodule hModule(::LoadLibraryA(injectee.c_str()));
	if (!hModule.is_valid())
	{
		SPDLOG_WARN("MQ2Main was not loadable at startup. This might cause issues later");
		return;
	}

	char* szVersion = (char*)GetProcAddress(hModule.get(), "gszVersion");
	if (!szVersion)
	{
		SPDLOG_WARN("Failed to get version from MQ2Main at startup. This may cause issues later");
		return;
	}

	ServerType = GetBuildTargetName(
		static_cast<BuildTarget>(*reinterpret_cast<int*>(GetProcAddress(hModule.get(), "gBuild"))));

	fmt::format_to(NID.szTip, "{} [{} ({})]\0", gszWinName, szVersion, ServerType);
	SPDLOG_INFO("Build: {0}", NID.szTip);

	to_lower(ServerType);
}

// ***************************************************************************
// Function:    WinMain
// Description: EXE entry point
// ***************************************************************************
int WINAPI CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd)
{
	g_hInst = hInstance;

	// Initialize Paths so we know where to put our logs and where to load our config from
	InitializePaths();

	bool showConsole = GetPrivateProfileBool("MacroQuest", "ShowLoaderConsole", false, internal_paths::MQini);
	UpdateShowConsole(showConsole, false);

	// Initialize Logging
	InitializeLogging();

	SPDLOG_INFO("Starting MacroQuest Loader. Built " __TIMESTAMP__);

	// Initialize crash handler
	gCrashPadInitialized = InitializeCrashpad();
	if (!gCrashPadInitialized && gEnableCrashpad)
		SPDLOG_WARN("Crashpad handler failed to initialize.");
	else if (!gEnableCrashpad)
		SPDLOG_INFO("Crashpad is disabled.");

	// TODO:  Allow argument processing of passing ini file so the file can be launched from anywhere
	std::string fullCommandLine = "";
	bool spawnedProcess = false;
	bool disableAppCompatCheck = false;
	bool injectOnce = false;
	for (int i = 1; i < __argc; ++i)
	{
		// Recreate the command line
		if (!fullCommandLine.empty())
		{
			fullCommandLine += " ";
		}
		std::string thisArg = __argv[i];
		if (thisArg.find(' ') != std::string::npos)
		{
			thisArg = fmt::format("\"{}\"", thisArg);
		}
		fullCommandLine += thisArg;

		if (ci_find_substr(thisArg, "noappcompat") != -1)
		{
			disableAppCompatCheck = true;
		}
		else if (ci_find_substr(thisArg, "injectonce") != -1)
		{
			injectOnce = true;
		}
		// Only need this if we're not already the spawned process
		else if (!spawnedProcess && ci_find_substr(thisArg, "spawnedprocess") != -1)
		{
			SPDLOG_INFO("I am a spawned process");
			spawnedProcess = true;
		}
	}

	if (!spawnedProcess)
	{
		char szFileName[MAX_PATH] = { 0 };
		GetModuleFileName(nullptr, szFileName, MAX_PATH);
		std::filesystem::path thisProgramPath = szFileName;

		if(!thisProgramPath.is_absolute())
		{
			std::error_code ec;
			thisProgramPath = absolute(thisProgramPath, ec);
		}

		std::filesystem::path ProgramPath;

		const std::string oldProcessName = GetPrivateProfileValue("Internal", "SpawnedProcess", "", internal_paths::MQini.c_str());
		if (oldProcessName.empty())
		{
			ProgramPath = GetUniqueFileName(thisProgramPath.parent_path(), "exe");
		}
		else
		{
			ProgramPath = thisProgramPath.parent_path() / oldProcessName;
		}

		// Launch a new process if this process isn't the renamed process
		if (!ci_equals(ProgramPath.filename().string(), thisProgramPath.filename().string()))
		{
			std::error_code ec;
			if (exists(ProgramPath, ec))
			{
				if (IsProcessRunning(oldProcessName.c_str()))
				{
					if (!file_equals(thisProgramPath, ProgramPath))
					{
						ShowWarningBlocking("Please exit out of the alternate loader for an update: " + oldProcessName);
					}
					else
					{
						SPDLOG_WARN("Alternate loader is already running: " + ProgramPath.string());
						exit(0);
					}
				}
				if (!file_equals(thisProgramPath, ProgramPath) && !remove(ProgramPath, ec))
				{
					ShowErrorBlocking("Could not delete alternate loader: " + ProgramPath.string());
					exit(1);
				}
			}
			if (!exists(ProgramPath, ec) && !std::filesystem::copy_file(thisProgramPath, ProgramPath, ec))
			{
				ShowErrorBlocking("Could not create duplicate of this program at: " + ProgramPath.string());
				exit(1);
			}

			fullCommandLine = fmt::format("\"{}\" {} /spawnedprocess", ProgramPath.string(), fullCommandLine);

			STARTUPINFO si = {};
			wil::unique_process_information pi;

			SPDLOG_INFO("Relaunching as spawned process");

			if (CreateProcess(ProgramPath.string().c_str(), // Application Name - Null says use command line processor
					&fullCommandLine[0], // Command line to run
					nullptr,             // Process Attributes - handle not inheritable
					nullptr,             // Thread Attributes - handle not inheritable
					false,               // Set handle inheritance to FALSE
					CREATE_NEW_CONSOLE,  // Creation Flags - Create a new console window instead of running in the existing console
					nullptr,             // Use parent's environment block
					nullptr,             // Use parent's starting directory
					&si,                 // Pointer to STARTUPINFO structure
					&pi)                 // Pointer to PROCESS_INFORMATION structure
				)
			{
				WritePrivateProfileValue("Internal", "SpawnedProcess", ProgramPath.filename().string(), internal_paths::MQini.c_str());
			}
			else
			{
				ShowErrorBlocking("Could not launch alternate loader at: " + ProgramPath.string());
				exit(1);
			}
			exit(0);
		}
	}

	// Initialize COM
	auto coCleanup = wil::CoInitializeEx();

	INITCOMMONCONTROLSEX ccex = { sizeof(INITCOMMONCONTROLSEX) };
	ccex.dwICC = ICC_STANDARD_CLASSES | ICC_HOTKEY_CLASS;
	::InitCommonControlsEx(&ccex);

	GetPrivateProfileString("MacroQuest", "MacroQuestWinClassName", "__MacroQuestTray", gszWinClassName, lengthof(gszWinClassName), internal_paths::MQini);
	GetPrivateProfileString("MacroQuest", "MacroQuestWinName", "MacroQuest", gszWinName, lengthof(gszWinClassName), internal_paths::MQini);

	// Make sure a MacroQuest instance isn't already running, if one is running, exit
	HWND hWndRunning = FindWindow(gszWinClassName, gszWinName);
	if (hWndRunning != nullptr)
	{
		SPDLOG_INFO("Closing because another window of class \"{}\" is open", gszWinClassName);
		return 0;
	}

	const std::string cycleNextWindowKey = GetPrivateProfileString("MacroQuest", "CycleNextWindow", "", internal_paths::MQini);
	const std::string cyclePrevWindowKey = GetPrivateProfileString("MacroQuest", "CyclePrevWindow", "", internal_paths::MQini);
	const std::string bossModeKey = GetPrivateProfileString("MacroQuest", "BossMode", "", internal_paths::MQini);

	// Update version information shown in the system tray tooltip
	InitializeVersionInfo();
	InitializeNamedPipeServer();
	InitializeWindows();
	InitializeAutoLogin();

	auto pMonitorEvents = std::make_unique<MQ2ProcessMonitorEvents>();
	StartProcessMonitor(pMonitorEvents.get());

	// Handle global hotkeys
	uint16_t modkey = 0;
	uint16_t hotkey = 0;

	if (!cycleNextWindowKey.empty() && cycleNextWindowKey != "0")
	{
		if (ConvertStringToModifiersAndVirtualKey(cycleNextWindowKey, modkey, hotkey))
		{
			if (RegisterHotKey(hMainWnd, HOTKEY_EQWIN_NEXT, modkey, hotkey))
			{
				gNextWindowHotKey = MAKELONG(modkey, hotkey);
			}
		}
	}
	if (!cyclePrevWindowKey.empty() && cyclePrevWindowKey != "0")
	{
		if (ConvertStringToModifiersAndVirtualKey(cyclePrevWindowKey, modkey, hotkey))
		{
			if (RegisterHotKey(hMainWnd, HOTKEY_EQWIN_PREVIOUS, modkey, hotkey))
			{
				gPrevWindowHotKey = MAKELONG(modkey, hotkey);
			}
		}
	}
	if (!bossModeKey.empty() && bossModeKey != "0")
	{
		if (ConvertStringToModifiersAndVirtualKey(bossModeKey, modkey, hotkey))
		{
			if (RegisterHotKey(hMainWnd, HOTKEY_EQWIN_BOSSKEY, modkey, hotkey))
			{
				gBossModeHotKey = MAKELONG(modkey, hotkey);
			}
		}
	}

	// This also initializes mqversion
	if (!InitializeInjector(injectOnce))
		PostQuitMessage(1);

	CheckMQ2MainUpdate();

	if (!GetPrivateProfileBool("MacroQuest", "DisableAppCompatCheck", disableAppCompatCheck, internal_paths::MQini))
		CheckAppCompat();

	// EQBC menu
	LauncherImGui::AddContextGroup("EQBC", ShowEQBCMenu);

	// advanced menu items
	LauncherImGui::AddContextGroup("##Advanced Menu Items", ShowAdvancedMenu);

	SPDLOG_INFO("Waiting for events...");

	MSG msg;
	LauncherImGui::Run(
		[&msg]()
		{
			ProcessPipeServer();
			ProcessPendingLogins();
			if (PeekMessageA(&msg, nullptr, 0, 0, PM_REMOVE) != 0)
			{
				switch (msg.message)
				{
				case WM_QUIT:
					return false;
				default:
					TranslateMessage(&msg);
					DispatchMessageA(&msg);
					return true;
				}
			}

			return true;
		});

	SPDLOG_INFO("Shutting down...");

	// Shutdown
	UnregisterHotKey(hMainWnd, 1);
	UnregisterHotKey(hMainWnd, 2);
	UnregisterHotKey(hMainWnd, 3);
	UnregisterGlobalHotkey(hMainWnd);
	Shell_NotifyIcon(NIM_DELETE, &NID);

	ShutdownAutoLogin();
	ShutdownInjector();
	ShutdownNamedPipeServer();
	StopProcessMonitor();
	if (injectOnce)
		UpdateShowConsole(false, false);
	ShutdownConsole();

	UnregisterClass(gszWinClassName, hInstance);

	spdlog::shutdown();

	return (int)msg.wParam;
}

HWND LocateHotkeyWindow(WORD modkey, WORD hotkey)
{
	auto wnd_it = hotkeyMap.find(std::make_pair(modkey, hotkey));
	if (wnd_it != hotkeyMap.end())
	{
		if (IsWindow(wnd_it->second))
		{
			// if we have a valid window, then return it -- the hotkey is valid
			return wnd_it->second;
		}

		// we don't have a valid window, so let's drop the hotkey
		UnregisterHotKey(wnd_it->second, MAKELONG(modkey, hotkey));
		hotkeyMap.erase(wnd_it);
	}

	return nullptr;
}

void RegisterGlobalHotkey(HWND hWnd, std::string_view hotkeyString)
{
	uint16_t modkey, hotkey;
	ConvertStringToModifiersAndVirtualKey(std::string(hotkeyString), modkey, hotkey);

	auto wnd_it = hotkeyMap.find(std::make_pair(modkey, hotkey));
	if (wnd_it != hotkeyMap.end())
	{
		// the hotkey already exists, so drop it and replace it with the new one
		UnregisterHotKey(wnd_it->second, MAKELONG(modkey, hotkey));
		hotkeyMap.erase(wnd_it);
	}

	hotkeyMap[std::make_pair(modkey, hotkey)] = hWnd;
	RegisterHotKey(hMainWnd, MAKELONG(modkey, hotkey), modkey, hotkey);
}

void UnregisterGlobalHotkey(std::string_view hotkeyString)
{
	uint16_t modkey, hotkey;
	ConvertStringToModifiersAndVirtualKey(std::string(hotkeyString), modkey, hotkey);

	auto wnd_it = hotkeyMap.find(std::make_pair(modkey, hotkey));
	if (wnd_it != hotkeyMap.end())
	{
		UnregisterHotKey(wnd_it->second, MAKELONG(modkey, hotkey));
		hotkeyMap.erase(wnd_it);
	}
}

void UnregisterGlobalHotkey(HWND hWnd)
{
	auto wnd_it = std::find_if(hotkeyMap.cbegin(), hotkeyMap.cend(),
		[&hWnd](const auto& pair) {
			return pair.second == hWnd;
		});
	if (wnd_it != hotkeyMap.end())
	{
		UnregisterHotKey(wnd_it->second, MAKELONG(std::get<0>(wnd_it->first), std::get<1>(wnd_it->first)));
		hotkeyMap.erase(wnd_it);
	}
}

std::string_view GetServerType()
{
	return ServerType;
}
