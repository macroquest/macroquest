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
//.rdata:005E13CC aMay42004       db 'May  4 2004',0
//.rdata:005E13D8 a181942         db '18:19:42',0
#define __ExpectedVersionDate                         "May  4 2004"
#define __ExpectedVersionTime                         "18:19:42"
#define __ActualVersionDate                                0x5E13CC
#define __ActualVersionTime                                0x5E13D8 

#define __ClientOverride                       0
#define __MacroQuestWinClassName                 "__MacroQuestTray"
#define __MacroQuestWinName                           "MacroQuest"

// Memory Protection
#define __MemChecker0                                      0x4C0F4F
#define __MemChecker1                                      0x4C58D0
#define __MemChecker2                                      0x4C76A7
#define __MemChecker3                                      0x4C7744
#define __EncryptPad0                                      0x6189D8
#define __EncryptPad1                                      0x618DD8
#define __EncryptPad2                                      0x6198A0
#define __EncryptPad3                                      0x619CA0

#define DI8__Main                                          0x79CBE4
#define DI8__Keyboard                                      0x79CBE8
#define DI8__Mouse                                         0x79CBEC

#define __LastTell                                         0x6DEA10
#define __Guilds                                           0x73F0D0
#define __Mouse                                            0x79CBF0
#define __Attack                                           0x73D244
#define __InChatMode                                       0x6DC950
#define __gWorld                                           0x73F028
#define __GroupCount                                       0x73D5D8
#define __CommandList                                      0x612860
#define __DoAbilityList                                    0x7164E4
#define __DoAbilityAvailable                               0x6DD730
#define __ServerHost                                       0x73D494
#define __ServerName                                       0x7164A4
#define __HWnd                                             0x6DC910
#define __Clicks                                           0x6DCA10
#define __ScreenX                                          0x6DC918
#define __ScreenY                                          0x6DC91C
#define __ScreenMode                                       0x6289EC
#define __MouseLook                                        0x6DC9E2
#define __EQP_IDArray                                      0x6D99E8
#define __CurrentMapLabel                                  0x7A5A78
#define __BindList                                         0x612330
#define __RangeAttackReady                                 0x6DD794
#define __AltTimerReady                                    0x6DD796
#define __Socials                                          0x7165A4
#define __HotkeyPage                                       0x73CE44
#define __CurrentSocial                                    0x60EB7C
#define __GroupLeader                                      0x73D734
#define __SkillDict                                        0x629E80
#define __DrawHandler                                      0x7B1734
#define __FriendsList                                      0x7132A4
#define __IgnoreList                                       0x714BA4
#define __NetStatusToggle                                  0x6DC9E4
#define __ShowNames										   0x6DD978 
#define __PCNames										   0x6DDA28
////
//Section 1: Vital Offsets
////
#define pinstCSidlManager                                  0x7B0E64
#define pinstCDisplay                                      0x73F0B4
#define pinstCEverQuest                                    0x79CD58
#define pinstPCData                                        0x73F090
#define pinstCharData                                      0x73F090
#define pinstCharSpawn                                     0x73F088
#define pinstSpawnList                                     0x73F050
#define pinstLocalPlayer                                   0x73F074
#define pinstControlledPlayer                              0x73F088
#define pinstWorldData                                     0x73F04C
#define pinstSpellManager                                  0x7997AC
#define pinstTradeTarget                                   0x73F070
#define pinstActiveMerchant                                0x73F0A0
#define pinstActiveBanker                                  0x73F0A4
#define pinstActiveCorpse                                  0x73F0A8
#define pinstActiveGMaster                                 0x73F0AC
#define pinstSelectedItem                                  0x7A5980
#define pinstGroup                                         0x73D720
#define pinstTarget                                        0x73F094
#define pinstSwitchManager                                 0x6DC904
#define pinstEQItemList                                    0x73F054
#define pinstSpellSets                                     0x73CE48
#define instEQZoneInfo                                     0x6DCB7C
#define pinstCXWndManager                                  0x7B0E5C
#define instKeypressHandler                                0x78BE90
#define pinstStringTable                                   0x73F040
#define pinstAltAdvManager                                 0x629A98
#define instCRaid                                          0x747360

