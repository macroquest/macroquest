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
#define __ExpectedVersionDate                                     "Mar  4 2021"
#define __ExpectedVersionTime                                     "08:50:08"
#define __ActualVersionDate_x                                      0xB45EE4
#define __ActualVersionTime_x                                      0xB45ED8
#define __ActualVersionBuild_x                                     0xB360C4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x663B40
#define __MemChecker1_x                                            0x945030
#define __MemChecker2_x                                            0x6DDAC0
#define __MemChecker3_x                                            0x6DDA30
#define __MemChecker4_x                                            0x8981F0
#define __EncryptPad0_x                                            0xE46F40
#define __EncryptPad1_x                                            0xEA1740
#define __EncryptPad2_x                                            0xE56158
#define __EncryptPad3_x                                            0xE55D58
#define __EncryptPad4_x                                            0xE92550
#define __EncryptPad5_x                                            0xF95020
#define __AC1_x                                                    0x852D90
#define __AC2_x                                                    0x61899F
#define __AC3_x                                                    0x61FD71
#define __AC4_x                                                    0x623EE0
#define __AC5_x                                                    0x62A79F
#define __AC6_x                                                    0x62EEE6
#define __AC7_x                                                    0x618400
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
#define __do_loot_x                                                0x5E1530
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
#define __gfMaxZoomCameraDistance_x                                0xB3DDC4
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
#define pinstCOverseerWnd_x                                        0xED40C8
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
#define pinstCZoneGuideWnd_x                                       0xED41F8
#define pinstCZonePathWnd_x                                        0xED4204

#define pinstEQSuiteTextureLoader_x                                0xEA1D00
#define pinstItemIconCache_x                                       0xFA1F18
#define pinstLootFiltersManager_x                                  0xED35E8
#define pinstRewardSelectionWnd_x                                  0xFA6F70

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5DC7F0
//it has no refs but we can possibly call it still 
#define __CastRay2_x                                               0x5DCA80
#define __ConvertItemTags_x                                        0x5F9AF0
#define __CleanItemTags_x                                          0x47DA70
#define __DoesFileExist_x                                          0x947FC0
#define __EQGetTime_x                                              0x944CA0
#define __ExecuteCmd_x                                             0x5D4C70
#define __FixHeading_x                                             0x9E1F00
#define __FlushDxKeyboard_x                                        0x6D8DC0
#define __GameLoop_x                                               0x6DC6C0
#define __get_bearing_x                                            0x5DC390
#define __get_melee_range_x                                        0x5DCCC0
#define __GetAnimationCache_x                                      0x74B3F0
#define __GetGaugeValueFromEQ_x                                    0x8511D0
#define __GetLabelFromEQ_x                                         0x852D10
#define __GetXTargetType_x                                         0x9E4270
#define __HandleMouseWheel_x                                       0x6DDB50
#define __HeadingDiff_x                                            0x9E1F60
#define __HelpPath_x                                               0xF8DCFC
#define __ExecuteFrontEnd_x                                        0x6D95A0
#define __NewUIINI_x                                               0x850EA0
#define __ProcessGameEvents_x                                      0x642BC0
#define __ProcessMouseEvent_x                                      0x6422C0
#define __SaveColors_x                                             0x571130
#define __STMLToText_x                                             0x97FBB0
#define __ToggleKeyRingItem_x                                      0x52A8F0
#define CMemoryMappedFile__SetFile_x                               0xAD26D0
#define CrashDetected_x                                            0x6DB2D0
#define DrawNetStatus_x                                            0x6720C0
#define Expansion_HoT_x                                            0xDA30E0
#define Teleport_Table_Size_x                                      0xF884E0
#define Teleport_Table_x                                           0xF860B8
#define Util__FastTime_x                                           0x944860
#define __CopyLayout_x                                             0x65EDC0
#define __WndProc_x                                                0x6DB7D0
#define __ProcessKeyboardEvent_x                                   0x6DAD10

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4919C0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x49B1A0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x49B020
#define CAdvancedLootWnd__AddPlayerToList_x                        0x495710
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x494950

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x57A140
#define AltAdvManager__IsAbilityReady_x                            0x578D30
#define AltAdvManager__GetAAById_x                                 0x5790D0
#define AltAdvManager__CanTrainAbility_x                           0x579140
#define AltAdvManager__CanSeeAbility_x                             0x5794D0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4D1210
#define CharacterZoneClient__HasSkill_x                            0x4DC980
#define CharacterZoneClient__MakeMeVisible_x                       0x4DE0C0
#define CharacterZoneClient__IsStackBlocked_x                      0x4C8660
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4C0E20
#define CharacterZoneClient__GetItemCountWorn_x                    0x4E0FD0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4E10D0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4E11D0
#define CharacterZoneClient__FindAffectSlot_x                      0x4CA8A0
#define CharacterZoneClient__BardCastBard_x                        0x4CD8B0
#define CharacterZoneClient__GetMaxEffects_x                       0x4C4D60
#define CharacterZoneClient__GetEffect_x                           0x4C0D60
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4CBEB0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4CBF60
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4CC000
#define CharacterZoneClient__CalcAffectChange_x                    0x4CC1C0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4CC3A0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B8620
#define CharacterZoneClient__FindItemByGuid_x                      0x4DF260
#define CharacterZoneClient__FindItemByRecord_x                    0x4DEBB0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x706810
#define CBankWnd__WndNotification_x                                0x7065B0

