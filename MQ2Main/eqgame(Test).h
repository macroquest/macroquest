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
#define __ExpectedVersionDate                                     "Aug 26 2020"
#define __ExpectedVersionTime                                     "08:19:22"
#define __ActualVersionDate_x                                      0xAF128C
#define __ActualVersionTime_x                                      0xAF1280
#define __ActualVersionBuild_x                                     0xADF2A4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x63FA50
#define __MemChecker1_x                                            0x8F2900
#define __MemChecker2_x                                            0x6B03D0
#define __MemChecker3_x                                            0x6B0320
#define __MemChecker4_x                                            0x849520
#define __EncryptPad0_x                                            0xC264E8
#define __EncryptPad1_x                                            0xC83D28
#define __EncryptPad2_x                                            0xC368B8
#define __EncryptPad3_x                                            0xC364B8
#define __EncryptPad4_x                                            0xC742C8
#define __EncryptPad5_x                                            0xF460B0
#define __AC1_x                                                    0x807E46
#define __AC2_x                                                    0x5F942F
#define __AC3_x                                                    0x600A80
#define __AC4_x                                                    0x604A30
#define __AC5_x                                                    0x60AD1F
#define __AC6_x                                                    0x60F1E6
#define __AC7_x                                                    0x5F8EA0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x193CD8