////
//Section 2:  UI Related Offsets
////
#define pinstCTextOverlay                                  0x622320
#define pinstCharacterSelect                               0x62947C
#define pinstCFacePick                                     0x629480
// removed 4-14 exe #define pinstCTextMessageWnd                               
#define pinstCNoteWnd                                      0x629484
#define pinstCHelpWnd                                      0x629488
#define pinstCBookWnd                                      0x62948C
#define pinstCPetInfoWnd                                   0x629490
#define pinstCTrainWnd                                     0x629494
#define pinstCSkillsWnd                                    0x629498
#define pinstCSkillsSelectWnd                              0x62949C
#define pinstCCombatSkillSelectWnd                         0x6294A0
#define pinstCFriendsWnd                                   0x6294A4
#define pinstCAAWnd                                        0x6294A8
#define pinstCGroupSearchFiltersWnd                        0x6294AC
#define pinstCLoadskinWnd                                  0x6294B0
#define pinstCAlarmWnd                                     0x6294B4
#define pinstCMusicPlayerWnd                               0x6294B8
#define pinstCRaidWnd                                      0x6294BC
#define pinstCRaidOptionsWnd                               0x6294C0
#define pinstCBreathWnd                                    0x6294C4
#define pinstCMapViewWnd                                   0x6294C8
#define pinstCMapToolbarWnd                                0x6294CC
#define pinstCEditLabelWnd                                 0x6294D0
#define pinstCTargetWnd                                    0x6294D4
#define pinstCHotButtonWnd                                 0x6294D8
#define pinstCColorPickerWnd                               0x6294DC
#define pinstCPlayerWnd                                    0x6294E0
#define pinstCOptionsWnd                                   0x6294E4
#define pinstCBuffWindowNORMAL                             0x6294E8
#define pinstCBuffWindowSHORT                              0x6294EC
#define pinstCharacterCreation                             0x6294F0
#define pinstCCursorAttachment                             0x6294F4
#define pinstCCastingWnd                                   0x6294F8
#define pinstCCastSpellWnd                                 0x6294FC
#define pinstCSpellBookWnd                                 0x629500
#define pinstCInventoryWnd                                 0x629504
#define pinstCBankWnd                                      0x629508
#define pinstCQuantityWnd                                  0x62950C
#define pinstCLootWnd                                      0x629510
#define pinstCActionsWnd                                   0x629514
#define pinstCCombatAbilityWnd                             0x629518
#define pinstCMerchantWnd                                  0x62951C
#define pinstCTradeWnd                                     0x629520
#define pinstCSelectorWnd                                  0x629524
#define pinstCBazaarWnd                                    0x629528
#define pinstCBazaarSearchWnd                              0x62952C
#define pinstCGiveWnd                                      0x629530
#define pinstCTrackingWnd                                  0x629534
#define pinstCInspectWnd                                   0x629538
#define pinstCSocialEditWnd                                0x62953C
#define pinstCFeedbackWnd                                  0x629540
#define pinstCBugReportWnd                                 0x629544
#define pinstCVideoModesWnd                                0x629548
#define pinstCTextEntryWnd                                 0x62954C
#define pinstCFileSelectionWnd                             0x629550
#define pinstCCompassWnd                                   0x629554
#define pinstCPlayerNotesWnd                               0x629558
#define pinstCGemsGameWnd                                  0x62955C
#define pinstCTimeLeftWnd                                  0x629560
#define pinstCPetitionQWnd                                 0x629564
#define pinstCSoulmarkWnd                                  0x629568
#define pinstCStoryWnd                                     0x62956C
#define pinstCJournalTextWnd                               0x629570
#define pinstCJournalCatWnd                                0x629574
#define pinstCBodyTintWnd                                  0x629578
#define pinstCInvSlotMgr                                   0x62957C
#define pinstCContainerMgr                                 0x629580
#define pinstCAdventureLeaderboardWnd                      0x7A5438
#define pinstCAdventureMerchantWnd                         0x7A5450
#define pinstCAdventureRequestWnd                          0x7A5468
#define pinstCAdventureStatsWnd                            0x7A5480
#define pinstCChatManager                                  0x7A5710
#define pinstCDynamicZoneWnd                               0x7A57C8
#define pinstCFindLocationWnd                              0x7A5858
#define pinstCGroupSearchWnd                               0x7A58D4
#define pinstCGroupWnd                                     0x7A58EC
#define pinstCGuildMgmtWnd                                 0x7A5904
#define pinstCItemDisplayManager                           0x7A59AC
#define pinstCLeadershipWnd                                0x7A5A14
#define pinstCPopupWndManager                              0x7A5B64
#define pinstCSystemInfoDialogBox                          0x7A6444
#define pinstCTargetOfTargetWnd                            0x7A645C
#define pinstCTipWndOFDAY                                  0x7A64E0
#define pinstCTipWndCONTEXT                                0x7A64E4
#define pinstCTradeskillWnd                                0x7A6510
#define pinstCTributeBenefitWnd                            0x7A6550
#define pinstCTributeMasterWnd                             0x7A6568
#define pinstCContextMenuManager                           0x7B0E80
// unknown window added 4-14 exe 0x79A234


