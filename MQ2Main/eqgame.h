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
//.rdata:005DC1CC aMar302004      db 'Mar 30 2004',0
//.rdata:005DC1D8 a151211         db '15:12:11',0
#define __ExpectedVersionDate                         "Mar 29 2004"
#define __ExpectedVersionTime                         "18:04:34"
#define __ActualVersionDate                                0x5DC1CC
#define __ActualVersionTime                                0x5DC1D8

#define __ClientOverride                       0
#define __MacroQuestWinClassName                 "__MacroQuestTray"
#define __MacroQuestWinName                           "MacroQuest"

// Memory Protection
#define __MemChecker0                                      0x4BEE36
#define __MemChecker1                                      0x4C3A22
#define __MemChecker2                                      0x4C57FE
#define __MemChecker3                                      0x4C589B
#define __EncryptPad0                                      0x6129C0
#define __EncryptPad1                                      0x612DC0
#define __EncryptPad2                                      0x613878
#define __EncryptPad3                                      0x613C78

#define DI8__Main                                          0x78FEEC
#define DI8__Keyboard                                      0x78FEF0
#define DI8__Mouse                                         0x78FEF4

#define __LastTell                                         0x6D1E9C
#define __Guilds                                           0x732558
#define __Mouse                                            0x78FEF8
#define __Attack                                           0x7306CE
#define __InChatMode                                       0x6CFDD0
#define __gWorld                                           0x7324B0
#define __GroupCount                                       0x730A60
#define __CommandList                                      0x60C730
#define __DoAbilityList                                    0x709970
#define __DoAbilityAvailable                               0x6D0BC4
#define __ServerHost                                       0x73091C
#define __ServerName                                       0x709930
#define __HWnd                                             0x6CFD90
#define __Clicks                                           0x6CFE90
#define __ScreenX                                          0x6CFD98
#define __ScreenY                                          0x6CFD9C
#define __EQP_IDArray                                      0x6CCE58
#define __CurrentMapLabel                                  0x798D54
#define __BindList                                         0x60C220
#define __RangeAttackReady                                 0x6D0C28
#define __Socials                                          0x709A30
#define __HotkeyPage                                       0x7302D0
#define __CurrentSocial                                    0x608A9C
////
//Section 1: Vital Offsets
////
#define pinstCSidlManager                                  0x7A40C4
#define pinstCDisplay                                      0x73253C
#define pinstCEverQuest                                    0x790060
#define pinstPCData                                        0x732518
#define pinstCharData                                      0x732518
#define pinstCharSpawn                                     0x732510
#define pinstSpawnList                                     0x7324D8
#define pinstLocalPlayer                                   0x7324FC
#define pinstControlledPlayer                              0x732510
#define pinstWorldData                                     0x7324D4
#define pinstSpellManager                                  0x78CAB4
#define pinstTradeTarget                                   0x7324F8
#define pinstActiveMerchant                                0x732528
#define pinstActiveBanker                                  0x73252C
#define pinstActiveCorpse                                  0x732530
#define pinstActiveGMaster                                 0x732534
#define pinstSelectedItem                                  0x798C70
#define pinstGroup                                         0x730BA8
#define pinstTarget                                        0x73251C
#define pinstSwitchManager                                 0x6CFD80
#define pinstEQItemList                                    0x7324DC
#define pinstSpellSets                                     0x7302D4
#define instEQZoneInfo                                     0x6D0004
#define pinstCXWndManager                                  0x7A40BC
#define instKeypressHandler                                0x77F300


