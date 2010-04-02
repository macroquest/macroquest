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
#define __ExpectedVersionDate                                     "Jun  7 2007"
#define __ExpectedVersionTime                                     "10:06:28"
#define __ActualVersionDate                                        0x6D8DEC
#define __ActualVersionTime                                        0x6D8DF8

#define __ClientOverride                                           0 
#define __MacroQuestWinClassName                                  "__MacroQuestTray" 
#define __MacroQuestWinName                                       "MacroQuest" 

// Memory Protection 
#define __MemChecker0                                              0x4E7610
#define __MemChecker1                                              0x62A810
#define __MemChecker2                                              0x5178E0
#define __MemChecker3                                              0x517990
#define __MemChecker4                                              0x5F7990
#define __EncryptPad0                                              0x732A20
#define __EncryptPad1                                              0x73C258
#define __EncryptPad2                                              0x734F80
#define __EncryptPad3                                              0x735380
#define __EncryptPad4                                              0x73B970

// Direct Input
#define DI8__Main                                                  0x96A184
#define DI8__Keyboard                                              0x96A188
#define DI8__Mouse                                                 0x96A18C
#define __AltTimerReady                                            0x906342
#define __Attack                                                   0x9639BA
#define __Autofire                                                 0x9639BB
#define __BindList                                                 0x72DC50
#define __Clicks                                                   0x90546C
#define __CommandList                                              0x72E450
#define __CurrentMapLabel                                          0x97524C
#define __CurrentSocial                                            0x72A4DC
#define __DoAbilityAvailable                                       0x9062DC
#define __DoAbilityList                                            0x93B500
#define __DrawHandler                                              0x9840A4
#define __GroupCount                                               0x8E5B90
#define __GroupLeader                                              0x8E5CEC
#define __Guilds                                                   0x8E76B0
#define __gWorld                                                   0x8E75F0
#define __HotkeyPage                                               0x9628EC
#define __HWnd                                                     0x96A130
#define __InChatMode                                               0x9053A8
#define __LastTell                                                 0x906C08
#define __Mouse                                                    0x96A190
#define __MouseLook                                                0x90543A
#define __NetStatusToggle                                          0x90543C
#define __PCNames                                                  0x906660
#define __RangeAttackReady                                         0x906340
#define __RunWalkState                                             0x9053AC
#define __ScreenMode                                               0x835660
#define __ScreenX                                                  0x905370
#define __ScreenY                                                  0x905374
#define __ServerHost                                               0x8E5AE4
#define __ServerName                                               0x93B4C0
#define __ShowNames                                                0x906534
#define __Socials                                                  0x93B5C0


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0x8FF300
#define instEQZoneInfo                                             0x9055D8
#define instKeypressHandler                                        0x963ABC
#define pinstActiveBanker                                          0x8E7688
#define pinstActiveCorpse                                          0x8E768C
#define pinstActiveGMaster                                         0x8E7690
#define pinstActiveMerchant                                        0x8E7684
#define pinstAltAdvManager                                         0x836348
#define pinstAuraMgr                                               0x74138C
#define pinstBandageTarget                                         0x8E7670
#define pinstCamActor                                              0x835E3C
#define pinstCDBStr                                                0x8354E0
#define pinstCDisplay                                              0x8E7698
#define pinstCEverQuest                                            0x96A2F8
#define pinstCharData                                              0x8E7654
#define pinstCharSpawn                                             0x8E767C
#define pinstControlledMissile                                     0x8E7650
#define pinstControlledPlayer                                      0x8E767C
#define pinstCSidlManager                                          0x9838A0
#define pinstCXWndManager                                          0x983898
#define instDynamicZone                                            0x904DC0
#define pinstDZMember                                              0x904ED0
#define pinstDZTimerInfo                                           0x904ED4
#define pinstEQItemList                                            0x8E7638
#define instEQMisc                                                 0x835498
#define pinstEQSoundManager                                        0x83636C
#define instExpeditionLeader                                       0x904E0A
#define instExpeditionName                                         0x904E4A
#define instGroup                                                  0x8E5B90
#define pinstGroup                                                 0x8E5B8C
#define pinstImeManager                                            0x9838A4
#define pinstLocalPlayer                                           0x8E7668
#define pinstModelPlayer                                           0x8E7694
#define pinstPCData                                                0x8E7654
#define pinstSelectedItem                                          0x9750A4
#define pinstSkillMgr                                              0x9671B8
#define pinstSpawnManager                                          0x967134
#define pinstSpellManager                                          0x9671BC
#define pinstSpellSets                                             0x9628F0
#define pinstStringTable                                           0x8E760C
#define pinstSwitchManager                                         0x8E57E0
#define pinstTarget                                                0x8E7680
#define pinstTargetObject                                          0x8E7658
#define pinstTargetSwitch                                          0x8E765C
#define pinstTaskMember                                            0x835478
#define pinstTrackTarget                                           0x8E7674
#define pinstTradeTarget                                           0x8E7664
#define instTributeActive                                          0x8354BD
#define pinstViewActor                                             0x835E38
#define pinstWorldData                                             0x8E7634


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x73F8C0
#define pinstCAudioTriggersWindow                                  0x73F88C
#define pinstCCharacterSelect                                      0x835D48
#define pinstCFacePick                                             0x835D00
#define pinstCNoteWnd                                              0x835D04
#define pinstCBookWnd                                              0x835D08
#define pinstCPetInfoWnd                                           0x835D0C
#define pinstCTrainWnd                                             0x835D10
#define pinstCSkillsWnd                                            0x835D14
#define pinstCSkillsSelectWnd                                      0x835D18
#define pinstCCombatSkillSelectWnd                                 0x835D1C
#define pinstCFriendsWnd                                           0x835D20
#define pinstCAuraWnd                                              0x835D24
#define pinstCRespawnWnd                                           0x835D28
#define pinstCBandolierWnd                                         0x835D2C
#define pinstCPotionBeltWnd                                        0x835D30
#define pinstCAAWnd                                                0x835D34
#define pinstCGroupSearchFiltersWnd                                0x835D38
#define pinstCLoadskinWnd                                          0x835D3C
#define pinstCAlarmWnd                                             0x835D40
#define pinstCMusicPlayerWnd                                       0x835D44
#define pinstCMailWnd                                              0x835D4C
#define pinstCMailCompositionWnd                                   0x835D50
#define pinstCMailAddressBookWnd                                   0x835D54
#define pinstCRaidWnd                                              0x835D5C
#define pinstCRaidOptionsWnd                                       0x835D60
#define pinstCBreathWnd                                            0x835D64
#define pinstCMapViewWnd                                           0x835D68
#define pinstCMapToolbarWnd                                        0x835D6C
#define pinstCEditLabelWnd                                         0x835D70
#define pinstCTargetWnd                                            0x835D74
#define pinstCColorPickerWnd                                       0x835D78
#define pinstCPlayerWnd                                            0x835D7C
#define pinstCOptionsWnd                                           0x835D80
#define pinstCBuffWindowNORMAL                                     0x835D84
#define pinstCBuffWindowSHORT                                      0x835D88
#define pinstCharacterCreation                                     0x835D8C
#define pinstCCursorAttachment                                     0x835D90
#define pinstCCastingWnd                                           0x835D94
#define pinstCCastSpellWnd                                         0x835D98
#define pinstCSpellBookWnd                                         0x835D9C
#define pinstCInventoryWnd                                         0x835DA0
#define pinstCBankWnd                                              0x835DA4
#define pinstCQuantityWnd                                          0x835DA8
#define pinstCLootWnd                                              0x835DAC
#define pinstCActionsWnd                                           0x835DB0
#define pinstCCombatAbilityWnd                                     0x835DB4
#define pinstCMerchantWnd                                          0x835DB8
#define pinstCTradeWnd                                             0x835DBC
#define pinstCSelectorWnd                                          0x835DC0
#define pinstCBazaarWnd                                            0x835DC4
#define pinstCBazaarSearchWnd                                      0x835DC8
#define pinstCGiveWnd                                              0x835DCC
#define pinstCTrackingWnd                                          0x835DD0
#define pinstCInspectWnd                                           0x835DD4
#define pinstCSocialEditWnd                                        0x835DD8
#define pinstCFeedbackWnd                                          0x835DDC
#define pinstCBugReportWnd                                         0x835DE0
#define pinstCVideoModesWnd                                        0x835DE4
#define pinstCTextEntryWnd                                         0x835DEC
#define pinstCFileSelectionWnd                                     0x835DF0
#define pinstCCompassWnd                                           0x835DF4
#define pinstCPlayerNotesWnd                                       0x835DF8
#define pinstCGemsGameWnd                                          0x835DFC
#define pinstCTimeLeftWnd                                          0x835E00
#define pinstCPetitionQWnd                                         0x835E04
#define pinstCSoulmarkWnd                                          0x835E08
#define pinstCStoryWnd                                             0x835E0C
#define pinstCJournalTextWnd                                       0x835E10
#define pinstCJournalCatWnd                                        0x835E14
#define pinstCBodyTintWnd                                          0x835E18
#define pinstCServerListWnd                                        0x835E1C
#define pinstCAvaZoneWnd                                           0x835E20
#define pinstCBlockedBuffWnd                                       0x835E24
#define pinstCBlockedPetBuffWnd                                    0x835E28
#define pinstCInvSlotMgr                                           0x835E2C
#define pinstCContainerMgr                                         0x835E30
#define pinstCAdventureLeaderboardWnd                              0x9728DC
#define pinstCAdventureRequestWnd                                  0x9728F8
#define pinstCAltStorageWnd                                        0x972958
#define pinstCAdventureStatsWnd                                    0x972914
#define pinstCBarterMerchantWnd                                    0x972B0C
#define pinstCBarterSearchWnd                                      0x972B28
#define pinstCBarterWnd                                            0x972B44
#define pinstCChatManager                                          0x972D0C
#define pinstCDynamicZoneWnd                                       0x972DE8
#define pinstCEQMainWnd                                            0x972E58
#define pinstCFellowshipWnd                                        0x972EBC
#define pinstCFindLocationWnd                                      0x972EF0
#define pinstCGroupSearchWnd                                       0x972FA0
#define pinstCGroupWnd                                             0x972FBC
#define pinstCGuildBankWnd                                         0x972FD8
#define pinstCGuildMgmtWnd                                         0x974FF8
#define pinstCGuildTributeMasterWnd                                0x975018
#define pinstCHotButtonWnd                                         0x975034
#define pinstCHotButtonWnd1                                        0x975034
#define pinstCHotButtonWnd2                                        0x975038
#define pinstCHotButtonWnd3                                        0x97503C
#define pinstCHotButtonWnd4                                        0x975040
#define pinstCItemDisplayManager                                   0x9750D8
#define pinstCItemExpTransferWnd                                   0x9750F8
#define pinstCLeadershipWnd                                        0x975174
#define pinstCLFGuildWnd                                           0x975190
#define pinstCMIZoneSelectWnd                                      0x9752B4
#define pinstCAdventureMerchantWnd                                 0x9753AC
#define pinstCConfirmationDialog                                   0x9753C8
#define pinstCPopupWndManager                                      0x9753C8
#define pinstCProgressionSelectionWnd                              0x9753FC
#define pinstCPvPLeaderboardWnd                                    0x975418
#define pinstCPvPStatsWnd                                          0x975434
#define pinstCSystemInfoDialogBox                                  0x975D9C
#define pinstCTargetOfTargetWnd                                    0x975DB8
#define pinstCTaskSelectWnd                                        0x975DEC
#define pinstCTaskTemplateSelectWnd                                0x975E08
#define pinstCTaskWnd                                              0x975E24
#define pinstCTipWndOFDAY                                          0x975E70
#define pinstCTipWndCONTEXT                                        0x975E74
#define pinstCTitleWnd                                             0x975E90
#define pinstCTradeskillWnd                                        0x975ED4
#define pinstCTributeBenefitWnd                                    0x975F20
#define pinstCTributeMasterWnd                                     0x975F3C
#define pinstCContextMenuManager                                   0x9838FC
#define pinstCVoiceMacroWnd                                        0x96726C
#define pinstCHtmlWnd                                              0x967288


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4A8F00
#define __ConvertItemTags                                          0x49D970
#define __ExecuteCmd                                               0x48F140
#define __get_melee_range                                          0x494140
#define __GetGaugeValueFromEQ                                      0x5CE4C0
#define __GetLabelFromEQ                                           0x5CECC0
#define __NewUIINI                                                 0x5CE0C0
#define __ProcessGameEvents                                        0x4D4440
#define __SendMessage                                              0x4B6660
#define CrashDetected                                              0x516AF0
#define DrawNetStatus                                              0x4EA390
#define Util__FastTime                                             0x62AEA0


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x46F050
#define AltAdvManager__IsAbilityReady                              0x46F090
#define AltAdvManager__GetAltAbility                               0x46F250

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x52BF30

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5353A0

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x6557B0

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x548210
#define CChatManager__InitContextMenu                              0x5489A0

