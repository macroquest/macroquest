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
//.rdata:005EA5EC aMay242004      db 'May 24 2004',0
//.rdata:005EA5F8 a151623         db '15:16:23',0
#define __ExpectedVersionDate                         "May 24 2004"
#define __ExpectedVersionTime                         "15:16:23"
#define __ActualVersionDate                                0x5EA5EC
#define __ActualVersionTime                                0x5EA5F8

#define __ClientOverride                       0
#define __MacroQuestWinClassName                 "__MacroQuestTray"
#define __MacroQuestWinName                           "MacroQuest"

// Memory Protection
#define __MemChecker0                                      0x4C2B68
#define __MemChecker1                                      0x4C752F
#define __MemChecker2                                      0x4C930B
#define __MemChecker3                                      0x4C93A8
#define __EncryptPad0                                      0x622A08
#define __EncryptPad1                                      0x622E08
#define __EncryptPad2                                      0x6238D0
#define __EncryptPad3                                      0x623CD0

#define DI8__Main                                          0x7A6E04
#define DI8__Keyboard                                      0x7A6E08
#define DI8__Mouse                                         0x7A6E0C

#define __LastTell                                         0x6E8C08
#define __Guilds                                           0x7492C8
#define __Mouse                                            0x7A6E10
#define __Attack                                           0x74743C
#define __InChatMode                                       0x6E6B40
#define __gWorld                                           0x749220
#define __GroupCount                                       0x7477D0
#define __CommandList                                      0x61C878
#define __DoAbilityList                                    0x7206DC
#define __DoAbilityAvailable                               0x6E7924
#define __ServerHost                                       0x74768C
#define __ServerName                                       0x72069C
#define __HWnd                                             0x6E6B00
#define __Clicks                                           0x6E6C00
#define __ScreenX                                          0x6E6B08
#define __ScreenY                                          0x6E6B0C
#define __ScreenMode                                       0x632BC0
#define __MouseLook                                        0x6E6BD2
#define __EQP_IDArray                                      0x6E3BC0
#define __CurrentMapLabel                                  0x7AFC98
#define __BindList                                         0x61C348
#define __RangeAttackReady                                 0x6E7988
#define __AltTimerReady                                    0x6E798A
#define __Socials                                          0x72079C
#define __HotkeyPage                                       0x74703C
#define __CurrentSocial                                    0x618B98
#define __GroupLeader                                      0x74792C
#define __SkillDict                                        0x634058
#define __DrawHandler                                      0x7BB99C
#define __FriendsList                                      0x71D49C
#define __IgnoreList                                       0x71ED9C
#define __NetStatusToggle                                  0x6E6BD4
#define __ShowNames                                        0x6E7B6C
#define __PCNames                                          0x6E7C1C
////
//Section 1: Vital Offsets
////
#define pinstCSidlManager                                  0x7BB0C4
#define pinstCDisplay                                      0x7492AC
#define pinstCEverQuest                                    0x7A6F78
#define pinstPCData                                        0x749288
#define pinstCharData                                      0x749288
#define pinstCharSpawn                                     0x749280
#define pinstSpawnList                                     0x749248
#define pinstLocalPlayer                                   0x74926C
#define pinstControlledPlayer                              0x749280
#define pinstWorldData                                     0x749244
#define pinstSpellManager                                  0x7A39B4
#define pinstTradeTarget                                   0x749268
#define pinstActiveMerchant                                0x749298
#define pinstActiveBanker                                  0x74929C
#define pinstActiveCorpse                                  0x7492A0
#define pinstActiveGMaster                                 0x7492A4
#define pinstSelectedItem                                  0x7AFBA0
#define pinstGroup                                         0x747918
#define pinstTarget                                        0x74928C
#define pinstSwitchManager                                 0x6E6AF0
#define pinstEQItemList                                    0x74924C
#define pinstSpellSets                                     0x747040
#define instEQZoneInfo                                     0x6E6D6C
#define pinstCXWndManager                                  0x7BB0BC
#define instKeypressHandler                                0x796088
#define pinstStringTable                                   0x749238
#define pinstAltAdvManager                                 0x633C70
#define instCRaid                                          0x751558

