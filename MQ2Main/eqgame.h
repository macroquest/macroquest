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
#define __ExpectedVersionDate                                     "Mar 11 2010"
#define __ExpectedVersionTime                                     "14:43:11"
#define __ActualVersionDate                                        0x81F400
#define __ActualVersionTime                                        0x81F40C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x511830
#define __MemChecker1                                              0x6E6EA0
#define __MemChecker2                                              0x573660
#define __MemChecker3                                              0x5735B0
#define __MemChecker4                                              0x69ADF0
#define __EncryptPad0                                              0x8B0190
#define __EncryptPad1                                              0x8BB290
#define __EncryptPad2                                              0x8B2DC8
#define __EncryptPad3                                              0x8B29C8
#define __EncryptPad4                                              0x8BA8D8
#define __AC1                                                      0x661370
#define __AC2                                                      0x4D99C5
#define __AC3                                                      0x4EDA18
#define __AC4                                                      0x4F18E8
#define __AC5                                                      0x4FC058
#define __AC6                                                      0x4FF4DB
#define __AC7                                                      0x4F8584
#define __AC1_Data                                                 0x8078F0

// Direct Input
#define DI8__Main                                                  0xB15CC4
#define DI8__Keyboard                                              0xB15CC8
#define DI8__Mouse                                                 0xB15CCC
#define __AltTimerReady                                            0xA9C9D6
#define __Attack                                                   0xB00076
#define __Autofire                                                 0xB00077
#define __BindList                                                 0x8AA910
#define __Clicks                                                   0xA9B6D0
#define __CommandList                                              0x8AB260
#define __CurrentMapLabel                                          0xB40F60
#define __CurrentSocial                                            0x8A683C
#define __DoAbilityAvailable                                       0xA9C970
#define __DoAbilityList                                            0xAD1F94
#define __do_loot                                                  0x4B2600
#define __DrawHandler                                              0xB50684
#define __GroupCount                                               0xA954CA
#define __Guilds                                                   0xA9AAB0
#define __gWorld                                                   0xA97388
#define __HotkeyPage                                               0xAF9380
#define __HWnd                                                     0xB15A00
#define __InChatMode                                               0xA9B608
#define __LastTell                                                 0xA9D2EC
#define __LMouseHeldTime                                           0xA9B6FC
#define __Mouse                                                    0xB15CD0
#define __MouseLook                                                0xA9B69E
#define __MouseEventTime                                           0xB001B8
#define __NetStatusToggle                                          0xA9B6A1
#define __PCNames                                                  0xA9CD30
#define __RangeAttackReady                                         0xA9C9D4
#define __RMouseHeldTime                                           0xA9B6F8
#define __RunWalkState                                             0xA9B60C
#define __ScreenMode                                               0x9E4D58
#define __ScreenX                                                  0xA9B5C0
#define __ScreenY                                                  0xA9B5C4
#define __ScreenXMax                                               0xA9B5C8
#define __ScreenYMax                                               0xA9B5CC
#define __ServerHost                                               0xA9540C
#define __ServerName                                               0xAD1F54
#define __ShiftKeyDown                                             0xA9BC88
#define __ShowNames                                                0xA9CC04
#define __Socials                                                  0xAD2054


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xA97448
#define instEQZoneInfo                                             0xA9B848
#define instKeypressHandler                                        0xB0019C
#define pinstActiveBanker                                          0xA9741C
#define pinstActiveCorpse                                          0xA97420
#define pinstActiveGMaster                                         0xA97424
#define pinstActiveMerchant                                        0xA97418
#define pinstAltAdvManager                                         0x9E5BD8
#define pinstAuraMgr                                               0x8CE61C
#define pinstBandageTarget                                         0xA97404
#define pinstCamActor                                              0x9E56C4
#define pinstCDBStr                                                0x9E4D48
#define pinstCDisplay                                              0xA9742C
#define pinstCEverQuest                                            0xB15E48
#define pinstCharData                                              0xA973E8
#define pinstCharSpawn                                             0xA97410
#define pinstControlledMissile                                     0xA973E4
#define pinstControlledPlayer                                      0xA97410
#define pinstCSidlManager                                          0xB4FDF8
#define pinstCXWndManager                                          0xB4FDF0
#define instDynamicZone                                            0xA9B490
#define pinstDZMember                                              0xA9B5A0
#define pinstDZTimerInfo                                           0xA9B5A4
#define pinstEQItemList                                            0xA946F0
#define instEQMisc                                                 0x9E4D00
#define pinstEQSoundManager                                        0x9E5BFC
#define instExpeditionLeader                                       0xA9B4DA
#define instExpeditionName                                         0xA9B51A
#define pinstGroup                                                 0xA954C6
#define pinstImeManager                                            0xB4FDFC
#define pinstLocalPlayer                                           0xA973FC
#define pinstMercenaryData                                         0xB00510
#define pinstModelPlayer                                           0xA97428
#define pinstPCData                                                0xA973E8
#define pinstSkillMgr                                              0xB12AB4
#define pinstSpawnManager                                          0xB12910
#define pinstSpellManager                                          0xB12AC0
#define pinstSpellSets                                             0xAF9384
#define pinstStringTable                                           0xA973A4
#define pinstSwitchManager                                         0xA9510C
#define pinstTarget                                                0xA97414
#define pinstTargetObject                                          0xA973EC
#define pinstTargetSwitch                                          0xA973F0
#define pinstTaskMember                                            0x9E4CE0
#define pinstTrackTarget                                           0xA97408
#define pinstTradeTarget                                           0xA973F8
#define instTributeActive                                          0x9E4D25
#define pinstViewActor                                             0x9E56C0
#define pinstWorldData                                             0xA973CC


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x8CBEE4
#define pinstCAudioTriggersWindow                                  0x8CBEB0
#define pinstCCharacterSelect                                      0x9E55C0
#define pinstCFacePick                                             0x9E5570
#define pinstCNoteWnd                                              0x9E5578
#define pinstCBookWnd                                              0x9E557C
#define pinstCPetInfoWnd                                           0x9E5580
#define pinstCTrainWnd                                             0x9E5584
#define pinstCSkillsWnd                                            0x9E5588
#define pinstCSkillsSelectWnd                                      0x9E558C
#define pinstCCombatSkillSelectWnd                                 0x9E5590
#define pinstCFriendsWnd                                           0x9E5594
#define pinstCAuraWnd                                              0x9E5598
#define pinstCRespawnWnd                                           0x9E559C
#define pinstCBandolierWnd                                         0x9E55A0
#define pinstCPotionBeltWnd                                        0x9E55A4
#define pinstCAAWnd                                                0x9E55A8
#define pinstCGroupSearchFiltersWnd                                0x9E55AC
#define pinstCLoadskinWnd                                          0x9E55B0
#define pinstCAlarmWnd                                             0x9E55B4
#define pinstCMusicPlayerWnd                                       0x9E55B8
#define pinstCMailWnd                                              0x9E55C4
#define pinstCMailCompositionWnd                                   0x9E55C8
#define pinstCMailAddressBookWnd                                   0x9E55CC
#define pinstCRaidWnd                                              0x9E55D4
#define pinstCRaidOptionsWnd                                       0x9E55D8
#define pinstCBreathWnd                                            0x9E55DC
#define pinstCMapViewWnd                                           0x9E55E0
#define pinstCMapToolbarWnd                                        0x9E55E4
#define pinstCEditLabelWnd                                         0x9E55E8
#define pinstCTargetWnd                                            0x9E55EC
#define pinstCColorPickerWnd                                       0x9E55F0
#define pinstCPlayerWnd                                            0x9E55F4
#define pinstCOptionsWnd                                           0x9E55F8
#define pinstCBuffWindowNORMAL                                     0x9E55FC
#define pinstCBuffWindowSHORT                                      0x9E5600
#define pinstCharacterCreation                                     0x9E5604
#define pinstCCursorAttachment                                     0x9E5608
#define pinstCCastingWnd                                           0x9E560C
#define pinstCCastSpellWnd                                         0x9E5610
#define pinstCSpellBookWnd                                         0x9E5614
#define pinstCInventoryWnd                                         0x9E5618
#define pinstCBankWnd                                              0x9E561C
#define pinstCQuantityWnd                                          0x9E5620
#define pinstCLootWnd                                              0x9E5624
#define pinstCActionsWnd                                           0x9E5628
#define pinstCCombatAbilityWnd                                     0x9E562C
#define pinstCMerchantWnd                                          0x9E5630
#define pinstCTradeWnd                                             0x9E5634
#define pinstCSelectorWnd                                          0x9E5638
#define pinstCBazaarWnd                                            0x9E563C
#define pinstCBazaarSearchWnd                                      0x9E5640
#define pinstCGiveWnd                                              0x9E5644
#define pinstCTrackingWnd                                          0x9E5648
#define pinstCInspectWnd                                           0x9E564C
#define pinstCSocialEditWnd                                        0x9E5650
#define pinstCFeedbackWnd                                          0x9E5654
#define pinstCBugReportWnd                                         0x9E5658
#define pinstCVideoModesWnd                                        0x9E565C
#define pinstCTextEntryWnd                                         0x9E5664
#define pinstCFileSelectionWnd                                     0x9E5668
#define pinstCCompassWnd                                           0x9E566C
#define pinstCPlayerNotesWnd                                       0x9E5670
#define pinstCGemsGameWnd                                          0x9E5674
#define pinstCTimeLeftWnd                                          0x9E5678
#define pinstCPetitionQWnd                                         0x9E568C
#define pinstCSoulmarkWnd                                          0x9E5690
#define pinstCStoryWnd                                             0x9E5694
#define pinstCJournalTextWnd                                       0x9E5698
#define pinstCJournalCatWnd                                        0x9E569C
#define pinstCBodyTintWnd                                          0x9E56A0
#define pinstCServerListWnd                                        0x9E56A4
#define pinstCAvaZoneWnd                                           0x9E56AC
#define pinstCBlockedBuffWnd                                       0x9E56B0
#define pinstCBlockedPetBuffWnd                                    0x9E56B4
#define pinstCInvSlotMgr                                           0x9E56B8
#define pinstCContainerMgr                                         0x9E56BC
#define pinstCAdventureLeaderboardWnd                              0xB3E478
#define pinstCAdventureRequestWnd                                  0xB3E494
#define pinstCAltStorageWnd                                        0xB3E4F4
#define pinstCAdventureStatsWnd                                    0xB3E4B0
#define pinstCBarterMerchantWnd                                    0xB3E6C0
#define pinstCBarterSearchWnd                                      0xB3E6DC
#define pinstCBarterWnd                                            0xB3E6F8
#define pinstCChatManager                                          0xB3E99C
#define pinstCDynamicZoneWnd                                       0xB3EA94
#define pinstCEQMainWnd                                            0xB3EB08
#define pinstCFellowshipWnd                                        0xB3EB6C
#define pinstCFindLocationWnd                                      0xB3EBA0
#define pinstCGroupSearchWnd                                       0xB3EC50
#define pinstCGroupWnd                                             0xB3EC6C
#define pinstCGuildBankWnd                                         0xB3EC88
#define pinstCGuildMgmtWnd                                         0xB40CC0
#define pinstCGuildTributeMasterWnd                                0xB40CE0
#define pinstCHotButtonWnd                                         0xB40D14
#define pinstCHotButtonWnd1                                        0xB40D14
#define pinstCHotButtonWnd2                                        0xB40D18
#define pinstCHotButtonWnd3                                        0xB40D1C
#define pinstCHotButtonWnd4                                        0xB40D20
#define pinstCItemDisplayManager                                   0xB40DCC
#define pinstCItemExpTransferWnd                                   0xB40DEC
#define pinstCLeadershipWnd                                        0xB40E88
#define pinstCLFGuildWnd                                           0xB40EA4
#define pinstCMIZoneSelectWnd                                      0xB41014
#define pinstCAdventureMerchantWnd                                 0xB41124
#define pinstCConfirmationDialog                                   0xB41140
#define pinstCPopupWndManager                                      0xB41140
#define pinstCProgressionSelectionWnd                              0xB41174
#define pinstCPvPLeaderboardWnd                                    0xB41190
#define pinstCPvPStatsWnd                                          0xB411AC
#define pinstCSystemInfoDialogBox                                  0xB41278
#define pinstCTargetOfTargetWnd                                    0xB41D78
#define pinstCTaskSelectWnd                                        0xB41DAC
#define pinstCTaskTemplateSelectWnd                                0xB41DC8
#define pinstCTaskWnd                                              0xB41DE4
#define pinstCTipWndOFDAY                                          0xB41E60
#define pinstCTipWndCONTEXT                                        0xB41E64
#define pinstCTitleWnd                                             0xB41E80
#define pinstCTradeskillWnd                                        0xB41EC4
#define pinstCTributeBenefitWnd                                    0xB41F10
#define pinstCTributeMasterWnd                                     0xB41F2C
#define pinstCContextMenuManager                                   0xB4FE54
#define pinstCVoiceMacroWnd                                        0xB12CB4
#define pinstCHtmlWnd                                              0xB12D00


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay                                                  0x4C6460
#define __ConvertItemTags                                          0x4B7C80
#define __ExecuteCmd                                               0x4A4040
#define __get_melee_range                                          0x4A9C60
#define __GetGaugeValueFromEQ                                      0x660220
#define __GetLabelFromEQ                                           0x661310
#define __GetXTargetType                                           0x7555E0
#define __LoadFrontEnd                                             0x572530
#define __NewUIINI                                                 0x65FDB0
#define __ProcessGameEvents                                        0x4F8970
#define CrashDetected                                              0x572330
#define DrawNetStatus                                              0x51C120
#define Util__FastTime                                             0x6E75B0


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x47B470
#define AltAdvManager__IsAbilityReady                              0x47B4B0
#define AltAdvManager__GetAltAbility                               0x47B710

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x58FA60

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5992B0

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x7154B0

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5AF190
#define CChatManager__InitContextMenu                              0x5AF960

