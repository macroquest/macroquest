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

#define __ClientName                                      "eqgame"
#define __ExpectedVersionDate                             "Aug  4 2005"               
#define __ExpectedVersionTime                             "15:40:59"     
#define __ActualVersionDate                                0x61B294
#define __ActualVersionTime                                0x61B2A0

#define __ClientOverride                                   0
#define __MacroQuestWinClassName                          "__MacroQuestTray"
#define __MacroQuestWinName                               "MacroQuest"

// Memory Protection
#define __MemChecker0                                      0x4B7FF1
#define __MemChecker2                                      0x4C6A81
#define __MemChecker3                                      0x4C6B0E
#define __MemChecker4                                      0x5D3250
#define __EncryptPad0                                      0x751EF8
#define __EncryptPad2                                      0x753170
#define __EncryptPad3                                      0x753570
#define __EncryptPad4                                      0x75CFB0

// Direct Input
#define DI8__Main                                          0x9499F4
#define DI8__Keyboard                                      0x9499F8
#define DI8__Mouse                                         0x9499FC

#define __AltTimerReady                                    0x8C72EE
#define __Attack                                           0x926E08
#define __BindList                                         0x74DDF8
#define __Clicks                                           0x8C64F4
#define __CommandList                                      0x74E398
#define __CurrentMapLabel                                  0x9529D0
#define __CurrentSocial                                    0x65B190
#define __DoAbilityAvailable                               0x8C7288
#define __DoAbilityList                                    0x900060
#define __DrawHandler                                      0x95F00C
#define __EQP_IDArray                                      0x8C34B0
#define __FriendsList                                      0x8FCE20
#define __GroupCount                                       0x927198
#define __GroupLeader                                      0x9272F4
#define __Guilds                                           0x92EBE0
#define __gWorld                                           0x928BF0
#define __HotkeyPage                                       0x9269C0
#define __HWnd                                             0x8C63F0
#define __IgnoreList                                       0x8FE720
#define __InChatMode                                       0x8C6430
#define __LastTell                                         0x8C858C
#define __Mouse                                            0x949A00
#define __MouseLook                                        0x8C64C2
#define __NetStatusToggle                                  0x8C64C4
#define __PCNames                                          0x8C75E4
#define __RangeAttackReady                                 0x8C72EC
#define __RunWalkState                                     0x8C6434
#define __ScreenMode                                       0x812278
#define __ScreenX                                          0x8C63F8
#define __ScreenY                                          0x8C63FC
#define __ServerHost                                       0x927054
#define __ServerName                                       0x900020
#define __ShowNames                                        0x8C74D4
#define __SkillDict                                        0x8137A8
#define __Socials                                          0x900120

////
//Section 1: Vital Offsets
////
#define instCRaid                                          0x928C88
#define instEQZoneInfo                                     0x8C6660
#define instKeypressHandler                                0x946778
#define pinstActiveBanker                                  0x928C68
#define pinstActiveCorpse                                  0x928C6C
#define pinstActiveGMaster                                 0x928C70
#define pinstActiveMerchant                                0x928C64
#define pinstAltAdvManager                                 0x813350
#define pinstCDisplay                                      0x928C78
#define pinstCEverQuest                                    0x949B68
#define pinstCharData                                      0x928C54
#define pinstCharSpawn                                     0x928C4C
#define pinstControlledPlayer                              0x928C4C
#define pinstCSidlManager                                  0x95E094
#define pinstCXWndManager                                  0x95E08C
#define pinstEQItemList                                    0x928C18
#define instGroup                                          0x927198
#define pinstLocalPlayer                                   0x928C38
#define pinstPCData                                        0x928C54
#define pinstSelectedItem                                  0x952848
#define pinstSpawnList                                     0x928C14
#define pinstSpellManager                                  0x946A48
#define pinstSpellSets                                     0x9269C4
#define pinstStringTable                                   0x928C00
#define pinstSwitchManager                                 0x8C63E4
#define pinstTarget                                        0x928C58
#define pinstTargetSwitch                                  0x928C60
#define pinstTradeTarget                                   0x928C34
#define instTributeActive                                  0x8120FD
#define pinstWorldData                                     0x928C10


