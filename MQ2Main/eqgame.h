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
//.rdata:005E2414 aMay112004      db 'May 11 2004',0      ; DATA XREF: ClearGfxDLLAddresses+25o
//.rdata:005E2420 a153527         db '15:35:27',0         ; DATA XREF: ClearGfxDLLAddresses+1Fo
#define __ExpectedVersionDate                         "May 11 2004"
#define __ExpectedVersionTime                         "15:35:27"
#define __ActualVersionDate                                0x5E2414
#define __ActualVersionTime                                0x5E2420

#define __ClientOverride                       0
#define __MacroQuestWinClassName                 "__MacroQuestTray"
#define __MacroQuestWinName                           "MacroQuest"

// Memory Protection
#define __MemChecker0                                      0x4C131A
#define __MemChecker1                                      0x4C5CBF
#define __MemChecker2                                      0x4C7A96
#define __MemChecker3                                      0x4C7B33
#define __EncryptPad0                                      0x6199D8
#define __EncryptPad1                                      0x619DD8
#define __EncryptPad2                                      0x61A8A0
#define __EncryptPad3                                      0x61ACA0

#define DI8__Main                                          0x79DBFC
#define DI8__Keyboard                                      0x79DC00
#define DI8__Mouse                                         0x79DC04

#define __LastTell                                         0x6DFA20
#define __Guilds                                           0x7400E0
#define __Mouse                                            0x79DC08
#define __Attack                                           0x73E254
#define __InChatMode                                       0x6DD960
#define __gWorld                                           0x740038
#define __GroupCount                                       0x73E5E8
#define __CommandList                                      0x613860
#define __DoAbilityList                                    0x7174F4
#define __DoAbilityAvailable                               0x6DE740
#define __ServerHost                                       0x73E4A4
#define __ServerName                                       0x7174B4
#define __HWnd                                             0x6DD920
#define __Clicks                                           0x6DDA20
#define __ScreenX                                          0x6DD928
#define __ScreenY                                          0x6DD92C
#define __ScreenMode                                       0x6299EC
#define __MouseLook                                        0x6DD9F2
#define __EQP_IDArray                                      0x6DA9E8
#define __CurrentMapLabel                                  0x7A6A90
#define __BindList                                         0x613330
#define __RangeAttackReady                                 0x6DE7A4
#define __AltTimerReady                                    0x6DE7A6
#define __Socials                                          0x7175B4
#define __HotkeyPage                                       0x73DE54
#define __CurrentSocial                                    0x60FB7C
#define __GroupLeader                                      0x73E744
#define __SkillDict                                        0x62AE80
#define __DrawHandler                                      0x7B2754
#define __FriendsList                                      0x7142B4
#define __IgnoreList                                       0x715BB4
#define __NetStatusToggle                                  0x6DD9F4
#define __ShowNames                                        0x6DE988
#define __PCNames                                          0x6DEA38
////
//Section 1: Vital Offsets
////
#define pinstCSidlManager                                  0x7B1E84
#define pinstCDisplay                                      0x7400C4
#define pinstCEverQuest                                    0x79DD70
#define pinstPCData                                        0x7400A0
#define pinstCharData                                      0x7400A0
#define pinstCharSpawn                                     0x740098
#define pinstSpawnList                                     0x740060
#define pinstLocalPlayer                                   0x740084
#define pinstControlledPlayer                              0x740098
#define pinstWorldData                                     0x74005C
#define pinstSpellManager                                  0x79A7C4
#define pinstTradeTarget                                   0x740080
#define pinstActiveMerchant                                0x7400B0
#define pinstActiveBanker                                  0x7400B4
#define pinstActiveCorpse                                  0x7400B8
#define pinstActiveGMaster                                 0x7400BC
#define pinstSelectedItem                                  0x7A6998
#define pinstGroup                                         0x73E730
#define pinstTarget                                        0x7400A4
#define pinstSwitchManager                                 0x6DD910
#define pinstEQItemList                                    0x740064
#define pinstSpellSets                                     0x73DE58
#define instEQZoneInfo                                     0x6DDB8C
#define pinstCXWndManager                                  0x7B1E7C
#define instKeypressHandler                                0x78CEA0
#define pinstStringTable                                   0x740050
#define pinstAltAdvManager                                 0x62AA98
#define instCRaid                                          0x748370

