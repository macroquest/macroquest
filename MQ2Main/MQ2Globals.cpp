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

// Exclude rarely-used stuff from Windows headers
#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT 0x510
#define DIRECTINPUT_VERSION 0x800

#include "MQ2Main.h"

namespace MQ2Globals
{
	DWORD baseAddress = (DWORD)GetModuleHandle(NULL);
	bool InitOffsets()
	{
		if (!EQGameBaseAddress)
		{
			return false;
		}

		EQADDR_HWND = __HWnd;
		EQADDR_MEMCHECK0 = __MemChecker0;
		EQADDR_MEMCHECK1 = __MemChecker1;
		EQADDR_MEMCHECK2 = __MemChecker2;
		EQADDR_MEMCHECK3 = __MemChecker3;
		EQADDR_MEMCHECK4 = __MemChecker4;
		EQADDR_SERVERHOST = (PCHAR)__ServerHost;
		EQADDR_SERVERNAME = (PCHAR)__ServerName;
		EQADDR_CONVERTITEMTAGS = __ConvertItemTags;
		EQADDR_CMDLIST = (PCMDLIST)__CommandList;

		EQADDR_ATTACK = (PBYTE)__Attack;
		EQADDR_NOTINCHATMODE = (PBYTE)__InChatMode;
		EQADDR_RUNWALKSTATE = (PBYTE)__RunWalkState;
		EQADDR_LASTTELL = (PCHAR)__LastTell;
		EQADDR_ZONETYPE = (PBYTE)__ZoneType;
		gbUseTellWindows = *(BOOL*)__UseTellWindows;
		gpbRangedAttackReady = (PCHAR)__RangeAttackReady;
		ppCResolutionHandler = (CResolutionHandler**)pinstCResolutionHandler;
		gpbShowNetStatus = (PCHAR)__NetStatusToggle;
		g_ppDrawHandler = (DWORD*)__DrawHandler;
		gpShowNames = (DWORD*)__ShowNames;
		EQADDR_SUBSCRIPTIONTYPE = (PDWORD)__SubscriptionType;
		EQADDR_GROUPAGGRO = (DWORD)__GroupAggro;
		EQADDR_TARGETAGGROHOLDER = (PCHAR)__TargetAggroHolder;
		gpPCNames = (DWORD*)__PCNames;
		pTributeActive = (PBYTE)instTributeActive;
		gpAutoFire = (PBYTE)__Autofire;
		gpAutoSkill = (PAUTOSKILL)__AutoSkillArray;
		gpShiftKeyDown = (PBYTE)__ShiftKeyDown; // addr+1=ctrl, addr+2=alt
		gpMouseEventTime = (DWORD*)__MouseEventTime;
		gpbCommandEvent = (DWORD*)__gpbCommandEvent;

		EQADDR_GWORLD = (PVOID)__gWorld;
		EQADDR_DOABILITYLIST = (PDWORD)__DoAbilityList;

		ppCurrentMapLabel = (PMAPLABEL*)__CurrentMapLabel;
		EQMappableCommandList = (PCHAR*)__BindList;
		EQbCommandStates = (PBYTE)g_eqCommandStates;

		EQADDR_ENCRYPTPAD0 = (PBYTE)__EncryptPad0;
		EQADDR_ENCRYPTPAD1 = (PBYTE)__EncryptPad1;
		EQADDR_ENCRYPTPAD2 = (PBYTE)__EncryptPad2;
		EQADDR_ENCRYPTPAD3 = (PBYTE)__EncryptPad3;
		EQADDR_ENCRYPTPAD4 = (PBYTE)__EncryptPad4;

		pScreenX = (DWORD*)__ScreenX;
		pScreenY = (DWORD*)__ScreenY;
		pScreenXMax = (DWORD*)__ScreenXMax;
		pScreenYMax = (DWORD*)__ScreenYMax;
		pScreenMode = (DWORD*)__ScreenMode;
		pMouseLook = (char*)__MouseLook;
		EQADDR_MOUSE = (PMOUSEINFO)__Mouse;
		EQADDR_MOUSECLICK = (PMOUSECLICK)__Clicks;

		EQADDR_DIMAIN = DI8__Main;
		EQADDR_DIKEYBOARD = (IDirectInputDevice8A**)DI8__Keyboard;
		EQADDR_DIMOUSE = (IDirectInputDevice8A**)DI8__Mouse;
		EQADDR_DIMOUSECOPY = (PPOINT)DI8__Mouse_Copy;
		EQADDR_DIMOUSECHECK = (PPOINT)DI8__Mouse_Check;


		pGuildList = (PGUILDS)__Guilds;
		pSocialList = (PEQSOCIAL)__Socials;
		pgCurrentSocial = (PINT)__CurrentSocial;

		NewUIINI = (fEQNewUIINI)__NewUIINI;
		ProcessGameEvents = (fEQProcGameEvts)__ProcessGameEvents;
		GetLabelFromEQ = (fGetLabelFromEQ)__GetLabelFromEQ;
		ppStringTable = (StringTable**)pinstStringTable;
		ppCDBStr = (CDBStr**)pinstCDBStr;
		pEQMisc = (EQMisc*)instEQMisc;
		ppCSkillMgr = (CSkillMgr**)pinstSkillMgr;
		pGuild = (CGuild*)__Guilds;
		ppSkillMgr = (SKILLMGR**)pinstSkillMgr;

		pEverQuestInfo = (PEVERQUESTINFO)pinstEverQuestInfo;
		ppEverQuest = (CEverQuest**)pinstCEverQuest;
		ppDisplay = (CDisplay**)pinstCDisplay;
		ppPCData = (EQ_PC**)pinstPCData;
		ppCharData = (EQ_Character**)pinstCharData;
		ppCharSpawn = (PlayerClient**)pinstCharSpawn;
		ppActiveMerchant = (PlayerClient**)pinstActiveMerchant;
		ppSpawnManager = (PlayerManagerClient**)pinstSpawnManager;
		ppLocalPlayer = (PlayerClient**)pinstLocalPlayer;
		ppControlledPlayer = (PlayerClient**)pinstControlledPlayer;
		ppWorldData = (EQWorldData**)pinstWorldData;
		ppSpellMgr = (ClientSpellManager**)pinstSpellManager;
		ppTarget = (PlayerClient**)pinstTarget;
		ppSwitchMgr = (EqSwitchManager**)pinstSwitchManager;
		pSpellSets = (SPELLFAVORITE*)pinstSpellSets;
		pZoneInfo = (EQZoneInfo*)instEQZoneInfo;
		ppAltAdvManager = (AltAdvManager**)pinstAltAdvManager;
		ppConnection = (connection_t**)__gWorld;
		ppAuraWnd = (CAuraWnd**)pinstCAuraWnd;
		ppLootFiltersManager = (LootFiltersManager**)pinstLootFiltersManager;

		ppTradeTarget = (PlayerClient**)pinstTradeTarget;
		ppActiveBanker = (PlayerClient **)pinstActiveBanker;
		ppActiveGMaster = (PlayerClient **)pinstActiveGMaster;
		ppActiveCorpse = (PlayerClient **)pinstActiveCorpse;

		ppContextMenuManager = (CContextMenuManager**)pinstCContextMenuManager;
		ppCursorAttachment = (CCursorAttachment**)pinstCCursorAttachment;
		ppSocialEditWnd = (CSocialEditWnd**)pinstCSocialEditWnd;
		ppContainerMgr = (CContainerMgr**)pinstCContainerMgr;
		ppChatManager = (CChatWindowManager**)pinstCChatWindowManager;
		ppFacePick = (CFacePick * *)pinstCFacePick;
		ppFactionWnd = (CFactionWnd**)pinstCFactionWnd;
		ppFindItemWnd = (CFindItemWnd**)pinstCFindItemWnd;

		ppExtendedTargetWnd = (CExtendedTargetWnd**)pinstCExtendedTargetWnd;
		ppFindLocationWnd = (CFindLocationWnd**)pinstCFindLocationWnd;
		ppInvSlotMgr = (CInvSlotMgr**)pinstCInvSlotMgr;
		ppNoteWnd = (CNoteWnd**)pinstCNoteWnd;
		ppBookWnd = (CBookWnd**)pinstCBookWnd;
		ppFriendsWnd = (CFriendsWnd**)pinstCFriendsWnd;
		ppMusicPlayerWnd = (CMusicPlayerWnd**)pinstCMusicPlayerWnd;

		ppRealEstateItemsWnd = (CRealEstateItemsWnd**)pinstCRealEstateItemsWnd;
		ppAchievementsWnd = (CAchievementsWnd**)pinstCAchievementsWnd;
		ppAlarmWnd = (CAlarmWnd**)pinstCAlarmWnd;
		ppLoadskinWnd = (CLoadskinWnd**)pinstCLoadskinWnd;
		ppPetInfoWnd = (CPetInfoWnd**)pinstCPetInfoWnd;
		ppRespawnWnd = (CRespawnWnd**)pinstCRespawnWnd;

		ppTrainWnd = (CTrainWnd**)pinstCTrainWnd;
		ppSkillsWnd = (CSkillsWnd**)pinstCSkillsWnd;
		ppSkillsSelectWnd = (CSkillsSelectWnd**)pinstCSkillsSelectWnd;
		ppAAWnd = (CAAWnd**)pinstCAAWnd;
		ppGroupWnd = (CGroupWnd**)pinstCGroupWnd;
		ppGroupSearchWnd = (CGroupSearchWnd**)pinstCGroupSearchWnd;
		ppGroupSearchFiltersWnd = (CGroupSearchFiltersWnd**)pinstCGroupSearchFiltersWnd;
		ppRaidWnd = (CRaidWnd**)pinstCRaidWnd;
		ppRaidOptionsWnd = (CRaidOptionsWnd**)pinstCRaidOptionsWnd;
		ppBreathWnd = (CBreathWnd**)pinstCBreathWnd;
		ppMapToolbarWnd = (CMapToolbarWnd**)pinstCMapToolbarWnd;
		ppMapViewWnd = (CMapViewWnd**)pinstCMapViewWnd;
		ppEditLabelWnd = (CEditLabelWnd**)pinstCEditLabelWnd;
		ppOptionsWnd = (COptionsWnd**)pinstCOptionsWnd;
		ppBuffWindowSHORT = (CBuffWindow**)pinstCBuffWindowSHORT;
		ppBuffWindowNORMAL = (CBuffWindow**)pinstCBuffWindowNORMAL;
		ppTargetWnd = (CTargetWnd**)pinstCTargetWnd;
		ppColorPickerWnd = (CColorPickerWnd**)pinstCColorPickerWnd;
		ppCombatSkillsSelectWnd = (CCombatSkillsSelectWnd**)pinstCCombatSkillsSelectWnd;
		ppHotButtonWnd = (CHotButtonWnd**)pinstCHotButtonWnd;
		ppPlayerWnd = (CPlayerWnd**)pinstCPlayerWnd;
		ppCastingWnd = (CCastingWnd**)pinstCCastingWnd;
		ppCastSpellWnd = (CCastSpellWnd**)pinstCCastSpellWnd;
		ppSpellBookWnd = (CSpellBookWnd**)pinstCSpellBookWnd;
		ppInventoryWnd = (CInventoryWnd**)pinstCInventoryWnd;
		ppBankWnd = (CBankWnd**)pinstCBankWnd;
		ppQuantityWnd = (CQuantityWnd**)pinstCQuantityWnd;
		ppTextEntryWnd = (CTextEntryWnd**)pinstCTextEntryWnd;
		ppFileSelectionWnd = (CFileSelectionWnd**)pinstCFileSelectionWnd;
		ppLootWnd = (CLootWnd**)pinstCLootWnd;
		ppActionsWnd = (CActionsWnd**)pinstCActionsWnd;
		ppCombatAbilityWnd = (CCombatAbilityWnd**)pinstCCombatAbilityWnd;
		ppMerchantWnd = (CMerchantWnd**)pinstCMerchantWnd;
		ppTradeWnd = (CTradeWnd**)pinstCTradeWnd;
		ppBazaarWnd = (CBazaarWnd**)pinstCBazaarWnd;
		ppBazaarSearchWnd = (CBazaarSearchWnd**)pinstCBazaarSearchWnd;
		ppGiveWnd = (CGiveWnd**)pinstCGiveWnd;
		ppSelectorWnd = (CSelectorWnd**)pinstCSelectorWnd;
		ppTrackingWnd = (CTrackingWnd**)pinstCTrackingWnd;
		ppInspectWnd = (CInspectWnd**)pinstCInspectWnd;
		ppBugReportWnd = (CBugReportWnd**)pinstCBugReportWnd;
		ppVideoModesWnd = (CVideoModesWnd**)pinstCVideoModesWnd;
		ppCompassWnd = (CCompassWnd**)pinstCCompassWnd;
		ppPlayerNotesWnd = (CPlayerNotesWnd**)pinstCPlayerNotesWnd;
		ppGemsGameWnd = (CGemsGameWnd**)pinstCGemsGameWnd;
		ppStoryWnd = (CStoryWnd**)pinstCStoryWnd;
		ppBodyTintWnd = (CBodyTintWnd**)pinstCBodyTintWnd;
		ppGuildMgmtWnd = (CGuildMgmtWnd**)pinstCGuildMgmtWnd;
		ppJournalTextWnd = (CJournalTextWnd**)pinstCJournalTextWnd;
		ppJournalCatWnd = (CJournalCatWnd**)pinstCJournalCatWnd;
		ppPetitionQWnd = (CPetitionQWnd**)pinstCPetitionQWnd;
		ppCWebManager = (CWebManager**)pinstCWebManager;
		ppTaskWnd = (CTaskWnd**)pinstCTaskWnd;
		ppTaskManager = (CTaskManager*)pinstCTaskManager;
		ppTimeLeftWnd = (CTimeLeftWnd**)pinstCTimeLeftWnd;
		ppAdvancedLootWnd = (CAdvancedLootWnd**)pinstCAdvancedLootWnd;
		ppBandolierWnd = (CBandolierWnd**)pinstCBandolierWnd;
		ppRewardSelectionWnd = (CRewardSelectionWnd**)pinstRewardSelectionWnd;
		ppConfirmationDialog = (CConfirmationDialog**)pinstCConfirmationDialog;
		ppEQSuiteTextureLoader = (CEQSuiteTextureLoader*)pinstEQSuiteTextureLoader;
		ppCZoneGuideWnd = (CZoneGuideWnd**)pinstCZoneGuideWnd;
		ppSidlMgr = (CSidlManager**)pinstCSidlManager;
		ppWndMgr = (CXWndManager**)pinstCXWndManager;
		pRaid = (PEQRAID)instCRaid;
		ppDZMember = (DZMEMBER**)pinstDZMember;
		ppDZTimerInfo = (DZTIMERINFO**)pinstDZTimerInfo;
		ppTaskMember = (TASKMEMBER**)pinstTaskMember;
		pDynamicZone = (DYNAMICZONE*)instDynamicZone;
		ppMercInfo = (MERCENARYINFO**)pinstMercenaryData;
		ppEQSpellStrings = (EQSpellStrings**)pinstEQSpellStrings;
		ppLargeDialog = (CLargeDialogWnd**)pinstCLargeDialogWnd;
		ppItemDisplayManager = (CItemDisplayManager**)pinstCItemDisplayManager;
		ppEqSoundManager = (EqSoundManager**)pinstEQSoundManager;

		return true;
	}

