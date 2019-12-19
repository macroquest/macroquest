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
#define __ExpectedVersionDate                                     "Dec 11 2019"
#define __ExpectedVersionTime                                     "13:24:57"
#define __ActualVersionDate_x                                      0xB0D664
#define __ActualVersionTime_x                                      0xB0D658
#define __ActualVersionBuild_x                                     0xAF933C

// Memory Protection
#define __MemChecker0_x                                            0x631BC0
#define __MemChecker1_x                                            0x905500
#define __MemChecker2_x                                            0x6C0250
#define __MemChecker3_x                                            0x6C01A0
#define __MemChecker4_x                                            0x85C2A0
#define __EncryptPad0_x                                            0xC443E8
#define __EncryptPad1_x                                            0xCA25E8
#define __EncryptPad2_x                                            0xC54C80
#define __EncryptPad3_x                                            0xC54880
#define __EncryptPad4_x                                            0xC92C00
#define __EncryptPad5_x                                            0xF6E210
#define __AC1_x                                                    0x818DF6
#define __AC2_x                                                    0x5EB9DF
#define __AC3_x                                                    0x5F30DF
#define __AC4_x                                                    0x5F70B0
#define __AC5_x                                                    0x5FD3BF
#define __AC6_x                                                    0x6019D6
#define __AC7_x                                                    0x5EB450
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
#define __do_loot_x                                                0x5B7250
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
#define __gfMaxZoomCameraDistance_x                                0xB02FD0
#define __gfMaxCameraDistance_x                                    0xB2F51C
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
#define __CastRay_x                                                0x5B26B0
#define __CastRay2_x                                               0x5B2700
#define __ConvertItemTags_x                                        0x5CE250
#define __CleanItemTags_x                                          0x47CFE0
#define __DoesFileExist_x                                          0x9085E0
#define __EQGetTime_x                                              0x904FD0
#define __ExecuteCmd_x                                             0x5AAF10
#define __FixHeading_x                                             0x99F9A0
#define __GameLoop_x                                               0x6BF440
#define __get_bearing_x                                            0x5B2220
#define __get_melee_range_x                                        0x5B28F0
#define __GetAnimationCache_x                                      0x7248A0
#define __GetGaugeValueFromEQ_x                                    0x8172A0
#define __GetLabelFromEQ_x                                         0x818D80
#define __GetXTargetType_x                                         0x9A13F0
#define __HandleMouseWheel_x                                       0x6C0300
#define __HeadingDiff_x                                            0x99FA10
#define __HelpPath_x                                               0xF6682C
#define __LoadFrontEnd_x                                           0x6BC760
#define __NewUIINI_x                                               0x816F70
#define __ProcessGameEvents_x                                      0x6131A0
#define __ProcessMouseEvent_x                                      0x612960
#define __SaveColors_x                                             0x553430
#define __STMLToText_x                                             0x942FE0
#define __ToggleKeyRingItem_x                                      0x516830
#define CMemoryMappedFile__SetFile_x                               0xA8ED00
#define CrashDetected_x                                            0x6BE200
#define DrawNetStatus_x                                            0x63F040
#define Expansion_HoT_x                                            0xEC877C
#define Teleport_Table_Size_x                                      0xEB77B0
#define Teleport_Table_x                                           0xEB7C28
#define Util__FastTime_x                                           0x904BA0
#define __eq_delete_x                                              0x9A7E3E
#define __eq_new_x                                                 0x9A83F4

////
// Section 4: Function Offsets
////
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4901E0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4990F0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x498EC0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493780
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492BD0

// AltAdvManager
#define AltAdvManager__GetCalculatedTimer_x                        0x55AFB0
#define AltAdvManager__IsAbilityReady_x                            0x559EE0
#define AltAdvManager__GetAAById_x                                 0x55A0E0
#define AltAdvManager__CanTrainAbility_x                           0x55A150
#define AltAdvManager__CanSeeAbility_x                             0x55A4B0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C9E90
#define CharacterZoneClient__HasSkill_x                            0x4D4D80
#define CharacterZoneClient__MakeMeVisible_x                       0x4D64A0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE080
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BA690
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8E40
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D8F20
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9000
#define CharacterZoneClient__FindAffectSlot_x                      0x4C2E80
#define CharacterZoneClient__BardCastBard_x                        0x4C59E0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BA760
#define CharacterZoneClient__GetEffect_x                           0x4BA5D0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C3ED0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C3FA0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C3FF0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4140
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4310
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2570
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7400
#define CharacterZoneClient__FindItemByRecord_x                    0x4D6E80

// CBankWnd
#define CBankWnd__GetNumBankSlots_x                                0x6E5EB0
#define CBankWnd__WndNotification_x                                0x6E5C90

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6F3620

