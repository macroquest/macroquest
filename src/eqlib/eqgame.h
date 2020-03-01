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
#define __ExpectedVersionDate                                     "Feb 13 2020"
#define __ExpectedVersionTime                                     "14:56:49"
#define __ActualVersionDate_x                                      0xB16C18
#define __ActualVersionTime_x                                      0xB16C0C
#define __ActualVersionBuild_x                                     0xB028F4

// Memory Protection
#define __MemChecker0_x                                            0x63B1F0
#define __MemChecker1_x                                            0x90DBC0
#define __MemChecker2_x                                            0x6C9390
#define __MemChecker3_x                                            0x6C92E0
#define __MemChecker4_x                                            0x8646A0
#define __EncryptPad0_x                                            0xC4E3F0
#define __EncryptPad1_x                                            0xCAC658
#define __EncryptPad2_x                                            0xC5EC88
#define __EncryptPad3_x                                            0xC5E888
#define __EncryptPad4_x                                            0xC9CC08
#define __EncryptPad5_x                                            0xF6D814
#define __AC1_x                                                    0x820F66
#define __AC2_x                                                    0x5F4F0F
#define __AC3_x                                                    0x5FC60F
#define __AC4_x                                                    0x6005E0
#define __AC5_x                                                    0x6068EF
#define __AC6_x                                                    0x60ADE6
#define __AC7_x                                                    0x5F4980
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
#define __do_loot_x                                                0x5C0A50
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

////
// Section 3: Miscellaneous Offsets
////
#define __CastRay_x                                                0x5BBEB0
#define __CastRay2_x                                               0x5BBF00
#define __ConvertItemTags_x                                        0x5D7A50
#define __CleanItemTags_x                                          0x47D0D0
#define __CreateCascadeMenuItems_x                                 0x559650
#define __DoesFileExist_x                                          0x910BF0
#define __EQGetTime_x                                              0x90D690
#define __ExecuteCmd_x                                             0x5B46E0
#define __FixHeading_x                                             0x9A8060
#define __FlushDxKeyboard_x                                        0x6C5250
#define __GameLoop_x                                               0x6C8560
#define __get_bearing_x                                            0x5BBA20
#define __get_melee_range_x                                        0x5BC0F0
#define __GetAnimationCache_x                                      0x72D9F0
#define __GetGaugeValueFromEQ_x                                    0x81F410
#define __GetLabelFromEQ_x                                         0x820EF0
#define __GetXTargetType_x                                         0x9A9AB0
#define __HandleMouseWheel_x                                       0x6C9440
#define __HeadingDiff_x                                            0x9A80D0
#define __HelpPath_x                                               0xF682CC
#define __LoadFrontEnd_x                                           0x6C5880
#define __NewUIINI_x                                               0x81F0E0
#define __ProcessGameEvents_x                                      0x61C690
#define __ProcessKeyboardEvents_x                                  0x6C6DC0
#define __ProcessMouseEvents_x                                     0x61BE50
#define __SaveColors_x                                             0x559530
#define __STMLToText_x                                             0x94B500
#define __WndProc_x                                                0x6C7820
#define CMemoryMappedFile__SetFile_x                               0xA973E0
#define CrashDetected_x                                            0x6C7320
#define DrawNetStatus_x                                            0x648520
#define Expansion_HoT_x                                            0xECA21C
#define Teleport_Table_Size_x                                      0xEC3CB4
#define Teleport_Table_x                                           0xEC1870
#define Util__FastTime_x                                           0x90D260
#define __eq_delete_x                                              0x9B044E
#define __eq_new_x                                                 0x9B0A04

////
// Section 4: Function Offsets
////
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4904C0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4993D0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4991A0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493A60
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492EB0

// AltAdvManager
#define AltAdvManager__GetCalculatedTimer_x                        0x561260
#define AltAdvManager__IsAbilityReady_x                            0x560000
#define AltAdvManager__GetAAById_x                                 0x560390
#define AltAdvManager__CanTrainAbility_x                           0x560400
#define AltAdvManager__CanSeeAbility_x                             0x560760

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C9EF0
#define CharacterZoneClient__HasSkill_x                            0x4D4D70
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6490
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE690
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BACC0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8E40
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D8F20
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9000
#define CharacterZoneClient__FindAffectSlot_x                      0x4C2D90
#define CharacterZoneClient__BardCastBard_x                        0x4C58F0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAD90
#define CharacterZoneClient__GetEffect_x                           0x4BAC00
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C3DE0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C3EB0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C3F00
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4050
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4220
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2B70
#define CharacterZoneClient__FindItemByGuid_x                      0x4D73F0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D6E70

// CBankWnd
#define CBankWnd__GetNumBankSlots_x                                0x6EEFA0
#define CBankWnd__WndNotification_x                                0x6EED80

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6FC730

