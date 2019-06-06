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
#define __ExpectedVersionDate                                     "May 17 2019"
#define __ExpectedVersionTime                                     "10:25:48"
#define __ActualVersionDate_x                                      0xAD6494
#define __ActualVersionTime_x                                      0xAD6488
#define __ActualVersionBuild_x                                     0xAD6F2C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x61A6B0
#define __MemChecker1_x                                            0x8F0740
#define __MemChecker2_x                                            0x6A9CA0
#define __MemChecker3_x                                            0x6A9BF0
#define __MemChecker4_x                                            0x847570
#define __EncryptPad0_x                                            0xC0B9B0
#define __EncryptPad1_x                                            0xC69938
#define __EncryptPad2_x                                            0xC1C228
#define __EncryptPad3_x                                            0xC1BE28
#define __EncryptPad4_x                                            0xC5A1A0
#define __EncryptPad5_x                                            0xF34310
#define __AC1_x                                                    0x804276
#define __AC2_x                                                    0x5D435F
#define __AC3_x                                                    0x5DBA6F
#define __AC4_x                                                    0x5DF8F0
#define __AC5_x                                                    0x5E5B60
#define __AC6_x                                                    0x5EA1F6
#define __AC7_x                                                    0x5D3DD0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1F14CC

// Direct Input
#define DI8__Main_x                                                0xF34330
#define DI8__Keyboard_x                                            0xF34334
#define DI8__Mouse_x                                               0xF338F0
#define DI8__Mouse_Copy_x                                          0xE8EFCC
#define DI8__Mouse_Check_x                                         0xF34664
#define __AutoSkillArray_x                                         0xE8FEE4
#define __Attack_x                                                 0xF2DCFB
#define __Autofire_x                                               0xF2DCFC
#define __BindList_x                                               0xBFA3F0
#define g_eqCommandStates_x                                        0xBFB168
#define __Clicks_x                                                 0xE8F084
#define __CommandList_x                                            0xBFBD28
#define __CurrentMapLabel_x                                        0x104EDA4
#define __CurrentSocial_x                                          0xBE4730
#define __DoAbilityList_x                                          0xEC581C
#define __do_loot_x                                                0x5A0B40
#define __DrawHandler_x                                            0x16CB778
#define __GroupCount_x                                             0xE7F28A
#define __Guilds_x                                                 0xE857D8
#define __gWorld_x                                                 0xE815B8
#define __HWnd_x                                                   0xF338F4
#define __heqmain_x                                                0x103E94C
#define __InChatMode_x                                             0xE8EFB4
#define __LastTell_x                                               0xE90F18
#define __LMouseHeldTime_x                                         0xE8F0F0
#define __Mouse_x                                                  0xF3431C
#define __MouseLook_x                                              0xE8F04A
#define __MouseEventTime_x                                         0xF2E7DC
#define __gpbCommandEvent_x                                        0xE815B0
#define __NetStatusToggle_x                                        0xE8F04D
#define __PCNames_x                                                0xE904C8
#define __RangeAttackReady_x                                       0xE901C8
#define __RMouseHeldTime_x                                         0xE8F0EC
#define __RunWalkState_x                                           0xE8EFB8
#define __ScreenMode_x                                             0xDCD1D0
#define __ScreenX_x                                                0xE8EF6C
#define __ScreenY_x                                                0xE8EF68
#define __ScreenXMax_x                                             0xE8EF70
#define __ScreenYMax_x                                             0xE8EF74
#define __ServerHost_x                                             0xE817EB
#define __ServerName_x                                             0xEC57DC
#define __ShiftKeyDown_x                                           0xE8F644
#define __ShowNames_x                                              0xE90384
#define __Socials_x                                                0xEC58DC
#define __SubscriptionType_x                                       0x1090940
#define __TargetAggroHolder_x                                      0x1051760
#define __ZoneType_x                                               0xE8F448
#define __GroupAggro_x                                             0x10517A0
#define __LoginName_x                                              0xF33FB4
#define __Inviter_x                                                0xF2DC78
#define __AttackOnAssist_x                                         0xE90340
#define __UseTellWindows_x                                         0xE90664
#define __gfMaxZoomCameraDistance_x                                0xACB918
#define __gfMaxCameraDistance_x                                    0xAF8DD8
#define __pulAutoRun_x                                             0xE8F068
#define __pulForward_x                                             0xE9069C
#define __pulBackward_x                                            0xE906A0
#define __pulTurnRight_x                                           0xE906A4
#define __pulTurnLeft_x                                            0xE906A8
#define __pulStrafeLeft_x                                          0xE906AC
#define __pulStrafeRight_x                                         0xE906B0

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE81B70
#define instEQZoneInfo_x                                           0xE8F240
#define pinstActiveBanker_x                                        0xE8164C
#define pinstActiveCorpse_x                                        0xE81644
#define pinstActiveGMaster_x                                       0xE81648
#define pinstActiveMerchant_x                                      0xE81640
#define pinstAltAdvManager_x                                       0xDCDE40
#define pinstBandageTarget_x                                       0xE8165C
#define pinstCamActor_x                                            0xDCD1C0
#define pinstCDBStr_x                                              0xDCCB6C
#define pinstCDisplay_x                                            0xE816A0
#define pinstCEverQuest_x                                          0x103E948
#define pinstEverQuestInfo_x                                       0xE8EF60
#define pinstCharData_x                                            0xE7F264
#define pinstCharSpawn_x                                           0xE81694
#define pinstControlledMissile_x                                   0xE81B28
#define pinstControlledPlayer_x                                    0xE81694
#define pinstCResolutionHandler_x                                  0x16CB9A8
#define pinstCSidlManager_x                                        0x16CA944
#define pinstCXWndManager_x                                        0x16CA938
#define instDynamicZone_x                                          0xE856B0
#define pinstDZMember_x                                            0xE857C0
#define pinstDZTimerInfo_x                                         0xE857C4
#define pinstEqLogin_x                                             0xF33900
#define instEQMisc_x                                               0xDCCAB0
#define pinstEQSoundManager_x                                      0xDCED68
#define pinstEQSpellStrings_x                                      0xC8E2C0
#define instExpeditionLeader_x                                     0xE856FA
#define instExpeditionName_x                                       0xE8573A
#define pinstGroup_x                                               0xE7F286
#define pinstImeManager_x                                          0x16CA93C
#define pinstLocalPlayer_x                                         0xE815BC
#define pinstMercenaryData_x                                       0xF302CC
#define pinstMercenaryStats_x                                      0x10518AC
#define pinstModelPlayer_x                                         0xE81654
#define pinstPCData_x                                              0xE7F264
#define pinstSkillMgr_x                                            0xF32440
#define pinstSpawnManager_x                                        0xF30EE8
#define pinstSpellManager_x                                        0xF32660
#define pinstSpellSets_x                                           0xF26924
#define pinstStringTable_x                                         0xE81480
#define pinstSwitchManager_x                                       0xE7F110
#define pinstTarget_x                                              0xE81690
#define pinstTargetObject_x                                        0xE8169C
#define pinstTargetSwitch_x                                        0xE7F268
#define pinstTaskMember_x                                          0xDCC944
#define pinstTrackTarget_x                                         0xE81698
#define pinstTradeTarget_x                                         0xE81650
#define instTributeActive_x                                        0xDCCAD1
#define pinstViewActor_x                                           0xDCD1BC
#define pinstWorldData_x                                           0xE815A8
#define pinstZoneAddr_x                                            0xE8F4E0
#define pinstPlayerPath_x                                          0xF30F80
#define pinstTargetIndicator_x                                     0xF328C8
#define EQObject_Top_x                                             0xE815B4
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDCD288
#define pinstCAchievementsWnd_x                                    0xDCD278
#define pinstCActionsWnd_x                                         0xDCCC4C
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDCD0FC
#define pinstCAdvancedLootWnd_x                                    0xDCCC44
#define pinstCAdventureLeaderboardWnd_x                            0x1048578
#define pinstCAdventureRequestWnd_x                                0x1048628
#define pinstCAdventureStatsWnd_x                                  0x10486D8
#define pinstCAggroMeterWnd_x                                      0xDCD158
#define pinstCAlarmWnd_x                                           0xDCD1B8
#define pinstCAlertHistoryWnd_x                                    0xDCD224
#define pinstCAlertStackWnd_x                                      0xDCD170
#define pinstCAlertWnd_x                                           0xDCD180
#define pinstCAltStorageWnd_x                                      0x1048A38
#define pinstCAudioTriggersWindow_x                                0xC805F0
#define pinstCAuraWnd_x                                            0xDCD150
#define pinstCAvaZoneWnd_x                                         0xDCD228
#define pinstCBandolierWnd_x                                       0xDCD184
#define pinstCBankWnd_x                                            0xDCD214
#define pinstCBarterMerchantWnd_x                                  0x1049C78
#define pinstCBarterSearchWnd_x                                    0x1049D28
#define pinstCBarterWnd_x                                          0x1049DD8
#define pinstCBazaarConfirmationWnd_x                              0xDCD16C
#define pinstCBazaarSearchWnd_x                                    0xDCCC7C
#define pinstCBazaarWnd_x                                          0xDCD198
#define pinstCBlockedBuffWnd_x                                     0xDCD1FC
#define pinstCBlockedPetBuffWnd_x                                  0xDCD22C
#define pinstCBodyTintWnd_x                                        0xDCD140
#define pinstCBookWnd_x                                            0xDCD1A0
#define pinstCBreathWnd_x                                          0xDCD294
#define pinstCBuffWindowNORMAL_x                                   0xDCD1CC
#define pinstCBuffWindowSHORT_x                                    0xDCD1D4
#define pinstCBugReportWnd_x                                       0xDCD28C
#define pinstCButtonWnd_x                                          0x16CABA8
#define pinstCCastingWnd_x                                         0xDCD27C
#define pinstCCastSpellWnd_x                                       0xDCD0E8
//#define pinstCCharacterCreationWnd_x                               0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDCD29C
#define pinstCChatWindowManager_x                                  0x104A898
#define pinstCClaimWnd_x                                           0x104A9F0
#define pinstCColorPickerWnd_x                                     0xDCCC2C
#define pinstCCombatAbilityWnd_x                                   0xDCD15C
#define pinstCCombatSkillsSelectWnd_x                              0xDCCC50
#define pinstCCompassWnd_x                                         0xDCD12C
#define pinstCConfirmationDialog_x                                 0x104F8F0
#define pinstCContainerMgr_x                                       0xDCD284
#define pinstCContextMenuManager_x                                 0x16CA8F8
#define pinstCCursorAttachment_x                                   0xDCD26C
#define pinstCDynamicZoneWnd_x                                     0x104AFB8
#define pinstCEditLabelWnd_x                                       0xDCD1AC
#define pinstCEQMainWnd_x                                          0x104B200
#define pinstCEventCalendarWnd_x                                   0xDCCC1C
#define pinstCExtendedTargetWnd_x                                  0xDCD148
#define pinstCFacePick_x                                           0xDCCC24
#define pinstCFactionWnd_x                                         0xDCD274
#define pinstCFellowshipWnd_x                                      0x104B400
#define pinstCFileSelectionWnd_x                                   0xDCCC3C
#define pinstCFindItemWnd_x                                        0xDCD1B0
#define pinstCFindLocationWnd_x                                    0x104B558
#define pinstCFriendsWnd_x                                         0xDCCC60
#define pinstCGemsGameWnd_x                                        0xDCD194
#define pinstCGiveWnd_x                                            0xDCD1B4
#define pinstCGroupSearchFiltersWnd_x                              0xDCD168
#define pinstCGroupSearchWnd_x                                     0x104B950
#define pinstCGroupWnd_x                                           0x104BA00
#define pinstCGuildBankWnd_x                                       0xE90324
#define pinstCGuildCreationWnd_x                                   0x104BB60
#define pinstCGuildMgmtWnd_x                                       0x104BC10
#define pinstCharacterCreation_x                                   0xDCD160
#define pinstCHelpWnd_x                                            0xDCD104
#define pinstCHeritageSelectionWnd_x                               0xDCCC38
#define pinstCHotButtonWnd_x                                       0x104DD68
#define pinstCHotButtonWnd1_x                                      0x104DD68
#define pinstCHotButtonWnd2_x                                      0x104DD6C
#define pinstCHotButtonWnd3_x                                      0x104DD70
#define pinstCHotButtonWnd4_x                                      0x104DD74
#define pinstCIconSelectionWnd_x                                   0xDCD240
#define pinstCInspectWnd_x                                         0xDCD24C
#define pinstCInventoryWnd_x                                       0xDCD188
#define pinstCInvSlotMgr_x                                         0xDCD21C
#define pinstCItemDisplayManager_x                                 0x104E2F8
#define pinstCItemExpTransferWnd_x                                 0x104E42C
#define pinstCItemOverflowWnd_x                                    0xDCCCE4
#define pinstCJournalCatWnd_x                                      0xDCCC5C
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDCCC20
#define pinstCKeyRingWnd_x                                         0xDCD1EC
#define pinstCLargeDialogWnd_x                                     0x1050570
#define pinstCLayoutCopyWnd_x                                      0x104E778
#define pinstCLFGuildWnd_x                                         0x104E828
#define pinstCLoadskinWnd_x                                        0xDCD19C
#define pinstCLootFiltersCopyWnd_x                                 0xC9C8B8
#define pinstCLootFiltersWnd_x                                     0xDCD1A8
#define pinstCLootSettingsWnd_x                                    0xDCD1E8
#define pinstCLootWnd_x                                            0xDCCC14
#define pinstCMailAddressBookWnd_x                                 0xDCD234
#define pinstCMailCompositionWnd_x                                 0xDCD204
#define pinstCMailIgnoreListWnd_x                                  0xDCD238
#define pinstCMailWnd_x                                            0xDCD1E4
#define pinstCManageLootWnd_x                                      0xDCE2F0
#define pinstCMapToolbarWnd_x                                      0xDCD18C
#define pinstCMapViewWnd_x                                         0xDCD17C
#define pinstCMarketplaceWnd_x                                     0xDCCC28
#define pinstCMerchantWnd_x                                        0xDCCC54
#define pinstCMIZoneSelectWnd_x                                    0x104F060
#define pinstCMusicPlayerWnd_x                                     0xDCD1F0
#define pinstCNameChangeMercWnd_x                                  0xDCD134
#define pinstCNameChangePetWnd_x                                   0xDCD124
#define pinstCNameChangeWnd_x                                      0xDCCC0C
#define pinstCNoteWnd_x                                            0xDCD0F8
#define pinstCObjectPreviewWnd_x                                   0xDCCC48
#define pinstCOptionsWnd_x                                         0xDCD190
#define pinstCPetInfoWnd_x                                         0xDCD208
#define pinstCPetitionQWnd_x                                       0xDCCC68
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDCD13C
#define pinstCPlayerWnd_x                                          0xDCD1A4
#define pinstCPopupWndManager_x                                    0x104F8F0
#define pinstCProgressionSelectionWnd_x                            0x104F9A0
#define pinstCPurchaseGroupWnd_x                                   0xDCD0F0
#define pinstCPurchaseWnd_x                                        0xDCCC58
#define pinstCPvPLeaderboardWnd_x                                  0x104FA50
#define pinstCPvPStatsWnd_x                                        0x104FB00
#define pinstCQuantityWnd_x                                        0xDCD244
#define pinstCRaceChangeWnd_x                                      0xDCCC34
#define pinstCRaidOptionsWnd_x                                     0xDCD178
#define pinstCRaidWnd_x                                            0xDCD250
#define pinstCRealEstateItemsWnd_x                                 0xDCD290
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDCCC18
#define pinstCRealEstateManageWnd_x                                0xDCD1F4
#define pinstCRealEstateNeighborhoodWnd_x                          0xDCD20C
#define pinstCRealEstatePlotSearchWnd_x                            0xDCD230
#define pinstCRealEstatePurchaseWnd_x                              0xDCD264
#define pinstCRespawnWnd_x                                         0xDCD164
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDCD14C
#define pinstCSendMoneyWnd_x                                       0xDCD1E0
#define pinstCServerListWnd_x                                      0xDCD220
#define pinstCSkillsSelectWnd_x                                    0xDCCC30
#define pinstCSkillsWnd_x                                          0xDCCC10
#define pinstCSocialEditWnd_x                                      0xDCD270
#define pinstCSocialWnd_x                                          0xDCD154
#define pinstCSpellBookWnd_x                                       0xDCD144
#define pinstCStoryWnd_x                                           0xDCD10C
#define pinstCTargetOfTargetWnd_x                                  0x1051930
#define pinstCTargetWnd_x                                          0xDCD200
#define pinstCTaskOverlayWnd_x                                     0xDCD23C
#define pinstCTaskSelectWnd_x                                      0x1051A88
#define pinstCTaskManager_x                                        0xC9D208
#define pinstCTaskTemplateSelectWnd_x                              0x1051B38
#define pinstCTaskWnd_x                                            0x1051BE8
#define pinstCTextEntryWnd_x                                       0xDCD130
#define pinstCTimeLeftWnd_x                                        0xDCCC40
#define pinstCTipWndCONTEXT_x                                      0x1051DEC
#define pinstCTipWndOFDAY_x                                        0x1051DE8
#define pinstCTitleWnd_x                                           0x1051E98
#define pinstCTrackingWnd_x                                        0xDCD218
#define pinstCTradeskillWnd_x                                      0x1052000
#define pinstCTradeWnd_x                                           0xDCD138
#define pinstCTrainWnd_x                                           0xDCD248
#define pinstCTributeBenefitWnd_x                                  0x1052200
#define pinstCTributeMasterWnd_x                                   0x10522B0
#define pinstCTributeTrophyWnd_x                                   0x1052360
#define pinstCVideoModesWnd_x                                      0xDCD254
#define pinstCVoiceMacroWnd_x                                      0xF33030
#define pinstCVoteResultsWnd_x                                     0xDCD0F4
#define pinstCVoteWnd_x                                            0xDCCC64
#define pinstCWebManager_x                                         0xF336AC
#define pinstCZoneGuideWnd_x                                       0xDCD1F8
#define pinstCZonePathWnd_x                                        0xDCD210

