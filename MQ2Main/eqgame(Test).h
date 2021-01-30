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
#define __ExpectedVersionDate                                     "Jan 25 2021"
#define __ExpectedVersionTime                                     "12:41:36"
#define __ActualVersionDate_x                                      0xB45EE4
#define __ActualVersionTime_x                                      0xB45ED8
#define __ActualVersionBuild_x                                     0xB360C4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x6646E0
#define __MemChecker1_x                                            0x945850
#define __MemChecker2_x                                            0x6DE8D0
#define __MemChecker3_x                                            0x6DE840
#define __MemChecker4_x                                            0x898E60
#define __EncryptPad0_x                                            0xE46F40
#define __EncryptPad1_x                                            0xEA1740
#define __EncryptPad2_x                                            0xE56158
#define __EncryptPad3_x                                            0xE55D58
#define __EncryptPad4_x                                            0xE92550
#define __EncryptPad5_x                                            0xF95020
#define __AC1_x                                                    0x853B50
#define __AC2_x                                                    0x61953F
#define __AC3_x                                                    0x620921
#define __AC4_x                                                    0x624A90
#define __AC5_x                                                    0x62B34F
#define __AC6_x                                                    0x62FA96
#define __AC7_x                                                    0x618FA0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x24D588

// Direct Input
#define DI8__Main_x                                                0xF950CC
#define DI8__Keyboard_x                                            0xF950D0
#define DI8__Mouse_x                                               0xF9502C
#define DI8__Mouse_Copy_x                                          0xDA1D7C
#define DI8__Mouse_Check_x                                         0xF92B74
#define __AutoSkillArray_x                                         0xDA2C98
#define __Attack_x                                                 0xE40AC7
#define __Autofire_x                                               0xE40AC8
#define __BindList_x                                               0xD97448
#define g_eqCommandStates_x                                        0xD981B0
#define __Clicks_x                                                 0xDA1E34
#define __CommandList_x                                            0xD98D38
#define __CurrentMapLabel_x                                        0xFA5ACC
#define __CurrentSocial_x                                          0xC5246C
#define __DoAbilityList_x                                          0xDD85E8
#define __do_loot_x                                                0x5E2370
#define __DrawHandler_x                                            0x1614820
#define __GroupCount_x                                             0xF8813A
#define __Guilds_x                                                 0xF8C610
#define __gWorld_x                                                 0xF8834C
#define __HWnd_x                                                   0xF95030
#define __heqmain_x                                                0xF95008
#define __InChatMode_x                                             0xDA1D64
#define __LastTell_x                                               0xDA3CE4
#define __LMouseHeldTime_x                                         0xDA1EA0
#define __Mouse_x                                                  0xF950B8
#define __MouseLook_x                                              0xDA1DFA
#define __MouseEventTime_x                                         0xF8E03C
#define __gpbCommandEvent_x                                        0xF88458
#define __NetStatusToggle_x                                        0xDA1DFD
#define __PCNames_x                                                0xDA3294
#define __RangeAttackReady_x                                       0xDA2F7C
#define __RMouseHeldTime_x                                         0xDA1E9C
#define __RunWalkState_x                                           0xDA1D68
#define __ScreenMode_x                                             0xED445C
#define __ScreenX_x                                                0xDA1D1C
#define __ScreenY_x                                                0xDA1D18
#define __ScreenXMax_x                                             0xDA1D20
#define __ScreenYMax_x                                             0xDA1D24
#define __ServerHost_x                                             0xF88623
#define __ServerName_x                                             0xDD85A8
#define __ShiftKeyDown_x                                           0xDA23F8
#define __ShowNames_x                                              0xDA3138
#define EverQuestInfo__bSocialChanged_x                            0xDD8630
#define __Socials_x                                                0xDD86A8
#define __SubscriptionType_x                                       0xFD9BA8
#define __TargetAggroHolder_x                                      0xFA8480
#define __ZoneType_x                                               0xDA21F8
#define __GroupAggro_x                                             0xFA84C0
#define __LoginName_x                                              0xF9579C
#define __Inviter_x                                                0xE40A44
#define __AttackOnAssist_x                                         0xDA30F4
#define __UseTellWindows_x                                         0xDA342C
#define __gfMaxZoomCameraDistance_x                                0xB3DDC8
#define __gfMaxCameraDistance_x                                    0xB66504
#define __pulAutoRun_x                                             0xDA1E18
#define __pulForward_x                                             0xDA3464
#define __pulBackward_x                                            0xDA3468
#define __pulTurnRight_x                                           0xDA346C
#define __pulTurnLeft_x                                            0xDA3470
#define __pulStrafeLeft_x                                          0xDA3474
#define __pulStrafeRight_x                                         0xDA3478

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF889A8
#define instEQZoneInfo_x                                           0xDA1FF0
#define pinstActiveBanker_x                                        0xF88944
#define pinstActiveCorpse_x                                        0xF8893C
#define pinstActiveGMaster_x                                       0xF88940
#define pinstActiveMerchant_x                                      0xF88938
#define pinstAltAdvManager_x                                       0xED52A0
#define pinstBandageTarget_x                                       0xF88954
#define pinstCamActor_x                                            0xED4450
#define pinstCDBStr_x                                              0xED4028
#define pinstCDisplay_x                                            0xF860B4
#define pinstCEverQuest_x                                          0xF95034
#define pinstEverQuestInfo_x                                       0xDA1D10
#define pinstCharData_x                                            0xF860A4
#define pinstCharSpawn_x                                           0xF8898C
#define pinstControlledMissile_x                                   0xF88998
#define pinstControlledPlayer_x                                    0xF8898C
#define pinstCResolutionHandler_x                                  0x1614A48
#define pinstCSidlManager_x                                        0x16139E4
#define pinstCXWndManager_x                                        0x16139DC
#define instDynamicZone_x                                          0xF8C4E8
#define pinstDZMember_x                                            0xF8C5F8
#define pinstDZTimerInfo_x                                         0xF8C5FC
#define pinstEqLogin_x                                             0xF950E8
#define instEQMisc_x                                               0xD8B8D8
#define pinstEQSoundManager_x                                      0xED5BB0
#define pinstEQSpellStrings_x                                      0xEC4CC8
#define instExpeditionLeader_x                                     0xF8C532
#define instExpeditionName_x                                       0xF8C572
#define pinstGroup_x                                               0xF88136
#define pinstImeManager_x                                          0x16139E0
#define pinstLocalPlayer_x                                         0xF88934
#define pinstMercenaryData_x                                       0xF8FB34
#define pinstMercenaryStats_x                                      0xFA854C
#define pinstModelPlayer_x                                         0xF8894C
#define pinstPCData_x                                              0xF860A4
#define pinstSkillMgr_x                                            0xF91C20
#define pinstSpawnManager_x                                        0xF906F8
#define pinstSpellManager_x                                        0xF91E60
#define pinstSpellSets_x                                           0xE396F0
#define pinstStringTable_x                                         0xF860AC
#define pinstSwitchManager_x                                       0xF85F48
#define pinstTarget_x                                              0xF88988
#define pinstTargetObject_x                                        0xF8609C
#define pinstTargetSwitch_x                                        0xF860A0
#define pinstTaskMember_x                                          0xD8B420
#define pinstTrackTarget_x                                         0xF88990
#define pinstTradeTarget_x                                         0xF88948
#define instTributeActive_x                                        0xD8B8F9
#define pinstViewActor_x                                           0xED444C
#define pinstWorldData_x                                           0xF860B0
#define pinstZoneAddr_x                                            0xDA2290
#define pinstPlayerPath_x                                          0xF90790
#define pinstTargetIndicator_x                                     0xF920C8
#define EQObject_Top_x                                             0xF86098
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xED4490
#define pinstCAchievementsWnd_x                                    0xED4120
#define pinstCActionsWnd_x                                         0xED4420
#define pinstCAdvancedDisplayOptionsWindow_x                       0xED442C
#define pinstCAdvancedLootWnd_x                                    0xED4424
#define pinstCAdventureLeaderboardWnd_x                            0xF9F2F0
#define pinstCAdventureRequestWnd_x                                0xF9F3A0
#define pinstCAdventureStatsWnd_x                                  0xF9F450
#define pinstCAggroMeterWnd_x                                      0xED41A8
#define pinstCAlarmWnd_x                                           0xED4488
#define pinstCAlertHistoryWnd_x                                    0xED420C
#define pinstCAlertStackWnd_x                                      0xED41DC
#define pinstCAlertWnd_x                                           0xED41E0
#define pinstCAltStorageWnd_x                                      0xF9F7B0
#define pinstCAudioTriggersWindow_x                                0xEB6FF8
#define pinstCAuraWnd_x                                            0xED4468
#define pinstCAvaZoneWnd_x                                         0xED4108
#define pinstCBandolierWnd_x                                       0xED4478
#define pinstCBankWnd_x                                            0xED41E8
#define pinstCBarterMerchantWnd_x                                  0xFA09F0
#define pinstCBarterSearchWnd_x                                    0xFA0AA0
#define pinstCBarterWnd_x                                          0xFA0B50
#define pinstCBazaarConfirmationWnd_x                              0xED44A8
#define pinstCBazaarSearchWnd_x                                    0xED4130
#define pinstCBazaarWnd_x                                          0xED40E8
#define pinstCBlockedBuffWnd_x                                     0xED416C
#define pinstCBlockedPetBuffWnd_x                                  0xED4174
#define pinstCBodyTintWnd_x                                        0xED44BC
#define pinstCBookWnd_x                                            0xED4200
#define pinstCBreathWnd_x                                          0xED4494
#define pinstCBuffWindowNORMAL_x                                   0xED4164
#define pinstCBuffWindowSHORT_x                                    0xED4168
#define pinstCBugReportWnd_x                                       0xED411C
#define pinstCButtonWnd_x                                          0x1613C48
#define pinstCCastingWnd_x                                         0xED41A4
#define pinstCCastSpellWnd_x                                       0xED41B4
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xED4148
#define pinstCChatWindowManager_x                                  0xFA15F8
#define pinstCClaimWnd_x                                           0xFA1750
#define pinstCColorPickerWnd_x                                     0xED415C
#define pinstCCombatAbilityWnd_x                                   0xED4438
#define pinstCCombatSkillsSelectWnd_x                              0xED443C
#define pinstCCompassWnd_x                                         0xED446C
#define pinstCConfirmationDialog_x                                 0xFA6618
#define pinstCContainerMgr_x                                       0xED449C
#define pinstCContextMenuManager_x                                 0x1613998
#define pinstCCursorAttachment_x                                   0xED419C
#define pinstCDynamicZoneWnd_x                                     0xFA1D18
#define pinstCEditLabelWnd_x                                       0xED40FC
#define pinstCEQMainWnd_x                                          0xFA1F60
#define pinstCEventCalendarWnd_x                                   0xED448C
#define pinstCExtendedTargetWnd_x                                  0xED41A0
#define pinstCPlayerCustomizationWnd_x                             0xED414C
#define pinstCFactionWnd_x                                         0xED41B0
#define pinstCFellowshipWnd_x                                      0xFA2160
#define pinstCFileSelectionWnd_x                                   0xED4444
#define pinstCFindItemWnd_x                                        0xED44C8
#define pinstCFindLocationWnd_x                                    0xFA22B8
#define pinstCFriendsWnd_x                                         0xED4440
#define pinstCGemsGameWnd_x                                        0xED4480
#define pinstCGiveWnd_x                                            0xED40F0
#define pinstCGroupSearchFiltersWnd_x                              0xED417C
#define pinstCGroupSearchWnd_x                                     0xFA26B0
#define pinstCGroupWnd_x                                           0xFA2760
#define pinstCGuildBankWnd_x                                       0xFA2810
#define pinstCGuildCreationWnd_x                                   0xFA28C0
#define pinstCGuildMgmtWnd_x                                       0xFA2970
#define pinstCharacterCreation_x                                   0xED4198
#define pinstCHelpWnd_x                                            0xED41D8
#define pinstCHeritageSelectionWnd_x                               0xED4150
#define pinstCHotButtonWnd_x                                       0xFA4AC8
#define pinstCHotButtonWnd1_x                                      0xFA4AC8
#define pinstCHotButtonWnd2_x                                      0xFA4ACC
#define pinstCHotButtonWnd3_x                                      0xFA4AD0
#define pinstCHotButtonWnd4_x                                      0xFA4AD4
#define pinstCIconSelectionWnd_x                                   0xED4118
#define pinstCInspectWnd_x                                         0xED4110
#define pinstCInventoryWnd_x                                       0xED41D4
#define pinstCInvSlotMgr_x                                         0xED4498
#define pinstCItemDisplayManager_x                                 0xFA5020
#define pinstCItemExpTransferWnd_x                                 0xFA5154
#define pinstCItemOverflowWnd_x                                    0xED40D0
#define pinstCJournalCatWnd_x                                      0xED44AC
//these are the same should probably rename to pinstCJournalNPCWnd at some point
#define pinstCJournalNPCWnd_x                                      0xED44A4
#define pinstCJournalTextWnd_x                                     0xED44A4
#define pinstCKeyRingWnd_x                                         0xED41E4
#define pinstCLargeDialogWnd_x                                     0xFA7298
#define pinstCLayoutCopyWnd_x                                      0xFA54A0
#define pinstCLFGuildWnd_x                                         0xFA5550
#define pinstCLoadskinWnd_x                                        0xED4484
#define pinstCLootFiltersCopyWnd_x                                 0xED3538
#define pinstCLootFiltersWnd_x                                     0xED44B0
#define pinstCLootSettingsWnd_x                                    0xED44B4
#define pinstCLootWnd_x                                            0xED4214
#define pinstCMailAddressBookWnd_x                                 0xED4140
#define pinstCMailCompositionWnd_x                                 0xED413C
#define pinstCMailIgnoreListWnd_x                                  0xED4144
#define pinstCMailWnd_x                                            0xED4138
#define pinstCManageLootWnd_x                                      0xED5720
#define pinstCMapToolbarWnd_x                                      0xED40F4
#define pinstCMapViewWnd_x                                         0xED40EC
#define pinstCMarketplaceWnd_x                                     0xED40D4
#define pinstCMerchantWnd_x                                        0xED40CC
#define pinstCMIZoneSelectWnd_x                                    0xFA5D88
#define pinstCMusicPlayerWnd_x                                     0xED447C
#define pinstCNameChangeMercWnd_x                                  0xED41CC
#define pinstCNameChangePetWnd_x                                   0xED41C8
#define pinstCNameChangeWnd_x                                      0xED4128
#define pinstCNoteWnd_x                                            0xED41D0
#define pinstCObjectPreviewWnd_x                                   0xED4134
#define pinstCOptionsWnd_x                                         0xED4160
#define pinstCPetInfoWnd_x                                         0xED4418
#define pinstCPetitionQWnd_x                                       0xED4184
#define pinstCPlayerNotesWnd_x                                     0xED4474
#define pinstCPlayerWnd_x                                          0xED44CC
#define pinstCPopupWndManager_x                                    0xFA6618
#define pinstCProgressionSelectionWnd_x                            0xFA66C8
#define pinstCPurchaseGroupWnd_x                                   0xED40E0
#define pinstCPurchaseWnd_x                                        0xED40DC
#define pinstCPvPLeaderboardWnd_x                                  0xFA6778
#define pinstCPvPStatsWnd_x                                        0xFA6828
#define pinstCQuantityWnd_x                                        0xED41FC
#define pinstCRaceChangeWnd_x                                      0xED412C
#define pinstCRaidOptionsWnd_x                                     0xED41AC
#define pinstCRaidWnd_x                                            0xED41B8
#define pinstCRealEstateItemsWnd_x                                 0xED4158
#define pinstCRealEstateLayoutDetailsWnd_x                         0xED4194
#define pinstCRealEstateManageWnd_x                                0xED4180
#define pinstCRealEstateNeighborhoodWnd_x                          0xED4188
#define pinstCRealEstatePlotSearchWnd_x                            0xED418C
#define pinstCRealEstatePurchaseWnd_x                              0xED4190
#define pinstCRespawnWnd_x                                         0xED4470
#define pinstCRewardSelectionWnd_x                                 0xFA6F70
#define pinstCSelectorWnd_x                                        0xED40E4
#define pinstCSendMoneyWnd_x                                       0xED40F8
#define pinstCServerListWnd_x                                      0xED4448
#define pinstCSkillsSelectWnd_x                                    0xED4430
#define pinstCSkillsWnd_x                                          0xED4428
#define pinstCSocialEditWnd_x                                      0xED4114
#define pinstCSocialWnd_x                                          0xED44A0
#define pinstCSpellBookWnd_x                                       0xED41C4
#define pinstCStoryWnd_x                                           0xED44B8
#define pinstCTargetOfTargetWnd_x                                  0xFA85D0
#define pinstCTargetWnd_x                                          0xED410C
#define pinstCTaskOverlayWnd_x                                     0xED44C0
#define pinstCTaskSelectWnd_x                                      0xFA8728
#define pinstCTaskManager_x                                        0xC5D268
#define pinstCTaskTemplateSelectWnd_x                              0xFA87D8
#define pinstCTaskWnd_x                                            0xFA8888
#define pinstCTextEntryWnd_x                                       0xED4434
#define pinstCTimeLeftWnd_x                                        0xED4178
#define pinstCTipWndCONTEXT_x                                      0xFA8A8C
#define pinstCTipWndOFDAY_x                                        0xFA8A88
#define pinstCTitleWnd_x                                           0xFA8B38
#define pinstCTrackingWnd_x                                        0xED4100
#define pinstCTradeskillWnd_x                                      0xFA8CA0
#define pinstCTradeWnd_x                                           0xED40D8
#define pinstCTrainWnd_x                                           0xED441C
#define pinstCTributeBenefitWnd_x                                  0xFA8EA0
#define pinstCTributeMasterWnd_x                                   0xFA8F50
#define pinstCTributeTrophyWnd_x                                   0xFA9000
#define pinstCVideoModesWnd_x                                      0xED4124
#define pinstCVoiceMacroWnd_x                                      0xF924E0
#define pinstCVoteResultsWnd_x                                     0xED41C0
#define pinstCVoteWnd_x                                            0xED41BC
#define pinstCZoneGuideWnd_x                                       0xED41EC
#define pinstCZonePathWnd_x                                        0xED4204