////
//Section 2:  UI Related Offsets
////
#define pinstCTextOverlay                                  0x75E880
#define pinstCharacterSelect                               0x812D0C
#define pinstCFacePick                                     0x812D10
#define pinstCNoteWnd                                      0x812D14
#define pinstCBookWnd                                      0x812D18
#define pinstCPetInfoWnd                                   0x812D1C
#define pinstCTrainWnd                                     0x812D20
#define pinstCSkillsWnd                                    0x812D24
#define pinstCSkillsSelectWnd                              0x812D28
#define pinstCCombatSkillSelectWnd                         0x812D2C
#define pinstCFriendsWnd                                   0x812D30
#define pinstCAAWnd                                        0x812D3C
#define pinstCGroupSearchFiltersWnd                        0x812D40
#define pinstCLoadskinWnd                                  0x812D44
#define pinstCAlarmWnd                                     0x812D48
#define pinstCMusicPlayerWnd                               0x812D4C
#define pinstCRaidWnd                                      0x812D5C
#define pinstCRaidOptionsWnd                               0x812D60
#define pinstCBreathWnd                                    0x812D64
#define pinstCMapViewWnd                                   0x812D68
#define pinstCMapToolbarWnd                                0x812D6C
#define pinstCEditLabelWnd                                 0x812D70
#define pinstCTargetWnd                                    0x812D74
#define pinstCHotButtonWnd                                 0x812D78
#define pinstCColorPickerWnd                               0x812D7C
#define pinstCPlayerWnd                                    0x812D80
#define pinstCOptionsWnd                                   0x812D84
#define pinstCBuffWindowNORMAL                             0x812D88
#define pinstCBuffWindowSHORT                              0x812D8C
#define pinstCharacterCreation                             0x812D90
#define pinstCCursorAttachment                             0x812D94
#define pinstCCastingWnd                                   0x812D98
#define pinstCCastSpellWnd                                 0x812D9C
#define pinstCSpellBookWnd                                 0x812DA0
#define pinstCInventoryWnd                                 0x812DA4
#define pinstCBankWnd                                      0x812DA8
#define pinstCQuantityWnd                                  0x812DAC
#define pinstCLootWnd                                      0x812DB0
#define pinstCActionsWnd                                   0x812DB4
#define pinstCCombatAbilityWnd                             0x812DB8
#define pinstCMerchantWnd                                  0x812DBC
#define pinstCTradeWnd                                     0x812DC0
#define pinstCSelectorWnd                                  0x812DC4
#define pinstCBazaarWnd                                    0x812DC8
#define pinstCBazaarSearchWnd                              0x812DCC
#define pinstCGiveWnd                                      0x812DD0
#define pinstCTrackingWnd                                  0x812DD4
#define pinstCInspectWnd                                   0x812DD8
#define pinstCSocialEditWnd                                0x812DDC
#define pinstCFeedbackWnd                                  0x812DE0
#define pinstCBugReportWnd                                 0x812DE4
#define pinstCVideoModesWnd                                0x812DE8
#define pinstCTextEntryWnd                                 0x812DF0
#define pinstCFileSelectionWnd                             0x812DF4
#define pinstCCompassWnd                                   0x812DF8
#define pinstCPlayerNotesWnd                               0x812DFC
#define pinstCGemsGameWnd                                  0x812E00
#define pinstCTimeLeftWnd                                  0x812E04
#define pinstCPetitionQWnd                                 0x812E08
#define pinstCSoulmarkWnd                                  0x812E0C
#define pinstCStoryWnd                                     0x812E10
#define pinstCJournalTextWnd                               0x812E14
#define pinstCJournalCatWnd                                0x812E18
#define pinstCBodyTintWnd                                  0x812E1C
#define pinstCInvSlotMgr                                   0x812E28
#define pinstCContainerMgr                                 0x812E2C
#define pinstCAdventureLeaderboardWnd                      0x952130
#define pinstCAdventureMerchantWnd                         0x75E864
#define pinstCAdventureRequestWnd                          0x95214C
#define pinstCAdventureStatsWnd                            0x952168
#define pinstCChatManager                                  0x952520
#define pinstCDynamicZoneWnd                               0x9525FC
#define pinstCFindLocationWnd                              0x9526C8
#define pinstCGroupSearchWnd                               0x95275C
#define pinstCGroupWnd                                     0x952778
#define pinstCGuildMgmtWnd                                 0x9527B0
#define pinstCItemDisplayManager                           0x95287C
#define pinstCLeadershipWnd                                0x9528F8
#define pinstCPopupWndManager                              0x952B18
#define pinstCSystemInfoDialogBox                          0x953470
#define pinstCTargetOfTargetWnd                            0x95348C
#define pinstCTipWndOFDAY                                  0x95357C
#define pinstCTipWndCONTEXT                                0x953580
#define pinstCTradeskillWnd                                0x9535F8
#define pinstCTributeBenefitWnd                            0x953644
#define pinstCTributeMasterWnd                             0x953660
#define pinstCContextMenuManager                           0x95E0B4
// unknown window added 4-14 exe 0x79A234


