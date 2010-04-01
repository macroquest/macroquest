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
#define __ExpectedVersionDate                              "Mar  2 2005"
#define __ExpectedVersionTime                              "16:37:01"
#define __ActualVersionDate                                0x611944
#define __ActualVersionTime                                0x611950

#define __ClientOverride                                   0
#define __MacroQuestWinClassName                           "__MacroQuestTray"
#define __MacroQuestWinName                                "MacroQuest"

// Memory Protection
#define __MemChecker0                                      0x50BB8F
#define __MemChecker2                                      0x5496EA
#define __MemChecker3                                      0x549777
#define __MemChecker4                                      0x5C4340
#define __EncryptPad0                                      0x7330E0
#define __EncryptPad2                                      0x7363C0
#define __EncryptPad3                                      0x7367C0
#define __EncryptPad4                                      0x73B170

// Direct Input
#define DI8__Main                                          0x90E2EC
#define DI8__Keyboard                                      0x90E2F0
#define DI8__Mouse                                         0x90E2F4

#define __AltTimerReady                                    0x880B96
#define __Attack                                           0x8E069C
#define __BindList                                         0x63AD50
#define __Clicks                                           0x87FDA4
#define __CommandList                                      0x63B2E0
#define __CurrentMapLabel                                  0x90062C
#define __CurrentSocial                                    0x63E748
#define __DoAbilityAvailable                               0x880B30
#define __DoAbilityList                                    0x8B98F4
#define __DrawHandler                                      0x918734
#define __EQP_IDArray                                      0x7CDF58
#define __FriendsList                                      0x8B66B4
#define __Guilds                                           0x8E8478
#define __gWorld                                           0x8E2488
#define __HotkeyPage                                       0x8E0254
#define __HWnd                                             0x87FCA0
#define __IgnoreList                                       0x8B7FB4
#define __InChatMode                                       0x87FCE0
#define __LastTell                                         0x881E20
#define __Mouse                                            0x90E2F8
#define __MouseLook                                        0x87FD72
#define __NetStatusToggle                                  0x87FD74
#define __PCNames                                          0x880E2C
#define __RangeAttackReady                                 0x880B94
#define __RunWalkState                                     0x87FCE4
#define __ScreenMode                                       0x7CBAD8
#define __ScreenX                                          0x87FCA8
#define __ScreenY                                          0x87FCAC
#define __ServerHost                                       0x8E08EC
#define __ServerName                                       0x8B98B4
#define __ShowNames                                        0x880D7C
#define __SkillDict                                        0x7D12E8
#define __Socials                                          0x8B99B4

////
//Section 1: Vital Offsets
////
#define instCRaid                                          0x8E2520
#define instEQZoneInfo                                     0x87FF10
#define instKeypressHandler                                0x9002DC
#define pinstActiveBanker                                  0x8E2500
#define pinstActiveCorpse                                  0x8E2504
#define pinstActiveGMaster                                 0x8E2508
#define pinstActiveMerchant                                0x8E24FC
#define pinstAltAdvManager                                 0x7D0E90
#define pinstCCursorAttachment                             0x7CC5F4
#define pinstCDisplay                                      0x8E2510
#define pinstCEverQuest                                    0x90E460
#define pinstCharData                                      0x8E24EC
#define pinstCharSpawn                                     0x8E24E4
#define pinstControlledPlayer                              0x8E24E4
#define pinstCSidlManager                                  0x917734
#define pinstCXWndManager                                  0x91772C
#define pinstEQItemList                                    0x8E24B0
#define instGroup                                          0x8E0A30
#define pinstLocalPlayer                                   0x8E24D0
#define pinstPCData                                        0x8E24EC
#define pinstSelectedItem                                  0x90025C
#define pinstSpawnList                                     0x8E24AC
#define pinstSpellManager                                  0x900988
#define pinstSpellSets                                     0x8E0258
#define pinstStringTable                                   0x8E2498
#define pinstSwitchManager                                 0x7D0E8C
#define pinstTarget                                        0x8E24F0
#define pinstTargetSwitch                                  0x8E24F8
#define pinstTradeTarget                                   0x8E24CC
#define pinstWorldData                                     0x8E24A8


