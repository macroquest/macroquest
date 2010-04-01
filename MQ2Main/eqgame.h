/******************************************************************************
    MQ2Main.dll: MacroQuest2's extension DLL for EverQuest
    Copyright (C) 2002-2003 Plazmic, 2003-2005 Lax

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License, version 2, as
published by
    the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
******************************************************************************/
#ifdef PRIVATE
#include "eqgame-private.h"
#endif

#define __ClientName                                       "eqgame"
#define __ExpectedVersionDate                              "Apr 11 2005"
#define __ExpectedVersionTime                              "14:42:23"
#define __ActualVersionDate                                0x614CC4
#define __ActualVersionTime                                0x614CD0

#define __ClientOverride                                   0
#define __MacroQuestWinClassName                           "__MacroQuestTray"
#define __MacroQuestWinName                                "MacroQuest"

// Memory Protection
#define __MemChecker0                                      0x50CD6D
#define __MemChecker2                                      0x54AD2B
#define __MemChecker3                                      0x54ADB8
#define __MemChecker4                                      0x5C6EB0
#define __EncryptPad0                                      0x737208
#define __EncryptPad2                                      0x73A930
#define __EncryptPad3                                      0x73AD30
#define __EncryptPad4                                      0x73F6F0

// Direct Input
#define DI8__Main                                          0x93764C
#define DI8__Keyboard                                      0x937650
#define DI8__Mouse                                         0x937654

#define __AltTimerReady                                    0x8A9EEE
#define __Attack                                           0x909A00
#define __BindList                                         0x63EE30
#define __Clicks                                           0x8A90FC
#define __CommandList                                      0x63F3D0
#define __CurrentMapLabel                                  0x92998C
#define __CurrentSocial                                    0x642840
#define __DoAbilityAvailable                               0x8A9E88
#define __DoAbilityList                                    0x8E2C58
#define __DrawHandler                                      0x941694
#define __EQP_IDArray                                      0x7F72B0
#define __FriendsList                                      0x8DFA18
#define __Guilds                                           0x9117D8
#define __gWorld                                           0x90B7E8
#define __HotkeyPage                                       0x9095B8
#define __HWnd                                             0x8A8FF8
#define __IgnoreList                                       0x8E1318
#define __InChatMode                                       0x8A9038
#define __LastTell                                         0x8AB184
#define __Mouse                                            0x937658
#define __MouseLook                                        0x8A90CA
#define __NetStatusToggle                                  0x8A90CC
#define __PCNames                                          0x8AA184
#define __RangeAttackReady                                 0x8A9EEC
#define __RunWalkState                                     0x8A903C
#define __ScreenMode                                       0x7F4E30
#define __ScreenX                                          0x8A9000
#define __ScreenY                                          0x8A9004
#define __ServerHost                                       0x909C4C
#define __ServerName                                       0x8E2C18
#define __ShowNames                                        0x8AA0D4
#define __SkillDict                                        0x7FA640
#define __Socials                                          0x8E2D18

////
//Section 1: Vital Offsets
////
#define instCRaid                                          0x90B880
#define instEQZoneInfo                                     0x8A9268
#define instKeypressHandler                                0x92963C
#define pinstActiveBanker                                  0x90B860
#define pinstActiveCorpse                                  0x90B864
#define pinstActiveGMaster                                 0x90B868
#define pinstActiveMerchant                                0x90B85C
#define pinstAltAdvManager                                 0x7FA1E8
#define pinstCCursorAttachment                             0x7F594C
#define pinstCDisplay                                      0x90B870
#define pinstCEverQuest                                    0x9377C0
#define pinstCharData                                      0x90B84C
#define pinstCharSpawn                                     0x90B844
#define pinstControlledPlayer                              0x90B844
#define pinstCSidlManager                                  0x940A9C
#define pinstCXWndManager                                  0x940A94
#define pinstEQItemList                                    0x90B810
#define instGroup                                          0x909D90
#define pinstLocalPlayer                                   0x90B830
#define pinstPCData                                        0x90B84C
#define pinstSelectedItem                                  0x9295BC
#define pinstSpawnList                                     0x90B80C
#define pinstSpellManager                                  0x929CE8
#define pinstSpellSets                                     0x9095BC
#define pinstStringTable                                   0x90B7F8
#define pinstSwitchManager                                 0x7FA1E4
#define pinstTarget                                        0x90B850
#define pinstTargetSwitch                                  0x90B858
#define pinstTradeTarget                                   0x90B82C
#define pinstWorldData                                     0x90B808


