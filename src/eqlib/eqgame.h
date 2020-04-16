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
#define __ExpectedVersionDate                                     "Apr 13 2020"
#define __ExpectedVersionTime                                     "16:06:55"
#define __ActualVersionDate_x                                      0xB1A3E0
#define __ActualVersionTime_x                                      0xB1A3D4
#define __ActualVersionBuild_x                                     0xB060C4

// Memory Protection
#define __MemChecker0_x                                            0x63D340
#define __MemChecker1_x                                            0x911740
#define __MemChecker2_x                                            0x6CBCE0
#define __MemChecker3_x                                            0x6CBC30
#define __MemChecker4_x                                            0x867B80
#define __EncryptPad0_x                                            0xC524E0
#define __EncryptPad1_x                                            0xCB0648
#define __EncryptPad2_x                                            0xC62D78
#define __EncryptPad3_x                                            0xC62978
#define __EncryptPad4_x                                            0xCA0BF8
#define __EncryptPad5_x                                            0xF73C7C
#define __AC1_x                                                    0x8243F6
#define __AC2_x                                                    0x5F6F8F
#define __AC3_x                                                    0x5FE5DF
#define __AC4_x                                                    0x6025A0
#define __AC5_x                                                    0x60884F
#define __AC6_x                                                    0x60CD46
#define __AC7_x                                                    0x5F6A00
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x70AF0

// Direct Input
#define DI8__Main_x                                                0xF73C9C
#define DI8__Keyboard_x                                            0xF73CA0
#define DI8__Mouse_x                                               0xF73CB8
#define DI8__Mouse_Copy_x                                          0xECCE6C
#define DI8__Mouse_Check_x                                         0xF717D0
#define __AutoSkillArray_x                                         0xECDD84
#define __Attack_x                                                 0xF6BBAB
#define __Autofire_x                                               0xF6BBAC
#define __BindList_x                                               0xC40F30
#define g_eqCommandStates_x                                        0xC41CB0
#define __Clicks_x                                                 0xECCF24
#define __CommandList_x                                            0xC42870
#define __CurrentMapLabel_x                                        0xF84674
#define __CurrentSocial_x                                          0xC2A7CC
#define __DoAbilityList_x                                          0xF036CC
#define __do_loot_x                                                0x5C27B0
#define __DrawHandler_x                                            0x16039F0
#define __GroupCount_x                                             0xEC7EC2
#define __Guilds_x                                                 0xECBDB0
#define __gWorld_x                                                 0xEC7E50
#define __HWnd_x                                                   0xF73CBC
#define __heqmain_x                                                0xF73C64
#define __InChatMode_x                                             0xECCE54
#define __LastTell_x                                               0xECEDC8
#define __LMouseHeldTime_x                                         0xECCF90
#define __Mouse_x                                                  0xF73C88
#define __MouseLook_x                                              0xECCEEA
#define __MouseEventTime_x                                         0xF6C68C
#define __gpbCommandEvent_x                                        0xEC80C0
#define __NetStatusToggle_x                                        0xECCEED
#define __PCNames_x                                                0xECE374
#define __RangeAttackReady_x                                       0xECE068
#define __RMouseHeldTime_x                                         0xECCF8C
#define __RunWalkState_x                                           0xECCE58
#define __ScreenMode_x                                             0xE131B4
#define __ScreenX_x                                                0xECCE0C
#define __ScreenY_x                                                0xECCE08
#define __ScreenXMax_x                                             0xECCE10
#define __ScreenYMax_x                                             0xECCE14
#define __ServerHost_x                                             0xEC59EB
#define __ServerName_x                                             0xF0368C
#define __ShiftKeyDown_x                                           0xECD4E4
#define __ShowNames_x                                              0xECE224
#define __SocialChangedList_x                                      0xF03714
#define __Socials_x                                                0xF0378C
#define __SubscriptionType_x                                       0xFC8B80
#define __TargetAggroHolder_x                                      0xF87028
#define __ZoneType_x                                               0xECD2E8
#define __GroupAggro_x                                             0xF87068
#define __LoginName_x                                              0xF743F4
#define __Inviter_x                                                0xF6BB28
#define __AttackOnAssist_x                                         0xECE1E0
#define __UseTellWindows_x                                         0xECE510
#define __gfMaxZoomCameraDistance_x                                0xB0FD18
#define __gfMaxCameraDistance_x                                    0xB3C14C
#define __pulAutoRun_x                                             0xECCF08
#define __pulForward_x                                             0xECE548
#define __pulBackward_x                                            0xECE54C
#define __pulTurnRight_x                                           0xECE550
#define __pulTurnLeft_x                                            0xECE554
#define __pulStrafeLeft_x                                          0xECE558
#define __pulStrafeRight_x                                         0xECE55C

////
//Section 1: Vital Offsets
////
#define instCRaid_x                                                0xEC8148
#define instEQZoneInfo_x                                           0xECD0E0
#define pinstActiveBanker_x                                        0xEC5850
#define pinstActiveCorpse_x                                        0xEC5844
#define pinstActiveGMaster_x                                       0xEC584C
#define pinstActiveMerchant_x                                      0xEC5840
#define pinstAltAdvManager_x                                       0xE14378
#define pinstBandageTarget_x                                       0xEC5864
#define pinstCamActor_x                                            0xE131A4
#define pinstCDBStr_x                                              0xE13094
#define pinstCDisplay_x                                            0xEC7D0C
#define pinstCEverQuest_x                                          0xF73CB4
#define pinstEverQuestInfo_x                                       0xECCE00
#define pinstCharData_x                                            0xEC7EAC
#define pinstCharSpawn_x                                           0xEC58B0
#define pinstControlledMissile_x                                   0xEC5AF4
#define pinstControlledPlayer_x                                    0xEC58B0
#define pinstCResolutionHandler_x                                  0x1603C20
#define pinstCSidlManager_x                                        0x1602BB8
#define pinstCXWndManager_x                                        0x1602BB4
#define instDynamicZone_x                                          0xECBC88
#define pinstDZMember_x                                            0xECBD98
#define pinstDZTimerInfo_x                                         0xECBD9C
#define pinstEqLogin_x                                             0xF73D40
#define instEQMisc_x                                               0xE12FD8
#define pinstEQSoundManager_x                                      0xE15348
#define pinstEQSpellStrings_x                                      0xCD59E0
#define instExpeditionLeader_x                                     0xECBCD2
#define instExpeditionName_x                                       0xECBD12
#define pinstSGraphicsEngine_x                                     0x16039E4
#define pinstGroup_x                                               0xEC7EBE
#define pinstImeManager_x                                          0x1602BB0
#define pinstLocalPlayer_x                                         0xEC583C
#define pinstMercenaryData_x                                       0xF6E184
#define pinstMercenaryStats_x                                      0xF87174
#define pinstModelPlayer_x                                         0xEC5858
#define pinstPCData_x                                              0xEC7EAC
#define pinstSkillMgr_x                                            0xF702E8
#define pinstSpawnManager_x                                        0xF6ED90
#define pinstSpellManager_x                                        0xF70528
#define pinstSpellSets_x                                           0xF647D4
#define pinstStringTable_x                                         0xEC80B0
#define pinstSwitchManager_x                                       0xEC56E8
#define pinstTarget_x                                              0xEC58A4
#define pinstTargetObject_x                                        0xEC58E0
#define pinstTargetSwitch_x                                        0xEC5D04
#define pinstTaskMember_x                                          0xE12E68
#define pinstTrackTarget_x                                         0xEC58B8
#define pinstTradeTarget_x                                         0xEC5854
#define instTributeActive_x                                        0xE12FF9
#define pinstViewActor_x                                           0xE131A0
#define pinstWorldData_x                                           0xEC5D00
#define pinstZoneAddr_x                                            0xECD380
#define pinstPlayerPath_x                                          0xF6EE28
#define pinstTargetIndicator_x                                     0xF70790
#define EQObject_Top_x                                             0xEC5838