////
//Section 2:  UI Related Offsets
////
#define pinstCTextOverlay                                  0x61C0A0
#define pinstCharacterSelect                               0x61CD04
#define pinstCFacePick                                     0x61CD08
#define pinstCTextMessageWnd                               0x61CD0C
#define pinstCNoteWnd                                      0x61CD10
#define pinstCHelpWnd                                      0x61CD14
#define pinstCBookWnd                                      0x61CD18
#define pinstCPetInfoWnd                                   0x61CD1C
#define pinstCTrainWnd                                     0x61CD20
#define pinstCSkillsWnd                                    0x61CD24
#define pinstCSkillsSelectWnd                              0x61CD28
#define pinstCCombatSkillSelectWnd                         0x61CD2C
#define pinstCFriendsWnd                                   0x61CD30
#define pinstCAAWnd                                        0x61CD34
#define pinstCGroupSearchFiltersWnd                        0x61CD38
#define pinstCLoadskinWnd                                  0x61CD3C
#define pinstCAlarmWnd                                     0x61CD40
#define pinstCMusicPlayerWnd                               0x61CD44
#define pinstCRaidWnd                                      0x61CD48
#define pinstCRaidOptionsWnd                               0x61CD4C
#define pinstCBreathWnd                                    0x61CD50
#define pinstCMapViewWnd                                   0x61CD54
#define pinstCMapToolbarWnd                                0x61CD58
#define pinstCEditLabelWnd                                 0x61CD5C
#define pinstCTargetWnd                                    0x61CD60
#define pinstCHotButtonWnd                                 0x61CD64
#define pinstCColorPickerWnd                               0x61CD68
#define pinstCPlayerWnd                                    0x61CD6C
#define pinstCOptionsWnd                                   0x61CD70
#define pinstCBuffWindowNORMAL                             0x61CD74
#define pinstCBuffWindowSHORT                              0x61CD78
#define pinstCharacterCreation                             0x61CD7C
#define pinstCCursorAttachment                             0x61CD80
#define pinstCCastingWnd                                   0x61CD84
#define pinstCCastSpellWnd                                 0x61CD88
#define pinstCSpellBookWnd                                 0x61CD8C
#define pinstCInventoryWnd                                 0x61CD90
#define pinstCBankWnd                                      0x61CD94
#define pinstCQuantityWnd                                  0x61CD98
#define pinstCLootWnd                                      0x61CD9C
#define pinstCActionsWnd                                   0x61CDA0
#define pinstCCombatAbilityWnd                             0x61CDA4
#define pinstCMerchantWnd                                  0x61CDA8
#define pinstCTradeWnd                                     0x61CDAC
#define pinstCSelectorWnd                                  0x61CDB0
#define pinstCBazaarWnd                                    0x61CDB4
#define pinstCBazaarSearchWnd                              0x61CDB8
#define pinstCGiveWnd                                      0x61CDBC
#define pinstCTrackingWnd                                  0x61CDC0
#define pinstCInspectWnd                                   0x61CDC4
#define pinstCSocialEditWnd                                0x61CDC8
#define pinstCFeedbackWnd                                  0x61CDCC
#define pinstCBugReportWnd                                 0x61CDD0
#define pinstCVideoModesWnd                                0x61CDD4
#define pinstCTextEntryWnd                                 0x61CDD8
#define pinstCFileSelectionWnd                             0x61CDDC
#define pinstCCompassWnd                                   0x61CDE0
#define pinstCPlayerNotesWnd                               0x61CDE4
#define pinstCGemsGameWnd                                  0x61CDE8
#define pinstCTimeLeftWnd                                  0x61CDEC
#define pinstCPetitionQWnd                                 0x61CDF0
#define pinstCSoulmarkWnd                                  0x61CDF4
#define pinstCStoryWnd                                     0x61CDF8
#define pinstCJournalTextWnd                               0x61CDFC
#define pinstCJournalCatWnd                                0x61CE00
#define pinstCBodyTintWnd                                  0x61CE04
#define pinstCInvSlotMgr                                   0x61CE08
#define pinstCContainerMgr                                 0x61CE0C
#define pinstCAdventureLeaderboardWnd                      0x798740
#define pinstCAdventureMerchantWnd                         0x798758
#define pinstCAdventureRequestWnd                          0x798770
#define pinstCAdventureStatsWnd                            0x798788
#define pinstCChatManager                                  0x798A00
#define pinstCDynamicZoneWnd                               0x798AB8
#define pinstCFindLocationWnd                              0x798B48
#define pinstCGroupSearchWnd                               0x798BC4
#define pinstCGroupWnd                                     0x798BDC
#define pinstCGuildMgmtWnd                                 0x798BF4
#define pinstCItemDisplayManager                           0x798C9C
#define pinstCLeadershipWnd                                0x798CF0
#define pinstCPopupWndManager                              0x798E40
#define pinstCSystemInfoDialogBox                          0x7996BC
#define pinstCTargetOfTargetWnd                            0x7996D4
#define pinstCTipWndOFDAY                                  0x79973C
#define pinstCTipWndCONTEXT                                0x799740
#define pinstCTradeskillWnd                                0x79976C
#define pinstCTributeBenefitWnd                            0x7997AC
#define pinstCTributeMasterWnd                             0x7997C4
#define pinstCContextMenuManager                           0x7A40E0