// CButtonWnd
#define CButtonWnd__SetCheck_x                                     0x621A90
#define CButtonWnd__CButtonWnd_x                                   0x93F3E0
#define CButtonWnd__dCButtonWnd_x                                  0x93F6B0
#define CButtonWnd__vftable_x                                      0xB480C8

// CChatWindowManager
#define CChatWindowManager__GetRGBAFromIndex_x                     0x713950
#define CChatWindowManager__InitContextMenu_x                      0x70CAA0
#define CChatWindowManager__FreeChatWindow_x                       0x712490
#define CChatWindowManager__GetLockedActiveChatWindow_x            0x4E84D0
#define CChatWindowManager__SetLockedActiveChatWindow_x            0x7135D0
#define CChatWindowManager__CreateChatWindow_x                     0x712AD0

// ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E85E0

// CChatWindow
#define CChatWindow__CChatWindow_x                                 0x714200
#define CChatWindow__Clear_x                                       0x7154D0
#define CChatWindow__WndNotification_x                             0x715C60
#define CChatWindow__AddHistory_x                                  0x714D90

// CContextMenu
#define CContextMenu__CContextMenu_x                               0x953990
#define CContextMenu__dCContextMenu_x                              0x953BD0
#define CContextMenu__AddMenuItem_x                                0x953BE0
#define CContextMenu__RemoveMenuItem_x                             0x953EF0
#define CContextMenu__RemoveAllMenuItems_x                         0x953F10
#define CContextMenu__CheckMenuItem_x                              0x953F90
#define CContextMenu__SetMenuItem_x                                0x953E10
#define CContextMenu__AddSeparator_x                               0x953D70

// CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x954530
#define CContextMenuManager__RemoveMenu_x                          0x9545A0
#define CContextMenuManager__PopupMenu_x                           0x954660
#define CContextMenuManager__Flush_x                               0x9544D0
#define CContextMenuManager__GetMenu_x                             0x49B240
#define CContextMenuManager__CreateDefaultMenu_x                   0x71F0A0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8E0580
#define CChatService__GetFriendName_x                              0x8E0590

// CComboWnd
#define CComboWnd__DeleteAll_x                                     0x950DF0
#define CComboWnd__Draw_x                                          0x9502E0
#define CComboWnd__GetCurChoice_x                                  0x950C30
#define CComboWnd__GetListRect_x                                   0x950790
#define CComboWnd__GetTextRect_x                                   0x950E60
#define CComboWnd__InsertChoice_x                                  0x950920
#define CComboWnd__SetColors_x                                     0x9508F0
#define CComboWnd__SetChoice_x                                     0x950C00
#define CComboWnd__GetItemCount_x                                  0x950C40
#define CComboWnd__GetCurChoiceText_x                              0x950C80
#define CComboWnd__GetChoiceText_x                                 0x950C50
#define CComboWnd__InsertChoiceAtIndex_x                           0x9509C0

// CContainerWnd
#define CContainerWnd__HandleCombine_x                             0x71CA80
#define CContainerWnd__vftable_x                                   0xB1685C
#define CContainerWnd__SetContainer_x                              0x71DFF0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54DE60
#define CDisplay__PreZoneMainUI_x                                  0x54DE70
#define CDisplay__CleanGameUI_x                                    0x5531F0
#define CDisplay__GetClickedActor_x                                0x546180
#define CDisplay__GetUserDefinedColor_x                            0x53E840
#define CDisplay__GetWorldFilePath_x                               0x547BF0
#define CDisplay__is3dON_x                                         0x542DE0
#define CDisplay__ReloadUI_x                                       0x54D2F0
#define CDisplay__WriteTextHD2_x                                   0x542BD0
#define CDisplay__TrueDistance_x                                   0x5498B0
#define CDisplay__SetViewActor_x                                   0x545AA0
#define CDisplay__GetFloorHeight_x                                 0x542EA0
#define CDisplay__SetRenderWindow_x                                0x541800
#define CDisplay__ToggleScreenshotMode_x                           0x545570

// CEditBaseWnd
#define CEditBaseWnd__SetSel_x                                     0x973640

// CEditWnd
#define CEditWnd__DrawCaret_x                                      0x956F00
#define CEditWnd__GetCharIndexPt_x                                 0x957E30
#define CEditWnd__GetDisplayString_x                               0x957CD0
#define CEditWnd__GetHorzOffset_x                                  0x956530
#define CEditWnd__GetLineForPrintableChar_x                        0x958FD0
#define CEditWnd__GetSelStartPt_x                                  0x9580E0
#define CEditWnd__GetSTMLSafeText_x                                0x957AF0
#define CEditWnd__PointFromPrintableChar_x                         0x958C00
#define CEditWnd__SelectableCharFromPoint_x                        0x958D70
#define CEditWnd__SetEditable_x                                    0x9581B0
#define CEditWnd__SetWindowTextA_x                                 0x957870
#define CEditWnd__ReplaceSelection_x                               0x958870

