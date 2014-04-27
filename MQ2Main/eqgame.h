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
#define __ExpectedVersionDate                                     "Nov 17 2011"
#define __ExpectedVersionTime                                     "15:54:33"
#define __ActualVersionDate                                        0x8D6AAC
#define __ActualVersionTime                                        0x8D6AB8

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x531E00
#define __MemChecker1                                              0x7E4B30
#define __MemChecker2                                              0x5AFB80
#define __MemChecker3                                              0x5AFAD0
#define __MemChecker4                                              0x806EB0
#define __EncryptPad0                                              0x9A5798
#define __EncryptPad1                                              0xA19628
#define __EncryptPad2                                              0x9BD638
#define __EncryptPad3                                              0x9BD238
#define __EncryptPad4                                              0xA1B0D8
#define __AC1                                                      0x6D69F0
#define __AC2                                                      0x4EDD05
#define __AC3                                                      0x500978
#define __AC4                                                      0x5063D4
#define __AC5                                                      0x5125AC
#define __AC6                                                      0x515E3E
#define __AC7                                                      0x50E10B
#define __AC1_Data                                                 0x8BD01D
// Direct Input
#define DI8__Main                                                  0xC98228
#define DI8__Keyboard                                              0xC9822C
#define DI8__Mouse                                                 0xC98230
#define __AltTimerReady                                            0xB60889
#define __Attack                                                   0xC9407A
#define __Autofire                                                 0xC9407B
#define __BindList                                                 0x98EAC0
#define __Clicks                                                   0xC1DB8C
#define __CommandList                                              0x990098
#define __CurrentMapLabel                                          0xCC3F08
#define __CurrentSocial                                            0x97B3F8
//#define __DoAbilityAvailable                                       0x0
#define __DoAbilityList                                            0xC54A54
#define __do_loot                                                  0x4C1D60
#define __DrawHandler                                              0x1320BA4
#define __GroupCount                                               0xC0E74A
#define __Guilds                                                   0xC10AD8
#define __gWorld                                                   0xC10A04
#define __HotkeyPage                                               0xC7D630
#define __HWnd                                                     0xC97F78
#define __InChatMode                                               0xC1DAC4
#define __LastTell                                                 0xC1F96C
#define __LMouseHeldTime                                           0xC1DBF8
#define __Mouse                                                    0xC98234
#define __MouseLook                                                0xC1DB5A
#define __MouseEventTime                                           0xC9435C
#define __NetStatusToggle                                          0xC1DB5D
#define __PCNames                                                  0xC1F014
#define __RangeAttackReady                                         0xC1ECAC
#define __RMouseHeldTime                                           0xC1DBF4
#define __RunWalkState                                             0xC1DAC8
#define __ScreenMode                                               0xB5DBE8
#define __ScreenX                                                  0xC1DA78
#define __ScreenY                                                  0xC1DA7C
#define __ScreenXMax                                               0xC1DA80
#define __ScreenYMax                                               0xC1DA84
#define __ServerHost                                               0xC0E68C
#define __ServerName                                               0xC54A14
#define __ShiftKeyDown                                             0xC1E144
#define __ShowNames                                                0xC1EEB8
#define __Socials                                                  0xC54B14


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xC1A3F0
#define instEQZoneInfo                                             0xC1DD40
#define instKeypressHandler                                        0xC94358
#define pinstActiveBanker                                          0xC10AAC
#define pinstActiveCorpse                                          0xC10AB0
#define pinstActiveGMaster                                         0xC10AB4
#define pinstActiveMerchant                                        0xC10AA8
#define pinstAltAdvManager                                         0xB5EB18
#define pinstAuraMgr                                               0xA2DD70
#define pinstBandageTarget                                         0xC10A94
#define pinstCamActor                                              0xB5E590
#define pinstCDBStr                                                0xB5DBC0
#define pinstCDisplay                                              0xC10ABC
#define pinstCEverQuest                                            0xC983B0
#define pinstCharData                                              0xC10A78
#define pinstCharSpawn                                             0xC10AA0
#define pinstControlledMissile                                     0xC10A74
#define pinstControlledPlayer                                      0xC10AA0
#define pinstCSidlManager                                          0x1321074
#define pinstCXWndManager                                          0x132106C
#define instDynamicZone                                            0xC19E48
#define pinstDZMember                                              0xC19F58
#define pinstDZTimerInfo                                           0xC19F5C
#define pinstEQItemList                                            0xC0D7F0
#define instEQMisc                                                 0xB5DB28
#define pinstEQSoundManager                                        0xB5EB88
#define instExpeditionLeader                                       0xC19E92
#define instExpeditionName                                         0xC19ED2
#define pinstGroup                                                 0xC0E746
#define pinstImeManager                                            0x1321078
#define pinstLocalPlayer                                           0xC10A8C
#define pinstMercenaryData                                         0xC947D8
#define pinstModelPlayer                                           0xC10AB8
#define pinstPCData                                                0xC10A78
#define pinstSkillMgr                                              0xC94DF0
#define pinstSpawnManager                                          0xC94A78
#define pinstSpellManager                                          0xC94E30
#define pinstSpellSets                                             0xC8D388
#define pinstStringTable                                           0xC10A20
#define pinstSwitchManager                                         0xC0E358
#define pinstTarget                                                0xC10AA4
#define pinstTargetObject                                          0xC10A7C
#define pinstTargetSwitch                                          0xC10A80
#define pinstTaskMember                                            0xB5DAF0
#define pinstTrackTarget                                           0xC10A98
#define pinstTradeTarget                                           0xC10A88
#define instTributeActive                                          0xB5DB4D
#define pinstViewActor                                             0xB5E58C
#define pinstWorldData                                             0xC10A5C


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0xA2B4D0
#define pinstCAudioTriggersWindow                                  0xA2B468
#define pinstCCharacterSelect                                      0xB5E458
#define pinstCFacePick                                             0xB5E408
#define pinstCNoteWnd                                              0xB5E410
#define pinstCBookWnd                                              0xB5E414
#define pinstCPetInfoWnd                                           0xB5E418
#define pinstCTrainWnd                                             0xB5E41C
#define pinstCSkillsWnd                                            0xB5E420
#define pinstCSkillsSelectWnd                                      0xB5E424
#define pinstCCombatSkillSelectWnd                                 0xB5E428
#define pinstCFriendsWnd                                           0xB5E42C
#define pinstCAuraWnd                                              0xB5E430
#define pinstCRespawnWnd                                           0xB5E434
#define pinstCBandolierWnd                                         0xB5E438
#define pinstCPotionBeltWnd                                        0xB5E43C
#define pinstCAAWnd                                                0xB5E440
#define pinstCGroupSearchFiltersWnd                                0xB5E444
#define pinstCLoadskinWnd                                          0xB5E448
#define pinstCAlarmWnd                                             0xB5E44C
#define pinstCMusicPlayerWnd                                       0xB5E450
#define pinstCMailWnd                                              0xB5E45C
#define pinstCMailCompositionWnd                                   0xB5E460
#define pinstCMailAddressBookWnd                                   0xB5E464
#define pinstCRaidWnd                                              0xB5E46C
#define pinstCRaidOptionsWnd                                       0xB5E470
#define pinstCBreathWnd                                            0xB5E474
#define pinstCMapViewWnd                                           0xB5E478
#define pinstCMapToolbarWnd                                        0xB5E47C
#define pinstCEditLabelWnd                                         0xB5E480
#define pinstCTargetWnd                                            0xB5E484
#define pinstCColorPickerWnd                                       0xB5E488
#define pinstCPlayerWnd                                            0xB5E48C
#define pinstCOptionsWnd                                           0xB5E490
#define pinstCBuffWindowNORMAL                                     0xB5E494
#define pinstCBuffWindowSHORT                                      0xB5E498
#define pinstCharacterCreation                                     0xB5E49C
#define pinstCCursorAttachment                                     0xB5E4A0
#define pinstCCastingWnd                                           0xB5E4A4
#define pinstCCastSpellWnd                                         0xB5E4A8
#define pinstCSpellBookWnd                                         0xB5E4AC
#define pinstCInventoryWnd                                         0xB5E4B0
#define pinstCBankWnd                                              0xB5E4B4
#define pinstCQuantityWnd                                          0xB5E4B8
#define pinstCLootWnd                                              0xB5E4BC
#define pinstCActionsWnd                                           0xB5E4C0
#define pinstCCombatAbilityWnd                                     0xB5E4C4
#define pinstCMerchantWnd                                          0xB5E4C8
#define pinstCTradeWnd                                             0xB5E4CC
#define pinstCSelectorWnd                                          0xB5E4D0
#define pinstCBazaarWnd                                            0xB5E4D4
#define pinstCBazaarSearchWnd                                      0xB5E4D8
#define pinstCGiveWnd                                              0xB5E4F4
#define pinstCTrackingWnd                                          0xB5E4FC
#define pinstCInspectWnd                                           0xB5E500
#define pinstCSocialEditWnd                                        0xB5E504
#define pinstCFeedbackWnd                                          0xB5E508
#define pinstCBugReportWnd                                         0xB5E50C
#define pinstCVideoModesWnd                                        0xB5E510
#define pinstCTextEntryWnd                                         0xB5E518
#define pinstCFileSelectionWnd                                     0xB5E51C
#define pinstCCompassWnd                                           0xB5E520
#define pinstCPlayerNotesWnd                                       0xB5E524
#define pinstCGemsGameWnd                                          0xB5E528
#define pinstCTimeLeftWnd                                          0xB5E52C
#define pinstCPetitionQWnd                                         0xB5E540
#define pinstCSoulmarkWnd                                          0xB5E544
#define pinstCStoryWnd                                             0xB5E548
#define pinstCJournalTextWnd                                       0xB5E54C
#define pinstCJournalCatWnd                                        0xB5E550
#define pinstCBodyTintWnd                                          0xB5E554
#define pinstCServerListWnd                                        0xB5E558
#define pinstCAvaZoneWnd                                           0xB5E560
#define pinstCBlockedBuffWnd                                       0xB5E564
#define pinstCBlockedPetBuffWnd                                    0xB5E568
#define pinstCInvSlotMgr                                           0xB5E584
#define pinstCContainerMgr                                         0xB5E588
#define pinstCAdventureLeaderboardWnd                              0xCC0AD8
#define pinstCAdventureRequestWnd                                  0xCC0AA0
#define pinstCAltStorageWnd                                        0xCC0B50
#define pinstCAdventureStatsWnd                                    0xCC0AD8
#define pinstCBarterMerchantWnd                                    0xCC0FA8
#define pinstCBarterSearchWnd                                      0xCC0FE0
#define pinstCBarterWnd                                            0xCC1018
#define pinstCChatManager                                          0xCC1410
#define pinstCDynamicZoneWnd                                       0xCC1600
#define pinstCEQMainWnd                                            0xCC16C0
#define pinstCFellowshipWnd                                        0xCC1788
#define pinstCFindLocationWnd                                      0xCC17F0
#define pinstCGroupSearchWnd                                       0xCC1950
#define pinstCGroupWnd                                             0xCC1988
#define pinstCGuildBankWnd                                         0xCC19C0
#define pinstCGuildMgmtWnd                                         0xCC3A30
#define pinstCGuildTributeMasterWnd                                0xCC5650
#define pinstCHotButtonWnd                                         0xCC3A84
#define pinstCHotButtonWnd1                                        0xCC3A84
#define pinstCHotButtonWnd2                                        0xCC3A88
#define pinstCHotButtonWnd3                                        0xCC3A8C
#define pinstCHotButtonWnd4                                        0xCC3AE4
#define pinstCItemDisplayManager                                   0xCC3C00
#define pinstCItemExpTransferWnd                                   0xCC3C3C
#define pinstCLeadershipWnd                                        0xCC3D68
#define pinstCLFGuildWnd                                           0xCC3DA0
#define pinstCMIZoneSelectWnd                                      0xCC4038
#define pinstCAdventureMerchantWnd                                 0xCC42E8
#define pinstCConfirmationDialog                                   0xCC4320
#define pinstCPopupWndManager                                      0xCC4320
#define pinstCProgressionSelectionWnd                              0xCC4388
#define pinstCPvPLeaderboardWnd                                    0xCC43C0
#define pinstCPvPStatsWnd                                          0xCC43F8
#define pinstCSystemInfoDialogBox                                  0xCC46E0
#define pinstCTargetOfTargetWnd                                    0xCC5300
#define pinstCTaskSelectWnd                                        0xCC5368
#define pinstCTaskTemplateSelectWnd                                0xCC53A0
#define pinstCTaskWnd                                              0xCC53D8
#define pinstCTipWndOFDAY                                          0xCC54D0
#define pinstCTipWndCONTEXT                                        0xCC54D4
#define pinstCTitleWnd                                             0xCC5508
#define pinstCTradeskillWnd                                        0xCC5580
#define pinstCTributeBenefitWnd                                    0xCC5618
#define pinstCTributeMasterWnd                                     0xCC5650
#define pinstCContextMenuManager                                   0x13210D0
#define pinstCVoiceMacroWnd                                        0xC95178
#define pinstCHtmlWnd                                              0xC951F0


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay                                                  0x4D6590
#define __ConvertItemTags                                          0x4C75B0
#define __ExecuteCmd                                               0x4B3320
#define __EQGetTime                                                0x7E5F90
#define __get_melee_range                                          0x4B9440
#define __GetGaugeValueFromEQ                                      0x6D57A0
#define __GetLabelFromEQ                                           0x6D6990
#define __GetXTargetType                                           0x752770
#define __LoadFrontEnd                                             0x5AEAF0
#define __NewUIINI                                                 0x6D5350
#define __ProcessGameEvents                                        0x50E8F0
#define CrashDetected                                              0x5AE8F0
#define DrawNetStatus                                              0x53E390
#define Util__FastTime                                             0x7E5400
#define Expansion_HoT                                              0xC1EE18
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x4861E0
#define AltAdvManager__IsAbilityReady                              0x4862C0
#define AltAdvManager__GetAltAbility                               0x486520

