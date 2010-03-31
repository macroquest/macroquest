                                                                                                                                                                                                                                                               
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
#define __ExpectedVersionDate                              "Jan 30 2005"
#define __ExpectedVersionTime                              "15:34:02"
#define __ActualVersionDate                                0x5FC99C
#define __ActualVersionTime                                0x5FC9A8

#define __ClientOverride                                   0
#define __MacroQuestWinClassName                           "__MacroQuestTray"
#define __MacroQuestWinName                                "MacroQuest"

// Memory Protection
#define __MemChecker0                                      0x4FBEB5
#define __MemChecker2                                      0x538646
#define __MemChecker3                                      0x5386D3
#define __MemChecker4                                      0x5B24E0
#define __EncryptPad0                                      0x71D0E0
#define __EncryptPad2                                      0x7202B8
#define __EncryptPad3                                      0x7206B8
#define __EncryptPad4                                      0x725DB0

// Direct Input
#define DI8__Main                                          0x884FEC
#define DI8__Keyboard                                      0x884FF0
#define DI8__Mouse                                         0x884FF4

#define __AltTimerReady                                    0x806F8E
#define __Attack                                           0x866A94
#define __BindList                                         0x624DB8
#define __Clicks                                           0x80619C
#define __CommandList                                      0x625348
#define __CurrentMapLabel                                  0x877324
#define __CurrentSocial                                    0x628750
#define __DoAbilityAvailable                               0x806F28
#define __DoAbilityList                                    0x83FCEC
#define __DrawHandler                                      0x88EF4C
#define __EQP_IDArray                                      0x754360
#define __FriendsList                                      0x83CAAC
#define __GroupCount                                       0x866E28
#define __GroupLeader                                      0x866F84
#define __Guilds                                           0x86E868
#define __gWorld                                           0x868880
#define __HotkeyPage                                       0x86664C
#define __HWnd                                             0x806098
#define __IgnoreList                                       0x83E3AC
#define __InChatMode                                       0x8060D8
#define __LastTell                                         0x808218
#define __Mouse                                            0x884FF8
#define __MouseLook                                        0x80616A
#define __NetStatusToggle                                  0x80616C
#define __PCNames                                          0x807224
#define __RangeAttackReady                                 0x806F8C
#define __ScreenMode                                       0x751EE8
#define __ScreenX                                          0x8060A0
#define __ScreenY                                          0x8060A4
#define __ServerHost                                       0x866CE4
#define __ServerName                                       0x83FCAC
#define __ShowNames                                        0x807174
#define __SkillDict                                        0x7576E0
#define __Socials                                          0x83FDAC

////
//Section 1: Vital Offsets
////
#define instCRaid                                          0x868910
#define instEQZoneInfo                                     0x806308
#define instKeypressHandler                                0x876FD4
#define pinstActiveBanker                                  0x8688F4
#define pinstActiveCorpse                                  0x8688F8
#define pinstActiveGMaster                                 0x8688FC
#define pinstActiveMerchant                                0x8688F0
#define pinstAltAdvManager                                 0x757288
#define pinstCCursorAttachment                             0x752A04
#define pinstCDisplay                                      0x868904
#define pinstCEverQuest                                    0x885160
#define pinstCharData                                      0x8688E0
#define pinstCharSpawn                                     0x8688D8
#define pinstControlledPlayer                              0x8688D8
#define pinstCSidlManager                                  0x88E2E4
#define pinstCXWndManager                                  0x88E2DC
#define pinstEQItemList                                    0x8688A4
#define pinstGroup                                         0x866F70
#define pinstLocalPlayer                                   0x8688C4
#define pinstPCData                                        0x8688E0
#define pinstSelectedItem                                  0x876F54
#define pinstSpawnList                                     0x8688A0
#define pinstSpellManager                                  0x877688
#define pinstSpellSets                                     0x866650
#define pinstStringTable                                   0x868890
#define pinstSwitchManager                                 0x757284
#define pinstTarget                                        0x8688E4
#define pinstTargetSwitch                                  0x8688EC
#define pinstTradeTarget                                   0x8688C0
#define pinstWorldData                                     0x86889C


