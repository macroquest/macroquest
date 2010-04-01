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
#define __ExpectedVersionDate                                     "Dec 14 2005" 
#define __ExpectedVersionTime                                     "18:09:20" 
#define __ActualVersionDate                                        0x651524
#define __ActualVersionTime                                        0x651530

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x4A9F9A
#define __MemChecker2                                              0x4CBD99
#define __MemChecker3                                              0x4CBE26
#define __MemChecker4                                              0x602440
#define __EncryptPad0                                              0x793488
#define __EncryptPad2                                              0x795590
#define __EncryptPad3                                              0x795990
#define __EncryptPad4                                              0x79FC50

// Direct Input
#define DI8__Main                                                  0x98B4DC
#define DI8__Keyboard                                              0x98B4E0
#define DI8__Mouse                                                 0x98B4E4

#define __AltTimerReady                                            0x926E82
#define __Attack                                                   0x9880DB
#define __BindList                                                 0x78E930
#define __Clicks                                                   0x926024
#define __CommandList                                              0x78F0F0
#define __CurrentMapLabel                                          0x99455C
#define __CurrentSocial                                            0x69AD54
#define __DoAbilityAvailable                                       0x926E1C
#define __DoAbilityList                                            0x95FC28
#define __DrawHandler                                              0x9A0A24
//#define __EQP_IDArray                                              0x0
#define __FriendsList                                              0x95C9C8
#define __GroupCount                                               0x906780
#define __GroupLeader                                              0x9068DC
#define __Guilds                                                   0x908268
#define __gWorld                                                   0x9081D8
#define __HotkeyPage                                               0x987014
#define __HWnd                                                     0x925F20
#define __IgnoreList                                               0x95E2C8
#define __InChatMode                                               0x925F60
#define __LastTell                                                 0x928134
#define __Mouse                                                    0x98B4E8
#define __MouseLook                                                0x925FF2
#define __NetStatusToggle                                          0x925FF4
#define __PCNames                                                  0x92718C
#define __RangeAttackReady                                         0x926E80
#define __RunWalkState                                             0x925F64
#define __ScreenMode                                               0x856138
#define __ScreenX                                                  0x925F28
#define __ScreenY                                                  0x925F2C
#define __ServerHost                                               0x906654
#define __ServerName                                               0x95FBE8
#define __ShowNames                                                0x927074
#define __SkillDict                                                0x856E30
#define __Socials                                                  0x95FCE8

////
//Section 1: Vital Offsets
////
#define instCRaid                                                  0x91FEB8
#define instEQZoneInfo                                             0x926190
#define instKeypressHandler                                        0x9881B0
#define pinstActiveBanker                                          0x908248
#define pinstActiveCorpse                                          0x90824C
#define pinstActiveGMaster                                         0x908250
#define pinstActiveMerchant                                        0x908244
#define pinstAltAdvManager                                         0x856E08
#define pinstBandageTarget                                         0x908230
#define pinstCamActor                                              0x8568F8
#define pinstCDBStr                                                0x855FC8
#define pinstCDisplay                                              0x908258
#define pinstCEverQuest                                            0x98B650
#define pinstCharData                                              0x908218
#define pinstCharSpawn                                             0x90823C
#define pinstControlledMissile                                     0x908214
#define pinstControlledPlayer                                      0x90823C
#define pinstCSidlManager                                          0x99FC94
#define pinstCXWndManager                                          0x99FC8C
#define pinstEQItemList                                            0x9081FC
#define pinstEQSoundManager                                        0x856FC0
#define instGroup                                                  0x906780
#define pinstGroup                                                 0x9068C8
#define pinstImeManager                                            0x99FC98
#define pinstLocalPlayer                                           0x908228
#define pinstModelPlayer                                           0x908254
#define pinstPCData                                                0x908218
#define pinstSelectedItem                                          0x9943B4
#define pinstSpawnManager                                          0x9884C4
#define pinstSpellManager                                          0x98852C
#define pinstSpellSets                                             0x987018
#define pinstStringTable                                           0x9081E8
#define pinstSwitchManager                                         0x9063D0
#define pinstTarget                                                0x908240
#define pinstTargetObject                                          0x90821C
#define pinstTargetSwitch                                          0x908220
#define pinstTrackTarget                                           0x908234
#define pinstTradeTarget                                           0x908224
#define instTributeActive                                          0x855FA5
#define pinstViewActor                                             0x8568F4
#define pinstWorldData                                             0x9081F8