// CButtonWnd
#define CButtonWnd__SetCheck_x                                     0x62AF40
#define CButtonWnd__CButtonWnd_x                                   0x9478E0
#define CButtonWnd__dCButtonWnd_x                                  0x947BC0
#define CButtonWnd__vftable_x                                      0xB51518

// CChatWindowManager
#define CChatWindowManager__GetRGBAFromIndex_x                     0x71C9D0
#define CChatWindowManager__InitContextMenu_x                      0x715B00
#define CChatWindowManager__FreeChatWindow_x                       0x71B510
#define CChatWindowManager__GetLockedActiveChatWindow_x            0x4E8540
#define CChatWindowManager__SetLockedActiveChatWindow_x            0x71C650
#define CChatWindowManager__CreateChatWindow_x                     0x71BB50

// ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8650

// CChatWindow
#define CChatWindow__CChatWindow_x                                 0x71D240
#define CChatWindow__Clear_x                                       0x71E500
#define CChatWindow__WndNotification_x                             0x71EC90
#define CChatWindow__AddHistory_x                                  0x71DDC0

// CContextMenu
#define CContextMenu__CContextMenu_x                               0x95BFC0
#define CContextMenu__dCContextMenu_x                              0x95C1F0
#define CContextMenu__AddMenuItem_x                                0x95C200
#define CContextMenu__RemoveMenuItem_x                             0x95C510
#define CContextMenu__RemoveAllMenuItems_x                         0x95C530
#define CContextMenu__CheckMenuItem_x                              0x95C5B0
#define CContextMenu__SetMenuItem_x                                0x95C430
#define CContextMenu__AddSeparator_x                               0x95C390

// CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x95CB40
#define CContextMenuManager__RemoveMenu_x                          0x95CBB0
#define CContextMenuManager__PopupMenu_x                           0x95CC70
#define CContextMenuManager__Flush_x                               0x95CAE0
#define CContextMenuManager__GetMenu_x                             0x49B530
#define CContextMenuManager__CreateDefaultMenu_x                   0x7281F0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8E8B00
#define CChatService__GetFriendName_x                              0x8E8B10

// CComboWnd
#define CComboWnd__DeleteAll_x                                     0x959400
#define CComboWnd__Draw_x                                          0x958910
#define CComboWnd__GetCurChoice_x                                  0x959240
#define CComboWnd__GetListRect_x                                   0x958DB0
#define CComboWnd__GetTextRect_x                                   0x959470
#define CComboWnd__InsertChoice_x                                  0x958F40
#define CComboWnd__SetColors_x                                     0x958F10
#define CComboWnd__SetChoice_x                                     0x959210
#define CComboWnd__GetItemCount_x                                  0x959250
#define CComboWnd__GetCurChoiceText_x                              0x959290
#define CComboWnd__GetChoiceText_x                                 0x959260
#define CComboWnd__InsertChoiceAtIndex_x                           0x958FD0

// CContainerWnd
#define CContainerWnd__HandleCombine_x                             0x725BD0
#define CContainerWnd__vftable_x                                   0xB1FE04
#define CContainerWnd__SetContainer_x                              0x727130

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x553F00
#define CDisplay__PreZoneMainUI_x                                  0x553F10
#define CDisplay__CleanGameUI_x                                    0x5592F0
#define CDisplay__GetClickedActor_x                                0x54C200
#define CDisplay__GetUserDefinedColor_x                            0x544860
#define CDisplay__GetWorldFilePath_x                               0x54DC70
#define CDisplay__is3dON_x                                         0x548E60
#define CDisplay__ReloadUI_x                                       0x553380
#define CDisplay__WriteTextHD2_x                                   0x548C50
#define CDisplay__TrueDistance_x                                   0x54F930
#define CDisplay__SetViewActor_x                                   0x54BB20
#define CDisplay__GetFloorHeight_x                                 0x548F20
#define CDisplay__SetRenderWindow_x                                0x547880
#define CDisplay__ToggleScreenshotMode_x                           0x54B5F0

// CEditBaseWnd
#define CEditBaseWnd__SetSel_x                                     0x97BB50

// CEditWnd
#define CEditWnd__DrawCaret_x                                      0x95F510
#define CEditWnd__EnsureCaretVisible_x                             0x9616E0
#define CEditWnd__GetCaretPt_x                                     0x960690
#define CEditWnd__GetCharIndexPt_x                                 0x960440
#define CEditWnd__GetDisplayString_x                               0x9602E0
#define CEditWnd__GetHorzOffset_x                                  0x95EB50
#define CEditWnd__GetLineForPrintableChar_x                        0x9615E0
#define CEditWnd__GetSelStartPt_x                                  0x9606F0
#define CEditWnd__GetSTMLSafeText_x                                0x960100
#define CEditWnd__PointFromPrintableChar_x                         0x961210
#define CEditWnd__ReplaceSelection_x                               0x960E80
#define CEditWnd__SelectableCharFromPoint_x                        0x961380
#define CEditWnd__SetEditable_x                                    0x9607C0
#define CEditWnd__SetWindowTextA_x                                 0x95FE80

