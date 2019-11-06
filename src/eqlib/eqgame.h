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
#define __ExpectedVersionDate                                     "Oct 15 2019"
#define __ExpectedVersionTime                                     "12:24:00"
#define __ActualVersionDate_x                                      0xADD374
#define __ActualVersionTime_x                                      0xADD368
#define __ActualVersionBuild_x                                     0xAC8BB4

// Memory Protection
#define __MemChecker0_x                                            0x61B2D0
#define __MemChecker1_x                                            0x8EE610
#define __MemChecker2_x                                            0x6A9D90
#define __MemChecker3_x                                            0x6A9CE0
#define __MemChecker4_x                                            0x8459B0
#define __EncryptPad0_x                                            0xC0EA28
#define __EncryptPad1_x                                            0xC6CAA8
#define __EncryptPad2_x                                            0xC1F2A8
#define __EncryptPad3_x                                            0xC1EEA8
#define __EncryptPad4_x                                            0xC5D1C8
#define __EncryptPad5_x                                            0xF3633C
#define __AC1_x                                                    0x802596
#define __AC2_x                                                    0x5D4F8F
#define __AC3_x                                                    0x5DC68F
#define __AC4_x                                                    0x5E0540
#define __AC5_x                                                    0x5E684F
#define __AC6_x                                                    0x5EAE66
#define __AC7_x                                                    0x5D4A00
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1F1734

// Direct Input
#define DI8__Main_x                                                0xF35530
#define DI8__Keyboard_x                                            0xF35534
#define DI8__Mouse_x                                               0xF35FD8
#define DI8__Mouse_Copy_x                                          0xE90BF4
#define DI8__Mouse_Check_x                                         0xF36300
#define __AutoSkillArray_x                                         0xE91B0C
#define __Attack_x                                                 0xF2F927
#define __Autofire_x                                               0xF2F928
#define __BindList_x                                               0xBFD480
#define g_eqCommandStates_x                                        0xBFE1F8
#define __Clicks_x                                                 0xE90CAC
#define __CommandList_x                                            0xBFEDB8
#define __CurrentMapLabel_x                                        0x10509C4
#define __CurrentSocial_x                                          0xBE77CC
#define __DoAbilityList_x                                          0xEC7448
#define __do_loot_x                                                0x5A1560
#define __DrawHandler_x                                            0x16CD360
#define __GroupCount_x                                             0xE81042
#define __Guilds_x                                                 0xE87400
#define __gWorld_x                                                 0xE81230
#define __HWnd_x                                                   0xF35FDC
#define __heqmain_x                                                0xF35510
#define __InChatMode_x                                             0xE90BDC
#define __LastTell_x                                               0xE92B44
#define __LMouseHeldTime_x                                         0xE90D18
#define __Mouse_x                                                  0xF3551C
#define __MouseLook_x                                              0xE90C72
#define __MouseEventTime_x                                         0xF3040C
#define __gpbCommandEvent_x                                        0xE8123C
#define __NetStatusToggle_x                                        0xE90C75
#define __PCNames_x                                                0xE920F4
#define __RangeAttackReady_x                                       0xE91DF0
#define __RMouseHeldTime_x                                         0xE90D14
#define __RunWalkState_x                                           0xE90BE0
#define __ScreenMode_x                                             0xDCE874
#define __ScreenX_x                                                0xE90B94
#define __ScreenY_x                                                0xE90B90
#define __ScreenXMax_x                                             0xE90B98
#define __ScreenYMax_x                                             0xE90B9C
#define __ServerHost_x                                             0xE81473
#define __ServerName_x                                             0xEC7408
#define __ShiftKeyDown_x                                           0xE9126C
#define __ShowNames_x                                              0xE91FAC
#define __Socials_x                                                0xEC7508
#define __SubscriptionType_x                                       0x1092548
#define __TargetAggroHolder_x                                      0x1053378
#define __ZoneType_x                                               0xE91070
#define __GroupAggro_x                                             0x10533B8
#define __LoginName_x                                              0xF35C84
#define __Inviter_x                                                0xF2F8A4
#define __AttackOnAssist_x                                         0xE91F68
#define __UseTellWindows_x                                         0xE92290
#define __gfMaxZoomCameraDistance_x                                0xAD28F0
#define __gfMaxCameraDistance_x                                    0xAFF2C8
#define __pulAutoRun_x                                             0xE90C90
#define __pulForward_x                                             0xE922C8
#define __pulBackward_x                                            0xE922CC
#define __pulTurnRight_x                                           0xE922D0
#define __pulTurnLeft_x                                            0xE922D4
#define __pulStrafeLeft_x                                          0xE922D8
#define __pulStrafeRight_x                                         0xE922DC

////
//Section 1: Vital Offsets
////
#define instCRaid_x                                                0xE83798
#define instEQZoneInfo_x                                           0xE90E68
#define pinstActiveBanker_x                                        0xE81254
#define pinstActiveCorpse_x                                        0xE8124C
#define pinstActiveGMaster_x                                       0xE81250
#define pinstActiveMerchant_x                                      0xE81248
#define pinstAltAdvManager_x                                       0xDCFA78
#define pinstBandageTarget_x                                       0xE81264
#define pinstCamActor_x                                            0xDCE860
#define pinstCDBStr_x                                              0xDCE7A4
#define pinstCDisplay_x                                            0xE81024
#define pinstCEverQuest_x                                          0xF3554C
#define pinstEverQuestInfo_x                                       0xE90B88
#define pinstCharData_x                                            0xE81020
#define pinstCharSpawn_x                                           0xE8131C
#define pinstControlledMissile_x                                   0xE8157C
#define pinstControlledPlayer_x                                    0xE8131C
#define pinstCResolutionHandler_x                                  0x16CD590
#define pinstCSidlManager_x                                        0x16CC528
#define pinstCXWndManager_x                                        0x16CC524
#define instDynamicZone_x                                          0xE872D8
#define pinstDZMember_x                                            0xE873E8
#define pinstDZTimerInfo_x                                         0xE873EC
#define pinstEqLogin_x                                             0xF355D0
#define instEQMisc_x                                               0xDCE6E8
#define pinstEQSoundManager_x                                      0xDD09A0
#define pinstEQSpellStrings_x                                      0xC91478
#define instExpeditionLeader_x                                     0xE87322
#define instExpeditionName_x                                       0xE87362
#define pinstGroup_x                                               0xE8103E
#define pinstImeManager_x                                          0x16CC520
#define pinstLocalPlayer_x                                         0xE81244
#define pinstMercenaryData_x                                       0xF31EFC
#define pinstMercenaryStats_x                                      0x10534C4
#define pinstModelPlayer_x                                         0xE8125C
#define pinstPCData_x                                              0xE81020
#define pinstSkillMgr_x                                            0xF34060
#define pinstSpawnManager_x                                        0xF32B08
#define pinstSpellManager_x                                        0xF34280
#define pinstSpellSets_x                                           0xF28550
#define pinstStringTable_x                                         0xE81028
#define pinstSwitchManager_x                                       0xE80D38
#define pinstTarget_x                                              0xE81318
#define pinstTargetObject_x                                        0xE81324
#define pinstTargetSwitch_x                                        0xE83788
#define pinstTaskMember_x                                          0xDCE578
#define pinstTrackTarget_x                                         0xE81320
#define pinstTradeTarget_x                                         0xE81258
#define instTributeActive_x                                        0xDCE709
#define pinstViewActor_x                                           0xDCE85C
#define pinstWorldData_x                                           0xE80E88
#define pinstZoneAddr_x                                            0xE91108
#define pinstPlayerPath_x                                          0xF32BA0
#define pinstTargetIndicator_x                                     0xF344E8
#define EQObject_Top_x                                             0xE81240