// CChatService
#define CChatService__GetNumberOfFriends                           0x61BF20
#define CChatService__GetFriendName                                0x61BF30

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x54CB20

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x63C680
#define CComboWnd__Draw                                            0x63C830
#define CComboWnd__GetCurChoice                                    0x63C630
#define CComboWnd__GetListRect                                     0x63CB10
#define CComboWnd__GetTextRect                                     0x63C6B0
#define CComboWnd__InsertChoice                                    0x63CB80
#define CComboWnd__SetColors                                       0x63C5C0
#define CComboWnd__SetChoice                                       0x63C5F0

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x553210
#define CContainerWnd__vftable                                     0x6DF080

// CDisplay 
#define CDisplay__CleanGameUI                                      0x45E5C0
#define CDisplay__GetClickedActor                                  0x45BE60
#define CDisplay__GetUserDefinedColor                              0x45B2D0
#define CDisplay__GetWorldFilePath                                 0x45A880
#define CDisplay__is3dON                                           0x459490
#define CDisplay__ReloadUI                                         0x46A3A0
#define CDisplay__WriteTextHD2                                     0x45FD90

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x526220
#define CEditBaseWnd__SetSel                                       0x660670

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x6498A0
#define CEditWnd__GetCharIndexPt                                   0x64A6F0
#define CEditWnd__GetDisplayString                                 0x649A30
#define CEditWnd__GetHorzOffset                                    0x649CB0
#define CEditWnd__GetLineForPrintableChar                          0x64A1A0
#define CEditWnd__GetSelStartPt                                    0x64A930
#define CEditWnd__GetSTMLSafeText                                  0x649E50
#define CEditWnd__PointFromPrintableChar                           0x64A2B0
#define CEditWnd__SelectableCharFromPoint                          0x64A430
#define CEditWnd__SetEditable                                      0x649E20

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4BA7C0
#define CEverQuest__DropHeldItemOnGround                           0x4BF370
#define CEverQuest__dsp_chat                                       0x4BFFF0
#define CEverQuest__EnterZone                                      0x4D2F50
#define CEverQuest__GetBodyTypeDesc                                0x4B7EC0
#define CEverQuest__GetClassDesc                                   0x4B7620
#define CEverQuest__GetClassThreeLetterCode                        0x4B7C20
#define CEverQuest__GetDeityDesc                                   0x4B8510
#define CEverQuest__GetLangDesc                                    0x4B8230
#define CEverQuest__GetRaceDesc                                    0x4B84E0
#define CEverQuest__InterpretCmd                                   0x4C0950
#define CEverQuest__LeftClickedOnPlayer                            0x4D1B40
#define CEverQuest__RightClickedOnPlayer                           0x4D1F00
#define CEverQuest__SetGameState                                   0x4BA890

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x55E230
#define CGaugeWnd__CalcLinesFillRect                               0x55E2A0
#define CGaugeWnd__Draw                                            0x55E630

