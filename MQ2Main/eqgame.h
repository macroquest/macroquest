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
//.rdata:005DF1F4 aApr192004      db 'Apr 19 2004',0
//.rdata:005DF200 a155350         db '15:53:50',0
#define __ExpectedVersionDate                         "Apr 19 2004"
#define __ExpectedVersionTime                         "15:53:50"
#define __ActualVersionDate                                0x5DF1F4
#define __ActualVersionTime                                0x5DF200

#define __ClientOverride                       0
#define __MacroQuestWinClassName                 "__MacroQuestTray"
#define __MacroQuestWinName                           "MacroQuest"

// Memory Protection
#define __MemChecker0                                      0x4BFC07
#define __MemChecker1                                      0x4C4790
#define __MemChecker2                                      0x4C656C
#define __MemChecker3                                      0x4C6609
#define __EncryptPad0                                      0x615960
#define __EncryptPad1                                      0x615D60
#define __EncryptPad2                                      0x616820
#define __EncryptPad3                                      0x616C20

#define DI8__Main                                          0x793404
#define DI8__Keyboard                                      0x793408
#define DI8__Mouse                                         0x79340C

#define __LastTell                                         0x6D5388
#define __Guilds                                           0x735A40
#define __Mouse                                            0x793410
#define __Attack                                           0x733BBA
#define __InChatMode                                       0x6D32D0
#define __gWorld                                           0x735998
#define __GroupCount                                       0x733F48
#define __CommandList                                      0x60F810
#define __DoAbilityList                                    0x70CE5C
#define __DoAbilityAvailable                               0x6D40B0
#define __ServerHost                                       0x733E04
#define __ServerName                                       0x70CE1C
#define __HWnd                                             0x6D3290
#define __Clicks                                           0x6D3390
#define __ScreenX                                          0x6D3298
#define __ScreenY                                          0x6D329C
#define __EQP_IDArray                                      0x6D0368
#define __CurrentMapLabel                                  0x79C298
#define __BindList                                         0x60F2F0
#define __RangeAttackReady                                 0x6D4114
#define __AltTimerReady		                               0x6D4116
#define __Socials                                          0x70CF1C
#define __HotkeyPage                                       0x7337BC
#define __CurrentSocial                                    0x60BB58
#define __GroupLeader									   0x7340A4
#define __SkillDict										   0x620808
#define __DrawHandler									   0x7A7F34
#define __FriendsList									   0x709C1C
#define __IgnoreList									   0x70B51C
////
//Section 1: Vital Offsets
////
#define pinstCSidlManager                                  0x7A7664
#define pinstCDisplay                                      0x735A24
#define pinstCEverQuest                                    0x793578
#define pinstPCData                                        0x735A00
#define pinstCharData                                      0x735A00
#define pinstCharSpawn                                     0x7359F8
#define pinstSpawnList                                     0x7359C0
#define pinstLocalPlayer                                   0x7359E4
#define pinstControlledPlayer                              0x7359F8
#define pinstWorldData                                     0x7359BC
#define pinstSpellManager                                  0x78FFCC
#define pinstTradeTarget                                   0x7359E0
#define pinstActiveMerchant                                0x735A10
#define pinstActiveBanker                                  0x735A14
#define pinstActiveCorpse                                  0x735A18
#define pinstActiveGMaster                                 0x735A1C
#define pinstSelectedItem                                  0x79C1A0
#define pinstGroup                                         0x734090
#define pinstTarget                                        0x735A04
#define pinstSwitchManager                                 0x6D3284
#define pinstEQItemList                                    0x7359C4
#define pinstSpellSets                                     0x7337C0
#define instEQZoneInfo                                     0x6D34FC
#define pinstCXWndManager                                  0x7A765C
#define instKeypressHandler                                0x782800
#define pinstStringTable								   0x7359B0

