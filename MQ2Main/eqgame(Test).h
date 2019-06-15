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
#define __ExpectedVersionDate                                     "Jun 10 2019"
#define __ExpectedVersionTime                                     "18:34:29"
#define __ActualVersionDate_x                                      0xAD743C
#define __ActualVersionTime_x                                      0xAD7430
#define __ActualVersionBuild_x                                     0xAD7ED4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x61B800
#define __MemChecker1_x                                            0x8F1EA0
#define __MemChecker2_x                                            0x6AABD0
#define __MemChecker3_x                                            0x6AAB20
#define __MemChecker4_x                                            0x848C60
#define __EncryptPad0_x                                            0xC0C998
#define __EncryptPad1_x                                            0xC6A998
#define __EncryptPad2_x                                            0xC1D210
#define __EncryptPad3_x                                            0xC1CE10
#define __EncryptPad4_x                                            0xC5B188
#define __EncryptPad5_x                                            0xF35410
#define __AC1_x                                                    0x805726
#define __AC2_x                                                    0x5D52CF
#define __AC3_x                                                    0x5DC9DF
#define __AC4_x                                                    0x5E08C0
#define __AC5_x                                                    0x5E6B30
#define __AC6_x                                                    0x5EB1C6
#define __AC7_x                                                    0x5D4D40
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1F3CCC