#define pinstEQSuiteTextureLoader_x                                0xC6B420
#define pinstItemIconCache_x                                       0x104B1B8
#define pinstLootFiltersManager_x                                  0xC9C968
#define pinstRewardSelectionWnd_x                                  0x1050248

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC1BE18
#define __CastRay_x                                                0x59BFA0
#define __CastRay2_x                                               0x59BFF0
#define __ConvertItemTags_x                                        0x5B7800
#define __CrashHandler_x                                           0x850F30
#define __CleanItemTags_x                                          0x4779F0
#define __DoesFileExist_x                                          0x8F37C0
#define __EQGetTime_x                                              0x8F0220
#define __ExecuteCmd_x                                             0x5948A0
#define __FixHeading_x                                             0x9800B0
#define __GameLoop_x                                               0x6A9160
#define __get_bearing_x                                            0x59BAF0
#define __get_melee_range_x                                        0x59C1E0
#define __GetAnimationCache_x                                      0x70E160
#define __GetGaugeValueFromEQ_x                                    0x802A80
#define __GetLabelFromEQ_x                                         0x804200
#define __GetXTargetType_x                                         0x981B80
#define __HandleMouseWheel_x                                       0x6A9D50
#define __HeadingDiff_x                                            0x980120
#define __HelpPath_x                                               0xF2E3CC
#define __LoadFrontEnd_x                                           0x6A5C30
#define __NewUIINI_x                                               0x802750
#define __pCrashHandler_x                                          0x106F768
#define __ProcessGameEvents_x                                      0x5FB8B0
#define __ProcessMouseEvent_x                                      0x5FB070
#define __SaveColors_x                                             0x545450
#define __STMLToText_x                                             0x923560
#define __ToggleKeyRingItem_x                                      0x5085E0
#define CMemoryMappedFile__SetFile_x                               0xA5A270
#define CrashDetected_x                                            0x6A7690
#define DrawNetStatus_x                                            0x627BA0
#define Expansion_HoT_x                                            0xE9032C
#define Teleport_Table_Size_x                                      0xE816A8
#define Teleport_Table_x                                           0xE7F478
#define Util__FastTime_x                                           0x8EFDE0
#define wwsCrashReportCheckForUploader_x                           0x851E80
#define wwsCrashReportPlatformLaunchUploader_x                     0x854560

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48B620
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4944C0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x494280
#define CAdvancedLootWnd__AddPlayerToList_x                        0x48EB70
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x48DFD0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x54D050
#define AltAdvManager__IsAbilityReady_x                            0x54BFA0
#define AltAdvManager__GetAAById_x                                 0x54C1A0
#define AltAdvManager__CanTrainAbility_x                           0x54C210
#define AltAdvManager__CanSeeAbility_x                             0x54C570

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C71A0
#define CharacterZoneClient__HasSkill_x                            0x4D2070
#define CharacterZoneClient__MakeMeVisible_x                       0x4D3790
#define CharacterZoneClient__IsStackBlocked_x                      0x4BB5A0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B7CF0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D6140
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D6220
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D6300
#define CharacterZoneClient__FindAffectSlot_x                      0x4C0090
#define CharacterZoneClient__BardCastBard_x                        0x4C2CF0
#define CharacterZoneClient__GetMaxEffects_x                       0x4B7DC0
#define CharacterZoneClient__GetEffect_x                           0x4B7C30
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C1090
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C1160
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C11B0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C1300
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C14D0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4AFAE0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D4700
#define CharacterZoneClient__FindItemByRecord_x                    0x4D4170

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6CF980
#define CBankWnd__WndNotification_x                                0x6CF760

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6DD170

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x60A460
#define CButtonWnd__CButtonWnd_x                                   0x91F900

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6FD210
#define CChatManager__InitContextMenu_x                            0x6F6590
#define CChatManager__FreeChatWindow_x                             0x6FBDD0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E5840
#define CChatManager__SetLockedActiveChatWindow_x                  0x6FCE90
#define CChatManager__CreateChatWindow_x                           0x6FC400

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E5910

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x9340E0
#define CContextMenu__dCContextMenu_x                              0x934310
#define CContextMenu__AddMenuItem_x                                0x934320
#define CContextMenu__RemoveMenuItem_x                             0x934630
#define CContextMenu__RemoveAllMenuItems_x                         0x934650
#define CContextMenu__CheckMenuItem_x                              0x9346D0
#define CContextMenu__SetMenuItem_x                                0x934550
#define CContextMenu__AddSeparator_x                               0x9344B0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x934C70
#define CContextMenuManager__RemoveMenu_x                          0x934CE0
#define CContextMenuManager__PopupMenu_x                           0x934DA0
#define CContextMenuManager__Flush_x                               0x934C10
#define CContextMenuManager__GetMenu_x                             0x4965E0
#define CContextMenuManager__CreateDefaultMenu_x                   0x708950

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D0B70
#define CChatService__GetFriendName_x                              0x8D0B80

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6FDA70
#define CChatWindow__Clear_x                                       0x6FED20
#define CChatWindow__WndNotification_x                             0x6FF4B0
#define CChatWindow__AddHistory_x                                  0x6FE5F0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x931570
#define CComboWnd__Draw_x                                          0x930A50
#define CComboWnd__GetCurChoice_x                                  0x9313B0
#define CComboWnd__GetListRect_x                                   0x930F10
#define CComboWnd__GetTextRect_x                                   0x9315E0
#define CComboWnd__InsertChoice_x                                  0x9310A0
#define CComboWnd__SetColors_x                                     0x931070
#define CComboWnd__SetChoice_x                                     0x931380
#define CComboWnd__GetItemCount_x                                  0x9313C0
#define CComboWnd__GetCurChoiceText_x                              0x931400
#define CComboWnd__GetChoiceText_x                                 0x9313D0
#define CComboWnd__InsertChoiceAtIndex_x                           0x931140

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x706340
#define CContainerWnd__vftable_x                                   0xADF6F0
#define CContainerWnd__SetContainer_x                              0x7078B0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x545210
#define CDisplay__GetClickedActor_x                                0x5381C0
#define CDisplay__GetUserDefinedColor_x                            0x5308A0
#define CDisplay__GetWorldFilePath_x                               0x539C10
#define CDisplay__is3dON_x                                         0x534E90
#define CDisplay__ReloadUI_x                                       0x53F330
#define CDisplay__WriteTextHD2_x                                   0x534C70
#define CDisplay__TrueDistance_x                                   0x53B870
#define CDisplay__SetViewActor_x                                   0x537B10
#define CDisplay__GetFloorHeight_x                                 0x534F50
#define CDisplay__SetRenderWindow_x                                0x533880
#define CDisplay__ToggleScreenshotMode_x                           0x5375E0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x953C10

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x937670
#define CEditWnd__GetCharIndexPt_x                                 0x938570
#define CEditWnd__GetDisplayString_x                               0x938410
#define CEditWnd__GetHorzOffset_x                                  0x936CA0
#define CEditWnd__GetLineForPrintableChar_x                        0x939770
#define CEditWnd__GetSelStartPt_x                                  0x938820
#define CEditWnd__GetSTMLSafeText_x                                0x938230
#define CEditWnd__PointFromPrintableChar_x                         0x9393A0
#define CEditWnd__SelectableCharFromPoint_x                        0x939510
#define CEditWnd__SetEditable_x                                    0x9388F0
#define CEditWnd__SetWindowTextA_x                                 0x937FB0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5E9720
#define CEverQuest__ClickedPlayer_x                                0x5DB850
#define CEverQuest__CreateTargetIndicator_x                        0x5F8B60
#define CEverQuest__DeleteTargetIndicator_x                        0x5F8BF0
#define CEverQuest__DoTellWindow_x                                 0x4E59F0
#define CEverQuest__OutputTextToLog_x                              0x4E5C20
#define CEverQuest__DropHeldItemOnGround_x                         0x5D0890
#define CEverQuest__dsp_chat_x                                     0x4E5FB0
#define CEverQuest__trimName_x                                     0x5F4E40
#define CEverQuest__Emote_x                                        0x5E9F30
#define CEverQuest__EnterZone_x                                    0x5E3F10
#define CEverQuest__GetBodyTypeDesc_x                              0x5EE6E0
#define CEverQuest__GetClassDesc_x                                 0x5EED20
#define CEverQuest__GetClassThreeLetterCode_x                      0x5EF320
#define CEverQuest__GetDeityDesc_x                                 0x5F74B0
#define CEverQuest__GetLangDesc_x                                  0x5EF4E0
#define CEverQuest__GetRaceDesc_x                                  0x5EED00
#define CEverQuest__InterpretCmd_x                                 0x5F7A80
#define CEverQuest__LeftClickedOnPlayer_x                          0x5D4A80
#define CEverQuest__LMouseUp_x                                     0x5D2E00
#define CEverQuest__RightClickedOnPlayer_x                         0x5D5360
#define CEverQuest__RMouseUp_x                                     0x5D3D90
#define CEverQuest__SetGameState_x                                 0x5D0620
#define CEverQuest__UPCNotificationFlush_x                         0x5F4D40
#define CEverQuest__IssuePetCommand_x                              0x5F08E0
#define CEverQuest__ReportSuccessfulHit_x                          0x5EB330

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7182D0
#define CGaugeWnd__CalcLinesFillRect_x                             0x718330
#define CGaugeWnd__Draw_x                                          0x7179C0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AC7E0
#define CGuild__GetGuildName_x                                     0x4AB8C0
#define CGuild__GetGuildIndex_x                                    0x4ABC50

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x733690

