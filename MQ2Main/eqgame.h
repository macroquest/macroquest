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

#define __ClientName								 "eqgame" 
#define __ClientVersion								 "Tue Mar 16 02:51:xx 2004" 
#define __ClientOverride							 0 
#define __MacroQuestWinClassName					 "__MacroQuestTray" 
#define __MacroQuestWinName							 "MacroQuest" 

// Memory Protection 
#define __MemChecker1                                0x4BDCEB 
#define __MemChecker2                                0x4C4434 
#define __MemChecker3                                0x4C26A3 
#define __MemCheckAddr1                              0x4C449B 
#define __MemCheckAddr2                              0x4C44C9
#define __EncryptPad1                                0x618028 
#define __EncryptPad2                                0x618EE0 
#define __EncryptPad3                                0x618428 

#define DI8__Main                                    0x795684 
#define DI8__Keyboard                                0x795688 
#define DI8__Mouse                                   0x79568C 

#define __LastTell                                   0x6D76DC 
#define __Guilds                                     0x73C6D8 
#define __Mouse                                      0x795690 
#define __Attack                                     0x735F0E 
#define __InChatMode                                 0x6D5610 
#define __gWorld                                     0x737CF0 
#define __GroupCount                                 0x7362A0 
#define __CommandList                                0x611B18 
#define __DoAbilityList                              0x70F1B0 
#define __DoAbilityAvailable                         0x6D6404 
#define __ServerHost                                 0x73615C 
#define __ServerName                                 0x70F170 
#define __HWnd                                       0x6D55D0 
#define __Clicks                                     0x6D56D0 
#define __ScreenX                                    0x6D55D8 
#define __ScreenY                                    0x6D55DC 
#define __EQP_IDArray                                0x6D26B8 
#define __CurrentMapLabel                            0x79E484 
#define __BindList                                   0x611608 
#define __RangeAttackReady							 0x6D6468 