// Direct Input
#define DI8__Main_x                                                0xF35430
#define DI8__Keyboard_x                                            0xF35434
#define DI8__Mouse_x                                               0xF349F0
#define DI8__Mouse_Copy_x                                          0xE900CC
#define DI8__Mouse_Check_x                                         0xF35764
#define __AutoSkillArray_x                                         0xE90FE4
#define __Attack_x                                                 0xF2EDFB
#define __Autofire_x                                               0xF2EDFC
#define __BindList_x                                               0xBFB3F0
#define g_eqCommandStates_x                                        0xBFC168
#define __Clicks_x                                                 0xE90184
#define __CommandList_x                                            0xBFCD28
#define __CurrentMapLabel_x                                        0x104FEA4
#define __CurrentSocial_x                                          0xBE5730
#define __DoAbilityList_x                                          0xEC691C
#define __do_loot_x                                                0x5A1930
#define __DrawHandler_x                                            0x16CC870
#define __GroupCount_x                                             0xE82942
#define __Guilds_x                                                 0xE868D8
#define __gWorld_x                                                 0xE82B60
#define __HWnd_x                                                   0xF349F4
#define __heqmain_x                                                0x103FA4C
#define __InChatMode_x                                             0xE900B4
#define __LastTell_x                                               0xE92018
#define __LMouseHeldTime_x                                         0xE901F0
#define __Mouse_x                                                  0xF3541C
#define __MouseLook_x                                              0xE9014A
#define __MouseEventTime_x                                         0xF2F8DC
#define __gpbCommandEvent_x                                        0xE80368
#define __NetStatusToggle_x                                        0xE9014D
#define __PCNames_x                                                0xE915C8
#define __RangeAttackReady_x                                       0xE912C8
#define __RMouseHeldTime_x                                         0xE901EC
#define __RunWalkState_x                                           0xE900B8
#define __ScreenMode_x                                             0xDCE4F8
#define __ScreenX_x                                                0xE9006C
#define __ScreenY_x                                                0xE90068
#define __ScreenXMax_x                                             0xE90070
#define __ScreenYMax_x                                             0xE90074
#define __ServerHost_x                                             0xE8059B
#define __ServerName_x                                             0xEC68DC
#define __ShiftKeyDown_x                                           0xE90744
#define __ShowNames_x                                              0xE91484
#define __Socials_x                                                0xEC69DC
#define __SubscriptionType_x                                       0x1091A38
#define __TargetAggroHolder_x                                      0x1052858
#define __ZoneType_x                                               0xE90548
#define __GroupAggro_x                                             0x1052898
#define __LoginName_x                                              0xF350B4
#define __Inviter_x                                                0xF2ED78
#define __AttackOnAssist_x                                         0xE91440
#define __UseTellWindows_x                                         0xE91764
#define __gfMaxZoomCameraDistance_x                                0xACC8C8
#define __gfMaxCameraDistance_x                                    0xAF9DD0
#define __pulAutoRun_x                                             0xE90168
#define __pulForward_x                                             0xE9179C
#define __pulBackward_x                                            0xE917A0
#define __pulTurnRight_x                                           0xE917A4
#define __pulTurnLeft_x                                            0xE917A8
#define __pulStrafeLeft_x                                          0xE917AC
#define __pulStrafeRight_x                                         0xE917B0

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE82C70
#define instEQZoneInfo_x                                           0xE90340
#define pinstActiveBanker_x                                        0xE80400
#define pinstActiveCorpse_x                                        0xE803F8
#define pinstActiveGMaster_x                                       0xE803FC
#define pinstActiveMerchant_x                                      0xE803F4
#define pinstAltAdvManager_x                                       0xDCEF40
#define pinstBandageTarget_x                                       0xE80410
#define pinstCamActor_x                                            0xDCE4EC
#define pinstCDBStr_x                                              0xDCDC6C
#define pinstCDisplay_x                                            0xE82B64
#define pinstCEverQuest_x                                          0x103EA3C
#define pinstEverQuestInfo_x                                       0xE90060
#define pinstCharData_x                                            0xE80920
#define pinstCharSpawn_x                                           0xE80448
#define pinstControlledMissile_x                                   0xE80914
#define pinstControlledPlayer_x                                    0xE80448
#define pinstCResolutionHandler_x                                  0x16CCAA0
#define pinstCSidlManager_x                                        0x16CBA3C
#define pinstCXWndManager_x                                        0x16CBA30
#define instDynamicZone_x                                          0xE867B0
#define pinstDZMember_x                                            0xE868C0
#define pinstDZTimerInfo_x                                         0xE868C4
#define pinstEqLogin_x                                             0xF34A00
#define instEQMisc_x                                               0xDCDBB0
#define pinstEQSoundManager_x                                      0xDCFE68
#define pinstEQSpellStrings_x                                      0xC8F3C0
#define instExpeditionLeader_x                                     0xE867FA
#define instExpeditionName_x                                       0xE8683A
#define pinstGroup_x                                               0xE8293E
#define pinstImeManager_x                                          0x16CBA34
#define pinstLocalPlayer_x                                         0xE803F0
#define pinstMercenaryData_x                                       0xF313CC
#define pinstMercenaryStats_x                                      0x10529A4
#define pinstModelPlayer_x                                         0xE80408
#define pinstPCData_x                                              0xE80920
#define pinstSkillMgr_x                                            0xF33540
#define pinstSpawnManager_x                                        0xF31FE8
#define pinstSpellManager_x                                        0xF33760
#define pinstSpellSets_x                                           0xF27A24
#define pinstStringTable_x                                         0xE82B68
#define pinstSwitchManager_x                                       0xE80210
#define pinstTarget_x                                              0xE80444
#define pinstTargetObject_x                                        0xE80494
#define pinstTargetSwitch_x                                        0xE8091C
#define pinstTaskMember_x                                          0xDCDA44
#define pinstTrackTarget_x                                         0xE8044C
#define pinstTradeTarget_x                                         0xE80404
#define instTributeActive_x                                        0xDCDBD1
#define pinstViewActor_x                                           0xDCE4E8
#define pinstWorldData_x                                           0xE82B54
#define pinstZoneAddr_x                                            0xE905E0
#define pinstPlayerPath_x                                          0xF32080
#define pinstTargetIndicator_x                                     0xF339C8
#define EQObject_Top_x                                             0xE8036C
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDCDFA4
#define pinstCAchievementsWnd_x                                    0xDCDF88
#define pinstCActionsWnd_x                                         0xDCE008
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDCE4D0
#define pinstCAdvancedLootWnd_x                                    0xDCDFFC
#define pinstCAdventureLeaderboardWnd_x                            0x1049678
#define pinstCAdventureRequestWnd_x                                0x1049728
#define pinstCAdventureStatsWnd_x                                  0x10497D8
#define pinstCAggroMeterWnd_x                                      0xDCE52C
#define pinstCAlarmWnd_x                                           0xDCDD0C
#define pinstCAlertHistoryWnd_x                                    0xDCDF34
#define pinstCAlertStackWnd_x                                      0xDCE528
#define pinstCAlertWnd_x                                           0xDCE538
#define pinstCAltStorageWnd_x                                      0x1049B38
#define pinstCAudioTriggersWindow_x                                0xC816F0
#define pinstCAuraWnd_x                                            0xDCE520
#define pinstCAvaZoneWnd_x                                         0xDCDF38
#define pinstCBandolierWnd_x                                       0xDCE550
#define pinstCBankWnd_x                                            0xDCDF54
#define pinstCBarterMerchantWnd_x                                  0x104AD78
#define pinstCBarterSearchWnd_x                                    0x104AE28
#define pinstCBarterWnd_x                                          0x104AED8
#define pinstCBazaarConfirmationWnd_x                              0xDCE524
#define pinstCBazaarSearchWnd_x                                    0xDCE4A0
#define pinstCBazaarWnd_x                                          0xDCE574
#define pinstCBlockedBuffWnd_x                                     0xDCDF3C
#define pinstCBlockedPetBuffWnd_x                                  0xDCDF60
#define pinstCBodyTintWnd_x                                        0xDCE50C
#define pinstCBookWnd_x                                            0xDCE578
#define pinstCBreathWnd_x                                          0xDCDFB4
#define pinstCBuffWindowNORMAL_x                                   0xDCDF10
#define pinstCBuffWindowSHORT_x                                    0xDCDF14
#define pinstCBugReportWnd_x                                       0xDCDFA8
#define pinstCButtonWnd_x                                          0x16CBCA0
#define pinstCCastingWnd_x                                         0xDCDF9C
#define pinstCCastSpellWnd_x                                       0xDCE4BC
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDCDFB8
#define pinstCChatWindowManager_x                                  0x104B998
#define pinstCClaimWnd_x                                           0x104BAF0
#define pinstCColorPickerWnd_x                                     0xDCDFE0
#define pinstCCombatAbilityWnd_x                                   0xDCE530
#define pinstCCombatSkillsSelectWnd_x                              0xDCE000
#define pinstCCompassWnd_x                                         0xDCE4E0
#define pinstCConfirmationDialog_x                                 0x10509F0
#define pinstCContainerMgr_x                                       0xDCDFA0
#define pinstCContextMenuManager_x                                 0x16CB9F0
#define pinstCCursorAttachment_x                                   0xDCDF90
#define pinstCDynamicZoneWnd_x                                     0x104C0B8
#define pinstCEditLabelWnd_x                                       0xDCE58C
#define pinstCEQMainWnd_x                                          0x104C300
#define pinstCEventCalendarWnd_x                                   0xDCDFC0
#define pinstCExtendedTargetWnd_x                                  0xDCE518
#define pinstCFacePick_x                                           0xDCDFD8
#define pinstCFactionWnd_x                                         0xDCDF98
#define pinstCFellowshipWnd_x                                      0x104C500
#define pinstCFileSelectionWnd_x                                   0xDCDFEC
#define pinstCFindItemWnd_x                                        0xDCE594
#define pinstCFindLocationWnd_x                                    0x104C658
#define pinstCFriendsWnd_x                                         0xDCE494
#define pinstCGemsGameWnd_x                                        0xDCE570
#define pinstCGiveWnd_x                                            0xDCE598
#define pinstCGroupSearchFiltersWnd_x                              0xDCE540
#define pinstCGroupSearchWnd_x                                     0x104CA50
#define pinstCGroupWnd_x                                           0x104CB00
#define pinstCGuildBankWnd_x                                       0xE91424
#define pinstCGuildCreationWnd_x                                   0x104CC60
#define pinstCGuildMgmtWnd_x                                       0x104CD10
#define pinstCharacterCreation_x                                   0xDCE534
#define pinstCHelpWnd_x                                            0xDCE4D8
#define pinstCHeritageSelectionWnd_x                               0xDCDFE8
#define pinstCHotButtonWnd_x                                       0x104EE68
#define pinstCHotButtonWnd1_x                                      0x104EE68
#define pinstCHotButtonWnd2_x                                      0x104EE6C
#define pinstCHotButtonWnd3_x                                      0x104EE70
#define pinstCHotButtonWnd4_x                                      0x104EE74
#define pinstCIconSelectionWnd_x                                   0xDCDF74
#define pinstCInspectWnd_x                                         0xDCDF80
#define pinstCInventoryWnd_x                                       0xDCE560
#define pinstCInvSlotMgr_x                                         0xDCDF58
#define pinstCItemDisplayManager_x                                 0x104F3F8
#define pinstCItemExpTransferWnd_x                                 0x104F52C
#define pinstCItemOverflowWnd_x                                    0xDCE4A8
#define pinstCJournalCatWnd_x                                      0xDCE084
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDCDFD4
#define pinstCKeyRingWnd_x                                         0xDCDF2C
#define pinstCLargeDialogWnd_x                                     0x1051670
#define pinstCLayoutCopyWnd_x                                      0x104F878
#define pinstCLFGuildWnd_x                                         0x104F928
#define pinstCLoadskinWnd_x                                        0xDCE580
#define pinstCLootFiltersCopyWnd_x                                 0xC9D9B8
#define pinstCLootFiltersWnd_x                                     0xDCE564
#define pinstCLootSettingsWnd_x                                    0xDCE588
#define pinstCLootWnd_x                                            0xDCDFCC
#define pinstCMailAddressBookWnd_x                                 0xDCDF64
#define pinstCMailCompositionWnd_x                                 0xDCDF44
#define pinstCMailIgnoreListWnd_x                                  0xDCDF68
#define pinstCMailWnd_x                                            0xDCDF18
#define pinstCManageLootWnd_x                                      0xDCF3F0
#define pinstCMapToolbarWnd_x                                      0xDCE568
#define pinstCMapViewWnd_x                                         0xDCE548
#define pinstCMarketplaceWnd_x                                     0xDCDFC4
#define pinstCMerchantWnd_x                                        0xDCE07C
#define pinstCMIZoneSelectWnd_x                                    0x1050160
#define pinstCMusicPlayerWnd_x                                     0xDCDF20
#define pinstCNameChangeMercWnd_x                                  0xDCE4D4
#define pinstCNameChangePetWnd_x                                   0xDCE4C4
#define pinstCNameChangeWnd_x                                      0xDCDFB0
#define pinstCNoteWnd_x                                            0xDCE4CC
#define pinstCObjectPreviewWnd_x                                   0xDCDFE4
#define pinstCOptionsWnd_x                                         0xDCE56C
#define pinstCPetInfoWnd_x                                         0xDCDF48
#define pinstCPetitionQWnd_x                                       0xDCE498
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDCE508
#define pinstCPlayerWnd_x                                          0xDCE584
#define pinstCPopupWndManager_x                                    0x10509F0
#define pinstCProgressionSelectionWnd_x                            0x1050AA0
#define pinstCPurchaseGroupWnd_x                                   0xDCE48C
#define pinstCPurchaseWnd_x                                        0xDCDFF0
#define pinstCPvPLeaderboardWnd_x                                  0x1050B50
#define pinstCPvPStatsWnd_x                                        0x1050C00
#define pinstCQuantityWnd_x                                        0xDCDF7C
#define pinstCRaceChangeWnd_x                                      0xDCDFD0
#define pinstCRaidOptionsWnd_x                                     0xDCE544
#define pinstCRaidWnd_x                                            0xDCDF84
#define pinstCRealEstateItemsWnd_x                                 0xDCDF8C
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDCDFBC
#define pinstCRealEstateManageWnd_x                                0xDCE590
#define pinstCRealEstateNeighborhoodWnd_x                          0xDCDF24
#define pinstCRealEstatePlotSearchWnd_x                            0xDCDF4C
#define pinstCRealEstatePurchaseWnd_x                              0xDCDF6C
#define pinstCRespawnWnd_x                                         0xDCE53C
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDCE51C
#define pinstCSendMoneyWnd_x                                       0xDCDF1C
#define pinstCServerListWnd_x                                      0xDCDF30
#define pinstCSkillsSelectWnd_x                                    0xDCDFDC
#define pinstCSkillsWnd_x                                          0xDCDFC8
#define pinstCSocialEditWnd_x                                      0xDCDF94
#define pinstCSocialWnd_x                                          0xDCE510
#define pinstCSpellBookWnd_x                                       0xDCE514
#define pinstCStoryWnd_x                                           0xDCE4DC
#define pinstCTargetOfTargetWnd_x                                  0x1052A28
#define pinstCTargetWnd_x                                          0xDCDF40
#define pinstCTaskOverlayWnd_x                                     0xDCDF50
#define pinstCTaskSelectWnd_x                                      0x1052B80
#define pinstCTaskManager_x                                        0xC9E308
#define pinstCTaskTemplateSelectWnd_x                              0x1052C30
#define pinstCTaskWnd_x                                            0x1052CE0
#define pinstCTextEntryWnd_x                                       0xDCE4E4
#define pinstCTimeLeftWnd_x                                        0xDCDFF4
#define pinstCTipWndCONTEXT_x                                      0x1052EE4
#define pinstCTipWndOFDAY_x                                        0x1052EE0
#define pinstCTitleWnd_x                                           0x1052F90
#define pinstCTrackingWnd_x                                        0xDCDF5C
#define pinstCTradeskillWnd_x                                      0x10530F8
#define pinstCTradeWnd_x                                           0xDCE504
#define pinstCTrainWnd_x                                           0xDCDF78
#define pinstCTributeBenefitWnd_x                                  0x10532F8
#define pinstCTributeMasterWnd_x                                   0x10533A8
#define pinstCTributeTrophyWnd_x                                   0x1053458
#define pinstCVideoModesWnd_x                                      0xDCE54C
#define pinstCVoiceMacroWnd_x                                      0xF34130
#define pinstCVoteResultsWnd_x                                     0xDCE490
#define pinstCVoteWnd_x                                            0xDCDFF8
#define pinstCWebManager_x                                         0xF347AC
#define pinstCZoneGuideWnd_x                                       0xDCE59C
#define pinstCZonePathWnd_x                                        0xDCDF28