// CharacterZoneClient
#define CharacterZoneClient__HasSkill                              0x43A9A0

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5CC480

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5D64B0

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x520660

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5EEB60
#define CChatManager__InitContextMenu                              0x5EF470

// CChatService
#define CChatService__GetNumberOfFriends                           0x746410
#define CChatService__GetFriendName                                0x746420

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5F4230
#define CChatWindow__Clear                                         0x5F3DF0
#define CChatWindow__WndNotification                               0x5F4640

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x792A80
#define CComboWnd__Draw                                            0x792C50
#define CComboWnd__GetCurChoice                                    0x7928C0
#define CComboWnd__GetListRect                                     0x792F40
#define CComboWnd__GetTextRect                                     0x792AB0
#define CComboWnd__InsertChoice                                    0x792FB0
#define CComboWnd__SetColors                                       0x792850
#define CComboWnd__SetChoice                                       0x792880

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5FDA90
#define CContainerWnd__vftable                                     0x8DE4D8

// CDisplay 
#define CDisplay__CleanGameUI                                      0x479EE0
#define CDisplay__GetClickedActor                                  0x472EE0
#define CDisplay__GetUserDefinedColor                              0x471810
#define CDisplay__GetWorldFilePath                                 0x470CC0
#define CDisplay__is3dON                                           0x46FDD0
#define CDisplay__ReloadUI                                         0x483000
#define CDisplay__WriteTextHD2                                     0x475DE0

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x5C6390
#define CEditBaseWnd__SetSel                                       0x7B5890

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x79C130
#define CEditWnd__GetCharIndexPt                                   0x79D110
#define CEditWnd__GetDisplayString                                 0x79C2E0
#define CEditWnd__GetHorzOffset                                    0x79C570
#define CEditWnd__GetLineForPrintableChar                          0x79CBC0
#define CEditWnd__GetSelStartPt                                    0x79D360
#define CEditWnd__GetSTMLSafeText                                  0x79C710
#define CEditWnd__PointFromPrintableChar                           0x79CCD0
#define CEditWnd__SelectableCharFromPoint                          0x79CE50
#define CEditWnd__SetEditable                                      0x79C6E0

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4EE450
#define CEverQuest__DropHeldItemOnGround                           0x4FB380
#define CEverQuest__dsp_chat                                       0x4F4670
#define CEverQuest__DoTellWindow                                   0x4F2DE0
#define CEverQuest__EnterZone                                      0x506360
#define CEverQuest__GetBodyTypeDesc                                0x4EB230
#define CEverQuest__GetClassDesc                                   0x4EAA70
#define CEverQuest__GetClassThreeLetterCode                        0x4EB070
#define CEverQuest__GetDeityDesc                                   0x4EB8E0
#define CEverQuest__GetLangDesc                                    0x4EB5C0
#define CEverQuest__GetRaceDesc                                    0x4EB8B0
#define CEverQuest__InterpretCmd                                   0x4F5220
#define CEverQuest__LeftClickedOnPlayer                            0x508430
#define CEverQuest__LMouseUp                                       0x50BF90
#define CEverQuest__RightClickedOnPlayer                           0x50D0F0
#define CEverQuest__RMouseUp                                       0x50E0D0
#define CEverQuest__SetGameState                                   0x4EE8E0
#define CEverQuest__Emote                                          0x4F4890

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x60B120
#define CGaugeWnd__CalcLinesFillRect                               0x60B180
#define CGaugeWnd__Draw                                            0x60B5D0

