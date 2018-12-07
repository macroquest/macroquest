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
#if defined(LIVE)
#include "eqgame-private(live).h"
#endif
#endif

#define __ClientName                                              "eqgame"
#define __ExpectedVersionDate                                     "Nov 27 2018"
#define __ExpectedVersionTime                                     "12:05:33"
#define __ActualVersionDate_x                                      0xAC3724
#define __ActualVersionTime_x                                      0xAC3718

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x60A8D0
#define __MemChecker1_x                                            0x8DE780
#define __MemChecker2_x                                            0x6993E0
#define __MemChecker3_x                                            0x699330
#define __MemChecker4_x                                            0x836570
#define __EncryptPad0_x                                            0xBF54C0
#define __EncryptPad1_x                                            0xC53198
#define __EncryptPad2_x                                            0xC06048
#define __EncryptPad3_x                                            0xC05C48
#define __EncryptPad4_x                                            0xC43F30
#define __EncryptPad5_x                                            0x101A24C
#define __AC1_x                                                    0x7F3056
#define __AC2_x                                                    0x5C5A1F
#define __AC3_x                                                    0x5CC8AF
#define __AC4_x                                                    0x5D0720
#define __AC5_x                                                    0x5D68DF
#define __AC6_x                                                    0x5DAE16
#define __AC7_x                                                    0x5C5490
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1EB972C

