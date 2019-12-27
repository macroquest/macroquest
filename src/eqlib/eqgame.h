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
#define __ExpectedVersionDate                                     "Dec 19 2019"
#define __ExpectedVersionTime                                     "15:04:34"
#define __ActualVersionDate_x                                      0xB0D674
#define __ActualVersionTime_x                                      0xB0D668
#define __ActualVersionBuild_x                                     0xAF9344

// Memory Protection
#define __MemChecker0_x                                            0x631E90
#define __MemChecker1_x                                            0x905680
#define __MemChecker2_x                                            0x6C0760
#define __MemChecker3_x                                            0x6C06B0
#define __MemChecker4_x                                            0x85C430
#define __EncryptPad0_x                                            0xC443E8
#define __EncryptPad1_x                                            0xCA25E8
#define __EncryptPad2_x                                            0xC54C80
#define __EncryptPad3_x                                            0xC54880
#define __EncryptPad4_x                                            0xC92C00
#define __EncryptPad5_x                                            0xF6E210
#define __AC1_x                                                    0x818E46
#define __AC2_x                                                    0x5EBB3F
#define __AC3_x                                                    0x5F323F
#define __AC4_x                                                    0x5F7210
#define __AC5_x                                                    0x5FD51F
#define __AC6_x                                                    0x601B36
#define __AC7_x                                                    0x5EB5B0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x193E2C

// Direct Input
#define DI8__Main_x                                                0xF6E238
#define DI8__Keyboard_x                                            0xF6E23C
#define DI8__Mouse_x                                               0xF6E21C
#define DI8__Mouse_Copy_x                                          0xEC741C
#define DI8__Mouse_Check_x                                         0xF6BD64
#define __AutoSkillArray_x                                         0xEC8334
#define __Attack_x                                                 0xF6615B
#define __Autofire_x                                               0xF6615C
#define __BindList_x                                               0xC32E20
#define g_eqCommandStates_x                                        0xC33BA0
#define __Clicks_x                                                 0xEC74D4
#define __CommandList_x                                            0xC34760
#define __CurrentMapLabel_x                                        0xF7EBDC
#define __CurrentSocial_x                                          0xC1C7CC
#define __DoAbilityList_x                                          0xEFDC7C
#define __do_loot_x                                                0x5B7460
#define __DrawHandler_x                                            0x15FDF50
#define __GroupCount_x                                             0xEB9DD2
#define __Guilds_x                                                 0xEBDC28
#define __gWorld_x                                                 0xEB9C88
#define __HWnd_x                                                   0xF6E220
#define __heqmain_x                                                0xF6E1F8
#define __InChatMode_x                                             0xEC7404
#define __LastTell_x                                               0xEC9378
#define __LMouseHeldTime_x                                         0xEC7540
#define __Mouse_x                                                  0xF6E224
#define __MouseLook_x                                              0xEC749A
#define __MouseEventTime_x                                         0xF66C3C
#define __gpbCommandEvent_x                                        0xEB76C0
#define __NetStatusToggle_x                                        0xEC749D
#define __PCNames_x                                                0xEC8924
#define __RangeAttackReady_x                                       0xEC8618
#define __RMouseHeldTime_x                                         0xEC753C
#define __RunWalkState_x                                           0xEC7408
#define __ScreenMode_x                                             0xE0509C
#define __ScreenX_x                                                0xEC73BC
#define __ScreenY_x                                                0xEC73B8
#define __ScreenXMax_x                                             0xEC73C0
#define __ScreenYMax_x                                             0xEC73C4
#define __ServerHost_x                                             0xEB78F3
#define __ServerName_x                                             0xEFDC3C
#define __ShiftKeyDown_x                                           0xEC7A94
#define __ShowNames_x                                              0xEC87D4
#define __Socials_x                                                0xEFDD3C
#define __SubscriptionType_x                                       0xFC30E0
#define __TargetAggroHolder_x                                      0xF81590
#define __ZoneType_x                                               0xEC7898
#define __GroupAggro_x                                             0xF815D0
#define __LoginName_x                                              0xF6E98C
#define __Inviter_x                                                0xF660D8
#define __AttackOnAssist_x                                         0xEC8790
#define __UseTellWindows_x                                         0xEC8AC0
#define __gfMaxZoomCameraDistance_x                                0xB02FD8
#define __gfMaxCameraDistance_x                                    0xB2F524
#define __pulAutoRun_x                                             0xEC74B8
#define __pulForward_x                                             0xEC8AF8
#define __pulBackward_x                                            0xEC8AFC
#define __pulTurnRight_x                                           0xEC8B00
#define __pulTurnLeft_x                                            0xEC8B04
#define __pulStrafeLeft_x                                          0xEC8B08
#define __pulStrafeRight_x                                         0xEC8B0C

////
//Section 1: Vital Offsets
////
#define instCRaid_x                                                0xEB9FC8
#define instEQZoneInfo_x                                           0xEC7690
#define pinstActiveBanker_x                                        0xEB76D8
#define pinstActiveCorpse_x                                        0xEB76D0
#define pinstActiveGMaster_x                                       0xEB76D4
#define pinstActiveMerchant_x                                      0xEB76CC
#define pinstAltAdvManager_x                                       0xE06200
#define pinstBandageTarget_x                                       0xEB76E8
#define pinstCamActor_x                                            0xE05090
#define pinstCDBStr_x                                              0xE04F1C
#define pinstCDisplay_x                                            0xEB9C84
#define pinstCEverQuest_x                                          0xF6E250
#define pinstEverQuestInfo_x                                       0xEC73B0
#define pinstCharData_x                                            0xEB9DB4
#define pinstCharSpawn_x                                           0xEB7720
#define pinstControlledMissile_x                                   0xEB7C0C
#define pinstControlledPlayer_x                                    0xEB7720
#define pinstCResolutionHandler_x                                  0x15FE180
#define pinstCSidlManager_x                                        0x15FD118
#define pinstCXWndManager_x                                        0x15FD114
#define instDynamicZone_x                                          0xEBDB00
#define pinstDZMember_x                                            0xEBDC10
#define pinstDZTimerInfo_x                                         0xEBDC14
#define pinstEqLogin_x                                             0xF6E2D8
#define instEQMisc_x                                               0xE04E60
#define pinstEQSoundManager_x                                      0xE071D0
#define pinstEQSpellStrings_x                                      0xCC7878
#define instExpeditionLeader_x                                     0xEBDB4A
#define instExpeditionName_x                                       0xEBDB8A
#define pinstGroup_x                                               0xEB9DCE
#define pinstImeManager_x                                          0x15FD110
#define pinstLocalPlayer_x                                         0xEB76C8
#define pinstMercenaryData_x                                       0xF6872C
#define pinstMercenaryStats_x                                      0xF816DC
#define pinstModelPlayer_x                                         0xEB76E0
#define pinstPCData_x                                              0xEB9DB4
#define pinstSkillMgr_x                                            0xF6A898
#define pinstSpawnManager_x                                        0xF69340
#define pinstSpellManager_x                                        0xF6AAB8
#define pinstSpellSets_x                                           0xF5ED84
#define pinstStringTable_x                                         0xEB9DB8
#define pinstSwitchManager_x                                       0xEB7568
#define pinstTarget_x                                              0xEB771C
#define pinstTargetObject_x                                        0xEB77A8
#define pinstTargetSwitch_x                                        0xEB9C28
#define pinstTaskMember_x                                          0xE04CF0
#define pinstTrackTarget_x                                         0xEB7724
#define pinstTradeTarget_x                                         0xEB76DC
#define instTributeActive_x                                        0xE04E81
#define pinstViewActor_x                                           0xE0508C
#define pinstWorldData_x                                           0xEB7C08
#define pinstZoneAddr_x                                            0xEC7930
#define pinstPlayerPath_x                                          0xF693D8
#define pinstTargetIndicator_x                                     0xF6AD20
#define EQObject_Top_x                                             0xEB76C4

