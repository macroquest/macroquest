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
#define __ExpectedVersionDate                         "Jul 15 2004" 
#define __ExpectedVersionTime                         "18:01:16" 
#define __ActualVersionDate                                0x5EFB64 
#define __ActualVersionTime                                0x5EFB70 

#define __ClientOverride                       0 
#define __MacroQuestWinClassName                 "__MacroQuestTray" 
#define __MacroQuestWinName                           "MacroQuest" 

// Memory Protection 
#define __MemChecker0                                      0x4C0985 
#define __MemChecker1                                      0x4C5CD5 
#define __MemChecker2                                      0x4C7B1E 
#define __MemChecker3                                      0x4C7BBB 
#define __EncryptPad0                                      0x7182E8 
#define __EncryptPad1                                      0x7186E8 
#define __EncryptPad2                                      0x7191C0 
#define __EncryptPad3                                      0x7195C0 

#define DI8__Main                                          0x89E734 
#define DI8__Keyboard                                      0x89E738 
#define DI8__Mouse                                         0x89E73C 

#define __LastTell                                         0x7DEEE0 
#define __Guilds                                           0x83F5A0 
#define __Mouse                                            0x89E740 
#define __Attack                                           0x83D714 
#define __InChatMode                                       0x7DCE10 
#define __gWorld                                           0x83F4F8 
#define __GroupCount                                       0x83DAA8 
#define __CommandList                                      0x712108 
#define __DoAbilityList                                    0x8169B4 
#define __DoAbilityAvailable                               0x7DDBFC 
#define __ServerHost                                       0x83D964 
#define __ServerName                                       0x816974 
#define __HWnd                                             0x7DCDD0 
#define __Clicks                                           0x7DCED0 
#define __ScreenX                                          0x7DCDD8 
#define __ScreenY                                          0x7DCDDC 
#define __ScreenMode                                       0x728D38 
#define __MouseLook                                        0x7DCEA2 
#define __EQP_IDArray                                      0x7D9EB8 
#define __CurrentMapLabel                                  0x8A7618 
#define __BindList                                         0x711BB8 
#define __RangeAttackReady                                 0x7DDC60 
#define __AltTimerReady                                    0x7DDC62 
#define __Socials                                          0x816A74 
#define __HotkeyPage                                       0x83D314 
#define __CurrentSocial                                    0x61EFB4 
#define __GroupLeader                                      0x83DC04 
#define __SkillDict                                        0x72A1D8 
#define __DrawHandler                                      0x8B3334 
#define __FriendsList                                      0x813774 
#define __IgnoreList                                       0x815074 
#define __NetStatusToggle                                  0x7DCEA4 
#define __ShowNames                                        0x7DDE44 
#define __PCNames                                          0x7DDEF4 
//// 
//Section 1: Vital Offsets 
//// 
#define pinstCSidlManager                                  0x8B2A64 
#define pinstCDisplay                                      0x83F584 
#define pinstCEverQuest                                    0x89E8A8 
#define pinstPCData                                        0x83F560 
#define pinstCharData                                      0x83F560 
#define pinstCharSpawn                                     0x83F558 
#define pinstSpawnList                                     0x83F520 
#define pinstLocalPlayer                                   0x83F544 
#define pinstControlledPlayer                              0x83F558 
#define pinstWorldData                                     0x83F51C 
#define pinstSpellManager                                  0x89B2E4 
#define pinstTradeTarget                                   0x83F540 
#define pinstActiveMerchant                                0x83F570 
#define pinstActiveBanker                                  0x83F574 
#define pinstActiveCorpse                                  0x83F578 
#define pinstActiveGMaster                                 0x83F57C 
#define pinstSelectedItem                                  0x8A7524 
#define pinstGroup                                         0x83DBF0 
#define pinstTarget                                        0x83F564 
#define pinstSwitchManager                                 0x7DCDC0 
#define pinstEQItemList                                    0x83F524 
#define pinstSpellSets                                     0x83D318 
#define instEQZoneInfo                                     0x7DD03C 
#define pinstCXWndManager                                  0x8B2A5C 
#define instKeypressHandler                                0x88D9A0 
#define pinstStringTable                                   0x83F510 
#define pinstAltAdvManager                                 0x729DF0 
#define instCRaid                                          0x847870 

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                  0x721D24 
#define pinstCharacterSelect                               0x7297CC 
#define pinstCFacePick                                     0x7297D0 
// removed 4-14 exe #define pinstCTextMessageWnd                                
#define pinstCNoteWnd                                      0x7297D4 
#define pinstCHelpWnd                                      0x7297D8 
#define pinstCBookWnd                                      0x7297DC 
#define pinstCPetInfoWnd                                   0x7297E0 
#define pinstCTrainWnd                                     0x7297E4 
#define pinstCSkillsWnd                                    0x7297E8 
#define pinstCSkillsSelectWnd                              0x7297EC 
#define pinstCCombatSkillSelectWnd                         0x7297F0 
#define pinstCFriendsWnd                                   0x7297F4 
#define pinstCAAWnd                                        0x7297F8 
#define pinstCGroupSearchFiltersWnd                        0x7297FC 
#define pinstCLoadskinWnd                                  0x729800 
#define pinstCAlarmWnd                                     0x729804 
#define pinstCMusicPlayerWnd                               0x729808 
#define pinstCRaidWnd                                      0x729814 
#define pinstCRaidOptionsWnd                               0x729818 
#define pinstCBreathWnd                                    0x72981C 
#define pinstCMapViewWnd                                   0x729820 
#define pinstCMapToolbarWnd                                0x729824 
#define pinstCEditLabelWnd                                 0x729828 
#define pinstCTargetWnd                                    0x72982C 
#define pinstCHotButtonWnd                                 0x729830 
#define pinstCColorPickerWnd                               0x729834 
#define pinstCPlayerWnd                                    0x729838 
#define pinstCOptionsWnd                                   0x72983C 
#define pinstCBuffWindowNORMAL                             0x729840 
#define pinstCBuffWindowSHORT                              0x729844 
#define pinstCharacterCreation                             0x729848 
#define pinstCCursorAttachment                             0x72984C 
#define pinstCCastingWnd                                   0x729850 
#define pinstCCastSpellWnd                                 0x729854 
#define pinstCSpellBookWnd                                 0x729858 
#define pinstCInventoryWnd                                 0x72985C 
#define pinstCBankWnd                                      0x729860 
#define pinstCQuantityWnd                                  0x729864 
#define pinstCLootWnd                                      0x729868 
#define pinstCActionsWnd                                   0x72986C 
#define pinstCCombatAbilityWnd                             0x729870 
#define pinstCMerchantWnd                                  0x729874 
#define pinstCTradeWnd                                     0x729878 
#define pinstCSelectorWnd                                  0x72987C 
#define pinstCBazaarWnd                                    0x729880 
#define pinstCBazaarSearchWnd                              0x729884 
#define pinstCGiveWnd                                      0x729888 
#define pinstCTrackingWnd                                  0x72988C 
#define pinstCInspectWnd                                   0x729890 
#define pinstCSocialEditWnd                                0x729894 
#define pinstCFeedbackWnd                                  0x729898 
#define pinstCBugReportWnd                                 0x72989C 
#define pinstCVideoModesWnd                                0x7298A0 
#define pinstCTextEntryWnd                                 0x7298A4 
#define pinstCFileSelectionWnd                             0x7298A8 
#define pinstCCompassWnd                                   0x7298AC 
#define pinstCPlayerNotesWnd                               0x7298B0 
#define pinstCGemsGameWnd                                  0x7298B4 
#define pinstCTimeLeftWnd                                  0x7298B8 
#define pinstCPetitionQWnd                                 0x7298BC 
#define pinstCSoulmarkWnd                                  0x7298C0 
#define pinstCStoryWnd                                     0x7298C4 
#define pinstCJournalTextWnd                               0x7298C8 
#define pinstCJournalCatWnd                                0x7298CC 
#define pinstCBodyTintWnd                                  0x7298D0 
#define pinstCInvSlotMgr                                   0x7298D4 
#define pinstCContainerMgr                                 0x7298D8 
#define pinstCAdventureLeaderboardWnd                      0x8A6F88 
#define pinstCAdventureMerchantWnd                         0x8A6FA0 
#define pinstCAdventureRequestWnd                          0x8A6FB8 
#define pinstCAdventureStatsWnd                            0x8A6FD0 
#define pinstCChatManager                                  0x8A7270 
#define pinstCDynamicZoneWnd                               0x8A7328 
#define pinstCFindLocationWnd                              0x8A73B8 
#define pinstCGroupSearchWnd                               0x8A7434 
#define pinstCGroupWnd                                     0x8A744C 
#define pinstCGuildMgmtWnd                                 0x8A7464 
#define pinstCItemDisplayManager                           0x8A74F8 
#define pinstCLeadershipWnd                                0x8A758C 
#define pinstCPopupWndManager                              0x8A7704 
#define pinstCSystemInfoDialogBox                          0x8A7FFC 
#define pinstCTargetOfTargetWnd                            0x8A8014 
#define pinstCTipWndOFDAY                                  0x8A80C8 
#define pinstCTipWndCONTEXT                                0x8A80CC 
#define pinstCTradeskillWnd                                0x8A810C 
#define pinstCTributeBenefitWnd                            0x8A814C 
#define pinstCTributeMasterWnd                             0x8A8164 
#define pinstCContextMenuManager                           0x8B2A80 
// unknown window added 4-14 exe 0x79A234 


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define DrawNetStatus                                      0x4B4D74 
#define CrashDetected                                      0x4C781C 
#define __ProcessGameEvents                                0x4AB2E3 
#define __ConvertItemTags                                  0x4589DA 
#define __SendMessage                                      0x4BAB07 
#define __NewUIINI                                         0x52D5EC 
#define __ExecuteCmd                                       0x44B458 
#define __GetGaugeValueFromEQ                              0x52BAB3 
#define __get_melee_range                                  0x44FF18 
#define __CastRay                                          0x45E705 

