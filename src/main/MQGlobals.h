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

#include "MacroSystem.h"
#include "MQInternal.h"

#include "eqlib/EQLib.h"

#include <memory>
#include <unordered_map>


// Probably move these to eqlib but for now these are all contained within MQ
#if defined(EMULATOR)
#define HAS_CHAT_TIMESTAMPS 1
#else
#define HAS_CHAT_TIMESTAMPS 0
#endif

namespace mq {

MQLIB_VAR const double DegToRad;
MQLIB_VAR const double PI;

/* BENCHMARK HANDLES */

MQLIB_API uint32_t bmUpdateSpawnSort;
MQLIB_API uint32_t bmUpdateSpawnCaptions;
MQLIB_API uint32_t bmCalculate;
MQLIB_API uint32_t bmRenderScene;

/**
 * Controls the macro system's command execution. Whenever a macro executes a command, this will be
 * set to false. If the command sets this back to true, the macro system will continuing executing
 * commands. This gives commands a frame to perform any side effects by default. If a command has no
 * side effects, it can set this to true to keep the macro running for that frame.
 */
MQLIB_VAR bool bRunNextCommand;

/**
 * Blocks the macro system while a turn animation is active.
 */
MQLIB_VAR bool TurnNotDone;


MQLIB_API char gszVersion[32];
MQLIB_API char gszTime[32];
MQLIB_API int gBuild;

MQLIB_VAR DWORD ThreadID;

MQLIB_VAR bool gbWriteAllConfig;

MQLIB_VAR HMODULE ghModule;
MQLIB_VAR HINSTANCE ghInstance;
MQLIB_VAR HWND ghInjectorWnd;
MQLIB_VAR bool gbUnload;
MQLIB_VAR bool gbForceUnload;

MQLIB_VAR double gZFilter;
MQLIB_VAR double gFaceAngle;
MQLIB_VAR double gLookAngle;

MQLIB_VAR char gszEQPath[MAX_STRING] DEPRECATE("Use gPathEverQuest in Plugins.  Except for WIN_API calls your relative path from the working directory is already the EQ Path.");
MQLIB_VAR char gszMacroPath[MAX_STRING] DEPRECATE("Use gPathMacros in Plugins");
MQLIB_VAR char gszLogPath[MAX_STRING] DEPRECATE("Use gPathLogs in Plugins");
MQLIB_VAR char gszINIPath[MAX_STRING] DEPRECATE("Use gPathMQRoot in Plugins - or one of the gPathResources/gPathConfig/gPathPlugins paths");
MQLIB_VAR char gszINIFilename[MAX_STRING] DEPRECATE("Use gPathMQini in Plugins");
MQLIB_VAR char gszItemDB[MAX_STRING] DEPRECATE("Use gResourcesPath / ItemDB.txt in Plugins");
MQLIB_VAR char gszMacroName[MAX_STRING];
MQLIB_VAR char szLastCommand[MAX_STRING];

enum eFilterMacro
{
	FILTERMACRO_ALL = 0,
	FILTERMACRO_ENHANCED = 1,
	FILTERMACRO_NONE = 2,
	FILTERMACRO_MACROENDED = 3,

	FILTERMACRO_MAX,
};
MQLIB_VAR eFilterMacro gFilterMacro;

MQLIB_VAR char gUISkin[MAX_PATH];

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
	extern std::string EverQuest;
}; // namespace internal_paths
MQLIB_VAR char gPathMQRoot[MAX_PATH];
MQLIB_VAR char gPathConfig[MAX_PATH];
MQLIB_VAR char gPathMQini[MAX_PATH];
MQLIB_VAR char gPathMacros[MAX_PATH];
MQLIB_VAR char gPathLogs[MAX_PATH];
MQLIB_VAR char gPathCrashDumps[MAX_PATH];
MQLIB_VAR char gPathPlugins[MAX_PATH];
MQLIB_VAR char gPathResources[MAX_PATH];
MQLIB_VAR char gPathEverQuest[MAX_PATH];

MQLIB_VAR bool gbMoving;

MQLIB_VAR bool gTargetbuffs;
MQLIB_VAR bool gItemsReceived;
MQLIB_VAR bool gbInZone;
MQLIB_VAR bool gZoning;
MQLIB_VAR uint64_t OldLastEnteredZone;
MQLIB_VAR uint64_t LastEnteredZone;
MQLIB_VAR bool gFilterSkillsAll;
MQLIB_VAR bool gFilterSkillsIncrease;
MQLIB_VAR bool gFilterTarget;
MQLIB_VAR bool gFilterDebug;
MQLIB_VAR bool gFilterMoney;
MQLIB_VAR bool gFilterFood;
MQLIB_VAR bool gFilterMQ;
MQLIB_VAR bool gFilterEncumber;
MQLIB_VAR bool gFilterCustom;
MQLIB_VAR bool gFilterMQ2DataErrors;
MQLIB_VAR bool gSpewToFile;
MQLIB_VAR bool gLClickedObject;
MQLIB_VAR MQWhoFilter gFilterSWho;
MQLIB_VAR bool gUseNewNamedTest;
MQLIB_VAR bool gbInForeground;

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

