/******************************************************************************
    MQ2Main.dll: MacroQuest2's extension DLL for EverQuest
    Copyright (C) 2002-2003 Plazmic, 2003-2005 Lax

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License, version 2, as
    published by the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
******************************************************************************/
#ifdef PRIVATE
#include "eqgame-private.h"
#endif

#define __ClientName                                      "eqgame"
#define __ExpectedVersionDate                             "May 17 2005"
#define __ExpectedVersionTime                             "09:28:11"
#define __ActualVersionDate                                0x61E4B4
#define __ActualVersionTime                                0x61E4C0

#define __ClientOverride                                   0
#define __MacroQuestWinClassName                          "__MacroQuestTray"
#define __MacroQuestWinName                               "MacroQuest"

// Memory Protection
#define __MemChecker0                                      0x5143CB
#define __MemChecker2                                      0x5531BA
#define __MemChecker3                                      0x553247
#define __MemChecker4                                      0x5CF620
#define __EncryptPad0                                      0x742850
#define __EncryptPad2                                      0x746150
#define __EncryptPad3                                      0x746550
#define __EncryptPad4                                      0x74AF30

// Direct Input
#define DI8__Main                                          0x942F3C
#define DI8__Keyboard                                      0x942F40
#define DI8__Mouse                                         0x942F44

#define __AltTimerReady                                    0x8B57BA
#define __Attack                                           0x9152D0
#define __BindList                                         0x649EA8
#define __Clicks                                           0x8B49C4
#define __CommandList                                      0x64A448
#define __CurrentMapLabel                                  0x935274
#define __CurrentSocial                                    0x64D8E8
#define __DoAbilityAvailable                               0x8B5754
#define __DoAbilityList                                    0x8EE528
#define __DrawHandler                                      0x94CF84
#define __EQP_IDArray                                      0x802B60
#define __FriendsList                                      0x8EB2E8
#define __GroupCount                                       0x915660
#define __GroupLeader                                      0x9157BC
#define __Guilds                                           0x91D0A8
#define __gWorld                                           0x9170B8
#define __HotkeyPage                                       0x914E88
#define __HWnd                                             0x8B48C0
#define __IgnoreList                                       0x8ECBE8
#define __InChatMode                                       0x8B4900
#define __LastTell                                         0x8B6A54
#define __Mouse                                            0x942F48
#define __MouseLook                                        0x8B4992
#define __NetStatusToggle                                  0x8B4994
#define __PCNames                                          0x8B5AB0
#define __RangeAttackReady                                 0x8B57B8
#define __RunWalkState                                     0x8B4904
#define __ScreenMode                                       0x8006D8
#define __ScreenX                                          0x8B48C8
#define __ScreenY                                          0x8B48CC
#define __ServerHost                                       0x91551C
#define __ServerName                                       0x8EE4E8
#define __ShowNames                                        0x8B59A0
#define __SkillDict                                        0x805EF0
#define __Socials                                          0x8EE5E8

////
//Section 1: Vital Offsets
////
#define instCRaid                                          0x917150
#define instEQZoneInfo                                     0x8B4B30
#define instKeypressHandler                                0x934F0C
#define pinstActiveBanker                                  0x917130
#define pinstActiveCorpse                                  0x917134
#define pinstActiveGMaster                                 0x917138
#define pinstActiveMerchant                                0x91712C
#define pinstAltAdvManager                                 0x805A98
#define pinstCDisplay                                      0x917140
#define pinstCEverQuest                                    0x9430B0
#define pinstCharData                                      0x91711C
#define pinstCharSpawn                                     0x917114
#define pinstControlledPlayer                              0x917114
#define pinstCSidlManager                                  0x94C38C
#define pinstCXWndManager                                  0x94C384
#define pinstEQItemList                                    0x9170E0
#define instGroup                                          0x915660
#define pinstLocalPlayer                                   0x917100
#define pinstPCData                                        0x91711C
#define pinstSelectedItem                                  0x934E8C
#define pinstSpawnList                                     0x9170DC
#define pinstSpellManager                                  0x9355D8
#define pinstSpellSets                                     0x914E8C
#define pinstStringTable                                   0x9170C8
#define pinstSwitchManager                                 0x805A94
#define pinstTarget                                        0x917120
#define pinstTargetSwitch                                  0x917128
#define pinstTradeTarget                                   0x9170FC
#define instTributeActive                                  0x7F4C9D
#define pinstWorldData                                     0x9170D8


