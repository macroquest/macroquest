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
#define __ExpectedVersionDate                                     "Jul 10 2019"
#define __ExpectedVersionTime                                     "16:29:05"
#define __ActualVersionDate_x                                      0xAE24F4
#define __ActualVersionTime_x                                      0xAE24E8
#define __ActualVersionBuild_x                                     0xAE2F8C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x61AFA0
#define __MemChecker1_x                                            0x8F0F70
#define __MemChecker2_x                                            0x6AA5A0
#define __MemChecker3_x                                            0x6AA4F0
#define __MemChecker4_x                                            0x847F80
#define __EncryptPad0_x                                            0xC18998
#define __EncryptPad1_x                                            0xC769C0
#define __EncryptPad2_x                                            0xC29210
#define __EncryptPad3_x                                            0xC28E10
#define __EncryptPad4_x                                            0xC67188
#define __EncryptPad5_x                                            0xF3FB70
#define __AC1_x                                                    0x804A46
#define __AC2_x                                                    0x5D4C6F
#define __AC3_x                                                    0x5DC37F
#define __AC4_x                                                    0x5E0260
#define __AC5_x                                                    0x5E65B0
#define __AC6_x                                                    0x5EAB76
#define __AC7_x                                                    0x5D46E0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1EEB4C

// Direct Input
#define DI8__Main_x                                                0xF3FB90
#define DI8__Keyboard_x                                            0xF3FB94
#define DI8__Mouse_x                                               0xF3F150
#define DI8__Mouse_Copy_x                                          0xE9A82C
#define DI8__Mouse_Check_x                                         0xF3FEC4
#define __AutoSkillArray_x                                         0xE9B744
#define __Attack_x                                                 0xF3955B
#define __Autofire_x                                               0xF3955C
#define __BindList_x                                               0xC073F0
#define g_eqCommandStates_x                                        0xC08168
#define __Clicks_x                                                 0xE9A8E4
#define __CommandList_x                                            0xC08D28
#define __CurrentMapLabel_x                                        0x105A604
#define __CurrentSocial_x                                          0xBF1730
#define __DoAbilityList_x                                          0xED107C
#define __do_loot_x                                                0x5A0C70
#define __DrawHandler_x                                            0x16D6FD8
#define __GroupCount_x                                             0xE8D1CA
#define __Guilds_x                                                 0xE91038
#define __gWorld_x                                                 0xE8D1B4
#define __HWnd_x                                                   0xF3F154
#define __heqmain_x                                                0x104A1AC
#define __InChatMode_x                                             0xE9A814
#define __LastTell_x                                               0xE9C778
#define __LMouseHeldTime_x                                         0xE9A950
#define __Mouse_x                                                  0xF3FB7C
#define __MouseLook_x                                              0xE9A8AA
#define __MouseEventTime_x                                         0xF3A03C
#define __gpbCommandEvent_x                                        0xE8ABC8
#define __NetStatusToggle_x                                        0xE9A8AD
#define __PCNames_x                                                0xE9BD28
#define __RangeAttackReady_x                                       0xE9BA28
#define __RMouseHeldTime_x                                         0xE9A94C
#define __RunWalkState_x                                           0xE9A818
#define __ScreenMode_x                                             0xDD8A3C
#define __ScreenX_x                                                0xE9A7CC
#define __ScreenY_x                                                0xE9A7C8
#define __ScreenXMax_x                                             0xE9A7D0
#define __ScreenYMax_x                                             0xE9A7D4
#define __ServerHost_x                                             0xE8ADFB
#define __ServerName_x                                             0xED103C
#define __ShiftKeyDown_x                                           0xE9AEA4
#define __ShowNames_x                                              0xE9BBE4
#define __Socials_x                                                0xED113C
#define __SubscriptionType_x                                       0x109C198
#define __TargetAggroHolder_x                                      0x105CFB8
#define __ZoneType_x                                               0xE9ACA8
#define __GroupAggro_x                                             0x105CFF8
#define __LoginName_x                                              0xF3F814
#define __Inviter_x                                                0xF394D8
#define __AttackOnAssist_x                                         0xE9BBA0
#define __UseTellWindows_x                                         0xE9BEC4
#define __gfMaxZoomCameraDistance_x                                0xAD7918
#define __gfMaxCameraDistance_x                                    0xB04E20
#define __pulAutoRun_x                                             0xE9A8C8
#define __pulForward_x                                             0xE9BEFC
#define __pulBackward_x                                            0xE9BF00
#define __pulTurnRight_x                                           0xE9BF04
#define __pulTurnLeft_x                                            0xE9BF08
#define __pulStrafeLeft_x                                          0xE9BF0C
#define __pulStrafeRight_x                                         0xE9BF10

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE8D3D0
#define instEQZoneInfo_x                                           0xE9AAA0
#define pinstActiveBanker_x                                        0xE8AC60
#define pinstActiveCorpse_x                                        0xE8AC58
#define pinstActiveGMaster_x                                       0xE8AC5C
#define pinstActiveMerchant_x                                      0xE8AC54
#define pinstAltAdvManager_x                                       0xDD96A0
#define pinstBandageTarget_x                                       0xE8AC70
#define pinstCamActor_x                                            0xDD8A30
#define pinstCDBStr_x                                              0xDD83CC
#define pinstCDisplay_x                                            0xE8D3BC
#define pinstCEverQuest_x                                          0x104919C
#define pinstEverQuestInfo_x                                       0xE9A7C0
#define pinstCharData_x                                            0xE8D11C
#define pinstCharSpawn_x                                           0xE8ACA8
#define pinstControlledMissile_x                                   0xE8B10C
#define pinstControlledPlayer_x                                    0xE8ACA8
#define pinstCResolutionHandler_x                                  0x16D7208
#define pinstCSidlManager_x                                        0x16D61A4
#define pinstCXWndManager_x                                        0x16D6198
#define instDynamicZone_x                                          0xE90F10
#define pinstDZMember_x                                            0xE91020
#define pinstDZTimerInfo_x                                         0xE91024
#define pinstEqLogin_x                                             0xF3F160
#define instEQMisc_x                                               0xDD8310
#define pinstEQSoundManager_x                                      0xDDA5C8
#define pinstEQSpellStrings_x                                      0xC9B5B0
#define instExpeditionLeader_x                                     0xE90F5A
#define instExpeditionName_x                                       0xE90F9A
#define pinstGroup_x                                               0xE8D1C6
#define pinstImeManager_x                                          0x16D619C
#define pinstLocalPlayer_x                                         0xE8AC50
#define pinstMercenaryData_x                                       0xF3BB2C
#define pinstMercenaryStats_x                                      0x105D104
#define pinstModelPlayer_x                                         0xE8AC68
#define pinstPCData_x                                              0xE8D11C
#define pinstSkillMgr_x                                            0xF3DCA0
#define pinstSpawnManager_x                                        0xF3C748
#define pinstSpellManager_x                                        0xF3DEC0
#define pinstSpellSets_x                                           0xF32184
#define pinstStringTable_x                                         0xE8D3C8
#define pinstSwitchManager_x                                       0xE8A970
#define pinstTarget_x                                              0xE8ACA4
#define pinstTargetObject_x                                        0xE8ACF4
#define pinstTargetSwitch_x                                        0xE8D118
#define pinstTaskMember_x                                          0xDD81A0
#define pinstTrackTarget_x                                         0xE8ACAC
#define pinstTradeTarget_x                                         0xE8AC64
#define instTributeActive_x                                        0xDD8331
#define pinstViewActor_x                                           0xDD8A2C
#define pinstWorldData_x                                           0xE8D3B8
#define pinstZoneAddr_x                                            0xE9AD40
#define pinstPlayerPath_x                                          0xF3C7E0
#define pinstTargetIndicator_x                                     0xF3E128
#define EQObject_Top_x                                             0xE8ABCC
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDD8534
#define pinstCAchievementsWnd_x                                    0xDD8518
#define pinstCActionsWnd_x                                         0xDD859C
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDD8A7C
#define pinstCAdvancedLootWnd_x                                    0xDD8590
#define pinstCAdventureLeaderboardWnd_x                            0x1053DD8
#define pinstCAdventureRequestWnd_x                                0x1053E88
#define pinstCAdventureStatsWnd_x                                  0x1053F38
#define pinstCAggroMeterWnd_x                                      0xDD8ACC
#define pinstCAlarmWnd_x                                           0xDD849C
#define pinstCAlertHistoryWnd_x                                    0xDD84C4
#define pinstCAlertStackWnd_x                                      0xDD8AC8
#define pinstCAlertWnd_x                                           0xDD8ADC
#define pinstCAltStorageWnd_x                                      0x1054298
#define pinstCAudioTriggersWindow_x                                0xC8D8E0
#define pinstCAuraWnd_x                                            0xDD8AC0
#define pinstCAvaZoneWnd_x                                         0xDD84C8
#define pinstCBandolierWnd_x                                       0xDD8AF4
#define pinstCBankWnd_x                                            0xDD84E8
#define pinstCBarterMerchantWnd_x                                  0x10554D8
#define pinstCBarterSearchWnd_x                                    0x1055588
#define pinstCBarterWnd_x                                          0x1055638
#define pinstCBazaarConfirmationWnd_x                              0xDD8AC4
#define pinstCBazaarSearchWnd_x                                    0xDD8A4C
#define pinstCBazaarWnd_x                                          0xDD8474
#define pinstCBlockedBuffWnd_x                                     0xDD84CC
#define pinstCBlockedPetBuffWnd_x                                  0xDD84F0
#define pinstCBodyTintWnd_x                                        0xDD8A9C
#define pinstCBookWnd_x                                            0xDD8478
#define pinstCBreathWnd_x                                          0xDD8544
#define pinstCBuffWindowNORMAL_x                                   0xDD84A0
#define pinstCBuffWindowSHORT_x                                    0xDD84A4
#define pinstCBugReportWnd_x                                       0xDD8538
#define pinstCButtonWnd_x                                          0x16D6408
#define pinstCCastingWnd_x                                         0xDD8530
#define pinstCCastSpellWnd_x                                       0xDD8A68
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDD8548
#define pinstCChatWindowManager_x                                  0x10560F8
#define pinstCClaimWnd_x                                           0x1056250
#define pinstCColorPickerWnd_x                                     0xDD8574
#define pinstCCombatAbilityWnd_x                                   0xDD8AD0
#define pinstCCombatSkillsSelectWnd_x                              0xDD8594
#define pinstCCompassWnd_x                                         0xDD8A8C
#define pinstCConfirmationDialog_x                                 0x105B150
#define pinstCContainerMgr_x                                       0xDD8528
#define pinstCContextMenuManager_x                                 0x16D6158
#define pinstCCursorAttachment_x                                   0xDD8520
#define pinstCDynamicZoneWnd_x                                     0x1056818
#define pinstCEditLabelWnd_x                                       0xDD8488
#define pinstCEQMainWnd_x                                          0x1056A60
#define pinstCEventCalendarWnd_x                                   0xDD8550
#define pinstCExtendedTargetWnd_x                                  0xDD8AAC
#define pinstCFacePick_x                                           0xDD856C
#define pinstCFactionWnd_x                                         0xDD852C
#define pinstCFellowshipWnd_x                                      0x1056C60
#define pinstCFileSelectionWnd_x                                   0xDD8580
#define pinstCFindItemWnd_x                                        0xDD8490
#define pinstCFindLocationWnd_x                                    0x1056DB8
#define pinstCFriendsWnd_x                                         0xDD8A24
#define pinstCGemsGameWnd_x                                        0xDD8470
#define pinstCGiveWnd_x                                            0xDD8494
#define pinstCGroupSearchFiltersWnd_x                              0xDD8AE4
#define pinstCGroupSearchWnd_x                                     0x10571B0
#define pinstCGroupWnd_x                                           0x1057260
#define pinstCGuildBankWnd_x                                       0xE9BB84
#define pinstCGuildCreationWnd_x                                   0x10573C0
#define pinstCGuildMgmtWnd_x                                       0x1057470
#define pinstCharacterCreation_x                                   0xDD8AD4
#define pinstCHelpWnd_x                                            0xDD8A84
#define pinstCHeritageSelectionWnd_x                               0xDD857C
#define pinstCHotButtonWnd_x                                       0x10595C8
#define pinstCHotButtonWnd1_x                                      0x10595C8
#define pinstCHotButtonWnd2_x                                      0x10595CC
#define pinstCHotButtonWnd3_x                                      0x10595D0
#define pinstCHotButtonWnd4_x                                      0x10595D4
#define pinstCIconSelectionWnd_x                                   0xDD8504
#define pinstCInspectWnd_x                                         0xDD8510
#define pinstCInventoryWnd_x                                       0xDD8CF8
#define pinstCInvSlotMgr_x                                         0xDD84E4
#define pinstCItemDisplayManager_x                                 0x1059B58
#define pinstCItemExpTransferWnd_x                                 0x1059C8C
#define pinstCItemOverflowWnd_x                                    0xDD8A54
#define pinstCJournalCatWnd_x                                      0xDD8614
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDD8564
#define pinstCKeyRingWnd_x                                         0xDD84BC
#define pinstCLargeDialogWnd_x                                     0x105BDD0
#define pinstCLayoutCopyWnd_x                                      0x1059FD8
#define pinstCLFGuildWnd_x                                         0x105A088
#define pinstCLoadskinWnd_x                                        0xDD847C
#define pinstCLootFiltersCopyWnd_x                                 0xCA9BA8
#define pinstCLootFiltersWnd_x                                     0xDD8CFC
#define pinstCLootSettingsWnd_x                                    0xDD8484
#define pinstCLootWnd_x                                            0xDD855C
#define pinstCMailAddressBookWnd_x                                 0xDD84F4
#define pinstCMailCompositionWnd_x                                 0xDD84D4
#define pinstCMailIgnoreListWnd_x                                  0xDD84F8
#define pinstCMailWnd_x                                            0xDD84A8
#define pinstCManageLootWnd_x                                      0xDD9B50
#define pinstCMapToolbarWnd_x                                      0xDD8468
#define pinstCMapViewWnd_x                                         0xDD8AEC
#define pinstCMarketplaceWnd_x                                     0xDD8554
#define pinstCMerchantWnd_x                                        0xDD85AC
#define pinstCMIZoneSelectWnd_x                                    0x105A8C0
#define pinstCMusicPlayerWnd_x                                     0xDD84B0
#define pinstCNameChangeMercWnd_x                                  0xDD8A80
#define pinstCNameChangePetWnd_x                                   0xDD8A70
#define pinstCNameChangeWnd_x                                      0xDD8540
#define pinstCNoteWnd_x                                            0xDD8A78
#define pinstCObjectPreviewWnd_x                                   0xDD8578
#define pinstCOptionsWnd_x                                         0xDD846C
#define pinstCPetInfoWnd_x                                         0xDD84D8
#define pinstCPetitionQWnd_x                                       0xDD8A28
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDD8A98
#define pinstCPlayerWnd_x                                          0xDD8480
#define pinstCPopupWndManager_x                                    0x105B150
#define pinstCProgressionSelectionWnd_x                            0x105B200
#define pinstCPurchaseGroupWnd_x                                   0xDD8A1C
#define pinstCPurchaseWnd_x                                        0xDD8584
#define pinstCPvPLeaderboardWnd_x                                  0x105B2B0
#define pinstCPvPStatsWnd_x                                        0x105B360
#define pinstCQuantityWnd_x                                        0xDD850C
#define pinstCRaceChangeWnd_x                                      0xDD8560
#define pinstCRaidOptionsWnd_x                                     0xDD8AE8
#define pinstCRaidWnd_x                                            0xDD8514
#define pinstCRealEstateItemsWnd_x                                 0xDD851C
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDD854C
#define pinstCRealEstateManageWnd_x                                0xDD848C
#define pinstCRealEstateNeighborhoodWnd_x                          0xDD84B4
#define pinstCRealEstatePlotSearchWnd_x                            0xDD84DC
#define pinstCRealEstatePurchaseWnd_x                              0xDD84FC
#define pinstCRespawnWnd_x                                         0xDD8AE0
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDD8ABC
#define pinstCSendMoneyWnd_x                                       0xDD84AC
#define pinstCServerListWnd_x                                      0xDD84C0
#define pinstCSkillsSelectWnd_x                                    0xDD8570
#define pinstCSkillsWnd_x                                          0xDD8558
#define pinstCSocialEditWnd_x                                      0xDD8524
#define pinstCSocialWnd_x                                          0xDD8AA0
#define pinstCSpellBookWnd_x                                       0xDD8AA4
#define pinstCStoryWnd_x                                           0xDD8A88
#define pinstCTargetOfTargetWnd_x                                  0x105D188
#define pinstCTargetWnd_x                                          0xDD84D0
#define pinstCTaskOverlayWnd_x                                     0xDD84E0
#define pinstCTaskSelectWnd_x                                      0x105D2E0
#define pinstCTaskManager_x                                        0xCAA4F8
#define pinstCTaskTemplateSelectWnd_x                              0x105D390
#define pinstCTaskWnd_x                                            0x105D440
#define pinstCTextEntryWnd_x                                       0xDD8A90
#define pinstCTimeLeftWnd_x                                        0xDD8588
#define pinstCTipWndCONTEXT_x                                      0x105D644
#define pinstCTipWndOFDAY_x                                        0x105D640
#define pinstCTitleWnd_x                                           0x105D6F0
#define pinstCTrackingWnd_x                                        0xDD84EC
#define pinstCTradeskillWnd_x                                      0x105D858
#define pinstCTradeWnd_x                                           0xDD8A94
#define pinstCTrainWnd_x                                           0xDD8508
#define pinstCTributeBenefitWnd_x                                  0x105DA58
#define pinstCTributeMasterWnd_x                                   0x105DB08
#define pinstCTributeTrophyWnd_x                                   0x105DBB8
#define pinstCVideoModesWnd_x                                      0xDD8AA8
#define pinstCVoiceMacroWnd_x                                      0xF3E890
#define pinstCVoteResultsWnd_x                                     0xDD8A20
#define pinstCVoteWnd_x                                            0xDD858C
#define pinstCWebManager_x                                         0xF3EF0C
#define pinstCZoneGuideWnd_x                                       0xDD8498
#define pinstCZonePathWnd_x                                        0xDD84B8