	/* SpellMap */
	HANDLE ghLockSpellMap = nullptr;

	/* PickZone */
	HANDLE ghLockPickZone = nullptr;
	HANDLE ghLockDelayCommand = nullptr;
	HANDLE ghInitializeMQ2SpellDb = nullptr;
	HANDLE ghCCommandLock = nullptr;
	HANDLE ghVariableLock = nullptr;
	HANDLE ghMacroBlockLock = nullptr;
	HANDLE ghGetClassMemberLock = nullptr;

	/* BENCHMARKS */
	DWORD bmWriteChatColor = 0;
	DWORD bmPluginsIncomingChat = 0;
	DWORD bmPluginsPulse = 0;
	DWORD bmPluginsOnZoned = 0;
	DWORD bmPluginsCleanUI = 0;
	DWORD bmPluginsReloadUI = 0;
	DWORD bmPluginsDrawHUD = 0;
	DWORD bmPluginsSetGameState = 0;
	DWORD bmParseMacroParameter = 0;
	DWORD bmUpdateSpawnSort = 0;
	DWORD bmUpdateSpawnCaptions = 0;
	DWORD bmCalculate = 0;
	DWORD bmBeginZone = 0;
	DWORD bmEndZone = 0;

	PDATAVAR pGlobalVariables = nullptr;
	PDATAVAR pMacroVariables = nullptr;

