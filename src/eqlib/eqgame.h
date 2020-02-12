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
#define __ExpectedVersionDate                                     "Feb 10 2020"
#define __ExpectedVersionTime                                     "18:39:00"
#define __ActualVersionDate_x                                      0xB16BD0
#define __ActualVersionTime_x                                      0xB16BC4
#define __ActualVersionBuild_x                                     0xB028F4

// Memory Protection
#define __MemChecker0_x                                            0x63B130
#define __MemChecker1_x                                            0x90E550
#define __MemChecker2_x                                            0x6CA200
#define __MemChecker3_x                                            0x6CA150
#define __MemChecker4_x                                            0x865090
#define __EncryptPad0_x                                            0xC4E3F0
#define __EncryptPad1_x                                            0xCAC658
#define __EncryptPad2_x                                            0xC5EC88
#define __EncryptPad3_x                                            0xC5E888
#define __EncryptPad4_x                                            0xC9CC08
#define __EncryptPad5_x                                            0xF6D814
#define __AC1_x                                                    0x8218F6
#define __AC2_x                                                    0x5F4C6F
#define __AC3_x                                                    0x5FC36F
#define __AC4_x                                                    0x600340
#define __AC5_x                                                    0x60664F
#define __AC6_x                                                    0x60AB46
#define __AC7_x                                                    0x5F46E0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x192EC8

// Direct Input
#define DI8__Main_x                                                0xF6D834
#define DI8__Keyboard_x                                            0xF6D838
#define DI8__Mouse_x                                               0xF6D854
#define DI8__Mouse_Copy_x                                          0xEC8EBC
#define DI8__Mouse_Check_x                                         0xF6E300
#define __AutoSkillArray_x                                         0xEC9DD4
#define __Attack_x                                                 0xF67BFB
#define __Autofire_x                                               0xF67BFC
#define __BindList_x                                               0xC3CE20
#define g_eqCommandStates_x                                        0xC3DBA0
#define __Clicks_x                                                 0xEC8F74
#define __CommandList_x                                            0xC3E760
#define __CurrentMapLabel_x                                        0xF806C4
#define __CurrentSocial_x                                          0xC267CC
#define __DoAbilityList_x                                          0xEFF71C
#define __do_loot_x                                                0x5C0710
#define __DrawHandler_x                                            0x15FFA40
#define __GroupCount_x                                             0xEC39D2
#define __Guilds_x                                                 0xEC7DD8
#define __gWorld_x                                                 0xEC3C20
#define __HWnd_x                                                   0xF6E2E0
#define __heqmain_x                                                0xF70794
#define __InChatMode_x                                             0xEC8EA4
#define __LastTell_x                                               0xECAE18
#define __LMouseHeldTime_x                                         0xEC8FE0
#define __Mouse_x                                                  0xF6D820
#define __MouseLook_x                                              0xEC8F3A
#define __MouseEventTime_x                                         0xF686DC
#define __gpbCommandEvent_x                                        0xEC3C28
#define __NetStatusToggle_x                                        0xEC8F3D
#define __PCNames_x                                                0xECA3C4
#define __RangeAttackReady_x                                       0xECA0B8
#define __RMouseHeldTime_x                                         0xEC8FDC
#define __RunWalkState_x                                           0xEC8EA8
#define __ScreenMode_x                                             0xE0F638
#define __ScreenX_x                                                0xEC8E5C
#define __ScreenY_x                                                0xEC8E58
#define __ScreenXMax_x                                             0xEC8E60
#define __ScreenYMax_x                                             0xEC8E64
#define __ServerHost_x                                             0xEC3E5B
#define __ServerName_x                                             0xEFF6DC
#define __ShiftKeyDown_x                                           0xEC9534
#define __ShowNames_x                                              0xECA274
#define __SocialChangedList_x                                      0xEFF764
#define __Socials_x                                                0xEFF7DC
#define __SubscriptionType_x                                       0xFC4BD0
#define __TargetAggroHolder_x                                      0xF83078
#define __ZoneType_x                                               0xEC9338
#define __GroupAggro_x                                             0xF830B8
#define __LoginName_x                                              0xF6DF8C
#define __Inviter_x                                                0xF67B78
#define __AttackOnAssist_x                                         0xECA230
#define __UseTellWindows_x                                         0xECA560
#define __gfMaxZoomCameraDistance_x                                0xB0C530
#define __gfMaxCameraDistance_x                                    0xB388DC
#define __pulAutoRun_x                                             0xEC8F58
#define __pulForward_x                                             0xECA598
#define __pulBackward_x                                            0xECA59C
#define __pulTurnRight_x                                           0xECA5A0
#define __pulTurnLeft_x                                            0xECA5A4
#define __pulStrafeLeft_x                                          0xECA5A8
#define __pulStrafeRight_x                                         0xECA5AC

////
//Section 1: Vital Offsets
////
#define instCRaid_x                                                0xEC4170
#define instEQZoneInfo_x                                           0xEC9130
#define pinstActiveBanker_x                                        0xEC3D08
#define pinstActiveCorpse_x                                        0xEC3D00
#define pinstActiveGMaster_x                                       0xEC3D04
#define pinstActiveMerchant_x                                      0xEC3CFC
#define pinstAltAdvManager_x                                       0xE103A8
#define pinstBandageTarget_x                                       0xEC3D18
#define pinstCamActor_x                                            0xE0F628
#define pinstCDBStr_x                                              0xE0F0C4
#define pinstCDisplay_x                                            0xEC3878
#define pinstCEverQuest_x                                          0xF6D850
#define pinstEverQuestInfo_x                                       0xEC8E50
#define pinstCharData_x                                            0xEC3C10
#define pinstCharSpawn_x                                           0xEC3D50
#define pinstControlledMissile_x                                   0xEC1864
#define pinstControlledPlayer_x                                    0xEC3D50
#define pinstCResolutionHandler_x                                  0x15FFC70
#define pinstCSidlManager_x                                        0x15FEC08
#define pinstCXWndManager_x                                        0x15FEC04
#define instDynamicZone_x                                          0xEC7CB0
#define pinstDZMember_x                                            0xEC7DC0
#define pinstDZTimerInfo_x                                         0xEC7DC4
#define pinstEqLogin_x                                             0xF6D8D8
#define instEQMisc_x                                               0xE0F008
#define pinstEQSoundManager_x                                      0xE11378
#define pinstEQSpellStrings_x                                      0xCD19E8
#define instExpeditionLeader_x                                     0xEC7CFA
#define instExpeditionName_x                                       0xEC7D3A
#define pinstSGraphicsEngine_x                                     0x15FFA34
#define pinstGroup_x                                               0xEC39CE
#define pinstImeManager_x                                          0x15FEC00
#define pinstLocalPlayer_x                                         0xEC3CF8
#define pinstMercenaryData_x                                       0xF6A1D4
#define pinstMercenaryStats_x                                      0xF831C4
#define pinstModelPlayer_x                                         0xEC3D10
#define pinstPCData_x                                              0xEC3C10
#define pinstSkillMgr_x                                            0xF6C338
#define pinstSpawnManager_x                                        0xF6ADE0
#define pinstSpellManager_x                                        0xF6C578
#define pinstSpellSets_x                                           0xF60824
#define pinstStringTable_x                                         0xEC3C1C
#define pinstSwitchManager_x                                       0xEC1710
#define pinstTarget_x                                              0xEC3D4C
#define pinstTargetObject_x                                        0xEC3F64
#define pinstTargetSwitch_x                                        0xEC186C
#define pinstTaskMember_x                                          0xE0EE98
#define pinstTrackTarget_x                                         0xEC3D54
#define pinstTradeTarget_x                                         0xEC3D0C
#define instTributeActive_x                                        0xE0F029
#define pinstViewActor_x                                           0xE0F624
#define pinstWorldData_x                                           0xEC3874
#define pinstZoneAddr_x                                            0xEC93D0
#define pinstPlayerPath_x                                          0xF6AE78
#define pinstTargetIndicator_x                                     0xF6C7E0
#define EQObject_Top_x                                             0xEC3CF4

