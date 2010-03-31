/****************************************************************************** 
    MQ2Main.dll: MacroQuest2's extension DLL for EverQuest 
    Copyright (C) 2002-2003 Plazmic, 2003-2005 Lax 

    This program is free software; you can redistribute it and/or modify 
    it under the terms of the GNU General Public License, version 2, as 
    published by the Free Software Foundation. 

    This program is distributed in the hope that it will be useful, 
    but WITHOUT ANY WARRANTY; without even the implied warranty of 
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
    GNU General Public License for more details. 
******************************************************************************/ 
#ifdef PRIVATE 
#include "eqgame-private.h" 
#endif 

#define __ClientName                                       "eqgame" 
#define __ExpectedVersionDate                              "Feb 14 2005" 
#define __ExpectedVersionTime                              "12:06:17" 
#define __ActualVersionDate                                0x61080C 
#define __ActualVersionTime                                0x610818 

#define __ClientOverride                                   0 
#define __MacroQuestWinClassName                           "__MacroQuestTray" 
#define __MacroQuestWinName                                "MacroQuest" 

// Memory Protection 
#define __MemChecker0                                      0x50B342 
#define __MemChecker2                                      0x548CD8 
#define __MemChecker3                                      0x548D65 
#define __MemChecker4                                      0x5C3920 
#define __EncryptPad0                                      0x7320C8 
#define __EncryptPad2                                      0x7353A8 
#define __EncryptPad3                                      0x7357A8 
#define __EncryptPad4                                      0x73A170 

// Direct Input 
#define DI8__Main                                          0x90D2EC 
#define DI8__Keyboard                                      0x90D2F0 
#define DI8__Mouse                                         0x90D2F4 

