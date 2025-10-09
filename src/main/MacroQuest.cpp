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

#include "pch.h"
#include "MacroQuest.h"
#include "MQ2Main.h"
#include "Logging.h"
#include "CrashHandler.h"
#include "MQActorAPI.h"
#include "MQCommandAPI.h"
#include "MQDataAPI.h"
#include "MQRenderDoc.h"
#include "MQ2KeyBinds.h"
#include "MQPluginHandler.h"
#include "ImGuiManager.h"
#include "GraphicsResources.h"

#include "mq/base/Logging.h"

#include "eqlib/EQLib.h"
#include "eqlib/Init.h"
#include "eqlib/Events.h"

#include <fmt/format.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/msvc_sink.h>
#include <wil/resource.h>
#include <fstream>

#if !defined(COMMENT_UPDATER)
#include "client/crashpad_client.h"
#endif

#include <Psapi.h>

#pragma comment(lib, "Psapi.lib")
#pragma comment(lib, "version.lib")

#define CLIENT_OVERRIDE 0

#if IS_LIVE_CLIENT

#if !defined(_M_AMD64)
#error Live build is only for x64
#endif
#pragma message("Building MacroQuest for LIVE (x64)")
#define MacroQuestWinClassName "__MacroQuestTray(Live)"
#define MacroQuestWinName "MacroQuest(Live)"

#elif IS_TEST_CLIENT

#if !defined(_M_AMD64)
#error Test build is only for x64
#endif
#pragma message("Building MacroQuest for TEST (x64)")
#define MacroQuestWinClassName "__MacroQuestTray(Test)"
#define MacroQuestWinName "MacroQuest(Test)"

#elif IS_BETA_CLIENT

#if !defined(_M_AMD64)
#error Beta build is only for x64
#endif
#pragma message("Building MacroQuest for BETA (x64)")
#define MacroQuestWinClassName "__MacroQuestTray(Beta)"
#define MacroQuestWinName "MacroQuest(Beta)"

#elif IS_EMU_CLIENT

#if defined(_M_AMD64)
#error Emulator Build is only for x86
#endif
#pragma message("Building MacroQuest for EMULATOR (x86)")
#define MacroQuestWinClassName "__MacroQuestTray(EQEmu)"
#define MacroQuestWinName "MacroQuest(EQEmu)"

#endif

namespace fs = std::filesystem;
using namespace std::chrono_literals;

namespace mq {

//============================================================================

void InitializeLoginFrontend();
void ShutdownLoginFrontend();
void InitializeDetours();
void ShutdownDetours();
void ShutdownInternalModules();

MQModule* GetSpellsModule();
MQModule* GetImGuiToolsModule();
MQModule* GetDataAPIModule();
MQModule* GetActorAPIModule();
MQModule* GetGroundSpawnsModule();
MQModule* GetSpawnsModule();
MQModule* GetItemsModule();
MQModule* GetWindowsModule();
MQModule* GetPostOfficeModule();
#if IS_EMU_CLIENT
MQModule* GetEmuExtensionsModule();
#endif

void InitializeMQ2AutoInventory();
void ShutdownMQ2AutoInventory();

DWORD WINAPI MacroQuestBackgroundThread(void* lpParameter);
HANDLE hMQ2StartThread = nullptr;
DWORD dwMainThreadId = 0;

wil::unique_event g_hLoadComplete;
HANDLE hUnloadComplete = nullptr;
void* ModuleListHandler = nullptr;

std::shared_ptr<spdlog::logger> g_logger;

MacroQuest* g_mq = nullptr;

static void WaitForLavishSoftware()
{
	// IsBoxer/InnerSpace
	HMODULE hISModule = ::GetModuleHandleA("InnerSpace.dll");
	if (!hISModule)
	{
		// Joe MultiBoxer / WinEQ2022
		hISModule = ::GetModuleHandleA("JMB.dll");
	}
	if (!hISModule)
	{
		// WinEQ?
		hISModule = ::GetModuleHandleA("Lavish.dll");
	}
	if (hISModule)
	{
		uintptr_t baseAddressLS = 0;
		uintptr_t endAddress = 0;

		MODULEINFO moduleInfo;
		HMODULE hKernelModule = ::GetModuleHandleA("kernel32.dll");

		if (hISModule
			&& ::K32GetModuleInformation(GetCurrentProcess(), hISModule, &moduleInfo, sizeof(MODULEINFO)))
		{
			baseAddressLS = (uintptr_t)moduleInfo.lpBaseOfDll;
			endAddress = baseAddressLS + (uintptr_t)moduleInfo.SizeOfImage;
		}

		bool foundHooks = baseAddressLS == 0;             // skip checks if InnerSpace.dll isn't loaded
		bool foundWindowHandle = false;

		// Do some checks against Lavish/InnerSpace integrations. Wait a total of 10 seconds or we fail all checks.
		const auto startTime = std::chrono::steady_clock::now();
		while (std::chrono::steady_clock::now() - startTime < std::chrono::seconds(10) && !(foundHooks && foundWindowHandle))
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(200));

			if (!foundHooks)
			{
				// Wait for module to finish loading before we try to continue. Otherwise it will modify our
				// import address table, resulting in our detours being ineffective if we go first.
				uintptr_t fnGetProcAddress = (uintptr_t)&::GetProcAddress;
				if (fnGetProcAddress >= baseAddressLS && fnGetProcAddress < endAddress)
				{
					foundHooks = true;
				}
				else
				{
					fnGetProcAddress = (uintptr_t)GetProcAddress(hKernelModule, "GetProcAddress");
					if (fnGetProcAddress >= baseAddressLS && fnGetProcAddress < endAddress)
					{
						foundHooks = true;
					}
				}
			}

			if (!foundWindowHandle)
			{
				// we also use this loop to wait for wineq2/innerspace to get the eqwindow up and running before we move on.
				HWND hEQWnd = GetEQWindowHandle();
				if (hEQWnd != nullptr)
				{
					foundWindowHandle = true;
				}
			}
		}

		// The lavish dlls steal our detour so that our GetProcAddress never sees the eqmain.dll load.  Delaying here
		// gives eqmain.dll time to load so that we're not waiting for that trigger when we inject at startup.
		std::this_thread::sleep_for(std::chrono::seconds(1));

		if (!foundHooks)
		{
			DebugSpewAlways("Was not able to detect the InnerSpace hook on GetProcAddress!");
		}

		if (!foundWindowHandle)
		{
			DebugSpewAlways("Was not able to detect the main EQ window handle!");
		}
	}
}

//============================================================================

extern "C" BOOL APIENTRY DllMain(HANDLE hModule, DWORD ul_reason_for_call, void* lpReserved)
{
	if (ul_reason_for_call != DLL_PROCESS_ATTACH && ul_reason_for_call != DLL_PROCESS_DETACH)
	{
		return true;
	}

	char szFilename[MAX_STRING] = { 0 };
	ghModule = (HMODULE)hModule;
	ghInstance = (HINSTANCE)hModule;
	ghInjectorWnd = FindWindowA(MacroQuestWinClassName, MacroQuestWinName);

	GetModuleFileName(nullptr, szFilename, MAX_STRING);

	char* szProcessName = strrchr(szFilename, '.');
	szProcessName[0] = '\0';
	szProcessName = strrchr(szFilename, '\\') + 1;

	if (_stricmp(szProcessName, "eqgame") == 0)
	{
		if (ul_reason_for_call == DLL_PROCESS_ATTACH)
		{
			::SetDllDirectoryA(nullptr);

			// Get path to the dll and strip off the filename
			::GetModuleFileNameA(ghModule, szFilename, MAX_STRING);
			szProcessName = strrchr(szFilename, '\\');
			szProcessName[0] = '\0';

			mq::internal_paths::MQRoot = szFilename;
			g_Loaded = true;

			RenderDoc_Startup();

			hMQ2StartThread = CreateThread(nullptr, 0, MacroQuestBackgroundThread, _strdup(szFilename), 0, &ThreadID);
		}
		else if (ul_reason_for_call == DLL_PROCESS_DETACH)
		{
			gbUnload = true;

			if (hMQ2StartThread)
			{
				const int dwtime = WaitForSingleObject(hMQ2StartThread, 1000);
				if (dwtime == WAIT_TIMEOUT)
				{
					Sleep(0);
				}
				CloseHandle(hMQ2StartThread);
			}

			return TRUE;
		}
	}

	return TRUE;
}

