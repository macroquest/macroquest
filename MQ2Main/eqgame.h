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
#define __ExpectedVersionDate							   "Sep 13 2004" 
#define __ExpectedVersionTime							   "17:08:38" 
#define __ActualVersionDate                                0x5ECB2C
#define __ActualVersionTime                                0x5ECB38

#define __ClientOverride								   0 
#define __MacroQuestWinClassName						   "__MacroQuestTray" 
#define __MacroQuestWinName								   "MacroQuest" 

// Memory Protection 
#define __MemChecker0                                      0x524CCE
#define __MemChecker1                                      0x529FAA
#define __MemChecker2                                      0x52DE1D
#define __MemChecker3                                      0x52DEAA
#define __EncryptPad0                                      0x70B540
#define __EncryptPad1                                      0x70B940
#define __EncryptPad2                                      0x70C430
#define __EncryptPad3                                      0x70C830

#define DI8__Main                                          0x8A3F44
#define DI8__Keyboard                                      0x8A3F48
#define DI8__Mouse                                         0x8A3F4C

#define __LastTell                                         0x7D9E5C
#define __Guilds                                           0x83A560
#define __Mouse                                            0x8A3F50
#define __Attack                                           0x8386D8
#define __InChatMode                                       0x7D7D30
#define __gWorld                                           0x83A4B8
#define __GroupCount                                       0x838A68
#define __CommandList                                      0x6111B0
#define __DoAbilityList                                    0x811930
#define __DoAbilityAvailable                               0x7D8B74
#define __ServerHost                                       0x838924
#define __ServerName                                       0x8118F0
#define __HWnd                                             0x7D7CF0
#define __Clicks                                           0x7D7DF4
#define __ScreenX                                          0x7D7CF8
#define __ScreenY                                          0x7D7CFC
#define __ScreenMode                                       0x723C08
#define __MouseLook                                        0x7D7DC2
#define __EQP_IDArray                                      0x726030
#define __CurrentMapLabel                                  0x888E78
#define __BindList                                         0x610C50
#define __RangeAttackReady                                 0x7D8BD8
#define __AltTimerReady                                    0x7D8BDA
#define __Socials                                          0x8119F0
#define __HotkeyPage                                       0x838290
#define __CurrentSocial                                    0x614480
#define __GroupLeader                                      0x838BC4
#define __SkillDict                                        0x729338
#define __DrawHandler                                      0x8AD91C
#define __FriendsList                                      0x80E6F0
#define __IgnoreList                                       0x80FFF0
#define __NetStatusToggle                                  0x7D7DC4
#define __ShowNames                                        0x7D8DBC
#define __PCNames                                          0x7D8E6C
//// 
//Section 1: Vital Offsets 
//// 
#define pinstCSidlManager                                  0x8AD3A4
#define pinstCDisplay                                      0x83A544
#define pinstCEverQuest                                    0x8A40B8
#define pinstPCData                                        0x83A520
#define pinstCharData                                      0x83A520
#define pinstCharSpawn                                     0x83A518
#define pinstSpawnList                                     0x83A4E0
#define pinstLocalPlayer                                   0x83A504
#define pinstControlledPlayer                              0x83A518
#define pinstWorldData                                     0x83A4DC
#define pinstSpellManager                                  0x896174
#define pinstTradeTarget                                   0x83A500
#define pinstActiveMerchant                                0x83A530
#define pinstActiveBanker                                  0x83A534
#define pinstActiveCorpse                                  0x83A538
#define pinstActiveGMaster                                 0x83A53C
#define pinstSelectedItem                                  0x888B00
#define pinstGroup                                         0x838BB0
#define pinstTarget                                        0x83A524
#define pinstSwitchManager                                 0x728F50
#define pinstEQItemList                                    0x83A4E4
#define pinstSpellSets                                     0x838294
#define instEQZoneInfo                                     0x7D7F60
#define pinstCXWndManager                                  0x8AD39C
#define instKeypressHandler                                0x888B6C
#define pinstStringTable                                   0x83A4D0
#define pinstAltAdvManager                                 0x728F54
#define instCRaid                                          0x842818

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                  0x712550
#define pinstCharacterSelect                               0x72469C
#define pinstCFacePick                                     0x7246A0
// removed 4-14 exe #define pinstCTextMessageWnd                                
#define pinstCNoteWnd                                      0x7246A4
#define pinstCHelpWnd                                      0x7246A8
#define pinstCBookWnd                                      0x7246AC
#define pinstCPetInfoWnd                                   0x7246B0
#define pinstCTrainWnd                                     0x7246B4
#define pinstCSkillsWnd                                    0x7246B8
#define pinstCSkillsSelectWnd                              0x7246BC
#define pinstCCombatSkillSelectWnd                         0x7246C0
#define pinstCFriendsWnd                                   0x7246C4
#define pinstCAAWnd                                        0x7246C8
#define pinstCGroupSearchFiltersWnd                        0x7246CC
#define pinstCLoadskinWnd                                  0x7246D0
#define pinstCAlarmWnd                                     0x7246D4
#define pinstCMusicPlayerWnd                               0x7246D8
#define pinstCRaidWnd                                      0x7246E4
#define pinstCRaidOptionsWnd                               0x7246E8
#define pinstCBreathWnd                                    0x7246EC
#define pinstCMapViewWnd                                   0x7246F0
#define pinstCMapToolbarWnd                                0x7246F4
#define pinstCEditLabelWnd                                 0x7246F8
#define pinstCTargetWnd                                    0x7246FC
#define pinstCHotButtonWnd                                 0x724700
#define pinstCColorPickerWnd                               0x724704
#define pinstCPlayerWnd                                    0x724708
#define pinstCOptionsWnd                                   0x72470C
#define pinstCBuffWindowNORMAL                             0x724710
#define pinstCBuffWindowSHORT                              0x724714
#define pinstCharacterCreation                             0x724718
#define pinstCCursorAttachment                             0x72471C
#define pinstCCastingWnd                                   0x724720
#define pinstCCastSpellWnd                                 0x724724
#define pinstCSpellBookWnd                                 0x724728
#define pinstCInventoryWnd                                 0x72472C
#define pinstCBankWnd                                      0x724730
#define pinstCQuantityWnd                                  0x724734
#define pinstCLootWnd                                      0x724738
#define pinstCActionsWnd                                   0x72473C
#define pinstCCombatAbilityWnd                             0x724740
#define pinstCMerchantWnd                                  0x724744
#define pinstCTradeWnd                                     0x724748
#define pinstCSelectorWnd                                  0x72474C
#define pinstCBazaarWnd                                    0x724750
#define pinstCBazaarSearchWnd                              0x724754
#define pinstCGiveWnd                                      0x724758
#define pinstCTrackingWnd                                  0x72475C
#define pinstCInspectWnd                                   0x724760
#define pinstCSocialEditWnd                                0x724764
#define pinstCFeedbackWnd                                  0x724768
#define pinstCBugReportWnd                                 0x72476C
#define pinstCVideoModesWnd                                0x724770
#define pinstCTextEntryWnd                                 0x724778
#define pinstCFileSelectionWnd                             0x72477C
#define pinstCCompassWnd                                   0x724780
#define pinstCPlayerNotesWnd                               0x724784
#define pinstCGemsGameWnd                                  0x724788
#define pinstCTimeLeftWnd                                  0x72478C
#define pinstCPetitionQWnd                                 0x724790
#define pinstCSoulmarkWnd                                  0x724794
#define pinstCStoryWnd                                     0x724798
#define pinstCJournalTextWnd                               0x72479C
#define pinstCJournalCatWnd                                0x7247A0
#define pinstCBodyTintWnd                                  0x7247A4
#define pinstCInvSlotMgr                                   0x7247A8
#define pinstCContainerMgr                                 0x7247AC
#define pinstCAdventureLeaderboardWnd                      0x7122E0
#define pinstCAdventureMerchantWnd                         0x7122F8
#define pinstCAdventureRequestWnd                          0x712310
#define pinstCAdventureStatsWnd                            0x712328
#define pinstCChatManager                                  0x7125F8
#define pinstCDynamicZoneWnd                               0x7248B0
#define pinstCFindLocationWnd                              0x88897C
#define pinstCGroupSearchWnd                               0x888A3C
#define pinstCGroupWnd                                     0x888A54
#define pinstCGuildMgmtWnd                                 0x888A6C
#define pinstCItemDisplayManager                           0x888B2C
#define pinstCLeadershipWnd                                0x888BF8
#define pinstCPopupWndManager                              0x889F88
#define pinstCSystemInfoDialogBox                          0x896DD4
#define pinstCTargetOfTargetWnd                            0x896DF4
#define pinstCTipWndOFDAY                                  0x896EC0
#define pinstCTipWndCONTEXT                                0x896EC4
#define pinstCTradeskillWnd                                0x896FB0
#define pinstCTributeBenefitWnd                            0x896FF0
#define pinstCTributeMasterWnd                             0x897008
#define pinstCContextMenuManager                           0x8AD434
// unknown window added 4-14 exe 0x79A234 


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define DrawNetStatus                                      0x4F0C4D
#define CrashDetected                                      0x52DAD9
#define __ProcessGameEvents                                0x4BA52D
#define __ConvertItemTags                                  0x45C5E4
#define __SendMessage                                      0x50A78F
#define __NewUIINI                                         0x512DD3
#define __ExecuteCmd                                       0x450DAA
#define __GetGaugeValueFromEQ                              0x5113EE
#define __get_melee_range                                  0x455365
#define __CastRay                                          0x45D269
#define __LoadSplashScreen								   0x5AB3E0