////
//Section 2:  UI Related Offsets
////
#define pinstCTextOverlay                                          0x7A1D90
#define pinstCCharacterSelect                                      0x8567CC
#define pinstCFacePick                                             0x8567D0
#define pinstCNoteWnd                                              0x8567D4
#define pinstCHelpWnd                                              0x995148
#define pinstCBookWnd                                              0x8567D8
#define pinstCPetInfoWnd                                           0x8567DC
#define pinstCTrainWnd                                             0x8567E0
#define pinstCSkillsWnd                                            0x8567E4
#define pinstCSkillsSelectWnd                                      0x8567E8
#define pinstCCombatSkillSelectWnd                                 0x8567EC
#define pinstCFriendsWnd                                           0x8567F0
#define pinstCAAWnd                                                0x856800
#define pinstCGroupSearchFiltersWnd                                0x856804
#define pinstCLoadskinWnd                                          0x856808
#define pinstCAlarmWnd                                             0x85680C
#define pinstCMusicPlayerWnd                                       0x856810
#define pinstCRaidWnd                                              0x856820
#define pinstCRaidOptionsWnd                                       0x856824
#define pinstCBreathWnd                                            0x856828
#define pinstCMapViewWnd                                           0x85682C
#define pinstCMapToolbarWnd                                        0x856830
#define pinstCEditLabelWnd                                         0x856834
#define pinstCTargetWnd                                            0x856838
#define pinstCHotButtonWnd                                         0x994344
#define pinstCHotButtonWnd1                                        0x994344
#define pinstCHotButtonWnd2                                        0x994348
#define pinstCHotButtonWnd3                                        0x99434C
#define pinstCHotButtonWnd4                                        0x994350
#define pinstCColorPickerWnd                                       0x85683C
#define pinstCPlayerWnd                                            0x856840
#define pinstCOptionsWnd                                           0x856844
#define pinstCBuffWindowNORMAL                                     0x856848
#define pinstCBuffWindowSHORT                                      0x85684C
#define pinstCharacterCreation                                     0x856850
#define pinstCCursorAttachment                                     0x856854
#define pinstCCastingWnd                                           0x856858
#define pinstCCastSpellWnd                                         0x85685C
#define pinstCSpellBookWnd                                         0x856860
#define pinstCInventoryWnd                                         0x856864
#define pinstCBankWnd                                              0x856868
#define pinstCQuantityWnd                                          0x85686C
#define pinstCLootWnd                                              0x856870
#define pinstCActionsWnd                                           0x856874
#define pinstCCombatAbilityWnd                                     0x856878
#define pinstCMerchantWnd                                          0x85687C
#define pinstCTradeWnd                                             0x856880
#define pinstCSelectorWnd                                          0x856884
#define pinstCBazaarWnd                                            0x856888
#define pinstCBazaarSearchWnd                                      0x85688C
#define pinstCGiveWnd                                              0x856890
#define pinstCTrackingWnd                                          0x856894
#define pinstCInspectWnd                                           0x856898
#define pinstCSocialEditWnd                                        0x85689C
#define pinstCFeedbackWnd                                          0x8568A0
#define pinstCBugReportWnd                                         0x8568A4
#define pinstCVideoModesWnd                                        0x8568A8
#define pinstCTextEntryWnd                                         0x8568B0
#define pinstCFileSelectionWnd                                     0x8568B4
#define pinstCCompassWnd                                           0x8568B8
#define pinstCPlayerNotesWnd                                       0x8568BC
#define pinstCGemsGameWnd                                          0x8568C0
#define pinstCTimeLeftWnd                                          0x8568C4
#define pinstCPetitionQWnd                                         0x8568C8
#define pinstCSoulmarkWnd                                          0x8568CC
#define pinstCStoryWnd                                             0x8568D0
#define pinstCJournalTextWnd                                       0x8568D4
#define pinstCJournalCatWnd                                        0x8568D8
#define pinstCBodyTintWnd                                          0x8568DC
#define pinstCInvSlotMgr                                           0x8568E8
#define pinstCContainerMgr                                         0x8568EC
#define pinstCAdventureLeaderboardWnd                              0x993C18
#define pinstCAdventureMerchantWnd                                 0x7A1D30
#define pinstCAdventureRequestWnd                                  0x993C34
#define pinstCAdventureStatsWnd                                    0x993C50
#define pinstCChatManager                                          0x994044
#define pinstCDynamicZoneWnd                                       0x994120
#define pinstCFindLocationWnd                                      0x994224
#define pinstCGroupSearchWnd                                       0x9942B8
#define pinstCGroupWnd                                             0x9942D4
#define pinstCGuildMgmtWnd                                         0x99430C
#define pinstCItemDisplayManager                                   0x9943E8
#define pinstCLeadershipWnd                                        0x994484
#define pinstCConfirmationDialog                                   0x9946A4
#define pinstCPopupWndManager                                      0x9946A4
#define pinstCSystemInfoDialogBox                                  0x995070
#define pinstCTargetOfTargetWnd                                    0x99508C
#define pinstCTipWndOFDAY                                          0x99517C
#define pinstCTipWndCONTEXT                                        0x995180
#define pinstCTradeskillWnd                                        0x9951E0
#define pinstCTributeBenefitWnd                                    0x99522C
#define pinstCTributeMasterWnd                                     0x995248
#define pinstCContextMenuManager                                   0x99FCB4