bool InitDirectory(std::string& strPathToInit,
	const std::string& strIniKey,
	const std::string& iniToRead,
	const std::filesystem::path& appendPathIfRelative = mq::internal_paths::MQRoot)
{
	DebugSpewAlways("Initializing Directory:  %s", strIniKey.c_str());

	std::filesystem::path pathToInit =
		GetPrivateProfileString("MacroQuest", strIniKey, strPathToInit, iniToRead);

	if (gbWriteAllConfig)
	{
		WritePrivateProfileString("MacroQuest", strIniKey, pathToInit.string(), iniToRead);
	}

	if (pathToInit.is_relative())
	{
		pathToInit = std::filesystem::absolute(appendPathIfRelative / pathToInit);
	}

	// Either way, update the string
	strPathToInit = pathToInit.string();
	std::error_code ec_fs;

	if (std::filesystem::exists(pathToInit, ec_fs) || std::filesystem::create_directories(pathToInit, ec_fs))
	{
		DebugSpewAlways("Directory Init of %s successful at: %s", strIniKey.c_str(), strPathToInit.c_str());
		return true;
	}

	const std::string strTemp = "Could not find or create " + strIniKey + " path: " + strPathToInit;
	DebugSpewAlways(strTemp.c_str());
	MessageBox(nullptr, strTemp.c_str(), "MacroQuest", MB_OK);
	return false;
}

/*
 * @fn InitConfig()
 *
 * Find the initial MacroQuest.ini to set the config directory.
 * Additional settings will be parsed out of the MacroQuest.ini in
 * that directory, but we don't want to parse the config directory
 * from there since that could cause a circular config relationship.
 *
 */
bool InitConfig(std::string& strMQRoot, std::string& strConfig, std::string& strMQini)
{
	DebugSpewAlways("Initializing Configuration...");

	std::filesystem::path pathMQRoot = strMQRoot;

	// If we still have a relative path to the MQ2 directory, make it absolute.
	if (pathMQRoot.is_relative())
	{
		pathMQRoot = std::filesystem::absolute(pathMQRoot).string();
	}
	// Set strMQRoot to the path we found.
	strMQRoot = pathMQRoot.string();
	std::error_code ec;

	// If the path to MQ2 doesn't exist none of our relative paths are going to work
	if (std::filesystem::exists(pathMQRoot, ec))
	{
		strMQini = GetCreateMacroQuestIni(pathMQRoot, strConfig, strMQini);

		gbWriteAllConfig = GetPrivateProfileBool("MacroQuest", "WriteAllConfig", false, strMQini);
		// Write the MQIniPath if we're writing all config.  This will be the full path and in the redirected ini
		// (not the original ini) but since WriteAllConfig is meant to write a full config, that's okay.
		if (gbWriteAllConfig)
		{
			WritePrivateProfileString("MacroQuest", "MQIniPath", strMQini, strMQini);
		}

		// Init the Config directory based on the ini we found.
		if (InitDirectory(strConfig, "ConfigPath", strMQini, strMQRoot))
		{
#pragma warning(push)
#pragma warning(disable: 4996) // temporarily disable deprecation warnings.
			// Backwards compatible before we deprecate
			strcpy_s(gszEQPath, std::filesystem::absolute(".").string().c_str());
			strcpy_s(gszINIPath, strMQRoot.c_str()); // or mq::internal_paths::Config but since it's mostly used to find the MQ2 directory...
			strcpy_s(gszINIFilename, strMQini.c_str());
			// API compatible
			strcpy_s(gPathMQRoot, strMQRoot.c_str());
			strcpy_s(gPathMQini, strMQini.c_str());
			strcpy_s(gPathConfig, strConfig.c_str());
#pragma warning(pop)
			return true;
		}
	}

	return false;
}

bool InitDirectories(const std::string& iniToRead)
{
	DebugSpewAlways("Initializing Required Directories...");

	if (InitDirectory(mq::internal_paths::Macros, "MacroPath", iniToRead, mq::internal_paths::MQRoot)
		&& InitDirectory(mq::internal_paths::Logs, "LogPath", iniToRead, mq::internal_paths::MQRoot)
		&& InitDirectory(mq::internal_paths::CrashDumps, "CrashDumpPath", iniToRead, mq::internal_paths::MQRoot)
		&& InitDirectory(mq::internal_paths::Plugins, "PluginPath", iniToRead, mq::internal_paths::MQRoot)
		&& InitDirectory(mq::internal_paths::Resources, "ResourcePath", iniToRead, mq::internal_paths::MQRoot)
		)
	{
		std::error_code ec;
		mq::internal_paths::EverQuest = std::filesystem::current_path(ec).string();
#pragma warning(push)
#pragma warning(disable: 4996) // temporarily disable deprecation warnings.
		// Backwards compatible before we deprecate
		strcpy_s(gszMacroPath, mq::internal_paths::Macros.c_str());
		strcpy_s(gszLogPath, mq::internal_paths::Logs.c_str());
		strcpy_s(gszEQPath, mq::internal_paths::EverQuest.c_str());
#pragma warning(pop)
		// API compatible
		strcpy_s(gPathMacros, mq::internal_paths::Macros.c_str());
		strcpy_s(gPathLogs, mq::internal_paths::Logs.c_str());
		strcpy_s(gPathCrashDumps, mq::internal_paths::CrashDumps.c_str());
		strcpy_s(gPathPlugins, mq::internal_paths::Plugins.c_str());
		strcpy_s(gPathResources, mq::internal_paths::Resources.c_str());
		strcpy_s(gPathEverQuest, mq::internal_paths::EverQuest.c_str());
		return true;
	}

	return false;
}

