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

//// 
//Section 1: Vital Offsets 
//// 
#define pinstCSidlManager                    0x7A9684 
#define pinstCDisplay                      0x737BFC 
#define pinstCEverQuest                      0x795678 
#define pinstPCData                        0x737BD8 
#define pinstCharData                      0x737BD8 
#define pinstCharSpawn                      0x737BD0 
#define pinstSpawnList                      0x737B98 
#define pinstSpawnListTail                    0x737BBC 
#define pinstWorldData                      0x737B94 
#define pinstSpellManager                    0x7920D4 
#define pinstActiveMerchant                    0x737BE8 
#define pinstSelectedItem                    0x79E21C 
#define pinstGroup                        0x736268 
#define pinstTarget                        0x737BDC 
#define pinstSwitchManager                    0x6D5440 
#define pinstEQItemList                      0x737B9C 
#define pinstSpellSets                      0x735994 
#define instEQZoneInfo                      0x6D56C4 


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCFacePick                                          0x6222EC 
#define pinstTextMessageWnd                    0x6222F0 
#define pinstCNoteWnd                                           0x6222F4 
#define pinstCHelpWnd                                           0x6222F8 
#define pinstCBookWnd                                           0x6222FC 
#define pinstCPetInfoWnd                                        0x622300 
#define pinstCTrainWnd                                          0x622304 
#define pinstCSkillsWnd                                         0x622308 
#define pinstCSkillsSelectWnd                                   0x62230C 
#define pinstCCombatAbilityWnd                                  0x622310  
#define pinstCFriendsWnd                                        0x622314 
#define pinstCAAWnd                                             0x622318 
#define pinstCGroupSearchFiltersWnd                             0x62231C 
#define pinstCLoadskinWnd                                       0x622320 
#define pinstCAlarmWnd                                          0x622324 
#define pinstCMusicPlayerWnd                                    0x622328 
#define pinstCRaidWnd                                           0x62232C 
#define pinstCRaidOptionsWnd                                    0x622330 
#define pinstCBreathWnd                                         0x622334 
#define pinstCMapViewWnd                                        0x622338 
#define pinstCMapToolbarWnd                                     0x62233C 
#define pinstCEditLabelWnd                                      0x622340 
#define pinstCTargetWnd                                         0x622344 
#define pinstCHotButtonWnd                                      0x622348 
#define pinstCColorPickerWnd                                    0x62234C 
#define pinstCPlayerWnd                                         0x622350 
#define pinstCOptionsWnd                                        0x622354 
#define pinstCBuffWindowNORMAL                                  0x622358 
#define pinstCBuffWindowSHORT                                   0x62235C 
#define pinstCCursorAttachment                                  0x622364 
#define pinstCCastingWnd                                        0x622368 
#define pinstCCastSpellWnd                                      0x62236C 
#define pinstCSpellBookWnd                                      0x622370 
#define pinstCInventoryWnd                                      0x622374 
#define pinstCBankWnd                                           0x622378 
#define pinstCQuantityWnd                                       0x62237C 
#define pinstCLootWnd                                           0x622380 
#define pinstCActionsWnd                                        0x622384 
#define pinstCCombatSkillSelectWnd                              0x622388 
#define pinstCMerchantWnd                                       0x62238C 
#define pinstCTradeWnd                                          0x622390 
#define pinstCSelectorWnd                                       0x622394 
#define pinstCBazaarWnd                                         0x622398 
#define pinstCBazaarSearchWnd                                   0x62239C 
#define pinstCGiveWnd                                           0x6223A0 
#define pinstCTrackingWnd                                       0x6223A4 
#define pinstCInspectWnd                                        0x6223A8 
#define pinstCSocialEditWnd                                     0x6223AC 
#define pinstCFeedbackWnd                                       0x6223B0 
#define pinstCBugReportWnd                                      0x6223B4 
#define pinstCVideoModesWnd                                     0x6223B8 
#define pinstCTextEntryWnd                                      0x6223BC 
#define pinstCFileSelectionWnd                                  0x6223C0 
#define pinstCCompassWnd                                        0x6223C4 
#define pinstCPlayerNotesWnd                                    0x6223C8 
#define pinstCGemsGameWnd                                       0x6223CC 
#define pinstCTimeLeftWnd                                       0x6223D0 
#define pinstCPetitionQWnd                                      0x6223D4 
#define pinstCSoulmarkWnd                                       0x6223D8 
#define pinstCStoryWnd                                          0x6223DC 
#define pinstCJournalTextWnd                                    0x6223E0 
#define pinstCJournalCatWnd                                     0x6223E4 
#define pinstCBodyTintWnd                                       0x6223E8 
#define pinstCContainerMgr                                      0x6223F0 
#define pinstCInvSlotMgr                                        0x6223EC 
#define pinstCAdventureRequestWnd                               0x6D641C 
#define pinstCLeadershipWnd                    0x6D6420
#define pinstCAdventureLeaderboardWnd                           0x79DCD8 
#define pinstCAdventureMerchantWnd                              0x79DCF0 
#define pinstCAdventureStatsWnd                                 0x79DD20 
#define pinstCChatManager                                       0x79DF98 
#define pinstCDynamicZoneWnd                  0x79E064  
#define pinstCFindLocationWnd                                   0x79E0F4 
#define pinstCGroupSearchWnd                                    0x79E170 
#define pinstCGroupWnd                                          0x79E188 
#define pinstCGuildMgmtWnd                                      0x79E1A0
#define pinstCPopupWndManager                  0x79E3EC  
#define pinstCSystemInfoDialogBox                               0x79EC6C 
#define pinstCTargetOfTargetWnd                  0x79EC84 
#define pinstCTipWndOFDAY                                       0x79ECEC 
#define pinstCTipWndCONTEXT                                     0x79ECF0 
#define pinstCTradeskillWnd                    0x79ED1C 
#define pinstCTributeBenefitWnd                                 0x79ED5C 
#define pinstCTributeMasterWnd                  0x79ED74 
#define pinstCContextMenuManager                                0x7A96A0 


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define DrawNetStatus                      0x4B31D4 
#define CrashDetected                      0x4C37F3 