////
//Section 2:  UI Related Offsets
////
#define pinstCTextOverlay                                  0x74CB80
#define pinstCharacterSelect                               0x80116C
#define pinstCFacePick                                     0x801170
#define pinstCNoteWnd                                      0x801174
#define pinstCHelpWnd                                      0x801178
#define pinstCBookWnd                                      0x80117C
#define pinstCPetInfoWnd                                   0x801180
#define pinstCTrainWnd                                     0x801184
#define pinstCSkillsWnd                                    0x801188
#define pinstCSkillsSelectWnd                              0x80118C
#define pinstCCombatSkillSelectWnd                         0x801190
#define pinstCFriendsWnd                                   0x801194
#define pinstCAAWnd                                        0x8011A0
#define pinstCGroupSearchFiltersWnd                        0x8011A4
#define pinstCLoadskinWnd                                  0x8011A8
#define pinstCAlarmWnd                                     0x8011AC
#define pinstCMusicPlayerWnd                               0x8011B0
#define pinstCRaidWnd                                      0x8011C0
#define pinstCRaidOptionsWnd                               0x8011C4
#define pinstCBreathWnd                                    0x8011C8
#define pinstCMapViewWnd                                   0x8011CC
#define pinstCMapToolbarWnd                                0x8011D0
#define pinstCEditLabelWnd                                 0x8011D4
#define pinstCTargetWnd                                    0x8011D8
#define pinstCHotButtonWnd                                 0x8011DC
#define pinstCColorPickerWnd                               0x8011E0
#define pinstCPlayerWnd                                    0x8011E4
#define pinstCOptionsWnd                                   0x8011E8
#define pinstCBuffWindowNORMAL                             0x8011EC
#define pinstCBuffWindowSHORT                              0x8011F0
#define pinstCharacterCreation                             0x8011F4
#define pinstCCursorAttachment                             0x8011F8
#define pinstCCastingWnd                                   0x8011FC
#define pinstCCastSpellWnd                                 0x801200
#define pinstCSpellBookWnd                                 0x801204
#define pinstCInventoryWnd                                 0x801208
#define pinstCBankWnd                                      0x80120C
#define pinstCQuantityWnd                                  0x801210
#define pinstCLootWnd                                      0x801214
#define pinstCActionsWnd                                   0x801218
#define pinstCCombatAbilityWnd                             0x80121C
#define pinstCMerchantWnd                                  0x801220
#define pinstCTradeWnd                                     0x801224
#define pinstCSelectorWnd                                  0x801228
#define pinstCBazaarWnd                                    0x80122C
#define pinstCBazaarSearchWnd                              0x801230
#define pinstCGiveWnd                                      0x801234
#define pinstCTrackingWnd                                  0x801238
#define pinstCInspectWnd                                   0x80123C
#define pinstCSocialEditWnd                                0x801240
#define pinstCFeedbackWnd                                  0x801244
#define pinstCBugReportWnd                                 0x801248
#define pinstCVideoModesWnd                                0x80124C
#define pinstCTextEntryWnd                                 0x801254
#define pinstCFileSelectionWnd                             0x801258
#define pinstCCompassWnd                                   0x80125C
#define pinstCPlayerNotesWnd                               0x801260
#define pinstCGemsGameWnd                                  0x801264
#define pinstCTimeLeftWnd                                  0x801268
#define pinstCPetitionQWnd                                 0x80126C
#define pinstCSoulmarkWnd                                  0x801270
#define pinstCStoryWnd                                     0x801274
#define pinstCJournalTextWnd                               0x801278
#define pinstCJournalCatWnd                                0x80127C
#define pinstCBodyTintWnd                                  0x801280
#define pinstCInvSlotMgr                                   0x801288
#define pinstCContainerMgr                                 0x80128C
#define pinstCAdventureLeaderboardWnd                      0x74C82C
#define pinstCAdventureMerchantWnd                         0x74C848
#define pinstCAdventureRequestWnd                          0x74C864
#define pinstCAdventureStatsWnd                            0x74C880
#define pinstCChatManager                                  0x74E284
#define pinstCDynamicZoneWnd                               0x80139C
#define pinstCFindLocationWnd                              0x934C90
#define pinstCGroupSearchWnd                               0x934D88
#define pinstCGroupWnd                                     0x934DA4
#define pinstCGuildMgmtWnd                                 0x934DDC
#define pinstCItemDisplayManager                           0x934EC0
#define pinstCLeadershipWnd                                0x934FA8
#define pinstCPopupWndManager                              0x9353D0
#define pinstCSystemInfoDialogBox                          0x935D80
#define pinstCTargetOfTargetWnd                            0x935DA4
#define pinstCTipWndOFDAY                                  0x935E94
#define pinstCTipWndCONTEXT                                0x935E98
#define pinstCTradeskillWnd                                0x935F90
#define pinstCTributeBenefitWnd                            0x935FDC
#define pinstCTributeMasterWnd                             0x935FF8
#define pinstCContextMenuManager                           0x94C3E4
// unknown window added 4-14 exe 0x79A234


