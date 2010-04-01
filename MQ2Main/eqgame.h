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
#define __ExpectedVersionDate                             "Oct 31 2005"
#define __ExpectedVersionTime                             "10:33:37"
#define __ActualVersionDate                                0x64D1D4
#define __ActualVersionTime                                0x64D1E0

#define __ClientOverride                                   0
#define __MacroQuestWinClassName                          "__MacroQuestTray"
#define __MacroQuestWinName                               "MacroQuest"

// Memory Protection
#define __MemChecker0                                      0x4B6C04
#define __MemChecker2                                      0x4CCA44
#define __MemChecker3                                      0x4CCAD1
#define __MemChecker4                                      0x600A70
#define __EncryptPad0                                      0x78E418
#define __EncryptPad2                                      0x790540
#define __EncryptPad3                                      0x790940
#define __EncryptPad4                                      0x79A810

// Direct Input
#define DI8__Main                                          0x988C7C
#define DI8__Keyboard                                      0x988C80
#define DI8__Mouse                                         0x988C84

#define __AltTimerReady                                    0x924672
#define __Attack                                           0x9858C7
#define __BindList                                         0x789908
#define __Clicks                                           0x923874
#define __CommandList                                      0x78A0C8
#define __CurrentMapLabel                                  0x991CFC
#define __CurrentSocial                                    0x694D8C
#define __DoAbilityAvailable                               0x92460C
#define __DoAbilityList                                    0x95D414
#define __DrawHandler                                      0x99E364
#define __EQP_IDArray                                      0x900F50
#define __FriendsList                                      0x95A1B4
#define __GroupCount                                       0x904248
#define __GroupLeader                                      0x9043A4
#define __Guilds                                           0x905D38
#define __gWorld                                           0x905CA0
#define __HotkeyPage                                       0x984800
#define __HWnd                                             0x923770
#define __IgnoreList                                       0x95BAB4
#define __InChatMode                                       0x9237B0
#define __LastTell                                         0x925920
#define __Mouse                                            0x988C88
#define __MouseLook                                        0x923842
#define __NetStatusToggle                                  0x923844
#define __PCNames                                          0x924978
#define __RangeAttackReady                                 0x924670
#define __RunWalkState                                     0x9237B4
#define __ScreenMode                                       0x850508
#define __ScreenX                                          0x923778
#define __ScreenY                                          0x92377C
#define __ServerHost                                       0x904104
#define __ServerName                                       0x95D3D4
#define __ShowNames                                        0x924860
#define __SkillDict                                        0x851200
#define __Socials                                          0x95D4D4

////
//Section 1: Vital Offsets
////
#define instCRaid                                          0x91D708
#define instEQZoneInfo                                     0x9239E0
#define instKeypressHandler                                0x98599C
#define pinstActiveBanker                                  0x905D14
#define pinstActiveCorpse                                  0x905D18
#define pinstActiveGMaster                                 0x905D1C
#define pinstActiveMerchant                                0x905D10
#define pinstAltAdvManager                                 0x8511D8
#define pinstCDBStr                                        0x850398
#define pinstCDisplay                                      0x905D24
#define pinstCEverQuest                                    0x988DF0
#define pinstCharData                                      0x905D00
#define pinstCharSpawn                                     0x905CF8
#define pinstControlledPlayer                              0x905CF8
#define pinstCSidlManager                                  0x99D3F4
#define pinstCXWndManager                                  0x99D3EC
#define pinstEQItemList                                    0x905CC8
#define instGroup                                          0x904248
#define pinstLocalPlayer                                   0x905CE4
#define pinstPCData                                        0x905D00
#define pinstSelectedItem                                  0x991B54
#define pinstSpawnList                                     0x905CC4
#define pinstSpellManager                                  0x985CC8
#define pinstSpellSets                                     0x984804
#define pinstStringTable                                   0x905CB0
#define pinstSwitchManager                                 0x903E84
#define pinstTarget                                        0x905D04
#define pinstTargetSwitch                                  0x905D0C
#define pinstTradeTarget                                   0x905CE0
#define instTributeActive                                  0x850375
#define pinstWorldData                                     0x905CC0