#define pinstEQSuiteTextureLoader_x                                0xC6C480
#define pinstItemIconCache_x                                       0x104C2B8
#define pinstLootFiltersManager_x                                  0xC9DA68
#define pinstRewardSelectionWnd_x                                  0x1051348

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC1CE00
#define __CastRay_x                                                0x59CD90
#define __CastRay2_x                                               0x59CDE0
#define __ConvertItemTags_x                                        0x5B85F0
#define __CrashHandler_x                                           0x852620
#define __CleanItemTags_x                                          0x477B90
#define __DoesFileExist_x                                          0x8F4F70
#define __EQGetTime_x                                              0x8F1980
#define __ExecuteCmd_x                                             0x595690
#define __FixHeading_x                                             0x981660
#define __GameLoop_x                                               0x6AA090
#define __get_bearing_x                                            0x59C8E0
#define __get_melee_range_x                                        0x59CFD0
#define __GetAnimationCache_x                                      0x70F0B0
#define __GetGaugeValueFromEQ_x                                    0x803BC0
#define __GetLabelFromEQ_x                                         0x8056B0
#define __GetXTargetType_x                                         0x9830C0
#define __HandleMouseWheel_x                                       0x6AAC80
#define __HeadingDiff_x                                            0x9816D0
#define __HelpPath_x                                               0xF2F4CC
#define __LoadFrontEnd_x                                           0x6A6B60
#define __NewUIINI_x                                               0x803890
#define __pCrashHandler_x                                          0x1070860
#define __ProcessGameEvents_x                                      0x5FCA00
#define __ProcessMouseEvent_x                                      0x5FC1C0
#define __SaveColors_x                                             0x545380
#define __STMLToText_x                                             0x924A90
#define __ToggleKeyRingItem_x                                      0x5089D0
#define CMemoryMappedFile__SetFile_x                               0xA5B8F0
#define CrashDetected_x                                            0x6A85C0
#define DrawNetStatus_x                                            0x628A50
#define Expansion_HoT_x                                            0xE9142C
#define Teleport_Table_Size_x                                      0xE80454
#define Teleport_Table_x                                           0xE80928
#define Util__FastTime_x                                           0x8F1540
#define wwsCrashReportCheckForUploader_x                           0x8535A0
#define wwsCrashReportPlatformLaunchUploader_x                     0x855C80

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48B9A0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x494870
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x494640
#define CAdvancedLootWnd__AddPlayerToList_x                        0x48EF20
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x48E370

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x54CF00
#define AltAdvManager__IsAbilityReady_x                            0x54BE50
#define AltAdvManager__GetAAById_x                                 0x54C050
#define AltAdvManager__CanTrainAbility_x                           0x54C0C0
#define AltAdvManager__CanSeeAbility_x                             0x54C420

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C7570
#define CharacterZoneClient__HasSkill_x                            0x4D2440
#define CharacterZoneClient__MakeMeVisible_x                       0x4D3B60
#define CharacterZoneClient__IsStackBlocked_x                      0x4BBC20
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B8370
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D6530
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D6610
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D66F0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C06D0
#define CharacterZoneClient__BardCastBard_x                        0x4C31A0
#define CharacterZoneClient__GetMaxEffects_x                       0x4B8440
#define CharacterZoneClient__GetEffect_x                           0x4B82B0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C1700
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C17D0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C1820
#define CharacterZoneClient__CalcAffectChange_x                    0x4C1970
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C1B50
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B00B0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D4AD0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D4540

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D09B0
#define CBankWnd__WndNotification_x                                0x6D0790

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6DE110

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x60B4A0
#define CButtonWnd__CButtonWnd_x                                   0x920E60

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6FE190
#define CChatManager__InitContextMenu_x                            0x6F74D0
#define CChatManager__FreeChatWindow_x                             0x6FCD10
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E5CD0
#define CChatManager__SetLockedActiveChatWindow_x                  0x6FDE10
#define CChatManager__CreateChatWindow_x                           0x6FD340

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E5D20

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x935580
#define CContextMenu__dCContextMenu_x                              0x9357B0
#define CContextMenu__AddMenuItem_x                                0x9357C0
#define CContextMenu__RemoveMenuItem_x                             0x935AD0
#define CContextMenu__RemoveAllMenuItems_x                         0x935AF0
#define CContextMenu__CheckMenuItem_x                              0x935B70
#define CContextMenu__SetMenuItem_x                                0x9359F0
#define CContextMenu__AddSeparator_x                               0x935950

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x936110
#define CContextMenuManager__RemoveMenu_x                          0x936180
#define CContextMenuManager__PopupMenu_x                           0x936240
#define CContextMenuManager__Flush_x                               0x9360B0
#define CContextMenuManager__GetMenu_x                             0x4969B0
#define CContextMenuManager__CreateDefaultMenu_x                   0x709890

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D1F30
#define CChatService__GetFriendName_x                              0x8D1F40

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6FE9E0
#define CChatWindow__Clear_x                                       0x6FFC80
#define CChatWindow__WndNotification_x                             0x700410
#define CChatWindow__AddHistory_x                                  0x6FF550

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x932A00
#define CComboWnd__Draw_x                                          0x931EE0
#define CComboWnd__GetCurChoice_x                                  0x932840
#define CComboWnd__GetListRect_x                                   0x9323A0
#define CComboWnd__GetTextRect_x                                   0x932A70
#define CComboWnd__InsertChoice_x                                  0x932530
#define CComboWnd__SetColors_x                                     0x932500
#define CComboWnd__SetChoice_x                                     0x932810
#define CComboWnd__GetItemCount_x                                  0x932850
#define CComboWnd__GetCurChoiceText_x                              0x932890
#define CComboWnd__GetChoiceText_x                                 0x932860
#define CComboWnd__InsertChoiceAtIndex_x                           0x9325D0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x707270
#define CContainerWnd__vftable_x                                   0xAE06F0
#define CContainerWnd__SetContainer_x                              0x7087E0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x545140
#define CDisplay__GetClickedActor_x                                0x538100
#define CDisplay__GetUserDefinedColor_x                            0x5307E0
#define CDisplay__GetWorldFilePath_x                               0x539B50
#define CDisplay__is3dON_x                                         0x534DD0
#define CDisplay__ReloadUI_x                                       0x53F270
#define CDisplay__WriteTextHD2_x                                   0x534BB0
#define CDisplay__TrueDistance_x                                   0x53B7B0
#define CDisplay__SetViewActor_x                                   0x537A50
#define CDisplay__GetFloorHeight_x                                 0x534E90
#define CDisplay__SetRenderWindow_x                                0x5337C0
#define CDisplay__ToggleScreenshotMode_x                           0x537520

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x955020

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x938AF0
#define CEditWnd__GetCharIndexPt_x                                 0x9399E0
#define CEditWnd__GetDisplayString_x                               0x939880
#define CEditWnd__GetHorzOffset_x                                  0x938130
#define CEditWnd__GetLineForPrintableChar_x                        0x93ABB0
#define CEditWnd__GetSelStartPt_x                                  0x939C90
#define CEditWnd__GetSTMLSafeText_x                                0x9396A0
#define CEditWnd__PointFromPrintableChar_x                         0x93A7F0
#define CEditWnd__SelectableCharFromPoint_x                        0x93A960
#define CEditWnd__SetEditable_x                                    0x939D50
#define CEditWnd__SetWindowTextA_x                                 0x939420

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5EA6F0
#define CEverQuest__ClickedPlayer_x                                0x5DC7C0
#define CEverQuest__CreateTargetIndicator_x                        0x5F9CB0
#define CEverQuest__DeleteTargetIndicator_x                        0x5F9D40
#define CEverQuest__DoTellWindow_x                                 0x4E5E00
#define CEverQuest__OutputTextToLog_x                              0x4E6030
#define CEverQuest__DropHeldItemOnGround_x                         0x5D1800
#define CEverQuest__dsp_chat_x                                     0x4E63C0
#define CEverQuest__trimName_x                                     0x5F5F90
#define CEverQuest__Emote_x                                        0x5EAF00
#define CEverQuest__EnterZone_x                                    0x5E4EE0
#define CEverQuest__GetBodyTypeDesc_x                              0x5EF840
#define CEverQuest__GetClassDesc_x                                 0x5EFE80
#define CEverQuest__GetClassThreeLetterCode_x                      0x5F0480
#define CEverQuest__GetDeityDesc_x                                 0x5F8600
#define CEverQuest__GetLangDesc_x                                  0x5F0640
#define CEverQuest__GetRaceDesc_x                                  0x5EFE60
#define CEverQuest__InterpretCmd_x                                 0x5F8BD0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5D59F0
#define CEverQuest__LMouseUp_x                                     0x5D3D70
#define CEverQuest__RightClickedOnPlayer_x                         0x5D62D0
#define CEverQuest__RMouseUp_x                                     0x5D4D00
#define CEverQuest__SetGameState_x                                 0x5D1590
#define CEverQuest__UPCNotificationFlush_x                         0x5F5E90
#define CEverQuest__IssuePetCommand_x                              0x5F1A40
#define CEverQuest__ReportSuccessfulHit_x                          0x5EC300

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x719430
#define CGaugeWnd__CalcLinesFillRect_x                             0x719490
#define CGaugeWnd__Draw_x                                          0x718A80

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ACD30
#define CGuild__GetGuildName_x                                     0x4ABE10
#define CGuild__GetGuildIndex_x                                    0x4AC1A0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x7347D0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x60B860

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x7417F0
#define CInvSlotMgr__MoveItem_x                                    0x740510
#define CInvSlotMgr__SelectSlot_x                                  0x7418C0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x73EDC0
#define CInvSlot__SliderComplete_x                                 0x73CB20
#define CInvSlot__GetItemBase_x                                    0x73C4A0
#define CInvSlot__UpdateItem_x                                     0x73C610

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x743320
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7424D0
#define CInvSlotWnd__HandleLButtonUp_x                             0x742EA0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7FFE20
#define CItemDisplayWnd__UpdateStrings_x                           0x751950
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x74B6C0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x74BBF0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x751F60
#define CItemDisplayWnd__AboutToShow_x                             0x751590
#define CItemDisplayWnd__WndNotification_x                         0x753470
#define CItemDisplayWnd__RequestConvertItem_x                      0x752F30
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x750600
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x7513B0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x837C10

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x757560

