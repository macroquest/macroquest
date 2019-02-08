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

// Exclude rarely-used stuff from Windows headers
#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT 0x510
#define DIRECTINPUT_VERSION 0x800

#if !defined(CINTERFACE)
#error /DCINTERFACE
#endif

#define DBG_SPEW

#include "MQ2Main.h"

namespace MQ2Globals
{

	DWORD baseAddress = (DWORD)GetModuleHandle(NULL);

	bool InitOffsets()
	{
		if (!baseAddress)
			return false;

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
#if !defined(ROF2EMU) && !defined(UFEMU)
		gpAutoSkill = (PAUTOSKILL)__AutoSkillArray;
#endif
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
		pMouseLook = (CHAR*)__MouseLook;
		EQADDR_MOUSE = (PMOUSEINFO)__Mouse;
		EQADDR_MOUSECLICK = (PMOUSECLICK)__Clicks;

#ifndef ISXEQ
		EQADDR_DIMAIN = DI8__Main;
		EQADDR_DIKEYBOARD = (IDirectInputDevice8A **)DI8__Keyboard;
		EQADDR_DIMOUSE = (IDirectInputDevice8A **)DI8__Mouse;
#endif
		EQADDR_DIMOUSECOPY = (PPOINT)DI8__Mouse_Copy;
		EQADDR_DIMOUSECHECK = (PPOINT)DI8__Mouse_Check;


		pGuildList = (PGUILDS)__Guilds;
		pSocialList = (PEQSOCIAL)__Socials;
#if defined(ROF2EMU) || defined(UFEMU)
		pgHotkeyPage = (PBYTE)__HotkeyPage;
#endif
		pgCurrentSocial = (PINT)__CurrentSocial;

		NewUIINI = (fEQNewUIINI)__NewUIINI;
		ProcessGameEvents = (fEQProcGameEvts)__ProcessGameEvents;
		GetLabelFromEQ = (fGetLabelFromEQ)__GetLabelFromEQ;
#if !defined(ROF2EMU) && !defined(UFEMU)
		cmdToggleKeyRingItem = (fEQToggleKeyRingItem)__ToggleKeyRingItem;
#endif
		ppStringTable = (StringTable**)pinstStringTable;
		ppCDBStr = (CDBStr**)pinstCDBStr;
		pEQMisc = (EQMisc*)instEQMisc;
		ppCSkillMgr = (CSkillMgr**)pinstSkillMgr;
		pGuild = (CGuild*)__Guilds;
		ppSkillMgr = (_SKILLMGR**)pinstSkillMgr;

		pEverQuestInfo = (PEVERQUESTINFO)pinstEverQuestInfo;
		ppEverQuest = (CEverQuest**)pinstCEverQuest;
		ppDisplay = (CDisplay**)pinstCDisplay;
#if !defined(ROF2EMU) && !defined(UFEMU)
		ppDistillerInfo = (CDistillerInfo**)pinstCDistillerInfo;
#endif
		ppPCData = (EQ_PC**)pinstPCData;
		ppCharData = (EQ_Character**)pinstCharData;
		ppCharSpawn = (EQPlayer**)pinstCharSpawn;
		ppActiveMerchant = (EQPlayer**)pinstActiveMerchant;
		ppSpawnManager = (EQPlayerManager**)pinstSpawnManager;
		ppLocalPlayer = (EQPlayer**)pinstLocalPlayer;
		ppControlledPlayer = (EQPlayer**)pinstControlledPlayer;
		ppWorldData = (EQWorldData**)pinstWorldData;
		ppSpellMgr = (ClientSpellManager**)pinstSpellManager;
		ppTarget = (EQPlayer**)pinstTarget;
		ppSwitchMgr = (EqSwitchManager**)pinstSwitchManager;
		ppItemList = (EQItemList**)pinstEQItemList;
		pSpellSets = (SPELLFAVORITE *)pinstSpellSets;
		pZoneInfo = (EQZoneInfo*)instEQZoneInfo;
		ppAltAdvManager = (AltAdvManager**)pinstAltAdvManager;
		ppConnection = (PCONNECTION_T*)__gWorld;
		ppAuraMgr = (AURAMGR**)pinstAuraMgr;
		ppAuraWnd = (CAuraWnd**)pinstCAuraWnd;
#if !defined(ROF2EMU) && !defined(UFEMU)
		ppLootFiltersManager = (LootFiltersManager**)pinstLootFiltersManager;
#endif
		ppEQChatMgr = (EQCHATMGR**)pinstCChatWindowManager;

		ppTradeTarget = (EQPlayer **)pinstTradeTarget;
		ppActiveBanker = (EQPlayer **)pinstActiveBanker;
		ppActiveGMaster = (EQPlayer **)pinstActiveGMaster;
		ppActiveCorpse = (EQPlayer **)pinstActiveCorpse;

		ppContextMenuManager = (CContextMenuManager**)pinstCContextMenuManager;
		ppCursorAttachment = (CCursorAttachment**)pinstCCursorAttachment;
		ppSocialEditWnd = (CSocialEditWnd**)pinstCSocialEditWnd;
		ppContainerMgr = (CContainerMgr**)pinstCContainerMgr;
		ppChatManager = (CChatManager**)pinstCChatWindowManager;
		ppFacePick = (CFacePick**)pinstCFacePick;
#if !defined(ROF2EMU) && !defined(UFEMU)
		ppFactionWnd = (CFactionWnd**)pinstCFactionWnd;
		ppFindItemWnd = (CFindItemWnd**)pinstCFindItemWnd;
#endif
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
#if defined(ROF2EMU) || defined(UFEMU)
		ppSoulmarkWnd = (CSoulmarkWnd**)pinstCSoulmarkWnd;
		ppFeedbackWnd = (CFeedbackWnd**)pinstCFeedbackWnd;
#endif
		ppCWebManager = (CWebManager**)pinstCWebManager;
		ppTaskWnd = (CTaskWnd**)pinstCTaskWnd;
		ppTaskManager = (CTaskManager*)pinstCTaskManager;
		ppTimeLeftWnd = (CTimeLeftWnd**)pinstCTimeLeftWnd;
		ppTextOverlay = (CTextOverlay**)pinstCTextOverlay;
#if defined(ROF2EMU) || defined(UFEMU)
		ppPotionBeltWnd = (CPotionBeltWnd**)pinstCPotionBeltWnd;
#endif
#if !defined(ROF2EMU) && !defined(UFEMU)
		ppAdvancedLootWnd = (CAdvancedLootWnd**)pinstCAdvancedLootWnd;
#endif
		ppBandolierWnd = (CBandolierWnd**)pinstCBandolierWnd;
		ppRewardSelectionWnd = (CRewardSelectionWnd**)pinstRewardSelectionWnd;
		ppConfirmationDialog = (CConfirmationDialog**)pinstCConfirmationDialog;
		ppEQSuiteTextureLoader = (CEQSuiteTextureLoader*)pinstEQSuiteTextureLoader;
#if defined(ROF2EMU) || defined(UFEMU)
		ppPointMerchantWnd = (PointMerchantWnd**)pinstCPointMerchantWnd;
#endif
		ppCZoneGuideWnd = (CZoneGuideWnd**)pinstCZoneGuideWnd;
		ppSidlMgr = (CSidlManager **)pinstCSidlManager;
		ppWndMgr = (CXWndManager**)pinstCXWndManager;
		ppKeypressHandler = (KeypressHandler**)instKeypressHandler;
		pRaid = (PEQRAID)instCRaid;
		ppDZMember = (DZMEMBER**)pinstDZMember;
		ppDZTimerInfo = (DZTIMERINFO**)pinstDZTimerInfo;
		ppTaskMember = (TASKMEMBER**)pinstTaskMember;
		pDynamicZone = (DYNAMICZONE*)instDynamicZone;
		ppMercInfo = (MERCENARYINFO**)pinstMercenaryData;
#if !defined(ROF2EMU) && !defined(UFEMU)
		ppMercAltAbilities = (EQMERCALTABILITIES**)pinstMercAltAbilities;
		ppEQSpellStrings = (EQSpellStrings**)pinstEQSpellStrings;
#endif
		ppAggroInfo = (AGGROINFO **)pinstAggroInfo;
		ppLargeDialog = (CLargeDialogWnd**)pinstCLargeDialogWnd;
		ppItemDisplayManager = (CItemDisplayManager**)pinstCItemDisplayManager;
		ppEqSoundManager = (EqSoundManager**)pinstEQSoundManager;

		return true;
	}
	DWORD LoginController__GiveTime = 0;
	struct _actordefentry ActorDefList[] = {
#include "actordef.h"
		0, 0, "NULL"
	};
	/* SpellMap */
	HANDLE ghLockSpellMap = 0;
	/* PickZone */
	HANDLE ghLockPickZone = 0;
	HANDLE ghLockDelayCommand = 0;
	HANDLE ghInitializeMQ2SpellDb = 0;
	HANDLE ghCCommandLock = 0;
	HANDLE ghVariableLock = 0;

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

#ifndef ISXEQ
	PDATAVAR pGlobalVariables = 0;
	PDATAVAR pMacroVariables = 0;
#endif

	ePVPServer PVPServer = PVP_NONE;
	DWORD gdwLocalPlayer = pinstLocalPlayer_x;
	CHAR gszVersion[32] = VersionString;
	CHAR gszTime[32] = TimeString;
#if defined(TEST)
	int gBuild = 2;//TEST
#elif defined(EQBETA)
	int gBuild = 3;//EQBETA
#elif defined(ROF2EMU)
	int gBuild = 4;//ROF2EMU
#elif defined(UFEMU)
	int gBuild = 5;//UFEMU
#else
	int gBuild = 1;//LIVE
#endif
	bool gbDoingModuleChecks = false;
	DWORD gGameState = 0;
	DWORD gMaxSpawnCaptions = 30;
	BOOL gMQCaptions = TRUE;
	BOOL gAnonymize = FALSE;
	DWORD ThreadID = 0;
	BOOL g_Loaded = FALSE;

	BOOL gStringTableFixed = FALSE;
	PCHATBUF gDelayedCommands = 0;

	HMODULE ghModule = NULL;
	HINSTANCE ghInstance = NULL;
	HWND ghInjectorWnd = NULL;
	//PHOTKEY pHotkey = NULL;
	BOOL gbUnload = FALSE;
	bool gBindInProgress = false;
	BOOL gbLoad = TRUE;
	DWORD gpHook = NULL;
	HMODULE ghmq2ic = 0;
#ifndef ISXEQ
	PMACROBLOCK gMacroBlock = NULL;
	int BlockIndex = 0;
	PMACROSTACK gMacroStack = NULL;
	decltype(gMacroSubLookupMap) gMacroSubLookupMap;
	decltype(gUndeclaredVars) gUndeclaredVars;
	PEVENTQUEUE gEventQueue = NULL;
	int gEventFunc[NUM_EVENTS] = { NULL };
#endif
	UCHAR gLastFind = 0;
	DOUBLE gZFilter = 10000.0f;
	DOUBLE gFaceAngle = 10000.0f;
	DOUBLE gLookAngle = 10000.0f;
	BOOL gbSpelldbLoaded = 0;
	CHAR gszEQPath[MAX_STRING] = { 0 };
	CHAR gszMacroPath[MAX_STRING] = { 0 };
	CHAR gszLogPath[MAX_STRING] = { 0 };
	CHAR gszINIPath[MAX_STRING] = { 0 };
	CHAR gszINIFilename[MAX_STRING] = { 0 };
	CHAR gszItemDB[MAX_STRING] = { 0 };
	CHAR gszMacroName[MAX_STRING] = { 0 };
	CHAR szLastCommand[MAX_STRING] = { 0 };

	CHAR gszLastNormalError[MAX_STRING] = { 0 };
	CHAR gszLastSyntaxError[MAX_STRING] = { 0 };
	CHAR gszLastMQ2DataError[MAX_STRING] = { 0 };