//// 
//Section 1: Vital Offsets 
//// 
#define pinstCSidlManager                             0x7A97E4 
#define pinstCDisplay                                 0x737D7C 
#define pinstCEverQuest                               0x7957F8 
#define pinstPCData                                   0x737D58 
#define pinstCharData                                 0x737D58 
#define pinstCharSpawn                                0x737D50 
#define pinstSpawnList                                0x737D18 
#define pinstSpawnListTail                            0x737D3C 
#define pinstWorldData                                0x737D14 
#define pinstSpellManager                             0x792254 
#define pinstActiveMerchant                           0x737D68 
#define pinstSelectedItem                             0x79E388 
#define pinstGroup                                    0x7363E8 
#define pinstTarget                                   0x737D5C 
#define pinstSwitchManager                            0x6D55C4 
#define pinstEQItemList                               0x737D1C 
#define pinstSpellSets                                0x735B14 
#define instEQZoneInfo                                0x6D5844 
#define pinstCXWndManager                             0x7A97DC 
#define instKeypressHandler							  0x784B48 


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                       0x621320 
/*      pinstCharacterSelect                                    0x622464*/ 
#define pinstCFacePick                                          0x622468 
#define pinstTextMessageWnd                                     0x62246C 
#define pinstCNoteWnd                                           0x622470 
#define pinstCHelpWnd                                           0x622474 
#define pinstCBookWnd                                           0x622478 
#define pinstCPetInfoWnd                                        0x62247C 
#define pinstCTrainWnd                                          0x622480 
#define pinstCSkillsWnd                                         0x622484 
#define pinstCSkillsSelectWnd                                   0x622488 
#define pinstCCombatSkillSelectWnd                              0x62248C 
#define pinstCFriendsWnd                                        0x622490 
#define pinstCAAWnd                                             0x622494 
#define pinstCGroupSearchFiltersWnd                             0x622498 
#define pinstCLoadskinWnd                                       0x62249C 
#define pinstCAlarmWnd                                          0x6224A0 
#define pinstCMusicPlayerWnd                                    0x6224A4 
#define pinstCRaidWnd                                           0x6224A8 
#define pinstCRaidOptionsWnd                                    0x6224AC 
#define pinstCBreathWnd                                         0x6224B0 
#define pinstCMapViewWnd                                        0x6224B4 
#define pinstCMapToolbarWnd                                     0x6224B8 
#define pinstCEditLabelWnd                                      0x6224BC 
#define pinstCTargetWnd                                         0x6224C0 
#define pinstCHotButtonWnd                                      0x6224C4 
#define pinstCColorPickerWnd                                    0x6224C8 
#define pinstCPlayerWnd                                         0x6224CC 
#define pinstCOptionsWnd                                        0x6224D0 
#define pinstCBuffWindowNORMAL                                  0x6224D4 
#define pinstCBuffWindowSHORT                                   0x6224D8 
/*      pinstCharacterCreation                                  0x6224DC*/ 
#define pinstCCursorAttachment                                  0x6224E0 
#define pinstCCastingWnd                                        0x6224E4 
#define pinstCCastSpellWnd                                      0x6224E8 
#define pinstCSpellBookWnd                                      0x6224EC 
#define pinstCInventoryWnd                                      0x6224F0 
#define pinstCBankWnd                                           0x6224F4 
#define pinstCQuantityWnd                                       0x6224F8 
#define pinstCLootWnd                                           0x6224FC 
#define pinstCActionsWnd                                        0x622500 
#define pinstCCombatAbilityWnd                                  0x622504 
#define pinstCMerchantWnd                                       0x622508 
#define pinstCTradeWnd                                          0x62250C 
#define pinstCSelectorWnd                                       0x622510 
#define pinstCBazaarWnd                                         0x622514 
#define pinstCBazaarSearchWnd                                   0x622518 
#define pinstCGiveWnd                                           0x62251C 
#define pinstCTrackingWnd                                       0x622520 
#define pinstCInspectWnd                                        0x622524 
#define pinstCSocialEditWnd                                     0x622528 
#define pinstCFeedbackWnd                                       0x62252C 
#define pinstCBugReportWnd                                      0x622530 
#define pinstCVideoModesWnd                                     0x622534 
#define pinstCTextEntryWnd                                      0x622538 
#define pinstCFileSelectionWnd                                  0x62253C 
#define pinstCCompassWnd                                        0x622540 
#define pinstCPlayerNotesWnd                                    0x622544 
#define pinstCGemsGameWnd                                       0x622548 
#define pinstCTimeLeftWnd                                       0x62254C 
#define pinstCPetitionQWnd                                      0x622550 
#define pinstCSoulmarkWnd                                       0x622554 
#define pinstCStoryWnd                                          0x622558 
#define pinstCJournalTextWnd                                    0x62255C 
#define pinstCJournalCatWnd                                     0x622560 
#define pinstCBodyTintWnd                                       0x622564 
#define pinstCContainerMgr                                      0x62256C 
#define pinstCInvSlotMgr                                        0x622568 
#define pinstCAdventureRequestWnd                               0x6D659C 
#define pinstCLeadershipWnd                                     0x6D65A0 
#define pinstCAdventureLeaderboardWnd                           0x79DE58 
#define pinstCAdventureMerchantWnd                              0x79DE70 
#define pinstCAdventureStatsWnd                                 0x79DEA0 
#define pinstCChatManager                                       0x79E118 
#define pinstCDynamicZoneWnd                                    0x79E1D0 
#define pinstCFindLocationWnd                                   0x79E260 
#define pinstCGroupSearchWnd                                    0x79E2DC 
#define pinstCGroupWnd                                          0x79E2F4 
#define pinstCGuildMgmtWnd                                      0x79E30C 
#define pinstCPopupWndManager                                   0x79E558 
#define pinstCSystemInfoDialogBox                               0x79EDD4 
#define pinstCTargetOfTargetWnd                                 0x79EDEC 
#define pinstCTipWndOFDAY                                       0x79EE54 
#define pinstCTipWndCONTEXT                                     0x79EE58 
#define pinstCTradeskillWnd                                     0x79EE84 
#define pinstCTributeBenefitWnd                                 0x79EEC4 
#define pinstCTributeMasterWnd                                  0x79EEDC 
#define pinstCContextMenuManager                                0x7A9800 
/*      pinstMaxItemDisplays                                    0x79E3B4*/


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define DrawNetStatus                                 0x4B3A91 
#define CrashDetected                                 0x4C40D9 
#define __ProcessGameEvents                           0x4AA72B 
#define __ConvertItemTags                             0x45B6D3 
#define __SendMessage                                 0x4B8AEC 
#define __NewUIINI                                    0x5203CC 
#define __ExecuteCmd                                  0x44DBE7 

// EQ_LoadingS 
#define EQ_LoadingS__WriteTextHD                      0x432F46 