#define pinstEQSuiteTextureLoader_x                                0xEA1D00
#define pinstItemIconCache_x                                       0xFA1F18
#define pinstLootFiltersManager_x                                  0xED35E8
#define pinstRewardSelectionWnd_x                                  0xFA6F70

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5DD630
//it has no refs but we can possibly call it still 
#define __CastRay2_x                                               0x5DD8C0
#define __ConvertItemTags_x                                        0x5FA910
#define __CleanItemTags_x                                          0x47DA80
#define __DoesFileExist_x                                          0x9487E0
#define __EQGetTime_x                                              0x9454C0
#define __ExecuteCmd_x                                             0x5D5B00
#define __FixHeading_x                                             0x9E1DA0
#define __FlushDxKeyboard_x                                        0x6D9BD0
#define __GameLoop_x                                               0x6DD4D0
#define __get_bearing_x                                            0x5DD1D0
#define __get_melee_range_x                                        0x5DDB00
#define __GetAnimationCache_x                                      0x74C0B0
#define __GetGaugeValueFromEQ_x                                    0x851F90
#define __GetLabelFromEQ_x                                         0x853AD0
#define __GetXTargetType_x                                         0x9E4110
#define __HandleMouseWheel_x                                       0x6DE960
#define __HeadingDiff_x                                            0x9E1E00
#define __HelpPath_x                                               0xF8DCFC
//#define __LoadFrontEnd_x                                           0x6DA320
#define __LoadFrontEnd_x                                           0x6DA3B0
#define __NewUIINI_x                                               0x851C60
#define __ProcessGameEvents_x                                      0x643780
#define __ProcessMouseEvent_x                                      0x642E80
#define __SaveColors_x                                             0x571070
#define __STMLToText_x                                             0x97FA50
#define __ToggleKeyRingItem_x                                      0x52A820
#define CMemoryMappedFile__SetFile_x                               0xAD2570
#define CrashDetected_x                                            0x6DC0E0
#define DrawNetStatus_x                                            0x672C60
#define Expansion_HoT_x                                            0xDA30E0
#define Teleport_Table_Size_x                                      0xF884E0
#define Teleport_Table_x                                           0xF860B8
#define Util__FastTime_x                                           0x945080
#define __CopyLayout_x                                             0x65F950
#define __WndProc_x                                                0x6DC5E0
#define __ProcessKeyboardEvent_x                                   0x6DBB20

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4919C0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x49B190
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x49B010
#define CAdvancedLootWnd__AddPlayerToList_x                        0x4956F0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x494930

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x57A050
#define AltAdvManager__IsAbilityReady_x                            0x578C40
#define AltAdvManager__GetAAById_x                                 0x578FE0
#define AltAdvManager__CanTrainAbility_x                           0x579050
#define AltAdvManager__CanSeeAbility_x                             0x5793E0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4D1210
#define CharacterZoneClient__HasSkill_x                            0x4DC980
#define CharacterZoneClient__MakeMeVisible_x                       0x4DE0C0
#define CharacterZoneClient__IsStackBlocked_x                      0x4C8630
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4C0DF0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4E0FA0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4E10A0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4E11A0
#define CharacterZoneClient__FindAffectSlot_x                      0x4CA870
#define CharacterZoneClient__BardCastBard_x                        0x4CD890
#define CharacterZoneClient__GetMaxEffects_x                       0x4C4D30
#define CharacterZoneClient__GetEffect_x                           0x4C0D30
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4CBE80
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4CBF30
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4CBFD0
#define CharacterZoneClient__CalcAffectChange_x                    0x4CC190
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4CC370
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B8610
#define CharacterZoneClient__FindItemByGuid_x                      0x4DF260
#define CharacterZoneClient__FindItemByRecord_x                    0x4DEBB0//check args

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x7075F0
#define CBankWnd__WndNotification_x                                0x707390

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x716630

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x97CFF0
#define CButtonWnd__CButtonWnd_x                                   0x97B950

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x739850
#define CChatManager__InitContextMenu_x                            0x732720
#define CChatManager__FreeChatWindow_x                             0x738410
//inlined since jan 25 2021 test exe see 4EFED5
//#define CChatManager__GetLockedActiveChatWindow_x                  0x0
#define CChatManager__SetLockedActiveChatWindow_x                  0x739530
#define CChatManager__CreateChatWindow_x                           0x738A40

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4F2010

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x992E00
#define CContextMenu__dCContextMenu_x                              0x993040
#define CContextMenu__AddMenuItem_x                                0x993050
#define CContextMenu__RemoveMenuItem_x                             0x993360
#define CContextMenu__RemoveAllMenuItems_x                         0x993380
#define CContextMenu__CheckMenuItem_x                              0x9933E0
#define CContextMenu__SetMenuItem_x                                0x993280
#define CContextMenu__AddSeparator_x                               0x9931E0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x993970
#define CContextMenuManager__RemoveMenu_x                          0x9939E0
#define CContextMenuManager__PopupMenu_x                           0x993AA0
#define CContextMenuManager__Flush_x                               0x993910
#define CContextMenuManager__GetMenu_x                             0x49D4D0
#define CContextMenuManager__CreateDefaultMenu_x                   0x7460A0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x91FBE0
#define CChatService__GetFriendName_x                              0x91FBF0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x73A1B0
#define CChatWindow__Clear_x                                       0x73B610
#define CChatWindow__WndNotification_x                             0x73BDA0
#define CChatWindow__AddHistory_x                                  0x73AE70

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x98FEF0
#define CComboWnd__Draw_x                                          0x98F380
#define CComboWnd__GetCurChoice_x                                  0x98FCC0
#define CComboWnd__GetListRect_x                                   0x98F830
#define CComboWnd__GetTextRect_x                                   0x98FF60
#define CComboWnd__InsertChoice_x                                  0x98F9C0
#define CComboWnd__SetColors_x                                     0x98F990
#define CComboWnd__SetChoice_x                                     0x98FCA0
#define CComboWnd__GetItemCount_x                                  0x98FCD0
#define CComboWnd__GetCurChoiceText_x                              0x98FD00
#define CComboWnd__GetChoiceText_x                                 0x98FCE0
#define CComboWnd__InsertChoiceAtIndex_x                           0x98FA60

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x743720
#define CContainerWnd__vftable_x                                   0xB4F104
#define CContainerWnd__SetContainer_x                              0x744F60

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x56BC40
#define CDisplay__PreZoneMainUI_x                                  0x56BC50
#define CDisplay__CleanGameUI_x                                    0x570E50
#define CDisplay__GetClickedActor_x                                0x563B20
#define CDisplay__GetUserDefinedColor_x                            0x55B890
//well they inlined it in jan 25 2021 test but the function is still left in exe so for now we can probably just call it...
#define CDisplay__GetWorldFilePath_x                               0x565630
#define CDisplay__is3dON_x                                         0x5603B0
#define CDisplay__ReloadUI_x                                       0x56AF60
#define CDisplay__WriteTextHD2_x                                   0x5601A0
#define CDisplay__TrueDistance_x                                   0x567500
#define CDisplay__SetViewActor_x                                   0x563440
#define CDisplay__GetFloorHeight_x                                 0x560470
#define CDisplay__SetRenderWindow_x                                0x55EDF0
#define CDisplay__ToggleScreenshotMode_x                           0x562F10

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x9B55B0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x996950
#define CEditWnd__EnsureCaretVisible_x                             0x998CC0
#define CEditWnd__GetCaretPt_x                                     0x997B30
#define CEditWnd__GetCharIndexPt_x                                 0x9978E0
#define CEditWnd__GetDisplayString_x                               0x997780
#define CEditWnd__GetHorzOffset_x                                  0x995EA0
#define CEditWnd__GetLineForPrintableChar_x                        0x998BD0
#define CEditWnd__GetSelStartPt_x                                  0x997B90
#define CEditWnd__GetSTMLSafeText_x                                0x997590
#define CEditWnd__PointFromPrintableChar_x                         0x998820
#define CEditWnd__SelectableCharFromPoint_x                        0x998980
#define CEditWnd__SetEditable_x                                    0x997C60
#define CEditWnd__SetWindowTextA_x                                 0x9972E0
#define CEditWnd__ReplaceSelection_x                               0x9983E0
#define CEditWnd__ReplaceSelection1_x                              0x998360

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x62F110
#define CEverQuest__ClickedPlayer_x                                0x620700
#define CEverQuest__CreateTargetIndicator_x                        0x6406F0
#define CEverQuest__DeleteTargetIndicator_x                        0x640780
#define CEverQuest__DoTellWindow_x                                 0x4F2110
#define CEverQuest__OutputTextToLog_x                              0x4F23E0
#define CEverQuest__DropHeldItemOnGround_x                         0x6156F0
#define CEverQuest__dsp_chat_x                                     0x4F2770
#define CEverQuest__trimName_x                                     0x63BEF0
#define CEverQuest__Emote_x                                        0x62F7D0
#define CEverQuest__EnterZone_x                                    0x629510
#define CEverQuest__GetBodyTypeDesc_x                              0x634C30
#define CEverQuest__GetClassDesc_x                                 0x635270
#define CEverQuest__GetClassThreeLetterCode_x                      0x635870
#define CEverQuest__GetDeityDesc_x                                 0x63EEA0
#define CEverQuest__GetLangDesc_x                                  0x635A30
#define CEverQuest__GetRaceDesc_x                                  0x635250
#define CEverQuest__InterpretCmd_x                                 0x63F510
#define CEverQuest__LeftClickedOnPlayer_x                          0x619C70
#define CEverQuest__LMouseUp_x                                     0x617CA0
#define CEverQuest__RightClickedOnPlayer_x                         0x61A860
#define CEverQuest__RMouseUp_x                                     0x618F60
#define CEverQuest__SetGameState_x                                 0x615470
#define CEverQuest__UPCNotificationFlush_x                         0x63BE10
#define CEverQuest__IssuePetCommand_x                              0x637030
#define CEverQuest__ReportSuccessfulHit_x                          0x6310E0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x757020
#define CGaugeWnd__CalcLinesFillRect_x                             0x757080
#define CGaugeWnd__Draw_x                                          0x756630