////
// Section 3: Miscellaneous Offsets
////
#define DrawNetStatus                                      0x4B58E0
#define CrashDetected                                      0x4C73A5
#define __ProcessGameEvents                                0x4ABFE1
#define __ConvertItemTags                                  0x45A95B
#define __SendMessage                                      0x4BB6C9
#define __NewUIINI                                         0x526646
#define __ExecuteCmd                                       0x44D7B2
#define __GetGaugeValueFromEQ                              0x524EAB
#define __get_melee_range                                  0x4522C3

// EQ_LoadingS
#define EQ_LoadingS__WriteTextHD                           0x432435


////
// Section 4: Function Offsets
////
// CEverQuest
#define CEverQuest__dsp_chat                               0x49BEF6
#define CEverQuest__ClickedPlayer                          0x4990A2
#define CEverQuest__EnterZone                              0x49CC21
#define CEverQuest__GetBodyTypeDesc                        0x492EA5
#define CEverQuest__GetClassDesc                           0x492927
#define CEverQuest__GetClassThreeLetterCode                0x492D42
#define CEverQuest__GetDeityDesc                           0x494938
#define CEverQuest__GetRaceDesc                            0x4931AA
#define CEverQuest__GetTitleDesc                           0x494A4F
#define CEverQuest__InterpretCmd                           0x4A8A0E
#define CEverQuest__LeftClickedOnPlayer                    0x4AABE5
#define CEverQuest__RightClickedOnPlayer                   0x4A37BA
#define CEverQuest__SetGameState                           0x499209
#define CEverQuest__DropHeldItemOnGround                   0x49B9B7

// StringTable
#define StringTable__getString                             0x4BE878

// AltAdvManager
#define AltAdvManager__IsAbilityReady                      0x41D1A1

// CXWndManager
#define CXWndManager__RemoveWnd                            0x574960
#define CXWndManager__GetKeyboardFlags                     0x574580
#define CXWndManager__HandleKeyboardMsg                    0x574A50
#define CXWndManager__DrawWindows                          0x5757C0
#define CXWndManager__DrawCursor                           0x575B70

// KeyPressHandler
#define KeypressHandler__HandleKeyDown                     0x4B0B50
#define KeypressHandler__HandleKeyUp                       0x4B0DF4
#define KeypressHandler__AttachKeyToEqCommand              0x4B21F1
#define KeypressHandler__AttachAltKeyToEqCommand           0x4B222E
#define KeypressHandler__SaveKeymapping                    0x4B20D9
#define KeypressHandler__ClearCommandStateArray            0x4B0DE3

// EQ_Character
#define EQ_Character__Max_Endurance                        0x41D346
#define EQ_Character__Max_Mana                             0x420CC8
#define EQ_Character__Max_HP                               0x420B13
#define EQ_Character__Cur_HP                               0x422694
#define EQ_Character__GetFocusCastingTimeModifier          0x42876A
#define EQ_Character__GetAACastingTimeModifier             0x428B03
#define EQ_Character__CastSpell                            0x42C64A
#define EQ_Character__GetAbility                           0x42057B

// EQPlayer
#define EQPlayer__EQPlayer                                 0x487CF3
#define EQPlayer__dEQPlayer                                0x4875B0
#define EQPlayer__DoAttack                                 0x483C35
#define EQPlayer__ChangeBoneStringSprite                   0x465D92
#define EQPlayer__SetNameSpriteState					   0x48223B
#define EQPlayer__SetNameSpriteTint						   0x465DFE

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr                                       0x4010C0
#define CXStr__CXStr1                                      0x511714
#define CXStr__CXStr3                                      0x5A3940
#define CXStr__dCXStr                                      0x4D229C
#define CXStr__operator_plus_equal1                        0x5A49D0
#define CXStr__operator_equal1                             0x5A3B00

