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

#define __ClientName							"eqgame"
#define __ClientVersion							"Wed Mar 10 01:47:xx 2004"
#define __ClientOverride						0
#define __MacroQuestWinClassName				"__MacroQuestTray"
#define __MacroQuestWinName						"MacroQuest"

// Memory Protection
#define __MemChecker1								0x4BDC03
#define __MemChecker2								0x4C431C
#define __MemChecker3								0x4C258C
#define __MemCheckAddr1								0x4C4383
#define __MemCheckAddr2								0x4C43B1
#define __EncryptPad1								0x617C20
#define __EncryptPad2								0x618AD8
#define __EncryptPad3								0x618020


#define DI8__Main									0x795244
#define DI8__Keyboard								0x795248
#define DI8__Mouse									0x79524C

#define __LastTell									0x6D729C
#define __Guilds									0x73C298 
#define __Mouse										0x795250
#define __Attack									0x735ACE
#define __InChatMode								0x6D51D0
#define __gWorld									0x7378B0
#define __GroupCount								0x735E60
#define __CommandList								0x611B18
#define __DoAbilityList								0x70ED70
#define __DoAbilityAvailable						0x6D5Fc4
#define __ServerHost								0x735D1C
#define __ServerName								0x70ED30
#define __HWnd										0x6D5190
#define __Clicks									0x6D5290
#define __ScreenX									0x6D5198
#define __ScreenY									0x6D519C
#define __EQP_IDArray								0x6D2278
#define __CurrentMapLabel							0x79E044
#define __BindList									0x611608
#define __RangeAttackReady							0x6D6028


