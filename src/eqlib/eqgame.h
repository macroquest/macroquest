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
#define __ExpectedVersionDate                                     "Aug 15 2019"
#define __ExpectedVersionTime                                     "14:36:17"
#define __ActualVersionDate_x                                      0xAE653C
#define __ActualVersionTime_x                                      0xAE6530
#define __ActualVersionBuild_x                                     0xAE6FD4

// Memory Protection
#define __MemChecker0_x                                            0x61BFA0
#define __MemChecker1_x                                            0x8F4140
#define __MemChecker2_x                                            0x6ABD90
#define __MemChecker3_x                                            0x6ABCE0
#define __MemChecker4_x                                            0x84AD20
#define __EncryptPad0_x                                            0xC1C990
#define __EncryptPad1_x                                            0xC7A9B8
#define __EncryptPad2_x                                            0xC2D208
#define __EncryptPad3_x                                            0xC2CE08
#define __EncryptPad4_x                                            0xC6B180
#define __EncryptPad5_x                                            0x104E718
#define __AC1_x                                                    0x807A06
#define __AC2_x                                                    0x5D5B5F
#define __AC3_x                                                    0x5DD26F
#define __AC4_x                                                    0x5E1150
#define __AC5_x                                                    0x5E74A0
#define __AC6_x                                                    0x5EBA66
#define __AC7_x                                                    0x5D55D0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1E9B25C

// Direct Input
#define DI8__Main_x                                                0x104E738
#define DI8__Keyboard_x                                            0x104E73C
#define DI8__Mouse_x                                               0xF43658
#define DI8__Mouse_Copy_x                                          0xE9ED34
#define DI8__Mouse_Check_x                                         0xF43990
#define __AutoSkillArray_x                                         0xE9FC4C
#define __Attack_x                                                 0xF3DA63
#define __Autofire_x                                               0xF3DA64
#define __BindList_x                                               0xC0B3E8
#define g_eqCommandStates_x                                        0xC0C160
#define __Clicks_x                                                 0xE9EDEC
#define __CommandList_x                                            0xC0CD20
#define __CurrentMapLabel_x                                        0x105EB0C
#define __CurrentSocial_x                                          0xBF5730
#define __DoAbilityList_x                                          0xED5584
#define __do_loot_x                                                0x5A1CF0
#define __DrawHandler_x                                            0x16DB4E0
#define __GroupCount_x                                             0xE8EFE2
#define __Guilds_x                                                 0xE95540
#define __gWorld_x                                                 0xE918C8
#define __HWnd_x                                                   0xF4365C
#define __heqmain_x                                                0x104DC78
#define __InChatMode_x                                             0xE9ED1C
#define __LastTell_x                                               0xEA0C80
#define __LMouseHeldTime_x                                         0xE9EE58
#define __Mouse_x                                                  0x104E724
#define __MouseLook_x                                              0xE9EDB2
#define __MouseEventTime_x                                         0xF3E544
#define __gpbCommandEvent_x                                        0xE913B4
#define __NetStatusToggle_x                                        0xE9EDB5
#define __PCNames_x                                                0xEA0230
#define __RangeAttackReady_x                                       0xE9FF30
#define __RMouseHeldTime_x                                         0xE9EE54
#define __RunWalkState_x                                           0xE9ED20
#define __ScreenMode_x                                             0xDDD174
#define __ScreenX_x                                                0xE9ECD4
#define __ScreenY_x                                                0xE9ECD0
#define __ScreenXMax_x                                             0xE9ECD8
#define __ScreenYMax_x                                             0xE9ECDC
#define __ServerHost_x                                             0xE9159B
#define __ServerName_x                                             0xED5544
#define __ShiftKeyDown_x                                           0xE9F3AC
#define __ShowNames_x                                              0xEA00EC
#define __Socials_x                                                0xED5644
#define __SubscriptionType_x                                       0x10A06A0
#define __TargetAggroHolder_x                                      0x10614C0
#define __ZoneType_x                                               0xE9F1B0
#define __GroupAggro_x                                             0x1061500
#define __LoginName_x                                              0x104E3BC
#define __Inviter_x                                                0xF3D9E0
#define __AttackOnAssist_x                                         0xEA00A8
#define __UseTellWindows_x                                         0xEA03CC
#define __gfMaxZoomCameraDistance_x                                0xADB9B8
#define __gfMaxCameraDistance_x                                    0xB08FD4
#define __pulAutoRun_x                                             0xE9EDD0
#define __pulForward_x                                             0xEA0404
#define __pulBackward_x                                            0xEA0408
#define __pulTurnRight_x                                           0xEA040C
#define __pulTurnLeft_x                                            0xEA0410
#define __pulStrafeLeft_x                                          0xEA0414
#define __pulStrafeRight_x                                         0xEA0418

////
//Section 1: Vital Offsets
////
#define instCRaid_x                                                0xE918D8
#define instEQZoneInfo_x                                           0xE9EFA8
#define pinstActiveBanker_x                                        0xE8F358
#define pinstActiveCorpse_x                                        0xE8F350
#define pinstActiveGMaster_x                                       0xE8F354
#define pinstActiveMerchant_x                                      0xE8F34C
#define pinstAltAdvManager_x                                       0xDDDBA0
#define pinstBandageTarget_x                                       0xE8F368
#define pinstCamActor_x                                            0xDDD164
#define pinstCDBStr_x                                              0xDDC8CC
#define pinstCDisplay_x                                            0xE918D0
#define pinstCEverQuest_x                                          0x104CC68
#define pinstEverQuestInfo_x                                       0xE9ECC8
#define pinstCharData_x                                            0xE9148C
#define pinstCharSpawn_x                                           0xE8F3A0
#define pinstControlledMissile_x                                   0xE913B8
#define pinstControlledPlayer_x                                    0xE8F3A0
#define pinstCResolutionHandler_x                                  0x16DB710
#define pinstCSidlManager_x                                        0x16DA6AC
#define pinstCXWndManager_x                                        0x16DA6A0
#define instDynamicZone_x                                          0xE95418
#define pinstDZMember_x                                            0xE95528
#define pinstDZTimerInfo_x                                         0xE9552C
#define pinstEqLogin_x                                             0x104DD08
#define instEQMisc_x                                               0xDDC810
#define pinstEQSoundManager_x                                      0xDDEAC8
#define pinstEQSpellStrings_x                                      0xC9F5A0
#define instExpeditionLeader_x                                     0xE95462
#define instExpeditionName_x                                       0xE954A2
#define pinstGroup_x                                               0xE8EFDE
#define pinstImeManager_x                                          0x16DA6A4
#define pinstLocalPlayer_x                                         0xE8F348
#define pinstMercenaryData_x                                       0xF40030
#define pinstMercenaryStats_x                                      0x106160C
#define pinstModelPlayer_x                                         0xE8F360
#define pinstPCData_x                                              0xE9148C
#define pinstSkillMgr_x                                            0xF421A8
#define pinstSpawnManager_x                                        0xF40C50
#define pinstSpellManager_x                                        0xF423C8
#define pinstSpellSets_x                                           0xF3668C
#define pinstStringTable_x                                         0xE8EFCC
#define pinstSwitchManager_x                                       0xE8EE78
#define pinstTarget_x                                              0xE8F39C
#define pinstTargetObject_x                                        0xE8F3A8
#define pinstTargetSwitch_x                                        0xE91488
#define pinstTaskMember_x                                          0xDDC6A0
#define pinstTrackTarget_x                                         0xE8F3A4
#define pinstTradeTarget_x                                         0xE8F35C
#define instTributeActive_x                                        0xDDC831
#define pinstViewActor_x                                           0xDDD160
#define pinstWorldData_x                                           0xE918CC
#define pinstZoneAddr_x                                            0xE9F248
#define pinstPlayerPath_x                                          0xF40CE8
#define pinstTargetIndicator_x                                     0xF42630
#define EQObject_Top_x                                             0xE8F344

