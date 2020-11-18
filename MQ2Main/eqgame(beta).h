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
#if defined(EQBETA)
#include "eqgame-private(beta).h"
#endif
#endif

#define __ClientName                                              "eqgame"
#define __ExpectedVersionDate                                     "Nov 18 2020"
#define __ExpectedVersionTime                                     "04:19:17"
#define __ActualVersionDate_x                                      0xAF4550
#define __ActualVersionTime_x                                      0xAF4544
#define __ActualVersionBuild_x                                     0xAE2544

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x642930
#define __MemChecker1_x                                            0x8F59F0
#define __MemChecker2_x                                            0x6B2D90
#define __MemChecker3_x                                            0x6B2CE0
#define __MemChecker4_x                                            0x84BBC0
#define __EncryptPad0_x                                            0xC2A9D0
#define __EncryptPad1_x                                            0xC88218
#define __EncryptPad2_x                                            0xC3AD98
#define __EncryptPad3_x                                            0xC3A998
#define __EncryptPad4_x                                            0xC787A8
#define __EncryptPad5_x                                            0xF4B0E8
#define __AC1_x                                                    0x80A6B6
#define __AC2_x                                                    0x5FC21F
#define __AC3_x                                                    0x603870
#define __AC4_x                                                    0x607820
#define __AC5_x                                                    0x60DB1F
#define __AC6_x                                                    0x611FD6
#define __AC7_x                                                    0x5FBC90
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1912FC