////
//Section 2:  UI Related Offsets
////
#define pinstCTextOverlay                                  0x623320
#define pinstCharacterSelect                               0x62A47C
#define pinstCFacePick                                     0x62A480
// removed 4-14 exe #define pinstCTextMessageWnd                               
#define pinstCNoteWnd                                      0x62A484
#define pinstCHelpWnd                                      0x62A488
#define pinstCBookWnd                                      0x62A48C
#define pinstCPetInfoWnd                                   0x62A490
#define pinstCTrainWnd                                     0x62A494
#define pinstCSkillsWnd                                    0x62A498
#define pinstCSkillsSelectWnd                              0x62A49C
#define pinstCCombatSkillSelectWnd                         0x62A4A0
#define pinstCFriendsWnd                                   0x62A4A4
#define pinstCAAWnd                                        0x62A4A8
#define pinstCGroupSearchFiltersWnd                        0x62A4AC
#define pinstCLoadskinWnd                                  0x62A4B0
#define pinstCAlarmWnd                                     0x62A4B4
#define pinstCMusicPlayerWnd                               0x62A4B8
#define pinstCRaidWnd                                      0x62A4BC
#define pinstCRaidOptionsWnd                               0x62A4C0
#define pinstCBreathWnd                                    0x62A4C4
#define pinstCMapViewWnd                                   0x62A4C8
#define pinstCMapToolbarWnd                                0x62A4CC
#define pinstCEditLabelWnd                                 0x62A4D0
#define pinstCTargetWnd                                    0x62A4D4
#define pinstCHotButtonWnd                                 0x62A4D8
#define pinstCColorPickerWnd                               0x62A4DC
#define pinstCPlayerWnd                                    0x62A4E0
#define pinstCOptionsWnd                                   0x62A4E4
#define pinstCBuffWindowNORMAL                             0x62A4E8
#define pinstCBuffWindowSHORT                              0x62A4EC
#define pinstCharacterCreation                             0x62A4F0
#define pinstCCursorAttachment                             0x62A4F4
#define pinstCCastingWnd                                   0x62A4F8
#define pinstCCastSpellWnd                                 0x62A4FC
#define pinstCSpellBookWnd                                 0x62A500
#define pinstCInventoryWnd                                 0x62A504
#define pinstCBankWnd                                      0x62A508
#define pinstCQuantityWnd                                  0x62A50C
#define pinstCLootWnd                                      0x62A510
#define pinstCActionsWnd                                   0x62A514
#define pinstCCombatAbilityWnd                             0x62A518
#define pinstCMerchantWnd                                  0x62A51C
#define pinstCTradeWnd                                     0x62A520
#define pinstCSelectorWnd                                  0x62A524
#define pinstCBazaarWnd                                    0x62A528
#define pinstCBazaarSearchWnd                              0x62A52C
#define pinstCGiveWnd                                      0x62A530
#define pinstCTrackingWnd                                  0x62A534
#define pinstCInspectWnd                                   0x62A538
#define pinstCSocialEditWnd                                0x62A53C
#define pinstCFeedbackWnd                                  0x62A540
#define pinstCBugReportWnd                                 0x62A544
#define pinstCVideoModesWnd                                0x62A548
#define pinstCTextEntryWnd                                 0x62A54C
#define pinstCFileSelectionWnd                             0x62A550
#define pinstCCompassWnd                                   0x62A554
#define pinstCPlayerNotesWnd                               0x62A558
#define pinstCGemsGameWnd                                  0x62A55C
#define pinstCTimeLeftWnd                                  0x62A560
#define pinstCPetitionQWnd                                 0x62A564
#define pinstCSoulmarkWnd                                  0x62A568
#define pinstCStoryWnd                                     0x62A56C
#define pinstCJournalTextWnd                               0x62A570
#define pinstCJournalCatWnd                                0x62A574
#define pinstCBodyTintWnd                                  0x62A578
#define pinstCInvSlotMgr                                   0x62A57C
#define pinstCContainerMgr                                 0x62A580
#define pinstCAdventureLeaderboardWnd                      0x7A6450
#define pinstCAdventureMerchantWnd                         0x7A6468
#define pinstCAdventureRequestWnd                          0x7A6480
#define pinstCAdventureStatsWnd                            0x7A6498
#define pinstCChatManager                                  0x7A6728
#define pinstCDynamicZoneWnd                               0x7A67E0
#define pinstCFindLocationWnd                              0x7A6870
#define pinstCGroupSearchWnd                               0x7A68EC
#define pinstCGroupWnd                                     0x7A6904
#define pinstCGuildMgmtWnd                                 0x7A691C
#define pinstCItemDisplayManager                           0x7A69C4
#define pinstCLeadershipWnd                                0x7A6A2C
#define pinstCPopupWndManager                              0x7A6B7C
#define pinstCSystemInfoDialogBox                          0x7A745C
#define pinstCTargetOfTargetWnd                            0x7A7474
#define pinstCTipWndOFDAY                                  0x7A74F8
#define pinstCTipWndCONTEXT                                0x7A74FC
#define pinstCTradeskillWnd                                0x7A7528
#define pinstCTributeBenefitWnd                            0x7A7568
#define pinstCTributeMasterWnd                             0x7A7580
#define pinstCContextMenuManager                           0x7B1EA0
// unknown window added 4-14 exe 0x79A234