// CEverQuest
#define CEverQuest__DoPercentConvert_x                             0x600EB0
#define CEverQuest__ClickedPlayer_x                                0x5F2EC0
#define CEverQuest__CreateTargetIndicator_x                        0x610440
#define CEverQuest__DeleteTargetIndicator_x                        0x6104D0
#define CEverQuest__DoTellWindow_x                                 0x4E86C0
#define CEverQuest__OutputTextToLog_x                              0x4E8940
#define CEverQuest__DropHeldItemOnGround_x                         0x5E7F00
#define CEverQuest__dsp_chat_x                                     0x4E8CD0
#define CEverQuest__trimName_x                                     0x60C720
#define CEverQuest__Emote_x                                        0x601710
#define CEverQuest__EnterZone_x                                    0x5FB690
#define CEverQuest__GetBodyTypeDesc_x                              0x605FE0
#define CEverQuest__GetClassDesc_x                                 0x606620
#define CEverQuest__GetClassThreeLetterCode_x                      0x606C20
#define CEverQuest__GetDeityDesc_x                                 0x60ED80
#define CEverQuest__GetLangDesc_x                                  0x606DE0
#define CEverQuest__GetRaceDesc_x                                  0x606600
#define CEverQuest__InterpretCmd_x                                 0x60F350
#define CEverQuest__LeftClickedOnPlayer_x                          0x5EC100
#define CEverQuest__LMouseUp_x                                     0x5EA490
#define CEverQuest__RightClickedOnPlayer_x                         0x5EC9E0
#define CEverQuest__RMouseUp_x                                     0x5EB410
#define CEverQuest__SetGameState_x                                 0x5E7C90
#define CEverQuest__UPCNotificationFlush_x                         0x60C620
#define CEverQuest__IssuePetCommand_x                              0x6081E0
#define CEverQuest__ReportSuccessfulHit_x                          0x602A60

// CGaugeWnd
// not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x72EB10
#define CGaugeWnd__CalcLinesFillRect_x                             0x72EB70
#define CGaugeWnd__Draw_x                                          0x72E190

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AEFD0
#define CGuild__GetGuildName_x                                     0x4AE0B0
#define CGuild__GetGuildIndex_x                                    0x4AE440

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton_x                               0x749F60

//CHotButton
#define CHotButton__SetButtonSize_x                                0x621E50

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot_x                                 0x756F30
#define CInvSlotMgr__MoveItem_x                                    0x755C90
#define CInvSlotMgr__SelectSlot_x                                  0x757000

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x754510
#define CInvSlot__SliderComplete_x                                 0x752260
#define CInvSlot__GetItemBase_x                                    0x751BF0
#define CInvSlot__UpdateItem_x                                     0x751D60

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x758A80
#define CInvSlotWnd__CInvSlotWnd_x                                 0x757C20
#define CInvSlotWnd__HandleLButtonUp_x                             0x758600

// CItemDisplayWnd
#define CItemDisplayWnd__SetSpell_x                                0x812610
#define CItemDisplayWnd__UpdateStrings_x                           0x767140
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x760F20
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x761420
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x767750
#define CItemDisplayWnd__AboutToShow_x                             0x766DA0
#define CItemDisplayWnd__WndNotification_x                         0x768820
#define CItemDisplayWnd__RequestConvertItem_x                      0x7682F0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x765E10
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x766BC0

// CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x84B0F0

// CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x76CD60

// CLabel
#define CLabel__Draw_x                                             0x772750