////
//Section 2:  UI Related Offsets
////
#define pinstCAAWnd_x                                              0xDCE8C0
#define pinstCAchievementsWnd_x                                    0xDCF0A4
#define pinstCActionsWnd_x                                         0xDCE868
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDCF030
#define pinstCAdvancedLootWnd_x                                    0xDCF000
#define pinstCAdventureLeaderboardWnd_x                            0x104A198
#define pinstCAdventureRequestWnd_x                                0x104A248
#define pinstCAdventureStatsWnd_x                                  0x104A2F8
#define pinstCAggroMeterWnd_x                                      0xDCF090
#define pinstCAlarmWnd_x                                           0xDCE964
#define pinstCAlertHistoryWnd_x                                    0xDCE928
#define pinstCAlertStackWnd_x                                      0xDCE880
#define pinstCAlertWnd_x                                           0xDCE89C
#define pinstCAltStorageWnd_x                                      0x104A658
#define pinstCAudioTriggersWindow_x                                0xC837A8
#define pinstCAuraWnd_x                                            0xDCF058
#define pinstCAvaZoneWnd_x                                         0xDCE8B8
#define pinstCBandolierWnd_x                                       0xDCF088
#define pinstCBankWnd_x                                            0xDCF054
#define pinstCBarterMerchantWnd_x                                  0x104B898
#define pinstCBarterSearchWnd_x                                    0x104B948
#define pinstCBarterWnd_x                                          0x104B9F8
#define pinstCBazaarConfirmationWnd_x                              0xDCF0D0
#define pinstCBazaarSearchWnd_x                                    0xDCE840
#define pinstCBazaarWnd_x                                          0xDCE920
#define pinstCBlockedBuffWnd_x                                     0xDCF05C
#define pinstCBlockedPetBuffWnd_x                                  0xDCF07C
#define pinstCBodyTintWnd_x                                        0xDCE894
#define pinstCBookWnd_x                                            0xDCF0B4
#define pinstCBreathWnd_x                                          0xDCE8D8
#define pinstCBuffWindowNORMAL_x                                   0xDCF044
#define pinstCBuffWindowSHORT_x                                    0xDCF048
#define pinstCBugReportWnd_x                                       0xDCF050
#define pinstCButtonWnd_x                                          0x16CC790
#define pinstCCastingWnd_x                                         0xDCF0A0
#define pinstCCastSpellWnd_x                                       0xDCE8D4
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDCE92C
#define pinstCChatWindowManager_x                                  0x104C4B8
#define pinstCClaimWnd_x                                           0x104C610
#define pinstCColorPickerWnd_x                                     0xDCE88C
#define pinstCCombatAbilityWnd_x                                   0xDCE958
#define pinstCCombatSkillsSelectWnd_x                              0xDCEB74
#define pinstCCompassWnd_x                                         0xDCE884
#define pinstCConfirmationDialog_x                                 0x1051510
#define pinstCContainerMgr_x                                       0xDCE924
#define pinstCContextMenuManager_x                                 0x16CC4E0
#define pinstCCursorAttachment_x                                   0xDCF094
#define pinstCDynamicZoneWnd_x                                     0x104CBD8
#define pinstCEditLabelWnd_x                                       0xDCF040
#define pinstCEQMainWnd_x                                          0x104CE20
#define pinstCEventCalendarWnd_x                                   0xDCF014
#define pinstCExtendedTargetWnd_x                                  0xDCF074
#define pinstCFacePick_x                                           0xDCEBF4
#define pinstCFactionWnd_x                                         0xDCE90C
#define pinstCFellowshipWnd_x                                      0x104D020
#define pinstCFileSelectionWnd_x                                   0xDCF09C
#define pinstCFindItemWnd_x                                        0xDCE8F4
#define pinstCFindLocationWnd_x                                    0x104D178
#define pinstCFriendsWnd_x                                         0xDCEFFC
#define pinstCGemsGameWnd_x                                        0xDCE904
#define pinstCGiveWnd_x                                            0xDCEB6C
#define pinstCGroupSearchFiltersWnd_x                              0xDCF0AC
#define pinstCGroupSearchWnd_x                                     0x104D570
#define pinstCGroupWnd_x                                           0x104D620
#define pinstCGuildBankWnd_x                                       0xE91F4C
#define pinstCGuildCreationWnd_x                                   0x104D780
#define pinstCGuildMgmtWnd_x                                       0x104D830
#define pinstCharacterCreation_x                                   0xDCEB84
#define pinstCHelpWnd_x                                            0xDCF028
#define pinstCHeritageSelectionWnd_x                               0xDCF004
#define pinstCHotButtonWnd_x                                       0x104F988
#define pinstCHotButtonWnd1_x                                      0x104F988
#define pinstCHotButtonWnd2_x                                      0x104F98C
#define pinstCHotButtonWnd3_x                                      0x104F990
#define pinstCHotButtonWnd4_x                                      0x104F994
#define pinstCIconSelectionWnd_x                                   0xDCF08C
#define pinstCInspectWnd_x                                         0xDCF024
#define pinstCInventoryWnd_x                                       0xDCF008
#define pinstCInvSlotMgr_x                                         0xDCE8BC
#define pinstCItemDisplayManager_x                                 0x104FF18
#define pinstCItemExpTransferWnd_x                                 0x105004C
#define pinstCItemOverflowWnd_x                                    0xDCE844
#define pinstCJournalCatWnd_x                                      0xDCF0BC
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDCF070
#define pinstCKeyRingWnd_x                                         0xDCF03C
#define pinstCLargeDialogWnd_x                                     0x1052190
#define pinstCLayoutCopyWnd_x                                      0x1050398
#define pinstCLFGuildWnd_x                                         0x1050448
#define pinstCLoadskinWnd_x                                        0xDCE91C
#define pinstCLootFiltersCopyWnd_x                                 0xC9FA70
#define pinstCLootFiltersWnd_x                                     0xDCE888
#define pinstCLootSettingsWnd_x                                    0xDCE8B0
#define pinstCLootWnd_x                                            0xDCF0C0
#define pinstCMailAddressBookWnd_x                                 0xDCE8C4
#define pinstCMailCompositionWnd_x                                 0xDCE8AC
#define pinstCMailIgnoreListWnd_x                                  0xDCE8C8
#define pinstCMailWnd_x                                            0xDCE870
#define pinstCManageLootWnd_x                                      0xDCFF28
#define pinstCMapToolbarWnd_x                                      0xDCF02C
#define pinstCMapViewWnd_x                                         0xDCF018
#define pinstCMarketplaceWnd_x                                     0xDCE890
#define pinstCMerchantWnd_x                                        0xDCF0C8
#define pinstCMIZoneSelectWnd_x                                    0x1050C80
#define pinstCMusicPlayerWnd_x                                     0xDCF0CC
#define pinstCNameChangeMercWnd_x                                  0xDCF0C4
#define pinstCNameChangePetWnd_x                                   0xDCF0A8
#define pinstCNameChangeWnd_x                                      0xDCF0D4
#define pinstCNoteWnd_x                                            0xDCF01C
#define pinstCObjectPreviewWnd_x                                   0xDCE8A8
#define pinstCOptionsWnd_x                                         0xDCF020
#define pinstCPetInfoWnd_x                                         0xDCE84C
#define pinstCPetitionQWnd_x                                       0xDCF084
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDCE898
#define pinstCPlayerWnd_x                                          0xDCE850
#define pinstCPopupWndManager_x                                    0x1051510
#define pinstCProgressionSelectionWnd_x                            0x10515C0
#define pinstCPurchaseGroupWnd_x                                   0xDCE8E0
#define pinstCPurchaseWnd_x                                        0xDCE8D0
#define pinstCPvPLeaderboardWnd_x                                  0x1051670
#define pinstCPvPStatsWnd_x                                        0x1051720
#define pinstCQuantityWnd_x                                        0xDCF078
#define pinstCRaceChangeWnd_x                                      0xDCE858
#define pinstCRaidOptionsWnd_x                                     0xDCF0B0
#define pinstCRaidWnd_x                                            0xDCE8B4
#define pinstCRealEstateItemsWnd_x                                 0xDCF098
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDCF034
#define pinstCRealEstateManageWnd_x                                0xDCE8F8
#define pinstCRealEstateNeighborhoodWnd_x                          0xDCE918
#define pinstCRealEstatePlotSearchWnd_x                            0xDCEB68
#define pinstCRealEstatePurchaseWnd_x                              0xDCEB8C
#define pinstCRespawnWnd_x                                         0xDCF068
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDCE8CC
#define pinstCSendMoneyWnd_x                                       0xDCEB70
#define pinstCServerListWnd_x                                      0xDCF00C
#define pinstCSkillsSelectWnd_x                                    0xDCE93C
#define pinstCSkillsWnd_x                                          0xDCE900
#define pinstCSocialEditWnd_x                                      0xDCF038
#define pinstCSocialWnd_x                                          0xDCF0B8
#define pinstCSpellBookWnd_x                                       0xDCE938
#define pinstCStoryWnd_x                                           0xDCE854
#define pinstCTargetOfTargetWnd_x                                  0x1053548
#define pinstCTargetWnd_x                                          0xDCF064
#define pinstCTaskOverlayWnd_x                                     0xDCE8DC
#define pinstCTaskSelectWnd_x                                      0x10536A0
#define pinstCTaskManager_x                                        0xCA03C0
#define pinstCTaskTemplateSelectWnd_x                              0x1053750
#define pinstCTaskWnd_x                                            0x1053800
#define pinstCTextEntryWnd_x                                       0xDCF04C
#define pinstCTimeLeftWnd_x                                        0xDCF060
#define pinstCTipWndCONTEXT_x                                      0x1053A04
#define pinstCTipWndOFDAY_x                                        0x1053A00
#define pinstCTitleWnd_x                                           0x1053AB0
#define pinstCTrackingWnd_x                                        0xDCF010
#define pinstCTradeskillWnd_x                                      0x1053C18
#define pinstCTradeWnd_x                                           0xDCE8A4
#define pinstCTrainWnd_x                                           0xDCE8A0
#define pinstCTributeBenefitWnd_x                                  0x1053E18
#define pinstCTributeMasterWnd_x                                   0x1053EC8
#define pinstCTributeTrophyWnd_x                                   0x1053F78
#define pinstCVideoModesWnd_x                                      0xDCE95C
#define pinstCVoiceMacroWnd_x                                      0xF34C50
#define pinstCVoteResultsWnd_x                                     0xDCF080
#define pinstCVoteWnd_x                                            0xDCF06C
#define pinstCWebManager_x                                         0xF352CC
#define pinstCZoneGuideWnd_x                                       0xDCE8E4
#define pinstCZonePathWnd_x                                        0xDCE908