////
//Section 2:  UI Related Offsets
////
#define pinstCTextOverlay                                  0x727880
#define pinstCharacterSelect                               0x75297C
#define pinstCFacePick                                     0x752980
#define pinstCNoteWnd                                      0x752984
#define pinstCHelpWnd                                      0x752988
#define pinstCBookWnd                                      0x75298C
#define pinstCPetInfoWnd                                   0x752990
#define pinstCTrainWnd                                     0x752994
#define pinstCSkillsWnd                                    0x752998
#define pinstCSkillsSelectWnd                              0x75299C
#define pinstCCombatSkillSelectWnd                         0x7529A0
#define pinstCFriendsWnd                                   0x7529A4
#define pinstCAAWnd                                        0x7529B0
#define pinstCGroupSearchFiltersWnd                        0x7529B4
#define pinstCLoadskinWnd                                  0x7529B8
#define pinstCAlarmWnd                                     0x7529BC
#define pinstCMusicPlayerWnd                               0x7529C0
#define pinstCRaidWnd                                      0x7529CC
#define pinstCRaidOptionsWnd                               0x7529D0
#define pinstCBreathWnd                                    0x7529D4
#define pinstCMapViewWnd                                   0x7529D8
#define pinstCMapToolbarWnd                                0x7529DC
#define pinstCEditLabelWnd                                 0x7529E0
#define pinstCTargetWnd                                    0x7529E4
#define pinstCHotButtonWnd                                 0x7529E8
#define pinstCColorPickerWnd                               0x7529EC
#define pinstCPlayerWnd                                    0x7529F0
#define pinstCOptionsWnd                                   0x7529F4
#define pinstCBuffWindowNORMAL                             0x7529F8
#define pinstCBuffWindowSHORT                              0x7529FC
#define pinstCharacterCreation                             0x752A00
#define pinstCCursorAttachment                             0x752A04
#define pinstCCastingWnd                                   0x752A08
#define pinstCCastSpellWnd                                 0x752A0C
#define pinstCSpellBookWnd                                 0x752A10
#define pinstCInventoryWnd                                 0x752A14
#define pinstCBankWnd                                      0x752A18
#define pinstCQuantityWnd                                  0x752A1C
#define pinstCLootWnd                                      0x752A20
#define pinstCActionsWnd                                   0x752A24
#define pinstCCombatAbilityWnd                             0x752A28
#define pinstCMerchantWnd                                  0x752A2C
#define pinstCTradeWnd                                     0x752A30
#define pinstCSelectorWnd                                  0x752A34
#define pinstCBazaarWnd                                    0x752A38
#define pinstCBazaarSearchWnd                              0x752A3C
#define pinstCGiveWnd                                      0x752A40
#define pinstCTrackingWnd                                  0x752A44
#define pinstCInspectWnd                                   0x752A48
#define pinstCSocialEditWnd                                0x752A4C
#define pinstCFeedbackWnd                                  0x752A50
#define pinstCBugReportWnd                                 0x752A54
#define pinstCVideoModesWnd                                0x752A58
#define pinstCTextEntryWnd                                 0x752A60
#define pinstCFileSelectionWnd                             0x752A64
#define pinstCCompassWnd                                   0x752A68
#define pinstCPlayerNotesWnd                               0x752A6C
#define pinstCGemsGameWnd                                  0x752A70
#define pinstCTimeLeftWnd                                  0x752A74
#define pinstCPetitionQWnd                                 0x752A78
#define pinstCSoulmarkWnd                                  0x752A7C
#define pinstCStoryWnd                                     0x752A80
#define pinstCJournalTextWnd                               0x752A84
#define pinstCJournalCatWnd                                0x752A88
#define pinstCBodyTintWnd                                  0x752A8C
#define pinstCInvSlotMgr                                   0x752A90
#define pinstCContainerMgr                                 0x752A94
#define pinstCAdventureLeaderboardWnd                      0x72752C
#define pinstCAdventureMerchantWnd                         0x727548
#define pinstCAdventureRequestWnd                          0x727564
#define pinstCAdventureStatsWnd                            0x727580
#define pinstCChatManager                                  0x7279B0
#define pinstCDynamicZoneWnd                               0x752BA0
#define pinstCFindLocationWnd                              0x876D58
#define pinstCGroupSearchWnd                               0x876E50
#define pinstCGroupWnd                                     0x876E6C
#define pinstCGuildMgmtWnd                                 0x876EA4
#define pinstCItemDisplayManager                           0x876F88
#define pinstCLeadershipWnd                                0x877070
#define pinstCPopupWndManager                              0x877498
#define pinstCSystemInfoDialogBox                          0x877E30
#define pinstCTargetOfTargetWnd                            0x877E54
#define pinstCTipWndOFDAY                                  0x877F44
#define pinstCTipWndCONTEXT                                0x877F48
#define pinstCTradeskillWnd                                0x878040
#define pinstCTributeBenefitWnd                            0x87808C
#define pinstCTributeMasterWnd                             0x8780A8
#define pinstCContextMenuManager                           0x88E50C
// unknown window added 4-14 exe 0x79A234


