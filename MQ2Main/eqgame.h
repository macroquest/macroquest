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
//.rdata:005DB174 aMar242004      db 'Mar 24 2004',0
//.rdata:005DB180 a184103         db '18:41:03',0
#define __ExpectedVersionDate                         "Mar 24 2004"
#define __ExpectedVersionTime                         "18:41:03"
#define __ActualVersionDate                                0x5DB174
#define __ActualVersionTime                                0x5DB180

#define __ClientOverride                       0
#define __MacroQuestWinClassName                 "__MacroQuestTray"
#define __MacroQuestWinName                           "MacroQuest"

// Memory Protection
#define __MemChecker0                                      0x4BEFAE
#define __MemChecker1                                      0x4C39B6
#define __MemChecker2                                      0x4C578D
#define __MemChecker3                                      0x4C582A
#define __EncryptPad0                                      0x6119C0
#define __EncryptPad1                                      0x611DC0
#define __EncryptPad2                                      0x612878
#define __EncryptPad3                                      0x612C78

#define DI8__Main                                          0x78EEEC
#define DI8__Keyboard                                      0x78EEF0
#define DI8__Mouse                                         0x78EEF4

#define __LastTell                                         0x6D0E9C
#define __Guilds                                           0x731558
#define __Mouse                                            0x78EEF8
#define __Attack                                           0x72F6CE
#define __InChatMode                                       0x6CEDD0
#define __gWorld                                           0x7314B0
#define __GroupCount                                       0x72FA60
#define __CommandList                                      0x60B730
#define __DoAbilityList                                    0x708970
#define __DoAbilityAvailable                               0x6CFBC4
#define __ServerHost                                       0x72F91C
#define __ServerName                                       0x708930
#define __HWnd                                             0x6CED90
#define __Clicks                                           0x6CEE90
#define __ScreenX                                          0x6CED98
#define __ScreenY                                          0x6CED9C
#define __EQP_IDArray                                      0x6CBE58
#define __CurrentMapLabel                                  0x797D54
#define __BindList                                         0x60B220
#define __RangeAttackReady                                 0x6CFC28
#define __Socials                                          0x708A30
#define __HotkeyPage									   0x72F2D0
#define __CurrentSocial									   0x607A9C
////
//Section 1: Vital Offsets
////
#define pinstCSidlManager                                  0x7A30C4
#define pinstCDisplay                                      0x73153C
#define pinstCEverQuest                                    0x78F060
#define pinstPCData                                        0x731518
#define pinstCharData                                      0x731518
#define pinstCharSpawn                                     0x731510
#define pinstSpawnList                                     0x7314D8
#define pinstLocalPlayer                                   0x7314FC
#define pinstControlledPlayer                              0x731510
#define pinstWorldData                                     0x7314D4
#define pinstSpellManager                                  0x78BAB4
#define pinstTradeTarget								   0x7314F8
#define pinstActiveMerchant                                0x731528
#define pinstActiveBanker								   0x73152C
#define pinstActiveCorpse								   0x731530
#define pinstActiveGMaster								   0x731534
#define pinstSelectedItem                                  0x797C70
#define pinstGroup                                         0x72FBA8
#define pinstTarget                                        0x73151C
#define pinstSwitchManager                                 0x6CED80
#define pinstEQItemList                                    0x7314DC
#define pinstSpellSets                                     0x72F2D4
#define instEQZoneInfo                                     0x6CF004
#define pinstCXWndManager                                  0x7A30BC
#define instKeypressHandler                                0x77E300