////
//Section 1: Vital Offsets
////
#define pinstCSidlManager                             0x7A93A4
#define pinstCDisplay                                 0x73793C
#define pinstCEverQuest                               0x7953B8
#define pinstPCData                                   0x737918
#define pinstCharData                                 0x737918
#define pinstCharSpawn                                0x737910
#define pinstSpawnList                                0x7378D8
#define pinstSpawnListTail                            0x7378FC
#define pinstWorldData                                0x7378D4
#define pinstSpellManager                             0x791E14
#define pinstActiveMerchant                           0x737928
#define pinstSelectedItem                             0x79DF48
#define pinstGroup                                    0x735FA8
#define pinstTarget                                   0x73791C
#define pinstSwitchManager                            0x6D5184
#define pinstEQItemList                               0x7378DC
#define pinstSpellSets                                0x7356D4
#define instEQZoneInfo                                0x6D5404 
#define pinstCXWndManager							  0x7A939C
#define instKeypressHandler							  0x784708
////
//Section 2:  UI Related Offsets
////
/*CharacterSelect                                               0x622024*/
#define pinstCFacePick                                          0x622028
#define pinstTextMessageWnd                                     0x62202C
#define pinstCNoteWnd                                           0x622030
#define pinstCHelpWnd                                           0x622034
#define pinstCBookWnd                                           0x622038
#define pinstCPetInfoWnd                                        0x62203C
#define pinstCTrainWnd                                          0x622040
#define pinstCSkillsWnd                                         0x622044
#define pinstCSkillsSelectWnd                                   0x622048
#define pinstCCombatSkillSelectWnd                              0x62204C
#define pinstCFriendsWnd                                        0x622050
#define pinstCAAWnd                                             0x622054
#define pinstCGroupSearchFiltersWnd                             0x622058
#define pinstCLoadskinWnd                                       0x62205C
#define pinstCAlarmWnd                                          0x622060
#define pinstCMusicPlayerWnd                                    0x622064
#define pinstCRaidWnd                                           0x622068
#define pinstCRaidOptionsWnd                                    0x62206C
#define pinstCBreathWnd                                         0x622070
#define pinstCMapViewWnd                                        0x622074
#define pinstCMapToolbarWnd                                     0x622078
#define pinstCEditLabelWnd                                      0x62207C
#define pinstCTargetWnd                                         0x622080
#define pinstCHotButtonWnd                                      0x622084
#define pinstCColorPickerWnd                                    0x622088
#define pinstCPlayerWnd                                         0x62208C
#define pinstCOptionsWnd                                        0x622090
#define pinstCBuffWindowNORMAL                                  0x622094
#define pinstCBuffWindowSHORT                                   0x622098
/*CharacterCreation                                             0x62209C*/
#define pinstCCursorAttachment                                  0x6220A0
#define pinstCCastingWnd                                        0x6220A4
#define pinstCCastSpellWnd                                      0x6220A8
#define pinstCSpellBookWnd                                      0x6220AC
#define pinstCInventoryWnd                                      0x6220B0
#define pinstCBankWnd                                           0x6220B4
#define pinstCQuantityWnd                                       0x6220B8
#define pinstCLootWnd                                           0x6220BC
#define pinstCActionsWnd                                        0x6220C0
#define pinstCCombatAbilityWnd                                  0x6220C4
#define pinstCMerchantWnd                                       0x6220C8
#define pinstCTradeWnd                                          0x6220CC
#define pinstCSelectorWnd                                       0x6220D0
#define pinstCBazaarWnd                                         0x6220D4
#define pinstCBazaarSearchWnd                                   0x6220D8
#define pinstCGiveWnd                                           0x6220DC
#define pinstCTrackingWnd                                       0x6220E0
#define pinstCInspectWnd                                        0x6220E4
#define pinstCSocialEditWnd                                     0x6220E8
#define pinstCFeedbackWnd                                       0x6220EC
#define pinstCBugReportWnd                                      0x6220F0
#define pinstCVideoModesWnd                                     0x6220F4
#define pinstCTextEntryWnd                                      0x6220F8
#define pinstCFileSelectionWnd                                  0x6220FC
#define pinstCCompassWnd                                        0x622100
#define pinstCPlayerNotesWnd                                    0x622104
#define pinstCGemsGameWnd                                       0x622108
#define pinstCTimeLeftWnd                                       0x62210C
#define pinstCPetitionQWnd                                      0x622110
#define pinstCSoulmarkWnd                                       0x622114
#define pinstCStoryWnd                                          0x622118
#define pinstCJournalTextWnd                                    0x62211C
#define pinstCJournalCatWnd                                     0x622120
#define pinstCBodyTintWnd                                       0x622124
#define pinstCContainerMgr                                      0x62212C
#define pinstCInvSlotMgr                                        0x622128
#define pinstCAdventureRequestWnd                               0x6D615C
#define pinstCLeadershipWnd                                     0x79DFC8
#define pinstCAdventureLeaderboardWnd                           0x79DA18
#define pinstCAdventureMerchantWnd                              0x79DA30
#define pinstCAdventureStatsWnd                                 0x79DA60
#define pinstCChatManager                                       0x79DCD8
#define pinstCDynamicZoneWnd                                    0x79DD90 
#define pinstCFindLocationWnd                                   0x79DE20
#define pinstCGroupSearchWnd                                    0x79DE9C
#define pinstCGroupWnd                                          0x79DEB4
#define pinstCGuildMgmtWnd                                      0x79DECC
#define pinstCPopupWndManager                                   0x79E118
#define pinstCSystemInfoDialogBox                               0x79E994
#define pinstCTargetOfTargetWnd                                 0x79E9AC
#define pinstCTipWndOFDAY                                       0x79EA14
#define pinstCTipWndCONTEXT                                     0x79EA18
#define pinstCTradeskillWnd                                     0x79EA44
#define pinstCTributeBenefitWnd                                 0x79EA84
#define pinstCTributeMasterWnd                                  0x79EA9C
#define pinstCContextMenuManager                                0x7A93C0 

#define pinstCTextOverlay										0x620EE0

////
// Section 3: Miscellaneous Offsets
////

#define DrawNetStatus                                 0x4B3906
#define CrashDetected                                 0x4C3FBE
#define __ProcessGameEvents								0x4AA61D
#define __ConvertItemTags								0x45B51E
#define __SendMessage									0x4B8A0B
#define __NewUIINI										0x520006
#define __ExecuteCmd									0x44DBC3

// EQ_LoadingS
#define EQ_LoadingS__WriteTextHD                      0x432FEB

// CStmlWnd
#define CStmlWnd__AppendSTML                          0x565D90

////
// Section 4: Function Offsets
////

