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
#define __ExpectedVersionDate                                     "Aug  6 2018"
#define __ExpectedVersionTime                                     "15:03:51"
#define __ActualVersionDate_x                                      0xAC073C
#define __ActualVersionTime_x                                      0xAC0730

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x609FF0
#define __MemChecker1_x                                            0x8DBCF0
#define __MemChecker2_x                                            0x698B50
#define __MemChecker3_x                                            0x698AA0
#define __MemChecker4_x                                            0x8356D0
#define __EncryptPad0_x                                            0xBF24B0
#define __EncryptPad1_x                                            0xC50190
#define __EncryptPad2_x                                            0xC03038
#define __EncryptPad3_x                                            0xC02C38
#define __EncryptPad4_x                                            0xC40F28
#define __EncryptPad5_x                                            0xF0DBC8
#define __AC1_x                                                    0x7F1FB6
#define __AC2_x                                                    0x5C5AEF
#define __AC3_x                                                    0x5CC97F
#define __AC4_x                                                    0x5D07F0
#define __AC5_x                                                    0x5D6A10
#define __AC6_x                                                    0x5DAF52
#define __AC7_x                                                    0x5C5560
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
#define __BindList_x                                               0xBE10A0
#define g_eqCommandStates_x                                        0xBE1E10
#define __Clicks_x                                                 0xE6B9D4
#define __CommandList_x                                            0xBE29C8
#define __CurrentMapLabel_x                                        0x10201D4
#define __CurrentSocial_x                                          0xBCC710
#define __DoAbilityList_x                                          0xEA214C
#define __do_loot_x                                                0x593050
#define __DrawHandler_x                                            0x169B6E8
#define __GroupCount_x                                             0xE5BBE2
#define __Guilds_x                                                 0xE62128
#define __gWorld_x                                                 0xE5C13C
#define __HWnd_x                                                   0xF0DBB4
#define __heqmain_x                                                0x1018E0C
#define __InChatMode_x                                             0xE6B904
#define __LastTell_x                                               0xE6D848
#define __LMouseHeldTime_x                                         0xE6BA40
#define __Mouse_x                                                  0xF0DBD4
#define __MouseLook_x                                              0xE6B99A
#define __MouseEventTime_x                                         0xF0B0E0
#define __gpbCommandEvent_x                                        0xE5BE68
#define __NetStatusToggle_x                                        0xE6B99D
#define __PCNames_x                                                0xE6CE08
#define __RangeAttackReady_x                                       0xE6CB10
#define __RMouseHeldTime_x                                         0xE6BA3C
#define __RunWalkState_x                                           0xE6B908
#define __ScreenMode_x                                             0xDAA48C
#define __ScreenX_x                                                0xE6B8BC
#define __ScreenY_x                                                0xE6B8B8
#define __ScreenXMax_x                                             0xE6B8C0
#define __ScreenYMax_x                                             0xE6B8C4
#define __ServerHost_x                                             0xE5C033
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
#define __gfMaxZoomCameraDistance_x                                0xAB5B40
#define __gfMaxCameraDistance_x                                    0xAE30D0
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
#define pinstActiveBanker_x                                        0xE5E484
#define pinstActiveCorpse_x                                        0xE5E47C
#define pinstActiveGMaster_x                                       0xE5E480
#define pinstActiveMerchant_x                                      0xE5E478
#define pinstAggroInfo_x                                           0xC66858
#define pinstAltAdvManager_x                                       0xDAAE70
#define pinstAuraMgr_x                                             0xC77540
#define pinstBandageTarget_x                                       0xE5E494
#define pinstCamActor_x                                            0xDAA480
#define pinstCDBStr_x                                              0xDA9BAC
#define pinstCDisplay_x                                            0xE5BDD0
#define pinstCEverQuest_x                                          0xF0DD08
#define pinstEverQuestInfo_x                                       0xE6B8B0
#define pinstCharData_x                                            0xE5BDE0
#define pinstCharSpawn_x                                           0xE5BBC0
#define pinstControlledMissile_x                                   0xE5BDE4
#define pinstControlledPlayer_x                                    0xE5BBC0
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
#define pinstLocalPlayer_x                                         0xE5E474
#define pinstMercenaryData_x                                       0xF0B880
#define pinstMercenaryStats_x                                      0x1022CD8
#define pinstMercAltAbilities_x                                    0xDAB440
#define pinstModelPlayer_x                                         0xE5E48C
#define pinstPCData_x                                              0xE5BDE0
#define pinstRealEstateItems_x                                     0xF0CD70
#define pinstSkillMgr_x                                            0xF0CE40
#define pinstSpawnManager_x                                        0xF0C430
#define pinstSpellManager_x                                        0xF0D018
#define pinstSpellSets_x                                           0xF03254
#define pinstStringTable_x                                         0xE5E348
#define pinstSwitchManager_x                                       0xE5BA70
#define pinstTarget_x                                              0xE5E4C8
#define pinstTargetObject_x                                        0xE5BBC8
#define pinstTargetSwitch_x                                        0xE5BDEC
#define pinstTaskMember_x                                          0xDA9978
#define pinstTrackTarget_x                                         0xE5BBC4
#define pinstTradeTarget_x                                         0xE5E488
#define instTributeActive_x                                        0xDA9B0D
#define pinstViewActor_x                                           0xDAA47C
#define pinstWorldData_x                                           0xE5BE48
#define pinstZoneAddr_x                                            0xE6BE30
#define pinstPlayerPath_x                                          0xF0C4C8
#define pinstTargetIndicator_x                                     0xF0D280
#define pinstCTargetManager_x                                      0xF0D318
#define EQObject_Top_x                                             0xE5E470
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDA9EEC
#define pinstCAchievementsWnd_x                                    0xDA9F8C
#define pinstCActionsWnd_x                                         0xDA9F44
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDA9CD0
#define pinstCAdvancedLootWnd_x                                    0xDA9C78
#define pinstCAdventureLeaderboardWnd_x                            0x10199A8
#define pinstCAdventureRequestWnd_x                                0x1019A58
#define pinstCAdventureStatsWnd_x                                  0x1019B08
#define pinstCAggroMeterWnd_x                                      0xDA9FB4
#define pinstCAlarmWnd_x                                           0xDA9F70
#define pinstCAlertHistoryWnd_x                                    0xDA9F4C
#define pinstCAlertStackWnd_x                                      0xDA9EE8
#define pinstCAlertWnd_x                                           0xDA9EF8
#define pinstCAltStorageWnd_x                                      0x1019E68
#define pinstCAudioTriggersWindow_x                                0xC66CE8
#define pinstCAuraWnd_x                                            0xDA9FB0
#define pinstCAvaZoneWnd_x                                         0xDA9F2C
#define pinstCBandolierWnd_x                                       0xDA9FF0
#define pinstCBankWnd_x                                            0xDA9C7C
#define pinstCBarterMerchantWnd_x                                  0x101B0A8
#define pinstCBarterSearchWnd_x                                    0x101B158
#define pinstCBarterWnd_x                                          0x101B208
#define pinstCBazaarConfirmationWnd_x                              0xDA9CE0
#define pinstCBazaarSearchWnd_x                                    0xDA9F5C
#define pinstCBazaarWnd_x                                          0xDA9FE8
#define pinstCBlockedBuffWnd_x                                     0xDA9C64
#define pinstCBlockedPetBuffWnd_x                                  0xDA9C8C
#define pinstCBodyTintWnd_x                                        0xDA9F04
#define pinstCBookWnd_x                                            0xDAA478
#define pinstCBreathWnd_x                                          0xDA9EFC
#define pinstCBuffWindowNORMAL_x                                   0xDAA4D4
#define pinstCBuffWindowSHORT_x                                    0xDA9C48
#define pinstCBugReportWnd_x                                       0xDA9CD8
#define pinstCButtonWnd_x                                          0x169A998
#define pinstCCastingWnd_x                                         0xDA9CD4
#define pinstCCastSpellWnd_x                                       0xDA9F6C
//#define pinstCCharacterCreationWnd_x                               0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDA9F08
#define pinstCChatWindowManager_x                                  0x101BCC8
#define pinstCClaimWnd_x                                           0x101BE20
#define pinstCColorPickerWnd_x                                     0xDA9F1C
#define pinstCCombatAbilityWnd_x                                   0xDA9FC0
#define pinstCCombatSkillsSelectWnd_x                              0xDA9F40
#define pinstCCompassWnd_x                                         0xDA9EF0
#define pinstCConfirmationDialog_x                                 0x1020D20
#define pinstCContainerMgr_x                                       0xDA9FE0
#define pinstCContextMenuManager_x                                 0x169A760
#define pinstCCursorAttachment_x                                   0xDA9CCC
#define pinstCDynamicZoneWnd_x                                     0x101C3E8
#define pinstCEditLabelWnd_x                                       0xDAA4A0
#define pinstCEQMainWnd_x                                          0x101C630
#define pinstCEventCalendarWnd_x                                   0xDA9FAC
#define pinstCExtendedTargetWnd_x                                  0xDA9FA4
#define pinstCFacePick_x                                           0xDA9F24
#define pinstCFellowshipWnd_x                                      0x101C830
#define pinstCFileSelectionWnd_x                                   0xDA9C60
#define pinstCFindItemWnd_x                                        0xDA9FD4
#define pinstCFindLocationWnd_x                                    0x101C988
#define pinstCFriendsWnd_x                                         0xDA9F60
#define pinstCGemsGameWnd_x                                        0xDA9F48
#define pinstCGiveWnd_x                                            0xDAA474
#define pinstCGroupSearchFiltersWnd_x                              0xDA9FCC
#define pinstCGroupSearchWnd_x                                     0x101CD80
#define pinstCGroupWnd_x                                           0x101CE30
#define pinstCGuildBankWnd_x                                       0xE6CC6C
#define pinstCGuildCreationWnd_x                                   0x101CF90
#define pinstCGuildMgmtWnd_x                                       0x101D040
#define pinstCharacterCreation_x                                   0xDA9FB8
#define pinstCHelpWnd_x                                            0xDA9F7C
#define pinstCHeritageSelectionWnd_x                               0xDA9F30
#define pinstCHotButtonWnd_x                                       0x101F198
#define pinstCHotButtonWnd1_x                                      0x101F198
#define pinstCHotButtonWnd2_x                                      0x101F19C
#define pinstCHotButtonWnd3_x                                      0x101F1A0
#define pinstCHotButtonWnd4_x                                      0x101F1A4
#define pinstCIconSelectionWnd_x                                   0xDA9CA4
#define pinstCInspectWnd_x                                         0xDA9C94
#define pinstCInventoryWnd_x                                       0xDAA064
#define pinstCInvSlotMgr_x                                         0xDA9F90
#define pinstCItemDisplayManager_x                                 0x101F728
#define pinstCItemExpTransferWnd_x                                 0x101F858
#define pinstCItemOverflowWnd_x                                    0xDA9F64
#define pinstCJournalCatWnd_x                                      0xDA9C90
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDAA4CC
#define pinstCKeyRingWnd_x                                         0xDA9C50
#define pinstCLargeDialogWnd_x                                     0x10219A0
#define pinstCLayoutCopyWnd_x                                      0x101FBA8
#define pinstCLFGuildWnd_x                                         0x101FC58
#define pinstCLoadskinWnd_x                                        0xDA9F58
#define pinstCLootFiltersCopyWnd_x                                 0xC77D20
#define pinstCLootFiltersWnd_x                                     0xDA9F0C
#define pinstCLootSettingsWnd_x                                    0xDA9F18
#define pinstCLootWnd_x                                            0xDA9F14
#define pinstCMailAddressBookWnd_x                                 0xDA9CAC
#define pinstCMailCompositionWnd_x                                 0xDA9C80
#define pinstCMailIgnoreListWnd_x                                  0xDA9CB0
#define pinstCMailWnd_x                                            0xDA9C54
#define pinstCManageLootWnd_x                                      0xDAB2E8
#define pinstCMapToolbarWnd_x                                      0xDAA068
#define pinstCMapViewWnd_x                                         0xDA9FD8
#define pinstCMarketplaceWnd_x                                     0xDA9FDC
#define pinstCMerchantWnd_x                                        0xDA9F3C
#define pinstCMIZoneSelectWnd_x                                    0x1020490
#define pinstCMusicPlayerWnd_x                                     0xDA9C4C
#define pinstCNameChangeMercWnd_x                                  0xDA9C84
#define pinstCNameChangePetWnd_x                                   0xDA9C5C
#define pinstCNameChangeWnd_x                                      0xDA9FBC
#define pinstCNoteWnd_x                                            0xDA9F78
#define pinstCObjectPreviewWnd_x                                   0xDAA49C
#define pinstCOptionsWnd_x                                         0xDAA06C
#define pinstCPetInfoWnd_x                                         0xDA9C70
#define pinstCPetitionQWnd_x                                       0xDA9CA8
//#define pinstCPlayerCustomizationWnd_x                             0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDA9F00
#define pinstCPlayerWnd_x                                          0xDA9F68
#define pinstCPopupWndManager_x                                    0x1020D20
#define pinstCProgressionSelectionWnd_x                            0x1020DD0
#define pinstCPurchaseGroupWnd_x                                   0xDA9C58
#define pinstCPurchaseWnd_x                                        0xDAA4C4
#define pinstCPvPLeaderboardWnd_x                                  0x1020E80
#define pinstCPvPStatsWnd_x                                        0x1020F30
#define pinstCQuantityWnd_x                                        0xDA9CB8
#define pinstCRaceChangeWnd_x                                      0xDA9FE4
#define pinstCRaidOptionsWnd_x                                     0xDA9FD0
#define pinstCRaidWnd_x                                            0xDA9CBC
#define pinstCRealEstateItemsWnd_x                                 0xDA9F98
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDA9FC4
#define pinstCRealEstateManageWnd_x                                0xDA9F34
#define pinstCRealEstateNeighborhoodWnd_x                          0xDA9F50
#define pinstCRealEstatePlotSearchWnd_x                            0xDA9F74
#define pinstCRealEstatePurchaseWnd_x                              0xDA9F80
#define pinstCRespawnWnd_x                                         0xDA9FC8
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDA9FA0
#define pinstCSendMoneyWnd_x                                       0xDAA4C8
#define pinstCServerListWnd_x                                      0xDA9F94
#define pinstCSkillsSelectWnd_x                                    0xDA9F20
#define pinstCSkillsWnd_x                                          0xDA9F10
#define pinstCSocialEditWnd_x                                      0xDA9CC0
#define pinstCSocialWnd_x                                          0xDA9CC4
#define pinstCSpellBookWnd_x                                       0xDA9F9C
#define pinstCStoryWnd_x                                           0xDA9CE4
#define pinstCTargetOfTargetWnd_x                                  0x1022D60
#define pinstCTargetWnd_x                                          0xDA9C6C
#define pinstCTaskOverlayWnd_x                                     0xDA9F54
#define pinstCTaskSelectWnd_x                                      0x1022EB8
#define pinstCTaskSomething_x                                      0xC78520
#define pinstCTaskTemplateSelectWnd_x                              0x1022F68
#define pinstCTaskWnd_x                                            0x1023018
#define pinstCTextEntryWnd_x                                       0xDA9EF4
#define pinstCTextOverlay_x                                        0xC66FF8
#define pinstCTimeLeftWnd_x                                        0xDA9C74
#define pinstCTipWndCONTEXT_x                                      0x102321C
#define pinstCTipWndOFDAY_x                                        0x1023218
#define pinstCTitleWnd_x                                           0x10232C8
#define pinstCTrackingWnd_x                                        0xDA9C68
#define pinstCTradeskillWnd_x                                      0x1023430
#define pinstCTradeWnd_x                                           0xDA9F84
#define pinstCTrainWnd_x                                           0xDA9CB4
#define pinstCTributeBenefitWnd_x                                  0x1023630
#define pinstCTributeMasterWnd_x                                   0x10236E0
#define pinstCTributeTrophyWnd_x                                   0x1023790
#define pinstCVideoModesWnd_x                                      0xDA9C88
#define pinstCVoiceMacroWnd_x                                      0xF0D848
#define pinstCVoteResultsWnd_x                                     0xDAA4D0
#define pinstCVoteWnd_x                                            0xDAA498
#define pinstCWebManager_x                                         0xF0D9AC
#define pinstCZoneGuideWnd_x                                       0xDA9F28
#define pinstCZonePathWnd_x                                        0xDA9F38