////
//Section 2:  UI Related Offsets
////
#define pinstCTextOverlay                                  0x79C164
#define pinstCharacterSelect                               0x850B9C
#define pinstCFacePick                                     0x850BA0
#define pinstCNoteWnd                                      0x850BA4
#define pinstCHelpWnd                                      0x9928A8
#define pinstCBookWnd                                      0x850BA8
#define pinstCPetInfoWnd                                   0x850BAC
#define pinstCTrainWnd                                     0x850BB0
#define pinstCSkillsWnd                                    0x850BB4
#define pinstCSkillsSelectWnd                              0x850BB8
#define pinstCCombatSkillSelectWnd                         0x850BBC
#define pinstCFriendsWnd                                   0x850BC0
#define pinstCAAWnd                                        0x850BD0
#define pinstCGroupSearchFiltersWnd                        0x850BD4
#define pinstCLoadskinWnd                                  0x850BD8
#define pinstCAlarmWnd                                     0x850BDC
#define pinstCMusicPlayerWnd                               0x850BE0
#define pinstCRaidWnd                                      0x850BF0
#define pinstCRaidOptionsWnd                               0x850BF4
#define pinstCBreathWnd                                    0x850BF8
#define pinstCMapViewWnd                                   0x850BFC
#define pinstCMapToolbarWnd                                0x850C00
#define pinstCEditLabelWnd                                 0x850C04
#define pinstCTargetWnd                                    0x850C08
#define pinstCHotButtonWnd                                 0x991AE4
#define pinstCHotButtonWnd1                                0x991AE4
#define pinstCHotButtonWnd2                                0x991AE8
#define pinstCHotButtonWnd3                                0x991AEC
#define pinstCHotButtonWnd4                                0x991AF0
#define pinstCColorPickerWnd                               0x850C0C
#define pinstCPlayerWnd                                    0x850C10
#define pinstCOptionsWnd                                   0x850C14
#define pinstCBuffWindowNORMAL                             0x850C18
#define pinstCBuffWindowSHORT                              0x850C1C
#define pinstCharacterCreation                             0x850C20
#define pinstCCursorAttachment                             0x850C24
#define pinstCCastingWnd                                   0x850C28
#define pinstCCastSpellWnd                                 0x850C2C
#define pinstCSpellBookWnd                                 0x850C30
#define pinstCInventoryWnd                                 0x850C34
#define pinstCBankWnd                                      0x850C38
#define pinstCQuantityWnd                                  0x850C3C
#define pinstCLootWnd                                      0x850C40
#define pinstCActionsWnd                                   0x850C44
#define pinstCCombatAbilityWnd                             0x850C48
#define pinstCMerchantWnd                                  0x850C4C
#define pinstCTradeWnd                                     0x850C50
#define pinstCSelectorWnd                                  0x850C54
#define pinstCBazaarWnd                                    0x850C58
#define pinstCBazaarSearchWnd                              0x850C5C
#define pinstCGiveWnd                                      0x850C60
#define pinstCTrackingWnd                                  0x850C64
#define pinstCInspectWnd                                   0x850C68
#define pinstCSocialEditWnd                                0x850C6C
#define pinstCFeedbackWnd                                  0x850C70
#define pinstCBugReportWnd                                 0x850C74
#define pinstCVideoModesWnd                                0x850C78
#define pinstCTextEntryWnd                                 0x850C80
#define pinstCFileSelectionWnd                             0x850C84
#define pinstCCompassWnd                                   0x850C88
#define pinstCPlayerNotesWnd                               0x850C8C
#define pinstCGemsGameWnd                                  0x850C90
#define pinstCTimeLeftWnd                                  0x850C94
#define pinstCPetitionQWnd                                 0x850C98
#define pinstCSoulmarkWnd                                  0x850C9C
#define pinstCStoryWnd                                     0x850CA0
#define pinstCJournalTextWnd                               0x850CA4
#define pinstCJournalCatWnd                                0x850CA8
#define pinstCBodyTintWnd                                  0x850CAC
#define pinstCInvSlotMgr                                   0x850CB8
#define pinstCContainerMgr                                 0x850CBC
#define pinstCAdventureLeaderboardWnd                      0x9913B8
#define pinstCAdventureMerchantWnd                         0x79C104
#define pinstCAdventureRequestWnd                          0x9913D4
#define pinstCAdventureStatsWnd                            0x9913F0
#define pinstCChatManager                                  0x9917E4
#define pinstCDynamicZoneWnd                               0x9918C0
#define pinstCFindLocationWnd                              0x9919C4
#define pinstCGroupSearchWnd                               0x991A58
#define pinstCGroupWnd                                     0x991A74
#define pinstCGuildMgmtWnd                                 0x991AAC
#define pinstCItemDisplayManager                           0x991B88
#define pinstCLeadershipWnd                                0x991C24
#define pinstCPopupWndManager                              0x991E44
#define pinstCSystemInfoDialogBox                          0x9927D0
#define pinstCTargetOfTargetWnd                            0x9927EC
#define pinstCTipWndOFDAY                                  0x9928DC
#define pinstCTipWndCONTEXT                                0x9928E0
#define pinstCTradeskillWnd                                0x992940
#define pinstCTributeBenefitWnd                            0x99298C
#define pinstCTributeMasterWnd                             0x9929A8
#define pinstCContextMenuManager                           0x99D414
// unknown window added 4-14 exe 0x79A234