	PSPAWNINFO pNamingSpawn = 0;
	CHAR gszSpawnPlayerName[8][MAX_STRING] = {
		"",//0
		"${If[${NamingSpawn.Mark},\"${NamingSpawn.Mark} - \",]}${If[${NamingSpawn.Trader},\"Trader \",]}${If[${NamingSpawn.Invis},(${NamingSpawn.DisplayName}),${NamingSpawn.DisplayName}]}${If[${NamingSpawn.AFK},\" AFK\",]}${If[${NamingSpawn.Linkdead},\" LD\",]}${If[${NamingSpawn.LFG},\" LFG\",]}${If[${NamingSpawn.GroupLeader},\" LDR\",]}",//1
		"${If[${NamingSpawn.Mark},\"${NamingSpawn.Mark} - \",]}${If[${NamingSpawn.Trader},\"Trader \",]}${If[${NamingSpawn.Invis},(${NamingSpawn.DisplayName}),${NamingSpawn.DisplayName}]}${If[${NamingSpawn.Surname.Length},\" ${NamingSpawn.Surname}\",]}${If[${NamingSpawn.AFK},\" AFK\",]}${If[${NamingSpawn.Linkdead},\" LD\",]}${If[${NamingSpawn.LFG},\" LFG\",]}${If[${NamingSpawn.GroupLeader},\" LDR\",]}",//2
		"${If[${NamingSpawn.Mark},\"${NamingSpawn.Mark} - \",]}${If[${NamingSpawn.Trader},\"Trader \",]}${If[${NamingSpawn.Invis},(${NamingSpawn.DisplayName}),${NamingSpawn.DisplayName}]}${If[${NamingSpawn.Surname.Length},\" ${NamingSpawn.Surname}\",]}${If[${NamingSpawn.AFK},\" AFK\",]}${If[${NamingSpawn.Linkdead},\" LD\",]}${If[${NamingSpawn.LFG},\" LFG\",]}${If[${NamingSpawn.GroupLeader},\" LDR\",]}${If[${NamingSpawn.Guild.Length},\n<${If[${NamingSpawn.GuildStatus.NotEqual[member]},\"${NamingSpawn.GuildStatus} of \",]}${NamingSpawn.Guild}>,]}",//3
		"${If[${NamingSpawn.Mark},\"${NamingSpawn.Mark} - \",]}${If[${NamingSpawn.Trader},\"Trader \",]}${If[${NamingSpawn.AARank},\"${NamingSpawn.AATitle} \",]}${If[${NamingSpawn.Invis},(${NamingSpawn.DisplayName}),${NamingSpawn.DisplayName}]}${If[${NamingSpawn.Surname.Length},\" ${NamingSpawn.Surname}\",]}${If[${NamingSpawn.Suffix.Length},\" ${NamingSpawn.Suffix}\",]}${If[${NamingSpawn.AFK},\" AFK\",]}${If[${NamingSpawn.Linkdead},\" LD\",]}${If[${NamingSpawn.LFG},\" LFG\",]}${If[${NamingSpawn.GroupLeader},\" LDR\",]}${If[${NamingSpawn.Guild.Length},\n<${If[${NamingSpawn.GuildStatus.NotEqual[member]},\"${NamingSpawn.GuildStatus} of \",]}${NamingSpawn.Guild}>,]}",//4
		"${If[${NamingSpawn.Mark},\"${NamingSpawn.Mark} - \",]}${If[${NamingSpawn.Trader},\"Trader \",]}${If[${NamingSpawn.AARank},\"${NamingSpawn.AATitle} \",]}${If[${NamingSpawn.Invis},(${NamingSpawn.DisplayName}),${NamingSpawn.DisplayName}]}${If[${NamingSpawn.Suffix.Length},\" ${NamingSpawn.Suffix}\",]}${If[${NamingSpawn.AFK},\" AFK\",]}${If[${NamingSpawn.Linkdead},\" LD\",]}${If[${NamingSpawn.LFG},\" LFG\",]}${If[${NamingSpawn.GroupLeader},\" LDR\",]}",//5
		"${If[${NamingSpawn.Mark},\"${NamingSpawn.Mark} - \",]}${If[${NamingSpawn.Trader},\"Trader \",]}${If[${NamingSpawn.AARank},\"${NamingSpawn.AATitle} \",]}${If[${NamingSpawn.Invis},(${NamingSpawn.DisplayName}),${NamingSpawn.DisplayName}]}${If[${NamingSpawn.Surname.Length},\" ${NamingSpawn.Surname}\",]}${If[${NamingSpawn.Suffix.Length},\" ${NamingSpawn.Suffix}\",]}${If[${NamingSpawn.AFK},\" AFK\",]}${If[${NamingSpawn.Linkdead},\" LD\",]}${If[${NamingSpawn.LFG},\" LFG\",]}${If[${NamingSpawn.GroupLeader},\" LDR\",]}",//6 
	};
	CHAR gszSpawnNPCName[MAX_STRING] = "${If[${NamingSpawn.Mark},\"${NamingSpawn.Mark} - \",]}${If[${NamingSpawn.Assist},\">> \",]}${NamingSpawn.DisplayName}${If[${NamingSpawn.Assist},\" - ${NamingSpawn.PctHPs}%<<\",]}${If[${NamingSpawn.Surname.Length},\n(${NamingSpawn.Surname}),]}";
	CHAR gszSpawnPetName[MAX_STRING] = "${If[${NamingSpawn.Mark},\"${NamingSpawn.Mark} - \",]}${If[${NamingSpawn.Assist},\">> \",]}${NamingSpawn.DisplayName}${If[${NamingSpawn.Assist},\" - ${NamingSpawn.PctHPs}%<<\",]}${If[${NamingSpawn.Master.Type.Equal[PC]},\n(${NamingSpawn.Master}),]}";
	CHAR gszSpawnCorpseName[MAX_STRING] = "${NamingSpawn.DisplayName}'s corpse";
	CHAR gszAnonCaption[MAX_STRING] = "[${NamingSpawn.Level}] ${NamingSpawn.Race} ${NamingSpawn.Class} ${NamingSpawn.Type}";

	DWORD DrawHUDParams[4] = { 0,0,0,0 };

#ifndef ISXEQ
	Blech *pMQ2Blech = 0;
	CHAR EventMsg[MAX_STRING] = { 0 };
#ifdef USEBLECHEVENTS
	Blech *pEventBlech = 0;
#endif
	PEVENTLIST pEventList = NULL;
#endif

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
	CHAR gIfDelimiter = ',';
	CHAR gIfAltDelimiter = '~';
	DWORD gNetStatusXPos = 0;
	DWORD gNetStatusYPos = 0;
	LONG gStackingDebug = 0;
	BOOL gUseNewNamedTest = 0;
	BOOL gbInForeground = FALSE;

	DOUBLE DegToRad = 57.295779513082320876846364344191;
	DOUBLE PI = 3.1415926535;

	//PKEYPRESS gKeyStack = NULL;
	PMQTIMER gTimer = NULL;
	LONG gDelay = 0;
	CHAR gDelayCondition[MAX_STRING] = { 0 };
	BOOL bAllowCommandParse = TRUE;
	LONG gDelayZoning = 0;
	std::map<DWORD, std::list<SEARCHSPAWN>> gAlertMap;

	SPAWNINFO MercenarySpawn = { 0 };
	SPAWNINFO PetSpawn = { 0 };
	SPAWNINFO EnviroTarget = { 0 };
	GROUNDOBJECT GroundObject = { GO_None, { 0 } };
	PGROUNDITEM	pGroundTarget = NULL;
	SPAWNINFO DoorEnviroTarget = { 0 };
	PDOOR pDoorTarget = NULL;
	PITEMDB gItemDB = NULL;
	BOOL bRunNextCommand = FALSE;
	BOOL gTurbo = FALSE;
	BOOL gWarning = FALSE;
	PDEFINE pDefines = NULL;
	PBINDLIST pBindList = NULL;
	CHAR gLastFindSlot[MAX_STRING] = { 0 };
	PFILTER gpFilters = NULL;

	BOOL g_bInDXMouse = FALSE;
	PMOUSESPOOF gMouseData = { 0 };
	BOOL bDetMouse = TRUE;

	// EQ Functions Initialization
	fEQCommand        cmdHelp = NULL;
	fEQCommand        cmdWho = NULL;
	fEQCommand        cmdWhoTarget = NULL;
	fEQCommand        cmdLocation = NULL;
	fEQCommand        cmdFace = NULL;
	fEQCommand        cmdTarget = NULL;
	fEQCommand        cmdCharInfo = NULL;
	fEQCommand        cmdFilter = NULL;
	fEQCommand        cmdDoAbility = NULL;
	fEQCommand        cmdCast = NULL;
	fEQCommand        cmdUseItem = NULL;
	fEQCommand        cmdPet = NULL;
	fEQCommand        cmdMercSwitch = NULL;
	fEQCommand        cmdAdvLoot = NULL;
	fEQCommand        cmdPickZone = NULL;
	fEQCommand        cmdAssist = NULL;

	PCHAR szEQMappableCommands[nEQMappableCommands];
	decltype(ItemSlotMap) ItemSlotMap;

	CHAR DataTypeTemp[MAX_STRING] = { 0 };

	decltype(SpawnByName) SpawnByName;
	MQRANK EQP_DistArray[3000];
	DWORD gSpawnCount = 0;

	// Motd and Pulse's mouse variables
	BOOL gMouseClickInProgress[8] = { FALSE };
	// End of mouse variables

	// Arrays  (Note:  See also EQLib_Utilities.cpp)
	DIKEYID gDiKeyID[] = {
#include "dikeys.h"
	{ NULL,0 }
	};

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
		NULL // SuperWhoTarget
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
		NULL
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
#include "skills.h"
		NULL
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
		NULL
	};

	PCHAR szCombineTypes[] = {
#include "combines.h"
		NULL
	};
	SIZE_T MAX_COMBINES = sizeof(szCombineTypes) / sizeof(PCHAR);

	PCHAR szItemTypes[] = {
#include "itemtypes.h"
		NULL
	};
	SIZE_T MAX_ITEMTYPES = sizeof(szItemTypes) / sizeof(PCHAR);

	PCHAR szSPATypes[] = {
#include "SpellEffects.h"
		NULL
	};
	SIZE_T MAX_SPELLEFFECTS = (sizeof(szSPATypes) / sizeof(PCHAR))-1;

	PCHAR szFactionNames[] = {
#include "FactionNames.h"
		NULL
	};
	SIZE_T MAX_FACTIONNAMES = (sizeof(szFactionNames) / sizeof(PCHAR))-1;

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
		"Dragons of Norrath",		//9
		"Depths of Darkhollow",		//10
		"Prophecy of Ro",			//11
		"Serpent's Spine",			//12
		"Buried Sea",				//13
		"Secrets of Faydwer",		//14
		"Seeds of Destruction",		//15
		"Underfoot",				//16
		"House of Thule",			//17
		"Veil of Alaris",			//18
		"Rain of Fear",				//19
		"Call of the Forsaken",		//20
		"Broken Mirror",			//21
	};

	//depricated
#if 0
#include "grounds.h"
	PCHAR szItemName[] = {
#include "weapons.h"
		NULL
	};
#endif

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
		NULL
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
		NULL            // 31
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
		NULL
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
		NULL
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
		NULL
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
		NULL
	};

	PCHAR szColorSyntaxError[] =
	{
		"",
		"%edont you know how to use a simple %acommand%y",
		NULL
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
		NULL
	};

	PCHAR szColorFatalError[] =
	{
		"",
		"%eyou fucking broke it%y",
		"%egood job%y. what's next? your head on a %astick thats %awhat%y",
		NULL
	};

	PCHAR szColorMQ2DataError[] =
	{
		"",
		"%ewhy dont you %aread the %areference%y",
		"%eget a %aclue%y",
		"%ewhatever you're %asmoking, pass it %aalong%y",
		"%e%aread the %areference%y",
		"%e%aread the %areference%y, until then fuck off%y",
		NULL
	};

	PMQPLUGIN pPlugins = 0;
	PMQXMLFILE pXMLFiles = 0;
	std::map<std::string,std::string> mAliases;
	std::map<std::string,PDATAVAR> VariableMap;
	std::unordered_map<std::string, std::unique_ptr<MQ2DATAITEM>> MQ2DataMap;
	PSUB pSubs = 0;
	PMQCOMMAND pCommands = 0;



	// Offset Initialization

	DWORD EQADDR_HWND = 0;
	DWORD EQADDR_MEMCHECK0 = 0;
	DWORD EQADDR_MEMCHECK1 = 0;
	DWORD EQADDR_MEMCHECK2 = 0;
	DWORD EQADDR_MEMCHECK3 = 0;
	DWORD EQADDR_MEMCHECK4 = 0;
	PCHAR EQADDR_SERVERHOST = 0;
	PCHAR EQADDR_SERVERNAME = 0;
	DWORD EQADDR_CONVERTITEMTAGS = 0;
	PCMDLIST EQADDR_CMDLIST = 0;

	PBYTE EQADDR_ATTACK = 0;
	PBYTE EQADDR_NOTINCHATMODE = 0;
	PBYTE EQADDR_RUNWALKSTATE = 0;
	PDWORD EQADDR_SUBSCRIPTIONTYPE = 0;
	DWORD EQADDR_GROUPAGGRO = 0;
	PCHAR EQADDR_TARGETAGGROHOLDER = 0;
	PCHAR EQADDR_LASTTELL = 0;
	PBYTE EQADDR_ZONETYPE = 0;
	BOOL gbUseTellWindows = 0;
	PCHAR gpbRangedAttackReady = 0;
	PCHAR gpbShowNetStatus = 0;
	DWORD *g_ppDrawHandler = 0;
	CResolutionHandler **ppCResolutionHandler = 0;
	DWORD *gpShowNames = 0;
	DWORD *gpPCNames = 0;
	PBYTE pTributeActive = 0;
	PBYTE gpAutoFire = 0;
	#if !defined(ROF2EMU) && !defined(UFEMU)
	PAUTOSKILL gpAutoSkill = 0;
	#endif
	size_t g_eqgameimagesize = 0;
	PBYTE gpShiftKeyDown = 0; // addr+1=ctrl, addr+2=alt
	DWORD *gpMouseEventTime = 0;
	DWORD *gpbCommandEvent = 0;
	BOOL gbTimeStampChat = 0;
	BOOL gUseTradeOnTarget = 1;
	BOOL gbBeepOnTells = 0;
	BOOL gbFlashOnTells = 0;
	BOOL gbIgnoreAlertRecursion = 0;
	BOOL gbShowCurrentCamera = 1;
	int  oldcameratype = 0;
	CHAR CameraText[2048] = { "Window Selector (Camera 0)" };
	PVOID EQADDR_GWORLD = 0;
	PDWORD EQADDR_DOABILITYLIST = 0;

	PMAPLABEL *ppCurrentMapLabel = 0;
	PCHAR *EQMappableCommandList = 0;
	PBYTE EQbCommandStates = 0;

	PBYTE EQADDR_ENCRYPTPAD0 = 0;
	PBYTE EQADDR_ENCRYPTPAD1 = 0;
	PBYTE EQADDR_ENCRYPTPAD2 = 0;
	PBYTE EQADDR_ENCRYPTPAD3 = 0;
	PBYTE EQADDR_ENCRYPTPAD4 = 0;

	DWORD *pScreenX = 0;
	DWORD *pScreenY = 0;
	DWORD *pScreenXMax = 0;
	DWORD *pScreenYMax = 0;
	DWORD *pScreenMode = 0;
	CHAR  *pMouseLook = 0;
	PMOUSEINFO EQADDR_MOUSE = 0;
	PMOUSECLICK EQADDR_MOUSECLICK = 0;