#define __AltTimerReady                                    0x87FB96 
#define __Attack                                           0x8DF69C 
#define __BindList                                         0x639D50 
#define __Clicks                                           0x87EDA4 
#define __CommandList                                      0x63A2E0 
#define __CurrentMapLabel                                  0x8FF62C 
#define __CurrentSocial                                    0x63D730 
#define __DoAbilityAvailable                               0x87FB30 
#define __DoAbilityList                                    0x8B88F4 
#define __DrawHandler                                      0x91772C 
#define __EQP_IDArray                                      0x7CCF58 
#define __FriendsList                                      0x8B56B4 
#define __GroupCount                                       0x8DFA30 
#define __GroupLeader                                      0x8DFB8C 
#define __Guilds                                           0x8E7478 
#define __gWorld                                           0x8E1488 
#define __HotkeyPage                                       0x8DF254 
#define __HWnd                                             0x87ECA0 
#define __IgnoreList                                       0x8B6FB4 
#define __InChatMode                                       0x87ECE0 
#define __LastTell                                         0x880E20 
#define __Mouse                                            0x90D2F8 
#define __MouseLook                                        0x87ED72 
#define __NetStatusToggle                                  0x87ED74 
#define __PCNames                                          0x87FE2C 
#define __RangeAttackReady                                 0x87FB94 
#define __ScreenMode                                       0x7CAAD8 
#define __ScreenX                                          0x87ECA8 
#define __ScreenY                                          0x87ECAC 
#define __ServerHost                                       0x8DF8EC 
#define __ServerName                                       0x8B88B4 
#define __ShowNames                                        0x87FD7C 
#define __SkillDict                                        0x7D02E8 
#define __Socials                                          0x8B89B4 

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                          0x8E1520 
#define instEQZoneInfo                                     0x87EF10 
#define instKeypressHandler                                0x8FF2DC 
#define pinstActiveBanker                                  0x8E1500 
#define pinstActiveCorpse                                  0x8E1504 
#define pinstActiveGMaster                                 0x8E1508 
#define pinstActiveMerchant                                0x8E14FC 
#define pinstAltAdvManager                                 0x7CFE90 
#define pinstCCursorAttachment                             0x7CB5F4 
#define pinstCDisplay                                      0x8E1510 
#define pinstCEverQuest                                    0x90D460 
#define pinstCharData                                      0x8E14EC 
#define pinstCharSpawn                                     0x8E14E4 
#define pinstControlledPlayer                              0x8E14E4 
#define pinstCSidlManager                                  0x91672C 
#define pinstCXWndManager                                  0x916724 
#define pinstEQItemList                                    0x8E14B0 
#define pinstGroup                                         0x8DFB78 
#define pinstLocalPlayer                                   0x8E14D0 
#define pinstPCData                                        0x8E14EC 
#define pinstSelectedItem                                  0x8FF25C 
#define pinstSpawnList                                     0x8E14AC 
#define pinstSpellManager                                  0x8FF988 
#define pinstSpellSets                                     0x8DF258 
#define pinstStringTable                                   0x8E1498 
#define pinstSwitchManager                                 0x7CFE8C 
#define pinstTarget                                        0x8E14F0 
#define pinstTargetSwitch                                  0x8E14F8 
#define pinstTradeTarget                                   0x8E14CC 
#define pinstWorldData                                     0x8E14A8 


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                  0x73BD80 
#define pinstCharacterSelect                               0x7CB56C 
#define pinstCFacePick                                     0x7CB570 
#define pinstCNoteWnd                                      0x7CB574 
#define pinstCHelpWnd                                      0x7CB578 
#define pinstCBookWnd                                      0x7CB57C 
#define pinstCPetInfoWnd                                   0x7CB580 
#define pinstCTrainWnd                                     0x7CB584 
#define pinstCSkillsWnd                                    0x7CB588 
#define pinstCSkillsSelectWnd                              0x7CB58C 
#define pinstCCombatSkillSelectWnd                         0x7CB590 
#define pinstCFriendsWnd                                   0x7CB594 
#define pinstCAAWnd                                        0x7CB5A0 
#define pinstCGroupSearchFiltersWnd                        0x7CB5A4 
#define pinstCLoadskinWnd                                  0x7CB5A8 
#define pinstCAlarmWnd                                     0x7CB5AC 
#define pinstCMusicPlayerWnd                               0x7CB5B0 
#define pinstCRaidWnd                                      0x7CB5BC 
#define pinstCRaidOptionsWnd                               0x7CB5C0 
#define pinstCBreathWnd                                    0x7CB5C4 
#define pinstCMapViewWnd                                   0x7CB5C8 
#define pinstCMapToolbarWnd                                0x7CB5CC 
#define pinstCEditLabelWnd                                 0x7CB5D0 
#define pinstCTargetWnd                                    0x7CB5D4 
#define pinstCHotButtonWnd                                 0x7CB5D8 
#define pinstCColorPickerWnd                               0x7CB5DC 
#define pinstCPlayerWnd                                    0x7CB5E0 
#define pinstCOptionsWnd                                   0x7CB5E4 
#define pinstCBuffWindowNORMAL                             0x7CB5E8 
#define pinstCBuffWindowSHORT                              0x7CB5EC 
#define pinstCharacterCreation                             0x7CB5F0 
#define pinstCCursorAttachment                             0x7CB5F4 
#define pinstCCastingWnd                                   0x7CB5F8 
#define pinstCCastSpellWnd                                 0x7CB5FC 
#define pinstCSpellBookWnd                                 0x7CB600 
#define pinstCInventoryWnd                                 0x7CB604 
#define pinstCBankWnd                                      0x7CB608 
#define pinstCQuantityWnd                                  0x7CB60C 
#define pinstCLootWnd                                      0x7CB610 
#define pinstCActionsWnd                                   0x7CB614 
#define pinstCCombatAbilityWnd                             0x7CB618 
#define pinstCMerchantWnd                                  0x7CB61C 
#define pinstCTradeWnd                                     0x7CB620 
#define pinstCSelectorWnd                                  0x7CB624 
#define pinstCBazaarWnd                                    0x7CB628 
#define pinstCBazaarSearchWnd                              0x7CB62C 
#define pinstCGiveWnd                                      0x7CB630 
#define pinstCTrackingWnd                                  0x7CB634 
#define pinstCInspectWnd                                   0x7CB638 
#define pinstCSocialEditWnd                                0x7CB63C 
#define pinstCFeedbackWnd                                  0x7CB640 
#define pinstCBugReportWnd                                 0x7CB644 
#define pinstCVideoModesWnd                                0x7CB648 
#define pinstCTextEntryWnd                                 0x7CB650 
#define pinstCFileSelectionWnd                             0x7CB654 
#define pinstCCompassWnd                                   0x7CB658 
#define pinstCPlayerNotesWnd                               0x7CB65C 
#define pinstCGemsGameWnd                                  0x7CB660 
#define pinstCTimeLeftWnd                                  0x7CB664 
#define pinstCPetitionQWnd                                 0x7CB668 
#define pinstCSoulmarkWnd                                  0x7CB66C 
#define pinstCStoryWnd                                     0x7CB670 
#define pinstCJournalTextWnd                               0x7CB674 
#define pinstCJournalCatWnd                                0x7CB678 
#define pinstCBodyTintWnd                                  0x7CB67C 
#define pinstCInvSlotMgr                                   0x7CB684 
#define pinstCContainerMgr                                 0x7CB688 
#define pinstCAdventureLeaderboardWnd                      0x73BA2C 
#define pinstCAdventureMerchantWnd                         0x73BA48 
#define pinstCAdventureRequestWnd                          0x73BA64 
#define pinstCAdventureStatsWnd                            0x73BA80 
#define pinstCChatManager                                  0x73BEB0 
#define pinstCDynamicZoneWnd                               0x7CB794 
#define pinstCFindLocationWnd                              0x8FF060 
#define pinstCGroupSearchWnd                               0x8FF158 
#define pinstCGroupWnd                                     0x8FF174 
#define pinstCGuildMgmtWnd                                 0x8FF1AC 
#define pinstCItemDisplayManager                           0x8FF290 
#define pinstCLeadershipWnd                                0x8FF378 
#define pinstCPopupWndManager                              0x8FF780 
#define pinstCSystemInfoDialogBox                          0x900130 
#define pinstCTargetOfTargetWnd                            0x900154 
#define pinstCTipWndOFDAY                                  0x900244 
#define pinstCTipWndCONTEXT                                0x900248 
#define pinstCTradeskillWnd                                0x900340 
#define pinstCTributeBenefitWnd                            0x90038C 
#define pinstCTributeMasterWnd                             0x9003A8 
#define pinstCContextMenuManager                           0x916784 
// unknown window added 4-14 exe 0x79A234 


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                          0x46DE97 
#define __ConvertItemTags                                  0x46D6F1 
#define __ExecuteCmd                                       0x45FD1C 
#define __get_melee_range                                  0x464185 
#define __GetGaugeValueFromEQ                              0x5313DB 
#define __LoadSplashScreen                                 0x5CADC0 
#define __NewUIINI                                         0x531CB3 
#define __ProcessGameEvents                                0x4CEC4C 
#define __SendMessage                                      0x4B5DB0 
#define CrashDetected                                      0x548994 
#define DrawNetStatus                                      0x50FA59 


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                  0x4921B0 
#define AltAdvManager__IsAbilityReady                      0x4921DE 