////
// Section 3: Miscellaneous Offsets
////
#define __CastRay                                          0x473010
#define __ConvertItemTags                                  0x472817
#define __ExecuteCmd                                       0x4650E2
#define __get_melee_range                                  0x469485
#define __GetGaugeValueFromEQ                              0x53B71C
#define __GetLabelFromEQ                                   0x53C1EB
#define __LoadSplashScreen                                 0x5D6750
#define __NewUIINI                                         0x53BFF4
#define __ProcessGameEvents                                0x4D4B30
#define __SendMessage                                      0x4BBACC
#define CrashDetected                                      0x552E76
#define DrawNetStatus                                      0x519430


////
// Section 4: Function Offsets
////
// AltAdvManager
#define AltAdvManager__GetCalculatedTimer                  0x4970FC
#define AltAdvManager__IsAbilityReady                      0x49712A

// CBankWnd
#define CBankWnd__GetNumBankSlots                          0x40BCAF

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg                  0x41339E

// CButtonWnd
#define CButtonWnd__SetCheck                               0x596B40

// CChatManager
#define CChatManager__GetRGBAFromIndex                     0x42516C
#define CChatManager__InitContextMenu                      0x425250

// CChatWindow
#define CChatWindow__CChatWindow                           0x428258

// CComboWnd
#define CComboWnd__DeleteAll                               0x597800
#define CComboWnd__Draw                                    0x597A00
#define CComboWnd__GetButtonRect                           0x597830
#define CComboWnd__GetCurChoice                            0x5977C0
#define CComboWnd__GetListRect                             0x597DF0
#define CComboWnd__GetTextRect                             0x597890
#define CComboWnd__InsertChoice                            0x597E50
#define CComboWnd__SetColors                               0x597750
#define CComboWnd__SetChoice                               0x597780

// CContainerWnd
#define CContainerWnd__HandleCombine                       0x438103
#define CContainerWnd__vftable                             0x605748

// CDisplay
#define CDisplay__CleanGameUI                              0x447345
#define CDisplay__GetClickedActor                          0x443F35
#define CDisplay__GetUserDefinedColor                      0x443499
#define CDisplay__GetWorldFilePath                         0x442C6D
#define CDisplay__ReloadUI                                 0x44F406
#define CDisplay__WriteTextHD2                             0x448630

// CEditBaseWnd
#define CEditBaseWnd__SetMaxChars                          0x408146
#define CEditBaseWnd__SetSel                               0x5A88A0

// CEditWnd
#define CEditWnd__DrawCaret                                0x5A4970
#define CEditWnd__GetCharIndexPt                           0x5A57C0
#define CEditWnd__GetDisplayString                         0x5A4AD0
#define CEditWnd__GetHorzOffset                            0x5A4D40
#define CEditWnd__GetLineForPrintableChar                  0x5A5260
#define CEditWnd__GetSelStartPt                            0x5A5A00
#define CEditWnd__GetSTMLSafeText                          0x5A4F20
#define CEditWnd__PointFromPrintableChar                   0x5A5370
#define CEditWnd__SelectableCharFromPoint                  0x5A54F0
#define CEditWnd__SetEditable                              0x5A4EF0

