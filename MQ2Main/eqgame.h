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
//.rdata:005DB13C aMar232004      db 'Mar 23 2004',0 
//.rdata:005DB148 a100314         db '10:03:14',0       
#define __ExpectedVersionDate                         "Mar 23 2004" 
#define __ExpectedVersionTime                         "10:03:14" 
#define __ActualVersionDate                           0x5DB13C 
#define __ActualVersionTime                           0x5DB148

#define __ClientOverride							  0 
#define __MacroQuestWinClassName					  "__MacroQuestTray" 
#define __MacroQuestWinName                           "MacroQuest" 

// Memory Protection 
#define __MemChecker0                                0x4BEBF9 
#define __MemChecker1                                0x4C35C9 
#define __MemChecker2                                0x4C53A0 
#define __MemChecker3                                0x4C543D 
#define __EncryptPad0                                0x6119C0 
#define __EncryptPad1                                0x611DC0 
#define __EncryptPad2                                0x612878 
#define __EncryptPad3                                0x612C78 

#define DI8__Main                                    0x78EE34 
#define DI8__Keyboard                                0x78EE38 
#define DI8__Mouse                                   0x78EE3C 

#define __LastTell                                   0x6D0E8C 
#define __Guilds                                     0x731548 
#define __Mouse                                      0x78EE40 
#define __Attack                                     0x72F6BE 
#define __InChatMode                                 0x6CEDC0 
#define __gWorld                                     0x7314A0 
#define __GroupCount                                 0x72FA50 
#define __CommandList                                0x60B730 
#define __DoAbilityList                              0x708960 
#define __DoAbilityAvailable                         0x6CFBB4 
#define __ServerHost                                 0x72F90C 
#define __ServerName                                 0x708920 
#define __HWnd                                       0x6CED80 
#define __Clicks                                     0x6CEE80 
#define __ScreenX                                    0x6CED88 
#define __ScreenY                                    0x6CED8C 
#define __EQP_IDArray                                0x6CBE58 
#define __CurrentMapLabel                            0x797C9C 
#define __BindList                                   0x60B220 
#define __RangeAttackReady                           0x6CFC18 
#define __Socials									 0x708A20 

