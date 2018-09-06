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
#define __ExpectedVersionDate                                     "Sep  4 2018"
#define __ExpectedVersionTime                                     "14:25:44"
#define __ActualVersionDate_x                                      0xAC0694
#define __ActualVersionTime_x                                      0xAC0688

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x609B90
#define __MemChecker1_x                                            0x8DB800
#define __MemChecker2_x                                            0x698390
#define __MemChecker3_x                                            0x6982E0
#define __MemChecker4_x                                            0x834F10
#define __EncryptPad0_x                                            0xBF24A8
#define __EncryptPad1_x                                            0xC50188
#define __EncryptPad2_x                                            0xC03030
#define __EncryptPad3_x                                            0xC02C30
#define __EncryptPad4_x                                            0xC40F20
#define __EncryptPad5_x                                            0xF0DBC8
#define __AC1_x                                                    0x7F1946
#define __AC2_x                                                    0x5C578F
#define __AC3_x                                                    0x5CC61F
#define __AC4_x                                                    0x5D0490
#define __AC5_x                                                    0x5D66B0
#define __AC6_x                                                    0x5DAB42
#define __AC7_x                                                    0x5C5200
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1AFAC4

// Direct Input
#define DI8__Main_x                                                0xF0DBEC
#define DI8__Keyboard_x                                            0xF0DBF0
#define DI8__Mouse_x                                               0xF0DBB0
#define DI8__Mouse_Copy_x                                          0xE6B91C
#define DI8__Mouse_Check_x                                         0xF0EAB0
#define __AutoSkillArray_x                                         0xE6C82C
#define __Attack_x                                                 0xF0A62B
#define __Autofire_x                                               0xF0A62C
#define __BindList_x                                               0xBE1098
#define g_eqCommandStates_x                                        0xBE1E08
#define __Clicks_x                                                 0xE6B9D4
#define __CommandList_x                                            0xBE29C0
#define __CurrentMapLabel_x                                        0x10201D4
#define __CurrentSocial_x                                          0xBCC710
#define __DoAbilityList_x                                          0xEA214C
#define __do_loot_x                                                0x592F50
#define __DrawHandler_x                                            0x169B6E8
#define __GroupCount_x                                             0xE5BBE2
#define __Guilds_x                                                 0xE62128
#define __gWorld_x                                                 0xE5C134
#define __HWnd_x                                                   0xF0DBB4
#define __heqmain_x                                                0x1018E0C
#define __InChatMode_x                                             0xE6B904
#define __LastTell_x                                               0xE6D848
#define __LMouseHeldTime_x                                         0xE6BA40
#define __Mouse_x                                                  0xF0DBD4
#define __MouseLook_x                                              0xE6B99A
#define __MouseEventTime_x                                         0xF0B0E0
#define __gpbCommandEvent_x                                        0xE5BE60
#define __NetStatusToggle_x                                        0xE6B99D
#define __PCNames_x                                                0xE6CE08
#define __RangeAttackReady_x                                       0xE6CB10
#define __RMouseHeldTime_x                                         0xE6BA3C
#define __RunWalkState_x                                           0xE6B908
#define __ScreenMode_x                                             0xDAA484
#define __ScreenX_x                                                0xE6B8BC
#define __ScreenY_x                                                0xE6B8B8
#define __ScreenXMax_x                                             0xE6B8C0
#define __ScreenYMax_x                                             0xE6B8C4
#define __ServerHost_x                                             0xE5C02B
#define __ServerName_x                                             0xEA210C
#define __ShiftKeyDown_x                                           0xE6BF94
#define __ShowNames_x                                              0xE6CCCC
#define __Socials_x                                                0xEA220C
#define __SubscriptionType_x                                       0x1061C9C
#define __TargetAggroHolder_x                                      0x1022B8C
#define __ZoneType_x                                               0xE6BD98
#define __GroupAggro_x                                             0x1022BCC
#define __LoginName_x                                              0xF0E444
#define __Inviter_x                                                0xF0A5A8
#define __AttackOnAssist_x                                         0xE6CC88
#define __UseTellWindows_x                                         0xE6CFA0
#define __gfMaxZoomCameraDistance_x                                0xAB5AF0
#define __gfMaxCameraDistance_x                                    0xAE3070
#define __pulAutoRun_x                                             0xE6B9B8
#define __pulForward_x                                             0xE6CFD8
#define __pulBackward_x                                            0xE6CFDC
#define __pulTurnRight_x                                           0xE6CFE0
#define __pulTurnLeft_x                                            0xE6CFE4
#define __pulStrafeLeft_x                                          0xE6CFE8
#define __pulStrafeRight_x                                         0xE6CFEC

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE5E4D0
#define instEQZoneInfo_x                                           0xE6BB90
#define instKeypressHandler_x                                      0xF0B090
#define pinstActiveBanker_x                                        0xE5E47C
#define pinstActiveCorpse_x                                        0xE5E474
#define pinstActiveGMaster_x                                       0xE5E478
#define pinstActiveMerchant_x                                      0xE5E470
#define pinstAggroInfo_x                                           0xC66858
#define pinstAltAdvManager_x                                       0xDAAE70
#define pinstAuraMgr_x                                             0xC77540
#define pinstBandageTarget_x                                       0xE5E48C
#define pinstCamActor_x                                            0xDAA478
#define pinstCDBStr_x                                              0xDA9BAC
#define pinstCDisplay_x                                            0xE5BBC4
#define pinstCEverQuest_x                                          0xF0DD08
#define pinstEverQuestInfo_x                                       0xE6B8B0
#define pinstCharData_x                                            0xE5BDD8
#define pinstCharSpawn_x                                           0xE5E4C4
#define pinstControlledMissile_x                                   0xE5BDDC
#define pinstControlledPlayer_x                                    0xE5E4C4
#define pinstCResolutionHandler_x                                  0x169B918
#define pinstCSidlManager_x                                        0x169A7AC
#define pinstCXWndManager_x                                        0x169A7A0
#define instDynamicZone_x                                          0xE62000
#define pinstDZMember_x                                            0xE62110
#define pinstDZTimerInfo_x                                         0xE62114
#define pinstEQItemList_x                                          0xE5A6C0
#define pinstEQObjectList_x                                        0xE5B8B0
#define instEQMisc_x                                               0xDA9AE8
#define pinstEQSoundManager_x                                      0xDAB6D0
#define pinstEQSpellStrings_x                                      0xC74990
#define instExpeditionLeader_x                                     0xE6204A
#define instExpeditionName_x                                       0xE6208A
#define pinstGroup_x                                               0xE5BBDE
#define pinstImeManager_x                                          0x169A7A4
#define pinstLocalPlayer_x                                         0xE5E46C
#define pinstMercenaryData_x                                       0xF0B880
#define pinstMercenaryStats_x                                      0x1022CD8
#define pinstMercAltAbilities_x                                    0xDAB440
#define pinstModelPlayer_x                                         0xE5E484
#define pinstPCData_x                                              0xE5BDD8
#define pinstRealEstateItems_x                                     0xF0CD70
#define pinstSkillMgr_x                                            0xF0CE40
#define pinstSpawnManager_x                                        0xF0C430
#define pinstSpellManager_x                                        0xF0D018
#define pinstSpellSets_x                                           0xF03254
#define pinstStringTable_x                                         0xE5E340
#define pinstSwitchManager_x                                       0xE5BA70
#define pinstTarget_x                                              0xE5E4C0
#define pinstTargetObject_x                                        0xE5BBC0
#define pinstTargetSwitch_x                                        0xE5BDE4
#define pinstTaskMember_x                                          0xDA9978
#define pinstTrackTarget_x                                         0xE5E4C8
#define pinstTradeTarget_x                                         0xE5E480
#define instTributeActive_x                                        0xDA9B0D
#define pinstViewActor_x                                           0xDAA470
#define pinstWorldData_x                                           0xE5BE18
#define pinstZoneAddr_x                                            0xE6BE30
#define pinstPlayerPath_x                                          0xF0C4C8
#define pinstTargetIndicator_x                                     0xF0D280
#define pinstCTargetManager_x                                      0xF0D318
#define EQObject_Top_x                                             0xE5E468
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDA9EE8
#define pinstCAchievementsWnd_x                                    0xDA9F88
#define pinstCActionsWnd_x                                         0xDA9F40
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDA9CD0
#define pinstCAdvancedLootWnd_x                                    0xDA9C80
#define pinstCAdventureLeaderboardWnd_x                            0x10199A8
#define pinstCAdventureRequestWnd_x                                0x1019A58
#define pinstCAdventureStatsWnd_x                                  0x1019B08
#define pinstCAggroMeterWnd_x                                      0xDA9FB0
#define pinstCAlarmWnd_x                                           0xDA9F6C
#define pinstCAlertHistoryWnd_x                                    0xDA9F48
#define pinstCAlertStackWnd_x                                      0xDA9EE4
#define pinstCAlertWnd_x                                           0xDA9EF8
#define pinstCAltStorageWnd_x                                      0x1019E68
#define pinstCAudioTriggersWindow_x                                0xC66CE8
#define pinstCAuraWnd_x                                            0xDA9FA8
#define pinstCAvaZoneWnd_x                                         0xDA9F2C
#define pinstCBandolierWnd_x                                       0xDA9FE8
#define pinstCBankWnd_x                                            0xDA9C78
#define pinstCBarterMerchantWnd_x                                  0x101B0A8
#define pinstCBarterSearchWnd_x                                    0x101B158
#define pinstCBarterWnd_x                                          0x101B208
#define pinstCBazaarConfirmationWnd_x                              0xDA9EDC
#define pinstCBazaarSearchWnd_x                                    0xDA9F50
#define pinstCBazaarWnd_x                                          0xDA9FE0
#define pinstCBlockedBuffWnd_x                                     0xDA9C5C
#define pinstCBlockedPetBuffWnd_x                                  0xDA9C88
#define pinstCBodyTintWnd_x                                        0xDA9F04
#define pinstCBookWnd_x                                            0xDAA490
#define pinstCBreathWnd_x                                          0xDA9EF4
#define pinstCBuffWindowNORMAL_x                                   0xDAA4D0
#define pinstCBuffWindowSHORT_x                                    0xDAA4D4
#define pinstCBugReportWnd_x                                       0xDA9ED8
#define pinstCButtonWnd_x                                          0x169A998
#define pinstCCastingWnd_x                                         0xDA9CD4
#define pinstCCastSpellWnd_x                                       0xDA9F68
//#define pinstCCharacterCreationWnd_x                               0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDA9F00
#define pinstCChatWindowManager_x                                  0x101BCC8
#define pinstCClaimWnd_x                                           0x101BE20
#define pinstCColorPickerWnd_x                                     0xDA9F18
#define pinstCCombatAbilityWnd_x                                   0xDA9FB8
#define pinstCCombatSkillsSelectWnd_x                              0xDA9F3C
#define pinstCCompassWnd_x                                         0xDA9EEC
#define pinstCConfirmationDialog_x                                 0x1020D20
#define pinstCContainerMgr_x                                       0xDA9FDC
#define pinstCContextMenuManager_x                                 0x169A760
#define pinstCCursorAttachment_x                                   0xDA9CC8
#define pinstCDynamicZoneWnd_x                                     0x101C3E8
#define pinstCEditLabelWnd_x                                       0xDAA49C
#define pinstCEQMainWnd_x                                          0x101C630
#define pinstCEventCalendarWnd_x                                   0xDA9FAC
#define pinstCExtendedTargetWnd_x                                  0xDA9FA0
#define pinstCFacePick_x                                           0xDA9F20
#define pinstCFellowshipWnd_x                                      0x101C830
#define pinstCFileSelectionWnd_x                                   0xDA9C60
#define pinstCFindItemWnd_x                                        0xDA9FD4
#define pinstCFindLocationWnd_x                                    0x101C988
#define pinstCFriendsWnd_x                                         0xDA9F54
#define pinstCGemsGameWnd_x                                        0xDA9F44
#define pinstCGiveWnd_x                                            0xDAA474
#define pinstCGroupSearchFiltersWnd_x                              0xDA9FC4
#define pinstCGroupSearchWnd_x                                     0x101CD80
#define pinstCGroupWnd_x                                           0x101CE30
#define pinstCGuildBankWnd_x                                       0xE6CC6C
#define pinstCGuildCreationWnd_x                                   0x101CF90
#define pinstCGuildMgmtWnd_x                                       0x101D040
#define pinstCharacterCreation_x                                   0xDA9FB4
#define pinstCHelpWnd_x                                            0xDA9F78
#define pinstCHeritageSelectionWnd_x                               0xDA9F28
#define pinstCHotButtonWnd_x                                       0x101F198
#define pinstCHotButtonWnd1_x                                      0x101F198
#define pinstCHotButtonWnd2_x                                      0x101F19C
#define pinstCHotButtonWnd3_x                                      0x101F1A0
#define pinstCHotButtonWnd4_x                                      0x101F1A4
#define pinstCIconSelectionWnd_x                                   0xDA9CA0
#define pinstCInspectWnd_x                                         0xDA9C94
#define pinstCInventoryWnd_x                                       0xDA9FF8
#define pinstCInvSlotMgr_x                                         0xDA9F8C
#define pinstCItemDisplayManager_x                                 0x101F728
#define pinstCItemExpTransferWnd_x                                 0x101F858
#define pinstCItemOverflowWnd_x                                    0xDA9F58
#define pinstCJournalCatWnd_x                                      0xDA9C8C
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDAA4C8
#define pinstCKeyRingWnd_x                                         0xDA9C4C
#define pinstCLargeDialogWnd_x                                     0x10219A0
#define pinstCLayoutCopyWnd_x                                      0x101FBA8
#define pinstCLFGuildWnd_x                                         0x101FC58
#define pinstCLoadskinWnd_x                                        0xDA9F60
#define pinstCLootFiltersCopyWnd_x                                 0xC77D20
#define pinstCLootFiltersWnd_x                                     0xDA9F0C
#define pinstCLootSettingsWnd_x                                    0xDA9F14
#define pinstCLootWnd_x                                            0xDA9F10
#define pinstCMailAddressBookWnd_x                                 0xDA9CA4
#define pinstCMailCompositionWnd_x                                 0xDA9C7C
#define pinstCMailIgnoreListWnd_x                                  0xDA9CA8
#define pinstCMailWnd_x                                            0xDA9C50
#define pinstCManageLootWnd_x                                      0xDAB2E8
#define pinstCMapToolbarWnd_x                                      0xDAA064
#define pinstCMapViewWnd_x                                         0xDA9FD0
#define pinstCMarketplaceWnd_x                                     0xDA9FD8
#define pinstCMerchantWnd_x                                        0xDA9F38
#define pinstCMIZoneSelectWnd_x                                    0x1020490
#define pinstCMusicPlayerWnd_x                                     0xDA9C48
#define pinstCNameChangeMercWnd_x                                  0xDA9C84
#define pinstCNameChangePetWnd_x                                   0xDA9C58
#define pinstCNameChangeWnd_x                                      0xDA9FBC
#define pinstCNoteWnd_x                                            0xDA9F74
#define pinstCObjectPreviewWnd_x                                   0xDAA498
#define pinstCOptionsWnd_x                                         0xDAA068
#define pinstCPetInfoWnd_x                                         0xDA9C6C
#define pinstCPetitionQWnd_x                                       0xDA9CAC
//#define pinstCPlayerCustomizationWnd_x                             0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDA9EFC
#define pinstCPlayerWnd_x                                          0xDA9F64
#define pinstCPopupWndManager_x                                    0x1020D20
#define pinstCProgressionSelectionWnd_x                            0x1020DD0
#define pinstCPurchaseGroupWnd_x                                   0xDA9C54
#define pinstCPurchaseWnd_x                                        0xDAA4C4
#define pinstCPvPLeaderboardWnd_x                                  0x1020E80
#define pinstCPvPStatsWnd_x                                        0x1020F30
#define pinstCQuantityWnd_x                                        0xDA9CB4
#define pinstCRaceChangeWnd_x                                      0xDA9FE4
#define pinstCRaidOptionsWnd_x                                     0xDA9FCC
#define pinstCRaidWnd_x                                            0xDA9CB8
#define pinstCRealEstateItemsWnd_x                                 0xDA9F98
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDA9FC8
#define pinstCRealEstateManageWnd_x                                0xDA9F30
#define pinstCRealEstateNeighborhoodWnd_x                          0xDA9F4C
#define pinstCRealEstatePlotSearchWnd_x                            0xDA9F70
#define pinstCRealEstatePurchaseWnd_x                              0xDA9F80
#define pinstCRespawnWnd_x                                         0xDA9FC0
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDA9F9C
#define pinstCSendMoneyWnd_x                                       0xDAA4B8
#define pinstCServerListWnd_x                                      0xDA9F90
#define pinstCSkillsSelectWnd_x                                    0xDA9F1C
#define pinstCSkillsWnd_x                                          0xDA9F08
#define pinstCSocialEditWnd_x                                      0xDA9CBC
#define pinstCSocialWnd_x                                          0xDA9CC4
#define pinstCSpellBookWnd_x                                       0xDA9F94
#define pinstCStoryWnd_x                                           0xDA9EE0
#define pinstCTargetOfTargetWnd_x                                  0x1022D60
#define pinstCTargetWnd_x                                          0xDA9C68
#define pinstCTaskOverlayWnd_x                                     0xDA9F5C
#define pinstCTaskSelectWnd_x                                      0x1022EB8
#define pinstCTaskSomething_x                                      0xC78520
#define pinstCTaskTemplateSelectWnd_x                              0x1022F68
#define pinstCTaskWnd_x                                            0x1023018
#define pinstCTextEntryWnd_x                                       0xDA9EF0
#define pinstCTextOverlay_x                                        0xC66FF8
#define pinstCTimeLeftWnd_x                                        0xDA9C70
#define pinstCTipWndCONTEXT_x                                      0x102321C
#define pinstCTipWndOFDAY_x                                        0x1023218
#define pinstCTitleWnd_x                                           0x10232C8
#define pinstCTrackingWnd_x                                        0xDA9C64
#define pinstCTradeskillWnd_x                                      0x1023430
#define pinstCTradeWnd_x                                           0xDA9F7C
#define pinstCTrainWnd_x                                           0xDA9CB0
#define pinstCTributeBenefitWnd_x                                  0x1023630
#define pinstCTributeMasterWnd_x                                   0x10236E0
#define pinstCTributeTrophyWnd_x                                   0x1023790
#define pinstCVideoModesWnd_x                                      0xDA9C74
#define pinstCVoiceMacroWnd_x                                      0xF0D848
#define pinstCVoteResultsWnd_x                                     0xDAA4CC
#define pinstCVoteWnd_x                                            0xDAA494
#define pinstCWebManager_x                                         0xF0D9AC
#define pinstCZoneGuideWnd_x                                       0xDA9F24
#define pinstCZonePathWnd_x                                        0xDA9F34

