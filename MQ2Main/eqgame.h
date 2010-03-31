/* ***************************************************************************** 
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


#define __ClientName                                      "eqgame" 
#define __ExpectedVersionDate                         "Aug 13 2004" 
#define __ExpectedVersionTime                         "10:18:48" 
#define __ActualVersionDate                                0x5D706C
#define __ActualVersionTime                                0x5D7078

#define __ClientOverride                       0 
#define __MacroQuestWinClassName                 "__MacroQuestTray" 
#define __MacroQuestWinName                           "MacroQuest" 

// Memory Protection 
#define __MemChecker0                                      0x4AA256
#define __MemChecker1                                      0x4AF760
#define __MemChecker2                                      0x4B15F8
#define __MemChecker3                                      0x4B1695
#define __EncryptPad0                                      0x6FE640
#define __EncryptPad1                                      0x6FEA40
#define __EncryptPad2                                      0x6FF518
#define __EncryptPad3                                      0x6FF918

#define DI8__Main                                          0x88F0A4
#define DI8__Keyboard                                      0x88F0A8
#define DI8__Mouse                                         0x88F0AC

#define __LastTell                                         0x7CF82C
#define __Guilds                                           0x82FF08
#define __Mouse                                            0x88F0B0
#define __Attack                                           0x82E080
#define __InChatMode                                       0x7CD708
#define __gWorld                                           0x82FE60
#define __GroupCount                                       0x82E410
#define __CommandList                                      0x6FA160
#define __DoAbilityList                                    0x807300
#define __DoAbilityAvailable                               0x7CE544
#define __ServerHost                                       0x82E2CC
#define __ServerName                                       0x8072C0
#define __HWnd                                             0x7CD6C8
#define __Clicks                                           0x7CD7CC
#define __ScreenX                                          0x7CD6D0
#define __ScreenY                                          0x7CD6D4
#define __ScreenMode                                       0x719618
#define __MouseLook                                        0x7CD79A
#define __EQP_IDArray                                      0x7CA798
#define __CurrentMapLabel                                  0x897F88
#define __BindList                                         0x6F9C10
#define __RangeAttackReady                                 0x7CE5A8
#define __AltTimerReady                                    0x7CE5AA
#define __Socials                                          0x8073C0
#define __HotkeyPage                                       0x82DC60
#define __CurrentSocial                                    0x607014
#define __GroupLeader                                      0x82E56C
#define __SkillDict                                        0x71AAB8
#define __DrawHandler                                      0x8A3C94
#define __FriendsList                                      0x8040C0
#define __IgnoreList                                       0x8059C0
#define __NetStatusToggle                                  0x7CD79C
#define __ShowNames                                        0x7CE78C
#define __PCNames                                          0x7CE83C
//// 
//Section 1: Vital Offsets 
//// 
#define pinstCSidlManager                                  0x8A33C4
#define pinstCDisplay                                      0x82FEEC
#define pinstCEverQuest                                    0x88F218
#define pinstPCData                                        0x82FEC8
#define pinstCharData                                      0x82FEC8
#define pinstCharSpawn                                     0x82FEC0
#define pinstSpawnList                                     0x82FE88
#define pinstLocalPlayer                                   0x82FEAC
#define pinstControlledPlayer                              0x82FEC0
#define pinstWorldData                                     0x82FE84
#define pinstSpellManager                                  0x88BC3C
#define pinstTradeTarget                                   0x82FEA8
#define pinstActiveMerchant                                0x82FED8
#define pinstActiveBanker                                  0x82FEDC
#define pinstActiveCorpse                                  0x82FEE0
#define pinstActiveGMaster                                 0x82FEE4
#define pinstSelectedItem                                  0x897E68
#define pinstGroup                                         0x82E558
#define pinstTarget                                        0x82FECC
#define pinstSwitchManager                                 0x7CD6B8
#define pinstEQItemList                                    0x82FE8C
#define pinstSpellSets                                     0x82DC64
#define instEQZoneInfo                                     0x7CD938
#define pinstCXWndManager                                  0x8A33BC
#define instKeypressHandler                                0x87E2F8
#define pinstStringTable                                   0x82FE78
#define pinstAltAdvManager                                 0x71A6D0
#define instCRaid                                          0x8381C0

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                  0x7080E4
#define pinstCharacterSelect                               0x71A0AC
#define pinstCFacePick                                     0x71A0B0
// removed 4-14 exe #define pinstCTextMessageWnd                                
#define pinstCNoteWnd                                      0x71A0B4
#define pinstCHelpWnd                                      0x71A0B8
#define pinstCBookWnd                                      0x71A0BC
#define pinstCPetInfoWnd                                   0x71A0C0
#define pinstCTrainWnd                                     0x71A0C4
#define pinstCSkillsWnd                                    0x71A0C8
#define pinstCSkillsSelectWnd                              0x71A0CC
#define pinstCCombatSkillSelectWnd                         0x71A0D0
#define pinstCFriendsWnd                                   0x71A0D4
#define pinstCAAWnd                                        0x71A0D8
#define pinstCGroupSearchFiltersWnd                        0x71A0DC
#define pinstCLoadskinWnd                                  0x71A0E0
#define pinstCAlarmWnd                                     0x71A0E4
#define pinstCMusicPlayerWnd                               0x71A0E8
#define pinstCRaidWnd                                      0x71A0F4
#define pinstCRaidOptionsWnd                               0x71A0F8
#define pinstCBreathWnd                                    0x71A0FC
#define pinstCMapViewWnd                                   0x71A100
#define pinstCMapToolbarWnd                                0x71A104
#define pinstCEditLabelWnd                                 0x71A108
#define pinstCTargetWnd                                    0x71A10C
#define pinstCHotButtonWnd                                 0x71A110
#define pinstCColorPickerWnd                               0x71A114
#define pinstCPlayerWnd                                    0x71A118
#define pinstCOptionsWnd                                   0x71A11C
#define pinstCBuffWindowNORMAL                             0x71A120
#define pinstCBuffWindowSHORT                              0x71A124
#define pinstCharacterCreation                             0x71A128
#define pinstCCursorAttachment                             0x71A12C
#define pinstCCastingWnd                                   0x71A130
#define pinstCCastSpellWnd                                 0x71A134
#define pinstCSpellBookWnd                                 0x71A138
#define pinstCInventoryWnd                                 0x71A13C
#define pinstCBankWnd                                      0x71A140
#define pinstCQuantityWnd                                  0x71A144
#define pinstCLootWnd                                      0x71A148
#define pinstCActionsWnd                                   0x71A14C
#define pinstCCombatAbilityWnd                             0x71A150
#define pinstCMerchantWnd                                  0x71A154
#define pinstCTradeWnd                                     0x71A158
#define pinstCSelectorWnd                                  0x71A15C
#define pinstCBazaarWnd                                    0x71A160
#define pinstCBazaarSearchWnd                              0x71A164
#define pinstCGiveWnd                                      0x71A168
#define pinstCTrackingWnd                                  0x71A16C
#define pinstCInspectWnd                                   0x71A170
#define pinstCSocialEditWnd                                0x71A174
#define pinstCFeedbackWnd                                  0x71A178
#define pinstCBugReportWnd                                 0x71A17C
#define pinstCVideoModesWnd                                0x71A180
#define pinstCTextEntryWnd                                 0x71A184
#define pinstCFileSelectionWnd                             0x71A188
#define pinstCCompassWnd                                   0x71A18C
#define pinstCPlayerNotesWnd                               0x71A190
#define pinstCGemsGameWnd                                  0x71A194
#define pinstCTimeLeftWnd                                  0x71A198
#define pinstCPetitionQWnd                                 0x71A19C
#define pinstCSoulmarkWnd                                  0x71A1A0
#define pinstCStoryWnd                                     0x71A1A4
#define pinstCJournalTextWnd                               0x71A1A8
#define pinstCJournalCatWnd                                0x71A1AC
#define pinstCBodyTintWnd                                  0x71A1B0
#define pinstCInvSlotMgr                                   0x71A1B4
#define pinstCContainerMgr                                 0x71A1B8
#define pinstCAdventureLeaderboardWnd                      0x8978F8
#define pinstCAdventureMerchantWnd                         0x897910
#define pinstCAdventureRequestWnd                          0x897928
#define pinstCAdventureStatsWnd                            0x897940
#define pinstCChatManager                                  0x897BE0
#define pinstCDynamicZoneWnd                               0x897C98
#define pinstCFindLocationWnd                              0x897D28
#define pinstCGroupSearchWnd                               0x897DA4
#define pinstCGroupWnd                                     0x897DBC
#define pinstCGuildMgmtWnd                                 0x897DD4
#define pinstCItemDisplayManager                           0x897E94
#define pinstCLeadershipWnd                                0x897EFC
#define pinstCPopupWndManager                              0x898074
#define pinstCSystemInfoDialogBox                          0x89896C
#define pinstCTargetOfTargetWnd                            0x898984
#define pinstCTipWndOFDAY                                  0x898A20
#define pinstCTipWndCONTEXT                                0x898A24
#define pinstCTradeskillWnd                                0x898A64
#define pinstCTributeBenefitWnd                            0x898AA4
#define pinstCTributeMasterWnd                             0x898ABC
#define pinstCContextMenuManager                           0x8A33E0
// unknown window added 4-14 exe 0x79A234 


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define DrawNetStatus                                      0x49DFD5
#define CrashDetected                                      0x4B21DA
#define __ProcessGameEvents                                0x494A0A
#define __ConvertItemTags                                  0x457B06
#define __SendMessage                                      0x4A3B6A
#define __NewUIINI                                         0x51949E
#define __ExecuteCmd                                       0x44C4E6
#define __GetGaugeValueFromEQ                              0x517AD4
#define __get_melee_range                                  0x4509A5
#define __CastRay                                          0x45F864

// EQ_LoadingS 
#define EQ_LoadingS__WriteTextHD                           0x431E8C


//// 
// Section 4: Function Offsets 
//// 
// CEverQuest 
#define CEverQuest__dsp_chat                               0x483D68
#define CEverQuest__ClickedPlayer                          0x480F65
#define CEverQuest__EnterZone                              0x484959
#define CEverQuest__GetBodyTypeDesc                        0x47AE1A
#define CEverQuest__GetClassDesc                           0x47A89C
#define CEverQuest__GetClassThreeLetterCode                0x47ACB7
#define CEverQuest__GetDeityDesc                           0x47C8AD
#define CEverQuest__GetRaceDesc                            0x47B11F
#define CEverQuest__GetTitleDesc                           0x47C9C4
#define CEverQuest__InterpretCmd                           0x49145F
#define CEverQuest__LeftClickedOnPlayer                    0x4936CF
#define CEverQuest__RightClickedOnPlayer                   0x48BC72
#define CEverQuest__SetGameState                           0x481038
#define CEverQuest__DropHeldItemOnGround                   0x483712

// StringTable 
#define StringTable__getString                             0x4A6D98

// AltAdvManager 
#define AltAdvManager__IsAbilityReady                      0x41BD48

// CXWndManager 
#define CXWndManager__RemoveWnd                            0x56AA50
#define CXWndManager__GetKeyboardFlags                     0x56A670
#define CXWndManager__HandleKeyboardMsg                    0x56AB40
#define CXWndManager__DrawWindows                          0x56B8B0
#define CXWndManager__DrawCursor                           0x56BC60
#define CXWndManager__GetFirstChildWnd                     0x56B230

// KeyPressHandler 
#define KeypressHandler__HandleKeyDown                     0x4991DA
#define KeypressHandler__HandleKeyUp                       0x49947E
#define KeypressHandler__AttachKeyToEqCommand              0x49A8EA
#define KeypressHandler__AttachAltKeyToEqCommand           0x49A927
#define KeypressHandler__SaveKeymapping                    0x49A7D2
#define KeypressHandler__ClearCommandStateArray            0x49946D

// EQ_Character 
#define EQ_Character__Max_Endurance                        0x41C994
#define EQ_Character__Max_Mana                             0x41CA1D
#define EQ_Character__Max_HP                               0x41C741
#define EQ_Character__Cur_HP                               0x420281
#define EQ_Character__GetFocusCastingTimeModifier          0x427B9C
#define EQ_Character__GetAACastingTimeModifier             0x427F79
#define EQ_Character__CastSpell                            0x42BDB2
#define EQ_Character__GetAbility                           0x429C06

// EQPlayer 
#define EQPlayer__EQPlayer                                 0x46EB4F
#define EQPlayer__dEQPlayer                                0x46E3F3
#define EQPlayer__DoAttack                                 0x46A95E
#define EQPlayer__ChangeBoneStringSprite                   0x464AC4
#define EQPlayer__SetNameSpriteState                       0x468DB9
#define EQPlayer__SetNameSpriteTint                        0x464B30

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                       0x401254
#define CXStr__CXStr1                                      0x401CB3
#define CXStr__CXStr3                                      0x59CC40
#define CXStr__dCXStr                                      0x40127E
#define CXStr__operator_plus_equal1                        0x59DD00
#define CXStr__operator_equal1                             0x59CE00

// CChatWindow 
#define CChatWindow__CChatWindow                           0x4CF38D

// CChatManager 
#define CChatManager__GetRGBAFromIndex                     0x4CBE30
#define CChatManager__InitContextMenu                      0x4CC794

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                           0x4ECD9D
#define CInvSlotMgr__MoveItem                              0x4ED1B9

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                           0x4F054E
#define CItemDisplayWnd__SetSpell                          0x4EF7EB

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                         0x4E9ADE

// CLabel 
#define CLabel__Draw                                       0x4F63E4

// CGauge 
#define CGaugeWnd__Draw                                    0x4DBF36

// CDisplay 
#define CDisplay__ReloadUI                                 0x41A46F
#define CDisplay__CleanGameUI                              0x412D44
#define CDisplay__GetClickedActor                          0x40FEE4
#define CDisplay__WriteTextHD2                             0x41385C
#define CDisplay__GetWorldFilePath                         0x40EBA9
#define CDisplay__GetUserDefinedColor                      0x40F3A5

#define CTextureFont__DrawWrappedText                      0x55AC90

// EQ_Item 
#define EQ_Item__GetItemLinkHash                           0x431216
#define EQ_Item__CanDrop                                   0x43160F

// CBankWnd 
#define CBankWnd__GetNumBankSlots                          0x4BCE92

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                  0x4BF6A5

// CMerchantWnd 
#define CMerchantWnd__SelectBuySellSlot                    0x4FEDFD
#define CMerchantWnd__RequestBuyItem                       0x4FEF30
#define CMerchantWnd__RequestSellItem                      0x4FF138
#define CMerchantWnd__DisplayBuyOrSellPrice                0x4FE40A

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                         0x51620F

// MapViewMap 
#define MapViewMap__SaveEx                                 0x4F9D58
#define MapViewMap__Clear                                  0x4F9BE7


// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                           0x4FD61C

// EQItemList 
#define EQItemList__EQItemList                             0x44EE15
#define EQItemList__dEQItemList                            0x44EE91

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                      0x4351AB

// CContainerWnd 
#define CContainerWnd__HandleCombine                       0x4D47B1
#define CContainerWnd__vftable                             0x5DB238

// CSidlScreenWnd 
#define CSidlScreenWnd__CSidlScreenWnd1                    0x54E670
#define CSidlScreenWnd__dCSidlScreenWnd                    0x54DD10
#define CSidlScreenWnd__CreateChildrenFromSidl             0x54D080
#define CSidlScreenWnd__WndNotification                    0x54CC00
#define CSidlScreenWnd__CalculateHSBRange                  0x54C220
#define CSidlScreenWnd__CalculateVSBRange                  0x54C160
#define CSidlScreenWnd__ConvertToRes                       0x54C910
#define CSidlScreenWnd__CSidlScreenWnd2                    0x54E760
#define CSidlScreenWnd__DrawSidlPiece                      0x54CCA0
#define CSidlScreenWnd__EnableIniStorage                   0x54C8C0
#define CSidlScreenWnd__GetSidlPiece                       0x54CF40
#define CSidlScreenWnd__Init1                              0x54E3C0
#define CSidlScreenWnd__LoadIniInfo                        0x54D130
#define CSidlScreenWnd__LoadIniListWnd                     0x54DA70
#define CSidlScreenWnd__LoadSidlScreen                     0x54CAE0
#define CSidlScreenWnd__SetScreen                          0x54DE30
#define CSidlScreenWnd__StoreIniInfo                       0x54C450

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1             0x573080

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                        0x57FFA0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                       0x55A5B0

// CXRect 
#define CXRect__CenterPoint                                0x4BCE99

// CXWnd 
#define CXWnd__BringToTop                                  0x54EDF0
#define CXWnd__Center                                      0x552450
#define CXWnd__ClrFocus                                    0x54EB40
#define CXWnd__DoAllDrawing                                0x553060
#define CXWnd__DrawChildren                                0x553190
#define CXWnd__DrawColoredRect                             0x54F020
#define CXWnd__DrawTooltipAtPoint                          0x552280
#define CXWnd__GetBorderFrame                              0x54F460
#define CXWnd__GetChildWndAt                               0x551E10
#define CXWnd__GetClientClipRect                           0x54F3B0
#define CXWnd__GetFirstChildWnd                            0x54EE80
#define CXWnd__GetNextChildWnd                             0x551DF0
#define CXWnd__GetNextSib                                  0x54EEA0
#define CXWnd__GetScreenClipRect                           0x5526E0
#define CXWnd__GetScreenRect                               0x54F630
#define CXWnd__GetTooltipRect                              0x5521D0
#define CXWnd__GetWindowTextA                              0x4B6CF1
#define CXWnd__GetXMLTooltip                               0x54E980
#define CXWnd__IsActive                                    0x54F420
#define CXWnd__IsDescendantOf                              0x54F430
#define CXWnd__IsReallyVisible                             0x551DD0
#define CXWnd__IsType                                      0x553000
#define CXWnd__Move                                        0x551980
#define CXWnd__Move1                                       0x551A10
#define CXWnd__ProcessTransition                           0x54EDB0
#define CXWnd__Refade                                      0x54EBE0
#define CXWnd__Resize                                      0x552820
#define CXWnd__Right                                       0x5525C0
#define CXWnd__SetFirstChildPointer                        0x54F880
#define CXWnd__SetFocus                                    0x550B60
#define CXWnd__SetKeyTooltip                               0x54F8C0
#define CXWnd__SetMouseOver                                0x54F8A0
#define CXWnd__SetNextSibPointer                           0x54F890
#define CXWnd__StartFade                                   0x54EE10

// CSliderWnd 
#define CSliderWnd__GetValue                               0x57E930
#define CSliderWnd__SetValue                               0x57EB20
#define CSliderWnd__UpdateThumb                            0x57E8F0

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                          0x4BCA08
#define CEditBaseWnd__SetSel                               0x575010

// CComboWnd 
#define CComboWnd__DeleteAll                               0x57A000
#define CComboWnd__Draw                                    0x57A200
#define CComboWnd__GetButtonRect                           0x57A030
#define CComboWnd__GetCurChoice                            0x579FC0
#define CComboWnd__GetListRect                             0x57A5F0
#define CComboWnd__GetTextRect                             0x57A090
#define CComboWnd__InsertChoice                            0x57A650
#define CComboWnd__SetColors                               0x579F90
#define CComboWnd__SetChoice                               0x57A730

// CListWnd 
#define CListWnd__AddColumn                                0x569370
#define CListWnd__AddColumn1                               0x568EC0
#define CListWnd__AddLine                                  0x568A80
#define CListWnd__AddString                                0x568C00
#define CListWnd__CalculateFirstVisibleLine                0x566070
#define CListWnd__CalculateVSBRange                        0x567C00
#define CListWnd__ClearAllSel                              0x5657D0
#define CListWnd__CloseAndUpdateEditWindow                 0x566670
#define CListWnd__Compare                                  0x5669B0
#define CListWnd__Draw                                     0x567860
#define CListWnd__DrawColumnSeparators                     0x5676B0
#define CListWnd__DrawHeader                               0x5659F0
#define CListWnd__DrawItem                                 0x5670C0
#define CListWnd__DrawLine                                 0x567420
#define CListWnd__DrawSeparator                            0x567780
#define CListWnd__EnsureVisible                            0x5660C0
#define CListWnd__ExtendSel                                0x566FF0
#define CListWnd__GetColumnFlags                           0x5652A0
#define CListWnd__GetColumnJustification                   0x565440
#define CListWnd__GetColumnMinWidth                        0x5653D0
#define CListWnd__GetColumnWidth                           0x565300
#define CListWnd__GetCurSel                                0x5650E0
#define CListWnd__GetHeaderRect                            0x564F20
#define CListWnd__GetItemAtPoint                           0x566370
#define CListWnd__GetItemAtPoint1                          0x5663E0
#define CListWnd__GetItemData                              0x565120
#define CListWnd__GetItemHeight                            0x565DF0
#define CListWnd__GetItemIcon                              0x5651E0
#define CListWnd__GetItemRect                              0x566190
#define CListWnd__GetItemText                              0x565160
#define CListWnd__GetSelList                               0x568DA0
#define CListWnd__GetSeparatorRect                         0x566900
#define CListWnd__IsLineEnabled                            0x5658C0
#define CListWnd__RemoveLine                               0x568D50
#define CListWnd__SetColors                                0x564E90
#define CListWnd__SetColumnWidth                           0x565380
#define CListWnd__SetColumnJustification                   0x5654A0
#define CListWnd__SetCurSel                                0x5656F0
#define CListWnd__SetItemColor                             0x5686C0
#define CListWnd__SetItemData                              0x565880
#define CListWnd__SetItemText                              0x568600
#define CListWnd__ShiftColumnSeparator                     0x566F60
#define CListWnd__Sort                                     0x569410
#define CListWnd__ToggleSel                                0x565710

// CEditWnd 
#define CEditWnd__DrawCaret                                0x57AA90
#define CEditWnd__GetCharIndexPt                           0x57B8E0
#define CEditWnd__GetDisplayString                         0x57ABF0
#define CEditWnd__GetHorzOffset                            0x57AE60
#define CEditWnd__GetLineForPrintableChar                  0x57B380
#define CEditWnd__GetSelStartPt                            0x57BB20
#define CEditWnd__GetSTMLSafeText                          0x57B040
#define CEditWnd__PointFromPrintableChar                   0x57B490
#define CEditWnd__SelectableCharFromPoint                  0x57B610
#define CEditWnd__SetEditable                              0x57B010

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                            0x4DBBDA
#define CGaugeWnd__CalcLinesFillRect                       0x4DBC36
#define CGaugeWnd__Draw                                    0x4DBF36

// CStmlWnd 
#define CStmlWnd__AppendSTML                               0x5643A0
#define CStmlWnd__CalculateHSBRange                        0x55BCB0
#define CStmlWnd__CalculateVSBRange                        0x55BC50
#define CStmlWnd__CanBreakAtCharacter                      0x55BDF0
#define CStmlWnd__CanGoBackward                            0x55BE70
#define CStmlWnd__FastForwardToEndOfTag                    0x55CBC0
#define CStmlWnd__GetNextChar                              0x55C2D0
#define CStmlWnd__GetNextTagPiece                          0x55C9C0
#define CStmlWnd__GetSTMLText                              0x4CF36F
#define CStmlWnd__GetThisChar                              0x55BB10
#define CStmlWnd__GetVisiableText                          0x55E390
#define CStmlWnd__InitializeWindowVariables                0x560190
#define CStmlWnd__MakeStmlColorTag                         0x55B2C0
#define CStmlWnd__MakeWndNotificationTag                   0x55B360
#define CStmlWnd__StripFirstSTMLLines                      0x564120
#define CStmlWnd__UpdateHistoryString                      0x55E7D0

// CTabWnd 
#define CTabWnd__Draw                                      0x579CE0
#define CTabWnd__DrawCurrentPage                           0x5797D0
#define CTabWnd__DrawTab                                   0x579550
#define CTabWnd__GetCurrentPage                            0x579100
#define CTabWnd__GetCurrentTabIndex                        0x578E50
#define CTabWnd__GetNumTabs                                0x578F50
#define CTabWnd__GetPageClientRect                         0x578E60
#define CTabWnd__GetPageFromTabIndex                       0x578F80
#define CTabWnd__GetPageInnerRect                          0x578EC0
#define CTabWnd__GetTabInnerRect                           0x579210
#define CTabWnd__GetTabRect                                0x579110
#define CTabWnd__IndexInBounds                             0x578F60
#define CTabWnd__InsertPage                                0x579BD0
#define CTabWnd__SetPage                                   0x5792B0
#define CTabWnd__SetPageRect                               0x5793C0
#define CTabWnd__UpdatePage                                0x579470

// CTextOverlay 
#define CTextOverlay__DisplayText                          0x40159A

/* 
CListWnd__GetCurCol 

CContextMenu__CContextMenu 
CContextMenu__AddMenuItem 
CContextMenu__AddSeparator 
CContextMenu__RemoveAllMenuItems 
CContextMenu__Activate 
/**/ 