// CListWnd
#define CListWnd__CListWnd_x                                       0x9295B0
#define CListWnd__dCListWnd_x                                      0x9298D0
#define CListWnd__vftable_x                                        0x913890
#define CListWnd__AddColumn_x                                      0x92DD40
#define CListWnd__AddColumn1_x                                     0x92DD90
#define CListWnd__AddLine_x                                        0x92E120
#define CListWnd__AddString_x                                      0x92DF20
#define CListWnd__CalculateFirstVisibleLine_x                      0x92DB10
#define CListWnd__CalculateVSBRange_x                              0x92D8F0
#define CListWnd__ClearSel_x                                       0x92E900
#define CListWnd__ClearAllSel_x                                    0x92E960
#define CListWnd__CloseAndUpdateEditWindow_x                       0x92F360
#define CListWnd__Compare_x                                        0x92D220
#define CListWnd__Draw_x                                           0x929A00
#define CListWnd__DrawColumnSeparators_x                           0x92C1F0
#define CListWnd__DrawHeader_x                                     0x92C660
#define CListWnd__DrawItem_x                                       0x92CB60
#define CListWnd__DrawLine_x                                       0x92C360
#define CListWnd__DrawSeparator_x                                  0x92C290
#define CListWnd__EnableLine_x                                     0x92BAD0
#define CListWnd__EnsureVisible_x                                  0x92F290
#define CListWnd__ExtendSel_x                                      0x92E830
#define CListWnd__GetColumnTooltip_x                               0x92B610
#define CListWnd__GetColumnMinWidth_x                              0x92B680
#define CListWnd__GetColumnWidth_x                                 0x92B580
#define CListWnd__GetCurSel_x                                      0x92AF10
#define CListWnd__GetItemAtPoint_x                                 0x92BD40
#define CListWnd__GetItemAtPoint1_x                                0x92BDB0
#define CListWnd__GetItemData_x                                    0x92AF90
#define CListWnd__GetItemHeight_x                                  0x92B350
#define CListWnd__GetItemIcon_x                                    0x92B120
#define CListWnd__GetItemRect_x                                    0x92BBC0
#define CListWnd__GetItemText_x                                    0x92AFD0
#define CListWnd__GetSelList_x                                     0x92E9B0
#define CListWnd__GetSeparatorRect_x                               0x92BFF0
#define CListWnd__InsertLine_x                                     0x92E510
#define CListWnd__RemoveLine_x                                     0x92E660
#define CListWnd__SetColors_x                                      0x92D8C0
#define CListWnd__SetColumnJustification_x                         0x92D5F0
#define CListWnd__SetColumnWidth_x                                 0x92D510
#define CListWnd__SetCurSel_x                                      0x92E770
#define CListWnd__SetItemColor_x                                   0x92EF50
#define CListWnd__SetItemData_x                                    0x92EF10
#define CListWnd__SetItemText_x                                    0x92EB20
#define CListWnd__ShiftColumnSeparator_x                           0x92D6B0
#define CListWnd__Sort_x                                           0x92D3A0
#define CListWnd__ToggleSel_x                                      0x92E7A0
#define CListWnd__SetColumnsSizable_x                              0x92D760
#define CListWnd__SetItemWnd_x                                     0x92EDD0
#define CListWnd__GetItemWnd_x                                     0x92B170
#define CListWnd__SetItemIcon_x                                    0x92EBA0
#define CListWnd__CalculateCustomWindowPositions_x                 0x92DC00
#define CListWnd__SetVScrollPos_x                                  0x92D4F0

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd_x                                 0x787F70

// MapViewMap
#define MapViewMap__MapViewMap_x                                   0x783460
#define MapViewMap__dMapViewMap_x                                  0x7835B0
#define MapViewMap__vftable_x                                      0xB1E068
#define MapViewMap__Clear_x                                        0x783DE0
#define MapViewMap__SaveEx_x                                       0x7871A0
#define MapViewMap__SetZoom_x                                      0x78B860
#define MapViewMap__HandleLButtonDown_x                            0x7836C0
#define MapViewMap__GetWorldCoordinates_x                          0x786680

// CMerchantWnd
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A8150
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A8A30
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A8F60
#define CMerchantWnd__SelectRecoverySlot_x                         0x7ABED0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A6CC0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7B1A80
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A7D70

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8AE120
#define CPacketScrambler__hton_x                                   0x8AE110

// CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x94CA00
#define CSidlManagerBase__CreatePageWnd_x                          0x94C1F0
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x948470
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x948400
#define CSidlManagerBase__FindAnimation1_x                         0x948650
#define CSidlManagerBase__FindScreenPieceTemplate_x                0x948A60
#define CSidlManagerBase__FindScreenPieceTemplate1_x               0x948850
#define CSidlManagerBase__CreateLabel_x                            0x809A40
#define CSidlManagerBase__CreateXWndFromTemplate_x                 0x94B9C0
#define CSidlManagerBase__CreateXWndFromTemplate1_x                0x94BBA0
#define CSidlManagerBase__CreateXWnd_x                             0x809970

// CSidlManager
#define CSidlManager__CreateHotButtonWnd_x                         0x809F40

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateHSBRange_x                        0x945110
#define CSidlScreenWnd__CalculateVSBRange_x                        0x945010
#define CSidlScreenWnd__ConvertToRes_x                             0x96A680
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x944AA0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x944790
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x944860
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x944930
#define CSidlScreenWnd__DrawSidlPiece_x                            0x9455B0
#define CSidlScreenWnd__EnableIniStorage_x                         0x945A80
#define CSidlScreenWnd__GetChildItem_x                             0x945A00
#define CSidlScreenWnd__GetSidlPiece_x                             0x9457A0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9350D0
#define CSidlScreenWnd__Init1_x                                    0x944390
#define CSidlScreenWnd__LoadIniInfo_x                              0x945AD0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x946630
#define CSidlScreenWnd__LoadSidlScreen_x                           0x943790
#define CSidlScreenWnd__m_layoutCopy_x                             0x15FCFA0
#define CSidlScreenWnd__StoreIniInfo_x                             0x9461A0
#define CSidlScreenWnd__StoreIniVis_x                              0x946510
#define CSidlScreenWnd__vftable_x                                  0xB48368
#define CSidlScreenWnd__WndNotification_x                          0x9454C0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x686760
#define CSkillMgr__GetSkillCap_x                                   0x686940
#define CSkillMgr__GetNameToken_x                                  0x685EE0
#define CSkillMgr__IsActivatedSkill_x                              0x686020
#define CSkillMgr__IsCombatSkill_x                                 0x685F60