// ***************************************************************************
// Function:    ParseINIFile
// Description: Parse INI file for settings
// ***************************************************************************
// FIXME:  We're over the stack size here.  MAX_STRING * 10...
bool ParseINIFile(const std::string& iniFile)
{
	char szBuffer[MAX_STRING] = { 0 };

	gFilterSkillsAll         = GetPrivateProfileBool("MacroQuest", "FilterSkills", gFilterSkillsAll, iniFile);
	gFilterSkillsIncrease    = 2 == GetPrivateProfileInt("MacroQuest", "FilterSkills", gFilterSkillsIncrease ? 2 : 0, iniFile);
	if (gbWriteAllConfig)
	{
		if (gFilterSkillsAll && gFilterSkillsIncrease)
			WritePrivateProfileInt("MacroQuest", "FilterSkills", 2, iniFile);
		else
			WritePrivateProfileBool("MacroQuest", "FilterSkills", gFilterSkillsAll, iniFile);
	}

	gFilterDebug             = GetPrivateProfileBool("MacroQuest", "FilterDebug", gFilterDebug, iniFile);
	gFilterMQ2DataErrors     = GetPrivateProfileBool("MacroQuest", "FilterMQ2Data", gFilterMQ2DataErrors, iniFile);
	gFilterTarget            = GetPrivateProfileBool("MacroQuest", "FilterTarget", gFilterTarget, iniFile);
	gFilterMoney             = GetPrivateProfileBool("MacroQuest", "FilterMoney", gFilterMoney, iniFile);
	gFilterFood              = GetPrivateProfileBool("MacroQuest", "FilterFood", gFilterFood, iniFile);
	gFilterMacro             = (eFilterMacro)GetPrivateProfileInt("MacroQuest", "FilterMacro", gFilterMacro, iniFile);
	gFilterEncumber          = GetPrivateProfileBool("MacroQuest", "FilterEncumber", gFilterEncumber, iniFile);
	gFilterCustom            = GetPrivateProfileBool("MacroQuest", "FilterCustom", gFilterCustom, iniFile);
	gSpewToFile              = GetPrivateProfileBool("MacroQuest", "DebugSpewToFile", gSpewToFile, iniFile);
	gMQPauseOnChat           = GetPrivateProfileBool("MacroQuest", "MQPauseOnChat", gMQPauseOnChat, iniFile);
	gKeepKeys                = GetPrivateProfileBool("MacroQuest", "KeepKeys", gKeepKeys, iniFile);
	bAllErrorsDumpStack      = GetPrivateProfileBool("MacroQuest", "AllErrorsDumpStack", bAllErrorsDumpStack, iniFile);
	bAllErrorsFatal          = GetPrivateProfileBool("MacroQuest", "AllErrorsFatal", bAllErrorsFatal, iniFile);
	gbMQ2LoadingMsg          = GetPrivateProfileBool("MacroQuest", "MQ2LoadingMsg", gbMQ2LoadingMsg, iniFile);
	gbExactSearchCleanNames  = GetPrivateProfileBool("MacroQuest", "ExactSearchCleanNames", gbExactSearchCleanNames, iniFile);
	gUseTradeOnTarget        = GetPrivateProfileBool("MacroQuest", "UseTradeOnTarget", gUseTradeOnTarget, iniFile);
	gbBeepOnTells            = GetPrivateProfileBool("MacroQuest", "BeepOnTells", gbBeepOnTells, iniFile);
	gbFlashOnTells           = GetPrivateProfileBool("MacroQuest", "FlashOnTells", gbFlashOnTells, iniFile);
	gbIgnoreAlertRecursion   = GetPrivateProfileBool("MacroQuest", "IgnoreAlertRecursion", gbIgnoreAlertRecursion, iniFile);
	gbShowCurrentCamera      = GetPrivateProfileBool("MacroQuest", "ShowCurrentCamera", gbShowCurrentCamera, iniFile);
	gTurboLimit              = GetPrivateProfileInt("MacroQuest", "TurboLimit", gTurboLimit, iniFile);
	gCreateMQ2NewsWindow     = GetPrivateProfileBool("MacroQuest", "CreateMQ2NewsWindow", gCreateMQ2NewsWindow, iniFile);
	gNetStatusXPos           = GetPrivateProfileInt("MacroQuest", "NetStatusXPos", gNetStatusXPos, iniFile);
	gNetStatusYPos           = GetPrivateProfileInt("MacroQuest", "NetStatusYPos", gNetStatusYPos, iniFile);
	gStackingDebug           = (eStackingDebug)GetPrivateProfileInt("MacroQuest", "BuffStackDebugMode", gStackingDebug, iniFile);
	gUseNewNamedTest         = GetPrivateProfileBool("MacroQuest", "UseNewNamedTest", gUseNewNamedTest, iniFile);
	gParserVersion           = GetPrivateProfileInt("MacroQuest", "ParserEngine", gParserVersion, iniFile); // 2 = new parser, everything else = old parser
	gIfDelimiter             = GetPrivateProfileString("MacroQuest", "IfDelimiter", std::string(1, gIfDelimiter), iniFile)[0];
	gIfAltDelimiter          = GetPrivateProfileString("MacroQuest", "IfAltDelimiter", std::string(1, gIfAltDelimiter), iniFile)[0];
#if HAS_CHAT_TIMESTAMPS
	gbTimeStampChat          = GetPrivateProfileBool("MacroQuest", "TimeStampChat", gbTimeStampChat, iniFile);
#endif

	if (gbWriteAllConfig)
	{
		WritePrivateProfileBool("MacroQuest", "FilterDebug", gFilterDebug, iniFile);
		WritePrivateProfileBool("MacroQuest", "FilterMQ2Data", gFilterMQ2DataErrors, iniFile);
		WritePrivateProfileBool("MacroQuest", "FilterTarget", gFilterTarget, iniFile);
		WritePrivateProfileBool("MacroQuest", "FilterMoney", gFilterMoney, iniFile);
		WritePrivateProfileBool("MacroQuest", "FilterFood", gFilterFood, iniFile);
		WritePrivateProfileBool("MacroQuest", "FilterMacro", gFilterMacro, iniFile);
		WritePrivateProfileBool("MacroQuest", "FilterEncumber", gFilterEncumber, iniFile);
		WritePrivateProfileBool("MacroQuest", "FilterCustom", gFilterCustom, iniFile);
		WritePrivateProfileBool("MacroQuest", "DebugSpewToFile", gSpewToFile, iniFile);
		WritePrivateProfileBool("MacroQuest", "MQPauseOnChat", gMQPauseOnChat, iniFile);
		WritePrivateProfileBool("MacroQuest", "KeepKeys", gKeepKeys, iniFile);
		WritePrivateProfileBool("MacroQuest", "AllErrorsDumpStack", bAllErrorsDumpStack, iniFile);
		WritePrivateProfileBool("MacroQuest", "AllErrorsFatal", bAllErrorsFatal, iniFile);
		WritePrivateProfileBool("MacroQuest", "MQ2LoadingMsg", gbMQ2LoadingMsg, iniFile);
		WritePrivateProfileBool("MacroQuest", "ExactSearchCleanNames", gbExactSearchCleanNames, iniFile);
		WritePrivateProfileBool("MacroQuest", "UseTradeOnTarget", gUseTradeOnTarget, iniFile);
		WritePrivateProfileBool("MacroQuest", "BeepOnTells", gbBeepOnTells, iniFile);
		WritePrivateProfileBool("MacroQuest", "FlashOnTells", gbFlashOnTells, iniFile);
		WritePrivateProfileBool("MacroQuest", "IgnoreAlertRecursion", gbIgnoreAlertRecursion, iniFile);
		WritePrivateProfileBool("MacroQuest", "ShowCurrentCamera", gbShowCurrentCamera, iniFile);
		WritePrivateProfileInt("MacroQuest", "TurboLimit", gTurboLimit, iniFile);
		WritePrivateProfileBool("MacroQuest", "CreateMQ2NewsWindow", gCreateMQ2NewsWindow, iniFile);
		WritePrivateProfileInt("MacroQuest", "NetStatusXPos", gNetStatusXPos, iniFile);
		WritePrivateProfileInt("MacroQuest", "NetStatusYPos", gNetStatusYPos, iniFile);
		WritePrivateProfileInt("MacroQuest", "BuffStackDebugMode", gStackingDebug, iniFile);
		WritePrivateProfileBool("MacroQuest", "UseNewNamedTest", gUseNewNamedTest, iniFile);
		WritePrivateProfileInt("MacroQuest", "ParserEngine", gParserVersion, iniFile);
		WritePrivateProfileString("MacroQuest", "IfDelimiter", std::string(1, gIfDelimiter), iniFile);
		WritePrivateProfileString("MacroQuest", "IfAltDelimiter", std::string(1, gIfAltDelimiter), iniFile);
#if HAS_CHAT_TIMESTAMPS
		WritePrivateProfileBool("MacroQuest", "TimeStampChat", gbTimeStampChat, iniFile);
#endif

	}

	GetPrivateProfileString("MacroQuest", "HUDMode", "UnderUI", szBuffer, MAX_STRING, iniFile);

	if (ci_equals(szBuffer, "normal"))
	{
		gbAlwaysDrawMQHUD = false;
		gbHUDUnderUI = false;
	}
	else
	{
		if (ci_equals(szBuffer, "always"))
		{
			gbAlwaysDrawMQHUD = true;
			gbHUDUnderUI = true;
		}
		else
		{
			strcpy_s(szBuffer, "UnderUI");
			gbAlwaysDrawMQHUD = false;
			gbHUDUnderUI = true;
		}
	}

	if (gbWriteAllConfig)
		WritePrivateProfileString("MacroQuest", "HUDMode", szBuffer, iniFile);

	gFilterSWho.Lastname        = GetPrivateProfileBool("SWho Filter", "Lastname", gFilterSWho.Lastname, iniFile);
	gFilterSWho.Class           = GetPrivateProfileBool("SWho Filter", "Class", gFilterSWho.Class, iniFile);
	gFilterSWho.Race            = GetPrivateProfileBool("SWho Filter", "Race", gFilterSWho.Race, iniFile);
	gFilterSWho.Level           = GetPrivateProfileBool("SWho Filter", "Level", gFilterSWho.Level, iniFile);
	gFilterSWho.GM              = GetPrivateProfileBool("SWho Filter", "GM", gFilterSWho.GM, iniFile);
	gFilterSWho.Guild           = GetPrivateProfileBool("SWho Filter", "Guild", gFilterSWho.Guild, iniFile);
	gFilterSWho.Sneak           = GetPrivateProfileBool("SWho Filter", "Sneak", gFilterSWho.Sneak, iniFile);
	gFilterSWho.LD              = GetPrivateProfileBool("SWho Filter", "LD", gFilterSWho.LD, iniFile);
	gFilterSWho.LFG             = GetPrivateProfileBool("SWho Filter", "LFG", gFilterSWho.LFG, iniFile);
	gFilterSWho.NPCTag          = GetPrivateProfileBool("SWho Filter", "NPCTag", gFilterSWho.NPCTag, iniFile);
	gFilterSWho.Trader          = GetPrivateProfileBool("SWho Filter", "Trader", gFilterSWho.Trader, iniFile);
	gFilterSWho.AFK             = GetPrivateProfileBool("SWho Filter", "AFK", gFilterSWho.AFK, iniFile);
	gFilterSWho.Anon            = GetPrivateProfileBool("SWho Filter", "Anon", gFilterSWho.Anon, iniFile);
	gFilterSWho.Distance        = GetPrivateProfileBool("SWho Filter", "Distance", gFilterSWho.Distance, iniFile);
	gFilterSWho.Light           = GetPrivateProfileBool("SWho Filter", "Light", gFilterSWho.Light, iniFile);
	gFilterSWho.Body            = GetPrivateProfileBool("SWho Filter", "Body", gFilterSWho.Body, iniFile);
	gFilterSWho.SpawnID         = GetPrivateProfileBool("SWho Filter", "SpawnID", gFilterSWho.SpawnID, iniFile);
	gFilterSWho.Holding         = GetPrivateProfileBool("SWho Filter", "Holding", gFilterSWho.Holding, iniFile);
	gFilterSWho.ConColor        = GetPrivateProfileBool("SWho Filter", "ConColor", gFilterSWho.ConColor, iniFile);
	gFilterSWho.Invisible       = GetPrivateProfileBool("SWho Filter", "Invisible", gFilterSWho.Invisible, iniFile);

	if (gbWriteAllConfig)
	{
		WritePrivateProfileBool("SWho Filter", "Lastname", gFilterSWho.Lastname, iniFile);
		WritePrivateProfileBool("SWho Filter", "Class", gFilterSWho.Class, iniFile);
		WritePrivateProfileBool("SWho Filter", "Race", gFilterSWho.Race, iniFile);
		WritePrivateProfileBool("SWho Filter", "Level", gFilterSWho.Level, iniFile);
		WritePrivateProfileBool("SWho Filter", "GM", gFilterSWho.GM, iniFile);
		WritePrivateProfileBool("SWho Filter", "Guild", gFilterSWho.Guild, iniFile);
		WritePrivateProfileBool("SWho Filter", "Sneak", gFilterSWho.Sneak, iniFile);
		WritePrivateProfileBool("SWho Filter", "LD", gFilterSWho.LD, iniFile);
		WritePrivateProfileBool("SWho Filter", "LFG", gFilterSWho.LFG, iniFile);
		WritePrivateProfileBool("SWho Filter", "NPCTag", gFilterSWho.NPCTag, iniFile);
		WritePrivateProfileBool("SWho Filter", "Trader", gFilterSWho.Trader, iniFile);
		WritePrivateProfileBool("SWho Filter", "AFK", gFilterSWho.AFK, iniFile);
		WritePrivateProfileBool("SWho Filter", "Anon", gFilterSWho.Anon, iniFile);
		WritePrivateProfileBool("SWho Filter", "Distance", gFilterSWho.Distance, iniFile);
		WritePrivateProfileBool("SWho Filter", "Light", gFilterSWho.Light, iniFile);
		WritePrivateProfileBool("SWho Filter", "Body", gFilterSWho.Body, iniFile);
		WritePrivateProfileBool("SWho Filter", "SpawnID", gFilterSWho.SpawnID, iniFile);
		WritePrivateProfileBool("SWho Filter", "Holding", gFilterSWho.Holding, iniFile);
		WritePrivateProfileBool("SWho Filter", "ConColor", gFilterSWho.ConColor, iniFile);
		WritePrivateProfileBool("SWho Filter", "Invisible", gFilterSWho.Invisible, iniFile);
	}

	DefaultFilters();

	// TODO:  Add a function that gets map for a section?
	char FilterList[MAX_STRING * 10] = { 0 };
	GetPrivateProfileString("Filter Names", "", "", FilterList, MAX_STRING * 10, iniFile);

	char* pFilterList = FilterList;
	if (pFilterList[0] == '\0' && gbWriteAllConfig)
	{
		WritePrivateProfileString("Filter Names", "Example", "NOBODY", iniFile);
	}
	while (pFilterList[0] != '\0')
	{
		std::string filter = GetPrivateProfileString("Filter Names", pFilterList, "", iniFile);

		if (!filter.empty() && filter != "NOBODY")
		{
			AddFilter(filter.c_str(), -1, gFilterCustom);
		}

		pFilterList += strlen(pFilterList) + 1;
	}

	const std::filesystem::path itemDBPath = std::filesystem::path(mq::internal_paths::Resources) / "ItemDB.txt";
	std::error_code ec_exists;
	if (std::filesystem::exists(itemDBPath, ec_exists))
	{
		// Backwards compatibility prior to deprecation
#pragma warning(suppress: 4996) // temporarily disable deprecation warnings.
		strcpy_s(gszItemDB, itemDBPath.string().c_str());

		std::ifstream itemDB(itemDBPath);
		std::string itemDBLine;
		while (std::getline(itemDB, itemDBLine))
		{
			size_t firstTab = itemDBLine.find('\t');
			size_t lastTab = itemDBLine.rfind('\t');

			if (firstTab != std::string::npos && lastTab != std::string::npos)
			{
				int itemID = GetIntFromString(itemDBLine.substr(0, firstTab), 0);
				int stackQTY = GetIntFromString(itemDBLine.substr(firstTab + 1, lastTab - firstTab), 0);
				std::string itemName = itemDBLine.substr(lastTab + 1);
				if (itemID != 0)
				{
					if (ITEMDB* Item = new ITEMDB())
					{
						Item->pNext = gItemDB;
						Item->ID = itemID;
						Item->StackSize = stackQTY;
						strcpy_s(Item->szName, itemName.c_str());
						gItemDB = Item;
					}
				}
				else
				{
					std::string strMessage = "Failed to parse ItemDB.  Check the data at " + itemDBPath.string();
					MessageBox(nullptr, strMessage.c_str(), "MacroQuest", MB_OK);
					break;
				}
			}
			else
			{
				std::string strMessage = "Unexpected Data in ItemDB.  Check the format at " + itemDBPath.string();
				MessageBox(nullptr, strMessage.c_str(), "MacroQuest", MB_OK);
				break;
			}
		}
	}

	return true;
}