//CBarterWnd
#define CBarterWnd__WndNotification_x                              0x711250

//CBarterSearchWnd
#define CBarterSearchWnd__WndNotification_x                        0x70BE90
#define CBarterSearchWnd__UpdateInventoryList_x                    0x709E60

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x715880

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x97D150
#define CButtonWnd__CButtonWnd_x                                   0x97BAB0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x738B60
#define CChatManager__InitContextMenu_x                            0x731A30
#define CChatManager__FreeChatWindow_x                             0x737720
#define CChatManager__SetLockedActiveChatWindow_x                  0x738840
#define CChatManager__CreateChatWindow_x                           0x737D50

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4F2070

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x992F40
#define CContextMenu__dCContextMenu_x                              0x993180
#define CContextMenu__AddMenuItem_x                                0x993190
#define CContextMenu__RemoveMenuItem_x                             0x9934A0
#define CContextMenu__RemoveAllMenuItems_x                         0x9934C0
#define CContextMenu__CheckMenuItem_x                              0x993520
#define CContextMenu__SetMenuItem_x                                0x9933C0
#define CContextMenu__AddSeparator_x                               0x993320

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x993AA0
#define CContextMenuManager__RemoveMenu_x                          0x993B10
#define CContextMenuManager__PopupMenu_x                           0x993BD0
#define CContextMenuManager__Flush_x                               0x993A40
#define CContextMenuManager__GetMenu_x                             0x49D4D0
#define CContextMenuManager__CreateDefaultMenu_x                   0x7453C0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x91F3A0
#define CChatService__GetFriendName_x                              0x91F3B0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x7394C0
#define CChatWindow__Clear_x                                       0x73A920
#define CChatWindow__WndNotification_x                             0x73B0B0
#define CChatWindow__AddHistory_x                                  0x73A180

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x990010
#define CComboWnd__Draw_x                                          0x98F4B0
#define CComboWnd__GetCurChoice_x                                  0x98FDE0
#define CComboWnd__GetListRect_x                                   0x98F950
#define CComboWnd__GetTextRect_x                                   0x990080
#define CComboWnd__InsertChoice_x                                  0x98FAE0
#define CComboWnd__SetColors_x                                     0x98FAB0
#define CComboWnd__SetChoice_x                                     0x98FDC0
#define CComboWnd__GetItemCount_x                                  0x98FDF0
#define CComboWnd__GetCurChoiceText_x                              0x98FE20
#define CComboWnd__GetChoiceText_x                                 0x98FE00
#define CComboWnd__InsertChoiceAtIndex_x                           0x98FB80

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x742A40
#define CContainerWnd__vftable_x                                   0xB4F104
#define CContainerWnd__SetContainer_x                              0x744290

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x56BD00
#define CDisplay__PreZoneMainUI_x                                  0x56BD10
#define CDisplay__CleanGameUI_x                                    0x570F10
#define CDisplay__GetClickedActor_x                                0x563BE0
#define CDisplay__GetUserDefinedColor_x                            0x55B950
//well they inlined it in jan 25 2021 test but the function is still left in exe so for now we can probably just call it...
#define CDisplay__GetWorldFilePath_x                               0x5656F0
#define CDisplay__is3dON_x                                         0x560470
#define CDisplay__ReloadUI_x                                       0x56B020
#define CDisplay__WriteTextHD2_x                                   0x560260
#define CDisplay__TrueDistance_x                                   0x5675C0
#define CDisplay__SetViewActor_x                                   0x563500
#define CDisplay__GetFloorHeight_x                                 0x560530
#define CDisplay__SetRenderWindow_x                                0x55EEB0
#define CDisplay__ToggleScreenshotMode_x                           0x562FD0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x9B5700

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x996A60
#define CEditWnd__EnsureCaretVisible_x                             0x998DE0
#define CEditWnd__GetCaretPt_x                                     0x997C40
#define CEditWnd__GetCharIndexPt_x                                 0x9979F0
#define CEditWnd__GetDisplayString_x                               0x997890
#define CEditWnd__GetHorzOffset_x                                  0x995FB0
#define CEditWnd__GetLineForPrintableChar_x                        0x998CF0
#define CEditWnd__GetSelStartPt_x                                  0x997CA0
#define CEditWnd__GetSTMLSafeText_x                                0x9976A0
#define CEditWnd__PointFromPrintableChar_x                         0x998930
#define CEditWnd__SelectableCharFromPoint_x                        0x998A90
#define CEditWnd__SetEditable_x                                    0x997D70
#define CEditWnd__SetWindowTextA_x                                 0x9973F0
#define CEditWnd__ReplaceSelection_x                               0x9984F0
#define CEditWnd__ReplaceSelection1_x                              0x998470

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x62E560
#define CEverQuest__ClickedPlayer_x                                0x61FB50
#define CEverQuest__CreateTargetIndicator_x                        0x63FB40
#define CEverQuest__DeleteTargetIndicator_x                        0x63FBD0
#define CEverQuest__DoTellWindow_x                                 0x4F2170
#define CEverQuest__OutputTextToLog_x                              0x4F2440
#define CEverQuest__DropHeldItemOnGround_x                         0x614B50
#define CEverQuest__dsp_chat_x                                     0x4F27D0
#define CEverQuest__trimName_x                                     0x63B340
#define CEverQuest__Emote_x                                        0x62EC20
#define CEverQuest__EnterZone_x                                    0x628960
#define CEverQuest__GetBodyTypeDesc_x                              0x634080
#define CEverQuest__GetClassDesc_x                                 0x6346C0
#define CEverQuest__GetClassThreeLetterCode_x                      0x634CC0
#define CEverQuest__GetDeityDesc_x                                 0x63E2F0
#define CEverQuest__GetLangDesc_x                                  0x634E80
#define CEverQuest__GetRaceDesc_x                                  0x6346A0
#define CEverQuest__InterpretCmd_x                                 0x63E960
#define CEverQuest__LeftClickedOnPlayer_x                          0x6190D0
#define CEverQuest__LMouseUp_x                                     0x617100
#define CEverQuest__RightClickedOnPlayer_x                         0x619CC0
#define CEverQuest__RMouseUp_x                                     0x6183C0
#define CEverQuest__SetGameState_x                                 0x6148D0
#define CEverQuest__UPCNotificationFlush_x                         0x63B260
#define CEverQuest__IssuePetCommand_x                              0x636480
#define CEverQuest__ReportSuccessfulHit_x                          0x630530

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x756370
#define CGaugeWnd__CalcLinesFillRect_x                             0x7563D0
#define CGaugeWnd__Draw_x                                          0x755980