// Direct Input
#define DI8__Main_x                                                0xF0F010
#define DI8__Keyboard_x                                            0xF0F014
#define DI8__Mouse_x                                               0xF0F008
#define DI8__Mouse_Copy_x                                          0xE6CD64
#define DI8__Mouse_Check_x                                         0xF0FED8
#define __AutoSkillArray_x                                         0xE6DC7C
#define __Attack_x                                                 0xF0BA7F
#define __Autofire_x                                               0xF0BA80
#define __BindList_x                                               0xBE40C0
#define g_eqCommandStates_x                                        0xBE4E30
#define __Clicks_x                                                 0xE6CE1C
#define __CommandList_x                                            0xBE59E8
#define __CurrentMapLabel_x                                        0x102162C
#define __CurrentSocial_x                                          0xBCF728
#define __DoAbilityList_x                                          0xEA35A0
#define __do_loot_x                                                0x593320
#define __DrawHandler_x                                            0x169CB60
#define __GroupCount_x                                             0xE5D5F2
#define __Guilds_x                                                 0xE63570
#define __gWorld_x                                                 0xE5D7E0
#define __HWnd_x                                                   0xF0F00C
#define __heqmain_x                                                0x101A234
#define __InChatMode_x                                             0xE6CD4C
#define __LastTell_x                                               0xE6EC9C
#define __LMouseHeldTime_x                                         0xE6CE88
#define __Mouse_x                                                  0x101A258
#define __MouseLook_x                                              0xE6CDE2
#define __MouseEventTime_x                                         0xF0C538
#define __gpbCommandEvent_x                                        0xE5D020
#define __NetStatusToggle_x                                        0xE6CDE5
#define __PCNames_x                                                0xE6E25C
#define __RangeAttackReady_x                                       0xE6DF60
#define __RMouseHeldTime_x                                         0xE6CE84
#define __RunWalkState_x                                           0xE6CD50
#define __ScreenMode_x                                             0xDAB0B8
#define __ScreenX_x                                                0xE6CD04
#define __ScreenY_x                                                0xE6CD00
#define __ScreenXMax_x                                             0xE6CD08
#define __ScreenYMax_x                                             0xE6CD0C
#define __ServerHost_x                                             0xE5D263
#define __ServerName_x                                             0xEA3560
#define __ShiftKeyDown_x                                           0xE6D3DC
#define __ShowNames_x                                              0xE6E11C
#define __Socials_x                                                0xEA3660
#define __SubscriptionType_x                                       0x10630F4
#define __TargetAggroHolder_x                                      0x1023FE4
#define __ZoneType_x                                               0xE6D1E0
#define __GroupAggro_x                                             0x1024024
#define __LoginName_x                                              0xF0F86C
#define __Inviter_x                                                0xF0B9FC
#define __AttackOnAssist_x                                         0xE6E0D8
#define __UseTellWindows_x                                         0xE6E3F4
#define __gfMaxZoomCameraDistance_x                                0xAB8B08
#define __gfMaxCameraDistance_x                                    0xAE60D4
#define __pulAutoRun_x                                             0xE6CE00
#define __pulForward_x                                             0xE6E42C
#define __pulBackward_x                                            0xE6E430
#define __pulTurnRight_x                                           0xE6E434
#define __pulTurnLeft_x                                            0xE6E438
#define __pulStrafeLeft_x                                          0xE6E43C
#define __pulStrafeRight_x                                         0xE6E440
//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE5F908
#define instEQZoneInfo_x                                           0xE6CFD8
#define instKeypressHandler_x                                      0xF0C4E8
#define pinstActiveBanker_x                                        0xE5D154
#define pinstActiveCorpse_x                                        0xE5D14C
#define pinstActiveGMaster_x                                       0xE5D150
#define pinstActiveMerchant_x                                      0xE5D148
#define pinstAggroInfo_x                                           0xC699B8
#define pinstAltAdvManager_x                                       0xDAC2B0
#define pinstAuraMgr_x                                             0xC7A6A0
#define pinstBandageTarget_x                                       0xE5D370
#define pinstCamActor_x                                            0xDAB0AC
#define pinstCDBStr_x                                              0xDAAFEC
#define pinstCDisplay_x                                            0xE5D5B8
#define pinstCEverQuest_x                                          0xF0F130
#define pinstEverQuestInfo_x                                       0xE6CCF8
#define pinstCharData_x                                            0xE5D5C0
#define pinstCharSpawn_x                                           0xE5D5AC
#define pinstControlledMissile_x                                   0xE5D5C4
#define pinstControlledPlayer_x                                    0xE5D5AC
#define pinstCResolutionHandler_x                                  0x169CD90
#define pinstCSidlManager_x                                        0x169BC24
#define pinstCXWndManager_x                                        0x169BC18
#define instDynamicZone_x                                          0xE63448
#define pinstDZMember_x                                            0xE63558
#define pinstDZTimerInfo_x                                         0xE6355C
#define pinstEQItemList_x                                          0xE5BAF8
#define pinstEQObjectList_x                                        0xE5CCE8
#define instEQMisc_x                                               0xDAAF28
#define pinstEQSoundManager_x                                      0xDACB10
#define pinstEQSpellStrings_x                                      0xC77AF0
#define instExpeditionLeader_x                                     0xE63492
#define instExpeditionName_x                                       0xE634D2
#define pinstGroup_x                                               0xE5D5EE
#define pinstImeManager_x                                          0x169BC1C
#define pinstLocalPlayer_x                                         0xE5D144
#define pinstMercenaryData_x                                       0xF0CCE0
#define pinstMercenaryStats_x                                      0x1024130
#define pinstMercAltAbilities_x                                    0xDAC880
#define pinstModelPlayer_x                                         0xE5D15C
#define pinstPCData_x                                              0xE5D5C0
#define pinstRealEstateItems_x                                     0xF0E1C8
#define pinstSkillMgr_x                                            0xF0E298
#define pinstSpawnManager_x                                        0xF0D888
#define pinstSpellManager_x                                        0xF0E470
#define pinstSpellSets_x                                           0xF046A8
#define pinstStringTable_x                                         0xE5F7EC
#define pinstSwitchManager_x                                       0xE5CEA8
#define pinstTarget_x                                              0xE5D374
#define pinstTargetObject_x                                        0xE5D5B4
#define pinstTargetSwitch_x                                        0xE5D5CC
#define pinstTaskMember_x                                          0xDAADBC
#define pinstTrackTarget_x                                         0xE5D5B0
#define pinstTradeTarget_x                                         0xE5D158
#define instTributeActive_x                                        0xDAAF4D
#define pinstViewActor_x                                           0xDAB0A8
#define pinstWorldData_x                                           0xE5D5D4
#define pinstZoneAddr_x                                            0xE6D278
#define pinstPlayerPath_x                                          0xF0D920
#define pinstTargetIndicator_x                                     0xF0E6D8
#define pinstCTargetManager_x                                      0xF0E770
#define EQObject_Top_x                                             0xE5D140

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDAB8D8
#define pinstCAchievementsWnd_x                                    0xDAB138
#define pinstCActionsWnd_x                                         0xDAB0A4
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDAB8E0
#define pinstCAdvancedLootWnd_x                                    0xDAB8B4
#define pinstCAdventureLeaderboardWnd_x                            0x101AE00
#define pinstCAdventureRequestWnd_x                                0x101AEB0
#define pinstCAdventureStatsWnd_x                                  0x101AF60
#define pinstCAggroMeterWnd_x                                      0xDAB148
#define pinstCAlarmWnd_x                                           0xDAB110
#define pinstCAlertHistoryWnd_x                                    0xDAB0FC
#define pinstCAlertStackWnd_x                                      0xDAB904
#define pinstCAlertWnd_x                                           0xDAB914
#define pinstCAltStorageWnd_x                                      0x101B2C0
#define pinstCAudioTriggersWindow_x                                0xC69E48
#define pinstCAuraWnd_x                                            0xDAB140
#define pinstCAvaZoneWnd_x                                         0xDAB0E0
#define pinstCBandolierWnd_x                                       0xDAB37C
#define pinstCBankWnd_x                                            0xDAB87C
#define pinstCBarterMerchantWnd_x                                  0x101C500
#define pinstCBarterSearchWnd_x                                    0x101C5B0
#define pinstCBarterWnd_x                                          0x101C660
#define pinstCBazaarConfirmationWnd_x                              0xDAB8FC
#define pinstCBazaarSearchWnd_x                                    0xDAB0CC
#define pinstCBazaarWnd_x                                          0xDAB378
#define pinstCBlockedBuffWnd_x                                     0xDAB844
#define pinstCBlockedPetBuffWnd_x                                  0xDAB88C
#define pinstCBodyTintWnd_x                                        0xDAB910
#define pinstCBookWnd_x                                            0xDAB3A0
#define pinstCBreathWnd_x                                          0xDAB8DC
#define pinstCBuffWindowNORMAL_x                                   0xDAB3B0
#define pinstCBuffWindowSHORT_x                                    0xDAB3B4
#define pinstCBugReportWnd_x                                       0xDAB8D4
#define pinstCButtonWnd_x                                          0x169BE10
#define pinstCCastingWnd_x                                         0xDAB8D0
#define pinstCCastSpellWnd_x                                       0xDAB0E4
//#define pinstCCharacterCreationWnd_x                             0xDAAE5C
#define pinstCCharacterListWnd_x                                   0xDAB8E8
#define pinstCChatWindowManager_x                                  0x101D120
#define pinstCClaimWnd_x                                           0x101D278
#define pinstCColorPickerWnd_x                                     0xDAB088
#define pinstCCombatAbilityWnd_x                                   0xDAB158
#define pinstCCombatSkillsSelectWnd_x                              0xDAB0A0
#define pinstCCompassWnd_x                                         0xDAB8F4
#define pinstCConfirmationDialog_x                                 0x1022178
#define pinstCContainerMgr_x                                       0xDAB374
#define pinstCContextMenuManager_x                                 0x169BBD8
#define pinstCCursorAttachment_x                                   0xDAB8C4
#define pinstCDistillerInfo_x                                      0x1020B84
#define pinstCDynamicZoneWnd_x                                     0x101D840
#define pinstCEditLabelWnd_x                                       0xDAB3A8
#define pinstCEQMainWnd_x                                          0x101DA88
#define pinstCEventCalendarWnd_x                                   0xDAB388
#define pinstCExtendedTargetWnd_x                                  0xDAB134
#define pinstCFacePick_x                                           0xDAB090
#define pinstCFellowshipWnd_x                                      0x101DC88
#define pinstCFileSelectionWnd_x                                   0xDAB894
#define pinstCFindItemWnd_x                                        0xDAB394
#define pinstCFindLocationWnd_x                                    0x101DDE0
#define pinstCFriendsWnd_x                                         0xDAB0D0
#define pinstCGemsGameWnd_x                                        0xDAB0E8
#define pinstCGiveWnd_x                                            0xDAB39C
#define pinstCGroupSearchFiltersWnd_x                              0xDAB364
#define pinstCGroupSearchWnd_x                                     0x101E1D8
#define pinstCGroupWnd_x                                           0x101E288
#define pinstCGuildBankWnd_x                                       0xE6E0BC
#define pinstCGuildCreationWnd_x                                   0x101E3E8
#define pinstCGuildMgmtWnd_x                                       0x101E498
#define pinstCharacterCreation_x                                   0xDAB154
#define pinstCHelpWnd_x                                            0xDAB100
#define pinstCHeritageSelectionWnd_x                               0xDAB094
#define pinstCHotButtonWnd_x                                       0x10205F0
#define pinstCHotButtonWnd1_x                                      0x10205F0
#define pinstCHotButtonWnd2_x                                      0x10205F4
#define pinstCHotButtonWnd3_x                                      0x10205F8
#define pinstCHotButtonWnd4_x                                      0x10205FC
#define pinstCIconSelectionWnd_x                                   0xDAB898
#define pinstCInspectWnd_x                                         0xDAB890
#define pinstCInventoryWnd_x                                       0xDAB384
#define pinstCInvSlotMgr_x                                         0xDAB124
#define pinstCItemDisplayManager_x                                 0x1020B80
#define pinstCItemExpTransferWnd_x                                 0x1020CB4
#define pinstCItemOverflowWnd_x                                    0xDAB0D4
#define pinstCJournalCatWnd_x                                      0xDAB8C0
//#define pinstCJournalNPCWnd_x                                    0xDAB354
#define pinstCJournalTextWnd_x                                     0xDAB850
#define pinstCKeyRingWnd_x                                         0xDAB434
#define pinstCLargeDialogWnd_x                                     0x1022DF8
#define pinstCLayoutCopyWnd_x                                      0x1021000
#define pinstCLFGuildWnd_x                                         0x10210B0
#define pinstCLoadskinWnd_x                                        0xDAB0F8
#define pinstCLootFiltersCopyWnd_x                                 0xC7AE80
#define pinstCLootFiltersWnd_x                                     0xDAB098
#define pinstCLootSettingsWnd_x                                    0xDAB0C4
#define pinstCLootWnd_x                                            0xDAB908
#define pinstCMailAddressBookWnd_x                                 0xDAB8A0
#define pinstCMailCompositionWnd_x                                 0xDAB884
#define pinstCMailIgnoreListWnd_x                                  0xDAB8A4
#define pinstCMailWnd_x                                            0xDAB840
#define pinstCManageLootWnd_x                                      0xDAC728
#define pinstCMapToolbarWnd_x                                      0xDAB38C
#define pinstCMapViewWnd_x                                         0xDAB36C
#define pinstCMarketplaceWnd_x                                     0xDAB398
#define pinstCMerchantWnd_x                                        0xDAB09C
#define pinstCMIZoneSelectWnd_x                                    0x10218E8
#define pinstCMusicPlayerWnd_x                                     0xDAB430
#define pinstCNameChangeMercWnd_x                                  0xDAB8C8
#define pinstCNameChangePetWnd_x                                   0xDAB8AC
#define pinstCNameChangeWnd_x                                      0xDAB370
#define pinstCNoteWnd_x                                            0xDAB0F4
#define pinstCObjectPreviewWnd_x                                   0xDAB42C
#define pinstCOptionsWnd_x                                         0xDAB390
#define pinstCPetInfoWnd_x                                         0xDAB858
#define pinstCPetitionQWnd_x                                       0xDAB8CC
//#define pinstCPlayerCustomizationWnd_x                             0xDAADC4
#define pinstCPlayerNotesWnd_x                                     0xDAB90C
#define pinstCPlayerWnd_x                                          0xDAB0D8
#define pinstCPopupWndManager_x                                    0x1022178
#define pinstCProgressionSelectionWnd_x                            0x1022228
#define pinstCPurchaseGroupWnd_x                                   0xDAB880
#define pinstCPurchaseWnd_x                                        0xDAB83C
#define pinstCPvPLeaderboardWnd_x                                  0x10222D8
#define pinstCPvPStatsWnd_x                                        0x1022388
#define pinstCQuantityWnd_x                                        0xDAB8B0
#define pinstCRaceChangeWnd_x                                      0xDAB3A4
#define pinstCRaidOptionsWnd_x                                     0xDAB368
#define pinstCRaidWnd_x                                            0xDAB8B8
#define pinstCRealEstateItemsWnd_x                                 0xDAB144
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDAB380
#define pinstCRealEstateManageWnd_x                                0xDAB0C8
#define pinstCRealEstateNeighborhoodWnd_x                          0xDAB0EC
#define pinstCRealEstatePlotSearchWnd_x                            0xDAB104
#define pinstCRealEstatePurchaseWnd_x                              0xDAB128
#define pinstCRespawnWnd_x                                         0xDAB360
//#define pinstCRewardSelectionWnd_x                               0x1022600
#define pinstCSelectorWnd_x                                        0xDAB130
#define pinstCSendMoneyWnd_x                                       0xDAB3AC
#define pinstCServerListWnd_x                                      0xDAB14C
#define pinstCSkillsSelectWnd_x                                    0xDAB08C
#define pinstCSkillsWnd_x                                          0xDAB900
#define pinstCSocialEditWnd_x                                      0xDAB8BC
#define pinstCSocialWnd_x                                          0xDAB8E4
#define pinstCSpellBookWnd_x                                       0xDAB12C
#define pinstCStoryWnd_x                                           0xDAB8EC
#define pinstCTargetOfTargetWnd_x                                  0x10241B8
#define pinstCTargetWnd_x                                          0xDAB854
#define pinstCTaskOverlayWnd_x                                     0xDAB108
#define pinstCTaskSelectWnd_x                                      0x1024310
#define pinstCTaskManager_x                                        0xC7B680
#define pinstCTaskTemplateSelectWnd_x                              0x10243C0
#define pinstCTaskWnd_x                                            0x1024470
#define pinstCTextEntryWnd_x                                       0xDAB8F8
#define pinstCTextOverlay_x                                        0xC6A158
#define pinstCTimeLeftWnd_x                                        0xDAB89C
#define pinstCTipWndCONTEXT_x                                      0x1024674
#define pinstCTipWndOFDAY_x                                        0x1024670
#define pinstCTitleWnd_x                                           0x1024720
#define pinstCTrackingWnd_x                                        0xDAB84C
#define pinstCTradeskillWnd_x                                      0x1024888
#define pinstCTradeWnd_x                                           0xDAB10C
#define pinstCTrainWnd_x                                           0xDAB8A8
#define pinstCTributeBenefitWnd_x                                  0x1024A88
#define pinstCTributeMasterWnd_x                                   0x1024B38
#define pinstCTributeTrophyWnd_x                                   0x1024BE8
#define pinstCVideoModesWnd_x                                      0xDAB114
#define pinstCVoiceMacroWnd_x                                      0xF0ECA0
#define pinstCVoteResultsWnd_x                                     0xDAB888
#define pinstCVoteWnd_x                                            0xDAB848
#define pinstCWebManager_x                                         0xF0EE04
#define pinstCZoneGuideWnd_x                                       0xDAB0DC
#define pinstCZonePathWnd_x                                        0xDAB0F0