// Direct Input
#define DI8__Main_x                                                0xF460D0
#define DI8__Keyboard_x                                            0xF460D4
#define DI8__Mouse_x                                               0xF460EC
#define DI8__Mouse_Copy_x                                          0xE9F44C
#define DI8__Mouse_Check_x                                         0xF43C04
#define __AutoSkillArray_x                                         0xEA0364
#define __Attack_x                                                 0xF3E187
#define __Autofire_x                                               0xF3E188
#define __BindList_x                                               0xC14F38
#define g_eqCommandStates_x                                        0xC15CB8
#define __Clicks_x                                                 0xE9F504
#define __CommandList_x                                            0xC16878
#define __CurrentMapLabel_x                                        0xF56AA4
#define __CurrentSocial_x                                          0xBFE7C8
#define __DoAbilityList_x                                          0xED5CA8
#define __do_loot_x                                                0x5C5150
#define __DrawHandler_x                                            0x15D5A98
#define __GroupCount_x                                             0xE9A522
#define __Guilds_x                                                 0xE9E388
#define __gWorld_x                                                 0xE9A4B4
#define __HWnd_x                                                   0xF460F0
#define __heqmain_x                                                0xF46098
#define __InChatMode_x                                             0xE9F434
#define __LastTell_x                                               0xEA13A4
#define __LMouseHeldTime_x                                         0xE9F570
#define __Mouse_x                                                  0xF460BC
#define __MouseLook_x                                              0xE9F4CA
#define __MouseEventTime_x                                         0xF3EC6C
#define __gpbCommandEvent_x                                        0xE97E20
#define __NetStatusToggle_x                                        0xE9F4CD
#define __PCNames_x                                                0xEA0954
#define __RangeAttackReady_x                                       0xEA0648
#define __RMouseHeldTime_x                                         0xE9F56C
#define __RunWalkState_x                                           0xE9F438
#define __ScreenMode_x                                             0xDE57B0
#define __ScreenX_x                                                0xE9F3EC
#define __ScreenY_x                                                0xE9F3E8
#define __ScreenXMax_x                                             0xE9F3F0
#define __ScreenYMax_x                                             0xE9F3F4
#define __ServerHost_x                                             0xE97FF3
#define __ServerName_x                                             0xED5C68
#define __ShiftKeyDown_x                                           0xE9FAC4
#define __ShowNames_x                                              0xEA0804
#define EverQuestInfo__bSocialChanged_x                            0xED5CF0
#define __Socials_x                                                0xED5D68
#define __SubscriptionType_x                                       0xF9AD68
#define __TargetAggroHolder_x                                      0xF59458
#define __ZoneType_x                                               0xE9F8C8
#define __GroupAggro_x                                             0xF59498
#define __LoginName_x                                              0xF4682C
#define __Inviter_x                                                0xF3E104
#define __AttackOnAssist_x                                         0xEA07C0
#define __UseTellWindows_x                                         0xEA0AEC
#define __gfMaxZoomCameraDistance_x                                0xAE8EA0
#define __gfMaxCameraDistance_x                                    0xB11B20
#define __pulAutoRun_x                                             0xE9F4E8
#define __pulForward_x                                             0xEA0B24
#define __pulBackward_x                                            0xEA0B28
#define __pulTurnRight_x                                           0xEA0B2C
#define __pulTurnLeft_x                                            0xEA0B30
#define __pulStrafeLeft_x                                          0xEA0B34
#define __pulStrafeRight_x                                         0xEA0B38

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE9A720
#define instEQZoneInfo_x                                           0xE9F6C0
#define pinstActiveBanker_x                                        0xE9830C
#define pinstActiveCorpse_x                                        0xE98304
#define pinstActiveGMaster_x                                       0xE98308
#define pinstActiveMerchant_x                                      0xE980FC
#define pinstAltAdvManager_x                                       0xDE6950
#define pinstBandageTarget_x                                       0xE9831C
#define pinstCamActor_x                                            0xDE57A4
#define pinstCDBStr_x                                              0xDE566C
#define pinstCDisplay_x                                            0xE9A374
#define pinstCEverQuest_x                                          0xF460E8
#define pinstEverQuestInfo_x                                       0xE9F3E0
#define pinstCharData_x                                            0xE9A710
#define pinstCharSpawn_x                                           0xE98354
#define pinstControlledMissile_x                                   0xE98364
#define pinstControlledPlayer_x                                    0xE98354
#define pinstCResolutionHandler_x                                  0x15D5CC8
#define pinstCSidlManager_x                                        0x15D4C60
#define pinstCXWndManager_x                                        0x15D4C5C
#define instDynamicZone_x                                          0xE9E260
#define pinstDZMember_x                                            0xE9E370
#define pinstDZTimerInfo_x                                         0xE9E374
#define pinstEqLogin_x                                             0xF46178
#define instEQMisc_x                                               0xDE55B0
#define pinstEQSoundManager_x                                      0xDE7920
#define pinstEQSpellStrings_x                                      0xCA7F68
#define instExpeditionLeader_x                                     0xE9E2AA
#define instExpeditionName_x                                       0xE9E2EA
#define pinstGroup_x                                               0xE9A51E
#define pinstImeManager_x                                          0x15D4C58
#define pinstLocalPlayer_x                                         0xE97EEC
#define pinstMercenaryData_x                                       0xF40764
#define pinstMercenaryStats_x                                      0xF59524
#define pinstModelPlayer_x                                         0xE98314
#define pinstPCData_x                                              0xE9A710
#define pinstSkillMgr_x                                            0xF428C8
#define pinstSpawnManager_x                                        0xF41370
#define pinstSpellManager_x                                        0xF42B08
#define pinstSpellSets_x                                           0xF36DB0
#define pinstStringTable_x                                         0xE9A718
#define pinstSwitchManager_x                                       0xE97CC0
#define pinstTarget_x                                              0xE98350
#define pinstTargetObject_x                                        0xE9835C
#define pinstTargetSwitch_x                                        0xE9836C
#define pinstTaskMember_x                                          0xDE5440
#define pinstTrackTarget_x                                         0xE98358
#define pinstTradeTarget_x                                         0xE98310
#define instTributeActive_x                                        0xDE55D1
#define pinstViewActor_x                                           0xDE579C
#define pinstWorldData_x                                           0xE97E10
#define pinstZoneAddr_x                                            0xE9F960
#define pinstPlayerPath_x                                          0xF41408
#define pinstTargetIndicator_x                                     0xF42D70
#define EQObject_Top_x                                             0xE97EE8
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDE5AE4
#define pinstCAchievementsWnd_x                                    0xDE5740
#define pinstCActionsWnd_x                                         0xDE5F78
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDE57FC
#define pinstCAdvancedLootWnd_x                                    0xDE5794
#define pinstCAdventureLeaderboardWnd_x                            0xF50278
#define pinstCAdventureRequestWnd_x                                0xF50328
#define pinstCAdventureStatsWnd_x                                  0xF503D8
#define pinstCAggroMeterWnd_x                                      0xDE57E4
#define pinstCAlarmWnd_x                                           0xDE5764
#define pinstCAlertHistoryWnd_x                                    0xDE5874
#define pinstCAlertStackWnd_x                                      0xDE57CC
#define pinstCAlertWnd_x                                           0xDE57E0
#define pinstCAltStorageWnd_x                                      0xF50738
#define pinstCAudioTriggersWindow_x                                0xC9A298
#define pinstCAuraWnd_x                                            0xDE5798
#define pinstCAvaZoneWnd_x                                         0xDE583C
#define pinstCBandolierWnd_x                                       0xDE57F8
#define pinstCBankWnd_x                                            0xDE582C
#define pinstCBarterMerchantWnd_x                                  0xF51978
#define pinstCBarterSearchWnd_x                                    0xF51A28
#define pinstCBarterWnd_x                                          0xF51AD8
#define pinstCBazaarConfirmationWnd_x                              0xDE577C
#define pinstCBazaarSearchWnd_x                                    0xDE5AE8
#define pinstCBazaarWnd_x                                          0xDE5744
#define pinstCBlockedBuffWnd_x                                     0xDE57C0
#define pinstCBlockedPetBuffWnd_x                                  0xDE57E8
#define pinstCBodyTintWnd_x                                        0xDE5F8C
#define pinstCBookWnd_x                                            0xDE5824
#define pinstCBreathWnd_x                                          0xDE5B6C
#define pinstCBuffWindowNORMAL_x                                   0xDE578C
#define pinstCBuffWindowSHORT_x                                    0xDE5790
#define pinstCBugReportWnd_x                                       0xDE5828
#define pinstCButtonWnd_x                                          0x15D4EC8
#define pinstCCastingWnd_x                                         0xDE5818
#define pinstCCastSpellWnd_x                                       0xDE5B68
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDE5F98
#define pinstCChatWindowManager_x                                  0xF52598
#define pinstCClaimWnd_x                                           0xF526F0
#define pinstCColorPickerWnd_x                                     0xDE5A94
#define pinstCCombatAbilityWnd_x                                   0xDE5758
#define pinstCCombatSkillsSelectWnd_x                              0xDE5710
#define pinstCCompassWnd_x                                         0xDE5F7C
#define pinstCConfirmationDialog_x                                 0xF575F0
#define pinstCContainerMgr_x                                       0xDE5F88
#define pinstCContextMenuManager_x                                 0x15D4C18
#define pinstCCursorAttachment_x                                   0xDE580C
#define pinstCDynamicZoneWnd_x                                     0xF52CB8
#define pinstCEditLabelWnd_x                                       0xDE5784
#define pinstCEQMainWnd_x                                          0xF52F00
#define pinstCEventCalendarWnd_x                                   0xDE5AFC
#define pinstCExtendedTargetWnd_x                                  0xDE57C8
#define pinstCFacePick_x                                           0xDE5714
#define pinstCFactionWnd_x                                         0xDE5734
#define pinstCFellowshipWnd_x                                      0xF53100
#define pinstCFileSelectionWnd_x                                   0xDE5A8C
#define pinstCFindItemWnd_x                                        0xDE5724
#define pinstCFindLocationWnd_x                                    0xF53258
#define pinstCFriendsWnd_x                                         0xDE5728
#define pinstCGemsGameWnd_x                                        0xDE5730
#define pinstCGiveWnd_x                                            0xDE5768
#define pinstCGroupSearchFiltersWnd_x                              0xDE5800
#define pinstCGroupSearchWnd_x                                     0xF53650
#define pinstCGroupWnd_x                                           0xF53700
#define pinstCGuildBankWnd_x                                       0xEA07A4
#define pinstCGuildCreationWnd_x                                   0xF53860
#define pinstCGuildMgmtWnd_x                                       0xF53910
#define pinstCharacterCreation_x                                   0xDE5718
#define pinstCHelpWnd_x                                            0xDE576C
#define pinstCHeritageSelectionWnd_x                               0xDE5720
#define pinstCHotButtonWnd_x                                       0xF55A68
#define pinstCHotButtonWnd1_x                                      0xF55A68
#define pinstCHotButtonWnd2_x                                      0xF55A6C
#define pinstCHotButtonWnd3_x                                      0xF55A70
#define pinstCHotButtonWnd4_x                                      0xF55A74
#define pinstCIconSelectionWnd_x                                   0xDE5808
#define pinstCInspectWnd_x                                         0xDE57EC
#define pinstCInventoryWnd_x                                       0xDE57A0
#define pinstCInvSlotMgr_x                                         0xDE5AD8
#define pinstCItemDisplayManager_x                                 0xF55FF8
#define pinstCItemExpTransferWnd_x                                 0xF56128
#define pinstCItemOverflowWnd_x                                    0xDE5B64
#define pinstCJournalCatWnd_x                                      0xDE5AA0
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDE5860
#define pinstCKeyRingWnd_x                                         0xDE5814
#define pinstCLargeDialogWnd_x                                     0xF58270
#define pinstCLayoutCopyWnd_x                                      0xF56478
#define pinstCLFGuildWnd_x                                         0xF56528
#define pinstCLoadskinWnd_x                                        0xDE5748
#define pinstCLootFiltersCopyWnd_x                                 0xCB6948
#define pinstCLootFiltersWnd_x                                     0xDE57D0
#define pinstCLootSettingsWnd_x                                    0xDE57F4
#define pinstCLootWnd_x                                            0xDE5AA8
#define pinstCMailAddressBookWnd_x                                 0xDE5ADC
#define pinstCMailCompositionWnd_x                                 0xDE5A98
#define pinstCMailIgnoreListWnd_x                                  0xDE5AE0
#define pinstCMailWnd_x                                            0xDE5A84
#define pinstCManageLootWnd_x                                      0xDE6E00
#define pinstCMapToolbarWnd_x                                      0xDE5770
#define pinstCMapViewWnd_x                                         0xDE573C
#define pinstCMarketplaceWnd_x                                     0xDE57D4
#define pinstCMerchantWnd_x                                        0xDE5AD0
#define pinstCMIZoneSelectWnd_x                                    0xF56D60
#define pinstCMusicPlayerWnd_x                                     0xDE5A80
#define pinstCNameChangeMercWnd_x                                  0xDE5774
#define pinstCNameChangePetWnd_x                                   0xDE574C
#define pinstCNameChangeWnd_x                                      0xDE5788
#define pinstCNoteWnd_x                                            0xDE5750
#define pinstCObjectPreviewWnd_x                                   0xDE57F0
#define pinstCOptionsWnd_x                                         0xDE575C
#define pinstCPetInfoWnd_x                                         0xDE587C
#define pinstCPetitionQWnd_x                                       0xDE570C
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDE5F90
#define pinstCPlayerWnd_x                                          0xDE586C
#define pinstCPopupWndManager_x                                    0xF575F0
#define pinstCProgressionSelectionWnd_x                            0xF576A0
#define pinstCPurchaseGroupWnd_x                                   0xDE5848
#define pinstCPurchaseWnd_x                                        0xDE581C
#define pinstCPvPLeaderboardWnd_x                                  0xF57750
#define pinstCPvPStatsWnd_x                                        0xF57800
#define pinstCQuantityWnd_x                                        0xDE585C
#define pinstCRaceChangeWnd_x                                      0xDE57BC
#define pinstCRaidOptionsWnd_x                                     0xDE5804
#define pinstCRaidWnd_x                                            0xDE5AB0
#define pinstCRealEstateItemsWnd_x                                 0xDE5738
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDE5F84
#define pinstCRealEstateManageWnd_x                                0xDE584C
#define pinstCRealEstateNeighborhoodWnd_x                          0xDE5868
#define pinstCRealEstatePlotSearchWnd_x                            0xDE5A88
#define pinstCRealEstatePurchaseWnd_x                              0xDE5AA4
#define pinstCRespawnWnd_x                                         0xDE57DC
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDE5708
#define pinstCSendMoneyWnd_x                                       0xDE5778
#define pinstCServerListWnd_x                                      0xDE5AAC
#define pinstCSkillsSelectWnd_x                                    0xDE5FA0
#define pinstCSkillsWnd_x                                          0xDE5F80
#define pinstCSocialEditWnd_x                                      0xDE5810
#define pinstCSocialWnd_x                                          0xDE5760
#define pinstCSpellBookWnd_x                                       0xDE5754
#define pinstCStoryWnd_x                                           0xDE5F74
#define pinstCTargetOfTargetWnd_x                                  0xF595A8
#define pinstCTargetWnd_x                                          0xDE57D8
#define pinstCTaskOverlayWnd_x                                     0xDE5840
#define pinstCTaskSelectWnd_x                                      0xF59700
#define pinstCTaskManager_x                                        0xCB7288
#define pinstCTaskTemplateSelectWnd_x                              0xF597B0
#define pinstCTaskWnd_x                                            0xF59860
#define pinstCTextEntryWnd_x                                       0xDE5820
#define pinstCTimeLeftWnd_x                                        0xDE5F9C
#define pinstCTipWndCONTEXT_x                                      0xF59A64
#define pinstCTipWndOFDAY_x                                        0xF59A60
#define pinstCTitleWnd_x                                           0xF59B10
#define pinstCTrackingWnd_x                                        0xDE57C4
#define pinstCTradeskillWnd_x                                      0xF59C78
#define pinstCTradeWnd_x                                           0xDE5F94
#define pinstCTrainWnd_x                                           0xDE5A9C
#define pinstCTributeBenefitWnd_x                                  0xF59E78
#define pinstCTributeMasterWnd_x                                   0xF59F28
#define pinstCTributeTrophyWnd_x                                   0xF59FD8
#define pinstCVideoModesWnd_x                                      0xDE5870
#define pinstCVoiceMacroWnd_x                                      0xF43328
#define pinstCVoteResultsWnd_x                                     0xDE572C
#define pinstCVoteWnd_x                                            0xDE571C
#define pinstCWebManager_x                                         0xF439A4
#define pinstCZoneGuideWnd_x                                       0xDE5844
#define pinstCZonePathWnd_x                                        0xDE5858