#ifndef ISXEQ
	DWORD EQADDR_DIMAIN = 0;
	IDirectInputDevice8A **EQADDR_DIKEYBOARD = 0;
	IDirectInputDevice8A **EQADDR_DIMOUSE = 0;
#endif
	PPOINT EQADDR_DIMOUSECOPY = 0;
	PPOINT EQADDR_DIMOUSECHECK = 0;


	PGUILDS pGuildList = 0;
	PEQSOCIAL   pSocialList = 0;
	PBYTE pgHotkeyPage = 0;
	PINT pgCurrentSocial = 0;

	fEQNewUIINI     NewUIINI = 0;
	fEQProcGameEvts ProcessGameEvents = 0;

	fEQGetMelee     get_melee_range = GetMeleeRange;
	fGetLabelFromEQ GetLabelFromEQ = 0;
#if !defined(ROF2EMU) && !defined(UFEMU)
	fEQToggleKeyRingItem  cmdToggleKeyRingItem = 0;
#endif
	fLoaderSetLoaded	IC_LoaderSetLoaded = 0;
	fLoaderClearLoaded	IC_LoaderClearLoaded = 0;
	fMQ2Unload			IC_MQ2Unload = 0;
	fClassLvl			IC_ClassLvl = 0;

	fEQW_GetDisplayWindow EQW_GetDisplayWindow = 0;

	StringTable **ppStringTable = 0;
	CDBStr **ppCDBStr = 0;
	EQMisc *pEQMisc = 0;
	CSkillMgr **ppCSkillMgr = 0;
	CGuild *pGuild = 0;
	_SKILLMGR **ppSkillMgr = 0;
	_EVERQUESTINFO *ppEverQuestInfo = 0;

	CEverQuest **ppEverQuest = 0;
	CDisplay **ppDisplay = 0;
	CDistillerInfo **ppDistillerInfo = 0;
	EQ_PC **ppPCData = 0;
	EQ_Character **ppCharData = 0;
	EQPlayer **ppCharSpawn = 0;
	EQPlayer **ppActiveMerchant = 0;
	EQPlayerManager **ppSpawnManager = 0;
	EQPlayer **ppLocalPlayer = 0;
	EQPlayer **ppControlledPlayer = 0;
	EQWorldData **ppWorldData = 0;
	ClientSpellManager **ppSpellMgr = 0;
	EQPlayer **ppTarget = 0;
	EqSwitchManager **ppSwitchMgr = 0;
	EQItemList **ppItemList = 0;
	SPELLFAVORITE *pSpellSets = 0;
	EQZoneInfo *pZoneInfo = 0;
	AltAdvManager** ppAltAdvManager = 0;
	CONNECTION_T **ppConnection = 0;
	AURAMGR **ppAuraMgr = 0;
	EQCHATMGR **ppEQChatMgr = 0;

	EQPlayer **ppTradeTarget = 0;
	EQPlayer **ppActiveBanker = 0;
	EQPlayer **ppActiveGMaster = 0;
	EQPlayer **ppActiveCorpse = 0;

	/* WINDOW INSTANCES */
	LootFiltersManager **ppLootFiltersManager = 0;
	EQSpellStrings ** ppEQSpellStrings = 0;
	CAuraWnd **ppAuraWnd = 0;
	CContextMenuManager **ppContextMenuManager = 0;
	CCursorAttachment **ppCursorAttachment = 0;
	CSocialEditWnd **ppSocialEditWnd = 0;
	CContainerMgr **ppContainerMgr = 0;
	CChatManager **ppChatManager = 0;
	CFacePick **ppFacePick = 0;
	CFactionWnd **ppFactionWnd = 0;
	CExtendedTargetWnd **ppExtendedTargetWnd = 0;
	#if !defined(ROF2EMU) && !defined(UFEMU)
	CFindItemWnd **ppFindItemWnd = 0;
	#endif
	CFindLocationWnd **ppFindLocationWnd = 0;
	CInvSlotMgr **ppInvSlotMgr = 0;
	CNoteWnd **ppNoteWnd = 0;
	CTipWnd **ppTipWndOFDAY = 0;
	CTipWnd **ppTipWndCONTEXT = 0;
	CBookWnd **ppBookWnd = 0;
	CFriendsWnd **ppFriendsWnd = 0;
	CMusicPlayerWnd **ppMusicPlayerWnd = 0;
	
	CRealEstateItemsWnd **ppRealEstateItemsWnd = 0;
	CAchievementsWnd **ppAchievementsWnd = 0;
	CAlarmWnd **ppAlarmWnd = 0;
	CLoadskinWnd **ppLoadskinWnd = 0;
	CPetInfoWnd **ppPetInfoWnd = 0;
	CRespawnWnd **ppRespawnWnd = 0;
	CTrainWnd **ppTrainWnd = 0;
	CSkillsWnd **ppSkillsWnd = 0;
	CSkillsSelectWnd **ppSkillsSelectWnd = 0;
	CAAWnd **ppAAWnd = 0;
	CGroupWnd **ppGroupWnd = 0;
	CGroupSearchWnd **ppGroupSearchWnd = 0;
	CGroupSearchFiltersWnd **ppGroupSearchFiltersWnd = 0;
	CRaidWnd **ppRaidWnd = 0;
	CRaidOptionsWnd **ppRaidOptionsWnd = 0;
	CBreathWnd **ppBreathWnd = 0;
	CMapToolbarWnd **ppMapToolbarWnd = 0;
	CMapViewWnd **ppMapViewWnd = 0;
	CEditLabelWnd **ppEditLabelWnd = 0;
	COptionsWnd **ppOptionsWnd = 0;
	CBuffWindow **ppBuffWindowSHORT = 0;
	CBuffWindow **ppBuffWindowNORMAL = 0;
	CTargetWnd **ppTargetWnd = 0;
	CColorPickerWnd **ppColorPickerWnd = 0;
	CCombatSkillsSelectWnd **ppCombatSkillsSelectWnd = 0;
	CHotButtonWnd **ppHotButtonWnd = 0;
	CPlayerWnd **ppPlayerWnd = 0;
	CCastingWnd **ppCastingWnd = 0;
	CCastSpellWnd **ppCastSpellWnd = 0;
	CSpellBookWnd **ppSpellBookWnd = 0;
	CInventoryWnd **ppInventoryWnd = 0;
	CBankWnd **ppBankWnd = 0;
	CQuantityWnd **ppQuantityWnd = 0;
	CTextEntryWnd **ppTextEntryWnd = 0;
	CFileSelectionWnd **ppFileSelectionWnd = 0;
	CLootWnd **ppLootWnd = 0;
	CActionsWnd **ppActionsWnd = 0;
	CCombatAbilityWnd **ppCombatAbilityWnd = 0;
	CMerchantWnd **ppMerchantWnd = 0;
	CTradeWnd **ppTradeWnd = 0;
	CBazaarWnd **ppBazaarWnd = 0;
	CBazaarSearchWnd **ppBazaarSearchWnd = 0;
	CGiveWnd **ppGiveWnd = 0;
	CSelectorWnd **ppSelectorWnd = 0;
	CTrackingWnd **ppTrackingWnd = 0;
	CInspectWnd **ppInspectWnd = 0;
	CFeedbackWnd **ppFeedbackWnd = 0;
	CBugReportWnd **ppBugReportWnd = 0;
	CVideoModesWnd **ppVideoModesWnd = 0;
	CCompassWnd **ppCompassWnd = 0;
	CPlayerNotesWnd **ppPlayerNotesWnd = 0;
	CGemsGameWnd **ppGemsGameWnd = 0;
	CStoryWnd **ppStoryWnd = 0;
	CBodyTintWnd **ppBodyTintWnd = 0;
	CGuildMgmtWnd **ppGuildMgmtWnd = 0;
	CJournalTextWnd **ppJournalTextWnd = 0;
	CJournalCatWnd **ppJournalCatWnd = 0;
	CPetitionQWnd **ppPetitionQWnd = 0;
#if defined(ROF2EMU) || defined(UFEMU)
	CSoulmarkWnd **ppSoulmarkWnd = 0;
	CPotionBeltWnd **ppPotionBeltWnd = 0;
#endif
	CBandolierWnd **ppBandolierWnd = 0;
	CWebManager **ppCWebManager = 0;
	CTaskWnd **ppTaskWnd = 0;
	CTaskManager *ppTaskManager = 0;
	CTimeLeftWnd **ppTimeLeftWnd = 0;
	CTextOverlay **ppTextOverlay = 0;
	CAdvancedLootWnd **ppAdvancedLootWnd = 0;
	CRewardSelectionWnd **ppRewardSelectionWnd = 0;
	CConfirmationDialog **ppConfirmationDialog = 0;
	CEQSuiteTextureLoader *ppEQSuiteTextureLoader = 0;
	PointMerchantWnd **ppPointMerchantWnd = 0;
	CZoneGuideWnd **ppCZoneGuideWnd = 0;
	
	CSidlManager **ppSidlMgr = 0;
	CXWndManager **ppWndMgr = 0;
	KeypressHandler **ppKeypressHandler = 0;
	PEQRAID pRaid = 0;
	DZMEMBER **ppDZMember = 0;
	DZTIMERINFO **ppDZTimerInfo = 0;
	TASKMEMBER **ppTaskMember = 0;
	DYNAMICZONE *pDynamicZone = 0;
	MERCENARYINFO **ppMercInfo = 0;
#if !defined(ROF2EMU) && !defined(UFEMU)
	EQMERCALTABILITIES **ppMercAltAbilities = 0;
#endif
	AGGROINFO **ppAggroInfo = 0;
	CLargeDialogWnd**ppLargeDialog = 0;
	CItemDisplayManager**ppItemDisplayManager = 0;
	EqSoundManager**ppEqSoundManager = 0;

#define INITIALIZE_EQGAME_OFFSET(var) DWORD var = (((DWORD)var##_x - 0x400000) + baseAddress)

