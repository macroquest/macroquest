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
#define __ExpectedVersionDate                             "Oct 25 2005"
#define __ExpectedVersionTime                             "17:13:06"
#define __ActualVersionDate                                0x64D1E4
#define __ActualVersionTime                                0x64D1F0

#define __ClientOverride                                   0
#define __MacroQuestWinClassName                          "__MacroQuestTray"
#define __MacroQuestWinName                               "MacroQuest"

// Memory Protection
#define __MemChecker0                                      0x4B6BE7
#define __MemChecker2                                      0x4CCA27
#define __MemChecker3                                      0x4CCAB4
#define __MemChecker4                                      0x600A30
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
#define __FastTime                                         0x576E60
#define __get_melee_range                                  0x46595A
#define __GetGaugeValueFromEQ                              0x55989F
#define __GetLabelFromEQ                                   0x559F96
#define __LoadSplashScreen                                 0x60E410
#define __NewUIINI                                         0x559528
#define __ProcessGameEvents                                0x4A9C67
#define __SendMessage                                      0x491294
#define CrashDetected                                      0x4CC6E3
#define DrawNetStatus                                      0x4B8DE0


////
// Section 4: Function Offsets
////
// AltAdvManager
#define AltAdvManager__GetCalculatedTimer                  0x447BAE
#define AltAdvManager__IsAbilityReady                      0x447BE2
#define AltAdvManager__GetAltAbility                       0x447D07

// CBankWnd
#define CBankWnd__GetNumBankSlots                          0x4DC814

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg                  0x4E453D

// CButtonWnd
#define CButtonWnd__SetCheck                               0x5BB100

// CChatManager
#define CChatManager__GetRGBAFromIndex                     0x4F2BA1
#define CChatManager__InitContextMenu                      0x4F3103

// CChatWindow
#define CChatWindow__CChatWindow                           0x4F6896

// CComboWnd
#define CComboWnd__DeleteAll                               0x59C3A0
#define CComboWnd__Draw                                    0x59C590
#define CComboWnd__GetButtonRect                           0x59C3D0
#define CComboWnd__GetCurChoice                            0x59C360
#define CComboWnd__GetListRect                             0x59C830
#define CComboWnd__GetTextRect                             0x59C420
#define CComboWnd__InsertChoice                            0x59C890
#define CComboWnd__SetColors                               0x59C2F0
#define CComboWnd__SetChoice                               0x59C320

// CContainerWnd
#define CContainerWnd__HandleCombine                       0x4FC0E9
#define CContainerWnd__vftable                             0x6531B0

// CDisplay
#define CDisplay__CleanGameUI                              0x43AF46
#define CDisplay__GetClickedActor                          0x43962A
#define CDisplay__GetUserDefinedColor                      0x438BA7
#define CDisplay__GetWorldFilePath                         0x438357
#define CDisplay__ReloadUI                                 0x443DBC
#define CDisplay__WriteTextHD2                             0x43C3E0

// CEditBaseWnd
#define CEditBaseWnd__SetMaxChars                          0x4D7E9F
#define CEditBaseWnd__SetSel                               0x5BA160

// CEditWnd
#define CEditWnd__DrawCaret                                0x5B7900
#define CEditWnd__GetCharIndexPt                           0x5B8700
#define CEditWnd__GetDisplayString                         0x5B7A90
#define CEditWnd__GetHorzOffset                            0x5B7D00
#define CEditWnd__GetLineForPrintableChar                  0x5B81E0
#define CEditWnd__GetSelStartPt                            0x5B8940
#define CEditWnd__GetSTMLSafeText                          0x5B7E90
#define CEditWnd__PointFromPrintableChar                   0x5B82F0
#define CEditWnd__SelectableCharFromPoint                  0x5B8460
#define CEditWnd__SetEditable                              0x5B7E60

// CEverQuest
#define CEverQuest__ClickedPlayer                          0x494AA8
#define CEverQuest__DropHeldItemOnGround                   0x497AD7
#define CEverQuest__dsp_chat                               0x4982A9
#define CEverQuest__EnterZone                              0x4A8600
#define CEverQuest__GetBodyTypeDesc                        0x49241B
#define CEverQuest__GetClassDesc                           0x491E3E
#define CEverQuest__GetClassThreeLetterCode                0x4922B8
#define CEverQuest__GetDeityDesc                           0x492740
#define CEverQuest__GetRaceDesc                            0x492720
#define CEverQuest__InterpretCmd                           0x498B5B
#define CEverQuest__LeftClickedOnPlayer                    0x4A6EF1
#define CEverQuest__RightClickedOnPlayer                   0x4A7339
#define CEverQuest__SetGameState                           0x494B20