////
//Section 2:  UI Related Offsets
////
#define pinstCTextOverlay                                  0x61B0A0
#define pinstCharacterSelect                               0x61BD04
#define pinstCFacePick                                     0x61BD08
#define pinstTextMessageWnd                                0x61BD0C
#define pinstCNoteWnd                                      0x61BD10
#define pinstCHelpWnd                                      0x61BD14
#define pinstCBookWnd                                      0x61BD18
#define pinstCPetInfoWnd                                   0x61BD1C
#define pinstCTrainWnd                                     0x61BD20
#define pinstCSkillsWnd                                    0x61BD24
#define pinstCSkillsSelectWnd                              0x61BD28
#define pinstCCombatSkillSelectWnd                         0x61BD2C
#define pinstCFriendsWnd                                   0x61BD30
#define pinstCAAWnd                                        0x61BD34
#define pinstCGroupSearchFiltersWnd                        0x61BD38
#define pinstCLoadskinWnd                                  0x61BD3C
#define pinstCAlarmWnd                                     0x61BD40
#define pinstCMusicPlayerWnd                               0x61BD44
#define pinstCRaidWnd                                      0x61BD48
#define pinstCRaidOptionsWnd                               0x61BD4C
#define pinstCBreathWnd                                    0x61BD50
#define pinstCMapViewWnd                                   0x61BD54
#define pinstCMapToolbarWnd                                0x61BD58
#define pinstCEditLabelWnd                                 0x61BD5C
#define pinstCTargetWnd                                    0x61BD60
#define pinstCHotButtonWnd                                 0x61BD64
#define pinstCColorPickerWnd                               0x61BD68
#define pinstCPlayerWnd                                    0x61BD6C
#define pinstCOptionsWnd                                   0x61BD70
#define pinstCBuffWindowNORMAL                             0x61BD74
#define pinstCBuffWindowSHORT                              0x61BD78
#define pinstCharacterCreation                             0x61BD7C
#define pinstCCursorAttachment                             0x61BD80
#define pinstCCastingWnd                                   0x61BD84
#define pinstCCastSpellWnd                                 0x61BD88
#define pinstCSpellBookWnd                                 0x61BD8C
#define pinstCInventoryWnd                                 0x61BD90
#define pinstCBankWnd                                      0x61BD94
#define pinstCQuantityWnd                                  0x61BD98
#define pinstCLootWnd                                      0x61BD9C
#define pinstCActionsWnd                                   0x61BDA0
#define pinstCCombatAbilityWnd                             0x61BDA4
#define pinstCMerchantWnd                                  0x61BDA8
#define pinstCTradeWnd                                     0x61BDAC
#define pinstCSelectorWnd                                  0x61BDB0
#define pinstCBazaarWnd                                    0x61BDB4
#define pinstCBazaarSearchWnd                              0x61BDB8
#define pinstCGiveWnd                                      0x61BDBC
#define pinstCTrackingWnd                                  0x61BDC0
#define pinstCInspectWnd                                   0x61BDC4
#define pinstCSocialEditWnd                                0x61BDC8
#define pinstCFeedbackWnd                                  0x61BDCC
#define pinstCBugReportWnd                                 0x61BDD0
#define pinstCVideoModesWnd                                0x61BDD4
#define pinstCTextEntryWnd                                 0x61BDD8
#define pinstCFileSelectionWnd                             0x61BDDC
#define pinstCCompassWnd                                   0x61BDE0
#define pinstCPlayerNotesWnd                               0x61BDE4
#define pinstCGemsGameWnd                                  0x61BDE8
#define pinstCTimeLeftWnd                                  0x61BDEC
#define pinstCPetitionQWnd                                 0x61BDF0
#define pinstCSoulmarkWnd                                  0x61BDF4
#define pinstCStoryWnd                                     0x61BDF8
#define pinstCJournalTextWnd                               0x61BDFC
#define pinstCJournalCatWnd                                0x61BE00
#define pinstCBodyTintWnd                                  0x61BE04
#define pinstCInvSlotMgr                                   0x61BE08
#define pinstCContainerMgr                                 0x61BE0C
#define pinstCAdventureLeaderboardWnd                      0x797740
#define pinstCAdventureMerchantWnd                         0x797758
#define pinstCAdventureRequestWnd                          0x797770
#define pinstCAdventureStatsWnd                            0x797788
#define pinstCChatManager                                  0x797A00
#define pinstCDynamicZoneWnd                               0x797AB8
#define pinstCFindLocationWnd                              0x797B48
#define pinstCGroupSearchWnd                               0x797BC4
#define pinstCGroupWnd                                     0x797BDC
#define pinstCGuildMgmtWnd                                 0x797BF4
#define pinstCItemDisplayManager                     0x797C9C
#define pinstCLeadershipWnd                                0x797CF0
#define pinstCPopupWndManager                              0x797E40
#define pinstCSystemInfoDialogBox                          0x7986BC
#define pinstCTargetOfTargetWnd                            0x7986D4
#define pinstCTipWndOFDAY                                  0x79873C
#define pinstCTipWndCONTEXT                                0x798740
#define pinstCTradeskillWnd                                0x79876C
#define pinstCTributeBenefitWnd                            0x7987AC
#define pinstCTributeMasterWnd                             0x7987C4
#define pinstCContextMenuManager                           0x7A30E0