#ifdef PRIVATE
#include "MQ2Globals-private.cpp"
#endif

	INITIALIZE_EQGAME_OFFSET(__ActualVersionDate);
	INITIALIZE_EQGAME_OFFSET(__ActualVersionTime);
	INITIALIZE_EQGAME_OFFSET(__MemChecker0);
	INITIALIZE_EQGAME_OFFSET(__MemChecker1);
	INITIALIZE_EQGAME_OFFSET(__MemChecker2);
	INITIALIZE_EQGAME_OFFSET(__MemChecker3);
	INITIALIZE_EQGAME_OFFSET(__MemChecker4);
	INITIALIZE_EQGAME_OFFSET(__EncryptPad0);
	INITIALIZE_EQGAME_OFFSET(__EncryptPad1);
	INITIALIZE_EQGAME_OFFSET(__EncryptPad2);
	INITIALIZE_EQGAME_OFFSET(__EncryptPad3);
	INITIALIZE_EQGAME_OFFSET(__EncryptPad4);
	INITIALIZE_EQGAME_OFFSET(__EncryptPad5);
	INITIALIZE_EQGAME_OFFSET(__AC1);
	INITIALIZE_EQGAME_OFFSET(__AC2);
	INITIALIZE_EQGAME_OFFSET(__AC3);
	INITIALIZE_EQGAME_OFFSET(__AC4);
	INITIALIZE_EQGAME_OFFSET(__AC5);
	INITIALIZE_EQGAME_OFFSET(__AC6);
	INITIALIZE_EQGAME_OFFSET(__AC7);
	INITIALIZE_EQGAME_OFFSET(__EP1_Data);
	INITIALIZE_EQGAME_OFFSET(DI8__Main);
	INITIALIZE_EQGAME_OFFSET(DI8__Keyboard);
	INITIALIZE_EQGAME_OFFSET(DI8__Mouse);
	INITIALIZE_EQGAME_OFFSET(DI8__Mouse_Copy);
	INITIALIZE_EQGAME_OFFSET(DI8__Mouse_Check);

	#if !defined(ROF2EMU) && !defined(UFEMU)
	INITIALIZE_EQGAME_OFFSET(__AutoSkillArray);
	#endif
	INITIALIZE_EQGAME_OFFSET(__Attack);
	INITIALIZE_EQGAME_OFFSET(__Autofire);
	INITIALIZE_EQGAME_OFFSET(__BindList);
	INITIALIZE_EQGAME_OFFSET(g_eqCommandStates);
	INITIALIZE_EQGAME_OFFSET(__Clicks);
	INITIALIZE_EQGAME_OFFSET(__CommandList);
	INITIALIZE_EQGAME_OFFSET(__CurrentMapLabel);
	INITIALIZE_EQGAME_OFFSET(__CurrentSocial);
	INITIALIZE_EQGAME_OFFSET(__DoAbilityList);
	INITIALIZE_EQGAME_OFFSET(__do_loot);
	INITIALIZE_EQGAME_OFFSET(__DrawHandler);
	INITIALIZE_EQGAME_OFFSET(__GroupAggro);
	INITIALIZE_EQGAME_OFFSET(__Guilds);
	INITIALIZE_EQGAME_OFFSET(__gWorld);
	#if defined(ROF2EMU) || defined(UFEMU)
	INITIALIZE_EQGAME_OFFSET(__HotkeyPage);
	#endif
	INITIALIZE_EQGAME_OFFSET(__HWnd);
	INITIALIZE_EQGAME_OFFSET(__heqmain);
	INITIALIZE_EQGAME_OFFSET(__InChatMode);
	INITIALIZE_EQGAME_OFFSET(__Inviter);
	INITIALIZE_EQGAME_OFFSET(__LastTell);
	INITIALIZE_EQGAME_OFFSET(__LMouseHeldTime);
	INITIALIZE_EQGAME_OFFSET(__LoginName);
	INITIALIZE_EQGAME_OFFSET(__Mouse);
	INITIALIZE_EQGAME_OFFSET(__MouseLook);
	INITIALIZE_EQGAME_OFFSET(__MouseEventTime);
	INITIALIZE_EQGAME_OFFSET(__gpbCommandEvent);
	INITIALIZE_EQGAME_OFFSET(__NetStatusToggle);
	INITIALIZE_EQGAME_OFFSET(__PCNames);
	INITIALIZE_EQGAME_OFFSET(__RangeAttackReady);
	INITIALIZE_EQGAME_OFFSET(__RMouseHeldTime);
	INITIALIZE_EQGAME_OFFSET(__RunWalkState);
	INITIALIZE_EQGAME_OFFSET(__ScreenMode);
	INITIALIZE_EQGAME_OFFSET(__ScreenX);
	INITIALIZE_EQGAME_OFFSET(__ScreenY);
	INITIALIZE_EQGAME_OFFSET(__ScreenXMax);
	INITIALIZE_EQGAME_OFFSET(__ScreenYMax);
	INITIALIZE_EQGAME_OFFSET(__ServerHost);
	INITIALIZE_EQGAME_OFFSET(__ServerName);
	INITIALIZE_EQGAME_OFFSET(__ShiftKeyDown);
	INITIALIZE_EQGAME_OFFSET(__ShowNames);
	INITIALIZE_EQGAME_OFFSET(__Socials);
	INITIALIZE_EQGAME_OFFSET(__SubscriptionType);
	INITIALIZE_EQGAME_OFFSET(__TargetAggroHolder);
	INITIALIZE_EQGAME_OFFSET(__ZoneType);
	INITIALIZE_EQGAME_OFFSET(__UseTellWindows);
	INITIALIZE_EQGAME_OFFSET(instCRaid);
	INITIALIZE_EQGAME_OFFSET(instEQZoneInfo);
	INITIALIZE_EQGAME_OFFSET(instKeypressHandler);
	INITIALIZE_EQGAME_OFFSET(pinstActiveBanker);
	INITIALIZE_EQGAME_OFFSET(pinstActiveCorpse);
	INITIALIZE_EQGAME_OFFSET(pinstActiveGMaster);
	INITIALIZE_EQGAME_OFFSET(pinstActiveMerchant);
	INITIALIZE_EQGAME_OFFSET(pinstAggroInfo);
	INITIALIZE_EQGAME_OFFSET(pinstAltAdvManager);
	INITIALIZE_EQGAME_OFFSET(pinstAuraMgr);
	INITIALIZE_EQGAME_OFFSET(pinstBandageTarget);
	INITIALIZE_EQGAME_OFFSET(pinstCamActor);
	INITIALIZE_EQGAME_OFFSET(pinstCDBStr);
	INITIALIZE_EQGAME_OFFSET(pinstCDisplay);
	INITIALIZE_EQGAME_OFFSET(pinstCEverQuest);
	INITIALIZE_EQGAME_OFFSET(pinstEverQuestInfo);
	INITIALIZE_EQGAME_OFFSET(pinstCharData);
	INITIALIZE_EQGAME_OFFSET(pinstCharSpawn);
	INITIALIZE_EQGAME_OFFSET(pinstControlledMissile);
	INITIALIZE_EQGAME_OFFSET(pinstControlledPlayer);
	INITIALIZE_EQGAME_OFFSET(pinstCResolutionHandler);
	INITIALIZE_EQGAME_OFFSET(pinstCSidlManager);
	INITIALIZE_EQGAME_OFFSET(pinstCXWndManager);
	INITIALIZE_EQGAME_OFFSET(instDynamicZone);
	INITIALIZE_EQGAME_OFFSET(pinstDZMember);
	INITIALIZE_EQGAME_OFFSET(pinstDZTimerInfo);
	INITIALIZE_EQGAME_OFFSET(pinstEQItemList);
	INITIALIZE_EQGAME_OFFSET(pinstEQObjectList);
	INITIALIZE_EQGAME_OFFSET(instEQMisc);
	INITIALIZE_EQGAME_OFFSET(pinstEQSoundManager);
	INITIALIZE_EQGAME_OFFSET(instExpeditionLeader);
	INITIALIZE_EQGAME_OFFSET(instExpeditionName);
	INITIALIZE_EQGAME_OFFSET(pinstGroup);
	INITIALIZE_EQGAME_OFFSET(pinstImeManager);
	INITIALIZE_EQGAME_OFFSET(pinstLocalPlayer);
	INITIALIZE_EQGAME_OFFSET(pinstMercenaryData);
#if !defined(ROF2EMU) && !defined(UFEMU)
	INITIALIZE_EQGAME_OFFSET(pinstEQSpellStrings);
	INITIALIZE_EQGAME_OFFSET(pinstMercenaryStats);
	INITIALIZE_EQGAME_OFFSET(pinstMercAltAbilities);
#endif
	INITIALIZE_EQGAME_OFFSET(pinstModelPlayer);
	INITIALIZE_EQGAME_OFFSET(pinstPCData);
	INITIALIZE_EQGAME_OFFSET(pinstSkillMgr);
	INITIALIZE_EQGAME_OFFSET(pinstSpawnManager);
	INITIALIZE_EQGAME_OFFSET(pinstSpellManager);
	INITIALIZE_EQGAME_OFFSET(pinstSpellSets);
	INITIALIZE_EQGAME_OFFSET(pinstStringTable);
	INITIALIZE_EQGAME_OFFSET(pinstSwitchManager);
	INITIALIZE_EQGAME_OFFSET(pinstTarget);
	INITIALIZE_EQGAME_OFFSET(pinstTargetObject);
	INITIALIZE_EQGAME_OFFSET(pinstTargetSwitch);
	INITIALIZE_EQGAME_OFFSET(pinstTaskMember);
	INITIALIZE_EQGAME_OFFSET(pinstTrackTarget);
	INITIALIZE_EQGAME_OFFSET(pinstTradeTarget);
	INITIALIZE_EQGAME_OFFSET(instTributeActive);
	INITIALIZE_EQGAME_OFFSET(pinstViewActor);
	INITIALIZE_EQGAME_OFFSET(pinstWorldData);
	INITIALIZE_EQGAME_OFFSET(pinstPlayerPath);
	INITIALIZE_EQGAME_OFFSET(pinstTargetIndicator);
	INITIALIZE_EQGAME_OFFSET(pinstCTargetManager);
	INITIALIZE_EQGAME_OFFSET(EQObject_Top);
	INITIALIZE_EQGAME_OFFSET(pinstRealEstateItems);
		
	INITIALIZE_EQGAME_OFFSET(pinstCRealEstateItemsWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCAchievementsWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCTextOverlay);
	INITIALIZE_EQGAME_OFFSET(pinstCAudioTriggersWindow);
	INITIALIZE_EQGAME_OFFSET(pinstCCharacterListWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCFacePick);
	#if !defined(ROF2EMU) && !defined(UFEMU)
	INITIALIZE_EQGAME_OFFSET(pinstCFactionWnd);
	#endif
	INITIALIZE_EQGAME_OFFSET(pinstCExtendedTargetWnd);
	
	#if !defined(ROF2EMU) && !defined(UFEMU)
	INITIALIZE_EQGAME_OFFSET(pinstCFindItemWnd);
	#endif
	INITIALIZE_EQGAME_OFFSET(pinstCNoteWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCBookWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCPetInfoWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCTrainWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCSkillsWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCSkillsSelectWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCCombatSkillsSelectWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCFriendsWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCAuraWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCRespawnWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCBandolierWnd);
	#if defined(ROF2EMU) || defined(UFEMU)
	INITIALIZE_EQGAME_OFFSET(pinstCPotionBeltWnd);
	#endif
	INITIALIZE_EQGAME_OFFSET(pinstCAAWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCGroupSearchFiltersWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCLoadskinWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCAlarmWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCMusicPlayerWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCMailWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCMailCompositionWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCMailAddressBookWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCRaidWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCRaidOptionsWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCBreathWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCMapViewWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCMapToolbarWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCEditLabelWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCTargetWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCColorPickerWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCPlayerWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCOptionsWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCBuffWindowNORMAL);
	INITIALIZE_EQGAME_OFFSET(pinstCBuffWindowSHORT);
	INITIALIZE_EQGAME_OFFSET(pinstCharacterCreation);
	INITIALIZE_EQGAME_OFFSET(pinstCCursorAttachment);
	INITIALIZE_EQGAME_OFFSET(pinstCCastingWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCCastSpellWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCSpellBookWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCInventoryWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCBankWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCQuantityWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCLootWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCActionsWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCCombatAbilityWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCMerchantWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCTradeWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCSelectorWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCBazaarWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCBazaarSearchWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCGiveWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCTrackingWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCInspectWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCSocialEditWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCBugReportWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCVideoModesWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCTextEntryWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCFileSelectionWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCCompassWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCPlayerNotesWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCGemsGameWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCTimeLeftWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCPetitionQWnd);
#if defined(ROF2EMU) || defined(UFEMU)
	INITIALIZE_EQGAME_OFFSET(pinstCSoulmarkWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCFeedbackWnd);
#endif
	INITIALIZE_EQGAME_OFFSET(pinstCStoryWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCJournalTextWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCJournalCatWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCBodyTintWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCServerListWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCAvaZoneWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCBlockedBuffWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCBlockedPetBuffWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCInvSlotMgr);
	INITIALIZE_EQGAME_OFFSET(pinstCContainerMgr);
	INITIALIZE_EQGAME_OFFSET(pinstCAdventureLeaderboardWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCAdventureRequestWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCAltStorageWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCAdventureStatsWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCBarterMerchantWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCBarterSearchWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCBarterWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCChatWindowManager);
	#if !defined(ROF2EMU) && !defined(UFEMU)
	INITIALIZE_EQGAME_OFFSET(pinstCDistillerInfo);
	#endif
	INITIALIZE_EQGAME_OFFSET(pinstCDynamicZoneWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCEQMainWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCFellowshipWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCFindLocationWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCGroupSearchWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCGroupWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCGuildBankWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCGuildMgmtWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCHotButtonWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCHotButtonWnd1);
	INITIALIZE_EQGAME_OFFSET(pinstCHotButtonWnd2);
	INITIALIZE_EQGAME_OFFSET(pinstCHotButtonWnd3);
	INITIALIZE_EQGAME_OFFSET(pinstCHotButtonWnd4);
	INITIALIZE_EQGAME_OFFSET(pinstCItemDisplayManager);
	INITIALIZE_EQGAME_OFFSET(pinstCItemExpTransferWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCLFGuildWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCMIZoneSelectWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCConfirmationDialog);
	#if defined(ROF2EMU) || defined(UFEMU)
	INITIALIZE_EQGAME_OFFSET(pinstCPointMerchantWnd);
	#endif
	INITIALIZE_EQGAME_OFFSET(pinstCZoneGuideWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCPopupWndManager);
	INITIALIZE_EQGAME_OFFSET(pinstCProgressionSelectionWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCPvPStatsWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCLargeDialogWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCTaskWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCTaskManager);
	INITIALIZE_EQGAME_OFFSET(pinstCTaskTemplateSelectWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCTipWndOFDAY);
	INITIALIZE_EQGAME_OFFSET(pinstCTipWndCONTEXT);
	INITIALIZE_EQGAME_OFFSET(pinstCTitleWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCContextMenuManager);
	INITIALIZE_EQGAME_OFFSET(pinstCVoiceMacroWnd);
	INITIALIZE_EQGAME_OFFSET(pinstCWebManager);
#if !defined(ROF2EMU) && !defined(UFEMU)
	INITIALIZE_EQGAME_OFFSET(pinstCAdvancedLootWnd);
#endif
	INITIALIZE_EQGAME_OFFSET(pinstItemIconCache);
	INITIALIZE_EQGAME_OFFSET(pinstRewardSelectionWnd);
	INITIALIZE_EQGAME_OFFSET(pinstEQSuiteTextureLoader);

	INITIALIZE_EQGAME_OFFSET(__CastRay);
	INITIALIZE_EQGAME_OFFSET(__CastRay2);
	INITIALIZE_EQGAME_OFFSET(__HeadingDiff);
	INITIALIZE_EQGAME_OFFSET(__FixHeading);
	INITIALIZE_EQGAME_OFFSET(__get_bearing);
	
	INITIALIZE_EQGAME_OFFSET(__ConvertItemTags);
	INITIALIZE_EQGAME_OFFSET(__ExecuteCmd);

	INITIALIZE_EQGAME_OFFSET(__EQGetTime);
	INITIALIZE_EQGAME_OFFSET(__get_melee_range);
	INITIALIZE_EQGAME_OFFSET(__GetGaugeValueFromEQ);
	INITIALIZE_EQGAME_OFFSET(__GetLabelFromEQ);
