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

#include "pch.h"
#include "MQ2Main.h"
#include "CrashHandler.h"

#include "common/NamedPipes.h"

#include <date/date.h>
#include <fmt/format.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/msvc_sink.h>
#include <wil/resource.h>
#include <fstream>

#include "client/crashpad_client.h"

#include <Psapi.h>
#pragma comment(lib, "Psapi.lib")
#pragma comment(lib, "version.lib")

#define CLIENT_OVERRIDE 0

#if defined(LIVE)
#pragma message("Building MQ2 for LIVE")
#define MacroQuestWinClassName "__MacroQuest2Tray(Live)"
#define MacroQuestWinName "MacroQuest2(Live)"
#elif defined(TEST)
#pragma message("Building MQ2 for TEST")
#define MacroQuestWinClassName "__MacroQuest2Tray(Test)"
#define MacroQuestWinName "MacroQuest2(Test)"
#endif

namespace fs = std::filesystem;

namespace mq {

//============================================================================

// From MQ2LoginFrontend.cpp
void InitializeLoginFrontend();
void ShutdownLoginFrontend();

DWORD WINAPI MQ2Start(void* lpParameter);
HANDLE hMQ2StartThread = nullptr;
DWORD dwMainThreadId = 0;

wil::unique_event g_hLoadComplete;
HANDLE hUnloadComplete = nullptr;
NamedPipeClient gPipeClient{ mq::MQ2_PIPE_SERVER_PATH };

void InitializeLogging()
{
	fs::path loggingPath = mq::internal_paths::Logs;
	std::string filename = (loggingPath / fmt::format("MacroQuest-{}.log",
		date::format("%Y%m%dT%H%M%SZ", date::floor<std::chrono::microseconds>(
			std::chrono::system_clock::now())))).string();

	// create color multi threaded logger
	auto logger = spdlog::create<spdlog::sinks::basic_file_sink_mt>("MQ2", filename, true);
	if (IsDebuggerPresent())
		logger->sinks().push_back(std::make_shared<spdlog::sinks::msvc_sink_mt>());
	logger->sinks().push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());

	spdlog::set_default_logger(logger);
#if LOG_FILENAMES
	spdlog::set_pattern("%L %Y-%m-%d %T.%f [%n] %v (%@)");
#else
	spdlog::set_pattern("%L %Y-%m-%d %T.%f [%n] %v");
#endif
	spdlog::flush_on(spdlog::level::trace);
	spdlog::set_level(spdlog::level::trace);

	SPDLOG_DEBUG("Logging Initialized");
}