////
// Section 3: Miscellaneous Offsets
////
#define __CastRay                                          0x476167
#define __ConvertItemTags                                  0x46D46D
#define __ExecuteCmd                                       0x4619CD
#define __FastTime                                         0x576E80
#define __get_melee_range                                  0x46595A
#define __GetGaugeValueFromEQ                              0x5598BC
#define __GetLabelFromEQ                                   0x559FB3
#define __LoadSplashScreen                                 0x60E450
#define __NewUIINI                                         0x559545
#define __ProcessGameEvents                                0x4A9C84
#define __SendMessage                                      0x4912B1
#define CrashDetected                                      0x4CC700
#define DrawNetStatus                                      0x4B8DFD


////
// Section 4: Function Offsets
////
// AltAdvManager
#define AltAdvManager__GetCalculatedTimer                  0x447BAE
#define AltAdvManager__IsAbilityReady                      0x447BE2
#define AltAdvManager__GetAltAbility                       0x447D07

// CBankWnd
#define CBankWnd__GetNumBankSlots                          0x4DC831

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg                  0x4E455A

// CButtonWnd
#define CButtonWnd__SetCheck                               0x5BB140

// CChatManager
#define CChatManager__GetRGBAFromIndex                     0x4F2BBE
#define CChatManager__InitContextMenu                      0x4F3120

// CChatWindow
#define CChatWindow__CChatWindow                           0x4F68B3

// CComboWnd
#define CComboWnd__DeleteAll                               0x59C3E0
#define CComboWnd__Draw                                    0x59C5D0
#define CComboWnd__GetButtonRect                           0x59C410
#define CComboWnd__GetCurChoice                            0x59C3A0
#define CComboWnd__GetListRect                             0x59C870
#define CComboWnd__GetTextRect                             0x59C460
#define CComboWnd__InsertChoice                            0x59C8D0
#define CComboWnd__SetColors                               0x59C330
#define CComboWnd__SetChoice                               0x59C360

// CContainerWnd
#define CContainerWnd__HandleCombine                       0x4FC106
#define CContainerWnd__vftable                             0x6531A0

// CDisplay
#define CDisplay__CleanGameUI                              0x43AF46
#define CDisplay__GetClickedActor                          0x43962A
#define CDisplay__GetUserDefinedColor                      0x438BA7
#define CDisplay__GetWorldFilePath                         0x438357
#define CDisplay__ReloadUI                                 0x443DBC
#define CDisplay__WriteTextHD2                             0x43C3E0

// CEditBaseWnd
#define CEditBaseWnd__SetMaxChars                          0x4D7EBC
#define CEditBaseWnd__SetSel                               0x5BA1A0

// CEditWnd
#define CEditWnd__DrawCaret                                0x5B7940
#define CEditWnd__GetCharIndexPt                           0x5B8740
#define CEditWnd__GetDisplayString                         0x5B7AD0
#define CEditWnd__GetHorzOffset                            0x5B7D40
#define CEditWnd__GetLineForPrintableChar                  0x5B8220
#define CEditWnd__GetSelStartPt                            0x5B8980
#define CEditWnd__GetSTMLSafeText                          0x5B7ED0
#define CEditWnd__PointFromPrintableChar                   0x5B8330
#define CEditWnd__SelectableCharFromPoint                  0x5B84A0
#define CEditWnd__SetEditable                              0x5B7EA0