MQLIB_VAR Property<MQGroundObject> GroundObject DEPRECATE("Use CurrentGroundSpawn() and the various GetGroundSpawnByX() functions instead");
MQLIB_VAR Property<eqlib::EQGroundItem*> pGroundTarget DEPRECATE("Use CurrentGroundSpawn() and the various GetGroundSpawnByX() functions instead");
MQLIB_VAR eqlib::EQSwitch* pDoorTarget DEPRECATE("Use pSwitchTarget instead of pDoorTarget");
MQLIB_VAR eqlib::EQSwitch* pSwitchTarget;
MQLIB_VAR ITEMDB* gItemDB;

MQLIB_VAR MQFilter* gpFilters;

// TODO: Change to use case insensitive comparison
MQLIB_VAR std::map<std::string, uint32_t> ItemSlotMap;

MQLIB_VAR int gGameState;
MQLIB_VAR bool gbExactSearchCleanNames;

MQLIB_VAR bool gMouseClickInProgress[8];

// ***************************************************************************
// String arrays
// ***************************************************************************

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
MQLIB_VAR const char* szZoneExpansionName[];

MQLIB_API const char* GetZoneExpansionName(int expansion);
MQLIB_API const char* GetHighestExpansionOwnedName(eqlib::EQExpansionOwned expansionOwned);
MQLIB_API uint32_t GetExpansionNumber(std::string_view expansionName);

MQLIB_VAR const char* szWornLoc[];

MQLIB_VAR fEQCommand cmdHelp;
MQLIB_VAR fEQCommand cmdWho;
MQLIB_VAR fEQCommand cmdWhoTarget;
MQLIB_VAR fEQCommand cmdLocation;
MQLIB_VAR fEQCommand cmdFace;
MQLIB_VAR fEQCommand cmdTarget;
MQLIB_VAR fEQCommand cmdCharInfo;
MQLIB_VAR fEQCommand cmdFilter;
MQLIB_VAR fEQCommand cmdDoAbility;
MQLIB_VAR fEQCommand cmdCast;
MQLIB_VAR fEQCommand cmdUseItem;
MQLIB_VAR fEQCommand cmdHotbutton;
MQLIB_VAR fEQCommand cmdTaskQuit;
MQLIB_VAR fEQCommand cmdPet;
MQLIB_VAR fEQCommand cmdMercSwitch;
MQLIB_VAR fEQCommand cmdAdvLoot;
MQLIB_VAR fEQCommand cmdPickZone;
MQLIB_VAR fEQCommand cmdAssist;
MQLIB_VAR fEQCommand cmdQuit;

using fEQGetMelee = float(*)(eqlib::PlayerClient*, eqlib::PlayerClient*);
MQLIB_VAR fEQGetMelee get_melee_range;

MQLIB_VAR bool ExecuteCmd(unsigned int command, bool keydown = false, void* data = nullptr);
MQLIB_VAR const char* szDmgBonusType[];
MQLIB_VAR const char* szBodyType[];
MQLIB_VAR const char* szAugRestrictions[];
MQLIB_VAR const char* szItemSlot[eqlib::InvSlot_Max + 1];
MQLIB_VAR const char* szEquipmentSlot[];

MQLIB_VAR MQPlugin* pPlugins;

// Prefer using gSpawnArray over these for internal usage
MQLIB_VAR MQRank* EQP_DistArray;
MQLIB_VAR int gSpawnCount;

// internal to mq2 only
extern std::vector<MQSpawnArrayItem> gSpawnsArray;
#if HAS_CHAT_TIMESTAMPS
extern bool gbTimeStampChat;
#endif

MQLIB_VAR bool gUseTradeOnTarget;
MQLIB_VAR bool gbShowCurrentCamera;
MQLIB_VAR bool gbIgnoreAlertRecursion;

/* DEPRECATION GLOBALS */
MQLIB_VAR int gbGroundDeprecateCount;

} // namespace mq

#if __has_include("../private/MQ2Globals-private.h")
#include "../private/MQ2Globals-private.h"
#endif
#if __has_include("../private/MQGlobals-private.h")
#include "../private/MQGlobals-private.h"
#endif