#define pinstEQSuiteTextureLoader_x                                0xC51C40
#define pinstItemIconCache_x                                       0x101C5E8
#define pinstLootFiltersManager_x                                  0xC77DD0
#define pinstRewardSelectionWnd_x                                  0x1021678

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC02C24
#define __CastRay_x                                                0x58E470
#define __CastRay2_x                                               0x58E4C0
#define __ConvertItemTags_x                                        0x5A90C0
#define __CrashHandler_x                                           0x83E8B0
#define __EQGetTime_x                                              0x8DB130
#define __ExecuteCmd_x                                             0x586E10
#define __FixHeading_x                                             0x96BD50
#define __get_bearing_x                                            0x58DFB0
#define __get_melee_range_x                                        0x58E6B0
#define __GetAnimationCache_x                                      0x6FBF40
#define __GetGaugeValueFromEQ_x                                    0x7F0160
#define __GetLabelFromEQ_x                                         0x7F18D0
#define __GetXTargetType_x                                         0x96D7B0
#define __HeadingDiff_x                                            0x96BDC0
#define __HelpPath_x                                               0xF0ACFC
#define __LoadFrontEnd_x                                           0x6941F0
#define __NewUIINI_x                                               0x7EFE30
#define __pCrashHandler_x                                          0x1040AF8
#define __ProcessGameEvents_x                                      0x5EB590
#define __ProcessMouseEvent_x                                      0x5EAD50
#define __SaveColors_x                                             0x537FE0
#define __STMLToText_x                                             0x90ED70
#define __ToggleKeyRingItem_x                                      0x4FB270
#define CrashDetected_x                                            0x695CE0
#define DrawNetStatus_x                                            0x616FB0
#define Expansion_HoT_x                                            0xE6CC74
#define Teleport_Table_Size_x                                      0xE5BEE8
#define Teleport_Table_x                                           0xE5C340
#define Util__FastTime_x                                           0x8DACF0
#define wwsCrashReportCheckForUploader_x                           0x83F3E0
#define wwsCrashReportPlatformLaunchUploader_x                     0x841AA0
#define __HandleMouseWheel_x                                       0x698440

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48A750
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x493540
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x493320

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x53F960
#define AltAdvManager__IsAbilityReady_x                            0x53E9E0
#define AltAdvManager__GetAAById_x                                 0x53EBE0
#define AltAdvManager__CanTrainAbility_x                           0x53EC50
#define AltAdvManager__CanSeeAbility_x                             0x53EE80

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C6330
#define CharacterZoneClient__HasSkill_x                            0x4D0ED0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D25F0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BA5D0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B6C90
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D4D50
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D4E30
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D4F10
#define CharacterZoneClient__FindAffectSlot_x                      0x4BF200
#define CharacterZoneClient__BardCastBard_x                        0x4C1E70
#define CharacterZoneClient__GetMaxEffects_x                       0x4B6D60
#define CharacterZoneClient__GetEffect_x                           0x4B6BD0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C0210
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C02E0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C0330
#define CharacterZoneClient__CalcAffectChange_x                    0x4C0480
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C0650

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6BE4D0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6CBD80

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5F9970
#define CButtonWnd__CButtonWnd_x                                   0x90B170

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6EA910
#define CChatManager__InitContextMenu_x                            0x6E4A20
#define CChatManager__FreeChatWindow_x                             0x6E9830
#define CChatManager__GetLockedActiveChatWindow_x                  0x6EE1A0
#define CChatManager__SetLockedActiveChatWindow_x                  0x6EA6B0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x91F910
#define CContextMenu__dCContextMenu_x                              0x91FB40
#define CContextMenu__AddMenuItem_x                                0x91FB50
#define CContextMenu__RemoveMenuItem_x                             0x91FE60
#define CContextMenu__RemoveAllMenuItems_x                         0x91FE80
#define CContextMenu__CheckMenuItem_x                              0x91FF00
#define CContextMenu__SetMenuItem_x                                0x91FD80

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x9204A0
#define CContextMenuManager__RemoveMenu_x                          0x920510
#define CContextMenuManager__PopupMenu_x                           0x9205D0
#define CContextMenuManager__Flush_x                               0x920440
#define CContextMenuManager__GetMenu_x                             0x495760

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8BCE90
#define CChatService__GetFriendName_x                              0x8BCEA0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6EAE80
#define CChatWindow__Clear_x                                       0x6EBED0
#define CChatWindow__WndNotification_x                             0x6EC430

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x91CDB0
#define CComboWnd__Draw_x                                          0x91C2B0
#define CComboWnd__GetCurChoice_x                                  0x91CBF0
#define CComboWnd__GetListRect_x                                   0x91C760
#define CComboWnd__GetTextRect_x                                   0x91CE20
#define CComboWnd__InsertChoice_x                                  0x91C8F0
#define CComboWnd__SetColors_x                                     0x91C8C0
#define CComboWnd__SetChoice_x                                     0x91CBC0
#define CComboWnd__GetItemCount_x                                  0x91CC00
#define CComboWnd__GetCurChoiceText_x                              0x91CC40

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6F4150
#define CContainerWnd__vftable_x                                   0xAC9A78
#define CContainerWnd__SetContainer_x                              0x6F56C0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x537DA0
#define CDisplay__GetClickedActor_x                                0x52AE00
#define CDisplay__GetUserDefinedColor_x                            0x5234E0
#define CDisplay__GetWorldFilePath_x                               0x52C850
#define CDisplay__is3dON_x                                         0x527AD0
#define CDisplay__ReloadUI_x                                       0x531F70
#define CDisplay__WriteTextHD2_x                                   0x5278B0
#define CDisplay__TrueDistance_x                                   0x52E4B0
#define CDisplay__SetViewActor_x                                   0x52A750

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x93F420

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x924010
#define CEditWnd__GetCharIndexPt_x                                 0x924F10
#define CEditWnd__GetDisplayString_x                               0x924DB0
#define CEditWnd__GetHorzOffset_x                                  0x923640
#define CEditWnd__GetLineForPrintableChar_x                        0x926050
#define CEditWnd__GetSelStartPt_x                                  0x9251C0
#define CEditWnd__GetSTMLSafeText_x                                0x924BD0
#define CEditWnd__PointFromPrintableChar_x                         0x925C80
#define CEditWnd__SelectableCharFromPoint_x                        0x925DF0
#define CEditWnd__SetEditable_x                                    0x925290

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5DA070
#define CEverQuest__ClickedPlayer_x                                0x5CC400
#define CEverQuest__CreateTargetIndicator_x                        0x5E8870
#define CEverQuest__DeleteTargetIndicator_x                        0x5E8900
#define CEverQuest__DoTellWindow_x                                 0x4E11C0
#define CEverQuest__OutputTextToLog_x                              0x4E13F0
#define CEverQuest__DropHeldItemOnGround_x                         0x5C1CC0
#define CEverQuest__dsp_chat_x                                     0x4E1780
#define CEverQuest__trimName_x                                     0x5E4E30
#define CEverQuest__Emote_x                                        0x5DA880
#define CEverQuest__EnterZone_x                                    0x5D4AA0
#define CEverQuest__GetBodyTypeDesc_x                              0x5DE6D0
#define CEverQuest__GetClassDesc_x                                 0x5DED10
#define CEverQuest__GetClassThreeLetterCode_x                      0x5DF310
#define CEverQuest__GetDeityDesc_x                                 0x5E71C0
#define CEverQuest__GetLangDesc_x                                  0x5DF4D0
#define CEverQuest__GetRaceDesc_x                                  0x5DECF0
#define CEverQuest__InterpretCmd_x                                 0x5E7790
#define CEverQuest__LeftClickedOnPlayer_x                          0x5C5EB0
#define CEverQuest__LMouseUp_x                                     0x5C4230
#define CEverQuest__RightClickedOnPlayer_x                         0x5C6790
#define CEverQuest__RMouseUp_x                                     0x5C51C0
#define CEverQuest__SetGameState_x                                 0x5C1A50
#define CEverQuest__UPCNotificationFlush_x                         0x5E4D30
#define CEverQuest__IssuePetCommand_x                              0x5E08D0
#define CEverQuest__ReportSuccessfulHit_x                          0x5DB520

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7060D0
#define CGaugeWnd__CalcLinesFillRect_x                             0x706130
#define CGaugeWnd__Draw_x                                          0x7057D0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ABC80
#define CGuild__GetGuildName_x                                     0x4AACC0
#define CGuild__GetGuildIndex_x                                    0x4AB050

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x721420

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x72E2D0
#define CInvSlotMgr__MoveItem_x                                    0x72D030
#define CInvSlotMgr__SelectSlot_x                                  0x72E3A0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x72B8E0
#define CInvSlot__SliderComplete_x                                 0x729700
#define CInvSlot__GetItemBase_x                                    0x729090
#define CInvSlot__UpdateItem_x                                     0x729200

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x72FCD0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x72EFA0
#define CInvSlotWnd__HandleLButtonUp_x                             0x72F850

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7EC350
#define CItemDisplayWnd__UpdateStrings_x                           0x73E8E0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x738930
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x738E10
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x73EE70
#define CItemDisplayWnd__AboutToShow_x                             0x73E530
#define CItemDisplayWnd__WndNotification_x                         0x740180

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x823A50

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x7441F0