////
//Section 2:  UI Related Offsets
////
#define pinstCAAWnd_x                                              0xE134AC
#define pinstCAchievementsWnd_x                                    0xE139BC
#define pinstCActionsWnd_x                                         0xE134F4
#define pinstCAdvancedDisplayOptionsWnd_x                          0xE131F4
#define pinstCAdvancedLootWnd_x                                    0xE13188
#define pinstCAdventureLeaderboardWnd_x                            0xF7DE48
#define pinstCAdventureRequestWnd_x                                0xF7DEF8
#define pinstCAdventureStatsWnd_x                                  0xF7DFA8
#define pinstCAggroMeterWnd_x                                      0xE131E8
#define pinstCAlarmWnd_x                                           0xE13164
#define pinstCAlertHistoryWnd_x                                    0xE13250
#define pinstCAlertStackWnd_x                                      0xE1318C
#define pinstCAlertWnd_x                                           0xE131C4
#define pinstCAltStorageWnd_x                                      0xF7E308
#define pinstCAudioTriggersWindow_x                                0xCC7D10
#define pinstCAuraWnd_x                                            0xE13190
#define pinstCAvaZoneWnd_x                                         0xE13260
#define pinstCBandolierWnd_x                                       0xE131E4
#define pinstCBankWnd_x                                            0xE1322C
#define pinstCBarterMerchantWnd_x                                  0xF7F548
#define pinstCBarterSearchWnd_x                                    0xF7F5F8
#define pinstCBarterWnd_x                                          0xF7F6A8
#define pinstCBazaarConfirmationWnd_x                              0xE13168
#define pinstCBazaarSearchWnd_x                                    0xE134B0
#define pinstCBazaarWnd_x                                          0xE13138
#define pinstCBlockedBuffWnd_x                                     0xE131A8
#define pinstCBlockedPetBuffWnd_x                                  0xE131DC
#define pinstCBodyTintWnd_x                                        0xE13978
#define pinstCBookWnd_x                                            0xE13210
#define pinstCBreathWnd_x                                          0xE134C0
#define pinstCBuffWindowNORMAL_x                                   0xE1317C
#define pinstCBuffWindowSHORT_x                                    0xE13180
#define pinstCBugReportWnd_x                                       0xE13224
#define pinstCButtonWnd_x                                          0x1602E20
#define pinstCCastingWnd_x                                         0xE13204
#define pinstCCastSpellWnd_x                                       0xE134B4
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE13990
#define pinstCChatWindowManager_x                                  0xF80168
#define pinstCClaimWnd_x                                           0xF802C0
#define pinstCColorPickerWnd_x                                     0xE13478
#define pinstCCombatAbilityWnd_x                                   0xE13150
#define pinstCCombatSkillsSelectWnd_x                              0xE139A0
#define pinstCCompassWnd_x                                         0xE13570
#define pinstCConfirmationDialog_x                                 0xF851C0
#define pinstCContainerMgr_x                                       0xE1398C
#define pinstCContextMenuManager_x                                 0x1602B70
#define pinstCCursorAttachment_x                                   0xE131F8
#define pinstCDynamicZoneWnd_x                                     0xF80888
#define pinstCEditLabelWnd_x                                       0xE13178
#define pinstCEQMainWnd_x                                          0xF80AD0
#define pinstCEventCalendarWnd_x                                   0xE134A8
#define pinstCExtendedTargetWnd_x                                  0xE131D8
#define pinstCFacePick_x                                           0xE139B0
#define pinstCFactionWnd_x                                         0xE13130
#define pinstCFellowshipWnd_x                                      0xF80CD0
#define pinstCFileSelectionWnd_x                                   0xE13474
#define pinstCFindItemWnd_x                                        0xE139B4
#define pinstCFindLocationWnd_x                                    0xF80E28
#define pinstCFriendsWnd_x                                         0xE139AC
#define pinstCGemsGameWnd_x                                        0xE139C8
#define pinstCGiveWnd_x                                            0xE13160
#define pinstCGroupSearchFiltersWnd_x                              0xE13208
#define pinstCGroupSearchWnd_x                                     0xF81220
#define pinstCGroupWnd_x                                           0xF812D0
#define pinstCGuildBankWnd_x                                       0xECE1C4
#define pinstCGuildCreationWnd_x                                   0xF81430
#define pinstCGuildMgmtWnd_x                                       0xF814E0
#define pinstCharacterCreation_x                                   0xE139A4
#define pinstCHelpWnd_x                                            0xE13158
#define pinstCHeritageSelectionWnd_x                               0xE139C4
#define pinstCHotButtonWnd_x                                       0xF83638
#define pinstCHotButtonWnd1_x                                      0xF83638
#define pinstCHotButtonWnd2_x                                      0xF8363C
#define pinstCHotButtonWnd3_x                                      0xF83640
#define pinstCHotButtonWnd4_x                                      0xF83644
#define pinstCIconSelectionWnd_x                                   0xE131EC
#define pinstCInspectWnd_x                                         0xE131E0
#define pinstCInventoryWnd_x                                       0xE13198
#define pinstCInvSlotMgr_x                                         0xE134BC
#define pinstCItemDisplayManager_x                                 0xF83BC8
#define pinstCItemExpTransferWnd_x                                 0xF83CF8
#define pinstCItemOverflowWnd_x                                    0xE134B8
#define pinstCJournalCatWnd_x                                      0xE13498
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE1325C
#define pinstCKeyRingWnd_x                                         0xE13200
#define pinstCLargeDialogWnd_x                                     0xF85E40
#define pinstCLayoutCopyWnd_x                                      0xF84048
#define pinstCLFGuildWnd_x                                         0xF840F8
#define pinstCLoadskinWnd_x                                        0xE13140
#define pinstCLootFiltersCopyWnd_x                                 0xCE4370
#define pinstCLootFiltersWnd_x                                     0xE13194
#define pinstCLootSettingsWnd_x                                    0xE131D4
#define pinstCLootWnd_x                                            0xE13490
#define pinstCMailAddressBookWnd_x                                 0xE134C4
#define pinstCMailCompositionWnd_x                                 0xE134A0
#define pinstCMailIgnoreListWnd_x                                  0xE134C8
#define pinstCMailWnd_x                                            0xE1347C
#define pinstCManageLootWnd_x                                      0xE14828
#define pinstCMapToolbarWnd_x                                      0xE1315C
#define pinstCMapViewWnd_x                                         0xE13134
#define pinstCMarketplaceWnd_x                                     0xE1319C
#define pinstCMerchantWnd_x                                        0xE1349C
#define pinstCMIZoneSelectWnd_x                                    0xF84930
#define pinstCMusicPlayerWnd_x                                     0xE13240
#define pinstCNameChangeMercWnd_x                                  0xE1314C
#define pinstCNameChangePetWnd_x                                   0xE139C0
#define pinstCNameChangeWnd_x                                      0xE1316C
#define pinstCNoteWnd_x                                            0xE13144
#define pinstCObjectPreviewWnd_x                                   0xE131D0
#define pinstCOptionsWnd_x                                         0xE13154
#define pinstCPetInfoWnd_x                                         0xE13264
#define pinstCPetitionQWnd_x                                       0xE13994
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE13984
#define pinstCPlayerWnd_x                                          0xE13470
#define pinstCPopupWndManager_x                                    0xF851C0
#define pinstCProgressionSelectionWnd_x                            0xF85270
#define pinstCPurchaseGroupWnd_x                                   0xE1321C
#define pinstCPurchaseWnd_x                                        0xE131F0
#define pinstCPvPLeaderboardWnd_x                                  0xF85320
#define pinstCPvPStatsWnd_x                                        0xF853D0
#define pinstCQuantityWnd_x                                        0xE13254
#define pinstCRaceChangeWnd_x                                      0xE13184
#define pinstCRaidOptionsWnd_x                                     0xE1320C
#define pinstCRaidWnd_x                                            0xE13494
#define pinstCRealEstateItemsWnd_x                                 0xE139B8
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE134F0
#define pinstCRealEstateManageWnd_x                                0xE13228
#define pinstCRealEstateNeighborhoodWnd_x                          0xE13248
#define pinstCRealEstatePlotSearchWnd_x                            0xE1326C
#define pinstCRealEstatePurchaseWnd_x                              0xE13480
#define pinstCRespawnWnd_x                                         0xE131CC
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE13998
#define pinstCSendMoneyWnd_x                                       0xE13170
#define pinstCServerListWnd_x                                      0xE13484
#define pinstCSkillsSelectWnd_x                                    0xE13988
#define pinstCSkillsWnd_x                                          0xE1356C
#define pinstCSocialEditWnd_x                                      0xE131FC
#define pinstCSocialWnd_x                                          0xE1313C
#define pinstCSpellBookWnd_x                                       0xE13148
#define pinstCStoryWnd_x                                           0xE134EC
#define pinstCTargetOfTargetWnd_x                                  0xF871F8
#define pinstCTargetWnd_x                                          0xE131C8
#define pinstCTaskOverlayWnd_x                                     0xE13218
#define pinstCTaskSelectWnd_x                                      0xF87350
#define pinstCTaskManager_x                                        0xCE4CB0
#define pinstCTaskTemplateSelectWnd_x                              0xF87400
#define pinstCTaskWnd_x                                            0xF874B0
#define pinstCTextEntryWnd_x                                       0xE13214
#define pinstCTimeLeftWnd_x                                        0xE13980
#define pinstCTipWndCONTEXT_x                                      0xF876B4
#define pinstCTipWndOFDAY_x                                        0xF876B0
#define pinstCTitleWnd_x                                           0xF87760
#define pinstCTrackingWnd_x                                        0xE131B8
#define pinstCTradeskillWnd_x                                      0xF878C8
#define pinstCTradeWnd_x                                           0xE1397C
#define pinstCTrainWnd_x                                           0xE13488
#define pinstCTributeBenefitWnd_x                                  0xF87AC8
#define pinstCTributeMasterWnd_x                                   0xF87B78
#define pinstCTributeTrophyWnd_x                                   0xF87C28
#define pinstCVideoModesWnd_x                                      0xE13258
#define pinstCVoiceMacroWnd_x                                      0xF70EF8
#define pinstCVoteResultsWnd_x                                     0xE139A8
#define pinstCVoteWnd_x                                            0xE1399C
#define pinstCWebManager_x                                         0xF71574
#define pinstCZoneGuideWnd_x                                       0xE13220
#define pinstCZonePathWnd_x                                        0xE1323C
#define pinstEQSuiteTextureLoader_x                                0xCB2120
#define pinstItemIconCache_x                                       0xF80A88
#define pinstLootFiltersManager_x                                  0xCE4420
#define pinstRewardSelectionWnd_x                                  0xF85B18