//============================================================================

DWORD GetMainThreadId()
{
	return dwMainThreadId;
}

bool IsMainThread()
{
	// If not initialized yet, we don't know. Treat as if we're on another
	// thread, then we'll stay extra safe.
	if (dwMainThreadId == 0)
		return false;

	return dwMainThreadId == ::GetCurrentThreadId();
}
void SetMainThreadId()
{
	// initialize main thread id
	if (dwMainThreadId == 0)
		dwMainThreadId = ::GetCurrentThreadId();
}

// Do shutdown time stuff on the main thread.
void DoMainThreadShutdown()
{
	g_mq->Shutdown();
}

// Perform first time initialization on the main thread.
void DoMainThreadInitialization()
{
	g_mq->Initialize();
}

//============================================================================

MacroQuest::MacroQuest()
{
	srand(static_cast<uint32_t>(time(nullptr)));

	InitializeLogging();
}

MacroQuest::~MacroQuest()
{
}

bool MacroQuest::CoreInitialize()
{
	WaitForLavishSoftware();

	DebugSpew("Expected Client version: %s %s", __ExpectedVersionDate, __ExpectedVersionTime);
	DebugSpew("    Real Client version: %s %s", __ActualVersionDate, __ActualVersionTime);

	const char* actualVersionDate = (const char*)__ActualVersionDate;
	const char* actualVersionTime = (const char*)__ActualVersionTime;

	// note: CLIENT_OVERRIDE is always #defined as 1 or 0
#if !CLIENT_OVERRIDE
	if (strncmp(__ExpectedVersionDate, actualVersionDate, strlen(__ExpectedVersionDate)) ||
		strncmp(__ExpectedVersionTime, actualVersionTime, strlen(__ExpectedVersionTime)))
	{
		char szMessage[256];
		sprintf_s(szMessage,
			"Incorrect client version:\n\nExpected client version: %s %s\nActual client version: %s %s",
			__ExpectedVersionDate, __ExpectedVersionTime, actualVersionDate, actualVersionTime
		);
		::MessageBoxA(nullptr, szMessage, "MacroQuest", MB_OK);
		return false;
	}
#endif

	// Load configuration so that we can create a logger.
	if (!InitConfig(mq::internal_paths::MQRoot, mq::internal_paths::Config, mq::internal_paths::MQini))
	{
		LOG_ERROR("InitConfig returned false - initialization aborted.");
		return false;
	}

	if (!InitDirectories(mq::internal_paths::MQini))
	{
		LOG_ERROR("InitDirectories returned false - initialization aborted.");
		return false;
	}

	// Initialize logging 2nd stage
	InitializeLoggingStage2();

	if (!InitializeEQLib())
	{
		LOG_ERROR("InitializeEQLib failed - check logs for more details");
		return false;
	}

	m_memoryPatcher = m_eqlib->GetMemoryPatcher();

	if (!ParseINIFile(mq::internal_paths::MQini))
	{
		LOG_ERROR("ParseINIFile returned false - initialization aborted.");
		return false;
	}

	CrashHandler_Startup();

	InitializePluginHandle();

	ZeroMemory(szEQMappableCommands, sizeof(szEQMappableCommands));
	for (int i = 0; i < nEQMappableCommands; i++)
	{
		if ((uintptr_t)EQMappableCommandList[i] == 0)
		{
			continue;
		}

		szEQMappableCommands[i] = EQMappableCommandList[i];
	}

	// as long nEQMappableCommands is right and these remain at the end, these should never need updating
	// who uses the unknowns anyway? - ieatacid
	// jul 16 2014 uhm had to update these, I didnt check the actual functions
	// so there is no guarantee calling for example TOGGLE_WINDOWMODE will work
	// but at least they are at the end again and nEQMappableCommands was 0x201 today,
	// last update Mar 10 2015 nEQMappableCommands was 0x207
	szEQMappableCommands[nEQMappableCommands - 22] = "UNKNOWN0x20c";//"Magic"
	szEQMappableCommands[nEQMappableCommands - 21] = "UNKNOWN0x20d";//"Fire"
	szEQMappableCommands[nEQMappableCommands - 20] = "UNKNOWN0x20e";//"Cold"
	szEQMappableCommands[nEQMappableCommands - 19] = "UNKNOWN0x20f";//"Disease"
	szEQMappableCommands[nEQMappableCommands - 18] = "CHAT_SEMICOLON";//"Poison"
	szEQMappableCommands[nEQMappableCommands - 17] = "CHAT_SLASH";//"Physical"
	szEQMappableCommands[nEQMappableCommands - 16] = "INSTANT_CAMP";//"Corruption" confirmed 16 jul 2014 -eqmule
	szEQMappableCommands[nEQMappableCommands - 15] = "UNKNOWN0x213";//"Unknown"
	szEQMappableCommands[nEQMappableCommands - 14] = "UNKNOWN0x214";//"Avatar"
	szEQMappableCommands[nEQMappableCommands - 13] = "UNKNOWN0x215";//"RemoveButton"
	szEQMappableCommands[nEQMappableCommands - 12] = "CHAT_EMPTY";//"ClearAll"
	szEQMappableCommands[nEQMappableCommands - 11] = "TOGGLE_WINDOWMODE";//"ClearTaskBecauseTaskNotFound" confirmed 16 jul 2014 -eqmule
	szEQMappableCommands[nEQMappableCommands - 10] = "UNKNOWN0x218";//"NoPlayersLeft"
	szEQMappableCommands[nEQMappableCommands - 9] = "UNKNOWN0x219";//"CreatedSharedTask"
	szEQMappableCommands[nEQMappableCommands - 8] = "CHANGEFACE";//"Complete" confirmed 16 jul 2014 -eqmule
	szEQMappableCommands[nEQMappableCommands - 7] = "UNKNOWN0x21b";//Expired
	szEQMappableCommands[nEQMappableCommands - 6] = "UNKNOWN0x21c";//Script
	szEQMappableCommands[nEQMappableCommands - 5] = "UNKNOWN0x21d";//LeaderRemoved
	szEQMappableCommands[nEQMappableCommands - 4] = "UNKNOWN0x21e";
	szEQMappableCommands[nEQMappableCommands - 3] = "UNKNOWN0x21f";
	szEQMappableCommands[nEQMappableCommands - 2] = "UNKNOWN0x220";
	szEQMappableCommands[nEQMappableCommands - 1] = "UNKNOWN0x221";

	pCommandAPI = new MQCommandAPI();

	InitializeMQ2Benchmarks();

	// These two sub-systems will get us onto the main thread.
	InitializeMQ2Pulse();

	if (m_eqmainLoaded)
	{
		InitializeLoginFrontend();
	}
	m_coreInitialized = true;

	// We will wait for pulse from the game to init on main thread.
	if (g_hLoadComplete.wait())
	{
		LOG_INFO("MacroQuest Loaded.");
		return true;
	}

	return false;
}