// CGuild
#define CGuild__FindMemberByName_x                                 0x4B4430
#define CGuild__GetGuildName_x                                     0x4B2C50
#define CGuild__GetGuildIndex_x                                    0x4B3370

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x774570

//CHotButton
#define CHotButton__SetCheck_x                                     0x653D50
#define CHotButton__SetButtonSize_x                                0x654110

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x781580
#define CInvSlotMgr__MoveItem_x                                    0x780120//check args
#define CInvSlotMgr__SelectSlot_x                                  0x781640

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x77E970
#define CInvSlot__SliderComplete_x                                 0x77BE60
#define CInvSlot__GetItemBase_x                                    0x77B720
#define CInvSlot__UpdateItem_x                                     0x77B910

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x783280
#define CInvSlotWnd__CInvSlotWnd_x                                 0x782460
#define CInvSlotWnd__HandleLButtonUp_x                             0x782E00

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x84C270
#define CItemDisplayWnd__UpdateStrings_x                           0x792400
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x78BE30
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x78C390
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x792A00
#define CItemDisplayWnd__AboutToShow_x                             0x792060
#define CItemDisplayWnd__WndNotification_x                         0x793F80
#define CItemDisplayWnd__RequestConvertItem_x                      0x793830
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x791080
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x791E80

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x881400

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x7988C0