// CGaugeWnd
#define CGaugeWnd__CalcFillRect                            0x504685
#define CGaugeWnd__CalcLinesFillRect                       0x5046E1
#define CGaugeWnd__Draw                                    0x5049E1

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton                         0x51413E

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot                           0x51A830
#define CInvSlotMgr__MoveItem                              0x51A98B

// CItemDisplayWnd
#define CItemDisplayWnd__SetItem                           0x52180A
#define CItemDisplayWnd__SetSpell                          0x51DA1E

// CLabel
#define CLabel__Draw                                       0x525E6C

// CListWnd
#define CListWnd__AddColumn                                0x59C100
#define CListWnd__AddColumn1                               0x59BC30
#define CListWnd__AddLine                                  0x59B7C0
#define CListWnd__AddString                                0x59B990
#define CListWnd__CalculateFirstVisibleLine                0x598D00
#define CListWnd__CalculateVSBRange                        0x59A840
#define CListWnd__ClearAllSel                              0x598540
#define CListWnd__CloseAndUpdateEditWindow                 0x599320
#define CListWnd__Compare                                  0x599690
#define CListWnd__Draw                                     0x59A550
#define CListWnd__DrawColumnSeparators                     0x59A3D0
#define CListWnd__DrawHeader                               0x598710
#define CListWnd__DrawItem                                 0x599DA0
#define CListWnd__DrawLine                                 0x59A110
#define CListWnd__DrawSeparator                            0x59A470
#define CListWnd__EnsureVisible                            0x598D50
#define CListWnd__ExtendSel                                0x599CD0
#define CListWnd__GetColumnFlags                           0x5980E0
#define CListWnd__GetColumnJustification                   0x598250
#define CListWnd__GetColumnMinWidth                        0x5981F0
#define CListWnd__GetColumnWidth                           0x598130
#define CListWnd__GetCurSel                                0x597BA0
#define CListWnd__GetHeaderRect                            0x597CB0
#define CListWnd__GetItemAtPoint                           0x599030
#define CListWnd__GetItemAtPoint1                          0x5990A0
#define CListWnd__GetItemData                              0x597E90
#define CListWnd__GetItemHeight                            0x598AA0
#define CListWnd__GetItemIcon                              0x598020
#define CListWnd__GetItemRect                              0x598E20
#define CListWnd__GetItemText                              0x597ED0
#define CListWnd__GetSelList                               0x59BB10
#define CListWnd__GetSeparatorRect                         0x5995E0
#define CListWnd__IsLineEnabled                            0x598620
#define CListWnd__RemoveLine                               0x59BAC0
#define CListWnd__SetColors                                0x597C20
#define CListWnd__SetColumnJustification                   0x5982A0
#define CListWnd__SetColumnWidth                           0x5981B0
#define CListWnd__SetCurSel                                0x597BE0
#define CListWnd__SetItemColor                             0x59B3A0
#define CListWnd__SetItemData                              0x5985E0
#define CListWnd__SetItemText                              0x59B320
#define CListWnd__ShiftColumnSeparator                     0x599C40
#define CListWnd__Sort                                     0x59C130
#define CListWnd__ToggleSel                                0x5984B0

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd                           0x535C8D

// CMerchantWnd
#define CMerchantWnd__DisplayBuyOrSellPrice                0x5372BB
#define CMerchantWnd__RequestBuyItem                       0x53824D
#define CMerchantWnd__RequestSellItem                      0x5374BA
#define CMerchantWnd__SelectBuySellSlot                    0x537FB1