////
//Section 2:  UI Related Offsets
////
#define pinstCAAWnd_x                                              0xDDD138
#define pinstCAchievementsWnd_x                                    0xDDD1A4
#define pinstCActionsWnd_x                                         0xDDD1BC
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDDC974
#define pinstCAdvancedLootWnd_x                                    0xDDD1B4
#define pinstCAdventureLeaderboardWnd_x                            0x10582E0
#define pinstCAdventureRequestWnd_x                                0x1058390
#define pinstCAdventureStatsWnd_x                                  0x1058440
#define pinstCAggroMeterWnd_x                                      0xDDD034
#define pinstCAlarmWnd_x                                           0xDDD0A8
#define pinstCAlertHistoryWnd_x                                    0xDDD154
#define pinstCAlertStackWnd_x                                      0xDDD0CC
#define pinstCAlertWnd_x                                           0xDDD0E4
#define pinstCAltStorageWnd_x                                      0x10587A0
#define pinstCAudioTriggersWindow_x                                0xC918D0
#define pinstCAuraWnd_x                                            0xDDD02C
#define pinstCAvaZoneWnd_x                                         0xDDD158
#define pinstCBandolierWnd_x                                       0xDDD074
#define pinstCBankWnd_x                                            0xDDD0E8
#define pinstCBarterMerchantWnd_x                                  0x10599E0
#define pinstCBarterSearchWnd_x                                    0x1059A90
#define pinstCBarterWnd_x                                          0x1059B40
#define pinstCBazaarConfirmationWnd_x                              0xDDD0C8
#define pinstCBazaarSearchWnd_x                                    0xDDD1F0
#define pinstCBazaarWnd_x                                          0xDDD08C
#define pinstCBlockedBuffWnd_x                                     0xDDD0D4
#define pinstCBlockedPetBuffWnd_x                                  0xDDD0F8
#define pinstCBodyTintWnd_x                                        0xDDCB98
#define pinstCBookWnd_x                                            0xDDD094
#define pinstCBreathWnd_x                                          0xDDD14C
#define pinstCBuffWindowNORMAL_x                                   0xDDD0B4
#define pinstCBuffWindowSHORT_x                                    0xDDD0B8
#define pinstCBugReportWnd_x                                       0xDDD144
#define pinstCButtonWnd_x                                          0x16DA910
#define pinstCCastingWnd_x                                         0xDDD134
#define pinstCCastSpellWnd_x                                       0xDDD1F8
//#define pinstCCharacterCreationWnd_x                             0xDAAE5C
#define pinstCCharacterListWnd_x                                   0xDDD148
#define pinstCChatWindowManager_x                                  0x105A600
#define pinstCClaimWnd_x                                           0x105A758
#define pinstCColorPickerWnd_x                                     0xDDD19C
#define pinstCCombatAbilityWnd_x                                   0xDDD038
#define pinstCCombatSkillsSelectWnd_x                              0xDDD1B8
#define pinstCCompassWnd_x                                         0xDDCB84
#define pinstCConfirmationDialog_x                                 0x105F658
#define pinstCContainerMgr_x                                       0xDDD128
#define pinstCContextMenuManager_x                                 0x16DA660
#define pinstCCursorAttachment_x                                   0xDDD120
#define pinstCDynamicZoneWnd_x                                     0x105AD20
#define pinstCEditLabelWnd_x                                       0xDDD09C
#define pinstCEQMainWnd_x                                          0x105AF68
#define pinstCEventCalendarWnd_x                                   0xDDD1EC
#define pinstCExtendedTargetWnd_x                                  0xDDCBA4
#define pinstCFacePick_x                                           0xDDD188
#define pinstCFactionWnd_x                                         0xDDD130
#define pinstCFellowshipWnd_x                                      0x105B168
#define pinstCFileSelectionWnd_x                                   0xDDD1A8
#define pinstCFindItemWnd_x                                        0xDDD0A0
#define pinstCFindLocationWnd_x                                    0x105B2C0
#define pinstCFriendsWnd_x                                         0xDDD1DC
#define pinstCGemsGameWnd_x                                        0xDDD088
#define pinstCGiveWnd_x                                            0xDDD0A4
#define pinstCGroupSearchFiltersWnd_x                              0xDDD044
#define pinstCGroupSearchWnd_x                                     0x105B6B8
#define pinstCGroupWnd_x                                           0x105B768
#define pinstCGuildBankWnd_x                                       0xEA008C
#define pinstCGuildCreationWnd_x                                   0x105B8C8
#define pinstCGuildMgmtWnd_x                                       0x105B978
#define pinstCharacterCreation_x                                   0xDDD03C
#define pinstCHelpWnd_x                                            0xDDC97C
#define pinstCHeritageSelectionWnd_x                               0xDDD1A0
#define pinstCHotButtonWnd_x                                       0x105DAD0
#define pinstCHotButtonWnd1_x                                      0x105DAD0
#define pinstCHotButtonWnd2_x                                      0x105DAD4
#define pinstCHotButtonWnd3_x                                      0x105DAD8
#define pinstCHotButtonWnd4_x                                      0x105DADC
#define pinstCIconSelectionWnd_x                                   0xDDD100
#define pinstCInspectWnd_x                                         0xDDD110
#define pinstCInventoryWnd_x                                       0xDDD078
#define pinstCInvSlotMgr_x                                         0xDDD0D8
#define pinstCItemDisplayManager_x                                 0x105E060
#define pinstCItemExpTransferWnd_x                                 0x105E194
#define pinstCItemFuseWnd_x                                        0xDDD194
#define pinstCItemOverflowWnd_x                                    0xDDD1F4
#define pinstCJournalCatWnd_x                                      0xDDD1C8
//#define pinstCJournalNPCWnd_x                                    0xDAB354
#define pinstCJournalTextWnd_x                                     0xDDD18C
#define pinstCKeyRingWnd_x                                         0xDDD0C4
#define pinstCLargeDialogWnd_x                                     0x10602D8
#define pinstCLayoutCopyWnd_x                                      0x105E4E0
#define pinstCLFGuildWnd_x                                         0x105E590
#define pinstCLoadskinWnd_x                                        0xDDD098
#define pinstCLootFiltersCopyWnd_x                                 0xCADB98
#define pinstCLootFiltersWnd_x                                     0xDDD0FC
#define pinstCLootSettingsWnd_x                                    0xDDD118
#define pinstCLootWnd_x                                            0xDDD184
#define pinstCMailAddressBookWnd_x                                 0xDDD0F0
#define pinstCMailCompositionWnd_x                                 0xDDD0D0
#define pinstCMailIgnoreListWnd_x                                  0xDDD0F4
#define pinstCMailWnd_x                                            0xDDD0B0
#define pinstCManageLootWnd_x                                      0xDDE050
#define pinstCMapToolbarWnd_x                                      0xDDD080
#define pinstCMapViewWnd_x                                         0xDDD070
#define pinstCMarketplaceWnd_x                                     0xDDC968
#define pinstCMerchantWnd_x                                        0xDDD1C4
#define pinstCMIZoneSelectWnd_x                                    0x105EDC8
#define pinstCMusicPlayerWnd_x                                     0xDDD0C0
#define pinstCNameChangeMercWnd_x                                  0xDDD07C
#define pinstCNameChangePetWnd_x                                   0xDDD064
#define pinstCNameChangeWnd_x                                      0xDDD1E0
#define pinstCNoteWnd_x                                            0xDDC96C
#define pinstCObjectPreviewWnd_x                                   0xDDCB8C
#define pinstCOptionsWnd_x                                         0xDDD084
#define pinstCPetInfoWnd_x                                         0xDDD0E0
#define pinstCPetitionQWnd_x                                       0xDDD1E4
//#define pinstCPlayerCustomizationWnd_x                           0xDAADC4
#define pinstCPlayerNotesWnd_x                                     0xDDCB94
#define pinstCPlayerWnd_x                                          0xDDD090
#define pinstCPopupWndManager_x                                    0x105F658
#define pinstCProgressionSelectionWnd_x                            0x105F708
#define pinstCPurchaseGroupWnd_x                                   0xDDCC24
#define pinstCPurchaseWnd_x                                        0xDDCB9C
#define pinstCPvPLeaderboardWnd_x                                  0x105F7B8
#define pinstCPvPStatsWnd_x                                        0x105F868
#define pinstCQuantityWnd_x                                        0xDDD108
#define pinstCRaceChangeWnd_x                                      0xDDC970
#define pinstCRaidOptionsWnd_x                                     0xDDD068
#define pinstCRaidWnd_x                                            0xDDD114
#define pinstCRealEstateItemsWnd_x                                 0xDDD1AC
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDDD1E8
#define pinstCRealEstateManageWnd_x                                0xDDD11C
#define pinstCRealEstateNeighborhoodWnd_x                          0xDDD13C
#define pinstCRealEstatePlotSearchWnd_x                            0xDDD15C
#define pinstCRealEstatePurchaseWnd_x                              0xDDD190
#define pinstCRespawnWnd_x                                         0xDDD040
//#define pinstCRewardSelectionWnd_x                               0x1022600
#define pinstCSelectorWnd_x                                        0xDDD028
#define pinstCSendMoneyWnd_x                                       0xDDD0BC
#define pinstCServerListWnd_x                                      0xDDD150
#define pinstCSkillsSelectWnd_x                                    0xDDD198
#define pinstCSkillsWnd_x                                          0xDDD180
#define pinstCSocialEditWnd_x                                      0xDDD124
#define pinstCSocialWnd_x                                          0xDDD0AC
#define pinstCSpellBookWnd_x                                       0xDDCBA0
#define pinstCStoryWnd_x                                           0xDDCB80
#define pinstCTargetOfTargetWnd_x                                  0x1061690
#define pinstCTargetWnd_x                                          0xDDD0DC
#define pinstCTaskOverlayWnd_x                                     0xDDD16C
#define pinstCTaskSelectWnd_x                                      0x10617E8
#define pinstCTaskManager_x                                        0xCAE4E8
#define pinstCTaskTemplateSelectWnd_x                              0x1061898
#define pinstCTaskWnd_x                                            0x1061948
#define pinstCTextEntryWnd_x                                       0xDDCB88
#define pinstCTimeLeftWnd_x                                        0xDDD1B0
#define pinstCTipWndCONTEXT_x                                      0x1061B4C
#define pinstCTipWndOFDAY_x                                        0x1061B48
#define pinstCTitleWnd_x                                           0x1061BF8
#define pinstCTrackingWnd_x                                        0xDDD0EC
#define pinstCTradeskillWnd_x                                      0x1061D60
#define pinstCTradeWnd_x                                           0xDDCB90
#define pinstCTrainWnd_x                                           0xDDD104
#define pinstCTributeBenefitWnd_x                                  0x1061F60
#define pinstCTributeMasterWnd_x                                   0x1062010
#define pinstCTributeTrophyWnd_x                                   0x10620C0
#define pinstCVideoModesWnd_x                                      0xDDD1C0
#define pinstCVoiceMacroWnd_x                                      0xF42D98
#define pinstCVoteResultsWnd_x                                     0xDDD030
#define pinstCVoteWnd_x                                            0xDDCBA8
#define pinstCWebManager_x                                         0xF43414
#define pinstCZoneGuideWnd_x                                       0xDDD12C
#define pinstCZonePathWnd_x                                        0xDDD140