// EQ_LoadingS 
#define EQ_LoadingS__WriteTextHD                           0x497131


//// 
// Section 4: Function Offsets 
//// 
// CEverQuest 
#define CEverQuest__dsp_chat                               0x4A9559
#define CEverQuest__ClickedPlayer                          0x4A726A
#define CEverQuest__EnterZone                              0x4AA212
#define CEverQuest__GetBodyTypeDesc                        0x4A30CE
#define CEverQuest__GetClassDesc                           0x4A2B50
#define CEverQuest__GetClassThreeLetterCode                0x4A2F6B
#define CEverQuest__GetDeityDesc                           0x4A4B61
#define CEverQuest__GetRaceDesc                            0x4A33D3
#define CEverQuest__InterpretCmd                           0x4B6D5B
#define CEverQuest__LeftClickedOnPlayer                    0x4B8FB1
#define CEverQuest__RightClickedOnPlayer                   0x4B1564
#define CEverQuest__SetGameState                           0x4A733D
#define CEverQuest__DropHeldItemOnGround                   0x4A8F03

// StringTable 
#define StringTable__getString                             0x511045

// AltAdvManager 
#define AltAdvManager__IsAbilityReady                      0x480C9A
#define AltAdvManager__GetCalculatedTimer				   0x480C6C

