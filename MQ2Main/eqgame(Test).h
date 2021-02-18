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
#define __ExpectedVersionDate                                     "Feb  9 2021"
#define __ExpectedVersionTime                                     "10:04:53"
#define __ActualVersionDate_x                                      0xB45EE4
#define __ActualVersionTime_x                                      0xB45ED8
#define __ActualVersionBuild_x                                     0xB360C4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x663C40
#define __MemChecker1_x                                            0x944EF0
#define __MemChecker2_x                                            0x6DDC30
#define __MemChecker3_x                                            0x6DDBA0
#define __MemChecker4_x                                            0x898130
#define __EncryptPad0_x                                            0xE46F40
#define __EncryptPad1_x                                            0xEA1740
#define __EncryptPad2_x                                            0xE56158
#define __EncryptPad3_x                                            0xE55D58
#define __EncryptPad4_x                                            0xE92550
#define __EncryptPad5_x                                            0xF95020
#define __AC1_x                                                    0x852D90
#define __AC2_x                                                    0x618B0F
#define __AC3_x                                                    0x61FEF1
#define __AC4_x                                                    0x624060
#define __AC5_x                                                    0x62A91F
#define __AC6_x                                                    0x62F066
#define __AC7_x                                                    0x618570
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
#define __do_loot_x                                                0x5E1660
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
#define __CastRay_x                                                0x5DC920
//it has no refs but we can possibly call it still 
#define __CastRay2_x                                               0x5DCBB0
#define __ConvertItemTags_x                                        0x5F9C00
#define __CleanItemTags_x                                          0x47DA80
#define __DoesFileExist_x                                          0x947E80
#define __EQGetTime_x                                              0x944B60
#define __ExecuteCmd_x                                             0x5D4E00
#define __FixHeading_x                                             0x9E17F0
#define __FlushDxKeyboard_x                                        0x6D8F30
#define __GameLoop_x                                               0x6DC830
#define __get_bearing_x                                            0x5DC4C0
#define __get_melee_range_x                                        0x5DCDF0
#define __GetAnimationCache_x                                      0x74B410
#define __GetGaugeValueFromEQ_x                                    0x8511D0
#define __GetLabelFromEQ_x                                         0x852D10
#define __GetXTargetType_x                                         0x9E3B60
#define __HandleMouseWheel_x                                       0x6DDCC0
#define __HeadingDiff_x                                            0x9E1850
#define __HelpPath_x                                               0xF8DCFC
#define __ExecuteFrontEnd_x                                        0x6D9710
#define __NewUIINI_x                                               0x850EA0
#define __ProcessGameEvents_x                                      0x642D40
#define __ProcessMouseEvent_x                                      0x642440
#define __SaveColors_x                                             0x571090
#define __STMLToText_x                                             0x97F560
#define __ToggleKeyRingItem_x                                      0x52A850
#define CMemoryMappedFile__SetFile_x                               0xAD1F70
#define CrashDetected_x                                            0x6DB440
#define DrawNetStatus_x                                            0x6721F0
#define Expansion_HoT_x                                            0xDA30E0
#define Teleport_Table_Size_x                                      0xF884E0
#define Teleport_Table_x                                           0xF860B8
#define Util__FastTime_x                                           0x944720
#define __CopyLayout_x                                             0x65EED0
#define __WndProc_x                                                0x6DB940
#define __ProcessKeyboardEvent_x                                   0x6DAE80

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4919C0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x49B180
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x49B000
#define CAdvancedLootWnd__AddPlayerToList_x                        0x495700
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x494940

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x57A090
#define AltAdvManager__IsAbilityReady_x                            0x578C80
#define AltAdvManager__GetAAById_x                                 0x579020
#define AltAdvManager__CanTrainAbility_x                           0x579090
#define AltAdvManager__CanSeeAbility_x                             0x579420

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4D11A0
#define CharacterZoneClient__HasSkill_x                            0x4DC910
#define CharacterZoneClient__MakeMeVisible_x                       0x4DE050
#define CharacterZoneClient__IsStackBlocked_x                      0x4C85D0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4C0D90
#define CharacterZoneClient__GetItemCountWorn_x                    0x4E0F60
#define CharacterZoneClient__GetItemCountInInventory_x             0x4E1060
#define CharacterZoneClient__GetCursorItemCount_x                  0x4E1160
#define CharacterZoneClient__FindAffectSlot_x                      0x4CA810
#define CharacterZoneClient__BardCastBard_x                        0x4CD820
#define CharacterZoneClient__GetMaxEffects_x                       0x4C4CD0
#define CharacterZoneClient__GetEffect_x                           0x4C0CD0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4CBE20
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4CBED0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4CBF70
#define CharacterZoneClient__CalcAffectChange_x                    0x4CC130
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4CC310
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B85B0
#define CharacterZoneClient__FindItemByGuid_x                      0x4DF1F0
#define CharacterZoneClient__FindItemByRecord_x                    0x4DEB40

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x7068E0
#define CBankWnd__WndNotification_x                                0x706680

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x715930

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x97CB00
#define CButtonWnd__CButtonWnd_x                                   0x97B4B0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x738BC0
#define CChatManager__InitContextMenu_x                            0x731AA0
#define CChatManager__FreeChatWindow_x                             0x737790
//inlined since jan 25 2021 test exe see 4EFED5
//#define CChatManager__GetLockedActiveChatWindow_x                  0x0
#define CChatManager__SetLockedActiveChatWindow_x                  0x7388A0
#define CChatManager__CreateChatWindow_x                           0x737DB0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4F1FD0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x992950
#define CContextMenu__dCContextMenu_x                              0x992B80
#define CContextMenu__AddMenuItem_x                                0x992B90
#define CContextMenu__RemoveMenuItem_x                             0x992E90
#define CContextMenu__RemoveAllMenuItems_x                         0x992EB0
#define CContextMenu__CheckMenuItem_x                              0x992F10
#define CContextMenu__SetMenuItem_x                                0x992DC0
#define CContextMenu__AddSeparator_x                               0x992D20

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x9934A0
#define CContextMenuManager__RemoveMenu_x                          0x993510
#define CContextMenuManager__PopupMenu_x                           0x9935D0
#define CContextMenuManager__Flush_x                               0x993440
#define CContextMenuManager__GetMenu_x                             0x49D4B0
#define CContextMenuManager__CreateDefaultMenu_x                   0x7453F0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x91F280
#define CChatService__GetFriendName_x                              0x91F290

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x739520
#define CChatWindow__Clear_x                                       0x73A970
#define CChatWindow__WndNotification_x                             0x73B0F0
#define CChatWindow__AddHistory_x                                  0x73A1D0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x98F990
#define CComboWnd__Draw_x                                          0x98EE40
#define CComboWnd__GetCurChoice_x                                  0x98F760
#define CComboWnd__GetListRect_x                                   0x98F2E0
#define CComboWnd__GetTextRect_x                                   0x98F9F0
#define CComboWnd__InsertChoice_x                                  0x98F470
#define CComboWnd__SetColors_x                                     0x98F440
#define CComboWnd__SetChoice_x                                     0x98F740
#define CComboWnd__GetItemCount_x                                  0x98F770
#define CComboWnd__GetCurChoiceText_x                              0x98F7A0
#define CComboWnd__GetChoiceText_x                                 0x98F780
#define CComboWnd__InsertChoiceAtIndex_x                           0x98F500

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x742A70
#define CContainerWnd__vftable_x                                   0xB4F104
#define CContainerWnd__SetContainer_x                              0x7442C0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x56BC60
#define CDisplay__PreZoneMainUI_x                                  0x56BC70
#define CDisplay__CleanGameUI_x                                    0x570E70
#define CDisplay__GetClickedActor_x                                0x563B40
#define CDisplay__GetUserDefinedColor_x                            0x55B8B0
//well they inlined it in jan 25 2021 test but the function is still left in exe so for now we can probably just call it...
#define CDisplay__GetWorldFilePath_x                               0x565650
#define CDisplay__is3dON_x                                         0x5603D0
#define CDisplay__ReloadUI_x                                       0x56AF80
#define CDisplay__WriteTextHD2_x                                   0x5601C0
#define CDisplay__TrueDistance_x                                   0x567520
#define CDisplay__SetViewActor_x                                   0x563460
#define CDisplay__GetFloorHeight_x                                 0x560490
#define CDisplay__SetRenderWindow_x                                0x55EE10
#define CDisplay__ToggleScreenshotMode_x                           0x562F30

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x9B5050

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x996440
#define CEditWnd__EnsureCaretVisible_x                             0x998790
#define CEditWnd__GetCaretPt_x                                     0x997600
#define CEditWnd__GetCharIndexPt_x                                 0x9973C0
#define CEditWnd__GetDisplayString_x                               0x997260
#define CEditWnd__GetHorzOffset_x                                  0x9959A0
#define CEditWnd__GetLineForPrintableChar_x                        0x9986A0
#define CEditWnd__GetSelStartPt_x                                  0x997660
#define CEditWnd__GetSTMLSafeText_x                                0x997070
#define CEditWnd__PointFromPrintableChar_x                         0x9982F0
#define CEditWnd__SelectableCharFromPoint_x                        0x998450
#define CEditWnd__SetEditable_x                                    0x997730
#define CEditWnd__SetWindowTextA_x                                 0x996DC0
#define CEditWnd__ReplaceSelection_x                               0x997EB0
#define CEditWnd__ReplaceSelection1_x                              0x997E30

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x62E6E0
#define CEverQuest__ClickedPlayer_x                                0x61FCD0
#define CEverQuest__CreateTargetIndicator_x                        0x63FCC0
#define CEverQuest__DeleteTargetIndicator_x                        0x63FD50
#define CEverQuest__DoTellWindow_x                                 0x4F20D0
#define CEverQuest__OutputTextToLog_x                              0x4F23A0
#define CEverQuest__DropHeldItemOnGround_x                         0x614CC0
#define CEverQuest__dsp_chat_x                                     0x4F2730
#define CEverQuest__trimName_x                                     0x63B4C0
#define CEverQuest__Emote_x                                        0x62EDA0
#define CEverQuest__EnterZone_x                                    0x628AE0
#define CEverQuest__GetBodyTypeDesc_x                              0x634200
#define CEverQuest__GetClassDesc_x                                 0x634840
#define CEverQuest__GetClassThreeLetterCode_x                      0x634E40
#define CEverQuest__GetDeityDesc_x                                 0x63E470
#define CEverQuest__GetLangDesc_x                                  0x635000
#define CEverQuest__GetRaceDesc_x                                  0x634820
#define CEverQuest__InterpretCmd_x                                 0x63EAE0
#define CEverQuest__LeftClickedOnPlayer_x                          0x619240
#define CEverQuest__LMouseUp_x                                     0x617270
#define CEverQuest__RightClickedOnPlayer_x                         0x619E30
#define CEverQuest__RMouseUp_x                                     0x618530
#define CEverQuest__SetGameState_x                                 0x614A40
#define CEverQuest__UPCNotificationFlush_x                         0x63B3E0
#define CEverQuest__IssuePetCommand_x                              0x636600
#define CEverQuest__ReportSuccessfulHit_x                          0x6306B0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x756390
#define CGaugeWnd__CalcLinesFillRect_x                             0x7563F0
#define CGaugeWnd__Draw_x                                          0x7559A0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4B43F0
#define CGuild__GetGuildName_x                                     0x4B2C10
#define CGuild__GetGuildIndex_x                                    0x4B3330

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x7737F0

