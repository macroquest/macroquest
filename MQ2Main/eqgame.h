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
//.rdata:005EA594 aJun12004       db 'Jun  1 2004',0
//.rdata:005EA5A0 a164155         db '16:41:55',0
#define __ExpectedVersionDate                         "Jun  1 2004"
#define __ExpectedVersionTime                         "16:41:55"
#define __ActualVersionDate                                0x5EA594
#define __ActualVersionTime                                0x5EA5A0

#define __ClientOverride                       0
#define __MacroQuestWinClassName                 "__MacroQuestTray"
#define __MacroQuestWinName                           "MacroQuest"

// Memory Protection
#define __MemChecker0                                      0x4C2B10
#define __MemChecker1                                      0x4C74B5
#define __MemChecker2                                      0x4C9291
#define __MemChecker3                                      0x4C932E
#define __EncryptPad0                                      0x711E28
#define __EncryptPad1                                      0x712228
#define __EncryptPad2                                      0x712CF0
#define __EncryptPad3                                      0x7130F0 

#define DI8__Main                                          0x896244
#define DI8__Keyboard                                      0x896248
#define DI8__Mouse                                         0x89624C

#define __LastTell                                         0x7D8048
#define __Guilds                                           0x838708
#define __Mouse                                            0x896250
#define __Attack                                           0x83687C
#define __InChatMode                                       0x7D5F80
#define __gWorld                                           0x838660
#define __GroupCount                                       0x836C10
#define __CommandList                                      0x70BC98
#define __DoAbilityList                                    0x80FB1C
#define __DoAbilityAvailable                               0x7D6D64
#define __ServerHost                                       0x836ACC
#define __ServerName                                       0x80FADC
#define __HWnd                                             0x7D5F40
#define __Clicks                                           0x7D6040
#define __ScreenX                                          0x7D5F48
#define __ScreenY                                          0x7D5F4C
#define __ScreenMode                                       0x722000
#define __MouseLook                                        0x7D6012
#define __EQP_IDArray                                      0x7D3000
#define __CurrentMapLabel                                  0x89F0D8
#define __BindList                                         0x70B768
#define __RangeAttackReady                                 0x7D6DC8
#define __AltTimerReady                                    0x7D6DCA
#define __Socials                                          0x80FBDC
#define __HotkeyPage                                       0x83647C
#define __CurrentSocial                                    0x618B98
#define __GroupLeader                                      0x836D6C
#define __SkillDict                                        0x723498
#define __DrawHandler                                      0x8AAE1C
#define __FriendsList                                      0x80C8DC
#define __IgnoreList                                       0x80E1DC
#define __NetStatusToggle                                  0x7D6014
#define __ShowNames                                        0x7D6FAC
#define __PCNames                                          0x7D705C
////
//Section 1: Vital Offsets
////
#define pinstCSidlManager                                  0x8AA504
#define pinstCDisplay                                      0x8386EC
#define pinstCEverQuest                                    0x8963B8
#define pinstPCData                                        0x8386C8
#define pinstCharData                                      0x8386C8
#define pinstCharSpawn                                     0x8386C0
#define pinstSpawnList                                     0x838688
#define pinstLocalPlayer                                   0x8386AC
#define pinstControlledPlayer                              0x8386C0
#define pinstWorldData                                     0x838684
#define pinstSpellManager                                  0x892DF4
#define pinstTradeTarget                                   0x8386A8
#define pinstActiveMerchant                                0x8386D8
#define pinstActiveBanker                                  0x8386DC
#define pinstActiveCorpse                                  0x8386E0
#define pinstActiveGMaster                                 0x8386E4
#define pinstSelectedItem                                  0x89EFE0
#define pinstGroup                                         0x836D58
#define pinstTarget                                        0x8386CC
#define pinstSwitchManager                                 0x7D5F30
#define pinstEQItemList                                    0x83868C
#define pinstSpellSets                                     0x836480
#define instEQZoneInfo                                     0x7D61AC
#define pinstCXWndManager                                  0x8AA4FC
#define instKeypressHandler                                0x8854C8
#define pinstStringTable                                   0x838678
#define pinstAltAdvManager                                 0x7230B0
#define instCRaid                                          0x840998

