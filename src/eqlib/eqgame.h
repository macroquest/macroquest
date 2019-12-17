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
#define __ExpectedVersionDate                                     "Nov 18 2019"
#define __ExpectedVersionTime                                     "19:01:07"
#define __ActualVersionDate_x                                      0xAF3DDC
#define __ActualVersionTime_x                                      0xAF3DD0
#define __ActualVersionBuild_x                                     0xADF9F4

// Memory Protection
#define __MemChecker0_x                                            0x61DDF0
#define __MemChecker1_x                                            0x8EF240
#define __MemChecker2_x                                            0x6AC5F0
#define __MemChecker3_x                                            0x6AC540
#define __MemChecker4_x                                            0x848930
#define __EncryptPad0_x                                            0xC27A40
#define __EncryptPad1_x                                            0xC85B18
#define __EncryptPad2_x                                            0xC382D8
#define __EncryptPad3_x                                            0xC37ED8
#define __EncryptPad4_x                                            0xC761F8
#define __EncryptPad5_x                                            0xF4ED54
#define __AC1_x                                                    0x805276
#define __AC2_x                                                    0x5D798F
#define __AC3_x                                                    0x5DF08F
#define __AC4_x                                                    0x5E3060
#define __AC5_x                                                    0x5E936F
#define __AC6_x                                                    0x5ED986
#define __AC7_x                                                    0x5D7410
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1AE114

// Direct Input
#define DI8__Main_x                                                0xF4ED74
#define DI8__Keyboard_x                                            0xF4ED78
#define DI8__Mouse_x                                               0xF4ED90
#define DI8__Mouse_Copy_x                                          0xEAA424
#define DI8__Mouse_Check_x                                         0xF4F840
#define __AutoSkillArray_x                                         0xEAB33C
#define __Attack_x                                                 0xF4915F
#define __Autofire_x                                               0xF49160
#define __BindList_x                                               0xC16490
#define g_eqCommandStates_x                                        0xC17208
#define __Clicks_x                                                 0xEAA4DC
#define __CommandList_x                                            0xC17DC8
#define __CurrentMapLabel_x                                        0xF61BDC
#define __CurrentSocial_x                                          0xC007CC
#define __DoAbilityList_x                                          0xEE0C80
#define __do_loot_x                                                0x5A3C50
#define __DrawHandler_x                                            0x15DE580
#define __GroupCount_x                                             0xE9C88A
#define __Guilds_x                                                 0xEA0C30
#define __gWorld_x                                                 0xE9C868
#define __HWnd_x                                                   0xF4ED94
#define __heqmain_x                                                0xF51CD4
#define __InChatMode_x                                             0xEAA40C
#define __LastTell_x                                               0xEAC37C
#define __LMouseHeldTime_x                                         0xEAA548
#define __Mouse_x                                                  0xF4ED60
#define __MouseLook_x                                              0xEAA4A2
#define __MouseEventTime_x                                         0xF49C44
#define __gpbCommandEvent_x                                        0xE9CA80
#define __NetStatusToggle_x                                        0xEAA4A5
#define __PCNames_x                                                0xEAB92C
#define __RangeAttackReady_x                                       0xEAB620
#define __RMouseHeldTime_x                                         0xEAA544
#define __RunWalkState_x                                           0xEAA410
#define __ScreenMode_x                                             0xDE80F4
#define __ScreenX_x                                                0xEAA3C4
#define __ScreenY_x                                                0xEAA3C0
#define __ScreenXMax_x                                             0xEAA3C8
#define __ScreenYMax_x                                             0xEAA3CC
#define __ServerHost_x                                             0xE9CCB3
#define __ServerName_x                                             0xEE0C40
#define __ShiftKeyDown_x                                           0xEAAA9C
#define __ShowNames_x                                              0xEAB7DC
#define __Socials_x                                                0xEE0D40
#define __SubscriptionType_x                                       0xFA3730
#define __TargetAggroHolder_x                                      0xF64590
#define __ZoneType_x                                               0xEAA8A0
#define __GroupAggro_x                                             0xF645D0
#define __LoginName_x                                              0xF4F4D4
#define __Inviter_x                                                0xF490DC
#define __AttackOnAssist_x                                         0xEAB798
#define __UseTellWindows_x                                         0xEABAC8
#define __gfMaxZoomCameraDistance_x                                0xAE9730
#define __gfMaxCameraDistance_x                                    0xB15C7C
#define __pulAutoRun_x                                             0xEAA4C0
#define __pulForward_x                                             0xEABB00
#define __pulBackward_x                                            0xEABB04
#define __pulTurnRight_x                                           0xEABB08
#define __pulTurnLeft_x                                            0xEABB0C
#define __pulStrafeLeft_x                                          0xEABB10
#define __pulStrafeRight_x                                         0xEABB14

////
//Section 1: Vital Offsets
////
#define instCRaid_x                                                0xE9CFC8
#define instEQZoneInfo_x                                           0xEAA698
#define pinstActiveBanker_x                                        0xE9CA98
#define pinstActiveCorpse_x                                        0xE9CA90
#define pinstActiveGMaster_x                                       0xE9CA94
#define pinstActiveMerchant_x                                      0xE9CA8C
#define pinstAltAdvManager_x                                       0xDE92A0
#define pinstBandageTarget_x                                       0xE9CAA8
#define pinstCamActor_x                                            0xDE80E8
#define pinstCDBStr_x                                              0xDE7FC4
#define pinstCDisplay_x                                            0xE9C80C
#define pinstCEverQuest_x                                          0xF4ED98
#define pinstEverQuestInfo_x                                       0xEAA3B8
#define pinstCharData_x                                            0xE9C86C
#define pinstCharSpawn_x                                           0xE9CB60
#define pinstControlledMissile_x                                   0xE9A6B8
#define pinstControlledPlayer_x                                    0xE9CB60
#define pinstCResolutionHandler_x                                  0x15DE7B0
#define pinstCSidlManager_x                                        0x15DD748
#define pinstCXWndManager_x                                        0x15DD744
#define instDynamicZone_x                                          0xEA0B08
#define pinstDZMember_x                                            0xEA0C18
#define pinstDZTimerInfo_x                                         0xEA0C1C
#define pinstEqLogin_x                                             0xF4EE20
#define instEQMisc_x                                               0xDE7F08
#define pinstEQSoundManager_x                                      0xDEA1C8
#define pinstEQSpellStrings_x                                      0xCAACA8
#define instExpeditionLeader_x                                     0xEA0B52
#define instExpeditionName_x                                       0xEA0B92
#define pinstGroup_x                                               0xE9C886
#define pinstImeManager_x                                          0x15DD740
#define pinstLocalPlayer_x                                         0xE9CA88
#define pinstMercenaryData_x                                       0xF4B72C
#define pinstMercenaryStats_x                                      0xF646DC
#define pinstModelPlayer_x                                         0xE9CAA0
#define pinstPCData_x                                              0xE9C86C
#define pinstSkillMgr_x                                            0xF4D898
#define pinstSpawnManager_x                                        0xF4C340
#define pinstSpellManager_x                                        0xF4DAB8
#define pinstSpellSets_x                                           0xF41D88
#define pinstStringTable_x                                         0xE9C870
#define pinstSwitchManager_x                                       0xE9A568
#define pinstTarget_x                                              0xE9CADC
#define pinstTargetObject_x                                        0xE9CB68
#define pinstTargetSwitch_x                                        0xE9C6C0
#define pinstTaskMember_x                                          0xDE7D98
#define pinstTrackTarget_x                                         0xE9CB64
#define pinstTradeTarget_x                                         0xE9CA9C
#define instTributeActive_x                                        0xDE7F29
#define pinstViewActor_x                                           0xDE80E4
#define pinstWorldData_x                                           0xE9C6CC
#define pinstZoneAddr_x                                            0xEAA938
#define pinstPlayerPath_x                                          0xF4C3D8
#define pinstTargetIndicator_x                                     0xF4DD20
#define EQObject_Top_x                                             0xE9CA84

