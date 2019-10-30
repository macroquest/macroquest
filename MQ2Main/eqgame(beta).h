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
#if defined(EQBETA)
#include "eqgame-private(beta).h"
#endif
#endif

#define __ClientName                                              "eqgame"
#define __ExpectedVersionDate                                     "Oct 30 2019"
#define __ExpectedVersionTime                                     "04:42:14"
#define __ActualVersionDate_x                                      0xB00DE8
#define __ActualVersionTime_x                                      0xB00DDC
#define __ActualVersionBuild_x                                     0xAECACC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x629160
#define __MemChecker1_x                                            0x8FB130
#define __MemChecker2_x                                            0x6B7400
#define __MemChecker3_x                                            0x6B7350
#define __MemChecker4_x                                            0x852EC0
#define __EncryptPad0_x                                            0xC363E8
#define __EncryptPad1_x                                            0xC945A8
#define __EncryptPad2_x                                            0xC46C80
#define __EncryptPad3_x                                            0xC46880
#define __EncryptPad4_x                                            0xC84C00
#define __EncryptPad5_x                                            0xF5DCE4
#define __AC1_x                                                    0x80F9A6
#define __AC2_x                                                    0x5E2EAF
#define __AC3_x                                                    0x5EA5AF
#define __AC4_x                                                    0x5EE580
#define __AC5_x                                                    0x5F488F
#define __AC6_x                                                    0x5F8EA6
#define __AC7_x                                                    0x5E2920
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1B2728

