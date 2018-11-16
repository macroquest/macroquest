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
#define __ExpectedVersionDate                                     "Nov 15 2018"
#define __ExpectedVersionTime                                     "04:42:50"
#define __ActualVersionDate_x                                      0xAC9DE4
#define __ActualVersionTime_x                                      0xAC9DD8

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x60F000
#define __MemChecker1_x                                            0x8E3E80
#define __MemChecker2_x                                            0x69EAC0
#define __MemChecker3_x                                            0x69EA10
#define __MemChecker4_x                                            0x83B520
#define __EncryptPad0_x                                            0xBFCE78
#define __EncryptPad1_x                                            0xC5B108
#define __EncryptPad2_x                                            0xC0DA00
#define __EncryptPad3_x                                            0xC0D600
#define __EncryptPad4_x                                            0xC4B978
#define __EncryptPad5_x                                            0xF170B4
#define __AC1_x                                                    0x7F7CC6
#define __AC2_x                                                    0x5CA07F
#define __AC3_x                                                    0x5D0F0F
#define __AC4_x                                                    0x5D4D30
#define __AC5_x                                                    0x5DAEE0
#define __AC6_x                                                    0x5DF426
#define __AC7_x                                                    0x5C9AF0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1BC548

// Direct Input
#define DI8__Main_x                                                0xF170D8
#define DI8__Keyboard_x                                            0xF170DC
#define DI8__Mouse_x                                               0xF170A0
#define DI8__Mouse_Copy_x                                          0xE74DFC
#define DI8__Mouse_Check_x                                         0xF17FA0
#define __AutoSkillArray_x                                         0xE75D14
#define __Attack_x                                                 0xF13B1B
#define __Autofire_x                                               0xF13B1C
#define __BindList_x                                               0xBEBA58
#define g_eqCommandStates_x                                        0xBEC7C8
#define __Clicks_x                                                 0xE74EB4
#define __CommandList_x                                            0xBED380
#define __CurrentMapLabel_x                                        0x10296C4
#define __CurrentSocial_x                                          0xBD6730
#define __DoAbilityList_x                                          0xEAB63C
#define __do_loot_x                                                0x597940
#define __DrawHandler_x                                            0x16A6098
#define __GroupCount_x                                             0xE657AA
#define __Guilds_x                                                 0xE6B608
#define __gWorld_x                                                 0xE6578C
#define __HWnd_x                                                   0xF170A4
#define __heqmain_x                                                0x10222FC
#define __InChatMode_x                                             0xE74DE4
#define __LastTell_x                                               0xE76D38
#define __LMouseHeldTime_x                                         0xE74F20
#define __Mouse_x                                                  0xF170C0
#define __MouseLook_x                                              0xE74E7A
#define __MouseEventTime_x                                         0xF145D0
#define __gpbCommandEvent_x                                        0xE65228
#define __NetStatusToggle_x                                        0xE74E7D
#define __PCNames_x                                                0xE762F4
#define __RangeAttackReady_x                                       0xE75FF8
#define __RMouseHeldTime_x                                         0xE74F1C
#define __RunWalkState_x                                           0xE74DE8
#define __ScreenMode_x                                             0xDB31A4
#define __ScreenX_x                                                0xE74D9C
#define __ScreenY_x                                                0xE74D98
#define __ScreenXMax_x                                             0xE74DA0
#define __ScreenYMax_x                                             0xE74DA4
#define __ServerHost_x                                             0xE6545B
#define __ServerName_x                                             0xEAB5FC
#define __ShiftKeyDown_x                                           0xE75474
#define __ShowNames_x                                              0xE761B4
#define __Socials_x                                                0xEAB6FC
#define __SubscriptionType_x                                       0x106B214
#define __TargetAggroHolder_x                                      0x102C080
#define __ZoneType_x                                               0xE75278
#define __GroupAggro_x                                             0x102C0C0
#define __LoginName_x                                              0xF17934
#define __Inviter_x                                                0xF13A98
#define __AttackOnAssist_x                                         0xE76170
#define __UseTellWindows_x                                         0xE7648C
#define __gfMaxZoomCameraDistance_x                                0xABF2F8
#define __gfMaxCameraDistance_x                                    0xAEC7EC
#define __pulAutoRun_x                                             0xE74E98
#define __pulForward_x                                             0xE764C4
#define __pulBackward_x                                            0xE764C8
#define __pulTurnRight_x                                           0xE764CC
#define __pulTurnLeft_x                                            0xE764D0
#define __pulStrafeLeft_x                                          0xE764D4
#define __pulStrafeRight_x                                         0xE764D8
//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE679A0
#define instEQZoneInfo_x                                           0xE75070
#define instKeypressHandler_x                                      0xF14580
#define pinstActiveBanker_x                                        0xE65308
#define pinstActiveCorpse_x                                        0xE65300
#define pinstActiveGMaster_x                                       0xE65304
#define pinstActiveMerchant_x                                      0xE652FC
#define pinstAggroInfo_x                                           0xC718F8
#define pinstAltAdvManager_x                                       0xDB4348
#define pinstAuraMgr_x                                             0xC825E0
#define pinstBandageTarget_x                                       0xE65318
#define pinstCamActor_x                                            0xDB3198
#define pinstCDBStr_x                                              0xDB307C
#define pinstCDisplay_x                                            0xE6576C
#define pinstCEverQuest_x                                          0xF171F8
#define pinstEverQuestInfo_x                                       0xE74D90
#define pinstCharData_x                                            0xE65778
#define pinstCharSpawn_x                                           0xE65350
#define pinstControlledMissile_x                                   0xE65774
#define pinstControlledPlayer_x                                    0xE65350
#define pinstCResolutionHandler_x                                  0x16A62C8
#define pinstCSidlManager_x                                        0x16A515C
#define pinstCXWndManager_x                                        0x16A5150
#define instDynamicZone_x                                          0xE6B4E0
#define pinstDZMember_x                                            0xE6B5F0
#define pinstDZTimerInfo_x                                         0xE6B5F4
#define pinstEQItemList_x                                          0xE63B90
#define pinstEQObjectList_x                                        0xE64D80
#define instEQMisc_x                                               0xDB2FB8
#define pinstEQSoundManager_x                                      0xDB4BA8
#define pinstEQSpellStrings_x                                      0xC7FA30
#define instExpeditionLeader_x                                     0xE6B52A
#define instExpeditionName_x                                       0xE6B56A
#define pinstGroup_x                                               0xE657A6
#define pinstImeManager_x                                          0x16A5154
#define pinstLocalPlayer_x                                         0xE652F8
#define pinstMercenaryData_x                                       0xF14D7C
#define pinstMercenaryStats_x                                      0x102C1CC
#define pinstMercAltAbilities_x                                    0xDB4918
#define pinstModelPlayer_x                                         0xE65310
#define pinstPCData_x                                              0xE65778
#define pinstRealEstateItems_x                                     0xF16260
#define pinstSkillMgr_x                                            0xF16330
#define pinstSpawnManager_x                                        0xF15920
#define pinstSpellManager_x                                        0xF16508
#define pinstSpellSets_x                                           0xF0C744
#define pinstStringTable_x                                         0xE650AC
#define pinstSwitchManager_x                                       0xE64F40
#define pinstTarget_x                                              0xE6534C
#define pinstTargetObject_x                                        0xE65564
#define pinstTargetSwitch_x                                        0xE65784
#define pinstTaskMember_x                                          0xDB2E4C
#define pinstTrackTarget_x                                         0xE65358
#define pinstTradeTarget_x                                         0xE6530C
#define instTributeActive_x                                        0xDB2FDD
#define pinstViewActor_x                                           0xDB3194
#define pinstWorldData_x                                           0xE6577C
#define pinstZoneAddr_x                                            0xE75310
#define pinstPlayerPath_x                                          0xF159B8
#define pinstTargetIndicator_x                                     0xF16770
#define pinstCTargetManager_x                                      0xF16808
#define EQObject_Top_x                                             0xE652F4

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDB3998
#define pinstCAchievementsWnd_x                                    0xDB31F0
#define pinstCActionsWnd_x                                         0xDB3150
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDB3954
#define pinstCAdvancedLootWnd_x                                    0xDB3484
#define pinstCAdventureLeaderboardWnd_x                            0x1022E98
#define pinstCAdventureRequestWnd_x                                0x1022F48
#define pinstCAdventureStatsWnd_x                                  0x1022FF8
#define pinstCAggroMeterWnd_x                                      0xDB31E0
#define pinstCAlarmWnd_x                                           0xDB316C
#define pinstCAlertHistoryWnd_x                                    0xDB31B4
#define pinstCAlertStackWnd_x                                      0xDB3130
#define pinstCAlertWnd_x                                           0xDB313C
#define pinstCAltStorageWnd_x                                      0x1023358
#define pinstCAudioTriggersWindow_x                                0xC71D88
#define pinstCAuraWnd_x                                            0xDB31DC
#define pinstCAvaZoneWnd_x                                         0xDB31BC
#define pinstCBandolierWnd_x                                       0xDB3220
#define pinstCBankWnd_x                                            0xDB34A8
#define pinstCBarterMerchantWnd_x                                  0x1024598
#define pinstCBarterSearchWnd_x                                    0x1024648
#define pinstCBarterWnd_x                                          0x10246F8
#define pinstCBazaarConfirmationWnd_x                              0xDB3128
#define pinstCBazaarSearchWnd_x                                    0xDB3164
#define pinstCBazaarWnd_x                                          0xDB321C
#define pinstCBlockedBuffWnd_x                                     0xDB3488
#define pinstCBlockedPetBuffWnd_x                                  0x539EC4
#define pinstCBodyTintWnd_x                                        0xDB39A0
#define pinstCBookWnd_x                                            0xDB3244
#define pinstCBreathWnd_x                                          0xDB39A8
#define pinstCBuffWindowNORMAL_x                                   0xDB3464
#define pinstCBuffWindowSHORT_x                                    0xDB3468
#define pinstCBugReportWnd_x                                       0xDB3994
#define pinstCButtonWnd_x                                          0x16A5380
#define pinstCCastingWnd_x                                         0xDB398C
#define pinstCCastSpellWnd_x                                       0xDB3170
//#define pinstCCharacterCreationWnd_x                             0xDAAE5C
#define pinstCCharacterListWnd_x                                   0xDB39AC
#define pinstCChatWindowManager_x                                  0x10251B8
#define pinstCClaimWnd_x                                           0x1025310
#define pinstCColorPickerWnd_x                                     0xDB312C
#define pinstCCombatAbilityWnd_x                                   0xDB31EC
#define pinstCCombatSkillsSelectWnd_x                              0xDB3148
#define pinstCCompassWnd_x                                         0xDB3988
#define pinstCConfirmationDialog_x                                 0x102A210
#define pinstCContainerMgr_x                                       0xDB3204
#define pinstCContextMenuManager_x                                 0x16A5110
#define pinstCCursorAttachment_x                                   0xDB3960
#define pinstCDistillerInfo_x                                      0x1028C1C
#define pinstCDynamicZoneWnd_x                                     0x10258D8
#define pinstCEditLabelWnd_x                                       0xDB3254
#define pinstCEQMainWnd_x                                          0x1025B20
#define pinstCEventCalendarWnd_x                                   0xDB3250
#define pinstCExtendedTargetWnd_x                                  0xDB31CC
#define pinstCFacePick_x                                           0xDB3124
#define pinstCFellowshipWnd_x                                      0x1025D20
#define pinstCFileSelectionWnd_x                                   0xDB3474
#define pinstCFindItemWnd_x                                        0xDB3230
#define pinstCFindLocationWnd_x                                    0x1025E78
#define pinstCFriendsWnd_x                                         0xDB3160
#define pinstCGemsGameWnd_x                                        0xDB3140
#define pinstCGiveWnd_x                                            0xDB3240
#define pinstCGroupSearchFiltersWnd_x                              0xDB31FC
#define pinstCGroupSearchWnd_x                                     0x1026270
#define pinstCGroupWnd_x                                           0x1026320
#define pinstCGuildBankWnd_x                                       0xE76154
#define pinstCGuildCreationWnd_x                                   0x1026480
#define pinstCGuildMgmtWnd_x                                       0x1026530
#define pinstCharacterCreation_x                                   0xDB31E8
#define pinstCHelpWnd_x                                            0xDB3184
#define pinstCHeritageSelectionWnd_x                               0xDB3138
#define pinstCHotButtonWnd_x                                       0x1028688
#define pinstCHotButtonWnd1_x                                      0x1028688
#define pinstCHotButtonWnd2_x                                      0x102868C
#define pinstCHotButtonWnd3_x                                      0x1028690
#define pinstCHotButtonWnd4_x                                      0x1028694
#define pinstCIconSelectionWnd_x                                   0xDB3538
#define pinstCInspectWnd_x                                         0xDB34C4
#define pinstCInventoryWnd_x                                       0xDB3224
#define pinstCInvSlotMgr_x                                         0xDB31B8
#define pinstCItemDisplayManager_x                                 0x1028C18
#define pinstCItemExpTransferWnd_x                                 0x1028D48
#define pinstCItemOverflowWnd_x                                    0xDB3168
#define pinstCJournalCatWnd_x                                      0xDB34A0
//#define pinstCJournalNPCWnd_x                                    0xDAB354
#define pinstCJournalTextWnd_x                                     0xDB3248
#define pinstCKeyRingWnd_x                                         0xDB347C
#define pinstCLargeDialogWnd_x                                     0x102AE90
#define pinstCLayoutCopyWnd_x                                      0x1029098
#define pinstCLFGuildWnd_x                                         0x1029148
#define pinstCLoadskinWnd_x                                        0xDB314C
#define pinstCLootFiltersCopyWnd_x                                 0xC82F10
#define pinstCLootFiltersWnd_x                                     0xDB315C
#define pinstCLootSettingsWnd_x                                    0xDB3174
#define pinstCLootWnd_x                                            0xDB311C
#define pinstCMailAddressBookWnd_x                                 0xDB34CC
#define pinstCMailCompositionWnd_x                                 0xDB349C
#define pinstCMailIgnoreListWnd_x                                  0xDB3534
#define pinstCMailWnd_x                                            0xDB3470
#define pinstCManageLootWnd_x                                      0xDB47C0
#define pinstCMapToolbarWnd_x                                      0xDB3228
#define pinstCMapViewWnd_x                                         0xDB3208
#define pinstCMarketplaceWnd_x                                     0xDB3460
#define pinstCMerchantWnd_x                                        0xDB3144
#define pinstCMIZoneSelectWnd_x                                    0x1029980
#define pinstCMusicPlayerWnd_x                                     0xDB3478
#define pinstCNameChangeMercWnd_x                                  0xDB39A4
#define pinstCNameChangePetWnd_x                                   0xDB3980
#define pinstCNameChangeWnd_x                                      0xDB3234
#define pinstCNoteWnd_x                                            0xDB3180
#define pinstCObjectPreviewWnd_x                                   0xDB3494
#define pinstCOptionsWnd_x                                         0xDB322C
#define pinstCPetInfoWnd_x                                         0xDB3498
#define pinstCPetitionQWnd_x                                       0xDB34AC
//#define pinstCPlayerCustomizationWnd_x                             0xDAADC4
#define pinstCPlayerNotesWnd_x                                     0xDB399C
#define pinstCPlayerWnd_x                                          0xDB3158
#define pinstCPopupWndManager_x                                    0x102A210
#define pinstCProgressionSelectionWnd_x                            0x102A2C0
#define pinstCPurchaseGroupWnd_x                                   0xDB3940
#define pinstCPurchaseWnd_x                                        0xDB34A4
#define pinstCPvPLeaderboardWnd_x                                  0x102A370
#define pinstCPvPStatsWnd_x                                        0x102A420
#define pinstCQuantityWnd_x                                        0xDB394C
#define pinstCRaceChangeWnd_x                                      0xDB346C
#define pinstCRaidOptionsWnd_x                                     0xDB3200
#define pinstCRaidWnd_x                                            0xDB3950
#define pinstCRealEstateItemsWnd_x                                 0xDB320C
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDB324C
#define pinstCRealEstateManageWnd_x                                0xDB3178
#define pinstCRealEstateNeighborhoodWnd_x                          0xDB3188
#define pinstCRealEstatePlotSearchWnd_x                            0xDB31C0
#define pinstCRealEstatePurchaseWnd_x                              0xDB31D4
#define pinstCRespawnWnd_x                                         0xDB31F8
//#define pinstCRewardSelectionWnd_x                               0x1022600
#define pinstCSelectorWnd_x                                        0xDB31D0
#define pinstCSendMoneyWnd_x                                       0xDB325C
#define pinstCServerListWnd_x                                      0xDB31B0
#define pinstCSkillsSelectWnd_x                                    0xDB3134
#define pinstCSkillsWnd_x                                          0xDB3118
#define pinstCSocialEditWnd_x                                      0xDB3958
#define pinstCSocialWnd_x                                          0xDB3120
#define pinstCSpellBookWnd_x                                       0xDB31C8
#define pinstCStoryWnd_x                                           0xDB395C
#define pinstCTargetOfTargetWnd_x                                  0x102C250
#define pinstCTargetWnd_x                                          0xDB3490
#define pinstCTaskOverlayWnd_x                                     0xDB31C4
#define pinstCTaskSelectWnd_x                                      0x102C3A8
#define pinstCTaskSomething_x                                      0xC83710
#define pinstCTaskTemplateSelectWnd_x                              0x102C458
#define pinstCTaskWnd_x                                            0x102C508
#define pinstCTextEntryWnd_x                                       0xDB3990
#define pinstCTextOverlay_x                                        0xC72098
#define pinstCTimeLeftWnd_x                                        0xDB3480
#define pinstCTipWndCONTEXT_x                                      0x102C70C
#define pinstCTipWndOFDAY_x                                        0x102C708
#define pinstCTitleWnd_x                                           0x102C7B8
#define pinstCTrackingWnd_x                                        0xDB348C
#define pinstCTradeskillWnd_x                                      0x102C920
#define pinstCTradeWnd_x                                           0xDB3190
#define pinstCTrainWnd_x                                           0xDB3944
#define pinstCTributeBenefitWnd_x                                  0x102CB20
#define pinstCTributeMasterWnd_x                                   0x102CBD0
#define pinstCTributeTrophyWnd_x                                   0x102CC80
#define pinstCVideoModesWnd_x                                      0xDB31F4
#define pinstCVoiceMacroWnd_x                                      0xF16D38
#define pinstCVoteResultsWnd_x                                     0xDB3948
#define pinstCVoteWnd_x                                            0xDB34B0
#define pinstCWebManager_x                                         0xF16E9C
#define pinstCZoneGuideWnd_x                                       0xDB317C
#define pinstCZonePathWnd_x                                        0xDB318C