////
//Section 2:  UI Related Offsets
////
#define pinstCAAWnd_x                                              0xDE816C
#define pinstCAchievementsWnd_x                                    0xDE810C
#define pinstCActionsWnd_x                                         0xDE8128
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDE88E4
#define pinstCAdvancedLootWnd_x                                    0xDE841C
#define pinstCAdventureLeaderboardWnd_x                            0xF5B3B0
#define pinstCAdventureRequestWnd_x                                0xF5B460
#define pinstCAdventureStatsWnd_x                                  0xF5B510
#define pinstCAggroMeterWnd_x                                      0xDE80A4
#define pinstCAlarmWnd_x                                           0xDE83DC
#define pinstCAlertHistoryWnd_x                                    0xDE8414
#define pinstCAlertStackWnd_x                                      0xDE817C
#define pinstCAlertWnd_x                                           0xDE8194
#define pinstCAltStorageWnd_x                                      0xF5B870
#define pinstCAudioTriggersWindow_x                                0xC9CFD8
#define pinstCAuraWnd_x                                            0xDE8078
#define pinstCAvaZoneWnd_x                                         0xDE83B0
#define pinstCBandolierWnd_x                                       0xDE809C
#define pinstCBankWnd_x                                            0xDE8074
#define pinstCBarterMerchantWnd_x                                  0xF5CAB0
#define pinstCBarterSearchWnd_x                                    0xF5CB60
#define pinstCBarterWnd_x                                          0xF5CC10
#define pinstCBazaarConfirmationWnd_x                              0xDE8138
#define pinstCBazaarSearchWnd_x                                    0xDE8104
#define pinstCBazaarWnd_x                                          0xDE83C8
#define pinstCBlockedBuffWnd_x                                     0xDE807C
#define pinstCBlockedPetBuffWnd_x                                  0xDE8098
#define pinstCBodyTintWnd_x                                        0xDE813C
#define pinstCBookWnd_x                                            0xDE80C0
#define pinstCBreathWnd_x                                          0xDE818C
#define pinstCBuffWindowNORMAL_x                                   0xDE8064
#define pinstCBuffWindowSHORT_x                                    0xDE8068
#define pinstCBugReportWnd_x                                       0xDE8070
#define pinstCButtonWnd_x                                          0x15DD9B0
#define pinstCCastingWnd_x                                         0xDE80B0
#define pinstCCastSpellWnd_x                                       0xDE8180
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDE83CC
#define pinstCChatWindowManager_x                                  0xF5D6D0
#define pinstCClaimWnd_x                                           0xF5D828
#define pinstCColorPickerWnd_x                                     0xDE8134
#define pinstCCombatAbilityWnd_x                                   0xDE83D8
#define pinstCCombatSkillsSelectWnd_x                              0xDE83FC
#define pinstCCompassWnd_x                                         0xDE8130
#define pinstCConfirmationDialog_x                                 0xF62728
#define pinstCContainerMgr_x                                       0xDE83C0
#define pinstCContextMenuManager_x                                 0x15DD700
#define pinstCCursorAttachment_x                                   0xDE80A8
#define pinstCDynamicZoneWnd_x                                     0xF5DDF0
#define pinstCEditLabelWnd_x                                       0xDE88F0
#define pinstCEQMainWnd_x                                          0xF5E038
#define pinstCEventCalendarWnd_x                                   0xDE8060
#define pinstCExtendedTargetWnd_x                                  0xDE8090
#define pinstCFacePick_x                                           0xDE8410
#define pinstCFactionWnd_x                                         0xDE83B8
#define pinstCFellowshipWnd_x                                      0xF5E238
#define pinstCFileSelectionWnd_x                                   0xDE80AC
#define pinstCFindItemWnd_x                                        0xDE83A8
#define pinstCFindLocationWnd_x                                    0xF5E390
#define pinstCFriendsWnd_x                                         0xDE8418
#define pinstCGemsGameWnd_x                                        0xDE83B4
#define pinstCGiveWnd_x                                            0xDE83E0
#define pinstCGroupSearchFiltersWnd_x                              0xDE80B8
#define pinstCGroupSearchWnd_x                                     0xF5E788
#define pinstCGroupWnd_x                                           0xF5E838
#define pinstCGuildBankWnd_x                                       0xEAB77C
#define pinstCGuildCreationWnd_x                                   0xF5E998
#define pinstCGuildMgmtWnd_x                                       0xF5EA48
#define pinstCharacterCreation_x                                   0xDE8404
#define pinstCHelpWnd_x                                            0xDE84D8
#define pinstCHeritageSelectionWnd_x                               0xDE8440
#define pinstCHotButtonWnd_x                                       0xF60BA0
#define pinstCHotButtonWnd1_x                                      0xF60BA0
#define pinstCHotButtonWnd2_x                                      0xF60BA4
#define pinstCHotButtonWnd3_x                                      0xF60BA8
#define pinstCHotButtonWnd4_x                                      0xF60BAC
#define pinstCIconSelectionWnd_x                                   0xDE80A0
#define pinstCInspectWnd_x                                         0xDE84D4
#define pinstCInventoryWnd_x                                       0xDE8444
#define pinstCInvSlotMgr_x                                         0xDE8164
#define pinstCItemDisplayManager_x                                 0xF61130
#define pinstCItemExpTransferWnd_x                                 0xF61264
#define pinstCItemOverflowWnd_x                                    0xDE8108
#define pinstCJournalCatWnd_x                                      0xDE80CC
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDE808C
#define pinstCKeyRingWnd_x                                         0xDE88EC
#define pinstCLargeDialogWnd_x                                     0xF633A8
#define pinstCLayoutCopyWnd_x                                      0xF615B0
#define pinstCLFGuildWnd_x                                         0xF61660
#define pinstCLoadskinWnd_x                                        0xDE83C4
#define pinstCLootFiltersCopyWnd_x                                 0xCB92A0
#define pinstCLootFiltersWnd_x                                     0xDE8184
#define pinstCLootSettingsWnd_x                                    0xDE81A4
#define pinstCLootWnd_x                                            0xDE80D0
#define pinstCMailAddressBookWnd_x                                 0xDE8170
#define pinstCMailCompositionWnd_x                                 0xDE8150
#define pinstCMailIgnoreListWnd_x                                  0xDE8174
#define pinstCMailWnd_x                                            0xDE812C
#define pinstCManageLootWnd_x                                      0xDE9750
#define pinstCMapToolbarWnd_x                                      0xDE84DC
#define pinstCMapViewWnd_x                                         0xDE8450
#define pinstCMarketplaceWnd_x                                     0xDE8190
#define pinstCMerchantWnd_x                                        0xDE80D4
#define pinstCMIZoneSelectWnd_x                                    0xF61E98
#define pinstCMusicPlayerWnd_x                                     0xDE80E0
#define pinstCNameChangeMercWnd_x                                  0xDE8124
#define pinstCNameChangePetWnd_x                                   0xDE8110
#define pinstCNameChangeWnd_x                                      0xDE8144
#define pinstCNoteWnd_x                                            0xDE8454
#define pinstCObjectPreviewWnd_x                                   0xDE81A0
#define pinstCOptionsWnd_x                                         0xDE8458
#define pinstCPetInfoWnd_x                                         0xDE8114
#define pinstCPetitionQWnd_x                                       0xDE80DC
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDE8140
#define pinstCPlayerWnd_x                                          0xDE8118
#define pinstCPopupWndManager_x                                    0xF62728
#define pinstCProgressionSelectionWnd_x                            0xF627D8
#define pinstCPurchaseGroupWnd_x                                   0xDE83E8
#define pinstCPurchaseWnd_x                                        0xDE83BC
#define pinstCPvPLeaderboardWnd_x                                  0xF62888
#define pinstCPvPStatsWnd_x                                        0xF62938
#define pinstCQuantityWnd_x                                        0xDE8094
#define pinstCRaceChangeWnd_x                                      0xDE8168
#define pinstCRaidOptionsWnd_x                                     0xDE80BC
#define pinstCRaidWnd_x                                            0xDE8154
#define pinstCRealEstateItemsWnd_x                                 0xDE8100
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDE8080
#define pinstCRealEstateManageWnd_x                                0xDE83F0
#define pinstCRealEstateNeighborhoodWnd_x                          0xDE840C
#define pinstCRealEstatePlotSearchWnd_x                            0xDE8448
#define pinstCRealEstatePurchaseWnd_x                              0xDE846C
#define pinstCRespawnWnd_x                                         0xDE8088
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDE8178
#define pinstCSendMoneyWnd_x                                       0xDE83F8
#define pinstCServerListWnd_x                                      0xDE88F4
#define pinstCSkillsSelectWnd_x                                    0xDE83D4
#define pinstCSkillsWnd_x                                          0xDE83AC
#define pinstCSocialEditWnd_x                                      0xDE88E8
#define pinstCSocialWnd_x                                          0xDE8120
#define pinstCSpellBookWnd_x                                       0xDE83D0
#define pinstCStoryWnd_x                                           0xDE811C
#define pinstCTargetOfTargetWnd_x                                  0xF64760
#define pinstCTargetWnd_x                                          0xDE8084
#define pinstCTaskOverlayWnd_x                                     0xDE83E4
#define pinstCTaskSelectWnd_x                                      0xF648B8
#define pinstCTaskManager_x                                        0xCB9BE0
#define pinstCTaskTemplateSelectWnd_x                              0xF64968
#define pinstCTaskWnd_x                                            0xF64A18
#define pinstCTextEntryWnd_x                                       0xDE806C
#define pinstCTimeLeftWnd_x                                        0xDE80B4
#define pinstCTipWndCONTEXT_x                                      0xF64C1C
#define pinstCTipWndOFDAY_x                                        0xF64C18
#define pinstCTitleWnd_x                                           0xF64CC8
#define pinstCTrackingWnd_x                                        0xDE844C
#define pinstCTradeskillWnd_x                                      0xF64E30
#define pinstCTradeWnd_x                                           0xDE814C
#define pinstCTrainWnd_x                                           0xDE8148
#define pinstCTributeBenefitWnd_x                                  0xF65030
#define pinstCTributeMasterWnd_x                                   0xF650E0
#define pinstCTributeTrophyWnd_x                                   0xF65190
#define pinstCVideoModesWnd_x                                      0xDE819C
#define pinstCVoiceMacroWnd_x                                      0xF4E488
#define pinstCVoteResultsWnd_x                                     0xDE80D8
#define pinstCVoteWnd_x                                            0xDE80C8
#define pinstCWebManager_x                                         0xF4EB04
#define pinstCZoneGuideWnd_x                                       0xDE83EC
#define pinstCZonePathWnd_x                                        0xDE8400

