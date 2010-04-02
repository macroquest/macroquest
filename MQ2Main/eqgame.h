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
#define __ExpectedVersionDate                                     "May 31 2007"
#define __ExpectedVersionTime                                     "18:23:38"
#define __ActualVersionDate                                        0x6D8DEC
#define __ActualVersionTime                                        0x6D8DF8

#define __ClientOverride                                           0 
#define __MacroQuestWinClassName                                  "__MacroQuestTray" 
#define __MacroQuestWinName                                       "MacroQuest" 

// Memory Protection 
#define __MemChecker0                                              0x4E75D0
#define __MemChecker1                                              0x62A7C0
#define __MemChecker2                                              0x517850
#define __MemChecker3                                              0x517900
#define __MemChecker4                                              0x5F7900
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
#define pinstCGroupSearchWnd                                       0x972FC4
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
#define __CastRay                                                  0x4A8EC0
#define __ConvertItemTags                                          0x49D930
#define __ExecuteCmd                                               0x48F0B0
#define __get_melee_range                                          0x494100
#define __GetGaugeValueFromEQ                                      0x5CE430
#define __GetLabelFromEQ                                           0x5CEC30
#define __NewUIINI                                                 0x5CE030
#define __ProcessGameEvents                                        0x4D4400
#define __SendMessage                                              0x4B6620
#define CrashDetected                                              0x516A60
#define DrawNetStatus                                              0x4EA350
#define Util__FastTime                                             0x62AE50


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x46F030
#define AltAdvManager__IsAbilityReady                              0x46F070
#define AltAdvManager__GetAltAbility                               0x46F1C0

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x52BEA0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x535310

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x655710

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x548180
#define CChatManager__InitContextMenu                              0x548910

// CChatService
#define CChatService__GetNumberOfFriends                           0x61BE90
#define CChatService__GetFriendName                                0x61BEA0

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x54CA90

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x63C580
#define CComboWnd__Draw                                            0x63C730
#define CComboWnd__GetCurChoice                                    0x63C530
#define CComboWnd__GetListRect                                     0x63CA10
#define CComboWnd__GetTextRect                                     0x63C5B0
#define CComboWnd__InsertChoice                                    0x63CA80
#define CComboWnd__SetColors                                       0x63C4C0
#define CComboWnd__SetChoice                                       0x63C4F0

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x553180
#define CContainerWnd__vftable                                     0x6DF080

// CDisplay 
#define CDisplay__CleanGameUI                                      0x45E5A0
#define CDisplay__GetClickedActor                                  0x45BE40
#define CDisplay__GetUserDefinedColor                              0x45B2B0
#define CDisplay__GetWorldFilePath                                 0x45A860
#define CDisplay__is3dON                                           0x459470
#define CDisplay__ReloadUI                                         0x46A380
#define CDisplay__WriteTextHD2                                     0x45FD70

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x526190
#define CEditBaseWnd__SetSel                                       0x6605D0

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x6497A0
#define CEditWnd__GetCharIndexPt                                   0x64A5F0
#define CEditWnd__GetDisplayString                                 0x649930
#define CEditWnd__GetHorzOffset                                    0x649BB0
#define CEditWnd__GetLineForPrintableChar                          0x64A0A0
#define CEditWnd__GetSelStartPt                                    0x64A830
#define CEditWnd__GetSTMLSafeText                                  0x649D50
#define CEditWnd__PointFromPrintableChar                           0x64A1B0
#define CEditWnd__SelectableCharFromPoint                          0x64A330
#define CEditWnd__SetEditable                                      0x649D20

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4BA780
#define CEverQuest__DropHeldItemOnGround                           0x4BF330
#define CEverQuest__dsp_chat                                       0x4BFFB0
#define CEverQuest__EnterZone                                      0x4D2F10
#define CEverQuest__GetBodyTypeDesc                                0x4B7E80
#define CEverQuest__GetClassDesc                                   0x4B75E0
#define CEverQuest__GetClassThreeLetterCode                        0x4B7BE0
#define CEverQuest__GetDeityDesc                                   0x4B84D0
#define CEverQuest__GetLangDesc                                    0x4B81F0
#define CEverQuest__GetRaceDesc                                    0x4B84A0
#define CEverQuest__InterpretCmd                                   0x4C0910
#define CEverQuest__LeftClickedOnPlayer                            0x4D1B00
#define CEverQuest__RightClickedOnPlayer                           0x4D1EC0
#define CEverQuest__SetGameState                                   0x4BA850

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x55E1A0
#define CGaugeWnd__CalcLinesFillRect                               0x55E210
#define CGaugeWnd__Draw                                            0x55E5A0