#define pinstEQSuiteTextureLoader_x                                0xC51C48
#define pinstItemIconCache_x                                       0x101C5E8
#define pinstLootFiltersManager_x                                  0xC77DD0
#define pinstRewardSelectionWnd_x                                  0x1021678

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC02C2C
#define __CastRay_x                                                0x58E570
#define __CastRay2_x                                               0x58E5C0
#define __ConvertItemTags_x                                        0x5A92E0
#define __CrashHandler_x                                           0x83F070
#define __EQGetTime_x                                              0x8DB620
#define __ExecuteCmd_x                                             0x586EC0
#define __FixHeading_x                                             0x96C220
#define __get_bearing_x                                            0x58E0B0
#define __get_melee_range_x                                        0x58E7B0
#define __GetAnimationCache_x                                      0x6FC6F0
#define __GetGaugeValueFromEQ_x                                    0x7F07D0
#define __GetLabelFromEQ_x                                         0x7F1F40
#define __GetXTargetType_x                                         0x96DC80
#define __HeadingDiff_x                                            0x96C290
#define __HelpPath_x                                               0xF0ACFC
#define __LoadFrontEnd_x                                           0x6949B0
#define __NewUIINI_x                                               0x7F04A0
#define __pCrashHandler_x                                          0x1040AF8
#define __ProcessGameEvents_x                                      0x5EB990
#define __ProcessMouseEvent_x                                      0x5EB150
#define __SaveColors_x                                             0x537DB0
#define __STMLToText_x                                             0x90F510
#define __ToggleKeyRingItem_x                                      0x4FB340
#define CrashDetected_x                                            0x6964A0
#define DrawNetStatus_x                                            0x617360
#define Expansion_HoT_x                                            0xE6CC74
#define Teleport_Table_Size_x                                      0xE5BEF0
#define Teleport_Table_x                                           0xE5C348
#define Util__FastTime_x                                           0x8DB1E0
#define wwsCrashReportCheckForUploader_x                           0x83FAD0
#define wwsCrashReportPlatformLaunchUploader_x                     0x8421B0
#define __HandleMouseWheel_x                                       0x698C00

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48A820
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4935E0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4933C0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x53F6B0
#define AltAdvManager__IsAbilityReady_x                            0x53E730
#define AltAdvManager__GetAAById_x                                 0x53E930
#define AltAdvManager__CanTrainAbility_x                           0x53E9A0
#define AltAdvManager__CanSeeAbility_x                             0x53EBD0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C62D0
#define CharacterZoneClient__HasSkill_x                            0x4D0E70
#define CharacterZoneClient__MakeMeVisible_x                       0x4D2590
#define CharacterZoneClient__IsStackBlocked_x                      0x4BA650
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B6CC0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D4CF0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D4DD0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D4EB0
#define CharacterZoneClient__FindAffectSlot_x                      0x4BF280
#define CharacterZoneClient__BardCastBard_x                        0x4C1F00
#define CharacterZoneClient__GetMaxEffects_x                       0x4B6D90
#define CharacterZoneClient__GetEffect_x                           0x4B6C00
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C0290
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C0360
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C03B0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C0500
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C06D0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6BECE0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6CC520

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5F9CA0
#define CButtonWnd__CButtonWnd_x                                   0x90B920

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6EB040
#define CChatManager__InitContextMenu_x                            0x6E5150
#define CChatManager__FreeChatWindow_x                             0x6E9F60
#define CChatManager__GetLockedActiveChatWindow_x                  0x6EE8F0
#define CChatManager__SetLockedActiveChatWindow_x                  0x6EADE0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x9200F0
#define CContextMenu__dCContextMenu_x                              0x920320
#define CContextMenu__AddMenuItem_x                                0x920330
#define CContextMenu__RemoveMenuItem_x                             0x920630
#define CContextMenu__RemoveAllMenuItems_x                         0x920650
#define CContextMenu__CheckMenuItem_x                              0x9206D0
#define CContextMenu__SetMenuItem_x                                0x920560

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x920C70
#define CContextMenuManager__RemoveMenu_x                          0x920CE0
#define CContextMenuManager__PopupMenu_x                           0x920DA0
#define CContextMenuManager__Flush_x                               0x920C10
#define CContextMenuManager__GetMenu_x                             0x495760

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8BD430
#define CChatService__GetFriendName_x                              0x8BD440

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6EB5C0
#define CChatWindow__Clear_x                                       0x6EC610
#define CChatWindow__WndNotification_x                             0x6ECB80

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x91D580
#define CComboWnd__Draw_x                                          0x91CA80
#define CComboWnd__GetCurChoice_x                                  0x91D3C0
#define CComboWnd__GetListRect_x                                   0x91CF30
#define CComboWnd__GetTextRect_x                                   0x91D5E0
#define CComboWnd__InsertChoice_x                                  0x91D0C0
#define CComboWnd__SetColors_x                                     0x91D090
#define CComboWnd__SetChoice_x                                     0x91D390
#define CComboWnd__GetItemCount_x                                  0x91D3D0
#define CComboWnd__GetCurChoiceText_x                              0x91D410

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6F47F0
#define CContainerWnd__vftable_x                                   0xAC9B20
#define CContainerWnd__SetContainer_x                              0x6F5D60

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x537B70
#define CDisplay__GetClickedActor_x                                0x52ABD0
#define CDisplay__GetUserDefinedColor_x                            0x5232B0
#define CDisplay__GetWorldFilePath_x                               0x52C620
#define CDisplay__is3dON_x                                         0x5278A0
#define CDisplay__ReloadUI_x                                       0x531D40
#define CDisplay__WriteTextHD2_x                                   0x527680
#define CDisplay__TrueDistance_x                                   0x52E280
#define CDisplay__SetViewActor_x                                   0x52A520

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x93FBA0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x9247E0
#define CEditWnd__GetCharIndexPt_x                                 0x9256D0
#define CEditWnd__GetDisplayString_x                               0x925570
#define CEditWnd__GetHorzOffset_x                                  0x923E10
#define CEditWnd__GetLineForPrintableChar_x                        0x926800
#define CEditWnd__GetSelStartPt_x                                  0x925970
#define CEditWnd__GetSTMLSafeText_x                                0x925390
#define CEditWnd__PointFromPrintableChar_x                         0x926430
#define CEditWnd__SelectableCharFromPoint_x                        0x9265A0
#define CEditWnd__SetEditable_x                                    0x925A40

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5DA480
#define CEverQuest__ClickedPlayer_x                                0x5CC760
#define CEverQuest__CreateTargetIndicator_x                        0x5E8C70
#define CEverQuest__DeleteTargetIndicator_x                        0x5E8D00
#define CEverQuest__DoTellWindow_x                                 0x4E1160
#define CEverQuest__OutputTextToLog_x                              0x4E1390
#define CEverQuest__DropHeldItemOnGround_x                         0x5C2020
#define CEverQuest__dsp_chat_x                                     0x4E1720
#define CEverQuest__trimName_x                                     0x5E5230
#define CEverQuest__Emote_x                                        0x5DAC90
#define CEverQuest__EnterZone_x                                    0x5D4E00
#define CEverQuest__GetBodyTypeDesc_x                              0x5DEAD0
#define CEverQuest__GetClassDesc_x                                 0x5DF110
#define CEverQuest__GetClassThreeLetterCode_x                      0x5DF710
#define CEverQuest__GetDeityDesc_x                                 0x5E75C0
#define CEverQuest__GetLangDesc_x                                  0x5DF8D0
#define CEverQuest__GetRaceDesc_x                                  0x5DF0F0
#define CEverQuest__InterpretCmd_x                                 0x5E7B90
#define CEverQuest__LeftClickedOnPlayer_x                          0x5C6210
#define CEverQuest__LMouseUp_x                                     0x5C4590
#define CEverQuest__RightClickedOnPlayer_x                         0x5C6AF0
#define CEverQuest__RMouseUp_x                                     0x5C5520
#define CEverQuest__SetGameState_x                                 0x5C1DB0
#define CEverQuest__UPCNotificationFlush_x                         0x5E5130
#define CEverQuest__IssuePetCommand_x                              0x5E0CD0
#define CEverQuest__ReportSuccessfulHit_x                          0x5DB930

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x706820
#define CGaugeWnd__CalcLinesFillRect_x                             0x706880
#define CGaugeWnd__Draw_x                                          0x705F10

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ABBD0
#define CGuild__GetGuildName_x                                     0x4AAC10
#define CGuild__GetGuildIndex_x                                    0x4AAFA0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x721B40

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x72EA30
#define CInvSlotMgr__MoveItem_x                                    0x72D740
#define CInvSlotMgr__SelectSlot_x                                  0x72EB00

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x72BFF0
#define CInvSlot__SliderComplete_x                                 0x729E10
#define CInvSlot__GetItemBase_x                                    0x729780
#define CInvSlot__UpdateItem_x                                     0x7298F0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x730430
#define CInvSlotWnd__CInvSlotWnd_x                                 0x72F700
#define CInvSlotWnd__HandleLButtonUp_x                             0x72FFB0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7EC9B0
#define CItemDisplayWnd__UpdateStrings_x                           0x73EFF0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x739080
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x739550
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x73F580
#define CItemDisplayWnd__AboutToShow_x                             0x73EC60
#define CItemDisplayWnd__WndNotification_x                         0x7408A0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8242A0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x7448F0