////
// Section 3: Miscellaneous Offsets
////
#define DrawNetStatus                                      0x4B469C
#define CrashDetected                                      0x4C54FC
#define __ProcessGameEvents                                0x4AB12A
#define __ConvertItemTags                                  0x45A39C
#define __SendMessage                                      0x4B9BE3
#define __NewUIINI                                         0x521DC5
#define __ExecuteCmd                                       0x44CBF7

// EQ_LoadingS
#define EQ_LoadingS__WriteTextHD                           0x43238E


////
// Section 4: Function Offsets
////
// CEverQuest
#define CEverQuest__dsp_chat                               0x49B275
#define CEverQuest__ClickedPlayer                          0x4985D0
#define CEverQuest__EnterZone                              0x49BF96
#define CEverQuest__GetBodyTypeDesc                        0x4923EB
#define CEverQuest__GetClassDesc                           0x491E6D
#define CEverQuest__GetClassThreeLetterCode                0x492288
#define CEverQuest__GetDeityDesc                           0x493E7E
#define CEverQuest__GetRaceDesc                            0x4926F0
#define CEverQuest__InterpretCmd                           0x4A7B7A
#define CEverQuest__LeftClickedOnPlayer                    0x4A9D40
#define CEverQuest__RightClickedOnPlayer                   0x4A3A74
#define CEverQuest__SetGameState                           0x498737

// CXWndManager
#define CXWndManager__RemoveWnd                            0x56EEC0
#define CXWndManager__GetKeyboardFlags                     0x56EAE0
#define CXWndManager__HandleKeyboardMsg                    0x56EFB0

// KeyPressHandler
#define KeypressHandler__HandleKeyDown                     0x4AFA27
#define KeypressHandler__HandleKeyUp                       0x4AFCCB
#define KeypressHandler__AttachKeyToEqCommand              0x4B1089
#define KeypressHandler__AttachAltKeyToEqCommand           0x4B10C6
#define KeypressHandler__SaveKeymapping                    0x4B0F71
#define KeypressHandler__ClearCommandStateArray            0x4AFCBA

// EQ_Character
#define EQ_Character__Max_Mana                             0x420DD8
#define EQ_Character__Max_HP                               0x420C23
#define EQ_Character__Cur_HP                               0x42279E
#define EQ_Character__GetFocusCastingTimeModifier          0x42886D
#define EQ_Character__GetAACastingTimeModifier             0x428BFA
#define EQ_Character__CastSpell                            0x42C741

// EQPlayer
#define EQPlayer__EQPlayer                                 0x48748D
#define EQPlayer__dEQPlayer                                0x486D4A
#define EQPlayer__DoAttack                                 0x482F80

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr                                       0x4010C0
#define CXStr__CXStr1                                      0x50ED47
#define CXStr__CXStr3                                      0x59DF80
#define CXStr__dCXStr                                      0x4010EA
#define CXStr__operator_plus_equal1                        0x59F010
#define CXStr__operator_equal1                             0x59E140

// CChatWindow
#define CChatWindow__CChatWindow                           0x4E1AB8

// CChatManager
#define CChatManager__GetRGBAFromIndex                     0x4DE67C
#define CChatManager__InitContextMenu                      0x4DEFE0

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot                           0x4FBF55
#define CInvSlotMgr__MoveItem                              0x4FB904

