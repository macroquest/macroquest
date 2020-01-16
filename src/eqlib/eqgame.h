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
#define __ExpectedVersionDate                                     "Jan  9 2020"
#define __ExpectedVersionTime                                     "13:39:57"
#define __ActualVersionDate_x                                      0xB0B538
#define __ActualVersionTime_x                                      0xB0B52C
#define __ActualVersionBuild_x                                     0xAF723C

// Memory Protection
#define __MemChecker0_x                                            0x630A10
#define __MemChecker1_x                                            0x902E00
#define __MemChecker2_x                                            0x6BEE10
#define __MemChecker3_x                                            0x6BED60
#define __MemChecker4_x                                            0x8591F0
#define __EncryptPad0_x                                            0xC423E8
#define __EncryptPad1_x                                            0xCA0650
#define __EncryptPad2_x                                            0xC52C80
#define __EncryptPad3_x                                            0xC52880
#define __EncryptPad4_x                                            0xC90C00
#define __EncryptPad5_x                                            0xF6CE10
#define __AC1_x                                                    0x816376
#define __AC2_x                                                    0x5EA90F
#define __AC3_x                                                    0x5F200F
#define __AC4_x                                                    0x5F5FE0
#define __AC5_x                                                    0x5FC2EF
#define __AC6_x                                                    0x6007E6
#define __AC7_x                                                    0x5EA380
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x19739C

// Direct Input
#define DI8__Main_x                                                0xF6CE38
#define DI8__Keyboard_x                                            0xF6CE3C
#define DI8__Mouse_x                                               0xF6CE1C
#define DI8__Mouse_Copy_x                                          0xEC556C
#define DI8__Mouse_Check_x                                         0xF6A964
#define __AutoSkillArray_x                                         0xEC6484
#define __Attack_x                                                 0xF642AB
#define __Autofire_x                                               0xF642AC
#define __BindList_x                                               0xC30E20
#define g_eqCommandStates_x                                        0xC31BA0
#define __Clicks_x                                                 0xEC5624
#define __CommandList_x                                            0xC32760
#define __CurrentMapLabel_x                                        0xF7CD74
#define __CurrentSocial_x                                          0xC1A7C0
#define __DoAbilityList_x                                          0xEFBDCC
#define __do_loot_x                                                0x5B6230
#define __DrawHandler_x                                            0x15FC0F0
#define __GroupCount_x                                             0xEB5822
#define __Guilds_x                                                 0xEBBD78
#define __gWorld_x                                                 0xEB5F68
#define __HWnd_x                                                   0xF6CE20
#define __heqmain_x                                                0xF6CDF8
#define __InChatMode_x                                             0xEC5554
#define __LastTell_x                                               0xEC74C8
#define __LMouseHeldTime_x                                         0xEC5690
#define __Mouse_x                                                  0xF6CE24
#define __MouseLook_x                                              0xEC55EA
#define __MouseEventTime_x                                         0xF64D8C
#define __gpbCommandEvent_x                                        0xEB5A24
#define __NetStatusToggle_x                                        0xEC55ED
#define __PCNames_x                                                0xEC6A74
#define __RangeAttackReady_x                                       0xEC6768
#define __RMouseHeldTime_x                                         0xEC568C
#define __RunWalkState_x                                           0xEC5558
#define __ScreenMode_x                                             0xE0323C
#define __ScreenX_x                                                0xEC550C
#define __ScreenY_x                                                0xEC5508
#define __ScreenXMax_x                                             0xEC5510
#define __ScreenYMax_x                                             0xEC5514
#define __ServerHost_x                                             0xEB5C53
#define __ServerName_x                                             0xEFBD8C
#define __ShiftKeyDown_x                                           0xEC5BE4
#define __ShowNames_x                                              0xEC6924
#define __Socials_x                                                0xEFBE8C
#define __SubscriptionType_x                                       0xFC1280
#define __TargetAggroHolder_x                                      0xF7F728
#define __ZoneType_x                                               0xEC59E8
#define __GroupAggro_x                                             0xF7F768
#define __LoginName_x                                              0xF6A5F4
#define __Inviter_x                                                0xF64228
#define __AttackOnAssist_x                                         0xEC68E0
#define __UseTellWindows_x                                         0xEC6C10
#define __gfMaxZoomCameraDistance_x                                0xB00E98
#define __gfMaxCameraDistance_x                                    0xB2D23C
#define __pulAutoRun_x                                             0xEC5608
#define __pulForward_x                                             0xEC6C48
#define __pulBackward_x                                            0xEC6C4C
#define __pulTurnRight_x                                           0xEC6C50
#define __pulTurnLeft_x                                            0xEC6C54
#define __pulStrafeLeft_x                                          0xEC6C58
#define __pulStrafeRight_x                                         0xEC6C5C

////
//Section 1: Vital Offsets
////
#define instCRaid_x                                                0xEB8110
#define instEQZoneInfo_x                                           0xEC57E0
#define pinstActiveBanker_x                                        0xEB5A38
#define pinstActiveCorpse_x                                        0xEB5A30
#define pinstActiveGMaster_x                                       0xEB5A34
#define pinstActiveMerchant_x                                      0xEB5A2C
#define pinstAltAdvManager_x                                       0xE04340
#define pinstBandageTarget_x                                       0xEB5A48
#define pinstCamActor_x                                            0xE03230
#define pinstCDBStr_x                                              0xE0305C
#define pinstCDisplay_x                                            0xEB7F78
#define pinstCEverQuest_x                                          0xF69EB8
#define pinstEverQuestInfo_x                                       0xEC5500
#define pinstCharData_x                                            0xEB5804
#define pinstCharSpawn_x                                           0xEB5A80
#define pinstControlledMissile_x                                   0xEB5F64
#define pinstControlledPlayer_x                                    0xEB5A80
#define pinstCResolutionHandler_x                                  0x15FC320
#define pinstCSidlManager_x                                        0x15FB2B8
#define pinstCXWndManager_x                                        0x15FB2B4
#define instDynamicZone_x                                          0xEBBC50
#define pinstDZMember_x                                            0xEBBD60
#define pinstDZTimerInfo_x                                         0xEBBD64
#define pinstEqLogin_x                                             0xF69F40
#define instEQMisc_x                                               0xE02FA0
#define pinstEQSoundManager_x                                      0xE05310
#define pinstEQSpellStrings_x                                      0xCC59B8
#define instExpeditionLeader_x                                     0xEBBC9A
#define instExpeditionName_x                                       0xEBBCDA
#define pinstGroup_x                                               0xEB581E
#define pinstImeManager_x                                          0x15FB2B0
#define pinstLocalPlayer_x                                         0xEB5A28
#define pinstMercenaryData_x                                       0xF66880
#define pinstMercenaryStats_x                                      0xF7F874
#define pinstModelPlayer_x                                         0xEB5A40
#define pinstPCData_x                                              0xEB5804
#define pinstSkillMgr_x                                            0xF689E8
#define pinstSpawnManager_x                                        0xF67490
#define pinstSpellManager_x                                        0xF68C28
#define pinstSpellSets_x                                           0xF5CED4
#define pinstStringTable_x                                         0xEB5808
#define pinstSwitchManager_x                                       0xEB56B0
#define pinstTarget_x                                              0xEB5A7C
#define pinstTargetObject_x                                        0xEB5B08
#define pinstTargetSwitch_x                                        0xEB7F70
#define pinstTaskMember_x                                          0xE02E30
#define pinstTrackTarget_x                                         0xEB5A84
#define pinstTradeTarget_x                                         0xEB5A3C
#define instTributeActive_x                                        0xE02FC1
#define pinstViewActor_x                                           0xE0322C
#define pinstWorldData_x                                           0xEB5A14
#define pinstZoneAddr_x                                            0xEC5A80
#define pinstPlayerPath_x                                          0xF67528
#define pinstTargetIndicator_x                                     0xF68E90
#define EQObject_Top_x                                             0xEB5A20

