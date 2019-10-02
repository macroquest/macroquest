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
#define __ExpectedVersionDate                                     "Sep  9 2019"
#define __ExpectedVersionTime                                     "15:22:59"
#define __ActualVersionDate_x                                      0xAE14A4
#define __ActualVersionTime_x                                      0xAE1498
#define __ActualVersionBuild_x                                     0xAE1F3C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x61B3F0
#define __MemChecker1_x                                            0x8F1960
#define __MemChecker2_x                                            0x6AA7B0
#define __MemChecker3_x                                            0x6AA700
#define __MemChecker4_x                                            0x848D40
#define __EncryptPad0_x                                            0xC13A30
#define __EncryptPad1_x                                            0xC71A80
#define __EncryptPad2_x                                            0xC242B0
#define __EncryptPad3_x                                            0xC23EB0
#define __EncryptPad4_x                                            0xC62228
#define __EncryptPad5_x                                            0xF3B308
#define __AC1_x                                                    0x805B86
#define __AC2_x                                                    0x5D512F
#define __AC3_x                                                    0x5DC82F
#define __AC4_x                                                    0x5E06E0
#define __AC5_x                                                    0x5E69DF
#define __AC6_x                                                    0x5EAFF6
#define __AC7_x                                                    0x5D4BA0
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
#define __do_loot_x                                                0x5A1600
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
#define __gfMaxZoomCameraDistance_x                                0xAD68E0
#define __gfMaxCameraDistance_x                                    0xB03F40
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
#define __CastRay_x                                                0x59CA60
#define __CastRay2_x                                               0x59CAB0
#define __ConvertItemTags_x                                        0x5B8600
#define __CrashHandler_x                                           0x852640
#define __CleanItemTags_x                                          0x4778C0
#define __DoesFileExist_x                                          0x8F49D0
#define __EQGetTime_x                                              0x8F1430
#define __ExecuteCmd_x                                             0x595460
#define __FixHeading_x                                             0x98C500
#define __GameLoop_x                                               0x6A9C70
#define __get_bearing_x                                            0x59C5D0
#define __get_melee_range_x                                        0x59CCA0
#define __GetAnimationCache_x                                      0x70EB90
#define __GetGaugeValueFromEQ_x                                    0x804030
#define __GetLabelFromEQ_x                                         0x805B10
#define __GetXTargetType_x                                         0x98E030
#define __HandleMouseWheel_x                                       0x6AA860
#define __HeadingDiff_x                                            0x98C570
#define __HelpPath_x                                               0xF34FDC
#define __LoadFrontEnd_x                                           0x6A6740
#define __NewUIINI_x                                               0x803D00
#define __pCrashHandler_x                                          0x1076358
#define __ProcessGameEvents_x                                      0x5FC870
#define __ProcessMouseEvent_x                                      0x5FC030
#define __SaveColors_x                                             0x546050
#define __STMLToText_x                                             0x92F840
#define __ToggleKeyRingItem_x                                      0x507AD0
#define CMemoryMappedFile__SetFile_x                               0xA66710
#define CrashDetected_x                                            0x6A81C0
#define DrawNetStatus_x                                            0x628820
#define Expansion_HoT_x                                            0xE96F34
#define Teleport_Table_Size_x                                      0xE86308
#define Teleport_Table_x                                           0xE86768
#define Util__FastTime_x                                           0x8F1000
#define wwsCrashReportCheckForUploader_x                           0x853480
#define wwsCrashReportPlatformLaunchUploader_x                     0x855B40

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48ABD0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x493AF0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4938C0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x48E170
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x48D5C0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x54DB10
#define AltAdvManager__IsAbilityReady_x                            0x54CA90
#define AltAdvManager__GetAAById_x                                 0x54CC90
#define AltAdvManager__CanTrainAbility_x                           0x54CD00
#define AltAdvManager__CanSeeAbility_x                             0x54D060

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C65E0
#define CharacterZoneClient__HasSkill_x                            0x4D14D0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D2BF0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BABC0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B7300
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D5560
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D5640
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D5720
#define CharacterZoneClient__FindAffectSlot_x                      0x4BF6C0
#define CharacterZoneClient__BardCastBard_x                        0x4C2220
#define CharacterZoneClient__GetMaxEffects_x                       0x4B73D0
#define CharacterZoneClient__GetEffect_x                           0x4B7240
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C0700
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C07D0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C0820
#define CharacterZoneClient__CalcAffectChange_x                    0x4C0970
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C0B50
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4AF1D0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D3B50
#define CharacterZoneClient__FindItemByRecord_x                    0x4D35D0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D0410
#define CBankWnd__WndNotification_x                                0x6D01F0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6DDCC0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x60B280
#define CButtonWnd__CButtonWnd_x                                   0x92BC20

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6FDD10
#define CChatManager__InitContextMenu_x                            0x6F6EE0
#define CChatManager__FreeChatWindow_x                             0x6FC830
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E4B10
#define CChatManager__SetLockedActiveChatWindow_x                  0x6FD990
#define CChatManager__CreateChatWindow_x                           0x6FCE70

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E4C20

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x9403E0
#define CContextMenu__dCContextMenu_x                              0x940610
#define CContextMenu__AddMenuItem_x                                0x940620
#define CContextMenu__RemoveMenuItem_x                             0x940930
#define CContextMenu__RemoveAllMenuItems_x                         0x940950
#define CContextMenu__CheckMenuItem_x                              0x9409D0
#define CContextMenu__SetMenuItem_x                                0x940850
#define CContextMenu__AddSeparator_x                               0x9407B0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x940F60
#define CContextMenuManager__RemoveMenu_x                          0x940FD0
#define CContextMenuManager__PopupMenu_x                           0x941090
#define CContextMenuManager__Flush_x                               0x940F00
#define CContextMenuManager__GetMenu_x                             0x495C10
#define CContextMenuManager__CreateDefaultMenu_x                   0x7093A0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D2130
#define CChatService__GetFriendName_x                              0x8D2140

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6FE580
#define CChatWindow__Clear_x                                       0x6FF850
#define CChatWindow__WndNotification_x                             0x6FFFE0
#define CChatWindow__AddHistory_x                                  0x6FF110

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93D830
#define CComboWnd__Draw_x                                          0x93CD30
#define CComboWnd__GetCurChoice_x                                  0x93D670
#define CComboWnd__GetListRect_x                                   0x93D1D0
#define CComboWnd__GetTextRect_x                                   0x93D8A0
#define CComboWnd__InsertChoice_x                                  0x93D360
#define CComboWnd__SetColors_x                                     0x93D330
#define CComboWnd__SetChoice_x                                     0x93D640
#define CComboWnd__GetItemCount_x                                  0x93D680
#define CComboWnd__GetCurChoiceText_x                              0x93D6C0
#define CComboWnd__GetChoiceText_x                                 0x93D690
#define CComboWnd__InsertChoiceAtIndex_x                           0x93D400

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x706D90
#define CContainerWnd__vftable_x                                   0xAEA74C
#define CContainerWnd__SetContainer_x                              0x708300

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x540AF0
#define CDisplay__PreZoneMainUI_x                                  0x540B00
#define CDisplay__CleanGameUI_x                                    0x545E10
#define CDisplay__GetClickedActor_x                                0x538E10
#define CDisplay__GetUserDefinedColor_x                            0x5314D0
#define CDisplay__GetWorldFilePath_x                               0x53A880
#define CDisplay__is3dON_x                                         0x535A70
#define CDisplay__ReloadUI_x                                       0x53FF80
#define CDisplay__WriteTextHD2_x                                   0x535860
#define CDisplay__TrueDistance_x                                   0x53C540
#define CDisplay__SetViewActor_x                                   0x538730
#define CDisplay__GetFloorHeight_x                                 0x535B30
#define CDisplay__SetRenderWindow_x                                0x534490
#define CDisplay__ToggleScreenshotMode_x                           0x538200

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x9600D0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x943930
#define CEditWnd__GetCharIndexPt_x                                 0x944860
#define CEditWnd__GetDisplayString_x                               0x944700
#define CEditWnd__GetHorzOffset_x                                  0x942F60
#define CEditWnd__GetLineForPrintableChar_x                        0x945A00
#define CEditWnd__GetSelStartPt_x                                  0x944B10
#define CEditWnd__GetSTMLSafeText_x                                0x944520
#define CEditWnd__PointFromPrintableChar_x                         0x945630
#define CEditWnd__SelectableCharFromPoint_x                        0x9457A0
#define CEditWnd__SetEditable_x                                    0x944BE0
#define CEditWnd__SetWindowTextA_x                                 0x9442A0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5EA4D0
#define CEverQuest__ClickedPlayer_x                                0x5DC610
#define CEverQuest__CreateTargetIndicator_x                        0x5F9B00
#define CEverQuest__DeleteTargetIndicator_x                        0x5F9B90
#define CEverQuest__DoTellWindow_x                                 0x4E4D00
#define CEverQuest__OutputTextToLog_x                              0x4E4F60
#define CEverQuest__DropHeldItemOnGround_x                         0x5D1650
#define CEverQuest__dsp_chat_x                                     0x4E52F0
#define CEverQuest__trimName_x                                     0x5F5DE0
#define CEverQuest__Emote_x                                        0x5EAD30
#define CEverQuest__EnterZone_x                                    0x5E4CB0
#define CEverQuest__GetBodyTypeDesc_x                              0x5EF6A0
#define CEverQuest__GetClassDesc_x                                 0x5EFCE0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5F02E0
#define CEverQuest__GetDeityDesc_x                                 0x5F8440
#define CEverQuest__GetLangDesc_x                                  0x5F04A0
#define CEverQuest__GetRaceDesc_x                                  0x5EFCC0
#define CEverQuest__InterpretCmd_x                                 0x5F8A10
#define CEverQuest__LeftClickedOnPlayer_x                          0x5D5850
#define CEverQuest__LMouseUp_x                                     0x5D3BE0
#define CEverQuest__RightClickedOnPlayer_x                         0x5D6130
#define CEverQuest__RMouseUp_x                                     0x5D4B60
#define CEverQuest__SetGameState_x                                 0x5D13E0
#define CEverQuest__UPCNotificationFlush_x                         0x5F5CE0
#define CEverQuest__IssuePetCommand_x                              0x5F18A0
#define CEverQuest__ReportSuccessfulHit_x                          0x5EC120

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x718D50
#define CGaugeWnd__CalcLinesFillRect_x                             0x718DB0
#define CGaugeWnd__Draw_x                                          0x7183D0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ABC10
#define CGuild__GetGuildName_x                                     0x4AACF0
#define CGuild__GetGuildIndex_x                                    0x4AB080

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x7341C0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x60B640

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x7411E0
#define CInvSlotMgr__MoveItem_x                                    0x73FF10
#define CInvSlotMgr__SelectSlot_x                                  0x7412B0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x73E7C0
#define CInvSlot__SliderComplete_x                                 0x73C550
#define CInvSlot__GetItemBase_x                                    0x73BEC0
#define CInvSlot__UpdateItem_x                                     0x73C030

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x742D30
#define CInvSlotWnd__CInvSlotWnd_x                                 0x741EE0
#define CInvSlotWnd__HandleLButtonUp_x                             0x7428B0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7FF410
#define CItemDisplayWnd__UpdateStrings_x                           0x7514E0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x74B1A0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x74B6D0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x751AE0
#define CItemDisplayWnd__AboutToShow_x                             0x751130
#define CItemDisplayWnd__WndNotification_x                         0x752BD0
#define CItemDisplayWnd__RequestConvertItem_x                      0x752690
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x750190
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x750F50

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x837DD0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x7570D0

