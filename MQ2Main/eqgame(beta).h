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
#define __ExpectedVersionDate                                     "Nov 14 2018"
#define __ExpectedVersionTime                                     "04:21:00"
#define __ActualVersionDate_x                                      0xAC9E24
#define __ActualVersionTime_x                                      0xAC9E18

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x60F280
#define __MemChecker1_x                                            0x8E4090
#define __MemChecker2_x                                            0x69E740
#define __MemChecker3_x                                            0x69E690
#define __MemChecker4_x                                            0x83B260
#define __EncryptPad0_x                                            0xBFCE78
#define __EncryptPad1_x                                            0xC5B108
#define __EncryptPad2_x                                            0xC0DA00
#define __EncryptPad3_x                                            0xC0D600
#define __EncryptPad4_x                                            0xC4B978
#define __EncryptPad5_x                                            0xF170B4
#define __AC1_x                                                    0x7F7A86
#define __AC2_x                                                    0x5CA23F
#define __AC3_x                                                    0x5D10CF
#define __AC4_x                                                    0x5D4EF0
#define __AC5_x                                                    0x5DB0AF
#define __AC6_x                                                    0x5DF5E6
#define __AC7_x                                                    0x5C9CB0
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
#define __do_loot_x                                                0x597BC0
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
#define __gfMaxZoomCameraDistance_x                                0xABF2E0
#define __gfMaxCameraDistance_x                                    0xAEC7D4
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
#define pinstCamActor_x                                            0xDB3194
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
#define pinstViewActor_x                                           0xDB3190
#define pinstWorldData_x                                           0xE6577C
#define pinstZoneAddr_x                                            0xE75310
#define pinstPlayerPath_x                                          0xF159B8
#define pinstTargetIndicator_x                                     0xF16770
#define pinstCTargetManager_x                                      0xF16808
#define EQObject_Top_x                                             0xE652F4

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDB3994
#define pinstCAchievementsWnd_x                                    0xDB31EC
#define pinstCActionsWnd_x                                         0xDB314C
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDB3950
#define pinstCAdvancedLootWnd_x                                    0xDB3480
#define pinstCAdventureLeaderboardWnd_x                            0x1022E98
#define pinstCAdventureRequestWnd_x                                0x1022F48
#define pinstCAdventureStatsWnd_x                                  0x1022FF8
#define pinstCAggroMeterWnd_x                                      0xDB31DC
#define pinstCAlarmWnd_x                                           0xDB3168
#define pinstCAlertHistoryWnd_x                                    0xDB31B0
#define pinstCAlertStackWnd_x                                      0xDB312C
#define pinstCAlertWnd_x                                           0xDB3138
#define pinstCAltStorageWnd_x                                      0x1023358
#define pinstCAudioTriggersWindow_x                                0xC71D88
#define pinstCAuraWnd_x                                            0xDB31D8
#define pinstCAvaZoneWnd_x                                         0xDB31B4
#define pinstCBandolierWnd_x                                       0xDB321C
#define pinstCBankWnd_x                                            0xDB34A4
#define pinstCBarterMerchantWnd_x                                  0x1024598
#define pinstCBarterSearchWnd_x                                    0x1024648
#define pinstCBarterWnd_x                                          0x10246F8
#define pinstCBazaarConfirmationWnd_x                              0xDB3124
#define pinstCBazaarSearchWnd_x                                    0xDB3160
#define pinstCBazaarWnd_x                                          0xDB3214
#define pinstCBlockedBuffWnd_x                                     0xDB3484
#define pinstCBlockedPetBuffWnd_x                                  0x5394C4
#define pinstCBodyTintWnd_x                                        0xDB399C
#define pinstCBookWnd_x                                            0xDB3240
#define pinstCBreathWnd_x                                          0xDB39A4
#define pinstCBuffWindowNORMAL_x                                   0xDB3460
#define pinstCBuffWindowSHORT_x                                    0xDB3464
#define pinstCBugReportWnd_x                                       0xDB3990
#define pinstCButtonWnd_x                                          0x16A5380
#define pinstCCastingWnd_x                                         0xDB3988
#define pinstCCastSpellWnd_x                                       0xDB316C
//#define pinstCCharacterCreationWnd_x                             0xDAAE5C
#define pinstCCharacterListWnd_x                                   0xDB39A8
#define pinstCChatWindowManager_x                                  0x10251B8
#define pinstCClaimWnd_x                                           0x1025310
#define pinstCColorPickerWnd_x                                     0xDB3128
#define pinstCCombatAbilityWnd_x                                   0xDB31E8
#define pinstCCombatSkillsSelectWnd_x                              0xDB3144
#define pinstCCompassWnd_x                                         0xDB3984
#define pinstCConfirmationDialog_x                                 0x102A210
#define pinstCContainerMgr_x                                       0xDB3208
#define pinstCContextMenuManager_x                                 0x16A5110
#define pinstCCursorAttachment_x                                   0xDB395C
#define pinstCDistillerInfo_x                                      0x1028C1C
#define pinstCDynamicZoneWnd_x                                     0x10258D8
#define pinstCEditLabelWnd_x                                       0xDB3250
#define pinstCEQMainWnd_x                                          0x1025B20
#define pinstCEventCalendarWnd_x                                   0xDB324C
#define pinstCExtendedTargetWnd_x                                  0xDB31C8
#define pinstCFacePick_x                                           0xDB3120
#define pinstCFellowshipWnd_x                                      0x1025D20
#define pinstCFileSelectionWnd_x                                   0xDB346C
#define pinstCFindItemWnd_x                                        0xDB322C
#define pinstCFindLocationWnd_x                                    0x1025E78
#define pinstCFriendsWnd_x                                         0xDB315C
#define pinstCGemsGameWnd_x                                        0xDB313C
#define pinstCGiveWnd_x                                            0xDB3238
#define pinstCGroupSearchFiltersWnd_x                              0xDB31F4
#define pinstCGroupSearchWnd_x                                     0x1026270
#define pinstCGroupWnd_x                                           0x1026320
#define pinstCGuildBankWnd_x                                       0xE76154
#define pinstCGuildCreationWnd_x                                   0x1026480
#define pinstCGuildMgmtWnd_x                                       0x1026530
#define pinstCharacterCreation_x                                   0xDB31E4
#define pinstCHelpWnd_x                                            0xDB3180
#define pinstCHeritageSelectionWnd_x                               0xDB3134
#define pinstCHotButtonWnd_x                                       0x1028688
#define pinstCHotButtonWnd1_x                                      0x1028688
#define pinstCHotButtonWnd2_x                                      0x102868C
#define pinstCHotButtonWnd3_x                                      0x1028690
#define pinstCHotButtonWnd4_x                                      0x1028694
#define pinstCIconSelectionWnd_x                                   0xDB352C
#define pinstCInspectWnd_x                                         0xDB34C0
#define pinstCInventoryWnd_x                                       0xDB3220
#define pinstCInvSlotMgr_x                                         0xDB31B8
#define pinstCItemDisplayManager_x                                 0x1028C18
#define pinstCItemExpTransferWnd_x                                 0x1028D48
#define pinstCItemOverflowWnd_x                                    0xDB3164
#define pinstCJournalCatWnd_x                                      0xDB3498
//#define pinstCJournalNPCWnd_x                                    0xDAB354
#define pinstCJournalTextWnd_x                                     0xDB3244
#define pinstCKeyRingWnd_x                                         0xDB3478
#define pinstCLargeDialogWnd_x                                     0x102AE90
#define pinstCLayoutCopyWnd_x                                      0x1029098
#define pinstCLFGuildWnd_x                                         0x1029148
#define pinstCLoadskinWnd_x                                        0xDB3148
#define pinstCLootFiltersCopyWnd_x                                 0xC82F10
#define pinstCLootFiltersWnd_x                                     0xDB3154
#define pinstCLootSettingsWnd_x                                    0xDB3170
#define pinstCLootWnd_x                                            0xDB3118
#define pinstCMailAddressBookWnd_x                                 0xDB3530
#define pinstCMailCompositionWnd_x                                 0xDB349C
#define pinstCMailIgnoreListWnd_x                                  0xDB3534
#define pinstCMailWnd_x                                            0xDB3470
#define pinstCManageLootWnd_x                                      0xDB47C0
#define pinstCMapToolbarWnd_x                                      0xDB3224
#define pinstCMapViewWnd_x                                         0xDB3200
#define pinstCMarketplaceWnd_x                                     0xDB325C
#define pinstCMerchantWnd_x                                        0xDB3140
#define pinstCMIZoneSelectWnd_x                                    0x1029980
#define pinstCMusicPlayerWnd_x                                     0xDB3474
#define pinstCNameChangeMercWnd_x                                  0xDB39A0
#define pinstCNameChangePetWnd_x                                   0xDB397C
#define pinstCNameChangeWnd_x                                      0xDB3230
#define pinstCNoteWnd_x                                            0xDB317C
#define pinstCObjectPreviewWnd_x                                   0xDB3490
#define pinstCOptionsWnd_x                                         0xDB3228
#define pinstCPetInfoWnd_x                                         0xDB3494
#define pinstCPetitionQWnd_x                                       0xDB34A8
//#define pinstCPlayerCustomizationWnd_x                             0xDAADC4
#define pinstCPlayerNotesWnd_x                                     0xDB3998
#define pinstCPlayerWnd_x                                          0xDB3158
#define pinstCPopupWndManager_x                                    0x102A210
#define pinstCProgressionSelectionWnd_x                            0x102A2C0
#define pinstCPurchaseGroupWnd_x                                   0xDB393C
#define pinstCPurchaseWnd_x                                        0xDB34A0
#define pinstCPvPLeaderboardWnd_x                                  0x102A370
#define pinstCPvPStatsWnd_x                                        0x102A420
#define pinstCQuantityWnd_x                                        0xDB3948
#define pinstCRaceChangeWnd_x                                      0xDB3468
#define pinstCRaidOptionsWnd_x                                     0xDB31FC
#define pinstCRaidWnd_x                                            0xDB394C
#define pinstCRealEstateItemsWnd_x                                 0xDB3204
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDB3248
#define pinstCRealEstateManageWnd_x                                0xDB3174
#define pinstCRealEstateNeighborhoodWnd_x                          0xDB3184
#define pinstCRealEstatePlotSearchWnd_x                            0xDB31BC
#define pinstCRealEstatePurchaseWnd_x                              0xDB31D0
#define pinstCRespawnWnd_x                                         0xDB31F0
//#define pinstCRewardSelectionWnd_x                               0x1022600
#define pinstCSelectorWnd_x                                        0xDB31CC
#define pinstCSendMoneyWnd_x                                       0xDB3254
#define pinstCServerListWnd_x                                      0xDB3198
#define pinstCSkillsSelectWnd_x                                    0xDB3130
#define pinstCSkillsWnd_x                                          0xDB39AC
#define pinstCSocialEditWnd_x                                      0xDB3954
#define pinstCSocialWnd_x                                          0xDB311C
#define pinstCSpellBookWnd_x                                       0xDB31C4
#define pinstCStoryWnd_x                                           0xDB3958
#define pinstCTargetOfTargetWnd_x                                  0x102C250
#define pinstCTargetWnd_x                                          0xDB348C
#define pinstCTaskOverlayWnd_x                                     0xDB31C0
#define pinstCTaskSelectWnd_x                                      0x102C3A8
#define pinstCTaskSomething_x                                      0xC83710
#define pinstCTaskTemplateSelectWnd_x                              0x102C458
#define pinstCTaskWnd_x                                            0x102C508
#define pinstCTextEntryWnd_x                                       0xDB398C
#define pinstCTextOverlay_x                                        0xC72098
#define pinstCTimeLeftWnd_x                                        0xDB347C
#define pinstCTipWndCONTEXT_x                                      0x102C70C
#define pinstCTipWndOFDAY_x                                        0x102C708
#define pinstCTitleWnd_x                                           0x102C7B8
#define pinstCTrackingWnd_x                                        0xDB3488
#define pinstCTradeskillWnd_x                                      0x102C920
#define pinstCTradeWnd_x                                           0xDB318C
#define pinstCTrainWnd_x                                           0xDB3940
#define pinstCTributeBenefitWnd_x                                  0x102CB20
#define pinstCTributeMasterWnd_x                                   0x102CBD0
#define pinstCTributeTrophyWnd_x                                   0x102CC80
#define pinstCVideoModesWnd_x                                      0xDB31F8
#define pinstCVoiceMacroWnd_x                                      0xF16D38
#define pinstCVoteResultsWnd_x                                     0xDB3944
#define pinstCVoteWnd_x                                            0xDB34AC
#define pinstCWebManager_x                                         0xF16E9C
#define pinstCZoneGuideWnd_x                                       0xDB3178
#define pinstCZonePathWnd_x                                        0xDB3188