#define pinstEQSuiteTextureLoader_x                                0xC5CBD8
#define pinstItemIconCache_x                                       0x1025AD8
#define pinstLootFiltersManager_x                                  0xC82FC0
#define pinstRewardSelectionWnd_x                                  0x102AB68

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC0D5F4
#define __CastRay_x                                                0x592E60
#define __CastRay2_x                                               0x592EB0
#define __ConvertItemTags_x                                        0x5ADA60
#define __CrashHandler_x                                           0x844E50
#define __EQGetTime_x                                              0x8E3970
#define __ExecuteCmd_x                                             0x58B790
#define __FixHeading_x                                             0x974280
#define __get_bearing_x                                            0x5929B0
#define __get_melee_range_x                                        0x5930A0
#define __GetAnimationCache_x                                      0x702360
#define __GetGaugeValueFromEQ_x                                    0x7F64E0
#define __GetLabelFromEQ_x                                         0x7F7C50
#define __GetXTargetType_x                                         0x975CE0
#define __HeadingDiff_x                                            0x9742F0
#define __HelpPath_x                                               0xF141EC
#define __LoadFrontEnd_x                                           0x69A920
#define __NewUIINI_x                                               0x7F61B0
#define __pCrashHandler_x                                          0x104A070
#define __ProcessGameEvents_x                                      0x5F0650
#define __ProcessMouseEvent_x                                      0x5EFE10
#define __SaveColors_x                                             0x53CA40
#define __STMLToText_x                                             0x9175D0
#define __ToggleKeyRingItem_x                                      0x4FFCE0
#define CrashDetected_x                                            0x69C410
#define DrawNetStatus_x                                            0x61C6B0
#define Expansion_HoT_x                                            0xE7615C
#define Teleport_Table_Size_x                                      0xE652B4
#define Teleport_Table_x                                           0xE659A0
#define Util__FastTime_x                                           0x8E3530
#define wwsCrashReportCheckForUploader_x                           0x8459B0
#define wwsCrashReportPlatformLaunchUploader_x                     0x848090
#define __HandleMouseWheel_x                                       0x69EB70

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48B360
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4941F0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x493FB0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x544340
#define AltAdvManager__IsAbilityReady_x                            0x5433C0
#define AltAdvManager__GetAAById_x                                 0x5435C0
#define AltAdvManager__CanTrainAbility_x                           0x543630
#define AltAdvManager__CanSeeAbility_x                             0x543860

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C74A0
#define CharacterZoneClient__HasSkill_x                            0x4D2160
#define CharacterZoneClient__MakeMeVisible_x                       0x4D3880
#define CharacterZoneClient__IsStackBlocked_x                      0x4BB8E0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B8060
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D6220
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D6300
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D63E0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C03C0
#define CharacterZoneClient__BardCastBard_x                        0x4C3030
#define CharacterZoneClient__GetMaxEffects_x                       0x4B8130
#define CharacterZoneClient__GetEffect_x                           0x4B7FA0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C13C0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C1490
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C14E0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C1630
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C1800

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6C48E0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6D2480

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5FEE30
#define CButtonWnd__CButtonWnd_x                                   0x9139C0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6F0D90
#define CChatManager__InitContextMenu_x                            0x6EAE30
#define CChatManager__FreeChatWindow_x                             0x6EFCA0
#define CChatManager__GetLockedActiveChatWindow_x                  0x6F4630
#define CChatManager__SetLockedActiveChatWindow_x                  0x6F0B30

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x928220
#define CContextMenu__dCContextMenu_x                              0x928450
#define CContextMenu__AddMenuItem_x                                0x928460
#define CContextMenu__RemoveMenuItem_x                             0x928770
#define CContextMenu__RemoveAllMenuItems_x                         0x928790
#define CContextMenu__CheckMenuItem_x                              0x928810
#define CContextMenu__SetMenuItem_x                                0x928690
#define CContextMenu__AddSeparator_x                               0x9285F0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x928DB0
#define CContextMenuManager__RemoveMenu_x                          0x928E20
#define CContextMenuManager__PopupMenu_x                           0x928EE0
#define CContextMenuManager__Flush_x                               0x928D50
#define CContextMenuManager__GetMenu_x                             0x496410

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8C4350
#define CChatService__GetFriendName_x                              0x8C4360

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6F1300
#define CChatWindow__Clear_x                                       0x6F2350
#define CChatWindow__WndNotification_x                             0x6F28B0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x9256B0
#define CComboWnd__Draw_x                                          0x924BA0
#define CComboWnd__GetCurChoice_x                                  0x9254F0
#define CComboWnd__GetListRect_x                                   0x925060
#define CComboWnd__GetTextRect_x                                   0x925720
#define CComboWnd__InsertChoice_x                                  0x9251F0
#define CComboWnd__SetColors_x                                     0x9251C0
#define CComboWnd__SetChoice_x                                     0x9254C0
#define CComboWnd__GetItemCount_x                                  0x925500
#define CComboWnd__GetCurChoiceText_x                              0x925540

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6FA550
#define CContainerWnd__vftable_x                                   0xAD3160
#define CContainerWnd__SetContainer_x                              0x6FBAC0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x53C800
#define CDisplay__GetClickedActor_x                                0x52F7B0
#define CDisplay__GetUserDefinedColor_x                            0x527E90
#define CDisplay__GetWorldFilePath_x                               0x531200
#define CDisplay__is3dON_x                                         0x52C480
#define CDisplay__ReloadUI_x                                       0x536920
#define CDisplay__WriteTextHD2_x                                   0x52C260
#define CDisplay__TrueDistance_x                                   0x532E60
#define CDisplay__SetViewActor_x                                   0x52F100
#define CDisplay__GetFloorHeight_x                                 0x52C540
#define CDisplay__SetRenderWindow_x                                0x52AE70
#define CDisplay__ToggleScreenshotMode_x                           0x52EBD0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x9478F0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x92C930
#define CEditWnd__GetCharIndexPt_x                                 0x92D830
#define CEditWnd__GetDisplayString_x                               0x92D6D0
#define CEditWnd__GetHorzOffset_x                                  0x92BF60
#define CEditWnd__GetLineForPrintableChar_x                        0x92E970
#define CEditWnd__GetSelStartPt_x                                  0x92DAE0
#define CEditWnd__GetSTMLSafeText_x                                0x92D4F0
#define CEditWnd__PointFromPrintableChar_x                         0x92E5A0
#define CEditWnd__SelectableCharFromPoint_x                        0x92E710
#define CEditWnd__SetEditable_x                                    0x92DBB0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5DE950
#define CEverQuest__ClickedPlayer_x                                0x5D0CF0
#define CEverQuest__CreateTargetIndicator_x                        0x5ED900
#define CEverQuest__DeleteTargetIndicator_x                        0x5ED990
#define CEverQuest__DoTellWindow_x                                 0x4E3330
#define CEverQuest__OutputTextToLog_x                              0x4E3560
#define CEverQuest__DropHeldItemOnGround_x                         0x5C65B0
#define CEverQuest__dsp_chat_x                                     0x4E38F0
#define CEverQuest__trimName_x                                     0x5E9E70
#define CEverQuest__Emote_x                                        0x5DF160
#define CEverQuest__EnterZone_x                                    0x5D9340
#define CEverQuest__GetBodyTypeDesc_x                              0x5E3710
#define CEverQuest__GetClassDesc_x                                 0x5E3D50
#define CEverQuest__GetClassThreeLetterCode_x                      0x5E4350
#define CEverQuest__GetDeityDesc_x                                 0x5EC250
#define CEverQuest__GetLangDesc_x                                  0x5E4510
#define CEverQuest__GetRaceDesc_x                                  0x5E3D30
#define CEverQuest__InterpretCmd_x                                 0x5EC820
#define CEverQuest__LeftClickedOnPlayer_x                          0x5CA7A0
#define CEverQuest__LMouseUp_x                                     0x5C8B20
#define CEverQuest__RightClickedOnPlayer_x                         0x5CB080
#define CEverQuest__RMouseUp_x                                     0x5C9AB0
#define CEverQuest__SetGameState_x                                 0x5C6340
#define CEverQuest__UPCNotificationFlush_x                         0x5E9D70
#define CEverQuest__IssuePetCommand_x                              0x5E5910
#define CEverQuest__ReportSuccessfulHit_x                          0x5E0560

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x70C400
#define CGaugeWnd__CalcLinesFillRect_x                             0x70C460
#define CGaugeWnd__Draw_x                                          0x70BAF0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ACB60
#define CGuild__GetGuildName_x                                     0x4ABC40
#define CGuild__GetGuildIndex_x                                    0x4ABFD0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x727780

