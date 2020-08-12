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
#define __ExpectedVersionDate                                     "Aug 11 2020"
#define __ExpectedVersionTime                                     "10:35:12"
#define __ActualVersionDate_x                                      0xAF1274
#define __ActualVersionTime_x                                      0xAF1268
#define __ActualVersionBuild_x                                     0xADF294

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x63FAB0
#define __MemChecker1_x                                            0x8F2520
#define __MemChecker2_x                                            0x6AFEB0
#define __MemChecker3_x                                            0x6AFE00
#define __MemChecker4_x                                            0x848D20
#define __EncryptPad0_x                                            0xC264E8
#define __EncryptPad1_x                                            0xC83D28
#define __EncryptPad2_x                                            0xC368B8
#define __EncryptPad3_x                                            0xC364B8
#define __EncryptPad4_x                                            0xC742C8
#define __EncryptPad5_x                                            0xF460B0
#define __AC1_x                                                    0x807986
#define __AC2_x                                                    0x5F95AF
#define __AC3_x                                                    0x600C00
#define __AC4_x                                                    0x604BB0
#define __AC5_x                                                    0x60AE9F
#define __AC6_x                                                    0x60F366
#define __AC7_x                                                    0x5F9020
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
#define __do_loot_x                                                0x5C5200
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
#define __gfMaxZoomCameraDistance_x                                0xAE8E90
#define __gfMaxCameraDistance_x                                    0xB11B18
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
#define __CastRay_x                                                0x5C0900
#define __CastRay2_x                                               0x5C0950
#define __ConvertItemTags_x                                        0x5DC510
#define __CleanItemTags_x                                          0x47CCD0
#define __DoesFileExist_x                                          0x8F5550
#define __EQGetTime_x                                              0x8F2150
#define __ExecuteCmd_x                                             0x5B9240
#define __FixHeading_x                                             0x986F20
#define __FlushDxKeyboard_x                                        0x6ABD50
#define __GameLoop_x                                               0x6AF080
#define __get_bearing_x                                            0x5C0460
#define __get_melee_range_x                                        0x5C0B40
#define __GetAnimationCache_x                                      0x714550
#define __GetGaugeValueFromEQ_x                                    0x805E30
#define __GetLabelFromEQ_x                                         0x807910
#define __GetXTargetType_x                                         0x9889E0
#define __HandleMouseWheel_x                                       0x6AFF60
#define __HeadingDiff_x                                            0x986F90
#define __HelpPath_x                                               0xF3E85C
#define __LoadFrontEnd_x                                           0x6AC390
#define __NewUIINI_x                                               0x805B00
#define __ProcessGameEvents_x                                      0x620F90
#define __ProcessMouseEvent_x                                      0x620720
#define __SaveColors_x                                             0x55A790
#define __STMLToText_x                                             0x92A310
#define __ToggleKeyRingItem_x                                      0x519250
#define CMemoryMappedFile__SetFile_x                               0xA76570
#define CrashDetected_x                                            0x6ADE40
#define DrawNetStatus_x                                            0x64CF90
#define Expansion_HoT_x                                            0xEA07AC
#define Teleport_Table_Size_x                                      0xE97EA8
#define Teleport_Table_x                                           0xE98370
#define Util__FastTime_x                                           0x8F1D20
#define __CopyLayout_x                                             0x63B1C0
#define __WndProc_x                                                0x6AE340
#define __ProcessKeyboardEvent_x                                   0x6AD8E0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4901B0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4991B0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x498F80
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493750
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492BA0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x5628E0
#define AltAdvManager__IsAbilityReady_x                            0x561680
#define AltAdvManager__GetAAById_x                                 0x561A10
#define AltAdvManager__CanTrainAbility_x                           0x561A80
#define AltAdvManager__CanSeeAbility_x                             0x561DE0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CACD0
#define CharacterZoneClient__HasSkill_x                            0x4D5B50
#define CharacterZoneClient__MakeMeVisible_x                       0x4D7270
#define CharacterZoneClient__IsStackBlocked_x                      0x4C2450
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BB8D0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9C20
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9D00
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9DE0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C4540
#define CharacterZoneClient__BardCastBard_x                        0x4C6F50
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF2F0
#define CharacterZoneClient__GetEffect_x                           0x4BB810
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C5590
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C5660
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C56B0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5800
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C59E0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3600
#define CharacterZoneClient__FindItemByGuid_x                      0x4D81D0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7C50

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D5B70
#define CBankWnd__WndNotification_x                                0x6D5950

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E34E0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x62F700
#define CButtonWnd__CButtonWnd_x                                   0x9266F0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x703620
#define CChatManager__InitContextMenu_x                            0x6FC750
#define CChatManager__FreeChatWindow_x                             0x702160
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9510
#define CChatManager__SetLockedActiveChatWindow_x                  0x7032A0
#define CChatManager__CreateChatWindow_x                           0x7027A0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9620

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x93AD30
#define CContextMenu__dCContextMenu_x                              0x93AF70
#define CContextMenu__AddMenuItem_x                                0x93AF80
#define CContextMenu__RemoveMenuItem_x                             0x93B290
#define CContextMenu__RemoveAllMenuItems_x                         0x93B2B0
#define CContextMenu__CheckMenuItem_x                              0x93B330
#define CContextMenu__SetMenuItem_x                                0x93B1B0
#define CContextMenu__AddSeparator_x                               0x93B110

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x93B8D0
#define CContextMenuManager__RemoveMenu_x                          0x93B940
#define CContextMenuManager__PopupMenu_x                           0x93BA00
#define CContextMenuManager__Flush_x                               0x93B870
#define CContextMenuManager__GetMenu_x                             0x49B450
#define CContextMenuManager__CreateDefaultMenu_x                   0x70EE80

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8CCD60
#define CChatService__GetFriendName_x                              0x8CCD70

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x703F50
#define CChatWindow__Clear_x                                       0x705220
#define CChatWindow__WndNotification_x                             0x7059B0
#define CChatWindow__AddHistory_x                                  0x704AE0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x938180
#define CComboWnd__Draw_x                                          0x937670
#define CComboWnd__GetCurChoice_x                                  0x937FC0
#define CComboWnd__GetListRect_x                                   0x937B20
#define CComboWnd__GetTextRect_x                                   0x9381F0
#define CComboWnd__InsertChoice_x                                  0x937CB0
#define CComboWnd__SetColors_x                                     0x937C80
#define CComboWnd__SetChoice_x                                     0x937F90
#define CComboWnd__GetItemCount_x                                  0x937FD0
#define CComboWnd__GetCurChoiceText_x                              0x938010
#define CComboWnd__GetChoiceText_x                                 0x937FE0
#define CComboWnd__InsertChoiceAtIndex_x                           0x937D50

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x70C890
#define CContainerWnd__vftable_x                                   0xAFA47C
#define CContainerWnd__SetContainer_x                              0x70DDE0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x555140
#define CDisplay__PreZoneMainUI_x                                  0x555150
#define CDisplay__CleanGameUI_x                                    0x55A550
#define CDisplay__GetClickedActor_x                                0x54D5A0
#define CDisplay__GetUserDefinedColor_x                            0x545C10
#define CDisplay__GetWorldFilePath_x                               0x54F010
#define CDisplay__is3dON_x                                         0x54A200
#define CDisplay__ReloadUI_x                                       0x554650
#define CDisplay__WriteTextHD2_x                                   0x549FF0
#define CDisplay__TrueDistance_x                                   0x550CD0
#define CDisplay__SetViewActor_x                                   0x54CEC0
#define CDisplay__GetFloorHeight_x                                 0x54A2C0
#define CDisplay__SetRenderWindow_x                                0x548C40
#define CDisplay__ToggleScreenshotMode_x                           0x54C990

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x95AC90

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x93E230
#define CEditWnd__EnsureCaretVisible_x                             0x940400
#define CEditWnd__GetCaretPt_x                                     0x93F3B0
#define CEditWnd__GetCharIndexPt_x                                 0x93F160
#define CEditWnd__GetDisplayString_x                               0x93F000
#define CEditWnd__GetHorzOffset_x                                  0x93D8D0
#define CEditWnd__GetLineForPrintableChar_x                        0x940300
#define CEditWnd__GetSelStartPt_x                                  0x93F410
#define CEditWnd__GetSTMLSafeText_x                                0x93EE20
#define CEditWnd__PointFromPrintableChar_x                         0x93FF30
#define CEditWnd__SelectableCharFromPoint_x                        0x9400A0
#define CEditWnd__SetEditable_x                                    0x93F4E0
#define CEditWnd__SetWindowTextA_x                                 0x93EBA0
#define CEditWnd__ReplaceSelection_x                               0x93FBA0
#define CEditWnd__ReplaceSelection1_x                              0x93FB20

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x60E840
#define CEverQuest__ClickedPlayer_x                                0x6009E0
#define CEverQuest__CreateTargetIndicator_x                        0x61E120
#define CEverQuest__DeleteTargetIndicator_x                        0x61E1B0
#define CEverQuest__DoTellWindow_x                                 0x4E9700
#define CEverQuest__OutputTextToLog_x                              0x4E99D0
#define CEverQuest__DropHeldItemOnGround_x                         0x5F5B30
#define CEverQuest__dsp_chat_x                                     0x4E9D60
#define CEverQuest__trimName_x                                     0x61A310
#define CEverQuest__Emote_x                                        0x60F0A0
#define CEverQuest__EnterZone_x                                    0x609190
#define CEverQuest__GetBodyTypeDesc_x                              0x6138A0
#define CEverQuest__GetClassDesc_x                                 0x613EE0
#define CEverQuest__GetClassThreeLetterCode_x                      0x6144E0
#define CEverQuest__GetDeityDesc_x                                 0x61C970
#define CEverQuest__GetLangDesc_x                                  0x6146A0
#define CEverQuest__GetRaceDesc_x                                  0x613EC0
#define CEverQuest__InterpretCmd_x                                 0x61CF40
#define CEverQuest__LeftClickedOnPlayer_x                          0x5F9CD0
#define CEverQuest__LMouseUp_x                                     0x5F8050
#define CEverQuest__RightClickedOnPlayer_x                         0x5FA5B0
#define CEverQuest__RMouseUp_x                                     0x5F8FE0
#define CEverQuest__SetGameState_x                                 0x5F58C0
#define CEverQuest__UPCNotificationFlush_x                         0x61A210
#define CEverQuest__IssuePetCommand_x                              0x615AB0
#define CEverQuest__ReportSuccessfulHit_x                          0x6103F0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x71E640
#define CGaugeWnd__CalcLinesFillRect_x                             0x71E6A0
#define CGaugeWnd__Draw_x                                          0x71DCC0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF970
#define CGuild__GetGuildName_x                                     0x4AE420
#define CGuild__GetGuildIndex_x                                    0x4AEA20

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x7382E0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x62FAC0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x7453F0
#define CInvSlotMgr__MoveItem_x                                    0x7440C0
#define CInvSlotMgr__SelectSlot_x                                  0x7454C0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7428B0
#define CInvSlot__SliderComplete_x                                 0x7405F0
#define CInvSlot__GetItemBase_x                                    0x73FF60
#define CInvSlot__UpdateItem_x                                     0x7400D0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x746F50
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7460E0
#define CInvSlotWnd__HandleLButtonUp_x                             0x746AD0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x801130
#define CItemDisplayWnd__UpdateStrings_x                           0x755750
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x74F3C0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x74F8F0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x755D60
#define CItemDisplayWnd__AboutToShow_x                             0x7553A0
#define CItemDisplayWnd__WndNotification_x                         0x756FE0
#define CItemDisplayWnd__RequestConvertItem_x                      0x756910
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x754400
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x7551C0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x831C30

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75B520

