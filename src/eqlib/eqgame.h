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
#define __ExpectedVersionDate                                     "Sep 13 2019"
#define __ExpectedVersionTime                                     "16:10:25"
#define __ActualVersionDate_x                                      0xAE14A4
#define __ActualVersionTime_x                                      0xAE1498
#define __ActualVersionBuild_x                                     0xAE1F3C

// Memory Protection
#define __MemChecker0_x                                            0x61B280
#define __MemChecker1_x                                            0x8F1AC0
#define __MemChecker2_x                                            0x6AABB0
#define __MemChecker3_x                                            0x6AAB00
#define __MemChecker4_x                                            0x848E70
#define __EncryptPad0_x                                            0xC13A30
#define __EncryptPad1_x                                            0xC71A80
#define __EncryptPad2_x                                            0xC242B0
#define __EncryptPad3_x                                            0xC23EB0
#define __EncryptPad4_x                                            0xC62228
#define __EncryptPad5_x                                            0xF3B308
#define __AC1_x                                                    0x805CB6
#define __AC2_x                                                    0x5D4EAF
#define __AC3_x                                                    0x5DC5AF
#define __AC4_x                                                    0x5E0460
#define __AC5_x                                                    0x5E675F
#define __AC6_x                                                    0x5EAD76
#define __AC7_x                                                    0x5D4920
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1F70E0

// Direct Input
#define DI8__Main_x                                                0xF3A504
#define DI8__Keyboard_x                                            0xF3A508
#define DI8__Mouse_x                                               0x10445B8
#define DI8__Mouse_Copy_x                                          0xE95BD4
#define DI8__Mouse_Check_x                                         0xF3B2CC
#define __AutoSkillArray_x                                         0xE96AEC
#define __Attack_x                                                 0xF34907
#define __Autofire_x                                               0xF34908
#define __BindList_x                                               0xC02488
#define g_eqCommandStates_x                                        0xC03200
#define __Clicks_x                                                 0xE95C8C
#define __CommandList_x                                            0xC03DC0
#define __CurrentMapLabel_x                                        0x10559A4
#define __CurrentSocial_x                                          0xBEC7CC
#define __DoAbilityList_x                                          0xECC428
#define __do_loot_x                                                0x5A1420
#define __DrawHandler_x                                            0x16D2340
#define __GroupCount_x                                             0xE85FB2
#define __Guilds_x                                                 0xE8C3E0
#define __gWorld_x                                                 0xE861A4
#define __HWnd_x                                                   0x10445BC
#define __heqmain_x                                                0x10455CC
#define __InChatMode_x                                             0xE95BBC
#define __LastTell_x                                               0xE97B24
#define __LMouseHeldTime_x                                         0xE95CF8
#define __Mouse_x                                                  0xF3A4F0
#define __MouseLook_x                                              0xE95C52
#define __MouseEventTime_x                                         0xF353EC
#define __gpbCommandEvent_x                                        0xE8621C
#define __NetStatusToggle_x                                        0xE95C55
#define __PCNames_x                                                0xE970D4
#define __RangeAttackReady_x                                       0xE96DD0
#define __RMouseHeldTime_x                                         0xE95CF4
#define __RunWalkState_x                                           0xE95BC0
#define __ScreenMode_x                                             0xDD3858
#define __ScreenX_x                                                0xE95B74
#define __ScreenY_x                                                0xE95B70
#define __ScreenXMax_x                                             0xE95B78
#define __ScreenYMax_x                                             0xE95B7C
#define __ServerHost_x                                             0xE86453
#define __ServerName_x                                             0xECC3E8
#define __ShiftKeyDown_x                                           0xE9624C
#define __ShowNames_x                                              0xE96F8C
#define __Socials_x                                                0xECC4E8
#define __SubscriptionType_x                                       0x1097528
#define __TargetAggroHolder_x                                      0x1058358
#define __ZoneType_x                                               0xE96050
#define __GroupAggro_x                                             0x1058398
#define __LoginName_x                                              0xF3AC5C
#define __Inviter_x                                                0xF34884
#define __AttackOnAssist_x                                         0xE96F48
#define __UseTellWindows_x                                         0xE97270
#define __gfMaxZoomCameraDistance_x                                0xAD68E8
#define __gfMaxCameraDistance_x                                    0xB03F38
#define __pulAutoRun_x                                             0xE95C70
#define __pulForward_x                                             0xE972A8
#define __pulBackward_x                                            0xE972AC
#define __pulTurnRight_x                                           0xE972B0
#define __pulTurnLeft_x                                            0xE972B4
#define __pulStrafeLeft_x                                          0xE972B8
#define __pulStrafeRight_x                                         0xE972BC

////
//Section 1: Vital Offsets
////
#define instCRaid_x                                                0xE88778
#define instEQZoneInfo_x                                           0xE95E48
#define pinstActiveBanker_x                                        0xE862B4
#define pinstActiveCorpse_x                                        0xE862AC
#define pinstActiveGMaster_x                                       0xE862B0
#define pinstActiveMerchant_x                                      0xE862A8
#define pinstAltAdvManager_x                                       0xDD4A58
#define pinstBandageTarget_x                                       0xE862C4
#define pinstCamActor_x                                            0xDD3844
#define pinstCDBStr_x                                              0xDD3784
#define pinstCDisplay_x                                            0xE85F9C
#define pinstCEverQuest_x                                          0xF3A520
#define pinstEverQuestInfo_x                                       0xE95B68
#define pinstCharData_x                                            0xE85F94
#define pinstCharSpawn_x                                           0xE86300
#define pinstControlledMissile_x                                   0xE8655C
#define pinstControlledPlayer_x                                    0xE86300
#define pinstCResolutionHandler_x                                  0x16D2570
#define pinstCSidlManager_x                                        0x16D1508
#define pinstCXWndManager_x                                        0x16D1504
#define instDynamicZone_x                                          0xE8C2B8
#define pinstDZMember_x                                            0xE8C3C8
#define pinstDZTimerInfo_x                                         0xE8C3CC
#define pinstEqLogin_x                                             0xF3A5A8
#define instEQMisc_x                                               0xDD36C8
#define pinstEQSoundManager_x                                      0xDD5980
#define pinstEQSpellStrings_x                                      0xC96458
#define instExpeditionLeader_x                                     0xE8C302
#define instExpeditionName_x                                       0xE8C342
#define pinstGroup_x                                               0xE85FAE
#define pinstImeManager_x                                          0x16D1500
#define pinstLocalPlayer_x                                         0xE862A4
#define pinstMercenaryData_x                                       0xF36EDC
#define pinstMercenaryStats_x                                      0x10584A4
#define pinstModelPlayer_x                                         0xE862BC
#define pinstPCData_x                                              0xE85F94
#define pinstSkillMgr_x                                            0xF39040
#define pinstSpawnManager_x                                        0xF37AE8
#define pinstSpellManager_x                                        0xF39260
#define pinstSpellSets_x                                           0xF2D530
#define pinstStringTable_x                                         0xE861A0
#define pinstSwitchManager_x                                       0xE85D18
#define pinstTarget_x                                              0xE862FC
#define pinstTargetObject_x                                        0xE86348
#define pinstTargetSwitch_x                                        0xE88768
#define pinstTaskMember_x                                          0xDD3558
#define pinstTrackTarget_x                                         0xE86304
#define pinstTradeTarget_x                                         0xE862B8
#define instTributeActive_x                                        0xDD36E9
#define pinstViewActor_x                                           0xDD3840
#define pinstWorldData_x                                           0xE85E68
#define pinstZoneAddr_x                                            0xE960E8
#define pinstPlayerPath_x                                          0xF37B80
#define pinstTargetIndicator_x                                     0xF394C8
#define EQObject_Top_x                                             0xE862A0