// CGuild
#define CGuild__FindMemberByName                                   0x417210

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x5740C0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x57BC90
#define CInvSlotMgr__MoveItem                                      0x57BE30

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x57CD30

// CInvSLot
#define CInvSlot__SliderComplete                                   0x57AC10

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x584350
#define CItemDisplayWnd__SetSpell                                  0x5CC4A0

// CLabel 
#define CLabel__Draw                                               0x589970

// CListWnd 
#define CListWnd__AddColumn                                        0x63C2B0
#define CListWnd__AddColumn1                                       0x63BD90
#define CListWnd__AddLine                                          0x63B970
#define CListWnd__AddString                                        0x63BB40
#define CListWnd__CalculateFirstVisibleLine                        0x638CA0
#define CListWnd__CalculateVSBRange                                0x63A910
#define CListWnd__ClearAllSel                                      0x638410
#define CListWnd__CloseAndUpdateEditWindow                         0x6392B0
#define CListWnd__Compare                                          0x639660
#define CListWnd__Draw                                             0x63A610
#define CListWnd__DrawColumnSeparators                             0x63A480
#define CListWnd__DrawHeader                                       0x6385E0
#define CListWnd__DrawItem                                         0x639D70
#define CListWnd__DrawLine                                         0x63A120
#define CListWnd__DrawSeparator                                    0x63A520
#define CListWnd__EnsureVisible                                    0x638CF0
#define CListWnd__ExtendSel                                        0x639CA0
#define CListWnd__GetColumnMinWidth                                0x6381B0
#define CListWnd__GetColumnWidth                                   0x6380F0
#define CListWnd__GetCurSel                                        0x637BB0
#define CListWnd__GetHeaderRect                                    0x637CC0
#define CListWnd__GetItemAtPoint                                   0x638FC0
#define CListWnd__GetItemAtPoint1                                  0x639030
#define CListWnd__GetItemData                                      0x637EA0
#define CListWnd__GetItemHeight                                    0x638A40
#define CListWnd__GetItemIcon                                      0x638030
#define CListWnd__GetItemRect                                      0x638DB0
#define CListWnd__GetItemText                                      0x637EE0
#define CListWnd__GetSelList                                       0x63BC70
#define CListWnd__GetSeparatorRect                                 0x6395A0
#define CListWnd__RemoveLine                                       0x63C260
#define CListWnd__SetColors                                        0x637C30
#define CListWnd__SetColumnJustification                           0x638210
#define CListWnd__SetColumnWidth                                   0x638170
#define CListWnd__SetCurSel                                        0x637BF0
#define CListWnd__SetItemColor                                     0x63B540
#define CListWnd__SetItemData                                      0x6384B0
#define CListWnd__SetItemText                                      0x63B4C0
#define CListWnd__ShiftColumnSeparator                             0x639C10
#define CListWnd__Sort                                             0x63C2E0
#define CListWnd__ToggleSel                                        0x638380

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x59C740

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x59E120
#define CMerchantWnd__RequestBuyItem                               0x59F3B0
#define CMerchantWnd__RequestSellItem                              0x59E380
#define CMerchantWnd__SelectBuySellSlot                            0x59F0F0