extern "C" BOOL APIENTRY DllMain(HANDLE hModule, DWORD ul_reason_for_call, void* lpReserved)
{
	char szFilename[MAX_STRING] = { 0 };
	ghModule = (HMODULE)hModule;
	ghInstance = (HINSTANCE)hModule;
	ghInjectorWnd = FindWindowA(MacroQuestWinClassName, MacroQuestWinName);

	GetModuleFileName(nullptr, szFilename, MAX_STRING);

	char* szProcessName = strrchr(szFilename, '.');
	szProcessName[0] = '\0';
	szProcessName = strrchr(szFilename, '\\') + 1;

	if (!_stricmp(szProcessName, __ClientName))
	{
		if (ul_reason_for_call == DLL_PROCESS_ATTACH)
		{
			// Get path to the dll and strip off the filename
			GetModuleFileName(ghModule, szFilename, MAX_STRING);
			szProcessName = strrchr(szFilename, '\\');
			szProcessName[0] = '\0';

			mq::internal_paths::MQRoot = szFilename;
			g_Loaded = true;

			hMQ2StartThread = CreateThread(nullptr, 0, MQ2Start, _strdup(szFilename), 0, &ThreadID);
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

	if (std::filesystem::exists(pathToInit) || std::filesystem::create_directories(pathToInit))
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

	// If the path to MQ2 doesn't exist none of our relative paths are going to work
	if (std::filesystem::exists(pathMQRoot))
	{
		std::filesystem::path pathMQini = strMQini;

		// If the ini path is relative, prepend the MQ2 path
		if (pathMQini.is_relative())
		{
			pathMQini = pathMQRoot / pathMQini;
		}

		if (!std::filesystem::exists(pathMQini))
		{
			// Check if the ini file exists in the same directory as MQ2
			if (std::filesystem::exists(pathMQRoot / "MacroQuest.ini"))
			{
				pathMQini = pathMQRoot / "MacroQuest.ini";
			}
			else if (std::filesystem::exists(pathMQRoot / strConfig / "MacroQuest_default.ini"))
			{
				// copy into the config directory and work from there.
				std::filesystem::copy_file(
					pathMQRoot / strConfig / "MacroQuest_default.ini",
					pathMQRoot / strConfig / "MacroQuest.ini");
			}
		}

		if (std::filesystem::exists(pathMQini))
		{
			// Check to see if there a different config folder we should be looking at?
			char szTempPath[MAX_PATH] = { 0 };
			GetPrivateProfileString("MacroQuest", "ConfigPath", strConfig, szTempPath, MAX_PATH , pathMQini.string());
			strConfig = szTempPath;

			// Change the ini file to the one in the new config folder
			pathMQini = std::filesystem::path(strConfig) / "MacroQuest.ini";

			// If it's relative, make it absolute relative to MQ2
			if (pathMQini.is_relative())
			{
				pathMQini = std::filesystem::absolute(pathMQRoot / pathMQini);
			}
		}

		// Set the ini to whatever we ended up with.
		strMQini = pathMQini.string();

		gbWriteAllConfig = GetPrivateProfileBool("MacroQuest", "WriteAllConfig", false, strMQini);

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
#pragma warning(push)
#pragma warning(disable: 4996) // temporarily disable deprecation warnings.
		// Backwards compatible before we deprecate
		strcpy_s(gszMacroPath, mq::internal_paths::Macros.c_str());
		strcpy_s(gszLogPath, mq::internal_paths::Logs.c_str());
		// API compatible
		strcpy_s(gPathMacros, mq::internal_paths::Macros.c_str());
		strcpy_s(gPathLogs, mq::internal_paths::Logs.c_str());
		strcpy_s(gPathCrashDumps, mq::internal_paths::CrashDumps.c_str());
		strcpy_s(gPathPlugins, mq::internal_paths::Plugins.c_str());
		strcpy_s(gPathResources, mq::internal_paths::Resources.c_str());
#pragma warning(pop)
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

	DebugSpew("Expected Client version: %s %s", __ExpectedVersionDate, __ExpectedVersionTime);
	DebugSpew("    Real Client version: %s %s", __ActualVersionDate, __ActualVersionTime);

	// note: CLIENT_OVERRIDE is always #defined as 1 or 0
#if !CLIENT_OVERRIDE
	if (strncmp(__ExpectedVersionDate, (const char*)__ActualVersionDate, strlen(__ExpectedVersionDate)) ||
		strncmp(__ExpectedVersionTime, (const char*)__ActualVersionTime, strlen(__ExpectedVersionTime)))
	{
		MessageBox(nullptr, "Incorrect client version", "MacroQuest", MB_OK);
		return false;
	}
#endif

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

	gAnonymize               = GetPrivateProfileBool("Captions", "Anonymize", gAnonymize, iniFile);
	gAnonymizeFlag           = (EAnonFlags)GetPrivateProfileInt("Captions", "AnonymizeFlag", gAnonymizeFlag, iniFile);

	if (gbWriteAllConfig)
	{
		WritePrivateProfileBool("Captions", "Anonymize", gAnonymize, iniFile);
		WritePrivateProfileInt("Captions", "AnonymizeFlag", gAnonymizeFlag, iniFile);
	}

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
	while (pFilterList[0] != 0)
	{
		std::string filter = GetPrivateProfileString("Filter Names", pFilterList, "", iniFile);

		if (!filter.empty() && filter != "NOBODY")
		{
			AddFilter(szBuffer, -1, gFilterCustom);
		}

		pFilterList += strlen(pFilterList) + 1;
	}

	const std::filesystem::path itemDBPath = std::filesystem::path(mq::internal_paths::Resources) / "ItemDB.txt";
	if (std::filesystem::exists(itemDBPath))
	{
#pragma warning(push)
#pragma warning(disable: 4996) // temporarily disable deprecation warnings.
		// Backwards compatibility prior to deprecation
		strcpy_s(gszItemDB, itemDBPath.string().c_str());
#pragma warning(pop)

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

void InitializeMQ2IcExports()
{
	IC_GetHashData = (fICGetHashData)GetProcAddress(ghmq2ic, "IC_GetHashData");
	IC_SetHashData = (fICSetHashData)GetProcAddress(ghmq2ic, "IC_SetHashData");
	IC_LoaderSetLoaded = (fLoaderSetLoaded)GetProcAddress(ghmq2ic, "IC_LoaderSetLoaded");
	IC_LoaderClearLoaded = (fLoaderClearLoaded)GetProcAddress(ghmq2ic, "IC_LoaderClearLoaded");
	IC_MQ2Unload = (fMQ2Unload)GetProcAddress(ghmq2ic, "IC_MQ2Unload");
	IC_ClassLvl = (fClassLvl)GetProcAddress(ghmq2ic, "IC_ClassLvl");
}

void DeInitializeMQ2IcExports()
{
	IC_GetHashData = nullptr;
	IC_SetHashData = nullptr;
	IC_LoaderSetLoaded = nullptr;
	IC_MQ2Unload = nullptr;
	IC_ClassLvl = nullptr;
}

void SetMainThreadId()
{
	// initialize main thread id
	if (dwMainThreadId == 0)
		dwMainThreadId = ::GetCurrentThreadId();
}

class PipeEventsHandler : public NamedPipeEvents
{
public:
	virtual void OnIncomingMessage(std::shared_ptr<PipeMessage> message) override
	{
		if (message->GetMessageId() == MQMessageId::MSG_MAIN_CRASHPAD_CONFIG)
		{
			// Message needs to at least have some substance...
			if (message->size() > 0)
			{
				std::string pipeName{ message->get<const char>() };

				if (pipeName.empty())
				{
					InitializeCrashpad();
				}
				else
				{
					InitializeCrashpadPipe(message->get<const char>());
				}
			}
		}
	}
};

// Perform first time initialization on the main thread.
void DoInitialization()
{
	gPipeClient.SetHandler(std::make_shared<PipeEventsHandler>());
	gPipeClient.Start();
	::atexit([]() { gPipeClient.Stop(); });

	InitializeMQ2Commands();
	InitializeMQ2Windows();
	InitializeMQ2AutoInventory();
	InitializeMQ2CrashHandler();

	MQ2MouseHooks(true);
	Sleep(100);

	InitializeMQ2KeyBinds();
	InitializeMQ2Overlay();
	InitializeMQ2Plugins();
	InitializeCachedBuffs();
}

// Perform injection-time initialization. This occurs on the injection thread.
bool MQ2Initialize()
{
	MODULEINFO EQGameModuleInfo;
	HMODULE hEQGameModule = GetModuleHandle(nullptr);

	GetModuleInformation(GetCurrentProcess(), hEQGameModule, &EQGameModuleInfo, sizeof(MODULEINFO));
	g_eqgameimagesize = (DWORD)hEQGameModule + EQGameModuleInfo.SizeOfImage;

	if (GetModuleHandle("Lavish.dll") || GetModuleHandle("InnerSpace.dll"))
	{
		uintptr_t baseAddress = 0;
		uintptr_t endAddress = 0;

		MODULEINFO moduleInfo;
		HMODULE hISModule = GetModuleHandle("InnerSpace.dll");
		HMODULE hKernelModule = GetModuleHandleA("kernel32.dll");

		if (hISModule
			&& GetModuleInformation(GetCurrentProcess(), hISModule, &moduleInfo, sizeof(MODULEINFO)))
		{
			baseAddress = (uintptr_t)moduleInfo.lpBaseOfDll;
			endAddress = baseAddress + (uintptr_t)moduleInfo.SizeOfImage;
		}

		bool foundHooks = baseAddress == 0;             // skip checks if InnerSpace.dll isn't loaded
		bool foundWindowHandle = false;

		// Do some checks against Lavish/InnerSpace integrations. Wait a total of 10 seconds of we fail all checks.
		auto startTime = std::chrono::steady_clock::now();
		while (std::chrono::steady_clock::now() - startTime < std::chrono::seconds{ 10 } && !(foundHooks && foundWindowHandle))
		{
			std::this_thread::sleep_for(std::chrono::milliseconds{ 200 });

			if (!foundHooks)
			{
				// Wait for InnerSpace to finish loading before we try to continue. InnerSpace will modify our
				// import address table, resulting in our detours being ineffective if we go first.
				uintptr_t fnGetProcAddress = (uintptr_t)&::GetProcAddress;
				if (fnGetProcAddress >= baseAddress && fnGetProcAddress < endAddress)
				{
					foundHooks = true;
				}
				else
				{
					fnGetProcAddress = (uintptr_t)GetProcAddress(hKernelModule, "GetProcAddress");
					if (fnGetProcAddress >= baseAddress && fnGetProcAddress < endAddress)
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
		};

		if (!foundHooks)
		{
			DebugSpewAlways("Was not able to detect the InnerSpace hook on GetProcAddress!");
		}

		if (!foundWindowHandle)
		{
			DebugSpewAlways("Was not able to detect the main EQ window handle!");
		}
	}

	eqlib::InitializeEQLib();

	if (!InitOffsets())
	{
		DebugSpewAlways("InitOffsets returned false - thread aborted.");
		g_Loaded = false;
		return false;
	}

	if (!InitConfig(mq::internal_paths::MQRoot, mq::internal_paths::Config, mq::internal_paths::MQini))
	{
		DebugSpewAlways("InitConfig returned false - thread aborted.");
		g_Loaded = false;
		return false;
	}

	if (!InitDirectories(mq::internal_paths::MQini))
	{
		DebugSpewAlways("InitDirectories returned false - thread aborted.");
		g_Loaded = false;
		return false;
	}

	if (!ParseINIFile(mq::internal_paths::MQini))
	{
		DebugSpewAlways("ParseINIFile returned false - thread aborted.");
		g_Loaded = false;
		return false;
	}

	InitializeLogging();
	InitializeCrashHandler();

	srand(static_cast<uint32_t>(time(nullptr)));

	ZeroMemory(szEQMappableCommands, sizeof(szEQMappableCommands));
	for (int i = 0; i < nEQMappableCommands; i++)
	{
		if ((DWORD)EQMappableCommandList[i] == 0)
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
	szEQMappableCommands[nEQMappableCommands -  9] = "UNKNOWN0x219";//"CreatedSharedTask"
	szEQMappableCommands[nEQMappableCommands -  8] = "CHANGEFACE";//"Complete" confirmed 16 jul 2014 -eqmule
	szEQMappableCommands[nEQMappableCommands -  7] = "UNKNOWN0x21b";//Expired
	szEQMappableCommands[nEQMappableCommands -  6] = "UNKNOWN0x21c";//Script
	szEQMappableCommands[nEQMappableCommands -  5] = "UNKNOWN0x21d";//LeaderRemoved
	szEQMappableCommands[nEQMappableCommands -  4] = "UNKNOWN0x21e";
	szEQMappableCommands[nEQMappableCommands -  3] = "UNKNOWN0x21f";
	szEQMappableCommands[nEQMappableCommands -  2] = "UNKNOWN0x220";
	szEQMappableCommands[nEQMappableCommands -  1] = "UNKNOWN0x221";

	InitializeMQ2Detours();

	// from now on MQ2Ic is not optional.
	LoadMQ2Plugin("mq2ic");

	if (ghmq2ic = GetModuleHandle("mq2ic.dll"))
		InitializeMQ2IcExports();

	InitializeMQ2Benchmarks();
	InitializeParser();
	InitializeDisplayHook();
	InitializeChatHook();
	InitializeMQ2Spawns();
	InitializeMQ2Pulse();
	InitializeLoginFrontend();

	// We will wait for pulse from the game to init on main thread.
	g_hLoadComplete.wait();
	return true;
}

// Do shutdown time stuff on the main thread.
void MQ2Shutdown()
{
	OutputDebugString("MQ2Shutdown Called");

	DebugTry(ShutdownCachedBuffs());
	DebugTry(ShutdownMQ2KeyBinds());
	DebugTry(ShutdownMQ2Spawns());
	DebugTry(ShutdownDisplayHook());
	DebugTry(ShutdownMQ2DInput());
	DebugTry(ShutdownChatHook());
	DebugTry(ShutdownMQ2Pulse());
	DebugTry(ShutdownLoginFrontend());
	DebugTry(ShutdownMQ2Windows());
	DebugTry(ShutdownMQ2AutoInventory());
	DebugTry(MQ2MouseHooks(false));
	DebugTry(ShutdownMQ2CrashHandler());
	DebugTry(ShutdownParser());
	DebugTry(ShutdownMQ2Commands());
	DebugTry(ShutdownMQ2Plugins());
	DebugTry(ShutdownMQ2Overlay());
	DebugTry(DeInitializeMQ2IcExports());
	DebugTry(ShutdownMQ2Detours());
	DebugTry(ShutdownMQ2Benchmarks());

	gPipeClient.Stop();
}

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

void ForceUnload()
{
	DWORD oldscreenmode = std::exchange(ScreenMode, 3);

	WriteChatColor(UnloadedString, USERCOLOR_DEFAULT);
	DebugSpewAlways("ForceUnload() called, this is not good %s", UnloadedString);

	// dont do this here ShutdownMQ2Plugins() will do it and its called from MQ2Shutdown();
	//UnloadMQ2Plugins();

	MQ2Shutdown();

	DebugSpew("Shutdown completed");
	g_Loaded = false;

	ScreenMode = 2;
}

// ***************************************************************************
// Function:    MQ2Start Thread
// Description: Where we start execution during the insertion
// ***************************************************************************
DWORD WINAPI MQ2Start(void* lpParameter)
{
	InstallUnhandledExceptionFilter();

	g_hLoadComplete.create(wil::EventOptions::ManualReset);

	hUnloadComplete = CreateEvent(nullptr, TRUE, FALSE, nullptr);

	char szBuffer[MAX_STRING] = { 0 };

	if (!MQ2Initialize())
	{
		MessageBox(nullptr, "Failed to Initialize MQ2.", "MQ2 Error", MB_OK);

		if (HMODULE h = GetCurrentModule())
			FreeLibraryAndExitThread(h, 0);
	}

	while (gGameState != GAMESTATE_CHARSELECT && gGameState != GAMESTATE_INGAME)
	{
		if (gbUnload)
		{
			goto getout;
		}

		Sleep(500);
	}

	InitializeMQ2DInput();

	DebugSpewAlways("%s", LoadedString);

	while (!gbUnload)
	{
		Sleep(500);
	}

getout:
	if (hUnloadComplete)
	{
		DWORD dwtime = WaitForSingleObject(hUnloadComplete, 1800000); // 30 mins so i can debug stuff
		if (dwtime == WAIT_TIMEOUT)
		{
			SPDLOG_WARN("I am unloading in MQ2Start due to TIMEOUT");
			ForceUnload();
		}

		CloseHandle(hUnloadComplete);
		hUnloadComplete = nullptr;
	}
	else
	{
		SPDLOG_WARN("I am unloading in MQ2Start this will probably crash");
		ForceUnload();
	}

	if (ScreenMode)
		ScreenMode = 2;

	UninstallUnhandledExceptionFilter();

	if (HMODULE h = GetCurrentModule())
		FreeLibraryAndExitThread(h, 0);

	return 0;
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
		SetWindowText("MacroQuest2 Recent Changes");
		SetZLayer(1);

		OutputBox = (CStmlWnd*)GetChildItem("CW_ChatOutput");
		OutputBox->SetParentWindow(this);
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


	FILE* file = nullptr;
	errno_t err = fopen_s(&file, pathChangeLog.string().c_str(), "rb");
	if (err || !file)
	{
		DeleteMQ2NewsWindow();
		return;
	}

	AddNewsLine("If you need help, refer to www.macroquest2.com/wiki", CONCOLOR_RED);
	AddNewsLine("Recent changes...", CONCOLOR_RED);

	char szLine[MAX_STRING] = { 0 };
	int nLines = 0;

	while (fgets(szLine, MAX_STRING, file))
	{
		char* Next_Token1 = nullptr;

		if (char* Cmd = strtok_s(szLine, "\r\n", &Next_Token1))
		{
			if (GetIntFromString(Cmd, 1))
				AddNewsLine(Cmd, CONCOLOR_GREEN);
			else
				AddNewsLine(Cmd, CONCOLOR_YELLOW);
		}

		nLines++;

		if (nLines > 200)
		{
			AddNewsLine("...read changes.txt for more.", CONCOLOR_RED);
			break;
		}
	}

	fclose(file);
}

void CreateMQ2NewsWindow()
{
	const std::filesystem::path pathChangeLog = std::filesystem::path(mq::internal_paths::MQRoot) / "CHANGELOG.md";

	if (!pNewsWindow && std::filesystem::exists(pathChangeLog))
	{
		pNewsWindow = new CMQNewsWnd();
	}

	InsertMQ2News(pathChangeLog);
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

//============================================================================

HHOOK g_hHook;

LRESULT CALLBACK hookCBTProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	return ::CallNextHookEx(g_hHook, nCode, wParam, lParam);
}

void InjectEnable()
{
	// Install the global hook, injecting this DLL into every other process
	g_hHook = SetWindowsHookEx(WH_CBT, hookCBTProc, ghInstance, 0);
}

void InjectDisable()
{
	UnhookWindowsHookEx(g_hHook);
	g_hHook = nullptr;
}

} // namespace mq