////
//Section 2:  UI Related Offsets
////
#define pinstCAAWnd_x                                              0xDD3880
#define pinstCAchievementsWnd_x                                    0xDD3890
#define pinstCActionsWnd_x                                         0xDD382C
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDD3B74
#define pinstCAdvancedLootWnd_x                                    0xDD3B2C
#define pinstCAdventureLeaderboardWnd_x                            0x104F178
#define pinstCAdventureRequestWnd_x                                0x104F228
#define pinstCAdventureStatsWnd_x                                  0x104F2D8
#define pinstCAggroMeterWnd_x                                      0xDD4078
#define pinstCAlarmWnd_x                                           0xDD38EC
#define pinstCAlertHistoryWnd_x                                    0xDD3B9C
#define pinstCAlertStackWnd_x                                      0xDD38F8
#define pinstCAlertWnd_x                                           0xDD3B14
#define pinstCAltStorageWnd_x                                      0x104F638
#define pinstCAudioTriggersWindow_x                                0xC88788
#define pinstCAuraWnd_x                                            0xDD3BCC
#define pinstCAvaZoneWnd_x                                         0xDD3B34
#define pinstCBandolierWnd_x                                       0xDD4070
#define pinstCBankWnd_x                                            0xDD3BC4
#define pinstCBarterMerchantWnd_x                                  0x1050878
#define pinstCBarterSearchWnd_x                                    0x1050928
#define pinstCBarterWnd_x                                          0x10509D8
#define pinstCBazaarConfirmationWnd_x                              0xDD38B0
#define pinstCBazaarSearchWnd_x                                    0xDD40AC
#define pinstCBazaarWnd_x                                          0xDD38D0
#define pinstCBlockedBuffWnd_x                                     0xDD3BD0
#define pinstCBlockedPetBuffWnd_x                                  0xDD3C64
#define pinstCBodyTintWnd_x                                        0xDD383C
#define pinstCBookWnd_x                                            0xDD4094
#define pinstCBreathWnd_x                                          0xDD389C
#define pinstCBuffWindowNORMAL_x                                   0xDD3B90
#define pinstCBuffWindowSHORT_x                                    0xDD3B94
#define pinstCBugReportWnd_x                                       0xDD3BBC
#define pinstCButtonWnd_x                                          0x16D1770
#define pinstCCastingWnd_x                                         0xDD4088
#define pinstCCastSpellWnd_x                                       0xDD3898
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDD38D8
#define pinstCChatWindowManager_x                                  0x1051498
#define pinstCClaimWnd_x                                           0x10515F0
#define pinstCColorPickerWnd_x                                     0xDD3838
#define pinstCCombatAbilityWnd_x                                   0xDD38E8
#define pinstCCombatSkillsSelectWnd_x                              0xDD3B10
#define pinstCCompassWnd_x                                         0xDD3834
#define pinstCConfirmationDialog_x                                 0x10564F0
#define pinstCContainerMgr_x                                       0xDD38D4
#define pinstCContextMenuManager_x                                 0x16D14C0
#define pinstCCursorAttachment_x                                   0xDD407C
#define pinstCDynamicZoneWnd_x                                     0x1051BB8
#define pinstCEditLabelWnd_x                                       0xDD3B84
#define pinstCEQMainWnd_x                                          0x1051E00
#define pinstCEventCalendarWnd_x                                   0xDD4084
#define pinstCExtendedTargetWnd_x                                  0xDD3C5C
#define pinstCFacePick_x                                           0xDD3B24
#define pinstCFactionWnd_x                                         0xDD38C8
#define pinstCFellowshipWnd_x                                      0x1052000
#define pinstCFileSelectionWnd_x                                   0xDD4080
#define pinstCFindItemWnd_x                                        0xDD38A8
#define pinstCFindLocationWnd_x                                    0x1052158
#define pinstCFriendsWnd_x                                         0xDD3B28
#define pinstCGemsGameWnd_x                                        0xDD38BC
#define pinstCGiveWnd_x                                            0xDD38F0
#define pinstCGroupSearchFiltersWnd_x                              0xDD408C
#define pinstCGroupSearchWnd_x                                     0x1052550
#define pinstCGroupWnd_x                                           0x1052600
#define pinstCGuildBankWnd_x                                       0xE96F2C
#define pinstCGuildCreationWnd_x                                   0x1052760
#define pinstCGuildMgmtWnd_x                                       0x1052810
#define pinstCharacterCreation_x                                   0xDD3B18
#define pinstCHelpWnd_x                                            0xDD3B64
#define pinstCHeritageSelectionWnd_x                               0xDD3B30
#define pinstCHotButtonWnd_x                                       0x1054968
#define pinstCHotButtonWnd1_x                                      0x1054968
#define pinstCHotButtonWnd2_x                                      0x105496C
#define pinstCHotButtonWnd3_x                                      0x1054970
#define pinstCHotButtonWnd4_x                                      0x1054974
#define pinstCIconSelectionWnd_x                                   0xDD4074
#define pinstCInspectWnd_x                                         0xDD3B58
#define pinstCInventoryWnd_x                                       0xDD3B38
#define pinstCInvSlotMgr_x                                         0xDD387C
#define pinstCItemDisplayManager_x                                 0x1054EF8
#define pinstCItemExpTransferWnd_x                                 0x105502C
#define pinstCItemOverflowWnd_x                                    0xDD40B0
#define pinstCJournalCatWnd_x                                      0xDD4098
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDD3C58
#define pinstCKeyRingWnd_x                                         0xDD3B80
#define pinstCLargeDialogWnd_x                                     0x1057170
#define pinstCLayoutCopyWnd_x                                      0x1055378
#define pinstCLFGuildWnd_x                                         0x1055428
#define pinstCLoadskinWnd_x                                        0xDD38CC
#define pinstCLootFiltersCopyWnd_x                                 0xCA4A50
#define pinstCLootFiltersWnd_x                                     0xDD3904
#define pinstCLootSettingsWnd_x                                    0xDD3B20
#define pinstCLootWnd_x                                            0xDD409C
#define pinstCMailAddressBookWnd_x                                 0xDD3884
#define pinstCMailCompositionWnd_x                                 0xDD386C
#define pinstCMailIgnoreListWnd_x                                  0xDD3888
#define pinstCMailWnd_x                                            0xDD3830
#define pinstCManageLootWnd_x                                      0xDD4F08
#define pinstCMapToolbarWnd_x                                      0xDD3B68
#define pinstCMapViewWnd_x                                         0xDD3B48
#define pinstCMarketplaceWnd_x                                     0xDD3B08
#define pinstCMerchantWnd_x                                        0xDD40A0
#define pinstCMIZoneSelectWnd_x                                    0x1055C60
#define pinstCMusicPlayerWnd_x                                     0xDD40A4
#define pinstCNameChangeMercWnd_x                                  0xDD38A4
#define pinstCNameChangePetWnd_x                                   0xDD3894
#define pinstCNameChangeWnd_x                                      0xDD38C4
#define pinstCNoteWnd_x                                            0xDD3B4C
#define pinstCObjectPreviewWnd_x                                   0xDD3B1C
#define pinstCOptionsWnd_x                                         0xDD3B50
#define pinstCPetInfoWnd_x                                         0xDD40B4
#define pinstCPetitionQWnd_x                                       0xDD406C
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDD3848
#define pinstCPlayerWnd_x                                          0xDD3820
#define pinstCPopupWndManager_x                                    0x10564F0
#define pinstCProgressionSelectionWnd_x                            0x10565A0
#define pinstCPurchaseGroupWnd_x                                   0xDD3B5C
#define pinstCPurchaseWnd_x                                        0xDD3B44
#define pinstCPvPLeaderboardWnd_x                                  0x1056650
#define pinstCPvPStatsWnd_x                                        0x1056700
#define pinstCQuantityWnd_x                                        0xDD3C60
#define pinstCRaceChangeWnd_x                                      0xDD38F4
#define pinstCRaidOptionsWnd_x                                     0xDD4090
#define pinstCRaidWnd_x                                            0xDD3870
#define pinstCRealEstateItemsWnd_x                                 0xDD3878
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDD40A8
#define pinstCRealEstateManageWnd_x                                0xDD3B6C
#define pinstCRealEstateNeighborhoodWnd_x                          0xDD3B8C
#define pinstCRealEstatePlotSearchWnd_x                            0xDD3BC8
#define pinstCRealEstatePurchaseWnd_x                              0xDD3C54
#define pinstCRespawnWnd_x                                         0xDD3BDC
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDD388C
#define pinstCSendMoneyWnd_x                                       0xDD3B0C
#define pinstCServerListWnd_x                                      0xDD3B3C
#define pinstCSkillsSelectWnd_x                                    0xDD38E4
#define pinstCSkillsWnd_x                                          0xDD38AC
#define pinstCSocialEditWnd_x                                      0xDD3B7C
#define pinstCSocialWnd_x                                          0xDD38A0
#define pinstCSpellBookWnd_x                                       0xDD38E0
#define pinstCStoryWnd_x                                           0xDD3824
#define pinstCTargetOfTargetWnd_x                                  0x1058528
#define pinstCTargetWnd_x                                          0xDD3BD8
#define pinstCTaskOverlayWnd_x                                     0xDD3B54
#define pinstCTaskSelectWnd_x                                      0x1058680
#define pinstCTaskManager_x                                        0xCA53A0
#define pinstCTaskTemplateSelectWnd_x                              0x1058730
#define pinstCTaskWnd_x                                            0x10587E0
#define pinstCTextEntryWnd_x                                       0xDD3B98
#define pinstCTimeLeftWnd_x                                        0xDD3BD4
#define pinstCTipWndCONTEXT_x                                      0x10589E4
#define pinstCTipWndOFDAY_x                                        0x10589E0
#define pinstCTitleWnd_x                                           0x1058A90
#define pinstCTrackingWnd_x                                        0xDD3B40
#define pinstCTradeskillWnd_x                                      0x1058BF8
#define pinstCTradeWnd_x                                           0xDD3868
#define pinstCTrainWnd_x                                           0xDD3864
#define pinstCTributeBenefitWnd_x                                  0x1058DF8
#define pinstCTributeMasterWnd_x                                   0x1058EA8
#define pinstCTributeTrophyWnd_x                                   0x1058F58
#define pinstCVideoModesWnd_x                                      0xDD3900
#define pinstCVoiceMacroWnd_x                                      0xF39C30
#define pinstCVoteResultsWnd_x                                     0xDD3874
#define pinstCVoteWnd_x                                            0xDD384C
#define pinstCWebManager_x                                         0xF3A2AC
#define pinstCZoneGuideWnd_x                                       0xDD3B60
#define pinstCZonePathWnd_x                                        0xDD3B78