//CHotButton
#define CHotButton__SetCheck_x                                     0x653330
#define CHotButton__SetButtonSize_x                                0x6536F0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x7807E0
#define CInvSlotMgr__MoveItem_x                                    0x77F3B0
#define CInvSlotMgr__SelectSlot_x                                  0x7808A0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x77DC00
#define CInvSlot__SliderComplete_x                                 0x77B0E0
#define CInvSlot__GetItemBase_x                                    0x77A9A0
#define CInvSlot__UpdateItem_x                                     0x77AB90

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7824F0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7816C0
#define CInvSlotWnd__HandleLButtonUp_x                             0x782070

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x84B4D0
#define CItemDisplayWnd__UpdateStrings_x                           0x7915A0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x78AFE0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x78B550
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x791BA0
#define CItemDisplayWnd__AboutToShow_x                             0x791200
#define CItemDisplayWnd__WndNotification_x                         0x793100
#define CItemDisplayWnd__RequestConvertItem_x                      0x7929D0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x790220
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x791020

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8806C0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x797A80

// CLabel 
#define CLabel__UpdateText_x                                       0x79E1A0

// CListWnd
#define CListWnd__CListWnd_x                                       0x9636C0
#define CListWnd__dCListWnd_x                                      0x9639B0
#define CListWnd__AddColumn_x                                      0x9683C0
#define CListWnd__AddColumn1_x                                     0x9684E0
#define CListWnd__AddLine_x                                        0x968850
#define CListWnd__AddString_x                                      0x968650
#define CListWnd__CalculateFirstVisibleLine_x                      0x968170
#define CListWnd__CalculateVSBRange_x                              0x967F60
#define CListWnd__ClearSel_x                                       0x969140
#define CListWnd__ClearAllSel_x                                    0x969190
#define CListWnd__CloseAndUpdateEditWindow_x                       0x969C20
#define CListWnd__Compare_x                                        0x967890
#define CListWnd__Draw_x                                           0x963B70
#define CListWnd__DrawColumnSeparators_x                           0x966680
#define CListWnd__DrawHeader_x                                     0x966AE0
#define CListWnd__DrawItem_x                                       0x967130
#define CListWnd__DrawLine_x                                       0x9667F0
#define CListWnd__DrawSeparator_x                                  0x966720
#define CListWnd__EnableLine_x                                     0x965F40
#define CListWnd__EnsureVisible_x                                  0x969B50
//no references in jan 25 2021 test exe we can probably still call it
#define CListWnd__ExtendSel_x                                      0x969080
#define CListWnd__GetColumnTooltip_x                               0x965AC0
#define CListWnd__GetColumnMinWidth_x                              0x965B30
#define CListWnd__GetColumnWidth_x                                 0x965A40
#define CListWnd__GetCurSel_x                                      0x9653F0
#define CListWnd__GetItemAtPoint_x                                 0x9661B0
//no references in jan 25 2021 test exe we can probably still call it
#define CListWnd__GetItemAtPoint1_x                                0x966220
#define CListWnd__GetItemData_x                                    0x965470
#define CListWnd__GetItemHeight_x                                  0x965810
#define CListWnd__GetItemIcon_x                                    0x9655F0
#define CListWnd__GetItemRect_x                                    0x966030
#define CListWnd__GetItemText_x                                    0x9654B0
#define CListWnd__GetSelList_x                                     0x9691E0
#define CListWnd__GetSeparatorRect_x                               0x966490
#define CListWnd__InsertLine_x                                     0x968CB0
#define CListWnd__RemoveLine_x                                     0x968ED0
#define CListWnd__SetColors_x                                      0x967F30
#define CListWnd__SetColumnJustification_x                         0x967C60
#define CListWnd__SetColumnLabel_x                                 0x9685F0
#define CListWnd__SetColumnWidth_x                                 0x967B70
#define CListWnd__SetCurSel_x                                      0x968FD0
#define CListWnd__SetItemColor_x                                   0x969820
#define CListWnd__SetItemData_x                                    0x9697E0
#define CListWnd__SetItemText_x                                    0x969400
#define CListWnd__ShiftColumnSeparator_x                           0x967D20
#define CListWnd__Sort_x                                           0x967A20
#define CListWnd__ToggleSel_x                                      0x969000
#define CListWnd__SetColumnsSizable_x                              0x967DC0
#define CListWnd__SetItemWnd_x                                     0x9696A0
#define CListWnd__GetItemWnd_x                                     0x965640
#define CListWnd__SetItemIcon_x                                    0x969480
#define CListWnd__CalculateCustomWindowPositions_x                 0x968270
#define CListWnd__SetVScrollPos_x                                  0x967B50

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7B5530
#define CMapViewWnd__GetWorldCoordinates_x                         0x7B3B50
#define CMapViewWnd__HandleLButtonDown_x                           0x7B09E0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7D8760
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7D90C0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7D9710
#define CMerchantWnd__SelectRecoverySlot_x                         0x7DC900
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7D71F0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7E2AA0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7D83B0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8EC200
#define CPacketScrambler__hton_x                                   0x8EC1F0