	ePVPServer PVPServer = PVP_NONE;
	DWORD gdwLocalPlayer = pinstLocalPlayer_x;
	char gszVersion[32] = VersionString;
	char gszTime[32] = TimeString;

#if defined(TEST)
	int gBuild = 2;               // TEST
#else
	int gBuild = 1;               // LIVE
#endif

	bool g_bDoingModuleChecks = false;
	DWORD gGameState = 0;
	DWORD gMaxSpawnCaptions = 30;
	BOOL gMQCaptions = TRUE;
	BOOL gAnonymize = FALSE;
	DWORD gAnonymizeFlag = 0;
	DWORD ThreadID = 0;
	BOOL g_Loaded = FALSE;

	BOOL gStringTableFixed = FALSE;
	PCHATBUF gDelayedCommands = 0;

	HMODULE ghModule = nullptr;
	HINSTANCE ghInstance = nullptr;
	HWND ghInjectorWnd = nullptr;
	//PHOTKEY pHotkey = nullptr;
	BOOL gbUnload = FALSE;
	bool gBindInProgress = false;
	BOOL gbLoad = TRUE;
	DWORD gpHook = 0;
	HMODULE ghmq2ic = nullptr;
	PMACROBLOCK gMacroBlock = nullptr;
	int BlockIndex = 0;
	PMACROSTACK gMacroStack = nullptr;
	decltype(gMacroSubLookupMap) gMacroSubLookupMap;
	decltype(gUndeclaredVars) gUndeclaredVars;
	PEVENTQUEUE gEventQueue = nullptr;
	int gEventFunc[NUM_EVENTS] = { 0 };
	UCHAR gLastFind = 0;
	double gZFilter = 10000.0f;
	double gFaceAngle = 10000.0f;
	double gLookAngle = 10000.0f;
	BOOL gbSpelldbLoaded = 0;
	char gszEQPath[MAX_STRING] = { 0 };
	char gszMacroPath[MAX_STRING] = { 0 };
	char gszLogPath[MAX_STRING] = { 0 };
	char gszINIPath[MAX_STRING] = { 0 };
	char gszINIFilename[MAX_STRING] = { 0 };
	char gszItemDB[MAX_STRING] = { 0 };
	char gszMacroName[MAX_STRING] = { 0 };
	char szLastCommand[MAX_STRING] = { 0 };

	char gszLastNormalError[MAX_STRING] = { 0 };
	char gszLastSyntaxError[MAX_STRING] = { 0 };
	char gszLastMQ2DataError[MAX_STRING] = { 0 };