// CLabel 
#define CLabel__Draw_x                                             0x749D90

// CListWnd
#define CListWnd__CListWnd_x                                       0x8F56E0
#define CListWnd__dCListWnd_x                                      0x8F5A00
#define CListWnd__AddColumn_x                                      0x8F9D40
#define CListWnd__AddColumn1_x                                     0x8F9D90
#define CListWnd__AddLine_x                                        0x8FA120
#define CListWnd__AddString_x                                      0x8F9F20
#define CListWnd__CalculateFirstVisibleLine_x                      0x8F9B00
#define CListWnd__CalculateVSBRange_x                              0x8F98E0
#define CListWnd__ClearSel_x                                       0x8FA900
#define CListWnd__ClearAllSel_x                                    0x8FA960
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8FB370
#define CListWnd__Compare_x                                        0x8F9220
#define CListWnd__Draw_x                                           0x8F5B00
#define CListWnd__DrawColumnSeparators_x                           0x8F82F0
#define CListWnd__DrawHeader_x                                     0x8F8760
#define CListWnd__DrawItem_x                                       0x8F8B60
#define CListWnd__DrawLine_x                                       0x8F8460
#define CListWnd__DrawSeparator_x                                  0x8F8390
#define CListWnd__EnableLine_x                                     0x8F7BC0
#define CListWnd__EnsureVisible_x                                  0x8FB290
#define CListWnd__ExtendSel_x                                      0x8FA830
#define CListWnd__GetColumnMinWidth_x                              0x8F7700
#define CListWnd__GetColumnWidth_x                                 0x8F7670
#define CListWnd__GetCurSel_x                                      0x8F7000
#define CListWnd__GetItemAtPoint_x                                 0x8F7E40
#define CListWnd__GetItemAtPoint1_x                                0x8F7EB0
#define CListWnd__GetItemData_x                                    0x8F7080
#define CListWnd__GetItemHeight_x                                  0x8F7440
#define CListWnd__GetItemIcon_x                                    0x8F7210
#define CListWnd__GetItemRect_x                                    0x8F7CB0
#define CListWnd__GetItemText_x                                    0x8F70C0
#define CListWnd__GetSelList_x                                     0x8FA9B0
#define CListWnd__GetSeparatorRect_x                               0x8F80F0
#define CListWnd__InsertLine_x                                     0x8FA510
#define CListWnd__RemoveLine_x                                     0x8FA660
#define CListWnd__SetColors_x                                      0x8F98B0
#define CListWnd__SetColumnJustification_x                         0x8F95E0
#define CListWnd__SetColumnWidth_x                                 0x8F9500
#define CListWnd__SetCurSel_x                                      0x8FA770
#define CListWnd__SetItemColor_x                                   0x8FAF40
#define CListWnd__SetItemData_x                                    0x8FAF00
#define CListWnd__SetItemText_x                                    0x8FAB30
#define CListWnd__ShiftColumnSeparator_x                           0x8F96A0
#define CListWnd__Sort_x                                           0x8F93A0
#define CListWnd__ToggleSel_x                                      0x8FA7A0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x75F210

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x782300
#define CMerchantWnd__RequestBuyItem_x                             0x782BE0
#define CMerchantWnd__RequestSellItem_x                            0x783120
#define CMerchantWnd__SelectRecoverySlot_x                         0x785F60
//did this get another arg?
#define CMerchantWnd__SelectBuySellSlot_x                          0x782960
#define CMerchantWnd__ActualSelect_x                               0x78BAD0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x88AF10
#define CPacketScrambler__hton_x                                   0x88AF00

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x914350
#define CSidlManager__FindScreenPieceTemplate_x                    0x914760
#define CSidlManager__FindScreenPieceTemplate1_x                   0x914550
#define CSidlManager__CreateLabel_x                                0x7E3830
#define CSidlManager__CreateXWndFromTemplate_x                     0x917830
#define CSidlManager__CreateXWndFromTemplate1_x                    0x917A10

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x910ED0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x910DD0
#define CSidlScreenWnd__ConvertToRes_x                             0x935BB0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x910870
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x910560
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x910630
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x910700
#define CSidlScreenWnd__DrawSidlPiece_x                            0x911370
#define CSidlScreenWnd__EnableIniStorage_x                         0x911840
#define CSidlScreenWnd__GetSidlPiece_x                             0x911560
#define CSidlScreenWnd__Init1_x                                    0x910150
#define CSidlScreenWnd__LoadIniInfo_x                              0x911890
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9123C0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x90F550
#define CSidlScreenWnd__StoreIniInfo_x                             0x911F40
#define CSidlScreenWnd__StoreIniVis_x                              0x9122A0
#define CSidlScreenWnd__WndNotification_x                          0x911280
#define CSidlScreenWnd__GetChildItem_x                             0x9117C0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x901150
#define CSidlScreenWnd__m_layoutCopy_x                             0x169A630

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x65D740
#define CSkillMgr__GetSkillCap_x                                   0x65D920
#define CSkillMgr__GetNameToken_x                                  0x65CED0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x921280
#define CSliderWnd__SetValue_x                                     0x9210F0
#define CSliderWnd__SetNumTicks_x                                  0x921150

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7E95D0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x927F00
#define CStmlWnd__CalculateHSBRange_x                              0x928F90
#define CStmlWnd__CalculateVSBRange_x                              0x928F00
#define CStmlWnd__CanBreakAtCharacter_x                            0x92D2C0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x92DEB0
#define CStmlWnd__ForceParseNow_x                                  0x9284A0
#define CStmlWnd__GetNextTagPiece_x                                0x92D220
#define CStmlWnd__GetSTMLText_x                                    0x4EF660
#define CStmlWnd__GetVisibleText_x                                 0x9284C0
#define CStmlWnd__InitializeWindowVariables_x                      0x92DD00
#define CStmlWnd__MakeStmlColorTag_x                               0x927690
#define CStmlWnd__MakeWndNotificationTag_x                         0x927700
#define CStmlWnd__SetSTMLText_x                                    0x926760
#define CStmlWnd__StripFirstSTMLLines_x                            0x92F010
#define CStmlWnd__UpdateHistoryString_x                            0x92E0C0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x932710
#define CTabWnd__DrawCurrentPage_x                                 0x932D30
#define CTabWnd__DrawTab_x                                         0x932B00
#define CTabWnd__GetCurrentPage_x                                  0x931F70
#define CTabWnd__GetPageInnerRect_x                                0x9321B0
#define CTabWnd__GetTabInnerRect_x                                 0x9320F0
#define CTabWnd__GetTabRect_x                                      0x931FA0
#define CTabWnd__InsertPage_x                                      0x9323A0
#define CTabWnd__SetPage_x                                         0x932230
#define CTabWnd__SetPageRect_x                                     0x932650
#define CTabWnd__UpdatePage_x                                      0x9329C0
#define CTabWnd__GetPageFromTabIndex_x                             0x932A40
#define CTabWnd__GetCurrentTabIndex_x                              0x931F60

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x744710
#define CPageWnd__SetTabText_x                                     0x93F830

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A57A0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8FE010
#define CTextureFont__GetTextExtent_x                              0x8FE1D0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x690F90
#define CHtmlComponentWnd__ValidateUri_x                           0x722E10
#define CHtmlWnd__SetClientCallbacks_x                             0x5FECE0
#define CHtmlWnd__AddObserver_x                                    0x5FED00
#define CHtmlWnd__RemoveObserver_x                                 0x5FED60
#define Window__getProgress_x                                      0x83C520
#define Window__getStatus_x                                        0x83C540
#define Window__getURI_x                                           0x83C550

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x93BDB0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8EB010

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4ACEE0
#define CXStr__CXStr1_x                                            0x82CAE0
#define CXStr__CXStr3_x                                            0x8D7220
#define CXStr__dCXStr_x                                            0x472270
#define CXStr__operator_equal_x                                    0x8D7450
#define CXStr__operator_equal1_x                                   0x8D7490
#define CXStr__operator_plus_equal1_x                              0x8D7F20

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x91F530
#define CXWnd__BringToTop_x                                        0x904830
#define CXWnd__Center_x                                            0x9043B0
#define CXWnd__ClrFocus_x                                          0x9041F0
#define CXWnd__Destroy_x                                           0x9042A0
#define CXWnd__DoAllDrawing_x                                      0x900900
#define CXWnd__DrawChildren_x                                      0x9008D0
#define CXWnd__DrawColoredRect_x                                   0x900D50
#define CXWnd__DrawTooltip_x                                       0x8FF460
#define CXWnd__DrawTooltipAtPoint_x                                0x8FF520
#define CXWnd__GetBorderFrame_x                                    0x900BB0
#define CXWnd__GetChildWndAt_x                                     0x9048D0
#define CXWnd__GetClientClipRect_x                                 0x902B70
#define CXWnd__GetScreenClipRect_x                                 0x902C40
#define CXWnd__GetScreenRect_x                                     0x902E00
#define CXWnd__GetTooltipRect_x                                    0x900DA0
#define CXWnd__GetWindowTextA_x                                    0x496DE0
#define CXWnd__IsActive_x                                          0x907740
#define CXWnd__IsDescendantOf_x                                    0x9037A0
#define CXWnd__IsReallyVisible_x                                   0x9037D0
#define CXWnd__IsType_x                                            0x904F40
#define CXWnd__Move_x                                              0x903840
#define CXWnd__Move1_x                                             0x9038F0
#define CXWnd__ProcessTransition_x                                 0x904360
#define CXWnd__Refade_x                                            0x903B90
#define CXWnd__Resize_x                                            0x903E30
#define CXWnd__Right_x                                             0x9045F0
#define CXWnd__SetFocus_x                                          0x9041B0
#define CXWnd__SetFont_x                                           0x904220
#define CXWnd__SetKeyTooltip_x                                     0x904D50
#define CXWnd__SetMouseOver_x                                      0x901CE0
#define CXWnd__StartFade_x                                         0x903670
#define CXWnd__GetChildItem_x                                      0x904A30
#define CXWnd__SetParent_x                                         0x903550

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x936C80

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x907780
#define CXWndManager__DrawWindows_x                                0x9077A0
#define CXWndManager__GetKeyboardFlags_x                           0x909E50
#define CXWndManager__HandleKeyboardMsg_x                          0x909A60
#define CXWndManager__RemoveWnd_x                                  0x90A0A0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x90A5F0