// EQ_LoadingS 
#define EQ_LoadingS__WriteTextHD                           0x431119 


//// 
// Section 4: Function Offsets 
//// 
// CEverQuest 
#define CEverQuest__dsp_chat                               0x49AA7A 
#define CEverQuest__ClickedPlayer                          0x497A41 
#define CEverQuest__EnterZone                              0x49B7A5 
#define CEverQuest__GetBodyTypeDesc                        0x49176B 
#define CEverQuest__GetClassDesc                           0x4911ED 
#define CEverQuest__GetClassThreeLetterCode                0x491608 
#define CEverQuest__GetDeityDesc                           0x4931FE 
#define CEverQuest__GetRaceDesc                            0x491A70 
#define CEverQuest__GetTitleDesc                           0x493315 
#define CEverQuest__InterpretCmd                           0x4A7BAE 
#define CEverQuest__LeftClickedOnPlayer                    0x4A9EE7 
#define CEverQuest__RightClickedOnPlayer                   0x4A2899 
#define CEverQuest__SetGameState                           0x497BA8 
#define CEverQuest__DropHeldItemOnGround                   0x49A53B 

// StringTable 
#define StringTable__getString                             0x4BDC7C 

// AltAdvManager 
#define AltAdvManager__IsAbilityReady                      0x41B11E 