//CHotButton
#define CHotButton__SetButtonSize_x                                0x5FF1F0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x734760
#define CInvSlotMgr__MoveItem_x                                    0x733480
#define CInvSlotMgr__SelectSlot_x                                  0x734830

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x731D30
#define CInvSlot__SliderComplete_x                                 0x72FAA0
#define CInvSlot__GetItemBase_x                                    0x72F410
#define CInvSlot__UpdateItem_x                                     0x72F580

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x736180
#define CInvSlotWnd__CInvSlotWnd_x                                 0x735450
#define CInvSlotWnd__HandleLButtonUp_x                             0x735D00

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7F26C0
#define CItemDisplayWnd__UpdateStrings_x                           0x744330
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x73E360
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x73E890
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x744940
#define CItemDisplayWnd__AboutToShow_x                             0x743F80
#define CItemDisplayWnd__WndNotification_x                         0x745E90

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x82A040

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x749F80

// CLabel 
#define CLabel__Draw_x                                             0x74FA00

// CListWnd
#define CListWnd__CListWnd_x                                       0x8FDDD0
#define CListWnd__dCListWnd_x                                      0x8FE0F0
#define CListWnd__AddColumn_x                                      0x902420
#define CListWnd__AddColumn1_x                                     0x902470
#define CListWnd__AddLine_x                                        0x902800
#define CListWnd__AddString_x                                      0x902600
#define CListWnd__CalculateFirstVisibleLine_x                      0x9021E0
#define CListWnd__CalculateVSBRange_x                              0x901FD0
#define CListWnd__ClearSel_x                                       0x902FE0
#define CListWnd__ClearAllSel_x                                    0x903040
#define CListWnd__CloseAndUpdateEditWindow_x                       0x903A50
#define CListWnd__Compare_x                                        0x901910
#define CListWnd__Draw_x                                           0x8FE1F0
#define CListWnd__DrawColumnSeparators_x                           0x9009E0
#define CListWnd__DrawHeader_x                                     0x900E50
#define CListWnd__DrawItem_x                                       0x901250
#define CListWnd__DrawLine_x                                       0x900B50
#define CListWnd__DrawSeparator_x                                  0x900A80
#define CListWnd__EnableLine_x                                     0x9002B0
#define CListWnd__EnsureVisible_x                                  0x903970
#define CListWnd__ExtendSel_x                                      0x902F10
#define CListWnd__GetColumnMinWidth_x                              0x8FFDF0
#define CListWnd__GetColumnWidth_x                                 0x8FFD60
#define CListWnd__GetCurSel_x                                      0x8FF6F0
#define CListWnd__GetItemAtPoint_x                                 0x900530
#define CListWnd__GetItemAtPoint1_x                                0x9005A0
#define CListWnd__GetItemData_x                                    0x8FF770
#define CListWnd__GetItemHeight_x                                  0x8FFB30
#define CListWnd__GetItemIcon_x                                    0x8FF900
#define CListWnd__GetItemRect_x                                    0x9003A0
#define CListWnd__GetItemText_x                                    0x8FF7B0
#define CListWnd__GetSelList_x                                     0x903090
#define CListWnd__GetSeparatorRect_x                               0x9007E0
#define CListWnd__InsertLine_x                                     0x902BF0
#define CListWnd__RemoveLine_x                                     0x902D40
#define CListWnd__SetColors_x                                      0x901FA0
#define CListWnd__SetColumnJustification_x                         0x901CD0
#define CListWnd__SetColumnWidth_x                                 0x901BF0
#define CListWnd__SetCurSel_x                                      0x902E50
#define CListWnd__SetItemColor_x                                   0x903620
#define CListWnd__SetItemData_x                                    0x9035E0
#define CListWnd__SetItemText_x                                    0x903210
#define CListWnd__ShiftColumnSeparator_x                           0x901D90
#define CListWnd__Sort_x                                           0x901A90
#define CListWnd__ToggleSel_x                                      0x902E80

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x765110
#define CMapViewWnd__GetWorldCoordinates_x                         0x763820
#define CMapViewWnd__HandleLButtonDown_x                           0x760880

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x788390
// CMerchantWnd__RequestBuyItem_x                             
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x788C70
// CMerchantWnd__RequestSellItem_x
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7891A0
#define CMerchantWnd__SelectRecoverySlot_x                         0x78BFD0
//CMerchantWnd__SelectBuySellSlot_x before
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x786D60
//CMerchantWnd__ActualSelect_x
#define CMerchantWnd__SelectBuySellSlot_x                          0x791BC0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x787FC0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8920B0
#define CPacketScrambler__hton_x                                   0x8920A0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x91CBC0
#define CSidlManager__FindScreenPieceTemplate_x                    0x91CFD0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x91CDC0
#define CSidlManager__CreateLabel_x                                0x7E9AB0
#define CSidlManager__CreateXWndFromTemplate_x                     0x9200A0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x920280
#define CSidlManager__CreateXWnd_x                                 0x7E99E0
#define CSidlManager__CreateHotButtonWnd_x                         0x7E9FA0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x919710
#define CSidlScreenWnd__CalculateVSBRange_x                        0x919610
#define CSidlScreenWnd__ConvertToRes_x                             0x93E740
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x9190B0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x918DA0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x918E70
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x918F40
#define CSidlScreenWnd__DrawSidlPiece_x                            0x919BB0
#define CSidlScreenWnd__EnableIniStorage_x                         0x91A080
#define CSidlScreenWnd__GetSidlPiece_x                             0x919DA0
#define CSidlScreenWnd__Init1_x                                    0x9189A0
#define CSidlScreenWnd__LoadIniInfo_x                              0x91A0D0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x91AC30
#define CSidlScreenWnd__LoadSidlScreen_x                           0x917DB0
#define CSidlScreenWnd__StoreIniInfo_x                             0x91A7A0
#define CSidlScreenWnd__StoreIniVis_x                              0x91AB10
#define CSidlScreenWnd__WndNotification_x                          0x919AC0
#define CSidlScreenWnd__GetChildItem_x                             0x91A000
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9098B0
#define CSidlScreenWnd__m_layoutCopy_x                             0x16A4FE0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x663920
#define CSkillMgr__GetSkillCap_x                                   0x663B00
#define CSkillMgr__GetNameToken_x                                  0x6630B0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x929BB0
#define CSliderWnd__SetValue_x                                     0x929A20
#define CSliderWnd__SetNumTicks_x                                  0x929A80

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7EF940

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x930820
#define CStmlWnd__CalculateHSBRange_x                              0x9318B0
#define CStmlWnd__CalculateVSBRange_x                              0x931820
#define CStmlWnd__CanBreakAtCharacter_x                            0x935BE0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x9367D0
#define CStmlWnd__ForceParseNow_x                                  0x930DC0
#define CStmlWnd__GetNextTagPiece_x                                0x935B40
#define CStmlWnd__GetSTMLText_x                                    0x4F18F0
#define CStmlWnd__GetVisibleText_x                                 0x930DE0
#define CStmlWnd__InitializeWindowVariables_x                      0x936620
#define CStmlWnd__MakeStmlColorTag_x                               0x92FFB0
#define CStmlWnd__MakeWndNotificationTag_x                         0x930020
#define CStmlWnd__SetSTMLText_x                                    0x92F080
#define CStmlWnd__StripFirstSTMLLines_x                            0x937930
#define CStmlWnd__UpdateHistoryString_x                            0x9369E0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x93B640
#define CTabWnd__DrawCurrentPage_x                                 0x93BC60
#define CTabWnd__DrawTab_x                                         0x93BA30
#define CTabWnd__GetCurrentPage_x                                  0x93AEA0
#define CTabWnd__GetPageInnerRect_x                                0x93B0E0
#define CTabWnd__GetTabInnerRect_x                                 0x93B020
#define CTabWnd__GetTabRect_x                                      0x93AED0
#define CTabWnd__InsertPage_x                                      0x93B2D0
#define CTabWnd__SetPage_x                                         0x93B160
#define CTabWnd__SetPageRect_x                                     0x93B580
#define CTabWnd__UpdatePage_x                                      0x93B8F0
#define CTabWnd__GetPageFromTabIndex_x                             0x93B970
#define CTabWnd__GetCurrentTabIndex_x                              0x93AE90

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x74A3E0
#define CPageWnd__SetTabText_x                                     0x947D00

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A66A0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x906720
#define CTextureFont__GetTextExtent_x                              0x9068E0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x697760
#define CHtmlComponentWnd__ValidateUri_x                           0x729170
#define CHtmlWnd__SetClientCallbacks_x                             0x6041E0
#define CHtmlWnd__AddObserver_x                                    0x604200
#define CHtmlWnd__RemoveObserver_x                                 0x604260
#define Window__getProgress_x                                      0x842AC0
#define Window__getStatus_x                                        0x842AE0
#define Window__getURI_x                                           0x842AF0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x944280

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8F3710

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4ADEC0
#define CXStr__CXStr1_x                                            0x9B5E50
#define CXStr__CXStr3_x                                            0x8DFA60
#define CXStr__dCXStr_x                                            0x472BB0
#define CXStr__operator_equal_x                                    0x8DFC90
#define CXStr__operator_equal1_x                                   0x8DFCD0
#define CXStr__operator_plus_equal1_x                              0x8E0760

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x927E30
#define CXWnd__BringToTop_x                                        0x90D020
#define CXWnd__Center_x                                            0x90CBA0
#define CXWnd__ClrFocus_x                                          0x90C9D0
#define CXWnd__Destroy_x                                           0x90CA80
#define CXWnd__DoAllDrawing_x                                      0x909070
#define CXWnd__DrawChildren_x                                      0x909040
#define CXWnd__DrawColoredRect_x                                   0x9094C0
#define CXWnd__DrawTooltip_x                                       0x907BB0
#define CXWnd__DrawTooltipAtPoint_x                                0x907C70
#define CXWnd__GetBorderFrame_x                                    0x909320
#define CXWnd__GetChildWndAt_x                                     0x90D0C0
#define CXWnd__GetClientClipRect_x                                 0x90B2F0
#define CXWnd__GetScreenClipRect_x                                 0x90B3A0
#define CXWnd__GetScreenRect_x                                     0x90B550
#define CXWnd__GetTooltipRect_x                                    0x909510
#define CXWnd__GetWindowTextA_x                                    0x497B90
#define CXWnd__IsActive_x                                          0x90FFB0
#define CXWnd__IsDescendantOf_x                                    0x90BF40
#define CXWnd__IsReallyVisible_x                                   0x90BF70
#define CXWnd__IsType_x                                            0x90D740
#define CXWnd__Move_x                                              0x90BFE0
#define CXWnd__Move1_x                                             0x90C090
#define CXWnd__ProcessTransition_x                                 0x90CB50
#define CXWnd__Refade_x                                            0x90C350
#define CXWnd__Resize_x                                            0x90C5E0
#define CXWnd__Right_x                                             0x90CDE0
#define CXWnd__SetFocus_x                                          0x90C990
#define CXWnd__SetFont_x                                           0x90CA00
#define CXWnd__SetKeyTooltip_x                                     0x90D550
#define CXWnd__SetMouseOver_x                                      0x90A470
#define CXWnd__StartFade_x                                         0x90BE10
#define CXWnd__GetChildItem_x                                      0x90D230
#define CXWnd__SetParent_x                                         0x90BCE0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x93F810

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x90FFF0
#define CXWndManager__DrawWindows_x                                0x910010
#define CXWndManager__GetKeyboardFlags_x                           0x9126A0
#define CXWndManager__HandleKeyboardMsg_x                          0x9122B0
#define CXWndManager__RemoveWnd_x                                  0x9128E0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x912E30