////
//Section 2:  UI Related Offsets
////
#define pinstCAAWnd_x                                              0xE03114
#define pinstCAchievementsWnd_x                                    0xE03170
#define pinstCActionsWnd_x                                         0xE0313C
#define pinstCAdvancedDisplayOptionsWnd_x                          0xE03268
#define pinstCAdvancedLootWnd_x                                    0xE03204
#define pinstCAdventureLeaderboardWnd_x                            0xF76548
#define pinstCAdventureRequestWnd_x                                0xF765F8
#define pinstCAdventureStatsWnd_x                                  0xF766A8
#define pinstCAggroMeterWnd_x                                      0xE03270
#define pinstCAlarmWnd_x                                           0xE031CC
#define pinstCAlertHistoryWnd_x                                    0xE03294
#define pinstCAlertStackWnd_x                                      0xE031DC
#define pinstCAlertWnd_x                                           0xE031EC
#define pinstCAltStorageWnd_x                                      0xF76A08
#define pinstCAudioTriggersWindow_x                                0xCB7CE8
#define pinstCAuraWnd_x                                            0xE0320C
#define pinstCAvaZoneWnd_x                                         0xE03220
#define pinstCBandolierWnd_x                                       0xE03264
#define pinstCBankWnd_x                                            0xE032B4
#define pinstCBarterMerchantWnd_x                                  0xF77C48
#define pinstCBarterSearchWnd_x                                    0xF77CF8
#define pinstCBarterWnd_x                                          0xF77DA8
#define pinstCBazaarConfirmationWnd_x                              0xE03198
#define pinstCBazaarSearchWnd_x                                    0xE03118
#define pinstCBazaarWnd_x                                          0xE031B4
#define pinstCBlockedBuffWnd_x                                     0xE03218
#define pinstCBlockedPetBuffWnd_x                                  0xE03258
#define pinstCBodyTintWnd_x                                        0xE0314C
#define pinstCBookWnd_x                                            0xE032A4
#define pinstCBreathWnd_x                                          0xE03128
#define pinstCBuffWindowNORMAL_x                                   0xE031FC
#define pinstCBuffWindowSHORT_x                                    0xE03200
#define pinstCBugReportWnd_x                                       0xE032AC
#define pinstCButtonWnd_x                                          0x15FB520
#define pinstCCastingWnd_x                                         0xE03290
#define pinstCCastSpellWnd_x                                       0xE03120
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE0316C
#define pinstCChatWindowManager_x                                  0xF78868
#define pinstCClaimWnd_x                                           0xF789C0
#define pinstCColorPickerWnd_x                                     0xE0378C
#define pinstCCombatAbilityWnd_x                                   0xE031C0
#define pinstCCombatSkillsSelectWnd_x                              0xE0317C
#define pinstCCompassWnd_x                                         0xE03140
#define pinstCConfirmationDialog_x                                 0xF7D8C0
#define pinstCContainerMgr_x                                       0xE03164
#define pinstCContextMenuManager_x                                 0x15FB270
#define pinstCCursorAttachment_x                                   0xE03278
#define pinstCDynamicZoneWnd_x                                     0xF78F88
#define pinstCEditLabelWnd_x                                       0xE031F0
#define pinstCEQMainWnd_x                                          0xF791D0
#define pinstCEventCalendarWnd_x                                   0xE03778
#define pinstCExtendedTargetWnd_x                                  0xE03248
#define pinstCFacePick_x                                           0xE03194
#define pinstCFactionWnd_x                                         0xE031A4
#define pinstCFellowshipWnd_x                                      0xF793D0
#define pinstCFileSelectionWnd_x                                   0xE03784
#define pinstCFindItemWnd_x                                        0xE0318C
#define pinstCFindLocationWnd_x                                    0xF79528
#define pinstCFriendsWnd_x                                         0xE03190
#define pinstCGemsGameWnd_x                                        0xE031A0
#define pinstCGiveWnd_x                                            0xE031D4
#define pinstCGroupSearchFiltersWnd_x                              0xE03298
#define pinstCGroupSearchWnd_x                                     0xF79920
#define pinstCGroupWnd_x                                           0xF799D0
#define pinstCGuildBankWnd_x                                       0xEC68C4
#define pinstCGuildCreationWnd_x                                   0xF79B30
#define pinstCGuildMgmtWnd_x                                       0xF79BE0
#define pinstCharacterCreation_x                                   0xE03184
#define pinstCHelpWnd_x                                            0xE031D0
#define pinstCHeritageSelectionWnd_x                               0xE031A8
#define pinstCHotButtonWnd_x                                       0xF7BD38
#define pinstCHotButtonWnd1_x                                      0xF7BD38
#define pinstCHotButtonWnd2_x                                      0xF7BD3C
#define pinstCHotButtonWnd3_x                                      0xF7BD40
#define pinstCHotButtonWnd4_x                                      0xF7BD44
#define pinstCIconSelectionWnd_x                                   0xE03274
#define pinstCInspectWnd_x                                         0xE0325C
#define pinstCInventoryWnd_x                                       0xE03210
#define pinstCInvSlotMgr_x                                         0xE03124
#define pinstCItemDisplayManager_x                                 0xF7C2C8
#define pinstCItemExpTransferWnd_x                                 0xF7C3F8
#define pinstCItemOverflowWnd_x                                    0xE0311C
#define pinstCJournalCatWnd_x                                      0xE030FC
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE032EC
#define pinstCKeyRingWnd_x                                         0xE03284
#define pinstCLargeDialogWnd_x                                     0xF7E540
#define pinstCLayoutCopyWnd_x                                      0xF7C748
#define pinstCLFGuildWnd_x                                         0xF7C7F8
#define pinstCLoadskinWnd_x                                        0xE031B0
#define pinstCLootFiltersCopyWnd_x                                 0xCD4338
#define pinstCLootFiltersWnd_x                                     0xE031E0
#define pinstCLootSettingsWnd_x                                    0xE031F8
#define pinstCLootWnd_x                                            0xE03100
#define pinstCMailAddressBookWnd_x                                 0xE0312C
#define pinstCMailCompositionWnd_x                                 0xE03110
#define pinstCMailIgnoreListWnd_x                                  0xE03130
#define pinstCMailWnd_x                                            0xE03990
#define pinstCManageLootWnd_x                                      0xE047F0
#define pinstCMapToolbarWnd_x                                      0xE031D8
#define pinstCMapViewWnd_x                                         0xE031AC
#define pinstCMarketplaceWnd_x                                     0xE031E4
#define pinstCMerchantWnd_x                                        0xE03108
#define pinstCMIZoneSelectWnd_x                                    0xF7D030
#define pinstCMusicPlayerWnd_x                                     0xE032B8
#define pinstCNameChangeMercWnd_x                                  0xE03188
#define pinstCNameChangePetWnd_x                                   0xE03174
#define pinstCNameChangeWnd_x                                      0xE0319C
#define pinstCNoteWnd_x                                            0xE031B8
#define pinstCObjectPreviewWnd_x                                   0xE031F4
#define pinstCOptionsWnd_x                                         0xE031C4
#define pinstCPetInfoWnd_x                                         0xE032FC
#define pinstCPetitionQWnd_x                                       0xE03158
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE03150
#define pinstCPlayerWnd_x                                          0xE0377C
#define pinstCPopupWndManager_x                                    0xF7D8C0
#define pinstCProgressionSelectionWnd_x                            0xF7D970
#define pinstCPurchaseGroupWnd_x                                   0xE03250
#define pinstCPurchaseWnd_x                                        0xE03214
#define pinstCPvPLeaderboardWnd_x                                  0xF7DA20
#define pinstCPvPStatsWnd_x                                        0xF7DAD0
#define pinstCQuantityWnd_x                                        0xE032F0
#define pinstCRaceChangeWnd_x                                      0xE031C8
#define pinstCRaidOptionsWnd_x                                     0xE032A0
#define pinstCRaidWnd_x                                            0xE03104
#define pinstCRealEstateItemsWnd_x                                 0xE03168
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE0310C
#define pinstCRealEstateManageWnd_x                                0xE03260
#define pinstCRealEstateNeighborhoodWnd_x                          0xE03288
#define pinstCRealEstatePlotSearchWnd_x                            0xE032B0
#define pinstCRealEstatePurchaseWnd_x                              0xE032E8
#define pinstCRespawnWnd_x                                         0xE03228
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE03178
#define pinstCSendMoneyWnd_x                                       0xE031E8
#define pinstCServerListWnd_x                                      0xE03770
#define pinstCSkillsSelectWnd_x                                    0xE03160
#define pinstCSkillsWnd_x                                          0xE03144
#define pinstCSocialEditWnd_x                                      0xE0327C
#define pinstCSocialWnd_x                                          0xE03180
#define pinstCSpellBookWnd_x                                       0xE031BC
#define pinstCStoryWnd_x                                           0xE03134
#define pinstCTargetOfTargetWnd_x                                  0xF7F8F8
#define pinstCTargetWnd_x                                          0xE03224
#define pinstCTaskOverlayWnd_x                                     0xE0324C
#define pinstCTaskSelectWnd_x                                      0xF7FA50
#define pinstCTaskManager_x                                        0xCD4C78
#define pinstCTaskTemplateSelectWnd_x                              0xF7FB00
#define pinstCTaskWnd_x                                            0xF7FBB0
#define pinstCTextEntryWnd_x                                       0xE0329C
#define pinstCTimeLeftWnd_x                                        0xE03138
#define pinstCTipWndCONTEXT_x                                      0xF7FDB4
#define pinstCTipWndOFDAY_x                                        0xF7FDB0
#define pinstCTitleWnd_x                                           0xF7FE60
#define pinstCTrackingWnd_x                                        0xE0321C
#define pinstCTradeskillWnd_x                                      0xF7FFC8
#define pinstCTradeWnd_x                                           0xE03154
#define pinstCTrainWnd_x                                           0xE030F8
#define pinstCTributeBenefitWnd_x                                  0xF801C8
#define pinstCTributeMasterWnd_x                                   0xF80278
#define pinstCTributeTrophyWnd_x                                   0xF80328
#define pinstCVideoModesWnd_x                                      0xE03780
#define pinstCVoiceMacroWnd_x                                      0xF695F8
#define pinstCVoteResultsWnd_x                                     0xE0315C
#define pinstCVoteWnd_x                                            0xE03148
#define pinstCWebManager_x                                         0xF69C74
#define pinstCZoneGuideWnd_x                                       0xE03254
#define pinstCZonePathWnd_x                                        0xE0326C