// CGuild
#define CGuild__FindMemberByName_x                                 0x4B4460
#define CGuild__GetGuildName_x                                     0x4B2C80
#define CGuild__GetGuildIndex_x                                    0x4B33A0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x7737B0

//CHotButton
#define CHotButton__SetCheck_x                                     0x6531D0
#define CHotButton__SetButtonSize_x                                0x653590

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x7807B0
#define CInvSlotMgr__MoveItem_x                                    0x77F380
#define CInvSlotMgr__SelectSlot_x                                  0x780870

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x77DBD0
#define CInvSlot__SliderComplete_x                                 0x77B0B0
#define CInvSlot__GetItemBase_x                                    0x77A980
#define CInvSlot__UpdateItem_x                                     0x77AB70

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7824B0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7816A0
#define CInvSlotWnd__HandleLButtonUp_x                             0x782030

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x84B4D0
#define CItemDisplayWnd__UpdateStrings_x                           0x7914E0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x78AF70
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x78B4C0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x791AE0
#define CItemDisplayWnd__AboutToShow_x                             0x791140
#define CItemDisplayWnd__WndNotification_x                         0x793040
#define CItemDisplayWnd__RequestConvertItem_x                      0x792910
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x790160
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x790F60

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x880790

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x7979C0
#define CItemDisplayManager__ShowItem_x                            0x796F70

// CLabel 
#define CLabel__UpdateText_x                                       0x79E0E0

