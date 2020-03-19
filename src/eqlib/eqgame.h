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
#define __ExpectedVersionDate                                     "Mar 17 2020"
#define __ExpectedVersionTime                                     "18:15:36"
#define __ActualVersionDate_x                                      0xB18388
#define __ActualVersionTime_x                                      0xB1837C
#define __ActualVersionBuild_x                                     0xB040DC

// Memory Protection
#define __MemChecker0_x                                            0x63CF90
#define __MemChecker1_x                                            0x9105D0
#define __MemChecker2_x                                            0x6CB500
#define __MemChecker3_x                                            0x6CB450
#define __MemChecker4_x                                            0x866BB0
#define __EncryptPad0_x                                            0xC504E8
#define __EncryptPad1_x                                            0xCAE650
#define __EncryptPad2_x                                            0xC60D80
#define __EncryptPad3_x                                            0xC60980
#define __EncryptPad4_x                                            0xC9EC00
#define __EncryptPad5_x                                            0xF6F7DC
#define __AC1_x                                                    0x8234A6
#define __AC2_x                                                    0x5F6BDF
#define __AC3_x                                                    0x5FE2DF
#define __AC4_x                                                    0x6022B0
#define __AC5_x                                                    0x6085BF
#define __AC6_x                                                    0x60CAB6
#define __AC7_x                                                    0x5F6650
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x6E178

// Direct Input
#define DI8__Main_x                                                0xF6F7FC
#define DI8__Keyboard_x                                            0xF6F800
#define DI8__Mouse_x                                               0xF6F81C
#define DI8__Mouse_Copy_x                                          0xECAE84
#define DI8__Mouse_Check_x                                         0xF702C8
#define __AutoSkillArray_x                                         0xECBD9C
#define __Attack_x                                                 0xF69BC3
#define __Autofire_x                                               0xF69BC4
#define __BindList_x                                               0xC3EF30
#define g_eqCommandStates_x                                        0xC3FCB0
#define __Clicks_x                                                 0xECAF3C
#define __CommandList_x                                            0xC40870
#define __CurrentMapLabel_x                                        0xF8268C
#define __CurrentSocial_x                                          0xC287CC
#define __DoAbilityList_x                                          0xF016E4
#define __do_loot_x                                                0x5C2680
#define __DrawHandler_x                                            0x1601A08
#define __GroupCount_x                                             0xEC5A1A
#define __Guilds_x                                                 0xEC9DC8
#define __gWorld_x                                                 0xEC5C10
#define __HWnd_x                                                   0xF702A8
#define __heqmain_x                                                0xF7275C
#define __InChatMode_x                                             0xECAE6C
#define __LastTell_x                                               0xECCDE0
#define __LMouseHeldTime_x                                         0xECAFA8
#define __Mouse_x                                                  0xF6F7E8
#define __MouseLook_x                                              0xECAF02
#define __MouseEventTime_x                                         0xF6A6A4
#define __gpbCommandEvent_x                                        0xEC5C1C
#define __NetStatusToggle_x                                        0xECAF05
#define __PCNames_x                                                0xECC38C
#define __RangeAttackReady_x                                       0xECC080
#define __RMouseHeldTime_x                                         0xECAFA4
#define __RunWalkState_x                                           0xECAE70
#define __ScreenMode_x                                             0xE111A8
#define __ScreenX_x                                                0xECAE24
#define __ScreenY_x                                                0xECAE20
#define __ScreenXMax_x                                             0xECAE28
#define __ScreenYMax_x                                             0xECAE2C
#define __ServerHost_x                                             0xEC5E4B
#define __ServerName_x                                             0xF016A4
#define __ShiftKeyDown_x                                           0xECB4FC
#define __ShowNames_x                                              0xECC23C
#define __SocialChangedList_x                                      0xF0172C
#define __Socials_x                                                0xF017A4
#define __SubscriptionType_x                                       0xFC6B98
#define __TargetAggroHolder_x                                      0xF85040
#define __ZoneType_x                                               0xECB300
#define __GroupAggro_x                                             0xF85080
#define __LoginName_x                                              0xF6FF54
#define __Inviter_x                                                0xF69B40
#define __AttackOnAssist_x                                         0xECC1F8
#define __UseTellWindows_x                                         0xECC528
#define __gfMaxZoomCameraDistance_x                                0xB0DCF0
#define __gfMaxCameraDistance_x                                    0xB3A08C
#define __pulAutoRun_x                                             0xECAF20
#define __pulForward_x                                             0xECC560
#define __pulBackward_x                                            0xECC564
#define __pulTurnRight_x                                           0xECC568
#define __pulTurnLeft_x                                            0xECC56C
#define __pulStrafeLeft_x                                          0xECC570
#define __pulStrafeRight_x                                         0xECC574

////
//Section 1: Vital Offsets
////
#define instCRaid_x                                                0xEC6160
#define instEQZoneInfo_x                                           0xECB0F8
#define pinstActiveBanker_x                                        0xEC5CF8
#define pinstActiveCorpse_x                                        0xEC5CF0
#define pinstActiveGMaster_x                                       0xEC5CF4
#define pinstActiveMerchant_x                                      0xEC5CEC
#define pinstAltAdvManager_x                                       0xE12390
#define pinstBandageTarget_x                                       0xEC5D08
#define pinstCamActor_x                                            0xE11198
#define pinstCDBStr_x                                              0xE110AC
#define pinstCDisplay_x                                            0xEC5868
#define pinstCEverQuest_x                                          0xF6F818
#define pinstEverQuestInfo_x                                       0xECAE18
#define pinstCharData_x                                            0xEC5A04
#define pinstCharSpawn_x                                           0xEC5D40
#define pinstControlledMissile_x                                   0xEC3854
#define pinstControlledPlayer_x                                    0xEC5D40
#define pinstCResolutionHandler_x                                  0x1601C38
#define pinstCSidlManager_x                                        0x1600BD0
#define pinstCXWndManager_x                                        0x1600BCC
#define instDynamicZone_x                                          0xEC9CA0
#define pinstDZMember_x                                            0xEC9DB0
#define pinstDZTimerInfo_x                                         0xEC9DB4
#define pinstEqLogin_x                                             0xF6F8A0
#define instEQMisc_x                                               0xE10FF0
#define pinstEQSoundManager_x                                      0xE13360
#define pinstEQSpellStrings_x                                      0xCD39F8
#define instExpeditionLeader_x                                     0xEC9CEA
#define instExpeditionName_x                                       0xEC9D2A
#define pinstSGraphicsEngine_x                                     0x16019FC
#define pinstGroup_x                                               0xEC5A16
#define pinstImeManager_x                                          0x1600BC8
#define pinstLocalPlayer_x                                         0xEC5CE8
#define pinstMercenaryData_x                                       0xF6C19C
#define pinstMercenaryStats_x                                      0xF8518C
#define pinstModelPlayer_x                                         0xEC5D00
#define pinstPCData_x                                              0xEC5A04
#define pinstSkillMgr_x                                            0xF6E300
#define pinstSpawnManager_x                                        0xF6CDA8
#define pinstSpellManager_x                                        0xF6E540
#define pinstSpellSets_x                                           0xF627EC
#define pinstStringTable_x                                         0xEC5C08
#define pinstSwitchManager_x                                       0xEC3700
#define pinstTarget_x                                              0xEC5D3C
#define pinstTargetObject_x                                        0xEC5F54
#define pinstTargetSwitch_x                                        0xEC385C
#define pinstTaskMember_x                                          0xE10E80
#define pinstTrackTarget_x                                         0xEC5D44
#define pinstTradeTarget_x                                         0xEC5CFC
#define instTributeActive_x                                        0xE11011
#define pinstViewActor_x                                           0xE11194
#define pinstWorldData_x                                           0xEC5864
#define pinstZoneAddr_x                                            0xECB398
#define pinstPlayerPath_x                                          0xF6CE40
#define pinstTargetIndicator_x                                     0xF6E7A8
#define EQObject_Top_x                                             0xEC5CE4