////
// Section 3: Miscellaneous Offsets
////
#define __CastRay                                          0x474787
#define __ConvertItemTags                                  0x46D857
#define __ExecuteCmd                                       0x460048
#define __get_melee_range                                  0x464481
#define __GetGaugeValueFromEQ                              0x547878
#define __GetLabelFromEQ                                   0x548347
#define __LoadSplashScreen                                 0x5DB2E0
#define __NewUIINI                                         0x548150
#define __ProcessGameEvents                                0x4AA949
#define __SendMessage                                      0x491911
#define CrashDetected                                      0x4C673D
#define DrawNetStatus                                      0x4B9F3B


////
// Section 4: Function Offsets
////
// AltAdvManager
#define AltAdvManager__GetCalculatedTimer                  0x42A67C
#define AltAdvManager__IsAbilityReady                      0x42A6AA
#define AltAdvManager__GetAltAbility                       0x42A7BF

// CBankWnd
#define CBankWnd__GetNumBankSlots                          0x4D4398

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg                  0x4DBE99

// CButtonWnd
#define CButtonWnd__SetCheck                               0x5A3550

// CChatManager
#define CChatManager__GetRGBAFromIndex                     0x4E8D90
#define CChatManager__InitContextMenu                      0x4E8E74

// CChatWindow
#define CChatWindow__CChatWindow                           0x4EC8B2

// CComboWnd
#define CComboWnd__DeleteAll                               0x5A7280
#define CComboWnd__Draw                                    0x5A7470
#define CComboWnd__GetButtonRect                           0x5A72B0
#define CComboWnd__GetCurChoice                            0x5A7240
#define CComboWnd__GetListRect                             0x5A7710
#define CComboWnd__GetTextRect                             0x5A7300
#define CComboWnd__InsertChoice                            0x5A7770
#define CComboWnd__SetColors                               0x5A71D0
#define CComboWnd__SetChoice                               0x5A7200

// CContainerWnd
#define CContainerWnd__HandleCombine                       0x4F21B3
#define CContainerWnd__vftable                             0x620938

// CDisplay
#define CDisplay__CleanGameUI                              0x41FC68
#define CDisplay__GetClickedActor                          0x41C6A9
#define CDisplay__GetUserDefinedColor                      0x41BC0D
#define CDisplay__GetWorldFilePath                         0x41B3E1
#define CDisplay__ReloadUI                                 0x428213
#define CDisplay__WriteTextHD2                             0x420FB3

// CEditBaseWnd
#define CEditBaseWnd__SetMaxChars                          0x4D0B0F
#define CEditBaseWnd__SetSel                               0x5A2600

// CEditWnd
#define CEditWnd__DrawCaret                                0x5A8EE0
#define CEditWnd__GetCharIndexPt                           0x5A9CD0
#define CEditWnd__GetDisplayString                         0x5A9070
#define CEditWnd__GetHorzOffset                            0x5A92E0
#define CEditWnd__GetLineForPrintableChar                  0x5A97B0
#define CEditWnd__GetSelStartPt                            0x5A9F10
#define CEditWnd__GetSTMLSafeText                          0x5A9470
#define CEditWnd__PointFromPrintableChar                   0x5A98C0
#define CEditWnd__SelectableCharFromPoint                  0x5A9A30
#define CEditWnd__SetEditable                              0x5A9440

