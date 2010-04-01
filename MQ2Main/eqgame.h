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
#define __ExpectedVersionDate                             "Sep 20 2005"
#define __ExpectedVersionTime                             "10:06:42"
#define __ActualVersionDate                                0x64C734
#define __ActualVersionTime                                0x64C740

#define __ClientOverride                                   0
#define __MacroQuestWinClassName                          "__MacroQuestTray"
#define __MacroQuestWinName                               "MacroQuest"

// Memory Protection
#define __MemChecker0                                      0x4B7218
#define __MemChecker2                                      0x4CD006
#define __MemChecker3                                      0x4CD093
#define __MemChecker4                                      0x6003C0
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
#define __CastRay                                          0x47503E
#define __ConvertItemTags                                  0x46C639
#define __ExecuteCmd                                       0x45F6A3
#define __get_melee_range                                  0x46362E
#define __GetGaugeValueFromEQ                              0x559461
#define __GetLabelFromEQ                                   0x559B58
#define __LoadSplashScreen                                 0x60DC20
#define __NewUIINI                                         0x5590EA
#define __ProcessGameEvents                                0x4AA1D6
#define __SendMessage                                      0x48FE73
#define CrashDetected                                      0x4CCCC2
#define DrawNetStatus                                      0x4B945D


////
// Section 4: Function Offsets
////
// AltAdvManager
#define AltAdvManager__GetCalculatedTimer                  0x44583C
#define AltAdvManager__IsAbilityReady                      0x445870
#define AltAdvManager__GetAltAbility                       0x445973

// CBankWnd
#define CBankWnd__GetNumBankSlots                          0x4DC835

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg                  0x4E4577

// CButtonWnd
#define CButtonWnd__SetCheck                               0x5BA200

// CChatManager
#define CChatManager__GetRGBAFromIndex                     0x4F2B4F
#define CChatManager__InitContextMenu                      0x4F309C

// CChatWindow
#define CChatWindow__CChatWindow                           0x4F682F

// CComboWnd
#define CComboWnd__DeleteAll                               0x5BBD20
#define CComboWnd__Draw                                    0x5BBF10
#define CComboWnd__GetButtonRect                           0x5BBD50
#define CComboWnd__GetCurChoice                            0x5BBCE0
#define CComboWnd__GetListRect                             0x5BC1B0
#define CComboWnd__GetTextRect                             0x5BBDA0
#define CComboWnd__InsertChoice                            0x5BC210
#define CComboWnd__SetColors                               0x5BBC70
#define CComboWnd__SetChoice                               0x5BBCA0

// CContainerWnd
#define CContainerWnd__HandleCombine                       0x4FC114
#define CContainerWnd__vftable                             0x6526D8

// CDisplay
#define CDisplay__CleanGameUI                              0x438891
#define CDisplay__GetClickedActor                          0x436ED8
#define CDisplay__GetUserDefinedColor                      0x43642C
#define CDisplay__GetWorldFilePath                         0x435BDC
#define CDisplay__ReloadUI                                 0x4433C6
#define CDisplay__WriteTextHD2                             0x439D15

// CEditBaseWnd
#define CEditBaseWnd__SetMaxChars                          0x4D821D
#define CEditBaseWnd__SetSel                               0x5B9260

// CEditWnd
#define CEditWnd__DrawCaret                                0x5B6A10
#define CEditWnd__GetCharIndexPt                           0x5B7800
#define CEditWnd__GetDisplayString                         0x5B6BA0
#define CEditWnd__GetHorzOffset                            0x5B6E10
#define CEditWnd__GetLineForPrintableChar                  0x5B72E0
#define CEditWnd__GetSelStartPt                            0x5B7A40
#define CEditWnd__GetSTMLSafeText                          0x5B6FA0
#define CEditWnd__PointFromPrintableChar                   0x5B73F0
#define CEditWnd__SelectableCharFromPoint                  0x5B7560
#define CEditWnd__SetEditable                              0x5B6F70