////
// Section 3: Miscellaneous Offsets
////
#define DrawNetStatus                                      0x4B5C8B
#define CrashDetected                                      0x4C7794
#define __ProcessGameEvents                                0x4AC359
#define __ConvertItemTags                                  0x45A932
#define __SendMessage                                      0x4BBAD6
#define __NewUIINI                                         0x5269E1
#define __ExecuteCmd                                       0x44D765
#define __GetGaugeValueFromEQ                              0x525246
#define __get_melee_range                                  0x452299

// EQ_LoadingS
#define EQ_LoadingS__WriteTextHD                           0x4323F4


////
// Section 4: Function Offsets
////
// CEverQuest
#define CEverQuest__dsp_chat                               0x49C26E
#define CEverQuest__ClickedPlayer                          0x49941A
#define CEverQuest__EnterZone                              0x49CF99
#define CEverQuest__GetBodyTypeDesc                        0x49321D
#define CEverQuest__GetClassDesc                           0x492C9F
#define CEverQuest__GetClassThreeLetterCode                0x4930BA
#define CEverQuest__GetDeityDesc                           0x494CB0
#define CEverQuest__GetRaceDesc                            0x493522
#define CEverQuest__GetTitleDesc                           0x494DC7
#define CEverQuest__InterpretCmd                           0x4A8D86
#define CEverQuest__LeftClickedOnPlayer                    0x4AAF5D
#define CEverQuest__RightClickedOnPlayer                   0x4A3B32
#define CEverQuest__SetGameState                           0x499581
#define CEverQuest__DropHeldItemOnGround                   0x49BD2F

// StringTable
#define StringTable__getString                             0x4BEC6C

// AltAdvManager
#define AltAdvManager__IsAbilityReady                      0x41D158

// CXWndManager
#define CXWndManager__RemoveWnd                            0x574D20
#define CXWndManager__GetKeyboardFlags                     0x574940
#define CXWndManager__HandleKeyboardMsg                    0x574E10
#define CXWndManager__DrawWindows                          0x575C00
#define CXWndManager__DrawCursor                           0x575FB0

// KeyPressHandler
#define KeypressHandler__HandleKeyDown                     0x4B0EE6
#define KeypressHandler__HandleKeyUp                       0x4B118A
#define KeypressHandler__AttachKeyToEqCommand              0x4B2587
#define KeypressHandler__AttachAltKeyToEqCommand           0x4B25C4
#define KeypressHandler__SaveKeymapping                    0x4B246F
#define KeypressHandler__ClearCommandStateArray            0x4B1179

// EQ_Character
#define EQ_Character__Max_Endurance                        0x41D2FD
#define EQ_Character__Max_Mana                             0x420C84
#define EQ_Character__Max_HP                               0x420ACF
#define EQ_Character__Cur_HP                               0x422650
#define EQ_Character__GetFocusCastingTimeModifier          0x428726
#define EQ_Character__GetAACastingTimeModifier             0x428ABF
#define EQ_Character__CastSpell                            0x42C606
#define EQ_Character__GetAbility                           0x420537

// EQPlayer
#define EQPlayer__EQPlayer                                 0x487D5A
#define EQPlayer__dEQPlayer                                0x487617
#define EQPlayer__DoAttack                                 0x483C2F
#define EQPlayer__ChangeBoneStringSprite                   0x465D69
#define EQPlayer__SetNameSpriteState                       0x482235
#define EQPlayer__SetNameSpriteTint                        0x465DD5

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr                                       0x4010C0
#define CXStr__CXStr1                                      0x401E96
#define CXStr__CXStr3                                      0x5A3C50
#define CXStr__dCXStr                                      0x4D2674
#define CXStr__operator_plus_equal1                        0x5A4CE0
#define CXStr__operator_equal1                             0x5A3E10