#if !defined(ROF2EMU) && !defined(UFEMU)
	INITIALIZE_EQGAME_OFFSET(__ToggleKeyRingItem);
	INITIALIZE_EQGAME_OFFSET(wwsCrashReportCheckForUploader);
	INITIALIZE_EQGAME_OFFSET(wwsCrashReportPlatformLaunchUploader);
	INITIALIZE_EQGAME_OFFSET(__AppCrashWrapper);
	INITIALIZE_EQGAME_OFFSET(__pCrashHandler);
	INITIALIZE_EQGAME_OFFSET(__CrashHandler);
#endif
	INITIALIZE_EQGAME_OFFSET(__GetXTargetType);
	INITIALIZE_EQGAME_OFFSET(__LoadFrontEnd);
	INITIALIZE_EQGAME_OFFSET(__NewUIINI);
	INITIALIZE_EQGAME_OFFSET(__ProcessGameEvents);
	INITIALIZE_EQGAME_OFFSET(CrashDetected);
	INITIALIZE_EQGAME_OFFSET(__SaveColors);
	INITIALIZE_EQGAME_OFFSET(__HandleMouseWheel);
	
	INITIALIZE_EQGAME_OFFSET(DrawNetStatus);
	INITIALIZE_EQGAME_OFFSET(Util__FastTime);
	INITIALIZE_EQGAME_OFFSET(Expansion_HoT);
	INITIALIZE_EQGAME_OFFSET(__HelpPath);
	INITIALIZE_EQGAME_OFFSET(__STMLToText);
	INITIALIZE_EQGAME_OFFSET(__GetAnimationCache);
	INITIALIZE_EQGAME_OFFSET(Teleport_Table);
	INITIALIZE_EQGAME_OFFSET(Teleport_Table_Size);

#if !defined(ROF2EMU) && !defined(UFEMU)
	INITIALIZE_EQGAME_OFFSET(CAdvancedLootWnd__CAdvancedLootWnd);
	INITIALIZE_EQGAME_OFFSET(CAdvancedLootWnd__DoAdvLootAction);
	INITIALIZE_EQGAME_OFFSET(CAdvancedLootWnd__DoSharedAdvLootAction);
	INITIALIZE_EQGAME_OFFSET(CAltAbilityData__GetMercCurrentRank);
	INITIALIZE_EQGAME_OFFSET(CAltAbilityData__GetMercMaxRank);