// CGuild
#define CGuild__FindMemberByName                                   0x417210

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x574150

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x57BD20
#define CInvSlotMgr__MoveItem                                      0x57BEC0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x57CDC0

// CInvSLot
#define CInvSlot__SliderComplete                                   0x57ACA0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x584440
#define CItemDisplayWnd__SetSpell                                  0x5CC590

// CLabel 
#define CLabel__Draw                                               0x589A60

// CListWnd 
#define CListWnd__AddColumn                                        0x63C3B0
#define CListWnd__AddColumn1                                       0x63BE90
#define CListWnd__AddLine                                          0x63BA70
#define CListWnd__AddString                                        0x63BC40
#define CListWnd__CalculateFirstVisibleLine                        0x638DA0
#define CListWnd__CalculateVSBRange                                0x63AA10
#define CListWnd__ClearAllSel                                      0x638510
#define CListWnd__CloseAndUpdateEditWindow                         0x6393B0
#define CListWnd__Compare                                          0x639760
#define CListWnd__Draw                                             0x63A710
#define CListWnd__DrawColumnSeparators                             0x63A580
#define CListWnd__DrawHeader                                       0x6386E0
#define CListWnd__DrawItem                                         0x639E70
#define CListWnd__DrawLine                                         0x63A220
#define CListWnd__DrawSeparator                                    0x63A620
#define CListWnd__EnsureVisible                                    0x638DF0
#define CListWnd__ExtendSel                                        0x639DA0
#define CListWnd__GetColumnMinWidth                                0x6382B0
#define CListWnd__GetColumnWidth                                   0x6381F0
#define CListWnd__GetCurSel                                        0x637CB0
#define CListWnd__GetHeaderRect                                    0x637DC0
#define CListWnd__GetItemAtPoint                                   0x6390C0
#define CListWnd__GetItemAtPoint1                                  0x639130
#define CListWnd__GetItemData                                      0x637FA0
#define CListWnd__GetItemHeight                                    0x638B40
#define CListWnd__GetItemIcon                                      0x638130
#define CListWnd__GetItemRect                                      0x638EB0
#define CListWnd__GetItemText                                      0x637FE0
#define CListWnd__GetSelList                                       0x63BD70
#define CListWnd__GetSeparatorRect                                 0x6396A0
#define CListWnd__RemoveLine                                       0x63C360
#define CListWnd__SetColors                                        0x637D30
#define CListWnd__SetColumnJustification                           0x638310
#define CListWnd__SetColumnWidth                                   0x638270
#define CListWnd__SetCurSel                                        0x637CF0
#define CListWnd__SetItemColor                                     0x63B640
#define CListWnd__SetItemData                                      0x6385B0
#define CListWnd__SetItemText                                      0x63B5C0
#define CListWnd__ShiftColumnSeparator                             0x639D10
#define CListWnd__Sort                                             0x63C3E0
#define CListWnd__ToggleSel                                        0x638480

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x59C830

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x59E210
#define CMerchantWnd__RequestBuyItem                               0x59F4A0
#define CMerchantWnd__RequestSellItem                              0x59E470
#define CMerchantWnd__SelectBuySellSlot                            0x59F1E0