// CLabel 
#define CLabel__Draw_x                                             0x760FB0

// CListWnd
#define CListWnd__CListWnd_x                                       0x910970
#define CListWnd__dCListWnd_x                                      0x910C90
#define CListWnd__AddColumn_x                                      0x915100
#define CListWnd__AddColumn1_x                                     0x915150
#define CListWnd__AddLine_x                                        0x9154E0
#define CListWnd__AddString_x                                      0x9152E0
#define CListWnd__CalculateFirstVisibleLine_x                      0x914EC0
#define CListWnd__CalculateVSBRange_x                              0x914CB0
#define CListWnd__ClearSel_x                                       0x915CC0
#define CListWnd__ClearAllSel_x                                    0x915D20
#define CListWnd__CloseAndUpdateEditWindow_x                       0x916740
#define CListWnd__Compare_x                                        0x9145E0
#define CListWnd__Draw_x                                           0x910DC0
#define CListWnd__DrawColumnSeparators_x                           0x9135B0
#define CListWnd__DrawHeader_x                                     0x913A20
#define CListWnd__DrawItem_x                                       0x913F20
#define CListWnd__DrawLine_x                                       0x913720
#define CListWnd__DrawSeparator_x                                  0x913650
#define CListWnd__EnableLine_x                                     0x912E90
#define CListWnd__EnsureVisible_x                                  0x916660
#define CListWnd__ExtendSel_x                                      0x915BF0
#define CListWnd__GetColumnTooltip_x                               0x9129D0
#define CListWnd__GetColumnMinWidth_x                              0x912A40
#define CListWnd__GetColumnWidth_x                                 0x912940
#define CListWnd__GetCurSel_x                                      0x9122D0
#define CListWnd__GetItemAtPoint_x                                 0x913110
#define CListWnd__GetItemAtPoint1_x                                0x913180
#define CListWnd__GetItemData_x                                    0x912350
#define CListWnd__GetItemHeight_x                                  0x912710
#define CListWnd__GetItemIcon_x                                    0x9124E0
#define CListWnd__GetItemRect_x                                    0x912F80
#define CListWnd__GetItemText_x                                    0x912390
#define CListWnd__GetSelList_x                                     0x915D70
#define CListWnd__GetSeparatorRect_x                               0x9133C0
#define CListWnd__InsertLine_x                                     0x9158D0
#define CListWnd__RemoveLine_x                                     0x915A20
#define CListWnd__SetColors_x                                      0x914C80
#define CListWnd__SetColumnJustification_x                         0x9149B0
#define CListWnd__SetColumnLabel_x                                 0x915280
#define CListWnd__SetColumnWidth_x                                 0x9148D0
#define CListWnd__SetCurSel_x                                      0x915B30
#define CListWnd__SetItemColor_x                                   0x916310
#define CListWnd__SetItemData_x                                    0x9162D0
#define CListWnd__SetItemText_x                                    0x915EE0
#define CListWnd__ShiftColumnSeparator_x                           0x914A70
#define CListWnd__Sort_x                                           0x914760
#define CListWnd__ToggleSel_x                                      0x915B60
#define CListWnd__SetColumnsSizable_x                              0x914B20
#define CListWnd__SetItemWnd_x                                     0x916190
#define CListWnd__GetItemWnd_x                                     0x912530
#define CListWnd__SetItemIcon_x                                    0x915F60
#define CListWnd__CalculateCustomWindowPositions_x                 0x914FC0
#define CListWnd__SetVScrollPos_x                                  0x9148B0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7765B0
#define CMapViewWnd__GetWorldCoordinates_x                         0x774CC0
#define CMapViewWnd__HandleLButtonDown_x                           0x771D00

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x796930
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x797210
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x797740
#define CMerchantWnd__SelectRecoverySlot_x                         0x79A6F0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7954A0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A02C0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x796540

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89AE20
#define CPacketScrambler__hton_x                                   0x89AE10

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x92F8E0
#define CSidlManager__FindScreenPieceTemplate_x                    0x92FCF0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x92FAE0
#define CSidlManager__CreateLabel_x                                0x7F8310
#define CSidlManager__CreateXWndFromTemplate_x                     0x932C50
#define CSidlManager__CreateXWndFromTemplate1_x                    0x932E20
#define CSidlManager__CreateXWnd_x                                 0x7F8240
#define CSidlManager__CreateHotButtonWnd_x                         0x7F8800

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x92C3C0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x92C2C0
#define CSidlScreenWnd__ConvertToRes_x                             0x9557E0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x92BDB0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x92BAA0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x92BB70
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x92BC40
#define CSidlScreenWnd__DrawSidlPiece_x                            0x92C860
#define CSidlScreenWnd__EnableIniStorage_x                         0x92CD30
#define CSidlScreenWnd__GetSidlPiece_x                             0x92CA50
#define CSidlScreenWnd__Init1_x                                    0x92B6A0
#define CSidlScreenWnd__LoadIniInfo_x                              0x92CD80
#define CSidlScreenWnd__LoadIniListWnd_x                           0x92D8C0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92AAC0
#define CSidlScreenWnd__StoreIniInfo_x                             0x92D440
#define CSidlScreenWnd__StoreIniVis_x                              0x92D7A0
#define CSidlScreenWnd__WndNotification_x                          0x92C770
#define CSidlScreenWnd__GetChildItem_x                             0x92CCB0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x91C4A0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15D4AE8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x695010
#define CSkillMgr__GetSkillCap_x                                   0x6951F0
#define CSkillMgr__GetNameToken_x                                  0x694790
#define CSkillMgr__IsActivatedSkill_x                              0x6948D0
#define CSkillMgr__IsCombatSkill_x                                 0x694810

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x93C6B0
#define CSliderWnd__SetValue_x                                     0x93C520
#define CSliderWnd__SetNumTicks_x                                  0x93C580

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7FE4C0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x945000
#define CStmlWnd__ParseSTML_x                                      0x946350
#define CStmlWnd__CalculateHSBRange_x                              0x946130
#define CStmlWnd__CalculateVSBRange_x                              0x9460A0
#define CStmlWnd__CanBreakAtCharacter_x                            0x94A460
#define CStmlWnd__FastForwardToEndOfTag_x                          0x94B0F0
#define CStmlWnd__ForceParseNow_x                                  0x9455F0
#define CStmlWnd__GetNextTagPiece_x                                0x94A3C0
#define CStmlWnd__GetSTMLText_x                                    0x50A670
#define CStmlWnd__GetVisibleText_x                                 0x945610
#define CStmlWnd__InitializeWindowVariables_x                      0x94AF40
#define CStmlWnd__MakeStmlColorTag_x                               0x944670
#define CStmlWnd__MakeWndNotificationTag_x                         0x9446E0
#define CStmlWnd__SetSTMLText_x                                    0x943720
#define CStmlWnd__StripFirstSTMLLines_x                            0x94C1F0
#define CStmlWnd__UpdateHistoryString_x                            0x94B300