// CSliderWnd
#define CSliderWnd__GetValue_x                                     0x955310
#define CSliderWnd__SetValue_x                                     0x955180
#define CSliderWnd__SetNumTicks_x                                  0x9551E0

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet_x                               0x80FAA0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x95DB30
#define CStmlWnd__CalculateHSBRange_x                              0x95EC40
#define CStmlWnd__CalculateVSBRange_x                              0x95EBC0
#define CStmlWnd__CanBreakAtCharacter_x                            0x962F80
#define CStmlWnd__FastForwardToEndOfTag_x                          0x963C10
#define CStmlWnd__ForceParseNow_x                                  0x95E120
#define CStmlWnd__GetNextTagPiece_x                                0x962EE0
#define CStmlWnd__GetSTMLText_x                                    0x505D20
#define CStmlWnd__GetVisibleText_x                                 0x95E140
#define CStmlWnd__InitializeWindowVariables_x                      0x963A60
#define CStmlWnd__MakeStmlColorTag_x                               0x95D1A0
#define CStmlWnd__MakeWndNotificationTag_x                         0x95D210
#define CStmlWnd__SetSTMLText_x                                    0x95C250
#define CStmlWnd__StripFirstSTMLLines_x                            0x964D00
#define CStmlWnd__UpdateHistoryString_x                            0x963E20

// CTabWnd
#define CTabWnd__Draw_x                                            0x95B380
#define CTabWnd__DrawCurrentPage_x                                 0x95BAB0
#define CTabWnd__DrawTab_x                                         0x95B7D0
#define CTabWnd__GetCurrentPage_x                                  0x95AB80
#define CTabWnd__GetPageInnerRect_x                                0x95ADC0
#define CTabWnd__GetTabInnerRect_x                                 0x95AD00
#define CTabWnd__GetTabRect_x                                      0x95ABB0
#define CTabWnd__InsertPage_x                                      0x95AFD0
#define CTabWnd__SetPage_x                                         0x95AE40
#define CTabWnd__SetPageRect_x                                     0x95B2C0
#define CTabWnd__UpdatePage_x                                      0x95B690
#define CTabWnd__GetPageFromTabIndex_x                             0x95B710
#define CTabWnd__GetCurrentTabIndex_x                              0x95AB70

// CPageWnd
#define CPageWnd__GetTabText_x                                     0x76D150
#define CPageWnd__SetTabText_x                                     0x95A6D0

// CTextOverlay
#define CTextOverlay__DisplayText_x                                0x4A8CE0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x931FA0
#define CTextureFont__GetTextExtent_x                              0x932160

// CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B9610
#define CHtmlComponentWnd__ValidateUri_x                           0x74B950
#define CHtmlWnd__SetClientCallbacks_x                             0x626EF0
#define CHtmlWnd__AddObserver_x                                    0x626F10
#define CHtmlWnd__RemoveObserver_x                                 0x626F70
#define Window__getProgress_x                                      0x863870
#define Window__getStatus_x                                        0x863890
#define Window__getURI_x                                           0x8638A0

// CXMLDataManager
#define CXMLDataManager__GetXMLData_x                              0x9700D0

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead_x                             0x91F0B0

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr_x                                             0x4E8210
#define CXStr__CXStr1_x                                            0x927AC0
#define CXStr__CXStr3_x                                            0x9010D0
#define CXStr__dCXStr_x                                            0x4786E0
#define CXStr__operator_equal_x                                    0x901300
#define CXStr__operator_equal1_x                                   0x901340
#define CXStr__operator_plus_equal1_x                              0x901DD0
#define CXStr__SetString_x                                         0x903CC0
#define CXStr__operator_char_p_x                                   0x901810
#define CXStr__GetChar_x                                           0x903610
#define CXStr__Delete_x                                            0x902EC0
#define CXStr__GetUnicode_x                                        0x903680
#define CXStr__GetLength_x                                         0x4A8A90
#define CXStr__Mid_x                                               0x47D390
#define CXStr__Insert_x                                            0x9036E0
#define CXStr__FindNext_x                                          0x903330
#define CXStr__gFreeLists_x                                        0xCA2518
#define CXStr__gCXStrAccess_x                                      0x15FC6C4

// CTileLayoutWnd
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x9535B0