// EQ_LoadingS 
#define EQ_LoadingS__WriteTextHD                0x43296F 


//// 
// Section 4: Function Offsets 
//// 

// CEverQuest 
#define CEverQuest__dsp_chat                  0x499D67 
#define CEverQuest__ClickedPlayer                0x497794 
#define CEverQuest__EnterZone                  0x49ABBB 
#define CEverQuest__InterpretCmd                0x4A6A7B 
#define CEverQuest__RightClickedOnPlayer            0x4A2975 
#define CEverQuest__LeftClickedOnPlayer              0x4A8C40 
#define CEverQuest__GetRaceDesc                  0x491A58 
#define CEverQuest__GetClassDesc                0x4911D5 
#define CEverQuest__GetDeityDesc                0x4931E6 
#define CEverQuest__GetBodyTypeDesc                0x4915F0 
#define CEverQuest__SetGameState                0x4978FB 

// CXWndManager
#define CXWndManager__RemoveWnd					0x56CDB0

// EQ_Character 
#define EQ_Character__Max_Mana                  0x41E176 
#define EQ_Character__Max_HP                  0x41DF69 
#define EQ_Character__Cur_HP                  0x42198F 
#define EQ_Character__GetFocusCastingTimeModifier        0x42911A 
#define EQ_Character__GetAACastingTimeModifier          0x4294A7 
#define EQ_Character__CastSpell                  0x42CFD4 

// EQPlayer
#define EQPlayer__EQPlayer                       0x48A1E1
#define EQPlayer__dEQPlayer                      0x488684

// CXStr 
// WARNING:  Be sure that none of these offsets are identical!  Otherwise, you
//           will cause a memory leak and Lax will pee in your bed!
#define CXStr__CXStr                      0x40104C 
#define CXStr__CXStr1                      0x401046 
#define CXStr__CXStr3                      0x59BC60 
#define CXStr__dCXStr                      0x4CE293 
#define CXStr__operator_plus_equal1                0x59CCF0 
#define CXStr__operator_equal1                  0x59BE20 

// CStmlWnd 
#define CStmlWnd__AppendSTML                  0x5660A0 

// CChatWindow 
#define CChatWindow__CChatWindow                0x4DF84D 
#define CChatWindow__dCChatWindow                0x4B95C2 

// CChatManager 
#define CChatManager__InitContextMenu              0x4DCD75 
#define CChatManager__GetRGBAFromIndex              0x4DC411 

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                0x4FA86C 
#define CInvSlotMgr__MoveItem                  0x4FA217 

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                0x4FD3BF 
#define CItemDisplayWnd__SetSpell                0x4FC927 

// CLabel 
#define CLabel__Draw                      0x503238 

// CDisplay 
#define CDisplay__ReloadUI                    0x4185E3 
#define CDisplay__CleanGameUI                  0x41179C 
#define CDisplay__GetClickedActor                0x40D5A5 
#define CDisplay__WriteTextHD2                  0x412198 
#define CDisplay__GetWorldFilePath                0x40BC45 