#define pinstEQSuiteTextureLoader_x                                0xC73570
#define pinstItemIconCache_x                                       0x1051DB8
#define pinstLootFiltersManager_x                                  0xCA4B00
#define pinstRewardSelectionWnd_x                                  0x1056E48

////
// Section 3: Miscellaneous Offsets
////
#define __AppCrashWrapper_x                                        0xC23EA0
#define __CastRay_x                                                0x59C880
#define __CastRay2_x                                               0x59C8D0
#define __ConvertItemTags_x                                        0x5B8430
#define __CleanItemTags_x                                          0x4779D0
#define __CrashHandler_x                                           0x852730
#define __DoesFileExist_x                                          0x8F4B80
#define __EQGetTime_x                                              0x8F1590
#define __ExecuteCmd_x                                             0x595290
#define __FixHeading_x                                             0x98C460
#define __GameLoop_x                                               0x6AA070
#define __get_bearing_x                                            0x59C3F0
#define __get_melee_range_x                                        0x59CAC0
#define __GetAnimationCache_x                                      0x70EFD0
#define __GetGaugeValueFromEQ_x                                    0x804160
#define __GetLabelFromEQ_x                                         0x805C40
#define __GetXTargetType_x                                         0x98DEB0
#define __HandleMouseWheel_x                                       0x6AAC60
#define __HeadingDiff_x                                            0x98C4D0
#define __HelpPath_x                                               0xF34FDC
#define __LoadFrontEnd_x                                           0x6A6B40
#define __NewUIINI_x                                               0x803E30
#define __pCrashHandler_x                                          0x1076358
#define __ProcessGameEvents_x                                      0x5FC5D0
#define __ProcessMouseEvent_x                                      0x5FBD90
#define __SaveColors_x                                             0x546080
#define __STMLToText_x                                             0x92FB60
#define __ToggleKeyRingItem_x                                      0x507BD0
#define CMemoryMappedFile__SetFile_x                               0xA664A0
#define CrashDetected_x                                            0x6A85C0
#define DrawNetStatus_x                                            0x628660
#define Expansion_HoT_x                                            0xE96F34
#define Teleport_Table_Size_x                                      0xE86308
#define Teleport_Table_x                                           0xE86768
#define Util__FastTime_x                                           0x8F1160
#define wwsCrashReportCheckForUploader_x                           0x853670
#define wwsCrashReportPlatformLaunchUploader_x                     0x855D50
#define __eq_delete_x                                              0x9948CE
#define __eq_new_x                                                 0x994E9C

