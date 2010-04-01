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

#define __ClientName                                              "eqgame"
#define __ExpectedVersionDate                                     "Dec  6 2005" 
#define __ExpectedVersionTime                                     "17:08:27" 
#define __ActualVersionDate                                        0x6504AC
#define __ActualVersionTime                                        0x6504B8

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x4A9A3B
#define __MemChecker2                                              0x4CB82F
#define __MemChecker3                                              0x4CB8BC
#define __MemChecker4                                              0x601570
#define __EncryptPad0                                              0x791488
#define __EncryptPad2                                              0x793590
#define __EncryptPad3                                              0x793990
#define __EncryptPad4                                              0x79DC50

// Direct Input
#define DI8__Main                                                  0x9894DC
#define DI8__Keyboard                                              0x9894E0
#define DI8__Mouse                                                 0x9894E4

#define __AltTimerReady                                            0x924E82
#define __Attack                                                   0x9860DB
#define __BindList                                                 0x78C930
#define __Clicks                                                   0x924024
#define __CommandList                                              0x78D0F0
#define __CurrentMapLabel                                          0x99255C
#define __CurrentSocial                                            0x698D54
#define __DoAbilityAvailable                                       0x924E1C
#define __DoAbilityList                                            0x95DC28
#define __DrawHandler                                              0x99EA24
#define __EQP_IDArray                                              0x0
#define __FriendsList                                              0x95A9C8
#define __GroupCount                                               0x904780
#define __GroupLeader                                              0x9048DC
#define __Guilds                                                   0x906268
#define __gWorld                                                   0x9061D8
#define __HotkeyPage                                               0x985014
#define __HWnd                                                     0x923F20
#define __IgnoreList                                               0x95C2C8
#define __InChatMode                                               0x923F60
#define __LastTell                                                 0x926134
#define __Mouse                                                    0x9894E8
#define __MouseLook                                                0x923FF2
#define __NetStatusToggle                                          0x923FF4
#define __PCNames                                                  0x92518C
#define __RangeAttackReady                                         0x924E80
#define __RunWalkState                                             0x923F64
#define __ScreenMode                                               0x854138
#define __ScreenX                                                  0x923F28
#define __ScreenY                                                  0x923F2C
#define __ServerHost                                               0x904654
#define __ServerName                                               0x95DBE8
#define __ShowNames                                                0x925074
#define __SkillDict                                                0x854E30
#define __Socials                                                  0x95DCE8

////
//Section 1: Vital Offsets
////
#define instCRaid                                                  0x91DEB8
#define instEQZoneInfo                                             0x924190
#define instKeypressHandler                                        0x9861B0
#define pinstActiveBanker                                          0x906248
#define pinstActiveCorpse                                          0x90624C
#define pinstActiveGMaster                                         0x906250
#define pinstActiveMerchant                                        0x906244
#define pinstAltAdvManager                                         0x854E08
#define pinstBandageTarget                                         0x906230
#define pinstCamActor                                              0x8548F8
#define pinstCDBStr                                                0x853FC8
#define pinstCDisplay                                              0x906258
#define pinstCEverQuest                                            0x989650
#define pinstCharData                                              0x906218
#define pinstCharSpawn                                             0x90623C
#define pinstControlledMissile                                     0x906214
#define pinstControlledPlayer                                      0x90623C
#define pinstCSidlManager                                          0x99DC94
#define pinstCXWndManager                                          0x99DC8C
#define pinstEQItemList                                            0x9061FC
#define pinstEQSoundManager                                        0x854FC0
#define instGroup                                                  0x904780
#define pinstGroup                                                 0x9048C8
#define pinstImeManager                                            0x99DC98
#define pinstLocalPlayer                                           0x906228
#define pinstModelPlayer                                           0x906254
#define pinstPCData                                                0x906218
#define pinstSelectedItem                                          0x9923B4
#define pinstSpawnManager                                          0x9864C4
#define pinstSpellManager                                          0x98652C
#define pinstSpellSets                                             0x985018
#define pinstStringTable                                           0x9061E8
#define pinstSwitchManager                                         0x9043D0
#define pinstTarget                                                0x906240
#define pinstTargetObject                                          0x90621C
#define pinstTargetSwitch                                          0x906220
#define pinstTrackTarget                                           0x906234
#define pinstTradeTarget                                           0x906224
#define instTributeActive                                          0x853FA5
#define pinstViewActor                                             0x8548F4
#define pinstWorldData                                             0x9061F8