////
// Section 3: Miscellaneous Offsets
////
#define __CastRay_x                                                0x5BDB80
#define __CastRay2_x                                               0x5BDBD0
#define __ConvertItemTags_x                                        0x5D9A10
#define __CleanItemTags_x                                          0x47CF80
#define __CreateCascadeMenuItems_x                                 0x558F00
#define __DoesFileExist_x                                          0x9147C0
#define __EQGetTime_x                                              0x911210
#define __ExecuteCmd_x                                             0x5B6400
#define __FixHeading_x                                             0x9AC300
#define __FlushDxKeyboard_x                                        0x6C7BA0
#define __GameLoop_x                                               0x6CAEB0
#define __get_bearing_x                                            0x5BD6F0
#define __get_melee_range_x                                        0x5BDDC0
#define __GetAnimationCache_x                                      0x7303E0
#define __GetGaugeValueFromEQ_x                                    0x8228A0
#define __GetLabelFromEQ_x                                         0x824380
#define __GetXTargetType_x                                         0x9ADDC0
#define __HandleMouseWheel_x                                       0x6CBD90
#define __HeadingDiff_x                                            0x9AC370
#define __HelpPath_x                                               0xF6C27C
#define __LoadFrontEnd_x                                           0x6C81D0
#define __NewUIINI_x                                               0x822570
#define __ProcessGameEvents_x                                      0x61E760
#define __ProcessKeyboardEvents_x                                  0x6C9710
#define __ProcessMouseEvents_x                                     0x61DF20
#define __SaveColors_x                                             0x558DE0
#define __STMLToText_x                                             0x94F820
#define __WndProc_x                                                0x6CA170
#define CMemoryMappedFile__SetFile_x                               0xA9B810
#define CrashDetected_x                                            0x6C9C70
#define DrawNetStatus_x                                            0x64A6E0
#define Expansion_HoT_x                                            0xECE1CC
#define Teleport_Table_Size_x                                      0xEC5860
#define Teleport_Table_x                                           0xEC5D08
#define Util__FastTime_x                                           0x910DE0
#define __eq_delete_x                                              0x9B491E
#define __eq_new_x                                                 0x9B4EE4

////
// Section 4: Function Offsets
////

// CAAwnd
#define CAAWnd__ShowAbility_x                                      0x6D8120
#define CAAWnd__Update_x                                           0x6D7440
#define CAAWnd__UpdateSelected_x                                   0x6D4990

// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490320
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499230
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499000
#define CAdvancedLootWnd__AddPlayerToList_x                        0x4938C0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492D10

// AltAdvManager
#define AltAdvManager__GetCalculatedTimer_x                        0x560F60
#define AltAdvManager__IsAbilityReady_x                            0x55FD00
#define AltAdvManager__GetAAById_x                                 0x560090
#define AltAdvManager__CanTrainAbility_x                           0x560100
#define AltAdvManager__CanSeeAbility_x                             0x560460