////
//Section 2:  UI Related Offsets
////
#define pinstCAAWnd_x                                              0xE1147C
#define pinstCAchievementsWnd_x                                    0xE1198C
#define pinstCActionsWnd_x                                         0xE114D4
#define pinstCAdvancedDisplayOptionsWnd_x                          0xE111BC
#define pinstCAdvancedLootWnd_x                                    0xE11154
#define pinstCAdventureLeaderboardWnd_x                            0xF7BE60
#define pinstCAdventureRequestWnd_x                                0xF7BF10
#define pinstCAdventureStatsWnd_x                                  0xF7BFC0
#define pinstCAggroMeterWnd_x                                      0xE111C0
#define pinstCAlarmWnd_x                                           0xE119CC
#define pinstCAlertHistoryWnd_x                                    0xE11210
#define pinstCAlertStackWnd_x                                      0xE11158
#define pinstCAlertWnd_x                                           0xE11178
#define pinstCAltStorageWnd_x                                      0xF7C320
#define pinstCAudioTriggersWindow_x                                0xCC5D28
#define pinstCAuraWnd_x                                            0xE11164
#define pinstCAvaZoneWnd_x                                         0xE11214
#define pinstCBandolierWnd_x                                       0xE111B4
#define pinstCBankWnd_x                                            0xE111FC
#define pinstCBarterMerchantWnd_x                                  0xF7D560
#define pinstCBarterSearchWnd_x                                    0xF7D610
#define pinstCBarterWnd_x                                          0xF7D6C0
#define pinstCBazaarConfirmationWnd_x                              0xE119C8
#define pinstCBazaarSearchWnd_x                                    0xE11480
#define pinstCBazaarWnd_x                                          0xE119AC
#define pinstCBlockedBuffWnd_x                                     0xE11170
#define pinstCBlockedPetBuffWnd_x                                  0xE11190
#define pinstCBodyTintWnd_x                                        0xE11948
#define pinstCBookWnd_x                                            0xE111E8
#define pinstCBreathWnd_x                                          0xE11490
#define pinstCBuffWindowNORMAL_x                                   0xE11148
#define pinstCBuffWindowSHORT_x                                    0xE1114C
#define pinstCBugReportWnd_x                                       0xE111F8
#define pinstCButtonWnd_x                                          0x1600E38
#define pinstCCastingWnd_x                                         0xE111D4
#define pinstCCastSpellWnd_x                                       0xE11484
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE11960
#define pinstCChatWindowManager_x                                  0xF7E180
#define pinstCClaimWnd_x                                           0xF7E2D8
#define pinstCColorPickerWnd_x                                     0xE11248
#define pinstCCombatAbilityWnd_x                                   0xE119BC
#define pinstCCombatSkillsSelectWnd_x                              0xE11970
#define pinstCCompassWnd_x                                         0xE1153C
#define pinstCConfirmationDialog_x                                 0xF831D8
#define pinstCContainerMgr_x                                       0xE1195C
#define pinstCContextMenuManager_x                                 0x1600B88
#define pinstCCursorAttachment_x                                   0xE111C8
#define pinstCDynamicZoneWnd_x                                     0xF7E8A0
#define pinstCEditLabelWnd_x                                       0xE119E0
#define pinstCEQMainWnd_x                                          0xF7EAE8
#define pinstCEventCalendarWnd_x                                   0xE11474
#define pinstCExtendedTargetWnd_x                                  0xE1118C
#define pinstCFacePick_x                                           0xE11988
#define pinstCFactionWnd_x                                         0xE11998
#define pinstCFellowshipWnd_x                                      0xF7ECE8
#define pinstCFileSelectionWnd_x                                   0xE1123C
#define pinstCFindItemWnd_x                                        0xE11980
#define pinstCFindLocationWnd_x                                    0xF7EE40
#define pinstCFriendsWnd_x                                         0xE1197C
#define pinstCGemsGameWnd_x                                        0xE11994
#define pinstCGiveWnd_x                                            0xE119D4
#define pinstCGroupSearchFiltersWnd_x                              0xE111D8
#define pinstCGroupSearchWnd_x                                     0xF7F238
#define pinstCGroupWnd_x                                           0xF7F2E8
#define pinstCGuildBankWnd_x                                       0xECC1DC
#define pinstCGuildCreationWnd_x                                   0xF7F448
#define pinstCGuildMgmtWnd_x                                       0xF7F4F8
#define pinstCharacterCreation_x                                   0xE11978
#define pinstCHelpWnd_x                                            0xE119C4
#define pinstCHeritageSelectionWnd_x                               0xE1199C
#define pinstCHotButtonWnd_x                                       0xF81650
#define pinstCHotButtonWnd1_x                                      0xF81650
#define pinstCHotButtonWnd2_x                                      0xF81654
#define pinstCHotButtonWnd3_x                                      0xF81658
#define pinstCHotButtonWnd4_x                                      0xF8165C
#define pinstCIconSelectionWnd_x                                   0xE111C4
#define pinstCInspectWnd_x                                         0xE1119C
#define pinstCInventoryWnd_x                                       0xE1116C
#define pinstCInvSlotMgr_x                                         0xE1148C
#define pinstCItemDisplayManager_x                                 0xF81BE0
#define pinstCItemExpTransferWnd_x                                 0xF81D10
#define pinstCItemOverflowWnd_x                                    0xE11488
#define pinstCJournalCatWnd_x                                      0xE11460
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE11218
#define pinstCKeyRingWnd_x                                         0xE111D0
#define pinstCLargeDialogWnd_x                                     0xF83E58
#define pinstCLayoutCopyWnd_x                                      0xF82060
#define pinstCLFGuildWnd_x                                         0xF82110
#define pinstCLoadskinWnd_x                                        0xE119A8
#define pinstCLootFiltersCopyWnd_x                                 0xCE2388
#define pinstCLootFiltersWnd_x                                     0xE1115C
#define pinstCLootSettingsWnd_x                                    0xE11184
#define pinstCLootWnd_x                                            0xE11464
#define pinstCMailAddressBookWnd_x                                 0xE11494
#define pinstCMailCompositionWnd_x                                 0xE11478
#define pinstCMailIgnoreListWnd_x                                  0xE1149C
#define pinstCMailWnd_x                                            0xE11250
#define pinstCManageLootWnd_x                                      0xE12840
#define pinstCMapToolbarWnd_x                                      0xE119D0
#define pinstCMapViewWnd_x                                         0xE119A0
#define pinstCMarketplaceWnd_x                                     0xE11160
#define pinstCMerchantWnd_x                                        0xE11470
#define pinstCMIZoneSelectWnd_x                                    0xF82948
#define pinstCMusicPlayerWnd_x                                     0xE11208
#define pinstCNameChangeMercWnd_x                                  0xE119B0
#define pinstCNameChangePetWnd_x                                   0xE11990
#define pinstCNameChangeWnd_x                                      0xE119D8
#define pinstCNoteWnd_x                                            0xE119B4
#define pinstCObjectPreviewWnd_x                                   0xE1117C
#define pinstCOptionsWnd_x                                         0xE119C0
#define pinstCPetInfoWnd_x                                         0xE11230
#define pinstCPetitionQWnd_x                                       0xE11964
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE11950
#define pinstCPlayerWnd_x                                          0xE11238
#define pinstCPopupWndManager_x                                    0xF831D8
#define pinstCProgressionSelectionWnd_x                            0xF83288
#define pinstCPurchaseGroupWnd_x                                   0xE111EC
#define pinstCPurchaseWnd_x                                        0xE111B8
#define pinstCPvPLeaderboardWnd_x                                  0xF83338
#define pinstCPvPStatsWnd_x                                        0xF833E8
#define pinstCQuantityWnd_x                                        0xE1121C
#define pinstCRaceChangeWnd_x                                      0xE11150
#define pinstCRaidOptionsWnd_x                                     0xE111E4
#define pinstCRaidWnd_x                                            0xE11468
#define pinstCRealEstateItemsWnd_x                                 0xE11984
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE114C0
#define pinstCRealEstateManageWnd_x                                0xE111F4
#define pinstCRealEstateNeighborhoodWnd_x                          0xE1120C
#define pinstCRealEstatePlotSearchWnd_x                            0xE1122C
#define pinstCRealEstatePurchaseWnd_x                              0xE11244
#define pinstCRespawnWnd_x                                         0xE11188
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE1196C
#define pinstCSendMoneyWnd_x                                       0xE119DC
#define pinstCServerListWnd_x                                      0xE11254
#define pinstCSkillsSelectWnd_x                                    0xE11958
#define pinstCSkillsWnd_x                                          0xE11944
#define pinstCSocialEditWnd_x                                      0xE111CC
#define pinstCSocialWnd_x                                          0xE119A4
#define pinstCSpellBookWnd_x                                       0xE119B8
#define pinstCStoryWnd_x                                           0xE114BC
#define pinstCTargetOfTargetWnd_x                                  0xF85210
#define pinstCTargetWnd_x                                          0xE11180
#define pinstCTaskOverlayWnd_x                                     0xE111E0
#define pinstCTaskSelectWnd_x                                      0xF85368
#define pinstCTaskManager_x                                        0xCE2CC8
#define pinstCTaskTemplateSelectWnd_x                              0xF85418
#define pinstCTaskWnd_x                                            0xF854C8
#define pinstCTextEntryWnd_x                                       0xE111DC
#define pinstCTimeLeftWnd_x                                        0xE1194C
#define pinstCTipWndCONTEXT_x                                      0xF856CC
#define pinstCTipWndOFDAY_x                                        0xF856C8
#define pinstCTitleWnd_x                                           0xF85778
#define pinstCTrackingWnd_x                                        0xE11174
#define pinstCTradeskillWnd_x                                      0xF858E0
#define pinstCTradeWnd_x                                           0xE11954
#define pinstCTrainWnd_x                                           0xE1125C
#define pinstCTributeBenefitWnd_x                                  0xF85AE0
#define pinstCTributeMasterWnd_x                                   0xF85B90
#define pinstCTributeTrophyWnd_x                                   0xF85C40
#define pinstCVideoModesWnd_x                                      0xE11240
#define pinstCVoiceMacroWnd_x                                      0xF6EF10
#define pinstCVoteResultsWnd_x                                     0xE11974
#define pinstCVoteWnd_x                                            0xE11968
#define pinstCWebManager_x                                         0xF6F58C
#define pinstCZoneGuideWnd_x                                       0xE111F0
#define pinstCZonePathWnd_x                                        0xE11200
#define pinstEQSuiteTextureLoader_x                                0xCB0128
#define pinstItemIconCache_x                                       0xF7EAA0
#define pinstLootFiltersManager_x                                  0xCE2438
#define pinstRewardSelectionWnd_x                                  0xF83B30