void MacroQuest::CoreShutdown()
{
	// We get called on the injection thread. This should happen after everything else
	// has already been shut down.
	if (m_eqlib)
	{
		eqlib::Shutdown(m_eqlib);
		m_eqlib = nullptr;
	}

	m_coreInitialized = false;

	LOG_DEBUG("Shutdown completed");

	g_logger.reset();

	spdlog::shutdown();
}

void MacroQuest::Initialize()
{
	InitializeDetours();

	pDataAPI = new MQDataAPI();
	pDataAPI->Initialize();

	pActorAPI = new MQActorAPI();

	InitializeDisplayHook();
	GraphicsResources_Initialize();
	ImGuiManager_Initialize();

	// this needs to be done before anything that would need to add a callback to string message parsing
	InitializeStringDB();

	InitializeChatHook();
	InitializeAnonymizer();
	InitializeInternalModules();
	AddInternalModule(GetWindowsModule());
	AddInternalModule(GetImGuiToolsModule());
	AddInternalModule(GetSpellsModule());
	AddInternalModule(GetDataAPIModule());
	AddInternalModule(GetActorAPIModule());
	AddInternalModule(GetGroundSpawnsModule());
	AddInternalModule(GetSpawnsModule());
	AddInternalModule(GetItemsModule());
	AddInternalModule(GetPostOfficeModule());
#if IS_EMU_CLIENT
	AddInternalModule(GetEmuExtensionsModule());
#endif
	InitializeMQ2AutoInventory();
	InitializeMQ2KeyBinds();
	InitializePlugins();
	InitializeCachedBuffs();

	g_hLoadComplete.SetEvent();
}