////
// Section 4: Function Offsets
////
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48AD80
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x493C90
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x493A60
#define CAdvancedLootWnd__AddPlayerToList_x                        0x48E310
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x48D760

// AltAdvManager
#define AltAdvManager__GetCalculatedTimer_x                        0x54DAD0
#define AltAdvManager__IsAbilityReady_x                            0x54CA50
#define AltAdvManager__GetAAById_x                                 0x54CC50
#define AltAdvManager__CanTrainAbility_x                           0x54CCC0
#define AltAdvManager__CanSeeAbility_x                             0x54D020

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C6740
#define CharacterZoneClient__HasSkill_x                            0x4D1630
#define CharacterZoneClient__MakeMeVisible_x                       0x4D2D50
#define CharacterZoneClient__IsStackBlocked_x                      0x4BAE00
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B7540
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D56B0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D5790
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D5870
#define CharacterZoneClient__FindAffectSlot_x                      0x4BF900
#define CharacterZoneClient__BardCastBard_x                        0x4C2460
#define CharacterZoneClient__GetMaxEffects_x                       0x4B7610
#define CharacterZoneClient__GetEffect_x                           0x4B7480
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C0940
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C0A10
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C0A60
#define CharacterZoneClient__CalcAffectChange_x                    0x4C0BB0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C0D90
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4AF3D0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D3CB0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D3730

// CBankWnd
#define CBankWnd__GetNumBankSlots_x                                0x6D0A10
#define CBankWnd__WndNotification_x                                0x6D07F0

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6DE250

// CButtonWnd
#define CButtonWnd__SetCheck_x                                     0x60B0C0
#define CButtonWnd__CButtonWnd_x                                   0x92BF40
#define CButtonWnd__dCButtonWnd_x                                  0x92C210
#define CButtonWnd__vftable_x                                      0xB1D404 

// CChatWindowManager
#define CChatWindowManager__GetRGBAFromIndex_x                     0x6FE160
#define CChatWindowManager__InitContextMenu_x                      0x6F7330
#define CChatWindowManager__FreeChatWindow_x                       0x6FCC80
#define CChatWindowManager__GetLockedActiveChatWindow_x            0x4E4B70
#define CChatWindowManager__SetLockedActiveChatWindow_x            0x6FDDE0
#define CChatWindowManager__CreateChatWindow_x                     0x6FD2C0

// ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E4C80

// CChatWindow
#define CChatWindow__CChatWindow_x                                 0x6FEA10
#define CChatWindow__Clear_x                                       0x6FFCD0
#define CChatWindow__WndNotification_x                             0x700460
#define CChatWindow__AddHistory_x                                  0x6FF590

// CContextMenu
#define CContextMenu__CContextMenu_x                               0x940500
#define CContextMenu__dCContextMenu_x                              0x940730
#define CContextMenu__AddMenuItem_x                                0x940740
#define CContextMenu__RemoveMenuItem_x                             0x940A40
#define CContextMenu__RemoveAllMenuItems_x                         0x940A60
#define CContextMenu__CheckMenuItem_x                              0x940AE0
#define CContextMenu__SetMenuItem_x                                0x940970
#define CContextMenu__AddSeparator_x                               0x9408D0

// CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x941080
#define CContextMenuManager__RemoveMenu_x                          0x9410F0
#define CContextMenuManager__PopupMenu_x                           0x9411B0
#define CContextMenuManager__Flush_x                               0x941020
#define CContextMenuManager__GetMenu_x                             0x495FC0
#define CContextMenuManager__CreateDefaultMenu_x                   0x709810

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D2230
#define CChatService__GetFriendName_x                              0x8D2240

// CComboWnd
#define CComboWnd__DeleteAll_x                                     0x93D970
#define CComboWnd__Draw_x                                          0x93CE70
#define CComboWnd__GetCurChoice_x                                  0x93D7B0
#define CComboWnd__GetListRect_x                                   0x93D320
#define CComboWnd__GetTextRect_x                                   0x93D9D0
#define CComboWnd__InsertChoice_x                                  0x93D4B0
#define CComboWnd__SetColors_x                                     0x93D480
#define CComboWnd__SetChoice_x                                     0x93D780
#define CComboWnd__GetItemCount_x                                  0x93D7C0
#define CComboWnd__GetCurChoiceText_x                              0x93D800
#define CComboWnd__GetChoiceText_x                                 0x93D7D0
#define CComboWnd__InsertChoiceAtIndex_x                           0x93D540

// CContainerWnd
#define CContainerWnd__HandleCombine_x                             0x7071F0
#define CContainerWnd__vftable_x                                   0xAEA744
#define CContainerWnd__SetContainer_x                              0x708750

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x540B20
#define CDisplay__PreZoneMainUI_x                                  0x540B30
#define CDisplay__CleanGameUI_x                                    0x545E40
#define CDisplay__GetClickedActor_x                                0x538E40
#define CDisplay__GetUserDefinedColor_x                            0x531500
#define CDisplay__GetWorldFilePath_x                               0x53A8B0
#define CDisplay__is3dON_x                                         0x535AA0
#define CDisplay__ReloadUI_x                                       0x53FFB0
#define CDisplay__WriteTextHD2_x                                   0x535890
#define CDisplay__TrueDistance_x                                   0x53C570
#define CDisplay__SetViewActor_x                                   0x538760
#define CDisplay__GetFloorHeight_x                                 0x535B60
#define CDisplay__SetRenderWindow_x                                0x5344C0
#define CDisplay__ToggleScreenshotMode_x                           0x538230

// CEditBaseWnd
#define CEditBaseWnd__SetSel_x                                     0x960120

// CEditWnd
#define CEditWnd__DrawCaret_x                                      0x943A70
#define CEditWnd__GetCharIndexPt_x                                 0x944990
#define CEditWnd__GetDisplayString_x                               0x944830
#define CEditWnd__GetHorzOffset_x                                  0x9430A0
#define CEditWnd__GetLineForPrintableChar_x                        0x945B30
#define CEditWnd__GetSelStartPt_x                                  0x944C40
#define CEditWnd__GetSTMLSafeText_x                                0x944650
#define CEditWnd__PointFromPrintableChar_x                         0x945760
#define CEditWnd__SelectableCharFromPoint_x                        0x9458D0
#define CEditWnd__SetEditable_x                                    0x944D10
#define CEditWnd__SetWindowTextA_x                                 0x9443D0