// CEverQuest
#define CEverQuest__ClickedPlayer                          0x496BFD
#define CEverQuest__DropHeldItemOnGround                   0x49DAD0
#define CEverQuest__dsp_chat                               0x4988EE
#define CEverQuest__EnterZone                              0x4A944A
#define CEverQuest__GetBodyTypeDesc                        0x492A92
#define CEverQuest__GetClassDesc                           0x4924B5
#define CEverQuest__GetClassThreeLetterCode                0x49292F
#define CEverQuest__GetDeityDesc                           0x494525
#define CEverQuest__GetRaceDesc                            0x492D97
#define CEverQuest__InterpretCmd                           0x4A300C
#define CEverQuest__LeftClickedOnPlayer                    0x4A7DA2
#define CEverQuest__RightClickedOnPlayer                   0x4A81D8
#define CEverQuest__SetGameState                           0x496C6E

// CGaugeWnd
#define CGaugeWnd__CalcFillRect                            0x4FA13F
#define CGaugeWnd__CalcLinesFillRect                       0x4FA19B
#define CGaugeWnd__Draw                                    0x4FA49B

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton                         0x509E78

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot                           0x50D736
#define CInvSlotMgr__MoveItem                              0x50D864

// CItemDisplayWnd
#define CItemDisplayWnd__SetItem                           0x51143A
#define CItemDisplayWnd__SetSpell                          0x510335

// CLabel
#define CLabel__Draw                                       0x5177F3

// CListWnd
#define CListWnd__AddColumn                                0x5979B0
#define CListWnd__AddColumn1                               0x5974F0
#define CListWnd__AddLine                                  0x597080
#define CListWnd__AddString                                0x597250
#define CListWnd__CalculateFirstVisibleLine                0x594670
#define CListWnd__CalculateVSBRange                        0x5961B0
#define CListWnd__ClearAllSel                              0x593EB0
#define CListWnd__CloseAndUpdateEditWindow                 0x594C90
#define CListWnd__Compare                                  0x595000
#define CListWnd__Draw                                     0x595EC0
#define CListWnd__DrawColumnSeparators                     0x595D40
#define CListWnd__DrawHeader                               0x594080
#define CListWnd__DrawItem                                 0x595710
#define CListWnd__DrawLine                                 0x595A80
#define CListWnd__DrawSeparator                            0x595DE0
#define CListWnd__EnsureVisible                            0x5946C0
#define CListWnd__ExtendSel                                0x595640
#define CListWnd__GetColumnFlags                           0x593A50
#define CListWnd__GetColumnJustification                   0x593BC0
#define CListWnd__GetColumnMinWidth                        0x593B60
#define CListWnd__GetColumnWidth                           0x593AA0
#define CListWnd__GetCurSel                                0x5935F0
#define CListWnd__GetHeaderRect                            0x593700
#define CListWnd__GetItemAtPoint                           0x5949A0
#define CListWnd__GetItemAtPoint1                          0x594A10
#define CListWnd__GetItemData                              0x5938D0
#define CListWnd__GetItemHeight                            0x594410
#define CListWnd__GetItemIcon                              0x593990
#define CListWnd__GetItemRect                              0x594790
#define CListWnd__GetItemText                              0x593910
#define CListWnd__GetSelList                               0x5973D0
#define CListWnd__GetSeparatorRect                         0x594F50
#define CListWnd__IsLineEnabled                            0x593F90
#define CListWnd__RemoveLine                               0x597380
#define CListWnd__SetColors                                0x593670
#define CListWnd__SetColumnJustification                   0x593C10
#define CListWnd__SetColumnWidth                           0x593B20
#define CListWnd__SetCurSel                                0x593630
#define CListWnd__SetItemColor                             0x596CB0
#define CListWnd__SetItemData                              0x593F50
#define CListWnd__SetItemText                              0x596C30
#define CListWnd__ShiftColumnSeparator                     0x5955B0
#define CListWnd__Sort                                     0x5979E0
#define CListWnd__ToggleSel                                0x593E20

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd                           0x52764B

// CMerchantWnd
#define CMerchantWnd__DisplayBuyOrSellPrice                0x528B21
#define CMerchantWnd__RequestBuyItem                       0x529B8F
#define CMerchantWnd__RequestSellItem                      0x528E89
#define CMerchantWnd__SelectBuySellSlot                    0x5298F5

