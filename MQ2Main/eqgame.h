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
//.rdata:005DD164 aApr132004      db 'Apr 13 2004',0
//.rdata:005DD170 a101257         db '10:12:57',0
#define __ExpectedVersionDate                         "Apr 13 2004"
#define __ExpectedVersionTime                         "10:12:57"
#define __ActualVersionDate                                0x5DD164
#define __ActualVersionTime                                0x5DD170

#define __ClientOverride                       0
#define __MacroQuestWinClassName                 "__MacroQuestTray"
#define __MacroQuestWinName                           "MacroQuest"

// Memory Protection
#define __MemChecker0                                      0x4BF80F
#define __MemChecker1                                      0x4C4199
#define __MemChecker2                                      0x4C5F70
#define __MemChecker3                                      0x4C600D
#define __EncryptPad0                                      0x6138B0
#define __EncryptPad1                                      0x613CB0
#define __EncryptPad2                                      0x614770
#define __EncryptPad3                                      0x614B70 

#define DI8__Main                                          0x79124C
#define DI8__Keyboard                                      0x791250
#define DI8__Mouse                                         0x791254

#define __LastTell                                         0x6D31D8
#define __Guilds                                           0x733890
#define __Mouse                                            0x791258
#define __Attack                                           0x731A0A
#define __InChatMode                                       0x6D1120
#define __gWorld                                           0x7337E8
#define __GroupCount                                       0x731D98
#define __CommandList                                      0x60D768
#define __DoAbilityList                                    0x70ACAC
#define __DoAbilityAvailable                               0x6D1F00
#define __ServerHost                                       0x731C54
#define __ServerName                                       0x70AC6C
#define __HWnd                                             0x6D10E0
#define __Clicks                                           0x6D11E0
#define __ScreenX                                          0x6D10E8
#define __ScreenY                                          0x6D10EC
#define __EQP_IDArray                                      0x6CE1A8
#define __CurrentMapLabel                                  0x79A0E0
#define __BindList                                         0x60D248
#define __RangeAttackReady                                 0x6D1F64
#define __Socials                                          0x70AD6C
#define __HotkeyPage                                       0x73160C
#define __CurrentSocial                                    0x609AAC
////
//Section 1: Vital Offsets
////
#define pinstCSidlManager                                  0x7A5464
#define pinstCDisplay                                      0x733874
#define pinstCEverQuest                                    0x7913C0
#define pinstPCData                                        0x733850
#define pinstCharData                                      0x733850
#define pinstCharSpawn                                     0x733848
#define pinstSpawnList                                     0x733810
#define pinstLocalPlayer                                   0x733834
#define pinstControlledPlayer                              0x733848
#define pinstWorldData                                     0x73380C
#define pinstSpellManager                                  0x78DE14
#define pinstTradeTarget                                   0x733830
#define pinstActiveMerchant                                0x733860
#define pinstActiveBanker                                  0x733864
#define pinstActiveCorpse                                  0x733868
#define pinstActiveGMaster                                 0x73386C
#define pinstSelectedItem                                  0x799FE8
#define pinstGroup                                         0x731EE0
#define pinstTarget                                        0x733854
#define pinstSwitchManager                                 0x6D10D0
#define pinstEQItemList                                    0x733814
#define pinstSpellSets                                     0x731610
#define instEQZoneInfo                                     0x6D134C
#define pinstCXWndManager                                  0x7A545C
#define instKeypressHandler                                0x780650