#define pinstEQSuiteTextureLoader_x                                0xC84648
#define pinstItemIconCache_x                                       0xF52EB8
#define pinstLootFiltersManager_x                                  0xCB69F8
#define pinstRewardSelectionWnd_x                                  0xF57F48

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5C0850
#define __CastRay2_x                                               0x5C08A0
#define __ConvertItemTags_x                                        0x5DC460
#define __CleanItemTags_x                                          0x47CD90
#define __DoesFileExist_x                                          0x8F5980
#define __EQGetTime_x                                              0x8F2530
#define __ExecuteCmd_x                                             0x5B91A0
#define __FixHeading_x                                             0x9877F0
#define __FlushDxKeyboard_x                                        0x6AC270
#define __GameLoop_x                                               0x6AF5A0
#define __get_bearing_x                                            0x5C03B0
#define __get_melee_range_x                                        0x5C0A90
#define __GetAnimationCache_x                                      0x714950
#define __GetGaugeValueFromEQ_x                                    0x8062F0
#define __GetLabelFromEQ_x                                         0x807DD0
#define __GetXTargetType_x                                         0x989310
#define __HandleMouseWheel_x                                       0x6B0480
#define __HeadingDiff_x                                            0x987860
#define __HelpPath_x                                               0xF3E85C
#define __LoadFrontEnd_x                                           0x6AC8B0
#define __NewUIINI_x                                               0x805FC0
#define __ProcessGameEvents_x                                      0x620E10
#define __ProcessMouseEvent_x                                      0x6205A0
#define __SaveColors_x                                             0x55A640
#define __STMLToText_x                                             0x92AC90
#define __ToggleKeyRingItem_x                                      0x518FE0
#define CMemoryMappedFile__SetFile_x                               0xA76D70
#define CrashDetected_x                                            0x6AE360
#define DrawNetStatus_x                                            0x64CE70
#define Expansion_HoT_x                                            0xEA07AC
#define Teleport_Table_Size_x                                      0xE97EA8
#define Teleport_Table_x                                           0xE98370
#define Util__FastTime_x                                           0x8F2100
#define __CopyLayout_x                                             0x63B1A0
#define __WndProc_x                                                0x6AE860
#define __ProcessKeyboardEvent_x                                   0x6ADE00

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4900D0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4990D0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x498EA0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493670
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492AC0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x5627A0
#define AltAdvManager__IsAbilityReady_x                            0x561540
#define AltAdvManager__GetAAById_x                                 0x5618D0
#define AltAdvManager__CanTrainAbility_x                           0x561940
#define AltAdvManager__CanSeeAbility_x                             0x561CA0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CADF0
#define CharacterZoneClient__HasSkill_x                            0x4D5C70
#define CharacterZoneClient__MakeMeVisible_x                       0x4D7390
#define CharacterZoneClient__IsStackBlocked_x                      0x4C2600
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBA80
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9D40
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9E20
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9F00
#define CharacterZoneClient__FindAffectSlot_x                      0x4C46F0
#define CharacterZoneClient__BardCastBard_x                        0x4C7100
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF4A0
#define CharacterZoneClient__GetEffect_x                           0x4BB9C0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C5740
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C5810
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C5860
#define CharacterZoneClient__CalcAffectChange_x                    0x4C59B0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5B90
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3770
#define CharacterZoneClient__FindItemByGuid_x                      0x4D82F0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7D70

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D6010
#define CBankWnd__WndNotification_x                                0x6D5DF0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E39D0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x928470
#define CButtonWnd__CButtonWnd_x                                   0x927070

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x703B20
#define CChatManager__InitContextMenu_x                            0x6FCC50
#define CChatManager__FreeChatWindow_x                             0x702660
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9580
#define CChatManager__SetLockedActiveChatWindow_x                  0x7037A0
#define CChatManager__CreateChatWindow_x                           0x702CA0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E96A0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x93B5E0
#define CContextMenu__dCContextMenu_x                              0x93B820
#define CContextMenu__AddMenuItem_x                                0x93B830
#define CContextMenu__RemoveMenuItem_x                             0x93BB40
#define CContextMenu__RemoveAllMenuItems_x                         0x93BB60
#define CContextMenu__CheckMenuItem_x                              0x93BBE0
#define CContextMenu__SetMenuItem_x                                0x93BA60
#define CContextMenu__AddSeparator_x                               0x93B9C0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x93C180
#define CContextMenuManager__RemoveMenu_x                          0x93C1F0
#define CContextMenuManager__PopupMenu_x                           0x93C2B0
#define CContextMenuManager__Flush_x                               0x93C120
#define CContextMenuManager__GetMenu_x                             0x49B3D0
#define CContextMenuManager__CreateDefaultMenu_x                   0x70F2B0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8CD370
#define CChatService__GetFriendName_x                              0x8CD380

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x704390
#define CChatWindow__Clear_x                                       0x705660
#define CChatWindow__WndNotification_x                             0x705DF0
#define CChatWindow__AddHistory_x                                  0x704F20

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x938A40
#define CComboWnd__Draw_x                                          0x937F30
#define CComboWnd__GetCurChoice_x                                  0x938880
#define CComboWnd__GetListRect_x                                   0x9383E0
#define CComboWnd__GetTextRect_x                                   0x938AB0
#define CComboWnd__InsertChoice_x                                  0x938570
#define CComboWnd__SetColors_x                                     0x938540
#define CComboWnd__SetChoice_x                                     0x938850
#define CComboWnd__GetItemCount_x                                  0x938890
#define CComboWnd__GetCurChoiceText_x                              0x9388D0
#define CComboWnd__GetChoiceText_x                                 0x9388A0
#define CComboWnd__InsertChoiceAtIndex_x                           0x938610

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x70CCC0
#define CContainerWnd__vftable_x                                   0xAFA484
#define CContainerWnd__SetContainer_x                              0x70E210

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x554FF0
#define CDisplay__PreZoneMainUI_x                                  0x555000
#define CDisplay__CleanGameUI_x                                    0x55A400
#define CDisplay__GetClickedActor_x                                0x54D450
#define CDisplay__GetUserDefinedColor_x                            0x545AC0
#define CDisplay__GetWorldFilePath_x                               0x54EEC0
#define CDisplay__is3dON_x                                         0x54A0B0
#define CDisplay__ReloadUI_x                                       0x554500
#define CDisplay__WriteTextHD2_x                                   0x549EA0
#define CDisplay__TrueDistance_x                                   0x550B80
#define CDisplay__SetViewActor_x                                   0x54CD70
#define CDisplay__GetFloorHeight_x                                 0x54A170
#define CDisplay__SetRenderWindow_x                                0x548AF0
#define CDisplay__ToggleScreenshotMode_x                           0x54C840

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x95B430

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x93EAF0
#define CEditWnd__EnsureCaretVisible_x                             0x940CC0
#define CEditWnd__GetCaretPt_x                                     0x93FC70
#define CEditWnd__GetCharIndexPt_x                                 0x93FA20
#define CEditWnd__GetDisplayString_x                               0x93F8C0
#define CEditWnd__GetHorzOffset_x                                  0x93E190
#define CEditWnd__GetLineForPrintableChar_x                        0x940BC0
#define CEditWnd__GetSelStartPt_x                                  0x93FCD0
#define CEditWnd__GetSTMLSafeText_x                                0x93F6E0
#define CEditWnd__PointFromPrintableChar_x                         0x9407F0
#define CEditWnd__SelectableCharFromPoint_x                        0x940960
#define CEditWnd__SetEditable_x                                    0x93FDA0
#define CEditWnd__SetWindowTextA_x                                 0x93F460
#define CEditWnd__ReplaceSelection_x                               0x940460
#define CEditWnd__ReplaceSelection1_x                              0x9403E0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x60E6C0
#define CEverQuest__ClickedPlayer_x                                0x600860
#define CEverQuest__CreateTargetIndicator_x                        0x61DFA0
#define CEverQuest__DeleteTargetIndicator_x                        0x61E030
#define CEverQuest__DoTellWindow_x                                 0x4E9780
#define CEverQuest__OutputTextToLog_x                              0x4E9A50
#define CEverQuest__DropHeldItemOnGround_x                         0x5F59B0
#define CEverQuest__dsp_chat_x                                     0x4E9DE0
#define CEverQuest__trimName_x                                     0x61A190
#define CEverQuest__Emote_x                                        0x60EF20
#define CEverQuest__EnterZone_x                                    0x609010
#define CEverQuest__GetBodyTypeDesc_x                              0x613720
#define CEverQuest__GetClassDesc_x                                 0x613D60
#define CEverQuest__GetClassThreeLetterCode_x                      0x614360
#define CEverQuest__GetDeityDesc_x                                 0x61C7F0
#define CEverQuest__GetLangDesc_x                                  0x614520
#define CEverQuest__GetRaceDesc_x                                  0x613D40
#define CEverQuest__InterpretCmd_x                                 0x61CDC0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5F9B50
#define CEverQuest__LMouseUp_x                                     0x5F7ED0
#define CEverQuest__RightClickedOnPlayer_x                         0x5FA430
#define CEverQuest__RMouseUp_x                                     0x5F8E60
#define CEverQuest__SetGameState_x                                 0x5F5740
#define CEverQuest__UPCNotificationFlush_x                         0x61A090
#define CEverQuest__IssuePetCommand_x                              0x615930
#define CEverQuest__ReportSuccessfulHit_x                          0x610270

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x71E920
#define CGaugeWnd__CalcLinesFillRect_x                             0x71E980
#define CGaugeWnd__Draw_x                                          0x71DFA0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AFB30
#define CGuild__GetGuildName_x                                     0x4AE5E0
#define CGuild__GetGuildIndex_x                                    0x4AEBE0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x7385C0