////
// Section 3: Miscellaneous Offsets
////
#define DrawNetStatus                                      0x4B45C5
#define CrashDetected                                      0x4C548B
#define __ProcessGameEvents                                0x4AB0A3
#define __ConvertItemTags                                  0x45A393
#define __SendMessage                                      0x4B9D7F
#define __NewUIINI                                         0x521CF5
#define __ExecuteCmd                                       0x44CBEE

// EQ_LoadingS
#define EQ_LoadingS__WriteTextHD                           0x4322E6


////
// Section 4: Function Offsets
////
// CEverQuest
#define CEverQuest__dsp_chat                               0x49B1EE
#define CEverQuest__ClickedPlayer                          0x498549
#define CEverQuest__EnterZone                              0x49BF0F
#define CEverQuest__GetBodyTypeDesc                        0x492364
#define CEverQuest__GetClassDesc                           0x491DE6
#define CEverQuest__GetClassThreeLetterCode                0x492201
#define CEverQuest__GetDeityDesc                           0x493DF7
#define CEverQuest__GetRaceDesc                            0x492669
#define CEverQuest__InterpretCmd                           0x4A7AF3
#define CEverQuest__LeftClickedOnPlayer                    0x4A9CB9
#define CEverQuest__RightClickedOnPlayer                   0x4A39ED
#define CEverQuest__SetGameState                           0x4986B0

// CXWndManager
#define CXWndManager__RemoveWnd                            0x56EA10
#define CXWndManager__GetKeyboardFlags                     0x56E630
#define CXWndManager__HandleKeyboardMsg                    0x56EB00

// KeyPressHandler
#define KeypressHandler__HandleKeyDown                     0x4AF994
#define KeypressHandler__HandleKeyUp                       0x4AFC38
#define KeypressHandler__AttachKeyToEqCommand              0x4B0FF6
#define KeypressHandler__AttachAltKeyToEqCommand           0x4B1033
#define KeypressHandler__SaveKeymapping                    0x4B0EDE
#define KeypressHandler__ClearCommandStateArray            0x4AFC27

// EQ_Character
#define EQ_Character__Max_Mana                             0x420D67
#define EQ_Character__Max_HP                               0x420BB2
#define EQ_Character__Cur_HP                               0x42272D
#define EQ_Character__GetFocusCastingTimeModifier          0x4287F9
#define EQ_Character__GetAACastingTimeModifier             0x428B86
#define EQ_Character__CastSpell                            0x42C6CD

// EQPlayer
#define EQPlayer__EQPlayer                                 0x48745F
#define EQPlayer__dEQPlayer                                0x4861CD
#define EQPlayer__DoAttack                                 0x483164

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr                                       0x4010C0
#define CXStr__CXStr1                                      0x50EC6C
#define CXStr__CXStr3                                      0x59DA80
#define CXStr__dCXStr                                      0x4010EA
#define CXStr__operator_plus_equal1                        0x59EB10
#define CXStr__operator_equal1                             0x59DC40

// CChatWindow
#define CChatWindow__CChatWindow                           0x4E1AA3

// CChatManager
#define CChatManager__GetRGBAFromIndex                     0x4DE667
#define CChatManager__InitContextMenu                      0x4DEFCB

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot                           0x4FBEC9
#define CInvSlotMgr__MoveItem                              0x4FB878

// CItemDisplayWnd
#define CItemDisplayWnd__SetItem                           0x4FEBCA
#define CItemDisplayWnd__SetSpell                          0x4FE0E7

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton						   0x4F8902

// CLabel
#define CLabel__Draw                                       0x504C0C

// CDisplay
#define CDisplay__ReloadUI                                 0x417645
#define CDisplay__CleanGameUI                              0x41000C
#define CDisplay__GetClickedActor                          0x40D3FA
#define CDisplay__WriteTextHD2                             0x410A49
#define CDisplay__GetWorldFilePath                         0x40BE28