// CXWndManager 
#define CXWndManager__RemoveWnd                            0x57DA90 
#define CXWndManager__GetKeyboardFlags                     0x57D6B0 
#define CXWndManager__HandleKeyboardMsg                    0x57DB80 
#define CXWndManager__DrawWindows                          0x57E8F0 
#define CXWndManager__DrawCursor                           0x57ECA0 
#define CXWndManager__GetFirstChildWnd                     0x57E270 

// KeyPressHandler 
#define KeypressHandler__HandleKeyDown                     0x4AFF79 
#define KeypressHandler__HandleKeyUp                       0x4B021D 
#define KeypressHandler__AttachKeyToEqCommand              0x4B1689 
#define KeypressHandler__AttachAltKeyToEqCommand           0x4B16C6 
#define KeypressHandler__SaveKeymapping                    0x4B1571 
#define KeypressHandler__ClearCommandStateArray            0x4B020C 

// EQ_Character 
#define EQ_Character__Max_Endurance                        0x41BCC7 
#define EQ_Character__Max_Mana                             0x41BD50 
#define EQ_Character__Max_HP                               0x41BB18 
#define EQ_Character__Cur_HP                               0x41FCEB 
#define EQ_Character__GetFocusCastingTimeModifier          0x426F35 
#define EQ_Character__GetAACastingTimeModifier             0x427336 
#define EQ_Character__CastSpell                            0x42AFFA 
#define EQ_Character__GetAbility                           0x429432 