void MacroQuest::Shutdown()
{
	WriteChatColor("MacroQuest Unloading...", USERCOLOR_DEFAULT);
	LOG_INFO("MacroQuest Unloading...");

	ShutdownCachedBuffs();
	ShutdownMQ2KeyBinds();
	ShutdownDisplayHook();
	ShutdownChatHook();
	ShutdownMQ2Pulse();
	ShutdownLoginFrontend();
	ShutdownMQ2AutoInventory();
	ShutdownAnonymizer();
	ShutdownPlugins();
	ShutdownFailedPlugins();
	ShutdownInternalModules();
	ImGuiManager_Shutdown();
	GraphicsResources_Shutdown();
	ShutdownStringDB();
	ShutdownMQ2Benchmarks();

	delete pDataAPI;
	pDataAPI = nullptr;

	delete pActorAPI;
	pActorAPI = nullptr;

	ShutdownDetours();

	g_Loaded = false;

	LOG_INFO("MacroQuest Unloaded.");
	SetEvent(hUnloadComplete);
}

bool MacroQuest::InitializeEQLib()
{
	eqlib::LibraryConfig config;
	config.flags = eqlib::ConfigFlags::EnableAllEvents;
	config.eventReceiver = this;
	config.logger = m_eqlibLogger;

	m_eqlib = eqlib::Initialize(&config);
	return m_eqlib != nullptr;
}

static void SetDefaultLoggingParams()
{
#if LOG_FILENAMES
	spdlog::set_pattern("%L %Y-%m-%d %T.%f [%n] %v (%@)");
#else
	spdlog::set_pattern("%L %Y-%m-%d %T.%f [%n] %v");
#endif
	spdlog::flush_on(spdlog::level::trace);
	spdlog::set_level(spdlog::level::trace);
}

void MacroQuest::InitializeLogging()
{
	auto new_logger = std::make_shared<spdlog::logger>("MQ");

	if (IsDebuggerPresent())
	{
		new_logger->sinks().push_back(std::make_shared<spdlog::sinks::msvc_sink_mt>(false));
	}

	m_logger = new_logger;
	spdlog::set_default_logger(new_logger);

	SetDefaultLoggingParams();

	g_logger = m_logger;

	LOG_DEBUG("Logging Initialized");
}

void MacroQuest::InitializeLoggingStage2()
{
	fmt::memory_buffer filename;
	auto out = fmt::format_to(fmt::appender(filename),
		"{}\\{}", mq::internal_paths::Logs, mq::CreateLogFilename("MacroQuest"));
	*out = 0;

	// Create file sink
	try
	{
		auto fileSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(filename.data(), true);
		m_logger->sinks().push_back(fileSink);
	}
	catch (const spdlog::spdlog_ex& ex)
	{
		LOG_WARN("Failed to create file logger: {}, ex: {}",
			std::string_view(filename.data(), filename.size()), ex.what());
	}

	m_eqlibLogger = std::make_shared<spdlog::logger>("EQLib", begin(m_logger->sinks()), end(m_logger->sinks()));
	spdlog::register_logger(m_eqlibLogger);

	SetDefaultLoggingParams();
}

void MacroQuest::OnEQMainDllLoadedStateChanged(bool loaded)
{
	if (loaded)
	{
		if (m_coreInitialized)
		{
			InitializeLoginFrontend();
		}

		m_eqmainLoaded = true;
	}
	else
	{
		m_eqmainLoaded = false;

		ShutdownLoginFrontend();
	}
}

//============================================================================

HMODULE GetCurrentModule()
{
	HMODULE hModule = nullptr;

	// Retrieve our current module handle by using the address of this function as a search param.
	GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS
		| GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, (LPCTSTR)GetCurrentModule, &hModule);

	return hModule;
}


// ***************************************************************************
// Function:    MQ2End Thread
// Description: Where we end execution during the ejection
// ***************************************************************************
DWORD WINAPI MQ2End(void* lpParameter)
{
	DWORD gs = GetGameState();

	if (gs == GAMESTATE_PRECHARSELECT)
	{
		if (hUnloadComplete)
		{
			CloseHandle(hUnloadComplete);
			hUnloadComplete = nullptr;
		}
	}

	bRunNextCommand = true;

	EndAllMacros();

	DebugSpew("%s", ToUnloadString);

	if (gs == GAMESTATE_INGAME || gs == GAMESTATE_CHARSELECT)
	{
		WriteChatColor(ToUnloadString, USERCOLOR_DEFAULT);
	}

	gbUnload = true;
	return 0;
}

DWORD WINAPI GetlocalPlayerOffset()
{
	return (DWORD)pinstLocalPlayer_x;
}

/**
 * Initialization point immediately after injection. Thread will persist until unload is requested,
 * and then will wait for unload to complete. When thread exits, it will unload the library.
 *
 * @param lpParameter Pointer to MQInjectStartupParams
 * @return
 */
DWORD WINAPI MacroQuestBackgroundThread(void* lpParameter)
{
	InstallUnhandledExceptionFilter();

	g_hLoadComplete.create(wil::EventOptions::ManualReset);

	hUnloadComplete = CreateEvent(nullptr, TRUE, FALSE, nullptr);

	MODULEINFO EQGameModuleInfo;
	HMODULE hEQGameModule = GetModuleHandle(nullptr);

	GetModuleInformation(GetCurrentProcess(), hEQGameModule, &EQGameModuleInfo, sizeof(MODULEINFO));
	g_eqgameimagesize = (uintptr_t)hEQGameModule + EQGameModuleInfo.SizeOfImage;

	g_mq = new MacroQuest();

	// Initialize will block until the first frame is handled.
	if (g_mq->CoreInitialize())
	{
		DebugSpewAlways("%s", LoadedString);

		while (!gbUnload)
		{
			Sleep(500);
		}

		WaitForSingleObject(hUnloadComplete, 1800000);
		CloseHandle(hUnloadComplete);
		hUnloadComplete = nullptr;
	}
	else
	{
		g_Loaded = false;

		MessageBox(nullptr, "Failed to Initialize MQ.", "MQ Error", MB_OK);
	}

	g_mq->CoreShutdown();
	delete g_mq;

	UninstallUnhandledExceptionFilter();

	FreeLibraryAndExitThread(GetCurrentModule(), 0);
}

