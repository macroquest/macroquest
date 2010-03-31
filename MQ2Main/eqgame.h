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
#define __ExpectedVersionDate							   "Oct 11 2004" 
#define __ExpectedVersionTime							   "15:21:50" 
#define __ActualVersionDate                                0x5F694C
#define __ActualVersionTime                                0x5F6958

#define __ClientOverride								   0 
#define __MacroQuestWinClassName						   "__MacroQuestTray" 
#define __MacroQuestWinName								   "MacroQuest" 

// Memory Protection 
#define __MemChecker0                                      0x4EF549 
#define __MemChecker1                                      0x526F1E
#define __MemChecker2                                      0x52ADC3
#define __MemChecker3                                      0x52AE50
#define __MemChecker4                                      0x5AED70
#define __EncryptPad0                                      0x715D70
#define __EncryptPad1                                      0x7185E0
#define __EncryptPad2                                      0x7190D0
#define __EncryptPad3                                      0x7194D0
#define __EncryptPad4                                      0x71EB50

#define DI8__Main                                          0x8B244C
#define DI8__Keyboard                                      0x8B2450
#define DI8__Mouse                                         0x8B2454

#define __LastTell                                         0x7E8354
#define __Guilds                                           0x84EAC8
#define __Mouse                                            0x8B2458
#define __Attack                                           0x846BD0
#define __InChatMode                                       0x7E6220
#define __gWorld                                           0x8489B0
#define __GroupCount                                       0x846F60
#define __CommandList                                      0x61E238
#define __DoAbilityList                                    0x81FE28
#define __DoAbilityAvailable                               0x7E7068
#define __ServerHost                                       0x846E1C
#define __ServerName                                       0x81FDE8
#define __HWnd                                             0x7E61E0
#define __Clicks                                           0x7E62E4
#define __ScreenX                                          0x7E61E8
#define __ScreenY                                          0x7E61EC
#define __ScreenMode                                       0x7320F8
#define __MouseLook                                        0x7E62B2
#define __EQP_IDArray                                      0x734520
#define __CurrentMapLabel                                  0x89737C
#define __BindList                                         0x61DCD8
#define __RangeAttackReady                                 0x7E70CC
#define __AltTimerReady                                    0x7E70CE
#define __Socials                                          0x81FEE8
#define __HotkeyPage                                       0x846788
#define __CurrentSocial                                    0x621520
#define __GroupLeader                                      0x8470BC
#define __SkillDict                                        0x737828
#define __DrawHandler                                      0x8BBDFC
#define __FriendsList                                      0x81CBE8
#define __IgnoreList                                       0x81E4E8
#define __NetStatusToggle                                  0x7E62B4
#define __ShowNames                                        0x7E72B0
#define __PCNames                                          0x7E7360
//// 
//Section 1: Vital Offsets 
//// 
#define pinstCSidlManager                                  0x8BB8BC
#define pinstCDisplay                                      0x848A3C
#define pinstCEverQuest                                    0x8B25C0
#define pinstPCData                                        0x848A18
#define pinstCharData                                      0x848A18
#define pinstCharSpawn                                     0x848A10
#define pinstSpawnList                                     0x8489D8
#define pinstLocalPlayer                                   0x8489FC
#define pinstControlledPlayer                              0x848A10
#define pinstWorldData                                     0x8489D4
#define pinstSpellManager                                  0x8A467C
#define pinstTradeTarget                                   0x8489F8
#define pinstActiveMerchant                                0x848A28
#define pinstActiveBanker                                  0x848A2C
#define pinstActiveCorpse                                  0x848A30
#define pinstActiveGMaster                                 0x848A34
#define pinstSelectedItem                                  0x897000
#define pinstGroup                                         0x8470A8
#define pinstTarget                                        0x848A1C
#define pinstSwitchManager                                 0x737440
#define pinstEQItemList                                    0x8489DC
#define pinstSpellSets                                     0x84678C
#define instEQZoneInfo                                     0x7E6450
#define pinstCXWndManager                                  0x8BB8B4
#define instKeypressHandler                                0x89706C
#define pinstStringTable                                   0x8489C8
#define pinstAltAdvManager                                 0x737444
#define instCRaid                                          0x848ED8

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                  0x720530
#define pinstCharacterSelect                               0x732B8C
#define pinstCFacePick                                     0x732B90
// removed 4-14 exe #define pinstCTextMessageWnd                                
#define pinstCNoteWnd                                      0x732B94
#define pinstCHelpWnd                                      0x732B98
#define pinstCBookWnd                                      0x732B9C
#define pinstCPetInfoWnd                                   0x732BA0
#define pinstCTrainWnd                                     0x732BA4
#define pinstCSkillsWnd                                    0x732BA8
#define pinstCSkillsSelectWnd                              0x732BAC
#define pinstCCombatSkillSelectWnd                         0x732BB0
#define pinstCFriendsWnd                                   0x732BB4
#define pinstCAAWnd                                        0x732BB8
#define pinstCGroupSearchFiltersWnd                        0x732BBC
#define pinstCLoadskinWnd                                  0x732BC0
#define pinstCAlarmWnd                                     0x732BC4
#define pinstCMusicPlayerWnd                               0x732BC8
#define pinstCRaidWnd                                      0x732BD4
#define pinstCRaidOptionsWnd                               0x732BD8
#define pinstCBreathWnd                                    0x732BDC
#define pinstCMapViewWnd                                   0x732BE0
#define pinstCMapToolbarWnd                                0x732BE4
#define pinstCEditLabelWnd                                 0x732BE8
#define pinstCTargetWnd                                    0x732BEC
#define pinstCHotButtonWnd                                 0x732BF0
#define pinstCColorPickerWnd                               0x732BF4
#define pinstCPlayerWnd                                    0x732BF8
#define pinstCOptionsWnd                                   0x732BFC
#define pinstCBuffWindowNORMAL                             0x732C00
#define pinstCBuffWindowSHORT                              0x732C04
#define pinstCharacterCreation                             0x732C08
#define pinstCCursorAttachment                             0x732C0C
#define pinstCCastingWnd                                   0x732C10
#define pinstCCastSpellWnd                                 0x732C14
#define pinstCSpellBookWnd                                 0x732C18
#define pinstCInventoryWnd                                 0x732C1C
#define pinstCBankWnd                                      0x732C20
#define pinstCQuantityWnd                                  0x732C24
#define pinstCLootWnd                                      0x732C28
#define pinstCActionsWnd                                   0x732C2C
#define pinstCCombatAbilityWnd                             0x732C30
#define pinstCMerchantWnd                                  0x732C34
#define pinstCTradeWnd                                     0x732C38
#define pinstCSelectorWnd                                  0x732C3C
#define pinstCBazaarWnd                                    0x732C40
#define pinstCBazaarSearchWnd                              0x732C44
#define pinstCGiveWnd                                      0x732C48
#define pinstCTrackingWnd                                  0x732C4C
#define pinstCInspectWnd                                   0x732C50
#define pinstCSocialEditWnd                                0x732C54
#define pinstCFeedbackWnd                                  0x732C58
#define pinstCBugReportWnd                                 0x732C5C
#define pinstCVideoModesWnd                                0x732C60
#define pinstCTextEntryWnd                                 0x732C68
#define pinstCFileSelectionWnd                             0x732C6C
#define pinstCCompassWnd                                   0x732C70
#define pinstCPlayerNotesWnd                               0x732C74
#define pinstCGemsGameWnd                                  0x732C78
#define pinstCTimeLeftWnd                                  0x732C7C
#define pinstCPetitionQWnd                                 0x732C80
#define pinstCSoulmarkWnd                                  0x732C84
#define pinstCStoryWnd                                     0x732C88
#define pinstCJournalTextWnd                               0x732C8C
#define pinstCJournalCatWnd                                0x732C90
#define pinstCBodyTintWnd                                  0x732C94
#define pinstCInvSlotMgr                                   0x732C98
#define pinstCContainerMgr                                 0x732C9C
#define pinstCAdventureLeaderboardWnd                      0x7202C0
#define pinstCAdventureMerchantWnd                         0x7202D8
#define pinstCAdventureRequestWnd                          0x7202F0
#define pinstCAdventureStatsWnd                            0x720308
#define pinstCChatManager                                  0x7205E4
#define pinstCDynamicZoneWnd                               0x732DA0
#define pinstCFindLocationWnd                              0x896E7C
#define pinstCGroupSearchWnd                               0x896F3C
#define pinstCGroupWnd                                     0x896F54
#define pinstCGuildMgmtWnd                                 0x896F6C
#define pinstCItemDisplayManager                           0x89702C
#define pinstCLeadershipWnd                                0x8970F8
#define pinstCPopupWndManager                              0x898490
#define pinstCSystemInfoDialogBox                          0x8A52DC
#define pinstCTargetOfTargetWnd                            0x8A52FC
#define pinstCTipWndOFDAY                                  0x8A53C8
#define pinstCTipWndCONTEXT                                0x8A53CC
#define pinstCTradeskillWnd                                0x8A54B8
#define pinstCTributeBenefitWnd                            0x8A54F8
#define pinstCTributeMasterWnd                             0x8A5510
#define pinstCContextMenuManager                           0x8BB94C
// unknown window added 4-14 exe 0x79A234 


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define DrawNetStatus                                      0x4F256F
#define CrashDetected                                      0x52AA7F
#define __ProcessGameEvents                                0x4BBB11
#define __ConvertItemTags                                  0x45D12B
#define __SendMessage                                      0x50C794
#define __NewUIINI                                         0x514DE2
#define __ExecuteCmd                                       0x451818
#define __GetGaugeValueFromEQ                              0x5133FD
#define __get_melee_range                                  0x455DD5
#define __CastRay                                          0x45DDB0
#define __LoadSplashScreen								   0x5B4440

