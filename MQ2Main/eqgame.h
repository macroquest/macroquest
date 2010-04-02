/******************************************************************************
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

#define __ClientName                                              "eqgame" 
#define __ExpectedVersionDate                                     "Aug 14 2007"
#define __ExpectedVersionTime                                     "17:27:32"
#define __ActualVersionDate                                        0x6F4EE4
#define __ActualVersionTime                                        0x6F4EF0

#define __ClientOverride                                           0 
#define __MacroQuestWinClassName                                  "__MacroQuestTray" 
#define __MacroQuestWinName                                       "MacroQuest" 

// Memory Protection
#define __MemChecker0                                              0x4EBFD0
#define __MemChecker1                                              0x6442B0
#define __MemChecker2                                              0x51F9F0
#define __MemChecker3                                              0x51FAA0
#define __MemChecker4                                              0x60D6B0
#define __EncryptPad0                                              0x750A60
#define __EncryptPad1                                              0x75A2F8
#define __EncryptPad2                                              0x752FC0
#define __EncryptPad3                                              0x7533C0
#define __EncryptPad4                                              0x759A10

// Direct Input
#define DI8__Main                                                  0x988504
#define DI8__Keyboard                                              0x988508
#define DI8__Mouse                                                 0x98850C
#define __AltTimerReady                                            0x9243CA
#define __Attack                                                   0x981CB2
#define __Autofire                                                 0x981CB3
#define __BindList                                                 0x74BC70
#define __Clicks                                                   0x9234F4
#define __CommandList                                              0x74C470
#define __CurrentMapLabel                                          0x99361C
#define __CurrentSocial                                            0x7484FC
#define __DoAbilityAvailable                                       0x924364
#define __DoAbilityList                                            0x9597F8
#define __DrawHandler                                              0x9A286C
#define __GroupCount                                               0x903C18
#define __GroupLeader                                              0x903D74
#define __Guilds                                                   0x905738
#define __gWorld                                                   0x905678
#define __HotkeyPage                                               0x980BE4
#define __HWnd                                                     0x9884AC
#define __InChatMode                                               0x923430
#define __LastTell                                                 0x924C90
#define __LMouseHeldTime                                           0x923514
#define __Mouse                                                    0x988510
#define __MouseLook                                                0x9234C2
#define __NetStatusToggle                                          0x9234C4
#define __PCNames                                                  0x9246E8
#define __RangeAttackReady                                         0x9243C8
#define __RMouseHeldTime                                           0x923510
#define __RunWalkState                                             0x923434
#define __ScreenMode                                               0x8536E8
#define __ScreenX                                                  0x9233F8
#define __ScreenY                                                  0x9233FC
#define __ScreenXMax                                               0x923400
#define __ScreenYMax                                               0x923404
#define __ServerHost                                               0x903B6C
#define __ServerName                                               0x9597B8
#define __ShowNames                                                0x9245BC
#define __Socials                                                  0x9598B8


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0x91D388
#define instEQZoneInfo                                             0x923660
#define instKeypressHandler                                        0x981D9C
#define pinstActiveBanker                                          0x905710
#define pinstActiveCorpse                                          0x905714
#define pinstActiveGMaster                                         0x905718
#define pinstActiveMerchant                                        0x90570C
#define pinstAltAdvManager                                         0x8543D0
#define pinstAuraMgr                                               0x75F414
#define pinstBandageTarget                                         0x9056F8
#define pinstCamActor                                              0x853EC4
#define pinstCDBStr                                                0x853568
#define pinstCDisplay                                              0x905720
#define pinstCEverQuest                                            0x988684
#define pinstCharData                                              0x9056DC
#define pinstCharSpawn                                             0x905704
#define pinstControlledMissile                                     0x9056D8
#define pinstControlledPlayer                                      0x905704
#define pinstCSidlManager                                          0x9A20BC
#define pinstCXWndManager                                          0x9A20B4
#define instDynamicZone                                            0x922E48
#define pinstDZMember                                              0x922F58
#define pinstDZTimerInfo                                           0x922F5C
#define pinstEQItemList                                            0x9056C0
#define instEQMisc                                                 0x853520
#define pinstEQSoundManager                                        0x8543F4
#define instExpeditionLeader                                       0x922E92
#define instExpeditionName                                         0x922ED2
#define instGroup                                                  0x903C18
#define pinstGroup                                                 0x903C14
#define pinstImeManager                                            0x9A20C0
#define pinstLocalPlayer                                           0x9056F0
#define pinstModelPlayer                                           0x90571C
#define pinstPCData                                                0x9056DC
#define pinstSelectedItem                                          0x993474
#define pinstSkillMgr                                              0x985498
#define pinstSpawnManager                                          0x985414
#define pinstSpellManager                                          0x98549C
#define pinstSpellSets                                             0x980BE8
#define pinstStringTable                                           0x905694
#define pinstSwitchManager                                         0x903868
#define pinstTarget                                                0x905708
#define pinstTargetObject                                          0x9056E0
#define pinstTargetSwitch                                          0x9056E4
#define pinstTaskMember                                            0x853500
#define pinstTrackTarget                                           0x9056FC
#define pinstTradeTarget                                           0x9056EC
#define instTributeActive                                          0x853545
#define pinstViewActor                                             0x853EC0
#define pinstWorldData                                             0x9056BC


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x75D948
#define pinstCAudioTriggersWindow                                  0x75D92C
#define pinstCCharacterSelect                                      0x853DD0
#define pinstCFacePick                                             0x853D88
#define pinstCNoteWnd                                              0x853D8C
#define pinstCBookWnd                                              0x853D90
#define pinstCPetInfoWnd                                           0x853D94
#define pinstCTrainWnd                                             0x853D98
#define pinstCSkillsWnd                                            0x853D9C
#define pinstCSkillsSelectWnd                                      0x853DA0
#define pinstCCombatSkillSelectWnd                                 0x853DA4
#define pinstCFriendsWnd                                           0x853DA8
#define pinstCAuraWnd                                              0x853DAC
#define pinstCRespawnWnd                                           0x853DB0
#define pinstCBandolierWnd                                         0x853DB4
#define pinstCPotionBeltWnd                                        0x853DB8
#define pinstCAAWnd                                                0x853DBC
#define pinstCGroupSearchFiltersWnd                                0x853DC0
#define pinstCLoadskinWnd                                          0x853DC4
#define pinstCAlarmWnd                                             0x853DC8
#define pinstCMusicPlayerWnd                                       0x853DCC
#define pinstCMailWnd                                              0x853DD4
#define pinstCMailCompositionWnd                                   0x853DD8
#define pinstCMailAddressBookWnd                                   0x853DDC
#define pinstCRaidWnd                                              0x853DE4
#define pinstCRaidOptionsWnd                                       0x853DE8
#define pinstCBreathWnd                                            0x853DEC
#define pinstCMapViewWnd                                           0x853DF0
#define pinstCMapToolbarWnd                                        0x853DF4
#define pinstCEditLabelWnd                                         0x853DF8
#define pinstCTargetWnd                                            0x853DFC
#define pinstCColorPickerWnd                                       0x853E00
#define pinstCPlayerWnd                                            0x853E04
#define pinstCOptionsWnd                                           0x853E08
#define pinstCBuffWindowNORMAL                                     0x853E0C
#define pinstCBuffWindowSHORT                                      0x853E10
#define pinstCharacterCreation                                     0x853E14
#define pinstCCursorAttachment                                     0x853E18
#define pinstCCastingWnd                                           0x853E1C
#define pinstCCastSpellWnd                                         0x853E20
#define pinstCSpellBookWnd                                         0x853E24
#define pinstCInventoryWnd                                         0x853E28
#define pinstCBankWnd                                              0x853E2C
#define pinstCQuantityWnd                                          0x853E30
#define pinstCLootWnd                                              0x853E34
#define pinstCActionsWnd                                           0x853E38
#define pinstCCombatAbilityWnd                                     0x853E3C
#define pinstCMerchantWnd                                          0x853E40
#define pinstCTradeWnd                                             0x853E44
#define pinstCSelectorWnd                                          0x853E48
#define pinstCBazaarWnd                                            0x853E4C
#define pinstCBazaarSearchWnd                                      0x853E50
#define pinstCGiveWnd                                              0x853E54
#define pinstCTrackingWnd                                          0x853E58
#define pinstCInspectWnd                                           0x853E5C
#define pinstCSocialEditWnd                                        0x853E60
#define pinstCFeedbackWnd                                          0x853E64
#define pinstCBugReportWnd                                         0x853E68
#define pinstCVideoModesWnd                                        0x853E6C
#define pinstCTextEntryWnd                                         0x853E74
#define pinstCFileSelectionWnd                                     0x853E78
#define pinstCCompassWnd                                           0x853E7C
#define pinstCPlayerNotesWnd                                       0x853E80
#define pinstCGemsGameWnd                                          0x853E84
#define pinstCTimeLeftWnd                                          0x853E88
#define pinstCPetitionQWnd                                         0x853E8C
#define pinstCSoulmarkWnd                                          0x853E90
#define pinstCStoryWnd                                             0x853E94
#define pinstCJournalTextWnd                                       0x853E98
#define pinstCJournalCatWnd                                        0x853E9C
#define pinstCBodyTintWnd                                          0x853EA0
#define pinstCServerListWnd                                        0x853EA4
#define pinstCAvaZoneWnd                                           0x853EA8
#define pinstCBlockedBuffWnd                                       0x853EAC
#define pinstCBlockedPetBuffWnd                                    0x853EB0
#define pinstCInvSlotMgr                                           0x853EB4
#define pinstCContainerMgr                                         0x853EB8
#define pinstCAdventureLeaderboardWnd                              0x990C64
#define pinstCAdventureRequestWnd                                  0x990C80
#define pinstCAltStorageWnd                                        0x990CE0
#define pinstCAdventureStatsWnd                                    0x990C9C
#define pinstCBarterMerchantWnd                                    0x990E94
#define pinstCBarterSearchWnd                                      0x990EB0
#define pinstCBarterWnd                                            0x990ECC
#define pinstCChatManager                                          0x9910C4
#define pinstCDynamicZoneWnd                                       0x9911A0
#define pinstCEQMainWnd                                            0x991210
#define pinstCFellowshipWnd                                        0x991274
#define pinstCFindLocationWnd                                      0x9912A8
#define pinstCGroupSearchWnd                                       0x991358
#define pinstCGroupWnd                                             0x991374
#define pinstCGuildBankWnd                                         0x991390
#define pinstCGuildMgmtWnd                                         0x9933B0
#define pinstCGuildTributeMasterWnd                                0x9933D0
#define pinstCHotButtonWnd                                         0x9933EC
#define pinstCHotButtonWnd1                                        0x9933EC
#define pinstCHotButtonWnd2                                        0x9933F0
#define pinstCHotButtonWnd3                                        0x9933F4
#define pinstCHotButtonWnd4                                        0x9933F8
#define pinstCItemDisplayManager                                   0x9934A8
#define pinstCItemExpTransferWnd                                   0x9934C8
#define pinstCLeadershipWnd                                        0x993544
#define pinstCLFGuildWnd                                           0x993560
#define pinstCMIZoneSelectWnd                                      0x993684
#define pinstCAdventureMerchantWnd                                 0x99377C
#define pinstCConfirmationDialog                                   0x993798
#define pinstCPopupWndManager                                      0x993798
#define pinstCProgressionSelectionWnd                              0x9937CC
#define pinstCPvPLeaderboardWnd                                    0x9937E8
#define pinstCPvPStatsWnd                                          0x993804
#define pinstCSystemInfoDialogBox                                  0x99416C
#define pinstCTargetOfTargetWnd                                    0x994188
#define pinstCTaskSelectWnd                                        0x9941BC
#define pinstCTaskTemplateSelectWnd                                0x9941D8
#define pinstCTaskWnd                                              0x9941F4
#define pinstCTipWndOFDAY                                          0x994288
#define pinstCTipWndCONTEXT                                        0x99428C
#define pinstCTitleWnd                                             0x9942A8
#define pinstCTradeskillWnd                                        0x9942EC
#define pinstCTributeBenefitWnd                                    0x994338
#define pinstCTributeMasterWnd                                     0x994354
#define pinstCContextMenuManager                                   0x9A217C
#define pinstCVoiceMacroWnd                                        0x98556C
#define pinstCHtmlWnd                                              0x985588


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4AE980
#define __ConvertItemTags                                          0x4A3320
#define __ExecuteCmd                                               0x494890
#define __get_melee_range                                          0x499970
#define __GetGaugeValueFromEQ                                      0x5E0170
#define __GetLabelFromEQ                                           0x5E0980
#define __NewUIINI                                                 0x5DFD60
#define __ProcessGameEvents                                        0x4DA2A0
#define __SendMessage                                              0x4BC0F0
#define CrashDetected                                              0x51EAF0
#define DrawNetStatus                                              0x4EECF0
#define Util__FastTime                                             0x644900


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x46F580
#define AltAdvManager__IsAbilityReady                              0x46F5C0
#define AltAdvManager__GetAltAbility                               0x46F710

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x534F90

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x53E410

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x6609D0

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5524A0
#define CChatManager__InitContextMenu                              0x552C30

// CChatService
#define CChatService__GetNumberOfFriends                           0x6350B0
#define CChatService__GetFriendName                                0x6350C0

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x556DA0
#define CChatWindow__WndNotification                               0x557790

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x656120
#define CComboWnd__Draw                                            0x6562D0
#define CComboWnd__GetCurChoice                                    0x6560C0
#define CComboWnd__GetListRect                                     0x6565B0
#define CComboWnd__GetTextRect                                     0x656150
#define CComboWnd__InsertChoice                                    0x656620
#define CComboWnd__SetColors                                       0x656050
#define CComboWnd__SetChoice                                       0x656080

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x55D3D0
#define CContainerWnd__vftable                                     0x6FB538

// CDisplay 
#define CDisplay__CleanGameUI                                      0x45E6B0
#define CDisplay__GetClickedActor                                  0x45BDB0
#define CDisplay__GetUserDefinedColor                              0x45B210
#define CDisplay__GetWorldFilePath                                 0x45A780
#define CDisplay__is3dON                                           0x459320
#define CDisplay__ReloadUI                                         0x46A770
#define CDisplay__WriteTextHD2                                     0x45FE80

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x52F1B0
#define CEditBaseWnd__SetSel                                       0x679210

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x6768C0
#define CEditWnd__GetCharIndexPt                                   0x677720
#define CEditWnd__GetDisplayString                                 0x676A50
#define CEditWnd__GetHorzOffset                                    0x676CF0
#define CEditWnd__GetLineForPrintableChar                          0x6771D0
#define CEditWnd__GetSelStartPt                                    0x677960
#define CEditWnd__GetSTMLSafeText                                  0x676E90
#define CEditWnd__PointFromPrintableChar                           0x6772E0
#define CEditWnd__SelectableCharFromPoint                          0x677460
#define CEditWnd__SetEditable                                      0x676E60

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4C0290
#define CEverQuest__DropHeldItemOnGround                           0x4C4E60
#define CEverQuest__dsp_chat                                       0x4C5AF0
#define CEverQuest__DoTellWindow                                   0x4C4F90
#define CEverQuest__EnterZone                                      0x4D8D90
#define CEverQuest__GetBodyTypeDesc                                0x4BD930
#define CEverQuest__GetClassDesc                                   0x4BD090
#define CEverQuest__GetClassThreeLetterCode                        0x4BD690
#define CEverQuest__GetDeityDesc                                   0x4BDFA0
#define CEverQuest__GetLangDesc                                    0x4BDCC0
#define CEverQuest__GetRaceDesc                                    0x4BDF70
#define CEverQuest__InterpretCmd                                   0x4C6470
#define CEverQuest__LeftClickedOnPlayer                            0x4D7940
#define CEverQuest__LMouseUp                                       0x4D9B00
#define CEverQuest__RightClickedOnPlayer                           0x4D7D10
#define CEverQuest__RMouseUp                                       0x4D93B0
#define CEverQuest__SetGameState                                   0x4C0360

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x568350
#define CGaugeWnd__CalcLinesFillRect                               0x5683C0
#define CGaugeWnd__Draw                                            0x568750

// CGuild
#define CGuild__FindMemberByName                                   0x415A50

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x57E180

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x587390
#define CInvSlotMgr__MoveItem                                      0x587530

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x588430

// CInvSLot
#define CInvSlot__SliderComplete                                   0x586300

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x595F90
#define CItemDisplayWnd__SetSpell                                  0x5DE040

// CLabel 
#define CLabel__Draw                                               0x59B5E0

// CListWnd 
#define CListWnd__AddColumn                                        0x655E60
#define CListWnd__AddColumn1                                       0x655950
#define CListWnd__AddLine                                          0x655530
#define CListWnd__AddString                                        0x655700
#define CListWnd__CalculateFirstVisibleLine                        0x652880
#define CListWnd__CalculateVSBRange                                0x6544E0
#define CListWnd__ClearAllSel                                      0x651FD0
#define CListWnd__CloseAndUpdateEditWindow                         0x652E90
#define CListWnd__Compare                                          0x653240
#define CListWnd__Draw                                             0x6541E0
#define CListWnd__DrawColumnSeparators                             0x654050
#define CListWnd__DrawHeader                                       0x6521A0
#define CListWnd__DrawItem                                         0x653950
#define CListWnd__DrawLine                                         0x653D00
#define CListWnd__DrawSeparator                                    0x6540F0
#define CListWnd__EnsureVisible                                    0x6528D0
#define CListWnd__ExtendSel                                        0x653880
#define CListWnd__GetColumnMinWidth                                0x651D70
#define CListWnd__GetColumnWidth                                   0x651CB0
#define CListWnd__GetCurSel                                        0x651790
#define CListWnd__GetHeaderRect                                    0x651880
#define CListWnd__GetItemAtPoint                                   0x652BA0
#define CListWnd__GetItemAtPoint1                                  0x652C10
#define CListWnd__GetItemData                                      0x651A60
#define CListWnd__GetItemHeight                                    0x652610
#define CListWnd__GetItemIcon                                      0x651BF0
#define CListWnd__GetItemRect                                      0x652990
#define CListWnd__GetItemText                                      0x651AA0
#define CListWnd__GetSelList                                       0x655830
#define CListWnd__GetSeparatorRect                                 0x653180
#define CListWnd__RemoveLine                                       0x655E10
#define CListWnd__SetColors                                        0x6517F0
#define CListWnd__SetColumnJustification                           0x651DD0
#define CListWnd__SetColumnWidth                                   0x651D30
#define CListWnd__SetCurSel                                        0x6517D0
#define CListWnd__SetItemColor                                     0x655100
#define CListWnd__SetItemData                                      0x652070
#define CListWnd__SetItemText                                      0x655080
#define CListWnd__ShiftColumnSeparator                             0x6537F0
#define CListWnd__Sort                                             0x655E90
#define CListWnd__ToggleSel                                        0x651F40

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x5AE3E0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x5AFDB0
#define CMerchantWnd__RequestBuyItem                               0x5B1040
#define CMerchantWnd__RequestSellItem                              0x5B0000
#define CMerchantWnd__SelectBuySellSlot                            0x5B0D80

// CObfuscator
#define CObfuscator__doit                                          0x6367B0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x6655B0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x530AB0
#define CSidlScreenWnd__CalculateVSBRange                          0x65B9D0
#define CSidlScreenWnd__ConvertToRes                               0x65C121
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x65C920
#define CSidlScreenWnd__CSidlScreenWnd1                            0x65DBA0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x65DC50
#define CSidlScreenWnd__dCSidlScreenWnd                            0x65D460
#define CSidlScreenWnd__DrawSidlPiece                              0x65C600
#define CSidlScreenWnd__EnableIniStorage                           0x65C0C0
#define CSidlScreenWnd__GetSidlPiece                               0x65C800
#define CSidlScreenWnd__Init1                                      0x65D9C0
#define CSidlScreenWnd__LoadIniInfo                                0x65C9D0
#define CSidlScreenWnd__LoadIniListWnd                             0x65C280
#define CSidlScreenWnd__LoadSidlScreen                             0x65C440
#define CSidlScreenWnd__StoreIniInfo                               0x65BC00
#define CSidlScreenWnd__WndNotification                            0x65C560

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x510A50

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x4283C0
#define CSliderWnd__SetValue                                       0x67B160
#define CSliderWnd__SetNumTicks                                    0x67B680

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x5DCDC0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x66FA30
#define CStmlWnd__CalculateVSBRange                                0x667DD0
#define CStmlWnd__CanBreakAtCharacter                              0x667F10
#define CStmlWnd__FastForwardToEndOfTag                            0x668A20
#define CStmlWnd__GetNextTagPiece                                  0x668940
#define CStmlWnd__GetSTMLText                                      0x556D40
#define CStmlWnd__GetThisChar                                      0x6987F0
#define CStmlWnd__GetVisiableText                                  0x669C40
#define CStmlWnd__InitializeWindowVariables                        0x66BDA0
#define CStmlWnd__MakeStmlColorTag                                 0x667450
#define CStmlWnd__MakeWndNotificationTag                           0x6674F0
#define CStmlWnd__StripFirstSTMLLines                              0x66F7C0
#define CStmlWnd__UpdateHistoryString                              0x66A4A0

// CTabWnd 
#define CTabWnd__Draw                                              0x67A900
#define CTabWnd__DrawCurrentPage                                   0x67A280
#define CTabWnd__DrawTab                                           0x67A060
#define CTabWnd__GetCurrentPage                                    0x67A580
#define CTabWnd__GetPageClientRect                                 0x679D30
#define CTabWnd__GetPageFromTabIndex                               0x679F90
#define CTabWnd__GetPageInnerRect                                  0x679D90
#define CTabWnd__GetTabInnerRect                                   0x679F10
#define CTabWnd__GetTabRect                                        0x679E20
#define CTabWnd__IndexInBounds                                     0x67A02D
#define CTabWnd__InsertPage                                        0x67AB20
#define CTabWnd__SetPage                                           0x67A5C0
#define CTabWnd__SetPageRect                                       0x67A830
#define CTabWnd__UpdatePage                                        0x67AAA0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x4125F0

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x65DFB0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x681930

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x651500

// CXRect 
#define CXRect__CenterPoint                                        0x5346F0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x412190
#define CXStr__CXStr1                                              0x64C4E0
#define CXStr__CXStr3                                              0x645FF0
#define CXStr__dCXStr                                              0x457BB0
#define CXStr__operator_equal1                                     0x6461B0
#define CXStr__operator_plus_equal1                                0x6470A0

// CXWnd 
#define CXWnd__BringToTop                                          0x656E70
#define CXWnd__Center                                              0x65A800
#define CXWnd__ClrFocus                                            0x656B90
#define CXWnd__DoAllDrawing                                        0x65B430
#define CXWnd__DrawChildren                                        0x65B560
#define CXWnd__DrawColoredRect                                     0x6570D0
#define CXWnd__DrawTooltip                                         0x65B350
#define CXWnd__DrawTooltipAtPoint                                  0x65A5D0
#define CXWnd__GetBorderFrame                                      0x657590
#define CXWnd__GetChildWndAt                                       0x65A0B0
#define CXWnd__GetClientClipRect                                   0x6574D0
#define CXWnd__GetFirstChildWnd                                    0x656F10
#define CXWnd__GetNextChildWnd                                     0x65A070
#define CXWnd__GetNextSib                                          0x656F30
#define CXWnd__GetScreenClipRect                                   0x65A9F0
#define CXWnd__GetScreenRect                                       0x657750
#define CXWnd__GetTooltipRect                                      0x657300
#define CXWnd__GetWindowTextA                                      0x51DC80
#define CXWnd__IsActive                                            0x671A10
#define CXWnd__IsDescendantOf                                      0x657540
#define CXWnd__IsReallyVisible                                     0x65A050
#define CXWnd__IsType                                              0x67C4F0
#define CXWnd__Move                                                0x659BB0
#define CXWnd__Move1                                               0x659C40
#define CXWnd__ProcessTransition                                   0x656E30
#define CXWnd__Refade                                              0x656C40
#define CXWnd__Resize                                              0x657810
#define CXWnd__Right                                               0x65A940
#define CXWnd__SetFirstChildPointer                                0x6579F0
#define CXWnd__SetFocus                                            0x658DD0
#define CXWnd__SetKeyTooltip                                       0x657A60
#define CXWnd__SetMouseOver                                        0x657A30
#define CXWnd__SetNextSibPointer                                   0x657A10
#define CXWnd__StartFade                                           0x656E90

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x672F50
#define CXWndManager__DrawWindows                                  0x672B90
#define CXWndManager__GetFirstChildWnd                             0x672460
#define CXWndManager__GetKeyboardFlags                             0x671710
#define CXWndManager__HandleKeyboardMsg                            0x671CB0
#define CXWndManager__RemoveWnd                                    0x671BD0

// CDBStr
#define CDBStr__GetString                                          0x457BD0

// EQ_Character 
#define EQ_Character__CastRay                                      0x6A43D0
#define EQ_Character__CastSpell                                    0x421F30
#define EQ_Character__Cur_HP                                       0x4299B0
#define EQ_Character__GetAACastingTimeModifier                     0x41D0D0
#define EQ_Character__GetCharInfo2                                 0x61D380
#define EQ_Character__GetFocusCastingTimeModifier                  0x419190
#define EQ_Character__GetFocusRangeModifier                        0x4192C0
#define EQ_Character__Max_Endurance                                0x428690
#define EQ_Character__Max_HP                                       0x428540
#define EQ_Character__Max_Mana                                     0x4F3D80
#define EQ_Character__doCombatAbility                              0x4F2C00
#define EQ_Character__UseSkill                                     0x435410
#define EQ_Character__GetConLevel                                  0x4F00B0

// EQ_Item 
#define EQ_Item__CanDrop                                           0x4E5B70
#define EQ_Item__GetItemLinkHash                                   0x61C520
#define EQ_Item__IsStackable                                       0x613380

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x4705E0
#define EQ_LoadingS__Array                                         0x74A180

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x4F6CB0
#define EQ_PC__GetAltAbilityIndex                                  0x622250
#define EQ_PC__GetCombatAbility                                    0x6222E0
#define EQ_PC__GetCombatAbilityTimer                               0x622390
#define EQ_PC__GetItemTimerValue                                   0x4F1E60
#define EQ_PC__HasLoreItem                                         0x4F52D0

// EQItemList 
#define EQItemList__dEQItemList                                    0x498190
#define EQItemList__EQItemList                                     0x4980E0

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x457630

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x4FB7D0
#define EQPlayer__dEQPlayer                                        0x4FFDF0
#define EQPlayer__DoAttack                                         0x50B520
#define EQPlayer__EQPlayer                                         0x5025C0
#define EQPlayer__SetNameSpriteState                               0x4FDF20
#define EQPlayer__SetNameSpriteTint                                0x4FB840
#define EQPlayer__IsBodyType_j                                     0x6A3DD0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x503550

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4E7740
#define KeypressHandler__AttachKeyToEqCommand                      0x4E7780
#define KeypressHandler__ClearCommandStateArray                    0x4E7550
#define KeypressHandler__HandleKeyDown                             0x4E6160
#define KeypressHandler__HandleKeyUp                               0x4E6460
#define KeypressHandler__SaveKeymapping                            0x4E7620

// MapViewMap 
#define MapViewMap__Clear                                          0x5AA400
#define MapViewMap__SaveEx                                         0x5AADD0

#define OtherCharData__GetAltCurrency                              0x63D660

// StringTable 
#define StringTable__getString                                     0x612D00