////
//Section 2:  UI Related Offsets
////
#define pinstCTextOverlay                                  0x62C3E0
#define pinstCharacterSelect                               0x633654
#define pinstCFacePick                                     0x633658
// removed 4-14 exe #define pinstCTextMessageWnd                               
#define pinstCNoteWnd                                      0x63365C
#define pinstCHelpWnd                                      0x633660
#define pinstCBookWnd                                      0x633664
#define pinstCPetInfoWnd                                   0x633668
#define pinstCTrainWnd                                     0x63366C
#define pinstCSkillsWnd                                    0x633670
#define pinstCSkillsSelectWnd                              0x633674
#define pinstCCombatSkillSelectWnd                         0x633678
#define pinstCFriendsWnd                                   0x63367C
#define pinstCAAWnd                                        0x633680
#define pinstCGroupSearchFiltersWnd                        0x633684
#define pinstCLoadskinWnd                                  0x633688
#define pinstCAlarmWnd                                     0x63368C
#define pinstCMusicPlayerWnd                               0x633690
#define pinstCRaidWnd                                      0x633694
#define pinstCRaidOptionsWnd                               0x633698
#define pinstCBreathWnd                                    0x63369C
#define pinstCMapViewWnd                                   0x6336A0
#define pinstCMapToolbarWnd                                0x6336A4
#define pinstCEditLabelWnd                                 0x6336A8
#define pinstCTargetWnd                                    0x6336AC
#define pinstCHotButtonWnd                                 0x6336B0
#define pinstCColorPickerWnd                               0x6336B4
#define pinstCPlayerWnd                                    0x6336B8
#define pinstCOptionsWnd                                   0x6336BC
#define pinstCBuffWindowNORMAL                             0x6336C0
#define pinstCBuffWindowSHORT                              0x6336C4
#define pinstCharacterCreation                             0x6336C8
#define pinstCCursorAttachment                             0x6336CC
#define pinstCCastingWnd                                   0x6336D0
#define pinstCCastSpellWnd                                 0x6336D4
#define pinstCSpellBookWnd                                 0x6336D8
#define pinstCInventoryWnd                                 0x6336DC
#define pinstCBankWnd                                      0x6336E0
#define pinstCQuantityWnd                                  0x6336E4
#define pinstCLootWnd                                      0x6336E8
#define pinstCActionsWnd                                   0x6336EC
#define pinstCCombatAbilityWnd                             0x6336F0
#define pinstCMerchantWnd                                  0x6336F4
#define pinstCTradeWnd                                     0x6336F8
#define pinstCSelectorWnd                                  0x6336FC
#define pinstCBazaarWnd                                    0x633700
#define pinstCBazaarSearchWnd                              0x633704
#define pinstCGiveWnd                                      0x633708
#define pinstCTrackingWnd                                  0x63370C
#define pinstCInspectWnd                                   0x633710
#define pinstCSocialEditWnd                                0x633714
#define pinstCFeedbackWnd                                  0x633718
#define pinstCBugReportWnd                                 0x63371C
#define pinstCVideoModesWnd                                0x633720
#define pinstCTextEntryWnd                                 0x633724
#define pinstCFileSelectionWnd                             0x633728
#define pinstCCompassWnd                                   0x63372C
#define pinstCPlayerNotesWnd                               0x633730
#define pinstCGemsGameWnd                                  0x633734
#define pinstCTimeLeftWnd                                  0x633738
#define pinstCPetitionQWnd                                 0x63373C
#define pinstCSoulmarkWnd                                  0x633740
#define pinstCStoryWnd                                     0x633744
#define pinstCJournalTextWnd                               0x633748
#define pinstCJournalCatWnd                                0x63374C
#define pinstCBodyTintWnd                                  0x633750
#define pinstCInvSlotMgr                                   0x633754
#define pinstCContainerMgr                                 0x633758
#define pinstCAdventureLeaderboardWnd                      0x7AF658
#define pinstCAdventureMerchantWnd                         0x7AF670
#define pinstCAdventureRequestWnd                          0x7AF688
#define pinstCAdventureStatsWnd                            0x7AF6A0
#define pinstCChatManager                                  0x7AF930
#define pinstCDynamicZoneWnd                               0x7AF9E8
#define pinstCFindLocationWnd                              0x7AFA78
#define pinstCGroupSearchWnd                               0x7AFAF4
#define pinstCGroupWnd                                     0x7AFB0C
#define pinstCGuildMgmtWnd                                 0x7AFB24
#define pinstCItemDisplayManager                           0x7AFBCC
#define pinstCLeadershipWnd                                0x7AFC34
#define pinstCPopupWndManager                              0x7AFD84
#define pinstCSystemInfoDialogBox                          0x7B0664
#define pinstCTargetOfTargetWnd                            0x7B067C
#define pinstCTipWndOFDAY                                  0x7B0730
#define pinstCTipWndCONTEXT                                0x7B0734
#define pinstCTradeskillWnd                                0x7B0760
#define pinstCTributeBenefitWnd                            0x7B07A0
#define pinstCTributeMasterWnd                             0x7B07B8
#define pinstCContextMenuManager                           0x7BB0E0
// unknown window added 4-14 exe 0x79A234