// CLabel 
#define CLabel__Draw_x                                             0x79EFE0

// CListWnd
#define CListWnd__CListWnd_x                                       0x963AB0
#define CListWnd__dCListWnd_x                                      0x963DB0
#define CListWnd__AddColumn_x                                      0x968800
#define CListWnd__AddColumn1_x                                     0x968920
#define CListWnd__AddLine_x                                        0x968C90
#define CListWnd__AddString_x                                      0x968A90
#define CListWnd__CalculateFirstVisibleLine_x                      0x9685B0
#define CListWnd__CalculateVSBRange_x                              0x968390
#define CListWnd__ClearSel_x                                       0x969580
#define CListWnd__ClearAllSel_x                                    0x9695D0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x96A070
#define CListWnd__Compare_x                                        0x967CC0
#define CListWnd__Draw_x                                           0x963F70
#define CListWnd__DrawColumnSeparators_x                           0x966AB0
#define CListWnd__DrawHeader_x                                     0x966F10
#define CListWnd__DrawItem_x                                       0x967560
#define CListWnd__DrawLine_x                                       0x966C20
#define CListWnd__DrawSeparator_x                                  0x966B50
#define CListWnd__EnableLine_x                                     0x966370
#define CListWnd__EnsureVisible_x                                  0x969FA0
//no references in jan 25 2021 test exe we can probably still call it
#define CListWnd__ExtendSel_x                                      0x9694C0
#define CListWnd__GetColumnTooltip_x                               0x965EF0
#define CListWnd__GetColumnMinWidth_x                              0x965F60
#define CListWnd__GetColumnWidth_x                                 0x965E70
#define CListWnd__GetCurSel_x                                      0x965810
#define CListWnd__GetItemAtPoint_x                                 0x9665E0
//no references in jan 25 2021 test exe we can probably still call it
#define CListWnd__GetItemAtPoint1_x                                0x966650
#define CListWnd__GetItemData_x                                    0x965890
#define CListWnd__GetItemHeight_x                                  0x965C40
#define CListWnd__GetItemIcon_x                                    0x965A10
#define CListWnd__GetItemRect_x                                    0x966460
#define CListWnd__GetItemText_x                                    0x9658D0
#define CListWnd__GetSelList_x                                     0x969620
#define CListWnd__GetSeparatorRect_x                               0x9668C0
#define CListWnd__InsertLine_x                                     0x9690F0
#define CListWnd__RemoveLine_x                                     0x969310
#define CListWnd__SetColors_x                                      0x968360
#define CListWnd__SetColumnJustification_x                         0x968090
#define CListWnd__SetColumnLabel_x                                 0x968A30
#define CListWnd__SetColumnWidth_x                                 0x967FA0
#define CListWnd__SetCurSel_x                                      0x969410
#define CListWnd__SetItemColor_x                                   0x969C60
#define CListWnd__SetItemData_x                                    0x969C20
#define CListWnd__SetItemText_x                                    0x969840
#define CListWnd__ShiftColumnSeparator_x                           0x968150
#define CListWnd__Sort_x                                           0x967E50
#define CListWnd__ToggleSel_x                                      0x969440
#define CListWnd__SetColumnsSizable_x                              0x9681F0
#define CListWnd__SetItemWnd_x                                     0x969AE0
#define CListWnd__GetItemWnd_x                                     0x965A60
#define CListWnd__SetItemIcon_x                                    0x9698C0
#define CListWnd__CalculateCustomWindowPositions_x                 0x9686B0
#define CListWnd__SetVScrollPos_x                                  0x967F80

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7B63F0
#define CMapViewWnd__GetWorldCoordinates_x                         0x7B4A10
#define CMapViewWnd__HandleLButtonDown_x                           0x7B18A0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7D95B0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7D9F10
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7DA550
#define CMerchantWnd__SelectRecoverySlot_x                         0x7DD740
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7D8050
#define CMerchantWnd__SelectBuySellSlot_x                          0x7E3890
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7D9210

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8ECF50
#define CPacketScrambler__hton_x                                   0x8ECF40

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x9860B0
#define CSidlManager__FindScreenPieceTemplate_x                    0x986480
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9862B0
#define CSidlManager__CreateLabel_x                                0x841FB0
#define CSidlManager__CreateXWndFromTemplate_x                     0x989930
#define CSidlManager__CreateXWndFromTemplate1_x                    0x989BC0
#define CSidlManager__CreateXWnd_x                                 0x841A30
//inlined since jan 25 2021 test but they left the function intact
#define CSidlManager__CreateHotButtonWnd_x                         0x8423E0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x981E00
#define CSidlScreenWnd__CalculateVSBRange_x                        0x981D00
#define CSidlScreenWnd__ConvertToRes_x                             0x9AF800
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x981680
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x981370
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x981440
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x981510
#define CSidlScreenWnd__DrawSidlPiece_x                            0x9826A0
#define CSidlScreenWnd__EnableIniStorage_x                         0x982B80
#define CSidlScreenWnd__GetSidlPiece_x                             0x982890
#define CSidlScreenWnd__Init1_x                                    0x980E20
#define CSidlScreenWnd__LoadIniInfo_x                              0x982BD0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9837A0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x980220
#define CSidlScreenWnd__StoreIniInfo_x                             0x983320
#define CSidlScreenWnd__StoreIniVis_x                              0x983690
#define CSidlScreenWnd__WndNotification_x                          0x982570
#define CSidlScreenWnd__GetChildItem_x                             0x982B00
#define CSidlScreenWnd__HandleLButtonUp_x                          0x971120
#define CSidlScreenWnd__m_layoutCopy_x                             0x1613868

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6C1600
#define CSkillMgr__GetSkillCap_x                                   0x6C17D0
#define CSkillMgr__GetNameToken_x                                  0x6C0E40
#define CSkillMgr__IsActivatedSkill_x                              0x6C0F30
#define CSkillMgr__IsCombatSkill_x                                 0x6C0EA0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x994A80
#define CSliderWnd__SetValue_x                                     0x9948B0
#define CSliderWnd__SetNumTicks_x                                  0x994910

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x848C50

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x99DEF0
#define CStmlWnd__ParseSTML_x                                      0x99F090
#define CStmlWnd__CalculateHSBRange_x                              0x99EE50
#define CStmlWnd__CalculateVSBRange_x                              0x99EDD0
#define CStmlWnd__CanBreakAtCharacter_x                            0x9A3CC0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x9A4960
#define CStmlWnd__ForceParseNow_x                                  0x99E460
#define CStmlWnd__GetNextTagPiece_x                                0x9A3C20
//cant find its inlined in jan 25 2021 test
//#define CStmlWnd__GetSTMLText_x                                    0x0
#define CStmlWnd__GetVisibleText_x                                 0x99E480
#define CStmlWnd__InitializeWindowVariables_x                      0x9A47B0
#define CStmlWnd__MakeStmlColorTag_x                               0x99D590
#define CStmlWnd__MakeWndNotificationTag_x                         0x99D600
#define CStmlWnd__SetSTMLText_x                                    0x99C370
#define CStmlWnd__StripFirstSTMLLines_x                            0x9A5B80
#define CStmlWnd__UpdateHistoryString_x                            0x9A4B60