//// 
//Section 1: Vital Offsets 
//// 
#define pinstCSidlManager                             0x7A3024 
#define pinstCDisplay                                 0x73152C 
#define pinstCEverQuest                               0x78EFA8 
#define pinstPCData                                   0x731508 
#define pinstCharData                                 0x731508 
#define pinstCharSpawn                                0x731500 
#define pinstSpawnList                                0x7314C8 
#define pinstLocalPlayer                              0x7314EC 
#define pinstControlledPlayer						  0x731500 
#define pinstWorldData                                0x7314C4 
#define pinstSpellManager                             0x78B9FC 
#define pinstActiveMerchant                           0x731518 
#define pinstSelectedItem                             0x797BB8 
#define pinstGroup                                    0x72FB98 
#define pinstTarget                                   0x73150C 
#define pinstSwitchManager                            0x6CED74 
#define pinstEQItemList                               0x7314CC 
#define pinstSpellSets                                0x72F2C4 
#define instEQZoneInfo                                0x6CEFF4 
#define pinstCXWndManager                             0x7A301C 
#define instKeypressHandler							  0x77E2F0


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                       0x61BD00 
/*      pinstCharacterSelect                                    0x61BD04*/ 
#define pinstCFacePick                                          0x61BD08 
#define pinstTextMessageWnd                                     0x61BD0C 
#define pinstCNoteWnd                                           0x61BD10 
#define pinstCHelpWnd                                           0x61BD14 
#define pinstCBookWnd                                           0x61BD18 
#define pinstCPetInfoWnd                                        0x61BD1C 
#define pinstCTrainWnd                                          0x61BD20 
#define pinstCSkillsWnd                                         0x61BD24 
#define pinstCSkillsSelectWnd                                   0x61BD28 
#define pinstCCombatSkillSelectWnd                              0x61BD2C 
#define pinstCFriendsWnd                                        0x61BD30 
#define pinstCAAWnd                                             0x61BD34 
#define pinstCGroupSearchFiltersWnd                             0x61BD38 
#define pinstCLoadskinWnd                                       0x61BD3C 
#define pinstCAlarmWnd                                          0x61BD40 
#define pinstCMusicPlayerWnd                                    0x61BD44 
#define pinstCRaidWnd                                           0x61BD48 
#define pinstCRaidOptionsWnd                                    0x61BD4C 
#define pinstCBreathWnd                                         0x61BD50 
#define pinstCMapViewWnd                                        0x61BD54 
#define pinstCMapToolbarWnd                                     0x61BD58 
#define pinstCEditLabelWnd                                      0x61BD5C 
#define pinstCTargetWnd                                         0x61BD60 
#define pinstCHotButtonWnd                                      0x61BD64 
#define pinstCColorPickerWnd                                    0x61BD68 
#define pinstCPlayerWnd                                         0x61BD6C 
#define pinstCOptionsWnd                                        0x61BD70 
#define pinstCBuffWindowNORMAL                                  0x61BD74 
#define pinstCBuffWindowSHORT                                   0x61BD78 
/*      pinstCharacterCreation                                  0x61BD7C*/ 
#define pinstCCursorAttachment                                  0x61BD80 
#define pinstCCastingWnd                                        0x61BD84 
#define pinstCCastSpellWnd                                      0x61BD88 
#define pinstCSpellBookWnd                                      0x61BD8C 
#define pinstCInventoryWnd                                      0x61BD90 
#define pinstCBankWnd                                           0x61BD94 
#define pinstCQuantityWnd                                       0x61BD98 
#define pinstCLootWnd                                           0x61BD9C 
#define pinstCActionsWnd                                        0x61BDA0 
#define pinstCCombatAbilityWnd                                  0x61BDA4 
#define pinstCMerchantWnd                                       0x61BDA8 
#define pinstCTradeWnd                                          0x61BDAC 
#define pinstCSelectorWnd                                       0x61BDB0 
#define pinstCBazaarWnd                                         0x61BDB4 
#define pinstCBazaarSearchWnd                                   0x61BDB8 
#define pinstCGiveWnd                                           0x61BDBC 
#define pinstCTrackingWnd                                       0x61BDC0 
#define pinstCInspectWnd                                        0x61BDC4 
#define pinstCSocialEditWnd                                     0x61BDC8 
#define pinstCFeedbackWnd                                       0x61BDCC 
#define pinstCBugReportWnd                                      0x61BDD0 
#define pinstCVideoModesWnd                                     0x61BDD4 
#define pinstCTextEntryWnd                                      0x61BDD8 
#define pinstCFileSelectionWnd                                  0x61BDDC 
#define pinstCCompassWnd                                        0x61BDE0 
#define pinstCPlayerNotesWnd                                    0x61BDE4 
#define pinstCGemsGameWnd                                       0x61BDE8 
#define pinstCTimeLeftWnd                                       0x61BDEC 
#define pinstCPetitionQWnd                                      0x61BDF0 
#define pinstCSoulmarkWnd                                       0x61BDF4 
#define pinstCStoryWnd                                          0x61BDF8 
#define pinstCJournalTextWnd                                    0x61BDFC 
#define pinstCJournalCatWnd                                     0x61BE00 
#define pinstCBodyTintWnd                                       0x61BE04 
#define pinstCInvSlotMgr                                        0x61BE08 
#define pinstCContainerMgr                                      0x61BE0C 
#define pinstCAdventureLeaderboardWnd                           0x797688 
#define pinstCAdventureMerchantWnd                              0x7976A0 
#define pinstCAdventureRequestWnd                               0x7976B8 
#define pinstCAdventureStatsWnd                                 0x7976D0 
#define pinstCChatManager                                       0x797948 
#define pinstCDynamicZoneWnd                                    0x797A00 
#define pinstCFindLocationWnd                                   0x797A90 
#define pinstCGroupSearchWnd                                    0x797B0C 
#define pinstCGroupWnd                                          0x797B24 
#define pinstCGuildMgmtWnd                                      0x797B3C 
/*      pinstMaxItemDisplays                                    0x797BE4*/ 
#define pinstCLeadershipWnd                                     0x797C38 
#define pinstCPopupWndManager                                   0x797D88 
#define pinstCSystemInfoDialogBox                               0x798604 
#define pinstCTargetOfTargetWnd                                 0x79861C 
#define pinstCTipWndOFDAY                                       0x798684 
#define pinstCTipWndCONTEXT                                     0x798688 
#define pinstCTradeskillWnd                                     0x7986B4 
#define pinstCTributeBenefitWnd                                 0x7986F4  
#define pinstCTributeMasterWnd                                  0x79870C 
#define pinstCContextMenuManager                                0x7A3040 


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define DrawNetStatus                                 0x4B420C 
#define CrashDetected                                 0x4C509E 
#define __ProcessGameEvents                           0x4AAE77 
#define __ConvertItemTags                             0x45A3D8 
#define __SendMessage                                 0x4B99F3 
#define __NewUIINI                                    0x521958 
#define __ExecuteCmd                                  0x44CC2F 

