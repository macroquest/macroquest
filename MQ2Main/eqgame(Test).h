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
#define __ExpectedVersionDate                                     "Feb 23 2021"
#define __ExpectedVersionTime                                     "11:23:20"
#define __ActualVersionDate_x                                      0xB45EE4
#define __ActualVersionTime_x                                      0xB45ED8
#define __ActualVersionBuild_x                                     0xB360C4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x663B50
#define __MemChecker1_x                                            0x945080
#define __MemChecker2_x                                            0x6DDD20
#define __MemChecker3_x                                            0x6DDC90
#define __MemChecker4_x                                            0x898430
#define __EncryptPad0_x                                            0xE46F40
#define __EncryptPad1_x                                            0xEA1740
#define __EncryptPad2_x                                            0xE56158
#define __EncryptPad3_x                                            0xE55D58
#define __EncryptPad4_x                                            0xE92550
#define __EncryptPad5_x                                            0xF95020
#define __AC1_x                                                    0x853020
#define __AC2_x                                                    0x618A3F
#define __AC3_x                                                    0x61FE21
#define __AC4_x                                                    0x623F90
#define __AC5_x                                                    0x62A84F
#define __AC6_x                                                    0x62EF96
#define __AC7_x                                                    0x6184A0
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
#define __do_loot_x                                                0x5E1590
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
#define __CastRay_x                                                0x5DC850
//it has no refs but we can possibly call it still 
#define __CastRay2_x                                               0x5DCAE0
#define __ConvertItemTags_x                                        0x5F9B50
#define __CleanItemTags_x                                          0x47DA80
#define __DoesFileExist_x                                          0x948010
#define __EQGetTime_x                                              0x944CF0
#define __ExecuteCmd_x                                             0x5D4D10
#define __FixHeading_x                                             0x9E1790
#define __FlushDxKeyboard_x                                        0x6D9020
#define __GameLoop_x                                               0x6DC920
#define __get_bearing_x                                            0x5DC3F0
#define __get_melee_range_x                                        0x5DCD20
#define __GetAnimationCache_x                                      0x74B630
#define __GetGaugeValueFromEQ_x                                    0x851460
#define __GetLabelFromEQ_x                                         0x852FA0
#define __GetXTargetType_x                                         0x9E3B00
#define __HandleMouseWheel_x                                       0x6DDDB0
#define __HeadingDiff_x                                            0x9E17F0
#define __HelpPath_x                                               0xF8DCFC
#define __ExecuteFrontEnd_x                                        0x6D9800
#define __NewUIINI_x                                               0x851130
#define __ProcessGameEvents_x                                      0x642C70
#define __ProcessMouseEvent_x                                      0x642370
#define __SaveColors_x                                             0x5710A0
#define __STMLToText_x                                             0x97F430
#define __ToggleKeyRingItem_x                                      0x52A840
#define CMemoryMappedFile__SetFile_x                               0xAD1F70
#define CrashDetected_x                                            0x6DB530
#define DrawNetStatus_x                                            0x6720C0
#define Expansion_HoT_x                                            0xDA30E0
#define Teleport_Table_Size_x                                      0xF884E0
#define Teleport_Table_x                                           0xF860B8
#define Util__FastTime_x                                           0x9448B0
#define __CopyLayout_x                                             0x65EE40
#define __WndProc_x                                                0x6DBA30
#define __ProcessKeyboardEvent_x                                   0x6DAF70

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4919C0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x49B1B0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x49B030
#define CAdvancedLootWnd__AddPlayerToList_x                        0x495710
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x494950

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x57A0A0
#define AltAdvManager__IsAbilityReady_x                            0x578C90
#define AltAdvManager__GetAAById_x                                 0x579030
#define AltAdvManager__CanTrainAbility_x                           0x5790A0
#define AltAdvManager__CanSeeAbility_x                             0x579430

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4D11F0
#define CharacterZoneClient__HasSkill_x                            0x4DC960
#define CharacterZoneClient__MakeMeVisible_x                       0x4DE0A0
#define CharacterZoneClient__IsStackBlocked_x                      0x4C8600
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4C0DC0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4E0FB0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4E10B0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4E11B0
#define CharacterZoneClient__FindAffectSlot_x                      0x4CA840
#define CharacterZoneClient__BardCastBard_x                        0x4CD850
#define CharacterZoneClient__GetMaxEffects_x                       0x4C4D00
#define CharacterZoneClient__GetEffect_x                           0x4C0D00
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4CBE50
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4CBF00
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4CBFA0
#define CharacterZoneClient__CalcAffectChange_x                    0x4CC160
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4CC340
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B85F0
#define CharacterZoneClient__FindItemByGuid_x                      0x4DF240
#define CharacterZoneClient__FindItemByRecord_x                    0x4DEB90

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x706AD0
#define CBankWnd__WndNotification_x                                0x706870

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x715B20

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x97C9E0
#define CButtonWnd__CButtonWnd_x                                   0x97B370

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x738DB0
#define CChatManager__InitContextMenu_x                            0x731CA0
#define CChatManager__FreeChatWindow_x                             0x737980
#define CChatManager__SetLockedActiveChatWindow_x                  0x738A90
#define CChatManager__CreateChatWindow_x                           0x737FB0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4F2030

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x992810
#define CContextMenu__dCContextMenu_x                              0x992A50
#define CContextMenu__AddMenuItem_x                                0x992A60
#define CContextMenu__RemoveMenuItem_x                             0x992D70
#define CContextMenu__RemoveAllMenuItems_x                         0x992D90
#define CContextMenu__CheckMenuItem_x                              0x992DF0
#define CContextMenu__SetMenuItem_x                                0x992C90
#define CContextMenu__AddSeparator_x                               0x992BF0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x993380
#define CContextMenuManager__RemoveMenu_x                          0x9933F0
#define CContextMenuManager__PopupMenu_x                           0x9934B0
#define CContextMenuManager__Flush_x                               0x993320
#define CContextMenuManager__GetMenu_x                             0x49D4E0
#define CContextMenuManager__CreateDefaultMenu_x                   0x7455E0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x91F410
#define CChatService__GetFriendName_x                              0x91F420

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x739710
#define CChatWindow__Clear_x                                       0x73AB60
#define CChatWindow__WndNotification_x                             0x73B2E0
#define CChatWindow__AddHistory_x                                  0x73A3C0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x98F8E0
#define CComboWnd__Draw_x                                          0x98ED70
#define CComboWnd__GetCurChoice_x                                  0x98F6B0
#define CComboWnd__GetListRect_x                                   0x98F220
#define CComboWnd__GetTextRect_x                                   0x98F950
#define CComboWnd__InsertChoice_x                                  0x98F3B0
#define CComboWnd__SetColors_x                                     0x98F380
#define CComboWnd__SetChoice_x                                     0x98F690
#define CComboWnd__GetItemCount_x                                  0x98F6C0
#define CComboWnd__GetCurChoiceText_x                              0x98F6F0
#define CComboWnd__GetChoiceText_x                                 0x98F6D0
#define CComboWnd__InsertChoiceAtIndex_x                           0x98F450

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x742C80
#define CContainerWnd__vftable_x                                   0xB4F104
#define CContainerWnd__SetContainer_x                              0x7444A0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x56BC70
#define CDisplay__PreZoneMainUI_x                                  0x56BC80
#define CDisplay__CleanGameUI_x                                    0x570E80
#define CDisplay__GetClickedActor_x                                0x563B50
#define CDisplay__GetUserDefinedColor_x                            0x55B8C0
//well they inlined it in jan 25 2021 test but the function is still left in exe so for now we can probably just call it...
#define CDisplay__GetWorldFilePath_x                               0x565660
#define CDisplay__is3dON_x                                         0x5603E0
#define CDisplay__ReloadUI_x                                       0x56AF90
#define CDisplay__WriteTextHD2_x                                   0x5601D0
#define CDisplay__TrueDistance_x                                   0x567530
#define CDisplay__SetViewActor_x                                   0x563470
#define CDisplay__GetFloorHeight_x                                 0x5604A0
#define CDisplay__SetRenderWindow_x                                0x55EE20
#define CDisplay__ToggleScreenshotMode_x                           0x562F40

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x9B4FB0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x996330
#define CEditWnd__EnsureCaretVisible_x                             0x998690
#define CEditWnd__GetCaretPt_x                                     0x997500
#define CEditWnd__GetCharIndexPt_x                                 0x9972B0
#define CEditWnd__GetDisplayString_x                               0x997160
#define CEditWnd__GetHorzOffset_x                                  0x995890
#define CEditWnd__GetLineForPrintableChar_x                        0x9985A0
#define CEditWnd__GetSelStartPt_x                                  0x997560
#define CEditWnd__GetSTMLSafeText_x                                0x996F70
#define CEditWnd__PointFromPrintableChar_x                         0x9981F0
#define CEditWnd__SelectableCharFromPoint_x                        0x998350
#define CEditWnd__SetEditable_x                                    0x997630
#define CEditWnd__SetWindowTextA_x                                 0x996CC0
#define CEditWnd__ReplaceSelection_x                               0x997DB0
#define CEditWnd__ReplaceSelection1_x                              0x997D30

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x62E610
#define CEverQuest__ClickedPlayer_x                                0x61FC00
#define CEverQuest__CreateTargetIndicator_x                        0x63FBF0
#define CEverQuest__DeleteTargetIndicator_x                        0x63FC80
#define CEverQuest__DoTellWindow_x                                 0x4F2130
#define CEverQuest__OutputTextToLog_x                              0x4F2400
#define CEverQuest__DropHeldItemOnGround_x                         0x614BF0
#define CEverQuest__dsp_chat_x                                     0x4F2790
#define CEverQuest__trimName_x                                     0x63B3F0
#define CEverQuest__Emote_x                                        0x62ECD0
#define CEverQuest__EnterZone_x                                    0x628A10
#define CEverQuest__GetBodyTypeDesc_x                              0x634130
#define CEverQuest__GetClassDesc_x                                 0x634770
#define CEverQuest__GetClassThreeLetterCode_x                      0x634D70
#define CEverQuest__GetDeityDesc_x                                 0x63E3A0
#define CEverQuest__GetLangDesc_x                                  0x634F30
#define CEverQuest__GetRaceDesc_x                                  0x634750
#define CEverQuest__InterpretCmd_x                                 0x63EA10
#define CEverQuest__LeftClickedOnPlayer_x                          0x619170
#define CEverQuest__LMouseUp_x                                     0x6171A0
#define CEverQuest__RightClickedOnPlayer_x                         0x619D60
#define CEverQuest__RMouseUp_x                                     0x618460
#define CEverQuest__SetGameState_x                                 0x614970
#define CEverQuest__UPCNotificationFlush_x                         0x63B310
#define CEverQuest__IssuePetCommand_x                              0x636530
#define CEverQuest__ReportSuccessfulHit_x                          0x6305E0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7565A0
#define CGaugeWnd__CalcLinesFillRect_x                             0x756600
#define CGaugeWnd__Draw_x                                          0x755BC0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4B4410
#define CGuild__GetGuildName_x                                     0x4B2C30
#define CGuild__GetGuildIndex_x                                    0x4B3350

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x773A30