//CHotButton
#define CHotButton__SetButtonSize_x                                0x60A820

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x740540
#define CInvSlotMgr__MoveItem_x                                    0x73F2A0
#define CInvSlotMgr__SelectSlot_x                                  0x740610

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x73DB50
#define CInvSlot__SliderComplete_x                                 0x73B8B0
#define CInvSlot__GetItemBase_x                                    0x73B240
#define CInvSlot__UpdateItem_x                                     0x73B3B0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x742070
#define CInvSlotWnd__CInvSlotWnd_x                                 0x741220
#define CInvSlotWnd__HandleLButtonUp_x                             0x741BF0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7FECD0
#define CItemDisplayWnd__UpdateStrings_x                           0x750600
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x74A3D0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x74A8F0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x750C10
#define CItemDisplayWnd__AboutToShow_x                             0x750250
#define CItemDisplayWnd__WndNotification_x                         0x752100
#define CItemDisplayWnd__RequestConvertItem_x                      0x751BD0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x74F2B0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x750070

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8366E0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x7561F0

// CLabel 
#define CLabel__Draw_x                                             0x75BCD0

// CListWnd
#define CListWnd__CListWnd_x                                       0x909DC0
#define CListWnd__dCListWnd_x                                      0x90A0E0
#define CListWnd__AddColumn_x                                      0x90E400
#define CListWnd__AddColumn1_x                                     0x90E450
#define CListWnd__AddLine_x                                        0x90E7E0
#define CListWnd__AddString_x                                      0x90E5E0
#define CListWnd__CalculateFirstVisibleLine_x                      0x90E1C0
#define CListWnd__CalculateVSBRange_x                              0x90DFB0
#define CListWnd__ClearSel_x                                       0x90EFC0
#define CListWnd__ClearAllSel_x                                    0x90F020
#define CListWnd__CloseAndUpdateEditWindow_x                       0x90FA40
#define CListWnd__Compare_x                                        0x90D8F0
#define CListWnd__Draw_x                                           0x90A1E0
#define CListWnd__DrawColumnSeparators_x                           0x90C9C0
#define CListWnd__DrawHeader_x                                     0x90CE30
#define CListWnd__DrawItem_x                                       0x90D230
#define CListWnd__DrawLine_x                                       0x90CB30
#define CListWnd__DrawSeparator_x                                  0x90CA60
#define CListWnd__EnableLine_x                                     0x90C2A0
#define CListWnd__EnsureVisible_x                                  0x90F960
#define CListWnd__ExtendSel_x                                      0x90EEF0
#define CListWnd__GetColumnTooltip_x                               0x90BDE0
#define CListWnd__GetColumnMinWidth_x                              0x90BE50
#define CListWnd__GetColumnWidth_x                                 0x90BD50
#define CListWnd__GetCurSel_x                                      0x90B6E0
#define CListWnd__GetItemAtPoint_x                                 0x90C520
#define CListWnd__GetItemAtPoint1_x                                0x90C590
#define CListWnd__GetItemData_x                                    0x90B760
#define CListWnd__GetItemHeight_x                                  0x90BB20
#define CListWnd__GetItemIcon_x                                    0x90B8F0
#define CListWnd__GetItemRect_x                                    0x90C390
#define CListWnd__GetItemText_x                                    0x90B7A0
#define CListWnd__GetSelList_x                                     0x90F070
#define CListWnd__GetSeparatorRect_x                               0x90C7D0
#define CListWnd__InsertLine_x                                     0x90EBD0
#define CListWnd__RemoveLine_x                                     0x90ED20
#define CListWnd__SetColors_x                                      0x90DF80
#define CListWnd__SetColumnJustification_x                         0x90DCB0
#define CListWnd__SetColumnWidth_x                                 0x90DBD0
#define CListWnd__SetCurSel_x                                      0x90EE30
#define CListWnd__SetItemColor_x                                   0x90F610
#define CListWnd__SetItemData_x                                    0x90F5D0
#define CListWnd__SetItemText_x                                    0x90F1E0
#define CListWnd__ShiftColumnSeparator_x                           0x90DD70
#define CListWnd__Sort_x                                           0x90DA70
#define CListWnd__ToggleSel_x                                      0x90EE60
#define CListWnd__SetColumnsSizable_x                              0x90DE10
#define CListWnd__SetItemWnd_x                                     0x90F490
#define CListWnd__GetItemWnd_x                                     0x90B940
#define CListWnd__SetItemIcon_x                                    0x90F260
#define CListWnd__CalculateCustomWindowPositions_x                 0x90E2C0
#define CListWnd__SetVScrollPos_x                                  0x90DBB0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x771250
#define CMapViewWnd__GetWorldCoordinates_x                         0x76F960
#define CMapViewWnd__HandleLButtonDown_x                           0x76C9C0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x794560
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x794E40
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x795370
#define CMerchantWnd__SelectRecoverySlot_x                         0x7982F0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7930A0
#define CMerchantWnd__SelectBuySellSlot_x                          0x79DED0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x794170

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89E6B0
#define CPacketScrambler__hton_x                                   0x89E6A0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x928B40
#define CSidlManager__FindScreenPieceTemplate_x                    0x928F50
#define CSidlManager__FindScreenPieceTemplate1_x                   0x928D40
#define CSidlManager__CreateLabel_x                                0x7F6120
#define CSidlManager__CreateXWndFromTemplate_x                     0x92BEF0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x92C0D0
#define CSidlManager__CreateXWnd_x                                 0x7F6050
#define CSidlManager__CreateHotButtonWnd_x                         0x7F6620

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9256B0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9255B0
#define CSidlScreenWnd__ConvertToRes_x                             0x94ABC0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x925040
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x924D30
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x924E00
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x924ED0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x925B50
#define CSidlScreenWnd__EnableIniStorage_x                         0x926020
#define CSidlScreenWnd__GetSidlPiece_x                             0x925D40
#define CSidlScreenWnd__Init1_x                                    0x924930
#define CSidlScreenWnd__LoadIniInfo_x                              0x926070
#define CSidlScreenWnd__LoadIniListWnd_x                           0x926BB0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x923D50
#define CSidlScreenWnd__StoreIniInfo_x                             0x926730
#define CSidlScreenWnd__StoreIniVis_x                              0x926A90
#define CSidlScreenWnd__WndNotification_x                          0x925A60
#define CSidlScreenWnd__GetChildItem_x                             0x925FA0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x915820
#define CSidlScreenWnd__m_layoutCopy_x                             0x16CA7C8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x66EDC0
#define CSkillMgr__GetSkillCap_x                                   0x66EFA0
#define CSkillMgr__GetNameToken_x                                  0x66E550
#define CSkillMgr__IsActivatedSkill_x                              0x66E690
#define CSkillMgr__IsCombatSkill_x                                 0x66E5D0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x935A70
#define CSliderWnd__SetValue_x                                     0x9358E0
#define CSliderWnd__SetNumTicks_x                                  0x935940

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7FC220

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x93E220
#define CStmlWnd__CalculateHSBRange_x                              0x93F310
#define CStmlWnd__CalculateVSBRange_x                              0x93F280
#define CStmlWnd__CanBreakAtCharacter_x                            0x943650
#define CStmlWnd__FastForwardToEndOfTag_x                          0x9442E0
#define CStmlWnd__ForceParseNow_x                                  0x93E7C0
#define CStmlWnd__GetNextTagPiece_x                                0x9435B0
#define CStmlWnd__GetSTMLText_x                                    0x4F7C60
#define CStmlWnd__GetVisibleText_x                                 0x93E7E0
#define CStmlWnd__InitializeWindowVariables_x                      0x944130
#define CStmlWnd__MakeStmlColorTag_x                               0x93D900
#define CStmlWnd__MakeWndNotificationTag_x                         0x93D970
#define CStmlWnd__SetSTMLText_x                                    0x93C9B0
#define CStmlWnd__StripFirstSTMLLines_x                            0x9453E0
#define CStmlWnd__UpdateHistoryString_x                            0x9444F0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x93BB50
#define CTabWnd__DrawCurrentPage_x                                 0x93C230
#define CTabWnd__DrawTab_x                                         0x93BF50
#define CTabWnd__GetCurrentPage_x                                  0x93B350
#define CTabWnd__GetPageInnerRect_x                                0x93B590
#define CTabWnd__GetTabInnerRect_x                                 0x93B4D0
#define CTabWnd__GetTabRect_x                                      0x93B380
#define CTabWnd__InsertPage_x                                      0x93B7A0
#define CTabWnd__SetPage_x                                         0x93B610
#define CTabWnd__SetPageRect_x                                     0x93BA90
#define CTabWnd__UpdatePage_x                                      0x93BE10
#define CTabWnd__GetPageFromTabIndex_x                             0x93BE90
#define CTabWnd__GetCurrentTabIndex_x                              0x93B340

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x756650
#define CPageWnd__SetTabText_x                                     0x93AE90

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A63E0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x912690
#define CTextureFont__GetTextExtent_x                              0x912850

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6A2C80
#define CHtmlComponentWnd__ValidateUri_x                           0x735080
#define CHtmlWnd__SetClientCallbacks_x                             0x60F8B0
#define CHtmlWnd__AddObserver_x                                    0x60F8D0
#define CHtmlWnd__RemoveObserver_x                                 0x60F930
#define Window__getProgress_x                                      0x84EBA0
#define Window__getStatus_x                                        0x84EBC0
#define Window__getURI_x                                           0x84EBD0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x950630

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8FFB10

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4ADB40
#define CXStr__CXStr1_x                                            0x908540
#define CXStr__CXStr3_x                                            0x8EC310
#define CXStr__dCXStr_x                                            0x473150
#define CXStr__operator_equal_x                                    0x8EC540
#define CXStr__operator_equal1_x                                   0x8EC580
#define CXStr__operator_plus_equal1_x                              0x8ED010
#define CXStr__SetString_x                                         0x8EEF00
#define CXStr__operator_char_p_x                                   0x8ECA50
#define CXStr__GetChar_x                                           0x8EE850
#define CXStr__Delete_x                                            0x8EE100
#define CXStr__GetUnicode_x                                        0x8EE8C0
#define CXStr__GetLength_x                                         0x4A6190
#define CXStr__Mid_x                                               0x477D10
#define CXStr__Insert_x                                            0x8EE920
#define CXStr__FindNext_x                                          0x8EE570

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x933D00
#define CXWnd__BringToTop_x                                        0x918F50
#define CXWnd__Center_x                                            0x918AD0
#define CXWnd__ClrFocus_x                                          0x918910
#define CXWnd__Destroy_x                                           0x9189B0
#define CXWnd__DoAllDrawing_x                                      0x914FC0
#define CXWnd__DrawChildren_x                                      0x914F90
#define CXWnd__DrawColoredRect_x                                   0x915430
#define CXWnd__DrawTooltip_x                                       0x913AD0
#define CXWnd__DrawTooltipAtPoint_x                                0x913B90
#define CXWnd__GetBorderFrame_x                                    0x915290
#define CXWnd__GetChildWndAt_x                                     0x918FF0
#define CXWnd__GetClientClipRect_x                                 0x917240
#define CXWnd__GetScreenClipRect_x                                 0x917310
#define CXWnd__GetScreenRect_x                                     0x9174A0
#define CXWnd__GetTooltipRect_x                                    0x915480
#define CXWnd__GetWindowTextA_x                                    0x497CA0
#define CXWnd__IsActive_x                                          0x915B90
#define CXWnd__IsDescendantOf_x                                    0x917EC0
#define CXWnd__IsReallyVisible_x                                   0x917EF0
#define CXWnd__IsType_x                                            0x919660
#define CXWnd__Move_x                                              0x917F50
#define CXWnd__Move1_x                                             0x918010
#define CXWnd__ProcessTransition_x                                 0x918A80
#define CXWnd__Refade_x                                            0x9182E0
#define CXWnd__Resize_x                                            0x918570
#define CXWnd__Right_x                                             0x918D10
#define CXWnd__SetFocus_x                                          0x9188D0
#define CXWnd__SetFont_x                                           0x918940
#define CXWnd__SetKeyTooltip_x                                     0x919480
#define CXWnd__SetMouseOver_x                                      0x9163E0
#define CXWnd__StartFade_x                                         0x917D90
#define CXWnd__GetChildItem_x                                      0x919160
#define CXWnd__SetParent_x                                         0x917C50
#define CXWnd__Minimize_x                                          0x9185D0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x94BC50

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x91BEC0
#define CXWndManager__DrawWindows_x                                0x91BEE0
#define CXWndManager__GetKeyboardFlags_x                           0x91E5B0
#define CXWndManager__HandleKeyboardMsg_x                          0x91E1B0
#define CXWndManager__RemoveWnd_x                                  0x91E7F0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x91ED40