class CMQNewsWnd : public CCustomWnd
{
public:
	CMQNewsWnd() : CCustomWnd("ChatWindow")
	{
		AddStyle(CWS_TITLE | CWS_MINIMIZE);
		RemoveStyle(CWS_TRANSPARENT | CWS_CLOSE);
		SetBGColor(0xFF000000);
		SetLocation({ 230,620,850,920 });
		SetWindowText("MacroQuest Recent Changes");
		SetZLayer(1);

		OutputBox = (CStmlWnd*)GetChildItem("CW_ChatOutput");
		OutputBox->SetParentWindow(this);

		// Disable the input box since it doesn't handle anything anyway.
		InputBox = (CEditWnd*)GetChildItem("CW_ChatInput");
		InputBox->SetParentWindow(this);
		InputBox->Enabled = false;
	}

	~CMQNewsWnd()
	{
	}

	int WndNotification(CXWnd* pWnd, unsigned int Message, void* unknown) override
	{
		if (pWnd == nullptr)
		{
			if (Message == XWM_CLOSE)
			{
				this->SetVisible(true);
				return 1;
			}
		}

		return CCustomWnd::WndNotification(pWnd, Message, unknown);
	};

	CStmlWnd* OutputBox;
	CEditWnd* InputBox;
};
CMQNewsWnd* pNewsWindow = nullptr;

void AddNewsLine(const char* Line, int inColor)
{
	char szLine[MAX_STRING] = { 0 };
	strcpy_s(szLine, Line);

	COLORREF color = pChatManager->GetRGBAFromIndex(inColor);

	char szProcessed[MAX_STRING] = { 0 };
	MQToSTML(szLine, szProcessed, MAX_STRING, color);

	strcat_s(szProcessed, "<br>");
	CXStr NewText(szProcessed);
	ConvertItemTags(NewText, 0);

	pNewsWindow->OutputBox->AppendSTML(NewText);
}

void DeleteMQ2NewsWindow()
{
	delete pNewsWindow;
	pNewsWindow = nullptr;
}

void InsertMQ2News(const std::filesystem::path& pathChangeLog)
{
	if (!pNewsWindow)
		return;

	FILE* file = _fsopen(pathChangeLog.string().c_str(), "rb", _SH_DENYNO);
	if (!file)
	{
		DeleteMQ2NewsWindow();
		return;
	}

	//AddNewsLine("If you need help, refer to www.macroquest2.com/wiki", CONCOLOR_RED);
	AddNewsLine("Recent changes...", CONCOLOR_RED);

	char szLine[MAX_STRING] = { 0 };
	int nLines = 0;

	while (fgets(szLine, MAX_STRING, file))
	{
		char* Next_Token1 = nullptr;

		if (char* Cmd = strtok_s(szLine, "\r\n", &Next_Token1))
		{
			// TODO:  Move this to a method that isn't going to hit false positives.  Change the colors to be nicer on the eyes.
			if (GetIntFromString(Cmd, 0) != 0
				|| ci_starts_with(Cmd, "Jan")
				|| ci_starts_with(Cmd, "Feb")
				|| ci_starts_with(Cmd, "Mar")
				|| ci_starts_with(Cmd, "Apr")
				|| ci_starts_with(Cmd, "May")
				|| ci_starts_with(Cmd, "Jun")
				|| ci_starts_with(Cmd, "Jul")
				|| ci_starts_with(Cmd, "Aug")
				|| ci_starts_with(Cmd, "Sep")
				|| ci_starts_with(Cmd, "Oct")
				|| ci_starts_with(Cmd, "Nov")
				|| ci_starts_with(Cmd, "Dec"))
				AddNewsLine(Cmd, CONCOLOR_YELLOW);
			else
				AddNewsLine(Cmd, CONCOLOR_GREEN);
		}
		else
		{
			AddNewsLine("", CONCOLOR_GREEN);
		}

		nLines++;

		if (nLines > 200)
		{
			AddNewsLine("...read CHANGELOG.md for more.", CONCOLOR_RED);
			break;
		}
	}

	fclose(file);
}

void CreateMQ2NewsWindow()
{
	// NOTE: This change log search logic is duplicated in the launcher menu item.
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

	if (!pNewsWindow && exists(pathChangeLog, ec))
	{
		pNewsWindow = new CMQNewsWnd();
	}

	InsertMQ2News(pathChangeLog);
}

//============================================================================

#pragma region DataAPI Functions

bool MacroQuest::AddTopLevelObject(
	const char* name,
	MQTopLevelObjectFunction callback,
	const MQPluginHandle& pluginHandle)
{
	return pDataAPI->AddTopLevelObject(name, std::move(callback), pluginHandle);
}

bool MacroQuest::RemoveTopLevelObject(
	const char* name,
	const MQPluginHandle& pluginHandle)
{
	return pDataAPI->RemoveTopLevelObject(name, pluginHandle);
}

MQTopLevelObject* MacroQuest::FindTopLevelObject(const char* name)
{
	return pDataAPI->FindTopLevelObject(name);
}

#pragma endregion

#pragma region ActorAPI Functions

void MacroQuest::SendToActor(
	postoffice::Dropbox* dropbox,
	const postoffice::Address& address,
	const std::string& data,
	const postoffice::ResponseCallbackAPI& callback,
	const MQPluginHandle& pluginHandle)
{
	pActorAPI->SendToActor(dropbox, address, data, callback, pluginHandle);
}

void MacroQuest::ReplyToActor(
	postoffice::Dropbox* dropbox,
	const std::shared_ptr<postoffice::Message>& message,
	const std::string& data,
	uint8_t status,
	const MQPluginHandle& pluginHandle)
{
	pActorAPI->ReplyToActor(dropbox, message, data, status, pluginHandle);
}

postoffice::Dropbox* MacroQuest::AddActor(
	const char* localAddress,
	postoffice::ReceiveCallbackAPI&& receive,
	const MQPluginHandle& pluginHandle)
{
	return pActorAPI->AddActor(localAddress, std::move(receive), pluginHandle);
}

void MacroQuest::RemoveActor(postoffice::Dropbox*& dropbox, const MQPluginHandle& pluginHandle)
{
	pActorAPI->RemoveActor(dropbox, pluginHandle);
}

#pragma endregion

#pragma region CommandAPI Functions

bool MacroQuest::AddCommand(std::string_view command, MQCommandHandler handler, bool eq, bool parse, bool inGame, const MQPluginHandle& pluginHandle)
{
	return pCommandAPI->AddCommand(command, handler, eq, parse, inGame, pluginHandle);
}

bool MacroQuest::RemoveCommand(std::string_view command, const MQPluginHandle& pluginHandle)
{
	return pCommandAPI->RemoveCommand(command, pluginHandle);
}

bool MacroQuest::IsCommand(std::string_view command) const
{
	return pCommandAPI->IsCommand(command);
}

void MacroQuest::DoCommand(const char* command, bool delayed, const MQPluginHandle& pluginHandle)
{
	pCommandAPI->DoCommand(command, delayed, pluginHandle);
}

void MacroQuest::TimedCommand(const char* command, int msDelay, const MQPluginHandle& pluginHandle)
{
	pCommandAPI->TimedCommand(command, msDelay, pluginHandle);
}

bool MacroQuest::AddAlias(const std::string& shortCommand, const std::string& longCommand, bool persist, const MQPluginHandle& pluginHandle)
{
	return pCommandAPI->AddAlias(shortCommand, longCommand, persist, pluginHandle);
}

bool MacroQuest::RemoveAlias(const std::string& shortCommand, const MQPluginHandle& pluginHandle)
{
	return pCommandAPI->RemoveAlias(shortCommand, pluginHandle);
}

bool MacroQuest::IsAlias(const std::string& alias) const
{
	return pCommandAPI->IsAlias(alias);
}

#pragma endregion