#define pinstEQSuiteTextureLoader_x                                0xC7C4A8
#define pinstItemIconCache_x                                       0x105AF20
#define pinstLootFiltersManager_x                                  0xCADC48
#define pinstRewardSelectionWnd_x                                  0x105FFB0

////
// Section 3: Miscellaneous Offsets
////
#define __AppCrashWrapper_x                                        0xC2CDF8
#define __CastRay_x                                                0x59D150
#define __CastRay2_x                                               0x59D1A0
#define __ConvertItemTags_x                                        0x5B8CF0
#define __CleanItemTags_x                                          0x477C40
#define __CrashHandler_x                                           0x854640
#define __DoesFileExist_x                                          0x8F71C0
#define __EQGetTime_x                                              0x8F3C20
#define __ExecuteCmd_x                                             0x595A50
#define __FixHeading_x                                             0x98F060
#define __GameLoop_x                                               0x6AB250
#define __get_bearing_x                                            0x59CCA0
#define __get_melee_range_x                                        0x59D390
#define __GetAnimationCache_x                                      0x710310
#define __GetGaugeValueFromEQ_x                                    0x805EA0
#define __GetLabelFromEQ_x                                         0x807990
#define __GetXTargetType_x                                         0x990AC0
#define __HandleMouseWheel_x                                       0x6ABE40
#define __HeadingDiff_x                                            0x98F0D0
#define __HelpPath_x                                               0xF3E134
#define __LoadFrontEnd_x                                           0x6A7D20
#define __NewUIINI_x                                               0x805B70
#define __pCrashHandler_x                                          0x107F4C8
#define __ProcessGameEvents_x                                      0x5FD2C0
#define __ProcessMouseEvent_x                                      0x5FCA80
#define __SaveColors_x                                             0x5468A0
#define __STMLToText_x                                             0x932190
#define __ToggleKeyRingItem_x                                      0x508B90
#define CMemoryMappedFile__SetFile_x                               0xA69420
#define CrashDetected_x                                            0x6A9780
#define DrawNetStatus_x                                            0x6291C0
#define Expansion_HoT_x                                            0xEA0094
#define Teleport_Table_Size_x                                      0xE91444
#define Teleport_Table_x                                           0xE8F3B0
#define Util__FastTime_x                                           0x8F37E0
#define wwsCrashReportCheckForUploader_x                           0x8553D0
#define wwsCrashReportPlatformLaunchUploader_x                     0x857AB0
#define __eq_delete_x                                              0x9975DE
#define __eq_new_x                                                 0x997BB4