////
// Section 3: Miscellaneous Offsets
////
#define __CastRay                                                  0x479F59
#define __ConvertItemTags                                          0x471352
#define __ExecuteCmd                                               0x465BB1
#define __get_melee_range                                          0x469B35
#define __GetGaugeValueFromEQ                                      0x559152
#define __GetLabelFromEQ                                           0x559717
#define __NewUIINI                                                 0x558E00
#define __ProcessGameEvents                                        0x49D024
#define __SendMessage                                              0x48474B
#define CrashDetected                                              0x4CBA55
#define DrawNetStatus                                              0x4AC189
#define Util__FastTime                                             0x571530


////
// Section 4: Function Offsets
////
// AltAdvManager
#define AltAdvManager__GetCalculatedTimer                          0x44D835
#define AltAdvManager__IsAbilityReady                              0x44D86B
#define AltAdvManager__GetAltAbility                               0x44D97F

// CBankWnd
#define CBankWnd__GetNumBankSlots                                  0x4DBBC1

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg                          0x4E3775

// CButtonWnd
#define CButtonWnd__SetCheck                                       0x5BB390

// CChatManager
#define CChatManager__GetRGBAFromIndex                             0x4F1EEE
#define CChatManager__InitContextMenu                              0x4F2450

// CChatWindow
#define CChatWindow__CChatWindow                                   0x4F5BE3

// CComboWnd
#define CComboWnd__DeleteAll                                       0x59C4D0
#define CComboWnd__Draw                                            0x59C6C0
#define CComboWnd__GetButtonRect                                   0x59C500
#define CComboWnd__GetCurChoice                                    0x59C490
#define CComboWnd__GetListRect                                     0x59C960
#define CComboWnd__GetTextRect                                     0x59C550
#define CComboWnd__InsertChoice                                    0x59C9C0
#define CComboWnd__SetColors                                       0x59C420
#define CComboWnd__SetChoice                                       0x59C450