// EQ_Item 
#define EQ_Item__GetItemLinkHash                0x4323D3 

// CBankWnd 
#define CBankWnd__GetNumBankSlots                0x4CE37F 

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg            0x4D0A31 

// CMerchantWnd 
#define CMerchantWnd__SelectBuySellSlot              0x50B94B 
#define CMerchantWnd__RequestBuyItem              0x50AB5C 
#define CMerchantWnd__RequestSellItem              0x50AECB 
    
// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                0x51CEC2 

// MapViewMap 
#define MapViewMap__SaveEx                    0x5066FE 
#define MapViewMap__Clear						0x0506184

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd					0x509A55

// EQItemList
#define EQItemList__EQItemList						0x44FC6E
#define EQItemList__dEQItemList						0x44FCEA

//
#define EQ_PC__DestroyHeldItemOrMoney              0x4352EB 

// CSidlScreenWnd 
#define CSidlScreenWnd__CSidlScreenWnd1              0x550C60 
#define CSidlScreenWnd__dCSidlScreenWnd              0x550300 
#define CSidlScreenWnd__CreateChildrenFromSidl          0x54F680 
#define CSidlScreenWnd__GetChildItem              0x54EF90 
#define CSidlScreenWnd__WndNotification              0x54F200 
#define CSidlScreenWnd__CalculateHSBRange            0x54E760 
#define CSidlScreenWnd__CalculateVSBRange            0x54E820 
#define CSidlScreenWnd__ConvertToRes              0x54EF10 
#define CSidlScreenWnd__CSidlScreenWnd2              0x550C60 
#define CSidlScreenWnd__DrawBackground              0x550490 
#define CSidlScreenWnd__DrawSidlPiece              0x54F2A0 
#define CSidlScreenWnd__EnableIniStorage            0x54EEC0 
#define CSidlScreenWnd__GetSidlPiece              0x54F540 
#define CSidlScreenWnd__HandleRButtonDown            0x54F000 
#define CSidlScreenWnd__Init1                  0x550820 
#define CSidlScreenWnd__LoadIniInfo                0x54F730 
#define CSidlScreenWnd__LoadIniListWnd              0x550060 
#define CSidlScreenWnd__LoadSidlScreen              0x54F0E0 
#define CSidlScreenWnd__OnResize                0x54E8D0 
#define CSidlScreenWnd__SetScreen                0x550420 
#define CSidlScreenWnd__StoreIniInfo              0x54EA50 
#define CSidlScreenWnd__StoreIniListWnd              0x550110 
             
// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1          0x575390  

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead              0x55CB50        

// CXRect
#define CXRect__CenterPoint					0x4CE386

