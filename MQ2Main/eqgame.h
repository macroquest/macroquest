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
#define __ExpectedVersionDate                             "Oct 10 2005"
#define __ExpectedVersionTime                             "17:02:52"
#define __ActualVersionDate                                0x64C7AC
#define __ActualVersionTime                                0x64C7B8

#define __ClientOverride                                   0
#define __MacroQuestWinClassName                          "__MacroQuestTray"
#define __MacroQuestWinName                               "MacroQuest"

// Memory Protection
#define __MemChecker0                                      0x4B71B7
#define __MemChecker2                                      0x4CCEBB
#define __MemChecker3                                      0x4CCF48
#define __MemChecker4                                      0x6063C0
#define __EncryptPad0                                      0x78B380
#define __EncryptPad2                                      0x78D498
#define __EncryptPad3                                      0x78D898
#define __EncryptPad4                                      0x7986D0

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
#define __DrawHandler                                      0x99C004
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
#define pinstCDBStr                                        0x84E1E0
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
#define pinstCHotButtonWnd1                                0x98F8E4
#define pinstCHotButtonWnd2                                0x98F8E8
#define pinstCHotButtonWnd3                                0x98F8EC
#define pinstCHotButtonWnd4                                0x98F8F0
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
#define __CastRay                                          0x475152
#define __ConvertItemTags                                  0x46C731
#define __ExecuteCmd                                       0x45F7A2
#define __get_melee_range                                  0x463726
#define __GetGaugeValueFromEQ                              0x5594AE
#define __GetLabelFromEQ                                   0x559BA5
#define __LoadSplashScreen                                 0x60DC90
#define __NewUIINI                                         0x559137
#define __ProcessGameEvents                                0x4AA1F8
#define __SendMessage                                      0x48FF34
#define CrashDetected                                      0x4CCB77
#define DrawNetStatus                                      0x4B93BC


////
// Section 4: Function Offsets
////
// AltAdvManager
#define AltAdvManager__GetCalculatedTimer                  0x445953
#define AltAdvManager__IsAbilityReady                      0x445987
#define AltAdvManager__GetAltAbility                       0x445A3F

// CBankWnd
#define CBankWnd__GetNumBankSlots                          0x4DC6C9

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg                  0x4E4406

// CButtonWnd
#define CButtonWnd__SetCheck                               0x5BA180

// CChatManager
#define CChatManager__GetRGBAFromIndex                     0x4F2A13
#define CChatManager__InitContextMenu                      0x4F2F60

// CChatWindow
#define CChatWindow__CChatWindow                           0x4F66F3

// CComboWnd
#define CComboWnd__DeleteAll                               0x5BBC30
#define CComboWnd__Draw                                    0x5BBE20
#define CComboWnd__GetButtonRect                           0x5BBC60
#define CComboWnd__GetCurChoice                            0x5BBBF0
#define CComboWnd__GetListRect                             0x5BC0C0
#define CComboWnd__GetTextRect                             0x5BBCB0
#define CComboWnd__InsertChoice                            0x5BC120
#define CComboWnd__SetColors                               0x5BBB80
#define CComboWnd__SetChoice                               0x5BBBB0

// CContainerWnd
#define CContainerWnd__HandleCombine                       0x4FC041
#define CContainerWnd__vftable                             0x652750

// CDisplay
#define CDisplay__CleanGameUI                              0x4389A8
#define CDisplay__GetClickedActor                          0x436FF7
#define CDisplay__GetUserDefinedColor                      0x43654B
#define CDisplay__GetWorldFilePath                         0x435CFB
#define CDisplay__ReloadUI                                 0x4434DD
#define CDisplay__WriteTextHD2                             0x439E2C

// CEditBaseWnd
#define CEditBaseWnd__SetMaxChars                          0x4D80D2
#define CEditBaseWnd__SetSel                               0x5B91E0

// CEditWnd
#define CEditWnd__DrawCaret                                0x5B6990
#define CEditWnd__GetCharIndexPt                           0x5B7780
#define CEditWnd__GetDisplayString                         0x5B6B20
#define CEditWnd__GetHorzOffset                            0x5B6D90
#define CEditWnd__GetLineForPrintableChar                  0x5B7260
#define CEditWnd__GetSelStartPt                            0x5B79C0
#define CEditWnd__GetSTMLSafeText                          0x5B6F20
#define CEditWnd__PointFromPrintableChar                   0x5B7370
#define CEditWnd__SelectableCharFromPoint                  0x5B74E0
#define CEditWnd__SetEditable                              0x5B6EF0