// EQ_LoadingS 
#define EQ_LoadingS__WriteTextHD                           0x498050


//// 
// Section 4: Function Offsets 
//// 
// CEverQuest 
#define CEverQuest__dsp_chat                               0x4AAAD2
#define CEverQuest__ClickedPlayer                          0x4A87C2
#define CEverQuest__EnterZone                              0x4AB78B
#define CEverQuest__GetBodyTypeDesc                        0x4A4626
#define CEverQuest__GetClassDesc                           0x4A40A8
#define CEverQuest__GetClassThreeLetterCode                0x4A44C3
#define CEverQuest__GetDeityDesc                           0x4A60B9
#define CEverQuest__GetRaceDesc                            0x4A492B
#define CEverQuest__InterpretCmd                           0x4B833F
#define CEverQuest__LeftClickedOnPlayer                    0x4BA595
#define CEverQuest__RightClickedOnPlayer                   0x4B2B3D
#define CEverQuest__SetGameState                           0x4A8895
#define CEverQuest__DropHeldItemOnGround                   0x4AA47C

// StringTable 
#define StringTable__getString                             0x51304E

// AltAdvManager 
#define AltAdvManager__IsAbilityReady                      0x481933
#define AltAdvManager__GetCalculatedTimer				   0x481905

// CXWndManager 
#define CXWndManager__RemoveWnd                            0x57BAB0
#define CXWndManager__GetKeyboardFlags                     0x57B6D0
#define CXWndManager__HandleKeyboardMsg                    0x57BBA0
#define CXWndManager__DrawWindows                          0x57C990
#define CXWndManager__DrawCursor                           0x57CD40
#define CXWndManager__GetFirstChildWnd                     0x57C290