// CSidlManager
#define CSidlManager__FindScreenPieceTemplate1             0x5B5C30

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateHSBRange                  0x5A1610
#define CSidlScreenWnd__CalculateVSBRange                  0x5A1550
#define CSidlScreenWnd__ConvertToRes                       0x5A1D50
#define CSidlScreenWnd__CreateChildrenFromSidl             0x5A2570
#define CSidlScreenWnd__CSidlScreenWnd1                    0x5A3810
#define CSidlScreenWnd__CSidlScreenWnd2                    0x5A38C0
#define CSidlScreenWnd__dCSidlScreenWnd                    0x5A30C0
#define CSidlScreenWnd__DrawSidlPiece                      0x5A2290
#define CSidlScreenWnd__EnableIniStorage                   0x5A1D00
#define CSidlScreenWnd__GetSidlPiece                       0x5A2450
#define CSidlScreenWnd__Init1                              0x5A3630
#define CSidlScreenWnd__LoadIniInfo                        0x5A2620
#define CSidlScreenWnd__LoadIniListWnd                     0x5A1EB0
#define CSidlScreenWnd__LoadSidlScreen                     0x5A20F0
#define CSidlScreenWnd__SetScreen                          0x5A31D0
#define CSidlScreenWnd__StoreIniInfo                       0x5A1850
#define CSidlScreenWnd__WndNotification                    0x5A21F0

// CSliderWnd
#define CSliderWnd__GetValue                               0x5BCB50
#define CSliderWnd__SetValue                               0x5BCCD0
#define CSliderWnd__UpdateThumb                            0x5BCB10

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet                         0x557CBB

// CStmlWnd
#define CStmlWnd__AppendSTML                               0x5AC260
#define CStmlWnd__CalculateHSBRange                        0x5A4A70
#define CStmlWnd__CalculateVSBRange                        0x5A4A10
#define CStmlWnd__CanBreakAtCharacter                      0x5A4BB0
#define CStmlWnd__CanGoBackward                            0x5A4C90
#define CStmlWnd__FastForwardToEndOfTag                    0x5DA260
#define CStmlWnd__GetNextChar                              0x591880
#define CStmlWnd__GetNextTagPiece                          0x5A5630
#define CStmlWnd__GetSTMLText                              0x4F6878
#define CStmlWnd__GetThisChar                              0x5D9A30
#define CStmlWnd__GetVisiableText                          0x5A6850
#define CStmlWnd__InitializeWindowVariables                0x5A89A0
#define CStmlWnd__MakeStmlColorTag                         0x5A40B0
#define CStmlWnd__MakeWndNotificationTag                   0x5A4150
#define CStmlWnd__StripFirstSTMLLines                      0x5ABFF0
#define CStmlWnd__UpdateHistoryString                      0x5A70B0

// CTabWnd
#define CTabWnd__Draw                                      0x5BC600
#define CTabWnd__DrawCurrentPage                           0x5BC0C0
#define CTabWnd__DrawTab                                   0x5BBEC0
#define CTabWnd__GetCurrentPage                            0x5BC350
#define CTabWnd__GetCurrentTabIndex                        0x5BBB80
#define CTabWnd__GetNumTabs                                0x5BBB70
#define CTabWnd__GetPageClientRect                         0x5BBB90
#define CTabWnd__GetPageFromTabIndex                       0x5BBE10
#define CTabWnd__GetPageInnerRect                          0x5BBBF0
#define CTabWnd__GetTabInnerRect                           0x5BBD90
#define CTabWnd__GetTabRect                                0x5BBCA0
#define CTabWnd__IndexInBounds                             0x5BBC80
#define CTabWnd__InsertPage                                0x5BC800
#define CTabWnd__SetPage                                   0x5BC360
#define CTabWnd__SetPageRect                               0x5BC550
#define CTabWnd__UpdatePage                                0x5BC780

// CTextOverlay
#define CTextOverlay__DisplayText                          0x40812F

// CTextureFont
#define CTextureFont__DrawWrappedText                      0x5A3C40

// CXMLDataManager
#define CXMLDataManager__GetXMLData                        0x5C3030

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead                       0x597950

// CXRect
#define CXRect__CenterPoint                                0x4DC010

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr                                       0x407D68
#define CXStr__CXStr1                                      0x53ACBC
#define CXStr__CXStr3                                      0x571DE0
#define CXStr__dCXStr                                      0x4482FB
#define CXStr__operator_equal1                             0x571FA0
#define CXStr__operator_plus_equal1                        0x572DE0