// CLabel 
#define CLabel__Draw_x                                             0x74A3C0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8F5CF0
#define CListWnd__dCListWnd_x                                      0x8F6010
#define CListWnd__AddColumn_x                                      0x8FA300
#define CListWnd__AddColumn1_x                                     0x8FA350
#define CListWnd__AddLine_x                                        0x8FA6E0
#define CListWnd__AddString_x                                      0x8FA4E0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8FA0D0
#define CListWnd__CalculateVSBRange_x                              0x8F9EB0
#define CListWnd__ClearSel_x                                       0x8FAEC0
#define CListWnd__ClearAllSel_x                                    0x8FAF20
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8FB8F0
#define CListWnd__Compare_x                                        0x8F97F0
#define CListWnd__Draw_x                                           0x8F6110
#define CListWnd__DrawColumnSeparators_x                           0x8F88D0
#define CListWnd__DrawHeader_x                                     0x8F8D40
#define CListWnd__DrawItem_x                                       0x8F9130
#define CListWnd__DrawLine_x                                       0x8F8A40
#define CListWnd__DrawSeparator_x                                  0x8F8970
#define CListWnd__EnableLine_x                                     0x8F81B0
#define CListWnd__EnsureVisible_x                                  0x8FB830
#define CListWnd__ExtendSel_x                                      0x8FADF0
#define CListWnd__GetColumnMinWidth_x                              0x8F7CF0
#define CListWnd__GetColumnWidth_x                                 0x8F7C60
#define CListWnd__GetCurSel_x                                      0x8F75F0
#define CListWnd__GetItemAtPoint_x                                 0x8F8420
#define CListWnd__GetItemAtPoint1_x                                0x8F8490
#define CListWnd__GetItemData_x                                    0x8F7670
#define CListWnd__GetItemHeight_x                                  0x8F7A30
#define CListWnd__GetItemIcon_x                                    0x8F7800
#define CListWnd__GetItemRect_x                                    0x8F82A0
#define CListWnd__GetItemText_x                                    0x8F76B0
#define CListWnd__GetSelList_x                                     0x8FAF70
#define CListWnd__GetSeparatorRect_x                               0x8F86D0
#define CListWnd__InsertLine_x                                     0x8FAAD0
#define CListWnd__RemoveLine_x                                     0x8FAC20
#define CListWnd__SetColors_x                                      0x8F9E80
#define CListWnd__SetColumnJustification_x                         0x8F9BB0
#define CListWnd__SetColumnWidth_x                                 0x8F9AD0
#define CListWnd__SetCurSel_x                                      0x8FAD30
#define CListWnd__SetItemColor_x                                   0x8FB4F0
#define CListWnd__SetItemData_x                                    0x8FB4B0
#define CListWnd__SetItemText_x                                    0x8FB0F0
#define CListWnd__ShiftColumnSeparator_x                           0x8F9C70
#define CListWnd__Sort_x                                           0x8F9970
#define CListWnd__ToggleSel_x                                      0x8FAD60

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x75F9B0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x782A40
#define CMerchantWnd__RequestBuyItem_x                             0x783320
#define CMerchantWnd__RequestSellItem_x                            0x783850
#define CMerchantWnd__SelectRecoverySlot_x                         0x786680
//did this get another arg?
#define CMerchantWnd__SelectBuySellSlot_x                          0x7830A0
#define CMerchantWnd__ActualSelect_x                               0x78C1E0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x88B630
#define CPacketScrambler__hton_x                                   0x88B620

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x914AF0
#define CSidlManager__FindScreenPieceTemplate_x                    0x914F00
#define CSidlManager__FindScreenPieceTemplate1_x                   0x914CF0
#define CSidlManager__CreateLabel_x                                0x7E3E70
#define CSidlManager__CreateXWndFromTemplate_x                     0x917FD0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x9181B0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x911660
#define CSidlScreenWnd__CalculateVSBRange_x                        0x911560
#define CSidlScreenWnd__ConvertToRes_x                             0x936390
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x910FF0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x910CE0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x910DB0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x910E80
#define CSidlScreenWnd__DrawSidlPiece_x                            0x911AF0
#define CSidlScreenWnd__EnableIniStorage_x                         0x911FC0
#define CSidlScreenWnd__GetSidlPiece_x                             0x911CE0
#define CSidlScreenWnd__Init1_x                                    0x9108F0
#define CSidlScreenWnd__LoadIniInfo_x                              0x912010
#define CSidlScreenWnd__LoadIniListWnd_x                           0x912B60
#define CSidlScreenWnd__LoadSidlScreen_x                           0x90FCF0
#define CSidlScreenWnd__StoreIniInfo_x                             0x9126D0
#define CSidlScreenWnd__StoreIniVis_x                              0x912A40
#define CSidlScreenWnd__WndNotification_x                          0x911A00
#define CSidlScreenWnd__GetChildItem_x                             0x911F40
#define CSidlScreenWnd__HandleLButtonUp_x                          0x901700
#define CSidlScreenWnd__m_layoutCopy_x                             0x169A630

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x65DB80
#define CSkillMgr__GetSkillCap_x                                   0x65DD60
#define CSkillMgr__GetNameToken_x                                  0x65D310

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x921A70
#define CSliderWnd__SetValue_x                                     0x9218E0
#define CSliderWnd__SetNumTicks_x                                  0x921940

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7E9C20

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x928690
#define CStmlWnd__CalculateHSBRange_x                              0x929700
#define CStmlWnd__CalculateVSBRange_x                              0x929670
#define CStmlWnd__CanBreakAtCharacter_x                            0x92DA40
#define CStmlWnd__FastForwardToEndOfTag_x                          0x92E630
#define CStmlWnd__ForceParseNow_x                                  0x928C30
#define CStmlWnd__GetNextTagPiece_x                                0x92D9A0
#define CStmlWnd__GetSTMLText_x                                    0x4EF550
#define CStmlWnd__GetVisibleText_x                                 0x928C50
#define CStmlWnd__InitializeWindowVariables_x                      0x92E480
#define CStmlWnd__MakeStmlColorTag_x                               0x927E20
#define CStmlWnd__MakeWndNotificationTag_x                         0x927E90
#define CStmlWnd__SetSTMLText_x                                    0x926EF0
#define CStmlWnd__StripFirstSTMLLines_x                            0x92F780
#define CStmlWnd__UpdateHistoryString_x                            0x92E840