// Direct Input
#define DI8__Main_x                                                0xF4B110
#define DI8__Keyboard_x                                            0xF4B114
#define DI8__Mouse_x                                               0xF4B0F4
#define DI8__Mouse_Copy_x                                          0xEA39E4
#define DI8__Mouse_Check_x                                         0xF48C3C
#define __AutoSkillArray_x                                         0xEA4900
#define __Attack_x                                                 0xF42733
#define __Autofire_x                                               0xF42734
#define __BindList_x                                               0xC19400
#define g_eqCommandStates_x                                        0xC1A180
#define __Clicks_x                                                 0xEA3A9C
#define __CommandList_x                                            0xC1AD40
#define __CurrentMapLabel_x                                        0xF5B154
#define __CurrentSocial_x                                          0xC027D4
#define __DoAbilityList_x                                          0xEDA254
#define __do_loot_x                                                0x5C7D90
#define __DrawHandler_x                                            0x15DA148
#define __GroupCount_x                                             0xE9C502
#define __Guilds_x                                                 0xEA2920
#define __gWorld_x                                                 0xE9CC9C
#define __HWnd_x                                                   0xF4B0F8
#define __heqmain_x                                                0xF4B0D0
#define __InChatMode_x                                             0xEA39CC
#define __LastTell_x                                               0xEA5950
#define __LMouseHeldTime_x                                         0xEA3B08
#define __Mouse_x                                                  0xF4B0FC
#define __MouseLook_x                                              0xEA3A62
#define __MouseEventTime_x                                         0xF43214
#define __gpbCommandEvent_x                                        0xE9C758
#define __NetStatusToggle_x                                        0xEA3A65
#define __PCNames_x                                                0xEA4EFC
#define __RangeAttackReady_x                                       0xEA4BE4
#define __RMouseHeldTime_x                                         0xEA3B04
#define __RunWalkState_x                                           0xEA39D0
#define __ScreenMode_x                                             0xDEA4A4
#define __ScreenX_x                                                0xEA3984
#define __ScreenY_x                                                0xEA3980
#define __ScreenXMax_x                                             0xEA3988
#define __ScreenYMax_x                                             0xEA398C
#define __ServerHost_x                                             0xE9C92B
#define __ServerName_x                                             0xEDA214
#define __ShiftKeyDown_x                                           0xEA4060
#define __ShowNames_x                                              0xEA4DA0
#define EverQuestInfo__bSocialChanged_x                            0xEDA29C
#define __Socials_x                                                0xEDA314
#define __SubscriptionType_x                                       0xF9F418
#define __TargetAggroHolder_x                                      0xF5DB08
#define __ZoneType_x                                               0xEA3E60
#define __GroupAggro_x                                             0xF5DB48
#define __LoginName_x                                              0xF488CC
#define __Inviter_x                                                0xF426B0
#define __AttackOnAssist_x                                         0xEA4D5C
#define __UseTellWindows_x                                         0xEA5094
#define __gfMaxZoomCameraDistance_x                                0xAEC160
#define __gfMaxCameraDistance_x                                    0xB14DE0
#define __pulAutoRun_x                                             0xEA3A80
#define __pulForward_x                                             0xEA50CC
#define __pulBackward_x                                            0xEA50D0
#define __pulTurnRight_x                                           0xEA50D4
#define __pulTurnLeft_x                                            0xEA50D8
#define __pulStrafeLeft_x                                          0xEA50DC
#define __pulStrafeRight_x                                         0xEA50E0

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE9ECB8
#define instEQZoneInfo_x                                           0xEA3C58
#define pinstActiveBanker_x                                        0xE9CC44
#define pinstActiveCorpse_x                                        0xE9CC3C
#define pinstActiveGMaster_x                                       0xE9CC40
#define pinstActiveMerchant_x                                      0xE9CA34
#define pinstAltAdvManager_x                                       0xDEAEF0
#define pinstBandageTarget_x                                       0xE9CC54
#define pinstCamActor_x                                            0xDEA494
#define pinstCDBStr_x                                              0xDE9C0C
#define pinstCDisplay_x                                            0xE9CCA4
#define pinstCEverQuest_x                                          0xF48190
#define pinstEverQuestInfo_x                                       0xEA3978
#define pinstCharData_x                                            0xE9C744
#define pinstCharSpawn_x                                           0xE9CC8C
#define pinstControlledMissile_x                                   0xE9CCA0
#define pinstControlledPlayer_x                                    0xE9CC8C
#define pinstCResolutionHandler_x                                  0x15DA378
#define pinstCSidlManager_x                                        0x15D9310
#define pinstCXWndManager_x                                        0x15D930C
#define instDynamicZone_x                                          0xEA27F8
#define pinstDZMember_x                                            0xEA2908
#define pinstDZTimerInfo_x                                         0xEA290C
#define pinstEqLogin_x                                             0xF48218
#define instEQMisc_x                                               0xDE9B50
#define pinstEQSoundManager_x                                      0xDEBEC0
#define pinstEQSpellStrings_x                                      0xCAC458
#define instExpeditionLeader_x                                     0xEA2842
#define instExpeditionName_x                                       0xEA2882
#define pinstGroup_x                                               0xE9C4FE
#define pinstImeManager_x                                          0x15D9308
#define pinstLocalPlayer_x                                         0xE9C824
#define pinstMercenaryData_x                                       0xF44D10
#define pinstMercenaryStats_x                                      0xF5DBD4
#define pinstModelPlayer_x                                         0xE9CC4C
#define pinstPCData_x                                              0xE9C744
#define pinstSkillMgr_x                                            0xF46E70
#define pinstSpawnManager_x                                        0xF45918
#define pinstSpellManager_x                                        0xF470B0
#define pinstSpellSets_x                                           0xF3B35C
#define pinstStringTable_x                                         0xE9C74C
#define pinstSwitchManager_x                                       0xE9C258
#define pinstTarget_x                                              0xE9CC88
#define pinstTargetObject_x                                        0xE9CC94
#define pinstTargetSwitch_x                                        0xE9CCAC
#define pinstTaskMember_x                                          0xDE99E0
#define pinstTrackTarget_x                                         0xE9CC90
#define pinstTradeTarget_x                                         0xE9CC48
#define instTributeActive_x                                        0xDE9B71
#define pinstViewActor_x                                           0xDEA490
#define pinstWorldData_x                                           0xE9C3A8
#define pinstZoneAddr_x                                            0xEA3EF8
#define pinstPlayerPath_x                                          0xF459B0
#define pinstTargetIndicator_x                                     0xF47318
#define EQObject_Top_x                                             0xE9C820
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDE9F30
#define pinstCAchievementsWnd_x                                    0xDEA444
#define pinstCActionsWnd_x                                         0xDE9F6C
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDEA504
#define pinstCAdvancedLootWnd_x                                    0xDEA4B8
#define pinstCAdventureLeaderboardWnd_x                            0xF54928
#define pinstCAdventureRequestWnd_x                                0xF549D8
#define pinstCAdventureStatsWnd_x                                  0xF54A88
#define pinstCAggroMeterWnd_x                                      0xDEA4EC
#define pinstCAlarmWnd_x                                           0xDEA470
#define pinstCAlertHistoryWnd_x                                    0xDE9EE4
#define pinstCAlertStackWnd_x                                      0xDEA4D4
#define pinstCAlertWnd_x                                           0xDEA4E8
#define pinstCAltStorageWnd_x                                      0xF54DE8
#define pinstCAudioTriggersWindow_x                                0xC9E788
#define pinstCAuraWnd_x                                            0xDEA4BC
#define pinstCAvaZoneWnd_x                                         0xDE9EDC
#define pinstCBandolierWnd_x                                       0xDEA500
#define pinstCBankWnd_x                                            0xDEA544
#define pinstCBarterMerchantWnd_x                                  0xF56028
#define pinstCBarterSearchWnd_x                                    0xF560D8
#define pinstCBarterWnd_x                                          0xF56188
#define pinstCBazaarConfirmationWnd_x                              0xDEA484
#define pinstCBazaarSearchWnd_x                                    0xDE9F34
#define pinstCBazaarWnd_x                                          0xDEA450
#define pinstCBlockedBuffWnd_x                                     0xDEA4C8
#define pinstCBlockedPetBuffWnd_x                                  0xDEA4F0
#define pinstCBodyTintWnd_x                                        0xDEA3F8
#define pinstCBookWnd_x                                            0xDEA538
#define pinstCBreathWnd_x                                          0xDE9F48
#define pinstCBuffWindowNORMAL_x                                   0xDEA4B0
#define pinstCBuffWindowSHORT_x                                    0xDEA4B4
#define pinstCBugReportWnd_x                                       0xDEA53C
#define pinstCButtonWnd_x                                          0x15D9578
#define pinstCCastingWnd_x                                         0xDEA52C
#define pinstCCastSpellWnd_x                                       0xDE9F40
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDEA404
#define pinstCChatWindowManager_x                                  0xF56C48
#define pinstCClaimWnd_x                                           0xF56DA0
#define pinstCColorPickerWnd_x                                     0xDE9EFC
#define pinstCCombatAbilityWnd_x                                   0xDEA460
#define pinstCCombatSkillsSelectWnd_x                              0xDEA418
#define pinstCCompassWnd_x                                         0xDE9FE4
#define pinstCConfirmationDialog_x                                 0xF5BCA0
#define pinstCContainerMgr_x                                       0xDEA3F4
#define pinstCContextMenuManager_x                                 0x15D92C8
#define pinstCCursorAttachment_x                                   0xDEA514
#define pinstCDynamicZoneWnd_x                                     0xF57368
#define pinstCEditLabelWnd_x                                       0xDEA498
#define pinstCEQMainWnd_x                                          0xF575B0
#define pinstCEventCalendarWnd_x                                   0xDE9F38
#define pinstCExtendedTargetWnd_x                                  0xDEA4D0
#define pinstCFacePick_x                                           0xDEA41C
#define pinstCFactionWnd_x                                         0xDEA43C
#define pinstCFellowshipWnd_x                                      0xF577B0
#define pinstCFileSelectionWnd_x                                   0xDE9EF4
#define pinstCFindItemWnd_x                                        0xDEA42C
#define pinstCFindLocationWnd_x                                    0xF57908
#define pinstCFriendsWnd_x                                         0xDEA430
#define pinstCGemsGameWnd_x                                        0xDEA438
#define pinstCGiveWnd_x                                            0xDEA474
#define pinstCGroupSearchFiltersWnd_x                              0xDEA508
#define pinstCGroupSearchWnd_x                                     0xF57D00
#define pinstCGroupWnd_x                                           0xF57DB0
#define pinstCGuildBankWnd_x                                       0xEA4D40
#define pinstCGuildCreationWnd_x                                   0xF57F10
#define pinstCGuildMgmtWnd_x                                       0xF57FC0
#define pinstCharacterCreation_x                                   0xDEA424
#define pinstCHelpWnd_x                                            0xDEA478
#define pinstCHeritageSelectionWnd_x                               0xDEA428
#define pinstCHotButtonWnd_x                                       0xF5A118
#define pinstCHotButtonWnd1_x                                      0xF5A118
#define pinstCHotButtonWnd2_x                                      0xF5A11C
#define pinstCHotButtonWnd3_x                                      0xF5A120
#define pinstCHotButtonWnd4_x                                      0xF5A124
#define pinstCIconSelectionWnd_x                                   0xDEA510
#define pinstCInspectWnd_x                                         0xDEA4F4
#define pinstCInventoryWnd_x                                       0xDEA4C0
#define pinstCInvSlotMgr_x                                         0xDE9F24
#define pinstCItemDisplayManager_x                                 0xF5A6A8
#define pinstCItemExpTransferWnd_x                                 0xF5A7D8
#define pinstCItemOverflowWnd_x                                    0xDE9F3C
#define pinstCJournalCatWnd_x                                      0xDE9F10
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDE9ED0
#define pinstCKeyRingWnd_x                                         0xDEA524
#define pinstCLargeDialogWnd_x                                     0xF5C920
#define pinstCLayoutCopyWnd_x                                      0xF5AB28
#define pinstCLFGuildWnd_x                                         0xF5ABD8
#define pinstCLoadskinWnd_x                                        0xDEA454
#define pinstCLootFiltersCopyWnd_x                                 0xCBAEE8
#define pinstCLootFiltersWnd_x                                     0xDEA4D8
#define pinstCLootSettingsWnd_x                                    0xDEA4FC
#define pinstCLootWnd_x                                            0xDE9F14
#define pinstCMailAddressBookWnd_x                                 0xDE9F28
#define pinstCMailCompositionWnd_x                                 0xDE9F04
#define pinstCMailIgnoreListWnd_x                                  0xDE9F2C
#define pinstCMailWnd_x                                            0xDE9F00
#define pinstCManageLootWnd_x                                      0xDEB3A0
#define pinstCMapToolbarWnd_x                                      0xDEA480
#define pinstCMapViewWnd_x                                         0xDEA448
#define pinstCMarketplaceWnd_x                                     0xDEA4DC
#define pinstCMerchantWnd_x                                        0xDE9F20
#define pinstCMIZoneSelectWnd_x                                    0xF5B410
#define pinstCMusicPlayerWnd_x                                     0xDE9EEC
#define pinstCNameChangeMercWnd_x                                  0xDEA47C
#define pinstCNameChangePetWnd_x                                   0xDEA44C
#define pinstCNameChangeWnd_x                                      0xDEA48C
#define pinstCNoteWnd_x                                            0xDEA458
#define pinstCObjectPreviewWnd_x                                   0xDEA4F8
#define pinstCOptionsWnd_x                                         0xDEA468
#define pinstCPetInfoWnd_x                                         0xDE9EE8
#define pinstCPetitionQWnd_x                                       0xDEA414
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDEA3FC
#define pinstCPlayerWnd_x                                          0xDE9EE0
#define pinstCPopupWndManager_x                                    0xF5BCA0
#define pinstCProgressionSelectionWnd_x                            0xF5BD50
#define pinstCPurchaseGroupWnd_x                                   0xDE9CB0
#define pinstCPurchaseWnd_x                                        0xDEA530
#define pinstCPvPLeaderboardWnd_x                                  0xF5BE00
#define pinstCPvPStatsWnd_x                                        0xF5BEB0
#define pinstCQuantityWnd_x                                        0xDE9ECC
#define pinstCRaceChangeWnd_x                                      0xDEA4C4
#define pinstCRaidOptionsWnd_x                                     0xDEA50C
#define pinstCRaidWnd_x                                            0xDE9F1C
#define pinstCRealEstateItemsWnd_x                                 0xDEA440
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDEA3E8
#define pinstCRealEstateManageWnd_x                                0xDE9CB8
#define pinstCRealEstateNeighborhoodWnd_x                          0xDE9ED8
#define pinstCRealEstatePlotSearchWnd_x                            0xDE9EF0
#define pinstCRealEstatePurchaseWnd_x                              0xDE9F0C
#define pinstCRespawnWnd_x                                         0xDEA4E4
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDEA410
#define pinstCSendMoneyWnd_x                                       0xDEA488
#define pinstCServerListWnd_x                                      0xDE9F18
#define pinstCSkillsSelectWnd_x                                    0xDEA40C
#define pinstCSkillsWnd_x                                          0xDEA3F0
#define pinstCSocialEditWnd_x                                      0xDEA518
#define pinstCSocialWnd_x                                          0xDEA46C
#define pinstCSpellBookWnd_x                                       0xDEA45C
#define pinstCStoryWnd_x                                           0xDE9F68
#define pinstCTargetOfTargetWnd_x                                  0xF5DC58
#define pinstCTargetWnd_x                                          0xDEA4E0
#define pinstCTaskOverlayWnd_x                                     0xDE9CA8
#define pinstCTaskSelectWnd_x                                      0xF5DDB0
#define pinstCTaskManager_x                                        0xCBB828
#define pinstCTaskTemplateSelectWnd_x                              0xF5DE60
#define pinstCTaskWnd_x                                            0xF5DF10
#define pinstCTextEntryWnd_x                                       0xDEA534
#define pinstCTimeLeftWnd_x                                        0xDEA408
#define pinstCTipWndCONTEXT_x                                      0xF5E114
#define pinstCTipWndOFDAY_x                                        0xF5E110
#define pinstCTitleWnd_x                                           0xF5E1C0
#define pinstCTrackingWnd_x                                        0xDEA4CC
#define pinstCTradeskillWnd_x                                      0xF5E328
#define pinstCTradeWnd_x                                           0xDEA400
#define pinstCTrainWnd_x                                           0xDE9F08
#define pinstCTributeBenefitWnd_x                                  0xF5E528
#define pinstCTributeMasterWnd_x                                   0xF5E5D8
#define pinstCTributeTrophyWnd_x                                   0xF5E688
#define pinstCVideoModesWnd_x                                      0xDE9CB4
#define pinstCVoiceMacroWnd_x                                      0xF478D0
#define pinstCVoteResultsWnd_x                                     0xDEA434
#define pinstCVoteWnd_x                                            0xDEA420
#define pinstCWebManager_x                                         0xF47F4C
#define pinstCZoneGuideWnd_x                                       0xDE9CAC
#define pinstCZonePathWnd_x                                        0xDE9EC8