// Direct Input
#define DI8__Main_x                                                0xF601C0
#define DI8__Keyboard_x                                            0xF601C4
#define DI8__Mouse_x                                               0xF601D8
#define DI8__Mouse_Copy_x                                          0xEB93AC
#define DI8__Mouse_Check_x                                         0xF5DD0C
#define __AutoSkillArray_x                                         0xEBA2C4
#define __Attack_x                                                 0xF580EB
#define __Autofire_x                                               0xF580EC
#define __BindList_x                                               0xC24E20
#define g_eqCommandStates_x                                        0xC25BA0
#define __Clicks_x                                                 0xEB9464
#define __CommandList_x                                            0xC26760
#define __CurrentMapLabel_x                                        0xF70B6C
#define __CurrentSocial_x                                          0xC0E7CC
#define __DoAbilityList_x                                          0xEEFC0C
#define __do_loot_x                                                0x5AF120
#define __DrawHandler_x                                            0x15EFEE0
#define __GroupCount_x                                             0xEABC5A
#define __Guilds_x                                                 0xEAFBB8
#define __gWorld_x                                                 0xEABB28
#define __HWnd_x                                                   0xF601DC
#define __heqmain_x                                                0xF601B4
#define __InChatMode_x                                             0xEB9394
#define __LastTell_x                                               0xEBB308
#define __LMouseHeldTime_x                                         0xEB94D0
#define __Mouse_x                                                  0xF601A0
#define __MouseLook_x                                              0xEB942A
#define __MouseEventTime_x                                         0xF58BCC
#define __gpbCommandEvent_x                                        0xEABE50
#define __NetStatusToggle_x                                        0xEB942D
#define __PCNames_x                                                0xEBA8B4
#define __RangeAttackReady_x                                       0xEBA5A8
#define __RMouseHeldTime_x                                         0xEB94CC
#define __RunWalkState_x                                           0xEB9398
#define __ScreenMode_x                                             0xDF7454
#define __ScreenX_x                                                0xEB934C
#define __ScreenY_x                                                0xEB9348
#define __ScreenXMax_x                                             0xEB9350
#define __ScreenYMax_x                                             0xEB9354
#define __ServerHost_x                                             0xEA97E3
#define __ServerName_x                                             0xEEFBCC
#define __ShiftKeyDown_x                                           0xEB9A24
#define __ShowNames_x                                              0xEBA764
#define __Socials_x                                                0xEEFCCC
#define __SubscriptionType_x                                       0xFB5070
#define __TargetAggroHolder_x                                      0xF73520
#define __ZoneType_x                                               0xEB9828
#define __GroupAggro_x                                             0xF73560
#define __LoginName_x                                              0xF6091C
#define __Inviter_x                                                0xF58068
#define __AttackOnAssist_x                                         0xEBA720
#define __UseTellWindows_x                                         0xEBAA50
#define __gfMaxZoomCameraDistance_x                                0xAF6740
#define __gfMaxCameraDistance_x                                    0xB22CA0
#define __pulAutoRun_x                                             0xEB9448
#define __pulForward_x                                             0xEBAA88
#define __pulBackward_x                                            0xEBAA8C
#define __pulTurnRight_x                                           0xEBAA90
#define __pulTurnLeft_x                                            0xEBAA94
#define __pulStrafeLeft_x                                          0xEBAA98
#define __pulStrafeRight_x                                         0xEBAA9C

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEABF50
#define instEQZoneInfo_x                                           0xEB9620
#define pinstActiveBanker_x                                        0xEABE68
#define pinstActiveCorpse_x                                        0xEABE60
#define pinstActiveGMaster_x                                       0xEABE64
#define pinstActiveMerchant_x                                      0xEABE5C
#define pinstAltAdvManager_x                                       0xDF8188
#define pinstBandageTarget_x                                       0xEABE78
#define pinstCamActor_x                                            0xDF7444
#define pinstCDBStr_x                                              0xDF6EA4
#define pinstCDisplay_x                                            0xEABB0C
#define pinstCEverQuest_x                                          0xF601E0
#define pinstEverQuestInfo_x                                       0xEB9340
#define pinstCharData_x                                            0xEABC3C
#define pinstCharSpawn_x                                           0xEABF34
#define pinstControlledMissile_x                                   0xEA9AF4
#define pinstControlledPlayer_x                                    0xEABF34
#define pinstCResolutionHandler_x                                  0x15F0110
#define pinstCSidlManager_x                                        0x15EF0A8
#define pinstCXWndManager_x                                        0x15EF0A4
#define instDynamicZone_x                                          0xEAFA90
#define pinstDZMember_x                                            0xEAFBA0
#define pinstDZTimerInfo_x                                         0xEAFBA4
#define pinstEqLogin_x                                             0xF60268
#define instEQMisc_x                                               0xDF6DE8
#define pinstEQSoundManager_x                                      0xDF9158
#define pinstEQSpellStrings_x                                      0xCB9868
#define instExpeditionLeader_x                                     0xEAFADA
#define instExpeditionName_x                                       0xEAFB1A
#define pinstGroup_x                                               0xEABC56
#define pinstImeManager_x                                          0x15EF0A0
#define pinstLocalPlayer_x                                         0xEABE58
#define pinstMercenaryData_x                                       0xF5A6BC
#define pinstMercenaryStats_x                                      0xF7366C
#define pinstModelPlayer_x                                         0xEABE70
#define pinstPCData_x                                              0xEABC3C
#define pinstSkillMgr_x                                            0xF5C828
#define pinstSpawnManager_x                                        0xF5B2D0
#define pinstSpellManager_x                                        0xF5CA48
#define pinstSpellSets_x                                           0xF50D14
#define pinstStringTable_x                                         0xEABC40
#define pinstSwitchManager_x                                       0xEA94F0
#define pinstTarget_x                                              0xEABF30
#define pinstTargetObject_x                                        0xEA9640
#define pinstTargetSwitch_x                                        0xEABB04
#define pinstTaskMember_x                                          0xDF6C78
#define pinstTrackTarget_x                                         0xEABF3C
#define pinstTradeTarget_x                                         0xEABE6C
#define instTributeActive_x                                        0xDF6E09
#define pinstViewActor_x                                           0xDF7440
#define pinstWorldData_x                                           0xEABB00
#define pinstZoneAddr_x                                            0xEB98C0
#define pinstPlayerPath_x                                          0xF5B368
#define pinstTargetIndicator_x                                     0xF5CCB0
#define EQObject_Top_x                                             0xEABE54
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDF7708
#define pinstCAchievementsWnd_x                                    0xDF74A0
#define pinstCActionsWnd_x                                         0xDF74CC
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDF73E0
#define pinstCAdvancedLootWnd_x                                    0xDF77D4
#define pinstCAdventureLeaderboardWnd_x                            0xF6A340
#define pinstCAdventureRequestWnd_x                                0xF6A3F0
#define pinstCAdventureStatsWnd_x                                  0xF6A4A0
#define pinstCAggroMeterWnd_x                                      0xDF7438
#define pinstCAlarmWnd_x                                           0xDF7774
#define pinstCAlertHistoryWnd_x                                    0xDF77CC
#define pinstCAlertStackWnd_x                                      0xDF771C
#define pinstCAlertWnd_x                                           0xDF7730
#define pinstCAltStorageWnd_x                                      0xF6A800
#define pinstCAudioTriggersWindow_x                                0xCABB98
#define pinstCAuraWnd_x                                            0xDF740C
#define pinstCAvaZoneWnd_x                                         0xDF7734
#define pinstCBandolierWnd_x                                       0xDF7434
#define pinstCBankWnd_x                                            0xDF7408
#define pinstCBarterMerchantWnd_x                                  0xF6BA40
#define pinstCBarterSearchWnd_x                                    0xF6BAF0
#define pinstCBarterWnd_x                                          0xF6BBA0
#define pinstCBazaarConfirmationWnd_x                              0xDF74DC
#define pinstCBazaarSearchWnd_x                                    0xDF7494
#define pinstCBazaarWnd_x                                          0xDF775C
#define pinstCBlockedBuffWnd_x                                     0xDF7410
#define pinstCBlockedPetBuffWnd_x                                  0xDF7430
#define pinstCBodyTintWnd_x                                        0xDF74E0
#define pinstCBookWnd_x                                            0xDF7474
#define pinstCBreathWnd_x                                          0xDF7728
#define pinstCBuffWindowNORMAL_x                                   0xDF73F8
#define pinstCBuffWindowSHORT_x                                    0xDF73FC
#define pinstCBugReportWnd_x                                       0xDF7404
#define pinstCButtonWnd_x                                          0x15EF310
#define pinstCCastingWnd_x                                         0xDF7464
#define pinstCCastSpellWnd_x                                       0xDF7720
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDF7760
#define pinstCChatWindowManager_x                                  0xF6C660
#define pinstCClaimWnd_x                                           0xF6C7B8
#define pinstCColorPickerWnd_x                                     0xDF74D4
#define pinstCCombatAbilityWnd_x                                   0xDF776C
#define pinstCCombatSkillsSelectWnd_x                              0xDF7794
#define pinstCCompassWnd_x                                         0xDF74D0
#define pinstCConfirmationDialog_x                                 0xF716B8
#define pinstCContainerMgr_x                                       0xDF7754
#define pinstCContextMenuManager_x                                 0x15EF060
#define pinstCCursorAttachment_x                                   0xDF7448
#define pinstCDynamicZoneWnd_x                                     0xF6CD80
#define pinstCEditLabelWnd_x                                       0xDF73EC
#define pinstCEQMainWnd_x                                          0xF6CFC8
#define pinstCEventCalendarWnd_x                                   0xDF73F4
#define pinstCExtendedTargetWnd_x                                  0xDF7424
#define pinstCFacePick_x                                           0xDF77C4
#define pinstCFactionWnd_x                                         0xDF774C
#define pinstCFellowshipWnd_x                                      0xF6D1C8
#define pinstCFileSelectionWnd_x                                   0xDF7460
#define pinstCFindItemWnd_x                                        0xDF7740
#define pinstCFindLocationWnd_x                                    0xF6D320
#define pinstCFriendsWnd_x                                         0xDF77D0
#define pinstCGemsGameWnd_x                                        0xDF7748
#define pinstCGiveWnd_x                                            0xDF7778
#define pinstCGroupSearchFiltersWnd_x                              0xDF746C
#define pinstCGroupSearchWnd_x                                     0xF6D718
#define pinstCGroupWnd_x                                           0xF6D7C8
#define pinstCGuildBankWnd_x                                       0xEBA704
#define pinstCGuildCreationWnd_x                                   0xF6D928
#define pinstCGuildMgmtWnd_x                                       0xF6D9D8
#define pinstCharacterCreation_x                                   0xDF779C
#define pinstCHelpWnd_x                                            0xDF73D8
#define pinstCHeritageSelectionWnd_x                               0xDF77D8
#define pinstCHotButtonWnd_x                                       0xF6FB30
#define pinstCHotButtonWnd1_x                                      0xF6FB30
#define pinstCHotButtonWnd2_x                                      0xF6FB34
#define pinstCHotButtonWnd3_x                                      0xF6FB38
#define pinstCHotButtonWnd4_x                                      0xF6FB3C
#define pinstCIconSelectionWnd_x                                   0xDF743C
#define pinstCInspectWnd_x                                         0xDF73D4
#define pinstCInventoryWnd_x                                       0xDF6F40
#define pinstCInvSlotMgr_x                                         0xDF7504
#define pinstCItemDisplayManager_x                                 0xF700C0
#define pinstCItemExpTransferWnd_x                                 0xF701F0
#define pinstCItemOverflowWnd_x                                    0xDF749C
#define pinstCJournalCatWnd_x                                      0xDF747C
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDF7428
#define pinstCKeyRingWnd_x                                         0xDF73E8
#define pinstCLargeDialogWnd_x                                     0xF72338
#define pinstCLayoutCopyWnd_x                                      0xF70540
#define pinstCLFGuildWnd_x                                         0xF705F0
#define pinstCLoadskinWnd_x                                        0xDF7758
#define pinstCLootFiltersCopyWnd_x                                 0xCC8180
#define pinstCLootFiltersWnd_x                                     0xDF7724
#define pinstCLootSettingsWnd_x                                    0xDF773C
#define pinstCLootWnd_x                                            0xDF7480
#define pinstCMailAddressBookWnd_x                                 0xDF7710
#define pinstCMailCompositionWnd_x                                 0xDF74F4
#define pinstCMailIgnoreListWnd_x                                  0xDF7714
#define pinstCMailWnd_x                                            0xDF74C8
#define pinstCManageLootWnd_x                                      0xDF8638
#define pinstCMapToolbarWnd_x                                      0xDF73DC
#define pinstCMapViewWnd_x                                         0xDF6F5C
#define pinstCMarketplaceWnd_x                                     0xDF772C
#define pinstCMerchantWnd_x                                        0xDF7484
#define pinstCMIZoneSelectWnd_x                                    0xF70E28
#define pinstCMusicPlayerWnd_x                                     0xDF748C
#define pinstCNameChangeMercWnd_x                                  0xDF74C4
#define pinstCNameChangePetWnd_x                                   0xDF74A4
#define pinstCNameChangeWnd_x                                      0xDF74EC
#define pinstCNoteWnd_x                                            0xDF73C8
#define pinstCObjectPreviewWnd_x                                   0xDF7738
#define pinstCOptionsWnd_x                                         0xDF73CC
#define pinstCPetInfoWnd_x                                         0xDF74A8
#define pinstCPetitionQWnd_x                                       0xDF7490
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDF74E4
#define pinstCPlayerWnd_x                                          0xDF74AC
#define pinstCPopupWndManager_x                                    0xF716B8
#define pinstCProgressionSelectionWnd_x                            0xF71768
#define pinstCPurchaseGroupWnd_x                                   0xDF7780
#define pinstCPurchaseWnd_x                                        0xDF7750
#define pinstCPvPLeaderboardWnd_x                                  0xF71818
#define pinstCPvPStatsWnd_x                                        0xF718C8
#define pinstCQuantityWnd_x                                        0xDF742C
#define pinstCRaceChangeWnd_x                                      0xDF770C
#define pinstCRaidOptionsWnd_x                                     0xDF7470
#define pinstCRaidWnd_x                                            0xDF74FC
#define pinstCRealEstateItemsWnd_x                                 0xDF7498
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDF7418
#define pinstCRealEstateManageWnd_x                                0xDF7788
#define pinstCRealEstateNeighborhoodWnd_x                          0xDF77C8
#define pinstCRealEstatePlotSearchWnd_x                            0xDF6F44
#define pinstCRealEstatePurchaseWnd_x                              0xDF73D0
#define pinstCRespawnWnd_x                                         0xDF741C
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDF7718
#define pinstCSendMoneyWnd_x                                       0xDF7790
#define pinstCServerListWnd_x                                      0xDF73F0
#define pinstCSkillsSelectWnd_x                                    0xDF7764
#define pinstCSkillsWnd_x                                          0xDF7744
#define pinstCSocialEditWnd_x                                      0xDF73E4
#define pinstCSocialWnd_x                                          0xDF74C0
#define pinstCSpellBookWnd_x                                       0xDF7768
#define pinstCStoryWnd_x                                           0xDF74B0
#define pinstCTargetOfTargetWnd_x                                  0xF736F0
#define pinstCTargetWnd_x                                          0xDF7414
#define pinstCTaskOverlayWnd_x                                     0xDF777C
#define pinstCTaskSelectWnd_x                                      0xF73848
#define pinstCTaskManager_x                                        0xCC8AC0
#define pinstCTaskTemplateSelectWnd_x                              0xF738F8
#define pinstCTaskWnd_x                                            0xF739A8
#define pinstCTextEntryWnd_x                                       0xDF7400
#define pinstCTimeLeftWnd_x                                        0xDF7468
#define pinstCTipWndCONTEXT_x                                      0xF73BAC
#define pinstCTipWndOFDAY_x                                        0xF73BA8
#define pinstCTitleWnd_x                                           0xF73C58
#define pinstCTrackingWnd_x                                        0xDF6F48
#define pinstCTradeskillWnd_x                                      0xF73DC0
#define pinstCTradeWnd_x                                           0xDF74F0
#define pinstCTrainWnd_x                                           0xDF74E8
#define pinstCTributeBenefitWnd_x                                  0xF73FC0
#define pinstCTributeMasterWnd_x                                   0xF74070
#define pinstCTributeTrophyWnd_x                                   0xF74120
#define pinstCVideoModesWnd_x                                      0xDF74F8
#define pinstCVoiceMacroWnd_x                                      0xF5D418
#define pinstCVoteResultsWnd_x                                     0xDF7488
#define pinstCVoteWnd_x                                            0xDF7478
#define pinstCWebManager_x                                         0xF5DA94
#define pinstCZoneGuideWnd_x                                       0xDF7784
#define pinstCZonePathWnd_x                                        0xDF7798