// CItemDisplayWnd
#define CItemDisplayWnd__SetItem                           0x4FEC5B
#define CItemDisplayWnd__SetSpell                          0x4FE173

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton                         0x4F8972

// CLabel
#define CLabel__Draw                                       0x504CBD

// CDisplay
#define CDisplay__ReloadUI                                 0x41771E
#define CDisplay__CleanGameUI                              0x4100ED
#define CDisplay__GetClickedActor                          0x40D4F6
#define CDisplay__WriteTextHD2                             0x410B2A
#define CDisplay__GetWorldFilePath                         0x40BF24

// EQ_Item
#define EQ_Item__GetItemLinkHash                           0x431E94

// CBankWnd
#define CBankWnd__GetNumBankSlots                          0x4D04AF

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg                  0x4D2B64

// CMerchantWnd
#define CMerchantWnd__SelectBuySellSlot                    0x50D6AE
#define CMerchantWnd__RequestBuyItem                       0x50C8A1
#define CMerchantWnd__RequestSellItem                      0x50CC1F
#define CMerchantWnd__DisplayBuyOrSellPrice                0x50C6D6

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet                         0x51F055

// MapViewMap
#define MapViewMap__SaveEx                                 0x507ED2
#define MapViewMap__Clear                                  0x507D61


// CMapViewWnd
#define CMapViewWnd__CMapViewWnd                           0x50B797

// EQItemList
#define EQItemList__EQItemList                             0x44F3B8
#define EQItemList__dEQItemList                            0x44F434

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney                      0x434E5A

// CSidlScreenWnd
#define CSidlScreenWnd__CSidlScreenWnd1                    0x552E20
#define CSidlScreenWnd__dCSidlScreenWnd                    0x5524C0
#define CSidlScreenWnd__CreateChildrenFromSidl             0x551840
#define CSidlScreenWnd__GetChildItem                       0x551150
#define CSidlScreenWnd__WndNotification                    0x5513C0
#define CSidlScreenWnd__CalculateHSBRange                  0x5509E0
#define CSidlScreenWnd__CalculateVSBRange                  0x550920
#define CSidlScreenWnd__ConvertToRes                       0x5510D0
#define CSidlScreenWnd__CSidlScreenWnd2                    0x552F10
#define CSidlScreenWnd__DrawSidlPiece                      0x551460
#define CSidlScreenWnd__EnableIniStorage                   0x551080
#define CSidlScreenWnd__GetSidlPiece                       0x551700
#define CSidlScreenWnd__Init1                              0x552B70
#define CSidlScreenWnd__LoadIniInfo                        0x5518F0
#define CSidlScreenWnd__LoadIniListWnd                     0x552220
#define CSidlScreenWnd__LoadSidlScreen                     0x5512A0
#define CSidlScreenWnd__SetScreen                          0x5525E0
#define CSidlScreenWnd__StoreIniInfo                       0x550C10
#define CSidlScreenWnd__StoreIniListWnd                    0x5522D0

// CSidlManager
#define CSidlManager__FindScreenPieceTemplate1             0x577580

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead                       0x55ED60

// CXRect
#define CXRect__CenterPoint                                0x4D04B6