#define pinstEQSuiteTextureLoader_x                                0xC88B38
#define pinstItemIconCache_x                                       0xF57568
#define pinstLootFiltersManager_x                                  0xCBAF98
#define pinstRewardSelectionWnd_x                                  0xF5C5F8

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5C3480
#define __CastRay2_x                                               0x5C34D0
#define __ConvertItemTags_x                                        0x5DF190
#define __CleanItemTags_x                                          0x47D3C0
#define __DoesFileExist_x                                          0x8F8A70
#define __EQGetTime_x                                              0x8F5620
#define __ExecuteCmd_x                                             0x5BBDD0
#define __FixHeading_x                                             0x98ABD0
#define __FlushDxKeyboard_x                                        0x6AEC30
#define __GameLoop_x                                               0x6B1F60
#define __get_bearing_x                                            0x5C2FE0
#define __get_melee_range_x                                        0x5C36C0
#define __GetAnimationCache_x                                      0x717330
#define __GetGaugeValueFromEQ_x                                    0x808B60
#define __GetLabelFromEQ_x                                         0x80A640
#define __GetXTargetType_x                                         0x98C5B0
#define __HandleMouseWheel_x                                       0x6B2E40
#define __HeadingDiff_x                                            0x98AC40
#define __HelpPath_x                                               0xF42E04
#define __LoadFrontEnd_x                                           0x6AF270
#define __NewUIINI_x                                               0x808830
#define __ProcessGameEvents_x                                      0x623EB0
#define __ProcessMouseEvent_x                                      0x623640
#define __SaveColors_x                                             0x55CD50
#define __STMLToText_x                                             0x92DFD0
#define __ToggleKeyRingItem_x                                      0x51B390
#define CMemoryMappedFile__SetFile_x                               0xA7A0A0
#define CrashDetected_x                                            0x6B0D20
#define DrawNetStatus_x                                            0x64FC80
#define Expansion_HoT_x                                            0xEA4D48
#define Teleport_Table_Size_x                                      0xE9C7E0
#define Teleport_Table_x                                           0xE9CCB0
#define Util__FastTime_x                                           0x8F51F0
#define __CopyLayout_x                                             0x63E020
#define __WndProc_x                                                0x6B1220
#define __ProcessKeyboardEvent_x                                   0x6B07C0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4906D0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4996C0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499490
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493C60
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x4930B0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x564FC0
#define AltAdvManager__IsAbilityReady_x                            0x563D60
#define AltAdvManager__GetAAById_x                                 0x5640F0
#define AltAdvManager__CanTrainAbility_x                           0x564160
#define AltAdvManager__CanSeeAbility_x                             0x5644C0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CB1E0
#define CharacterZoneClient__HasSkill_x                            0x4D6060
#define CharacterZoneClient__MakeMeVisible_x                       0x4D7780
#define CharacterZoneClient__IsStackBlocked_x                      0x4C2860
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBD00
#define CharacterZoneClient__GetItemCountWorn_x                    0x4DA110
#define CharacterZoneClient__GetItemCountInInventory_x             0x4DA1F0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4DA2D0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C4950
#define CharacterZoneClient__BardCastBard_x                        0x4C7380
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF710
#define CharacterZoneClient__GetEffect_x                           0x4BBC40
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C59C0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C5A90
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C5AE0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5C30
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5E10
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3C50
#define CharacterZoneClient__FindItemByGuid_x                      0x4D86E0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D8160

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D8B20
#define CBankWnd__WndNotification_x                                0x6D8900

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E6620

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x92B7B0
#define CButtonWnd__CButtonWnd_x                                   0x92A3C0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x706540
#define CChatManager__InitContextMenu_x                            0x6FF670
#define CChatManager__FreeChatWindow_x                             0x705080
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9A30
#define CChatManager__SetLockedActiveChatWindow_x                  0x7061C0
#define CChatManager__CreateChatWindow_x                           0x7056C0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9B40

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x93E8F0
#define CContextMenu__dCContextMenu_x                              0x93EB30
#define CContextMenu__AddMenuItem_x                                0x93EB40
#define CContextMenu__RemoveMenuItem_x                             0x93EE50
#define CContextMenu__RemoveAllMenuItems_x                         0x93EE70
#define CContextMenu__CheckMenuItem_x                              0x93EEF0
#define CContextMenu__SetMenuItem_x                                0x93ED70
#define CContextMenu__AddSeparator_x                               0x93ECD0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x93F490
#define CContextMenuManager__RemoveMenu_x                          0x93F500
#define CContextMenuManager__PopupMenu_x                           0x93F5C0
#define CContextMenuManager__Flush_x                               0x93F430
#define CContextMenuManager__GetMenu_x                             0x49B860
#define CContextMenuManager__CreateDefaultMenu_x                   0x711CB0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D05E0
#define CChatService__GetFriendName_x                              0x8D05F0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x706DB0
#define CChatWindow__Clear_x                                       0x708070
#define CChatWindow__WndNotification_x                             0x708800
#define CChatWindow__AddHistory_x                                  0x707930

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93BD50
#define CComboWnd__Draw_x                                          0x93B250
#define CComboWnd__GetCurChoice_x                                  0x93BB90
#define CComboWnd__GetListRect_x                                   0x93B700
#define CComboWnd__GetTextRect_x                                   0x93BDC0
#define CComboWnd__InsertChoice_x                                  0x93B890
#define CComboWnd__SetColors_x                                     0x93B860
#define CComboWnd__SetChoice_x                                     0x93BB60
#define CComboWnd__GetItemCount_x                                  0x93BBA0
#define CComboWnd__GetCurChoiceText_x                              0x93BBE0
#define CComboWnd__GetChoiceText_x                                 0x93BBB0
#define CComboWnd__InsertChoiceAtIndex_x                           0x93B920

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x70F6C0
#define CContainerWnd__vftable_x                                   0xAFD74C
#define CContainerWnd__SetContainer_x                              0x710C20

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x5576B0
#define CDisplay__PreZoneMainUI_x                                  0x5576C0
#define CDisplay__CleanGameUI_x                                    0x55CB10
#define CDisplay__GetClickedActor_x                                0x54FB10
#define CDisplay__GetUserDefinedColor_x                            0x548190
#define CDisplay__GetWorldFilePath_x                               0x551580
#define CDisplay__is3dON_x                                         0x54C770
#define CDisplay__ReloadUI_x                                       0x556BC0
#define CDisplay__WriteTextHD2_x                                   0x54C560
#define CDisplay__TrueDistance_x                                   0x553240
#define CDisplay__SetViewActor_x                                   0x54F430
#define CDisplay__GetFloorHeight_x                                 0x54C830
#define CDisplay__SetRenderWindow_x                                0x54B1B0
#define CDisplay__ToggleScreenshotMode_x                           0x54EF00

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x95E800

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x941DF0
#define CEditWnd__EnsureCaretVisible_x                             0x943FC0
#define CEditWnd__GetCaretPt_x                                     0x942F70
#define CEditWnd__GetCharIndexPt_x                                 0x942D20
#define CEditWnd__GetDisplayString_x                               0x942BC0
#define CEditWnd__GetHorzOffset_x                                  0x9414A0
#define CEditWnd__GetLineForPrintableChar_x                        0x943EC0
#define CEditWnd__GetSelStartPt_x                                  0x942FD0
#define CEditWnd__GetSTMLSafeText_x                                0x9429E0
#define CEditWnd__PointFromPrintableChar_x                         0x943AF0
#define CEditWnd__SelectableCharFromPoint_x                        0x943C60
#define CEditWnd__SetEditable_x                                    0x9430A0
#define CEditWnd__SetWindowTextA_x                                 0x942760
#define CEditWnd__ReplaceSelection_x                               0x943760
#define CEditWnd__ReplaceSelection1_x                              0x9436E0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x6114B0
#define CEverQuest__ClickedPlayer_x                                0x603650
#define CEverQuest__CreateTargetIndicator_x                        0x621020
#define CEverQuest__DeleteTargetIndicator_x                        0x6210B0
#define CEverQuest__DoTellWindow_x                                 0x4E9C20
#define CEverQuest__OutputTextToLog_x                              0x4E9EF0
#define CEverQuest__DropHeldItemOnGround_x                         0x5F87A0
#define CEverQuest__dsp_chat_x                                     0x4EA280
#define CEverQuest__trimName_x                                     0x61D1D0
#define CEverQuest__Emote_x                                        0x611D10
#define CEverQuest__EnterZone_x                                    0x60BE10
#define CEverQuest__GetBodyTypeDesc_x                              0x616760
#define CEverQuest__GetClassDesc_x                                 0x616DA0
#define CEverQuest__GetClassThreeLetterCode_x                      0x6173A0
#define CEverQuest__GetDeityDesc_x                                 0x61F870
#define CEverQuest__GetLangDesc_x                                  0x617560
#define CEverQuest__GetRaceDesc_x                                  0x616D80
#define CEverQuest__InterpretCmd_x                                 0x61FE40
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FC940
#define CEverQuest__LMouseUp_x                                     0x5FACC0
#define CEverQuest__RightClickedOnPlayer_x                         0x5FD220
#define CEverQuest__RMouseUp_x                                     0x5FBC50
#define CEverQuest__SetGameState_x                                 0x5F8530
#define CEverQuest__UPCNotificationFlush_x                         0x61D0D0
#define CEverQuest__IssuePetCommand_x                              0x618970
#define CEverQuest__ReportSuccessfulHit_x                          0x613060

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x721310
#define CGaugeWnd__CalcLinesFillRect_x                             0x721370
#define CGaugeWnd__Draw_x                                          0x720990

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AFFE0
#define CGuild__GetGuildName_x                                     0x4AEA90
#define CGuild__GetGuildIndex_x                                    0x4AF090

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73AFA0