////
//Section 2:  UI Related Offsets
////
#define pinstCTextOverlay                                  0x71B820
#define pinstCharacterSelect                               0x722A94
#define pinstCFacePick                                     0x722A98
// removed 4-14 exe #define pinstCTextMessageWnd                               
#define pinstCNoteWnd                                      0x722A9C
#define pinstCHelpWnd                                      0x722AA0
#define pinstCBookWnd                                      0x722AA4
#define pinstCPetInfoWnd                                   0x722AA8
#define pinstCTrainWnd                                     0x722AAC
#define pinstCSkillsWnd                                    0x722AB0
#define pinstCSkillsSelectWnd                              0x722AB4
#define pinstCCombatSkillSelectWnd                         0x722AB8
#define pinstCFriendsWnd                                   0x722ABC
#define pinstCAAWnd                                        0x722AC0
#define pinstCGroupSearchFiltersWnd                        0x722AC4
#define pinstCLoadskinWnd                                  0x722AC8
#define pinstCAlarmWnd                                     0x722ACC
#define pinstCMusicPlayerWnd                               0x722AD0
#define pinstCRaidWnd                                      0x722AD4
#define pinstCRaidOptionsWnd                               0x722AD8
#define pinstCBreathWnd                                    0x722ADC
#define pinstCMapViewWnd                                   0x722AE0
#define pinstCMapToolbarWnd                                0x722AE4
#define pinstCEditLabelWnd                                 0x722AE8
#define pinstCTargetWnd                                    0x722AEC
#define pinstCHotButtonWnd                                 0x722AF0
#define pinstCColorPickerWnd                               0x722AF4
#define pinstCPlayerWnd                                    0x722AF8
#define pinstCOptionsWnd                                   0x722AFC
#define pinstCBuffWindowNORMAL                             0x722B00
#define pinstCBuffWindowSHORT                              0x722B04
#define pinstCharacterCreation                             0x722B08
#define pinstCCursorAttachment                             0x722B0C
#define pinstCCastingWnd                                   0x722B10
#define pinstCCastSpellWnd                                 0x722B14
#define pinstCSpellBookWnd                                 0x722B18
#define pinstCInventoryWnd                                 0x722B1C
#define pinstCBankWnd                                      0x722B20
#define pinstCQuantityWnd                                  0x722B24
#define pinstCLootWnd                                      0x722B28
#define pinstCActionsWnd                                   0x722B2C
#define pinstCCombatAbilityWnd                             0x722B30
#define pinstCMerchantWnd                                  0x722B34
#define pinstCTradeWnd                                     0x722B38
#define pinstCSelectorWnd                                  0x722B3C
#define pinstCBazaarWnd                                    0x722B40
#define pinstCBazaarSearchWnd                              0x722B44
#define pinstCGiveWnd                                      0x722B48
#define pinstCTrackingWnd                                  0x722B4C
#define pinstCInspectWnd                                   0x722B50
#define pinstCSocialEditWnd                                0x722B54
#define pinstCFeedbackWnd                                  0x722B58
#define pinstCBugReportWnd                                 0x722B5C
#define pinstCVideoModesWnd                                0x722B60
#define pinstCTextEntryWnd                                 0x722B64
#define pinstCFileSelectionWnd                             0x722B68
#define pinstCCompassWnd                                   0x722B6C
#define pinstCPlayerNotesWnd                               0x722B70
#define pinstCGemsGameWnd                                  0x722B74
#define pinstCTimeLeftWnd                                  0x722B78
#define pinstCPetitionQWnd                                 0x722B7C
#define pinstCSoulmarkWnd                                  0x722B80
#define pinstCStoryWnd                                     0x722B84
#define pinstCJournalTextWnd                               0x722B88
#define pinstCJournalCatWnd                                0x722B8C
#define pinstCBodyTintWnd                                  0x722B90
#define pinstCInvSlotMgr                                   0x722B94
#define pinstCContainerMgr                                 0x722B98
#define pinstCAdventureLeaderboardWnd                      0x89EA98
#define pinstCAdventureMerchantWnd                         0x89EAB0
#define pinstCAdventureRequestWnd                          0x89EAC8
#define pinstCAdventureStatsWnd                            0x89EAE0
#define pinstCChatManager                                  0x89ED70
#define pinstCDynamicZoneWnd                               0x89EE28
#define pinstCFindLocationWnd                              0x89EEB8
#define pinstCGroupSearchWnd                               0x89EF34
#define pinstCGroupWnd                                     0x89EF4C
#define pinstCGuildMgmtWnd                                 0x89EF64
#define pinstCItemDisplayManager                           0x89F00C
#define pinstCLeadershipWnd                                0x89F074
#define pinstCPopupWndManager                              0x89F1C4
#define pinstCSystemInfoDialogBox                          0x89FAA4
#define pinstCTargetOfTargetWnd                            0x89FABC
#define pinstCTipWndOFDAY                                  0x89FB70
#define pinstCTipWndCONTEXT                                0x89FB74
#define pinstCTradeskillWnd                                0x89FBA0
#define pinstCTributeBenefitWnd                            0x89FBE0
#define pinstCTributeMasterWnd                             0x89FBF8
#define pinstCContextMenuManager                           0x8AA520
// unknown window added 4-14 exe 0x79A234