// CEverQuest
#define CEverQuest__ClickedPlayer                          0x4C0D9C
#define CEverQuest__DropHeldItemOnGround                   0x4C7D0E
#define CEverQuest__dsp_chat                               0x4C2A8A
#define CEverQuest__EnterZone                              0x4D3631
#define CEverQuest__GetBodyTypeDesc                        0x4BCC47
#define CEverQuest__GetClassDesc                           0x4BC66A
#define CEverQuest__GetClassThreeLetterCode                0x4BCAE4
#define CEverQuest__GetDeityDesc                           0x4BE6DA
#define CEverQuest__GetRaceDesc                            0x4BCF4C
#define CEverQuest__InterpretCmd                           0x4CD24A
#define CEverQuest__LeftClickedOnPlayer                    0x4D1F89
#define CEverQuest__RightClickedOnPlayer                   0x4D23BF
#define CEverQuest__SetGameState                           0x4C0E0D

// CGaugeWnd
#define CGaugeWnd__CalcFillRect                            0x4E07FC
#define CGaugeWnd__CalcLinesFillRect                       0x4E0858
#define CGaugeWnd__Draw                                    0x4E0B58

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton                         0x4F0C32

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot                           0x4F4442
#define CInvSlotMgr__MoveItem                              0x4F4570

// CItemDisplayWnd
#define CItemDisplayWnd__SetItem                           0x4F9600
#define CItemDisplayWnd__SetSpell                          0x4F8611

// CLabel
#define CLabel__Draw                                       0x500C28

// CListWnd
#define CListWnd__AddColumn                                0x580D60
#define CListWnd__AddColumn1                               0x5808E0
#define CListWnd__AddLine                                  0x580450
#define CListWnd__AddString                                0x580620
#define CListWnd__CalculateFirstVisibleLine                0x57D880
#define CListWnd__CalculateVSBRange                        0x57F520
#define CListWnd__ClearAllSel                              0x57CFF0
#define CListWnd__CloseAndUpdateEditWindow                 0x57DEC0
#define CListWnd__Compare                                  0x57E230
#define CListWnd__Draw                                     0x57F170
#define CListWnd__DrawColumnSeparators                     0x57EF90
#define CListWnd__DrawHeader                               0x57D200
#define CListWnd__DrawItem                                 0x57E940
#define CListWnd__DrawLine                                 0x57ECD0
#define CListWnd__DrawSeparator                            0x57F060
#define CListWnd__EnsureVisible                            0x57D8D0
#define CListWnd__ExtendSel                                0x57E870
#define CListWnd__GetColumnFlags                           0x57CB90
#define CListWnd__GetColumnJustification                   0x57CD00
#define CListWnd__GetColumnMinWidth                        0x57CCA0
#define CListWnd__GetColumnWidth                           0x57CBE0
#define CListWnd__GetCurSel                                0x57C750
#define CListWnd__GetHeaderRect                            0x57C840
#define CListWnd__GetItemAtPoint                           0x57DBB0
#define CListWnd__GetItemAtPoint1                          0x57DC20
#define CListWnd__GetItemData                              0x57CA10
#define CListWnd__GetItemHeight                            0x57D600
#define CListWnd__GetItemIcon                              0x57CAD0
#define CListWnd__GetItemRect                              0x57D9A0
#define CListWnd__GetItemText                              0x57CA50
#define CListWnd__GetSelList                               0x5807C0
#define CListWnd__GetSeparatorRect                         0x57E180
#define CListWnd__IsLineEnabled                            0x57D0D0
#define CListWnd__RemoveLine                               0x580770
#define CListWnd__SetColors                                0x57C7B0
#define CListWnd__SetColumnJustification                   0x57CD50
#define CListWnd__SetColumnWidth                           0x57CC60
#define CListWnd__SetCurSel                                0x57C790
#define CListWnd__SetItemColor                             0x580080
#define CListWnd__SetItemData                              0x57D090
#define CListWnd__SetItemText                              0x57FFC0
#define CListWnd__ShiftColumnSeparator                     0x57E7E0
#define CListWnd__Sort                                     0x580E00
#define CListWnd__ToggleSel                                0x57CF60

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd                           0x5133A7

// CMerchantWnd
#define CMerchantWnd__DisplayBuyOrSellPrice                0x514825
#define CMerchantWnd__RequestBuyItem                       0x5156AD
#define CMerchantWnd__RequestSellItem                      0x514B8D
#define CMerchantWnd__SelectBuySellSlot                    0x515413