////
// Section 4: Function Offsets
////
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48B9D0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4948E0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4946B0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x48EF60
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x48E3B0

// AltAdvManager
#define AltAdvManager__GetCalculatedTimer_x                        0x54E3F0
#define AltAdvManager__IsAbilityReady_x                            0x54D340
#define AltAdvManager__GetAAById_x                                 0x54D540
#define AltAdvManager__CanTrainAbility_x                           0x54D5B0
#define AltAdvManager__CanSeeAbility_x                             0x54D910

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C7A00
#define CharacterZoneClient__HasSkill_x                            0x4D28D0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D3FF0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BC030
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B8770
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D69C0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D6AA0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D6B80
#define CharacterZoneClient__FindAffectSlot_x                      0x4C0B10
#define CharacterZoneClient__BardCastBard_x                        0x4C35E0
#define CharacterZoneClient__GetMaxEffects_x                       0x4B8840
#define CharacterZoneClient__GetEffect_x                           0x4B86B0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C1B40
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C1C10
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C1C60
#define CharacterZoneClient__CalcAffectChange_x                    0x4C1DB0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C1F90
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B0530
#define CharacterZoneClient__FindItemByGuid_x                      0x4D4F60
#define CharacterZoneClient__FindItemByRecord_x                    0x4D49D0

// CBankWnd
#define CBankWnd__GetNumBankSlots_x                                0x6D1A80
#define CBankWnd__WndNotification_x                                0x6D1860

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6DF230

// CButtonWnd
#define CButtonWnd__SetCheck_x                                     0x60BC00 // unused
#define CButtonWnd__CButtonWnd_x                                   0x92E550
#define CButtonWnd__dCButtonWnd_x                                  0x92E820
#define CButtonWnd__vftable_x                                      0xB22434

// CChatWindowManager
#define CChatWindowManager__GetRGBAFromIndex_x                     0x6FF300
#define CChatWindowManager__InitContextMenu_x                      0x6F8590
#define CChatWindowManager__FreeChatWindow_x                       0x6FDE20
#define CChatWindowManager__GetLockedActiveChatWindow_x            0x4E60D0
#define CChatWindowManager__SetLockedActiveChatWindow_x            0x6FEF80
#define CChatWindowManager__CreateChatWindow_x                     0x6FE460

// ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E61E0

// CChatWindow
#define CChatWindow__CChatWindow_x                                 0x6FFC30
#define CChatWindow__Clear_x                                       0x700ED0
#define CChatWindow__WndNotification_x                             0x701660
#define CChatWindow__AddHistory_x                                  0x7007A0

// CContextMenu
#define CContextMenu__CContextMenu_x                               0x942C30
#define CContextMenu__dCContextMenu_x                              0x942E60
#define CContextMenu__AddMenuItem_x                                0x942E70
#define CContextMenu__RemoveMenuItem_x                             0x943180
#define CContextMenu__RemoveAllMenuItems_x                         0x9431A0
#define CContextMenu__CheckMenuItem_x                              0x943220
#define CContextMenu__SetMenuItem_x                                0x9430A0
#define CContextMenu__AddSeparator_x                               0x943000

// CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x9437C0
#define CContextMenuManager__RemoveMenu_x                          0x943830
#define CContextMenuManager__PopupMenu_x                           0x9438F0
#define CContextMenuManager__Flush_x                               0x943760
#define CContextMenuManager__GetMenu_x                             0x496B80
#define CContextMenuManager__CreateDefaultMenu_x                   0x70AAD0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D4110
#define CChatService__GetFriendName_x                              0x8D4120

// CComboWnd
#define CComboWnd__DeleteAll_x                                     0x9400C0
#define CComboWnd__Draw_x                                          0x93F5C0
#define CComboWnd__GetCurChoice_x                                  0x93FF00
#define CComboWnd__GetListRect_x                                   0x93FA70
#define CComboWnd__GetTextRect_x                                   0x940130
#define CComboWnd__InsertChoice_x                                  0x93FC00
#define CComboWnd__SetColors_x                                     0x93FBD0
#define CComboWnd__SetChoice_x                                     0x93FED0
#define CComboWnd__GetItemCount_x                                  0x93FF10
#define CComboWnd__GetCurChoiceText_x                              0x93FF50
#define CComboWnd__GetChoiceText_x                                 0x93FF20
#define CComboWnd__InsertChoiceAtIndex_x                           0x93FC90

// CContainerWnd
#define CContainerWnd__HandleCombine_x                             0x7084C0
#define CContainerWnd__vftable_x                                   0xAEF7E8
#define CContainerWnd__SetContainer_x                              0x709A30

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x541300
#define CDisplay__PreZoneMainUI_x                                  0x541310
#define CDisplay__CleanGameUI_x                                    0x546660
#define CDisplay__GetClickedActor_x                                0x539620
#define CDisplay__GetUserDefinedColor_x                            0x531CE0
#define CDisplay__GetWorldFilePath_x                               0x53B070
#define CDisplay__is3dON_x                                         0x5362D0
#define CDisplay__ReloadUI_x                                       0x540790
#define CDisplay__WriteTextHD2_x                                   0x5360B0
#define CDisplay__TrueDistance_x                                   0x53CCD0
#define CDisplay__SetViewActor_x                                   0x538F70
#define CDisplay__GetFloorHeight_x                                 0x536390
#define CDisplay__SetRenderWindow_x                                0x534CC0
#define CDisplay__ToggleScreenshotMode_x                           0x538A40

// CEditBaseWnd
#define CEditBaseWnd__SetSel_x                                     0x9628C0

// CEditWnd
#define CEditWnd__DrawCaret_x                                      0x946190
#define CEditWnd__GetCharIndexPt_x                                 0x947090
#define CEditWnd__GetDisplayString_x                               0x946F30
#define CEditWnd__GetHorzOffset_x                                  0x9457C0
#define CEditWnd__GetLineForPrintableChar_x                        0x948240
#define CEditWnd__GetSelStartPt_x                                  0x947340
#define CEditWnd__GetSTMLSafeText_x                                0x946D50
#define CEditWnd__PointFromPrintableChar_x                         0x947E70
#define CEditWnd__SelectableCharFromPoint_x                        0x947FE0
#define CEditWnd__SetEditable_x                                    0x947410
#define CEditWnd__SetWindowTextA_x                                 0x946AD0