////
// Section 3: Miscellaneous Offsets
////
#define DrawNetStatus                                      0x4B6E2D
#define CrashDetected                                      0x4C8F8F
#define __ProcessGameEvents                                0x4AD453
#define __ConvertItemTags                                  0x45B54C
#define __SendMessage                                      0x4BCC43
#define __NewUIINI                                         0x52987A
#define __ExecuteCmd                                       0x44E1CB
#define __GetGaugeValueFromEQ                              0x5280DF
#define __get_melee_range                                  0x452C69

// EQ_LoadingS
#define EQ_LoadingS__WriteTextHD                           0x432B27


////
// Section 4: Function Offsets
////
// CEverQuest
#define CEverQuest__dsp_chat                               0x49D2D7
#define CEverQuest__ClickedPlayer                          0x49A463
#define CEverQuest__EnterZone                              0x49E002
#define CEverQuest__GetBodyTypeDesc                        0x494248
#define CEverQuest__GetClassDesc                           0x493CCA
#define CEverQuest__GetClassThreeLetterCode                0x4940E5
#define CEverQuest__GetDeityDesc                           0x495CDB
#define CEverQuest__GetRaceDesc                            0x49454D
#define CEverQuest__GetTitleDesc                           0x495DF2
#define CEverQuest__InterpretCmd                           0x4A9E80
#define CEverQuest__LeftClickedOnPlayer                    0x4AC057
#define CEverQuest__RightClickedOnPlayer                   0x4A4BE2
#define CEverQuest__SetGameState                           0x49A5CA
#define CEverQuest__DropHeldItemOnGround                   0x49CD98

// StringTable
#define StringTable__getString                             0x4BFDD6

// AltAdvManager
#define AltAdvManager__IsAbilityReady                      0x41D50A

// CXWndManager
#define CXWndManager__RemoveWnd                            0x579B50
#define CXWndManager__GetKeyboardFlags                     0x579770
#define CXWndManager__HandleKeyboardMsg                    0x579C40
#define CXWndManager__DrawWindows                          0x57AA60
#define CXWndManager__DrawCursor                           0x57AE10
#define CXWndManager__GetFirstChildWnd                     0x57A330

// KeyPressHandler
#define KeypressHandler__HandleKeyDown                     0x4B208E
#define KeypressHandler__HandleKeyUp                       0x4B2333
#define KeypressHandler__AttachKeyToEqCommand              0x4B374B
#define KeypressHandler__AttachAltKeyToEqCommand           0x4B3788
#define KeypressHandler__SaveKeymapping                    0x4B3633
#define KeypressHandler__ClearCommandStateArray            0x4B2321

// EQ_Character
#define EQ_Character__Max_Endurance                        0x41D6AF
#define EQ_Character__Max_Mana                             0x421072
#define EQ_Character__Max_HP                               0x420EBD
#define EQ_Character__Cur_HP                               0x422A33
#define EQ_Character__GetFocusCastingTimeModifier          0x428DE8
#define EQ_Character__GetAACastingTimeModifier             0x42917C
#define EQ_Character__CastSpell                            0x42CD7B
#define EQ_Character__GetAbility                           0x420918