#define pinstEQSuiteTextureLoader_x                                0xC54C50
#define pinstItemIconCache_x                                       0x101DA40
#define pinstLootFiltersManager_x                                  0xC7AF30
#define pinstRewardSelectionWnd_x                                  0x1022AD0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC05C3C
#define __CastRay_x                                                0x58E840
#define __CastRay2_x                                               0x58E890
#define __ConvertItemTags_x                                        0x5A9430
#define __CrashHandler_x                                           0x83FF40
#define __EQGetTime_x                                              0x8DE270
#define __ExecuteCmd_x                                             0x5871B0
#define __FixHeading_x                                             0x96E970
#define __get_bearing_x                                            0x58E380
#define __get_melee_range_x                                        0x58EA80
#define __GetAnimationCache_x                                      0x6FD0A0
#define __GetGaugeValueFromEQ_x                                    0x7F1870
#define __GetLabelFromEQ_x                                         0x7F2FE0
#define __GetXTargetType_x                                         0x9704A0
#define __HandleMouseWheel_x                                       0x699490
#define __HeadingDiff_x                                            0x96E9E0
#define __HelpPath_x                                               0xF0C154
#define __LoadFrontEnd_x                                           0x695240
#define __NewUIINI_x                                               0x7F1540
#define __pCrashHandler_x                                          0x1041F50
#define __ProcessGameEvents_x                                      0x5EBE80
#define __ProcessMouseEvent_x                                      0x5EB640
#define __SaveColors_x                                             0x538B70
#define __STMLToText_x                                             0x911E00
#define __ToggleKeyRingItem_x                                      0x4FBCB0
#define CrashDetected_x                                            0x696D30
#define DrawNetStatus_x                                            0x618090
#define Expansion_HoT_x                                            0xE6E0C4
#define Teleport_Table_Size_x                                      0xE5D100
#define Teleport_Table_x                                           0xE5D7E8
#define Util__FastTime_x                                           0x8DDE30
#define wwsCrashReportCheckForUploader_x                           0x840AF0
#define wwsCrashReportPlatformLaunchUploader_x                     0x8431B0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48AAD0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4938D0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4936B0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x5404A0
#define AltAdvManager__IsAbilityReady_x                            0x53F520
#define AltAdvManager__GetAAById_x                                 0x53F720
#define AltAdvManager__CanTrainAbility_x                           0x53F790
#define AltAdvManager__CanSeeAbility_x                             0x53F9C0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C6460
#define CharacterZoneClient__HasSkill_x                            0x4D1000
#define CharacterZoneClient__MakeMeVisible_x                       0x4D2720
#define CharacterZoneClient__IsStackBlocked_x                      0x4BA8D0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B7050
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D4E60
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D4F40
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D5020
#define CharacterZoneClient__FindAffectSlot_x                      0x4BF3B0
#define CharacterZoneClient__BardCastBard_x                        0x4C2020
#define CharacterZoneClient__GetMaxEffects_x                       0x4B7120
#define CharacterZoneClient__GetEffect_x                           0x4B6F90
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C03B0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C0480
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C04D0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C0620
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C07F0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6BF620

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6CCF50

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5FA4E0
#define CButtonWnd__CButtonWnd_x                                   0x90E210

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6EBAA0
#define CChatManager__InitContextMenu_x                            0x6E5B40
#define CChatManager__FreeChatWindow_x                             0x6EA9B0
#define CChatManager__GetLockedActiveChatWindow_x                  0x6EF340
#define CChatManager__SetLockedActiveChatWindow_x                  0x6EB840

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x922A00
#define CContextMenu__dCContextMenu_x                              0x922C30
#define CContextMenu__AddMenuItem_x                                0x922C40
#define CContextMenu__RemoveMenuItem_x                             0x922F50
#define CContextMenu__RemoveAllMenuItems_x                         0x922F70
#define CContextMenu__CheckMenuItem_x                              0x922FF0
#define CContextMenu__SetMenuItem_x                                0x922E70
#define CContextMenu__AddSeparator_x                               0x922DD0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x923590
#define CContextMenuManager__RemoveMenu_x                          0x923600
#define CContextMenuManager__PopupMenu_x                           0x9236C0
#define CContextMenuManager__Flush_x                               0x923530
#define CContextMenuManager__GetMenu_x                             0x4959A0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8BED40
#define CChatService__GetFriendName_x                              0x8BED50

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6EC010
#define CChatWindow__Clear_x                                       0x6ED060
#define CChatWindow__WndNotification_x                             0x6ED5D0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x91FE90
#define CComboWnd__Draw_x                                          0x91F370
#define CComboWnd__GetCurChoice_x                                  0x91FCD0
#define CComboWnd__GetListRect_x                                   0x91F830
#define CComboWnd__GetTextRect_x                                   0x91FF00
#define CComboWnd__InsertChoice_x                                  0x91F9C0
#define CComboWnd__SetColors_x                                     0x91F990
#define CComboWnd__SetChoice_x                                     0x91FCA0
#define CComboWnd__GetItemCount_x                                  0x91FCE0
#define CComboWnd__GetCurChoiceText_x                              0x91FD20

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6F5250
#define CContainerWnd__vftable_x                                   0xACCB10
#define CContainerWnd__SetContainer_x                              0x6F67C0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x538930
#define CDisplay__GetClickedActor_x                                0x52B980
#define CDisplay__GetUserDefinedColor_x                            0x524060
#define CDisplay__GetWorldFilePath_x                               0x52D3D0
#define CDisplay__is3dON_x                                         0x528650
#define CDisplay__ReloadUI_x                                       0x532AF0
#define CDisplay__WriteTextHD2_x                                   0x528430
#define CDisplay__TrueDistance_x                                   0x52F030
#define CDisplay__SetViewActor_x                                   0x52B2D0
#define CDisplay__GetFloorHeight_x                                 0x528710
#define CDisplay__SetRenderWindow_x                                0x527040
#define CDisplay__ToggleScreenshotMode_x                           0x52ADA0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x942130

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x927120
#define CEditWnd__GetCharIndexPt_x                                 0x928010
#define CEditWnd__GetDisplayString_x                               0x927EB0
#define CEditWnd__GetHorzOffset_x                                  0x926750
#define CEditWnd__GetLineForPrintableChar_x                        0x929120
#define CEditWnd__GetSelStartPt_x                                  0x9282C0
#define CEditWnd__GetSTMLSafeText_x                                0x927CD0
#define CEditWnd__PointFromPrintableChar_x                         0x928D60
#define CEditWnd__SelectableCharFromPoint_x                        0x928ED0
#define CEditWnd__SetEditable_x                                    0x928380

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5DA340
#define CEverQuest__ClickedPlayer_x                                0x5CC690
#define CEverQuest__CreateTargetIndicator_x                        0x5E9160
#define CEverQuest__DeleteTargetIndicator_x                        0x5E91F0
#define CEverQuest__DoTellWindow_x                                 0x4E1880
#define CEverQuest__OutputTextToLog_x                              0x4E1AB0
#define CEverQuest__DropHeldItemOnGround_x                         0x5C1F50
#define CEverQuest__dsp_chat_x                                     0x4E1E40
#define CEverQuest__trimName_x                                     0x5E56E0
#define CEverQuest__Emote_x                                        0x5DAB50
#define CEverQuest__EnterZone_x                                    0x5D4D30
#define CEverQuest__GetBodyTypeDesc_x                              0x5DEF90
#define CEverQuest__GetClassDesc_x                                 0x5DF5D0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5DFBD0
#define CEverQuest__GetDeityDesc_x                                 0x5E7AB0
#define CEverQuest__GetLangDesc_x                                  0x5DFD90
#define CEverQuest__GetRaceDesc_x                                  0x5DF5B0
#define CEverQuest__InterpretCmd_x                                 0x5E8080
#define CEverQuest__LeftClickedOnPlayer_x                          0x5C6140
#define CEverQuest__LMouseUp_x                                     0x5C44C0
#define CEverQuest__RightClickedOnPlayer_x                         0x5C6A20
#define CEverQuest__RMouseUp_x                                     0x5C5450
#define CEverQuest__SetGameState_x                                 0x5C1CE0
#define CEverQuest__UPCNotificationFlush_x                         0x5E55E0
#define CEverQuest__IssuePetCommand_x                              0x5E1190
#define CEverQuest__ReportSuccessfulHit_x                          0x5DB870

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x707220
#define CGaugeWnd__CalcLinesFillRect_x                             0x707280
#define CGaugeWnd__Draw_x                                          0x706920

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ABF80
#define CGuild__GetGuildName_x                                     0x4AB060
#define CGuild__GetGuildIndex_x                                    0x4AB3F0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x7225F0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x5FA8A0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x72F5B0
#define CInvSlotMgr__MoveItem_x                                    0x72E2D0
#define CInvSlotMgr__SelectSlot_x                                  0x72F680

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x72CB80
#define CInvSlot__SliderComplete_x                                 0x72A8F0
#define CInvSlot__GetItemBase_x                                    0x72A260
#define CInvSlot__UpdateItem_x                                     0x72A3D0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x730FD0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7302A0
#define CInvSlotWnd__HandleLButtonUp_x                             0x730B50

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7EDA70
#define CItemDisplayWnd__UpdateStrings_x                           0x73FBB0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x739CC0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x73A1F0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x740140
#define CItemDisplayWnd__AboutToShow_x                             0x73F810
#define CItemDisplayWnd__WndNotification_x                         0x741460

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x825370

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x745510