// CEverQuest
#define CEverQuest__ClickedPlayer                          0x494AC5
#define CEverQuest__DropHeldItemOnGround                   0x497AF4
#define CEverQuest__dsp_chat                               0x4982C6
#define CEverQuest__EnterZone                              0x4A861D
#define CEverQuest__GetBodyTypeDesc                        0x492438
#define CEverQuest__GetClassDesc                           0x491E5B
#define CEverQuest__GetClassThreeLetterCode                0x4922D5
#define CEverQuest__GetDeityDesc                           0x49275D
#define CEverQuest__GetRaceDesc                            0x49273D
#define CEverQuest__InterpretCmd                           0x498B78
#define CEverQuest__LeftClickedOnPlayer                    0x4A6F0E
#define CEverQuest__RightClickedOnPlayer                   0x4A7356
#define CEverQuest__SetGameState                           0x494B3D

// CGaugeWnd
#define CGaugeWnd__CalcFillRect                            0x5046A2
#define CGaugeWnd__CalcLinesFillRect                       0x5046FE
#define CGaugeWnd__Draw                                    0x5049FE

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton                         0x51415B

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot                           0x51A84D
#define CInvSlotMgr__MoveItem                              0x51A9A8

// CItemDisplayWnd
#define CItemDisplayWnd__SetItem                           0x521827
#define CItemDisplayWnd__SetSpell                          0x51DA3B

// CLabel
#define CLabel__Draw                                       0x525E89

// CListWnd
#define CListWnd__AddColumn                                0x59C140
#define CListWnd__AddColumn1                               0x59BC70
#define CListWnd__AddLine                                  0x59B800
#define CListWnd__AddString                                0x59B9D0
#define CListWnd__CalculateFirstVisibleLine                0x598D40
#define CListWnd__CalculateVSBRange                        0x59A880
#define CListWnd__ClearAllSel                              0x598580
#define CListWnd__CloseAndUpdateEditWindow                 0x599360
#define CListWnd__Compare                                  0x5996D0
#define CListWnd__Draw                                     0x59A590
#define CListWnd__DrawColumnSeparators                     0x59A410
#define CListWnd__DrawHeader                               0x598750
#define CListWnd__DrawItem                                 0x599DE0
#define CListWnd__DrawLine                                 0x59A150
#define CListWnd__DrawSeparator                            0x59A4B0
#define CListWnd__EnsureVisible                            0x598D90
#define CListWnd__ExtendSel                                0x599D10
#define CListWnd__GetColumnFlags                           0x598120
#define CListWnd__GetColumnJustification                   0x598290
#define CListWnd__GetColumnMinWidth                        0x598230
#define CListWnd__GetColumnWidth                           0x598170
#define CListWnd__GetCurSel                                0x597BE0
#define CListWnd__GetHeaderRect                            0x597CF0
#define CListWnd__GetItemAtPoint                           0x599070
#define CListWnd__GetItemAtPoint1                          0x5990E0
#define CListWnd__GetItemData                              0x597ED0
#define CListWnd__GetItemHeight                            0x598AE0
#define CListWnd__GetItemIcon                              0x598060
#define CListWnd__GetItemRect                              0x598E60
#define CListWnd__GetItemText                              0x597F10
#define CListWnd__GetSelList                               0x59BB50
#define CListWnd__GetSeparatorRect                         0x599620
#define CListWnd__IsLineEnabled                            0x598660
#define CListWnd__RemoveLine                               0x59BB00
#define CListWnd__SetColors                                0x597C60
#define CListWnd__SetColumnJustification                   0x5982E0
#define CListWnd__SetColumnWidth                           0x5981F0
#define CListWnd__SetCurSel                                0x597C20
#define CListWnd__SetItemColor                             0x59B3E0
#define CListWnd__SetItemData                              0x598620
#define CListWnd__SetItemText                              0x59B360
#define CListWnd__ShiftColumnSeparator                     0x599C80
#define CListWnd__Sort                                     0x59C170
#define CListWnd__ToggleSel                                0x5984F0

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd                           0x535CAA

// CMerchantWnd
#define CMerchantWnd__DisplayBuyOrSellPrice                0x5372D8
#define CMerchantWnd__RequestBuyItem                       0x53826A
#define CMerchantWnd__RequestSellItem                      0x5374D7
#define CMerchantWnd__SelectBuySellSlot                    0x537FCE