////
//Section 2:  UI Related Offsets
////
#define pinstCTextOverlay                                  0x61F1A0
#define pinstCharacterSelect                               0x61FE04
#define pinstCFacePick                                     0x61FE08
// removed 4-14 exe #define pinstCTextMessageWnd                               
#define pinstCNoteWnd                                      0x61FE0C
#define pinstCHelpWnd                                      0x61FE10
#define pinstCBookWnd                                      0x61FE14
#define pinstCPetInfoWnd                                   0x61FE18
#define pinstCTrainWnd                                     0x61FE1C
#define pinstCSkillsWnd                                    0x61FE20
#define pinstCSkillsSelectWnd                              0x61FE24
#define pinstCCombatSkillSelectWnd                         0x61FE28
#define pinstCFriendsWnd                                   0x61FE2C
#define pinstCAAWnd                                        0x61FE30
#define pinstCGroupSearchFiltersWnd                        0x61FE34
#define pinstCLoadskinWnd                                  0x61FE38
#define pinstCAlarmWnd                                     0x61FE3C
#define pinstCMusicPlayerWnd                               0x61FE40
#define pinstCRaidWnd                                      0x61FE44
#define pinstCRaidOptionsWnd                               0x61FE48
#define pinstCBreathWnd                                    0x61FE4C
#define pinstCMapViewWnd                                   0x61FE50
#define pinstCMapToolbarWnd                                0x61FE54
#define pinstCEditLabelWnd                                 0x61FE58
#define pinstCTargetWnd                                    0x61FE5C
#define pinstCHotButtonWnd                                 0x61FE60
#define pinstCColorPickerWnd                               0x61FE64
#define pinstCPlayerWnd                                    0x61FE68
#define pinstCOptionsWnd                                   0x61FE6C
#define pinstCBuffWindowNORMAL                             0x61FE70
#define pinstCBuffWindowSHORT                              0x61FE74
#define pinstCharacterCreation                             0x61FE78
#define pinstCCursorAttachment                             0x61FE7C
#define pinstCCastingWnd                                   0x61FE80
#define pinstCCastSpellWnd                                 0x61FE84
#define pinstCSpellBookWnd                                 0x61FE88
#define pinstCInventoryWnd                                 0x61FE8C
#define pinstCBankWnd                                      0x61FE90
#define pinstCQuantityWnd                                  0x61FE94
#define pinstCLootWnd                                      0x61FE98
#define pinstCActionsWnd                                   0x61FE9C
#define pinstCCombatAbilityWnd                             0x61FEA0
#define pinstCMerchantWnd                                  0x61FEA4
#define pinstCTradeWnd                                     0x61FEA8
#define pinstCSelectorWnd                                  0x61FEAC
#define pinstCBazaarWnd                                    0x61FEB0
#define pinstCBazaarSearchWnd                              0x61FEB4
#define pinstCGiveWnd                                      0x61FEB8
#define pinstCTrackingWnd                                  0x61FEBC
#define pinstCInspectWnd                                   0x61FEC0
#define pinstCSocialEditWnd                                0x61FEC4
#define pinstCFeedbackWnd                                  0x61FEC8
#define pinstCBugReportWnd                                 0x61FECC
#define pinstCVideoModesWnd                                0x61FED0
#define pinstCTextEntryWnd                                 0x61FED4
#define pinstCFileSelectionWnd                             0x61FED8
#define pinstCCompassWnd                                   0x61FEDC
#define pinstCPlayerNotesWnd                               0x61FEE0
#define pinstCGemsGameWnd                                  0x61FEE4
#define pinstCTimeLeftWnd                                  0x61FEE8
#define pinstCPetitionQWnd                                 0x61FEEC
#define pinstCSoulmarkWnd                                  0x61FEF0
#define pinstCStoryWnd                                     0x61FEF4
#define pinstCJournalTextWnd                               0x61FEF8
#define pinstCJournalCatWnd                                0x61FEFC
#define pinstCBodyTintWnd                                  0x61FF00
#define pinstCInvSlotMgr                                   0x61FF04
#define pinstCContainerMgr                                 0x61FF08
#define pinstCAdventureLeaderboardWnd                      0x79BC58
#define pinstCAdventureMerchantWnd                         0x79BC70
#define pinstCAdventureRequestWnd                          0x79BC88
#define pinstCAdventureStatsWnd                            0x79BCA0
#define pinstCChatManager                                  0x79BF30
#define pinstCDynamicZoneWnd                               0x79BFE8
#define pinstCFindLocationWnd                              0x79C078
#define pinstCGroupSearchWnd                               0x79C0F4
#define pinstCGroupWnd                                     0x79C10C
#define pinstCGuildMgmtWnd                                 0x79C124
#define pinstCItemDisplayManager                           0x79C1CC
#define pinstCLeadershipWnd                                0x79C234
#define pinstCPopupWndManager                              0x79C384
#define pinstCSystemInfoDialogBox                          0x79CC64
#define pinstCTargetOfTargetWnd                            0x79CC7C
#define pinstCTipWndOFDAY                                  0x79CCD0
#define pinstCTipWndCONTEXT                                0x79CCD4
#define pinstCTradeskillWnd                                0x79CD00
#define pinstCTributeBenefitWnd                            0x79CD40
#define pinstCTributeMasterWnd                             0x79CD58
#define pinstCContextMenuManager                           0x7A7680
// unknown window added 4-14 exe 0x79A234