#define pinstEQSuiteTextureLoader_x                                0xC5CBD8
#define pinstItemIconCache_x                                       0x1025AD8
#define pinstLootFiltersManager_x                                  0xC82FC0
#define pinstRewardSelectionWnd_x                                  0x102AB68

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC0D5F4
#define __CastRay_x                                                0x5930E0
#define __CastRay2_x                                               0x593130
#define __ConvertItemTags_x                                        0x5ADCE0
#define __CrashHandler_x                                           0x844BE0
#define __EQGetTime_x                                              0x8E3B80
#define __ExecuteCmd_x                                             0x58B9F0
#define __FixHeading_x                                             0x9748D0
#define __get_bearing_x                                            0x592C30
#define __get_melee_range_x                                        0x593320
#define __GetAnimationCache_x                                      0x7021E0
#define __GetGaugeValueFromEQ_x                                    0x7F62A0
#define __GetLabelFromEQ_x                                         0x7F7A10
#define __GetXTargetType_x                                         0x9763A0
#define __HeadingDiff_x                                            0x974940
#define __HelpPath_x                                               0xF141EC
#define __LoadFrontEnd_x                                           0x69A5A0
#define __NewUIINI_x                                               0x7F5F70
#define __pCrashHandler_x                                          0x104A070
#define __ProcessGameEvents_x                                      0x5F0810
#define __ProcessMouseEvent_x                                      0x5EFFD0
#define __SaveColors_x                                             0x53C040
#define __STMLToText_x                                             0x917940
#define __ToggleKeyRingItem_x                                      0x4FF370
#define CrashDetected_x                                            0x69C090
#define DrawNetStatus_x                                            0x61C890
#define Expansion_HoT_x                                            0xE7615C
#define Teleport_Table_Size_x                                      0xE652B4
#define Teleport_Table_x                                           0xE659A0
#define Util__FastTime_x                                           0x8E3740
#define wwsCrashReportCheckForUploader_x                           0x845A80
#define wwsCrashReportPlatformLaunchUploader_x                     0x848140
#define __HandleMouseWheel_x                                       0x69E7F0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48B2B0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x494120
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x493EE0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x543A30
#define AltAdvManager__IsAbilityReady_x                            0x542AB0
#define AltAdvManager__GetAAById_x                                 0x542CB0
#define AltAdvManager__CanTrainAbility_x                           0x542D20
#define AltAdvManager__CanSeeAbility_x                             0x542F50

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C6EF0
#define CharacterZoneClient__HasSkill_x                            0x4D1BB0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D32D0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BB310
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B7A90
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D5C80
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D5D60
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D5E40
#define CharacterZoneClient__FindAffectSlot_x                      0x4BFDF0
#define CharacterZoneClient__BardCastBard_x                        0x4C2A50
#define CharacterZoneClient__GetMaxEffects_x                       0x4B7B60
#define CharacterZoneClient__GetEffect_x                           0x4B79D0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C0DF0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C0EC0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C0F10
#define CharacterZoneClient__CalcAffectChange_x                    0x4C1060
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C1230

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6C46E0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6D20B0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5FEFE0
#define CButtonWnd__CButtonWnd_x                                   0x913D30

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6F0B90
#define CChatManager__InitContextMenu_x                            0x6EAC30
#define CChatManager__FreeChatWindow_x                             0x6EFAA0
#define CChatManager__GetLockedActiveChatWindow_x                  0x6F4450
#define CChatManager__SetLockedActiveChatWindow_x                  0x6F0930

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x928520
#define CContextMenu__dCContextMenu_x                              0x928750
#define CContextMenu__AddMenuItem_x                                0x928760
#define CContextMenu__RemoveMenuItem_x                             0x928A70
#define CContextMenu__RemoveAllMenuItems_x                         0x928A90
#define CContextMenu__CheckMenuItem_x                              0x928B10
#define CContextMenu__SetMenuItem_x                                0x928990
#define CContextMenu__AddSeparator_x                               0x9288F0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x9290B0
#define CContextMenuManager__RemoveMenu_x                          0x929120
#define CContextMenuManager__PopupMenu_x                           0x9291E0
#define CContextMenuManager__Flush_x                               0x929050
#define CContextMenuManager__GetMenu_x                             0x4963B0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8C4580
#define CChatService__GetFriendName_x                              0x8C4590

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6F1100
#define CChatWindow__Clear_x                                       0x6F2160
#define CChatWindow__WndNotification_x                             0x6F26D0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x9259A0
#define CComboWnd__Draw_x                                          0x924E80
#define CComboWnd__GetCurChoice_x                                  0x9257E0
#define CComboWnd__GetListRect_x                                   0x925340
#define CComboWnd__GetTextRect_x                                   0x925A10
#define CComboWnd__InsertChoice_x                                  0x9254D0
#define CComboWnd__SetColors_x                                     0x9254A0
#define CComboWnd__SetChoice_x                                     0x9257B0
#define CComboWnd__GetItemCount_x                                  0x9257F0
#define CComboWnd__GetCurChoiceText_x                              0x925830

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6FA3D0
#define CContainerWnd__vftable_x                                   0xAD31A8
#define CContainerWnd__SetContainer_x                              0x6FB940

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x53BE00
#define CDisplay__GetClickedActor_x                                0x52EDB0
#define CDisplay__GetUserDefinedColor_x                            0x527490
#define CDisplay__GetWorldFilePath_x                               0x530800
#define CDisplay__is3dON_x                                         0x52BA80
#define CDisplay__ReloadUI_x                                       0x535F20
#define CDisplay__WriteTextHD2_x                                   0x52B860
#define CDisplay__TrueDistance_x                                   0x532460
#define CDisplay__SetViewActor_x                                   0x52E700
#define CDisplay__GetFloorHeight_x                                 0x52BB40
#define CDisplay__SetRenderWindow_x                                0x52A470
#define CDisplay__ToggleScreenshotMode_x                           0x52E1D0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x947ED0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x92CC40
#define CEditWnd__GetCharIndexPt_x                                 0x92DB40
#define CEditWnd__GetDisplayString_x                               0x92D9E0
#define CEditWnd__GetHorzOffset_x                                  0x92C270
#define CEditWnd__GetLineForPrintableChar_x                        0x92EC80
#define CEditWnd__GetSelStartPt_x                                  0x92DDF0
#define CEditWnd__GetSTMLSafeText_x                                0x92D800
#define CEditWnd__PointFromPrintableChar_x                         0x92E8B0
#define CEditWnd__SelectableCharFromPoint_x                        0x92EA20
#define CEditWnd__SetEditable_x                                    0x92DEC0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5DEB10
#define CEverQuest__ClickedPlayer_x                                0x5D0EB0
#define CEverQuest__CreateTargetIndicator_x                        0x5EDAC0
#define CEverQuest__DeleteTargetIndicator_x                        0x5EDB50
#define CEverQuest__DoTellWindow_x                                 0x4E2EC0
#define CEverQuest__OutputTextToLog_x                              0x4E30F0
#define CEverQuest__DropHeldItemOnGround_x                         0x5C6770
#define CEverQuest__dsp_chat_x                                     0x4E3480
#define CEverQuest__trimName_x                                     0x5EA030
#define CEverQuest__Emote_x                                        0x5DF320
#define CEverQuest__EnterZone_x                                    0x5D9500
#define CEverQuest__GetBodyTypeDesc_x                              0x5E38D0
#define CEverQuest__GetClassDesc_x                                 0x5E3F10
#define CEverQuest__GetClassThreeLetterCode_x                      0x5E4510
#define CEverQuest__GetDeityDesc_x                                 0x5EC410
#define CEverQuest__GetLangDesc_x                                  0x5E46D0
#define CEverQuest__GetRaceDesc_x                                  0x5E3EF0
#define CEverQuest__InterpretCmd_x                                 0x5EC9E0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5CA960
#define CEverQuest__LMouseUp_x                                     0x5C8CE0
#define CEverQuest__RightClickedOnPlayer_x                         0x5CB240
#define CEverQuest__RMouseUp_x                                     0x5C9C70
#define CEverQuest__SetGameState_x                                 0x5C6500
#define CEverQuest__UPCNotificationFlush_x                         0x5E9F30
#define CEverQuest__IssuePetCommand_x                              0x5E5AD0
#define CEverQuest__ReportSuccessfulHit_x                          0x5E0720

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x70C2F0
#define CGaugeWnd__CalcLinesFillRect_x                             0x70C350
#define CGaugeWnd__Draw_x                                          0x70B9E0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AC970
#define CGuild__GetGuildName_x                                     0x4ABA50
#define CGuild__GetGuildIndex_x                                    0x4ABDE0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x727690