#define pinstEQSuiteTextureLoader_x                                0xC784B0
#define pinstItemIconCache_x                                       0x1056A18
#define pinstLootFiltersManager_x                                  0xCA9C58
#define pinstRewardSelectionWnd_x                                  0x105BAA8

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC28E00
#define __CastRay_x                                                0x59C0D0
#define __CastRay2_x                                               0x59C120
#define __ConvertItemTags_x                                        0x5B7C70
#define __CrashHandler_x                                           0x851900
#define __CleanItemTags_x                                          0x477B10
#define __DoesFileExist_x                                          0x8F4060
#define __EQGetTime_x                                              0x8F0A50
#define __ExecuteCmd_x                                             0x5949E0
#define __FixHeading_x                                             0x98B520
#define __GameLoop_x                                               0x6A9A60
#define __get_bearing_x                                            0x59BC20
#define __get_melee_range_x                                        0x59C310
#define __GetAnimationCache_x                                      0x70EA00
#define __GetGaugeValueFromEQ_x                                    0x802EE0
#define __GetLabelFromEQ_x                                         0x8049D0
#define __GetXTargetType_x                                         0x98CF80
#define __HandleMouseWheel_x                                       0x6AA650
#define __HeadingDiff_x                                            0x98B590
#define __HelpPath_x                                               0xF39C2C
#define __LoadFrontEnd_x                                           0x6A6530
#define __NewUIINI_x                                               0x802BB0
#define __pCrashHandler_x                                          0x107AFC0
#define __ProcessGameEvents_x                                      0x5FC3D0
#define __ProcessMouseEvent_x                                      0x5FBB90
#define __SaveColors_x                                             0x545970
#define __STMLToText_x                                             0x92EA50
#define __ToggleKeyRingItem_x                                      0x508980
#define CMemoryMappedFile__SetFile_x                               0xA659A0
#define CrashDetected_x                                            0x6A7F90
#define DrawNetStatus_x                                            0x6282A0
#define Expansion_HoT_x                                            0xE9BB8C
#define Teleport_Table_Size_x                                      0xE8ACB4
#define Teleport_Table_x                                           0xE8B110
#define Util__FastTime_x                                           0x8F0610
#define wwsCrashReportCheckForUploader_x                           0x852470
#define wwsCrashReportPlatformLaunchUploader_x                     0x854B50

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48BA40
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x494940
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x494710
#define CAdvancedLootWnd__AddPlayerToList_x                        0x48EFD0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x48E420

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x54D4D0
#define AltAdvManager__IsAbilityReady_x                            0x54C420
#define AltAdvManager__GetAAById_x                                 0x54C620
#define AltAdvManager__CanTrainAbility_x                           0x54C690
#define AltAdvManager__CanSeeAbility_x                             0x54C9F0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C7680
#define CharacterZoneClient__HasSkill_x                            0x4D2550
#define CharacterZoneClient__MakeMeVisible_x                       0x4D3C70
#define CharacterZoneClient__IsStackBlocked_x                      0x4BBD30
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B8480
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D6600
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D66E0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D67C0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C0800
#define CharacterZoneClient__BardCastBard_x                        0x4C32C0
#define CharacterZoneClient__GetMaxEffects_x                       0x4B8550
#define CharacterZoneClient__GetEffect_x                           0x4B83C0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C1830
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C1900
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C1950
#define CharacterZoneClient__CalcAffectChange_x                    0x4C1AA0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C1C80
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B01E0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D4BE0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D4650

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D0310
#define CBankWnd__WndNotification_x                                0x6D00F0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6DDB10

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x60ADA0
#define CButtonWnd__CButtonWnd_x                                   0x92ADF0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6FDBA0
#define CChatManager__InitContextMenu_x                            0x6F6E30
#define CChatManager__FreeChatWindow_x                             0x6FC6C0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E5C20
#define CChatManager__SetLockedActiveChatWindow_x                  0x6FD820
#define CChatManager__CreateChatWindow_x                           0x6FCD00

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E5D30

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x93F4C0
#define CContextMenu__dCContextMenu_x                              0x93F6F0
#define CContextMenu__AddMenuItem_x                                0x93F700
#define CContextMenu__RemoveMenuItem_x                             0x93FA10
#define CContextMenu__RemoveAllMenuItems_x                         0x93FA30
#define CContextMenu__CheckMenuItem_x                              0x93FAB0
#define CContextMenu__SetMenuItem_x                                0x93F930
#define CContextMenu__AddSeparator_x                               0x93F890

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x940050
#define CContextMenuManager__RemoveMenu_x                          0x9400C0
#define CContextMenuManager__PopupMenu_x                           0x940180
#define CContextMenuManager__Flush_x                               0x93FFF0
#define CContextMenuManager__GetMenu_x                             0x496A60
#define CContextMenuManager__CreateDefaultMenu_x                   0x709220

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D1080
#define CChatService__GetFriendName_x                              0x8D1090

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6FE420
#define CChatWindow__Clear_x                                       0x6FF6C0
#define CChatWindow__WndNotification_x                             0x6FFE50
#define CChatWindow__AddHistory_x                                  0x6FEF90

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93C950
#define CComboWnd__Draw_x                                          0x93BE50
#define CComboWnd__GetCurChoice_x                                  0x93C790
#define CComboWnd__GetListRect_x                                   0x93C300
#define CComboWnd__GetTextRect_x                                   0x93C9C0
#define CComboWnd__InsertChoice_x                                  0x93C490
#define CComboWnd__SetColors_x                                     0x93C460
#define CComboWnd__SetChoice_x                                     0x93C760
#define CComboWnd__GetItemCount_x                                  0x93C7A0
#define CComboWnd__GetCurChoiceText_x                              0x93C7E0
#define CComboWnd__GetChoiceText_x                                 0x93C7B0
#define CComboWnd__InsertChoiceAtIndex_x                           0x93C520

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x706C20
#define CContainerWnd__vftable_x                                   0xAEB788
#define CContainerWnd__SetContainer_x                              0x708190

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x545730
#define CDisplay__GetClickedActor_x                                0x5386F0
#define CDisplay__GetUserDefinedColor_x                            0x530DD0
#define CDisplay__GetWorldFilePath_x                               0x53A140
#define CDisplay__is3dON_x                                         0x5353C0
#define CDisplay__ReloadUI_x                                       0x53F860
#define CDisplay__WriteTextHD2_x                                   0x5351A0
#define CDisplay__TrueDistance_x                                   0x53BDA0
#define CDisplay__SetViewActor_x                                   0x538040
#define CDisplay__GetFloorHeight_x                                 0x535480
#define CDisplay__SetRenderWindow_x                                0x533DB0
#define CDisplay__ToggleScreenshotMode_x                           0x537B10

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x95EEF0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x942A20
#define CEditWnd__GetCharIndexPt_x                                 0x943920
#define CEditWnd__GetDisplayString_x                               0x9437C0
#define CEditWnd__GetHorzOffset_x                                  0x942060
#define CEditWnd__GetLineForPrintableChar_x                        0x944AD0
#define CEditWnd__GetSelStartPt_x                                  0x943BD0
#define CEditWnd__GetSTMLSafeText_x                                0x9435E0
#define CEditWnd__PointFromPrintableChar_x                         0x944700
#define CEditWnd__SelectableCharFromPoint_x                        0x944870
#define CEditWnd__SetEditable_x                                    0x943CA0
#define CEditWnd__SetWindowTextA_x                                 0x943360

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5EA0A0
#define CEverQuest__ClickedPlayer_x                                0x5DC160
#define CEverQuest__CreateTargetIndicator_x                        0x5F9680
#define CEverQuest__DeleteTargetIndicator_x                        0x5F9710
#define CEverQuest__DoTellWindow_x                                 0x4E5E10
#define CEverQuest__OutputTextToLog_x                              0x4E6040
#define CEverQuest__DropHeldItemOnGround_x                         0x5D11A0
#define CEverQuest__dsp_chat_x                                     0x4E63D0
#define CEverQuest__trimName_x                                     0x5F5960
#define CEverQuest__Emote_x                                        0x5EA8B0
#define CEverQuest__EnterZone_x                                    0x5E4890
#define CEverQuest__GetBodyTypeDesc_x                              0x5EF1F0
#define CEverQuest__GetClassDesc_x                                 0x5EF830
#define CEverQuest__GetClassThreeLetterCode_x                      0x5EFE30
#define CEverQuest__GetDeityDesc_x                                 0x5F7FD0
#define CEverQuest__GetLangDesc_x                                  0x5EFFF0
#define CEverQuest__GetRaceDesc_x                                  0x5EF810
#define CEverQuest__InterpretCmd_x                                 0x5F85A0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5D5390
#define CEverQuest__LMouseUp_x                                     0x5D3710
#define CEverQuest__RightClickedOnPlayer_x                         0x5D5C70
#define CEverQuest__RMouseUp_x                                     0x5D46A0
#define CEverQuest__SetGameState_x                                 0x5D0F30
#define CEverQuest__UPCNotificationFlush_x                         0x5F5860
#define CEverQuest__IssuePetCommand_x                              0x5F1400
#define CEverQuest__ReportSuccessfulHit_x                          0x5EBCB0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x718D00
#define CGaugeWnd__CalcLinesFillRect_x                             0x718D60
#define CGaugeWnd__Draw_x                                          0x718340

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ACF30
#define CGuild__GetGuildName_x                                     0x4AC010
#define CGuild__GetGuildIndex_x                                    0x4AC3A0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x7340D0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x60B160

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x741070
#define CInvSlotMgr__MoveItem_x                                    0x73FDD0
#define CInvSlotMgr__SelectSlot_x                                  0x741140

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x73E680
#define CInvSlot__SliderComplete_x                                 0x73C3F0
#define CInvSlot__GetItemBase_x                                    0x73BD80
#define CInvSlot__UpdateItem_x                                     0x73BEF0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x742B80
#define CInvSlotWnd__CInvSlotWnd_x                                 0x741D30
#define CInvSlotWnd__HandleLButtonUp_x                             0x742700

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7FF110
#define CItemDisplayWnd__UpdateStrings_x                           0x750FB0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x74AE00
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x74B300
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x7515A0
#define CItemDisplayWnd__AboutToShow_x                             0x750C10
#define CItemDisplayWnd__WndNotification_x                         0x752AA0
#define CItemDisplayWnd__RequestConvertItem_x                      0x752560
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x74FC70
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x750A30

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x836D20

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x756B50