// CEverQuest
#define CEverQuest__DoPercentConvert_x                             0x5EAF90
#define CEverQuest__ClickedPlayer_x                                0x5DD050
#define CEverQuest__CreateTargetIndicator_x                        0x5FA570
#define CEverQuest__DeleteTargetIndicator_x                        0x5FA600
#define CEverQuest__DoTellWindow_x                                 0x4E62C0
#define CEverQuest__OutputTextToLog_x                              0x4E64F0
#define CEverQuest__DropHeldItemOnGround_x                         0x5D2080
#define CEverQuest__dsp_chat_x                                     0x4E6880
#define CEverQuest__trimName_x                                     0x5F6850
#define CEverQuest__Emote_x                                        0x5EB7A0
#define CEverQuest__EnterZone_x                                    0x5E5780
#define CEverQuest__GetBodyTypeDesc_x                              0x5F00E0
#define CEverQuest__GetClassDesc_x                                 0x5F0720
#define CEverQuest__GetClassThreeLetterCode_x                      0x5F0D20
#define CEverQuest__GetDeityDesc_x                                 0x5F8EC0
#define CEverQuest__GetLangDesc_x                                  0x5F0EE0
#define CEverQuest__GetRaceDesc_x                                  0x5F0700
#define CEverQuest__InterpretCmd_x                                 0x5F9490
#define CEverQuest__LeftClickedOnPlayer_x                          0x5D6280
#define CEverQuest__LMouseUp_x                                     0x5D45F0
#define CEverQuest__RightClickedOnPlayer_x                         0x5D6B60
#define CEverQuest__RMouseUp_x                                     0x5D5590
#define CEverQuest__SetGameState_x                                 0x5D1E10
#define CEverQuest__UPCNotificationFlush_x                         0x5F6750
#define CEverQuest__IssuePetCommand_x                              0x5F22F0
#define CEverQuest__ReportSuccessfulHit_x                          0x5ECBA0

// CGaugeWnd
// not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x71A550
#define CGaugeWnd__CalcLinesFillRect_x                             0x71A5B0
#define CGaugeWnd__Draw_x                                          0x719BA0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ACF90
#define CGuild__GetGuildName_x                                     0x4AC070
#define CGuild__GetGuildIndex_x                                    0x4AC400

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton_x                               0x7358C0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x60BFC0

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot_x                                 0x7428F0
#define CInvSlotMgr__MoveItem_x                                    0x741600
#define CInvSlotMgr__SelectSlot_x                                  0x7429C0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x73FEB0
#define CInvSlot__SliderComplete_x                                 0x73DC10
#define CInvSlot__GetItemBase_x                                    0x73D590
#define CInvSlot__UpdateItem_x                                     0x73D700

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x744420
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7435D0
#define CInvSlotWnd__HandleLButtonUp_x                             0x743FA0

// CItemDisplayWnd
#define CItemDisplayWnd__SetSpell_x                                0x8012C0
#define CItemDisplayWnd__UpdateStrings_x                           0x752BB0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x74C8D0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x74CDF0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x7531C0
#define CItemDisplayWnd__AboutToShow_x                             0x752800
#define CItemDisplayWnd__WndNotification_x                         0x7542B0
#define CItemDisplayWnd__RequestConvertItem_x                      0x753D70
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x751860
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x752620

// CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x839D00

// CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x758810

// CLabel 
#define CLabel__Draw_x                                             0x75E320

// CListWnd
#define CListWnd__CListWnd_x                                       0x918B70
#define CListWnd__dCListWnd_x                                      0x918E80
#define CListWnd__vftable_x                                        0xB21D98
#define CListWnd__AddColumn_x                                      0x91D190
#define CListWnd__AddColumn1_x                                     0x91D1E0
#define CListWnd__AddLine_x                                        0x91D570
#define CListWnd__AddString_x                                      0x91D370
#define CListWnd__CalculateFirstVisibleLine_x                      0x91CF60
#define CListWnd__CalculateVSBRange_x                              0x91CD50
#define CListWnd__ClearSel_x                                       0x91DD50
#define CListWnd__ClearAllSel_x                                    0x91DDB0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x91E7B0
#define CListWnd__Compare_x                                        0x91C690
#define CListWnd__Draw_x                                           0x918F80
#define CListWnd__DrawColumnSeparators_x                           0x91B760
#define CListWnd__DrawHeader_x                                     0x91BBD0
#define CListWnd__DrawItem_x                                       0x91BFD0
#define CListWnd__DrawLine_x                                       0x91B8D0
#define CListWnd__DrawSeparator_x                                  0x91B800
#define CListWnd__EnableLine_x                                     0x91B040
#define CListWnd__EnsureVisible_x                                  0x91E6E0
#define CListWnd__ExtendSel_x                                      0x91DC80
#define CListWnd__GetColumnTooltip_x                               0x91AB80
#define CListWnd__GetColumnMinWidth_x                              0x91ABF0
#define CListWnd__GetColumnWidth_x                                 0x91AAF0
#define CListWnd__GetCurSel_x                                      0x91A480
#define CListWnd__GetItemAtPoint_x                                 0x91B2B0
#define CListWnd__GetItemAtPoint1_x                                0x91B320
#define CListWnd__GetItemData_x                                    0x91A500
#define CListWnd__GetItemHeight_x                                  0x91A8C0
#define CListWnd__GetItemIcon_x                                    0x91A690
#define CListWnd__GetItemRect_x                                    0x91B130
#define CListWnd__GetItemText_x                                    0x91A540
#define CListWnd__GetSelList_x                                     0x91DE00
#define CListWnd__GetSeparatorRect_x                               0x91B560
#define CListWnd__InsertLine_x                                     0x91D960
#define CListWnd__RemoveLine_x                                     0x91DAB0
#define CListWnd__SetColors_x                                      0x91CD20
#define CListWnd__SetColumnJustification_x                         0x91CA50
#define CListWnd__SetColumnWidth_x                                 0x91C970
#define CListWnd__SetCurSel_x                                      0x91DBC0
#define CListWnd__SetItemColor_x                                   0x91E3A0
#define CListWnd__SetItemData_x                                    0x91E360
#define CListWnd__SetItemText_x                                    0x91DF70
#define CListWnd__ShiftColumnSeparator_x                           0x91CB10
#define CListWnd__Sort_x                                           0x91C810
#define CListWnd__ToggleSel_x                                      0x91DBF0
#define CListWnd__SetColumnsSizable_x                              0x91CBB0
#define CListWnd__SetItemWnd_x                                     0x91E220
#define CListWnd__GetItemWnd_x                                     0x91A6E0
#define CListWnd__SetItemIcon_x                                    0x91DFF0
#define CListWnd__CalculateCustomWindowPositions_x                 0x91D050
#define CListWnd__SetVScrollPos_x                                  0x91C950

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd_x                                 0x773A60
#define CMapViewWnd__GetWorldCoordinates_x                         0x772170
#define CMapViewWnd__HandleLButtonDown_x                           0x76F1D0 //MapViewMap