// CDBStr
#define CDBStr__GetString_x                                        0x526E40

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B9010
#define EQ_Character__Cur_HP_x                                     0x4CF1E0
#define EQ_Character__Cur_Mana_x                                   0x4D68E0
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BBF20
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AFAF0
#define EQ_Character__GetFocusRangeModifier_x                      0x4AFC40
#define EQ_Character__GetHPRegen_x                                 0x4DC840
#define EQ_Character__GetEnduranceRegen_x                          0x4DCE50
#define EQ_Character__GetManaRegen_x                               0x4DD290
#define EQ_Character__Max_Endurance_x                              0x629E30
#define EQ_Character__Max_HP_x                                     0x4CF010
#define EQ_Character__Max_Mana_x                                   0x629C30
#define EQ_Character__doCombatAbility_x                            0x62C300
#define EQ_Character__UseSkill_x                                   0x4DF0A0
#define EQ_Character__GetConLevel_x                                0x623440
#define EQ_Character__IsExpansionFlag_x                            0x589E60
#define EQ_Character__TotalEffect_x                                0x4C25B0
#define EQ_Character__GetPCSpellAffect_x                           0x4BCB10
#define EQ_Character__SpellDuration_x                              0x4BC640
#define EQ_Character__FindItemByRecord_x                           0x4D47F0
#define EQ_Character__GetAdjustedSkill_x                           0x4D1F20
#define EQ_Character__GetBaseSkill_x                               0x4D2EC0
#define EQ_Character__CanUseItem_x                                 0x4D6BF0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8B11C0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x640580