// CSidlManagerbase we should rename at some point
#define CSidlManager__FindAnimation1_x                             0x985BA0
#define CSidlManager__FindScreenPieceTemplate_x                    0x985F70
#define CSidlManager__FindScreenPieceTemplate1_x                   0x985DA0
#define CSidlManager__CreateXWndFromTemplate_x                     0x989420
#define CSidlManager__CreateXWndFromTemplate1_x                    0x9896B0
#define CSidlManagerbase__CreateXWnd_x                             0x9896F0

//inlined since jan 25 2021 test but they left the function intact
#define CSidlManager__CreateHotButtonWnd_x                         0x841620
#define CSidlManager__CreateLabel_x                                0x8411F0

//CSidlManager
#define CSidlManager__CreateXWnd_x                                 0x840C70

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9818E0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9817E0
#define CSidlScreenWnd__ConvertToRes_x                             0x9AF2A0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x981160
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x980E50
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x980F20
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x980FF0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x982180
#define CSidlScreenWnd__EnableIniStorage_x                         0x982660
#define CSidlScreenWnd__GetSidlPiece_x                             0x982370
#define CSidlScreenWnd__Init1_x                                    0x980930
#define CSidlScreenWnd__LoadIniInfo_x                              0x9826B0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x983290
#define CSidlScreenWnd__LoadSidlScreen_x                           0x97FD40
#define CSidlScreenWnd__StoreIniInfo_x                             0x982E00
#define CSidlScreenWnd__StoreIniVis_x                              0x983180
#define CSidlScreenWnd__WndNotification_x                          0x982050
#define CSidlScreenWnd__GetChildItem_x                             0x9825E0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x970C70
#define CSidlScreenWnd__m_layoutCopy_x                             0x1613868

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6C0BE0
#define CSkillMgr__GetSkillCap_x                                   0x6C0DB0
#define CSkillMgr__GetNameToken_x                                  0x6C0420
#define CSkillMgr__IsActivatedSkill_x                              0x6C0510
#define CSkillMgr__IsCombatSkill_x                                 0x6C0480

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9945A0
#define CSliderWnd__SetValue_x                                     0x9943D0
#define CSliderWnd__SetNumTicks_x                                  0x994430

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x847EA0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x99D9B0
#define CStmlWnd__ParseSTML_x                                      0x99EB60
#define CStmlWnd__CalculateHSBRange_x                              0x99E930
#define CStmlWnd__CalculateVSBRange_x                              0x99E8A0
#define CStmlWnd__CanBreakAtCharacter_x                            0x9A3760
#define CStmlWnd__FastForwardToEndOfTag_x                          0x9A4400
#define CStmlWnd__ForceParseNow_x                                  0x99DF20
#define CStmlWnd__GetNextTagPiece_x                                0x9A36C0
//cant find its inlined in jan 25 2021 test
//#define CStmlWnd__GetSTMLText_x                                    0x0
#define CStmlWnd__GetVisibleText_x                                 0x99DF40
#define CStmlWnd__InitializeWindowVariables_x                      0x9A4250
#define CStmlWnd__MakeStmlColorTag_x                               0x99D050
#define CStmlWnd__MakeWndNotificationTag_x                         0x99D0C0
#define CStmlWnd__SetSTMLText_x                                    0x99BE30
#define CStmlWnd__StripFirstSTMLLines_x                            0x9A5620
#define CStmlWnd__UpdateHistoryString_x                            0x9A4600