// CContainerWnd
#define CContainerWnd__HandleCombine                               0x4FB433
#define CContainerWnd__vftable                                     0x6574F0

// CDisplay
#define CDisplay__CleanGameUI                                      0x4405EC
#define CDisplay__GetClickedActor                                  0x43E486
#define CDisplay__GetUserDefinedColor                              0x43DB52
#define CDisplay__GetWorldFilePath                                 0x43D2F4
#define CDisplay__ReloadUI                                         0x4499F5
#define CDisplay__WriteTextHD2                                     0x441AA7

// CEditBaseWnd
#define CEditBaseWnd__SetMaxChars                                  0x4D7223
#define CEditBaseWnd__SetSel                                       0x5BA3F0

// CEditWnd
#define CEditWnd__DrawCaret                                        0x5B7B90
#define CEditWnd__GetCharIndexPt                                   0x5B8990
#define CEditWnd__GetDisplayString                                 0x5B7D20
#define CEditWnd__GetHorzOffset                                    0x5B7F90
#define CEditWnd__GetLineForPrintableChar                          0x5B8470
#define CEditWnd__GetSelStartPt                                    0x5B8BD0
#define CEditWnd__GetSTMLSafeText                                  0x5B8120
#define CEditWnd__PointFromPrintableChar                           0x5B8580
#define CEditWnd__SelectableCharFromPoint                          0x5B86F0
#define CEditWnd__SetEditable                                      0x5B80F0

// CEverQuest
#define CEverQuest__ClickedPlayer                                  0x487BAA
#define CEverQuest__DropHeldItemOnGround                           0x48AD96
#define CEverQuest__dsp_chat                                       0x48B70B
#define CEverQuest__EnterZone                                      0x49B9DD
#define CEverQuest__GetBodyTypeDesc                                0x4858D4
#define CEverQuest__GetClassDesc                                   0x4852F7
#define CEverQuest__GetClassThreeLetterCode                        0x485771
#define CEverQuest__GetDeityDesc                                   0x485BF9
#define CEverQuest__GetRaceDesc                                    0x485BD9
#define CEverQuest__InterpretCmd                                   0x48BFB4
#define CEverQuest__LeftClickedOnPlayer                            0x49A2D6
#define CEverQuest__RightClickedOnPlayer                           0x49A725
#define CEverQuest__SetGameState                                   0x487C2B

// CGaugeWnd
#define CGaugeWnd__CalcFillRect                                    0x503AC7
#define CGaugeWnd__CalcLinesFillRect                               0x503B23
#define CGaugeWnd__Draw                                            0x503E23

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton                                 0x513C4A

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot                                   0x51A2C1
#define CInvSlotMgr__MoveItem                                      0x51A41C

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x51B229

// CItemDisplayWnd
#define CItemDisplayWnd__SetItem                                   0x52133E
#define CItemDisplayWnd__SetSpell                                  0x51D499

// CLabel
#define CLabel__Draw                                               0x5259BC

