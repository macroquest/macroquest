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
//.rdata:005DC16C aMar292004      db 'Mar 29 2004',0
//.rdata:005DC178 a180434         db '18:04:34',0
#define __ExpectedVersionDate                         "Mar 29 2004"
#define __ExpectedVersionTime                         "18:04:34"
#define __ActualVersionDate                                0x5DC16C
#define __ActualVersionTime                                0x5DC178

#define __ClientOverride                       0
#define __MacroQuestWinClassName                 "__MacroQuestTray"
#define __MacroQuestWinName                           "MacroQuest"

// Memory Protection
#define __MemChecker0                                      0x4BF064
#define __MemChecker1                                      0x4C39E5
#define __MemChecker2                                      0x4C57C2
#define __MemChecker3                                      0x4C585F
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
#define DrawNetStatus                                      0x4B467E
#define CrashDetected                                      0x4C54C0
#define __ProcessGameEvents                                0x4AB08F
#define __ConvertItemTags                                  0x45A2D5
#define __SendMessage                                      0x4B9E0D
#define __NewUIINI                                         0x521E12
#define __ExecuteCmd                                       0x44CB30

// EQ_LoadingS
#define EQ_LoadingS__WriteTextHD                           0x432283


////
// Section 4: Function Offsets
////
// CEverQuest
#define CEverQuest__dsp_chat                               0x49B1DA
#define CEverQuest__ClickedPlayer                          0x498535
#define CEverQuest__EnterZone                              0x49BEFB
#define CEverQuest__GetBodyTypeDesc                        0x492350
#define CEverQuest__GetClassDesc                           0x491DD2
#define CEverQuest__GetClassThreeLetterCode                0x4921ED
#define CEverQuest__GetDeityDesc                           0x493DE3
#define CEverQuest__GetRaceDesc                            0x492655
#define CEverQuest__InterpretCmd                           0x4A7ADF
#define CEverQuest__LeftClickedOnPlayer                    0x4A9CA5
#define CEverQuest__RightClickedOnPlayer                   0x4A39D9
#define CEverQuest__SetGameState                           0x49869C

// CXWndManager
#define CXWndManager__RemoveWnd                            0x56EF60
#define CXWndManager__GetKeyboardFlags                     0x56EB80
#define CXWndManager__HandleKeyboardMsg                    0x56F050

// KeyPressHandler
#define KeypressHandler__HandleKeyDown                     0x4AFA09
#define KeypressHandler__HandleKeyUp                       0x4AFCAD
#define KeypressHandler__AttachKeyToEqCommand              0x4B106B
#define KeypressHandler__AttachAltKeyToEqCommand           0x4B10A8
#define KeypressHandler__SaveKeymapping                    0x4B0F53
#define KeypressHandler__ClearCommandStateArray            0x4AFC9C

// EQ_Character
#define EQ_Character__Max_Mana                             0x420D4A
#define EQ_Character__Max_HP                               0x420B95
#define EQ_Character__Cur_HP                               0x422710
#define EQ_Character__GetFocusCastingTimeModifier          0x4287DF
#define EQ_Character__GetAACastingTimeModifier             0x428B6C
#define EQ_Character__CastSpell                            0x42C6B3

// EQPlayer
#define EQPlayer__EQPlayer                                 0x487410
#define EQPlayer__dEQPlayer                                0x486CCD
#define EQPlayer__DoAttack                                 0x482F03

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr                                       0x4010C0
#define CXStr__CXStr1                                      0x50EDD7
#define CXStr__CXStr3                                      0x59DF40
#define CXStr__dCXStr                                      0x4010EA
#define CXStr__operator_plus_equal1                        0x59EFD0
#define CXStr__operator_equal1                             0x59E100

// CChatWindow
#define CChatWindow__CChatWindow                           0x4E1AC8

// CChatManager
#define CChatManager__GetRGBAFromIndex                     0x4DE68C
#define CChatManager__InitContextMenu                      0x4DEFF0

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot                           0x4FBFED
#define CInvSlotMgr__MoveItem                              0x4FB99C