////
//Section 2:  UI Related Offsets
////
#define pinstCTextOverlay                                  0x61CFE0
#define pinstCharacterSelect                               0x61DC44
#define pinstCFacePick                                     0x61DC48
// removed 4-14 exe #define pinstCTextMessageWnd                               
#define pinstCNoteWnd                                      0x61DC4C
#define pinstCHelpWnd                                      0x61DC50
#define pinstCBookWnd                                      0x61DC54
#define pinstCPetInfoWnd                                   0x61DC58
#define pinstCTrainWnd                                     0x61DC5C
#define pinstCSkillsWnd                                    0x61DC60
#define pinstCSkillsSelectWnd                              0x61DC64
#define pinstCCombatSkillSelectWnd                         0x61DC68
#define pinstCFriendsWnd                                   0x61DC6C
#define pinstCAAWnd                                        0x61DC70
#define pinstCGroupSearchFiltersWnd                        0x61DC74
#define pinstCLoadskinWnd                                  0x61DC78
#define pinstCAlarmWnd                                     0x61DC7C
#define pinstCMusicPlayerWnd                               0x61DC80
#define pinstCRaidWnd                                      0x61DC84
#define pinstCRaidOptionsWnd                               0x61DC88
#define pinstCBreathWnd                                    0x61DC8C
#define pinstCMapViewWnd                                   0x61DC90
#define pinstCMapToolbarWnd                                0x61DC94
#define pinstCEditLabelWnd                                 0x61DC98
#define pinstCTargetWnd                                    0x61DC9C
#define pinstCHotButtonWnd                                 0x61DCA0
#define pinstCColorPickerWnd                               0x61DCA4
#define pinstCPlayerWnd                                    0x61DCA8
#define pinstCOptionsWnd                                   0x61DCAC
#define pinstCBuffWindowNORMAL                             0x61DCB0
#define pinstCBuffWindowSHORT                              0x61DCB4
#define pinstCharacterCreation                             0x61DCB8
#define pinstCCursorAttachment                             0x61DCBC
#define pinstCCastingWnd                                   0x61DCC0
#define pinstCCastSpellWnd                                 0x61DCC4
#define pinstCSpellBookWnd                                 0x61DCC8
#define pinstCInventoryWnd                                 0x61DCCC
#define pinstCBankWnd                                      0x61DCD0
#define pinstCQuantityWnd                                  0x61DCD4
#define pinstCLootWnd                                      0x61DCD8
#define pinstCActionsWnd                                   0x61DCDC
#define pinstCCombatAbilityWnd                             0x61DCE0
#define pinstCMerchantWnd                                  0x61DCE4
#define pinstCTradeWnd                                     0x61DCE8
#define pinstCSelectorWnd                                  0x61DCEC
#define pinstCBazaarWnd                                    0x61DCF0
#define pinstCBazaarSearchWnd                              0x61DCF4
#define pinstCGiveWnd                                      0x61DCF8
#define pinstCTrackingWnd                                  0x61DCFC
#define pinstCInspectWnd                                   0x61DD00
#define pinstCSocialEditWnd                                0x61DD04
#define pinstCFeedbackWnd                                  0x61DD08
#define pinstCBugReportWnd                                 0x61DD0C
#define pinstCVideoModesWnd                                0x61DD10
#define pinstCTextEntryWnd                                 0x61DD14
#define pinstCFileSelectionWnd                             0x61DD18
#define pinstCCompassWnd                                   0x61DD1C
#define pinstCPlayerNotesWnd                               0x61DD20
#define pinstCGemsGameWnd                                  0x61DD24
#define pinstCTimeLeftWnd                                  0x61DD28
#define pinstCPetitionQWnd                                 0x61DD2C
#define pinstCSoulmarkWnd                                  0x61DD30
#define pinstCStoryWnd                                     0x61DD34
#define pinstCJournalTextWnd                               0x61DD38
#define pinstCJournalCatWnd                                0x61DD3C
#define pinstCBodyTintWnd                                  0x61DD40
#define pinstCInvSlotMgr                                   0x61DD44
#define pinstCContainerMgr                                 0x61DD48
#define pinstCAdventureLeaderboardWnd                      0x799AA0
#define pinstCAdventureMerchantWnd                         0x799AB8
#define pinstCAdventureRequestWnd                          0x799AD0
#define pinstCAdventureStatsWnd                            0x799AE8
#define pinstCChatManager                                  0x799D78
#define pinstCDynamicZoneWnd                               0x799E30
#define pinstCFindLocationWnd                              0x799EC0
#define pinstCGroupSearchWnd                               0x799F3C
#define pinstCGroupWnd                                     0x799F54
#define pinstCGuildMgmtWnd                                 0x799F6C
#define pinstCItemDisplayManager                           0x79A014
#define pinstCLeadershipWnd                                0x79A07C
#define pinstCPopupWndManager                              0x79A1CC
#define pinstCSystemInfoDialogBox                          0x79AA64
#define pinstCTargetOfTargetWnd                            0x79AA7C
#define pinstCTipWndOFDAY                                  0x79AAD0
#define pinstCTipWndCONTEXT                                0x79AAD4
#define pinstCTradeskillWnd                                0x79AB00
#define pinstCTributeBenefitWnd                            0x79AB40
#define pinstCTributeMasterWnd                             0x79AB58
#define pinstCContextMenuManager                           0x7A5480
// unknown window added 4-14 exe 0x79A234