// CLabel 
#define CLabel__Draw_x                                             0x75C570

// CListWnd
#define CListWnd__CListWnd_x                                       0x915230
#define CListWnd__dCListWnd_x                                      0x915540
#define CListWnd__AddColumn_x                                      0x919820
#define CListWnd__AddColumn1_x                                     0x919870
#define CListWnd__AddLine_x                                        0x919C00
#define CListWnd__AddString_x                                      0x919A00
#define CListWnd__CalculateFirstVisibleLine_x                      0x9195F0
#define CListWnd__CalculateVSBRange_x                              0x9193E0
#define CListWnd__ClearSel_x                                       0x91A3E0
#define CListWnd__ClearAllSel_x                                    0x91A440
#define CListWnd__CloseAndUpdateEditWindow_x                       0x91AE40
#define CListWnd__Compare_x                                        0x918D30
#define CListWnd__Draw_x                                           0x915640
#define CListWnd__DrawColumnSeparators_x                           0x917E00
#define CListWnd__DrawHeader_x                                     0x918270
#define CListWnd__DrawItem_x                                       0x918670
#define CListWnd__DrawLine_x                                       0x917F70
#define CListWnd__DrawSeparator_x                                  0x917EA0
#define CListWnd__EnableLine_x                                     0x9176F0
#define CListWnd__EnsureVisible_x                                  0x91AD70
#define CListWnd__ExtendSel_x                                      0x91A310
#define CListWnd__GetColumnTooltip_x                               0x917230
#define CListWnd__GetColumnMinWidth_x                              0x9172A0
#define CListWnd__GetColumnWidth_x                                 0x9171A0
#define CListWnd__GetCurSel_x                                      0x916B30
#define CListWnd__GetItemAtPoint_x                                 0x917960
#define CListWnd__GetItemAtPoint1_x                                0x9179D0
#define CListWnd__GetItemData_x                                    0x916BB0
#define CListWnd__GetItemHeight_x                                  0x916F70
#define CListWnd__GetItemIcon_x                                    0x916D40
#define CListWnd__GetItemRect_x                                    0x9177E0
#define CListWnd__GetItemText_x                                    0x916BF0
#define CListWnd__GetSelList_x                                     0x91A490
#define CListWnd__GetSeparatorRect_x                               0x917C10
#define CListWnd__InsertLine_x                                     0x919FF0
#define CListWnd__RemoveLine_x                                     0x91A140
#define CListWnd__SetColors_x                                      0x9193C0
#define CListWnd__SetColumnJustification_x                         0x9190F0
#define CListWnd__SetColumnWidth_x                                 0x919010
#define CListWnd__SetCurSel_x                                      0x91A250
#define CListWnd__SetItemColor_x                                   0x91AA30
#define CListWnd__SetItemData_x                                    0x91A9F0
#define CListWnd__SetItemText_x                                    0x91A600
#define CListWnd__ShiftColumnSeparator_x                           0x9191B0
#define CListWnd__Sort_x                                           0x918EB0
#define CListWnd__ToggleSel_x                                      0x91A280
#define CListWnd__SetColumnsSizable_x                              0x919250
#define CListWnd__SetItemWnd_x                                     0x91A8B0
#define CListWnd__GetItemWnd_x                                     0x916D90
#define CListWnd__SetItemIcon_x                                    0x91A680
#define CListWnd__CalculateCustomWindowPositions_x                 0x9196E0
#define CListWnd__SetVScrollPos_x                                  0x918FF0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x771D60
#define CMapViewWnd__GetWorldCoordinates_x                         0x770470
#define CMapViewWnd__HandleLButtonDown_x                           0x76D4D0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x794D20
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x795600
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x795B30
#define CMerchantWnd__SelectRecoverySlot_x                         0x798AA0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x793880
#define CMerchantWnd__SelectBuySellSlot_x                          0x79E660
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x794940

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89ED30
#define CPacketScrambler__hton_x                                   0x89ED20

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x933FE0
#define CSidlManager__FindScreenPieceTemplate_x                    0x9343F0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9341E0
#define CSidlManager__CreateLabel_x                                0x7F6580
#define CSidlManager__CreateXWndFromTemplate_x                     0x937390
#define CSidlManager__CreateXWndFromTemplate1_x                    0x937560
#define CSidlManager__CreateXWnd_x                                 0x7F64B0
#define CSidlManager__CreateHotButtonWnd_x                         0x7F6A70

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x930B60
#define CSidlScreenWnd__CalculateVSBRange_x                        0x930A60
#define CSidlScreenWnd__ConvertToRes_x                             0x955EB0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x930500
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x9301F0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x9302C0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x930390
#define CSidlScreenWnd__DrawSidlPiece_x                            0x930FF0
#define CSidlScreenWnd__EnableIniStorage_x                         0x9314C0
#define CSidlScreenWnd__GetSidlPiece_x                             0x9311E0
#define CSidlScreenWnd__Init1_x                                    0x92FE10
#define CSidlScreenWnd__LoadIniInfo_x                              0x931510
#define CSidlScreenWnd__LoadIniListWnd_x                           0x932050
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92F230
#define CSidlScreenWnd__StoreIniInfo_x                             0x931BD0
#define CSidlScreenWnd__StoreIniVis_x                              0x931F30
#define CSidlScreenWnd__WndNotification_x                          0x930F00
#define CSidlScreenWnd__GetChildItem_x                             0x931440
#define CSidlScreenWnd__HandleLButtonUp_x                          0x920CB0
#define CSidlScreenWnd__m_layoutCopy_x                             0x16D6028

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x66FA80
#define CSkillMgr__GetSkillCap_x                                   0x66FC60
#define CSkillMgr__GetNameToken_x                                  0x66F210
#define CSkillMgr__IsActivatedSkill_x                              0x66F350
#define CSkillMgr__IsCombatSkill_x                                 0x66F290

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x940E30
#define CSliderWnd__SetValue_x                                     0x940CA0
#define CSliderWnd__SetNumTicks_x                                  0x940D00

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7FC5F0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x9495E0
#define CStmlWnd__CalculateHSBRange_x                              0x94A6B0
#define CStmlWnd__CalculateVSBRange_x                              0x94A620
#define CStmlWnd__CanBreakAtCharacter_x                            0x94E9E0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x94F670
#define CStmlWnd__ForceParseNow_x                                  0x949B80
#define CStmlWnd__GetNextTagPiece_x                                0x94E940
#define CStmlWnd__GetSTMLText_x                                    0x4F7C90
#define CStmlWnd__GetVisibleText_x                                 0x949BA0
#define CStmlWnd__InitializeWindowVariables_x                      0x94F4C0
#define CStmlWnd__MakeStmlColorTag_x                               0x948C50
#define CStmlWnd__MakeWndNotificationTag_x                         0x948CC0
#define CStmlWnd__SetSTMLText_x                                    0x947D00
#define CStmlWnd__StripFirstSTMLLines_x                            0x950760
#define CStmlWnd__UpdateHistoryString_x                            0x94F880