// CXWndManager 
#define CXWndManager__RemoveWnd                            0x577A10
#define CXWndManager__GetKeyboardFlags                     0x577630
#define CXWndManager__HandleKeyboardMsg                    0x577B00
#define CXWndManager__DrawWindows                          0x578870
#define CXWndManager__DrawCursor                           0x578C20
#define CXWndManager__GetFirstChildWnd                     0x5781F0

// KeyPressHandler 
#define KeypressHandler__HandleKeyDown                     0x4E1E3C
#define KeypressHandler__HandleKeyUp                       0x4E20B3
#define KeypressHandler__AttachKeyToEqCommand              0x4E3159
#define KeypressHandler__AttachAltKeyToEqCommand           0x4E318C
#define KeypressHandler__SaveKeymapping                    0x4E3029
#define KeypressHandler__ClearCommandStateArray            0x4E2FA4

// EQ_Character 
#define EQ_Character__Max_Endurance                        0x48193E
#define EQ_Character__Max_HP                               0x4816EB
#define EQ_Character__Cur_HP                               0x485229
#define EQ_Character__GetFocusCastingTimeModifier          0x48CC24
#define EQ_Character__GetAACastingTimeModifier             0x48D07F
#define EQ_Character__CastSpell                            0x490775
#define EQ_Character__Max_Mana                             0x499594 

// EQPlayer 
#define EQPlayer__EQPlayer                                 0x474733
#define EQPlayer__dEQPlayer                                0x473FDC
#define EQPlayer__DoAttack                                 0x471984
#define EQPlayer__ChangeBoneStringSprite                   0x469D2C
#define EQPlayer__SetNameSpriteState                       0x46E363
#define EQPlayer__SetNameSpriteTint                        0x469D98

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                       0x401000
#define CXStr__CXStr1                                      0x4F157B
#define CXStr__CXStr3                                      0x5A48E0
#define CXStr__dCXStr                                      0x40A826
#define CXStr__operator_plus_equal1                        0x5A58E0
#define CXStr__operator_equal1                             0x5A4AA0