// CharacterZoneClient
#define CharacterZoneClient__BardCastBard_x                        0x4C5880
#define CharacterZoneClient__CalcAffectChange_x                    0x4C3FC0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4190
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BAC30
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C9E70
#define CharacterZoneClient__FindAffectSlot_x                      0x4C2D00
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7370
#define CharacterZoneClient__FindItemByRecord_x                    0x4D6DF0
#define CharacterZoneClient__GetCurrentMod_x                       0x4E4B20
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D8F70
#define CharacterZoneClient__GetEffect_x                           0x4BAB70
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C3E20
#define CharacterZoneClient__GetFocusDurationMod_x                 0x4B1060
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2AF0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D8E90
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8DB0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C3E70
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAD00
#define CharacterZoneClient__GetModCap_x                           0x4E4A20
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C3D50
#define CharacterZoneClient__HasSkill_x                            0x4D4CF0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE600
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6410

// CBankWnd
#define CBankWnd__GetNumBankSlots_x                                0x6F19B0
#define CBankWnd__WndNotification_x                                0x6F1790

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6FF310

// CButtonWnd
#define CButtonWnd__SetCheck_x                                     0x62CFF0
#define CButtonWnd__CButtonWnd_x                                   0x94BBD0
#define CButtonWnd__dCButtonWnd_x                                  0x94BEB0
#define CButtonWnd__vftable_x                                      0xB54E78

// CChatWindowManager
#define CChatWindowManager__GetRGBAFromIndex_x                     0x71F470
#define CChatWindowManager__InitContextMenu_x                      0x7185A0
#define CChatWindowManager__FreeChatWindow_x                       0x71DFB0
#define CChatWindowManager__GetLockedActiveChatWindow_x            0x4E8310
#define CChatWindowManager__SetLockedActiveChatWindow_x            0x71F0F0
#define CChatWindowManager__CreateChatWindow_x                     0x71E5F0

// ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8420

// CChatWindow
#define CChatWindow__CChatWindow_x                                 0x71FCE0
#define CChatWindow__Clear_x                                       0x720FA0
#define CChatWindow__WndNotification_x                             0x721730
#define CChatWindow__AddHistory_x                                  0x720860

// CContextMenu
#define CContextMenu__CContextMenu_x                               0x960300
#define CContextMenu__dCContextMenu_x                              0x960540
#define CContextMenu__AddMenuItem_x                                0x960550
#define CContextMenu__RemoveMenuItem_x                             0x960860
#define CContextMenu__RemoveAllMenuItems_x                         0x960880
#define CContextMenu__CheckMenuItem_x                              0x960900
#define CContextMenu__SetMenuItem_x                                0x960780
#define CContextMenu__AddSeparator_x                               0x9606E0

// CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x960E90
#define CContextMenuManager__RemoveMenu_x                          0x960F00
#define CContextMenuManager__PopupMenu_x                           0x960FC0
#define CContextMenuManager__Flush_x                               0x960E30
#define CContextMenuManager__GetMenu_x                             0x49B300
#define CContextMenuManager__CreateDefaultMenu_x                   0x72ABE0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8B4790
#define CChatService__GetFriendName_x                              0x8EC300

// CComboWnd
#define CComboWnd__DeleteAll_x                                     0x95D760
#define CComboWnd__Draw_x                                          0x95CC50
#define CComboWnd__GetCurChoice_x                                  0x95D5A0
#define CComboWnd__GetListRect_x                                   0x95D100
#define CComboWnd__GetTextRect_x                                   0x95D7D0
#define CComboWnd__InsertChoice_x                                  0x95D290
#define CComboWnd__SetColors_x                                     0x95D260
#define CComboWnd__SetChoice_x                                     0x95D570
#define CComboWnd__GetItemCount_x                                  0x95D5B0
#define CComboWnd__GetCurChoiceText_x                              0x95D5F0
#define CComboWnd__GetChoiceText_x                                 0x95D5C0
#define CComboWnd__InsertChoiceAtIndex_x                           0x95D330

// CContainerWnd
#define CContainerWnd__HandleCombine_x                             0x7285F0
#define CContainerWnd__vftable_x                                   0xB235C4
#define CContainerWnd__SetContainer_x                              0x729B40

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x553790
#define CDisplay__PreZoneMainUI_x                                  0x5537A0
#define CDisplay__CleanGameUI_x                                    0x558BA0
#define CDisplay__GetClickedActor_x                                0x54BB50
#define CDisplay__GetUserDefinedColor_x                            0x5441B0
#define CDisplay__GetWorldFilePath_x                               0x54D5C0
#define CDisplay__is3dON_x                                         0x5487B0
#define CDisplay__ReloadUI_x                                       0x552C10
#define CDisplay__WriteTextHD2_x                                   0x5485A0
#define CDisplay__TrueDistance_x                                   0x54F280
#define CDisplay__SetViewActor_x                                   0x54B470
#define CDisplay__GetFloorHeight_x                                 0x548870
#define CDisplay__SetRenderWindow_x                                0x5471D0
#define CDisplay__ToggleScreenshotMode_x                           0x54AF40

// CEditBaseWnd
#define CEditBaseWnd__SetSel_x                                     0x97FF70

// CEditWnd
#define CEditWnd__DrawCaret_x                                      0x963870
#define CEditWnd__EnsureCaretVisible_x                             0x965A40
#define CEditWnd__GetCaretPt_x                                     0x9649F0
#define CEditWnd__GetCharIndexPt_x                                 0x9647A0
#define CEditWnd__GetDisplayString_x                               0x964640
#define CEditWnd__GetHorzOffset_x                                  0x962EA0
#define CEditWnd__GetLineForPrintableChar_x                        0x965940
#define CEditWnd__GetSelStartPt_x                                  0x964A50
#define CEditWnd__GetSTMLSafeText_x                                0x964460
#define CEditWnd__PointFromPrintableChar_x                         0x965570
#define CEditWnd__ReplaceSelection_x                               0x9651E0
#define CEditWnd__SelectableCharFromPoint_x                        0x9656E0
#define CEditWnd__SetEditable_x                                    0x964B20
#define CEditWnd__SetWindowTextA_x                                 0x9641E0

// CEverQuest
#define CEverQuest__DoPercentConvert_x                             0x60C220
#define CEverQuest__ClickedPlayer_x                                0x5FE3C0
#define CEverQuest__CreateTargetIndicator_x                        0x61B9F0
#define CEverQuest__DeleteTargetIndicator_x                        0x61BA80
#define CEverQuest__DoTellWindow_x                                 0x4E8500
#define CEverQuest__OutputTextToLog_x                              0x4E87D0
#define CEverQuest__DropHeldItemOnGround_x                         0x5F34B0
#define CEverQuest__dsp_chat_x                                     0x4E8B60
#define CEverQuest__trimName_x                                     0x617C00
#define CEverQuest__Emote_x                                        0x60CA80
#define CEverQuest__EnterZone_x                                    0x606B20
#define CEverQuest__GetBodyTypeDesc_x                              0x611340
#define CEverQuest__GetClassDesc_x                                 0x611980
#define CEverQuest__GetClassThreeLetterCode_x                      0x611F80
#define CEverQuest__GetDeityDesc_x                                 0x61A240
#define CEverQuest__GetLangDesc_x                                  0x612140
#define CEverQuest__GetRaceDesc_x                                  0x611960
#define CEverQuest__InterpretCmd_x                                 0x61A810
#define CEverQuest__LeftClickedOnPlayer_x                          0x5F76B0
#define CEverQuest__LMouseUp_x                                     0x5F5A40
#define CEverQuest__RightClickedOnPlayer_x                         0x5F7F90
#define CEverQuest__RMouseUp_x                                     0x5F69C0
#define CEverQuest__SetGameState_x                                 0x5F3240
#define CEverQuest__UPCNotificationFlush_x                         0x617B00
#define CEverQuest__IssuePetCommand_x                              0x613540
#define CEverQuest__ReportSuccessfulHeal_x                         0x60D7A0
#define CEverQuest__ReportSuccessfulHit_x                          0x60DDD0