//CHotButton
#define CHotButton__SetCheck_x                                     0x653260
#define CHotButton__SetButtonSize_x                                0x653620

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x780A10
#define CInvSlotMgr__MoveItem_x                                    0x77F5F0
#define CInvSlotMgr__SelectSlot_x                                  0x780AD0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x77DE40
#define CInvSlot__SliderComplete_x                                 0x77B320
#define CInvSlot__GetItemBase_x                                    0x77ABE0
#define CInvSlot__UpdateItem_x                                     0x77ADD0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x782720
#define CInvSlotWnd__CInvSlotWnd_x                                 0x781900
#define CInvSlotWnd__HandleLButtonUp_x                             0x7822A0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x84B780
#define CItemDisplayWnd__UpdateStrings_x                           0x7917F0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x78B2A0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x78B7F0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x791DF0
#define CItemDisplayWnd__AboutToShow_x                             0x791440
#define CItemDisplayWnd__WndNotification_x                         0x793360
#define CItemDisplayWnd__RequestConvertItem_x                      0x792C20
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x790460
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x791260

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8809C0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x797CB0

// CLabel 
#define CLabel__UpdateText_x                                       0x79E3D0

// CListWnd
#define CListWnd__CListWnd_x                                       0x9632C0
#define CListWnd__dCListWnd_x                                      0x9635C0
#define CListWnd__AddColumn_x                                      0x968000
#define CListWnd__AddColumn1_x                                     0x968120
#define CListWnd__AddLine_x                                        0x968490
#define CListWnd__AddString_x                                      0x968290
#define CListWnd__CalculateFirstVisibleLine_x                      0x967DB0
#define CListWnd__CalculateVSBRange_x                              0x967BA0
#define CListWnd__ClearSel_x                                       0x968D80
#define CListWnd__ClearAllSel_x                                    0x968DD0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x969880
#define CListWnd__Compare_x                                        0x9674D0
#define CListWnd__Draw_x                                           0x963780
#define CListWnd__DrawColumnSeparators_x                           0x9662D0
#define CListWnd__DrawHeader_x                                     0x966730
#define CListWnd__DrawItem_x                                       0x966D70
#define CListWnd__DrawLine_x                                       0x966440
#define CListWnd__DrawSeparator_x                                  0x966370
#define CListWnd__EnableLine_x                                     0x965B80
#define CListWnd__EnsureVisible_x                                  0x9697A0
//no references in jan 25 2021 test exe we can probably still call it
#define CListWnd__ExtendSel_x                                      0x968CC0
#define CListWnd__GetColumnTooltip_x                               0x965700
#define CListWnd__GetColumnMinWidth_x                              0x965770
#define CListWnd__GetColumnWidth_x                                 0x965680
#define CListWnd__GetCurSel_x                                      0x965020
#define CListWnd__GetItemAtPoint_x                                 0x965E00
//no references in jan 25 2021 test exe we can probably still call it
#define CListWnd__GetItemAtPoint1_x                                0x965E70
#define CListWnd__GetItemData_x                                    0x9650A0
#define CListWnd__GetItemHeight_x                                  0x965450
#define CListWnd__GetItemIcon_x                                    0x965220
#define CListWnd__GetItemRect_x                                    0x965C70
#define CListWnd__GetItemText_x                                    0x9650E0
#define CListWnd__GetSelList_x                                     0x968E20
#define CListWnd__GetSeparatorRect_x                               0x9660E0
#define CListWnd__InsertLine_x                                     0x9688F0
#define CListWnd__RemoveLine_x                                     0x968B10
#define CListWnd__SetColors_x                                      0x967B70
#define CListWnd__SetColumnJustification_x                         0x9678A0
#define CListWnd__SetColumnLabel_x                                 0x968230
#define CListWnd__SetColumnWidth_x                                 0x9677B0
#define CListWnd__SetCurSel_x                                      0x968C10
#define CListWnd__SetItemColor_x                                   0x969460
#define CListWnd__SetItemData_x                                    0x969420
#define CListWnd__SetItemText_x                                    0x969040
#define CListWnd__ShiftColumnSeparator_x                           0x967960
#define CListWnd__Sort_x                                           0x967660
#define CListWnd__ToggleSel_x                                      0x968C40
#define CListWnd__SetColumnsSizable_x                              0x967A00
#define CListWnd__SetItemWnd_x                                     0x9692E0
#define CListWnd__GetItemWnd_x                                     0x965270
#define CListWnd__SetItemIcon_x                                    0x9690C0
#define CListWnd__CalculateCustomWindowPositions_x                 0x967EB0
#define CListWnd__SetVScrollPos_x                                  0x967790

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7B5800
#define CMapViewWnd__GetWorldCoordinates_x                         0x7B3E20
#define CMapViewWnd__HandleLButtonDown_x                           0x7B0CB0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7D8A20
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7D9380
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7D99C0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7DCB80
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7D74B0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7E2D00
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7D8670

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8EC420
#define CPacketScrambler__hton_x                                   0x8EC410

