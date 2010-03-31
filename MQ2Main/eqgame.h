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
#define __ExpectedVersionDate                              "Feb  7 2005" 
#define __ExpectedVersionTime                              "21:31:40" 
#define __ActualVersionDate                                0x5FCB0C 
#define __ActualVersionTime                                0x5FCB18 

#define __ClientOverride                                   0 
#define __MacroQuestWinClassName                           "__MacroQuestTray" 
#define __MacroQuestWinName                                "MacroQuest" 

// Memory Protection 
#define __MemChecker0                                      0x4FBF41 
#define __MemChecker2                                      0x5387A2 
#define __MemChecker3                                      0x53882F 
#define __MemChecker4                                      0x5B2760 
#define __EncryptPad0                                      0x71D0E0 
#define __EncryptPad2                                      0x7202B8 
#define __EncryptPad3                                      0x7206B8 
#define __EncryptPad4                                      0x725DB0 

// Direct Input 
#define DI8__Main                                          0x8946EC 
#define DI8__Keyboard                                      0x8946F0 
#define DI8__Mouse                                         0x8946F4 

#define __AltTimerReady                                    0x806F8E 
#define __Attack                                           0x866A94 
#define __BindList                                         0x624DB8 
#define __Clicks                                           0x80619C 
#define __CommandList                                      0x625348 
#define __CurrentMapLabel                                  0x886A24 
#define __CurrentSocial                                    0x628750 
#define __DoAbilityAvailable                               0x806F28 
#define __DoAbilityList                                    0x83FCEC 
#define __DrawHandler                                      0x89E64C 
#define __EQP_IDArray                                      0x754360 
#define __FriendsList                                      0x83CAAC 
#define __GroupCount                                       0x866E28 
#define __GroupLeader                                      0x866F84 
#define __Guilds                                           0x86E868 
#define __gWorld                                           0x868880 
#define __HotkeyPage                                       0x86664C 
#define __HWnd                                             0x806098 
#define __IgnoreList                                       0x83E3AC 
#define __InChatMode                                       0x8060D8 
#define __LastTell                                         0x808218 
#define __Mouse                                            0x8946F8 
#define __MouseLook                                        0x80616A 
#define __NetStatusToggle                                  0x80616C 
#define __PCNames                                          0x807224 
#define __RangeAttackReady                                 0x806F8C 
#define __ScreenMode                                       0x751EE8 
#define __ScreenX                                          0x8060A0 
#define __ScreenY                                          0x8060A4 
#define __ServerHost                                       0x866CE4 
#define __ServerName                                       0x83FCAC 
#define __ShowNames                                        0x807174 
#define __SkillDict                                        0x7576E0 
#define __Socials                                          0x83FDAC 

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                          0x868910 
#define instEQZoneInfo                                     0x806308 
#define instKeypressHandler                                0x8866D4 
#define pinstActiveBanker                                  0x8688F4 
#define pinstActiveCorpse                                  0x8688F8 
#define pinstActiveGMaster                                 0x8688FC 
#define pinstActiveMerchant                                0x8688F0 
#define pinstAltAdvManager                                 0x757288 
#define pinstCCursorAttachment                             0x752A04 
#define pinstCDisplay                                      0x868904 
#define pinstCEverQuest                                    0x894860 
#define pinstCharData                                      0x8688E0 
#define pinstCharSpawn                                     0x8688D8 
#define pinstControlledPlayer                              0x8688D8 
#define pinstCSidlManager                                  0x89D9E4 
#define pinstCXWndManager                                  0x89D9DC 
#define pinstEQItemList                                    0x8688A4 
#define pinstGroup                                         0x866F70 
#define pinstLocalPlayer                                   0x8688C4 
#define pinstPCData                                        0x8688E0 
#define pinstSelectedItem                                  0x886654 
#define pinstSpawnList                                     0x8688A0 
#define pinstSpellManager                                  0x886D88 
#define pinstSpellSets                                     0x866650 
#define pinstStringTable                                   0x868890 
#define pinstSwitchManager                                 0x757284 
#define pinstTarget                                        0x8688E4 
#define pinstTargetSwitch                                  0x8688EC 
#define pinstTradeTarget                                   0x8688C0 
#define pinstWorldData                                     0x86889C 


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                  0x727880 
#define pinstCharacterSelect                               0x75297C 
#define pinstCFacePick                                     0x752980 
#define pinstCNoteWnd                                      0x752984 
#define pinstCHelpWnd                                      0x752988 
#define pinstCBookWnd                                      0x75298C 
#define pinstCPetInfoWnd                                   0x752990 
#define pinstCTrainWnd                                     0x752994 
#define pinstCSkillsWnd                                    0x752998 
#define pinstCSkillsSelectWnd                              0x75299C 
#define pinstCCombatSkillSelectWnd                         0x7529A0 
#define pinstCFriendsWnd                                   0x7529A4 
#define pinstCAAWnd                                        0x7529B0 
#define pinstCGroupSearchFiltersWnd                        0x7529B4 
#define pinstCLoadskinWnd                                  0x7529B8 
#define pinstCAlarmWnd                                     0x7529BC 
#define pinstCMusicPlayerWnd                               0x7529C0 
#define pinstCRaidWnd                                      0x7529CC 
#define pinstCRaidOptionsWnd                               0x7529D0 
#define pinstCBreathWnd                                    0x7529D4 
#define pinstCMapViewWnd                                   0x7529D8 
#define pinstCMapToolbarWnd                                0x7529DC 
#define pinstCEditLabelWnd                                 0x7529E0 
#define pinstCTargetWnd                                    0x7529E4 
#define pinstCHotButtonWnd                                 0x7529E8 
#define pinstCColorPickerWnd                               0x7529EC 
#define pinstCPlayerWnd                                    0x7529F0 
#define pinstCOptionsWnd                                   0x7529F4 
#define pinstCBuffWindowNORMAL                             0x7529F8 
#define pinstCBuffWindowSHORT                              0x7529FC 
#define pinstCharacterCreation                             0x752A00 
#define pinstCCursorAttachment                             0x752A04 
#define pinstCCastingWnd                                   0x752A08 
#define pinstCCastSpellWnd                                 0x752A0C 
#define pinstCSpellBookWnd                                 0x752A10 
#define pinstCInventoryWnd                                 0x752A14 
#define pinstCBankWnd                                      0x752A18 
#define pinstCQuantityWnd                                  0x752A1C 
#define pinstCLootWnd                                      0x752A20 
#define pinstCActionsWnd                                   0x752A24 
#define pinstCCombatAbilityWnd                             0x752A28 
#define pinstCMerchantWnd                                  0x752A2C 
#define pinstCTradeWnd                                     0x752A30 
#define pinstCSelectorWnd                                  0x752A34 
#define pinstCBazaarWnd                                    0x752A38 
#define pinstCBazaarSearchWnd                              0x752A3C 
#define pinstCGiveWnd                                      0x752A40 
#define pinstCTrackingWnd                                  0x752A44 
#define pinstCInspectWnd                                   0x752A48 
#define pinstCSocialEditWnd                                0x752A4C 
#define pinstCFeedbackWnd                                  0x752A50 
#define pinstCBugReportWnd                                 0x752A54 
#define pinstCVideoModesWnd                                0x752A58 
#define pinstCTextEntryWnd                                 0x752A60 
#define pinstCFileSelectionWnd                             0x752A64 
#define pinstCCompassWnd                                   0x752A68 
#define pinstCPlayerNotesWnd                               0x752A6C 
#define pinstCGemsGameWnd                                  0x752A70 
#define pinstCTimeLeftWnd                                  0x752A74 
#define pinstCPetitionQWnd                                 0x752A78 
#define pinstCSoulmarkWnd                                  0x752A7C 
#define pinstCStoryWnd                                     0x752A80 
#define pinstCJournalTextWnd                               0x752A84 
#define pinstCJournalCatWnd                                0x752A88 
#define pinstCBodyTintWnd                                  0x752A8C 
#define pinstCInvSlotMgr                                   0x752A90 
#define pinstCContainerMgr                                 0x752A94 
#define pinstCAdventureLeaderboardWnd                      0x72752C 
#define pinstCAdventureMerchantWnd                         0x727548 
#define pinstCAdventureRequestWnd                          0x727564 
#define pinstCAdventureStatsWnd                            0x727580 
#define pinstCChatManager                                  0x7279B0 
#define pinstCDynamicZoneWnd                               0x752BA0 
#define pinstCFindLocationWnd                              0x886458 
#define pinstCGroupSearchWnd                               0x886550 
#define pinstCGroupWnd                                     0x88656C 
#define pinstCGuildMgmtWnd                                 0x8865A4 
#define pinstCItemDisplayManager                           0x886688 
#define pinstCLeadershipWnd                                0x886770 
#define pinstCPopupWndManager                              0x886B98 
#define pinstCSystemInfoDialogBox                          0x887530 
#define pinstCTargetOfTargetWnd                            0x887554 
#define pinstCTipWndOFDAY                                  0x887644 
#define pinstCTipWndCONTEXT                                0x887648 
#define pinstCTradeskillWnd                                0x887740 
#define pinstCTributeBenefitWnd                            0x88778C 
#define pinstCTributeMasterWnd                             0x8877A8 
#define pinstCContextMenuManager                           0x89DC0C 
// unknown window added 4-14 exe 0x79A234 


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                          0x46494F 
#define __ConvertItemTags                                  0x4641A9 
#define __ExecuteCmd                                       0x455F68 
#define __get_melee_range                                  0x45AB48 
#define __GetGaugeValueFromEQ                              0x521668 
#define __LoadSplashScreen                                 0x5B8310 
#define __NewUIINI                                         0x523201 
#define __ProcessGameEvents                                0x4C2BBC 
#define __SendMessage                                      0x4AA053 
#define CrashDetected                                      0x53845E 
#define DrawNetStatus                                      0x5003A2 


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                  0x487069 
#define AltAdvManager__IsAbilityReady                      0x487097 

