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
#if defined(TEST)
#include "eqgame-private(test).h"
#endif
#endif

#define __ClientName                                              "eqgame"
#define __ExpectedVersionDate                                     "Apr 18 2019"
#define __ExpectedVersionTime                                     "16:59:25"
#define __ActualVersionDate_x                                      0xAD64E4
#define __ActualVersionTime_x                                      0xAD64D8
#define __ActualVersionBuild_x                                     0xAD6F7C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x61B4F0
#define __MemChecker1_x                                            0x8F0590
#define __MemChecker2_x                                            0x6AA210
#define __MemChecker3_x                                            0x6AA160
#define __MemChecker4_x                                            0x8475F0
#define __EncryptPad0_x                                            0xC0B9A8
#define __EncryptPad1_x                                            0xC69928
#define __EncryptPad2_x                                            0xC1C220
#define __EncryptPad3_x                                            0xC1BE20
#define __EncryptPad4_x                                            0xC5A198
#define __EncryptPad5_x                                            0xF34300
#define __AC1_x                                                    0x804056
#define __AC2_x                                                    0x5D521F
#define __AC3_x                                                    0x5DC92F
#define __AC4_x                                                    0x5E07B0
#define __AC5_x                                                    0x5E6A20
#define __AC6_x                                                    0x5EB0B6
#define __AC7_x                                                    0x5D4C90
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1F14CC