// CEverQuest
#define CEverQuest__dsp_chat                     0x49A612
#define CEverQuest__ClickedPlayer                0x498009
#define CEverQuest__EnterZone                    0x49B466
#define CEverQuest__InterpretCmd                 0x4A706F
#define CEverQuest__RightClickedOnPlayer         0x4A2F69
#define CEverQuest__LeftClickedOnPlayer          0x4A9234
#define CEverQuest__GetRaceDesc                  0x4922B4
#define CEverQuest__GetClassDesc                 0x491A31
#define CEverQuest__GetClassThreeLetterCode      0x491E4C
#define CEverQuest__GetDeityDesc                 0x493A42
#define CEverQuest__GetBodyTypeDesc              0x491FAF
#define CEverQuest__SetGameState                 0x498170 

// CXWndManager
#define CXWndManager__RemoveWnd                  0x56CA20
#define CXWndManager__GetKeyboardFlags			 0x56C640

// KeyPressHandler
#define KeyPressHandler__HandleKeyDown			0x4AEEFE
#define KeyPressHandler__HandleKeyUp			0x4AF1A2
#define KeypressHandler__AttachKeyToEqCommand		0x4B0560
#define KeypressHandler__AttachAltKeyToEqCommand	0x4B059D

// EQ_Character
#define EQ_Character__Max_Mana                           0x421A0B
#define EQ_Character__Max_HP                             0x421856
#define EQ_Character__Cur_HP                             0x4233C4
#define EQ_Character__GetFocusCastingTimeModifier        0x42948F
#define EQ_Character__GetAACastingTimeModifier           0x42981C
#define EQ_Character__CastSpell                          0x42D363

// EQPlayer
#define EQPlayer__EQPlayer                               0x48AA55
#define EQPlayer__dEQPlayer                              0x488EF9
#define EQPlayer__DoAttack								 0x485D0E

// CXStr
// WARNING:  Be sure that none of these offsets are identical!  Otherwise, you
//           will cause a memory leak and Lax will eat your first born child!
#define CXStr__CXStr                                     0x40104C
#define CXStr__CXStr1                                    0x401046
#define CXStr__CXStr3                                    0x59B910
#define CXStr__dCXStr                                    0x401076
#define CXStr__operator_plus_equal1                      0x59C9A0
#define CXStr__operator_equal1                           0x59BAD0


// CStmlWnd
#define CStmlWnd__AppendSTML                             0x565D90

// CChatWindow
#define CChatWindow__CChatWindow                 0x4E0160
#define CChatWindow__dCChatWindow                0x4B9F5D

// CChatManager
#define CChatManager__InitContextMenu            0x4DD688
#define CChatManager__GetRGBAFromIndex           0x4DCD24

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot                         0x4FA4C6
#define CInvSlotMgr__MoveItem                            0x4F9E71

// CItemDisplayWnd
#define CItemDisplayWnd__SetItem                         0x4FD334
#define CItemDisplayWnd__SetSpell                        0x4FC657

// CLabel
#define CLabel__Draw                                     0x503175

// CDisplay
#define CDisplay__ReloadUI                               0x41860C
#define CDisplay__CleanGameUI                            0x410ABA
#define CDisplay__GetClickedActor                        0x40D608
#define CDisplay__WriteTextHD2                           0x4114E3
#define CDisplay__GetWorldFilePath                       0x40BC80

// EQ_Item
#define EQ_Item__GetItemLinkHash                 0x432A42

// CBankWnd
#define CBankWnd__GetNumBankSlots                0x4CEC19

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg        0x4D12CB

// CMerchantWnd
#define CMerchantWnd__SelectBuySellSlot          0x50B9F2
#define CMerchantWnd__RequestBuyItem             0x50ABE5
#define CMerchantWnd__RequestSellItem            0x50AF63
#define CMerchantWnd__DisplayBuyOrSellPrice             0x50AA1A

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet               0x51D296

// MapViewMap
#define MapViewMap__SaveEx                       0x506787
#define MapViewMap__Clear                       0x5061AF
//#define MapViewMap__Draw						0x508B0E

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd                 0x509ADE

// EQItemList
#define EQItemList__EQItemList                   0x450384
#define EQItemList__dEQItemList                  0x450400

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney            0x435983