////
// Section 3: Miscellaneous Offsets
////
#define DrawNetStatus                                      0x4B6DEE
#define CrashDetected                                      0x4C9009
#define __ProcessGameEvents                                0x4AD3E6
#define __ConvertItemTags                                  0x45B369
#define __SendMessage                                      0x4BCBEB
#define __NewUIINI                                         0x529891
#define __ExecuteCmd                                       0x44DF10
#define __GetGaugeValueFromEQ                              0x5280F6
#define __get_melee_range                                  0x452B01

// EQ_LoadingS
#define EQ_LoadingS__WriteTextHD                           0x432989


////
// Section 4: Function Offsets
////
// CEverQuest
#define CEverQuest__dsp_chat                               0x49D26A
#define CEverQuest__ClickedPlayer                          0x49A3F6
#define CEverQuest__EnterZone                              0x49DF95
#define CEverQuest__GetBodyTypeDesc                        0x4941DB
#define CEverQuest__GetClassDesc                           0x493C5D
#define CEverQuest__GetClassThreeLetterCode                0x494078
#define CEverQuest__GetDeityDesc                           0x495C6E
#define CEverQuest__GetRaceDesc                            0x4944E0
#define CEverQuest__GetTitleDesc                           0x495D85
#define CEverQuest__InterpretCmd                           0x4A9E13
#define CEverQuest__LeftClickedOnPlayer                    0x4ABFEA
#define CEverQuest__RightClickedOnPlayer                   0x4A4B75
#define CEverQuest__SetGameState                           0x49A55D
#define CEverQuest__DropHeldItemOnGround                   0x49CD2B

// StringTable
#define StringTable__getString                             0x4BFDA6

// AltAdvManager
#define AltAdvManager__IsAbilityReady                      0x41D3C3

// CXWndManager
#define CXWndManager__RemoveWnd                            0x5799F0
#define CXWndManager__GetKeyboardFlags                     0x579580
#define CXWndManager__HandleKeyboardMsg                    0x579AE0
#define CXWndManager__DrawWindows                          0x57A850
#define CXWndManager__DrawCursor                           0x57AC00
#define CXWndManager__GetFirstChildWnd                     0x57A1D0

// KeyPressHandler
#define KeypressHandler__HandleKeyDown                     0x4B2021
#define KeypressHandler__HandleKeyUp                       0x4B22C6
#define KeypressHandler__AttachKeyToEqCommand              0x4B36DE
#define KeypressHandler__AttachAltKeyToEqCommand           0x4B371B
#define KeypressHandler__SaveKeymapping                    0x4B35C6
#define KeypressHandler__ClearCommandStateArray            0x4B22B4

// EQ_Character
#define EQ_Character__Max_Endurance                        0x41D568
#define EQ_Character__Max_Mana                             0x420F37
#define EQ_Character__Max_HP                               0x420D82
#define EQ_Character__Cur_HP                               0x4228F8
#define EQ_Character__GetFocusCastingTimeModifier          0x428CAF
#define EQ_Character__GetAACastingTimeModifier             0x429043
#define EQ_Character__CastSpell                            0x42CBA7
#define EQ_Character__GetAbility                           0x4207DD

