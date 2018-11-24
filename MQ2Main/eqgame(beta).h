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
#if defined(EQBETA)
#include "eqgame-private(beta).h"
#endif
#endif

#define __ClientName                                              "eqgame"
#define __ExpectedVersionDate                                     "Nov 24 2018"
#define __ExpectedVersionTime                                     "04:22:28"
#define __ActualVersionDate_x                                      0xACD01C
#define __ActualVersionTime_x                                      0xACD010

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x6136A0
#define __MemChecker1_x                                            0x8E79E0
#define __MemChecker2_x                                            0x6A2880
#define __MemChecker3_x                                            0x6A27D0
#define __MemChecker4_x                                            0x83EE60
#define __EncryptPad0_x                                            0xC01340
#define __EncryptPad1_x                                            0xC5F5D0
#define __EncryptPad2_x                                            0xC11EC8
#define __EncryptPad3_x                                            0xC11AC8
#define __EncryptPad4_x                                            0xC4FE40
#define __EncryptPad5_x                                            0x1030770
#define __AC1_x                                                    0x7FBBE6
#define __AC2_x                                                    0x5CE6BF
#define __AC3_x                                                    0x5D554F
#define __AC4_x                                                    0x5D9370
#define __AC5_x                                                    0x5DF52F
#define __AC6_x                                                    0x5E3A56
#define __AC7_x                                                    0x5CE130
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1E8AEE4