// CListWnd
#define CListWnd__CListWnd_x                                       0x963C30
#define CListWnd__dCListWnd_x                                      0x963F30
#define CListWnd__AddColumn_x                                      0x968970
#define CListWnd__AddColumn1_x                                     0x968A90
#define CListWnd__AddLine_x                                        0x968E00
#define CListWnd__AddString_x                                      0x968C00
#define CListWnd__CalculateFirstVisibleLine_x                      0x968720
#define CListWnd__CalculateVSBRange_x                              0x968500
#define CListWnd__ClearSel_x                                       0x9696F0
#define CListWnd__ClearAllSel_x                                    0x969740
#define CListWnd__CloseAndUpdateEditWindow_x                       0x96A1F0
#define CListWnd__Compare_x                                        0x967E30
#define CListWnd__Draw_x                                           0x9640F0
#define CListWnd__DrawColumnSeparators_x                           0x966C20
#define CListWnd__DrawHeader_x                                     0x967080
#define CListWnd__DrawItem_x                                       0x9676D0
#define CListWnd__DrawLine_x                                       0x966D90
#define CListWnd__DrawSeparator_x                                  0x966CC0
#define CListWnd__EnableLine_x                                     0x9664E0
#define CListWnd__EnsureVisible_x                                  0x96A110
//no references in jan 25 2021 test exe we can probably still call it
#define CListWnd__ExtendSel_x                                      0x969630
#define CListWnd__GetColumnTooltip_x                               0x966060
#define CListWnd__GetColumnMinWidth_x                              0x9660D0
#define CListWnd__GetColumnWidth_x                                 0x965FE0
#define CListWnd__GetCurSel_x                                      0x965980
#define CListWnd__GetItemAtPoint_x                                 0x966760
//no references in jan 25 2021 test exe we can probably still call it
#define CListWnd__GetItemAtPoint1_x                                0x9667D0
#define CListWnd__GetItemData_x                                    0x965A00
#define CListWnd__GetItemHeight_x                                  0x965DB0
#define CListWnd__GetItemIcon_x                                    0x965B80
#define CListWnd__GetItemRect_x                                    0x9665D0
#define CListWnd__GetItemText_x                                    0x965A40
#define CListWnd__GetSelList_x                                     0x969790
#define CListWnd__GetSeparatorRect_x                               0x966A40
#define CListWnd__InsertLine_x                                     0x969260
#define CListWnd__RemoveLine_x                                     0x969480
#define CListWnd__SetColors_x                                      0x9684D0
#define CListWnd__SetColumnJustification_x                         0x968200
#define CListWnd__SetColumnLabel_x                                 0x968BA0
#define CListWnd__SetColumnWidth_x                                 0x968110
#define CListWnd__SetCurSel_x                                      0x969580
#define CListWnd__SetItemColor_x                                   0x969DD0
#define CListWnd__SetItemData_x                                    0x969D90
#define CListWnd__SetItemText_x                                    0x9699B0
#define CListWnd__ShiftColumnSeparator_x                           0x9682C0
#define CListWnd__Sort_x                                           0x967FC0
#define CListWnd__ToggleSel_x                                      0x9695B0
#define CListWnd__SetColumnsSizable_x                              0x968360
#define CListWnd__SetItemWnd_x                                     0x969C50
#define CListWnd__GetItemWnd_x                                     0x965BD0
#define CListWnd__SetItemIcon_x                                    0x969A30
#define CListWnd__CalculateCustomWindowPositions_x                 0x968820
#define CListWnd__SetVScrollPos_x                                  0x9680F0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7B5550
#define CMapViewWnd__GetWorldCoordinates_x                         0x7B3B70
#define CMapViewWnd__HandleLButtonDown_x                           0x7B0A00

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7D8740
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7D90A0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7D96E0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7DC8B0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7D71D0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7E2A30
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7D8390

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8EC300
#define CPacketScrambler__hton_x                                   0x8EC2F0

// CSidlManagerbase we should rename at some point
#define CSidlManager__FindAnimation1_x                             0x9861F0
#define CSidlManager__FindScreenPieceTemplate_x                    0x9865C0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9863F0
#define CSidlManager__CreateXWndFromTemplate_x                     0x989A70
#define CSidlManager__CreateXWndFromTemplate1_x                    0x989D00
#define CSidlManagerbase__CreateXWnd_x                             0x989D40

//inlined since jan 25 2021 test but they left the function intact
#define CSidlManager__CreateHotButtonWnd_x                         0x841650
#define CSidlManager__CreateLabel_x                                0x841220