// CChatWindow
#define CChatWindow__CChatWindow                           0x4E3E85

// CChatManager
#define CChatManager__GetRGBAFromIndex                     0x4E0A49
#define CChatManager__InitContextMenu                      0x4E13AD

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot                           0x4FE2BC
#define CInvSlotMgr__MoveItem                              0x4FDC6B

// CItemDisplayWnd
#define CItemDisplayWnd__SetItem                           0x50117C
#define CItemDisplayWnd__SetSpell                          0x500666

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton                         0x4FACDB

// CLabel
#define CLabel__Draw                                       0x507282

// CGauge
#define CGaugeWnd__Draw                                    0x4EFA45

// CDisplay
#define CDisplay__ReloadUI                                 0x4172F7
#define CDisplay__CleanGameUI                              0x4101E7
#define CDisplay__GetClickedActor                          0x40D4E6
#define CDisplay__WriteTextHD2                             0x410C91
#define CDisplay__GetWorldFilePath                         0x40C0E8
#define CDisplay__GetUserDefinedColor                      0x40C8E1

#define CTextureFont__DrawWrappedText                      0x564DB0

// EQ_Item
#define EQ_Item__GetItemLinkHash                           0x431F2C
#define EQ_Item__CanDrop                                   0x432024

// CBankWnd
#define CBankWnd__GetNumBankSlots                          0x4D238D

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg                  0x4D4D53

// CMerchantWnd
#define CMerchantWnd__SelectBuySellSlot                    0x51007B
#define CMerchantWnd__RequestBuyItem                       0x50F26D
#define CMerchantWnd__RequestSellItem                      0x50F5EB
#define CMerchantWnd__DisplayBuyOrSellPrice                0x50F0A2

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet                         0x5238AF

// MapViewMap
#define MapViewMap__SaveEx                                 0x50A89E
#define MapViewMap__Clear                                  0x50A72D


// CMapViewWnd
#define CMapViewWnd__CMapViewWnd                           0x50E163

// EQItemList
#define EQItemList__EQItemList                             0x450062
#define EQItemList__dEQItemList                            0x462574

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney                      0x434F6F

// CContainerWnd
#define CContainerWnd__HandleCombine                       0x4E8069
#define CContainerWnd__vftable                             0x5E5758

// CSidlScreenWnd
#define CSidlScreenWnd__CSidlScreenWnd1                    0x558790
#define CSidlScreenWnd__dCSidlScreenWnd                    0x557E30
#define CSidlScreenWnd__CreateChildrenFromSidl             0x5571A0
#define CSidlScreenWnd__GetChildItem                       0x556AB0
#define CSidlScreenWnd__WndNotification                    0x556D20
#define CSidlScreenWnd__CalculateHSBRange                  0x556340
#define CSidlScreenWnd__CalculateVSBRange                  0x556280
#define CSidlScreenWnd__ConvertToRes                       0x556A30
#define CSidlScreenWnd__CSidlScreenWnd2                    0x558880
#define CSidlScreenWnd__DrawSidlPiece                      0x556DC0
#define CSidlScreenWnd__EnableIniStorage                   0x5569E0
#define CSidlScreenWnd__GetSidlPiece                       0x557060
#define CSidlScreenWnd__Init1                              0x5584E0
#define CSidlScreenWnd__LoadIniInfo                        0x557250
#define CSidlScreenWnd__LoadIniListWnd                     0x557B90
#define CSidlScreenWnd__LoadSidlScreen                     0x556C00
#define CSidlScreenWnd__SetScreen                          0x557F50
#define CSidlScreenWnd__StoreIniInfo                       0x556570
#define CSidlScreenWnd__StoreIniListWnd                    0x557C40

// CSidlManager
#define CSidlManager__FindScreenPieceTemplate1             0x57CFA0

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead                       0x5646D0

// CXRect
#define CXRect__CenterPoint                                0x4D2394

