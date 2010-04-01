/*****************************************************************************
    MQ2Main.dll: MacroQuest2's extension DLL for EverQuest
    Copyright (C) 2002-2003 Plazmic, 2003-2005 Lax

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License, version 2, as published by
    the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
******************************************************************************/

namespace MQ2Globals
{

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

#ifndef ISXEQ
EQLIB_VAR PDATAVAR pGlobalVariables;
EQLIB_VAR PDATAVAR pMacroVariables;
#endif

EQLIB_VAR BOOL bAllErrorsFatal;
EQLIB_VAR BOOL bAllErrorsDumpStack;
EQLIB_API CHAR DataTypeTemp[MAX_STRING];

EQLIB_API CHAR gszVersion[32];


EQLIB_API DWORD gGameState;
EQLIB_API ePVPServer PVPServer;

EQLIB_VAR BOOL g_Loaded;
EQLIB_VAR DWORD ThreadID;

EQLIB_VAR BOOL gStringTableFixed;
EQLIB_VAR DWORD gMaxSpawnCaptions;
EQLIB_VAR BOOL gMQCaptions;

EQLIB_VAR HMODULE ghModule;
EQLIB_VAR HINSTANCE ghInstance;
EQLIB_VAR BOOL gbEQWLoaded;
//EQLIB_VAR PHOTKEY pHotkey;
EQLIB_VAR BOOL gbUnload;
EQLIB_VAR DWORD gpHook;
#ifndef ISXEQ
EQLIB_VAR PMACROBLOCK gMacroBlock;
EQLIB_VAR PMACROSTACK gMacroStack;
EQLIB_VAR map<string,PMACROBLOCK> gMacroSubLookupMap; 
EQLIB_VAR PEVENTQUEUE gEventQueue;
EQLIB_VAR PMACROBLOCK gEventFunc[NUM_EVENTS];
#endif
EQLIB_VAR UCHAR gLastFind;
EQLIB_VAR BOOL gInClick;
EQLIB_VAR DOUBLE gZFilter;
EQLIB_VAR DOUBLE gFaceAngle;
EQLIB_VAR DOUBLE gLookAngle;
EQLIB_VAR CHAR gszEQPath[MAX_STRING];
EQLIB_VAR CHAR gszMacroPath[MAX_STRING];
EQLIB_VAR CHAR gszLogPath[MAX_STRING];
EQLIB_VAR CHAR gszINIPath[MAX_STRING];
EQLIB_VAR CHAR gszINIFilename[MAX_STRING];
EQLIB_VAR CHAR gszItemDB[MAX_STRING];
EQLIB_VAR CHAR gszMacroName[MAX_STRING];
EQLIB_VAR CHAR szLastCommand[MAX_STRING];

EQLIB_VAR CHAR gszLastNormalError[MAX_STRING];// QUIT USING THIS DIRECTLY, USE MacroError, FatalError, ETC
EQLIB_VAR CHAR gszLastSyntaxError[MAX_STRING];
EQLIB_VAR CHAR gszLastMQ2DataError[MAX_STRING];

EQLIB_VAR PSPAWNINFO pNamingSpawn;
EQLIB_VAR CHAR gszSpawnNPCName[MAX_STRING];
EQLIB_VAR CHAR gszSpawnPlayerName[5][MAX_STRING];
EQLIB_VAR CHAR gszSpawnPetName[MAX_STRING];
EQLIB_VAR CHAR gszSpawnCorpseName[MAX_STRING];

EQLIB_VAR DWORD DrawHUDParams[4];

EQLIB_VAR DWORD gEventChat;
EQLIB_VAR DWORD gRunning;
EQLIB_VAR BOOL gbMoving;
EQLIB_VAR DWORD gMaxTurbo;

EQLIB_VAR PCHATBUF gDelayedCommands;

EQLIB_VAR BOOL gZoning;
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
//EQLIB_VAR DWORD gUseMQChatWnd;
EQLIB_VAR BOOL gFilterMQ;
EQLIB_VAR BOOL gFilterMacro;
EQLIB_VAR BOOL gFilterEncumber;
EQLIB_VAR BOOL gFilterCustom;
EQLIB_VAR BOOL gSpewToFile;
EQLIB_VAR BOOL gbDoAutoRun;
EQLIB_VAR BOOL gMQPauseOnChat;
EQLIB_VAR BOOL gKeepKeys;
EQLIB_VAR SWHOFILTER gFilterSWho;

EQLIB_VAR BOOL gbHUDUnderUI;
EQLIB_VAR BOOL gbAlwaysDrawMQHUD;

EQLIB_VAR BOOL gFilterMQ2DataErrors;

EQLIB_VAR DOUBLE DegToRad;
EQLIB_VAR DOUBLE PI;
#define ZoneShift			 0

#ifndef ISXEQ
EQLIB_VAR Blech *pMQ2Blech;
EQLIB_VAR CHAR EventMsg[MAX_STRING];
#ifdef USEBLECHEVENTS
EQLIB_VAR Blech *pEventBlech;
#endif
EQLIB_VAR PEVENTLIST pEventList;
#endif

//EQLIB_VAR PKEYPRESS gKeyStack;
EQLIB_VAR PMQTIMER gTimer;
EQLIB_VAR LONG gDelay;
EQLIB_VAR CHAR gDelayCondition[MAX_STRING];
EQLIB_VAR PALERTLIST gpAlertList;
EQLIB_VAR BOOL gMacroPause;
EQLIB_VAR SPAWNINFO EnviroTarget;
EQLIB_VAR ACTORINFO EnviroActor;
EQLIB_VAR PGROUNDITEM pGroundTarget;
EQLIB_VAR SPAWNINFO DoorEnviroTarget;
EQLIB_VAR PDOOR pDoorTarget;
EQLIB_VAR PITEMDB gItemDB;
EQLIB_VAR BOOL bRunNextCommand;
EQLIB_VAR BOOL bAllowCommandParse;
EQLIB_VAR BOOL gTurbo;
EQLIB_VAR PDEFINE pDefines;
//EQLIB_VAR CHAR gLastFindSlot[MAX_STRING];
//EQLIB_VAR CHAR gLastError[MAX_STRING];
//EQLIB_VAR HWND ghWnd;
EQLIB_VAR PFILTER gpFilters;

EQLIB_VAR map<string,unsigned long> ItemSlotMap;

EQLIB_VAR BOOL g_bInDXMouse;
EQLIB_VAR PMOUSESPOOF gMouseData;

EQLIB_VAR DIKEYID gDiKeyID[];
EQLIB_VAR PCHAR gDiKeyName[256];


EQLIB_VAR DWORD ManaGained;
EQLIB_VAR DWORD HealthGained;
EQLIB_VAR DWORD EnduranceGained;

EQLIB_VAR DWORD gGameState;


EQLIB_VAR DWORD EQADDR_CONVERTITEMTAGS;

EQLIB_VAR DWORD EQADDR_MEMCHECK0;
EQLIB_VAR DWORD EQADDR_MEMCHECK2;
EQLIB_VAR DWORD EQADDR_MEMCHECK3;
EQLIB_VAR DWORD EQADDR_MEMCHECK4;
EQLIB_VAR PCHAR EQADDR_SERVERHOST;
EQLIB_VAR PCHAR EQADDR_SERVERNAME;
EQLIB_VAR DWORD EQADDR_HWND;

EQLIB_VAR PSKILL *SkillDict;

EQLIB_VAR PEQFRIENDSLIST pFriendsList;
EQLIB_VAR PEQFRIENDSLIST pIgnoreList;

EQLIB_VAR PCMDLIST EQADDR_CMDLIST;

EQLIB_VAR PBYTE EQADDR_ATTACK;
EQLIB_VAR PBYTE EQADDR_NOTINCHATMODE;
EQLIB_VAR PBYTE EQADDR_RUNWALKSTATE;
EQLIB_VAR PCHAR EQADDR_LASTTELL;
EQLIB_VAR PVOID EQADDR_GWORLD;
EQLIB_VAR PDWORD EQADDR_DOABILITYLIST;
EQLIB_VAR PBYTE EQADDR_DOABILITYAVAILABLE;
EQLIB_VAR PBYTE pTributeActive;

EQLIB_VAR PBYTE EQADDR_ENCRYPTPAD0;
EQLIB_VAR PBYTE EQADDR_ENCRYPTPAD2;
EQLIB_VAR PBYTE EQADDR_ENCRYPTPAD3;
EQLIB_VAR PBYTE EQADDR_ENCRYPTPAD4;

EQLIB_VAR PMOUSEINFO EQADDR_MOUSE;
EQLIB_VAR PMOUSECLICK EQADDR_MOUSECLICK;

EQLIB_VAR PMAPLABEL *ppCurrentMapLabel;
#define pCurrentMapLabel (*ppCurrentMapLabel)

EQLIB_VAR PCHAR gpbRangedAttackReady;
#define gbRangedAttackReady (*gpbRangedAttackReady)
EQLIB_VAR PCHAR gpbAltTimerReady;
#define gbAltTimerReady (*gpbAltTimerReady)
EQLIB_VAR PCHAR gpbShowNetStatus;
#define gbShowNetStatus (*gpbShowNetStatus)
EQLIB_VAR DWORD *gpShowNames;
#define gShowNames (*gpShowNames)
EQLIB_VAR DWORD *gpPCNames;
#define gPCNames (*gpPCNames)


EQLIB_VAR DWORD *g_ppDrawHandler;
#define g_pDrawHandler (*g_ppDrawHandler)

EQLIB_VAR PCHAR *EQMappableCommandList;
EQLIB_VAR DWORD gnNormalEQMappableCommands;

#ifndef ISXEQ
EQLIB_VAR DWORD EQADDR_DIMAIN;
EQLIB_VAR IDirectInputDevice8A **EQADDR_DIKEYBOARD;
EQLIB_VAR IDirectInputDevice8A **EQADDR_DIMOUSE;
#endif

EQLIB_VAR DWORD EQADDR_EQLABELS;

EQLIB_VAR BOOL gMouseLeftClickInProgress;
EQLIB_VAR BOOL gMouseRightClickInProgress;
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
EQLIB_VAR PCHAR szCombineTypes[];
EQLIB_VAR PCHAR szItemTypes[];

EQLIB_VAR PCHAR szWornLoc[];


EQLIB_VAR fEQCommand         cmdHelp;
EQLIB_VAR fEQCommand         cmdWho;
EQLIB_VAR fEQCommand         cmdWhoTarget;
EQLIB_VAR fEQCommand         cmdLocation;
EQLIB_VAR fEQCommand         cmdFace;
EQLIB_VAR fEQCommand         cmdTarget;
EQLIB_VAR fEQCommand         cmdCharInfo;
EQLIB_VAR fEQCommand         cmdFilter;
EQLIB_VAR fEQCommand         cmdDoAbility;
EQLIB_VAR fEQCommand         cmdCast;


EQLIB_VAR fEQNewUIINI        NewUIINI;
EQLIB_VAR fEQProcGameEvts    ProcessGameEvents;
EQLIB_VAR fEQSendMessage     send_message;
EQLIB_VAR fEQExecuteCmd		 ExecuteCmd;
EQLIB_VAR fEQGetMelee    get_melee_range;

EQLIB_VAR PCHAR szItemName[];
EQLIB_VAR PCHAR szItemName4xx[];
//EQLIB_VAR PCHAR szTheme[]; 
EQLIB_VAR PCHAR szDmgBonusType[];
EQLIB_VAR PCHAR szBodyType[];
EQLIB_VAR PCHAR szAugRestrictions[];
EQLIB_VAR PCHAR szItemSlot[];

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

EQLIB_VAR PALIAS pAliases;
EQLIB_VAR PSUB pSubs;
EQLIB_VAR PMQCOMMAND pCommands;
EQLIB_VAR PMQPLUGIN pPlugins;
EQLIB_VAR PMQXMLFILE pXMLFiles;

EQLIB_VAR fGetLabelFromEQ GetLabelFromEQ;

EQLIB_VAR map<string,PSPAWNINFO> SpawnByName;
EQLIB_VAR EQPlayer **ppEQP_IDArray;
EQLIB_VAR MQRANK EQP_DistArray[3000];
EQLIB_VAR DWORD gSpawnCount;
//#define ppEQP_IDArray (*pppEQP_IDArray)

EQLIB_VAR StringTable **ppStringTable;
#define pStringTable (*ppStringTable)

EQLIB_VAR CDBStr **ppCDBStr;
#define pCDBStr (*ppCDBStr)

EQLIB_VAR CEverQuest **ppEverQuest;
#define pEverQuest (*ppEverQuest)
EQLIB_VAR CDisplay **ppDisplay;
#define pDisplay (*ppDisplay)
EQLIB_VAR EQ_PC **ppPCData;
#define pPCData (*ppPCData)
EQLIB_VAR EQ_Character **ppCharData;
#define pCharData (*ppCharData)
#define pCharData1 ((EQ_Character1 *)(((char *)(*ppCharData))+0xc280))
EQLIB_VAR EQPlayer **ppCharSpawn;
#define pCharSpawn (*ppCharSpawn)
EQLIB_VAR EQPlayer **ppActiveMerchant;
#define pActiveMerchant (*ppActiveMerchant)
EQLIB_VAR EQPlayer **ppSpawnList;
#define pSpawnList (*ppSpawnList)

EQLIB_VAR EQPlayer **ppLocalPlayer;
#define pLocalPlayer (*ppLocalPlayer)
EQLIB_VAR EQPlayer **ppControlledPlayer;
#define pControlledPlayer (*ppControlledPlayer)



EQLIB_VAR EQWorldData **ppWorldData;
#define pWorldData (*ppWorldData)
EQLIB_VAR SpellManager **ppSpellMgr;
#define pSpellMgr (*ppSpellMgr)
EQLIB_VAR CInvSlot **ppSelectedItem;
#define pSelectedItem (*ppSelectedItem)
EQLIB_VAR EQGROUP *pGroup;
EQLIB_VAR EQPlayer **ppTarget;
#define pTarget (*ppTarget)
EQLIB_VAR EqSwitchManager **ppSwitchMgr;
#define pSwitchMgr (*ppSwitchMgr)
EQLIB_VAR EQItemList **ppItemList;
#define pItemList (*ppItemList)
EQLIB_VAR EQZoneInfo *pZoneInfo;
EQLIB_VAR PGUILDS pGuildList;
EQLIB_VAR PEQSOCIAL   pSocialList;

EQLIB_VAR PBYTE pgHotkeyPage;
#define gHotkeyPage (*pgHotkeyPage)

EQLIB_VAR EQPlayer **ppTradeTarget;
#define pTradeTarget (*ppTradeTarget)
EQLIB_VAR EQPlayer **ppActiveBanker;
#define pActiveBanker (*ppActiveBanker)
EQLIB_VAR EQPlayer **ppActiveGMaster;
#define pActiveGMaster (*ppActiveGMaster)
EQLIB_VAR EQPlayer **ppActiveCorpse;
#define pActiveCorpse (*ppActiveCorpse)

EQLIB_VAR CSidlManager **ppSidlMgr;
#define pSidlMgr (*ppSidlMgr)

EQLIB_VAR CXWndManager **ppWndMgr;
#define pWndMgr (*ppWndMgr)

EQLIB_VAR KeypressHandler **ppKeypressHandler;
#define pKeypressHandler (*ppKeypressHandler)

EQLIB_VAR PEQRAID pRaid;

EQLIB_VAR PINT pgCurrentSocial;
#define gCurrentSocial (*pgCurrentSocial)

EQLIB_VAR DWORD *pScreenX;
#define ScreenX (*pScreenX)
EQLIB_VAR DWORD *pScreenY;
#define ScreenY (*pScreenY)
EQLIB_VAR DWORD *pScreenMode;
#define ScreenMode (*pScreenMode)
EQLIB_VAR CHAR  *pMouseLook;
#define bMouseLook (*pMouseLook)

EQLIB_VAR SPELLFAVORITE *pSpellSets;
EQLIB_VAR AltAdvManager** ppAltAdvManager;
#define pAltAdvManager (*ppAltAdvManager)

/* WINDOW INSTANCES */ 
EQLIB_VAR CContextMenuManager **ppContextMenuManager;
EQLIB_VAR CCursorAttachment **ppCursorAttachment;
EQLIB_VAR CSocialEditWnd **ppSocialEditWnd;
EQLIB_VAR CContainerMgr **ppContainerMgr;
EQLIB_VAR CChatManager **ppChatManager;
EQLIB_VAR CConfirmationDialog **ppConfirmationDialog;
EQLIB_VAR CFacePick **ppFacePick;
EQLIB_VAR CInvSlotMgr **ppInvSlotMgr;
//EQLIB_VAR CPopupWndManager **ppPopupWndManager;
EQLIB_VAR CNoteWnd **ppNoteWnd;
EQLIB_VAR CHelpWnd **ppHelpWnd;
EQLIB_VAR CTipWnd **ppTipWnd;
EQLIB_VAR CTipWnd **ppTipWnd;
EQLIB_VAR CBookWnd **ppBookWnd;
EQLIB_VAR CFriendsWnd **ppFriendsWnd;
EQLIB_VAR CMusicPlayerWnd **ppMusicPlayerWnd;
EQLIB_VAR CAlarmWnd **ppAlarmWnd;
EQLIB_VAR CLoadskinWnd **ppLoadskinWnd;
EQLIB_VAR CPetInfoWnd **ppPetInfoWnd;
EQLIB_VAR CTrainWnd **ppTrainWnd;
EQLIB_VAR CSkillsWnd **ppSkillsWnd;
EQLIB_VAR CSkillsSelectWnd **ppSkillsSelectWnd;
//EQLIB_VAR CCombatSkillSelectWnd **ppCombatSkillSelectWnd;
EQLIB_VAR CAAWnd **ppAAWnd;
EQLIB_VAR CGroupWnd **ppGroupWnd;
//EQLIB_VAR CSystemInfoDialogBox **ppSystemInfoDialogBox;
EQLIB_VAR CGroupSearchWnd **ppGroupSearchWnd;
EQLIB_VAR CGroupSearchFiltersWnd **ppGroupSearchFiltersWnd;
EQLIB_VAR CRaidWnd **ppRaidWnd;
EQLIB_VAR CRaidOptionsWnd **ppRaidOptionsWnd;
EQLIB_VAR CBreathWnd **ppBreathWnd;
EQLIB_VAR CMapToolbarWnd **ppMapToolbarWnd;
EQLIB_VAR CMapViewWnd **ppMapViewWnd;
EQLIB_VAR CEditLabelWnd **ppEditLabelWnd;
EQLIB_VAR COptionsWnd **ppOptionsWnd;
EQLIB_VAR CBuffWindow **ppBuffWindow;
EQLIB_VAR CBuffWindow **ppBuffWindow;
EQLIB_VAR CTargetWnd **ppTargetWnd;
EQLIB_VAR CColorPickerWnd **ppColorPickerWnd;
EQLIB_VAR CHotButtonWnd **ppHotButtonWnd;
EQLIB_VAR CPlayerWnd **ppPlayerWnd;
EQLIB_VAR CCastingWnd **ppCastingWnd;
EQLIB_VAR CCastSpellWnd **ppCastSpellWnd;
EQLIB_VAR CSpellBookWnd **ppSpellBookWnd;
EQLIB_VAR CInventoryWnd **ppInventoryWnd;
EQLIB_VAR CBankWnd **ppBankWnd;
EQLIB_VAR CQuantityWnd **ppQuantityWnd;
EQLIB_VAR CTextEntryWnd **ppTextEntryWnd;
EQLIB_VAR CFileSelectionWnd **ppFileSelectionWnd;
EQLIB_VAR CLootWnd **ppLootWnd;
EQLIB_VAR CPetInfoWnd **ppPetInfoWnd;
EQLIB_VAR CActionsWnd **ppActionsWnd;
//EQLIB_VAR CCombatAbilityWnd **ppCombatAbilityWnd;
EQLIB_VAR CMerchantWnd **ppMerchantWnd;
EQLIB_VAR CTradeWnd **ppTradeWnd;
EQLIB_VAR CBazaarWnd **ppBazaarWnd;
EQLIB_VAR CBazaarSearchWnd **ppBazaarSearchWnd;
EQLIB_VAR CGiveWnd **ppGiveWnd;
EQLIB_VAR CSelectorWnd **ppSelectorWnd;
EQLIB_VAR CTrackingWnd **ppTrackingWnd;
EQLIB_VAR CInspectWnd **ppInspectWnd;
EQLIB_VAR CFeedbackWnd **ppFeedbackWnd;
EQLIB_VAR CBugReportWnd **ppBugReportWnd;
EQLIB_VAR CVideoModesWnd **ppVideoModesWnd;
EQLIB_VAR CCompassWnd **ppCompassWnd;
EQLIB_VAR CPlayerNotesWnd **ppPlayerNotesWnd;
EQLIB_VAR CGemsGameWnd **ppGemsGameWnd;
EQLIB_VAR CStoryWnd **ppStoryWnd;
//EQLIB_VAR CFindLocationWnd **ppFindLocationWnd;
//EQLIB_VAR CAdventureRequestWnd **ppAdventureRequestWnd;
//EQLIB_VAR CAdventureMerchantWnd **ppAdventureMerchantWnd;
//EQLIB_VAR CAdventureStatsWnd **ppAdventureStatsWnd;
//EQLIB_VAR CAdventureLeaderboardWnd **ppAdventureLeaderboardWnd;
//EQLIB_VAR CLeadershipWindow **ppLeadershipWindow;
EQLIB_VAR CBodyTintWnd **ppBodyTintWnd;
EQLIB_VAR CGuildMgmtWnd **ppGuildMgmtWnd;
EQLIB_VAR CJournalTextWnd **ppJournalTextWnd;
EQLIB_VAR CJournalCatWnd **ppJournalCatWnd;
//EQLIB_VAR CTributeBenefitWnd **ppTributeBenefitWnd;
//EQLIB_VAR CTributeMasterWnd **ppTributeMasterWnd;
EQLIB_VAR CPetitionQWnd **ppPetitionQWnd;
EQLIB_VAR CSoulmarkWnd **ppSoulmarkWnd;
EQLIB_VAR CTimeLeftWnd **ppTimeLeftWnd;
EQLIB_VAR CTextOverlay **ppTextOverlay;


#define pContextMenuManager (*ppContextMenuManager)
#define pCursorAttachment (*ppCursorAttachment)
#define pSocialEditWnd (*ppSocialEditWnd)
#define pContainerMgr (*ppContainerMgr)
#define pChatManager (*ppChatManager)
#define pConfirmationDialog (*ppConfirmationDialog)
#define pFacePick (*ppFacePick)
#define pInvSlotMgr (*ppInvSlotMgr)
#define pPopupWndManager (*ppPopupWndManager)
#define pNoteWnd (*ppNoteWnd)
#define pHelpWnd (*ppHelpWnd)
#define pTipWnd (*ppTipWnd)
#define pTipWnd (*ppTipWnd)
#define pBookWnd (*ppBookWnd)
#define pFriendsWnd (*ppFriendsWnd)
#define pMusicPlayerWnd (*ppMusicPlayerWnd)
#define pAlarmWnd (*ppAlarmWnd)
#define pLoadskinWnd (*ppLoadskinWnd)
#define pPetInfoWnd (*ppPetInfoWnd)
#define pTrainWnd (*ppTrainWnd)
#define pSkillsWnd (*ppSkillsWnd)
#define pSkillsSelectWnd (*ppSkillsSelectWnd)
#define pCombatSkillSelectWnd (*ppCombatSkillSelectWnd)
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
#define pBuffWindow (*ppBuffWindow)
#define pBuffWindow (*ppBuffWindow)
#define pTargetWnd (*ppTargetWnd)
#define pColorPickerWnd (*ppColorPickerWnd)
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
#define pPetInfoWnd (*ppPetInfoWnd)
#define pActionsWnd (*ppActionsWnd)
#define pCombatAbilityWnd (*ppCombatAbilityWnd)
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
#define pFindLocationWnd (*ppFindLocationWnd)
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
#define pSoulmarkWnd (*ppSoulmarkWnd)
#define pTimeLeftWnd (*ppTimeLeftWnd)
#define pTextOverlay (*ppTextOverlay)

/*
#define pContextMenuManager (*ppContextMenuManager)
#define pCursorAttachment (*ppCursorAttachment)
#define pSocialEditWnd (*ppSocialEditWnd)
#define pInvSlotMgr (*ppInvSlotMgr)
#define pContainerMgr (*ppContainerMgr)
#define pChatManager (*ppChatManager)
#define pConfirmationDialog (*ppConfirmationDialog)
#define pFacePick (*ppFacePick)
#define pItemDisplayMgr (*ppItemDisplayMgr)
#define pSpellDisplayMgr (*ppSpellDisplayMgr)
#define pNoteWnd (*ppNoteWnd)
#define pHelpWnd (*ppHelpWnd)
#define pTipWnd (*ppTipWnd)
#define pTipWnd (*ppTipWnd)
#define pBookWnd (*ppBookWnd)
#define pFriendsWnd (*ppFriendsWnd)
#define pMusicPlayerWnd (*ppMusicPlayerWnd)
#define pAlarmWnd (*ppAlarmWnd)
#define pLoadskinWnd (*ppLoadskinWnd)
#define pPetInfoWnd (*ppPetInfoWnd)
#define pTrainWnd (*ppTrainWnd)
#define pSkillsWnd (*ppSkillsWnd)
#define pSkillsSelectWnd (*ppSkillsSelectWnd)
#define pAAWnd (*ppAAWnd)
#define pGroupWnd (*ppGroupWnd)
#define pJournalNPCWnd (*ppJournalNPCWnd)
#define pGroupSearchWnd (*ppGroupSearchWnd)
#define pGroupSearchFiltersWnd (*ppGroupSearchFiltersWnd)
#define pRaidWnd (*ppRaidWnd)
#define pRaidOptionsWnd (*ppRaidOptionsWnd)
#define pBreathWnd (*ppBreathWnd)
#define pMapToolbarWnd (*ppMapToolbarWnd)
#define pMapViewWnd (*ppMapViewWnd)
#define pEditLabelWnd (*ppEditLabelWnd)
#define pOptionsWnd (*ppOptionsWnd)
#define pBuffWindow (*ppBuffWindow)
#define pBuffWindow (*ppBuffWindow)
#define pTargetWnd (*ppTargetWnd)
#define pColorPickerWnd (*ppColorPickerWnd)
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
#define pFindLocationWnd (*ppFindLocationWnd)
#define pAdventureRequestWnd (*ppAdventureRequestWnd)
#define pAdventureStatsWnd (*ppAdventureStatsWnd)
#define pAdventureLeaderboardWnd (*ppAdventureLeaderboardWnd)
#define pBodyTintWnd (*ppBodyTintWnd)
#define pGuildMgmtWnd (*ppGuildMgmtWnd)
#define pJournalTextWnd (*ppJournalTextWnd)
#define pJournalCatWnd (*ppJournalCatWnd)
#define pPetitionQWnd (*ppPetitionQWnd)
#define pSoulmarkWnd (*ppSoulmarkWnd)
#define pTimeLeftWnd (*ppTimeLeftWnd)
/**/
}
using namespace MQ2Globals;