// KeyPressHandler 
#define KeypressHandler__HandleKeyDown                     0x4E3423
#define KeypressHandler__HandleKeyUp                       0x4E369A
#define KeypressHandler__AttachKeyToEqCommand              0x4E4740
#define KeypressHandler__AttachAltKeyToEqCommand           0x4E4773
#define KeypressHandler__SaveKeymapping                    0x4E4610
#define KeypressHandler__ClearCommandStateArray            0x4E458B

// EQ_Character 
#define EQ_Character__Max_Endurance                        0x482635
#define EQ_Character__Max_HP                               0x4823E2
#define EQ_Character__Cur_HP                               0x485F60
#define EQ_Character__GetFocusCastingTimeModifier          0x48DA22
#define EQ_Character__GetAACastingTimeModifier             0x48DF27
#define EQ_Character__CastSpell                            0x491667
#define EQ_Character__Max_Mana                             0x49A99A

// EQPlayer 
#define EQPlayer__EQPlayer                                 0x4754AA
#define EQPlayer__dEQPlayer                                0x474D53
#define EQPlayer__DoAttack                                 0x4726EC
#define EQPlayer__ChangeBoneStringSprite                   0x46AAB2
#define EQPlayer__SetNameSpriteState                       0x46F0BF
#define EQPlayer__SetNameSpriteTint                        0x46AB1E

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                       0x401006
#define CXStr__CXStr1                                      0x401000
#define CXStr__CXStr3                                      0x52E850
#define CXStr__dCXStr                                      0x40A86D
#define CXStr__operator_plus_equal1                        0x52F850
#define CXStr__operator_equal1                             0x52EA10