////
// Section 3: Miscellaneous Offsets
////
#define __CastRay_x                                                0x5BDA50
#define __CastRay2_x                                               0x5BDAA0
#define __ConvertItemTags_x                                        0x5D9660
#define __CleanItemTags_x                                          0x47D0E0
#define __CreateCascadeMenuItems_x                                 0x5591A0
#define __DoesFileExist_x                                          0x913650
#define __EQGetTime_x                                              0x9100A0
#define __ExecuteCmd_x                                             0x5B62D0
#define __FixHeading_x                                             0x9AA3D0
#define __FlushDxKeyboard_x                                        0x6C73C0
#define __GameLoop_x                                               0x6CA6D0
#define __get_bearing_x                                            0x5BD5C0
#define __get_melee_range_x                                        0x5BDC90
#define __GetAnimationCache_x                                      0x72FDF0
#define __GetGaugeValueFromEQ_x                                    0x821950
#define __GetLabelFromEQ_x                                         0x823430
#define __GetXTargetType_x                                         0x9ABE90
#define __HandleMouseWheel_x                                       0x6CB5B0
#define __HeadingDiff_x                                            0x9AA440
#define __HelpPath_x                                               0xF6A294
#define __LoadFrontEnd_x                                           0x6C79F0
#define __NewUIINI_x                                               0x821620
#define __ProcessGameEvents_x                                      0x61E3B0
#define __ProcessKeyboardEvents_x                                  0x6C8F30
#define __ProcessMouseEvents_x                                     0x61DB70
#define __SaveColors_x                                             0x559080
#define __STMLToText_x                                             0x94D9D0
#define __WndProc_x                                                0x6C9990
#define CMemoryMappedFile__SetFile_x                               0xA99680
#define CrashDetected_x                                            0x6C9490
#define DrawNetStatus_x                                            0x64A460
#define Expansion_HoT_x                                            0xECC1E4
#define Teleport_Table_Size_x                                      0xEC5CA4
#define Teleport_Table_x                                           0xEC3860
#define Util__FastTime_x                                           0x90FC70
#define __eq_delete_x                                              0x9B28AE
#define __eq_new_x                                                 0x9B2E74

////
// Section 4: Function Offsets
////

// CAAwnd
#define CAAWnd__ShowAbility_x                                      0x6D7970

// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490270
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499190
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x498F60
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493810
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492C60

// AltAdvManager
#define AltAdvManager__GetCalculatedTimer_x                        0x5611C0
#define AltAdvManager__IsAbilityReady_x                            0x55FF60
#define AltAdvManager__GetAAById_x                                 0x5602F0
#define AltAdvManager__CanTrainAbility_x                           0x560360
#define AltAdvManager__CanSeeAbility_x                             0x5606C0