//CHotButton
#define CHotButton__SetCheck_x                                     0x6325B0
#define CHotButton__SetButtonSize_x                                0x632970

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x748040
#define CInvSlotMgr__MoveItem_x                                    0x746D10
#define CInvSlotMgr__SelectSlot_x                                  0x748110

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x745540
#define CInvSlot__SliderComplete_x                                 0x743280
#define CInvSlot__GetItemBase_x                                    0x742C00
#define CInvSlot__UpdateItem_x                                     0x742D70

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x749B70
#define CInvSlotWnd__CInvSlotWnd_x                                 0x748D10
#define CInvSlotWnd__HandleLButtonUp_x                             0x7496F0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x803EF0
#define CItemDisplayWnd__UpdateStrings_x                           0x758260
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x751EE0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x752410
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x758860
#define CItemDisplayWnd__AboutToShow_x                             0x757EB0
#define CItemDisplayWnd__WndNotification_x                         0x759AD0
#define CItemDisplayWnd__RequestConvertItem_x                      0x759410
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x756F10
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x757CD0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x834AC0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75E020

// CLabel 
#define CLabel__Draw_x                                             0x763A50

// CListWnd
#define CListWnd__CListWnd_x                                       0x9145F0
#define CListWnd__dCListWnd_x                                      0x914910
#define CListWnd__AddColumn_x                                      0x918D80
#define CListWnd__AddColumn1_x                                     0x918DD0
#define CListWnd__AddLine_x                                        0x919160
#define CListWnd__AddString_x                                      0x918F60
#define CListWnd__CalculateFirstVisibleLine_x                      0x918B40
#define CListWnd__CalculateVSBRange_x                              0x918920
#define CListWnd__ClearSel_x                                       0x919940
#define CListWnd__ClearAllSel_x                                    0x9199A0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x91A3C0
#define CListWnd__Compare_x                                        0x918260
#define CListWnd__Draw_x                                           0x914A40
#define CListWnd__DrawColumnSeparators_x                           0x917230
#define CListWnd__DrawHeader_x                                     0x9176A0
#define CListWnd__DrawItem_x                                       0x917BA0
#define CListWnd__DrawLine_x                                       0x9173A0
#define CListWnd__DrawSeparator_x                                  0x9172D0
#define CListWnd__EnableLine_x                                     0x916B00
#define CListWnd__EnsureVisible_x                                  0x91A2E0
#define CListWnd__ExtendSel_x                                      0x919870
#define CListWnd__GetColumnTooltip_x                               0x916640
#define CListWnd__GetColumnMinWidth_x                              0x9166B0
#define CListWnd__GetColumnWidth_x                                 0x9165B0
#define CListWnd__GetCurSel_x                                      0x915F40
#define CListWnd__GetItemAtPoint_x                                 0x916D80
#define CListWnd__GetItemAtPoint1_x                                0x916DF0
#define CListWnd__GetItemData_x                                    0x915FC0
#define CListWnd__GetItemHeight_x                                  0x916380
#define CListWnd__GetItemIcon_x                                    0x916150
#define CListWnd__GetItemRect_x                                    0x916BF0
#define CListWnd__GetItemText_x                                    0x916000
#define CListWnd__GetSelList_x                                     0x9199F0
#define CListWnd__GetSeparatorRect_x                               0x917030
#define CListWnd__InsertLine_x                                     0x919550
#define CListWnd__RemoveLine_x                                     0x9196A0
#define CListWnd__SetColors_x                                      0x918900
#define CListWnd__SetColumnJustification_x                         0x918630
#define CListWnd__SetColumnLabel_x                                 0x918F00
#define CListWnd__SetColumnWidth_x                                 0x918550
#define CListWnd__SetCurSel_x                                      0x9197B0
#define CListWnd__SetItemColor_x                                   0x919F90
#define CListWnd__SetItemData_x                                    0x919F50
#define CListWnd__SetItemText_x                                    0x919B60
#define CListWnd__ShiftColumnSeparator_x                           0x9186F0
#define CListWnd__Sort_x                                           0x9183E0
#define CListWnd__ToggleSel_x                                      0x9197E0
#define CListWnd__SetColumnsSizable_x                              0x9187A0
#define CListWnd__SetItemWnd_x                                     0x919E10
#define CListWnd__GetItemWnd_x                                     0x9161A0
#define CListWnd__SetItemIcon_x                                    0x919BE0
#define CListWnd__CalculateCustomWindowPositions_x                 0x918C40
#define CListWnd__SetVScrollPos_x                                  0x918530

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x779250
#define CMapViewWnd__GetWorldCoordinates_x                         0x777960
#define CMapViewWnd__HandleLButtonDown_x                           0x7749A0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x799520
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x799E00
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79A330
#define CMerchantWnd__SelectRecoverySlot_x                         0x79D2E0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7980A0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A2E90
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x799140

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89DDC0
#define CPacketScrambler__hton_x                                   0x89DDB0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x9335C0
#define CSidlManager__FindScreenPieceTemplate_x                    0x9339D0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9337C0
#define CSidlManager__CreateLabel_x                                0x7FB170
#define CSidlManager__CreateXWndFromTemplate_x                     0x936930
#define CSidlManager__CreateXWndFromTemplate1_x                    0x936B10
#define CSidlManager__CreateXWnd_x                                 0x7FB0A0
#define CSidlManager__CreateHotButtonWnd_x                         0x7FB670

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9300A0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x92FFA0
#define CSidlScreenWnd__ConvertToRes_x                             0x9592A0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x92FA90
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x92F780
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x92F850
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x92F920
#define CSidlScreenWnd__DrawSidlPiece_x                            0x930540
#define CSidlScreenWnd__EnableIniStorage_x                         0x930A10
#define CSidlScreenWnd__GetSidlPiece_x                             0x930730
#define CSidlScreenWnd__Init1_x                                    0x92F380
#define CSidlScreenWnd__LoadIniInfo_x                              0x930A60
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9315A0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92E780
#define CSidlScreenWnd__StoreIniInfo_x                             0x931120
#define CSidlScreenWnd__StoreIniVis_x                              0x931480
#define CSidlScreenWnd__WndNotification_x                          0x930450
#define CSidlScreenWnd__GetChildItem_x                             0x930990
#define CSidlScreenWnd__HandleLButtonUp_x                          0x920250
#define CSidlScreenWnd__m_layoutCopy_x                             0x15D9198

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x697F90
#define CSkillMgr__GetSkillCap_x                                   0x698170
#define CSkillMgr__GetNameToken_x                                  0x697710
#define CSkillMgr__IsActivatedSkill_x                              0x697850
#define CSkillMgr__IsCombatSkill_x                                 0x697790

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x940270
#define CSliderWnd__SetValue_x                                     0x9400E0
#define CSliderWnd__SetNumTicks_x                                  0x940140

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x8012C0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x948BD0
#define CStmlWnd__ParseSTML_x                                      0x949EE0
#define CStmlWnd__CalculateHSBRange_x                              0x949CB0
#define CStmlWnd__CalculateVSBRange_x                              0x949C20
#define CStmlWnd__CanBreakAtCharacter_x                            0x94DFF0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x94EC80
#define CStmlWnd__ForceParseNow_x                                  0x949170
#define CStmlWnd__GetNextTagPiece_x                                0x94DF50
#define CStmlWnd__GetSTMLText_x                                    0x50CAE0
#define CStmlWnd__GetVisibleText_x                                 0x949190
#define CStmlWnd__InitializeWindowVariables_x                      0x94EAD0
#define CStmlWnd__MakeStmlColorTag_x                               0x948240
#define CStmlWnd__MakeWndNotificationTag_x                         0x9482B0
#define CStmlWnd__SetSTMLText_x                                    0x9472F0
#define CStmlWnd__StripFirstSTMLLines_x                            0x94FD80
#define CStmlWnd__UpdateHistoryString_x                            0x94EE90