//CSidlManager
#define CSidlManager__CreateXWnd_x                                 0x840CA0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x981F30
#define CSidlScreenWnd__CalculateVSBRange_x                        0x981E30
#define CSidlScreenWnd__ConvertToRes_x                             0x9AF950
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x9817B0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x9814A0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x981570
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x981640
#define CSidlScreenWnd__DrawSidlPiece_x                            0x9827F0
#define CSidlScreenWnd__EnableIniStorage_x                         0x982CD0
#define CSidlScreenWnd__GetSidlPiece_x                             0x9829E0
#define CSidlScreenWnd__Init1_x                                    0x980F70
#define CSidlScreenWnd__LoadIniInfo_x                              0x982D20
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9838E0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x980380
#define CSidlScreenWnd__StoreIniInfo_x                             0x983460
#define CSidlScreenWnd__StoreIniVis_x                              0x9837D0
#define CSidlScreenWnd__WndNotification_x                          0x9826C0
#define CSidlScreenWnd__GetChildItem_x                             0x982C50
#define CSidlScreenWnd__HandleLButtonUp_x                          0x971280
#define CSidlScreenWnd__m_layoutCopy_x                             0x1613868

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6C0AB0
#define CSkillMgr__GetSkillCap_x                                   0x6C0C80
#define CSkillMgr__GetNameToken_x                                  0x6C02F0
#define CSkillMgr__IsActivatedSkill_x                              0x6C03E0
#define CSkillMgr__IsCombatSkill_x                                 0x6C0350

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x994B90
#define CSliderWnd__SetValue_x                                     0x9949C0
#define CSliderWnd__SetNumTicks_x                                  0x994A20

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x847EB0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x99E030
#define CStmlWnd__ParseSTML_x                                      0x99F1F0
#define CStmlWnd__CalculateHSBRange_x                              0x99EFB0
#define CStmlWnd__CalculateVSBRange_x                              0x99EF20
#define CStmlWnd__CanBreakAtCharacter_x                            0x9A3E10
#define CStmlWnd__FastForwardToEndOfTag_x                          0x9A4AB0
#define CStmlWnd__ForceParseNow_x                                  0x99E5A0
#define CStmlWnd__GetNextTagPiece_x                                0x9A3D70
#define CStmlWnd__GetVisibleText_x                                 0x99E5C0
#define CStmlWnd__InitializeWindowVariables_x                      0x9A4900
#define CStmlWnd__MakeStmlColorTag_x                               0x99D6D0
#define CStmlWnd__MakeWndNotificationTag_x                         0x99D740
#define CStmlWnd__SetSTMLText_x                                    0x99C4B0
#define CStmlWnd__StripFirstSTMLLines_x                            0x9A5CD0
#define CStmlWnd__UpdateHistoryString_x                            0x9A4CB0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x99B400
#define CTabWnd__DrawCurrentPage_x                                 0x99BD90
#define CTabWnd__DrawTab_x                                         0x99B980
#define CTabWnd__GetCurrentPage_x                                  0x99AB60
#define CTabWnd__GetPageInnerRect_x                                0x99AD90
#define CTabWnd__GetTabInnerRect_x                                 0x99ACD0
#define CTabWnd__GetTabRect_x                                      0x99AB90
#define CTabWnd__InsertPage_x                                      0x99AF80
#define CTabWnd__RemovePage_x                                      0x99B0D0
#define CTabWnd__SetPage_x                                         0x99AE10
//inlined but we can probably call it jan 25 2021
#define CTabWnd__SetPageRect_x                                     0x99B300
#define CTabWnd__UpdatePage_x                                      0x99B770
#define CTabWnd__GetPageFromTabIndex_x                             0x99B8C0
#define CTabWnd__GetCurrentTabIndex_x                              0x99AB50