// CChatWindow 
#define CChatWindow__CChatWindow                           0x41FDB2

// CChatManager 
#define CChatManager__GetRGBAFromIndex                     0x41D075
#define CChatManager__InitContextMenu                      0x41D159

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                           0x4D7642
#define CInvSlotMgr__MoveItem                              0x4D7A7A

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                           0x4DBF93
#define CItemDisplayWnd__SetSpell                          0x4DB18C

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                         0x4D42EA

// CLabel 
#define CLabel__Draw                                       0x4E3321

// CGauge 
#define CGaugeWnd__Draw                                    0x4C5D94

// CDisplay 
#define CDisplay__ReloadUI                                 0x43D6F2
#define CDisplay__CleanGameUI                              0x436017
#define CDisplay__GetClickedActor                          0x433114
#define CDisplay__WriteTextHD2                             0x436B94
#define CDisplay__GetWorldFilePath                         0x431DE7
#define CDisplay__GetUserDefinedColor                      0x4325DB

#define CTextureFont__DrawWrappedText                      0x55B4B0

// EQ_Item 
#define EQ_Item__GetItemLinkHash                           0x4966AC
#define EQ_Item__CanDrop                                   0x496AB3

// CBankWnd 
#define CBankWnd__GetNumBankSlots                          0x40AFA2

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                  0x40D468

// CMerchantWnd 
#define CMerchantWnd__SelectBuySellSlot                    0x4EED90
#define CMerchantWnd__RequestBuyItem                       0x4EEEC3
#define CMerchantWnd__RequestSellItem                      0x4EF0CB
#define CMerchantWnd__DisplayBuyOrSellPrice                0x4EE1F6

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                         0x50F47D

// MapViewMap 
#define MapViewMap__SaveEx                                 0x4EA93A
#define MapViewMap__Clear                                  0x4EA1A8


// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                           0x4ED49B

// EQItemList 
#define EQItemList__EQItemList                             0x4537CC
#define EQItemList__dEQItemList                            0x453848

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                      0x49A522

// CContainerWnd 
#define CContainerWnd__HandleCombine                       0x427840
#define CContainerWnd__vftable                             0x5D5750

// CSidlScreenWnd 
#define CSidlScreenWnd__CSidlScreenWnd1                    0x5562F0
#define CSidlScreenWnd__dCSidlScreenWnd                    0x555990
#define CSidlScreenWnd__CreateChildrenFromSidl             0x554D00
#define CSidlScreenWnd__WndNotification                    0x554880
#define CSidlScreenWnd__CalculateHSBRange                  0x553EA0
#define CSidlScreenWnd__CalculateVSBRange                  0x553DE0
#define CSidlScreenWnd__ConvertToRes                       0x554590
#define CSidlScreenWnd__CSidlScreenWnd2                    0x5563E0
#define CSidlScreenWnd__DrawSidlPiece                      0x554920
#define CSidlScreenWnd__EnableIniStorage                   0x554540
#define CSidlScreenWnd__GetSidlPiece                       0x554BC0
#define CSidlScreenWnd__Init1                              0x556040
#define CSidlScreenWnd__LoadIniInfo                        0x554DB0
#define CSidlScreenWnd__LoadIniListWnd                     0x5556F0
#define CSidlScreenWnd__LoadSidlScreen                     0x554760
#define CSidlScreenWnd__SetScreen                          0x555AB0
#define CSidlScreenWnd__StoreIniInfo                       0x5540D0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1             0x583640

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                        0x587C40

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                       0x574540

// CXRect 
#define CXRect__CenterPoint                                0x40A83A