// CEverQuest
#define CEverQuest__ClickedPlayer                          0x49512E
#define CEverQuest__DropHeldItemOnGround                   0x498140
#define CEverQuest__dsp_chat                               0x498912
#define CEverQuest__EnterZone                              0x4A8C5E
#define CEverQuest__GetBodyTypeDesc                        0x4910B8
#define CEverQuest__GetClassDesc                           0x490ADB
#define CEverQuest__GetClassThreeLetterCode                0x490F55
#define CEverQuest__GetDeityDesc                           0x492DB1
#define CEverQuest__GetRaceDesc                            0x4913BD
#define CEverQuest__InterpretCmd                           0x4991C4
#define CEverQuest__LeftClickedOnPlayer                    0x4A754F
#define CEverQuest__RightClickedOnPlayer                   0x4A7997
#define CEverQuest__SetGameState                           0x4951A6

// CGaugeWnd
#define CGaugeWnd__CalcFillRect                            0x50462A
#define CGaugeWnd__CalcLinesFillRect                       0x504686
#define CGaugeWnd__Draw                                    0x504986

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton                         0x513E10

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot                           0x51A4B3
#define CInvSlotMgr__MoveItem                              0x51A60E

// CItemDisplayWnd
#define CItemDisplayWnd__SetItem                           0x52166F
#define CItemDisplayWnd__SetSpell                          0x51D67A

// CLabel
#define CLabel__Draw                                       0x525D0E

// CListWnd
#define CListWnd__AddColumn                                0x5ABBD0
#define CListWnd__AddColumn1                               0x5AB6F0
#define CListWnd__AddLine                                  0x5AB280
#define CListWnd__AddString                                0x5AB450
#define CListWnd__CalculateFirstVisibleLine                0x5A8870
#define CListWnd__CalculateVSBRange                        0x5AA3B0
#define CListWnd__ClearAllSel                              0x5A80B0
#define CListWnd__CloseAndUpdateEditWindow                 0x5A8E90
#define CListWnd__Compare                                  0x5A9200
#define CListWnd__Draw                                     0x5AA0C0
#define CListWnd__DrawColumnSeparators                     0x5A9F40
#define CListWnd__DrawHeader                               0x5A8280
#define CListWnd__DrawItem                                 0x5A9910
#define CListWnd__DrawLine                                 0x5A9C80
#define CListWnd__DrawSeparator                            0x5A9FE0
#define CListWnd__EnsureVisible                            0x5A88C0
#define CListWnd__ExtendSel                                0x5A9840
#define CListWnd__GetColumnFlags                           0x5A7C50
#define CListWnd__GetColumnJustification                   0x5A7DC0
#define CListWnd__GetColumnMinWidth                        0x5A7D60
#define CListWnd__GetColumnWidth                           0x5A7CA0
#define CListWnd__GetCurSel                                0x5A7720
#define CListWnd__GetHeaderRect                            0x5A7830
#define CListWnd__GetItemAtPoint                           0x5A8BA0
#define CListWnd__GetItemAtPoint1                          0x5A8C10
#define CListWnd__GetItemData                              0x5A7A00
#define CListWnd__GetItemHeight                            0x5A8610
#define CListWnd__GetItemIcon                              0x5A7B90
#define CListWnd__GetItemRect                              0x5A8990
#define CListWnd__GetItemText                              0x5A7A40
#define CListWnd__GetSelList                               0x5AB5D0
#define CListWnd__GetSeparatorRect                         0x5A9150
#define CListWnd__IsLineEnabled                            0x5A8190
#define CListWnd__RemoveLine                               0x5AB580
#define CListWnd__SetColors                                0x5A77A0
#define CListWnd__SetColumnJustification                   0x5A7E10
#define CListWnd__SetColumnWidth                           0x5A7D20
#define CListWnd__SetCurSel                                0x5A7760
#define CListWnd__SetItemColor                             0x5AAEB0
#define CListWnd__SetItemData                              0x5A8150
#define CListWnd__SetItemText                              0x5AAE30
#define CListWnd__ShiftColumnSeparator                     0x5A97B0
#define CListWnd__Sort                                     0x5ABC00
#define CListWnd__ToggleSel                                0x5A8020

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd                           0x535B2F

// CMerchantWnd
#define CMerchantWnd__DisplayBuyOrSellPrice                0x53715D
#define CMerchantWnd__RequestBuyItem                       0x5380EF
#define CMerchantWnd__RequestSellItem                      0x53735C
#define CMerchantWnd__SelectBuySellSlot                    0x537E53