//CHotButton
#define CHotButton__SetCheck_x                                     0x62F610
#define CHotButton__SetButtonSize_x                                0x62F9D0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x7456F0
#define CInvSlotMgr__MoveItem_x                                    0x7443C0
#define CInvSlotMgr__SelectSlot_x                                  0x7457C0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x742BB0
#define CInvSlot__SliderComplete_x                                 0x7408F0
#define CInvSlot__GetItemBase_x                                    0x740260
#define CInvSlot__UpdateItem_x                                     0x7403D0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x747250
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7463E0
#define CInvSlotWnd__HandleLButtonUp_x                             0x746DD0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x801660
#define CItemDisplayWnd__UpdateStrings_x                           0x755A70
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x74F6E0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x74FC10
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x756080
#define CItemDisplayWnd__AboutToShow_x                             0x7556C0
#define CItemDisplayWnd__WndNotification_x                         0x757300
#define CItemDisplayWnd__RequestConvertItem_x                      0x756C30
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x754720
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x7554E0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x832090

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75B840

// CLabel 
#define CLabel__Draw_x                                             0x7612D0

// CListWnd
#define CListWnd__CListWnd_x                                       0x9111F0
#define CListWnd__dCListWnd_x                                      0x911510
#define CListWnd__AddColumn_x                                      0x915980
#define CListWnd__AddColumn1_x                                     0x9159D0
#define CListWnd__AddLine_x                                        0x915D60
#define CListWnd__AddString_x                                      0x915B60
#define CListWnd__CalculateFirstVisibleLine_x                      0x915740
#define CListWnd__CalculateVSBRange_x                              0x915530
#define CListWnd__ClearSel_x                                       0x916540
#define CListWnd__ClearAllSel_x                                    0x9165A0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x916FC0
#define CListWnd__Compare_x                                        0x914E60
#define CListWnd__Draw_x                                           0x911640
#define CListWnd__DrawColumnSeparators_x                           0x913E30
#define CListWnd__DrawHeader_x                                     0x9142A0
#define CListWnd__DrawItem_x                                       0x9147A0
#define CListWnd__DrawLine_x                                       0x913FA0
#define CListWnd__DrawSeparator_x                                  0x913ED0
#define CListWnd__EnableLine_x                                     0x913710
#define CListWnd__EnsureVisible_x                                  0x916EE0
#define CListWnd__ExtendSel_x                                      0x916470
#define CListWnd__GetColumnTooltip_x                               0x913250
#define CListWnd__GetColumnMinWidth_x                              0x9132C0
#define CListWnd__GetColumnWidth_x                                 0x9131C0
#define CListWnd__GetCurSel_x                                      0x912B50
#define CListWnd__GetItemAtPoint_x                                 0x913990
#define CListWnd__GetItemAtPoint1_x                                0x913A00
#define CListWnd__GetItemData_x                                    0x912BD0
#define CListWnd__GetItemHeight_x                                  0x912F90
#define CListWnd__GetItemIcon_x                                    0x912D60
#define CListWnd__GetItemRect_x                                    0x913800
#define CListWnd__GetItemText_x                                    0x912C10
#define CListWnd__GetSelList_x                                     0x9165F0
#define CListWnd__GetSeparatorRect_x                               0x913C40
#define CListWnd__InsertLine_x                                     0x916150
#define CListWnd__RemoveLine_x                                     0x9162A0
#define CListWnd__SetColors_x                                      0x915500
#define CListWnd__SetColumnJustification_x                         0x915230
#define CListWnd__SetColumnLabel_x                                 0x915B00
#define CListWnd__SetColumnWidth_x                                 0x915150
#define CListWnd__SetCurSel_x                                      0x9163B0
#define CListWnd__SetItemColor_x                                   0x916B90
#define CListWnd__SetItemData_x                                    0x916B50
#define CListWnd__SetItemText_x                                    0x916760
#define CListWnd__ShiftColumnSeparator_x                           0x9152F0
#define CListWnd__Sort_x                                           0x914FE0
#define CListWnd__ToggleSel_x                                      0x9163E0
#define CListWnd__SetColumnsSizable_x                              0x9153A0
#define CListWnd__SetItemWnd_x                                     0x916A10
#define CListWnd__GetItemWnd_x                                     0x912DB0
#define CListWnd__SetItemIcon_x                                    0x9167E0
#define CListWnd__CalculateCustomWindowPositions_x                 0x915840
#define CListWnd__SetVScrollPos_x                                  0x915130

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7768D0
#define CMapViewWnd__GetWorldCoordinates_x                         0x774FE0
#define CMapViewWnd__HandleLButtonDown_x                           0x772020

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x796CB0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x797590
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x797AC0
#define CMerchantWnd__SelectRecoverySlot_x                         0x79AA70
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x795820
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A0640
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7968C0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89B290
#define CPacketScrambler__hton_x                                   0x89B280

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x930260
#define CSidlManager__FindScreenPieceTemplate_x                    0x930670
#define CSidlManager__FindScreenPieceTemplate1_x                   0x930460
#define CSidlManager__CreateLabel_x                                0x7F88B0
#define CSidlManager__CreateXWndFromTemplate_x                     0x9335D0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x9337A0
#define CSidlManager__CreateXWnd_x                                 0x7F87E0
#define CSidlManager__CreateHotButtonWnd_x                         0x7F8DA0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x92CD40
#define CSidlScreenWnd__CalculateVSBRange_x                        0x92CC40
#define CSidlScreenWnd__ConvertToRes_x                             0x955F20
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x92C730
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x92C420
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x92C4F0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x92C5C0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x92D1E0
#define CSidlScreenWnd__EnableIniStorage_x                         0x92D6B0
#define CSidlScreenWnd__GetSidlPiece_x                             0x92D3D0
#define CSidlScreenWnd__Init1_x                                    0x92C020
#define CSidlScreenWnd__LoadIniInfo_x                              0x92D700
#define CSidlScreenWnd__LoadIniListWnd_x                           0x92E240
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92B440
#define CSidlScreenWnd__StoreIniInfo_x                             0x92DDC0
#define CSidlScreenWnd__StoreIniVis_x                              0x92E120
#define CSidlScreenWnd__WndNotification_x                          0x92D0F0
#define CSidlScreenWnd__GetChildItem_x                             0x92D630
#define CSidlScreenWnd__HandleLButtonUp_x                          0x91CDF0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15D4AE8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x695170
#define CSkillMgr__GetSkillCap_x                                   0x695350
#define CSkillMgr__GetNameToken_x                                  0x6948F0
#define CSkillMgr__IsActivatedSkill_x                              0x694A30
#define CSkillMgr__IsCombatSkill_x                                 0x694970

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x93CF60
#define CSliderWnd__SetValue_x                                     0x93CDD0
#define CSliderWnd__SetNumTicks_x                                  0x93CE30

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7FE9F0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x9458C0
#define CStmlWnd__ParseSTML_x                                      0x946C10
#define CStmlWnd__CalculateHSBRange_x                              0x9469F0
#define CStmlWnd__CalculateVSBRange_x                              0x946960
#define CStmlWnd__CanBreakAtCharacter_x                            0x94AD20
#define CStmlWnd__FastForwardToEndOfTag_x                          0x94B9B0
#define CStmlWnd__ForceParseNow_x                                  0x945EB0
#define CStmlWnd__GetNextTagPiece_x                                0x94AC80
#define CStmlWnd__GetSTMLText_x                                    0x50A4E0
#define CStmlWnd__GetVisibleText_x                                 0x945ED0
#define CStmlWnd__InitializeWindowVariables_x                      0x94B800
#define CStmlWnd__MakeStmlColorTag_x                               0x944F30
#define CStmlWnd__MakeWndNotificationTag_x                         0x944FA0
#define CStmlWnd__SetSTMLText_x                                    0x943FE0
#define CStmlWnd__StripFirstSTMLLines_x                            0x94CAB0
#define CStmlWnd__UpdateHistoryString_x                            0x94BBC0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x943130
#define CTabWnd__DrawCurrentPage_x                                 0x943860
#define CTabWnd__DrawTab_x                                         0x943580
#define CTabWnd__GetCurrentPage_x                                  0x942930
#define CTabWnd__GetPageInnerRect_x                                0x942B70
#define CTabWnd__GetTabInnerRect_x                                 0x942AB0
#define CTabWnd__GetTabRect_x                                      0x942960
#define CTabWnd__InsertPage_x                                      0x942D80
#define CTabWnd__RemovePage_x                                      0x942EF0
#define CTabWnd__SetPage_x                                         0x942BF0
#define CTabWnd__SetPageRect_x                                     0x943070
#define CTabWnd__UpdatePage_x                                      0x943440
#define CTabWnd__GetPageFromTabIndex_x                             0x9434C0
#define CTabWnd__GetCurrentTabIndex_x                              0x942920

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x75BC50
#define CPageWnd__SetTabText_x                                     0x942470
#define CPageWnd__FlashTab_x                                       0x9424D0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8E10

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x919CB0
#define CTextureFont__GetTextExtent_x                              0x919E70

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6A9450
#define CHtmlComponentWnd__ValidateUri_x                           0x739FB0
#define CHtmlWnd__SetClientCallbacks_x                             0x634A70
#define CHtmlWnd__AddObserver_x                                    0x634A90
#define CHtmlWnd__RemoveObserver_x                                 0x634AF0
#define Window__getProgress_x                                      0x850B30
#define Window__getStatus_x                                        0x850B50
#define Window__getURI_x                                           0x850B60

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x952D30

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x906DC0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9470
#define CXStr__CXStr1_x                                            0x4B71F0
#define CXStr__CXStr3_x                                            0x8EE4F0
#define CXStr__dCXStr_x                                            0x477F50
#define CXStr__operator_equal_x                                    0x8EE720
#define CXStr__operator_equal1_x                                   0x8EE760
#define CXStr__operator_plus_equal1_x                              0x8EF1F0
#define CXStr__SetString_x                                         0x8F10E0
#define CXStr__operator_char_p_x                                   0x8EEC30
#define CXStr__GetChar_x                                           0x8F0A10
#define CXStr__Delete_x                                            0x8F02E0
#define CXStr__GetUnicode_x                                        0x8F0A80
#define CXStr__GetLength_x                                         0x4A8BC0
#define CXStr__Mid_x                                               0x47D140
#define CXStr__Insert_x                                            0x8F0AE0
#define CXStr__FindNext_x                                          0x8F0750

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93B200
#define CXWnd__BringToTop_x                                        0x9205D0
#define CXWnd__Center_x                                            0x920150
#define CXWnd__ClrFocus_x                                          0x91FF70
#define CXWnd__Destroy_x                                           0x920010
#define CXWnd__DoAllDrawing_x                                      0x91C580
#define CXWnd__DrawChildren_x                                      0x91C550
#define CXWnd__DrawColoredRect_x                                   0x91C9E0
#define CXWnd__DrawTooltip_x                                       0x91B090
#define CXWnd__DrawTooltipAtPoint_x                                0x91B150
#define CXWnd__GetBorderFrame_x                                    0x91C840
#define CXWnd__GetChildWndAt_x                                     0x920670
#define CXWnd__GetClientClipRect_x                                 0x91E7F0
#define CXWnd__GetScreenClipRect_x                                 0x91E8C0
#define CXWnd__GetScreenRect_x                                     0x91EA90
#define CXWnd__GetRelativeRect_x                                   0x91EB60
#define CXWnd__GetTooltipRect_x                                    0x91CA30
#define CXWnd__GetWindowTextA_x                                    0x49CAC0
#define CXWnd__IsActive_x                                          0x91D170
#define CXWnd__IsDescendantOf_x                                    0x91F4C0
#define CXWnd__IsReallyVisible_x                                   0x91F4F0
#define CXWnd__IsType_x                                            0x920CE0
#define CXWnd__Move_x                                              0x91F550
#define CXWnd__Move1_x                                             0x91F600
#define CXWnd__ProcessTransition_x                                 0x920100
#define CXWnd__Refade_x                                            0x91F8E0
#define CXWnd__Resize_x                                            0x91FB80
#define CXWnd__Right_x                                             0x920390
#define CXWnd__SetFocus_x                                          0x91FF30
#define CXWnd__SetFont_x                                           0x91FFA0
#define CXWnd__SetKeyTooltip_x                                     0x920B00
#define CXWnd__SetMouseOver_x                                      0x91D9B0
#define CXWnd__StartFade_x                                         0x91F3A0
#define CXWnd__GetChildItem_x                                      0x9207E0
#define CXWnd__SetParent_x                                         0x91F250
#define CXWnd__Minimize_x                                          0x91FBF0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x956FA0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x923520
#define CXWndManager__DrawWindows_x                                0x923540
#define CXWndManager__GetKeyboardFlags_x                           0x925C60
#define CXWndManager__HandleKeyboardMsg_x                          0x925810
#define CXWndManager__RemoveWnd_x                                  0x925E90
#define CXWndManager__RemovePendingDeletionWnd_x                   0x926410