// Direct Input
#define DI8__Main_x                                                0x1030794
#define DI8__Keyboard_x                                            0x1030798
#define DI8__Mouse_x                                               0xF26498
#define DI8__Mouse_Copy_x                                          0xE84194
#define DI8__Mouse_Check_x                                         0x1031658
#define __AutoSkillArray_x                                         0xE850AC
#define __Attack_x                                                 0xF22EB3
#define __Autofire_x                                               0xF22EB4
#define __BindList_x                                               0xBEFF20
#define g_eqCommandStates_x                                        0xBF0C90
#define __Clicks_x                                                 0xE8424C
#define __CommandList_x                                            0xBF1848
#define __CurrentMapLabel_x                                        0x1038A5C
#define __CurrentSocial_x                                          0xBDA730
#define __DoAbilityList_x                                          0xEBA9D4
#define __do_loot_x                                                0x59BDF0
#define __DrawHandler_x                                            0x16B5430
#define __GroupCount_x                                             0xE74442
#define __Guilds_x                                                 0xE7A9A0
#define __gWorld_x                                                 0xE76D1C
#define __HWnd_x                                                   0xF2649C
#define __heqmain_x                                                0x1030758
#define __InChatMode_x                                             0xE8417C
#define __LastTell_x                                               0xE860D0
#define __LMouseHeldTime_x                                         0xE842B8
#define __Mouse_x                                                  0x103077C
#define __MouseLook_x                                              0xE84212
#define __MouseEventTime_x                                         0xF23968
#define __gpbCommandEvent_x                                        0xE76760
#define __NetStatusToggle_x                                        0xE84215
#define __PCNames_x                                                0xE8568C
#define __RangeAttackReady_x                                       0xE85390
#define __RMouseHeldTime_x                                         0xE842B4
#define __RunWalkState_x                                           0xE84180
#define __ScreenMode_x                                             0xDC2A68
#define __ScreenX_x                                                0xE84134
#define __ScreenY_x                                                0xE84130
#define __ScreenXMax_x                                             0xE84138
#define __ScreenYMax_x                                             0xE8413C
#define __ServerHost_x                                             0xE769B3
#define __ServerName_x                                             0xEBA994
#define __ShiftKeyDown_x                                           0xE8480C
#define __ShowNames_x                                              0xE8554C
#define __Socials_x                                                0xEBAA94
#define __SubscriptionType_x                                       0x107A5AC
#define __TargetAggroHolder_x                                      0x103B418
#define __ZoneType_x                                               0xE84610
#define __GroupAggro_x                                             0x103B458
#define __LoginName_x                                              0x1030FEC
#define __Inviter_x                                                0xF22E30
#define __AttackOnAssist_x                                         0xE85508
#define __UseTellWindows_x                                         0xE85824
#define __gfMaxZoomCameraDistance_x                                0xAC2538
#define __gfMaxCameraDistance_x                                    0xAEF978
#define __pulAutoRun_x                                             0xE84230
#define __pulForward_x                                             0xE8585C
#define __pulBackward_x                                            0xE85860
#define __pulTurnRight_x                                           0xE85864
#define __pulTurnLeft_x                                            0xE85868
#define __pulStrafeLeft_x                                          0xE8586C
#define __pulStrafeRight_x                                         0xE85870
//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE76D38
#define instEQZoneInfo_x                                           0xE84408
#define instKeypressHandler_x                                      0xF23918
#define pinstActiveBanker_x                                        0xE76858
#define pinstActiveCorpse_x                                        0xE76850
#define pinstActiveGMaster_x                                       0xE76854
#define pinstActiveMerchant_x                                      0xE7684C
#define pinstAggroInfo_x                                           0xC75E08
#define pinstAltAdvManager_x                                       0xDC36D8
#define pinstAuraMgr_x                                             0xC91970
#define pinstBandageTarget_x                                       0xE76868
#define pinstCamActor_x                                            0xDC2A5C
#define pinstCDBStr_x                                              0xDC240C
#define pinstCDisplay_x                                            0xE76D14
#define pinstCEverQuest_x                                          0x10308B0
#define pinstEverQuestInfo_x                                       0xE84128
#define pinstCharData_x                                            0xE76D24
#define pinstCharSpawn_x                                           0xE768A0
#define pinstControlledMissile_x                                   0xE76D20
#define pinstControlledPlayer_x                                    0xE768A0
#define pinstCResolutionHandler_x                                  0x16B5660
#define pinstCSidlManager_x                                        0x16B44F4
#define pinstCXWndManager_x                                        0x16B44E8
#define instDynamicZone_x                                          0xE7A878
#define pinstDZMember_x                                            0xE7A988
#define pinstDZTimerInfo_x                                         0xE7A98C
#define pinstEQItemList_x                                          0xE72F28
#define pinstEQObjectList_x                                        0xE74118
#define instEQMisc_x                                               0xDC2348
#define pinstEQSoundManager_x                                      0xDC3F38
#define pinstEQSpellStrings_x                                      0xC83F40
#define instExpeditionLeader_x                                     0xE7A8C2
#define instExpeditionName_x                                       0xE7A902
#define pinstGroup_x                                               0xE7443E
#define pinstImeManager_x                                          0x16B44EC
#define pinstLocalPlayer_x                                         0xE76848
#define pinstMercenaryData_x                                       0xF24114
#define pinstMercenaryStats_x                                      0x103B564
#define pinstMercAltAbilities_x                                    0xDC3CA8
#define pinstModelPlayer_x                                         0xE76860
#define pinstPCData_x                                              0xE76D24
#define pinstRealEstateItems_x                                     0xF255F8
#define pinstSkillMgr_x                                            0xF256C8
#define pinstSpawnManager_x                                        0xF24CB8
#define pinstSpellManager_x                                        0xF258A0
#define pinstSpellSets_x                                           0xF1BADC
#define pinstStringTable_x                                         0xE76638
#define pinstSwitchManager_x                                       0xE742D8
#define pinstTarget_x                                              0xE7689C
#define pinstTargetObject_x                                        0xE76CC8
#define pinstTargetSwitch_x                                        0xE76D2C
#define pinstTaskMember_x                                          0xDC21DC
#define pinstTrackTarget_x                                         0xE768B0
#define pinstTradeTarget_x                                         0xE7685C
#define instTributeActive_x                                        0xDC236D
#define pinstViewActor_x                                           0xDC2A58
#define pinstWorldData_x                                           0xE76768
#define pinstZoneAddr_x                                            0xE846A8
#define pinstPlayerPath_x                                          0xF24D50
#define pinstTargetIndicator_x                                     0xF25B08
#define pinstCTargetManager_x                                      0xF25BA0
#define EQObject_Top_x                                             0xE76844

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDC2518
#define pinstCAchievementsWnd_x                                    0xDC24CC
#define pinstCActionsWnd_x                                         0xDC29F4
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDC29E4
#define pinstCAdvancedLootWnd_x                                    0xDC2534
#define pinstCAdventureLeaderboardWnd_x                            0x1032230
#define pinstCAdventureRequestWnd_x                                0x10322E0
#define pinstCAdventureStatsWnd_x                                  0x1032390
#define pinstCAggroMeterWnd_x                                      0xDC2A98
#define pinstCAlarmWnd_x                                           0xDC2AB8
#define pinstCAlertHistoryWnd_x                                    0xDC2B1C
#define pinstCAlertStackWnd_x                                      0xDC2A7C
#define pinstCAlertWnd_x                                           0xDC2A8C
#define pinstCAltStorageWnd_x                                      0x10326F0
#define pinstCAudioTriggersWindow_x                                0xC76298
#define pinstCAuraWnd_x                                            0xDC2A94
#define pinstCAvaZoneWnd_x                                         0xDC2D20
#define pinstCBandolierWnd_x                                       0xDC2ADC
#define pinstCBankWnd_x                                            0xDC24C4
#define pinstCBarterMerchantWnd_x                                  0x1033930
#define pinstCBarterSearchWnd_x                                    0x10339E0
#define pinstCBarterWnd_x                                          0x1033A90
#define pinstCBazaarConfirmationWnd_x                              0xDC2A78
#define pinstCBazaarSearchWnd_x                                    0xDC2A30
#define pinstCBazaarWnd_x                                          0xDC2AD4
#define pinstCBlockedBuffWnd_x                                     0xDC24A8
#define pinstCBlockedPetBuffWnd_x                                  0xDC24D0
#define pinstCBodyTintWnd_x                                        0xDC2A3C
#define pinstCBookWnd_x                                            0xDC2B00
#define pinstCBreathWnd_x                                          0xDC2520
#define pinstCBuffWindowNORMAL_x                                   0xDC2D24
#define pinstCBuffWindowSHORT_x                                    0xDC2D28
#define pinstCBugReportWnd_x                                       0xDC2508
#define pinstCButtonWnd_x                                          0x16B4718
#define pinstCCastingWnd_x                                         0xDC2504
#define pinstCCastSpellWnd_x                                       0xDC2A44
//#define pinstCCharacterCreationWnd_x                             0xDAAE5C
#define pinstCCharacterListWnd_x                                   0xDC2524
#define pinstCChatWindowManager_x                                  0x1034550
#define pinstCClaimWnd_x                                           0x10346A8
#define pinstCColorPickerWnd_x                                     0xDC2554
#define pinstCCombatAbilityWnd_x                                   0xDC2AA4
#define pinstCCombatSkillsSelectWnd_x                              0xDC29EC
#define pinstCCompassWnd_x                                         0xDC2A24
#define pinstCConfirmationDialog_x                                 0x10395A8
#define pinstCContainerMgr_x                                       0xDC2AC0
#define pinstCContextMenuManager_x                                 0x16B44A8
#define pinstCCursorAttachment_x                                   0xDC24F8
#define pinstCDistillerInfo_x                                      0x1037FB4
#define pinstCDynamicZoneWnd_x                                     0x1034C70
#define pinstCEditLabelWnd_x                                       0xDC2B0C
#define pinstCEQMainWnd_x                                          0x1034EB8
#define pinstCEventCalendarWnd_x                                   0xDC2514
#define pinstCExtendedTargetWnd_x                                  0xDC2A84
#define pinstCFacePick_x                                           0xDC254C
#define pinstCFellowshipWnd_x                                      0x10350B8
#define pinstCFileSelectionWnd_x                                   0xDC252C
#define pinstCFindItemWnd_x                                        0xDC2AF4
#define pinstCFindLocationWnd_x                                    0x1035210
#define pinstCFriendsWnd_x                                         0xDC2A2C
#define pinstCGemsGameWnd_x                                        0xDC2A90
#define pinstCGiveWnd_x                                            0xDC2AF8
#define pinstCGroupSearchFiltersWnd_x                              0xDC2AB0
#define pinstCGroupSearchWnd_x                                     0x1035608
#define pinstCGroupWnd_x                                           0x10356B8
#define pinstCGuildBankWnd_x                                       0xE854EC
#define pinstCGuildCreationWnd_x                                   0x1035818
#define pinstCGuildMgmtWnd_x                                       0x10358C8
#define pinstCharacterCreation_x                                   0xDC2AA0
#define pinstCHelpWnd_x                                            0xDC2A4C
#define pinstCHeritageSelectionWnd_x                               0xDC25D4
#define pinstCHotButtonWnd_x                                       0x1037A20
#define pinstCHotButtonWnd1_x                                      0x1037A20
#define pinstCHotButtonWnd2_x                                      0x1037A24
#define pinstCHotButtonWnd3_x                                      0x1037A28
#define pinstCHotButtonWnd4_x                                      0x1037A2C
#define pinstCIconSelectionWnd_x                                   0xDC24E0
#define pinstCInspectWnd_x                                         0xDC24D4
#define pinstCInventoryWnd_x                                       0xDC2AE4
#define pinstCInvSlotMgr_x                                         0xDC2A74
#define pinstCItemDisplayManager_x                                 0x1037FB0
#define pinstCItemExpTransferWnd_x                                 0x10380E0
#define pinstCItemOverflowWnd_x                                    0xDC2A34
#define pinstCJournalCatWnd_x                                      0xDC2544
//#define pinstCJournalNPCWnd_x                                    0xDAB354
#define pinstCJournalTextWnd_x                                     0xDC250C
#define pinstCKeyRingWnd_x                                         0xDC2D3C
#define pinstCLargeDialogWnd_x                                     0x103A228
#define pinstCLayoutCopyWnd_x                                      0x1038430
#define pinstCLFGuildWnd_x                                         0x10384E0
#define pinstCLoadskinWnd_x                                        0xDC2A9C
#define pinstCLootFiltersCopyWnd_x                                 0xC922A0
#define pinstCLootFiltersWnd_x                                     0xDC2AA8
#define pinstCLootSettingsWnd_x                                    0xDC2AC8
#define pinstCLootWnd_x                                            0xDC253C
#define pinstCMailAddressBookWnd_x                                 0xDC24D8
#define pinstCMailCompositionWnd_x                                 0xDC24B4
#define pinstCMailIgnoreListWnd_x                                  0xDC24DC
#define pinstCMailWnd_x                                            0xDC2D2C
#define pinstCManageLootWnd_x                                      0xDC3B50
#define pinstCMapToolbarWnd_x                                      0xDC2AE8
#define pinstCMapViewWnd_x                                         0xDC2AC4
#define pinstCMarketplaceWnd_x                                     0xDC251C
#define pinstCMerchantWnd_x                                        0xDC29E8
#define pinstCMIZoneSelectWnd_x                                    0x1038D18
#define pinstCMusicPlayerWnd_x                                     0xDC2D38
#define pinstCNameChangeMercWnd_x                                  0xDC2A40
#define pinstCNameChangePetWnd_x                                   0xDC2A14
#define pinstCNameChangeWnd_x                                      0xDC24FC
#define pinstCNoteWnd_x                                            0xDC2A48
#define pinstCObjectPreviewWnd_x                                   0xDC2540
#define pinstCOptionsWnd_x                                         0xDC2AEC
#define pinstCPetInfoWnd_x                                         0xDC24B8
#define pinstCPetitionQWnd_x                                       0xDC2550
//#define pinstCPlayerCustomizationWnd_x                             0xDAADC4
#define pinstCPlayerNotesWnd_x                                     0xDC2A38
#define pinstCPlayerWnd_x                                          0xDC2A1C
#define pinstCPopupWndManager_x                                    0x10395A8
#define pinstCProgressionSelectionWnd_x                            0x1039658
#define pinstCPurchaseGroupWnd_x                                   0xDC29DC
#define pinstCPurchaseWnd_x                                        0xDC2548
#define pinstCPvPLeaderboardWnd_x                                  0x1039708
#define pinstCPvPStatsWnd_x                                        0x10397B8
#define pinstCQuantityWnd_x                                        0xDC24EC
#define pinstCRaceChangeWnd_x                                      0xDC2528
#define pinstCRaidOptionsWnd_x                                     0xDC2ABC
#define pinstCRaidWnd_x                                            0xDC24F0
#define pinstCRealEstateItemsWnd_x                                 0xDC24E4
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDC2510
#define pinstCRealEstateManageWnd_x                                0xDC2AE0
#define pinstCRealEstateNeighborhoodWnd_x                          0xDC2B04
#define pinstCRealEstatePlotSearchWnd_x                            0xDC2D30
#define pinstCRealEstatePurchaseWnd_x                              0xDC24BC
#define pinstCRespawnWnd_x                                         0xDC2AAC
//#define pinstCRewardSelectionWnd_x                               0x1022600
#define pinstCSelectorWnd_x                                        0xDC2A88
#define pinstCSendMoneyWnd_x                                       0xDC2B10
#define pinstCServerListWnd_x                                      0xDC2B14
#define pinstCSkillsSelectWnd_x                                    0xDC255C
#define pinstCSkillsWnd_x                                          0xDC2538
#define pinstCSocialEditWnd_x                                      0xDC24F4
#define pinstCSocialWnd_x                                          0xDC2A50
#define pinstCSpellBookWnd_x                                       0xDC2A80
#define pinstCStoryWnd_x                                           0xDC29F0
#define pinstCTargetOfTargetWnd_x                                  0x103B5E8
#define pinstCTargetWnd_x                                          0xDC24B0
#define pinstCTaskOverlayWnd_x                                     0xDC2D34
#define pinstCTaskSelectWnd_x                                      0x103B740
#define pinstCTaskManager_x                                        0xC92AA0
#define pinstCTaskTemplateSelectWnd_x                              0x103B7F0
#define pinstCTaskWnd_x                                            0x103B8A0
#define pinstCTextEntryWnd_x                                       0xDC2A28
#define pinstCTextOverlay_x                                        0xC765A8
#define pinstCTimeLeftWnd_x                                        0xDC2530
#define pinstCTipWndCONTEXT_x                                      0x103BAA4
#define pinstCTipWndOFDAY_x                                        0x103BAA0
#define pinstCTitleWnd_x                                           0x103BB50
#define pinstCTrackingWnd_x                                        0xDC24AC
#define pinstCTradeskillWnd_x                                      0x103BCB8
#define pinstCTradeWnd_x                                           0xDC2A54
#define pinstCTrainWnd_x                                           0xDC24E8
#define pinstCTributeBenefitWnd_x                                  0x103BEB8
#define pinstCTributeMasterWnd_x                                   0x103BF68
#define pinstCTributeTrophyWnd_x                                   0x103C018
#define pinstCVideoModesWnd_x                                      0xDC2AB4
#define pinstCVoiceMacroWnd_x                                      0xF260D0
#define pinstCVoteResultsWnd_x                                     0xDC29E0
#define pinstCVoteWnd_x                                            0xDC2558
#define pinstCWebManager_x                                         0xF26234
#define pinstCZoneGuideWnd_x                                       0xDC2AF0
#define pinstCZonePathWnd_x                                        0xDC2B08