// EQ_LoadingS 
#define EQ_LoadingS__WriteTextHD                      0x43235D


//// 
// Section 4: Function Offsets 
//// 
// CEverQuest 
#define CEverQuest__dsp_chat                     0x49AFC7 
#define CEverQuest__ClickedPlayer                0x49832C 
#define CEverQuest__EnterZone                    0x49BCE8 
#define CEverQuest__GetBodyTypeDesc              0x49215F 
#define CEverQuest__GetClassDesc                 0x491BE1 
#define CEverQuest__GetClassThreeLetterCode      0x491FFC 
#define CEverQuest__GetDeityDesc                 0x493BF2 
#define CEverQuest__GetRaceDesc                  0x492464 
#define CEverQuest__InterpretCmd                 0x4A78C7 
#define CEverQuest__LeftClickedOnPlayer          0x4A9A8D 
#define CEverQuest__RightClickedOnPlayer         0x4A37C1 
#define CEverQuest__SetGameState				 0x498493 

// CXWndManager 
#define CXWndManager__RemoveWnd                  0x56E730 
#define CXWndManager__GetKeyboardFlags           0x56E350 
#define CXWndManager__HandleKeyboardMsg          0x56E820 

// KeyPressHandler 
#define KeypressHandler__HandleKeyDown                   0x4AF7E5 
#define KeypressHandler__HandleKeyUp                     0x4AFA89 
#define KeypressHandler__AttachKeyToEqCommand            0x4B0E47 
#define KeypressHandler__AttachAltKeyToEqCommand         0x4B0E84 
#define KeypressHandler__SaveKeymapping                  0x4B0D90 
#define KeypressHandler__ClearCommandStateArray          0x4AFA78 

// EQ_Character 
#define EQ_Character__Max_Mana                           0x420E5B 
#define EQ_Character__Max_HP                             0x420CA6 
#define EQ_Character__Cur_HP                             0x422821 
#define EQ_Character__GetFocusCastingTimeModifier        0x4288ED 
#define EQ_Character__GetAACastingTimeModifier           0x428C1B 
#define EQ_Character__CastSpell                          0x42C7C1 

// EQPlayer 
#define EQPlayer__EQPlayer                               0x4872F7 
#define EQPlayer__dEQPlayer                              0x486065  
#define EQPlayer__DoAttack                               0x482FFC 

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr                                     0x4010C0 
#define CXStr__CXStr1                                    0x401E96 
#define CXStr__CXStr3                                    0x59D8E0 
#define CXStr__dCXStr                                    0x4CFF79 
#define CXStr__operator_plus_equal1                      0x59E970 
#define CXStr__operator_equal1                           0x59DAA0 

// CChatWindow 
#define CChatWindow__CChatWindow                         0x4E166D 
//#define CChatWindow__dCChatWindow                      0x4ba03b 

// CChatManager 
#define CChatManager__GetRGBAFromIndex                   0x4DE231 
#define CChatManager__InitContextMenu                    0x4DEB95 

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                         0x4FBACF 
#define CInvSlotMgr__MoveItem							 0x4FB47E 

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem						 0x4FE7D9 
#define CItemDisplayWnd__SetSpell                        0x4FDCF6 

// CLabel 
#define CLabel__Draw                                     0x5048E2 

// CDisplay 
#define CDisplay__ReloadUI                               0x41771B
#define CDisplay__CleanGameUI                            0x41009C 
#define CDisplay__GetClickedActor                        0x40D525 
#define CDisplay__WriteTextHD2                           0x410B59
#define CDisplay__GetWorldFilePath                       0x40BF53 

// EQ_Item 
#define EQ_Item__GetItemLinkHash                         0x431E63 

// CBankWnd 
#define CBankWnd__GetNumBankSlots                        0x4D006A 

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                0x4D2724 

// CMerchantWnd 
#define CMerchantWnd__SelectBuySellSlot                  0x50D2A9 
#define CMerchantWnd__RequestBuyItem                     0x50C49C 
#define CMerchantWnd__RequestSellItem                    0x50C81A 
#define CMerchantWnd__DisplayBuyOrSellPrice              0x50C2D1 

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                  0x51EBE8 