// CObfuscator
#define CObfuscator__doit                                          0x61D590

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x6512D0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x527AE0
#define CSidlScreenWnd__CalculateVSBRange                          0x641D10
#define CSidlScreenWnd__ConvertToRes                               0x642461
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x642C60
#define CSidlScreenWnd__CSidlScreenWnd1                            0x643F20
#define CSidlScreenWnd__CSidlScreenWnd2                            0x643FD0
#define CSidlScreenWnd__dCSidlScreenWnd                            0x6437D0
#define CSidlScreenWnd__DrawSidlPiece                              0x642940
#define CSidlScreenWnd__EnableIniStorage                           0x642400
#define CSidlScreenWnd__GetSidlPiece                               0x642B40
#define CSidlScreenWnd__Init1                                      0x643D30
#define CSidlScreenWnd__LoadIniInfo                                0x642D10
#define CSidlScreenWnd__LoadIniListWnd                             0x6425B0
#define CSidlScreenWnd__LoadSidlScreen                             0x642770
#define CSidlScreenWnd__StoreIniInfo                               0x641F40
#define CSidlScreenWnd__WndNotification                            0x6428A0

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x50B410

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x662470
#define CSliderWnd__SetValue                                       0x662570
#define CSliderWnd__SetNumTicks                                    0x662AB0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x5CB2E0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x65E970
#define CStmlWnd__CalculateVSBRange                                0x656D00
#define CStmlWnd__CanBreakAtCharacter                              0x656E40
#define CStmlWnd__FastForwardToEndOfTag                            0x657950
#define CStmlWnd__GetNextTagPiece                                  0x657870
#define CStmlWnd__GetSTMLText                                      0x54CAC0
#define CStmlWnd__GetThisChar                                      0x67E850
#define CStmlWnd__GetVisiableText                                  0x658B70
#define CStmlWnd__InitializeWindowVariables                        0x65ACD0
#define CStmlWnd__MakeStmlColorTag                                 0x656400
#define CStmlWnd__MakeWndNotificationTag                           0x6564A0
#define CStmlWnd__StripFirstSTMLLines                              0x65E6F0
#define CStmlWnd__UpdateHistoryString                              0x6593D0