//CHotButton
#define CHotButton__SetButtonSize_x                                0x5FF3A0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x734630
#define CInvSlotMgr__MoveItem_x                                    0x733390
#define CInvSlotMgr__SelectSlot_x                                  0x734700

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x731C40
#define CInvSlot__SliderComplete_x                                 0x72F9A0
#define CInvSlot__GetItemBase_x                                    0x72F330
#define CInvSlot__UpdateItem_x                                     0x72F4A0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x736050
#define CInvSlotWnd__CInvSlotWnd_x                                 0x735320
#define CInvSlotWnd__HandleLButtonUp_x                             0x735BD0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7F2490
#define CItemDisplayWnd__UpdateStrings_x                           0x743FB0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x73E0E0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x73E5E0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x744590
#define CItemDisplayWnd__AboutToShow_x                             0x743C10
#define CItemDisplayWnd__WndNotification_x                         0x745AC0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x82A010

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x749BD0

// CLabel 
#define CLabel__Draw_x                                             0x74F660

// CListWnd
#define CListWnd__CListWnd_x                                       0x8FDFE0
#define CListWnd__dCListWnd_x                                      0x8FE310
#define CListWnd__AddColumn_x                                      0x902610
#define CListWnd__AddColumn1_x                                     0x902660
#define CListWnd__AddLine_x                                        0x9029F0
#define CListWnd__AddString_x                                      0x9027F0
#define CListWnd__CalculateFirstVisibleLine_x                      0x9023E0
#define CListWnd__CalculateVSBRange_x                              0x9021C0
#define CListWnd__ClearSel_x                                       0x9031D0
#define CListWnd__ClearAllSel_x                                    0x903230
#define CListWnd__CloseAndUpdateEditWindow_x                       0x903C20
#define CListWnd__Compare_x                                        0x901B00
#define CListWnd__Draw_x                                           0x8FE410
#define CListWnd__DrawColumnSeparators_x                           0x900BE0
#define CListWnd__DrawHeader_x                                     0x901040
#define CListWnd__DrawItem_x                                       0x901440
#define CListWnd__DrawLine_x                                       0x900D40
#define CListWnd__DrawSeparator_x                                  0x900C80
#define CListWnd__EnableLine_x                                     0x9004C0
#define CListWnd__EnsureVisible_x                                  0x903B50
#define CListWnd__ExtendSel_x                                      0x903100
#define CListWnd__GetColumnMinWidth_x                              0x900000
#define CListWnd__GetColumnWidth_x                                 0x8FFF70
#define CListWnd__GetCurSel_x                                      0x8FF900
#define CListWnd__GetItemAtPoint_x                                 0x900730
#define CListWnd__GetItemAtPoint1_x                                0x9007A0
#define CListWnd__GetItemData_x                                    0x8FF980
#define CListWnd__GetItemHeight_x                                  0x8FFD40
#define CListWnd__GetItemIcon_x                                    0x8FFB10
#define CListWnd__GetItemRect_x                                    0x9005B0
#define CListWnd__GetItemText_x                                    0x8FF9C0
#define CListWnd__GetSelList_x                                     0x903280
#define CListWnd__GetSeparatorRect_x                               0x9009E0
#define CListWnd__InsertLine_x                                     0x902DE0
#define CListWnd__RemoveLine_x                                     0x902F30
#define CListWnd__SetColors_x                                      0x902190
#define CListWnd__SetColumnJustification_x                         0x901EC0
#define CListWnd__SetColumnWidth_x                                 0x901DE0
#define CListWnd__SetCurSel_x                                      0x903040
#define CListWnd__SetItemColor_x                                   0x903810
#define CListWnd__SetItemData_x                                    0x9037D0
#define CListWnd__SetItemText_x                                    0x903400
#define CListWnd__ShiftColumnSeparator_x                           0x901F80
#define CListWnd__Sort_x                                           0x901C80
#define CListWnd__ToggleSel_x                                      0x903070

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x764B60
#define CMapViewWnd__GetWorldCoordinates_x                         0x763270
#define CMapViewWnd__HandleLButtonDown_x                           0x7602D0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x787EB0
// CMerchantWnd__RequestBuyItem_x                             
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x788790
// CMerchantWnd__RequestSellItem_x
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x788CC0
#define CMerchantWnd__SelectRecoverySlot_x                         0x78BAF0
//CMerchantWnd__SelectBuySellSlot_x before
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x786890
//CMerchantWnd__ActualSelect_x
#define CMerchantWnd__SelectBuySellSlot_x                          0x7916D0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x787AF0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x892230
#define CPacketScrambler__hton_x                                   0x892220

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x91CF40
#define CSidlManager__FindScreenPieceTemplate_x                    0x91D350
#define CSidlManager__FindScreenPieceTemplate1_x                   0x91D140
#define CSidlManager__CreateLabel_x                                0x7E9930
#define CSidlManager__CreateXWndFromTemplate_x                     0x920420
#define CSidlManager__CreateXWndFromTemplate1_x                    0x920600
#define CSidlManager__CreateXWnd_x                                 0x7E9860
#define CSidlManager__CreateHotButtonWnd_x                         0x7E9E30

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x919AA0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9199A0
#define CSidlScreenWnd__ConvertToRes_x                             0x93ED00
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x919430
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x919120
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x9191F0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x9192C0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x919F30
#define CSidlScreenWnd__EnableIniStorage_x                         0x91A400
#define CSidlScreenWnd__GetSidlPiece_x                             0x91A120
#define CSidlScreenWnd__Init1_x                                    0x918D30
#define CSidlScreenWnd__LoadIniInfo_x                              0x91A450
#define CSidlScreenWnd__LoadIniListWnd_x                           0x91AFB0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x918130
#define CSidlScreenWnd__StoreIniInfo_x                             0x91AB20
#define CSidlScreenWnd__StoreIniVis_x                              0x91AE90
#define CSidlScreenWnd__WndNotification_x                          0x919E40
#define CSidlScreenWnd__GetChildItem_x                             0x91A380
#define CSidlScreenWnd__HandleLButtonUp_x                          0x909AB0
#define CSidlScreenWnd__m_layoutCopy_x                             0x16A4FE0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6634E0
#define CSkillMgr__GetSkillCap_x                                   0x6636C0
#define CSkillMgr__GetNameToken_x                                  0x662C70

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x929EC0
#define CSliderWnd__SetValue_x                                     0x929D30
#define CSliderWnd__SetNumTicks_x                                  0x929D90

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7EF700

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x930B20
#define CStmlWnd__CalculateHSBRange_x                              0x931B80
#define CStmlWnd__CalculateVSBRange_x                              0x931AF0
#define CStmlWnd__CanBreakAtCharacter_x                            0x935EC0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x936AB0
#define CStmlWnd__ForceParseNow_x                                  0x9310C0
#define CStmlWnd__GetNextTagPiece_x                                0x935E20
#define CStmlWnd__GetSTMLText_x                                    0x4F13C0
#define CStmlWnd__GetVisibleText_x                                 0x9310E0
#define CStmlWnd__InitializeWindowVariables_x                      0x936900
#define CStmlWnd__MakeStmlColorTag_x                               0x9302B0
#define CStmlWnd__MakeWndNotificationTag_x                         0x930320
#define CStmlWnd__SetSTMLText_x                                    0x92F380
#define CStmlWnd__StripFirstSTMLLines_x                            0x937C00
#define CStmlWnd__UpdateHistoryString_x                            0x936CC0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x93B8E0
#define CTabWnd__DrawCurrentPage_x                                 0x93BF00
#define CTabWnd__DrawTab_x                                         0x93BCD0
#define CTabWnd__GetCurrentPage_x                                  0x93B140
#define CTabWnd__GetPageInnerRect_x                                0x93B380
#define CTabWnd__GetTabInnerRect_x                                 0x93B2C0
#define CTabWnd__GetTabRect_x                                      0x93B170
#define CTabWnd__InsertPage_x                                      0x93B570
#define CTabWnd__SetPage_x                                         0x93B400
#define CTabWnd__SetPageRect_x                                     0x93B820
#define CTabWnd__UpdatePage_x                                      0x93BB90
#define CTabWnd__GetPageFromTabIndex_x                             0x93BC10
#define CTabWnd__GetCurrentTabIndex_x                              0x93B130

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x74A030
#define CPageWnd__SetTabText_x                                     0x9482F0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A64A0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x9068D0
#define CTextureFont__GetTextExtent_x                              0x906A90

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6973F0
#define CHtmlComponentWnd__ValidateUri_x                           0x729080
#define CHtmlWnd__SetClientCallbacks_x                             0x604360
#define CHtmlWnd__AddObserver_x                                    0x604380
#define CHtmlWnd__RemoveObserver_x                                 0x6043E0
#define Window__getProgress_x                                      0x842850
#define Window__getStatus_x                                        0x842870
#define Window__getURI_x                                           0x842880

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x944860

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8F3750

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4ADCD0
#define CXStr__CXStr1_x                                            0x8FC240
#define CXStr__CXStr3_x                                            0x8DFC70
#define CXStr__dCXStr_x                                            0x472AB0
#define CXStr__operator_equal_x                                    0x8DFEA0
#define CXStr__operator_equal1_x                                   0x8DFEE0
#define CXStr__operator_plus_equal1_x                              0x8E0970

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x928130
#define CXWnd__BringToTop_x                                        0x90D270
#define CXWnd__Center_x                                            0x90CDF0
#define CXWnd__ClrFocus_x                                          0x90CC20
#define CXWnd__Destroy_x                                           0x90CCD0
#define CXWnd__DoAllDrawing_x                                      0x909240
#define CXWnd__DrawChildren_x                                      0x909210
#define CXWnd__DrawColoredRect_x                                   0x9096A0
#define CXWnd__DrawTooltip_x                                       0x907D60
#define CXWnd__DrawTooltipAtPoint_x                                0x907E20
#define CXWnd__GetBorderFrame_x                                    0x909500
#define CXWnd__GetChildWndAt_x                                     0x90D310
#define CXWnd__GetClientClipRect_x                                 0x90B520
#define CXWnd__GetScreenClipRect_x                                 0x90B5F0
#define CXWnd__GetScreenRect_x                                     0x90B7B0
#define CXWnd__GetTooltipRect_x                                    0x9096F0
#define CXWnd__GetWindowTextA_x                                    0x497B20
#define CXWnd__IsActive_x                                          0x910170
#define CXWnd__IsDescendantOf_x                                    0x90C1C0
#define CXWnd__IsReallyVisible_x                                   0x90C1F0
#define CXWnd__IsType_x                                            0x90D970
#define CXWnd__Move_x                                              0x90C260
#define CXWnd__Move1_x                                             0x90C320
#define CXWnd__ProcessTransition_x                                 0x90CDA0
#define CXWnd__Refade_x                                            0x90C5F0
#define CXWnd__Resize_x                                            0x90C880
#define CXWnd__Right_x                                             0x90D030
#define CXWnd__SetFocus_x                                          0x90CBE0
#define CXWnd__SetFont_x                                           0x90CC50
#define CXWnd__SetKeyTooltip_x                                     0x90D780
#define CXWnd__SetMouseOver_x                                      0x90A670
#define CXWnd__StartFade_x                                         0x90C090
#define CXWnd__GetChildItem_x                                      0x90D480
#define CXWnd__SetParent_x                                         0x90BF50

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x93FDD0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9101B0
#define CXWndManager__DrawWindows_x                                0x9101D0
#define CXWndManager__GetKeyboardFlags_x                           0x912950
#define CXWndManager__HandleKeyboardMsg_x                          0x912550
#define CXWndManager__RemoveWnd_x                                  0x912BA0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x9130F0