// CTabWnd 
#define CTabWnd__Draw_x                                            0x942870
#define CTabWnd__DrawCurrentPage_x                                 0x942FA0
#define CTabWnd__DrawTab_x                                         0x942CC0
#define CTabWnd__GetCurrentPage_x                                  0x942070
#define CTabWnd__GetPageInnerRect_x                                0x9422B0
#define CTabWnd__GetTabInnerRect_x                                 0x9421F0
#define CTabWnd__GetTabRect_x                                      0x9420A0
#define CTabWnd__InsertPage_x                                      0x9424C0
#define CTabWnd__RemovePage_x                                      0x942630
#define CTabWnd__SetPage_x                                         0x942330
#define CTabWnd__SetPageRect_x                                     0x9427B0
#define CTabWnd__UpdatePage_x                                      0x942B80
#define CTabWnd__GetPageFromTabIndex_x                             0x942C00
#define CTabWnd__GetCurrentTabIndex_x                              0x942060

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x75B9A0
#define CPageWnd__SetTabText_x                                     0x941BB0
#define CPageWnd__FlashTab_x                                       0x941C10

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8CF0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x919360
#define CTextureFont__GetTextExtent_x                              0x919520

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6A9200
#define CHtmlComponentWnd__ValidateUri_x                           0x739CD0
#define CHtmlWnd__SetClientCallbacks_x                             0x634B60
#define CHtmlWnd__AddObserver_x                                    0x634B80
#define CHtmlWnd__RemoveObserver_x                                 0x634BE0
#define Window__getProgress_x                                      0x850350
#define Window__getStatus_x                                        0x850370
#define Window__getURI_x                                           0x850380

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9525F0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x9063A0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9350
#define CXStr__CXStr1_x                                            0x4811C0
#define CXStr__CXStr3_x                                            0x8EE110
#define CXStr__dCXStr_x                                            0x477F20
#define CXStr__operator_equal_x                                    0x8EE340
#define CXStr__operator_equal1_x                                   0x8EE380
#define CXStr__operator_plus_equal1_x                              0x8EEE10
#define CXStr__SetString_x                                         0x8F0D00
#define CXStr__operator_char_p_x                                   0x8EE880
#define CXStr__GetChar_x                                           0x8F0630
#define CXStr__Delete_x                                            0x8EFF00
#define CXStr__GetUnicode_x                                        0x8F06A0
#define CXStr__GetLength_x                                         0x47D080
#define CXStr__Mid_x                                               0x47D090
#define CXStr__Insert_x                                            0x8F0700
#define CXStr__FindNext_x                                          0x8F0370

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93A940
#define CXWnd__BringToTop_x                                        0x91FC80
#define CXWnd__Center_x                                            0x91F800
#define CXWnd__ClrFocus_x                                          0x91F620
#define CXWnd__Destroy_x                                           0x91F6C0
#define CXWnd__DoAllDrawing_x                                      0x91BC30
#define CXWnd__DrawChildren_x                                      0x91BC00
#define CXWnd__DrawColoredRect_x                                   0x91C090
#define CXWnd__DrawTooltip_x                                       0x91A740
#define CXWnd__DrawTooltipAtPoint_x                                0x91A800
#define CXWnd__GetBorderFrame_x                                    0x91BEF0
#define CXWnd__GetChildWndAt_x                                     0x91FD20
#define CXWnd__GetClientClipRect_x                                 0x91DEA0
#define CXWnd__GetScreenClipRect_x                                 0x91DF70
#define CXWnd__GetScreenRect_x                                     0x91E140
#define CXWnd__GetRelativeRect_x                                   0x91E210
#define CXWnd__GetTooltipRect_x                                    0x91C0E0
#define CXWnd__GetWindowTextA_x                                    0x49CB40
#define CXWnd__IsActive_x                                          0x91C820
#define CXWnd__IsDescendantOf_x                                    0x91EB70
#define CXWnd__IsReallyVisible_x                                   0x91EBA0
#define CXWnd__IsType_x                                            0x920390
#define CXWnd__Move_x                                              0x91EC00
#define CXWnd__Move1_x                                             0x91ECB0
#define CXWnd__ProcessTransition_x                                 0x91F7B0
#define CXWnd__Refade_x                                            0x91EF90
#define CXWnd__Resize_x                                            0x91F230
#define CXWnd__Right_x                                             0x91FA40
#define CXWnd__SetFocus_x                                          0x91F5E0
#define CXWnd__SetFont_x                                           0x91F650
#define CXWnd__SetKeyTooltip_x                                     0x9201B0
#define CXWnd__SetMouseOver_x                                      0x91D060
#define CXWnd__StartFade_x                                         0x91EA50
#define CXWnd__GetChildItem_x                                      0x91FE90
#define CXWnd__SetParent_x                                         0x91E900
#define CXWnd__Minimize_x                                          0x91F2A0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x956860

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x922BD0
#define CXWndManager__DrawWindows_x                                0x922BF0
#define CXWndManager__GetKeyboardFlags_x                           0x925310
#define CXWndManager__HandleKeyboardMsg_x                          0x924EC0
#define CXWndManager__RemoveWnd_x                                  0x925540
#define CXWndManager__RemovePendingDeletionWnd_x                   0x925AC0