// CDBStr
#define CDBStr__GetString_x                                        0x522470

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B7C40
#define EQ_Character__Cur_HP_x                                     0x4CDF50
#define EQ_Character__Cur_Mana_x                                   0x4D5410
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BAD60
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AEAE0
#define EQ_Character__GetFocusRangeModifier_x                      0x4AEC30
#define EQ_Character__GetHPRegen_x                                 0x4DAAF0
#define EQ_Character__GetEnduranceRegen_x                          0x4DB100
#define EQ_Character__GetManaRegen_x                               0x4DB540
#define EQ_Character__Max_Endurance_x                              0x624760
#define EQ_Character__Max_HP_x                                     0x4CDD80
#define EQ_Character__Max_Mana_x                                   0x624560
#define EQ_Character__doCombatAbility_x                            0x626910
#define EQ_Character__UseSkill_x                                   0x4DD350
#define EQ_Character__GetConLevel_x                                0x61DD00
#define EQ_Character__IsExpansionFlag_x                            0x5857B0
#define EQ_Character__TotalEffect_x                                0x4C13F0
#define EQ_Character__GetPCSpellAffect_x                           0x4BB950
#define EQ_Character__SpellDuration_x                              0x4BB480
#define EQ_Character__FindItemByRecord_x                           0x4D3560
#define EQ_Character__GetAdjustedSkill_x                           0x4D0C90
#define EQ_Character__GetBaseSkill_x                               0x4D1C30
#define EQ_Character__CanUseItem_x                                 0x4D5720

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8AA1F0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x63A670