// CSidlManagerbase we should rename at some point
#define CSidlManager__FindAnimation1_x                             0x985A90
#define CSidlManager__FindScreenPieceTemplate_x                    0x985E60
#define CSidlManager__FindScreenPieceTemplate1_x                   0x985C90
#define CSidlManager__CreateXWndFromTemplate_x                     0x989310
#define CSidlManager__CreateXWndFromTemplate1_x                    0x9895A0
#define CSidlManagerbase__CreateXWnd_x                             0x9895E0

//inlined since jan 25 2021 test but they left the function intact
#define CSidlManager__CreateHotButtonWnd_x                         0x8418E0
#define CSidlManager__CreateLabel_x                                0x8414A0

//CSidlManager
#define CSidlManager__CreateXWnd_x                                 0x840F10

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9817E0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9816E0
#define CSidlScreenWnd__ConvertToRes_x                             0x9AF200
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x981060
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x980D50
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x980E20
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x980EF0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x982090
#define CSidlScreenWnd__EnableIniStorage_x                         0x982570
#define CSidlScreenWnd__GetSidlPiece_x                             0x982280
#define CSidlScreenWnd__Init1_x                                    0x980800
#define CSidlScreenWnd__LoadIniInfo_x                              0x9825C0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x983180
#define CSidlScreenWnd__LoadSidlScreen_x                           0x97FC00
#define CSidlScreenWnd__StoreIniInfo_x                             0x982D00
#define CSidlScreenWnd__StoreIniVis_x                              0x983070
#define CSidlScreenWnd__WndNotification_x                          0x981F60
#define CSidlScreenWnd__GetChildItem_x                             0x9824F0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9709F0
#define CSidlScreenWnd__m_layoutCopy_x                             0x1613868

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6C0AA0
#define CSkillMgr__GetSkillCap_x                                   0x6C0C70
#define CSkillMgr__GetNameToken_x                                  0x6C02E0
#define CSkillMgr__IsActivatedSkill_x                              0x6C03D0
#define CSkillMgr__IsCombatSkill_x                                 0x6C0340

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x994470
#define CSliderWnd__SetValue_x                                     0x9942A0
#define CSliderWnd__SetNumTicks_x                                  0x994300

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x848160

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x99D8E0
#define CStmlWnd__ParseSTML_x                                      0x99EA90
#define CStmlWnd__CalculateHSBRange_x                              0x99E860
#define CStmlWnd__CalculateVSBRange_x                              0x99E7D0
#define CStmlWnd__CanBreakAtCharacter_x                            0x9A36C0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x9A4360
#define CStmlWnd__ForceParseNow_x                                  0x99DE50
#define CStmlWnd__GetNextTagPiece_x                                0x9A3620
#define CStmlWnd__GetVisibleText_x                                 0x99DE70
#define CStmlWnd__InitializeWindowVariables_x                      0x9A41B0
#define CStmlWnd__MakeStmlColorTag_x                               0x99CF80
#define CStmlWnd__MakeWndNotificationTag_x                         0x99CFF0
#define CStmlWnd__SetSTMLText_x                                    0x99BD60
#define CStmlWnd__StripFirstSTMLLines_x                            0x9A5580
#define CStmlWnd__UpdateHistoryString_x                            0x9A4560