////
// Section 3: Miscellaneous Offsets
////
#define __CastRay                                          0x46476F
#define __ConvertItemTags                                  0x463FC9
#define __ExecuteCmd                                       0x455D81
#define __get_melee_range                                  0x45A967
#define __GetGaugeValueFromEQ                              0x521534
#define __LoadSplashScreen                                 0x5B80E0
#define __NewUIINI                                         0x5230CD
#define __ProcessGameEvents                                0x4C2A4B
#define __SendMessage                                      0x4A9FAA
#define CrashDetected                                      0x538302
#define DrawNetStatus                                      0x5002F8


////
// Section 4: Function Offsets
////
// AltAdvManager
#define AltAdvManager__GetCalculatedTimer                  0x487008
#define AltAdvManager__IsAbilityReady                      0x487036

// CBankWnd
#define CBankWnd__GetNumBankSlots                          0x40B572

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg                  0x40E8DA

// CButtonWnd
#define CButtonWnd__SetCheck                               0x57A680

// CChatManager
#define CChatManager__GetRGBAFromIndex                     0x41F466
#define CChatManager__InitContextMenu                      0x41F54A

// CChatWindow
#define CChatWindow__CChatWindow                           0x4224AD

// CComboWnd
#define CComboWnd__DeleteAll                               0x57B2F0
#define CComboWnd__Draw                                    0x57B4F0
#define CComboWnd__GetButtonRect                           0x57B320
#define CComboWnd__GetCurChoice                            0x57B2B0
#define CComboWnd__GetListRect                             0x57B8E0
#define CComboWnd__GetTextRect                             0x57B380
#define CComboWnd__InsertChoice                            0x57B940
#define CComboWnd__SetColors                               0x57B280
#define CComboWnd__SetChoice                               0x57BA20

// CContainerWnd
#define CContainerWnd__HandleCombine                       0x429EBC
#define CContainerWnd__vftable                             0x5E4E18

// CDisplay
#define CDisplay__CleanGameUI                              0x43990A
#define CDisplay__GetClickedActor                          0x4364CA
#define CDisplay__GetUserDefinedColor                      0x43588D
#define CDisplay__GetWorldFilePath                         0x435099
#define CDisplay__ReloadUI                                 0x441053
#define CDisplay__WriteTextHD2                             0x43A594

// CEditBaseWnd
#define CEditBaseWnd__SetMaxChars                          0x408129
#define CEditBaseWnd__SetSel                               0x58C400

// CEditWnd
#define CEditWnd__DrawCaret                                0x588460
#define CEditWnd__GetCharIndexPt                           0x5892C0
#define CEditWnd__GetDisplayString                         0x5885C0
#define CEditWnd__GetHorzOffset                            0x588830
#define CEditWnd__GetLineForPrintableChar                  0x588D60
#define CEditWnd__GetSelStartPt                            0x589500
#define CEditWnd__GetSTMLSafeText                          0x588A10
#define CEditWnd__PointFromPrintableChar                   0x588E70
#define CEditWnd__SelectableCharFromPoint                  0x588FF0
#define CEditWnd__SetEditable                              0x5889E0