// CGuild
#define CGuild__FindMemberByName                                   0x41BB10

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x6235E0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x62F630
#define CInvSlotMgr__MoveItem                                      0x62FF70

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x62ECC0
#define CInvSlot__SliderComplete                                   0x62D0F0
#define CInvSlot__GetItemBase                                      0x62C7B0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x630CD0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x6D2D50
#define CItemDisplayWnd__UpdateStrings                             0x631D10

// CLabel 
#define CLabel__Draw                                               0x6462A0

// CListWnd 
#define CListWnd__AddColumn                                        0x78AD40
#define CListWnd__AddColumn1                                       0x78A3B0
#define CListWnd__AddLine                                          0x789F60
#define CListWnd__AddString                                        0x78A100
#define CListWnd__CalculateFirstVisibleLine                        0x786270
#define CListWnd__CalculateVSBRange                                0x7885D0
#define CListWnd__ClearAllSel                                      0x7857B0
#define CListWnd__CloseAndUpdateEditWindow                         0x7895C0
#define CListWnd__Compare                                          0x786D30
#define CListWnd__Draw                                             0x788210
#define CListWnd__DrawColumnSeparators                             0x7880A0
#define CListWnd__DrawHeader                                       0x785A40
#define CListWnd__DrawItem                                         0x787720
#define CListWnd__DrawLine                                         0x787D60
#define CListWnd__DrawSeparator                                    0x788140
#define CListWnd__EnsureVisible                                    0x7863D0
#define CListWnd__ExtendSel                                        0x787640
#define CListWnd__GetColumnMinWidth                                0x785480
#define CListWnd__GetColumnWidth                                   0x7853C0
#define CListWnd__GetCurSel                                        0x784C30
#define CListWnd__GetHeaderRect                                    0x784DA0
#define CListWnd__GetItemAtPoint                                   0x7866B0
#define CListWnd__GetItemAtPoint1                                  0x786720
#define CListWnd__GetItemData                                      0x784FC0
#define CListWnd__GetItemHeight                                    0x785ED0
#define CListWnd__GetItemIcon                                      0x7851A0
#define CListWnd__GetItemRect                                      0x7864A0
#define CListWnd__GetItemText                                      0x785050
#define CListWnd__GetSelList                                       0x78A290
#define CListWnd__GetSeparatorRect                                 0x786C80
#define CListWnd__RemoveLine                                       0x78ACF0
#define CListWnd__SetColors                                        0x784D00
#define CListWnd__SetColumnJustification                           0x785620
#define CListWnd__SetColumnWidth                                   0x785440
#define CListWnd__SetCurSel                                        0x784C70
#define CListWnd__SetItemColor                                     0x789270
#define CListWnd__SetItemData                                      0x785850
#define CListWnd__SetItemText                                      0x7890B0
#define CListWnd__ShiftColumnSeparator                             0x788F20
#define CListWnd__Sort                                             0x78B480
#define CListWnd__ToggleSel                                        0x785720

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x65C470

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x670AE0
#define CMerchantWnd__RequestBuyItem                               0x676DB0
#define CMerchantWnd__RequestSellItem                              0x6981D0
#define CMerchantWnd__SelectBuySellSlot                            0x670D70