// EQ_Item
#define EQ_Item__GetItemLinkHash                           0x431DEC

// CBankWnd
#define CBankWnd__GetNumBankSlots                          0x4D043E

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg                  0x4D2AF3

// CMerchantWnd
#define CMerchantWnd__SelectBuySellSlot                    0x50D5D3
#define CMerchantWnd__RequestBuyItem                       0x50C7C6
#define CMerchantWnd__RequestSellItem                      0x50CB44
#define CMerchantWnd__DisplayBuyOrSellPrice                0x50C5FB

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet                         0x51EF80

// MapViewMap
#define MapViewMap__SaveEx                                 0x507E21
#define MapViewMap__Clear                                  0x507CB0


// CMapViewWnd
#define CMapViewWnd__CMapViewWnd                           0x50B6BC

// EQItemList
#define EQItemList__EQItemList                             0x44F3AF
#define EQItemList__dEQItemList                            0x44F42B

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney                      0x434DAF

// CSidlScreenWnd
#define CSidlScreenWnd__CSidlScreenWnd1                    0x552960
#define CSidlScreenWnd__dCSidlScreenWnd                    0x552000
#define CSidlScreenWnd__CreateChildrenFromSidl             0x551380
#define CSidlScreenWnd__GetChildItem                       0x550C90
#define CSidlScreenWnd__WndNotification                    0x550F00
#define CSidlScreenWnd__CalculateHSBRange                  0x550520
#define CSidlScreenWnd__CalculateVSBRange                  0x550460
#define CSidlScreenWnd__ConvertToRes                       0x550C10
#define CSidlScreenWnd__CSidlScreenWnd2                    0x552A50
#define CSidlScreenWnd__DrawSidlPiece                      0x550FA0
#define CSidlScreenWnd__EnableIniStorage                   0x550BC0
#define CSidlScreenWnd__GetSidlPiece                       0x551240
#define CSidlScreenWnd__Init1                              0x5526B0
#define CSidlScreenWnd__LoadIniInfo                        0x551430
#define CSidlScreenWnd__LoadIniListWnd                     0x551D60
#define CSidlScreenWnd__LoadSidlScreen                     0x550DE0
#define CSidlScreenWnd__SetScreen                          0x552120
#define CSidlScreenWnd__StoreIniInfo                       0x550750
#define CSidlScreenWnd__StoreIniListWnd                    0x551E10

// CSidlManager
#define CSidlManager__FindScreenPieceTemplate1             0x577110

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead                       0x55E8E0

// CXRect
#define CXRect__CenterPoint                                0x4D0445

// CXWnd
#define CXWnd__Bottom                                      0x556920
#define CXWnd__BringToTop                                  0x5530E0
#define CXWnd__Center                                      0x5566E0
#define CXWnd__ClrFocus                                    0x552E30
#define CXWnd__Deactivate                                  0x550740
#define CXWnd__DoAllDrawing                                0x5572F0
#define CXWnd__DrawChildren                                0x557420
#define CXWnd__DrawCloseBox                                0x554F50
#define CXWnd__DrawColoredRect                             0x553310
#define CXWnd__DrawCursor                                  0x552EA0
#define CXWnd__DrawHScrollbar                              0x555450
#define CXWnd__DrawLasso                                   0x556290
#define CXWnd__DrawMinimizeBox                             0x555030
#define CXWnd__DrawTileBox                                 0x555110
#define CXWnd__DrawTooltipAtPoint                          0x556510
#define CXWnd__DrawVScrollbar                              0x555850
#define CXWnd__GetBorderFrame                              0x553740
#define CXWnd__GetChildWndAt                               0x5560F0
#define CXWnd__GetClientClipRect                           0x553690
#define CXWnd__GetCloseBoxTemplate                         0x5537A0
#define CXWnd__GetFirstChildWnd                            0x553170
#define CXWnd__GetMinimizeBoxTemplate                      0x5537D0
#define CXWnd__GetNextChildWnd                             0x5560D0
#define CXWnd__GetNextSib                                  0x553190
#define CXWnd__GetScreenClipRect                           0x556970
#define CXWnd__GetScreenRect                               0x553910
#define CXWnd__GetTileBoxTemplate                          0x5537F0
#define CXWnd__GetTooltipRect                              0x556460
#define CXWnd__GetWindowTextA                              0x4CAEF8
#define CXWnd__GetXMLTooltip                               0x552C70
#define CXWnd__IsActive                                    0x553700
#define CXWnd__IsDescendantOf                              0x553710
#define CXWnd__IsReallyVisible                             0x5560B0
#define CXWnd__IsType                                      0x557290
#define CXWnd__Left                                        0x5567A0
#define CXWnd__Move                                        0x555C60
#define CXWnd__Move1                                       0x555CF0
#define CXWnd__ProcessTransition                           0x5530A0
#define CXWnd__Refade                                      0x552ED0
#define CXWnd__Resize                                      0x556AB0
#define CXWnd__Right                                       0x556850
#define CXWnd__SetFirstChildPointer                        0x553B60
#define CXWnd__SetFocus                                    0x554E40
#define CXWnd__SetKeyTooltip                               0x553BA0
#define CXWnd__SetMouseOver                                0x553B80
#define CXWnd__SetNextSibPointer                           0x553B70
#define CXWnd__StartFade                                   0x553100