// CBankWnd 
#define CBankWnd__GetNumBankSlots                          0x40B5BA 

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                  0x40E8FA 

// CButtonWnd 
#define CButtonWnd__SetCheck                               0x57A850 

// CChatManager 
#define CChatManager__GetRGBAFromIndex                     0x41F3AD 
#define CChatManager__InitContextMenu                      0x41F491 

// CChatWindow 
#define CChatWindow__CChatWindow                           0x4223F4 

// CComboWnd 
#define CComboWnd__DeleteAll                               0x57B4C0 
#define CComboWnd__Draw                                    0x57B6C0 
#define CComboWnd__GetButtonRect                           0x57B4F0 
#define CComboWnd__GetCurChoice                            0x57B480 
#define CComboWnd__GetListRect                             0x57BAB0 
#define CComboWnd__GetTextRect                             0x57B550 
#define CComboWnd__InsertChoice                            0x57BB10 
#define CComboWnd__SetColors                               0x57B450 
#define CComboWnd__SetChoice                               0x57BBF0 

// CContainerWnd 
#define CContainerWnd__HandleCombine                       0x429E85 
#define CContainerWnd__vftable                             0x5E4E30 

// CDisplay 
#define CDisplay__CleanGameUI                              0x439A53 
#define CDisplay__GetClickedActor                          0x436613 
#define CDisplay__GetUserDefinedColor                      0x4359D6 
#define CDisplay__GetWorldFilePath                         0x4351E2 
#define CDisplay__ReloadUI                                 0x4411A7 
#define CDisplay__WriteTextHD2                             0x43A6DD 

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                          0x408165 
#define CEditBaseWnd__SetSel                               0x58C5B0 