// CTabWnd 
#define CTabWnd__Draw_x                                            0x946430
#define CTabWnd__DrawCurrentPage_x                                 0x946B60
#define CTabWnd__DrawTab_x                                         0x946880
#define CTabWnd__GetCurrentPage_x                                  0x945C30
#define CTabWnd__GetPageInnerRect_x                                0x945E70
#define CTabWnd__GetTabInnerRect_x                                 0x945DB0
#define CTabWnd__GetTabRect_x                                      0x945C60
#define CTabWnd__InsertPage_x                                      0x946080
#define CTabWnd__RemovePage_x                                      0x9461F0
#define CTabWnd__SetPage_x                                         0x945EF0
#define CTabWnd__SetPageRect_x                                     0x946370
#define CTabWnd__UpdatePage_x                                      0x946740
#define CTabWnd__GetPageFromTabIndex_x                             0x9467C0
#define CTabWnd__GetCurrentTabIndex_x                              0x945C20

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x75E440
#define CPageWnd__SetTabText_x                                     0x945770
#define CPageWnd__FlashTab_x                                       0x9457D0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9320

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91D0B0
#define CTextureFont__GetTextExtent_x                              0x91D270

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AC0F0
#define CHtmlComponentWnd__ValidateUri_x                           0x73C990
#define CHtmlWnd__SetClientCallbacks_x                             0x6379F0
#define CHtmlWnd__AddObserver_x                                    0x637A10
#define CHtmlWnd__RemoveObserver_x                                 0x637A70
#define Window__getProgress_x                                      0x8531C0
#define Window__getStatus_x                                        0x8531E0
#define Window__getURI_x                                           0x8531F0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9560B0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x90A0B0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9920
#define CXStr__CXStr1_x                                            0x4818B0
#define CXStr__CXStr3_x                                            0x8F15E0
#define CXStr__dCXStr_x                                            0x478410
#define CXStr__operator_equal_x                                    0x8F1810
#define CXStr__operator_equal1_x                                   0x8F1850
#define CXStr__operator_plus_equal1_x                              0x8F22E0
#define CXStr__SetString_x                                         0x8F41D0
#define CXStr__operator_char_p_x                                   0x8F1D20
#define CXStr__GetChar_x                                           0x8F3B20
#define CXStr__Delete_x                                            0x8F33D0
#define CXStr__GetUnicode_x                                        0x8F3B90
#define CXStr__GetLength_x                                         0x47D770
#define CXStr__Mid_x                                               0x47D780
#define CXStr__Insert_x                                            0x8F3BF0
#define CXStr__FindNext_x                                          0x8F3840

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93E510
#define CXWnd__BringToTop_x                                        0x9239F0
#define CXWnd__Center_x                                            0x923570
#define CXWnd__ClrFocus_x                                          0x923390
#define CXWnd__Destroy_x                                           0x923430
#define CXWnd__DoAllDrawing_x                                      0x91F9E0
#define CXWnd__DrawChildren_x                                      0x91F9B0
#define CXWnd__DrawColoredRect_x                                   0x91FE40
#define CXWnd__DrawTooltip_x                                       0x91E4E0
#define CXWnd__DrawTooltipAtPoint_x                                0x91E5A0
#define CXWnd__GetBorderFrame_x                                    0x91FCA0
#define CXWnd__GetChildWndAt_x                                     0x923A90
#define CXWnd__GetClientClipRect_x                                 0x921C90
#define CXWnd__GetScreenClipRect_x                                 0x921D40
#define CXWnd__GetScreenRect_x                                     0x921EC0
#define CXWnd__GetRelativeRect_x                                   0x921F90
#define CXWnd__GetTooltipRect_x                                    0x91FE90
#define CXWnd__GetWindowTextA_x                                    0x49CFE0
#define CXWnd__IsActive_x                                          0x9205D0
#define CXWnd__IsDescendantOf_x                                    0x9228D0
#define CXWnd__IsReallyVisible_x                                   0x922900
#define CXWnd__IsType_x                                            0x924110
#define CXWnd__Move_x                                              0x922980
#define CXWnd__Move1_x                                             0x922A40
#define CXWnd__ProcessTransition_x                                 0x923520
#define CXWnd__Refade_x                                            0x922D20
#define CXWnd__Resize_x                                            0x922FB0
#define CXWnd__Right_x                                             0x9237B0
#define CXWnd__SetFocus_x                                          0x923350
#define CXWnd__SetFont_x                                           0x9233C0
#define CXWnd__SetKeyTooltip_x                                     0x923F20
#define CXWnd__SetMouseOver_x                                      0x920E00
#define CXWnd__StartFade_x                                         0x9227B0
#define CXWnd__GetChildItem_x                                      0x923C00
#define CXWnd__SetParent_x                                         0x922670
#define CXWnd__Minimize_x                                          0x923020

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x95A320

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x926910
#define CXWndManager__DrawWindows_x                                0x926930
#define CXWndManager__GetKeyboardFlags_x                           0x929050
#define CXWndManager__HandleKeyboardMsg_x                          0x928C00
#define CXWndManager__RemoveWnd_x                                  0x929270
#define CXWndManager__RemovePendingDeletionWnd_x                   0x9297E0

