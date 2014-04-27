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
#define __ExpectedVersionDate                                     "Jun 25 2012"
#define __ExpectedVersionTime                                     "12:28:47"
#define __ActualVersionDate                                        0x90C7A4
#define __ActualVersionTime                                        0x90C7B0

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x536EB0
#define __MemChecker1                                              0x816730
#define __MemChecker2                                              0x5B98E0
#define __MemChecker3                                              0x5B9830
#define __MemChecker4                                              0x838EB0
#define __EncryptPad0                                              0x9E44F0
#define __EncryptPad1                                              0xA5CEA0
#define __EncryptPad2                                              0x9FC9A0
#define __EncryptPad3                                              0x9FC5A0
#define __EncryptPad4                                              0xA5E948
#define __AC1                                                      0x6F5B50
#define __AC2                                                      0x4F20B5
#define __AC3                                                      0x504D78
#define __AC4                                                      0x50A6F4
#define __AC5                                                      0x516B08
#define __AC6                                                      0x51A43B
#define __AC7                                                      0x51248B
#define __AC1_Data                                                 0x8F22DD
// Direct Input
#define DI8__Main                                                  0xCE2290
#define DI8__Keyboard                                              0xCE2294
#define DI8__Mouse                                                 0xCE2298
#define __AltTimerReady                                            0xBAA881
#define __Attack                                                   0xCDE092
#define __Autofire                                                 0xCDE093
#define __BindList                                                 0x9CCB58
#define __Clicks                                                   0xC67B84
#define __CommandList                                              0x9CE190
#define __CurrentMapLabel                                          0xD0E0D0
#define __CurrentSocial                                            0x9B8E30
#define __DoAbilityList                                            0xC9EA6C
#define __do_loot                                                  0x4C5CF0
#define __DrawHandler                                              0x136AD6C
#define __GroupCount                                               0xC58742
#define __Guilds                                                   0xC5AAD0
#define __gWorld                                                   0xC5A9FC
#define __HotkeyPage                                               0xCC7648
#define __HWnd                                                     0xCE1FE0
#define __InChatMode                                               0xC67ABC
#define __LastTell                                                 0xC69984
#define __LMouseHeldTime                                           0xC67BF0
#define __Mouse                                                    0xCE229C
#define __MouseLook                                                0xC67B52
#define __MouseEventTime                                           0xCDE3AC
#define __NetStatusToggle                                          0xC67B55
#define __PCNames                                                  0xC69008
#define __RangeAttackReady                                         0xC68CA0
#define __RMouseHeldTime                                           0xC67BEC
#define __RunWalkState                                             0xC67AC0
#define __ScreenMode                                               0xBA7BC8
#define __ScreenX                                                  0xC67A70
#define __ScreenY                                                  0xC67A74
#define __ScreenXMax                                               0xC67A78
#define __ScreenYMax                                               0xC67A7C
#define __ServerHost                                               0xC58684
#define __ServerName                                               0xC9EA2C
#define __ShiftKeyDown                                             0xC6813C
#define __ShowNames                                                0xC68EAC
#define __Socials                                                  0xC9EB2C


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xC643E8
#define instEQZoneInfo                                             0xC67D38
#define instKeypressHandler                                        0xCDE3A8
#define pinstActiveBanker                                          0xC5AAA4
#define pinstActiveCorpse                                          0xC5AAA8
#define pinstActiveGMaster                                         0xC5AAAC
#define pinstActiveMerchant                                        0xC5AAA0
#define pinstAltAdvManager                                         0xBA8B10
#define pinstAuraMgr                                               0xA77D50
#define pinstBandageTarget                                         0xC5AA8C
#define pinstCamActor                                              0xBA8584
#define pinstCDBStr                                                0xBA7BA0
#define pinstCDisplay                                              0xC5AAB4
#define pinstCEverQuest                                            0xCE2418
#define pinstCharData                                              0xC5AA70
#define pinstCharSpawn                                             0xC5AA98
#define pinstControlledMissile                                     0xC5AA6C
#define pinstControlledPlayer                                      0xC5AA98
#define pinstCSidlManager                                          0x136B2AC
#define pinstCXWndManager                                          0x136B2A4
#define instDynamicZone                                            0xC63E40
#define pinstDZMember                                              0xC63F50
#define pinstDZTimerInfo                                           0xC63F54
#define pinstEQItemList                                            0xC577F0
#define instEQMisc                                                 0xBA7B08
#define pinstEQSoundManager                                        0xBA8B80
#define instExpeditionLeader                                       0xC63E8A
#define instExpeditionName                                         0xC63ECA
#define pinstGroup                                                 0xC5873E
#define pinstImeManager                                            0x136B2B0
#define pinstLocalPlayer                                           0xC5AA84
#define pinstMercenaryData                                         0xCDE828
#define pinstModelPlayer                                           0xC5AAB0
#define pinstPCData                                                0xC5AA70
#define pinstSkillMgr                                              0xCDEE58
#define pinstSpawnManager                                          0xCDEAC8
#define pinstSpellManager                                          0xCDEE98
#define pinstSpellSets                                             0xCD73A0
#define pinstStringTable                                           0xC5AA18
#define pinstSwitchManager                                         0xC58350
#define pinstTarget                                                0xC5AA9C
#define pinstTargetObject                                          0xC5AA74
#define pinstTargetSwitch                                          0xC5AA78
#define pinstTaskMember                                            0xBA7AD0
#define pinstTrackTarget                                           0xC5AA90
#define pinstTradeTarget                                           0xC5AA80
#define instTributeActive                                          0xBA7B2D
#define pinstViewActor                                             0xBA8580
#define pinstWorldData                                             0xC5AA54


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0xA6ED90
#define pinstCAudioTriggersWindow                                  0xA6ED28
#define pinstCCharacterSelect                                      0xBA8438
#define pinstCFacePick                                             0xBA83E8
#define pinstCNoteWnd                                              0xBA83F0
#define pinstCBookWnd                                              0xBA83F8
#define pinstCPetInfoWnd                                           0xBA83FC
#define pinstCTrainWnd                                             0xBA8400
#define pinstCSkillsWnd                                            0xBA8404
#define pinstCSkillsSelectWnd                                      0xBA8408
#define pinstCCombatSkillSelectWnd                                 0xBA840C
#define pinstCFriendsWnd                                           0xBA8410
#define pinstCAuraWnd                                              0xBA8414
#define pinstCRespawnWnd                                           0xBA8418
#define pinstCBandolierWnd                                         0xBA841C
#define pinstCPotionBeltWnd                                        0xBA8420
#define pinstCAAWnd                                                0xBA8424
#define pinstCGroupSearchFiltersWnd                                0xBA8428
#define pinstCLoadskinWnd                                          0xBA842C
#define pinstCAlarmWnd                                             0xBA8430
#define pinstCMusicPlayerWnd                                       0xBA8434
#define pinstCMailWnd                                              0xBA843C
#define pinstCMailCompositionWnd                                   0xBA8440
#define pinstCMailAddressBookWnd                                   0xBA8444
#define pinstCRaidWnd                                              0xBA844C
#define pinstCRaidOptionsWnd                                       0xBA8450
#define pinstCBreathWnd                                            0xBA8454
#define pinstCMapViewWnd                                           0xBA8458
#define pinstCMapToolbarWnd                                        0xBA845C
#define pinstCEditLabelWnd                                         0xBA8460
#define pinstCTargetWnd                                            0xBA8464
#define pinstCColorPickerWnd                                       0xBA8468
#define pinstCPlayerWnd                                            0xBA846C
#define pinstCOptionsWnd                                           0xBA8470
#define pinstCBuffWindowNORMAL                                     0xBA8474
#define pinstCBuffWindowSHORT                                      0xBA8478
#define pinstCharacterCreation                                     0xBA847C
#define pinstCCursorAttachment                                     0xBA8480
#define pinstCCastingWnd                                           0xBA8484
#define pinstCCastSpellWnd                                         0xBA8488
#define pinstCSpellBookWnd                                         0xBA848C
#define pinstCInventoryWnd                                         0xBA8490
#define pinstCBankWnd                                              0xBA8494
#define pinstCQuantityWnd                                          0xBA8498
#define pinstCLootWnd                                              0xBA849C
#define pinstCActionsWnd                                           0xBA84A0
#define pinstCCombatAbilityWnd                                     0xBA84A4
#define pinstCMerchantWnd                                          0xBA84A8
#define pinstCTradeWnd                                             0xBA84AC
#define pinstCSelectorWnd                                          0xBA84B0
#define pinstCBazaarWnd                                            0xBA84B4
#define pinstCBazaarSearchWnd                                      0xBA84B8
#define pinstCGiveWnd                                              0xBA84D4
#define pinstCTrackingWnd                                          0xBA84DC
#define pinstCInspectWnd                                           0xBA84E0
#define pinstCSocialEditWnd                                        0xBA84E4
#define pinstCFeedbackWnd                                          0xBA84E8
#define pinstCBugReportWnd                                         0xBA84EC
#define pinstCVideoModesWnd                                        0xBA84F0
#define pinstCTextEntryWnd                                         0xBA84F8
#define pinstCFileSelectionWnd                                     0xBA84FC
#define pinstCCompassWnd                                           0xBA8500
#define pinstCPlayerNotesWnd                                       0xBA8504
#define pinstCGemsGameWnd                                          0xBA8508
#define pinstCTimeLeftWnd                                          0xBA850C
#define pinstCPetitionQWnd                                         0xBA8520
#define pinstCSoulmarkWnd                                          0xBA8524
#define pinstCStoryWnd                                             0xBA8528
#define pinstCJournalTextWnd                                       0xBA852C
#define pinstCJournalCatWnd                                        0xBA8530
#define pinstCBodyTintWnd                                          0xBA8534
#define pinstCServerListWnd                                        0xBA8538
#define pinstCAvaZoneWnd                                           0xBA8540
#define pinstCBlockedBuffWnd                                       0xBA8544
#define pinstCBlockedPetBuffWnd                                    0xBA8548
#define pinstCInvSlotMgr                                           0xBA8578
#define pinstCContainerMgr                                         0xBA857C
#define pinstCAdventureLeaderboardWnd                              0xD0AC08
#define pinstCAdventureRequestWnd                                  0xD0ABD0
#define pinstCAltStorageWnd                                        0xD0AD10
#define pinstCAdventureStatsWnd                                    0xD0AC08
#define pinstCBarterMerchantWnd                                    0xD0B168
#define pinstCBarterSearchWnd                                      0xD0B1A0
#define pinstCBarterWnd                                            0xD0B1D8
#define pinstCChatManager                                          0xD0B5D0
#define pinstCDynamicZoneWnd                                       0xD0B7C0
#define pinstCEQMainWnd                                            0xD0B880
#define pinstCFellowshipWnd                                        0xD0B7B4
#define pinstCFindLocationWnd                                      0xD0B9B0
#define pinstCGroupSearchWnd                                       0xD0BB10
#define pinstCGroupWnd                                             0xD0BB48
#define pinstCGuildBankWnd                                         0xD0BB80
#define pinstCGuildMgmtWnd                                         0xD0DBF0
#define pinstCGuildTributeMasterWnd                                0xD0F818
#define pinstCHotButtonWnd                                         0xD0DC44
#define pinstCHotButtonWnd1                                        0xD0DC44
#define pinstCHotButtonWnd2                                        0xD0DC48
#define pinstCHotButtonWnd3                                        0xD0DC4C
#define pinstCHotButtonWnd4                                        0xD0DC8C
#define pinstCItemDisplayManager                                   0xD0DDC0
#define pinstCItemExpTransferWnd                                   0xD0DDFC
#define pinstCLeadershipWnd                                        0xD0DF28
#define pinstCLFGuildWnd                                           0xD0DF60
#define pinstCMIZoneSelectWnd                                      0xD0E200
#define pinstCAdventureMerchantWnd                                 0xD0E4B0
#define pinstCConfirmationDialog                                   0xD0E4E8
#define pinstCPopupWndManager                                      0xD0E4E8
#define pinstCProgressionSelectionWnd                              0xD0E550
#define pinstCPvPLeaderboardWnd                                    0xD0E588
#define pinstCPvPStatsWnd                                          0xD0E5C0
#define pinstCSystemInfoDialogBox                                  0xD0E8A8
#define pinstCTargetOfTargetWnd                                    0xD0F4C8
#define pinstCTaskSelectWnd                                        0xD0E764
#define pinstCTaskTemplateSelectWnd                                0xD0F568
#define pinstCTaskWnd                                              0xD0F5A0
#define pinstCTipWndOFDAY                                          0xD0F698
#define pinstCTipWndCONTEXT                                        0xD0F69C
#define pinstCTitleWnd                                             0xD0F6D0
#define pinstCTradeskillWnd                                        0xD0F748
#define pinstCTributeBenefitWnd                                    0xD0F7E0
#define pinstCTributeMasterWnd                                     0xD0F818
#define pinstCContextMenuManager                                   0x136B308
#define pinstCVoiceMacroWnd                                        0xCDF1E0
#define pinstCHtmlWnd                                              0xCDF258


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay                                                  0x4DA440
#define __ConvertItemTags                                          0x4CB410
#define __ExecuteCmd                                               0x4B6EE0
#define __EQGetTime                                                0x817B50
#define __get_melee_range                                          0x4BD1D0
#define __GetGaugeValueFromEQ                                      0x6F4900
#define __GetLabelFromEQ                                           0x6F5AF0
#define __GetXTargetType                                           0x773530
#define __LoadFrontEnd                                             0x5B8850
#define __NewUIINI                                                 0x6F44B0
#define __ProcessGameEvents                                        0x512C70
#define CrashDetected                                              0x5B8650
#define DrawNetStatus                                              0x544880
#define Util__FastTime                                             0x817000
#define Expansion_HoT                                              0xC68E0C
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x489BB0
#define AltAdvManager__IsAbilityReady                              0x489C60
#define AltAdvManager__GetAltAbility                               0x489E80