#endif
	INITIALIZE_EQGAME_OFFSET(AltAdvManager__GetCalculatedTimer);
	INITIALIZE_EQGAME_OFFSET(AltAdvManager__IsAbilityReady);
	INITIALIZE_EQGAME_OFFSET(AltAdvManager__GetAAById);
	INITIALIZE_EQGAME_OFFSET(AltAdvManager__CanTrainAbility);
	INITIALIZE_EQGAME_OFFSET(AltAdvManager__CanSeeAbility);
	
	INITIALIZE_EQGAME_OFFSET(CAltAbilityData__GetMaxRank);

	INITIALIZE_EQGAME_OFFSET(CCastSpellWnd__ForgetMemorizedSpell);
	INITIALIZE_EQGAME_OFFSET(CCastSpellWnd__IsBardSongPlaying);
	
	INITIALIZE_EQGAME_OFFSET(CharacterZoneClient__CharacterZoneClient);
	INITIALIZE_EQGAME_OFFSET(CharacterZoneClient__HasSkill);
	INITIALIZE_EQGAME_OFFSET(CharacterZoneClient__MakeMeVisible);
	INITIALIZE_EQGAME_OFFSET(CharacterZoneClient__IsStackBlocked);
	INITIALIZE_EQGAME_OFFSET(CharacterZoneClient__CanUseMemorizedSpellSlot);
	INITIALIZE_EQGAME_OFFSET(CharacterZoneClient__GetItemCountWorn);
	INITIALIZE_EQGAME_OFFSET(CharacterZoneClient__GetItemCountInInventory);
	INITIALIZE_EQGAME_OFFSET(CharacterZoneClient__GetCursorItemCount);
	INITIALIZE_EQGAME_OFFSET(CharacterZoneClient__FindAffectSlot);
	INITIALIZE_EQGAME_OFFSET(CharacterZoneClient__BardCastBard);
	INITIALIZE_EQGAME_OFFSET(CharacterZoneClient__GetMaxEffects);
	INITIALIZE_EQGAME_OFFSET(CharacterZoneClient__GetEffect);
	INITIALIZE_EQGAME_OFFSET(CharacterZoneClient__GetOpenEffectSlot);
	INITIALIZE_EQGAME_OFFSET(CharacterZoneClient__GetFirstEffectSlot);
	INITIALIZE_EQGAME_OFFSET(CharacterZoneClient__GetLastEffectSlot);
	
	#if !defined(ROF2EMU) && !defined(UFEMU)
	INITIALIZE_EQGAME_OFFSET(CFindItemWnd__Update);
	INITIALIZE_EQGAME_OFFSET(CFindItemWnd__PickupSelectedItem);
	INITIALIZE_EQGAME_OFFSET(CFindItemWnd__WndNotification);
	#endif
	INITIALIZE_EQGAME_OFFSET(CBankWnd__WndNotification);
	INITIALIZE_EQGAME_OFFSET(CBankWnd__GetNumBankSlots);
	INITIALIZE_EQGAME_OFFSET(CBazaarSearchWnd__HandleBazaarMsg);
	INITIALIZE_EQGAME_OFFSET(CButtonWnd__SetCheck);
	INITIALIZE_EQGAME_OFFSET(CChatManager__GetRGBAFromIndex);
	INITIALIZE_EQGAME_OFFSET(CChatManager__InitContextMenu);
	INITIALIZE_EQGAME_OFFSET(CChatManager__FreeChatWindow);
	INITIALIZE_EQGAME_OFFSET(CChatManager__GetLockedActiveChatWindow);
	INITIALIZE_EQGAME_OFFSET(CChatManager__SetLockedActiveChatWindow);
	
	INITIALIZE_EQGAME_OFFSET(CContextMenu__CContextMenu);
	INITIALIZE_EQGAME_OFFSET(CContextMenu__dCContextMenu);
	INITIALIZE_EQGAME_OFFSET(CContextMenu__AddMenuItem);
	INITIALIZE_EQGAME_OFFSET(CContextMenuManager__AddMenu);
	INITIALIZE_EQGAME_OFFSET(CContextMenuManager__RemoveMenu);
	INITIALIZE_EQGAME_OFFSET(CContextMenuManager__PopupMenu);
	INITIALIZE_EQGAME_OFFSET(CContextMenu__RemoveMenuItem);
	INITIALIZE_EQGAME_OFFSET(CContextMenu__RemoveAllMenuItems);
	INITIALIZE_EQGAME_OFFSET(CContextMenu__CheckMenuItem);
	INITIALIZE_EQGAME_OFFSET(CContextMenu__SetMenuItem);
	INITIALIZE_EQGAME_OFFSET(CContextMenu__AddSeparator);
	
	INITIALIZE_EQGAME_OFFSET(CContextMenuManager__Flush);
	INITIALIZE_EQGAME_OFFSET(CContextMenuManager__GetMenu);
	INITIALIZE_EQGAME_OFFSET(CContextMenuManager__CreateDefaultMenu);
	
	INITIALIZE_EQGAME_OFFSET(CChatService__GetNumberOfFriends);
	INITIALIZE_EQGAME_OFFSET(CChatService__GetFriendName);

	INITIALIZE_EQGAME_OFFSET(CChatWindow__CChatWindow);
	INITIALIZE_EQGAME_OFFSET(CChatWindow__Clear);
	INITIALIZE_EQGAME_OFFSET(CChatWindow__WndNotification);

	INITIALIZE_EQGAME_OFFSET(CComboWnd__DeleteAll);
	INITIALIZE_EQGAME_OFFSET(CComboWnd__Draw);
	INITIALIZE_EQGAME_OFFSET(CComboWnd__GetCurChoice);
	INITIALIZE_EQGAME_OFFSET(CComboWnd__GetListRect);
	INITIALIZE_EQGAME_OFFSET(CComboWnd__GetTextRect);
	INITIALIZE_EQGAME_OFFSET(CComboWnd__InsertChoice);
	INITIALIZE_EQGAME_OFFSET(CComboWnd__SetColors);
	INITIALIZE_EQGAME_OFFSET(CComboWnd__SetChoice);
	INITIALIZE_EQGAME_OFFSET(CComboWnd__GetItemCount);
	INITIALIZE_EQGAME_OFFSET(CComboWnd__GetCurChoiceText);
	
	INITIALIZE_EQGAME_OFFSET(CContainerWnd__HandleCombine);
	INITIALIZE_EQGAME_OFFSET(CContainerWnd__vftable);
	INITIALIZE_EQGAME_OFFSET(CContainerWnd__SetContainer);
	
	INITIALIZE_EQGAME_OFFSET(CDisplay__CleanGameUI);
	INITIALIZE_EQGAME_OFFSET(CDisplay__GetClickedActor);
	INITIALIZE_EQGAME_OFFSET(CDisplay__GetUserDefinedColor);
	INITIALIZE_EQGAME_OFFSET(CDisplay__GetWorldFilePath);
	INITIALIZE_EQGAME_OFFSET(CDisplay__is3dON);
	INITIALIZE_EQGAME_OFFSET(CDisplay__ReloadUI);
	INITIALIZE_EQGAME_OFFSET(CDisplay__WriteTextHD2);
	INITIALIZE_EQGAME_OFFSET(CDisplay__TrueDistance);
	INITIALIZE_EQGAME_OFFSET(CDisplay__SetViewActor);
    INITIALIZE_EQGAME_OFFSET(CDisplay__GetFloorHeight);
	INITIALIZE_EQGAME_OFFSET(CDisplay__SetRenderWindow);
	INITIALIZE_EQGAME_OFFSET(CDisplay__ToggleScreenshotMode);
	
	INITIALIZE_EQGAME_OFFSET(CEditBaseWnd__SetSel);

	INITIALIZE_EQGAME_OFFSET(CEditWnd__DrawCaret);
	INITIALIZE_EQGAME_OFFSET(CEditWnd__GetCharIndexPt);
	INITIALIZE_EQGAME_OFFSET(CEditWnd__GetDisplayString);
	INITIALIZE_EQGAME_OFFSET(CEditWnd__GetHorzOffset);
	INITIALIZE_EQGAME_OFFSET(CEditWnd__GetLineForPrintableChar);
	INITIALIZE_EQGAME_OFFSET(CEditWnd__GetSelStartPt);
	INITIALIZE_EQGAME_OFFSET(CEditWnd__GetSTMLSafeText);
	INITIALIZE_EQGAME_OFFSET(CEditWnd__PointFromPrintableChar);
	INITIALIZE_EQGAME_OFFSET(CEditWnd__SelectableCharFromPoint);
	INITIALIZE_EQGAME_OFFSET(CEditWnd__SetEditable);

	INITIALIZE_EQGAME_OFFSET(CEverQuest__DoPercentConvert);
	INITIALIZE_EQGAME_OFFSET(CEverQuest__ClickedPlayer);
	INITIALIZE_EQGAME_OFFSET(CEverQuest__DoTellWindow);
	INITIALIZE_EQGAME_OFFSET(CEverQuest__OutputTextToLog);
	INITIALIZE_EQGAME_OFFSET(CEverQuest__DropHeldItemOnGround);
	INITIALIZE_EQGAME_OFFSET(CEverQuest__dsp_chat);
	INITIALIZE_EQGAME_OFFSET(CEverQuest__trimName);
	INITIALIZE_EQGAME_OFFSET(CEverQuest__Emote);
	INITIALIZE_EQGAME_OFFSET(CEverQuest__EnterZone);
	INITIALIZE_EQGAME_OFFSET(CEverQuest__GetBodyTypeDesc);
	INITIALIZE_EQGAME_OFFSET(CEverQuest__GetClassDesc);
	INITIALIZE_EQGAME_OFFSET(CEverQuest__GetClassThreeLetterCode);
	INITIALIZE_EQGAME_OFFSET(CEverQuest__GetDeityDesc);
	INITIALIZE_EQGAME_OFFSET(CEverQuest__GetLangDesc);
	INITIALIZE_EQGAME_OFFSET(CEverQuest__GetRaceDesc);
	INITIALIZE_EQGAME_OFFSET(CEverQuest__InterpretCmd);
	INITIALIZE_EQGAME_OFFSET(CEverQuest__LeftClickedOnPlayer);
	INITIALIZE_EQGAME_OFFSET(CEverQuest__LMouseUp);
	INITIALIZE_EQGAME_OFFSET(CEverQuest__RightClickedOnPlayer);
	INITIALIZE_EQGAME_OFFSET(CEverQuest__RMouseUp);
	INITIALIZE_EQGAME_OFFSET(CEverQuest__SetGameState);
	INITIALIZE_EQGAME_OFFSET(CEverQuest__UPCNotificationFlush);
	INITIALIZE_EQGAME_OFFSET(CEverQuest__IssuePetCommand);
	INITIALIZE_EQGAME_OFFSET(CEverQuest__ReportSuccessfulHit);
	INITIALIZE_EQGAME_OFFSET(CEverQuest__CreateTargetIndicator);
	INITIALIZE_EQGAME_OFFSET(CEverQuest__DeleteTargetIndicator);
	#if !defined(ROF2EMU) && !defined(UFEMU)
	INITIALIZE_EQGAME_OFFSET(CFindItemWnd__CFindItemWnd);
	#endif
	INITIALIZE_EQGAME_OFFSET(CGaugeWnd__CalcFillRect);
	INITIALIZE_EQGAME_OFFSET(CGaugeWnd__CalcLinesFillRect);
	INITIALIZE_EQGAME_OFFSET(CGaugeWnd__Draw);
	INITIALIZE_EQGAME_OFFSET(IString__Append);
	INITIALIZE_EQGAME_OFFSET(CDisplay__cameraType);
	INITIALIZE_EQGAME_OFFSET(EverQuest__Cameras);
	INITIALIZE_EQGAME_OFFSET(CGuild__FindMemberByName);
	#if !defined(ROF2EMU) && !defined(UFEMU)
	INITIALIZE_EQGAME_OFFSET(pinstLootFiltersManager);
	INITIALIZE_EQGAME_OFFSET(LootFiltersManager__AddItemLootFilter);
	INITIALIZE_EQGAME_OFFSET(LootFiltersManager__GetItemFilterData);
	INITIALIZE_EQGAME_OFFSET(LootFiltersManager__RemoveItemLootFilter);
	INITIALIZE_EQGAME_OFFSET(LootFiltersManager__SetItemLootFilter);
	#endif
	#if !defined(UFEMU)
	INITIALIZE_EQGAME_OFFSET(CGuild__GetGuildName);
	INITIALIZE_EQGAME_OFFSET(CGuild__GetGuildIndex);
	#endif
	INITIALIZE_EQGAME_OFFSET(CResolutionHandler__GetWindowedStyle);
	INITIALIZE_EQGAME_OFFSET(CResolutionHandler__UpdateResolution);
	INITIALIZE_EQGAME_OFFSET(COptionsWnd__FillChatFilterList);
	INITIALIZE_EQGAME_OFFSET(CharacterBase__GetMemorizedSpell);
	INITIALIZE_EQGAME_OFFSET(CharacterBase__CreateItemGlobalIndex);
	INITIALIZE_EQGAME_OFFSET(CharacterBase__CreateItemIndex);
	INITIALIZE_EQGAME_OFFSET(CharacterBase__GetItemPossession);
	INITIALIZE_EQGAME_OFFSET(CharacterBase__GetItemByGlobalIndex);
	INITIALIZE_EQGAME_OFFSET(CharacterBase__GetItemByGlobalIndex1);
	INITIALIZE_EQGAME_OFFSET(CharacterBase__GetEffectId);
	
	INITIALIZE_EQGAME_OFFSET(CHotButtonWnd__DoHotButton);
	INITIALIZE_EQGAME_OFFSET(CHotButton__SetButtonSize);
	
	INITIALIZE_EQGAME_OFFSET(CInvSlotMgr__FindInvSlot);
	INITIALIZE_EQGAME_OFFSET(CInvSlotMgr__MoveItem);
	INITIALIZE_EQGAME_OFFSET(CInvSlotMgr__SelectSlot);

	INITIALIZE_EQGAME_OFFSET(CInvSlot__HandleRButtonUp);
	INITIALIZE_EQGAME_OFFSET(CInvSlot__SliderComplete);
	INITIALIZE_EQGAME_OFFSET(CInvSlot__GetItemBase);
	INITIALIZE_EQGAME_OFFSET(CInvSlot__UpdateItem);
	
	INITIALIZE_EQGAME_OFFSET(CInvSlotWnd__DrawTooltip);
	INITIALIZE_EQGAME_OFFSET(CInvSlotWnd__CInvSlotWnd);
	INITIALIZE_EQGAME_OFFSET(CInvSlotWnd__HandleLButtonUp);
	
	INITIALIZE_EQGAME_OFFSET(CItemDisplayWnd__SetSpell);
	INITIALIZE_EQGAME_OFFSET(CItemDisplayWnd__UpdateStrings);
	INITIALIZE_EQGAME_OFFSET(CItemDisplayWnd__InsertAugmentRequest);
	INITIALIZE_EQGAME_OFFSET(CItemDisplayWnd__RemoveAugmentRequest);
	INITIALIZE_EQGAME_OFFSET(CItemDisplayWnd__SetItem);
	INITIALIZE_EQGAME_OFFSET(CItemDisplayWnd__AboutToShow);
	INITIALIZE_EQGAME_OFFSET(CItemDisplayWnd__WndNotification);
	#if !defined(ROF2EMU) && !defined(UFEMU)
	INITIALIZE_EQGAME_OFFSET(CItemDisplayWnd__RequestConvertItem);
	#endif
	INITIALIZE_EQGAME_OFFSET(CItemDisplayWnd__CItemDisplayWnd);
	INITIALIZE_EQGAME_OFFSET(CItemDisplayWnd__dCItemDisplayWnd);

	INITIALIZE_EQGAME_OFFSET(CLabel__Draw);

	INITIALIZE_EQGAME_OFFSET(CListWnd__CListWnd);
	INITIALIZE_EQGAME_OFFSET(CListWnd__dCListWnd);
	INITIALIZE_EQGAME_OFFSET(CListWnd__AddColumn);
	INITIALIZE_EQGAME_OFFSET(CListWnd__AddColumn1);
	INITIALIZE_EQGAME_OFFSET(CListWnd__AddLine);
	INITIALIZE_EQGAME_OFFSET(CListWnd__AddString);
	INITIALIZE_EQGAME_OFFSET(CListWnd__CalculateFirstVisibleLine);
	INITIALIZE_EQGAME_OFFSET(CListWnd__CalculateVSBRange);
	INITIALIZE_EQGAME_OFFSET(CListWnd__ClearSel);
	INITIALIZE_EQGAME_OFFSET(CListWnd__ClearAllSel);
	INITIALIZE_EQGAME_OFFSET(CListWnd__CloseAndUpdateEditWindow);
	INITIALIZE_EQGAME_OFFSET(CListWnd__Compare);
	INITIALIZE_EQGAME_OFFSET(CListWnd__Draw);
	INITIALIZE_EQGAME_OFFSET(CListWnd__DrawColumnSeparators);
	INITIALIZE_EQGAME_OFFSET(CListWnd__DrawHeader);
	INITIALIZE_EQGAME_OFFSET(CListWnd__DrawItem);
	INITIALIZE_EQGAME_OFFSET(CListWnd__DrawLine);
	INITIALIZE_EQGAME_OFFSET(CListWnd__DrawSeparator);
	INITIALIZE_EQGAME_OFFSET(CListWnd__EnableLine);
	INITIALIZE_EQGAME_OFFSET(CListWnd__EnsureVisible);
	INITIALIZE_EQGAME_OFFSET(CListWnd__ExtendSel);
	INITIALIZE_EQGAME_OFFSET(CListWnd__GetColumnMinWidth);
	INITIALIZE_EQGAME_OFFSET(CListWnd__GetColumnTooltip);
	INITIALIZE_EQGAME_OFFSET(CListWnd__GetColumnWidth);
	INITIALIZE_EQGAME_OFFSET(CListWnd__GetCurSel);
	INITIALIZE_EQGAME_OFFSET(CListWnd__GetItemAtPoint);
	INITIALIZE_EQGAME_OFFSET(CListWnd__GetItemAtPoint1);
	INITIALIZE_EQGAME_OFFSET(CListWnd__GetItemData);
	INITIALIZE_EQGAME_OFFSET(CListWnd__GetItemHeight);
	INITIALIZE_EQGAME_OFFSET(CListWnd__GetItemIcon);
	INITIALIZE_EQGAME_OFFSET(CListWnd__GetItemRect);
	INITIALIZE_EQGAME_OFFSET(CListWnd__GetItemText);
	INITIALIZE_EQGAME_OFFSET(CListWnd__GetSelList);
	INITIALIZE_EQGAME_OFFSET(CListWnd__GetSeparatorRect);
	INITIALIZE_EQGAME_OFFSET(CListWnd__InsertLine);
	INITIALIZE_EQGAME_OFFSET(CListWnd__RemoveLine);
	INITIALIZE_EQGAME_OFFSET(CListWnd__SetColors);
	INITIALIZE_EQGAME_OFFSET(CListWnd__SetColumnJustification);
	INITIALIZE_EQGAME_OFFSET(CListWnd__SetColumnWidth);
	INITIALIZE_EQGAME_OFFSET(CListWnd__SetCurSel);
	INITIALIZE_EQGAME_OFFSET(CListWnd__SetItemColor);
	INITIALIZE_EQGAME_OFFSET(CListWnd__SetItemData);
	INITIALIZE_EQGAME_OFFSET(CListWnd__SetItemText);
	INITIALIZE_EQGAME_OFFSET(CListWnd__ShiftColumnSeparator);
	INITIALIZE_EQGAME_OFFSET(CListWnd__Sort);
	INITIALIZE_EQGAME_OFFSET(CListWnd__ToggleSel);
	INITIALIZE_EQGAME_OFFSET(CListWnd__SetColumnsSizable);
	INITIALIZE_EQGAME_OFFSET(CListWnd__SetItemWnd);
	INITIALIZE_EQGAME_OFFSET(CListWnd__GetItemWnd);
	INITIALIZE_EQGAME_OFFSET(CListWnd__SetItemIcon);
	INITIALIZE_EQGAME_OFFSET(CListWnd__CalculateCustomWindowPositions);
	
	INITIALIZE_EQGAME_OFFSET(CMapViewWnd__CMapViewWnd);
    INITIALIZE_EQGAME_OFFSET(CMapViewWnd__HandleLButtonDown);
    INITIALIZE_EQGAME_OFFSET(CMapViewWnd__GetWorldCoordinates);

	INITIALIZE_EQGAME_OFFSET(CMerchantWnd__DisplayBuyOrSellPrice);
	INITIALIZE_EQGAME_OFFSET(CMerchantWnd__PurchasePageHandler__RequestGetItem);
	INITIALIZE_EQGAME_OFFSET(CMerchantWnd__PurchasePageHandler__RequestPutItem);
	INITIALIZE_EQGAME_OFFSET(CMerchantWnd__SelectBuySellSlot);
	INITIALIZE_EQGAME_OFFSET(CMerchantWnd__PurchasePageHandler__UpdateList);
	
	INITIALIZE_EQGAME_OFFSET(CPacketScrambler__ntoh);
	INITIALIZE_EQGAME_OFFSET(CPacketScrambler__hton);

	
	INITIALIZE_EQGAME_OFFSET(CSidlManager__FindScreenPieceTemplate);
	INITIALIZE_EQGAME_OFFSET(CSidlManager__FindScreenPieceTemplate1);
	INITIALIZE_EQGAME_OFFSET(CSidlManager__CreateLabel);
	INITIALIZE_EQGAME_OFFSET(CSidlManager__CreateXWndFromTemplate);
	INITIALIZE_EQGAME_OFFSET(CSidlManager__CreateXWndFromTemplate1);
	INITIALIZE_EQGAME_OFFSET(CSidlManager__CreateXWnd);
	INITIALIZE_EQGAME_OFFSET(CSidlManager__CreateHotButtonWnd);
	
	INITIALIZE_EQGAME_OFFSET(CSidlScreenWnd__CalculateHSBRange);
	INITIALIZE_EQGAME_OFFSET(CSidlScreenWnd__CalculateVSBRange);
	INITIALIZE_EQGAME_OFFSET(CSidlScreenWnd__ConvertToRes);
	INITIALIZE_EQGAME_OFFSET(CSidlScreenWnd__CreateChildrenFromSidl);
	INITIALIZE_EQGAME_OFFSET(CSidlScreenWnd__CSidlScreenWnd1);
	INITIALIZE_EQGAME_OFFSET(CSidlScreenWnd__CSidlScreenWnd2);
	INITIALIZE_EQGAME_OFFSET(CSidlScreenWnd__dCSidlScreenWnd);
	INITIALIZE_EQGAME_OFFSET(CSidlScreenWnd__DrawSidlPiece);
	INITIALIZE_EQGAME_OFFSET(CSidlScreenWnd__EnableIniStorage);
	INITIALIZE_EQGAME_OFFSET(CSidlScreenWnd__GetSidlPiece);
	INITIALIZE_EQGAME_OFFSET(CSidlScreenWnd__Init1);
	INITIALIZE_EQGAME_OFFSET(CSidlScreenWnd__LoadIniInfo);
	INITIALIZE_EQGAME_OFFSET(CSidlScreenWnd__LoadIniListWnd);
	INITIALIZE_EQGAME_OFFSET(CSidlScreenWnd__LoadSidlScreen);
	INITIALIZE_EQGAME_OFFSET(CSidlScreenWnd__StoreIniInfo);
	INITIALIZE_EQGAME_OFFSET(CSidlScreenWnd__StoreIniVis);
	INITIALIZE_EQGAME_OFFSET(CSidlScreenWnd__WndNotification);
	INITIALIZE_EQGAME_OFFSET(CSidlScreenWnd__GetChildItem);
	INITIALIZE_EQGAME_OFFSET(CSidlScreenWnd__HandleLButtonUp);
	INITIALIZE_EQGAME_OFFSET(CSidlScreenWnd__m_layoutCopy);

	INITIALIZE_EQGAME_OFFSET(CSkillMgr__IsAvailable);
	INITIALIZE_EQGAME_OFFSET(CSkillMgr__GetSkillCap);
	INITIALIZE_EQGAME_OFFSET(CSkillMgr__GetNameToken);
	INITIALIZE_EQGAME_OFFSET(CSkillMgr__IsActivatedSkill);
	INITIALIZE_EQGAME_OFFSET(CSkillMgr__IsCombatSkill);

	INITIALIZE_EQGAME_OFFSET(CSliderWnd__GetValue);
	INITIALIZE_EQGAME_OFFSET(CSliderWnd__SetValue);
	INITIALIZE_EQGAME_OFFSET(CSliderWnd__SetNumTicks);

	INITIALIZE_EQGAME_OFFSET(CSpellBookWnd__MemorizeSet);

	INITIALIZE_EQGAME_OFFSET(CStmlWnd__AppendSTML);
	INITIALIZE_EQGAME_OFFSET(CStmlWnd__CalculateHSBRange);
	INITIALIZE_EQGAME_OFFSET(CStmlWnd__CalculateVSBRange);
	INITIALIZE_EQGAME_OFFSET(CStmlWnd__CanBreakAtCharacter);
	INITIALIZE_EQGAME_OFFSET(CStmlWnd__FastForwardToEndOfTag);
	INITIALIZE_EQGAME_OFFSET(CStmlWnd__ForceParseNow);
	INITIALIZE_EQGAME_OFFSET(CStmlWnd__GetNextTagPiece);
	INITIALIZE_EQGAME_OFFSET(CStmlWnd__GetSTMLText);
	INITIALIZE_EQGAME_OFFSET(CStmlWnd__GetVisibleText);
	INITIALIZE_EQGAME_OFFSET(CStmlWnd__InitializeWindowVariables);
	INITIALIZE_EQGAME_OFFSET(CStmlWnd__MakeStmlColorTag);
	INITIALIZE_EQGAME_OFFSET(CStmlWnd__MakeWndNotificationTag);
	INITIALIZE_EQGAME_OFFSET(CStmlWnd__SetSTMLText);
	INITIALIZE_EQGAME_OFFSET(CStmlWnd__StripFirstSTMLLines);
	INITIALIZE_EQGAME_OFFSET(CStmlWnd__UpdateHistoryString);

	INITIALIZE_EQGAME_OFFSET(CTabWnd__Draw);
	INITIALIZE_EQGAME_OFFSET(CTabWnd__DrawCurrentPage);
	INITIALIZE_EQGAME_OFFSET(CTabWnd__DrawTab);
	INITIALIZE_EQGAME_OFFSET(CTabWnd__GetCurrentPage);
	INITIALIZE_EQGAME_OFFSET(CTabWnd__GetPageInnerRect);
	INITIALIZE_EQGAME_OFFSET(CTabWnd__GetTabInnerRect);
	INITIALIZE_EQGAME_OFFSET(CTabWnd__GetTabRect);
	INITIALIZE_EQGAME_OFFSET(CTabWnd__InsertPage);
	INITIALIZE_EQGAME_OFFSET(CTabWnd__SetPage);
	INITIALIZE_EQGAME_OFFSET(CTabWnd__SetPageRect);
	INITIALIZE_EQGAME_OFFSET(CTabWnd__UpdatePage);
	INITIALIZE_EQGAME_OFFSET(CTabWnd__GetPageFromTabIndex);
	INITIALIZE_EQGAME_OFFSET(CTabWnd__GetCurrentTabIndex);

	INITIALIZE_EQGAME_OFFSET(CPageWnd__GetTabText);
	INITIALIZE_EQGAME_OFFSET(CPageWnd__SetTabText);
	
	INITIALIZE_EQGAME_OFFSET(CTargetRing__Cast);
	INITIALIZE_EQGAME_OFFSET(CTargetWnd__RefreshTargetBuffs);
	INITIALIZE_EQGAME_OFFSET(CTargetWnd__HandleBuffRemoveRequest);
	
	INITIALIZE_EQGAME_OFFSET(CTextOverlay__DisplayText);

	INITIALIZE_EQGAME_OFFSET(CTextureFont__DrawWrappedText);
	INITIALIZE_EQGAME_OFFSET(CTextureFont__GetTextExtent);

	INITIALIZE_EQGAME_OFFSET(CWebManager__CreateHtmlWnd);
	INITIALIZE_EQGAME_OFFSET(CHtmlComponentWnd__ValidateUri);
	INITIALIZE_EQGAME_OFFSET(CHtmlWnd__SetClientCallbacks);
	INITIALIZE_EQGAME_OFFSET(CHtmlWnd__AddObserver);
	INITIALIZE_EQGAME_OFFSET(CHtmlWnd__RemoveObserver);
	INITIALIZE_EQGAME_OFFSET(Window__getProgress);
	INITIALIZE_EQGAME_OFFSET(Window__getStatus);
	INITIALIZE_EQGAME_OFFSET(Window__getURI);

	INITIALIZE_EQGAME_OFFSET(CXMLDataManager__GetXMLData);

	INITIALIZE_EQGAME_OFFSET(CXMLSOMDocumentBase__XMLRead);

	INITIALIZE_EQGAME_OFFSET(CXStr__CXStr);
	INITIALIZE_EQGAME_OFFSET(CXStr__CXStr1);
	INITIALIZE_EQGAME_OFFSET(CXStr__CXStr3);
	INITIALIZE_EQGAME_OFFSET(CXStr__dCXStr);
	INITIALIZE_EQGAME_OFFSET(CXStr__operator_equal);
	INITIALIZE_EQGAME_OFFSET(CXStr__operator_equal1);
	INITIALIZE_EQGAME_OFFSET(CXStr__operator_plus_equal1);
	INITIALIZE_EQGAME_OFFSET(CXStr__SetString);
	
	INITIALIZE_EQGAME_OFFSET(CXWnd__BringToTop);
	INITIALIZE_EQGAME_OFFSET(CXWnd__Center);
	INITIALIZE_EQGAME_OFFSET(CXWnd__ClrFocus);
	INITIALIZE_EQGAME_OFFSET(CXWnd__Destroy);
	INITIALIZE_EQGAME_OFFSET(CXWnd__DoAllDrawing);
	INITIALIZE_EQGAME_OFFSET(CXWnd__DrawChildren);
	INITIALIZE_EQGAME_OFFSET(CXWnd__DrawColoredRect);
	INITIALIZE_EQGAME_OFFSET(CXWnd__DrawTooltip);
	INITIALIZE_EQGAME_OFFSET(CXWnd__DrawTooltipAtPoint);
	INITIALIZE_EQGAME_OFFSET(CXWnd__GetBorderFrame);
	INITIALIZE_EQGAME_OFFSET(CXWnd__GetChildWndAt);
	INITIALIZE_EQGAME_OFFSET(CXWnd__GetClientClipRect);
	INITIALIZE_EQGAME_OFFSET(CXWnd__GetScreenClipRect);
	INITIALIZE_EQGAME_OFFSET(CXWnd__GetScreenRect);
	INITIALIZE_EQGAME_OFFSET(CXWnd__GetTooltipRect);
	INITIALIZE_EQGAME_OFFSET(CXWnd__GetWindowTextA);
	INITIALIZE_EQGAME_OFFSET(CXWnd__IsActive);
	INITIALIZE_EQGAME_OFFSET(CXWnd__IsDescendantOf);
	INITIALIZE_EQGAME_OFFSET(CXWnd__IsReallyVisible);
	INITIALIZE_EQGAME_OFFSET(CXWnd__IsType);
	INITIALIZE_EQGAME_OFFSET(CScreenPieceTemplate__IsType);
	INITIALIZE_EQGAME_OFFSET(CXWnd__Move);
	INITIALIZE_EQGAME_OFFSET(CXWnd__Move1);
	INITIALIZE_EQGAME_OFFSET(CXWnd__ProcessTransition);
	INITIALIZE_EQGAME_OFFSET(CXWnd__Refade);
	INITIALIZE_EQGAME_OFFSET(CXWnd__Resize);
	INITIALIZE_EQGAME_OFFSET(CXWnd__Right);
	INITIALIZE_EQGAME_OFFSET(CXWnd__SetFocus);
	INITIALIZE_EQGAME_OFFSET(CXWnd__SetFont);
	INITIALIZE_EQGAME_OFFSET(CXWnd__SetKeyTooltip);
	INITIALIZE_EQGAME_OFFSET(CXWnd__SetMouseOver);
	INITIALIZE_EQGAME_OFFSET(CXWnd__StartFade);
	INITIALIZE_EQGAME_OFFSET(CXWnd__GetChildItem);
	INITIALIZE_EQGAME_OFFSET(CXWnd__SetParent);
	
	INITIALIZE_EQGAME_OFFSET(CXWndManager__DrawCursor);
	INITIALIZE_EQGAME_OFFSET(CXWndManager__DrawWindows);
	INITIALIZE_EQGAME_OFFSET(CXWndManager__GetKeyboardFlags);
	INITIALIZE_EQGAME_OFFSET(CXWndManager__HandleKeyboardMsg);
	INITIALIZE_EQGAME_OFFSET(CXWndManager__RemoveWnd);

	INITIALIZE_EQGAME_OFFSET(CDBStr__GetString);

	INITIALIZE_EQGAME_OFFSET(EQ_Character__CastSpell);
	INITIALIZE_EQGAME_OFFSET(EQ_Character__Cur_HP);
	INITIALIZE_EQGAME_OFFSET(EQ_Character__GetManaRegen);
	INITIALIZE_EQGAME_OFFSET(EQ_Character__GetHPRegen);
	INITIALIZE_EQGAME_OFFSET(EQ_Character__GetEnduranceRegen);
	INITIALIZE_EQGAME_OFFSET(EQ_Character__Cur_Mana);
	INITIALIZE_EQGAME_OFFSET(EQ_Character__GetAACastingTimeModifier);
	INITIALIZE_EQGAME_OFFSET(ProfileManager__GetCurrentProfile);
	INITIALIZE_EQGAME_OFFSET(EQ_Character__GetFocusCastingTimeModifier);
	INITIALIZE_EQGAME_OFFSET(EQ_Character__GetFocusRangeModifier);
	INITIALIZE_EQGAME_OFFSET(EQ_Character__Max_Endurance);
	INITIALIZE_EQGAME_OFFSET(EQ_Character__Max_HP);
	INITIALIZE_EQGAME_OFFSET(EQ_Character__Max_Mana);
	INITIALIZE_EQGAME_OFFSET(EQ_Character__doCombatAbility);
	INITIALIZE_EQGAME_OFFSET(EQ_Character__UseSkill);
	INITIALIZE_EQGAME_OFFSET(EQ_Character__GetConLevel);
	INITIALIZE_EQGAME_OFFSET(EQ_Character__IsExpansionFlag);
	INITIALIZE_EQGAME_OFFSET(EQ_Character__TotalEffect);
	INITIALIZE_EQGAME_OFFSET(EQ_Character__GetPCSpellAffect);
	INITIALIZE_EQGAME_OFFSET(EQ_Character__SpellDuration);
	INITIALIZE_EQGAME_OFFSET(CharacterZoneClient__FindItemByGuid);
	INITIALIZE_EQGAME_OFFSET(CharacterZoneClient__FindItemByRecord);
	INITIALIZE_EQGAME_OFFSET(EQ_Character__GetAdjustedSkill);
	INITIALIZE_EQGAME_OFFSET(EQ_Character__GetBaseSkill);
	INITIALIZE_EQGAME_OFFSET(EQ_Character__CanUseItem);
	INITIALIZE_EQGAME_OFFSET(BaseProfile__GetItemPossession);
	
	INITIALIZE_EQGAME_OFFSET(ArrayClass__DeleteElement);
	INITIALIZE_EQGAME_OFFSET(__GameLoop);
	
	INITIALIZE_EQGAME_OFFSET(CCharacterListWnd__SelectCharacter);
	INITIALIZE_EQGAME_OFFSET(CCharacterListWnd__EnterWorld);
	INITIALIZE_EQGAME_OFFSET(CCharacterListWnd__Quit);
	INITIALIZE_EQGAME_OFFSET(CCharacterListWnd__UpdateList);

	INITIALIZE_EQGAME_OFFSET(EQ_Item__CanDrop);
	INITIALIZE_EQGAME_OFFSET(EQ_Item__CreateItemTagString);
	INITIALIZE_EQGAME_OFFSET(EQ_Item__IsStackable);
	INITIALIZE_EQGAME_OFFSET(EQ_Item__GetImageNum);
	INITIALIZE_EQGAME_OFFSET(EQ_Item__CreateItemClient);
	INITIALIZE_EQGAME_OFFSET(EQ_Item__GetItemValue);
	INITIALIZE_EQGAME_OFFSET(EQ_Item__ValueSellMerchant);