// CEverQuest
#define CEverQuest__DoPercentConvert_x                             0x5EA250
#define CEverQuest__ClickedPlayer_x                                0x5DC390
#define CEverQuest__CreateTargetIndicator_x                        0x5F9870
#define CEverQuest__DeleteTargetIndicator_x                        0x5F9900
#define CEverQuest__DoTellWindow_x                                 0x4E4D60
#define CEverQuest__OutputTextToLog_x                              0x4E4FC0
#define CEverQuest__DropHeldItemOnGround_x                         0x5D13D0
#define CEverQuest__dsp_chat_x                                     0x4E5350
#define CEverQuest__trimName_x                                     0x5F5B60
#define CEverQuest__Emote_x                                        0x5EAAB0
#define CEverQuest__EnterZone_x                                    0x5E4A30
#define CEverQuest__GetBodyTypeDesc_x                              0x5EF420
#define CEverQuest__GetClassDesc_x                                 0x5EFA60
#define CEverQuest__GetClassThreeLetterCode_x                      0x5F0060
#define CEverQuest__GetDeityDesc_x                                 0x5F81B0
#define CEverQuest__GetLangDesc_x                                  0x5F0220
#define CEverQuest__GetRaceDesc_x                                  0x5EFA40
#define CEverQuest__InterpretCmd_x                                 0x5F8780
#define CEverQuest__LeftClickedOnPlayer_x                          0x5D55D0
#define CEverQuest__LMouseUp_x                                     0x5D3960
#define CEverQuest__RightClickedOnPlayer_x                         0x5D5EB0
#define CEverQuest__RMouseUp_x                                     0x5D48E0
#define CEverQuest__SetGameState_x                                 0x5D1160
#define CEverQuest__UPCNotificationFlush_x                         0x5F5A60
#define CEverQuest__IssuePetCommand_x                              0x5F1620
#define CEverQuest__ReportSuccessfulHit_x                          0x5EBEA0

// CGaugeWnd
// not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x719150
#define CGaugeWnd__CalcLinesFillRect_x                             0x7191B0
#define CGaugeWnd__Draw_x                                          0x7187D0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ABEC0
#define CGuild__GetGuildName_x                                     0x4AAFA0
#define CGuild__GetGuildIndex_x                                    0x4AB330

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton_x                               0x7345E0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x60B480

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot_x                                 0x741560
#define CInvSlotMgr__MoveItem_x                                    0x7402E0
#define CInvSlotMgr__SelectSlot_x                                  0x741630

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x73EB90
#define CInvSlot__SliderComplete_x                                 0x73C920
#define CInvSlot__GetItemBase_x                                    0x73C2C0
#define CInvSlot__UpdateItem_x                                     0x73C430

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x743080
#define CInvSlotWnd__CInvSlotWnd_x                                 0x742230
#define CInvSlotWnd__HandleLButtonUp_x                             0x742C00

// CItemDisplayWnd
#define CItemDisplayWnd__SetSpell_x                                0x7FF550
#define CItemDisplayWnd__UpdateStrings_x                           0x751740
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x74B4A0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x74B9B0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x751D40
#define CItemDisplayWnd__AboutToShow_x                             0x751390
#define CItemDisplayWnd__WndNotification_x                         0x752E20
#define CItemDisplayWnd__RequestConvertItem_x                      0x7528E0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x7503F0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x7511B0

// CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x837FA0

// CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x757320

// CLabel
#define CLabel__Draw_x                                             0x75CD60

// CListWnd
#define CListWnd__CListWnd_x                                       0x916180
#define CListWnd__dCListWnd_x                                      0x916490
#define CListWnd__vftable_x                                        0xB1CD58
#define CListWnd__AddColumn_x                                      0x91A8D0
#define CListWnd__AddColumn1_x                                     0x91A920
#define CListWnd__AddLine_x                                        0x91ACB0
#define CListWnd__AddString_x                                      0x91AAB0
#define CListWnd__CalculateFirstVisibleLine_x                      0x91A690
#define CListWnd__CalculateVSBRange_x                              0x91A470
#define CListWnd__ClearSel_x                                       0x91B490
#define CListWnd__ClearAllSel_x                                    0x91B4F0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x91BEE0
#define CListWnd__Compare_x                                        0x919DB0
#define CListWnd__Draw_x                                           0x9165C0
#define CListWnd__DrawColumnSeparators_x                           0x918D80
#define CListWnd__DrawHeader_x                                     0x9191F0
#define CListWnd__DrawItem_x                                       0x9196F0
#define CListWnd__DrawLine_x                                       0x918EF0
#define CListWnd__DrawSeparator_x                                  0x918E20
#define CListWnd__EnableLine_x                                     0x918670
#define CListWnd__EnsureVisible_x                                  0x91BE10
#define CListWnd__ExtendSel_x                                      0x91B3C0
#define CListWnd__GetColumnTooltip_x                               0x9181B0
#define CListWnd__GetColumnMinWidth_x                              0x918220
#define CListWnd__GetColumnWidth_x                                 0x918120
#define CListWnd__GetCurSel_x                                      0x917AB0
#define CListWnd__GetItemAtPoint_x                                 0x9188E0
#define CListWnd__GetItemAtPoint1_x                                0x918950
#define CListWnd__GetItemData_x                                    0x917B30
#define CListWnd__GetItemHeight_x                                  0x917EF0
#define CListWnd__GetItemIcon_x                                    0x917CC0
#define CListWnd__GetItemRect_x                                    0x918760
#define CListWnd__GetItemText_x                                    0x917B70
#define CListWnd__GetSelList_x                                     0x91B540
#define CListWnd__GetSeparatorRect_x                               0x918B90
#define CListWnd__InsertLine_x                                     0x91B0A0
#define CListWnd__RemoveLine_x                                     0x91B1F0
#define CListWnd__SetColors_x                                      0x91A440
#define CListWnd__SetColumnJustification_x                         0x91A180
#define CListWnd__SetColumnWidth_x                                 0x91A0A0
#define CListWnd__SetCurSel_x                                      0x91B300
#define CListWnd__SetItemColor_x                                   0x91BAD0
#define CListWnd__SetItemData_x                                    0x91BA90
#define CListWnd__SetItemText_x                                    0x91B6B0
#define CListWnd__ShiftColumnSeparator_x                           0x91A240
#define CListWnd__Sort_x                                           0x919F30
#define CListWnd__ToggleSel_x                                      0x91B330
#define CListWnd__SetColumnsSizable_x                              0x91A2E0
#define CListWnd__SetItemWnd_x                                     0x91B960
#define CListWnd__GetItemWnd_x                                     0x917D10
#define CListWnd__SetItemIcon_x                                    0x91B730
#define CListWnd__CalculateCustomWindowPositions_x                 0x91A790
#define CListWnd__SetVScrollPos_x                                  0x91A080

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd_x                                 0x7724C0
#define CMapViewWnd__GetWorldCoordinates_x                         0x770BD0
#define CMapViewWnd__HandleLButtonDown_x                           0x76DC10

// MapViewMap
#define MapViewMap__Clear_x                                        0x76E330
#define MapViewMap__SaveEx_x                                       0x7716F0
#define MapViewMap__SetZoom_x                                      0x775DB0