// CBankWnd 
#define CBankWnd__GetNumBankSlots                          0x40B9DA 

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                  0x412DC2 

// CButtonWnd 
#define CButtonWnd__SetCheck                               0x58B810 

// CChatManager 
#define CChatManager__GetRGBAFromIndex                     0x4243BC 
#define CChatManager__InitContextMenu                      0x4244A0 

// CChatWindow 
#define CChatWindow__CChatWindow                           0x427433 

// CComboWnd 
#define CComboWnd__DeleteAll                               0x58C480 
#define CComboWnd__Draw                                    0x58C680 
#define CComboWnd__GetButtonRect                           0x58C4B0 
#define CComboWnd__GetCurChoice                            0x58C440 
#define CComboWnd__GetListRect                             0x58CA70 
#define CComboWnd__GetTextRect                             0x58C510 
#define CComboWnd__InsertChoice                            0x58CAD0 
#define CComboWnd__SetColors                               0x58C410 
#define CComboWnd__SetChoice                               0x58CBB0 

// CContainerWnd 
#define CContainerWnd__HandleCombine                       0x4332F4 
#define CContainerWnd__vftable                             0x5F8418 

// CDisplay 
#define CDisplay__CleanGameUI                              0x442B65 
#define CDisplay__GetClickedActor                          0x43F7CC 
#define CDisplay__GetUserDefinedColor                      0x43EB8F 
#define CDisplay__GetWorldFilePath                         0x43E363 
#define CDisplay__ReloadUI                                 0x44A3E3 
#define CDisplay__WriteTextHD2                             0x443805 

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                          0x408150 
#define CEditBaseWnd__SetSel                               0x59D530 

// CEditWnd 
#define CEditWnd__DrawCaret                                0x5995B0 
#define CEditWnd__GetCharIndexPt                           0x59A400 
#define CEditWnd__GetDisplayString                         0x599710 
#define CEditWnd__GetHorzOffset                            0x599980 
#define CEditWnd__GetLineForPrintableChar                  0x599EA0 
#define CEditWnd__GetSelStartPt                            0x59A640 
#define CEditWnd__GetSTMLSafeText                          0x599B60 
#define CEditWnd__PointFromPrintableChar                   0x599FB0 
#define CEditWnd__SelectableCharFromPoint                  0x59A130 
#define CEditWnd__SetEditable                              0x599B30 