// CChatService
#define CChatService__GetNumberOfFriends                           0x6D1710
#define CChatService__GetFriendName                                0x6D1720

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5B3B60
#define CChatWindow__Clear                                         0x5B44D0
#define CChatWindow__WndNotification                               0x5B46C0

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x6FF4F0
#define CComboWnd__Draw                                            0x6FF6B0
#define CComboWnd__GetCurChoice                                    0x6FF490
#define CComboWnd__GetListRect                                     0x6FF9A0
#define CComboWnd__GetTextRect                                     0x6FF520
#define CComboWnd__InsertChoice                                    0x6FFA10
#define CComboWnd__SetColors                                       0x6FF420
#define CComboWnd__SetChoice                                       0x6FF450

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5BBB70
#define CContainerWnd__vftable                                     0x826E30

// CDisplay 
#define CDisplay__CleanGameUI                                      0x46E590
#define CDisplay__GetClickedActor                                  0x4678D0
#define CDisplay__GetUserDefinedColor                              0x4669F0
#define CDisplay__GetWorldFilePath                                 0x465E80
#define CDisplay__is3dON                                           0x464FC0
#define CDisplay__ReloadUI                                         0x478680
#define CDisplay__WriteTextHD2                                     0x46A5B0

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x589A70
#define CEditBaseWnd__SetSel                                       0x721EB0

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x7085A0
#define CEditWnd__GetCharIndexPt                                   0x709570
#define CEditWnd__GetDisplayString                                 0x708740
#define CEditWnd__GetHorzOffset                                    0x7089D0
#define CEditWnd__GetLineForPrintableChar                          0x709020
#define CEditWnd__GetSelStartPt                                    0x7097C0
#define CEditWnd__GetSTMLSafeText                                  0x708B70
#define CEditWnd__PointFromPrintableChar                           0x709130
#define CEditWnd__SelectableCharFromPoint                          0x7092B0
#define CEditWnd__SetEditable                                      0x708B40

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4DA0A0
#define CEverQuest__DropHeldItemOnGround                           0x4DE640
#define CEverQuest__dsp_chat                                       0x4DFDE0
#define CEverQuest__DoTellWindow                                   0x4DE7C0
#define CEverQuest__EnterZone                                      0x4F1880
#define CEverQuest__GetBodyTypeDesc                                0x4D72A0
#define CEverQuest__GetClassDesc                                   0x4D6AE0
#define CEverQuest__GetClassThreeLetterCode                        0x4D70E0
#define CEverQuest__GetDeityDesc                                   0x4D7910
#define CEverQuest__GetLangDesc                                    0x4D7630
#define CEverQuest__GetRaceDesc                                    0x4D78E0
#define CEverQuest__InterpretCmd                                   0x4E0940
#define CEverQuest__LeftClickedOnPlayer                            0x4F33B0
#define CEverQuest__LMouseUp                                       0x4F6CC0
#define CEverQuest__RightClickedOnPlayer                           0x4F7560
#define CEverQuest__RMouseUp                                       0x4F8540
#define CEverQuest__SetGameState                                   0x4DA530
#define CEverQuest__Emote                                          0x4E0000

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5C83C0
#define CGaugeWnd__CalcLinesFillRect                               0x5C8420
#define CGaugeWnd__Draw                                            0x5C8870