// CEverQuest
#define CEverQuest__DoPercentConvert_x                             0x60A2C0
#define CEverQuest__ClickedPlayer_x                                0x5FC3F0
#define CEverQuest__CreateTargetIndicator_x                        0x619930
#define CEverQuest__DeleteTargetIndicator_x                        0x6199C0
#define CEverQuest__DoTellWindow_x                                 0x4E8730
#define CEverQuest__OutputTextToLog_x                              0x4E8A00
#define CEverQuest__DropHeldItemOnGround_x                         0x5F1430
#define CEverQuest__dsp_chat_x                                     0x4E8D90
#define CEverQuest__trimName_x                                     0x615B20
#define CEverQuest__Emote_x                                        0x60AB20
#define CEverQuest__EnterZone_x                                    0x604BC0
#define CEverQuest__GetBodyTypeDesc_x                              0x60F3E0
#define CEverQuest__GetClassDesc_x                                 0x60FA20
#define CEverQuest__GetClassThreeLetterCode_x                      0x610020
#define CEverQuest__GetDeityDesc_x                                 0x618180
#define CEverQuest__GetLangDesc_x                                  0x6101E0
#define CEverQuest__GetRaceDesc_x                                  0x60FA00
#define CEverQuest__InterpretCmd_x                                 0x618750
#define CEverQuest__LeftClickedOnPlayer_x                          0x5F5630
#define CEverQuest__LMouseUp_x                                     0x5F39C0
#define CEverQuest__RightClickedOnPlayer_x                         0x5F5F10
#define CEverQuest__RMouseUp_x                                     0x5F4940
#define CEverQuest__SetGameState_x                                 0x5F11C0
#define CEverQuest__UPCNotificationFlush_x                         0x615A20
#define CEverQuest__IssuePetCommand_x                              0x6115E0
#define CEverQuest__ReportSuccessfulHit_x                          0x60BE70

// CGaugeWnd
// not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x737AB0
#define CGaugeWnd__CalcLinesFillRect_x                             0x737B10
#define CGaugeWnd__Draw_x                                          0x737130

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF560
#define CGuild__GetGuildName_x                                     0x4AE590
#define CGuild__GetGuildIndex_x                                    0x4AE9D0

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton_x                               0x751CD0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x62B300

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot_x                                 0x75EC80
#define CInvSlotMgr__MoveItem_x                                    0x75D9E0
#define CInvSlotMgr__SelectSlot_x                                  0x75ED50

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x75C260
#define CInvSlot__SliderComplete_x                                 0x759FB0
#define CInvSlot__GetItemBase_x                                    0x759940
#define CInvSlot__UpdateItem_x                                     0x759AB0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7607D0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x75F970
#define CInvSlotWnd__HandleLButtonUp_x                             0x760350

// CItemDisplayWnd
#define CItemDisplayWnd__SetSpell_x                                0x81A760
#define CItemDisplayWnd__UpdateStrings_x                           0x76EE90
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x768BB0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x7690D0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x76F490
#define CItemDisplayWnd__AboutToShow_x                             0x76EAF0
#define CItemDisplayWnd__WndNotification_x                         0x770560
#define CItemDisplayWnd__RequestConvertItem_x                      0x770030
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x76DB60
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x76E910

// CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x853390

// CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x774AA0

// CKeyRingWnd
#define CKeyRingWnd__ExecuteRightClick_x                           0x51A210

// CLabel
#define CLabel__Draw_x                                             0x77A550