#define pinstEQSuiteTextureLoader_x                                0xC96080
#define pinstItemIconCache_x                                       0xF6CF80
#define pinstLootFiltersManager_x                                  0xCC8230
#define pinstRewardSelectionWnd_x                                  0xF72010

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5AA580
#define __CastRay2_x                                               0x5AA5D0
#define __ConvertItemTags_x                                        0x5C6110
#define __CleanItemTags_x                                          0x47CFC0
#define __DoesFileExist_x                                          0x8FE210
#define __EQGetTime_x                                              0x8FAC00
#define __ExecuteCmd_x                                             0x5A2E40
#define __FixHeading_x                                             0x994ED0
#define __GameLoop_x                                               0x6B65F0
#define __get_bearing_x                                            0x5AA0F0
#define __get_melee_range_x                                        0x5AA7C0
#define __GetAnimationCache_x                                      0x71B8E0
#define __GetGaugeValueFromEQ_x                                    0x80DE50
#define __GetLabelFromEQ_x                                         0x80F930
#define __GetXTargetType_x                                         0x996920
#define __HandleMouseWheel_x                                       0x6B74B0
#define __HeadingDiff_x                                            0x994F40
#define __HelpPath_x                                               0xF587BC
#define __LoadFrontEnd_x                                           0x6B3910
#define __NewUIINI_x                                               0x80DB20
#define __ProcessGameEvents_x                                      0x60A720
#define __ProcessMouseEvent_x                                      0x609EE0
#define __SaveColors_x                                             0x54FBA0
#define __STMLToText_x                                             0x9383B0
#define __ToggleKeyRingItem_x                                      0x512EF0
#define CMemoryMappedFile__SetFile_x                               0xA83F40
#define CrashDetected_x                                            0x6B53B0
#define DrawNetStatus_x                                            0x6363F0
#define Expansion_HoT_x                                            0xEBA70C
#define Teleport_Table_Size_x                                      0xEA9648
#define Teleport_Table_x                                           0xEA9B00
#define Util__FastTime_x                                           0x8FA7D0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490380
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4992A0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499070
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493920
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492D70

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x5576B0
#define AltAdvManager__IsAbilityReady_x                            0x5565E0
#define AltAdvManager__GetAAById_x                                 0x5567E0
#define AltAdvManager__CanTrainAbility_x                           0x556850
#define AltAdvManager__CanSeeAbility_x                             0x556BB0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA0A0
#define CharacterZoneClient__HasSkill_x                            0x4D4F90
#define CharacterZoneClient__MakeMeVisible_x                       0x4D66B0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE3B0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BA9B0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9020
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9100
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D91E0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C31A0
#define CharacterZoneClient__BardCastBard_x                        0x4C5D00
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAA80
#define CharacterZoneClient__GetEffect_x                           0x4BA8F0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C41F0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C42C0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C4310
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4460
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4630
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2860
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7610
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7090

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6DCFC0
#define CBankWnd__WndNotification_x                                0x6DCDA0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6EA6E0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x618EA0
#define CButtonWnd__CButtonWnd_x                                   0x9347C0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x70A9C0
#define CChatManager__InitContextMenu_x                            0x703B10
#define CChatManager__FreeChatWindow_x                             0x709500
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E86F0
#define CChatManager__SetLockedActiveChatWindow_x                  0x70A640
#define CChatManager__CreateChatWindow_x                           0x709B40

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8800

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x948D30
#define CContextMenu__dCContextMenu_x                              0x948F70
#define CContextMenu__AddMenuItem_x                                0x948F80
#define CContextMenu__RemoveMenuItem_x                             0x949290
#define CContextMenu__RemoveAllMenuItems_x                         0x9492B0
#define CContextMenu__CheckMenuItem_x                              0x949330
#define CContextMenu__SetMenuItem_x                                0x9491B0
#define CContextMenu__AddSeparator_x                               0x949110

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x9498D0
#define CContextMenuManager__RemoveMenu_x                          0x949940
#define CContextMenuManager__PopupMenu_x                           0x949A00
#define CContextMenuManager__Flush_x                               0x949870
#define CContextMenuManager__GetMenu_x                             0x49B3F0
#define CContextMenuManager__CreateDefaultMenu_x                   0x7160E0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D7690
#define CChatService__GetFriendName_x                              0x8D76A0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x70B2C0
#define CChatWindow__Clear_x                                       0x70C590
#define CChatWindow__WndNotification_x                             0x70CD20
#define CChatWindow__AddHistory_x                                  0x70BE50

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x946180
#define CComboWnd__Draw_x                                          0x945670
#define CComboWnd__GetCurChoice_x                                  0x945FC0
#define CComboWnd__GetListRect_x                                   0x945B20
#define CComboWnd__GetTextRect_x                                   0x9461F0
#define CComboWnd__InsertChoice_x                                  0x945CB0
#define CComboWnd__SetColors_x                                     0x945C80
#define CComboWnd__SetChoice_x                                     0x945F90
#define CComboWnd__GetItemCount_x                                  0x945FD0
#define CComboWnd__GetCurChoiceText_x                              0x946010
#define CComboWnd__GetChoiceText_x                                 0x945FE0
#define CComboWnd__InsertChoiceAtIndex_x                           0x945D50

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x713AD0
#define CContainerWnd__vftable_x                                   0xB09FDC
#define CContainerWnd__SetContainer_x                              0x715030

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54A5E0
#define CDisplay__PreZoneMainUI_x                                  0x54A5F0
#define CDisplay__CleanGameUI_x                                    0x54F960
#define CDisplay__GetClickedActor_x                                0x542900
#define CDisplay__GetUserDefinedColor_x                            0x53AFC0
#define CDisplay__GetWorldFilePath_x                               0x544370
#define CDisplay__is3dON_x                                         0x53F560
#define CDisplay__ReloadUI_x                                       0x549A70
#define CDisplay__WriteTextHD2_x                                   0x53F350
#define CDisplay__TrueDistance_x                                   0x546030
#define CDisplay__SetViewActor_x                                   0x542220
#define CDisplay__GetFloorHeight_x                                 0x53F620
#define CDisplay__SetRenderWindow_x                                0x53DF80
#define CDisplay__ToggleScreenshotMode_x                           0x541CF0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x968A60

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x94C2A0
#define CEditWnd__GetCharIndexPt_x                                 0x94D1D0
#define CEditWnd__GetDisplayString_x                               0x94D070
#define CEditWnd__GetHorzOffset_x                                  0x94B8D0
#define CEditWnd__GetLineForPrintableChar_x                        0x94E370
#define CEditWnd__GetSelStartPt_x                                  0x94D480
#define CEditWnd__GetSTMLSafeText_x                                0x94CE90
#define CEditWnd__PointFromPrintableChar_x                         0x94DFA0
#define CEditWnd__SelectableCharFromPoint_x                        0x94E110
#define CEditWnd__SetEditable_x                                    0x94D550
#define CEditWnd__SetWindowTextA_x                                 0x94CC10

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5F8380
#define CEverQuest__ClickedPlayer_x                                0x5EA390
#define CEverQuest__CreateTargetIndicator_x                        0x6079B0
#define CEverQuest__DeleteTargetIndicator_x                        0x607A40
#define CEverQuest__DoTellWindow_x                                 0x4E88E0
#define CEverQuest__OutputTextToLog_x                              0x4E8B60
#define CEverQuest__DropHeldItemOnGround_x                         0x5DF3D0
#define CEverQuest__dsp_chat_x                                     0x4E8EF0
#define CEverQuest__trimName_x                                     0x603C90
#define CEverQuest__Emote_x                                        0x5F8BE0
#define CEverQuest__EnterZone_x                                    0x5F2B60
#define CEverQuest__GetBodyTypeDesc_x                              0x5FD550
#define CEverQuest__GetClassDesc_x                                 0x5FDB90
#define CEverQuest__GetClassThreeLetterCode_x                      0x5FE190
#define CEverQuest__GetDeityDesc_x                                 0x6062F0
#define CEverQuest__GetLangDesc_x                                  0x5FE350
#define CEverQuest__GetRaceDesc_x                                  0x5FDB70
#define CEverQuest__InterpretCmd_x                                 0x6068C0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5E35D0
#define CEverQuest__LMouseUp_x                                     0x5E1960
#define CEverQuest__RightClickedOnPlayer_x                         0x5E3EB0
#define CEverQuest__RMouseUp_x                                     0x5E28E0
#define CEverQuest__SetGameState_x                                 0x5DF160
#define CEverQuest__UPCNotificationFlush_x                         0x603B90
#define CEverQuest__IssuePetCommand_x                              0x5FF750
#define CEverQuest__ReportSuccessfulHit_x                          0x5F9FD0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7258E0
#define CGaugeWnd__CalcLinesFillRect_x                             0x725940
#define CGaugeWnd__Draw_x                                          0x724F70

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF350
#define CGuild__GetGuildName_x                                     0x4AE430
#define CGuild__GetGuildIndex_x                                    0x4AE7C0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x740D20