// CTabWnd 
#define CTabWnd__Draw_x                                            0x946E80
#define CTabWnd__DrawCurrentPage_x                                 0x947560
#define CTabWnd__DrawTab_x                                         0x947280
#define CTabWnd__GetCurrentPage_x                                  0x946690
#define CTabWnd__GetPageInnerRect_x                                0x9468D0
#define CTabWnd__GetTabInnerRect_x                                 0x946810
#define CTabWnd__GetTabRect_x                                      0x9466C0
#define CTabWnd__InsertPage_x                                      0x946AE0
#define CTabWnd__SetPage_x                                         0x946950
#define CTabWnd__SetPageRect_x                                     0x946DC0
#define CTabWnd__UpdatePage_x                                      0x947140
#define CTabWnd__GetPageFromTabIndex_x                             0x9471C0
#define CTabWnd__GetCurrentTabIndex_x                              0x946680

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x756F40
#define CPageWnd__SetTabText_x                                     0x9461E0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A6C20

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91DB20
#define CTextureFont__GetTextExtent_x                              0x91DCE0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6A3570
#define CHtmlComponentWnd__ValidateUri_x                           0x735AD0
#define CHtmlWnd__SetClientCallbacks_x                             0x6101D0
#define CHtmlWnd__AddObserver_x                                    0x6101F0
#define CHtmlWnd__RemoveObserver_x                                 0x610250
#define Window__getProgress_x                                      0x84F570
#define Window__getStatus_x                                        0x84F590
#define Window__getURI_x                                           0x84F5A0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x95B920

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x90AE80

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E5B10
#define CXStr__CXStr1_x                                            0x47C030
#define CXStr__CXStr3_x                                            0x8ECB40
#define CXStr__dCXStr_x                                            0x4730E0
#define CXStr__operator_equal_x                                    0x8ECD70
#define CXStr__operator_equal1_x                                   0x8ECDB0
#define CXStr__operator_plus_equal1_x                              0x8ED840
#define CXStr__SetString_x                                         0x8EF730
#define CXStr__operator_char_p_x                                   0x8ED280
#define CXStr__GetChar_x                                           0x8EF060
#define CXStr__Delete_x                                            0x8EE930
#define CXStr__GetUnicode_x                                        0x8EF0D0
#define CXStr__GetLength_x                                         0x4A69D0
#define CXStr__Mid_x                                               0x477EC0
#define CXStr__Insert_x                                            0x8EF130
#define CXStr__FindNext_x                                          0x8EEDA0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93F0D0
#define CXWnd__BringToTop_x                                        0x9243F0
#define CXWnd__Center_x                                            0x923F70
#define CXWnd__ClrFocus_x                                          0x923DA0
#define CXWnd__Destroy_x                                           0x923E50
#define CXWnd__DoAllDrawing_x                                      0x920450
#define CXWnd__DrawChildren_x                                      0x920420
#define CXWnd__DrawColoredRect_x                                   0x9208A0
#define CXWnd__DrawTooltip_x                                       0x91EF60
#define CXWnd__DrawTooltipAtPoint_x                                0x91F020
#define CXWnd__GetBorderFrame_x                                    0x920700
#define CXWnd__GetChildWndAt_x                                     0x924490
#define CXWnd__GetClientClipRect_x                                 0x922670
#define CXWnd__GetScreenClipRect_x                                 0x922720
#define CXWnd__GetScreenRect_x                                     0x9228D0
#define CXWnd__GetTooltipRect_x                                    0x9208F0
#define CXWnd__GetWindowTextA_x                                    0x4981D0
#define CXWnd__IsActive_x                                          0x921020
#define CXWnd__IsDescendantOf_x                                    0x9232E0
#define CXWnd__IsReallyVisible_x                                   0x923310
#define CXWnd__IsType_x                                            0x924AE0
#define CXWnd__Move_x                                              0x923380
#define CXWnd__Move1_x                                             0x923430
#define CXWnd__ProcessTransition_x                                 0x923F20
#define CXWnd__Refade_x                                            0x923700
#define CXWnd__Resize_x                                            0x9239C0
#define CXWnd__Right_x                                             0x9241B0
#define CXWnd__SetFocus_x                                          0x923D60
#define CXWnd__SetFont_x                                           0x923DD0
#define CXWnd__SetKeyTooltip_x                                     0x924900
#define CXWnd__SetMouseOver_x                                      0x921840
#define CXWnd__StartFade_x                                         0x9231B0
#define CXWnd__GetChildItem_x                                      0x9245F0
#define CXWnd__SetParent_x                                         0x923070
#define CXWnd__Minimize_x                                          0x923A30

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x956F40

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x927340
#define CXWndManager__DrawWindows_x                                0x927360
#define CXWndManager__GetKeyboardFlags_x                           0x929AD0
#define CXWndManager__HandleKeyboardMsg_x                          0x9296E0
#define CXWndManager__RemoveWnd_x                                  0x929D20
#define CXWndManager__RemovePendingDeletionWnd_x                   0x92A250