// CLabel 
#define CLabel__Draw_x                                             0x75CFE0

// CListWnd
#define CListWnd__CListWnd_x                                       0x90B320
#define CListWnd__dCListWnd_x                                      0x90B640
#define CListWnd__AddColumn_x                                      0x90F980
#define CListWnd__AddColumn1_x                                     0x90F9D0
#define CListWnd__AddLine_x                                        0x90FD60
#define CListWnd__AddString_x                                      0x90FB60
#define CListWnd__CalculateFirstVisibleLine_x                      0x90F740
#define CListWnd__CalculateVSBRange_x                              0x90F520
#define CListWnd__ClearSel_x                                       0x910540
#define CListWnd__ClearAllSel_x                                    0x9105A0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x910FC0
#define CListWnd__Compare_x                                        0x90EE60
#define CListWnd__Draw_x                                           0x90B740
#define CListWnd__DrawColumnSeparators_x                           0x90DF30
#define CListWnd__DrawHeader_x                                     0x90E3A0
#define CListWnd__DrawItem_x                                       0x90E7A0
#define CListWnd__DrawLine_x                                       0x90E0A0
#define CListWnd__DrawSeparator_x                                  0x90DFD0
#define CListWnd__EnableLine_x                                     0x90D800
#define CListWnd__EnsureVisible_x                                  0x910EE0
#define CListWnd__ExtendSel_x                                      0x910470
#define CListWnd__GetColumnTooltip_x                               0x90D340
#define CListWnd__GetColumnMinWidth_x                              0x90D3B0
#define CListWnd__GetColumnWidth_x                                 0x90D2B0
#define CListWnd__GetCurSel_x                                      0x90CC40
#define CListWnd__GetItemAtPoint_x                                 0x90DA80
#define CListWnd__GetItemAtPoint1_x                                0x90DAF0
#define CListWnd__GetItemData_x                                    0x90CCC0
#define CListWnd__GetItemHeight_x                                  0x90D080
#define CListWnd__GetItemIcon_x                                    0x90CE50
#define CListWnd__GetItemRect_x                                    0x90D8F0
#define CListWnd__GetItemText_x                                    0x90CD00
#define CListWnd__GetSelList_x                                     0x9105F0
#define CListWnd__GetSeparatorRect_x                               0x90DD30
#define CListWnd__InsertLine_x                                     0x910150
#define CListWnd__RemoveLine_x                                     0x9102A0
#define CListWnd__SetColors_x                                      0x90F4F0
#define CListWnd__SetColumnJustification_x                         0x90F220
#define CListWnd__SetColumnWidth_x                                 0x90F140
#define CListWnd__SetCurSel_x                                      0x9103B0
#define CListWnd__SetItemColor_x                                   0x910B90
#define CListWnd__SetItemData_x                                    0x910B50
#define CListWnd__SetItemText_x                                    0x910760
#define CListWnd__ShiftColumnSeparator_x                           0x90F2E0
#define CListWnd__Sort_x                                           0x90EFE0
#define CListWnd__ToggleSel_x                                      0x9103E0
#define CListWnd__SetColumnsSizable_x                              0x90F380
#define CListWnd__SetItemWnd_x                                     0x910A10
#define CListWnd__GetItemWnd_x                                     0x90CEA0
#define CListWnd__SetItemIcon_x                                    0x9107E0
#define CListWnd__CalculateCustomWindowPositions_x                 0x90F840
#define CListWnd__SetVScrollPos_x                                  0x90F120

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x772750
#define CMapViewWnd__GetWorldCoordinates_x                         0x770E60
#define CMapViewWnd__HandleLButtonDown_x                           0x76DEC0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x795760
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x796040
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x796580
#define CMerchantWnd__SelectRecoverySlot_x                         0x799510
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7942A0
#define CMerchantWnd__SelectBuySellSlot_x                          0x79F0F0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x795370

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89FB70
#define CPacketScrambler__hton_x                                   0x89FB60

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x92A030
#define CSidlManager__FindScreenPieceTemplate_x                    0x92A440
#define CSidlManager__FindScreenPieceTemplate1_x                   0x92A230
#define CSidlManager__CreateLabel_x                                0x7F7370
#define CSidlManager__CreateXWndFromTemplate_x                     0x92D3E0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x92D5C0
#define CSidlManager__CreateXWnd_x                                 0x7F72A0
#define CSidlManager__CreateHotButtonWnd_x                         0x7F7860

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x926BE0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x926AE0
#define CSidlScreenWnd__ConvertToRes_x                             0x94BFE0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x926570
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x926260
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x926330
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x926400
#define CSidlScreenWnd__DrawSidlPiece_x                            0x927080
#define CSidlScreenWnd__EnableIniStorage_x                         0x927550
#define CSidlScreenWnd__GetSidlPiece_x                             0x927270
#define CSidlScreenWnd__Init1_x                                    0x925E60
#define CSidlScreenWnd__LoadIniInfo_x                              0x9275A0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9280A0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x925270
#define CSidlScreenWnd__StoreIniInfo_x                             0x927C30
#define CSidlScreenWnd__StoreIniVis_x                              0x927F80
#define CSidlScreenWnd__WndNotification_x                          0x926F90
#define CSidlScreenWnd__GetChildItem_x                             0x9274D0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x916D90
#define CSidlScreenWnd__m_layoutCopy_x                             0x16CB8C0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6701C0
#define CSkillMgr__GetSkillCap_x                                   0x6703A0
#define CSkillMgr__GetNameToken_x                                  0x66F950
#define CSkillMgr__IsActivatedSkill_x                              0x66FA90
#define CSkillMgr__IsCombatSkill_x                                 0x66F9D0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x936F00
#define CSliderWnd__SetValue_x                                     0x936D70
#define CSliderWnd__SetNumTicks_x                                  0x936DD0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7FD370

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x93F710
#define CStmlWnd__CalculateHSBRange_x                              0x940800
#define CStmlWnd__CalculateVSBRange_x                              0x940770
#define CStmlWnd__CanBreakAtCharacter_x                            0x944B40
#define CStmlWnd__FastForwardToEndOfTag_x                          0x9457D0
#define CStmlWnd__ForceParseNow_x                                  0x93FCB0
#define CStmlWnd__GetNextTagPiece_x                                0x944AA0
#define CStmlWnd__GetSTMLText_x                                    0x4F8030
#define CStmlWnd__GetVisibleText_x                                 0x93FCD0
#define CStmlWnd__InitializeWindowVariables_x                      0x945620
#define CStmlWnd__MakeStmlColorTag_x                               0x93EDF0
#define CStmlWnd__MakeWndNotificationTag_x                         0x93EE60
#define CStmlWnd__SetSTMLText_x                                    0x93DEA0
#define CStmlWnd__StripFirstSTMLLines_x                            0x9468D0
#define CStmlWnd__UpdateHistoryString_x                            0x9459E0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x93CF90
#define CTabWnd__DrawCurrentPage_x                                 0x93D670
#define CTabWnd__DrawTab_x                                         0x93D390
#define CTabWnd__GetCurrentPage_x                                  0x93C790
#define CTabWnd__GetPageInnerRect_x                                0x93C9D0
#define CTabWnd__GetTabInnerRect_x                                 0x93C910
#define CTabWnd__GetTabRect_x                                      0x93C7C0
#define CTabWnd__InsertPage_x                                      0x93CBE0
#define CTabWnd__SetPage_x                                         0x93CA50
#define CTabWnd__SetPageRect_x                                     0x93CED0
#define CTabWnd__UpdatePage_x                                      0x93D250
#define CTabWnd__GetPageFromTabIndex_x                             0x93D2D0
#define CTabWnd__GetCurrentTabIndex_x                              0x93C780

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x7579A0
#define CPageWnd__SetTabText_x                                     0x93C2D0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A6940

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x913C10
#define CTextureFont__GetTextExtent_x                              0x913DD0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6A3B90
#define CHtmlComponentWnd__ValidateUri_x                           0x7361C0
#define CHtmlWnd__SetClientCallbacks_x                             0x6108E0
#define CHtmlWnd__AddObserver_x                                    0x610900
#define CHtmlWnd__RemoveObserver_x                                 0x610960
#define Window__getProgress_x                                      0x850280
#define Window__getStatus_x                                        0x8502A0
#define Window__getURI_x                                           0x8502B0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x951A50

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x900F50

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4AE090
#define CXStr__CXStr1_x                                            0x4F2FF0
#define CXStr__CXStr3_x                                            0x8EDAB0
#define CXStr__dCXStr_x                                            0x473110
#define CXStr__operator_equal_x                                    0x8EDCE0
#define CXStr__operator_equal1_x                                   0x8EDD20
#define CXStr__operator_plus_equal1_x                              0x8EE7B0
#define CXStr__SetString_x                                         0x8F06A0
#define CXStr__operator_char_p_x                                   0x8EE220
#define CXStr__GetChar_x                                           0x8EFFF0
#define CXStr__Delete_x                                            0x8EF8A0
#define CXStr__GetUnicode_x                                        0x8F0060
#define CXStr__GetLength_x                                         0x477EB0
#define CXStr__Mid_x                                               0x477EC0
#define CXStr__Insert_x                                            0x8F00C0
#define CXStr__FindNext_x                                          0x8EFD10

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x935190
#define CXWnd__BringToTop_x                                        0x91A4B0
#define CXWnd__Center_x                                            0x91A030
#define CXWnd__ClrFocus_x                                          0x919E70
#define CXWnd__Destroy_x                                           0x919F10
#define CXWnd__DoAllDrawing_x                                      0x916520
#define CXWnd__DrawChildren_x                                      0x9164F0
#define CXWnd__DrawColoredRect_x                                   0x916980
#define CXWnd__DrawTooltip_x                                       0x915060
#define CXWnd__DrawTooltipAtPoint_x                                0x915120
#define CXWnd__GetBorderFrame_x                                    0x9167E0
#define CXWnd__GetChildWndAt_x                                     0x91A550
#define CXWnd__GetClientClipRect_x                                 0x9187C0
#define CXWnd__GetScreenClipRect_x                                 0x918890
#define CXWnd__GetScreenRect_x                                     0x918A60
#define CXWnd__GetTooltipRect_x                                    0x9169D0
#define CXWnd__GetWindowTextA_x                                    0x4980A0
#define CXWnd__IsActive_x                                          0x917100
#define CXWnd__IsDescendantOf_x                                    0x919430
#define CXWnd__IsReallyVisible_x                                   0x919460
#define CXWnd__IsType_x                                            0x91ABB0
#define CXWnd__Move_x                                              0x9194D0
#define CXWnd__Move1_x                                             0x919580
#define CXWnd__ProcessTransition_x                                 0x919FE0
#define CXWnd__Refade_x                                            0x919820
#define CXWnd__Resize_x                                            0x919AA0
#define CXWnd__Right_x                                             0x91A270
#define CXWnd__SetFocus_x                                          0x919E30
#define CXWnd__SetFont_x                                           0x919EA0
#define CXWnd__SetKeyTooltip_x                                     0x91A9D0
#define CXWnd__SetMouseOver_x                                      0x917910
#define CXWnd__StartFade_x                                         0x919300
#define CXWnd__GetChildItem_x                                      0x91A6C0
#define CXWnd__SetParent_x                                         0x9191C0
#define CXWnd__Minimize_x                                          0x919B10

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x94D070

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x91D3F0
#define CXWndManager__DrawWindows_x                                0x91D410
#define CXWndManager__GetKeyboardFlags_x                           0x91FAB0
#define CXWndManager__HandleKeyboardMsg_x                          0x91F6B0
#define CXWndManager__RemoveWnd_x                                  0x91FD00
#define CXWndManager__RemovePendingDeletionWnd_x                   0x920260