// Direct Input
#define DI8__Main_x                                                0xF34320
#define DI8__Keyboard_x                                            0xF34324
#define DI8__Mouse_x                                               0xF338E0
#define DI8__Mouse_Copy_x                                          0xE8EFBC
#define DI8__Mouse_Check_x                                         0xF34654
#define __AutoSkillArray_x                                         0xE8FED4
#define __Attack_x                                                 0xF2DCEB
#define __Autofire_x                                               0xF2DCEC
#define __BindList_x                                               0xBFA3E8
#define g_eqCommandStates_x                                        0xBFB160
#define __Clicks_x                                                 0xE8F074
#define __CommandList_x                                            0xBFBD20
#define __CurrentMapLabel_x                                        0x104ED94
#define __CurrentSocial_x                                          0xBE4730
#define __DoAbilityList_x                                          0xEC580C
#define __do_loot_x                                                0x5A1BA0
#define __DrawHandler_x                                            0x16CB768
#define __GroupCount_x                                             0xE7F272
#define __Guilds_x                                                 0xE857C8
#define __gWorld_x                                                 0xE8167C
#define __HWnd_x                                                   0xF338E4
#define __heqmain_x                                                0x103E938
#define __InChatMode_x                                             0xE8EFA4
#define __LastTell_x                                               0xE90F08
#define __LMouseHeldTime_x                                         0xE8F0E0
#define __Mouse_x                                                  0xF3430C
#define __MouseLook_x                                              0xE8F03A
#define __MouseEventTime_x                                         0xF2E7CC
#define __gpbCommandEvent_x                                        0xE8158C
#define __NetStatusToggle_x                                        0xE8F03D
#define __PCNames_x                                                0xE904B8
#define __RangeAttackReady_x                                       0xE901B8
#define __RMouseHeldTime_x                                         0xE8F0DC
#define __RunWalkState_x                                           0xE8EFA8
#define __ScreenMode_x                                             0xDCD1B8
#define __ScreenX_x                                                0xE8EF5C
#define __ScreenY_x                                                0xE8EF58
#define __ScreenXMax_x                                             0xE8EF60
#define __ScreenYMax_x                                             0xE8EF64
#define __ServerHost_x                                             0xE817DB
#define __ServerName_x                                             0xEC57CC
#define __ShiftKeyDown_x                                           0xE8F634
#define __ShowNames_x                                              0xE90374
#define __Socials_x                                                0xEC58CC
#define __SubscriptionType_x                                       0x1090930
#define __TargetAggroHolder_x                                      0x1051750
#define __ZoneType_x                                               0xE8F438
#define __GroupAggro_x                                             0x1051790
#define __LoginName_x                                              0xF33FA4
#define __Inviter_x                                                0xF2DC68
#define __AttackOnAssist_x                                         0xE90330
#define __UseTellWindows_x                                         0xE90654
#define __gfMaxZoomCameraDistance_x                                0xACB970
#define __gfMaxCameraDistance_x                                    0xAF8E38
#define __pulAutoRun_x                                             0xE8F058
#define __pulForward_x                                             0xE9068C
#define __pulBackward_x                                            0xE90690
#define __pulTurnRight_x                                           0xE90694
#define __pulTurnLeft_x                                            0xE90698
#define __pulStrafeLeft_x                                          0xE9069C
#define __pulStrafeRight_x                                         0xE906A0

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE81B60
#define instEQZoneInfo_x                                           0xE8F230
#define pinstActiveBanker_x                                        0xE81634
#define pinstActiveCorpse_x                                        0xE8162C
#define pinstActiveGMaster_x                                       0xE81630
#define pinstActiveMerchant_x                                      0xE81628
#define pinstAltAdvManager_x                                       0xDCDE30
#define pinstBandageTarget_x                                       0xE81644
#define pinstCamActor_x                                            0xDCD1A8
#define pinstCDBStr_x                                              0xDCCB5C
#define pinstCDisplay_x                                            0xE8168C
#define pinstCEverQuest_x                                          0x103E944
#define pinstEverQuestInfo_x                                       0xE8EF50
#define pinstCharData_x                                            0xE7F250
#define pinstCharSpawn_x                                           0xE81680
#define pinstControlledMissile_x                                   0xE81B14
#define pinstControlledPlayer_x                                    0xE81680
#define pinstCResolutionHandler_x                                  0x16CB998
#define pinstCSidlManager_x                                        0x16CA934
#define pinstCXWndManager_x                                        0x16CA928
#define instDynamicZone_x                                          0xE856A0
#define pinstDZMember_x                                            0xE857B0
#define pinstDZTimerInfo_x                                         0xE857B4
#define pinstEqLogin_x                                             0xF338F0
#define instEQMisc_x                                               0xDCCAA0
#define pinstEQSoundManager_x                                      0xDCED58
#define pinstEQSpellStrings_x                                      0xC8E2B0
#define instExpeditionLeader_x                                     0xE856EA
#define instExpeditionName_x                                       0xE8572A
#define pinstGroup_x                                               0xE7F26E
#define pinstImeManager_x                                          0x16CA92C
#define pinstLocalPlayer_x                                         0xE815A4
#define pinstMercenaryData_x                                       0xF302BC
#define pinstMercenaryStats_x                                      0x105189C
#define pinstModelPlayer_x                                         0xE8163C
#define pinstPCData_x                                              0xE7F250
#define pinstSkillMgr_x                                            0xF32430
#define pinstSpawnManager_x                                        0xF30ED8
#define pinstSpellManager_x                                        0xF32650
#define pinstSpellSets_x                                           0xF26914
#define pinstStringTable_x                                         0xE8146C
#define pinstSwitchManager_x                                       0xE7F100
#define pinstTarget_x                                              0xE81678
#define pinstTargetObject_x                                        0xE81688
#define pinstTargetSwitch_x                                        0xE7F254
#define pinstTaskMember_x                                          0xDCC934
#define pinstTrackTarget_x                                         0xE81684
#define pinstTradeTarget_x                                         0xE81638
#define instTributeActive_x                                        0xDCCAC1
#define pinstViewActor_x                                           0xDCD1A4
#define pinstWorldData_x                                           0xE81594
#define pinstZoneAddr_x                                            0xE8F4D0
#define pinstPlayerPath_x                                          0xF30F70
#define pinstTargetIndicator_x                                     0xF328B8
#define EQObject_Top_x                                             0xE815A0
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDCD270
#define pinstCAchievementsWnd_x                                    0xDCD260
#define pinstCActionsWnd_x                                         0xDCCC34
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDCD0E4
#define pinstCAdvancedLootWnd_x                                    0xDCCC2C
#define pinstCAdventureLeaderboardWnd_x                            0x1048568
#define pinstCAdventureRequestWnd_x                                0x1048618
#define pinstCAdventureStatsWnd_x                                  0x10486C8
#define pinstCAggroMeterWnd_x                                      0xDCD140
#define pinstCAlarmWnd_x                                           0xDCD1A0
#define pinstCAlertHistoryWnd_x                                    0xDCD20C
#define pinstCAlertStackWnd_x                                      0xDCD158
#define pinstCAlertWnd_x                                           0xDCD168
#define pinstCAltStorageWnd_x                                      0x1048A28
#define pinstCAudioTriggersWindow_x                                0xC805E0
#define pinstCAuraWnd_x                                            0xDCD138
#define pinstCAvaZoneWnd_x                                         0xDCD210
#define pinstCBandolierWnd_x                                       0xDCD16C
#define pinstCBankWnd_x                                            0xDCD1FC
#define pinstCBarterMerchantWnd_x                                  0x1049C68
#define pinstCBarterSearchWnd_x                                    0x1049D18
#define pinstCBarterWnd_x                                          0x1049DC8
#define pinstCBazaarConfirmationWnd_x                              0xDCD154
#define pinstCBazaarSearchWnd_x                                    0xDCCC64
#define pinstCBazaarWnd_x                                          0xDCD180
#define pinstCBlockedBuffWnd_x                                     0xDCD1E4
#define pinstCBlockedPetBuffWnd_x                                  0xDCD214
#define pinstCBodyTintWnd_x                                        0xDCD128
#define pinstCBookWnd_x                                            0xDCD188
#define pinstCBreathWnd_x                                          0xDCD27C
#define pinstCBuffWindowNORMAL_x                                   0xDCD1B0
#define pinstCBuffWindowSHORT_x                                    0xDCD1BC
#define pinstCBugReportWnd_x                                       0xDCD274
#define pinstCButtonWnd_x                                          0x16CAB98
#define pinstCCastingWnd_x                                         0xDCD264
#define pinstCCastSpellWnd_x                                       0xDCD0D8
//#define pinstCCharacterCreationWnd_x                               0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDCD284
#define pinstCChatWindowManager_x                                  0x104A888
#define pinstCClaimWnd_x                                           0x104A9E0
#define pinstCColorPickerWnd_x                                     0xDCCC14
#define pinstCCombatAbilityWnd_x                                   0xDCD144
#define pinstCCombatSkillsSelectWnd_x                              0xDCCC38
#define pinstCCompassWnd_x                                         0xDCD114
#define pinstCConfirmationDialog_x                                 0x104F8E0
#define pinstCContainerMgr_x                                       0xDCD26C
#define pinstCContextMenuManager_x                                 0x16CA8E8
#define pinstCCursorAttachment_x                                   0xDCD254
#define pinstCDynamicZoneWnd_x                                     0x104AFA8
#define pinstCEditLabelWnd_x                                       0xDCD194
#define pinstCEQMainWnd_x                                          0x104B1F0
#define pinstCEventCalendarWnd_x                                   0xDCCC04
#define pinstCExtendedTargetWnd_x                                  0xDCD130
#define pinstCFacePick_x                                           0xDCCC0C
#define pinstCFactionWnd_x                                         0xDCD25C
#define pinstCFellowshipWnd_x                                      0x104B3F0
#define pinstCFileSelectionWnd_x                                   0xDCCC24
#define pinstCFindItemWnd_x                                        0xDCD198
#define pinstCFindLocationWnd_x                                    0x104B548
#define pinstCFriendsWnd_x                                         0xDCCC48
#define pinstCGemsGameWnd_x                                        0xDCD178
#define pinstCGiveWnd_x                                            0xDCD19C
#define pinstCGroupSearchFiltersWnd_x                              0xDCD150
#define pinstCGroupSearchWnd_x                                     0x104B940
#define pinstCGroupWnd_x                                           0x104B9F0
#define pinstCGuildBankWnd_x                                       0xE90314
#define pinstCGuildCreationWnd_x                                   0x104BB50
#define pinstCGuildMgmtWnd_x                                       0x104BC00
#define pinstCharacterCreation_x                                   0xDCD148
#define pinstCHelpWnd_x                                            0xDCD0F8
#define pinstCHeritageSelectionWnd_x                               0xDCCC20
#define pinstCHotButtonWnd_x                                       0x104DD58
#define pinstCHotButtonWnd1_x                                      0x104DD58
#define pinstCHotButtonWnd2_x                                      0x104DD5C
#define pinstCHotButtonWnd3_x                                      0x104DD60
#define pinstCHotButtonWnd4_x                                      0x104DD64
#define pinstCIconSelectionWnd_x                                   0xDCD228
#define pinstCInspectWnd_x                                         0xDCD234
#define pinstCInventoryWnd_x                                       0xDCD170
#define pinstCInvSlotMgr_x                                         0xDCD204
#define pinstCItemDisplayManager_x                                 0x104E2E8
#define pinstCItemExpTransferWnd_x                                 0x104E41C
#define pinstCItemOverflowWnd_x                                    0xDCCCCC
#define pinstCJournalCatWnd_x                                      0xDCCC44
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDCCC08
#define pinstCKeyRingWnd_x                                         0xDCD1D4
#define pinstCLargeDialogWnd_x                                     0x1050560
#define pinstCLayoutCopyWnd_x                                      0x104E768
#define pinstCLFGuildWnd_x                                         0x104E818
#define pinstCLoadskinWnd_x                                        0xDCD184
#define pinstCLootFiltersCopyWnd_x                                 0xC9C8A8
#define pinstCLootFiltersWnd_x                                     0xDCD18C
#define pinstCLootSettingsWnd_x                                    0xDCD1CC
#define pinstCLootWnd_x                                            0xDCCBF8
#define pinstCMailAddressBookWnd_x                                 0xDCD21C
#define pinstCMailCompositionWnd_x                                 0xDCD1EC
#define pinstCMailIgnoreListWnd_x                                  0xDCD224
#define pinstCMailWnd_x                                            0xDCD1D0
#define pinstCManageLootWnd_x                                      0xDCE2E0
#define pinstCMapToolbarWnd_x                                      0xDCD174
#define pinstCMapViewWnd_x                                         0xDCD164
#define pinstCMarketplaceWnd_x                                     0xDCCC10
#define pinstCMerchantWnd_x                                        0xDCCC3C
#define pinstCMIZoneSelectWnd_x                                    0x104F050
#define pinstCMusicPlayerWnd_x                                     0xDCD1DC
#define pinstCNameChangeMercWnd_x                                  0xDCD11C
#define pinstCNameChangePetWnd_x                                   0xDCD10C
#define pinstCNameChangeWnd_x                                      0xDCD48C
#define pinstCNoteWnd_x                                            0xDCD0E0
#define pinstCObjectPreviewWnd_x                                   0xDCCC30
#define pinstCOptionsWnd_x                                         0xDCD17C
#define pinstCPetInfoWnd_x                                         0xDCD1F0
#define pinstCPetitionQWnd_x                                       0xDCCC50
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDCD124
#define pinstCPlayerWnd_x                                          0xDCD190
#define pinstCPopupWndManager_x                                    0x104F8E0
#define pinstCProgressionSelectionWnd_x                            0x104F990
#define pinstCPurchaseGroupWnd_x                                   0xDCD0D4
#define pinstCPurchaseWnd_x                                        0xDCCC40
#define pinstCPvPLeaderboardWnd_x                                  0x104FA40
#define pinstCPvPStatsWnd_x                                        0x104FAF0
#define pinstCQuantityWnd_x                                        0xDCD22C
#define pinstCRaceChangeWnd_x                                      0xDCCC1C
#define pinstCRaidOptionsWnd_x                                     0xDCD160
#define pinstCRaidWnd_x                                            0xDCD238
#define pinstCRealEstateItemsWnd_x                                 0xDCD278
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDCCC00
#define pinstCRealEstateManageWnd_x                                0xDCD1D8
#define pinstCRealEstateNeighborhoodWnd_x                          0xDCD1F4
#define pinstCRealEstatePlotSearchWnd_x                            0xDCD218
#define pinstCRealEstatePurchaseWnd_x                              0xDCD24C
#define pinstCRespawnWnd_x                                         0xDCD14C
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDCD134
#define pinstCSendMoneyWnd_x                                       0xDCD1C8
#define pinstCServerListWnd_x                                      0xDCD208
#define pinstCSkillsSelectWnd_x                                    0xDCCC18
#define pinstCSkillsWnd_x                                          0xDCCBFC
#define pinstCSocialEditWnd_x                                      0xDCD258
#define pinstCSocialWnd_x                                          0xDCD13C
#define pinstCSpellBookWnd_x                                       0xDCD12C
#define pinstCStoryWnd_x                                           0xDCD0F0
#define pinstCTargetOfTargetWnd_x                                  0x1051920
#define pinstCTargetWnd_x                                          0xDCD1E8
#define pinstCTaskOverlayWnd_x                                     0xDCD220
#define pinstCTaskSelectWnd_x                                      0x1051A78
#define pinstCTaskManager_x                                        0xC9D1F8
#define pinstCTaskTemplateSelectWnd_x                              0x1051B28
#define pinstCTaskWnd_x                                            0x1051BD8
#define pinstCTextEntryWnd_x                                       0xDCD118
#define pinstCTimeLeftWnd_x                                        0xDCCC28
#define pinstCTipWndCONTEXT_x                                      0x1051DDC
#define pinstCTipWndOFDAY_x                                        0x1051DD8
#define pinstCTitleWnd_x                                           0x1051E88
#define pinstCTrackingWnd_x                                        0xDCD200
#define pinstCTradeskillWnd_x                                      0x1051FF0
#define pinstCTradeWnd_x                                           0xDCD120
#define pinstCTrainWnd_x                                           0xDCD230
#define pinstCTributeBenefitWnd_x                                  0x10521F0
#define pinstCTributeMasterWnd_x                                   0x10522A0
#define pinstCTributeTrophyWnd_x                                   0x1052350
#define pinstCVideoModesWnd_x                                      0xDCD23C
#define pinstCVoiceMacroWnd_x                                      0xF33020
#define pinstCVoteResultsWnd_x                                     0xDCD0DC
#define pinstCVoteWnd_x                                            0xDCCC4C
#define pinstCWebManager_x                                         0xF3369C
#define pinstCZoneGuideWnd_x                                       0xDCD1E0
#define pinstCZonePathWnd_x                                        0xDCD1F8