// CEverQuest 
#define CEverQuest__ClickedPlayer                          0x4BB1DB 
#define CEverQuest__DropHeldItemOnGround                   0x4C219D 
#define CEverQuest__dsp_chat                               0x4BD29A 
#define CEverQuest__EnterZone                              0x4CD9B9 
#define CEverQuest__GetBodyTypeDesc                        0x4B6F2B 
#define CEverQuest__GetClassDesc                           0x4B694E 
#define CEverQuest__GetClassThreeLetterCode                0x4B6DC8 
#define CEverQuest__GetDeityDesc                           0x4B89BE 
#define CEverQuest__GetRaceDesc                            0x4B7230 
#define CEverQuest__InterpretCmd                           0x4C76D9 
#define CEverQuest__LeftClickedOnPlayer                    0x4CC311 
#define CEverQuest__RightClickedOnPlayer                   0x4CC747 
#define CEverQuest__SetGameState                           0x4BB2BB 

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                            0x4DA4F6 
#define CGaugeWnd__CalcLinesFillRect                       0x4DA552 
#define CGaugeWnd__Draw                                    0x4DA852 

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                         0x4EA85A 

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                           0x4EDFF9 
#define CInvSlotMgr__MoveItem                              0x4EE127 

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                           0x4F3247 
#define CItemDisplayWnd__SetSpell                          0x4F21CF 

// CLabel 
#define CLabel__Draw                                       0x4FA866 

// CListWnd 
#define CListWnd__AddColumn                                0x575E80 
#define CListWnd__AddColumn1                               0x5759D0 
#define CListWnd__AddLine                                  0x575590 
#define CListWnd__AddString                                0x575710 
#define CListWnd__CalculateFirstVisibleLine                0x572B00 
#define CListWnd__CalculateVSBRange                        0x574690 
#define CListWnd__ClearAllSel                              0x572260 
#define CListWnd__CloseAndUpdateEditWindow                 0x573100 
#define CListWnd__Compare                                  0x573440 
#define CListWnd__Draw                                     0x5742F0 
#define CListWnd__DrawColumnSeparators                     0x574140 
#define CListWnd__DrawHeader                               0x572480 
#define CListWnd__DrawItem                                 0x573B50 
#define CListWnd__DrawLine                                 0x573EB0 
#define CListWnd__DrawSeparator                            0x574210 
#define CListWnd__EnsureVisible                            0x572B50 
#define CListWnd__ExtendSel                                0x573A80 
#define CListWnd__GetColumnFlags                           0x571D30 
#define CListWnd__GetColumnJustification                   0x571ED0 
#define CListWnd__GetColumnMinWidth                        0x571E60 
#define CListWnd__GetColumnWidth                           0x571D90 
#define CListWnd__GetCurSel                                0x571B70 
#define CListWnd__GetHeaderRect                            0x5719B0 
#define CListWnd__GetItemAtPoint                           0x572E00 
#define CListWnd__GetItemAtPoint1                          0x572E70 
#define CListWnd__GetItemData                              0x571BB0 
#define CListWnd__GetItemHeight                            0x572880 
#define CListWnd__GetItemIcon                              0x571C70 
#define CListWnd__GetItemRect                              0x572C20 
#define CListWnd__GetItemText                              0x571BF0 
#define CListWnd__GetSelList                               0x5758B0 
#define CListWnd__GetSeparatorRect                         0x573390 
#define CListWnd__IsLineEnabled                            0x572350 
#define CListWnd__RemoveLine                               0x575860 
#define CListWnd__SetColors                                0x571920 
#define CListWnd__SetColumnJustification                   0x571F30 
#define CListWnd__SetColumnWidth                           0x571E10 
#define CListWnd__SetCurSel                                0x572180 
#define CListWnd__SetItemColor                             0x5751D0 
#define CListWnd__SetItemData                              0x572310 
#define CListWnd__SetItemText                              0x575110 
#define CListWnd__ShiftColumnSeparator                     0x5739F0 
#define CListWnd__Sort                                     0x575F20 
#define CListWnd__ToggleSel                                0x5721A0 

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                           0x50A323 

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                0x50B825 
#define CMerchantWnd__RequestBuyItem                       0x50C212 
#define CMerchantWnd__RequestSellItem                      0x50BB59 
#define CMerchantWnd__SelectBuySellSlot                    0x50C092 

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1             0x5975A0 

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                  0x569D80 
#define CSidlScreenWnd__CalculateVSBRange                  0x569CC0 
#define CSidlScreenWnd__ConvertToRes                       0x56A470 
#define CSidlScreenWnd__CreateChildrenFromSidl             0x56ABE0 
#define CSidlScreenWnd__CSidlScreenWnd1                    0x56C2E0 
#define CSidlScreenWnd__CSidlScreenWnd2                    0x56C3D0 
#define CSidlScreenWnd__dCSidlScreenWnd                    0x56B930 
#define CSidlScreenWnd__DrawSidlPiece                      0x56A800 
#define CSidlScreenWnd__EnableIniStorage                   0x56A420 
#define CSidlScreenWnd__GetSidlPiece                       0x56AAA0 
#define CSidlScreenWnd__Init1                              0x56C030 
#define CSidlScreenWnd__LoadIniInfo                        0x56AC90 
#define CSidlScreenWnd__LoadIniListWnd                     0x56B5D0 
#define CSidlScreenWnd__LoadSidlScreen                     0x56A640 
#define CSidlScreenWnd__SetScreen                          0x56BA50 
#define CSidlScreenWnd__StoreIniInfo                       0x569FB0 
#define CSidlScreenWnd__WndNotification                    0x56A760 