// CSliderWnd
#define CSliderWnd__GetValue                               0x582930
#define CSliderWnd__SetValue                               0x582B10
#define CSliderWnd__UpdateThumb                            0x5828F0

// CEditBaseWnd
#define CEditBaseWnd__SetMaxChars                          0x4CFFB4
#define CEditBaseWnd__SetSel                               0x5790C0

// CComboWnd
#define CComboWnd__DeleteAll                               0x57E030
#define CComboWnd__Draw                                    0x57E230
#define CComboWnd__GetButtonRect                           0x57E060
#define CComboWnd__GetCurChoice                            0x57DFF0
#define CComboWnd__GetListRect                             0x57E620
#define CComboWnd__GetTextRect                             0x57E0C0
#define CComboWnd__HitTest                                   0x4D6CF8
#define CComboWnd__InsertChoice                            0x57E680
#define CComboWnd__SetColors                               0x57DFC0
#define CComboWnd__SetChoice                               0x57E760

// CListWnd
#define CListWnd__AddColumn								   0x56D320
#define CListWnd__AddColumn1							   0x59A650
#define CListWnd__AddLine                                  0x56CA40
#define CListWnd__AddString                                0x56CBC0
#define CListWnd__CalculateFirstVisibleLine                0x56A070
#define CListWnd__CalculateLineHeights                     0x56A010
#define CListWnd__CalculateVSBRange                        0x56BBE0
#define CListWnd__ClearAllSel                              0x5698A0
#define CListWnd__CloseAndUpdateEditWindow                 0x56A670
#define CListWnd__Compare                                  0x56A9B0
#define CListWnd__Draw                                     0x56B840
#define CListWnd__DrawColumnSeparators                     0x56B6A0
#define CListWnd__DrawHeader                               0x569AC0
#define CListWnd__DrawItem                                 0x56B0C0
#define CListWnd__DrawLine                                 0x56B410
#define CListWnd__DrawSeparator                            0x56B770
#define CListWnd__EnsureVisible                            0x56A0C0
#define CListWnd__ExtendSel                                0x56AFF0
#define CListWnd__GetColumnFlags                           0x569370
#define CListWnd__GetColumnJustification				   0x569510 
#define CListWnd__GetColumnMinWidth                        0x5694A0
#define CListWnd__GetColumnWidth                           0x5693D0
#define CListWnd__GetCurSel                                0x5691B0
#define CListWnd__GetHeaderRect                            0x568FF0
#define CListWnd__GetItemAtPoint                           0x56A370
#define CListWnd__GetItemAtPoint1                          0x56A3E0
#define CListWnd__GetItemData                              0x5691F0
#define CListWnd__GetItemHeight                            0x569EA0
#define CListWnd__GetItemIcon                              0x5692B0
#define CListWnd__GetItemRect                              0x56A190
#define CListWnd__GetItemText                              0x569230
#define CListWnd__GetSelList                               0x56CD60
#define CListWnd__GetSeparatorRect                         0x56A900
#define CListWnd__IsLineEnabled                            0x569990
#define CListWnd__RemoveLine							   0x56CD10
#define CListWnd__SetColors                                0x568F60
#define CListWnd__SetColumnWidth                           0x569450
#define CListWnd__SetColumnJustification				   0x569570 
#define CListWnd__SetCurSel                                0x5697C0
#define CListWnd__SetItemColor                             0x56C680
#define CListWnd__SetItemData                              0x569950
#define CListWnd__SetItemText                              0x56C5C0
#define CListWnd__ShiftColumnSeparator                     0x56AF60
#define CListWnd__Sort                                     0x578CD0
#define CListWnd__ToggleSel                                0x5697E0