// CTabWnd 
#define CTabWnd__Draw_x                                            0x99AD80
#define CTabWnd__DrawCurrentPage_x                                 0x99B710
#define CTabWnd__DrawTab_x                                         0x99B300
#define CTabWnd__GetCurrentPage_x                                  0x99A4F0
#define CTabWnd__GetPageInnerRect_x                                0x99A720
#define CTabWnd__GetTabInnerRect_x                                 0x99A660
#define CTabWnd__GetTabRect_x                                      0x99A520
#define CTabWnd__InsertPage_x                                      0x99A910
#define CTabWnd__RemovePage_x                                      0x99AA50
#define CTabWnd__SetPage_x                                         0x99A7A0
//inlined but we can probably call it jan 25 2021
#define CTabWnd__SetPageRect_x                                     0x99AC80
#define CTabWnd__UpdatePage_x                                      0x99B0F0
#define CTabWnd__GetPageFromTabIndex_x                             0x99B240
#define CTabWnd__GetCurrentTabIndex_x                              0x99A4E0

// CPageWnd
//inlined in Jan 25 2021 test
//#define CPageWnd__GetTabText_x                                     0x479340
#define CPageWnd__SetTabText_x                                     0x999E90
#define CPageWnd__FlashTab_x                                       0x999EF0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4AC490

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x96D1A0
#define CTextureFont__GetTextExtent_x                              0x96D4A0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9ABD40

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x959170

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x544280
#define CXStr__CXStr1_x                                            0x482750
#define CXStr__CXStr3_x                                            0x940AB0
#define CXStr__dCXStr_x                                            0x478F60
#define CXStr__operator_equal_x                                    0x940CF0
#define CXStr__operator_equal1_x                                   0x940D30
#define CXStr__operator_plus_equal1_x                              0x941790
#define CXStr__SetString_x                                         0x943630
#define CXStr__operator_char_p_x                                   0x9411E0
#define CXStr__GetChar_x                                           0x942F90
#define CXStr__Delete_x                                            0x942860
#define CXStr__GetUnicode_x                                        0x943000
//inlined in jan 25 2021 test
//#define CXStr__GetLength_x                                         0x0
//inlined in jan 25 2021 test
//#define CXStr__Mid_x                                               0x0
#define CXStr__Insert_x                                            0x943060
#define CXStr__FindNext_x                                          0x942CB0
#define CXStr__Copy_x                                              0x942670

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x9925B0we dont call it but better check anyway changed in jan 25 2021
#define CXWnd__BringToTop_x                                        0x974680
//inlined in jan 25 2021
//#define CXWnd__Center_x                                            0x0
#define CXWnd__ClrFocus_x                                          0x974010
#define CXWnd__Destroy_x                                           0x9740B0
#define CXWnd__DoAllDrawing_x                                      0x9702F0
//inlined in jan 25 2021 we can probably still call it
#define CXWnd__DrawChildren_x                                      0x9702C0
#define CXWnd__DrawColoredRect_x                                   0x970860
#define CXWnd__DrawTooltip_x                                       0x96E8B0
#define CXWnd__DrawTooltipAtPoint_x                                0x96E970
#define CXWnd__GetBorderFrame_x                                    0x970500
#define CXWnd__GetChildWndAt_x                                     0x974720
#define CXWnd__GetClientClipRect_x                                 0x972840
#define CXWnd__GetScreenClipRect_x                                 0x972910
#define CXWnd__GetScreenRect_x                                     0x972AD0
#define CXWnd__GetRelativeRect_x                                   0x972B90
#define CXWnd__GetTooltipRect_x                                    0x9708B0
#define CXWnd__GetWindowTextA_x                                    0x4F1F70
#define CXWnd__IsActive_x                                          0x970FD0
#define CXWnd__IsDescendantOf_x                                    0x973530
#define CXWnd__IsReallyVisible_x                                   0x973560
#define CXWnd__IsType_x                                            0x974E80
#define CXWnd__Move_x                                              0x9735D0
#define CXWnd__Move1_x                                             0x9736D0
#define CXWnd__ProcessTransition_x                                 0x974190
#define CXWnd__Refade_x                                            0x973990
#define CXWnd__Resize_x                                            0x973C30
#define CXWnd__Right_x                                             0x974470
#define CXWnd__SetFocus_x                                          0x973FD0
#define CXWnd__SetFont_x                                           0x974040
#define CXWnd__SetKeyTooltip_x                                     0x974C50
#define CXWnd__SetMouseOver_x                                      0x971930
#define CXWnd__StartFade_x                                         0x905440
#define CXWnd__GetChildItem_x                                      0x974890
#define CXWnd__SetParent_x                                         0x973260
#define CXWnd__Minimize_x                                          0x973CA0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x9B02F0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x977690
#define CXWndManager__DrawWindows_x                                0x9777E0
#define CXWndManager__GetKeyboardFlags_x                           0x97A0F0
#define CXWndManager__HandleKeyboardMsg_x                          0x979CE0
#define CXWndManager__RemoveWnd_x                                  0x97A3B0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x97A860