#define pinstEQSuiteTextureLoader_x                                0xC610A0
#define pinstItemIconCache_x                                       0x1034E70
#define pinstLootFiltersManager_x                                  0xC92350
#define pinstRewardSelectionWnd_x                                  0x1039F00

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC11ABC
#define __CastRay_x                                                0x597310
#define __CastRay2_x                                               0x597360
#define __ConvertItemTags_x                                        0x5B1F10
#define __CrashHandler_x                                           0x8487D0
#define __EQGetTime_x                                              0x8E74D0
#define __ExecuteCmd_x                                             0x58FC90
#define __FixHeading_x                                             0x977D30
#define __get_bearing_x                                            0x596E60
#define __get_melee_range_x                                        0x597550
#define __GetAnimationCache_x                                      0x705F40
#define __GetGaugeValueFromEQ_x                                    0x7FA400
#define __GetLabelFromEQ_x                                         0x7FBB70
#define __GetXTargetType_x                                         0x979800
#define __HeadingDiff_x                                            0x977DA0
#define __HelpPath_x                                               0xF23584
#define __LoadFrontEnd_x                                           0x69E6E0
#define __NewUIINI_x                                               0x7FA0D0
#define __pCrashHandler_x                                          0x1059408
#define __ProcessGameEvents_x                                      0x5F4C80
#define __ProcessMouseEvent_x                                      0x5F4440
#define __SaveColors_x                                             0x53FD50
#define __STMLToText_x                                             0x91B150
#define __ToggleKeyRingItem_x                                      0x503000
#define CrashDetected_x                                            0x6A01D0
#define DrawNetStatus_x                                            0x620C00
#define Expansion_HoT_x                                            0xE854F4
#define Teleport_Table_Size_x                                      0xE76804
#define Teleport_Table_x                                           0xE74638
#define Util__FastTime_x                                           0x8E7090
#define wwsCrashReportCheckForUploader_x                           0x8495D0
#define wwsCrashReportPlatformLaunchUploader_x                     0x84BCB0
#define __HandleMouseWheel_x                                       0x6A2930

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48B3F0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x494250
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x494010

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x5477F0
#define AltAdvManager__IsAbilityReady_x                            0x546740
#define AltAdvManager__GetAAById_x                                 0x546940
#define AltAdvManager__CanTrainAbility_x                           0x5469B0
#define AltAdvManager__CanSeeAbility_x                             0x546D10

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C71A0
#define CharacterZoneClient__HasSkill_x                            0x4D1E60
#define CharacterZoneClient__MakeMeVisible_x                       0x4D3580
#define CharacterZoneClient__IsStackBlocked_x                      0x4BB660
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B7DD0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D5F40
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D6020
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D6100
#define CharacterZoneClient__FindAffectSlot_x                      0x4C0140
#define CharacterZoneClient__BardCastBard_x                        0x4C2DA0
#define CharacterZoneClient__GetMaxEffects_x                       0x4B7EA0
#define CharacterZoneClient__GetEffect_x                           0x4B7D10
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C1140
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C1210
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C1260
#define CharacterZoneClient__CalcAffectChange_x                    0x4C13B0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C1580

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6C84B0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6D5E70

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x603420
#define CButtonWnd__CButtonWnd_x                                   0x917550

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6F4900
#define CChatManager__InitContextMenu_x                            0x6EE9A0
#define CChatManager__FreeChatWindow_x                             0x6F3810
#define CChatManager__GetLockedActiveChatWindow_x                  0x6F81C0
#define CChatManager__SetLockedActiveChatWindow_x                  0x6F46A0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x92BDD0
#define CContextMenu__dCContextMenu_x                              0x92C000
#define CContextMenu__AddMenuItem_x                                0x92C010
#define CContextMenu__RemoveMenuItem_x                             0x92C320
#define CContextMenu__RemoveAllMenuItems_x                         0x92C340
#define CContextMenu__CheckMenuItem_x                              0x92C3C0
#define CContextMenu__SetMenuItem_x                                0x92C240
#define CContextMenu__AddSeparator_x                               0x92C1A0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x92C960
#define CContextMenuManager__RemoveMenu_x                          0x92C9D0
#define CContextMenuManager__PopupMenu_x                           0x92CA90
#define CContextMenuManager__Flush_x                               0x92C900
#define CContextMenuManager__GetMenu_x                             0x496510

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8C7CB0
#define CChatService__GetFriendName_x                              0x8C7CC0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6F4E70
#define CChatWindow__Clear_x                                       0x6F5ED0
#define CChatWindow__WndNotification_x                             0x6F6440

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x929240
#define CComboWnd__Draw_x                                          0x928730
#define CComboWnd__GetCurChoice_x                                  0x929080
#define CComboWnd__GetListRect_x                                   0x928BE0
#define CComboWnd__GetTextRect_x                                   0x9292B0
#define CComboWnd__InsertChoice_x                                  0x928D70
#define CComboWnd__SetColors_x                                     0x928D40
#define CComboWnd__SetChoice_x                                     0x929050
#define CComboWnd__GetItemCount_x                                  0x929090
#define CComboWnd__GetCurChoiceText_x                              0x9290D0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6FE140
#define CContainerWnd__vftable_x                                   0xAD62C8
#define CContainerWnd__SetContainer_x                              0x6FF6B0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x53FB10
#define CDisplay__GetClickedActor_x                                0x532AD0
#define CDisplay__GetUserDefinedColor_x                            0x52B1B0
#define CDisplay__GetWorldFilePath_x                               0x534520
#define CDisplay__is3dON_x                                         0x52F7A0
#define CDisplay__ReloadUI_x                                       0x539C40
#define CDisplay__WriteTextHD2_x                                   0x52F580
#define CDisplay__TrueDistance_x                                   0x536180
#define CDisplay__SetViewActor_x                                   0x532420
#define CDisplay__GetFloorHeight_x                                 0x52F860
#define CDisplay__SetRenderWindow_x                                0x52E190
#define CDisplay__ToggleScreenshotMode_x                           0x531EF0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x94B4B0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x9304D0
#define CEditWnd__GetCharIndexPt_x                                 0x9313D0
#define CEditWnd__GetDisplayString_x                               0x931270
#define CEditWnd__GetHorzOffset_x                                  0x92FB00
#define CEditWnd__GetLineForPrintableChar_x                        0x932510
#define CEditWnd__GetSelStartPt_x                                  0x931680
#define CEditWnd__GetSTMLSafeText_x                                0x931090
#define CEditWnd__PointFromPrintableChar_x                         0x932140
#define CEditWnd__SelectableCharFromPoint_x                        0x9322B0
#define CEditWnd__SetEditable_x                                    0x931750

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5E2F80
#define CEverQuest__ClickedPlayer_x                                0x5D5330
#define CEverQuest__CreateTargetIndicator_x                        0x5F1F30
#define CEverQuest__DeleteTargetIndicator_x                        0x5F1FC0
#define CEverQuest__DoTellWindow_x                                 0x4E3030
#define CEverQuest__OutputTextToLog_x                              0x4E3260
#define CEverQuest__DropHeldItemOnGround_x                         0x5CABF0
#define CEverQuest__dsp_chat_x                                     0x4E35F0
#define CEverQuest__trimName_x                                     0x5EE4A0
#define CEverQuest__Emote_x                                        0x5E3790
#define CEverQuest__EnterZone_x                                    0x5DD980
#define CEverQuest__GetBodyTypeDesc_x                              0x5E7D40
#define CEverQuest__GetClassDesc_x                                 0x5E8380
#define CEverQuest__GetClassThreeLetterCode_x                      0x5E8980
#define CEverQuest__GetDeityDesc_x                                 0x5F0880
#define CEverQuest__GetLangDesc_x                                  0x5E8B40
#define CEverQuest__GetRaceDesc_x                                  0x5E8360
#define CEverQuest__InterpretCmd_x                                 0x5F0E50
#define CEverQuest__LeftClickedOnPlayer_x                          0x5CEDE0
#define CEverQuest__LMouseUp_x                                     0x5CD160
#define CEverQuest__RightClickedOnPlayer_x                         0x5CF6C0
#define CEverQuest__RMouseUp_x                                     0x5CE0F0
#define CEverQuest__SetGameState_x                                 0x5CA980
#define CEverQuest__UPCNotificationFlush_x                         0x5EE3A0
#define CEverQuest__IssuePetCommand_x                              0x5E9F40
#define CEverQuest__ReportSuccessfulHit_x                          0x5E4B90

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7100E0
#define CGaugeWnd__CalcLinesFillRect_x                             0x710140
#define CGaugeWnd__Draw_x                                          0x70F7D0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AC9F0
#define CGuild__GetGuildName_x                                     0x4ABAD0
#define CGuild__GetGuildIndex_x                                    0x4ABE60

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x72B470