// EQPlayer
#define EQPlayer__EQPlayer                                 0x4888E8
#define EQPlayer__dEQPlayer                                0x4881A5
#define EQPlayer__DoAttack                                 0x484786
#define EQPlayer__ChangeBoneStringSprite                   0x46682E
#define EQPlayer__SetNameSpriteState                       0x482D3B
#define EQPlayer__SetNameSpriteTint                        0x46689A

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr                                       0x4010C0
#define CXStr__CXStr1                                      0x55D810
#define CXStr__CXStr3                                      0x5ABE30
#define CXStr__dCXStr                                      0x4D3F22
#define CXStr__operator_plus_equal1                        0x5ACEC0
#define CXStr__operator_equal1                             0x5ABFF0

// CChatWindow
#define CChatWindow__CChatWindow                           0x4E6189

// CChatManager
#define CChatManager__GetRGBAFromIndex                     0x4E2C33
#define CChatManager__InitContextMenu                      0x4E3597

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot                           0x500ED7
#define CInvSlotMgr__MoveItem                              0x500886

// CItemDisplayWnd
#define CItemDisplayWnd__SetItem                           0x503E00
#define CItemDisplayWnd__SetSpell                          0x503243

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton                         0x4FD686

// CLabel
#define CLabel__Draw                                       0x509F3E

// CGauge
#define CGaugeWnd__Draw                                    0x4F1DD2

// CDisplay
#define CDisplay__ReloadUI                                 0x417519
#define CDisplay__CleanGameUI                              0x410402
#define CDisplay__GetClickedActor                          0x40D654
#define CDisplay__WriteTextHD2                             0x410ED8
#define CDisplay__GetWorldFilePath                         0x40C256
#define CDisplay__GetUserDefinedColor                      0x40CA4F

#define CTextureFont__DrawWrappedText                      0x569D70

// EQ_Item
#define EQ_Item__GetItemLinkHash                           0x432480
#define EQ_Item__CanDrop                                   0x432578

// CBankWnd
#define CBankWnd__GetNumBankSlots                          0x4D400E

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg                  0x4D6B30

// CMerchantWnd
#define CMerchantWnd__SelectBuySellSlot                    0x51308D
#define CMerchantWnd__RequestBuyItem                       0x51227F
#define CMerchantWnd__RequestSellItem                      0x5125FD
#define CMerchantWnd__DisplayBuyOrSellPrice                0x5120B4

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet                         0x526AFA

// MapViewMap
#define MapViewMap__SaveEx                                 0x50D8B1
#define MapViewMap__Clear                                  0x50D740


// CMapViewWnd
#define CMapViewWnd__CMapViewWnd                           0x511175

// EQItemList
#define EQItemList__EQItemList                             0x450825
#define EQItemList__dEQItemList                            0x4508A1

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney                      0x4354ED

// CContainerWnd
#define CContainerWnd__HandleCombine                       0x4EA3D7
#define CContainerWnd__vftable                             0x5EEA08

// CSidlScreenWnd
#define CSidlScreenWnd__CSidlScreenWnd1                    0x55D720
#define CSidlScreenWnd__dCSidlScreenWnd                    0x55CDC0
#define CSidlScreenWnd__CreateChildrenFromSidl             0x55C100
#define CSidlScreenWnd__WndNotification                    0x55BC80
#define CSidlScreenWnd__CalculateHSBRange                  0x55B2A0
#define CSidlScreenWnd__CalculateVSBRange                  0x55B1E0
#define CSidlScreenWnd__ConvertToRes                       0x55B990
#define CSidlScreenWnd__CSidlScreenWnd2                    0x55D720
#define CSidlScreenWnd__DrawSidlPiece                      0x55BD20
#define CSidlScreenWnd__EnableIniStorage                   0x55B940
#define CSidlScreenWnd__GetSidlPiece                       0x55BFC0
#define CSidlScreenWnd__Init1                              0x55D470
#define CSidlScreenWnd__LoadIniInfo                        0x55C1B0
#define CSidlScreenWnd__LoadIniListWnd                     0x55CAF0
#define CSidlScreenWnd__LoadSidlScreen                     0x55BB60
#define CSidlScreenWnd__SetScreen                          0x55CEE0
#define CSidlScreenWnd__StoreIniInfo                       0x55B4D0

// CSidlManager
#define CSidlManager__FindScreenPieceTemplate1             0x581EF0

// CXMLDataManager
#define CXMLDataManager__GetXMLData                        0x58EBF0

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead                       0x569690

// CXRect
#define CXRect__CenterPoint                                0x4D4015