#define pinstEQSuiteTextureLoader_x                                0xCA2128
#define pinstItemIconCache_x                                       0xF79188
#define pinstLootFiltersManager_x                                  0xCD43E8
#define pinstRewardSelectionWnd_x                                  0xF7E218

////
// Section 3: Miscellaneous Offsets
////
#define __CastRay_x                                                0x5B1690
#define __CastRay2_x                                               0x5B16E0
#define __ConvertItemTags_x                                        0x5CD240
#define __CleanItemTags_x                                          0x47D050
#define __CreateCascadeMenuItems_x                                 0x5536D0
#define __DoesFileExist_x                                          0x905E80
#define __EQGetTime_x                                              0x9028D0
#define __ExecuteCmd_x                                             0x5A9EF0
#define __FixHeading_x                                             0x99DD60
#define __FlushDxKeyboard_x                                        0x6BACF0
#define __GameLoop_x                                               0x6BE000
#define __get_bearing_x                                            0x5B1200
#define __get_melee_range_x                                        0x5B18D0
#define __GetAnimationCache_x                                      0x723260
#define __GetGaugeValueFromEQ_x                                    0x814820
#define __GetLabelFromEQ_x                                         0x816300
#define __GetXTargetType_x                                         0x99F740
#define __HandleMouseWheel_x                                       0x6BEEC0
#define __HeadingDiff_x                                            0x99DDD0
#define __HelpPath_x                                               0xF6497C
#define __LoadFrontEnd_x                                           0x6BB320
#define __NewUIINI_x                                               0x8144F0
#define __ProcessGameEvents_x                                      0x611FA0
#define __ProcessKeyboardEvents_x                                  0x6BC860
#define __ProcessMouseEvents_x                                     0x611760
#define __SaveColors_x                                             0x5535B0
#define __STMLToText_x                                             0x9413B0
#define __ToggleKeyRingItem_x                                      0x516310
#define __WndProc_x                                                0x6BD2C0
#define CMemoryMappedFile__SetFile_x                               0xA8D130
#define CrashDetected_x                                            0x6BCDC0
#define DrawNetStatus_x                                            0x63DDB0
#define Expansion_HoT_x                                            0xEC68CC
#define Teleport_Table_Size_x                                      0xEB5B10
#define Teleport_Table_x                                           0xEB5F70
#define Util__FastTime_x                                           0x9024A0
#define __eq_delete_x                                              0x9A620E
#define __eq_new_x                                                 0x9A67D4