// CSidlScreenWnd
#define CSidlScreenWnd__CSidlScreenWnd1          0x5509D0
#define CSidlScreenWnd__dCSidlScreenWnd          0x550070
#define CSidlScreenWnd__CreateChildrenFromSidl   0x54F3C0
#define CSidlScreenWnd__GetChildItem             0x54ECD0
#define CSidlScreenWnd__WndNotification          0x54EF40
#define CSidlScreenWnd__CalculateHSBRange        0x54E4A0
#define CSidlScreenWnd__CalculateVSBRange        0x54E560
#define CSidlScreenWnd__ConvertToRes             0x54EC50
#define CSidlScreenWnd__CSidlScreenWnd2          0x5509D0
#define CSidlScreenWnd__DrawBackground           0x550200
#define CSidlScreenWnd__DrawSidlPiece            0x54EFE0
#define CSidlScreenWnd__EnableIniStorage         0x54EC00
#define CSidlScreenWnd__GetSidlPiece             0x54F280
#define CSidlScreenWnd__HandleRButtonDown        0x54ED40
#define CSidlScreenWnd__Init1                    0x550590
#define CSidlScreenWnd__LoadIniInfo              0x54F470
#define CSidlScreenWnd__LoadIniListWnd           0x54FDA0
#define CSidlScreenWnd__LoadSidlScreen           0x54EE20
#define CSidlScreenWnd__OnResize                 0x54E610
#define CSidlScreenWnd__SetScreen                0x550190
#define CSidlScreenWnd__StoreIniInfo             0x54E790
#define CSidlScreenWnd__StoreIniListWnd          0x54FE50

// CSidlManager
#define CSidlManager__FindScreenPieceTemplate1               0x575080

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead                       0x55C840

// CXRect
#define CXRect__CenterPoint                     0x4CEC20

// CXWnd
#define CXWnd__Bottom                      0x554980
#define CXWnd__BringToTop                    0x551150
#define CXWnd__Center                      0x554740
#define CXWnd__ClrFocus                      0x550EA0
#define CXWnd__Deactivate                    0x54E780
#define CXWnd__DoAllDrawing                    0x555320
#define CXWnd__DrawBackground                  0x554430
#define CXWnd__DrawChildren                    0x555450
#define CXWnd__DrawCloseBox                   0x553170
#define CXWnd__DrawColoredRect                  0x551360
#define CXWnd__DrawCursor                    0x550F10
#define CXWnd__DrawHScrollbar                  0x5534B0
#define CXWnd__DrawLasso                    0x5542F0
#define CXWnd__DrawMinimizeBox                  0x552FB0
#define CXWnd__DrawNC                      0x554E90
#define CXWnd__DrawTileBox                    0x553090
#define CXWnd__DrawTitleBar                    0x553250
#define CXWnd__DrawTooltipAtPoint                0x554570
#define CXWnd__DrawVScrollbar                  0x5538B0
#define CXWnd__GetBorderFrame                  0x5517A0
#define CXWnd__GetChildWndAt                  0x554150
#define CXWnd__GetClientClipRect                0x5516E0
#define CXWnd__GetClientRect                  0x403D6F
#define CXWnd__GetCloseBoxTemplate                0x551800
#define CXWnd__GetCursorToDisplay                0x551220
#define CXWnd__GetDragDropCursor                0x551690
#define CXWnd__GetFirstChildWnd                  0x5511E0
#define CXWnd__GetHitTestRect                  0x552220
#define CXWnd__GetInnerRect                    0x403D6A
#define CXWnd__GetMinimizeBoxTemplate              0x551830
#define CXWnd__GetMinimizedRect                  0x553E50
#define CXWnd__GetMinSize                        0x403D7C
#define CXWnd__GetNextChildWnd                  0x554130
#define CXWnd__GetNextSib                    0x551200
#define CXWnd__GetScreenClipRect                0x5549D0
#define CXWnd__GetScreenRect                  0x551970
#define CXWnd__GetTileBoxTemplate                0x551850
#define CXWnd__GetTooltip                    0x550EF0
#define CXWnd__GetTooltipRect                  0x5544C0
#define CXWnd__GetUntileSize                  0x403D50
#define CXWnd__GetWindowTextA                  0x4C9690
#define CXWnd__GetXMLTooltip                  0x550CE0
#define CXWnd__HitTest                      0x5541D0
#define CXWnd__IsActive                      0x551750
#define CXWnd__IsDescendantOf                  0x551760
#define CXWnd__IsReallyVisible                  0x554110
#define CXWnd__IsType                            0x5552C0
#define CXWnd__IsValid                      0x403D2E
#define CXWnd__Left                        0x554910
#define CXWnd__Move                        0x553CC0
#define CXWnd__Move1                      0x553D50
#define CXWnd__PostDraw                      0x4F2EFE
#define CXWnd__ProcessTransition                0x551110
#define CXWnd__QueryClickStickDropOK              0x5516A0
#define CXWnd__QueryDropOK                    0x551650
#define CXWnd__Refade                      0x550F40
#define CXWnd__RequestDockInfo                  0x5521A0
#define CXWnd__Resize                      0x554B00
#define CXWnd__Right                             0x5548B0
#define CXWnd__SetAttributesFromSidl              0x554A40
#define CXWnd__SetFirstChildPointer                0x551BC0
#define CXWnd__SetFocus                      0x552EA0
#define CXWnd__SetKeyTooltip                  0x551C00
#define CXWnd__SetMouseOver                    0x551BE0
#define CXWnd__SetNextSibPointer                0x551BD0
#define CXWnd__SetVScrollPos                  0x551530
#define CXWnd__StartFade                    0x551170