// CDBStr
#define CDBStr__GetString_x                                        0x52F7B0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B9350
#define EQ_Character__Cur_HP_x                                     0x4CF420
#define EQ_Character__Cur_Mana_x                                   0x4D6BF0
#define EQ_Character__GetCastingTimeModifier_x                     0x4BC270
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AFCF0
#define EQ_Character__GetFocusRangeModifier_x                      0x4AFE40
#define EQ_Character__GetHPRegen_x                                 0x4DCA20
#define EQ_Character__GetEnduranceRegen_x                          0x4DD030
#define EQ_Character__GetManaRegen_x                               0x4DD470
#define EQ_Character__Max_Endurance_x                              0x6364A0
#define EQ_Character__Max_HP_x                                     0x4CF250
#define EQ_Character__Max_Mana_x                                   0x6362A0
#define EQ_Character__doCombatAbility_x                            0x638960
#define EQ_Character__UseSkill_x                                   0x4DF280
#define EQ_Character__GetConLevel_x                                0x62F9D0
#define EQ_Character__IsExpansionFlag_x                            0x593E50
#define EQ_Character__TotalEffect_x                                0x4C28E0
#define EQ_Character__GetPCSpellAffect_x                           0x4BCE60
#define EQ_Character__SpellDuration_x                              0x4BC990
#define EQ_Character__GetAdjustedSkill_x                           0x4D2200
#define EQ_Character__GetBaseSkill_x                               0x4D31A0
#define EQ_Character__CanUseItem_x                                 0x4D6F00

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BED80

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x64CAC0