#define pinstEQSuiteTextureLoader_x                                0xC6B410
#define pinstItemIconCache_x                                       0x104B1A8
#define pinstLootFiltersManager_x                                  0xC9C958
#define pinstRewardSelectionWnd_x                                  0x1050238

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC1BE10
#define __CastRay_x                                                0x59D000
#define __CastRay2_x                                               0x59D050
#define __ConvertItemTags_x                                        0x5B8780
#define __CrashHandler_x                                           0x850F30
#define __EQGetTime_x                                              0x8F0070
#define __ExecuteCmd_x                                             0x595930
#define __FixHeading_x                                             0x980120
#define __GameLoop_x                                               0x6A96D0
#define __get_bearing_x                                            0x59CB50
#define __get_melee_range_x                                        0x59D240
#define __GetAnimationCache_x                                      0x70E530
#define __GetGaugeValueFromEQ_x                                    0x802860
#define __GetLabelFromEQ_x                                         0x803FE0
#define __GetXTargetType_x                                         0x981BF0
#define __HandleMouseWheel_x                                       0x6AA2C0
#define __HeadingDiff_x                                            0x980190
#define __HelpPath_x                                               0xF2E3BC
#define __LoadFrontEnd_x                                           0x6A61C0
#define __NewUIINI_x                                               0x802530
#define __pCrashHandler_x                                          0x106F758
#define __ProcessGameEvents_x                                      0x5FC770
#define __ProcessMouseEvent_x                                      0x5FBF30
#define __SaveColors_x                                             0x5458D0
#define __STMLToText_x                                             0x9237A0
#define __ToggleKeyRingItem_x                                      0x508A20
#define CrashDetected_x                                            0x6A7C20
#define DrawNetStatus_x                                            0x628750
#define Expansion_HoT_x                                            0xE9031C
#define Teleport_Table_Size_x                                      0xE81694
#define Teleport_Table_x                                           0xE7F460
#define Util__FastTime_x                                           0x8EFC30
#define wwsCrashReportCheckForUploader_x                           0x851D90
#define wwsCrashReportPlatformLaunchUploader_x                     0x854450

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48B630
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4944C0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x494280
#define CAdvancedLootWnd__AddPlayerToList_x                        0x48EB80
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x48DFE0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x54D490
#define AltAdvManager__IsAbilityReady_x                            0x54C3E0
#define AltAdvManager__GetAAById_x                                 0x54C5E0
#define AltAdvManager__CanTrainAbility_x                           0x54C650
#define AltAdvManager__CanSeeAbility_x                             0x54C9B0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C74B0
#define CharacterZoneClient__HasSkill_x                            0x4D2380
#define CharacterZoneClient__MakeMeVisible_x                       0x4D3AA0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BB950
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B8090
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D6470
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D6550
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D6630
#define CharacterZoneClient__FindAffectSlot_x                      0x4C0440
#define CharacterZoneClient__BardCastBard_x                        0x4C30B0
#define CharacterZoneClient__GetMaxEffects_x                       0x4B8160
#define CharacterZoneClient__GetEffect_x                           0x4B7FD0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C1440
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C1510
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C1560
#define CharacterZoneClient__CalcAffectChange_x                    0x4C16B0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C1880
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4AFE70
#define CharacterZoneClient__FindItemByGuid_x                      0x4D4A10
#define CharacterZoneClient__FindItemByRecord_x                    0x4D4480

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6CFDB0
#define CBankWnd__WndNotification_x                                0x6CFB90

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6DD6E0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x60B260
#define CButtonWnd__CButtonWnd_x                                   0x91FBA0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6FD6B0
#define CChatManager__InitContextMenu_x                            0x6F6A30
#define CChatManager__FreeChatWindow_x                             0x6FC270
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E5D60
#define CChatManager__SetLockedActiveChatWindow_x                  0x6FD330

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x934310
#define CContextMenu__dCContextMenu_x                              0x934540
#define CContextMenu__AddMenuItem_x                                0x934550
#define CContextMenu__RemoveMenuItem_x                             0x934860
#define CContextMenu__RemoveAllMenuItems_x                         0x934880
#define CContextMenu__CheckMenuItem_x                              0x934900
#define CContextMenu__SetMenuItem_x                                0x934780
#define CContextMenu__AddSeparator_x                               0x9346E0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x934EA0
#define CContextMenuManager__RemoveMenu_x                          0x934F10
#define CContextMenuManager__PopupMenu_x                           0x934FD0
#define CContextMenuManager__Flush_x                               0x934E40
#define CContextMenuManager__GetMenu_x                             0x4965E0
#define CContextMenuManager__CreateDefaultMenu_x                   0x708D40

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D0A30
#define CChatService__GetFriendName_x                              0x8D0A40

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6FDF40
#define CChatWindow__Clear_x                                       0x6FF1E0
#define CChatWindow__WndNotification_x                             0x6FF970

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x9317A0
#define CComboWnd__Draw_x                                          0x930C90
#define CComboWnd__GetCurChoice_x                                  0x9315E0
#define CComboWnd__GetListRect_x                                   0x931140
#define CComboWnd__GetTextRect_x                                   0x931810
#define CComboWnd__InsertChoice_x                                  0x9312D0
#define CComboWnd__SetColors_x                                     0x9312A0
#define CComboWnd__SetChoice_x                                     0x9315B0
#define CComboWnd__GetItemCount_x                                  0x9315F0
#define CComboWnd__GetCurChoiceText_x                              0x931630
#define CComboWnd__GetChoiceText_x                                 0x931600
#define CComboWnd__InsertChoiceAtIndex_x                           0x931370

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x706730
#define CContainerWnd__vftable_x                                   0xADF748
#define CContainerWnd__SetContainer_x                              0x707CA0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x545690
#define CDisplay__GetClickedActor_x                                0x538630
#define CDisplay__GetUserDefinedColor_x                            0x530D10
#define CDisplay__GetWorldFilePath_x                               0x53A080
#define CDisplay__is3dON_x                                         0x535300
#define CDisplay__ReloadUI_x                                       0x53F7A0
#define CDisplay__WriteTextHD2_x                                   0x5350E0
#define CDisplay__TrueDistance_x                                   0x53BCE0
#define CDisplay__SetViewActor_x                                   0x537F80
#define CDisplay__GetFloorHeight_x                                 0x5353C0
#define CDisplay__SetRenderWindow_x                                0x533CF0
#define CDisplay__ToggleScreenshotMode_x                           0x537A50

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x953DE0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x937890
#define CEditWnd__GetCharIndexPt_x                                 0x938790
#define CEditWnd__GetDisplayString_x                               0x938630
#define CEditWnd__GetHorzOffset_x                                  0x936EC0
#define CEditWnd__GetLineForPrintableChar_x                        0x939990
#define CEditWnd__GetSelStartPt_x                                  0x938A40
#define CEditWnd__GetSTMLSafeText_x                                0x938450
#define CEditWnd__PointFromPrintableChar_x                         0x9395C0
#define CEditWnd__SelectableCharFromPoint_x                        0x939730
#define CEditWnd__SetEditable_x                                    0x938B10
#define CEditWnd__SetWindowTextA_x                                 0x9381D0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5EA5E0
#define CEverQuest__ClickedPlayer_x                                0x5DC710
#define CEverQuest__CreateTargetIndicator_x                        0x5F9A20
#define CEverQuest__DeleteTargetIndicator_x                        0x5F9AB0
#define CEverQuest__DoTellWindow_x                                 0x4E5E90
#define CEverQuest__OutputTextToLog_x                              0x4E60C0
#define CEverQuest__DropHeldItemOnGround_x                         0x5D1750
#define CEverQuest__dsp_chat_x                                     0x4E6450
#define CEverQuest__trimName_x                                     0x5F5D00
#define CEverQuest__Emote_x                                        0x5EADF0
#define CEverQuest__EnterZone_x                                    0x5E4DD0
#define CEverQuest__GetBodyTypeDesc_x                              0x5EF5A0
#define CEverQuest__GetClassDesc_x                                 0x5EFBE0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5F01E0
#define CEverQuest__GetDeityDesc_x                                 0x5F8370
#define CEverQuest__GetLangDesc_x                                  0x5F03A0
#define CEverQuest__GetRaceDesc_x                                  0x5EFBC0
#define CEverQuest__InterpretCmd_x                                 0x5F8940
#define CEverQuest__LeftClickedOnPlayer_x                          0x5D5940
#define CEverQuest__LMouseUp_x                                     0x5D3CC0
#define CEverQuest__RightClickedOnPlayer_x                         0x5D6220
#define CEverQuest__RMouseUp_x                                     0x5D4C50
#define CEverQuest__SetGameState_x                                 0x5D14E0
#define CEverQuest__UPCNotificationFlush_x                         0x5F5C00
#define CEverQuest__IssuePetCommand_x                              0x5F17A0
#define CEverQuest__ReportSuccessfulHit_x                          0x5EC1F0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x718580
#define CGaugeWnd__CalcLinesFillRect_x                             0x7185E0
#define CGaugeWnd__Draw_x                                          0x717C80

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ACB20
#define CGuild__GetGuildName_x                                     0x4ABC00
#define CGuild__GetGuildIndex_x                                    0x4ABF90

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x733930