// CLabel 
#define CLabel__Draw_x                                             0x75CAB0

// CListWnd
#define CListWnd__CListWnd_x                                       0x915E40
#define CListWnd__dCListWnd_x                                      0x916160
#define CListWnd__AddColumn_x                                      0x91A5B0
#define CListWnd__AddColumn1_x                                     0x91A600
#define CListWnd__AddLine_x                                        0x91A990
#define CListWnd__AddString_x                                      0x91A790
#define CListWnd__CalculateFirstVisibleLine_x                      0x91A370
#define CListWnd__CalculateVSBRange_x                              0x91A150
#define CListWnd__ClearSel_x                                       0x91B170
#define CListWnd__ClearAllSel_x                                    0x91B1D0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x91BBF0
#define CListWnd__Compare_x                                        0x919A90
#define CListWnd__Draw_x                                           0x916290
#define CListWnd__DrawColumnSeparators_x                           0x918A70
#define CListWnd__DrawHeader_x                                     0x918ED0
#define CListWnd__DrawItem_x                                       0x9193D0
#define CListWnd__DrawLine_x                                       0x918BD0
#define CListWnd__DrawSeparator_x                                  0x918B10
#define CListWnd__EnableLine_x                                     0x918350
#define CListWnd__EnsureVisible_x                                  0x91BB10
#define CListWnd__ExtendSel_x                                      0x91B0A0
#define CListWnd__GetColumnTooltip_x                               0x917E90
#define CListWnd__GetColumnMinWidth_x                              0x917F00
#define CListWnd__GetColumnWidth_x                                 0x917E00
#define CListWnd__GetCurSel_x                                      0x917790
#define CListWnd__GetItemAtPoint_x                                 0x9185C0
#define CListWnd__GetItemAtPoint1_x                                0x918630
#define CListWnd__GetItemData_x                                    0x917810
#define CListWnd__GetItemHeight_x                                  0x917BD0
#define CListWnd__GetItemIcon_x                                    0x9179A0
#define CListWnd__GetItemRect_x                                    0x918440
#define CListWnd__GetItemText_x                                    0x917850
#define CListWnd__GetSelList_x                                     0x91B220
#define CListWnd__GetSeparatorRect_x                               0x918870
#define CListWnd__InsertLine_x                                     0x91AD80
#define CListWnd__RemoveLine_x                                     0x91AED0
#define CListWnd__SetColors_x                                      0x91A120
#define CListWnd__SetColumnJustification_x                         0x919E60
#define CListWnd__SetColumnWidth_x                                 0x919D80
#define CListWnd__SetCurSel_x                                      0x91AFE0
#define CListWnd__SetItemColor_x                                   0x91B7C0
#define CListWnd__SetItemData_x                                    0x91B780
#define CListWnd__SetItemText_x                                    0x91B390
#define CListWnd__ShiftColumnSeparator_x                           0x919F20
#define CListWnd__Sort_x                                           0x919C10
#define CListWnd__ToggleSel_x                                      0x91B010
#define CListWnd__SetColumnsSizable_x                              0x919FC0
#define CListWnd__SetItemWnd_x                                     0x91B640
#define CListWnd__GetItemWnd_x                                     0x9179F0
#define CListWnd__SetItemIcon_x                                    0x91B410
#define CListWnd__CalculateCustomWindowPositions_x                 0x91A470
#define CListWnd__SetVScrollPos_x                                  0x919D60

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x772150
#define CMapViewWnd__GetWorldCoordinates_x                         0x770860
#define CMapViewWnd__HandleLButtonDown_x                           0x76D8A0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x795090
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x795970
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x795EA0
#define CMerchantWnd__SelectRecoverySlot_x                         0x798E30
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x793C00
#define CMerchantWnd__SelectBuySellSlot_x                          0x79E9E0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x794CB0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89FC60
#define CPacketScrambler__hton_x                                   0x89FC50

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x934E90
#define CSidlManager__FindScreenPieceTemplate_x                    0x9352A0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x935090
#define CSidlManager__CreateLabel_x                                0x7F6860
#define CSidlManager__CreateXWndFromTemplate_x                     0x938200
#define CSidlManager__CreateXWndFromTemplate1_x                    0x9383E0
#define CSidlManager__CreateXWnd_x                                 0x7F6790
#define CSidlManager__CreateHotButtonWnd_x                         0x7F6D60

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x931970
#define CSidlScreenWnd__CalculateVSBRange_x                        0x931870
#define CSidlScreenWnd__ConvertToRes_x                             0x957090
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x931300
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x930FF0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x9310C0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x931190
#define CSidlScreenWnd__DrawSidlPiece_x                            0x931E10
#define CSidlScreenWnd__EnableIniStorage_x                         0x9322E0
#define CSidlScreenWnd__GetSidlPiece_x                             0x932000
#define CSidlScreenWnd__Init1_x                                    0x930BF0
#define CSidlScreenWnd__LoadIniInfo_x                              0x932330
#define CSidlScreenWnd__LoadIniListWnd_x                           0x932E70
#define CSidlScreenWnd__LoadSidlScreen_x                           0x930000
#define CSidlScreenWnd__StoreIniInfo_x                             0x9329F0
#define CSidlScreenWnd__StoreIniVis_x                              0x932D50
#define CSidlScreenWnd__WndNotification_x                          0x931D20
#define CSidlScreenWnd__GetChildItem_x                             0x932260
#define CSidlScreenWnd__HandleLButtonUp_x                          0x921A30
#define CSidlScreenWnd__m_layoutCopy_x                             0x16D1390

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x66F920
#define CSkillMgr__GetSkillCap_x                                   0x66FB00
#define CSkillMgr__GetNameToken_x                                  0x66F0A0
#define CSkillMgr__IsActivatedSkill_x                              0x66F1E0
#define CSkillMgr__IsCombatSkill_x                                 0x66F120

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x941D40
#define CSliderWnd__SetValue_x                                     0x941BB0
#define CSliderWnd__SetNumTicks_x                                  0x941C10

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7FC8A0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x94A570
#define CStmlWnd__CalculateHSBRange_x                              0x94B690
#define CStmlWnd__CalculateVSBRange_x                              0x94B600
#define CStmlWnd__CanBreakAtCharacter_x                            0x94F9C0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x950650
#define CStmlWnd__ForceParseNow_x                                  0x94AB60
#define CStmlWnd__GetNextTagPiece_x                                0x94F920
#define CStmlWnd__GetSTMLText_x                                    0x4F7600
#define CStmlWnd__GetVisibleText_x                                 0x94AB80
#define CStmlWnd__InitializeWindowVariables_x                      0x9504A0
#define CStmlWnd__MakeStmlColorTag_x                               0x949BE0
#define CStmlWnd__MakeWndNotificationTag_x                         0x949C50
#define CStmlWnd__SetSTMLText_x                                    0x948C90
#define CStmlWnd__StripFirstSTMLLines_x                            0x951720
#define CStmlWnd__UpdateHistoryString_x                            0x950860