// CChatWindow
#define CChatWindow__CChatWindow                           0x4E4120

// CChatManager
#define CChatManager__GetRGBAFromIndex                     0x4E0CE4
#define CChatManager__InitContextMenu                      0x4E1648

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot                           0x4FE045
#define CInvSlotMgr__MoveItem                              0x4FE47D

// CItemDisplayWnd
#define CItemDisplayWnd__SetItem                           0x501550
#define CItemDisplayWnd__SetSpell                          0x500993

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton                         0x4FB017

// CLabel
#define CLabel__Draw                                       0x5076E0

// CGauge
#define CGaugeWnd__Draw                                    0x4EFDAA

// CDisplay
#define CDisplay__ReloadUI                                 0x4172AE
#define CDisplay__CleanGameUI                              0x41024F
#define CDisplay__GetClickedActor                          0x40D54E
#define CDisplay__WriteTextHD2                             0x410CF9
#define CDisplay__GetWorldFilePath                         0x40C150
#define CDisplay__GetUserDefinedColor                      0x40C949

#define CTextureFont__DrawWrappedText                      0x565180

// EQ_Item
#define EQ_Item__GetItemLinkHash                           0x431EEB
#define EQ_Item__CanDrop                                   0x431FE3

// CBankWnd
#define CBankWnd__GetNumBankSlots                          0x4D2765

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg                  0x4D5101

// CMerchantWnd
#define CMerchantWnd__SelectBuySellSlot                    0x5104D9
#define CMerchantWnd__RequestBuyItem                       0x50F6CB
#define CMerchantWnd__RequestSellItem                      0x50FA49
#define CMerchantWnd__DisplayBuyOrSellPrice                0x50F500

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet                         0x523C4A

// MapViewMap
#define MapViewMap__SaveEx                                 0x50ACFC
#define MapViewMap__Clear                                  0x50AB8B


// CMapViewWnd
#define CMapViewWnd__CMapViewWnd                           0x50E5C1

// EQItemList
#define EQItemList__EQItemList                             0x450015
#define EQItemList__dEQItemList                            0x46254B

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney                      0x434F2E

// CContainerWnd
#define CContainerWnd__HandleCombine                       0x4E8393
#define CContainerWnd__vftable                             0x5E67B0

// CSidlScreenWnd
#define CSidlScreenWnd__CSidlScreenWnd1                    0x558AD0
#define CSidlScreenWnd__dCSidlScreenWnd                    0x558170
#define CSidlScreenWnd__CreateChildrenFromSidl             0x5574E0
#define CSidlScreenWnd__GetChildItem                       0x556DF0
#define CSidlScreenWnd__WndNotification                    0x557060
#define CSidlScreenWnd__CalculateHSBRange                  0x556680
#define CSidlScreenWnd__CalculateVSBRange                  0x5565C0
#define CSidlScreenWnd__ConvertToRes                       0x556D70
#define CSidlScreenWnd__CSidlScreenWnd2                    0x558BC0
#define CSidlScreenWnd__DrawSidlPiece                      0x557100
#define CSidlScreenWnd__EnableIniStorage                   0x556D20
#define CSidlScreenWnd__GetSidlPiece                       0x5573A0
#define CSidlScreenWnd__Init1                              0x558820
#define CSidlScreenWnd__LoadIniInfo                        0x557590
#define CSidlScreenWnd__LoadIniListWnd                     0x557ED0
#define CSidlScreenWnd__LoadSidlScreen                     0x556F40
#define CSidlScreenWnd__SetScreen                          0x558290
#define CSidlScreenWnd__StoreIniInfo                       0x5568B0
//#define CSidlScreenWnd__StoreIniListWnd                    0x0

// CSidlManager
#define CSidlManager__FindScreenPieceTemplate1             0x57D400

// CXMLDataManager
#define CXMLDataManager__GetXMLData						   0x58A070 

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead                       0x564A50

// CXRect
#define CXRect__CenterPoint                                0x4D276C