////
//Section 2:  UI Related Offsets
////
#define pinstCBarterMerchantWnd							   0x7411AC
#define pinstCBarterSearchWnd							   0x7411C8
#define pinstCBarterWnd									   0x7411E4
#define pinstCTextOverlay                                  0x741300
#define pinstCharacterSelect                               0x7F58C4
#define pinstCFacePick                                     0x7F58C8
#define pinstCNoteWnd                                      0x7F58CC
#define pinstCHelpWnd                                      0x7F58D0
#define pinstCBookWnd                                      0x7F58D4
#define pinstCPetInfoWnd                                   0x7F58D8
#define pinstCTrainWnd                                     0x7F58DC
#define pinstCSkillsWnd                                    0x7F58E0
#define pinstCSkillsSelectWnd                              0x7F58E4
#define pinstCCombatSkillSelectWnd                         0x7F58E8
#define pinstCFriendsWnd                                   0x7F58EC
#define pinstCAAWnd                                        0x7F58F8
#define pinstCGroupSearchFiltersWnd                        0x7F58FC
#define pinstCLoadskinWnd                                  0x7F5900
#define pinstCAlarmWnd                                     0x7F5904
#define pinstCMusicPlayerWnd                               0x7F5908
#define pinstCMailWnd									   0x7F590C
#define pinstCMailCompositionWnd						   0x7F5910
#define pinstCRaidWnd                                      0x7F5914
#define pinstCRaidOptionsWnd                               0x7F5918
#define pinstCBreathWnd                                    0x7F591C
#define pinstCMapViewWnd                                   0x7F5920
#define pinstCMapToolbarWnd                                0x7F5924
#define pinstCEditLabelWnd                                 0x7F5928
#define pinstCTargetWnd                                    0x7F592C
#define pinstCHotButtonWnd                                 0x7F5930
#define pinstCColorPickerWnd                               0x7F5934
#define pinstCPlayerWnd                                    0x7F5938
#define pinstCOptionsWnd                                   0x7F593C
#define pinstCBuffWindowNORMAL                             0x7F5940
#define pinstCBuffWindowSHORT                              0x7F5944
#define pinstCharacterCreation                             0x7F5948
#define pinstCCursorAttachment                             0x7F594C
#define pinstCCastingWnd                                   0x7F5950
#define pinstCCastSpellWnd                                 0x7F5954
#define pinstCSpellBookWnd                                 0x7F5958
#define pinstCInventoryWnd                                 0x7F595C
#define pinstCBankWnd                                      0x7F5960
#define pinstCQuantityWnd                                  0x7F5964
#define pinstCLootWnd                                      0x7F5968
#define pinstCActionsWnd                                   0x7F596C
#define pinstCCombatAbilityWnd                             0x7F5970
#define pinstCMerchantWnd                                  0x7F5974
#define pinstCTradeWnd                                     0x7F5978
#define pinstCSelectorWnd                                  0x7F597C
#define pinstCBazaarWnd                                    0x7F5980
#define pinstCBazaarSearchWnd                              0x7F5984
#define pinstCGiveWnd                                      0x7F5988
#define pinstCTrackingWnd                                  0x7F598C
#define pinstCInspectWnd                                   0x7F5990
#define pinstCSocialEditWnd                                0x7F5994
#define pinstCFeedbackWnd                                  0x7F5998
#define pinstCBugReportWnd                                 0x7F599C
#define pinstCVideoModesWnd                                0x7F59A0
#define pinstCTextEntryWnd                                 0x7F59A8
#define pinstCFileSelectionWnd                             0x7F59AC
#define pinstCCompassWnd                                   0x7F59B0
#define pinstCPlayerNotesWnd                               0x7F59B4
#define pinstCGemsGameWnd                                  0x7F59B8
#define pinstCTimeLeftWnd                                  0x7F59BC
#define pinstCPetitionQWnd                                 0x7F59C0
#define pinstCSoulmarkWnd                                  0x7F59C4
#define pinstCStoryWnd                                     0x7F59C8
#define pinstCJournalTextWnd                               0x7F59CC
#define pinstCJournalCatWnd                                0x7F59D0
#define pinstCBodyTintWnd                                  0x7F59D4
#define pinstCInvSlotMgr                                   0x7F59DC
#define pinstCContainerMgr                                 0x7F59E0
#define pinstCAdventureLeaderboardWnd                      0x740FAC
#define pinstCAdventureMerchantWnd                         0x740FC8
#define pinstCAdventureRequestWnd                          0x740FE4
#define pinstCAdventureStatsWnd                            0x741000
#define pinstCChatManager                                  0x742A04
#define pinstCDynamicZoneWnd                               0x7F5AEC
#define pinstCFindLocationWnd                              0x9293C0
#define pinstCGroupSearchWnd                               0x9294B8
#define pinstCGroupWnd                                     0x9294D4
#define pinstCGuildBankWnd								   0x9294F0
#define pinstCGuildMgmtWnd                                 0x92950C
#define pinstCGuildTributeMasterWnd						   0x929528
#define pinstCItemDisplayManager                           0x9295F0
#define pinstCLeadershipWnd                                0x9296D8
#define pinstCLFGuildWnd								   0x9296F4
#define pinstCPointMerchantWnd							   0x929AC4
#define pinstCPopupWndManager                              0x929AE0
#define pinstCPvpLeaderboardWnd							   0x929B1C
#define pinstCPvpStatsWnd								   0x929B54
#define pinstCLargeDialogWnd							   0x929C00
#define pinstCSystemInfoDialogBox                          0x92A490
#define pinstCTargetOfTargetWnd                            0x92A4B4
#define pinstCTaskSelectWnd								   0x92A4E8
#define pinstCTaskWnd									   0x92A504
#define pinstCTicketCommentWnd							   0x92A538
#define pinstCTicketWnd									   0x92A570
#define pinstCTipWndOFDAY                                  0x92A5A4
#define pinstCTipWndCONTEXT                                0x92A5A8
#define pinstCTitleWnd									   0x92A5DC
#define pinstCTradeskillWnd                                0x92A6A0
#define pinstCTributeBenefitWnd                            0x92A6EC
#define pinstCTributeMasterWnd                             0x92A708
#define pinstCVoiceMacroWnd								   0x934764
#define pinstCContextMenuManager                           0x940AF4
// unknown window added 4-14 exe 0x79A234