// CTabWnd 
#define CTabWnd__Draw_x                                            0x932E00
#define CTabWnd__DrawCurrentPage_x                                 0x933420
#define CTabWnd__DrawTab_x                                         0x9331F0
#define CTabWnd__GetCurrentPage_x                                  0x932660
#define CTabWnd__GetPageInnerRect_x                                0x9328A0
#define CTabWnd__GetTabInnerRect_x                                 0x9327E0
#define CTabWnd__GetTabRect_x                                      0x932690
#define CTabWnd__InsertPage_x                                      0x932A90
#define CTabWnd__SetPage_x                                         0x932920
#define CTabWnd__SetPageRect_x                                     0x932D40
#define CTabWnd__UpdatePage_x                                      0x9330B0
#define CTabWnd__GetPageFromTabIndex_x                             0x933130
#define CTabWnd__GetCurrentTabIndex_x                              0x932650

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x744DC0
#define CPageWnd__SetTabText_x                                     0x93FFB0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A5700

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8FE580
#define CTextureFont__GetTextExtent_x                              0x8FE740

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x691720
#define CHtmlComponentWnd__ValidateUri_x                           0x723530
#define CHtmlWnd__SetClientCallbacks_x                             0x5FF010
#define CHtmlWnd__AddObserver_x                                    0x5FF030
#define CHtmlWnd__RemoveObserver_x                                 0x5FF090
#define Window__getProgress_x                                      0x83CCE0
#define Window__getStatus_x                                        0x83CD00
#define Window__getURI_x                                           0x83CD10

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x93C530

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8EB5D0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4ACEF0
#define CXStr__CXStr1_x                                            0x4EA4F0
#define CXStr__CXStr3_x                                            0x8D7710
#define CXStr__dCXStr_x                                            0x472180
#define CXStr__operator_equal_x                                    0x8D7940
#define CXStr__operator_equal1_x                                   0x8D7980
#define CXStr__operator_plus_equal1_x                              0x8D8410

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x91FD00
#define CXWnd__BringToTop_x                                        0x904E50
#define CXWnd__Center_x                                            0x9049D0
#define CXWnd__ClrFocus_x                                          0x904820
#define CXWnd__Destroy_x                                           0x9048C0
#define CXWnd__DoAllDrawing_x                                      0x900E90
#define CXWnd__DrawChildren_x                                      0x900E60
#define CXWnd__DrawColoredRect_x                                   0x9012F0
#define CXWnd__DrawTooltip_x                                       0x8FF9D0
#define CXWnd__DrawTooltipAtPoint_x                                0x8FFA90
#define CXWnd__GetBorderFrame_x                                    0x901150
#define CXWnd__GetChildWndAt_x                                     0x904EF0
#define CXWnd__GetClientClipRect_x                                 0x903150
#define CXWnd__GetScreenClipRect_x                                 0x903200
#define CXWnd__GetScreenRect_x                                     0x903390
#define CXWnd__GetTooltipRect_x                                    0x901340
#define CXWnd__GetWindowTextA_x                                    0x496E00
#define CXWnd__IsActive_x                                          0x907DC0
#define CXWnd__IsDescendantOf_x                                    0x903D90
#define CXWnd__IsReallyVisible_x                                   0x903DC0
#define CXWnd__IsType_x                                            0x905550
#define CXWnd__Move_x                                              0x903E30
#define CXWnd__Move1_x                                             0x903EE0
#define CXWnd__ProcessTransition_x                                 0x904980
#define CXWnd__Refade_x                                            0x9041B0
#define CXWnd__Resize_x                                            0x904440
#define CXWnd__Right_x                                             0x904C10
#define CXWnd__SetFocus_x                                          0x9047E0
#define CXWnd__SetFont_x                                           0x904850
#define CXWnd__SetKeyTooltip_x                                     0x905370
#define CXWnd__SetMouseOver_x                                      0x9022A0
#define CXWnd__StartFade_x                                         0x903C60
#define CXWnd__GetChildItem_x                                      0x905060
#define CXWnd__SetParent_x                                         0x903B30

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x937460

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x907E00
#define CXWndManager__DrawWindows_x                                0x907E20
#define CXWndManager__GetKeyboardFlags_x                           0x90A5A0
#define CXWndManager__HandleKeyboardMsg_x                          0x90A1A0
#define CXWndManager__RemoveWnd_x                                  0x90A7F0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x90AD40