// CDBStr
#define CDBStr__GetString_x                                        0x544BE0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BFA50
#define EQ_Character__Cur_HP_x                                     0x4D2B90
#define EQ_Character__Cur_Mana_x                                   0x4DA2E0
#define EQ_Character__GetCastingTimeModifier_x                     0x4C2AC0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B3240
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3390
#define EQ_Character__GetHPRegen_x                                 0x4E0120
#define EQ_Character__GetEnduranceRegen_x                          0x4E0720
#define EQ_Character__GetManaRegen_x                               0x4E0B60
#define EQ_Character__Max_Endurance_x                              0x65B580
#define EQ_Character__Max_HP_x                                     0x4D29C0
#define EQ_Character__Max_Mana_x                                   0x65B380
#define EQ_Character__doCombatAbility_x                            0x65D960
#define EQ_Character__UseSkill_x                                   0x4E2960
#define EQ_Character__GetConLevel_x                                0x653E80
#define EQ_Character__IsExpansionFlag_x                            0x5B7A30
#define EQ_Character__TotalEffect_x                                0x4C6840
#define EQ_Character__GetPCSpellAffect_x                           0x4C3810
#define EQ_Character__SpellDuration_x                              0x4C3340
#define EQ_Character__MySpellDuration_x                            0x4B1B70
#define EQ_Character__GetAdjustedSkill_x                           0x4D5910
#define EQ_Character__GetBaseSkill_x                               0x4D68B0
#define EQ_Character__CanUseItem_x                                 0x4DA5F0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8B9E40

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x6718B0