// CXWnd
#define CXWnd__Bottom                                      0x55C7B0
#define CXWnd__BringToTop                                  0x558F10
#define CXWnd__Center                                      0x55C570
#define CXWnd__ClrFocus                                    0x558C60
#define CXWnd__DoAllDrawing                                0x55D180
#define CXWnd__DrawChildren                                0x55D2B0
#define CXWnd__DrawColoredRect                             0x559140
#define CXWnd__DrawTooltipAtPoint                          0x55C3A0
#define CXWnd__GetBorderFrame                              0x559580
#define CXWnd__GetChildWndAt                               0x55BF30
#define CXWnd__GetClientClipRect                           0x5594D0
#define CXWnd__GetFirstChildWnd                            0x558FA0
#define CXWnd__GetNextChildWnd                             0x55BF10
#define CXWnd__GetNextSib                                  0x558FC0
#define CXWnd__GetScreenClipRect                           0x55C800
#define CXWnd__GetScreenRect                               0x559750
#define CXWnd__GetTooltipRect                              0x55C2F0
#define CXWnd__GetWindowTextA                              0x4CCE12
#define CXWnd__GetXMLTooltip                               0x558AA0
#define CXWnd__IsActive                                    0x559540
#define CXWnd__IsDescendantOf                              0x559550
#define CXWnd__IsReallyVisible                             0x55BEF0
#define CXWnd__IsType                                      0x55D120
#define CXWnd__Left                                        0x55C630
#define CXWnd__Move                                        0x55BAA0
#define CXWnd__Move1                                       0x55BB30
#define CXWnd__ProcessTransition                           0x558ED0
#define CXWnd__Refade                                      0x558D00
#define CXWnd__Resize                                      0x55C940
#define CXWnd__Right                                       0x55C6E0
#define CXWnd__SetFirstChildPointer                        0x5599A0
#define CXWnd__SetFocus                                    0x55AC80
#define CXWnd__SetKeyTooltip                               0x5599E0
#define CXWnd__SetMouseOver                                0x5599C0
#define CXWnd__SetNextSibPointer                           0x5599B0
#define CXWnd__StartFade                                   0x558F30

// CSliderWnd
#define CSliderWnd__GetValue                               0x588830
#define CSliderWnd__SetValue                               0x588A20
#define CSliderWnd__UpdateThumb                            0x5887F0

// CEditBaseWnd
#define CEditBaseWnd__SetMaxChars                          0x4D1ECE
#define CEditBaseWnd__SetSel                               0x57EF20

// CComboWnd
#define CComboWnd__DeleteAll                               0x583F10
#define CComboWnd__Draw                                    0x584110
#define CComboWnd__GetButtonRect                           0x583F40
#define CComboWnd__GetCurChoice                            0x583ED0
#define CComboWnd__GetListRect                             0x584500
#define CComboWnd__GetTextRect                             0x583FA0
#define CComboWnd__InsertChoice                            0x584560
#define CComboWnd__SetColors                               0x583EA0
#define CComboWnd__SetChoice                               0x584640

// CListWnd
#define CListWnd__AddColumn                                0x573280
#define CListWnd__AddColumn1                               0x572DE0
#define CListWnd__AddLine                                  0x5729A0
#define CListWnd__AddString                                0x572B20
#define CListWnd__CalculateFirstVisibleLine                0x56FFD0
#define CListWnd__CalculateLineHeights                     0x56FF70
#define CListWnd__CalculateVSBRange                        0x571B40
#define CListWnd__ClearAllSel                              0x56F800
#define CListWnd__CloseAndUpdateEditWindow                 0x5705D0
#define CListWnd__Compare                                  0x570910
#define CListWnd__Draw                                     0x5717A0
#define CListWnd__DrawColumnSeparators                     0x571600
#define CListWnd__DrawHeader                               0x56FA20
#define CListWnd__DrawItem                                 0x571020
#define CListWnd__DrawLine                                 0x571370
#define CListWnd__DrawSeparator                            0x5716D0
#define CListWnd__EnsureVisible                            0x570020
#define CListWnd__ExtendSel                                0x570F50
#define CListWnd__GetColumnFlags                           0x56F2D0
#define CListWnd__GetColumnJustification                   0x56F470
#define CListWnd__GetColumnMinWidth                        0x56F400
#define CListWnd__GetColumnWidth                           0x56F330
#define CListWnd__GetCurSel                                0x56F110
#define CListWnd__GetHeaderRect                            0x56EF50
#define CListWnd__GetItemAtPoint                           0x5702D0
#define CListWnd__GetItemAtPoint1                          0x570340
#define CListWnd__GetItemData                              0x56F150
#define CListWnd__GetItemHeight                            0x56FE00
#define CListWnd__GetItemIcon                              0x56F210
#define CListWnd__GetItemRect                              0x5700F0
#define CListWnd__GetItemText                              0x56F190
#define CListWnd__GetSelList                               0x572CC0
#define CListWnd__GetSeparatorRect                         0x570860
#define CListWnd__IsLineEnabled                            0x56F8F0
#define CListWnd__RemoveLine                               0x572C70
#define CListWnd__SetColors                                0x56EEC0
#define CListWnd__SetColumnWidth                           0x56F3B0
#define CListWnd__SetColumnJustification                   0x56F4D0
#define CListWnd__SetCurSel                                0x56F720
#define CListWnd__SetItemColor                             0x5725E0
#define CListWnd__SetItemData                              0x56F8B0
#define CListWnd__SetItemText                              0x572520
#define CListWnd__ShiftColumnSeparator                     0x570EC0
#define CListWnd__Sort                                     0x573320
#define CListWnd__ToggleSel                                0x56F740