// CSliderWnd 
#define CSliderWnd__GetValue                               0x58CEF0 
#define CSliderWnd__SetValue                               0x58D0D0 
#define CSliderWnd__UpdateThumb                            0x58CEB0 

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                         0x52F441 

// CStmlWnd 
#define CStmlWnd__AppendSTML                               0x57F420 
#define CStmlWnd__CalculateHSBRange                        0x576D20 
#define CStmlWnd__CalculateVSBRange                        0x576CC0 
#define CStmlWnd__CanBreakAtCharacter                      0x576E60 
#define CStmlWnd__CanGoBackward                            0x576EE0 
#define CStmlWnd__FastForwardToEndOfTag                    0x577BD0 
#define CStmlWnd__GetNextChar                              0x577320 
#define CStmlWnd__GetNextTagPiece                          0x5779D0 
#define CStmlWnd__GetSTMLText                              0x427415 
#define CStmlWnd__GetThisChar                              0x576B80 
#define CStmlWnd__GetVisiableText                          0x5793A0 
#define CStmlWnd__InitializeWindowVariables                0x57B1A0 
#define CStmlWnd__MakeStmlColorTag                         0x576250 
#define CStmlWnd__MakeWndNotificationTag                   0x5762F0 
#define CStmlWnd__StripFirstSTMLLines                      0x57F1A0 
#define CStmlWnd__UpdateHistoryString                      0x5797E0 

// CTabWnd 
#define CTabWnd__Draw                                      0x583230 
#define CTabWnd__DrawCurrentPage                           0x582D20 
#define CTabWnd__DrawTab                                   0x582AA0 
#define CTabWnd__GetCurrentPage                            0x582590 
#define CTabWnd__GetCurrentTabIndex                        0x582280 
#define CTabWnd__GetNumTabs                                0x5823B0 
#define CTabWnd__GetPageClientRect                         0x582290 
#define CTabWnd__GetPageFromTabIndex                       0x5823E0 
#define CTabWnd__GetPageInnerRect                          0x5822F0 
#define CTabWnd__GetTabInnerRect                           0x5826A0 
#define CTabWnd__GetTabRect                                0x5825A0 
#define CTabWnd__IndexInBounds                             0x5823C0 
#define CTabWnd__InsertPage                                0x583120 
#define CTabWnd__SetPage                                   0x582740 
#define CTabWnd__SetPageRect                               0x582910 
#define CTabWnd__UpdatePage                                0x5829C0 

// CTextOverlay 
#define CTextOverlay__DisplayText                          0x41729C 

// CTextureFont 
#define CTextureFont__DrawWrappedText                      0x571480 

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                        0x59E1A0 

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                       0x58A570 

// CXRect 
#define CXRect__CenterPoint                                0x40B23D 

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                       0x401006 
#define CXStr__CXStr1                                      0x401000 
#define CXStr__CXStr3                                      0x54C6D0 
#define CXStr__dCXStr                                      0x4087A2 
#define CXStr__operator_equal1                             0x54C890 
#define CXStr__operator_plus_equal1                        0x54D6D0 