// CDBStr
#define CDBStr__GetString_x                                        0x52F860

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B8CD0
#define EQ_Character__Cur_HP_x                                     0x4CF050
#define EQ_Character__Cur_Mana_x                                   0x4D6800
#define EQ_Character__GetCastingTimeModifier_x                     0x4BBBF0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AF720
#define EQ_Character__GetFocusRangeModifier_x                      0x4AF870
#define EQ_Character__GetHPRegen_x                                 0x4DC6F0
#define EQ_Character__GetEnduranceRegen_x                          0x4DCD00
#define EQ_Character__GetManaRegen_x                               0x4DD140
#define EQ_Character__Max_Endurance_x                              0x635710
#define EQ_Character__Max_HP_x                                     0x4CEE80
#define EQ_Character__Max_Mana_x                                   0x635510
#define EQ_Character__doCombatAbility_x                            0x637BD0
#define EQ_Character__UseSkill_x                                   0x4DEF50
#define EQ_Character__GetConLevel_x                                0x62EAE0
#define EQ_Character__IsExpansionFlag_x                            0x593080
#define EQ_Character__TotalEffect_x                                0x4C2250
#define EQ_Character__GetPCSpellAffect_x                           0x4BC7E0
#define EQ_Character__SpellDuration_x                              0x4BC310
#define EQ_Character__GetAdjustedSkill_x                           0x4D1E30
#define EQ_Character__GetBaseSkill_x                               0x4D2DD0
#define EQ_Character__CanUseItem_x                                 0x4D6B10

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BD9E0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x64BD50

