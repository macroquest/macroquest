/******************************************************************************
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
#ifdef PRIVATE
#include "eqgame-private.h"
#endif

#define __ClientName                                              "eqgame"
#define __ExpectedVersionDate                                     "Feb 16 2011"
#define __ExpectedVersionTime                                     "15:55:00"
#define __ActualVersionDate                                        0x89CBAC
#define __ActualVersionTime                                        0x89CBB8

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x524250
#define __MemChecker1                                              0x7AFC40
#define __MemChecker2                                              0x59A420
#define __MemChecker3                                              0x59A370
#define __MemChecker4                                              0x7D1930
#define __EncryptPad0                                              0x93C5E8
#define __EncryptPad1                                              0x9486D8
#define __EncryptPad2                                              0x93F378
#define __EncryptPad3                                              0x93EF78
#define __EncryptPad4                                              0x94A180
#define __AC1                                                      0x6B3200
#define __AC2                                                      0x4E6D55
#define __AC3                                                      0x4F9518
#define __AC4                                                      0x4FEA98
#define __AC5                                                      0x50ACBE
#define __AC6                                                      0x50E42E
#define __AC7                                                      0x50686B
#define __AC1_Data                                                 0x88464D
// Direct Input
#define DI8__Main                                                  0xBA68D4
#define DI8__Keyboard                                              0xBA68D8
#define DI8__Mouse                                                 0xBA68DC
#define __AltTimerReady                                            0xB2AFCA
#define __Attack                                                   0xB8EAB6
#define __Autofire                                                 0xB8EAB7
#define __BindList                                                 0x936B98
#define __Clicks                                                   0xB29C78
#define __CommandList                                              0x937588
#define __CurrentMapLabel                                          0xBD1B78
#define __CurrentSocial                                            0x9329F0
#define __DoAbilityAvailable                                       0xB2AF64
#define __DoAbilityList                                            0xB609D4
#define __do_loot                                                  0x4BBCC0
#define __DrawHandler                                              0x1D56754
#define __GroupCount                                               0xB23A62
#define __Guilds                                                   0xB259F0
#define __gWorld                                                   0xB2591C
#define __HotkeyPage                                               0xB87DC0
#define __HWnd                                                     0xBA6610
#define __InChatMode                                               0xB29BB0
#define __LastTell                                                 0xB2B8EC
#define __LMouseHeldTime                                           0xB29CE4
#define __Mouse                                                    0xBA68E0
#define __MouseLook                                                0xB29C46
#define __MouseEventTime                                           0xB8EC18
#define __NetStatusToggle                                          0xB29C49
#define __PCNames                                                  0xB2B330
#define __RangeAttackReady                                         0xB2AFC8
#define __RMouseHeldTime                                           0xB29CE0
#define __RunWalkState                                             0xB29BB4
#define __ScreenMode                                               0xA732A0
#define __ScreenX                                                  0xB29B68
#define __ScreenY                                                  0xB29B6C
#define __ScreenXMax                                               0xB29B70
#define __ScreenYMax                                               0xB29B74
#define __ServerHost                                               0xB239A4
#define __ServerName                                               0xB60994
#define __ShiftKeyDown                                             0xB2A274
#define __ShowNames                                                0xB2B200
#define __Socials                                                  0xB60A94


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xB25F50
#define instEQZoneInfo                                             0xB29E30
#define instKeypressHandler                                        0xB8EBFC
#define pinstActiveBanker                                          0xB259C4
#define pinstActiveCorpse                                          0xB259C8
#define pinstActiveGMaster                                         0xB259CC
#define pinstActiveMerchant                                        0xB259C0
#define pinstAltAdvManager                                         0xA74148
#define pinstAuraMgr                                               0x95CB5C
#define pinstBandageTarget                                         0xB259AC
#define pinstCamActor                                              0xA73C38
#define pinstCDBStr                                                0xA73294
#define pinstCDisplay                                              0xB259D4
#define pinstCEverQuest                                            0xBA6A58
#define pinstCharData                                              0xB25990
#define pinstCharSpawn                                             0xB259B8
#define pinstControlledMissile                                     0xB2598C
#define pinstControlledPlayer                                      0xB259B8
#define pinstCSidlManager                                          0x1D56C24
#define pinstCXWndManager                                          0x1D56C1C
#define instDynamicZone                                            0xB295B8
#define pinstDZMember                                              0xB296C8
#define pinstDZTimerInfo                                           0xB296CC
#define pinstEQItemList                                            0xB22C74
#define instEQMisc                                                 0xA73240
#define pinstEQSoundManager                                        0xA7416C
#define instExpeditionLeader                                       0xB29602
#define instExpeditionName                                         0xB29642
#define pinstGroup                                                 0xB23A5E
#define pinstImeManager                                            0x1D56C28
#define pinstLocalPlayer                                           0xB259A4
#define pinstMercenaryData                                         0xB8EF8C
#define pinstModelPlayer                                           0xB259D0
#define pinstPCData                                                0xB25990
#define pinstSkillMgr                                              0xBA3694
#define pinstSpawnManager                                          0xBA3478
#define pinstSpellManager                                          0xBA36A0
#define pinstSpellSets                                             0xB87DC4
#define pinstStringTable                                           0xB25938
#define pinstSwitchManager                                         0xB236A4
#define pinstTarget                                                0xB259BC
#define pinstTargetObject                                          0xB25994
#define pinstTargetSwitch                                          0xB25998
#define pinstTaskMember                                            0xA73220
#define pinstTrackTarget                                           0xB259B0
#define pinstTradeTarget                                           0xB259A0
#define instTributeActive                                          0xA73265
#define pinstViewActor                                             0xA73C34
#define pinstWorldData                                             0xB25974


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x95A420
#define pinstCAudioTriggersWindow                                  0x95A3EC
#define pinstCCharacterSelect                                      0xA73B10
#define pinstCFacePick                                             0xA73AC0
#define pinstCNoteWnd                                              0xA73AC8
#define pinstCBookWnd                                              0xA73ACC
#define pinstCPetInfoWnd                                           0xA73AD0
#define pinstCTrainWnd                                             0xA73AD4
#define pinstCSkillsWnd                                            0xA73AD8
#define pinstCSkillsSelectWnd                                      0xA73ADC
#define pinstCCombatSkillSelectWnd                                 0xA73AE0
#define pinstCFriendsWnd                                           0xA73AE4
#define pinstCAuraWnd                                              0xA73AE8
#define pinstCRespawnWnd                                           0xA73AEC
#define pinstCBandolierWnd                                         0xA73AF0
#define pinstCPotionBeltWnd                                        0xA73AF4
#define pinstCAAWnd                                                0xA73AF8
#define pinstCGroupSearchFiltersWnd                                0xA73AFC
#define pinstCLoadskinWnd                                          0xA73B00
#define pinstCAlarmWnd                                             0xA73B04
#define pinstCMusicPlayerWnd                                       0xA73B08
#define pinstCMailWnd                                              0xA73B14
#define pinstCMailCompositionWnd                                   0xA73B18
#define pinstCMailAddressBookWnd                                   0xA73B1C
#define pinstCRaidWnd                                              0xA73B24
#define pinstCRaidOptionsWnd                                       0xA73B28
#define pinstCBreathWnd                                            0xA73B2C
#define pinstCMapViewWnd                                           0xA73B30
#define pinstCMapToolbarWnd                                        0xA73B34
#define pinstCEditLabelWnd                                         0xA73B38
#define pinstCTargetWnd                                            0xA73B3C
#define pinstCColorPickerWnd                                       0xA73B40
#define pinstCPlayerWnd                                            0xA73B44
#define pinstCOptionsWnd                                           0xA73B48
#define pinstCBuffWindowNORMAL                                     0xA73B4C
#define pinstCBuffWindowSHORT                                      0xA73B50
#define pinstCharacterCreation                                     0xA73B54
#define pinstCCursorAttachment                                     0xA73B58
#define pinstCCastingWnd                                           0xA73B5C
#define pinstCCastSpellWnd                                         0xA73B60
#define pinstCSpellBookWnd                                         0xA73B64
#define pinstCInventoryWnd                                         0xA73B68
#define pinstCBankWnd                                              0xA73B6C
#define pinstCQuantityWnd                                          0xA73B70
#define pinstCLootWnd                                              0xA73B74
#define pinstCActionsWnd                                           0xA73B78
#define pinstCCombatAbilityWnd                                     0xA73B7C
#define pinstCMerchantWnd                                          0xA73B80
#define pinstCTradeWnd                                             0xA73B84
#define pinstCSelectorWnd                                          0xA73B88
#define pinstCBazaarWnd                                            0xA73B8C
#define pinstCBazaarSearchWnd                                      0xA73B90
#define pinstCGiveWnd                                              0xA73BAC
#define pinstCTrackingWnd                                          0xA73BB0
#define pinstCInspectWnd                                           0xA73BB4
#define pinstCSocialEditWnd                                        0xA73BB8
#define pinstCFeedbackWnd                                          0xA73BBC
#define pinstCBugReportWnd                                         0xA73BC0
#define pinstCVideoModesWnd                                        0xA73BC4
#define pinstCTextEntryWnd                                         0xA73BCC
#define pinstCFileSelectionWnd                                     0xA73BD0
#define pinstCCompassWnd                                           0xA73BD4
#define pinstCPlayerNotesWnd                                       0xA73BD8
#define pinstCGemsGameWnd                                          0xA73BDC
#define pinstCTimeLeftWnd                                          0xA73BE0
#define pinstCPetitionQWnd                                         0xA73BF4
#define pinstCSoulmarkWnd                                          0xA73BF8
#define pinstCStoryWnd                                             0xA73BFC
#define pinstCJournalTextWnd                                       0xA73C00
#define pinstCJournalCatWnd                                        0xA73C04
#define pinstCBodyTintWnd                                          0xA73C08
#define pinstCServerListWnd                                        0xA73C0C
#define pinstCAvaZoneWnd                                           0xA73C14
#define pinstCBlockedBuffWnd                                       0xA73C18
#define pinstCBlockedPetBuffWnd                                    0xA73C1C
#define pinstCInvSlotMgr                                           0xA73C2C
#define pinstCContainerMgr                                         0xA73C30
#define pinstCAdventureLeaderboardWnd                              0xBCF090
#define pinstCAdventureRequestWnd                                  0xBCF0AC
#define pinstCAltStorageWnd                                        0xBCF10C
#define pinstCAdventureStatsWnd                                    0xBCF0C8
#define pinstCBarterMerchantWnd                                    0xBCF2D8
#define pinstCBarterSearchWnd                                      0xBCF2F4
#define pinstCBarterWnd                                            0xBCF310
#define pinstCChatManager                                          0xBCF5B4
#define pinstCDynamicZoneWnd                                       0xBCF6AC
#define pinstCEQMainWnd                                            0xBCF720
#define pinstCFellowshipWnd                                        0xBCF784
#define pinstCFindLocationWnd                                      0xBCF7B8
#define pinstCGroupSearchWnd                                       0xBCF868
#define pinstCGroupWnd                                             0xBCF884
#define pinstCGuildBankWnd                                         0xBCF8A0
#define pinstCGuildMgmtWnd                                         0xBD18D8
#define pinstCGuildTributeMasterWnd                                0xBD18F8
#define pinstCHotButtonWnd                                         0xBD192C
#define pinstCHotButtonWnd1                                        0xBD192C
#define pinstCHotButtonWnd2                                        0xBD1930
#define pinstCHotButtonWnd3                                        0xBD1934
#define pinstCHotButtonWnd4                                        0xBD1938
#define pinstCItemDisplayManager                                   0xBD19E4
#define pinstCItemExpTransferWnd                                   0xBD1A04
#define pinstCLeadershipWnd                                        0xBD1AA0
#define pinstCLFGuildWnd                                           0xBD1ABC
#define pinstCMIZoneSelectWnd                                      0xBD1C2C
#define pinstCAdventureMerchantWnd                                 0xBD1D54
#define pinstCConfirmationDialog                                   0xBD1D70
#define pinstCPopupWndManager                                      0xBD1D70
#define pinstCProgressionSelectionWnd                              0xBD1DA4
#define pinstCPvPLeaderboardWnd                                    0xBD1DC0
#define pinstCPvPStatsWnd                                          0xBD1DDC
#define pinstCSystemInfoDialogBox                                  0xBD1F20
#define pinstCTargetOfTargetWnd                                    0xBD2A28
#define pinstCTaskSelectWnd                                        0xBD2A5C
#define pinstCTaskTemplateSelectWnd                                0xBD2A78
#define pinstCTaskWnd                                              0xBD2A94
#define pinstCTipWndOFDAY                                          0xBD2B10
#define pinstCTipWndCONTEXT                                        0xBD2B14
#define pinstCTitleWnd                                             0xBD2B30
#define pinstCTradeskillWnd                                        0xBD2B74
#define pinstCTributeBenefitWnd                                    0xBD2BC0
#define pinstCTributeMasterWnd                                     0xBD2BDC
#define pinstCContextMenuManager                                   0x1D56C80
#define pinstCVoiceMacroWnd                                        0xBA3894
#define pinstCHtmlWnd                                              0xBA38D0


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay                                                  0x4CFB70
#define __ConvertItemTags                                          0x4C1350
#define __ExecuteCmd                                               0x4AD260
#define __get_melee_range                                          0x4B32D0
#define __GetGaugeValueFromEQ                                      0x6B2080
#define __GetLabelFromEQ                                           0x6B31A0
#define __GetXTargetType                                           0x7289B0
#define __LoadFrontEnd                                             0x599350
#define __NewUIINI                                                 0x6B1C40
#define __ProcessGameEvents                                        0x506FE0
#define CrashDetected                                              0x599150
#define DrawNetStatus                                              0x5307C0
#define Util__FastTime                                             0x7B03F0
#define Expansion_HoT                                              0xB2B160

//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x482590
#define AltAdvManager__IsAbilityReady                              0x4825D0
#define AltAdvManager__GetAltAbility                               0x4827F0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill                              0x439350

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5B6FE0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5C1300

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x776670

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5D8D50
#define CChatManager__InitContextMenu                              0x5D9520

// CChatService
#define CChatService__GetNumberOfFriends                           0x71D630
#define CChatService__GetFriendName                                0x71D640

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5DD850
#define CChatWindow__Clear                                         0x5DE1B0
#define CChatWindow__WndNotification                               0x5DE3A0

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x760320
#define CComboWnd__Draw                                            0x7604F0
#define CComboWnd__GetCurChoice                                    0x7601E0
#define CComboWnd__GetListRect                                     0x7607E0
#define CComboWnd__GetTextRect                                     0x760350
#define CComboWnd__InsertChoice                                    0x760850
#define CComboWnd__SetColors                                       0x760170
#define CComboWnd__SetChoice                                       0x7601A0

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5E7660
#define CContainerWnd__vftable                                     0x8A43D8

// CDisplay 
#define CDisplay__CleanGameUI                                      0x476680
#define CDisplay__GetClickedActor                                  0x46F6C0
#define CDisplay__GetUserDefinedColor                              0x46E0A0
#define CDisplay__GetWorldFilePath                                 0x46D550
#define CDisplay__is3dON                                           0x46C680
#define CDisplay__ReloadUI                                         0x47F6C0
#define CDisplay__WriteTextHD2                                     0x472400

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x5B0FD0
#define CEditBaseWnd__SetSel                                       0x783C70

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x769620
#define CEditWnd__GetCharIndexPt                                   0x76A5E0
#define CEditWnd__GetDisplayString                                 0x7697B0
#define CEditWnd__GetHorzOffset                                    0x769A40
#define CEditWnd__GetLineForPrintableChar                          0x76A090
#define CEditWnd__GetSelStartPt                                    0x76A830
#define CEditWnd__GetSTMLSafeText                                  0x769BE0
#define CEditWnd__PointFromPrintableChar                           0x76A1A0
#define CEditWnd__SelectableCharFromPoint                          0x76A320
#define CEditWnd__SetEditable                                      0x769BB0

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4E7480
#define CEverQuest__DropHeldItemOnGround                           0x4F48E0
#define CEverQuest__dsp_chat                                       0x4ED880
#define CEverQuest__DoTellWindow                                   0x4EC020
#define CEverQuest__EnterZone                                      0x4FEA30
#define CEverQuest__GetBodyTypeDesc                                0x4E42F0
#define CEverQuest__GetClassDesc                                   0x4E3B30
#define CEverQuest__GetClassThreeLetterCode                        0x4E4130
#define CEverQuest__GetDeityDesc                                   0x4E4960
#define CEverQuest__GetLangDesc                                    0x4E4680
#define CEverQuest__GetRaceDesc                                    0x4E4930
#define CEverQuest__InterpretCmd                                   0x4EE3E0
#define CEverQuest__LeftClickedOnPlayer                            0x500B90
#define CEverQuest__LMouseUp                                       0x504550
#define CEverQuest__RightClickedOnPlayer                           0x5056B0
#define CEverQuest__RMouseUp                                       0x506830
#define CEverQuest__SetGameState                                   0x4E7910
#define CEverQuest__Emote                                          0x4EDAA0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5F4560
#define CGaugeWnd__CalcLinesFillRect                               0x5F45C0
#define CGaugeWnd__Draw                                            0x5F4A10

// CGuild
#define CGuild__FindMemberByName                                   0x41B9F0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x60D790

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x619280
#define CInvSlotMgr__MoveItem                                      0x619690

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x6186E0
#define CInvSlot__SliderComplete                                   0x616A40
#define CInvSlot__GetItemBase                                      0x6161A0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x61A470

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x6AF940
#define CItemDisplayWnd__UpdateStrings                             0x61B360

// CLabel 
#define CLabel__Draw                                               0x62F750

// CListWnd 
#define CListWnd__AddColumn                                        0x758E80
#define CListWnd__AddColumn1                                       0x7584E0
#define CListWnd__AddLine                                          0x758090
#define CListWnd__AddString                                        0x758230
#define CListWnd__CalculateFirstVisibleLine                        0x7543A0
#define CListWnd__CalculateVSBRange                                0x7566D0
#define CListWnd__ClearAllSel                                      0x7538F0
#define CListWnd__CloseAndUpdateEditWindow                         0x757700
#define CListWnd__Compare                                          0x754DA0
#define CListWnd__Draw                                             0x756310
#define CListWnd__DrawColumnSeparators                             0x756180
#define CListWnd__DrawHeader                                       0x753B80
#define CListWnd__DrawItem                                         0x7557A0
#define CListWnd__DrawLine                                         0x755E00
#define CListWnd__DrawSeparator                                    0x756220
#define CListWnd__EnsureVisible                                    0x754500
#define CListWnd__ExtendSel                                        0x7556C0
#define CListWnd__GetColumnMinWidth                                0x7535C0
#define CListWnd__GetColumnWidth                                   0x753500
#define CListWnd__GetCurSel                                        0x752D80
#define CListWnd__GetHeaderRect                                    0x752EE0
#define CListWnd__GetItemAtPoint                                   0x7547D0
#define CListWnd__GetItemAtPoint1                                  0x754840
#define CListWnd__GetItemData                                      0x753100
#define CListWnd__GetItemHeight                                    0x754010
#define CListWnd__GetItemIcon                                      0x7532E0
#define CListWnd__GetItemRect                                      0x7545D0
#define CListWnd__GetItemText                                      0x753190
#define CListWnd__GetSelList                                       0x7583C0
#define CListWnd__GetSeparatorRect                                 0x754CF0
#define CListWnd__RemoveLine                                       0x758E30
#define CListWnd__SetColors                                        0x752E50
#define CListWnd__SetColumnJustification                           0x753760
#define CListWnd__SetColumnWidth                                   0x753580
#define CListWnd__SetCurSel                                        0x752DC0
#define CListWnd__SetItemColor                                     0x7573C0
#define CListWnd__SetItemData                                      0x753990
#define CListWnd__SetItemText                                      0x7571A0
#define CListWnd__ShiftColumnSeparator                             0x757010
#define CListWnd__Sort                                             0x7595C0
#define CListWnd__ToggleSel                                        0x753860

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x6456B0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x656970
#define CMerchantWnd__RequestBuyItem                               0x65A1C0
#define CMerchantWnd__RequestSellItem                              0x679250
#define CMerchantWnd__SelectBuySellSlot                            0x657C50

// CObfuscator
#define CObfuscator__doit                                          0x6ECDD0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x771EA0
#define CSidlManager__CreateLabel                                  0x6A8800

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5B3170
#define CSidlScreenWnd__CalculateVSBRange                          0x5B3090
#define CSidlScreenWnd__ConvertToRes                               0x783B50
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x762720
#define CSidlScreenWnd__CSidlScreenWnd1                            0x763820
#define CSidlScreenWnd__CSidlScreenWnd2                            0x7638D0
#define CSidlScreenWnd__dCSidlScreenWnd                            0x762FD0
#define CSidlScreenWnd__DrawSidlPiece                              0x7623E0
#define CSidlScreenWnd__EnableIniStorage                           0x761BA0
#define CSidlScreenWnd__GetSidlPiece                               0x7625F0
#define CSidlScreenWnd__Init1                                      0x763680
#define CSidlScreenWnd__LoadIniInfo                                0x7627D0
#define CSidlScreenWnd__LoadIniListWnd                             0x761CF0
#define CSidlScreenWnd__LoadSidlScreen                             0x763220
#define CSidlScreenWnd__StoreIniInfo                               0x7617A0
#define CSidlScreenWnd__StoreIniVis                                0x761B30
#define CSidlScreenWnd__WndNotification                            0x763400
#define CSidlScreenWnd__GetChildItem                               0x761C00

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x566A20

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x784540
#define CSliderWnd__SetValue                                       0x784640
#define CSliderWnd__SetNumTicks                                    0x784BF0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x6AD550

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x7811F0
#define CStmlWnd__CalculateHSBRange                                0x778920
#define CStmlWnd__CalculateVSBRange                                0x778890
#define CStmlWnd__CanBreakAtCharacter                              0x778A80
#define CStmlWnd__FastForwardToEndOfTag                            0x779750
#define CStmlWnd__ForceParseNow                                    0x781720
#define CStmlWnd__GetNextTagPiece                                  0x779670
#define CStmlWnd__GetSTMLText                                      0x5DD7F0
#define CStmlWnd__GetThisChar                                      0x7A9080
#define CStmlWnd__GetVisiableText                                  0x77ABA0
#define CStmlWnd__InitializeWindowVariables                        0x77D170
#define CStmlWnd__MakeStmlColorTag                                 0x7777B0
#define CStmlWnd__MakeWndNotificationTag                           0x777850
#define CStmlWnd__SetSTMLText                                      0x77D290
#define CStmlWnd__StripFirstSTMLLines                              0x780EA0
#define CStmlWnd__UpdateHistoryString                              0x77B430

// CTabWnd 
#define CTabWnd__Draw                                              0x785AF0
#define CTabWnd__DrawCurrentPage                                   0x7853C0
#define CTabWnd__DrawTab                                           0x7851A0
#define CTabWnd__GetCurrentPage                                    0x785780
#define CTabWnd__GetPageClientRect                                 0x784E50
#define CTabWnd__GetPageFromTabIndex                               0x7850D0
#define CTabWnd__GetPageInnerRect                                  0x784EB0
#define CTabWnd__GetTabInnerRect                                   0x785050
#define CTabWnd__GetTabRect                                        0x784F40
#define CTabWnd__InsertPage                                        0x785D80
#define CTabWnd__SetPage                                           0x7857C0
#define CTabWnd__SetPageRect                                       0x785A20
#define CTabWnd__UpdatePage                                        0x785D00

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x417FE0

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x763C50

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x786980

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x751D20

// CXRect 
#define CXRect__CenterPoint                                        0x5B6840

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x51DA70
#define CXStr__CXStr1                                              0x6D5CC0
#define CXStr__CXStr3                                              0x7AD650
#define CXStr__dCXStr                                              0x44E650
#define CXStr__operator_equal1                                     0x7AD810
#define CXStr__operator_plus_equal1                                0x7AE8A0

// CXWnd 
#define CXWnd__BringToTop                                          0x759BB0
#define CXWnd__Center                                              0x75EBC0
#define CXWnd__ClrFocus                                            0x7599D0
#define CXWnd__DoAllDrawing                                        0x75F510
#define CXWnd__DrawChildren                                        0x75F660
#define CXWnd__DrawColoredRect                                     0x759EB0
#define CXWnd__DrawTooltip                                         0x75EAF0
#define CXWnd__DrawTooltipAtPoint                                  0x75E220
#define CXWnd__GetBorderFrame                                      0x75A3F0
#define CXWnd__GetChildWndAt                                       0x75D690
#define CXWnd__GetClientClipRect                                   0x75A170
#define CXWnd__GetScreenClipRect                                   0x75E6E0
#define CXWnd__GetScreenRect                                       0x75A510
#define CXWnd__GetTooltipRect                                      0x759FC0
#define CXWnd__GetWindowTextA                                      0x5A4410
#define CXWnd__IsActive                                            0x764D80
#define CXWnd__IsDescendantOf                                      0x75A2E0
#define CXWnd__IsReallyVisible                                     0x75D670
#define CXWnd__IsType                                              0x789780
#define CXWnd__Move                                                0x75CB80
#define CXWnd__Move1                                               0x75CC20
#define CXWnd__ProcessTransition                                   0x759B60
#define CXWnd__Refade                                              0x759AD0
#define CXWnd__Resize                                              0x75A5E0
#define CXWnd__Right                                               0x75E5F0
#define CXWnd__SetFocus                                            0x75BD80
#define CXWnd__SetKeyTooltip                                       0x75A830
#define CXWnd__SetMouseOver                                        0x75E9D0
#define CXWnd__StartFade                                           0x759BF0
#define CXWnd__GetChildItem                                        0x75E940

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x766370
#define CXWndManager__DrawWindows                                  0x765FF0
#define CXWndManager__GetKeyboardFlags                             0x7649E0
#define CXWndManager__HandleKeyboardMsg                            0x765050
#define CXWndManager__RemoveWnd                                    0x764EA0

// CDBStr
#define CDBStr__GetString                                          0x46AF10

// EQ_Character 
#define EQ_Character__CastRay                                      0x70B210
#define EQ_Character__CastSpell                                    0x430260
#define EQ_Character__Cur_HP                                       0x439010
#define EQ_Character__GetAACastingTimeModifier                     0x425380
#define EQ_Character__GetCharInfo2                                 0x709F50
#define EQ_Character__GetFocusCastingTimeModifier                  0x420A90
#define EQ_Character__GetFocusRangeModifier                        0x420C60
#define EQ_Character__Max_Endurance                                0x538990
#define EQ_Character__Max_HP                                       0x433FE0
#define EQ_Character__Max_Mana                                     0x538790
#define EQ_Character__doCombatAbility                              0x537600
#define EQ_Character__UseSkill                                     0x447860
#define EQ_Character__GetConLevel                                  0x532400
#define EQ_Character__IsExpansionFlag                              0x40D920
#define EQ_Character__TotalEffect                                  0x4297E0

// EQ_Item 
#define EQ_Item__CanDrop                                           0x518370
#define EQ_Item__CreateItemTagString                               0x6F9D10
#define EQ_Item__IsStackable                                       0x6ED850

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x4836C0
#define EQ_LoadingS__Array                                         0x934F58

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x53C900
#define EQ_PC__GetAltAbilityIndex                                  0x6FFA00
#define EQ_PC__GetCombatAbility                                    0x6FFA90
#define EQ_PC__GetCombatAbilityTimer                               0x6FFB40
#define EQ_PC__GetItemTimerValue                                   0x537420
#define EQ_PC__HasLoreItem                                         0x708AB0

// EQItemList 
#define EQItemList__EQItemList                                     0x4B1520
#define EQItemList__add_item                                       0x4B14B0
#define EQItemList__delete_item                                    0x4B18D0
#define EQItemList__FreeItemList                                   0x4B1800

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x46A6E0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x541390
#define EQPlayer__dEQPlayer                                        0x545CF0
#define EQPlayer__DoAttack                                         0x5569A0
#define EQPlayer__EQPlayer                                         0x54B510
#define EQPlayer__SetNameSpriteState                               0x5437A0
#define EQPlayer__SetNameSpriteTint                                0x541400
#define EQPlayer__IsBodyType_j                                     0x70AAE0
#define EQPlayer__IsTargetable                                     0x70ACB0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x54C7D0
#define EQPlayerManager__GetSpawnByName                            0x54CB70

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x51D490
#define KeypressHandler__AttachKeyToEqCommand                      0x51D4D0
#define KeypressHandler__ClearCommandStateArray                    0x51D2A0
#define KeypressHandler__HandleKeyDown                             0x51BD10
#define KeypressHandler__HandleKeyUp                               0x51C020
#define KeypressHandler__SaveKeymapping                            0x51D370

// MapViewMap 
#define MapViewMap__Clear                                          0x640D50
#define MapViewMap__SaveEx                                         0x641720

#define PlayerPointManager__GetAltCurrency                         0x6FB160

// StringTable 
#define StringTable__getString                                     0x6ED050