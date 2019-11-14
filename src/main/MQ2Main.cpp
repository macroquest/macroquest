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
#include <fstream>

#include <Psapi.h>
#pragma comment(lib, "dbghelp.lib")
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

namespace mq {

//============================================================================

DWORD WINAPI MQ2Start(void* lpParameter);
HANDLE hMQ2StartThread = nullptr;
DWORD dwMainThreadId = 0;

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

bool InitDirectory(std::string& strPathToInit, const std::string& strIniKey, const std::string& iniToRead, const std::filesystem::path& appendPathIfRelative = mq::internal_paths::MQRoot, const bool bWriteAllConfig = false)
{
	DebugSpewAlways("Initializing Directory:  %s", strIniKey.c_str());
	char szTempPath[MAX_PATH] = { 0 };
	GetPrivateProfileString("MacroQuest", strIniKey, strPathToInit, szTempPath, MAX_PATH, iniToRead);
	std::filesystem::path pathToInit = szTempPath;
	if (bWriteAllConfig)
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
	std::filesystem::path pathMQRoot = strMQRoot;
	DebugSpewAlways("Initializing Configuration...");
	// If we still have a relative path to the MQ2 directory, make it absolute.
	if (pathMQRoot.is_relative())
	{
		pathMQRoot = std::filesystem::absolute(pathMQRoot).string();
	}
	// Set strMQRoot to the path we found.
	strMQRoot = pathMQRoot.string();

	// If the path to MQ2 doesn't exist none of our relative paths are going to work
	if(std::filesystem::exists(pathMQRoot))
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

		// Init the Config directory based on the ini we found.
		if (InitDirectory(strConfig, "ConfigPath", strMQini, strMQRoot, GetPrivateProfileBool("MacroQuest", "WriteAllConfig", false, strMQini)))
		{
			// Backwards compatible before we deprecate
			strcpy_s(gszEQPath, std::filesystem::absolute(".").string().c_str());
			strcpy_s(gszINIPath, strMQRoot.c_str()); // or mq::internal_paths::Config but since it's mostly used to find the MQ2 directory...
			strcpy_s(gszINIFilename, strMQini.c_str());
			// API compatible
			strcpy_s(gPathMQRoot, strMQRoot.c_str());
			strcpy_s(gPathMQini, strMQini.c_str());
			strcpy_s(gPathConfig, strConfig.c_str());
			return true;
		}
	}

	return false;
}