// CSidlManager
#define CSidlManager__FindScreenPieceTemplate1             0x5A09B0

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateHSBRange                  0x5835B0
#define CSidlScreenWnd__CalculateVSBRange                  0x5834F0
#define CSidlScreenWnd__ConvertToRes                       0x583CF0
#define CSidlScreenWnd__CreateChildrenFromSidl             0x5845A0
#define CSidlScreenWnd__CSidlScreenWnd1                    0x585860
#define CSidlScreenWnd__CSidlScreenWnd2                    0x585910
#define CSidlScreenWnd__dCSidlScreenWnd                    0x5850C0
#define CSidlScreenWnd__DrawSidlPiece                      0x5842C0
#define CSidlScreenWnd__EnableIniStorage                   0x583CA0
#define CSidlScreenWnd__GetSidlPiece                       0x584480
#define CSidlScreenWnd__Init1                              0x585680
#define CSidlScreenWnd__LoadIniInfo                        0x584650
#define CSidlScreenWnd__LoadIniListWnd                     0x583E50
#define CSidlScreenWnd__LoadSidlScreen                     0x584120
#define CSidlScreenWnd__SetScreen                          0x5851D0
#define CSidlScreenWnd__StoreIniInfo                       0x5837F0
#define CSidlScreenWnd__WndNotification                    0x584220

// CSliderWnd
#define CSliderWnd__GetValue                               0x5A7A90
#define CSliderWnd__SetValue                               0x5A7C10
#define CSliderWnd__UpdateThumb                            0x5A7A50

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet                         0x54630A

// CStmlWnd
#define CStmlWnd__AppendSTML                               0x592B20
#define CStmlWnd__CalculateHSBRange                        0x58B510
#define CStmlWnd__CalculateVSBRange                        0x58B4B0
#define CStmlWnd__CanBreakAtCharacter                      0x58B650
#define CStmlWnd__CanGoBackward                            0x58B6D0
#define CStmlWnd__FastForwardToEndOfTag                    0x5C57B0
#define CStmlWnd__GetNextChar                              0x57D1E0
#define CStmlWnd__GetNextTagPiece                          0x58C0A0
#define CStmlWnd__GetSTMLText                              0x4EC894
#define CStmlWnd__GetThisChar                              0x5C4F80
#define CStmlWnd__GetVisiableText                          0x58D590
#define CStmlWnd__InitializeWindowVariables                0x58F280
#define CStmlWnd__MakeStmlColorTag                         0x58AB50
#define CStmlWnd__MakeWndNotificationTag                   0x58ABF0
#define CStmlWnd__StripFirstSTMLLines                      0x5928B0
#define CStmlWnd__UpdateHistoryString                      0x58D9E0

// CTabWnd
#define CTabWnd__Draw                                      0x5A6CD0
#define CTabWnd__DrawCurrentPage                           0x5A67B0
#define CTabWnd__DrawTab                                   0x5A65B0
#define CTabWnd__GetCurrentPage                            0x5A6A40
#define CTabWnd__GetCurrentTabIndex                        0x5A6270
#define CTabWnd__GetNumTabs                                0x5A6260
#define CTabWnd__GetPageClientRect                         0x5A6280
#define CTabWnd__GetPageFromTabIndex                       0x5A6500
#define CTabWnd__GetPageInnerRect                          0x5A62E0
#define CTabWnd__GetTabInnerRect                           0x5A6480
#define CTabWnd__GetTabRect                                0x5A6390
#define CTabWnd__IndexInBounds                             0x5A6370
#define CTabWnd__InsertPage                                0x5A6ED0
#define CTabWnd__SetPage                                   0x5A6A50
#define CTabWnd__SetPageRect                               0x5A6C20
#define CTabWnd__UpdatePage                                0x5A6E50

// CTextOverlay
#define CTextOverlay__DisplayText                          0x40204F

// CTextureFont
#define CTextureFont__DrawWrappedText                      0x58A6E0

// CXMLDataManager
#define CXMLDataManager__GetXMLData                        0x5AE520

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead                       0x5832B0

// CXRect
#define CXRect__CenterPoint                                0x4D3BFB

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr                                       0x401C88
#define CXStr__CXStr1                                      0x52C53E
#define CXStr__CXStr3                                      0x55D9E0
#define CXStr__dCXStr                                      0x418936
#define CXStr__operator_equal1                             0x55DBA0
#define CXStr__operator_plus_equal1                        0x55E9E0