// CSidlManager
#define CSidlManager__FindScreenPieceTemplate1             0x5B5C70

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateHSBRange                  0x5A1650
#define CSidlScreenWnd__CalculateVSBRange                  0x5A1590
#define CSidlScreenWnd__ConvertToRes                       0x5A1D90
#define CSidlScreenWnd__CreateChildrenFromSidl             0x5A25B0
#define CSidlScreenWnd__CSidlScreenWnd1                    0x5A3850
#define CSidlScreenWnd__CSidlScreenWnd2                    0x5A3900
#define CSidlScreenWnd__dCSidlScreenWnd                    0x5A3100
#define CSidlScreenWnd__DrawSidlPiece                      0x5A22D0
#define CSidlScreenWnd__EnableIniStorage                   0x5A1D40
#define CSidlScreenWnd__GetSidlPiece                       0x5A2490
#define CSidlScreenWnd__Init1                              0x5A3670
#define CSidlScreenWnd__LoadIniInfo                        0x5A2660
#define CSidlScreenWnd__LoadIniListWnd                     0x5A1EF0
#define CSidlScreenWnd__LoadSidlScreen                     0x5A2130
#define CSidlScreenWnd__SetScreen                          0x5A3210
#define CSidlScreenWnd__StoreIniInfo                       0x5A1890
#define CSidlScreenWnd__WndNotification                    0x5A2230

// CSliderWnd
#define CSliderWnd__GetValue                               0x5BCB90
#define CSliderWnd__SetValue                               0x5BCD10
#define CSliderWnd__UpdateThumb                            0x5BCB50

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet                         0x557CD8

// CStmlWnd
#define CStmlWnd__AppendSTML                               0x5AC2A0
#define CStmlWnd__CalculateHSBRange                        0x5A4AB0
#define CStmlWnd__CalculateVSBRange                        0x5A4A50
#define CStmlWnd__CanBreakAtCharacter                      0x5A4BF0
#define CStmlWnd__CanGoBackward                            0x5A4CD0
#define CStmlWnd__FastForwardToEndOfTag                    0x5DA2A0
#define CStmlWnd__GetNextChar                              0x5918C0
#define CStmlWnd__GetNextTagPiece                          0x5A5670
#define CStmlWnd__GetSTMLText                              0x4F6895
#define CStmlWnd__GetThisChar                              0x5D9A70
#define CStmlWnd__GetVisiableText                          0x5A6890
#define CStmlWnd__InitializeWindowVariables                0x5A89E0
#define CStmlWnd__MakeStmlColorTag                         0x5A40F0
#define CStmlWnd__MakeWndNotificationTag                   0x5A4190
#define CStmlWnd__StripFirstSTMLLines                      0x5AC030
#define CStmlWnd__UpdateHistoryString                      0x5A70F0

// CTabWnd
#define CTabWnd__Draw                                      0x5BC640
#define CTabWnd__DrawCurrentPage                           0x5BC100
#define CTabWnd__DrawTab                                   0x5BBF00
#define CTabWnd__GetCurrentPage                            0x5BC390
#define CTabWnd__GetCurrentTabIndex                        0x5BBBC0
#define CTabWnd__GetNumTabs                                0x5BBBB0
#define CTabWnd__GetPageClientRect                         0x5BBBD0
#define CTabWnd__GetPageFromTabIndex                       0x5BBE50
#define CTabWnd__GetPageInnerRect                          0x5BBC30
#define CTabWnd__GetTabInnerRect                           0x5BBDD0
#define CTabWnd__GetTabRect                                0x5BBCE0
#define CTabWnd__IndexInBounds                             0x5BBCC0
#define CTabWnd__InsertPage                                0x5BC840
#define CTabWnd__SetPage                                   0x5BC3A0
#define CTabWnd__SetPageRect                               0x5BC590
#define CTabWnd__UpdatePage                                0x5BC7C0

// CTextOverlay
#define CTextOverlay__DisplayText                          0x40812F

// CTextureFont
#define CTextureFont__DrawWrappedText                      0x5A3C80

// CXMLDataManager
#define CXMLDataManager__GetXMLData                        0x5C3070

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead                       0x597990

// CXRect
#define CXRect__CenterPoint                                0x4DC02D

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr                                       0x407D68
#define CXStr__CXStr1                                      0x53ACD9
#define CXStr__CXStr3                                      0x571E00
#define CXStr__dCXStr                                      0x4482FB
#define CXStr__operator_equal1                             0x571FC0
#define CXStr__operator_plus_equal1                        0x572E00