// MapViewMap
#define MapViewMap__Clear_x                                        0x76F8F0
#define MapViewMap__SaveEx_x                                       0x772C90
#define MapViewMap__SetZoom_x                                      0x777350

// CMerchantWnd
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x796DA0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x797680
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x797BB0
#define CMerchantWnd__SelectRecoverySlot_x                         0x79AB30
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7958F0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A0700
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7969C0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8A1CC0
#define CPacketScrambler__hton_x                                   0x8A1CB0

// CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x93BAD0
#define CSidlManagerBase__CreatePageWnd_x                          0x93B2F0
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x937550
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x9374E0
#define CSidlManagerBase__FindAnimation1_x                         0x937730
#define CSidlManagerBase__FindScreenPieceTemplate_x                0x937B40
#define CSidlManagerBase__FindScreenPieceTemplate1_x               0x937930
#define CSidlManagerBase__CreateLabel_x                            0x7F8760
#define CSidlManagerBase__CreateXWndFromTemplate_x                 0x93AAE0
#define CSidlManagerBase__CreateXWndFromTemplate1_x                0x93ACC0
#define CSidlManagerBase__CreateXWnd_x                             0x7F8690

// CSidlManager
#define CSidlManager__CreateHotButtonWnd_x                         0x7F8C40

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9342D0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9341D0
#define CSidlScreenWnd__ConvertToRes_x                             0x9598D0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x933C70
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x933960
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x933A30
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x933B00
#define CSidlScreenWnd__DrawSidlPiece_x                            0x934760
#define CSidlScreenWnd__EnableIniStorage_x                         0x934C30
#define CSidlScreenWnd__GetChildItem_x                             0x934BB0
#define CSidlScreenWnd__GetSidlPiece_x                             0x934950
#define CSidlScreenWnd__HandleLButtonUp_x                          0x924560
#define CSidlScreenWnd__Init1_x                                    0x933570
#define CSidlScreenWnd__LoadIniInfo_x                              0x934C80
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9357A0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x932970
#define CSidlScreenWnd__m_layoutCopy_x                             0x16DA530
#define CSidlScreenWnd__StoreIniInfo_x                             0x935320
#define CSidlScreenWnd__StoreIniVis_x                              0x935680
#define CSidlScreenWnd__vftable_x                                  0xB226D0
#define CSidlScreenWnd__WndNotification_x                          0x934670

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6710A0
#define CSkillMgr__GetSkillCap_x                                   0x671280
#define CSkillMgr__GetNameToken_x                                  0x670830
#define CSkillMgr__IsActivatedSkill_x                              0x670970
#define CSkillMgr__IsCombatSkill_x                                 0x6708B0

// CSliderWnd
#define CSliderWnd__GetValue_x                                     0x944590
#define CSliderWnd__SetValue_x                                     0x944400
#define CSliderWnd__SetNumTicks_x                                  0x944460

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet_x                               0x7FE760

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x94CD50
#define CStmlWnd__CalculateHSBRange_x                              0x94DE20
#define CStmlWnd__CalculateVSBRange_x                              0x94DD90
#define CStmlWnd__CanBreakAtCharacter_x                            0x952150
#define CStmlWnd__FastForwardToEndOfTag_x                          0x952DE0
#define CStmlWnd__ForceParseNow_x                                  0x94D2F0
#define CStmlWnd__GetNextTagPiece_x                                0x9520B0
#define CStmlWnd__GetSTMLText_x                                    0x4F80C0
#define CStmlWnd__GetVisibleText_x                                 0x94D310
#define CStmlWnd__InitializeWindowVariables_x                      0x952C30
#define CStmlWnd__MakeStmlColorTag_x                               0x94C3C0
#define CStmlWnd__MakeWndNotificationTag_x                         0x94C430
#define CStmlWnd__SetSTMLText_x                                    0x94B470
#define CStmlWnd__StripFirstSTMLLines_x                            0x953ED0
#define CStmlWnd__UpdateHistoryString_x                            0x952FF0

// CTabWnd
#define CTabWnd__Draw_x                                            0x94A5F0
#define CTabWnd__DrawCurrentPage_x                                 0x94ACD0
#define CTabWnd__DrawTab_x                                         0x94A9F0
#define CTabWnd__GetCurrentPage_x                                  0x949E00
#define CTabWnd__GetPageInnerRect_x                                0x94A040
#define CTabWnd__GetTabInnerRect_x                                 0x949F80
#define CTabWnd__GetTabRect_x                                      0x949E30
#define CTabWnd__InsertPage_x                                      0x94A250
#define CTabWnd__SetPage_x                                         0x94A0C0
#define CTabWnd__SetPageRect_x                                     0x94A530
#define CTabWnd__UpdatePage_x                                      0x94A8B0
#define CTabWnd__GetPageFromTabIndex_x                             0x94A930
#define CTabWnd__GetCurrentTabIndex_x                              0x949DF0

// CPageWnd
#define CPageWnd__GetTabText_x                                     0x758BE0
#define CPageWnd__SetTabText_x                                     0x949950

// CTextOverlay
#define CTextOverlay__DisplayText_x                                0x4A6BC0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x921420
#define CTextureFont__GetTextExtent_x                              0x9215E0

// CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6A4D30
#define CHtmlComponentWnd__ValidateUri_x                           0x7372B0
#define CHtmlWnd__SetClientCallbacks_x                             0x611050
#define CHtmlWnd__AddObserver_x                                    0x611070
#define CHtmlWnd__RemoveObserver_x                                 0x6110D0
#define Window__getProgress_x                                      0x852350
#define Window__getStatus_x                                        0x852370
#define Window__getURI_x                                           0x852380

// CXMLDataManager
#define CXMLDataManager__GetXMLData_x                              0x95F2F0

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead_x                             0x90E700

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr_x                                             0x4E5F10
#define CXStr__CXStr1_x                                            0x4B40C0
#define CXStr__CXStr3_x                                            0x8EFD10
#define CXStr__dCXStr_x                                            0x473100
#define CXStr__operator_equal_x                                    0x8EFF40
#define CXStr__operator_equal1_x                                   0x8EFF80
#define CXStr__operator_plus_equal1_x                              0x8F0A10
#define CXStr__SetString_x                                         0x8F2900
#define CXStr__operator_char_p_x                                   0x8F0450
#define CXStr__GetChar_x                                           0x8F2250
#define CXStr__Delete_x                                            0x8F1B00
#define CXStr__GetUnicode_x                                        0x8F22C0
#define CXStr__GetLength_x                                         0x4A6970
#define CXStr__Mid_x                                               0x477FF0
#define CXStr__Insert_x                                            0x8F2320
#define CXStr__FindNext_x                                          0x8F1F70
#define CXStr__gFreeLists_x                                        0xC7A8E8
#define CXStr__gCXStrAccess_x                                      0x16D9C44

// CTileLayoutWnd
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x942840