//PcClient
#define PcClient__PcClient_x                                       0x62C220

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6940
#define CCharacterListWnd__EnterWorld_x                            0x4B6380
#define CCharacterListWnd__Quit_x                                  0x4B6090
#define CCharacterListWnd__UpdateList_x                            0x4B6510

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x610AB0
#define EQ_Item__CreateItemTagString_x                             0x897FE0
#define EQ_Item__IsStackable_x                                     0x89CA30
#define EQ_Item__GetImageNum_x                                     0x899A50
#define EQ_Item__CreateItemClient_x                                0x60FC90
#define EQ_Item__GetItemValue_x                                    0x89ACB0
#define EQ_Item__ValueSellMerchant_x                               0x89E250
#define EQ_Item__IsKeyRingItem_x                                   0x89C380
#define EQ_Item__CanGoInBag_x                                      0x610BD0
#define EQ_Item__IsEmpty_x                                         0x89BEC0
#define EQ_Item__GetMaxItemCount_x                                 0x89B080
#define EQ_Item__GetHeldItem_x                                     0x899920
#define EQ_Item__GetAugmentFitBySlot_x                             0x897920

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x54DD50
#define EQ_LoadingS__Array_x                                       0xBF3600

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x636070
#define EQ_PC__GetAlternateAbilityId_x                             0x8A7320
#define EQ_PC__GetCombatAbility_x                                  0x8A7990
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A7A00
#define EQ_PC__GetItemRecastTimer_x                                0x638150
#define EQ_PC__HasLoreItem_x                                       0x62F2A0
#define EQ_PC__AlertInventoryChanged_x                             0x62E420
#define EQ_PC__GetPcZoneClient_x                                   0x65A4C0
#define EQ_PC__RemoveMyAffect_x                                    0x63B370
#define EQ_PC__GetKeyRingItems_x                                   0x8A82A0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A8020
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A8590

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5995C0
#define EQItemList__add_object_x                                   0x5C5FF0
#define EQItemList__add_item_x                                     0x599B10
#define EQItemList__delete_item_x                                  0x599B60
#define EQItemList__FreeItemList_x                                 0x599A60

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x52CDA0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x64D5D0
#define EQPlayer__dEQPlayer_x                                      0x6408F0
#define EQPlayer__DoAttack_x                                       0x655180
#define EQPlayer__EQPlayer_x                                       0x640FA0
#define EQPlayer__SetNameSpriteState_x                             0x645250
#define EQPlayer__SetNameSpriteTint_x                              0x646120
#define PlayerBase__HasProperty_j_x                                0x97E440
#define EQPlayer__IsTargetable_x                                   0x97E8E0
#define EQPlayer__CanSee_x                                         0x97E740
#define EQPlayer__CanSee1_x                                        0x97E810
#define PlayerBase__GetVisibilityLineSegment_x                     0x97E500

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x657F50
#define PlayerZoneClient__GetLevel_x                               0x65A500
#define PlayerZoneClient__IsValidTeleport_x                        0x5C7160
#define PlayerZoneClient__LegalPlayerRace_x                        0x5470C0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x650350
#define EQPlayerManager__GetSpawnByName_x                          0x650370
#define EQPlayerManager__GetPlayerFromPartialName_x                0x650400

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x6141C0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x614240
#define KeypressHandler__AttachKeyToEqCommand_x                    0x614280
#define KeypressHandler__ClearCommandStateArray_x                  0x615690
#define KeypressHandler__HandleKeyDown_x                           0x6156B0
#define KeypressHandler__HandleKeyUp_x                             0x615750
#define KeypressHandler__SaveKeymapping_x                          0x615B80

