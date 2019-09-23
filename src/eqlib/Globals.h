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

#include "Common.h"
#include "eqgame.h"

#if !defined(DIRECTINPUT_VERSION)
#define DIRECTINPUT_VERSION    0x800
#endif

#include <dxsdk90\include\dinput.h>

namespace eqlib {

// the base address of eqgame.exe
EQLIB_VAR DWORD EQGameBaseAddress;

//============================================================================
// Data
//============================================================================

EQLIB_VAR const char* szCombineTypes[];
EQLIB_VAR size_t MAX_COMBINES;
EQLIB_VAR const char* szItemTypes[];
EQLIB_VAR size_t MAX_ITEMTYPES;
EQLIB_VAR const char* szSPATypes[];
EQLIB_VAR size_t MAX_SPELLEFFECTS;
EQLIB_VAR const char* szFactionNames[];
EQLIB_VAR size_t MAX_FACTIONNAMES;

struct ACTORDEFENTRY
{
	uint32_t Def;
	int      ZoneID;
	char     Name[256];
};
EQLIB_VAR ACTORDEFENTRY ActorDefList[];

struct DIKEYID
{
	char szName[32];
	WORD Id;
};
EQLIB_VAR DIKEYID gDiKeyID[];



//============================================================================
// Offsets
//============================================================================

EQLIB_VAR DWORD __ActualVersionDate;
EQLIB_VAR DWORD __ActualVersionTime;
EQLIB_VAR DWORD __ActualVersionBuild;

EQLIB_VAR DWORD __AC1;
EQLIB_VAR DWORD __AC2;
EQLIB_VAR DWORD __AC3;
EQLIB_VAR DWORD __AC4;
EQLIB_VAR DWORD __AC5;
EQLIB_VAR DWORD __AC6;
EQLIB_VAR DWORD __AC7;
EQLIB_VAR DWORD __Attack;
EQLIB_VAR DWORD __Autofire;
EQLIB_VAR DWORD __AutoSkillArray;
EQLIB_VAR DWORD __BindList;
EQLIB_VAR DWORD __Clicks;
EQLIB_VAR DWORD __CommandList;
EQLIB_VAR DWORD __CurrentMapLabel;
EQLIB_VAR DWORD __CurrentSocial;
EQLIB_VAR DWORD __do_loot;
EQLIB_VAR DWORD __DoAbilityList;
EQLIB_VAR DWORD __DrawHandler;
EQLIB_VAR DWORD __EncryptPad0;
EQLIB_VAR DWORD __EncryptPad1;
EQLIB_VAR DWORD __EncryptPad2;
EQLIB_VAR DWORD __EncryptPad3;
EQLIB_VAR DWORD __EncryptPad4;
EQLIB_VAR DWORD __EncryptPad5;
EQLIB_VAR DWORD __EP1_Data;
EQLIB_VAR DWORD __gpbCommandEvent;
EQLIB_VAR DWORD __GroupAggro;
EQLIB_VAR DWORD __Guilds;
EQLIB_VAR DWORD __gWorld;
EQLIB_VAR DWORD __heqmain;
EQLIB_VAR DWORD __HotkeyPage;
EQLIB_VAR DWORD __HWnd;
EQLIB_VAR DWORD __InChatMode;
EQLIB_VAR DWORD __Inviter;
EQLIB_VAR DWORD __LastTell;
EQLIB_VAR DWORD __LMouseHeldTime;
EQLIB_VAR DWORD __LoginName;
EQLIB_VAR DWORD __MemChecker0;
EQLIB_VAR DWORD __MemChecker1;
EQLIB_VAR DWORD __MemChecker2;
EQLIB_VAR DWORD __MemChecker3;
EQLIB_VAR DWORD __MemChecker4;
EQLIB_VAR DWORD __Mouse;
EQLIB_VAR DWORD __MouseEventTime;
EQLIB_VAR DWORD __MouseLook;
EQLIB_VAR DWORD __NetStatusToggle;
EQLIB_VAR DWORD __PCNames;
EQLIB_VAR DWORD __RangeAttackReady;
EQLIB_VAR DWORD __RMouseHeldTime;
EQLIB_VAR DWORD __RunWalkState;
EQLIB_VAR DWORD __ScreenMode;
EQLIB_VAR DWORD __ScreenX;
EQLIB_VAR DWORD __ScreenXMax;
EQLIB_VAR DWORD __ScreenY;
EQLIB_VAR DWORD __ScreenYMax;
EQLIB_VAR DWORD __ServerHost;
EQLIB_VAR DWORD __ServerName;
EQLIB_VAR DWORD __ShiftKeyDown;
EQLIB_VAR DWORD __ShowNames;
EQLIB_VAR DWORD __Socials;
EQLIB_VAR DWORD __SubscriptionType;
EQLIB_VAR DWORD __TargetAggroHolder;
EQLIB_VAR DWORD __UseTellWindows;
EQLIB_VAR DWORD __ZoneType;
EQLIB_VAR DWORD DI8__Keyboard;
EQLIB_VAR DWORD DI8__Main;
EQLIB_VAR DWORD DI8__Mouse_Check;
EQLIB_VAR DWORD DI8__Mouse_Copy;
EQLIB_VAR DWORD DI8__Mouse;
EQLIB_VAR DWORD g_eqCommandStates;
EQLIB_VAR DWORD LoginController__GiveTime;
EQLIB_VAR DWORD __eq_delete;
EQLIB_VAR DWORD __eq_new;

EQLIB_VAR DWORD EQObject_Top;
EQLIB_VAR DWORD instCRaid;
EQLIB_VAR DWORD instDynamicZone;
EQLIB_VAR DWORD instEQMisc;
EQLIB_VAR DWORD instEQZoneInfo;
EQLIB_VAR DWORD instExpeditionLeader;
EQLIB_VAR DWORD instExpeditionName;
EQLIB_VAR DWORD instTributeActive;
EQLIB_VAR DWORD pinstActiveBanker;
EQLIB_VAR DWORD pinstActiveCorpse;
EQLIB_VAR DWORD pinstActiveGMaster;
EQLIB_VAR DWORD pinstActiveMerchant;
EQLIB_VAR DWORD pinstAltAdvManager;
EQLIB_VAR DWORD pinstBandageTarget;
EQLIB_VAR DWORD pinstCAAWnd;
EQLIB_VAR DWORD pinstCAchievementsWnd;
EQLIB_VAR DWORD pinstCActionsWnd;
EQLIB_VAR DWORD pinstCAdvancedLootWnd;
EQLIB_VAR DWORD pinstCAdventureLeaderboardWnd;
EQLIB_VAR DWORD pinstCAdventureRequestWnd;
EQLIB_VAR DWORD pinstCAdventureStatsWnd;
EQLIB_VAR DWORD pinstCAlarmWnd;
EQLIB_VAR DWORD pinstCAltStorageWnd;
EQLIB_VAR DWORD pinstCamActor;
EQLIB_VAR DWORD pinstCAudioTriggersWindow;
EQLIB_VAR DWORD pinstCAuraWnd;
EQLIB_VAR DWORD pinstCAvaZoneWnd;
EQLIB_VAR DWORD pinstCBandolierWnd;
EQLIB_VAR DWORD pinstCBankWnd;
EQLIB_VAR DWORD pinstCBarterMerchantWnd;
EQLIB_VAR DWORD pinstCBarterSearchWnd;
EQLIB_VAR DWORD pinstCBarterWnd;
EQLIB_VAR DWORD pinstCBazaarSearchWnd;
EQLIB_VAR DWORD pinstCBazaarWnd;
EQLIB_VAR DWORD pinstCBlockedBuffWnd;
EQLIB_VAR DWORD pinstCBlockedPetBuffWnd;
EQLIB_VAR DWORD pinstCBodyTintWnd;
EQLIB_VAR DWORD pinstCBookWnd;
EQLIB_VAR DWORD pinstCBreathWnd;
EQLIB_VAR DWORD pinstCBuffWindowNORMAL;
EQLIB_VAR DWORD pinstCBuffWindowSHORT;
EQLIB_VAR DWORD pinstCBugReportWnd;
EQLIB_VAR DWORD pinstCCastingWnd;
EQLIB_VAR DWORD pinstCCastSpellWnd;
EQLIB_VAR DWORD pinstCCharacterListWnd;
EQLIB_VAR DWORD pinstCChatWindowManager;
EQLIB_VAR DWORD pinstCColorPickerWnd;
EQLIB_VAR DWORD pinstCCombatAbilityWnd;
EQLIB_VAR DWORD pinstCCombatSkillsSelectWnd;
EQLIB_VAR DWORD pinstCCompassWnd;
EQLIB_VAR DWORD pinstCConfirmationDialog;
EQLIB_VAR DWORD pinstCConfirmationDialog;
EQLIB_VAR DWORD pinstCContainerMgr;
EQLIB_VAR DWORD pinstCContextMenuManager;
EQLIB_VAR DWORD pinstCCursorAttachment;
EQLIB_VAR DWORD pinstCDBStr;
EQLIB_VAR DWORD pinstCDisplay;
EQLIB_VAR DWORD pinstCDynamicZoneWnd;
EQLIB_VAR DWORD pinstCEditLabelWnd;
EQLIB_VAR DWORD pinstCEQMainWnd;
EQLIB_VAR DWORD pinstCEverQuest;
EQLIB_VAR DWORD pinstCExtendedTargetWnd;
EQLIB_VAR DWORD pinstCFacePick;
EQLIB_VAR DWORD pinstCFactionWnd;
EQLIB_VAR DWORD pinstCFellowshipWnd;
EQLIB_VAR DWORD pinstCFileSelectionWnd;
EQLIB_VAR DWORD pinstCFindItemWnd;
EQLIB_VAR DWORD pinstCFindLocationWnd;
EQLIB_VAR DWORD pinstCFriendsWnd;
EQLIB_VAR DWORD pinstCGemsGameWnd;
EQLIB_VAR DWORD pinstCGiveWnd;
EQLIB_VAR DWORD pinstCGroupSearchFiltersWnd;
EQLIB_VAR DWORD pinstCGroupSearchWnd;
EQLIB_VAR DWORD pinstCGroupWnd;
EQLIB_VAR DWORD pinstCGuildBankWnd;
EQLIB_VAR DWORD pinstCGuildMgmtWnd;
EQLIB_VAR DWORD pinstCharacterCreation;
EQLIB_VAR DWORD pinstCharData;
EQLIB_VAR DWORD pinstCharSpawn;
EQLIB_VAR DWORD pinstCHotButtonWnd;
EQLIB_VAR DWORD pinstCHotButtonWnd1;
EQLIB_VAR DWORD pinstCHotButtonWnd2;
EQLIB_VAR DWORD pinstCHotButtonWnd3;
EQLIB_VAR DWORD pinstCHotButtonWnd4;
EQLIB_VAR DWORD pinstCInspectWnd;
EQLIB_VAR DWORD pinstCInventoryWnd;
EQLIB_VAR DWORD pinstCInvSlotMgr;
EQLIB_VAR DWORD pinstCItemDisplayManager;
EQLIB_VAR DWORD pinstCItemExpTransferWnd;
EQLIB_VAR DWORD pinstCJournalCatWnd;
EQLIB_VAR DWORD pinstCJournalTextWnd;
EQLIB_VAR DWORD pinstCLargeDialogWnd;
EQLIB_VAR DWORD pinstCLFGuildWnd;
EQLIB_VAR DWORD pinstCLoadskinWnd;
EQLIB_VAR DWORD pinstCLootWnd;
EQLIB_VAR DWORD pinstCMailAddressBookWnd;
EQLIB_VAR DWORD pinstCMailCompositionWnd;
EQLIB_VAR DWORD pinstCMailWnd;
EQLIB_VAR DWORD pinstCMapToolbarWnd;
EQLIB_VAR DWORD pinstCMapViewWnd;
EQLIB_VAR DWORD pinstCMerchantWnd;
EQLIB_VAR DWORD pinstCMIZoneSelectWnd;
EQLIB_VAR DWORD pinstCMusicPlayerWnd;
EQLIB_VAR DWORD pinstCNoteWnd;
EQLIB_VAR DWORD pinstControlledMissile;
EQLIB_VAR DWORD pinstControlledPlayer;
EQLIB_VAR DWORD pinstCOptionsWnd;
EQLIB_VAR DWORD pinstCPetInfoWnd;
EQLIB_VAR DWORD pinstCPetitionQWnd;
EQLIB_VAR DWORD pinstCPlayerNotesWnd;
EQLIB_VAR DWORD pinstCPlayerWnd;
EQLIB_VAR DWORD pinstCPointMerchantWnd;
EQLIB_VAR DWORD pinstCPopupWndManager;
EQLIB_VAR DWORD pinstCPotionBeltWnd;
EQLIB_VAR DWORD pinstCProgressionSelectionWnd;
EQLIB_VAR DWORD pinstCPvPStatsWnd;
EQLIB_VAR DWORD pinstCQuantityWnd;
EQLIB_VAR DWORD pinstCRaidOptionsWnd;
EQLIB_VAR DWORD pinstCRaidWnd;
EQLIB_VAR DWORD pinstCRealEstateItemsWnd;
EQLIB_VAR DWORD pinstCResolutionHandler;
EQLIB_VAR DWORD pinstCRespawnWnd;
EQLIB_VAR DWORD pinstCSelectorWnd;
EQLIB_VAR DWORD pinstCServerListWnd;
EQLIB_VAR DWORD pinstCSidlManager;
EQLIB_VAR DWORD pinstCSkillsSelectWnd;
EQLIB_VAR DWORD pinstCSkillsWnd;
EQLIB_VAR DWORD pinstCSocialEditWnd;
EQLIB_VAR DWORD pinstCSpellBookWnd;
EQLIB_VAR DWORD pinstCStoryWnd;
EQLIB_VAR DWORD pinstCTargetOfTargetWnd;
EQLIB_VAR DWORD pinstCTargetWnd;
EQLIB_VAR DWORD pinstCTaskManager;
EQLIB_VAR DWORD pinstCTaskTemplateSelectWnd;
EQLIB_VAR DWORD pinstCTaskWnd;
EQLIB_VAR DWORD pinstCTextEntryWnd;
EQLIB_VAR DWORD pinstCTimeLeftWnd;
EQLIB_VAR DWORD pinstCTipWndCONTEXT;
EQLIB_VAR DWORD pinstCTipWndOFDAY;
EQLIB_VAR DWORD pinstCTitleWnd;
EQLIB_VAR DWORD pinstCTrackingWnd;
EQLIB_VAR DWORD pinstCTradeWnd;
EQLIB_VAR DWORD pinstCTrainWnd;
EQLIB_VAR DWORD pinstCVideoModesWnd;
EQLIB_VAR DWORD pinstCVoiceMacroWnd;
EQLIB_VAR DWORD pinstCWebManager;
EQLIB_VAR DWORD pinstCXWndManager;
EQLIB_VAR DWORD pinstCZoneGuideWnd;
EQLIB_VAR DWORD pinstDZMember;
EQLIB_VAR DWORD pinstDZTimerInfo;
EQLIB_VAR DWORD pinstEqLogin;
EQLIB_VAR DWORD pinstEQSoundManager;
EQLIB_VAR DWORD pinstEQSpellStrings;
EQLIB_VAR DWORD pinstEQSuiteTextureLoader;
EQLIB_VAR DWORD pinstEverQuestInfo;
EQLIB_VAR DWORD pinstGroup;
EQLIB_VAR DWORD pinstImeManager;
EQLIB_VAR DWORD pinstItemIconCache;
EQLIB_VAR DWORD pinstLocalPlayer;
EQLIB_VAR DWORD pinstMercenaryData;
EQLIB_VAR DWORD pinstMercenaryStats;
EQLIB_VAR DWORD pinstModelPlayer;
EQLIB_VAR DWORD pinstPCData;
EQLIB_VAR DWORD pinstPlayerPath;
EQLIB_VAR DWORD pinstRewardSelectionWnd;
EQLIB_VAR DWORD pinstSkillMgr;
EQLIB_VAR DWORD pinstSpawnManager;
EQLIB_VAR DWORD pinstSpellManager;
EQLIB_VAR DWORD pinstSpellSets;
EQLIB_VAR DWORD pinstStringTable;
EQLIB_VAR DWORD pinstSwitchManager;
EQLIB_VAR DWORD pinstTarget;
EQLIB_VAR DWORD pinstTargetIndicator;
EQLIB_VAR DWORD pinstTargetObject;
EQLIB_VAR DWORD pinstTargetSwitch;
EQLIB_VAR DWORD pinstTaskMember;
EQLIB_VAR DWORD pinstTrackTarget;
EQLIB_VAR DWORD pinstTradeTarget;
EQLIB_VAR DWORD pinstViewActor;
EQLIB_VAR DWORD pinstWorldData;

EQLIB_VAR DWORD __AppCrashWrapper;
EQLIB_VAR DWORD __CastRay;
EQLIB_VAR DWORD __CastRay2;
EQLIB_VAR DWORD __ConvertItemTags;
EQLIB_VAR DWORD __CleanItemTags;
EQLIB_VAR DWORD __CrashHandler;
EQLIB_VAR DWORD __DoesFileExist;
EQLIB_VAR DWORD __EQGetTime;
EQLIB_VAR DWORD __ExecuteCmd;
EQLIB_VAR DWORD __FixHeading;
EQLIB_VAR DWORD __get_bearing;
EQLIB_VAR DWORD __get_melee_range;
EQLIB_VAR DWORD __GetAnimationCache;
EQLIB_VAR DWORD __GetGaugeValueFromEQ;
EQLIB_VAR DWORD __GetLabelFromEQ;
EQLIB_VAR DWORD __GetXTargetType;
EQLIB_VAR DWORD __HandleMouseWheel;
EQLIB_VAR DWORD __HeadingDiff;
EQLIB_VAR DWORD __HelpPath;
EQLIB_VAR DWORD __LoadFrontEnd;
EQLIB_VAR DWORD __NewUIINI;
EQLIB_VAR DWORD __pCrashHandler;
EQLIB_VAR DWORD __ProcessGameEvents;
EQLIB_VAR DWORD __SaveColors;
EQLIB_VAR DWORD __STMLToText;
EQLIB_VAR DWORD __ToggleKeyRingItem;
EQLIB_VAR DWORD CMemoryMappedFile__SetFile;
EQLIB_VAR DWORD CrashDetected;
EQLIB_VAR DWORD DrawNetStatus;
EQLIB_VAR DWORD Expansion_HoT;
EQLIB_VAR DWORD Teleport_Table;
EQLIB_VAR DWORD Teleport_Table_Size;
EQLIB_VAR DWORD Util__FastTime;
EQLIB_VAR DWORD wwsCrashReportCheckForUploader;
EQLIB_VAR DWORD wwsCrashReportPlatformLaunchUploader;

EQLIB_VAR DWORD CAdvancedLootWnd__CAdvancedLootWnd;
EQLIB_VAR DWORD CAdvancedLootWnd__DoAdvLootAction;
EQLIB_VAR DWORD CAdvancedLootWnd__DoSharedAdvLootAction;
EQLIB_VAR DWORD CAdvancedLootWnd__AddPlayerToList;
EQLIB_VAR DWORD CAdvancedLootWnd__UpdateMasterLooter;

EQLIB_VAR DWORD AltAdvManager__GetCalculatedTimer;
EQLIB_VAR DWORD AltAdvManager__IsAbilityReady;
EQLIB_VAR DWORD AltAdvManager__GetAAById;
EQLIB_VAR DWORD AltAdvManager__CanTrainAbility;
EQLIB_VAR DWORD AltAdvManager__CanSeeAbility;

EQLIB_VAR DWORD CAltAbilityData__GetMercCurrentRank;
EQLIB_VAR DWORD CAltAbilityData__GetMercMaxRank;
EQLIB_VAR DWORD CAltAbilityData__GetMaxRank;

EQLIB_VAR DWORD CharacterZoneClient__CharacterZoneClient;
EQLIB_VAR DWORD CharacterZoneClient__HasSkill;
EQLIB_VAR DWORD CharacterZoneClient__MakeMeVisible;
EQLIB_VAR DWORD CharacterZoneClient__ApplyDamage;
EQLIB_VAR DWORD CharacterZoneClient__IsStackBlocked;
EQLIB_VAR DWORD CharacterZoneClient__CanUseMemorizedSpellSlot;
EQLIB_VAR DWORD CharacterZoneClient__GetItemCountWorn;
EQLIB_VAR DWORD CharacterZoneClient__GetItemCountInInventory;
EQLIB_VAR DWORD CharacterZoneClient__GetCursorItemCount;
EQLIB_VAR DWORD CharacterZoneClient__FindAffectSlot;
EQLIB_VAR DWORD CharacterZoneClient__BardCastBard;
EQLIB_VAR DWORD CharacterZoneClient__GetMaxEffects;
EQLIB_VAR DWORD CharacterZoneClient__GetEffect;
EQLIB_VAR DWORD CharacterZoneClient__GetOpenEffectSlot;
EQLIB_VAR DWORD CharacterZoneClient__GetFirstEffectSlot;
EQLIB_VAR DWORD CharacterZoneClient__GetLastEffectSlot;

EQLIB_VAR DWORD CBankWnd__GetNumBankSlots;
EQLIB_VAR DWORD CBankWnd__WndNotification;
EQLIB_VAR DWORD CFindItemWnd__WndNotification;
EQLIB_VAR DWORD CFindItemWnd__Update;
EQLIB_VAR DWORD CFindItemWnd__PickupSelectedItem;

EQLIB_VAR DWORD CBazaarSearchWnd__HandleBazaarMsg;

EQLIB_VAR DWORD CButtonWnd__CButtonWnd;
EQLIB_VAR DWORD CButtonWnd__dCButtonWnd;
EQLIB_VAR DWORD CButtonWnd__vftable;

EQLIB_VAR DWORD CCastSpellWnd__ForgetMemorizedSpell;
EQLIB_VAR DWORD CCastSpellWnd__IsBardSongPlaying;
EQLIB_VAR DWORD CCastSpellWnd__RefreshSpellGemButtons;

EQLIB_VAR DWORD CChatWindowManager__GetRGBAFromIndex;
EQLIB_VAR DWORD CChatWindowManager__InitContextMenu;
EQLIB_VAR DWORD CChatWindowManager__FreeChatWindow;
EQLIB_VAR DWORD CChatWindowManager__GetLockedActiveChatWindow;
EQLIB_VAR DWORD CChatWindowManager__SetLockedActiveChatWindow;
EQLIB_VAR DWORD CChatWindowManager__CreateChatWindow;

EQLIB_VAR DWORD CContextMenu__CContextMenu;
EQLIB_VAR DWORD CContextMenu__dCContextMenu;
EQLIB_VAR DWORD CContextMenu__AddMenuItem;
EQLIB_VAR DWORD CContextMenuManager__AddMenu;
EQLIB_VAR DWORD CContextMenuManager__RemoveMenu;
EQLIB_VAR DWORD CContextMenuManager__PopupMenu;
EQLIB_VAR DWORD CContextMenu__RemoveAllMenuItems;
EQLIB_VAR DWORD CContextMenu__CheckMenuItem;
EQLIB_VAR DWORD CContextMenu__RemoveMenuItem;
EQLIB_VAR DWORD CContextMenu__SetMenuItem;
EQLIB_VAR DWORD CContextMenu__AddSeparator;

EQLIB_VAR DWORD CContextMenuManager__Flush;
EQLIB_VAR DWORD CContextMenuManager__GetMenu;
EQLIB_VAR DWORD CContextMenuManager__CreateDefaultMenu;

EQLIB_VAR DWORD CChatService__GetNumberOfFriends;
EQLIB_VAR DWORD CChatService__GetFriendName;

EQLIB_VAR DWORD CChatWindow__CChatWindow;
EQLIB_VAR DWORD CChatWindow__Clear;
EQLIB_VAR DWORD CChatWindow__WndNotification;
EQLIB_VAR DWORD CChatWindow__AddHistory;

EQLIB_VAR DWORD CComboWnd__DeleteAll;
EQLIB_VAR DWORD CComboWnd__Draw;
EQLIB_VAR DWORD CComboWnd__GetCurChoice;
EQLIB_VAR DWORD CComboWnd__GetListRect;
EQLIB_VAR DWORD CComboWnd__GetTextRect;
EQLIB_VAR DWORD CComboWnd__InsertChoice;
EQLIB_VAR DWORD CComboWnd__SetColors;
EQLIB_VAR DWORD CComboWnd__SetChoice;
EQLIB_VAR DWORD CComboWnd__GetItemCount;
EQLIB_VAR DWORD CComboWnd__GetCurChoiceText;
EQLIB_VAR DWORD CComboWnd__GetChoiceText;
EQLIB_VAR DWORD CComboWnd__InsertChoiceAtIndex;

EQLIB_VAR DWORD CContainerWnd__HandleCombine;
EQLIB_VAR DWORD CContainerWnd__vftable;
EQLIB_VAR DWORD CContainerWnd__SetContainer;

EQLIB_VAR DWORD CDisplay__ZoneMainUI;
EQLIB_VAR DWORD CDisplay__PreZoneMainUI;
EQLIB_VAR DWORD CDisplay__CleanGameUI;
EQLIB_VAR DWORD CDisplay__GetClickedActor;
EQLIB_VAR DWORD CDisplay__GetUserDefinedColor;
EQLIB_VAR DWORD CDisplay__GetWorldFilePath;
EQLIB_VAR DWORD CDisplay__is3dON;
EQLIB_VAR DWORD CDisplay__ReloadUI;
EQLIB_VAR DWORD CDisplay__WriteTextHD2;
EQLIB_VAR DWORD CDisplay__TrueDistance;
EQLIB_VAR DWORD CDisplay__SetViewActor;
EQLIB_VAR DWORD CDisplay__GetFloorHeight;
EQLIB_VAR DWORD CDisplay__SetRenderWindow;
EQLIB_VAR DWORD CDisplay__ToggleScreenshotMode;

EQLIB_VAR DWORD CEditBaseWnd__SetSel;

EQLIB_VAR DWORD CEditWnd__DrawCaret;
EQLIB_VAR DWORD CEditWnd__GetCharIndexPt;
EQLIB_VAR DWORD CEditWnd__GetDisplayString;
EQLIB_VAR DWORD CEditWnd__GetHorzOffset;
EQLIB_VAR DWORD CEditWnd__GetLineForPrintableChar;
EQLIB_VAR DWORD CEditWnd__GetSelStartPt;
EQLIB_VAR DWORD CEditWnd__GetSTMLSafeText;
EQLIB_VAR DWORD CEditWnd__PointFromPrintableChar;
EQLIB_VAR DWORD CEditWnd__SelectableCharFromPoint;
EQLIB_VAR DWORD CEditWnd__SetEditable;
EQLIB_VAR DWORD CEditWnd__SetWindowTextA;

EQLIB_VAR DWORD CEverQuest__DoPercentConvert;
EQLIB_VAR DWORD CEverQuest__ClickedPlayer;
EQLIB_VAR DWORD CEverQuest__DoTellWindow;
EQLIB_VAR DWORD CEverQuest__OutputTextToLog;
EQLIB_VAR DWORD CEverQuest__DropHeldItemOnGround;
EQLIB_VAR DWORD CEverQuest__dsp_chat;
EQLIB_VAR DWORD CEverQuest__trimName;
EQLIB_VAR DWORD CEverQuest__Emote;
EQLIB_VAR DWORD CEverQuest__EnterZone;
EQLIB_VAR DWORD CEverQuest__GetBodyTypeDesc;
EQLIB_VAR DWORD CEverQuest__GetClassDesc;
EQLIB_VAR DWORD CEverQuest__GetClassThreeLetterCode;
EQLIB_VAR DWORD CEverQuest__GetDeityDesc;
EQLIB_VAR DWORD CEverQuest__GetLangDesc;
EQLIB_VAR DWORD CEverQuest__GetRaceDesc;
EQLIB_VAR DWORD CEverQuest__InterpretCmd;
EQLIB_VAR DWORD CEverQuest__LeftClickedOnPlayer;
EQLIB_VAR DWORD CEverQuest__LMouseUp;
EQLIB_VAR DWORD CEverQuest__RightClickedOnPlayer;
EQLIB_VAR DWORD CEverQuest__RMouseUp;
EQLIB_VAR DWORD CEverQuest__SetGameState;
EQLIB_VAR DWORD CEverQuest__UPCNotificationFlush;
EQLIB_VAR DWORD CEverQuest__IssuePetCommand;
EQLIB_VAR DWORD CEverQuest__ReportSuccessfulHit;
EQLIB_VAR DWORD CEverQuest__CreateTargetIndicator;
EQLIB_VAR DWORD CEverQuest__DeleteTargetIndicator;

EQLIB_VAR DWORD CFindItemWnd__CFindItemWnd;
EQLIB_VAR DWORD IString__Append;
EQLIB_VAR DWORD CDisplay__cameraType;
EQLIB_VAR DWORD EverQuest__Cameras;
EQLIB_VAR DWORD pinstLootFiltersManager;
EQLIB_VAR DWORD LootFiltersManager__AddItemLootFilter;
EQLIB_VAR DWORD LootFiltersManager__GetItemFilterData;
EQLIB_VAR DWORD LootFiltersManager__RemoveItemLootFilter;
EQLIB_VAR DWORD LootFiltersManager__SetItemLootFilter;
EQLIB_VAR DWORD COptionsWnd__FillChatFilterList;
EQLIB_VAR DWORD CResolutionHandler__UpdateResolution;
EQLIB_VAR DWORD CResolutionHandler__GetWindowedStyle;
EQLIB_VAR DWORD CContainerMgr__OpenExperimentContainer;
EQLIB_VAR DWORD CColorPickerWnd__Open;
EQLIB_VAR DWORD CDistillerInfo__GetIDFromRecordNum;
EQLIB_VAR DWORD CDistillerInfo__Instance;
EQLIB_VAR DWORD CGroupWnd__WndNotification;
EQLIB_VAR DWORD CGroupWnd__UpdateDisplay;

EQLIB_VAR DWORD CGaugeWnd__CalcFillRect;
EQLIB_VAR DWORD CGaugeWnd__CalcLinesFillRect;
EQLIB_VAR DWORD CGaugeWnd__Draw;

EQLIB_VAR DWORD CGuild__FindMemberByName;
EQLIB_VAR DWORD CGuild__GetGuildName;
EQLIB_VAR DWORD CGuild__GetGuildIndex;

EQLIB_VAR DWORD CharacterBase__GetMemorizedSpell;
EQLIB_VAR DWORD CharacterBase__CreateItemGlobalIndex;
EQLIB_VAR DWORD CharacterBase__CreateItemIndex;
EQLIB_VAR DWORD CharacterBase__GetItemPossession;
EQLIB_VAR DWORD CharacterBase__GetItemByGlobalIndex;
EQLIB_VAR DWORD CharacterBase__GetItemByGlobalIndex1;
EQLIB_VAR DWORD CharacterBase__GetEffectId;

EQLIB_VAR DWORD CHotButtonWnd__DoHotButton;
EQLIB_VAR DWORD CHotButton__SetButtonSize;

EQLIB_VAR DWORD CInvSlotMgr__FindInvSlot;
EQLIB_VAR DWORD CInvSlotMgr__MoveItem;
EQLIB_VAR DWORD CInvSlotMgr__SelectSlot;

EQLIB_VAR DWORD CInvSlot__HandleRButtonUp;
EQLIB_VAR DWORD CInvSlot__SliderComplete;
EQLIB_VAR DWORD CInvSlot__GetItemBase;
EQLIB_VAR DWORD CInvSlot__UpdateItem;

EQLIB_VAR DWORD CInvSlotWnd__DrawTooltip;
EQLIB_VAR DWORD CInvSlotWnd__CInvSlotWnd;
EQLIB_VAR DWORD CInvSlotWnd__HandleLButtonUp;

EQLIB_VAR DWORD CItemDisplayWnd__SetSpell;
EQLIB_VAR DWORD CItemDisplayWnd__UpdateStrings;
EQLIB_VAR DWORD CItemDisplayWnd__InsertAugmentRequest;
EQLIB_VAR DWORD CItemDisplayWnd__RemoveAugmentRequest;
EQLIB_VAR DWORD CItemDisplayWnd__SetItem;
EQLIB_VAR DWORD CItemDisplayWnd__AboutToShow;
EQLIB_VAR DWORD CItemDisplayWnd__WndNotification;
EQLIB_VAR DWORD CItemDisplayWnd__RequestConvertItem;
EQLIB_VAR DWORD CItemDisplayWnd__CItemDisplayWnd;
EQLIB_VAR DWORD CItemDisplayWnd__dCItemDisplayWnd;

EQLIB_VAR DWORD CLabel__Draw;

EQLIB_VAR DWORD CListWnd__CListWnd;
EQLIB_VAR DWORD CListWnd__dCListWnd;
EQLIB_VAR DWORD CListWnd__vftable;
EQLIB_VAR DWORD CListWnd__AddColumn;
EQLIB_VAR DWORD CListWnd__AddColumn1;
EQLIB_VAR DWORD CListWnd__AddLine;
EQLIB_VAR DWORD CListWnd__AddString;
EQLIB_VAR DWORD CListWnd__CalculateFirstVisibleLine;
EQLIB_VAR DWORD CListWnd__CalculateVSBRange;
EQLIB_VAR DWORD CListWnd__ClearSel;
EQLIB_VAR DWORD CListWnd__ClearAllSel;
EQLIB_VAR DWORD CListWnd__CloseAndUpdateEditWindow;
EQLIB_VAR DWORD CListWnd__Compare;
EQLIB_VAR DWORD CListWnd__Draw;
EQLIB_VAR DWORD CListWnd__DrawColumnSeparators;
EQLIB_VAR DWORD CListWnd__DrawHeader;
EQLIB_VAR DWORD CListWnd__DrawItem;
EQLIB_VAR DWORD CListWnd__DrawLine;
EQLIB_VAR DWORD CListWnd__DrawSeparator;
EQLIB_VAR DWORD CListWnd__EnableLine;
EQLIB_VAR DWORD CListWnd__EnsureVisible;
EQLIB_VAR DWORD CListWnd__ExtendSel;
EQLIB_VAR DWORD CListWnd__GetColumnMinWidth;
EQLIB_VAR DWORD CListWnd__GetColumnTooltip;
EQLIB_VAR DWORD CListWnd__GetColumnWidth;
EQLIB_VAR DWORD CListWnd__GetCurSel;
EQLIB_VAR DWORD CListWnd__GetItemAtPoint;
EQLIB_VAR DWORD CListWnd__GetItemAtPoint1;
EQLIB_VAR DWORD CListWnd__GetItemData;
EQLIB_VAR DWORD CListWnd__GetItemHeight;
EQLIB_VAR DWORD CListWnd__GetItemIcon;
EQLIB_VAR DWORD CListWnd__GetItemRect;
EQLIB_VAR DWORD CListWnd__GetItemText;
EQLIB_VAR DWORD CListWnd__GetSelList;
EQLIB_VAR DWORD CListWnd__GetSeparatorRect;
EQLIB_VAR DWORD CListWnd__InsertLine;
EQLIB_VAR DWORD CListWnd__RemoveLine;
EQLIB_VAR DWORD CListWnd__SetColors;
EQLIB_VAR DWORD CListWnd__SetColumnJustification;
EQLIB_VAR DWORD CListWnd__SetColumnWidth;
EQLIB_VAR DWORD CListWnd__SetCurSel;
EQLIB_VAR DWORD CListWnd__SetItemColor;
EQLIB_VAR DWORD CListWnd__SetItemData;
EQLIB_VAR DWORD CListWnd__SetItemText;
EQLIB_VAR DWORD CListWnd__ShiftColumnSeparator;
EQLIB_VAR DWORD CListWnd__Sort;
EQLIB_VAR DWORD CListWnd__ToggleSel;
EQLIB_VAR DWORD CListWnd__SetColumnsSizable;
EQLIB_VAR DWORD CListWnd__SetItemWnd;
EQLIB_VAR DWORD CListWnd__GetItemWnd;
EQLIB_VAR DWORD CListWnd__SetItemIcon;
EQLIB_VAR DWORD CListWnd__CalculateCustomWindowPositions;
EQLIB_VAR DWORD CListWnd__SetVScrollPos;

EQLIB_VAR DWORD CMapViewWnd__CMapViewWnd;
EQLIB_VAR DWORD CMapViewWnd__GetWorldCoordinates;
EQLIB_VAR DWORD CMapViewWnd__HandleLButtonDown;

EQLIB_VAR DWORD CMerchantWnd__DisplayBuyOrSellPrice;
EQLIB_VAR DWORD CMerchantWnd__PurchasePageHandler__RequestGetItem;
EQLIB_VAR DWORD CMerchantWnd__PurchasePageHandler__RequestPutItem;
EQLIB_VAR DWORD CMerchantWnd__SelectBuySellSlot;
EQLIB_VAR DWORD CMerchantWnd__PurchasePageHandler__UpdateList;

EQLIB_VAR DWORD CPacketScrambler__ntoh;
EQLIB_VAR DWORD CPacketScrambler__hton;

EQLIB_VAR DWORD CSidlManagerBase__FindScreenPieceTemplate;
EQLIB_VAR DWORD CSidlManagerBase__FindScreenPieceTemplate1;
EQLIB_VAR DWORD CSidlManagerBase__CreateLabel;
EQLIB_VAR DWORD CSidlManagerBase__CreateXWndFromTemplate;
EQLIB_VAR DWORD CSidlManagerBase__CreateXWndFromTemplate1;
EQLIB_VAR DWORD CSidlManagerBase__CreateXWnd;
EQLIB_VAR DWORD CSidlManagerBase__FindAnimation1;
EQLIB_VAR DWORD CSidlManagerBase__FindButtonDrawTemplate;
EQLIB_VAR DWORD CSidlManagerBase__FindButtonDrawTemplate1;
EQLIB_VAR DWORD CSidlManager__CreateHotButtonWnd;

EQLIB_VAR DWORD CSidlScreenWnd__CalculateHSBRange;
EQLIB_VAR DWORD CSidlScreenWnd__CalculateVSBRange;
EQLIB_VAR DWORD CSidlScreenWnd__ConvertToRes;
EQLIB_VAR DWORD CSidlScreenWnd__CreateChildrenFromSidl;
EQLIB_VAR DWORD CSidlScreenWnd__CSidlScreenWnd1;
EQLIB_VAR DWORD CSidlScreenWnd__CSidlScreenWnd2;
EQLIB_VAR DWORD CSidlScreenWnd__dCSidlScreenWnd;
EQLIB_VAR DWORD CSidlScreenWnd__DrawSidlPiece;
EQLIB_VAR DWORD CSidlScreenWnd__EnableIniStorage;
EQLIB_VAR DWORD CSidlScreenWnd__GetChildItem;
EQLIB_VAR DWORD CSidlScreenWnd__GetSidlPiece;
EQLIB_VAR DWORD CSidlScreenWnd__HandleLButtonUp;
EQLIB_VAR DWORD CSidlScreenWnd__Init1;
EQLIB_VAR DWORD CSidlScreenWnd__LoadIniListWnd;
EQLIB_VAR DWORD CSidlScreenWnd__LoadSidlScreen;
EQLIB_VAR DWORD CSidlScreenWnd__m_layoutCopy;
EQLIB_VAR DWORD CSidlScreenWnd__StoreIniVis;
EQLIB_VAR DWORD CSidlScreenWnd__vftable;

EQLIB_VAR DWORD CSkillMgr__IsAvailable;
EQLIB_VAR DWORD CSkillMgr__GetSkillCap;
EQLIB_VAR DWORD CSkillMgr__GetNameToken;
EQLIB_VAR DWORD CSkillMgr__IsActivatedSkill;
EQLIB_VAR DWORD CSkillMgr__IsCombatSkill;

EQLIB_VAR DWORD CSliderWnd__GetValue;
EQLIB_VAR DWORD CSliderWnd__SetValue;
EQLIB_VAR DWORD CSliderWnd__SetNumTicks;

EQLIB_VAR DWORD CSpellBookWnd__MemorizeSet;

EQLIB_VAR DWORD CStmlWnd__AppendSTML;
EQLIB_VAR DWORD CStmlWnd__CalculateHSBRange;
EQLIB_VAR DWORD CStmlWnd__CalculateVSBRange;
EQLIB_VAR DWORD CStmlWnd__CanBreakAtCharacter;
EQLIB_VAR DWORD CStmlWnd__FastForwardToEndOfTag;
EQLIB_VAR DWORD CStmlWnd__ForceParseNow;
EQLIB_VAR DWORD CStmlWnd__GetNextTagPiece;
EQLIB_VAR DWORD CStmlWnd__GetSTMLText;
EQLIB_VAR DWORD CStmlWnd__GetVisibleText;
EQLIB_VAR DWORD CStmlWnd__InitializeWindowVariables;
EQLIB_VAR DWORD CStmlWnd__MakeStmlColorTag;
EQLIB_VAR DWORD CStmlWnd__MakeWndNotificationTag;
EQLIB_VAR DWORD CStmlWnd__SetSTMLText;
EQLIB_VAR DWORD CStmlWnd__StripFirstSTMLLines;
EQLIB_VAR DWORD CStmlWnd__UpdateHistoryString;

EQLIB_VAR DWORD CTabWnd__Draw;
EQLIB_VAR DWORD CTabWnd__DrawCurrentPage;
EQLIB_VAR DWORD CTabWnd__DrawTab;
EQLIB_VAR DWORD CTabWnd__GetCurrentPage;
EQLIB_VAR DWORD CTabWnd__GetPageInnerRect;
EQLIB_VAR DWORD CTabWnd__GetTabInnerRect;
EQLIB_VAR DWORD CTabWnd__GetTabRect;
EQLIB_VAR DWORD CTabWnd__InsertPage;
EQLIB_VAR DWORD CTabWnd__SetPage;
EQLIB_VAR DWORD CTabWnd__SetPageRect;
EQLIB_VAR DWORD CTabWnd__UpdatePage;
EQLIB_VAR DWORD CTabWnd__GetPageFromTabIndex;
EQLIB_VAR DWORD CTabWnd__GetCurrentTabIndex;
EQLIB_VAR DWORD CPageWnd__GetTabText;

EQLIB_VAR DWORD CPageWnd__SetTabText;

EQLIB_VAR DWORD CTargetRing__Cast;
EQLIB_VAR DWORD CTargetWnd__RefreshTargetBuffs;
EQLIB_VAR DWORD CTargetWnd__HandleBuffRemoveRequest;

EQLIB_VAR DWORD CTextOverlay__DisplayText;

EQLIB_VAR DWORD CTextureFont__DrawWrappedText;
EQLIB_VAR DWORD CTextureFont__GetTextExtent;

EQLIB_VAR DWORD CWebManager__CreateHtmlWnd;
EQLIB_VAR DWORD CHtmlComponentWnd__ValidateUri;
EQLIB_VAR DWORD CHtmlWnd__SetClientCallbacks;
EQLIB_VAR DWORD CHtmlWnd__AddObserver;
EQLIB_VAR DWORD CHtmlWnd__RemoveObserver;
EQLIB_VAR DWORD Window__getProgress;
EQLIB_VAR DWORD Window__getStatus;
EQLIB_VAR DWORD Window__getURI;

EQLIB_VAR DWORD CXMLDataManager__GetXMLData;

EQLIB_VAR DWORD CXMLSOMDocumentBase__XMLRead;

EQLIB_VAR DWORD CXStr__CXStr;
EQLIB_VAR DWORD CXStr__CXStr1;
EQLIB_VAR DWORD CXStr__CXStr3;
EQLIB_VAR DWORD CXStr__dCXStr;
EQLIB_VAR DWORD CXStr__operator_equal;
EQLIB_VAR DWORD CXStr__operator_equal1;
EQLIB_VAR DWORD CXStr__operator_plus_equal1;
EQLIB_VAR DWORD CXStr__SetString;
EQLIB_VAR DWORD CXStr__operator_char_p;
EQLIB_VAR DWORD CXStr__GetChar;
EQLIB_VAR DWORD CXStr__Delete;
EQLIB_VAR DWORD CXStr__GetUnicode;
EQLIB_VAR DWORD CXStr__GetLength;
EQLIB_VAR DWORD CXStr__Mid;
EQLIB_VAR DWORD CXStr__Insert;
EQLIB_VAR DWORD CXStr__FindNext;
EQLIB_VAR DWORD CXStr__gFreeLists;
EQLIB_VAR DWORD CXStr__gCXStrAccess;

EQLIB_VAR DWORD CScreenPieceTemplate__IsType;
EQLIB_VAR DWORD CXWnd__BringToTop;
EQLIB_VAR DWORD CXWnd__CXWnd;
EQLIB_VAR DWORD CXWnd__dCXWnd;
EQLIB_VAR DWORD CXWnd__Center;
EQLIB_VAR DWORD CXWnd__ClrFocus;
EQLIB_VAR DWORD CXWnd__Destroy;
EQLIB_VAR DWORD CXWnd__DoAllDrawing;
EQLIB_VAR DWORD CXWnd__DrawChildren;
EQLIB_VAR DWORD CXWnd__DrawColoredRect;
EQLIB_VAR DWORD CXWnd__DrawTooltip;
EQLIB_VAR DWORD CXWnd__DrawTooltipAtPoint;
EQLIB_VAR DWORD CXWnd__GetBorderFrame;
EQLIB_VAR DWORD CXWnd__GetChildItem;
EQLIB_VAR DWORD CXWnd__GetChildWndAt;
EQLIB_VAR DWORD CXWnd__GetClientClipRect;
EQLIB_VAR DWORD CXWnd__GetScreenClipRect;
EQLIB_VAR DWORD CXWnd__GetScreenRect;
EQLIB_VAR DWORD CXWnd__GetTooltipRect;
EQLIB_VAR DWORD CXWnd__GetWindowTextA;
EQLIB_VAR DWORD CXWnd__IsActive;
EQLIB_VAR DWORD CXWnd__IsDescendantOf;
EQLIB_VAR DWORD CXWnd__IsReallyVisible;
EQLIB_VAR DWORD CXWnd__IsType;
EQLIB_VAR DWORD CXWnd__Minimize;
EQLIB_VAR DWORD CXWnd__Move;
EQLIB_VAR DWORD CXWnd__Move1;
EQLIB_VAR DWORD CXWnd__ProcessTransition;
EQLIB_VAR DWORD CXWnd__Refade;
EQLIB_VAR DWORD CXWnd__Resize;
EQLIB_VAR DWORD CXWnd__Right;
EQLIB_VAR DWORD CXWnd__SetFocus;
EQLIB_VAR DWORD CXWnd__SetFont;
EQLIB_VAR DWORD CXWnd__SetKeyTooltip;
EQLIB_VAR DWORD CXWnd__SetMouseOver;
EQLIB_VAR DWORD CXWnd__SetParent;
EQLIB_VAR DWORD CXWnd__StartFade;
EQLIB_VAR DWORD CXWnd__vftable;

EQLIB_VAR DWORD CXWndManager__DrawCursor;
EQLIB_VAR DWORD CXWndManager__DrawWindows;
EQLIB_VAR DWORD CXWndManager__GetKeyboardFlags;
EQLIB_VAR DWORD CXWndManager__HandleKeyboardMsg;
EQLIB_VAR DWORD CXWndManager__RemoveWnd;

EQLIB_VAR DWORD CDBStr__GetString;

EQLIB_VAR DWORD CharacterZoneClient__CastSpell;
EQLIB_VAR DWORD CharacterZoneClient__GetManaRegen;
EQLIB_VAR DWORD CharacterZoneClient__GetHPRegen;
EQLIB_VAR DWORD CharacterZoneClient__GetEnduranceRegen;
EQLIB_VAR DWORD CharacterZoneClient__Cur_HP;
EQLIB_VAR DWORD CharacterZoneClient__Cur_Mana;
EQLIB_VAR DWORD CharacterZoneClient__GetCastingTimeModifier;
EQLIB_VAR DWORD CharacterZoneClient__GetFocusCastingTimeModifier;
EQLIB_VAR DWORD CharacterZoneClient__GetFocusRangeModifier;
EQLIB_VAR DWORD CharacterZoneClient__Max_Endurance;
EQLIB_VAR DWORD CharacterZoneClient__Max_HP;
EQLIB_VAR DWORD CharacterZoneClient__Max_Mana;
EQLIB_VAR DWORD CharacterZoneClient__doCombatAbility;
EQLIB_VAR DWORD CharacterZoneClient__UseSkill;
EQLIB_VAR DWORD CharacterZoneClient__IsExpansionFlag;
EQLIB_VAR DWORD CharacterZoneClient__TotalEffect;
EQLIB_VAR DWORD CharacterZoneClient__GetPCSpellAffect;
EQLIB_VAR DWORD CharacterZoneClient__SpellDuration;
EQLIB_VAR DWORD CharacterZoneClient__FindItemByGuid;
EQLIB_VAR DWORD CharacterZoneClient__FindItemByRecord;
EQLIB_VAR DWORD CharacterZoneClient__GetAdjustedSkill;
EQLIB_VAR DWORD CharacterZoneClient__GetBaseSkill;
EQLIB_VAR DWORD CharacterZoneClient__CanUseItem;
EQLIB_VAR DWORD BaseProfile__GetItemPossession;

EQLIB_VAR DWORD ArrayClass__DeleteElement;
EQLIB_VAR DWORD __GameLoop;
EQLIB_VAR DWORD AggroMeterManagerClient__Instance;
EQLIB_VAR DWORD ClientSOIManager__GetSingleton;
EQLIB_VAR DWORD MercenaryAlternateAdvancementManagerClient__Instance;
EQLIB_VAR DWORD CTargetManager__Get;
EQLIB_VAR DWORD CBroadcast__Get;
EQLIB_VAR DWORD EQGroundItemListManager__Instance;
EQLIB_VAR DWORD EverQuestinfo__IsItemPending;

EQLIB_VAR DWORD ProfileManager__GetCurrentProfile;

EQLIB_VAR DWORD CCharacterListWnd__SelectCharacter;
EQLIB_VAR DWORD CCharacterListWnd__EnterWorld;
EQLIB_VAR DWORD CCharacterListWnd__Quit;
EQLIB_VAR DWORD CCharacterListWnd__UpdateList;

EQLIB_VAR DWORD EQ_Item__CanDrop;
EQLIB_VAR DWORD EQ_Item__CreateItemTagString;
EQLIB_VAR DWORD EQ_Item__IsStackable;
EQLIB_VAR DWORD EQ_Item__GetImageNum;
EQLIB_VAR DWORD EQ_Item__CreateItemClient;
EQLIB_VAR DWORD EQ_Item__GetItemValue;
EQLIB_VAR DWORD EQ_Item__ValueSellMerchant;
EQLIB_VAR DWORD EQ_Item__IsKeyRingItem;
EQLIB_VAR DWORD EQ_Item__CanGoInBag;
EQLIB_VAR DWORD EQ_Item__IsEmpty;
EQLIB_VAR DWORD EQ_Item__GetMaxItemCount;
EQLIB_VAR DWORD EQ_Item__GetAugmentFitBySlot;

EQLIB_VAR DWORD EQ_LoadingS__SetProgressBar;
EQLIB_VAR DWORD EQ_LoadingS__Array;

EQLIB_VAR DWORD EQ_PC__AlertInventoryChanged;
EQLIB_VAR DWORD EQ_PC__DestroyHeldItemOrMoney;
EQLIB_VAR DWORD EQ_PC__GetAlternateAbilityId;
EQLIB_VAR DWORD EQ_PC__GetCombatAbility;
EQLIB_VAR DWORD EQ_PC__GetPcZoneClient;
EQLIB_VAR DWORD EQ_PC__GetCombatAbilityTimer;
EQLIB_VAR DWORD EQ_PC__GetItemRecastTimer;
EQLIB_VAR DWORD EQ_PC__HasLoreItem;
EQLIB_VAR DWORD EQ_PC__RemoveMyAffect;
EQLIB_VAR DWORD EQ_PC__GetKeyRingItems;
EQLIB_VAR DWORD EQ_PC__GetItemContainedRealEstateIds;
EQLIB_VAR DWORD EQ_PC__GetNonArchivedOwnedRealEstates;

EQLIB_VAR DWORD ItemBaseContainer__ItemBaseContainer;
EQLIB_VAR DWORD ItemBaseContainer__CreateItemGlobalIndex;

EQLIB_VAR DWORD ItemBase__IsLore;
EQLIB_VAR DWORD ItemBase__IsLoreEquipped;

EQLIB_VAR DWORD EQItemList__EQItemList;
EQLIB_VAR DWORD EQItemList__add_item;
EQLIB_VAR DWORD EQItemList__delete_item;
EQLIB_VAR DWORD EQItemList__FreeItemList;

EQLIB_VAR DWORD EQMisc__GetActiveFavorCost;

EQLIB_VAR DWORD RealEstateManagerClient__GetItemByRealEstateAndItemIds;
EQLIB_VAR DWORD RealEstateManagerClient__Instance;
EQLIB_VAR DWORD FactionManagerClient__Instance;
EQLIB_VAR DWORD FactionManagerClient__HandleFactionMessage;

EQLIB_VAR DWORD ChatManagerClient__Instance;
EQLIB_VAR DWORD EQPlacedItemManager__Instance;
EQLIB_VAR DWORD EQPlacedItemManager__GetItemByGuid;
EQLIB_VAR DWORD EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds;
EQLIB_VAR DWORD EQPlayer__ChangeBoneStringSprite;
EQLIB_VAR DWORD EQPlayer__dEQPlayer;
EQLIB_VAR DWORD EQPlayer__DoAttack;
EQLIB_VAR DWORD EQPlayer__EQPlayer;
EQLIB_VAR DWORD EQPlayer__SetNameSpriteState;
EQLIB_VAR DWORD EQPlayer__SetNameSpriteTint;
EQLIB_VAR DWORD PlayerBase__HasProperty_j;
EQLIB_VAR DWORD EQPlayer__IsTargetable;
EQLIB_VAR DWORD EQPlayer__CanSee;
EQLIB_VAR DWORD PlayerZoneClient__ChangeHeight;
EQLIB_VAR DWORD PlayerZoneClient__GetLevel;
EQLIB_VAR DWORD PlayerZoneClient__IsValidTeleport;
EQLIB_VAR DWORD EQPlayer__CanSee1;
EQLIB_VAR DWORD PlayerBase__GetVisibilityLineSegment;
EQLIB_VAR DWORD PlayerZoneClient__LegalPlayerRace;


EQLIB_VAR DWORD PlayerClient__GetPcClient;
EQLIB_VAR DWORD PcClient__PcClient;
EQLIB_VAR DWORD PcClient__GetConLevel;

EQLIB_VAR DWORD EQPlayerManager__GetSpawnByID;
EQLIB_VAR DWORD EQPlayerManager__GetSpawnByName;
EQLIB_VAR DWORD EQPlayerManager__GetPlayerFromPartialName;

EQLIB_VAR DWORD KeypressHandler__Get;
EQLIB_VAR DWORD KeypressHandler__AttachAltKeyToEqCommand;
EQLIB_VAR DWORD KeypressHandler__AttachKeyToEqCommand;
EQLIB_VAR DWORD KeypressHandler__ClearCommandStateArray;
EQLIB_VAR DWORD KeypressHandler__HandleKeyDown;
EQLIB_VAR DWORD KeypressHandler__HandleKeyUp;
EQLIB_VAR DWORD KeypressHandler__SaveKeymapping;

EQLIB_VAR DWORD MapViewMap__Clear;
EQLIB_VAR DWORD MapViewMap__SaveEx;
EQLIB_VAR DWORD MapViewMap__SetZoom;

EQLIB_VAR DWORD PlayerPointManager__GetAltCurrency;

EQLIB_VAR DWORD StringTable__getString;

EQLIB_VAR DWORD PcZoneClient__GetPcSkillLimit;
EQLIB_VAR DWORD PcZoneClient__HasCombatAbility;
EQLIB_VAR DWORD PcZoneClient__RemovePetEffect;
EQLIB_VAR DWORD PcZoneClient__HasAlternateAbility;
EQLIB_VAR DWORD PcZoneClient__GetCurrentMod;
EQLIB_VAR DWORD PcZoneClient__GetModCap;
EQLIB_VAR DWORD PcZoneClient__CanEquipItem;
EQLIB_VAR DWORD PcZoneClient__GetItemByID;
EQLIB_VAR DWORD PcZoneClient__GetItemByItemClass;
EQLIB_VAR DWORD PcZoneClient__RemoveBuffEffect;
EQLIB_VAR DWORD PcZoneClient__BandolierSwap;
EQLIB_VAR DWORD PcZoneClient__GetLinkedSpellReuseTimer;

EQLIB_VAR DWORD EQSwitch__UseSwitch;
EQLIB_VAR DWORD IconCache__GetIcon;
EQLIB_VAR DWORD CContainerMgr__OpenContainer;

EQLIB_VAR DWORD CContainerMgr__CloseContainer;
EQLIB_VAR DWORD CQuantityWnd__Open;

EQLIB_VAR DWORD CHelpWnd__SetFile;
EQLIB_VAR DWORD EQ_Spell__GetSpellLevelNeeded;
EQLIB_VAR DWORD EQ_Spell__SpellAffects;
EQLIB_VAR DWORD EQ_Spell__IsStackable;
EQLIB_VAR DWORD EQ_Spell__GetSpellAffectBySlot;
EQLIB_VAR DWORD EQ_Spell__GetSpellAffectByIndex;
EQLIB_VAR DWORD EQ_Spell__IsSPAStacking;
EQLIB_VAR DWORD EQ_Spell__IsSPAIgnoredByStacking;
EQLIB_VAR DWORD EQ_Spell__SpellAffectBase;
EQLIB_VAR DWORD EQ_Spell__IsNoRemove;
EQLIB_VAR DWORD EQ_Spell__IsDegeneratingLevelMod;

EQLIB_VAR DWORD EQSpellStrings__GetString;

EQLIB_VAR DWORD __IsResEffectSpell;
EQLIB_VAR DWORD EQ_Affect__GetAffectData;

EQLIB_VAR DWORD CharacterZoneClient__CalcAffectChangeGeneric;
EQLIB_VAR DWORD CharacterZoneClient__GetFocusReuseMod;
EQLIB_VAR DWORD CharacterZoneClient__CalcAffectChange;
EQLIB_VAR DWORD CLootWnd__LootAll;
EQLIB_VAR DWORD CLootWnd__RequestLootSlot;
EQLIB_VAR DWORD CTargetWnd__GetBuffCaster;
EQLIB_VAR DWORD CTargetWnd__WndNotification;
EQLIB_VAR DWORD CTaskWnd__UpdateTaskTimers;
EQLIB_VAR DWORD CTaskManager__GetEntry;

EQLIB_VAR DWORD EqSoundManager__WavePlay;
EQLIB_VAR DWORD EqSoundManager__PlayScriptMp3;
EQLIB_VAR DWORD EqSoundManager__SoundAssistPlay;
EQLIB_VAR DWORD EqSoundManager__WaveInstancePlay;
EQLIB_VAR DWORD CCombatSkillsSelectWnd__ShouldDisplayThisSkill;
EQLIB_VAR DWORD ActorClient__GetPosition;
EQLIB_VAR DWORD ActorClient__GetPosition1;
EQLIB_VAR DWORD CTextureAnimation__SetCurCell;
EQLIB_VAR DWORD msg_spell_worn_off;
EQLIB_VAR DWORD msg_new_text;
EQLIB_VAR DWORD __msgTokenTextParam;
EQLIB_VAR DWORD msgTokenText;
EQLIB_VAR DWORD SpellManager__SpellManager;
EQLIB_VAR DWORD Spellmanager__LoadTextSpells;
EQLIB_VAR DWORD SpellManager__GetSpellByGroupAndRank;
EQLIB_VAR DWORD CLargeDialogWnd__Open;
EQLIB_VAR DWORD CWndDisplayManager__FindWindowA;
EQLIB_VAR DWORD CItemDisplayManager__CreateWindowInstance;
EQLIB_VAR DWORD CCursorAttachment__AttachToCursor;
EQLIB_VAR DWORD CCursorAttachment__AttachToCursor1;
EQLIB_VAR DWORD CCursorAttachment__Deactivate;
EQLIB_VAR DWORD CEQSuiteTextureLoader__GetDefaultUIPath;
EQLIB_VAR DWORD CEQSuiteTextureLoader__GetTexture;

//----------------------------------------------------------------------------
// Global data

EQLIB_VAR StringTable** ppStringTable;
#define pStringTable (*ppStringTable)

EQLIB_VAR DatabaseStringTable** ppCDBStr;
#define pCDBStr (*ppCDBStr)
EQLIB_VAR EQMisc* pEQMisc;
EQLIB_VAR CSkillMgr** ppCSkillMgr;
#define pCSkillMgr (*ppCSkillMgr)
EQLIB_VAR CGuild* pGuild;

EQLIB_VAR CEverQuest** ppEverQuest;
#define pEverQuest (*ppEverQuest)
EQLIB_VAR CDisplay** ppDisplay;
#define pDisplay (*ppDisplay)
EQLIB_VAR PcClient** ppPCData;
#define pPCData (*ppPCData)
EQLIB_VAR PcClient** ppCharData;
#define pCharData (*ppCharData)
EQLIB_VAR PlayerClient** ppCharSpawn; // player that is being controlled
#define pCharSpawn (*ppCharSpawn)
EQLIB_VAR PlayerClient** ppActiveMerchant;
#define pActiveMerchant (*ppActiveMerchant)
EQLIB_VAR PlayerManagerClient** ppSpawnManager;
#define pSpawnManager (*ppSpawnManager)
#define pSpawnList ((pSpawnManager)->FirstSpawn)
#define pChatService ((CChatService*)((EVERQUEST*)pEverQuest)->ChatService)
#define pPlayerPointManager ((PlayerPointManager*)&GetCharInfo()->PointManager.vfTable)

EQLIB_VAR PlayerClient** ppLocalPlayer; // the local player
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
EQLIB_VAR GUILDS* pGuildList;
EQLIB_VAR EQSOCIAL*   pSocialList;

EQLIB_VAR BYTE* pgHotkeyPage;
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
EQLIB_VAR EQRAID* pRaid;
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

EQLIB_VAR SpellLoadout* pSpellSets;
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

using fEQNewUIINI            = char* (*)();
EQLIB_VAR fEQNewUIINI          NewUIINI;

using fEQProcGameEvts        = int    (*)();
EQLIB_VAR fEQProcGameEvts      ProcessGameEvents;

using fEQToggleKeyRingItem   = int    (*)(int, CONTENTS**, int);
EQLIB_VAR fEQToggleKeyRingItem cmdToggleKeyRingItem;

using fGetLabelFromEQ        = bool   (*)(int, CXStr*, bool*, COLORREF*);
EQLIB_VAR fGetLabelFromEQ      GetLabelFromEQ;

EQLIB_VAR DWORD EQADDR_CONVERTITEMTAGS;

EQLIB_VAR DWORD EQADDR_MEMCHECK0;
EQLIB_VAR DWORD EQADDR_MEMCHECK1;
EQLIB_VAR DWORD EQADDR_MEMCHECK2;
EQLIB_VAR DWORD EQADDR_MEMCHECK3;
EQLIB_VAR DWORD EQADDR_MEMCHECK4;
EQLIB_VAR char* EQADDR_SERVERHOST;
EQLIB_VAR char* EQADDR_SERVERNAME;
EQLIB_VAR DWORD EQADDR_HWND;
EQLIB_VAR CMDLIST* EQADDR_CMDLIST;

EQLIB_VAR BYTE* EQADDR_ATTACK;
EQLIB_VAR BYTE* EQADDR_NOTINCHATMODE;
EQLIB_VAR BYTE* EQADDR_RUNWALKSTATE;
EQLIB_VAR char* EQADDR_LASTTELL;
EQLIB_VAR void* EQADDR_GWORLD;
EQLIB_VAR int* EQADDR_DOABILITYLIST;
EQLIB_VAR PDWORD EQADDR_SUBSCRIPTIONTYPE;
EQLIB_VAR DWORD EQADDR_GROUPAGGRO;
EQLIB_VAR char* EQADDR_TARGETAGGROHOLDER;
EQLIB_VAR BYTE* EQADDR_ZONETYPE;

EQLIB_VAR BOOL gbUseTellWindows;

// FIXME: Remove these macros
#define indoor (((*EQADDR_ZONETYPE) == 0) || ((*EQADDR_ZONETYPE) == 3) || ((*EQADDR_ZONETYPE) == 4))
#define outdoor (((*EQADDR_ZONETYPE) == 1) || ((*EQADDR_ZONETYPE) == 2) || ((*EQADDR_ZONETYPE) == 5))
#define bindable (((*EQADDR_ZONETYPE) == 2) || ((*EQADDR_ZONETYPE) == 3) || ((*EQADDR_ZONETYPE) == 4))

//EQLIB_VAR BYTE* EQADDR_DOABILITYAVAILABLE;
EQLIB_VAR BYTE* pTributeActive;

EQLIB_VAR BYTE* EQADDR_ENCRYPTPAD0;
EQLIB_VAR BYTE* EQADDR_ENCRYPTPAD1;
EQLIB_VAR BYTE* EQADDR_ENCRYPTPAD2;
EQLIB_VAR BYTE* EQADDR_ENCRYPTPAD3;
EQLIB_VAR BYTE* EQADDR_ENCRYPTPAD4;

EQLIB_VAR MQMouseInfo* EQADDR_MOUSE;
EQLIB_VAR MOUSECLICK* EQADDR_MOUSECLICK;

EQLIB_VAR MAPLABEL** ppCurrentMapLabel;
#define pCurrentMapLabel (*ppCurrentMapLabel)

EQLIB_VAR char* gpbRangedAttackReady;
#define gbRangedAttackReady (*gpbRangedAttackReady)
EQLIB_VAR char* gpbShowNetStatus;
#define gbShowNetStatus (*gpbShowNetStatus)
EQLIB_VAR DWORD* gpShowNames;
#define gShowNames (*gpShowNames)
EQLIB_VAR DWORD* gpPCNames;
#define gPCNames (*gpPCNames)
EQLIB_VAR BYTE* gpAutoFire;
#define gAutoFire (*gpAutoFire)
EQLIB_VAR AUTOSKILL* gpAutoSkill;
#define gAutoSkill (*gpAutoSkill)
EQLIB_VAR BYTE* gpShiftKeyDown;
#define gShiftKeyDown (*gpShiftKeyDown)
EQLIB_VAR DWORD* gpMouseEventTime;
#define gMouseEventTime (*gpMouseEventTime)
EQLIB_VAR DWORD* gpbCommandEvent;
#define gbCommandEvent (*gpbCommandEvent)

EQLIB_VAR CResolutionHandler** ppCResolutionHandler;
#define pCResolutionHandler (*ppCResolutionHandler)
EQLIB_VAR DWORD* g_ppDrawHandler;
#define g_pDrawHandler (*g_ppDrawHandler)

EQLIB_VAR char** EQMappableCommandList;
EQLIB_VAR BYTE* EQbCommandStates;

EQLIB_VAR DWORD EQADDR_DIMAIN;
EQLIB_VAR IDirectInputDevice8A** EQADDR_DIKEYBOARD;
EQLIB_VAR IDirectInputDevice8A** EQADDR_DIMOUSE;
EQLIB_VAR PPOINT EQADDR_DIMOUSECOPY;
EQLIB_VAR PPOINT EQADDR_DIMOUSECHECK;

EQLIB_VAR DWORD EQADDR_EQLABELS;

EQLIB_VAR SKILLMGR** ppSkillMgr;
#define pSkillMgr (*ppSkillMgr)
EQLIB_VAR EVERQUESTINFO* ppEverQuestInfo;
#define pEverQuestInfo (ppEverQuestInfo)

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


//----------------------------------------------------------------------------
// Global Functions

struct SPAWNINFO;

/* OTHER IMPORTED FROM EQ */
EQLIB_API int CastRay(SPAWNINFO*, float y, float x, float z);
EQLIB_API int CastRayLoc(const CVector3& SourcePos, int Race, float DestX, float DestY, float DestZ);
EQLIB_OBJECT CXStr CleanItemTags(const CXStr& In, bool bFlag);
EQLIB_API float HeadingDiff(float h1, float h2, float* DiffOut);
EQLIB_API float FixHeading(float Heading);
EQLIB_API float get_bearing(float x1, float y1, float x2, float y2);
EQLIB_API unsigned long GetFastTime();

// definitely not a __Stdcall -- ExtendedTargetList member
EQLIB_API const char* __stdcall GetXtargetType(DWORD type);
EQLIB_API DWORD EQGetTime();
EQLIB_OBJECT CXStr STMLToText(const CXStr& In, bool bReplaceBrWithNewline = true);
EQLIB_API class IconCache* __cdecl GetAnimationCache(int index);
EQLIB_API void SaveColors(int, int, int, int);

//----------------------------------------------------------------------------

EQLIB_API KeypressHandler* GetKeyPresshandler();
EQLIB_API AggroMeterManagerClient* GetAggroInfo();
EQLIB_API ClientSOIManager* GetAuraMgr();
EQLIB_API CBroadcast* GetTextOverlay();
EQLIB_API MercenaryAlternateAdvancementManagerClient* GetMercAltAbilities();
EQLIB_API EQGroundItemListManager* GetItemList();


//----------------------------------------------------------------------------

void InitializeGlobals();

EQLIB_API void InitializeEQLib();
EQLIB_API void ShutdownEQLib();

//----------------------------------------------------------------------------

} // namespace eqlib

#if __has_include("globals-private.h")
#include "globals-private.h"
#endif