// CEditWnd 
#define CEditWnd__DrawCaret                                0x588620 
#define CEditWnd__GetCharIndexPt                           0x589470 
#define CEditWnd__GetDisplayString                         0x588780 
#define CEditWnd__GetHorzOffset                            0x5889F0 
#define CEditWnd__GetLineForPrintableChar                  0x588F10 
#define CEditWnd__GetSelStartPt                            0x5896B0 
#define CEditWnd__GetSTMLSafeText                          0x588BD0 
#define CEditWnd__PointFromPrintableChar                   0x589020 
#define CEditWnd__SelectableCharFromPoint                  0x5891A0 
#define CEditWnd__SetEditable                              0x588BA0 

// CEverQuest 
#define CEverQuest__ClickedPlayer                          0x4AF476 
#define CEverQuest__DropHeldItemOnGround                   0x4B1219 
#define CEverQuest__dsp_chat                               0x4B186F 
#define CEverQuest__EnterZone                              0x4C1943 
#define CEverQuest__GetBodyTypeDesc                        0x4AB0EC 
#define CEverQuest__GetClassDesc                           0x4AAB0F 
#define CEverQuest__GetClassThreeLetterCode                0x4AAF89 
#define CEverQuest__GetDeityDesc                           0x4ACB7F 
#define CEverQuest__GetRaceDesc                            0x4AB3F1 
#define CEverQuest__InterpretCmd                           0x4BBF9D 
#define CEverQuest__LeftClickedOnPlayer                    0x4C029B 
#define CEverQuest__RightClickedOnPlayer                   0x4C06D1 
#define CEverQuest__SetGameState                           0x4AF556 

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                            0x4CE2C4 
#define CGaugeWnd__CalcLinesFillRect                       0x4CE320 
#define CGaugeWnd__Draw                                    0x4CE620 

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                         0x4DE5F9 

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                           0x4E1F71 
#define CInvSlotMgr__MoveItem                              0x4E18B5 

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                           0x4E699D 
#define CItemDisplayWnd__SetSpell                          0x4E59AD 