// CObfuscator
#define CObfuscator__doit                                          0x71DDE0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x7A4B00
#define CSidlManager__CreateLabel                                  0x6CB580

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5C8610
#define CSidlScreenWnd__CalculateVSBRange                          0x5C8530
#define CSidlScreenWnd__ConvertToRes                               0x7B5770
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x7950B0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x796280
#define CSidlScreenWnd__CSidlScreenWnd2                            0x796330
#define CSidlScreenWnd__dCSidlScreenWnd                            0x795A20
#define CSidlScreenWnd__DrawSidlPiece                              0x794B80
#define CSidlScreenWnd__EnableIniStorage                           0x794330
#define CSidlScreenWnd__GetSidlPiece                               0x794D90
#define CSidlScreenWnd__Init1                                      0x7960D0
#define CSidlScreenWnd__LoadIniInfo                                0x795170
#define CSidlScreenWnd__LoadIniListWnd                             0x794480
#define CSidlScreenWnd__LoadSidlScreen                             0x795C80
#define CSidlScreenWnd__StoreIniInfo                               0x793F30
#define CSidlScreenWnd__StoreIniVis                                0x7942C0
#define CSidlScreenWnd__WndNotification                            0x795EC0
#define CSidlScreenWnd__GetChildItem                               0x794390