// CGuild
#define CGuild__FindMemberByName                                   0x41AFF0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x5E13A0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x5EA950
#define CInvSlotMgr__MoveItem                                      0x5EAAF0

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x5EA1E0
#define CInvSlot__SliderComplete                                   0x5E92F0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x5EBAA0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x65DB90
#define CItemDisplayWnd__UpdateStrings                             0x5EC750

// CLabel 
#define CLabel__Draw                                               0x5FEE30

// CListWnd 
#define CListWnd__AddColumn                                        0x6F8F10
#define CListWnd__AddColumn1                                       0x6F89E0
#define CListWnd__AddLine                                          0x6F8500
#define CListWnd__AddString                                        0x6F86A0
#define CListWnd__CalculateFirstVisibleLine                        0x6F51C0
#define CListWnd__CalculateVSBRange                                0x6F73E0
#define CListWnd__ClearAllSel                                      0x6F4710
#define CListWnd__CloseAndUpdateEditWindow                         0x6F5840
#define CListWnd__Compare                                          0x6F5BE0
#define CListWnd__Draw                                             0x6F7060
#define CListWnd__DrawColumnSeparators                             0x6F6ED0
#define CListWnd__DrawHeader                                       0x6F49A0
#define CListWnd__DrawItem                                         0x6F64F0
#define CListWnd__DrawLine                                         0x6F6B40
#define CListWnd__DrawSeparator                                    0x6F6F70
#define CListWnd__EnsureVisible                                    0x6F5250
#define CListWnd__ExtendSel                                        0x6F6410
#define CListWnd__GetColumnMinWidth                                0x6F44A0
#define CListWnd__GetColumnWidth                                   0x6F43E0
#define CListWnd__GetCurSel                                        0x6F3DF0
#define CListWnd__GetHeaderRect                                    0x6F3F60
#define CListWnd__GetItemAtPoint                                   0x6F5550
#define CListWnd__GetItemAtPoint1                                  0x6F55C0
#define CListWnd__GetItemData                                      0x6F4190
#define CListWnd__GetItemHeight                                    0x6F4E30
#define CListWnd__GetItemIcon                                      0x6F4320
#define CListWnd__GetItemRect                                      0x6F5330
#define CListWnd__GetItemText                                      0x6F41D0
#define CListWnd__GetSelList                                       0x6F88C0
#define CListWnd__GetSeparatorRect                                 0x6F5B20
#define CListWnd__RemoveLine                                       0x6F8870
#define CListWnd__SetColors                                        0x6F3EC0
#define CListWnd__SetColumnJustification                           0x6F4580
#define CListWnd__SetColumnWidth                                   0x6F4460
#define CListWnd__SetCurSel                                        0x6F3E30
#define CListWnd__SetItemColor                                     0x6F8090
#define CListWnd__SetItemData                                      0x6F47B0
#define CListWnd__SetItemText                                      0x6F8010
#define CListWnd__ShiftColumnSeparator                             0x6F6320
#define CListWnd__Sort                                             0x6F8F50
#define CListWnd__ToggleSel                                        0x6F4680

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x614700

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x6226B0
#define CMerchantWnd__RequestBuyItem                               0x6245F0
#define CMerchantWnd__RequestSellItem                              0x624A10
#define CMerchantWnd__SelectBuySellSlot                            0x623A80