////
// Section 4: Function Offsets
////
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4903E0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4992E0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4990B0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493970
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492DC0

// AltAdvManager
#define AltAdvManager__GetCalculatedTimer_x                        0x55B190
#define AltAdvManager__IsAbilityReady_x                            0x55A0C0
#define AltAdvManager__GetAAById_x                                 0x55A2C0
#define AltAdvManager__CanTrainAbility_x                           0x55A330
#define AltAdvManager__CanSeeAbility_x                             0x55A690

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C9D70
#define CharacterZoneClient__HasSkill_x                            0x4D4C60
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6380
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE660
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BAC90
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8D00
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D8DE0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D8EC0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C2E70
#define CharacterZoneClient__BardCastBard_x                        0x4C59D0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAD60
#define CharacterZoneClient__GetEffect_x                           0x4BABD0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C3EC0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C3F90
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C3FE0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4130
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4300
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2B70
#define CharacterZoneClient__FindItemByGuid_x                      0x4D72E0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D6D60

// CBankWnd
#define CBankWnd__GetNumBankSlots_x                                0x6E4AC0
#define CBankWnd__WndNotification_x                                0x6E48A0

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6F23C0

// CButtonWnd
#define CButtonWnd__SetCheck_x                                     0x6207B0
#define CButtonWnd__CButtonWnd_x                                   0x93D760
#define CButtonWnd__dCButtonWnd_x                                  0x93DA40
#define CButtonWnd__vftable_x                                      0xB45E48

// CChatWindowManager
#define CChatWindowManager__GetRGBAFromIndex_x                     0x712410
#define CChatWindowManager__InitContextMenu_x                      0x70B570
#define CChatWindowManager__FreeChatWindow_x                       0x710F50
#define CChatWindowManager__GetLockedActiveChatWindow_x            0x4E8290
#define CChatWindowManager__SetLockedActiveChatWindow_x            0x712090
#define CChatWindowManager__CreateChatWindow_x                     0x711590

// ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E83A0

// CChatWindow
#define CChatWindow__CChatWindow_x                                 0x712C90
#define CChatWindow__Clear_x                                       0x713F50
#define CChatWindow__WndNotification_x                             0x7146E0
#define CChatWindow__AddHistory_x                                  0x713810

// CContextMenu
#define CContextMenu__CContextMenu_x                               0x951D70
#define CContextMenu__dCContextMenu_x                              0x951FA0
#define CContextMenu__AddMenuItem_x                                0x951FB0
#define CContextMenu__RemoveMenuItem_x                             0x9522C0
#define CContextMenu__RemoveAllMenuItems_x                         0x9522E0
#define CContextMenu__CheckMenuItem_x                              0x952360
#define CContextMenu__SetMenuItem_x                                0x9521E0
#define CContextMenu__AddSeparator_x                               0x952140

// CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x952900
#define CContextMenuManager__RemoveMenu_x                          0x952970
#define CContextMenuManager__PopupMenu_x                           0x952A30
#define CContextMenuManager__Flush_x                               0x9528A0
#define CContextMenuManager__GetMenu_x                             0x49B510
#define CContextMenuManager__CreateDefaultMenu_x                   0x71DA80

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8DDEC0
#define CChatService__GetFriendName_x                              0x8DDED0

// CComboWnd
#define CComboWnd__DeleteAll_x                                     0x94F1E0
#define CComboWnd__Draw_x                                          0x94E6E0
#define CComboWnd__GetCurChoice_x                                  0x94F020
#define CComboWnd__GetListRect_x                                   0x94EB90
#define CComboWnd__GetTextRect_x                                   0x94F250
#define CComboWnd__InsertChoice_x                                  0x94ED20
#define CComboWnd__SetColors_x                                     0x94ECF0
#define CComboWnd__SetChoice_x                                     0x94EFF0
#define CComboWnd__GetItemCount_x                                  0x94F030
#define CComboWnd__GetCurChoiceText_x                              0x94F070
#define CComboWnd__GetChoiceText_x                                 0x94F040
#define CComboWnd__InsertChoiceAtIndex_x                           0x94EDB0

// CContainerWnd
#define CContainerWnd__HandleCombine_x                             0x71B480
#define CContainerWnd__vftable_x                                   0xB14724
#define CContainerWnd__SetContainer_x                              0x71C9E0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54DFE0
#define CDisplay__PreZoneMainUI_x                                  0x54DFF0
#define CDisplay__CleanGameUI_x                                    0x553370
#define CDisplay__GetClickedActor_x                                0x546300
#define CDisplay__GetUserDefinedColor_x                            0x53E9B0
#define CDisplay__GetWorldFilePath_x                               0x547D70
#define CDisplay__is3dON_x                                         0x542F60
#define CDisplay__ReloadUI_x                                       0x54D470
#define CDisplay__WriteTextHD2_x                                   0x542D50
#define CDisplay__TrueDistance_x                                   0x549A30
#define CDisplay__SetViewActor_x                                   0x545C20
#define CDisplay__GetFloorHeight_x                                 0x543020
#define CDisplay__SetRenderWindow_x                                0x541980
#define CDisplay__ToggleScreenshotMode_x                           0x5456F0

// CEditBaseWnd
#define CEditBaseWnd__SetSel_x                                     0x971B90

// CEditWnd
#define CEditWnd__DrawCaret_x                                      0x9552D0
#define CEditWnd__EnsureCaretVisible_x                             0x9574A0
#define CEditWnd__GetCaretPt_x                                     0x956450
#define CEditWnd__GetCharIndexPt_x                                 0x956200
#define CEditWnd__GetDisplayString_x                               0x9560A0
#define CEditWnd__GetHorzOffset_x                                  0x954900
#define CEditWnd__GetLineForPrintableChar_x                        0x9573A0
#define CEditWnd__GetSelStartPt_x                                  0x9564B0
#define CEditWnd__GetSTMLSafeText_x                                0x955EC0
#define CEditWnd__PointFromPrintableChar_x                         0x956FD0
#define CEditWnd__ReplaceSelection_x                               0x956C40
#define CEditWnd__SelectableCharFromPoint_x                        0x957140
#define CEditWnd__SetEditable_x                                    0x956580
#define CEditWnd__SetWindowTextA_x                                 0x955C40