// CDBStr
#define CDBStr__GetString_x                                        0x544A60

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BFC00
#define EQ_Character__Cur_HP_x                                     0x4D2CB0
#define EQ_Character__Cur_Mana_x                                   0x4DA400
#define EQ_Character__GetCastingTimeModifier_x                     0x4C2C70
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B33B0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3500
#define EQ_Character__GetHPRegen_x                                 0x4E0240
#define EQ_Character__GetEnduranceRegen_x                          0x4E0840
#define EQ_Character__GetManaRegen_x                               0x4E0C80
#define EQ_Character__Max_Endurance_x                              0x65B7F0
#define EQ_Character__Max_HP_x                                     0x4D2AE0
#define EQ_Character__Max_Mana_x                                   0x65B5F0
#define EQ_Character__doCombatAbility_x                            0x65DBD0
#define EQ_Character__UseSkill_x                                   0x4E2A80
#define EQ_Character__GetConLevel_x                                0x653E70
#define EQ_Character__IsExpansionFlag_x                            0x5B7990
#define EQ_Character__TotalEffect_x                                0x4C69F0
#define EQ_Character__GetPCSpellAffect_x                           0x4C39C0
#define EQ_Character__SpellDuration_x                              0x4C34F0
#define EQ_Character__MySpellDuration_x                            0x4B1CE0
#define EQ_Character__GetAdjustedSkill_x                           0x4D5A30
#define EQ_Character__GetBaseSkill_x                               0x4D69D0
#define EQ_Character__CanUseItem_x                                 0x4DA710

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BA3F0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x671B20