// CListWnd
#define CListWnd__CListWnd_x                                       0x931B70
#define CListWnd__dCListWnd_x                                      0x931E90
#define CListWnd__vftable_x                                        0xB50DF0
#define CListWnd__AddColumn_x                                      0x9362F0
#define CListWnd__AddColumn1_x                                     0x936340
#define CListWnd__AddLine_x                                        0x9366D0
#define CListWnd__AddString_x                                      0x9364D0
#define CListWnd__CalculateFirstVisibleLine_x                      0x9360B0
#define CListWnd__CalculateVSBRange_x                              0x935E90
#define CListWnd__ClearSel_x                                       0x936EB0
#define CListWnd__ClearAllSel_x                                    0x936F10
#define CListWnd__CloseAndUpdateEditWindow_x                       0x937930
#define CListWnd__Compare_x                                        0x9357D0
#define CListWnd__Draw_x                                           0x931FC0
#define CListWnd__DrawColumnSeparators_x                           0x9347A0
#define CListWnd__DrawHeader_x                                     0x934C10
#define CListWnd__DrawItem_x                                       0x935110
#define CListWnd__DrawLine_x                                       0x934910
#define CListWnd__DrawSeparator_x                                  0x934840
#define CListWnd__EnableLine_x                                     0x934080
#define CListWnd__EnsureVisible_x                                  0x937850
#define CListWnd__ExtendSel_x                                      0x936DE0
#define CListWnd__GetColumnTooltip_x                               0x933BC0
#define CListWnd__GetColumnMinWidth_x                              0x933C30
#define CListWnd__GetColumnWidth_x                                 0x933B30
#define CListWnd__GetCurSel_x                                      0x9334C0
#define CListWnd__GetItemAtPoint_x                                 0x934300
#define CListWnd__GetItemAtPoint1_x                                0x934370
#define CListWnd__GetItemData_x                                    0x933540
#define CListWnd__GetItemHeight_x                                  0x933900
#define CListWnd__GetItemIcon_x                                    0x9336D0
#define CListWnd__GetItemRect_x                                    0x934170
#define CListWnd__GetItemText_x                                    0x933580
#define CListWnd__GetSelList_x                                     0x936F60
#define CListWnd__GetSeparatorRect_x                               0x9345B0
#define CListWnd__InsertLine_x                                     0x936AC0
#define CListWnd__RemoveLine_x                                     0x936C10
#define CListWnd__SetColors_x                                      0x935E70
#define CListWnd__SetColumnJustification_x                         0x935BA0
#define CListWnd__SetColumnLabel_x                                 0x936470
#define CListWnd__SetColumnWidth_x                                 0x935AC0
#define CListWnd__SetCurSel_x                                      0x936D20
#define CListWnd__SetItemColor_x                                   0x937500
#define CListWnd__SetItemData_x                                    0x9374C0
#define CListWnd__SetItemText_x                                    0x9370D0
#define CListWnd__ShiftColumnSeparator_x                           0x935C60
#define CListWnd__Sort_x                                           0x935950
#define CListWnd__ToggleSel_x                                      0x936D50
#define CListWnd__SetColumnsSizable_x                              0x935D10
#define CListWnd__SetItemWnd_x                                     0x937380
#define CListWnd__GetItemWnd_x                                     0x933720
#define CListWnd__SetItemIcon_x                                    0x937150
#define CListWnd__CalculateCustomWindowPositions_x                 0x9361B0
#define CListWnd__SetVScrollPos_x                                  0x935AA0

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd_x                                 0x78FBE0

// MapViewMap
#define MapViewMap__MapViewMap_x                                   0x78B0D0
#define MapViewMap__dMapViewMap_x                                  0x78B220
#define MapViewMap__vftable_x                                      0xB27448
#define MapViewMap__Clear_x                                        0x78BA50
#define MapViewMap__SaveEx_x                                       0x78EE10
#define MapViewMap__SetZoom_x                                      0x7934D0
#define MapViewMap__HandleLButtonDown_x                            0x78B330
#define MapViewMap__GetWorldCoordinates_x                          0x78E2F0

// CMerchantWnd
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7AFD70
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7B0650
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7B0B80
#define CMerchantWnd__SelectRecoverySlot_x                         0x7B3B00
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7AE8E0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7B96C0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7AF990

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8B68D0
#define CPacketScrambler__hton_x                                   0x8B68C0

// CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x954EE0
#define CSidlManagerBase__CreatePageWnd_x                          0x9546D0
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x950950
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x9508E0
#define CSidlManagerBase__FindAnimation1_x                         0x950B30
#define CSidlManagerBase__FindScreenPieceTemplate_x                0x950F40
#define CSidlManagerBase__FindScreenPieceTemplate1_x               0x950D30
#define CSidlManagerBase__CreateLabel_x                            0x811980
#define CSidlManagerBase__CreateXWndFromTemplate_x                 0x953EA0
#define CSidlManagerBase__CreateXWndFromTemplate1_x                0x954080
#define CSidlManagerBase__CreateXWnd_x                             0x8118B0

// CSidlManager
#define CSidlManager__CreateHotButtonWnd_x                         0x811E80

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateHSBRange_x                        0x94D610
#define CSidlScreenWnd__CalculateVSBRange_x                        0x94D510
#define CSidlScreenWnd__ConvertToRes_x                             0x9766A0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x94CFA0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x94CC90
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x94CD60
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x94CE30
#define CSidlScreenWnd__DrawSidlPiece_x                            0x94DAB0
#define CSidlScreenWnd__EnableIniStorage_x                         0x94DF80
#define CSidlScreenWnd__GetChildItem_x                             0x94DF00
#define CSidlScreenWnd__GetSidlPiece_x                             0x94DCA0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x93D6B0
#define CSidlScreenWnd__Init1_x                                    0x94C890
#define CSidlScreenWnd__LoadIniInfo_x                              0x94DFD0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x94EB00
#define CSidlScreenWnd__LoadSidlScreen_x                           0x94BCB0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15FEA90
#define CSidlScreenWnd__StoreIniInfo_x                             0x94E680
#define CSidlScreenWnd__StoreIniVis_x                              0x94E9E0
#define CSidlScreenWnd__vftable_x                                  0xB517B8
#define CSidlScreenWnd__WndNotification_x                          0x94D9C0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x68FAB0
#define CSkillMgr__GetSkillCap_x                                   0x68FC90
#define CSkillMgr__GetNameToken_x                                  0x68F230
#define CSkillMgr__IsActivatedSkill_x                              0x68F370
#define CSkillMgr__IsCombatSkill_x                                 0x68F2B0