// CDBStr
#define CDBStr__GetString_x                                        0x526380

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B8A40
#define EQ_Character__Cur_HP_x                                     0x4CEC30
#define EQ_Character__Cur_Mana_x                                   0x4D6340
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BB950
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AF8D0
#define EQ_Character__GetFocusRangeModifier_x                      0x4AFA20
#define EQ_Character__GetHPRegen_x                                 0x4DC2A0
#define EQ_Character__GetEnduranceRegen_x                          0x4DC8B0
#define EQ_Character__GetManaRegen_x                               0x4DCCF0
#define EQ_Character__Max_Endurance_x                              0x62A2D0
#define EQ_Character__Max_HP_x                                     0x4CEA60
#define EQ_Character__Max_Mana_x                                   0x62A0D0
#define EQ_Character__doCombatAbility_x                            0x62C7A0
#define EQ_Character__UseSkill_x                                   0x4DEB00
#define EQ_Character__GetConLevel_x                                0x623590
#define EQ_Character__IsExpansionFlag_x                            0x58A050
#define EQ_Character__TotalEffect_x                                0x4C1FD0
#define EQ_Character__GetPCSpellAffect_x                           0x4BC540
#define EQ_Character__SpellDuration_x                              0x4BC070
#define EQ_Character__FindItemByRecord_x                           0x4D4240
#define EQ_Character__GetAdjustedSkill_x                           0x4D1970
#define EQ_Character__GetBaseSkill_x                               0x4D2910
#define EQ_Character__CanUseItem_x                                 0x4D6650

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8B13F0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x640650