////
// Section 3: Miscellaneous Offsets
////
#define DrawNetStatus                                      0x4B476A
#define CrashDetected                                      0x4C626A
#define __ProcessGameEvents                                0x4AB19C
#define __ConvertItemTags                                  0x45A28E
#define __SendMessage                                      0x4BA399
#define __NewUIINI                                         0x524D9E
#define __ExecuteCmd                                       0x44D11C
#define __GetGaugeValueFromEQ							   0x523603
#define __get_melee_range								   0x451C33

// EQ_LoadingS
#define EQ_LoadingS__WriteTextHD                           0x431F86


////
// Section 4: Function Offsets
////
// CEverQuest
#define CEverQuest__dsp_chat                               0x49B21C
#define CEverQuest__ClickedPlayer                          0x498577
#define CEverQuest__EnterZone                              0x49BF47
#define CEverQuest__GetBodyTypeDesc                        0x49237A
#define CEverQuest__GetClassDesc                           0x491DFC
#define CEverQuest__GetClassThreeLetterCode                0x492217
#define CEverQuest__GetDeityDesc                           0x493E0D
#define CEverQuest__GetRaceDesc                            0x49267F
#define CEverQuest__InterpretCmd                           0x4A7BE1
#define CEverQuest__LeftClickedOnPlayer                    0x4A9DA0
#define CEverQuest__RightClickedOnPlayer                   0x4A29D3
#define CEverQuest__SetGameState                           0x4986DE
#define CEverQuest__DropHeldItemOnGround				   0x49ACDD

#define StringTable__getString							   0x4BD566

// CXWndManager
#define CXWndManager__RemoveWnd                            0x5720D0
#define CXWndManager__GetKeyboardFlags                     0x571CF0
#define CXWndManager__HandleKeyboardMsg                    0x5721C0

// KeyPressHandler
#define KeypressHandler__HandleKeyDown                     0x4AFB25
#define KeypressHandler__HandleKeyUp                       0x4AFDC8
#define KeypressHandler__AttachKeyToEqCommand              0x4B11A7
#define KeypressHandler__AttachAltKeyToEqCommand           0x4B11E4
#define KeypressHandler__SaveKeymapping                    0x4B108F
#define KeypressHandler__ClearCommandStateArray            0x4AFDB8

// EQ_Character
#define EQ_Character__Max_Endurance						   0x41D02D
#define EQ_Character__Max_Mana                             0x4209AE
#define EQ_Character__Max_HP                               0x4207F9
#define EQ_Character__Cur_HP                               0x422374
#define EQ_Character__GetFocusCastingTimeModifier          0x428338
#define EQ_Character__GetAACastingTimeModifier             0x4286D1
#define EQ_Character__CastSpell                            0x42C218

// EQPlayer
#define EQPlayer__EQPlayer                                 0x4873F4
#define EQPlayer__dEQPlayer                                0x486CB1
#define EQPlayer__DoAttack                                 0x4833C5

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr                                       0x401022
#define CXStr__CXStr1                                      0x5101BC
#define CXStr__CXStr3                                      0x5A1000
#define CXStr__dCXStr                                      0x40104C
#define CXStr__operator_plus_equal1                        0x5A2090
#define CXStr__operator_equal1                             0x5A11C0

// CChatWindow
#define CChatWindow__CChatWindow                           0x4E2841