//CHotButton
#define CHotButton__SetButtonSize_x                                0x619260

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x74DD50
#define CInvSlotMgr__MoveItem_x                                    0x74CA60
#define CInvSlotMgr__SelectSlot_x                                  0x74DE20

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x74B2D0
#define CInvSlot__SliderComplete_x                                 0x749030
#define CInvSlot__GetItemBase_x                                    0x7489B0
#define CInvSlot__UpdateItem_x                                     0x748B20

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x74F890
#define CInvSlotWnd__CInvSlotWnd_x                                 0x74EA40
#define CInvSlotWnd__HandleLButtonUp_x                             0x74F410

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x809170
#define CItemDisplayWnd__UpdateStrings_x                           0x75DFB0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x757C90
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x7581C0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x75E5B0
#define CItemDisplayWnd__AboutToShow_x                             0x75DBF0
#define CItemDisplayWnd__WndNotification_x                         0x75F6A0
#define CItemDisplayWnd__RequestConvertItem_x                      0x75F160
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x75CC50
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x75DA10

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x841DC0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x763BA0

// CLabel 
#define CLabel__Draw_x                                             0x769630

// CListWnd
#define CListWnd__CListWnd_x                                       0x91EAB0
#define CListWnd__dCListWnd_x                                      0x91EDD0
#define CListWnd__AddColumn_x                                      0x923230
#define CListWnd__AddColumn1_x                                     0x923280
#define CListWnd__AddLine_x                                        0x923610
#define CListWnd__AddString_x                                      0x923410
#define CListWnd__CalculateFirstVisibleLine_x                      0x922FF0
#define CListWnd__CalculateVSBRange_x                              0x922DD0
#define CListWnd__ClearSel_x                                       0x923DF0
#define CListWnd__ClearAllSel_x                                    0x923E50
#define CListWnd__CloseAndUpdateEditWindow_x                       0x924870
#define CListWnd__Compare_x                                        0x922700
#define CListWnd__Draw_x                                           0x91EF00
#define CListWnd__DrawColumnSeparators_x                           0x9216E0
#define CListWnd__DrawHeader_x                                     0x921B40
#define CListWnd__DrawItem_x                                       0x922040
#define CListWnd__DrawLine_x                                       0x921840
#define CListWnd__DrawSeparator_x                                  0x921780
#define CListWnd__EnableLine_x                                     0x920FC0
#define CListWnd__EnsureVisible_x                                  0x924790
#define CListWnd__ExtendSel_x                                      0x923D20
#define CListWnd__GetColumnTooltip_x                               0x920B00
#define CListWnd__GetColumnMinWidth_x                              0x920B70
#define CListWnd__GetColumnWidth_x                                 0x920A70
#define CListWnd__GetCurSel_x                                      0x920400
#define CListWnd__GetItemAtPoint_x                                 0x921230
#define CListWnd__GetItemAtPoint1_x                                0x9212A0
#define CListWnd__GetItemData_x                                    0x920480
#define CListWnd__GetItemHeight_x                                  0x920840
#define CListWnd__GetItemIcon_x                                    0x920610
#define CListWnd__GetItemRect_x                                    0x9210B0
#define CListWnd__GetItemText_x                                    0x9204C0
#define CListWnd__GetSelList_x                                     0x923EA0
#define CListWnd__GetSeparatorRect_x                               0x9214E0
#define CListWnd__InsertLine_x                                     0x923A00
#define CListWnd__RemoveLine_x                                     0x923B50
#define CListWnd__SetColors_x                                      0x922DA0
#define CListWnd__SetColumnJustification_x                         0x922AD0
#define CListWnd__SetColumnWidth_x                                 0x9229F0
#define CListWnd__SetCurSel_x                                      0x923C60
#define CListWnd__SetItemColor_x                                   0x924440
#define CListWnd__SetItemData_x                                    0x924400
#define CListWnd__SetItemText_x                                    0x924010
#define CListWnd__ShiftColumnSeparator_x                           0x922B90
#define CListWnd__Sort_x                                           0x922880
#define CListWnd__ToggleSel_x                                      0x923C90
#define CListWnd__SetColumnsSizable_x                              0x922C40
#define CListWnd__SetItemWnd_x                                     0x9242C0
#define CListWnd__GetItemWnd_x                                     0x920660
#define CListWnd__SetItemIcon_x                                    0x924090
#define CListWnd__CalculateCustomWindowPositions_x                 0x9230F0
#define CListWnd__SetVScrollPos_x                                  0x9229D0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x77ED60
#define CMapViewWnd__GetWorldCoordinates_x                         0x77D470
#define CMapViewWnd__HandleLButtonDown_x                           0x77A4B0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x79ED30
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79F610
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79FB40
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A2AD0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x79D8A0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A8680
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x79E950

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8A5030
#define CPacketScrambler__hton_x                                   0x8A5020

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x93D9D0
#define CSidlManager__FindScreenPieceTemplate_x                    0x93DDE0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x93DBD0
#define CSidlManager__CreateLabel_x                                0x800600
#define CSidlManager__CreateXWndFromTemplate_x                     0x940D40
#define CSidlManager__CreateXWndFromTemplate1_x                    0x940F20
#define CSidlManager__CreateXWnd_x                                 0x800530
#define CSidlManager__CreateHotButtonWnd_x                         0x800B00

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x93A4E0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x93A3E0
#define CSidlScreenWnd__ConvertToRes_x                             0x95FA10
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x939E70
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x939B60
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x939C30
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x939D00
#define CSidlScreenWnd__DrawSidlPiece_x                            0x93A980
#define CSidlScreenWnd__EnableIniStorage_x                         0x93AE50
#define CSidlScreenWnd__GetSidlPiece_x                             0x93AB70
#define CSidlScreenWnd__Init1_x                                    0x939760
#define CSidlScreenWnd__LoadIniInfo_x                              0x93AEA0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x93B9B0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x938B60
#define CSidlScreenWnd__StoreIniInfo_x                             0x93B530
#define CSidlScreenWnd__StoreIniVis_x                              0x93B890
#define CSidlScreenWnd__WndNotification_x                          0x93A890
#define CSidlScreenWnd__GetChildItem_x                             0x93ADD0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x92A610
#define CSidlScreenWnd__m_layoutCopy_x                             0x15EEF30

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x67D780
#define CSkillMgr__GetSkillCap_x                                   0x67D960
#define CSkillMgr__GetNameToken_x                                  0x67CF00
#define CSkillMgr__IsActivatedSkill_x                              0x67D040
#define CSkillMgr__IsCombatSkill_x                                 0x67CF80

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x94A6B0
#define CSliderWnd__SetValue_x                                     0x94A520
#define CSliderWnd__SetNumTicks_x                                  0x94A580

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x806600

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x952F80
#define CStmlWnd__CalculateHSBRange_x                              0x9540A0
#define CStmlWnd__CalculateVSBRange_x                              0x954010
#define CStmlWnd__CanBreakAtCharacter_x                            0x9583D0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x959060
#define CStmlWnd__ForceParseNow_x                                  0x953570
#define CStmlWnd__GetNextTagPiece_x                                0x958330
#define CStmlWnd__GetSTMLText_x                                    0x5026A0
#define CStmlWnd__GetVisibleText_x                                 0x953590
#define CStmlWnd__InitializeWindowVariables_x                      0x958EB0
#define CStmlWnd__MakeStmlColorTag_x                               0x9525F0
#define CStmlWnd__MakeWndNotificationTag_x                         0x952660
#define CStmlWnd__SetSTMLText_x                                    0x9516A0
#define CStmlWnd__StripFirstSTMLLines_x                            0x95A130
#define CStmlWnd__UpdateHistoryString_x                            0x959270