////
//Section 2:  UI Related Offsets
////
#define pinstCTextOverlay                                  0x73CD80
#define pinstCharacterSelect                               0x7CC56C
#define pinstCFacePick                                     0x7CC570
#define pinstCNoteWnd                                      0x7CC574
#define pinstCHelpWnd                                      0x7CC578
#define pinstCBookWnd                                      0x7CC57C
#define pinstCPetInfoWnd                                   0x7CC580
#define pinstCTrainWnd                                     0x7CC584
#define pinstCSkillsWnd                                    0x7CC588
#define pinstCSkillsSelectWnd                              0x7CC58C
#define pinstCCombatSkillSelectWnd                         0x7CC590
#define pinstCFriendsWnd                                   0x7CC594
#define pinstCAAWnd                                        0x7CC5A0
#define pinstCGroupSearchFiltersWnd                        0x7CC5A4
#define pinstCLoadskinWnd                                  0x7CC5A8
#define pinstCAlarmWnd                                     0x7CC5AC
#define pinstCMusicPlayerWnd                               0x7CC5B0
#define pinstCRaidWnd                                      0x7CC5BC
#define pinstCRaidOptionsWnd                               0x7CC5C0
#define pinstCBreathWnd                                    0x7CC5C4
#define pinstCMapViewWnd                                   0x7CC5C8
#define pinstCMapToolbarWnd                                0x7CC5CC
#define pinstCEditLabelWnd                                 0x7CC5D0
#define pinstCTargetWnd                                    0x7CC5D4
#define pinstCHotButtonWnd                                 0x7CC5D8
#define pinstCColorPickerWnd                               0x7CC5DC
#define pinstCPlayerWnd                                    0x7CC5E0
#define pinstCOptionsWnd                                   0x7CC5E4
#define pinstCBuffWindowNORMAL                             0x7CC5E8
#define pinstCBuffWindowSHORT                              0x7CC5EC
#define pinstCharacterCreation                             0x7CC5F0
#define pinstCCursorAttachment                             0x7CC5F4
#define pinstCCastingWnd                                   0x7CC5F8
#define pinstCCastSpellWnd                                 0x7CC5FC
#define pinstCSpellBookWnd                                 0x7CC600
#define pinstCInventoryWnd                                 0x7CC604
#define pinstCBankWnd                                      0x7CC608
#define pinstCQuantityWnd                                  0x7CC60C
#define pinstCLootWnd                                      0x7CC610
#define pinstCActionsWnd                                   0x7CC614
#define pinstCCombatAbilityWnd                             0x7CC618
#define pinstCMerchantWnd                                  0x7CC61C
#define pinstCTradeWnd                                     0x7CC620
#define pinstCSelectorWnd                                  0x7CC624
#define pinstCBazaarWnd                                    0x7CC628
#define pinstCBazaarSearchWnd                              0x7CC62C
#define pinstCGiveWnd                                      0x7CC630
#define pinstCTrackingWnd                                  0x7CC634
#define pinstCInspectWnd                                   0x7CC638
#define pinstCSocialEditWnd                                0x7CC63C
#define pinstCFeedbackWnd                                  0x7CC640
#define pinstCBugReportWnd                                 0x7CC644
#define pinstCVideoModesWnd                                0x7CC648
#define pinstCTextEntryWnd                                 0x7CC650
#define pinstCFileSelectionWnd                             0x7CC654
#define pinstCCompassWnd                                   0x7CC658
#define pinstCPlayerNotesWnd                               0x7CC65C
#define pinstCGemsGameWnd                                  0x7CC660
#define pinstCTimeLeftWnd                                  0x7CC664
#define pinstCPetitionQWnd                                 0x7CC668
#define pinstCSoulmarkWnd                                  0x7CC66C
#define pinstCStoryWnd                                     0x7CC670
#define pinstCJournalTextWnd                               0x7CC674
#define pinstCJournalCatWnd                                0x7CC678
#define pinstCBodyTintWnd                                  0x7CC67C
#define pinstCInvSlotMgr                                   0x7CC684
#define pinstCContainerMgr                                 0x7CC688
#define pinstCAdventureLeaderboardWnd                      0x73CA2C
#define pinstCAdventureMerchantWnd                         0x73CA48
#define pinstCAdventureRequestWnd                          0x73CA64
#define pinstCAdventureStatsWnd                            0x73CA80
#define pinstCChatManager                                  0x73CEB0
#define pinstCDynamicZoneWnd                               0x7CC794
#define pinstCFindLocationWnd                              0x900060
#define pinstCGroupSearchWnd                               0x900158
#define pinstCGroupWnd                                     0x900174
#define pinstCGuildMgmtWnd                                 0x9001AC
#define pinstCItemDisplayManager                           0x900290
#define pinstCLeadershipWnd                                0x900378
#define pinstCPopupWndManager                              0x900780
#define pinstCSystemInfoDialogBox                          0x901130
#define pinstCTargetOfTargetWnd                            0x901154
#define pinstCTipWndOFDAY                                  0x901244
#define pinstCTipWndCONTEXT                                0x901248
#define pinstCTradeskillWnd                                0x901340
#define pinstCTributeBenefitWnd                            0x90138C
#define pinstCTributeMasterWnd                             0x9013A8
#define pinstCContextMenuManager                           0x91778C
// unknown window added 4-14 exe 0x79A234