// CXWnd 
#define CXWnd__BringToTop                                  0x556A70
#define CXWnd__Center                                      0x55A0E0
#define CXWnd__ClrFocus                                    0x5567C0
#define CXWnd__DoAllDrawing                                0x55ACF0
#define CXWnd__DrawChildren                                0x55AE20
#define CXWnd__DrawColoredRect                             0x556CB0
#define CXWnd__DrawTooltipAtPoint                          0x559F10
#define CXWnd__GetBorderFrame                              0x5570F0
#define CXWnd__GetChildWndAt                               0x559AA0
#define CXWnd__GetClientClipRect                           0x557040
#define CXWnd__GetFirstChildWnd                            0x556B00
#define CXWnd__GetNextChildWnd                             0x559A80
#define CXWnd__GetNextSib                                  0x556B20
#define CXWnd__GetScreenClipRect                           0x55A370
#define CXWnd__GetScreenRect                               0x5572C0
#define CXWnd__GetTooltipRect                              0x559E60
#define CXWnd__GetWindowTextA                              0x402A7C
// CHECK THIS ^^^^^^^^^^^^^^
#define CXWnd__GetXMLTooltip                               0x556600
#define CXWnd__IsActive                                    0x5570B0
#define CXWnd__IsDescendantOf                              0x5570C0
#define CXWnd__IsReallyVisible                             0x559A60
#define CXWnd__IsType                                      0x55AC90
#define CXWnd__Move                                        0x559610
#define CXWnd__Move1                                       0x5596A0
#define CXWnd__ProcessTransition                           0x556A30
#define CXWnd__Refade                                      0x556860
#define CXWnd__Resize                                      0x55A4B0
#define CXWnd__Right                                       0x55A250
#define CXWnd__SetFirstChildPointer                        0x557510
#define CXWnd__SetFocus                                    0x5587F0
#define CXWnd__SetKeyTooltip                               0x557550
#define CXWnd__SetMouseOver                                0x557530
#define CXWnd__SetNextSibPointer                           0x557520
#define CXWnd__StartFade                                   0x556A90

// CSliderWnd 
#define CSliderWnd__GetValue                               0x576DE0
#define CSliderWnd__SetValue                               0x576FC0
#define CSliderWnd__UpdateThumb                            0x576DA0

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                          0x40A33E
#define CEditBaseWnd__SetSel                               0x586D50

// CComboWnd 
#define CComboWnd__DeleteAll                               0x576370
#define CComboWnd__Draw                                    0x576570
#define CComboWnd__GetButtonRect                           0x5763A0
#define CComboWnd__GetCurChoice                            0x576330
#define CComboWnd__GetListRect                             0x576960
#define CComboWnd__GetTextRect                             0x576400
#define CComboWnd__InsertChoice                            0x5769C0
#define CComboWnd__SetColors                               0x576300
#define CComboWnd__SetChoice                               0x576AA0

// CListWnd 
#define CListWnd__AddColumn                                0x55FEF0
#define CListWnd__AddColumn1                               0x55FA40
#define CListWnd__AddLine                                  0x55F600
#define CListWnd__AddString                                0x55F780
#define CListWnd__CalculateFirstVisibleLine                0x55CBF0
#define CListWnd__CalculateVSBRange                        0x55E780
#define CListWnd__ClearAllSel                              0x55C350
#define CListWnd__CloseAndUpdateEditWindow                 0x55D1F0
#define CListWnd__Compare                                  0x55D530
#define CListWnd__Draw                                     0x55E3E0
#define CListWnd__DrawColumnSeparators                     0x55E230
#define CListWnd__DrawHeader                               0x55C570
#define CListWnd__DrawItem                                 0x55DC40
#define CListWnd__DrawLine                                 0x55DFA0
#define CListWnd__DrawSeparator                            0x55E300
#define CListWnd__EnsureVisible                            0x55CC40
#define CListWnd__ExtendSel                                0x55DB70
#define CListWnd__GetColumnFlags                           0x55BE20
#define CListWnd__GetColumnJustification                   0x55BFC0
#define CListWnd__GetColumnMinWidth                        0x55BF50
#define CListWnd__GetColumnWidth                           0x55BE80
#define CListWnd__GetCurSel                                0x55BC60
#define CListWnd__GetHeaderRect                            0x55BAA0
#define CListWnd__GetItemAtPoint                           0x55CEF0
#define CListWnd__GetItemAtPoint1                          0x55CF60
#define CListWnd__GetItemData                              0x55BCA0
#define CListWnd__GetItemHeight                            0x55C970
#define CListWnd__GetItemIcon                              0x55BD60
#define CListWnd__GetItemRect                              0x55CD10
#define CListWnd__GetItemText                              0x55BCE0
#define CListWnd__GetSelList                               0x55F920
#define CListWnd__GetSeparatorRect                         0x55D480
#define CListWnd__IsLineEnabled                            0x55C440
#define CListWnd__RemoveLine                               0x55F8D0
#define CListWnd__SetColors                                0x55BA10
#define CListWnd__SetColumnWidth                           0x55BF00
#define CListWnd__SetColumnJustification                   0x55C020
#define CListWnd__SetCurSel                                0x55C270
#define CListWnd__SetItemColor                             0x55F240
#define CListWnd__SetItemData                              0x55C400
#define CListWnd__SetItemText                              0x55F180
#define CListWnd__ShiftColumnSeparator                     0x55DAE0
#define CListWnd__Sort                                     0x55FF90
#define CListWnd__ToggleSel                                0x55C290