// CXWnd
//#define CXWnd__Bottom                                      0x0
#define CXWnd__BringToTop                                  0x559270
#define CXWnd__Center                                      0x55C8F0
#define CXWnd__ClrFocus                                    0x558FC0
#define CXWnd__DoAllDrawing                                0x55D500
#define CXWnd__DrawChildren                                0x55D630
#define CXWnd__DrawColoredRect                             0x5594B0
#define CXWnd__DrawTooltipAtPoint                          0x55C720
#define CXWnd__GetBorderFrame                              0x559900
#define CXWnd__GetChildWndAt                               0x55C2B0
#define CXWnd__GetClientClipRect                           0x559840
#define CXWnd__GetFirstChildWnd                            0x559300
#define CXWnd__GetNextChildWnd                             0x55C290
#define CXWnd__GetNextSib                                  0x559320
#define CXWnd__GetScreenClipRect                           0x55CB80
#define CXWnd__GetScreenRect                               0x559AD0
#define CXWnd__GetTooltipRect                              0x55C670
#define CXWnd__GetWindowTextA                              0x4CD201
#define CXWnd__GetXMLTooltip                               0x558E00
#define CXWnd__IsActive                                    0x5598B0
#define CXWnd__IsDescendantOf                              0x5598C0
#define CXWnd__IsReallyVisible                             0x55C270
#define CXWnd__IsType                                      0x55D4A0
//#define CXWnd__Left                                        0x0
#define CXWnd__Move                                        0x55BE20
#define CXWnd__Move1                                       0x55BEB0
#define CXWnd__ProcessTransition                           0x559230
#define CXWnd__Refade                                      0x559060
#define CXWnd__Resize                                      0x55CCC0
#define CXWnd__Right                                       0x55CA60
#define CXWnd__SetFirstChildPointer                        0x559D20
#define CXWnd__SetFocus                                    0x55B000
#define CXWnd__SetKeyTooltip                               0x559D60
#define CXWnd__SetMouseOver                                0x559D40
#define CXWnd__SetNextSibPointer                           0x559D30
#define CXWnd__StartFade                                   0x559290

// CSliderWnd
#define CSliderWnd__GetValue                               0x588C20
#define CSliderWnd__SetValue                               0x588DF0
#define CSliderWnd__UpdateThumb                            0x588BE0

// CEditBaseWnd
#define CEditBaseWnd__SetMaxChars                          0x4D22BD
#define CEditBaseWnd__SetSel                               0x57F3B0

// CComboWnd
#define CComboWnd__DeleteAll                               0x584310
#define CComboWnd__Draw                                    0x584510
#define CComboWnd__GetButtonRect                           0x584340
#define CComboWnd__GetCurChoice                            0x5842D0
#define CComboWnd__GetListRect                             0x584900
#define CComboWnd__GetTextRect                             0x5843A0
#define CComboWnd__InsertChoice                            0x584960
#define CComboWnd__SetColors                               0x5842A0
#define CComboWnd__SetChoice                               0x584A40

// CListWnd
#define CListWnd__AddColumn                                0x573640
#define CListWnd__AddColumn1                               0x5731A0
#define CListWnd__AddLine                                  0x572D60
#define CListWnd__AddString                                0x572EE0
#define CListWnd__CalculateFirstVisibleLine                0x570390
//#define CListWnd__CalculateLineHeights                     0x0
#define CListWnd__CalculateVSBRange                        0x571F00
#define CListWnd__ClearAllSel                              0x56FBC0
#define CListWnd__CloseAndUpdateEditWindow                 0x570990
#define CListWnd__Compare                                  0x570CD0
#define CListWnd__Draw                                     0x571B60
#define CListWnd__DrawColumnSeparators                     0x5719C0
#define CListWnd__DrawHeader                               0x56FDE0
#define CListWnd__DrawItem                                 0x5713E0
#define CListWnd__DrawLine                                 0x571730
#define CListWnd__DrawSeparator                            0x571A90
#define CListWnd__EnsureVisible                            0x5703E0
#define CListWnd__ExtendSel                                0x571310
#define CListWnd__GetColumnFlags                           0x56F690
#define CListWnd__GetColumnJustification                   0x56F830
#define CListWnd__GetColumnMinWidth                        0x56F7C0
#define CListWnd__GetColumnWidth                           0x56F6F0
#define CListWnd__GetCurSel                                0x56F4D0
#define CListWnd__GetHeaderRect                            0x56F310
#define CListWnd__GetItemAtPoint                           0x570690
#define CListWnd__GetItemAtPoint1                          0x570700
#define CListWnd__GetItemData                              0x56F510
#define CListWnd__GetItemHeight                            0x5701C0
#define CListWnd__GetItemIcon                              0x56F5D0
#define CListWnd__GetItemRect                              0x5704B0
#define CListWnd__GetItemText                              0x56F550
#define CListWnd__GetSelList                               0x573080
#define CListWnd__GetSeparatorRect                         0x570C20
#define CListWnd__IsLineEnabled                            0x56FCB0
#define CListWnd__RemoveLine                               0x573030
#define CListWnd__SetColors                                0x56F280
#define CListWnd__SetColumnWidth                           0x56F770
#define CListWnd__SetColumnJustification                   0x56F890
#define CListWnd__SetCurSel                                0x56FAE0
#define CListWnd__SetItemColor                             0x5729A0
#define CListWnd__SetItemData                              0x56FC70
#define CListWnd__SetItemText                              0x5728E0
#define CListWnd__ShiftColumnSeparator                     0x571280
#define CListWnd__Sort                                     0x5736E0
#define CListWnd__ToggleSel                                0x56FB00