// CDBStr
#define CDBStr__GetString_x                                        0x52FD60

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B9460
#define EQ_Character__Cur_HP_x                                     0x4CF530
#define EQ_Character__Cur_Mana_x                                   0x4D6CC0
#define EQ_Character__GetCastingTimeModifier_x                     0x4BC380
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AFE20
#define EQ_Character__GetFocusRangeModifier_x                      0x4AFF70
#define EQ_Character__GetHPRegen_x                                 0x4DCAD0
#define EQ_Character__GetEnduranceRegen_x                          0x4DD0E0
#define EQ_Character__GetManaRegen_x                               0x4DD520
#define EQ_Character__Max_Endurance_x                              0x6362C0
#define EQ_Character__Max_HP_x                                     0x4CF360
#define EQ_Character__Max_Mana_x                                   0x6360C0
#define EQ_Character__doCombatAbility_x                            0x638780
#define EQ_Character__UseSkill_x                                   0x4DF310
#define EQ_Character__GetConLevel_x                                0x62F220
#define EQ_Character__IsExpansionFlag_x                            0x593180
#define EQ_Character__TotalEffect_x                                0x4C2A00
#define EQ_Character__GetPCSpellAffect_x                           0x4BCF80
#define EQ_Character__SpellDuration_x                              0x4BCAB0
#define EQ_Character__GetAdjustedSkill_x                           0x4D2310
#define EQ_Character__GetBaseSkill_x                               0x4D32B0
#define EQ_Character__CanUseItem_x                                 0x4D6FD0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BDE80

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x64C970

