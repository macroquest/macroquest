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

#pragma once

#include "../EQLib/EQLib.h"
#include "MQ2Internal.h"

#include <memory>
#include <unordered_map>

struct CaseInsensitiveLess
{
	bool operator()(const std::string& lhs, const std::string& rhs) const noexcept
	{
		return (::_stricmp(lhs.c_str(), rhs.c_str()) < 0);
	};
};

struct IDirect3DDevice9;

namespace mq {

MQLIB_VAR const double DegToRad;
MQLIB_VAR const double PI;

MQLIB_API DWORD baseAddress [[deprecated]];

bool InitOffsets();

/* BENCHMARK HANDLES */

MQLIB_API DWORD bmWriteChatColor;
MQLIB_API DWORD bmPluginsIncomingChat;
MQLIB_API DWORD bmPluginsPulse;
MQLIB_API DWORD bmPluginsOnZoned;
MQLIB_API DWORD bmPluginsCleanUI;
MQLIB_API DWORD bmPluginsReloadUI;
MQLIB_API DWORD bmPluginsDrawHUD;
MQLIB_API DWORD bmPluginsSetGameState;
MQLIB_API DWORD bmParseMacroParameter;
MQLIB_API DWORD bmUpdateSpawnSort;
MQLIB_API DWORD bmUpdateSpawnCaptions;
MQLIB_API DWORD bmCalculate;
MQLIB_API DWORD bmBeginZone;
MQLIB_API DWORD bmEndZone;
MQLIB_API DWORD bmPluginsUpdateImGui;
MQLIB_API DWORD bmSpellLoad;
MQLIB_API DWORD bmSpellAccess;

/* OTHER */

MQLIB_VAR MQDataVar* pGlobalVariables;
MQLIB_VAR MQDataVar* pMacroVariables;

MQLIB_VAR bool bAllErrorsFatal;
MQLIB_VAR bool bAllErrorsDumpStack;
MQLIB_VAR bool bAllErrorsLog;
MQLIB_API char DataTypeTemp[MAX_STRING];
MQLIB_API TargetBuff TargetBuffTemp;
MQLIB_API char gszVersion[32];
MQLIB_API char gszTime[32];
MQLIB_API int gBuild;
MQLIB_API bool g_bDoingModuleChecks;

MQLIB_API ePVPServer PVPServer;
MQLIB_API HANDLE ghInitializeSpellDbThread;

MQLIB_VAR bool g_Loaded;
MQLIB_VAR DWORD ThreadID;

MQLIB_VAR bool gStringTableFixed;
MQLIB_VAR bool gbWriteAllConfig;

enum EAnonFlags
{
	EAF_None,
	EAF_Class,
};
MQLIB_VAR EAnonFlags gAnonymizeFlag;
MQLIB_VAR bool gAnonymize;

MQLIB_VAR HMODULE ghModule;
MQLIB_VAR HINSTANCE ghInstance;
MQLIB_VAR HWND ghInjectorWnd;
MQLIB_VAR bool gbUnload;
MQLIB_VAR bool gBindInProgress;
MQLIB_VAR bool gbLoad;
MQLIB_VAR DWORD gpHook;
MQLIB_VAR HMODULE ghmq2ic;
MQLIB_VAR MQMacroBlockPtr gMacroBlock;
MQLIB_VAR int BlockIndex;
MQLIB_VAR MQMacroStack* gMacroStack;
MQLIB_VAR std::map<std::string, int, CaseInsensitiveLess> gMacroSubLookupMap;
MQLIB_VAR std::map<std::string, int> gUndeclaredVars;
MQLIB_VAR MQEventQueue* gEventQueue;
MQLIB_VAR int gEventFunc[NUM_EVENTS];
MQLIB_VAR UCHAR gLastFind;
MQLIB_VAR double gZFilter;
MQLIB_VAR double gFaceAngle;
MQLIB_VAR double gLookAngle;
MQLIB_VAR bool gbSpelldbLoaded;
MQLIB_VAR char gszEQPath[MAX_STRING] DEPRECATE("Your relative path from the working directory is already the EQ Path.");
MQLIB_VAR char gszMacroPath[MAX_STRING] DEPRECATE("Use internal_paths::Macros in Core or gPathMacros in Plugins");
MQLIB_VAR char gszLogPath[MAX_STRING] DEPRECATE("Use internal_paths::Logs in Core or gPathLogs in Plugins");
MQLIB_VAR char gszINIPath[MAX_STRING] DEPRECATE("Use internal_paths::MQRoot in Core or gPathMQRoot in Plugins - or one of the Resources/Config/Plugins paths");
MQLIB_VAR char gszINIFilename[MAX_STRING] DEPRECATE("Use internal_paths::MQini in Core or gPathMQini in Plugins");
MQLIB_VAR char gszItemDB[MAX_STRING] DEPRECATE("Use internal_paths::Resources / \"ItemDB.txt\" in Core or gResourcesPath / ItemDB.txt in Plugins");
MQLIB_VAR char gszMacroName[MAX_STRING];
MQLIB_VAR char szLastCommand[MAX_STRING];

// FIXME:  Convert this to a Global Object. Include setting of gPathX (and remove from Init).
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
MQLIB_VAR char gPathMQRoot[MAX_PATH];
MQLIB_VAR char gPathConfig[MAX_PATH];
MQLIB_VAR char gPathMQini[MAX_PATH];
MQLIB_VAR char gPathMacros[MAX_PATH];
MQLIB_VAR char gPathLogs[MAX_PATH];
MQLIB_VAR char gPathCrashDumps[MAX_PATH];
MQLIB_VAR char gPathPlugins[MAX_PATH];
MQLIB_VAR char gPathResources[MAX_PATH];

MQLIB_VAR char gszLastNormalError[MAX_STRING];// QUIT USING THIS DIRECTLY, USE MacroError, FatalError, ETC
MQLIB_VAR char gszLastSyntaxError[MAX_STRING];
MQLIB_VAR char gszLastMQ2DataError[MAX_STRING];

MQLIB_VAR DWORD DrawHUDParams[4];

MQLIB_VAR DWORD gEventChat;
MQLIB_VAR uint64_t gRunning;
MQLIB_VAR bool gbMoving;
MQLIB_VAR int gMaxTurbo;
MQLIB_VAR int gTurboLimit;

MQLIB_VAR bool gReturn;
MQLIB_VAR bool gTargetbuffs;
MQLIB_VAR bool gItemsReceived;
MQLIB_VAR bool gbInZone;
MQLIB_VAR bool gZoning;
MQLIB_VAR uint64_t OldLastEnteredZone;
MQLIB_VAR uint64_t LastEnteredZone;
MQLIB_VAR bool WereWeZoning;
MQLIB_VAR bool gbInChat;
MQLIB_VAR bool gFilterSkillsAll;
MQLIB_VAR bool gFilterSkillsIncrease;
MQLIB_VAR bool gFilterTarget;
MQLIB_VAR bool gFilterDebug;
MQLIB_VAR bool gFilterMoney;
MQLIB_VAR bool gFilterFood;
MQLIB_VAR bool gFilterMQ;
MQLIB_VAR eFilterMacro gFilterMacro;
MQLIB_VAR bool gFilterEncumber;
MQLIB_VAR bool gFilterCustom;
MQLIB_VAR bool gFilterMQ2DataErrors;
MQLIB_VAR bool gSpewToFile;
MQLIB_VAR bool gbDoAutoRun;
MQLIB_VAR bool gMQPauseOnChat;
MQLIB_VAR bool gKeepKeys;
MQLIB_VAR bool gLClickedObject;
MQLIB_VAR MQWhoFilter gFilterSWho;
MQLIB_VAR bool gCreateMQ2NewsWindow;
MQLIB_VAR bool gUseNewNamedTest;
MQLIB_VAR bool gbInForeground;

MQLIB_VAR bool gbHUDUnderUI;
MQLIB_VAR bool gbAlwaysDrawMQHUD;


MQLIB_VAR char gIfDelimiter;
MQLIB_VAR char gIfAltDelimiter;

MQLIB_VAR int gNetStatusXPos;
MQLIB_VAR int gNetStatusYPos;

enum eStackingDebug
{
	STACKINGDEBUG_OFF = 0,
	STACKINGDEBUG_ON = 1,
	STACKINGDEBUG_OUTPUT = 2,
};
MQLIB_VAR eStackingDebug gStackingDebug;

enum eAssistStage
{
	AS_None = 0,
	AS_AssistSent = 1,
	AS_AssistReceived = 2
};
MQLIB_VAR eAssistStage gbAssistComplete;

extern Blech* pMQ2Blech;
MQLIB_VAR char EventMsg[MAX_STRING];
MQLIB_VAR Blech* pEventBlech;
MQLIB_VAR MQEventList* pEventList;

MQLIB_VAR MQTimer* gTimer;
MQLIB_VAR int gDelay;
MQLIB_VAR char gDelayCondition[MAX_STRING];
MQLIB_VAR SPAWNINFO EnviroTarget;
MQLIB_VAR SPAWNINFO PetSpawn;
MQLIB_VAR SPAWNINFO MercenarySpawn;
MQLIB_VAR MQGroundObject GroundObject;
MQLIB_VAR GROUNDITEM* pGroundTarget;
MQLIB_VAR SPAWNINFO DoorEnviroTarget;
MQLIB_VAR PDOOR pDoorTarget;
MQLIB_VAR ITEMDB* gItemDB;
MQLIB_VAR bool bRunNextCommand;
MQLIB_VAR bool bAllowCommandParse;
MQLIB_VAR bool gTurbo;
MQLIB_VAR bool gWarning;
MQLIB_VAR MQDefine* pDefines;
MQLIB_VAR MQBindList* pBindList;
MQLIB_VAR MQFilter* gpFilters;

// TODO: Change to use case insensitive comparison
MQLIB_VAR std::map<std::string, uint32_t> ItemSlotMap;

MQLIB_VAR MOUSESPOOF* gMouseData;

MQLIB_VAR DWORD gGameState;
MQLIB_VAR bool gbMQ2LoadingMsg;
MQLIB_VAR bool gbExactSearchCleanNames;


MQLIB_VAR bool gMouseClickInProgress[8];
MQLIB_VAR bool bDetMouse;

// ***************************************************************************
// String arrays
// ***************************************************************************
MQLIB_VAR const char* szEQMappableCommands[nEQMappableCommands];

MQLIB_VAR const char* szHeading[];
MQLIB_VAR const char* szHeadingShort[];
MQLIB_VAR const char* szHeadingNormal[];
MQLIB_VAR const char* szHeadingNormalShort[];
MQLIB_VAR const char* szSize[];
MQLIB_VAR const char* szSpawnType[];
MQLIB_VAR const char* szGuildStatus[];
MQLIB_VAR const char* szGender[];
MQLIB_VAR const char* szDeityTeam[];
MQLIB_VAR const char* szLights[];
MQLIB_VAR BYTE LightBrightness[];
MQLIB_VAR const char* szSkills[];
MQLIB_VAR const char* szInnates[];

MQLIB_VAR const char* szWornLoc[];

MQLIB_VAR fEQCommand            cmdHelp;
MQLIB_VAR fEQCommand            cmdWho;
MQLIB_VAR fEQCommand            cmdWhoTarget;
MQLIB_VAR fEQCommand            cmdLocation;
MQLIB_VAR fEQCommand            cmdFace;
MQLIB_VAR fEQCommand            cmdTarget;
MQLIB_VAR fEQCommand            cmdCharInfo;
MQLIB_VAR fEQCommand            cmdFilter;
MQLIB_VAR fEQCommand            cmdDoAbility;
MQLIB_VAR fEQCommand            cmdCast;
MQLIB_VAR fEQCommand            cmdUseItem;
MQLIB_VAR fEQCommand            cmdHotbutton;
MQLIB_VAR fEQCommand            cmdPet;
MQLIB_VAR fEQCommand            cmdMercSwitch;
MQLIB_VAR fEQCommand            cmdAdvLoot;
MQLIB_VAR fEQCommand            cmdPickZone;
MQLIB_VAR fEQCommand            cmdAssist;
MQLIB_VAR fEQCommand            cmdQuit;

MQLIB_VAR fEQGetMelee           get_melee_range;

MQLIB_VAR fICGetHashData        IC_GetHashData;
MQLIB_VAR fICSetHashData        IC_SetHashData;
MQLIB_VAR fLoaderSetLoaded      IC_LoaderSetLoaded;
MQLIB_VAR fLoaderClearLoaded    IC_LoaderClearLoaded;
MQLIB_VAR fMQ2Unload            IC_MQ2Unload;
MQLIB_VAR fClassLvl             IC_ClassLvl;

MQLIB_VAR fEQW_GetDisplayWindow EQW_GetDisplayWindow;

MQLIB_VAR bool ExecuteCmd(unsigned int command, bool keydown = false, void* data = nullptr);
MQLIB_VAR bool IsResEffectSpell(int);
MQLIB_VAR const char* szDmgBonusType[];
MQLIB_VAR const char* szBodyType[];
MQLIB_VAR const char* szAugRestrictions[];
MQLIB_VAR const char* szItemSlot[];
MQLIB_VAR const char* szEquipmentSlot[];
MQLIB_VAR const char* szExpansions[];

MQLIB_VAR std::map<std::string, MQDataVar*> VariableMap;
MQLIB_VAR std::unordered_map<std::string, std::unique_ptr<MQDataItem>> MQ2DataMap;
MQLIB_VAR MQPlugin* pPlugins;

MQLIB_VAR std::map<std::string, SPAWNINFO*> SpawnByName;

MQLIB_VAR MQRank EQP_DistArray[3000];
MQLIB_VAR int gSpawnCount;

MQLIB_VAR size_t g_eqgameimagesize;

MQLIB_VAR bool gUseTradeOnTarget;
MQLIB_VAR bool gbBeepOnTells;
MQLIB_VAR bool gbFlashOnTells;
MQLIB_VAR bool gbShowCurrentCamera;
MQLIB_VAR int  gOldCameraType;
MQLIB_VAR bool gbIgnoreAlertRecursion;

const std::string PARSE_PARAM_BEG = "${Parse[";
const std::string PARSE_PARAM_END = "]}";

extern std::map<int, std::string> targetBuffSlotToCasterMap;
extern std::map<int, std::map<int, TargetBuff>> CachedBuffsMap;

MQLIB_VAR int gParserVersion;

/* OVERLAY GLOBALS */
MQLIB_VAR IDirect3DDevice9* gpD3D9Device;
MQLIB_VAR bool gbDeviceAcquired;
MQLIB_VAR bool gbDeviceHooksInstalled;

} // namespace mq