#define pinstEQSuiteTextureLoader_x                                0xC6E598
#define pinstItemIconCache_x                                       0x104CDD8
#define pinstLootFiltersManager_x                                  0xC9FB20
#define pinstRewardSelectionWnd_x                                  0x1051E68

////
// Section 3: Miscellaneous Offsets
////
#define __AppCrashWrapper_x                                        0xC1EE98
#define __CastRay_x                                                0x59C9C0
#define __CastRay2_x                                               0x59CA10
#define __ConvertItemTags_x                                        0x5B8560
#define __CleanItemTags_x                                          0x4777C0
#define __CrashHandler_x                                           0x84F2B0
#define __DoesFileExist_x                                          0x8F1680
#define __EQGetTime_x                                              0x8EE0E0
#define __ExecuteCmd_x                                             0x595390
#define __FixHeading_x                                             0x988890
#define __GameLoop_x                                               0x6A9250
#define __get_bearing_x                                            0x59C530
#define __get_melee_range_x                                        0x59CC00
#define __GetAnimationCache_x                                      0x70E350
#define __GetGaugeValueFromEQ_x                                    0x800A40
#define __GetLabelFromEQ_x                                         0x802520
#define __GetXTargetType_x                                         0x98A2E0
#define __HandleMouseWheel_x                                       0x6A9E40
#define __HeadingDiff_x                                            0x988900
#define __HelpPath_x                                               0xF2FFFC
#define __LoadFrontEnd_x                                           0x6A5D20
#define __NewUIINI_x                                               0x800710
#define __pCrashHandler_x                                          0x1071378
#define __ProcessGameEvents_x                                      0x5FC6D0
#define __ProcessMouseEvent_x                                      0x5FBE90
#define __SaveColors_x                                             0x546270
#define __STMLToText_x                                             0x92BDC0
#define __ToggleKeyRingItem_x                                      0x507FB0
#define CMemoryMappedFile__SetFile_x                               0xA62AD0
#define CrashDetected_x                                            0x6A77A0
#define DrawNetStatus_x                                            0x628670
#define Expansion_HoT_x                                            0xE91F54
#define Teleport_Table_Size_x                                      0xE8132C
#define Teleport_Table_x                                           0xE81788
#define Util__FastTime_x                                           0x8EDCB0
#define wwsCrashReportCheckForUploader_x                           0x850070
#define wwsCrashReportPlatformLaunchUploader_x                     0x852750
#define __eq_delete_x                                              0x990D3E
#define __eq_new_x                                                 0x991304