	PSPAWNINFO pNamingSpawn = 0;
	char gszSpawnPlayerName[8][MAX_STRING] = {
		"",//0
		"${If[${NamingSpawn.Mark},\"${NamingSpawn.Mark} - \",]}${If[${NamingSpawn.Trader},\"Trader \",]}${If[${NamingSpawn.Invis},(${NamingSpawn.DisplayName}),${NamingSpawn.DisplayName}]}${If[${NamingSpawn.AFK},\" AFK\",]}${If[${NamingSpawn.Linkdead},\" LD\",]}${If[${NamingSpawn.LFG},\" LFG\",]}${If[${NamingSpawn.GroupLeader},\" LDR\",]}",//1
		"${If[${NamingSpawn.Mark},\"${NamingSpawn.Mark} - \",]}${If[${NamingSpawn.Trader},\"Trader \",]}${If[${NamingSpawn.Invis},(${NamingSpawn.DisplayName}),${NamingSpawn.DisplayName}]}${If[${NamingSpawn.Surname.Length},\" ${NamingSpawn.Surname}\",]}${If[${NamingSpawn.AFK},\" AFK\",]}${If[${NamingSpawn.Linkdead},\" LD\",]}${If[${NamingSpawn.LFG},\" LFG\",]}${If[${NamingSpawn.GroupLeader},\" LDR\",]}",//2
		"${If[${NamingSpawn.Mark},\"${NamingSpawn.Mark} - \",]}${If[${NamingSpawn.Trader},\"Trader \",]}${If[${NamingSpawn.Invis},(${NamingSpawn.DisplayName}),${NamingSpawn.DisplayName}]}${If[${NamingSpawn.Surname.Length},\" ${NamingSpawn.Surname}\",]}${If[${NamingSpawn.AFK},\" AFK\",]}${If[${NamingSpawn.Linkdead},\" LD\",]}${If[${NamingSpawn.LFG},\" LFG\",]}${If[${NamingSpawn.GroupLeader},\" LDR\",]}${If[${NamingSpawn.Guild.Length},\n<${If[${NamingSpawn.GuildStatus.NotEqual[member]},\"${NamingSpawn.GuildStatus} of \",]}${NamingSpawn.Guild}>,]}",//3
		"${If[${NamingSpawn.Mark},\"${NamingSpawn.Mark} - \",]}${If[${NamingSpawn.Trader},\"Trader \",]}${If[${NamingSpawn.AARank},\"${NamingSpawn.AATitle} \",]}${If[${NamingSpawn.Invis},(${NamingSpawn.DisplayName}),${NamingSpawn.DisplayName}]}${If[${NamingSpawn.Surname.Length},\" ${NamingSpawn.Surname}\",]}${If[${NamingSpawn.Suffix.Length},\" ${NamingSpawn.Suffix}\",]}${If[${NamingSpawn.AFK},\" AFK\",]}${If[${NamingSpawn.Linkdead},\" LD\",]}${If[${NamingSpawn.LFG},\" LFG\",]}${If[${NamingSpawn.GroupLeader},\" LDR\",]}${If[${NamingSpawn.Guild.Length},\n<${If[${NamingSpawn.GuildStatus.NotEqual[member]},\"${NamingSpawn.GuildStatus} of \",]}${NamingSpawn.Guild}>,]}",//4
		"${If[${NamingSpawn.Mark},\"${NamingSpawn.Mark} - \",]}${If[${NamingSpawn.Trader},\"Trader \",]}${If[${NamingSpawn.AARank},\"${NamingSpawn.AATitle} \",]}${If[${NamingSpawn.Invis},(${NamingSpawn.DisplayName}),${NamingSpawn.DisplayName}]}${If[${NamingSpawn.Suffix.Length},\" ${NamingSpawn.Suffix}\",]}${If[${NamingSpawn.AFK},\" AFK\",]}${If[${NamingSpawn.Linkdead},\" LD\",]}${If[${NamingSpawn.LFG},\" LFG\",]}${If[${NamingSpawn.GroupLeader},\" LDR\",]}",//5
		"${If[${NamingSpawn.Mark},\"${NamingSpawn.Mark} - \",]}${If[${NamingSpawn.Trader},\"Trader \",]}${If[${NamingSpawn.AARank},\"${NamingSpawn.AATitle} \",]}${If[${NamingSpawn.Invis},(${NamingSpawn.DisplayName}),${NamingSpawn.DisplayName}]}${If[${NamingSpawn.Surname.Length},\" ${NamingSpawn.Surname}\",]}${If[${NamingSpawn.Suffix.Length},\" ${NamingSpawn.Suffix}\",]}${If[${NamingSpawn.AFK},\" AFK\",]}${If[${NamingSpawn.Linkdead},\" LD\",]}${If[${NamingSpawn.LFG},\" LFG\",]}${If[${NamingSpawn.GroupLeader},\" LDR\",]}",//6 
	};
	char gszSpawnNPCName[MAX_STRING] = "${If[${NamingSpawn.Mark},\"${NamingSpawn.Mark} - \",]}${If[${NamingSpawn.Assist},\">> \",]}${NamingSpawn.DisplayName}${If[${NamingSpawn.Assist},\" - ${NamingSpawn.PctHPs}%<<\",]}${If[${NamingSpawn.Surname.Length},\n(${NamingSpawn.Surname}),]}";
	char gszSpawnPetName[MAX_STRING] = "${If[${NamingSpawn.Mark},\"${NamingSpawn.Mark} - \",]}${If[${NamingSpawn.Assist},\">> \",]}${NamingSpawn.DisplayName}${If[${NamingSpawn.Assist},\" - ${NamingSpawn.PctHPs}%<<\",]}${If[${NamingSpawn.Master.Type.Equal[PC]},\n(${NamingSpawn.Master}),]}";
	char gszSpawnCorpseName[MAX_STRING] = "${NamingSpawn.DisplayName}'s corpse";
	char gszAnonCaption[MAX_STRING] = "[${NamingSpawn.Level}] ${NamingSpawn.Race} ${NamingSpawn.Class} ${NamingSpawn.Type}";

	DWORD DrawHUDParams[4] = { 0,0,0,0 };

	Blech *pMQ2Blech = nullptr;
	char EventMsg[MAX_STRING] = { 0 };
	Blech *pEventBlech = nullptr;
	PEVENTLIST pEventList = nullptr;

	DWORD gEventChat = 0;
	ULONGLONG gRunning = 0;
	BOOL gbMoving = FALSE;
	DWORD gMaxTurbo = 80;
	DWORD gTurboLimit = 240;
	BOOL gReturn = TRUE;
	BOOL gInClick = FALSE;
	DWORD gbAssistComplete = 0;
	BOOL gTargetbuffs = FALSE;
	BOOL gItemsReceived = FALSE;
	BOOL gbInZone = FALSE;
	BOOL gZoning = FALSE;
	ULONGLONG OldLastEnteredZone = 0;
	ULONGLONG LastEnteredZone = 0;
	BOOL WereWeZoning = TRUE;
	BOOL gbInDInput = FALSE;
	BOOL gbInChat = FALSE;
	BOOL gbInDState = FALSE;
	BOOL gbInDAcquire = FALSE;
	BOOL gFilterSkillsAll = FALSE;
	BOOL gFilterSkillsIncrease = FALSE;
	BOOL gFilterTarget = FALSE;
	BOOL gFilterDebug = FALSE;
	BOOL gFilterMoney = FALSE;
	BOOL gFilterFood = FALSE;
	BOOL gFilterMacro = FALSE;
	BOOL gFilterMQ = FALSE;
	BOOL gFilterEncumber = FALSE;
	BOOL gFilterCustom = TRUE;
	BOOL gSpewToFile = FALSE;
	BOOL gbDoAutoRun = FALSE;
	BOOL gMQPauseOnChat = FALSE;
	BOOL gKeepKeys = FALSE;
	BOOL gLClickedObject = FALSE;
	SWHOFILTER gFilterSWho = { 0 };
	EQLIB_VAR BOOL gFilterMQ2DataErrors = FALSE;
	BOOL gCreateMQ2NewsWindow = TRUE;
	char gIfDelimiter = ',';
	char gIfAltDelimiter = '~';
	DWORD gNetStatusXPos = 0;
	DWORD gNetStatusYPos = 0;
	LONG gStackingDebug = 0;
	BOOL gUseNewNamedTest = 0;
	BOOL gbInForeground = FALSE;

	double DegToRad = 57.295779513082320876846364344191;
	double PI = 3.1415926535;

	PMQTIMER gTimer = nullptr;
	LONG gDelay = 0;
	char gDelayCondition[MAX_STRING] = { 0 };
	BOOL bAllowCommandParse = TRUE;
	LONG gDelayZoning = 0;
	std::map<DWORD, std::list<SEARCHSPAWN>> gAlertMap;

	SPAWNINFO MercenarySpawn = { 0 };
	SPAWNINFO PetSpawn = { 0 };
	SPAWNINFO EnviroTarget = { 0 };
	GROUNDOBJECT GroundObject = { GO_None, { 0 } };
	PGROUNDITEM	pGroundTarget = nullptr;
	SPAWNINFO DoorEnviroTarget = { 0 };
	PDOOR pDoorTarget = nullptr;
	PITEMDB gItemDB = nullptr;
	BOOL bRunNextCommand = FALSE;
	BOOL gTurbo = FALSE;
	BOOL gWarning = FALSE;
	BOOL gknightlyparse = FALSE;
	PDEFINE pDefines = nullptr;
	PBINDLIST pBindList = nullptr;
	char gLastFindSlot[MAX_STRING] = { 0 };
	PFILTER gpFilters = nullptr;

	BOOL g_bInDXMouse = FALSE;
	PMOUSESPOOF gMouseData = { 0 };
	BOOL bDetMouse = TRUE;

	// EQ Functions Initialization
	fEQCommand        cmdHelp = nullptr;
	fEQCommand        cmdWho = nullptr;
	fEQCommand        cmdWhoTarget = nullptr;
	fEQCommand        cmdLocation = nullptr;
	fEQCommand        cmdFace = nullptr;
	fEQCommand        cmdTarget = nullptr;
	fEQCommand        cmdCharInfo = nullptr;
	fEQCommand        cmdFilter = nullptr;
	fEQCommand        cmdDoAbility = nullptr;
	fEQCommand        cmdCast = nullptr;
	fEQCommand        cmdUseItem = nullptr;
	fEQCommand        cmdPet = nullptr;
	fEQCommand        cmdMercSwitch = nullptr;
	fEQCommand        cmdAdvLoot = nullptr;
	fEQCommand        cmdPickZone = nullptr;
	fEQCommand        cmdAssist = nullptr;
	fEQCommand        cmdQuit = nullptr;