// CTabWnd 
#define CTabWnd__Draw_x                                            0x950740
#define CTabWnd__DrawCurrentPage_x                                 0x950E70
#define CTabWnd__DrawTab_x                                         0x950B90
#define CTabWnd__GetCurrentPage_x                                  0x94FF40
#define CTabWnd__GetPageInnerRect_x                                0x950180
#define CTabWnd__GetTabInnerRect_x                                 0x9500C0
#define CTabWnd__GetTabRect_x                                      0x94FF70
#define CTabWnd__InsertPage_x                                      0x950390
#define CTabWnd__SetPage_x                                         0x950200
#define CTabWnd__SetPageRect_x                                     0x950680
#define CTabWnd__UpdatePage_x                                      0x950A50
#define CTabWnd__GetPageFromTabIndex_x                             0x950AD0
#define CTabWnd__GetCurrentTabIndex_x                              0x94FF30

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x763F70
#define CPageWnd__SetTabText_x                                     0x94FA80

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9050

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x927490
#define CTextureFont__GetTextExtent_x                              0x927650

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B04F0
#define CHtmlComponentWnd__ValidateUri_x                           0x742710
#define CHtmlWnd__SetClientCallbacks_x                             0x61E2C0
#define CHtmlWnd__AddObserver_x                                    0x61E2E0
#define CHtmlWnd__RemoveObserver_x                                 0x61E340
#define Window__getProgress_x                                      0x85A480
#define Window__getStatus_x                                        0x85A4A0
#define Window__getURI_x                                           0x85A4B0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9654B0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x914620

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8430
#define CXStr__CXStr1_x                                            0x4FD860
#define CXStr__CXStr3_x                                            0x8F6D00
#define CXStr__dCXStr_x                                            0x478670
#define CXStr__operator_equal_x                                    0x8F6F30
#define CXStr__operator_equal1_x                                   0x8F6F70
#define CXStr__operator_plus_equal1_x                              0x8F7A00
#define CXStr__SetString_x                                         0x8F98F0
#define CXStr__operator_char_p_x                                   0x8F7440
#define CXStr__GetChar_x                                           0x8F9240
#define CXStr__Delete_x                                            0x8F8AF0
#define CXStr__GetUnicode_x                                        0x8F92B0
#define CXStr__GetLength_x                                         0x4A8E00
#define CXStr__Mid_x                                               0x47D370
#define CXStr__Insert_x                                            0x8F9310
#define CXStr__FindNext_x                                          0x8F8F60

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x948940
#define CXWnd__BringToTop_x                                        0x92DC80
#define CXWnd__Center_x                                            0x92D800
#define CXWnd__ClrFocus_x                                          0x92D620
#define CXWnd__Destroy_x                                           0x92D6C0
#define CXWnd__DoAllDrawing_x                                      0x929DB0
#define CXWnd__DrawChildren_x                                      0x929D80
#define CXWnd__DrawColoredRect_x                                   0x92A200
#define CXWnd__DrawTooltip_x                                       0x9288C0
#define CXWnd__DrawTooltipAtPoint_x                                0x928980
#define CXWnd__GetBorderFrame_x                                    0x92A060
#define CXWnd__GetChildWndAt_x                                     0x92DD20
#define CXWnd__GetClientClipRect_x                                 0x92C030
#define CXWnd__GetScreenClipRect_x                                 0x92C0E0
#define CXWnd__GetScreenRect_x                                     0x92C290
#define CXWnd__GetTooltipRect_x                                    0x92A250
#define CXWnd__GetWindowTextA_x                                    0x49CB40
#define CXWnd__IsActive_x                                          0x92A990
#define CXWnd__IsDescendantOf_x                                    0x92CC00
#define CXWnd__IsReallyVisible_x                                   0x92CC30
#define CXWnd__IsType_x                                            0x92E380
#define CXWnd__Move_x                                              0x92CC90
#define CXWnd__Move1_x                                             0x92CD40
#define CXWnd__ProcessTransition_x                                 0x92D7B0
#define CXWnd__Refade_x                                            0x92CFF0
#define CXWnd__Resize_x                                            0x92D260
#define CXWnd__Right_x                                             0x92DA40
#define CXWnd__SetFocus_x                                          0x92D5E0
#define CXWnd__SetFont_x                                           0x92D650
#define CXWnd__SetKeyTooltip_x                                     0x92E1A0
#define CXWnd__SetMouseOver_x                                      0x92B190
#define CXWnd__StartFade_x                                         0x92CAE0
#define CXWnd__GetChildItem_x                                      0x92DE90
#define CXWnd__SetParent_x                                         0x92C9E0
#define CXWnd__Minimize_x                                          0x92D2D0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x960A90

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x930BB0
#define CXWndManager__DrawWindows_x                                0x930BD0
#define CXWndManager__GetKeyboardFlags_x                           0x9333D0
#define CXWndManager__HandleKeyboardMsg_x                          0x932F80
#define CXWndManager__RemoveWnd_x                                  0x933620
#define CXWndManager__RemovePendingDeletionWnd_x                   0x933B80