#pragma region Detour API Functions

bool MacroQuest::ValidateNewPatch(uintptr_t address, size_t numBytes, std::string_view name, const MQPluginHandle& pluginHandle) const
{
	eqlib::MemoryPatch* existingPatch = nullptr;

	if (m_memoryPatcher->FindPatches(address, numBytes, &existingPatch, 1) != 0)
	{
		if (pluginHandle == mqplugin::ThisPluginHandle || existingPatch->GetUserData() == 0)
			return false;

		MQPlugin* otherPlugin = GetPluginByHandle(MQPluginHandle{ existingPatch->GetUserData() });
		MQPlugin* thisPlugin = GetPluginByHandle(pluginHandle);

		if (existingPatch->GetAddress() == address)
		{
			LOG_ERROR("Plugin \"{}\" tried to detour address 0x{:X} (\"{}\") but it already exists as another detour created by {}",
				thisPlugin->name, address, name, otherPlugin ? std::string_view(otherPlugin->name) : std::string_view("(NULL)"));
		}
		else
		{
			LOG_ERROR("Plugin \"{}\" tried to detour address 0x{:X} (\"{}\") but it conflicts with another detour created by {}",
				thisPlugin->name, address, name, otherPlugin ? std::string_view(otherPlugin->name) : std::string_view("(NULL)"));
		}

		return false;
	}

	return true;
}

bool MacroQuest::CreateDetour(uintptr_t address, void** target, void* detour, std::string_view name, const MQPluginHandle& pluginHandle)
{
	if (!ValidateNewPatch(address, eqlib::DETOUR_BYTES_COUNT, name, pluginHandle))
		return false;

	if (eqlib::MemoryPatch* memoryPatch = m_memoryPatcher->CreatePatch(address, target, detour, name))
	{
		m_memoryPatcher->SetUserData(memoryPatch, pluginHandle.pluginID);

		return true;
	}

	return false;
}

bool MacroQuest::RemoveDetour(uintptr_t address, const MQPluginHandle& pluginHandle)
{
	eqlib::MemoryPatch* patch = m_memoryPatcher->GetPatch(address);

	if (!patch || patch->GetType() != eqlib::MemoryPatch::Type::Detour)
	{
		LOG_WARN("Failed to remove detour at 0x{:X}: Detour not found", address);

		return false;
	}

	if (patch->GetUserData() != pluginHandle.pluginID)
	{
		if (patch->GetUserData() == 0)
		{
			LOG_WARN("Failed to remove detour at 0x{:X}: Detour is owned by MQ", address);
		}
		else
		{
			MQPlugin* plugin = GetPluginByHandle(MQPluginHandle{ patch->GetUserData() });

			if (plugin)
			{
				LOG_WARN("Failed to remove detour at 0x{:X}: Detour is owned by {}", address, plugin->name);
			}
			else
			{
				LOG_WARN("Failed to remove detour at 0x{:X}: Detour is owned by an unknown plugin", address);
			}
		}
	}

	return m_memoryPatcher->RemovePatch(address);
}

bool MacroQuest::AddPatch(uintptr_t address, size_t numBytes, std::string_view name, const MQPluginHandle& pluginHandle)
{
	if (!ValidateNewPatch(address, numBytes, name, pluginHandle))
		return false;

	if (eqlib::MemoryPatch* memoryPatch = m_memoryPatcher->CreatePatch(address, numBytes, name))
	{
		m_memoryPatcher->SetUserData(memoryPatch, pluginHandle.pluginID);

		return true;
	}

	return false;
}

bool MacroQuest::AddPatch(uintptr_t address, const uint8_t* newBytes, size_t numBytes, const uint8_t* expectedBytes,
	std::string_view name, const MQPluginHandle& pluginHandle)
{
	if (!ValidateNewPatch(address, numBytes, name, pluginHandle))
		return false;

	if (eqlib::MemoryPatch* memoryPatch = m_memoryPatcher->CreatePatch(address, newBytes, numBytes, expectedBytes, name))
	{
		m_memoryPatcher->SetUserData(memoryPatch, pluginHandle.pluginID);

		return true;
	}

	return false;
}

bool MacroQuest::RemovePatch(uintptr_t address, const MQPluginHandle& pluginHandle)
{
	eqlib::MemoryPatch* patch = m_memoryPatcher->GetPatch(address);

	if (!patch || patch->GetType() != eqlib::MemoryPatch::Type::Patch)
	{
		LOG_WARN("Failed to remove patch at 0x{:X}: Patch not found", address);

		return false;
	}

	if (patch->GetUserData() != pluginHandle.pluginID)
	{
		if (patch->GetUserData() == 0)
		{
			LOG_WARN("Failed to remove patch at 0x{:X}: Patch is owned by MQ", address);
		}
		else
		{
			MQPlugin* plugin = GetPluginByHandle(MQPluginHandle{ patch->GetUserData() });

			if (plugin)
			{
				LOG_WARN("Failed to remove patch at 0x{:X}: Patch is owned by {}", address, plugin->name);
			}
			else
			{
				LOG_WARN("Failed to remove patch at 0x{:X}: Patch is owned by an unknown plugin", address);
			}
		}
	}

	return m_memoryPatcher->RemovePatch(address);
}

std::vector<eqlib::MemoryPatch*> MacroQuest::FindPatches(uintptr_t address, size_t width)
{
	std::vector<eqlib::MemoryPatch*> result;
	uintptr_t endAddress = address + width;
	size_t offset = 0;

	// Ferry list of patches across dll boundary...
	constexpr uint32_t MAX_PER_ITERATION = 100;
	eqlib::MemoryPatch* patches[MAX_PER_ITERATION];

	uint32_t count = m_memoryPatcher->FindPatches(address, width, patches, MAX_PER_ITERATION);
	if (count == 0)
		return result;

	// Count is the total number of patches found, so we can resize as soon as we know.
	result.resize(count);

	// Now we iterate through results until we have all the patches.
	memcpy(result.data() + offset, patches, std::min(MAX_PER_ITERATION, count));

	while (count > MAX_PER_ITERATION)
	{
		offset += MAX_PER_ITERATION;

		address = result.back()->GetAddress() + result.back()->GetBytesSize();
		width = endAddress - address;

		count = m_memoryPatcher->FindPatches(address, width, patches, MAX_PER_ITERATION);

		memcpy(result.data() + offset, patches, std::min(MAX_PER_ITERATION, count));
	}

	return result;
}

bool MacroQuest::IsAddressPatched(uintptr_t address, size_t width)
{
	return m_memoryPatcher->IsAddressPatched(address, width);
}

bool detail::CreateDetour(uintptr_t address, void** target, void* detour, std::string_view name)
{
	return g_mq->CreateDetour(address, target, detour, name, mqplugin::ThisPluginHandle);
}

bool RemoveDetour(uintptr_t address)
{
	return g_mq->RemoveDetour(address, mqplugin::ThisPluginHandle);
}

bool AddPatch(uintptr_t address, size_t width, std::string_view name)
{
	return g_mq->AddPatch(address, width, name, mqplugin::ThisPluginHandle);
}

bool AddPatch(uintptr_t address, const uint8_t* newBytes, size_t numBytes,
	const uint8_t* expectedBytes, std::string_view name)
{
	return g_mq->AddPatch(address, newBytes, numBytes, expectedBytes, name, mqplugin::ThisPluginHandle);
}

bool RemovePatch(uintptr_t address)
{
	return g_mq->RemovePatch(address, mqplugin::ThisPluginHandle);
}


#pragma endregion

MainInterface* GetMainInterface()
{
	return g_mq;
}

} // namespace mq

#if __has_include("../private/MQ2Main-private.cpp")
#include "../private/MQ2Main-private.cpp"
#endif