// CEverQuest
#define CEverQuest__ClickedPlayer                          0x4AF358
#define CEverQuest__DropHeldItemOnGround                   0x4B10E5
#define CEverQuest__dsp_chat                               0x4B173B
#define CEverQuest__EnterZone                              0x4C17D2
#define CEverQuest__GetBodyTypeDesc                        0x4AAFD9
#define CEverQuest__GetClassDesc                           0x4AA9FC
#define CEverQuest__GetClassThreeLetterCode                0x4AAE76
#define CEverQuest__GetDeityDesc                           0x4ACA6C
#define CEverQuest__GetRaceDesc                            0x4AB2DE
#define CEverQuest__InterpretCmd                           0x4BBE2D
#define CEverQuest__LeftClickedOnPlayer                    0x4C012A
#define CEverQuest__RightClickedOnPlayer                   0x4C0560
#define CEverQuest__SetGameState                           0x4AF438

// CGaugeWnd
#define CGaugeWnd__CalcFillRect                            0x4CE1C1
#define CGaugeWnd__CalcLinesFillRect                       0x4CE21D
#define CGaugeWnd__Draw                                    0x4CE51D

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton                         0x4DE492

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot                           0x4E1E0A
#define CInvSlotMgr__MoveItem                              0x4E174E

// CItemDisplayWnd
#define CItemDisplayWnd__SetItem                           0x4E68A8
#define CItemDisplayWnd__SetSpell                          0x4E5846

// CLabel
#define CLabel__Draw                                       0x4EDF70

// CListWnd
#define CListWnd__AddColumn                                0x564D10
#define CListWnd__AddColumn1                               0x564860
#define CListWnd__AddLine                                  0x564420
#define CListWnd__AddString                                0x5645A0
#define CListWnd__CalculateFirstVisibleLine                0x561990
#define CListWnd__CalculateVSBRange                        0x563520
#define CListWnd__ClearAllSel                              0x5610F0
#define CListWnd__CloseAndUpdateEditWindow                 0x561F90
#define CListWnd__Compare                                  0x5622D0
#define CListWnd__Draw                                     0x563180
#define CListWnd__DrawColumnSeparators                     0x562FD0
#define CListWnd__DrawHeader                               0x561310
#define CListWnd__DrawItem                                 0x5629E0
#define CListWnd__DrawLine                                 0x562D40
#define CListWnd__DrawSeparator                            0x5630A0
#define CListWnd__EnsureVisible                            0x5619E0
#define CListWnd__ExtendSel                                0x562910
#define CListWnd__GetColumnFlags                           0x560BC0
#define CListWnd__GetColumnJustification                   0x560D60
#define CListWnd__GetColumnMinWidth                        0x560CF0
#define CListWnd__GetColumnWidth                           0x560C20
#define CListWnd__GetCurSel                                0x560A00
#define CListWnd__GetHeaderRect                            0x560840
#define CListWnd__GetItemAtPoint                           0x561C90
#define CListWnd__GetItemAtPoint1                          0x561D00
#define CListWnd__GetItemData                              0x560A40
#define CListWnd__GetItemHeight                            0x561710
#define CListWnd__GetItemIcon                              0x560B00
#define CListWnd__GetItemRect                              0x561AB0
#define CListWnd__GetItemText                              0x560A80
#define CListWnd__GetSelList                               0x564740
#define CListWnd__GetSeparatorRect                         0x562220
#define CListWnd__IsLineEnabled                            0x5611E0
#define CListWnd__RemoveLine                               0x5646F0
#define CListWnd__SetColors                                0x5607B0
#define CListWnd__SetColumnJustification                   0x560DC0
#define CListWnd__SetColumnWidth                           0x560CA0
#define CListWnd__SetCurSel                                0x561010
#define CListWnd__SetItemColor                             0x564060
#define CListWnd__SetItemData                              0x5611A0
#define CListWnd__SetItemText                              0x563FA0
#define CListWnd__ShiftColumnSeparator                     0x562880
#define CListWnd__Sort                                     0x564DB0
#define CListWnd__ToggleSel                                0x561030

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd                           0x4FAEA6

// CMerchantWnd
#define CMerchantWnd__DisplayBuyOrSellPrice                0x4FC398
#define CMerchantWnd__RequestBuyItem                       0x4FC556
#define CMerchantWnd__RequestSellItem                      0x4FC8EF
#define CMerchantWnd__SelectBuySellSlot                    0x4FD6B4

