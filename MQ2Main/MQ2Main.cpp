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

#include "MQ2Main.h"

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

//============================================================================

DWORD WINAPI MQ2Start(void* lpParameter);
HANDLE hMQ2StartThread = nullptr;
DWORD dwMainThreadId = 0;

BOOL APIENTRY DllMain(HANDLE hModule, DWORD ul_reason_for_call, void* lpReserved)
{
	char szFilename[MAX_STRING] = { 0 };
	char* szProcessName;
	ghModule = (HMODULE)hModule;
	ghInstance = (HINSTANCE)hModule;
	ghInjectorWnd = FindWindowA(MacroQuestWinClassName, MacroQuestWinName);

	GetModuleFileName(ghModule, szFilename, MAX_STRING);
	szProcessName = strrchr(szFilename, '\\');
	szProcessName[0] = '\0';
	strcat_s(szFilename, "\\eqgame.ini");

	GetModuleFileName(nullptr, szFilename, MAX_STRING);

	szProcessName = strrchr(szFilename, '.');
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
			g_Loaded = true;

			hMQ2StartThread = CreateThread(nullptr, 0, MQ2Start, _strdup(szFilename), 0, &ThreadID);
		}
		else if (ul_reason_for_call == DLL_PROCESS_DETACH)
		{
			gbUnload = true;

			if (hMQ2StartThread)
			{
				int dwtime = WaitForSingleObject(hMQ2StartThread, 1000);
				if (dwtime == WAIT_TIMEOUT)
				{
					Sleep(0);
				}
				CloseHandle(hMQ2StartThread);
			}

			return TRUE;
		}
	}

	if (szProcessName[0] != '\0' && !_stricmp(szProcessName, "LaunchPad"))
	{
		if (ul_reason_for_call == DLL_PROCESS_ATTACH)
		{
			exit(-1);
		}
	}

	return TRUE;
}