// CTabWnd 
#define CTabWnd__Draw_x                                            0x947DE0
#define CTabWnd__DrawCurrentPage_x                                 0x948510
#define CTabWnd__DrawTab_x                                         0x948230
#define CTabWnd__GetCurrentPage_x                                  0x9475E0
#define CTabWnd__GetPageInnerRect_x                                0x947820
#define CTabWnd__GetTabInnerRect_x                                 0x947760
#define CTabWnd__GetTabRect_x                                      0x947610
#define CTabWnd__InsertPage_x                                      0x947A30
#define CTabWnd__SetPage_x                                         0x9478A0
#define CTabWnd__SetPageRect_x                                     0x947D20
#define CTabWnd__UpdatePage_x                                      0x9480F0
#define CTabWnd__GetPageFromTabIndex_x                             0x948170
#define CTabWnd__GetCurrentTabIndex_x                              0x9475D0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x7574A0
#define CPageWnd__SetTabText_x                                     0x947120

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A5900

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91E8E0
#define CTextureFont__GetTextExtent_x                              0x91EAA0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6A3620
#define CHtmlComponentWnd__ValidateUri_x                           0x735BB0
#define CHtmlWnd__SetClientCallbacks_x                             0x6106B0
#define CHtmlWnd__AddObserver_x                                    0x6106D0
#define CHtmlWnd__RemoveObserver_x                                 0x610730
#define Window__getProgress_x                                      0x850340
#define Window__getStatus_x                                        0x850360
#define Window__getURI_x                                           0x850370

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x95CB60

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x90BA70

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E4A00
#define CXStr__CXStr1_x                                            0x9CDDF0
#define CXStr__CXStr3_x                                            0x8ED570
#define CXStr__dCXStr_x                                            0x472F20
#define CXStr__operator_equal_x                                    0x8ED7A0
#define CXStr__operator_equal1_x                                   0x8ED7E0
#define CXStr__operator_plus_equal1_x                              0x8EE270
#define CXStr__SetString_x                                         0x8F0160
#define CXStr__operator_char_p_x                                   0x8EDCE0
#define CXStr__GetChar_x                                           0x8EFA90
#define CXStr__Delete_x                                            0x8EF360
#define CXStr__GetUnicode_x                                        0x8EFB00
#define CXStr__GetLength_x                                         0x477C70
#define CXStr__Mid_x                                               0x477C80
#define CXStr__Insert_x                                            0x8EFB60
#define CXStr__FindNext_x                                          0x8EF7D0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93FFF0
#define CXWnd__BringToTop_x                                        0x925170
#define CXWnd__Center_x                                            0x924CF0
#define CXWnd__ClrFocus_x                                          0x924B00
#define CXWnd__Destroy_x                                           0x924BB0
#define CXWnd__DoAllDrawing_x                                      0x9211F0
#define CXWnd__DrawChildren_x                                      0x9211C0
#define CXWnd__DrawColoredRect_x                                   0x921640
#define CXWnd__DrawTooltip_x                                       0x91FD20
#define CXWnd__DrawTooltipAtPoint_x                                0x91FDE0
#define CXWnd__GetBorderFrame_x                                    0x9214A0
#define CXWnd__GetChildWndAt_x                                     0x925210
#define CXWnd__GetClientClipRect_x                                 0x923420
#define CXWnd__GetScreenClipRect_x                                 0x9234F0
#define CXWnd__GetScreenRect_x                                     0x923690
#define CXWnd__GetTooltipRect_x                                    0x921690
#define CXWnd__GetWindowTextA_x                                    0x497380
#define CXWnd__IsActive_x                                          0x921DB0
#define CXWnd__IsDescendantOf_x                                    0x924060
#define CXWnd__IsReallyVisible_x                                   0x924090
#define CXWnd__IsType_x                                            0x925880
#define CXWnd__Move_x                                              0x924100
#define CXWnd__Move1_x                                             0x9241C0
#define CXWnd__ProcessTransition_x                                 0x924CA0
#define CXWnd__Refade_x                                            0x9244A0
#define CXWnd__Resize_x                                            0x924720
#define CXWnd__Right_x                                             0x924F30
#define CXWnd__SetFocus_x                                          0x924AC0
#define CXWnd__SetFont_x                                           0x924B30
#define CXWnd__SetKeyTooltip_x                                     0x925690
#define CXWnd__SetMouseOver_x                                      0x9225D0
#define CXWnd__StartFade_x                                         0x923F40
#define CXWnd__GetChildItem_x                                      0x925380
#define CXWnd__SetParent_x                                         0x923E30
#define CXWnd__Minimize_x                                          0x924790

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x958110

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9280F0
#define CXWndManager__DrawWindows_x                                0x928110
#define CXWndManager__GetKeyboardFlags_x                           0x92A8A0
#define CXWndManager__HandleKeyboardMsg_x                          0x92A450
#define CXWndManager__RemoveWnd_x                                  0x92AAF0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x92B040