////
// Section 3: Miscellaneous Offsets
////
#define __CastRay                                          0x46E33A
#define __ConvertItemTags                                  0x46DB46
#define __ExecuteCmd                                       0x460150
#define __get_melee_range                                  0x4645B9
#define __GetLabelFromEQ								   0x53276E
#define __GetGaugeValueFromEQ                              0x531CA6
#define __LoadSplashScreen                                 0x5CB8D0
#define __NewUIINI                                         0x53257E
#define __ProcessGameEvents                                0x4CF1EF
#define __SendMessage                                      0x4B636B
#define CrashDetected                                      0x5493A6
#define DrawNetStatus                                      0x51027E


////
// Section 4: Function Offsets
////
// AltAdvManager
#define AltAdvManager__GetCalculatedTimer                  0x49275A
#define AltAdvManager__IsAbilityReady                      0x492788

// CBankWnd
#define CBankWnd__GetNumBankSlots                          0x40BA51

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg                  0x412F54

// CButtonWnd
#define CButtonWnd__SetCheck                               0x58C170

// CChatManager
#define CChatManager__GetRGBAFromIndex                     0x4244C4
#define CChatManager__InitContextMenu                      0x4245A8

// CChatWindow
#define CChatWindow__CChatWindow                           0x42753B

// CComboWnd
#define CComboWnd__DeleteAll                               0x58CDE0
#define CComboWnd__Draw                                    0x58CFE0
#define CComboWnd__GetButtonRect                           0x58CE10
#define CComboWnd__GetCurChoice                            0x58CDA0
#define CComboWnd__GetListRect                             0x58D3D0
#define CComboWnd__GetTextRect                             0x58CE70
#define CComboWnd__InsertChoice                            0x58D430
#define CComboWnd__SetColors                               0x58CD70
#define CComboWnd__SetChoice                               0x58D510

// CContainerWnd
#define CContainerWnd__HandleCombine                       0x43371B
#define CContainerWnd__vftable                             0x5F9410

// CDisplay
#define CDisplay__CleanGameUI                              0x442FEF
#define CDisplay__GetClickedActor                          0x43FC56
#define CDisplay__GetUserDefinedColor                      0x43F017
#define CDisplay__GetWorldFilePath                         0x43E7EB
#define CDisplay__ReloadUI                                 0x44A86E
#define CDisplay__WriteTextHD2                             0x443C8F

// CEditBaseWnd
#define CEditBaseWnd__SetMaxChars                          0x408168
#define CEditBaseWnd__SetSel                               0x59DF20

// CEditWnd
#define CEditWnd__DrawCaret                                0x599F90
#define CEditWnd__GetCharIndexPt                           0x59ADE0
#define CEditWnd__GetDisplayString                         0x59A0F0
#define CEditWnd__GetHorzOffset                            0x59A360
#define CEditWnd__GetLineForPrintableChar                  0x59A880
#define CEditWnd__GetSelStartPt                            0x59B020
#define CEditWnd__GetSTMLSafeText                          0x59A540
#define CEditWnd__PointFromPrintableChar                   0x59A990
#define CEditWnd__SelectableCharFromPoint                  0x59AB10
#define CEditWnd__SetEditable                              0x59A510