// CDBStr
#define CDBStr__GetString_x                                        0x539F50

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BB990
#define EQ_Character__Cur_HP_x                                     0x4D1FD0
#define EQ_Character__Cur_Mana_x                                   0x4D96E0
#define EQ_Character__GetCastingTimeModifier_x                     0x4BEA00
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B24A0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B25F0
#define EQ_Character__GetHPRegen_x                                 0x4DF480
#define EQ_Character__GetEnduranceRegen_x                          0x4DFA80
#define EQ_Character__GetManaRegen_x                               0x4DFEC0
#define EQ_Character__Max_Endurance_x                              0x644270
#define EQ_Character__Max_HP_x                                     0x4D1E00
#define EQ_Character__Max_Mana_x                                   0x644070
#define EQ_Character__doCombatAbility_x                            0x6466D0
#define EQ_Character__UseSkill_x                                   0x4E1CA0
#define EQ_Character__GetConLevel_x                                0x63D2F0
#define EQ_Character__IsExpansionFlag_x                            0x5A15F0
#define EQ_Character__TotalEffect_x                                0x4C5440
#define EQ_Character__GetPCSpellAffect_x                           0x4BF750
#define EQ_Character__SpellDuration_x                              0x4BF280
#define EQ_Character__GetAdjustedSkill_x                           0x4D4D50
#define EQ_Character__GetBaseSkill_x                               0x4D5CF0
#define EQ_Character__CanUseItem_x                                 0x4D99F0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8C4590

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x65A7C0