// CChatWindow 
#define CChatWindow__CChatWindow                           0x4200EF

// CChatManager 
#define CChatManager__GetRGBAFromIndex                     0x41D0A8
#define CChatManager__InitContextMenu                      0x41D18C

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                           0x4D8C7A
#define CInvSlotMgr__MoveItem                              0x4D90B2

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                           0x4DD602
#define CItemDisplayWnd__SetSpell                          0x4DC7E5

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                         0x4D5922

// CLabel 
#define CLabel__Draw                                       0x4E4908

// CGauge 
#define CGaugeWnd__Draw                                    0x4C7370

// CDisplay 
#define CDisplay__ReloadUI                                 0x43DEAC
#define CDisplay__CleanGameUI                              0x43691B
#define CDisplay__GetClickedActor                          0x433822
#define CDisplay__WriteTextHD2                             0x437491
#define CDisplay__GetWorldFilePath                         0x4324F5
#define CDisplay__GetUserDefinedColor                      0x432CE9

#define CTextureFont__DrawWrappedText                      0x55F5E0

// EQ_Item 
#define EQ_Item__GetItemLinkHash                           0x49760E
#define EQ_Item__CanDrop                                   0x497A15

// CBankWnd 
#define CBankWnd__GetNumBankSlots                          0x40AFE9

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                  0x40D4AF

// CMerchantWnd 
#define CMerchantWnd__SelectBuySellSlot                    0x4F06B2
#define CMerchantWnd__RequestBuyItem                       0x4F07E5
#define CMerchantWnd__RequestSellItem                      0x4F09ED
#define CMerchantWnd__DisplayBuyOrSellPrice                0x4EFB13

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                         0x511486

// MapViewMap 
#define MapViewMap__SaveEx                                 0x4EC257
#define MapViewMap__Clear                                  0x4EBAC5


// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                           0x4EEDB8

// EQItemList 
#define EQItemList__EQItemList                             0x45423C
#define EQItemList__dEQItemList                            0x4542B8

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                      0x49B996

// CContainerWnd 
#define CContainerWnd__HandleCombine                       0x427CB6
#define CContainerWnd__vftable                             0x5DF7A0

// CSidlScreenWnd 
#define CSidlScreenWnd__CSidlScreenWnd1                    0x55A3E0
#define CSidlScreenWnd__dCSidlScreenWnd                    0x559A30
#define CSidlScreenWnd__CreateChildrenFromSidl             0x558CE0
#define CSidlScreenWnd__WndNotification                    0x558860
#define CSidlScreenWnd__CalculateHSBRange                  0x557E80
#define CSidlScreenWnd__CalculateVSBRange                  0x557DC0
#define CSidlScreenWnd__ConvertToRes                       0x558570
#define CSidlScreenWnd__CSidlScreenWnd2                    0x55A4D0
#define CSidlScreenWnd__DrawSidlPiece                      0x558900
#define CSidlScreenWnd__EnableIniStorage                   0x558520
#define CSidlScreenWnd__GetSidlPiece                       0x558BA0
#define CSidlScreenWnd__Init1                              0x55A130
#define CSidlScreenWnd__LoadIniInfo                        0x558D90
#define CSidlScreenWnd__LoadIniListWnd                     0x5596D0
#define CSidlScreenWnd__LoadSidlScreen                     0x558740
#define CSidlScreenWnd__SetScreen                          0x559B50
#define CSidlScreenWnd__StoreIniInfo                       0x5580B0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1             0x587870

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                        0x58BE10

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                       0x5785C0

// CXRect 
#define CXRect__CenterPoint                                0x40A881