// CSidlManager
#define CSidlManager__FindScreenPieceTemplate1             0x5A2980

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateHSBRange                  0x574AC0
#define CSidlScreenWnd__CalculateVSBRange                  0x574A00
#define CSidlScreenWnd__ConvertToRes                       0x5751F0
#define CSidlScreenWnd__CreateChildrenFromSidl             0x575B40
#define CSidlScreenWnd__CSidlScreenWnd1                    0x577100
#define CSidlScreenWnd__CSidlScreenWnd2                    0x5771F0
#define CSidlScreenWnd__dCSidlScreenWnd                    0x576730
#define CSidlScreenWnd__DrawSidlPiece                      0x575760
#define CSidlScreenWnd__EnableIniStorage                   0x5751A0
#define CSidlScreenWnd__GetSidlPiece                       0x575A00
#define CSidlScreenWnd__Init1                              0x576E50
#define CSidlScreenWnd__LoadIniInfo                        0x575BF0
#define CSidlScreenWnd__LoadIniListWnd                     0x575360
#define CSidlScreenWnd__LoadSidlScreen                     0x5755A0
#define CSidlScreenWnd__SetScreen                          0x576840
#define CSidlScreenWnd__StoreIniInfo                       0x574CF0
#define CSidlScreenWnd__WndNotification                    0x5756C0

// CSliderWnd
#define CSliderWnd__GetValue                               0x598240
#define CSliderWnd__SetValue                               0x598420
#define CSliderWnd__UpdateThumb                            0x598200

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet                         0x53978D

// CStmlWnd
#define CStmlWnd__AppendSTML                               0x58A190
#define CStmlWnd__CalculateHSBRange                        0x581BF0
#define CStmlWnd__CalculateVSBRange                        0x581B90
#define CStmlWnd__CanBreakAtCharacter                      0x581D30
#define CStmlWnd__CanGoBackward                            0x581DB0
#define CStmlWnd__FastForwardToEndOfTag                    0x582AE0
#define CStmlWnd__GetNextChar                              0x5821D0
#define CStmlWnd__GetNextTagPiece                          0x5828E0
#define CStmlWnd__GetSTMLText                              0x42823A
#define CStmlWnd__GetThisChar                              0x581A30
#define CStmlWnd__GetVisiableText                          0x5842A0
#define CStmlWnd__InitializeWindowVariables                0x586010
#define CStmlWnd__MakeStmlColorTag                         0x581100
#define CStmlWnd__MakeWndNotificationTag                   0x5811A0
#define CStmlWnd__StripFirstSTMLLines                      0x589F20
#define CStmlWnd__UpdateHistoryString                      0x5846F0

// CTabWnd
#define CTabWnd__Draw                                      0x58DD60
#define CTabWnd__DrawCurrentPage                           0x58D580
#define CTabWnd__DrawTab                                   0x58D300
#define CTabWnd__GetCurrentPage                            0x58DAD0
#define CTabWnd__GetCurrentTabIndex                        0x58CF70
#define CTabWnd__GetNumTabs                                0x58CF60
#define CTabWnd__GetPageClientRect                         0x58CF80
#define CTabWnd__GetPageFromTabIndex                       0x58D250
#define CTabWnd__GetPageInnerRect                          0x58CFE0
#define CTabWnd__GetTabInnerRect                           0x58D1B0
#define CTabWnd__GetTabRect                                0x58D0B0
#define CTabWnd__IndexInBounds                             0x58D090
#define CTabWnd__InsertPage                                0x58DF80
#define CTabWnd__SetPage                                   0x58DAE0
#define CTabWnd__SetPageRect                               0x58DCB0
#define CTabWnd__UpdatePage                                0x58DEF0

// CTextOverlay
#define CTextOverlay__DisplayText                          0x41796D

// CTextureFont
#define CTextureFont__DrawWrappedText                      0x57C2E0

// CXMLDataManager
#define CXMLDataManager__GetXMLData                        0x5A94E0

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead                       0x5958A0

// CXRect
#define CXRect__CenterPoint                                0x40B512

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr                                       0x401000
#define CXStr__CXStr1                                      0x519BCB
#define CXStr__CXStr3                                      0x556BB0
#define CXStr__dCXStr                                      0x408978
#define CXStr__operator_equal1                             0x556D70
#define CXStr__operator_plus_equal1                        0x557BB0

