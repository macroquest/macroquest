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
#define __ExpectedVersionDate                             "Jul  6 2005"               
#define __ExpectedVersionTime                             "17:48:42"     
#define __ActualVersionDate                                0x62BAF4
#define __ActualVersionTime                                0x62BB00

#define __ClientOverride                                   0
#define __MacroQuestWinClassName                          "__MacroQuestTray"
#define __MacroQuestWinName                               "MacroQuest"

// Memory Protection
#define __MemChecker0                                      0x5184A5
#define __MemChecker2                                      0x559EF3
#define __MemChecker3                                      0x559F80
#define __MemChecker4                                      0x5D4630
#define __EncryptPad0                                      0x7538A8
#define __EncryptPad2                                      0x757220
#define __EncryptPad3                                      0x757620
#define __EncryptPad4                                      0x75CF70

// Direct Input
#define DI8__Main                                          0x954F8C
#define DI8__Keyboard                                      0x954F90
#define DI8__Mouse                                         0x954F94

#define __AltTimerReady                                    0x8C7836
#define __Attack                                           0x927350
#define __BindList                                         0x65BEA8
#define __Clicks                                           0x8C6A3C
#define __CommandList                                      0x65C448
#define __CurrentMapLabel                                  0x94728C
#define __CurrentSocial                                    0x65F8E8
#define __DoAbilityAvailable                               0x8C77D0
#define __DoAbilityList                                    0x9005A8
#define __DrawHandler                                      0x95EFD4
#define __EQP_IDArray                                      0x814BD8
#define __FriendsList                                      0x8FD368
#define __GroupCount                                       0x9276E0
#define __GroupLeader                                      0x92783C
#define __Guilds                                           0x92F128
#define __gWorld                                           0x929138
#define __HotkeyPage                                       0x926F08
#define __HWnd                                             0x8C6938
#define __IgnoreList                                       0x8FEC68
#define __InChatMode                                       0x8C6978
#define __LastTell                                         0x8C8AD4
#define __Mouse                                            0x954F98
#define __MouseLook                                        0x8C6A0A
#define __NetStatusToggle                                  0x8C6A0C
#define __PCNames                                          0x8C7B2C
#define __RangeAttackReady                                 0x8C7834
#define __RunWalkState                                     0x8C697C
#define __ScreenMode                                       0x812750
#define __ScreenX                                          0x8C6940
#define __ScreenY                                          0x8C6944
#define __ServerHost                                       0x92759C
#define __ServerName                                       0x900568
#define __ShowNames                                        0x8C7A1C
#define __SkillDict                                        0x817F68
#define __Socials                                          0x900668

////
//Section 1: Vital Offsets
////
#define instCRaid                                          0x9291D0
#define instEQZoneInfo                                     0x8C6BA8
#define instKeypressHandler                                0x946F20
#define pinstActiveBanker                                  0x9291B0
#define pinstActiveCorpse                                  0x9291B4
#define pinstActiveGMaster                                 0x9291B8
#define pinstActiveMerchant                                0x9291AC
#define pinstAltAdvManager                                 0x817B10
#define pinstCDisplay                                      0x9291C0
#define pinstCEverQuest                                    0x955100
#define pinstCharData                                      0x92919C
#define pinstCharSpawn                                     0x929194
#define pinstControlledPlayer                              0x929194
#define pinstCSidlManager                                  0x95E3DC
#define pinstCXWndManager                                  0x95E3D4
#define pinstEQItemList                                    0x929160
#define instGroup                                          0x9276E0
#define pinstLocalPlayer                                   0x929180
#define pinstPCData                                        0x92919C
#define pinstSelectedItem                                  0x946EA0
#define pinstSpawnList                                     0x92915C
#define pinstSpellManager                                  0x947608
#define pinstSpellSets                                     0x926F0C
#define pinstStringTable                                   0x929148
#define pinstSwitchManager                                 0x817B0C
#define pinstTarget                                        0x9291A0
#define pinstTargetSwitch                                  0x9291A8
#define pinstTradeTarget                                   0x92917C
#define instTributeActive                                  0x8125BD
#define pinstWorldData                                     0x929158