// CLabel 
#define CLabel__Draw_x                                             0x74B030

// CListWnd
#define CListWnd__CListWnd_x                                       0x8F8730
#define CListWnd__dCListWnd_x                                      0x8F8A50
#define CListWnd__AddColumn_x                                      0x8FCD80
#define CListWnd__AddColumn1_x                                     0x8FCDD0
#define CListWnd__AddLine_x                                        0x8FD160
#define CListWnd__AddString_x                                      0x8FCF60
#define CListWnd__CalculateFirstVisibleLine_x                      0x8FCB40
#define CListWnd__CalculateVSBRange_x                              0x8FC920
#define CListWnd__ClearSel_x                                       0x8FD940
#define CListWnd__ClearAllSel_x                                    0x8FD9A0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8FE3B0
#define CListWnd__Compare_x                                        0x8FC260
#define CListWnd__Draw_x                                           0x8F8B50
#define CListWnd__DrawColumnSeparators_x                           0x8FB330
#define CListWnd__DrawHeader_x                                     0x8FB7A0
#define CListWnd__DrawItem_x                                       0x8FBBA0
#define CListWnd__DrawLine_x                                       0x8FB4A0
#define CListWnd__DrawSeparator_x                                  0x8FB3D0
#define CListWnd__EnableLine_x                                     0x8FAC10
#define CListWnd__EnsureVisible_x                                  0x8FE2D0
#define CListWnd__ExtendSel_x                                      0x8FD870
#define CListWnd__GetColumnMinWidth_x                              0x8FA750
#define CListWnd__GetColumnWidth_x                                 0x8FA6C0
#define CListWnd__GetCurSel_x                                      0x8FA050
#define CListWnd__GetItemAtPoint_x                                 0x8FAE90
#define CListWnd__GetItemAtPoint1_x                                0x8FAF00
#define CListWnd__GetItemData_x                                    0x8FA0D0
#define CListWnd__GetItemHeight_x                                  0x8FA490
#define CListWnd__GetItemIcon_x                                    0x8FA260
#define CListWnd__GetItemRect_x                                    0x8FAD00
#define CListWnd__GetItemText_x                                    0x8FA110
#define CListWnd__GetSelList_x                                     0x8FD9F0
#define CListWnd__GetSeparatorRect_x                               0x8FB140
#define CListWnd__InsertLine_x                                     0x8FD550
#define CListWnd__RemoveLine_x                                     0x8FD6A0
#define CListWnd__SetColors_x                                      0x8FC8F0
#define CListWnd__SetColumnJustification_x                         0x8FC620
#define CListWnd__SetColumnWidth_x                                 0x8FC540
#define CListWnd__SetCurSel_x                                      0x8FD7B0
#define CListWnd__SetItemColor_x                                   0x8FDF80
#define CListWnd__SetItemData_x                                    0x8FDF40
#define CListWnd__SetItemText_x                                    0x8FDB70
#define CListWnd__ShiftColumnSeparator_x                           0x8FC6E0
#define CListWnd__Sort_x                                           0x8FC3E0
#define CListWnd__ToggleSel_x                                      0x8FD7E0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7603F0
#define CMapViewWnd__GetWorldCoordinates_x                         0x75EB00
#define CMapViewWnd__HandleLButtonDown_x                           0x75BB60

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x783600
// CMerchantWnd__RequestBuyItem_x                             
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x783EE0
// CMerchantWnd__RequestSellItem_x
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x784410
#define CMerchantWnd__SelectRecoverySlot_x                         0x787240
//CMerchantWnd__SelectBuySellSlot_x before
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x781FE0
//CMerchantWnd__ActualSelect_x
#define CMerchantWnd__SelectBuySellSlot_x                          0x78CDD0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x783230

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x88CC30
#define CPacketScrambler__hton_x                                   0x88CC20

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x9173D0
#define CSidlManager__FindScreenPieceTemplate_x                    0x9177E0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9175D0
#define CSidlManager__CreateLabel_x                                0x7E4EA0
#define CSidlManager__CreateXWndFromTemplate_x                     0x91A8B0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x91AA90
#define CSidlManager__CreateXWnd_x                                 0x7E4DD0
#define CSidlManager__CreateHotButtonWnd_x                         0x7E5390

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x913F70
#define CSidlScreenWnd__CalculateVSBRange_x                        0x913E70
#define CSidlScreenWnd__ConvertToRes_x                             0x9389C0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x913900
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x9135F0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x9136C0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x913790
#define CSidlScreenWnd__DrawSidlPiece_x                            0x914410
#define CSidlScreenWnd__EnableIniStorage_x                         0x9148E0
#define CSidlScreenWnd__GetSidlPiece_x                             0x914600
#define CSidlScreenWnd__Init1_x                                    0x9131E0
#define CSidlScreenWnd__LoadIniInfo_x                              0x914930
#define CSidlScreenWnd__LoadIniListWnd_x                           0x915440
#define CSidlScreenWnd__LoadSidlScreen_x                           0x9125F0
#define CSidlScreenWnd__StoreIniInfo_x                             0x914FC0
#define CSidlScreenWnd__StoreIniVis_x                              0x915320
#define CSidlScreenWnd__WndNotification_x                          0x914320
#define CSidlScreenWnd__GetChildItem_x                             0x914860
#define CSidlScreenWnd__HandleLButtonUp_x                          0x904140
#define CSidlScreenWnd__m_layoutCopy_x                             0x169BAA8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x65EC60
#define CSkillMgr__GetSkillCap_x                                   0x65EE40
#define CSkillMgr__GetNameToken_x                                  0x65E3F0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x924390
#define CSliderWnd__SetValue_x                                     0x924200
#define CSliderWnd__SetNumTicks_x                                  0x924260

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7EACC0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x92AFD0
#define CStmlWnd__CalculateHSBRange_x                              0x92C060
#define CStmlWnd__CalculateVSBRange_x                              0x92BFD0
#define CStmlWnd__CanBreakAtCharacter_x                            0x9303A0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x930F90
#define CStmlWnd__ForceParseNow_x                                  0x92B570
#define CStmlWnd__GetNextTagPiece_x                                0x930300
#define CStmlWnd__GetSTMLText_x                                    0x4EFC70
#define CStmlWnd__GetVisibleText_x                                 0x92B590
#define CStmlWnd__InitializeWindowVariables_x                      0x930DE0
#define CStmlWnd__MakeStmlColorTag_x                               0x92A760
#define CStmlWnd__MakeWndNotificationTag_x                         0x92A7D0
#define CStmlWnd__SetSTMLText_x                                    0x929830
#define CStmlWnd__StripFirstSTMLLines_x                            0x9320F0
#define CStmlWnd__UpdateHistoryString_x                            0x9311A0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x935850
#define CTabWnd__DrawCurrentPage_x                                 0x935E70
#define CTabWnd__DrawTab_x                                         0x935C40
#define CTabWnd__GetCurrentPage_x                                  0x9350B0
#define CTabWnd__GetPageInnerRect_x                                0x9352F0
#define CTabWnd__GetTabInnerRect_x                                 0x935230
#define CTabWnd__GetTabRect_x                                      0x9350E0
#define CTabWnd__InsertPage_x                                      0x9354E0
#define CTabWnd__SetPage_x                                         0x935370
#define CTabWnd__SetPageRect_x                                     0x935790
#define CTabWnd__UpdatePage_x                                      0x935B00
#define CTabWnd__GetPageFromTabIndex_x                             0x935B80
#define CTabWnd__GetCurrentTabIndex_x                              0x9350A0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x745970
#define CPageWnd__SetTabText_x                                     0x942540

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A5AD0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x900FD0
#define CTextureFont__GetTextExtent_x                              0x901190

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x692090
#define CHtmlComponentWnd__ValidateUri_x                           0x723FE0
#define CHtmlWnd__SetClientCallbacks_x                             0x5FF880
#define CHtmlWnd__AddObserver_x                                    0x5FF8A0
#define CHtmlWnd__RemoveObserver_x                                 0x5FF900
#define Window__getProgress_x                                      0x83DBB0
#define Window__getStatus_x                                        0x83DBD0
#define Window__getURI_x                                           0x83DBE0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x93EAC0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8EDF90

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4AD220
#define CXStr__CXStr1_x                                            0x9B05F0
#define CXStr__CXStr3_x                                            0x8DA360
#define CXStr__dCXStr_x                                            0x472340
#define CXStr__operator_equal_x                                    0x8DA590
#define CXStr__operator_equal1_x                                   0x8DA5D0
#define CXStr__operator_plus_equal1_x                              0x8DB060

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x922620
#define CXWnd__BringToTop_x                                        0x907800
#define CXWnd__Center_x                                            0x907380
#define CXWnd__ClrFocus_x                                          0x9071B0
#define CXWnd__Destroy_x                                           0x907260
#define CXWnd__DoAllDrawing_x                                      0x9038D0
#define CXWnd__DrawChildren_x                                      0x9038A0
#define CXWnd__DrawColoredRect_x                                   0x903D30
#define CXWnd__DrawTooltip_x                                       0x902410
#define CXWnd__DrawTooltipAtPoint_x                                0x9024D0
#define CXWnd__GetBorderFrame_x                                    0x903B90
#define CXWnd__GetChildWndAt_x                                     0x9078A0
#define CXWnd__GetClientClipRect_x                                 0x905B10
#define CXWnd__GetScreenClipRect_x                                 0x905BE0
#define CXWnd__GetScreenRect_x                                     0x905DA0
#define CXWnd__GetTooltipRect_x                                    0x903D80
#define CXWnd__GetWindowTextA_x                                    0x497020
#define CXWnd__IsActive_x                                          0x90A6F0
#define CXWnd__IsDescendantOf_x                                    0x906760
#define CXWnd__IsReallyVisible_x                                   0x906790
#define CXWnd__IsType_x                                            0x907F00
#define CXWnd__Move_x                                              0x9067F0
#define CXWnd__Move1_x                                             0x9068A0
#define CXWnd__ProcessTransition_x                                 0x907330
#define CXWnd__Refade_x                                            0x906B50
#define CXWnd__Resize_x                                            0x906E10
#define CXWnd__Right_x                                             0x9075C0
#define CXWnd__SetFocus_x                                          0x907170
#define CXWnd__SetFont_x                                           0x9071E0
#define CXWnd__SetKeyTooltip_x                                     0x907D30
#define CXWnd__SetMouseOver_x                                      0x904CB0
#define CXWnd__StartFade_x                                         0x906630
#define CXWnd__GetChildItem_x                                      0x907A10
#define CXWnd__SetParent_x                                         0x906500

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x939A90

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x90A730
#define CXWndManager__DrawWindows_x                                0x90A750
#define CXWndManager__GetKeyboardFlags_x                           0x90CED0
#define CXWndManager__HandleKeyboardMsg_x                          0x90CAD0
#define CXWndManager__RemoveWnd_x                                  0x90D120
#define CXWndManager__RemovePendingDeletionWnd_x                   0x90D680