// CharacterZoneClient
#define CharacterZoneClient__HasSkill                              0x43D040

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5DF4F0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5E9570

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x5250A0

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x6029C0
#define CChatManager__InitContextMenu                              0x6032F0

// CChatService
#define CChatService__GetNumberOfFriends                           0x76A170
#define CChatService__GetFriendName                                0x76A180

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x6080B0
#define CChatWindow__Clear                                         0x607C60
#define CChatWindow__WndNotification                               0x6084C0

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x7C6340
#define CComboWnd__Draw                                            0x7C6500
#define CComboWnd__GetCurChoice                                    0x7C6160
#define CComboWnd__GetListRect                                     0x7C67E0
#define CComboWnd__GetTextRect                                     0x7C6370
#define CComboWnd__InsertChoice                                    0x7C6850
#define CComboWnd__SetColors                                       0x7C60F0
#define CComboWnd__SetChoice                                       0x7C6120

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x6119B0
#define CContainerWnd__vftable                                     0x9151E8

// CDisplay 
#define CDisplay__CleanGameUI                                      0x47D4A0
#define CDisplay__GetClickedActor                                  0x475F20
#define CDisplay__GetUserDefinedColor                              0x474850
#define CDisplay__GetWorldFilePath                                 0x473D70
#define CDisplay__is3dON                                           0x472E70
#define CDisplay__ReloadUI                                         0x486AB0
#define CDisplay__WriteTextHD2                                     0x478F60

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x5D7130
#define CEditBaseWnd__SetSel                                       0x7E6C70

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x7CF9E0
#define CEditWnd__GetCharIndexPt                                   0x7D09B0
#define CEditWnd__GetDisplayString                                 0x7CFB80
#define CEditWnd__GetHorzOffset                                    0x7CFE10
#define CEditWnd__GetLineForPrintableChar                          0x7D0460
#define CEditWnd__GetSelStartPt                                    0x7D0BF0
#define CEditWnd__GetSTMLSafeText                                  0x7CFFB0
#define CEditWnd__PointFromPrintableChar                           0x7D0570
#define CEditWnd__SelectableCharFromPoint                          0x7D06F0
#define CEditWnd__SetEditable                                      0x7CFF80

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4F2800
#define CEverQuest__DropHeldItemOnGround                           0x4FF780
#define CEverQuest__dsp_chat                                       0x4F8B20
#define CEverQuest__DoTellWindow                                   0x4F7260
#define CEverQuest__EnterZone                                      0x50A680
#define CEverQuest__GetBodyTypeDesc                                0x4EF600
#define CEverQuest__GetClassDesc                                   0x4EEE40
#define CEverQuest__GetClassThreeLetterCode                        0x4EF440
#define CEverQuest__GetDeityDesc                                   0x4EFCB0
#define CEverQuest__GetLangDesc                                    0x4EF990
#define CEverQuest__GetRaceDesc                                    0x4EFC80
#define CEverQuest__InterpretCmd                                   0x4F9630
#define CEverQuest__LeftClickedOnPlayer                            0x50C720
#define CEverQuest__LMouseUp                                       0x510310
#define CEverQuest__RightClickedOnPlayer                           0x511470
#define CEverQuest__RMouseUp                                       0x512450
#define CEverQuest__SetGameState                                   0x4F2C90
#define CEverQuest__Emote                                          0x4F8D40

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x61F9B0
#define CGaugeWnd__CalcLinesFillRect                               0x61FA10
#define CGaugeWnd__Draw                                            0x61FE60