// CDBStr
#define CDBStr__GetString_x                                        0x547150

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BFE70
#define EQ_Character__Cur_HP_x                                     0x4D30A0
#define EQ_Character__Cur_Mana_x                                   0x4DA7D0
#define EQ_Character__GetCastingTimeModifier_x                     0x4C2ED0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B3890
#define EQ_Character__GetFocusRangeModifier_x                      0x4B39E0
#define EQ_Character__GetHPRegen_x                                 0x4E06D0
#define EQ_Character__GetEnduranceRegen_x                          0x4E0CD0
#define EQ_Character__GetManaRegen_x                               0x4E1110
#define EQ_Character__Max_Endurance_x                              0x65E2B0
#define EQ_Character__Max_HP_x                                     0x4D2ED0
#define EQ_Character__Max_Mana_x                                   0x65E0B0
#define EQ_Character__doCombatAbility_x                            0x6606A0
#define EQ_Character__UseSkill_x                                   0x4E2F10
#define EQ_Character__GetConLevel_x                                0x656C30
#define EQ_Character__IsExpansionFlag_x                            0x5BA570
#define EQ_Character__TotalEffect_x                                0x4C6C70
#define EQ_Character__GetPCSpellAffect_x                           0x4C3C20
#define EQ_Character__SpellDuration_x                              0x4C3750
#define EQ_Character__MySpellDuration_x                            0x4B21C0
#define EQ_Character__GetAdjustedSkill_x                           0x4D5E20
#define EQ_Character__GetBaseSkill_x                               0x4D6DC0
#define EQ_Character__CanUseItem_x                                 0x4DAAE0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BD4E0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x6745E0