// CDBStr
#define CDBStr__GetString_x                                        0x55A3E0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4C5650
#define EQ_Character__Cur_HP_x                                     0x4D9580
#define EQ_Character__Cur_Mana_x                                   0x4E1690
#define EQ_Character__GetCastingTimeModifier_x                     0x4C8CC0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B81C0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B8310
#define EQ_Character__GetHPRegen_x                                 0x4E8090
#define EQ_Character__GetEnduranceRegen_x                          0x4E8650
#define EQ_Character__GetManaRegen_x                               0x4E8A90
#define EQ_Character__Max_Endurance_x                              0x681D60
#define EQ_Character__Max_HP_x                                     0x4D93B0
#define EQ_Character__Max_Mana_x                                   0x681B50
#define EQ_Character__doCombatAbility_x                            0x6846A0
#define EQ_Character__UseSkill_x                                   0x4EAAA0
#define EQ_Character__GetConLevel_x                                0x679E60
#define EQ_Character__IsExpansionFlag_x                            0x5D3620
#define EQ_Character__TotalEffect_x                                0x4CD130
#define EQ_Character__GetPCSpellAffect_x                           0x4C9AF0
#define EQ_Character__SpellDuration_x                              0x4C9530
#define EQ_Character__MySpellDuration_x                            0x4B6880
#define EQ_Character__GetAdjustedSkill_x                           0x4DC6D0
#define EQ_Character__GetBaseSkill_x                               0x4DD670
#define EQ_Character__CanUseItem_x                                 0x4E19C0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x90C6D0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x6997B0