// CTabWnd 
#define CTabWnd__Draw                                              0x661CF0
#define CTabWnd__DrawCurrentPage                                   0x6616E0
#define CTabWnd__DrawTab                                           0x6614C0
#define CTabWnd__GetCurrentPage                                    0x661960
#define CTabWnd__GetPageClientRect                                 0x661190
#define CTabWnd__GetPageFromTabIndex                               0x6613F0
#define CTabWnd__GetPageInnerRect                                  0x6611F0
#define CTabWnd__GetTabInnerRect                                   0x661370
#define CTabWnd__GetTabRect                                        0x661280
#define CTabWnd__IndexInBounds                                     0x66148D
#define CTabWnd__InsertPage                                        0x661F10
#define CTabWnd__SetPage                                           0x6619A0
#define CTabWnd__SetPageRect                                       0x661C20
#define CTabWnd__UpdatePage                                        0x661E90

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x413E20

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x644330

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x667B90

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x637A20

// CXRect 
#define CXRect__CenterPoint                                        0x52B6F0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x412340
#define CXStr__CXStr1                                              0x507280
#define CXStr__CXStr3                                              0x62C5A0
#define CXStr__dCXStr                                              0x63C530
#define CXStr__operator_equal1                                     0x62C760
#define CXStr__operator_plus_equal1                                0x62D650