//CHotButton
#define CHotButton__SetButtonSize_x                                0x6037E0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x7383F0
#define CInvSlotMgr__MoveItem_x                                    0x737150
#define CInvSlotMgr__SelectSlot_x                                  0x7384C0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7359F0
#define CInvSlot__SliderComplete_x                                 0x733750
#define CInvSlot__GetItemBase_x                                    0x7330E0
#define CInvSlot__UpdateItem_x                                     0x733250

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x739DF0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7390C0
#define CInvSlotWnd__HandleLButtonUp_x                             0x739970

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7F65F0
#define CItemDisplayWnd__UpdateStrings_x                           0x747FF0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x741F70
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x742490
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x748610
#define CItemDisplayWnd__AboutToShow_x                             0x747C40
#define CItemDisplayWnd__WndNotification_x                         0x749B50

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x82DE00

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x74DCB0

// CLabel 
#define CLabel__Draw_x                                             0x753780

// CListWnd
#define CListWnd__CListWnd_x                                       0x901950
#define CListWnd__dCListWnd_x                                      0x901C70
#define CListWnd__AddColumn_x                                      0x905FB0
#define CListWnd__AddColumn1_x                                     0x906000
#define CListWnd__AddLine_x                                        0x906390
#define CListWnd__AddString_x                                      0x906190
#define CListWnd__CalculateFirstVisibleLine_x                      0x905D70
#define CListWnd__CalculateVSBRange_x                              0x905B40
#define CListWnd__ClearSel_x                                       0x906B70
#define CListWnd__ClearAllSel_x                                    0x906BD0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x9075E0
#define CListWnd__Compare_x                                        0x905480
#define CListWnd__Draw_x                                           0x901D70
#define CListWnd__DrawColumnSeparators_x                           0x904550
#define CListWnd__DrawHeader_x                                     0x9049C0
#define CListWnd__DrawItem_x                                       0x904DC0
#define CListWnd__DrawLine_x                                       0x9046C0
#define CListWnd__DrawSeparator_x                                  0x9045F0
#define CListWnd__EnableLine_x                                     0x903E20
#define CListWnd__EnsureVisible_x                                  0x907500
#define CListWnd__ExtendSel_x                                      0x906AA0
#define CListWnd__GetColumnMinWidth_x                              0x903960
#define CListWnd__GetColumnWidth_x                                 0x9038D0
#define CListWnd__GetCurSel_x                                      0x903260
#define CListWnd__GetItemAtPoint_x                                 0x9040A0
#define CListWnd__GetItemAtPoint1_x                                0x904110
#define CListWnd__GetItemData_x                                    0x9032E0
#define CListWnd__GetItemHeight_x                                  0x9036A0
#define CListWnd__GetItemIcon_x                                    0x903470
#define CListWnd__GetItemRect_x                                    0x903F10
#define CListWnd__GetItemText_x                                    0x903320
#define CListWnd__GetSelList_x                                     0x906C20
#define CListWnd__GetSeparatorRect_x                               0x904350
#define CListWnd__InsertLine_x                                     0x906780
#define CListWnd__RemoveLine_x                                     0x9068D0
#define CListWnd__SetColors_x                                      0x905B10
#define CListWnd__SetColumnJustification_x                         0x905840
#define CListWnd__SetColumnWidth_x                                 0x905760
#define CListWnd__SetCurSel_x                                      0x9069E0
#define CListWnd__SetItemColor_x                                   0x9071B0
#define CListWnd__SetItemData_x                                    0x907170
#define CListWnd__SetItemText_x                                    0x906DA0
#define CListWnd__ShiftColumnSeparator_x                           0x905900
#define CListWnd__Sort_x                                           0x905600
#define CListWnd__ToggleSel_x                                      0x906A10

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x768CA0
#define CMapViewWnd__GetWorldCoordinates_x                         0x7673B0
#define CMapViewWnd__HandleLButtonDown_x                           0x764410

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x78C150
// CMerchantWnd__RequestBuyItem_x                             
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x78CA30
// CMerchantWnd__RequestSellItem_x
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x78CF70
#define CMerchantWnd__SelectRecoverySlot_x                         0x78FDA0
//CMerchantWnd__SelectBuySellSlot_x before
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x78AB30
//CMerchantWnd__ActualSelect_x
#define CMerchantWnd__SelectBuySellSlot_x                          0x7959A0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x78BD80

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x895CF0
#define CPacketScrambler__hton_x                                   0x895CE0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x920720
#define CSidlManager__FindScreenPieceTemplate_x                    0x920B30
#define CSidlManager__FindScreenPieceTemplate1_x                   0x920920
#define CSidlManager__CreateLabel_x                                0x7ED9C0
#define CSidlManager__CreateXWndFromTemplate_x                     0x923C00
#define CSidlManager__CreateXWndFromTemplate1_x                    0x923DE0
#define CSidlManager__CreateXWnd_x                                 0x7ED8F0
#define CSidlManager__CreateHotButtonWnd_x                         0x7EDEB0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x91D2A0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x91D1A0
#define CSidlScreenWnd__ConvertToRes_x                             0x9422E0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x91CC30
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x91C920
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x91C9F0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x91CAC0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x91D740
#define CSidlScreenWnd__EnableIniStorage_x                         0x91DC10
#define CSidlScreenWnd__GetSidlPiece_x                             0x91D930
#define CSidlScreenWnd__Init1_x                                    0x91C530
#define CSidlScreenWnd__LoadIniInfo_x                              0x91DC60
#define CSidlScreenWnd__LoadIniListWnd_x                           0x91E790
#define CSidlScreenWnd__LoadSidlScreen_x                           0x91B930
#define CSidlScreenWnd__StoreIniInfo_x                             0x91E310
#define CSidlScreenWnd__StoreIniVis_x                              0x91E670
#define CSidlScreenWnd__WndNotification_x                          0x91D650
#define CSidlScreenWnd__GetChildItem_x                             0x91DB90
#define CSidlScreenWnd__HandleLButtonUp_x                          0x90D4B0
#define CSidlScreenWnd__m_layoutCopy_x                             0x16B4378

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x667710
#define CSkillMgr__GetSkillCap_x                                   0x6678F0
#define CSkillMgr__GetNameToken_x                                  0x666EA0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x92D750
#define CSliderWnd__SetValue_x                                     0x92D5C0
#define CSliderWnd__SetNumTicks_x                                  0x92D620

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7F3860

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x9343C0
#define CStmlWnd__CalculateHSBRange_x                              0x935450
#define CStmlWnd__CalculateVSBRange_x                              0x9353C0
#define CStmlWnd__CanBreakAtCharacter_x                            0x939790
#define CStmlWnd__FastForwardToEndOfTag_x                          0x93A380
#define CStmlWnd__ForceParseNow_x                                  0x934960
#define CStmlWnd__GetNextTagPiece_x                                0x9396F0
#define CStmlWnd__GetSTMLText_x                                    0x4F4960
#define CStmlWnd__GetVisibleText_x                                 0x934980
#define CStmlWnd__InitializeWindowVariables_x                      0x93A1D0
#define CStmlWnd__MakeStmlColorTag_x                               0x933B50
#define CStmlWnd__MakeWndNotificationTag_x                         0x933BC0
#define CStmlWnd__SetSTMLText_x                                    0x932C20
#define CStmlWnd__StripFirstSTMLLines_x                            0x93B4E0
#define CStmlWnd__UpdateHistoryString_x                            0x93A590