// CTabWnd 
#define CTabWnd__Draw_x                                            0x99B2C0
#define CTabWnd__DrawCurrentPage_x                                 0x99BC50
#define CTabWnd__DrawTab_x                                         0x99B840
#define CTabWnd__GetCurrentPage_x                                  0x99AA20
#define CTabWnd__GetPageInnerRect_x                                0x99AC50
#define CTabWnd__GetTabInnerRect_x                                 0x99AB90
#define CTabWnd__GetTabRect_x                                      0x99AA50
#define CTabWnd__InsertPage_x                                      0x99AE40
#define CTabWnd__RemovePage_x                                      0x99AF90
#define CTabWnd__SetPage_x                                         0x99ACD0
//inlined but we can probably call it jan 25 2021
#define CTabWnd__SetPageRect_x                                     0x99B1C0
#define CTabWnd__UpdatePage_x                                      0x99B630
#define CTabWnd__GetPageFromTabIndex_x                             0x99B780
#define CTabWnd__GetCurrentTabIndex_x                              0x99AA10

// CPageWnd
//inlined in Jan 25 2021 test
//#define CPageWnd__GetTabText_x                                     0x479340
#define CPageWnd__SetTabText_x                                     0x99A3B0
#define CPageWnd__FlashTab_x                                       0x99A410

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4AC4A0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x96D5F0
#define CTextureFont__GetTextExtent_x                              0x96D8F0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9AC2B0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x959560

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x544240
#define CXStr__CXStr1_x                                            0x482750
#define CXStr__CXStr3_x                                            0x941410
#define CXStr__dCXStr_x                                            0x478F60
#define CXStr__operator_equal_x                                    0x941650
#define CXStr__operator_equal1_x                                   0x941690
#define CXStr__operator_plus_equal1_x                              0x9420F0
#define CXStr__SetString_x                                         0x943F90
#define CXStr__operator_char_p_x                                   0x941B40
#define CXStr__GetChar_x                                           0x9438F0
#define CXStr__Delete_x                                            0x9431C0
#define CXStr__GetUnicode_x                                        0x943960
//inlined in jan 25 2021 test
//#define CXStr__GetLength_x                                         0x0
//inlined in jan 25 2021 test
//#define CXStr__Mid_x                                               0x0
#define CXStr__Insert_x                                            0x9439C0
#define CXStr__FindNext_x                                          0x943610
#define CXStr__Copy_x                                              0x942FD0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x992A60//we dont call it but better check anyway changed in jan 25 2021
#define CXWnd__BringToTop_x                                        0x974B60
//inlined in jan 25 2021
//#define CXWnd__Center_x                                            0x0
#define CXWnd__ClrFocus_x                                          0x9744F0
#define CXWnd__Destroy_x                                           0x974590
#define CXWnd__DoAllDrawing_x                                      0x9707A0
//inlined in jan 25 2021 we can probably still call it
#define CXWnd__DrawChildren_x                                      0x970770
#define CXWnd__DrawColoredRect_x                                   0x970D20
#define CXWnd__DrawTooltip_x                                       0x96ED30
#define CXWnd__DrawTooltipAtPoint_x                                0x96EDF0
#define CXWnd__GetBorderFrame_x                                    0x96DBD0
#define CXWnd__GetChildWndAt_x                                     0x974C00
#define CXWnd__GetClientClipRect_x                                 0x972D50
#define CXWnd__GetScreenClipRect_x                                 0x972E20
#define CXWnd__GetScreenRect_x                                     0x972FE0
#define CXWnd__GetRelativeRect_x                                   0x9730A0
#define CXWnd__GetTooltipRect_x                                    0x970D70
#define CXWnd__GetWindowTextA_x                                    0x4F1FB0
#define CXWnd__IsActive_x                                          0x9714A0
#define CXWnd__IsDescendantOf_x                                    0x973A50
#define CXWnd__IsReallyVisible_x                                   0x973A80
#define CXWnd__IsType_x                                            0x975380
#define CXWnd__Move_x                                              0x973AF0
#define CXWnd__Move1_x                                             0x973BF0
#define CXWnd__ProcessTransition_x                                 0x974670
#define CXWnd__Refade_x                                            0x973EC0
#define CXWnd__Resize_x                                            0x974150
#define CXWnd__Right_x                                             0x974950
#define CXWnd__SetFocus_x                                          0x9744B0
#define CXWnd__SetFont_x                                           0x974520
#define CXWnd__SetKeyTooltip_x                                     0x975140
#define CXWnd__SetMouseOver_x                                      0x971E10
#define CXWnd__StartFade_x                                         0x973930
#define CXWnd__GetChildItem_x                                      0x974D80
#define CXWnd__SetParent_x                                         0x973770
#define CXWnd__Minimize_x                                          0x9741B0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x9B0850

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x977B70
#define CXWndManager__DrawWindows_x                                0x977CC0
#define CXWndManager__GetKeyboardFlags_x                           0x97A570
#define CXWndManager__HandleKeyboardMsg_x                          0x97A150
#define CXWndManager__RemoveWnd_x                                  0x97A840
#define CXWndManager__RemovePendingDeletionWnd_x                   0x97AD00