// CSidlManager
#define CSidlManager__FindScreenPieceTemplate1             0x586450

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateHSBRange                  0x558C40
#define CSidlScreenWnd__CalculateVSBRange                  0x558B80
#define CSidlScreenWnd__ConvertToRes                       0x559330
#define CSidlScreenWnd__CreateChildrenFromSidl             0x559AA0
#define CSidlScreenWnd__CSidlScreenWnd1                    0x55B1A0
#define CSidlScreenWnd__CSidlScreenWnd2                    0x55B290
#define CSidlScreenWnd__dCSidlScreenWnd                    0x55A7F0
#define CSidlScreenWnd__DrawSidlPiece                      0x5596C0
#define CSidlScreenWnd__EnableIniStorage                   0x5592E0
#define CSidlScreenWnd__GetSidlPiece                       0x559960
#define CSidlScreenWnd__Init1                              0x55AEF0
#define CSidlScreenWnd__LoadIniInfo                        0x559B50
#define CSidlScreenWnd__LoadIniListWnd                     0x55A490
#define CSidlScreenWnd__LoadSidlScreen                     0x559500
#define CSidlScreenWnd__SetScreen                          0x55A910
#define CSidlScreenWnd__StoreIniInfo                       0x558E70
#define CSidlScreenWnd__WndNotification                    0x559620

// CSliderWnd
#define CSliderWnd__GetValue                               0x57BD60
#define CSliderWnd__SetValue                               0x57BF40
#define CSliderWnd__UpdateThumb                            0x57BD20

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet                         0x51F9B1

// CStmlWnd
#define CStmlWnd__AppendSTML                               0x56E310
#define CStmlWnd__CalculateHSBRange                        0x565BD0
#define CStmlWnd__CalculateVSBRange                        0x565B70
#define CStmlWnd__CanBreakAtCharacter                      0x565D10
#define CStmlWnd__CanGoBackward                            0x565D90
#define CStmlWnd__FastForwardToEndOfTag                    0x566AC0
#define CStmlWnd__GetNextChar                              0x5661D0
#define CStmlWnd__GetNextTagPiece                          0x5668C0
#define CStmlWnd__GetSTMLText                              0x42248F
#define CStmlWnd__GetThisChar                              0x565A10
#define CStmlWnd__GetVisiableText                          0x568290
#define CStmlWnd__InitializeWindowVariables                0x56A090
#define CStmlWnd__MakeStmlColorTag                         0x5650E0
#define CStmlWnd__MakeWndNotificationTag                   0x565180
#define CStmlWnd__StripFirstSTMLLines                      0x56E090
#define CStmlWnd__UpdateHistoryString                      0x5686D0

// CTabWnd
#define CTabWnd__Draw                                      0x5720F0
#define CTabWnd__DrawCurrentPage                           0x571BE0
#define CTabWnd__DrawTab                                   0x571960
#define CTabWnd__GetCurrentPage                            0x571450
#define CTabWnd__GetCurrentTabIndex                        0x571170
#define CTabWnd__GetNumTabs                                0x5712A0
#define CTabWnd__GetPageClientRect                         0x571180
#define CTabWnd__GetPageFromTabIndex                       0x5712D0
#define CTabWnd__GetPageInnerRect                          0x5711E0
#define CTabWnd__GetTabInnerRect                           0x571560
#define CTabWnd__GetTabRect                                0x571460
#define CTabWnd__IndexInBounds                             0x5712B0
#define CTabWnd__InsertPage                                0x571FE0
#define CTabWnd__SetPage                                   0x571600
#define CTabWnd__SetPageRect                               0x5717D0
#define CTabWnd__UpdatePage                                0x571880

// CTextOverlay
#define CTextOverlay__DisplayText                          0x412CB3

// CTextureFont
#define CTextureFont__DrawWrappedText                      0x560330

// CXMLDataManager
#define CXMLDataManager__GetXMLData                        0x58D070

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead                       0x5793E0

// CXRect
#define CXRect__CenterPoint                                0x40ADD5

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr                                       0x401006
#define CXStr__CXStr1                                      0x401000
#define CXStr__CXStr3                                      0x53BFE0
#define CXStr__dCXStr                                      0x401030
#define CXStr__operator_equal1                             0x53C1A0
#define CXStr__operator_plus_equal1                        0x53CFE0