// CDBStr
#define CDBStr__GetString_x                                        0x523000

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B8000
#define EQ_Character__Cur_HP_x                                     0x4CE080
#define EQ_Character__Cur_Mana_x                                   0x4D5520
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BAF10
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AEE20
#define EQ_Character__GetFocusRangeModifier_x                      0x4AEF70
#define EQ_Character__GetHPRegen_x                                 0x4DAEB0
#define EQ_Character__GetEnduranceRegen_x                          0x4DB4C0
#define EQ_Character__GetManaRegen_x                               0x4DB900
#define EQ_Character__Max_Endurance_x                              0x625BF0
#define EQ_Character__Max_HP_x                                     0x4CDEB0
#define EQ_Character__Max_Mana_x                                   0x6259F0
#define EQ_Character__doCombatAbility_x                            0x627DA0
#define EQ_Character__UseSkill_x                                   0x4DD710
#define EQ_Character__GetConLevel_x                                0x61EE20
#define EQ_Character__IsExpansionFlag_x                            0x585970
#define EQ_Character__TotalEffect_x                                0x4C15A0
#define EQ_Character__GetPCSpellAffect_x                           0x4BBB00
#define EQ_Character__SpellDuration_x                              0x4BB630
#define EQ_Character__FindItemByRecord_x                           0x4D3690
#define EQ_Character__GetAdjustedSkill_x                           0x4D0DC0
#define EQ_Character__GetBaseSkill_x                               0x4D1D60
#define EQ_Character__CanUseItem_x                                 0x4D5830

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8ABC70

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x63BB30