// CXWnd 
#define CXWnd__BringToTop                                          0x63D370
#define CXWnd__Center                                              0x640A60
#define CXWnd__ClrFocus                                            0x63D0A0
#define CXWnd__DoAllDrawing                                        0x641710
#define CXWnd__DrawChildren                                        0x641840
#define CXWnd__DrawColoredRect                                     0x63D5D0
#define CXWnd__DrawTooltip                                         0x641630
#define CXWnd__DrawTooltipAtPoint                                  0x6408B0
#define CXWnd__GetBorderFrame                                      0x63DA90
#define CXWnd__GetChildWndAt                                       0x6403B0
#define CXWnd__GetClientClipRect                                   0x63D9D0
#define CXWnd__GetFirstChildWnd                                    0x63D410
#define CXWnd__GetNextChildWnd                                     0x640370
#define CXWnd__GetNextSib                                          0x63D430
#define CXWnd__GetScreenClipRect                                   0x640C80
#define CXWnd__GetScreenRect                                       0x63DC70
#define CXWnd__GetTooltipRect                                      0x63D800
#define CXWnd__GetWindowTextA                                      0x4DF720
#define CXWnd__IsActive                                            0x645410
#define CXWnd__IsDescendantOf                                      0x63DA40
#define CXWnd__IsReallyVisible                                     0x640350
#define CXWnd__IsType                                              0x6638C0
#define CXWnd__Move                                                0x63FE80
#define CXWnd__Move1                                               0x63FF20
#define CXWnd__ProcessTransition                                   0x63D340
#define CXWnd__Refade                                              0x63D150
#define CXWnd__Resize                                              0x640DC0
#define CXWnd__Right                                               0x640BD0
#define CXWnd__SetFirstChildPointer                                0x63DEC0
#define CXWnd__SetFocus                                            0x63F1B0
#define CXWnd__SetKeyTooltip                                       0x63DF30
#define CXWnd__SetMouseOver                                        0x63DF00
#define CXWnd__SetNextSibPointer                                   0x63DEE0
#define CXWnd__StartFade                                           0x63D390

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x6468E0
#define CXWndManager__DrawWindows                                  0x646520
#define CXWndManager__GetFirstChildWnd                             0x645DB0
#define CXWndManager__GetKeyboardFlags                             0x6450F0
#define CXWndManager__HandleKeyboardMsg                            0x645600
#define CXWndManager__RemoveWnd                                    0x645520