// CItemDisplayWnd
#define CItemDisplayWnd__SetItem                           0x4FECEE
#define CItemDisplayWnd__SetSpell                          0x4FE20B

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton                         0x4F8A12

// CLabel
#define CLabel__Draw                                       0x504D4D

// CDisplay
#define CDisplay__ReloadUI                                 0x417695
#define CDisplay__CleanGameUI                              0x41005C
#define CDisplay__GetClickedActor                          0x40D465
#define CDisplay__WriteTextHD2                             0x410A99
#define CDisplay__GetWorldFilePath                         0x40BE93

// EQ_Item
#define EQ_Item__GetItemLinkHash                           0x431D89

// CBankWnd
#define CBankWnd__GetNumBankSlots                          0x4D04CD

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg                  0x4D2B82

// CMerchantWnd
#define CMerchantWnd__SelectBuySellSlot                    0x50D73E
#define CMerchantWnd__RequestBuyItem                       0x50C931
#define CMerchantWnd__RequestSellItem                      0x50CCAF
#define CMerchantWnd__DisplayBuyOrSellPrice                0x50C766

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet                         0x51F0A2

// MapViewMap
#define MapViewMap__SaveEx                                 0x507F62
#define MapViewMap__Clear                                  0x507DF1


// CMapViewWnd
#define CMapViewWnd__CMapViewWnd                           0x50B827

// EQItemList
#define EQItemList__EQItemList                             0x44F2F1
#define EQItemList__dEQItemList                            0x44F36D

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney                      0x434D4C

// CSidlScreenWnd
#define CSidlScreenWnd__CSidlScreenWnd1                    0x552E70
#define CSidlScreenWnd__dCSidlScreenWnd                    0x552510
#define CSidlScreenWnd__CreateChildrenFromSidl             0x551890
#define CSidlScreenWnd__GetChildItem                       0x551110
#define CSidlScreenWnd__WndNotification                    0x551410
#define CSidlScreenWnd__CalculateHSBRange                  0x5509A0
#define CSidlScreenWnd__CalculateVSBRange                  0x5508E0
#define CSidlScreenWnd__ConvertToRes                       0x551090
#define CSidlScreenWnd__CSidlScreenWnd2                    0x552F60
#define CSidlScreenWnd__DrawSidlPiece                      0x5514B0
#define CSidlScreenWnd__EnableIniStorage                   0x551040
#define CSidlScreenWnd__GetSidlPiece                       0x551750
#define CSidlScreenWnd__Init1                              0x552BC0
#define CSidlScreenWnd__LoadIniInfo                        0x551940
#define CSidlScreenWnd__LoadIniListWnd                     0x552270
#define CSidlScreenWnd__LoadSidlScreen                     0x5512F0
#define CSidlScreenWnd__SetScreen                          0x552630
#define CSidlScreenWnd__StoreIniInfo                       0x550BD0
#define CSidlScreenWnd__StoreIniListWnd                    0x552320

// CSidlManager
#define CSidlManager__FindScreenPieceTemplate1             0x5775D0

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead                       0x55EE00

// CXRect
#define CXRect__CenterPoint                                0x4D04D4