// EQPlayer
#define EQPlayer__EQPlayer                                 0x48886F
#define EQPlayer__dEQPlayer                                0x48812C
#define EQPlayer__DoAttack                                 0x4846BB
#define EQPlayer__ChangeBoneStringSprite                   0x466731
#define EQPlayer__SetNameSpriteState                       0x482C51
#define EQPlayer__SetNameSpriteTint                        0x46679D

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr                                       0x4010c0
#define CXStr__CXStr1                                      0x55D970
#define CXStr__CXStr3                                      0x5ABFA0
#define CXStr__dCXStr                                      0x4010EA
#define CXStr__operator_plus_equal1                        0x5AD030
#define CXStr__operator_equal1                             0x5AC160

// CChatWindow
#define CChatWindow__CChatWindow                           0x4E612E

// CChatManager
#define CChatManager__GetRGBAFromIndex                     0x4E2BD8
#define CChatManager__InitContextMenu                      0x4E353C

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot                           0x500E49
#define CInvSlotMgr__MoveItem                              0x5007F8

// CItemDisplayWnd
#define CItemDisplayWnd__SetItem                           0x503DA7
#define CItemDisplayWnd__SetSpell                          0x5031EA

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton                         0x4FD5F5

// CLabel
#define CLabel__Draw                                       0x509EB2

// CGauge
#define CGaugeWnd__Draw                                    0x4F1D3E

// CDisplay
#define CDisplay__ReloadUI                                 0x4175E3
#define CDisplay__CleanGameUI                              0x41046D
#define CDisplay__GetClickedActor                          0x40D6A5
#define CDisplay__WriteTextHD2                             0x410F43
#define CDisplay__GetWorldFilePath                         0x40C2A7
#define CDisplay__GetUserDefinedColor                      0x40CAA0

#define CTextureFont__DrawWrappedText                      0x569EB0

// EQ_Item
#define EQ_Item__GetItemLinkHash                           0x43261E
#define EQ_Item__CanDrop                                   0x432716

// CBankWnd
#define CBankWnd__GetNumBankSlots                          0x4D3F42

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg                  0x4D6A5F

// CMerchantWnd
#define CMerchantWnd__SelectBuySellSlot                    0x513006
#define CMerchantWnd__RequestBuyItem                       0x5121F8
#define CMerchantWnd__RequestSellItem                      0x512576
#define CMerchantWnd__DisplayBuyOrSellPrice                0x51202D

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet                         0x526AE9

// MapViewMap
#define MapViewMap__SaveEx                                 0x50D82A
#define MapViewMap__Clear                                  0x50D6B9


// CMapViewWnd
#define CMapViewWnd__CMapViewWnd                           0x5110EE

// EQItemList
#define EQItemList__EQItemList                             0x450AE0
#define EQItemList__dEQItemList                            0x450B5C

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney                      0x4355C6

// CContainerWnd
#define CContainerWnd__HandleCombine                       0x4EA367
#define CContainerWnd__vftable                             0x5EE9B0

// CSidlScreenWnd
#define CSidlScreenWnd__CSidlScreenWnd1                    0x55d880
#define CSidlScreenWnd__dCSidlScreenWnd                    0x55CF20
#define CSidlScreenWnd__CreateChildrenFromSidl             0x55C290
#define CSidlScreenWnd__WndNotification                    0x55BE10
#define CSidlScreenWnd__CalculateHSBRange                  0x55B3A0
#define CSidlScreenWnd__CalculateVSBRange                  0x55B2E0
#define CSidlScreenWnd__ConvertToRes                       0x55BA90
#define CSidlScreenWnd__CSidlScreenWnd2                    0x55D880
#define CSidlScreenWnd__DrawSidlPiece                      0x55BEB0
#define CSidlScreenWnd__EnableIniStorage                   0x55BA40
#define CSidlScreenWnd__GetSidlPiece                       0x55C150
#define CSidlScreenWnd__Init1                              0x55D5D0
#define CSidlScreenWnd__LoadIniInfo                        0x55C340
#define CSidlScreenWnd__LoadIniListWnd                     0x55CC80
#define CSidlScreenWnd__LoadSidlScreen                     0x55BCF0
#define CSidlScreenWnd__SetScreen                          0x55D040
#define CSidlScreenWnd__StoreIniInfo                       0x55B5D0

// CSidlManager
#define CSidlManager__FindScreenPieceTemplate1             0x582120

// CXMLDataManager
#define CXMLDataManager__GetXMLData                        0x58EDD0

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead                       0x5697D0

// CXRect
#define CXRect__CenterPoint                                0x4D3F49