// CXWnd 
#define CXWnd__BringToTop                                  0x55AB60
#define CXWnd__Center                                      0x55E1C0
#define CXWnd__ClrFocus                                    0x55A8B0
#define CXWnd__DoAllDrawing                                0x55EDD0
#define CXWnd__DrawChildren                                0x55EF00
#define CXWnd__DrawColoredRect                             0x55AD80
#define CXWnd__DrawTooltipAtPoint                          0x55DFF0
#define CXWnd__GetBorderFrame                              0x55B1D0
#define CXWnd__GetChildWndAt                               0x55DB80
#define CXWnd__GetClientClipRect                           0x55B110
#define CXWnd__GetFirstChildWnd                            0x55ABF0
#define CXWnd__GetNextChildWnd                             0x55DB60
#define CXWnd__GetNextSib                                  0x55AC10
#define CXWnd__GetScreenClipRect                           0x55E450
#define CXWnd__GetScreenRect                               0x55B3A0
#define CXWnd__GetTooltipRect                              0x55DF40
#define CXWnd__GetWindowTextA                              0x402A9A
// CHECK THIS ^^^^^^^^^^^^^^
#define CXWnd__GetXMLTooltip                               0x55A6F0
#define CXWnd__IsActive                                    0x55B180
#define CXWnd__IsDescendantOf                              0x55B190
#define CXWnd__IsReallyVisible                             0x55DB40
#define CXWnd__IsType                                      0x55ED70
#define CXWnd__Move                                        0x55D6F0
#define CXWnd__Move1                                       0x55D780
#define CXWnd__ProcessTransition                           0x55AB20
#define CXWnd__Refade                                      0x55A950
#define CXWnd__Resize                                      0x55E590
#define CXWnd__Right                                       0x55E330
#define CXWnd__SetFirstChildPointer                        0x55B5F0
#define CXWnd__SetFocus                                    0x55C8D0
#define CXWnd__SetKeyTooltip                               0x55B630
#define CXWnd__SetMouseOver                                0x55B610
#define CXWnd__SetNextSibPointer                           0x55B600
#define CXWnd__StartFade                                   0x55AB80

// CSliderWnd 
#define CSliderWnd__GetValue                               0x57AE80
#define CSliderWnd__SetValue                               0x57B060
#define CSliderWnd__UpdateThumb                            0x57AE40

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                          0x40A385
#define CEditBaseWnd__SetSel                               0x58AF70

// CComboWnd 
#define CComboWnd__DeleteAll                               0x57A400
#define CComboWnd__Draw                                    0x57A600
#define CComboWnd__GetButtonRect                           0x57A430
#define CComboWnd__GetCurChoice                            0x57A3C0
#define CComboWnd__GetListRect                             0x57A9F0
#define CComboWnd__GetTextRect                             0x57A490
#define CComboWnd__InsertChoice                            0x57AA50
#define CComboWnd__SetColors                               0x57A390
#define CComboWnd__SetChoice                               0x57AB30

// CListWnd 
#define CListWnd__AddColumn                                0x564010
#define CListWnd__AddColumn1                               0x563B70
#define CListWnd__AddLine                                  0x563730
#define CListWnd__AddString                                0x5638B0
#define CListWnd__CalculateFirstVisibleLine                0x560D20
#define CListWnd__CalculateVSBRange                        0x5628B0
#define CListWnd__ClearAllSel                              0x560480
#define CListWnd__CloseAndUpdateEditWindow                 0x561320
#define CListWnd__Compare                                  0x561660
#define CListWnd__Draw                                     0x562510
#define CListWnd__DrawColumnSeparators                     0x562360
#define CListWnd__DrawHeader                               0x5606A0
#define CListWnd__DrawItem                                 0x561D70
#define CListWnd__DrawLine                                 0x5620D0
#define CListWnd__DrawSeparator                            0x562430
#define CListWnd__EnsureVisible                            0x560D70
#define CListWnd__ExtendSel                                0x561CA0
#define CListWnd__GetColumnFlags                           0x55FF50
#define CListWnd__GetColumnJustification                   0x5600F0
#define CListWnd__GetColumnMinWidth                        0x560080
#define CListWnd__GetColumnWidth                           0x55FFB0
#define CListWnd__GetCurSel                                0x55FD90
#define CListWnd__GetHeaderRect                            0x55FBD0
#define CListWnd__GetItemAtPoint                           0x561020
#define CListWnd__GetItemAtPoint1                          0x561090
#define CListWnd__GetItemData                              0x55FDD0
#define CListWnd__GetItemHeight                            0x560AA0
#define CListWnd__GetItemIcon                              0x55FE90
#define CListWnd__GetItemRect                              0x560E40
#define CListWnd__GetItemText                              0x55FE10
#define CListWnd__GetSelList                               0x563A50
#define CListWnd__GetSeparatorRect                         0x5615B0
#define CListWnd__IsLineEnabled                            0x560570
#define CListWnd__RemoveLine                               0x563A00
#define CListWnd__SetColors                                0x55FB40
#define CListWnd__SetColumnWidth                           0x560030
#define CListWnd__SetColumnJustification                   0x560150
#define CListWnd__SetCurSel                                0x5603A0
#define CListWnd__SetItemColor                             0x563370
#define CListWnd__SetItemData                              0x560530
#define CListWnd__SetItemText                              0x5632B0
#define CListWnd__ShiftColumnSeparator                     0x561C10
#define CListWnd__Sort                                     0x5640B0
#define CListWnd__ToggleSel                                0x5603C0