//PcClient
#define PcClient__PcClient_x                                       0x61B5C0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B5A20
#define CCharacterListWnd__EnterWorld_x                            0x4B5460
#define CCharacterListWnd__Quit_x                                  0x4B5170
#define CCharacterListWnd__UpdateList_x                            0x4B55F0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x5FFEF0
#define EQ_Item__CreateItemTagString_x                             0x885230
#define EQ_Item__IsStackable_x                                     0x8893D0
#define EQ_Item__GetImageNum_x                                     0x886A10
#define EQ_Item__CreateItemClient_x                                0x5FF0C0
#define EQ_Item__GetItemValue_x                                    0x887AC0
#define EQ_Item__ValueSellMerchant_x                               0x88AAB0
#define EQ_Item__IsKeyRingItem_x                                   0x888D90
#define EQ_Item__CanGoInBag_x                                      0x600010
#define EQ_Item__GetMaxItemCount_x                                 0x887BC0
#define EQ_Item__GetHeldItem_x                                     0x8868E0
#define EQ_Item__GetAugmentFitBySlot_x                             0x884D70

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x540640
#define EQ_LoadingS__Array_x                                       0xBDA2A8

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x6250C0
#define EQ_PC__GetAlternateAbilityId_x                             0x893D80
#define EQ_PC__GetCombatAbility_x                                  0x8943F0
#define EQ_PC__GetCombatAbilityTimer_x                             0x894460
#define EQ_PC__GetItemRecastTimer_x                                0x626E90
#define EQ_PC__HasLoreItem_x                                       0x61E4C0
#define EQ_PC__AlertInventoryChanged_x                             0x61D7D0
#define EQ_PC__GetPcZoneClient_x                                   0x648F00
#define EQ_PC__RemoveMyAffect_x                                    0x629FD0
#define EQ_PC__GetKeyRingItems_x                                   0x894D00
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x894A80
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x894FF0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x58B9F0
#define EQItemList__add_object_x                                   0x5B7340
#define EQItemList__add_item_x                                     0x58C000
#define EQItemList__delete_item_x                                  0x58C050
#define EQItemList__FreeItemList_x                                 0x58BF50

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x51FA90

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x63BEF0
#define EQPlayer__dEQPlayer_x                                      0x62F5F0
#define EQPlayer__DoAttack_x                                       0x643C00
#define EQPlayer__EQPlayer_x                                       0x62FCA0
#define EQPlayer__SetNameSpriteState_x                             0x633F60
#define EQPlayer__SetNameSpriteTint_x                              0x634DF0
#define PlayerBase__HasProperty_j_x                                0x96A120
#define EQPlayer__IsTargetable_x                                   0x96A5C0
#define EQPlayer__CanSee_x                                         0x96A420
#define EQPlayer__CanSee1_x                                        0x96A4F0
#define PlayerBase__GetVisibilityLineSegment_x                     0x96A1E0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x6469D0
#define PlayerZoneClient__GetLevel_x                               0x648F40
#define PlayerZoneClient__IsValidTeleport_x                        0x5B8490
#define PlayerZoneClient__LegalPlayerRace_x                        0x539B50

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x63ED10
#define EQPlayerManager__GetSpawnByName_x                          0x63ED30
#define EQPlayerManager__GetPlayerFromPartialName_x                0x63EDC0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x603780
#define KeypressHandler__AttachKeyToEqCommand_x                    0x6037C0
#define KeypressHandler__ClearCommandStateArray_x                  0x604BB0
#define KeypressHandler__HandleKeyDown_x                           0x604BD0
#define KeypressHandler__HandleKeyUp_x                             0x604C70
#define KeypressHandler__SaveKeymapping_x                          0x605050