//CHotButton
#define CHotButton__SetButtonSize_x                                0x60B620

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x7407D0
#define CInvSlotMgr__MoveItem_x                                    0x73F4E0
#define CInvSlotMgr__SelectSlot_x                                  0x7408A0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x73DD90
#define CInvSlot__SliderComplete_x                                 0x73BAF0
#define CInvSlot__GetItemBase_x                                    0x73B480
#define CInvSlot__UpdateItem_x                                     0x73B5F0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7422E0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x741490
#define CInvSlotWnd__HandleLButtonUp_x                             0x741E60

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7FEA90
#define CItemDisplayWnd__UpdateStrings_x                           0x750730
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x74A480
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x74A9B0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x750D40
#define CItemDisplayWnd__AboutToShow_x                             0x750380
#define CItemDisplayWnd__WndNotification_x                         0x752240
#define CItemDisplayWnd__RequestConvertItem_x                      0x751DC0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x74F3E0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x7501A0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x836610

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x756340

// CLabel 
#define CLabel__Draw_x                                             0x75BDB0

// CListWnd
#define CListWnd__CListWnd_x                                       0x909F40
#define CListWnd__dCListWnd_x                                      0x90A260
#define CListWnd__AddColumn_x                                      0x90E580
#define CListWnd__AddColumn1_x                                     0x90E5D0
#define CListWnd__AddLine_x                                        0x90E960
#define CListWnd__AddString_x                                      0x90E760
#define CListWnd__CalculateFirstVisibleLine_x                      0x90E340
#define CListWnd__CalculateVSBRange_x                              0x90E120
#define CListWnd__ClearSel_x                                       0x90F140
#define CListWnd__ClearAllSel_x                                    0x90F1A0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x90FBB0
#define CListWnd__Compare_x                                        0x90DA60
#define CListWnd__Draw_x                                           0x90A360
#define CListWnd__DrawColumnSeparators_x                           0x90CB40
#define CListWnd__DrawHeader_x                                     0x90CFA0
#define CListWnd__DrawItem_x                                       0x90D3A0
#define CListWnd__DrawLine_x                                       0x90CCA0
#define CListWnd__DrawSeparator_x                                  0x90CBE0
#define CListWnd__EnableLine_x                                     0x90C420
#define CListWnd__EnsureVisible_x                                  0x90FAD0
#define CListWnd__ExtendSel_x                                      0x90F070
#define CListWnd__GetColumnTooltip_x                               0x90BF60
#define CListWnd__GetColumnMinWidth_x                              0x90BFD0
#define CListWnd__GetColumnWidth_x                                 0x90BED0
#define CListWnd__GetCurSel_x                                      0x90B860
#define CListWnd__GetItemAtPoint_x                                 0x90C690
#define CListWnd__GetItemAtPoint1_x                                0x90C700
#define CListWnd__GetItemData_x                                    0x90B8E0
#define CListWnd__GetItemHeight_x                                  0x90BCA0
#define CListWnd__GetItemIcon_x                                    0x90BA70
#define CListWnd__GetItemRect_x                                    0x90C510
#define CListWnd__GetItemText_x                                    0x90B920
#define CListWnd__GetSelList_x                                     0x90F1F0
#define CListWnd__GetSeparatorRect_x                               0x90C940
#define CListWnd__InsertLine_x                                     0x90ED50
#define CListWnd__RemoveLine_x                                     0x90EEA0
#define CListWnd__SetColors_x                                      0x90E0F0
#define CListWnd__SetColumnJustification_x                         0x90DE20
#define CListWnd__SetColumnWidth_x                                 0x90DD40
#define CListWnd__SetCurSel_x                                      0x90EFB0
#define CListWnd__SetItemColor_x                                   0x90F780
#define CListWnd__SetItemData_x                                    0x90F740
#define CListWnd__SetItemText_x                                    0x90F360
#define CListWnd__ShiftColumnSeparator_x                           0x90DEE0
#define CListWnd__Sort_x                                           0x90DBE0
#define CListWnd__ToggleSel_x                                      0x90EFE0
#define CListWnd__SetColumnsSizable_x                              0x90DF80
#define CListWnd__SetItemWnd_x                                     0x90F610
#define CListWnd__GetItemWnd_x                                     0x90BAC0
#define CListWnd__SetItemIcon_x                                    0x90F3E0
#define CListWnd__CalculateCustomWindowPositions_x                 0x90E440
#define CListWnd__SetVScrollPos_x                                  0x90DD20

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7711E0
#define CMapViewWnd__GetWorldCoordinates_x                         0x76F8F0
#define CMapViewWnd__HandleLButtonDown_x                           0x76C950

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x794540
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x794E20
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x795360
#define CMerchantWnd__SelectRecoverySlot_x                         0x7982F0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x793080
#define CMerchantWnd__SelectBuySellSlot_x                          0x79DEC0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x794150

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89E650
#define CPacketScrambler__hton_x                                   0x89E640

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x928D60
#define CSidlManager__FindScreenPieceTemplate_x                    0x929170
#define CSidlManager__FindScreenPieceTemplate1_x                   0x928F60
#define CSidlManager__CreateLabel_x                                0x7F5EB0
#define CSidlManager__CreateXWndFromTemplate_x                     0x92C110
#define CSidlManager__CreateXWndFromTemplate1_x                    0x92C2E0
#define CSidlManager__CreateXWnd_x                                 0x7F5DE0
#define CSidlManager__CreateHotButtonWnd_x                         0x7F6390

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9258F0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9257F0
#define CSidlScreenWnd__ConvertToRes_x                             0x94AD90
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x925280
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x924F70
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x925040
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x925110
#define CSidlScreenWnd__DrawSidlPiece_x                            0x925D80
#define CSidlScreenWnd__EnableIniStorage_x                         0x926250
#define CSidlScreenWnd__GetSidlPiece_x                             0x925F70
#define CSidlScreenWnd__Init1_x                                    0x924B70
#define CSidlScreenWnd__LoadIniInfo_x                              0x9262A0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x926DD0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x923F80
#define CSidlScreenWnd__StoreIniInfo_x                             0x926950
#define CSidlScreenWnd__StoreIniVis_x                              0x926CB0
#define CSidlScreenWnd__WndNotification_x                          0x925C90
#define CSidlScreenWnd__GetChildItem_x                             0x9261D0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x915980
#define CSidlScreenWnd__m_layoutCopy_x                             0x16CA7B8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x66FBB0
#define CSkillMgr__GetSkillCap_x                                   0x66FD90
#define CSkillMgr__GetNameToken_x                                  0x66F340
#define CSkillMgr__IsActivatedSkill_x                              0x66F480
#define CSkillMgr__IsCombatSkill_x                                 0x66F3C0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x935C90
#define CSliderWnd__SetValue_x                                     0x935B00
#define CSliderWnd__SetNumTicks_x                                  0x935B60

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7FBFE0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x93E450
#define CStmlWnd__CalculateHSBRange_x                              0x93F530
#define CStmlWnd__CalculateVSBRange_x                              0x93F4A0
#define CStmlWnd__CanBreakAtCharacter_x                            0x943870
#define CStmlWnd__FastForwardToEndOfTag_x                          0x944500
#define CStmlWnd__ForceParseNow_x                                  0x93E9F0
#define CStmlWnd__GetNextTagPiece_x                                0x9437D0
#define CStmlWnd__GetSTMLText_x                                    0x4F8100
#define CStmlWnd__GetVisibleText_x                                 0x93EA10
#define CStmlWnd__InitializeWindowVariables_x                      0x944350
#define CStmlWnd__MakeStmlColorTag_x                               0x93DB30
#define CStmlWnd__MakeWndNotificationTag_x                         0x93DBA0
#define CStmlWnd__SetSTMLText_x                                    0x93CBE0
#define CStmlWnd__StripFirstSTMLLines_x                            0x9455D0
#define CStmlWnd__UpdateHistoryString_x                            0x944710