// CSkillMgr
#define CSkillMgr__IsAvailable                                     0x57AA90
#define CSkillMgr__GetSkillCap                                     0x57AB00

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x7BD910
#define CSliderWnd__SetValue                                       0x7BDA10
#define CSliderWnd__SetNumTicks                                    0x7BDFC0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x6D0AD0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x7B2DA0
#define CStmlWnd__CalculateHSBRange                                0x7AA3E0
#define CStmlWnd__CalculateVSBRange                                0x7AA470
#define CStmlWnd__CanBreakAtCharacter                              0x7AA5E0
#define CStmlWnd__FastForwardToEndOfTag                            0x7AB2C0
#define CStmlWnd__ForceParseNow                                    0x7B32D0
#define CStmlWnd__GetNextTagPiece                                  0x7AB1E0
#define CStmlWnd__GetSTMLText                                      0x5F3680
#define CStmlWnd__GetThisChar                                      0x7DDCF0
#define CStmlWnd__GetVisiableText                                  0x7AC720
#define CStmlWnd__InitializeWindowVariables                        0x7AED10
#define CStmlWnd__MakeStmlColorTag                                 0x7A9300
#define CStmlWnd__MakeWndNotificationTag                           0x7A93A0
#define CStmlWnd__SetSTMLText                                      0x7AEE30
#define CStmlWnd__StripFirstSTMLLines                              0x7B2A40
#define CStmlWnd__UpdateHistoryString                              0x7ACFC0