#define pinstEQSuiteTextureLoader_x                                0xC875F0
#define pinstItemIconCache_x                                       0xF5DFF0
#define pinstLootFiltersManager_x                                  0xCB9350
#define pinstRewardSelectionWnd_x                                  0xF63080

////
// Section 3: Miscellaneous Offsets
////
#define __CastRay_x                                                0x59F0B0
#define __CastRay2_x                                               0x59F100
#define __ConvertItemTags_x                                        0x5BAC60
#define __CleanItemTags_x                                          0x47CA50
#define __DoesFileExist_x                                          0x8F22D0
#define __EQGetTime_x                                              0x8EED10
#define __ExecuteCmd_x                                             0x5979F0
#define __FixHeading_x                                             0x989B80
#define __GameLoop_x                                               0x6AB7E0
#define __get_bearing_x                                            0x59EC20
#define __get_melee_range_x                                        0x59F2F0
#define __GetAnimationCache_x                                      0x710CB0
#define __GetGaugeValueFromEQ_x                                    0x803720
#define __GetLabelFromEQ_x                                         0x805200
#define __GetXTargetType_x                                         0x98B6A0
#define __HandleMouseWheel_x                                       0x6AC6A0
#define __HeadingDiff_x                                            0x989BF0
#define __HelpPath_x                                               0xF49834
#define __LoadFrontEnd_x                                           0x6A8B00
#define __NewUIINI_x                                               0x8033F0
#define __ProcessGameEvents_x                                      0x5FF200
#define __ProcessMouseEvent_x                                      0x5FE9C0
#define __SaveColors_x                                             0x547BC0
#define __STMLToText_x                                             0x92D230
#define __ToggleKeyRingItem_x                                      0x50B270
#define CMemoryMappedFile__SetFile_x                               0xA78EE0
#define CrashDetected_x                                            0x6AA5A0
#define DrawNetStatus_x                                            0x62B2A0
#define Expansion_HoT_x                                            0xEAB784
#define Teleport_Table_Size_x                                      0xE9CB70
#define Teleport_Table_x                                           0xE9A6C0
#define Util__FastTime_x                                           0x8EE8E0
#define __eq_delete_x                                              0x9920AE
#define __eq_new_x                                                 0x992664