// CDBStr
#define CDBStr__GetString_x                                        0x522260

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B7C70
#define EQ_Character__Cur_HP_x                                     0x4CDEF0
#define EQ_Character__Cur_Mana_x                                   0x4D53B0
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BADE0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AEAC0
#define EQ_Character__GetFocusRangeModifier_x                      0x4AEC10
#define EQ_Character__GetHPRegen_x                                 0x4DAA90
#define EQ_Character__GetEnduranceRegen_x                          0x4DB0A0
#define EQ_Character__GetManaRegen_x                               0x4DB4E0
#define EQ_Character__Max_Endurance_x                              0x624E10
#define EQ_Character__Max_HP_x                                     0x4CDD20
#define EQ_Character__Max_Mana_x                                   0x624C10
#define EQ_Character__doCombatAbility_x                            0x626FC0
#define EQ_Character__UseSkill_x                                   0x4DD2F0
#define EQ_Character__GetConLevel_x                                0x61E0C0
#define EQ_Character__IsExpansionFlag_x                            0x585880
#define EQ_Character__TotalEffect_x                                0x4C1480
#define EQ_Character__GetPCSpellAffect_x                           0x4BB9D0
#define EQ_Character__SpellDuration_x                              0x4BB500
#define EQ_Character__FindItemByRecord_x                           0x4D3500
#define EQ_Character__GetAdjustedSkill_x                           0x4D0C30
#define EQ_Character__GetBaseSkill_x                               0x4D1BD0
#define EQ_Character__CanUseItem_x                                 0x4D56C0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8AA7B0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x63AD50