// CGuild
#define CGuild__FindMemberByName                                   0x41CF00

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x639EF0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x6442D0
#define CInvSlotMgr__MoveItem                                      0x644F80

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x643950
#define CInvSlot__SliderComplete                                   0x641C40
#define CInvSlot__GetItemBase                                      0x6412D0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x645CD0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x6F1EB0
#define CItemDisplayWnd__UpdateStrings                             0x646D10

// CLabel 
#define CLabel__Draw                                               0x65B480

// CListWnd 
#define CListWnd__AddColumn                                        0x7BBF10
#define CListWnd__AddColumn1                                       0x7BB540
#define CListWnd__AddLine                                          0x7BB0F0
#define CListWnd__AddString                                        0x7BB290
#define CListWnd__CalculateFirstVisibleLine                        0x7B7360
#define CListWnd__CalculateVSBRange                                0x7B9760
#define CListWnd__ClearAllSel                                      0x7B68B0
#define CListWnd__CloseAndUpdateEditWindow                         0x7BA760
#define CListWnd__Compare                                          0x7B7E00
#define CListWnd__Draw                                             0x7B93A0
#define CListWnd__DrawColumnSeparators                             0x7B9230
#define CListWnd__DrawHeader                                       0x7B6B40
#define CListWnd__DrawItem                                         0x7B8800
#define CListWnd__DrawLine                                         0x7B8EF0
#define CListWnd__DrawSeparator                                    0x7B92D0
#define CListWnd__EnsureVisible                                    0x7B74C0
#define CListWnd__ExtendSel                                        0x7B8720
#define CListWnd__GetColumnMinWidth                                0x7B6580
#define CListWnd__GetColumnWidth                                   0x7B64C0
#define CListWnd__GetCurSel                                        0x7B5C50
#define CListWnd__GetHeaderRect                                    0x7B5DB0
#define CListWnd__GetItemAtPoint                                   0x7B7790
#define CListWnd__GetItemAtPoint1                                  0x7B7800
#define CListWnd__GetItemData                                      0x7B60C0
#define CListWnd__GetItemHeight                                    0x7B6FD0
#define CListWnd__GetItemIcon                                      0x7B62A0
#define CListWnd__GetItemRect                                      0x7B7590
#define CListWnd__GetItemText                                      0x7B6150
#define CListWnd__GetSelList                                       0x7BB420
#define CListWnd__GetSeparatorRect                                 0x7B7D50
#define CListWnd__RemoveLine                                       0x7BBEC0
#define CListWnd__SetColors                                        0x7B5D20
#define CListWnd__SetColumnJustification                           0x7B6720
#define CListWnd__SetColumnWidth                                   0x7B6540
#define CListWnd__SetCurSel                                        0x7B5C90
#define CListWnd__SetItemColor                                     0x7BA410
#define CListWnd__SetItemData                                      0x7B6950
#define CListWnd__SetItemText                                      0x7BA240
#define CListWnd__ShiftColumnSeparator                             0x7BA0B0
#define CListWnd__Sort                                             0x7BC670
#define CListWnd__ToggleSel                                        0x7B6820

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x673EF0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x68F2B0
#define CMerchantWnd__RequestBuyItem                               0x6954A0
#define CMerchantWnd__RequestSellItem                              0x6B6B20
#define CMerchantWnd__SelectBuySellSlot                            0x68F560