// CGaugeWnd
// not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x73A6B0
#define CGaugeWnd__CalcLinesFillRect_x                             0x73A710
#define CGaugeWnd__Draw_x                                          0x739D30

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF4C0
#define CGuild__GetGuildName_x                                     0x4AE500
#define CGuild__GetGuildIndex_x                                    0x4AE940

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton_x                               0x754950

//CHotButton
#define CHotButton__SetButtonSize_x                                0x62D3B0

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot_x                                 0x761960
#define CInvSlotMgr__MoveItem_x                                    0x760680
#define CInvSlotMgr__SelectSlot_x                                  0x761A30

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x75EF00
#define CInvSlot__SliderComplete_x                                 0x75CC60
#define CInvSlot__GetItemBase_x                                    0x75C5E0
#define CInvSlot__UpdateItem_x                                     0x75C750

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7634B0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x762650
#define CInvSlotWnd__HandleLButtonUp_x                             0x763030

// CItemDisplayWnd
#define CItemDisplayWnd__SetSpell_x                                0x81DC40
#define CItemDisplayWnd__UpdateStrings_x                           0x771C20
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x76B940
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x76BE50
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x772230
#define CItemDisplayWnd__AboutToShow_x                             0x771870
#define CItemDisplayWnd__WndNotification_x                         0x773370
#define CItemDisplayWnd__RequestConvertItem_x                      0x772DE0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x7708D0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x771690

// CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x856950

// CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x7778A0

// CKeyRingWnd
#define CKeyRingWnd__ExecuteRightClick_x                           0x5195A0

// CLabel
#define CLabel__Draw_x                                             0x77D2F0

// CListWnd
#define CListWnd__CListWnd_x                                       0x935D50
#define CListWnd__dCListWnd_x                                      0x936070
#define CListWnd__vftable_x                                        0xB54750
#define CListWnd__AddColumn_x                                      0x93A4C0
#define CListWnd__AddColumn1_x                                     0x93A510
#define CListWnd__AddLine_x                                        0x93A8A0
#define CListWnd__AddString_x                                      0x93A6A0
#define CListWnd__CalculateFirstVisibleLine_x                      0x93A280
#define CListWnd__CalculateVSBRange_x                              0x93A080
#define CListWnd__ClearSel_x                                       0x93B080
#define CListWnd__ClearAllSel_x                                    0x93B0E0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x93BB00
#define CListWnd__Compare_x                                        0x9399B0
#define CListWnd__Draw_x                                           0x9361A0
#define CListWnd__DrawColumnSeparators_x                           0x938990
#define CListWnd__DrawHeader_x                                     0x938DF0
#define CListWnd__DrawItem_x                                       0x9392F0
#define CListWnd__DrawLine_x                                       0x938AF0
#define CListWnd__DrawSeparator_x                                  0x938A30
#define CListWnd__EnableLine_x                                     0x938270
#define CListWnd__EnsureVisible_x                                  0x93BA20
#define CListWnd__ExtendSel_x                                      0x93AFB0
#define CListWnd__GetColumnTooltip_x                               0x937DB0
#define CListWnd__GetColumnMinWidth_x                              0x937E20
#define CListWnd__GetColumnWidth_x                                 0x937D20
#define CListWnd__GetCurSel_x                                      0x9376B0
#define CListWnd__GetItemAtPoint_x                                 0x9384E0
#define CListWnd__GetItemAtPoint1_x                                0x938550
#define CListWnd__GetItemData_x                                    0x937730
#define CListWnd__GetItemHeight_x                                  0x937AF0
#define CListWnd__GetItemIcon_x                                    0x9378C0
#define CListWnd__GetItemRect_x                                    0x938360
#define CListWnd__GetItemText_x                                    0x937770
#define CListWnd__GetSelList_x                                     0x93B130
#define CListWnd__GetSeparatorRect_x                               0x938790
#define CListWnd__InsertLine_x                                     0x93AC90
#define CListWnd__RemoveLine_x                                     0x93ADE0
#define CListWnd__SetColors_x                                      0x93A050
#define CListWnd__SetColumnJustification_x                         0x939D80
#define CListWnd__SetColumnLabel_x                                 0x93A640
#define CListWnd__SetColumnWidth_x                                 0x939CA0
#define CListWnd__SetCurSel_x                                      0x93AEF0
#define CListWnd__SetItemColor_x                                   0x93B6D0
#define CListWnd__SetItemData_x                                    0x93B690
#define CListWnd__SetItemText_x                                    0x93B2A0
#define CListWnd__ShiftColumnSeparator_x                           0x939E40
#define CListWnd__Sort_x                                           0x939B30
#define CListWnd__ToggleSel_x                                      0x93AF20
#define CListWnd__SetColumnsSizable_x                              0x939EF0
#define CListWnd__SetItemWnd_x                                     0x93B550
#define CListWnd__GetItemWnd_x                                     0x937910
#define CListWnd__SetItemIcon_x                                    0x93B320
#define CListWnd__CalculateCustomWindowPositions_x                 0x93A380
#define CListWnd__SetVScrollPos_x                                  0x939C80

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd_x                                 0x792B20

// MapViewMap
#define MapViewMap__MapViewMap_x                                   0x78E010
#define MapViewMap__dMapViewMap_x                                  0x78E160
#define MapViewMap__vftable_x                                      0xB2AC08
#define MapViewMap__Clear_x                                        0x78E990
#define MapViewMap__SaveEx_x                                       0x791D50
#define MapViewMap__SetZoom_x                                      0x796410
#define MapViewMap__HandleLButtonDown_x                            0x78E270
#define MapViewMap__GetWorldCoordinates_x                          0x791230

// CMerchantWnd
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7B2F00
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7B37E0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7B3D10
#define CMerchantWnd__SelectRecoverySlot_x                         0x7B6C80
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7B1A70
#define CMerchantWnd__SelectBuySellSlot_x                          0x7BC830
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7B2B10

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8B9DD0
#define CPacketScrambler__hton_x                                   0x8B9DC0

// CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x959220
#define CSidlManagerBase__CreatePageWnd_x                          0x958A10
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x954C90
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x954C20
#define CSidlManagerBase__FindAnimation1_x                         0x954E70
#define CSidlManagerBase__FindScreenPieceTemplate_x                0x955280
#define CSidlManagerBase__FindScreenPieceTemplate1_x               0x955070
#define CSidlManagerBase__CreateLabel_x                            0x814F10
#define CSidlManagerBase__CreateXWndFromTemplate_x                 0x9581E0
#define CSidlManagerBase__CreateXWndFromTemplate1_x                0x9583C0
#define CSidlManagerBase__CreateXWnd_x                             0x814E40