// CDBStr
#define CDBStr__GetString_x                                        0x5304A0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B82E0
#define EQ_Character__Cur_HP_x                                     0x4CE510
#define EQ_Character__Cur_Mana_x                                   0x4D5C20
#define EQ_Character__GetCastingTimeModifier_x                     0x4BB210
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AEE10
#define EQ_Character__GetFocusRangeModifier_x                      0x4AEF60
#define EQ_Character__GetHPRegen_x                                 0x4DB9C0
#define EQ_Character__GetEnduranceRegen_x                          0x4DBFC0
#define EQ_Character__GetManaRegen_x                               0x4DC400
#define EQ_Character__Max_Endurance_x                              0x6364C0
#define EQ_Character__Max_HP_x                                     0x4CE340
#define EQ_Character__Max_Mana_x                                   0x6362C0
#define EQ_Character__doCombatAbility_x                            0x638910
#define EQ_Character__UseSkill_x                                   0x4DE1E0
#define EQ_Character__GetConLevel_x                                0x62F720
#define EQ_Character__IsExpansionFlag_x                            0x593BF0
#define EQ_Character__TotalEffect_x                                0x4C1960
#define EQ_Character__GetPCSpellAffect_x                           0x4BBE20
#define EQ_Character__SpellDuration_x                              0x4BB950
#define EQ_Character__GetAdjustedSkill_x                           0x4D1290
#define EQ_Character__GetBaseSkill_x                               0x4D2230
#define EQ_Character__CanUseItem_x                                 0x4D5F30

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BEFF0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x64C990

