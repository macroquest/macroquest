/*
 * MacroQuest2: The extension platform for EverQuest
 * Copyright (C) 2002-2019 MacroQuest Authors
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2, as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#pragma once

#define __ClientName                                              "eqgame"
#define __ExpectedVersionDate                                     "Jul 12 2019"
#define __ExpectedVersionTime                                     "11:58:54"
#define __ActualVersionDate_x                                      0xAE24A4
#define __ActualVersionTime_x                                      0xAE2498
#define __ActualVersionBuild_x                                     0xAE2F3C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x61ACC0
#define __MemChecker1_x                                            0x8F17A0
#define __MemChecker2_x                                            0x6AA320
#define __MemChecker3_x                                            0x6AA270
#define __MemChecker4_x                                            0x8484F0
#define __EncryptPad0_x                                            0xC18998
#define __EncryptPad1_x                                            0xC769C0
#define __EncryptPad2_x                                            0xC29210
#define __EncryptPad3_x                                            0xC28E10
#define __EncryptPad4_x                                            0xC67188
#define __EncryptPad5_x                                            0xF3FB70
#define __AC1_x                                                    0x804EA6
#define __AC2_x                                                    0x5D45DF
#define __AC3_x                                                    0x5DBCEF
#define __AC4_x                                                    0x5DFBD0
#define __AC5_x                                                    0x5E5F20
#define __AC6_x                                                    0x5EA4E6
#define __AC7_x                                                    0x5D4050
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1EEB4C

// Direct Input
#define DI8__Main_x                                                0xF3FB90
#define DI8__Keyboard_x                                            0xF3FB94
#define DI8__Mouse_x                                               0xF3F150
#define DI8__Mouse_Copy_x                                          0xE9A82C
#define DI8__Mouse_Check_x                                         0xF3FEC4
#define __AutoSkillArray_x                                         0xE9B744
#define __Attack_x                                                 0xF3955B
#define __Autofire_x                                               0xF3955C
#define __BindList_x                                               0xC073F0
#define g_eqCommandStates_x                                        0xC08168
#define __Clicks_x                                                 0xE9A8E4
#define __CommandList_x                                            0xC08D28
#define __CurrentMapLabel_x                                        0x105A604
#define __CurrentSocial_x                                          0xBF1730
#define __DoAbilityList_x                                          0xED107C
#define __do_loot_x                                                0x5A0520
#define __DrawHandler_x                                            0x16D6FD8
#define __GroupCount_x                                             0xE8D1CA
#define __Guilds_x                                                 0xE91038
#define __gWorld_x                                                 0xE8D1B4
#define __HWnd_x                                                   0xF3F154
#define __heqmain_x                                                0x104A1AC
#define __InChatMode_x                                             0xE9A814
#define __LastTell_x                                               0xE9C778
#define __LMouseHeldTime_x                                         0xE9A950
#define __Mouse_x                                                  0xF3FB7C
#define __MouseLook_x                                              0xE9A8AA
#define __MouseEventTime_x                                         0xF3A03C
#define __gpbCommandEvent_x                                        0xE8ABC8
#define __NetStatusToggle_x                                        0xE9A8AD
#define __PCNames_x                                                0xE9BD28
#define __RangeAttackReady_x                                       0xE9BA28
#define __RMouseHeldTime_x                                         0xE9A94C
#define __RunWalkState_x                                           0xE9A818
#define __ScreenMode_x                                             0xDD8A3C
#define __ScreenX_x                                                0xE9A7CC
#define __ScreenY_x                                                0xE9A7C8
#define __ScreenXMax_x                                             0xE9A7D0
#define __ScreenYMax_x                                             0xE9A7D4
#define __ServerHost_x                                             0xE8ADFB
#define __ServerName_x                                             0xED103C
#define __ShiftKeyDown_x                                           0xE9AEA4
#define __ShowNames_x                                              0xE9BBE4
#define __Socials_x                                                0xED113C
#define __SubscriptionType_x                                       0x109C198
#define __TargetAggroHolder_x                                      0x105CFB8
#define __ZoneType_x                                               0xE9ACA8
#define __GroupAggro_x                                             0x105CFF8
#define __LoginName_x                                              0xF3F814
#define __Inviter_x                                                0xF394D8
#define __AttackOnAssist_x                                         0xE9BBA0
#define __UseTellWindows_x                                         0xE9BEC4
#define __gfMaxZoomCameraDistance_x                                0xAD7930
#define __gfMaxCameraDistance_x                                    0xB04E28
#define __pulAutoRun_x                                             0xE9A8C8
#define __pulForward_x                                             0xE9BEFC
#define __pulBackward_x                                            0xE9BF00
#define __pulTurnRight_x                                           0xE9BF04
#define __pulTurnLeft_x                                            0xE9BF08
#define __pulStrafeLeft_x                                          0xE9BF0C
#define __pulStrafeRight_x                                         0xE9BF10

////
//Section 1: Vital Offsets
////
#define instCRaid_x                                                0xE8D3D0
#define instEQZoneInfo_x                                           0xE9AAA0
#define pinstActiveBanker_x                                        0xE8AC60
#define pinstActiveCorpse_x                                        0xE8AC58
#define pinstActiveGMaster_x                                       0xE8AC5C
#define pinstActiveMerchant_x                                      0xE8AC54
#define pinstAltAdvManager_x                                       0xDD96A0
#define pinstBandageTarget_x                                       0xE8AC70
#define pinstCamActor_x                                            0xDD8A30
#define pinstCDBStr_x                                              0xDD83CC
#define pinstCDisplay_x                                            0xE8D3BC
#define pinstCEverQuest_x                                          0x104919C
#define pinstEverQuestInfo_x                                       0xE9A7C0
#define pinstCharData_x                                            0xE8D11C
#define pinstCharSpawn_x                                           0xE8ACA8
#define pinstControlledMissile_x                                   0xE8B10C
#define pinstControlledPlayer_x                                    0xE8ACA8
#define pinstCResolutionHandler_x                                  0x16D7208
#define pinstCSidlManager_x                                        0x16D61A4
#define pinstCXWndManager_x                                        0x16D6198
#define instDynamicZone_x                                          0xE90F10
#define pinstDZMember_x                                            0xE91020
#define pinstDZTimerInfo_x                                         0xE91024
#define pinstEqLogin_x                                             0xF3F160
#define instEQMisc_x                                               0xDD8310
#define pinstEQSoundManager_x                                      0xDDA5C8
#define pinstEQSpellStrings_x                                      0xC9B5B0
#define instExpeditionLeader_x                                     0xE90F5A
#define instExpeditionName_x                                       0xE90F9A
#define pinstGroup_x                                               0xE8D1C6
#define pinstImeManager_x                                          0x16D619C
#define pinstLocalPlayer_x                                         0xE8AC50
#define pinstMercenaryData_x                                       0xF3BB2C
#define pinstMercenaryStats_x                                      0x105D104
#define pinstModelPlayer_x                                         0xE8AC68
#define pinstPCData_x                                              0xE8D11C
#define pinstSkillMgr_x                                            0xF3DCA0
#define pinstSpawnManager_x                                        0xF3C748
#define pinstSpellManager_x                                        0xF3DEC0
#define pinstSpellSets_x                                           0xF32184
#define pinstStringTable_x                                         0xE8D3C8
#define pinstSwitchManager_x                                       0xE8A970
#define pinstTarget_x                                              0xE8ACA4
#define pinstTargetObject_x                                        0xE8ACF0
#define pinstTargetSwitch_x                                        0xE8D118
#define pinstTaskMember_x                                          0xDD81A0
#define pinstTrackTarget_x                                         0xE8ACAC
#define pinstTradeTarget_x                                         0xE8AC64
#define instTributeActive_x                                        0xDD8331
#define pinstViewActor_x                                           0xDD8A2C
#define pinstWorldData_x                                           0xE8D3B8
#define pinstZoneAddr_x                                            0xE9AD40
#define pinstPlayerPath_x                                          0xF3C7E0
#define pinstTargetIndicator_x                                     0xF3E128
#define EQObject_Top_x                                             0xE8ABCC

////
//Section 2:  UI Related Offsets
////
#define pinstCAAWnd_x                                              0xDD8534
#define pinstCAchievementsWnd_x                                    0xDD8518
#define pinstCActionsWnd_x                                         0xDD859C
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDD8A7C
#define pinstCAdvancedLootWnd_x                                    0xDD8590
#define pinstCAdventureLeaderboardWnd_x                            0x1053DD8
#define pinstCAdventureRequestWnd_x                                0x1053E88
#define pinstCAdventureStatsWnd_x                                  0x1053F38
#define pinstCAggroMeterWnd_x                                      0xDD8ACC
#define pinstCAlarmWnd_x                                           0xDD849C
#define pinstCAlertHistoryWnd_x                                    0xDD84C4
#define pinstCAlertStackWnd_x                                      0xDD8AC8
#define pinstCAlertWnd_x                                           0xDD8ADC
#define pinstCAltStorageWnd_x                                      0x1054298
#define pinstCAudioTriggersWindow_x                                0xC8D8E0
#define pinstCAuraWnd_x                                            0xDD8AC0
#define pinstCAvaZoneWnd_x                                         0xDD84C8
#define pinstCBandolierWnd_x                                       0xDD8AF4
#define pinstCBankWnd_x                                            0xDD84E4
#define pinstCBarterMerchantWnd_x                                  0x10554D8
#define pinstCBarterSearchWnd_x                                    0x1055588
#define pinstCBarterWnd_x                                          0x1055638
#define pinstCBazaarConfirmationWnd_x                              0xDD8AC4
#define pinstCBazaarSearchWnd_x                                    0xDD8A4C
#define pinstCBazaarWnd_x                                          0xDD8474
#define pinstCBlockedBuffWnd_x                                     0xDD84CC
#define pinstCBlockedPetBuffWnd_x                                  0xDD84F0
#define pinstCBodyTintWnd_x                                        0xDD8A9C
#define pinstCBookWnd_x                                            0xDD8478
#define pinstCBreathWnd_x                                          0xDD8544
#define pinstCBuffWindowNORMAL_x                                   0xDD84A0
#define pinstCBuffWindowSHORT_x                                    0xDD84A4
#define pinstCBugReportWnd_x                                       0xDD8538
#define pinstCButtonWnd_x                                          0x16D6408
#define pinstCCastingWnd_x                                         0xDD852C
#define pinstCCastSpellWnd_x                                       0xDD8A68
//#define pinstCCharacterCreationWnd_x                             0xDAAE5C
#define pinstCCharacterListWnd_x                                   0xDD8548
#define pinstCChatWindowManager_x                                  0x10560F8
#define pinstCClaimWnd_x                                           0x1056250
#define pinstCColorPickerWnd_x                                     0xDD8574
#define pinstCCombatAbilityWnd_x                                   0xDD8AD0
#define pinstCCombatSkillsSelectWnd_x                              0xDD8594
#define pinstCCompassWnd_x                                         0xDD8A8C
#define pinstCConfirmationDialog_x                                 0x105B150
#define pinstCContainerMgr_x                                       0xDD8530
#define pinstCContextMenuManager_x                                 0x16D6158
#define pinstCCursorAttachment_x                                   0xDD8520
#define pinstCDynamicZoneWnd_x                                     0x1056818
#define pinstCEditLabelWnd_x                                       0xDD8488
#define pinstCEQMainWnd_x                                          0x1056A60
#define pinstCEventCalendarWnd_x                                   0xDD8550
#define pinstCExtendedTargetWnd_x                                  0xDD8AA8
#define pinstCFacePick_x                                           0xDD856C
#define pinstCFactionWnd_x                                         0xDD8528
#define pinstCFellowshipWnd_x                                      0x1056C60
#define pinstCFileSelectionWnd_x                                   0xDD8580
#define pinstCFindItemWnd_x                                        0xDD8490
#define pinstCFindLocationWnd_x                                    0x1056DB8
#define pinstCFriendsWnd_x                                         0xDD8A24
#define pinstCGemsGameWnd_x                                        0xDD8470
#define pinstCGiveWnd_x                                            0xDD8494
#define pinstCGroupSearchFiltersWnd_x                              0xDD8AE4
#define pinstCGroupSearchWnd_x                                     0x10571B0
#define pinstCGroupWnd_x                                           0x1057260
#define pinstCGuildBankWnd_x                                       0xE9BB84
#define pinstCGuildCreationWnd_x                                   0x10573C0
#define pinstCGuildMgmtWnd_x                                       0x1057470
#define pinstCharacterCreation_x                                   0xDD8AD4
#define pinstCHelpWnd_x                                            0xDD8A84
#define pinstCHeritageSelectionWnd_x                               0xDD857C
#define pinstCHotButtonWnd_x                                       0x10595C8
#define pinstCHotButtonWnd1_x                                      0x10595C8
#define pinstCHotButtonWnd2_x                                      0x10595CC
#define pinstCHotButtonWnd3_x                                      0x10595D0
#define pinstCHotButtonWnd4_x                                      0x10595D4
#define pinstCIconSelectionWnd_x                                   0xDD8504
#define pinstCInspectWnd_x                                         0xDD8510
#define pinstCInventoryWnd_x                                       0xDD8CF8
#define pinstCInvSlotMgr_x                                         0xDD84E8
#define pinstCItemDisplayManager_x                                 0x1059B58
#define pinstCItemExpTransferWnd_x                                 0x1059C8C
#define pinstCItemFuseWnd_x                                        0xDD8500
#define pinstCItemOverflowWnd_x                                    0xDD8A54
#define pinstCJournalCatWnd_x                                      0xDD8614
//#define pinstCJournalNPCWnd_x                                    0xDAB354
#define pinstCJournalTextWnd_x                                     0xDD8564
#define pinstCKeyRingWnd_x                                         0xDD84BC
#define pinstCLargeDialogWnd_x                                     0x105BDD0
#define pinstCLayoutCopyWnd_x                                      0x1059FD8
#define pinstCLFGuildWnd_x                                         0x105A088
#define pinstCLoadskinWnd_x                                        0xDD847C
#define pinstCLootFiltersCopyWnd_x                                 0xCA9BA8
#define pinstCLootFiltersWnd_x                                     0xDD8CFC
#define pinstCLootSettingsWnd_x                                    0xDD8484
#define pinstCLootWnd_x                                            0xDD855C
#define pinstCMailAddressBookWnd_x                                 0xDD84F4
#define pinstCMailCompositionWnd_x                                 0xDD84DC
#define pinstCMailIgnoreListWnd_x                                  0xDD84F8
#define pinstCMailWnd_x                                            0xDD84A8
#define pinstCManageLootWnd_x                                      0xDD9B50
#define pinstCMapToolbarWnd_x                                      0xDD8468
#define pinstCMapViewWnd_x                                         0xDD8AEC
#define pinstCMarketplaceWnd_x                                     0xDD8554
#define pinstCMerchantWnd_x                                        0xDD85AC
#define pinstCMIZoneSelectWnd_x                                    0x105A8C0
#define pinstCMusicPlayerWnd_x                                     0xDD84B0
#define pinstCNameChangeMercWnd_x                                  0xDD8A80
#define pinstCNameChangePetWnd_x                                   0xDD8A70
#define pinstCNameChangeWnd_x                                      0xDD8540
#define pinstCNoteWnd_x                                            0xDD8A78
#define pinstCObjectPreviewWnd_x                                   0xDD8578
#define pinstCOptionsWnd_x                                         0xDD846C
#define pinstCPetInfoWnd_x                                         0xDD84D4
#define pinstCPetitionQWnd_x                                       0xDD8A28
//#define pinstCPlayerCustomizationWnd_x                           0xDAADC4
#define pinstCPlayerNotesWnd_x                                     0xDD8A98
#define pinstCPlayerWnd_x                                          0xDD8480
#define pinstCPopupWndManager_x                                    0x105B150
#define pinstCProgressionSelectionWnd_x                            0x105B200
#define pinstCPurchaseGroupWnd_x                                   0xDD8A1C
#define pinstCPurchaseWnd_x                                        0xDD8584
#define pinstCPvPLeaderboardWnd_x                                  0x105B2B0
#define pinstCPvPStatsWnd_x                                        0x105B360
#define pinstCQuantityWnd_x                                        0xDD850C
#define pinstCRaceChangeWnd_x                                      0xDD8560
#define pinstCRaidOptionsWnd_x                                     0xDD8AE8
#define pinstCRaidWnd_x                                            0xDD8514
#define pinstCRealEstateItemsWnd_x                                 0xDD851C
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDD854C
#define pinstCRealEstateManageWnd_x                                0xDD848C
#define pinstCRealEstateNeighborhoodWnd_x                          0xDD84B4
#define pinstCRealEstatePlotSearchWnd_x                            0xDD84D8
#define pinstCRealEstatePurchaseWnd_x                              0xDD84FC
#define pinstCRespawnWnd_x                                         0xDD8AE0
//#define pinstCRewardSelectionWnd_x                               0x1022600
#define pinstCSelectorWnd_x                                        0xDD8ABC
#define pinstCSendMoneyWnd_x                                       0xDD84AC
#define pinstCServerListWnd_x                                      0xDD84C0
#define pinstCSkillsSelectWnd_x                                    0xDD8570
#define pinstCSkillsWnd_x                                          0xDD8558
#define pinstCSocialEditWnd_x                                      0xDD8524
#define pinstCSocialWnd_x                                          0xDD8AA0
#define pinstCSpellBookWnd_x                                       0xDD8AA4
#define pinstCStoryWnd_x                                           0xDD8A88
#define pinstCTargetOfTargetWnd_x                                  0x105D188
#define pinstCTargetWnd_x                                          0xDD84D0
#define pinstCTaskOverlayWnd_x                                     0xDD84E0
#define pinstCTaskSelectWnd_x                                      0x105D2E0
#define pinstCTaskManager_x                                        0xCAA4F8
#define pinstCTaskTemplateSelectWnd_x                              0x105D390
#define pinstCTaskWnd_x                                            0x105D440
#define pinstCTextEntryWnd_x                                       0xDD8A90
#define pinstCTimeLeftWnd_x                                        0xDD8588
#define pinstCTipWndCONTEXT_x                                      0x105D644
#define pinstCTipWndOFDAY_x                                        0x105D640
#define pinstCTitleWnd_x                                           0x105D6F0
#define pinstCTrackingWnd_x                                        0xDD84EC
#define pinstCTradeskillWnd_x                                      0x105D858
#define pinstCTradeWnd_x                                           0xDD8A94
#define pinstCTrainWnd_x                                           0xDD8508
#define pinstCTributeBenefitWnd_x                                  0x105DA58
#define pinstCTributeMasterWnd_x                                   0x105DB08
#define pinstCTributeTrophyWnd_x                                   0x105DBB8
#define pinstCVideoModesWnd_x                                      0xDD8AAC
#define pinstCVoiceMacroWnd_x                                      0xF3E890
#define pinstCVoteResultsWnd_x                                     0xDD8A20
#define pinstCVoteWnd_x                                            0xDD858C
#define pinstCWebManager_x                                         0xF3EF0C
#define pinstCZoneGuideWnd_x                                       0xDD8498
#define pinstCZonePathWnd_x                                        0xDD84B8

#define pinstEQSuiteTextureLoader_x                                0xC784B0
#define pinstItemIconCache_x                                       0x1056A18
#define pinstLootFiltersManager_x                                  0xCA9C58
#define pinstRewardSelectionWnd_x                                  0x105BAA8

////
// Section 3: Miscellaneous Offsets
////
#define __AppCrashWrapper_x                                        0xC28E00
#define __CastRay_x                                                0x59B980
#define __CastRay2_x                                               0x59B9D0
#define __ConvertItemTags_x                                        0x5B7510
#define __CleanItemTags_x                                          0x477BC0
#define __CrashHandler_x                                           0x851E70
#define __DoesFileExist_x                                          0x8F4820
#define __EQGetTime_x                                              0x8F1280
#define __ExecuteCmd_x                                             0x5942A0
#define __FixHeading_x                                             0x98B5C0
#define __GameLoop_x                                               0x6A97E0
#define __get_bearing_x                                            0x59B4D0
#define __get_melee_range_x                                        0x59BBC0
#define __GetAnimationCache_x                                      0x70E890
#define __GetGaugeValueFromEQ_x                                    0x803340
#define __GetLabelFromEQ_x                                         0x804E30
#define __GetXTargetType_x                                         0x98D090
#define __HandleMouseWheel_x                                       0x6AA3D0
#define __HeadingDiff_x                                            0x98B630
#define __HelpPath_x                                               0xF39C2C
#define __LoadFrontEnd_x                                           0x6A62B0
#define __NewUIINI_x                                               0x803010
#define __pCrashHandler_x                                          0x107AFC0
#define __ProcessGameEvents_x                                      0x5FBD40
#define __ProcessMouseEvent_x                                      0x5FB500
#define __SaveColors_x                                             0x545420
#define __STMLToText_x                                             0x92E840
#define __ToggleKeyRingItem_x                                      0x5086A0
#define CMemoryMappedFile__SetFile_x                               0xA65AA0
#define CrashDetected_x                                            0x6A7D10
#define DrawNetStatus_x                                            0x628120
#define Expansion_HoT_x                                            0xE9BB8C
#define Teleport_Table_Size_x                                      0xE8ACB4
#define Teleport_Table_x                                           0xE8B110
#define Util__FastTime_x                                           0x8F0E40
#define wwsCrashReportCheckForUploader_x                           0x852950
#define wwsCrashReportPlatformLaunchUploader_x                     0x855030
#define __eq_delete_x                                              0x993BAE
#define __eq_new_x                                                 0x994164

////
// Section 4: Function Offsets
////
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48BA60
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x494990
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x494760
#define CAdvancedLootWnd__AddPlayerToList_x                        0x48F000
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x48E450

// AltAdvManager
#define AltAdvManager__GetCalculatedTimer_x                        0x54D090
#define AltAdvManager__IsAbilityReady_x                            0x54BFE0
#define AltAdvManager__GetAAById_x                                 0x54C1E0
#define AltAdvManager__CanTrainAbility_x                           0x54C250
#define AltAdvManager__CanSeeAbility_x                             0x54C5B0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C77B0
#define CharacterZoneClient__HasSkill_x                            0x4D2680
#define CharacterZoneClient__MakeMeVisible_x                       0x4D3DA0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BBDA0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B84F0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D6750
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D6830
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D6910
#define CharacterZoneClient__FindAffectSlot_x                      0x4C0870
#define CharacterZoneClient__BardCastBard_x                        0x4C3340
#define CharacterZoneClient__GetMaxEffects_x                       0x4B85C0
#define CharacterZoneClient__GetEffect_x                           0x4B8430
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C18A0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C1970
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C19C0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C1B10
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C1CF0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B0220
#define CharacterZoneClient__FindItemByGuid_x                      0x4D4D10
#define CharacterZoneClient__FindItemByRecord_x                    0x4D4780

// CBankWnd
#define CBankWnd__GetNumBankSlots_x                                0x6D0110
#define CBankWnd__WndNotification_x                                0x6CFEF0

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6DD8E0

// CButtonWnd
#define CButtonWnd__SetCheck_x                                     0x60A850 // unused
#define CButtonWnd__CButtonWnd_x                                   0x92AC30
#define CButtonWnd__dCButtonWnd_x                                  0x92AF10
#define CButtonWnd__vftable_x                                      0xB1E284

// CChatWindowManager
#define CChatWindowManager__GetRGBAFromIndex_x                     0x6FD9F0
#define CChatWindowManager__InitContextMenu_x                      0x6F6C70
#define CChatWindowManager__FreeChatWindow_x                       0x6FC510
#define CChatWindowManager__GetLockedActiveChatWindow_x            0x4E5E00
#define CChatWindowManager__SetLockedActiveChatWindow_x            0x6FD670
#define CChatWindowManager__CreateChatWindow_x                     0x6FCB50

// ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E5F10

// CChatWindow
#define CChatWindow__CChatWindow_x                                 0x6FE260
#define CChatWindow__Clear_x                                       0x6FF510
#define CChatWindow__WndNotification_x                             0x6FFCA0 // don't need
#define CChatWindow__AddHistory_x                                  0x6FEDE0

// CContextMenu
#define CContextMenu__CContextMenu_x                               0x93F310
#define CContextMenu__dCContextMenu_x                              0x93F540
#define CContextMenu__AddMenuItem_x                                0x93F550
#define CContextMenu__RemoveMenuItem_x                             0x93F860
#define CContextMenu__RemoveAllMenuItems_x                         0x93F880
#define CContextMenu__CheckMenuItem_x                              0x93F900
#define CContextMenu__SetMenuItem_x                                0x93F780
#define CContextMenu__AddSeparator_x                               0x93F6E0

// CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x93FEA0
#define CContextMenuManager__RemoveMenu_x                          0x93FF10
#define CContextMenuManager__PopupMenu_x                           0x93FFD0
#define CContextMenuManager__Flush_x                               0x93FE40
#define CContextMenuManager__GetMenu_x                             0x496B50
#define CContextMenuManager__CreateDefaultMenu_x                   0x709090

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D1850
#define CChatService__GetFriendName_x                              0x8D1860

// CComboWnd
#define CComboWnd__DeleteAll_x                                     0x93C790
#define CComboWnd__Draw_x                                          0x93BC80
#define CComboWnd__GetCurChoice_x                                  0x93C5D0
#define CComboWnd__GetListRect_x                                   0x93C130
#define CComboWnd__GetTextRect_x                                   0x93C800
#define CComboWnd__InsertChoice_x                                  0x93C2C0
#define CComboWnd__SetColors_x                                     0x93C290
#define CComboWnd__SetChoice_x                                     0x93C5A0
#define CComboWnd__GetItemCount_x                                  0x93C5E0
#define CComboWnd__GetCurChoiceText_x                              0x93C620
#define CComboWnd__GetChoiceText_x                                 0x93C5F0
#define CComboWnd__InsertChoiceAtIndex_x                           0x93C360

// CContainerWnd
#define CContainerWnd__HandleCombine_x                             0x706A80
#define CContainerWnd__vftable_x                                   0xAEB738
#define CContainerWnd__SetContainer_x                              0x707FF0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x53FE80
#define CDisplay__PreZoneMainUI_x                                  0x53FE90
#define CDisplay__CleanGameUI_x                                    0x5451E0
#define CDisplay__GetClickedActor_x                                0x5381A0
#define CDisplay__GetUserDefinedColor_x                            0x530880
#define CDisplay__GetWorldFilePath_x                               0x539BF0
#define CDisplay__is3dON_x                                         0x534E70
#define CDisplay__ReloadUI_x                                       0x53F310
#define CDisplay__WriteTextHD2_x                                   0x534C50
#define CDisplay__TrueDistance_x                                   0x53B850
#define CDisplay__SetViewActor_x                                   0x537AF0
#define CDisplay__GetFloorHeight_x                                 0x534F30
#define CDisplay__SetRenderWindow_x                                0x533860
#define CDisplay__ToggleScreenshotMode_x                           0x5375C0

// CEditBaseWnd
#define CEditBaseWnd__SetSel_x                                     0x95F020

// CEditWnd
#define CEditWnd__DrawCaret_x                                      0x942880
#define CEditWnd__GetCharIndexPt_x                                 0x943770
#define CEditWnd__GetDisplayString_x                               0x943610
#define CEditWnd__GetHorzOffset_x                                  0x941EC0
#define CEditWnd__GetLineForPrintableChar_x                        0x9448F0
#define CEditWnd__GetSelStartPt_x                                  0x943A20
#define CEditWnd__GetSTMLSafeText_x                                0x943430
#define CEditWnd__PointFromPrintableChar_x                         0x944530
#define CEditWnd__SelectableCharFromPoint_x                        0x9446A0
#define CEditWnd__SetEditable_x                                    0x943AE0
#define CEditWnd__SetWindowTextA_x                                 0x9431B0

// CEverQuest
#define CEverQuest__DoPercentConvert_x                             0x5E9A10
#define CEverQuest__ClickedPlayer_x                                0x5DBAD0
#define CEverQuest__CreateTargetIndicator_x                        0x5F8FF0
#define CEverQuest__DeleteTargetIndicator_x                        0x5F9080
#define CEverQuest__DoTellWindow_x                                 0x4E5FF0
#define CEverQuest__OutputTextToLog_x                              0x4E6220
#define CEverQuest__DropHeldItemOnGround_x                         0x5D0B10
#define CEverQuest__dsp_chat_x                                     0x4E65B0
#define CEverQuest__trimName_x                                     0x5F52D0
#define CEverQuest__Emote_x                                        0x5EA220
#define CEverQuest__EnterZone_x                                    0x5E4200
#define CEverQuest__GetBodyTypeDesc_x                              0x5EEB60
#define CEverQuest__GetClassDesc_x                                 0x5EF1A0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5EF7A0
#define CEverQuest__GetDeityDesc_x                                 0x5F7940
#define CEverQuest__GetLangDesc_x                                  0x5EF960
#define CEverQuest__GetRaceDesc_x                                  0x5EF180
#define CEverQuest__InterpretCmd_x                                 0x5F7F10
#define CEverQuest__LeftClickedOnPlayer_x                          0x5D4D00
#define CEverQuest__LMouseUp_x                                     0x5D3080
#define CEverQuest__RightClickedOnPlayer_x                         0x5D55E0
#define CEverQuest__RMouseUp_x                                     0x5D4010
#define CEverQuest__SetGameState_x                                 0x5D08A0
#define CEverQuest__UPCNotificationFlush_x                         0x5F51D0
#define CEverQuest__IssuePetCommand_x                              0x5F0D70
#define CEverQuest__ReportSuccessfulHit_x                          0x5EB620

// CGaugeWnd
// not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7189D0
#define CGaugeWnd__CalcLinesFillRect_x                             0x718A30
#define CGaugeWnd__Draw_x                                          0x718010

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ACED0
#define CGuild__GetGuildName_x                                     0x4ABFB0
#define CGuild__GetGuildIndex_x                                    0x4AC340

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton_x                               0x733DA0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x60AC10

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot_x                                 0x740DD0
#define CInvSlotMgr__MoveItem_x                                    0x73FAE0
#define CInvSlotMgr__SelectSlot_x                                  0x740EA0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x73E390
#define CInvSlot__SliderComplete_x                                 0x73C0F0
#define CInvSlot__GetItemBase_x                                    0x73BA60
#define CInvSlot__UpdateItem_x                                     0x73BBD0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x742900
#define CInvSlotWnd__CInvSlotWnd_x                                 0x741AB0
#define CInvSlotWnd__HandleLButtonUp_x                             0x742480

// CItemDisplayWnd
#define CItemDisplayWnd__SetSpell_x                                0x7FF570
#define CItemDisplayWnd__UpdateStrings_x                           0x750F70
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x74ACF0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x74B220
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x751580
#define CItemDisplayWnd__AboutToShow_x                             0x750BD0
#define CItemDisplayWnd__WndNotification_x                         0x752670
#define CItemDisplayWnd__RequestConvertItem_x                      0x752130
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x74FC30
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x7509F0

// CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x837240

// CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x756840

// CLabel
#define CLabel__Draw_x                                             0x75C370 // CLabel::UpdateText

// CListWnd
#define CListWnd__CListWnd_x                                       0x915040
#define CListWnd__dCListWnd_x                                      0x915360
#define CListWnd__vftable_x                                        0xB1DBE8
#define CListWnd__AddColumn_x                                      0x919660
#define CListWnd__AddColumn1_x                                     0x9196B0
#define CListWnd__AddLine_x                                        0x919A40
#define CListWnd__AddString_x                                      0x919840
#define CListWnd__CalculateFirstVisibleLine_x                      0x919430
#define CListWnd__CalculateVSBRange_x                              0x919210
#define CListWnd__ClearSel_x                                       0x91A220
#define CListWnd__ClearAllSel_x                                    0x91A280
#define CListWnd__CloseAndUpdateEditWindow_x                       0x91AC80
#define CListWnd__Compare_x                                        0x918B50
#define CListWnd__Draw_x                                           0x915460
#define CListWnd__DrawColumnSeparators_x                           0x917C20
#define CListWnd__DrawHeader_x                                     0x918090
#define CListWnd__DrawItem_x                                       0x918490
#define CListWnd__DrawLine_x                                       0x917D90
#define CListWnd__DrawSeparator_x                                  0x917CC0
#define CListWnd__EnableLine_x                                     0x917510
#define CListWnd__EnsureVisible_x                                  0x91ABB0
#define CListWnd__ExtendSel_x                                      0x91A150
#define CListWnd__GetColumnTooltip_x                               0x917050
#define CListWnd__GetColumnMinWidth_x                              0x9170C0
#define CListWnd__GetColumnWidth_x                                 0x916FC0
#define CListWnd__GetCurSel_x                                      0x916950
#define CListWnd__GetItemAtPoint_x                                 0x917780
#define CListWnd__GetItemAtPoint1_x                                0x9177F0
#define CListWnd__GetItemData_x                                    0x9169D0
#define CListWnd__GetItemHeight_x                                  0x916D90
#define CListWnd__GetItemIcon_x                                    0x916B60
#define CListWnd__GetItemRect_x                                    0x917600
#define CListWnd__GetItemText_x                                    0x916A10
#define CListWnd__GetSelList_x                                     0x91A2D0
#define CListWnd__GetSeparatorRect_x                               0x917A30
#define CListWnd__InsertLine_x                                     0x919E30
#define CListWnd__RemoveLine_x                                     0x919F80
#define CListWnd__SetColors_x                                      0x9191E0
#define CListWnd__SetColumnJustification_x                         0x918F10
#define CListWnd__SetColumnWidth_x                                 0x918E30
#define CListWnd__SetCurSel_x                                      0x91A090
#define CListWnd__SetItemColor_x                                   0x91A870
#define CListWnd__SetItemData_x                                    0x91A830
#define CListWnd__SetItemText_x                                    0x91A440
#define CListWnd__ShiftColumnSeparator_x                           0x918FD0
#define CListWnd__Sort_x                                           0x918CD0
#define CListWnd__ToggleSel_x                                      0x91A0C0
#define CListWnd__SetColumnsSizable_x                              0x919070
#define CListWnd__SetItemWnd_x                                     0x91A6F0
#define CListWnd__GetItemWnd_x                                     0x916BB0
#define CListWnd__SetItemIcon_x                                    0x91A4C0
#define CListWnd__CalculateCustomWindowPositions_x                 0x919520
#define CListWnd__SetVScrollPos_x                                  0x918E10

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd_x                                 0x771CD0
#define CMapViewWnd__GetWorldCoordinates_x                         0x7703E0
#define CMapViewWnd__HandleLButtonDown_x                           0x76D440 //MapViewMap

// MapViewMap
#define MapViewMap__Clear_x                                        0x76DB60
#define MapViewMap__SaveEx_x                                       0x770F00
#define MapViewMap__SetZoom_x                                      0x7755D0

// CMerchantWnd
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x794CF0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7955D0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x795B00
#define CMerchantWnd__SelectRecoverySlot_x                         0x798A90
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x793830
#define CMerchantWnd__SelectBuySellSlot_x                          0x79E670
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x794900

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89F380
#define CPacketScrambler__hton_x                                   0x89F370

// CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x9381E0
#define CSidlManagerBase__CreatePageWnd_x                          0x9379E0
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x933C20
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x933BB0
#define CSidlManagerBase__FindAnimation1_x                         0x933E00
#define CSidlManagerBase__FindScreenPieceTemplate_x                0x934210
#define CSidlManagerBase__FindScreenPieceTemplate1_x               0x934000
#define CSidlManagerBase__CreateLabel_x                            0x7F68C0
#define CSidlManagerBase__CreateXWndFromTemplate_x                 0x9371B0
#define CSidlManagerBase__CreateXWndFromTemplate1_x                0x937390
#define CSidlManagerBase__CreateXWnd_x                             0x7F67F0

// CSidlManager
#define CSidlManager__CreateHotButtonWnd_x                         0x7F6DC0

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateHSBRange_x                        0x930990
#define CSidlScreenWnd__CalculateVSBRange_x                        0x930890
#define CSidlScreenWnd__ConvertToRes_x                             0x956040
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x930320
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x930010
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x9300E0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x9301B0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x930E20
#define CSidlScreenWnd__EnableIniStorage_x                         0x9312F0
#define CSidlScreenWnd__GetChildItem_x                             0x931270
#define CSidlScreenWnd__GetSidlPiece_x                             0x931010
#define CSidlScreenWnd__HandleLButtonUp_x                          0x920B80
#define CSidlScreenWnd__Init1_x                                    0x92FC10
#define CSidlScreenWnd__LoadIniInfo_x                              0x931340
#define CSidlScreenWnd__LoadIniListWnd_x                           0x931E70
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92F020
#define CSidlScreenWnd__m_layoutCopy_x                             0x16D6028
#define CSidlScreenWnd__StoreIniInfo_x                             0x9319F0
#define CSidlScreenWnd__StoreIniVis_x                              0x931D50
#define CSidlScreenWnd__vftable_x                                  0xB1E520
#define CSidlScreenWnd__WndNotification_x                          0x930D30

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x66FA20
#define CSkillMgr__GetSkillCap_x                                   0x66FC00
#define CSkillMgr__GetNameToken_x                                  0x66F1B0
#define CSkillMgr__IsActivatedSkill_x                              0x66F2F0
#define CSkillMgr__IsCombatSkill_x                                 0x66F230

// CSliderWnd
#define CSliderWnd__GetValue_x                                     0x940C90
#define CSliderWnd__SetValue_x                                     0x940B00
#define CSliderWnd__SetNumTicks_x                                  0x940B60

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet_x                               0x7FCA40

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x9493F0
#define CStmlWnd__CalculateHSBRange_x                              0x94A4C0
#define CStmlWnd__CalculateVSBRange_x                              0x94A430
#define CStmlWnd__CanBreakAtCharacter_x                            0x94E800
#define CStmlWnd__FastForwardToEndOfTag_x                          0x94F490
#define CStmlWnd__ForceParseNow_x                                  0x949990
#define CStmlWnd__GetNextTagPiece_x                                0x94E760
#define CStmlWnd__GetSTMLText_x                                    0x4F7CB0
#define CStmlWnd__GetVisibleText_x                                 0x9499B0
#define CStmlWnd__InitializeWindowVariables_x                      0x94F2E0
#define CStmlWnd__MakeStmlColorTag_x                               0x948A60
#define CStmlWnd__MakeWndNotificationTag_x                         0x948AD0
#define CStmlWnd__SetSTMLText_x                                    0x947B10
#define CStmlWnd__StripFirstSTMLLines_x                            0x950580
#define CStmlWnd__UpdateHistoryString_x                            0x94F6A0

// CTabWnd
#define CTabWnd__Draw_x                                            0x946CB0
#define CTabWnd__DrawCurrentPage_x                                 0x947390
#define CTabWnd__DrawTab_x                                         0x9470B0
#define CTabWnd__GetCurrentPage_x                                  0x9464B0
#define CTabWnd__GetPageInnerRect_x                                0x9466F0
#define CTabWnd__GetTabInnerRect_x                                 0x946630
#define CTabWnd__GetTabRect_x                                      0x9464E0
#define CTabWnd__InsertPage_x                                      0x946900
#define CTabWnd__SetPage_x                                         0x946770
#define CTabWnd__SetPageRect_x                                     0x946BF0
#define CTabWnd__UpdatePage_x                                      0x946F70
#define CTabWnd__GetPageFromTabIndex_x                             0x946FF0
#define CTabWnd__GetCurrentTabIndex_x                              0x9464A0

// CPageWnd
#define CPageWnd__GetTabText_x                                     0x756C10
#define CPageWnd__SetTabText_x                                     0x945FF0

// CTextOverlay
#define CTextOverlay__DisplayText_x                                0x4A6B00

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91DA10
#define CTextureFont__GetTextExtent_x                              0x91DBD0

// CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6A32F0
#define CHtmlComponentWnd__ValidateUri_x                           0x735790
#define CHtmlWnd__SetClientCallbacks_x                             0x60FCA0
#define CHtmlWnd__AddObserver_x                                    0x60FCC0
#define CHtmlWnd__RemoveObserver_x                                 0x60FD20
#define Window__getProgress_x                                      0x84FAE0
#define Window__getStatus_x                                        0x84FB00
#define Window__getURI_x                                           0x84FB10

// CXMLDataManager
#define CXMLDataManager__GetXMLData_x                              0x95BA50

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead_x                             0x90AD10

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr_x                                             0x4E5CF0
#define CXStr__CXStr1_x                                            0x4F2F10
#define CXStr__CXStr3_x                                            0x8ED3B0
#define CXStr__dCXStr_x                                            0x473160
#define CXStr__operator_equal_x                                    0x8ED5E0
#define CXStr__operator_equal1_x                                   0x8ED620
#define CXStr__operator_plus_equal1_x                              0x8EE0B0
#define CXStr__SetString_x                                         0x8EFFA0
#define CXStr__operator_char_p_x                                   0x8EDAF0
#define CXStr__GetChar_x                                           0x8EF8D0
#define CXStr__Delete_x                                            0x8EF1A0
#define CXStr__GetUnicode_x                                        0x8EF940
#define CXStr__GetLength_x                                         0x477F70
#define CXStr__Mid_x                                               0x477F80
#define CXStr__Insert_x                                            0x8EF9A0
#define CXStr__FindNext_x                                          0x8EF610
#define CXStr__gFreeLists_x                                        0xC768F0
#define CXStr__gCXStrAccess_x                                      0x16D573C

// CTileLayoutWnd
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93EF20

// CXWnd
#define CXWnd__BringToTop_x                                        0x924290
#define CXWnd__Center_x                                            0x923E10
#define CXWnd__ClrFocus_x                                          0x923C40
#define CXWnd__Destroy_x                                           0x923CF0
#define CXWnd__DoAllDrawing_x                                      0x920330
#define CXWnd__DrawChildren_x                                      0x920300
#define CXWnd__DrawColoredRect_x                                   0x920790
#define CXWnd__DrawTooltip_x                                       0x91EE50
#define CXWnd__DrawTooltipAtPoint_x                                0x91EF10
#define CXWnd__GetBorderFrame_x                                    0x9205F0
#define CXWnd__GetChildItem_x                                      0x9244A0
#define CXWnd__GetChildWndAt_x                                     0x924330
#define CXWnd__GetClientClipRect_x                                 0x922550
#define CXWnd__GetScreenClipRect_x                                 0x922620
#define CXWnd__GetScreenRect_x                                     0x9227E0
#define CXWnd__GetTooltipRect_x                                    0x9207E0
#define CXWnd__GetWindowTextA_x                                    0x4982B0
#define CXWnd__IsActive_x                                          0x920F00
#define CXWnd__IsDescendantOf_x                                    0x9231E0
#define CXWnd__IsReallyVisible_x                                   0x923210
#define CXWnd__IsType_x                                            0x9249A0
#define CXWnd__Minimize_x                                          0x9238E0
#define CXWnd__Move_x                                              0x923270
#define CXWnd__Move1_x                                             0x923320
#define CXWnd__ProcessTransition_x                                 0x923DC0
#define CXWnd__Refade_x                                            0x9235F0
#define CXWnd__Resize_x                                            0x923870
#define CXWnd__Right_x                                             0x924050
#define CXWnd__SetFocus_x                                          0x923C00
#define CXWnd__SetFont_x                                           0x923C70
#define CXWnd__SetKeyTooltip_x                                     0x9247B0
#define CXWnd__SetMouseOver_x                                      0x921710
#define CXWnd__SetParent_x                                         0x922F80
#define CXWnd__StartFade_x                                         0x9230B0
#define CXWnd__vftable_x                                           0xB1E024
#define CXWnd__CXWnd_x                                             0x91DEF0
#define CXWnd__dCXWnd_x                                            0x91E400

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x9570D0

// CXWndManager
#define CXWndManager__DrawCursor_x                                 0x927210
#define CXWndManager__DrawWindows_x                                0x927230
#define CXWndManager__GetKeyboardFlags_x                           0x929900
#define CXWndManager__HandleKeyboardMsg_x                          0x929500
#define CXWndManager__RemoveWnd_x                                  0x929B40
#define CXWndManager__RemovePendingDeletionWnd_x                   0x92A080

// CDBStr
#define CDBStr__GetString_x                                        0x52F850

// EQ_Character
#define EQ_Character__CastSpell_x                                  0x4B94D0
#define EQ_Character__Cur_HP_x                                     0x4CF660
#define EQ_Character__Cur_Mana_x                                   0x4D6E10
#define EQ_Character__GetCastingTimeModifier_x                     0x4BC3F0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AFE60
#define EQ_Character__GetFocusRangeModifier_x                      0x4AFFB0
#define EQ_Character__GetHPRegen_x                                 0x4DCC20
#define EQ_Character__GetEnduranceRegen_x                          0x4DD230
#define EQ_Character__GetManaRegen_x                               0x4DD670
#define EQ_Character__Max_Endurance_x                              0x6360C0
#define EQ_Character__Max_HP_x                                     0x4CF490
#define EQ_Character__Max_Mana_x                                   0x635EC0
#define EQ_Character__doCombatAbility_x                            0x638580
#define EQ_Character__UseSkill_x                                   0x4DF480
#define EQ_Character__GetConLevel_x                                0x62F070
#define EQ_Character__IsExpansionFlag_x                            0x592A80
#define EQ_Character__TotalEffect_x                                0x4C2A80
#define EQ_Character__GetPCSpellAffect_x                           0x4BCFF0
#define EQ_Character__SpellDuration_x                              0x4BCB20
#define EQ_Character__GetAdjustedSkill_x                           0x4D2440
#define EQ_Character__GetBaseSkill_x                               0x4D33E0
#define EQ_Character__CanUseItem_x                                 0x4D7120

// ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BE590

// PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x64C730

// PcClient
#define PcClient__PcClient_x                                       0x62C7A0

// CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B7110
#define CCharacterListWnd__EnterWorld_x                            0x4B6B50
#define CCharacterListWnd__Quit_x                                  0x4B6860
#define CCharacterListWnd__UpdateList_x                            0x4B6CE0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x610EC0
#define EQ_Item__CreateItemTagString_x                             0x898B90
#define EQ_Item__IsStackable_x                                     0x89D6F0
#define EQ_Item__GetImageNum_x                                     0x89A5D0
#define EQ_Item__CreateItemClient_x                                0x610080
#define EQ_Item__GetItemValue_x                                    0x89B900
#define EQ_Item__ValueSellMerchant_x                               0x89EF20
#define EQ_Item__IsKeyRingItem_x                                   0x89D050
#define EQ_Item__CanGoInBag_x                                      0x610FE0
#define EQ_Item__IsEmpty_x                                         0x89CB50
#define EQ_Item__GetMaxItemCount_x                                 0x89BD30
#define EQ_Item__GetHeldItem_x                                     0x89A4A0
#define EQ_Item__GetAugmentFitBySlot_x                             0x8984E0

// EQ_LoadingS
#define EQ_LoadingS__SetProgressBar_x                              0x54DDC0
#define EQ_LoadingS__Array_x                                       0xC00600

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x636A20
#define EQ_PC__GetAlternateAbilityId_x                             0x8A7F90
#define EQ_PC__GetCombatAbility_x                                  0x8A8600
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A8670
#define EQ_PC__GetItemRecastTimer_x                                0x638B00
#define EQ_PC__HasLoreItem_x                                       0x62F890
#define EQ_PC__AlertInventoryChanged_x                             0x62E9A0
#define EQ_PC__GetPcZoneClient_x                                   0x65B200
#define EQ_PC__RemoveMyAffect_x                                    0x63BD20
#define EQ_PC__GetKeyRingItems_x                                   0x8A8F10
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A8C90
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A9200

// EQItemList
#define EQItemList__EQItemList_x                                   0x598FC0
#define EQItemList__add_object_x                                   0x5C6220
#define EQItemList__add_item_x                                     0x599510
#define EQItemList__delete_item_x                                  0x599560
#define EQItemList__FreeItemList_x                                 0x599460

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x52D370

// EQPlayer
#define EQPlayer__ChangeBoneStringSprite_x                         0x64DFB0
#define EQPlayer__dEQPlayer_x                                      0x641290
#define EQPlayer__DoAttack_x                                       0x655E90
#define EQPlayer__EQPlayer_x                                       0x641950
#define EQPlayer__SetNameSpriteState_x                             0x645C10
#define EQPlayer__SetNameSpriteTint_x                              0x646AE0
#define PlayerBase__HasProperty_j_x                                0x9899A0
#define EQPlayer__IsTargetable_x                                   0x989E40
#define EQPlayer__CanSee_x                                         0x989CA0
#define EQPlayer__CanSee1_x                                        0x989D70
#define PlayerBase__GetVisibilityLineSegment_x                     0x989A60

// PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x658C90
#define PlayerZoneClient__GetLevel_x                               0x65B240
#define PlayerZoneClient__IsValidTeleport_x                        0x5C7390
#define PlayerZoneClient__LegalPlayerRace_x                        0x547090

// EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x650DA0
#define EQPlayerManager__GetSpawnByName_x                          0x650E50
#define EQPlayerManager__GetPlayerFromPartialName_x                0x650EE0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x614730
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x6147B0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x6147F0
#define KeypressHandler__ClearCommandStateArray_x                  0x615C00
#define KeypressHandler__HandleKeyDown_x                           0x615C20
#define KeypressHandler__HandleKeyUp_x                             0x615CC0
#define KeypressHandler__SaveKeymapping_x                          0x6160F0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BC480

// StringTable
#define StringTable__getString_x                                   0x8B7230

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x63B990
#define PcZoneClient__RemovePetEffect_x                            0x63BFC0
#define PcZoneClient__HasAlternateAbility_x                        0x635D00
#define PcZoneClient__GetCurrentMod_x                              0x4E2570
#define PcZoneClient__GetModCap_x                                  0x4E2470
#define PcZoneClient__CanEquipItem_x                               0x6363B0
#define PcZoneClient__GetItemByID_x                                0x638F70
#define PcZoneClient__GetItemByItemClass_x                         0x6390C0
#define PcZoneClient__RemoveBuffEffect_x                           0x63BFE0
#define PcZoneClient__BandolierSwap_x                              0x636FE0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x638AA0

// Doors
#define EQSwitch__UseSwitch_x                                      0x5CBFF0

// IconCache
#define IconCache__GetIcon_x                                       0x70E120

// CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x705C20
#define CContainerMgr__CloseContainer_x                            0x705EF0
#define CContainerMgr__OpenExperimentContainer_x                   0x706970

// CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7C8E10

// CHelpWnd
#define CHelpWnd__SetFile_x                                        0x609020

// CLootWnd
#define CLootWnd__LootAll_x                                        0x763F10
#define CLootWnd__RequestLootSlot_x                                0x763110

// EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x566340
#define EQ_Spell__SpellAffects_x                                   0x5667B0
#define EQ_Spell__SpellAffectBase_x                                0x566570
#define EQ_Spell__IsStackable_x                                    0x4C7110
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C6FC0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B4450
#define EQ_Spell__IsSPAStacking_x                                  0x5675E0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x566B00
#define EQ_Spell__IsNoRemove_x                                     0x4C70F0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x5675F0
#define __IsResEffectSpell_x                                       0x4C6430

// EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AAC30

// EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C6C20

// CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x80EE20
#define CTargetWnd__WndNotification_x                              0x80E6B0
#define CTargetWnd__RefreshTargetBuffs_x                           0x80E980
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x80D800

// CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x8133F0

// CTaskManager
#define CTaskManager__GetEntry_x                                   0x52AE80
#define CTaskManager__HandleMessage_x                              0x529570

// EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5618D0
#define EqSoundManager__PlayScriptMp3_x                            0x561A30
#define EqSoundManager__SoundAssistPlay_x                          0x6739D0
#define EqSoundManager__WaveInstancePlay_x                         0x672F40

// CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x51EFF0

// CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x9454F0

// CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x5557B0
#define CAltAbilityData__GetMercMaxRank_x                          0x555750
#define CAltAbilityData__GetMaxRank_x                              0x54AE80

// CTargetRing
#define CTargetRing__Cast_x                                        0x607120

// CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C6FA0
#define CharacterBase__CreateItemGlobalIndex_x                     0x504A80
#define CharacterBase__CreateItemIndex_x                           0x60F260
#define CharacterBase__GetItemPossession_x                         0x4F0A10
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CF2D0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CF330

// CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6ED030
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6ED860
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6ED910

// messages
#define msg_spell_worn_off_x                                       0x58AC10
#define msg_new_text_x                                             0x57FA30
#define __msgTokenTextParam_x                                      0x58D140
#define msgTokenText_x                                             0x58D390

// SpellManager
#define SpellManager__vftable_x                                    0xAC5CC0
#define SpellManager__SpellManager_x                               0x676D00
#define Spellmanager__LoadTextSpells_x                             0x677600
#define SpellManager__GetSpellByGroupAndRank_x                     0x676ED0

// CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98D980

// ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C75C0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C7840

// CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x75C6C0

// CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x70A340
#define CCursorAttachment__AttachToCursor1_x                       0x70A380
#define CCursorAttachment__Deactivate_x                            0x70B350

// CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9551C0
#define CEQSuiteTextureLoader__GetTexture_x                        0x954E80

// CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x501FF0
#define CFindItemWnd__WndNotification_x                            0x502AD0
#define CFindItemWnd__Update_x                                     0x503640
#define CFindItemWnd__PickupSelectedItem_x                         0x501850

// IString
#define IString__Append_x                                          0x4F2040

// Camera
#define CDisplay__cameraType_x                                     0xDD8AF0
#define EverQuest__Cameras_x                                       0xE9BED0

// LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x50A990
#define LootFiltersManager__GetItemFilterData_x                    0x50A290
#define LootFiltersManager__RemoveItemLootFilter_x                 0x50A2C0
#define LootFiltersManager__SetItemLootFilter_x                    0x50A4E0

// COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B6DC0

// CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x993610
#define CResolutionHandler__GetWindowedStyle_x                     0x66E450

// CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x7029D0

// CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D9F10
#define CDistillerInfo__Instance_x                                 0x8D9EB0

// CGroupWnd
#define CGroupWnd__WndNotification_x                               0x722B40
#define CGroupWnd__UpdateDisplay_x                                 0x721EA0

// ItemBase
#define ItemBase__IsLore_x                                         0x89D0B0
#define ItemBase__IsLoreEquipped_x                                 0x89D120

// EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5C6180
#define EQPlacedItemManager__GetItemByGuid_x                       0x5C62C0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5C6320

// RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x663D40
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x667710

// CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x4F8340

// FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4E7950
#define FactionManagerClient__HandleFactionMessage_x               0x4E7FC0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4E85F0
#define FactionManagerClient__GetMaxFaction_x                      0x4E8640
#define FactionManagerClient__GetMinFaction_x                      0x4E85C0

// BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4F09E0

// ArrayClass
#define ArrayClass__DeleteElement_x                                0x91C930

// AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x4975D0

// ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4F0C90

// MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x554C80

// CTargetManager
#define CTargetManager__Get_x                                      0x67A5C0

// RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x663D40

// CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A68C0

// EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x599400

// EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF39560