//PcClient
#define PcClient__PcClient_x                                       0x620D10

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6CB0
#define CCharacterListWnd__EnterWorld_x                            0x4B66F0
#define CCharacterListWnd__Quit_x                                  0x4B6400
#define CCharacterListWnd__UpdateList_x                            0x4B6880

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x605430
#define EQ_Item__CreateItemTagString_x                             0x88BA80
#define EQ_Item__IsStackable_x                                     0x890470
#define EQ_Item__GetImageNum_x                                     0x88D490
#define EQ_Item__CreateItemClient_x                                0x6045E0
#define EQ_Item__GetItemValue_x                                    0x88E710
#define EQ_Item__ValueSellMerchant_x                               0x891C40
#define EQ_Item__IsKeyRingItem_x                                   0x88FDC0
#define EQ_Item__CanGoInBag_x                                      0x605550
#define EQ_Item__GetMaxItemCount_x                                 0x88EAE0
#define EQ_Item__GetHeldItem_x                                     0x88D360
#define EQ_Item__GetAugmentFitBySlot_x                             0x88B3C0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x545020
#define EQ_LoadingS__Array_x                                       0xBE4C68

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x62A790
#define EQ_PC__GetAlternateAbilityId_x                             0x89AEF0
#define EQ_PC__GetCombatAbility_x                                  0x89B560
#define EQ_PC__GetCombatAbilityTimer_x                             0x89B5D0
#define EQ_PC__GetItemRecastTimer_x                                0x62C880
#define EQ_PC__HasLoreItem_x                                       0x623C10
#define EQ_PC__AlertInventoryChanged_x                             0x622F10
#define EQ_PC__GetPcZoneClient_x                                   0x64ED40
#define EQ_PC__RemoveMyAffect_x                                    0x62FA70
#define EQ_PC__GetKeyRingItems_x                                   0x89BE70
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x89BBF0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x89C160

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5903D0
#define EQItemList__add_object_x                                   0x5BBD60
#define EQItemList__add_item_x                                     0x5909E0
#define EQItemList__delete_item_x                                  0x590A30
#define EQItemList__FreeItemList_x                                 0x590930

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x524440

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x641E00
#define EQPlayer__dEQPlayer_x                                      0x6350E0
#define EQPlayer__DoAttack_x                                       0x649A20
#define EQPlayer__EQPlayer_x                                       0x635790
#define EQPlayer__SetNameSpriteState_x                             0x639E30
#define EQPlayer__SetNameSpriteTint_x                              0x63AD00
#define PlayerBase__HasProperty_j_x                                0x972660
#define EQPlayer__IsTargetable_x                                   0x972B00
#define EQPlayer__CanSee_x                                         0x972960
#define EQPlayer__CanSee1_x                                        0x972A30
#define PlayerBase__GetVisibilityLineSegment_x                     0x972720

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x64C7F0
#define PlayerZoneClient__GetLevel_x                               0x64ED80
#define PlayerZoneClient__IsValidTeleport_x                        0x5BCEC0
#define PlayerZoneClient__LegalPlayerRace_x                        0x53E5E0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x644B50
#define EQPlayerManager__GetSpawnByName_x                          0x644B70
#define EQPlayerManager__GetPlayerFromPartialName_x                0x644C00

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x608CC0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x608D00
#define KeypressHandler__ClearCommandStateArray_x                  0x60A0F0
#define KeypressHandler__HandleKeyDown_x                           0x60A110
#define KeypressHandler__HandleKeyUp_x                             0x60A1B0
#define KeypressHandler__SaveKeymapping_x                          0x60A590