////
// Section 3: Miscellaneous Offsets
////
#define DrawNetStatus                                      0x4B4584
#define CrashDetected                                      0x4C5C6E
#define __ProcessGameEvents                                0x4AB011
#define __ConvertItemTags                                  0x45A22E
#define __SendMessage                                      0x4B9FBA
#define __NewUIINI                                         0x522E8E
#define __ExecuteCmd                                       0x44CE1B

// EQ_LoadingS
#define EQ_LoadingS__WriteTextHD                           0x432408


////
// Section 4: Function Offsets
////
// CEverQuest
#define CEverQuest__dsp_chat                               0x49B0FD
#define CEverQuest__ClickedPlayer                          0x498458
#define CEverQuest__EnterZone                              0x49BE28
#define CEverQuest__GetBodyTypeDesc                        0x492273
#define CEverQuest__GetClassDesc                           0x491CF5
#define CEverQuest__GetClassThreeLetterCode                0x492110
#define CEverQuest__GetDeityDesc                           0x493D06
#define CEverQuest__GetRaceDesc                            0x492578
#define CEverQuest__InterpretCmd                           0x4A7A4F
#define CEverQuest__LeftClickedOnPlayer                    0x4A9C15
#define CEverQuest__RightClickedOnPlayer                   0x4A3949
#define CEverQuest__SetGameState                           0x4985BF

// CXWndManager
#define CXWndManager__RemoveWnd                            0x56FFF0
#define CXWndManager__GetKeyboardFlags                     0x56FC10
#define CXWndManager__HandleKeyboardMsg                    0x5700E0

// KeyPressHandler
#define KeypressHandler__HandleKeyDown                     0x4AF99D
#define KeypressHandler__HandleKeyUp                       0x4AFC43
#define KeypressHandler__AttachKeyToEqCommand              0x4B1004
#define KeypressHandler__AttachAltKeyToEqCommand           0x4B1041
#define KeypressHandler__SaveKeymapping                    0x4B0EEC
#define KeypressHandler__ClearCommandStateArray            0x4AFC30

// EQ_Character
#define EQ_Character__Max_Mana                             0x420CCC
#define EQ_Character__Max_HP                               0x420B17
#define EQ_Character__Cur_HP                               0x422692
#define EQ_Character__GetFocusCastingTimeModifier          0x428761
#define EQ_Character__GetAACastingTimeModifier             0x428AF5
#define EQ_Character__CastSpell                            0x42C63C

// EQPlayer
#define EQPlayer__EQPlayer                                 0x4872F2
#define EQPlayer__dEQPlayer                                0x486BAF
#define EQPlayer__DoAttack                                 0x482DE5

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr                                       0x4010C0
#define CXStr__CXStr1                                      0x401E96
#define CXStr__CXStr3                                      0x59EF00
#define CXStr__dCXStr                                      0x4D0B49
#define CXStr__operator_plus_equal1                        0x59FF90
#define CXStr__operator_equal1                             0x59F0C0

// CChatWindow
#define CChatWindow__CChatWindow                           0x4E21CB

// CChatManager
#define CChatManager__GetRGBAFromIndex                     0x4DED8F
#define CChatManager__InitContextMenu                      0x4DF6F3

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot                           0x4FC65B
#define CInvSlotMgr__MoveItem                              0x4FC00A