	PCHAR szEQMappableCommands[nEQMappableCommands];
	decltype(ItemSlotMap) ItemSlotMap;

	char DataTypeTemp[MAX_STRING] = { 0 };
	cTargetBuff TargetBuffTemp = { 0 };

	decltype(SpawnByName) SpawnByName;
	MQRANK EQP_DistArray[3000];
	DWORD gSpawnCount = 0;

	// Motd and Pulse's mouse variables
	BOOL gMouseClickInProgress[8] = { FALSE };
	// End of mouse variables

	PCHAR gDiKeyName[256];

	PCHAR szHeading[] = {
		"south",                //0
		"south by southeast",   //1
		"southeast",            //2
		"east by southeast",    //3
		"east",                 //4
		"east by northeast",    //5
		"northeast",            //6
		"north by northeast",   //7
		"north",                //8
		"north by northwest",   //9
		"northwest",            //10
		"west by northwest",    //11
		"west",                 //12
		"west by southwest",    //13
		"southwest",            //14
		"south by southwest"    //15
	};

	PCHAR szHeadingShort[] = {
		"S",    //0
		"SSE",  //1
		"SE",   //2
		"ESE",  //3
		"E",    //4
		"ENE",  //5
		"NE",   //6
		"NNE",  //7
		"N",    //8
		"NNW",  //9
		"NW",   //10
		"WNW",  //11
		"W",    //12
		"WSW",  //13
		"SW",   //14
		"SSW"   //15
	};

	PCHAR szHeadingNormal[] = {
		"north",                //0
		"north by northeast",   //1
		"northeast",            //2
		"east by northeast",    //3
		"east",                 //4
		"east by southeast",    //5
		"southeast",            //6
		"south by southeast",   //7
		"south",                //8
		"south by southwest",   //9
		"southwest",            //10
		"west by southwest",    //11
		"west",                 //12
		"west by northwest",    //13
		"northwest",            //14
		"north by northwest"    //15
	};

	PCHAR szHeadingNormalShort[] = {
		"N",    //0
		"NNE",  //1
		"NE",   //2
		"ENE",  //3
		"E",    //4
		"ESE",  //5
		"SE",   //6
		"SSE",  //7
		"S",    //8
		"SSW",  //9
		"SW",   //10
		"WSW",  //11
		"W",    //12
		"WNW",  //13
		"NW",   //14
		"NNW"   //15
	};

	PCHAR szSize[] = {
		"Tiny",
		"Small",
		"Normal",
		"Large",
		"Giant",
		"Huge", //?
		"Unknown" //?
	};

	PCHAR szSpawnType[] = {
		"player",
		"NPC",
		"corpse",
		"any",
		"pet",
		nullptr // SuperWhoTarget
	};

	PCHAR szGuildStatus[] = {
		"",
		"Leader",
		"Senior Officer",
		"Officer",
		"Active Member",
		"Member",
		"Junior Member",
		"Initiate",
		"Recruit",
		nullptr
	};

	PCHAR szGender[] = {
		"male",
		"female",
		"neuter",
		"unknown"
	};

	PCHAR szDeityTeam[] = {
		"none",     //0
		"good",     //1
		"neutral",  //2
		"evil"      //3
	};

	PCHAR szLights[] = {
		"NONE",    // 0  - No light
		"CDL", // 1  - Candle
		"TR",  // 2  - Torch
		"TGS", // 3  - Tiny Glowing Skull
		"SL",  // 4  - Small Lantern
		"SoM", // 5  - Stein of Moggok
		"LL",  // 6  - Large Lantern
		"FL",  // 7  - Flameless lantern, Halo of Light
		"GOS", // 8  - Globe of stars
		"LG",  // 9  - Light Globe
		"LS",  // 10 - Lightstone, Burnt-out lightstone, wispstone
		"GLS", // 11 - Greater lightstone
		"FBE", // 12 - Fire Beatle Eye, Firefly Globe
		"CL"  // 13 - Coldlight
	};

	BYTE LightBrightness[] = {
		0,      //0
		1,      //1
		2,      //2
		3,      //3
		6,      //4
		7,      //5
		8,      //6
		9,      //7
		10,     //8
		0,      //9
		0,      //10
		0,      //11
		4,      //12
		5       //13
	};

	PCHAR szSkills[] = {
#include "EQLib/data/skills.h"
		nullptr
	};

	PCHAR szInnates[] = {
		"Awareness",//c4c
		"Bash Door",//c50
		"Breathe Fire",//c54
		"Harmony",//c58
		"Harm Touch",//c5c
		"Infravision",//c60
		"Lay Hands",//c64
		"Lore",//c68
		"No Bash",//c6c
		"Regeneration",//c70
		"Slam",//c74
		"Surprise",//c78
		"Ultravision",//c7c
		"Inspect",//c80
		"Open",//c84
		nullptr
	};

	PCHAR szZoneExpansionName[] = {
		"Original EQ",              //0
		"Kunark",                   //1
		"Velious",                  //2
		"Luclin",                   //3
		"Planes of Power",          //4
		"Legacy of Ykesha",         //5
		"Lost Dungeons of Norrath", //6
		"Gates of Discord",         //7
		"Omens of War",             //8
		"Dragons of Norrath",       //9
		"Depths of Darkhollow",     //10
		"Prophecy of Ro",           //11
		"Serpent's Spine",          //12
		"Buried Sea",               //13
		"Secrets of Faydwer",       //14
		"Seeds of Destruction",     //15
		"Underfoot",                //16
		"House of Thule",           //17
		"Veil of Alaris",           //18
		"Rain of Fear",             //19
		"Call of the Forsaken",     //20
		"Broken Mirror",            //21
	};

	PCHAR szDmgBonusType[] = {
		"None",
		"Magic",
		"Fire",
		"Cold",
		"Poison",
		"Disease"
	};