////
// Section 4: Function Offsets
////
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48FD80
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x498C90
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x498A60
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493320
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492770

// AltAdvManager
#define AltAdvManager__GetCalculatedTimer_x                        0x54F720
#define AltAdvManager__IsAbilityReady_x                            0x54E650
#define AltAdvManager__GetAAById_x                                 0x54E850
#define AltAdvManager__CanTrainAbility_x                           0x54E8C0
#define AltAdvManager__CanSeeAbility_x                             0x54EC20

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C9C50
#define CharacterZoneClient__HasSkill_x                            0x4D4B40
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6260
#define CharacterZoneClient__IsStackBlocked_x                      0x4BDF20
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BA520
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8BF0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D8CD0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D8DB0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C2D10
#define CharacterZoneClient__BardCastBard_x                        0x4C5870
#define CharacterZoneClient__GetMaxEffects_x                       0x4BA5F0
#define CharacterZoneClient__GetEffect_x                           0x4BA460
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C3D60
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C3E30
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C3E80
#define CharacterZoneClient__CalcAffectChange_x                    0x4C3FD0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C41A0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B23F0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D71C0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D6C40

// CBankWnd
#define CBankWnd__GetNumBankSlots_x                                0x6D2200
#define CBankWnd__WndNotification_x                                0x6D1FE0

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6DF9B0

// CButtonWnd
#define CButtonWnd__SetCheck_x                                     0x60DC70
#define CButtonWnd__CButtonWnd_x                                   0x9295E0
#define CButtonWnd__dCButtonWnd_x                                  0x9298C0
#define CButtonWnd__vftable_x                                      0xB2E458

// CChatWindowManager
#define CChatWindowManager__GetRGBAFromIndex_x                     0x6FFCE0
#define CChatWindowManager__InitContextMenu_x                      0x6F8E30
#define CChatWindowManager__FreeChatWindow_x                       0x6FE820
#define CChatWindowManager__GetLockedActiveChatWindow_x            0x4E82F0
#define CChatWindowManager__SetLockedActiveChatWindow_x            0x6FF960
#define CChatWindowManager__CreateChatWindow_x                     0x6FEE60

// ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8400

// CChatWindow
#define CChatWindow__CChatWindow_x                                 0x7005F0
#define CChatWindow__Clear_x                                       0x7018C0
#define CChatWindow__WndNotification_x                             0x702050
#define CChatWindow__AddHistory_x                                  0x701180

// CContextMenu
#define CContextMenu__CContextMenu_x                               0x93DBB0
#define CContextMenu__dCContextMenu_x                              0x93DDE0
#define CContextMenu__AddMenuItem_x                                0x93DDF0
#define CContextMenu__RemoveMenuItem_x                             0x93E100
#define CContextMenu__RemoveAllMenuItems_x                         0x93E120
#define CContextMenu__CheckMenuItem_x                              0x93E1A0
#define CContextMenu__SetMenuItem_x                                0x93E020
#define CContextMenu__AddSeparator_x                               0x93DF80

// CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x93E740
#define CContextMenuManager__RemoveMenu_x                          0x93E7B0
#define CContextMenuManager__PopupMenu_x                           0x93E870
#define CContextMenuManager__Flush_x                               0x93E6E0
#define CContextMenuManager__GetMenu_x                             0x49AE30
#define CContextMenuManager__CreateDefaultMenu_x                   0x70B4D0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8CCAB0
#define CChatService__GetFriendName_x                              0x8CCAC0

// CComboWnd
#define CComboWnd__DeleteAll_x                                     0x93B000
#define CComboWnd__Draw_x                                          0x93A4E0
#define CComboWnd__GetCurChoice_x                                  0x93AE40
#define CComboWnd__GetListRect_x                                   0x93A9A0
#define CComboWnd__GetTextRect_x                                   0x93B070
#define CComboWnd__InsertChoice_x                                  0x93AB30
#define CComboWnd__SetColors_x                                     0x93AB00
#define CComboWnd__SetChoice_x                                     0x93AE10
#define CComboWnd__GetItemCount_x                                  0x93AE50
#define CComboWnd__GetCurChoiceText_x                              0x93AE90
#define CComboWnd__GetChoiceText_x                                 0x93AE60
#define CComboWnd__InsertChoiceAtIndex_x                           0x93ABD0

// CContainerWnd
#define CContainerWnd__HandleCombine_x                             0x708EB0
#define CContainerWnd__vftable_x                                   0xAFCFE4
#define CContainerWnd__SetContainer_x                              0x70A420

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x542660
#define CDisplay__PreZoneMainUI_x                                  0x542670
#define CDisplay__CleanGameUI_x                                    0x547980
#define CDisplay__GetClickedActor_x                                0x53A980
#define CDisplay__GetUserDefinedColor_x                            0x533040
#define CDisplay__GetWorldFilePath_x                               0x53C3F0
#define CDisplay__is3dON_x                                         0x5375E0
#define CDisplay__ReloadUI_x                                       0x541AF0
#define CDisplay__WriteTextHD2_x                                   0x5373D0
#define CDisplay__TrueDistance_x                                   0x53E0B0
#define CDisplay__SetViewActor_x                                   0x53A2A0
#define CDisplay__GetFloorHeight_x                                 0x5376A0
#define CDisplay__SetRenderWindow_x                                0x536000
#define CDisplay__ToggleScreenshotMode_x                           0x539D70

// CEditBaseWnd
#define CEditBaseWnd__SetSel_x                                     0x95D770

// CEditWnd
#define CEditWnd__DrawCaret_x                                      0x941120
#define CEditWnd__GetCharIndexPt_x                                 0x942050
#define CEditWnd__GetDisplayString_x                               0x941EF0
#define CEditWnd__GetHorzOffset_x                                  0x940750
#define CEditWnd__GetLineForPrintableChar_x                        0x9431F0
#define CEditWnd__GetSelStartPt_x                                  0x942300
#define CEditWnd__GetSTMLSafeText_x                                0x941D10
#define CEditWnd__PointFromPrintableChar_x                         0x942E20
#define CEditWnd__SelectableCharFromPoint_x                        0x942F90
#define CEditWnd__SetEditable_x                                    0x9423D0
#define CEditWnd__SetWindowTextA_x                                 0x941A90
#define CEditWnd__ReplaceSelection_x                               0x942A90