////
//Section 2:  UI Related Offsets
////
#define pinstCAAWnd_x                                              0xE0F8F4
#define pinstCAchievementsWnd_x                                    0xE0F964
#define pinstCActionsWnd_x                                         0xE0F91C
#define pinstCAdvancedDisplayOptionsWnd_x                          0xE0F630
#define pinstCAdvancedLootWnd_x                                    0xE0F17C
#define pinstCAdventureLeaderboardWnd_x                            0xF79E98
#define pinstCAdventureRequestWnd_x                                0xF79F48
#define pinstCAdventureStatsWnd_x                                  0xF79FF8
#define pinstCAggroMeterWnd_x                                      0xE0F644
#define pinstCAlarmWnd_x                                           0xE0F9BC
#define pinstCAlertHistoryWnd_x                                    0xE0F690
#define pinstCAlertStackWnd_x                                      0xE0F9F4
#define pinstCAlertWnd_x                                           0xE0F1E4
#define pinstCAltStorageWnd_x                                      0xF7A358
#define pinstCAudioTriggersWindow_x                                0xCC3D18
#define pinstCAuraWnd_x                                            0xE0F5F0
#define pinstCAvaZoneWnd_x                                         0xE0F950
#define pinstCBandolierWnd_x                                       0xE0F620
#define pinstCBankWnd_x                                            0xE0F68C
#define pinstCBarterMerchantWnd_x                                  0xF7B598
#define pinstCBarterSearchWnd_x                                    0xF7B648
#define pinstCBarterWnd_x                                          0xF7B6F8
#define pinstCBazaarConfirmationWnd_x                              0xE0F998
#define pinstCBazaarSearchWnd_x                                    0xE0F8F8
#define pinstCBazaarWnd_x                                          0xE0F99C
#define pinstCBlockedBuffWnd_x                                     0xE0F5FC
#define pinstCBlockedPetBuffWnd_x                                  0xE0F618
#define pinstCBodyTintWnd_x                                        0xE0F928
#define pinstCBookWnd_x                                            0xE0F678
#define pinstCBreathWnd_x                                          0xE0F90C
#define pinstCBuffWindowNORMAL_x                                   0xE0F160
#define pinstCBuffWindowSHORT_x                                    0xE0F168
#define pinstCBugReportWnd_x                                       0xE0F680
#define pinstCButtonWnd_x                                          0x15FEE70
#define pinstCCastingWnd_x                                         0xE0F668
#define pinstCCastSpellWnd_x                                       0xE0F900
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE0F944
#define pinstCChatWindowManager_x                                  0xF7C1B8
#define pinstCClaimWnd_x                                           0xF7C310
#define pinstCColorPickerWnd_x                                     0xE0F6C4
#define pinstCCombatAbilityWnd_x                                   0xE0F9B0
#define pinstCCombatSkillsSelectWnd_x                              0xE0F958
#define pinstCCompassWnd_x                                         0xE0F920
#define pinstCConfirmationDialog_x                                 0xF81210
#define pinstCContainerMgr_x                                       0xE0F940
#define pinstCContextMenuManager_x                                 0x15FEBC0
#define pinstCCursorAttachment_x                                   0xE0F650
#define pinstCDynamicZoneWnd_x                                     0xF7C8D8
#define pinstCEditLabelWnd_x                                       0xE0F5E8
#define pinstCEQMainWnd_x                                          0xF7CB20
#define pinstCEventCalendarWnd_x                                   0xE0F6D8
#define pinstCExtendedTargetWnd_x                                  0xE0F610
#define pinstCFacePick_x                                           0xE0F974
#define pinstCFactionWnd_x                                         0xE0F988
#define pinstCFellowshipWnd_x                                      0xF7CD20
#define pinstCFileSelectionWnd_x                                   0xE0F6BC
#define pinstCFindItemWnd_x                                        0xE0F970
#define pinstCFindLocationWnd_x                                    0xF7CE78
#define pinstCFriendsWnd_x                                         0xE0F96C
#define pinstCGemsGameWnd_x                                        0xE0F984
#define pinstCGiveWnd_x                                            0xE0F9C4
#define pinstCGroupSearchFiltersWnd_x                              0xE0F66C
#define pinstCGroupSearchWnd_x                                     0xF7D270
#define pinstCGroupWnd_x                                           0xF7D320
#define pinstCGuildBankWnd_x                                       0xECA214
#define pinstCGuildCreationWnd_x                                   0xF7D480
#define pinstCGuildMgmtWnd_x                                       0xF7D530
#define pinstCharacterCreation_x                                   0xE0F960
#define pinstCHelpWnd_x                                            0xE0F9B8
#define pinstCHeritageSelectionWnd_x                               0xE0F98C
#define pinstCHotButtonWnd_x                                       0xF7F688
#define pinstCHotButtonWnd1_x                                      0xF7F688
#define pinstCHotButtonWnd2_x                                      0xF7F68C
#define pinstCHotButtonWnd3_x                                      0xF7F690
#define pinstCHotButtonWnd4_x                                      0xF7F694
#define pinstCIconSelectionWnd_x                                   0xE0F648
#define pinstCInspectWnd_x                                         0xE0F61C
#define pinstCInventoryWnd_x                                       0xE0F5F8
#define pinstCInvSlotMgr_x                                         0xE0F908
#define pinstCItemDisplayManager_x                                 0xF7FC18
#define pinstCItemExpTransferWnd_x                                 0xF7FD48
#define pinstCItemOverflowWnd_x                                    0xE0F904
#define pinstCJournalCatWnd_x                                      0xE0F8E0
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE0F69C
#define pinstCKeyRingWnd_x                                         0xE0F660
#define pinstCLargeDialogWnd_x                                     0xF81E90
#define pinstCLayoutCopyWnd_x                                      0xF80098
#define pinstCLFGuildWnd_x                                         0xF80148
#define pinstCLoadskinWnd_x                                        0xE0F994
#define pinstCLootFiltersCopyWnd_x                                 0xCE03A0
#define pinstCLootFiltersWnd_x                                     0xE0F9F8
#define pinstCLootSettingsWnd_x                                    0xE0F5F4
#define pinstCLootWnd_x                                            0xE0F8E4
#define pinstCMailAddressBookWnd_x                                 0xE0F910
#define pinstCMailCompositionWnd_x                                 0xE0F8F0
#define pinstCMailIgnoreListWnd_x                                  0xE0F914
#define pinstCMailWnd_x                                            0xE0F6CC
#define pinstCManageLootWnd_x                                      0xE10858
#define pinstCMapToolbarWnd_x                                      0xE0F9C0
#define pinstCMapViewWnd_x                                         0xE0F990
#define pinstCMarketplaceWnd_x                                     0xE0F164
#define pinstCMerchantWnd_x                                        0xE0F8EC
#define pinstCMIZoneSelectWnd_x                                    0xF80980
#define pinstCMusicPlayerWnd_x                                     0xE0F694
#define pinstCNameChangeMercWnd_x                                  0xE0F97C
#define pinstCNameChangePetWnd_x                                   0xE0F968
#define pinstCNameChangeWnd_x                                      0xE0F9A4
#define pinstCNoteWnd_x                                            0xE0F9A8
#define pinstCObjectPreviewWnd_x                                   0xE0F5EC
#define pinstCOptionsWnd_x                                         0xE0F9B4
#define pinstCPetInfoWnd_x                                         0xE0F6AC
#define pinstCPetitionQWnd_x                                       0xE0F948
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE0F930
#define pinstCPlayerWnd_x                                          0xE0F6B8
#define pinstCPopupWndManager_x                                    0xF81210
#define pinstCProgressionSelectionWnd_x                            0xF812C0
#define pinstCPurchaseGroupWnd_x                                   0xE0F654
#define pinstCPurchaseWnd_x                                        0xE0F614
#define pinstCPvPLeaderboardWnd_x                                  0xF81370
#define pinstCPvPStatsWnd_x                                        0xF81420
#define pinstCQuantityWnd_x                                        0xE0F6A0
#define pinstCRaceChangeWnd_x                                      0xE0F9EC
#define pinstCRaidOptionsWnd_x                                     0xE0F674
#define pinstCRaidWnd_x                                            0xE0F8E8
#define pinstCRealEstateItemsWnd_x                                 0xE0F95C
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE0F8FC
#define pinstCRealEstateManageWnd_x                                0xE0F664
#define pinstCRealEstateNeighborhoodWnd_x                          0xE0F688
#define pinstCRealEstatePlotSearchWnd_x                            0xE0F698
#define pinstCRealEstatePurchaseWnd_x                              0xE0F6B4
#define pinstCRespawnWnd_x                                         0xE0F60C
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE0F954
#define pinstCSendMoneyWnd_x                                       0xE0F9E8
#define pinstCServerListWnd_x                                      0xE0F6C8
#define pinstCSkillsSelectWnd_x                                    0xE0F938
#define pinstCSkillsWnd_x                                          0xE0F924
#define pinstCSocialEditWnd_x                                      0xE0F65C
#define pinstCSocialWnd_x                                          0xE0F978
#define pinstCSpellBookWnd_x                                       0xE0F9AC
#define pinstCStoryWnd_x                                           0xE0F918
#define pinstCTargetOfTargetWnd_x                                  0xF83248
#define pinstCTargetWnd_x                                          0xE0F608
#define pinstCTaskOverlayWnd_x                                     0xE0F64C
#define pinstCTaskSelectWnd_x                                      0xF833A0
#define pinstCTaskManager_x                                        0xCE0CE0
#define pinstCTaskTemplateSelectWnd_x                              0xF83450
#define pinstCTaskWnd_x                                            0xF83500
#define pinstCTextEntryWnd_x                                       0xE0F670
#define pinstCTimeLeftWnd_x                                        0xE0F92C
#define pinstCTipWndCONTEXT_x                                      0xF83704
#define pinstCTipWndOFDAY_x                                        0xF83700
#define pinstCTitleWnd_x                                           0xF837B0
#define pinstCTrackingWnd_x                                        0xE0F600
#define pinstCTradeskillWnd_x                                      0xF83918
#define pinstCTradeWnd_x                                           0xE0F934
#define pinstCTrainWnd_x                                           0xE0F6D4
#define pinstCTributeBenefitWnd_x                                  0xF83B18
#define pinstCTributeMasterWnd_x                                   0xF83BC8
#define pinstCTributeTrophyWnd_x                                   0xF83C78
#define pinstCVideoModesWnd_x                                      0xE0F6D0
#define pinstCVoiceMacroWnd_x                                      0xF6CF48
#define pinstCVoteResultsWnd_x                                     0xE0F94C
#define pinstCVoteWnd_x                                            0xE0F93C
#define pinstCWebManager_x                                         0xF6D5C4
#define pinstCZoneGuideWnd_x                                       0xE0F658
#define pinstCZonePathWnd_x                                        0xE0F67C
#define pinstEQSuiteTextureLoader_x                                0xCAE130
#define pinstItemIconCache_x                                       0xF7CAD8
#define pinstLootFiltersManager_x                                  0xCE0450
#define pinstRewardSelectionWnd_x                                  0xF81B68
#define instExceptionSubmissionEndpoint_x                          0xC5E870