//PcClient
#define PcClient__PcClient_x                                       0x62CE60

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B5F30
#define CCharacterListWnd__EnterWorld_x                            0x4B5970
#define CCharacterListWnd__Quit_x                                  0x4B56C0
#define CCharacterListWnd__UpdateList_x                            0x4B5B00

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6118F0
#define EQ_Item__CreateItemTagString_x                             0x899520
#define EQ_Item__IsStackable_x                                     0x89E010
#define EQ_Item__GetImageNum_x                                     0x89AFA0
#define EQ_Item__CreateItemClient_x                                0x610AB0
#define EQ_Item__GetItemValue_x                                    0x89C290
#define EQ_Item__ValueSellMerchant_x                               0x89F830
#define EQ_Item__IsKeyRingItem_x                                   0x89D960
#define EQ_Item__CanGoInBag_x                                      0x611A10
#define EQ_Item__IsEmpty_x                                         0x89D4D0
#define EQ_Item__GetMaxItemCount_x                                 0x89C6B0
#define EQ_Item__GetHeldItem_x                                     0x89AE70
#define EQ_Item__GetAugmentFitBySlot_x                             0x898E90

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x54E7F0
#define EQ_LoadingS__Array_x                                       0xBFB690

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x636E10
#define EQ_PC__GetAlternateAbilityId_x                             0x8A8A90
#define EQ_PC__GetCombatAbility_x                                  0x8A9100
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A9170
#define EQ_PC__GetItemRecastTimer_x                                0x638E90
#define EQ_PC__HasLoreItem_x                                       0x62FF30
#define EQ_PC__AlertInventoryChanged_x                             0x62F060
#define EQ_PC__GetPcZoneClient_x                                   0x65B3B0
#define EQ_PC__RemoveMyAffect_x                                    0x63C0C0
#define EQ_PC__GetKeyRingItems_x                                   0x8A99D0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A9790
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A9CC0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x59A110
#define EQItemList__add_object_x                                   0x5C6D80
#define EQItemList__add_item_x                                     0x59A670
#define EQItemList__delete_item_x                                  0x59A6C0
#define EQItemList__FreeItemList_x                                 0x59A5C0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x52CF20

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x64E210
#define EQPlayer__dEQPlayer_x                                      0x641560
#define EQPlayer__DoAttack_x                                       0x656070
#define EQPlayer__EQPlayer_x                                       0x641C20
#define EQPlayer__SetNameSpriteState_x                             0x645EF0
#define EQPlayer__SetNameSpriteTint_x                              0x646DC0
#define PlayerBase__HasProperty_j_x                                0x98A8D0
#define EQPlayer__IsTargetable_x                                   0x98AD70
#define EQPlayer__CanSee_x                                         0x98ABD0
#define EQPlayer__CanSee1_x                                        0x98ACA0
#define PlayerBase__GetVisibilityLineSegment_x                     0x98A990

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x658E40
#define PlayerZoneClient__GetLevel_x                               0x65B3F0
#define PlayerZoneClient__IsValidTeleport_x                        0x5C7EF0
#define PlayerZoneClient__LegalPlayerRace_x                        0x547C70

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x650F60
#define EQPlayerManager__GetSpawnByName_x                          0x651010
#define EQPlayerManager__GetPlayerFromPartialName_x                0x6510A0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x614F60
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x614FE0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x615020
#define KeypressHandler__ClearCommandStateArray_x                  0x616430
#define KeypressHandler__HandleKeyDown_x                           0x616450
#define KeypressHandler__HandleKeyUp_x                             0x6164F0
#define KeypressHandler__SaveKeymapping_x                          0x616930