////
//Section 2:  UI Related Offsets
////
#define pinstCAAWnd_x                                              0xE057EC
#define pinstCAchievementsWnd_x                                    0xE057E8
#define pinstCActionsWnd_x                                         0xE057B0
#define pinstCAdvancedDisplayOptionsWnd_x                          0xE05020
#define pinstCAdvancedLootWnd_x                                    0xE04FE0
#define pinstCAdventureLeaderboardWnd_x                            0xF783B0
#define pinstCAdventureRequestWnd_x                                0xF78460
#define pinstCAdventureStatsWnd_x                                  0xF78510
#define pinstCAggroMeterWnd_x                                      0xE05540
#define pinstCAlarmWnd_x                                           0xE05848
#define pinstCAlertHistoryWnd_x                                    0xE05040
#define pinstCAlertStackWnd_x                                      0xE05850
#define pinstCAlertWnd_x                                           0xE04FC4
#define pinstCAltStorageWnd_x                                      0xF78870
#define pinstCAudioTriggersWindow_x                                0xCB9BA8
#define pinstCAuraWnd_x                                            0xE05064
#define pinstCAvaZoneWnd_x                                         0xE04FF8
#define pinstCBandolierWnd_x                                       0xE050D4
#define pinstCBankWnd_x                                            0xE05060
#define pinstCBarterMerchantWnd_x                                  0xF79AB0
#define pinstCBarterSearchWnd_x                                    0xF79B60
#define pinstCBarterWnd_x                                          0xF79C10
#define pinstCBazaarConfirmationWnd_x                              0xE05814
#define pinstCBazaarSearchWnd_x                                    0xE05588
#define pinstCBazaarWnd_x                                          0xE05830
#define pinstCBlockedBuffWnd_x                                     0xE05068
#define pinstCBlockedPetBuffWnd_x                                  0xE050C0
#define pinstCBodyTintWnd_x                                        0xE057C0
#define pinstCBookWnd_x                                            0xE05564
#define pinstCBreathWnd_x                                          0xE05804
#define pinstCBuffWindowNORMAL_x                                   0xE05044
#define pinstCBuffWindowSHORT_x                                    0xE05048
#define pinstCBugReportWnd_x                                       0xE05058
#define pinstCButtonWnd_x                                          0x15FD380
#define pinstCCastingWnd_x                                         0xE05558
#define pinstCCastSpellWnd_x                                       0xE05800
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE05834
#define pinstCChatWindowManager_x                                  0xF7A6D0
#define pinstCClaimWnd_x                                           0xF7A828
#define pinstCColorPickerWnd_x                                     0xE057B8
#define pinstCCombatAbilityWnd_x                                   0xE05840
#define pinstCCombatSkillsSelectWnd_x                              0xE04FC8
#define pinstCCompassWnd_x                                         0xE057B4
#define pinstCConfirmationDialog_x                                 0xF7F728
#define pinstCContainerMgr_x                                       0xE05828
#define pinstCContextMenuManager_x                                 0x15FD0D0
#define pinstCCursorAttachment_x                                   0xE0554C
#define pinstCDynamicZoneWnd_x                                     0xF7ADF0
#define pinstCEditLabelWnd_x                                       0xE0503C
#define pinstCEQMainWnd_x                                          0xF7B038
#define pinstCEventCalendarWnd_x                                   0xE05550
#define pinstCExtendedTargetWnd_x                                  0xE050B4
#define pinstCFacePick_x                                           0xE04FD8
#define pinstCFactionWnd_x                                         0xE05824
#define pinstCFellowshipWnd_x                                      0xF7B238
#define pinstCFileSelectionWnd_x                                   0xE05554
#define pinstCFindItemWnd_x                                        0xE05810
#define pinstCFindLocationWnd_x                                    0xF7B390
#define pinstCFriendsWnd_x                                         0xE04FDC
#define pinstCGemsGameWnd_x                                        0xE05820
#define pinstCGiveWnd_x                                            0xE0584C
#define pinstCGroupSearchFiltersWnd_x                              0xE0555C
#define pinstCGroupSearchWnd_x                                     0xF7B788
#define pinstCGroupWnd_x                                           0xF7B838
#define pinstCGuildBankWnd_x                                       0xEC8774
#define pinstCGuildCreationWnd_x                                   0xF7B998
#define pinstCGuildMgmtWnd_x                                       0xF7BA48
#define pinstCharacterCreation_x                                   0xE04FD0
#define pinstCHelpWnd_x                                            0xE05014
#define pinstCHeritageSelectionWnd_x                               0xE04FE4
#define pinstCHotButtonWnd_x                                       0xF7DBA0
#define pinstCHotButtonWnd1_x                                      0xF7DBA0
#define pinstCHotButtonWnd2_x                                      0xF7DBA4
#define pinstCHotButtonWnd3_x                                      0xF7DBA8
#define pinstCHotButtonWnd4_x                                      0xF7DBAC
#define pinstCIconSelectionWnd_x                                   0xE05548
#define pinstCInspectWnd_x                                         0xE05010
#define pinstCInventoryWnd_x                                       0xE04FE8
#define pinstCInvSlotMgr_x                                         0xE057E4
#define pinstCItemDisplayManager_x                                 0xF7E130
#define pinstCItemExpTransferWnd_x                                 0xF7E260
#define pinstCItemOverflowWnd_x                                    0xE0558C
#define pinstCJournalCatWnd_x                                      0xE05568
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE050B8
#define pinstCKeyRingWnd_x                                         0xE05030
#define pinstCLargeDialogWnd_x                                     0xF803A8
#define pinstCLayoutCopyWnd_x                                      0xF7E5B0
#define pinstCLFGuildWnd_x                                         0xF7E660
#define pinstCLoadskinWnd_x                                        0xE0582C
#define pinstCLootFiltersCopyWnd_x                                 0xCD61F8
#define pinstCLootFiltersWnd_x                                     0xE04FB8
#define pinstCLootSettingsWnd_x                                    0xE04FD4
#define pinstCLootWnd_x                                            0xE0556C
#define pinstCMailAddressBookWnd_x                                 0xE057F0
#define pinstCMailCompositionWnd_x                                 0xE057D0
#define pinstCMailIgnoreListWnd_x                                  0xE057F4
#define pinstCMailWnd_x                                            0xE057AC
#define pinstCManageLootWnd_x                                      0xE066B0
#define pinstCMapToolbarWnd_x                                      0xE0501C
#define pinstCMapViewWnd_x                                         0xE04FF4
#define pinstCMarketplaceWnd_x                                     0xE04FBC
#define pinstCMerchantWnd_x                                        0xE05570
#define pinstCMIZoneSelectWnd_x                                    0xF7EE98
#define pinstCMusicPlayerWnd_x                                     0xE05584
#define pinstCNameChangeMercWnd_x                                  0xE0580C
#define pinstCNameChangePetWnd_x                                   0xE057F8
#define pinstCNameChangeWnd_x                                      0xE0581C
#define pinstCNoteWnd_x                                            0xE04FFC
#define pinstCObjectPreviewWnd_x                                   0xE04FCC
#define pinstCOptionsWnd_x                                         0xE05000
#define pinstCPetInfoWnd_x                                         0xE05594
#define pinstCPetitionQWnd_x                                       0xE057D8
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE057C4
#define pinstCPlayerWnd_x                                          0xE05598
#define pinstCPopupWndManager_x                                    0xF7F728
#define pinstCProgressionSelectionWnd_x                            0xF7F7D8
#define pinstCPurchaseGroupWnd_x                                   0xE05008
#define pinstCPurchaseWnd_x                                        0xE04FEC
#define pinstCPvPLeaderboardWnd_x                                  0xF7F888
#define pinstCPvPStatsWnd_x                                        0xF7F938
#define pinstCQuantityWnd_x                                        0xE050BC
#define pinstCRaceChangeWnd_x                                      0xE05844
#define pinstCRaidOptionsWnd_x                                     0xE05560
#define pinstCRaidWnd_x                                            0xE057D4
#define pinstCRealEstateItemsWnd_x                                 0xE057E0
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE05574
#define pinstCRealEstateManageWnd_x                                0xE05018
#define pinstCRealEstateNeighborhoodWnd_x                          0xE05034
#define pinstCRealEstatePlotSearchWnd_x                            0xE0505C
#define pinstCRealEstatePurchaseWnd_x                              0xE050B0
#define pinstCRespawnWnd_x                                         0xE050AC
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE057FC
#define pinstCSendMoneyWnd_x                                       0xE04FC0
#define pinstCServerListWnd_x                                      0xE0513C
#define pinstCSkillsSelectWnd_x                                    0xE05838
#define pinstCSkillsWnd_x                                          0xE05818
#define pinstCSocialEditWnd_x                                      0xE05028
#define pinstCSocialWnd_x                                          0xE05808
#define pinstCSpellBookWnd_x                                       0xE0583C
#define pinstCStoryWnd_x                                           0xE0559C
#define pinstCTargetOfTargetWnd_x                                  0xF81760
#define pinstCTargetWnd_x                                          0xE050A8
#define pinstCTaskOverlayWnd_x                                     0xE05004
#define pinstCTaskSelectWnd_x                                      0xF818B8
#define pinstCTaskManager_x                                        0xCD6B38
#define pinstCTaskTemplateSelectWnd_x                              0xF81968
#define pinstCTaskWnd_x                                            0xF81A18
#define pinstCTextEntryWnd_x                                       0xE0504C
#define pinstCTimeLeftWnd_x                                        0xE057A8
#define pinstCTipWndCONTEXT_x                                      0xF81C1C
#define pinstCTipWndOFDAY_x                                        0xF81C18
#define pinstCTitleWnd_x                                           0xF81CC8
#define pinstCTrackingWnd_x                                        0xE04FF0
#define pinstCTradeskillWnd_x                                      0xF81E30
#define pinstCTradeWnd_x                                           0xE057CC
#define pinstCTrainWnd_x                                           0xE057C8
#define pinstCTributeBenefitWnd_x                                  0xF82030
#define pinstCTributeMasterWnd_x                                   0xF820E0
#define pinstCTributeTrophyWnd_x                                   0xF82190
#define pinstCVideoModesWnd_x                                      0xE055A0
#define pinstCVoiceMacroWnd_x                                      0xF6B488
#define pinstCVoteResultsWnd_x                                     0xE057DC
#define pinstCVoteWnd_x                                            0xE057BC
#define pinstCWebManager_x                                         0xF6BB04
#define pinstCZoneGuideWnd_x                                       0xE0500C
#define pinstCZonePathWnd_x                                        0xE05024