// CPageWnd
//inlined in Jan 25 2021 test
//#define CPageWnd__GetTabText_x                                     0x479340
#define CPageWnd__SetTabText_x                                     0x99A4F0
#define CPageWnd__FlashTab_x                                       0x99A550

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4AC4A0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x96D780
#define CTextureFont__GetTextExtent_x                              0x96DA80

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9AC400

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x9596E0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x544310
#define CXStr__CXStr1_x                                            0x482740
#define CXStr__CXStr3_x                                            0x940BF0
#define CXStr__dCXStr_x                                            0x478F50
#define CXStr__operator_equal_x                                    0x940E30
#define CXStr__operator_equal1_x                                   0x940E70
#define CXStr__operator_plus_equal1_x                              0x9418D0
#define CXStr__SetString_x                                         0x943770
#define CXStr__operator_char_p_x                                   0x941320
#define CXStr__GetChar_x                                           0x9430D0
#define CXStr__Delete_x                                            0x9429A0
#define CXStr__GetUnicode_x                                        0x943140
#define CXStr__Insert_x                                            0x9431A0
#define CXStr__FindNext_x                                          0x942DF0
#define CXStr__Copy_x                                              0x9427B0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x992BA0
#define CXWnd__BringToTop_x                                        0x974C50
#define CXWnd__ClrFocus_x                                          0x9745D0
#define CXWnd__Destroy_x                                           0x974680
#define CXWnd__DoAllDrawing_x                                      0x9708D0
//inlined in jan 25 2021 we can probably still call it
#define CXWnd__DrawChildren_x                                      0x9708A0
#define CXWnd__DrawColoredRect_x                                   0x970E60
#define CXWnd__DrawTooltip_x                                       0x96EEA0
#define CXWnd__DrawTooltipAtPoint_x                                0x96EF60
#define CXWnd__GetBorderFrame_x                                    0x970B00
#define CXWnd__GetChildWndAt_x                                     0x974CF0
#define CXWnd__GetClientClipRect_x                                 0x972E10
#define CXWnd__GetScreenClipRect_x                                 0x972EB0
#define CXWnd__GetScreenRect_x                                     0x973060
#define CXWnd__GetRelativeRect_x                                   0x973120
#define CXWnd__GetTooltipRect_x                                    0x970EB0
#define CXWnd__GetWindowTextA_x                                    0x4F2010
#define CXWnd__IsActive_x                                          0x971600
#define CXWnd__IsDescendantOf_x                                    0x973AD0
#define CXWnd__IsReallyVisible_x                                   0x973B00
#define CXWnd__IsType_x                                            0x975460
#define CXWnd__Move_x                                              0x973B60
#define CXWnd__Move1_x                                             0x973C60
#define CXWnd__ProcessTransition_x                                 0x974760
#define CXWnd__Refade_x                                            0x973F30
#define CXWnd__Resize_x                                            0x974200
#define CXWnd__Right_x                                             0x974A40
#define CXWnd__SetFocus_x                                          0x974590
#define CXWnd__SetFont_x                                           0x974600
#define CXWnd__SetKeyTooltip_x                                     0x975230
#define CXWnd__SetMouseOver_x                                      0x971F80
#define CXWnd__StartFade_x                                         0x9739C0
#define CXWnd__GetChildItem_x                                      0x974E70
#define CXWnd__SetParent_x                                         0x973800
#define CXWnd__Minimize_x                                          0x974270

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x9B09A0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x977CC0
#define CXWndManager__DrawWindows_x                                0x977E10
#define CXWndManager__GetKeyboardFlags_x                           0x97A6C0
#define CXWndManager__HandleKeyboardMsg_x                          0x97A2A0
#define CXWndManager__RemoveWnd_x                                  0x97A990
#define CXWndManager__RemovePendingDeletionWnd_x                   0x97AE50

// CDBStr
#define CDBStr__GetString_x                                        0x55A470

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4C56E0
#define EQ_Character__Cur_HP_x                                     0x4D95F0
#define EQ_Character__Cur_Mana_x                                   0x4E1700
#define EQ_Character__GetCastingTimeModifier_x                     0x4C8D50
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B8230
#define EQ_Character__GetFocusRangeModifier_x                      0x4B8380
#define EQ_Character__GetHPRegen_x                                 0x4E8100
#define EQ_Character__GetEnduranceRegen_x                          0x4E86C0
#define EQ_Character__GetManaRegen_x                               0x4E8B00
#define EQ_Character__Max_Endurance_x                              0x681C10
#define EQ_Character__Max_HP_x                                     0x4D9420
#define EQ_Character__Max_Mana_x                                   0x681A00
#define EQ_Character__doCombatAbility_x                            0x684550
#define EQ_Character__UseSkill_x                                   0x4EAB20
#define EQ_Character__GetConLevel_x                                0x679D10
#define EQ_Character__IsExpansionFlag_x                            0x5D34D0
#define EQ_Character__TotalEffect_x                                0x4CD1C0
#define EQ_Character__GetPCSpellAffect_x                           0x4C9B80
#define EQ_Character__SpellDuration_x                              0x4C95C0
#define EQ_Character__MySpellDuration_x                            0x4B68F0
#define EQ_Character__GetAdjustedSkill_x                           0x4DC740
#define EQ_Character__GetBaseSkill_x                               0x4DD6E0
#define EQ_Character__CanUseItem_x                                 0x4E1A30

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x90C7D0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x699660