// CEverQuest
#define CEverQuest__DoPercentConvert_x                             0x5FFCC0
#define CEverQuest__ClickedPlayer_x                                0x5F1DF0
#define CEverQuest__CreateTargetIndicator_x                        0x60F240
#define CEverQuest__DeleteTargetIndicator_x                        0x60F2D0
#define CEverQuest__DoTellWindow_x                                 0x4E8480
#define CEverQuest__OutputTextToLog_x                              0x4E8750
#define CEverQuest__DropHeldItemOnGround_x                         0x5E6E30
#define CEverQuest__dsp_chat_x                                     0x4E8AE0
#define CEverQuest__trimName_x                                     0x60B520
#define CEverQuest__Emote_x                                        0x600520
#define CEverQuest__EnterZone_x                                    0x5FA5C0
#define CEverQuest__GetBodyTypeDesc_x                              0x604DE0
#define CEverQuest__GetClassDesc_x                                 0x605420
#define CEverQuest__GetClassThreeLetterCode_x                      0x605A20
#define CEverQuest__GetDeityDesc_x                                 0x60DB80
#define CEverQuest__GetLangDesc_x                                  0x605BE0
#define CEverQuest__GetRaceDesc_x                                  0x605400
#define CEverQuest__InterpretCmd_x                                 0x60E150
#define CEverQuest__LeftClickedOnPlayer_x                          0x5EB030
#define CEverQuest__LMouseUp_x                                     0x5E93C0
#define CEverQuest__RightClickedOnPlayer_x                         0x5EB910
#define CEverQuest__RMouseUp_x                                     0x5EA340
#define CEverQuest__SetGameState_x                                 0x5E6BC0
#define CEverQuest__UPCNotificationFlush_x                         0x60B420
#define CEverQuest__IssuePetCommand_x                              0x606FE0
#define CEverQuest__ReportSuccessfulHit_x                          0x601870

// CGaugeWnd
// not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x72D400
#define CGaugeWnd__CalcLinesFillRect_x                             0x72D460
#define CGaugeWnd__Draw_x                                          0x72CA80

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF640
#define CGuild__GetGuildName_x                                     0x4AE660
#define CGuild__GetGuildIndex_x                                    0x4AEAB0

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton_x                               0x7476A0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x620B70

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot_x                                 0x754640
#define CInvSlotMgr__MoveItem_x                                    0x7533B0
#define CInvSlotMgr__SelectSlot_x                                  0x754710

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x751C30
#define CInvSlot__SliderComplete_x                                 0x74F9A0
#define CInvSlot__GetItemBase_x                                    0x74F340
#define CInvSlot__UpdateItem_x                                     0x74F4B0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x756170
#define CInvSlotWnd__CInvSlotWnd_x                                 0x755310
#define CInvSlotWnd__HandleLButtonUp_x                             0x755CF0

// CItemDisplayWnd
#define CItemDisplayWnd__SetSpell_x                                0x80FBC0
#define CItemDisplayWnd__UpdateStrings_x                           0x764810
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75E5A0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x75EAA0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x764E10
#define CItemDisplayWnd__AboutToShow_x                             0x764480
#define CItemDisplayWnd__WndNotification_x                         0x765EF0
#define CItemDisplayWnd__RequestConvertItem_x                      0x7659B0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x7634E0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x7642A0

// CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8484F0

// CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x76A3F0

// CLabel
#define CLabel__Draw_x                                             0x76FE30

// CListWnd
#define CListWnd__CListWnd_x                                       0x927A50
#define CListWnd__dCListWnd_x                                      0x927D70
#define CListWnd__vftable_x                                        0xB45720
#define CListWnd__AddColumn_x                                      0x92C1C0
#define CListWnd__AddColumn1_x                                     0x92C210
#define CListWnd__AddLine_x                                        0x92C5A0
#define CListWnd__AddString_x                                      0x92C3A0
#define CListWnd__CalculateFirstVisibleLine_x                      0x92BF90
#define CListWnd__CalculateVSBRange_x                              0x92BD80
#define CListWnd__ClearSel_x                                       0x92CD80
#define CListWnd__ClearAllSel_x                                    0x92CDE0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x92D7E0
#define CListWnd__Compare_x                                        0x92B6B0
#define CListWnd__Draw_x                                           0x927EA0
#define CListWnd__DrawColumnSeparators_x                           0x92A680
#define CListWnd__DrawHeader_x                                     0x92AAF0
#define CListWnd__DrawItem_x                                       0x92AFF0
#define CListWnd__DrawLine_x                                       0x92A7F0
#define CListWnd__DrawSeparator_x                                  0x92A720
#define CListWnd__EnableLine_x                                     0x929F70
#define CListWnd__EnsureVisible_x                                  0x92D710
#define CListWnd__ExtendSel_x                                      0x92CCB0
#define CListWnd__GetColumnTooltip_x                               0x929AB0
#define CListWnd__GetColumnMinWidth_x                              0x929B20
#define CListWnd__GetColumnWidth_x                                 0x929A20
#define CListWnd__GetCurSel_x                                      0x9293B0
#define CListWnd__GetItemAtPoint_x                                 0x92A1E0
#define CListWnd__GetItemAtPoint1_x                                0x92A250
#define CListWnd__GetItemData_x                                    0x929430
#define CListWnd__GetItemHeight_x                                  0x9297F0
#define CListWnd__GetItemIcon_x                                    0x9295C0
#define CListWnd__GetItemRect_x                                    0x92A060
#define CListWnd__GetItemText_x                                    0x929470
#define CListWnd__GetSelList_x                                     0x92CE30
#define CListWnd__GetSeparatorRect_x                               0x92A490
#define CListWnd__InsertLine_x                                     0x92C990
#define CListWnd__RemoveLine_x                                     0x92CAE0
#define CListWnd__SetColors_x                                      0x92BD50
#define CListWnd__SetColumnJustification_x                         0x92BA80
#define CListWnd__SetColumnWidth_x                                 0x92B9A0
#define CListWnd__SetCurSel_x                                      0x92CBF0
#define CListWnd__SetItemColor_x                                   0x92D3D0
#define CListWnd__SetItemData_x                                    0x92D390
#define CListWnd__SetItemText_x                                    0x92CFA0
#define CListWnd__ShiftColumnSeparator_x                           0x92BB40
#define CListWnd__Sort_x                                           0x92B830
#define CListWnd__ToggleSel_x                                      0x92CC20
#define CListWnd__SetColumnsSizable_x                              0x92BBF0
#define CListWnd__SetItemWnd_x                                     0x92D250
#define CListWnd__GetItemWnd_x                                     0x929610
#define CListWnd__SetItemIcon_x                                    0x92D020
#define CListWnd__CalculateCustomWindowPositions_x                 0x92C080
#define CListWnd__SetVScrollPos_x                                  0x92B980

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd_x                                 0x785500

// MapViewMap
#define MapViewMap__MapViewMap_x                                   0x780A00
#define MapViewMap__dMapViewMap_x                                  0x780B40
#define MapViewMap__vftable_x                                      0xB1BD88
#define MapViewMap__Clear_x                                        0x781370
#define MapViewMap__SaveEx_x                                       0x784730
#define MapViewMap__SetZoom_x                                      0x788DF0
#define MapViewMap__HandleLButtonDown_x                            0x780C50
#define MapViewMap__GetWorldCoordinates_x                          0x783C10

// CMerchantWnd
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A5690
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A5F70
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A64A0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A9410
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A4200
#define CMerchantWnd__SelectBuySellSlot_x                          0x7AEFC0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A52A0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8AB9A0
#define CPacketScrambler__hton_x                                   0x8AB990

// CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x94AD30
#define CSidlManagerBase__CreatePageWnd_x                          0x94A530
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x9467C0
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x946750
#define CSidlManagerBase__FindAnimation1_x                         0x9469A0
#define CSidlManagerBase__FindScreenPieceTemplate_x                0x946DB0
#define CSidlManagerBase__FindScreenPieceTemplate1_x               0x946BA0
#define CSidlManagerBase__CreateLabel_x                            0x806E40
#define CSidlManagerBase__CreateXWndFromTemplate_x                 0x949D10
#define CSidlManagerBase__CreateXWndFromTemplate1_x                0x949EE0
#define CSidlManagerBase__CreateXWnd_x                             0x806D70

// CSidlManager
#define CSidlManager__CreateHotButtonWnd_x                         0x807330

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9434B0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9433C0
#define CSidlScreenWnd__ConvertToRes_x                             0x968BD0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x942E60
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x942B50
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x942C20
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x942CF0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x943930
#define CSidlScreenWnd__EnableIniStorage_x                         0x943E00
#define CSidlScreenWnd__GetChildItem_x                             0x943D80
#define CSidlScreenWnd__GetSidlPiece_x                             0x943B20
#define CSidlScreenWnd__HandleLButtonUp_x                          0x933620
#define CSidlScreenWnd__Init1_x                                    0x942750
#define CSidlScreenWnd__LoadIniInfo_x                              0x943E50
#define CSidlScreenWnd__LoadIniListWnd_x                           0x944980
#define CSidlScreenWnd__LoadSidlScreen_x                           0x941B70
#define CSidlScreenWnd__m_layoutCopy_x                             0x15FB140
#define CSidlScreenWnd__StoreIniInfo_x                             0x944500
#define CSidlScreenWnd__StoreIniVis_x                              0x944860
#define CSidlScreenWnd__vftable_x                                  0xB460E8
#define CSidlScreenWnd__WndNotification_x                          0x943840

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6852A0
#define CSkillMgr__GetSkillCap_x                                   0x685480
#define CSkillMgr__GetNameToken_x                                  0x684A20
#define CSkillMgr__IsActivatedSkill_x                              0x684B60
#define CSkillMgr__IsCombatSkill_x                                 0x684AA0

// CSliderWnd
#define CSliderWnd__GetValue_x                                     0x9536E0
#define CSliderWnd__SetValue_x                                     0x953550
#define CSliderWnd__SetNumTicks_x                                  0x9535B0

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet_x                               0x80CF80

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x95BF80
#define CStmlWnd__CalculateHSBRange_x                              0x95D0E0
#define CStmlWnd__CalculateVSBRange_x                              0x95D060
#define CStmlWnd__CanBreakAtCharacter_x                            0x961400
#define CStmlWnd__FastForwardToEndOfTag_x                          0x962090
#define CStmlWnd__ForceParseNow_x                                  0x95C5C0
#define CStmlWnd__GetNextTagPiece_x                                0x961360
#define CStmlWnd__GetSTMLText_x                                    0x505BA0
#define CStmlWnd__GetVisibleText_x                                 0x95C5E0
#define CStmlWnd__InitializeWindowVariables_x                      0x961EE0
#define CStmlWnd__MakeStmlColorTag_x                               0x95B5F0
#define CStmlWnd__MakeWndNotificationTag_x                         0x95B660
#define CStmlWnd__SetSTMLText_x                                    0x95A6A0
#define CStmlWnd__StripFirstSTMLLines_x                            0x963180
#define CStmlWnd__UpdateHistoryString_x                            0x9622A0

// CTabWnd
#define CTabWnd__Draw_x                                            0x959740
#define CTabWnd__DrawCurrentPage_x                                 0x959E70
#define CTabWnd__DrawTab_x                                         0x959B90
#define CTabWnd__GetCurrentPage_x                                  0x958F50
#define CTabWnd__GetPageInnerRect_x                                0x959190
#define CTabWnd__GetTabInnerRect_x                                 0x9590D0
#define CTabWnd__GetTabRect_x                                      0x958F80
#define CTabWnd__InsertPage_x                                      0x9593A0
#define CTabWnd__SetPage_x                                         0x959210
#define CTabWnd__SetPageRect_x                                     0x959680
#define CTabWnd__UpdatePage_x                                      0x959A50
#define CTabWnd__GetPageFromTabIndex_x                             0x959AD0
#define CTabWnd__GetCurrentTabIndex_x                              0x958F40

// CPageWnd
#define CPageWnd__GetTabText_x                                     0x76A7C0
#define CPageWnd__SetTabText_x                                     0x958AA0

// CTextOverlay
#define CTextOverlay__DisplayText_x                                0x4A9100

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x930500
#define CTextureFont__GetTextExtent_x                              0x9306C0

// CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B81D0
#define CHtmlComponentWnd__ValidateUri_x                           0x749090
#define CHtmlWnd__SetClientCallbacks_x                             0x625BE0
#define CHtmlWnd__AddObserver_x                                    0x625C00
#define CHtmlWnd__RemoveObserver_x                                 0x625C60
#define Window__getProgress_x                                      0x860820
#define Window__getStatus_x                                        0x860840
#define Window__getURI_x                                           0x860850

// CXMLDataManager
#define CXMLDataManager__GetXMLData_x                              0x96E620

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead_x                             0x91D6A0

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr_x                                             0x4E80D0
#define CXStr__CXStr1_x                                            0x8513D0
#define CXStr__CXStr3_x                                            0x8FEA10
#define CXStr__dCXStr_x                                            0x478740
#define CXStr__operator_equal_x                                    0x8FEC40
#define CXStr__operator_equal1_x                                   0x8FEC80
#define CXStr__operator_plus_equal1_x                              0x8FF710
#define CXStr__SetString_x                                         0x901600
#define CXStr__operator_char_p_x                                   0x8FF180
#define CXStr__GetChar_x                                           0x900F50
#define CXStr__Delete_x                                            0x900800
#define CXStr__GetUnicode_x                                        0x900FC0
#define CXStr__GetLength_x                                         0x4A8EB0
#define CXStr__Mid_x                                               0x47D400
#define CXStr__Insert_x                                            0x901020
#define CXStr__FindNext_x                                          0x900C70
#define CXStr__gFreeLists_x                                        0xCA0580
#define CXStr__gCXStrAccess_x                                      0x15FA864

// CTileLayoutWnd
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x951980