// CDBStr
#define CDBStr__GetString_x                                        0x55A3C0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4C56B0
#define EQ_Character__Cur_HP_x                                     0x4D95F0
#define EQ_Character__Cur_Mana_x                                   0x4E16D0
#define EQ_Character__GetCastingTimeModifier_x                     0x4C8D20
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B8220
#define EQ_Character__GetFocusRangeModifier_x                      0x4B8370
#define EQ_Character__GetHPRegen_x                                 0x4E80B0
#define EQ_Character__GetEnduranceRegen_x                          0x4E8670
#define EQ_Character__GetManaRegen_x                               0x4E8AB0
#define EQ_Character__Max_Endurance_x                              0x6827B0
#define EQ_Character__Max_HP_x                                     0x4D9420
#define EQ_Character__Max_Mana_x                                   0x6825A0
#define EQ_Character__doCombatAbility_x                            0x6850F0
#define EQ_Character__UseSkill_x                                   0x4EAAD0
#define EQ_Character__GetConLevel_x                                0x67A8C0
#define EQ_Character__IsExpansionFlag_x                            0x5D4350
#define EQ_Character__TotalEffect_x                                0x4CD1A0
#define EQ_Character__GetPCSpellAffect_x                           0x4C9B50
#define EQ_Character__SpellDuration_x                              0x4C9590
#define EQ_Character__MySpellDuration_x                            0x4B68E0
#define EQ_Character__GetAdjustedSkill_x                           0x4DC740
#define EQ_Character__GetBaseSkill_x                               0x4DD6E0
#define EQ_Character__CanUseItem_x                                 0x4E1A00

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x90D040

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x69A210