// EQPlayer 
#define EQPlayer__EQPlayer                                 0x485DC6 
#define EQPlayer__dEQPlayer                                0x48566A 
#define EQPlayer__DoAttack                                 0x481B82 
#define EQPlayer__ChangeBoneStringSprite                   0x463AF0 
#define EQPlayer__SetNameSpriteState                       0x47FFFC 
#define EQPlayer__SetNameSpriteTint                        0x463B5C 

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                       0x401254 
#define CXStr__CXStr1                                      0x5171F3 
#define CXStr__CXStr3                                      0x5AFC70 
#define CXStr__dCXStr                                      0x4D345D 
#define CXStr__operator_plus_equal1                        0x5B0D30 
#define CXStr__operator_equal1                             0x5AFE30 

// CChatWindow 
#define CChatWindow__CChatWindow                           0x4E59CA 

// CChatManager 
#define CChatManager__GetRGBAFromIndex                     0x4E246D 
#define CChatManager__InitContextMenu                      0x4E2DD1 

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                           0x503A19 
#define CInvSlotMgr__MoveItem                              0x5033C8 

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                           0x506A9D 
#define CItemDisplayWnd__SetSpell                          0x505D9B 

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                         0x500159 

// CLabel 
#define CLabel__Draw                                       0x50CA2C 

// CGauge 
#define CGaugeWnd__Draw                                    0x4F2532 

// CDisplay 
#define CDisplay__ReloadUI                                 0x419A04 
#define CDisplay__CleanGameUI                              0x412802 
#define CDisplay__GetClickedActor                          0x40F9CC 
#define CDisplay__WriteTextHD2                             0x41331A 
#define CDisplay__GetWorldFilePath                         0x40E5A4 
#define CDisplay__GetUserDefinedColor                      0x40EDA0 

#define CTextureFont__DrawWrappedText                      0x56DE10 

// EQ_Item 
#define EQ_Item__GetItemLinkHash                           0x4305D9 
#define EQ_Item__CanDrop                                   0x4309C4 

// CBankWnd 
#define CBankWnd__GetNumBankSlots                          0x4D3549 

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                  0x4D6090 

// CMerchantWnd 
#define CMerchantWnd__SelectBuySellSlot                    0x515B5A 
#define CMerchantWnd__RequestBuyItem                       0x514D4C 
#define CMerchantWnd__RequestSellItem                      0x5150CA 
#define CMerchantWnd__DisplayBuyOrSellPrice                0x514B81 

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                         0x52A4B7 

// MapViewMap 
#define MapViewMap__SaveEx                                 0x5103A0 
#define MapViewMap__Clear                                  0x51022F 


// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                           0x513C64 

// EQItemList 
#define EQItemList__EQItemList                             0x44DD87 
#define EQItemList__dEQItemList                            0x44DE03 

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                      0x433926 

// CContainerWnd 
#define CContainerWnd__HandleCombine                       0x4EA73D 
#define CContainerWnd__vftable                             0x5F3FC8 

// CSidlScreenWnd 
#define CSidlScreenWnd__CSidlScreenWnd1                    0x5617B0 
#define CSidlScreenWnd__dCSidlScreenWnd                    0x560E50 
#define CSidlScreenWnd__CreateChildrenFromSidl             0x5601C0 
#define CSidlScreenWnd__WndNotification                    0x55FD40 
#define CSidlScreenWnd__CalculateHSBRange                  0x55F360 
#define CSidlScreenWnd__CalculateVSBRange                  0x55F2A0 
#define CSidlScreenWnd__ConvertToRes                       0x55FA50 
#define CSidlScreenWnd__CSidlScreenWnd2                    0x5618A0 
#define CSidlScreenWnd__DrawSidlPiece                      0x55FDE0 
#define CSidlScreenWnd__EnableIniStorage                   0x55FA00 
#define CSidlScreenWnd__GetSidlPiece                       0x560080 
#define CSidlScreenWnd__Init1                              0x561500 
#define CSidlScreenWnd__LoadIniInfo                        0x560270 
#define CSidlScreenWnd__LoadIniListWnd                     0x560BB0 
#define CSidlScreenWnd__LoadSidlScreen                     0x55FC20 
#define CSidlScreenWnd__SetScreen                          0x560F70 
#define CSidlScreenWnd__StoreIniInfo                       0x55F590 

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1             0x5860A0 

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                        0x592FC0 

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                       0x56D730 

// CXRect 
#define CXRect__CenterPoint                                0x4D3550 