// CXWnd
#define CXWnd__Bottom                                      0x556DE0
#define CXWnd__BringToTop                                  0x5535A0
#define CXWnd__Center                                      0x556BA0
#define CXWnd__ClrFocus                                    0x5532F0
#define CXWnd__DoAllDrawing                                0x5577B0
#define CXWnd__DrawChildren                                0x5578E0
#define CXWnd__DrawColoredRect                             0x5537D0
#define CXWnd__DrawTooltipAtPoint                          0x5569D0
#define CXWnd__GetBorderFrame                              0x553C00
#define CXWnd__GetChildWndAt                               0x5565B0
#define CXWnd__GetClientClipRect                           0x553B50
#define CXWnd__GetFirstChildWnd                            0x553630
#define CXWnd__GetNextChildWnd                             0x556590
#define CXWnd__GetNextSib                                  0x553650
#define CXWnd__GetScreenClipRect                           0x556E30
#define CXWnd__GetScreenRect                               0x553DD0
#define CXWnd__GetTooltipRect                              0x556920
#define CXWnd__GetWindowTextA                              0x4CAF69
#define CXWnd__GetXMLTooltip                               0x553130
#define CXWnd__IsActive                                    0x553BC0
#define CXWnd__IsDescendantOf                              0x553BD0
#define CXWnd__IsReallyVisible                             0x556570
#define CXWnd__IsType                                      0x557750
#define CXWnd__Left                                        0x556C60
#define CXWnd__Move                                        0x556120
#define CXWnd__Move1                                       0x5561B0
#define CXWnd__ProcessTransition                           0x553560
#define CXWnd__Refade                                      0x553390
#define CXWnd__Resize                                      0x556F70
#define CXWnd__Right                                       0x556D10
#define CXWnd__SetFirstChildPointer                        0x554020
#define CXWnd__SetFocus                                    0x555300
#define CXWnd__SetKeyTooltip                               0x554060
#define CXWnd__SetMouseOver                                0x554040
#define CXWnd__SetNextSibPointer                           0x554030
#define CXWnd__StartFade                                   0x5535C0

// CSliderWnd
#define CSliderWnd__GetValue                               0x582DE0
#define CSliderWnd__SetValue                               0x582FC0
#define CSliderWnd__UpdateThumb                            0x582DA0

// CEditBaseWnd
#define CEditBaseWnd__SetMaxChars                          0x4D0025
#define CEditBaseWnd__SetSel                               0x579520

// CComboWnd
#define CComboWnd__DeleteAll                               0x57E500
#define CComboWnd__Draw                                    0x57E700
#define CComboWnd__GetButtonRect                           0x57E530
#define CComboWnd__GetCurChoice                            0x57E4C0
#define CComboWnd__GetListRect                             0x57EAF0
#define CComboWnd__GetTextRect                             0x57E590
#define CComboWnd__InsertChoice                            0x57EB50
#define CComboWnd__SetColors                               0x57E490
#define CComboWnd__SetChoice                               0x57EC30

// CListWnd
#define CListWnd__AddColumn                                0x56D7D0
#define CListWnd__AddColumn1                               0x56D330
#define CListWnd__AddLine                                  0x56CEF0
#define CListWnd__AddString                                0x56D070
#define CListWnd__CalculateFirstVisibleLine                0x56A520
#define CListWnd__CalculateLineHeights                     0x56A4C0
#define CListWnd__CalculateVSBRange                        0x56C090
#define CListWnd__ClearAllSel                              0x569D50
#define CListWnd__CloseAndUpdateEditWindow                 0x56AB20
#define CListWnd__Compare                                  0x56AE60
#define CListWnd__Draw                                     0x56BCF0
#define CListWnd__DrawColumnSeparators                     0x56BB50
#define CListWnd__DrawHeader                               0x569F70
#define CListWnd__DrawItem                                 0x56B570
#define CListWnd__DrawLine                                 0x56B8C0
#define CListWnd__DrawSeparator                            0x56BC20
#define CListWnd__EnsureVisible                            0x56A570
#define CListWnd__ExtendSel                                0x56B4A0
#define CListWnd__GetColumnFlags                           0x569820
#define CListWnd__GetColumnJustification                   0x5699C0
#define CListWnd__GetColumnMinWidth                        0x569950
#define CListWnd__GetColumnWidth                           0x569880
#define CListWnd__GetCurSel                                0x569660
#define CListWnd__GetHeaderRect                            0x5694A0
#define CListWnd__GetItemAtPoint                           0x56A820
#define CListWnd__GetItemAtPoint1                          0x56A890
#define CListWnd__GetItemData                              0x5696A0
#define CListWnd__GetItemHeight                            0x56A350
#define CListWnd__GetItemIcon                              0x569760
#define CListWnd__GetItemRect                              0x56A640
#define CListWnd__GetItemText                              0x5696E0
#define CListWnd__GetSelList                               0x56D210
#define CListWnd__GetSeparatorRect                         0x56ADB0
#define CListWnd__IsLineEnabled                            0x569E40
#define CListWnd__RemoveLine                               0x56D1C0
#define CListWnd__SetColors                                0x569410
#define CListWnd__SetColumnWidth                           0x569900
#define CListWnd__SetColumnJustification                   0x569A20
#define CListWnd__SetCurSel                                0x569C70
#define CListWnd__SetItemColor                             0x56CB30
#define CListWnd__SetItemData                              0x569E00
#define CListWnd__SetItemText                              0x56CA70
#define CListWnd__ShiftColumnSeparator                     0x56B410
#define CListWnd__Sort                                     0x56D870
#define CListWnd__ToggleSel                                0x569C90