//PcClient
#define PcClient__PcClient_x                                       0x620E60

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6810
#define CCharacterListWnd__EnterWorld_x                            0x4B6250
#define CCharacterListWnd__Quit_x                                  0x4B5F60
#define CCharacterListWnd__UpdateList_x                            0x4B63E0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6055B0
#define EQ_Item__CreateItemTagString_x                             0x88BC00
#define EQ_Item__IsStackable_x                                     0x8905E0
#define EQ_Item__GetImageNum_x                                     0x88D620
#define EQ_Item__CreateItemClient_x                                0x604760
#define EQ_Item__GetItemValue_x                                    0x88E860
#define EQ_Item__ValueSellMerchant_x                               0x891DC0
#define EQ_Item__IsKeyRingItem_x                                   0x88FF30
#define EQ_Item__CanGoInBag_x                                      0x6056D0
#define EQ_Item__GetMaxItemCount_x                                 0x88EC30
#define EQ_Item__GetHeldItem_x                                     0x88D4F0
#define EQ_Item__GetAugmentFitBySlot_x                             0x88B540

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x544750
#define EQ_LoadingS__Array_x                                       0xBE4C68

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x62AC30
#define EQ_PC__GetAlternateAbilityId_x                             0x89B000
#define EQ_PC__GetCombatAbility_x                                  0x89B670
#define EQ_PC__GetCombatAbilityTimer_x                             0x89B6E0
#define EQ_PC__GetItemRecastTimer_x                                0x62CD20
#define EQ_PC__HasLoreItem_x                                       0x623D60
#define EQ_PC__AlertInventoryChanged_x                             0x623060
#define EQ_PC__GetPcZoneClient_x                                   0x64EEA0
#define EQ_PC__RemoveMyAffect_x                                    0x62FF20
#define EQ_PC__GetKeyRingItems_x                                   0x89BF80
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x89BD00
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x89C270