// CEditWnd
#define CEditWnd__DrawCaret                                0x57EAC0
#define CEditWnd__DrawMultiline                            0x580000
#define CEditWnd__GetCaretPt                               0x5803B0
#define CEditWnd__GetCharIndexPt                           0x57F900
#define CEditWnd__GetDisplayString                         0x57EC20
#define CEditWnd__GetHorzOffset                            0x57EE90
#define CEditWnd__GetLineForPrintableChar                  0x57F3B0
#define CEditWnd__GetSelEndPt                              0x57FB40
#define CEditWnd__GetSelStartPt                            0x57FB20
#define CEditWnd__GetSTMLSafeText                          0x57F070
#define CEditWnd__PointFromPrintableChar                   0x57F4C0
#define CEditWnd__SelectableCharFromPoint                  0x57F640
#define CEditWnd__SetEditable                              0x57F040

// CGaugeWnd
#define CGaugeWnd__CalcFillRect                            0x4ED347
#define CGaugeWnd__CalcLinesFillRect                       0x4ED3A3
#define CGaugeWnd__Draw                                    0x4ED6A3

// CStmlWnd
#define CStmlWnd__AppendSTML                               0x568470
#define CStmlWnd__CalculateHSBRange                        0x55FF40
#define CStmlWnd__CalculateVSBRange                        0x55FEE0
#define CStmlWnd__CanBreakAtCharacter                      0x560080
#define CStmlWnd__CanGoBackward                            0x560100
#define CStmlWnd__FastForwardPastSpaces                    0x560A80
#define CStmlWnd__FastForwardToEndOfTag                    0x560DE0
#define CStmlWnd__GetNextChar                              0x560540
#define CStmlWnd__GetNextTagPiece                          0x560BF0
#define CStmlWnd__GetSTMLText                              0x4E1A85
#define CStmlWnd__GetThisChar                              0x55FDA0
#define CStmlWnd__GetVisiableText                          0x5625B0
#define CStmlWnd__InitializeTempVariables                  0x55FD50
#define CStmlWnd__InitializeWindowVariables                0x564340
#define CStmlWnd__MakeStmlColorTag                         0x55F530
#define CStmlWnd__MakeWndNotificationTag                   0x55F5D0
#define CStmlWnd__StripFirstSTMLLines                      0x5681F0
#define CStmlWnd__UpdateHistoryString                      0x5629F0

// CTabWnd
#define CTabWnd__Draw                                      0x57DD10
#define CTabWnd__DrawCurrentPage                           0x57D800
#define CTabWnd__DrawTab                                   0x57D580
#define CTabWnd__GetCurrentPage                            0x57D130
#define CTabWnd__GetCurrentTabIndex                        0x57CF00
#define CTabWnd__GetNumTabs                                0x57D000
#define CTabWnd__GetPageClientRect                         0x57CF10
#define CTabWnd__GetPageFromTabIndex                       0x57D030
#define CTabWnd__GetPageInnerRect                          0x57CF70
#define CTabWnd__GetTabInnerRect                           0x57D240
#define CTabWnd__GetTabRect                                0x57D140
#define CTabWnd__IndexInBounds                             0x57D010
#define CTabWnd__InsertPage                                0x57DC00
#define CTabWnd__SetPage                                   0x57D2E0
#define CTabWnd__SetPageRect                               0x57D3F0
#define CTabWnd__UpdatePage                                0x57D4A0

// CTextOverlay
#define CTextOverlay__DisplayText                          0x401406 