// CSidlManager
#define CSidlManager__CreateHotButtonWnd_x                         0x815410

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateHSBRange_x                        0x951950
#define CSidlScreenWnd__CalculateVSBRange_x                        0x951850
#define CSidlScreenWnd__ConvertToRes_x                             0x97AA60
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x9512E0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x950FD0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x9510A0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x951170
#define CSidlScreenWnd__DrawSidlPiece_x                            0x951DE0
#define CSidlScreenWnd__EnableIniStorage_x                         0x9522B0
#define CSidlScreenWnd__GetChildItem_x                             0x952230
#define CSidlScreenWnd__GetSidlPiece_x                             0x951FD0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9418F0
#define CSidlScreenWnd__Init1_x                                    0x950BD0
#define CSidlScreenWnd__LoadIniInfo_x                              0x952300
#define CSidlScreenWnd__LoadIniListWnd_x                           0x952E50
#define CSidlScreenWnd__LoadSidlScreen_x                           0x94FFD0
#define CSidlScreenWnd__m_layoutCopy_x                             0x1602A40
#define CSidlScreenWnd__StoreIniInfo_x                             0x9529C0
#define CSidlScreenWnd__StoreIniVis_x                              0x952D30
#define CSidlScreenWnd__vftable_x                                  0xB55108
#define CSidlScreenWnd__WndNotification_x                          0x951CF0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6921D0
#define CSkillMgr__GetSkillCap_x                                   0x6923B0
#define CSkillMgr__GetNameToken_x                                  0x691950
#define CSkillMgr__IsActivatedSkill_x                              0x691A90
#define CSkillMgr__IsCombatSkill_x                                 0x6919D0

// CSliderWnd
#define CSliderWnd__GetValue_x                                     0x961C80
#define CSliderWnd__SetValue_x                                     0x961AF0
#define CSliderWnd__SetNumTicks_x                                  0x961B50

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet_x                               0x81B000

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x96A4B0
#define CStmlWnd__CalculateHSBRange_x                              0x96B5D0
#define CStmlWnd__CalculateVSBRange_x                              0x96B540
#define CStmlWnd__CanBreakAtCharacter_x                            0x96F900
#define CStmlWnd__FastForwardToEndOfTag_x                          0x970590
#define CStmlWnd__ForceParseNow_x                                  0x96AAA0
#define CStmlWnd__GetNextTagPiece_x                                0x96F860
#define CStmlWnd__GetSTMLText_x                                    0x508ED0
#define CStmlWnd__GetVisibleText_x                                 0x96AAC0
#define CStmlWnd__InitializeWindowVariables_x                      0x9703E0
#define CStmlWnd__MakeStmlColorTag_x                               0x969B20
#define CStmlWnd__MakeWndNotificationTag_x                         0x969B90
#define CStmlWnd__SetSTMLText_x                                    0x968BD0
#define CStmlWnd__StripFirstSTMLLines_x                            0x971660
#define CStmlWnd__UpdateHistoryString_x                            0x9707A0

// CTabWnd
#define CTabWnd__Draw_x                                            0x967D10
#define CTabWnd__DrawCurrentPage_x                                 0x968440
#define CTabWnd__DrawTab_x                                         0x968160
#define CTabWnd__GetCurrentPage_x                                  0x967510
#define CTabWnd__GetCurrentTabIndex_x                              0x967500
#define CTabWnd__GetPageFromTabIndex_x                             0x9680A0
#define CTabWnd__GetPageInnerRect_x                                0x967750
#define CTabWnd__GetTabInnerRect_x                                 0x967690
#define CTabWnd__GetTabRect_x                                      0x967540
#define CTabWnd__InsertPage_x                                      0x967960
#define CTabWnd__RemovePage_x                                      0x967AD0
#define CTabWnd__SetPage_x                                         0x9677D0
#define CTabWnd__SetPageRect_x                                     0x967C50
#define CTabWnd__UpdatePage_x                                      0x968020

// CPageWnd
#define CPageWnd__FlashTab_x                                       0x9670B0
#define CPageWnd__GetTabText_x                                     0x777C70
#define CPageWnd__SetTabText_x                                     0x967050


// CTextOverlay
#define CTextOverlay__DisplayText_x                                0x4A8E80

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x93E7C0
#define CTextureFont__DrawWrappedText1_x                           0x93E6F0
#define CTextureFont__DrawWrappedText2_x                           0x93E810
#define CTextureFont__GetTextExtent_x                              0x93E980

// CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6C4D90
#define CHtmlComponentWnd__ValidateUri_x                           0x756340
#define CHtmlWnd__SetClientCallbacks_x                             0x632450
#define CHtmlWnd__AddObserver_x                                    0x632470
#define CHtmlWnd__RemoveObserver_x                                 0x6324D0
#define Window__getProgress_x                                      0x86F1A0
#define Window__getStatus_x                                        0x86F1C0
#define Window__getURI_x                                           0x86F1D0

// CXMLDataManager
#define CXMLDataManager__GetXMLData_x                              0x977860

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead_x                             0x92BA30

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr_x                                             0x4E81D0
#define CXStr__CXStr1_x                                            0x934440
#define CXStr__CXStr3_x                                            0x90D3B0
#define CXStr__dCXStr_x                                            0x478680
#define CXStr__operator_equal_x                                    0x90D5E0
#define CXStr__operator_equal1_x                                   0x90D620
#define CXStr__operator_plus_equal1_x                              0x90E0B0
#define CXStr__SetString_x                                         0x90FFA0
#define CXStr__operator_char_p_x                                   0x90DAF0
#define CXStr__GetChar_x                                           0x90F8D0
#define CXStr__Delete_x                                            0x90F1A0
#define CXStr__GetUnicode_x                                        0x90F940
#define CXStr__GetLength_x                                         0x47D330
#define CXStr__Mid_x                                               0x47D340
#define CXStr__Insert_x                                            0x90F9A0
#define CXStr__FindNext_x                                          0x90F610
#define CXStr__gFreeLists_x                                        0xCB0578
#define CXStr__gCXStrAccess_x                                      0x1602164

// CTileLayoutWnd
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x95FF20