//PcClient
#define PcClient__PcClient_x                                       0x61B980

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B5A50
#define CCharacterListWnd__EnterWorld_x                            0x4B5490
#define CCharacterListWnd__Quit_x                                  0x4B51A0
#define CCharacterListWnd__UpdateList_x                            0x4B5620

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x600240
#define EQ_Item__CreateItemTagString_x                             0x885970
#define EQ_Item__IsStackable_x                                     0x889B10
#define EQ_Item__GetImageNum_x                                     0x887140
#define EQ_Item__CreateItemClient_x                                0x5FF410
#define EQ_Item__GetItemValue_x                                    0x888200
#define EQ_Item__ValueSellMerchant_x                               0x88B1D0
#define EQ_Item__IsKeyRingItem_x                                   0x8894E0
#define EQ_Item__CanGoInBag_x                                      0x600360
#define EQ_Item__GetMaxItemCount_x                                 0x888300
#define EQ_Item__GetHeldItem_x                                     0x887010
#define EQ_Item__GetAugmentFitBySlot_x                             0x8854C0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x5403D0
#define EQ_LoadingS__Array_x                                       0xBDA2B0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x625770
#define EQ_PC__GetAlternateAbilityId_x                             0x8943E0
#define EQ_PC__GetCombatAbility_x                                  0x894A50
#define EQ_PC__GetCombatAbilityTimer_x                             0x894AC0
#define EQ_PC__GetItemRecastTimer_x                                0x627540
#define EQ_PC__HasLoreItem_x                                       0x61E830
#define EQ_PC__AlertInventoryChanged_x                             0x61DB90
#define EQ_PC__GetPcZoneClient_x                                   0x649580
#define EQ_PC__RemoveMyAffect_x                                    0x62A670
#define EQ_PC__GetKeyRingItems_x                                   0x895360
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8950E0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x895650