// MapViewMap 
#define MapViewMap__SaveEx                          0x507AF7  
#define MapViewMap__Clear                           0x507928 
//#define MapViewMap__Draw							0x508E79 


// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd					0x50B392 

// EQItemList 
#define EQItemList__EQItemList                      0x44F3F0 
#define EQItemList__dEQItemList                     0x44F46C 

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney               0x434E26  

// CSidlScreenWnd 
#define CSidlScreenWnd__CSidlScreenWnd1             0x552520  
#define CSidlScreenWnd__dCSidlScreenWnd             0x551BC0 
#define CSidlScreenWnd__CreateChildrenFromSidl      0x550F40 
#define CSidlScreenWnd__GetChildItem                0x550850 
#define CSidlScreenWnd__WndNotification             0x550AC0 
#define CSidlScreenWnd__CalculateHSBRange           0x5500E0  
#define CSidlScreenWnd__CalculateVSBRange           0x5500E0 
#define CSidlScreenWnd__ConvertToRes                0x5507D0 
#define CSidlScreenWnd__CSidlScreenWnd2             0x552520 
#define CSidlScreenWnd__DrawBackground              0x551D50 
#define CSidlScreenWnd__DrawSidlPiece               0x550B60 
#define CSidlScreenWnd__EnableIniStorage            0x550780 
#define CSidlScreenWnd__GetSidlPiece                0x550E00 
#define CSidlScreenWnd__HandleRButtonDown           0x5508C0 
#define CSidlScreenWnd__Init1						0x5520E0 
#define CSidlScreenWnd__LoadIniInfo                 0x550FF0 
#define CSidlScreenWnd__LoadIniListWnd              0x551920 
#define CSidlScreenWnd__LoadSidlScreen              0x5509A0 
#define CSidlScreenWnd__OnResize					0x550190 
#define CSidlScreenWnd__SetScreen                   0x551CE0 
#define CSidlScreenWnd__StoreIniInfo                0x550310 
#define CSidlScreenWnd__StoreIniListWnd             0x5519D0 

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1      0x576CF0 

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                0x55E460 

// CXRect 
#define CXRect__CenterPoint                         0x4D0071 

// CXWnd 
#define CXWnd__Bottom						0x556510  
#define CXWnd__BringToTop					0x552CC0 
#define CXWnd__Center						0x5562D0 
#define CXWnd__ClrFocus                     0x552A10 
#define CXWnd__Deactivate                   0x550300 
#define CXWnd__DoAllDrawing                 0x556EE0 
#define CXWnd__DrawBackground               0x556510  
#define CXWnd__DrawChildren                 0x557010 
#define CXWnd__DrawCloseBox                 0x554B40 
#define CXWnd__DrawColoredRect              0x552EF0 
#define CXWnd__DrawCursor                   0x552A80 
#define CXWnd__DrawHScrollbar               0x555040 
#define CXWnd__DrawLasso                    0x555E80 
#define CXWnd__DrawMinimizeBox              0x554C20 
#define CXWnd__DrawNC						0x556A50 
#define CXWnd__DrawTileBox                  0x554D00 
#define CXWnd__DrawTitleBar                 0x554DE0 
#define CXWnd__DrawTooltipAtPoint           0x556100 
#define CXWnd__DrawVScrollbar               0x555440 
#define CXWnd__GetBorderFrame               0x553330 
#define CXWnd__GetChildWndAt                0x555CE0 
#define CXWnd__GetClientClipRect            0x553270 
#define CXWnd__GetClientRect                0x404032  
#define CXWnd__GetCloseBoxTemplate          0x553390 
#define CXWnd__GetCursorToDisplay           0x552D90 
#define CXWnd__GetDragDropCursor            0x5531E0 
#define CXWnd__GetFirstChildWnd             0x552D50 
#define CXWnd__GetHitTestRect               0x553DB0 
#define CXWnd__GetInnerRect                 0x403FFB  
#define CXWnd__GetMinimizeBoxTemplate       0x5533C0 
#define CXWnd__GetMinimizedRect             0x5559E0 
#define CXWnd__GetNextChildWnd              0x555CC0 
#define CXWnd__GetNextSib                   0x552D70 
#define CXWnd__GetScreenClipRect            0x556560 
#define CXWnd__GetScreenRect                0x553500 
#define CXWnd__GetTileBoxTemplate           0x5533E0 
#define CXWnd__GetTooltip                   0x552A60 
#define CXWnd__GetTooltipRect               0x556050 
#define CXWnd__GetUntileSize                0x403FE1 
#define CXWnd__GetWindowTextA               0x4CAB0B 
#define CXWnd__GetXMLTooltip                0x552850 
#define CXWnd__HitTest                      0x555D60 
#define CXWnd__IsActive                     0x5532E0 
#define CXWnd__IsDescendantOf               0x5532F0 
#define CXWnd__IsReallyVisible              0x555CA0 
#define CXWnd__IsType                       0x556E80 
#define CXWnd__IsValid                      0x403FBF 
#define CXWnd__Left							0x5564A0 
#define CXWnd__Move							0x555850 
#define CXWnd__Move1						0x5558E0
#define CXWnd__PostDraw                     0x4E4B10  
#define CXWnd__ProcessTransition            0x552C80 
#define CXWnd__QueryClickStickDropOK        0x553230 
#define CXWnd__QueryDropOK                  0x5531F0 
#define CXWnd__Refade						0x552AB0 
#define CXWnd__RequestDockInfo				0x553D30 
#define CXWnd__Resize						0x5566A0 
#define CXWnd__Right                        0x556440 
#define CXWnd__SetAttributesFromSidl        0x5565D0 
#define CXWnd__SetFirstChildPointer         0x553750 
#define CXWnd__SetFocus                     0x554A30 
#define CXWnd__SetKeyTooltip                0x553790 
#define CXWnd__SetMouseOver                 0x553770 
#define CXWnd__SetNextSibPointer            0x553760 
#define CXWnd__SetVScrollPos                0x5530C0 
#define CXWnd__StartFade                    0x552CE0 