// CSliderWnd
#define CSliderWnd__GetValue_x                                     0x95D920
#define CSliderWnd__SetValue_x                                     0x95D790
#define CSliderWnd__SetNumTicks_x                                  0x95D7F0

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet_x                               0x817AB0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x966140
#define CStmlWnd__CalculateHSBRange_x                              0x967260
#define CStmlWnd__CalculateVSBRange_x                              0x9671E0
#define CStmlWnd__CanBreakAtCharacter_x                            0x96B5A0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x96C230
#define CStmlWnd__ForceParseNow_x                                  0x966730
#define CStmlWnd__GetNextTagPiece_x                                0x96B500
#define CStmlWnd__GetSTMLText_x                                    0x509AC0
#define CStmlWnd__GetVisibleText_x                                 0x966750
#define CStmlWnd__InitializeWindowVariables_x                      0x96C080
#define CStmlWnd__MakeStmlColorTag_x                               0x9657B0
#define CStmlWnd__MakeWndNotificationTag_x                         0x965820
#define CStmlWnd__SetSTMLText_x                                    0x964860
#define CStmlWnd__StripFirstSTMLLines_x                            0x96D330
#define CStmlWnd__UpdateHistoryString_x                            0x96C440

// CTabWnd
#define CTabWnd__Draw_x                                            0x9639B0
#define CTabWnd__DrawCurrentPage_x                                 0x9640E0
#define CTabWnd__DrawTab_x                                         0x963E00
#define CTabWnd__GetCurrentPage_x                                  0x9631B0
#define CTabWnd__GetPageInnerRect_x                                0x9633F0
#define CTabWnd__GetTabInnerRect_x                                 0x963330
#define CTabWnd__GetTabRect_x                                      0x9631E0
#define CTabWnd__InsertPage_x                                      0x963600
#define CTabWnd__SetPage_x                                         0x963470
#define CTabWnd__SetPageRect_x                                     0x9638F0
#define CTabWnd__UpdatePage_x                                      0x963CC0
#define CTabWnd__GetPageFromTabIndex_x                             0x963D40
#define CTabWnd__GetCurrentTabIndex_x                              0x9631A0

// CPageWnd
#define CPageWnd__GetTabText_x                                     0x774ED0
#define CPageWnd__SetTabText_x                                     0x962CF0

// CTextOverlay
#define CTextOverlay__DisplayText_x                                0x4A90A0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x93A5B0
#define CTextureFont__GetTextExtent_x                              0x93A770

// CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6C2710
#define CHtmlComponentWnd__ValidateUri_x                           0x7536C0
#define CHtmlWnd__SetClientCallbacks_x                             0x630390
#define CHtmlWnd__AddObserver_x                                    0x6303B0
#define CHtmlWnd__RemoveObserver_x                                 0x630410
#define Window__getProgress_x                                      0x86BCA0
#define Window__getStatus_x                                        0x86BCC0
#define Window__getURI_x                                           0x86BCD0

// CXMLDataManager
#define CXMLDataManager__GetXMLData_x                              0x9734B0

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead_x                             0x927700

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr_x                                             0x4E8280
#define CXStr__CXStr1_x                                            0x4815E0
#define CXStr__CXStr3_x                                            0x9097F0
#define CXStr__dCXStr_x                                            0x4787B0
#define CXStr__operator_equal_x                                    0x909A20
#define CXStr__operator_equal1_x                                   0x909A60
#define CXStr__operator_plus_equal1_x                              0x90A4F0
#define CXStr__SetString_x                                         0x90C3E0
#define CXStr__operator_char_p_x                                   0x909F60
#define CXStr__GetChar_x                                           0x90BD30
#define CXStr__Delete_x                                            0x90B5E0
#define CXStr__GetUnicode_x                                        0x90BDA0
#define CXStr__GetLength_x                                         0x4A8E50
#define CXStr__Mid_x                                               0x47D480
#define CXStr__Insert_x                                            0x90BE00
#define CXStr__FindNext_x                                          0x90BA50
#define CXStr__gFreeLists_x                                        0xCAC588
#define CXStr__gCXStrAccess_x                                      0x15FE1B4

// CTileLayoutWnd
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x95BBC0