// CXWnd
#define CXWnd__BringToTop                                  0x59D040
#define CXWnd__Center                                      0x5A0440
#define CXWnd__ClrFocus                                    0x59CD90
#define CXWnd__DoAllDrawing                                0x5A1030
#define CXWnd__DrawChildren                                0x5A1160
#define CXWnd__DrawColoredRect                             0x59D2A0
#define CXWnd__DrawTooltipAtPoint                          0x5A02B0
#define CXWnd__GetBorderFrame                              0x59D750
#define CXWnd__GetChildWndAt                               0x59FEC0
#define CXWnd__GetClientClipRect                           0x59D680
#define CXWnd__GetFirstChildWnd                            0x59D0D0
#define CXWnd__GetNextChildWnd                             0x59FEA0
#define CXWnd__GetNextSib                                  0x59D0F0
#define CXWnd__GetScreenClipRect                           0x5A06D0
#define CXWnd__GetScreenRect                               0x59D920
//note: CXWnd__GetTooltipRect is wrong -- it takes two params now
#define CXWnd__GetTooltipRect                              0x59D1B0
#define CXWnd__GetWindowTextA                              0x4D22BA
//#define CXWnd__GetXMLTooltip                               0x0 <-- missing in 6/29
#define CXWnd__IsActive                                    0x59D6F0
#define CXWnd__IsDescendantOf                              0x59D700
#define CXWnd__IsReallyVisible                             0x59FE80
#define CXWnd__IsType                                      0x5A0FD0
#define CXWnd__Move                                        0x59FA30
#define CXWnd__Move1                                       0x59FAC0
#define CXWnd__ProcessTransition                           0x59D000
#define CXWnd__Refade                                      0x59CE30
#define CXWnd__Resize                                      0x5A0810
#define CXWnd__Right                                       0x5A05B0
#define CXWnd__SetFirstChildPointer                        0x59DB70
#define CXWnd__SetFocus                                    0x59EDB0
#define CXWnd__SetKeyTooltip                               0x59DBB0
#define CXWnd__SetMouseOver                                0x59DB90
#define CXWnd__SetNextSibPointer                           0x59DB80
#define CXWnd__StartFade                                   0x59D060

// CXWndManager
#define CXWndManager__DrawCursor                           0x5AF540
#define CXWndManager__DrawWindows                          0x5AF210
#define CXWndManager__GetFirstChildWnd                     0x5AEB20
#define CXWndManager__GetKeyboardFlags                     0x5ADF20
#define CXWndManager__HandleKeyboardMsg                    0x5AE3F0
#define CXWndManager__RemoveWnd                            0x5AE300

// CDBStr
#define CDBStr__GetString                                  0x4355F7

// EQ_Character
#define EQ_Character__CastSpell                            0x411F3D
#define EQ_Character__Cur_HP                               0x417E07
#define EQ_Character__GetAACastingTimeModifier             0x40E2D2
#define EQ_Character__GetCharInfo2                         0x5EC1E0
#define EQ_Character__GetFocusCastingTimeModifier          0x40D663
#define EQ_Character__Max_Endurance                        0x416A40
#define EQ_Character__Max_HP                               0x416963
#define EQ_Character__Max_Mana                             0x4BC437
#define EQ_Character__doCombatAbility                      0x4BB380

// EQ_Item
#define EQ_Item__CanDrop                                   0x4B1EC6
#define EQ_Item__GetItemLinkHash                           0x5E3810
#define EQ_Item__IsStackable                               0x5EC720

// EQ_LoadingS
#define EQ_LoadingS__WriteTextHD                           0x448376

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney                      0x4BE5E1
#define EQ_PC__GetItemTimerValue                           0x4BAC2B

// EQItemList
#define EQItemList__dEQItemList                            0x46471B
#define EQItemList__EQItemList                             0x46469F

// EQPlayer
#define EQPlayer__ChangeBoneStringSprite                   0x47A997
#define EQPlayer__dEQPlayer                                0x4849AA
#define EQPlayer__DoAttack                                 0x482973
#define EQPlayer__EQPlayer                                 0x485098
#define EQPlayer__SetNameSpriteState                       0x47CF74
#define EQPlayer__SetNameSpriteTint                        0x47AA03

// KeyPressHandler
#define KeypressHandler__AttachAltKeyToEqCommand           0x4B3737
#define KeypressHandler__AttachKeyToEqCommand              0x4B3704
#define KeypressHandler__ClearCommandStateArray            0x4B354C
#define KeypressHandler__HandleKeyDown                     0x4B23A7
#define KeypressHandler__HandleKeyUp                       0x4B261E
#define KeypressHandler__SaveKeymapping                    0x4B35D4

// MapViewMap
#define MapViewMap__Clear                                  0x5323F3
#define MapViewMap__SaveEx                                 0x532BB0

// StringTable
#define StringTable__getString                             0x5DF9C0