////
// Section 3: Miscellaneous Offsets
////
#define __CastRay_x                                                0x5BBB70
#define __CastRay2_x                                               0x5BBBC0
#define __ConvertItemTags_x                                        0x5D7720
#define __CleanItemTags_x                                          0x47D0A0
#define __CreateCascadeMenuItems_x                                 0x559340
#define __DoesFileExist_x                                          0x9115D0
#define __EQGetTime_x                                              0x90E020
#define __ExecuteCmd_x                                             0x5B4370
#define __FixHeading_x                                             0x9A8C80
#define __FlushDxKeyboard_x                                        0x6C60C0
#define __GameLoop_x                                               0x6C93D0
#define __get_bearing_x                                            0x5BB6E0
#define __get_melee_range_x                                        0x5BBDB0
#define __GetAnimationCache_x                                      0x72E800
#define __GetGaugeValueFromEQ_x                                    0x81FDA0
#define __GetLabelFromEQ_x                                         0x821880
#define __GetXTargetType_x                                         0x9AA720
#define __HandleMouseWheel_x                                       0x6CA2B0
#define __HeadingDiff_x                                            0x9A8CF0
#define __HelpPath_x                                               0xF682CC
#define __LoadFrontEnd_x                                           0x6C66F0
#define __NewUIINI_x                                               0x81FA70
#define __ProcessGameEvents_x                                      0x61C3E0
#define __ProcessKeyboardEvents_x                                  0x6C7C30
#define __ProcessMouseEvents_x                                     0x61BBA0
#define __SaveColors_x                                             0x559220
#define __STMLToText_x                                             0x94BF50
#define __WndProc_x                                                0x6C8690
#define CMemoryMappedFile__SetFile_x                               0xA97FF0
#define CrashDetected_x                                            0x6C8190
#define DrawNetStatus_x                                            0x648410
#define Expansion_HoT_x                                            0xECA21C
#define Teleport_Table_Size_x                                      0xEC3CB4
#define Teleport_Table_x                                           0xEC1870
#define Util__FastTime_x                                           0x90DBE0
#define __eq_delete_x                                              0x9B113E
#define __eq_new_x                                                 0x9B1704

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
#define AltAdvManager__GetCalculatedTimer_x                        0x560F60
#define AltAdvManager__IsAbilityReady_x                            0x55FD00
#define AltAdvManager__GetAAById_x                                 0x560090
#define AltAdvManager__CanTrainAbility_x                           0x560100
#define AltAdvManager__CanSeeAbility_x                             0x560460

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C9CE0
#define CharacterZoneClient__HasSkill_x                            0x4D4B60
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6280
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE450
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BAA80
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8BE0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D8CC0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D8DA0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C2B50
#define CharacterZoneClient__BardCastBard_x                        0x4C56B0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAB50
#define CharacterZoneClient__GetEffect_x                           0x4BA9C0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C3BA0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C3C70
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C3CC0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C3E10
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C3FE0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2900
#define CharacterZoneClient__FindItemByGuid_x                      0x4D71E0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D6C60

