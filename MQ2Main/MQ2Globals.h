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

#include "EQLib/EQLib.h"

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

namespace MQ2Globals {

	EQLIB_API DWORD baseAddress [[deprecated]];

bool InitOffsets();

/* BENCHMARK HANDLES */

EQLIB_API DWORD bmWriteChatColor;
EQLIB_API DWORD bmPluginsIncomingChat;
EQLIB_API DWORD bmPluginsPulse;
EQLIB_API DWORD bmPluginsOnZoned;
EQLIB_API DWORD bmPluginsCleanUI;
EQLIB_API DWORD bmPluginsReloadUI;
EQLIB_API DWORD bmPluginsDrawHUD;
EQLIB_API DWORD bmPluginsSetGameState;
EQLIB_API DWORD bmParseMacroParameter;
EQLIB_API DWORD bmUpdateSpawnSort;
EQLIB_API DWORD bmUpdateSpawnCaptions;
EQLIB_API DWORD bmCalculate;
EQLIB_API DWORD bmBeginZone;
EQLIB_API DWORD bmEndZone;

/* OTHER */

EQLIB_VAR PDATAVAR pGlobalVariables;
EQLIB_VAR PDATAVAR pMacroVariables;

EQLIB_VAR BOOL bAllErrorsFatal;
EQLIB_VAR BOOL bAllErrorsDumpStack;
EQLIB_VAR BOOL bAllErrorsLog;
EQLIB_API char DataTypeTemp[MAX_STRING];
EQLIB_API cTargetBuff TargetBuffTemp;
EQLIB_API char gszVersion[32];
EQLIB_VAR DWORD gdwLocalPlayer;
EQLIB_API char gszTime[32];
EQLIB_API int gBuild;
EQLIB_API bool gbDoingModuleChecks;

EQLIB_API ePVPServer PVPServer;
EQLIB_API HANDLE ghInitializeMQ2SpellDb;
EQLIB_VAR HANDLE ghLockSpellMap;
EQLIB_VAR HANDLE ghLockPickZone;
EQLIB_VAR HANDLE ghLockDelayCommand;
EQLIB_VAR HANDLE ghCCommandLock;
EQLIB_VAR HANDLE ghVariableLock;
EQLIB_VAR HANDLE ghGetClassMemberLock;

EQLIB_VAR BOOL g_Loaded;
EQLIB_VAR DWORD ThreadID;

EQLIB_VAR BOOL gStringTableFixed;
EQLIB_VAR DWORD gMaxSpawnCaptions;
EQLIB_VAR BOOL gMQCaptions;
EQLIB_VAR BOOL gAnonymize;

enum EAnonFlags
{
	EAF_None,
	EAF_Class,
};

EQLIB_VAR DWORD gAnonymizeFlag;
EQLIB_VAR HMODULE ghModule;
EQLIB_VAR HINSTANCE ghInstance;
EQLIB_VAR HWND ghInjectorWnd;
EQLIB_VAR BOOL gbEQWLoaded;
EQLIB_VAR BOOL gbUnload;
EQLIB_VAR bool gBindInProgress;
EQLIB_VAR BOOL gbLoad;
EQLIB_VAR DWORD gpHook;
EQLIB_VAR HMODULE ghmq2ic;
EQLIB_VAR PMACROBLOCK gMacroBlock;
EQLIB_VAR int BlockIndex;
EQLIB_VAR PMACROSTACK gMacroStack;
EQLIB_VAR std::map <std::string, int, CaseInsensitiveLess> gMacroSubLookupMap;
EQLIB_VAR std::map<std::string, int> gUndeclaredVars;
EQLIB_VAR PEVENTQUEUE gEventQueue;
EQLIB_VAR int gEventFunc[NUM_EVENTS];
EQLIB_VAR UCHAR gLastFind;
EQLIB_VAR BOOL gInClick;
EQLIB_VAR double gZFilter;
EQLIB_VAR double gFaceAngle;
EQLIB_VAR double gLookAngle;
EQLIB_VAR BOOL gbSpelldbLoaded;
EQLIB_VAR char gszEQPath[MAX_STRING];
EQLIB_VAR char gszMacroPath[MAX_STRING];
EQLIB_VAR char gszLogPath[MAX_STRING];
EQLIB_VAR char gszINIPath[MAX_STRING];
EQLIB_VAR char gszINIFilename[MAX_STRING];
EQLIB_VAR char gszItemDB[MAX_STRING];
EQLIB_VAR char gszMacroName[MAX_STRING];
EQLIB_VAR char szLastCommand[MAX_STRING];

EQLIB_VAR char gszLastNormalError[MAX_STRING];// QUIT USING THIS DIRECTLY, USE MacroError, FatalError, ETC
EQLIB_VAR char gszLastSyntaxError[MAX_STRING];
EQLIB_VAR char gszLastMQ2DataError[MAX_STRING];

EQLIB_VAR SPAWNINFO* pNamingSpawn;
EQLIB_VAR char gszSpawnNPCName[MAX_STRING];
EQLIB_VAR char gszSpawnPlayerName[8][MAX_STRING];
EQLIB_VAR char gszSpawnPetName[MAX_STRING];
EQLIB_VAR char gszSpawnCorpseName[MAX_STRING];
EQLIB_VAR char gszAnonCaption[MAX_STRING];

EQLIB_VAR DWORD DrawHUDParams[4];

EQLIB_VAR DWORD gEventChat;
EQLIB_VAR ULONGLONG gRunning;
EQLIB_VAR BOOL gbMoving;
EQLIB_VAR DWORD gMaxTurbo;
EQLIB_VAR DWORD gTurboLimit;

EQLIB_VAR BOOL gReturn;

EQLIB_VAR PCHATBUF gDelayedCommands;

EQLIB_VAR DWORD gbAssistComplete;
EQLIB_VAR BOOL gTargetbuffs;
EQLIB_VAR BOOL gItemsReceived;
EQLIB_VAR BOOL gbInZone;
EQLIB_VAR BOOL gZoning;
EQLIB_VAR ULONGLONG OldLastEnteredZone;
EQLIB_VAR ULONGLONG LastEnteredZone;
EQLIB_VAR BOOL WereWeZoning;
EQLIB_VAR BOOL gbInDInput;
EQLIB_VAR BOOL gbInDState;
EQLIB_VAR BOOL gbInDAcquire;
EQLIB_VAR BOOL gbInChat;
EQLIB_VAR BOOL gFilterSkillsAll;
EQLIB_VAR BOOL gFilterSkillsIncrease;
EQLIB_VAR BOOL gFilterTarget;
EQLIB_VAR BOOL gFilterDebug;
EQLIB_VAR BOOL gFilterMoney;
EQLIB_VAR BOOL gFilterFood;
EQLIB_VAR BOOL gFilterMQ;
EQLIB_VAR BOOL gFilterMacro;
EQLIB_VAR BOOL gFilterEncumber;
EQLIB_VAR BOOL gFilterCustom;
EQLIB_VAR BOOL gSpewToFile;
EQLIB_VAR BOOL gbDoAutoRun;
EQLIB_VAR BOOL gMQPauseOnChat;
EQLIB_VAR BOOL gKeepKeys;
EQLIB_VAR BOOL gLClickedObject;
EQLIB_VAR SWHOFILTER gFilterSWho;
EQLIB_VAR BOOL gCreateMQ2NewsWindow;
EQLIB_VAR BOOL gUseNewNamedTest;
EQLIB_VAR BOOL gbInForeground;

EQLIB_VAR BOOL gbHUDUnderUI;
EQLIB_VAR BOOL gbAlwaysDrawMQHUD;

EQLIB_VAR BOOL gFilterMQ2DataErrors;

EQLIB_VAR char gIfDelimiter;
EQLIB_VAR char gIfAltDelimiter;

EQLIB_VAR DWORD gNetStatusXPos;
EQLIB_VAR DWORD gNetStatusYPos;

EQLIB_VAR LONG gStackingDebug;

EQLIB_VAR double DegToRad;
EQLIB_VAR double PI;

extern Blech* pMQ2Blech;
EQLIB_VAR char EventMsg[MAX_STRING];
EQLIB_VAR Blech* pEventBlech;
EQLIB_VAR PEVENTLIST pEventList;

EQLIB_VAR PMQTIMER gTimer;
EQLIB_VAR LONG gDelay;
EQLIB_VAR char gDelayCondition[MAX_STRING];
EQLIB_VAR SPAWNINFO EnviroTarget;
EQLIB_VAR SPAWNINFO PetSpawn;
EQLIB_VAR SPAWNINFO MercenarySpawn;
EQLIB_VAR GROUNDOBJECT GroundObject;
EQLIB_VAR PGROUNDITEM pGroundTarget;
EQLIB_VAR SPAWNINFO DoorEnviroTarget;
EQLIB_VAR PDOOR pDoorTarget;
EQLIB_VAR PITEMDB gItemDB;
EQLIB_VAR BOOL bRunNextCommand;
EQLIB_VAR BOOL bAllowCommandParse;
EQLIB_VAR BOOL gTurbo;
EQLIB_VAR BOOL gWarning;
EQLIB_VAR BOOL gknightlyparse;
EQLIB_VAR PDEFINE pDefines;
EQLIB_VAR PBINDLIST pBindList;
EQLIB_VAR PFILTER gpFilters;

EQLIB_VAR std::map<std::string, unsigned long> ItemSlotMap;

EQLIB_VAR BOOL g_bInDXMouse;
EQLIB_VAR PMOUSESPOOF gMouseData;

EQLIB_VAR PCHAR gDiKeyName[256];

EQLIB_VAR DWORD gGameState;
EQLIB_VAR BOOL gbMQ2LoadingMsg;
EQLIB_VAR BOOL gbExactSearchCleanNames;

EQLIB_VAR DWORD EQADDR_CONVERTITEMTAGS;

EQLIB_VAR DWORD EQADDR_MEMCHECK0;
EQLIB_VAR DWORD EQADDR_MEMCHECK1;
EQLIB_VAR DWORD EQADDR_MEMCHECK2;
EQLIB_VAR DWORD EQADDR_MEMCHECK3;
EQLIB_VAR DWORD EQADDR_MEMCHECK4;
EQLIB_VAR PCHAR EQADDR_SERVERHOST;
EQLIB_VAR PCHAR EQADDR_SERVERNAME;
EQLIB_VAR DWORD EQADDR_HWND;

EQLIB_VAR SKILLMGR** ppSkillMgr;
#define pSkillMgr (*ppSkillMgr)
EQLIB_VAR EVERQUESTINFO* ppEverQuestInfo;
#define pEverQuestInfo (ppEverQuestInfo)

EQLIB_VAR PCMDLIST EQADDR_CMDLIST;

EQLIB_VAR PBYTE EQADDR_ATTACK;
EQLIB_VAR PBYTE EQADDR_NOTINCHATMODE;
EQLIB_VAR PBYTE EQADDR_RUNWALKSTATE;
EQLIB_VAR PCHAR EQADDR_LASTTELL;
EQLIB_VAR PVOID EQADDR_GWORLD;
EQLIB_VAR PDWORD EQADDR_DOABILITYLIST;
EQLIB_VAR PDWORD EQADDR_SUBSCRIPTIONTYPE;
EQLIB_VAR DWORD EQADDR_GROUPAGGRO;
EQLIB_VAR PCHAR EQADDR_TARGETAGGROHOLDER;
EQLIB_VAR PBYTE EQADDR_ZONETYPE;
EQLIB_VAR BOOL gbUseTellWindows;

#define indoor (((*EQADDR_ZONETYPE) == 0) || ((*EQADDR_ZONETYPE) == 3) || ((*EQADDR_ZONETYPE) == 4))
#define outdoor (((*EQADDR_ZONETYPE) == 1) || ((*EQADDR_ZONETYPE) == 2) || ((*EQADDR_ZONETYPE) == 5))
#define bindable (((*EQADDR_ZONETYPE) == 2) || ((*EQADDR_ZONETYPE) == 3) || ((*EQADDR_ZONETYPE) == 4))
//EQLIB_VAR PBYTE EQADDR_DOABILITYAVAILABLE;
EQLIB_VAR PBYTE pTributeActive;

EQLIB_VAR PBYTE EQADDR_ENCRYPTPAD0;
EQLIB_VAR PBYTE EQADDR_ENCRYPTPAD1;
EQLIB_VAR PBYTE EQADDR_ENCRYPTPAD2;
EQLIB_VAR PBYTE EQADDR_ENCRYPTPAD3;
EQLIB_VAR PBYTE EQADDR_ENCRYPTPAD4;

EQLIB_VAR PMOUSEINFO EQADDR_MOUSE;
EQLIB_VAR PMOUSECLICK EQADDR_MOUSECLICK;

EQLIB_VAR PMAPLABEL * ppCurrentMapLabel;
#define pCurrentMapLabel (*ppCurrentMapLabel)

EQLIB_VAR PCHAR gpbRangedAttackReady;
#define gbRangedAttackReady (*gpbRangedAttackReady)
EQLIB_VAR PCHAR gpbShowNetStatus;
#define gbShowNetStatus (*gpbShowNetStatus)
EQLIB_VAR DWORD * gpShowNames;
#define gShowNames (*gpShowNames)
EQLIB_VAR DWORD * gpPCNames;
#define gPCNames (*gpPCNames)
EQLIB_VAR PBYTE gpAutoFire;
#define gAutoFire (*gpAutoFire)
EQLIB_VAR PAUTOSKILL gpAutoSkill;
#define gAutoSkill (*gpAutoSkill)
EQLIB_VAR PBYTE gpShiftKeyDown;
#define gShiftKeyDown (*gpShiftKeyDown)
EQLIB_VAR DWORD * gpMouseEventTime;
#define gMouseEventTime (*gpMouseEventTime)
EQLIB_VAR DWORD * gpbCommandEvent;
#define gbCommandEvent (*gpbCommandEvent)

EQLIB_VAR CResolutionHandler * *ppCResolutionHandler;
#define pCResolutionHandler (*ppCResolutionHandler)
EQLIB_VAR DWORD * g_ppDrawHandler;
#define g_pDrawHandler (*g_ppDrawHandler)

EQLIB_VAR PCHAR * EQMappableCommandList;
EQLIB_VAR PBYTE EQbCommandStates;

EQLIB_VAR DWORD EQADDR_DIMAIN;
EQLIB_VAR IDirectInputDevice8A * *EQADDR_DIKEYBOARD;
EQLIB_VAR IDirectInputDevice8A * *EQADDR_DIMOUSE;
EQLIB_VAR PPOINT EQADDR_DIMOUSECOPY;
EQLIB_VAR PPOINT EQADDR_DIMOUSECHECK;

EQLIB_VAR DWORD EQADDR_EQLABELS;

EQLIB_VAR BOOL gMouseClickInProgress[8];
EQLIB_VAR BOOL bDetMouse;

// ***************************************************************************
// String arrays
// ***************************************************************************
EQLIB_VAR PCHAR szEQMappableCommands[nEQMappableCommands];

EQLIB_VAR PCHAR szHeading[];
EQLIB_VAR PCHAR szHeadingShort[];
EQLIB_VAR PCHAR szHeadingNormal[];
EQLIB_VAR PCHAR szHeadingNormalShort[];
EQLIB_VAR PCHAR szSize[];
EQLIB_VAR PCHAR szSpawnType[];
EQLIB_VAR PCHAR szGuildStatus[];
EQLIB_VAR PCHAR szGender[];
EQLIB_VAR PCHAR szDeityTeam[];
EQLIB_VAR PCHAR szLights[];
EQLIB_VAR BYTE LightBrightness[];
EQLIB_VAR PCHAR szSkills[];
EQLIB_VAR PCHAR szInnates[];

EQLIB_VAR PCHAR szWornLoc[];

EQLIB_VAR fEQCommand			cmdHelp;
EQLIB_VAR fEQCommand			cmdWho;
EQLIB_VAR fEQCommand			cmdWhoTarget;
EQLIB_VAR fEQCommand			cmdLocation;
EQLIB_VAR fEQCommand			cmdFace;
EQLIB_VAR fEQCommand			cmdTarget;
EQLIB_VAR fEQCommand			cmdCharInfo;
EQLIB_VAR fEQCommand			cmdFilter;
EQLIB_VAR fEQCommand			cmdDoAbility;
EQLIB_VAR fEQCommand			cmdCast;
EQLIB_VAR fEQCommand			cmdUseItem;
EQLIB_VAR fEQCommand			cmdPet;
EQLIB_VAR fEQCommand			cmdMercSwitch;
EQLIB_VAR fEQCommand			cmdAdvLoot;
EQLIB_VAR fEQCommand			cmdPickZone;
EQLIB_VAR fEQCommand			cmdAssist;
EQLIB_VAR fEQCommand			cmdQuit;

EQLIB_VAR fEQNewUIINI			NewUIINI;
EQLIB_VAR fEQProcGameEvts		ProcessGameEvents;
EQLIB_VAR fEQGetMelee			get_melee_range;
EQLIB_VAR fEQToggleKeyRingItem	cmdToggleKeyRingItem;
EQLIB_VAR fICGetHashData		IC_GetHashData;
EQLIB_VAR fICSetHashData		IC_SetHashData;
EQLIB_VAR fLoaderSetLoaded		IC_LoaderSetLoaded;
EQLIB_VAR fLoaderClearLoaded	IC_LoaderClearLoaded;
EQLIB_VAR fMQ2Unload            IC_MQ2Unload;
EQLIB_VAR fClassLvl				IC_ClassLvl;

EQLIB_VAR fEQW_GetDisplayWindow EQW_GetDisplayWindow;

EQLIB_VAR bool ExecuteCmd(unsigned int command, bool keydown, void* data);
EQLIB_VAR bool IsResEffectSpell(int);
//EQLIB_VAR PCHAR szItemName[];
//EQLIB_VAR PCHAR szItemName4xx[];
//EQLIB_VAR PCHAR szTheme[];
EQLIB_VAR PCHAR szDmgBonusType[];
EQLIB_VAR PCHAR szBodyType[];
EQLIB_VAR PCHAR szAugRestrictions[];
EQLIB_VAR PCHAR szItemSlot[];
EQLIB_VAR PCHAR szEquipmentSlot[];
EQLIB_VAR PCHAR szExpansions[];

EQLIB_VAR BOOL bLaxColor;
EQLIB_VAR PCHAR szColorAdjective[];
EQLIB_VAR PCHAR szColorAdjectiveYou[];
EQLIB_VAR PCHAR szColorExpletive[];
EQLIB_VAR PCHAR szColorSyntaxError[];
EQLIB_VAR PCHAR szColorMacroError[];
EQLIB_VAR PCHAR szColorMQ2DataError[];
EQLIB_VAR PCHAR szColorFatalError[];
EQLIB_VAR DWORD nColorAdjective;
EQLIB_VAR DWORD nColorAdjectiveYou;
EQLIB_VAR DWORD nColorExpletive;
EQLIB_VAR DWORD nColorSyntaxError;
EQLIB_VAR DWORD nColorMacroError;
EQLIB_VAR DWORD nColorMQ2DataError;
EQLIB_VAR DWORD nColorFatalError;

EQLIB_VAR std::map<std::string, std::string> mAliases;
EQLIB_VAR std::map<std::string, PDATAVAR> VariableMap;
EQLIB_VAR std::unordered_map<std::string, std::unique_ptr<MQ2DATAITEM>> MQ2DataMap;
EQLIB_VAR PSUB pSubs;
EQLIB_VAR PMQCOMMAND pCommands;
EQLIB_VAR PMQPLUGIN pPlugins;

EQLIB_VAR fGetLabelFromEQ GetLabelFromEQ;

EQLIB_VAR std::map<std::string, PSPAWNINFO> SpawnByName;
//EQLIB_VAR EQPlayer **ppEQP_IDArray;
EQLIB_VAR MQRANK EQP_DistArray[3000];
EQLIB_VAR DWORD gSpawnCount;
//#define ppEQP_IDArray (*pppEQP_IDArray)

EQLIB_VAR StringTable **ppStringTable;
#define pStringTable (*ppStringTable)

EQLIB_VAR CDBStr** ppCDBStr;
#define pCDBStr (*ppCDBStr)
EQLIB_VAR EQMisc* pEQMisc;
EQLIB_VAR CSkillMgr** ppCSkillMgr;
#define pCSkillMgr (*ppCSkillMgr)
EQLIB_VAR CGuild* pGuild;

EQLIB_VAR CEverQuest** ppEverQuest;
#define pEverQuest (*ppEverQuest)
EQLIB_VAR CDisplay** ppDisplay;
#define pDisplay (*ppDisplay)
EQLIB_VAR EQ_PC** ppPCData;
#define pPCData (*ppPCData)
EQLIB_VAR EQ_Character** ppCharData;
#define pCharData (*ppCharData)
#define pCharData1 ((EQ_Character1 *)&GetCharInfo()->vtable2)
EQLIB_VAR PlayerClient** ppCharSpawn;
#define pCharSpawn (*ppCharSpawn)
EQLIB_VAR PlayerClient** ppActiveMerchant;
#define pActiveMerchant (*ppActiveMerchant)
EQLIB_VAR PlayerManagerClient** ppSpawnManager;
#define pSpawnManager (*ppSpawnManager)
#define pSpawnList ((pSpawnManager)->FirstSpawn)
#define pChatService ((CChatService*)((EVERQUEST*)pEverQuest)->ChatService)
#define pPlayerPointManager ((PlayerPointManager*)&GetCharInfo()->PointManager.vfTable)

EQLIB_VAR PlayerClient** ppLocalPlayer;
#define pLocalPlayer (*ppLocalPlayer)
EQLIB_VAR PlayerClient** ppControlledPlayer;
#define pControlledPlayer (*ppControlledPlayer)

EQLIB_VAR EQWorldData** ppWorldData;
#define pWorldData (*ppWorldData)
EQLIB_VAR ClientSpellManager** ppSpellMgr;
#define pSpellMgr (*ppSpellMgr)
EQLIB_VAR PlayerClient** ppTarget;
#define pTarget (*ppTarget)
EQLIB_VAR EqSwitchManager** ppSwitchMgr;
#define pSwitchMgr (*ppSwitchMgr)
EQLIB_VAR EQZoneInfo* pZoneInfo;
EQLIB_VAR PGUILDS pGuildList;
EQLIB_VAR PEQSOCIAL   pSocialList;

EQLIB_VAR PBYTE pgHotkeyPage;
#define gHotkeyPage (*pgHotkeyPage)

EQLIB_VAR PlayerClient** ppTradeTarget;
#define pTradeTarget (*ppTradeTarget)
EQLIB_VAR PlayerClient** ppActiveBanker;
#define pActiveBanker (*ppActiveBanker)
EQLIB_VAR PlayerClient** ppActiveGMaster;
#define pActiveGMaster (*ppActiveGMaster)
EQLIB_VAR PlayerClient** ppActiveCorpse;
#define pActiveCorpse (*ppActiveCorpse)

EQLIB_VAR CSidlManager** ppSidlMgr;
#define pSidlMgr (*ppSidlMgr)

EQLIB_VAR CXWndManager** ppWndMgr;
#define pWndMgr (*ppWndMgr)
#define pItemList GetItemList()
#define pKeypressHandler GetKeyPresshandler()
EQLIB_VAR PEQRAID pRaid;
EQLIB_VAR DZMEMBER** ppDZMember;
EQLIB_VAR TASKMEMBER** ppTaskMember;
EQLIB_VAR DZTIMERINFO** ppDZTimerInfo;
EQLIB_VAR DYNAMICZONE* pDynamicZone;

EQLIB_VAR PINT pgCurrentSocial;
#define gCurrentSocial (*pgCurrentSocial)

EQLIB_VAR DWORD* pScreenX;
#define ScreenX (*pScreenX)
EQLIB_VAR DWORD* pScreenY;
#define ScreenY (*pScreenY)
EQLIB_VAR DWORD* pScreenXMax;
#define ScreenXMax (*pScreenXMax)
EQLIB_VAR DWORD* pScreenYMax;
#define ScreenYMax (*pScreenYMax)
EQLIB_VAR DWORD* pScreenMode;
#define ScreenMode (*pScreenMode)
EQLIB_VAR char* pMouseLook;
#define bMouseLook (*pMouseLook)

EQLIB_VAR SPELLFAVORITE* pSpellSets;
EQLIB_VAR AltAdvManager** ppAltAdvManager;
#define pAltAdvManager (*ppAltAdvManager)

EQLIB_VAR connection_t** ppConnection;
#define pConnection (*ppConnection)
#define pAuraMgr GetAuraMgr()
EQLIB_VAR CAuraWnd** ppAuraWnd;
#define pAuraWnd (*ppAuraWnd)

EQLIB_VAR MERCENARYINFO** ppMercInfo;
#define pMercInfo (*ppMercInfo)

#define pMercAltAbilities GetMercAltAbilities()
EQLIB_VAR LootFiltersManager** ppLootFiltersManager;
#define pLootFiltersManager (*ppLootFiltersManager)
EQLIB_VAR EQSpellStrings** ppEQSpellStrings;
#define pEQSpellStrings (*ppEQSpellStrings)
#define pAggroInfo GetAggroInfo()
EQLIB_VAR CLargeDialogWnd** ppLargeDialog;
#define pLargeDialog (*ppLargeDialog)
EQLIB_VAR CItemDisplayManager** ppItemDisplayManager;
#define pItemDisplayManager (*ppItemDisplayManager)
EQLIB_VAR EqSoundManager** ppEqSoundManager;
#define pEqSoundManager (*ppEqSoundManager)

/* WINDOW INSTANCES */
EQLIB_VAR CContextMenuManager** ppContextMenuManager;
EQLIB_VAR CCursorAttachment** ppCursorAttachment;
EQLIB_VAR CSocialEditWnd** ppSocialEditWnd;
EQLIB_VAR CContainerMgr** ppContainerMgr;
EQLIB_VAR CChatWindowManager** ppChatManager;
EQLIB_VAR CConfirmationDialog** ppConfirmationDialog;

EQLIB_VAR CFacePick** ppFacePick;
EQLIB_VAR CFactionWnd** ppFactionWnd;
EQLIB_VAR CExtendedTargetWnd** ppExtendedTargetWnd;
EQLIB_VAR CFindItemWnd** ppFindItemWnd;
EQLIB_VAR CFindLocationWnd** ppFindLocationWnd;
EQLIB_VAR CInvSlotMgr** ppInvSlotMgr;
//EQLIB_VAR CPopupWndManager **ppPopupWndManager;
EQLIB_VAR CNoteWnd** ppNoteWnd;
EQLIB_VAR CHelpWnd** ppHelpWnd;
EQLIB_VAR CTipWnd** ppTipWnd;
EQLIB_VAR CTipWnd** ppTipWnd;
EQLIB_VAR CBookWnd** ppBookWnd;
EQLIB_VAR CFriendsWnd** ppFriendsWnd;
EQLIB_VAR CMusicPlayerWnd** ppMusicPlayerWnd;

EQLIB_VAR CRealEstateItemsWnd** ppRealEstateItemsWnd;
EQLIB_VAR CAchievementsWnd** ppAchievementsWnd;
EQLIB_VAR CAlarmWnd** ppAlarmWnd;
EQLIB_VAR CLoadskinWnd** ppLoadskinWnd;
EQLIB_VAR CPetInfoWnd** ppPetInfoWnd;
EQLIB_VAR CTrainWnd** ppTrainWnd;
EQLIB_VAR CSkillsWnd** ppSkillsWnd;
EQLIB_VAR CSkillsSelectWnd** ppSkillsSelectWnd;
EQLIB_VAR CAAWnd** ppAAWnd;
EQLIB_VAR CGroupWnd** ppGroupWnd;
//EQLIB_VAR CSystemInfoDialogBox **ppSystemInfoDialogBox;
EQLIB_VAR CGroupSearchWnd** ppGroupSearchWnd;
EQLIB_VAR CGroupSearchFiltersWnd** ppGroupSearchFiltersWnd;
EQLIB_VAR CRaidWnd** ppRaidWnd;
EQLIB_VAR CRaidOptionsWnd** ppRaidOptionsWnd;
EQLIB_VAR CBreathWnd** ppBreathWnd;
EQLIB_VAR CMapToolbarWnd** ppMapToolbarWnd;
EQLIB_VAR CMapViewWnd** ppMapViewWnd;
EQLIB_VAR CEditLabelWnd** ppEditLabelWnd;
EQLIB_VAR COptionsWnd** ppOptionsWnd;
EQLIB_VAR CBuffWindow** ppBuffWindowNORMAL;
EQLIB_VAR CBuffWindow** ppBuffWindowSHORT;
EQLIB_VAR CTargetWnd** ppTargetWnd;
EQLIB_VAR CColorPickerWnd** ppColorPickerWnd;
EQLIB_VAR CCombatSkillsSelectWnd** ppCombatSkillsSelectWnd;
EQLIB_VAR CHotButtonWnd** ppHotButtonWnd;
EQLIB_VAR CPlayerWnd** ppPlayerWnd;
EQLIB_VAR CCastingWnd** ppCastingWnd;
EQLIB_VAR CCastSpellWnd** ppCastSpellWnd;
EQLIB_VAR CSpellBookWnd** ppSpellBookWnd;
EQLIB_VAR CInventoryWnd** ppInventoryWnd;
EQLIB_VAR CBankWnd** ppBankWnd;
EQLIB_VAR CQuantityWnd** ppQuantityWnd;
EQLIB_VAR CTextEntryWnd** ppTextEntryWnd;
EQLIB_VAR CFileSelectionWnd** ppFileSelectionWnd;
EQLIB_VAR CLootWnd** ppLootWnd;
EQLIB_VAR CRespawnWnd** ppRespawnWnd;
EQLIB_VAR CActionsWnd** ppActionsWnd;
EQLIB_VAR CCombatAbilityWnd** ppCombatAbilityWnd;
EQLIB_VAR CMerchantWnd** ppMerchantWnd;
EQLIB_VAR CTradeWnd** ppTradeWnd;
EQLIB_VAR CBazaarWnd** ppBazaarWnd;
EQLIB_VAR CBazaarSearchWnd** ppBazaarSearchWnd;
EQLIB_VAR CGiveWnd** ppGiveWnd;
EQLIB_VAR CSelectorWnd** ppSelectorWnd;
EQLIB_VAR CTrackingWnd** ppTrackingWnd;
EQLIB_VAR CInspectWnd** ppInspectWnd;
EQLIB_VAR CFeedbackWnd** ppFeedbackWnd;
EQLIB_VAR CBugReportWnd** ppBugReportWnd;
EQLIB_VAR CVideoModesWnd** ppVideoModesWnd;
EQLIB_VAR CCompassWnd** ppCompassWnd;
EQLIB_VAR CPlayerNotesWnd** ppPlayerNotesWnd;
EQLIB_VAR CGemsGameWnd** ppGemsGameWnd;
EQLIB_VAR CStoryWnd** ppStoryWnd;
//EQLIB_VAR CAdventureRequestWnd **ppAdventureRequestWnd;
//EQLIB_VAR CAdventureMerchantWnd **ppAdventureMerchantWnd;
//EQLIB_VAR CAdventureStatsWnd **ppAdventureStatsWnd;
//EQLIB_VAR CAdventureLeaderboardWnd **ppAdventureLeaderboardWnd;
//EQLIB_VAR CLeadershipWindow **ppLeadershipWindow;
EQLIB_VAR CBodyTintWnd** ppBodyTintWnd;
EQLIB_VAR CGuildMgmtWnd** ppGuildMgmtWnd;
EQLIB_VAR CJournalTextWnd** ppJournalTextWnd;
EQLIB_VAR CJournalCatWnd** ppJournalCatWnd;
//EQLIB_VAR CTributeBenefitWnd **ppTributeBenefitWnd;
//EQLIB_VAR CTributeMasterWnd **ppTributeMasterWnd;
EQLIB_VAR CPetitionQWnd** ppPetitionQWnd;
EQLIB_VAR CBandolierWnd** ppBandolierWnd;
EQLIB_VAR CWebManager** ppCWebManager;
#define pCWebManager (*ppCWebManager)
EQLIB_VAR CTaskWnd** ppTaskWnd;
EQLIB_VAR CTaskManager* ppTaskManager;
#define pTaskManager (*ppTaskManager)
EQLIB_VAR CTimeLeftWnd** ppTimeLeftWnd;
EQLIB_VAR CAdvancedLootWnd** ppAdvancedLootWnd;
EQLIB_VAR CRewardSelectionWnd** ppRewardSelectionWnd;
EQLIB_VAR CEQSuiteTextureLoader* ppEQSuiteTextureLoader;
EQLIB_VAR PointMerchantWnd** ppPointMerchantWnd;
EQLIB_VAR CZoneGuideWnd** ppCZoneGuideWnd;


#define pPointMerchantWnd (*ppPointMerchantWnd)
#define pCZoneGuideWnd (*ppCZoneGuideWnd)
#define pConfirmationDialog (*ppConfirmationDialog)
#define pRewardSelectionWnd (*ppRewardSelectionWnd)
#define pAdvancedLootWnd (*ppAdvancedLootWnd)
#define pContextMenuManager (*ppContextMenuManager)
#define pCursorAttachment (*ppCursorAttachment)
#define pSocialEditWnd (*ppSocialEditWnd)
#define pContainerMgr (*ppContainerMgr)
#define pChatManager (*ppChatManager)
#define pEQSuiteTextureLoader (ppEQSuiteTextureLoader)
#define pFacePick (*ppFacePick)
#define pFactionWnd (*ppFactionWnd)
#define pExtendedTargetWnd (*ppExtendedTargetWnd)
#define pFindItemWnd (*ppFindItemWnd)
#define pFindLocationWnd (*ppFindLocationWnd)
#define pInvSlotMgr (*ppInvSlotMgr)
#define pPopupWndManager (*ppPopupWndManager)
#define pNoteWnd (*ppNoteWnd)
#define pHelpWnd (*ppHelpWnd)
#define pTipWnd (*ppTipWnd)
#define pTipWnd (*ppTipWnd)
#define pBookWnd (*ppBookWnd)
#define pFriendsWnd (*ppFriendsWnd)
#define pMusicPlayerWnd (*ppMusicPlayerWnd)
#define pRealEstateItemsWnd (*ppRealEstateItemsWnd)
#define pAchievementsWnd (*ppAchievementsWnd)
#define pAlarmWnd (*ppAlarmWnd)
#define pLoadskinWnd (*ppLoadskinWnd)
#define pPetInfoWnd (*ppPetInfoWnd)
#define pTrainWnd (*ppTrainWnd)
#define pSkillsWnd (*ppSkillsWnd)
#define pSkillsSelectWnd (*ppSkillsSelectWnd)
#define pAAWnd (*ppAAWnd)
#define pGroupWnd (*ppGroupWnd)
#define pSystemInfoDialogBox (*ppSystemInfoDialogBox)
#define pGroupSearchWnd (*ppGroupSearchWnd)
#define pGroupSearchFiltersWnd (*ppGroupSearchFiltersWnd)
#define pRaidWnd (*ppRaidWnd)
#define pRaidOptionsWnd (*ppRaidOptionsWnd)
#define pBreathWnd (*ppBreathWnd)
#define pMapToolbarWnd (*ppMapToolbarWnd)
#define pMapViewWnd (*ppMapViewWnd)
#define pEditLabelWnd (*ppEditLabelWnd)
#define pOptionsWnd (*ppOptionsWnd)
#define pBuffWnd (*ppBuffWindowNORMAL)
#define pSongWnd (*ppBuffWindowSHORT)
#define pTargetWnd (*ppTargetWnd)
#define pColorPickerWnd (*ppColorPickerWnd)
#define pCombatAbilityWnd (*ppCombatAbilityWnd)
#define pCombatSkillsSelectWnd (*ppCombatSkillsSelectWnd)
#define pHotButtonWnd (*ppHotButtonWnd)
#define pPlayerWnd (*ppPlayerWnd)
#define pCastingWnd (*ppCastingWnd)
#define pCastSpellWnd (*ppCastSpellWnd)
#define pSpellBookWnd (*ppSpellBookWnd)
#define pInventoryWnd (*ppInventoryWnd)
#define pBankWnd (*ppBankWnd)
#define pQuantityWnd (*ppQuantityWnd)
#define pTextEntryWnd (*ppTextEntryWnd)
#define pFileSelectionWnd (*ppFileSelectionWnd)
#define pLootWnd (*ppLootWnd)
#define pRespawnWnd (*ppRespawnWnd)
#define pActionsWnd (*ppActionsWnd)
#define pMerchantWnd (*ppMerchantWnd)
#define pTradeWnd (*ppTradeWnd)
#define pBazaarWnd (*ppBazaarWnd)
#define pBazaarSearchWnd (*ppBazaarSearchWnd)
#define pGiveWnd (*ppGiveWnd)
#define pSelectorWnd (*ppSelectorWnd)
#define pTrackingWnd (*ppTrackingWnd)
#define pInspectWnd (*ppInspectWnd)
#define pFeedbackWnd (*ppFeedbackWnd)
#define pBugReportWnd (*ppBugReportWnd)
#define pVideoModesWnd (*ppVideoModesWnd)
#define pCompassWnd (*ppCompassWnd)
#define pPlayerNotesWnd (*ppPlayerNotesWnd)
#define pGemsGameWnd (*ppGemsGameWnd)
#define pStoryWnd (*ppStoryWnd)
#define pAdventureRequestWnd (*ppAdventureRequestWnd)
#define pAdventureMerchantWnd (*ppAdventureMerchantWnd)
#define pAdventureStatsWnd (*ppAdventureStatsWnd)
#define pAdventureLeaderboardWnd (*ppAdventureLeaderboardWnd)
#define pLeadershipWindow (*ppLeadershipWindow)
#define pBodyTintWnd (*ppBodyTintWnd)
#define pGuildMgmtWnd (*ppGuildMgmtWnd)
#define pJournalTextWnd (*ppJournalTextWnd)
#define pJournalCatWnd (*ppJournalCatWnd)
#define pTributeBenefitWnd (*ppTributeBenefitWnd)
#define pTributeMasterWnd (*ppTributeMasterWnd)
#define pPetitionQWnd (*ppPetitionQWnd)
#define pTaskWnd (*ppTaskWnd)
#define pTaskSomething (ppTaskSomething)
#define pTimeLeftWnd (*ppTimeLeftWnd)
#define pTextOverlay GetTextOverlay()
#define pPotionBeltWnd (*ppPotionBeltWnd)
#define pBandolierWnd (*ppBandolierWnd)
#define pDZMember (*ppDZMember)
#define pDZTimerInfo (*ppDZTimerInfo)
#define pTaskMember (*ppTaskMember)

EQLIB_VAR BOOL gbTimeStampChat;
EQLIB_VAR size_t g_eqgameimagesize;

EQLIB_VAR BOOL gUseTradeOnTarget;
EQLIB_VAR BOOL gbBeepOnTells;
EQLIB_VAR BOOL gbFlashOnTells;
EQLIB_VAR BOOL gbShowCurrentCamera;
EQLIB_VAR int  oldcameratype;
EQLIB_VAR char CameraText[2048];
EQLIB_VAR BOOL gbIgnoreAlertRecursion;

// used for KNIGHTLYPARSE
const std::string PARSE_PARAM_BEG = "${Parse[";
const std::string PARSE_PARAM_END = "]}";

#if __has_include("MQ2Globals-private.h")
#include "MQ2Globals-private.h"
#endif

} // namespace MQ2Globals
using namespace MQ2Globals;