// CMerchantWnd
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7953C0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x795CA0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7961D0
#define CMerchantWnd__SelectRecoverySlot_x                         0x799150
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x793F30
#define CMerchantWnd__SelectBuySellSlot_x                          0x79ECF0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x794FD0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89FEB0
#define CPacketScrambler__hton_x                                   0x89FEA0

// CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x939540
#define CSidlManagerBase__CreatePageWnd_x                          0x938D50
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x934FE0
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x934F70
#define CSidlManagerBase__FindAnimation1_x                         0x9351C0
#define CSidlManagerBase__FindScreenPieceTemplate_x                0x9355D0
#define CSidlManagerBase__FindScreenPieceTemplate1_x               0x9353C0
#define CSidlManagerBase__CreateLabel_x                            0x7F6940
#define CSidlManagerBase__CreateXWndFromTemplate_x                 0x938530
#define CSidlManagerBase__CreateXWndFromTemplate1_x                0x938700
#define CSidlManagerBase__CreateXWnd_x                             0x7F6870

// CSidlManager
#define CSidlManager__CreateHotButtonWnd_x                         0x7F6E30

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateHSBRange_x                        0x931C80
#define CSidlScreenWnd__CalculateVSBRange_x                        0x931B80
#define CSidlScreenWnd__ConvertToRes_x                             0x957120
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x931610
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x931300
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x9313D0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x9314A0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x932120
#define CSidlScreenWnd__EnableIniStorage_x                         0x9325F0
#define CSidlScreenWnd__GetChildItem_x                             0x932570
#define CSidlScreenWnd__GetSidlPiece_x                             0x932310
#define CSidlScreenWnd__HandleLButtonUp_x                          0x921D40
#define CSidlScreenWnd__Init1_x                                    0x930F00
#define CSidlScreenWnd__LoadIniInfo_x                              0x932640
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9331A0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x930310
#define CSidlScreenWnd__m_layoutCopy_x                             0x16D1390
#define CSidlScreenWnd__StoreIniInfo_x                             0x932D10
#define CSidlScreenWnd__StoreIniVis_x                              0x933080
#define CSidlScreenWnd__vftable_x                                  0xB1D6A0
#define CSidlScreenWnd__WndNotification_x                          0x932030

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x66FE30
#define CSkillMgr__GetSkillCap_x                                   0x670010
#define CSkillMgr__GetNameToken_x                                  0x66F5B0
#define CSkillMgr__IsActivatedSkill_x                              0x66F6F0
#define CSkillMgr__IsCombatSkill_x                                 0x66F630

// CSliderWnd
#define CSliderWnd__GetValue_x                                     0x941E70
#define CSliderWnd__SetValue_x                                     0x941CE0
#define CSliderWnd__SetNumTicks_x                                  0x941D40

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet_x                               0x7FC9D0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x94A680
#define CStmlWnd__CalculateHSBRange_x                              0x94B760
#define CStmlWnd__CalculateVSBRange_x                              0x94B6D0
#define CStmlWnd__CanBreakAtCharacter_x                            0x94FAB0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x950740
#define CStmlWnd__ForceParseNow_x                                  0x94AC20
#define CStmlWnd__GetNextTagPiece_x                                0x94FA10
#define CStmlWnd__GetSTMLText_x                                    0x4F7800
#define CStmlWnd__GetVisibleText_x                                 0x94AC40
#define CStmlWnd__InitializeWindowVariables_x                      0x950590
#define CStmlWnd__MakeStmlColorTag_x                               0x949CF0
#define CStmlWnd__MakeWndNotificationTag_x                         0x949D60
#define CStmlWnd__SetSTMLText_x                                    0x948DA0
#define CStmlWnd__StripFirstSTMLLines_x                            0x951840
#define CStmlWnd__UpdateHistoryString_x                            0x950950

// CTabWnd
#define CTabWnd__Draw_x                                            0x947EF0
#define CTabWnd__DrawCurrentPage_x                                 0x948620
#define CTabWnd__DrawTab_x                                         0x948340
#define CTabWnd__GetCurrentPage_x                                  0x9476F0
#define CTabWnd__GetPageInnerRect_x                                0x947930
#define CTabWnd__GetTabInnerRect_x                                 0x947870
#define CTabWnd__GetTabRect_x                                      0x947720
#define CTabWnd__InsertPage_x                                      0x947B40
#define CTabWnd__SetPage_x                                         0x9479B0
#define CTabWnd__SetPageRect_x                                     0x947E30
#define CTabWnd__UpdatePage_x                                      0x948200
#define CTabWnd__GetPageFromTabIndex_x                             0x948280
#define CTabWnd__GetCurrentTabIndex_x                              0x9476E0

// CPageWnd
#define CPageWnd__GetTabText_x                                     0x7576F0
#define CPageWnd__SetTabText_x                                     0x947240

// CTextOverlay
#define CTextOverlay__DisplayText_x                                0x4A5B30

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91EBD0
#define CTextureFont__GetTextExtent_x                              0x91ED90

// CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6A3A40
#define CHtmlComponentWnd__ValidateUri_x                           0x735FD0
#define CHtmlWnd__SetClientCallbacks_x                             0x6104F0
#define CHtmlWnd__AddObserver_x                                    0x610510
#define CHtmlWnd__RemoveObserver_x                                 0x610570
#define Window__getProgress_x                                      0x850440
#define Window__getStatus_x                                        0x850460
#define Window__getURI_x                                           0x850470

// CXMLDataManager
#define CXMLDataManager__GetXMLData_x                              0x95CBB0

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead_x                             0x90BD50

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr_x                                             0x4E4A60
#define CXStr__CXStr1_x                                            0x47BEB0
#define CXStr__CXStr3_x                                            0x8ED690
#define CXStr__dCXStr_x                                            0x472EF0
#define CXStr__operator_equal_x                                    0x8ED8C0
#define CXStr__operator_equal1_x                                   0x8ED900
#define CXStr__operator_plus_equal1_x                              0x8EE390
#define CXStr__SetString_x                                         0x8F0280
#define CXStr__operator_char_p_x                                   0x8EDE00
#define CXStr__GetChar_x                                           0x8EFBD0
#define CXStr__Delete_x                                            0x8EF480
#define CXStr__GetUnicode_x                                        0x8EFC40
#define CXStr__GetLength_x                                         0x4A58D0
#define CXStr__Mid_x                                               0x477D80
#define CXStr__Insert_x                                            0x8EFCA0
#define CXStr__FindNext_x                                          0x8EF8F0
#define CXStr__gFreeLists_x                                        0xC719B0
#define CXStr__gCXStrAccess_x                                      0x16D0AAC

// CTileLayoutWnd
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x940120