////
//Section 2:  UI Related Offsets
////
#define pinstCTextOverlay                                  0x75EBD8
#define pinstCharacterSelect                               0x8131E4
#define pinstCFacePick                                     0x8131E8
#define pinstCNoteWnd                                      0x8131EC
#define pinstCBookWnd                                      0x8131F0
#define pinstCPetInfoWnd                                   0x8131F4
#define pinstCTrainWnd                                     0x8131F8
#define pinstCSkillsWnd                                    0x8131FC
#define pinstCSkillsSelectWnd                              0x813200
#define pinstCCombatSkillSelectWnd                         0x813204
#define pinstCFriendsWnd                                   0x813208
#define pinstCAAWnd                                        0x813214
#define pinstCGroupSearchFiltersWnd                        0x813218
#define pinstCLoadskinWnd                                  0x81321C
#define pinstCAlarmWnd                                     0x813220
#define pinstCMusicPlayerWnd                               0x813224
#define pinstCRaidWnd                                      0x813234
#define pinstCRaidOptionsWnd                               0x813238
#define pinstCBreathWnd                                    0x81323C
#define pinstCMapViewWnd                                   0x813240
#define pinstCMapToolbarWnd                                0x813244
#define pinstCEditLabelWnd                                 0x813248
#define pinstCTargetWnd                                    0x81324C
#define pinstCHotButtonWnd                                 0x813250
#define pinstCColorPickerWnd                               0x813254
#define pinstCPlayerWnd                                    0x813258
#define pinstCOptionsWnd                                   0x81325C
#define pinstCBuffWindowNORMAL                             0x813260
#define pinstCBuffWindowSHORT                              0x813264
#define pinstCharacterCreation                             0x813268
#define pinstCCursorAttachment                             0x81326C
#define pinstCCastingWnd                                   0x813270
#define pinstCCastSpellWnd                                 0x813274
#define pinstCSpellBookWnd                                 0x813278
#define pinstCInventoryWnd                                 0x81327C
#define pinstCBankWnd                                      0x813280
#define pinstCQuantityWnd                                  0x813284
#define pinstCLootWnd                                      0x813288
#define pinstCActionsWnd                                   0x81328C
#define pinstCCombatAbilityWnd                             0x813290
#define pinstCMerchantWnd                                  0x813294
#define pinstCTradeWnd                                     0x813298
#define pinstCSelectorWnd                                  0x81329C
#define pinstCBazaarWnd                                    0x8132A0
#define pinstCBazaarSearchWnd                              0x8132A4
#define pinstCGiveWnd                                      0x8132A8
#define pinstCTrackingWnd                                  0x8132AC
#define pinstCInspectWnd                                   0x8132B0
#define pinstCSocialEditWnd                                0x8132B4
#define pinstCFeedbackWnd                                  0x8132B8
#define pinstCBugReportWnd                                 0x8132BC
#define pinstCVideoModesWnd                                0x8132C0
#define pinstCTextEntryWnd                                 0x8132C8
#define pinstCFileSelectionWnd                             0x8132CC
#define pinstCCompassWnd                                   0x8132D0
#define pinstCPlayerNotesWnd                               0x8132D4
#define pinstCGemsGameWnd                                  0x8132D8
#define pinstCTimeLeftWnd                                  0x8132DC
#define pinstCPetitionQWnd                                 0x8132E0
#define pinstCSoulmarkWnd                                  0x8132E4
#define pinstCStoryWnd                                     0x8132E8
#define pinstCJournalTextWnd                               0x8132EC
#define pinstCJournalCatWnd                                0x8132F0
#define pinstCBodyTintWnd                                  0x8132F4
#define pinstCInvSlotMgr                                   0x813300
#define pinstCContainerMgr                                 0x813304
#define pinstCAdventureLeaderboardWnd                      0x75E86C
#define pinstCAdventureMerchantWnd                         0x75E888
#define pinstCAdventureRequestWnd                          0x75E8A4
#define pinstCAdventureStatsWnd                            0x75E8C0
#define pinstCChatManager                                  0x7602DC
#define pinstCDynamicZoneWnd                               0x813414
#define pinstCFindLocationWnd                              0x946CBC
#define pinstCGroupSearchWnd                               0x946DB4
#define pinstCGroupWnd                                     0x946DD0
#define pinstCGuildMgmtWnd                                 0x946E08
#define pinstCItemDisplayManager                           0x946ED4
#define pinstCLeadershipWnd                                0x946FBC
#define pinstCPopupWndManager                              0x947400
#define pinstCSystemInfoDialogBox                          0x947DB0
#define pinstCTargetOfTargetWnd                            0x947DD4
#define pinstCTipWndOFDAY                                  0x947EE0
#define pinstCTipWndCONTEXT                                0x947EE4
#define pinstCTradeskillWnd                                0x947FE0
#define pinstCTributeBenefitWnd                            0x94802C
#define pinstCTributeMasterWnd                             0x948048
#define pinstCContextMenuManager                           0x95E434
// unknown window added 4-14 exe 0x79A234