//PcClient
#define PcClient__PcClient_x                                       0x62C960

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B70D0
#define CCharacterListWnd__EnterWorld_x                            0x4B6B10
#define CCharacterListWnd__Quit_x                                  0x4B6820
#define CCharacterListWnd__UpdateList_x                            0x4B6CA0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6113F0
#define EQ_Item__CreateItemTagString_x                             0x898650
#define EQ_Item__IsStackable_x                                     0x89D080
#define EQ_Item__GetImageNum_x                                     0x89A030
#define EQ_Item__CreateItemClient_x                                0x6105B0
#define EQ_Item__GetItemValue_x                                    0x89B290
#define EQ_Item__ValueSellMerchant_x                               0x89E8C0
#define EQ_Item__IsKeyRingItem_x                                   0x89C9D0
#define EQ_Item__CanGoInBag_x                                      0x611510
#define EQ_Item__IsEmpty_x                                         0x89C510
#define EQ_Item__GetMaxItemCount_x                                 0x89B6C0
#define EQ_Item__GetHeldItem_x                                     0x899F00
#define EQ_Item__GetAugmentFitBySlot_x                             0x897FA0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x54E200
#define EQ_LoadingS__Array_x                                       0xC00600

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x636C20
#define EQ_PC__GetAlternateAbilityId_x                             0x8A79B0
#define EQ_PC__GetCombatAbility_x                                  0x8A8020
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A8090
#define EQ_PC__GetItemRecastTimer_x                                0x638D00
#define EQ_PC__HasLoreItem_x                                       0x62F9E0
#define EQ_PC__AlertInventoryChanged_x                             0x62EB60
#define EQ_PC__GetPcZoneClient_x                                   0x65B3F0
#define EQ_PC__RemoveMyAffect_x                                    0x63BF30
#define EQ_PC__GetKeyRingItems_x                                   0x8A8930
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A86B0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A8C20

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5996D0
#define EQItemList__add_object_x                                   0x5C6800
#define EQItemList__add_item_x                                     0x599C20
#define EQItemList__delete_item_x                                  0x599C70
#define EQItemList__FreeItemList_x                                 0x599B70

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x52D890

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x64E1F0
#define EQPlayer__dEQPlayer_x                                      0x641500
#define EQPlayer__DoAttack_x                                       0x6560A0
#define EQPlayer__EQPlayer_x                                       0x641BC0
#define EQPlayer__SetNameSpriteState_x                             0x645E60
#define EQPlayer__SetNameSpriteTint_x                              0x646D20
#define PlayerBase__HasProperty_j_x                                0x9898F0
#define EQPlayer__IsTargetable_x                                   0x989D90
#define EQPlayer__CanSee_x                                         0x989BF0
#define EQPlayer__CanSee1_x                                        0x989CC0
#define PlayerBase__GetVisibilityLineSegment_x                     0x9899B0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x658EA0
#define PlayerZoneClient__GetLevel_x                               0x65B430
#define PlayerZoneClient__IsValidTeleport_x                        0x5C7970
#define PlayerZoneClient__LegalPlayerRace_x                        0x5475B0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x650FC0
#define EQPlayerManager__GetSpawnByName_x                          0x651070
#define EQPlayerManager__GetPlayerFromPartialName_x                0x651100

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x614B10
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x614B90
#define KeypressHandler__AttachKeyToEqCommand_x                    0x614BD0
#define KeypressHandler__ClearCommandStateArray_x                  0x615FE0
#define KeypressHandler__HandleKeyDown_x                           0x616000
#define KeypressHandler__HandleKeyUp_x                             0x6160A0
#define KeypressHandler__SaveKeymapping_x                          0x6164D0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x76DBF0
#define MapViewMap__SaveEx_x                                       0x770F90
#define MapViewMap__SetZoom_x                                      0x775650

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BBD70