////
// Section 3: Miscellaneous Offsets
////
#define __CastRay                                          0x46E84B
#define __ConvertItemTags                                  0x46E052
#define __ExecuteCmd                                       0x460A10
#define __get_melee_range                                  0x464D7D
#define __GetLabelFromEQ                                   0x533E8D
#define __GetGaugeValueFromEQ                              0x5333C5
#define __LoadSplashScreen                                 0x5CDEE0
#define __NewUIINI                                         0x533C9D
#define __ProcessGameEvents                                0x4D0158
#define __SendMessage                                      0x4B6F7C
#define CrashDetected                                      0x54A9E7
#define DrawNetStatus                                      0x51145F


////
// Section 4: Function Offsets
////
// AltAdvManager
#define AltAdvManager__GetCalculatedTimer                  0x492BEC
#define AltAdvManager__IsAbilityReady                      0x492C1A

// CBankWnd
#define CBankWnd__GetNumBankSlots                          0x40BB68

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg                  0x41321D

// CButtonWnd
#define CButtonWnd__SetCheck                               0x58E420

// CChatManager
#define CChatManager__GetRGBAFromIndex                     0x4243D2
#define CChatManager__InitContextMenu                      0x4244B6

// CChatWindow
#define CChatWindow__CChatWindow                           0x4274A7

