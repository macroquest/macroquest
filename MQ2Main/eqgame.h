/* 
***************************************************************************** 
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

#define __ClientName									   "eqgame" 
#define __ExpectedVersionDate							   "Dec 16 2004" 
#define __ExpectedVersionTime							   "17:15:50" 
#define __ActualVersionDate                                0x5FFB74 
#define __ActualVersionTime                                0x5FFB80 

#define __ClientOverride								   0 
#define __MacroQuestWinClassName					       "__MacroQuestTray" 
#define __MacroQuestWinName								   "MacroQuest" 

// Memory Protection 
#define __MemChecker0                                      0x4F5797 
#define __MemChecker1                                      0x52D8AD 
#define __MemChecker2                                      0x5317A4 
#define __MemChecker3                                      0x531831 
#define __MemChecker4                                      0x5B7650 
#define __EncryptPad0                                      0x71EFC0 
#define __EncryptPad1                                      0x721A28 
#define __EncryptPad2                                      0x722530 
#define __EncryptPad3                                      0x722930 
#define __EncryptPad4                                      0x728030 

#define DI8__Main                                          0x8BB5C4 
#define DI8__Keyboard                                      0x8BB5C8 
#define DI8__Mouse                                         0x8BB5CC 

#define __LastTell                                         0x7F1968 
#define __Guilds                                           0x857FB8 
#define __Mouse                                            0x8BB5D0 
#define __Attack                                           0x8501E4 
#define __InChatMode                                       0x7EF830 
#define __gWorld                                           0x851FC8 
#define __GroupCount                                       0x850578 
#define __CommandList                                      0x6272F8 
#define __DoAbilityList                                    0x82943C 
#define __DoAbilityAvailable                               0x7F067C 
#define __ServerHost                                       0x850434 
#define __ServerName                                       0x8293FC 
#define __HWnd                                             0x7EF7F0 
#define __Clicks                                           0x7EF8F4 
#define __ScreenX                                          0x7EF7F8 
#define __ScreenY                                          0x7EF7FC 
#define __ScreenMode                                       0x73B6A0 
#define __MouseLook                                        0x7EF8C2 
#define __EQP_IDArray                                      0x73DAD8 
#define __CurrentMapLabel                                  0x8A09A4 
#define __BindList                                         0x626D68 
#define __RangeAttackReady                                 0x7F06E0 
#define __AltTimerReady                                    0x7F06E2 
#define __Socials                                          0x8294FC 
#define __HotkeyPage                                       0x84FD9C 
#define __CurrentSocial                                    0x62A640 
#define __GroupLeader                                      0x8506D4 
#define __SkillDict                                        0x740E38 
#define __DrawHandler                                      0x8C543C 
#define __FriendsList                                      0x8261FC 
#define __IgnoreList                                       0x827AFC 
#define __NetStatusToggle                                  0x7EF8C4 
#define __ShowNames                                        0x7F08C4 
#define __PCNames                                          0x7F0974 
//// 
//Section 1: Vital Offsets 
//// 
#define pinstCSidlManager                                  0x8C4A3C 
#define pinstCDisplay                                      0x852054 
#define pinstCEverQuest                                    0x8BB738 
#define pinstPCData                                        0x852030 
#define pinstCharData                                      0x852030 
#define pinstCharSpawn                                     0x852028 
#define pinstSpawnList                                     0x851FF0 
#define pinstLocalPlayer                                   0x852014 
#define pinstControlledPlayer                              0x852028 
#define pinstWorldData                                     0x851FEC 
#define pinstSpellManager                                  0x8ADCBC 
#define pinstTradeTarget                                   0x852010 
#define pinstActiveMerchant                                0x852040 
#define pinstActiveBanker                                  0x852044 
#define pinstActiveCorpse                                  0x852048 
#define pinstActiveGMaster                                 0x85204C 
#define pinstSelectedItem                                  0x8A0614 
#define pinstGroup                                         0x8506C0 
#define pinstTarget                                        0x852034 
#define pinstSwitchManager                                 0x7409F8 
#define pinstEQItemList                                    0x851FF4 
#define pinstSpellSets                                     0x84FDA0 
#define instEQZoneInfo                                     0x7EFA60 
#define pinstCXWndManager                                  0x8C4A34 
#define instKeypressHandler                                0x8A0680 
#define pinstStringTable                                   0x851FE0 
#define pinstAltAdvManager                                 0x7409FC 
#define instCRaid                                          0x852060 

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                  0x729A74 
#define pinstCharacterSelect                               0x73C134 
#define pinstCFacePick                                     0x73C138 
// removed 4-14 exe #define pinstCTextMessageWnd                                
#define pinstCNoteWnd                                      0x73C13C 
#define pinstCHelpWnd                                      0x73C140 
#define pinstCBookWnd                                      0x73C144 
#define pinstCPetInfoWnd                                   0x73C148 
#define pinstCTrainWnd                                     0x73C14C 
#define pinstCSkillsWnd                                    0x73C150 
#define pinstCSkillsSelectWnd                              0x73C154 
#define pinstCCombatSkillSelectWnd                         0x73C158 
#define pinstCFriendsWnd                                   0x73C15C 
#define pinstCAAWnd                                        0x73C168 
#define pinstCGroupSearchFiltersWnd                        0x73C16C 
#define pinstCLoadskinWnd                                  0x73C170 
#define pinstCAlarmWnd                                     0x73C174 
#define pinstCMusicPlayerWnd                               0x73C178 
#define pinstCRaidWnd                                      0x73C184 
#define pinstCRaidOptionsWnd                               0x73C188 
#define pinstCBreathWnd                                    0x73C18C 
#define pinstCMapViewWnd                                   0x73C190 
#define pinstCMapToolbarWnd                                0x73C194 
#define pinstCEditLabelWnd                                 0x73C198 
#define pinstCTargetWnd                                    0x73C19C 
#define pinstCHotButtonWnd                                 0x73C1A0 
#define pinstCColorPickerWnd                               0x73C1A4 
#define pinstCPlayerWnd                                    0x73C1A8 
#define pinstCOptionsWnd                                   0x73C1AC 
#define pinstCBuffWindowNORMAL                             0x73C1B0 
#define pinstCBuffWindowSHORT                              0x73C1B4 
#define pinstCharacterCreation                             0x73C1B8 
#define pinstCCursorAttachment                             0x73C1BC 
#define pinstCCastingWnd                                   0x73C1C0 
#define pinstCCastSpellWnd                                 0x73C1C4 
#define pinstCSpellBookWnd                                 0x73C1C8 
#define pinstCInventoryWnd                                 0x73C1CC 
#define pinstCBankWnd                                      0x73C1D0 
#define pinstCQuantityWnd                                  0x73C1D4 
#define pinstCLootWnd                                      0x73C1D8 
#define pinstCActionsWnd                                   0x73C1DC 
#define pinstCCombatAbilityWnd                             0x73C1E0 
#define pinstCMerchantWnd                                  0x73C1E4 
#define pinstCTradeWnd                                     0x73C1E8 
#define pinstCSelectorWnd                                  0x73C1EC 
#define pinstCBazaarWnd                                    0x73C1F0 
#define pinstCBazaarSearchWnd                              0x73C1F4 
#define pinstCGiveWnd                                      0x73C1F8 
#define pinstCTrackingWnd                                  0x73C1FC 
#define pinstCInspectWnd                                   0x73C200 
#define pinstCSocialEditWnd                                0x73C204 
#define pinstCFeedbackWnd                                  0x73C208 
#define pinstCBugReportWnd                                 0x73C20C 
#define pinstCVideoModesWnd                                0x73C210 
#define pinstCTextEntryWnd                                 0x73C218 
#define pinstCFileSelectionWnd                             0x73C21C 
#define pinstCCompassWnd                                   0x73C220 
#define pinstCPlayerNotesWnd                               0x73C224 
#define pinstCGemsGameWnd                                  0x73C228 
#define pinstCTimeLeftWnd                                  0x73C22C 
#define pinstCPetitionQWnd                                 0x73C230 
#define pinstCSoulmarkWnd                                  0x73C234 
#define pinstCStoryWnd                                     0x73C238 
#define pinstCJournalTextWnd                               0x73C23C 
#define pinstCJournalCatWnd                                0x73C240 
#define pinstCBodyTintWnd                                  0x73C244 
#define pinstCInvSlotMgr                                   0x73C248 
#define pinstCContainerMgr                                 0x73C24C 
#define pinstCAdventureLeaderboardWnd                      0x7297A0 
#define pinstCAdventureMerchantWnd                         0x7297B8 
#define pinstCAdventureRequestWnd                          0x7297D0 
#define pinstCAdventureStatsWnd                            0x7297E8 
#define pinstCChatManager                                  0x729B8C 
#define pinstCDynamicZoneWnd                               0x73C350 
#define pinstCFindLocationWnd                              0x8A0490 
#define pinstCGroupSearchWnd                               0x8A0550 
#define pinstCGroupWnd                                     0x8A0568 
#define pinstCGuildMgmtWnd                                 0x8A0580 
#define pinstCItemDisplayManager                           0x8A0640 
#define pinstCLeadershipWnd                                0x8A070C 
#define pinstCPopupWndManager                              0x8A1AB8 
#define pinstCSystemInfoDialogBox                          0x8AE45C 
#define pinstCTargetOfTargetWnd                            0x8AE47C 
#define pinstCTipWndOFDAY                                  0x8AE548 
#define pinstCTipWndCONTEXT                                0x8AE54C 
#define pinstCTradeskillWnd                                0x8AE634 
#define pinstCTributeBenefitWnd                            0x8AE674 
#define pinstCTributeMasterWnd                             0x8AE68C 
#define pinstCContextMenuManager                           0x8C4A74 
// unknown window added 4-14 exe 0x79A234 


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define DrawNetStatus                                      0x4F9C85 
#define CrashDetected                                      0x531460 
#define __ProcessGameEvents                                0x4C0BD9 
#define __ConvertItemTags                                  0x46110D 
#define __SendMessage                                      0x5140A8 
#define __NewUIINI                                         0x51C35D 
#define __ExecuteCmd                                       0x455573 
#define __GetGaugeValueFromEQ                              0x51A978 
#define __get_melee_range                                  0x459BC0 
#define __CastRay                                          0x461CE6 
#define __LoadSplashScreen                           0x5BCDB0 

// EQ_LoadingS 
#define EQ_LoadingS__WriteTextHD                           0x49CA62 


//// 
// Section 4: Function Offsets 
//// 
// CEverQuest 
#define CEverQuest__dsp_chat                               0x4AF7D9 
#define CEverQuest__ClickedPlayer                          0x4AD502 
#define CEverQuest__EnterZone                              0x4BF960 
#define CEverQuest__GetBodyTypeDesc                        0x4A91DD 
#define CEverQuest__GetClassDesc                           0x4A8C5F 
#define CEverQuest__GetClassThreeLetterCode                0x4A907A 
#define CEverQuest__GetDeityDesc                           0x4AAC70 
#define CEverQuest__GetRaceDesc                            0x4A94E2 
#define CEverQuest__InterpretCmd                           0x4B9DE4 
#define CEverQuest__LeftClickedOnPlayer                    0x4BE37E 
#define CEverQuest__RightClickedOnPlayer                   0x4BE7B4 
#define CEverQuest__SetGameState                           0x4AD5E2 
#define CEverQuest__DropHeldItemOnGround                   0x4AF183 

// StringTable 
#define StringTable__getString                             0x5AEC70 

// AltAdvManager 
#define AltAdvManager__IsAbilityReady                      0x485CCB 
#define AltAdvManager__GetCalculatedTimer               0x485C9D 

// CXWndManager 
#define CXWndManager__RemoveWnd                            0x582530 
#define CXWndManager__GetKeyboardFlags                     0x582150 
#define CXWndManager__HandleKeyboardMsg                    0x582620 
#define CXWndManager__DrawWindows                          0x583410 
#define CXWndManager__DrawCursor                           0x5837C0 
#define CXWndManager__GetFirstChildWnd                     0x582D10 

// KeyPressHandler 
#define KeypressHandler__HandleKeyDown                     0x4E898F 
#define KeypressHandler__HandleKeyUp                       0x4E8C06 
#define KeypressHandler__AttachKeyToEqCommand              0x4E9CAE 
#define KeypressHandler__AttachAltKeyToEqCommand           0x4E9CE1 
#define KeypressHandler__SaveKeymapping                    0x4E9B7E 
#define KeypressHandler__ClearCommandStateArray            0x4E9AF7 

// EQ_Character 
#define EQ_Character__Max_Endurance                        0x486991 
#define EQ_Character__Max_HP                               0x48673E 
#define EQ_Character__Cur_HP                               0x48A3C6 
#define EQ_Character__GetFocusCastingTimeModifier          0x492134 
#define EQ_Character__GetAACastingTimeModifier             0x49264C 
#define EQ_Character__CastSpell                            0x495DAF 
#define EQ_Character__Max_Mana                             0x49F50A 

// EQPlayer 
#define EQPlayer__EQPlayer                                 0x47935F 
#define EQPlayer__dEQPlayer                                0x478BE4 
#define EQPlayer__DoAttack                                 0x4767C8 
#define EQPlayer__ChangeBoneStringSprite                   0x46EDE7 
#define EQPlayer__SetNameSpriteState                       0x4730ED 
#define EQPlayer__SetNameSpriteTint                        0x46EE53 

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                       0x401006 
#define CXStr__CXStr1                                      0x401000 
#define CXStr__CXStr3                                      0x535090 
#define CXStr__dCXStr                                      0x40A895 
#define CXStr__operator_plus_equal1                        0x536090 
#define CXStr__operator_equal1                             0x535250 

// CChatWindow 
#define CChatWindow__CChatWindow                           0x42388F 

// CChatManager 
#define CChatManager__GetRGBAFromIndex                     0x420848 
#define CChatManager__InitContextMenu                      0x42092C 

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                           0x4DDFA6 
#define CInvSlotMgr__MoveItem                              0x4DE3DE 

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                           0x4E2BAE 
#define CItemDisplayWnd__SetSpell                          0x4E1C0D 

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                         0x4DAC51 

// CLabel 
#define CLabel__Draw                                       0x4E9E78 

// CGauge 
#define CGaugeWnd__Draw                                    0x4CC564 

// CDisplay 
#define CDisplay__ReloadUI                                 0x44190E 
#define CDisplay__CleanGameUI                              0x43A134 
#define CDisplay__GetClickedActor                          0x436FD9 
#define CDisplay__WriteTextHD2                             0x43AD44 
#define CDisplay__GetWorldFilePath                         0x435CAB 
#define CDisplay__GetUserDefinedColor                      0x43649F 

#define CTextureFont__DrawWrappedText                      0x566150 

// EQ_Item 
#define EQ_Item__GetItemLinkHash                           0x49BFB7 
#define EQ_Item__CanDrop                                   0x49C3BE 

// CBankWnd 
#define CBankWnd__GetNumBankSlots                          0x40B4DD 

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                  0x40E838 

// CMerchantWnd 
#define CMerchantWnd__SelectBuySellSlot                    0x4F6830 
#define CMerchantWnd__RequestBuyItem                       0x4F6963 
#define CMerchantWnd__RequestSellItem                      0x4F6B83 
#define CMerchantWnd__DisplayBuyOrSellPrice                0x4F5C7A 

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                         0x518DBD 

// MapViewMap 
#define MapViewMap__SaveEx                                 0x4F24A5 
#define MapViewMap__Clear                                  0x4F1D13 


// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                           0x4F5006 
#define CButtonWnd__SetCheck                        0x580230 

// EQItemList 
#define EQItemList__EQItemList                             0x458002 
#define EQItemList__dEQItemList                            0x45807E 

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                      0x4A0559 

// CContainerWnd 
#define CContainerWnd__HandleCombine                       0x42B4EF 
#define CContainerWnd__vftable                             0x5E8B50 

// CSidlScreenWnd 
#define CSidlScreenWnd__CSidlScreenWnd1                    0x560F60 
#define CSidlScreenWnd__dCSidlScreenWnd                    0x5605B0 
#define CSidlScreenWnd__CreateChildrenFromSidl             0x55F860 
#define CSidlScreenWnd__WndNotification                    0x55F3E0 
#define CSidlScreenWnd__CalculateHSBRange                  0x55EA00 
#define CSidlScreenWnd__CalculateVSBRange                  0x55E940 
#define CSidlScreenWnd__ConvertToRes                       0x55F0F0 
#define CSidlScreenWnd__CSidlScreenWnd2                    0x561050 
#define CSidlScreenWnd__DrawSidlPiece                      0x55F480 
#define CSidlScreenWnd__EnableIniStorage                   0x55F0A0 
#define CSidlScreenWnd__GetSidlPiece                       0x55F720 
#define CSidlScreenWnd__Init1                              0x560CB0 
#define CSidlScreenWnd__LoadIniInfo                        0x55F910 
#define CSidlScreenWnd__LoadIniListWnd                     0x560250 
#define CSidlScreenWnd__LoadSidlScreen                     0x55F2C0 
#define CSidlScreenWnd__SetScreen                          0x5606D0 
#define CSidlScreenWnd__StoreIniInfo                       0x55EC30 

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1             0x58BA00 

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                        0x592820 

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                       0x57F070 

// CXRect 
#define CXRect__CenterPoint                                0x40AD40 

// CXWnd 
#define CXWnd__BringToTop                                  0x561710 
#define CXWnd__Center                                      0x564D80 
#define CXWnd__ClrFocus                                    0x561450 
#define CXWnd__DoAllDrawing                                0x565990 
#define CXWnd__DrawChildren                                0x565AC0 
#define CXWnd__DrawColoredRect                             0x561940 
#define CXWnd__DrawTooltipAtPoint                          0x564BB0 
#define CXWnd__GetBorderFrame                              0x561D90 
#define CXWnd__GetChildWndAt                               0x564740 
#define CXWnd__GetClientClipRect                           0x561CD0 
#define CXWnd__GetFirstChildWnd                            0x5617A0 
#define CXWnd__GetNextChildWnd                             0x564720 
#define CXWnd__GetNextSib                                  0x5617C0 
#define CXWnd__GetScreenClipRect                           0x565010 
#define CXWnd__GetScreenRect                               0x561F60 
#define CXWnd__GetTooltipRect                              0x564B00 
#define CXWnd__GetWindowTextA                              0x402A90 
// CHECK THIS ^^^^^^^^^^^^^^ 
#define CXWnd__GetXMLTooltip                               0x561290 
#define CXWnd__IsActive                                    0x561D40 
#define CXWnd__IsDescendantOf                              0x561D50 
#define CXWnd__IsReallyVisible                             0x564700 
#define CXWnd__IsType                                      0x565930 
#define CXWnd__Move                                        0x5642B0 
#define CXWnd__Move1                                       0x564340 
#define CXWnd__ProcessTransition                           0x5616D0 
#define CXWnd__Refade                                      0x561500 
#define CXWnd__Resize                                      0x565150 
#define CXWnd__Right                                       0x564EF0 
#define CXWnd__SetFirstChildPointer                        0x5621B0 
#define CXWnd__SetFocus                                    0x563490 
#define CXWnd__SetKeyTooltip                               0x5621F0 
#define CXWnd__SetMouseOver                                0x5621D0 
#define CXWnd__SetNextSibPointer                           0x5621C0 
#define CXWnd__StartFade                                   0x561730 

// CSliderWnd 
#define CSliderWnd__GetValue                               0x581910 
#define CSliderWnd__SetValue                               0x581AE0 
#define CSliderWnd__UpdateThumb                            0x5818D0 

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                          0x40A3AD 
#define CEditBaseWnd__SetSel                               0x591980 

// CComboWnd 
#define CComboWnd__DeleteAll                               0x580EA0 
#define CComboWnd__Draw                                    0x5810A0 
#define CComboWnd__GetButtonRect                           0x580ED0 
#define CComboWnd__GetCurChoice                            0x580E60 
#define CComboWnd__GetListRect                             0x581490 
#define CComboWnd__GetTextRect                             0x580F30 
#define CComboWnd__InsertChoice                            0x5814F0 
#define CComboWnd__SetColors                               0x580E30 
#define CComboWnd__SetChoice                               0x5815D0 

// CListWnd 
#define CListWnd__AddColumn                                0x56AB40 
#define CListWnd__AddColumn1                               0x56A6A0 
#define CListWnd__AddLine                                  0x56A260 
#define CListWnd__AddString                                0x56A3E0 
#define CListWnd__CalculateFirstVisibleLine                0x5677D0 
#define CListWnd__CalculateVSBRange                        0x569360 
#define CListWnd__ClearAllSel                              0x566F30 
#define CListWnd__CloseAndUpdateEditWindow                 0x567DD0 
#define CListWnd__Compare                                  0x568110 
#define CListWnd__Draw                                     0x568FC0 
#define CListWnd__DrawColumnSeparators                     0x568E10 
#define CListWnd__DrawHeader                               0x567150 
#define CListWnd__DrawItem                                 0x568820 
#define CListWnd__DrawLine                                 0x568B80 
#define CListWnd__DrawSeparator                            0x568EE0 
#define CListWnd__EnsureVisible                            0x567820 
#define CListWnd__ExtendSel                                0x568750 
#define CListWnd__GetColumnFlags                           0x566A00 
#define CListWnd__GetColumnJustification                   0x566BA0 
#define CListWnd__GetColumnMinWidth                        0x566B30 
#define CListWnd__GetColumnWidth                           0x566A60 
#define CListWnd__GetCurSel                                0x566840 
#define CListWnd__GetHeaderRect                            0x566680 
#define CListWnd__GetItemAtPoint                           0x567AD0 
#define CListWnd__GetItemAtPoint1                          0x567B40 
#define CListWnd__GetItemData                              0x566880 
#define CListWnd__GetItemHeight                            0x567550 
#define CListWnd__GetItemIcon                              0x566940 
#define CListWnd__GetItemRect                              0x5678F0 
#define CListWnd__GetItemText                              0x5668C0 
#define CListWnd__GetSelList                               0x56A580 
#define CListWnd__GetSeparatorRect                         0x568060 
#define CListWnd__IsLineEnabled                            0x567020 
#define CListWnd__RemoveLine                               0x56A530 
#define CListWnd__SetColors                                0x5665F0 
#define CListWnd__SetColumnWidth                           0x566AE0 
#define CListWnd__SetColumnJustification                   0x566C00 
#define CListWnd__SetCurSel                                0x566E50 
#define CListWnd__SetItemColor                             0x569EA0 
#define CListWnd__SetItemData                              0x566FE0 
#define CListWnd__SetItemText                              0x569DE0 
#define CListWnd__ShiftColumnSeparator                     0x5686C0 
#define CListWnd__Sort                                     0x56ABE0 
#define CListWnd__ToggleSel                                0x566E70 

// CEditWnd 
#define CEditWnd__DrawCaret                                0x58DA00 
#define CEditWnd__GetCharIndexPt                           0x58E850 
#define CEditWnd__GetDisplayString                         0x58DB60 
#define CEditWnd__GetHorzOffset                            0x58DDD0 
#define CEditWnd__GetLineForPrintableChar                  0x58E2F0 
#define CEditWnd__GetSelStartPt                            0x58EA90 
#define CEditWnd__GetSTMLSafeText                          0x58DFB0 
#define CEditWnd__PointFromPrintableChar                   0x58E400 
#define CEditWnd__SelectableCharFromPoint                  0x58E580 
#define CEditWnd__SetEditable                              0x58DF80 

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                            0x4CC208 
#define CGaugeWnd__CalcLinesFillRect                       0x4CC264 
#define CGaugeWnd__Draw                                    0x4CC564 

// CStmlWnd 
#define CStmlWnd__AppendSTML                               0x5740A0 
#define CStmlWnd__CalculateHSBRange                        0x56B9A0 
#define CStmlWnd__CalculateVSBRange                        0x56B940 
#define CStmlWnd__CanBreakAtCharacter                      0x56BAE0 
#define CStmlWnd__CanGoBackward                            0x56BB60 
#define CStmlWnd__FastForwardToEndOfTag                    0x56C850 
#define CStmlWnd__GetNextChar                              0x56BFA0 
#define CStmlWnd__GetNextTagPiece                          0x56C650 
#define CStmlWnd__GetSTMLText                              0x423871 
#define CStmlWnd__GetThisChar                              0x56B800 
#define CStmlWnd__GetVisiableText                          0x56E020 
#define CStmlWnd__InitializeWindowVariables                0x56FE20 
#define CStmlWnd__MakeStmlColorTag                         0x56AED0 
#define CStmlWnd__MakeWndNotificationTag                   0x56AF70 
#define CStmlWnd__StripFirstSTMLLines                      0x573E20 
#define CStmlWnd__UpdateHistoryString                      0x56E460 

// CTabWnd 
#define CTabWnd__Draw                                      0x577D40 
#define CTabWnd__DrawCurrentPage                           0x577830 
#define CTabWnd__DrawTab                                   0x5775B0 
#define CTabWnd__GetCurrentPage                            0x577160 
#define CTabWnd__GetCurrentTabIndex                        0x576F30 
#define CTabWnd__GetNumTabs                                0x577030 
#define CTabWnd__GetPageClientRect                         0x576F40 
#define CTabWnd__GetPageFromTabIndex                       0x577060 
#define CTabWnd__GetPageInnerRect                          0x576FA0 
#define CTabWnd__GetTabInnerRect                           0x577270 
#define CTabWnd__GetTabRect                                0x577170 
#define CTabWnd__IndexInBounds                             0x577040 
#define CTabWnd__InsertPage                                0x577C30 
#define CTabWnd__SetPage                                   0x577310 
#define CTabWnd__SetPageRect                               0x577420 
#define CTabWnd__UpdatePage                                0x5774D0 

// CTextOverlay 
#define CTextOverlay__DisplayText                          0x412D11 

/* 
CListWnd__GetCurCol 

CContextMenu__CContextMenu 
CContextMenu__AddMenuItem 
CContextMenu__AddSeparator 
CContextMenu__RemoveAllMenuItems 
CContextMenu__Activate 
/**/ 