// CObfuscator
#define CObfuscator__doit                                          0x73D6A0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x7D8450
#define CSidlManager__CreateLabel                                  0x6EA5C0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5DB1C0
#define CSidlScreenWnd__CalculateVSBRange                          0x5DB0E0
#define CSidlScreenWnd__ConvertToRes                               0x7E6B50
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x7C8990
#define CSidlScreenWnd__CSidlScreenWnd1                            0x7C9BD0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x7C9C80
#define CSidlScreenWnd__dCSidlScreenWnd                            0x7C9360
#define CSidlScreenWnd__DrawSidlPiece                              0x7C8430
#define CSidlScreenWnd__EnableIniStorage                           0x7C7BF0
#define CSidlScreenWnd__GetSidlPiece                               0x7C8650
#define CSidlScreenWnd__Init1                                      0x7C9A20
#define CSidlScreenWnd__LoadIniInfo                                0x7C8A50
#define CSidlScreenWnd__LoadIniListWnd                             0x7C7D40
#define CSidlScreenWnd__LoadSidlScreen                             0x7C95C0
#define CSidlScreenWnd__StoreIniInfo                               0x7C77C0
#define CSidlScreenWnd__StoreIniVis                                0x7C7B80
#define CSidlScreenWnd__WndNotification                            0x7C9810
#define CSidlScreenWnd__GetChildItem                               0x7C7C50