// CharacterZoneClient
#define CharacterZoneClient__BardCastBard_x                        0x4C57B0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C3EF0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C40C0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BAB60
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C9DC0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C2C30
#define CharacterZoneClient__FindItemByGuid_x                      0x4D72C0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D6D40
#define CharacterZoneClient__GetCurrentMod_x                       0x4E4A70
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D8EC0
#define CharacterZoneClient__GetEffect_x                           0x4BAAA0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C3D50
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2A20
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D8DE0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8D00
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C3DA0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAC30
#define CharacterZoneClient__GetModCap_x                           0x4E4970
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C3C80
#define CharacterZoneClient__HasSkill_x                            0x4D4C40
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE530
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6360

// CBankWnd
#define CBankWnd__GetNumBankSlots_x                                0x6F1270
#define CBankWnd__WndNotification_x                                0x6F1050

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6FEC00

// CButtonWnd
#define CButtonWnd__SetCheck_x                                     0x62CBA0
#define CButtonWnd__CButtonWnd_x                                   0x949D90
#define CButtonWnd__dCButtonWnd_x                                  0x94A060
#define CButtonWnd__vftable_x                                      0xB52DC8

// CChatWindowManager
#define CChatWindowManager__GetRGBAFromIndex_x                     0x71EDC0
#define CChatWindowManager__InitContextMenu_x                      0x717EF0
#define CChatWindowManager__FreeChatWindow_x                       0x71D900
#define CChatWindowManager__GetLockedActiveChatWindow_x            0x4E8230
#define CChatWindowManager__SetLockedActiveChatWindow_x            0x71EA40
#define CChatWindowManager__CreateChatWindow_x                     0x71DF40

// ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8340

// CChatWindow
#define CChatWindow__CChatWindow_x                                 0x71F670
#define CChatWindow__Clear_x                                       0x720930
#define CChatWindow__WndNotification_x                             0x7210C0
#define CChatWindow__AddHistory_x                                  0x7201F0

// CContextMenu
#define CContextMenu__CContextMenu_x                               0x95E400
#define CContextMenu__dCContextMenu_x                              0x95E640
#define CContextMenu__AddMenuItem_x                                0x95E650
#define CContextMenu__RemoveMenuItem_x                             0x95E960
#define CContextMenu__RemoveAllMenuItems_x                         0x95E980
#define CContextMenu__CheckMenuItem_x                              0x95EA00
#define CContextMenu__SetMenuItem_x                                0x95E880
#define CContextMenu__AddSeparator_x                               0x95E7E0

// CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x95EFA0
#define CContextMenuManager__RemoveMenu_x                          0x95F010
#define CContextMenuManager__PopupMenu_x                           0x95F0D0
#define CContextMenuManager__Flush_x                               0x95EF40
#define CContextMenuManager__GetMenu_x                             0x49B2B0
#define CContextMenuManager__CreateDefaultMenu_x                   0x72A5C0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8EB240
#define CChatService__GetFriendName_x                              0x8EB250

// CComboWnd
#define CComboWnd__DeleteAll_x                                     0x95B860
#define CComboWnd__Draw_x                                          0x95AD40
#define CComboWnd__GetCurChoice_x                                  0x95B6A0
#define CComboWnd__GetListRect_x                                   0x95B200
#define CComboWnd__GetTextRect_x                                   0x95B8D0
#define CComboWnd__InsertChoice_x                                  0x95B390
#define CComboWnd__SetColors_x                                     0x95B360
#define CComboWnd__SetChoice_x                                     0x95B670
#define CComboWnd__GetItemCount_x                                  0x95B6B0
#define CComboWnd__GetCurChoiceText_x                              0x95B6F0
#define CComboWnd__GetChoiceText_x                                 0x95B6C0
#define CComboWnd__InsertChoiceAtIndex_x                           0x95B430

// CContainerWnd
#define CContainerWnd__HandleCombine_x                             0x727FA0
#define CContainerWnd__vftable_x                                   0xB2157C
#define CContainerWnd__SetContainer_x                              0x729500

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x553A30
#define CDisplay__PreZoneMainUI_x                                  0x553A40
#define CDisplay__CleanGameUI_x                                    0x558E40
#define CDisplay__GetClickedActor_x                                0x54BD30
#define CDisplay__GetUserDefinedColor_x                            0x544390
#define CDisplay__GetWorldFilePath_x                               0x54D7A0
#define CDisplay__is3dON_x                                         0x548990
#define CDisplay__ReloadUI_x                                       0x552EB0
#define CDisplay__WriteTextHD2_x                                   0x548780
#define CDisplay__TrueDistance_x                                   0x54F460
#define CDisplay__SetViewActor_x                                   0x54B650
#define CDisplay__GetFloorHeight_x                                 0x548A50
#define CDisplay__SetRenderWindow_x                                0x5473B0
#define CDisplay__ToggleScreenshotMode_x                           0x54B120

// CEditBaseWnd
#define CEditBaseWnd__SetSel_x                                     0x97E090

// CEditWnd
#define CEditWnd__DrawCaret_x                                      0x961970
#define CEditWnd__EnsureCaretVisible_x                             0x963B40
#define CEditWnd__GetCaretPt_x                                     0x962AF0
#define CEditWnd__GetCharIndexPt_x                                 0x9628A0
#define CEditWnd__GetDisplayString_x                               0x962740
#define CEditWnd__GetHorzOffset_x                                  0x960FA0
#define CEditWnd__GetLineForPrintableChar_x                        0x963A40
#define CEditWnd__GetSelStartPt_x                                  0x962B50
#define CEditWnd__GetSTMLSafeText_x                                0x962560
#define CEditWnd__PointFromPrintableChar_x                         0x963670
#define CEditWnd__ReplaceSelection_x                               0x9632E0
#define CEditWnd__SelectableCharFromPoint_x                        0x9637E0
#define CEditWnd__SetEditable_x                                    0x962C20
#define CEditWnd__SetWindowTextA_x                                 0x9622E0

// CEverQuest
#define CEverQuest__DoPercentConvert_x                             0x60BF90
#define CEverQuest__ClickedPlayer_x                                0x5FE0C0
#define CEverQuest__CreateTargetIndicator_x                        0x61B650
#define CEverQuest__DeleteTargetIndicator_x                        0x61B6E0
#define CEverQuest__DoTellWindow_x                                 0x4E8420
#define CEverQuest__OutputTextToLog_x                              0x4E86F0
#define CEverQuest__DropHeldItemOnGround_x                         0x5F3100
#define CEverQuest__dsp_chat_x                                     0x4E8A80
#define CEverQuest__trimName_x                                     0x6177C0
#define CEverQuest__Emote_x                                        0x60C7F0
#define CEverQuest__EnterZone_x                                    0x606890
#define CEverQuest__GetBodyTypeDesc_x                              0x6110B0
#define CEverQuest__GetClassDesc_x                                 0x6116F0
#define CEverQuest__GetClassThreeLetterCode_x                      0x611CF0
#define CEverQuest__GetDeityDesc_x                                 0x619EA0
#define CEverQuest__GetLangDesc_x                                  0x611EB0
#define CEverQuest__GetRaceDesc_x                                  0x6116D0
#define CEverQuest__InterpretCmd_x                                 0x61A470
#define CEverQuest__LeftClickedOnPlayer_x                          0x5F7300
#define CEverQuest__LMouseUp_x                                     0x5F5690
#define CEverQuest__RightClickedOnPlayer_x                         0x5F7BE0
#define CEverQuest__RMouseUp_x                                     0x5F6610
#define CEverQuest__SetGameState_x                                 0x5F2E90
#define CEverQuest__UPCNotificationFlush_x                         0x6176C0
#define CEverQuest__IssuePetCommand_x                              0x6132B0
#define CEverQuest__ReportSuccessfulHeal_x                         0x60D510
#define CEverQuest__ReportSuccessfulHit_x                          0x60DB40