////
// Section 4: Function Offsets
////
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48AA90
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4939A0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x493770
#define CAdvancedLootWnd__AddPlayerToList_x                        0x48E030
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x48D480

// AltAdvManager
#define AltAdvManager__GetCalculatedTimer_x                        0x54DCB0
#define AltAdvManager__IsAbilityReady_x                            0x54CC30
#define AltAdvManager__GetAAById_x                                 0x54CE30
#define AltAdvManager__CanTrainAbility_x                           0x54CEA0
#define AltAdvManager__CanSeeAbility_x                             0x54D200

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C6820
#define CharacterZoneClient__HasSkill_x                            0x4D1710
#define CharacterZoneClient__MakeMeVisible_x                       0x4D2E30
#define CharacterZoneClient__IsStackBlocked_x                      0x4BACA0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B72A0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D57E0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D58C0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D59A0
#define CharacterZoneClient__FindAffectSlot_x                      0x4BF950
#define CharacterZoneClient__BardCastBard_x                        0x4C24B0
#define CharacterZoneClient__GetMaxEffects_x                       0x4B7370
#define CharacterZoneClient__GetEffect_x                           0x4B71E0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C09A0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C0A70
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C0AC0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C0C10
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C0DE0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4AF180
#define CharacterZoneClient__FindItemByGuid_x                      0x4D3D90
#define CharacterZoneClient__FindItemByRecord_x                    0x4D3810

// CBankWnd
#define CBankWnd__GetNumBankSlots_x                                0x6CFB80
#define CBankWnd__WndNotification_x                                0x6CF960

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6DD470

// CButtonWnd
#define CButtonWnd__SetCheck_x                                     0x60AFE0
#define CButtonWnd__CButtonWnd_x                                   0x928190
#define CButtonWnd__dCButtonWnd_x                                  0x928470
#define CButtonWnd__vftable_x                                      0xB187A4

// CChatWindowManager
#define CChatWindowManager__GetRGBAFromIndex_x                     0x6FD500
#define CChatWindowManager__InitContextMenu_x                      0x6F6690
#define CChatWindowManager__FreeChatWindow_x                       0x6FC020
#define CChatWindowManager__GetLockedActiveChatWindow_x            0x4E4EA0
#define CChatWindowManager__SetLockedActiveChatWindow_x            0x6FD180
#define CChatWindowManager__CreateChatWindow_x                     0x6FC660

// ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E4FB0

// CChatWindow
#define CChatWindow__CChatWindow_x                                 0x6FDD70
#define CChatWindow__Clear_x                                       0x6FF030
#define CChatWindow__WndNotification_x                             0x6FF7C0
#define CChatWindow__AddHistory_x                                  0x6FE8F0

// CContextMenu
#define CContextMenu__CContextMenu_x                               0x93C840
#define CContextMenu__dCContextMenu_x                              0x93CA70
#define CContextMenu__AddMenuItem_x                                0x93CA80
#define CContextMenu__RemoveMenuItem_x                             0x93CD90
#define CContextMenu__RemoveAllMenuItems_x                         0x93CDB0
#define CContextMenu__CheckMenuItem_x                              0x93CE30
#define CContextMenu__SetMenuItem_x                                0x93CCB0
#define CContextMenu__AddSeparator_x                               0x93CC10

// CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x93D3D0
#define CContextMenuManager__RemoveMenu_x                          0x93D440
#define CContextMenuManager__PopupMenu_x                           0x93D500
#define CContextMenuManager__Flush_x                               0x93D370
#define CContextMenuManager__GetMenu_x                             0x495B90
#define CContextMenuManager__CreateDefaultMenu_x                   0x708B70

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8CEBE0
#define CChatService__GetFriendName_x                              0x8CEBF0

// CComboWnd
#define CComboWnd__DeleteAll_x                                     0x939C90
#define CComboWnd__Draw_x                                          0x939190
#define CComboWnd__GetCurChoice_x                                  0x939AD0
#define CComboWnd__GetListRect_x                                   0x939640
#define CComboWnd__GetTextRect_x                                   0x939D00
#define CComboWnd__InsertChoice_x                                  0x9397D0
#define CComboWnd__SetColors_x                                     0x9397A0
#define CComboWnd__SetChoice_x                                     0x939AA0
#define CComboWnd__GetItemCount_x                                  0x939AE0
#define CComboWnd__GetCurChoiceText_x                              0x939B20
#define CComboWnd__GetChoiceText_x                                 0x939AF0
#define CComboWnd__InsertChoiceAtIndex_x                           0x939860

// CContainerWnd
#define CContainerWnd__HandleCombine_x                             0x706550
#define CContainerWnd__vftable_x                                   0xAE661C
#define CContainerWnd__SetContainer_x                              0x707AC0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x540D10
#define CDisplay__PreZoneMainUI_x                                  0x540D20
#define CDisplay__CleanGameUI_x                                    0x546030
#define CDisplay__GetClickedActor_x                                0x539030
#define CDisplay__GetUserDefinedColor_x                            0x5316F0
#define CDisplay__GetWorldFilePath_x                               0x53AAA0
#define CDisplay__is3dON_x                                         0x535C90
#define CDisplay__ReloadUI_x                                       0x5401A0
#define CDisplay__WriteTextHD2_x                                   0x535A80
#define CDisplay__TrueDistance_x                                   0x53C760
#define CDisplay__SetViewActor_x                                   0x538950
#define CDisplay__GetFloorHeight_x                                 0x535D50
#define CDisplay__SetRenderWindow_x                                0x5346B0
#define CDisplay__ToggleScreenshotMode_x                           0x538420

// CEditBaseWnd
#define CEditBaseWnd__SetSel_x                                     0x95C540

// CEditWnd
#define CEditWnd__DrawCaret_x                                      0x93FD90
#define CEditWnd__GetCharIndexPt_x                                 0x940CB0
#define CEditWnd__GetDisplayString_x                               0x940B60
#define CEditWnd__GetHorzOffset_x                                  0x93F3E0
#define CEditWnd__GetLineForPrintableChar_x                        0x941E20
#define CEditWnd__GetSelStartPt_x                                  0x940F60
#define CEditWnd__GetSTMLSafeText_x                                0x940980
#define CEditWnd__PointFromPrintableChar_x                         0x941A60
#define CEditWnd__SelectableCharFromPoint_x                        0x941BD0
#define CEditWnd__SetEditable_x                                    0x941020
#define CEditWnd__SetWindowTextA_x                                 0x940700