//PcClient
#define PcClient__vftable_x                                        0xAF11C0
#define PcClient__PcClient_x                                       0x654390

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA890
#define CCharacterListWnd__EnterWorld_x                            0x4BA260
#define CCharacterListWnd__Quit_x                                  0x4B9FB0
#define CCharacterListWnd__UpdateList_x                            0x4BA450

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x638BD0
#define EQ_Item__CreateItemTagString_x                             0x8973A0
#define EQ_Item__IsStackable_x                                     0x89C070
#define EQ_Item__GetImageNum_x                                     0x898F40
#define EQ_Item__CreateItemClient_x                                0x637E10
#define EQ_Item__GetItemValue_x                                    0x89A220
#define EQ_Item__ValueSellMerchant_x                               0x89D9A0
#define EQ_Item__IsKeyRingItem_x                                   0x89B970
#define EQ_Item__CanGoInBag_x                                      0x638CF0
#define EQ_Item__IsEmpty_x                                         0x89B4D0
#define EQ_Item__GetMaxItemCount_x                                 0x89A640
#define EQ_Item__GetHeldItem_x                                     0x898E10
#define EQ_Item__GetAugmentFitBySlot_x                             0x896BF0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x565CD0
#define EQ_LoadingS__Array_x                                       0xC12130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65EBB0
#define EQ_PC__GetAlternateAbilityId_x                             0x8A6E30
#define EQ_PC__GetCombatAbility_x                                  0x8A74A0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A7510
#define EQ_PC__GetItemRecastTimer_x                                0x660C20
#define EQ_PC__HasLoreItem_x                                       0x6574A0
#define EQ_PC__AlertInventoryChanged_x                             0x656560
#define EQ_PC__GetPcZoneClient_x                                   0x683640
#define EQ_PC__RemoveMyAffect_x                                    0x663E60
#define EQ_PC__GetKeyRingItems_x                                   0x8A7DE0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A7B60
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A80E0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5C0A10
#define EQItemList__add_object_x                                   0x5EDFC0
#define EQItemList__add_item_x                                     0x5C0F70
#define EQItemList__delete_item_x                                  0x5C0FC0
#define EQItemList__FreeItemList_x                                 0x5C0EC0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x543CB0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x675EE0
#define EQPlayer__dEQPlayer_x                                      0x669260
#define EQPlayer__DoAttack_x                                       0x67DDE0
#define EQPlayer__EQPlayer_x                                       0x669920
#define EQPlayer__SetNameSpriteState_x                             0x66DBF0
#define EQPlayer__SetNameSpriteTint_x                              0x66EAD0
#define PlayerBase__HasProperty_j_x                                0x988FE0
#define EQPlayer__IsTargetable_x                                   0x989480
#define EQPlayer__CanSee_x                                         0x9892E0
#define EQPlayer__CanSee1_x                                        0x9893B0
#define PlayerBase__GetVisibilityLineSegment_x                     0x9890A0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x6810E0
#define PlayerZoneClient__GetLevel_x                               0x683680
#define PlayerZoneClient__IsValidTeleport_x                        0x5EF130
#define PlayerZoneClient__LegalPlayerRace_x                        0x55E9D0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x678CD0
#define EQPlayerManager__GetSpawnByName_x                          0x678D80
#define EQPlayerManager__GetPlayerFromPartialName_x                0x678E10

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63C280
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63C300
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63C340
#define KeypressHandler__ClearCommandStateArray_x                  0x63D730
#define KeypressHandler__HandleKeyDown_x                           0x63D750
#define KeypressHandler__HandleKeyUp_x                             0x63D7F0
#define KeypressHandler__SaveKeymapping_x                          0x63DC40

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7750C0
#define MapViewMap__SaveEx_x                                       0x778480
#define MapViewMap__SetZoom_x                                      0x77CB40

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BB490