// MapViewMap 
#define MapViewMap__Clear_x                                        0x76DFC0
#define MapViewMap__SaveEx_x                                       0x771380
#define MapViewMap__SetZoom_x                                      0x775A40

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BCF10

// StringTable 
#define StringTable__getString_x                                   0x8B7CD0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x63BD30
#define PcZoneClient__RemovePetEffect_x                            0x63C360
#define PcZoneClient__HasAlternateAbility_x                        0x6360F0
#define PcZoneClient__GetCurrentMod_x                              0x4E12A0
#define PcZoneClient__GetModCap_x                                  0x4E11A0
#define PcZoneClient__CanEquipItem_x                               0x6367B0
#define PcZoneClient__GetItemByID_x                                0x639300
#define PcZoneClient__GetItemByItemClass_x                         0x639450
#define PcZoneClient__RemoveBuffEffect_x                           0x63C380
#define PcZoneClient__BandolierSwap_x                              0x6373D0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x638E30

//Doors
#define EQSwitch__UseSwitch_x                                      0x5CCA80

//IconCache
#define IconCache__GetIcon_x                                       0x70E430

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x705F20
#define CContainerMgr__CloseContainer_x                            0x7061F0
#define CContainerMgr__OpenExperimentContainer_x                   0x706C70

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7C9060

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x609A70