//PcClient
#define PcClient__vftable_x                                        0xAEDF04
#define PcClient__PcClient_x                                       0x6515D0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA620
#define CCharacterListWnd__EnterWorld_x                            0x4BA000
#define CCharacterListWnd__Quit_x                                  0x4B9D50
#define CCharacterListWnd__UpdateList_x                            0x4BA1F0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x635C30
#define EQ_Item__CreateItemTagString_x                             0x894880
#define EQ_Item__IsStackable_x                                     0x899520
#define EQ_Item__GetImageNum_x                                     0x896400
#define EQ_Item__CreateItemClient_x                                0x634E70
#define EQ_Item__GetItemValue_x                                    0x897700
#define EQ_Item__ValueSellMerchant_x                               0x89AE70
#define EQ_Item__IsKeyRingItem_x                                   0x898E40
#define EQ_Item__CanGoInBag_x                                      0x635D50
#define EQ_Item__IsEmpty_x                                         0x898980
#define EQ_Item__GetMaxItemCount_x                                 0x897B10
#define EQ_Item__GetHeldItem_x                                     0x8962D0
#define EQ_Item__GetAugmentFitBySlot_x                             0x8940E0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x5634E0
#define EQ_LoadingS__Array_x                                       0xC0DC68

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65C0F0
#define EQ_PC__GetAlternateAbilityId_x                             0x8A3E50
#define EQ_PC__GetCombatAbility_x                                  0x8A44C0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A4530
#define EQ_PC__GetItemRecastTimer_x                                0x65E150
#define EQ_PC__HasLoreItem_x                                       0x654680
#define EQ_PC__AlertInventoryChanged_x                             0x6537A0
#define EQ_PC__GetPcZoneClient_x                                   0x680D10
#define EQ_PC__RemoveMyAffect_x                                    0x661380
#define EQ_PC__GetKeyRingItems_x                                   0x8A4DC0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A4B50
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A50C0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5BDDA0
#define EQItemList__add_object_x                                   0x5EB1E0
#define EQItemList__add_item_x                                     0x5BE300
#define EQItemList__delete_item_x                                  0x5BE350
#define EQItemList__FreeItemList_x                                 0x5BE250

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x541630

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x673420
#define EQPlayer__dEQPlayer_x                                      0x6667A0
#define EQPlayer__DoAttack_x                                       0x67B4B0
#define EQPlayer__EQPlayer_x                                       0x666E60
#define EQPlayer__SetNameSpriteState_x                             0x66B130
#define EQPlayer__SetNameSpriteTint_x                              0x66C010
#define PlayerBase__HasProperty_j_x                                0x985C00
#define EQPlayer__IsTargetable_x                                   0x9860A0
#define EQPlayer__CanSee_x                                         0x985F00
#define EQPlayer__CanSee1_x                                        0x985FD0
#define PlayerBase__GetVisibilityLineSegment_x                     0x985CC0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x67E7B0
#define PlayerZoneClient__GetLevel_x                               0x680D50
#define PlayerZoneClient__IsValidTeleport_x                        0x5EC350
#define PlayerZoneClient__LegalPlayerRace_x                        0x55C290

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x6762F0
#define EQPlayerManager__GetSpawnByName_x                          0x6763A0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x676430

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x639400
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x639480
#define KeypressHandler__AttachKeyToEqCommand_x                    0x6394C0
#define KeypressHandler__ClearCommandStateArray_x                  0x63A8B0
#define KeypressHandler__HandleKeyDown_x                           0x63A8D0
#define KeypressHandler__HandleKeyUp_x                             0x63A970
#define KeypressHandler__SaveKeymapping_x                          0x63ADC0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x772740
#define MapViewMap__SaveEx_x                                       0x775B00
#define MapViewMap__SetZoom_x                                      0x77A1C0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B8450