// MapViewMap 
#define MapViewMap__Clear_x                                        0x75B0A0
#define MapViewMap__SaveEx_x                                       0x75E440
#define MapViewMap__SetZoom_x                                      0x762B00

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8A80D0

// StringTable 
#define StringTable__getString_x                                   0x8A3050

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x629C40
#define PcZoneClient__RemovePetEffect_x                            0x62A270
#define PcZoneClient__HasAlternateAbility_x                        0x6243A0
#define PcZoneClient__GetCurrentMod_x                              0x4E02B0
#define PcZoneClient__GetModCap_x                                  0x4E01B0
#define PcZoneClient__CanEquipItem_x                               0x624A50
#define PcZoneClient__GetItemByID_x                                0x627310
#define PcZoneClient__GetItemByItemClass_x                         0x6273A0
#define PcZoneClient__RemoveBuffEffect_x                           0x62A290

//Doors
#define EQSwitch__UseSwitch_x                                      0x5BD140

//IconCache
#define IconCache__GetIcon_x                                       0x6FB7D0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6F3240
#define CContainerMgr__CloseContainer_x                            0x6F3510
#define CContainerMgr__OpenExperimentContainer_x                   0x6F3F90

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7B61B0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5F8140

//CLootWnd
#define CLootWnd__LootAll_x                                        0x751550
#define CLootWnd__RequestLootSlot_x                                0x750900

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x558C40
#define EQ_Spell__SpellAffects_x                                   0x5590B0
#define EQ_Spell__SpellAffectBase_x                                0x558E70
#define EQ_Spell__IsStackable_x                                    0x4C5C30
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C5AB0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B2FF0
#define EQ_Spell__IsSPAStacking_x                                  0x559EE0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x559400
#define EQ_Spell__IsNoRemove_x                                     0x4C5C10
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x559EF0
#define __IsResEffectSpell_x                                       0x4C4F30

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4A98E0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8B2450

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7FB680
#define CTargetWnd__WndNotification_x                              0x7FAF10
#define CTargetWnd__RefreshTargetBuffs_x                           0x7FB1E0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x7FA070

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7FFD50

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5541E0
#define EqSoundManager__PlayScriptMp3_x                            0x554340
#define EqSoundManager__SoundAssistPlay_x                          0x661290
#define EqSoundManager__WaveInstancePlay_x                         0x6607E0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x511480

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x922C70

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x548210
#define CAltAbilityData__GetMercMaxRank_x                          0x5481B0
#define CAltAbilityData__GetMaxRank_x                              0x53D890