// MapViewMap 
#define MapViewMap__Clear_x                                        0x760FA0
#define MapViewMap__SaveEx_x                                       0x764340
#define MapViewMap__SetZoom_x                                      0x768A10

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8AF0B0

// StringTable 
#define StringTable__getString_x                                   0x8AA080

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x62F6E0
#define PcZoneClient__RemovePetEffect_x                            0x62FD10
#define PcZoneClient__HasAlternateAbility_x                        0x629A70
#define PcZoneClient__GetCurrentMod_x                              0x4E21A0
#define PcZoneClient__GetModCap_x                                  0x4E20A0
#define PcZoneClient__CanEquipItem_x                               0x62A120
#define PcZoneClient__GetItemByID_x                                0x62CCF0
#define PcZoneClient__GetItemByItemClass_x                         0x62CE40
#define PcZoneClient__RemoveBuffEffect_x                           0x62FD30
#define PcZoneClient__BandolierSwap_x                              0x62AD50

//Doors
#define EQSwitch__UseSwitch_x                                      0x5C1AA0

//IconCache
#define IconCache__GetIcon_x                                       0x701BF0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6F96E0
#define CContainerMgr__CloseContainer_x                            0x6F99B0
#define CContainerMgr__OpenExperimentContainer_x                   0x6FA430

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7BC180

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5FD620