// StringTable 
#define StringTable__getString_x                                   0x8B3210

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x660FF0
#define PcZoneClient__RemovePetEffect_x                            0x661620
#define PcZoneClient__HasAlternateAbility_x                        0x65B420
#define PcZoneClient__GetCurrentMod_x                              0x4E5B60
#define PcZoneClient__GetModCap_x                                  0x4E5A60
#define PcZoneClient__CanEquipItem_x                               0x65BAD0
#define PcZoneClient__GetItemByID_x                                0x65E5C0
#define PcZoneClient__GetItemByItemClass_x                         0x65E710
#define PcZoneClient__RemoveBuffEffect_x                           0x661640
#define PcZoneClient__BandolierSwap_x                              0x65C6A0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x65E0F0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F0EC0

//IconCache
#define IconCache__GetIcon_x                                       0x714350

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x70BE60
#define CContainerMgr__CloseContainer_x                            0x70C130
#define CContainerMgr__OpenExperimentContainer_x                   0x70CBB0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CAF50

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x62DDD0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x768D10
#define CLootWnd__RequestLootSlot_x                                0x767FF0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58A420
#define EQ_Spell__SpellAffects_x                                   0x58A890
#define EQ_Spell__SpellAffectBase_x                                0x58A650
#define EQ_Spell__IsStackable_x                                    0x4CA6E0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CA530
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B78B0
#define EQ_Spell__IsSPAStacking_x                                  0x58B6E0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58ABF0
#define EQ_Spell__IsNoRemove_x                                     0x4CA6C0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58B6F0
#define __IsResEffectSpell_x                                       0x4C9930

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD080

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C29D0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x811D50
#define CTargetWnd__WndNotification_x                              0x811590
#define CTargetWnd__RefreshTargetBuffs_x                           0x811860
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x8106F0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x8163A0
#define CTaskWnd__ConfirmAbandonTask_x                             0x818FE0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x53F060
#define CTaskManager__HandleMessage_x                              0x53D4F0
#define CTaskManager__GetTaskStatus_x                              0x53F110
#define CTaskManager__GetElementDescription_x                      0x53F190

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5855C0
#define EqSoundManager__PlayScriptMp3_x                            0x585880
#define EqSoundManager__SoundAssistPlay_x                          0x699100
#define EqSoundManager__WaveInstancePlay_x                         0x698670

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x530600

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x941980
#define CTextureAnimation__Draw_x                                  0x941B80

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x93D8D0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56B000
#define CAltAbilityData__GetMercMaxRank_x                          0x56AF90
#define CAltAbilityData__GetMaxRank_x                              0x5603B0