// CSkillMgr
#define CSkillMgr__IsAvailable                                     0x582820
#define CSkillMgr__GetSkillCap                                     0x582890

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x7EEDA0
#define CSliderWnd__SetValue                                       0x7EEEA0
#define CSliderWnd__SetNumTicks                                    0x7EF450

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x6EFB50

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x7E4090
#define CStmlWnd__CalculateHSBRange                                0x7DB650
#define CStmlWnd__CalculateVSBRange                                0x7DB6E0
#define CStmlWnd__CanBreakAtCharacter                              0x7DB860
#define CStmlWnd__FastForwardToEndOfTag                            0x7DC540
#define CStmlWnd__ForceParseNow                                    0x7E4680
#define CStmlWnd__GetNextTagPiece                                  0x7DC460
#define CStmlWnd__GetSTMLText                                      0x607500
#define CStmlWnd__GetThisChar                                      0x80F870
#define CStmlWnd__GetVisiableText                                  0x7DD9A0
#define CStmlWnd__InitializeWindowVariables                        0x7DFF90
#define CStmlWnd__MakeStmlColorTag                                 0x7DA570
#define CStmlWnd__MakeWndNotificationTag                           0x7DA610
#define CStmlWnd__SetSTMLText                                      0x7E00C0
#define CStmlWnd__StripFirstSTMLLines                              0x7E3D30
#define CStmlWnd__UpdateHistoryString                              0x7DE240