// CTabWnd 
#define CTabWnd__Draw_x                                            0x93BD70
#define CTabWnd__DrawCurrentPage_x                                 0x93C450
#define CTabWnd__DrawTab_x                                         0x93C170
#define CTabWnd__GetCurrentPage_x                                  0x93B570
#define CTabWnd__GetPageInnerRect_x                                0x93B7B0
#define CTabWnd__GetTabInnerRect_x                                 0x93B6F0
#define CTabWnd__GetTabRect_x                                      0x93B5A0
#define CTabWnd__InsertPage_x                                      0x93B9C0
#define CTabWnd__SetPage_x                                         0x93B830
#define CTabWnd__SetPageRect_x                                     0x93BCB0
#define CTabWnd__UpdatePage_x                                      0x93C030
#define CTabWnd__GetPageFromTabIndex_x                             0x93C0B0
#define CTabWnd__GetCurrentTabIndex_x                              0x93B560

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x756710
#define CPageWnd__SetTabText_x                                     0x93B0B0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A6790

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x912800
#define CTextureFont__GetTextExtent_x                              0x9129C0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6A3210
#define CHtmlComponentWnd__ValidateUri_x                           0x735320
#define CHtmlWnd__SetClientCallbacks_x                             0x610510
#define CHtmlWnd__AddObserver_x                                    0x610530
#define CHtmlWnd__RemoveObserver_x                                 0x610590
#define Window__getProgress_x                                      0x84EBA0
#define Window__getStatus_x                                        0x84EBC0
#define Window__getURI_x                                           0x84EBD0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x950810

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8FFAC0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4ADE80
#define CXStr__CXStr1_x                                            0x9084E0
#define CXStr__CXStr3_x                                            0x8EC160
#define CXStr__dCXStr_x                                            0x473070
#define CXStr__operator_equal_x                                    0x8EC390
#define CXStr__operator_equal1_x                                   0x8EC3D0
#define CXStr__operator_plus_equal1_x                              0x8ECE60
#define CXStr__SetString_x                                         0x8EED50
#define CXStr__operator_char_p_x                                   0x8EC8A0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x933F30
#define CXWnd__BringToTop_x                                        0x919170
#define CXWnd__Center_x                                            0x918CF0
#define CXWnd__ClrFocus_x                                          0x918B20
#define CXWnd__Destroy_x                                           0x918BD0
#define CXWnd__DoAllDrawing_x                                      0x915110
#define CXWnd__DrawChildren_x                                      0x9150E0
#define CXWnd__DrawColoredRect_x                                   0x915570
#define CXWnd__DrawTooltip_x                                       0x913C30
#define CXWnd__DrawTooltipAtPoint_x                                0x913CF0
#define CXWnd__GetBorderFrame_x                                    0x9153D0
#define CXWnd__GetChildWndAt_x                                     0x919210
#define CXWnd__GetClientClipRect_x                                 0x9173D0
#define CXWnd__GetScreenClipRect_x                                 0x9174A0
#define CXWnd__GetScreenRect_x                                     0x917660
#define CXWnd__GetTooltipRect_x                                    0x9155C0
#define CXWnd__GetWindowTextA_x                                    0x497CE0
#define CXWnd__IsActive_x                                          0x91C0A0
#define CXWnd__IsDescendantOf_x                                    0x918070
#define CXWnd__IsReallyVisible_x                                   0x9180A0
#define CXWnd__IsType_x                                            0x919860
#define CXWnd__Move_x                                              0x918120
#define CXWnd__Move1_x                                             0x9181D0
#define CXWnd__ProcessTransition_x                                 0x918CA0
#define CXWnd__Refade_x                                            0x9184A0
#define CXWnd__Resize_x                                            0x918740
#define CXWnd__Right_x                                             0x918F30
#define CXWnd__SetFocus_x                                          0x918AE0
#define CXWnd__SetFont_x                                           0x918B50
#define CXWnd__SetKeyTooltip_x                                     0x919690
#define CXWnd__SetMouseOver_x                                      0x916520
#define CXWnd__StartFade_x                                         0x917F40
#define CXWnd__GetChildItem_x                                      0x919380
#define CXWnd__SetParent_x                                         0x917E00
#define CXWnd__Minimize_x                                          0x9187B0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x94BE20

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x91C0E0
#define CXWndManager__DrawWindows_x                                0x91C100
#define CXWndManager__GetKeyboardFlags_x                           0x91E880
#define CXWndManager__HandleKeyboardMsg_x                          0x91E480
#define CXWndManager__RemoveWnd_x                                  0x91EAD0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x91F020