////
//Section 2:  UI Related Offsets
////
#define pinstCTextOverlay                                          0x79FD90
#define pinstCCharacterSelect                                      0x8547CC
#define pinstCFacePick                                             0x8547D0
#define pinstCNoteWnd                                              0x8547D4
#define pinstCHelpWnd                                              0x993148
#define pinstCBookWnd                                              0x8547D8
#define pinstCPetInfoWnd                                           0x8547DC
#define pinstCTrainWnd                                             0x8547E0
#define pinstCSkillsWnd                                            0x8547E4
#define pinstCSkillsSelectWnd                                      0x8547E8
#define pinstCCombatSkillSelectWnd                                 0x8547EC
#define pinstCFriendsWnd                                           0x8547F0
#define pinstCAAWnd                                                0x854800
#define pinstCGroupSearchFiltersWnd                                0x854804
#define pinstCLoadskinWnd                                          0x854808
#define pinstCAlarmWnd                                             0x85480C
#define pinstCMusicPlayerWnd                                       0x854810
#define pinstCRaidWnd                                              0x854820
#define pinstCRaidOptionsWnd                                       0x854824
#define pinstCBreathWnd                                            0x854828
#define pinstCMapViewWnd                                           0x85482C
#define pinstCMapToolbarWnd                                        0x854830
#define pinstCEditLabelWnd                                         0x854834
#define pinstCTargetWnd                                            0x854838
#define pinstCHotButtonWnd                                         0x992344
#define pinstCHotButtonWnd1                                        0x992344
#define pinstCHotButtonWnd2                                        0x992348
#define pinstCHotButtonWnd3                                        0x99234C
#define pinstCHotButtonWnd4                                        0x992350
#define pinstCColorPickerWnd                                       0x85483C
#define pinstCPlayerWnd                                            0x854840
#define pinstCOptionsWnd                                           0x854844
#define pinstCBuffWindowNORMAL                                     0x854848
#define pinstCBuffWindowSHORT                                      0x85484C
#define pinstCharacterCreation                                     0x854850
#define pinstCCursorAttachment                                     0x854854
#define pinstCCastingWnd                                           0x854858
#define pinstCCastSpellWnd                                         0x85485C
#define pinstCSpellBookWnd                                         0x854860
#define pinstCInventoryWnd                                         0x854864
#define pinstCBankWnd                                              0x854868
#define pinstCQuantityWnd                                          0x85486C
#define pinstCLootWnd                                              0x854870
#define pinstCActionsWnd                                           0x854874
#define pinstCCombatAbilityWnd                                     0x854878
#define pinstCMerchantWnd                                          0x85487C
#define pinstCTradeWnd                                             0x854880
#define pinstCSelectorWnd                                          0x854884
#define pinstCBazaarWnd                                            0x854888
#define pinstCBazaarSearchWnd                                      0x85488C
#define pinstCGiveWnd                                              0x854890
#define pinstCTrackingWnd                                          0x854894
#define pinstCInspectWnd                                           0x854898
#define pinstCSocialEditWnd                                        0x85489C
#define pinstCFeedbackWnd                                          0x8548A0
#define pinstCBugReportWnd                                         0x8548A4
#define pinstCVideoModesWnd                                        0x8548A8
#define pinstCTextEntryWnd                                         0x8548B0
#define pinstCFileSelectionWnd                                     0x8548B4
#define pinstCCompassWnd                                           0x8548B8
#define pinstCPlayerNotesWnd                                       0x8548BC
#define pinstCGemsGameWnd                                          0x8548C0
#define pinstCTimeLeftWnd                                          0x8548C4
#define pinstCPetitionQWnd                                         0x8548C8
#define pinstCSoulmarkWnd                                          0x8548CC
#define pinstCStoryWnd                                             0x8548D0
#define pinstCJournalTextWnd                                       0x8548D4
#define pinstCJournalCatWnd                                        0x8548D8
#define pinstCBodyTintWnd                                          0x8548DC
#define pinstCInvSlotMgr                                           0x8548E8
#define pinstCContainerMgr                                         0x8548EC
#define pinstCAdventureLeaderboardWnd                              0x991C18
#define pinstCAdventureMerchantWnd                                 0x79FD30
#define pinstCAdventureRequestWnd                                  0x991C34
#define pinstCAdventureStatsWnd                                    0x991C50
#define pinstCChatManager                                          0x992044
#define pinstCDynamicZoneWnd                                       0x992120
#define pinstCFindLocationWnd                                      0x992224
#define pinstCGroupSearchWnd                                       0x9922B8
#define pinstCGroupWnd                                             0x9922D4
#define pinstCGuildMgmtWnd                                         0x99230C
#define pinstCItemDisplayManager                                   0x9923E8
#define pinstCLeadershipWnd                                        0x992484
#define pinstCConfirmationDialog                                   0x9926A4
#define pinstCPopupWndManager                                      0x9926A4
#define pinstCSystemInfoDialogBox                                  0x993070
#define pinstCTargetOfTargetWnd                                    0x99308C
#define pinstCTipWndOFDAY                                          0x99317C
#define pinstCTipWndCONTEXT                                        0x993180
#define pinstCTradeskillWnd                                        0x9931E0
#define pinstCTributeBenefitWnd                                    0x99322C
#define pinstCTributeMasterWnd                                     0x993248
#define pinstCContextMenuManager                                   0x99DCB4