// CComboWnd
#define CComboWnd__DeleteAll                               0x58F0D0
#define CComboWnd__Draw                                    0x58F2D0
#define CComboWnd__GetButtonRect                           0x58F100
#define CComboWnd__GetCurChoice                            0x58F090
#define CComboWnd__GetListRect                             0x58F6C0
#define CComboWnd__GetTextRect                             0x58F160
#define CComboWnd__InsertChoice                            0x58F720
#define CComboWnd__SetColors                               0x58F020
#define CComboWnd__SetChoice                               0x58F050

// CContainerWnd
#define CContainerWnd__HandleCombine                       0x433EFF
#define CContainerWnd__vftable                             0x5FC4D8

// CDisplay
#define CDisplay__CleanGameUI                              0x44360B
#define CDisplay__GetClickedActor                          0x44026D
#define CDisplay__GetUserDefinedColor                      0x43F7D1
#define CDisplay__GetWorldFilePath                         0x43EFA5
#define CDisplay__ReloadUI                                 0x44B05F
#define CDisplay__WriteTextHD2                             0x4442AB

// CEditBaseWnd
#define CEditBaseWnd__SetMaxChars                          0x408113
#define CEditBaseWnd__SetSel                               0x5A0100

// CEditWnd
#define CEditWnd__DrawCaret                                0x59C1E0
#define CEditWnd__GetCharIndexPt                           0x59D030
#define CEditWnd__GetDisplayString                         0x59C340
#define CEditWnd__GetHorzOffset                            0x59C5B0
#define CEditWnd__GetLineForPrintableChar                  0x59CAD0
#define CEditWnd__GetSelStartPt                            0x59D270
#define CEditWnd__GetSTMLSafeText                          0x59C790
#define CEditWnd__PointFromPrintableChar                   0x59CBE0
#define CEditWnd__SelectableCharFromPoint                  0x59CD60
#define CEditWnd__SetEditable                              0x59C760

// CEverQuest
#define CEverQuest__ClickedPlayer                          0x4BC3CF
#define CEverQuest__DropHeldItemOnGround                   0x4C3436
#define CEverQuest__dsp_chat                               0x4BE465
#define CEverQuest__EnterZone                              0x4CEC59
#define CEverQuest__GetBodyTypeDesc                        0x4B80F4
#define CEverQuest__GetClassDesc                           0x4B7B17
#define CEverQuest__GetClassThreeLetterCode                0x4B7F91
#define CEverQuest__GetDeityDesc                           0x4B9B87
#define CEverQuest__GetRaceDesc                            0x4B83F9
#define CEverQuest__InterpretCmd                           0x4C8972
#define CEverQuest__LeftClickedOnPlayer                    0x4CD5B1
#define CEverQuest__RightClickedOnPlayer                   0x4CD9E7
#define CEverQuest__SetGameState                           0x4BC440

// CGaugeWnd
#define CGaugeWnd__CalcFillRect                            0x4DB9F5
#define CGaugeWnd__CalcLinesFillRect                       0x4DBA51
#define CGaugeWnd__Draw                                    0x4DBD51

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton                         0x4EBEB3

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot                           0x4EF6E5
#define CInvSlotMgr__MoveItem                              0x4EF813

// CItemDisplayWnd
#define CItemDisplayWnd__SetItem                           0x4F48C8
#define CItemDisplayWnd__SetSpell                          0x4F390F

// CLabel
#define CLabel__Draw                                       0x4FBED5