// CXWnd
#define CXWnd__BringToTop                                  0x55DED0
#define CXWnd__Center                                      0x561530
#define CXWnd__ClrFocus                                    0x55DC10
#define CXWnd__DoAllDrawing                                0x562140
#define CXWnd__DrawChildren                                0x562270
#define CXWnd__DrawColoredRect                             0x55E100
#define CXWnd__DrawTooltipAtPoint                          0x561360
#define CXWnd__GetBorderFrame                              0x55E540
#define CXWnd__GetChildWndAt                               0x560EF0
#define CXWnd__GetClientClipRect                           0x55E490
#define CXWnd__GetFirstChildWnd                            0x55DF60
#define CXWnd__GetNextChildWnd                             0x560ED0
#define CXWnd__GetNextSib                                  0x55DF80
#define CXWnd__GetScreenClipRect                           0x5617C0
#define CXWnd__GetScreenRect                               0x55E710
#define CXWnd__GetTooltipRect                              0x5612B0
#define CXWnd__GetWindowTextA                              0x4CEA76
#define CXWnd__GetXMLTooltip                               0x55DA50
#define CXWnd__IsActive                                    0x55E500
#define CXWnd__IsDescendantOf                              0x55E510
#define CXWnd__IsReallyVisible                             0x560EB0
#define CXWnd__IsType                                      0x5620E0
#define CXWnd__Move                                        0x560A60
#define CXWnd__Move1                                       0x560AF0
#define CXWnd__ProcessTransition                           0x55DE90
#define CXWnd__Refade                                      0x55DCC0
#define CXWnd__Resize                                      0x561900
#define CXWnd__Right                                       0x5616A0
#define CXWnd__SetFirstChildPointer                        0x55E960
#define CXWnd__SetFocus                                    0x55FC40
#define CXWnd__SetKeyTooltip                               0x55E9A0
#define CXWnd__SetMouseOver                                0x55E980
#define CXWnd__SetNextSibPointer                           0x55E970
#define CXWnd__StartFade                                   0x55DEF0

// CSliderWnd
#define CSliderWnd__GetValue                               0x58D7A0
#define CSliderWnd__SetValue                               0x58D980
#define CSliderWnd__UpdateThumb                            0x58D760

// CEditBaseWnd
#define CEditBaseWnd__SetMaxChars                          0x4D3B70
#define CEditBaseWnd__SetSel                               0x583E90

// CComboWnd
#define CComboWnd__DeleteAll                               0x588EC0
#define CComboWnd__Draw                                    0x5890C0
#define CComboWnd__GetButtonRect                           0x588EF0
#define CComboWnd__GetCurChoice                            0x588E80
#define CComboWnd__GetListRect                             0x5894B0
#define CComboWnd__GetTextRect                             0x588F50
#define CComboWnd__InsertChoice                            0x589510
#define CComboWnd__SetColors                               0x588E50
#define CComboWnd__SetChoice                               0x5895F0

// CListWnd
#define CListWnd__AddColumn                                0x578280
#define CListWnd__AddColumn1                               0x577DE0
#define CListWnd__AddLine                                  0x5779A0
#define CListWnd__AddString                                0x577B20
#define CListWnd__CalculateFirstVisibleLine                0x574FD0
#define CListWnd__CalculateVSBRange                        0x576B40
#define CListWnd__ClearAllSel                              0x574800
#define CListWnd__CloseAndUpdateEditWindow                 0x5755D0
#define CListWnd__Compare                                  0x575910
#define CListWnd__Draw                                     0x5767A0
#define CListWnd__DrawColumnSeparators                     0x576600
#define CListWnd__DrawHeader                               0x574A20
#define CListWnd__DrawItem                                 0x576020
#define CListWnd__DrawLine                                 0x576370
#define CListWnd__DrawSeparator                            0x5766D0
#define CListWnd__EnsureVisible                            0x575020
#define CListWnd__ExtendSel                                0x575F50
#define CListWnd__GetColumnFlags                           0x5742D0
#define CListWnd__GetColumnJustification                   0x574470
#define CListWnd__GetColumnMinWidth                        0x574400
#define CListWnd__GetColumnWidth                           0x574330
#define CListWnd__GetCurSel                                0x574110
#define CListWnd__GetHeaderRect                            0x573F50
#define CListWnd__GetItemAtPoint                           0x5752D0
#define CListWnd__GetItemAtPoint1                          0x575340
#define CListWnd__GetItemData                              0x574150
#define CListWnd__GetItemHeight                            0x574E00
#define CListWnd__GetItemIcon                              0x574210
#define CListWnd__GetItemRect                              0x5750F0
#define CListWnd__GetItemText                              0x574190
#define CListWnd__GetSelList                               0x577CC0
#define CListWnd__GetSeparatorRect                         0x575860
#define CListWnd__IsLineEnabled                            0x5748F0
#define CListWnd__RemoveLine                               0x577C70
#define CListWnd__SetColors                                0x573EC0
#define CListWnd__SetColumnWidth                           0x5743B0
#define CListWnd__SetColumnJustification                   0x5744D0
#define CListWnd__SetCurSel                                0x574720
#define CListWnd__SetItemColor                             0x5775E0
#define CListWnd__SetItemData                              0x5748B0
#define CListWnd__SetItemText                              0x577520
#define CListWnd__ShiftColumnSeparator                     0x575EC0
#define CListWnd__Sort                                     0x578320
#define CListWnd__ToggleSel                                0x574740