////
// Section 3: Miscellaneous Offsets
////
#define __CastRay                                                  0x4799B0
#define __ConvertItemTags                                          0x470DAF
#define __ExecuteCmd                                               0x46560E
#define __get_melee_range                                          0x469592
#define __GetGaugeValueFromEQ                                      0x558C20
#define __GetLabelFromEQ                                           0x5591DD
#define __NewUIINI                                                 0x5588CE
#define __ProcessGameEvents                                        0x49CAE3
#define __SendMessage                                              0x4841E6
#define CrashDetected                                              0x4CB4EB
#define DrawNetStatus                                              0x4ABC90
#define Util__FastTime                                             0x570F90


////
// Section 4: Function Offsets
////
// AltAdvManager
#define AltAdvManager__GetCalculatedTimer                          0x44D30C
#define AltAdvManager__IsAbilityReady                              0x44D340
#define AltAdvManager__GetAltAbility                               0x44D41A

// CBankWnd
#define CBankWnd__GetNumBankSlots                                  0x4DB659

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg                          0x4E320B

// CButtonWnd
#define CButtonWnd__SetCheck                                       0x5BACA0

// CChatManager
#define CChatManager__GetRGBAFromIndex                             0x4F1A5A
#define CChatManager__InitContextMenu                              0x4F1FBC

// CChatWindow
#define CChatWindow__CChatWindow                                   0x4F574F

// CComboWnd
#define CComboWnd__DeleteAll                                       0x59BE30
#define CComboWnd__Draw                                            0x59C020
#define CComboWnd__GetButtonRect                                   0x59BE60
#define CComboWnd__GetCurChoice                                    0x59BDF0
#define CComboWnd__GetListRect                                     0x59C2C0
#define CComboWnd__GetTextRect                                     0x59BEB0
#define CComboWnd__InsertChoice                                    0x59C320
#define CComboWnd__SetColors                                       0x59BD80
#define CComboWnd__SetChoice                                       0x59BDB0