// CEditWnd 
#define CEditWnd__DrawCaret                                0x57B0B0
#define CEditWnd__GetCharIndexPt                           0x57BED0
#define CEditWnd__GetDisplayString                         0x57B1E0
#define CEditWnd__GetHorzOffset                            0x57B450
#define CEditWnd__GetLineForPrintableChar                  0x57B970
#define CEditWnd__GetSelStartPt                            0x57C110
#define CEditWnd__GetSTMLSafeText                          0x57B630
#define CEditWnd__PointFromPrintableChar                   0x57BA80
#define CEditWnd__SelectableCharFromPoint                  0x57BC00
#define CEditWnd__SetEditable                              0x57B600

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                            0x4C5A38
#define CGaugeWnd__CalcLinesFillRect                       0x4C5A94
#define CGaugeWnd__Draw                                    0x4C5D94

// CStmlWnd 
#define CStmlWnd__AppendSTML                               0x569400
#define CStmlWnd__CalculateHSBRange                        0x560D50
#define CStmlWnd__CalculateVSBRange                        0x560CF0
#define CStmlWnd__CanBreakAtCharacter                      0x560E90
#define CStmlWnd__CanGoBackward                            0x560F10
#define CStmlWnd__FastForwardToEndOfTag                    0x561C20
#define CStmlWnd__GetNextChar                              0x561370
#define CStmlWnd__GetNextTagPiece                          0x561A20
#define CStmlWnd__GetSTMLText                              0x41FD94
#define CStmlWnd__GetThisChar                              0x560BB0
#define CStmlWnd__GetVisiableText                          0x5633F0
#define CStmlWnd__InitializeWindowVariables                0x565180
#define CStmlWnd__MakeStmlColorTag                         0x560280
#define CStmlWnd__MakeWndNotificationTag                   0x560320
#define CStmlWnd__StripFirstSTMLLines                      0x569180
#define CStmlWnd__UpdateHistoryString                      0x563830

// CTabWnd 
#define CTabWnd__Draw                                      0x56D1E0
#define CTabWnd__DrawCurrentPage                           0x56CCD0
#define CTabWnd__DrawTab                                   0x56CA50
#define CTabWnd__GetCurrentPage                            0x56C600
#define CTabWnd__GetCurrentTabIndex                        0x56C290
#define CTabWnd__GetNumTabs                                0x56C450
#define CTabWnd__GetPageClientRect                         0x56C2A0
#define CTabWnd__GetPageFromTabIndex                       0x56C480
#define CTabWnd__GetPageInnerRect                          0x56C300
#define CTabWnd__GetTabInnerRect                           0x56C710
#define CTabWnd__GetTabRect                                0x56C610
#define CTabWnd__IndexInBounds                             0x56C460
#define CTabWnd__InsertPage                                0x56D0D0
#define CTabWnd__SetPage                                   0x56C7B0
#define CTabWnd__SetPageRect                               0x56C8C0
#define CTabWnd__UpdatePage                                0x56C970

// CTextOverlay 
#define CTextOverlay__DisplayText                          0x4118D8

/* 
CListWnd__GetCurCol 

CContextMenu__CContextMenu 
CContextMenu__AddMenuItem 
CContextMenu__AddSeparator 
CContextMenu__RemoveAllMenuItems 
CContextMenu__Activate 
/**/ 