//// 
// Section 4: Function Offsets 
//// 
// CEverQuest 
#define CEverQuest__dsp_chat					 0x49a733 
#define CEverQuest__ClickedPlayer                0x49812A 
#define CEverQuest__EnterZone				     0x49b587
#define CEverQuest__GetBodyTypeDesc				 0x4920c3 
#define CEverQuest__GetClassDesc				 0x491b45
#define CEverQuest__GetClassThreeLetterCode      0x491F60 
#define CEverQuest__GetDeityDesc				 0x493b56 
#define CEverQuest__GetRaceDesc					 0x4923c8
#define CEverQuest__InterpretCmd				 0x4a717d
#define CEverQuest__LeftClickedOnPlayer          0x4a9342
#define CEverQuest__RightClickedOnPlayer         0x4a3077
#define CEverQuest__SetGameState				 0x498291 

// CXWndManager 
#define CXWndManager__RemoveWnd                  0x56CF40
#define CXWndManager__GetKeyboardFlags           0x56CB60
#define CXWndManager__HandleKeyboardMsg			 0x56D030

// KeyPressHandler 
#define KeypressHandler__HandleKeyDown					  0x4AF089 
#define KeypressHandler__HandleKeyUp                      0x4AF32D
#define KeypressHandler__AttachKeyToEqCommand			  0x4B06EB 
#define KeypressHandler__AttachAltKeyToEqCommand	      0x4B0728 
#define KeypressHandler__SaveKeymapping					  0x4B0634 
#define KeypressHandler__ClearCommandStateArray			  0x4AF31C

// EQ_Character 
#define EQ_Character__Max_Mana                           0x4219E0 
#define EQ_Character__Max_HP                             0x42182B 
#define EQ_Character__Cur_HP                             0x423399 
#define EQ_Character__GetFocusCastingTimeModifier        0x429464 
#define EQ_Character__GetAACastingTimeModifier           0x429792 
#define EQ_Character__CastSpell                          0x42D338

// EQPlayer 
#define EQPlayer__EQPlayer                               0x489EB9 
#define EQPlayer__dEQPlayer                              0x488601 
#define EQPlayer__DoAttack                               0x48599D

// CXStr 
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  cCXStr, CXStr1, & CXStr3 can be found in the 'bookwindow' constructor (0x4D4BB4, 3/16 patch)
#define CXStr__CXStr                                     0x401046
#define CXStr__CXStr1                                    0x50D3F9
#define CXStr__CXStr3                                    0x59BEF0 
#define CXStr__dCXStr                                    0x401070 
#define CXStr__operator_plus_equal1                      0x59CF80 
#define CXStr__operator_equal1                           0x59C0B0 

// CChatWindow 
#define CChatWindow__CChatWindow						 0x4e03c3
#define CChatWindow__dCChatWindow				         0x4ba03b 

// CChatManager 
#define CChatManager__GetRGBAFromIndex					 0x4dcf87 
#define CChatManager__InitContextMenu					 0x4dd8eb 

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                         0x4fa70b 
#define CInvSlotMgr__MoveItem							 0x4fa0b6 

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem						 0x4fd402 
#define CItemDisplayWnd__SetSpell                        0x4fc91f 

// CLabel 
#define CLabel__Draw                                     0x503464 

// CDisplay 
#define CDisplay__ReloadUI                               0x418593 
#define CDisplay__CleanGameUI                            0x4109C9 
#define CDisplay__GetClickedActor                        0x40D80D 
#define CDisplay__WriteTextHD2                           0x411472 
#define CDisplay__GetWorldFilePath                       0x40BE85 

// EQ_Item 
#define EQ_Item__GetItemLinkHash                         0x43299D 

// CBankWnd 
#define CBankWnd__GetNumBankSlots                        0x4CEE00 

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                0x4D14BD 

// CMerchantWnd 
#define CMerchantWnd__SelectBuySellSlot                  0x50BD60 
#define CMerchantWnd__RequestBuyItem                     0x50AF53 
#define CMerchantWnd__RequestSellItem                    0x50B2D1 
#define CMerchantWnd__DisplayBuyOrSellPrice              0x50AD88

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet						 0x51d65c 

// MapViewMap 
#define MapViewMap__SaveEx								 0x506AF2 
#define MapViewMap__Clear								 0x50651A 
//#define MapViewMap__Draw								 0x508E79 


// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd						 0x509E49 

