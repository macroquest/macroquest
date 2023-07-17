/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2023 MacroQuest Authors
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
#include "AutoLogin.h"
#include "ProcessMonitor.h"
#include "Crashpad.h"
#include "common/NamedPipes.h"

#include "resource.h"

#include <date/date.h>
#include <fmt/format.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/wincolor_sink.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/msvc_sink.h>
#include <wil/registry.h>
#include <wil/resource.h>

#include <filesystem>
#include <tuple>

#include <shellapi.h>
#include <fcntl.h>

#include <mq/utils/Naming.h>
#include <mq/utils/OS.h>
#include <mq/base/BuildInfo.h>

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
HDC dc = { 0 };
NOTIFYICONDATA NID;
PAINTSTRUCT PS;

char gszMQVersion[64] = { 0 };
char WinDir[_MAX_PATH] = { 0 };

uint32_t gNextWindowHotKey = 0;
uint32_t gPrevWindowHotKey = 0;
uint32_t gBossModeHotKey = 0;

bool gbAllEQWindowsHidden = false;
DWORD gLastEQGameSwitchedTo = 0;
bool gbMinimized = false;
HMENU hMenu = nullptr;
HINSTANCE g_hInst = nullptr;

char gszWinClassName[64] = { 0 };
char gszWinName[64] = { 0 };

const int HOTKEY_EQWIN_PREVIOUS = 1;
const int HOTKEY_EQWIN_NEXT = 2;
const int HOTKEY_EQWIN_BOSSKEY = 3;

bool gbConsoleVisible = false;
bool gbConsoleCreated = false;
mq::NamedPipeServer* gPipeServer = nullptr;
bool gCrashPadInitialized = false;