// CListWnd
#define CListWnd__AddColumn                                        0x59C230
#define CListWnd__AddColumn1                                       0x59BD60
#define CListWnd__AddLine                                          0x59B8F0
#define CListWnd__AddString                                        0x59BAC0
#define CListWnd__CalculateFirstVisibleLine                        0x598E10
#define CListWnd__CalculateVSBRange                                0x59A950
#define CListWnd__ClearAllSel                                      0x598650
#define CListWnd__CloseAndUpdateEditWindow                         0x599430
#define CListWnd__Compare                                          0x5997A0
#define CListWnd__Draw                                             0x59A660
#define CListWnd__DrawColumnSeparators                             0x59A4E0
#define CListWnd__DrawHeader                                       0x598820
#define CListWnd__DrawItem                                         0x599EB0
#define CListWnd__DrawLine                                         0x59A220
#define CListWnd__DrawSeparator                                    0x59A580
#define CListWnd__EnsureVisible                                    0x598E60
#define CListWnd__ExtendSel                                        0x599DE0
#define CListWnd__GetColumnFlags                                   0x5981F0
#define CListWnd__GetColumnJustification                           0x598360
#define CListWnd__GetColumnMinWidth                                0x598300
#define CListWnd__GetColumnWidth                                   0x598240
#define CListWnd__GetCurSel                                        0x597CB0
#define CListWnd__GetHeaderRect                                    0x597DC0
#define CListWnd__GetItemAtPoint                                   0x599140
#define CListWnd__GetItemAtPoint1                                  0x5991B0
#define CListWnd__GetItemData                                      0x597FA0
#define CListWnd__GetItemHeight                                    0x598BB0
#define CListWnd__GetItemIcon                                      0x598130
#define CListWnd__GetItemRect                                      0x598F30
#define CListWnd__GetItemText                                      0x597FE0
#define CListWnd__GetSelList                                       0x59BC40
#define CListWnd__GetSeparatorRect                                 0x5996F0
#define CListWnd__IsLineEnabled                                    0x598730
#define CListWnd__RemoveLine                                       0x59BBF0
#define CListWnd__SetColors                                        0x597D30
#define CListWnd__SetColumnJustification                           0x5983B0
#define CListWnd__SetColumnWidth                                   0x5982C0
#define CListWnd__SetCurSel                                        0x597CF0
#define CListWnd__SetItemColor                                     0x59B4C0
#define CListWnd__SetItemData                                      0x5986F0
#define CListWnd__SetItemText                                      0x59B440
#define CListWnd__ShiftColumnSeparator                             0x599D50
#define CListWnd__Sort                                             0x59C260
#define CListWnd__ToggleSel                                        0x5985C0

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd                                   0x5357CD

// CMerchantWnd
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x536DEF
#define CMerchantWnd__RequestBuyItem                               0x537D6E
#define CMerchantWnd__RequestSellItem                              0x536FE8
#define CMerchantWnd__SelectBuySellSlot                            0x537AD2

// CSidlManager
#define CSidlManager__FindScreenPieceTemplate1                     0x5B5ED0

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateHSBRange                          0x5A1760
#define CSidlScreenWnd__CalculateVSBRange                          0x5A16A0
#define CSidlScreenWnd__ConvertToRes                               0x5A1EA0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x5A26D0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x5A3940
#define CSidlScreenWnd__CSidlScreenWnd2                            0x5A39F0
#define CSidlScreenWnd__dCSidlScreenWnd                            0x5A31F0
#define CSidlScreenWnd__DrawSidlPiece                              0x5A23F0
#define CSidlScreenWnd__EnableIniStorage                           0x5A1E50
#define CSidlScreenWnd__GetSidlPiece                               0x5A25B0
#define CSidlScreenWnd__Init1                                      0x5A3760
#define CSidlScreenWnd__LoadIniInfo                                0x5A2780
#define CSidlScreenWnd__LoadIniListWnd                             0x5A2010
#define CSidlScreenWnd__LoadSidlScreen                             0x5A2250
#define CSidlScreenWnd__SetScreen                                  0x5A3300
#define CSidlScreenWnd__StoreIniInfo                               0x5A19A0
#define CSidlScreenWnd__WndNotification                            0x5A2350