// CDBStr
#define CDBStr__GetString                                          0x457E10

// EQ_Character 
#define EQ_Character__CastRay                                      0x68A020
#define EQ_Character__CastSpell                                    0x422F90
#define EQ_Character__Cur_HP                                       0x42A420
#define EQ_Character__GetAACastingTimeModifier                     0x41E270
#define EQ_Character__GetCharInfo2                                 0x60E8B0
#define EQ_Character__GetFocusCastingTimeModifier                  0x41A920
#define EQ_Character__GetFocusRangeModifier                        0x41AA50
#define EQ_Character__Max_Endurance                                0x429210
#define EQ_Character__Max_HP                                       0x4290C0
#define EQ_Character__Max_Mana                                     0x4EF330
#define EQ_Character__doCombatAbility                              0x4EE1B0
#define EQ_Character__UseSkill                                     0x4358D0
#define EQ_Character__GetConLevel                                  0x4EB760

// EQ_Item 
#define EQ_Item__CanDrop                                           0x4E1250
#define EQ_Item__GetItemLinkHash                                   0x603210
#define EQ_Item__IsStackable                                       0x5FD440

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x470240
#define EQ_LoadingS__Array                                         0x72C160

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x4F2250
#define EQ_PC__GetAltAbilityIndex                                  0x607C30
#define EQ_PC__GetCombatAbility                                    0x607CC0
#define EQ_PC__GetCombatAbilityTimer                               0x607D70
#define EQ_PC__GetItemTimerValue                                   0x4ED4E0
#define EQ_PC__HasLoreItem                                         0x4F0870

// EQItemList 
#define EQItemList__dEQItemList                                    0x492A10
#define EQItemList__EQItemList                                     0x492960

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x4577A0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x4F6C10
#define EQPlayer__dEQPlayer                                        0x4FB040
#define EQPlayer__DoAttack                                         0x5064E0
#define EQPlayer__EQPlayer                                         0x4FD7B0
#define EQPlayer__SetNameSpriteState                               0x4F92F0
#define EQPlayer__SetNameSpriteTint                                0x4F6C80
#define EQPlayer__IsBodyType_j                                     0x689A50

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x4FE5B0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4E2DE0
#define KeypressHandler__AttachKeyToEqCommand                      0x4E2E20
#define KeypressHandler__ClearCommandStateArray                    0x4E2BF0
#define KeypressHandler__HandleKeyDown                             0x4E1800
#define KeypressHandler__HandleKeyUp                               0x4E1B00
#define KeypressHandler__SaveKeymapping                            0x4E2CC0

// MapViewMap 
#define MapViewMap__Clear                                          0x598870
#define MapViewMap__SaveEx                                         0x599240

#define OtherCharData__GetAltCurrency                              0x624100

// StringTable 
#define StringTable__getString                                     0x5FCE50