// CSliderWnd 
#define CSliderWnd__GetValue                          0x581FF0 
#define CSliderWnd__SetValue                          0x582770 
#define CSliderWnd__UpdateThumb                       0x582560 

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                     0x4CFBC7 
#define CEditBaseWnd__SetSel                          0x578CA0 

// CComboWnd 
#define CComboWnd__DeleteAll                          0x57DCC0 
#define CComboWnd__Draw                               0x57DEC0 
#define CComboWnd__GetButtonRect                      0x57DCF0 
#define CComboWnd__GetCurChoice                       0x57DC80 
#define CComboWnd__GetListRect                        0x57E2B0 
#define CComboWnd__GetTextRect                        0x57DD50 
#define CComboWnd__HitTest                            0x4D6929 
#define CComboWnd__InsertChoice                       0x57E310 
#define CComboWnd__SetColors                          0x57DC50 
#define CComboWnd__SetChoice                          0x57E3F0 

// CListWnd 
#define CListWnd__AddLine                             0x56C760 
#define CListWnd__AddString                           0x56C8E0 
#define CListWnd__CalculateFirstVisibleLine           0x569D90 
#define CListWnd__CalculateLineHeights                0x569D30 
#define CListWnd__CalculateVSBRange                   0x56B900 
#define CListWnd__ClearAllSel                         0x5695C0 
#define CListWnd__CloseAndUpdateEditWindow            0x56A390 
#define CListWnd__Compare                             0x56A6D0 
#define CListWnd__Draw                                0x56B560 
#define CListWnd__DrawBackground                      0x568D50 
#define CListWnd__DrawColumnSeparators                0x563520 
#define CListWnd__DrawHeader                          0x56B490 
#define CListWnd__DrawItem                            0x56ADE0 
#define CListWnd__DrawLine                            0x56B130 
#define CListWnd__DrawSeparator                       0x521ED6 
#define CListWnd__EnsureVisible                       0x569DE0 
#define CListWnd__ExtendSel                           0x56AD10 
#define CListWnd__GetColumnFlags                      0x569090 
#define CListWnd__GetColumnMinWidth                   0x5691C0 
#define CListWnd__GetColumnWidth                      0x5690F0 
#define CListWnd__GetCurSel                           0x568ED0 
#define CListWnd__GetCursorToDisplay                  0x568DE0 
#define CListWnd__GetHeaderRect                       0x568D10 
#define CListWnd__GetItemAtPoint                      0x56A090 
#define CListWnd__GetItemAtPoint1                     0x56A100 
#define CListWnd__GetItemData                         0x568F10 
#define CListWnd__GetItemHeight                       0x569BC0 
#define CListWnd__GetItemIcon                         0x568FD0 
#define CListWnd__GetItemRect                         0x569EB0 
#define CListWnd__GetItemText                         0x568F50 
#define CListWnd__GetSelList                          0x56CA80 
#define CListWnd__GetSeparatorRect                    0x56A620 
#define CListWnd__IsLineEnabled                       0x5696B0 
#define CListWnd__SetColors                           0x568C80  
#define CListWnd__SetColumnWidth                      0x569170 
#define CListWnd__SetCurSel                           0x5694E0 
#define CListWnd__SetItemColor                        0x56C3A0 
#define CListWnd__SetItemData                         0x569670 
#define CListWnd__SetItemText                         0x56C2E0 
#define CListWnd__SetVScrollPos                       0x56A870 
#define CListWnd__ShiftColumnSeparator                0x56AC80 
#define CListWnd__Sort                                0x5788B0 
#define CListWnd__ToggleSel                           0x569500 