// CLabel 
#define CLabel__Draw                                       0x4EDFA3 

// CListWnd 
#define CListWnd__AddColumn                                0x564F10 
#define CListWnd__AddColumn1                               0x564A60 
#define CListWnd__AddLine                                  0x564620 
#define CListWnd__AddString                                0x5647A0 
#define CListWnd__CalculateFirstVisibleLine                0x561B90 
#define CListWnd__CalculateVSBRange                        0x563720 
#define CListWnd__ClearAllSel                              0x5612F0 
#define CListWnd__CloseAndUpdateEditWindow                 0x562190 
#define CListWnd__Compare                                  0x5624D0 
#define CListWnd__Draw                                     0x563380 
#define CListWnd__DrawColumnSeparators                     0x5631D0 
#define CListWnd__DrawHeader                               0x561510 
#define CListWnd__DrawItem                                 0x562BE0 
#define CListWnd__DrawLine                                 0x562F40 
#define CListWnd__DrawSeparator                            0x5632A0 
#define CListWnd__EnsureVisible                            0x561BE0 
#define CListWnd__ExtendSel                                0x562B10 
#define CListWnd__GetColumnFlags                           0x560DC0 
#define CListWnd__GetColumnJustification                   0x560F60 
#define CListWnd__GetColumnMinWidth                        0x560EF0 
#define CListWnd__GetColumnWidth                           0x560E20 
#define CListWnd__GetCurSel                                0x560C00 
#define CListWnd__GetHeaderRect                            0x560A40 
#define CListWnd__GetItemAtPoint                           0x561E90 
#define CListWnd__GetItemAtPoint1                          0x561F00 
#define CListWnd__GetItemData                              0x560C40 
#define CListWnd__GetItemHeight                            0x561910 
#define CListWnd__GetItemIcon                              0x560D00 
#define CListWnd__GetItemRect                              0x561CB0 
#define CListWnd__GetItemText                              0x560C80 
#define CListWnd__GetSelList                               0x564940 
#define CListWnd__GetSeparatorRect                         0x562420 
#define CListWnd__IsLineEnabled                            0x5613E0 
#define CListWnd__RemoveLine                               0x5648F0 
#define CListWnd__SetColors                                0x5609B0 
#define CListWnd__SetColumnJustification                   0x560FC0 
#define CListWnd__SetColumnWidth                           0x560EA0 
#define CListWnd__SetCurSel                                0x561210 
#define CListWnd__SetItemColor                             0x564260 
#define CListWnd__SetItemData                              0x5613A0 
#define CListWnd__SetItemText                              0x5641A0 
#define CListWnd__ShiftColumnSeparator                     0x562A80 
#define CListWnd__Sort                                     0x564FB0 
#define CListWnd__ToggleSel                                0x561230 

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                           0x4FAF32 

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                0x4FC424 
#define CMerchantWnd__RequestBuyItem                       0x4FC5E2 
#define CMerchantWnd__RequestSellItem                      0x4FC97B 
#define CMerchantWnd__SelectBuySellSlot                    0x4FD740 

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1             0x586640 

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                  0x558E00 
#define CSidlScreenWnd__CalculateVSBRange                  0x558D40 
#define CSidlScreenWnd__ConvertToRes                       0x5594F0 
#define CSidlScreenWnd__CreateChildrenFromSidl             0x559C60 
#define CSidlScreenWnd__CSidlScreenWnd1                    0x55B360 
#define CSidlScreenWnd__CSidlScreenWnd2                    0x55B450 
#define CSidlScreenWnd__dCSidlScreenWnd                    0x55A9B0 
#define CSidlScreenWnd__DrawSidlPiece                      0x559880 
#define CSidlScreenWnd__EnableIniStorage                   0x5594A0 
#define CSidlScreenWnd__GetSidlPiece                       0x559B20 
#define CSidlScreenWnd__Init1                              0x55B0B0 
#define CSidlScreenWnd__LoadIniInfo                        0x559D10 
#define CSidlScreenWnd__LoadIniListWnd                     0x55A650 
#define CSidlScreenWnd__LoadSidlScreen                     0x5596C0 
#define CSidlScreenWnd__SetScreen                          0x55AAD0 
#define CSidlScreenWnd__StoreIniInfo                       0x559030 
#define CSidlScreenWnd__WndNotification                    0x5597E0 