////
// Section 3: Miscellaneous Offsets
////
#define __CastRay                                          0x4767A3
#define __ConvertItemTags                                  0x475FC0
#define __ExecuteCmd                                       0x468832
#define __get_melee_range                                  0x46CBEA
#define __GetGaugeValueFromEQ                              0x541384
#define __GetLabelFromEQ                                   0x541E53
#define __LoadSplashScreen                                 0x5DC220
#define __NewUIINI                                         0x541C5C
#define __ProcessGameEvents                                0x4D82F5
#define __SendMessage                                      0x4BF31F
#define CrashDetected                                      0x559BAF
#define DrawNetStatus                                      0x51DDD7


////
// Section 4: Function Offsets
////
// AltAdvManager
#define AltAdvManager__GetCalculatedTimer                  0x49AAA0
#define AltAdvManager__IsAbilityReady                      0x49AACE
#define AltAdvManager__GetAltAbility                       0x49AB85

// CBankWnd
#define CBankWnd__GetNumBankSlots                          0x40CDCE

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg                  0x414AF0

// CButtonWnd
#define CButtonWnd__SetCheck                               0x59BCB0

// CChatManager
#define CChatManager__GetRGBAFromIndex                     0x426D03
#define CChatManager__InitContextMenu                      0x426DE7

// CChatWindow
#define CChatWindow__CChatWindow                           0x42A855

// CComboWnd
#define CComboWnd__DeleteAll                               0x59C7D0
#define CComboWnd__Draw                                    0x59C9C0
#define CComboWnd__GetButtonRect                           0x59C800
#define CComboWnd__GetCurChoice                            0x59C790
#define CComboWnd__GetListRect                             0x59CC60
#define CComboWnd__GetTextRect                             0x59C850
#define CComboWnd__InsertChoice                            0x59CCC0
#define CComboWnd__SetColors                               0x59C720
#define CComboWnd__SetChoice                               0x59C750

// CContainerWnd
#define CContainerWnd__HandleCombine                       0x43B16E
#define CContainerWnd__vftable                             0x611FA0

// CDisplay
#define CDisplay__CleanGameUI                              0x44A5BC
#define CDisplay__GetClickedActor                          0x4470E2
#define CDisplay__GetUserDefinedColor                      0x446646
#define CDisplay__GetWorldFilePath                         0x445E1A
#define CDisplay__ReloadUI                                 0x452950
#define CDisplay__WriteTextHD2                             0x44B907

// CEditBaseWnd
#define CEditBaseWnd__SetMaxChars                          0x408C36
#define CEditBaseWnd__SetSel                               0x5AC2A0

// CEditWnd
#define CEditWnd__DrawCaret                                0x5A8890
#define CEditWnd__GetCharIndexPt                           0x5A9680
#define CEditWnd__GetDisplayString                         0x5A8A20
#define CEditWnd__GetHorzOffset                            0x5A8C90
#define CEditWnd__GetLineForPrintableChar                  0x5A9160
#define CEditWnd__GetSelStartPt                            0x5A98C0
#define CEditWnd__GetSTMLSafeText                          0x5A8E20
#define CEditWnd__PointFromPrintableChar                   0x5A9270
#define CEditWnd__SelectableCharFromPoint                  0x5A93E0
#define CEditWnd__SetEditable                              0x5A8DF0