// CTabWnd 
#define CTabWnd__Draw_x                                            0x99ACB0
#define CTabWnd__DrawCurrentPage_x                                 0x99B640
#define CTabWnd__DrawTab_x                                         0x99B230
#define CTabWnd__GetCurrentPage_x                                  0x99A410
#define CTabWnd__GetPageInnerRect_x                                0x99A640
#define CTabWnd__GetTabInnerRect_x                                 0x99A580
#define CTabWnd__GetTabRect_x                                      0x99A440
#define CTabWnd__InsertPage_x                                      0x99A830
#define CTabWnd__RemovePage_x                                      0x99A980
#define CTabWnd__SetPage_x                                         0x99A6C0
//inlined but we can probably call it jan 25 2021
#define CTabWnd__SetPageRect_x                                     0x99ABB0
#define CTabWnd__UpdatePage_x                                      0x99B020
#define CTabWnd__GetPageFromTabIndex_x                             0x99B170
#define CTabWnd__GetCurrentTabIndex_x                              0x99A400

// CPageWnd
//inlined in Jan 25 2021 test
//#define CPageWnd__GetTabText_x                                     0x479340
#define CPageWnd__SetTabText_x                                     0x999DA0
#define CPageWnd__FlashTab_x                                       0x999E00

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4AC4A0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x96CE10
#define CTextureFont__GetTextExtent_x                              0x96D110

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9ABCB0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x958D60

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x544280
#define CXStr__CXStr1_x                                            0x482750
#define CXStr__CXStr3_x                                            0x940C40
#define CXStr__dCXStr_x                                            0x478F60
#define CXStr__operator_equal_x                                    0x940E80
#define CXStr__operator_equal1_x                                   0x940EC0
#define CXStr__operator_plus_equal1_x                              0x941920
#define CXStr__SetString_x                                         0x9437C0
#define CXStr__operator_char_p_x                                   0x941370
#define CXStr__GetChar_x                                           0x943120
#define CXStr__Delete_x                                            0x9429F0
#define CXStr__GetUnicode_x                                        0x943190
#define CXStr__Insert_x                                            0x9431F0
#define CXStr__FindNext_x                                          0x942E40
#define CXStr__Copy_x                                              0x942800

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x992470
#define CXWnd__BringToTop_x                                        0x974440
#define CXWnd__ClrFocus_x                                          0x973DC0
#define CXWnd__Destroy_x                                           0x973E70
#define CXWnd__DoAllDrawing_x                                      0x970040
//inlined in jan 25 2021 we can probably still call it
#define CXWnd__DrawChildren_x                                      0x970010
#define CXWnd__DrawColoredRect_x                                   0x9705D0
#define CXWnd__DrawTooltip_x                                       0x96E580
#define CXWnd__DrawTooltipAtPoint_x                                0x96E640
#define CXWnd__GetBorderFrame_x                                    0x970270
#define CXWnd__GetChildWndAt_x                                     0x9744E0
#define CXWnd__GetClientClipRect_x                                 0x972650
#define CXWnd__GetScreenClipRect_x                                 0x972720
#define CXWnd__GetScreenRect_x                                     0x9728F0
#define CXWnd__GetRelativeRect_x                                   0x9729B0
#define CXWnd__GetTooltipRect_x                                    0x970620
#define CXWnd__GetWindowTextA_x                                    0x4F1FD0
#define CXWnd__IsActive_x                                          0x970D70
#define CXWnd__IsDescendantOf_x                                    0x973330
#define CXWnd__IsReallyVisible_x                                   0x973360
#define CXWnd__IsType_x                                            0x974C70
#define CXWnd__Move_x                                              0x9733D0
#define CXWnd__Move1_x                                             0x9734C0
#define CXWnd__ProcessTransition_x                                 0x973F50
#define CXWnd__Refade_x                                            0x973770
#define CXWnd__Resize_x                                            0x973A00
#define CXWnd__Right_x                                             0x974230
#define CXWnd__SetFocus_x                                          0x973D80
#define CXWnd__SetFont_x                                           0x973DF0
#define CXWnd__SetKeyTooltip_x                                     0x974A30
#define CXWnd__SetMouseOver_x                                      0x971710
#define CXWnd__StartFade_x                                         0x905610
#define CXWnd__GetChildItem_x                                      0x974660
#define CXWnd__SetParent_x                                         0x973050
#define CXWnd__Minimize_x                                          0x973A70

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x9B0250

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9774C0
#define CXWndManager__DrawWindows_x                                0x977610
#define CXWndManager__GetKeyboardFlags_x                           0x979FB0
#define CXWndManager__HandleKeyboardMsg_x                          0x979B90
#define CXWndManager__RemoveWnd_x                                  0x97A270
#define CXWndManager__RemovePendingDeletionWnd_x                   0x97A720