//PcClient
#define PcClient__vftable_x                                        0xAEDEF4
#define PcClient__PcClient_x                                       0x6515E0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA470
#define CCharacterListWnd__EnterWorld_x                            0x4B9E50
#define CCharacterListWnd__Quit_x                                  0x4B9BA0
#define CCharacterListWnd__UpdateList_x                            0x4BA040

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x635D20
#define EQ_Item__CreateItemTagString_x                             0x894400
#define EQ_Item__IsStackable_x                                     0x8990A0
#define EQ_Item__GetImageNum_x                                     0x895F80
#define EQ_Item__CreateItemClient_x                                0x634F60
#define EQ_Item__GetItemValue_x                                    0x897280
#define EQ_Item__ValueSellMerchant_x                               0x89AA00
#define EQ_Item__IsKeyRingItem_x                                   0x8989C0
#define EQ_Item__CanGoInBag_x                                      0x635E40
#define EQ_Item__IsEmpty_x                                         0x898500
#define EQ_Item__GetMaxItemCount_x                                 0x897690
#define EQ_Item__GetHeldItem_x                                     0x895E50
#define EQ_Item__GetAugmentFitBySlot_x                             0x893C60

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x5635B0
#define EQ_LoadingS__Array_x                                       0xC0DC68

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65BE80
#define EQ_PC__GetAlternateAbilityId_x                             0x8A39F0
#define EQ_PC__GetCombatAbility_x                                  0x8A4060
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A40D0
#define EQ_PC__GetItemRecastTimer_x                                0x65DEE0
#define EQ_PC__HasLoreItem_x                                       0x654690
#define EQ_PC__AlertInventoryChanged_x                             0x6537B0
#define EQ_PC__GetPcZoneClient_x                                   0x6809A0
#define EQ_PC__RemoveMyAffect_x                                    0x661110
#define EQ_PC__GetKeyRingItems_x                                   0x8A4960
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A46F0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A4C60

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5BDE40
#define EQItemList__add_object_x                                   0x5EB220
#define EQItemList__add_item_x                                     0x5BE3A0
#define EQItemList__delete_item_x                                  0x5BE3F0
#define EQItemList__FreeItemList_x                                 0x5BE2F0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x5417B0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x6731B0
#define EQPlayer__dEQPlayer_x                                      0x666530
#define EQPlayer__DoAttack_x                                       0x67B140
#define EQPlayer__EQPlayer_x                                       0x666BF0
#define EQPlayer__SetNameSpriteState_x                             0x66AEC0
#define EQPlayer__SetNameSpriteTint_x                              0x66BDA0
#define PlayerBase__HasProperty_j_x                                0x985330
#define EQPlayer__IsTargetable_x                                   0x9857D0
#define EQPlayer__CanSee_x                                         0x985630
#define EQPlayer__CanSee1_x                                        0x985700
#define PlayerBase__GetVisibilityLineSegment_x                     0x9853F0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x67E440
#define PlayerZoneClient__GetLevel_x                               0x6809E0
#define PlayerZoneClient__IsValidTeleport_x                        0x5EC390
#define PlayerZoneClient__LegalPlayerRace_x                        0x55C3E0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x676010
#define EQPlayerManager__GetSpawnByName_x                          0x6760C0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x676150

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x639420
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x6394A0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x6394E0
#define KeypressHandler__ClearCommandStateArray_x                  0x63A8D0
#define KeypressHandler__HandleKeyDown_x                           0x63A8F0
#define KeypressHandler__HandleKeyUp_x                             0x63A990
#define KeypressHandler__SaveKeymapping_x                          0x63ADE0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x772420
#define MapViewMap__SaveEx_x                                       0x7757E0
#define MapViewMap__SetZoom_x                                      0x779EA0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B7EB0