// CDBStr
#define CDBStr__GetString_x                                        0x52FCC0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B9070
#define EQ_Character__Cur_HP_x                                     0x4CF360
#define EQ_Character__Cur_Mana_x                                   0x4D6B30
#define EQ_Character__GetCastingTimeModifier_x                     0x4BBFA0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AFAB0
#define EQ_Character__GetFocusRangeModifier_x                      0x4AFC00
#define EQ_Character__GetHPRegen_x                                 0x4DCAD0
#define EQ_Character__GetEnduranceRegen_x                          0x4DD0E0
#define EQ_Character__GetManaRegen_x                               0x4DD520
#define EQ_Character__Max_Endurance_x                              0x636520
#define EQ_Character__Max_HP_x                                     0x4CF190
#define EQ_Character__Max_Mana_x                                   0x636320
#define EQ_Character__doCombatAbility_x                            0x6389E0
#define EQ_Character__UseSkill_x                                   0x4DF330
#define EQ_Character__GetConLevel_x                                0x62F700
#define EQ_Character__IsExpansionFlag_x                            0x5940E0
#define EQ_Character__TotalEffect_x                                0x4C2610
#define EQ_Character__GetPCSpellAffect_x                           0x4BCB90
#define EQ_Character__SpellDuration_x                              0x4BC6C0
#define EQ_Character__GetAdjustedSkill_x                           0x4D2140
#define EQ_Character__GetBaseSkill_x                               0x4D30E0
#define EQ_Character__CanUseItem_x                                 0x4D6E40

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BD920

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x64CBB0