// CTabWnd 
#define CTabWnd__Draw_x                                            0x93F200
#define CTabWnd__DrawCurrentPage_x                                 0x93F820
#define CTabWnd__DrawTab_x                                         0x93F5F0
#define CTabWnd__GetCurrentPage_x                                  0x93EA60
#define CTabWnd__GetPageInnerRect_x                                0x93ECA0
#define CTabWnd__GetTabInnerRect_x                                 0x93EBE0
#define CTabWnd__GetTabRect_x                                      0x93EA90
#define CTabWnd__InsertPage_x                                      0x93EE90
#define CTabWnd__SetPage_x                                         0x93ED20
#define CTabWnd__SetPageRect_x                                     0x93F140
#define CTabWnd__UpdatePage_x                                      0x93F4B0
#define CTabWnd__GetPageFromTabIndex_x                             0x93F530
#define CTabWnd__GetCurrentTabIndex_x                              0x93EA50

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x74E110
#define CPageWnd__SetTabText_x                                     0x94B8C0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A65D0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x90A320
#define CTextureFont__GetTextExtent_x                              0x90A4E0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x69B4F0
#define CHtmlComponentWnd__ValidateUri_x                           0x72CE60
#define CHtmlWnd__SetClientCallbacks_x                             0x608790
#define CHtmlWnd__AddObserver_x                                    0x6087B0
#define CHtmlWnd__RemoveObserver_x                                 0x608810
#define Window__getProgress_x                                      0x846430
#define Window__getStatus_x                                        0x846450
#define Window__getURI_x                                           0x846460

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x947E40

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8F7270

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4ADC90
#define CXStr__CXStr1_x                                            0x8FFD60
#define CXStr__CXStr3_x                                            0x8E35C0
#define CXStr__dCXStr_x                                            0x472EC0
#define CXStr__operator_equal_x                                    0x8E37F0
#define CXStr__operator_equal1_x                                   0x8E3830
#define CXStr__operator_plus_equal1_x                              0x8E42C0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x92B9D0
#define CXWnd__BringToTop_x                                        0x910C00
#define CXWnd__Center_x                                            0x910780
#define CXWnd__ClrFocus_x                                          0x9105C0
#define CXWnd__Destroy_x                                           0x910670
#define CXWnd__DoAllDrawing_x                                      0x90CC40
#define CXWnd__DrawChildren_x                                      0x90CC10
#define CXWnd__DrawColoredRect_x                                   0x90D0A0
#define CXWnd__DrawTooltip_x                                       0x90B780
#define CXWnd__DrawTooltipAtPoint_x                                0x90B840
#define CXWnd__GetBorderFrame_x                                    0x90CF00
#define CXWnd__GetChildWndAt_x                                     0x910CA0
#define CXWnd__GetClientClipRect_x                                 0x90EED0
#define CXWnd__GetScreenClipRect_x                                 0x90EFA0
#define CXWnd__GetScreenRect_x                                     0x90F160
#define CXWnd__GetTooltipRect_x                                    0x90D0F0
#define CXWnd__GetWindowTextA_x                                    0x497C90
#define CXWnd__IsActive_x                                          0x913AF0
#define CXWnd__IsDescendantOf_x                                    0x90FB50
#define CXWnd__IsReallyVisible_x                                   0x90FB80
#define CXWnd__IsType_x                                            0x911310
#define CXWnd__Move_x                                              0x90FBF0
#define CXWnd__Move1_x                                             0x90FCA0
#define CXWnd__ProcessTransition_x                                 0x910730
#define CXWnd__Refade_x                                            0x90FF80
#define CXWnd__Resize_x                                            0x910220
#define CXWnd__Right_x                                             0x9109C0
#define CXWnd__SetFocus_x                                          0x910580
#define CXWnd__SetFont_x                                           0x9105F0
#define CXWnd__SetKeyTooltip_x                                     0x911130
#define CXWnd__SetMouseOver_x                                      0x90E050
#define CXWnd__StartFade_x                                         0x90FA30
#define CXWnd__GetChildItem_x                                      0x910E10
#define CXWnd__SetParent_x                                         0x90F900

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x9433B0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x913B30
#define CXWndManager__DrawWindows_x                                0x913B50
#define CXWndManager__GetKeyboardFlags_x                           0x916210
#define CXWndManager__HandleKeyboardMsg_x                          0x915E10
#define CXWndManager__RemoveWnd_x                                  0x916460
#define CXWndManager__RemovePendingDeletionWnd_x                   0x9169C0