// CChatManager
#define CChatManager__GetRGBAFromIndex                     0x4DF405
#define CChatManager__InitContextMenu                      0x4DFD69

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot                           0x4FCC6F
#define CInvSlotMgr__MoveItem                              0x4FC61E

// CItemDisplayWnd
#define CItemDisplayWnd__SetItem                           0x4FFBCE
#define CItemDisplayWnd__SetSpell                          0x4FF011

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton                         0x4F9691

// CLabel
#define CLabel__Draw                                       0x505D68

// CGauge
#define CGauge__Draw									   0x4EE427

// CDisplay
#define CDisplay__ReloadUI                                 0x416F61
#define CDisplay__CleanGameUI                              0x40FECD
#define CDisplay__GetClickedActor                          0x40D1D7
#define CDisplay__WriteTextHD2                             0x41094C
#define CDisplay__GetWorldFilePath                         0x40BDD9

// EQ_Item
#define EQ_Item__GetItemLinkHash                           0x431A7D
#define EQ_Item__CanDrop								   0x431B75

// CBankWnd
#define CBankWnd__GetNumBankSlots                          0x4D1268

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg                  0x4D391D

// CMerchantWnd
#define CMerchantWnd__SelectBuySellSlot                    0x50EB23
#define CMerchantWnd__RequestBuyItem                       0x50DD16
#define CMerchantWnd__RequestSellItem                      0x50E094
#define CMerchantWnd__DisplayBuyOrSellPrice                0x50DB4B

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet                         0x522007

// MapViewMap
#define MapViewMap__SaveEx                                 0x509342
#define MapViewMap__Clear                                  0x5091D1


// CMapViewWnd
#define CMapViewWnd__CMapViewWnd                           0x50CC07

// EQItemList
#define EQItemList__EQItemList                             0x44F9CB
#define EQItemList__dEQItemList                            0x44FA47

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney                      0x434AC3

// CContainerWnd
#define CContainerWnd__HandleCombine					   0x4E6A2A
#define CContainerWnd__vftable							   0x5E3510

// CSidlScreenWnd
#define CSidlScreenWnd__CSidlScreenWnd1                    0x555ED0
#define CSidlScreenWnd__dCSidlScreenWnd                    0x555570
#define CSidlScreenWnd__CreateChildrenFromSidl             0x5548C0
#define CSidlScreenWnd__GetChildItem                       0x5541D0
#define CSidlScreenWnd__WndNotification                    0x554440
#define CSidlScreenWnd__CalculateHSBRange                  0x553A60
#define CSidlScreenWnd__CalculateVSBRange                  0x5539A0
#define CSidlScreenWnd__ConvertToRes                       0x554150
#define CSidlScreenWnd__CSidlScreenWnd2                    0x555FC0
#define CSidlScreenWnd__DrawSidlPiece                      0x5544E0
#define CSidlScreenWnd__EnableIniStorage                   0x554100
#define CSidlScreenWnd__GetSidlPiece                       0x554780
#define CSidlScreenWnd__Init1                              0x555C20
#define CSidlScreenWnd__LoadIniInfo                        0x554970
#define CSidlScreenWnd__LoadIniListWnd                     0x5552A0
#define CSidlScreenWnd__LoadSidlScreen                     0x554320
#define CSidlScreenWnd__SetScreen                          0x555690
#define CSidlScreenWnd__StoreIniInfo                       0x553C90
#define CSidlScreenWnd__StoreIniListWnd                    0x555350

// CSidlManager
#define CSidlManager__FindScreenPieceTemplate1             0x57A700

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead                       0x561E10

// CXRect
#define CXRect__CenterPoint                                0x4D126F