// CDBStr
#define CDBStr__GetString_x                                        0x55A400

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4C5680
#define EQ_Character__Cur_HP_x                                     0x4D95D0
#define EQ_Character__Cur_Mana_x                                   0x4E16E0
#define EQ_Character__GetCastingTimeModifier_x                     0x4C8CF0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B8200
#define EQ_Character__GetFocusRangeModifier_x                      0x4B8350
#define EQ_Character__GetHPRegen_x                                 0x4E80E0
#define EQ_Character__GetEnduranceRegen_x                          0x4E86A0
#define EQ_Character__GetManaRegen_x                               0x4E8AE0
#define EQ_Character__Max_Endurance_x                              0x681BF0
#define EQ_Character__Max_HP_x                                     0x4D9400
#define EQ_Character__Max_Mana_x                                   0x6819E0
#define EQ_Character__doCombatAbility_x                            0x684520
#define EQ_Character__UseSkill_x                                   0x4EAAE0
#define EQ_Character__GetConLevel_x                                0x679D10
#define EQ_Character__IsExpansionFlag_x                            0x5D3590
#define EQ_Character__TotalEffect_x                                0x4CD160
#define EQ_Character__GetPCSpellAffect_x                           0x4C9B20
#define EQ_Character__SpellDuration_x                              0x4C9560
#define EQ_Character__MySpellDuration_x                            0x4B68C0
#define EQ_Character__GetAdjustedSkill_x                           0x4DC720
#define EQ_Character__GetBaseSkill_x                               0x4DD6C0
#define EQ_Character__CanUseItem_x                                 0x4E1A10

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x90C8A0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x699650