// CXWnd
#define CXWnd__BringToTop                                  0x55B940
#define CXWnd__Center                                      0x55EF60
#define CXWnd__ClrFocus                                    0x55B690
#define CXWnd__DoAllDrawing                                0x55FB70
#define CXWnd__DrawChildren                                0x55FCA0
#define CXWnd__DrawColoredRect                             0x55BB60
#define CXWnd__DrawTooltipAtPoint                          0x55ED90
#define CXWnd__GetBorderFrame                              0x55BFA0
#define CXWnd__GetChildWndAt                               0x55E920
#define CXWnd__GetClientClipRect                           0x55BEF0
#define CXWnd__GetFirstChildWnd                            0x55B9D0
#define CXWnd__GetNextChildWnd                             0x55E900
#define CXWnd__GetNextSib                                  0x55B9F0
#define CXWnd__GetScreenClipRect                           0x55F1F0
#define CXWnd__GetScreenRect                               0x55C170
#define CXWnd__GetTooltipRect                              0x55ECE0
#define CXWnd__GetWindowTextA                              0x402A95
#define CXWnd__GetXMLTooltip                               0x55B4D0
#define CXWnd__IsActive                                    0x55BF60
#define CXWnd__IsDescendantOf                              0x55BF70
#define CXWnd__IsReallyVisible                             0x55E8E0
#define CXWnd__IsType                                      0x55FB10
#define CXWnd__Move                                        0x55E490
#define CXWnd__Move1                                       0x55E520
#define CXWnd__ProcessTransition                           0x55B900
#define CXWnd__Refade                                      0x55B730
#define CXWnd__Resize                                      0x55F330
#define CXWnd__Right                                       0x55F0D0
#define CXWnd__SetFirstChildPointer                        0x55C3C0
#define CXWnd__SetFocus                                    0x55D670
#define CXWnd__SetKeyTooltip                               0x55C400
#define CXWnd__SetMouseOver                                0x55C3E0
#define CXWnd__SetNextSibPointer                           0x55C3D0
#define CXWnd__StartFade                                   0x55B960

// CXWndManager
#define CXWndManager__DrawCursor                           0x57EF30
#define CXWndManager__DrawWindows                          0x57EB80
#define CXWndManager__GetFirstChildWnd                     0x57E500
#define CXWndManager__GetKeyboardFlags                     0x57D940
#define CXWndManager__HandleKeyboardMsg                    0x57DE10
#define CXWndManager__RemoveWnd                            0x57DD20

// EQ_Character
#define EQ_Character__CastSpell                            0x49721A
#define EQ_Character__Cur_HP                               0x48C1D6
#define EQ_Character__GetAACastingTimeModifier             0x493ABD
#define EQ_Character__GetFocusCastingTimeModifier          0x4935A5
#define EQ_Character__Max_Endurance                        0x487C9E
#define EQ_Character__Max_HP                               0x487A4B
#define EQ_Character__Max_Mana                             0x4A111C

// EQ_Item
#define EQ_Item__CanDrop                                   0x49D86E
#define EQ_Item__GetItemLinkHash                           0x49D460
#define EQ_Item__IsStackable                               0x49DA12

// EQ_LoadingS
#define EQ_LoadingS__WriteTextHD                           0x49DF4A

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney                      0x4A1313

// EQItemList
#define EQItemList__dEQItemList                            0x458893
#define EQItemList__EQItemList                             0x458817

// EQPlayer
#define EQPlayer__ChangeBoneStringSprite                   0x46FD3B
#define EQPlayer__dEQPlayer                                0x479ACF
#define EQPlayer__DoAttack                                 0x4760DB
#define EQPlayer__EQPlayer                                 0x47A24A
#define EQPlayer__SetNameSpriteState                       0x47417A
#define EQPlayer__SetNameSpriteTint                        0x46FDA7

// KeyPressHandler
#define KeypressHandler__AttachAltKeyToEqCommand           0x4EDDD9
#define KeypressHandler__AttachKeyToEqCommand              0x4EDDA6
#define KeypressHandler__ClearCommandStateArray            0x4EDBEF
#define KeypressHandler__HandleKeyDown                     0x4ECA5E
#define KeypressHandler__HandleKeyUp                       0x4ECCD5
#define KeypressHandler__SaveKeymapping                    0x4EDC76

// MapViewMap
#define MapViewMap__Clear                                  0x4F7C80
#define MapViewMap__SaveEx                                 0x4F841B

// StringTable
#define StringTable__getString                             0x5A94B0