// CItemDisplayWnd
#define CItemDisplayWnd__SetItem                           0x4FF5D0
#define CItemDisplayWnd__SetSpell                          0x4FEA13

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton                         0x4F9080

// CLabel
#define CLabel__Draw                                       0x505617

// CDisplay
#define CDisplay__ReloadUI                                 0x4172F6
#define CDisplay__CleanGameUI                              0x40FE75
#define CDisplay__GetClickedActor                          0x40D1B4
#define CDisplay__WriteTextHD2                             0x4108B2
#define CDisplay__GetWorldFilePath                         0x40BD0F

// EQ_Item
#define EQ_Item__GetItemLinkHash                           0x431EFF

// CBankWnd
#define CBankWnd__GetNumBankSlots                          0x4D0C35

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg                  0x4D32EA

// CMerchantWnd
#define CMerchantWnd__SelectBuySellSlot                    0x50E3D0
#define CMerchantWnd__RequestBuyItem                       0x50D5C3
#define CMerchantWnd__RequestSellItem                      0x50D941
#define CMerchantWnd__DisplayBuyOrSellPrice                0x50D3F8

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet                         0x5200F1

// MapViewMap
#define MapViewMap__SaveEx                                 0x508BF4
#define MapViewMap__Clear                                  0x508A83


// CMapViewWnd
#define CMapViewWnd__CMapViewWnd                           0x50C4B9

// EQItemList
#define EQItemList__EQItemList                             0x44F68E
#define EQItemList__dEQItemList                            0x44F70A

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney                      0x434F42

// CSidlScreenWnd
#define CSidlScreenWnd__CSidlScreenWnd1                    0x553E70
#define CSidlScreenWnd__dCSidlScreenWnd                    0x553510
#define CSidlScreenWnd__CreateChildrenFromSidl             0x552890
#define CSidlScreenWnd__GetChildItem                       0x552110
#define CSidlScreenWnd__WndNotification                    0x552410
#define CSidlScreenWnd__CalculateHSBRange                  0x5519A0
#define CSidlScreenWnd__CalculateVSBRange                  0x5518E0
#define CSidlScreenWnd__ConvertToRes                       0x552090
#define CSidlScreenWnd__CSidlScreenWnd2                    0x553F60
#define CSidlScreenWnd__DrawSidlPiece                      0x5524B0
#define CSidlScreenWnd__EnableIniStorage                   0x552040
#define CSidlScreenWnd__GetSidlPiece                       0x552750
#define CSidlScreenWnd__Init1                              0x553BC0
#define CSidlScreenWnd__LoadIniInfo                        0x552940
#define CSidlScreenWnd__LoadIniListWnd                     0x553270
#define CSidlScreenWnd__LoadSidlScreen                     0x5522F0
#define CSidlScreenWnd__SetScreen                          0x553630
#define CSidlScreenWnd__StoreIniInfo                       0x551BD0
#define CSidlScreenWnd__StoreIniListWnd                    0x553320

// CSidlManager
#define CSidlManager__FindScreenPieceTemplate1             0x578560

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead                       0x55FE00

// CXRect
#define CXRect__CenterPoint                                0x4D0C3C