// EQItemList 
#define EQItemList__EQItemList_x                                   0x58BAA0
#define EQItemList__add_object_x                                   0x5B7680
#define EQItemList__add_item_x                                     0x58C0B0
#define EQItemList__delete_item_x                                  0x58C100
#define EQItemList__FreeItemList_x                                 0x58C000

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x51F880

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x63C5D0
#define EQPlayer__dEQPlayer_x                                      0x62FCD0
#define EQPlayer__DoAttack_x                                       0x644290
#define EQPlayer__EQPlayer_x                                       0x630380
#define EQPlayer__SetNameSpriteState_x                             0x634640
#define EQPlayer__SetNameSpriteTint_x                              0x6354D0
#define PlayerBase__HasProperty_j_x                                0x96A600
#define EQPlayer__IsTargetable_x                                   0x96AAA0
#define EQPlayer__CanSee_x                                         0x96A900
#define EQPlayer__CanSee1_x                                        0x96A9D0
#define PlayerBase__GetVisibilityLineSegment_x                     0x96A6C0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x647050
#define PlayerZoneClient__GetLevel_x                               0x6495C0
#define PlayerZoneClient__IsValidTeleport_x                        0x5B87D0
#define PlayerZoneClient__LegalPlayerRace_x                        0x539960

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x63F3D0
#define EQPlayerManager__GetSpawnByName_x                          0x63F3F0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x63F480

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x603BE0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x603C20
#define KeypressHandler__ClearCommandStateArray_x                  0x605010
#define KeypressHandler__HandleKeyDown_x                           0x605030
#define KeypressHandler__HandleKeyUp_x                             0x6050D0
#define KeypressHandler__SaveKeymapping_x                          0x6054B0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x75B840
#define MapViewMap__SaveEx_x                                       0x75EBE0
#define MapViewMap__SetZoom_x                                      0x7632B0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8A86A0