// CXWnd 
#define CXWnd__Bottom                      0x554D20 
#define CXWnd__BringToTop                    0x5511F0 
#define CXWnd__Center                      0x554AB0 
#define CXWnd__ClrFocus                      0x551130 
#define CXWnd__Deactivate                    0x54EA40 
#define CXWnd__DoAllDrawing                    0x5555B0 
#define CXWnd__DrawBackground                  0x554780 
#define CXWnd__DrawChildren                    0x555760 
#define CXWnd__DrawCloseBox                    0x552F80 
#define CXWnd__DrawColoredRect                  0x551410 
#define CXWnd__DrawCursor                    0x5511A0 
#define CXWnd__DrawHScrollbar                  0x553560 
#define CXWnd__DrawLasso                    0x554640 
#define CXWnd__DrawMinimizeBox                  0x552F80 
#define CXWnd__DrawNC                      0x555257 
#define CXWnd__DrawTileBox                    0x552F80 
#define CXWnd__DrawTitleBar                    0x55334D 
#define CXWnd__DrawTooltip                    0x5554D0 
#define CXWnd__DrawTooltipAtPoint                0x5548E0 
#define CXWnd__DrawVScrollbar                  0x553960 
#define CXWnd__GetBorderFrame                  0x551850 
#define CXWnd__GetChildWndAt                  0x5544A0 
#define CXWnd__GetClientClipRect                0x551790 
#define CXWnd__GetClientRect                  0x403CCA 
#define CXWnd__GetCloseBoxTemplate                0x5518B3 
#define CXWnd__GetCursorToDisplay                0x5512D0 
#define CXWnd__GetDragDropCursor                0x551740 
#define CXWnd__GetFirstChildWnd                  0x551280 
#define CXWnd__GetHitTestRect                  0x5522D0 
#define CXWnd__GetInnerRect                    0x403CC5 
#define CXWnd__GetMinimizeBoxTemplate              0x5518E0 
#define CXWnd__GetMinimizedRect                  0x554010 
#define CXWnd__GetNextChildWnd                  0x554480 
#define CXWnd__GetNextSib                    0x5512A0 
#define CXWnd__GetScreenClipRect                0x554D70 
#define CXWnd__GetScreenRect                  0x551A20 
#define CXWnd__GetTileBoxTemplate                0x551900 
#define CXWnd__GetTooltip                    0x551180 
#define CXWnd__GetTooltipRect                  0x551660 
#define CXWnd__GetUntileSize                  0x403CAB 
#define CXWnd__GetWindowTextA                  0x4C8E77 
#define CXWnd__GetXMLTooltip                  0x550f70 
#define CXWnd__HitTest                      0x554520 
#define CXWnd__IsActive                      0x551800 
#define CXWnd__IsDescendantOf                  0x551810 
#define CXWnd__IsReallyVisible                  0x551250 
#define CXWnd__IsValid                      0x403C89 
#define CXWnd__Left                        0x554B80 
#define CXWnd__Move                        0x553E80 
#define CXWnd__Move1                      0x553F10 
#define CXWnd__PostDraw                      0x4AD538 
#define CXWnd__ProcessTransition                0x554060 
#define CXWnd__QueryClickStickDropOK              0x551750 
#define CXWnd__QueryDropOK                    0x551700 
#define CXWnd__Refade                      0x5511D0 
#define CXWnd__RequestDockInfo                  0x552250 
#define CXWnd__Resize                      0x554EA0 
#define CXWnd__SetAttributesFromSidl              0x554DE0 
#define CXWnd__SetFirstChildPointer                0x551280 
#define CXWnd__SetFocus                      0x552F53 
#define CXWnd__SetKeyTooltip                  0x551CB0 
#define CXWnd__SetMouseOver                    0x551C90 
#define CXWnd__SetNextSibPointer                0x551C80 
#define CXWnd__SetVScrollPos                  0x5515e0 
#define CXWnd__StartFade                    0x551210 

// CSliderWnd 
#define CSliderWnd__GetValue                  0x580BA0 
#define CSliderWnd__UpdateThumb                  0x580B80 
#define CSliderWnd__SetValue                  0x580D70                  

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                0x4CDEE1 
#define CEditBaseWnd__SetSel                  0x577330 
             
// CComboWnd 
#define CComboWnd__DeleteAll                  0x57C2F0 
#define CComboWnd__Draw                      0x57C4F0 
#define CComboWnd__GetButtonRect                0x57C320 
#define CComboWnd__GetCurChoice                  0x57C2B0 
#define CComboWnd__GetListRect                  0x57C8E0 
#define CComboWnd__GetTextRect                  0x57C380 
#define CComboWnd__HitTest                    0x4D4C36 
#define CComboWnd__InsertChoice                  0x57C940 
#define CComboWnd__SetColors                  0x57C280 
#define CComboWnd__SetChoice                  0x57CA20

// CListWnd 
#define CListWnd__CalculateFirstVisibleLine            0x567CA0 
#define CListWnd__Sort                      0x576F60 
#define CListWnd__DrawSeparator                  0x52019F 
#define CListWnd__ShiftColumnSeparator              0x568B90 
#define CListWnd__GetItemText                  0x566E60 
#define CListWnd__ExtendSel                    0x568C20 
#define CListWnd__SetItemColor                  0x56A2B0 
#define CListWnd__DrawColumnSeparators              0x561430 
#define CListWnd__CalculateLineHeights              0x567C40 
#define CListWnd__SetItemText                  0x56A1F0 
#define CListWnd__CloseAndUpdateEditWindow            0x5682A0 
#define CListWnd__Compare                    0x5685E0 
#define CListWnd__CalculateVSBRange                0x569810 
#define CListWnd__GetItemHeight                  0x567AD0 
#define CListWnd__AddLine                    0x56A670 
#define CListWnd__AddString                    0x56A7F0 
#define CListWnd__Draw                      0x569470 
#define CListWnd__ClearAllSel                  0x5674D0 
#define CListWnd__GetSelList                  0x56A990 
#define CListWnd__GetItemAtPoint                0x567FA0 
#define CListWnd__GetItemAtPoint1                0x568010 
#define CListWnd__GetSeparatorRect                0x568530 
#define CListWnd__EnsureVisible                  0x567CF0 
#define CListWnd__GetHeaderRect                  0x566C20 
#define CListWnd__DrawHeader                  0x5693A0 
#define CListWnd__GetItemRect                  0x567DC0 
#define CListWnd__DrawBackground                0x566C60 
#define CListWnd__DrawLine                    0x569040 
#define CListWnd__DrawItem                    0x568CF0    
#define CListWnd__SetVScrollPos                  0x568780 
#define CListWnd__GetColumnMinWidth                0x5670D0 
#define CListWnd__ToggleSel                    0x567410 
#define CListWnd__SetCurSel                    0x5673F0 
#define CListWnd__GetItemData                  0x566E20 
#define CListWnd__GetItemIcon                  0x566EE0 
#define CListWnd__SetItemData                  0x567580 
#define CListWnd__IsLineEnabled                  0x5675C0 
#define CListWnd__GetColumnWidth                0x567000 
#define CListWnd__GetColumnFlags                0x566FA0 
#define CListWnd__SetColumnWidth                0x567080 
#define CListWnd__GetCurSel                    0x566DE0 
#define CListWnd__GetCursorToDisplay              0x566CF0 
#define CListWnd__SetColors                    0x566B90 