// MapViewMap 
#define MapViewMap__Clear_x                                        0x76D0E0
#define MapViewMap__SaveEx_x                                       0x770480
#define MapViewMap__SetZoom_x                                      0x774B50

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BB820

// StringTable 
#define StringTable__getString_x                                   0x8B6670

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x63AFE0
#define PcZoneClient__RemovePetEffect_x                            0x63B610
#define PcZoneClient__HasAlternateAbility_x                        0x635350
#define PcZoneClient__GetCurrentMod_x                              0x4E2040
#define PcZoneClient__GetModCap_x                                  0x4E1F40
#define PcZoneClient__CanEquipItem_x                               0x635A00
#define PcZoneClient__GetItemByID_x                                0x6385C0
#define PcZoneClient__GetItemByItemClass_x                         0x638710
#define PcZoneClient__RemoveBuffEffect_x                           0x63B630
#define PcZoneClient__BandolierSwap_x                              0x636630
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x6380F0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5CBD70

//IconCache
#define IconCache__GetIcon_x                                       0x70D9F0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x7054E0
#define CContainerMgr__CloseContainer_x                            0x7057B0
#define CContainerMgr__OpenExperimentContainer_x                   0x706230

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7C8620

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x608C40

//CLootWnd
#define CLootWnd__LootAll_x                                        0x763480
#define CLootWnd__RequestLootSlot_x                                0x762820

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x5660A0
#define EQ_Spell__SpellAffects_x                                   0x566510
#define EQ_Spell__SpellAffectBase_x                                0x5662D0
#define EQ_Spell__IsStackable_x                                    0x4C6AD0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C6920
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B3CB0
#define EQ_Spell__IsSPAStacking_x                                  0x567340
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x566860
#define EQ_Spell__IsNoRemove_x                                     0x4C6AB0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x567350
#define __IsResEffectSpell_x                                       0x4C5DC0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AA4E0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C5FB0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x80E010
#define CTargetWnd__WndNotification_x                              0x80D8A0
#define CTargetWnd__RefreshTargetBuffs_x                           0x80DB70
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x80C9F0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x8126E0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x52A700
#define CTaskManager__HandleMessage_x                              0x528E70

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x561650
#define EqSoundManager__PlayScriptMp3_x                            0x5617B0
#define EqSoundManager__SoundAssistPlay_x                          0x672D00
#define EqSoundManager__WaveInstancePlay_x                         0x672270

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x51E6F0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x93A390

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x5556E0
#define CAltAbilityData__GetMercMaxRank_x                          0x555680
#define CAltAbilityData__GetMaxRank_x                              0x54AE50

