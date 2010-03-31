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


#define __ClientName                                       "eqgame" 
#define __ExpectedVersionDate							   "Aug  9 2004" 
#define __ExpectedVersionTime							   "18:37:35" 
#define __ActualVersionDate                                0x5D706C 
#define __ActualVersionTime                                0x5D7078 

#define __ClientOverride								   0 
#define __MacroQuestWinClassName						   "__MacroQuestTray" 
#define __MacroQuestWinName								   "MacroQuest" 

// Memory Protection 
#define __MemChecker0                                      0x4AA17A 
#define __MemChecker1                                      0x4AF75A 
#define __MemChecker2                                      0x4B15F2 
#define __MemChecker3                                      0x4B168F 
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
#define DrawNetStatus                                      0x49DEF9 
#define CrashDetected                                      0x4B21D4 
#define __ProcessGameEvents                                0x49492E 
#define __ConvertItemTags                                  0x457AE4 
#define __SendMessage                                      0x4A3AE2 
#define __NewUIINI                                         0x5193C7 
#define __ExecuteCmd                                       0x44C4C4 
#define __GetGaugeValueFromEQ                              0x5179FD 
#define __get_melee_range                                  0x450983 
#define __CastRay                                          0x45F842 

// EQ_LoadingS 
#define EQ_LoadingS__WriteTextHD                           0x431E5B 


//// 
// Section 4: Function Offsets 
//// 
// CEverQuest 
#define CEverQuest__dsp_chat                               0x483C8C 
#define CEverQuest__ClickedPlayer                          0x480E89 
#define CEverQuest__EnterZone                              0x48487D 
#define CEverQuest__GetBodyTypeDesc                        0x47AD3E 
#define CEverQuest__GetClassDesc                           0x47A7C0 
#define CEverQuest__GetClassThreeLetterCode                0x47ABDB 
#define CEverQuest__GetDeityDesc                           0x47C7D1 
#define CEverQuest__GetRaceDesc                            0x47B043 
#define CEverQuest__GetTitleDesc                           0x47C8E8 
#define CEverQuest__InterpretCmd                           0x491383 
#define CEverQuest__LeftClickedOnPlayer                    0x4935F3 
#define CEverQuest__RightClickedOnPlayer                   0x48BB96 
#define CEverQuest__SetGameState                           0x480F5C 
#define CEverQuest__DropHeldItemOnGround                   0x483636 

// StringTable 
#define StringTable__getString                             0x4A6CBC 

// AltAdvManager 
#define AltAdvManager__IsAbilityReady                      0x41BC30 

// CXWndManager 
#define CXWndManager__RemoveWnd                            0x56A990 
#define CXWndManager__GetKeyboardFlags                     0x56A5B0 
#define CXWndManager__HandleKeyboardMsg                    0x56AA80 
#define CXWndManager__DrawWindows                          0x56B870 
#define CXWndManager__DrawCursor                           0x56BC20 
#define CXWndManager__GetFirstChildWnd                     0x56B170 

// KeyPressHandler 
#define KeypressHandler__HandleKeyDown                     0x4990FE 
#define KeypressHandler__HandleKeyUp                       0x4993A2 
#define KeypressHandler__AttachKeyToEqCommand              0x49A80E 
#define KeypressHandler__AttachAltKeyToEqCommand           0x49A84B 
#define KeypressHandler__SaveKeymapping                    0x49A6F6 
#define KeypressHandler__ClearCommandStateArray            0x499391 

// EQ_Character 
#define EQ_Character__Max_Endurance                        0x41C8E6 
#define EQ_Character__Max_Mana                             0x41C96F 
#define EQ_Character__Max_HP                               0x41C693 
#define EQ_Character__Cur_HP                               0x4201D3 
#define EQ_Character__GetFocusCastingTimeModifier          0x427AEE 
#define EQ_Character__GetAACastingTimeModifier             0x427ECB 
#define EQ_Character__CastSpell                            0x42BD04 
#define EQ_Character__GetAbility                           0x429FB7 

// EQPlayer 
#define EQPlayer__EQPlayer                                 0x46EB0E 
#define EQPlayer__dEQPlayer                                0x46E3B2 
#define EQPlayer__DoAttack                                 0x46A91D 
#define EQPlayer__ChangeBoneStringSprite                   0x464AA2 
#define EQPlayer__SetNameSpriteState                       0x468D97 
#define EQPlayer__SetNameSpriteTint                        0x464B0E 

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                       0x4011B6 
#define CXStr__CXStr1                                      0x401CB3 
#define CXStr__CXStr3                                      0x59CC40 
#define CXStr__dCXStr                                      0x4011E0 
#define CXStr__operator_plus_equal1                        0x59DD00 
#define CXStr__operator_equal1                             0x59CE00 