// CTabWnd 
#define CTabWnd__Draw                                              0x7B6E00
#define CTabWnd__DrawCurrentPage                                   0x7B6680
#define CTabWnd__DrawTab                                           0x7B6450
#define CTabWnd__GetCurrentPage                                    0x7B6A40
#define CTabWnd__GetPageClientRect                                 0x7B6100
#define CTabWnd__GetPageFromTabIndex                               0x7B6380
#define CTabWnd__GetPageInnerRect                                  0x7B6160
#define CTabWnd__GetTabInnerRect                                   0x7B6300
#define CTabWnd__GetTabRect                                        0x7B61F0
#define CTabWnd__InsertPage                                        0x7B7090
#define CTabWnd__SetPage                                           0x7B6A80
#define CTabWnd__SetPageRect                                       0x7B6D30
#define CTabWnd__UpdatePage                                        0x7B7010

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x417F70

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x7966B0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x7B7CA0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x783A40

// CXRect 
#define CXRect__CenterPoint                                        0x51F750

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x52AD80
#define CXStr__CXStr1                                              0x6F9BF0
#define CXStr__CXStr3                                              0x7E2310
#define CXStr__dCXStr                                              0x6D3AD0
#define CXStr__operator_equal                                      0x7E2480
#define CXStr__operator_equal1                                     0x7E24D0
#define CXStr__operator_plus_equal1                                0x7E3560