// CXWnd
#define CXWnd__BringToTop_x                                        0x940E00
#define CXWnd__Center_x                                            0x940980
#define CXWnd__ClrFocus_x                                          0x9407A0
#define CXWnd__Destroy_x                                           0x940840
#define CXWnd__DoAllDrawing_x                                      0x93CE40
#define CXWnd__DrawChildren_x                                      0x93CE10
#define CXWnd__DrawColoredRect_x                                   0x93D2A0
#define CXWnd__DrawTooltip_x                                       0x93B990
#define CXWnd__DrawTooltipAtPoint_x                                0x93BA50
#define CXWnd__GetBorderFrame_x                                    0x93D100
#define CXWnd__GetChildItem_x                                      0x941010
#define CXWnd__GetChildWndAt_x                                     0x940EA0
#define CXWnd__GetClientClipRect_x                                 0x93F060
#define CXWnd__GetRelativeRect_x                                   0x93F3A0
#define CXWnd__GetScreenClipRect_x                                 0x93F130
#define CXWnd__GetScreenRect_x                                     0x93F2D0
#define CXWnd__GetTooltipRect_x                                    0x93D2F0
#define CXWnd__GetWindowTextA_x                                    0x49CC10
#define CXWnd__IsActive_x                                          0x93DA20
#define CXWnd__IsDescendantOf_x                                    0x93FCE0
#define CXWnd__IsReallyVisible_x                                   0x93FD10
#define CXWnd__IsType_x                                            0x941510
#define CXWnd__Minimize_x                                          0x940420
#define CXWnd__Move_x                                              0x93FD70
#define CXWnd__Move1_x                                             0x93FE30
#define CXWnd__ProcessTransition_x                                 0x940930
#define CXWnd__Refade_x                                            0x940110
#define CXWnd__Resize_x                                            0x9403B0
#define CXWnd__Right_x                                             0x940BC0
#define CXWnd__SetFocus_x                                          0x940760
#define CXWnd__SetFont_x                                           0x9407D0
#define CXWnd__SetKeyTooltip_x                                     0x941330
#define CXWnd__SetMouseOver_x                                      0x93E240
#define CXWnd__SetParent_x                                         0x93FA80
#define CXWnd__StartFade_x                                         0x93FBD0
#define CXWnd__vftable_x                                           0xB51234
#define CXWnd__CXWnd_x                                             0x93AA90
#define CXWnd__dCXWnd_x                                            0x93AFA0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x977720

// CXWndManager
#define CXWndManager__DrawCursor_x                                 0x943D20
#define CXWndManager__DrawWindows_x                                0x943D40
#define CXWndManager__GetKeyboardFlags_x                           0x946520
#define CXWndManager__HandleKeyboardMsg_x                          0x9460D0
#define CXWndManager__RemoveWnd_x                                  0x946740
#define CXWndManager__RemovePendingDeletionWnd_x                   0x946CB0

// CDBStr
#define CDBStr__GetString_x                                        0x543820

// CharacterZoneClient
#define CharacterZoneClient__CastSpell_x                           0x4BBCA0
#define CharacterZoneClient__Cur_HP_x                              0x4D1DB0
#define CharacterZoneClient__Cur_Mana_x                            0x4D9500
#define CharacterZoneClient__GetCastingTimeModifier_x              0x4BECE0
#define CharacterZoneClient__GetFocusCastingTimeModifier_x         0x4B27B0
#define CharacterZoneClient__GetFocusRangeModifier_x               0x4B2900
#define CharacterZoneClient__GetHPRegen_x                          0x4DF2D0
#define CharacterZoneClient__GetEnduranceRegen_x                   0x4DF8D0
#define CharacterZoneClient__GetManaRegen_x                        0x4DFD10
#define CharacterZoneClient__Max_Endurance_x                       0x656560
#define CharacterZoneClient__Max_HP_x                              0x4D1BE0
#define CharacterZoneClient__Max_Mana_x                            0x656360
#define CharacterZoneClient__doCombatAbility_x                     0x6589A0
#define CharacterZoneClient__UseSkill_x                            0x4E1AF0
#define CharacterZoneClient__IsExpansionFlag_x                     0x5B2EB0
#define CharacterZoneClient__TotalEffect_x                         0x4C5030
#define CharacterZoneClient__GetPCSpellAffect_x                    0x4BFA30
#define CharacterZoneClient__SpellDuration_x                       0x4BF560
#define CharacterZoneClient__GetAdjustedSkill_x                    0x4D4B30
#define CharacterZoneClient__GetBaseSkill_x                        0x4D5AD0
#define CharacterZoneClient__CanUseItem_x                          0x4D9810

// ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8D5A30

// PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x66CA30

// PcClient
#define PcClient__PcClient_x                                       0x64CBD0
#define PcClient__GetConLevel_x                                    0x64F490

// CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B9900
#define CCharacterListWnd__EnterWorld_x                            0x4B9340
#define CCharacterListWnd__Quit_x                                  0x4B9090
#define CCharacterListWnd__UpdateList_x                            0x4B94D0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x631550
#define EQ_Item__CreateItemTagString_x                             0x8AFED0
#define EQ_Item__IsStackable_x                                     0x8B4B30
#define EQ_Item__GetImageNum_x                                     0x8B1960
#define EQ_Item__CreateItemClient_x                                0x6307B0
#define EQ_Item__GetItemValue_x                                    0x8B2D40
#define EQ_Item__ValueSellMerchant_x                               0x8B64B0
#define EQ_Item__IsKeyRingItem_x                                   0x8B4450
#define EQ_Item__CanGoInBag_x                                      0x631670
#define EQ_Item__IsEmpty_x                                         0x8B3F80
#define EQ_Item__GetMaxItemCount_x                                 0x8B3150
#define EQ_Item__GetHeldItem_x                                     0x8B1830
#define EQ_Item__GetAugmentFitBySlot_x                             0x8AF810
#define ItemClient__ItemClient_x                                   0x5B1280
#define ItemClient__dItemClient_x                                  0x630700

// EQ_LoadingS
#define EQ_LoadingS__SetProgressBar_x                              0x561FB0
#define EQ_LoadingS__Array_x                                       0xC35B60

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x656EA0
#define EQ_PC__GetAlternateAbilityId_x                             0x8BF6C0
#define EQ_PC__GetCombatAbility_x                                  0x8BFD30
#define EQ_PC__GetCombatAbilityTimer_x                             0x8BFDA0
#define EQ_PC__GetItemRecastTimer_x                                0x658F20
#define EQ_PC__HasLoreItem_x                                       0x64FCA0
#define EQ_PC__AlertInventoryChanged_x                             0x64EDC0
#define EQ_PC__GetPcZoneClient_x                                   0x67B4C0
#define EQ_PC__RemoveMyAffect_x                                    0x65C150
#define EQ_PC__GetKeyRingItems_x                                   0x8C0630
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8C03C0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8C0930

// EQItemList
#define EQItemList__EQItemList_x                                   0x5B9410
#define EQItemList__add_object_x                                   0x5E6C20
#define EQItemList__add_item_x                                     0x5B9970
#define EQItemList__delete_item_x                                  0x5B99C0
#define EQItemList__FreeItemList_x                                 0x5B98C0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x5403C0

// EQPlayer
#define EQPlayer__ChangeBoneStringSprite_x                         0x66E2B0
#define EQPlayer__dEQPlayer_x                                      0x661610
#define EQPlayer__DoAttack_x                                       0x676150
#define EQPlayer__EQPlayer_x                                       0x661CD0
#define EQPlayer__SetNameSpriteState_x                             0x665F90
#define EQPlayer__SetNameSpriteTint_x                              0x666E60
#define PlayerBase__HasProperty_j_x                                0x9A6470
#define EQPlayer__IsTargetable_x                                   0x9A6910
#define EQPlayer__CanSee_x                                         0x9A6770
#define EQPlayer__CanSee1_x                                        0x9A6840
#define PlayerBase__GetVisibilityLineSegment_x                     0x9A6530

// PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x678F50
#define PlayerZoneClient__GetLevel_x                               0x67B500
#define PlayerZoneClient__IsValidTeleport_x                        0x5E7D90
#define PlayerZoneClient__LegalPlayerRace_x                        0x55B190

// EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x671070
#define EQPlayerManager__GetSpawnByName_x                          0x671120
#define EQPlayerManager__GetPlayerFromPartialName_x                0x6711B0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x634BE0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x634C60
#define KeypressHandler__AttachKeyToEqCommand_x                    0x634CA0
#define KeypressHandler__ClearCommandStateArray_x                  0x6360B0
#define KeypressHandler__HandleKeyDown_x                           0x6360D0
#define KeypressHandler__HandleKeyUp_x                             0x636170
#define KeypressHandler__SaveKeymapping_x                          0x6365C0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8D3A70

// StringTable
#define StringTable__getString_x                                   0x8CE8C0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x65BDC0
#define PcZoneClient__RemovePetEffect_x                            0x65C3F0
#define PcZoneClient__HasAlternateAbility_x                        0x656190
#define PcZoneClient__GetCurrentMod_x                              0x4E4BB0
#define PcZoneClient__GetModCap_x                                  0x4E4AB0
#define PcZoneClient__CanEquipItem_x                               0x656840
#define PcZoneClient__GetItemByID_x                                0x659390
#define PcZoneClient__GetItemByItemClass_x                         0x6594E0
#define PcZoneClient__RemoveBuffEffect_x                           0x65C410
#define PcZoneClient__BandolierSwap_x                              0x657460
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x658EC0

// Doors
#define EQSwitch__UseSwitch_x                                      0x5EC8B0

// IconCache
#define IconCache__GetIcon_x                                       0x72D290

// CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x724D70
#define CContainerMgr__CloseContainer_x                            0x725040
#define CContainerMgr__OpenExperimentContainer_x                   0x725AC0

// CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7E3E00

// CHelpWnd
#define CHelpWnd__SetFile_x                                        0x629700

// CLootWnd
#define CLootWnd__LootAll_x                                        0x782040
#define CLootWnd__RequestLootSlot_x                                0x781270

// EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x586C30
#define EQ_Spell__SpellAffects_x                                   0x5870A0
#define EQ_Spell__SpellAffectBase_x                                0x586E60
#define EQ_Spell__IsStackable_x                                    0x4C97D0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C95F0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6C80
#define EQ_Spell__IsSPAStacking_x                                  0x587EF0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x587400
#define EQ_Spell__IsNoRemove_x                                     0x4C97B0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x587F00
#define __IsResEffectSpell_x                                       0x4C8A50

// EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD0E0

// EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8DE090

// CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x82AF70
#define CTargetWnd__WndNotification_x                              0x82A7B0
#define CTargetWnd__RefreshTargetBuffs_x                           0x82AA80
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x829930

// CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x82F580

// CTaskManager
#define CTaskManager__GetEntry_x                                   0x53DDF0
#define CTaskManager__HandleMessage_x                              0x53C290
#define CTaskManager__GetTaskStatus_x                              0x53DEA0
#define CTaskManager__GetElementDescription_x                      0x53DF20

// EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x581D90
#define EqSoundManager__PlayScriptMp3_x                            0x582050
#define EqSoundManager__SoundAssistPlay_x                          0x6939F0
#define EqSoundManager__WaveInstancePlay_x                         0x692F60

// CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52F560

// CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x962200

// CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x569A50
#define CAltAbilityData__GetMercMaxRank_x                          0x5699E0
#define CAltAbilityData__GetMaxRank_x                              0x55EE80

// CTargetRing
#define CTargetRing__Cast_x                                        0x627810

// CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C95D0
#define CharacterBase__CreateItemGlobalIndex_x                     0x516790
#define CharacterBase__CreateItemIndex_x                           0x62F940
#define CharacterBase__GetItemPossession_x                         0x5025F0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8E66F0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8E6750

// CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x70BD10
#define CCastSpellWnd__IsBardSongPlaying_x                         0x70C540
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x70C5F0

// messages
#define msg_spell_worn_off_x                                       0x5AB0B0
#define msg_new_text_x                                             0x59FE30
#define __msgTokenTextParam_x                                      0x5AD5E0
#define msgTokenText_x                                             0x5AD830

// SpellManager
#define SpellManager__vftable_x                                    0xAF9780
#define SpellManager__SpellManager_x                               0x696D20
#define Spellmanager__LoadTextSpells_x                             0x697610
#define SpellManager__GetSpellByGroupAndRank_x                     0x696EF0

// CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x 0x9AA3A0

// ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8DEA30
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8DECB0

// CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x77A890

// CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x729490
#define CCursorAttachment__AttachToCursor1_x                       0x7294D0
#define CCursorAttachment__Deactivate_x                            0x72A4C0

// CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x971E00
#define CEQSuiteTextureLoader__GetTexture_x                        0x971AC0

// CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x513D30
#define CFindItemWnd__WndNotification_x                            0x514810
#define CFindItemWnd__Update_x                                     0x515380
#define CFindItemWnd__PickupSelectedItem_x                         0x513570

// IString
#define IString__Append_x                                          0x4F3930

// Camera
#define CDisplay__cameraType_x                                     0xE0F6DC
#define EverQuest__Cameras_x                                       0xECA56C

// LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51C5C0
#define LootFiltersManager__GetItemFilterData_x                    0x51BED0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51BF00
#define LootFiltersManager__SetItemLootFilter_x                    0x51C120

// COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7D1CC0

// CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9AFEC0
#define CResolutionHandler__GetWindowedStyle_x                     0x68E520

// CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x7219A0

// CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8F3E50
#define CDistillerInfo__Instance_x                                 0x8F3DF0

// CGroupWnd
#define CGroupWnd__WndNotification_x                               0x740A80
#define CGroupWnd__UpdateDisplay_x                                 0x73FDE0

// ItemBase
#define ItemBase__IsLore_x                                         0x8B4500
#define ItemBase__IsLoreEquipped_x                                 0x8B4570

// EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5E6B80
#define EQPlacedItemManager__GetItemByGuid_x                       0x5E6CC0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5E6D20

// RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x683C70
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x687620

// CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50A100

// FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F65F0
#define FactionManagerClient__HandleFactionMessage_x               0x4F6C60
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F7260
#define FactionManagerClient__GetMaxFaction_x                      0x4F727F
#define FactionManagerClient__GetMinFaction_x                      0x4F7230

// BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x5025C0

// ArrayClass
#define ArrayClass__DeleteElement_x                                0x9395D0

// AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BF20

// ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x502830

// MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x568EF0

// CTargetManager
#define CTargetManager__Get_x                                      0x69A540

// RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x683C70

// CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8E60

// EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5B9860

// EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF67C00

// KeyCombo
#define KeyCombo__GetTextDescription_x                             0x923DD0

//
// EQGraphicsDX9.dll offsets (maybe this should go in eqgraphics.h?)
//

#define __eqgraphics_fopen_x                                       0x10147468
#define CParticleSystem__Render_x                                  0x10071190