// CObfuscator
#define CObfuscator__doit                                          0x6AB6A0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x710DD0
#define CSidlManager__CreateLabel                                  0x656B30

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x701220
#define CSidlScreenWnd__CalculateVSBRange                          0x701140
#define CSidlScreenWnd__ConvertToRes                               0x721D90
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x7016F0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x7027E0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x702890
#define CSidlScreenWnd__dCSidlScreenWnd                            0x701F90
#define CSidlScreenWnd__DrawSidlPiece                              0x7013B0
#define CSidlScreenWnd__EnableIniStorage                           0x700E30
#define CSidlScreenWnd__GetSidlPiece                               0x7015C0
#define CSidlScreenWnd__Init1                                      0x702640
#define CSidlScreenWnd__LoadIniInfo                                0x7017B0
#define CSidlScreenWnd__LoadIniListWnd                             0x700F80
#define CSidlScreenWnd__LoadSidlScreen                             0x7021E0
#define CSidlScreenWnd__StoreIniInfo                               0x700A40
#define CSidlScreenWnd__StoreIniVis                                0x700DC0
#define CSidlScreenWnd__WndNotification                            0x7023C0
#define CSidlScreenWnd__GetChildItem                               0x700E90

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x53FFE0

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x7232F0
#define CSliderWnd__SetValue                                       0x7233F0
#define CSliderWnd__SetNumTicks                                    0x7239A0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x65B8F0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x71FFB0
#define CStmlWnd__CalculateHSBRange                                0x717740
#define CStmlWnd__CalculateVSBRange                                0x7176B0
#define CStmlWnd__CanBreakAtCharacter                              0x7178C0
#define CStmlWnd__FastForwardToEndOfTag                            0x718590
#define CStmlWnd__ForceParseNow                                    0x7204B0
#define CStmlWnd__GetNextTagPiece                                  0x7184B0
#define CStmlWnd__GetSTMLText                                      0x5B3B00
#define CStmlWnd__GetThisChar                                      0x747170
#define CStmlWnd__GetVisiableText                                  0x7199D0
#define CStmlWnd__InitializeWindowVariables                        0x71BF30
#define CStmlWnd__MakeStmlColorTag                                 0x7165D0
#define CStmlWnd__MakeWndNotificationTag                           0x716670
#define CStmlWnd__SetSTMLText                                      0x71C050
#define CStmlWnd__StripFirstSTMLLines                              0x71FC50
#define CStmlWnd__UpdateHistoryString                              0x71A260