// CBankWnd
#define CBankWnd__GetNumBankSlots_x                                0x6EFDF0
#define CBankWnd__WndNotification_x                                0x6EFBD0

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6FD640

// CButtonWnd
#define CButtonWnd__SetCheck_x                                     0x62AD60
#define CButtonWnd__CButtonWnd_x                                   0x948300
#define CButtonWnd__dCButtonWnd_x                                  0x9485E0
#define CButtonWnd__vftable_x                                      0xB51518

// CChatWindowManager
#define CChatWindowManager__GetRGBAFromIndex_x                     0x71D760
#define CChatWindowManager__InitContextMenu_x                      0x716890
#define CChatWindowManager__FreeChatWindow_x                       0x71C2A0
#define CChatWindowManager__GetLockedActiveChatWindow_x            0x4E82A0
#define CChatWindowManager__SetLockedActiveChatWindow_x            0x71D3E0
#define CChatWindowManager__CreateChatWindow_x                     0x71C8E0

// ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E83B0

// CChatWindow
#define CChatWindow__CChatWindow_x                                 0x71E010
#define CChatWindow__Clear_x                                       0x71F2E0
#define CChatWindow__WndNotification_x                             0x71FA70
#define CChatWindow__AddHistory_x                                  0x71EBA0

// CContextMenu
#define CContextMenu__CContextMenu_x                               0x95C990
#define CContextMenu__dCContextMenu_x                              0x95CBD0
#define CContextMenu__AddMenuItem_x                                0x95CBE0
#define CContextMenu__RemoveMenuItem_x                             0x95CEF0
#define CContextMenu__RemoveAllMenuItems_x                         0x95CF10
#define CContextMenu__CheckMenuItem_x                              0x95CF90
#define CContextMenu__SetMenuItem_x                                0x95CE10
#define CContextMenu__AddSeparator_x                               0x95CD70

// CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x95D530
#define CContextMenuManager__RemoveMenu_x                          0x95D5A0
#define CContextMenuManager__PopupMenu_x                           0x95D660
#define CContextMenuManager__Flush_x                               0x95D4D0
#define CContextMenuManager__GetMenu_x                             0x49B360
#define CContextMenuManager__CreateDefaultMenu_x                   0x728FD0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8E93B0
#define CChatService__GetFriendName_x                              0x8E93C0

// CComboWnd
#define CComboWnd__DeleteAll_x                                     0x959DF0
#define CComboWnd__Draw_x                                          0x9592D0
#define CComboWnd__GetCurChoice_x                                  0x959C30
#define CComboWnd__GetListRect_x                                   0x959790
#define CComboWnd__GetTextRect_x                                   0x959E60
#define CComboWnd__InsertChoice_x                                  0x959920
#define CComboWnd__SetColors_x                                     0x9598F0
#define CComboWnd__SetChoice_x                                     0x959C00
#define CComboWnd__GetItemCount_x                                  0x959C40
#define CComboWnd__GetCurChoiceText_x                              0x959C80
#define CComboWnd__GetChoiceText_x                                 0x959C50
#define CComboWnd__InsertChoiceAtIndex_x                           0x9599C0

// CContainerWnd
#define CContainerWnd__HandleCombine_x                             0x7269B0
#define CContainerWnd__vftable_x                                   0xB1FDB4
#define CContainerWnd__SetContainer_x                              0x727F10

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x553BF0
#define CDisplay__PreZoneMainUI_x                                  0x553C00
#define CDisplay__CleanGameUI_x                                    0x558FE0
#define CDisplay__GetClickedActor_x                                0x54BEF0
#define CDisplay__GetUserDefinedColor_x                            0x544550
#define CDisplay__GetWorldFilePath_x                               0x54D960
#define CDisplay__is3dON_x                                         0x548B50
#define CDisplay__ReloadUI_x                                       0x553070
#define CDisplay__WriteTextHD2_x                                   0x548940
#define CDisplay__TrueDistance_x                                   0x54F620
#define CDisplay__SetViewActor_x                                   0x54B810
#define CDisplay__GetFloorHeight_x                                 0x548C10
#define CDisplay__SetRenderWindow_x                                0x547570
#define CDisplay__ToggleScreenshotMode_x                           0x54B2E0

// CEditBaseWnd
#define CEditBaseWnd__SetSel_x                                     0x97C6D0

// CEditWnd
#define CEditWnd__DrawCaret_x                                      0x95FF00
#define CEditWnd__EnsureCaretVisible_x                             0x9620D0
#define CEditWnd__GetCaretPt_x                                     0x961080
#define CEditWnd__GetCharIndexPt_x                                 0x960E30
#define CEditWnd__GetDisplayString_x                               0x960CD0
#define CEditWnd__GetHorzOffset_x                                  0x95F530
#define CEditWnd__GetLineForPrintableChar_x                        0x961FD0
#define CEditWnd__GetSelStartPt_x                                  0x9610E0
#define CEditWnd__GetSTMLSafeText_x                                0x960AF0
#define CEditWnd__PointFromPrintableChar_x                         0x961C00
#define CEditWnd__ReplaceSelection_x                               0x961870
#define CEditWnd__SelectableCharFromPoint_x                        0x961D70
#define CEditWnd__SetEditable_x                                    0x9611B0
#define CEditWnd__SetWindowTextA_x                                 0x960870