// StringTable 
#define StringTable__getString_x                                   0x8B2DA0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x660D80
#define PcZoneClient__RemovePetEffect_x                            0x6613B0
#define PcZoneClient__HasAlternateAbility_x                        0x65B1B0
#define PcZoneClient__GetCurrentMod_x                              0x4E5A40
#define PcZoneClient__GetModCap_x                                  0x4E5940
#define PcZoneClient__CanEquipItem_x                               0x65B860
#define PcZoneClient__GetItemByID_x                                0x65E350
#define PcZoneClient__GetItemByItemClass_x                         0x65E4A0
#define PcZoneClient__RemoveBuffEffect_x                           0x6613D0
#define PcZoneClient__BandolierSwap_x                              0x65C430
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x65DE80

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F0F50

//IconCache
#define IconCache__GetIcon_x                                       0x713F50

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x70BA20
#define CContainerMgr__CloseContainer_x                            0x70BCF0
#define CContainerMgr__OpenExperimentContainer_x                   0x70C770

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CAA30

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x62DEC0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x7689E0
#define CLootWnd__RequestLootSlot_x                                0x767CC0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58A420
#define EQ_Spell__SpellAffects_x                                   0x58A890
#define EQ_Spell__SpellAffectBase_x                                0x58A650
#define EQ_Spell__IsStackable_x                                    0x4CA5A0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CA3C0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7730
#define EQ_Spell__IsSPAStacking_x                                  0x58B6E0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58ABF0
#define EQ_Spell__IsNoRemove_x                                     0x4CA580
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58B6F0
#define __IsResEffectSpell_x                                       0x4C9780

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4ACEC0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C23C0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x8118D0
#define CTargetWnd__WndNotification_x                              0x811110
#define CTargetWnd__RefreshTargetBuffs_x                           0x8113E0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x810270

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x815F20
#define CTaskWnd__ConfirmAbandonTask_x                             0x818B60

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x53F200
#define CTaskManager__HandleMessage_x                              0x53D690
#define CTaskManager__GetTaskStatus_x                              0x53F2B0
#define CTaskManager__GetElementDescription_x                      0x53F330

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5855A0
#define EqSoundManager__PlayScriptMp3_x                            0x585860
#define EqSoundManager__SoundAssistPlay_x                          0x698F70
#define EqSoundManager__WaveInstancePlay_x                         0x6984E0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x5307F0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x9410C0
#define CTextureAnimation__Draw_x                                  0x9412C0

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x93D010

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56B180
#define CAltAbilityData__GetMercMaxRank_x                          0x56B110
#define CAltAbilityData__GetMaxRank_x                              0x560500