//PcClient
#define PcClient__PcClient_x                                       0x62D110

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6FC0
#define CCharacterListWnd__EnterWorld_x                            0x4B6A00
#define CCharacterListWnd__Quit_x                                  0x4B6710
#define CCharacterListWnd__UpdateList_x                            0x4B6B90

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x611B10
#define EQ_Item__CreateItemTagString_x                             0x8994A0
#define EQ_Item__IsStackable_x                                     0x89DEC0
#define EQ_Item__GetImageNum_x                                     0x89AEE0
#define EQ_Item__CreateItemClient_x                                0x610CE0
#define EQ_Item__GetItemValue_x                                    0x89C160
#define EQ_Item__ValueSellMerchant_x                               0x89F710
#define EQ_Item__IsKeyRingItem_x                                   0x89D820
#define EQ_Item__CanGoInBag_x                                      0x611C30
#define EQ_Item__IsEmpty_x                                         0x89D330
#define EQ_Item__GetMaxItemCount_x                                 0x89C520
#define EQ_Item__GetHeldItem_x                                     0x89ADB0
#define EQ_Item__GetAugmentFitBySlot_x                             0x898DF0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x54DBF0
#define EQ_LoadingS__Array_x                                       0xBF4600

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x636E00
#define EQ_PC__GetAlternateAbilityId_x                             0x8A8800
#define EQ_PC__GetCombatAbility_x                                  0x8A8E70
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A8EE0
#define EQ_PC__GetItemRecastTimer_x                                0x638EE0
#define EQ_PC__HasLoreItem_x                                       0x6301E0
#define EQ_PC__AlertInventoryChanged_x                             0x62F310
#define EQ_PC__GetPcZoneClient_x                                   0x65B3A0
#define EQ_PC__RemoveMyAffect_x                                    0x63C100
#define EQ_PC__GetKeyRingItems_x                                   0x8A9780
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A9500
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A9A70