//PcClient
#define PcClient__vftable_x                                        0xB42C5C
#define PcClient__PcClient_x                                       0x676F80

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BFCA0
#define CCharacterListWnd__EnterWorld_x                            0x4BF670
#define CCharacterListWnd__Quit_x                                  0x4BF390
#define CCharacterListWnd__UpdateList_x                            0x4BF860

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x659470
#define EQ_Item__CreateItemTagString_x                             0x8E5460
#define EQ_Item__IsStackable_x                                     0x8EA440
#define EQ_Item__GetImageNum_x                                     0x8E7130
#define EQ_Item__CreateItemClient_x                                0x658420
#define EQ_Item__GetItemValue_x                                    0x8E8420
#define EQ_Item__ValueSellMerchant_x                               0x8EC150
#define EQ_Item__IsKeyRingItem_x                                   0x8E9C30
#define EQ_Item__CanGoInBag_x                                      0x659590
#define EQ_Item__IsEmpty_x                                         0x8E96E0
#define EQ_Item__GetMaxItemCount_x                                 0x8E8810
#define EQ_Item__GetHeldItem_x                                     0x8E6FF0
#define EQ_Item__CanGemFitInSlot_x                                 0x8E4C70

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x57AEA0
#define EQ_LoadingS__Array_x                                       0xD8FD00

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x6826E0
#define EQ_PC__GetAlternateAbilityId_x                             0x8F6180
#define EQ_PC__GetCombatAbility_x                                  0x8F6700
#define EQ_PC__GetCombatAbilityTimer_x                             0x8F6770
#define EQ_PC__GetItemRecastTimer_x                                0x684B20
#define EQ_PC__HasLoreItem_x                                       0x67A6B0
#define EQ_PC__AlertInventoryChanged_x                             0x6795D0
#define EQ_PC__GetPcZoneClient_x                                   0x6A9D50
#define EQ_PC__RemoveMyAffect_x                                    0x688040
#define EQ_PC__GetKeyRingItems_x                                   0x8F7200
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8F6D60
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8F7350

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5D9900
#define EQItemList__add_object_x                                   0x609A70
#define EQItemList__add_item_x                                     0x5D9EE0
#define EQItemList__delete_item_x                                  0x5D9F30
#define EQItemList__FreeItemList_x                                 0x5D9E40

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x556530

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x69B080
#define EQPlayer__dEQPlayer_x                                      0x68D930
#define EQPlayer__DoAttack_x                                       0x6A3A90
#define EQPlayer__EQPlayer_x                                       0x68E180
#define EQPlayer__SetNameSpriteState_x                             0x692730
#define EQPlayer__SetNameSpriteTint_x                              0x693600
#define PlayerBase__HasProperty_j_x                                0x9DFB50
#define EQPlayer__IsTargetable_x                                   0x9E00B0
#define EQPlayer__CanSee_x                                         0x9DFEA0
#define EQPlayer__CanSee1_x                                        0x9DFF70
#define PlayerBase__GetVisibilityLineSegment_x                     0x9DFC10

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x6A7850
#define PlayerZoneClient__GetLevel_x                               0x6A9D90
#define PlayerZoneClient__IsValidTeleport_x                        0x60AF10
#define PlayerZoneClient__LegalPlayerRace_x                        0x572E60

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x69E240
#define EQPlayerManager__GetSpawnByName_x                          0x69E2F0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x69E380

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x65CE00
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x65CED0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x65CF10
#define KeypressHandler__ClearCommandStateArray_x                  0x65E3D0
#define KeypressHandler__HandleKeyDown_x                           0x65E3F0
#define KeypressHandler__HandleKeyUp_x                             0x65E490
#define KeypressHandler__SaveKeymapping_x                          0x65EA40

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7B14B0
#define MapViewMap__SaveEx_x                                       0x7B49EF
#define MapViewMap__SetZoom_x                                      0x7BA630

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x90A730