// CXWnd
#define CXWnd__BringToTop_x                                        0x9254B0
#define CXWnd__Center_x                                            0x925030
#define CXWnd__ClrFocus_x                                          0x924E50
#define CXWnd__Destroy_x                                           0x924EF0
#define CXWnd__DoAllDrawing_x                                      0x9214F0
#define CXWnd__DrawChildren_x                                      0x9214C0
#define CXWnd__DrawColoredRect_x                                   0x921950
#define CXWnd__DrawTooltip_x                                       0x920010
#define CXWnd__DrawTooltipAtPoint_x                                0x9200D0
#define CXWnd__GetBorderFrame_x                                    0x9217B0
#define CXWnd__GetChildItem_x                                      0x9256C0
#define CXWnd__GetChildWndAt_x                                     0x925550
#define CXWnd__GetClientClipRect_x                                 0x923740
#define CXWnd__GetScreenClipRect_x                                 0x923810
#define CXWnd__GetScreenRect_x                                     0x9239B0
#define CXWnd__GetTooltipRect_x                                    0x9219A0
#define CXWnd__GetWindowTextA_x                                    0x4976A0
#define CXWnd__IsActive_x                                          0x9220C0
#define CXWnd__IsDescendantOf_x                                    0x924390
#define CXWnd__IsReallyVisible_x                                   0x9243C0
#define CXWnd__IsType_x                                            0x925BD0
#define CXWnd__Minimize_x                                          0x924AD0
#define CXWnd__Move_x                                              0x924430
#define CXWnd__Move1_x                                             0x9244F0
#define CXWnd__ProcessTransition_x                                 0x924FE0
#define CXWnd__Refade_x                                            0x9247D0
#define CXWnd__Resize_x                                            0x924A60
#define CXWnd__Right_x                                             0x925270
#define CXWnd__SetFocus_x                                          0x924E10
#define CXWnd__SetFont_x                                           0x924E80
#define CXWnd__SetKeyTooltip_x                                     0x9259E0
#define CXWnd__SetMouseOver_x                                      0x922900
#define CXWnd__SetParent_x                                         0x924160
#define CXWnd__StartFade_x                                         0x924270
#define CXWnd__vftable_x                                           0xB1D1A4
#define CXWnd__CXWnd_x                                             0x91F0B0
#define CXWnd__dCXWnd_x                                            0x91F610

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x9581A0

// CXWndManager
#define CXWndManager__DrawCursor_x                                 0x928420
#define CXWndManager__DrawWindows_x                                0x928440
#define CXWndManager__GetKeyboardFlags_x                           0x92AB50
#define CXWndManager__HandleKeyboardMsg_x                          0x92A700
#define CXWndManager__RemoveWnd_x                                  0x92AD90
#define CXWndManager__RemovePendingDeletionWnd_x                   0x92B2D0

// CDBStr
#define CDBStr__GetString_x                                        0x530460

// CharacterZoneClient
#define CharacterZoneClient__CastSpell_x                           0x4B8520
#define CharacterZoneClient__Cur_HP_x                              0x4CE670
#define CharacterZoneClient__Cur_Mana_x                            0x4D5D70
#define CharacterZoneClient__GetCastingTimeModifier_x              0x4BB450
#define CharacterZoneClient__GetFocusCastingTimeModifier_x         0x4AF010
#define CharacterZoneClient__GetFocusRangeModifier_x               0x4AF160
#define CharacterZoneClient__GetHPRegen_x                          0x4DBB10
#define CharacterZoneClient__GetEnduranceRegen_x                   0x4DC110
#define CharacterZoneClient__GetManaRegen_x                        0x4DC550
#define CharacterZoneClient__Max_Endurance_x                       0x6363C0
#define CharacterZoneClient__Max_HP_x                              0x4CE4A0
#define CharacterZoneClient__Max_Mana_x                            0x6361C0
#define CharacterZoneClient__doCombatAbility_x                     0x638800
#define CharacterZoneClient__UseSkill_x                            0x4DE320
#define CharacterZoneClient__IsExpansionFlag_x                     0x593A70
#define CharacterZoneClient__TotalEffect_x                         0x4C1BA0
#define CharacterZoneClient__GetPCSpellAffect_x                    0x4BC060
#define CharacterZoneClient__SpellDuration_x                       0x4BBB90
#define CharacterZoneClient__GetAdjustedSkill_x                    0x4D13F0
#define CharacterZoneClient__GetBaseSkill_x                        0x4D2390
#define CharacterZoneClient__CanUseItem_x                          0x4D6080

// ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BF110

// PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x64CD10

// PcClient
#define PcClient__PcClient_x                                       0x62CD00
#define PcClient__GetConLevel_x                                    0x62F5D0

// CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6190
#define CCharacterListWnd__EnterWorld_x                            0x4B5BD0
#define CCharacterListWnd__Quit_x                                  0x4B5920
#define CCharacterListWnd__UpdateList_x                            0x4B5D60

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x611740
#define EQ_Item__CreateItemTagString_x                             0x899750
#define EQ_Item__IsStackable_x                                     0x89E270
#define EQ_Item__GetImageNum_x                                     0x89B1C0
#define EQ_Item__CreateItemClient_x                                0x610910
#define EQ_Item__GetItemValue_x                                    0x89C4C0
#define EQ_Item__ValueSellMerchant_x                               0x89FA90
#define EQ_Item__IsKeyRingItem_x                                   0x89DBC0
#define EQ_Item__CanGoInBag_x                                      0x611860
#define EQ_Item__IsEmpty_x                                         0x89D740
#define EQ_Item__GetMaxItemCount_x                                 0x89C8E0
#define EQ_Item__GetHeldItem_x                                     0x89B090
#define EQ_Item__GetAugmentFitBySlot_x                             0x8990C0

// EQ_LoadingS
#define EQ_LoadingS__SetProgressBar_x                              0x54E7D0
#define EQ_LoadingS__Array_x                                       0xBFB690

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x636D10
#define EQ_PC__GetAlternateAbilityId_x                             0x8A8BD0
#define EQ_PC__GetCombatAbility_x                                  0x8A9240
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A92B0
#define EQ_PC__GetItemRecastTimer_x                                0x638D80
#define EQ_PC__HasLoreItem_x                                       0x62FDE0
#define EQ_PC__AlertInventoryChanged_x                             0x62EF00
#define EQ_PC__GetPcZoneClient_x                                   0x65B780
#define EQ_PC__RemoveMyAffect_x                                    0x63BFC0
#define EQ_PC__GetKeyRingItems_x                                   0x8A9B10
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A98D0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A9E00

// EQItemList
#define EQItemList__EQItemList_x                                   0x599F10
#define EQItemList__add_object_x                                   0x5C6BE0
#define EQItemList__add_item_x                                     0x59A470
#define EQItemList__delete_item_x                                  0x59A4C0
#define EQItemList__FreeItemList_x                                 0x59A3C0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x52CF90