// StringTable 
#define StringTable__getString_x                                   0x8A3590

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x62A2E0
#define PcZoneClient__RemovePetEffect_x                            0x62A910
#define PcZoneClient__HasAlternateAbility_x                        0x624A50
#define PcZoneClient__GetCurrentMod_x                              0x4E0250
#define PcZoneClient__GetModCap_x                                  0x4E0150
#define PcZoneClient__CanEquipItem_x                               0x625100
#define PcZoneClient__GetItemByID_x                                0x6279B0
#define PcZoneClient__GetItemByItemClass_x                         0x627A40
#define PcZoneClient__RemoveBuffEffect_x                           0x62A930

//Doors
#define EQSwitch__UseSwitch_x                                      0x5BD480

//IconCache
#define IconCache__GetIcon_x                                       0x6FBF80

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6F3990
#define CContainerMgr__CloseContainer_x                            0x6F3C60
#define CContainerMgr__OpenExperimentContainer_x                   0x6F46E0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7B6680

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5F8480

//CLootWnd
#define CLootWnd__LootAll_x                                        0x751D10
#define CLootWnd__RequestLootSlot_x                                0x7510C0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x558B10
#define EQ_Spell__SpellAffects_x                                   0x558F80
#define EQ_Spell__SpellAffectBase_x                                0x558D40
#define EQ_Spell__IsStackable_x                                    0x4C5BF0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C5AA0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B3000
#define EQ_Spell__IsSPAStacking_x                                  0x559D20
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x5592D0
#define EQ_Spell__IsNoRemove_x                                     0x4C5BD0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x559D30
#define __IsResEffectSpell_x                                       0x4C4FE0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4A9860

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8B29F0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7FBCF0
#define CTargetWnd__WndNotification_x                              0x7FB580
#define CTargetWnd__RefreshTargetBuffs_x                           0x7FB850
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x7FA6D0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x8003B0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5540A0
#define EqSoundManager__PlayScriptMp3_x                            0x554200
#define EqSoundManager__SoundAssistPlay_x                          0x661690
#define EqSoundManager__WaveInstancePlay_x                         0x660BE0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x511250

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x923450

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x5480A0
#define CAltAbilityData__GetMercMaxRank_x                          0x548040
#define CAltAbilityData__GetMaxRank_x                              0x53D5E0

//CTargetRing
#define CTargetRing__Cast_x                                        0x5F6590

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C5A80
#define CharacterBase__CreateItemGlobalIndex_x                     0x4F7770
#define CharacterBase__CreateItemIndex_x                           0x5FE620
#define CharacterBase__GetItemPossession_x                         0x4B2EB0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8BAF60
#define CharacterBase__GetEffectId_x                               0x4C5A30

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6DBC20
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6DC440

//messages
#define msg_spell_worn_off_x                                       0x57E1D0
#define msg_new_text_x                                             0x5733A0
#define __msgTokenTextParam_x                                      0x580820
#define msgTokenText_x                                             0x580A70

//SpellManager
#define SpellManager__vftable_x                                    0xAA4818
#define SpellManager__SpellManager_x                               0x6649C0
#define Spellmanager__LoadTextSpells_x                             0x665220
#define SpellManager__GetSpellByGroupAndRank_x                     0x664B90

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x96E570

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4F7E20
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x583FB0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x6171C0
#define ItemGlobalIndex__IsValidIndex_x                            0x4F7E80

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8B3330
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8B35B0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x74A710

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6F8100
#define CCursorAttachment__Deactivate_x                            0x6F90E0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x935320
#define CEQSuiteTextureLoader__GetTexture_x                        0x934FE0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4F4DF0

//IString
#define IString__Append_x                                          0x4E9630

//Camera
#define CDisplay__cameraType_x                                     0xDA9CDC
#define EverQuest__Cameras_x                                       0xE6CFAC

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x4FD5C0
#define LootFiltersManager__GetItemFilterData_x                    0x4FCEB0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x4FCEE0
#define LootFiltersManager__SetItemLootFilter_x                    0x4FD100

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7A46B0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9742B0
#define CResolutionHandler__GetWindowedStyle_x                     0x65C680

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6F0760

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