// CEverQuest
#define CEverQuest__DoPercentConvert_x                             0x60A020
#define CEverQuest__ClickedPlayer_x                                0x5FC150
#define CEverQuest__CreateTargetIndicator_x                        0x619680
#define CEverQuest__DeleteTargetIndicator_x                        0x619710
#define CEverQuest__DoTellWindow_x                                 0x4E8490
#define CEverQuest__OutputTextToLog_x                              0x4E8760
#define CEverQuest__DropHeldItemOnGround_x                         0x5F1190
#define CEverQuest__dsp_chat_x                                     0x4E8AF0
#define CEverQuest__trimName_x                                     0x615880
#define CEverQuest__Emote_x                                        0x60A880
#define CEverQuest__EnterZone_x                                    0x604920
#define CEverQuest__GetBodyTypeDesc_x                              0x60F140
#define CEverQuest__GetClassDesc_x                                 0x60F780
#define CEverQuest__GetClassThreeLetterCode_x                      0x60FD80
#define CEverQuest__GetDeityDesc_x                                 0x617ED0
#define CEverQuest__GetLangDesc_x                                  0x60FF40
#define CEverQuest__GetRaceDesc_x                                  0x60F760
#define CEverQuest__InterpretCmd_x                                 0x6184A0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5F5390
#define CEverQuest__LMouseUp_x                                     0x5F3720
#define CEverQuest__RightClickedOnPlayer_x                         0x5F5C70
#define CEverQuest__RMouseUp_x                                     0x5F46A0
#define CEverQuest__SetGameState_x                                 0x5F0F20
#define CEverQuest__UPCNotificationFlush_x                         0x615780
#define CEverQuest__IssuePetCommand_x                              0x611340
#define CEverQuest__ReportSuccessfulHit_x                          0x60BBD0

// CGaugeWnd
// not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x738910
#define CGaugeWnd__CalcLinesFillRect_x                             0x738970
#define CGaugeWnd__Draw_x                                          0x737F90

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF400
#define CGuild__GetGuildName_x                                     0x4AE430
#define CGuild__GetGuildIndex_x                                    0x4AE870

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton_x                               0x752B30

//CHotButton
#define CHotButton__SetButtonSize_x                                0x62B120

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot_x                                 0x75FB30
#define CInvSlotMgr__MoveItem_x                                    0x75E8A0
#define CInvSlotMgr__SelectSlot_x                                  0x75FC00

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x75D0E0
#define CInvSlot__SliderComplete_x                                 0x75AE40
#define CInvSlot__GetItemBase_x                                    0x75A7D0
#define CInvSlot__UpdateItem_x                                     0x75A940

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x761690
#define CInvSlotWnd__CInvSlotWnd_x                                 0x760820
#define CInvSlotWnd__HandleLButtonUp_x                             0x761210

// CItemDisplayWnd
#define CItemDisplayWnd__SetSpell_x                                0x81B100
#define CItemDisplayWnd__UpdateStrings_x                           0x76FE30
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x769B00
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x76A020
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x770430
#define CItemDisplayWnd__AboutToShow_x                             0x76FA80
#define CItemDisplayWnd__WndNotification_x                         0x771510
#define CItemDisplayWnd__RequestConvertItem_x                      0x770FD0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x76EAE0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x76F8A0

// CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x853D30

// CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x775A10

// CKeyRingWnd
#define CKeyRingWnd__ExecuteRightClick_x                           0x51A460

// CLabel
#define CLabel__Draw_x                                             0x77B480

// CListWnd
#define CListWnd__CListWnd_x                                       0x932420
#define CListWnd__dCListWnd_x                                      0x932740
#define CListWnd__vftable_x                                        0xB50DF0
#define CListWnd__AddColumn_x                                      0x936BB0
#define CListWnd__AddColumn1_x                                     0x936C00
#define CListWnd__AddLine_x                                        0x936F90
#define CListWnd__AddString_x                                      0x936D90
#define CListWnd__CalculateFirstVisibleLine_x                      0x936970
#define CListWnd__CalculateVSBRange_x                              0x936750
#define CListWnd__ClearSel_x                                       0x937770
#define CListWnd__ClearAllSel_x                                    0x9377D0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x9381F0
#define CListWnd__Compare_x                                        0x936080
#define CListWnd__Draw_x                                           0x932870
#define CListWnd__DrawColumnSeparators_x                           0x935060
#define CListWnd__DrawHeader_x                                     0x9354C0
#define CListWnd__DrawItem_x                                       0x9359C0
#define CListWnd__DrawLine_x                                       0x9351C0
#define CListWnd__DrawSeparator_x                                  0x935100
#define CListWnd__EnableLine_x                                     0x934940
#define CListWnd__EnsureVisible_x                                  0x938110
#define CListWnd__ExtendSel_x                                      0x9376A0
#define CListWnd__GetColumnTooltip_x                               0x934480
#define CListWnd__GetColumnMinWidth_x                              0x9344F0
#define CListWnd__GetColumnWidth_x                                 0x9343F0
#define CListWnd__GetCurSel_x                                      0x933D80
#define CListWnd__GetItemAtPoint_x                                 0x934BB0
#define CListWnd__GetItemAtPoint1_x                                0x934C20
#define CListWnd__GetItemData_x                                    0x933E00
#define CListWnd__GetItemHeight_x                                  0x9341C0
#define CListWnd__GetItemIcon_x                                    0x933F90
#define CListWnd__GetItemRect_x                                    0x934A30
#define CListWnd__GetItemText_x                                    0x933E40
#define CListWnd__GetSelList_x                                     0x937820
#define CListWnd__GetSeparatorRect_x                               0x934E60
#define CListWnd__InsertLine_x                                     0x937380
#define CListWnd__RemoveLine_x                                     0x9374D0
#define CListWnd__SetColors_x                                      0x936720
#define CListWnd__SetColumnJustification_x                         0x936450
#define CListWnd__SetColumnLabel_x                                 0x936D30
#define CListWnd__SetColumnWidth_x                                 0x936370
#define CListWnd__SetCurSel_x                                      0x9375E0
#define CListWnd__SetItemColor_x                                   0x937DC0
#define CListWnd__SetItemData_x                                    0x937D80
#define CListWnd__SetItemText_x                                    0x937990
#define CListWnd__ShiftColumnSeparator_x                           0x936510
#define CListWnd__Sort_x                                           0x936200
#define CListWnd__ToggleSel_x                                      0x937610
#define CListWnd__SetColumnsSizable_x                              0x9365C0
#define CListWnd__SetItemWnd_x                                     0x937C40
#define CListWnd__GetItemWnd_x                                     0x933FE0
#define CListWnd__SetItemIcon_x                                    0x937A10
#define CListWnd__CalculateCustomWindowPositions_x                 0x936A70
#define CListWnd__SetVScrollPos_x                                  0x936350

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd_x                                 0x790B40

// MapViewMap
#define MapViewMap__MapViewMap_x                                   0x78C030
#define MapViewMap__dMapViewMap_x                                  0x78C180
#define MapViewMap__vftable_x                                      0xB273F8
#define MapViewMap__Clear_x                                        0x78C9B0
#define MapViewMap__SaveEx_x                                       0x78FD70
#define MapViewMap__SetZoom_x                                      0x794430
#define MapViewMap__HandleLButtonDown_x                            0x78C290
#define MapViewMap__GetWorldCoordinates_x                          0x78F250

// CMerchantWnd
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7B0C50
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7B1530
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7B1A60
#define CMerchantWnd__SelectRecoverySlot_x                         0x7B49E0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7AF7C0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7BA590
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7B0860

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8B72F0
#define CPacketScrambler__hton_x                                   0x8B72E0

// CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x955970
#define CSidlManagerBase__CreatePageWnd_x                          0x955160
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x9513E0
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x951370
#define CSidlManagerBase__FindAnimation1_x                         0x9515C0
#define CSidlManagerBase__FindScreenPieceTemplate_x                0x9519D0
#define CSidlManagerBase__FindScreenPieceTemplate1_x               0x9517C0
#define CSidlManagerBase__CreateLabel_x                            0x812340
#define CSidlManagerBase__CreateXWndFromTemplate_x                 0x954930
#define CSidlManagerBase__CreateXWndFromTemplate1_x                0x954B10
#define CSidlManagerBase__CreateXWnd_x                             0x812270

// CSidlManager
#define CSidlManager__CreateHotButtonWnd_x                         0x812840

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateHSBRange_x                        0x94E080
#define CSidlScreenWnd__CalculateVSBRange_x                        0x94DF80
#define CSidlScreenWnd__ConvertToRes_x                             0x977110
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x94DA10
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x94D700
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x94D7D0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x94D8A0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x94E520
#define CSidlScreenWnd__EnableIniStorage_x                         0x94E9F0
#define CSidlScreenWnd__GetChildItem_x                             0x94E970
#define CSidlScreenWnd__GetSidlPiece_x                             0x94E710
#define CSidlScreenWnd__HandleLButtonUp_x                          0x93DFE0
#define CSidlScreenWnd__Init1_x                                    0x94D300
#define CSidlScreenWnd__LoadIniInfo_x                              0x94EA40
#define CSidlScreenWnd__LoadIniListWnd_x                           0x94F5A0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x94C700
#define CSidlScreenWnd__m_layoutCopy_x                             0x15FEA90
#define CSidlScreenWnd__StoreIniInfo_x                             0x94F110
#define CSidlScreenWnd__StoreIniVis_x                              0x94F480
#define CSidlScreenWnd__vftable_x                                  0xB517B8
#define CSidlScreenWnd__WndNotification_x                          0x94E430

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x68FF50
#define CSkillMgr__GetSkillCap_x                                   0x690130
#define CSkillMgr__GetNameToken_x                                  0x68F6D0
#define CSkillMgr__IsActivatedSkill_x                              0x68F810
#define CSkillMgr__IsCombatSkill_x                                 0x68F750

// CSliderWnd
#define CSliderWnd__GetValue_x                                     0x95E310
#define CSliderWnd__SetValue_x                                     0x95E180
#define CSliderWnd__SetNumTicks_x                                  0x95E1E0

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet_x                               0x818490

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x966B30
#define CStmlWnd__CalculateHSBRange_x                              0x967C50
#define CStmlWnd__CalculateVSBRange_x                              0x967BC0
#define CStmlWnd__CanBreakAtCharacter_x                            0x96BF80
#define CStmlWnd__FastForwardToEndOfTag_x                          0x96CC10
#define CStmlWnd__ForceParseNow_x                                  0x967120
#define CStmlWnd__GetNextTagPiece_x                                0x96BEE0
#define CStmlWnd__GetSTMLText_x                                    0x509DD0
#define CStmlWnd__GetVisibleText_x                                 0x967140
#define CStmlWnd__InitializeWindowVariables_x                      0x96CA60
#define CStmlWnd__MakeStmlColorTag_x                               0x9661A0
#define CStmlWnd__MakeWndNotificationTag_x                         0x966210
#define CStmlWnd__SetSTMLText_x                                    0x965250
#define CStmlWnd__StripFirstSTMLLines_x                            0x96DCE0
#define CStmlWnd__UpdateHistoryString_x                            0x96CE20

// CTabWnd
#define CTabWnd__Draw_x                                            0x9643A0
#define CTabWnd__DrawCurrentPage_x                                 0x964AD0
#define CTabWnd__DrawTab_x                                         0x9647F0
#define CTabWnd__GetCurrentPage_x                                  0x963BA0
#define CTabWnd__GetPageInnerRect_x                                0x963DE0
#define CTabWnd__GetTabInnerRect_x                                 0x963D20
#define CTabWnd__GetTabRect_x                                      0x963BD0
#define CTabWnd__InsertPage_x                                      0x963FF0
#define CTabWnd__SetPage_x                                         0x963E60
#define CTabWnd__SetPageRect_x                                     0x9642E0
#define CTabWnd__UpdatePage_x                                      0x9646B0
#define CTabWnd__GetPageFromTabIndex_x                             0x964730
#define CTabWnd__GetCurrentTabIndex_x                              0x963B90

// CPageWnd
#define CPageWnd__GetTabText_x                                     0x775E00
#define CPageWnd__SetTabText_x                                     0x9636E0

// CTextOverlay
#define CTextOverlay__DisplayText_x                                0x4A8F50

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x93AE40
#define CTextureFont__GetTextExtent_x                              0x93B000

// CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6C3280
#define CHtmlComponentWnd__ValidateUri_x                           0x754520
#define CHtmlWnd__SetClientCallbacks_x                             0x6301A0
#define CHtmlWnd__AddObserver_x                                    0x6301C0
#define CHtmlWnd__RemoveObserver_x                                 0x630220
#define Window__getProgress_x                                      0x86C650
#define Window__getStatus_x                                        0x86C670
#define Window__getURI_x                                           0x86C680

// CXMLDataManager
#define CXMLDataManager__GetXMLData_x                              0x973F20

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead_x                             0x928070

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr_x                                             0x4E80E0
#define CXStr__CXStr1_x                                            0x9FF4A0
#define CXStr__CXStr3_x                                            0x90A170
#define CXStr__dCXStr_x                                            0x478780
#define CXStr__operator_equal_x                                    0x90A3A0
#define CXStr__operator_equal1_x                                   0x90A3E0
#define CXStr__operator_plus_equal1_x                              0x90AE70
#define CXStr__SetString_x                                         0x90CD60
#define CXStr__operator_char_p_x                                   0x90A8E0
#define CXStr__GetChar_x                                           0x90C690
#define CXStr__Delete_x                                            0x90BF60
#define CXStr__GetUnicode_x                                        0x90C700
#define CXStr__GetLength_x                                         0x47D450
#define CXStr__Mid_x                                               0x47D460
#define CXStr__Insert_x                                            0x90C760
#define CXStr__FindNext_x                                          0x90C3D0
#define CXStr__gFreeLists_x                                        0xCAC588
#define CXStr__gCXStrAccess_x                                      0x15FE1B4

// CTileLayoutWnd
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x95C5B0