// CEverQuest
#define CEverQuest__DoPercentConvert_x                             0x5EA340
#define CEverQuest__ClickedPlayer_x                                0x5DC470
#define CEverQuest__CreateTargetIndicator_x                        0x5F9960
#define CEverQuest__DeleteTargetIndicator_x                        0x5F99F0
#define CEverQuest__DoTellWindow_x                                 0x4E5090
#define CEverQuest__OutputTextToLog_x                              0x4E5310
#define CEverQuest__DropHeldItemOnGround_x                         0x5D14B0
#define CEverQuest__dsp_chat_x                                     0x4E56A0
#define CEverQuest__trimName_x                                     0x5F5C40
#define CEverQuest__Emote_x                                        0x5EABA0
#define CEverQuest__EnterZone_x                                    0x5E4B20
#define CEverQuest__GetBodyTypeDesc_x                              0x5EF510
#define CEverQuest__GetClassDesc_x                                 0x5EFB50
#define CEverQuest__GetClassThreeLetterCode_x                      0x5F0150
#define CEverQuest__GetDeityDesc_x                                 0x5F82A0
#define CEverQuest__GetLangDesc_x                                  0x5F0310
#define CEverQuest__GetRaceDesc_x                                  0x5EFB30
#define CEverQuest__InterpretCmd_x                                 0x5F8870
#define CEverQuest__LeftClickedOnPlayer_x                          0x5D56B0
#define CEverQuest__LMouseUp_x                                     0x5D3A40
#define CEverQuest__RightClickedOnPlayer_x                         0x5D5F90
#define CEverQuest__RMouseUp_x                                     0x5D49C0
#define CEverQuest__SetGameState_x                                 0x5D1240
#define CEverQuest__UPCNotificationFlush_x                         0x5F5B40
#define CEverQuest__IssuePetCommand_x                              0x5F1700
#define CEverQuest__ReportSuccessfulHit_x                          0x5EBF90

// CGaugeWnd
// not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x718420
#define CGaugeWnd__CalcLinesFillRect_x                             0x718480
#define CGaugeWnd__Draw_x                                          0x717AA0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ABBB0
#define CGuild__GetGuildName_x                                     0x4AAC90
#define CGuild__GetGuildIndex_x                                    0x4AB020

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton_x                               0x7338A0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x60B3A0

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot_x                                 0x740880
#define CInvSlotMgr__MoveItem_x                                    0x73F5B0
#define CInvSlotMgr__SelectSlot_x                                  0x740950

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x73DE60
#define CInvSlot__SliderComplete_x                                 0x73BBE0
#define CInvSlot__GetItemBase_x                                    0x73B550
#define CInvSlot__UpdateItem_x                                     0x73B6C0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7423C0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x741570
#define CInvSlotWnd__HandleLButtonUp_x                             0x741F40

// CItemDisplayWnd
#define CItemDisplayWnd__SetSpell_x                                0x7FBD50
#define CItemDisplayWnd__UpdateStrings_x                           0x7509B0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x74A700
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x74AC10
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x750FB0
#define CItemDisplayWnd__AboutToShow_x                             0x7505F0
#define CItemDisplayWnd__WndNotification_x                         0x7520A0
#define CItemDisplayWnd__RequestConvertItem_x                      0x751B60
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x74F650
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x750410

// CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x834B00

// CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x7565D0

// CLabel
#define CLabel__Draw_x                                             0x75C080

// CListWnd
#define CListWnd__CListWnd_x                                       0x9122E0
#define CListWnd__dCListWnd_x                                      0x9125F0
#define CListWnd__vftable_x                                        0xB180F8
#define CListWnd__AddColumn_x                                      0x916A30
#define CListWnd__AddColumn1_x                                     0x916A80
#define CListWnd__AddLine_x                                        0x916E10
#define CListWnd__AddString_x                                      0x916C10
#define CListWnd__CalculateFirstVisibleLine_x                      0x9167F0
#define CListWnd__CalculateVSBRange_x                              0x9165E0
#define CListWnd__ClearSel_x                                       0x9175F0
#define CListWnd__ClearAllSel_x                                    0x917650
#define CListWnd__CloseAndUpdateEditWindow_x                       0x918070
#define CListWnd__Compare_x                                        0x915F30
#define CListWnd__Draw_x                                           0x912720
#define CListWnd__DrawColumnSeparators_x                           0x914F00
#define CListWnd__DrawHeader_x                                     0x915370
#define CListWnd__DrawItem_x                                       0x915870
#define CListWnd__DrawLine_x                                       0x915070
#define CListWnd__DrawSeparator_x                                  0x914FA0
#define CListWnd__EnableLine_x                                     0x9147D0
#define CListWnd__EnsureVisible_x                                  0x917F90
#define CListWnd__ExtendSel_x                                      0x917520
#define CListWnd__GetColumnTooltip_x                               0x914310
#define CListWnd__GetColumnMinWidth_x                              0x914380
#define CListWnd__GetColumnWidth_x                                 0x914280
#define CListWnd__GetCurSel_x                                      0x913C10
#define CListWnd__GetItemAtPoint_x                                 0x914A50
#define CListWnd__GetItemAtPoint1_x                                0x914AC0
#define CListWnd__GetItemData_x                                    0x913C90
#define CListWnd__GetItemHeight_x                                  0x914050
#define CListWnd__GetItemIcon_x                                    0x913E20
#define CListWnd__GetItemRect_x                                    0x9148C0
#define CListWnd__GetItemText_x                                    0x913CD0
#define CListWnd__GetSelList_x                                     0x9176A0
#define CListWnd__GetSeparatorRect_x                               0x914D00
#define CListWnd__InsertLine_x                                     0x917200
#define CListWnd__RemoveLine_x                                     0x917350
#define CListWnd__SetColors_x                                      0x9165C0
#define CListWnd__SetColumnJustification_x                         0x916300
#define CListWnd__SetColumnWidth_x                                 0x916220
#define CListWnd__SetCurSel_x                                      0x917460
#define CListWnd__SetItemColor_x                                   0x917C40
#define CListWnd__SetItemData_x                                    0x917C00
#define CListWnd__SetItemText_x                                    0x917810
#define CListWnd__ShiftColumnSeparator_x                           0x9163C0
#define CListWnd__Sort_x                                           0x9160B0
#define CListWnd__ToggleSel_x                                      0x917490
#define CListWnd__SetColumnsSizable_x                              0x916460
#define CListWnd__SetItemWnd_x                                     0x917AC0
#define CListWnd__GetItemWnd_x                                     0x913E70
#define CListWnd__SetItemIcon_x                                    0x917890
#define CListWnd__CalculateCustomWindowPositions_x                 0x9168F0
#define CListWnd__SetVScrollPos_x                                  0x916200

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd_x                                 0x7718D0

// MapViewMap
#define MapViewMap__MapViewMap_x                                   0x76CDC0
#define MapViewMap__dMapViewMap_x                                  0x76CF10
#define MapViewMap__vftable_x                                      0xAEDDF0
#define MapViewMap__Clear_x                                        0x76D740
#define MapViewMap__SaveEx_x                                       0x770B00
#define MapViewMap__SetZoom_x                                      0x7751C0
#define MapViewMap__HandleLButtonDown_x                            0x76D020
#define MapViewMap__GetWorldCoordinates_x                          0x76FFE0