// CXWnd
#define CXWnd__BringToTop_x                                        0x927C30
#define CXWnd__Center_x                                            0x9277B0
#define CXWnd__ClrFocus_x                                          0x9275F0
#define CXWnd__Destroy_x                                           0x927690
#define CXWnd__DoAllDrawing_x                                      0x923D20
#define CXWnd__DrawChildren_x                                      0x923CF0
#define CXWnd__DrawColoredRect_x                                   0x924170
#define CXWnd__DrawTooltip_x                                       0x922850
#define CXWnd__DrawTooltipAtPoint_x                                0x922910
#define CXWnd__GetBorderFrame_x                                    0x923FD0
#define CXWnd__GetChildItem_x                                      0x927E40
#define CXWnd__GetChildWndAt_x                                     0x927CD0
#define CXWnd__GetClientClipRect_x                                 0x925F80
#define CXWnd__GetScreenClipRect_x                                 0x926050
#define CXWnd__GetScreenRect_x                                     0x926210
#define CXWnd__GetTooltipRect_x                                    0x9241C0
#define CXWnd__GetWindowTextA_x                                    0x498270
#define CXWnd__IsActive_x                                          0x9248D0
#define CXWnd__IsDescendantOf_x                                    0x926BC0
#define CXWnd__IsReallyVisible_x                                   0x926BF0
#define CXWnd__IsType_x                                            0x928340
#define CXWnd__Minimize_x                                          0x9272B0
#define CXWnd__Move_x                                              0x926C50
#define CXWnd__Move1_x                                             0x926D00
#define CXWnd__ProcessTransition_x                                 0x927760
#define CXWnd__Refade_x                                            0x926FA0
#define CXWnd__Resize_x                                            0x927240
#define CXWnd__Right_x                                             0x9279F0
#define CXWnd__SetFocus_x                                          0x9275B0
#define CXWnd__SetFont_x                                           0x927620
#define CXWnd__SetKeyTooltip_x                                     0x928160
#define CXWnd__SetMouseOver_x                                      0x9250F0
#define CXWnd__SetParent_x                                         0x926960
#define CXWnd__StartFade_x                                         0x926A90
#define CXWnd__vftable_x                                           0xB221D4
#define CXWnd__CXWnd_x                                             0x921900
#define CXWnd__dCXWnd_x                                            0x921E30

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x95A960

// CXWndManager
#define CXWndManager__DrawCursor_x                                 0x92AB60
#define CXWndManager__DrawWindows_x                                0x92AB80
#define CXWndManager__GetKeyboardFlags_x                           0x92D240
#define CXWndManager__HandleKeyboardMsg_x                          0x92CE50
#define CXWndManager__RemoveWnd_x                                  0x92D490
#define CXWndManager__RemovePendingDeletionWnd_x                   0x92D9D0

// CDBStr
#define CDBStr__GetString_x                                        0x530CB0

// CharacterZoneClient
#define CharacterZoneClient__CastSpell_x                           0x4B9750
#define CharacterZoneClient__Cur_HP_x                              0x4CF8B0
#define CharacterZoneClient__Cur_Mana_x                            0x4D7080
#define CharacterZoneClient__GetCastingTimeModifier_x              0x4BC680
#define CharacterZoneClient__GetFocusCastingTimeModifier_x         0x4B0170
#define CharacterZoneClient__GetFocusRangeModifier_x               0x4B02C0
#define CharacterZoneClient__GetHPRegen_x                          0x4DCEB0
#define CharacterZoneClient__GetEnduranceRegen_x                   0x4DD4C0
#define CharacterZoneClient__GetManaRegen_x                        0x4DD900
#define CharacterZoneClient__Max_Endurance_x                       0x636D40
#define CharacterZoneClient__Max_HP_x                              0x4CF6E0
#define CharacterZoneClient__Max_Mana_x                            0x636B40
#define CharacterZoneClient__doCombatAbility_x                     0x639200
#define CharacterZoneClient__UseSkill_x                            0x4DF710
#define CharacterZoneClient__IsExpansionFlag_x                     0x594210
#define CharacterZoneClient__TotalEffect_x                         0x4C2D20
#define CharacterZoneClient__GetPCSpellAffect_x                    0x4BD280
#define CharacterZoneClient__SpellDuration_x                       0x4BCDB0
#define CharacterZoneClient__GetAdjustedSkill_x                    0x4D2690
#define CharacterZoneClient__GetBaseSkill_x                        0x4D3630
#define CharacterZoneClient__CanUseItem_x                          0x4D7390

// ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8C0ED0

// PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x64D790

// PcClient
#define PcClient__PcClient_x                                       0x62D8B0
#define PcClient__GetConLevel_x                                    0x630170

// CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B73C0
#define CCharacterListWnd__EnterWorld_x                            0x4B6E00
#define CCharacterListWnd__Quit_x                                  0x4B6B10
#define CCharacterListWnd__UpdateList_x                            0x4B6F90

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x612280
#define EQ_Item__CreateItemTagString_x                             0x89B4F0
#define EQ_Item__IsStackable_x                                     0x8A0010
#define EQ_Item__GetImageNum_x                                     0x89CF30
#define EQ_Item__CreateItemClient_x                                0x611450
#define EQ_Item__GetItemValue_x                                    0x89E220
#define EQ_Item__ValueSellMerchant_x                               0x8A1850
#define EQ_Item__IsKeyRingItem_x                                   0x89F960
#define EQ_Item__CanGoInBag_x                                      0x6123A0
#define EQ_Item__IsEmpty_x                                         0x89F490
#define EQ_Item__GetMaxItemCount_x                                 0x89E650
#define EQ_Item__GetHeldItem_x                                     0x89CE00
#define EQ_Item__GetAugmentFitBySlot_x                             0x89AE20

// EQ_LoadingS
#define EQ_LoadingS__SetProgressBar_x                              0x54F120
#define EQ_LoadingS__Array_x                                       0xC045F8

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x6376A0
#define EQ_PC__GetAlternateAbilityId_x                             0x8AA8E0
#define EQ_PC__GetCombatAbility_x                                  0x8AAF50
#define EQ_PC__GetCombatAbilityTimer_x                             0x8AAFC0
#define EQ_PC__GetItemRecastTimer_x                                0x639780
#define EQ_PC__HasLoreItem_x                                       0x630990
#define EQ_PC__AlertInventoryChanged_x                             0x62FAB0
#define EQ_PC__GetPcZoneClient_x                                   0x65C230
#define EQ_PC__RemoveMyAffect_x                                    0x63C9A0
#define EQ_PC__GetKeyRingItems_x                                   0x8AB860
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8AB5E0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8ABB50

// EQItemList
#define EQItemList__EQItemList_x                                   0x59A770
#define EQItemList__add_object_x                                   0x5C7800
#define EQItemList__add_item_x                                     0x59ACC0
#define EQItemList__delete_item_x                                  0x59AD10
#define EQItemList__FreeItemList_x                                 0x59AC10

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x52D7C0