//PcClient
#define PcClient__PcClient_x                                       0x63AA30

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B95F0
#define CCharacterListWnd__EnterWorld_x                            0x4B9030
#define CCharacterListWnd__Quit_x                                  0x4B8D80
#define CCharacterListWnd__UpdateList_x                            0x4B91C0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x61F510
#define EQ_Item__CreateItemTagString_x                             0x89E8F0
#define EQ_Item__IsStackable_x                                     0x8A3410
#define EQ_Item__GetImageNum_x                                     0x8A0340
#define EQ_Item__CreateItemClient_x                                0x61E6E0
#define EQ_Item__GetItemValue_x                                    0x8A1660
#define EQ_Item__ValueSellMerchant_x                               0x8A4C10
#define EQ_Item__IsKeyRingItem_x                                   0x8A2D40
#define EQ_Item__CanGoInBag_x                                      0x61F630
#define EQ_Item__IsEmpty_x                                         0x8A2890
#define EQ_Item__GetMaxItemCount_x                                 0x8A1A70
#define EQ_Item__GetHeldItem_x                                     0x8A0210
#define EQ_Item__GetAugmentFitBySlot_x                             0x89E280

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x558380
#define EQ_LoadingS__Array_x                                       0xC1DB60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x644BD0
#define EQ_PC__GetAlternateAbilityId_x                             0x8ADE20
#define EQ_PC__GetCombatAbility_x                                  0x8AE490
#define EQ_PC__GetCombatAbilityTimer_x                             0x8AE500
#define EQ_PC__GetItemRecastTimer_x                                0x646C50
#define EQ_PC__HasLoreItem_x                                       0x63DB00
#define EQ_PC__AlertInventoryChanged_x                             0x63CC30
#define EQ_PC__GetPcZoneClient_x                                   0x6691D0
#define EQ_PC__RemoveMyAffect_x                                    0x649E80
#define EQ_PC__GetKeyRingItems_x                                   0x8AED90
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8AEB20
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8AF090

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5A7B70
#define EQItemList__add_object_x                                   0x5D4B30
#define EQItemList__add_item_x                                     0x5A80D0
#define EQItemList__delete_item_x                                  0x5A8120
#define EQItemList__FreeItemList_x                                 0x5A8020

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x536A80

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x65C040
#define EQPlayer__dEQPlayer_x                                      0x64F390
#define EQPlayer__DoAttack_x                                       0x663E80
#define EQPlayer__EQPlayer_x                                       0x64FA50
#define EQPlayer__SetNameSpriteState_x                             0x653D20
#define EQPlayer__SetNameSpriteTint_x                              0x654BF0
#define PlayerBase__HasProperty_j_x                                0x9932A0
#define EQPlayer__IsTargetable_x                                   0x993740
#define EQPlayer__CanSee_x                                         0x9935A0
#define EQPlayer__CanSee1_x                                        0x993670
#define PlayerBase__GetVisibilityLineSegment_x                     0x993360

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x666C60
#define PlayerZoneClient__GetLevel_x                               0x669210
#define PlayerZoneClient__IsValidTeleport_x                        0x5D5CA0
#define PlayerZoneClient__LegalPlayerRace_x                        0x5517C0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x65ED90
#define EQPlayerManager__GetSpawnByName_x                          0x65EE40
#define EQPlayerManager__GetPlayerFromPartialName_x                0x65EED0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x622C40
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x622CC0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x622D00
#define KeypressHandler__ClearCommandStateArray_x                  0x624110
#define KeypressHandler__HandleKeyDown_x                           0x624130
#define KeypressHandler__HandleKeyUp_x                             0x6241D0
#define KeypressHandler__SaveKeymapping_x                          0x624620