//PcClient
#define PcClient__vftable_x                                        0xB42C5C
#define PcClient__PcClient_x                                       0x6770D0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BFC50
#define CCharacterListWnd__EnterWorld_x                            0x4BF620
#define CCharacterListWnd__Quit_x                                  0x4BF340
#define CCharacterListWnd__UpdateList_x                            0x4BF810

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x659530
#define EQ_Item__CreateItemTagString_x                             0x8E5190
#define EQ_Item__IsStackable_x                                     0x8EA250
#define EQ_Item__GetImageNum_x                                     0x8E6F00
#define EQ_Item__CreateItemClient_x                                0x6584E0
#define EQ_Item__GetItemValue_x                                    0x8E81B0
#define EQ_Item__ValueSellMerchant_x                               0x8EBF30
#define EQ_Item__IsKeyRingItem_x                                   0x8E9A20
#define EQ_Item__CanGoInBag_x                                      0x659650
#define EQ_Item__IsEmpty_x                                         0x8E94C0
#define EQ_Item__GetMaxItemCount_x                                 0x8E85C0
#define EQ_Item__GetHeldItem_x                                     0x8E6DC0
#define EQ_Item__CanGemFitInSlot_x                                 0x8E4960

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x57AE90
#define EQ_LoadingS__Array_x                                       0xD8FD00

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x682850
#define EQ_PC__GetAlternateAbilityId_x                             0x8F5F80
#define EQ_PC__GetCombatAbility_x                                  0x8F6500
#define EQ_PC__GetCombatAbilityTimer_x                             0x8F6570
#define EQ_PC__GetItemRecastTimer_x                                0x684CA0
#define EQ_PC__HasLoreItem_x                                       0x67A820
#define EQ_PC__AlertInventoryChanged_x                             0x679720
#define EQ_PC__GetPcZoneClient_x                                   0x6A9EB0
#define EQ_PC__RemoveMyAffect_x                                    0x6881C0
#define EQ_PC__GetKeyRingItems_x                                   0x8F7000
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8F6B60
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8F7150

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5D99E0
#define EQItemList__add_object_x                                   0x609B40
#define EQItemList__add_item_x                                     0x5D9FC0
#define EQItemList__delete_item_x                                  0x5DA010
#define EQItemList__FreeItemList_x                                 0x5D9F20

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x556520

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x69B1E0
#define EQPlayer__dEQPlayer_x                                      0x68DA80
#define EQPlayer__DoAttack_x                                       0x6A3BE0
#define EQPlayer__EQPlayer_x                                       0x68E2D0
#define EQPlayer__SetNameSpriteState_x                             0x6928A0
#define EQPlayer__SetNameSpriteTint_x                              0x693760
#define PlayerBase__HasProperty_j_x                                0x9DFBA0
#define EQPlayer__IsTargetable_x                                   0x9E0100
#define EQPlayer__CanSee_x                                         0x9DFEF0
#define EQPlayer__CanSee1_x                                        0x9DFFC0
#define PlayerBase__GetVisibilityLineSegment_x                     0x9DFC60

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x6A79A0
#define PlayerZoneClient__GetLevel_x                               0x6A9EF0
#define PlayerZoneClient__IsValidTeleport_x                        0x60AFF0
#define PlayerZoneClient__LegalPlayerRace_x                        0x572E50

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x69E380
#define EQPlayerManager__GetSpawnByName_x                          0x69E430
#define EQPlayerManager__GetPlayerFromPartialName_x                0x69E4C0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x65CE90
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x65CF60
#define KeypressHandler__AttachKeyToEqCommand_x                    0x65CFA0
#define KeypressHandler__ClearCommandStateArray_x                  0x65E460
#define KeypressHandler__HandleKeyDown_x                           0x65E480
#define KeypressHandler__HandleKeyUp_x                             0x65E520
#define KeypressHandler__SaveKeymapping_x                          0x65EAD0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7B11E0
#define MapViewMap__SaveEx_x                                       0x7B471F
#define MapViewMap__SetZoom_x                                      0x7BA350

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x90A560