//PcClient
#define PcClient__PcClient_x                                       0x61C6F0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B5DE0
#define CCharacterListWnd__EnterWorld_x                            0x4B5820
#define CCharacterListWnd__Quit_x                                  0x4B5530
#define CCharacterListWnd__UpdateList_x                            0x4B59B0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x600AD0
#define EQ_Item__CreateItemTagString_x                             0x886B50
#define EQ_Item__IsStackable_x                                     0x88B120
#define EQ_Item__GetImageNum_x                                     0x888440
#define EQ_Item__CreateItemClient_x                                0x5FFC80
#define EQ_Item__GetItemValue_x                                    0x889510
#define EQ_Item__ValueSellMerchant_x                               0x88C7D0
#define EQ_Item__IsKeyRingItem_x                                   0x88AA80
#define EQ_Item__CanGoInBag_x                                      0x600BF0
#define EQ_Item__GetMaxItemCount_x                                 0x889820
#define EQ_Item__GetHeldItem_x                                     0x888310
#define EQ_Item__GetAugmentFitBySlot_x                             0x8865B0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x541180
#define EQ_LoadingS__Array_x                                       0xBDD2D0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x626550
#define EQ_PC__GetAlternateAbilityId_x                             0x8959C0
#define EQ_PC__GetCombatAbility_x                                  0x896030
#define EQ_PC__GetCombatAbilityTimer_x                             0x8960A0
#define EQ_PC__GetItemRecastTimer_x                                0x628320
#define EQ_PC__HasLoreItem_x                                       0x61F5F0
#define EQ_PC__AlertInventoryChanged_x                             0x61E8F0
#define EQ_PC__GetPcZoneClient_x                                   0x64A320
#define EQ_PC__RemoveMyAffect_x                                    0x62B450
#define EQ_PC__GetKeyRingItems_x                                   0x896940
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8966C0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x896C30