// CEverQuest
#define CEverQuest__ClickedPlayer                          0x4C45AD
#define CEverQuest__DropHeldItemOnGround                   0x4CB47D
#define CEverQuest__dsp_chat                               0x4C629B
#define CEverQuest__EnterZone                              0x4D6DF6
#define CEverQuest__GetBodyTypeDesc                        0x4C049D
#define CEverQuest__GetClassDesc                           0x4BFEC0
#define CEverQuest__GetClassThreeLetterCode                0x4C033A
#define CEverQuest__GetDeityDesc                           0x4C1F30
#define CEverQuest__GetRaceDesc                            0x4C07A2
#define CEverQuest__InterpretCmd                           0x4D09B9
#define CEverQuest__LeftClickedOnPlayer                    0x4D574E
#define CEverQuest__RightClickedOnPlayer                   0x4D5B84
#define CEverQuest__SetGameState                           0x4C461E

// CGaugeWnd
#define CGaugeWnd__CalcFillRect                            0x4E3A8B
#define CGaugeWnd__CalcLinesFillRect                       0x4E3AE7
#define CGaugeWnd__Draw                                    0x4E3DE7

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton                         0x4F4009

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot                           0x4F78CA
#define CInvSlotMgr__MoveItem                              0x4F79F8

// CItemDisplayWnd
#define CItemDisplayWnd__SetItem                           0x4FCA9C
#define CItemDisplayWnd__SetSpell                          0x4FBA92

// CLabel
#define CLabel__Draw                                       0x50431E

// CListWnd
#define CListWnd__AddColumn                                0x588820
#define CListWnd__AddColumn1                               0x588350
#define CListWnd__AddLine                                  0x587EE0
#define CListWnd__AddString                                0x5880B0
#define CListWnd__CalculateFirstVisibleLine                0x5854D0
#define CListWnd__CalculateVSBRange                        0x587010
#define CListWnd__ClearAllSel                              0x584D10
#define CListWnd__CloseAndUpdateEditWindow                 0x585AF0
#define CListWnd__Compare                                  0x585E60
#define CListWnd__Draw                                     0x586D20
#define CListWnd__DrawColumnSeparators                     0x586BA0
#define CListWnd__DrawHeader                               0x584EE0
#define CListWnd__DrawItem                                 0x586570
#define CListWnd__DrawLine                                 0x5868E0
#define CListWnd__DrawSeparator                            0x586C40
#define CListWnd__EnsureVisible                            0x585520
#define CListWnd__ExtendSel                                0x5864A0
#define CListWnd__GetColumnFlags                           0x5848B0
#define CListWnd__GetColumnJustification                   0x584A20
#define CListWnd__GetColumnMinWidth                        0x5849C0
#define CListWnd__GetColumnWidth                           0x584900
#define CListWnd__GetCurSel                                0x584450
#define CListWnd__GetHeaderRect                            0x584560
#define CListWnd__GetItemAtPoint                           0x585800
#define CListWnd__GetItemAtPoint1                          0x585870
#define CListWnd__GetItemData                              0x584730
#define CListWnd__GetItemHeight                            0x585270
#define CListWnd__GetItemIcon                              0x5847F0
#define CListWnd__GetItemRect                              0x5855F0
#define CListWnd__GetItemText                              0x584770
#define CListWnd__GetSelList                               0x588230
#define CListWnd__GetSeparatorRect                         0x585DB0
#define CListWnd__IsLineEnabled                            0x584DF0
#define CListWnd__RemoveLine                               0x5881E0
#define CListWnd__SetColors                                0x5844D0
#define CListWnd__SetColumnJustification                   0x584A70
#define CListWnd__SetColumnWidth                           0x584980
#define CListWnd__SetCurSel                                0x584490
#define CListWnd__SetItemColor                             0x587B10
#define CListWnd__SetItemData                              0x584DB0
#define CListWnd__SetItemText                              0x587A90
#define CListWnd__ShiftColumnSeparator                     0x586410
#define CListWnd__Sort                                     0x588850
#define CListWnd__ToggleSel                                0x584C80

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd                           0x517429

// CMerchantWnd
#define CMerchantWnd__DisplayBuyOrSellPrice                0x51892C
#define CMerchantWnd__RequestBuyItem                       0x51999A
#define CMerchantWnd__RequestSellItem                      0x518C94
#define CMerchantWnd__SelectBuySellSlot                    0x519700