// CXWnd 
#define CXWnd__BringToTop                                  0x56CA80 
#define CXWnd__Center                                      0x5700B0 
#define CXWnd__ClrFocus                                    0x56C7D0 
#define CXWnd__DoAllDrawing                                0x570CC0 
#define CXWnd__DrawChildren                                0x570DF0 
#define CXWnd__DrawColoredRect                             0x56CCA0 
#define CXWnd__DrawTooltipAtPoint                          0x56FEE0 
#define CXWnd__GetBorderFrame                              0x56D0F0 
#define CXWnd__GetChildWndAt                               0x56FA70 
#define CXWnd__GetClientClipRect                           0x56D030 
#define CXWnd__GetFirstChildWnd                            0x56CB10 
#define CXWnd__GetNextChildWnd                             0x56FA50 
#define CXWnd__GetNextSib                                  0x56CB30 
#define CXWnd__GetScreenClipRect                           0x570340 
#define CXWnd__GetScreenRect                               0x56D2C0 
#define CXWnd__GetTooltipRect                              0x56FE30 
#define CXWnd__GetWindowTextA                              0x402A89 
#define CXWnd__GetXMLTooltip                               0x56C610 
#define CXWnd__IsActive                                    0x56D0A0 
#define CXWnd__IsDescendantOf                              0x56D0B0 
#define CXWnd__IsReallyVisible                             0x56FA30 
#define CXWnd__IsType                                      0x570C60 
#define CXWnd__Move                                        0x56F5E0 
#define CXWnd__Move1                                       0x56F670 
#define CXWnd__ProcessTransition                           0x56CA40 
#define CXWnd__Refade                                      0x56C870 
#define CXWnd__Resize                                      0x570480 
#define CXWnd__Right                                       0x570220 
#define CXWnd__SetFirstChildPointer                        0x56D510 
#define CXWnd__SetFocus                                    0x56E7C0 
#define CXWnd__SetKeyTooltip                               0x56D550 
#define CXWnd__SetMouseOver                                0x56D530 
#define CXWnd__SetNextSibPointer                           0x56D520 
#define CXWnd__StartFade                                   0x56CAA0 

// CXWndManager 
#define CXWndManager__DrawCursor                           0x58F1F0 
#define CXWndManager__DrawWindows                          0x58EE40 
#define CXWndManager__GetFirstChildWnd                     0x58E7C0 
#define CXWndManager__GetKeyboardFlags                     0x58DC00 
#define CXWndManager__HandleKeyboardMsg                    0x58E0D0 
#define CXWndManager__RemoveWnd                            0x58DFE0 

// EQ_Character 
#define EQ_Character__CastSpell                            0x4A29F4 
#define EQ_Character__Cur_HP                               0x4961E2 
#define EQ_Character__GetAACastingTimeModifier             0x49F116 
#define EQ_Character__GetFocusCastingTimeModifier          0x49EC9A 
#define EQ_Character__Max_Endurance                        0x492CC9 
#define EQ_Character__Max_HP                               0x492A76 
#define EQ_Character__Max_Mana                             0x4ABB73 

// EQ_Item 
#define EQ_Item__CanDrop                                   0x4A9136 
#define EQ_Item__GetItemLinkHash                           0x4A8D28 
#define EQ_Item__IsStackable                               0x4A92DA 

// EQ_LoadingS 
#define EQ_LoadingS__WriteTextHD                           0x4A983D 

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                      0x4AEDE9 

// EQItemList 
#define EQItemList__dEQItemList                            0x462868 
#define EQItemList__EQItemList                             0x4627EC 

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                   0x4799B4 
#define EQPlayer__dEQPlayer                                0x482603 
#define EQPlayer__DoAttack                                 0x480661 
#define EQPlayer__EQPlayer                                 0x482BF3 
#define EQPlayer__SetNameSpriteState                       0x47C63B 
#define EQPlayer__SetNameSpriteTint                        0x479A20 

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand           0x4FA6CF 
#define KeypressHandler__AttachKeyToEqCommand              0x4FA69C 
#define KeypressHandler__ClearCommandStateArray            0x4FA4E5 
#define KeypressHandler__HandleKeyDown                     0x4F9340 
#define KeypressHandler__HandleKeyUp                       0x4F95B7 
#define KeypressHandler__SaveKeymapping                    0x4FA56C 

// MapViewMap 
#define MapViewMap__Clear                                  0x5070FD 
#define MapViewMap__SaveEx                                 0x507898 

// StringTable 
#define StringTable__getString                             0x5BA5F0 