//CTargetRing
#define CTargetRing__Cast_x                                        0x62BFE0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA3A0
#define CharacterBase__CreateItemGlobalIndex_x                     0x5173E0
#define CharacterBase__CreateItemIndex_x                           0x634110
#define CharacterBase__GetItemPossession_x                         0x5030E0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CAA10
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CAA70
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F2980
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F31B0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F3260

//messages
#define msg_spell_worn_off_x                                       0x5AF9C0
#define msg_new_text_x                                             0x5A4350
#define __msgTokenTextParam_x                                      0x5B1C60
#define msgTokenText_x                                             0x5B1EB0

//SpellManager
#define SpellManager__vftable_x                                    0xAD62DC
#define SpellManager__SpellManager_x                               0x69C2A0
#define Spellmanager__LoadTextSpells_x                             0x69CB90
#define SpellManager__GetSpellByGroupAndRank_x                     0x69C470

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9892D0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x517A60
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B5E30
#define ItemGlobalIndex__IsEquippedLocation_x                      0x64CDF0
#define ItemGlobalIndex__IsValidIndex_x                            0x517AF0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C2D60
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C2FE0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x7612F0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x710120
#define CCursorAttachment__AttachToCursor1_x                       0x710160
#define CCursorAttachment__Deactivate_x                            0x711150

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x933C70
#define CSidlManagerBase__CreatePageWnd_x                          0x933470
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x92F700
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x92F690

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x951100
#define CEQSuiteTextureLoader__GetTexture_x                        0x950DC0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x514930
#define CFindItemWnd__WndNotification_x                            0x515410
#define CFindItemWnd__Update_x                                     0x515F80
#define CFindItemWnd__PickupSelectedItem_x                         0x514150