// CSidlManager
#define CSidlManager__FindScreenPieceTemplate1             0x5A6BE0

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateHSBRange                  0x57CF00
#define CSidlScreenWnd__CalculateVSBRange                  0x57CE40
#define CSidlScreenWnd__ConvertToRes                       0x57D640
#define CSidlScreenWnd__CreateChildrenFromSidl             0x57DE60
#define CSidlScreenWnd__CSidlScreenWnd1                    0x57F240
#define CSidlScreenWnd__CSidlScreenWnd2                    0x57F2F0
#define CSidlScreenWnd__dCSidlScreenWnd                    0x57EA50
#define CSidlScreenWnd__DrawSidlPiece                      0x57DB80
#define CSidlScreenWnd__EnableIniStorage                   0x57D5F0
#define CSidlScreenWnd__GetSidlPiece                       0x57DD40
#define CSidlScreenWnd__Init1                              0x57F060
#define CSidlScreenWnd__LoadIniInfo                        0x57DF10
#define CSidlScreenWnd__LoadIniListWnd                     0x57D7A0
#define CSidlScreenWnd__LoadSidlScreen                     0x57D9E0
#define CSidlScreenWnd__SetScreen                          0x57EB60
#define CSidlScreenWnd__StoreIniInfo                       0x57D140
#define CSidlScreenWnd__WndNotification                    0x57DAE0

// CSliderWnd
#define CSliderWnd__GetValue                               0x59CFE0
#define CSliderWnd__SetValue                               0x59D160
#define CSliderWnd__UpdateThumb                            0x59CFA0

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet                         0x53F2D7

// CStmlWnd
#define CStmlWnd__AppendSTML                               0x590A90
#define CStmlWnd__CalculateHSBRange                        0x5894D0
#define CStmlWnd__CalculateVSBRange                        0x589470
#define CStmlWnd__CanBreakAtCharacter                      0x589610
#define CStmlWnd__CanGoBackward                            0x589690
#define CStmlWnd__FastForwardToEndOfTag                    0x5C4900
#define CStmlWnd__GetNextChar                              0x594B70
#define CStmlWnd__GetNextTagPiece                          0x58A010
#define CStmlWnd__GetSTMLText                              0x42A837
#define CStmlWnd__GetThisChar                              0x5C40D0
#define CStmlWnd__GetVisiableText                          0x58B500
#define CStmlWnd__InitializeWindowVariables                0x58D1F0
#define CStmlWnd__MakeStmlColorTag                         0x588B10
#define CStmlWnd__MakeWndNotificationTag                   0x588BB0
#define CStmlWnd__StripFirstSTMLLines                      0x590820
#define CStmlWnd__UpdateHistoryString                      0x58B950

// CTabWnd
#define CTabWnd__Draw                                      0x594230
#define CTabWnd__DrawCurrentPage                           0x593D10
#define CTabWnd__DrawTab                                   0x593B10
#define CTabWnd__GetCurrentPage                            0x593FA0
#define CTabWnd__GetCurrentTabIndex                        0x5937D0
#define CTabWnd__GetNumTabs                                0x5937C0
#define CTabWnd__GetPageClientRect                         0x5937E0
#define CTabWnd__GetPageFromTabIndex                       0x593A60
#define CTabWnd__GetPageInnerRect                          0x593840
#define CTabWnd__GetTabInnerRect                           0x5939E0
#define CTabWnd__GetTabRect                                0x5938F0
#define CTabWnd__IndexInBounds                             0x5938D0
#define CTabWnd__InsertPage                                0x594430
#define CTabWnd__SetPage                                   0x593FB0
#define CTabWnd__SetPageRect                               0x594180
#define CTabWnd__UpdatePage                                0x5943B0

// CTextOverlay
#define CTextOverlay__DisplayText                          0x41925F

// CTextureFont
#define CTextureFont__DrawWrappedText                      0x5840D0

// CXMLDataManager
#define CXMLDataManager__GetXMLData                        0x5ACE80

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead                       0x59AC30

// CXRect
#define CXRect__CenterPoint                                0x40C631

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr                                       0x401000
#define CXStr__CXStr1                                      0x51E582
#define CXStr__CXStr3                                      0x55D8F0
#define CXStr__dCXStr                                      0x40949D
#define CXStr__operator_equal1                             0x55DAB0
#define CXStr__operator_plus_equal1                        0x55E8F0