// StringTable 
#define StringTable__getString_x                                   0x8B6BF0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x63BBA0
#define PcZoneClient__RemovePetEffect_x                            0x63C1D0
#define PcZoneClient__HasAlternateAbility_x                        0x635F00
#define PcZoneClient__GetCurrentMod_x                              0x4E23F0
#define PcZoneClient__GetModCap_x                                  0x4E22F0
#define PcZoneClient__CanEquipItem_x                               0x6365B0
#define PcZoneClient__GetItemByID_x                                0x639180
#define PcZoneClient__GetItemByItemClass_x                         0x6392D0
#define PcZoneClient__RemoveBuffEffect_x                           0x63C1F0
#define PcZoneClient__BandolierSwap_x                              0x6371E0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x638CA0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5CC5C0

//IconCache
#define IconCache__GetIcon_x                                       0x70E290

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x705DB0
#define CContainerMgr__CloseContainer_x                            0x706080
#define CContainerMgr__OpenExperimentContainer_x                   0x706B00

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7C8D50

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x609590

//CLootWnd
#define CLootWnd__LootAll_x                                        0x764020
#define CLootWnd__RequestLootSlot_x                                0x763240

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x566760
#define EQ_Spell__SpellAffects_x                                   0x566BD0
#define EQ_Spell__SpellAffectBase_x                                0x566990
#define EQ_Spell__IsStackable_x                                    0x4C6FA0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C6E80
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B43F0
#define EQ_Spell__IsSPAStacking_x                                  0x567A00
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x566F20
#define EQ_Spell__IsNoRemove_x                                     0x4C6F80
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x567A10
#define __IsResEffectSpell_x                                       0x4C6390

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AAC90

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C64D0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x80E930
#define CTargetWnd__WndNotification_x                              0x80E1C0
#define CTargetWnd__RefreshTargetBuffs_x                           0x80E490
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x80D320

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x812EF0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x52B390
#define CTaskManager__HandleMessage_x                              0x529A80

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x561D10
#define EqSoundManager__PlayScriptMp3_x                            0x561E70
#define EqSoundManager__SoundAssistPlay_x                          0x6739F0
#define EqSoundManager__WaveInstancePlay_x                         0x672F60

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x51F3B0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x9456E0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x555B80
#define CAltAbilityData__GetMercMaxRank_x                          0x555B20
#define CAltAbilityData__GetMaxRank_x                              0x54B2D0