//CTargetRing
#define CTargetRing__Cast_x                                        0x62BEF0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA510
#define CharacterBase__CreateItemGlobalIndex_x                     0x5171E0
#define CharacterBase__CreateItemIndex_x                           0x634020
#define CharacterBase__GetItemPossession_x                         0x502DF0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CB020
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CB080
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F2DF0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F3620
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F36D0

//messages
#define msg_spell_worn_off_x                                       0x5AF9C0
#define msg_new_text_x                                             0x5A4350
#define __msgTokenTextParam_x                                      0x5B1C60
#define msgTokenText_x                                             0x5B1EB0

//SpellManager
#define SpellManager__vftable_x                                    0xAD62B4
#define SpellManager__SpellManager_x                               0x69C430
#define Spellmanager__LoadTextSpells_x                             0x69CD20
#define SpellManager__GetSpellByGroupAndRank_x                     0x69C600

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x989C00

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x517830
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B5E20
#define ItemGlobalIndex__IsEquippedLocation_x                      0x64CCD0
#define ItemGlobalIndex__IsValidIndex_x                            0x5178C0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C3370
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C35F0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x761610

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x710550
#define CCursorAttachment__AttachToCursor1_x                       0x710590
#define CCursorAttachment__Deactivate_x                            0x711580

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x9345F0
#define CSidlManagerBase__CreatePageWnd_x                          0x933DF0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x930080
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x930010

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x951850
#define CEQSuiteTextureLoader__GetTexture_x                        0x951510

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x514760
#define CFindItemWnd__WndNotification_x                            0x515240
#define CFindItemWnd__Update_x                                     0x515DB0
#define CFindItemWnd__PickupSelectedItem_x                         0x513F80

//IString
#define IString__Append_x                                          0x5046B0

//Camera
#define CDisplay__cameraType_x                                     0xDE5878
#define EverQuest__Cameras_x                                       0xEA0AF8

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51D180
#define LootFiltersManager__GetItemFilterData_x                    0x51CA80
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51CAB0
#define LootFiltersManager__SetItemLootFilter_x                    0x51CCD0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B8D90

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x98F810
#define CResolutionHandler__GetWindowedStyle_x                     0x693CA0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x708B10

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D8950
#define CDistillerInfo__Instance_x                                 0x8D88F0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x727900
#define CGroupWnd__UpdateDisplay_x                                 0x726C50

//ItemBase
#define ItemBase__IsLore_x                                         0x898EF0
#define ItemBase__IsLoreEquipped_x                                 0x898F60

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EB140
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EB280
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EB2E0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x689430
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x68CD90

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50AB50

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F6BF0
#define FactionManagerClient__HandleFactionMessage_x               0x4F7260
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F7860
#define FactionManagerClient__GetMaxFaction_x                      0x4F787F
#define FactionManagerClient__GetMinFaction_x                      0x4F7830

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x502DC0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x918C60

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BDD0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x5030C0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56A480

//CTargetManager
#define CTargetManager__Get_x                                      0x69FD70

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x689430

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8BD0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5BE1F0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF3E18C

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6BC7C0
#define CAAWnd__UpdateSelected_x                                   0x6B9030
#define CAAWnd__Update_x                                           0x6BBAE0

//CXRect
#define CXRect__operator_and_x                                     0x71E9E0

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x482D60

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