// CXWnd
#define CXWnd__Bottom                                      0x556E40
#define CXWnd__BringToTop                                  0x553600
#define CXWnd__Center                                      0x556C00
#define CXWnd__ClrFocus                                    0x553340
#define CXWnd__DoAllDrawing                                0x557810
#define CXWnd__DrawChildren                                0x557940
#define CXWnd__DrawColoredRect                             0x553830
#define CXWnd__DrawTooltipAtPoint                          0x556A30
#define CXWnd__GetBorderFrame                              0x553C60
#define CXWnd__GetChildWndAt                               0x556610
#define CXWnd__GetClientClipRect                           0x553BB0
#define CXWnd__GetFirstChildWnd                            0x553690
#define CXWnd__GetNextChildWnd                             0x5565F0
#define CXWnd__GetNextSib                                  0x5536B0
#define CXWnd__GetScreenClipRect                           0x556E90
#define CXWnd__GetScreenRect                               0x553E30
#define CXWnd__GetTooltipRect                              0x556980
#define CXWnd__GetWindowTextA                              0x4CAF2D
#define CXWnd__GetXMLTooltip                               0x553180
#define CXWnd__IsActive                                    0x553C20
#define CXWnd__IsDescendantOf                              0x553C30
#define CXWnd__IsReallyVisible                             0x5565D0
#define CXWnd__IsType                                      0x5577B0
#define CXWnd__Left                                        0x556CC0
#define CXWnd__Move                                        0x556180
#define CXWnd__Move1                                       0x556210
#define CXWnd__ProcessTransition                           0x5535C0
#define CXWnd__Refade                                      0x5533F0
#define CXWnd__Resize                                      0x556FD0
#define CXWnd__Right                                       0x556D70
#define CXWnd__SetFirstChildPointer                        0x554080
#define CXWnd__SetFocus                                    0x555360
#define CXWnd__SetKeyTooltip                               0x5540C0
#define CXWnd__SetMouseOver                                0x5540A0
#define CXWnd__SetNextSibPointer                           0x554090
#define CXWnd__StartFade                                   0x553620

// CSliderWnd
#define CSliderWnd__GetValue                               0x582DC0
#define CSliderWnd__SetValue                               0x582FA0
#define CSliderWnd__UpdateThumb                            0x582D80

// CEditBaseWnd
#define CEditBaseWnd__SetMaxChars                          0x4D0043
#define CEditBaseWnd__SetSel                               0x579550

// CComboWnd
#define CComboWnd__DeleteAll                               0x57E4F0
#define CComboWnd__Draw                                    0x57E6F0
#define CComboWnd__GetButtonRect                           0x57E520
#define CComboWnd__GetCurChoice                            0x57E4B0
#define CComboWnd__GetListRect                             0x57EAE0
#define CComboWnd__GetTextRect                             0x57E580
#define CComboWnd__InsertChoice                            0x57EB40
#define CComboWnd__SetColors                               0x57E480
#define CComboWnd__SetChoice                               0x57EC20

// CListWnd
#define CListWnd__AddColumn                                0x56D880
#define CListWnd__AddColumn1                               0x56D3E0
#define CListWnd__AddLine                                  0x56CFA0
#define CListWnd__AddString                                0x56D120
#define CListWnd__CalculateFirstVisibleLine                0x56A5D0
#define CListWnd__CalculateLineHeights                     0x56A570
#define CListWnd__CalculateVSBRange                        0x56C140
#define CListWnd__ClearAllSel                              0x569E00
#define CListWnd__CloseAndUpdateEditWindow                 0x56ABD0
#define CListWnd__Compare                                  0x56AF10
#define CListWnd__Draw                                     0x56BDA0
#define CListWnd__DrawColumnSeparators                     0x56BC00
#define CListWnd__DrawHeader                               0x56A020
#define CListWnd__DrawItem                                 0x56B620
#define CListWnd__DrawLine                                 0x56B970
#define CListWnd__DrawSeparator                            0x56BCD0
#define CListWnd__EnsureVisible                            0x56A620
#define CListWnd__ExtendSel                                0x56B550
#define CListWnd__GetColumnFlags                           0x5698D0
#define CListWnd__GetColumnJustification                   0x569A70
#define CListWnd__GetColumnMinWidth                        0x569A00
#define CListWnd__GetColumnWidth                           0x569930
#define CListWnd__GetCurSel                                0x569710
#define CListWnd__GetHeaderRect                            0x569550
#define CListWnd__GetItemAtPoint                           0x56A8D0
#define CListWnd__GetItemAtPoint1                          0x56A940
#define CListWnd__GetItemData                              0x569750
#define CListWnd__GetItemHeight                            0x56A400
#define CListWnd__GetItemIcon                              0x569810
#define CListWnd__GetItemRect                              0x56A6F0
#define CListWnd__GetItemText                              0x569790
#define CListWnd__GetSelList                               0x56D2C0
#define CListWnd__GetSeparatorRect                         0x56AE60
#define CListWnd__IsLineEnabled                            0x569EF0
#define CListWnd__RemoveLine                               0x56D270
#define CListWnd__SetColors                                0x5694C0
#define CListWnd__SetColumnWidth                           0x5699B0
#define CListWnd__SetColumnJustification                   0x569AD0
#define CListWnd__SetCurSel                                0x569D20
#define CListWnd__SetItemColor                             0x56CBE0
#define CListWnd__SetItemData                              0x569EB0
#define CListWnd__SetItemText                              0x56CB20
#define CListWnd__ShiftColumnSeparator                     0x56B4C0
#define CListWnd__Sort                                     0x56D920
#define CListWnd__ToggleSel                                0x569D40