// CDBStr
#define CDBStr__GetString_x                                        0x52A140

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B8D80
#define EQ_Character__Cur_HP_x                                     0x4CEEE0
#define EQ_Character__Cur_Mana_x                                   0x4D6600
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BBCA0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AF850
#define EQ_Character__GetFocusRangeModifier_x                      0x4AF9A0
#define EQ_Character__GetHPRegen_x                                 0x4DC580
#define EQ_Character__GetEnduranceRegen_x                          0x4DCB90
#define EQ_Character__GetManaRegen_x                               0x4DCFD0
#define EQ_Character__Max_Endurance_x                              0x62E330
#define EQ_Character__Max_HP_x                                     0x4CED10
#define EQ_Character__Max_Mana_x                                   0x62E130
#define EQ_Character__doCombatAbility_x                            0x6307F0
#define EQ_Character__UseSkill_x                                   0x4DEDC0
#define EQ_Character__GetConLevel_x                                0x627970
#define EQ_Character__IsExpansionFlag_x                            0x58E440
#define EQ_Character__TotalEffect_x                                0x4C2320
#define EQ_Character__GetPCSpellAffect_x                           0x4BC890
#define EQ_Character__SpellDuration_x                              0x4BC3C0
#define EQ_Character__FindItemByRecord_x                           0x4D44F0
#define EQ_Character__GetAdjustedSkill_x                           0x4D1C20
#define EQ_Character__GetBaseSkill_x                               0x4D2BC0
#define EQ_Character__CanUseItem_x                                 0x4D6910

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8B4CA0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x6445F0