// CEditWnd 
#define CEditWnd__DrawCaret                           0x57E750 
#define CEditWnd__DrawMultiline                       0x57FC60 
#define CEditWnd__GetCaretPt                          0x580010 
#define CEditWnd__GetCharIndexPt                      0x57F560 
#define CEditWnd__GetDisplayString                    0x57EFF0 
#define CEditWnd__GetHorzOffset                       0x596E70 
#define CEditWnd__GetLineForPrintableChar             0x57F010 
#define CEditWnd__GetSelEndPt                         0x57F7A0 
#define CEditWnd__GetSelStartPt                       0x57F780 
#define CEditWnd__GetSTMLSafeText                     0x57ECD0 
#define CEditWnd__PointFromPrintableChar              0x57F120 
#define CEditWnd__SelectableCharFromPoint             0x57F2A0 
#define CEditWnd__SetEditable                         0x57ECA0 
#define CEditWnd__SetWindowTextA                      0x588380 

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect							0x4ECF69 
#define CGaugeWnd__CalcLinesFillRect					0x4ECFC5 
#define CGaugeWnd__Draw									0x4ED2C5 
#define CGaugeWnd__SetAttributesFromSidl				0x51FAB0 

// CStmlWnd 
#define CStmlWnd__AppendSTML							0x568190 
#define CStmlWnd__CalculateHSBRange						0x55FBF0 
#define CStmlWnd__CalculateVSBRange						0x55FB90 
#define CStmlWnd__CanBreakAtCharacter					0x55FD30 
#define CStmlWnd__CanGoBackward							0x55FDB0  
#define CStmlWnd__FastForwardPastSpaces					0x560730 
#define CStmlWnd__FastForwardToEndOfTag					0x560A90 
#define CStmlWnd__GetCursorToDisplay					0x563550 
#define CStmlWnd__GetNextChar							0x5601F0 
#define CStmlWnd__GetNextTagPiece						0x5608A0 
#define CStmlWnd__GetSTMLText							0x4E164F 
#define CStmlWnd__GetThisChar							0x55FA50 
#define CStmlWnd__GetVisiableText						0x562260
#define CStmlWnd__InitializeTempVariables				0x55FA00 
#define CStmlWnd__InitializeWindowVariables				0x564060 
#define CStmlWnd__MakeStmlColorTag						0x55F200 
#define CStmlWnd__MakeWndNotificationTag				0x55F2A0 
#define CStmlWnd__StripFirstSTMLLines					0x567F10 
#define CStmlWnd__UpdateHistoryString					0x55F0A0  

// CTabWnd 
#define CTabWnd__Draw                                 0x57D9A0 
#define CTabWnd__DrawCurrentPage                      0x57D490 
#define CTabWnd__DrawTab							  0x57D210 
#define CTabWnd__GetCurrentPage                       0x57CDC0 
#define CTabWnd__GetCurrentTabIndex                   0x57CB70 
#define CTabWnd__GetNumTabs                           0x57CC90 
#define CTabWnd__GetPageClientRect                    0x57CB80
#define CTabWnd__GetPageFromTabIndex                  0x57C750 
#define CTabWnd__GetPageInnerRect                     0x57CBE0 
#define CTabWnd__GetTabInnerRect                      0x57CED0 
#define CTabWnd__GetTabRect                           0x57CDD0 
#define CTabWnd__IndexInBounds                        0x57CCA0 
#define CTabWnd__InsertPage                           0x57D890 
#define CTabWnd__SetPage                              0x57CF70 
#define CTabWnd__SetPageRect                          0x57D080 
#define CTabWnd__UpdatePage                           0x57D130 

// CTextOverlay 
#define CTextOverlay__DisplayText                     0x4013F2 