// CEverQuest
#define CEverQuest__ClickedPlayer                          0x4BB769
#define CEverQuest__DropHeldItemOnGround                   0x4C273D
#define CEverQuest__dsp_chat                               0x4BD846
#define CEverQuest__EnterZone                              0x4CDF5C
#define CEverQuest__GetBodyTypeDesc                        0x4B74E9
#define CEverQuest__GetClassDesc                           0x4B6F0C
#define CEverQuest__GetClassThreeLetterCode                0x4B7386
#define CEverQuest__GetDeityDesc                           0x4B8F7C
#define CEverQuest__GetRaceDesc                            0x4B77EE
#define CEverQuest__InterpretCmd                           0x4C7C79
#define CEverQuest__LeftClickedOnPlayer                    0x4CC8B4
#define CEverQuest__RightClickedOnPlayer                   0x4CCCEA
#define CEverQuest__SetGameState                           0x4BB849

// CGaugeWnd
#define CGaugeWnd__CalcFillRect                            0x4DAA54
#define CGaugeWnd__CalcLinesFillRect                       0x4DAAB0
#define CGaugeWnd__Draw                                    0x4DADB0

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton                         0x4EAEA4

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot                           0x4EE643
#define CInvSlotMgr__MoveItem                              0x4EE771

// CItemDisplayWnd
#define CItemDisplayWnd__SetItem                           0x4F38B5
#define CItemDisplayWnd__SetSpell                          0x4F2819

// CLabel
#define CLabel__Draw                                       0x4FAECF

// CListWnd
#define CListWnd__AddColumn                                0x576880
#define CListWnd__AddColumn1                               0x5763D0
#define CListWnd__AddLine                                  0x575F90
#define CListWnd__AddString                                0x576110
#define CListWnd__CalculateFirstVisibleLine                0x573500
#define CListWnd__CalculateVSBRange                        0x575090
#define CListWnd__ClearAllSel                              0x572C60
#define CListWnd__CloseAndUpdateEditWindow                 0x573B00
#define CListWnd__Compare                                  0x573E40
#define CListWnd__Draw                                     0x574CF0
#define CListWnd__DrawColumnSeparators                     0x574B40
#define CListWnd__DrawHeader                               0x572E80
#define CListWnd__DrawItem                                 0x574550
#define CListWnd__DrawLine                                 0x5748B0
#define CListWnd__DrawSeparator                            0x574C10
#define CListWnd__EnsureVisible                            0x573550
#define CListWnd__ExtendSel                                0x574480
#define CListWnd__GetColumnFlags                           0x572730
#define CListWnd__GetColumnJustification                   0x5728D0
#define CListWnd__GetColumnMinWidth                        0x572860
#define CListWnd__GetColumnWidth                           0x572790
#define CListWnd__GetCurSel                                0x572570
#define CListWnd__GetHeaderRect                            0x5723B0
#define CListWnd__GetItemAtPoint                           0x573800
#define CListWnd__GetItemAtPoint1                          0x573870
#define CListWnd__GetItemData                              0x5725B0
#define CListWnd__GetItemHeight                            0x573280
#define CListWnd__GetItemIcon                              0x572670
#define CListWnd__GetItemRect                              0x573620
#define CListWnd__GetItemText                              0x5725F0
#define CListWnd__GetSelList                               0x5762B0
#define CListWnd__GetSeparatorRect                         0x573D90
#define CListWnd__IsLineEnabled                            0x572D50
#define CListWnd__RemoveLine                               0x576260
#define CListWnd__SetColors                                0x572320
#define CListWnd__SetColumnJustification                   0x572930
#define CListWnd__SetColumnWidth                           0x572810
#define CListWnd__SetCurSel                                0x572B80
#define CListWnd__SetItemColor                             0x575BD0
#define CListWnd__SetItemData                              0x572D10
#define CListWnd__SetItemText                              0x575B10
#define CListWnd__ShiftColumnSeparator                     0x5743F0
#define CListWnd__Sort                                     0x576920
#define CListWnd__ToggleSel                                0x572BA0

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd                           0x50AB70

// CMerchantWnd
#define CMerchantWnd__DisplayBuyOrSellPrice                0x50C072
#define CMerchantWnd__RequestBuyItem                       0x50CA5F
#define CMerchantWnd__RequestSellItem                      0x50C3A6
#define CMerchantWnd__SelectBuySellSlot                    0x50C8DF