//PcClient
#define PcClient__PcClient_x                                       0x62CE40

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6CB0
#define CCharacterListWnd__EnterWorld_x                            0x4B66F0
#define CCharacterListWnd__Quit_x                                  0x4B6400
#define CCharacterListWnd__UpdateList_x                            0x4B6880

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x611730
#define EQ_Item__CreateItemTagString_x                             0x897FA0
#define EQ_Item__IsStackable_x                                     0x89C9B0
#define EQ_Item__GetImageNum_x                                     0x8999D0
#define EQ_Item__CreateItemClient_x                                0x610910
#define EQ_Item__GetItemValue_x                                    0x89AC30
#define EQ_Item__ValueSellMerchant_x                               0x89E1E0
#define EQ_Item__IsKeyRingItem_x                                   0x89C300
#define EQ_Item__CanGoInBag_x                                      0x611850
#define EQ_Item__IsEmpty_x                                         0x89BE30
#define EQ_Item__GetMaxItemCount_x                                 0x89B000
#define EQ_Item__GetHeldItem_x                                     0x8998A0
#define EQ_Item__GetAugmentFitBySlot_x                             0x8978E0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x54E180
#define EQ_LoadingS__Array_x                                       0xBF35F8

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x636E80
#define EQ_PC__GetAlternateAbilityId_x                             0x8A7390
#define EQ_PC__GetCombatAbility_x                                  0x8A7A00
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A7A70
#define EQ_PC__GetItemRecastTimer_x                                0x638F60
#define EQ_PC__HasLoreItem_x                                       0x62FE70
#define EQ_PC__AlertInventoryChanged_x                             0x62F040
#define EQ_PC__GetPcZoneClient_x                                   0x65B400
#define EQ_PC__RemoveMyAffect_x                                    0x63C190
#define EQ_PC__GetKeyRingItems_x                                   0x8A8310
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A8090
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A8600

// EQItemList 
#define EQItemList__EQItemList_x                                   0x59A620
#define EQItemList__add_object_x                                   0x5C6EA0
#define EQItemList__add_item_x                                     0x59AB70
#define EQItemList__delete_item_x                                  0x59ABC0
#define EQItemList__FreeItemList_x                                 0x59AAC0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x52D280

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x64E430
#define EQPlayer__dEQPlayer_x                                      0x641720
#define EQPlayer__DoAttack_x                                       0x6560B0
#define EQPlayer__EQPlayer_x                                       0x641DD0
#define EQPlayer__SetNameSpriteState_x                             0x6460C0
#define EQPlayer__SetNameSpriteTint_x                              0x646F80
#define PlayerBase__HasProperty_j_x                                0x97E500
#define EQPlayer__IsTargetable_x                                   0x97E9A0
#define EQPlayer__CanSee_x                                         0x97E800
#define EQPlayer__CanSee1_x                                        0x97E8D0
#define PlayerBase__GetVisibilityLineSegment_x                     0x97E5C0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x658E90
#define PlayerZoneClient__GetLevel_x                               0x65B440
#define PlayerZoneClient__IsValidTeleport_x                        0x5C8010
#define PlayerZoneClient__LegalPlayerRace_x                        0x547510

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x651220
#define EQPlayerManager__GetSpawnByName_x                          0x651240
#define EQPlayerManager__GetPlayerFromPartialName_x                0x6512D0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x614F90
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x615010
#define KeypressHandler__AttachKeyToEqCommand_x                    0x615050
#define KeypressHandler__ClearCommandStateArray_x                  0x616460
#define KeypressHandler__HandleKeyDown_x                           0x616480
#define KeypressHandler__HandleKeyUp_x                             0x616520
#define KeypressHandler__SaveKeymapping_x                          0x616950