std::map<std::tuple<uint16_t, uint16_t>, HWND> hotkeyMap;
uint32_t gFocusProcessID = 0;

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
	if (showConsole == gbConsoleVisible)
		return;

	HMENU hSubMenu = GetSubMenu(hMenu, 0);
	MENUITEMINFOA mi = { sizeof(MENUITEMINFOA) };
	mi.fMask = MIIM_STATE;

	if (showConsole)
	{
		mi.fState = MF_CHECKED;
		ShowConsole();
	}
	else
	{
		mi.fState = MF_UNCHECKED;
		HideConsole();
	}

	gbConsoleVisible = showConsole;

	SetMenuItemInfo(hSubMenu, ID_ADVANCED_TOGGLECONSOLE, FALSE, &mi);

	if (updateIni)
	{
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

// This routine is a simple function to print the client request to the console
// and populate the reply buffer with a default data string. This is where you
// would put the actual client request processing code that runs in the context
// of an instance thread. Keep in mind the main thread will continue to wait for
// and receive other client connections while the instance thread is working.

// TODO: This isn't currently used -- do we need it?
void GetAnswerToRequest(char* pchRequest, char* pchReply, size_t* pchBytes)
{
	char szMessage[MAX_STRING];

	if (char* pDest = strchr(pchRequest, ' '))
	{
		pDest[0] = '\0';
		pDest++;
		strcpy_s(szMessage, pDest);
	}

	DWORD msgID = atoi(pchRequest);

	switch (msgID)
	{
	case MSG_LOGINCHAR:
		// FIXME: These are WIP
		break;

	case MSG_LOADED:
		HandleAutoLoginProfileLoaded(szMessage);
		break;

	case MSG_UNLOADED:
		HandleAutoLoginProfileUnloaded(szMessage);
		break;

	case MSG_MQ2UNLOAD:
		HandleAutoLoginMQ2Unload(szMessage);
		break;

	case MSG_CLASSLVL:
		HandleAutoLoginUpdateCharacterDetails(szMessage);
		break;

	default:
		if (FAILED(StringCchCopy(pchReply, PIPE_BUFFER_SIZE, TEXT("invalid/missing msg id passed"))))
		{
			*pchBytes = 0;
			pchReply[0] = 0;
			SPDLOG_DEBUG("StringCchCopy failed, no outgoing message.");
			return;
		}
		*pchBytes = (lstrlen(pchReply) + 1) * sizeof(TCHAR);
		return;

	}

	// OutputDebugString("Client Request String:\"%s\"\n", pchRequest );
	SPDLOG_DEBUG("Client request string: \"{}\'", pchRequest);

	// Check the outgoing message to make sure it's not too long for the buffer.
	if (FAILED(StringCchCopy(pchReply, PIPE_BUFFER_SIZE, TEXT("default answer from server"))))
	{
		*pchBytes = 0;
		pchReply[0] = 0;
		SPDLOG_DEBUG("StringCchCopy failed, no outgoing message.");
		return;
	}

	*pchBytes = (lstrlen(pchReply) + 1) * sizeof(TCHAR);
}

static void SetForegroundWindowInternal(HWND hWnd)
{
	if (!IsWindow(hWnd))
		return;

	if (IsIconic(hWnd))
		ShowWindow(hWnd, SW_RESTORE);

	if (::SetForegroundWindow(hWnd))
		return;

	if (gFocusProcessID != 0)
	{
		// Send request to focus to the correct client
		if (auto connection = gPipeServer->GetConnectionForProcessId(gFocusProcessID))
		{
			MQMessageActivateWnd message;
			message.hWnd = hWnd;

			gPipeServer->SendMessage(connection->GetConnectionId(),
				mq::MQMessageId::MSG_MAIN_FOCUS_ACTIVATE_WND, &message, sizeof(message));
			return;
		}
	}

	SPDLOG_DEBUG("Failed to set foreground window. Doing it with min/restore.");

	ShowWindow(hWnd, SW_MINIMIZE);
	ShowWindow(hWnd, SW_RESTORE);
}


class MQ2NamedPipeEvents : public NamedPipeEvents
{
public:
	// Handle messages from NamedPipeServer
	virtual void OnIncomingMessage(std::shared_ptr<PipeMessage> message) override
	{
		SPDLOG_TRACE("Received message: id={} length={} connectionId={}", message->GetMessageId(),
			message->size(), message->GetConnectionId());

		switch (message->GetMessageId())
		{
		case mq::MQMessageId::MSG_ECHO:
		{
			std::string str(message->get<const char>(), message->size() - 1);
			message->SendReply(MQMessageId::MSG_ECHO, str.data(), (uint32_t)str.length() + 1);
			SPDLOG_INFO("Handling echo request: {}", str);
			break;
		}

		case mq::MQMessageId::MSG_AUTOLOGIN_PROFILE_LOADED:
			HandleAutoLoginProfileLoaded(std::string(message->get<const char>(), message->size()));
			break;

		case mq::MQMessageId::MSG_AUTOLOGIN_PROFILE_UNLOADED:
			HandleAutoLoginProfileUnloaded(std::string(message->get<const char>(), message->size()));
			break;

		case mq::MQMessageId::MSG_AUTOLOGIN_PROFILE_CHARINFO:
			HandleAutoLoginUpdateCharacterDetails(std::string(message->get<const char>(), message->size()));
			break;

		case mq::MQMessageId::MSG_AUTOLOGIN_START_INSTANCE:
			HandleAutoLoginStartInstance(std::string(message->get<const char>(), message->size()));
			break;

		case mq::MQMessageId::MSG_MAIN_PROCESS_UNLOADED:
			break;

		case mq::MQMessageId::MSG_MAIN_PROCESS_LOADED: {
			MQMessageProcessLoadedResponse response;
			response.processId = GetCurrentProcessId();

			gPipeServer->SendMessage(message->GetConnectionId(), mq::MQMessageId::MSG_MAIN_PROCESS_LOADED,
				&response, sizeof(response));
			break;
		}

		case mq::MQMessageId::MSG_MAIN_FOCUS_REQUEST: {
			if (message->size() >= sizeof(MQMessageFocusRequest))
			{
				const MQMessageFocusRequest* request = message->get<MQMessageFocusRequest>();
				if (request->focusMode == MQMessageFocusRequest::FocusMode::HasFocus)
				{
					if (request->state)
					{
						gFocusProcessID = request->processId;
						SPDLOG_TRACE("Process has focus: {}", gFocusProcessID);
					}
					else if (request->processId == gFocusProcessID)
					{
						SPDLOG_TRACE("Process no longer has focus: {}", gFocusProcessID);
						gFocusProcessID = 0;
					}
				}
				else if (request->focusMode == MQMessageFocusRequest::FocusMode::WantFocus)
				{
					HWND hWnd = (HWND)request->hWnd;

					SetForegroundWindowInternal(hWnd);
				}
			}
			break;
		}

		default: break;
		}
	}

	virtual void OnRequestProcessEvents() override
	{
		PostMessageA(hMainWnd, WM_USER_CALLBACK, 0, 0);
	}

	virtual void OnIncomingConnection(int connectionId, int processid) override
	{
		std::string namedPipe;

		if (gCrashPadInitialized && gEnableSharedCrashpad)
		{
			namedPipe = GetHandlerIPCPipe();
		}

		// send the name of the named pipe to the connected client. If crashpad isn't
		// enabled, or shared is disabled, this will send an empty string, which basically
		// tells the process that its own its own.
		gPipeServer->SendMessage(connectionId,
			mq::MakeSimpleMessageV0(MQMessageId::MSG_MAIN_CRASHPAD_CONFIG,
				namedPipe.c_str(), (uint32_t)namedPipe.length() + 1));
	}
};

//----------------------------------------------------------------------------

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

void HandleCommand(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	char lpModulePath[_MAX_PATH] = { 0 };
	GetCurrentDirectory(_MAX_PATH, lpModulePath);

	switch (wParam)
	{
	case ID_ADVANCED_TOGGLECONSOLE:
		UpdateShowConsole(!gbConsoleVisible, true);
		break;

	case ID_MENU_WEBSITE:
		ShellExecute(hWnd, "open", "https://macroquest.org", nullptr, lpModulePath, SW_SHOW);
		break;

	case ID_MENU_FORUMS:
		ShellExecute(hWnd, "open", "https://macroquest.org/phpBB3", nullptr, lpModulePath, SW_SHOW);
		break;

	case ID_MQSITES_WIKI:
		ShellExecute(hWnd, "open", "https://docs.macroquest.org", nullptr, lpModulePath, SW_SHOW);
		break;

	case ID_MQSITES_GITHUB:
		ShellExecute(hWnd, "open", "https://github.com/macroquest/macroquest", nullptr, lpModulePath, SW_SHOW);
		break;

	case ID_MQSITES_ISSUETRACKER:
		ShellExecute(hWnd, "open", "https://github.com/macroquest/macroquest/issues", nullptr, lpModulePath, SW_SHOW);
		break;

	case ID_MENU_CHANGELOG: {
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
			ShellExecute(hWnd, "open", pathChangeLog.string().c_str(), nullptr, lpModulePath, SW_SHOW);
		}
		else
		{
			const std::string strMessage = "Could not find CHANGELOG.md: " + pathChangeLog.string();
			MessageBox(nullptr, strMessage.c_str(), "MacroQuest", MB_OK);
		}
		break;
	}

	case ID_FILE_OPENFOLDERMQ2:
		ShellExecute(hWnd, "explore", internal_paths::MQRoot.c_str(), nullptr, lpModulePath, SW_SHOW);
		break;

	case ID_FILE_OPENFOLDERCONFIG:
		ShellExecute(hWnd, "explore", internal_paths::Config.c_str(), nullptr, lpModulePath, SW_SHOW);
		break;

	case ID_FILE_OPENFOLDERMACROS:
		ShellExecute(hWnd, "explore", internal_paths::Macros.c_str(), nullptr, lpModulePath, SW_SHOW);
		break;

	case ID_FILE_OPENFOLDERRESOURCES:
		ShellExecute(hWnd, "explore", internal_paths::Resources.c_str(), nullptr, lpModulePath, SW_SHOW);
		break;

	case ID_FILE_OPENFOLDERLOGS:
		ShellExecute(hWnd, "explore", internal_paths::Logs.c_str(), nullptr, lpModulePath, SW_SHOW);
		break;

	case ID_FILE_OPENFOLDERCRASHDUMPS:
		ShellExecute(hWnd, "explore", internal_paths::CrashDumps.c_str(), nullptr, lpModulePath, SW_SHOW);
		break;

	case ID_MENU_INI:
		ShellExecute(hWnd, "open", internal_paths::MQini.c_str(), nullptr, lpModulePath, SW_SHOW);
		break;

	case ID_STARTEQBCS:
		if (IsProcessRunning("eqbcs.exe"))
		{
			ThreadedMessage("EQBCS is already running.", MB_OK | MB_ICONWARNING);
		}
		else
		{
			std::string strCommandLine = fmt::format("{}\\eqbcs.exe", lpModulePath);
			std::error_code ec;
			if (std::filesystem::exists(strCommandLine, ec))
			{
				ShellExecute(hWnd, "open", strCommandLine.c_str(), nullptr, lpModulePath, SW_SHOW);
			}
			else
			{
				ThreadedMessage(fmt::format("EQBCS could not be found: {}", strCommandLine), MB_OK | MB_ICONWARNING);
			}
		}
		break;

	case ID_MENU_EXIT:
		PostQuitMessage(0);
		break;

	case ID_FILE_REFRESH:
		RefreshInjections();
		break;

	case ID_FORCEUNLOADOFALLMQ2:
		for (int connId : gPipeServer->GetConnectionIds())
		{
			SPDLOG_DEBUG("Requesting forced unload to connection Id {0}", connId);
			gPipeServer->SendMessage(connId, MQMessageId::MSG_MAIN_REQ_FORCEUNLOAD, nullptr, 0);
		}
		break;

	case ID_UNLOADALLMQ:
		for (int connId : gPipeServer->GetConnectionIds())
		{
			SPDLOG_DEBUG("Requesting unload to connection Id {0}", connId);
			gPipeServer->SendMessage(connId, MQMessageId::MSG_MAIN_REQ_UNLOAD, nullptr, 0);
		}
		break;

	case ID_MENU_CHECKAPPCOMPAT:
	{
		CheckAppCompat(true);
		break;
	}

#ifdef MQ_UPDATE_URL
	case ID_MENU_CHECKFORUPDATES:
	{
		CheckMQ2MainUpdate(true);
		break;
	}
#endif

	default:
		SPDLOG_INFO("Unhandled WM_COMMAND: {}", wParam);
	}
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT MSG, WPARAM wParam, LPARAM lParam)
{
	LRESULT autoLoginResult = 0;
	if (HandleAutoLoginWindowMessage(hWnd, MSG, wParam, lParam, &autoLoginResult))
		return autoLoginResult;

	switch (MSG)
	{
	case WM_HOTKEY:
		return HandleHotkey(wParam, lParam);

	case WM_PAINT:
		BeginPaint(hWnd, &PS);
		dc = PS.hdc;
		EndPaint(hWnd, &PS);
		break;

	case WM_COMMAND:
		HandleCommand(hWnd, wParam, lParam);
		break;

	case WM_WINDOWPOSCHANGING:
		Shell_NotifyIcon(NIM_ADD, &NID); //Add the systray icon.
		break;

	case WM_SIZE:
		if (wParam == SIZE_MINIMIZED)
			gbMinimized = true;
		ShowWindow(hWnd, SW_HIDE); // Hide our window just after the minimize is done.
		Shell_NotifyIcon(NIM_ADD, &NID); //Add the systray icon.
		break;

	case WM_SYSCOMMAND:
		switch (LOWORD(wParam)) // We capture the 'X' button
		{
		case SC_CLOSE:
			gbMinimized = false;
			ShowWindow(hWnd, SW_HIDE);
			Shell_NotifyIcon(NIM_ADD, &NID);
			return 0;

		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		}
		break;

	case WM_USER_PROCESS_ADDED:
	case WM_USER_PROCESS_REMOVED: {
		DWORD processId = (DWORD)wParam;
		if (MSG == WM_USER_PROCESS_ADDED)
		{
			Inject(processId, 1s);
		}
		else
		{
			AutoLoginRemoveProcess(processId);
		}
		break;
	}

	case WM_USER_CALLBACK:
		gPipeServer->Process();
		break;

	default:
		if (MSG == NID.uCallbackMessage) // This is where we get our SysTray Icon notifications.
		{
			POINT mp;

			switch (lParam)
			{
			case WM_LBUTTONDBLCLK:
			{
				char lpModulePath[_MAX_PATH] = { 0 };
				GetCurrentDirectory(_MAX_PATH, lpModulePath);
				ShellExecute(hWnd, "open", "https://macroquest.org", nullptr, lpModulePath, SW_SHOW);
				break;
			}

			case WM_RBUTTONUP:
				GetCursorPos(&mp);
				SetForegroundWindow(hWnd);
				TrackPopupMenu(GetSubMenu(hMenu, 0),
					TPM_LEFTBUTTON | TPM_RECURSE,
					mp.x,
					mp.y,
					0,
					hWnd,
					nullptr);

				PostMessage(hWnd, WM_NULL, 0, 0);
				break;
			}
			break;
		}
	}

	return DefWindowProc(hWnd, MSG, wParam, lParam);
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

	hMenu = LoadMenu(g_hInst, MAKEINTRESOURCE(IDR_MENU1));

	NID.cbSize = sizeof(NID);
	NID.hIcon = LoadIcon(g_hInst, MAKEINTRESOURCE(IDI_ICON1));
	NID.uCallbackMessage = WM_USER_SHELLNOTIFY_CALLBACK;
	NID.hWnd = hMainWnd;
	NID.uID = WM_USER_SYSTRAY;
	NID.uFlags = NIF_TIP | NIF_ICON | NIF_MESSAGE;
	Shell_NotifyIcon(NIM_ADD, &NID);
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
		SendMessageA(hMainWnd, WM_USER_PROCESS_REMOVED, processId, 0);
	}
};