// CTabWnd 
#define CTabWnd__Draw                                              0x724740
#define CTabWnd__DrawCurrentPage                                   0x724150
#define CTabWnd__DrawTab                                           0x723F30
#define CTabWnd__GetCurrentPage                                    0x7243D0
#define CTabWnd__GetPageClientRect                                 0x723C00
#define CTabWnd__GetPageFromTabIndex                               0x723E60
#define CTabWnd__GetPageInnerRect                                  0x723C60
#define CTabWnd__GetTabInnerRect                                   0x723DE0
#define CTabWnd__GetTabRect                                        0x723CF0
#define CTabWnd__InsertPage                                        0x7249D0
#define CTabWnd__SetPage                                           0x724410
#define CTabWnd__SetPageRect                                       0x724670
#define CTabWnd__UpdatePage                                        0x724950

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x4175D0

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x702C10

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x7255E0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x6F3000

// CXRect 
#define CXRect__CenterPoint                                        0x58F0E0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x415910
#define CXStr__CXStr1                                              0x6ECC70
#define CXStr__CXStr3                                              0x6E48B0
#define CXStr__dCXStr                                              0x4017D0
#define CXStr__operator_equal1                                     0x6E4A70
#define CXStr__operator_plus_equal1                                0x6E5AB0

// CXWnd 
#define CXWnd__BringToTop                                          0x6F9530
#define CXWnd__Center                                              0x6FDD20
#define CXWnd__ClrFocus                                            0x6F9350
#define CXWnd__DoAllDrawing                                        0x6FEBC0
#define CXWnd__DrawChildren                                        0x6FED10
#define CXWnd__DrawColoredRect                                     0x6F9810
#define CXWnd__DrawTooltip                                         0x6FEA10
#define CXWnd__DrawTooltipAtPoint                                  0x6FDAD0
#define CXWnd__GetBorderFrame                                      0x6F9C50
#define CXWnd__GetChildWndAt                                       0x6FD300
#define CXWnd__GetClientClipRect                                   0x6F9AD0
#define CXWnd__GetScreenClipRect                                   0x6FDF40
#define CXWnd__GetScreenRect                                       0x6F9DE0
#define CXWnd__GetTooltipRect                                      0x6F9920
#define CXWnd__GetWindowTextA                                      0x57D3E0
#define CXWnd__IsActive                                            0x703D80
#define CXWnd__IsDescendantOf                                      0x6F9B80
#define CXWnd__IsReallyVisible                                     0x6FD2E0
#define CXWnd__IsType                                              0x7283F0
#define CXWnd__Move                                                0x6FCAA0
#define CXWnd__Move1                                               0x6FE7F0
#define CXWnd__ProcessTransition                                   0x6F94E0
#define CXWnd__Refade                                              0x6F9460
#define CXWnd__Resize                                              0x6F9EB0
#define CXWnd__Right                                               0x6FDE80
#define CXWnd__SetFocus                                            0x6FB670
#define CXWnd__SetKeyTooltip                                       0x6FA090
#define CXWnd__SetMouseOver                                        0x6FE220
#define CXWnd__StartFade                                           0x6F9570
#define CXWnd__GetChildItem                                        0x6FE1A0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x705350
#define CXWndManager__DrawWindows                                  0x704FD0
#define CXWndManager__GetKeyboardFlags                             0x7039D0
#define CXWndManager__HandleKeyboardMsg                            0x704050
#define CXWndManager__RemoveWnd                                    0x703EA0