//CTargetRing
#define CTargetRing__Cast_x                                        0x607680

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C6E60
#define CharacterBase__CreateItemGlobalIndex_x                     0x504D20
#define CharacterBase__CreateItemIndex_x                           0x60F790
#define CharacterBase__GetItemPossession_x                         0x4F0900
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CEB50
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CEBB0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6ED0C0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6ED8F0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6ED9A0

//messages
#define msg_spell_worn_off_x                                       0x58B490
#define msg_new_text_x                                             0x5802F0
#define __msgTokenTextParam_x                                      0x58D9C0
#define msgTokenText_x                                             0x58DC10

//SpellManager
#define SpellManager__vftable_x                                    0xAC5CB0
#define SpellManager__SpellManager_x                               0x676D20
#define Spellmanager__LoadTextSpells_x                             0x677620
#define SpellManager__GetSpellByGroupAndRank_x                     0x676EF0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98D870

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x505400
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x591750
#define ItemGlobalIndex__IsEquippedLocation_x                      0x628100
#define ItemGlobalIndex__IsValidIndex_x                            0x505460

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C6E70
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C70F0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x75C8B0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x70A4B0
#define CCursorAttachment__AttachToCursor1_x                       0x70A4F0
#define CCursorAttachment__Deactivate_x                            0x70B4D0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x938390
#define CSidlManagerBase__CreatePageWnd_x                          0x937BA0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x933E00
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x933D90

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x955450
#define CEQSuiteTextureLoader__GetTexture_x                        0x955110

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x502290
#define CFindItemWnd__WndNotification_x                            0x502D70
#define CFindItemWnd__Update_x                                     0x5038E0
#define CFindItemWnd__PickupSelectedItem_x                         0x501B00

//IString
#define IString__Append_x                                          0x4F1EA0

//Camera
#define CDisplay__cameraType_x                                     0xDD8AF0
#define EverQuest__Cameras_x                                       0xE9BED0

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x50AC70
#define LootFiltersManager__GetItemFilterData_x                    0x50A560
#define LootFiltersManager__RemoveItemLootFilter_x                 0x50A590
#define LootFiltersManager__SetItemLootFilter_x                    0x50A7B0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B6D80

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9934B0
#define CResolutionHandler__GetWindowedStyle_x                     0x66E4E0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x702B80

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D9680
#define CDistillerInfo__Instance_x                                 0x8D9620

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x722E80
#define CGroupWnd__UpdateDisplay_x                                 0x7221F0

//ItemBase
#define ItemBase__IsLore_x                                         0x89CA30
#define ItemBase__IsLoreEquipped_x                                 0x89CAA0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5C6760
#define EQPlacedItemManager__GetItemByGuid_x                       0x5C68A0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5C6900

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x663F10
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x6678F0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x4F8670

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4E7750
#define FactionManagerClient__HandleFactionMessage_x               0x4E7DC0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4E83F0
#define FactionManagerClient__GetMaxFaction_x                      0x4E8440
#define FactionManagerClient__GetMinFaction_x                      0x4E83C0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4F08D0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91CAF0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x4974F0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4F0AF0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x555060

//CTargetManager
#define CTargetManager__Get_x                                      0x67A570

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x663F10

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A69E0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x599B10

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF39560

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