// CSliderWnd
#define CSliderWnd__GetValue                                       0x5BCE40
#define CSliderWnd__SetValue                                       0x5BCFC0
#define CSliderWnd__UpdateThumb                                    0x5BCE00

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet                                 0x5575FE

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x5AC3C0
#define CStmlWnd__CalculateHSBRange                                0x5A4BA0
#define CStmlWnd__CalculateVSBRange                                0x5A4B40
#define CStmlWnd__CanBreakAtCharacter                              0x5A4CE0
#define CStmlWnd__CanGoBackward                                    0x5A4DC0
#define CStmlWnd__FastForwardToEndOfTag                            0x5A5860
#define CStmlWnd__GetNextChar                                      0x5A5220
#define CStmlWnd__GetNextTagPiece                                  0x5A5780
#define CStmlWnd__GetSTMLText                                      0x4F5BC5
#define CStmlWnd__GetThisChar                                      0x5D9AD0
#define CStmlWnd__GetVisiableText                                  0x5A69B0
#define CStmlWnd__InitializeWindowVariables                        0x5A8B00
#define CStmlWnd__MakeStmlColorTag                                 0x5A41E0
#define CStmlWnd__MakeWndNotificationTag                           0x5A4280
#define CStmlWnd__StripFirstSTMLLines                              0x5AC150
#define CStmlWnd__UpdateHistoryString                              0x5A7210

// CTabWnd
#define CTabWnd__Draw                                              0x5BC900
#define CTabWnd__DrawCurrentPage                                   0x5BC340
#define CTabWnd__DrawTab                                           0x5BC140
#define CTabWnd__GetCurrentPage                                    0x5BC650
#define CTabWnd__GetCurrentTabIndex                                0x5BBE00
#define CTabWnd__GetNumTabs                                        0x5BBDF0
#define CTabWnd__GetPageClientRect                                 0x5BBE10
#define CTabWnd__GetPageFromTabIndex                               0x5BC090
#define CTabWnd__GetPageInnerRect                                  0x5BBE70
#define CTabWnd__GetTabInnerRect                                   0x5BC010
#define CTabWnd__GetTabRect                                        0x5BBF20
#define CTabWnd__IndexInBounds                                     0x5BBF00
#define CTabWnd__InsertPage                                        0x5BCB00
#define CTabWnd__SetPage                                           0x5BC660
#define CTabWnd__SetPageRect                                       0x5BC850
#define CTabWnd__UpdatePage                                        0x5BCA80

// CTextOverlay
#define CTextOverlay__DisplayText                                  0x40CE9E

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x5A3D70

// CXMLDataManager
#define CXMLDataManager__GetXMLData                                0x5C31A0

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead                               0x597A60

// CXRect
#define CXRect__CenterPoint                                        0x4DB3C1

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr                                               0x40CAD7
#define CXStr__CXStr1                                              0x4060FC
#define CXStr__CXStr3                                              0x572B10
#define CXStr__dCXStr                                              0x406102
#define CXStr__operator_equal1                                     0x572CD0
#define CXStr__operator_plus_equal1                                0x573B10

// CXWnd
#define CXWnd__BringToTop                                          0x59D170
#define CXWnd__Center                                              0x5A0590
#define CXWnd__ClrFocus                                            0x59CEC0
#define CXWnd__DoAllDrawing                                        0x5A1180
#define CXWnd__DrawChildren                                        0x5A12B0
#define CXWnd__DrawColoredRect                                     0x59D3F0
#define CXWnd__DrawTooltipAtPoint                                  0x5A0400
#define CXWnd__GetBorderFrame                                      0x59D8A0
#define CXWnd__GetChildWndAt                                       0x5A0010
#define CXWnd__GetClientClipRect                                   0x59D7D0
#define CXWnd__GetFirstChildWnd                                    0x59D200
#define CXWnd__GetNextChildWnd                                     0x59FFF0
#define CXWnd__GetNextSib                                          0x59D220
#define CXWnd__GetScreenClipRect                                   0x5A0820
#define CXWnd__GetScreenRect                                       0x59DA70
#define CXWnd__GetTooltipRect                                      0x59D640
#define CXWnd__GetWindowTextA                                      0x4D164A
#define CXWnd__IsActive                                            0x59D840
#define CXWnd__IsDescendantOf                                      0x59D850
#define CXWnd__IsReallyVisible                                     0x59FFD0
#define CXWnd__IsType                                              0x5A1120
#define CXWnd__Move                                                0x59FB80
#define CXWnd__Move1                                               0x59FC10
#define CXWnd__ProcessTransition                                   0x59D130
#define CXWnd__Refade                                              0x59CF60
#define CXWnd__Resize                                              0x5A0960
#define CXWnd__Right                                               0x5A0700
#define CXWnd__SetFirstChildPointer                                0x59DCC0
#define CXWnd__SetFocus                                            0x59EF00
#define CXWnd__SetKeyTooltip                                       0x59DD00
#define CXWnd__SetMouseOver                                        0x59DCE0
#define CXWnd__SetNextSibPointer                                   0x59DCD0
#define CXWnd__StartFade                                           0x59D190