// CMerchantWnd
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7918F0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7921D0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x792700
#define CMerchantWnd__SelectRecoverySlot_x                         0x795690
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x790460
#define CMerchantWnd__SelectBuySellSlot_x                          0x79B240
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x791510

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89C860
#define CPacketScrambler__hton_x                                   0x89C850

// CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x9357D0
#define CSidlManagerBase__CreatePageWnd_x                          0x934FD0
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x931250
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x9311E0
#define CSidlManagerBase__FindAnimation1_x                         0x931430
#define CSidlManagerBase__FindScreenPieceTemplate_x                0x931840
#define CSidlManagerBase__FindScreenPieceTemplate1_x               0x931630
#define CSidlManagerBase__CreateLabel_x                            0x7F3110
#define CSidlManagerBase__CreateXWndFromTemplate_x                 0x9347A0
#define CSidlManagerBase__CreateXWndFromTemplate1_x                0x934980
#define CSidlManagerBase__CreateXWnd_x                             0x7F3040

// CSidlManager
#define CSidlManager__CreateHotButtonWnd_x                         0x7F3610

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateHSBRange_x                        0x92DEF0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x92DDF0
#define CSidlScreenWnd__ConvertToRes_x                             0x953530
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x92D880
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x92D570
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x92D640
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x92D710
#define CSidlScreenWnd__DrawSidlPiece_x                            0x92E390
#define CSidlScreenWnd__EnableIniStorage_x                         0x92E860
#define CSidlScreenWnd__GetChildItem_x                             0x92E7E0
#define CSidlScreenWnd__GetSidlPiece_x                             0x92E580
#define CSidlScreenWnd__HandleLButtonUp_x                          0x91DEF0
#define CSidlScreenWnd__Init1_x                                    0x92D170
#define CSidlScreenWnd__LoadIniInfo_x                              0x92E8B0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x92F410
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92C570
#define CSidlScreenWnd__m_layoutCopy_x                             0x16CC3B0
#define CSidlScreenWnd__StoreIniInfo_x                             0x92EF80
#define CSidlScreenWnd__StoreIniVis_x                              0x92F2F0
#define CSidlScreenWnd__vftable_x                                  0xB18A40
#define CSidlScreenWnd__WndNotification_x                          0x92E2A0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x66FC40
#define CSkillMgr__GetSkillCap_x                                   0x66FE20
#define CSkillMgr__GetNameToken_x                                  0x66F3C0
#define CSkillMgr__IsActivatedSkill_x                              0x66F500
#define CSkillMgr__IsCombatSkill_x                                 0x66F440

// CSliderWnd
#define CSliderWnd__GetValue_x                                     0x93E1C0
#define CSliderWnd__SetValue_x                                     0x93E030
#define CSliderWnd__SetNumTicks_x                                  0x93E090

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet_x                               0x7F91D0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x946980
#define CStmlWnd__CalculateHSBRange_x                              0x947AB0
#define CStmlWnd__CalculateVSBRange_x                              0x947A20
#define CStmlWnd__CanBreakAtCharacter_x                            0x94BDE0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x94CA70
#define CStmlWnd__ForceParseNow_x                                  0x946F70
#define CStmlWnd__GetNextTagPiece_x                                0x94BD40
#define CStmlWnd__GetSTMLText_x                                    0x4F79C0
#define CStmlWnd__GetVisibleText_x                                 0x946F90
#define CStmlWnd__InitializeWindowVariables_x                      0x94C8C0
#define CStmlWnd__MakeStmlColorTag_x                               0x945FF0
#define CStmlWnd__MakeWndNotificationTag_x                         0x946060
#define CStmlWnd__SetSTMLText_x                                    0x9450A0
#define CStmlWnd__StripFirstSTMLLines_x                            0x94DB70
#define CStmlWnd__UpdateHistoryString_x                            0x94CC80

// CTabWnd
#define CTabWnd__Draw_x                                            0x9441F0
#define CTabWnd__DrawCurrentPage_x                                 0x944920
#define CTabWnd__DrawTab_x                                         0x944640
#define CTabWnd__GetCurrentPage_x                                  0x9439F0
#define CTabWnd__GetPageInnerRect_x                                0x943C30
#define CTabWnd__GetTabInnerRect_x                                 0x943B70
#define CTabWnd__GetTabRect_x                                      0x943A20
#define CTabWnd__InsertPage_x                                      0x943E40
#define CTabWnd__SetPage_x                                         0x943CB0
#define CTabWnd__SetPageRect_x                                     0x944130
#define CTabWnd__UpdatePage_x                                      0x944500
#define CTabWnd__GetPageFromTabIndex_x                             0x944580
#define CTabWnd__GetCurrentTabIndex_x                              0x9439E0

// CPageWnd
#define CPageWnd__GetTabText_x                                     0x756A10
#define CPageWnd__SetTabText_x                                     0x943530

// CTextOverlay
#define CTextOverlay__DisplayText_x                                0x4A57E0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91AD90
#define CTextureFont__GetTextExtent_x                              0x91AF50

// CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6A2C20
#define CHtmlComponentWnd__ValidateUri_x                           0x735290
#define CHtmlWnd__SetClientCallbacks_x                             0x610420
#define CHtmlWnd__AddObserver_x                                    0x610440
#define CHtmlWnd__RemoveObserver_x                                 0x6104A0
#define Window__getProgress_x                                      0x84CFC0
#define Window__getStatus_x                                        0x84CFE0
#define Window__getURI_x                                           0x84CFF0

// CXMLDataManager
#define CXMLDataManager__GetXMLData_x                              0x958FD0

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead_x                             0x907D50

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr_x                                             0x4E4CE0
#define CXStr__CXStr1_x                                            0x4B2BE0
#define CXStr__CXStr3_x                                            0x8EA220
#define CXStr__dCXStr_x                                            0x472EE0
#define CXStr__operator_equal_x                                    0x8EA450
#define CXStr__operator_equal1_x                                   0x8EA490
#define CXStr__operator_plus_equal1_x                              0x8EAF20
#define CXStr__SetString_x                                         0x8ECE10
#define CXStr__operator_char_p_x                                   0x8EA990
#define CXStr__GetChar_x                                           0x8EC740
#define CXStr__Delete_x                                            0x8EC010
#define CXStr__GetUnicode_x                                        0x8EC7B0
#define CXStr__GetLength_x                                         0x477B70
#define CXStr__Mid_x                                               0x477B80
#define CXStr__Insert_x                                            0x8EC810
#define CXStr__FindNext_x                                          0x8EC480
#define CXStr__gFreeLists_x                                        0xC6C9D8
#define CXStr__gCXStrAccess_x                                      0x16CBACC

// CTileLayoutWnd
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93C450