// CTabWnd 
#define CTabWnd__Draw                                              0x7EA8D0
#define CTabWnd__DrawCurrentPage                                   0x7EA150
#define CTabWnd__DrawTab                                           0x7E9F20
#define CTabWnd__GetCurrentPage                                    0x7EA510
#define CTabWnd__GetPageClientRect                                 0x7E9BD0
#define CTabWnd__GetPageFromTabIndex                               0x7E9E50
#define CTabWnd__GetPageInnerRect                                  0x7E9C30
#define CTabWnd__GetTabInnerRect                                   0x7E9DD0
#define CTabWnd__GetTabRect                                        0x7E9CC0
#define CTabWnd__InsertPage                                        0x7EAB60
#define CTabWnd__SetPage                                           0x7EA550
#define CTabWnd__SetPageRect                                       0x7EA800
#define CTabWnd__UpdatePage                                        0x7EAAE0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x419470

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x7CA000

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x7E7D80

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x7B4B10

// CXRect 
#define CXRect__CenterPoint                                        0x5241C0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x52F910
#define CXStr__CXStr1                                              0x401430
#define CXStr__CXStr3                                              0x813E90
#define CXStr__dCXStr                                              0x401020
#define CXStr__operator_equal                                      0x814000
#define CXStr__operator_equal1                                     0x814050
#define CXStr__operator_plus_equal1                                0x815160