// CXWndManager
#define CXWndManager__DrawCursor                                   0x5AF6F0
#define CXWndManager__DrawWindows                                  0x5AF3C0
#define CXWndManager__GetFirstChildWnd                             0x5AED50
#define CXWndManager__GetKeyboardFlags                             0x5AE0A0
#define CXWndManager__HandleKeyboardMsg                            0x5AE620
#define CXWndManager__RemoveWnd                                    0x5AE530

// CDBStr
#define CDBStr__GetString                                          0x43B067

// EQ_Character
#define EQ_Character__CastSpell                                    0x416C5D
#define EQ_Character__Cur_HP                                       0x41C85D
#define EQ_Character__GetAACastingTimeModifier                     0x412F77
#define EQ_Character__GetCharInfo2                                 0x5EC2B0
#define EQ_Character__GetFocusCastingTimeModifier                  0x41246C
#define EQ_Character__Max_Endurance                                0x41B62A
#define EQ_Character__Max_HP                                       0x41B526
#define EQ_Character__Max_Mana                                     0x4AFE3C
#define EQ_Character__doCombatAbility                              0x4AED7F

// EQ_Item
#define EQ_Item__CanDrop                                           0x4A52C7
#define EQ_Item__GetItemLinkHash                                   0x5E38E0
#define EQ_Item__IsStackable                                       0x5EC7F0

// EQ_LoadingS
#define EQ_LoadingS__WriteTextHD                                   0x44DFBD

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney                              0x4B1FFB
#define EQ_PC__GetAltAbilityIndex                                  0x5F09B0
#define EQ_PC__GetCombatAbility                                    0x5F0AA0
#define EQ_PC__GetCombatAbilityTimer                               0x5F0B50
#define EQ_PC__GetItemTimerValue                                   0x4AE5FB

// EQItemList
#define EQItemList__dEQItemList                                    0x468920
#define EQItemList__EQItemList                                     0x4688A4

// EQPlayer
#define EQPlayer__ChangeBoneStringSprite                           0x4B61B4
#define EQPlayer__dEQPlayer                                        0x4B8D6B
#define EQPlayer__DoAttack                                         0x4C1A8E
#define EQPlayer__EQPlayer                                         0x4BAC35
#define EQPlayer__SetNameSpriteState                               0x4B7A17
#define EQPlayer__SetNameSpriteTint                                0x4B621C

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x4BB83D

// KeyPressHandler
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4A6B38
#define KeypressHandler__AttachKeyToEqCommand                      0x4A6B05
#define KeypressHandler__ClearCommandStateArray                    0x4A694D
#define KeypressHandler__HandleKeyDown                             0x4A57A8
#define KeypressHandler__HandleKeyUp                               0x4A5A1F
#define KeypressHandler__SaveKeymapping                            0x4A69D5

// MapViewMap
#define MapViewMap__Clear                                          0x531F33
#define MapViewMap__SaveEx                                         0x5326F0

// StringTable
#define StringTable__getString                                     0x5DFA60