// EQItemList 
#define EQItemList__EQItemList_x                                   0x59A3B0
#define EQItemList__add_object_x                                   0x5C6F10
#define EQItemList__add_item_x                                     0x59A900
#define EQItemList__delete_item_x                                  0x59A950
#define EQItemList__FreeItemList_x                                 0x59A850

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x52D2E0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x64E340
#define EQPlayer__dEQPlayer_x                                      0x641630
#define EQPlayer__DoAttack_x                                       0x656050
#define EQPlayer__EQPlayer_x                                       0x641CF0
#define EQPlayer__SetNameSpriteState_x                             0x645FC0
#define EQPlayer__SetNameSpriteTint_x                              0x646E90
#define PlayerBase__HasProperty_j_x                                0x97FA40
#define EQPlayer__IsTargetable_x                                   0x97FEE0
#define EQPlayer__CanSee_x                                         0x97FD40
#define EQPlayer__CanSee1_x                                        0x97FE10
#define PlayerBase__GetVisibilityLineSegment_x                     0x97FB00

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x658E30
#define PlayerZoneClient__GetLevel_x                               0x65B3E0
#define PlayerZoneClient__IsValidTeleport_x                        0x5C8080
#define PlayerZoneClient__LegalPlayerRace_x                        0x546F90

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x651090
#define EQPlayerManager__GetSpawnByName_x                          0x651140
#define EQPlayerManager__GetPlayerFromPartialName_x                0x6511D0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x615320
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x6153A0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x6153E0
#define KeypressHandler__ClearCommandStateArray_x                  0x6167F0
#define KeypressHandler__HandleKeyDown_x                           0x616810
#define KeypressHandler__HandleKeyUp_x                             0x6168B0
#define KeypressHandler__SaveKeymapping_x                          0x616CE0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x76E5E0
#define MapViewMap__SaveEx_x                                       0x771980
#define MapViewMap__SetZoom_x                                      0x776050

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BCC70