// CObfuscator
#define CObfuscator__doit                                          0x61D500

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x6511D0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x527A50
#define CSidlScreenWnd__CalculateVSBRange                          0x641C10
#define CSidlScreenWnd__ConvertToRes                               0x642361
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x642B60
#define CSidlScreenWnd__CSidlScreenWnd1                            0x643E20
#define CSidlScreenWnd__CSidlScreenWnd2                            0x643ED0
#define CSidlScreenWnd__dCSidlScreenWnd                            0x6436D0
#define CSidlScreenWnd__DrawSidlPiece                              0x642840
#define CSidlScreenWnd__EnableIniStorage                           0x642300
#define CSidlScreenWnd__GetSidlPiece                               0x642A40
#define CSidlScreenWnd__Init1                                      0x643C30
#define CSidlScreenWnd__LoadIniInfo                                0x642C10
#define CSidlScreenWnd__LoadIniListWnd                             0x6424B0
#define CSidlScreenWnd__LoadSidlScreen                             0x642670
#define CSidlScreenWnd__StoreIniInfo                               0x641E40
#define CSidlScreenWnd__WndNotification                            0x6427A0

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x50B380

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x6623D0
#define CSliderWnd__SetValue                                       0x6624D0
#define CSliderWnd__SetNumTicks                                    0x662A10

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x5CB1F0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x65E8D0
#define CStmlWnd__CalculateVSBRange                                0x656C60
#define CStmlWnd__CanBreakAtCharacter                              0x656DA0
#define CStmlWnd__FastForwardToEndOfTag                            0x6578B0
#define CStmlWnd__GetNextTagPiece                                  0x6577D0
#define CStmlWnd__GetSTMLText                                      0x54CA30
#define CStmlWnd__GetThisChar                                      0x67E7B0
#define CStmlWnd__GetVisiableText                                  0x658AD0
#define CStmlWnd__InitializeWindowVariables                        0x65AC30
#define CStmlWnd__MakeStmlColorTag                                 0x656360
#define CStmlWnd__MakeWndNotificationTag                           0x656400
#define CStmlWnd__StripFirstSTMLLines                              0x65E650
#define CStmlWnd__UpdateHistoryString                              0x659330

// CTabWnd 
#define CTabWnd__Draw                                              0x661C50
#define CTabWnd__DrawCurrentPage                                   0x661640
#define CTabWnd__DrawTab                                           0x661420
#define CTabWnd__GetCurrentPage                                    0x6618C0
#define CTabWnd__GetPageClientRect                                 0x6610F0
#define CTabWnd__GetPageFromTabIndex                               0x661350
#define CTabWnd__GetPageInnerRect                                  0x661150
#define CTabWnd__GetTabInnerRect                                   0x6612D0
#define CTabWnd__GetTabRect                                        0x6611E0
#define CTabWnd__IndexInBounds                                     0x6613ED
#define CTabWnd__InsertPage                                        0x661E70
#define CTabWnd__SetPage                                           0x661900
#define CTabWnd__SetPageRect                                       0x661B80
#define CTabWnd__UpdatePage                                        0x661DF0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x413E20

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x644230

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x667AF0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x637920

// CXRect 
#define CXRect__CenterPoint                                        0x52B660

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x412340
#define CXStr__CXStr1                                              0x5071F0
#define CXStr__CXStr3                                              0x62C500
#define CXStr__dCXStr                                              0x63C430
#define CXStr__operator_equal1                                     0x62C6C0
#define CXStr__operator_plus_equal1                                0x62D5B0