// CListWnd
#define CListWnd__AddColumn                                0x578700
#define CListWnd__AddColumn1                               0x578270
#define CListWnd__AddLine                                  0x577DE0
#define CListWnd__AddString                                0x577FB0
#define CListWnd__CalculateFirstVisibleLine                0x575210
#define CListWnd__CalculateVSBRange                        0x576EB0
#define CListWnd__ClearAllSel                              0x574980
#define CListWnd__CloseAndUpdateEditWindow                 0x575850
#define CListWnd__Compare                                  0x575BC0
#define CListWnd__Draw                                     0x576B00
#define CListWnd__DrawColumnSeparators                     0x619888
#define CListWnd__DrawHeader                               0x574B90
#define CListWnd__DrawItem                                 0x5762D0
#define CListWnd__DrawLine                                 0x576660
#define CListWnd__DrawSeparator                            0x5769F0
#define CListWnd__EnsureVisible                            0x575260
#define CListWnd__ExtendSel                                0x576200
#define CListWnd__GetColumnFlags                           0x574520
#define CListWnd__GetColumnJustification                   0x574690
#define CListWnd__GetColumnMinWidth                        0x574630
#define CListWnd__GetColumnWidth                           0x574570
#define CListWnd__GetCurSel                                0x5740E0
#define CListWnd__GetHeaderRect                            0x5741D0
#define CListWnd__GetItemAtPoint                           0x575540
#define CListWnd__GetItemAtPoint1                          0x5755B0
#define CListWnd__GetItemData                              0x5743A0
#define CListWnd__GetItemHeight                            0x574F90
#define CListWnd__GetItemIcon                              0x574460
#define CListWnd__GetItemRect                              0x575330
#define CListWnd__GetItemText                              0x5743E0
#define CListWnd__GetSelList                               0x578150
#define CListWnd__GetSeparatorRect                         0x575B10
#define CListWnd__IsLineEnabled                            0x574A60
#define CListWnd__RemoveLine                               0x578100
#define CListWnd__SetColors                                0x574140
#define CListWnd__SetColumnJustification                   0x5746E0
#define CListWnd__SetColumnWidth                           0x5745F0
#define CListWnd__SetCurSel                                0x574120
#define CListWnd__SetItemColor                             0x577A10
#define CListWnd__SetItemData                              0x574A20
#define CListWnd__SetItemText                              0x577950
#define CListWnd__ShiftColumnSeparator                     0x576170
#define CListWnd__Sort                                     0x5787A0
#define CListWnd__ToggleSel                                0x5748F0

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd                           0x50BD4E

// CMerchantWnd
#define CMerchantWnd__DisplayBuyOrSellPrice                0x50D250
#define CMerchantWnd__RequestBuyItem                       0x50DC3D
#define CMerchantWnd__RequestSellItem                      0x50D584
#define CMerchantWnd__SelectBuySellSlot                    0x50DABD

// CSidlManager
#define CSidlManager__FindScreenPieceTemplate1             0x59A1E0

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateHSBRange                  0x56C540
#define CSidlScreenWnd__CalculateVSBRange                  0x56C480
#define CSidlScreenWnd__ConvertToRes                       0x56CC30
#define CSidlScreenWnd__CreateChildrenFromSidl             0x56D510
#define CSidlScreenWnd__CSidlScreenWnd1                    0x56EAB0
#define CSidlScreenWnd__CSidlScreenWnd2                    0x56EBA0
#define CSidlScreenWnd__dCSidlScreenWnd                    0x56E0F0
#define CSidlScreenWnd__DrawSidlPiece                      0x56D130
#define CSidlScreenWnd__EnableIniStorage                   0x56CBE0
#define CSidlScreenWnd__GetSidlPiece                       0x56D3D0
#define CSidlScreenWnd__Init1                              0x56E800
#define CSidlScreenWnd__LoadIniInfo                        0x56D5C0
#define CSidlScreenWnd__LoadIniListWnd                     0x56CD70
#define CSidlScreenWnd__LoadSidlScreen                     0x56CF70
#define CSidlScreenWnd__SetScreen                          0x56E200
#define CSidlScreenWnd__StoreIniInfo                       0x56C770
#define CSidlScreenWnd__WndNotification                    0x56D090

