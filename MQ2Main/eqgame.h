/*****************************************************************************
    MQ2Main.dll: MacroQuest2's extension DLL for EverQuest
    Copyright (C) 2002-2003 Plazmic, 2003-2004 Lax

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


#define __ClientName                                  "eqgame"
//.rdata:005DF29C aApr262004      db 'Apr 26 2004',0
//.rdata:005DF2A8 a175716         db '17:57:16',0
#define __ExpectedVersionDate                         "Apr 26 2004"
#define __ExpectedVersionTime                         "17:57:16"
#define __ActualVersionDate                                0x5DF29C
#define __ActualVersionTime                                0x5DF2A8

#define __ClientOverride                       0
#define __MacroQuestWinClassName                 "__MacroQuestTray"
#define __MacroQuestWinName                           "MacroQuest"

// Memory Protection
#define __MemChecker0                                      0x4BFF92
#define __MemChecker1                                      0x4C4AB1
#define __MemChecker2                                      0x4C688D
#define __MemChecker3                                      0x4C692A
#define __EncryptPad0                                      0x616960
#define __EncryptPad1                                      0x616D60
#define __EncryptPad2                                      0x617820
#define __EncryptPad3                                      0x617C20

#define DI8__Main                                          0x79A904
#define DI8__Keyboard                                      0x79A908
#define DI8__Mouse                                         0x79A90C

#define __LastTell                                         0x6DC884
#define __Guilds                                           0x73CF40
#define __Mouse                                            0x79A910
#define __Attack                                           0x73B0B8
#define __InChatMode                                       0x6DA7C8
#define __gWorld                                           0x73CE98
#define __GroupCount                                       0x73B448
#define __CommandList                                      0x610810
#define __DoAbilityList                                    0x714358
#define __DoAbilityAvailable                               0x6DB5A8
#define __ServerHost                                       0x73B304
#define __ServerName                                       0x714318
#define __HWnd                                             0x6DA788
#define __Clicks                                           0x6DA888
#define __ScreenX                                          0x6DA790
#define __ScreenY                                          0x6DA794
#define __EQP_IDArray                                      0x6D7860
#define __CurrentMapLabel                                  0x7A3798
#define __BindList                                         0x6102F0
#define __RangeAttackReady                                 0x6DB60C
#define __AltTimerReady                                    0x6DB60E
#define __Socials                                          0x714418
#define __HotkeyPage                                       0x73ACB8
#define __CurrentSocial                                    0x60CB58
#define __GroupLeader                                      0x73B5A4
#define __SkillDict                                        0x627D00
#define __DrawHandler                                      0x7AF454
#define __FriendsList                                      0x711118
#define __IgnoreList                                       0x712A18
////
//Section 1: Vital Offsets
////
#define pinstCSidlManager                                  0x7AEB84
#define pinstCDisplay                                      0x73CF24
#define pinstCEverQuest                                    0x79AA78
#define pinstPCData                                        0x73CF00
#define pinstCharData                                      0x73CF00
#define pinstCharSpawn                                     0x73CEF8
#define pinstSpawnList                                     0x73CEC0
#define pinstLocalPlayer                                   0x73CEE4
#define pinstControlledPlayer                              0x73CEF8
#define pinstWorldData                                     0x73CEBC
#define pinstSpellManager                                  0x7974CC
#define pinstTradeTarget                                   0x73CEE0
#define pinstActiveMerchant                                0x73CF10
#define pinstActiveBanker                                  0x73CF14
#define pinstActiveCorpse                                  0x73CF18
#define pinstActiveGMaster                                 0x73CF1C
#define pinstSelectedItem                                  0x7A36A0
#define pinstGroup                                         0x73B590
#define pinstTarget                                        0x73CF04
#define pinstSwitchManager                                 0x6DA77C
#define pinstEQItemList                                    0x73CEC4
#define pinstSpellSets                                     0x73ACBC
#define instEQZoneInfo                                     0x6DA9F4
#define pinstCXWndManager                                  0x7AEB7C
#define instKeypressHandler                                0x789D00
#define pinstStringTable                                   0x73CEB0
#define pinstAltAdvManager                                 0x627918

////
//Section 2:  UI Related Offsets
////
#define pinstCTextOverlay                                  0x6201A0
#define pinstCharacterSelect                               0x6272FC
#define pinstCFacePick                                     0x627300
// removed 4-14 exe #define pinstCTextMessageWnd                               
#define pinstCNoteWnd                                      0x627304
#define pinstCHelpWnd                                      0x627308
#define pinstCBookWnd                                      0x62730C
#define pinstCPetInfoWnd                                   0x627310
#define pinstCTrainWnd                                     0x627314
#define pinstCSkillsWnd                                    0x627318
#define pinstCSkillsSelectWnd                              0x62731C
#define pinstCCombatSkillSelectWnd                         0x627320
#define pinstCFriendsWnd                                   0x627324
#define pinstCAAWnd                                        0x627328
#define pinstCGroupSearchFiltersWnd                        0x62732C
#define pinstCLoadskinWnd                                  0x627330
#define pinstCAlarmWnd                                     0x627334
#define pinstCMusicPlayerWnd                               0x627338
#define pinstCRaidWnd                                      0x62733C
#define pinstCRaidOptionsWnd                               0x627340
#define pinstCBreathWnd                                    0x627344
#define pinstCMapViewWnd                                   0x627348
#define pinstCMapToolbarWnd                                0x62734C
#define pinstCEditLabelWnd                                 0x627350
#define pinstCTargetWnd                                    0x627354
#define pinstCHotButtonWnd                                 0x627358
#define pinstCColorPickerWnd                               0x62735C
#define pinstCPlayerWnd                                    0x627360
#define pinstCOptionsWnd                                   0x627364
#define pinstCBuffWindowNORMAL                             0x627368
#define pinstCBuffWindowSHORT                              0x62736C
#define pinstCharacterCreation                             0x627370
#define pinstCCursorAttachment                             0x627374
#define pinstCCastingWnd                                   0x627378
#define pinstCCastSpellWnd                                 0x62737C
#define pinstCSpellBookWnd                                 0x627380
#define pinstCInventoryWnd                                 0x627384
#define pinstCBankWnd                                      0x627388
#define pinstCQuantityWnd                                  0x62738C
#define pinstCLootWnd                                      0x627390
#define pinstCActionsWnd                                   0x627394
#define pinstCCombatAbilityWnd                             0x627398
#define pinstCMerchantWnd                                  0x62739C
#define pinstCTradeWnd                                     0x6273A0
#define pinstCSelectorWnd                                  0x6273A4
#define pinstCBazaarWnd                                    0x6273A8
#define pinstCBazaarSearchWnd                              0x6273AC
#define pinstCGiveWnd                                      0x6273B0
#define pinstCTrackingWnd                                  0x6273B4
#define pinstCInspectWnd                                   0x6273B8
#define pinstCSocialEditWnd                                0x6273BC
#define pinstCFeedbackWnd                                  0x6273C0
#define pinstCBugReportWnd                                 0x6273C4
#define pinstCVideoModesWnd                                0x6273C8
#define pinstCTextEntryWnd                                 0x6273CC
#define pinstCFileSelectionWnd                             0x6273D0
#define pinstCCompassWnd                                   0x6273D4
#define pinstCPlayerNotesWnd                               0x6273D8
#define pinstCGemsGameWnd                                  0x6273DC
#define pinstCTimeLeftWnd                                  0x6273E0
#define pinstCPetitionQWnd                                 0x6273E4
#define pinstCSoulmarkWnd                                  0x6273E8
#define pinstCStoryWnd                                     0x6273EC
#define pinstCJournalTextWnd                               0x6273F0
#define pinstCJournalCatWnd                                0x6273F4
#define pinstCBodyTintWnd                                  0x6273F8
#define pinstCInvSlotMgr                                   0x6273FC
#define pinstCContainerMgr                                 0x627400
#define pinstCAdventureLeaderboardWnd                      0x7A3158
#define pinstCAdventureMerchantWnd                         0x7A3170
#define pinstCAdventureRequestWnd                          0x7A3188
#define pinstCAdventureStatsWnd                            0x7A31A0
#define pinstCChatManager                                  0x7A3430
#define pinstCDynamicZoneWnd                               0x7A34E8
#define pinstCFindLocationWnd                              0x7A3578
#define pinstCGroupSearchWnd                               0x7A35F4
#define pinstCGroupWnd                                     0x7A360C
#define pinstCGuildMgmtWnd                                 0x7A3624
#define pinstCItemDisplayManager                           0x7A36CC
#define pinstCLeadershipWnd                                0x7A3734
#define pinstCPopupWndManager                              0x7A3884
#define pinstCSystemInfoDialogBox                          0x7A4164
#define pinstCTargetOfTargetWnd                            0x7A417C
#define pinstCTipWndOFDAY                                  0x7A41E8
#define pinstCTipWndCONTEXT                                0x7A41EC
#define pinstCTradeskillWnd                                0x7A4218
#define pinstCTributeBenefitWnd                            0x7A4258
#define pinstCTributeMasterWnd                             0x7A4270
#define pinstCContextMenuManager                           0x7AEBA0
// unknown window added 4-14 exe 0x79A234


////
// Section 3: Miscellaneous Offsets
////
#define DrawNetStatus                                      0x4B4AF5
#define CrashDetected                                      0x4C658B
#define __ProcessGameEvents                                0x4AB527
#define __ConvertItemTags                                  0x45A451
#define __SendMessage                                      0x4BA760
#define __NewUIINI                                         0x52545E
#define __ExecuteCmd                                       0x44D2E6
#define __GetGaugeValueFromEQ                              0x523CC3
#define __get_melee_range                                  0x451DF6

// EQ_LoadingS
#define EQ_LoadingS__WriteTextHD                           0x432217


////
// Section 4: Function Offsets
////
// CEverQuest
#define CEverQuest__dsp_chat                               0x49B4AE
#define CEverQuest__ClickedPlayer                          0x4987EC
#define CEverQuest__EnterZone                              0x49C1D9
#define CEverQuest__GetBodyTypeDesc                        0x4925EF
#define CEverQuest__GetClassDesc                           0x492071
#define CEverQuest__GetClassThreeLetterCode                0x49248C
#define CEverQuest__GetDeityDesc                           0x494082
#define CEverQuest__GetRaceDesc                            0x4928F4
#define CEverQuest__InterpretCmd                           0x4A7F54
#define CEverQuest__LeftClickedOnPlayer                    0x4AA12B
#define CEverQuest__RightClickedOnPlayer                   0x4A2D46
#define CEverQuest__SetGameState                           0x498953
#define CEverQuest__DropHeldItemOnGround                   0x49AF6F

// StringTable
#define StringTable__getString                             0x4BD8E1

// AltAdvManager
#define AltAdvManager__IsAbilityReady                      0x41D090

// CXWndManager
#define CXWndManager__RemoveWnd                            0x572950
#define CXWndManager__GetKeyboardFlags                     0x572570
#define CXWndManager__HandleKeyboardMsg                    0x572A40

// KeyPressHandler
#define KeypressHandler__HandleKeyDown                     0x4AFEB0
#define KeypressHandler__HandleKeyUp                       0x4B0153
#define KeypressHandler__AttachKeyToEqCommand              0x4B1532
#define KeypressHandler__AttachAltKeyToEqCommand           0x4B156F
#define KeypressHandler__SaveKeymapping                    0x4B141A
#define KeypressHandler__ClearCommandStateArray            0x4B0143

// EQ_Character
#define EQ_Character__Max_Endurance                        0x41D235
#define EQ_Character__Max_Mana                             0x420BBC
#define EQ_Character__Max_HP                               0x420A07
#define EQ_Character__Cur_HP                               0x422588
#define EQ_Character__GetFocusCastingTimeModifier          0x42854C
#define EQ_Character__GetAACastingTimeModifier             0x4288E5
#define EQ_Character__CastSpell                            0x42C42C
#define EQ_Character__GetAbility                           0x42046F

// EQPlayer
#define EQPlayer__EQPlayer                                 0x487609
#define EQPlayer__dEQPlayer                                0x486EC6
#define EQPlayer__DoAttack                                 0x4835DA

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr                                       0x4010C0
#define CXStr__CXStr1                                      0x510514
#define CXStr__CXStr3                                      0x5A18D0
#define CXStr__dCXStr                                      0x4010EA
#define CXStr__operator_plus_equal1                        0x5A2960
#define CXStr__operator_equal1                             0x5A1A90

// CChatWindow
#define CChatWindow__CChatWindow                           0x4E2C01

// CChatManager
#define CChatManager__GetRGBAFromIndex                     0x4DF7C5
#define CChatManager__InitContextMenu                      0x4E0129

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot                           0x4FD08E
#define CInvSlotMgr__MoveItem                              0x4FCA3D

// CItemDisplayWnd
#define CItemDisplayWnd__SetItem                           0x4FFF77
#define CItemDisplayWnd__SetSpell                          0x4FF461

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton                         0x4F9ACF

// CLabel
#define CLabel__Draw                                       0x506082

// CGauge
#define CGaugeWnd__Draw                                    0x4EE809

// CDisplay
#define CDisplay__ReloadUI                                 0x4171E6
#define CDisplay__CleanGameUI                              0x4100EC
#define CDisplay__GetClickedActor                          0x40D3EE
#define CDisplay__WriteTextHD2                             0x410B80
#define CDisplay__GetWorldFilePath                         0x40BFF0

// EQ_Item
#define EQ_Item__GetItemLinkHash                           0x431D0E
#define EQ_Item__CanDrop                                   0x431E06

// CBankWnd
#define CBankWnd__GetNumBankSlots                          0x4D153E

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg                  0x4D3BF3

// CMerchantWnd
#define CMerchantWnd__SelectBuySellSlot                    0x50EE7B
#define CMerchantWnd__RequestBuyItem                       0x50E06D
#define CMerchantWnd__RequestSellItem                      0x50E3EB
#define CMerchantWnd__DisplayBuyOrSellPrice                0x50DEA2

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet                         0x5226C2

// MapViewMap
#define MapViewMap__SaveEx                                 0x50969E
#define MapViewMap__Clear                                  0x50952D


// CMapViewWnd
#define CMapViewWnd__CMapViewWnd                           0x50CF63

// EQItemList
#define EQItemList__EQItemList                             0x44FB95
#define EQItemList__dEQItemList                            0x44FC11

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney                      0x434D54

// CContainerWnd
#define CContainerWnd__HandleCombine                       0x4E6E3A
#define CContainerWnd__vftable                             0x5E35B8

// CSidlScreenWnd
#define CSidlScreenWnd__CSidlScreenWnd1                    0x5567E0
#define CSidlScreenWnd__dCSidlScreenWnd                    0x555E80
#define CSidlScreenWnd__CreateChildrenFromSidl             0x555200
#define CSidlScreenWnd__GetChildItem                       0x554B10
#define CSidlScreenWnd__WndNotification                    0x554D80
#define CSidlScreenWnd__CalculateHSBRange                  0x5543A0
#define CSidlScreenWnd__CalculateVSBRange                  0x5542E0
#define CSidlScreenWnd__ConvertToRes                       0x554A90
#define CSidlScreenWnd__CSidlScreenWnd2                    0x5568D0
#define CSidlScreenWnd__DrawSidlPiece                      0x554E20
#define CSidlScreenWnd__EnableIniStorage                   0x554A40
#define CSidlScreenWnd__GetSidlPiece                       0x5550C0
#define CSidlScreenWnd__Init1                              0x556530
#define CSidlScreenWnd__LoadIniInfo                        0x5552B0
#define CSidlScreenWnd__LoadIniListWnd                     0x555BE0
#define CSidlScreenWnd__LoadSidlScreen                     0x554C60
#define CSidlScreenWnd__SetScreen                          0x555FA0
#define CSidlScreenWnd__StoreIniInfo                       0x5545D0
#define CSidlScreenWnd__StoreIniListWnd                    0x555C90

// CSidlManager
#define CSidlManager__FindScreenPieceTemplate1             0x57AF80

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead                       0x5626B0

// CXRect
#define CXRect__CenterPoint                                0x4D1545

// CXWnd
#define CXWnd__Bottom                                      0x55A7A0
#define CXWnd__BringToTop                                  0x556F60
#define CXWnd__Center                                      0x55A560
#define CXWnd__ClrFocus                                    0x556CB0
#define CXWnd__DoAllDrawing                                0x55B170
#define CXWnd__DrawChildren                                0x55B2A0
#define CXWnd__DrawColoredRect                             0x557190
#define CXWnd__DrawTooltipAtPoint                          0x55A390
#define CXWnd__GetBorderFrame                              0x5575C0
#define CXWnd__GetChildWndAt                               0x559F70
#define CXWnd__GetClientClipRect                           0x557510
#define CXWnd__GetFirstChildWnd                            0x556FF0
#define CXWnd__GetNextChildWnd                             0x559F50
#define CXWnd__GetNextSib                                  0x557010
#define CXWnd__GetScreenClipRect                           0x55A7F0
#define CXWnd__GetScreenRect                               0x557790
#define CXWnd__GetTooltipRect                              0x55A2E0
#define CXWnd__GetWindowTextA                              0x4CBFF8
#define CXWnd__GetXMLTooltip                               0x556AF0
#define CXWnd__IsActive                                    0x557580
#define CXWnd__IsDescendantOf                              0x557590
#define CXWnd__IsReallyVisible                             0x559F30
#define CXWnd__IsType                                      0x55B110
#define CXWnd__Left                                        0x55A620
#define CXWnd__Move                                        0x559AE0
#define CXWnd__Move1                                       0x559B70
#define CXWnd__ProcessTransition                           0x556F20
#define CXWnd__Refade                                      0x556D50
#define CXWnd__Resize                                      0x55A930
#define CXWnd__Right                                       0x55A6D0
#define CXWnd__SetFirstChildPointer                        0x5579E0
#define CXWnd__SetFocus                                    0x558CC0
#define CXWnd__SetKeyTooltip                               0x557A20
#define CXWnd__SetMouseOver                                0x557A00
#define CXWnd__SetNextSibPointer                           0x5579F0
#define CXWnd__StartFade                                   0x556F80

// CSliderWnd
#define CSliderWnd__GetValue                               0x586800
#define CSliderWnd__SetValue                               0x5869E0
#define CSliderWnd__UpdateThumb                            0x5867C0

// CEditBaseWnd
#define CEditBaseWnd__SetMaxChars                          0x4D10B4
#define CEditBaseWnd__SetSel                               0x57CF10

// CComboWnd
#define CComboWnd__DeleteAll                               0x581F20
#define CComboWnd__Draw                                    0x582120
#define CComboWnd__GetButtonRect                           0x581F50
#define CComboWnd__GetCurChoice                            0x581EE0
#define CComboWnd__GetListRect                             0x582510
#define CComboWnd__GetTextRect                             0x581FB0
#define CComboWnd__InsertChoice                            0x582570
#define CComboWnd__SetColors                               0x581EB0
#define CComboWnd__SetChoice                               0x582650

// CListWnd
#define CListWnd__AddColumn                                0x571260
#define CListWnd__AddColumn1                               0x570DC0
#define CListWnd__AddLine                                  0x570980
#define CListWnd__AddString                                0x570B00
#define CListWnd__CalculateFirstVisibleLine                0x56DFB0
#define CListWnd__CalculateLineHeights                     0x56DF50
#define CListWnd__CalculateVSBRange                        0x56FB20
#define CListWnd__ClearAllSel                              0x56D7E0
#define CListWnd__CloseAndUpdateEditWindow                 0x56E5B0
#define CListWnd__Compare                                  0x56E8F0
#define CListWnd__Draw                                     0x56F780
#define CListWnd__DrawColumnSeparators                     0x56F5E0
#define CListWnd__DrawHeader                               0x56DA00
#define CListWnd__DrawItem                                 0x56F000
#define CListWnd__DrawLine                                 0x56F350
#define CListWnd__DrawSeparator                            0x56F6B0
#define CListWnd__EnsureVisible                            0x56E000
#define CListWnd__ExtendSel                                0x56EF30
#define CListWnd__GetColumnFlags                           0x56D2B0
#define CListWnd__GetColumnJustification                   0x56D450
#define CListWnd__GetColumnMinWidth                        0x56D3E0
#define CListWnd__GetColumnWidth                           0x56D310
#define CListWnd__GetCurSel                                0x56D0F0
#define CListWnd__GetHeaderRect                            0x56CF30
#define CListWnd__GetItemAtPoint                           0x56E2B0
#define CListWnd__GetItemAtPoint1                          0x56E320
#define CListWnd__GetItemData                              0x56D130
#define CListWnd__GetItemHeight                            0x56DDE0
#define CListWnd__GetItemIcon                              0x56D1F0
#define CListWnd__GetItemRect                              0x56E0D0
#define CListWnd__GetItemText                              0x56D170
#define CListWnd__GetSelList                               0x570CA0
#define CListWnd__GetSeparatorRect                         0x56E840
#define CListWnd__IsLineEnabled                            0x56D8D0
#define CListWnd__RemoveLine                               0x570C50
#define CListWnd__SetColors                                0x56CEA0
#define CListWnd__SetColumnWidth                           0x56D390
#define CListWnd__SetColumnJustification                   0x56D4B0
#define CListWnd__SetCurSel                                0x56D700
#define CListWnd__SetItemColor                             0x5705C0
#define CListWnd__SetItemData                              0x56D890
#define CListWnd__SetItemText                              0x570500
#define CListWnd__ShiftColumnSeparator                     0x56EEA0
#define CListWnd__Sort                                     0x571300
#define CListWnd__ToggleSel                                0x56D720

// CEditWnd
#define CEditWnd__DrawCaret                                0x5829B0
#define CEditWnd__DrawMultiline                            0x583EC0
#define CEditWnd__GetCaretPt                               0x584270
#define CEditWnd__GetCharIndexPt                           0x5837C0
#define CEditWnd__GetDisplayString                         0x582AE0
#define CEditWnd__GetHorzOffset                            0x582D50
#define CEditWnd__GetLineForPrintableChar                  0x583270
#define CEditWnd__GetSelEndPt                              0x583A00
#define CEditWnd__GetSelStartPt                            0x5839E0
#define CEditWnd__GetSTMLSafeText                          0x582F30
#define CEditWnd__PointFromPrintableChar                   0x583380
#define CEditWnd__SelectableCharFromPoint                  0x583500
#define CEditWnd__SetEditable                              0x582F00

// CGaugeWnd
#define CGaugeWnd__CalcFillRect                            0x4EE4AD
#define CGaugeWnd__CalcLinesFillRect                       0x4EE509
#define CGaugeWnd__Draw                                    0x4EE809

// CStmlWnd
#define CStmlWnd__AppendSTML                               0x56C3B0
#define CStmlWnd__CalculateHSBRange                        0x563DD0
#define CStmlWnd__CalculateVSBRange                        0x563D70
#define CStmlWnd__CanBreakAtCharacter                      0x563F10
#define CStmlWnd__CanGoBackward                            0x563F90
#define CStmlWnd__FastForwardPastSpaces                    0x564950
#define CStmlWnd__FastForwardToEndOfTag                    0x564CB0
#define CStmlWnd__GetNextChar                              0x5643D0
#define CStmlWnd__GetNextTagPiece                          0x564AC0
#define CStmlWnd__GetSTMLText                              0x4E2BE3
#define CStmlWnd__GetThisChar                              0x563C30
#define CStmlWnd__GetVisiableText                          0x566480
#define CStmlWnd__InitializeTempVariables                  0x563BE0
#define CStmlWnd__InitializeWindowVariables                0x568280
#define CStmlWnd__MakeStmlColorTag                         0x5633C0
#define CStmlWnd__MakeWndNotificationTag                   0x563460
#define CStmlWnd__StripFirstSTMLLines                      0x56C130
#define CStmlWnd__UpdateHistoryString                      0x5668C0

// CTabWnd
#define CTabWnd__Draw                                      0x581C00
#define CTabWnd__DrawCurrentPage                           0x5816F0
#define CTabWnd__DrawTab                                   0x581470
#define CTabWnd__GetCurrentPage                            0x581020
#define CTabWnd__GetCurrentTabIndex                        0x580D50
#define CTabWnd__GetNumTabs                                0x580E70
#define CTabWnd__GetPageClientRect                         0x580D60
#define CTabWnd__GetPageFromTabIndex                       0x580EA0
#define CTabWnd__GetPageInnerRect                          0x580DC0
#define CTabWnd__GetTabInnerRect                           0x581130
#define CTabWnd__GetTabRect                                0x581030
#define CTabWnd__IndexInBounds                             0x580E80
#define CTabWnd__InsertPage                                0x581AF0
#define CTabWnd__SetPage                                   0x5811D0
#define CTabWnd__SetPageRect                               0x5812E0
#define CTabWnd__UpdatePage                                0x581390

// CTextOverlay
#define CTextOverlay__DisplayText                          0x401406