//PcClient
#define PcClient__PcClient_x                                       0x625240

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6A00
#define CCharacterListWnd__EnterWorld_x                            0x4B6440
#define CCharacterListWnd__Quit_x                                  0x4B6150
#define CCharacterListWnd__UpdateList_x                            0x4B65D0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6099B0
#define EQ_Item__CreateItemTagString_x                             0x88F6A0
#define EQ_Item__IsStackable_x                                     0x8940B0
#define EQ_Item__GetImageNum_x                                     0x8910B0
#define EQ_Item__CreateItemClient_x                                0x608B70
#define EQ_Item__GetItemValue_x                                    0x892310
#define EQ_Item__ValueSellMerchant_x                               0x895880
#define EQ_Item__IsKeyRingItem_x                                   0x893A00
#define EQ_Item__CanGoInBag_x                                      0x609AD0
#define EQ_Item__GetMaxItemCount_x                                 0x8926E0
#define EQ_Item__GetHeldItem_x                                     0x890F80
#define EQ_Item__GetAugmentFitBySlot_x                             0x88EFE0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x548520
#define EQ_LoadingS__Array_x                                       0xBE9130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x62EC90
#define EQ_PC__GetAlternateAbilityId_x                             0x89EAA0
#define EQ_PC__GetCombatAbility_x                                  0x89F110
#define EQ_PC__GetCombatAbilityTimer_x                             0x89F180
#define EQ_PC__GetItemRecastTimer_x                                0x630D70
#define EQ_PC__HasLoreItem_x                                       0x628140
#define EQ_PC__AlertInventoryChanged_x                             0x627440
#define EQ_PC__GetPcZoneClient_x                                   0x652DA0
#define EQ_PC__RemoveMyAffect_x                                    0x633F70
#define EQ_PC__GetKeyRingItems_x                                   0x89FA20
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x89F7A0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x89FD10

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5948B0
#define EQItemList__add_object_x                                   0x5C0210
#define EQItemList__add_item_x                                     0x594EC0
#define EQItemList__delete_item_x                                  0x594F10
#define EQItemList__FreeItemList_x                                 0x594E10

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x5277A0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x645E70
#define EQPlayer__dEQPlayer_x                                      0x6395A0
#define EQPlayer__DoAttack_x                                       0x64DAA0
#define EQPlayer__EQPlayer_x                                       0x639C50
#define EQPlayer__SetNameSpriteState_x                             0x63DEB0
#define EQPlayer__SetNameSpriteTint_x                              0x63ED70
#define PlayerBase__HasProperty_j_x                                0x976110
#define EQPlayer__IsTargetable_x                                   0x9765B0
#define EQPlayer__CanSee_x                                         0x976410
#define EQPlayer__CanSee1_x                                        0x9764E0
#define PlayerBase__GetVisibilityLineSegment_x                     0x9761D0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x650870
#define PlayerZoneClient__GetLevel_x                               0x652DE0
#define PlayerZoneClient__IsValidTeleport_x                        0x5C1360
#define PlayerZoneClient__LegalPlayerRace_x                        0x541890

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x648B50
#define EQPlayerManager__GetSpawnByName_x                          0x648B70
#define EQPlayerManager__GetPlayerFromPartialName_x                0x648C00

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x60D250
#define KeypressHandler__AttachKeyToEqCommand_x                    0x60D290
#define KeypressHandler__ClearCommandStateArray_x                  0x60E680
#define KeypressHandler__HandleKeyDown_x                           0x60E6A0
#define KeypressHandler__HandleKeyUp_x                             0x60E740
#define KeypressHandler__SaveKeymapping_x                          0x60EB20