// CSidlManager
#define CSidlManager__FindScreenPieceTemplate1             0x597F90

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateHSBRange                  0x56A780
#define CSidlScreenWnd__CalculateVSBRange                  0x56A6C0
#define CSidlScreenWnd__ConvertToRes                       0x56AE70
#define CSidlScreenWnd__CreateChildrenFromSidl             0x56B5E0
#define CSidlScreenWnd__CSidlScreenWnd1                    0x56CCE0
#define CSidlScreenWnd__CSidlScreenWnd2                    0x56CDD0
#define CSidlScreenWnd__dCSidlScreenWnd                    0x56C330
#define CSidlScreenWnd__DrawSidlPiece                      0x56B200
#define CSidlScreenWnd__EnableIniStorage                   0x56AE20
#define CSidlScreenWnd__GetSidlPiece                       0x56B4A0
#define CSidlScreenWnd__Init1                              0x56CA30
#define CSidlScreenWnd__LoadIniInfo                        0x56B690
#define CSidlScreenWnd__LoadIniListWnd                     0x56BFD0
#define CSidlScreenWnd__LoadSidlScreen                     0x56B040
#define CSidlScreenWnd__SetScreen                          0x56C450
#define CSidlScreenWnd__StoreIniInfo                       0x56A9B0
#define CSidlScreenWnd__WndNotification                    0x56B160

// CSliderWnd
#define CSliderWnd__GetValue                               0x58D850
#define CSliderWnd__SetValue                               0x58DA20
#define CSliderWnd__UpdateThumb                            0x58D810

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet                         0x52FD0C

// CStmlWnd
#define CStmlWnd__AppendSTML                               0x57FE00
#define CStmlWnd__CalculateHSBRange                        0x577700
#define CStmlWnd__CalculateVSBRange                        0x5776A0
#define CStmlWnd__CanBreakAtCharacter                      0x577840
#define CStmlWnd__CanGoBackward                            0x5778C0
#define CStmlWnd__FastForwardToEndOfTag                    0x5785B0
#define CStmlWnd__GetNextChar                              0x577D00
#define CStmlWnd__GetNextTagPiece                          0x5783B0
#define CStmlWnd__GetSTMLText                              0x42751D
#define CStmlWnd__GetThisChar                              0x577540
#define CStmlWnd__GetVisiableText                          0x579D80
#define CStmlWnd__InitializeWindowVariables                0x57BB80
#define CStmlWnd__MakeStmlColorTag                         0x576C10
#define CStmlWnd__MakeWndNotificationTag                   0x576CB0
#define CStmlWnd__StripFirstSTMLLines                      0x57FB80
#define CStmlWnd__UpdateHistoryString                      0x57A1C0

// CTabWnd
#define CTabWnd__Draw                                      0x583BE0
#define CTabWnd__DrawCurrentPage                           0x5836D0
#define CTabWnd__DrawTab                                   0x583450
#define CTabWnd__GetCurrentPage                            0x582F40
#define CTabWnd__GetCurrentTabIndex                        0x582C60
#define CTabWnd__GetNumTabs                                0x582D90
#define CTabWnd__GetPageClientRect                         0x582C70
#define CTabWnd__GetPageFromTabIndex                       0x582DC0
#define CTabWnd__GetPageInnerRect                          0x582CD0
#define CTabWnd__GetTabInnerRect                           0x583050
#define CTabWnd__GetTabRect                                0x582F50
#define CTabWnd__IndexInBounds                             0x582DA0
#define CTabWnd__InsertPage                                0x583AD0
#define CTabWnd__SetPage                                   0x5830F0
#define CTabWnd__SetPageRect                               0x5832C0
#define CTabWnd__UpdatePage                                0x583370

// CTextOverlay
#define CTextOverlay__DisplayText                          0x41747D

// CTextureFont
#define CTextureFont__DrawWrappedText                      0x571EA0

// CXMLDataManager
#define CXMLDataManager__GetXMLData                        0x59EBD0

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead                       0x58AED0

// CXRect
#define CXRect__CenterPoint                                0x40B2B4

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr                                       0x401006
#define CXStr__CXStr1                                      0x401000
#define CXStr__CXStr3                                      0x54D0E0
#define CXStr__dCXStr                                      0x4087C7
#define CXStr__operator_equal1                             0x54D2A0
#define CXStr__operator_plus_equal1                        0x54E0E0