// CXWnd 
#define CXWnd__BringToTop                                          0x78BA80
#define CXWnd__Center                                              0x791430
#define CXWnd__ClrFocus                                            0x78B8A0
#define CXWnd__DoAllDrawing                                        0x7912B0
#define CXWnd__DrawChildren                                        0x7913F0
#define CXWnd__DrawColoredRect                                     0x78BD90
#define CXWnd__DrawTooltip                                         0x78BF80
#define CXWnd__DrawTooltipAtPoint                                  0x790530
#define CXWnd__GetBorderFrame                                      0x78C380
#define CXWnd__GetChildWndAt                                       0x78F6F0
#define CXWnd__GetClientClipRect                                   0x78C120
#define CXWnd__GetScreenClipRect                                   0x790A80
#define CXWnd__GetScreenRect                                       0x78C4B0
#define CXWnd__GetTooltipRect                                      0x78BEA0
#define CXWnd__GetWindowTextA                                      0x51F7F0
#define CXWnd__IsActive                                            0x7977F0
#define CXWnd__IsDescendantOf                                      0x78C250
#define CXWnd__IsReallyVisible                                     0x78F6D0
#define CXWnd__IsType                                              0x7BAD70
#define CXWnd__Move                                                0x78EE00
#define CXWnd__Move1                                               0x790F70
#define CXWnd__ProcessTransition                                   0x78BA30
#define CXWnd__Refade                                              0x78B9B0
#define CXWnd__Resize                                              0x78C580
#define CXWnd__Right                                               0x790990
#define CXWnd__SetFocus                                            0x78E010
#define CXWnd__SetKeyTooltip                                       0x78C7D0
#define CXWnd__SetMouseOver                                        0x790D60
#define CXWnd__StartFade                                           0x78BAC0
#define CXWnd__GetChildItem                                        0x790CD0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x798D60
#define CXWndManager__DrawWindows                                  0x7989E0
#define CXWndManager__GetKeyboardFlags                             0x797440
#define CXWndManager__HandleKeyboardMsg                            0x797AC0
#define CXWndManager__RemoveWnd                                    0x797910

// CDBStr
#define CDBStr__GetString                                          0x46E610

// EQ_Character 
#define EQ_Character__CastRay                                      0x733AB0
#define EQ_Character__CastSpell                                    0x4315A0
#define EQ_Character__Cur_HP                                       0x43A640
#define EQ_Character__GetAACastingTimeModifier                     0x426220
#define EQ_Character__GetCharInfo2                                 0x7327C0
#define EQ_Character__GetFocusCastingTimeModifier                  0x421790
#define EQ_Character__GetFocusRangeModifier                        0x421960
#define EQ_Character__Max_Endurance                                0x5488D0
#define EQ_Character__Max_HP                                       0x4353F0
#define EQ_Character__Max_Mana                                     0x5486D0
#define EQ_Character__doCombatAbility                              0x547550
#define EQ_Character__UseSkill                                     0x449B70
#define EQ_Character__GetConLevel                                  0x540BD0
#define EQ_Character__IsExpansionFlag                              0x40D910
#define EQ_Character__TotalEffect                                  0x42AA00

// EQ_Item 
#define EQ_Item__CanDrop                                           0x524CA0
#define EQ_Item__CreateItemTagString                               0x71BF90
#define EQ_Item__IsStackable                                       0x711200

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x4877E0
#define EQ_LoadingS__Array                                         0x989938

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x54C190
#define EQ_PC__GetAltAbilityIndex                                  0x723CB0
#define EQ_PC__GetCombatAbility                                    0x723D40
#define EQ_PC__GetCombatAbilityTimer                               0x723DF0
#define EQ_PC__GetItemTimerValue                                   0x547310
#define EQ_PC__HasLoreItem                                         0x545E40

// EQItemList 
#define EQItemList__EQItemList                                     0x4B76E0
#define EQItemList__add_item                                       0x4B7670
#define EQItemList__delete_item                                    0x4B7A90
#define EQItemList__FreeItemList                                   0x4B79C0

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x46DBB0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x551230
#define EQPlayer__dEQPlayer                                        0x555E20
#define EQPlayer__DoAttack                                         0x5671A0
#define EQPlayer__EQPlayer                                         0x55B880
#define EQPlayer__SetNameSpriteState                               0x553760
#define EQPlayer__SetNameSpriteTint                                0x5512A0
#define EQPlayer__IsBodyType_j                                     0x733350
#define EQPlayer__IsTargetable                                     0x733620

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x55CBE0
#define EQPlayerManager__GetSpawnByName                            0x55CE70

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x52A6F0
#define KeypressHandler__AttachKeyToEqCommand                      0x52A730
#define KeypressHandler__ClearCommandStateArray                    0x52A500
#define KeypressHandler__HandleKeyDown                             0x528EC0
#define KeypressHandler__HandleKeyUp                               0x5291D0
#define KeypressHandler__SaveKeymapping                            0x52A5D0

// MapViewMap 
#define MapViewMap__Clear                                          0x657AA0
#define MapViewMap__SaveEx                                         0x658470

#define PlayerPointManager__GetAltCurrency                         0x71E4E0

// StringTable 
#define StringTable__getString                                     0x71E060

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit                              0x54AA60