//CTargetRing
#define CTargetRing__Cast_x                                        0x5F6260

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C5A90
#define CharacterBase__CreateItemGlobalIndex_x                     0x4F7740
#define CharacterBase__CreateItemIndex_x                           0x5FE2F0
#define CharacterBase__GetItemPossession_x                         0x4B2EA0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8BA9C0
#define CharacterBase__GetEffectId_x                               0x4C5A40

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6DB540
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6DBD60

//messages
#define msg_spell_worn_off_x                                       0x57DF80
#define msg_new_text_x                                             0x573150
#define __msgTokenTextParam_x                                      0x5805D0
#define msgTokenText_x                                             0x580820

//SpellManager
#define SpellManager__vftable_x                                    0xAA4838
#define SpellManager__SpellManager_x                               0x6645C0
#define Spellmanager__LoadTextSpells_x                             0x664E90
#define SpellManager__GetSpellByGroupAndRank_x                     0x664790

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x96E0A0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4F7E20
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x583D50
#define ItemGlobalIndex__IsEquippedLocation_x                      0x616E10
#define ItemGlobalIndex__IsValidIndex_x                            0x4F7E80

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8B2D90
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8B3010

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x74A0E0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6F7A20
#define CCursorAttachment__Deactivate_x                            0x6F8A00

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x935130
#define CEQSuiteTextureLoader__GetTexture_x                        0x934DF0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4F4DF0

//IString
#define IString__Append_x                                          0x4E9600

//Camera
#define CDisplay__cameraType_x                                     0xDA9CCC
#define EverQuest__Cameras_x                                       0xE6CFAC

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x4FD4F0
#define LootFiltersManager__GetItemFilterData_x                    0x4FCDE0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x4FCE10
#define LootFiltersManager__SetItemLootFilter_x                    0x4FD030

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7A40D0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x973D70
#define CResolutionHandler__GetWindowedStyle_x                     0x65C1E0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6F0010

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
#ifdef EMU
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\xFD\xFF\xFF\x8B\xCE\x5E\xE9\x00\x00\xFF\xFF\xC7\x01";
static char lpMask[] = "xxxx?xxxxxxx??xxxx";
#else
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
#endif