// MapViewMap 
#define MapViewMap__Clear_x                                        0x764B30
#define MapViewMap__SaveEx_x                                       0x767ED0
#define MapViewMap__SetZoom_x                                      0x76C5A0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B2B90

// StringTable 
#define StringTable__getString_x                                   0x8ADCD0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x633BE0
#define PcZoneClient__RemovePetEffect_x                            0x634210
#define PcZoneClient__HasAlternateAbility_x                        0x62DF70
#define PcZoneClient__GetCurrentMod_x                              0x4E1EB0
#define PcZoneClient__GetModCap_x                                  0x4E1DB0
#define PcZoneClient__CanEquipItem_x                               0x62E620
#define PcZoneClient__GetItemByID_x                                0x6311F0
#define PcZoneClient__GetItemByItemClass_x                         0x631340
#define PcZoneClient__RemoveBuffEffect_x                           0x634230
#define PcZoneClient__BandolierSwap_x                              0x62F250

//Doors
#define EQSwitch__UseSwitch_x                                      0x5C5FC0

//IconCache
#define IconCache__GetIcon_x                                       0x7057D0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6FD2E0
#define CContainerMgr__CloseContainer_x                            0x6FD5B0
#define CContainerMgr__OpenExperimentContainer_x                   0x6FE030

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7BFFA0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x601BC0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x75AF20
#define CLootWnd__RequestLootSlot_x                                0x75A2E0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x560BF0
#define EQ_Spell__SpellAffects_x                                   0x561060
#define EQ_Spell__SpellAffectBase_x                                0x560E20
#define EQ_Spell__IsStackable_x                                    0x4C6AC0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C6910
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B3D80
#define EQ_Spell__IsSPAStacking_x                                  0x561E90
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x5613B0
#define EQ_Spell__IsNoRemove_x                                     0x4C6AA0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x561EA0
#define __IsResEffectSpell_x                                       0x4C5E60

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AA720

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8BD160

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x8059A0
#define CTargetWnd__WndNotification_x                              0x805230
#define CTargetWnd__RefreshTargetBuffs_x                           0x805500
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x804380

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x80A070

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x5250F0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x55C190
#define EqSoundManager__PlayScriptMp3_x                            0x55C2F0
#define EqSoundManager__SoundAssistPlay_x                          0x66B5C0
#define EqSoundManager__WaveInstancePlay_x                         0x66AB30

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x519130

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x92F130

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x550230
#define CAltAbilityData__GetMercMaxRank_x                          0x5501D0
#define CAltAbilityData__GetMaxRank_x                              0x5455F0

//CTargetRing
#define CTargetRing__Cast_x                                        0x5FFCD0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C68F0
#define CharacterBase__CreateItemGlobalIndex_x                     0x4FF4C0
#define CharacterBase__CreateItemIndex_x                           0x607DD0
#define CharacterBase__GetItemPossession_x                         0x4B3C30
#define CharacterBase__GetItemByGlobalIndex_x                      0x8C57E0
#define CharacterBase__GetEffectId_x                               0x4C68A0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6E5440
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6E5C60

//messages
#define msg_spell_worn_off_x                                       0x586530
#define msg_new_text_x                                             0x57B430
#define __msgTokenTextParam_x                                      0x588B80
#define msgTokenText_x                                             0x588DD0

//SpellManager
#define SpellManager__vftable_x                                    0xAB0A18
#define SpellManager__SpellManager_x                               0x66E8F0
#define Spellmanager__LoadTextSpells_x                             0x66F1C0
#define SpellManager__GetSpellByGroupAndRank_x                     0x66EAC0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x97A0F0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4FFBA0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x58C990
#define ItemGlobalIndex__IsEquippedLocation_x                      0x620A60
#define ItemGlobalIndex__IsValidIndex_x                            0x4FFC00

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8BDAA0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8BDD20

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x753AD0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x701A30
#define CCursorAttachment__Deactivate_x                            0x702A10

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x941740
#define CEQSuiteTextureLoader__GetTexture_x                        0x941400

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4FCC50

//IString
#define IString__Append_x                                          0x4EEAC0

//Camera
#define CDisplay__cameraType_x                                     0xDC2B18
#define EverQuest__Cameras_x                                       0xE85830

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x505280
#define LootFiltersManager__GetItemFilterData_x                    0x504B70
#define LootFiltersManager__RemoveItemLootFilter_x                 0x504BA0
#define LootFiltersManager__SetItemLootFilter_x                    0x504DC0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7ADFF0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x97FE30
#define CResolutionHandler__GetWindowedStyle_x                     0x6662C0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6FA020

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D01C0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x71A250
#define CGroupWnd__UpdateDisplay_x                                 0x7195B0

//ItemBase
#define ItemBase__IsLore_x                                         0x893A60
#define ItemBase__IsLoreEquipped_x                                 0x893AD0

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