// CEditWnd
#define CEditWnd__DrawCaret                                0x5849A0
#define CEditWnd__DrawMultiline                            0x585EE0
#define CEditWnd__GetCaretPt                               0x586290
#define CEditWnd__GetCharIndexPt                           0x5857E0
#define CEditWnd__GetDisplayString                         0x584B00
#define CEditWnd__GetHorzOffset                            0x584D70
#define CEditWnd__GetLineForPrintableChar                  0x585290
#define CEditWnd__GetSelEndPt                              0x585A20
#define CEditWnd__GetSelStartPt                            0x585A00
#define CEditWnd__GetSTMLSafeText                          0x584F50
#define CEditWnd__PointFromPrintableChar                   0x5853A0
#define CEditWnd__SelectableCharFromPoint                  0x585520
#define CEditWnd__SetEditable                              0x584F20

// CGaugeWnd
#define CGaugeWnd__CalcFillRect                            0x4EF6E9
#define CGaugeWnd__CalcLinesFillRect                       0x4EF745
#define CGaugeWnd__Draw                                    0x4EFA45

// CStmlWnd
#define CStmlWnd__AppendSTML                               0x56E3F0
#define CStmlWnd__CalculateHSBRange                        0x565E10
#define CStmlWnd__CalculateVSBRange                        0x565DB0
#define CStmlWnd__CanBreakAtCharacter                      0x565F50
#define CStmlWnd__CanGoBackward                            0x565FD0
#define CStmlWnd__FastForwardPastSpaces                    0x566980
#define CStmlWnd__FastForwardToEndOfTag                    0x566CF0
#define CStmlWnd__GetNextChar                              0x566400
#define CStmlWnd__GetNextTagPiece                          0x566AF0
#define CStmlWnd__GetSTMLText                              0x4E3E67
#define CStmlWnd__GetThisChar                              0x565C50
#define CStmlWnd__GetVisiableText                          0x5684C0
#define CStmlWnd__InitializeTempVariables                  0x565C00
#define CStmlWnd__InitializeWindowVariables                0x56A2C0
#define CStmlWnd__MakeStmlColorTag                         0x5653E0
#define CStmlWnd__MakeWndNotificationTag                   0x565480
#define CStmlWnd__StripFirstSTMLLines                      0x56E170
#define CStmlWnd__UpdateHistoryString                      0x568900

// CTabWnd
#define CTabWnd__Draw                                      0x583BF0
#define CTabWnd__DrawCurrentPage                           0x5836E0
#define CTabWnd__DrawTab                                   0x583460
#define CTabWnd__GetCurrentPage                            0x583010
#define CTabWnd__GetCurrentTabIndex                        0x582D70
#define CTabWnd__GetNumTabs                                0x582E60
#define CTabWnd__GetPageClientRect                         0x582D80
#define CTabWnd__GetPageFromTabIndex                       0x582E90
#define CTabWnd__GetPageInnerRect                          0x582DE0
#define CTabWnd__GetTabInnerRect                           0x583120
#define CTabWnd__GetTabRect                                0x583020
#define CTabWnd__IndexInBounds                             0x582E70
#define CTabWnd__InsertPage                                0x583AE0
#define CTabWnd__SetPage                                   0x5831C0
#define CTabWnd__SetPageRect                               0x5832D0
#define CTabWnd__UpdatePage                                0x583380

// CTextOverlay
#define CTextOverlay__DisplayText                          0x4013F2