// CDBStr
#define CDBStr__GetString                                          0x463910

// EQ_Character 
#define EQ_Character__CastRay                                      0x753320
#define EQ_Character__CastSpell                                    0x42DC80
#define EQ_Character__Cur_HP                                       0x4371A0
#define EQ_Character__GetAACastingTimeModifier                     0x423B00
#define EQ_Character__GetCharInfo2                                 0x6C2720
#define EQ_Character__GetFocusCastingTimeModifier                  0x41F380
#define EQ_Character__GetFocusRangeModifier                        0x41F4C0
#define EQ_Character__Max_Endurance                                0x5226A0
#define EQ_Character__Max_HP                                       0x432180
#define EQ_Character__Max_Mana                                     0x5224D0
#define EQ_Character__doCombatAbility                              0x5213E0
#define EQ_Character__UseSkill                                     0x4418C0
#define EQ_Character__GetConLevel                                  0x51D5F0

// EQ_Item 
#define EQ_Item__CanDrop                                           0x509050
#define EQ_Item__GetItemLinkHash                                   0x6B5150
#define EQ_Item__IsStackable                                       0x6ABF80

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x47C5E0
#define EQ_LoadingS__Array                                         0x8A8D78

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x525540
#define EQ_PC__GetAltAbilityIndex                                  0x6BA3E0
#define EQ_PC__GetCombatAbility                                    0x6BA470
#define EQ_PC__GetCombatAbilityTimer                               0x6BA520
#define EQ_PC__GetItemTimerValue                                   0x520310
#define EQ_PC__HasLoreItem                                         0x5239F0