// EQItemList 
#define EQItemList__EQItemList							 0x4503A8 
#define EQItemList__dEQItemList							 0x450424 

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney					 0x4358e1 

// CSidlScreenWnd 
#define CSidlScreenWnd__CSidlScreenWnd1					 0x550DE0 
#define CSidlScreenWnd__dCSidlScreenWnd					 0x550480 
#define CSidlScreenWnd__CreateChildrenFromSidl			 0x54F800 
#define CSidlScreenWnd__GetChildItem					 0x54F110 
#define CSidlScreenWnd__WndNotification					 0x54F380 
#define CSidlScreenWnd__CalculateHSBRange				 0x54E8E0 
#define CSidlScreenWnd__CalculateVSBRange				 0x54E9A0 
#define CSidlScreenWnd__ConvertToRes					 0x54F090 
#define CSidlScreenWnd__CSidlScreenWnd2					 0x550DE0 
#define CSidlScreenWnd__DrawBackground					 0x550610 
#define CSidlScreenWnd__DrawSidlPiece					 0x54F420 
#define CSidlScreenWnd__EnableIniStorage				 0x54F040 
#define CSidlScreenWnd__GetSidlPiece					 0x54F6C0 
#define CSidlScreenWnd__HandleRButtonDown				 0x54F180 
#define CSidlScreenWnd__Init1							 0x5509A0 
#define CSidlScreenWnd__LoadIniInfo						 0x54F8B0 
#define CSidlScreenWnd__LoadIniListWnd					 0x5501E0 
#define CSidlScreenWnd__LoadSidlScreen					 0x54F260 
#define CSidlScreenWnd__OnResize						 0x54EA50 
#define CSidlScreenWnd__SetScreen						 0x5505A0 
#define CSidlScreenWnd__StoreIniInfo					 0x54EBD0 
#define CSidlScreenWnd__StoreIniListWnd					 0x550290

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1           0x575570 

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead					 0x55cd70

// CXRect 
#define CXRect__CenterPoint								 0x4CEE07

// CXWnd
#define CXWnd__Bottom						0x554DB0 
#define CXWnd__BringToTop					0x551560 
#define CXWnd__Center						0x554B70 
#define CXWnd__ClrFocus                     0x5512B0 
#define CXWnd__Deactivate                   0x54EBC0 
#define CXWnd__DoAllDrawing                 0x555780 
#define CXWnd__DrawBackground               0x554860 
#define CXWnd__DrawChildren                 0x5558B0 
#define CXWnd__DrawCloseBox                 0x5535A0 
#define CXWnd__DrawColoredRect              0x551790 
#define CXWnd__DrawCursor                   0x551320 
#define CXWnd__DrawHScrollbar               0x5538E0 
#define CXWnd__DrawLasso                    0x554720 
#define CXWnd__DrawMinimizeBox              0x5533E0 
#define CXWnd__DrawNC						0x5552F0 
#define CXWnd__DrawTileBox                  0x5534C0 
#define CXWnd__DrawTitleBar                 0x553680 
#define CXWnd__DrawTooltipAtPoint           0x5549A0 
#define CXWnd__DrawVScrollbar               0x553CE0 
#define CXWnd__GetBorderFrame               0x551BD0 
#define CXWnd__GetChildWndAt                0x554580 
#define CXWnd__GetClientClipRect            0x551B10 
#define CXWnd__GetClientRect                0x403FB2 
#define CXWnd__GetCloseBoxTemplate          0x551C30 
#define CXWnd__GetCursorToDisplay           0x551630 
#define CXWnd__GetDragDropCursor            0x551A80 
#define CXWnd__GetFirstChildWnd             0x5515F0 
#define CXWnd__GetHitTestRect               0x552650 
#define CXWnd__GetInnerRect                 0x403FA0 
#define CXWnd__GetMinimizeBoxTemplate       0x551C60 
#define CXWnd__GetMinimizedRect             0x554280 
#define CXWnd__GetMinSize                   0x403FD9 
#define CXWnd__GetNextChildWnd              0x554560 
#define CXWnd__GetNextSib                   0x551610 
#define CXWnd__GetScreenClipRect            0x554E00 
#define CXWnd__GetScreenRect                0x551DA0 
#define CXWnd__GetTileBoxTemplate           0x551C80 
#define CXWnd__GetTooltip                   0x551300 
#define CXWnd__GetTooltipRect               0x5548F0 
#define CXWnd__GetUntileSize                0x403F86 
#define CXWnd__GetWindowTextA               0x4C98B5 
#define CXWnd__GetXMLTooltip                0x5510F0 
#define CXWnd__HitTest                      0x554600 
#define CXWnd__IsActive                     0x551B80 
#define CXWnd__IsDescendantOf               0x551B90 
#define CXWnd__IsReallyVisible              0x554540 
#define CXWnd__IsType                       0x555720 
#define CXWnd__IsValid                      0x403F64 
#define CXWnd__Left							0x554D40 
#define CXWnd__Move							0x5540F0 
#define CXWnd__Move1						0x554180 
#define CXWnd__PostDraw                     0x4CFB9B 
#define CXWnd__ProcessTransition            0x551520 
#define CXWnd__QueryClickStickDropOK        0x551AD0 
#define CXWnd__QueryDropOK                  0x551A90 
#define CXWnd__Refade						0x551350 
#define CXWnd__RequestDockInfo				0x5525D0 
#define CXWnd__Resize						0x554F40 
#define CXWnd__Right                        0x554CE0 
#define CXWnd__SetAttributesFromSidl        0x554E70 
#define CXWnd__SetFirstChildPointer         0x551FF0 
#define CXWnd__SetFocus                     0x5532D0 
#define CXWnd__SetKeyTooltip                0x552030 
#define CXWnd__SetMouseOver                 0x552010 
#define CXWnd__SetNextSibPointer            0x552000 
#define CXWnd__SetVScrollPos                0x551960 
#define CXWnd__StartFade                    0x551580