//PcClient
#define PcClient__vftable_x                                        0xB42C5C
#define PcClient__PcClient_x                                       0x676F80

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BFCF0
#define CCharacterListWnd__EnterWorld_x                            0x4BF6C0
#define CCharacterListWnd__Quit_x                                  0x4BF3E0
#define CCharacterListWnd__UpdateList_x                            0x4BF8B0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6593D0
#define EQ_Item__CreateItemTagString_x                             0x8E5210
#define EQ_Item__IsStackable_x                                     0x8EA330
#define EQ_Item__GetImageNum_x                                     0x8E6F60
#define EQ_Item__CreateItemClient_x                                0x658360
#define EQ_Item__GetItemValue_x                                    0x8E8240
#define EQ_Item__ValueSellMerchant_x                               0x8EC030
#define EQ_Item__IsKeyRingItem_x                                   0x8E9AF0
#define EQ_Item__CanGoInBag_x                                      0x6594F0
#define EQ_Item__IsEmpty_x                                         0x8E9580
#define EQ_Item__GetMaxItemCount_x                                 0x8E8660
#define EQ_Item__GetHeldItem_x                                     0x8E6E20
#define EQ_Item__CanGemFitInSlot_x                                 0x8E49E0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x57AF40
#define EQ_LoadingS__Array_x                                       0xD8FD00

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x682700
#define EQ_PC__GetAlternateAbilityId_x                             0x8F6080
#define EQ_PC__GetCombatAbility_x                                  0x8F6600
#define EQ_PC__GetCombatAbilityTimer_x                             0x8F6670
#define EQ_PC__GetItemRecastTimer_x                                0x684B50
#define EQ_PC__HasLoreItem_x                                       0x67A6D0
#define EQ_PC__AlertInventoryChanged_x                             0x6795D0
#define EQ_PC__GetPcZoneClient_x                                   0x6A9D60
#define EQ_PC__RemoveMyAffect_x                                    0x688070
#define EQ_PC__GetKeyRingItems_x                                   0x8F7100
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8F6C60
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8F7250

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5D9860
#define EQItemList__add_object_x                                   0x609A00
#define EQItemList__add_item_x                                     0x5D9E40
#define EQItemList__delete_item_x                                  0x5D9E90
#define EQItemList__FreeItemList_x                                 0x5D9DA0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x5565E0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x69B090
#define EQPlayer__dEQPlayer_x                                      0x68D930
#define EQPlayer__DoAttack_x                                       0x6A3A90
#define EQPlayer__EQPlayer_x                                       0x68E180
#define EQPlayer__SetNameSpriteState_x                             0x692740
#define EQPlayer__SetNameSpriteTint_x                              0x693610
#define PlayerBase__HasProperty_j_x                                0x9E02C0
#define EQPlayer__IsTargetable_x                                   0x9E0820
#define EQPlayer__CanSee_x                                         0x9E0610
#define EQPlayer__CanSee1_x                                        0x9E06E0
#define PlayerBase__GetVisibilityLineSegment_x                     0x9E0380

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x6A7850
#define PlayerZoneClient__GetLevel_x                               0x6A9DA0
#define PlayerZoneClient__IsValidTeleport_x                        0x60AEA0
#define PlayerZoneClient__LegalPlayerRace_x                        0x572EF0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x69E240
#define EQPlayerManager__GetSpawnByName_x                          0x69E2F0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x69E380

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x65CD80
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x65CE50
#define KeypressHandler__AttachKeyToEqCommand_x                    0x65CE90
#define KeypressHandler__ClearCommandStateArray_x                  0x65E350
#define KeypressHandler__HandleKeyDown_x                           0x65E370
#define KeypressHandler__HandleKeyUp_x                             0x65E410
#define KeypressHandler__SaveKeymapping_x                          0x65E9C0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7B1200
#define MapViewMap__SaveEx_x                                       0x7B473F
#define MapViewMap__SetZoom_x                                      0x7BA380

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x90A660

// StringTable 
#define StringTable__getString_x                                   0x905540

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x687CC0
#define PcZoneClient__RemovePetEffect_x                            0x688320
#define PcZoneClient__HasAlternateAbility_x                        0x681860
#define PcZoneClient__GetCurrentMod_x                              0x4EE2B0
#define PcZoneClient__GetModCap_x                                  0x4EE1B0
#define PcZoneClient__CanEquipItem_x                               0x681F10
#define PcZoneClient__GetItemByID_x                                0x685020
#define PcZoneClient__GetItemByItemClass_x                         0x685160
#define PcZoneClient__RemoveBuffEffect_x                           0x6883D0
#define PcZoneClient__BandolierSwap_x                              0x682CC0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x684AF0

//Doors
#define EQSwitch__UseSwitch_x                                      0x60F9F0

//IconCache
#define IconCache__GetIcon_x                                       0x74AD90

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x741950
#define CContainerMgr__CloseContainer_x                            0x741C30
#define CContainerMgr__OpenExperimentContainer_x                   0x742790

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x8106B0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x651910