// EQItemList 
#define EQItemList__EQItemList_x                                   0x590630
#define EQItemList__add_object_x                                   0x5BBF80
#define EQItemList__add_item_x                                     0x590C40
#define EQItemList__delete_item_x                                  0x590C90
#define EQItemList__FreeItemList_x                                 0x590B90

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x523990

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x641ED0
#define EQPlayer__dEQPlayer_x                                      0x6355E0
#define EQPlayer__DoAttack_x                                       0x649B80
#define EQPlayer__EQPlayer_x                                       0x635C90
#define EQPlayer__SetNameSpriteState_x                             0x639F00
#define EQPlayer__SetNameSpriteTint_x                              0x63ADD0
#define PlayerBase__HasProperty_j_x                                0x972C60
#define EQPlayer__IsTargetable_x                                   0x973100
#define EQPlayer__CanSee_x                                         0x972F60
#define EQPlayer__CanSee1_x                                        0x973030
#define PlayerBase__GetVisibilityLineSegment_x                     0x972D20

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x64C950
#define PlayerZoneClient__GetLevel_x                               0x64EEE0
#define PlayerZoneClient__IsValidTeleport_x                        0x5BD0D0
#define PlayerZoneClient__LegalPlayerRace_x                        0x53DBB0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x644C50
#define EQPlayerManager__GetSpawnByName_x                          0x644C70
#define EQPlayerManager__GetPlayerFromPartialName_x                0x644D00

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x608E80
#define KeypressHandler__AttachKeyToEqCommand_x                    0x608EC0
#define KeypressHandler__ClearCommandStateArray_x                  0x60A2B0
#define KeypressHandler__HandleKeyDown_x                           0x60A2D0
#define KeypressHandler__HandleKeyUp_x                             0x60A370
#define KeypressHandler__SaveKeymapping_x                          0x60A750

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7609F0
#define MapViewMap__SaveEx_x                                       0x763D90
#define MapViewMap__SetZoom_x                                      0x768460

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8AF2E0