//PcClient
#define PcClient__vftable_x                                        0xB42C5C
#define PcClient__PcClient_x                                       0x677B20

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BFCC0
#define CCharacterListWnd__EnterWorld_x                            0x4BF690
#define CCharacterListWnd__Quit_x                                  0x4BF3B0
#define CCharacterListWnd__UpdateList_x                            0x4BF880

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x659F70
#define EQ_Item__CreateItemTagString_x                             0x8E5EE0
#define EQ_Item__IsStackable_x                                     0x8EAF70
#define EQ_Item__GetImageNum_x                                     0x8E7C00
#define EQ_Item__CreateItemClient_x                                0x658EE0
#define EQ_Item__GetItemValue_x                                    0x8E8EE0
#define EQ_Item__ValueSellMerchant_x                               0x8ECC80
#define EQ_Item__IsKeyRingItem_x                                   0x8EA740
#define EQ_Item__CanGoInBag_x                                      0x65A090
#define EQ_Item__IsEmpty_x                                         0x8EA200
#define EQ_Item__GetMaxItemCount_x                                 0x8E9300
#define EQ_Item__GetHeldItem_x                                     0x8E7AC0
#define EQ_Item__CanGemFitInSlot_x                                 0x8E56C0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x57AE50
#define EQ_LoadingS__Array_x                                       0xD8FD00

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x6832A0
#define EQ_PC__GetAlternateAbilityId_x                             0x8F6BE0
#define EQ_PC__GetCombatAbility_x                                  0x8F7160
#define EQ_PC__GetCombatAbilityTimer_x                             0x8F71D0
#define EQ_PC__GetItemRecastTimer_x                                0x6856F0
#define EQ_PC__HasLoreItem_x                                       0x67B270
#define EQ_PC__AlertInventoryChanged_x                             0x67A170
#define EQ_PC__GetPcZoneClient_x                                   0x6AA8E0
#define EQ_PC__RemoveMyAffect_x                                    0x688C10
#define EQ_PC__GetKeyRingItems_x                                   0x8F7C60
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8F77C0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8F7DB0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5DA6E0
#define EQItemList__add_object_x                                   0x60A590
#define EQItemList__add_item_x                                     0x5DACC0
#define EQItemList__delete_item_x                                  0x5DAD10
#define EQItemList__FreeItemList_x                                 0x5DAC20

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x556500

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x69BC40
#define EQPlayer__dEQPlayer_x                                      0x68E4E0
#define EQPlayer__DoAttack_x                                       0x6A4640
#define EQPlayer__EQPlayer_x                                       0x68ED30
#define EQPlayer__SetNameSpriteState_x                             0x693300
#define EQPlayer__SetNameSpriteTint_x                              0x6941C0
#define PlayerBase__HasProperty_j_x                                0x9E0170
#define EQPlayer__IsTargetable_x                                   0x9E06D0
#define EQPlayer__CanSee_x                                         0x9E04C0
#define EQPlayer__CanSee1_x                                        0x9E0590
#define PlayerBase__GetVisibilityLineSegment_x                     0x9E0230

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x6A83D0
#define PlayerZoneClient__GetLevel_x                               0x6AA920
#define PlayerZoneClient__IsValidTeleport_x                        0x60BA30
#define PlayerZoneClient__LegalPlayerRace_x                        0x572E30

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x69EDF0
#define EQPlayerManager__GetSpawnByName_x                          0x69EEA0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x69EF30

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x65D910
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x65D9E0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x65DA20
#define KeypressHandler__ClearCommandStateArray_x                  0x65EEE0
#define KeypressHandler__HandleKeyDown_x                           0x65EF00
#define KeypressHandler__HandleKeyUp_x                             0x65EFA0
#define KeypressHandler__SaveKeymapping_x                          0x65F550

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7B20A0
#define MapViewMap__SaveEx_x                                       0x7B55DF
#define MapViewMap__SetZoom_x                                      0x7BB210

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x90AED0

// StringTable 
#define StringTable__getString_x                                   0x905DB0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x688860
#define PcZoneClient__RemovePetEffect_x                            0x688EC0
#define PcZoneClient__HasAlternateAbility_x                        0x682400
#define PcZoneClient__GetCurrentMod_x                              0x4EE250
#define PcZoneClient__GetModCap_x                                  0x4EE150
#define PcZoneClient__CanEquipItem_x                               0x682AB0
#define PcZoneClient__GetItemByID_x                                0x685BC0
#define PcZoneClient__GetItemByItemClass_x                         0x685D00
#define PcZoneClient__RemoveBuffEffect_x                           0x688F70
#define PcZoneClient__BandolierSwap_x                              0x683860
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x685690