// MapViewMap 
#define MapViewMap__Clear_x                                        0x77ABD0
#define MapViewMap__SaveEx_x                                       0x77DF90
#define MapViewMap__SetZoom_x                                      0x782650

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C24B0

// StringTable 
#define StringTable__getString_x                                   0x8BD0B0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x649AF0
#define PcZoneClient__RemovePetEffect_x                            0x64A120
#define PcZoneClient__HasAlternateAbility_x                        0x643EA0
#define PcZoneClient__GetCurrentMod_x                              0x4E4D60
#define PcZoneClient__GetModCap_x                                  0x4E4C60
#define PcZoneClient__CanEquipItem_x                               0x644570
#define PcZoneClient__GetItemByID_x                                0x6470C0
#define PcZoneClient__GetItemByItemClass_x                         0x647210
#define PcZoneClient__RemoveBuffEffect_x                           0x64A140
#define PcZoneClient__BandolierSwap_x                              0x645190
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x646BF0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5DA830

//IconCache
#define IconCache__GetIcon_x                                       0x71B180

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x712C70
#define CContainerMgr__CloseContainer_x                            0x712F40
#define CContainerMgr__OpenExperimentContainer_x                   0x7139C0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D2BA0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x617690

//CLootWnd
#define CLootWnd__LootAll_x                                        0x771100
#define CLootWnd__RequestLootSlot_x                                0x770330

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x5759C0
#define EQ_Spell__SpellAffects_x                                   0x575E30
#define EQ_Spell__SpellAffectBase_x                                0x575BF0
#define EQ_Spell__IsStackable_x                                    0x4C9A10
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9890
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6970
#define EQ_Spell__IsSPAStacking_x                                  0x576C80
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x576190
#define EQ_Spell__IsNoRemove_x                                     0x4C99F0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x576C90
#define __IsResEffectSpell_x                                       0x4C8E80

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD090

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8CCB50

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x8198E0
#define CTargetWnd__WndNotification_x                              0x819170
#define CTargetWnd__RefreshTargetBuffs_x                           0x819440
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x8182D0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x81DEE0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x5344A0
#define CTaskManager__HandleMessage_x                              0x532950
#define CTaskManager__GetTaskStatus_x                              0x534550
#define CTaskManager__GetElementDescription_x                      0x5345D0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x570F10
#define EqSoundManager__PlayScriptMp3_x                            0x571070
#define EqSoundManager__SoundAssistPlay_x                          0x6816C0
#define EqSoundManager__WaveInstancePlay_x                         0x680C30

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x528210

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x94EF90

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x55FE70
#define CAltAbilityData__GetMercMaxRank_x                          0x55FE00
#define CAltAbilityData__GetMaxRank_x                              0x555460

//CTargetRing
#define CTargetRing__Cast_x                                        0x6157B0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9870
#define CharacterBase__CreateItemGlobalIndex_x                     0x50F560
#define CharacterBase__CreateItemIndex_x                           0x61D870
#define CharacterBase__GetItemPossession_x                         0x4FB0D0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8D5160
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8D51C0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F9D70
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6FA5A0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6FA650

//messages
#define msg_spell_worn_off_x                                       0x5997F0
#define msg_new_text_x                                             0x58E580
#define __msgTokenTextParam_x                                      0x59BD20
#define msgTokenText_x                                             0x59BF70

//SpellManager
#define SpellManager__vftable_x                                    0xAE4184
#define SpellManager__SpellManager_x                               0x6849F0
#define Spellmanager__LoadTextSpells_x                             0x6852E0
#define SpellManager__GetSpellByGroupAndRank_x                     0x684BC0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x997210

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x50FBE0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x59FAD0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x636250
#define ItemGlobalIndex__IsValidIndex_x                            0x50FC40

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8CD4F0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8CD770

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x769970

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x717380
#define CCursorAttachment__AttachToCursor1_x                       0x7173C0
#define CCursorAttachment__Deactivate_x                            0x7183B0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x941D80
#define CSidlManagerBase__CreatePageWnd_x                          0x941570
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x93D7F0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x93D780

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x95EFB0
#define CEQSuiteTextureLoader__GetTexture_x                        0x95EC70

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50CAC0
#define CFindItemWnd__WndNotification_x                            0x50D5A0
#define CFindItemWnd__Update_x                                     0x50E110
#define CFindItemWnd__PickupSelectedItem_x                         0x50C300

//IString
#define IString__Append_x                                          0x4FC970

//Camera
#define CDisplay__cameraType_x                                     0xDF7500
#define EverQuest__Cameras_x                                       0xEBAA5C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x515290
#define LootFiltersManager__GetItemFilterData_x                    0x514BA0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x514BD0
#define LootFiltersManager__SetItemLootFilter_x                    0x514DF0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C0B10

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x99CD80
#define CResolutionHandler__GetWindowedStyle_x                     0x67C100

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70FA30

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E11F0
#define CDistillerInfo__Instance_x                                 0x8E1190

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72FB10
#define CGroupWnd__UpdateDisplay_x                                 0x72EE60

//ItemBase
#define ItemBase__IsLore_x                                         0x8A2DE0
#define ItemBase__IsLoreEquipped_x                                 0x8A2E50

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5D4A90
#define EQPlacedItemManager__GetItemByGuid_x                       0x5D4BD0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5D4C30

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6718F0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x675260

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x502D50

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F1770
#define FactionManagerClient__HandleFactionMessage_x               0x4F1DE0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F23A0
#define FactionManagerClient__GetMaxFaction_x                      0x4F23BF
#define FactionManagerClient__GetMinFaction_x                      0x4F2370

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FB0A0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x9264E0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BE50

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FB380

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x55F330

//CTargetManager
#define CTargetManager__Get_x                                      0x688260

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6718F0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8E10

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5A7FC0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF580F0

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