// CEverQuest
#define CEverQuest__DoPercentConvert_x                             0x5ECE60
#define CEverQuest__ClickedPlayer_x                                0x5DEE70
#define CEverQuest__CreateTargetIndicator_x                        0x5FC490
#define CEverQuest__DeleteTargetIndicator_x                        0x5FC520
#define CEverQuest__DoTellWindow_x                                 0x4E84E0
#define CEverQuest__OutputTextToLog_x                              0x4E8760
#define CEverQuest__DropHeldItemOnGround_x                         0x5D3EC0
#define CEverQuest__dsp_chat_x                                     0x4E8AF0
#define CEverQuest__trimName_x                                     0x5F8770
#define CEverQuest__Emote_x                                        0x5ED6C0
#define CEverQuest__EnterZone_x                                    0x5E7640
#define CEverQuest__GetBodyTypeDesc_x                              0x5F2030
#define CEverQuest__GetClassDesc_x                                 0x5F2670
#define CEverQuest__GetClassThreeLetterCode_x                      0x5F2C70
#define CEverQuest__GetDeityDesc_x                                 0x5FADD0
#define CEverQuest__GetLangDesc_x                                  0x5F2E30
#define CEverQuest__GetRaceDesc_x                                  0x5F2650
#define CEverQuest__InterpretCmd_x                                 0x5FB3A0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5D80B0
#define CEverQuest__LMouseUp_x                                     0x5D6450
#define CEverQuest__RightClickedOnPlayer_x                         0x5D8990
#define CEverQuest__RMouseUp_x                                     0x5D73D0
#define CEverQuest__SetGameState_x                                 0x5D3C50
#define CEverQuest__UPCNotificationFlush_x                         0x5F8670
#define CEverQuest__IssuePetCommand_x                              0x5F4230
#define CEverQuest__ReportSuccessfulHit_x                          0x5EEAB0

// CGaugeWnd
// not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x71AE80
#define CGaugeWnd__CalcLinesFillRect_x                             0x71AEE0
#define CGaugeWnd__Draw_x                                          0x71A500

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AEE20
#define CGuild__GetGuildName_x                                     0x4ADF00
#define CGuild__GetGuildIndex_x                                    0x4AE290

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton_x                               0x736380

//CHotButton
#define CHotButton__SetButtonSize_x                                0x60E030

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot_x                                 0x743340
#define CInvSlotMgr__MoveItem_x                                    0x742070
#define CInvSlotMgr__SelectSlot_x                                  0x743410

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x740920
#define CInvSlot__SliderComplete_x                                 0x73E6A0
#define CInvSlot__GetItemBase_x                                    0x73E010
#define CInvSlot__UpdateItem_x                                     0x73E180

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x744E90
#define CInvSlotWnd__CInvSlotWnd_x                                 0x744030
#define CInvSlotWnd__HandleLButtonUp_x                             0x744A10

// CItemDisplayWnd
#define CItemDisplayWnd__SetSpell_x                                0x7FEA70
#define CItemDisplayWnd__UpdateStrings_x                           0x7535D0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x74D290
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x74D7C0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x753BD0
#define CItemDisplayWnd__AboutToShow_x                             0x753210
#define CItemDisplayWnd__WndNotification_x                         0x754CC0
#define CItemDisplayWnd__RequestConvertItem_x                      0x754780
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x752280
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x753030

// CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x837590

// CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x7591D0

// CLabel
#define CLabel__Draw_x                                             0x75EBC0

// CListWnd
#define CListWnd__CListWnd_x                                       0x913890
#define CListWnd__dCListWnd_x                                      0x913BB0
#define CListWnd__vftable_x                                        0xB2DD28
#define CListWnd__AddColumn_x                                      0x918000
#define CListWnd__AddColumn1_x                                     0x918050
#define CListWnd__AddLine_x                                        0x9183E0
#define CListWnd__AddString_x                                      0x9181E0
#define CListWnd__CalculateFirstVisibleLine_x                      0x917DC0
#define CListWnd__CalculateVSBRange_x                              0x917BA0
#define CListWnd__ClearSel_x                                       0x918BC0
#define CListWnd__ClearAllSel_x                                    0x918C20
#define CListWnd__CloseAndUpdateEditWindow_x                       0x919640
#define CListWnd__Compare_x                                        0x9174E0
#define CListWnd__Draw_x                                           0x913CE0
#define CListWnd__DrawColumnSeparators_x                           0x9164C0
#define CListWnd__DrawHeader_x                                     0x916920
#define CListWnd__DrawItem_x                                       0x916E20
#define CListWnd__DrawLine_x                                       0x916620
#define CListWnd__DrawSeparator_x                                  0x916560
#define CListWnd__EnableLine_x                                     0x915DA0
#define CListWnd__EnsureVisible_x                                  0x919560
#define CListWnd__ExtendSel_x                                      0x918AF0
#define CListWnd__GetColumnTooltip_x                               0x9158E0
#define CListWnd__GetColumnMinWidth_x                              0x915950
#define CListWnd__GetColumnWidth_x                                 0x915850
#define CListWnd__GetCurSel_x                                      0x9151E0
#define CListWnd__GetItemAtPoint_x                                 0x916010
#define CListWnd__GetItemAtPoint1_x                                0x916080
#define CListWnd__GetItemData_x                                    0x915260
#define CListWnd__GetItemHeight_x                                  0x915620
#define CListWnd__GetItemIcon_x                                    0x9153F0
#define CListWnd__GetItemRect_x                                    0x915E90
#define CListWnd__GetItemText_x                                    0x9152A0
#define CListWnd__GetSelList_x                                     0x918C70
#define CListWnd__GetSeparatorRect_x                               0x9162C0
#define CListWnd__InsertLine_x                                     0x9187D0
#define CListWnd__RemoveLine_x                                     0x918920
#define CListWnd__SetColors_x                                      0x917B70
#define CListWnd__SetColumnJustification_x                         0x9178B0
#define CListWnd__SetColumnWidth_x                                 0x9177D0
#define CListWnd__SetCurSel_x                                      0x918A30
#define CListWnd__SetItemColor_x                                   0x919210
#define CListWnd__SetItemData_x                                    0x9191D0
#define CListWnd__SetItemText_x                                    0x918DE0
#define CListWnd__ShiftColumnSeparator_x                           0x917970
#define CListWnd__Sort_x                                           0x917660
#define CListWnd__ToggleSel_x                                      0x918A60
#define CListWnd__SetColumnsSizable_x                              0x917A10
#define CListWnd__SetItemWnd_x                                     0x919090
#define CListWnd__GetItemWnd_x                                     0x915440
#define CListWnd__SetItemIcon_x                                    0x918E60
#define CListWnd__CalculateCustomWindowPositions_x                 0x917EC0
#define CListWnd__SetVScrollPos_x                                  0x9177B0

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd_x                                 0x774340

// MapViewMap
#define MapViewMap__MapViewMap_x                                   0x76F830
#define MapViewMap__dMapViewMap_x                                  0x76F980
#define MapViewMap__vftable_x                                      0xB047D0
#define MapViewMap__Clear_x                                        0x7701B0
#define MapViewMap__SaveEx_x                                       0x773570
#define MapViewMap__SetZoom_x                                      0x777C30
#define MapViewMap__HandleLButtonDown_x                            0x76FA90
#define MapViewMap__GetWorldCoordinates_x                          0x772A50

// CMerchantWnd
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x794470
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x794D50
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x795280
#define CMerchantWnd__SelectRecoverySlot_x                         0x798210
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x792FD0
#define CMerchantWnd__SelectBuySellSlot_x                          0x79DDD0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x794080

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89A650
#define CPacketScrambler__hton_x                                   0x89A640

// CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x936C30
#define CSidlManagerBase__CreatePageWnd_x                          0x936430
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x9326B0
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x932640
#define CSidlManagerBase__FindAnimation1_x                         0x932890
#define CSidlManagerBase__FindScreenPieceTemplate_x                0x932CA0
#define CSidlManagerBase__FindScreenPieceTemplate1_x               0x932A90
#define CSidlManagerBase__CreateLabel_x                            0x7F5E90
#define CSidlManagerBase__CreateXWndFromTemplate_x                 0x935C00
#define CSidlManagerBase__CreateXWndFromTemplate1_x                0x935DE0
#define CSidlManagerBase__CreateXWnd_x                             0x7F5DC0

// CSidlManager
#define CSidlManager__CreateHotButtonWnd_x                         0x7F6390

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateHSBRange_x                        0x92F350
#define CSidlScreenWnd__CalculateVSBRange_x                        0x92F250
#define CSidlScreenWnd__ConvertToRes_x                             0x954790
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x92ECE0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x92E9D0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x92EAA0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x92EB70
#define CSidlScreenWnd__DrawSidlPiece_x                            0x92F7F0
#define CSidlScreenWnd__EnableIniStorage_x                         0x92FCC0
#define CSidlScreenWnd__GetChildItem_x                             0x92FC40
#define CSidlScreenWnd__GetSidlPiece_x                             0x92F9E0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x91F490
#define CSidlScreenWnd__Init1_x                                    0x92E5D0
#define CSidlScreenWnd__LoadIniInfo_x                              0x92FD10
#define CSidlScreenWnd__LoadIniListWnd_x                           0x930870
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92D9E0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15DD5D0
#define CSidlScreenWnd__StoreIniInfo_x                             0x9303E0
#define CSidlScreenWnd__StoreIniVis_x                              0x930750
#define CSidlScreenWnd__vftable_x                                  0xB2E6F8
#define CSidlScreenWnd__WndNotification_x                          0x92F700

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6727C0
#define CSkillMgr__GetSkillCap_x                                   0x6729A0
#define CSkillMgr__GetNameToken_x                                  0x671F40
#define CSkillMgr__IsActivatedSkill_x                              0x672080
#define CSkillMgr__IsCombatSkill_x                                 0x671FC0

// CSliderWnd
#define CSliderWnd__GetValue_x                                     0x93F530
#define CSliderWnd__SetValue_x                                     0x93F3A0
#define CSliderWnd__SetNumTicks_x                                  0x93F400

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet_x                               0x7FBF00

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x947D50
#define CStmlWnd__CalculateHSBRange_x                              0x948E70
#define CStmlWnd__CalculateVSBRange_x                              0x948DE0
#define CStmlWnd__CanBreakAtCharacter_x                            0x94D1A0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x94DE30
#define CStmlWnd__ForceParseNow_x                                  0x948340
#define CStmlWnd__GetNextTagPiece_x                                0x94D100
#define CStmlWnd__GetSTMLText_x                                    0x4FAE10
#define CStmlWnd__GetVisibleText_x                                 0x948360
#define CStmlWnd__InitializeWindowVariables_x                      0x94DC80
#define CStmlWnd__MakeStmlColorTag_x                               0x9473C0
#define CStmlWnd__MakeWndNotificationTag_x                         0x947430
#define CStmlWnd__SetSTMLText_x                                    0x946470
#define CStmlWnd__StripFirstSTMLLines_x                            0x94EF00
#define CStmlWnd__UpdateHistoryString_x                            0x94E040

// CTabWnd
#define CTabWnd__Draw_x                                            0x9455C0
#define CTabWnd__DrawCurrentPage_x                                 0x945CF0
#define CTabWnd__DrawTab_x                                         0x945A10
#define CTabWnd__GetCurrentPage_x                                  0x944DC0
#define CTabWnd__GetPageInnerRect_x                                0x945000
#define CTabWnd__GetTabInnerRect_x                                 0x944F40
#define CTabWnd__GetTabRect_x                                      0x944DF0
#define CTabWnd__InsertPage_x                                      0x945210
#define CTabWnd__SetPage_x                                         0x945080
#define CTabWnd__SetPageRect_x                                     0x945500
#define CTabWnd__UpdatePage_x                                      0x9458D0
#define CTabWnd__GetPageFromTabIndex_x                             0x945950
#define CTabWnd__GetCurrentTabIndex_x                              0x944DB0

// CPageWnd
#define CPageWnd__GetTabText_x                                     0x7595A0
#define CPageWnd__SetTabText_x                                     0x944900

// CTextOverlay
#define CTextOverlay__DisplayText_x                                0x4A8AF0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91C350
#define CTextureFont__GetTextExtent_x                              0x91C510

// CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6A59B0
#define CHtmlComponentWnd__ValidateUri_x                           0x737D70
#define CHtmlWnd__SetClientCallbacks_x                             0x6130B0
#define CHtmlWnd__AddObserver_x                                    0x6130D0
#define CHtmlWnd__RemoveObserver_x                                 0x613130
#define Window__getProgress_x                                      0x84FF60
#define Window__getStatus_x                                        0x84FF80
#define Window__getURI_x                                           0x84FF90

// CXMLDataManager
#define CXMLDataManager__GetXMLData_x                              0x95A1C0

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead_x                             0x9093C0

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr_x                                             0x4E8030
#define CXStr__CXStr1_x                                            0x480F40
#define CXStr__CXStr3_x                                            0x8EAE00
#define CXStr__dCXStr_x                                            0x4780C0
#define CXStr__operator_equal_x                                    0x8EB030
#define CXStr__operator_equal1_x                                   0x8EB070
#define CXStr__operator_plus_equal1_x                              0x8EBB00
#define CXStr__SetString_x                                         0x8ED9F0
#define CXStr__operator_char_p_x                                   0x8EB570
#define CXStr__GetChar_x                                           0x8ED340
#define CXStr__Delete_x                                            0x8ECBF0
#define CXStr__GetUnicode_x                                        0x8ED3B0
#define CXStr__GetLength_x                                         0x47CE00
#define CXStr__Mid_x                                               0x47CE10
#define CXStr__Insert_x                                            0x8ED410
#define CXStr__FindNext_x                                          0x8ED060
#define CXStr__gFreeLists_x                                        0xC85A48
#define CXStr__gCXStrAccess_x                                      0x15DCCF4

// CTileLayoutWnd
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93D7C0