// MapViewMap 
#define MapViewMap__Clear_x                                        0x76D070
#define MapViewMap__SaveEx_x                                       0x770410
#define MapViewMap__SetZoom_x                                      0x774AE0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BB810

// StringTable 
#define StringTable__getString_x                                   0x8B6670

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x63BE00
#define PcZoneClient__RemovePetEffect_x                            0x63C430
#define PcZoneClient__HasAlternateAbility_x                        0x636160
#define PcZoneClient__GetCurrentMod_x                              0x4E2410
#define PcZoneClient__GetModCap_x                                  0x4E2310
#define PcZoneClient__CanEquipItem_x                               0x636810
#define PcZoneClient__GetItemByID_x                                0x6393E0
#define PcZoneClient__GetItemByItemClass_x                         0x639530
#define PcZoneClient__RemoveBuffEffect_x                           0x63C450
#define PcZoneClient__BandolierSwap_x                              0x637440
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x638F00

//Doors
#define EQSwitch__UseSwitch_x                                      0x5CCBA0

//IconCache
#define IconCache__GetIcon_x                                       0x70DDC0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x7058D0
#define CContainerMgr__CloseContainer_x                            0x705BA0
#define CContainerMgr__OpenExperimentContainer_x                   0x706620

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7C8420

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x609A40

//CLootWnd
#define CLootWnd__LootAll_x                                        0x763560
#define CLootWnd__RequestLootSlot_x                                0x762900

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x566780
#define EQ_Spell__SpellAffects_x                                   0x566BF0
#define EQ_Spell__SpellAffectBase_x                                0x5669B0
#define EQ_Spell__IsStackable_x                                    0x4C6DE0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C6C60
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B4040
#define EQ_Spell__IsSPAStacking_x                                  0x567A20
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x566F40
#define EQ_Spell__IsNoRemove_x                                     0x4C6DC0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x567A30
#define __IsResEffectSpell_x                                       0x4C61A0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AA820

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C5EB0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x80DE20
#define CTargetWnd__WndNotification_x                              0x80D6B0
#define CTargetWnd__RefreshTargetBuffs_x                           0x80D980
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x80C800

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x812500

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x52AC40
#define CTaskManager__HandleMessage_x                              0x5293A0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x561D30
#define EqSoundManager__PlayScriptMp3_x                            0x561E90
#define EqSoundManager__SoundAssistPlay_x                          0x673A80
#define EqSoundManager__WaveInstancePlay_x                         0x672FF0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x51EC10

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x93A5B0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x555B50
#define CAltAbilityData__GetMercMaxRank_x                          0x555AF0
#define CAltAbilityData__GetMaxRank_x                              0x54B290

//CTargetRing
#define CTargetRing__Cast_x                                        0x607B40

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C6C40
#define CharacterBase__CreateItemGlobalIndex_x                     0x504EC0
#define CharacterBase__CreateItemIndex_x                           0x60FB40
#define CharacterBase__GetItemPossession_x                         0x4F0DB0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CE4F0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CE550
#define CharacterBase__GetEffectId_x                               0x4C6BF0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6ECC70
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6ED4A0

//messages
#define msg_spell_worn_off_x                                       0x58C320
#define msg_new_text_x                                             0x581160
#define __msgTokenTextParam_x                                      0x58E850
#define msgTokenText_x                                             0x58EAA0

//SpellManager
#define SpellManager__vftable_x                                    0xAB9C70
#define SpellManager__SpellManager_x                               0x676DA0
#define Spellmanager__LoadTextSpells_x                             0x677670
#define SpellManager__GetSpellByGroupAndRank_x                     0x676F70

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9824E0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x5055A0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x592680
#define ItemGlobalIndex__IsEquippedLocation_x                      0x6285B0
#define ItemGlobalIndex__IsValidIndex_x                            0x505600

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C67F0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C6A70

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x75C0F0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x709FE0
#define CCursorAttachment__AttachToCursor1_x                       0x70A020
#define CCursorAttachment__Deactivate_x                            0x70B000

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x92D0F0
#define CSidlManagerBase__CreatePageWnd_x                          0x92C910
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x928B80
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x928B10

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x94A2A0
#define CEQSuiteTextureLoader__GetTexture_x                        0x949F60

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x502430
#define CFindItemWnd__WndNotification_x                            0x502F10
#define CFindItemWnd__Update_x                                     0x503A50
#define CFindItemWnd__PickupSelectedItem_x                         0x501C90

//IString
#define IString__Append_x                                          0x4F2350

//Camera
#define CDisplay__cameraType_x                                     0xDCD280
#define EverQuest__Cameras_x                                       0xE90660

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x50ACA0
#define LootFiltersManager__GetItemFilterData_x                    0x50A590
#define LootFiltersManager__RemoveItemLootFilter_x                 0x50A5C0
#define LootFiltersManager__SetItemLootFilter_x                    0x50A7E0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B6460

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x988170
#define CResolutionHandler__GetWindowedStyle_x                     0x66E690

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x702690

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D9010
#define CDistillerInfo__Instance_x                                 0x8D8FB0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x7226F0
#define CGroupWnd__UpdateDisplay_x                                 0x721A50

//ItemBase
#define ItemBase__IsLore_x                                         0x89C360
#define ItemBase__IsLoreEquipped_x                                 0x89C3D0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5C6E00
#define EQPlacedItemManager__GetItemByGuid_x                       0x5C6F40
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5C6FA0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x663EF0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x667910

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x4F8740

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4E77E0
#define FactionManagerClient__HandleFactionMessage_x               0x4E7E50
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4E8440
#define FactionManagerClient__GetMaxFaction_x                      0x4E8490
#define FactionManagerClient__GetMinFaction_x                      0x4E8410

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4F0D80

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x911860

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x497000

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4F0FA0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x555030

//CTargetManager
#define CTargetManager__Get_x                                      0x67A620

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x663EF0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A6550

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x59AA60

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF2DCF0

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