// CXWnd 
#define CXWnd__BringToTop                                  0x561F60 
#define CXWnd__Center                                      0x5655D0 
#define CXWnd__ClrFocus                                    0x561CA0 
#define CXWnd__DoAllDrawing                                0x5661E0 
#define CXWnd__DrawChildren                                0x566310 
#define CXWnd__DrawColoredRect                             0x562190 
#define CXWnd__DrawTooltipAtPoint                          0x565400 
#define CXWnd__GetBorderFrame                              0x5625E0 
#define CXWnd__GetChildWndAt                               0x564F90 
#define CXWnd__GetClientClipRect                           0x562520 
#define CXWnd__GetFirstChildWnd                            0x561FF0 
#define CXWnd__GetNextChildWnd                             0x564F70 
#define CXWnd__GetNextSib                                  0x562010 
#define CXWnd__GetScreenClipRect                           0x565860 
#define CXWnd__GetScreenRect                               0x5627B0 
#define CXWnd__GetTooltipRect                              0x565350 
#define CXWnd__GetWindowTextA                              0x4CD29A 
#define CXWnd__GetXMLTooltip                               0x561AE0 
#define CXWnd__IsActive                                    0x562590 
#define CXWnd__IsDescendantOf                              0x5625A0 
#define CXWnd__IsReallyVisible                             0x564F50 
#define CXWnd__IsType                                      0x566180 
#define CXWnd__Move                                        0x564B00 
#define CXWnd__Move1                                       0x564B90 
#define CXWnd__ProcessTransition                           0x561F20 
#define CXWnd__Refade                                      0x561D50 
#define CXWnd__Resize                                      0x5659A0 
#define CXWnd__Right                                       0x565740 
#define CXWnd__SetFirstChildPointer                        0x562A00 
#define CXWnd__SetFocus                                    0x563CE0 
#define CXWnd__SetKeyTooltip                               0x562A40 
#define CXWnd__SetMouseOver                                0x562A20 
#define CXWnd__SetNextSibPointer                           0x562A10 
#define CXWnd__StartFade                                   0x561F80 

// CSliderWnd 
#define CSliderWnd__GetValue                               0x591970 
#define CSliderWnd__SetValue                               0x591B40 
#define CSliderWnd__UpdateThumb                            0x591930 

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                          0x4D308F 
#define CEditBaseWnd__SetSel                               0x588050 

// CComboWnd 
#define CComboWnd__DeleteAll                               0x58D060 
#define CComboWnd__Draw                                    0x58D260 
#define CComboWnd__GetButtonRect                           0x58D090 
#define CComboWnd__GetCurChoice                            0x58D020 
#define CComboWnd__GetListRect                             0x58D650 
#define CComboWnd__GetTextRect                             0x58D0F0 
#define CComboWnd__InsertChoice                            0x58D6B0 
#define CComboWnd__SetColors                               0x58CFF0 
#define CComboWnd__SetChoice                               0x58D790 

// CListWnd 
#define CListWnd__AddColumn                                0x57C3B0 
#define CListWnd__AddColumn1                               0x57BF10 
#define CListWnd__AddLine                                  0x57BAD0 
#define CListWnd__AddString                                0x57BC50 
#define CListWnd__CalculateFirstVisibleLine                0x579100 
#define CListWnd__CalculateVSBRange                        0x57AC70 
#define CListWnd__ClearAllSel                              0x578930 
#define CListWnd__CloseAndUpdateEditWindow                 0x579700 
#define CListWnd__Compare                                  0x579A40 
#define CListWnd__Draw                                     0x57A8D0 
#define CListWnd__DrawColumnSeparators                     0x57A730 
#define CListWnd__DrawHeader                               0x578B50 
#define CListWnd__DrawItem                                 0x57A150 
#define CListWnd__DrawLine                                 0x57A4A0 
#define CListWnd__DrawSeparator                            0x57A800 
#define CListWnd__EnsureVisible                            0x579150 
#define CListWnd__ExtendSel                                0x57A080 
#define CListWnd__GetColumnFlags                           0x578400 
#define CListWnd__GetColumnJustification                   0x5785A0 
#define CListWnd__GetColumnMinWidth                        0x578530 
#define CListWnd__GetColumnWidth                           0x578460 
#define CListWnd__GetCurSel                                0x578240 
#define CListWnd__GetHeaderRect                            0x578080 
#define CListWnd__GetItemAtPoint                           0x579400 
#define CListWnd__GetItemAtPoint1                          0x579470 
#define CListWnd__GetItemData                              0x578280 
#define CListWnd__GetItemHeight                            0x578F30 
#define CListWnd__GetItemIcon                              0x578340 
#define CListWnd__GetItemRect                              0x579220 
#define CListWnd__GetItemText                              0x5782C0 
#define CListWnd__GetSelList                               0x57BDF0 
#define CListWnd__GetSeparatorRect                         0x579990 
#define CListWnd__IsLineEnabled                            0x578A20 
#define CListWnd__RemoveLine                               0x57BDA0 
#define CListWnd__SetColors                                0x577FF0 
#define CListWnd__SetColumnWidth                           0x5784E0 
#define CListWnd__SetColumnJustification                   0x578600 
#define CListWnd__SetCurSel                                0x578850 
#define CListWnd__SetItemColor                             0x57B710 
#define CListWnd__SetItemData                              0x5789E0 
#define CListWnd__SetItemText                              0x57B650 
#define CListWnd__ShiftColumnSeparator                     0x579FF0 
#define CListWnd__Sort                                     0x57C450 
#define CListWnd__ToggleSel                                0x578870 