//CTargetRing
#define CTargetRing__Cast_x                                        0x606D40

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C6900
#define CharacterBase__CreateItemGlobalIndex_x                     0x5049A0
#define CharacterBase__CreateItemIndex_x                           0x60EE70
#define CharacterBase__GetItemPossession_x                         0x4F08A0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CE630
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CE690
#define CharacterBase__GetEffectId_x                               0x4C68B0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6EC900
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6ED130
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6ED1E0 

//messages
#define msg_spell_worn_off_x                                       0x58B120
#define msg_new_text_x                                             0x57FF70
#define __msgTokenTextParam_x                                      0x58D650
#define msgTokenText_x                                             0x58D8A0

//SpellManager
#define SpellManager__vftable_x                                    0xAB9C58
#define SpellManager__SpellManager_x                               0x676020
#define Spellmanager__LoadTextSpells_x                             0x6768F0
#define SpellManager__GetSpellByGroupAndRank_x                     0x6761F0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x982470

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x505060
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x591450
#define ItemGlobalIndex__IsEquippedLocation_x                      0x627A00
#define ItemGlobalIndex__IsValidIndex_x                            0x5050C0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C68F0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C6B70

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x75C020

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x709C00
#define CCursorAttachment__AttachToCursor1_x                       0x709C40
#define CCursorAttachment__Deactivate_x                            0x70AC20

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x92CF20
#define CSidlManagerBase__CreatePageWnd_x                          0x92C720
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x928960
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x9288F0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x94A050
#define CEQSuiteTextureLoader__GetTexture_x                        0x949D10

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x501F40
#define CFindItemWnd__WndNotification_x                            0x502A20
#define CFindItemWnd__Update_x                                     0x503590
#define CFindItemWnd__PickupSelectedItem_x                         0x5017A0

