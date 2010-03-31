/* 
***************************************************************************** 
    MQ2Main.dll: MacroQuest2's extension DLL for EverQuest 
    Copyright (C) 2002-2003 Plazmic, 2003-2005 Lax 

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

#define __ClientName									   "eqgame" 
#define __ExpectedVersionDate                              "Jan 26 2005"
#define __ExpectedVersionTime                              "10:36:55"
#define __ActualVersionDate                                0x5FB92C
#define __ActualVersionTime                                0x5FB938

#define __ClientOverride								   0 
#define __MacroQuestWinClassName					       "__MacroQuestTray" 
#define __MacroQuestWinName								   "MacroQuest" 

// Memory Protection 
#define __MemChecker0                                      0x4FBCF0
//#define __MemChecker1                                      0x0
#define __MemChecker2                                      0x538547
#define __MemChecker3                                      0x5385D4
#define __MemChecker4                                      0x5B2320

#define __EncryptPad0                                      0x71C0E0
//#define __EncryptPad1                                      0x723BA8
#define __EncryptPad2                                      0x71F2B8
#define __EncryptPad3                                      0x71F6B8
#define __EncryptPad4                                      0x724DB0

#define DI8__Main                                          0x883FE4
#define DI8__Keyboard                                      0x883FE8
#define DI8__Mouse                                         0x883FEC

#define __LastTell                                         0x807218
#define __Guilds                                           0x86D868
#define __Mouse                                            0x883FF0
#define __Attack                                           0x865A94
#define __InChatMode                                       0x8050D8
#define __gWorld                                           0x867880
#define __GroupCount                                       0x865E28
#define __CommandList                                      0x624348
#define __DoAbilityList                                    0x83ECEC
#define __DoAbilityAvailable                               0x805F28
#define __ServerHost                                       0x865C64
#define __ServerName                                       0x83ECAC
#define __HWnd                                             0x805098
#define __Clicks                                           0x80519C
#define __ScreenX                                          0x8050A0
#define __ScreenY                                          0x8050A4
#define __ScreenMode                                       0x750EE8
#define __MouseLook                                        0x80516A
#define __EQP_IDArray                                      0x753360
#define __CurrentMapLabel                                  0x876324
#define __BindList                                         0x623DB8
#define __RangeAttackReady                                 0x805F8C
#define __AltTimerReady                                    0x805F8E
#define __Socials                                          0x83EDAC
#define __HotkeyPage                                       0x86564C
#define __CurrentSocial                                    0x627750
#define __GroupLeader                                      0x865F84
#define __SkillDict                                        0x7566E0
#define __DrawHandler                                      0x88DF44
#define __FriendsList                                      0x83BAAC
#define __IgnoreList                                       0x83D3AC
#define __NetStatusToggle                                  0x80516C
#define __ShowNames                                        0x806174
#define __PCNames                                          0x806224
//// 
//Section 1: Vital Offsets 
//// 
#define pinstCSidlManager                                  0x88D2DC
#define pinstCDisplay                                      0x867904
#define pinstCEverQuest                                    0x884158
#define pinstPCData                                        0x8678E0
#define pinstCharData                                      0x8678E0
#define pinstCharSpawn                                     0x8678D8
#define pinstSpawnList                                     0x8678A0
#define pinstLocalPlayer                                   0x8678C4
#define pinstControlledPlayer                              0x8678D8
#define pinstWorldData                                     0x86789C
#define pinstSpellManager                                  0x876680
#define pinstTradeTarget                                   0x8678C0
#define pinstActiveMerchant                                0x8678F0
#define pinstActiveBanker                                  0x8678F4
#define pinstActiveCorpse                                  0x8678F8
#define pinstActiveGMaster                                 0x8678FC
#define pinstSelectedItem                                  0x875F54
#define pinstGroup                                         0x865F70
#define pinstTarget                                        0x8678E4
#define pinstSwitchManager                                 0x756284
#define pinstEQItemList                                    0x8678A4
#define pinstSpellSets                                     0x865650
#define instEQZoneInfo                                     0x805308
#define pinstCXWndManager                                  0x88D2D4
#define instKeypressHandler                                0x875FD4
#define pinstStringTable                                   0x867890
#define pinstAltAdvManager                                 0x756288
#define instCRaid                                          0x867910

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                  0x726880
#define pinstCharacterSelect                               0x75197C
#define pinstCFacePick                                     0x751980
// removed 4-14 exe #define pinstCTextMessageWnd                                
#define pinstCNoteWnd                                      0x751984
#define pinstCHelpWnd                                      0x751988
#define pinstCBookWnd                                      0x75198C
#define pinstCPetInfoWnd                                   0x751990
#define pinstCTrainWnd                                     0x751994
#define pinstCSkillsWnd                                    0x751998
#define pinstCSkillsSelectWnd                              0x75199C
#define pinstCCombatSkillSelectWnd                         0x7519A0
#define pinstCFriendsWnd                                   0x7519A4
#define pinstCAAWnd                                        0x7519B0
#define pinstCGroupSearchFiltersWnd                        0x7519B4
#define pinstCLoadskinWnd                                  0x7519B8
#define pinstCAlarmWnd                                     0x7519BC
#define pinstCMusicPlayerWnd                               0x7519C0
#define pinstCRaidWnd                                      0x7519CC
#define pinstCRaidOptionsWnd                               0x7519D0
#define pinstCBreathWnd                                    0x7519D4
#define pinstCMapViewWnd                                   0x7519D8
#define pinstCMapToolbarWnd                                0x7519DC
#define pinstCEditLabelWnd                                 0x7519E0
#define pinstCTargetWnd                                    0x7519E4
#define pinstCHotButtonWnd                                 0x7519E8
#define pinstCColorPickerWnd                               0x7519EC
#define pinstCPlayerWnd                                    0x7519F0
#define pinstCOptionsWnd                                   0x7519F4
#define pinstCBuffWindowNORMAL                             0x7519F8
#define pinstCBuffWindowSHORT                              0x7519FC
#define pinstCharacterCreation                             0x751A00
#define pinstCCursorAttachment                             0x751A04
#define pinstCCastingWnd                                   0x751A08
#define pinstCCastSpellWnd                                 0x751A0C
#define pinstCSpellBookWnd                                 0x751A10
#define pinstCInventoryWnd                                 0x751A14
#define pinstCBankWnd                                      0x751A18
#define pinstCQuantityWnd                                  0x751A1C
#define pinstCLootWnd                                      0x751A20
#define pinstCActionsWnd                                   0x751A24
#define pinstCCombatAbilityWnd                             0x751A28
#define pinstCMerchantWnd                                  0x751A2C
#define pinstCTradeWnd                                     0x751A30
#define pinstCSelectorWnd                                  0x751A34
#define pinstCBazaarWnd                                    0x751A38
#define pinstCBazaarSearchWnd                              0x751A3C
#define pinstCGiveWnd                                      0x751A40
#define pinstCTrackingWnd                                  0x751A44
#define pinstCInspectWnd                                   0x751A48
#define pinstCSocialEditWnd                                0x751A4C
#define pinstCFeedbackWnd                                  0x751A50
#define pinstCBugReportWnd                                 0x751A54
#define pinstCVideoModesWnd                                0x751A58
#define pinstCTextEntryWnd                                 0x751A60
#define pinstCFileSelectionWnd                             0x751A64
#define pinstCCompassWnd                                   0x751A68
#define pinstCPlayerNotesWnd                               0x751A6C
#define pinstCGemsGameWnd                                  0x751A70
#define pinstCTimeLeftWnd                                  0x751A74
#define pinstCPetitionQWnd                                 0x751A78
#define pinstCSoulmarkWnd                                  0x751A7C
#define pinstCStoryWnd                                     0x751A80
#define pinstCJournalTextWnd                               0x751A84
#define pinstCJournalCatWnd                                0x751A88
#define pinstCBodyTintWnd                                  0x751A8C
#define pinstCInvSlotMgr                                   0x751A90
#define pinstCContainerMgr                                 0x751A94
#define pinstCAdventureLeaderboardWnd                      0x72652C
#define pinstCAdventureMerchantWnd                         0x726548
#define pinstCAdventureRequestWnd                          0x726564
#define pinstCAdventureStatsWnd                            0x726580
#define pinstCChatManager                                  0x7269B0
#define pinstCDynamicZoneWnd                               0x751BA0
#define pinstCFindLocationWnd                              0x875D58
#define pinstCGroupSearchWnd                               0x875E50
#define pinstCGroupWnd                                     0x875E6C
#define pinstCGuildMgmtWnd                                 0x875EA4
#define pinstCItemDisplayManager                           0x875F88
#define pinstCLeadershipWnd                                0x876070
#define pinstCPopupWndManager                              0x876490
#define pinstCSystemInfoDialogBox                          0x876E28
#define pinstCTargetOfTargetWnd                            0x876E4C
#define pinstCTipWndOFDAY                                  0x876F3C
#define pinstCTipWndCONTEXT                                0x876F40
#define pinstCTradeskillWnd                                0x877038
#define pinstCTributeBenefitWnd                            0x877084
#define pinstCTributeMasterWnd                             0x8770A0
#define pinstCContextMenuManager                           0x88D504
// unknown window added 4-14 exe 0x79A234 


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define DrawNetStatus                                      0x500139
#define CrashDetected                                      0x538203
#define __ProcessGameEvents                                0x4C29CF
#define __ConvertItemTags                                  0x463EDD
#define __SendMessage                                      0x4A9F42
#define __NewUIINI                                         0x52303A
#define __ExecuteCmd                                       0x455C95
#define __GetGaugeValueFromEQ                              0x5214A1
#define __get_melee_range                                  0x45A87B
#define __CastRay                                          0x464683
#define __LoadSplashScreen								   0x5B7F60

// EQ_LoadingS 
#define EQ_LoadingS__WriteTextHD                           0x49DE33


//// 
// Section 4: Function Offsets 
//// 
// CEverQuest 
#define CEverQuest__dsp_chat                               0x4B16C4
#define CEverQuest__ClickedPlayer                          0x4AF2E6
#define CEverQuest__EnterZone                              0x4C1756
#define CEverQuest__GetBodyTypeDesc                        0x4AAF6C
#define CEverQuest__GetClassDesc                           0x4AA98F
#define CEverQuest__GetClassThreeLetterCode                0x4AAE09
#define CEverQuest__GetDeityDesc                           0x4AC9FF
#define CEverQuest__GetRaceDesc                            0x4AB271
#define CEverQuest__InterpretCmd                           0x4BBDB6
#define CEverQuest__LeftClickedOnPlayer                    0x4C00B3
#define CEverQuest__RightClickedOnPlayer                   0x4C04E9
#define CEverQuest__SetGameState                           0x4AF3C6
#define CEverQuest__DropHeldItemOnGround                   0x4B106E

// StringTable 
#define StringTable__getString                             0x5A9300

// AltAdvManager 
#define AltAdvManager__IsAbilityReady                      0x486E25
#define AltAdvManager__GetCalculatedTimer                  0x486DF7

// CXWndManager 
#define CXWndManager__RemoveWnd                            0x57DBF0
#define CXWndManager__GetKeyboardFlags                     0x57D780
#define CXWndManager__HandleKeyboardMsg                    0x57DCE0
#define CXWndManager__DrawWindows                          0x57EA80
#define CXWndManager__DrawCursor                           0x57EE30
#define CXWndManager__GetFirstChildWnd                     0x57E3D0

// KeyPressHandler 
#define KeypressHandler__HandleKeyDown                     0x4EC8B6
#define KeypressHandler__HandleKeyUp                       0x4ECB2D
#define KeypressHandler__AttachKeyToEqCommand              0x4EDBFE
#define KeypressHandler__AttachAltKeyToEqCommand           0x4EDC31
#define KeypressHandler__SaveKeymapping                    0x4EDACE
#define KeypressHandler__ClearCommandStateArray            0x4EDA47

// EQ_Character 
#define EQ_Character__Max_Endurance                        0x487B0A
#define EQ_Character__Max_HP                               0x4878B7
#define EQ_Character__Cur_HP                               0x48C042
#define EQ_Character__GetFocusCastingTimeModifier          0x493411
#define EQ_Character__GetAACastingTimeModifier             0x493929
#define EQ_Character__CastSpell                            0x497086
#define EQ_Character__Max_Mana                             0x4A1005

// EQPlayer 
#define EQPlayer__EQPlayer                                 0x47A058
#define EQPlayer__dEQPlayer                                0x4798DD
#define EQPlayer__DoAttack                                 0x475EE9
#define EQPlayer__ChangeBoneStringSprite                   0x46FC4F
#define EQPlayer__SetNameSpriteState                       0x473F88
#define EQPlayer__SetNameSpriteTint                        0x46FCBB

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                       0x401006
#define CXStr__CXStr1                                      0x401000
#define CXStr__CXStr3                                      0x53BE50
#define CXStr__dCXStr                                      0x40A054
#define CXStr__operator_plus_equal1                        0x53CE50
#define CXStr__operator_equal1                             0x53C010

// CChatWindow 
#define CChatWindow__CChatWindow                           0x422490

// CChatManager 
#define CChatManager__GetRGBAFromIndex                     0x41F449
#define CChatManager__InitContextMenu                      0x41F52D

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                           0x4E1D80
#define CInvSlotMgr__MoveItem                              0x4E16C4

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                           0x4E67C2
#define CItemDisplayWnd__SetSpell                          0x4E57BC

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                         0x4DE408

// CLabel 
#define CLabel__Draw                                       0x4EDDC8

// CGauge 
#define CGaugeWnd__Draw                                    0x4CE413

// CDisplay 
#define CDisplay__ReloadUI                                 0x440F67
#define CDisplay__CleanGameUI                              0x43981E
#define CDisplay__GetClickedActor                          0x4363DE
#define CDisplay__WriteTextHD2                             0x43A4A8
#define CDisplay__GetWorldFilePath                         0x434FAD
#define CDisplay__GetUserDefinedColor                      0x4357A1

#define CTextureFont__DrawWrappedText                      0x5601B0

// EQ_Item 
#define EQ_Item__GetItemLinkHash                           0x49D349
#define EQ_Item__CanDrop                                   0x49D757
#define EQ_Item__IsStackable                               0x49D8FB

// CBankWnd 
#define CBankWnd__GetNumBankSlots                          0x40B5EA

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                  0x40E933

// CMerchantWnd 
#define CMerchantWnd__SelectBuySellSlot                    0x4FD4EF
#define CMerchantWnd__RequestBuyItem                       0x4FC391
#define CMerchantWnd__RequestSellItem                      0x4FC72A
#define CMerchantWnd__DisplayBuyOrSellPrice                0x4FC1D3

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                         0x51F918

// MapViewMap 
#define MapViewMap__SaveEx                                 0x4F8256
#define MapViewMap__Clear                                  0x4F7ABB


// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                           0x4FACE1
#define CButtonWnd__SetCheck                        0x57A4C0

// EQItemList 
#define EQItemList__EQItemList                             0x45872B
#define EQItemList__dEQItemList                            0x4587A7

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                      0x4A11FC

// CContainerWnd 
#define CContainerWnd__HandleCombine                       0x429DD0
#define CContainerWnd__vftable                             0x5E3DA8

// CSidlScreenWnd 
#define CSidlScreenWnd__CSidlScreenWnd1                    0x55B020
#define CSidlScreenWnd__dCSidlScreenWnd                    0x55A670
#define CSidlScreenWnd__CreateChildrenFromSidl             0x559920
#define CSidlScreenWnd__WndNotification                    0x5594A0
#define CSidlScreenWnd__CalculateHSBRange                  0x558AC0
#define CSidlScreenWnd__CalculateVSBRange                  0x558A00
#define CSidlScreenWnd__ConvertToRes                       0x5591B0
#define CSidlScreenWnd__CSidlScreenWnd2                    0x55B110
#define CSidlScreenWnd__DrawSidlPiece                      0x559540
#define CSidlScreenWnd__EnableIniStorage                   0x559160
#define CSidlScreenWnd__GetSidlPiece                       0x5597E0
#define CSidlScreenWnd__Init1                              0x55AD70
#define CSidlScreenWnd__LoadIniInfo                        0x5599D0
#define CSidlScreenWnd__LoadIniListWnd                     0x55A310
#define CSidlScreenWnd__LoadSidlScreen                     0x559380
#define CSidlScreenWnd__SetScreen                          0x55A790
#define CSidlScreenWnd__StoreIniInfo                       0x558CF0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1             0x586370

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                        0x58CF80

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                       0x579220

// CXRect 
#define CXRect__CenterPoint                                0x40AE4D

// CXWnd 
#define CXWnd__BringToTop                                  0x55B7C0
#define CXWnd__Center                                      0x55EDE0
#define CXWnd__ClrFocus                                    0x55B510
#define CXWnd__DoAllDrawing                                0x55F9F0
#define CXWnd__DrawChildren                                0x55FB20
#define CXWnd__DrawColoredRect                             0x55B9E0
#define CXWnd__DrawTooltipAtPoint                          0x55EC10
#define CXWnd__GetBorderFrame                              0x55BE20
#define CXWnd__GetChildWndAt                               0x55E7A0
#define CXWnd__GetClientClipRect                           0x55BD70
#define CXWnd__GetFirstChildWnd                            0x55B850
#define CXWnd__GetNextChildWnd                             0x55E780
#define CXWnd__GetNextSib                                  0x55B870
#define CXWnd__GetScreenClipRect                           0x55F070
#define CXWnd__GetScreenRect                               0x55BFF0
#define CXWnd__GetTooltipRect                              0x55EB60
#define CXWnd__GetWindowTextA                              0x402A8F
// CHECK THIS ^^^^^^^^^^^^^^ 
#define CXWnd__GetXMLTooltip                               0x55B350
#define CXWnd__IsActive                                    0x55BDE0
#define CXWnd__IsDescendantOf                              0x55BDF0
#define CXWnd__IsReallyVisible                             0x55E760
#define CXWnd__IsType                                      0x55F990
#define CXWnd__Move                                        0x55E310
#define CXWnd__Move1                                       0x55E3A0
#define CXWnd__ProcessTransition                           0x55B780
#define CXWnd__Refade                                      0x55B5B0
#define CXWnd__Resize                                      0x55F1B0
#define CXWnd__Right                                       0x55EF50
#define CXWnd__SetFirstChildPointer                        0x55C240
#define CXWnd__SetFocus                                    0x55D4F0
#define CXWnd__SetKeyTooltip                               0x55C280
#define CXWnd__SetMouseOver                                0x55C260
#define CXWnd__SetNextSibPointer                           0x55C250
#define CXWnd__StartFade                                   0x55B7E0

// CSliderWnd 
#define CSliderWnd__GetValue                               0x57BBA0
#define CSliderWnd__SetValue                               0x57BD80
#define CSliderWnd__UpdateThumb                            0x57BB60

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                          0x408123
#define CEditBaseWnd__SetSel                               0x58C310

// CComboWnd 
#define CComboWnd__DeleteAll                               0x57B130
#define CComboWnd__Draw                                    0x57B330
#define CComboWnd__GetButtonRect                           0x57B160
#define CComboWnd__GetCurChoice                            0x57B0F0
#define CComboWnd__GetListRect                             0x57B720
#define CComboWnd__GetTextRect                             0x57B1C0
#define CComboWnd__InsertChoice                            0x57B780
#define CComboWnd__SetColors                               0x57B0C0
#define CComboWnd__SetChoice                               0x57B860

// CListWnd 
#define CListWnd__AddColumn                                0x564B90
#define CListWnd__AddColumn1                               0x5646E0
#define CListWnd__AddLine                                  0x5642A0
#define CListWnd__AddString                                0x564420
#define CListWnd__CalculateFirstVisibleLine                0x561810
#define CListWnd__CalculateVSBRange                        0x5633A0
#define CListWnd__ClearAllSel                              0x560F70
#define CListWnd__CloseAndUpdateEditWindow                 0x561E10
#define CListWnd__Compare                                  0x562150
#define CListWnd__Draw                                     0x563000
#define CListWnd__DrawColumnSeparators                     0x562E50
#define CListWnd__DrawHeader                               0x561190
#define CListWnd__DrawItem                                 0x562860
#define CListWnd__DrawLine                                 0x562BC0
#define CListWnd__DrawSeparator                            0x562F20
#define CListWnd__EnsureVisible                            0x561860
#define CListWnd__ExtendSel                                0x562790
#define CListWnd__GetColumnFlags                           0x560A40
#define CListWnd__GetColumnJustification                   0x560BE0
#define CListWnd__GetColumnMinWidth                        0x560B70
#define CListWnd__GetColumnWidth                           0x560AA0
#define CListWnd__GetCurSel                                0x560880
#define CListWnd__GetHeaderRect                            0x5606C0
#define CListWnd__GetItemAtPoint                           0x561B10
#define CListWnd__GetItemAtPoint1                          0x561B80
#define CListWnd__GetItemData                              0x5608C0
#define CListWnd__GetItemHeight                            0x561590
#define CListWnd__GetItemIcon                              0x560980
#define CListWnd__GetItemRect                              0x561930
#define CListWnd__GetItemText                              0x560900
#define CListWnd__GetSelList                               0x5645C0
#define CListWnd__GetSeparatorRect                         0x5620A0
#define CListWnd__IsLineEnabled                            0x561060
#define CListWnd__RemoveLine                               0x564570
#define CListWnd__SetColors                                0x560630
#define CListWnd__SetColumnWidth                           0x560B20
#define CListWnd__SetColumnJustification                   0x560C40
#define CListWnd__SetCurSel                                0x560E90
#define CListWnd__SetItemColor                             0x563EE0
#define CListWnd__SetItemData                              0x561020
#define CListWnd__SetItemText                              0x563E20
#define CListWnd__ShiftColumnSeparator                     0x562700
#define CListWnd__Sort                                     0x564C30
#define CListWnd__ToggleSel                                0x560EB0

// CEditWnd 
#define CEditWnd__DrawCaret                                0x588380
#define CEditWnd__GetCharIndexPt                           0x5891E0
#define CEditWnd__GetDisplayString                         0x5884E0
#define CEditWnd__GetHorzOffset                            0x588750
#define CEditWnd__GetLineForPrintableChar                  0x588C80
#define CEditWnd__GetSelStartPt                            0x589420
#define CEditWnd__GetSTMLSafeText                          0x588930
#define CEditWnd__PointFromPrintableChar                   0x588D90
#define CEditWnd__SelectableCharFromPoint                  0x588F10
#define CEditWnd__SetEditable                              0x588900

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                            0x4CE0B7
#define CGaugeWnd__CalcLinesFillRect                       0x4CE113
#define CGaugeWnd__Draw                                    0x4CE413

// CStmlWnd 
#define CStmlWnd__AppendSTML                               0x56E150
#define CStmlWnd__CalculateHSBRange                        0x565A10
#define CStmlWnd__CalculateVSBRange                        0x5659B0
#define CStmlWnd__CanBreakAtCharacter                      0x565B50
#define CStmlWnd__CanGoBackward                            0x565BD0
#define CStmlWnd__FastForwardToEndOfTag                    0x566900
#define CStmlWnd__GetNextChar                              0x566010
#define CStmlWnd__GetNextTagPiece                          0x566700
#define CStmlWnd__GetSTMLText                              0x422472
#define CStmlWnd__GetThisChar                              0x565850
#define CStmlWnd__GetVisiableText                          0x5680D0
#define CStmlWnd__InitializeWindowVariables                0x569ED0
#define CStmlWnd__MakeStmlColorTag                         0x564F20
#define CStmlWnd__MakeWndNotificationTag                   0x564FC0
#define CStmlWnd__StripFirstSTMLLines                      0x56DED0
#define CStmlWnd__UpdateHistoryString                      0x568510

// CTabWnd 
#define CTabWnd__Draw                                      0x571F30
#define CTabWnd__DrawCurrentPage                           0x571A20
#define CTabWnd__DrawTab                                   0x5717A0
#define CTabWnd__GetCurrentPage                            0x571290
#define CTabWnd__GetCurrentTabIndex                        0x570FB0
#define CTabWnd__GetNumTabs                                0x5710E0
#define CTabWnd__GetPageClientRect                         0x570FC0
#define CTabWnd__GetPageFromTabIndex                       0x571110
#define CTabWnd__GetPageInnerRect                          0x571020
#define CTabWnd__GetTabInnerRect                           0x5713A0
#define CTabWnd__GetTabRect                                0x5712A0
#define CTabWnd__IndexInBounds                             0x5710F0
#define CTabWnd__InsertPage                                0x571E20
#define CTabWnd__SetPage                                   0x571440
#define CTabWnd__SetPageRect                               0x571610
#define CTabWnd__UpdatePage                                0x5716C0

// CTextOverlay 
#define CTextOverlay__DisplayText                          0x412D28

/* 
CListWnd__GetCurCol 

CContextMenu__CContextMenu 
CContextMenu__AddMenuItem 
CContextMenu__AddSeparator 
CContextMenu__RemoveAllMenuItems 
CContextMenu__Activate 
/**/ 