void InitializeNamedPipeServer()
{
	gPipeServer = new NamedPipeServer(MQ2_PIPE_SERVER_PATH);
	gPipeServer->SetHandler(std::make_shared<MQ2NamedPipeEvents>());
	gPipeServer->Start();
}

void ShutdownNamedPipeServer()
{
	gPipeServer->Stop();
	delete gPipeServer;
}

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
	strcpy_s(gszMQVersion, szVersion);

	sprintf_s(gszMQVersion, "%s (%s)", gszMQVersion, GetBuildTargetName(*reinterpret_cast<BuildTarget*>(GetProcAddress(hModule.get(), "gBuild"))));

	sprintf_s(NID.szTip, "%s [%s]", gszWinName, gszMQVersion);
	SPDLOG_INFO("Build: {0}", NID.szTip);
	Shell_NotifyIcon(NIM_MODIFY, &NID);
}

// ***************************************************************************
// Function:    WinMain
// Description: EXE entry point
// ***************************************************************************
int WINAPI CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
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
		return 0;

	const std::string cycleNextWindowKey = GetPrivateProfileString("MacroQuest", "CycleNextWindow", "", internal_paths::MQini);
	const std::string cyclePrevWindowKey = GetPrivateProfileString("MacroQuest", "CyclePrevWindow", "", internal_paths::MQini);
	const std::string bossModeKey = GetPrivateProfileString("MacroQuest", "BossMode", "", internal_paths::MQini);

	InitializeNamedPipeServer();
	InitializeWindows();
	InitializeAutoLogin();

	auto pMonitorEvents = std::make_unique<MQ2ProcessMonitorEvents>();
	StartProcessMonitor(pMonitorEvents.get());

	// Update version information shown in the system tray tooltip
	InitializeVersionInfo();

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

	SPDLOG_INFO("Waiting for events...");

	MSG msg;
	BOOL bRet;
	while ((bRet = GetMessage(&msg, nullptr, 0, 0)) != 0)
	{
		if (bRet == -1)
		{
			break;
		}
		else
		{
			if (msg.message == WM_QUIT)
				break;

			if (!IsDialogMessage(hEditProfileWnd, &msg))
			{
				TranslateMessage(&msg);
				DispatchMessageA(&msg);
			}
		}
	}

	SPDLOG_INFO("Shutting down...");

	// Shutdown
	UnregisterHotKey(hMainWnd, 1);
	UnregisterHotKey(hMainWnd, 2);
	UnregisterHotKey(hMainWnd, 3);
	UnregisterGlobalHotkey(hMainWnd);
	Shell_NotifyIcon(NIM_DELETE, &NID);

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