// CXWnd
#define CXWnd__BringToTop_x                                        0x938940
#define CXWnd__Center_x                                            0x9384C0
#define CXWnd__ClrFocus_x                                          0x9382E0
#define CXWnd__Destroy_x                                           0x938380
#define CXWnd__DoAllDrawing_x                                      0x934880
#define CXWnd__DrawChildren_x                                      0x934850
#define CXWnd__DrawColoredRect_x                                   0x934CE0
#define CXWnd__DrawTooltip_x                                       0x9333A0
#define CXWnd__DrawTooltipAtPoint_x                                0x933460
#define CXWnd__GetBorderFrame_x                                    0x934B40
#define CXWnd__GetChildItem_x                                      0x938B50
#define CXWnd__GetChildWndAt_x                                     0x9389E0
#define CXWnd__GetClientClipRect_x                                 0x936B40
#define CXWnd__GetScreenClipRect_x                                 0x936C10
#define CXWnd__GetScreenRect_x                                     0x936DE0
#define CXWnd__GetTooltipRect_x                                    0x934D30
#define CXWnd__GetWindowTextA_x                                    0x49C930
#define CXWnd__IsActive_x                                          0x935450
#define CXWnd__IsDescendantOf_x                                    0x9377F0
#define CXWnd__IsReallyVisible_x                                   0x937820
#define CXWnd__IsType_x                                            0x939060
#define CXWnd__Minimize_x                                          0x937F70
#define CXWnd__Move_x                                              0x937890
#define CXWnd__Move1_x                                             0x937950
#define CXWnd__ProcessTransition_x                                 0x938470
#define CXWnd__Refade_x                                            0x937C30
#define CXWnd__Resize_x                                            0x937F00
#define CXWnd__Right_x                                             0x938700
#define CXWnd__SetFocus_x                                          0x9382A0
#define CXWnd__SetFont_x                                           0x938310
#define CXWnd__SetKeyTooltip_x                                     0x938E70
#define CXWnd__SetMouseOver_x                                      0x935CB0
#define CXWnd__SetParent_x                                         0x937590
#define CXWnd__StartFade_x                                         0x9376D0
#define CXWnd__vftable_x                                           0xB47DE4
#define CXWnd__CXWnd_x                                             0x932480
#define CXWnd__dCXWnd_x                                            0x9329A0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x96B700

// CXWndManager
#define CXWndManager__DrawCursor_x                                 0x93B890
#define CXWndManager__DrawWindows_x                                0x93B8B0
#define CXWndManager__GetKeyboardFlags_x                           0x93DFD0
#define CXWndManager__HandleKeyboardMsg_x                          0x93DB80
#define CXWndManager__RemoveWnd_x                                  0x93E200
#define CXWndManager__RemovePendingDeletionWnd_x                   0x93E770

// CDBStr
#define CDBStr__GetString_x                                        0x53D810

// CharacterZoneClient
#define CharacterZoneClient__CastSpell_x                           0x4BB670
#define CharacterZoneClient__Cur_HP_x                              0x4D1DC0
#define CharacterZoneClient__Cur_Mana_x                            0x4D9500
#define CharacterZoneClient__GetCastingTimeModifier_x              0x4BE6D0
#define CharacterZoneClient__GetFocusCastingTimeModifier_x         0x4B21B0
#define CharacterZoneClient__GetFocusRangeModifier_x               0x4B2300
#define CharacterZoneClient__GetHPRegen_x                          0x4DF2D0
#define CharacterZoneClient__GetEnduranceRegen_x                   0x4DF8D0
#define CharacterZoneClient__GetManaRegen_x                        0x4DFD10
#define CharacterZoneClient__Max_Endurance_x                       0x64D000
#define CharacterZoneClient__Max_HP_x                              0x4D1BF0
#define CharacterZoneClient__Max_Mana_x                            0x64CE00
#define CharacterZoneClient__doCombatAbility_x                     0x64F460
#define CharacterZoneClient__UseSkill_x                            0x4E1AF0
#define CharacterZoneClient__IsExpansionFlag_x                     0x5A96E0
#define CharacterZoneClient__TotalEffect_x                         0x4C5120
#define CharacterZoneClient__GetPCSpellAffect_x                    0x4BF420
#define CharacterZoneClient__SpellDuration_x                       0x4BEF50
#define CharacterZoneClient__GetAdjustedSkill_x                    0x4D4B40
#define CharacterZoneClient__GetBaseSkill_x                        0x4D5AE0
#define CharacterZoneClient__CanUseItem_x                          0x4D9810

// ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8CD500

// PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x663540

// PcClient
#define PcClient__PcClient_x                                       0x643750
#define PcClient__GetConLevel_x                                    0x646010

// CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B92E0
#define CCharacterListWnd__EnterWorld_x                            0x4B8D20
#define CCharacterListWnd__Quit_x                                  0x4B8A70
#define CCharacterListWnd__UpdateList_x                            0x4B8EB0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x628120
#define EQ_Item__CreateItemTagString_x                             0x8A7960
#define EQ_Item__IsStackable_x                                     0x8AC4F0
#define EQ_Item__GetImageNum_x                                     0x8A93E0
#define EQ_Item__CreateItemClient_x                                0x6272F0
#define EQ_Item__GetItemValue_x                                    0x8AA6D0
#define EQ_Item__ValueSellMerchant_x                               0x8ADD00
#define EQ_Item__IsKeyRingItem_x                                   0x8ABDE0
#define EQ_Item__CanGoInBag_x                                      0x628240
#define EQ_Item__IsEmpty_x                                         0x8AB930
#define EQ_Item__GetMaxItemCount_x                                 0x8AAAF0
#define EQ_Item__GetHeldItem_x                                     0x8A92B0
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A72D0

// EQ_LoadingS
#define EQ_LoadingS__SetProgressBar_x                              0x55BC90
#define EQ_LoadingS__Array_x                                       0xC2BB60

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x64D960
#define EQ_PC__GetAlternateAbilityId_x                             0x8B6F40
#define EQ_PC__GetCombatAbility_x                                  0x8B75B0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B7620
#define EQ_PC__GetItemRecastTimer_x                                0x64F9E0
#define EQ_PC__HasLoreItem_x                                       0x6467D0
#define EQ_PC__AlertInventoryChanged_x                             0x645950
#define EQ_PC__GetPcZoneClient_x                                   0x672100
#define EQ_PC__RemoveMyAffect_x                                    0x652C10
#define EQ_PC__GetKeyRingItems_x                                   0x8B7EB0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B7C40
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B81B0

// EQItemList
#define EQItemList__EQItemList_x                                   0x5AFC40
#define EQItemList__add_object_x                                   0x5DD5E0
#define EQItemList__add_item_x                                     0x5B01A0
#define EQItemList__delete_item_x                                  0x5B01F0
#define EQItemList__FreeItemList_x                                 0x5B00F0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x53A320

// EQPlayer
#define EQPlayer__ChangeBoneStringSprite_x                         0x664DC0
#define EQPlayer__dEQPlayer_x                                      0x658100
#define EQPlayer__DoAttack_x                                       0x66CD90
#define EQPlayer__EQPlayer_x                                       0x6587C0
#define EQPlayer__SetNameSpriteState_x                             0x65CAA0
#define EQPlayer__SetNameSpriteTint_x                              0x65D970
#define PlayerBase__HasProperty_j_x                                0x99DDB0
#define EQPlayer__IsTargetable_x                                   0x99E250
#define EQPlayer__CanSee_x                                         0x99E0B0
#define EQPlayer__CanSee1_x                                        0x99E180
#define PlayerBase__GetVisibilityLineSegment_x                     0x99DE70

// PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x66FB90
#define PlayerZoneClient__GetLevel_x                               0x672140
#define PlayerZoneClient__IsValidTeleport_x                        0x5DE750
#define PlayerZoneClient__LegalPlayerRace_x                        0x555080

// EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x667C30
#define EQPlayerManager__GetSpawnByName_x                          0x667CE0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x667D70

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x62B760
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x62B7E0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x62B820
#define KeypressHandler__ClearCommandStateArray_x                  0x62CC30
#define KeypressHandler__HandleKeyDown_x                           0x62CC50
#define KeypressHandler__HandleKeyUp_x                             0x62CCF0
#define KeypressHandler__SaveKeymapping_x                          0x62D140

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8CB370

// StringTable
#define StringTable__getString_x                                   0x8C6260

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x652880
#define PcZoneClient__RemovePetEffect_x                            0x652EB0
#define PcZoneClient__HasAlternateAbility_x                        0x64CC30
#define PcZoneClient__GetCurrentMod_x                              0x4E4BB0
#define PcZoneClient__GetModCap_x                                  0x4E4AB0
#define PcZoneClient__CanEquipItem_x                               0x64D300
#define PcZoneClient__GetItemByID_x                                0x64FE50
#define PcZoneClient__GetItemByItemClass_x                         0x64FFA0
#define PcZoneClient__RemoveBuffEffect_x                           0x652ED0
#define PcZoneClient__BandolierSwap_x                              0x64DF20
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64F980

// Doors
#define EQSwitch__UseSwitch_x                                      0x5E3320

// IconCache
#define IconCache__GetIcon_x                                       0x724140

// CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x71BC20
#define CContainerMgr__CloseContainer_x                            0x71BEF0
#define CContainerMgr__OpenExperimentContainer_x                   0x71C970

// CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7DBFD0

// CHelpWnd
#define CHelpWnd__SetFile_x                                        0x620250