// CXWnd
#define CXWnd__BringToTop                                  0x57F930
#define CXWnd__Center                                      0x582D90
#define CXWnd__ClrFocus                                    0x57F680
#define CXWnd__DoAllDrawing                                0x583980
#define CXWnd__DrawChildren                                0x583AB0
#define CXWnd__DrawColoredRect                             0x57FB60
#define CXWnd__DrawTooltipAtPoint                          0x582C00
#define CXWnd__GetBorderFrame                              0x57FFC0
#define CXWnd__GetChildWndAt                               0x5827B0
#define CXWnd__GetClientClipRect                           0x57FEF0
#define CXWnd__GetFirstChildWnd                            0x57F9C0
#define CXWnd__GetNextChildWnd                             0x582790
#define CXWnd__GetNextSib                                  0x57F9E0
#define CXWnd__GetScreenClipRect                           0x583020
#define CXWnd__GetScreenRect                               0x580190
#define CXWnd__GetTooltipRect                              0x582B50
#define CXWnd__GetWindowTextA                              0x402A33
#define CXWnd__GetXMLTooltip                               0x0
#define CXWnd__IsActive                                    0x57FF60
#define CXWnd__IsDescendantOf                              0x57FF70
#define CXWnd__IsReallyVisible                             0x582770
#define CXWnd__IsType                                      0x583920
#define CXWnd__Move                                        0x582320
#define CXWnd__Move1                                       0x5823B0
#define CXWnd__ProcessTransition                           0x57F8F0
#define CXWnd__Refade                                      0x57F720
#define CXWnd__Resize                                      0x583160
#define CXWnd__Right                                       0x582F00
#define CXWnd__SetFirstChildPointer                        0x5803E0
#define CXWnd__SetFocus                                    0x5816A0
#define CXWnd__SetKeyTooltip                               0x580420
#define CXWnd__SetMouseOver                                0x580400
#define CXWnd__SetNextSibPointer                           0x5803F0
#define CXWnd__StartFade                                   0x57F950

// CXWndManager
#define CXWndManager__DrawCursor                           0x59EFF0
#define CXWndManager__DrawWindows                          0x59ECB0
#define CXWndManager__GetFirstChildWnd                     0x59E5F0
#define CXWndManager__GetKeyboardFlags                     0x59DAB0
#define CXWndManager__HandleKeyboardMsg                    0x59DF80
#define CXWndManager__RemoveWnd                            0x59DE90

// EQ_Character
#define EQ_Character__CastSpell                            0x4AB7DC
#define EQ_Character__Cur_HP                               0x49EB02
#define EQ_Character__GetAACastingTimeModifier             0x4A7935
#define EQ_Character__GetFocusCastingTimeModifier          0x4A749E
#define EQ_Character__Max_Endurance                        0x49B5DD
#define EQ_Character__Max_HP                               0x49B38A
#define EQ_Character__Max_Mana                             0x4B485C
#define EQ_Character__doCombatAbility                      0x4B4BEE

// EQ_Item
#define EQ_Item__CanDrop                                   0x4B1EB5
#define EQ_Item__GetItemLinkHash                           0x4B1AA7
#define EQ_Item__IsStackable                               0x4B2059

// EQ_LoadingS
#define EQ_LoadingS__WriteTextHD                           0x4B25C5

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney                      0x4B6F30

// EQItemList
#define EQItemList__dEQItemList                            0x46B3C7
#define EQItemList__EQItemList                             0x46B34B

// EQPlayer
#define EQPlayer__ChangeBoneStringSprite                   0x4817F0
#define EQPlayer__dEQPlayer                                0x48AC55
#define EQPlayer__DoAttack                                 0x488CAF
#define EQPlayer__EQPlayer                                 0x48B245
#define EQPlayer__SetNameSpriteState                       0x4841F0
#define EQPlayer__SetNameSpriteTint                        0x48185C

// KeyPressHandler
#define KeypressHandler__AttachAltKeyToEqCommand           0x5041A7
#define KeypressHandler__AttachKeyToEqCommand              0x504174
#define KeypressHandler__ClearCommandStateArray            0x503FBF
#define KeypressHandler__HandleKeyDown                     0x502E1A
#define KeypressHandler__HandleKeyUp                       0x503091
#define KeypressHandler__SaveKeymapping                    0x504044

// MapViewMap
#define MapViewMap__Clear                                  0x513BA2
#define MapViewMap__SaveEx                                 0x51435F

// StringTable
#define StringTable__getString                             0x5CAFD0 