// EQPlayer
#define EQPlayer__ChangeBoneStringSprite_x                         0x64F010
#define EQPlayer__dEQPlayer_x                                      0x641EE0
#define EQPlayer__DoAttack_x                                       0x656EC0
#define EQPlayer__EQPlayer_x                                       0x6425A0
#define EQPlayer__SetNameSpriteState_x                             0x646C70
#define EQPlayer__SetNameSpriteTint_x                              0x647B40
#define PlayerBase__HasProperty_j_x                                0x98D440
#define EQPlayer__IsTargetable_x                                   0x98D8E0
#define EQPlayer__CanSee_x                                         0x98D740
#define EQPlayer__CanSee1_x                                        0x98D810
#define PlayerBase__GetVisibilityLineSegment_x                     0x98D500

// PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x659CC0
#define PlayerZoneClient__GetLevel_x                               0x65C270
#define PlayerZoneClient__IsValidTeleport_x                        0x5C8970
#define PlayerZoneClient__LegalPlayerRace_x                        0x548540

// EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x651DD0
#define EQPlayerManager__GetSpawnByName_x                          0x651E80
#define EQPlayerManager__GetPlayerFromPartialName_x                0x651F10

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x615A70
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x615AF0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x615B30
#define KeypressHandler__ClearCommandStateArray_x                  0x616F40
#define KeypressHandler__HandleKeyDown_x                           0x616F60
#define KeypressHandler__HandleKeyUp_x                             0x617000
#define KeypressHandler__SaveKeymapping_x                          0x617430

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BEDC0

// StringTable
#define StringTable__getString_x                                   0x8B9B40

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x63C610
#define PcZoneClient__RemovePetEffect_x                            0x63CC40
#define PcZoneClient__HasAlternateAbility_x                        0x636980
#define PcZoneClient__GetCurrentMod_x                              0x4E2800
#define PcZoneClient__GetModCap_x                                  0x4E2700
#define PcZoneClient__CanEquipItem_x                               0x637030
#define PcZoneClient__GetItemByID_x                                0x639BF0
#define PcZoneClient__GetItemByItemClass_x                         0x639D40
#define PcZoneClient__RemoveBuffEffect_x                           0x63CC60
#define PcZoneClient__BandolierSwap_x                              0x637C60
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x639720

// Doors
#define EQSwitch__UseSwitch_x                                      0x5CD570

// IconCache
#define IconCache__GetIcon_x                                       0x70FBA0

// CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x707660
#define CContainerMgr__CloseContainer_x                            0x707930
#define CContainerMgr__OpenExperimentContainer_x                   0x7083B0

// CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CAF00

// CHelpWnd
#define CHelpWnd__SetFile_x                                        0x60A3E0

// CLootWnd
#define CLootWnd__LootAll_x                                        0x765C60
#define CLootWnd__RequestLootSlot_x                                0x764E60

// EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x567620
#define EQ_Spell__SpellAffects_x                                   0x567A90
#define EQ_Spell__SpellAffectBase_x                                0x567850
#define EQ_Spell__IsStackable_x                                    0x4C7350
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C71A0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B4760
#define EQ_Spell__IsSPAStacking_x                                  0x5688C0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x567DE0
#define EQ_Spell__IsNoRemove_x                                     0x4C7330
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x5688D0
#define __IsResEffectSpell_x                                       0x4C66D0

// EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AAD00

// EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C9540

// CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x811980
#define CTargetWnd__WndNotification_x                              0x811210
#define CTargetWnd__RefreshTargetBuffs_x                           0x8114E0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x810370

// CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x815F50

// CTaskManager
#define CTaskManager__GetEntry_x                                   0x52B1C0
#define CTaskManager__HandleMessage_x                              0x529650

// EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x562BD0
#define EqSoundManager__PlayScriptMp3_x                            0x562D30
#define EqSoundManager__SoundAssistPlay_x                          0x675070
#define EqSoundManager__WaveInstancePlay_x                         0x6745E0

// CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x51F050

// CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x948E50

// CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x556AA0
#define CAltAbilityData__GetMercMaxRank_x                          0x556A40
#define CAltAbilityData__GetMaxRank_x                              0x54C1F0

// CTargetRing
#define CTargetRing__Cast_x                                        0x6084D0

// CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C7180
#define CharacterBase__CreateItemGlobalIndex_x                     0x504F60
#define CharacterBase__CreateItemIndex_x                           0x610610
#define CharacterBase__GetItemPossession_x                         0x4F0B70
#define CharacterBase__GetItemByGlobalIndex_x                      0x8D1BD0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8D1C30

// CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6EE960
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6EF190
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6EF240

// messages
#define msg_spell_worn_off_x                                       0x58C3D0
#define msg_new_text_x                                             0x581200
#define __msgTokenTextParam_x                                      0x58E8F0
#define msgTokenText_x                                             0x58EB40

// SpellManager
#define SpellManager__vftable_x                                    0xAC9CB8
#define SpellManager__SpellManager_x                               0x6783A0
#define Spellmanager__LoadTextSpells_x                             0x678CA0
#define SpellManager__GetSpellByGroupAndRank_x                     0x678570

// CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9913B0

// ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C9EE0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8CA160

// CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x75E670

// CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x70BD70
#define CCursorAttachment__AttachToCursor1_x                       0x70BDB0
#define CCursorAttachment__Deactivate_x                            0x70CD90

// CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x958D50
#define CEQSuiteTextureLoader__GetTexture_x                        0x958A10

// CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x502500
#define CFindItemWnd__WndNotification_x                            0x502FE0
#define CFindItemWnd__Update_x                                     0x503B50
#define CFindItemWnd__PickupSelectedItem_x                         0x501D70

// IString
#define IString__Append_x                                          0x4F2240

// Camera
#define CDisplay__cameraType_x                                     0xDDC978
#define EverQuest__Cameras_x                                       0xEA03D8

// LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x50AE80
#define LootFiltersManager__GetItemFilterData_x                    0x50A770
#define LootFiltersManager__RemoveItemLootFilter_x                 0x50A7A0
#define LootFiltersManager__SetItemLootFilter_x                    0x50A9C0

// COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B8E50

// CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x997040
#define CResolutionHandler__GetWindowedStyle_x                     0x66F8B0

// CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x704390

// CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8DC7B0
#define CDistillerInfo__Instance_x                                 0x8DC750

// CGroupWnd
#define CGroupWnd__WndNotification_x                               0x7246A0
#define CGroupWnd__UpdateDisplay_x                                 0x723A10

// ItemBase
#define ItemBase__IsLore_x                                         0x89F9C0
#define ItemBase__IsLoreEquipped_x                                 0x89FA30

// EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5C7760
#define EQPlacedItemManager__GetItemByGuid_x                       0x5C78A0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5C7900

// RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x664D60
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x668710

// CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x4F88C0

// FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4E7C00
#define FactionManagerClient__HandleFactionMessage_x               0x4E8270
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4E8860
#define FactionManagerClient__GetMaxFaction_x                      0x4E88B0
#define FactionManagerClient__GetMinFaction_x                      0x4E8830

// BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4F0B40

// ArrayClass
#define ArrayClass__DeleteElement_x                                0x920460

// AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x497590

// ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4F0E90

// MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x555F90

// CTargetManager
#define CTargetManager__Get_x                                      0x67BC80

// RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x664D60

// CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A6980

// EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x59ABB0

// EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF3DA68