// StringTable 
#define StringTable__getString_x                                   0x905610

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x687C90
#define PcZoneClient__RemovePetEffect_x                            0x6882F0
#define PcZoneClient__HasAlternateAbility_x                        0x681840
#define PcZoneClient__GetCurrentMod_x                              0x4EE270
#define PcZoneClient__GetModCap_x                                  0x4EE170
#define PcZoneClient__CanEquipItem_x                               0x681EF0
#define PcZoneClient__GetItemByID_x                                0x684FF0
#define PcZoneClient__GetItemByItemClass_x                         0x685130
#define PcZoneClient__RemoveBuffEffect_x                           0x6883A0
#define PcZoneClient__BandolierSwap_x                              0x682C90
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x684AC0

//Doors
#define EQSwitch__UseSwitch_x                                      0x60FA60

//IconCache
#define IconCache__GetIcon_x                                       0x74AFD0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x741B90
#define CContainerMgr__CloseContainer_x                            0x741E70
#define CContainerMgr__OpenExperimentContainer_x                   0x7429D0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x8109C0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x6519B0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x7A66F0
#define CLootWnd__RequestLootSlot_x                                0x7A5920

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x5A5460
#define EQ_Spell__SpellAffects_x                                   0x5A5960
#define EQ_Spell__SpellAffectBase_x                                0x5A5680
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4D0B50
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4D0B00
#define EQ_Spell__IsSPAStacking_x                                  0x5A6870
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x5A5CC0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x5A6880
#define EQ_Spell__IsLullSpell_x                                    0x5A60B0
#define __IsResEffectSpell_x                                       0x4D0300

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4B11E0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x9151B0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x85D3A0
#define CTargetWnd__WndNotification_x                              0x85CB30
#define CTargetWnd__RefreshTargetBuffs_x                           0x85CE90
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x85B910

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x861F20
#define CTaskWnd__ConfirmAbandonTask_x                             0x864FF0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x554100
#define CTaskManager__HandleMessage_x                              0x551FD0
#define CTaskManager__GetTaskStatus_x                              0x5541B0
#define CTaskManager__GetElementDescription_x                      0x554230

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5A0090
#define EqSoundManager__PlayScriptMp3_x                            0x5A0290
#define EqSoundManager__SoundAssistPlay_x                          0x6C4F30
#define EqSoundManager__WaveInstancePlay_x                         0x6C4420

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x543F30

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x999220
#define CTextureAnimation__Draw_x                                  0x999460
#define CTextureAnimation__AddBlankFrame_x                         0x999040

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x994F70

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x583490
#define CAltAbilityData__GetMercMaxRank_x                          0x583420
#define CAltAbilityData__GetMaxRank_x                              0x577810