#define pinstEQSuiteTextureLoader_x                                0xCA40C0
#define pinstItemIconCache_x                                       0xF7AFF0
#define pinstLootFiltersManager_x                                  0xCD62A8
#define pinstRewardSelectionWnd_x                                  0xF80080

////
// Section 3: Miscellaneous Offsets
////
#define __CastRay_x                                                0x5B28C0
#define __CastRay2_x                                               0x5B2910
#define __ConvertItemTags_x                                        0x5CE470
#define __CleanItemTags_x                                          0x47D080
#define __CreateCascadeMenuItems_x                                 0x553280
#define __DoesFileExist_x                                          0x908710
#define __EQGetTime_x                                              0x905150
#define __ExecuteCmd_x                                             0x5AB0D0
#define __FixHeading_x                                             0x99FF00
#define __FlushDxKeyboard_x                                        0x6BC640
#define __GameLoop_x                                               0x6BF950
#define __get_bearing_x                                            0x5B2430
#define __get_melee_range_x                                        0x5B2B00
#define __GetAnimationCache_x                                      0x724D20
#define __GetGaugeValueFromEQ_x                                    0x8172F0
#define __GetLabelFromEQ_x                                         0x818DD0
#define __GetXTargetType_x                                         0x9A18E0
#define __HandleMouseWheel_x                                       0x6C0810
#define __HeadingDiff_x                                            0x99FF70
#define __HelpPath_x                                               0xF6682C
#define __LoadFrontEnd_x                                           0x6BCC70
#define __NewUIINI_x                                               0x816FC0
#define __ProcessGameEvents_x                                      0x6132E0
#define __ProcessKeyboardEvents_x                                  0x6BE1B0
#define __ProcessMouseEvents_x                                     0x612AA0
#define __SaveColors_x                                             0x553160
#define __STMLToText_x                                             0x943630
#define __ToggleKeyRingItem_x                                      0x5169A0
#define __WndProc_x                                                0x6BEC10
#define CMemoryMappedFile__SetFile_x                               0xA8F200
#define CrashDetected_x                                            0x6BE710
#define DrawNetStatus_x                                            0x63F2D0
#define Expansion_HoT_x                                            0xEC877C
#define Teleport_Table_Size_x                                      0xEB77B0
#define Teleport_Table_x                                           0xEB7C28
#define Util__FastTime_x                                           0x904D20
#define __eq_delete_x                                              0x9A834E
#define __eq_new_x                                                 0x9A8904