// CContainerWnd
#define CContainerWnd__HandleCombine                               0x4FAF9F
#define CContainerWnd__vftable                                     0x656478

// CDisplay
#define CDisplay__CleanGameUI                                      0x4400C7
#define CDisplay__GetClickedActor                                  0x43DF61
#define CDisplay__GetUserDefinedColor                              0x43D62D
#define CDisplay__GetWorldFilePath                                 0x43CDCF
#define CDisplay__ReloadUI                                         0x4494CC
#define CDisplay__WriteTextHD2                                     0x441582

// CEditBaseWnd
#define CEditBaseWnd__SetMaxChars                                  0x4D6CB9
#define CEditBaseWnd__SetSel                                       0x5B9D00

// CEditWnd
#define CEditWnd__DrawCaret                                        0x5B74A0
#define CEditWnd__GetCharIndexPt                                   0x5B82A0
#define CEditWnd__GetDisplayString                                 0x5B7630
#define CEditWnd__GetHorzOffset                                    0x5B78A0
#define CEditWnd__GetLineForPrintableChar                          0x5B7D80
#define CEditWnd__GetSelStartPt                                    0x5B84E0
#define CEditWnd__GetSTMLSafeText                                  0x5B7A30
#define CEditWnd__PointFromPrintableChar                           0x5B7E90
#define CEditWnd__SelectableCharFromPoint                          0x5B8000
#define CEditWnd__SetEditable                                      0x5B7A00

// CEverQuest
#define CEverQuest__ClickedPlayer                                  0x487697
#define CEverQuest__DropHeldItemOnGround                           0x48A85E
#define CEverQuest__dsp_chat                                       0x48B1D3
#define CEverQuest__EnterZone                                      0x49B49C
#define CEverQuest__GetBodyTypeDesc                                0x485372
#define CEverQuest__GetClassDesc                                   0x484D95
#define CEverQuest__GetClassThreeLetterCode                        0x48520F
#define CEverQuest__GetDeityDesc                                   0x485697
#define CEverQuest__GetRaceDesc                                    0x485677
#define CEverQuest__InterpretCmd                                   0x48BA7C
#define CEverQuest__LeftClickedOnPlayer                            0x499D95
#define CEverQuest__RightClickedOnPlayer                           0x49A1E4
#define CEverQuest__SetGameState                                   0x487718

// CGaugeWnd
#define CGaugeWnd__CalcFillRect                                    0x503571
#define CGaugeWnd__CalcLinesFillRect                               0x5035CD
#define CGaugeWnd__Draw                                            0x5038CD

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton                                 0x513601

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot                                   0x519CA0
#define CInvSlotMgr__MoveItem                                      0x519DFB

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x51AC08

// CItemDisplayWnd
#define CItemDisplayWnd__SetItem                                   0x520D66
#define CItemDisplayWnd__SetSpell                                  0x51CE78

// CLabel
#define CLabel__Draw                                               0x5253E4