// CXWnd
#define CXWnd__BringToTop_x                                        0x941780
#define CXWnd__Center_x                                            0x941300
#define CXWnd__ClrFocus_x                                          0x941110
#define CXWnd__Destroy_x                                           0x9411C0
#define CXWnd__DoAllDrawing_x                                      0x93D770
#define CXWnd__DrawChildren_x                                      0x93D740
#define CXWnd__DrawColoredRect_x                                   0x93DBD0
#define CXWnd__DrawTooltip_x                                       0x93C270
#define CXWnd__DrawTooltipAtPoint_x                                0x93C330
#define CXWnd__GetBorderFrame_x                                    0x93DA30
#define CXWnd__GetChildItem_x                                      0x941990
#define CXWnd__GetChildWndAt_x                                     0x941820
#define CXWnd__GetClientClipRect_x                                 0x93F9F0
#define CXWnd__GetRelativeRect_x                                   0x93FD20
#define CXWnd__GetScreenClipRect_x                                 0x93FAC0
#define CXWnd__GetScreenRect_x                                     0x93FC60
#define CXWnd__GetTooltipRect_x                                    0x93DC20
#define CXWnd__GetWindowTextA_x                                    0x49CA60
#define CXWnd__IsActive_x                                          0x93E360
#define CXWnd__IsDescendantOf_x                                    0x940660
#define CXWnd__IsReallyVisible_x                                   0x940690
#define CXWnd__IsType_x                                            0x941E90
#define CXWnd__Minimize_x                                          0x940DA0
#define CXWnd__Move_x                                              0x940700
#define CXWnd__Move1_x                                             0x9407B0
#define CXWnd__ProcessTransition_x                                 0x9412B0
#define CXWnd__Refade_x                                            0x940A90
#define CXWnd__Resize_x                                            0x940D30
#define CXWnd__Right_x                                             0x941540
#define CXWnd__SetFocus_x                                          0x9410D0
#define CXWnd__SetFont_x                                           0x941140
#define CXWnd__SetKeyTooltip_x                                     0x941CA0
#define CXWnd__SetMouseOver_x                                      0x93EB60
#define CXWnd__SetParent_x                                         0x940400
#define CXWnd__StartFade_x                                         0x940540
#define CXWnd__vftable_x                                           0xB51234
#define CXWnd__CXWnd_x                                             0x93B320
#define CXWnd__dCXWnd_x                                            0x93B850

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x978190

// CXWndManager
#define CXWndManager__DrawCursor_x                                 0x944710
#define CXWndManager__DrawWindows_x                                0x944730
#define CXWndManager__GetKeyboardFlags_x                           0x946F30
#define CXWndManager__HandleKeyboardMsg_x                          0x946AE0
#define CXWndManager__RemoveWnd_x                                  0x947160
#define CXWndManager__RemovePendingDeletionWnd_x                   0x9476D0

// CDBStr
#define CDBStr__GetString_x                                        0x543520

// CharacterZoneClient
#define CharacterZoneClient__CastSpell_x                           0x4BBA60
#define CharacterZoneClient__Cur_HP_x                              0x4D1BA0
#define CharacterZoneClient__Cur_Mana_x                            0x4D92A0
#define CharacterZoneClient__GetCastingTimeModifier_x              0x4BEAA0
#define CharacterZoneClient__GetFocusCastingTimeModifier_x         0x4B2540
#define CharacterZoneClient__GetFocusRangeModifier_x               0x4B2690
#define CharacterZoneClient__GetHPRegen_x                          0x4DF040
#define CharacterZoneClient__GetEnduranceRegen_x                   0x4DF640
#define CharacterZoneClient__GetManaRegen_x                        0x4DFA80
#define CharacterZoneClient__Max_Endurance_x                       0x6562D0
#define CharacterZoneClient__Max_HP_x                              0x4D19D0
#define CharacterZoneClient__Max_Mana_x                            0x6560D0
#define CharacterZoneClient__doCombatAbility_x                     0x658700
#define CharacterZoneClient__UseSkill_x                            0x4E1850
#define CharacterZoneClient__IsExpansionFlag_x                     0x5B2BB0
#define CharacterZoneClient__TotalEffect_x                         0x4C4DF0
#define CharacterZoneClient__GetPCSpellAffect_x                    0x4BF7F0
#define CharacterZoneClient__SpellDuration_x                       0x4BF320
#define CharacterZoneClient__GetAdjustedSkill_x                    0x4D4920
#define CharacterZoneClient__GetBaseSkill_x                        0x4D58C0
#define CharacterZoneClient__CanUseItem_x                          0x4D95B0

// ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8D62B0

// PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x66CC30

// PcClient
#define PcClient__PcClient_x                                       0x64CAF0
#define PcClient__GetConLevel_x                                    0x64F3A0

// CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B96B0
#define CCharacterListWnd__EnterWorld_x                            0x4B90F0
#define CCharacterListWnd__Quit_x                                  0x4B8E40
#define CCharacterListWnd__UpdateList_x                            0x4B9280

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x631370
#define EQ_Item__CreateItemTagString_x                             0x8B08B0
#define EQ_Item__IsStackable_x                                     0x8B5540
#define EQ_Item__GetImageNum_x                                     0x8B2330
#define EQ_Item__CreateItemClient_x                                0x6305C0
#define EQ_Item__GetItemValue_x                                    0x8B3740
#define EQ_Item__ValueSellMerchant_x                               0x8B6ED0
#define EQ_Item__IsKeyRingItem_x                                   0x8B4E60
#define EQ_Item__CanGoInBag_x                                      0x631490
#define EQ_Item__IsEmpty_x                                         0x8B49B0
#define EQ_Item__GetMaxItemCount_x                                 0x8B3B50
#define EQ_Item__GetHeldItem_x                                     0x8B2200
#define EQ_Item__GetAugmentFitBySlot_x                             0x8B01F0
#define ItemClient__ItemClient_x                                   0x5B1170
#define ItemClient__dItemClient_x                                  0x630510

// EQ_LoadingS
#define EQ_LoadingS__SetProgressBar_x                              0x561C30
#define EQ_LoadingS__Array_x                                       0xC35B60

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x656C10
#define EQ_PC__GetAlternateAbilityId_x                             0x8C0110
#define EQ_PC__GetCombatAbility_x                                  0x8C0780
#define EQ_PC__GetCombatAbilityTimer_x                             0x8C07F0
#define EQ_PC__GetItemRecastTimer_x                                0x658C80
#define EQ_PC__HasLoreItem_x                                       0x64FB60
#define EQ_PC__AlertInventoryChanged_x                             0x64ECE0
#define EQ_PC__GetPcZoneClient_x                                   0x67B780
#define EQ_PC__RemoveMyAffect_x                                    0x65BEB0
#define EQ_PC__GetKeyRingItems_x                                   0x8C1080
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8C0E10
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8C1380

// EQItemList
#define EQItemList__EQItemList_x                                   0x5B90A0
#define EQItemList__add_object_x                                   0x5E6930
#define EQItemList__add_item_x                                     0x5B9600
#define EQItemList__delete_item_x                                  0x5B9650
#define EQItemList__FreeItemList_x                                 0x5B9550

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x540080

// EQPlayer
#define EQPlayer__ChangeBoneStringSprite_x                         0x66E4B0
#define EQPlayer__dEQPlayer_x                                      0x6613C0
#define EQPlayer__DoAttack_x                                       0x676420
#define EQPlayer__EQPlayer_x                                       0x661A80
#define EQPlayer__SetNameSpriteState_x                             0x666190
#define EQPlayer__SetNameSpriteTint_x                              0x667060
#define PlayerBase__HasProperty_j_x                                0x9A7070
#define EQPlayer__IsTargetable_x                                   0x9A7510
#define EQPlayer__CanSee_x                                         0x9A7370
#define EQPlayer__CanSee1_x                                        0x9A7440
#define PlayerBase__GetVisibilityLineSegment_x                     0x9A7130

// PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x679220
#define PlayerZoneClient__GetLevel_x                               0x67B7C0
#define PlayerZoneClient__IsValidTeleport_x                        0x5E7AA0
#define PlayerZoneClient__LegalPlayerRace_x                        0x55AE40

// EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x671300
#define EQPlayerManager__GetSpawnByName_x                          0x6713B0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x671440

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x634AE0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x634B60
#define KeypressHandler__AttachKeyToEqCommand_x                    0x634BA0
#define KeypressHandler__ClearCommandStateArray_x                  0x635FB0
#define KeypressHandler__HandleKeyDown_x                           0x635FD0
#define KeypressHandler__HandleKeyUp_x                             0x636070
#define KeypressHandler__SaveKeymapping_x                          0x6364C0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8D43B0

// StringTable
#define StringTable__getString_x                                   0x8CF210

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x65BB20
#define PcZoneClient__RemovePetEffect_x                            0x65C150
#define PcZoneClient__HasAlternateAbility_x                        0x655F00
#define PcZoneClient__GetCurrentMod_x                              0x4E4910
#define PcZoneClient__GetModCap_x                                  0x4E4810
#define PcZoneClient__CanEquipItem_x                               0x6565B0
#define PcZoneClient__GetItemByID_x                                0x6590F0
#define PcZoneClient__GetItemByItemClass_x                         0x659240
#define PcZoneClient__RemoveBuffEffect_x                           0x65C170
#define PcZoneClient__BandolierSwap_x                              0x6571C0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x658C20

// Doors
#define EQSwitch__UseSwitch_x                                      0x5EC610

// IconCache
#define IconCache__GetIcon_x                                       0x72E0A0

// CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x725B50
#define CContainerMgr__CloseContainer_x                            0x725E20
#define CContainerMgr__OpenExperimentContainer_x                   0x7268A0

// CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7E4AC0

// CHelpWnd
#define CHelpWnd__SetFile_x                                        0x629540

// CLootWnd
#define CLootWnd__LootAll_x                                        0x782F50
#define CLootWnd__RequestLootSlot_x                                0x782180

// EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x5866A0
#define EQ_Spell__SpellAffects_x                                   0x586B10
#define EQ_Spell__SpellAffectBase_x                                0x5868D0
#define EQ_Spell__IsStackable_x                                    0x4C95F0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9410
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6A30
#define EQ_Spell__IsSPAStacking_x                                  0x587960
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x586E70
#define EQ_Spell__IsNoRemove_x                                     0x4C95D0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x587970
#define __IsResEffectSpell_x                                       0x4C8810

// EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4ACF80

// EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8DE960

// CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x82B890
#define CTargetWnd__WndNotification_x                              0x82B0D0
#define CTargetWnd__RefreshTargetBuffs_x                           0x82B3A0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x82A230

// CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x82FEA0

// CTaskManager
#define CTaskManager__GetEntry_x                                   0x53DAD0
#define CTaskManager__HandleMessage_x                              0x53BF60
#define CTaskManager__GetTaskStatus_x                              0x53DB80
#define CTaskManager__GetElementDescription_x                      0x53DC00

// EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5818D0
#define EqSoundManager__PlayScriptMp3_x                            0x581B90
#define EqSoundManager__SoundAssistPlay_x                          0x693E40
#define EqSoundManager__WaveInstancePlay_x                         0x6933B0

// CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52F260

// CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x962BF0

// CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x569760
#define CAltAbilityData__GetMercMaxRank_x                          0x5696F0
#define CAltAbilityData__GetMaxRank_x                              0x55EB80

// CTargetRing
#define CTargetRing__Cast_x                                        0x627650

// CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C93F0
#define CharacterBase__CreateItemGlobalIndex_x                     0x5169F0
#define CharacterBase__CreateItemIndex_x                           0x62F750
#define CharacterBase__GetItemPossession_x                         0x5027F0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8E6FA0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8E7000

// CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x70CB20
#define CCastSpellWnd__IsBardSongPlaying_x                         0x70D350
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x70D400

// messages
#define msg_spell_worn_off_x                                       0x5AAF70
#define msg_new_text_x                                             0x59FD00
#define __msgTokenTextParam_x                                      0x5AD4A0
#define msgTokenText_x                                             0x5AD6F0

// SpellManager
#define SpellManager__vftable_x                                    0xAF9780
#define SpellManager__SpellManager_x                               0x697160
#define Spellmanager__LoadTextSpells_x                             0x697A50
#define SpellManager__GetSpellByGroupAndRank_x                     0x697330

// CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x 0x9AB010

// ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8DF300
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8DF580

// CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x77B7C0

// CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x72A270
#define CCursorAttachment__AttachToCursor1_x                       0x72A2B0
#define CCursorAttachment__Deactivate_x                            0x72B2A0

// CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9729F0
#define CEQSuiteTextureLoader__GetTexture_x                        0x9726B0

// CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x514090
#define CFindItemWnd__WndNotification_x                            0x514B70
#define CFindItemWnd__Update_x                                     0x5156E0
#define CFindItemWnd__PickupSelectedItem_x                         0x5138D0

// IString
#define IString__Append_x                                          0x4F3940

// Camera
#define CDisplay__cameraType_x                                     0xE0F6DC
#define EverQuest__Cameras_x                                       0xECA56C

// LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51C800
#define LootFiltersManager__GetItemFilterData_x                    0x51C100
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51C130
#define LootFiltersManager__SetItemLootFilter_x                    0x51C350

// COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7D2A30

// CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9B0BB0
#define CResolutionHandler__GetWindowedStyle_x                     0x68E990

// CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x722780

// CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8F47E0
#define CDistillerInfo__Instance_x                                 0x8F4780

// CGroupWnd
#define CGroupWnd__WndNotification_x                               0x7418F0
#define CGroupWnd__UpdateDisplay_x                                 0x740C40

// ItemBase
#define ItemBase__IsLore_x                                         0x8B4F10
#define ItemBase__IsLoreEquipped_x                                 0x8B4F80

// EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5E6890
#define EQPlacedItemManager__GetItemByGuid_x                       0x5E69D0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5E6A30

// RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x683EB0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x687820

// CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50A400

// FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F6760
#define FactionManagerClient__HandleFactionMessage_x               0x4F6DD0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F7390
#define FactionManagerClient__GetMaxFaction_x                      0x4F73AF
#define FactionManagerClient__GetMinFaction_x                      0x4F7360

// BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x5027C0

// ArrayClass
#define ArrayClass__DeleteElement_x                                0x939E90

// AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BD70

// ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x502AA0

// MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x568C00

// CTargetManager
#define CTargetManager__Get_x                                      0x69A9D0

// RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x683EB0

// CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8D10

// EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5B94F0

// EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF67C00

// KeyCombo
#define KeyCombo__GetTextDescription_x                             0x9245E0

//
// EQGraphicsDX9.dll offsets (maybe this should go in eqgraphics.h?)
//

#define __eqgraphics_fopen_x                                       0x10147468
#define CParticleSystem__Render_x                                  0x10071190