// StringTable 
#define StringTable__getString_x                                   0x905440

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x687E10
#define PcZoneClient__RemovePetEffect_x                            0x688470
#define PcZoneClient__HasAlternateAbility_x                        0x6819B0
#define PcZoneClient__GetCurrentMod_x                              0x4EE220
#define PcZoneClient__GetModCap_x                                  0x4EE120
#define PcZoneClient__CanEquipItem_x                               0x682060
#define PcZoneClient__GetItemByID_x                                0x685170
#define PcZoneClient__GetItemByItemClass_x                         0x6852B0
#define PcZoneClient__RemoveBuffEffect_x                           0x688520
#define PcZoneClient__BandolierSwap_x                              0x682E10
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x684C40

//Doors
#define EQSwitch__UseSwitch_x                                      0x60FB40

//IconCache
#define IconCache__GetIcon_x                                       0x74ADB0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x741980
#define CContainerMgr__CloseContainer_x                            0x741C60
#define CContainerMgr__OpenExperimentContainer_x                   0x7427C0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x8106D0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x651A80

//CLootWnd
#define CLootWnd__LootAll_x                                        0x7A6480
#define CLootWnd__RequestLootSlot_x                                0x7A56B0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x5A53E0
#define EQ_Spell__SpellAffects_x                                   0x5A58E0
#define EQ_Spell__SpellAffectBase_x                                0x5A5600
//inlined in jan 25 2021 test
//#define EQ_Spell__IsStackable_x                                    0x0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4D0B20
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4D0AD0
#define EQ_Spell__IsSPAStacking_x                                  0x5A67F0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x5A5C40
//inlined in jan 25 2021 test
//#define EQ_Spell__IsNoRemove_x                                     0x0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x5A6800
#define EQ_Spell__IsLullSpell_x                                    0x5A6030
#define __IsResEffectSpell_x                                       0x4D02D0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4B11B0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x914FF0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x85D0D0
#define CTargetWnd__WndNotification_x                              0x85C860
#define CTargetWnd__RefreshTargetBuffs_x                           0x85CBC0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x85B660

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x861C30
#define CTaskWnd__ConfirmAbandonTask_x                             0x864CE0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x5540E0
#define CTaskManager__HandleMessage_x                              0x551FB0
#define CTaskManager__GetTaskStatus_x                              0x554190
#define CTaskManager__GetElementDescription_x                      0x554210

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5A0010
#define EqSoundManager__PlayScriptMp3_x                            0x5A0210
#define EqSoundManager__SoundAssistPlay_x                          0x6C50A0
#define EqSoundManager__WaveInstancePlay_x                         0x6C4590

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x543F30

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x999320
#define CTextureAnimation__Draw_x                                  0x999560
#define CTextureAnimation__AddBlankFrame_x                         0x999140

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x995080

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x583450
#define CAltAbilityData__GetMercMaxRank_x                          0x5833E0
#define CAltAbilityData__GetMaxRank_x                              0x5777F0