// EQItemList 
#define EQItemList__EQItemList                                     0x4A7E40
#define EQItemList__add_item                                       0x4A7EF0
#define EQItemList__delete_item                                    0x4A8150
#define EQItemList__FreeItemList                                   0x4A7F10

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x4632C0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x529F20
#define EQPlayer__dEQPlayer                                        0x52E0D0
#define EQPlayer__DoAttack                                         0x53C0C0
#define EQPlayer__EQPlayer                                         0x531E50
#define EQPlayer__SetNameSpriteState                               0x52C030
#define EQPlayer__SetNameSpriteTint                                0x529F90
#define EQPlayer__IsBodyType_j                                     0x752C30
#define EQPlayer__IsTargetable                                     0x752DC0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x533000
#define EQPlayerManager__GetSpawnByName                            0x5332E0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x50AD00
#define KeypressHandler__AttachKeyToEqCommand                      0x50AD40
#define KeypressHandler__ClearCommandStateArray                    0x50AB10
#define KeypressHandler__HandleKeyDown                             0x509690
#define KeypressHandler__HandleKeyUp                               0x5099A0
#define KeypressHandler__SaveKeymapping                            0x50ABE0

// MapViewMap 
#define MapViewMap__Clear                                          0x60FDA0
#define MapViewMap__SaveEx                                         0x610770

#define OtherCharData__GetAltCurrency                              0x6DA3C0

// StringTable 
#define StringTable__getString                                     0x6AB920