// CGaugeWnd
// not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x739F30
#define CGaugeWnd__CalcLinesFillRect_x                             0x739F90
#define CGaugeWnd__Draw_x                                          0x7395B0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF500
#define CGuild__GetGuildName_x                                     0x4AE540
#define CGuild__GetGuildIndex_x                                    0x4AE980

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton_x                               0x7540F0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x62CF60

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot_x                                 0x761070
#define CInvSlotMgr__MoveItem_x                                    0x75FDE0
#define CInvSlotMgr__SelectSlot_x                                  0x761140

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x75E660
#define CInvSlot__SliderComplete_x                                 0x75C3C0
#define CInvSlot__GetItemBase_x                                    0x75BD60
#define CInvSlot__UpdateItem_x                                     0x75BED0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x762BC0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x761D60
#define CInvSlotWnd__HandleLButtonUp_x                             0x762740

// CItemDisplayWnd
#define CItemDisplayWnd__SetSpell_x                                0x81CCE0
#define CItemDisplayWnd__UpdateStrings_x                           0x7711F0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x76AF50
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x76B450
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x771800
#define CItemDisplayWnd__AboutToShow_x                             0x770E30
#define CItemDisplayWnd__WndNotification_x                         0x772920
#define CItemDisplayWnd__RequestConvertItem_x                      0x7723A0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x76FE90
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x770C50

// CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x855840

// CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x776E50

// CKeyRingWnd
#define CKeyRingWnd__ExecuteRightClick_x                           0x519760

// CLabel
#define CLabel__Draw_x                                             0x77C890

// CListWnd
#define CListWnd__CListWnd_x                                       0x933EC0
#define CListWnd__dCListWnd_x                                      0x9341E0
#define CListWnd__vftable_x                                        0xB526A0
#define CListWnd__AddColumn_x                                      0x938620
#define CListWnd__AddColumn1_x                                     0x938670
#define CListWnd__AddLine_x                                        0x938A00
#define CListWnd__AddString_x                                      0x938800
#define CListWnd__CalculateFirstVisibleLine_x                      0x9383E0
#define CListWnd__CalculateVSBRange_x                              0x9381E0
#define CListWnd__ClearSel_x                                       0x9391E0
#define CListWnd__ClearAllSel_x                                    0x939240
#define CListWnd__CloseAndUpdateEditWindow_x                       0x939C60
#define CListWnd__Compare_x                                        0x937B10
#define CListWnd__Draw_x                                           0x934310
#define CListWnd__DrawColumnSeparators_x                           0x936AF0
#define CListWnd__DrawHeader_x                                     0x936F50
#define CListWnd__DrawItem_x                                       0x937450
#define CListWnd__DrawLine_x                                       0x936C50
#define CListWnd__DrawSeparator_x                                  0x936B90
#define CListWnd__EnableLine_x                                     0x9363D0
#define CListWnd__EnsureVisible_x                                  0x939B80
#define CListWnd__ExtendSel_x                                      0x939110
#define CListWnd__GetColumnTooltip_x                               0x935F10
#define CListWnd__GetColumnMinWidth_x                              0x935F80
#define CListWnd__GetColumnWidth_x                                 0x935E80
#define CListWnd__GetCurSel_x                                      0x935810
#define CListWnd__GetItemAtPoint_x                                 0x936640
#define CListWnd__GetItemAtPoint1_x                                0x9366B0
#define CListWnd__GetItemData_x                                    0x935890
#define CListWnd__GetItemHeight_x                                  0x935C50
#define CListWnd__GetItemIcon_x                                    0x935A20
#define CListWnd__GetItemRect_x                                    0x9364C0
#define CListWnd__GetItemText_x                                    0x9358D0
#define CListWnd__GetSelList_x                                     0x939290
#define CListWnd__GetSeparatorRect_x                               0x9368F0
#define CListWnd__InsertLine_x                                     0x938DF0
#define CListWnd__RemoveLine_x                                     0x938F40
#define CListWnd__SetColors_x                                      0x9381B0
#define CListWnd__SetColumnJustification_x                         0x937EE0
#define CListWnd__SetColumnLabel_x                                 0x9387A0
#define CListWnd__SetColumnWidth_x                                 0x937E00
#define CListWnd__SetCurSel_x                                      0x939050
#define CListWnd__SetItemColor_x                                   0x939830
#define CListWnd__SetItemData_x                                    0x9397F0
#define CListWnd__SetItemText_x                                    0x939400
#define CListWnd__ShiftColumnSeparator_x                           0x937FA0
#define CListWnd__Sort_x                                           0x937C90
#define CListWnd__ToggleSel_x                                      0x939080
#define CListWnd__SetColumnsSizable_x                              0x938050
#define CListWnd__SetItemWnd_x                                     0x9396B0
#define CListWnd__GetItemWnd_x                                     0x935A70
#define CListWnd__SetItemIcon_x                                    0x939480
#define CListWnd__CalculateCustomWindowPositions_x                 0x9384E0
#define CListWnd__SetVScrollPos_x                                  0x937DE0

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd_x                                 0x7920D0

// MapViewMap
#define MapViewMap__MapViewMap_x                                   0x78D5C0
#define MapViewMap__dMapViewMap_x                                  0x78D710
#define MapViewMap__vftable_x                                      0xB28BC0
#define MapViewMap__Clear_x                                        0x78DF40
#define MapViewMap__SaveEx_x                                       0x791300
#define MapViewMap__SetZoom_x                                      0x7959C0
#define MapViewMap__HandleLButtonDown_x                            0x78D820
#define MapViewMap__GetWorldCoordinates_x                          0x7907E0

// CMerchantWnd
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7B22F0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7B2BD0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7B3100
#define CMerchantWnd__SelectRecoverySlot_x                         0x7B6070
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7B0E70
#define CMerchantWnd__SelectBuySellSlot_x                          0x7BBC20
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7B1F10

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8B8D90
#define CPacketScrambler__hton_x                                   0x8B8D80

// CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x9573B0
#define CSidlManagerBase__CreatePageWnd_x                          0x956BA0
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x952E20
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x952DB0
#define CSidlManagerBase__FindAnimation1_x                         0x953000
#define CSidlManagerBase__FindScreenPieceTemplate_x                0x953410
#define CSidlManagerBase__FindScreenPieceTemplate1_x               0x953200
#define CSidlManagerBase__CreateLabel_x                            0x813FB0
#define CSidlManagerBase__CreateXWndFromTemplate_x                 0x956370
#define CSidlManagerBase__CreateXWndFromTemplate1_x                0x956550
#define CSidlManagerBase__CreateXWnd_x                             0x813EE0