// EQItemList 
#define EQItemList__EQItemList_x                                   0x58BDC0
#define EQItemList__add_object_x                                   0x5B76D0
#define EQItemList__add_item_x                                     0x58C3D0
#define EQItemList__delete_item_x                                  0x58C420
#define EQItemList__FreeItemList_x                                 0x58C320

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x520650

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x63D3B0
#define EQPlayer__dEQPlayer_x                                      0x630AB0
#define EQPlayer__DoAttack_x                                       0x645000
#define EQPlayer__EQPlayer_x                                       0x631160
#define EQPlayer__SetNameSpriteState_x                             0x6353E0
#define EQPlayer__SetNameSpriteTint_x                              0x6362B0
#define PlayerBase__HasProperty_j_x                                0x96CD40
#define EQPlayer__IsTargetable_x                                   0x96D1E0
#define EQPlayer__CanSee_x                                         0x96D040
#define EQPlayer__CanSee1_x                                        0x96D110
#define PlayerBase__GetVisibilityLineSegment_x                     0x96CE00

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x647DD0
#define PlayerZoneClient__GetLevel_x                               0x64A360
#define PlayerZoneClient__IsValidTeleport_x                        0x5B8820
#define PlayerZoneClient__LegalPlayerRace_x                        0x53A740

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x640130
#define EQPlayerManager__GetSpawnByName_x                          0x640150
#define EQPlayerManager__GetPlayerFromPartialName_x                0x6401E0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x604470
#define KeypressHandler__AttachKeyToEqCommand_x                    0x6044B0
#define KeypressHandler__ClearCommandStateArray_x                  0x6058A0
#define KeypressHandler__HandleKeyDown_x                           0x6058C0
#define KeypressHandler__HandleKeyUp_x                             0x605960
#define KeypressHandler__SaveKeymapping_x                          0x605D40