// CListWnd
#define CListWnd__AddColumn                                        0x59BB70
#define CListWnd__AddColumn1                                       0x59B6A0
#define CListWnd__AddLine                                          0x59B230
#define CListWnd__AddString                                        0x59B400
#define CListWnd__CalculateFirstVisibleLine                        0x598750
#define CListWnd__CalculateVSBRange                                0x59A290
#define CListWnd__ClearAllSel                                      0x597F90
#define CListWnd__CloseAndUpdateEditWindow                         0x598D70
#define CListWnd__Compare                                          0x5990E0
#define CListWnd__Draw                                             0x599FA0
#define CListWnd__DrawColumnSeparators                             0x599E20
#define CListWnd__DrawHeader                                       0x598160
#define CListWnd__DrawItem                                         0x5997F0
#define CListWnd__DrawLine                                         0x599B60
#define CListWnd__DrawSeparator                                    0x599EC0
#define CListWnd__EnsureVisible                                    0x5987A0
#define CListWnd__ExtendSel                                        0x599720
#define CListWnd__GetColumnFlags                                   0x597B30
#define CListWnd__GetColumnJustification                           0x597CA0
#define CListWnd__GetColumnMinWidth                                0x597C40
#define CListWnd__GetColumnWidth                                   0x597B80
#define CListWnd__GetCurSel                                        0x5975F0
#define CListWnd__GetHeaderRect                                    0x597700
#define CListWnd__GetItemAtPoint                                   0x598A80
#define CListWnd__GetItemAtPoint1                                  0x598AF0
#define CListWnd__GetItemData                                      0x5978E0
#define CListWnd__GetItemHeight                                    0x5984F0
#define CListWnd__GetItemIcon                                      0x597A70
#define CListWnd__GetItemRect                                      0x598870
#define CListWnd__GetItemText                                      0x597920
#define CListWnd__GetSelList                                       0x59B580
#define CListWnd__GetSeparatorRect                                 0x599030
#define CListWnd__IsLineEnabled                                    0x598070
#define CListWnd__RemoveLine                                       0x59B530
#define CListWnd__SetColors                                        0x597670
#define CListWnd__SetColumnJustification                           0x597CF0
#define CListWnd__SetColumnWidth                                   0x597C00
#define CListWnd__SetCurSel                                        0x597630
#define CListWnd__SetItemColor                                     0x59AE00
#define CListWnd__SetItemData                                      0x598030
#define CListWnd__SetItemText                                      0x59AD80
#define CListWnd__ShiftColumnSeparator                             0x599690
#define CListWnd__Sort                                             0x59BBA0
#define CListWnd__ToggleSel                                        0x597F00

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd                                   0x53522D

// CMerchantWnd
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x53684F
#define CMerchantWnd__RequestBuyItem                               0x5377CE
#define CMerchantWnd__RequestSellItem                              0x536A48
#define CMerchantWnd__SelectBuySellSlot                            0x537532

// CSidlManager
#define CSidlManager__FindScreenPieceTemplate1                     0x5B57E0

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateHSBRange                          0x5A10B0
#define CSidlScreenWnd__CalculateVSBRange                          0x5A0FF0
#define CSidlScreenWnd__ConvertToRes                               0x5A17F0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x5A2020
#define CSidlScreenWnd__CSidlScreenWnd1                            0x5A3290
#define CSidlScreenWnd__CSidlScreenWnd2                            0x5A3340
#define CSidlScreenWnd__dCSidlScreenWnd                            0x5A2B40
#define CSidlScreenWnd__DrawSidlPiece                              0x5A1D40
#define CSidlScreenWnd__EnableIniStorage                           0x5A17A0
#define CSidlScreenWnd__GetSidlPiece                               0x5A1F00
#define CSidlScreenWnd__Init1                                      0x5A30B0
#define CSidlScreenWnd__LoadIniInfo                                0x5A20D0
#define CSidlScreenWnd__LoadIniListWnd                             0x5A1960
#define CSidlScreenWnd__LoadSidlScreen                             0x5A1BA0
#define CSidlScreenWnd__SetScreen                                  0x5A2C50
#define CSidlScreenWnd__StoreIniInfo                               0x5A12F0
#define CSidlScreenWnd__WndNotification                            0x5A1CA0