// CEditWnd 
#define CEditWnd__DrawCaret                                0x58DAF0 
#define CEditWnd__GetCharIndexPt                           0x58E910 
#define CEditWnd__GetDisplayString                         0x58DC20 
#define CEditWnd__GetHorzOffset                            0x58DE90 
#define CEditWnd__GetLineForPrintableChar                  0x58E3B0 
#define CEditWnd__GetSelStartPt                            0x58EB50 
#define CEditWnd__GetSTMLSafeText                          0x58E070 
#define CEditWnd__PointFromPrintableChar                   0x58E4C0 
#define CEditWnd__SelectableCharFromPoint                  0x58E640 
#define CEditWnd__SetEditable                              0x58E040 

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                            0x4F21D6 
#define CGaugeWnd__CalcLinesFillRect                       0x4F2232 
#define CGaugeWnd__Draw                                    0x4F2532 

// CStmlWnd 
#define CStmlWnd__AppendSTML                               0x577500 
#define CStmlWnd__CalculateHSBRange                        0x56EE30 
#define CStmlWnd__CalculateVSBRange                        0x56EDD0 
#define CStmlWnd__CanBreakAtCharacter                      0x56EF70 
#define CStmlWnd__CanGoBackward                            0x56EFF0 
#define CStmlWnd__FastForwardToEndOfTag                    0x56FD20 
#define CStmlWnd__GetNextChar                              0x56F430 
#define CStmlWnd__GetNextTagPiece                          0x56FB20 
#define CStmlWnd__GetSTMLText                              0x4E59AC 
#define CStmlWnd__GetThisChar                              0x56EC90 
#define CStmlWnd__GetVisiableText                          0x5714F0 
#define CStmlWnd__InitializeWindowVariables                0x5732F0 
#define CStmlWnd__MakeStmlColorTag                         0x56E440 
#define CStmlWnd__MakeWndNotificationTag                   0x56E4E0 
#define CStmlWnd__StripFirstSTMLLines                      0x577280 
#define CStmlWnd__UpdateHistoryString                      0x571930 

// CTabWnd 
#define CTabWnd__Draw                                      0x58CD40 
#define CTabWnd__DrawCurrentPage                           0x58C830 
#define CTabWnd__DrawTab                                   0x58C5B0 
#define CTabWnd__GetCurrentPage                            0x58C160 
#define CTabWnd__GetCurrentTabIndex                        0x58BE90 
#define CTabWnd__GetNumTabs                                0x58BFB0 
#define CTabWnd__GetPageClientRect                         0x58BEA0 
#define CTabWnd__GetPageFromTabIndex                       0x58BFE0 
#define CTabWnd__GetPageInnerRect                          0x58BF00 
#define CTabWnd__GetTabInnerRect                           0x58C270 
#define CTabWnd__GetTabRect                                0x58C170 
#define CTabWnd__IndexInBounds                             0x58BFC0 
#define CTabWnd__InsertPage                                0x58CC30 
#define CTabWnd__SetPage                                   0x58C310 
#define CTabWnd__SetPageRect                               0x58C420 
#define CTabWnd__UpdatePage                                0x58C4D0 

// CTextOverlay 
#define CTextOverlay__DisplayText                          0x401586 

/* 
CListWnd__GetCurCol 

CContextMenu__CContextMenu 
CContextMenu__AddMenuItem 
CContextMenu__AddSeparator 
CContextMenu__RemoveAllMenuItems 
CContextMenu__Activate 
/**/ 