// StringTable 
#define StringTable__getString_x                                   0x8AA260

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x62FB90
#define PcZoneClient__RemovePetEffect_x                            0x6301C0
#define PcZoneClient__HasAlternateAbility_x                        0x629F10
#define PcZoneClient__GetCurrentMod_x                              0x4E1C00
#define PcZoneClient__GetModCap_x                                  0x4E1B00
#define PcZoneClient__CanEquipItem_x                               0x62A5C0
#define PcZoneClient__GetItemByID_x                                0x62D1A0
#define PcZoneClient__GetItemByItemClass_x                         0x62D2F0
#define PcZoneClient__RemoveBuffEffect_x                           0x6301E0
#define PcZoneClient__BandolierSwap_x                              0x62B1F0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5C1C60

//IconCache
#define IconCache__GetIcon_x                                       0x701A70

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6F9570
#define CContainerMgr__CloseContainer_x                            0x6F9840
#define CContainerMgr__OpenExperimentContainer_x                   0x6FA2C0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7BBE80

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5FD7B0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x756E80
#define CLootWnd__RequestLootSlot_x                                0x756230

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x55CBA0
#define EQ_Spell__SpellAffects_x                                   0x55D010
#define EQ_Spell__SpellAffectBase_x                                0x55CDD0
#define EQ_Spell__IsStackable_x                                    0x4C67F0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C6670
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B3DE0
#define EQ_Spell__IsSPAStacking_x                                  0x55DE40
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x55D360
#define EQ_Spell__IsNoRemove_x                                     0x4C67D0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x55DE50
#define __IsResEffectSpell_x                                       0x4C5B10

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AA690

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8B9940

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x801810
#define CTargetWnd__WndNotification_x                              0x8010A0
#define CTargetWnd__RefreshTargetBuffs_x                           0x801370
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x8001F0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x805EE0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x558140
#define EqSoundManager__PlayScriptMp3_x                            0x5582A0
#define EqSoundManager__SoundAssistPlay_x                          0x6673F0
#define EqSoundManager__WaveInstancePlay_x                         0x666960

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x515360

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x92B8A0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x54C3C0
#define CAltAbilityData__GetMercMaxRank_x                          0x54C360
#define CAltAbilityData__GetMaxRank_x                              0x541960