// CXWnd
#define CXWnd__BringToTop_x                                        0x9216A0
#define CXWnd__Center_x                                            0x921220
#define CXWnd__ClrFocus_x                                          0x921030
#define CXWnd__Destroy_x                                           0x9210E0
#define CXWnd__DoAllDrawing_x                                      0x91D680
#define CXWnd__DrawChildren_x                                      0x91D650
#define CXWnd__DrawColoredRect_x                                   0x91DAE0
#define CXWnd__DrawTooltip_x                                       0x91C1B0
#define CXWnd__DrawTooltipAtPoint_x                                0x91C270
#define CXWnd__GetBorderFrame_x                                    0x91D940
#define CXWnd__GetChildItem_x                                      0x9218B0
#define CXWnd__GetChildWndAt_x                                     0x921740
#define CXWnd__GetClientClipRect_x                                 0x91F950
#define CXWnd__GetScreenClipRect_x                                 0x91FA00
#define CXWnd__GetScreenRect_x                                     0x91FBB0
#define CXWnd__GetTooltipRect_x                                    0x91DB30
#define CXWnd__GetWindowTextA_x                                    0x497270
#define CXWnd__IsActive_x                                          0x91E270
#define CXWnd__IsDescendantOf_x                                    0x920590
#define CXWnd__IsReallyVisible_x                                   0x9205C0
#define CXWnd__IsType_x                                            0x921DB0
#define CXWnd__Minimize_x                                          0x920CC0
#define CXWnd__Move_x                                              0x920630
#define CXWnd__Move1_x                                             0x9206F0
#define CXWnd__ProcessTransition_x                                 0x9211D0
#define CXWnd__Refade_x                                            0x9209C0
#define CXWnd__Resize_x                                            0x920C50
#define CXWnd__Right_x                                             0x921460
#define CXWnd__SetFocus_x                                          0x920FF0
#define CXWnd__SetFont_x                                           0x921060
#define CXWnd__SetKeyTooltip_x                                     0x921BC0
#define CXWnd__SetMouseOver_x                                      0x91EAA0
#define CXWnd__SetParent_x                                         0x920360
#define CXWnd__StartFade_x                                         0x920470
#define CXWnd__vftable_x                                           0xB18544
#define CXWnd__CXWnd_x                                             0x91B270
#define CXWnd__dCXWnd_x                                            0x91B7A0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x9545B0

// CXWndManager
#define CXWndManager__DrawCursor_x                                 0x9245E0
#define CXWndManager__DrawWindows_x                                0x924600
#define CXWndManager__GetKeyboardFlags_x                           0x926DF0
#define CXWndManager__HandleKeyboardMsg_x                          0x9269A0
#define CXWndManager__RemoveWnd_x                                  0x927030
#define CXWndManager__RemovePendingDeletionWnd_x                   0x927560

// CDBStr
#define CDBStr__GetString_x                                        0x530680

// CharacterZoneClient
#define CharacterZoneClient__CastSpell_x                           0x4B8280
#define CharacterZoneClient__Cur_HP_x                              0x4CE750
#define CharacterZoneClient__Cur_Mana_x                            0x4D5EA0
#define CharacterZoneClient__GetCastingTimeModifier_x              0x4BB2F0
#define CharacterZoneClient__GetFocusCastingTimeModifier_x         0x4AEDC0
#define CharacterZoneClient__GetFocusRangeModifier_x               0x4AEF10
#define CharacterZoneClient__GetHPRegen_x                          0x4DBC70
#define CharacterZoneClient__GetEnduranceRegen_x                   0x4DC270
#define CharacterZoneClient__GetManaRegen_x                        0x4DC6B0
#define CharacterZoneClient__Max_Endurance_x                       0x636870
#define CharacterZoneClient__Max_HP_x                              0x4CE580
#define CharacterZoneClient__Max_Mana_x                            0x636670
#define CharacterZoneClient__doCombatAbility_x                     0x638CC0
#define CharacterZoneClient__UseSkill_x                            0x4DE490
#define CharacterZoneClient__IsExpansionFlag_x                     0x593B50
#define CharacterZoneClient__TotalEffect_x                         0x4C1BF0
#define CharacterZoneClient__GetPCSpellAffect_x                    0x4BBF00
#define CharacterZoneClient__SpellDuration_x                       0x4BBA30
#define CharacterZoneClient__GetAdjustedSkill_x                    0x4D14D0
#define CharacterZoneClient__GetBaseSkill_x                        0x4D2470
#define CharacterZoneClient__CanUseItem_x                          0x4D61B0

// ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BBA60

// PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x64CD90

// PcClient
#define PcClient__PcClient_x                                       0x62CD30
#define PcClient__GetConLevel_x                                    0x62F600

// CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B5EF0
#define CCharacterListWnd__EnterWorld_x                            0x4B5930
#define CCharacterListWnd__Quit_x                                  0x4B5680
#define CCharacterListWnd__UpdateList_x                            0x4B5AC0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x611670
#define EQ_Item__CreateItemTagString_x                             0x896080
#define EQ_Item__IsStackable_x                                     0x89ABE0
#define EQ_Item__GetImageNum_x                                     0x897B40
#define EQ_Item__CreateItemClient_x                                0x610840
#define EQ_Item__GetItemValue_x                                    0x898E30
#define EQ_Item__ValueSellMerchant_x                               0x89C430
#define EQ_Item__IsKeyRingItem_x                                   0x89A530
#define EQ_Item__CanGoInBag_x                                      0x611790
#define EQ_Item__IsEmpty_x                                         0x89A080
#define EQ_Item__GetMaxItemCount_x                                 0x899250
#define EQ_Item__GetHeldItem_x                                     0x897A10
#define EQ_Item__GetAugmentFitBySlot_x                             0x8959F0

// EQ_LoadingS
#define EQ_LoadingS__SetProgressBar_x                              0x54E9C0
#define EQ_LoadingS__Array_x                                       0xBF6688

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x6371C0
#define EQ_PC__GetAlternateAbilityId_x                             0x8A5660
#define EQ_PC__GetCombatAbility_x                                  0x8A5CD0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A5D40
#define EQ_PC__GetItemRecastTimer_x                                0x639240
#define EQ_PC__HasLoreItem_x                                       0x62FE10
#define EQ_PC__AlertInventoryChanged_x                             0x62EF30
#define EQ_PC__GetPcZoneClient_x                                   0x65B820
#define EQ_PC__RemoveMyAffect_x                                    0x63C480
#define EQ_PC__GetKeyRingItems_x                                   0x8A65A0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A6360
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A6890

// EQItemList
#define EQItemList__EQItemList_x                                   0x59A040
#define EQItemList__add_object_x                                   0x5C6D50
#define EQItemList__add_item_x                                     0x59A5A0
#define EQItemList__delete_item_x                                  0x59A5F0
#define EQItemList__FreeItemList_x                                 0x59A4F0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x52D180

// EQPlayer
#define EQPlayer__ChangeBoneStringSprite_x                         0x64E610
#define EQPlayer__dEQPlayer_x                                      0x641950
#define EQPlayer__DoAttack_x                                       0x6564E0
#define EQPlayer__EQPlayer_x                                       0x642010
#define EQPlayer__SetNameSpriteState_x                             0x6462F0
#define EQPlayer__SetNameSpriteTint_x                              0x6471C0
#define PlayerBase__HasProperty_j_x                                0x986C70
#define EQPlayer__IsTargetable_x                                   0x987110
#define EQPlayer__CanSee_x                                         0x986F70
#define EQPlayer__CanSee1_x                                        0x987040
#define PlayerBase__GetVisibilityLineSegment_x                     0x986D30

// PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x6592B0
#define PlayerZoneClient__GetLevel_x                               0x65B860
#define PlayerZoneClient__IsValidTeleport_x                        0x5C7EC0
#define PlayerZoneClient__LegalPlayerRace_x                        0x547E60

// EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x6513F0
#define EQPlayerManager__GetSpawnByName_x                          0x6514A0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x651530

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x614D80
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x614E00
#define KeypressHandler__AttachKeyToEqCommand_x                    0x614E40
#define KeypressHandler__ClearCommandStateArray_x                  0x616250
#define KeypressHandler__HandleKeyDown_x                           0x616270
#define KeypressHandler__HandleKeyUp_x                             0x616310
#define KeypressHandler__SaveKeymapping_x                          0x616750

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B9980

// StringTable
#define StringTable__getString_x                                   0x8B4830

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x63C0F0
#define PcZoneClient__RemovePetEffect_x                            0x63C720
#define PcZoneClient__HasAlternateAbility_x                        0x6364A0
#define PcZoneClient__GetCurrentMod_x                              0x4E1550
#define PcZoneClient__GetModCap_x                                  0x4E1450
#define PcZoneClient__CanEquipItem_x                               0x636B60
#define PcZoneClient__GetItemByID_x                                0x6396C0
#define PcZoneClient__GetItemByItemClass_x                         0x639810
#define PcZoneClient__RemoveBuffEffect_x                           0x63C740
#define PcZoneClient__BandolierSwap_x                              0x637780
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x6391E0

// Doors
#define EQSwitch__UseSwitch_x                                      0x5CC9D0

// IconCache
#define IconCache__GetIcon_x                                       0x70DBF0

// CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x7056F0
#define CContainerMgr__CloseContainer_x                            0x7059C0
#define CContainerMgr__OpenExperimentContainer_x                   0x706440

// CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7C5830

// CHelpWnd
#define CHelpWnd__SetFile_x                                        0x6097C0

// CLootWnd
#define CLootWnd__LootAll_x                                        0x763B70
#define CLootWnd__RequestLootSlot_x                                0x762DA0

// EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x566E90
#define EQ_Spell__SpellAffects_x                                   0x567300
#define EQ_Spell__SpellAffectBase_x                                0x5670C0
#define EQ_Spell__IsStackable_x                                    0x4C61A0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C5FF0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B32A0
#define EQ_Spell__IsSPAStacking_x                                  0x568150
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x567660
#define EQ_Spell__IsNoRemove_x                                     0x4C6180
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x568160
#define __IsResEffectSpell_x                                       0x4C5590

// EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4A98F0

// EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C4080

// CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x80C520
#define CTargetWnd__WndNotification_x                              0x80BDB0
#define CTargetWnd__RefreshTargetBuffs_x                           0x80C080
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x80AF20

// CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x810B20

// CTaskManager
#define CTaskManager__GetEntry_x                                   0x52ABC0
#define CTaskManager__HandleMessage_x                              0x529060
#define CTaskManager__GetTaskStatus_x                              0x52AC70
#define CTaskManager__GetElementDescription_x                      0x52ACF0

// EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x562400
#define EqSoundManager__PlayScriptMp3_x                            0x562560
#define EqSoundManager__SoundAssistPlay_x                          0x673BE0
#define EqSoundManager__WaveInstancePlay_x                         0x673150

// CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x51E9C0

// CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x942A40

// CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x556380
#define CAltAbilityData__GetMercMaxRank_x                          0x556310
#define CAltAbilityData__GetMaxRank_x                              0x54BAF0

// CTargetRing
#define CTargetRing__Cast_x                                        0x6078E0

// CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C5FD0
#define CharacterBase__CreateItemGlobalIndex_x                     0x504810
#define CharacterBase__CreateItemIndex_x                           0x60F9D0
#define CharacterBase__GetItemPossession_x                         0x4F02D0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CC680
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CC6E0

// CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6EC920
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6ED150
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6ED200

// messages
#define msg_spell_worn_off_x                                       0x58BDF0
#define msg_new_text_x                                             0x580BB0
#define __msgTokenTextParam_x                                      0x58E320
#define msgTokenText_x                                             0x58E570

// SpellManager
#define SpellManager__vftable_x                                    0xAC0C14
#define SpellManager__SpellManager_x                               0x676F00
#define Spellmanager__LoadTextSpells_x                             0x6777F0
#define SpellManager__GetSpellByGroupAndRank_x                     0x6770D0

// CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x 0x98ABD0

// ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C4A20
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C4CA0

// CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x75C3C0

// CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x709E10
#define CCursorAttachment__AttachToCursor1_x                       0x709E50
#define CCursorAttachment__Deactivate_x                            0x70AE20

// CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x952740
#define CEQSuiteTextureLoader__GetTexture_x                        0x952400

// CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x501D80
#define CFindItemWnd__WndNotification_x                            0x502860
#define CFindItemWnd__Update_x                                     0x5033D0
#define CFindItemWnd__PickupSelectedItem_x                         0x5015F0

// IString
#define IString__Append_x                                          0x4F1AA0

// Camera
#define CDisplay__cameraType_x                                     0xDCE94C
#define EverQuest__Cameras_x                                       0xE9229C

// LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x50A270
#define LootFiltersManager__GetItemFilterData_x                    0x509B80
#define LootFiltersManager__RemoveItemLootFilter_x                 0x509BB0
#define LootFiltersManager__SetItemLootFilter_x                    0x509DD0

// COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B3830

// CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9907B0
#define CResolutionHandler__GetWindowedStyle_x                     0x66E800

// CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x7024D0

// CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D73F0
#define CDistillerInfo__Instance_x                                 0x8D7390

// CGroupWnd
#define CGroupWnd__WndNotification_x                               0x722630
#define CGroupWnd__UpdateDisplay_x                                 0x721990

// ItemBase
#define ItemBase__IsLore_x                                         0x89A590
#define ItemBase__IsLoreEquipped_x                                 0x89A610

// EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5C6CB0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5C6DF0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5C6E50

// RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x663F50
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x6678D0

// CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x4F8210

// FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4E6A20
#define FactionManagerClient__HandleFactionMessage_x               0x4E7090
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4E7650
#define FactionManagerClient__GetMaxFaction_x                      0x4E766F
#define FactionManagerClient__GetMinFaction_x                      0x4E7620

// BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4F02A0

// ArrayClass
#define ArrayClass__DeleteElement_x                                0x919D10

// AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x496580

// ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4F04D0

// MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x555840

// CTargetManager
#define CTargetManager__Get_x                                      0x67A760

// RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x663F50

// CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A55A0

// EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x59A490

// EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF2F92C