// CSidlManager
#define CSidlManager__CreateHotButtonWnd_x                         0x8144B0

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateHSBRange_x                        0x94FAF0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x94F9F0
#define CSidlScreenWnd__ConvertToRes_x                             0x978B70
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x94F480
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x94F170
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x94F240
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x94F310
#define CSidlScreenWnd__DrawSidlPiece_x                            0x94FF80
#define CSidlScreenWnd__EnableIniStorage_x                         0x950450
#define CSidlScreenWnd__GetChildItem_x                             0x9503D0
#define CSidlScreenWnd__GetSidlPiece_x                             0x950170
#define CSidlScreenWnd__HandleLButtonUp_x                          0x93FA60
#define CSidlScreenWnd__Init1_x                                    0x94ED70
#define CSidlScreenWnd__LoadIniInfo_x                              0x9504A0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x950FE0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x94E180
#define CSidlScreenWnd__m_layoutCopy_x                             0x1600A58
#define CSidlScreenWnd__StoreIniInfo_x                             0x950B60
#define CSidlScreenWnd__StoreIniVis_x                              0x950EC0
#define CSidlScreenWnd__vftable_x                                  0xB53058
#define CSidlScreenWnd__WndNotification_x                          0x94FE90

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x691810
#define CSkillMgr__GetSkillCap_x                                   0x6919F0
#define CSkillMgr__GetNameToken_x                                  0x690F90
#define CSkillMgr__IsActivatedSkill_x                              0x6910D0
#define CSkillMgr__IsCombatSkill_x                                 0x691010

// CSliderWnd
#define CSliderWnd__GetValue_x                                     0x95FD80
#define CSliderWnd__SetValue_x                                     0x95FBF0
#define CSliderWnd__SetNumTicks_x                                  0x95FC50

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet_x                               0x81A0B0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x968590
#define CStmlWnd__CalculateHSBRange_x                              0x9696B0
#define CStmlWnd__CalculateVSBRange_x                              0x969620
#define CStmlWnd__CanBreakAtCharacter_x                            0x96D9E0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x96E670
#define CStmlWnd__ForceParseNow_x                                  0x968B80
#define CStmlWnd__GetNextTagPiece_x                                0x96D940
#define CStmlWnd__GetSTMLText_x                                    0x509100
#define CStmlWnd__GetVisibleText_x                                 0x968BA0
#define CStmlWnd__InitializeWindowVariables_x                      0x96E4C0
#define CStmlWnd__MakeStmlColorTag_x                               0x967C00
#define CStmlWnd__MakeWndNotificationTag_x                         0x967C70
#define CStmlWnd__SetSTMLText_x                                    0x966CB0
#define CStmlWnd__StripFirstSTMLLines_x                            0x96F740
#define CStmlWnd__UpdateHistoryString_x                            0x96E880

// CTabWnd
#define CTabWnd__Draw_x                                            0x965E00
#define CTabWnd__DrawCurrentPage_x                                 0x966530
#define CTabWnd__DrawTab_x                                         0x966250
#define CTabWnd__GetCurrentPage_x                                  0x965600
#define CTabWnd__GetCurrentTabIndex_x                              0x9655F0
#define CTabWnd__GetPageFromTabIndex_x                             0x966190
#define CTabWnd__GetPageInnerRect_x                                0x965840
#define CTabWnd__GetTabInnerRect_x                                 0x965780
#define CTabWnd__GetTabRect_x                                      0x965630
#define CTabWnd__InsertPage_x                                      0x965A50
#define CTabWnd__RemovePage_x                                      0x965BC0
#define CTabWnd__SetPage_x                                         0x9658C0
#define CTabWnd__SetPageRect_x                                     0x965D40
#define CTabWnd__UpdatePage_x                                      0x966110

// CPageWnd
#define CPageWnd__FlashTab_x                                       0x9651B0
#define CPageWnd__GetTabText_x                                     0x777220
#define CPageWnd__SetTabText_x                                     0x965150


// CTextOverlay
#define CTextOverlay__DisplayText_x                                0x4A8F50

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x93C8E0
#define CTextureFont__DrawWrappedText1_x                           0x93C810
#define CTextureFont__DrawWrappedText2_x                           0x93C930
#define CTextureFont__GetTextExtent_x                              0x93CAA0

// CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6C45B0
#define CHtmlComponentWnd__ValidateUri_x                           0x755AE0
#define CHtmlWnd__SetClientCallbacks_x                             0x631FE0
#define CHtmlWnd__AddObserver_x                                    0x632000
#define CHtmlWnd__RemoveObserver_x                                 0x632060
#define Window__getProgress_x                                      0x86E190
#define Window__getStatus_x                                        0x86E1B0
#define Window__getURI_x                                           0x86E1C0

// CXMLDataManager
#define CXMLDataManager__GetXMLData_x                              0x975980

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead_x                             0x929B90

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr_x                                             0x4E8120
#define CXStr__CXStr1_x                                            0x9325B0
#define CXStr__CXStr3_x                                            0x90C200
#define CXStr__dCXStr_x                                            0x478780
#define CXStr__operator_equal_x                                    0x90C430
#define CXStr__operator_equal1_x                                   0x90C470
#define CXStr__operator_plus_equal1_x                              0x90CF00
#define CXStr__SetString_x                                         0x90EDF0
#define CXStr__operator_char_p_x                                   0x90C970
#define CXStr__GetChar_x                                           0x90E720
#define CXStr__Delete_x                                            0x90DFF0
#define CXStr__GetUnicode_x                                        0x90E790
#define CXStr__GetLength_x                                         0x47D490
#define CXStr__Mid_x                                               0x47D4A0
#define CXStr__Insert_x                                            0x90E7F0
#define CXStr__FindNext_x                                          0x90E460
#define CXStr__gFreeLists_x                                        0xCAE580
#define CXStr__gCXStrAccess_x                                      0x160017C

// CTileLayoutWnd
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x95E020