// CSliderWnd 
#define CSliderWnd__GetValue                          0x580890 
#define CSliderWnd__SetValue                          0x581010 
#define CSliderWnd__UpdateThumb                       0x580E00 

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                     0x4CE971 
#define CEditBaseWnd__SetSel                          0x577500

// CComboWnd 
#define CComboWnd__DeleteAll                          0x57C560 
#define CComboWnd__Draw                               0x57C760 
#define CComboWnd__GetButtonRect                      0x57C590 
#define CComboWnd__GetCurChoice                       0x57C520 
#define CComboWnd__GetListRect                        0x57CB50 
#define CComboWnd__GetTextRect                        0x57C5F0 
#define CComboWnd__HitTest                            0x4D56C2 
#define CComboWnd__InsertChoice                       0x57CBB0 
#define CComboWnd__SetColors                          0x57C4F0 
#define CComboWnd__SetChoice                          0x57CC90

// CListWnd 
#define CListWnd__AddLine                             0x56AF80 
#define CListWnd__AddString                           0x56B100 
#define CListWnd__CalculateFirstVisibleLine           0x5685B0 
#define CListWnd__CalculateLineHeights                0x568550 
#define CListWnd__CalculateVSBRange                   0x56A120 
#define CListWnd__ClearAllSel                         0x567DE0 
#define CListWnd__CloseAndUpdateEditWindow            0x568BB0 
#define CListWnd__Compare                             0x568EF0 
#define CListWnd__Draw                                0x569D80 
#define CListWnd__DrawBackground                      0x567570 
#define CListWnd__DrawColumnSeparators                0x561D60 
#define CListWnd__DrawHeader                          0x569CB0 
#define CListWnd__DrawItem                            0x569600 
#define CListWnd__DrawLine                            0x569950 
#define CListWnd__DrawSeparator                       0x52094A 
#define CListWnd__EnsureVisible                       0x568600 
#define CListWnd__ExtendSel                           0x569530 
#define CListWnd__GetColumnFlags                      0x5678B0 
#define CListWnd__GetColumnMinWidth                   0x5679E0 
#define CListWnd__GetColumnWidth                      0x567910 
#define CListWnd__GetCurSel                           0x5676F0 
#define CListWnd__GetCursorToDisplay                  0x567600 
#define CListWnd__GetHeaderRect                       0x567530 
#define CListWnd__GetItemAtPoint                      0x5688B0 
#define CListWnd__GetItemAtPoint1                     0x568920 
#define CListWnd__GetItemData                         0x567730 
#define CListWnd__GetItemHeight                       0x5683E0 
#define CListWnd__GetItemIcon                         0x5677F0 
#define CListWnd__GetItemRect                         0x5686D0 
#define CListWnd__GetItemText                         0x567770 
#define CListWnd__GetSelList                          0x56B2A0 
#define CListWnd__GetSeparatorRect                    0x568E40 
#define CListWnd__IsLineEnabled                       0x567ED0 
#define CListWnd__SetColors                           0x5674A0 
#define CListWnd__SetColumnWidth                      0x567990 
#define CListWnd__SetCurSel                           0x567D00 
#define CListWnd__SetItemColor                        0x56ABC0 
#define CListWnd__SetItemData                         0x567E90 
#define CListWnd__SetItemText                         0x56AB00 
#define CListWnd__SetVScrollPos                       0x569090 
#define CListWnd__ShiftColumnSeparator                0x5694A0 
#define CListWnd__Sort                                0x577130 
#define CListWnd__ToggleSel                           0x567D20