// CXWnd
#define CXWnd__Bottom                                      0x557E40
#define CXWnd__BringToTop                                  0x5545F0
#define CXWnd__Center                                      0x557C00
#define CXWnd__ClrFocus                                    0x554340
#define CXWnd__DoAllDrawing                                0x558810
#define CXWnd__DrawChildren                                0x558940
#define CXWnd__DrawColoredRect                             0x554830
#define CXWnd__DrawTooltipAtPoint                          0x557A30
#define CXWnd__GetBorderFrame                              0x554C60
#define CXWnd__GetChildWndAt                               0x557610
#define CXWnd__GetClientClipRect                           0x554BB0
#define CXWnd__GetFirstChildWnd                            0x554680
#define CXWnd__GetNextChildWnd                             0x5575F0
#define CXWnd__GetNextSib                                  0x5546A0
#define CXWnd__GetScreenClipRect                           0x557E90
#define CXWnd__GetScreenRect                               0x554E30
#define CXWnd__GetTooltipRect                              0x557980
#define CXWnd__GetWindowTextA                              0x4CB6DB
#define CXWnd__GetXMLTooltip                               0x554180
#define CXWnd__IsActive                                    0x554C20
#define CXWnd__IsDescendantOf                              0x554C30
#define CXWnd__IsReallyVisible                             0x5575D0
#define CXWnd__IsType                                      0x5587B0
#define CXWnd__Left                                        0x557CC0
#define CXWnd__Move                                        0x557180
#define CXWnd__Move1                                       0x557210
#define CXWnd__ProcessTransition                           0x5545B0
#define CXWnd__Refade                                      0x5543E0
#define CXWnd__Resize                                      0x557FD0
#define CXWnd__Right                                       0x557D70
#define CXWnd__SetFirstChildPointer                        0x555080
#define CXWnd__SetFocus                                    0x556360
#define CXWnd__SetKeyTooltip                               0x5550C0
#define CXWnd__SetMouseOver                                0x5550A0
#define CXWnd__SetNextSibPointer                           0x555090
#define CXWnd__StartFade                                   0x554610

// CSliderWnd
#define CSliderWnd__GetValue                               0x583D80
#define CSliderWnd__SetValue                               0x583F60
#define CSliderWnd__UpdateThumb                            0x583D40

// CEditBaseWnd
#define CEditBaseWnd__SetMaxChars                          0x4D0797
#define CEditBaseWnd__SetSel                               0x57A4E0

// CComboWnd
#define CComboWnd__DeleteAll                               0x57F470
#define CComboWnd__Draw                                    0x57F670
#define CComboWnd__GetButtonRect                           0x57F4A0
#define CComboWnd__GetCurChoice                            0x57F430
#define CComboWnd__GetListRect                             0x57FA60
#define CComboWnd__GetTextRect                             0x57F500
#define CComboWnd__InsertChoice                            0x57FAC0
#define CComboWnd__SetColors                               0x57F400
#define CComboWnd__SetChoice                               0x57FBA0

// CListWnd
#define CListWnd__AddColumn                                0x56E910
#define CListWnd__AddColumn1                               0x56E460
#define CListWnd__AddLine                                  0x56E020
#define CListWnd__AddString                                0x56E1A0
#define CListWnd__CalculateFirstVisibleLine                0x56B650
#define CListWnd__CalculateLineHeights                     0x56B5F0
#define CListWnd__CalculateVSBRange                        0x56D1C0
#define CListWnd__ClearAllSel                              0x56AE80
#define CListWnd__CloseAndUpdateEditWindow                 0x56BC50
#define CListWnd__Compare                                  0x56BF90
#define CListWnd__Draw                                     0x56CE20
#define CListWnd__DrawColumnSeparators                     0x56CC80
#define CListWnd__DrawHeader                               0x56B0A0
#define CListWnd__DrawItem                                 0x56C6A0
#define CListWnd__DrawLine                                 0x56C9F0
#define CListWnd__DrawSeparator                            0x56CD50
#define CListWnd__EnsureVisible                            0x56B6A0
#define CListWnd__ExtendSel                                0x56C5D0
#define CListWnd__GetColumnFlags                           0x56A950
#define CListWnd__GetColumnJustification                   0x56AAF0
#define CListWnd__GetColumnMinWidth                        0x56AA80
#define CListWnd__GetColumnWidth                           0x56A9B0
#define CListWnd__GetCurSel                                0x56A790
#define CListWnd__GetHeaderRect                            0x56A5D0
#define CListWnd__GetItemAtPoint                           0x56B950
#define CListWnd__GetItemAtPoint1                          0x56B9C0
#define CListWnd__GetItemData                              0x56A7D0
#define CListWnd__GetItemHeight                            0x56B480
#define CListWnd__GetItemIcon                              0x56A890
#define CListWnd__GetItemRect                              0x56B770
#define CListWnd__GetItemText                              0x56A810
#define CListWnd__GetSelList                               0x56E340
#define CListWnd__GetSeparatorRect                         0x56BEE0
#define CListWnd__IsLineEnabled                            0x56AF70
#define CListWnd__RemoveLine                               0x56E2F0
#define CListWnd__SetColors                                0x56A540
#define CListWnd__SetColumnWidth                           0x56AA30
#define CListWnd__SetColumnJustification                   0x56AB50
#define CListWnd__SetCurSel                                0x56ADA0
#define CListWnd__SetItemColor                             0x56DC60
#define CListWnd__SetItemData                              0x56AF30
#define CListWnd__SetItemText                              0x56DBA0
#define CListWnd__ShiftColumnSeparator                     0x56C540
#define CListWnd__Sort                                     0x56E9B0
#define CListWnd__ToggleSel                                0x56ADC0