// CXWnd
#define CXWnd__BringToTop_x                                        0x922C00
#define CXWnd__Center_x                                            0x922780
#define CXWnd__ClrFocus_x                                          0x9225A0
#define CXWnd__Destroy_x                                           0x922640
#define CXWnd__DoAllDrawing_x                                      0x91EC40
#define CXWnd__DrawChildren_x                                      0x91EC10
#define CXWnd__DrawColoredRect_x                                   0x91F0A0
#define CXWnd__DrawTooltip_x                                       0x91D750
#define CXWnd__DrawTooltipAtPoint_x                                0x91D810
#define CXWnd__GetBorderFrame_x                                    0x91EF00
#define CXWnd__GetChildItem_x                                      0x922E10
#define CXWnd__GetChildWndAt_x                                     0x922CA0
#define CXWnd__GetClientClipRect_x                                 0x920EF0
#define CXWnd__GetScreenClipRect_x                                 0x920FA0
#define CXWnd__GetScreenRect_x                                     0x921120
#define CXWnd__GetTooltipRect_x                                    0x91F0F0
#define CXWnd__GetWindowTextA_x                                    0x49C5B0
#define CXWnd__IsActive_x                                          0x91F810
#define CXWnd__IsDescendantOf_x                                    0x921B20
#define CXWnd__IsReallyVisible_x                                   0x921B50
#define CXWnd__IsType_x                                            0x923310
#define CXWnd__Minimize_x                                          0x922230
#define CXWnd__Move_x                                              0x921BB0
#define CXWnd__Move1_x                                             0x921C60
#define CXWnd__ProcessTransition_x                                 0x922730
#define CXWnd__Refade_x                                            0x921F30
#define CXWnd__Resize_x                                            0x9221C0
#define CXWnd__Right_x                                             0x9229C0
#define CXWnd__SetFocus_x                                          0x922560
#define CXWnd__SetFont_x                                           0x9225D0
#define CXWnd__SetKeyTooltip_x                                     0x923130
#define CXWnd__SetMouseOver_x                                      0x920040
#define CXWnd__SetParent_x                                         0x9218C0
#define CXWnd__StartFade_x                                         0x921A00
#define CXWnd__vftable_x                                           0xB2E174
#define CXWnd__CXWnd_x                                             0x91C830
#define CXWnd__dCXWnd_x                                            0x91CD30

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x955810

// CXWndManager
#define CXWndManager__DrawCursor_x                                 0x925B30
#define CXWndManager__DrawWindows_x                                0x925B50
#define CXWndManager__GetKeyboardFlags_x                           0x928270
#define CXWndManager__HandleKeyboardMsg_x                          0x927E20
#define CXWndManager__RemoveWnd_x                                  0x928490
#define CXWndManager__RemovePendingDeletionWnd_x                   0x928A00

// CDBStr
#define CDBStr__GetString_x                                        0x532000

// CharacterZoneClient
#define CharacterZoneClient__CastSpell_x                           0x4BB500
#define CharacterZoneClient__Cur_HP_x                              0x4D1B80
#define CharacterZoneClient__Cur_Mana_x                            0x4D92B0
#define CharacterZoneClient__GetCastingTimeModifier_x              0x4BE570
#define CharacterZoneClient__GetFocusCastingTimeModifier_x         0x4B2030
#define CharacterZoneClient__GetFocusRangeModifier_x               0x4B2180
#define CharacterZoneClient__GetHPRegen_x                          0x4DF050
#define CharacterZoneClient__GetEnduranceRegen_x                   0x4DF650
#define CharacterZoneClient__GetManaRegen_x                        0x4DFA90
#define CharacterZoneClient__Max_Endurance_x                       0x6392A0
#define CharacterZoneClient__Max_HP_x                              0x4D19B0
#define CharacterZoneClient__Max_Mana_x                            0x6390A0
#define CharacterZoneClient__doCombatAbility_x                     0x63B6F0
#define CharacterZoneClient__UseSkill_x                            0x4E1870
#define CharacterZoneClient__IsExpansionFlag_x                     0x596190
#define CharacterZoneClient__TotalEffect_x                         0x4C4FB0
#define CharacterZoneClient__GetPCSpellAffect_x                    0x4BF2C0
#define CharacterZoneClient__SpellDuration_x                       0x4BEDF0
#define CharacterZoneClient__GetAdjustedSkill_x                    0x4D4900
#define CharacterZoneClient__GetBaseSkill_x                        0x4D58A0
#define CharacterZoneClient__CanUseItem_x                          0x4D95C0

// ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8B9940

// PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x64F7E0

// PcClient
#define PcClient__PcClient_x                                       0x62F930
#define PcClient__GetConLevel_x                                    0x632200

// CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B9170
#define CCharacterListWnd__EnterWorld_x                            0x4B8BB0
#define CCharacterListWnd__Quit_x                                  0x4B8900
#define CCharacterListWnd__UpdateList_x                            0x4B8D40

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6142F0
#define EQ_Item__CreateItemTagString_x                             0x893EF0
#define EQ_Item__IsStackable_x                                     0x8989D0
#define EQ_Item__GetImageNum_x                                     0x895940
#define EQ_Item__CreateItemClient_x                                0x6134B0
#define EQ_Item__GetItemValue_x                                    0x896C30
#define EQ_Item__ValueSellMerchant_x                               0x89A220
#define EQ_Item__IsKeyRingItem_x                                   0x898320
#define EQ_Item__CanGoInBag_x                                      0x614410
#define EQ_Item__IsEmpty_x                                         0x897E80
#define EQ_Item__GetMaxItemCount_x                                 0x897050
#define EQ_Item__GetHeldItem_x                                     0x895810
#define EQ_Item__GetAugmentFitBySlot_x                             0x893860

// EQ_LoadingS
#define EQ_LoadingS__SetProgressBar_x                              0x5504B0
#define EQ_LoadingS__Array_x                                       0xC0F698

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x639BF0
#define EQ_PC__GetAlternateAbilityId_x                             0x8A3400
#define EQ_PC__GetCombatAbility_x                                  0x8A3A70
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A3AE0
#define EQ_PC__GetItemRecastTimer_x                                0x63BC70
#define EQ_PC__HasLoreItem_x                                       0x6329C0
#define EQ_PC__AlertInventoryChanged_x                             0x631B30
#define EQ_PC__GetPcZoneClient_x                                   0x65E230
#define EQ_PC__RemoveMyAffect_x                                    0x63EEA0
#define EQ_PC__GetKeyRingItems_x                                   0x8A4340
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A4100
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A4630

// EQItemList
#define EQItemList__EQItemList_x                                   0x59C6A0
#define EQItemList__add_object_x                                   0x5C96F0
#define EQItemList__add_item_x                                     0x59CC00
#define EQItemList__delete_item_x                                  0x59CC50
#define EQItemList__FreeItemList_x                                 0x59CB50

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x52EB20

// EQPlayer
#define EQPlayer__ChangeBoneStringSprite_x                         0x651060
#define EQPlayer__dEQPlayer_x                                      0x6443B0
#define EQPlayer__DoAttack_x                                       0x658EE0
#define EQPlayer__EQPlayer_x                                       0x644A70
#define EQPlayer__SetNameSpriteState_x                             0x648D40
#define EQPlayer__SetNameSpriteTint_x                              0x649C10
#define PlayerBase__HasProperty_j_x                                0x987F70
#define EQPlayer__IsTargetable_x                                   0x988410
#define EQPlayer__CanSee_x                                         0x988270
#define EQPlayer__CanSee1_x                                        0x988340
#define PlayerBase__GetVisibilityLineSegment_x                     0x988030

// PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x65BCC0
#define PlayerZoneClient__GetLevel_x                               0x65E270
#define PlayerZoneClient__IsValidTeleport_x                        0x5CA860
#define PlayerZoneClient__LegalPlayerRace_x                        0x549810

// EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x653DC0
#define EQPlayerManager__GetSpawnByName_x                          0x653E70
#define EQPlayerManager__GetPlayerFromPartialName_x                0x653F00

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x617980
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x617A00
#define KeypressHandler__AttachKeyToEqCommand_x                    0x617A40
#define KeypressHandler__ClearCommandStateArray_x                  0x618E50
#define KeypressHandler__HandleKeyDown_x                           0x618E70
#define KeypressHandler__HandleKeyUp_x                             0x618F10
#define KeypressHandler__SaveKeymapping_x                          0x619350

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B7860

// StringTable
#define StringTable__getString_x                                   0x8B2640

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x63EB10
#define PcZoneClient__RemovePetEffect_x                            0x63F140
#define PcZoneClient__HasAlternateAbility_x                        0x638ED0
#define PcZoneClient__GetCurrentMod_x                              0x4E4930
#define PcZoneClient__GetModCap_x                                  0x4E4830
#define PcZoneClient__CanEquipItem_x                               0x639590
#define PcZoneClient__GetItemByID_x                                0x63C0E0
#define PcZoneClient__GetItemByItemClass_x                         0x63C230
#define PcZoneClient__RemoveBuffEffect_x                           0x63F160
#define PcZoneClient__BandolierSwap_x                              0x63A1B0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x63BC10

// Doors
#define EQSwitch__UseSwitch_x                                      0x5CF370

// IconCache
#define IconCache__GetIcon_x                                       0x710550

// CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x708010
#define CContainerMgr__CloseContainer_x                            0x7082E0
#define CContainerMgr__OpenExperimentContainer_x                   0x708D60

// CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7C8370

// CHelpWnd
#define CHelpWnd__SetFile_x                                        0x60C450

// CLootWnd
#define CLootWnd__LootAll_x                                        0x7666A0
#define CLootWnd__RequestLootSlot_x                                0x7658D0

// EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x568990
#define EQ_Spell__SpellAffects_x                                   0x568E00
#define EQ_Spell__SpellAffectBase_x                                0x568BC0
#define EQ_Spell__IsStackable_x                                    0x4C95C0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9410
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6520
#define EQ_Spell__IsSPAStacking_x                                  0x569C50
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x569160
#define EQ_Spell__IsNoRemove_x                                     0x4C95A0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x569C60
#define __IsResEffectSpell_x                                       0x4C89F0

// EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4ACBB0

// EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C1F70

// CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x80F1F0
#define CTargetWnd__WndNotification_x                              0x80EA80
#define CTargetWnd__RefreshTargetBuffs_x                           0x80ED50
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x80DBF0

// CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x813800

// CTaskManager
#define CTaskManager__GetEntry_x                                   0x52C550
#define CTaskManager__HandleMessage_x                              0x52A9D0
#define CTaskManager__GetTaskStatus_x                              0x52C600
#define CTaskManager__GetElementDescription_x                      0x52C680

// EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x563EE0
#define EqSoundManager__PlayScriptMp3_x                            0x564040
#define EqSoundManager__SoundAssistPlay_x                          0x676720
#define EqSoundManager__WaveInstancePlay_x                         0x675C90

// CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x520360

// CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x943E10

// CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x557EB0
#define CAltAbilityData__GetMercMaxRank_x                          0x557E40
#define CAltAbilityData__GetMaxRank_x                              0x54D4D0

// CTargetRing
#define CTargetRing__Cast_x                                        0x60A560

// CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C93F0
#define CharacterBase__CreateItemGlobalIndex_x                     0x507B10
#define CharacterBase__CreateItemIndex_x                           0x612660
#define CharacterBase__GetItemPossession_x                         0x4F3950
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CA590
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CA5F0

// CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6EEF90
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6EF7C0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6EF870

// messages
#define msg_spell_worn_off_x                                       0x58E340
#define msg_new_text_x                                             0x5830D0
#define __msgTokenTextParam_x                                      0x590870
#define msgTokenText_x                                             0x590AC0

// SpellManager
#define SpellManager__vftable_x                                    0xAD7AC4
#define SpellManager__SpellManager_x                               0x679A50
#define Spellmanager__LoadTextSpells_x                             0x67A340
#define SpellManager__GetSpellByGroupAndRank_x                     0x679C20

// CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x 0x98BF90

// ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C2910
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C2B90

// CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x75EF00

// CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x70C770
#define CCursorAttachment__AttachToCursor1_x                       0x70C7B0
#define CCursorAttachment__Deactivate_x                            0x70D780

// CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x953C20
#define CEQSuiteTextureLoader__GetTexture_x                        0x9538E0

// CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x505080
#define CFindItemWnd__WndNotification_x                            0x505B60
#define CFindItemWnd__Update_x                                     0x5066D0
#define CFindItemWnd__PickupSelectedItem_x                         0x5048F0

// IString
#define IString__Append_x                                          0x4F5120

// Camera
#define CDisplay__cameraType_x                                     0xDE8198
#define EverQuest__Cameras_x                                       0xEABAD4

// LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x50D540
#define LootFiltersManager__GetItemFilterData_x                    0x50CE40
#define LootFiltersManager__RemoveItemLootFilter_x                 0x50CE70
#define LootFiltersManager__SetItemLootFilter_x                    0x50D090

// COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B6300

// CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x991B20
#define CResolutionHandler__GetWindowedStyle_x                     0x671380

// CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x704D60

// CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D5310
#define CDistillerInfo__Instance_x                                 0x8D52B0

// CGroupWnd
#define CGroupWnd__WndNotification_x                               0x7250C0
#define CGroupWnd__UpdateDisplay_x                                 0x724410

// ItemBase
#define ItemBase__IsLore_x                                         0x898380
#define ItemBase__IsLoreEquipped_x                                 0x898400

// EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5C9650
#define EQPlacedItemManager__GetItemByGuid_x                       0x5C9790
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5C97F0

// RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x666A10
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x66A380

// CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x4FB450

// FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4E9E80
#define FactionManagerClient__HandleFactionMessage_x               0x4EA4F0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4EAAF0
#define FactionManagerClient__GetMaxFaction_x                      0x4EAB0F
#define FactionManagerClient__GetMinFaction_x                      0x4EAAC0

// BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4F3920

// ArrayClass
#define ArrayClass__DeleteElement_x                                0x91B2F0

// AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49B8C0

// ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4F3B50

// MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x557360

// CTargetManager
#define CTargetManager__Get_x                                      0x67D280

// RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x666A10

// CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A88B0

// EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x59CAF0

// EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF49164