// CXWnd
#define CXWnd__BringToTop                                  0x585F50
#define CXWnd__Center                                      0x5893A0
#define CXWnd__ClrFocus                                    0x585CA0
#define CXWnd__DoAllDrawing                                0x589F90
#define CXWnd__DrawChildren                                0x58A0C0
#define CXWnd__DrawColoredRect                             0x586170
#define CXWnd__DrawTooltipAtPoint                          0x589210
#define CXWnd__GetBorderFrame                              0x5865D0
#define CXWnd__GetChildWndAt                               0x588DC0
#define CXWnd__GetClientClipRect                           0x586500
#define CXWnd__GetFirstChildWnd                            0x585FE0
#define CXWnd__GetNextChildWnd                             0x588DA0
#define CXWnd__GetNextSib                                  0x586000
#define CXWnd__GetScreenClipRect                           0x589630
#define CXWnd__GetScreenRect                               0x5867A0
#define CXWnd__GetTooltipRect                              0x589160
#define CXWnd__GetWindowTextA                              0x4CAF7A
//#define CXWnd__GetXMLTooltip                               0x0
#define CXWnd__IsActive                                    0x586570
#define CXWnd__IsDescendantOf                              0x586580
#define CXWnd__IsReallyVisible                             0x588D80
#define CXWnd__IsType                                      0x589F30
#define CXWnd__Move                                        0x588930
#define CXWnd__Move1                                       0x5889C0
#define CXWnd__ProcessTransition                           0x585F10
#define CXWnd__Refade                                      0x585D40
#define CXWnd__Resize                                      0x589770
#define CXWnd__Right                                       0x589510
#define CXWnd__SetFirstChildPointer                        0x5869F0
#define CXWnd__SetFocus                                    0x587CB0
#define CXWnd__SetKeyTooltip                               0x586A30
#define CXWnd__SetMouseOver                                0x586A10
#define CXWnd__SetNextSibPointer                           0x586A00
#define CXWnd__StartFade                                   0x585F70

// CXWndManager
#define CXWndManager__DrawCursor                           0x59A160
#define CXWndManager__DrawWindows                          0x599E20
#define CXWndManager__GetFirstChildWnd                     0x599760
#define CXWndManager__GetKeyboardFlags                     0x598C20
#define CXWndManager__HandleKeyboardMsg                    0x5990F0
#define CXWndManager__RemoveWnd                            0x599000

// EQ_Character
#define EQ_Character__CastSpell                            0x43B41B
#define EQ_Character__Cur_HP                               0x42E741
#define EQ_Character__GetAACastingTimeModifier             0x437574
#define EQ_Character__GetFocusCastingTimeModifier          0x4370DD
#define EQ_Character__Max_Endurance                        0x42B21C
#define EQ_Character__Max_HP                               0x42AFC9
#define EQ_Character__Max_Mana                             0x4444A7
#define EQ_Character__doCombatAbility                      0x4448D2

// EQ_Item
#define EQ_Item__CanDrop                                   0x441A77
#define EQ_Item__GetItemLinkHash                           0x441669
#define EQ_Item__IsStackable                               0x441C1B

// EQ_LoadingS
#define EQ_LoadingS__WriteTextHD                           0x442188

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney                      0x446C19

// EQItemList
#define EQItemList__dEQItemList                            0x462BDD
#define EQItemList__EQItemList                             0x462B61

// EQPlayer
#define EQPlayer__ChangeBoneStringSprite                   0x479014
#define EQPlayer__dEQPlayer                                0x48241F
#define EQPlayer__DoAttack                                 0x480479
#define EQPlayer__EQPlayer                                 0x482A0F
#define EQPlayer__SetNameSpriteState                       0x47B99E
#define EQPlayer__SetNameSpriteTint                        0x479080

// KeyPressHandler
#define KeypressHandler__AttachAltKeyToEqCommand           0x4B4BDB
#define KeypressHandler__AttachKeyToEqCommand              0x4B4BA8
#define KeypressHandler__ClearCommandStateArray            0x4B49F3
#define KeypressHandler__HandleKeyDown                     0x4B384E
#define KeypressHandler__HandleKeyUp                       0x4B3AC5
#define KeypressHandler__SaveKeymapping                    0x4B4A78

// MapViewMap
#define MapViewMap__Clear                                  0x523DC4
#define MapViewMap__SaveEx                                 0x524581

// StringTable
#define StringTable__getString                             0x5CAF10 
