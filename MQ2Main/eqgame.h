/******************************************************************************
    MQ2Main.dll: MacroQuest2's extension DLL for EverQuest
    Copyright (C) 2002-2003 Plazmic, 2003-2005 Lax

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License, version 2, as 
published by
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
#define __ExpectedVersionDate                             "Jun 27 2005"
#define __ExpectedVersionTime                             "20:30:51"
#define __ActualVersionDate                                0x62BAF4
#define __ActualVersionTime                                0x62BB00

#define __ClientOverride                                   0
#define __MacroQuestWinClassName                          "__MacroQuestTray"
#define __MacroQuestWinName                               "MacroQuest"

// Memory Protection
#define __MemChecker0                                      0x5184F7
#define __MemChecker2                                      0x559E6B
#define __MemChecker3                                      0x559EF8
#define __MemChecker4                                      0x5D4510
#define __EncryptPad0                                      0x7538A8
#define __EncryptPad2                                      0x757220
#define __EncryptPad3                                      0x757620
#define __EncryptPad4                                      0x75CF70

// Direct Input
#define DI8__Main                                          0x954F8C
#define DI8__Keyboard                                      0x954F90
#define DI8__Mouse                                         0x954F94

#define __AltTimerReady                                    0x8C7836
#define __Attack                                           0x927350
#define __BindList                                         0x65BEA8
#define __Clicks                                           0x8C6A3C
#define __CommandList                                      0x65C448
#define __CurrentMapLabel                                  0x94728C
#define __CurrentSocial                                    0x65F8E8
#define __DoAbilityAvailable                               0x8C77D0
#define __DoAbilityList                                    0x9005A8
#define __DrawHandler                                      0x95EFD4
#define __EQP_IDArray                                      0x814BD8
#define __FriendsList                                      0x8FD368
#define __GroupCount                                       0x9276E0
#define __GroupLeader                                      0x92783C
#define __Guilds                                           0x92F128
#define __gWorld                                           0x929138
#define __HotkeyPage                                       0x926F08
#define __HWnd                                             0x8C6938
#define __IgnoreList                                       0x8FEC68
#define __InChatMode                                       0x8C6978
#define __LastTell                                         0x8C8AD4
#define __Mouse                                            0x954F98
#define __MouseLook                                        0x8C6A0A
#define __NetStatusToggle                                  0x8C6A0C
#define __PCNames                                          0x8C7B2C
#define __RangeAttackReady                                 0x8C7834
#define __RunWalkState                                     0x8C697C
#define __ScreenMode                                       0x812750
#define __ScreenX                                          0x8C6940
#define __ScreenY                                          0x8C6944
#define __ServerHost                                       0x92759C
#define __ServerName                                       0x900568
#define __ShowNames                                        0x8C7A1C
#define __SkillDict                                        0x817F68
#define __Socials                                          0x900668

////
//Section 1: Vital Offsets
////
#define instCRaid                                          0x9291D0
#define instEQZoneInfo                                     0x8C6BA8
#define instKeypressHandler                                0x946F20
#define pinstActiveBanker                                  0x9291B0
#define pinstActiveCorpse                                  0x9291B4
#define pinstActiveGMaster                                 0x9291B8
#define pinstActiveMerchant                                0x9291AC
#define pinstAltAdvManager                                 0x817B10
#define pinstCDisplay                                      0x9291C0
#define pinstCEverQuest                                    0x955100
#define pinstCharData                                      0x92919C
#define pinstCharSpawn                                     0x929194
#define pinstControlledPlayer                              0x929194
#define pinstCSidlManager                                  0x95E3DC
#define pinstCXWndManager                                  0x95E3D4
#define pinstEQItemList                                    0x929160
#define instGroup                                          0x9276E0
#define pinstLocalPlayer                                   0x929180
#define pinstPCData                                        0x92919C
#define pinstSelectedItem                                  0x946EA0
#define pinstSpawnList                                     0x92915C
#define pinstSpellManager                                  0x947608
#define pinstSpellSets                                     0x926F0C
#define pinstStringTable                                   0x929148
#define pinstSwitchManager                                 0x817B0C
#define pinstTarget                                        0x9291A0
#define pinstTargetSwitch                                  0x9291A8
#define pinstTradeTarget                                   0x92917C
#define instTributeActive                                  0x8125BD
#define pinstWorldData                                     0x929158


////
//Section 2:  UI Related Offsets
////
#define pinstCTextOverlay                                  0x75EBD8
#define pinstCharacterSelect                               0x8131E4
#define pinstCFacePick                                     0x8131E8
#define pinstCNoteWnd                                      0x8131EC
#define pinstCBookWnd                                      0x8131F0
#define pinstCPetInfoWnd                                   0x8131F4
#define pinstCTrainWnd                                     0x8131F8
#define pinstCSkillsWnd                                    0x8131FC
#define pinstCSkillsSelectWnd                              0x813200
#define pinstCCombatSkillSelectWnd                         0x813204
#define pinstCFriendsWnd                                   0x813208
#define pinstCAAWnd                                        0x813214
#define pinstCGroupSearchFiltersWnd                        0x813218
#define pinstCLoadskinWnd                                  0x81321C
#define pinstCAlarmWnd                                     0x813220
#define pinstCMusicPlayerWnd                               0x813224
#define pinstCRaidWnd                                      0x813234
#define pinstCRaidOptionsWnd                               0x813238
#define pinstCBreathWnd                                    0x81323C
#define pinstCMapViewWnd                                   0x813240
#define pinstCMapToolbarWnd                                0x813244
#define pinstCEditLabelWnd                                 0x813248
#define pinstCTargetWnd                                    0x81324C
#define pinstCHotButtonWnd                                 0x813250
#define pinstCColorPickerWnd                               0x813254
#define pinstCPlayerWnd                                    0x813258
#define pinstCOptionsWnd                                   0x81325C
#define pinstCBuffWindowNORMAL                             0x813260
#define pinstCBuffWindowSHORT                              0x813264
#define pinstCharacterCreation                             0x813268
#define pinstCCursorAttachment                             0x81326C
#define pinstCCastingWnd                                   0x813270
#define pinstCCastSpellWnd                                 0x813274
#define pinstCSpellBookWnd                                 0x813278
#define pinstCInventoryWnd                                 0x81327C
#define pinstCBankWnd                                      0x813280
#define pinstCQuantityWnd                                  0x813284
#define pinstCLootWnd                                      0x813288
#define pinstCActionsWnd                                   0x81328C
#define pinstCCombatAbilityWnd                             0x813290
#define pinstCMerchantWnd                                  0x813294
#define pinstCTradeWnd                                     0x813298
#define pinstCSelectorWnd                                  0x81329C
#define pinstCBazaarWnd                                    0x8132A0
#define pinstCBazaarSearchWnd                              0x8132A4
#define pinstCGiveWnd                                      0x8132A8
#define pinstCTrackingWnd                                  0x8132AC
#define pinstCInspectWnd                                   0x8132B0
#define pinstCSocialEditWnd                                0x8132B4
#define pinstCFeedbackWnd                                  0x8132B8
#define pinstCBugReportWnd                                 0x8132BC
#define pinstCVideoModesWnd                                0x8132C0
#define pinstCTextEntryWnd                                 0x8132C8
#define pinstCFileSelectionWnd                             0x8132CC
#define pinstCCompassWnd                                   0x8132D0
#define pinstCPlayerNotesWnd                               0x8132D4
#define pinstCGemsGameWnd                                  0x8132D8
#define pinstCTimeLeftWnd                                  0x8132DC
#define pinstCPetitionQWnd                                 0x8132E0
#define pinstCSoulmarkWnd                                  0x8132E4
#define pinstCStoryWnd                                     0x8132E8
#define pinstCJournalTextWnd                               0x8132EC
#define pinstCJournalCatWnd                                0x8132F0
#define pinstCBodyTintWnd                                  0x8132F4
#define pinstCInvSlotMgr                                   0x813300
#define pinstCContainerMgr                                 0x813304
#define pinstCAdventureLeaderboardWnd                      0x75E86C
#define pinstCAdventureMerchantWnd                         0x75E888
#define pinstCAdventureRequestWnd                          0x75E8A4
#define pinstCAdventureStatsWnd                            0x75E8C0
#define pinstCChatManager                                  0x7602DC
#define pinstCDynamicZoneWnd                               0x813414
#define pinstCFindLocationWnd                              0x946CBC
#define pinstCGroupSearchWnd                               0x946DB4
#define pinstCGroupWnd                                     0x946DD0
#define pinstCGuildMgmtWnd                                 0x946E08
#define pinstCItemDisplayManager                           0x946ED4
#define pinstCLeadershipWnd                                0x946FBC
#define pinstCPopupWndManager                              0x947400
#define pinstCSystemInfoDialogBox                          0x947DB0
#define pinstCTargetOfTargetWnd                            0x947DD4
#define pinstCTipWndOFDAY                                  0x947EE0
#define pinstCTipWndCONTEXT                                0x947EE4
#define pinstCTradeskillWnd                                0x947FE0
#define pinstCTributeBenefitWnd                            0x94802C
#define pinstCTributeMasterWnd                             0x948048
#define pinstCContextMenuManager                           0x95E434
// unknown window added 4-14 exe 0x79A234


////
// Section 3: Miscellaneous Offsets
////
#define __CastRay                                          0x476883
#define __ConvertItemTags                                  0x4760A0
#define __ExecuteCmd                                       0x468912
#define __get_melee_range                                  0x46CCCA
#define __GetGaugeValueFromEQ                              0x541235
#define __GetLabelFromEQ                                   0x541D04
#define __LoadSplashScreen                                 0x5DC190
#define __NewUIINI                                         0x541B0D
#define __ProcessGameEvents                                0x4D8433
#define __SendMessage                                      0x4BF45B
#define CrashDetected                                      0x559B27
#define DrawNetStatus                                      0x51DE2A


////
// Section 4: Function Offsets
////
// AltAdvManager
#define AltAdvManager__GetCalculatedTimer                  0x49ABBC
#define AltAdvManager__IsAbilityReady                      0x49ABEA
#define AltAdvManager__GetAltAbility                       0x49ACFF

// CBankWnd
#define CBankWnd__GetNumBankSlots                          0x40CD0E

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg                  0x414A5F

// CButtonWnd
#define CButtonWnd__SetCheck                               0x59BCF0

// CChatManager
#define CChatManager__GetRGBAFromIndex                     0x426D43
#define CChatManager__InitContextMenu                      0x426E27

// CChatWindow
#define CChatWindow__CChatWindow                           0x42A895

// CComboWnd
#define CComboWnd__DeleteAll                               0x59C810
#define CComboWnd__Draw                                    0x59CA00
#define CComboWnd__GetButtonRect                           0x59C840
#define CComboWnd__GetCurChoice                            0x59C7D0
#define CComboWnd__GetListRect                             0x59CCA0
#define CComboWnd__GetTextRect                             0x59C890
#define CComboWnd__InsertChoice                            0x59CD00
#define CComboWnd__SetColors                               0x59C760
#define CComboWnd__SetChoice                               0x59C790

// CContainerWnd
#define CContainerWnd__HandleCombine                       0x43B1FA
#define CContainerWnd__vftable                             0x611FA0

// CDisplay
#define CDisplay__CleanGameUI                              0x44A738
#define CDisplay__GetClickedActor                          0x44725E
#define CDisplay__GetUserDefinedColor                      0x4467C2
#define CDisplay__GetWorldFilePath                         0x445F96
#define CDisplay__ReloadUI                                 0x452ACC
#define CDisplay__WriteTextHD2                             0x44BA83

// CEditBaseWnd
#define CEditBaseWnd__SetMaxChars                          0x408C0E
#define CEditBaseWnd__SetSel                               0x5AC140

// CEditWnd
#define CEditWnd__DrawCaret                                0x5A8740
#define CEditWnd__GetCharIndexPt                           0x5A9540
#define CEditWnd__GetDisplayString                         0x5A88D0
#define CEditWnd__GetHorzOffset                            0x5A8B40
#define CEditWnd__GetLineForPrintableChar                  0x5A9020
#define CEditWnd__GetSelStartPt                            0x5A9780
#define CEditWnd__GetSTMLSafeText                          0x5A8CD0
#define CEditWnd__PointFromPrintableChar                   0x5A9130
#define CEditWnd__SelectableCharFromPoint                  0x5A92A0
#define CEditWnd__SetEditable                              0x5A8CA0

// CEverQuest
#define CEverQuest__ClickedPlayer                          0x4C46EA
#define CEverQuest__DropHeldItemOnGround                   0x4CB5BA
#define CEverQuest__dsp_chat                               0x4C63D8
#define CEverQuest__EnterZone                              0x4D6F34
#define CEverQuest__GetBodyTypeDesc                        0x4C05DA
#define CEverQuest__GetClassDesc                           0x4BFFFD
#define CEverQuest__GetClassThreeLetterCode                0x4C0477
#define CEverQuest__GetDeityDesc                           0x4C206D
#define CEverQuest__GetRaceDesc                            0x4C08DF
#define CEverQuest__InterpretCmd                           0x4D0AF6
#define CEverQuest__LeftClickedOnPlayer                    0x4D588C
#define CEverQuest__RightClickedOnPlayer                   0x4D5CC2
#define CEverQuest__SetGameState                           0x4C475B

// CGaugeWnd
#define CGaugeWnd__CalcFillRect                            0x4E3B7A
#define CGaugeWnd__CalcLinesFillRect                       0x4E3BD6
#define CGaugeWnd__Draw                                    0x4E3ED6

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton                         0x4F410E

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot                           0x4F79CF
#define CInvSlotMgr__MoveItem                              0x4F7AFD

// CItemDisplayWnd
#define CItemDisplayWnd__SetItem                           0x4FCB2F
#define CItemDisplayWnd__SetSpell                          0x4FBB25

// CLabel
#define CLabel__Draw                                       0x5043B1

// CListWnd
#define CListWnd__AddColumn                                0x588710
#define CListWnd__AddColumn1                               0x588240
#define CListWnd__AddLine                                  0x587DD0
#define CListWnd__AddString                                0x587FA0
#define CListWnd__CalculateFirstVisibleLine                0x5853C0
#define CListWnd__CalculateVSBRange                        0x586F00
#define CListWnd__ClearAllSel                              0x584C00
#define CListWnd__CloseAndUpdateEditWindow                 0x5859E0
#define CListWnd__Compare                                  0x585D50
#define CListWnd__Draw                                     0x586B30
#define CListWnd__DrawColumnSeparators                     0x586A90
#define CListWnd__DrawHeader                               0x584DD0
#define CListWnd__DrawItem                                 0x586460
#define CListWnd__DrawLine                                 0x5867D0
#define CListWnd__DrawSeparator                            0x586B30
#define CListWnd__EnsureVisible                            0x585410
#define CListWnd__ExtendSel                                0x586390
#define CListWnd__GetColumnFlags                           0x5847A0
#define CListWnd__GetColumnJustification                   0x584910
#define CListWnd__GetColumnMinWidth                        0x5848B0
#define CListWnd__GetColumnWidth                           0x5847F0
#define CListWnd__GetCurSel                                0x584360
#define CListWnd__GetHeaderRect                            0x584450
#define CListWnd__GetItemAtPoint                           0x5856F0
#define CListWnd__GetItemAtPoint1                          0x585760
#define CListWnd__GetItemData                              0x584620
#define CListWnd__GetItemHeight                            0x585160
#define CListWnd__GetItemIcon                              0x5846E0
#define CListWnd__GetItemRect                              0x5854E0
#define CListWnd__GetItemText                              0x584660
#define CListWnd__GetSelList                               0x588120
#define CListWnd__GetSeparatorRect                         0x585CA0
#define CListWnd__IsLineEnabled                            0x584CE0
#define CListWnd__RemoveLine                               0x5880D0
#define CListWnd__SetColors                                0x5843C0
#define CListWnd__SetColumnJustification                   0x584960
#define CListWnd__SetColumnWidth                           0x584870
#define CListWnd__SetCurSel                                0x5843A0
#define CListWnd__SetItemColor                             0x587A00
#define CListWnd__SetItemData                              0x584CA0
#define CListWnd__SetItemText                              0x587980
#define CListWnd__ShiftColumnSeparator                     0x586300
#define CListWnd__Sort                                     0x588740
#define CListWnd__ToggleSel                                0x584B70

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd                           0x51747B

// CMerchantWnd
#define CMerchantWnd__DisplayBuyOrSellPrice                0x51897E
#define CMerchantWnd__RequestBuyItem                       0x5199EC
#define CMerchantWnd__RequestSellItem                      0x518CE6
#define CMerchantWnd__SelectBuySellSlot                    0x519752

// CSidlManager
#define CSidlManager__FindScreenPieceTemplate1             0x5A6A90

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateHSBRange                  0x57CE40
#define CSidlScreenWnd__CalculateVSBRange                  0x57CD80
#define CSidlScreenWnd__ConvertToRes                       0x57D580
#define CSidlScreenWnd__CreateChildrenFromSidl             0x57DDA0
#define CSidlScreenWnd__CSidlScreenWnd1                    0x57F180
#define CSidlScreenWnd__CSidlScreenWnd2                    0x57F230
#define CSidlScreenWnd__dCSidlScreenWnd                    0x57E990
#define CSidlScreenWnd__DrawSidlPiece                      0x57DAC0
#define CSidlScreenWnd__EnableIniStorage                   0x57D530
#define CSidlScreenWnd__GetSidlPiece                       0x57DC80
#define CSidlScreenWnd__Init1                              0x57EFA0
#define CSidlScreenWnd__LoadIniInfo                        0x57DE50
#define CSidlScreenWnd__LoadIniListWnd                     0x57D6E0
#define CSidlScreenWnd__LoadSidlScreen                     0x57D920
#define CSidlScreenWnd__SetScreen                          0x57EAA0
#define CSidlScreenWnd__StoreIniInfo                       0x57D080
#define CSidlScreenWnd__WndNotification                    0x57DA20

// CSliderWnd
#define CSliderWnd__GetValue                               0x59D020
#define CSliderWnd__SetValue                               0x59D1A0
#define CSliderWnd__UpdateThumb                            0x59CFE0

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet                         0x53F1A2

// CStmlWnd
#define CStmlWnd__AppendSTML                               0x5909C0
#define CStmlWnd__CalculateHSBRange                        0x5893E0
#define CStmlWnd__CalculateVSBRange                        0x589380
#define CStmlWnd__CanBreakAtCharacter                      0x589520
#define CStmlWnd__CanGoBackward                            0x5895A0
#define CStmlWnd__FastForwardToEndOfTag                    0x5C47F0
#define CStmlWnd__GetNextChar                              0x594BA0
#define CStmlWnd__GetNextTagPiece                          0x589F40
#define CStmlWnd__GetSTMLText                              0x42A877
#define CStmlWnd__GetThisChar                              0x5C3FC0
#define CStmlWnd__GetVisiableText                          0x58B430
#define CStmlWnd__InitializeWindowVariables                0x58D120
#define CStmlWnd__MakeStmlColorTag                         0x588A00
#define CStmlWnd__MakeWndNotificationTag                   0x588AA0
#define CStmlWnd__StripFirstSTMLLines                      0x590750
#define CStmlWnd__UpdateHistoryString                      0x0

// CTabWnd
#define CTabWnd__Draw                                      0x594270
#define CTabWnd__DrawCurrentPage                           0x593CD0
#define CTabWnd__DrawTab                                   0x593AD0
#define CTabWnd__GetCurrentPage                            0x593FE0
#define CTabWnd__GetCurrentTabIndex                        0x593790
#define CTabWnd__GetNumTabs                                0x593780
#define CTabWnd__GetPageClientRect                         0x5937A0
#define CTabWnd__GetPageFromTabIndex                       0x593A20
#define CTabWnd__GetPageInnerRect                          0x593800
#define CTabWnd__GetTabInnerRect                           0x5939A0
#define CTabWnd__GetTabRect                                0x5938B0
#define CTabWnd__IndexInBounds                             0x593890
#define CTabWnd__InsertPage                                0x594470
#define CTabWnd__SetPage                                   0x593FF0
#define CTabWnd__SetPageRect                               0x5941C0
#define CTabWnd__UpdatePage                                0x5943F0

// CTextOverlay
#define CTextOverlay__DisplayText                          0x4191D3

// CTextureFont
#define CTextureFont__DrawWrappedText                      0x583FE0

// CXMLDataManager
#define CXMLDataManager__GetXMLData                        0x5ACD20

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead                       0x5971F0

// CXRect
#define CXRect__CenterPoint                                0x40C571

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr                                       0x401006
#define CXStr__CXStr1                                      0x401000
#define CXStr__CXStr3                                      0x55D860
#define CXStr__dCXStr                                      0x409459
#define CXStr__operator_equal1                             0x55DA20
#define CXStr__operator_plus_equal1                        0x55E860

// CXWnd
#define CXWnd__BringToTop                                  0x57F850
#define CXWnd__Center                                      0x582CA0
#define CXWnd__ClrFocus                                    0x57F5A0
#define CXWnd__DoAllDrawing                                0x583890
#define CXWnd__DrawChildren                                0x5839C0
#define CXWnd__DrawColoredRect                             0x57FA70
#define CXWnd__DrawTooltipAtPoint                          0x582B10
#define CXWnd__GetBorderFrame                              0x57FED0
#define CXWnd__GetChildWndAt                               0x5826C0
#define CXWnd__GetClientClipRect                           0x57FE00
#define CXWnd__GetFirstChildWnd                            0x57F8E0
#define CXWnd__GetNextChildWnd                             0x5826A0
#define CXWnd__GetNextSib                                  0x57F900
#define CXWnd__GetScreenClipRect                           0x582F30
#define CXWnd__GetScreenRect                               0x5800A0
#define CXWnd__GetTooltipRect                              0x582A60
#define CXWnd__GetWindowTextA                              0x402A4F
#define CXWnd__GetXMLTooltip                               0x0 
#define CXWnd__IsActive                                    0x57FE70
#define CXWnd__IsDescendantOf                              0x57FE80
#define CXWnd__IsReallyVisible                             0x582680
#define CXWnd__IsType                                      0x583830
#define CXWnd__Move                                        0x582230
#define CXWnd__Move1                                       0x5822C0
#define CXWnd__ProcessTransition                           0x57F810
#define CXWnd__Refade                                      0x57F640
#define CXWnd__Resize                                      0x583070
#define CXWnd__Right                                       0x582E10
#define CXWnd__SetFirstChildPointer                        0x5802F0
#define CXWnd__SetFocus                                    0x5815B0
#define CXWnd__SetKeyTooltip                               0x580330
#define CXWnd__SetMouseOver                                0x580310
#define CXWnd__SetNextSibPointer                           0x580300
#define CXWnd__StartFade                                   0x57F870

// CXWndManager
#define CXWndManager__DrawCursor                           0x59EFB0
#define CXWndManager__DrawWindows                          0x59EC70
#define CXWndManager__GetFirstChildWnd                     0x59E630
#define CXWndManager__GetKeyboardFlags                     0x59DAF0
#define CXWndManager__HandleKeyboardMsg                    0x59DFC0
#define CXWndManager__RemoveWnd                            0x59DED0

// EQ_Character
#define EQ_Character__CastSpell                            0x4AB937
#define EQ_Character__Cur_HP                               0x49EC5D
#define EQ_Character__GetAACastingTimeModifier             0x4A7A90
#define EQ_Character__GetFocusCastingTimeModifier          0x4A75F9
#define EQ_Character__Max_Endurance                        0x49B738
#define EQ_Character__Max_HP                               0x49B4E5
#define EQ_Character__Max_Mana                             0x4B4998
#define EQ_Character__doCombatAbility                      0x4B4D2A

// EQ_Item
#define EQ_Item__CanDrop                                   0x4B1FF5
#define EQ_Item__GetItemLinkHash                           0x4B1BE7
#define EQ_Item__IsStackable                               0x4B2199

// EQ_LoadingS
#define EQ_LoadingS__WriteTextHD                           0x4B2705

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney                      0x4B706C

// EQItemList
#define EQItemList__dEQItemList                            0x46B4A7
#define EQItemList__EQItemList                             0x46B42B

// EQPlayer
#define EQPlayer__ChangeBoneStringSprite                   0x4818D0
#define EQPlayer__dEQPlayer                                0x48AD3A
#define EQPlayer__DoAttack                                 0x488D94
#define EQPlayer__EQPlayer                                 0x48B32A
#define EQPlayer__SetNameSpriteState                       0x48429A
#define EQPlayer__SetNameSpriteTint                        0x48193C

// KeyPressHandler
#define KeypressHandler__AttachAltKeyToEqCommand           0x50423A
#define KeypressHandler__AttachKeyToEqCommand              0x504207
#define KeypressHandler__ClearCommandStateArray            0x504052
#define KeypressHandler__HandleKeyDown                     0x502EAD
#define KeypressHandler__HandleKeyUp                       0x503124
#define KeypressHandler__SaveKeymapping                    0x5040D7

// MapViewMap
#define MapViewMap__Clear                                  0x513BF4
#define MapViewMap__SaveEx                                 0x5143B1

// StringTable
#define StringTable__getString                             0x5CAEC0