//CTargetRing
#define CTargetRing__Cast_x                                        0x64F1C0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x658270
#define CharacterBase__CreateItemGlobalIndex_x                     0x6458E0
//this is a guess testing is needed
#define CharacterBase__GetItemPossession_x                         0x658250
#define CharacterBase__GetItemByGlobalIndex_x                      0x91CD10
#define CharacterBase__GetItemByGlobalIndex1_x                     0x91CD60
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x726A20
#define CCastSpellWnd__IsBardSongPlaying_x                         0x7272E0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x727390

//messages
#define msg_spell_worn_off_x                                       0x5CAED0
#define msg_new_text_x                                             0x5BECE0
#define __msgTokenTextParam_x                                      0x5CD340
#define msgTokenText_x                                             0x5CD750

//SpellManager
#define SpellManager__vftable_x                                    0xB2D2FC
#define SpellManager__SpellManager_x                               0x6C8B60
#define Spellmanager__LoadTextSpells_x                             0x6C9460
#define SpellManager__GetSpellByGroupAndRank_x                     0x6C8D30

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9E43B0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x5D35E0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5D1AB0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x671E60
#define ItemGlobalIndex__IsValidIndex_x                            0x5D3770

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x915BB0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x915F00

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x79E840

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x746880
#define CCursorAttachment__AttachToCursor1_x                       0x7468C0
#define CCursorAttachment__Deactivate_x                            0x747E50

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x98AB60
#define CSidlManagerBase__CreatePageWnd_x                          0x98A340
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x985810
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x9857A0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9AA880
#define CEQSuiteTextureLoader__GetTexture_x                        0x9AA500

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x5241F0
#define CFindItemWnd__WndNotification_x                            0x5250B0
#define CFindItemWnd__Update_x                                     0x525C90
#define CFindItemWnd__PickupSelectedItem_x                         0x5238F0

//IString
#define IString__Append_x                                          0x513500

//Camera
#define CDisplay__cameraType_x                                     0xED4210
#define EverQuest__Cameras_x                                       0xDA3438

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x52ED80
#define LootFiltersManager__GetItemFilterData_x                    0x52E6B0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x52E6E0
#define LootFiltersManager__SetItemLootFilter_x                    0x52E8F0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7FD4B0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9EA070
#define CResolutionHandler__GetWindowedStyle_x                     0x6BF3E0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x73E510

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x921080
#define CDistillerInfo__Instance_x                                 0x920FC0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x7611B0
#define CGroupWnd__UpdateDisplay_x                                 0x760400

//ItemBase
#define ItemBase__IsLore_x                                         0x8E9CD0
#define ItemBase__IsLoreEquipped_x                                 0x8E9D40

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x6099D0
#define EQPlacedItemManager__GetItemByGuid_x                       0x609B10
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x609B70

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6B3B10
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x6B8410

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x519CD0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x504A80
#define FactionManagerClient__HandleFactionMessage_x               0x5052A0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x505AC0
#define FactionManagerClient__GetMaxFaction_x                      0x505ADF
#define FactionManagerClient__GetMinFaction_x                      0x505A90

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x511690

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x96BA80

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49DEF0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x511900

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x582640

//CTargetManager
#define CTargetManager__Get_x                                      0x6CCAE0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6B3B10

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4AC260

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5D9DE0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xE40ACC

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6EA500
#define CAAWnd__UpdateSelected_x                                   0x6E6B90
#define CAAWnd__Update_x                                           0x6E9820

//CXRect
#define CXRect__operator_and_x                                     0x756660

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