// CSliderWnd
#define CSliderWnd__GetValue                                       0x5BC770
#define CSliderWnd__SetValue                                       0x5BC8F0
#define CSliderWnd__UpdateThumb                                    0x5BC730

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet                                 0x5570C6

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x5ABCE0
#define CStmlWnd__CalculateHSBRange                                0x5A44F0
#define CStmlWnd__CalculateVSBRange                                0x5A4490
#define CStmlWnd__CanBreakAtCharacter                              0x5A4630
#define CStmlWnd__CanGoBackward                                    0x5A4710
#define CStmlWnd__FastForwardToEndOfTag                            0x5A5180
#define CStmlWnd__GetNextChar                                      0x5A4B40
#define CStmlWnd__GetNextTagPiece                                  0x5A50A0
#define CStmlWnd__GetSTMLText                                      0x4F5731
#define CStmlWnd__GetThisChar                                      0x5D9370
#define CStmlWnd__GetVisiableText                                  0x5A62D0
#define CStmlWnd__InitializeWindowVariables                        0x5A8420
#define CStmlWnd__MakeStmlColorTag                                 0x5A3B30
#define CStmlWnd__MakeWndNotificationTag                           0x5A3BD0
#define CStmlWnd__StripFirstSTMLLines                              0x5ABA70
#define CStmlWnd__UpdateHistoryString                              0x5A6B30

// CTabWnd
#define CTabWnd__Draw                                              0x5BC220
#define CTabWnd__DrawCurrentPage                                   0x5BBC60
#define CTabWnd__DrawTab                                           0x5BBA60
#define CTabWnd__GetCurrentPage                                    0x5BBF70
#define CTabWnd__GetCurrentTabIndex                                0x5BB720
#define CTabWnd__GetNumTabs                                        0x5BB710
#define CTabWnd__GetPageClientRect                                 0x5BB730
#define CTabWnd__GetPageFromTabIndex                               0x5BB9B0
#define CTabWnd__GetPageInnerRect                                  0x5BB790
#define CTabWnd__GetTabInnerRect                                   0x5BB930
#define CTabWnd__GetTabRect                                        0x5BB840
#define CTabWnd__IndexInBounds                                     0x5BB820
#define CTabWnd__InsertPage                                        0x5BC420
#define CTabWnd__SetPage                                           0x5BBF80
#define CTabWnd__SetPageRect                                       0x5BC170
#define CTabWnd__UpdatePage                                        0x5BC3A0

// CTextOverlay
#define CTextOverlay__DisplayText                                  0x40CE0F

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x5A36C0

// CXMLDataManager
#define CXMLDataManager__GetXMLData                                0x5C2AB0

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead                               0x5973A0

// CXRect
#define CXRect__CenterPoint                                        0x4DAE59

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr                                               0x40CA48
#define CXStr__CXStr1                                              0x4060FC
#define CXStr__CXStr3                                              0x572570
#define CXStr__dCXStr                                              0x44DA15
#define CXStr__operator_equal1                                     0x572730
#define CXStr__operator_plus_equal1                                0x573570

// CXWnd
#define CXWnd__BringToTop                                          0x59CAD0
#define CXWnd__Center                                              0x59FEE0
#define CXWnd__ClrFocus                                            0x59C820
#define CXWnd__DoAllDrawing                                        0x5A0AD0
#define CXWnd__DrawChildren                                        0x5A0C00
#define CXWnd__DrawColoredRect                                     0x59CD40
#define CXWnd__DrawTooltipAtPoint                                  0x59FD50
#define CXWnd__GetBorderFrame                                      0x59D1F0
#define CXWnd__GetChildWndAt                                       0x59F960
#define CXWnd__GetClientClipRect                                   0x59D120
#define CXWnd__GetFirstChildWnd                                    0x59CB60
#define CXWnd__GetNextChildWnd                                     0x59F940
#define CXWnd__GetNextSib                                          0x59CB80
#define CXWnd__GetScreenClipRect                                   0x5A0170
#define CXWnd__GetScreenRect                                       0x59D3C0
#define CXWnd__GetTooltipRect                                      0x59CF90
#define CXWnd__GetWindowTextA                                      0x4D10E0
#define CXWnd__IsActive                                            0x59D190
#define CXWnd__IsDescendantOf                                      0x59D1A0
#define CXWnd__IsReallyVisible                                     0x59F920
#define CXWnd__IsType                                              0x5A0A70
#define CXWnd__Move                                                0x59F4D0
#define CXWnd__Move1                                               0x59F560
#define CXWnd__ProcessTransition                                   0x59CA90
#define CXWnd__Refade                                              0x59C8C0
#define CXWnd__Resize                                              0x5A02B0
#define CXWnd__Right                                               0x5A0050
#define CXWnd__SetFirstChildPointer                                0x59D610
#define CXWnd__SetFocus                                            0x59E850
#define CXWnd__SetKeyTooltip                                       0x59D650
#define CXWnd__SetMouseOver                                        0x59D630
#define CXWnd__SetNextSibPointer                                   0x59D620
#define CXWnd__StartFade                                           0x59CAF0