// CSidlManager
#define CSidlManager__FindScreenPieceTemplate1             0x5B4CE0

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateHSBRange                  0x597640
#define CSidlScreenWnd__CalculateVSBRange                  0x597580
#define CSidlScreenWnd__ConvertToRes                       0x597D80
#define CSidlScreenWnd__CreateChildrenFromSidl             0x5985A0
#define CSidlScreenWnd__CSidlScreenWnd1                    0x599860
#define CSidlScreenWnd__CSidlScreenWnd2                    0x599910
#define CSidlScreenWnd__dCSidlScreenWnd                    0x5990C0
#define CSidlScreenWnd__DrawSidlPiece                      0x5982C0
#define CSidlScreenWnd__EnableIniStorage                   0x597D30
#define CSidlScreenWnd__GetSidlPiece                       0x598480
#define CSidlScreenWnd__Init1                              0x599680
#define CSidlScreenWnd__LoadIniInfo                        0x598650
#define CSidlScreenWnd__LoadIniListWnd                     0x597EE0
#define CSidlScreenWnd__LoadSidlScreen                     0x598120
#define CSidlScreenWnd__SetScreen                          0x5991D0
#define CSidlScreenWnd__StoreIniInfo                       0x597880
#define CSidlScreenWnd__WndNotification                    0x598220

// CSliderWnd
#define CSliderWnd__GetValue                               0x5BC440
#define CSliderWnd__SetValue                               0x5BC5C0
#define CSliderWnd__UpdateThumb                            0x5BC400

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet                         0x5578D3

// CStmlWnd
#define CStmlWnd__AppendSTML                               0x5A6BF0
#define CStmlWnd__CalculateHSBRange                        0x59F560
#define CStmlWnd__CalculateVSBRange                        0x59F500
#define CStmlWnd__CanBreakAtCharacter                      0x59F6A0
#define CStmlWnd__CanGoBackward                            0x59F780
#define CStmlWnd__FastForwardToEndOfTag                    0x5D9A90
#define CStmlWnd__GetNextChar                              0x591270
#define CStmlWnd__GetNextTagPiece                          0x5A0150
#define CStmlWnd__GetSTMLText                              0x4F66D5
#define CStmlWnd__GetThisChar                              0x5D9260
#define CStmlWnd__GetVisiableText                          0x5A1640
#define CStmlWnd__InitializeWindowVariables                0x5A3330
#define CStmlWnd__MakeStmlColorTag                         0x59EBA0
#define CStmlWnd__MakeWndNotificationTag                   0x59EC40
#define CStmlWnd__StripFirstSTMLLines                      0x5A6980
#define CStmlWnd__UpdateHistoryString                      0x5A1A90

// CTabWnd
#define CTabWnd__Draw                                      0x5BB680
#define CTabWnd__DrawCurrentPage                           0x5BB140
#define CTabWnd__DrawTab                                   0x5BAF40
#define CTabWnd__GetCurrentPage                            0x5BB3D0
#define CTabWnd__GetCurrentTabIndex                        0x5BAC00
#define CTabWnd__GetNumTabs                                0x5BABF0
#define CTabWnd__GetPageClientRect                         0x5BAC10
#define CTabWnd__GetPageFromTabIndex                       0x5BAE90
#define CTabWnd__GetPageInnerRect                          0x5BAC70
#define CTabWnd__GetTabInnerRect                           0x5BAE10
#define CTabWnd__GetTabRect                                0x5BAD20
#define CTabWnd__IndexInBounds                             0x5BAD00
#define CTabWnd__InsertPage                                0x5BB880
#define CTabWnd__SetPage                                   0x5BB3E0
#define CTabWnd__SetPageRect                               0x5BB5D0
#define CTabWnd__UpdatePage                                0x5BB800

// CTextOverlay
#define CTextOverlay__DisplayText                          0x40588F

// CTextureFont
#define CTextureFont__DrawWrappedText                      0x59E730

// CXMLDataManager
#define CXMLDataManager__GetXMLData                        0x5C29A0

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead                       0x597340

// CXRect
#define CXRect__CenterPoint                                0x4DBEC5

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr                                       0x4054C8
#define CXStr__CXStr1                                      0x53AB5E
#define CXStr__CXStr3                                      0x571880
#define CXStr__dCXStr                                      0x4013E2
#define CXStr__operator_equal1                             0x571A40
#define CXStr__operator_plus_equal1                        0x572880