// MapViewMap 
#define MapViewMap__Clear_x                                        0x75C280
#define MapViewMap__SaveEx_x                                       0x75F620
#define MapViewMap__SetZoom_x                                      0x763CF0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8A9AC0

// StringTable 
#define StringTable__getString_x                                   0x8A4AF0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x62B0C0
#define PcZoneClient__RemovePetEffect_x                            0x62B6F0
#define PcZoneClient__HasAlternateAbility_x                        0x625830
#define PcZoneClient__GetCurrentMod_x                              0x4E0680
#define PcZoneClient__GetModCap_x                                  0x4E0580
#define PcZoneClient__CanEquipItem_x                               0x625EE0
#define PcZoneClient__GetItemByID_x                                0x628790
#define PcZoneClient__GetItemByItemClass_x                         0x628820
#define PcZoneClient__RemoveBuffEffect_x                           0x62B710
#define PcZoneClient__BandolierSwap_x                              0x626B10

//Doors
#define EQSwitch__UseSwitch_x                                      0x5BD410

//IconCache
#define IconCache__GetIcon_x                                       0x6FC930

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6F43F0
#define CContainerMgr__CloseContainer_x                            0x6F46C0
#define CContainerMgr__OpenExperimentContainer_x                   0x6F5140

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7B7450

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5F8CD0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x752770
#define CLootWnd__RequestLootSlot_x                                0x751B20

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x559690
#define EQ_Spell__SpellAffects_x                                   0x559B00
#define EQ_Spell__SpellAffectBase_x                                0x5598C0
#define EQ_Spell__IsStackable_x                                    0x4C5D80
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C5C60
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B3350
#define EQ_Spell__IsSPAStacking_x                                  0x55A930
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x559E50
#define EQ_Spell__IsNoRemove_x                                     0x4C5D60
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x55A940
#define __IsResEffectSpell_x                                       0x4C5100

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4A9CA0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8B41D0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7FCDE0
#define CTargetWnd__WndNotification_x                              0x7FC670
#define CTargetWnd__RefreshTargetBuffs_x                           0x7FC940
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x7FB7C0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x8014C0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x51DFD0
#define CTaskManager__HandleMessage_x                              0x51C720

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x554C10
#define EqSoundManager__PlayScriptMp3_x                            0x554D70
#define EqSoundManager__SoundAssistPlay_x                          0x662700
#define EqSoundManager__WaveInstancePlay_x                         0x661C70

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x511F70

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x925D80

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x548EB0
#define CAltAbilityData__GetMercMaxRank_x                          0x548E50
#define CAltAbilityData__GetMaxRank_x                              0x53E3D0

//CTargetRing
#define CTargetRing__Cast_x                                        0x5F6DE0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C5C40
#define CharacterBase__CreateItemGlobalIndex_x                     0x4F8170
#define CharacterBase__CreateItemIndex_x                           0x5FEE90
#define CharacterBase__GetItemPossession_x                         0x4B3200
#define CharacterBase__GetItemByGlobalIndex_x                      0x8BC870
#define CharacterBase__GetEffectId_x                               0x4C5BF0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6DC5C0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6DCDE0

//messages
#define msg_spell_worn_off_x                                       0x57DE40
#define msg_new_text_x                                             0x572EB0
#define __msgTokenTextParam_x                                      0x580490
#define msgTokenText_x                                             0x5806E0

//SpellManager
#define SpellManager__vftable_x                                    0xAA7848
#define SpellManager__SpellManager_x                               0x665A30
#define Spellmanager__LoadTextSpells_x                             0x666300
#define SpellManager__GetSpellByGroupAndRank_x                     0x665C00

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x970D90

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4F8820
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x583EA0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x617EA0
#define ItemGlobalIndex__IsValidIndex_x                            0x4F8880

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8B4B10
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8B4D90

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x74B380

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6F8B50
#define CCursorAttachment__Deactivate_x                            0x6F9B20

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x937E30
#define CEQSuiteTextureLoader__GetTexture_x                        0x937AF0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4F5820

//IString
#define IString__Append_x                                          0x4E9CA0

//Camera
#define CDisplay__cameraType_x                                     0xDAB15C
#define EverQuest__Cameras_x                                       0xE6E400

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x4FDF30
#define LootFiltersManager__GetItemFilterData_x                    0x4FD830
#define LootFiltersManager__RemoveItemLootFilter_x                 0x4FD860
#define LootFiltersManager__SetItemLootFilter_x                    0x4FDA80

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7A5490

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x976B20
#define CResolutionHandler__GetWindowedStyle_x                     0x65D6B0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6F11B0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8C6D00

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x7113C0
#define CGroupWnd__UpdateDisplay_x                                 0x710720

//ItemBase
#define ItemBase__IsLore_x                                         0x88AAE0
#define ItemBase__IsLoreEquipped_x                                 0x88AB50

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5B75C0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5B7770
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5B77D0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x652F70
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x656C50

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