	PCHAR szBodyType[] = {
		"Object",//0       (catapults, tents, practice dummies, etc)
		"Humanoid", //1
		"Lycanthrope", //2
		"Undead", //3
		"Giant", //4
		"Construct", //5   (includes confused mutations in ldon, chests as of 9-19-2006)
		"Extraplanar", //6
		"Magical", //7
		"Undead Pet", //8
		"Bane Giant", //9
		"Dain", //10
		"Untargetable", //11
		"Vampyre", //12
		"Atenha Ra", //13
		"Greater Akheva",//14
		"Khati Sha", //15
		"Seru", //16
		"Greig", //17
		"Draz Nurakk", //18
		"Zek", //19
		"Luggald", //20
		"Animal", //21
		"Insect", //22
		"Monster", //23
		"Elemental", //24
		"Plant", //25
		"Dragon", //26
		"Elemental", //27
		"Summoned Creature",//28
		"Puff Dragon",//29
		"Bane Dragon",//30
		"Familiar",//31
		"Proc Pet",//32 (NoCorpseNpc)
		"Cursed",//33  (5 as of 9-19-2006)
		"Muramite",//34
		"*UNKNOWN BODYTYPE 35",
		"*UNKNOWN BODYTYPE 36",
		"*UNKNOWN BODYTYPE 37",
		"*UNKNOWN BODYTYPE 38",
		"*UNKNOWN BODYTYPE 39",
		"*UNKNOWN BODYTYPE 40",
		"*UNKNOWN BODYTYPE 41",
		"*UNKNOWN BODYTYPE 42",
		"*UNKNOWN BODYTYPE 43",
		"*UNKNOWN BODYTYPE 44",
		"*UNKNOWN BODYTYPE 45",
		"*UNKNOWN BODYTYPE 46",
		"*UNKNOWN BODYTYPE 47",
		"*UNKNOWN BODYTYPE 48",
		"*UNKNOWN BODYTYPE 49",
		"*UNKNOWN BODYTYPE 50",
		"*UNKNOWN BODYTYPE 51",
		"*UNKNOWN BODYTYPE 52",
		"*UNKNOWN BODYTYPE 53",
		"*UNKNOWN BODYTYPE 54",
		"*UNKNOWN BODYTYPE 55",
		"*UNKNOWN BODYTYPE 56",
		"*UNKNOWN BODYTYPE 57",
		"*UNKNOWN BODYTYPE 58",
		"*UNKNOWN BODYTYPE 59",
		"*UNKNOWN BODYTYPE 60",
		"*UNKNOWN BODYTYPE 61",
		"*UNKNOWN BODYTYPE 62",
		"Swarm Pet",//63
		"Monster Summoning",//64
		"Trap",//65
		"Timer",//66
		"Trigger",//67
		"*UNKNOWN BODYTYPE 68",
		"*UNKNOWN BODYTYPE 69",
		"*UNKNOWN BODYTYPE 70",
		"*UNKNOWN BODYTYPE 71",
		"*UNKNOWN BODYTYPE 72",
		"*UNKNOWN BODYTYPE 73",
		"*UNKNOWN BODYTYPE 74",
		"*UNKNOWN BODYTYPE 75",
		"*UNKNOWN BODYTYPE 76",
		"*UNKNOWN BODYTYPE 77",
		"*UNKNOWN BODYTYPE 78",
		"*UNKNOWN BODYTYPE 79",
		"*UNKNOWN BODYTYPE 80",
		"*UNKNOWN BODYTYPE 81",
		"*UNKNOWN BODYTYPE 82",
		"*UNKNOWN BODYTYPE 83",
		"*UNKNOWN BODYTYPE 84",
		"*UNKNOWN BODYTYPE 85",
		"*UNKNOWN BODYTYPE 86",
		"*UNKNOWN BODYTYPE 87",
		"*UNKNOWN BODYTYPE 88",
		"*UNKNOWN BODYTYPE 89",
		"*UNKNOWN BODYTYPE 90",
		"*UNKNOWN BODYTYPE 91",
		"*UNKNOWN BODYTYPE 92",
		"*UNKNOWN BODYTYPE 93",
		"*UNKNOWN BODYTYPE 94",
		"*UNKNOWN BODYTYPE 95",
		"*UNKNOWN BODYTYPE 96",
		"*UNKNOWN BODYTYPE 97",
		"*UNKNOWN BODYTYPE 98",
		"*UNKNOWN BODYTYPE 99",
		"Untargetable",//100 (Property Utility)
		"Property Trap",//101
		"Property Companion",//102
		"Property Suicide",//103
	};

	PCHAR szAugRestrictions[] = {
		"None",
		"Armor Only",
		"Weapons Only",
		"1H Weapons Only",
		"2H Weapons Only",
		"1H Slash Only",
		"1H Blunt Only",
		"Piercing Only",
		"Hand to Hand Only",
		"2H Slash Only",
		"2H Blunt Only",
		"2H Pierce Only",
		"Bows Only",
		"Shields Only"
	};

	PCHAR szEquipmentSlot[] = {
		"head",
		"chest",
		"arms",
		"wrists",
		"hands",
		"legs",
		"feet",
		"primary",
		"offhand",
		nullptr
	};

	PCHAR szItemSlot[] = {
		"charm",        // 0
		"leftear",      // 1
		"head",
		"face",
		"rightear",
		"neck",
		"shoulder",
		"arms",
		"back",
		"leftwrist",
		"rightwrist",   // 10
		"ranged",
		"hands",
		"mainhand",
		"offhand",
		"leftfinger",
		"rightfinger",
		"chest",
		"legs",
		"feet",
		"waist",        // 20
		"powersource",
		"ammo",
		"pack1",
		"pack2",
		"pack3",
		"pack4",
		"pack5",
		"pack6",
		"pack7",
		"pack8",        // 30
		"pack9",
		"pack10",
		"cursor",
		nullptr            // 31
	};

	PCHAR szExpansions[] = {
		"The Ruins of Kunark",
		"The Scars of Velious",
		"The Shadows of Luclin",
		"The Planes of Power",
		"The Legacy of Ykesha",
		"Lost Dungeons of Norrath",
		"Gates of Discord",
		"Omens of War",
		"Dragons of Norrath",
		"Depths of Darkhollow",
		"Prophecy of Ro",
		"The Serpent's Spine",
		"The Buried Sea",
		"Secrets of Faydwer",
		"Seeds of Destruction",
		"Underfoot",
		"House of Thule",
		"Veil of Alaris",
		"Rain of Fear",
		"Call of the Forsaken",
		"The Darkened Sea",
		"The Broken Mirror",
		"Empires of Kunark",
		"Ring of Scale",
		"The Burning Lands",
		nullptr
	};

	BOOL bAllErrorsFatal = FALSE;
	BOOL bAllErrorsDumpStack = FALSE;
	BOOL bLaxColor = FALSE;
	BOOL bAllErrorsLog = FALSE;
	BOOL gbHUDUnderUI = 1;
	BOOL gbAlwaysDrawMQHUD = 0;
	BOOL gbMQ2LoadingMsg = TRUE;
	BOOL gbExactSearchCleanNames = FALSE;

	DWORD nColorAdjective = 0;
	DWORD nColorAdjectiveYou = 0;
	DWORD nColorExpletive = 0;
	DWORD nColorSyntaxError = 0;
	DWORD nColorMacroError = 0;
	DWORD nColorMQ2DataError = 0;
	DWORD nColorFatalError = 0;

	PCHAR szColorAdjective[] =
	{
		"",
		"GOD DAMN ",
		"FUCKING ",
		"MOTHER FUCKING ",
		nullptr
	};

	PCHAR szColorAdjectiveYou[] =
	{
		"",
		" FUCKER",
		" MOTHER FUCKER",
		" ASSHOLE",
		" FUCKTARD",
		" FUCKING RETARDED MONKEY",
		" GOD DAMN SHORT BUS PASSENGER",
		" ASSMONKEY",
		" PIGFUCKER",
		" PEEN",
		" FUCKING IDIOT",
		" STUPID FUCKER",
		" DUMBASS",
		" FUCKING DUMBASS",
		" STUPID FUCK",
		nullptr
	};

	PCHAR szColorExpletive[] =
	{
		"",
		"CHRIST ",
		"JESUS FUCK ",
		"GOD ",
		"JESUS FUCKING CHRIST ",
		"FUCKING CHRIST ",
		"GKFJDGJKFDGJKDF ",
		nullptr
	};

	PCHAR szColorSyntaxError[] =
	{
		"",
		"%edont you know how to use a simple %acommand%y",
		nullptr
	};