// CXWnd
#define CXWnd__BringToTop                                  0x55E000
#define CXWnd__Center                                      0x561670
#define CXWnd__ClrFocus                                    0x55DD50
#define CXWnd__DoAllDrawing                                0x562280
#define CXWnd__DrawChildren                                0x5623B0
#define CXWnd__DrawColoredRect                             0x55E230
#define CXWnd__DrawTooltipAtPoint                          0x5614A0
#define CXWnd__GetBorderFrame                              0x55E680
#define CXWnd__GetChildWndAt                               0x561030
#define CXWnd__GetClientClipRect                           0x55E5C0
#define CXWnd__GetFirstChildWnd                            0x55E090
#define CXWnd__GetNextChildWnd                             0x561010
#define CXWnd__GetNextSib                                  0x55E0B0
#define CXWnd__GetScreenClipRect                           0x561900
#define CXWnd__GetScreenRect                               0x55E850
#define CXWnd__GetTooltipRect                              0x5613F0
#define CXWnd__GetWindowTextA                              0x4CE9FC
#define CXWnd__GetXMLTooltip                               0x55DB90
#define CXWnd__IsActive                                    0x55E630
#define CXWnd__IsDescendantOf                              0x55E640
#define CXWnd__IsReallyVisible                             0x560FF0
#define CXWnd__IsType                                      0x562220
#define CXWnd__Move                                        0x560BA0
#define CXWnd__Move1                                       0x560C30
#define CXWnd__ProcessTransition                           0x55DFC0
#define CXWnd__Refade                                      0x55DDF0
#define CXWnd__Resize                                      0x561A40
#define CXWnd__Right                                       0x5617E0
#define CXWnd__SetFirstChildPointer                        0x55EAA0
#define CXWnd__SetFocus                                    0x55FD80
#define CXWnd__SetKeyTooltip                               0x55EAE0
#define CXWnd__SetMouseOver                                0x55EAC0
#define CXWnd__SetNextSibPointer                           0x55EAB0
#define CXWnd__StartFade                                   0x55E020

// CSliderWnd
#define CSliderWnd__GetValue                               0x58D950
#define CSliderWnd__SetValue                               0x58DB20
#define CSliderWnd__UpdateThumb                            0x58D910

// CEditBaseWnd
#define CEditBaseWnd__SetMaxChars                          0x4D3AB8
#define CEditBaseWnd__SetSel                               0x5840C0

// CComboWnd
#define CComboWnd__DeleteAll                               0x589040
#define CComboWnd__Draw                                    0x589240
#define CComboWnd__GetButtonRect                           0x589070
#define CComboWnd__GetCurChoice                            0x589000
#define CComboWnd__GetListRect                             0x589630
#define CComboWnd__GetTextRect                             0x5890D0
#define CComboWnd__InsertChoice                            0x589690
#define CComboWnd__SetColors                               0x588FD0
#define CComboWnd__SetChoice                               0x589770

// CListWnd
#define CListWnd__AddColumn                                0x578460
#define CListWnd__AddColumn1                               0x577FC0
#define CListWnd__AddLine                                  0x577B80
#define CListWnd__AddString                                0x577D00
#define CListWnd__CalculateFirstVisibleLine                0x5751B0
#define CListWnd__CalculateVSBRange                        0x576D20
#define CListWnd__ClearAllSel                              0x5749E0
#define CListWnd__CloseAndUpdateEditWindow                 0x5757B0
#define CListWnd__Compare                                  0x575AF0
#define CListWnd__Draw                                     0x576980
#define CListWnd__DrawColumnSeparators                     0x5767E0
#define CListWnd__DrawHeader                               0x574C00
#define CListWnd__DrawItem                                 0x576200
#define CListWnd__DrawLine                                 0x576550
#define CListWnd__DrawSeparator                            0x5768B0
#define CListWnd__EnsureVisible                            0x575200
#define CListWnd__ExtendSel                                0x576130
#define CListWnd__GetColumnFlags                           0x5744B0
#define CListWnd__GetColumnJustification                   0x574650
#define CListWnd__GetColumnMinWidth                        0x5745E0
#define CListWnd__GetColumnWidth                           0x574510
#define CListWnd__GetCurSel                                0x5742F0
#define CListWnd__GetHeaderRect                            0x574130
#define CListWnd__GetItemAtPoint                           0x5754B0
#define CListWnd__GetItemAtPoint1                          0x575520
#define CListWnd__GetItemData                              0x574330
#define CListWnd__GetItemHeight                            0x574FE0
#define CListWnd__GetItemIcon                              0x5743F0
#define CListWnd__GetItemRect                              0x5752D0
#define CListWnd__GetItemText                              0x574370
#define CListWnd__GetSelList                               0x577EA0
#define CListWnd__GetSeparatorRect                         0x575A40
#define CListWnd__IsLineEnabled                            0x574AD0
#define CListWnd__RemoveLine                               0x577E50
#define CListWnd__SetColors                                0x5740A0
#define CListWnd__SetColumnWidth                           0x574590
#define CListWnd__SetColumnJustification                   0x5746B0
#define CListWnd__SetCurSel                                0x574900
#define CListWnd__SetItemColor                             0x5777C0
#define CListWnd__SetItemData                              0x574A90
#define CListWnd__SetItemText                              0x577700
#define CListWnd__ShiftColumnSeparator                     0x5760A0
#define CListWnd__Sort                                     0x578500
#define CListWnd__ToggleSel                                0x574920