//Doors
#define EQSwitch__UseSwitch_x                                      0x610580

//IconCache
#define IconCache__GetIcon_x                                       0x74BA50

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x742630
#define CContainerMgr__CloseContainer_x                            0x742910
#define CContainerMgr__OpenExperimentContainer_x                   0x743470

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x811500

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x6524B0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x7A72F0
#define CLootWnd__RequestLootSlot_x                                0x7A6520

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x5A52F0
#define EQ_Spell__SpellAffects_x                                   0x5A57F0
#define EQ_Spell__SpellAffectBase_x                                0x5A5510
//inlined in jan 25 2021 test
//#define EQ_Spell__IsStackable_x                                    0x0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4D0BA0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4D0B50
#define EQ_Spell__IsSPAStacking_x                                  0x5A6700
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x5A5B50
//inlined in jan 25 2021 test
//#define EQ_Spell__IsNoRemove_x                                     0x0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x5A6710
#define EQ_Spell__IsLullSpell_x                                    0x5A5F40
#define __IsResEffectSpell_x                                       0x4D0350

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4B11F0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x915950

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x85DEA0
#define CTargetWnd__WndNotification_x                              0x85D630
#define CTargetWnd__RefreshTargetBuffs_x                           0x85D990
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x85C430

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x862A30
#define CTaskWnd__ConfirmAbandonTask_x                             0x865AE0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x5540C0
#define CTaskManager__HandleMessage_x                              0x551F80
#define CTaskManager__GetTaskStatus_x                              0x554170
#define CTaskManager__GetElementDescription_x                      0x5541F0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x59FF20
#define EqSoundManager__PlayScriptMp3_x                            0x5A0120
#define EqSoundManager__SoundAssistPlay_x                          0x6C5AB0
#define EqSoundManager__WaveInstancePlay_x                         0x6C4FA0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x543EF0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x999830
#define CTextureAnimation__Draw_x                                  0x999A70
#define CTextureAnimation__AddBlankFrame_x                         0x999650

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x995580

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x583420
#define CAltAbilityData__GetMercMaxRank_x                          0x5833B0
#define CAltAbilityData__GetMaxRank_x                              0x5777C0

//CTargetRing
#define CTargetRing__Cast_x                                        0x64FCC0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x658D30
#define CharacterBase__CreateItemGlobalIndex_x                     0x6463F0
//inlined in jan 25 2021 test we can call 4F6AE0 directly i guess
//#define CharacterBase__CreateItemIndex_x                           0x0
//this is a guess testing is needed
#define CharacterBase__GetItemPossession_x                         0x658D10
#define CharacterBase__GetItemByGlobalIndex_x                      0x91D4D0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x91D520
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x7274B0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x727D70
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x727E20

//messages
#define msg_spell_worn_off_x                                       0x5CBC90
#define msg_new_text_x                                             0x5BFA90
#define __msgTokenTextParam_x                                      0x5CE0F0
#define msgTokenText_x                                             0x5CE500

//SpellManager
#define SpellManager__vftable_x                                    0xB2D2FC
#define SpellManager__SpellManager_x                               0x6C96E0
#define Spellmanager__LoadTextSpells_x                             0x6C9FE0
#define SpellManager__GetSpellByGroupAndRank_x                     0x6C98B0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9E49C0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x5D43A0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5D2870
#define ItemGlobalIndex__IsEquippedLocation_x                      0x672A00
#define ItemGlobalIndex__IsValidIndex_x                            0x5D4530

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x916350
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x9166A0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x79F460

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x747310
#define CCursorAttachment__AttachToCursor1_x                       0x747350
#define CCursorAttachment__Deactivate_x                            0x7488E0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x98B170
#define CSidlManagerBase__CreatePageWnd_x                          0x98A960
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x985E30
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x985DC0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9AAE80
#define CEQSuiteTextureLoader__GetTexture_x                        0x9AAB00

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x5241C0
#define CFindItemWnd__WndNotification_x                            0x525070
#define CFindItemWnd__Update_x                                     0x525C50
#define CFindItemWnd__PickupSelectedItem_x                         0x5238D0

//IString
#define IString__Append_x                                          0x513500

//Camera
#define CDisplay__cameraType_x                                     0xED4210
#define EverQuest__Cameras_x                                       0xDA3438

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x52ED50
#define LootFiltersManager__GetItemFilterData_x                    0x52E690
#define LootFiltersManager__RemoveItemLootFilter_x                 0x52E6C0
#define LootFiltersManager__SetItemLootFilter_x                    0x52E8D0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7FE020

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9EA680
#define CResolutionHandler__GetWindowedStyle_x                     0x6BFF50

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x73EFD0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x921850
#define CDistillerInfo__Instance_x                                 0x921790

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x761CB0
#define CGroupWnd__UpdateDisplay_x                                 0x760F00

//ItemBase
#define ItemBase__IsLore_x                                         0x8EA7E0
#define ItemBase__IsLoreEquipped_x                                 0x8EA860

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x60A4F0
#define EQPlacedItemManager__GetItemByGuid_x                       0x60A630
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x60A690

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6B4680
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x6B8FA0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x519CA0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x504A60
#define FactionManagerClient__HandleFactionMessage_x               0x505280
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x505AA0
#define FactionManagerClient__GetMaxFaction_x                      0x505ABF
#define FactionManagerClient__GetMinFaction_x                      0x505A70

//BaseProfile (PCHARINFO2)
//not found in jan 25 2021 test
//#define BaseProfile__GetItemPossession_x                           0x0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x96C280

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49DEF0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x511900

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x5825D0

//CTargetManager
#define CTargetManager__Get_x                                      0x6CD660

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6B4680

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4AC260

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5DABC0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xE40ACC

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6EB060
#define CAAWnd__UpdateSelected_x                                   0x6E7700
#define CAAWnd__Update_x                                           0x6EA390

//CXRect
#define CXRect__operator_and_x                                     0x7570E0

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x47D240

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";

//__eqgraphics_fopen
//Jan 09 2020 EQGraphicsDX9.dll
//IDA Style Sig: E8 ? ? ? ? 83 C4 08 89 45 A0
//#define __eqgraphics_fopen_x                                       0x101473C8
//static PBYTE efPattern = (PBYTE)"\xE8\x00\x00\x00\x00\x83\xC4\x08\x89\x45\xA0";
//static char efMask[] = "x????xxxxxx";
//Jan 25 2021 Test
//E8 ? ? ? ? 8B D8 53
static PBYTE efPattern = (PBYTE)"\xE8\x00\x00\x00\x00\x8B\xD8\x53";
static char efMask[] = "x????xxx";