	PCHAR szColorMacroError[] =
	{
		"",
		"%ei'm pretty sure you're on %acrack%y"
		"%egood job%y, cant you do anything %aright%y",
		"%ewhatever you're %asmoking, pass it %aalong%y",
		"%e%aRTFM%y",
		"%e%aRTFM%y, until then fuck off%y",
		"%eget a %abrain%y",
		nullptr
	};

	PCHAR szColorFatalError[] =
	{
		"",
		"%eyou fucking broke it%y",
		"%egood job%y. what's next? your head on a %astick thats %awhat%y",
		nullptr
	};

	PCHAR szColorMQ2DataError[] =
	{
		"",
		"%ewhy dont you %aread the %areference%y",
		"%eget a %aclue%y",
		"%ewhatever you're %asmoking, pass it %aalong%y",
		"%e%aread the %areference%y",
		"%e%aread the %areference%y, until then fuck off%y",
		nullptr
	};

	PMQPLUGIN pPlugins = nullptr;
	std::map<std::string, std::string> mAliases;
	std::map<std::string, PDATAVAR> VariableMap;
	std::unordered_map<std::string, std::unique_ptr<MQ2DATAITEM>> MQ2DataMap;
	PSUB pSubs = nullptr;
	PMQCOMMAND pCommands = nullptr;



	// Offset Initialization

	DWORD EQADDR_HWND = 0;
	DWORD EQADDR_MEMCHECK0 = 0;
	DWORD EQADDR_MEMCHECK1 = 0;
	DWORD EQADDR_MEMCHECK2 = 0;
	DWORD EQADDR_MEMCHECK3 = 0;
	DWORD EQADDR_MEMCHECK4 = 0;
	PCHAR EQADDR_SERVERHOST = nullptr;
	PCHAR EQADDR_SERVERNAME = nullptr;
	DWORD EQADDR_CONVERTITEMTAGS = 0;
	PCMDLIST EQADDR_CMDLIST = nullptr;

	PBYTE EQADDR_ATTACK = nullptr;
	PBYTE EQADDR_NOTINCHATMODE = nullptr;
	PBYTE EQADDR_RUNWALKSTATE = nullptr;
	PDWORD EQADDR_SUBSCRIPTIONTYPE = nullptr;
	DWORD EQADDR_GROUPAGGRO = 0;
	PCHAR EQADDR_TARGETAGGROHOLDER = nullptr;
	PCHAR EQADDR_LASTTELL = nullptr;
	PBYTE EQADDR_ZONETYPE = nullptr;
	BOOL gbUseTellWindows = 0;
	PCHAR gpbRangedAttackReady = nullptr;
	PCHAR gpbShowNetStatus = nullptr;
	DWORD* g_ppDrawHandler = nullptr;
	CResolutionHandler** ppCResolutionHandler = nullptr;
	DWORD* gpShowNames = nullptr;
	DWORD* gpPCNames = nullptr;
	PBYTE pTributeActive = nullptr;
	PBYTE gpAutoFire = nullptr;
	PAUTOSKILL gpAutoSkill = nullptr;
	size_t g_eqgameimagesize = 0;
	PBYTE gpShiftKeyDown = nullptr; // addr+1=ctrl, addr+2=alt
	DWORD *gpMouseEventTime = nullptr;
	DWORD *gpbCommandEvent = nullptr;
	BOOL gbTimeStampChat = 0;
	BOOL gUseTradeOnTarget = 1;
	BOOL gbBeepOnTells = 0;
	BOOL gbFlashOnTells = 0;
	BOOL gbIgnoreAlertRecursion = 0;
	BOOL gbShowCurrentCamera = 1;
	int  oldcameratype = -1;
	char CameraText[2048] = { "Window Selector (Camera 0)" };
	PVOID EQADDR_GWORLD = nullptr;
	PDWORD EQADDR_DOABILITYLIST = nullptr;

	PMAPLABEL *ppCurrentMapLabel = nullptr;
	PCHAR *EQMappableCommandList = nullptr;
	PBYTE EQbCommandStates = nullptr;

	PBYTE EQADDR_ENCRYPTPAD0 = nullptr;
	PBYTE EQADDR_ENCRYPTPAD1 = nullptr;
	PBYTE EQADDR_ENCRYPTPAD2 = nullptr;
	PBYTE EQADDR_ENCRYPTPAD3 = nullptr;
	PBYTE EQADDR_ENCRYPTPAD4 = nullptr;

	DWORD *pScreenX = nullptr;
	DWORD *pScreenY = nullptr;
	DWORD *pScreenXMax = nullptr;
	DWORD *pScreenYMax = nullptr;
	DWORD *pScreenMode = nullptr;
	char  *pMouseLook = nullptr;
	PMOUSEINFO EQADDR_MOUSE = nullptr;
	PMOUSECLICK EQADDR_MOUSECLICK = nullptr;

	DWORD EQADDR_DIMAIN = 0;
	IDirectInputDevice8A **EQADDR_DIKEYBOARD = nullptr;
	IDirectInputDevice8A **EQADDR_DIMOUSE = nullptr;
	PPOINT EQADDR_DIMOUSECOPY = nullptr;
	PPOINT EQADDR_DIMOUSECHECK = nullptr;


	PGUILDS pGuildList = nullptr;
	PEQSOCIAL   pSocialList = nullptr;
	PBYTE pgHotkeyPage = nullptr;
	PINT pgCurrentSocial = nullptr;

	fEQNewUIINI     NewUIINI = nullptr;
	fEQProcGameEvts ProcessGameEvents = nullptr;

	fEQGetMelee     get_melee_range = GetMeleeRange;
	fGetLabelFromEQ GetLabelFromEQ = nullptr;
	fEQToggleKeyRingItem  cmdToggleKeyRingItem = nullptr;
	fEQW_GetDisplayWindow EQW_GetDisplayWindow = nullptr;

	fICGetHashData IC_GetHashData = nullptr;
	fICSetHashData IC_SetHashData = nullptr;
	fLoaderSetLoaded IC_LoaderSetLoaded = nullptr;
	fLoaderClearLoaded IC_LoaderClearLoaded = nullptr;
	fMQ2Unload IC_MQ2Unload = nullptr;
	fClassLvl IC_ClassLvl = nullptr;

	StringTable** ppStringTable = nullptr;
	CDBStr** ppCDBStr = nullptr;
	EQMisc* pEQMisc = nullptr;
	CSkillMgr** ppCSkillMgr = nullptr;
	CGuild* pGuild = nullptr;
	SKILLMGR** ppSkillMgr = nullptr;
	EVERQUESTINFO* ppEverQuestInfo = nullptr;

	CEverQuest** ppEverQuest = nullptr;
	CDisplay** ppDisplay = nullptr;
	EQ_PC** ppPCData = nullptr;
	EQ_Character** ppCharData = nullptr;
	PlayerClient** ppCharSpawn = nullptr;
	PlayerClient** ppActiveMerchant = nullptr;
	PlayerManagerClient** ppSpawnManager = nullptr;
	PlayerClient** ppLocalPlayer = nullptr;
	PlayerClient** ppControlledPlayer = nullptr;
	EQWorldData** ppWorldData = nullptr;
	ClientSpellManager** ppSpellMgr = nullptr;
	PlayerClient** ppTarget = nullptr;
	EqSwitchManager** ppSwitchMgr = nullptr;
	SPELLFAVORITE* pSpellSets = nullptr;
	EQZoneInfo* pZoneInfo = nullptr;
	AltAdvManager** ppAltAdvManager = nullptr;
	connection_t** ppConnection = nullptr;
	PlayerClient** ppTradeTarget = nullptr;
	PlayerClient** ppActiveBanker = nullptr;
	PlayerClient** ppActiveGMaster = nullptr;
	PlayerClient** ppActiveCorpse = nullptr;