// ***************************************************************************
// Function:    ParseINIFile
// Description: Parse INI file for memory locations
// ***************************************************************************
bool ParseINIFile(const char* lpINIPath)
{
	char Filename[MAX_STRING] = { 0 };
	char MQChatSettings[MAX_STRING] = { 0 };
	char CustomSettings[MAX_STRING] = { 0 };
	char ClientINI[MAX_STRING] = { 0 };
	char szBuffer[MAX_STRING] = { 0 };
	char szBuffer2[MAX_STRING] = { 0 };
	char ClientName[MAX_STRING] = { 0 };
	char FilterList[MAX_STRING * 10] = { 0 };
	char Delimiter[MAX_STRING] = { 0 };

	GetEQPath(gszEQPath, MAX_STRING);
	DWORD StackingDebug = 0;

	sprintf_s(Filename, "%s\\MacroQuest.ini", lpINIPath);
	sprintf_s(ClientINI, "%s\\eqgame.ini", lpINIPath);
	strcpy_s(gszINIFilename, Filename);

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

	// this is a new addition to core, if they dont have it, I want them to at least see it
	// from that point on they can chose to unload it.
	int defval = GetPrivateProfileInt("Plugins", "MQ2TargetInfo", -1, Filename);
	if (defval == -1)
	{
		WritePrivateProfileString("Plugins", "MQ2TargetInfo", "1", Filename);
	}

	int ic = GetPrivateProfileInt("Plugins", "MQ2Ic", 1, Filename);
	if (ic == 0)
	{
		// its set to 0 thats not good
		WritePrivateProfileString("Plugins", "MQ2Ic", "1", Filename);
	}

	gFilterSkillsAll         = 0 != GetPrivateProfileInt("MacroQuest", "FilterSkills", 0, Filename);
	gFilterSkillsIncrease    = 2 == GetPrivateProfileInt("MacroQuest", "FilterSkills", 0, Filename);
	gFilterDebug             = 1 == GetPrivateProfileInt("MacroQuest", "FilterDebug", 0, Filename);
	gFilterMQ2DataErrors     = 1 == GetPrivateProfileInt("MacroQuest", "FilterMQ2Data", 0, Filename);
	gFilterTarget            = 1 == GetPrivateProfileInt("MacroQuest", "FilterTarget", 0, Filename);
	gFilterMoney             = 1 == GetPrivateProfileInt("MacroQuest", "FilterMoney", 0, Filename);
	gFilterFood              = 1 == GetPrivateProfileInt("MacroQuest", "FilterFood", 0, Filename);
	gFilterMacro             =      GetPrivateProfileInt("MacroQuest", "FilterMacro", 0, Filename);
	gFilterEncumber          = 1 == GetPrivateProfileInt("MacroQuest", "FilterEncumber", 0, Filename);
	gFilterCustom            = 1 == GetPrivateProfileInt("MacroQuest", "FilterCustom", 1, Filename);
	gSpewToFile              = 1 == GetPrivateProfileInt("MacroQuest", "DebugSpewToFile", 0, Filename);
	gMQPauseOnChat           = 1 == GetPrivateProfileInt("MacroQuest", "MQPauseOnChat", 0, Filename);
	gKeepKeys                = 1 == GetPrivateProfileInt("MacroQuest", "KeepKeys", 0, Filename);
	bAllErrorsDumpStack      = 1 == GetPrivateProfileInt("MacroQuest", "AllErrorsDumpStack", 1, Filename);
	bAllErrorsFatal          = 1 == GetPrivateProfileInt("MacroQuest", "AllErrorsFatal", 0, Filename);
	gbMQ2LoadingMsg          = 1 == GetPrivateProfileInt("MacroQuest", "MQ2LoadingMsg", 1, Filename);
	gbExactSearchCleanNames  = 1 == GetPrivateProfileInt("MacroQuest", "ExactSearchCleanNames", 0, Filename);
	gbTimeStampChat          = 1 == GetPrivateProfileInt("MacroQuest", "TimeStampChat", 1, Filename);
	gUseTradeOnTarget        = 1 == GetPrivateProfileInt("MacroQuest", "UseTradeOnTarget", 1, Filename);
	gbBeepOnTells            = 1 == GetPrivateProfileInt("MacroQuest", "BeepOnTells", 1, Filename);
	gbFlashOnTells           = 1 == GetPrivateProfileInt("MacroQuest", "FlashOnTells", 1, Filename);
	gbIgnoreAlertRecursion   = 1 == GetPrivateProfileInt("MacroQuest", "IgnoreAlertRecursion", 0, Filename);
	gbShowCurrentCamera      = 1 == GetPrivateProfileInt("MacroQuest", "ShowCurrentCamera", 1, Filename);
	gTurboLimit              =      GetPrivateProfileInt("MacroQuest", "TurboLimit", 240, Filename);
	gCreateMQ2NewsWindow     = 1 == GetPrivateProfileInt("MacroQuest", "CreateMQ2NewsWindow", 1, Filename);
	gNetStatusXPos           =      GetPrivateProfileInt("MacroQuest", "NetStatusXPos", 0, Filename);
	gNetStatusYPos           =      GetPrivateProfileInt("MacroQuest", "NetStatusYPos", 0, Filename);
	StackingDebug            =      GetPrivateProfileInt("MacroQuest", "BuffStackTestDebug", 0, Filename); gStackingDebug = (StackingDebug == 2 ? -1 : StackingDebug);
	gUseNewNamedTest         = 1 == GetPrivateProfileInt("MacroQuest", "UseNewNamedTest", 0, Filename);
	gdwParserEngineVer       =      GetPrivateProfileInt("MacroQuest", ("Parser" + ENGINE_SWITCH_CMD).c_str(), 1, Filename);

	GetPrivateProfileString("Macroquest", "IfDelimiter", ",", Delimiter, MAX_STRING, Filename); gIfDelimiter = Delimiter[0];
	GetPrivateProfileString("Macroquest", "IfAltDelimiter", "~", Delimiter, MAX_STRING, Filename); gIfAltDelimiter = Delimiter[0];
	GetPrivateProfileString("MacroQuest", "HUDMode", "UnderUI", CustomSettings, MAX_STRING, Filename);

	if (!_stricmp(CustomSettings, "normal"))
	{
		gbAlwaysDrawMQHUD = false;
		gbHUDUnderUI = false;
	}
	else
	{
		if (!_stricmp(CustomSettings, "underui"))
		{
			gbHUDUnderUI = true;
			gbAlwaysDrawMQHUD = false;
		}
		else if (!_stricmp(CustomSettings, "always"))
		{
			gbHUDUnderUI = true;
			gbAlwaysDrawMQHUD = true;
		}
	}

	GetPrivateProfileString("Captions", "NPC", gszSpawnNPCName, gszSpawnNPCName, MAX_STRING, Filename);
	GetPrivateProfileString("Captions", "Player1", gszSpawnPlayerName[1], gszSpawnPlayerName[1], MAX_STRING, Filename);
	GetPrivateProfileString("Captions", "Player2", gszSpawnPlayerName[2], gszSpawnPlayerName[2], MAX_STRING, Filename);
	GetPrivateProfileString("Captions", "Player3", gszSpawnPlayerName[3], gszSpawnPlayerName[3], MAX_STRING, Filename);
	GetPrivateProfileString("Captions", "Player4", gszSpawnPlayerName[4], gszSpawnPlayerName[4], MAX_STRING, Filename);
	GetPrivateProfileString("Captions", "Player5", gszSpawnPlayerName[5], gszSpawnPlayerName[5], MAX_STRING, Filename);
	GetPrivateProfileString("Captions", "Player6", gszSpawnPlayerName[6], gszSpawnPlayerName[6], MAX_STRING, Filename);
	GetPrivateProfileString("Captions", "Corpse", gszSpawnCorpseName, gszSpawnCorpseName, MAX_STRING, Filename);
	GetPrivateProfileString("Captions", "Pet", gszSpawnPetName, gszSpawnPetName, MAX_STRING, Filename);

	gMaxSpawnCaptions        =      GetPrivateProfileInt("Captions", "Update", gMaxSpawnCaptions, Filename);
	gMQCaptions              = 1 == GetPrivateProfileInt("Captions", "MQCaptions", 1, Filename);
	gAnonymize               = 1 == GetPrivateProfileInt("Captions", "Anonymize", 0, Filename);
	gAnonymizeFlag           =      GetPrivateProfileInt("Captions", "AnonymizeFlag", -1, Filename);

	if (gAnonymizeFlag == -1)
	{
		WritePrivateProfileString("Captions", "AnonymizeFlag", "0", Filename);
		gAnonymizeFlag = 0;
	}

	GetPrivateProfileString("Captions", "AnonCaption", "", gszAnonCaption, MAX_STRING, Filename);
	if (gszAnonCaption[0] == '\0')
	{
		WritePrivateProfileString("Captions", "AnonCaption", "[${NamingSpawn.Level}] ${NamingSpawn.Race} ${NamingSpawn.Class} ${NamingSpawn.Type}", Filename);
	}

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

	gFilterSWho.Lastname        = GetPrivateProfileInt("SWho Filter", "Lastname", 1, Filename);
	gFilterSWho.Class           = GetPrivateProfileInt("SWho Filter", "Class", 1, Filename);
	gFilterSWho.Race            = GetPrivateProfileInt("SWho Filter", "Race", 1, Filename);
	gFilterSWho.Level           = GetPrivateProfileInt("SWho Filter", "Level", 1, Filename);
	gFilterSWho.GM              = GetPrivateProfileInt("SWho Filter", "GM", 1, Filename);
	gFilterSWho.Guild           = GetPrivateProfileInt("SWho Filter", "Guild", 1, Filename);
	gFilterSWho.Sneak           = GetPrivateProfileInt("SWho Filter", "Sneak", 1, Filename);
	gFilterSWho.LD              = GetPrivateProfileInt("SWho Filter", "LD", 1, Filename);
	gFilterSWho.LFG             = GetPrivateProfileInt("SWho Filter", "LFG", 1, Filename);
	gFilterSWho.NPCTag          = GetPrivateProfileInt("SWho Filter", "NPCTag", 1, Filename);
	gFilterSWho.Trader          = GetPrivateProfileInt("SWho Filter", "Trader", 1, Filename);
	gFilterSWho.AFK             = GetPrivateProfileInt("SWho Filter", "AFK", 1, Filename);
	gFilterSWho.Anon            = GetPrivateProfileInt("SWho Filter", "Anon", 1, Filename);
	gFilterSWho.Distance        = GetPrivateProfileInt("SWho Filter", "Distance", 1, Filename);
	gFilterSWho.Light           = GetPrivateProfileInt("SWho Filter", "Light", 0, Filename);
	gFilterSWho.Body            = GetPrivateProfileInt("SWho Filter", "Body", 0, Filename);
	gFilterSWho.SpawnID         = GetPrivateProfileInt("SWho Filter", "SpawnID", 0, Filename);
	gFilterSWho.Holding         = GetPrivateProfileInt("SWho Filter", "Holding", 0, Filename);
	gFilterSWho.ConColor        = GetPrivateProfileInt("SWho Filter", "ConColor", 0, Filename);
	gFilterSWho.Invisible       = GetPrivateProfileInt("SWho Filter", "Invisible", 0, Filename);

	GetPrivateProfileString("MacroQuest", "MacroPath", ".", szBuffer, MAX_STRING, Filename);

	if (szBuffer[0] == '.')
	{
		sprintf_s(gszMacroPath, "%s%s", lpINIPath, szBuffer + 1);
	}
	else
	{
		strcat_s(gszMacroPath, szBuffer);
	}

	GetPrivateProfileString("MacroQuest", "LogPath", ".", szBuffer, MAX_STRING, Filename);

	if (szBuffer[0] == '.')
	{
		sprintf_s(gszLogPath, "%s%s", lpINIPath, szBuffer + 1);
	}
	else
	{
		strcat_s(gszLogPath, szBuffer);
	}

	DefaultFilters();

	GetPrivateProfileString("Filter Names", nullptr, "", FilterList, MAX_STRING * 10, Filename);

	char* pFilterList = FilterList;
	while (pFilterList[0] != 0)
	{
		GetPrivateProfileString("Filter Names", pFilterList, "", szBuffer, MAX_STRING, Filename);

		if (szBuffer[0] != 0 && strcmp(szBuffer, "NOBODY"))
		{
			AddFilter(szBuffer, -1, gFilterCustom);
		}
		pFilterList += strlen(pFilterList) + 1;
	}

	sprintf_s(Filename, "%s\\ItemDB.txt", lpINIPath);
	FILE* fDB = nullptr;
	errno_t err = fopen_s(&fDB, Filename, "rt");
	strcpy_s(gszItemDB, Filename);
	char* pDest = nullptr;

	if (!err)
	{
		fgets(szBuffer, MAX_STRING, fDB);
		while ((!feof(fDB)) && (strstr(szBuffer, "\t")))
		{
			if (ITEMDB* Item = new ITEMDB())
			{
				Item->pNext = gItemDB;
				Item->ID = atoi(szBuffer);

				if (pDest = (strstr(szBuffer, "\t") + 1))
				{
					strcpy_s(szBuffer2, pDest);
					Item->StackSize = atoi(szBuffer2);

					if (pDest = strstr(szBuffer2, "\t"))
					{
						strcpy_s(Item->szName, pDest + 1);
						Item->szName[strstr(Item->szName, "\n") - Item->szName] = 0;
						gItemDB = Item;
						fgets(szBuffer, MAX_STRING, fDB);
					}
					else
					{
						sprintf_s(szBuffer, "Your file: %s is old.\nPlease replace it with the one from the latest zip", Filename);
						MessageBox(nullptr, szBuffer, "ItemDB.txt version mismatch", MB_OK);
						exit(0);
					}
				}
			}
		}

		fclose(fDB);
	}

	if (!gSpewToFile)
	{
		// lets check if the user has it set in his/her custom ini
		sprintf_s(Filename, "%s\\CustomPlugin.ini", lpINIPath);
		gSpewToFile = 1 == GetPrivateProfileInt("MacroQuest", "DebugSpewToFile", 0, Filename);
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

	if (!InitOffsets())
	{
		DebugSpewAlways("InitOffsets returned false - thread aborted.");
		g_Loaded = false;
		return false;
	}

	eqlib::InitializeEQLib();

	if (!ParseINIFile(gszINIPath))
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

	// from now on MQ2IC is not optional.
	LoadMQ2Plugin("mq2ic");

	if (ghmq2ic = GetModuleHandle("mq2ic.dll"))
		InitializeMQ2IcExports();

	InitializeMQ2Benchmarks();
	InitializeParser();
	InitializeMQ2Detours();
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

	char* lpINIPath = (char*)lpParameter;
	strcpy_s(gszINIPath, lpINIPath);
	free(lpINIPath);

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

	if (gGameState == GAMESTATE_INGAME || gGameState == GAMESTATE_CHARSELECT || gGameState == GAMESTATE_CHARCREATE)
	{
		gbInZone = true;
		PluginsSetGameState(gGameState);
	}

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

void InsertMQ2News()
{
	if (!pNewsWindow)
		return;

	char Filename[MAX_PATH] = { 0 };
	sprintf_s(Filename, "%s\\changes.txt", gszINIPath);

	FILE* file = nullptr;
	errno_t err = fopen_s(&file, Filename, "rb");
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
			if (atoi(Cmd))
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
	char Filename[MAX_STRING] = { 0 };
	sprintf_s(Filename, "%s\\changes.txt", gszINIPath);

	if (!pNewsWindow && _FileExists(Filename))
	{
		pNewsWindow = new CMQNewsWnd();
	}

	InsertMQ2News();
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

//============================================================================

/* OTHER FUNCTIONS IMPORTED FROM EQ */
#ifdef __CastRay_x
FUNCTION_AT_ADDRESS(int CastRay(SPAWNINFO*, float y, float x, float z), __CastRay);
#endif
#ifdef __CastRay2_x
FUNCTION_AT_ADDRESS(int CastRayLoc(const CVector3& SourcePos, int Race, float DestX, float DestY, float DestZ), __CastRay2);
#endif
#ifdef __CleanItemTags_x
FUNCTION_AT_ADDRESS(CXStr CleanItemTags(const CXStr& In, bool bFlag), __CleanItemTags);
#endif
#ifdef __HeadingDiff_x
FUNCTION_AT_ADDRESS(float HeadingDiff(float h1, float h2, float* DiffOut), __HeadingDiff);
#endif
#ifdef __FixHeading_x
FUNCTION_AT_ADDRESS(float FixHeading(float Heading), __FixHeading);
#endif
#ifdef __get_bearing_x
FUNCTION_AT_ADDRESS(float get_bearing(float x1, float y1, float x2, float y2), __get_bearing)
#endif
#ifdef Util__FastTime_x
FUNCTION_AT_ADDRESS(unsigned long  GetFastTime(), Util__FastTime);
#endif
#ifdef __GetXTargetType_x
FUNCTION_AT_ADDRESS(const char* __stdcall GetXtargetType(DWORD type), __GetXTargetType);
#endif
#ifdef __EQGetTime_x
FUNCTION_AT_ADDRESS(DWORD EQGetTime(), __EQGetTime);
#endif
#ifdef __msg_successful_hit_x
FUNCTION_AT_ADDRESS(void msg_successful_hit(struct _EQSuccessfulHit*), __msg_successful_hit);
#endif
#ifdef __STMLToText_x
FUNCTION_AT_ADDRESS(CXStr STMLToText(const CXStr&, bool), __STMLToText);
#endif
#ifdef __GetAnimationCache_x
FUNCTION_AT_ADDRESS(IconCache* GetAnimationCache(int index), __GetAnimationCache);
#endif
#ifdef __SaveColors_x
FUNCTION_AT_ADDRESS(void SaveColors(int, int, int, int), __SaveColors);
#endif