// CXWnd 
#define CXWnd__BringToTop                                          0x7BF310
#define CXWnd__Center                                              0x7C4CC0
#define CXWnd__ClrFocus                                            0x7BF150
#define CXWnd__DoAllDrawing                                        0x7C4B50
#define CXWnd__DrawChildren                                        0x7C4C90
#define CXWnd__DrawColoredRect                                     0x7BF630
#define CXWnd__DrawTooltip                                         0x7BF820
#define CXWnd__DrawTooltipAtPoint                                  0x7C3DC0
#define CXWnd__GetBorderFrame                                      0x7BFC40
#define CXWnd__GetChildWndAt                                       0x7C2FB0
#define CXWnd__GetClientClipRect                                   0x7BF9C0
#define CXWnd__GetScreenClipRect                                   0x7C42F0
#define CXWnd__GetScreenRect                                       0x7BFD70
#define CXWnd__GetTooltipRect                                      0x7BF740
#define CXWnd__GetWindowTextA                                      0x523D40
#define CXWnd__IsActive                                            0x7CB140
#define CXWnd__IsDescendantOf                                      0x7BFB30
#define CXWnd__IsReallyVisible                                     0x7C2F90
#define CXWnd__IsType                                              0x7EC1F0
#define CXWnd__Move                                                0x7C2700
#define CXWnd__Move1                                               0x7C4820
#define CXWnd__ProcessTransition                                   0x7BF2C0
#define CXWnd__Refade                                              0x7BF250
#define CXWnd__Resize                                              0x7BFE40
#define CXWnd__Right                                               0x7C4200
#define CXWnd__SetFocus                                            0x7C1870
#define CXWnd__SetKeyTooltip                                       0x7C0090
#define CXWnd__SetMouseOver                                        0x7C4610
#define CXWnd__StartFade                                           0x7BF350
#define CXWnd__GetChildItem                                        0x7C4550

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x7CC6A0
#define CXWndManager__DrawWindows                                  0x7CC320
#define CXWndManager__GetKeyboardFlags                             0x7CAD90
#define CXWndManager__HandleKeyboardMsg                            0x7CB410
#define CXWndManager__RemoveWnd                                    0x7CB260

// CDBStr
#define CDBStr__GetString                                          0x471490

// EQ_Character 
#define EQ_Character__CastRay                                      0x757200
#define EQ_Character__CastSpell                                    0x433370
#define EQ_Character__Cur_HP                                       0x43CCE0
#define EQ_Character__GetAACastingTimeModifier                     0x427F20
#define EQ_Character__GetCharInfo2                                 0x755600
#define EQ_Character__GetFocusCastingTimeModifier                  0x422C50
#define EQ_Character__GetFocusRangeModifier                        0x422E20
#define EQ_Character__Max_Endurance                                0x54FEA0
#define EQ_Character__Max_HP                                       0x437390
#define EQ_Character__Max_Mana                                     0x54FCA0
#define EQ_Character__doCombatAbility                              0x54EA90
#define EQ_Character__UseSkill                                     0x44CA00
#define EQ_Character__GetConLevel                                  0x547F90
#define EQ_Character__IsExpansionFlag                              0x40DC50
#define EQ_Character__TotalEffect                                  0x42C7D0

// EQ_Item 
#define EQ_Item__CanDrop                                           0x5297C0
#define EQ_Item__CreateItemTagString                               0x73B7C0
#define EQ_Item__IsStackable                                       0x730060

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x48B170
#define EQ_LoadingS__Array                                         0x9C78D0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x553770
#define EQ_PC__GetAltAbilityIndex                                  0x746B00
#define EQ_PC__GetCombatAbility                                    0x746B90
#define EQ_PC__GetCombatAbilityTimer                               0x746C40
#define EQ_PC__GetItemTimerValue                                   0x54E800
#define EQ_PC__HasLoreItem                                         0x54D2E0

// EQItemList 
#define EQItemList__EQItemList                                     0x4BB4F0
#define EQItemList__add_item                                       0x4BB480
#define EQItemList__delete_item                                    0x4BB8A0
#define EQItemList__FreeItemList                                   0x4BB7D0

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x470A40

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x558880
#define EQPlayer__dEQPlayer                                        0x55D520
#define EQPlayer__DoAttack                                         0x56EC50
#define EQPlayer__EQPlayer                                         0x562FB0
#define EQPlayer__SetNameSpriteState                               0x55AD50
#define EQPlayer__SetNameSpriteTint                                0x5588F0
#define EQPlayer__IsBodyType_j                                     0x756AA0
#define EQPlayer__IsTargetable                                     0x756D70

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x564370
#define EQPlayerManager__GetSpawnByName                            0x564600

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x52F280
#define KeypressHandler__AttachKeyToEqCommand                      0x52F2C0
#define KeypressHandler__ClearCommandStateArray                    0x52F090
#define KeypressHandler__HandleKeyDown                             0x52DA30
#define KeypressHandler__HandleKeyUp                               0x52DD40
#define KeypressHandler__SaveKeymapping                            0x52F160

// MapViewMap 
#define MapViewMap__Clear                                          0x66D140
#define MapViewMap__SaveEx                                         0x6707F0

#define PlayerPointManager__GetAltCurrency                         0x7410C0

// StringTable 
#define StringTable__getString                                     0x73D920

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit                              0x552030