// CEditWnd 
#define CEditWnd__GetLineForPrintableChar            0x57D640 
#define CEditWnd__PointFromPrintableChar            0x57D750 
#define CEditWnd__GetCharIndexPt                0x57DB90 
#define CEditWnd__SetWindowTextA                0x586950 
#define CEditWnd__DrawMultiline                  0x57E290 
#define CEditWnd__GetHorzOffset                  0x595220 
#define CEditWnd__GetSTMLSafeText                0x57D300 
#define CEditWnd__DrawCaret                    0x57CD80 
#define CEditWnd__SetEditable                  0x57D2D0 
#define CEditWnd__GetCaretPt                  0x57E640 
#define CEditWnd__SelectableCharFromPoint            0x587780 
#define CEditWnd__GetSelStartPt                  0x57DDB0 
#define CEditWnd__GetSelEndPt                  0x57DDD0 
#define CEditWnd__GetDisplayString                0x57D620 

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                  0x4EBD03 
#define CGaugeWnd__CalcLinesFillRect              0x4EBD5F 
#define CGaugeWnd__Draw                      0x4EC05F 
#define CGaugeWnd__SetAttributesFromSidl            0x51DD7F 

// CStmlWnd 
#define CStmlWnd__GetCursorToDisplay              0x561460 
#define CStmlWnd__GetSTMLText                  0x4DF82F 
#define CStmlWnd__GetVisiableText                0x520AB4 
#define CStmlWnd__CanBreakAtCharacter              0x55DC00 
#define CStmlWnd__GetThisChar                  0x55D920 
#define CStmlWnd__InitializeWindowVariables            0x561F70 
#define CStmlWnd__FastForwardPastSpaces              0x55E640 
#define CStmlWnd__GetNextTagPiece                0x55E7B0 
#define CStmlWnd__GetNextChar                  0x55E0C0 
#define CStmlWnd__UpdateHistoryString              0x55CF50 
#define CStmlWnd__MakeStmlColorTag                0x55D0B0 
#define CStmlWnd__FastForwardToEndOfTag              0x55E9A0 
#define CStmlWnd__MakeWndNotificationTag            0x55D150 
#define CStmlWnd__StripFirstSTMLLines              0x565E20 
#define CStmlWnd__CalculateHSBRange                0x55DAC0 
#define CStmlWnd__CalculateVSBRange                0x55DA60 
#define CStmlWnd__InitializeTempVariables            0x55D8D0 
#define CStmlWnd__CanGoBackward                  0x55DC80 

// CTabWnd 
#define CTabWnd__Draw                      0x57BFD0 
#define CTabWnd__GetPageFromTabIndex              0x57B2F0 
#define CTabWnd__InsertPage                    0x57BEC0 
#define CTabWnd__SetPage                    0x57B5A0 
#define CTabWnd__UpdatePage                    0x57B760 
#define CTabWnd__SetPageRect                  0x57B6B0 
#define CTabWnd__GetTabInnerRect                0x57B500 
#define CTabWnd__GetPageInnerRect                0x57B200 
#define CTabWnd__GetTabRect                    0x57B400 
#define CTabWnd__DrawCurrentPage                0x57BAC0 
#define CTabWnd__DrawTab                    0x57B840 
#define CTabWnd__GetPageClientRect                0x57B1A0 
#define CTabWnd__IndexInBounds                  0x57B2D0 
#define CTabWnd__GetNumTabs                    0x57B2C0 
#define CTabWnd__GetCurrentTabIndex                0x57B190 
#define CTabWnd__GetCurrentPage                  0x57B3F0 