// CLootWnd
#define CLootWnd__LootAll_x                                        0x77A290
#define CLootWnd__RequestLootSlot_x                                0x7794C0

// EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x57BEF0
#define EQ_Spell__SpellAffects_x                                   0x57C360
#define EQ_Spell__SpellAffectBase_x                                0x57C120
#define EQ_Spell__IsStackable_x                                    0x4C9800
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9620
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B66B0
#define EQ_Spell__IsSPAStacking_x                                  0x57D1B0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x57C6C0
#define EQ_Spell__IsNoRemove_x                                     0x4C97E0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57D1C0
#define __IsResEffectSpell_x                                       0x4C8B40

// EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4ACD10

// EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D5A40

// CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x822D50
#define CTargetWnd__WndNotification_x                              0x8225E0
#define CTargetWnd__RefreshTargetBuffs_x                           0x8228B0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x821750

// CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x827350

// CTaskManager
#define CTaskManager__GetEntry_x                                   0x537D50
#define CTaskManager__HandleMessage_x                              0x5361E0
#define CTaskManager__GetTaskStatus_x                              0x537E00
#define CTaskManager__GetElementDescription_x                      0x537E80

// EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x577440
#define EqSoundManager__PlayScriptMp3_x                            0x5775A0
#define EqSoundManager__SoundAssistPlay_x                          0x68A690
#define EqSoundManager__WaveInstancePlay_x                         0x689C00

// CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52BB30

// CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x959BE0

// CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x563720
#define CAltAbilityData__GetMercMaxRank_x                          0x5636B0
#define CAltAbilityData__GetMaxRank_x                              0x558D60

// CTargetRing
#define CTargetRing__Cast_x                                        0x61E370

// CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9600
#define CharacterBase__CreateItemGlobalIndex_x                     0x512EB0
#define CharacterBase__CreateItemIndex_x                           0x6264A0
#define CharacterBase__GetItemPossession_x                         0x4FE740
#define CharacterBase__GetItemByGlobalIndex_x                      0x8DE050
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8DE0B0

// CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x702C30
#define CCastSpellWnd__IsBardSongPlaying_x                         0x703460
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x703510

// messages
#define msg_spell_worn_off_x                                       0x5A1860
#define msg_new_text_x                                             0x596600
#define __msgTokenTextParam_x                                      0x5A3D80
#define msgTokenText_x                                             0x5A3FD0

// SpellManager
#define SpellManager__vftable_x                                    0xAF0694
#define SpellManager__SpellManager_x                               0x68D9C0
#define Spellmanager__LoadTextSpells_x                             0x68E2B0
#define SpellManager__GetSpellByGroupAndRank_x                     0x68DB90

// CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x 0x9A1CE0

// ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D63E0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D6660

// CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x772A90

// CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x720340
#define CCursorAttachment__AttachToCursor1_x                       0x720380
#define CCursorAttachment__Deactivate_x                            0x721370

// CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9697E0
#define CEQSuiteTextureLoader__GetTexture_x                        0x9694A0

// CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x510420
#define CFindItemWnd__WndNotification_x                            0x510F00
#define CFindItemWnd__Update_x                                     0x511A70
#define CFindItemWnd__PickupSelectedItem_x                         0x50FC70

// IString
#define IString__Append_x                                          0x4F1290

// Camera
#define CDisplay__cameraType_x                                     0xE055A4
#define EverQuest__Cameras_x                                       0xEC8ACC

// LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x518BC0
#define LootFiltersManager__GetItemFilterData_x                    0x5184D0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x518500
#define LootFiltersManager__SetItemLootFilter_x                    0x518720

// COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C9F80

// CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A78B0
#define CResolutionHandler__GetWindowedStyle_x                     0x685040

// CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x718970

// CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8EB690
#define CDistillerInfo__Instance_x                                 0x8EB630

// CGroupWnd
#define CGroupWnd__WndNotification_x                               0x738D60
#define CGroupWnd__UpdateDisplay_x                                 0x7380B0

// ItemBase
#define ItemBase__IsLore_x                                         0x8ABE90
#define ItemBase__IsLoreEquipped_x                                 0x8ABF10

// EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5DD540
#define EQPlacedItemManager__GetItemByGuid_x                       0x5DD680
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5DD6E0

// RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x67A820
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x67E1C0

// CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x506770

// FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F31C0
#define FactionManagerClient__HandleFactionMessage_x               0x4F3830
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F3DF0
#define FactionManagerClient__GetMaxFaction_x                      0x4F3E0F
#define FactionManagerClient__GetMinFaction_x                      0x4F3DC0

// BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FE710

// ArrayClass
#define ArrayClass__DeleteElement_x                                0x931000

// AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BC40

// ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FE990

// MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x562BE0

// CTargetManager
#define CTargetManager__Get_x                                      0x691210

// RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x67A820

// CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8AA0

// EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5B0090

// EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF66160