// CSliderWnd
#define CSliderWnd__GetValue                          0x580890
#define CSliderWnd__SetValue                          0x580A60
#define CSliderWnd__UpdateThumb                       0x580850

// CEditBaseWnd
#define CEditBaseWnd__SetMaxChars                     0x4CE78F
#define CEditBaseWnd__SetSel                          0x577030

// CComboWnd
#define CComboWnd__DeleteAll                          0x57BFC0
#define CComboWnd__Draw                               0x57C1C0
#define CComboWnd__GetButtonRect                      0x57BFF0
#define CComboWnd__GetCurChoice                       0x57BF80
#define CComboWnd__GetListRect                        0x57C5B0
#define CComboWnd__GetTextRect                        0x57C050
#define CComboWnd__HitTest                            0x4D54D0
#define CComboWnd__InsertChoice                       0x57C610
#define CComboWnd__SetColors                          0x57BF50
#define CComboWnd__SetChoice                          0x57C6F0

// CListWnd
#define CListWnd__AddLine                             0x56A360
#define CListWnd__AddString                           0x56A4E0
#define CListWnd__CalculateFirstVisibleLine           0x567990
#define CListWnd__CalculateLineHeights                0x567930
#define CListWnd__CalculateVSBRange                   0x569500
#define CListWnd__ClearAllSel                         0x5671C0
#define CListWnd__CloseAndUpdateEditWindow            0x567F90
#define CListWnd__Compare                             0x5682D0
#define CListWnd__Draw                                0x569160
#define CListWnd__DrawBackground                      0x566950
#define CListWnd__DrawColumnSeparators                0x561120
#define CListWnd__DrawHeader                          0x569090
#define CListWnd__DrawItem                            0x5689E0
#define CListWnd__DrawLine                            0x568D30
#define CListWnd__DrawSeparator                       0x520584
#define CListWnd__EnsureVisible                       0x5679E0
#define CListWnd__ExtendSel                           0x568910
#define CListWnd__GetColumnFlags                      0x566C90
#define CListWnd__GetColumnMinWidth                   0x566DC0
#define CListWnd__GetColumnWidth                      0x566CF0
#define CListWnd__GetCurSel                           0x566AD0
#define CListWnd__GetCursorToDisplay                  0x5669E0
#define CListWnd__GetHeaderRect                       0x566910
#define CListWnd__GetItemAtPoint                      0x567C90
#define CListWnd__GetItemAtPoint1                     0x567D00
#define CListWnd__GetItemData                         0x566B10
#define CListWnd__GetItemHeight                       0x5677C0
#define CListWnd__GetItemIcon                         0x566BD0
#define CListWnd__GetItemRect                         0x567AB0
#define CListWnd__GetItemText                         0x566B50
#define CListWnd__GetSelList                          0x56A680
#define CListWnd__GetSeparatorRect                    0x568220
#define CListWnd__IsLineEnabled                       0x5672B0
#define CListWnd__SetColors                           0x566880
#define CListWnd__SetColumnWidth                      0x566D70
#define CListWnd__SetCurSel                           0x5670E0
#define CListWnd__SetItemColor                        0x569FA0
#define CListWnd__SetItemData                         0x567270
#define CListWnd__SetItemText                         0x569EE0
#define CListWnd__SetVScrollPos                       0x568470
#define CListWnd__ShiftColumnSeparator                0x568880
#define CListWnd__Sort                                0x576C40
#define CListWnd__ToggleSel                           0x567100

