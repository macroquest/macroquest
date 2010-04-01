/******************************************************************************
    MQ2Main.dll: MacroQuest2's extension DLL for EverQuest
    Copyright (C) 2002-2003 Plazmic, 2003-2005 Lax

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

#define __ClientName                                      "eqgame"
#define __ExpectedVersionDate                             "Sep 15 2005"
#define __ExpectedVersionTime                             "18:55:26"
#define __ActualVersionDate                                0x64C734
#define __ActualVersionTime                                0x64C740

#define __ClientOverride                                   0
#define __MacroQuestWinClassName                          "__MacroQuestTray"
#define __MacroQuestWinName                               "MacroQuest"

// Memory Protection
#define __MemChecker0                                      0x4B7241
#define __MemChecker2                                      0x4CCF3C
#define __MemChecker3                                      0x4CCFC9
#define __MemChecker4                                      0x600580
#define __EncryptPad0                                      0x78B380
#define __EncryptPad2                                      0x78D498
#define __EncryptPad3                                      0x78D898
#define __EncryptPad4                                      0x798690

// Direct Input
#define DI8__Main                                          0x986A7C
#define DI8__Keyboard                                      0x986A80
#define DI8__Mouse                                         0x986A84

#define __AltTimerReady                                    0x9224AA
#define __Attack                                           0x9836F3
#define __BindList                                         0x786900
#define __Clicks                                           0x9216AC
#define __CommandList                                      0x7870B0
#define __CurrentMapLabel                                  0x98FAFC
#define __CurrentSocial                                    0x691D98
#define __DoAbilityAvailable                               0x922444
#define __DoAbilityList                                    0x95B240
#define __DrawHandler                                      0x99C164
#define __EQP_IDArray                                      0x8FED88
#define __FriendsList                                      0x957FE0
#define __GroupCount                                       0x902080
#define __GroupLeader                                      0x9021DC
#define __Guilds                                           0x903B70
#define __gWorld                                           0x903AD8
#define __HotkeyPage                                       0x98262C
#define __HWnd                                             0x9215A8
#define __IgnoreList                                       0x9598E0
#define __InChatMode                                       0x9215E8
#define __LastTell                                         0x92374C
#define __Mouse                                            0x986A88
#define __MouseLook                                        0x92167A
#define __NetStatusToggle                                  0x92167C
#define __PCNames                                          0x9227A4
#define __RangeAttackReady                                 0x9224A8
#define __RunWalkState                                     0x9215EC
#define __ScreenMode                                       0x84E344
#define __ScreenX                                          0x9215B0
#define __ScreenY                                          0x9215B4
#define __ServerHost                                       0x901F3C
#define __ServerName                                       0x95B200
#define __ShowNames                                        0x922698
#define __SkillDict                                        0x84F038
#define __Socials                                          0x95B300

////
//Section 1: Vital Offsets
////
#define instCRaid                                          0x91B540
#define instEQZoneInfo                                     0x921818
#define instKeypressHandler                                0x9837C8
#define pinstActiveBanker                                  0x903B4C
#define pinstActiveCorpse                                  0x903B50
#define pinstActiveGMaster                                 0x903B54
#define pinstActiveMerchant                                0x903B48
#define pinstAltAdvManager                                 0x84F010
#define pinstCDisplay                                      0x903B5C
#define pinstCEverQuest                                    0x986BF0
#define pinstCharData                                      0x903B38
#define pinstCharSpawn                                     0x903B30
#define pinstControlledPlayer                              0x903B30
#define pinstCSidlManager                                  0x99B1DC
#define pinstCXWndManager                                  0x99B1D4
#define pinstEQItemList                                    0x903B00
#define instGroup                                          0x902080
#define pinstLocalPlayer                                   0x903B1C
#define pinstPCData                                        0x903B38
#define pinstSelectedItem                                  0x98F954
#define pinstSpawnList                                     0x903AFC
#define pinstSpellManager                                  0x983AC8
#define pinstSpellSets                                     0x982630
#define pinstStringTable                                   0x903AE8
#define pinstSwitchManager                                 0x901CBC
#define pinstTarget                                        0x903B3C
#define pinstTargetSwitch                                  0x903B44
#define pinstTradeTarget                                   0x903B18
#define instTributeActive                                  0x84E1BD
#define pinstWorldData                                     0x903AF8


////
//Section 2:  UI Related Offsets
////
#define pinstCTextOverlay                                  0x799FC4
#define pinstCharacterSelect                               0x84E9D4
#define pinstCFacePick                                     0x84E9D8
#define pinstCNoteWnd                                      0x84E9DC
#define pinstCHelpWnd                                      0x9906A8
#define pinstCBookWnd                                      0x84E9E0
#define pinstCPetInfoWnd                                   0x84E9E4
#define pinstCTrainWnd                                     0x84E9E8
#define pinstCSkillsWnd                                    0x84E9EC
#define pinstCSkillsSelectWnd                              0x84E9F0
#define pinstCCombatSkillSelectWnd                         0x84E9F4
#define pinstCFriendsWnd                                   0x84E9F8
#define pinstCAAWnd                                        0x84EA08
#define pinstCGroupSearchFiltersWnd                        0x84EA0C
#define pinstCLoadskinWnd                                  0x84EA10
#define pinstCAlarmWnd                                     0x84EA14
#define pinstCMusicPlayerWnd                               0x84EA18
#define pinstCRaidWnd                                      0x84EA28
#define pinstCRaidOptionsWnd                               0x84EA2C
#define pinstCBreathWnd                                    0x84EA30
#define pinstCMapViewWnd                                   0x84EA34
#define pinstCMapToolbarWnd                                0x84EA38
#define pinstCEditLabelWnd                                 0x84EA3C
#define pinstCTargetWnd                                    0x84EA40
#define pinstCHotButtonWnd                                 0x98F8E4
#define pinstCColorPickerWnd                               0x84EA44
#define pinstCPlayerWnd                                    0x84EA48
#define pinstCOptionsWnd                                   0x84EA4C
#define pinstCBuffWindowNORMAL                             0x84EA50
#define pinstCBuffWindowSHORT                              0x84EA54
#define pinstCharacterCreation                             0x84EA58
#define pinstCCursorAttachment                             0x84EA5C
#define pinstCCastingWnd                                   0x84EA60
#define pinstCCastSpellWnd                                 0x84EA64
#define pinstCSpellBookWnd                                 0x84EA68
#define pinstCInventoryWnd                                 0x84EA6C
#define pinstCBankWnd                                      0x84EA70
#define pinstCQuantityWnd                                  0x84EA74
#define pinstCLootWnd                                      0x84EA78
#define pinstCActionsWnd                                   0x84EA7C
#define pinstCCombatAbilityWnd                             0x84EA80
#define pinstCMerchantWnd                                  0x84EA84
#define pinstCTradeWnd                                     0x84EA88
#define pinstCSelectorWnd                                  0x84EA8C
#define pinstCBazaarWnd                                    0x84EA90
#define pinstCBazaarSearchWnd                              0x84EA94
#define pinstCGiveWnd                                      0x84EA98
#define pinstCTrackingWnd                                  0x84EA9C
#define pinstCInspectWnd                                   0x84EAA0
#define pinstCSocialEditWnd                                0x84EAA4
#define pinstCFeedbackWnd                                  0x84EAA8
#define pinstCBugReportWnd                                 0x84EAAC
#define pinstCVideoModesWnd                                0x84EAB0
#define pinstCTextEntryWnd                                 0x84EAB8
#define pinstCFileSelectionWnd                             0x84EABC
#define pinstCCompassWnd                                   0x84EAC0
#define pinstCPlayerNotesWnd                               0x84EAC4
#define pinstCGemsGameWnd                                  0x84EAC8
#define pinstCTimeLeftWnd                                  0x84EACC
#define pinstCPetitionQWnd                                 0x84EAD0
#define pinstCSoulmarkWnd                                  0x84EAD4
#define pinstCStoryWnd                                     0x84EAD8
#define pinstCJournalTextWnd                               0x84EADC
#define pinstCJournalCatWnd                                0x84EAE0
#define pinstCBodyTintWnd                                  0x84EAE4
#define pinstCInvSlotMgr                                   0x84EAF0
#define pinstCContainerMgr                                 0x84EAF4
#define pinstCAdventureLeaderboardWnd                      0x98F1B8
#define pinstCAdventureMerchantWnd                         0x799F84
#define pinstCAdventureRequestWnd                          0x98F1D4
#define pinstCAdventureStatsWnd                            0x98F1F0
#define pinstCChatManager                                  0x98F5E4
#define pinstCDynamicZoneWnd                               0x98F6C0
#define pinstCFindLocationWnd                              0x98F7C4
#define pinstCGroupSearchWnd                               0x98F858
#define pinstCGroupWnd                                     0x98F874
#define pinstCGuildMgmtWnd                                 0x98F8AC
#define pinstCItemDisplayManager                           0x98F988
#define pinstCLeadershipWnd                                0x98FA24
#define pinstCPopupWndManager                              0x98FC44
#define pinstCSystemInfoDialogBox                          0x9905D0
#define pinstCTargetOfTargetWnd                            0x9905EC
#define pinstCTipWndOFDAY                                  0x9906DC
#define pinstCTipWndCONTEXT                                0x9906E0
#define pinstCTradeskillWnd                                0x990740
#define pinstCTributeBenefitWnd                            0x99078C
#define pinstCTributeMasterWnd                             0x9907A8
#define pinstCContextMenuManager                           0x99B1FC
// unknown window added 4-14 exe 0x79A234


////
// Section 3: Miscellaneous Offsets
////
#define __CastRay                                          0x474FD9
#define __ConvertItemTags                                  0x46C5D4
#define __ExecuteCmd                                       0x45F645
#define __get_melee_range                                  0x4635C9
#define __GetGaugeValueFromEQ                              0x559440
#define __GetLabelFromEQ                                   0x559B37
#define __LoadSplashScreen                                 0x60DBD0
#define __NewUIINI                                         0x5590C9
#define __ProcessGameEvents                                0x4AA1EB
#define __SendMessage                                      0x48FF2E
#define CrashDetected                                      0x4CCBF8
#define DrawNetStatus                                      0x4B9446


////
// Section 4: Function Offsets
////
// AltAdvManager
#define AltAdvManager__GetCalculatedTimer                  0x4457DA
#define AltAdvManager__IsAbilityReady                      0x44580E
#define AltAdvManager__GetAltAbility                       0x4458C6

// CBankWnd
#define CBankWnd__GetNumBankSlots                          0x4DC7A0

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg                  0x4E451D

// CButtonWnd
#define CButtonWnd__SetCheck                               0x5BA320

// CChatManager
#define CChatManager__GetRGBAFromIndex                     0x4F2B52
#define CChatManager__InitContextMenu                      0x4F309F

// CChatWindow
#define CChatWindow__CChatWindow                           0x4F6832

// CComboWnd
#define CComboWnd__DeleteAll                               0x5BBE40
#define CComboWnd__Draw                                    0x5BC030
#define CComboWnd__GetButtonRect                           0x5BBE70
#define CComboWnd__GetCurChoice                            0x5BBE00
#define CComboWnd__GetListRect                             0x5BC2D0
#define CComboWnd__GetTextRect                             0x5BBEC0
#define CComboWnd__InsertChoice                            0x5BC330
#define CComboWnd__SetColors                               0x5BBD90
#define CComboWnd__SetChoice                               0x5BBDC0

// CContainerWnd
#define CContainerWnd__HandleCombine                       0x4FC085
#define CContainerWnd__vftable                             0x6526D8

// CDisplay
#define CDisplay__CleanGameUI                              0x43882F
#define CDisplay__GetClickedActor                          0x436E7E
#define CDisplay__GetUserDefinedColor                      0x4363D2
#define CDisplay__GetWorldFilePath                         0x435B82
#define CDisplay__ReloadUI                                 0x443364
#define CDisplay__WriteTextHD2                             0x439CB3

// CEditBaseWnd
#define CEditBaseWnd__SetMaxChars                          0x4D8153
#define CEditBaseWnd__SetSel                               0x5B9380

// CEditWnd
#define CEditWnd__DrawCaret                                0x5B6B30
#define CEditWnd__GetCharIndexPt                           0x5B7920
#define CEditWnd__GetDisplayString                         0x5B6CC0
#define CEditWnd__GetHorzOffset                            0x5B6F30
#define CEditWnd__GetLineForPrintableChar                  0x5B7400
#define CEditWnd__GetSelStartPt                            0x5B7B60
#define CEditWnd__GetSTMLSafeText                          0x5B70C0
#define CEditWnd__PointFromPrintableChar                   0x5B7510
#define CEditWnd__SelectableCharFromPoint                  0x5B7680
#define CEditWnd__SetEditable                              0x5B7090

// CEverQuest
#define CEverQuest__ClickedPlayer                          0x495122
#define CEverQuest__DropHeldItemOnGround                   0x49E4D7
#define CEverQuest__dsp_chat                               0x498906
#define CEverQuest__EnterZone                              0x4A8C51
#define CEverQuest__GetBodyTypeDesc                        0x4910AC
#define CEverQuest__GetClassDesc                           0x490ACF
#define CEverQuest__GetClassThreeLetterCode                0x490F49
#define CEverQuest__GetDeityDesc                           0x492DA5
#define CEverQuest__GetRaceDesc                            0x4913B1
#define CEverQuest__InterpretCmd                           0x4991B8
#define CEverQuest__LeftClickedOnPlayer                    0x4A7542
#define CEverQuest__RightClickedOnPlayer                   0x4A798A
#define CEverQuest__SetGameState                           0x49519A

// CGaugeWnd
#define CGaugeWnd__CalcFillRect                            0x50461D
#define CGaugeWnd__CalcLinesFillRect                       0x504679
#define CGaugeWnd__Draw                                    0x504979

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton                         0x513E1D

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot                           0x51A474
#define CInvSlotMgr__MoveItem                              0x51A5CF

// CItemDisplayWnd
//#define CItemDisplayWnd__SetItem                           0x51E61E
#define CItemDisplayWnd__SetItem                           0x5215E0
#define CItemDisplayWnd__SetSpell                          0x51D62F

// CLabel
#define CLabel__Draw                                       0x525C47

// CListWnd
#define CListWnd__AddColumn                                0x5ABD50
#define CListWnd__AddColumn1                               0x5AB880
#define CListWnd__AddLine                                  0x5AB410
#define CListWnd__AddString                                0x5AB5E0
#define CListWnd__CalculateFirstVisibleLine                0x5A8A00
#define CListWnd__CalculateVSBRange                        0x5AA540
#define CListWnd__ClearAllSel                              0x5A8240
#define CListWnd__CloseAndUpdateEditWindow                 0x5A9020
#define CListWnd__Compare                                  0x5A9390
#define CListWnd__Draw                                     0x5AA250
#define CListWnd__DrawColumnSeparators                     0x5AA0D0
#define CListWnd__DrawHeader                               0x5A8410
#define CListWnd__DrawItem                                 0x5A9AA0
#define CListWnd__DrawLine                                 0x5A9E10
#define CListWnd__DrawSeparator                            0x5AA170
#define CListWnd__EnsureVisible                            0x5A8A50
#define CListWnd__ExtendSel                                0x5A99D0
#define CListWnd__GetColumnFlags                           0x5A7DE0
#define CListWnd__GetColumnJustification                   0x5A7F50
#define CListWnd__GetColumnMinWidth                        0x5A7EF0
#define CListWnd__GetColumnWidth                           0x5A7E30
#define CListWnd__GetCurSel                                0x5A78B0
#define CListWnd__GetHeaderRect                            0x5A79C0
#define CListWnd__GetItemAtPoint                           0x5A8D30
#define CListWnd__GetItemAtPoint1                          0x5A8DA0
#define CListWnd__GetItemData                              0x5A7B90
#define CListWnd__GetItemHeight                            0x5A87A0
#define CListWnd__GetItemIcon                              0x5A7D20
#define CListWnd__GetItemRect                              0x5A8B20
#define CListWnd__GetItemText                              0x5A7BD0
#define CListWnd__GetSelList                               0x5AB760
#define CListWnd__GetSeparatorRect                         0x5A92E0
#define CListWnd__IsLineEnabled                            0x5A8320
#define CListWnd__RemoveLine                               0x5AB710
#define CListWnd__SetColors                                0x5A7930
#define CListWnd__SetColumnJustification                   0x5A7FA0
#define CListWnd__SetColumnWidth                           0x5A7EB0
#define CListWnd__SetCurSel                                0x5A78F0
#define CListWnd__SetItemColor                             0x5AB040
#define CListWnd__SetItemData                              0x5A82E0
#define CListWnd__SetItemText                              0x5AAFC0
#define CListWnd__ShiftColumnSeparator                     0x5A9940
#define CListWnd__Sort                                     0x5ABD80
#define CListWnd__ToggleSel                                0x5A81B0

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd                           0x535A6B

// CMerchantWnd
#define CMerchantWnd__DisplayBuyOrSellPrice                0x537063
#define CMerchantWnd__RequestBuyItem                       0x537FF5
#define CMerchantWnd__RequestSellItem                      0x537262
#define CMerchantWnd__SelectBuySellSlot                    0x537D59

// CSidlManager
#define CSidlManager__FindScreenPieceTemplate1             0x5B4E50

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateHSBRange                  0x597810
#define CSidlScreenWnd__CalculateVSBRange                  0x597750
#define CSidlScreenWnd__ConvertToRes                       0x597F50
#define CSidlScreenWnd__CreateChildrenFromSidl             0x598770
#define CSidlScreenWnd__CSidlScreenWnd1                    0x599A30
#define CSidlScreenWnd__CSidlScreenWnd2                    0x599AE0
#define CSidlScreenWnd__dCSidlScreenWnd                    0x599290
#define CSidlScreenWnd__DrawSidlPiece                      0x598490
#define CSidlScreenWnd__EnableIniStorage                   0x597F00
#define CSidlScreenWnd__GetSidlPiece                       0x598650
#define CSidlScreenWnd__Init1                              0x599850
#define CSidlScreenWnd__LoadIniInfo                        0x598820
#define CSidlScreenWnd__LoadIniListWnd                     0x5980B0
#define CSidlScreenWnd__LoadSidlScreen                     0x5982F0
#define CSidlScreenWnd__SetScreen                          0x5993A0
#define CSidlScreenWnd__StoreIniInfo                       0x597A50
#define CSidlScreenWnd__WndNotification                    0x5983F0

// CSliderWnd
#define CSliderWnd__GetValue                               0x5BC650
#define CSliderWnd__SetValue                               0x5BC7D0
#define CSliderWnd__UpdateThumb                            0x5BC610

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet                         0x55785F

// CStmlWnd
#define CStmlWnd__AppendSTML                               0x5A6D80
#define CStmlWnd__CalculateHSBRange                        0x59F730
#define CStmlWnd__CalculateVSBRange                        0x59F6D0
#define CStmlWnd__CanBreakAtCharacter                      0x59F870
#define CStmlWnd__CanGoBackward                            0x59F950
#define CStmlWnd__FastForwardToEndOfTag                    0x5D9C50
#define CStmlWnd__GetNextChar                              0x5913F0
#define CStmlWnd__GetNextTagPiece                          0x5A02E0
#define CStmlWnd__GetSTMLText                              0x4F6814
#define CStmlWnd__GetThisChar                              0x5D9420
#define CStmlWnd__GetVisiableText                          0x5A17D0
#define CStmlWnd__InitializeWindowVariables                0x5A34C0
#define CStmlWnd__MakeStmlColorTag                         0x59ED70
#define CStmlWnd__MakeWndNotificationTag                   0x59EE10
#define CStmlWnd__StripFirstSTMLLines                      0x5A6B10
#define CStmlWnd__UpdateHistoryString                      0x5A1C20

// CTabWnd
#define CTabWnd__Draw                                      0x5BB890
#define CTabWnd__DrawCurrentPage                           0x5BB2D0
#define CTabWnd__DrawTab                                   0x5BB0D0
#define CTabWnd__GetCurrentPage                            0x5BB5E0
#define CTabWnd__GetCurrentTabIndex                        0x5BAD90
#define CTabWnd__GetNumTabs                                0x5BAD80
#define CTabWnd__GetPageClientRect                         0x5BADA0
#define CTabWnd__GetPageFromTabIndex                       0x5BB020
#define CTabWnd__GetPageInnerRect                          0x5BAE00
#define CTabWnd__GetTabInnerRect                           0x5BAFA0
#define CTabWnd__GetTabRect                                0x5BAEB0
#define CTabWnd__IndexInBounds                             0x5BAE90
#define CTabWnd__InsertPage                                0x5BBA90
#define CTabWnd__SetPage                                   0x5BB5F0
#define CTabWnd__SetPageRect                               0x5BB7E0
#define CTabWnd__UpdatePage                                0x5BBA10

// CTextOverlay
#define CTextOverlay__DisplayText                          0x405869

// CTextureFont
#define CTextureFont__DrawWrappedText                      0x59E900

// CXMLDataManager
#define CXMLDataManager__GetXMLData                        0x5C2B40

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead                       0x597510

// CXRect
#define CXRect__CenterPoint                                0x4DBF9C

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr                                       0x4054A2
#define CXStr__CXStr1                                      0x53AA64
#define CXStr__CXStr3                                      0x571840
#define CXStr__dCXStr                                      0x445E84
#define CXStr__operator_equal1                             0x571A00
#define CXStr__operator_plus_equal1                        0x572840

// CXWnd
#define CXWnd__BringToTop                                  0x59A100
#define CXWnd__Center                                      0x59D5C0
#define CXWnd__ClrFocus                                    0x599E50
#define CXWnd__DoAllDrawing                                0x59E1B0
#define CXWnd__DrawChildren                                0x59E2E0
#define CXWnd__DrawColoredRect                             0x59A340
#define CXWnd__DrawTooltipAtPoint                          0x59D430
#define CXWnd__GetBorderFrame                              0x59A7A0
#define CXWnd__GetChildWndAt                               0x59CF90
#define CXWnd__GetClientClipRect                           0x59A6D0
#define CXWnd__GetFirstChildWnd                            0x59A190
#define CXWnd__GetNextChildWnd                             0x59CF70
#define CXWnd__GetNextSib                                  0x59A1B0
#define CXWnd__GetScreenClipRect                           0x59D850
#define CXWnd__GetScreenRect                               0x59A970
#define CXWnd__GetTooltipRect                              0x59D380
#define CXWnd__GetWindowTextA                              0x4D256E
#define CXWnd__GetXMLTooltip                               0x0
#define CXWnd__IsActive                                    0x59A740
#define CXWnd__IsDescendantOf                              0x59A750
#define CXWnd__IsReallyVisible                             0x59CF50
#define CXWnd__IsType                                      0x59E150
#define CXWnd__Move                                        0x59CB00
#define CXWnd__Move1                                       0x59CB90
#define CXWnd__ProcessTransition                           0x59A0C0
#define CXWnd__Refade                                      0x599EF0
#define CXWnd__Resize                                      0x59D990
#define CXWnd__Right                                       0x59D730
#define CXWnd__SetFirstChildPointer                        0x59ABC0
#define CXWnd__SetFocus                                    0x59BE80
#define CXWnd__SetKeyTooltip                               0x59AC00
#define CXWnd__SetMouseOver                                0x59ABE0
#define CXWnd__SetNextSibPointer                           0x59ABD0
#define CXWnd__StartFade                                   0x59A120

// CXWndManager
#define CXWndManager__DrawCursor                           0x5AE530
#define CXWndManager__DrawWindows                          0x5AE200
#define CXWndManager__GetFirstChildWnd                     0x5ADBC0
#define CXWndManager__GetKeyboardFlags                     0x5ACFD0
#define CXWndManager__HandleKeyboardMsg                    0x5AD4A0
#define CXWndManager__RemoveWnd                            0x5AD3B0

// EQ_Character
#define EQ_Character__CastSpell                            0x40F6CB
#define EQ_Character__Cur_HP                               0x415567
#define EQ_Character__GetAACastingTimeModifier             0x40BA42
#define EQ_Character__GetFocusCastingTimeModifier          0x40ADD3
#define EQ_Character__Max_Endurance                        0x4141BD
#define EQ_Character__Max_HP                               0x4140E4
#define EQ_Character__Max_Mana                             0x4BC92D
#define EQ_Character__doCombatAbility                      0x4BB876

// EQ_Item
#define EQ_Item__CanDrop                                   0x4B24E3
#define EQ_Item__GetItemLinkHash                           0x5E3190
#define EQ_Item__IsStackable                               0x5EC0C0

// EQ_LoadingS
#define EQ_LoadingS__WriteTextHD                           0x445EFF

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney                      0x4BEAF5

// EQItemList
#define EQItemList__dEQItemList                            0x462392
#define EQItemList__EQItemList                             0x462316

// EQPlayer
#define EQPlayer__ChangeBoneStringSprite                   0x479808
#define EQPlayer__dEQPlayer                                0x48364D
#define EQPlayer__DoAttack                                 0x482369
#define EQPlayer__EQPlayer                                 0x483C51
#define EQPlayer__SetNameSpriteState                       0x47BD47
#define EQPlayer__SetNameSpriteTint                        0x479874

// KeyPressHandler
#define KeypressHandler__AttachAltKeyToEqCommand           0x4B3D53
#define KeypressHandler__AttachKeyToEqCommand              0x4B3D20
#define KeypressHandler__ClearCommandStateArray            0x4B3B69
#define KeypressHandler__HandleKeyDown                     0x4B29C4
#define KeypressHandler__HandleKeyUp                       0x4B2C3B
#define KeypressHandler__SaveKeymapping                    0x4B3BF0

// MapViewMap
#define MapViewMap__Clear                                  0x5321D1
#define MapViewMap__SaveEx                                 0x53298E

// StringTable
#define StringTable__getString                             0x5DF3B0 
