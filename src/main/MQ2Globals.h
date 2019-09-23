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

namespace mq {

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

/* OTHER */

MQLIB_VAR MQDataVar* pGlobalVariables;
MQLIB_VAR MQDataVar* pMacroVariables;

MQLIB_VAR BOOL bAllErrorsFatal;
MQLIB_VAR bool bAllErrorsDumpStack;
MQLIB_VAR BOOL bAllErrorsLog;
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

MQLIB_VAR BOOL gStringTableFixed;
MQLIB_VAR int gMaxSpawnCaptions;
MQLIB_VAR BOOL gMQCaptions;
MQLIB_VAR BOOL gAnonymize;

enum EAnonFlags
{
	EAF_None,
	EAF_Class,
};

MQLIB_VAR DWORD gAnonymizeFlag;
MQLIB_VAR HMODULE ghModule;
MQLIB_VAR HINSTANCE ghInstance;
MQLIB_VAR HWND ghInjectorWnd;
MQLIB_VAR BOOL gbEQWLoaded;
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
MQLIB_VAR BOOL gInClick;
MQLIB_VAR double gZFilter;
MQLIB_VAR double gFaceAngle;
MQLIB_VAR double gLookAngle;
MQLIB_VAR bool gbSpelldbLoaded;
MQLIB_VAR char gszEQPath[MAX_STRING];
MQLIB_VAR char gszMacroPath[MAX_STRING];
MQLIB_VAR char gszLogPath[MAX_STRING];
MQLIB_VAR char gszINIPath[MAX_STRING];
MQLIB_VAR char gszINIFilename[MAX_STRING];
MQLIB_VAR char gszItemDB[MAX_STRING];
MQLIB_VAR char gszMacroName[MAX_STRING];
MQLIB_VAR char szLastCommand[MAX_STRING];

MQLIB_VAR char gszLastNormalError[MAX_STRING];// QUIT USING THIS DIRECTLY, USE MacroError, FatalError, ETC
MQLIB_VAR char gszLastSyntaxError[MAX_STRING];
MQLIB_VAR char gszLastMQ2DataError[MAX_STRING];

MQLIB_VAR SPAWNINFO* pNamingSpawn;
MQLIB_VAR char gszSpawnNPCName[MAX_STRING];
MQLIB_VAR char gszSpawnPlayerName[8][MAX_STRING];
MQLIB_VAR char gszSpawnPetName[MAX_STRING];
MQLIB_VAR char gszSpawnCorpseName[MAX_STRING];
MQLIB_VAR char gszAnonCaption[MAX_STRING];

MQLIB_VAR DWORD DrawHUDParams[4];

MQLIB_VAR DWORD gEventChat;
MQLIB_VAR ULONGLONG gRunning;
MQLIB_VAR BOOL gbMoving;
MQLIB_VAR DWORD gMaxTurbo;
MQLIB_VAR DWORD gTurboLimit;

MQLIB_VAR BOOL gReturn;

MQLIB_VAR DWORD gbAssistComplete;
MQLIB_VAR BOOL gTargetbuffs;
MQLIB_VAR BOOL gItemsReceived;
MQLIB_VAR bool gbInZone;
MQLIB_VAR bool gZoning;
MQLIB_VAR ULONGLONG OldLastEnteredZone;
MQLIB_VAR ULONGLONG LastEnteredZone;
MQLIB_VAR bool WereWeZoning;
MQLIB_VAR bool gbInChat;
MQLIB_VAR bool gFilterSkillsAll;
MQLIB_VAR bool gFilterSkillsIncrease;
MQLIB_VAR bool gFilterTarget;
MQLIB_VAR BOOL gFilterDebug;
MQLIB_VAR bool gFilterMoney;
MQLIB_VAR bool gFilterFood;
MQLIB_VAR BOOL gFilterMQ;
MQLIB_VAR BOOL gFilterMacro;
MQLIB_VAR bool gFilterEncumber;
MQLIB_VAR bool gFilterCustom;
MQLIB_VAR BOOL gSpewToFile;
MQLIB_VAR bool gbDoAutoRun;
MQLIB_VAR BOOL gMQPauseOnChat;
MQLIB_VAR BOOL gKeepKeys;
MQLIB_VAR bool gLClickedObject;
MQLIB_VAR MQWhoFilter gFilterSWho;
MQLIB_VAR BOOL gCreateMQ2NewsWindow;
MQLIB_VAR BOOL gUseNewNamedTest;
MQLIB_VAR BOOL gbInForeground;

MQLIB_VAR BOOL gbHUDUnderUI;
MQLIB_VAR BOOL gbAlwaysDrawMQHUD;

MQLIB_VAR BOOL gFilterMQ2DataErrors;

MQLIB_VAR char gIfDelimiter;
MQLIB_VAR char gIfAltDelimiter;

MQLIB_VAR DWORD gNetStatusXPos;
MQLIB_VAR DWORD gNetStatusYPos;

MQLIB_VAR LONG gStackingDebug;

MQLIB_VAR double DegToRad;
MQLIB_VAR double PI;

extern Blech* pMQ2Blech;
MQLIB_VAR char EventMsg[MAX_STRING];
MQLIB_VAR Blech* pEventBlech;
MQLIB_VAR MQEventList* pEventList;

MQLIB_VAR MQTimer* gTimer;
MQLIB_VAR LONG gDelay;
MQLIB_VAR char gDelayCondition[MAX_STRING];
MQLIB_VAR SPAWNINFO EnviroTarget;
MQLIB_VAR SPAWNINFO PetSpawn;
MQLIB_VAR SPAWNINFO MercenarySpawn;
MQLIB_VAR GROUNDOBJECT GroundObject;
MQLIB_VAR PGROUNDITEM pGroundTarget;
MQLIB_VAR SPAWNINFO DoorEnviroTarget;
MQLIB_VAR PDOOR pDoorTarget;
MQLIB_VAR PITEMDB gItemDB;
MQLIB_VAR bool bRunNextCommand;
MQLIB_VAR BOOL bAllowCommandParse;
MQLIB_VAR bool gTurbo;
MQLIB_VAR bool gWarning;
MQLIB_VAR MQDefine* pDefines;
MQLIB_VAR MQBindList* pBindList;
MQLIB_VAR MQFilter* gpFilters;

// TODO: Change to use case insensitive comparison
MQLIB_VAR std::map<std::string, uint32_t> ItemSlotMap;

MQLIB_VAR MOUSESPOOF* gMouseData;

MQLIB_VAR const char* gDiKeyName[256];

MQLIB_VAR DWORD gGameState;
MQLIB_VAR BOOL gbMQ2LoadingMsg;
MQLIB_VAR BOOL gbExactSearchCleanNames;


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
//MQLIB_VAR char* szItemName[];
//MQLIB_VAR char* szItemName4xx[];
//MQLIB_VAR char* szTheme[];
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

//MQLIB_VAR EQPlayer **ppEQP_IDArray;
MQLIB_VAR MQRank EQP_DistArray[3000];
MQLIB_VAR DWORD gSpawnCount;
//#define ppEQP_IDArray (*pppEQP_IDArray)

MQLIB_VAR bool gbTimeStampChat;
MQLIB_VAR size_t g_eqgameimagesize;

MQLIB_VAR BOOL gUseTradeOnTarget;
MQLIB_VAR bool gbBeepOnTells;
MQLIB_VAR bool gbFlashOnTells;
MQLIB_VAR bool gbShowCurrentCamera;
MQLIB_VAR int  oldcameratype;
MQLIB_VAR char CameraText[2048];
MQLIB_VAR BOOL gbIgnoreAlertRecursion;

const std::string PARSE_PARAM_BEG = "${Parse[";
const std::string PARSE_PARAM_END = "]}";

extern std::map<int, std::string> targetBuffSlotToCasterMap;
extern std::map<int, std::map<int, TargetBuff>> CachedBuffsMap;

MQLIB_VAR DWORD gdwParserEngineVer;

} // namespace mq