// CXWnd 
#define CXWnd__BringToTop                                          0x63D270
#define CXWnd__Center                                              0x640960
#define CXWnd__ClrFocus                                            0x63CFA0
#define CXWnd__DoAllDrawing                                        0x641610
#define CXWnd__DrawChildren                                        0x641740
#define CXWnd__DrawColoredRect                                     0x63D4D0
#define CXWnd__DrawTooltip                                         0x641530
#define CXWnd__DrawTooltipAtPoint                                  0x6407B0
#define CXWnd__GetBorderFrame                                      0x63DA10
#define CXWnd__GetChildWndAt                                       0x6402B0
#define CXWnd__GetClientClipRect                                   0x63D8D0
#define CXWnd__GetFirstChildWnd                                    0x63D310
#define CXWnd__GetNextChildWnd                                     0x640270
#define CXWnd__GetNextSib                                          0x63D330
#define CXWnd__GetScreenClipRect                                   0x640B80
#define CXWnd__GetScreenRect                                       0x63DB70
#define CXWnd__GetTooltipRect                                      0x63D700
#define CXWnd__GetWindowTextA                                      0x4DF6E0
#define CXWnd__IsActive                                            0x645310
#define CXWnd__IsDescendantOf                                      0x63D940
#define CXWnd__IsReallyVisible                                     0x640250
#define CXWnd__IsType                                              0x663820
#define CXWnd__Move                                                0x63FD80
#define CXWnd__Move1                                               0x63FE20
#define CXWnd__ProcessTransition                                   0x63D240
#define CXWnd__Refade                                              0x63D050
#define CXWnd__Resize                                              0x640CC0
#define CXWnd__Right                                               0x640AD0
#define CXWnd__SetFirstChildPointer                                0x63DDC0
#define CXWnd__SetFocus                                            0x63F0B0
#define CXWnd__SetKeyTooltip                                       0x63DE30
#define CXWnd__SetMouseOver                                        0x63DE00
#define CXWnd__SetNextSibPointer                                   0x63DDE0
#define CXWnd__StartFade                                           0x63D290

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x6467E0
#define CXWndManager__DrawWindows                                  0x646420
#define CXWndManager__GetFirstChildWnd                             0x645CB0
#define CXWndManager__GetKeyboardFlags                             0x644FF0
#define CXWndManager__HandleKeyboardMsg                            0x645500
#define CXWndManager__RemoveWnd                                    0x645420

// CDBStr
#define CDBStr__GetString                                          0x457DF0

// EQ_Character 
#define EQ_Character__CastRay                                      0x689F80
#define EQ_Character__CastSpell                                    0x422F30
#define EQ_Character__Cur_HP                                       0x42A3C0
#define EQ_Character__GetAACastingTimeModifier                     0x41E250
#define EQ_Character__GetCharInfo2                                 0x60E820
#define EQ_Character__GetFocusCastingTimeModifier                  0x41A920
#define EQ_Character__GetFocusRangeModifier                        0x41AA50
#define EQ_Character__Max_Endurance                                0x4291B0
#define EQ_Character__Max_HP                                       0x429060
#define EQ_Character__Max_Mana                                     0x4EF2F0
#define EQ_Character__doCombatAbility                              0x4EE170
#define EQ_Character__UseSkill                                     0x435880
#define EQ_Character__GetConLevel                                  0x4EB720

// EQ_Item 
#define EQ_Item__CanDrop                                           0x4E1210
#define EQ_Item__GetItemLinkHash                                   0x603180
#define EQ_Item__IsStackable                                       0x5FD3B0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x4701B0
#define EQ_LoadingS__Array                                         0x72C160

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x4F2210
#define EQ_PC__GetAltAbilityIndex                                  0x607BA0
#define EQ_PC__GetCombatAbility                                    0x607C30
#define EQ_PC__GetCombatAbilityTimer                               0x607CE0
#define EQ_PC__GetItemTimerValue                                   0x4ED4A0
#define EQ_PC__HasLoreItem                                         0x4F0830

// EQItemList 
#define EQItemList__dEQItemList                                    0x492980
#define EQItemList__EQItemList                                     0x4928D0

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x457780

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x4F6BD0
#define EQPlayer__dEQPlayer                                        0x4FB000
#define EQPlayer__DoAttack                                         0x506450
#define EQPlayer__EQPlayer                                         0x4FD720
#define EQPlayer__SetNameSpriteState                               0x4F92B0
#define EQPlayer__SetNameSpriteTint                                0x4F6C40
#define EQPlayer__IsBodyType_j                                     0x6899B0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x4FE520

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4E2DA0
#define KeypressHandler__AttachKeyToEqCommand                      0x4E2DE0
#define KeypressHandler__ClearCommandStateArray                    0x4E2BB0
#define KeypressHandler__HandleKeyDown                             0x4E17C0
#define KeypressHandler__HandleKeyUp                               0x4E1AC0
#define KeypressHandler__SaveKeymapping                            0x4E2C80

// MapViewMap 
#define MapViewMap__Clear                                          0x598780
#define MapViewMap__SaveEx                                         0x599150

#define OtherCharData__GetAltCurrency                              0x6240B0

// StringTable 
#define StringTable__getString                                     0x5FCDC0