// CXWnd
#define CXWnd__BringToTop_x                                        0x945110
#define CXWnd__Center_x                                            0x944C90
#define CXWnd__ClrFocus_x                                          0x944AA0
#define CXWnd__Destroy_x                                           0x944B50
#define CXWnd__DoAllDrawing_x                                      0x941080
#define CXWnd__DrawChildren_x                                      0x941050
#define CXWnd__DrawColoredRect_x                                   0x9414E0
#define CXWnd__DrawTooltip_x                                       0x93FBC0
#define CXWnd__DrawTooltipAtPoint_x                                0x93FC80
#define CXWnd__GetBorderFrame_x                                    0x941340
#define CXWnd__GetChildItem_x                                      0x945320
#define CXWnd__GetChildWndAt_x                                     0x9451B0
#define CXWnd__GetClientClipRect_x                                 0x943310
#define CXWnd__GetRelativeRect_x                                   0x943640
#define CXWnd__GetScreenClipRect_x                                 0x9433E0
#define CXWnd__GetScreenRect_x                                     0x943580
#define CXWnd__GetTooltipRect_x                                    0x941530
#define CXWnd__GetWindowTextA_x                                    0x49C9E0
#define CXWnd__IsActive_x                                          0x941C70
#define CXWnd__IsDescendantOf_x                                    0x943FA0
#define CXWnd__IsReallyVisible_x                                   0x943FD0
#define CXWnd__IsType_x                                            0x945820
#define CXWnd__Minimize_x                                          0x944720
#define CXWnd__Move_x                                              0x944040
#define CXWnd__Move1_x                                             0x944100
#define CXWnd__ProcessTransition_x                                 0x944C40
#define CXWnd__Refade_x                                            0x9443E0
#define CXWnd__Resize_x                                            0x9446B0
#define CXWnd__Right_x                                             0x944ED0
#define CXWnd__SetFocus_x                                          0x944A60
#define CXWnd__SetFont_x                                           0x944AD0
#define CXWnd__SetKeyTooltip_x                                     0x945630
#define CXWnd__SetMouseOver_x                                      0x9424A0
#define CXWnd__SetParent_x                                         0x943D30
#define CXWnd__StartFade_x                                         0x943E80
#define CXWnd__vftable_x                                           0xB54B94
#define CXWnd__CXWnd_x                                             0x93ECA0
#define CXWnd__dCXWnd_x                                            0x93F1C0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x97BAE0

// CXWndManager
#define CXWndManager__DrawCursor_x                                 0x948050
#define CXWndManager__DrawWindows_x                                0x948070
#define CXWndManager__GetKeyboardFlags_x                           0x94A870
#define CXWndManager__HandleKeyboardMsg_x                          0x94A420
#define CXWndManager__RemoveWnd_x                                  0x94AA90
#define CXWndManager__RemovePendingDeletionWnd_x                   0x94AFF0

// CDBStr
#define CDBStr__GetString_x                                        0x543130

// CharacterZoneClient
#define CharacterZoneClient__CanUseItem_x                          0x4D9780
#define CharacterZoneClient__CastSpell_x                           0x4BBC10
#define CharacterZoneClient__Cur_HP_x                              0x4D1D30
#define CharacterZoneClient__Cur_Mana_x                            0x4D9470
#define CharacterZoneClient__GetAdjustedSkill_x                    0x4D4AB0
#define CharacterZoneClient__GetBaseSkill_x                        0x4D5A50
#define CharacterZoneClient__GetCastingTimeModifier_x              0x4BEC50
#define CharacterZoneClient__GetEnduranceRegen_x                   0x4DF840
#define CharacterZoneClient__GetFocusCastingTimeModifier_x         0x4B2730
#define CharacterZoneClient__GetFocusRangeModifier_x               0x4B2880
#define CharacterZoneClient__GetHPRegen_x                          0x4DF240
#define CharacterZoneClient__GetManaRegen_x                        0x4DFC80
#define CharacterZoneClient__GetPCSpellAffect_x                    0x4BF9A0
#define CharacterZoneClient__Max_Endurance_x                       0x658D20
#define CharacterZoneClient__Max_HP_x                              0x4D1B60
#define CharacterZoneClient__Max_Mana_x                            0x658B20
#define CharacterZoneClient__SpellDuration_x                       0x4BF4D0
#define CharacterZoneClient__TotalEffect_x                         0x4C4FC0
#define CharacterZoneClient__UseSkill_x                            0x4E1A60

// ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8D9220

// PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x66F150

// PcClient
#define PcClient__PcClient_x                                       0x64EDA0
#define PcClient__GetConLevel_x                                    0x651670

// CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B9880
#define CCharacterListWnd__EnterWorld_x                            0x4B92C0
#define CCharacterListWnd__Quit_x                                  0x4B9010
#define CCharacterListWnd__UpdateList_x                            0x4B9450

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x633610
#define EQ_Item__CreateItemTagString_x                             0x8B3390
#define EQ_Item__IsStackable_x                                     0x8B8050
#define EQ_Item__GetImageNum_x                                     0x8B4F20
#define EQ_Item__CreateItemClient_x                                0x632850
#define EQ_Item__GetItemValue_x                                    0x8B6240
#define EQ_Item__ValueSellMerchant_x                               0x8B99B0
#define EQ_Item__IsKeyRingItem_x                                   0x8B7970
#define EQ_Item__CanGoInBag_x                                      0x633730
#define EQ_Item__IsEmpty_x                                         0x8B74A0
#define EQ_Item__GetMaxItemCount_x                                 0x8B6650
#define EQ_Item__GetHeldItem_x                                     0x8B4DF0
#define EQ_Item__GetAugmentFitBySlot_x                             0x8B2BD0
#define ItemClient__ItemClient_x                                   0x5B3010
#define ItemClient__dItemClient_x                                  0x6327A0

// EQ_LoadingS
#define EQ_LoadingS__SetProgressBar_x                              0x561C70
#define EQ_LoadingS__Array_x                                       0xC39C60

// EQ_PC
#define EQ_PC__GetAlternateAbilityId_x                             0x8C2E50
#define EQ_PC__GetCombatAbility_x                                  0x8C34C0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8C3530
#define EQ_PC__GetItemRecastTimer_x                                0x65B6C0
#define EQ_PC__HasLoreItem_x                                       0x651E30
#define EQ_PC__AlertInventoryChanged_x                             0x650FA0
#define EQ_PC__GetPcZoneClient_x                                   0x67DB70
#define EQ_PC__RemoveMyAffect_x                                    0x65E8F0
#define EQ_PC__GetKeyRingItems_x                                   0x8C3DC0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8C3B50
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8C40C0

// EQItemList
#define EQItemList__EQItemList_x                                   0x5BB100
#define EQItemList__add_object_x                                   0x5E8D00
#define EQItemList__add_item_x                                     0x5BB660
#define EQItemList__delete_item_x                                  0x5BB6B0
#define EQItemList__FreeItemList_x                                 0x5BB5B0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x53FC70

// EQPlayer
#define EQPlayer__ChangeBoneStringSprite_x                         0x6709D0
#define EQPlayer__dEQPlayer_x                                      0x663EA0
#define EQPlayer__DoAttack_x                                       0x678830
#define EQPlayer__EQPlayer_x                                       0x664560
#define EQPlayer__SetNameSpriteState_x                             0x6687E0
#define EQPlayer__SetNameSpriteTint_x                              0x6696B0
#define PlayerBase__HasProperty_j_x                                0x9AA710
#define EQPlayer__IsTargetable_x                                   0x9AABB0
#define EQPlayer__CanSee_x                                         0x9AAA10
#define EQPlayer__CanSee1_x                                        0x9AAAE0
#define PlayerBase__GetVisibilityLineSegment_x                     0x9AA7D0

// PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x67B610
#define PlayerZoneClient__GetLevel_x                               0x67DBB0
#define PlayerZoneClient__IsValidTeleport_x                        0x5E9E70
#define PlayerZoneClient__LegalPlayerRace_x                        0x55A9D0

// EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x673720
#define EQPlayerManager__GetSpawnByName_x                          0x6737D0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x673860

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x636D10
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x636D90
#define KeypressHandler__AttachKeyToEqCommand_x                    0x636DD0
#define KeypressHandler__ClearCommandStateArray_x                  0x6381E0
#define KeypressHandler__HandleKeyDown_x                           0x638200
#define KeypressHandler__HandleKeyUp_x                             0x6382A0
#define KeypressHandler__SaveKeymapping_x                          0x6386F0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8D7250

// StringTable
#define StringTable__getString_x                                   0x8D2160

// PcZoneClient
#define PcZoneClient__doCombatAbility_x                            0x65B140
#define PcZoneClient__DestroyHeldItemOrMoney_x                     0x659660
#define PcZoneClient__GetPcSkillLimit_x                            0x65E560
#define PcZoneClient__RemovePetEffect_x                            0x65EB90
#define PcZoneClient__HasAlternateAbility_x                        0x658950
#define PcZoneClient__CanEquipItem_x                               0x659000
#define PcZoneClient__GetItemByID_x                                0x65BB30
#define PcZoneClient__GetItemByItemClass_x                         0x65BC80
#define PcZoneClient__RemoveBuffEffect_x                           0x65EBB0
#define PcZoneClient__BandolierSwap_x                              0x659C10
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x65B660

// Doors
#define EQSwitch__UseSwitch_x                                      0x5EE910

// IconCache
#define IconCache__GetIcon_x                                       0x72FC80

// CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x727790
#define CContainerMgr__CloseContainer_x                            0x727A60
#define CContainerMgr__OpenExperimentContainer_x                   0x7284E0

// CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7E7290

// CHelpWnd
#define CHelpWnd__SetFile_x                                        0x62B7B0

// CLootWnd
#define CLootWnd__LootAll_x                                        0x784DE0
#define CLootWnd__RequestLootSlot_x                                0x784010

// EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x588380
#define EQ_Spell__SpellAffects_x                                   0x5887F0
#define EQ_Spell__SpellAffectBase_x                                0x5885B0
#define EQ_Spell__IsStackable_x                                    0x4C9780
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C95A0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6C00
#define EQ_Spell__IsSPAStacking_x                                  0x589640
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x588B50
#define EQ_Spell__IsNoRemove_x                                     0x4C9760
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x589650
#define __IsResEffectSpell_x                                       0x4C8A40

// EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD030

// EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8E17A0

// CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x82E370
#define CTargetWnd__WndNotification_x                              0x82DBB0
#define CTargetWnd__RefreshTargetBuffs_x                           0x82DE80
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x82CD20

// CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x8329B0
#define CTaskWnd__ConfirmAbandonTask_x                             0x8355F0

// CTaskManager
#define CTaskManager__GetEntry_x                                   0x53D6B0
#define CTaskManager__HandleMessage_x                              0x53BB30
#define CTaskManager__GetTaskStatus_x                              0x53D760
#define CTaskManager__GetElementDescription_x                      0x53D7E0

// EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x583530
#define EqSoundManager__PlayScriptMp3_x                            0x5837F0
#define EqSoundManager__SoundAssistPlay_x                          0x696090
#define EqSoundManager__WaveInstancePlay_x                         0x695600

// CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52ED20

// CTextureAnimation
#define CTextureAnimation__Draw_x                                  0x966760
#define CTextureAnimation__SetCurCell_x                            0x966560

// CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x569750
#define CAltAbilityData__GetMercMaxRank_x                          0x5696E0
#define CAltAbilityData__GetMaxRank_x                              0x55EB80

// CTargetRing
#define CTargetRing__Cast_x                                        0x6298D0

// CharacterBase
#define CharacterBase__CreateItemGlobalIndex_x                     0x515B50
#define CharacterBase__CreateItemIndex_x                           0x631A00
#define CharacterBase__GetItemByGlobalIndex_x                      0x8E9EB0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8E9F10
#define CharacterBase__GetItemPossession_x                         0x5018D0
#define CharacterBase__GetMemorizedSpell_x                         0x4C9580
#define CharacterBase__IsExpansionFlag_x                           0x5B4C40

// CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x70E7B0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x70EFE0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x70F090

// messages
#define msg_spell_worn_off_x                                       0x5ACCC0
#define msg_new_text_x                                             0x5A1680
#define __msgTokenTextParam_x                                      0x5AEF60
#define msgTokenText_x                                             0x5AF1B0

// SpellManager
#define SpellManager__vftable_x                                    0xAFD140
#define SpellManager__SpellManager_x                               0x6993C0
#define Spellmanager__LoadTextSpells_x                             0x699CB0
#define SpellManager__GetSpellByGroupAndRank_x                     0x699590

// CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x 0x9AE6B0

// ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8E2140
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8E23C0

// CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x77D630

// CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x72BE80
#define CCursorAttachment__AttachToCursor1_x                       0x72BEC0
#define CCursorAttachment__Deactivate_x                            0x72CEB0

// CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9761B0
#define CEQSuiteTextureLoader__GetTexture_x                        0x975E70

// CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x5130F0
#define CFindItemWnd__WndNotification_x                            0x513BD0
#define CFindItemWnd__Update_x                                     0x514740
#define CFindItemWnd__PickupSelectedItem_x                         0x512940

// IString
#define IString__Append_x                                          0x503160

// Camera
#define CDisplay__cameraType_x                                     0xE13268
#define EverQuest__Cameras_x                                       0xECE51C

// LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51B940
#define LootFiltersManager__GetItemFilterData_x                    0x51B240
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51B270
#define LootFiltersManager__SetItemLootFilter_x                    0x51B490

// COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7D5080

// CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9B4390
#define CResolutionHandler__GetWindowedStyle_x                     0x690C60

// CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x724440

// CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8F78E0
#define CDistillerInfo__Instance_x                                 0x8F7880

// CGroupWnd
#define CGroupWnd__WndNotification_x                               0x7436E0
#define CGroupWnd__UpdateDisplay_x                                 0x742A30

// ItemBase
#define ItemBase__IsLore_x                                         0x8B7A20
#define ItemBase__IsLoreEquipped_x                                 0x8B7A90

// EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5E8C60
#define EQPlacedItemManager__GetItemByGuid_x                       0x5E8DA0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5E8E00

// RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x686290
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x689BF0

// CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x5094D0

// FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F5C80
#define FactionManagerClient__HandleFactionMessage_x               0x4F62F0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F68B0
#define FactionManagerClient__GetMaxFaction_x                      0x4F68CF
#define FactionManagerClient__GetMinFaction_x                      0x4F6880

// BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x5018A0

// ArrayClass
#define ArrayClass__DeleteElement_x                                0x93D770

// AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BCF0

// ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x501B60

// MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x568BF0

// CTargetManager
#define CTargetManager__Get_x                                      0x69CC00

// RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x686290

// CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8C40

// EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5BB550

// EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF6BBB0

// KeyCombo
#define KeyCombo__GetTextDescription_x                             0x927FA0

//
// EQGraphicsDX9.dll offsets (maybe this should go in eqgraphics.h?)
//

#define __eqgraphics_fopen_x                                       0x10147468
#define CParticleSystem__Render_x                                  0x10071190