	/* WINDOW INSTANCES */
	LootFiltersManager** ppLootFiltersManager = nullptr;
	EQSpellStrings** ppEQSpellStrings = nullptr;
	CAuraWnd** ppAuraWnd = nullptr;
	CContextMenuManager** ppContextMenuManager = nullptr;
	CCursorAttachment** ppCursorAttachment = nullptr;
	CSocialEditWnd** ppSocialEditWnd = nullptr;
	CContainerMgr** ppContainerMgr = nullptr;
	CChatWindowManager** ppChatManager = nullptr;
	CFacePick** ppFacePick = nullptr;
	CFactionWnd** ppFactionWnd = nullptr;
	CExtendedTargetWnd** ppExtendedTargetWnd = nullptr;
	CFindItemWnd** ppFindItemWnd = nullptr;
	CFindLocationWnd** ppFindLocationWnd = nullptr;
	CInvSlotMgr** ppInvSlotMgr = nullptr;
	CNoteWnd** ppNoteWnd = nullptr;
	CTipWnd** ppTipWndOFDAY = nullptr;
	CTipWnd** ppTipWndCONTEXT = nullptr;
	CBookWnd** ppBookWnd = nullptr;
	CFriendsWnd** ppFriendsWnd = nullptr;
	CMusicPlayerWnd** ppMusicPlayerWnd = nullptr;

	CRealEstateItemsWnd** ppRealEstateItemsWnd = nullptr;
	CAchievementsWnd** ppAchievementsWnd = nullptr;
	CAlarmWnd** ppAlarmWnd = nullptr;
	CLoadskinWnd** ppLoadskinWnd = nullptr;
	CPetInfoWnd** ppPetInfoWnd = nullptr;
	CRespawnWnd** ppRespawnWnd = nullptr;
	CTrainWnd** ppTrainWnd = nullptr;
	CSkillsWnd** ppSkillsWnd = nullptr;
	CSkillsSelectWnd** ppSkillsSelectWnd = nullptr;
	CAAWnd** ppAAWnd = nullptr;
	CGroupWnd** ppGroupWnd = nullptr;
	CGroupSearchWnd** ppGroupSearchWnd = nullptr;
	CGroupSearchFiltersWnd** ppGroupSearchFiltersWnd = nullptr;
	CRaidWnd** ppRaidWnd = nullptr;
	CRaidOptionsWnd** ppRaidOptionsWnd = nullptr;
	CBreathWnd** ppBreathWnd = nullptr;
	CMapToolbarWnd** ppMapToolbarWnd = nullptr;
	CMapViewWnd** ppMapViewWnd = nullptr;
	CEditLabelWnd** ppEditLabelWnd = nullptr;
	COptionsWnd** ppOptionsWnd = nullptr;
	CBuffWindow** ppBuffWindowSHORT = nullptr;
	CBuffWindow** ppBuffWindowNORMAL = nullptr;
	CTargetWnd** ppTargetWnd = nullptr;
	CColorPickerWnd** ppColorPickerWnd = nullptr;
	CCombatSkillsSelectWnd** ppCombatSkillsSelectWnd = nullptr;
	CHotButtonWnd** ppHotButtonWnd = nullptr;
	CPlayerWnd** ppPlayerWnd = nullptr;
	CCastingWnd** ppCastingWnd = nullptr;
	CCastSpellWnd** ppCastSpellWnd = nullptr;
	CSpellBookWnd** ppSpellBookWnd = nullptr;
	CInventoryWnd** ppInventoryWnd = nullptr;
	CBankWnd** ppBankWnd = nullptr;
	CQuantityWnd** ppQuantityWnd = nullptr;
	CTextEntryWnd** ppTextEntryWnd = nullptr;
	CFileSelectionWnd** ppFileSelectionWnd = nullptr;
	CLootWnd** ppLootWnd = nullptr;
	CActionsWnd** ppActionsWnd = nullptr;
	CCombatAbilityWnd** ppCombatAbilityWnd = nullptr;
	CMerchantWnd** ppMerchantWnd = nullptr;
	CTradeWnd** ppTradeWnd = nullptr;
	CBazaarWnd** ppBazaarWnd = nullptr;
	CBazaarSearchWnd** ppBazaarSearchWnd = nullptr;
	CGiveWnd** ppGiveWnd = nullptr;
	CSelectorWnd** ppSelectorWnd = nullptr;
	CTrackingWnd** ppTrackingWnd = nullptr;
	CInspectWnd** ppInspectWnd = nullptr;
	CFeedbackWnd** ppFeedbackWnd = nullptr;
	CBugReportWnd** ppBugReportWnd = nullptr;
	CVideoModesWnd** ppVideoModesWnd = nullptr;
	CCompassWnd** ppCompassWnd = nullptr;
	CPlayerNotesWnd** ppPlayerNotesWnd = nullptr;
	CGemsGameWnd** ppGemsGameWnd = nullptr;
	CStoryWnd** ppStoryWnd = nullptr;
	CBodyTintWnd** ppBodyTintWnd = nullptr;
	CGuildMgmtWnd** ppGuildMgmtWnd = nullptr;
	CJournalTextWnd** ppJournalTextWnd = nullptr;
	CJournalCatWnd** ppJournalCatWnd = nullptr;
	CPetitionQWnd** ppPetitionQWnd = nullptr;
	CBandolierWnd** ppBandolierWnd = nullptr;
	CWebManager** ppCWebManager = nullptr;
	CTaskWnd** ppTaskWnd = nullptr;
	CTaskManager* ppTaskManager = nullptr;
	CTimeLeftWnd** ppTimeLeftWnd = nullptr;
	CAdvancedLootWnd** ppAdvancedLootWnd = nullptr;
	CRewardSelectionWnd** ppRewardSelectionWnd = nullptr;
	CConfirmationDialog** ppConfirmationDialog = nullptr;
	CEQSuiteTextureLoader* ppEQSuiteTextureLoader = nullptr;
	PointMerchantWnd** ppPointMerchantWnd = nullptr;
	CZoneGuideWnd** ppCZoneGuideWnd = nullptr;

	CSidlManager** ppSidlMgr = nullptr;
	CXWndManager** ppWndMgr = nullptr;
	PEQRAID pRaid = nullptr;
	DZMEMBER** ppDZMember = nullptr;
	DZTIMERINFO** ppDZTimerInfo = nullptr;
	TASKMEMBER** ppTaskMember = nullptr;
	DYNAMICZONE* pDynamicZone = nullptr;
	MERCENARYINFO** ppMercInfo = nullptr;
	EQMERCALTABILITIES** ppMercAltAbilities = nullptr;
	CLargeDialogWnd** ppLargeDialog = nullptr;
	CItemDisplayManager** ppItemDisplayManager = nullptr;
	EqSoundManager** ppEqSoundManager = nullptr;

#ifdef __ExecuteCmd_x
	FUNCTION_AT_ADDRESS(bool EQExecuteCmd(unsigned int command, bool keyDown, void* data, const KeyCombo* combo), __ExecuteCmd);
#endif

	bool ExecuteCmd(unsigned int command, bool keyDown, void* data)
	{
		return EQExecuteCmd(command, keyDown, data, nullptr);
	}

#if __has_include("MQ2Globals-private.cpp")
#include "MQ2Globals-private.cpp"
#endif


} // namespace MQ2Globals