//CLootWnd
#define CLootWnd__LootAll_x                                        0x7573B0
#define CLootWnd__RequestLootSlot_x                                0x756760

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x55D480
#define EQ_Spell__SpellAffects_x                                   0x55D8F0
#define EQ_Spell__SpellAffectBase_x                                0x55D6B0
#define EQ_Spell__IsStackable_x                                    0x4C6DC0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C6C40
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B4040
#define EQ_Spell__IsSPAStacking_x                                  0x55E720
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x55DC40
#define EQ_Spell__IsNoRemove_x                                     0x4C6DA0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x55E730
#define __IsResEffectSpell_x                                       0x4C6110

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AA870

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8B9700

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x801A60
#define CTargetWnd__WndNotification_x                              0x8012F0
#define CTargetWnd__RefreshTargetBuffs_x                           0x8015C0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x800450

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x806130

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x558A10
#define EqSoundManager__PlayScriptMp3_x                            0x558B70
#define EqSoundManager__SoundAssistPlay_x                          0x6678A0
#define EqSoundManager__WaveInstancePlay_x                         0x666E10

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x515D60

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x92B590

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x54CDA0
#define CAltAbilityData__GetMercMaxRank_x                          0x54CD40
#define CAltAbilityData__GetMaxRank_x                              0x542270