// CChatWindow 
#define CChatWindow__CChatWindow                           0x4CF3C5 

// CChatManager 
#define CChatManager__GetRGBAFromIndex                     0x4CBE68 
#define CChatManager__InitContextMenu                      0x4CC7CC 

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                           0x4ECD9C 
#define CInvSlotMgr__MoveItem                              0x4ED1B8 

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                           0x4F0598 
#define CItemDisplayWnd__SetSpell                          0x4EF7EA 

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                         0x4E9ADD 

// CLabel 
#define CLabel__Draw                                       0x4F6411 

// CGauge 
#define CGaugeWnd__Draw                                    0x4DBF97 

// CDisplay 
#define CDisplay__ReloadUI                                 0x41A3D4 
#define CDisplay__CleanGameUI                              0x412C95 
#define CDisplay__GetClickedActor                          0x40FE35 
#define CDisplay__WriteTextHD2                             0x4137AD 
#define CDisplay__GetWorldFilePath                         0x40EAFA 
#define CDisplay__GetUserDefinedColor                      0x40F2F6 

#define CTextureFont__DrawWrappedText                      0x55AC90 

// EQ_Item 
#define EQ_Item__GetItemLinkHash                           0x4311E5 
#define EQ_Item__CanDrop                                   0x4315DE 

// CBankWnd 
#define CBankWnd__GetNumBankSlots                          0x4BCF02 

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                  0x4BF715 

// CMerchantWnd 
#define CMerchantWnd__SelectBuySellSlot                    0x4FEE2A 
#define CMerchantWnd__RequestBuyItem                       0x4FEF5D 
#define CMerchantWnd__RequestSellItem                      0x4FF165 
#define CMerchantWnd__DisplayBuyOrSellPrice                0x4FE437 

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                         0x516138 

// MapViewMap 
#define MapViewMap__SaveEx                                 0x4F9D85 
#define MapViewMap__Clear                                  0x4F9C14 


// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                           0x4FD649 

// EQItemList 
#define EQItemList__EQItemList                             0x44EDF3 
#define EQItemList__dEQItemList                            0x44EE6F 

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                      0x43517A 

// CContainerWnd 
#define CContainerWnd__HandleCombine                       0x4D47E9 
#define CContainerWnd__vftable                             0x5DB230 

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
#define CSidlManager__FindScreenPieceTemplate1             0x573040 

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                        0x57FED0 

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                       0x55A5B0 

// CXRect 
#define CXRect__CenterPoint                                0x4BCF09 

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
#define CXWnd__GetWindowTextA                              0x4B6CEB 
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
#define CSliderWnd__GetValue                               0x57E860 
#define CSliderWnd__SetValue                               0x57EA50 
#define CSliderWnd__UpdateThumb                            0x57E820 

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                          0x4BCA78 
#define CEditBaseWnd__SetSel                               0x574FC0 

// CComboWnd 
#define CComboWnd__DeleteAll                               0x579F60 
#define CComboWnd__Draw                                    0x57A160 
#define CComboWnd__GetButtonRect                           0x579F90 
#define CComboWnd__GetCurChoice                            0x579F20 
#define CComboWnd__GetListRect                             0x57A550 
#define CComboWnd__GetTextRect                             0x579FF0 
#define CComboWnd__InsertChoice                            0x57A5B0 
#define CComboWnd__SetColors                               0x579EF0 
#define CComboWnd__SetChoice                               0x57A690 