////
// Section 4: Function Offsets
////
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4903A0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4992A0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499070
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493930
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492D80

// AltAdvManager
#define AltAdvManager__GetCalculatedTimer_x                        0x55AD90
#define AltAdvManager__IsAbilityReady_x                            0x559CC0
#define AltAdvManager__GetAAById_x                                 0x559EC0
#define AltAdvManager__CanTrainAbility_x                           0x559F30
#define AltAdvManager__CanSeeAbility_x                             0x55A290

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA160
#define CharacterZoneClient__HasSkill_x                            0x4D5050
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6760
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE440
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BAA40
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D90C0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D91A0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9280
#define CharacterZoneClient__FindAffectSlot_x                      0x4C3240
#define CharacterZoneClient__BardCastBard_x                        0x4C5DA0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAB10
#define CharacterZoneClient__GetEffect_x                           0x4BA980
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C4290
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C4360
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C43B0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4500
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C46D0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B28D0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D76B0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7130

// CBankWnd
#define CBankWnd__GetNumBankSlots_x                                0x6E6480
#define CBankWnd__WndNotification_x                                0x6E6260

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6F3B90

// CButtonWnd
#define CButtonWnd__SetCheck_x                                     0x621C50
#define CButtonWnd__CButtonWnd_x                                   0x93F9E0
#define CButtonWnd__dCButtonWnd_x                                  0x93FCC0
#define CButtonWnd__vftable_x                                      0xB480C8

// CChatWindowManager
#define CChatWindowManager__GetRGBAFromIndex_x                     0x713E40
#define CChatWindowManager__InitContextMenu_x                      0x70CFA0
#define CChatWindowManager__FreeChatWindow_x                       0x712980
#define CChatWindowManager__GetLockedActiveChatWindow_x            0x4E8770
#define CChatWindowManager__SetLockedActiveChatWindow_x            0x713AC0
#define CChatWindowManager__CreateChatWindow_x                     0x712FC0

// ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8880

// CChatWindow
#define CChatWindow__CChatWindow_x                                 0x7146B0
#define CChatWindow__Clear_x                                       0x715970
#define CChatWindow__WndNotification_x                             0x716100
#define CChatWindow__AddHistory_x                                  0x715230

// CContextMenu
#define CContextMenu__CContextMenu_x                               0x953FD0
#define CContextMenu__dCContextMenu_x                              0x954200
#define CContextMenu__AddMenuItem_x                                0x954210
#define CContextMenu__RemoveMenuItem_x                             0x954520
#define CContextMenu__RemoveAllMenuItems_x                         0x954540
#define CContextMenu__CheckMenuItem_x                              0x9545C0
#define CContextMenu__SetMenuItem_x                                0x954440
#define CContextMenu__AddSeparator_x                               0x9543A0

// CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x954B60
#define CContextMenuManager__RemoveMenu_x                          0x954BD0
#define CContextMenuManager__PopupMenu_x                           0x954C90
#define CContextMenuManager__Flush_x                               0x954B00
#define CContextMenuManager__GetMenu_x                             0x49B490
#define CContextMenuManager__CreateDefaultMenu_x                   0x71F530

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8E0760
#define CChatService__GetFriendName_x                              0x8E0770

// CComboWnd
#define CComboWnd__DeleteAll_x                                     0x951440
#define CComboWnd__Draw_x                                          0x950940
#define CComboWnd__GetCurChoice_x                                  0x951280
#define CComboWnd__GetListRect_x                                   0x950DF0
#define CComboWnd__GetTextRect_x                                   0x9514B0
#define CComboWnd__InsertChoice_x                                  0x950F80
#define CComboWnd__SetColors_x                                     0x950F50
#define CComboWnd__SetChoice_x                                     0x951250
#define CComboWnd__GetItemCount_x                                  0x951290
#define CComboWnd__GetCurChoiceText_x                              0x9512D0
#define CComboWnd__GetChoiceText_x                                 0x9512A0
#define CComboWnd__InsertChoiceAtIndex_x                           0x951010

// CContainerWnd
#define CContainerWnd__HandleCombine_x                             0x71CF20
#define CContainerWnd__vftable_x                                   0xB1686C
#define CContainerWnd__SetContainer_x                              0x71E480

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54DB90
#define CDisplay__PreZoneMainUI_x                                  0x54DBA0
#define CDisplay__CleanGameUI_x                                    0x552F20
#define CDisplay__GetClickedActor_x                                0x545EB0
#define CDisplay__GetUserDefinedColor_x                            0x53E570
#define CDisplay__GetWorldFilePath_x                               0x547920
#define CDisplay__is3dON_x                                         0x542B10
#define CDisplay__ReloadUI_x                                       0x54D020
#define CDisplay__WriteTextHD2_x                                   0x542900
#define CDisplay__TrueDistance_x                                   0x5495E0
#define CDisplay__SetViewActor_x                                   0x5457D0
#define CDisplay__GetFloorHeight_x                                 0x542BD0
#define CDisplay__SetRenderWindow_x                                0x541530
#define CDisplay__ToggleScreenshotMode_x                           0x5452A0

// CEditBaseWnd
#define CEditBaseWnd__SetSel_x                                     0x973C00

// CEditWnd
#define CEditWnd__DrawCaret_x                                      0x957540
#define CEditWnd__GetCharIndexPt_x                                 0x958470
#define CEditWnd__GetDisplayString_x                               0x958310
#define CEditWnd__GetHorzOffset_x                                  0x956B70
#define CEditWnd__GetLineForPrintableChar_x                        0x959610
#define CEditWnd__GetSelStartPt_x                                  0x958720
#define CEditWnd__GetSTMLSafeText_x                                0x958130
#define CEditWnd__PointFromPrintableChar_x                         0x959240
#define CEditWnd__SelectableCharFromPoint_x                        0x9593B0
#define CEditWnd__SetEditable_x                                    0x9587F0
#define CEditWnd__SetWindowTextA_x                                 0x957EB0
#define CEditWnd__ReplaceSelection_x                               0x958EB0

