/*****************************************************************************
    MQ2Main.dll: MacroQuest2's extension DLL for EverQuest
    Copyright (C) 2002-2003 Plazmic, 2003-2004 Lax

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


#define __ClientName                                  "eqgame"
//.rdata:005EE6D4 aJun152004      db 'Jun 15 2004',0     
//.rdata:005EE6E0 a150939         db '15:09:39',0         
#define __ExpectedVersionDate                         "Jun 15 2004"
#define __ExpectedVersionTime                         "15:09:39"
#define __ActualVersionDate                                0x5EE6D4
#define __ActualVersionTime                                0x5EE6E0

#define __ClientOverride                       0
#define __MacroQuestWinClassName                 "__MacroQuestTray"
#define __MacroQuestWinName                           "MacroQuest"

// Memory Protection
#define __MemChecker0                                      0x4C2630
#define __MemChecker1                                      0x4C7BA9
#define __MemChecker2                                      0x4C9980
#define __MemChecker3                                      0x4C9A1D
#define __EncryptPad0                                      0x715EF0
#define __EncryptPad1                                      0x7162F0
#define __EncryptPad2                                      0x716DC0
#define __EncryptPad3                                      0x7171C0

#define DI8__Main                                          0x89C144
#define DI8__Keyboard                                      0x89C148
#define DI8__Mouse                                         0x89C14C

#define __LastTell                                         0x7DC900
#define __Guilds                                           0x83CFC0
#define __Mouse                                            0x89C150
#define __Attack                                           0x83B134
#define __InChatMode                                       0x7DA838
#define __gWorld                                           0x83CF18
#define __GroupCount                                       0x83B4C8
#define __CommandList                                      0x70FD20
#define __DoAbilityList                                    0x8143D4
#define __DoAbilityAvailable                               0x7DB61C
#define __ServerHost                                       0x83B384
#define __ServerName                                       0x814394
#define __HWnd                                             0x7DA7F8
#define __Clicks                                           0x7DA8F8
#define __ScreenX                                          0x7DA800
#define __ScreenY                                          0x7DA804
#define __ScreenMode                                       0x7268E0
#define __MouseLook                                        0x7DA8CA
#define __EQP_IDArray                                      0x7D78E0
#define __CurrentMapLabel                                  0x8A5014
#define __BindList                                         0x70F7E0
#define __RangeAttackReady                                 0x7DB680
#define __AltTimerReady                                    0x7DB682
#define __Socials                                          0x814494
#define __HotkeyPage                                       0x83AD34
#define __CurrentSocial                                    0x61CBF4
#define __GroupLeader                                      0x83B624
#define __SkillDict                                        0x727D78
#define __DrawHandler                                      0x8B0D14
#define __FriendsList                                      0x811194
#define __IgnoreList                                       0x812A94
#define __NetStatusToggle                                  0x7DA8CC
#define __ShowNames                                        0x7DB864
#define __PCNames                                          0x7DB914
////
//Section 1: Vital Offsets
////
#define pinstCSidlManager                                  0x8B0444
#define pinstCDisplay                                      0x83CFA4
#define pinstCEverQuest                                    0x89C2B8
#define pinstPCData                                        0x83CF80
#define pinstCharData                                      0x83CF80
#define pinstCharSpawn                                     0x83CF78
#define pinstSpawnList                                     0x83CF40
#define pinstLocalPlayer                                   0x83CF64
#define pinstControlledPlayer                              0x83CF78
#define pinstWorldData                                     0x83CF3C
#define pinstSpellManager                                  0x898CF4
#define pinstTradeTarget                                   0x83CF60
#define pinstActiveMerchant                                0x83CF90
#define pinstActiveBanker                                  0x83CF94
#define pinstActiveCorpse                                  0x83CF98
#define pinstActiveGMaster                                 0x83CF9C
#define pinstSelectedItem                                  0x8A4F08
#define pinstGroup                                         0x83B610
#define pinstTarget                                        0x83CF84
#define pinstSwitchManager                                 0x7DA7EC
#define pinstEQItemList                                    0x83CF44
#define pinstSpellSets                                     0x83AD38
#define instEQZoneInfo                                     0x7DAA64
#define pinstCXWndManager                                  0x8B043C
#define instKeypressHandler                                0x88B3C0
#define pinstStringTable                                   0x83CF30
#define pinstAltAdvManager                                 0x727990
#define instCRaid                                          0x845290

////
//Section 2:  UI Related Offsets
////
#define pinstCTextOverlay                                  0x71F8E0
#define pinstCharacterSelect                               0x727374
#define pinstCFacePick                                     0x727378
// removed 4-14 exe #define pinstCTextMessageWnd                               
#define pinstCNoteWnd                                      0x72737C
#define pinstCHelpWnd                                      0x727380
#define pinstCBookWnd                                      0x727384
#define pinstCPetInfoWnd                                   0x727388
#define pinstCTrainWnd                                     0x72738C
#define pinstCSkillsWnd                                    0x727390
#define pinstCSkillsSelectWnd                              0x727394
#define pinstCCombatSkillSelectWnd                         0x727398
#define pinstCFriendsWnd                                   0x72739C
#define pinstCAAWnd                                        0x7273A0
#define pinstCGroupSearchFiltersWnd                        0x7273A4
#define pinstCLoadskinWnd                                  0x7273A8
#define pinstCAlarmWnd                                     0x7273AC
#define pinstCMusicPlayerWnd                               0x7273B0
#define pinstCRaidWnd                                      0x7273B8
#define pinstCRaidOptionsWnd                               0x7273BC
#define pinstCBreathWnd                                    0x7273C0
#define pinstCMapViewWnd                                   0x7273C4
#define pinstCMapToolbarWnd                                0x7273C8
#define pinstCEditLabelWnd                                 0x7273CC
#define pinstCTargetWnd                                    0x7273D0
#define pinstCHotButtonWnd                                 0x7273D4
#define pinstCColorPickerWnd                               0x7273D8
#define pinstCPlayerWnd                                    0x7273DC
#define pinstCOptionsWnd                                   0x7273E0
#define pinstCBuffWindowNORMAL                             0x7273E4
#define pinstCBuffWindowSHORT                              0x7273E8
#define pinstCharacterCreation                             0x7273EC
#define pinstCCursorAttachment                             0x7273F0
#define pinstCCastingWnd                                   0x7273F4
#define pinstCCastSpellWnd                                 0x7273F8
#define pinstCSpellBookWnd                                 0x7273FC
#define pinstCInventoryWnd                                 0x727400
#define pinstCBankWnd                                      0x727404
#define pinstCQuantityWnd                                  0x727408
#define pinstCLootWnd                                      0x72740C
#define pinstCActionsWnd                                   0x727410
#define pinstCCombatAbilityWnd                             0x727414
#define pinstCMerchantWnd                                  0x727418
#define pinstCTradeWnd                                     0x72741C
#define pinstCSelectorWnd                                  0x727420
#define pinstCBazaarWnd                                    0x727424
#define pinstCBazaarSearchWnd                              0x727428
#define pinstCGiveWnd                                      0x72742C
#define pinstCTrackingWnd                                  0x727430
#define pinstCInspectWnd                                   0x727434
#define pinstCSocialEditWnd                                0x727438
#define pinstCFeedbackWnd                                  0x72743C
#define pinstCBugReportWnd                                 0x727440
#define pinstCVideoModesWnd                                0x727444
#define pinstCTextEntryWnd                                 0x727448
#define pinstCFileSelectionWnd                             0x72744C
#define pinstCCompassWnd                                   0x727450
#define pinstCPlayerNotesWnd                               0x727454
#define pinstCGemsGameWnd                                  0x727458
#define pinstCTimeLeftWnd                                  0x72745C
#define pinstCPetitionQWnd                                 0x727460
#define pinstCSoulmarkWnd                                  0x727464
#define pinstCStoryWnd                                     0x727468
#define pinstCJournalTextWnd                               0x72746C
#define pinstCJournalCatWnd                                0x727470
#define pinstCBodyTintWnd                                  0x727474
#define pinstCInvSlotMgr                                   0x727478
#define pinstCContainerMgr                                 0x72747C
#define pinstCAdventureLeaderboardWnd                      0x8A4998
#define pinstCAdventureMerchantWnd                         0x8A49B0
#define pinstCAdventureRequestWnd                          0x8A49C8
#define pinstCAdventureStatsWnd                            0x8A49E0
#define pinstCChatManager                                  0x8A4C80
#define pinstCDynamicZoneWnd                               0x8A4D38
#define pinstCFindLocationWnd                              0x8A4DC8
#define pinstCGroupSearchWnd                               0x8A4E44
#define pinstCGroupWnd                                     0x8A4E5C
#define pinstCGuildMgmtWnd                                 0x8A4E74
#define pinstCItemDisplayManager                           0x8A4F34
#define pinstCLeadershipWnd                                0x8A4F9C
#define pinstCPopupWndManager                              0x8A5100
#define pinstCSystemInfoDialogBox                          0x8A59EC
#define pinstCTargetOfTargetWnd                            0x8A5A04
#define pinstCTipWndOFDAY                                  0x8A5AB8
#define pinstCTipWndCONTEXT                                0x8A5ABC
#define pinstCTradeskillWnd                                0x8A5AE8
#define pinstCTributeBenefitWnd                            0x8A5B28
#define pinstCTributeMasterWnd                             0x8A5B40
#define pinstCContextMenuManager                           0x8B0460
// unknown window added 4-14 exe 0x79A234


////
// Section 3: Miscellaneous Offsets
////
#define DrawNetStatus                                      0x4B6BD3
#define CrashDetected                                      0x4C967E
#define __ProcessGameEvents                                0x4AD1BC
#define __ConvertItemTags                                  0x45ADA5
#define __SendMessage                                      0x4BC78E
#define __NewUIINI                                         0x52D0AF
#define __ExecuteCmd                                       0x44D8F4
#define __GetGaugeValueFromEQ                              0x52B7BA
#define __get_melee_range                                  0x45236A
#define __CastRay										   0x460C2A

// EQ_LoadingS
#define EQ_LoadingS__WriteTextHD                           0x433D9D


////
// Section 4: Function Offsets
////
// CEverQuest
#define CEverQuest__dsp_chat                               0x49C9CA
#define CEverQuest__ClickedPlayer                          0x4999DC
#define CEverQuest__EnterZone                              0x49D6F5
#define CEverQuest__GetBodyTypeDesc                        0x49383C
#define CEverQuest__GetClassDesc                           0x4932BE
#define CEverQuest__GetClassThreeLetterCode                0x4936D9
#define CEverQuest__GetDeityDesc                           0x4952CF
#define CEverQuest__GetRaceDesc                            0x493B41
#define CEverQuest__GetTitleDesc                           0x4953E6
#define CEverQuest__InterpretCmd                           0x4A9A87
#define CEverQuest__LeftClickedOnPlayer                    0x4ABDC0
#define CEverQuest__RightClickedOnPlayer                   0x4A47A2
#define CEverQuest__SetGameState                           0x499B43
#define CEverQuest__DropHeldItemOnGround                   0x49C48B

// StringTable
#define StringTable__getString                             0x4BF92B

// AltAdvManager
#define AltAdvManager__IsAbilityReady                      0x41E6F2

// CXWndManager
#define CXWndManager__RemoveWnd                            0x57D460
#define CXWndManager__GetKeyboardFlags                     0x57D080
#define CXWndManager__HandleKeyboardMsg                    0x57D550
#define CXWndManager__DrawWindows                          0x57E340
#define CXWndManager__DrawCursor                           0x57E6F0
#define CXWndManager__GetFirstChildWnd                     0x57DC40

// KeyPressHandler
#define KeypressHandler__HandleKeyDown                     0x4B1E18
#define KeypressHandler__HandleKeyUp                       0x4B20BE
#define KeypressHandler__AttachKeyToEqCommand              0x4B34F1
#define KeypressHandler__AttachAltKeyToEqCommand           0x4B352E
#define KeypressHandler__SaveKeymapping                    0x4B33D9
#define KeypressHandler__ClearCommandStateArray            0x4B20AB

// EQ_Character
#define EQ_Character__Max_Endurance                        0x41ED78
#define EQ_Character__Max_Mana                             0x41EE01
#define EQ_Character__Max_HP                               0x41EBD9
#define EQ_Character__Cur_HP                               0x422469
#define EQ_Character__GetFocusCastingTimeModifier          0x42A113
#define EQ_Character__GetAACastingTimeModifier             0x42A4A7
#define EQ_Character__CastSpell                            0x42E0B4
#define EQ_Character__GetAbility                           0x422151

// EQPlayer
#define EQPlayer__EQPlayer                                 0x4881FE
#define EQPlayer__dEQPlayer                                0x487ABB
#define EQPlayer__DoAttack                                 0x48404A
#define EQPlayer__ChangeBoneStringSprite                   0x465FB6
#define EQPlayer__SetNameSpriteState                       0x4824D6
#define EQPlayer__SetNameSpriteTint                        0x466022

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr                                       0x4010C0
#define CXStr__CXStr1                                      0x401EAA
#define CXStr__CXStr3                                      0x5AF680
#define CXStr__dCXStr                                      0x4010EA
#define CXStr__operator_plus_equal1                        0x5B0710
#define CXStr__operator_equal1                             0x5AF840

// CChatWindow
#define CChatWindow__CChatWindow                           0x4E6A1E

// CChatManager
#define CChatManager__GetRGBAFromIndex                     0x4E34C1
#define CChatManager__InitContextMenu                      0x4E3E25

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot                           0x503A54
#define CInvSlotMgr__MoveItem                              0x503403

// CItemDisplayWnd
#define CItemDisplayWnd__SetItem                           0x506AE7
#define CItemDisplayWnd__SetSpell                          0x505E27

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton                         0x5001E6

// CLabel
#define CLabel__Draw                                       0x50CA1A

// CGauge
#define CGaugeWnd__Draw                                    0x4F25F3

// CDisplay
#define CDisplay__ReloadUI                                 0x41880E
#define CDisplay__CleanGameUI                              0x411654
#define CDisplay__GetClickedActor                          0x40E821
#define CDisplay__WriteTextHD2                             0x412156
#define CDisplay__GetWorldFilePath                         0x40D420
#define CDisplay__GetUserDefinedColor                      0x40DC1C

#define CTextureFont__DrawWrappedText                      0x56D8F0

// EQ_Item
#define EQ_Item__GetItemLinkHash                           0x433885
#define EQ_Item__CanDrop                                   0x43397D

// CBankWnd
#define CBankWnd__GetNumBankSlots                          0x4D467E

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg                  0x4D719B

// CMerchantWnd
#define CMerchantWnd__SelectBuySellSlot                    0x515B48
#define CMerchantWnd__RequestBuyItem                       0x514D3A
#define CMerchantWnd__RequestSellItem                      0x5150B8
#define CMerchantWnd__DisplayBuyOrSellPrice                0x514B6F

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet                         0x52A1BE

// MapViewMap
#define MapViewMap__SaveEx                                 0x51038E
#define MapViewMap__Clear                                  0x51021D


// CMapViewWnd
#define CMapViewWnd__CMapViewWnd                           0x513C52

// EQItemList
#define EQItemList__EQItemList                             0x4501CC
#define EQItemList__dEQItemList                            0x450248

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney                      0x4365C1

// CContainerWnd
#define CContainerWnd__HandleCombine                       0x4EAC24
#define CContainerWnd__vftable                             0x5F2B10

// CSidlScreenWnd
#define CSidlScreenWnd__CSidlScreenWnd1                    0x561240
#define CSidlScreenWnd__dCSidlScreenWnd                    0x5608E0
#define CSidlScreenWnd__CreateChildrenFromSidl             0x55FC50
#define CSidlScreenWnd__WndNotification                    0x55F7D0
#define CSidlScreenWnd__CalculateHSBRange                  0x55ED60
#define CSidlScreenWnd__CalculateVSBRange                  0x55ECA0
#define CSidlScreenWnd__ConvertToRes                       0x55F450
#define CSidlScreenWnd__CSidlScreenWnd2                    0x561330
#define CSidlScreenWnd__DrawSidlPiece                      0x55F870
#define CSidlScreenWnd__EnableIniStorage                   0x55F400
#define CSidlScreenWnd__GetSidlPiece                       0x55FB10
#define CSidlScreenWnd__Init1                              0x560F90
#define CSidlScreenWnd__LoadIniInfo                        0x55FD00
#define CSidlScreenWnd__LoadIniListWnd                     0x560640
#define CSidlScreenWnd__LoadSidlScreen                     0x55F6B0
#define CSidlScreenWnd__SetScreen                          0x560A00
#define CSidlScreenWnd__StoreIniInfo                       0x55EF90

// CSidlManager
#define CSidlManager__FindScreenPieceTemplate1             0x585AC0

// CXMLDataManager
#define CXMLDataManager__GetXMLData                        0x592700

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead                       0x56D210

// CXRect
#define CXRect__CenterPoint                                0x4D4685

// CXWnd
#define CXWnd__BringToTop                                  0x5619C0
#define CXWnd__Center                                      0x565040
#define CXWnd__ClrFocus                                    0x561710
#define CXWnd__DoAllDrawing                                0x565C50
#define CXWnd__DrawChildren                                0x565D80
#define CXWnd__DrawColoredRect                             0x561C00
#define CXWnd__DrawTooltipAtPoint                          0x564E70
#define CXWnd__GetBorderFrame                              0x562050
#define CXWnd__GetChildWndAt                               0x564A00
#define CXWnd__GetClientClipRect                           0x561F90
#define CXWnd__GetFirstChildWnd                            0x561A50
#define CXWnd__GetNextChildWnd                             0x5649E0
#define CXWnd__GetNextSib                                  0x561A70
#define CXWnd__GetScreenClipRect                           0x5652D0
#define CXWnd__GetScreenRect                               0x562220
#define CXWnd__GetTooltipRect                              0x564DC0
#define CXWnd__GetWindowTextA                              0x4CF129
#define CXWnd__GetXMLTooltip                               0x561550
#define CXWnd__IsActive                                    0x562000
#define CXWnd__IsDescendantOf                              0x562010
#define CXWnd__IsReallyVisible                             0x5649C0
#define CXWnd__IsType                                      0x565BF0
#define CXWnd__Move                                        0x564570
#define CXWnd__Move1                                       0x564600
#define CXWnd__ProcessTransition                           0x561980
#define CXWnd__Refade                                      0x5617B0
#define CXWnd__Resize                                      0x565410
#define CXWnd__Right                                       0x5651B0
#define CXWnd__SetFirstChildPointer                        0x562470
#define CXWnd__SetFocus                                    0x563750
#define CXWnd__SetKeyTooltip                               0x5624B0
#define CXWnd__SetMouseOver                                0x562490
#define CXWnd__SetNextSibPointer                           0x562480
#define CXWnd__StartFade                                   0x5619E0

// CSliderWnd
#define CSliderWnd__GetValue                               0x5912C0
#define CSliderWnd__SetValue                               0x591490
#define CSliderWnd__UpdateThumb                            0x591280

// CEditBaseWnd
#define CEditBaseWnd__SetMaxChars                          0x4D41EF
#define CEditBaseWnd__SetSel                               0x587A50

// CComboWnd
#define CComboWnd__DeleteAll                               0x58C9B0
#define CComboWnd__Draw                                    0x58CBB0
#define CComboWnd__GetButtonRect                           0x58C9E0
#define CComboWnd__GetCurChoice                            0x58C970
#define CComboWnd__GetListRect                             0x58CFA0
#define CComboWnd__GetTextRect                             0x58CA40
#define CComboWnd__InsertChoice                            0x58D000
#define CComboWnd__SetColors                               0x58C940
#define CComboWnd__SetChoice                               0x58D0E0

// CListWnd
#define CListWnd__AddColumn                                0x57BD80
#define CListWnd__AddColumn1                               0x57B8E0
#define CListWnd__AddLine                                  0x57B4A0
#define CListWnd__AddString                                0x57B620
#define CListWnd__CalculateFirstVisibleLine                0x578AD0
#define CListWnd__CalculateVSBRange                        0x57A640
#define CListWnd__ClearAllSel                              0x578300
#define CListWnd__CloseAndUpdateEditWindow                 0x5790D0
#define CListWnd__Compare                                  0x579410
#define CListWnd__Draw                                     0x57A2A0
#define CListWnd__DrawColumnSeparators                     0x57A100
#define CListWnd__DrawHeader                               0x578520
#define CListWnd__DrawItem                                 0x579B20
#define CListWnd__DrawLine                                 0x579E70
#define CListWnd__DrawSeparator                            0x57A1D0
#define CListWnd__EnsureVisible                            0x578B20
#define CListWnd__ExtendSel                                0x579A50
#define CListWnd__GetColumnFlags                           0x577DD0
#define CListWnd__GetColumnJustification                   0x577F70
#define CListWnd__GetColumnMinWidth                        0x577F00
#define CListWnd__GetColumnWidth                           0x577E30
#define CListWnd__GetCurSel                                0x577C10
#define CListWnd__GetHeaderRect                            0x577A50
#define CListWnd__GetItemAtPoint                           0x578DD0
#define CListWnd__GetItemAtPoint1                          0x578E40
#define CListWnd__GetItemData                              0x577C50
#define CListWnd__GetItemHeight                            0x578900
#define CListWnd__GetItemIcon                              0x577D10
#define CListWnd__GetItemRect                              0x578BF0
#define CListWnd__GetItemText                              0x577C90
#define CListWnd__GetSelList                               0x57B7C0
#define CListWnd__GetSeparatorRect                         0x579360
#define CListWnd__IsLineEnabled                            0x5783F0
#define CListWnd__RemoveLine                               0x57B770
#define CListWnd__SetColors                                0x5779C0
#define CListWnd__SetColumnWidth                           0x577EB0
#define CListWnd__SetColumnJustification                   0x577FD0
#define CListWnd__SetCurSel                                0x578220
#define CListWnd__SetItemColor                             0x57B0E0
#define CListWnd__SetItemData                              0x5783B0
#define CListWnd__SetItemText                              0x57B020
#define CListWnd__ShiftColumnSeparator                     0x5799C0
#define CListWnd__Sort                                     0x57BE20
#define CListWnd__ToggleSel                                0x578240

// CEditWnd
#define CEditWnd__DrawCaret                                0x58D440
#define CEditWnd__GetCharIndexPt                           0x58E280
#define CEditWnd__GetDisplayString                         0x58D5A0
#define CEditWnd__GetHorzOffset                            0x58D810
#define CEditWnd__GetLineForPrintableChar                  0x58DD30
#define CEditWnd__GetSelStartPt                            0x58E4A0
#define CEditWnd__GetSTMLSafeText                          0x58D9F0
#define CEditWnd__PointFromPrintableChar                   0x58DE40
#define CEditWnd__SelectableCharFromPoint                  0x58DFC0
#define CEditWnd__SetEditable                              0x58D9C0

// CGaugeWnd
#define CGaugeWnd__CalcFillRect                            0x4F2297
#define CGaugeWnd__CalcLinesFillRect                       0x4F22F3
#define CGaugeWnd__Draw                                    0x4F25F3

// CStmlWnd
#define CStmlWnd__AppendSTML                               0x576ED0
#define CStmlWnd__CalculateHSBRange                        0x56E850
#define CStmlWnd__CalculateVSBRange                        0x56E7F0
#define CStmlWnd__CanBreakAtCharacter                      0x56E990
#define CStmlWnd__CanGoBackward                            0x56EA10
#define CStmlWnd__FastForwardToEndOfTag                    0x56F760
#define CStmlWnd__GetNextChar                              0x56EE70
#define CStmlWnd__GetNextTagPiece                          0x56F560
#define CStmlWnd__GetSTMLText                              0x4E6A00
#define CStmlWnd__GetThisChar                              0x56E6B0
#define CStmlWnd__GetVisiableText                          0x570F30
#define CStmlWnd__InitializeWindowVariables                0x572CC0
#define CStmlWnd__MakeStmlColorTag                         0x56DE60
#define CStmlWnd__MakeWndNotificationTag                   0x56DF00
#define CStmlWnd__StripFirstSTMLLines                      0x576C50
#define CStmlWnd__UpdateHistoryString                      0x571370

// CTabWnd
#define CTabWnd__Draw                                      0x58C690
#define CTabWnd__DrawCurrentPage                           0x58C180
#define CTabWnd__DrawTab                                   0x58BF00
#define CTabWnd__GetCurrentPage                            0x58BAB0
#define CTabWnd__GetCurrentTabIndex                        0x58B890
#define CTabWnd__GetNumTabs                                0x58B980
#define CTabWnd__GetPageClientRect                         0x58B8A0
#define CTabWnd__GetPageFromTabIndex                       0x58B9B0
#define CTabWnd__GetPageInnerRect                          0x58B900
#define CTabWnd__GetTabInnerRect                           0x58BBC0
#define CTabWnd__GetTabRect                                0x58BAC0
#define CTabWnd__IndexInBounds                             0x58B990
#define CTabWnd__InsertPage                                0x58C580
#define CTabWnd__SetPage                                   0x58BC60
#define CTabWnd__SetPageRect                               0x58BD70
#define CTabWnd__UpdatePage                                0x58BE20

// CTextOverlay
#define CTextOverlay__DisplayText                          0x401406


/*
CListWnd__GetCurCol

CContextMenu__CContextMenu
CContextMenu__AddMenuItem
CContextMenu__AddSeparator
CContextMenu__RemoveAllMenuItems
CContextMenu__Activate
/**/