//CLootWnd
#define CLootWnd__LootAll_x                                        0x7643E0
#define CLootWnd__RequestLootSlot_x                                0x763610

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x566D50
#define EQ_Spell__SpellAffects_x                                   0x5671C0
#define EQ_Spell__SpellAffectBase_x                                0x566F80
#define EQ_Spell__IsStackable_x                                    0x4C5F10
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C5D60
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B32E0
#define EQ_Spell__IsSPAStacking_x                                  0x568000
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x567520
#define EQ_Spell__IsNoRemove_x                                     0x4C5EF0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x568010
#define __IsResEffectSpell_x                                       0x4C5300

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4A9960

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C75C0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x80FB50
#define CTargetWnd__WndNotification_x                              0x80F3E0
#define CTargetWnd__RefreshTargetBuffs_x                           0x80F6B0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x80E540

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x814160

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x52A950
#define CTaskManager__HandleMessage_x                              0x528DF0
#define CTaskManager__GetTaskStatus_x                              0x52AA00
#define CTaskManager__GetElementDescription_x                      0x52AA80

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x562290
#define EqSoundManager__PlayScriptMp3_x                            0x5623F0
#define EqSoundManager__SoundAssistPlay_x                          0x673890
#define EqSoundManager__WaveInstancePlay_x                         0x672E00

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x51E710

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x946630

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x556280
#define CAltAbilityData__GetMercMaxRank_x                          0x556210
#define CAltAbilityData__GetMaxRank_x                              0x54B950