// CEditWnd
#define CEditWnd__DrawCaret                                0x57EF90
#define CEditWnd__DrawMultiline                            0x5804A0
#define CEditWnd__GetCaretPt                               0x580850 
#define CEditWnd__GetCharIndexPt                           0x57FDA0
#define CEditWnd__GetDisplayString                         0x57F0C0
#define CEditWnd__GetHorzOffset                            0x57F330
#define CEditWnd__GetLineForPrintableChar                  0x57F850
#define CEditWnd__GetSelEndPt                              0x57FFE0
#define CEditWnd__GetSelStartPt                            0x57FFC0
#define CEditWnd__GetSTMLSafeText                          0x57F510
#define CEditWnd__PointFromPrintableChar                   0x57F960
#define CEditWnd__SelectableCharFromPoint                  0x57FAE0
#define CEditWnd__SetEditable                              0x57F4E0

// CGaugeWnd
#define CGaugeWnd__CalcFillRect                            0x4ED3CB
#define CGaugeWnd__CalcLinesFillRect                       0x4ED427
#define CGaugeWnd__Draw                                    0x4ED727

// CStmlWnd
#define CStmlWnd__AppendSTML                               0x568920
#define CStmlWnd__CalculateHSBRange                        0x5603A0
#define CStmlWnd__CalculateVSBRange                        0x560340
#define CStmlWnd__CanBreakAtCharacter                      0x5604E0
#define CStmlWnd__CanGoBackward                            0x560560
#define CStmlWnd__FastForwardPastSpaces                    0x560F30
#define CStmlWnd__FastForwardToEndOfTag                    0x561290
#define CStmlWnd__GetNextChar                              0x5609B0
#define CStmlWnd__GetNextTagPiece                          0x5610A0
#define CStmlWnd__GetSTMLText                              0x4E1A9A
#define CStmlWnd__GetThisChar                              0x560200
#define CStmlWnd__GetVisiableText                          0x562A60
#define CStmlWnd__InitializeTempVariables                  0x5601B0
#define CStmlWnd__InitializeWindowVariables                0x5647F0
#define CStmlWnd__MakeStmlColorTag                         0x55F9B0
#define CStmlWnd__MakeWndNotificationTag                   0x55FA50
#define CStmlWnd__StripFirstSTMLLines                      0x5686A0
#define CStmlWnd__UpdateHistoryString                      0x562EA0

// CTabWnd
#define CTabWnd__Draw                                      0x57E1E0
#define CTabWnd__DrawCurrentPage                           0x57DCD0
#define CTabWnd__DrawTab                                   0x57DA50
#define CTabWnd__GetCurrentPage                            0x57D600
#define CTabWnd__GetCurrentTabIndex                        0x57D3A0
#define CTabWnd__GetNumTabs                                0x57D4D0
#define CTabWnd__GetPageClientRect                         0x57D3B0
#define CTabWnd__GetPageFromTabIndex                       0x57D500
#define CTabWnd__GetPageInnerRect                          0x57D410
#define CTabWnd__GetTabInnerRect                           0x57D710
#define CTabWnd__GetTabRect                                0x57D610
#define CTabWnd__IndexInBounds                             0x57D4E0
#define CTabWnd__InsertPage                                0x57E0D0
#define CTabWnd__SetPage                                   0x57D7B0
#define CTabWnd__SetPageRect                               0x57D8C0
#define CTabWnd__UpdatePage                                0x57D970

// CTextOverlay
#define CTextOverlay__DisplayText                          0x401406