// CXWnd
#define CXWnd__BringToTop                                  0x56D480
#define CXWnd__Center                                      0x570AD0
#define CXWnd__ClrFocus                                    0x56D1D0
#define CXWnd__DoAllDrawing                                0x5716E0
#define CXWnd__DrawChildren                                0x571810
#define CXWnd__DrawColoredRect                             0x56D6C0
#define CXWnd__DrawTooltipAtPoint                          0x570900
#define CXWnd__GetBorderFrame                              0x56DB10
#define CXWnd__GetChildWndAt                               0x570490
#define CXWnd__GetClientClipRect                           0x56DA50
#define CXWnd__GetFirstChildWnd                            0x56D510
#define CXWnd__GetNextChildWnd                             0x570470
#define CXWnd__GetNextSib                                  0x56D530
#define CXWnd__GetScreenClipRect                           0x570D60
#define CXWnd__GetScreenRect                               0x56DCE0
#define CXWnd__GetTooltipRect                              0x570850
#define CXWnd__GetWindowTextA                              0x402A90
#define CXWnd__GetXMLTooltip                               0x56D010
#define CXWnd__IsActive                                    0x56DAC0
#define CXWnd__IsDescendantOf                              0x56DAD0
#define CXWnd__IsReallyVisible                             0x570450
#define CXWnd__IsType                                      0x571680
#define CXWnd__Move                                        0x570000
#define CXWnd__Move1                                       0x570090
#define CXWnd__ProcessTransition                           0x56D440
#define CXWnd__Refade                                      0x56D270
#define CXWnd__Resize                                      0x570EA0
#define CXWnd__Right                                       0x570C40
#define CXWnd__SetFirstChildPointer                        0x56DF30
#define CXWnd__SetFocus                                    0x56F1E0
#define CXWnd__SetKeyTooltip                               0x56DF70
#define CXWnd__SetMouseOver                                0x56DF50
#define CXWnd__SetNextSibPointer                           0x56DF40
#define CXWnd__StartFade                                   0x56D4A0

// CXWndManager
#define CXWndManager__DrawCursor                           0x58FB40
#define CXWndManager__DrawWindows                          0x58F790
#define CXWndManager__GetFirstChildWnd                     0x58F110
#define CXWndManager__GetKeyboardFlags                     0x58E550
#define CXWndManager__HandleKeyboardMsg                    0x58EA20
#define CXWndManager__RemoveWnd                            0x58E930

// EQ_Character
#define EQ_Character__CastSpell                            0x4A3035
#define EQ_Character__Cur_HP                               0x49680D
#define EQ_Character__GetAACastingTimeModifier             0x49F757
#define EQ_Character__GetFocusCastingTimeModifier          0x49F2DB
#define EQ_Character__Max_Endurance                        0x4932F4
#define EQ_Character__Max_HP                               0x4930A1
#define EQ_Character__Max_Mana                             0x4AC1D9

// EQ_Item
#define EQ_Item__CanDrop                                   0x4A979C
#define EQ_Item__GetItemLinkHash                           0x4A938E
#define EQ_Item__IsStackable                               0x4A9940

// EQ_LoadingS
#define EQ_LoadingS__WriteTextHD                           0x4A9EA3

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney                      0x4AF44C

// EQItemList
#define EQItemList__dEQItemList                            0x462C9C
#define EQItemList__EQItemList                             0x462C20

// EQPlayer
#define EQPlayer__ChangeBoneStringSprite                   0x479E58
#define EQPlayer__dEQPlayer                                0x482AD2
#define EQPlayer__DoAttack                                 0x480B30
#define EQPlayer__EQPlayer                                 0x4830C2
#define EQPlayer__SetNameSpriteState                       0x47CABF
#define EQPlayer__SetNameSpriteTint                        0x479EC4

// KeyPressHandler
#define KeypressHandler__AttachAltKeyToEqCommand           0x4FAD38
#define KeypressHandler__AttachKeyToEqCommand              0x4FAD05
#define KeypressHandler__ClearCommandStateArray            0x4FAB4E
#define KeypressHandler__HandleKeyDown                     0x4F99A9
#define KeypressHandler__HandleKeyUp                       0x4F9C20
#define KeypressHandler__SaveKeymapping                    0x4FABD5

// MapViewMap
#define MapViewMap__Clear                                  0x50794A
#define MapViewMap__SaveEx                                 0x5080E5

// StringTable
#define StringTable__getString                             0x5BB000 