// CXWnd
#define CXWnd__Bottom                                      0x559E90
#define CXWnd__BringToTop                                  0x556650
#define CXWnd__Center                                      0x559C50
#define CXWnd__ClrFocus                                    0x5563A0
#define CXWnd__DoAllDrawing                                0x55A860
#define CXWnd__DrawChildren                                0x55A990
#define CXWnd__DrawColoredRect                             0x556880
#define CXWnd__DrawTooltipAtPoint                          0x559A80
#define CXWnd__GetBorderFrame                              0x556CB0
#define CXWnd__GetChildWndAt                               0x559660
#define CXWnd__GetClientClipRect                           0x556C00
#define CXWnd__GetFirstChildWnd                            0x5566E0
#define CXWnd__GetNextChildWnd                             0x559640
#define CXWnd__GetNextSib                                  0x556700
#define CXWnd__GetScreenClipRect                           0x559EE0
#define CXWnd__GetScreenRect                               0x556E80
#define CXWnd__GetTooltipRect                              0x5599D0
#define CXWnd__GetWindowTextA                              0x4CBCED
#define CXWnd__GetXMLTooltip                               0x5561E0
#define CXWnd__IsActive                                    0x556C70
#define CXWnd__IsDescendantOf                              0x556C80
#define CXWnd__IsReallyVisible                             0x559620
#define CXWnd__IsType                                      0x55A800
#define CXWnd__Left                                        0x559D10
#define CXWnd__Move                                        0x5591D0
#define CXWnd__Move1                                       0x559260
#define CXWnd__ProcessTransition                           0x556610
#define CXWnd__Refade                                      0x556440
#define CXWnd__Resize                                      0x55A020
#define CXWnd__Right                                       0x559DC0
#define CXWnd__SetFirstChildPointer                        0x5570D0
#define CXWnd__SetFocus                                    0x5583B0
#define CXWnd__SetKeyTooltip                               0x557110
#define CXWnd__SetMouseOver                                0x5570F0
#define CXWnd__SetNextSibPointer                           0x5570E0
#define CXWnd__StartFade                                   0x556670

// CSliderWnd
#define CSliderWnd__GetValue                               0x585F80
#define CSliderWnd__SetValue                               0x586160
#define CSliderWnd__UpdateThumb                            0x585F40

// CEditBaseWnd
#define CEditBaseWnd__SetMaxChars                          0x4D0DDE
#define CEditBaseWnd__SetSel                               0x57C680

// CComboWnd
#define CComboWnd__DeleteAll                               0x5816B0
#define CComboWnd__Draw                                    0x5818B0
#define CComboWnd__GetButtonRect                           0x5816E0
#define CComboWnd__GetCurChoice                            0x581670
#define CComboWnd__GetListRect                             0x581CA0
#define CComboWnd__GetTextRect                             0x581740
#define CComboWnd__InsertChoice                            0x581D00
#define CComboWnd__SetColors                               0x581640
#define CComboWnd__SetChoice                               0x581DE0

// CListWnd
#define CListWnd__AddColumn                                0x5709E0
#define CListWnd__AddColumn1                               0x570540
#define CListWnd__AddLine                                  0x570100
#define CListWnd__AddString                                0x570280
#define CListWnd__CalculateFirstVisibleLine                0x56D730
#define CListWnd__CalculateLineHeights                     0x56D6D0
#define CListWnd__CalculateVSBRange                        0x56F2A0
#define CListWnd__ClearAllSel                              0x56CF60
#define CListWnd__CloseAndUpdateEditWindow                 0x56DD30
#define CListWnd__Compare                                  0x56E070
#define CListWnd__Draw                                     0x56EF00
#define CListWnd__DrawColumnSeparators                     0x56ED60
#define CListWnd__DrawHeader                               0x56D180
#define CListWnd__DrawItem                                 0x56E780
#define CListWnd__DrawLine                                 0x56EAD0
#define CListWnd__DrawSeparator                            0x56EE30
#define CListWnd__EnsureVisible                            0x56D780
#define CListWnd__ExtendSel                                0x56E6B0
#define CListWnd__GetColumnFlags                           0x56CA30
#define CListWnd__GetColumnJustification                   0x56CBD0
#define CListWnd__GetColumnMinWidth                        0x56CB60
#define CListWnd__GetColumnWidth                           0x56CA90
#define CListWnd__GetCurSel                                0x56C870
#define CListWnd__GetHeaderRect                            0x56C6B0
#define CListWnd__GetItemAtPoint                           0x56DA30
#define CListWnd__GetItemAtPoint1                          0x56DAA0
#define CListWnd__GetItemData                              0x56C8B0
#define CListWnd__GetItemHeight                            0x56D560
#define CListWnd__GetItemIcon                              0x56C970
#define CListWnd__GetItemRect                              0x56D850
#define CListWnd__GetItemText                              0x56C8F0
#define CListWnd__GetSelList                               0x570420
#define CListWnd__GetSeparatorRect                         0x56DFC0
#define CListWnd__IsLineEnabled                            0x56D050
#define CListWnd__RemoveLine                               0x5703D0
#define CListWnd__SetColors                                0x56C620
#define CListWnd__SetColumnWidth                           0x56CB10
#define CListWnd__SetColumnJustification                   0x56CC30
#define CListWnd__SetCurSel                                0x56CE80
#define CListWnd__SetItemColor                             0x56FD40
#define CListWnd__SetItemData                              0x56D010
#define CListWnd__SetItemText                              0x56FC80
#define CListWnd__ShiftColumnSeparator                     0x56E620
#define CListWnd__Sort                                     0x570A80
#define CListWnd__ToggleSel                                0x56CEA0