#if !defined(ROF2EMU) && !defined(UFEMU)
	INITIALIZE_EQGAME_OFFSET(EQ_Item__IsKeyRingItem);
#endif
	INITIALIZE_EQGAME_OFFSET(EQ_Item__CanGoInBag);
	INITIALIZE_EQGAME_OFFSET(EQ_Item__IsEmpty);
	INITIALIZE_EQGAME_OFFSET(EQ_Item__GetAugmentFitBySlot);
	
	INITIALIZE_EQGAME_OFFSET(EQ_LoadingS__SetProgressBar);
	INITIALIZE_EQGAME_OFFSET(EQ_LoadingS__Array);

	INITIALIZE_EQGAME_OFFSET(EQ_PC__AlertInventoryChanged);
	INITIALIZE_EQGAME_OFFSET(EQ_PC__DestroyHeldItemOrMoney);
	INITIALIZE_EQGAME_OFFSET(EQ_PC__GetAlternateAbilityId);
	INITIALIZE_EQGAME_OFFSET(EQ_PC__GetCombatAbility);
	INITIALIZE_EQGAME_OFFSET(EQ_PC__GetPcZoneClient);
	INITIALIZE_EQGAME_OFFSET(EQ_PC__GetCombatAbilityTimer);
	INITIALIZE_EQGAME_OFFSET(EQ_PC__GetItemRecastTimer);
	INITIALIZE_EQGAME_OFFSET(EQ_PC__HasLoreItem);
	INITIALIZE_EQGAME_OFFSET(EQ_PC__GetItemContainedRealEstateIds);
	INITIALIZE_EQGAME_OFFSET(EQ_PC__GetNonArchivedOwnedRealEstates);
	INITIALIZE_EQGAME_OFFSET(EQ_PC__RemoveMyAffect);