// CEverQuest
#define CEverQuest__ClickedPlayer                          0x4950C8
#define CEverQuest__DropHeldItemOnGround                   0x49811E
#define CEverQuest__dsp_chat                               0x4988F0
#define CEverQuest__EnterZone                              0x4A8C3C
#define CEverQuest__GetBodyTypeDesc                        0x490FF7
#define CEverQuest__GetClassDesc                           0x490A1A
#define CEverQuest__GetClassThreeLetterCode                0x490E94
#define CEverQuest__GetDeityDesc                           0x492CF0
#define CEverQuest__GetRaceDesc                            0x4912FC
#define CEverQuest__InterpretCmd                           0x4991A2
#define CEverQuest__LeftClickedOnPlayer                    0x4A752D
#define CEverQuest__RightClickedOnPlayer                   0x4A7975
#define CEverQuest__SetGameState                           0x495140

// CGaugeWnd
#define CGaugeWnd__CalcFillRect                            0x50475C
#define CGaugeWnd__CalcLinesFillRect                       0x5047B8
#define CGaugeWnd__Draw                                    0x504AB8

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton                         0x513EDB

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot                           0x51A570
#define CInvSlotMgr__MoveItem                              0x51A6CB

// CItemDisplayWnd
#define CItemDisplayWnd__SetItem                           0x521752
#define CItemDisplayWnd__SetSpell                          0x51D6F7

// CLabel
#define CLabel__Draw                                       0x525DB4

// CListWnd
#define CListWnd__AddColumn                                0x5ABC90
#define CListWnd__AddColumn1                               0x5AB7B0
#define CListWnd__AddLine                                  0x5AB340
#define CListWnd__AddString                                0x5AB510
#define CListWnd__CalculateFirstVisibleLine                0x5A8930
#define CListWnd__CalculateVSBRange                        0x5AA470
#define CListWnd__ClearAllSel                              0x5A8170
#define CListWnd__CloseAndUpdateEditWindow                 0x5A8F50
#define CListWnd__Compare                                  0x5A92C0
#define CListWnd__Draw                                     0x5AA180
#define CListWnd__DrawColumnSeparators                     0x5AA000
#define CListWnd__DrawHeader                               0x5A8340
#define CListWnd__DrawItem                                 0x5A99D0
#define CListWnd__DrawLine                                 0x5A9D40
#define CListWnd__DrawSeparator                            0x5AA0A0
#define CListWnd__EnsureVisible                            0x5A8980
#define CListWnd__ExtendSel                                0x5A9900
#define CListWnd__GetColumnFlags                           0x5A7D10
#define CListWnd__GetColumnJustification                   0x5A7E80
#define CListWnd__GetColumnMinWidth                        0x5A7E20
#define CListWnd__GetColumnWidth                           0x5A7D60
#define CListWnd__GetCurSel                                0x5A7800
#define CListWnd__GetHeaderRect                            0x5A78F0
#define CListWnd__GetItemAtPoint                           0x5A8C60
#define CListWnd__GetItemAtPoint1                          0x5A8CD0
#define CListWnd__GetItemData                              0x5A7AC0
#define CListWnd__GetItemHeight                            0x5A86D0
#define CListWnd__GetItemIcon                              0x5A7C50
#define CListWnd__GetItemRect                              0x5A8A50
#define CListWnd__GetItemText                              0x5A7B00
#define CListWnd__GetSelList                               0x5AB690
#define CListWnd__GetSeparatorRect                         0x5A9210
#define CListWnd__IsLineEnabled                            0x5A8250
#define CListWnd__RemoveLine                               0x5AB640
#define CListWnd__SetColors                                0x5A7860
#define CListWnd__SetColumnJustification                   0x5A7ED0
#define CListWnd__SetColumnWidth                           0x5A7DE0
#define CListWnd__SetCurSel                                0x5A7840
#define CListWnd__SetItemColor                             0x5AAF70
#define CListWnd__SetItemData                              0x5A8210
#define CListWnd__SetItemText                              0x5AAEF0
#define CListWnd__ShiftColumnSeparator                     0x5A9870
#define CListWnd__Sort                                     0x5ABCC0
#define CListWnd__ToggleSel                                0x5A80E0

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd                           0x535BD5

// CMerchantWnd
#define CMerchantWnd__DisplayBuyOrSellPrice                0x5371CD
#define CMerchantWnd__RequestBuyItem                       0x53815F
#define CMerchantWnd__RequestSellItem                      0x5373CC
#define CMerchantWnd__SelectBuySellSlot                    0x537EC3