// CXWnd
#define CXWnd__BringToTop_x                                        0x936D50
#define CXWnd__Center_x                                            0x9368D0
#define CXWnd__ClrFocus_x                                          0x9366E0
#define CXWnd__Destroy_x                                           0x936790
#define CXWnd__DoAllDrawing_x                                      0x932DD0
#define CXWnd__DrawChildren_x                                      0x932DA0
#define CXWnd__DrawColoredRect_x                                   0x933210
#define CXWnd__DrawTooltip_x                                       0x931900
#define CXWnd__DrawTooltipAtPoint_x                                0x9319C0
#define CXWnd__GetBorderFrame_x                                    0x933070
#define CXWnd__GetChildItem_x                                      0x936F50
#define CXWnd__GetChildWndAt_x                                     0x936DF0
#define CXWnd__GetClientClipRect_x                                 0x934FF0
#define CXWnd__GetScreenClipRect_x                                 0x9350C0
#define CXWnd__GetScreenRect_x                                     0x935280
#define CXWnd__GetTooltipRect_x                                    0x933260
#define CXWnd__GetWindowTextA_x                                    0x49CC80
#define CXWnd__IsActive_x                                          0x933990
#define CXWnd__IsDescendantOf_x                                    0x935C40
#define CXWnd__IsReallyVisible_x                                   0x935C70
#define CXWnd__IsType_x                                            0x937440
#define CXWnd__Minimize_x                                          0x936390
#define CXWnd__Move_x                                              0x935CD0
#define CXWnd__Move1_x                                             0x935D80
#define CXWnd__ProcessTransition_x                                 0x936880
#define CXWnd__Refade_x                                            0x936050
#define CXWnd__Resize_x                                            0x936320
#define CXWnd__Right_x                                             0x936B10
#define CXWnd__SetFocus_x                                          0x9366A0
#define CXWnd__SetFont_x                                           0x936710
#define CXWnd__SetKeyTooltip_x                                     0x937260
#define CXWnd__SetMouseOver_x                                      0x9341B0
#define CXWnd__SetParent_x                                         0x935A10
#define CXWnd__StartFade_x                                         0x935B30
#define CXWnd__vftable_x                                           0xB45B64
#define CXWnd__CXWnd_x                                             0x9309E0
#define CXWnd__dCXWnd_x                                            0x930F00

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x969C50

// CXWndManager
#define CXWndManager__DrawCursor_x                                 0x939C30
#define CXWndManager__DrawWindows_x                                0x939C50
#define CXWndManager__GetKeyboardFlags_x                           0x93C420
#define CXWndManager__HandleKeyboardMsg_x                          0x93BFE0
#define CXWndManager__RemoveWnd_x                                  0x93C640
#define CXWndManager__RemovePendingDeletionWnd_x                   0x93CB90

// CDBStr
#define CDBStr__GetString_x                                        0x53D980

// CharacterZoneClient
#define CharacterZoneClient__CastSpell_x                           0x4BBC70
#define CharacterZoneClient__Cur_HP_x                              0x4D1CA0
#define CharacterZoneClient__Cur_Mana_x                            0x4D93C0
#define CharacterZoneClient__GetCastingTimeModifier_x              0x4BECB0
#define CharacterZoneClient__GetFocusCastingTimeModifier_x         0x4B27B0
#define CharacterZoneClient__GetFocusRangeModifier_x               0x4B2900
#define CharacterZoneClient__GetHPRegen_x                          0x4DF160
#define CharacterZoneClient__GetEnduranceRegen_x                   0x4DF760
#define CharacterZoneClient__GetManaRegen_x                        0x4DFBA0
#define CharacterZoneClient__Max_Endurance_x                       0x64BDA0
#define CharacterZoneClient__Max_HP_x                              0x4D1AD0
#define CharacterZoneClient__Max_Mana_x                            0x64BBA0
#define CharacterZoneClient__doCombatAbility_x                     0x64E1F0
#define CharacterZoneClient__UseSkill_x                            0x4E1970
#define CharacterZoneClient__IsExpansionFlag_x                     0x5A8720
#define CharacterZoneClient__TotalEffect_x                         0x4C5110
#define CharacterZoneClient__GetPCSpellAffect_x                    0x4BFA00
#define CharacterZoneClient__SpellDuration_x                       0x4BF530
#define CharacterZoneClient__GetAdjustedSkill_x                    0x4D4A20
#define CharacterZoneClient__GetBaseSkill_x                        0x4D59C0
#define CharacterZoneClient__CanUseItem_x                          0x4D96D0

// ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8CAD30

// PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x662310

// PcClient
#define PcClient__PcClient_x                                       0x642440
#define PcClient__GetConLevel_x                                    0x644D00

// CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B98E0
#define CCharacterListWnd__EnterWorld_x                            0x4B9320
#define CCharacterListWnd__Quit_x                                  0x4B9070
#define CCharacterListWnd__UpdateList_x                            0x4B94B0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x626D80
#define EQ_Item__CreateItemTagString_x                             0x8A4F40
#define EQ_Item__IsStackable_x                                     0x8A9BE0
#define EQ_Item__GetImageNum_x                                     0x8A69D0
#define EQ_Item__CreateItemClient_x                                0x625FE0
#define EQ_Item__GetItemValue_x                                    0x8A7DA0
#define EQ_Item__ValueSellMerchant_x                               0x8AB580
#define EQ_Item__IsKeyRingItem_x                                   0x8A94E0
#define EQ_Item__CanGoInBag_x                                      0x626EA0
#define EQ_Item__IsEmpty_x                                         0x8A9040
#define EQ_Item__GetMaxItemCount_x                                 0x8A81C0
#define EQ_Item__GetHeldItem_x                                     0x8A68A0
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A4870
#define ItemClient__ItemClient_x                                   0x5A6C20
#define ItemClient__dItemClient_x                                  0x625F30

// EQ_LoadingS
#define EQ_LoadingS__SetProgressBar_x                              0x55BEA0
#define EQ_LoadingS__Array_x                                       0xC29B60

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x64C700
#define EQ_PC__GetAlternateAbilityId_x                             0x8B47C0
#define EQ_PC__GetCombatAbility_x                                  0x8B4E30
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B4EA0
#define EQ_PC__GetItemRecastTimer_x                                0x64E770
#define EQ_PC__HasLoreItem_x                                       0x645510
#define EQ_PC__AlertInventoryChanged_x                             0x644640
#define EQ_PC__GetPcZoneClient_x                                   0x670D80
#define EQ_PC__RemoveMyAffect_x                                    0x6519B0
#define EQ_PC__GetKeyRingItems_x                                   0x8B5730
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B54C0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B5A30

// EQItemList
#define EQItemList__EQItemList_x                                   0x5AEC00
#define EQItemList__add_object_x                                   0x5DC5B0
#define EQItemList__add_item_x                                     0x5AF160
#define EQItemList__delete_item_x                                  0x5AF1B0
#define EQItemList__FreeItemList_x                                 0x5AF0B0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x53A530

// EQPlayer
#define EQPlayer__ChangeBoneStringSprite_x                         0x663B90
#define EQPlayer__dEQPlayer_x                                      0x656EE0
#define EQPlayer__DoAttack_x                                       0x66BA20
#define EQPlayer__EQPlayer_x                                       0x6575A0
#define EQPlayer__SetNameSpriteState_x                             0x65B880
#define EQPlayer__SetNameSpriteTint_x                              0x65C740
#define PlayerBase__HasProperty_j_x                                0x99C170
#define EQPlayer__IsTargetable_x                                   0x99C610
#define EQPlayer__CanSee_x                                         0x99C470
#define EQPlayer__CanSee1_x                                        0x99C540
#define PlayerBase__GetVisibilityLineSegment_x                     0x99C230

// PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x66E820
#define PlayerZoneClient__GetLevel_x                               0x670DC0
#define PlayerZoneClient__IsValidTeleport_x                        0x5DD720
#define PlayerZoneClient__LegalPlayerRace_x                        0x555230

// EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x666940
#define EQPlayerManager__GetSpawnByName_x                          0x6669F0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x666A80

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x62A590
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x62A610
#define KeypressHandler__AttachKeyToEqCommand_x                    0x62A650
#define KeypressHandler__ClearCommandStateArray_x                  0x62BA60
#define KeypressHandler__HandleKeyDown_x                           0x62BA80
#define KeypressHandler__HandleKeyUp_x                             0x62BB20
#define KeypressHandler__SaveKeymapping_x                          0x62BF70

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C8C40

// StringTable
#define StringTable__getString_x                                   0x8C39E0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x651620
#define PcZoneClient__RemovePetEffect_x                            0x651C50
#define PcZoneClient__HasAlternateAbility_x                        0x64B9D0
#define PcZoneClient__GetCurrentMod_x                              0x4E4A20
#define PcZoneClient__GetModCap_x                                  0x4E4920
#define PcZoneClient__CanEquipItem_x                               0x64C0A0
#define PcZoneClient__GetItemByID_x                                0x64EBF0
#define PcZoneClient__GetItemByItemClass_x                         0x64ED40
#define PcZoneClient__RemoveBuffEffect_x                           0x651C70
#define PcZoneClient__BandolierSwap_x                              0x64CCB0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64E710

// Doors
#define EQSwitch__UseSwitch_x                                      0x5E2310

// IconCache
#define IconCache__GetIcon_x                                       0x722B00

// CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x71A620
#define CContainerMgr__CloseContainer_x                            0x71A8F0
#define CContainerMgr__OpenExperimentContainer_x                   0x71B370

// CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D94F0

// CHelpWnd
#define CHelpWnd__SetFile_x                                        0x61EFA0

// CLootWnd
#define CLootWnd__LootAll_x                                        0x7778F0
#define CLootWnd__RequestLootSlot_x                                0x776B20

// EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x57C640
#define EQ_Spell__SpellAffects_x                                   0x57CAB0
#define EQ_Spell__SpellAffectBase_x                                0x57C870
#define EQ_Spell__IsStackable_x                                    0x4C96F0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9540
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6CA0
#define EQ_Spell__IsSPAStacking_x                                  0x57D900
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x57CE10
#define EQ_Spell__IsNoRemove_x                                     0x4C96D0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57D910
#define __IsResEffectSpell_x                                       0x4C8B30

// EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD1C0

// EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D3360

// CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x8202D0
#define CTargetWnd__WndNotification_x                              0x81FB60
#define CTargetWnd__RefreshTargetBuffs_x                           0x81FE30
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x81ECD0

// CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x8248D0

// CTaskManager
#define CTaskManager__GetEntry_x                                   0x537F60
#define CTaskManager__HandleMessage_x                              0x5363E0
#define CTaskManager__GetTaskStatus_x                              0x538010
#define CTaskManager__GetElementDescription_x                      0x538090

// EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x577740
#define EqSoundManager__PlayScriptMp3_x                            0x577A00
#define EqSoundManager__SoundAssistPlay_x                          0x6891A0
#define EqSoundManager__WaveInstancePlay_x                         0x688710

// CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52B7D0

// CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x957FB0

// CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x563850
#define CAltAbilityData__GetMercMaxRank_x                          0x5637E0
#define CAltAbilityData__GetMaxRank_x                              0x558F40

// CTargetRing
#define CTargetRing__Cast_x                                        0x61D0C0

// CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9520
#define CharacterBase__CreateItemGlobalIndex_x                     0x5128A0
#define CharacterBase__CreateItemIndex_x                           0x6251A0
#define CharacterBase__GetItemPossession_x                         0x4FE590
#define CharacterBase__GetItemByGlobalIndex_x                      0x8DB950
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8DB9B0

// CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x7017F0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x702020
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x7020D0

// messages
#define msg_spell_worn_off_x                                       0x5A0A60
#define msg_new_text_x                                             0x5957E0
#define __msgTokenTextParam_x                                      0x5A2F80
#define msgTokenText_x                                             0x5A31D0

// SpellManager
#define SpellManager__vftable_x                                    0xAEE56C
#define SpellManager__SpellManager_x                               0x68C4D0
#define Spellmanager__LoadTextSpells_x                             0x68CDC0
#define SpellManager__GetSpellByGroupAndRank_x                     0x68C6A0

// CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x 0x9A0030

// ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D3D00
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D3F80

// CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x770170

// CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x71ED10
#define CCursorAttachment__AttachToCursor1_x                       0x71ED50
#define CCursorAttachment__Deactivate_x                            0x71FD40

// CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9681C0
#define CEQSuiteTextureLoader__GetTexture_x                        0x967E80

// CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50FE10
#define CFindItemWnd__WndNotification_x                            0x5108F0
#define CFindItemWnd__Update_x                                     0x511460
#define CFindItemWnd__PickupSelectedItem_x                         0x50F660

// IString
#define IString__Append_x                                          0x4F0F20

// Camera
#define CDisplay__cameraType_x                                     0xE03788
#define EverQuest__Cameras_x                                       0xEC6C1C

// LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x5186B0
#define LootFiltersManager__GetItemFilterData_x                    0x517FB0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x517FE0
#define LootFiltersManager__SetItemLootFilter_x                    0x518200

// COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C74E0

// CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A5C80
#define CResolutionHandler__GetWindowedStyle_x                     0x683CD0

// CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x717400

// CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E8FF0
#define CDistillerInfo__Instance_x                                 0x8E8F90

// CGroupWnd
#define CGroupWnd__WndNotification_x                               0x7363C0
#define CGroupWnd__UpdateDisplay_x                                 0x735720

// ItemBase
#define ItemBase__IsLore_x                                         0x8A9590
#define ItemBase__IsLoreEquipped_x                                 0x8A9610

// EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5DC510
#define EQPlacedItemManager__GetItemByGuid_x                       0x5DC650
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5DC6B0

// RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x679490
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x67CE30

// CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x5061B0

// FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F2E60
#define FactionManagerClient__HandleFactionMessage_x               0x4F34D0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F3AD0
#define FactionManagerClient__GetMaxFaction_x                      0x4F3AEF
#define FactionManagerClient__GetMinFaction_x                      0x4F3AA0

// BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FE560

// ArrayClass
#define ArrayClass__DeleteElement_x                                0x92F490

// AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BF90

// ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FE900

// MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x562CF0

// CTargetManager
#define CTargetManager__Get_x                                      0x68FD30

// RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x679490

// CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8EC0

// EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5AF050

// EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF642B0

// KeyCombo
#define KeyCombo__GetTextDescription_x                             0x919C70

//
// EQGraphicsDX9.dll offsets (maybe this should go in eqgraphics.h?)
//

#define __eqgraphics_fopen_x                                       0x101473C8
#define CParticleSystem__Render_x                                  0x10071100