// CEditWnd
#define CEditWnd__DrawCaret                                0x589950
#define CEditWnd__GetCharIndexPt                           0x58A760
#define CEditWnd__GetDisplayString                         0x589A80
#define CEditWnd__GetHorzOffset                            0x589CF0
#define CEditWnd__GetLineForPrintableChar                  0x58A210
#define CEditWnd__GetSelStartPt                            0x58A980
#define CEditWnd__GetSTMLSafeText                          0x589ED0
#define CEditWnd__PointFromPrintableChar                   0x58A320
#define CEditWnd__SelectableCharFromPoint                  0x58A4A0
#define CEditWnd__SetEditable                              0x589EA0

// CGaugeWnd
#define CGaugeWnd__CalcFillRect                            0x4F1A76
#define CGaugeWnd__CalcLinesFillRect                       0x4F1AD2
#define CGaugeWnd__Draw                                    0x4F1DD2

// CStmlWnd
#define CStmlWnd__AppendSTML                               0x5733F0
#define CStmlWnd__CalculateHSBRange                        0x56AD30
#define CStmlWnd__CalculateVSBRange                        0x56ACD0
#define CStmlWnd__CanBreakAtCharacter                      0x56AE70
#define CStmlWnd__CanGoBackward                            0x56AEF0
#define CStmlWnd__FastForwardToEndOfTag                    0x56BC10
#define CStmlWnd__GetNextChar                              0x56B320
#define CStmlWnd__GetNextTagPiece                          0x56BA10
#define CStmlWnd__GetSTMLText                              0x4E616B
#define CStmlWnd__GetThisChar                              0x56AB70
#define CStmlWnd__GetVisiableText                          0x56D3E0
#define CStmlWnd__InitializeWindowVariables                0x56F1E0
#define CStmlWnd__MakeStmlColorTag                         0x56A320
#define CStmlWnd__MakeWndNotificationTag                   0x56A3C0
#define CStmlWnd__StripFirstSTMLLines                      0x573170
#define CStmlWnd__UpdateHistoryString                      0x56D820

// CTabWnd
#define CTabWnd__Draw                                      0x588BA0
#define CTabWnd__DrawCurrentPage                           0x588690
#define CTabWnd__DrawTab                                   0x588410
#define CTabWnd__GetCurrentPage                            0x587FC0
#define CTabWnd__GetCurrentTabIndex                        0x587CE0
#define CTabWnd__GetNumTabs                                0x587E10
#define CTabWnd__GetPageClientRect                         0x587CF0
#define CTabWnd__GetPageFromTabIndex                       0x587E40
#define CTabWnd__GetPageInnerRect                          0x587D50
#define CTabWnd__GetTabInnerRect                           0x5880D0
#define CTabWnd__GetTabRect                                0x587FD0
#define CTabWnd__IndexInBounds                             0x587E20
#define CTabWnd__InsertPage                                0x588A90
#define CTabWnd__SetPage                                   0x588170
#define CTabWnd__SetPageRect                               0x588280
#define CTabWnd__UpdatePage                                0x588330

// CTextOverlay
#define CTextOverlay__DisplayText                          0x4013F2