// EQPlayer
#define EQPlayer__ChangeBoneStringSprite_x                         0x64E590
#define EQPlayer__dEQPlayer_x                                      0x6414D0
#define EQPlayer__DoAttack_x                                       0x656450
#define EQPlayer__EQPlayer_x                                       0x641B90
#define EQPlayer__SetNameSpriteState_x                             0x646280
#define EQPlayer__SetNameSpriteTint_x                              0x647140
#define PlayerBase__HasProperty_j_x                                0x98A7F0
#define EQPlayer__IsTargetable_x                                   0x98AC90
#define EQPlayer__CanSee_x                                         0x98AAF0
#define EQPlayer__CanSee1_x                                        0x98ABC0
#define PlayerBase__GetVisibilityLineSegment_x                     0x98A8B0

// PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x659220
#define PlayerZoneClient__GetLevel_x                               0x65B7C0
#define PlayerZoneClient__IsValidTeleport_x                        0x5C7D50
#define PlayerZoneClient__LegalPlayerRace_x                        0x547C70

// EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x651340
#define EQPlayerManager__GetSpawnByName_x                          0x6513F0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x651480

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x614DA0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x614E20
#define KeypressHandler__AttachKeyToEqCommand_x                    0x614E60
#define KeypressHandler__ClearCommandStateArray_x                  0x616270
#define KeypressHandler__HandleKeyDown_x                           0x616290
#define KeypressHandler__HandleKeyUp_x                             0x616330
#define KeypressHandler__SaveKeymapping_x                          0x616770

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BCF80

// StringTable
#define StringTable__getString_x                                   0x8B7EA0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x63BC30
#define PcZoneClient__RemovePetEffect_x                            0x63C260
#define PcZoneClient__HasAlternateAbility_x                        0x635FF0
#define PcZoneClient__GetCurrentMod_x                              0x4E13D0
#define PcZoneClient__GetModCap_x                                  0x4E12D0
#define PcZoneClient__CanEquipItem_x                               0x6366B0
#define PcZoneClient__GetItemByID_x                                0x639200
#define PcZoneClient__GetItemByItemClass_x                         0x639350
#define PcZoneClient__RemoveBuffEffect_x                           0x63C280
#define PcZoneClient__BandolierSwap_x                              0x6372C0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x638D20

// Doors
#define EQSwitch__UseSwitch_x                                      0x5CC8C0

// IconCache
#define IconCache__GetIcon_x                                       0x70E870

// CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x706390
#define CContainerMgr__CloseContainer_x                            0x706660
#define CContainerMgr__OpenExperimentContainer_x                   0x7070E0

// CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7C91B0

// CHelpWnd
#define CHelpWnd__SetFile_x                                        0x6098B0

// CLootWnd
#define CLootWnd__LootAll_x                                        0x764850
#define CLootWnd__RequestLootSlot_x                                0x763A80

// EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x566CF0
#define EQ_Spell__SpellAffects_x                                   0x567160
#define EQ_Spell__SpellAffectBase_x                                0x566F20
#define EQ_Spell__IsStackable_x                                    0x4C60A0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C5F80
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B34C0
#define EQ_Spell__IsSPAStacking_x                                  0x567FA0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x5674C0
#define EQ_Spell__IsNoRemove_x                                     0x4C6080
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x567FB0
#define __IsResEffectSpell_x                                       0x4C5520

// EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4A9C20

// EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C7650

// CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x80FBF0
#define CTargetWnd__WndNotification_x                              0x80F480
#define CTargetWnd__RefreshTargetBuffs_x                           0x80F750
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x80E5E0

// CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x814200

// CTaskManager
#define CTaskManager__GetEntry_x                                   0x52A980
#define CTaskManager__HandleMessage_x                              0x528E30

// EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5622B0
#define EqSoundManager__PlayScriptMp3_x                            0x562410
#define EqSoundManager__SoundAssistPlay_x                          0x673D20
#define EqSoundManager__WaveInstancePlay_x                         0x673290

// CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x51E740

// CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x946750

// CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x556290
#define CAltAbilityData__GetMercMaxRank_x                          0x556220
#define CAltAbilityData__GetMaxRank_x                              0x54B910

// CTargetRing
#define CTargetRing__Cast_x                                        0x6079C0

// CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C5F60
#define CharacterBase__CreateItemGlobalIndex_x                     0x504440
#define CharacterBase__CreateItemIndex_x                           0x60FAA0
#define CharacterBase__GetItemPossession_x                         0x4F0240
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CFC40
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CFCA0

// CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6ED6E0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6EDF10
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6EDFC0

// messages
#define msg_spell_worn_off_x                                       0x58BC60
#define msg_new_text_x                                             0x580A40
#define __msgTokenTextParam_x                                      0x58E190
#define msgTokenText_x                                             0x58E3E0

// SpellManager
#define SpellManager__vftable_x                                    0xAC4C0C
#define SpellManager__SpellManager_x                               0x677050
#define Spellmanager__LoadTextSpells_x                             0x677950
#define SpellManager__GetSpellByGroupAndRank_x                     0x677220

// CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x 0x98E7A0

// ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C7FF0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C8270

// CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x75D0A0

// CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x70AAA0
#define CCursorAttachment__AttachToCursor1_x                       0x70AAE0
#define CCursorAttachment__Deactivate_x                            0x70BAB0

// CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x956600
#define CEQSuiteTextureLoader__GetTexture_x                        0x9562C0

// CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x5019B0
#define CFindItemWnd__WndNotification_x                            0x502490
#define CFindItemWnd__Update_x                                     0x503000
#define CFindItemWnd__PickupSelectedItem_x                         0x501220

// IString
#define IString__Append_x                                          0x4F1A90

// Camera
#define CDisplay__cameraType_x                                     0xDD38FC
#define EverQuest__Cameras_x                                       0xE9727C

// LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x509EA0
#define LootFiltersManager__GetItemFilterData_x                    0x5097A0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x5097D0
#define LootFiltersManager__SetItemLootFilter_x                    0x5099F0

// COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B7180

// CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x994340
#define CResolutionHandler__GetWindowedStyle_x                     0x66E6D0

// CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x703170

// CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8DAA60
#define CDistillerInfo__Instance_x                                 0x8DAA00

// CGroupWnd
#define CGroupWnd__WndNotification_x                               0x723380
#define CGroupWnd__UpdateDisplay_x                                 0x7226D0

// ItemBase
#define ItemBase__IsLore_x                                         0x89DC20
#define ItemBase__IsLoreEquipped_x                                 0x89DCA0

// EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5C6B40
#define EQPlacedItemManager__GetItemByGuid_x                       0x5C6C80
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5C6CE0

// RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x663E80
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x6677F0

// CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x4F7E30

// FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4E67F0
#define FactionManagerClient__HandleFactionMessage_x               0x4E6E60
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4E7460
#define FactionManagerClient__GetMaxFaction_x                      0x4E747F
#define FactionManagerClient__GetMinFaction_x                      0x4E7430

// BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4F0210

// ArrayClass
#define ArrayClass__DeleteElement_x                                0x91DB50

// AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x4969B0

// ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4F04C0

// MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x555750

// CTargetManager
#define CTargetManager__Get_x                                      0x67A8A0

// RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x663E80

// CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A58F0

// EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x59A360

// EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF3490C