bool InitDirectories(const std::string& iniToRead)
{
	DebugSpewAlways("Initializing Required Directories...");
	const bool bWriteAllConfig = GetPrivateProfileBool("MacroQuest", "WriteAllConfig", false, iniToRead);
	if (InitDirectory(mq::internal_paths::Macros, "MacroPath", iniToRead, mq::internal_paths::MQRoot, bWriteAllConfig)
		&& InitDirectory(mq::internal_paths::Logs, "LogPath", iniToRead, mq::internal_paths::MQRoot, bWriteAllConfig)
		&& InitDirectory(mq::internal_paths::CrashDumps, "CrashDumpPath", iniToRead, mq::internal_paths::MQRoot, bWriteAllConfig)
		&& InitDirectory(mq::internal_paths::Plugins, "PluginPath", iniToRead, mq::internal_paths::MQRoot, bWriteAllConfig)
		&& InitDirectory(mq::internal_paths::Resources, "ResourcePath", iniToRead, mq::internal_paths::MQRoot, bWriteAllConfig)
		)
	{
		// Backwards compatible before we deprecate
		strcpy_s(gszMacroPath, mq::internal_paths::Macros.c_str());
		strcpy_s(gszLogPath, mq::internal_paths::Logs.c_str());
		// API compatible
		strcpy_s(gPathMacros, mq::internal_paths::Macros.c_str());
		strcpy_s(gPathLogs, mq::internal_paths::Logs.c_str());
		strcpy_s(gPathCrashDumps, mq::internal_paths::CrashDumps.c_str());
		strcpy_s(gPathPlugins, mq::internal_paths::Plugins.c_str());
		strcpy_s(gPathResources, mq::internal_paths::Resources.c_str());
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
	const bool bWriteAllConfig = GetPrivateProfileBool("MacroQuest", "WriteAllConfig", false, iniFile);

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

	int ic = GetPrivateProfileInt("Plugins", "MQ2Ic", 1, iniFile);
	if (ic == 0)
	{
		// its set to 0 thats not good
		WritePrivateProfileString("Plugins", "MQ2Ic", "1", iniFile);
	}

	gFilterSkillsAll         = GetPrivateProfileBool("MacroQuest", "FilterSkills", gFilterSkillsAll, iniFile);
	gFilterSkillsIncrease    = 2 == GetPrivateProfileInt("MacroQuest", "FilterSkills", gFilterSkillsIncrease ? 2 : 0, iniFile);
	if (bWriteAllConfig)
	{
		if (gFilterSkillsAll && gFilterSkillsIncrease)
			WritePrivateProfileString("MacroQuest", "FilterSkills", "2", iniFile);
		else
			WritePrivateProfileString("MacroQuest", "FilterSkills", std::to_string(gFilterSkillsAll), iniFile);
	}

	gFilterDebug             = GetPrivateProfileBool("MacroQuest", "FilterDebug", gFilterDebug, iniFile);
	gFilterMQ2DataErrors     = GetPrivateProfileBool("MacroQuest", "FilterMQ2Data", gFilterMQ2DataErrors, iniFile);
	gFilterTarget            = GetPrivateProfileBool("MacroQuest", "FilterTarget", gFilterTarget, iniFile);
	gFilterMoney             = GetPrivateProfileBool("MacroQuest", "FilterMoney", gFilterMoney, iniFile);
	gFilterFood              = GetPrivateProfileBool("MacroQuest", "FilterFood", gFilterFood, iniFile);
	gFilterMacro             = GetPrivateProfileBool("MacroQuest", "FilterMacro", gFilterMacro, iniFile);
	gFilterEncumber          = GetPrivateProfileBool("MacroQuest", "FilterEncumber", gFilterEncumber, iniFile);
	gFilterCustom            = GetPrivateProfileBool("MacroQuest", "FilterCustom", gFilterCustom, iniFile);
	gSpewToFile              = GetPrivateProfileBool("MacroQuest", "DebugSpewToFile", gSpewToFile, iniFile);
	gMQPauseOnChat           = GetPrivateProfileBool("MacroQuest", "MQPauseOnChat", gMQPauseOnChat, iniFile);
	gKeepKeys                = GetPrivateProfileBool("MacroQuest", "KeepKeys", gKeepKeys, iniFile);
	bAllErrorsDumpStack      = GetPrivateProfileBool("MacroQuest", "AllErrorsDumpStack", bAllErrorsDumpStack, iniFile);
	bAllErrorsFatal          = GetPrivateProfileBool("MacroQuest", "AllErrorsFatal", bAllErrorsFatal, iniFile);
	gbMQ2LoadingMsg          = GetPrivateProfileBool("MacroQuest", "MQ2LoadingMsg", gbMQ2LoadingMsg, iniFile);
	gbExactSearchCleanNames  = GetPrivateProfileBool("MacroQuest", "ExactSearchCleanNames", gbExactSearchCleanNames, iniFile);
	gbTimeStampChat          = GetPrivateProfileBool("MacroQuest", "TimeStampChat", gbTimeStampChat, iniFile);
	gUseTradeOnTarget        = GetPrivateProfileBool("MacroQuest", "UseTradeOnTarget", gUseTradeOnTarget, iniFile);
	gbBeepOnTells            = GetPrivateProfileBool("MacroQuest", "BeepOnTells", gbBeepOnTells, iniFile);
	gbFlashOnTells           = GetPrivateProfileBool("MacroQuest", "FlashOnTells", gbFlashOnTells, iniFile);
	gbIgnoreAlertRecursion   = GetPrivateProfileBool("MacroQuest", "IgnoreAlertRecursion", gbIgnoreAlertRecursion, iniFile);
	gbShowCurrentCamera      = GetPrivateProfileBool("MacroQuest", "ShowCurrentCamera", gbShowCurrentCamera, iniFile);
	gTurboLimit              = GetPrivateProfileInt("MacroQuest", "TurboLimit", gTurboLimit, iniFile);
	gCreateMQ2NewsWindow     = GetPrivateProfileBool("MacroQuest", "CreateMQ2NewsWindow", gCreateMQ2NewsWindow, iniFile);
	gNetStatusXPos           = GetPrivateProfileInt("MacroQuest", "NetStatusXPos", gNetStatusXPos, iniFile);
	gNetStatusYPos           = GetPrivateProfileInt("MacroQuest", "NetStatusYPos", gNetStatusYPos, iniFile);
	gStackingDebug           = GetPrivateProfileInt("MacroQuest", "BuffStackDebugMode", gStackingDebug, iniFile); // 0 = off, 1 = on, 2 = on and output to chat
	gUseNewNamedTest         = GetPrivateProfileBool("MacroQuest", "UseNewNamedTest", gUseNewNamedTest, iniFile);
	gParserVersion           = GetPrivateProfileInt("MacroQuest", "ParserEngine", gParserVersion, iniFile); // 2 = new parser, everything else = old parser
	GetPrivateProfileString("MacroQuest", "IfDelimiter", std::to_string(gIfDelimiter), szBuffer, MAX_STRING, iniFile);
	gIfDelimiter = szBuffer[0];
	GetPrivateProfileString("MacroQuest", "IfAltDelimiter", std::to_string(gIfAltDelimiter), szBuffer, MAX_STRING, iniFile);
	gIfAltDelimiter = szBuffer[0];
	if (bWriteAllConfig)
	{
		WritePrivateProfileString("MacroQuest", "FilterDebug", std::to_string(gFilterDebug), iniFile);
		WritePrivateProfileString("MacroQuest", "FilterMQ2Data", std::to_string(gFilterMQ2DataErrors), iniFile);
		WritePrivateProfileString("MacroQuest", "FilterTarget", std::to_string(gFilterTarget), iniFile);
		WritePrivateProfileString("MacroQuest", "FilterMoney", std::to_string(gFilterMoney), iniFile);
		WritePrivateProfileString("MacroQuest", "FilterFood", std::to_string(gFilterFood), iniFile);
		WritePrivateProfileString("MacroQuest", "FilterMacro", std::to_string(gFilterMacro), iniFile);
		WritePrivateProfileString("MacroQuest", "FilterEncumber", std::to_string(gFilterEncumber), iniFile);
		WritePrivateProfileString("MacroQuest", "FilterCustom", std::to_string(gFilterCustom), iniFile);
		WritePrivateProfileString("MacroQuest", "DebugSpewToFile", std::to_string(gSpewToFile), iniFile);
		WritePrivateProfileString("MacroQuest", "MQPauseOnChat", std::to_string(gMQPauseOnChat), iniFile);
		WritePrivateProfileString("MacroQuest", "KeepKeys", std::to_string(gKeepKeys), iniFile);
		WritePrivateProfileString("MacroQuest", "AllErrorsDumpStack", std::to_string(bAllErrorsDumpStack), iniFile);
		WritePrivateProfileString("MacroQuest", "AllErrorsFatal", std::to_string(bAllErrorsFatal), iniFile);
		WritePrivateProfileString("MacroQuest", "MQ2LoadingMsg", std::to_string(gbMQ2LoadingMsg), iniFile);
		WritePrivateProfileString("MacroQuest", "ExactSearchCleanNames", std::to_string(gbExactSearchCleanNames), iniFile);
		WritePrivateProfileString("MacroQuest", "TimeStampChat", std::to_string(gbTimeStampChat), iniFile);
		WritePrivateProfileString("MacroQuest", "UseTradeOnTarget", std::to_string(gUseTradeOnTarget), iniFile);
		WritePrivateProfileString("MacroQuest", "BeepOnTells", std::to_string(gbBeepOnTells), iniFile);
		WritePrivateProfileString("MacroQuest", "FlashOnTells", std::to_string(gbFlashOnTells), iniFile);
		WritePrivateProfileString("MacroQuest", "IgnoreAlertRecursion", std::to_string(gbIgnoreAlertRecursion), iniFile);
		WritePrivateProfileString("MacroQuest", "ShowCurrentCamera", std::to_string(gbShowCurrentCamera), iniFile);
		WritePrivateProfileString("MacroQuest", "TurboLimit", std::to_string(gTurboLimit), iniFile);
		WritePrivateProfileString("MacroQuest", "CreateMQ2NewsWindow", std::to_string(gCreateMQ2NewsWindow), iniFile);
		WritePrivateProfileString("MacroQuest", "NetStatusXPos", std::to_string(gNetStatusXPos), iniFile);
		WritePrivateProfileString("MacroQuest", "NetStatusYPos", std::to_string(gNetStatusYPos), iniFile);
		WritePrivateProfileString("MacroQuest", "BuffStackDebugMode", std::to_string(gStackingDebug), iniFile);
		WritePrivateProfileString("MacroQuest", "UseNewNamedTest", std::to_string(gUseNewNamedTest), iniFile);
		WritePrivateProfileString("MacroQuest", "ParserEngine", std::to_string(gParserVersion), iniFile);
		WritePrivateProfileString("MacroQuest", "IfDelimiter", std::to_string(gIfDelimiter), iniFile);
		WritePrivateProfileString("MacroQuest", "IfAltDelimiter", std::to_string(gIfAltDelimiter), iniFile);
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
	if (bWriteAllConfig) WritePrivateProfileString("MacroQuest", "HUDMode", szBuffer, iniFile);

	GetPrivateProfileString("Captions", "NPC", gszSpawnNPCName, gszSpawnNPCName, MAX_STRING, iniFile);
	GetPrivateProfileString("Captions", "Player1", gszSpawnPlayerName[1], gszSpawnPlayerName[1], MAX_STRING, iniFile);
	GetPrivateProfileString("Captions", "Player2", gszSpawnPlayerName[2], gszSpawnPlayerName[2], MAX_STRING, iniFile);
	GetPrivateProfileString("Captions", "Player3", gszSpawnPlayerName[3], gszSpawnPlayerName[3], MAX_STRING, iniFile);
	GetPrivateProfileString("Captions", "Player4", gszSpawnPlayerName[4], gszSpawnPlayerName[4], MAX_STRING, iniFile);
	GetPrivateProfileString("Captions", "Player5", gszSpawnPlayerName[5], gszSpawnPlayerName[5], MAX_STRING, iniFile);
	GetPrivateProfileString("Captions", "Player6", gszSpawnPlayerName[6], gszSpawnPlayerName[6], MAX_STRING, iniFile);
	GetPrivateProfileString("Captions", "Corpse", gszSpawnCorpseName, gszSpawnCorpseName, MAX_STRING, iniFile);
	GetPrivateProfileString("Captions", "Pet", gszSpawnPetName, gszSpawnPetName, MAX_STRING, iniFile);
	if (bWriteAllConfig)
	{
		WritePrivateProfileString("Captions", "NPC", gszSpawnNPCName, iniFile);
		WritePrivateProfileString("Captions", "Player1", gszSpawnPlayerName[1], iniFile);
		WritePrivateProfileString("Captions", "Player2", gszSpawnPlayerName[2], iniFile);
		WritePrivateProfileString("Captions", "Player3", gszSpawnPlayerName[3], iniFile);
		WritePrivateProfileString("Captions", "Player4", gszSpawnPlayerName[4], iniFile);
		WritePrivateProfileString("Captions", "Player5", gszSpawnPlayerName[5], iniFile);
		WritePrivateProfileString("Captions", "Player6", gszSpawnPlayerName[6], iniFile);
		WritePrivateProfileString("Captions", "Corpse", gszSpawnCorpseName, iniFile);
		WritePrivateProfileString("Captions", "Pet", gszSpawnPetName, iniFile);
	}

	gMaxSpawnCaptions        = GetPrivateProfileInt("Captions", "Update", gMaxSpawnCaptions, iniFile);
	gMQCaptions              = GetPrivateProfileBool("Captions", "MQCaptions", gMQCaptions, iniFile);
	gAnonymize               = GetPrivateProfileBool("Captions", "Anonymize", gAnonymize, iniFile);
	gAnonymizeFlag           = GetPrivateProfileInt("Captions", "AnonymizeFlag", gAnonymizeFlag, iniFile);
	if (bWriteAllConfig)
	{
		WritePrivateProfileString("Captions", "Update", std::to_string(gMaxSpawnCaptions), iniFile);
		WritePrivateProfileString("Captions", "MQCaptions", std::to_string(gMQCaptions), iniFile);
		WritePrivateProfileString("Captions", "Anonymize", std::to_string(gAnonymize), iniFile);
		WritePrivateProfileString("Captions", "AnonymizeFlag", std::to_string(gAnonymizeFlag), iniFile);
	}

	GetPrivateProfileString("Captions", "AnonCaption", gszAnonCaption, gszAnonCaption, MAX_STRING, iniFile);
	if (bWriteAllConfig) WritePrivateProfileString("Captions", "AnonCaption", gszAnonCaption, iniFile);

	ConvertCR(gszSpawnNPCName, MAX_STRING);
	ConvertCR(gszSpawnPlayerName[1], MAX_STRING);
	ConvertCR(gszSpawnPlayerName[2], MAX_STRING);
	ConvertCR(gszSpawnPlayerName[3], MAX_STRING);
	ConvertCR(gszSpawnPlayerName[4], MAX_STRING);
	ConvertCR(gszSpawnPlayerName[5], MAX_STRING);
	ConvertCR(gszSpawnPlayerName[6], MAX_STRING);
	ConvertCR(gszSpawnCorpseName, MAX_STRING);
	ConvertCR(gszSpawnPetName, MAX_STRING);
	ConvertCR(gszAnonCaption, MAX_STRING);

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
	if (bWriteAllConfig)
	{
		WritePrivateProfileString("SWho Filter", "Lastname", std::to_string(gFilterSWho.Lastname), iniFile);
		WritePrivateProfileString("SWho Filter", "Class", std::to_string(gFilterSWho.Class), iniFile);
		WritePrivateProfileString("SWho Filter", "Race", std::to_string(gFilterSWho.Race), iniFile);
		WritePrivateProfileString("SWho Filter", "Level", std::to_string(gFilterSWho.Level), iniFile);
		WritePrivateProfileString("SWho Filter", "GM", std::to_string(gFilterSWho.GM), iniFile);
		WritePrivateProfileString("SWho Filter", "Guild", std::to_string(gFilterSWho.Guild), iniFile);
		WritePrivateProfileString("SWho Filter", "Sneak", std::to_string(gFilterSWho.Sneak), iniFile);
		WritePrivateProfileString("SWho Filter", "LD", std::to_string(gFilterSWho.LD), iniFile);
		WritePrivateProfileString("SWho Filter", "LFG", std::to_string(gFilterSWho.LFG), iniFile);
		WritePrivateProfileString("SWho Filter", "NPCTag", std::to_string(gFilterSWho.NPCTag), iniFile);
		WritePrivateProfileString("SWho Filter", "Trader", std::to_string(gFilterSWho.Trader), iniFile);
		WritePrivateProfileString("SWho Filter", "AFK", std::to_string(gFilterSWho.AFK), iniFile);
		WritePrivateProfileString("SWho Filter", "Anon", std::to_string(gFilterSWho.Anon), iniFile);
		WritePrivateProfileString("SWho Filter", "Distance", std::to_string(gFilterSWho.Distance), iniFile);
		WritePrivateProfileString("SWho Filter", "Light", std::to_string(gFilterSWho.Light), iniFile);
		WritePrivateProfileString("SWho Filter", "Body", std::to_string(gFilterSWho.Body), iniFile);
		WritePrivateProfileString("SWho Filter", "SpawnID", std::to_string(gFilterSWho.SpawnID), iniFile);
		WritePrivateProfileString("SWho Filter", "Holding", std::to_string(gFilterSWho.Holding), iniFile);
		WritePrivateProfileString("SWho Filter", "ConColor", std::to_string(gFilterSWho.ConColor), iniFile);
		WritePrivateProfileString("SWho Filter", "Invisible", std::to_string(gFilterSWho.Invisible), iniFile);
	}

	DefaultFilters();

	// TODO:  Add a function that gets map for a section?
	char FilterList[MAX_STRING * 10] = { 0 };
	GetPrivateProfileString("Filter Names", "", "", FilterList, MAX_STRING * 10, iniFile);

	char* pFilterList = FilterList;
	while (pFilterList[0] != 0)
	{
		GetPrivateProfileString("Filter Names", pFilterList, "", szBuffer, MAX_STRING, iniFile);

		if (szBuffer[0] != 0 && strcmp(szBuffer, "NOBODY"))
		{
			AddFilter(szBuffer, -1, gFilterCustom);
		}
		pFilterList += strlen(pFilterList) + 1;
	}

	const std::filesystem::path itemDBPath = std::filesystem::path(mq::internal_paths::Resources) / "ItemDB.txt";
	if (std::filesystem::exists(itemDBPath))
	{
		// Backwards compatibility prior to deprecation
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

void DoInitialization()
{
	// initialize main thread id
	dwMainThreadId = ::GetCurrentThreadId();

	InitializeMQ2Commands();
	InitializeMQ2Windows();

	MQ2MouseHooks(true);
	Sleep(100);

	InitializeMQ2KeyBinds();
	InitializeMQ2Plugins();
}

bool MQ2Initialize()
{
	MODULEINFO modinfo = { nullptr };
	HMODULE heagamemod = GetModuleHandle(nullptr);

	GetModuleInformation(GetCurrentProcess(), heagamemod, &modinfo, sizeof(MODULEINFO));
	g_eqgameimagesize = (DWORD)heagamemod + modinfo.SizeOfImage;

	if (GetModuleHandle("Lavish.dll") || GetModuleHandle("InnerSpace.dll"))
	{
		// I dont know why but if we dont sleep here for a while
		// we will crash but only if I have a detour on wwsCrashReportCheckForUploader
		// I suspect Lax would know more about this than me -eqmule
		HWND hEQWnd = nullptr;

		// we use this loop to just wait for wineq2 to get the eqwindow up and running before we move on
		// there is some kind of weird race condition going on... again lax would know more about this than I...
		while (hEQWnd == nullptr)
		{
			hEQWnd = GetEQWindowHandle();

			if (!hEQWnd)
			{
				Sleep(1000);
			}
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

	srand(static_cast<uint32_t>(time(nullptr)));
	ZeroMemory(gDiKeyName, sizeof(gDiKeyName));

	for (int i = 0; gDiKeyID[i].Id; i++)
	{
		gDiKeyName[gDiKeyID[i].Id] = gDiKeyID[i].szName;
	}

	ZeroMemory(szEQMappableCommands, sizeof(szEQMappableCommands));
	for (int i = 0; i < nEQMappableCommands; i++)
	{
		if ((DWORD)EQMappableCommandList[i] == 0 || (DWORD)EQMappableCommandList[i] > g_eqgameimagesize)
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
	szEQMappableCommands[nEQMappableCommands - 22] = "UNKNOWN0x208";//"Magic"
	szEQMappableCommands[nEQMappableCommands - 21] = "UNKNOWN0x209";//"Fire"
	szEQMappableCommands[nEQMappableCommands - 20] = "UNKNOWN0x20a";//"Cold"
	szEQMappableCommands[nEQMappableCommands - 19] = "UNKNOWN0x20b";//"Disease"
	szEQMappableCommands[nEQMappableCommands - 18] = "CHAT_SEMICOLON";//"Poison"
	szEQMappableCommands[nEQMappableCommands - 17] = "CHAT_SLASH";//"Physical"
	szEQMappableCommands[nEQMappableCommands - 16] = "INSTANT_CAMP";//"Corruption" confirmed 16 jul 2014 -eqmule
	szEQMappableCommands[nEQMappableCommands - 15] = "UNKNOWN0x20f";//"Unknown"
	szEQMappableCommands[nEQMappableCommands - 14] = "UNKNOWN0x210";//"Avatar"
	szEQMappableCommands[nEQMappableCommands - 13] = "UNKNOWN0x211";//"RemoveButton"
	szEQMappableCommands[nEQMappableCommands - 12] = "CHAT_EMPTY";//"ClearAll"
	szEQMappableCommands[nEQMappableCommands - 11] = "TOGGLE_WINDOWMODE";//"ClearTaskBecauseTaskNotFound" confirmed 16 jul 2014 -eqmule
	szEQMappableCommands[nEQMappableCommands - 10] = "UNKNOWN0x214";//"NoPlayersLeft"
	szEQMappableCommands[nEQMappableCommands - 9] = "UNKNOWN0x215";//"CreatedSharedTask"
	szEQMappableCommands[nEQMappableCommands - 8] = "CHANGEFACE";//"Complete" confirmed 16 jul 2014 -eqmule
	szEQMappableCommands[nEQMappableCommands - 7] = "UNKNOWN0x216";//Expired
	szEQMappableCommands[nEQMappableCommands - 6] = "UNKNOWN0x217";//Script
	szEQMappableCommands[nEQMappableCommands - 5] = "UNKNOWN0x219";//LeaderRemoved
	szEQMappableCommands[nEQMappableCommands - 4] = "UNKNOWN0x21a";
	szEQMappableCommands[nEQMappableCommands - 3] = "UNKNOWN0x21b";
	szEQMappableCommands[nEQMappableCommands - 2] = "UNKNOWN0x21c";
	szEQMappableCommands[nEQMappableCommands - 1] = "UNKNOWN0x21d";

	InitializeMQ2Detours();

	// from now on MQ2IC is not optional.
	LoadMQ2Plugin("mq2ic");

	if (ghmq2ic = GetModuleHandle("mq2ic.dll"))
		InitializeMQ2IcExports();

	InitializeMQ2Benchmarks();
	InitializeParser();
	InitializeDisplayHook();
	InitializeChatHook();
	InitializeMQ2Spawns();
	InitializeMQ2Pulse();

	// if we are precharselect we init here otherwise we init in HeartBeat
	DWORD gs = GetGameState();
	if (gs == GAMESTATE_PRECHARSELECT && !IsPluginsInitialized() && gbLoad)
	{
		OutputDebugString("I am loading in MQ2Initialize");

		DoInitialization();
		gbLoad = false;
	}
	else
	{
		// game isn't read. Wait for pulse to init instead.
		if (hLoadComplete)
		{
			WaitForSingleObject(hLoadComplete, 60000);
			Sleep(0);
		}
	}

	return true;
}

void MQ2Shutdown()
{
	OutputDebugString("MQ2Shutdown Called");

	DebugTry(ShutdownMQ2KeyBinds());
	DebugTry(ShutdownMQ2Spawns());
	DebugTry(ShutdownDisplayHook());
	DebugTry(ShutdownMQ2DInput());
	DebugTry(ShutdownChatHook());
	DebugTry(ShutdownMQ2Pulse());
	DebugTry(ShutdownMQ2Windows());
	DebugTry(MQ2MouseHooks(0));
	RemoveDetour(EQPlayer__SetNameSpriteState); // put here so it doesnt crash :)
	DebugTry(ShutdownParser());
	DebugTry(ShutdownMQ2Commands());
	DebugTry(ShutdownMQ2Plugins());
	DebugTry(DeInitializeMQ2IcExports());
	DebugTry(ShutdownMQ2Detours());
	DebugTry(ShutdownMQ2Benchmarks());
}

HMODULE GetCurrentModule()
{
	HMODULE hModule = nullptr;

	GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS
		| GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, (LPCTSTR)GetCurrentModule, &hModule);

	return hModule;
}

HANDLE hUnloadComplete = nullptr;
HANDLE hLoadComplete = nullptr;

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

LONG WINAPI OurCrashHandler(EXCEPTION_POINTERS* ex)
{
	MQ2ExceptionFilter(0, ex, "OurCrashHandler");
	int mbret = MessageBox(nullptr,
		"MQ2Start caught a crash.\n"
		"This does NOT mean it was a MQ2 crash, it could also be a eqgame crash.\n\n"
		"You can click retry and hope for the best, or just click cancel to kill the process right now.",
		"Crash Detected", MB_RETRYCANCEL | MB_DEFBUTTON1 | MB_ICONERROR | MB_SYSTEMMODAL);

	if (mbret == IDCANCEL)
	{
		exit(0);
	}

	return EXCEPTION_CONTINUE_EXECUTION;
}

// ***************************************************************************
// Function:    MQ2Start Thread
// Description: Where we start execution during the insertion
// ***************************************************************************
DWORD WINAPI MQ2Start(void* lpParameter)
{
	SetUnhandledExceptionFilter(OurCrashHandler);

	hUnloadComplete = CreateEvent(nullptr, TRUE, FALSE, nullptr);
	hLoadComplete = CreateEvent(nullptr, TRUE, FALSE, nullptr);

	char szBuffer[MAX_STRING] = { 0 };

	if (!MQ2Initialize())
	{
		MessageBox(nullptr, "Failed to Initialize MQ2 will free lib and exit", "MQ2 Error", MB_OK);

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
	if (hLoadComplete)
	{
		CloseHandle(hLoadComplete);
		hLoadComplete = 0;
	}

	if (hUnloadComplete)
	{
		DWORD dwtime = WaitForSingleObject(hUnloadComplete, 1800000); // 30 mins so i can debug stuff
		if (dwtime == WAIT_TIMEOUT)
		{
			OutputDebugString("I am unloading in MQ2Start due to TIMEOUT");
			ForceUnload();
		}

		CloseHandle(hUnloadComplete);
		hUnloadComplete = nullptr;
	}
	else
	{
		OutputDebugString("I am unloading in MQ2Start this will probably crash");
		ForceUnload();
	}

	if (ScreenMode)
		ScreenMode = 2;

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

	return dwMainThreadId == ::GetCurrentProcessId();
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