// CEverQuest
#define CEverQuest__DoPercentConvert_x                             0x601010
#define CEverQuest__ClickedPlayer_x                                0x5F3020
#define CEverQuest__CreateTargetIndicator_x                        0x610580
#define CEverQuest__DeleteTargetIndicator_x                        0x610610
#define CEverQuest__DoTellWindow_x                                 0x4E8960
#define CEverQuest__OutputTextToLog_x                              0x4E8BE0
#define CEverQuest__DropHeldItemOnGround_x                         0x5E8060
#define CEverQuest__dsp_chat_x                                     0x4E8F70
#define CEverQuest__trimName_x                                     0x60C880
#define CEverQuest__Emote_x                                        0x601870
#define CEverQuest__EnterZone_x                                    0x5FB7F0
#define CEverQuest__GetBodyTypeDesc_x                              0x606140
#define CEverQuest__GetClassDesc_x                                 0x606780
#define CEverQuest__GetClassThreeLetterCode_x                      0x606D80
#define CEverQuest__GetDeityDesc_x                                 0x60EEC0
#define CEverQuest__GetLangDesc_x                                  0x606F40
#define CEverQuest__GetRaceDesc_x                                  0x606760
#define CEverQuest__InterpretCmd_x                                 0x60F490
#define CEverQuest__LeftClickedOnPlayer_x                          0x5EC260
#define CEverQuest__LMouseUp_x                                     0x5EA5F0
#define CEverQuest__RightClickedOnPlayer_x                         0x5ECB40
#define CEverQuest__RMouseUp_x                                     0x5EB570
#define CEverQuest__SetGameState_x                                 0x5E7DF0
#define CEverQuest__UPCNotificationFlush_x                         0x60C780
#define CEverQuest__IssuePetCommand_x                              0x608340
#define CEverQuest__ReportSuccessfulHit_x                          0x602BC0

// CGaugeWnd
// not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x72EDB0
#define CGaugeWnd__CalcLinesFillRect_x                             0x72EE10
#define CGaugeWnd__Draw_x                                          0x72E430

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF3B0
#define CGuild__GetGuildName_x                                     0x4AE490
#define CGuild__GetGuildIndex_x                                    0x4AE820

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton_x                               0x74A230

//CHotButton
#define CHotButton__SetButtonSize_x                                0x622010

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot_x                                 0x7571D0
#define CInvSlotMgr__MoveItem_x                                    0x755F30
#define CInvSlotMgr__SelectSlot_x                                  0x7572A0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7547B0
#define CInvSlot__SliderComplete_x                                 0x752510
#define CInvSlot__GetItemBase_x                                    0x751EB0
#define CInvSlot__UpdateItem_x                                     0x752020

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x758CF0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x757EA0
#define CInvSlotWnd__HandleLButtonUp_x                             0x758870

// CItemDisplayWnd
#define CItemDisplayWnd__SetSpell_x                                0x812660
#define CItemDisplayWnd__UpdateStrings_x                           0x767410
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x761180
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x7616A0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x767A10
#define CItemDisplayWnd__AboutToShow_x                             0x767070
#define CItemDisplayWnd__WndNotification_x                         0x768AF0
#define CItemDisplayWnd__RequestConvertItem_x                      0x7685B0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x7660D0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x766E90

// CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x84B120

// CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x76CFF0

// CLabel
#define CLabel__Draw_x                                             0x772AF0

// CListWnd
#define CListWnd__CListWnd_x                                       0x929B60
#define CListWnd__dCListWnd_x                                      0x929E80
#define CListWnd__vftable_x                                        0xB47998
#define CListWnd__AddColumn_x                                      0x92E300
#define CListWnd__AddColumn1_x                                     0x92E350
#define CListWnd__AddLine_x                                        0x92E6E0
#define CListWnd__AddString_x                                      0x92E4E0
#define CListWnd__CalculateFirstVisibleLine_x                      0x92E0C0
#define CListWnd__CalculateVSBRange_x                              0x92DEB0
#define CListWnd__ClearSel_x                                       0x92EEC0
#define CListWnd__ClearAllSel_x                                    0x92EF20
#define CListWnd__CloseAndUpdateEditWindow_x                       0x92F930
#define CListWnd__Compare_x                                        0x92D7E0
#define CListWnd__Draw_x                                           0x929FB0
#define CListWnd__DrawColumnSeparators_x                           0x92C7B0
#define CListWnd__DrawHeader_x                                     0x92CC20
#define CListWnd__DrawItem_x                                       0x92D120
#define CListWnd__DrawLine_x                                       0x92C920
#define CListWnd__DrawSeparator_x                                  0x92C850
#define CListWnd__EnableLine_x                                     0x92C080
#define CListWnd__EnsureVisible_x                                  0x92F850
#define CListWnd__ExtendSel_x                                      0x92EDF0
#define CListWnd__GetColumnTooltip_x                               0x92BBC0
#define CListWnd__GetColumnMinWidth_x                              0x92BC30
#define CListWnd__GetColumnWidth_x                                 0x92BB30
#define CListWnd__GetCurSel_x                                      0x92B4C0
#define CListWnd__GetItemAtPoint_x                                 0x92C300
#define CListWnd__GetItemAtPoint1_x                                0x92C370
#define CListWnd__GetItemData_x                                    0x92B540
#define CListWnd__GetItemHeight_x                                  0x92B900
#define CListWnd__GetItemIcon_x                                    0x92B6D0
#define CListWnd__GetItemRect_x                                    0x92C170
#define CListWnd__GetItemText_x                                    0x92B580
#define CListWnd__GetSelList_x                                     0x92EF70
#define CListWnd__GetSeparatorRect_x                               0x92C5B0
#define CListWnd__InsertLine_x                                     0x92EAD0
#define CListWnd__RemoveLine_x                                     0x92EC20
#define CListWnd__SetColors_x                                      0x92DE80
#define CListWnd__SetColumnJustification_x                         0x92DBB0
#define CListWnd__SetColumnWidth_x                                 0x92DAD0
#define CListWnd__SetCurSel_x                                      0x92ED30
#define CListWnd__SetItemColor_x                                   0x92F500
#define CListWnd__SetItemData_x                                    0x92F4C0
#define CListWnd__SetItemText_x                                    0x92F0E0
#define CListWnd__ShiftColumnSeparator_x                           0x92DC70
#define CListWnd__Sort_x                                           0x92D960
#define CListWnd__ToggleSel_x                                      0x92ED60
#define CListWnd__SetColumnsSizable_x                              0x92DD20
#define CListWnd__SetItemWnd_x                                     0x92F390
#define CListWnd__GetItemWnd_x                                     0x92B720
#define CListWnd__SetItemIcon_x                                    0x92F160
#define CListWnd__CalculateCustomWindowPositions_x                 0x92E1C0
#define CListWnd__SetVScrollPos_x                                  0x92DAB0

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd_x                                 0x788320

// MapViewMap
#define MapViewMap__MapViewMap_x                                   0x783820
#define MapViewMap__dMapViewMap_x                                  0x783960
#define MapViewMap__vftable_x                                      0xB1E058
#define MapViewMap__Clear_x                                        0x784190
#define MapViewMap__SaveEx_x                                       0x787550
#define MapViewMap__SetZoom_x                                      0x78BC10
#define MapViewMap__HandleLButtonDown_x                            0x783A70
#define MapViewMap__GetWorldCoordinates_x                          0x786A30

// CMerchantWnd
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A8450
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A8D30
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A9260
#define CMerchantWnd__SelectRecoverySlot_x                         0x7AC1E0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A6FB0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7B1D90
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A8060

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8AE3A0
#define CPacketScrambler__hton_x                                   0x8AE390

// CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x94CFF0
#define CSidlManagerBase__CreatePageWnd_x                          0x94C800
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x948AB0
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x948A40
#define CSidlManagerBase__FindAnimation1_x                         0x948C90
#define CSidlManagerBase__FindScreenPieceTemplate_x                0x9490A0
#define CSidlManagerBase__FindScreenPieceTemplate1_x               0x948E90
#define CSidlManagerBase__CreateLabel_x                            0x809B00
#define CSidlManagerBase__CreateXWndFromTemplate_x                 0x94C000
#define CSidlManagerBase__CreateXWndFromTemplate1_x                0x94C1D0
#define CSidlManagerBase__CreateXWnd_x                             0x809A30

// CSidlManager
#define CSidlManager__CreateHotButtonWnd_x                         0x809FE0

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateHSBRange_x                        0x945750
#define CSidlScreenWnd__CalculateVSBRange_x                        0x945650
#define CSidlScreenWnd__ConvertToRes_x                             0x96AC30
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x9450F0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x944DE0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x944EB0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x944F80
#define CSidlScreenWnd__DrawSidlPiece_x                            0x945BF0
#define CSidlScreenWnd__EnableIniStorage_x                         0x9460C0
#define CSidlScreenWnd__GetChildItem_x                             0x946040
#define CSidlScreenWnd__GetSidlPiece_x                             0x945DE0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x935720
#define CSidlScreenWnd__Init1_x                                    0x9449E0
#define CSidlScreenWnd__LoadIniInfo_x                              0x946110
#define CSidlScreenWnd__LoadIniListWnd_x                           0x946C50
#define CSidlScreenWnd__LoadSidlScreen_x                           0x943DE0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15FCFA0
#define CSidlScreenWnd__StoreIniInfo_x                             0x9467D0
#define CSidlScreenWnd__StoreIniVis_x                              0x946B30
#define CSidlScreenWnd__vftable_x                                  0xB48368
#define CSidlScreenWnd__WndNotification_x                          0x945B00

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6867E0
#define CSkillMgr__GetSkillCap_x                                   0x6869C0
#define CSkillMgr__GetNameToken_x                                  0x685F60
#define CSkillMgr__IsActivatedSkill_x                              0x6860A0
#define CSkillMgr__IsCombatSkill_x                                 0x685FE0

// CSliderWnd
#define CSliderWnd__GetValue_x                                     0x955950
#define CSliderWnd__SetValue_x                                     0x9557C0
#define CSliderWnd__SetNumTicks_x                                  0x955820

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet_x                               0x80FAF0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x95E150
#define CStmlWnd__CalculateHSBRange_x                              0x95F230
#define CStmlWnd__CalculateVSBRange_x                              0x95F1A0
#define CStmlWnd__CanBreakAtCharacter_x                            0x963560
#define CStmlWnd__FastForwardToEndOfTag_x                          0x9641F0
#define CStmlWnd__ForceParseNow_x                                  0x95E6F0
#define CStmlWnd__GetNextTagPiece_x                                0x9634C0
#define CStmlWnd__GetSTMLText_x                                    0x5061F0
#define CStmlWnd__GetVisibleText_x                                 0x95E710
#define CStmlWnd__InitializeWindowVariables_x                      0x964040
#define CStmlWnd__MakeStmlColorTag_x                               0x95D7C0
#define CStmlWnd__MakeWndNotificationTag_x                         0x95D830
#define CStmlWnd__SetSTMLText_x                                    0x95C870
#define CStmlWnd__StripFirstSTMLLines_x                            0x9652F0
#define CStmlWnd__UpdateHistoryString_x                            0x964400

// CTabWnd
#define CTabWnd__Draw_x                                            0x95B9C0
#define CTabWnd__DrawCurrentPage_x                                 0x95C0F0
#define CTabWnd__DrawTab_x                                         0x95BE10
#define CTabWnd__GetCurrentPage_x                                  0x95B1D0
#define CTabWnd__GetPageInnerRect_x                                0x95B410
#define CTabWnd__GetTabInnerRect_x                                 0x95B350
#define CTabWnd__GetTabRect_x                                      0x95B200
#define CTabWnd__InsertPage_x                                      0x95B620
#define CTabWnd__SetPage_x                                         0x95B490
#define CTabWnd__SetPageRect_x                                     0x95B900
#define CTabWnd__UpdatePage_x                                      0x95BCD0
#define CTabWnd__GetPageFromTabIndex_x                             0x95BD50
#define CTabWnd__GetCurrentTabIndex_x                              0x95B1C0

// CPageWnd
#define CPageWnd__GetTabText_x                                     0x76D3C0
#define CPageWnd__SetTabText_x                                     0x95AD20

// CTextOverlay
#define CTextOverlay__DisplayText_x                                0x4A90C0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x9325F0
#define CTextureFont__GetTextExtent_x                              0x9327B0

// CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B9B20
#define CHtmlComponentWnd__ValidateUri_x                           0x74BC20
#define CHtmlWnd__SetClientCallbacks_x                             0x6270A0
#define CHtmlWnd__AddObserver_x                                    0x6270C0
#define CHtmlWnd__RemoveObserver_x                                 0x627120
#define Window__getProgress_x                                      0x8639F0
#define Window__getStatus_x                                        0x863A10
#define Window__getURI_x                                           0x863A20

// CXMLDataManager
#define CXMLDataManager__GetXMLData_x                              0x970690

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead_x                             0x91F790

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr_x                                             0x4E85B0
#define CXStr__CXStr1_x                                            0x4B6350
#define CXStr__CXStr3_x                                            0x901250
#define CXStr__dCXStr_x                                            0x478740
#define CXStr__operator_equal_x                                    0x901480
#define CXStr__operator_equal1_x                                   0x9014C0
#define CXStr__operator_plus_equal1_x                              0x901F50
#define CXStr__SetString_x                                         0x903E40
#define CXStr__operator_char_p_x                                   0x901990
#define CXStr__GetChar_x                                           0x903770
#define CXStr__Delete_x                                            0x903040
#define CXStr__GetUnicode_x                                        0x9037E0
#define CXStr__GetLength_x                                         0x47D430
#define CXStr__Mid_x                                               0x47D440
#define CXStr__Insert_x                                            0x903840
#define CXStr__FindNext_x                                          0x9034B0
#define CXStr__gFreeLists_x                                        0xCA2518
#define CXStr__gCXStrAccess_x                                      0x15FC6C4

// CTileLayoutWnd
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x953BE0