//IString
#define IString__Append_x                                          0x4F1EF0

//Camera
#define CDisplay__cameraType_x                                     0xDCD298
#define EverQuest__Cameras_x                                       0xE90670

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x50A8C0
#define LootFiltersManager__GetItemFilterData_x                    0x50A1C0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x50A1F0
#define LootFiltersManager__SetItemLootFilter_x                    0x50A410

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B6620

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x988070
#define CResolutionHandler__GetWindowedStyle_x                     0x66D930

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x7021E0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D9190
#define CDistillerInfo__Instance_x                                 0x8D9130

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x722440
#define CGroupWnd__UpdateDisplay_x                                 0x7217A0

//ItemBase
#define ItemBase__IsLore_x                                         0x89C3E0
#define ItemBase__IsLoreEquipped_x                                 0x89C450

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5C5F50
#define EQPlacedItemManager__GetItemByGuid_x                       0x5C6090
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5C60F0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x663010
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x6669D0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x4F8260

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4E7350
#define FactionManagerClient__HandleFactionMessage_x               0x4E79C0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4E7FF0
#define FactionManagerClient__GetMaxFaction_x                      0x4E8040
#define FactionManagerClient__GetMinFaction_x                      0x4E7FC0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4F0870

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x9116C0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x496F90

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4F0B40

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x554BC0

//CTargetManager
#define CTargetManager__Get_x                                      0x679880

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x663010

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A61A0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x599A00

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF2DD00

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