// StringTable 
#define StringTable__getString_x                                   0x8B7AD0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x63BD70
#define PcZoneClient__RemovePetEffect_x                            0x63C3A0
#define PcZoneClient__HasAlternateAbility_x                        0x6360E0
#define PcZoneClient__GetCurrentMod_x                              0x4E2370
#define PcZoneClient__GetModCap_x                                  0x4E2270
#define PcZoneClient__CanEquipItem_x                               0x636790
#define PcZoneClient__GetItemByID_x                                0x639350
#define PcZoneClient__GetItemByItemClass_x                         0x6394A0
#define PcZoneClient__RemoveBuffEffect_x                           0x63C3C0
#define PcZoneClient__BandolierSwap_x                              0x6373C0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x638E80

//Doors
#define EQSwitch__UseSwitch_x                                      0x5CCCE0

//IconCache
#define IconCache__GetIcon_x                                       0x70E940

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x706410
#define CContainerMgr__CloseContainer_x                            0x7066E0
#define CContainerMgr__OpenExperimentContainer_x                   0x707160

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7C9950

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x609C80

//CLootWnd
#define CLootWnd__LootAll_x                                        0x764A00
#define CLootWnd__RequestLootSlot_x                                0x763D60

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x566130
#define EQ_Spell__SpellAffects_x                                   0x5665A0
#define EQ_Spell__SpellAffectBase_x                                0x566360
#define EQ_Spell__IsStackable_x                                    0x4C6EA0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C6D80
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B42E0
#define EQ_Spell__IsSPAStacking_x                                  0x5673D0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x5668F0
#define EQ_Spell__IsNoRemove_x                                     0x4C6E80
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x5673E0
#define __IsResEffectSpell_x                                       0x4C6290

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AAA40

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C7370

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x80F680
#define CTargetWnd__WndNotification_x                              0x80EF10
#define CTargetWnd__RefreshTargetBuffs_x                           0x80F1E0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x80E070

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x813D60

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x52AE30
#define CTaskManager__HandleMessage_x                              0x529560

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5616C0
#define EqSoundManager__PlayScriptMp3_x                            0x561820
#define EqSoundManager__SoundAssistPlay_x                          0x674160
#define EqSoundManager__WaveInstancePlay_x                         0x6736D0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x51EEF0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x93B7D0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x5555A0
#define CAltAbilityData__GetMercMaxRank_x                          0x555540
#define CAltAbilityData__GetMaxRank_x                              0x54AD00

//CTargetRing
#define CTargetRing__Cast_x                                        0x607D90

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C6D60
#define CharacterBase__CreateItemGlobalIndex_x                     0x504C70
#define CharacterBase__CreateItemIndex_x                           0x60FEA0
#define CharacterBase__GetItemPossession_x                         0x4F0B30
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CF9B0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CFA10
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6ED860
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6EE090
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6EE140

//messages
#define msg_spell_worn_off_x                                       0x58BF00
#define msg_new_text_x                                             0x580D10
#define __msgTokenTextParam_x                                      0x58E430
#define msgTokenText_x                                             0x58E680

//SpellManager
#define SpellManager__vftable_x                                    0xABAC80
#define SpellManager__SpellManager_x                               0x677480
#define Spellmanager__LoadTextSpells_x                             0x677D50
#define SpellManager__GetSpellByGroupAndRank_x                     0x677650

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9839B0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x505380
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x592240
#define ItemGlobalIndex__IsEquippedLocation_x                      0x6288B0
#define ItemGlobalIndex__IsValidIndex_x                            0x5053E0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C7CB0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C7F30

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x75D320

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x70AB40
#define CCursorAttachment__AttachToCursor1_x                       0x70AB80
#define CCursorAttachment__Deactivate_x                            0x70BB50

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x92E400
#define CSidlManagerBase__CreatePageWnd_x                          0x92DC10
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x929E50
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x929DE0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x94B560
#define CEQSuiteTextureLoader__GetTexture_x                        0x94B220

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x502210
#define CFindItemWnd__WndNotification_x                            0x502CF0
#define CFindItemWnd__Update_x                                     0x503830
#define CFindItemWnd__PickupSelectedItem_x                         0x501A70

//IString
#define IString__Append_x                                          0x4F2120

//Camera
#define CDisplay__cameraType_x                                     0xDCDD08
#define EverQuest__Cameras_x                                       0xE91770

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x50ACD0
#define LootFiltersManager__GetItemFilterData_x                    0x50A5C0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x50A5F0
#define LootFiltersManager__SetItemLootFilter_x                    0x50A810

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B7890

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x989680
#define CResolutionHandler__GetWindowedStyle_x                     0x66EBD0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x703130

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8DA640
#define CDistillerInfo__Instance_x                                 0x8DA5E0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x723580
#define CGroupWnd__UpdateDisplay_x                                 0x7228E0

//ItemBase
#define ItemBase__IsLore_x                                         0x89D880
#define ItemBase__IsLoreEquipped_x                                 0x89D8F0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5C6E70
#define EQPlacedItemManager__GetItemByGuid_x                       0x5C6FB0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5C7010

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x663EF0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x6678D0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x4F86B0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4E77E0
#define FactionManagerClient__HandleFactionMessage_x               0x4E7E50
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4E8480
#define FactionManagerClient__GetMaxFaction_x                      0x4E84D0
#define FactionManagerClient__GetMinFaction_x                      0x4E8450

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4F0B00

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x912C70

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x4973C0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4F0D60

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x554A80

//CTargetManager
#define CTargetManager__Get_x                                      0x67ACE0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x663EF0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A6700

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x59A7F0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF2EE00

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