// CSidlManager
#define CSidlManager__FindScreenPieceTemplate1             0x5B4D60

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateHSBRange                  0x597740
#define CSidlScreenWnd__CalculateVSBRange                  0x597680
#define CSidlScreenWnd__ConvertToRes                       0x597E80
#define CSidlScreenWnd__CreateChildrenFromSidl             0x5986A0
#define CSidlScreenWnd__CSidlScreenWnd1                    0x599960
#define CSidlScreenWnd__CSidlScreenWnd2                    0x599A10
#define CSidlScreenWnd__dCSidlScreenWnd                    0x5991C0
#define CSidlScreenWnd__DrawSidlPiece                      0x5983C0
#define CSidlScreenWnd__EnableIniStorage                   0x597E30
#define CSidlScreenWnd__GetSidlPiece                       0x598580
#define CSidlScreenWnd__Init1                              0x599780
#define CSidlScreenWnd__LoadIniInfo                        0x598750
#define CSidlScreenWnd__LoadIniListWnd                     0x597FE0
#define CSidlScreenWnd__LoadSidlScreen                     0x598220
#define CSidlScreenWnd__SetScreen                          0x5992D0
#define CSidlScreenWnd__StoreIniInfo                       0x597980
#define CSidlScreenWnd__WndNotification                    0x598320

// CSliderWnd
#define CSliderWnd__GetValue                               0x5BC530
#define CSliderWnd__SetValue                               0x5BC6B0
#define CSliderWnd__UpdateThumb                            0x5BC4F0

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet                         0x557886

// CStmlWnd
#define CStmlWnd__AppendSTML                               0x5A6CD0
#define CStmlWnd__CalculateHSBRange                        0x59F680
#define CStmlWnd__CalculateVSBRange                        0x59F620
#define CStmlWnd__CanBreakAtCharacter                      0x59F7C0
#define CStmlWnd__CanGoBackward                            0x59F8A0
#define CStmlWnd__FastForwardToEndOfTag                    0x5D9BD0
#define CStmlWnd__GetNextChar                              0x591360
#define CStmlWnd__GetNextTagPiece                          0x5A0230
#define CStmlWnd__GetSTMLText                              0x4F6811
#define CStmlWnd__GetThisChar                              0x5D93A0
#define CStmlWnd__GetVisiableText                          0x5A1720
#define CStmlWnd__InitializeWindowVariables                0x5A3410
#define CStmlWnd__MakeStmlColorTag                         0x59ECA0
#define CStmlWnd__MakeWndNotificationTag                   0x59ED40
#define CStmlWnd__StripFirstSTMLLines                      0x5A6A60
#define CStmlWnd__UpdateHistoryString                      0x5A1B70

// CTabWnd
#define CTabWnd__Draw                                      0x5BB770
#define CTabWnd__DrawCurrentPage                           0x5BB1B0
#define CTabWnd__DrawTab                                   0x5BAFB0
#define CTabWnd__GetCurrentPage                            0x5BB4C0
#define CTabWnd__GetCurrentTabIndex                        0x5BAC70
#define CTabWnd__GetNumTabs                                0x5BAC60
#define CTabWnd__GetPageClientRect                         0x5BAC80
#define CTabWnd__GetPageFromTabIndex                       0x5BAF00
#define CTabWnd__GetPageInnerRect                          0x5BACE0
#define CTabWnd__GetTabInnerRect                           0x5BAE80
#define CTabWnd__GetTabRect                                0x5BAD90
#define CTabWnd__IndexInBounds                             0x5BAD70
#define CTabWnd__InsertPage                                0x5BB970
#define CTabWnd__SetPage                                   0x5BB4D0
#define CTabWnd__SetPageRect                               0x5BB6C0
#define CTabWnd__UpdatePage                                0x5BB8F0

// CTextOverlay
#define CTextOverlay__DisplayText                          0x40583C

// CTextureFont
#define CTextureFont__DrawWrappedText                      0x59E830

// CXMLDataManager
#define CXMLDataManager__GetXMLData                        0x5C2A70

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead                       0x597440

// CXRect
#define CXRect__CenterPoint                                0x4DC031

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr                                       0x405475
#define CXStr__CXStr1                                      0x4013E2
#define CXStr__CXStr3                                      0x571870
#define CXStr__dCXStr                                      0x4013E8
#define CXStr__operator_equal1                             0x571A30
#define CXStr__operator_plus_equal1                        0x572870