// CSliderWnd 
#define CSliderWnd__GetValue                               0x57BF30 
#define CSliderWnd__SetValue                               0x57C110 
#define CSliderWnd__UpdateThumb                            0x57BEF0 

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                         0x51FAAD 

// CStmlWnd 
#define CStmlWnd__AppendSTML                               0x56E440 
#define CStmlWnd__CalculateHSBRange                        0x565D70 
#define CStmlWnd__CalculateVSBRange                        0x565D10 
#define CStmlWnd__CanBreakAtCharacter                      0x565EB0 
#define CStmlWnd__CanGoBackward                            0x565F30 
#define CStmlWnd__FastForwardToEndOfTag                    0x566C60 
#define CStmlWnd__GetNextChar                              0x566370 
#define CStmlWnd__GetNextTagPiece                          0x566A60 
#define CStmlWnd__GetSTMLText                              0x4223D6 
#define CStmlWnd__GetThisChar                              0x565BD0 
#define CStmlWnd__GetVisiableText                          0x568430 
#define CStmlWnd__InitializeWindowVariables                0x56A1C0 
#define CStmlWnd__MakeStmlColorTag                         0x5652A0 
#define CStmlWnd__MakeWndNotificationTag                   0x565340 
#define CStmlWnd__StripFirstSTMLLines                      0x56E1C0 
#define CStmlWnd__UpdateHistoryString                      0x568870 

// CTabWnd 
#define CTabWnd__Draw                                      0x572250 
#define CTabWnd__DrawCurrentPage                           0x571D40 
#define CTabWnd__DrawTab                                   0x571AC0 
#define CTabWnd__GetCurrentPage                            0x5715B0 
#define CTabWnd__GetCurrentTabIndex                        0x5712A0 
#define CTabWnd__GetNumTabs                                0x5713D0 
#define CTabWnd__GetPageClientRect                         0x5712B0 
#define CTabWnd__GetPageFromTabIndex                       0x571400 
#define CTabWnd__GetPageInnerRect                          0x571310 
#define CTabWnd__GetTabInnerRect                           0x5716C0 
#define CTabWnd__GetTabRect                                0x5715C0 
#define CTabWnd__IndexInBounds                             0x5713E0 
#define CTabWnd__InsertPage                                0x572140 
#define CTabWnd__SetPage                                   0x571760 
#define CTabWnd__SetPageRect                               0x571930 
#define CTabWnd__UpdatePage                                0x5719E0 

// CTextOverlay 
#define CTextOverlay__DisplayText                          0x412CD3 

// CTextureFont 
#define CTextureFont__DrawWrappedText                      0x560510 

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                        0x58D220 

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                       0x5795B0 

// CXRect 
#define CXRect__CenterPoint                                0x40AE1D 

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                       0x401000 
#define CXStr__CXStr1                                      0x500B7B 
#define CXStr__CXStr3                                      0x53C140 
#define CXStr__dCXStr                                      0x40A01F 
#define CXStr__operator_equal1                             0x53C300 
#define CXStr__operator_plus_equal1                        0x53D140 