// CEditWnd
#define CEditWnd__DrawCaret                                0x57EF80
#define CEditWnd__DrawMultiline                            0x580490
#define CEditWnd__GetCaretPt                               0x580840
#define CEditWnd__GetCharIndexPt                           0x57FD90
#define CEditWnd__GetDisplayString                         0x57F0B0
#define CEditWnd__GetHorzOffset                            0x57F320
#define CEditWnd__GetLineForPrintableChar                  0x57F840
#define CEditWnd__GetSelEndPt                              0x57FFD0
#define CEditWnd__GetSelStartPt                            0x57FFB0
#define CEditWnd__GetSTMLSafeText                          0x57F500
#define CEditWnd__PointFromPrintableChar                   0x57F950
#define CEditWnd__SelectableCharFromPoint                  0x57FAD0
#define CEditWnd__SetEditable                              0x57F4D0

// CGaugeWnd
#define CGaugeWnd__CalcFillRect                            0x4ED3EB
#define CGaugeWnd__CalcLinesFillRect                       0x4ED447
#define CGaugeWnd__Draw                                    0x4ED747

// CStmlWnd
#define CStmlWnd__AppendSTML                               0x5689D0
#define CStmlWnd__CalculateHSBRange                        0x5604A0
#define CStmlWnd__CalculateVSBRange                        0x560440
#define CStmlWnd__CanBreakAtCharacter                      0x5605E0
#define CStmlWnd__CanGoBackward                            0x560660
#define CStmlWnd__FastForwardPastSpaces                    0x560FE0
#define CStmlWnd__FastForwardToEndOfTag                    0x561340
#define CStmlWnd__GetNextChar                              0x560AA0
#define CStmlWnd__GetNextTagPiece                          0x561150
#define CStmlWnd__GetSTMLText                              0x4E1AAA
#define CStmlWnd__GetThisChar                              0x560300
#define CStmlWnd__GetVisiableText                          0x562B10
#define CStmlWnd__InitializeTempVariables                  0x5602B0
#define CStmlWnd__InitializeWindowVariables                0x5648A0
#define CStmlWnd__MakeStmlColorTag                         0x55FA90
#define CStmlWnd__MakeWndNotificationTag                   0x55FB30
#define CStmlWnd__StripFirstSTMLLines                      0x568750
#define CStmlWnd__UpdateHistoryString                      0x562F50

// CTabWnd
#define CTabWnd__Draw                                      0x57E1D0
#define CTabWnd__DrawCurrentPage                           0x57DCC0
#define CTabWnd__DrawTab                                   0x57DA40
#define CTabWnd__GetCurrentPage                            0x57D5F0
#define CTabWnd__GetCurrentTabIndex                        0x57D390
#define CTabWnd__GetNumTabs                                0x57D4C0
#define CTabWnd__GetPageClientRect                         0x57D3A0
#define CTabWnd__GetPageFromTabIndex                       0x57D4F0
#define CTabWnd__GetPageInnerRect                          0x57D400
#define CTabWnd__GetTabInnerRect                           0x57D700
#define CTabWnd__GetTabRect                                0x57D600
#define CTabWnd__IndexInBounds                             0x57D4D0
#define CTabWnd__InsertPage                                0x57E0C0
#define CTabWnd__SetPage                                   0x57D7A0
#define CTabWnd__SetPageRect                               0x57D8B0
#define CTabWnd__UpdatePage                                0x57D960

// CTextOverlay
#define CTextOverlay__DisplayText                          0x401406