// CXWnd
#define CXWnd__BringToTop                                  0x59A050
#define CXWnd__Center                                      0x59D4F0
#define CXWnd__ClrFocus                                    0x599DA0
#define CXWnd__DoAllDrawing                                0x59E0E0
#define CXWnd__DrawChildren                                0x59E210
#define CXWnd__DrawColoredRect                             0x59A270
#define CXWnd__DrawTooltipAtPoint                          0x59D360
#define CXWnd__GetBorderFrame                              0x59A6D0
#define CXWnd__GetChildWndAt                               0x59CEC0
#define CXWnd__GetClientClipRect                           0x59A600
#define CXWnd__GetFirstChildWnd                            0x59A0E0
#define CXWnd__GetNextChildWnd                             0x59CEA0
#define CXWnd__GetNextSib                                  0x59A100
#define CXWnd__GetScreenClipRect                           0x59D780
#define CXWnd__GetScreenRect                               0x59A8A0
#define CXWnd__GetTooltipRect                              0x59D2B0
#define CXWnd__GetWindowTextA                              0x4D2638
#define CXWnd__IsActive                                    0x59A670
#define CXWnd__IsDescendantOf                              0x59A680
#define CXWnd__IsReallyVisible                             0x59CE80
#define CXWnd__IsType                                      0x59E080
#define CXWnd__Move                                        0x59CA30
#define CXWnd__Move1                                       0x59CAC0
#define CXWnd__ProcessTransition                           0x59A010
#define CXWnd__Refade                                      0x599E40
#define CXWnd__Resize                                      0x59D8C0
#define CXWnd__Right                                       0x59D660
#define CXWnd__SetFirstChildPointer                        0x59AAF0
#define CXWnd__SetFocus                                    0x59BDB0
#define CXWnd__SetKeyTooltip                               0x59AB30
#define CXWnd__SetMouseOver                                0x59AB10
#define CXWnd__SetNextSibPointer                           0x59AB00
#define CXWnd__StartFade                                   0x59A070

// CXWndManager
#define CXWndManager__DrawCursor                           0x5AE510
#define CXWndManager__DrawWindows                          0x5AE1E0
#define CXWndManager__GetFirstChildWnd                     0x5ADB70
#define CXWndManager__GetKeyboardFlags                     0x5ACEF0
#define CXWndManager__HandleKeyboardMsg                    0x5AD450
#define CXWndManager__RemoveWnd                            0x5AD360

// EQ_Character
#define EQ_Character__CastSpell                            0x40F680
#define EQ_Character__Cur_HP                               0x41551D
#define EQ_Character__GetAACastingTimeModifier             0x40B9F7
#define EQ_Character__GetFocusCastingTimeModifier          0x40AD88
#define EQ_Character__Max_Endurance                        0x41416F
#define EQ_Character__Max_HP                               0x414096
#define EQ_Character__Max_Mana                             0x4BC931
#define EQ_Character__doCombatAbility                      0x4BB87A

// EQ_Item
#define EQ_Item__CanDrop                                   0x4B24BA
#define EQ_Item__GetItemLinkHash                           0x5E3120
#define EQ_Item__IsStackable                               0x5EC090

// EQ_LoadingS
#define EQ_LoadingS__WriteTextHD                           0x445FB1

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney                      0x4BEAF9

// EQItemList
#define EQItemList__dEQItemList                            0x4623F0
#define EQItemList__EQItemList                             0x462374

// EQPlayer
#define EQPlayer__ChangeBoneStringSprite                   0x47986D
#define EQPlayer__dEQPlayer                                0x483710
#define EQPlayer__DoAttack                                 0x48242C
#define EQPlayer__EQPlayer                                 0x483D14
#define EQPlayer__SetNameSpriteState                       0x47BE0A
#define EQPlayer__SetNameSpriteTint                        0x4798D9

// KeyPressHandler
#define KeypressHandler__AttachAltKeyToEqCommand           0x4B3D2A
#define KeypressHandler__AttachKeyToEqCommand              0x4B3CF7
#define KeypressHandler__ClearCommandStateArray            0x4B3B40
#define KeypressHandler__HandleKeyDown                     0x4B299B
#define KeypressHandler__HandleKeyUp                       0x4B2C12
#define KeypressHandler__SaveKeymapping                    0x4B3BC7

// MapViewMap
#define MapViewMap__Clear                                  0x53233B
#define MapViewMap__SaveEx                                 0x532AF8

// StringTable
#define StringTable__getString                             0x5DF330 
#define pinstCDBStr                                        0x84E1E0
#define CDBStr__GetString                                  0x432C90