//CTargetRing
#define CTargetRing__Cast_x                                        0x5FB8B0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C6650
#define CharacterBase__CreateItemGlobalIndex_x                     0x4FB820
#define CharacterBase__CreateItemIndex_x                           0x6039A0
#define CharacterBase__GetItemPossession_x                         0x4B3C90
#define CharacterBase__GetItemByGlobalIndex_x                      0x8C1FD0
#define CharacterBase__GetEffectId_x                               0x4C6600

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6E16D0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6E1EF0

//messages
#define msg_spell_worn_off_x                                       0x582120
#define msg_new_text_x                                             0x577020
#define __msgTokenTextParam_x                                      0x584760
#define msgTokenText_x                                             0x5849B0

//SpellManager
#define SpellManager__vftable_x                                    0xAAD8C0
#define SpellManager__SpellManager_x                               0x66A720
#define Spellmanager__LoadTextSpells_x                             0x66AFF0
#define SpellManager__GetSpellByGroupAndRank_x                     0x66A8F0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x976C90

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4FBF00
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5885B0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x58A030
#define ItemGlobalIndex__IsValidIndex_x                            0x4FBF60

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8BA280
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8BA500

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x74F9B0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6FDCC0
#define CCursorAttachment__Deactivate_x                            0x6FECA0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x93E1D0
#define CEQSuiteTextureLoader__GetTexture_x                        0x93DE90

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4F8EA0

//IString
#define IString__Append_x                                          0x4EB320

//Camera
#define CDisplay__cameraType_x                                     0xDB3258
#define EverQuest__Cameras_x                                       0xE76498

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x5015E0
#define LootFiltersManager__GetItemFilterData_x                    0x500EE0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x500F10
#define LootFiltersManager__SetItemLootFilter_x                    0x501130

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7A9E60

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x97CAB0
#define CResolutionHandler__GetWindowedStyle_x                     0x662020

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6F62B0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8CCA40

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x716440
#define CGroupWnd__UpdateDisplay_x                                 0x7157A0

//ItemBase
#define ItemBase__IsLore_x                                         0x88FF90
#define ItemBase__IsLoreEquipped_x                                 0x890000

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