// CEditWnd
#define CEditWnd__DrawCaret                           0x57CA50
#define CEditWnd__DrawMultiline                       0x57DF60
#define CEditWnd__GetCaretPt                          0x57E310
#define CEditWnd__GetCharIndexPt                      0x57D860
#define CEditWnd__GetDisplayString                    0x57D2F0
#define CEditWnd__GetHorzOffset                       0x594E90
#define CEditWnd__GetLineForPrintableChar             0x57D310
#define CEditWnd__GetSelEndPt                         0x57DAA0
#define CEditWnd__GetSelStartPt                       0x57DA80
#define CEditWnd__GetSTMLSafeText                     0x57CFD0
#define CEditWnd__PointFromPrintableChar              0x57D420
#define CEditWnd__SelectableCharFromPoint             0x587430
#define CEditWnd__SetEditable                         0x57CFA0
#define CEditWnd__SetWindowTextA                      0x586650

// CGaugeWnd
#define CGaugeWnd__CalcFillRect                       0x4EB963
#define CGaugeWnd__CalcLinesFillRect                  0x4EB9BF
#define CGaugeWnd__Draw                               0x4EBCBF
#define CGaugeWnd__SetAttributesFromSidl              0x51E15E

// CStmlWnd
#define CStmlWnd__CalculateHSBRange                   0x55D790
#define CStmlWnd__CalculateVSBRange                   0x55D730
#define CStmlWnd__CanBreakAtCharacter                 0x55D8D0
#define CStmlWnd__CanGoBackward                       0x55D950
#define CStmlWnd__FastForwardPastSpaces               0x55E330
#define CStmlWnd__FastForwardToEndOfTag               0x55E690
#define CStmlWnd__GetCursorToDisplay                  0x561150
#define CStmlWnd__GetNextChar                         0x55DDB0
#define CStmlWnd__GetNextTagPiece                     0x55E4A0
#define CStmlWnd__GetSTMLText                         0x4E0142
#define CStmlWnd__GetThisChar                         0x55D5F0
#define CStmlWnd__GetVisiableText                     0x520E9E
#define CStmlWnd__InitializeTempVariables             0x55D5A0
#define CStmlWnd__InitializeWindowVariables           0x561C60
#define CStmlWnd__MakeStmlColorTag                    0x55CDA0
#define CStmlWnd__MakeWndNotificationTag              0x55CE40
#define CStmlWnd__StripFirstSTMLLines                 0x565B10
#define CStmlWnd__UpdateHistoryString                 0x55CC40

// CTabWnd
#define CTabWnd__Draw                                 0x554E90
#define CTabWnd__DrawCurrentPage                      0x57B790
#define CTabWnd__DrawTab                             0x57B510
#define CTabWnd__GetCurrentPage                       0x57B0C0
#define CTabWnd__GetCurrentTabIndex                   0x57AE60
#define CTabWnd__GetNumTabs                           0x57AF90
#define CTabWnd__GetPageClientRect                    0x57AE70
#define CTabWnd__GetPageFromTabIndex                  0x57AFC0
#define CTabWnd__GetPageInnerRect                     0x57AED0
#define CTabWnd__GetTabInnerRect                      0x57B1D0
#define CTabWnd__GetTabRect                           0x57B0D0
#define CTabWnd__IndexInBounds                        0x57AFA0
#define CTabWnd__InsertPage                           0x57BB90
#define CTabWnd__SetPage                              0x57B270
#define CTabWnd__SetPageRect                          0x57B380
#define CTabWnd__UpdatePage                           0x57B430

// CTextOverlay
#define CTextOverlay__DisplayText                    0x4013FE