// CXWnd
#define CXWnd__BringToTop_x                                        0x938E80
#define CXWnd__Center_x                                            0x938A00
#define CXWnd__ClrFocus_x                                          0x938820
#define CXWnd__Destroy_x                                           0x9388C0
#define CXWnd__DoAllDrawing_x                                      0x934ED0
#define CXWnd__DrawChildren_x                                      0x934EA0
#define CXWnd__DrawColoredRect_x                                   0x935310
#define CXWnd__DrawTooltip_x                                       0x9339F0
#define CXWnd__DrawTooltipAtPoint_x                                0x933AB0
#define CXWnd__GetBorderFrame_x                                    0x935170
#define CXWnd__GetChildItem_x                                      0x939080
#define CXWnd__GetChildWndAt_x                                     0x938F20
#define CXWnd__GetClientClipRect_x                                 0x937150
#define CXWnd__GetScreenClipRect_x                                 0x937220
#define CXWnd__GetScreenRect_x                                     0x9373E0
#define CXWnd__GetTooltipRect_x                                    0x935360
#define CXWnd__GetWindowTextA_x                                    0x49CC00
#define CXWnd__IsActive_x                                          0x935A90
#define CXWnd__IsDescendantOf_x                                    0x937DC0
#define CXWnd__IsReallyVisible_x                                   0x937DF0
#define CXWnd__IsType_x                                            0x939590
#define CXWnd__Minimize_x                                          0x9384B0
#define CXWnd__Move_x                                              0x937E70
#define CXWnd__Move1_x                                             0x937F20
#define CXWnd__ProcessTransition_x                                 0x9389B0
#define CXWnd__Refade_x                                            0x9381E0
#define CXWnd__Resize_x                                            0x938440
#define CXWnd__Right_x                                             0x938C40
#define CXWnd__SetFocus_x                                          0x9387E0
#define CXWnd__SetFont_x                                           0x938850
#define CXWnd__SetKeyTooltip_x                                     0x9393A0
#define CXWnd__SetMouseOver_x                                      0x9362D0
#define CXWnd__SetParent_x                                         0x937B70
#define CXWnd__StartFade_x                                         0x937CA0
#define CXWnd__vftable_x                                           0xB47DE4
#define CXWnd__CXWnd_x                                             0x932AE0
#define CXWnd__dCXWnd_x                                            0x933000 

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x96BCC0

// CXWndManager
#define CXWndManager__DrawCursor_x                                 0x93BDE0
#define CXWndManager__DrawWindows_x                                0x93BE00
#define CXWndManager__GetKeyboardFlags_x                           0x93E5D0
#define CXWndManager__HandleKeyboardMsg_x                          0x93E190
#define CXWndManager__RemoveWnd_x                                  0x93E7F0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x93ED60

// CDBStr
#define CDBStr__GetString_x                                        0x53D520

// CharacterZoneClient
#define CharacterZoneClient__CastSpell_x                           0x4BBA20
#define CharacterZoneClient__Cur_HP_x                              0x4D2090
#define CharacterZoneClient__Cur_Mana_x                            0x4D9780
#define CharacterZoneClient__GetCastingTimeModifier_x              0x4BEA90
#define CharacterZoneClient__GetFocusCastingTimeModifier_x         0x4B2510
#define CharacterZoneClient__GetFocusRangeModifier_x               0x4B2660
#define CharacterZoneClient__GetHPRegen_x                          0x4DF520
#define CharacterZoneClient__GetEnduranceRegen_x                   0x4DFB20
#define CharacterZoneClient__GetManaRegen_x                        0x4DFF60
#define CharacterZoneClient__Max_Endurance_x                       0x64D400
#define CharacterZoneClient__Max_HP_x                              0x4D1EC0
#define CharacterZoneClient__Max_Mana_x                            0x64D200
#define CharacterZoneClient__doCombatAbility_x                     0x64F860
#define CharacterZoneClient__UseSkill_x                            0x4E1D40
#define CharacterZoneClient__IsExpansionFlag_x                     0x5A98B0
#define CharacterZoneClient__TotalEffect_x                         0x4C54E0
#define CharacterZoneClient__GetPCSpellAffect_x                    0x4BF7E0
#define CharacterZoneClient__SpellDuration_x                       0x4BF310
#define CharacterZoneClient__GetAdjustedSkill_x                    0x4D4E10
#define CharacterZoneClient__GetBaseSkill_x                        0x4D5DB0
#define CharacterZoneClient__CanUseItem_x                          0x4D9A90

// ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8CD6F0

// PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x663950

// PcClient
#define PcClient__PcClient_x                                       0x6439E0
#define PcClient__GetConLevel_x                                    0x6462A0

// CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B9690
#define CCharacterListWnd__EnterWorld_x                            0x4B90D0
#define CCharacterListWnd__Quit_x                                  0x4B8E20
#define CCharacterListWnd__UpdateList_x                            0x4B9260

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6282D0
#define EQ_Item__CreateItemTagString_x                             0x8A7C00
#define EQ_Item__IsStackable_x                                     0x8AC770
#define EQ_Item__GetImageNum_x                                     0x8A9680
#define EQ_Item__CreateItemClient_x                                0x6274A0
#define EQ_Item__GetItemValue_x                                    0x8AA9B0
#define EQ_Item__ValueSellMerchant_x                               0x8ADF80
#define EQ_Item__IsKeyRingItem_x                                   0x8AC090
#define EQ_Item__CanGoInBag_x                                      0x6283F0
#define EQ_Item__IsEmpty_x                                         0x8ABBE0
#define EQ_Item__GetMaxItemCount_x                                 0x8AADC0
#define EQ_Item__GetHeldItem_x                                     0x8A9550
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A7580
#define ItemClient__ItemClient_x                                   0x5A7C80
#define ItemClient__dItemClient_x                                  0x6273F0

// EQ_LoadingS
#define EQ_LoadingS__SetProgressBar_x                              0x55BAA0
#define EQ_LoadingS__Array_x                                       0xC2BB60

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x64DD60
#define EQ_PC__GetAlternateAbilityId_x                             0x8B71E0
#define EQ_PC__GetCombatAbility_x                                  0x8B7850
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B78C0
#define EQ_PC__GetItemRecastTimer_x                                0x64FDE0
#define EQ_PC__HasLoreItem_x                                       0x646A60
#define EQ_PC__AlertInventoryChanged_x                             0x645BE0
#define EQ_PC__GetPcZoneClient_x                                   0x6723D0
#define EQ_PC__RemoveMyAffect_x                                    0x653020
#define EQ_PC__GetKeyRingItems_x                                   0x8B8150
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B7EE0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B8450

// EQItemList
#define EQItemList__EQItemList_x                                   0x5AFDE0
#define EQItemList__add_object_x                                   0x5DD840
#define EQItemList__add_item_x                                     0x5B0340
#define EQItemList__delete_item_x                                  0x5B0390
#define EQItemList__FreeItemList_x                                 0x5B0290

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x53A010

// EQPlayer
#define EQPlayer__ChangeBoneStringSprite_x                         0x6651D0
#define EQPlayer__dEQPlayer_x                                      0x658530
#define EQPlayer__DoAttack_x                                       0x66D060
#define EQPlayer__EQPlayer_x                                       0x658BF0
#define EQPlayer__SetNameSpriteState_x                             0x65CEC0
#define EQPlayer__SetNameSpriteTint_x                              0x65DD80
#define PlayerBase__HasProperty_j_x                                0x99E310
#define EQPlayer__IsTargetable_x                                   0x99E7B0
#define EQPlayer__CanSee_x                                         0x99E610
#define EQPlayer__CanSee1_x                                        0x99E6E0
#define PlayerBase__GetVisibilityLineSegment_x                     0x99E3D0

// PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x66FE60
#define PlayerZoneClient__GetLevel_x                               0x672410
#define PlayerZoneClient__IsValidTeleport_x                        0x5DE9B0
#define PlayerZoneClient__LegalPlayerRace_x                        0x554DE0

// EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x667F20
#define EQPlayerManager__GetSpawnByName_x                          0x667FD0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x668060

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x62B9A0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x62BA20
#define KeypressHandler__AttachKeyToEqCommand_x                    0x62BA60
#define KeypressHandler__ClearCommandStateArray_x                  0x62CE70
#define KeypressHandler__HandleKeyDown_x                           0x62CE90
#define KeypressHandler__HandleKeyUp_x                             0x62CF30
#define KeypressHandler__SaveKeymapping_x                          0x62D380

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8CB610

// StringTable
#define StringTable__getString_x                                   0x8C6490

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x652C90
#define PcZoneClient__RemovePetEffect_x                            0x6532C0
#define PcZoneClient__HasAlternateAbility_x                        0x64D030
#define PcZoneClient__GetCurrentMod_x                              0x4E4DF0
#define PcZoneClient__GetModCap_x                                  0x4E4CF0
#define PcZoneClient__CanEquipItem_x                               0x64D700
#define PcZoneClient__GetItemByID_x                                0x650260
#define PcZoneClient__GetItemByItemClass_x                         0x6503B0
#define PcZoneClient__RemoveBuffEffect_x                           0x6532E0
#define PcZoneClient__BandolierSwap_x                              0x64E320
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64FD80

// Doors
#define EQSwitch__UseSwitch_x                                      0x5E34A0

// IconCache
#define IconCache__GetIcon_x                                       0x7245C0

// CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x71C0B0
#define CContainerMgr__CloseContainer_x                            0x71C380
#define CContainerMgr__OpenExperimentContainer_x                   0x71CE00

// CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7DC1E0

// CHelpWnd
#define CHelpWnd__SetFile_x                                        0x620450

// CLootWnd
#define CLootWnd__LootAll_x                                        0x77A640
#define CLootWnd__RequestLootSlot_x                                0x779870

// EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x57BCD0
#define EQ_Spell__SpellAffects_x                                   0x57C140
#define EQ_Spell__SpellAffectBase_x                                0x57BF00
#define EQ_Spell__IsStackable_x                                    0x4C9AB0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9960
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B69F0
#define EQ_Spell__IsSPAStacking_x                                  0x57CF90
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x57C4A0
#define EQ_Spell__IsNoRemove_x                                     0x4C9A90
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57CFA0
#define __IsResEffectSpell_x                                       0x4C8F00

// EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD0F0

// EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D5C20

// CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x822D70
#define CTargetWnd__WndNotification_x                              0x822600
#define CTargetWnd__RefreshTargetBuffs_x                           0x8228D0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x821770

// CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x827360

// CTaskManager
#define CTaskManager__GetEntry_x                                   0x537A20
#define CTaskManager__HandleMessage_x                              0x535EC0
#define CTaskManager__GetTaskStatus_x                              0x537AD0
#define CTaskManager__GetElementDescription_x                      0x537B50

// EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5771C0
#define EqSoundManager__PlayScriptMp3_x                            0x577320
#define EqSoundManager__SoundAssistPlay_x                          0x68A740
#define EqSoundManager__WaveInstancePlay_x                         0x689CB0

// CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52B820

// CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x95A230

// CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x563480
#define CAltAbilityData__GetMercMaxRank_x                          0x563410
#define CAltAbilityData__GetMaxRank_x                              0x558B40

// CTargetRing
#define CTargetRing__Cast_x                                        0x61E570

// CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9940
#define CharacterBase__CreateItemGlobalIndex_x                     0x513000
#define CharacterBase__CreateItemIndex_x                           0x626650
#define CharacterBase__GetItemPossession_x                         0x4FEB70
#define CharacterBase__GetItemByGlobalIndex_x                      0x8DE230
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8DE290

// CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x703220
#define CCastSpellWnd__IsBardSongPlaying_x                         0x703A50
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x703B00

// messages
#define msg_spell_worn_off_x                                       0x5A1AB0
#define msg_new_text_x                                             0x596850
#define __msgTokenTextParam_x                                      0x5A3FE0
#define msgTokenText_x                                             0x5A4230

// SpellManager
#define SpellManager__vftable_x                                    0xAF0694
#define SpellManager__SpellManager_x                               0x68DA70
#define Spellmanager__LoadTextSpells_x                             0x68E360
#define SpellManager__GetSpellByGroupAndRank_x                     0x68DC40

// CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x 0x9A21D0

// ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D65C0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D6840

// CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x772E30

// CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x7207C0
#define CCursorAttachment__AttachToCursor1_x                       0x720800
#define CCursorAttachment__Deactivate_x                            0x7217F0

// CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x96A1E0
#define CEQSuiteTextureLoader__GetTexture_x                        0x969EA0

// CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x510570
#define CFindItemWnd__WndNotification_x                            0x511050
#define CFindItemWnd__Update_x                                     0x511BC0
#define CFindItemWnd__PickupSelectedItem_x                         0x50FDB0

// IString
#define IString__Append_x                                          0x4F1480

// Camera
#define CDisplay__cameraType_x                                     0xE055A4
#define EverQuest__Cameras_x                                       0xEC8ACC

// LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x518D40
#define LootFiltersManager__GetItemFilterData_x                    0x518640
#define LootFiltersManager__RemoveItemLootFilter_x                 0x518670
#define LootFiltersManager__SetItemLootFilter_x                    0x518890

// COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7CA1D0

// CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A7DC0
#define CResolutionHandler__GetWindowedStyle_x                     0x685210

// CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x718E10

// CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8EB8A0
#define CDistillerInfo__Instance_x                                 0x8EB840

// CGroupWnd
#define CGroupWnd__WndNotification_x                               0x739020
#define CGroupWnd__UpdateDisplay_x                                 0x738380

// ItemBase
#define ItemBase__IsLore_x                                         0x8AC140
#define ItemBase__IsLoreEquipped_x                                 0x8AC1B0

// EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5DD7A0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5DD8E0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5DD940

// RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x67AB00
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x67E4A0

// CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x506860

// FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F33A0
#define FactionManagerClient__HandleFactionMessage_x               0x4F3A10
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F3FD0
#define FactionManagerClient__GetMaxFaction_x                      0x4F3FEF
#define FactionManagerClient__GetMinFaction_x                      0x4F3FA0

// BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FEB40

// ArrayClass
#define ArrayClass__DeleteElement_x                                0x9315A0

// AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BF10

// ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FEDD0

// MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x562930

// CTargetManager
#define CTargetManager__Get_x                                      0x6912C0

// RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x67AB00

// CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8E80

// EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5B0230

// EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF66160

// KeyCombo
#define KeyCombo__GetTextDescription_x                             0x91BEA0