// CSliderWnd
#define CSliderWnd__GetValue                               0x58FB00
#define CSliderWnd__SetValue                               0x58FCD0
#define CSliderWnd__UpdateThumb                            0x58FAC0

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet                         0x53141F

// CStmlWnd
#define CStmlWnd__AppendSTML                               0x581B30
#define CStmlWnd__CalculateHSBRange                        0x5795D0
#define CStmlWnd__CalculateVSBRange                        0x579570
#define CStmlWnd__CanBreakAtCharacter                      0x579710
#define CStmlWnd__CanGoBackward                            0x579790
#define CStmlWnd__FastForwardToEndOfTag                    0x57A480
#define CStmlWnd__GetNextChar                              0x579BC0
#define CStmlWnd__GetNextTagPiece                          0x57A280
#define CStmlWnd__GetSTMLText                              0x427489
#define CStmlWnd__GetThisChar                              0x579410
#define CStmlWnd__GetVisiableText                          0x57BC40
#define CStmlWnd__InitializeWindowVariables                0x57D9B0
#define CStmlWnd__MakeStmlColorTag                         0x578AE0
#define CStmlWnd__MakeWndNotificationTag                   0x578B80
#define CStmlWnd__StripFirstSTMLLines                      0x5818C0
#define CStmlWnd__UpdateHistoryString                      0x57C090

// CTabWnd
#define CTabWnd__Draw                                      0x585720
#define CTabWnd__DrawCurrentPage                           0x584FF0
#define CTabWnd__DrawTab                                   0x584D70
#define CTabWnd__GetCurrentPage                            0x585490
#define CTabWnd__GetCurrentTabIndex                        0x5849D0
#define CTabWnd__GetNumTabs                                0x5849C0
#define CTabWnd__GetPageClientRect                         0x5849E0
#define CTabWnd__GetPageFromTabIndex                       0x584CC0
#define CTabWnd__GetPageInnerRect                          0x584A40
#define CTabWnd__GetTabInnerRect                           0x584C20
#define CTabWnd__GetTabRect                                0x584B20
#define CTabWnd__IndexInBounds                             0x584B00
#define CTabWnd__InsertPage                                0x585860
#define CTabWnd__SetPage                                   0x5854A0
#define CTabWnd__SetPageRect                               0x585670
#define CTabWnd__UpdatePage                                0x5857D0

// CTextOverlay
#define CTextOverlay__DisplayText                          0x4177E6

// CTextureFont
#define CTextureFont__DrawWrappedText                      0x573C70

// CXMLDataManager
#define CXMLDataManager__GetXMLData                        0x5A0D90

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead                       0x58D180

// CXRect
#define CXRect__CenterPoint                                0x40B3CB

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr                                       0x401000
#define CXStr__CXStr1                                      0x511BFA
#define CXStr__CXStr3                                      0x54E720
#define CXStr__dCXStr                                      0x40102A
#define CXStr__operator_equal1                             0x54E8E0
#define CXStr__operator_plus_equal1                        0x54F720