#if !defined(ROF2EMU) && !defined(UFEMU)
	INITIALIZE_EQGAME_OFFSET(EQ_PC__GetKeyRingItems);
#endif
	INITIALIZE_EQGAME_OFFSET(EQItemList__EQItemList);
	INITIALIZE_EQGAME_OFFSET(EQItemList__add_item);
	INITIALIZE_EQGAME_OFFSET(EQItemList__delete_item);
	INITIALIZE_EQGAME_OFFSET(EQItemList__FreeItemList);

	INITIALIZE_EQGAME_OFFSET(EQMisc__GetActiveFavorCost);
	
	INITIALIZE_EQGAME_OFFSET(RealEstateManagerClient__GetItemByRealEstateAndItemIds);
	INITIALIZE_EQGAME_OFFSET(RealEstateManagerClient__Instance);
	#if !defined(ROF2EMU) && !defined(UFEMU)
	INITIALIZE_EQGAME_OFFSET(FactionManagerClient__Instance);
	INITIALIZE_EQGAME_OFFSET(FactionManagerClient__HandleFactionMessage);
	#endif
	INITIALIZE_EQGAME_OFFSET(EQPlacedItemManager__Instance);
	INITIALIZE_EQGAME_OFFSET(EQPlacedItemManager__GetItemByGuid);
	INITIALIZE_EQGAME_OFFSET(EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds);
	INITIALIZE_EQGAME_OFFSET(EQPlayer__ChangeBoneStringSprite);
	INITIALIZE_EQGAME_OFFSET(EQPlayer__dEQPlayer);
	INITIALIZE_EQGAME_OFFSET(EQPlayer__DoAttack);
	INITIALIZE_EQGAME_OFFSET(EQPlayer__EQPlayer);
	INITIALIZE_EQGAME_OFFSET(EQPlayer__SetNameSpriteState);
	INITIALIZE_EQGAME_OFFSET(EQPlayer__SetNameSpriteTint);
	INITIALIZE_EQGAME_OFFSET(PlayerBase__HasProperty_j);
	INITIALIZE_EQGAME_OFFSET(EQPlayer__IsTargetable);
	INITIALIZE_EQGAME_OFFSET(EQPlayer__CanSee);
	INITIALIZE_EQGAME_OFFSET(PlayerZoneClient__ChangeHeight);
	INITIALIZE_EQGAME_OFFSET(PlayerZoneClient__GetLevel);
	INITIALIZE_EQGAME_OFFSET(PlayerZoneClient__IsValidTeleport);
	INITIALIZE_EQGAME_OFFSET(EQPlayer__CanSee1);
	INITIALIZE_EQGAME_OFFSET(PlayerBase__GetVisibilityLineSegment);
	#if !defined(UFEMU)
	INITIALIZE_EQGAME_OFFSET(PlayerZoneClient__LegalPlayerRace);
	#endif
	
	INITIALIZE_EQGAME_OFFSET(PlayerClient__GetPcClient);
	INITIALIZE_EQGAME_OFFSET(PcClient__PcClient);
	
	INITIALIZE_EQGAME_OFFSET(EQPlayerManager__GetSpawnByID);
	INITIALIZE_EQGAME_OFFSET(EQPlayerManager__GetSpawnByName);
	INITIALIZE_EQGAME_OFFSET(EQPlayerManager__GetPlayerFromPartialName);
	
	INITIALIZE_EQGAME_OFFSET(KeypressHandler__AttachAltKeyToEqCommand);
	INITIALIZE_EQGAME_OFFSET(KeypressHandler__AttachKeyToEqCommand);
	INITIALIZE_EQGAME_OFFSET(KeypressHandler__ClearCommandStateArray);
	INITIALIZE_EQGAME_OFFSET(KeypressHandler__HandleKeyDown);
	INITIALIZE_EQGAME_OFFSET(KeypressHandler__HandleKeyUp);
	INITIALIZE_EQGAME_OFFSET(KeypressHandler__SaveKeymapping);

	INITIALIZE_EQGAME_OFFSET(MapViewMap__Clear);
	INITIALIZE_EQGAME_OFFSET(MapViewMap__SaveEx);
	INITIALIZE_EQGAME_OFFSET(MapViewMap__SetZoom);
	
	INITIALIZE_EQGAME_OFFSET(PlayerPointManager__GetAltCurrency);

	INITIALIZE_EQGAME_OFFSET(StringTable__getString);

	INITIALIZE_EQGAME_OFFSET(PcZoneClient__GetPcSkillLimit);
	INITIALIZE_EQGAME_OFFSET(PcZoneClient__RemovePetEffect);
	INITIALIZE_EQGAME_OFFSET(PcZoneClient__HasAlternateAbility);
	INITIALIZE_EQGAME_OFFSET(PcZoneClient__CanEquipItem);
	#if !defined(ROF2EMU) && !defined(UFEMU)
	INITIALIZE_EQGAME_OFFSET(ItemGlobalIndex__IsKeyRingLocation);
	INITIALIZE_EQGAME_OFFSET(PcZoneClient__GetCurrentMod);
	#endif
	INITIALIZE_EQGAME_OFFSET(PcZoneClient__GetModCap);
	INITIALIZE_EQGAME_OFFSET(PcZoneClient__GetItemByID);
	INITIALIZE_EQGAME_OFFSET(PcZoneClient__GetItemByItemClass);
	INITIALIZE_EQGAME_OFFSET(PcZoneClient__RemoveBuffEffect);
	INITIALIZE_EQGAME_OFFSET(PcZoneClient__BandolierSwap);
	INITIALIZE_EQGAME_OFFSET(PcZoneClient__GetLinkedSpellReuseTimer);
	
	INITIALIZE_EQGAME_OFFSET(EQSwitch__UseSwitch);
	INITIALIZE_EQGAME_OFFSET(IconCache__GetIcon);
	INITIALIZE_EQGAME_OFFSET(CContainerMgr__OpenContainer);
	INITIALIZE_EQGAME_OFFSET(CContainerMgr__CloseContainer);
	INITIALIZE_EQGAME_OFFSET(CQuantityWnd__Open);
	INITIALIZE_EQGAME_OFFSET(CHelpWnd__SetFile);
	INITIALIZE_EQGAME_OFFSET(EQ_Spell__GetSpellLevelNeeded);
	INITIALIZE_EQGAME_OFFSET(EQ_Spell__SpellAffects);
	INITIALIZE_EQGAME_OFFSET(EQ_Spell__IsStackable);
	INITIALIZE_EQGAME_OFFSET(EQ_Spell__GetSpellAffectBySlot);

	INITIALIZE_EQGAME_OFFSET(EQ_Spell__IsSPAStacking);
	INITIALIZE_EQGAME_OFFSET(EQ_Spell__IsSPAIgnoredByStacking);
	INITIALIZE_EQGAME_OFFSET(EQ_Spell__SpellAffectBase);
	INITIALIZE_EQGAME_OFFSET(EQ_Spell__IsNoRemove);

	#if !defined(ROF2EMU) && !defined(UFEMU)
	INITIALIZE_EQGAME_OFFSET(EQSpellStrings__GetString);
	INITIALIZE_EQGAME_OFFSET(EQ_Spell__GetSpellAffectByIndex);
	INITIALIZE_EQGAME_OFFSET(EQ_Spell__IsDegeneratingLevelMod);
	#endif
	
	INITIALIZE_EQGAME_OFFSET(__IsResEffectSpell);
	INITIALIZE_EQGAME_OFFSET(EQ_Affect__GetAffectData);

	INITIALIZE_EQGAME_OFFSET(CharacterZoneClient__CalcAffectChange);
	INITIALIZE_EQGAME_OFFSET(CharacterZoneClient__CalcAffectChangeGeneric);
	INITIALIZE_EQGAME_OFFSET(CharacterZoneClient__GetFocusReuseMod);
	INITIALIZE_EQGAME_OFFSET(CLootWnd__LootAll);
	INITIALIZE_EQGAME_OFFSET(CLootWnd__RequestLootSlot);
	INITIALIZE_EQGAME_OFFSET(CTargetWnd__GetBuffCaster);
	INITIALIZE_EQGAME_OFFSET(CTargetWnd__WndNotification);
	INITIALIZE_EQGAME_OFFSET(CTaskWnd__UpdateTaskTimers);
	INITIALIZE_EQGAME_OFFSET(CTaskManager__GetEntry);
	INITIALIZE_EQGAME_OFFSET(EqSoundManager__WavePlay);
	INITIALIZE_EQGAME_OFFSET(EqSoundManager__PlayScriptMp3);
	INITIALIZE_EQGAME_OFFSET(EqSoundManager__SoundAssistPlay);
	INITIALIZE_EQGAME_OFFSET(EqSoundManager__WaveInstancePlay);
	INITIALIZE_EQGAME_OFFSET(CCombatSkillsSelectWnd__ShouldDisplayThisSkill);
	INITIALIZE_EQGAME_OFFSET(CTextureAnimation__SetCurCell);
	INITIALIZE_EQGAME_OFFSET(CSidlManager__FindAnimation1);
	//INITIALIZE_EQGAME_OFFSET(ActorClient__GetPosition);
	//INITIALIZE_EQGAME_OFFSET(ActorClient__GetPosition1);
	INITIALIZE_EQGAME_OFFSET(msg_spell_worn_off);
	INITIALIZE_EQGAME_OFFSET(msg_new_text);
	INITIALIZE_EQGAME_OFFSET(__msgTokenTextParam);
	INITIALIZE_EQGAME_OFFSET(msgTokenText);
	INITIALIZE_EQGAME_OFFSET(SpellManager__SpellManager);
	INITIALIZE_EQGAME_OFFSET(Spellmanager__LoadTextSpells);
	INITIALIZE_EQGAME_OFFSET(SpellManager__GetSpellByGroupAndRank);
	INITIALIZE_EQGAME_OFFSET(CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility);
	INITIALIZE_EQGAME_OFFSET(ItemGlobalIndex__ItemGlobalIndex);
	INITIALIZE_EQGAME_OFFSET(ItemGlobalIndex__IsEquippedLocation);
	INITIALIZE_EQGAME_OFFSET(ItemGlobalIndex__IsValidIndex);
	INITIALIZE_EQGAME_OFFSET(ItemBaseContainer__ItemBaseContainer);
	INITIALIZE_EQGAME_OFFSET(ItemBaseContainer__CreateItemGlobalIndex);
	INITIALIZE_EQGAME_OFFSET(ItemBase__IsLore);
#if !defined(ROF2EMU) && !defined(UFEMU)
	INITIALIZE_EQGAME_OFFSET(ItemBase__IsLoreEquipped);
#endif
	INITIALIZE_EQGAME_OFFSET(CLargeDialogWnd__Open);
	INITIALIZE_EQGAME_OFFSET(CWndDisplayManager__FindWindowA);
	INITIALIZE_EQGAME_OFFSET(CItemDisplayManager__CreateWindowInstance);
	INITIALIZE_EQGAME_OFFSET(CCursorAttachment__AttachToCursor);
	INITIALIZE_EQGAME_OFFSET(CCursorAttachment__AttachToCursor1);
	INITIALIZE_EQGAME_OFFSET(CCursorAttachment__Deactivate);
	INITIALIZE_EQGAME_OFFSET(CSidlManagerBase__FindButtonDrawTemplate);
	INITIALIZE_EQGAME_OFFSET(CSidlManagerBase__FindButtonDrawTemplate1);
	INITIALIZE_EQGAME_OFFSET(CEQSuiteTextureLoader__GetDefaultUIPath);
	INITIALIZE_EQGAME_OFFSET(CEQSuiteTextureLoader__GetTexture);
	INITIALIZE_EQGAME_OFFSET(CContainerMgr__OpenExperimentContainer);
#if !defined(ROF2EMU) && !defined(UFEMU)
	INITIALIZE_EQGAME_OFFSET(CDistillerInfo__GetIDFromRecordNum);
#endif
	INITIALIZE_EQGAME_OFFSET(CColorPickerWnd__Open);
	INITIALIZE_EQGAME_OFFSET(CGroupWnd__WndNotification);
	INITIALIZE_EQGAME_OFFSET(CGroupWnd__UpdateDisplay);
	
#ifdef __IsResEffectSpell_x
FUNCTION_AT_ADDRESS(bool IsResEffectSpell(int) ,__IsResEffectSpell);
#endif
#ifdef __ExecuteCmd_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(BOOL __cdecl EQExecuteCmd(DWORD arg1, BOOL arg2, PVOID arg3, BOOL arg4), __ExecuteCmd);
#else
FUNCTION_AT_ADDRESS(BOOL __cdecl EQExecuteCmd(DWORD arg1, BOOL arg2, PVOID arg3), __ExecuteCmd);
#endif
#endif
	BOOL ExecuteCmd(DWORD arg1, BOOL arg2, PVOID arg3)
	{
		#if !defined(ROF2EMU) && !defined(UFEMU)
		return EQExecuteCmd(arg1,arg2,arg3,0);
		#else
		return EQExecuteCmd(arg1,arg2,arg3);
		#endif
	}
	
};