// CXWndManager
#define CXWndManager__DrawCursor                                   0x5AEF50
#define CXWndManager__DrawWindows                                  0x5AEC20
#define CXWndManager__GetFirstChildWnd                             0x5AE5B0
#define CXWndManager__GetKeyboardFlags                             0x5AD9B0
#define CXWndManager__HandleKeyboardMsg                            0x5ADE80
#define CXWndManager__RemoveWnd                                    0x5ADD90

// CDBStr
#define CDBStr__GetString                                          0x43AB54

// EQ_Character
#define EQ_Character__CastSpell                                    0x416B88
#define EQ_Character__Cur_HP                                       0x41C710
#define EQ_Character__GetAACastingTimeModifier                     0x412EE8
#define EQ_Character__GetCharInfo2                                 0x5EBBC0
#define EQ_Character__GetFocusCastingTimeModifier                  0x4123DD
#define EQ_Character__Max_Endurance                                0x41B508
#define EQ_Character__Max_HP                                       0x41B421
#define EQ_Character__Max_Mana                                     0x4AF939
#define EQ_Character__doCombatAbility                              0x4AE884

// EQ_Item
#define EQ_Item__CanDrop                                           0x4A4D68
#define EQ_Item__GetItemLinkHash                                   0x5E3170
#define EQ_Item__IsStackable                                       0x5EC110

// EQ_LoadingS
#define EQ_LoadingS__WriteTextHD                                   0x44DA8B

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney                              0x4B1AE2
#define EQ_PC__GetAltAbilityIndex                                  0x5F0190
#define EQ_PC__GetCombatAbility                                    0x5F0280
#define EQ_PC__GetCombatAbilityTimer                               0x5F0330
#define EQ_PC__GetItemTimerValue                                   0x4AE105

// EQItemList
#define EQItemList__dEQItemList                                    0x46837D
#define EQItemList__EQItemList                                     0x468301

// EQPlayer
#define EQPlayer__ChangeBoneStringSprite                           0x4B5BFE
#define EQPlayer__dEQPlayer                                        0x4B8791
#define EQPlayer__DoAttack                                         0x4C1507
#define EQPlayer__EQPlayer                                         0x4BA65B
#define EQPlayer__SetNameSpriteState                               0x4B744B
#define EQPlayer__SetNameSpriteTint                                0x4B5C66

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x4BB263

// KeyPressHandler
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4A65D9
#define KeypressHandler__AttachKeyToEqCommand                      0x4A65A6
#define KeypressHandler__ClearCommandStateArray                    0x4A63EE
#define KeypressHandler__HandleKeyDown                             0x4A5249
#define KeypressHandler__HandleKeyUp                               0x4A54C0
#define KeypressHandler__SaveKeymapping                            0x4A6476

// MapViewMap
#define MapViewMap__Clear                                          0x531993
#define MapViewMap__SaveEx                                         0x532150

// StringTable
#define StringTable__getString                                     0x5DF300