//CTargetRing
#define CTargetRing__Cast_x                                        0x607B90

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C5D40
#define CharacterBase__CreateItemGlobalIndex_x                     0x504380
#define CharacterBase__CreateItemIndex_x                           0x60FC60
#define CharacterBase__GetItemPossession_x                         0x4EFFE0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CFBD0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CFC30
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6ED1C0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6ED9F0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6EDAA0

//messages
#define msg_spell_worn_off_x                                       0x58BDD0
#define msg_new_text_x                                             0x580B90
#define __msgTokenTextParam_x                                      0x58E300
#define msgTokenText_x                                             0x58E550

//SpellManager
#define SpellManager__vftable_x                                    0xAC4C04
#define SpellManager__SpellManager_x                               0x676BC0
#define Spellmanager__LoadTextSpells_x                             0x6774C0
#define SpellManager__GetSpellByGroupAndRank_x                     0x676D90

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98E920

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x504A30
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5920D0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x628680
#define ItemGlobalIndex__IsValidIndex_x                            0x504A90

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C7F60
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C81E0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x75CDF0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x70A640
#define CCursorAttachment__AttachToCursor1_x                       0x70A680
#define CCursorAttachment__Deactivate_x                            0x70B650

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x939230
#define CSidlManagerBase__CreatePageWnd_x                          0x938A30
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x934CB0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x934C40

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x956470
#define CEQSuiteTextureLoader__GetTexture_x                        0x956130

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x501920
#define CFindItemWnd__WndNotification_x                            0x502400
#define CFindItemWnd__Update_x                                     0x502F70
#define CFindItemWnd__PickupSelectedItem_x                         0x501190

//IString
#define IString__Append_x                                          0x4F17E0

//Camera
#define CDisplay__cameraType_x                                     0xDD38FC
#define EverQuest__Cameras_x                                       0xE9727C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x509DA0
#define LootFiltersManager__GetItemFilterData_x                    0x5096B0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x5096E0
#define LootFiltersManager__SetItemLootFilter_x                    0x509900

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B7000

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x994470
#define CResolutionHandler__GetWindowedStyle_x                     0x66E3E0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x702CF0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8DA8C0
#define CDistillerInfo__Instance_x                                 0x8DA860

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x722F80
#define CGroupWnd__UpdateDisplay_x                                 0x7222D0

//ItemBase
#define ItemBase__IsLore_x                                         0x89D9C0
#define ItemBase__IsLoreEquipped_x                                 0x89DA40

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5C6CE0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5C6E20
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5C6E80

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x663B30
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x6674B0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x4F7C50

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4E6680
#define FactionManagerClient__HandleFactionMessage_x               0x4E6CF0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4E72B0
#define FactionManagerClient__GetMaxFaction_x                      0x4E72CF
#define FactionManagerClient__GetMinFaction_x                      0x4E7280

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4EFFB0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91D860

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x496690

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4F0210

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x555720

//CTargetManager
#define CTargetManager__Get_x                                      0x67A3F0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x663B30

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A56C0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x59A560

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF3490C

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