// CXWnd
#define CXWnd__BringToTop                                  0x599F50
#define CXWnd__Center                                      0x59D3F0
#define CXWnd__ClrFocus                                    0x599CA0
#define CXWnd__DoAllDrawing                                0x59DFE0
#define CXWnd__DrawChildren                                0x59E110
#define CXWnd__DrawColoredRect                             0x59A170
#define CXWnd__DrawTooltipAtPoint                          0x59D260
#define CXWnd__GetBorderFrame                              0x59A5D0
#define CXWnd__GetChildWndAt                               0x59CDC0
#define CXWnd__GetClientClipRect                           0x59A500
#define CXWnd__GetFirstChildWnd                            0x599FE0
#define CXWnd__GetNextChildWnd                             0x59CDA0
#define CXWnd__GetNextSib                                  0x59A000
#define CXWnd__GetScreenClipRect                           0x59D680
#define CXWnd__GetScreenRect                               0x59A7A0
#define CXWnd__GetTooltipRect                              0x59D1B0
#define CXWnd__GetWindowTextA                              0x4D24ED
//#define CXWnd__GetXMLTooltip                               0x0 <-- missing in 6/29
#define CXWnd__IsActive                                    0x59A570
#define CXWnd__IsDescendantOf                              0x59A580
#define CXWnd__IsReallyVisible                             0x59CD80
#define CXWnd__IsType                                      0x59DF80
#define CXWnd__Move                                        0x59C930
#define CXWnd__Move1                                       0x59C9C0
#define CXWnd__ProcessTransition                           0x599F10
#define CXWnd__Refade                                      0x599D40
#define CXWnd__Resize                                      0x59D7C0
#define CXWnd__Right                                       0x59D560
#define CXWnd__SetFirstChildPointer                        0x59A9F0
#define CXWnd__SetFocus                                    0x59BCB0
#define CXWnd__SetKeyTooltip                               0x59AA30
#define CXWnd__SetMouseOver                                0x59AA10
#define CXWnd__SetNextSibPointer                           0x59AA00
#define CXWnd__StartFade                                   0x599F70

// CXWndManager
#define CXWndManager__DrawCursor                           0x5AE430
#define CXWndManager__DrawWindows                          0x5AE100
#define CXWndManager__GetFirstChildWnd                     0x5ADA40
#define CXWndManager__GetKeyboardFlags                     0x5ACE50
#define CXWndManager__HandleKeyboardMsg                    0x5AD320
#define CXWndManager__RemoveWnd                            0x5AD230

// CDBStr
#define CDBStr__GetString                                  0x432DAF

// EQ_Character
#define EQ_Character__CastSpell                            0x40F750
#define EQ_Character__Cur_HP                               0x4155F1
#define EQ_Character__GetAACastingTimeModifier             0x40BAC7
#define EQ_Character__GetCharInfo2                         0x5E3F20
#define EQ_Character__GetFocusCastingTimeModifier          0x40AE58
#define EQ_Character__Max_Endurance                        0x414243
#define EQ_Character__Max_HP                               0x414166
#define EQ_Character__Max_Mana                             0x4BC8A5
#define EQ_Character__doCombatAbility                      0x4BB7EE

// EQ_Item
#define EQ_Item__CanDrop                                   0x4B24F6
#define EQ_Item__GetItemLinkHash                           0x5E2FD0
#define EQ_Item__IsStackable                               0x5E4430

// EQ_LoadingS
#define EQ_LoadingS__WriteTextHD                           0x44607D

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney                      0x4BEA6D

// EQItemList
#define EQItemList__dEQItemList                            0x4624EF
#define EQItemList__EQItemList                             0x462473

// EQPlayer
#define EQPlayer__ChangeBoneStringSprite                   0x479981
#define EQPlayer__dEQPlayer                                0x48380C
#define EQPlayer__DoAttack                                 0x482528
#define EQPlayer__EQPlayer                                 0x483E10
#define EQPlayer__SetNameSpriteState                       0x47BF06
#define EQPlayer__SetNameSpriteTint                        0x4799ED

// KeyPressHandler
#define KeypressHandler__AttachAltKeyToEqCommand           0x4B3CE9
#define KeypressHandler__AttachKeyToEqCommand              0x4B3CB6
#define KeypressHandler__ClearCommandStateArray            0x4B3AFF
#define KeypressHandler__HandleKeyDown                     0x4B295A
#define KeypressHandler__HandleKeyUp                       0x4B2BD1
#define KeypressHandler__SaveKeymapping                    0x4B3B86

// MapViewMap
#define MapViewMap__Clear                                  0x532295
#define MapViewMap__SaveEx                                 0x532A52

// StringTable
#define StringTable__getString                             0x5DF1F0