// CXWnd 
#define CXWnd__BringToTop                                  0x55BB10 
#define CXWnd__Center                                      0x55F140 
#define CXWnd__ClrFocus                                    0x55B850 
#define CXWnd__DoAllDrawing                                0x55FD50 
#define CXWnd__DrawChildren                                0x55FE80 
#define CXWnd__DrawColoredRect                             0x55BD40 
#define CXWnd__DrawTooltipAtPoint                          0x55EF70 
#define CXWnd__GetBorderFrame                              0x55C180 
#define CXWnd__GetChildWndAt                               0x55EB00 
#define CXWnd__GetClientClipRect                           0x55C0D0 
#define CXWnd__GetFirstChildWnd                            0x55BBA0 
#define CXWnd__GetNextChildWnd                             0x55EAE0 
#define CXWnd__GetNextSib                                  0x55BBC0 
#define CXWnd__GetScreenClipRect                           0x55F3D0 
#define CXWnd__GetScreenRect                               0x55C350 
#define CXWnd__GetTooltipRect                              0x55EEC0 
#define CXWnd__GetWindowTextA                              0x402A92 
#define CXWnd__GetXMLTooltip                               0x55B690 
#define CXWnd__IsActive                                    0x55C140 
#define CXWnd__IsDescendantOf                              0x55C150 
#define CXWnd__IsReallyVisible                             0x55EAC0 
#define CXWnd__IsType                                      0x55FCF0 
#define CXWnd__Move                                        0x55E670 
#define CXWnd__Move1                                       0x55E700 
#define CXWnd__ProcessTransition                           0x55BAD0 
#define CXWnd__Refade                                      0x55B900 
#define CXWnd__Resize                                      0x55F510 
#define CXWnd__Right                                       0x55F2B0 
#define CXWnd__SetFirstChildPointer                        0x55C5A0 
#define CXWnd__SetFocus                                    0x55D850 
#define CXWnd__SetKeyTooltip                               0x55C5E0 
#define CXWnd__SetMouseOver                                0x55C5C0 
#define CXWnd__SetNextSibPointer                           0x55C5B0 
#define CXWnd__StartFade                                   0x55BB30 

// CXWndManager 
#define CXWndManager__DrawCursor                           0x57F180 
#define CXWndManager__DrawWindows                          0x57EDD0 
#define CXWndManager__GetFirstChildWnd                     0x57E750 
#define CXWndManager__GetKeyboardFlags                     0x57DB00 
#define CXWndManager__HandleKeyboardMsg                    0x57E060 
#define CXWndManager__RemoveWnd                            0x57DF70 

// EQ_Character 
#define EQ_Character__CastSpell                            0x4972D9 
#define EQ_Character__Cur_HP                               0x48C295 
#define EQ_Character__GetAACastingTimeModifier             0x493B7C 
#define EQ_Character__GetFocusCastingTimeModifier          0x493664 
#define EQ_Character__Max_Endurance                        0x487D5D 
#define EQ_Character__Max_HP                               0x487B0A 
#define EQ_Character__Max_Mana                             0x4A1177 

// EQ_Item 
#define EQ_Item__CanDrop                                   0x49D9AA 
#define EQ_Item__GetItemLinkHash                           0x49D59C 
#define EQ_Item__IsStackable                               0x49DB4E 

// EQ_LoadingS 
#define EQ_LoadingS__WriteTextHD                           0x49E086 

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                      0x4A136E 

// EQItemList 
#define EQItemList__dEQItemList                            0x458A7A 
#define EQItemList__EQItemList                             0x4589FE 

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                   0x46FF1B 
#define EQPlayer__dEQPlayer                                0x479B9E 
#define EQPlayer__DoAttack                                 0x4761AA 
#define EQPlayer__EQPlayer                                 0x47A319 
#define EQPlayer__SetNameSpriteState                       0x474249 
#define EQPlayer__SetNameSpriteTint                        0x46FF87 

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand           0x4EDE0C 
#define KeypressHandler__AttachKeyToEqCommand              0x4EDDD9 
#define KeypressHandler__ClearCommandStateArray            0x4EDC22 
#define KeypressHandler__HandleKeyDown                     0x4ECA91 
#define KeypressHandler__HandleKeyUp                       0x4ECD08 
#define KeypressHandler__SaveKeymapping                    0x4EDCA9 

// MapViewMap 
#define MapViewMap__Clear                                  0x4F7D0C 
#define MapViewMap__SaveEx                                 0x4F84A7 

// StringTable 
#define StringTable__getString                             0x5A9630 