// CListWnd 
#define CListWnd__AddColumn                                0x5692B0 
#define CListWnd__AddColumn1                               0x568E00 
#define CListWnd__AddLine                                  0x5689C0 
#define CListWnd__AddString                                0x568B40 
#define CListWnd__CalculateFirstVisibleLine                0x565FB0 
#define CListWnd__CalculateVSBRange                        0x567B40 
#define CListWnd__ClearAllSel                              0x565710 
#define CListWnd__CloseAndUpdateEditWindow                 0x5665B0 
#define CListWnd__Compare                                  0x5668F0 
#define CListWnd__Draw                                     0x5677A0 
#define CListWnd__DrawColumnSeparators                     0x5675F0 
#define CListWnd__DrawHeader                               0x565930 
#define CListWnd__DrawItem                                 0x567000 
#define CListWnd__DrawLine                                 0x567360 
#define CListWnd__DrawSeparator                            0x5676C0 
#define CListWnd__EnsureVisible                            0x566000 
#define CListWnd__ExtendSel                                0x566F30 
#define CListWnd__GetColumnFlags                           0x5651E0 
#define CListWnd__GetColumnJustification                   0x565380 
#define CListWnd__GetColumnMinWidth                        0x565310 
#define CListWnd__GetColumnWidth                           0x565240 
#define CListWnd__GetCurSel                                0x565020 
#define CListWnd__GetHeaderRect                            0x564E60 
#define CListWnd__GetItemAtPoint                           0x5662B0 
#define CListWnd__GetItemAtPoint1                          0x566320 
#define CListWnd__GetItemData                              0x565060 
#define CListWnd__GetItemHeight                            0x565D30 
#define CListWnd__GetItemIcon                              0x565120 
#define CListWnd__GetItemRect                              0x5660D0 
#define CListWnd__GetItemText                              0x5650A0 
#define CListWnd__GetSelList                               0x568CE0 
#define CListWnd__GetSeparatorRect                         0x566840 
#define CListWnd__IsLineEnabled                            0x565800 
#define CListWnd__RemoveLine                               0x568C90 
#define CListWnd__SetColors                                0x564DD0 
#define CListWnd__SetColumnWidth                           0x5652C0 
#define CListWnd__SetColumnJustification                   0x5653E0 
#define CListWnd__SetCurSel                                0x565630 
#define CListWnd__SetItemColor                             0x568600 
#define CListWnd__SetItemData                              0x5657C0 
#define CListWnd__SetItemText                              0x568540 
#define CListWnd__ShiftColumnSeparator                     0x566EA0 
#define CListWnd__Sort                                     0x569350 
#define CListWnd__ToggleSel                                0x565650 

// CEditWnd 
#define CEditWnd__DrawCaret                                0x57A9F0 
#define CEditWnd__GetCharIndexPt                           0x57B810 
#define CEditWnd__GetDisplayString                         0x57AB20 
#define CEditWnd__GetHorzOffset                            0x57AD90 
#define CEditWnd__GetLineForPrintableChar                  0x57B2B0 
#define CEditWnd__GetSelStartPt                            0x57BA50 
#define CEditWnd__GetSTMLSafeText                          0x57AF70 
#define CEditWnd__PointFromPrintableChar                   0x57B3C0 
#define CEditWnd__SelectableCharFromPoint                  0x57B540 
#define CEditWnd__SetEditable                              0x57AF40 

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                            0x4DBC3B 
#define CGaugeWnd__CalcLinesFillRect                       0x4DBC97 
#define CGaugeWnd__Draw                                    0x4DBF97 

// CStmlWnd 
#define CStmlWnd__AppendSTML                               0x564300 
#define CStmlWnd__CalculateHSBRange                        0x55BC10 
#define CStmlWnd__CalculateVSBRange                        0x55BBB0 
#define CStmlWnd__CanBreakAtCharacter                      0x55BD50 
#define CStmlWnd__CanGoBackward                            0x55BDD0 
#define CStmlWnd__FastForwardToEndOfTag                    0x55CB20 
#define CStmlWnd__GetNextChar                              0x55C230 
#define CStmlWnd__GetNextTagPiece                          0x55C920 
#define CStmlWnd__GetSTMLText                              0x4CF3A7 
#define CStmlWnd__GetThisChar                              0x55BA50 
#define CStmlWnd__GetVisiableText                          0x55E2F0 
#define CStmlWnd__InitializeWindowVariables                0x5600F0 
#define CStmlWnd__MakeStmlColorTag                         0x55B200 
#define CStmlWnd__MakeWndNotificationTag                   0x55B2A0 
#define CStmlWnd__StripFirstSTMLLines                      0x564080 
#define CStmlWnd__UpdateHistoryString                      0x55E730 

// CTabWnd 
#define CTabWnd__Draw                                      0x579C40 
#define CTabWnd__DrawCurrentPage                           0x579730 
#define CTabWnd__DrawTab                                   0x5794B0 
#define CTabWnd__GetCurrentPage                            0x579060 
#define CTabWnd__GetCurrentTabIndex                        0x578E00 
#define CTabWnd__GetNumTabs                                0x578F30 
#define CTabWnd__GetPageClientRect                         0x578E10 
#define CTabWnd__GetPageFromTabIndex                       0x578F60 
#define CTabWnd__GetPageInnerRect                          0x578E70 
#define CTabWnd__GetTabInnerRect                           0x579170 
#define CTabWnd__GetTabRect                                0x579070 
#define CTabWnd__IndexInBounds                             0x578F40 
#define CTabWnd__InsertPage                                0x579B30 
#define CTabWnd__SetPage                                   0x579210 
#define CTabWnd__SetPageRect                               0x579320 
#define CTabWnd__UpdatePage                                0x5793D0 

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