//CTargetRing
#define CTargetRing__Cast_x                                        0x64F290

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x658330
#define CharacterBase__CreateItemGlobalIndex_x                     0x6459B0
//inlined in jan 25 2021 test we can call 4F6AE0 directly i guess
//#define CharacterBase__CreateItemIndex_x                           0x0
//this is a guess testing is needed
#define CharacterBase__GetItemPossession_x                         0x658310
#define CharacterBase__GetItemByGlobalIndex_x                      0x91CB70
#define CharacterBase__GetItemByGlobalIndex1_x                     0x91CBC0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x726820
#define CCastSpellWnd__IsBardSongPlaying_x                         0x7270E0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x727190

//messages
#define msg_spell_worn_off_x                                       0x5CAF60
#define msg_new_text_x                                             0x5BED50
#define __msgTokenTextParam_x                                      0x5CD3D0
#define msgTokenText_x                                             0x5CD7E0

//SpellManager
#define SpellManager__vftable_x                                    0xB2D2FC
#define SpellManager__SpellManager_x                               0x6C8CD0
#define Spellmanager__LoadTextSpells_x                             0x6C95D0
#define SpellManager__GetSpellByGroupAndRank_x                     0x6C8EA0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9E4410

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x5D3670
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5D1B40
#define ItemGlobalIndex__IsEquippedLocation_x                      0x671F90
#define ItemGlobalIndex__IsValidIndex_x                            0x5D3800

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x9159F0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x915D40

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x79E610

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x746670
#define CCursorAttachment__AttachToCursor1_x                       0x7466B0
#define CCursorAttachment__Deactivate_x                            0x747C40

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x98AC40
#define CSidlManagerBase__CreatePageWnd_x                          0x98A440
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x985920
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x9858B0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9AA910
#define CEQSuiteTextureLoader__GetTexture_x                        0x9AA590

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x524200
#define CFindItemWnd__WndNotification_x                            0x5250B0
#define CFindItemWnd__Update_x                                     0x525C90
#define CFindItemWnd__PickupSelectedItem_x                         0x523900

//IString
#define IString__Append_x                                          0x513500

//Camera
#define CDisplay__cameraType_x                                     0xED4210
#define EverQuest__Cameras_x                                       0xDA3438

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x52ED80
#define LootFiltersManager__GetItemFilterData_x                    0x52E6C0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x52E6F0
#define LootFiltersManager__SetItemLootFilter_x                    0x52E900

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7FD1C0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9EA0D0
#define CResolutionHandler__GetWindowedStyle_x                     0x6BF530

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x73E320

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x920EF0
#define CDistillerInfo__Instance_x                                 0x920E30

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x760FA0
#define CGroupWnd__UpdateDisplay_x                                 0x760200

//ItemBase
#define ItemBase__IsLore_x                                         0x8E9AC0
#define ItemBase__IsLoreEquipped_x                                 0x8E9B40

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x609AA0
#define EQPlacedItemManager__GetItemByGuid_x                       0x609BE0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x609C40

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6B3C70
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x6B8550

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x519CB0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x504A90
#define FactionManagerClient__HandleFactionMessage_x               0x5052B0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x505AA0
#define FactionManagerClient__GetMaxFaction_x                      0x505ABF
#define FactionManagerClient__GetMinFaction_x                      0x505A70

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x511690

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x96BE10

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49DED0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x511900

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x582620

//CTargetManager
#define CTargetManager__Get_x                                      0x6CCC60

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6B3C70

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4AC250

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5D9EC0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xE40ACC

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6EA3A0
#define CAAWnd__UpdateSelected_x                                   0x6E6A40
#define CAAWnd__Update_x                                           0x6E96D0

//CXRect
#define CXRect__operator_and_x                                     0x756450

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