//IString
#define IString__Append_x                                          0x504900

//Camera
#define CDisplay__cameraType_x                                     0xDE5878
#define EverQuest__Cameras_x                                       0xEA0AF8

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51D400
#define LootFiltersManager__GetItemFilterData_x                    0x51CD00
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51CD30
#define LootFiltersManager__SetItemLootFilter_x                    0x51CF50

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B8870

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x98F020
#define CResolutionHandler__GetWindowedStyle_x                     0x693A20

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x7086D0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D84F0
#define CDistillerInfo__Instance_x                                 0x8D8490

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x727670
#define CGroupWnd__UpdateDisplay_x                                 0x7269C0

//ItemBase
#define ItemBase__IsLore_x                                         0x898A70
#define ItemBase__IsLoreEquipped_x                                 0x898AE0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EB180
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EB2C0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EB320

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6890C0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x68CA20

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50AC70

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F6DF0
#define FactionManagerClient__HandleFactionMessage_x               0x4F7460
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F7A60
#define FactionManagerClient__GetMaxFaction_x                      0x4F7A7F
#define FactionManagerClient__GetMinFaction_x                      0x4F7A30

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x5030B0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x9183B0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BE50

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x503310

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56A600

//CTargetManager
#define CTargetManager__Get_x                                      0x69FAE0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6890C0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8AB0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5BE290

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF3E18C

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6BC2F0
#define CAAWnd__UpdateSelected_x                                   0x6B8B60
#define CAAWnd__Update_x                                           0x6BB610

//CXRect
#define CXRect__operator_and_x                                     0x71E750

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x482D90

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