// CEditWnd
#define CEditWnd__DrawCaret                                0x584DA0
//#define CEditWnd__DrawMultiline                            0x0
//#define CEditWnd__GetCaretPt                               0x0
#define CEditWnd__GetCharIndexPt                           0x585BE0
#define CEditWnd__GetDisplayString                         0x584F00
#define CEditWnd__GetHorzOffset                            0x585170
#define CEditWnd__GetLineForPrintableChar                  0x585690
//#define CEditWnd__GetSelEndPt                              0x0
#define CEditWnd__GetSelStartPt                            0x585E00
#define CEditWnd__GetSTMLSafeText                          0x585350
#define CEditWnd__PointFromPrintableChar                   0x5857A0
#define CEditWnd__SelectableCharFromPoint                  0x585920
#define CEditWnd__SetEditable                              0x585320

// CGaugeWnd
#define CGaugeWnd__CalcFillRect                            0x4EFA4E
#define CGaugeWnd__CalcLinesFillRect                       0x4EFAAA
#define CGaugeWnd__Draw                                    0x4EFDAA

// CStmlWnd
#define CStmlWnd__AppendSTML                               0x56E790
#define CStmlWnd__CalculateHSBRange                        0x5661A0
#define CStmlWnd__CalculateVSBRange                        0x566140
#define CStmlWnd__CanBreakAtCharacter                      0x5662E0
#define CStmlWnd__CanGoBackward                            0x566360
//#define CStmlWnd__FastForwardPastSpaces                    0x0
#define CStmlWnd__FastForwardToEndOfTag                    0x567090
#define CStmlWnd__GetNextChar                              0x5667A0
#define CStmlWnd__GetNextTagPiece                          0x566E90
#define CStmlWnd__GetSTMLText                              0x4E4102
#define CStmlWnd__GetThisChar                              0x566000
#define CStmlWnd__GetVisiableText                          0x568860
//#define CStmlWnd__InitializeTempVariables                  0x0
#define CStmlWnd__InitializeWindowVariables                0x56A660
#define CStmlWnd__MakeStmlColorTag                         0x5657B0
#define CStmlWnd__MakeWndNotificationTag                   0x565850
#define CStmlWnd__StripFirstSTMLLines                      0x56E510
#define CStmlWnd__UpdateHistoryString                      0x568CA0

// CTabWnd
#define CTabWnd__Draw                                      0x583FF0
#define CTabWnd__DrawCurrentPage                           0x583AE0
#define CTabWnd__DrawTab                                   0x583860
#define CTabWnd__GetCurrentPage                            0x583410
#define CTabWnd__GetCurrentTabIndex                        0x5831F0
#define CTabWnd__GetNumTabs                                0x5832E0
#define CTabWnd__GetPageClientRect                         0x583200
#define CTabWnd__GetPageFromTabIndex                       0x583310
#define CTabWnd__GetPageInnerRect                          0x583260
#define CTabWnd__GetTabInnerRect                           0x583520
#define CTabWnd__GetTabRect                                0x583420
#define CTabWnd__IndexInBounds                             0x5832F0
#define CTabWnd__InsertPage                                0x583EE0
#define CTabWnd__SetPage                                   0x5835C0
#define CTabWnd__SetPageRect                               0x5836D0
#define CTabWnd__UpdatePage                                0x583780

// CTextOverlay
#define CTextOverlay__DisplayText                          0x4013F2