// CEditWnd
#define CEditWnd__DrawCaret                                0x589AD0
#define CEditWnd__GetCharIndexPt                           0x58A910
#define CEditWnd__GetDisplayString                         0x589C30
#define CEditWnd__GetHorzOffset                            0x589EA0
#define CEditWnd__GetLineForPrintableChar                  0x58A3C0
#define CEditWnd__GetSelStartPt                            0x58AB30
#define CEditWnd__GetSTMLSafeText                          0x58A080
#define CEditWnd__PointFromPrintableChar                   0x58A4D0
#define CEditWnd__SelectableCharFromPoint                  0x58A650
#define CEditWnd__SetEditable                              0x58A050

// CGaugeWnd
#define CGaugeWnd__CalcFillRect                            0x4F19E2
#define CGaugeWnd__CalcLinesFillRect                       0x4F1A3E
#define CGaugeWnd__Draw                                    0x4F1D3E

// CStmlWnd
#define CStmlWnd__AppendSTML                               0x5735B0
#define CStmlWnd__CalculateHSBRange                        0x56AF10
#define CStmlWnd__CalculateVSBRange                        0x56AEB0
#define CStmlWnd__CanBreakAtCharacter                      0x56B050
#define CStmlWnd__CanGoBackward                            0x56B0D0
#define CStmlWnd__FastForwardToEndOfTag                    0x56BDD0
#define CStmlWnd__GetNextChar                              0x56B520
#define CStmlWnd__GetNextTagPiece                          0x56BBD0
#define CStmlWnd__GetSTMLText                              0x4E6110
#define CStmlWnd__GetThisChar                              0x56AD70
#define CStmlWnd__GetVisiableText                          0x56D5A0
#define CStmlWnd__InitializeWindowVariables                0x56F3A0
#define CStmlWnd__MakeStmlColorTag                         0x56A520
#define CStmlWnd__MakeWndNotificationTag                   0x56A5C0
#define CStmlWnd__StripFirstSTMLLines                      0x573330
#define CStmlWnd__UpdateHistoryString                      0x56D9E0

// CTabWnd
#define CTabWnd__Draw                                      0x588D20
#define CTabWnd__DrawCurrentPage                           0x588810
#define CTabWnd__DrawTab                                   0x588590
#define CTabWnd__GetCurrentPage                            0x588140
#define CTabWnd__GetCurrentTabIndex                        0x587F10
#define CTabWnd__GetNumTabs                                0x588010
#define CTabWnd__GetPageClientRect                         0x587F20
#define CTabWnd__GetPageFromTabIndex                       0x588040
#define CTabWnd__GetPageInnerRect                          0x587F80
#define CTabWnd__GetTabInnerRect                           0x588250
#define CTabWnd__GetTabRect                                0x588150
#define CTabWnd__IndexInBounds                             0x588020
#define CTabWnd__InsertPage                                0x588C10
#define CTabWnd__SetPage                                   0x5882F0
#define CTabWnd__SetPageRect                               0x588400
#define CTabWnd__UpdatePage                                0x5884B0

// CTextOverlay
#define CTextOverlay__DisplayText                          0x401406