// CXWnd
#define CXWnd__BringToTop                                  0x56F260
#define CXWnd__Center                                      0x5728C0
#define CXWnd__ClrFocus                                    0x56EFA0
#define CXWnd__DoAllDrawing                                0x5734D0
#define CXWnd__DrawChildren                                0x573600
#define CXWnd__DrawColoredRect                             0x56F480
#define CXWnd__DrawTooltipAtPoint                          0x5726F0
#define CXWnd__GetBorderFrame                              0x56F8D0
#define CXWnd__GetChildWndAt                               0x572280
#define CXWnd__GetClientClipRect                           0x56F810
#define CXWnd__GetFirstChildWnd                            0x56F2F0
#define CXWnd__GetNextChildWnd                             0x572260
#define CXWnd__GetNextSib                                  0x56F310
#define CXWnd__GetScreenClipRect                           0x572B50
#define CXWnd__GetScreenRect                               0x56FAA0
#define CXWnd__GetTooltipRect                              0x572640
#define CXWnd__GetWindowTextA                              0x402A96
#define CXWnd__GetXMLTooltip                               0x56EDE0
#define CXWnd__IsActive                                    0x56F880
#define CXWnd__IsDescendantOf                              0x56F890
#define CXWnd__IsReallyVisible                             0x572240
#define CXWnd__IsType                                      0x573470
#define CXWnd__Move                                        0x571DF0
#define CXWnd__Move1                                       0x571E80
#define CXWnd__ProcessTransition                           0x56F220
#define CXWnd__Refade                                      0x56F050
#define CXWnd__Resize                                      0x572C90
#define CXWnd__Right                                       0x572A30
#define CXWnd__SetFirstChildPointer                        0x56FCF0
#define CXWnd__SetFocus                                    0x570FD0
#define CXWnd__SetKeyTooltip                               0x56FD30
#define CXWnd__SetMouseOver                                0x56FD10
#define CXWnd__SetNextSibPointer                           0x56FD00
#define CXWnd__StartFade                                   0x56F280

// CXWndManager
#define CXWndManager__DrawCursor                           0x591E10
#define CXWndManager__DrawWindows                          0x591A60
#define CXWndManager__GetFirstChildWnd                     0x591360
#define CXWndManager__GetKeyboardFlags                     0x590800
#define CXWndManager__HandleKeyboardMsg                    0x590CD0
#define CXWndManager__RemoveWnd                            0x590BE0

// EQ_Character
#define EQ_Character__CastSpell                            0x4A3993
#define EQ_Character__Cur_HP                               0x496C7E
#define EQ_Character__GetAACastingTimeModifier             0x49FA41
#define EQ_Character__GetFocusCastingTimeModifier          0x49F5E8
#define EQ_Character__Max_Endurance                        0x493765
#define EQ_Character__Max_HP                               0x493512
#define EQ_Character__Max_Mana                             0x4ACCA3

// EQ_Item
#define EQ_Item__CanDrop                                   0x4AA2F6
#define EQ_Item__GetItemLinkHash                           0x4A9EE8
#define EQ_Item__IsStackable                               0x4AA49A

// EQ_LoadingS
#define EQ_LoadingS__WriteTextHD                           0x4AA9FD

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney                      0x4AF327

// EQItemList
#define EQItemList__dEQItemList                            0x463594
#define EQItemList__EQItemList                             0x463518

// EQPlayer
#define EQPlayer__ChangeBoneStringSprite                   0x47A112
#define EQPlayer__dEQPlayer                                0x4834D2
#define EQPlayer__DoAttack                                 0x48152C
#define EQPlayer__EQPlayer                                 0x483AC2
#define EQPlayer__SetNameSpriteState                       0x47CAA1
#define EQPlayer__SetNameSpriteTint                        0x47A17E

// KeyPressHandler
#define KeypressHandler__AttachAltKeyToEqCommand           0x4FBD40
#define KeypressHandler__AttachKeyToEqCommand              0x4FBD0D
#define KeypressHandler__ClearCommandStateArray            0x4FBB58
#define KeypressHandler__HandleKeyDown                     0x4FA9B3
#define KeypressHandler__HandleKeyUp                       0x4FAC2A
#define KeypressHandler__SaveKeymapping                    0x4FBBDD

// MapViewMap
#define MapViewMap__Clear                                  0x508B43
#define MapViewMap__SaveEx                                 0x5092DE

// StringTable
#define StringTable__getString                             0x5BD6B0