// CEditWnd
#define CEditWnd__DrawCaret                                0x582140
#define CEditWnd__DrawMultiline                            0x583650
#define CEditWnd__GetCaretPt                               0x583A00
#define CEditWnd__GetCharIndexPt                           0x582F50
#define CEditWnd__GetDisplayString                         0x582270
#define CEditWnd__GetHorzOffset                            0x5824E0
#define CEditWnd__GetLineForPrintableChar                  0x582A00
#define CEditWnd__GetSelEndPt                              0x583190
#define CEditWnd__GetSelStartPt                            0x583170
#define CEditWnd__GetSTMLSafeText                          0x5826C0
#define CEditWnd__PointFromPrintableChar                   0x582B10
#define CEditWnd__SelectableCharFromPoint                  0x582C90
#define CEditWnd__SetEditable                              0x582690

// CGaugeWnd
#define CGaugeWnd__CalcFillRect                            0x4EE0CB
#define CGaugeWnd__CalcLinesFillRect                       0x4EE127
#define CGaugeWnd__Draw                                    0x4EE427

// CStmlWnd
#define CStmlWnd__AppendSTML                               0x56BB30
#define CStmlWnd__CalculateHSBRange                        0x5635A0
#define CStmlWnd__CalculateVSBRange                        0x563540
#define CStmlWnd__CanBreakAtCharacter                      0x5636E0
#define CStmlWnd__CanGoBackward                            0x563760
#define CStmlWnd__FastForwardPastSpaces                    0x564140
#define CStmlWnd__FastForwardToEndOfTag                    0x5644A0
#define CStmlWnd__GetNextChar                              0x563BC0
#define CStmlWnd__GetNextTagPiece                          0x5642B0
#define CStmlWnd__GetSTMLText                              0x4E2823
#define CStmlWnd__GetThisChar                              0x563400
#define CStmlWnd__GetVisiableText                          0x565C70
#define CStmlWnd__InitializeTempVariables                  0x5633B0
#define CStmlWnd__InitializeWindowVariables                0x567A00
#define CStmlWnd__MakeStmlColorTag                         0x562BB0
#define CStmlWnd__MakeWndNotificationTag                   0x562C50
#define CStmlWnd__StripFirstSTMLLines                      0x56B8B0
#define CStmlWnd__UpdateHistoryString                      0x5660B0

// CTabWnd
#define CTabWnd__Draw                                      0x581390
#define CTabWnd__DrawCurrentPage                           0x580E80
#define CTabWnd__DrawTab                                   0x580C00
#define CTabWnd__GetCurrentPage                            0x5807B0
#define CTabWnd__GetCurrentTabIndex                        0x5804C0
#define CTabWnd__GetNumTabs                                0x580680
#define CTabWnd__GetPageClientRect                         0x5804D0
#define CTabWnd__GetPageFromTabIndex                       0x5806B0
#define CTabWnd__GetPageInnerRect                          0x580530
#define CTabWnd__GetTabInnerRect                           0x5808C0
#define CTabWnd__GetTabRect                                0x5807C0
#define CTabWnd__IndexInBounds                             0x580690
#define CTabWnd__InsertPage                                0x581280
#define CTabWnd__SetPage                                   0x580960
#define CTabWnd__SetPageRect                               0x580A70
#define CTabWnd__UpdatePage                                0x580B20

// CTextOverlay
#define CTextOverlay__DisplayText                          0x401406