//CLootWnd
#define CLootWnd__LootAll_x                                        0x7A6420
#define CLootWnd__RequestLootSlot_x                                0x7A5650

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x5A5480
#define EQ_Spell__SpellAffects_x                                   0x5A5980
#define EQ_Spell__SpellAffectBase_x                                0x5A56A0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4D0BB0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4D0B60
#define EQ_Spell__IsSPAStacking_x                                  0x5A6890
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x5A5CE0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x5A68A0
#define EQ_Spell__IsLullSpell_x                                    0x5A60D0
#define __IsResEffectSpell_x                                       0x4D0360

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4B11F0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x915110

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x85D0F0
#define CTargetWnd__WndNotification_x                              0x85C880
#define CTargetWnd__RefreshTargetBuffs_x                           0x85CBE0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x85B660

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x861C70
#define CTaskWnd__ConfirmAbandonTask_x                             0x864D40

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x554180
#define CTaskManager__HandleMessage_x                              0x552050
#define CTaskManager__GetTaskStatus_x                              0x554230
#define CTaskManager__GetElementDescription_x                      0x5542B0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5A00B0
#define EqSoundManager__PlayScriptMp3_x                            0x5A02B0
#define EqSoundManager__SoundAssistPlay_x                          0x6C4F70
#define EqSoundManager__WaveInstancePlay_x                         0x6C4460

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x543FC0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x999970
#define CTextureAnimation__Draw_x                                  0x999BB0
#define CTextureAnimation__AddBlankFrame_x                         0x999790

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x995690

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x583520
#define CAltAbilityData__GetMercMaxRank_x                          0x5834B0
#define CAltAbilityData__GetMaxRank_x                              0x5778B0

//CTargetRing
#define CTargetRing__Cast_x                                        0x64F120

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x6581B0
#define CharacterBase__CreateItemGlobalIndex_x                     0x645830
//this is a guess testing is needed
#define CharacterBase__GetItemPossession_x                         0x658190
#define CharacterBase__GetItemByGlobalIndex_x                      0x91CC90
#define CharacterBase__GetItemByGlobalIndex1_x                     0x91CCE0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x7267B0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x727070
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x727120

//messages
#define msg_spell_worn_off_x                                       0x5CAE10
#define msg_new_text_x                                             0x5BEBE0
#define __msgTokenTextParam_x                                      0x5CD280
#define msgTokenText_x                                             0x5CD690

//SpellManager
#define SpellManager__vftable_x                                    0xB2D2FC
#define SpellManager__SpellManager_x                               0x6C8BA0
#define Spellmanager__LoadTextSpells_x                             0x6C94A0
#define SpellManager__GetSpellByGroupAndRank_x                     0x6C8D70

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9E4B20

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x5D3520
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5D1A00
#define ItemGlobalIndex__IsEquippedLocation_x                      0x671E60
#define ItemGlobalIndex__IsValidIndex_x                            0x5D36B0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x915B10
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x915E60

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x79E560

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x746640
#define CCursorAttachment__AttachToCursor1_x                       0x746680
#define CCursorAttachment__Deactivate_x                            0x747C10

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x98B2B0
#define CSidlManagerBase__CreatePageWnd_x                          0x98AAA0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x985F70
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x985F00

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9AAFD0
#define CEQSuiteTextureLoader__GetTexture_x                        0x9AAC50

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x5242B0
#define CFindItemWnd__WndNotification_x                            0x525170
#define CFindItemWnd__Update_x                                     0x525D30
#define CFindItemWnd__PickupSelectedItem_x                         0x5239B0

//IString
#define IString__Append_x                                          0x513580

//Camera
#define CDisplay__cameraType_x                                     0xED4210
#define EverQuest__Cameras_x                                       0xDA3438

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x52EE20
#define LootFiltersManager__GetItemFilterData_x                    0x52E760
#define LootFiltersManager__RemoveItemLootFilter_x                 0x52E790
#define LootFiltersManager__SetItemLootFilter_x                    0x52E9A0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7FD1C0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9EA7E0
#define CResolutionHandler__GetWindowedStyle_x                     0x6BF3F0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x73E2D0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x921010
#define CDistillerInfo__Instance_x                                 0x920F50

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x760F40
#define CGroupWnd__UpdateDisplay_x                                 0x760190

//ItemBase
#define ItemBase__IsLore_x                                         0x8E9B90
#define ItemBase__IsLoreEquipped_x                                 0x8E9C10

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x609960
#define EQPlacedItemManager__GetItemByGuid_x                       0x609AA0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x609B00

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6B3B20
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x6B8410

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x519D60

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x504AF0
#define FactionManagerClient__HandleFactionMessage_x               0x505310
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x505B30
#define FactionManagerClient__GetMaxFaction_x                      0x505B4F
#define FactionManagerClient__GetMinFaction_x                      0x505B00

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x511710

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x96C3F0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49DEF0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x511980

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x5826E0

//CTargetManager
#define CTargetManager__Get_x                                      0x6CCB20

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6B3B20

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4AC260

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5D9D40

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xE40ACC

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6EA2A0
#define CAAWnd__UpdateSelected_x                                   0x6E6930
#define CAAWnd__Update_x                                           0x6E95C0

//CXRect
#define CXRect__operator_and_x                                     0x756430

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x47D230

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