// CEditWnd 
#define CEditWnd__DrawCaret                           0x57CFF0 
#define CEditWnd__DrawMultiline                       0x57E500 
#define CEditWnd__GetCaretPt                          0x57E8B0 
#define CEditWnd__GetCharIndexPt                      0x57DE00 
#define CEditWnd__GetDisplayString                    0x57D890 
#define CEditWnd__GetHorzOffset                       0x595470 
#define CEditWnd__GetLineForPrintableChar             0x57D8B0 
#define CEditWnd__GetSelEndPt                         0x57E040 
#define CEditWnd__GetSelStartPt                       0x57E020 
#define CEditWnd__GetSTMLSafeText                     0x57D570 
#define CEditWnd__PointFromPrintableChar              0x57D9C0 
#define CEditWnd__SelectableCharFromPoint             0x57DB40 
#define CEditWnd__SetEditable                         0x57D540 
#define CEditWnd__SetWindowTextA                      0x586BF0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect						  0x4EBB98 
#define CGaugeWnd__CalcLinesFillRect				  0x4EBBF4 
#define CGaugeWnd__Draw								  0x4ebef4 
#define CGaugeWnd__SetAttributesFromSidl              0x51e524

// CStmlWnd 
#define CStmlWnd__AppendSTML						  0x5669d0 
#define CStmlWnd__CalculateHSBRange					  0x55e490 
#define CStmlWnd__CalculateVSBRange                   0x55e430 
#define CStmlWnd__CanBreakAtCharacter				  0x55e5d0 
#define CStmlWnd__CanGoBackward						  0x55E650            
#define CStmlWnd__FastForwardPastSpaces               0x55efe0 
#define CStmlWnd__FastForwardToEndOfTag               0x55f340 
#define CStmlWnd__GetCursorToDisplay				  0x561D90 
#define CStmlWnd__GetNextChar						  0x55eaa0 
#define CStmlWnd__GetNextTagPiece					  0x55f150 
#define CStmlWnd__GetSTMLText						  0x4E03A5 
#define CStmlWnd__GetThisChar						  0x55e2d0 
#define CStmlWnd__GetVisiableText					  0x5212a6 
#define CStmlWnd__InitializeTempVariables             0x55e280 
#define CStmlWnd__InitializeWindowVariables           0x5628a0 
#define CStmlWnd__MakeStmlColorTag					  0x55da80 
#define CStmlWnd__MakeWndNotificationTag              0x55db20 
#define CStmlWnd__StripFirstSTMLLines				  0x566750 
#define CStmlWnd__UpdateHistoryString				  0x55d920 

// CTabWnd 
#define CTabWnd__Draw                                 0x57C240
#define CTabWnd__DrawCurrentPage                      0x57BD30 
#define CTabWnd__DrawTab							  0x57BAB0 
#define CTabWnd__GetCurrentPage                       0x57B660 
#define CTabWnd__GetCurrentTabIndex                   0x57B380 
#define CTabWnd__GetNumTabs                           0x57B4B0 
#define CTabWnd__GetPageClientRect                    0x57B390 
#define CTabWnd__GetPageFromTabIndex                  0x57AFC0 
#define CTabWnd__GetPageInnerRect                     0x57B3F0 
#define CTabWnd__GetTabInnerRect                      0x57B770 
#define CTabWnd__GetTabRect                           0x57B670 
#define CTabWnd__IndexInBounds                        0x57B4C0 
#define CTabWnd__InsertPage                           0x57C130 
#define CTabWnd__SetPage                              0x57B810 
#define CTabWnd__SetPageRect                          0x57B920 
#define CTabWnd__UpdatePage                           0x57B9D0 

// CTextOverlay 
#define CTextOverlay__DisplayText                     0x4013F8 