// StringTable 
#define StringTable__getString_x                                   0x8B6370

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x663AD0
#define PcZoneClient__RemovePetEffect_x                            0x664100
#define PcZoneClient__HasAlternateAbility_x                        0x65DEE0
#define PcZoneClient__GetCurrentMod_x                              0x4E6020
#define PcZoneClient__GetModCap_x                                  0x4E5F20
#define PcZoneClient__CanEquipItem_x                               0x65E590
#define PcZoneClient__GetItemByID_x                                0x6610A0
#define PcZoneClient__GetItemByItemClass_x                         0x6611F0
#define PcZoneClient__RemoveBuffEffect_x                           0x664120
#define PcZoneClient__BandolierSwap_x                              0x65F170
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x660BC0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F3CC0

//IconCache
#define IconCache__GetIcon_x                                       0x716D30

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x70E860
#define CContainerMgr__CloseContainer_x                            0x70EB30
#define CContainerMgr__OpenExperimentContainer_x                   0x70F5B0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CD6E0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x630D70

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76B4C0
#define CLootWnd__RequestLootSlot_x                                0x76A7A0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58D6C0
#define EQ_Spell__SpellAffects_x                                   0x58DB30
#define EQ_Spell__SpellAffectBase_x                                0x58D8F0
#define EQ_Spell__IsStackable_x                                    0x4CAAE0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CA900
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7B50
#define EQ_Spell__IsSPAStacking_x                                  0x58E980
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58DE90
#define EQ_Spell__IsNoRemove_x                                     0x4CAAC0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58E990
#define __IsResEffectSpell_x                                       0x4C9CC0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD570

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C5C40

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x814610
#define CTargetWnd__WndNotification_x                              0x813E50
#define CTargetWnd__RefreshTargetBuffs_x                           0x814120
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x812FC0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x818C70
#define CTaskWnd__ConfirmAbandonTask_x                             0x81B8A0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x5416B0
#define CTaskManager__HandleMessage_x                              0x53FB00
#define CTaskManager__GetTaskStatus_x                              0x541760
#define CTaskManager__GetElementDescription_x                      0x5417E0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5887F0
#define EqSoundManager__PlayScriptMp3_x                            0x588AB0
#define EqSoundManager__SoundAssistPlay_x                          0x69BEE0
#define EqSoundManager__WaveInstancePlay_x                         0x69B450

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x532A20

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x944C80
#define CTextureAnimation__Draw_x                                  0x944E80

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x940BE0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56D7C0
#define CAltAbilityData__GetMercMaxRank_x                          0x56D750
#define CAltAbilityData__GetMaxRank_x                              0x562BE0

//CTargetRing
#define CTargetRing__Cast_x                                        0x62EE90

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA8E0
#define CharacterBase__CreateItemGlobalIndex_x                     0x519570
#define CharacterBase__CreateItemIndex_x                           0x636FA0
#define CharacterBase__GetItemPossession_x                         0x5055A0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CE290
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CE2F0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F58F0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F6120
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F61D0

//messages
#define msg_spell_worn_off_x                                       0x5B2600
#define msg_new_text_x                                             0x5A6F90
#define __msgTokenTextParam_x                                      0x5B48A0
#define msgTokenText_x                                             0x5B4AF0

//SpellManager
#define SpellManager__vftable_x                                    0xAD9544
#define SpellManager__SpellManager_x                               0x69F200
#define Spellmanager__LoadTextSpells_x                             0x69FAF0
#define SpellManager__GetSpellByGroupAndRank_x                     0x69F3D0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98CEA0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x519BF0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B8A80
#define ItemGlobalIndex__IsEquippedLocation_x                      0x64FAE0
#define ItemGlobalIndex__IsValidIndex_x                            0x519C80

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C65E0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C6860

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x763D90

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x712F40
#define CCursorAttachment__AttachToCursor1_x                       0x712F80
#define CCursorAttachment__Deactivate_x                            0x713F70

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x937970
#define CSidlManagerBase__CreatePageWnd_x                          0x937160
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x9333E0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x933370

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9549B0
#define CEQSuiteTextureLoader__GetTexture_x                        0x954670

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x516AE0
#define CFindItemWnd__WndNotification_x                            0x5175C0
#define CFindItemWnd__Update_x                                     0x518130
#define CFindItemWnd__PickupSelectedItem_x                         0x516300

//IString
#define IString__Append_x                                          0x506E20

//Camera
#define CDisplay__cameraType_x                                     0xDE9CBC
#define EverQuest__Cameras_x                                       0xEA50A0

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51F500
#define LootFiltersManager__GetItemFilterData_x                    0x51EE10
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51EE40
#define LootFiltersManager__SetItemLootFilter_x                    0x51F060

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BB540

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x992AA0
#define CResolutionHandler__GetWindowedStyle_x                     0x696990

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70B520

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8DBB50
#define CDistillerInfo__Instance_x                                 0x8DBAF0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72A2F0
#define CGroupWnd__UpdateDisplay_x                                 0x729650

//ItemBase
#define ItemBase__IsLore_x                                         0x89BA20
#define ItemBase__IsLoreEquipped_x                                 0x89BAA0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EDF20
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EE060
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EE0C0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68BDE0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x68F7A0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50D0E0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F9380
#define FactionManagerClient__HandleFactionMessage_x               0x4F99F0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F9FB0
#define FactionManagerClient__GetMaxFaction_x                      0x4F9FCF
#define FactionManagerClient__GetMinFaction_x                      0x4F9F80

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x505570

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91C060

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C2F0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x505830

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56CC70

//CTargetManager
#define CTargetManager__Get_x                                      0x6A2A70

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68BDE0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A90E0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5C0E60

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF42738

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6BF180
#define CAAWnd__UpdateSelected_x                                   0x6BB9F0
#define CAAWnd__Update_x                                           0x6BE4A0

//CXRect
#define CXRect__operator_and_x                                     0x7213D0

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x4833F0

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
static PBYTE efPattern = (PBYTE)"\xE8\x00\x00\x00\x00\x83\xC4\x08\x89\x45\xA0";
static char efMask[] = "x????xxxxxx";