// CEditWnd
#define CEditWnd__DrawCaret                                0x57FF00
#define CEditWnd__DrawMultiline                            0x581440
#define CEditWnd__GetCaretPt                               0x5817F0
#define CEditWnd__GetCharIndexPt                           0x580D40
#define CEditWnd__GetDisplayString                         0x580060
#define CEditWnd__GetHorzOffset                            0x5802D0
#define CEditWnd__GetLineForPrintableChar                  0x5807F0
#define CEditWnd__GetSelEndPt                              0x580F80
#define CEditWnd__GetSelStartPt                            0x580F60
#define CEditWnd__GetSTMLSafeText                          0x5804B0
#define CEditWnd__PointFromPrintableChar                   0x580900
#define CEditWnd__SelectableCharFromPoint                  0x580A80
#define CEditWnd__SetEditable                              0x580480

// CGaugeWnd
#define CGaugeWnd__CalcFillRect                            0x4EDAD9
#define CGaugeWnd__CalcLinesFillRect                       0x4EDB35
#define CGaugeWnd__Draw                                    0x4EDE35

// CStmlWnd
#define CStmlWnd__AppendSTML                               0x569A50
#define CStmlWnd__CalculateHSBRange                        0x561500
#define CStmlWnd__CalculateVSBRange                        0x5614A0
#define CStmlWnd__CanBreakAtCharacter                      0x561640
#define CStmlWnd__CanGoBackward                            0x5616C0
#define CStmlWnd__FastForwardPastSpaces                    0x562060
#define CStmlWnd__FastForwardToEndOfTag                    0x5623C0
#define CStmlWnd__GetNextChar                              0x561B20
#define CStmlWnd__GetNextTagPiece                          0x5621D0
#define CStmlWnd__GetSTMLText                              0x4E21AD
#define CStmlWnd__GetThisChar                              0x561360
#define CStmlWnd__GetVisiableText                          0x563B90
#define CStmlWnd__InitializeTempVariables                  0x561310
#define CStmlWnd__InitializeWindowVariables                0x565920
#define CStmlWnd__MakeStmlColorTag                         0x560B10
#define CStmlWnd__MakeWndNotificationTag                   0x560BB0
#define CStmlWnd__StripFirstSTMLLines                      0x5697D0
#define CStmlWnd__UpdateHistoryString                      0x563FD0

// CTabWnd
#define CTabWnd__Draw                                      0x57F150
#define CTabWnd__DrawCurrentPage                           0x57EC40
#define CTabWnd__DrawTab                                   0x57E9C0
#define CTabWnd__GetCurrentPage                            0x57E570
#define CTabWnd__GetCurrentTabIndex                        0x57E350
#define CTabWnd__GetNumTabs                                0x57E440
#define CTabWnd__GetPageClientRect                         0x57E360
#define CTabWnd__GetPageFromTabIndex                       0x57E470
#define CTabWnd__GetPageInnerRect                          0x57E3C0
#define CTabWnd__GetTabInnerRect                           0x57E680
#define CTabWnd__GetTabRect                                0x57E580
#define CTabWnd__IndexInBounds                             0x57E450
#define CTabWnd__InsertPage                                0x57F040
#define CTabWnd__SetPage                                   0x57E720
#define CTabWnd__SetPageRect                               0x57E830
#define CTabWnd__UpdatePage                                0x57E8E0

// CTextOverlay
#define CTextOverlay__DisplayText                          0x4013F2