// CXWnd
#define CXWnd__BringToTop                                  0x59D080
#define CXWnd__Center                                      0x5A0480
#define CXWnd__ClrFocus                                    0x59CDD0
#define CXWnd__DoAllDrawing                                0x5A1070
#define CXWnd__DrawChildren                                0x5A11A0
#define CXWnd__DrawColoredRect                             0x59D2E0
#define CXWnd__DrawTooltipAtPoint                          0x5A02F0
#define CXWnd__GetBorderFrame                              0x59D790
#define CXWnd__GetChildWndAt                               0x59FF00
#define CXWnd__GetClientClipRect                           0x59D6C0
#define CXWnd__GetFirstChildWnd                            0x59D110
#define CXWnd__GetNextChildWnd                             0x59FEE0
#define CXWnd__GetNextSib                                  0x59D130
#define CXWnd__GetScreenClipRect                           0x5A0710
#define CXWnd__GetScreenRect                               0x59D960
#define CXWnd__GetTooltipRect                              0x59D1F0
#define CXWnd__GetWindowTextA                              0x4D22D7
#define CXWnd__IsActive                                    0x59D730
#define CXWnd__IsDescendantOf                              0x59D740
#define CXWnd__IsReallyVisible                             0x59FEC0
#define CXWnd__IsType                                      0x5A1010
#define CXWnd__Move                                        0x59FA70
#define CXWnd__Move1                                       0x59FB00
#define CXWnd__ProcessTransition                           0x59D040
#define CXWnd__Refade                                      0x59CE70
#define CXWnd__Resize                                      0x5A0850
#define CXWnd__Right                                       0x5A05F0
#define CXWnd__SetFirstChildPointer                        0x59DBB0
#define CXWnd__SetFocus                                    0x59EDF0
#define CXWnd__SetKeyTooltip                               0x59DBF0
#define CXWnd__SetMouseOver                                0x59DBD0
#define CXWnd__SetNextSibPointer                           0x59DBC0
#define CXWnd__StartFade                                   0x59D0A0

// CXWndManager
#define CXWndManager__DrawCursor                           0x5AF580
#define CXWndManager__DrawWindows                          0x5AF250
#define CXWndManager__GetFirstChildWnd                     0x5AEB60
#define CXWndManager__GetKeyboardFlags                     0x5ADF60
#define CXWndManager__HandleKeyboardMsg                    0x5AE430
#define CXWndManager__RemoveWnd                            0x5AE340

// CDBStr
#define CDBStr__GetString                                  0x4355F7

// EQ_Character
#define EQ_Character__CastSpell                            0x411F3D
#define EQ_Character__Cur_HP                               0x417E07
#define EQ_Character__GetAACastingTimeModifier             0x40E2D2
#define EQ_Character__GetCharInfo2                         0x5EC220
#define EQ_Character__GetFocusCastingTimeModifier          0x40D663
#define EQ_Character__Max_Endurance                        0x416A40
#define EQ_Character__Max_HP                               0x416963
#define EQ_Character__Max_Mana                             0x4BC454
#define EQ_Character__doCombatAbility                      0x4BB39D

// EQ_Item
#define EQ_Item__CanDrop                                   0x4B1EE3
#define EQ_Item__GetItemLinkHash                           0x5E3850
#define EQ_Item__IsStackable                               0x5EC760

// EQ_LoadingS
#define EQ_LoadingS__WriteTextHD                           0x448376

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney                      0x4BE5FE
#define EQ_PC__GetItemTimerValue                           0x4BAC48

// EQItemList
#define EQItemList__dEQItemList                            0x46471B
#define EQItemList__EQItemList                             0x46469F

// EQPlayer
#define EQPlayer__ChangeBoneStringSprite                   0x47A99F
#define EQPlayer__dEQPlayer                                0x4849B2
#define EQPlayer__DoAttack                                 0x48297B
#define EQPlayer__EQPlayer                                 0x4850A0
#define EQPlayer__SetNameSpriteState                       0x47CF7C
#define EQPlayer__SetNameSpriteTint                        0x47AA0B

// KeyPressHandler
#define KeypressHandler__AttachAltKeyToEqCommand           0x4B3754
#define KeypressHandler__AttachKeyToEqCommand              0x4B3721
#define KeypressHandler__ClearCommandStateArray            0x4B3569
#define KeypressHandler__HandleKeyDown                     0x4B23C4
#define KeypressHandler__HandleKeyUp                       0x4B263B
#define KeypressHandler__SaveKeymapping                    0x4B35F1

// MapViewMap
#define MapViewMap__Clear                                  0x532410
#define MapViewMap__SaveEx                                 0x532BCD

// StringTable
#define StringTable__getString                             0x5DFA00 