//CTargetRing
#define CTargetRing__Cast_x                                        0x5FB730

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C6C20
#define CharacterBase__CreateItemGlobalIndex_x                     0x4FC120
#define CharacterBase__CreateItemIndex_x                           0x6037F0
#define CharacterBase__GetItemPossession_x                         0x4B3EF0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8C1DA0
#define CharacterBase__GetEffectId_x                               0x4C6BD0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6E18D0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6E20F0

//messages
#define msg_spell_worn_off_x                                       0x581D60
#define msg_new_text_x                                             0x576C20
#define __msgTokenTextParam_x                                      0x5843B0
#define msgTokenText_x                                             0x584600

//SpellManager
#define SpellManager__vftable_x                                    0xAAD8B8
#define SpellManager__SpellManager_x                               0x66ABD0
#define Spellmanager__LoadTextSpells_x                             0x66B4A0
#define SpellManager__GetSpellByGroupAndRank_x                     0x66ADA0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9765D0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4FC7D0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x588430
#define ItemGlobalIndex__IsEquippedLocation_x                      0x61C510
#define ItemGlobalIndex__IsValidIndex_x                            0x4FC830

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8BA040
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8BA2C0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x74FD50

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6FDE40
#define CCursorAttachment__Deactivate_x                            0x6FEE20

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x93DC50
#define CEQSuiteTextureLoader__GetTexture_x                        0x93D910

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4F97D0

//IString
#define IString__Append_x                                          0x4EB8A0

//Camera
#define CDisplay__cameraType_x                                     0xDB3258
#define EverQuest__Cameras_x                                       0xE76498

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x501F70
#define LootFiltersManager__GetItemFilterData_x                    0x501860
#define LootFiltersManager__RemoveItemLootFilter_x                 0x501890
#define LootFiltersManager__SetItemLootFilter_x                    0x501AB0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7AA190

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x97C400
#define CResolutionHandler__GetWindowedStyle_x                     0x6622E0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6F64A0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8CC840

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x716560
#define CGroupWnd__UpdateDisplay_x                                 0x7158D0

//ItemBase
#define ItemBase__IsLore_x                                         0x88FE20
#define ItemBase__IsLoreEquipped_x                                 0x88FE90

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