// CXWnd
#define CXWnd__BringToTop                                  0x5778B0
#define CXWnd__Center                                      0x57AF30
#define CXWnd__ClrFocus                                    0x577600
#define CXWnd__DoAllDrawing                                0x57BB40
#define CXWnd__DrawChildren                                0x57BC70
#define CXWnd__DrawColoredRect                             0x577AE0
#define CXWnd__DrawTooltipAtPoint                          0x57AD60
#define CXWnd__GetBorderFrame                              0x577F40
#define CXWnd__GetChildWndAt                               0x57A8F0
#define CXWnd__GetClientClipRect                           0x577E70
#define CXWnd__GetFirstChildWnd                            0x577940
#define CXWnd__GetNextChildWnd                             0x57A8D0
#define CXWnd__GetNextSib                                  0x577960
#define CXWnd__GetScreenClipRect                           0x57B1C0
#define CXWnd__GetScreenRect                               0x578110
#define CXWnd__GetTooltipRect                              0x57ACB0
#define CXWnd__GetWindowTextA                              0x402ABE
#define CXWnd__GetXMLTooltip                               0x577440
#define CXWnd__IsActive                                    0x577EE0
#define CXWnd__IsDescendantOf                              0x577EF0
#define CXWnd__IsReallyVisible                             0x57A8B0
#define CXWnd__IsType                                      0x57BAE0
#define CXWnd__Move                                        0x57A460
#define CXWnd__Move1                                       0x57A4F0
#define CXWnd__ProcessTransition                           0x577870
#define CXWnd__Refade                                      0x5776A0
#define CXWnd__Resize                                      0x57B300
#define CXWnd__Right                                       0x57B0A0
#define CXWnd__SetFirstChildPointer                        0x578360
#define CXWnd__SetFocus                                    0x579640
#define CXWnd__SetKeyTooltip                               0x5783A0
#define CXWnd__SetMouseOver                                0x578380
#define CXWnd__SetNextSibPointer                           0x578370
#define CXWnd__StartFade                                   0x5778D0

// CXWndManager
#define CXWndManager__DrawCursor                           0x59A4E0
#define CXWndManager__DrawWindows                          0x59A130
#define CXWndManager__GetFirstChildWnd                     0x599AB0
#define CXWndManager__GetKeyboardFlags                     0x598F50
#define CXWndManager__HandleKeyboardMsg                    0x599420
#define CXWndManager__RemoveWnd                            0x599330

// EQ_Character
#define EQ_Character__CastSpell                            0x4A7E32
#define EQ_Character__Cur_HP                               0x49B15C
#define EQ_Character__GetAACastingTimeModifier             0x4A3F8B
#define EQ_Character__GetFocusCastingTimeModifier          0x4A3AF4
#define EQ_Character__Max_Endurance                        0x497C37
#define EQ_Character__Max_HP                               0x4979E4
#define EQ_Character__Max_Mana                             0x4B115A

// EQ_Item
#define EQ_Item__CanDrop                                   0x4AE7C0
#define EQ_Item__GetItemLinkHash                           0x4AE3B2
#define EQ_Item__IsStackable                               0x4AE964

// EQ_LoadingS
#define EQ_LoadingS__WriteTextHD                           0x4AEEC7

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney                      0x4B3812

// EQItemList
#define EQItemList__dEQItemList                            0x467C66
#define EQItemList__EQItemList                             0x467BEA

// EQPlayer
#define EQPlayer__ChangeBoneStringSprite                   0x47E077
#define EQPlayer__dEQPlayer                                0x4874A9
#define EQPlayer__DoAttack                                 0x485503
#define EQPlayer__EQPlayer                                 0x487A99
#define EQPlayer__SetNameSpriteState                       0x480A4C
#define EQPlayer__SetNameSpriteTint                        0x47E0E3

// KeyPressHandler
#define KeypressHandler__AttachAltKeyToEqCommand           0x500A93
#define KeypressHandler__AttachKeyToEqCommand              0x500A60
#define KeypressHandler__ClearCommandStateArray            0x5008AB
#define KeypressHandler__HandleKeyDown                     0x4FF706
#define KeypressHandler__HandleKeyUp                       0x4FF97D
#define KeypressHandler__SaveKeymapping                    0x500930

// MapViewMap
#define MapViewMap__Clear                                  0x51019C
#define MapViewMap__SaveEx                                 0x510937

// StringTable
#define StringTable__getString                             0x5C5E70 