// CEditWnd 
#define CEditWnd__DrawCaret                                0x57F1D0
#define CEditWnd__GetCharIndexPt                           0x580020
#define CEditWnd__GetDisplayString                         0x57F330
#define CEditWnd__GetHorzOffset                            0x57F5A0
#define CEditWnd__GetLineForPrintableChar                  0x57FAC0
#define CEditWnd__GetSelStartPt                            0x580260
#define CEditWnd__GetSTMLSafeText                          0x57F780
#define CEditWnd__PointFromPrintableChar                   0x57FBD0
#define CEditWnd__SelectableCharFromPoint                  0x57FD50
#define CEditWnd__SetEditable                              0x57F750

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                            0x4C7014
#define CGaugeWnd__CalcLinesFillRect                       0x4C7070
#define CGaugeWnd__Draw                                    0x4C7370

// CStmlWnd 
#define CStmlWnd__AppendSTML                               0x56D580
#define CStmlWnd__CalculateHSBRange                        0x564E70
#define CStmlWnd__CalculateVSBRange                        0x564E10
#define CStmlWnd__CanBreakAtCharacter                      0x564FB0
#define CStmlWnd__CanGoBackward                            0x565030
#define CStmlWnd__FastForwardToEndOfTag                    0x565D30
#define CStmlWnd__GetNextChar                              0x565480
#define CStmlWnd__GetNextTagPiece                          0x565B30
#define CStmlWnd__GetSTMLText                              0x4200D1
#define CStmlWnd__GetThisChar                              0x564CD0
#define CStmlWnd__GetVisiableText                          0x567500
#define CStmlWnd__InitializeWindowVariables                0x569300
#define CStmlWnd__MakeStmlColorTag                         0x5643A0
#define CStmlWnd__MakeWndNotificationTag                   0x564440
#define CStmlWnd__StripFirstSTMLLines                      0x56D300
#define CStmlWnd__UpdateHistoryString                      0x567940

// CTabWnd 
#define CTabWnd__Draw                                      0x571290
#define CTabWnd__DrawCurrentPage                           0x570D80
#define CTabWnd__DrawTab                                   0x570B00
#define CTabWnd__GetCurrentPage                            0x5706B0
#define CTabWnd__GetCurrentTabIndex                        0x570490
#define CTabWnd__GetNumTabs                                0x570580
#define CTabWnd__GetPageClientRect                         0x5704A0
#define CTabWnd__GetPageFromTabIndex                       0x5705B0
#define CTabWnd__GetPageInnerRect                          0x570500
#define CTabWnd__GetTabInnerRect                           0x5707C0
#define CTabWnd__GetTabRect                                0x5706C0
#define CTabWnd__IndexInBounds                             0x570590
#define CTabWnd__InsertPage                                0x571180
#define CTabWnd__SetPage                                   0x570860
#define CTabWnd__SetPageRect                               0x570970
#define CTabWnd__UpdatePage                                0x570A20

// CTextOverlay 
#define CTextOverlay__DisplayText                          0x411930

/* 
CListWnd__GetCurCol 

CContextMenu__CContextMenu 
CContextMenu__AddMenuItem 
CContextMenu__AddSeparator 
CContextMenu__RemoveAllMenuItems 
CContextMenu__Activate 
/**/ 