// CXWnd
#define CXWnd__BringToTop_x                                        0x943270
#define CXWnd__Center_x                                            0x942DF0
#define CXWnd__ClrFocus_x                                          0x942C00
#define CXWnd__Destroy_x                                           0x942CB0
#define CXWnd__DoAllDrawing_x                                      0x93F1F0
#define CXWnd__DrawChildren_x                                      0x93F1C0
#define CXWnd__DrawColoredRect_x                                   0x93F650
#define CXWnd__DrawTooltip_x                                       0x93DD00
#define CXWnd__DrawTooltipAtPoint_x                                0x93DDC0
#define CXWnd__GetBorderFrame_x                                    0x93F4B0
#define CXWnd__GetChildItem_x                                      0x943480
#define CXWnd__GetChildWndAt_x                                     0x943310
#define CXWnd__GetClientClipRect_x                                 0x941490
#define CXWnd__GetRelativeRect_x                                   0x9417F0
#define CXWnd__GetScreenClipRect_x                                 0x941560
#define CXWnd__GetScreenRect_x                                     0x941730
#define CXWnd__GetTooltipRect_x                                    0x93F6A0
#define CXWnd__GetWindowTextA_x                                    0x49CA20
#define CXWnd__IsActive_x                                          0x93FDE0
#define CXWnd__IsDescendantOf_x                                    0x942130
#define CXWnd__IsReallyVisible_x                                   0x942160
#define CXWnd__IsType_x                                            0x943970
#define CXWnd__Minimize_x                                          0x942880
#define CXWnd__Move_x                                              0x9421D0
#define CXWnd__Move1_x                                             0x942290
#define CXWnd__ProcessTransition_x                                 0x942DA0
#define CXWnd__Refade_x                                            0x942570
#define CXWnd__Resize_x                                            0x942810
#define CXWnd__Right_x                                             0x943030
#define CXWnd__SetFocus_x                                          0x942BC0
#define CXWnd__SetFont_x                                           0x942C30
#define CXWnd__SetKeyTooltip_x                                     0x943790
#define CXWnd__SetMouseOver_x                                      0x9405E0
#define CXWnd__SetParent_x                                         0x941ED0
#define CXWnd__StartFade_x                                         0x942010
#define CXWnd__vftable_x                                           0xB52AE4
#define CXWnd__CXWnd_x                                             0x93CDC0
#define CXWnd__dCXWnd_x                                            0x93D300

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x979BF0

// CXWndManager
#define CXWndManager__DrawCursor_x                                 0x946220
#define CXWndManager__DrawWindows_x                                0x946240
#define CXWndManager__GetKeyboardFlags_x                           0x948A40
#define CXWndManager__HandleKeyboardMsg_x                          0x9485F0
#define CXWndManager__RemoveWnd_x                                  0x948C60
#define CXWndManager__RemovePendingDeletionWnd_x                   0x9491D0

// CDBStr
#define CDBStr__GetString_x                                        0x543360

// CharacterZoneClient
#define CharacterZoneClient__CanUseItem_x                          0x4D96D0
#define CharacterZoneClient__CastSpell_x                           0x4BBB40
#define CharacterZoneClient__Cur_HP_x                              0x4D1C80
#define CharacterZoneClient__Cur_Mana_x                            0x4D93C0
#define CharacterZoneClient__GetAdjustedSkill_x                    0x4D4A00
#define CharacterZoneClient__GetBaseSkill_x                        0x4D59A0
#define CharacterZoneClient__GetCastingTimeModifier_x              0x4BEB80
#define CharacterZoneClient__GetEnduranceRegen_x                   0x4DF790
#define CharacterZoneClient__GetFocusCastingTimeModifier_x         0x4B2660
#define CharacterZoneClient__GetFocusRangeModifier_x               0x4B27B0
#define CharacterZoneClient__GetHPRegen_x                          0x4DF190
#define CharacterZoneClient__GetManaRegen_x                        0x4DFBD0
#define CharacterZoneClient__GetPCSpellAffect_x                    0x4BF8D0
#define CharacterZoneClient__Max_Endurance_x                       0x658590
#define CharacterZoneClient__Max_HP_x                              0x4D1AB0
#define CharacterZoneClient__Max_Mana_x                            0x658390
#define CharacterZoneClient__SpellDuration_x                       0x4BF400
#define CharacterZoneClient__TotalEffect_x                         0x4C4EF0
#define CharacterZoneClient__UseSkill_x                            0x4E19B0

// ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8D81B0

// PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x66EB10

// PcClient
#define PcClient__PcClient_x                                       0x64EAF0
#define PcClient__GetConLevel_x                                    0x6513A0

// CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B97B0
#define CCharacterListWnd__EnterWorld_x                            0x4B91F0
#define CCharacterListWnd__Quit_x                                  0x4B8F40
#define CCharacterListWnd__UpdateList_x                            0x4B9380

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6331C0
#define EQ_Item__CreateItemTagString_x                             0x8B2320
#define EQ_Item__IsStackable_x                                     0x8B7000
#define EQ_Item__GetImageNum_x                                     0x8B3DE0
#define EQ_Item__CreateItemClient_x                                0x632400
#define EQ_Item__GetItemValue_x                                    0x8B51E0
#define EQ_Item__ValueSellMerchant_x                               0x8B8970
#define EQ_Item__IsKeyRingItem_x                                   0x8B6920
#define EQ_Item__CanGoInBag_x                                      0x6332E0
#define EQ_Item__IsEmpty_x                                         0x8B6460
#define EQ_Item__GetMaxItemCount_x                                 0x8B55F0
#define EQ_Item__GetHeldItem_x                                     0x8B3CB0
#define EQ_Item__GetAugmentFitBySlot_x                             0x8B1B80
#define ItemClient__ItemClient_x                                   0x5B2D50
#define ItemClient__dItemClient_x                                  0x632350

// EQ_LoadingS
#define EQ_LoadingS__SetProgressBar_x                              0x561E90
#define EQ_LoadingS__Array_x                                       0xC37C60

// EQ_PC
#define EQ_PC__GetAlternateAbilityId_x                             0x8C1E30
#define EQ_PC__GetCombatAbility_x                                  0x8C24A0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8C2510
#define EQ_PC__GetItemRecastTimer_x                                0x65AF40
#define EQ_PC__HasLoreItem_x                                       0x651B60
#define EQ_PC__AlertInventoryChanged_x                             0x650CE0
#define EQ_PC__GetPcZoneClient_x                                   0x67D510
#define EQ_PC__RemoveMyAffect_x                                    0x65E170
#define EQ_PC__GetKeyRingItems_x                                   0x8C2DA0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8C2B30
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8C30A0

// EQItemList
#define EQItemList__EQItemList_x                                   0x5BAFD0
#define EQItemList__add_object_x                                   0x5E88E0
#define EQItemList__add_item_x                                     0x5BB530
#define EQItemList__delete_item_x                                  0x5BB580
#define EQItemList__FreeItemList_x                                 0x5BB480

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x53FE70

// EQPlayer
#define EQPlayer__ChangeBoneStringSprite_x                         0x670390
#define EQPlayer__dEQPlayer_x                                      0x663690
#define EQPlayer__DoAttack_x                                       0x6781B0
#define EQPlayer__EQPlayer_x                                       0x663D50
#define EQPlayer__SetNameSpriteState_x                             0x668070
#define EQPlayer__SetNameSpriteTint_x                              0x668F40
#define PlayerBase__HasProperty_j_x                                0x9A87D0
#define EQPlayer__IsTargetable_x                                   0x9A8C70
#define EQPlayer__CanSee_x                                         0x9A8AD0
#define EQPlayer__CanSee1_x                                        0x9A8BA0
#define PlayerBase__GetVisibilityLineSegment_x                     0x9A8890

// PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x67AFB0
#define PlayerZoneClient__GetLevel_x                               0x67D550
#define PlayerZoneClient__IsValidTeleport_x                        0x5E9A50
#define PlayerZoneClient__LegalPlayerRace_x                        0x55AC70

// EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x6730D0
#define EQPlayerManager__GetSpawnByName_x                          0x673180
#define EQPlayerManager__GetPlayerFromPartialName_x                0x673210

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x6368F0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x636970
#define KeypressHandler__AttachKeyToEqCommand_x                    0x6369B0
#define KeypressHandler__ClearCommandStateArray_x                  0x637DC0
#define KeypressHandler__HandleKeyDown_x                           0x637DE0
#define KeypressHandler__HandleKeyUp_x                             0x637E80
#define KeypressHandler__SaveKeymapping_x                          0x6382D0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8D6210

// StringTable
#define StringTable__getString_x                                   0x8D1130

// PcZoneClient
#define PcZoneClient__doCombatAbility_x                            0x65A9C0
#define PcZoneClient__DestroyHeldItemOrMoney_x                     0x658ED0
#define PcZoneClient__GetPcSkillLimit_x                            0x65DDE0
#define PcZoneClient__RemovePetEffect_x                            0x65E410
#define PcZoneClient__HasAlternateAbility_x                        0x6581C0
#define PcZoneClient__CanEquipItem_x                               0x658870
#define PcZoneClient__GetItemByID_x                                0x65B3B0
#define PcZoneClient__GetItemByItemClass_x                         0x65B500
#define PcZoneClient__RemoveBuffEffect_x                           0x65E430
#define PcZoneClient__BandolierSwap_x                              0x659480
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x65AEE0

// Doors
#define EQSwitch__UseSwitch_x                                      0x5EE610

// IconCache
#define IconCache__GetIcon_x                                       0x72F690

// CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x727140
#define CContainerMgr__CloseContainer_x                            0x727410
#define CContainerMgr__OpenExperimentContainer_x                   0x727E90

// CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7E6370

// CHelpWnd
#define CHelpWnd__SetFile_x                                        0x62B360

// CLootWnd
#define CLootWnd__LootAll_x                                        0x7843D0
#define CLootWnd__RequestLootSlot_x                                0x783600

// EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x588310
#define EQ_Spell__SpellAffects_x                                   0x588780
#define EQ_Spell__SpellAffectBase_x                                0x588540
#define EQ_Spell__IsStackable_x                                    0x4C96C0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C94E0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6B30
#define EQ_Spell__IsSPAStacking_x                                  0x5895D0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x588AE0
#define EQ_Spell__IsNoRemove_x                                     0x4C96A0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x5895E0
#define __IsResEffectSpell_x                                       0x4C8950

// EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD0C0

// EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8E0730

// CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x82D490
#define CTargetWnd__WndNotification_x                              0x82CCD0
#define CTargetWnd__RefreshTargetBuffs_x                           0x82CFA0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x82BE30

// CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x831AD0
#define CTaskWnd__ConfirmAbandonTask_x                             0x8345D0

// CTaskManager
#define CTaskManager__GetEntry_x                                   0x53D8B0
#define CTaskManager__HandleMessage_x                              0x53BD30
#define CTaskManager__GetTaskStatus_x                              0x53D960
#define CTaskManager__GetElementDescription_x                      0x53D9E0

// EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x583470
#define EqSoundManager__PlayScriptMp3_x                            0x583730
#define EqSoundManager__SoundAssistPlay_x                          0x695740
#define EqSoundManager__WaveInstancePlay_x                         0x694CB0

// CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52EFA0

// CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x964660

// CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x5699C0
#define CAltAbilityData__GetMercMaxRank_x                          0x569950
#define CAltAbilityData__GetMaxRank_x                              0x55EDE0

// CTargetRing
#define CTargetRing__Cast_x                                        0x629480

// CharacterBase
#define CharacterBase__CreateItemGlobalIndex_x                     0x515DD0
#define CharacterBase__CreateItemIndex_x                           0x631590
#define CharacterBase__GetItemByGlobalIndex_x                      0x8E8D60
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8E8DC0
#define CharacterBase__GetItemPossession_x                         0x5019F0
#define CharacterBase__GetMemorizedSpell_x                         0x4C94C0
#define CharacterBase__IsExpansionFlag_x                           0x5B4A70

// CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x70E020
#define CCastSpellWnd__IsBardSongPlaying_x                         0x70E850
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x70E900

// messages
#define msg_spell_worn_off_x                                       0x5ACF20
#define msg_new_text_x                                             0x5A1900
#define __msgTokenTextParam_x                                      0x5AF1C0
#define msgTokenText_x                                             0x5AF410

// SpellManager
#define SpellManager__vftable_x                                    0xAFB150
#define SpellManager__SpellManager_x                               0x698A60
#define Spellmanager__LoadTextSpells_x                             0x699350
#define SpellManager__GetSpellByGroupAndRank_x                     0x698C30

// CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x 0x9AC780

// ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8E10D0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8E1350

// CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x77CBD0

// CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x72B860
#define CCursorAttachment__AttachToCursor1_x                       0x72B8A0
#define CCursorAttachment__Deactivate_x                            0x72C890

// CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x974540
#define CEQSuiteTextureLoader__GetTexture_x                        0x974200

// CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x513340
#define CFindItemWnd__WndNotification_x                            0x513E20
#define CFindItemWnd__Update_x                                     0x514990
#define CFindItemWnd__PickupSelectedItem_x                         0x512B90

// IString
#define IString__Append_x                                          0x5032D0

// Camera
#define CDisplay__cameraType_x                                     0xE1124C
#define EverQuest__Cameras_x                                       0xECC534

// LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51BAF0
#define LootFiltersManager__GetItemFilterData_x                    0x51B400
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51B430
#define LootFiltersManager__SetItemLootFilter_x                    0x51B650

// COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7D4160

// CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9B2320
#define CResolutionHandler__GetWindowedStyle_x                     0x6902F0

// CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x723DE0

// CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8F6660
#define CDistillerInfo__Instance_x                                 0x8F6600

// CGroupWnd
#define CGroupWnd__WndNotification_x                               0x742F00
#define CGroupWnd__UpdateDisplay_x                                 0x742250

// ItemBase
#define ItemBase__IsLore_x                                         0x8B69D0
#define ItemBase__IsLoreEquipped_x                                 0x8B6A40

// EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5E8840
#define EQPlacedItemManager__GetItemByGuid_x                       0x5E8980
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5E89E0

// RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x685C90
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x689660

// CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x509700

// FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F5BA0
#define FactionManagerClient__HandleFactionMessage_x               0x4F6210
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F6810
#define FactionManagerClient__GetMaxFaction_x                      0x4F682F
#define FactionManagerClient__GetMinFaction_x                      0x4F67E0

// BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x5019C0

// ArrayClass
#define ArrayClass__DeleteElement_x                                0x93B900

// AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BD30

// ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x501CC0

// MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x568E80

// CTargetManager
#define CTargetManager__Get_x                                      0x69C2E0

// RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x685C90

// CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8D10

// EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5BB420

// EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF69BC8

// KeyCombo
#define KeyCombo__GetTextDescription_x                             0x926260

//
// EQGraphicsDX9.dll offsets (maybe this should go in eqgraphics.h?)
//

#define __eqgraphics_fopen_x                                       0x10147468
#define CParticleSystem__Render_x                                  0x10071190
