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
#define __ExpectedVersionDate                                     "Nov  6 2018"
#define __ExpectedVersionTime                                     "16:44:41"
#define __ActualVersionDate_x                                      0xAC36C4
#define __ActualVersionTime_x                                      0xAC36B8

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x60A270
#define __MemChecker1_x                                            0x8DE960
#define __MemChecker2_x                                            0x699070
#define __MemChecker3_x                                            0x698FC0
#define __MemChecker4_x                                            0x8366D0
#define __EncryptPad0_x                                            0xBF54C0
#define __EncryptPad1_x                                            0xC53198
#define __EncryptPad2_x                                            0xC06048
#define __EncryptPad3_x                                            0xC05C48
#define __EncryptPad4_x                                            0xC43F30
#define __EncryptPad5_x                                            0x101A24C
#define __AC1_x                                                    0x7F2EB6
#define __AC2_x                                                    0x5C53FF
#define __AC3_x                                                    0x5CC28F
#define __AC4_x                                                    0x5D0100
#define __AC5_x                                                    0x5D62BF
#define __AC6_x                                                    0x5DA7F6
#define __AC7_x                                                    0x5C4E70
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1EB972C

// Direct Input
#define DI8__Main_x                                                0xF0F008
#define DI8__Keyboard_x                                            0xF0F00C
#define DI8__Mouse_x                                               0xF0F010
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
#define __do_loot_x                                                0x592B70
#define __DrawHandler_x                                            0x169CB60
#define __GroupCount_x                                             0xE5D5F2
#define __Guilds_x                                                 0xE63570
#define __gWorld_x                                                 0xE5D7E0
#define __HWnd_x                                                   0xF0F014
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
#define __ServerHost_x                                             0xE5D25B
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
#define __gfMaxZoomCameraDistance_x                                0xAB8B00
#define __gfMaxCameraDistance_x                                    0xAE60CC
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
#define pinstBandageTarget_x                                       0xE5D574
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
#define pinstModelPlayer_x                                         0xE5D56C
#define pinstPCData_x                                              0xE5D5C0
#define pinstRealEstateItems_x                                     0xF0E1C8
#define pinstSkillMgr_x                                            0xF0E298
#define pinstSpawnManager_x                                        0xF0D888
#define pinstSpellManager_x                                        0xF0E470
#define pinstSpellSets_x                                           0xF046A8
#define pinstStringTable_x                                         0xE5F7EC
#define pinstSwitchManager_x                                       0xE5CEA8
#define pinstTarget_x                                              0xE5D5A8
#define pinstTargetObject_x                                        0xE5D5B4
#define pinstTargetSwitch_x                                        0xE5D5CC
#define pinstTaskMember_x                                          0xDAADBC
#define pinstTrackTarget_x                                         0xE5D5B0
#define pinstTradeTarget_x                                         0xE5D364
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
//#define pinstCCharacterCreationWnd_x                               0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDAB8E8
#define pinstCChatWindowManager_x                                  0x101D120
#define pinstCClaimWnd_x                                           0x101D278
#define pinstCColorPickerWnd_x                                     0xDAB088
#define pinstCCombatAbilityWnd_x                                   0xDAB158
#define pinstCCombatSkillsSelectWnd_x                              0xDAB0A0
#define pinstCCompassWnd_x                                         0xDAB8F0
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
#define pinstCInvSlotMgr_x                                         0xDAB118
#define pinstCItemDisplayManager_x                                 0x1020B80
#define pinstCItemExpTransferWnd_x                                 0x1020CB4
#define pinstCItemOverflowWnd_x                                    0xDAB0D4
#define pinstCJournalCatWnd_x                                      0xDAB8C0
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
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
//#define pinstCPlayerCustomizationWnd_x                             0xDA8E24
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
//#define pinstCRewardSelectionWnd_x                               0x10205B0
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
#define pinstCTaskSomething_x                                      0xC7B680
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
#define __CastRay_x                                                0x58E090
#define __CastRay2_x                                               0x58E0E0
#define __ConvertItemTags_x                                        0x5A8C90
#define __CrashHandler_x                                           0x840040
#define __EQGetTime_x                                              0x8DE450
#define __ExecuteCmd_x                                             0x5869E0
#define __FixHeading_x                                             0x96EB40
#define __get_bearing_x                                            0x58DBD0
#define __get_melee_range_x                                        0x58E2D0
#define __GetAnimationCache_x                                      0x6FCE90
#define __GetGaugeValueFromEQ_x                                    0x7F16D0
#define __GetLabelFromEQ_x                                         0x7F2E40
#define __GetXTargetType_x                                         0x970610
#define __HandleMouseWheel_x                                       0x699120
#define __HeadingDiff_x                                            0x96EBB0
#define __HelpPath_x                                               0xF0C154
#define __LoadFrontEnd_x                                           0x694ED0
#define __NewUIINI_x                                               0x7F13A0
#define __pCrashHandler_x                                          0x1041F50
#define __ProcessGameEvents_x                                      0x5EB830
#define __ProcessMouseEvent_x                                      0x5EAFF0
#define __SaveColors_x                                             0x538280
#define __STMLToText_x                                             0x9121B0
#define __ToggleKeyRingItem_x                                      0x4FB660
#define CrashDetected_x                                            0x6969C0
#define DrawNetStatus_x                                            0x6178C0
#define Expansion_HoT_x                                            0xE6E0C4
#define Teleport_Table_Size_x                                      0xE5D100
#define Teleport_Table_x                                           0xE5D7E8
#define Util__FastTime_x                                           0x8DE010
#define wwsCrashReportCheckForUploader_x                           0x840B60
#define wwsCrashReportPlatformLaunchUploader_x                     0x843230

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48A840
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x493630
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x493410

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x53FCC0
#define AltAdvManager__IsAbilityReady_x                            0x53ED40
#define AltAdvManager__GetAAById_x                                 0x53EF40
#define AltAdvManager__CanTrainAbility_x                           0x53EFB0
#define AltAdvManager__CanSeeAbility_x                             0x53F1E0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C6000
#define CharacterZoneClient__HasSkill_x                            0x4D0BA0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D22C0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BA4A0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B6C20
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D4A20
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D4B00
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D4BE0
#define CharacterZoneClient__FindAffectSlot_x                      0x4BEF80
#define CharacterZoneClient__BardCastBard_x                        0x4C1BE0
#define CharacterZoneClient__GetMaxEffects_x                       0x4B6CF0
#define CharacterZoneClient__GetEffect_x                           0x4B6B60
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4BFF80
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C0050
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C00A0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C01F0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C03C0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6BF210

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6CCDF0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5F9F70
#define CButtonWnd__CButtonWnd_x                                   0x90E5C0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6EB800
#define CChatManager__InitContextMenu_x                            0x6E58A0
#define CChatManager__FreeChatWindow_x                             0x6EA710
#define CChatManager__GetLockedActiveChatWindow_x                  0x6EF0A0
#define CChatManager__SetLockedActiveChatWindow_x                  0x6EB5A0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x922E50
#define CContextMenu__dCContextMenu_x                              0x923080
#define CContextMenu__AddMenuItem_x                                0x923090
#define CContextMenu__RemoveMenuItem_x                             0x923390
#define CContextMenu__RemoveAllMenuItems_x                         0x9233B0
#define CContextMenu__CheckMenuItem_x                              0x923430
#define CContextMenu__SetMenuItem_x                                0x9232C0
#define CContextMenu__AddSeparator_x                               0x923220

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x9239D0
#define CContextMenuManager__RemoveMenu_x                          0x923A40
#define CContextMenuManager__PopupMenu_x                           0x923B00
#define CContextMenuManager__Flush_x                               0x923970
#define CContextMenuManager__GetMenu_x                             0x4956B0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8BEF50
#define CChatService__GetFriendName_x                              0x8BEF60

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6EBD70
#define CChatWindow__Clear_x                                       0x6ECDC0
#define CChatWindow__WndNotification_x                             0x6ED330

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x9202E0
#define CComboWnd__Draw_x                                          0x91F7E0
#define CComboWnd__GetCurChoice_x                                  0x920120
#define CComboWnd__GetListRect_x                                   0x91FC90
#define CComboWnd__GetTextRect_x                                   0x920340
#define CComboWnd__InsertChoice_x                                  0x91FE20
#define CComboWnd__SetColors_x                                     0x91FDF0
#define CComboWnd__SetChoice_x                                     0x9200F0
#define CComboWnd__GetItemCount_x                                  0x920130
#define CComboWnd__GetCurChoiceText_x                              0x920170

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6F5060
#define CContainerWnd__vftable_x                                   0xACCAB8
#define CContainerWnd__SetContainer_x                              0x6F65D0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x538040
#define CDisplay__GetClickedActor_x                                0x52B090
#define CDisplay__GetUserDefinedColor_x                            0x523770
#define CDisplay__GetWorldFilePath_x                               0x52CAE0
#define CDisplay__is3dON_x                                         0x527D60
#define CDisplay__ReloadUI_x                                       0x532200
#define CDisplay__WriteTextHD2_x                                   0x527B40
#define CDisplay__TrueDistance_x                                   0x52E740
#define CDisplay__SetViewActor_x                                   0x52A9E0
#define CDisplay__GetFloorHeight_x                                 0x527E20
#define CDisplay__SetRenderWindow_x                                0x526750
#define CDisplay__ToggleScreenshotMode_x                           0x52A4B0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x9423D0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x927540
#define CEditWnd__GetCharIndexPt_x                                 0x928430
#define CEditWnd__GetDisplayString_x                               0x9282D0
#define CEditWnd__GetHorzOffset_x                                  0x926B70
#define CEditWnd__GetLineForPrintableChar_x                        0x929560
#define CEditWnd__GetSelStartPt_x                                  0x9286D0
#define CEditWnd__GetSTMLSafeText_x                                0x9280F0
#define CEditWnd__PointFromPrintableChar_x                         0x929190
#define CEditWnd__SelectableCharFromPoint_x                        0x929300
#define CEditWnd__SetEditable_x                                    0x9287A0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5D9D20
#define CEverQuest__ClickedPlayer_x                                0x5CC070
#define CEverQuest__CreateTargetIndicator_x                        0x5E8B10
#define CEverQuest__DeleteTargetIndicator_x                        0x5E8BA0
#define CEverQuest__DoTellWindow_x                                 0x4E1370
#define CEverQuest__OutputTextToLog_x                              0x4E15A0
#define CEverQuest__DropHeldItemOnGround_x                         0x5C1930
#define CEverQuest__dsp_chat_x                                     0x4E1930
#define CEverQuest__trimName_x                                     0x5E5090
#define CEverQuest__Emote_x                                        0x5DA530
#define CEverQuest__EnterZone_x                                    0x5D4710
#define CEverQuest__GetBodyTypeDesc_x                              0x5DE930
#define CEverQuest__GetClassDesc_x                                 0x5DEF70
#define CEverQuest__GetClassThreeLetterCode_x                      0x5DF570
#define CEverQuest__GetDeityDesc_x                                 0x5E7460
#define CEverQuest__GetLangDesc_x                                  0x5DF730
#define CEverQuest__GetRaceDesc_x                                  0x5DEF50
#define CEverQuest__InterpretCmd_x                                 0x5E7A30
#define CEverQuest__LeftClickedOnPlayer_x                          0x5C5B20
#define CEverQuest__LMouseUp_x                                     0x5C3EA0
#define CEverQuest__RightClickedOnPlayer_x                         0x5C6400
#define CEverQuest__RMouseUp_x                                     0x5C4E30
#define CEverQuest__SetGameState_x                                 0x5C16C0
#define CEverQuest__UPCNotificationFlush_x                         0x5E4F90
#define CEverQuest__IssuePetCommand_x                              0x5E0B30
#define CEverQuest__ReportSuccessfulHit_x                          0x5DB250

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x707020
#define CGaugeWnd__CalcLinesFillRect_x                             0x707080
#define CGaugeWnd__Draw_x                                          0x706710

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ABAD0
#define CGuild__GetGuildName_x                                     0x4AABB0
#define CGuild__GetGuildIndex_x                                    0x4AAF40

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x722410

//CHotButton
#define CHotButton__SetButtonSize_x                                0x5FA330

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x72F3B0
#define CInvSlotMgr__MoveItem_x                                    0x72E110
#define CInvSlotMgr__SelectSlot_x                                  0x72F480

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x72C9C0
#define CInvSlot__SliderComplete_x                                 0x72A720
#define CInvSlot__GetItemBase_x                                    0x72A0A0
#define CInvSlot__UpdateItem_x                                     0x72A210

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x730DD0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7300A0
#define CInvSlotWnd__HandleLButtonUp_x                             0x730950

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7ED8D0
#define CItemDisplayWnd__UpdateStrings_x                           0x73FA00
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x739B60
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x73A080
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x73FF90
#define CItemDisplayWnd__AboutToShow_x                             0x73F650
#define CItemDisplayWnd__WndNotification_x                         0x7412A0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8252F0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x745390

// CLabel 
#define CLabel__Draw_x                                             0x74AE70

// CListWnd
#define CListWnd__CListWnd_x                                       0x8F89B0
#define CListWnd__dCListWnd_x                                      0x8F8CD0
#define CListWnd__AddColumn_x                                      0x8FCFD0
#define CListWnd__AddColumn1_x                                     0x8FD020
#define CListWnd__AddLine_x                                        0x8FD3B0
#define CListWnd__AddString_x                                      0x8FD1B0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8FCDA0
#define CListWnd__CalculateVSBRange_x                              0x8FCB80
#define CListWnd__ClearSel_x                                       0x8FDB90
#define CListWnd__ClearAllSel_x                                    0x8FDBF0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8FE5D0
#define CListWnd__Compare_x                                        0x8FC4C0
#define CListWnd__Draw_x                                           0x8F8DD0
#define CListWnd__DrawColumnSeparators_x                           0x8FB5A0
#define CListWnd__DrawHeader_x                                     0x8FBA10
#define CListWnd__DrawItem_x                                       0x8FBE00
#define CListWnd__DrawLine_x                                       0x8FB710
#define CListWnd__DrawSeparator_x                                  0x8FB640
#define CListWnd__EnableLine_x                                     0x8FAE80
#define CListWnd__EnsureVisible_x                                  0x8FE510
#define CListWnd__ExtendSel_x                                      0x8FDAC0
#define CListWnd__GetColumnMinWidth_x                              0x8FA9C0
#define CListWnd__GetColumnWidth_x                                 0x8FA930
#define CListWnd__GetCurSel_x                                      0x8FA2C0
#define CListWnd__GetItemAtPoint_x                                 0x8FB0F0
#define CListWnd__GetItemAtPoint1_x                                0x8FB160
#define CListWnd__GetItemData_x                                    0x8FA340
#define CListWnd__GetItemHeight_x                                  0x8FA700
#define CListWnd__GetItemIcon_x                                    0x8FA4D0
#define CListWnd__GetItemRect_x                                    0x8FAF70
#define CListWnd__GetItemText_x                                    0x8FA380
#define CListWnd__GetSelList_x                                     0x8FDC40
#define CListWnd__GetSeparatorRect_x                               0x8FB3A0
#define CListWnd__InsertLine_x                                     0x8FD7A0
#define CListWnd__RemoveLine_x                                     0x8FD8F0
#define CListWnd__SetColors_x                                      0x8FCB50
#define CListWnd__SetColumnJustification_x                         0x8FC880
#define CListWnd__SetColumnWidth_x                                 0x8FC7A0
#define CListWnd__SetCurSel_x                                      0x8FDA00
#define CListWnd__SetItemColor_x                                   0x8FE1D0
#define CListWnd__SetItemData_x                                    0x8FE190
#define CListWnd__SetItemText_x                                    0x8FDDC0
#define CListWnd__ShiftColumnSeparator_x                           0x8FC940
#define CListWnd__Sort_x                                           0x8FC640
#define CListWnd__ToggleSel_x                                      0x8FDA30

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x760550
#define CMapViewWnd__GetWorldCoordinates_x                         0x75EC60
#define CMapViewWnd__HandleLButtonDown_x                           0x75BCC0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x783730
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x784010
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x784550
#define CMerchantWnd__SelectRecoverySlot_x                         0x787390
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x782100
#define CMerchantWnd__SelectBuySellSlot_x                          0x78CF30
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x783360

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x88CBF0
#define CPacketScrambler__hton_x                                   0x88CBE0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x9177C0
#define CSidlManager__FindScreenPieceTemplate_x                    0x917BD0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9179C0
#define CSidlManager__CreateLabel_x                                0x7E4DA0
#define CSidlManager__CreateXWndFromTemplate_x                     0x91ACA0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x91AE80
#define CSidlManager__CreateXWnd_x                                 0x7E4CD0
#define CSidlManager__CreateHotButtonWnd_x                         0x7E5290

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x914330
#define CSidlScreenWnd__CalculateVSBRange_x                        0x914230
#define CSidlScreenWnd__ConvertToRes_x                             0x938C70
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x913CC0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x9139B0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x913A80
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x913B50
#define CSidlScreenWnd__DrawSidlPiece_x                            0x9147D0
#define CSidlScreenWnd__EnableIniStorage_x                         0x914CA0
#define CSidlScreenWnd__GetSidlPiece_x                             0x9149C0
#define CSidlScreenWnd__Init1_x                                    0x9135A0
#define CSidlScreenWnd__LoadIniInfo_x                              0x914CF0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x915830
#define CSidlScreenWnd__LoadSidlScreen_x                           0x9129A0
#define CSidlScreenWnd__StoreIniInfo_x                             0x9153B0
#define CSidlScreenWnd__StoreIniVis_x                              0x915710
#define CSidlScreenWnd__WndNotification_x                          0x9146E0
#define CSidlScreenWnd__GetChildItem_x                             0x914C20
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9043C0
#define CSidlScreenWnd__m_layoutCopy_x                             0x169BAA8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x65E430
#define CSkillMgr__GetSkillCap_x                                   0x65E610
#define CSkillMgr__GetNameToken_x                                  0x65DBC0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9247D0
#define CSliderWnd__SetValue_x                                     0x924640
#define CSliderWnd__SetNumTicks_x                                  0x9246A0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7EAB50

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x92B3F0
#define CStmlWnd__CalculateHSBRange_x                              0x92C460
#define CStmlWnd__CalculateVSBRange_x                              0x92C3D0
#define CStmlWnd__CanBreakAtCharacter_x                            0x9307A0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x931390
#define CStmlWnd__ForceParseNow_x                                  0x92B990
#define CStmlWnd__GetNextTagPiece_x                                0x930700
#define CStmlWnd__GetSTMLText_x                                    0x4EF6E0
#define CStmlWnd__GetVisibleText_x                                 0x92B9B0
#define CStmlWnd__InitializeWindowVariables_x                      0x9311E0
#define CStmlWnd__MakeStmlColorTag_x                               0x92AB80
#define CStmlWnd__MakeWndNotificationTag_x                         0x92ABF0
#define CStmlWnd__SetSTMLText_x                                    0x929C50
#define CStmlWnd__StripFirstSTMLLines_x                            0x9324E0
#define CStmlWnd__UpdateHistoryString_x                            0x9315A0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x935B50
#define CTabWnd__DrawCurrentPage_x                                 0x936170
#define CTabWnd__DrawTab_x                                         0x935F40
#define CTabWnd__GetCurrentPage_x                                  0x9353B0
#define CTabWnd__GetPageInnerRect_x                                0x9355F0
#define CTabWnd__GetTabInnerRect_x                                 0x935530
#define CTabWnd__GetTabRect_x                                      0x9353E0
#define CTabWnd__InsertPage_x                                      0x9357E0
#define CTabWnd__SetPage_x                                         0x935670
#define CTabWnd__SetPageRect_x                                     0x935A90
#define CTabWnd__UpdatePage_x                                      0x935E00
#define CTabWnd__GetPageFromTabIndex_x                             0x935E80
#define CTabWnd__GetCurrentTabIndex_x                              0x9353A0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x7457F0
#define CPageWnd__SetTabText_x                                     0x9427E0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A5630

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x901210
#define CTextureFont__GetTextExtent_x                              0x9013D0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x691D10
#define CHtmlComponentWnd__ValidateUri_x                           0x723E00
#define CHtmlWnd__SetClientCallbacks_x                             0x5FF300
#define CHtmlWnd__AddObserver_x                                    0x5FF320
#define CHtmlWnd__RemoveObserver_x                                 0x5FF380
#define Window__getProgress_x                                      0x83DCB0
#define Window__getStatus_x                                        0x83DCD0
#define Window__getURI_x                                           0x83DCE0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x93ED60

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8EE130

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4ACD80
#define CXStr__CXStr1_x                                            0x47B0A0
#define CXStr__CXStr3_x                                            0x8DA540
#define CXStr__dCXStr_x                                            0x472260
#define CXStr__operator_equal_x                                    0x8DA770
#define CXStr__operator_equal1_x                                   0x8DA7B0
#define CXStr__operator_plus_equal1_x                              0x8DB240

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x922A60
#define CXWnd__BringToTop_x                                        0x907B60
#define CXWnd__Center_x                                            0x9076E0
#define CXWnd__ClrFocus_x                                          0x907520
#define CXWnd__Destroy_x                                           0x9075C0
#define CXWnd__DoAllDrawing_x                                      0x903B50
#define CXWnd__DrawChildren_x                                      0x903B20
#define CXWnd__DrawColoredRect_x                                   0x903FB0
#define CXWnd__DrawTooltip_x                                       0x902680
#define CXWnd__DrawTooltipAtPoint_x                                0x902740
#define CXWnd__GetBorderFrame_x                                    0x903E10
#define CXWnd__GetChildWndAt_x                                     0x907C00
#define CXWnd__GetClientClipRect_x                                 0x905DF0
#define CXWnd__GetScreenClipRect_x                                 0x905EB0
#define CXWnd__GetScreenRect_x                                     0x906070
#define CXWnd__GetTooltipRect_x                                    0x904000
#define CXWnd__GetWindowTextA_x                                    0x496D40
#define CXWnd__IsActive_x                                          0x90AAC0
#define CXWnd__IsDescendantOf_x                                    0x906A70
#define CXWnd__IsReallyVisible_x                                   0x906AA0
#define CXWnd__IsType_x                                            0x908250
#define CXWnd__Move_x                                              0x906B10
#define CXWnd__Move1_x                                             0x906BC0
#define CXWnd__ProcessTransition_x                                 0x907690
#define CXWnd__Refade_x                                            0x906E90
#define CXWnd__Resize_x                                            0x907130
#define CXWnd__Right_x                                             0x907920
#define CXWnd__SetFocus_x                                          0x9074E0
#define CXWnd__SetFont_x                                           0x907550
#define CXWnd__SetKeyTooltip_x                                     0x908080
#define CXWnd__SetMouseOver_x                                      0x904F60
#define CXWnd__StartFade_x                                         0x906940
#define CXWnd__GetChildItem_x                                      0x907D70
#define CXWnd__SetParent_x                                         0x906810

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x939D40

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x90AB00
#define CXWndManager__DrawWindows_x                                0x90AB20
#define CXWndManager__GetKeyboardFlags_x                           0x90D290
#define CXWndManager__HandleKeyboardMsg_x                          0x90CE90
#define CXWndManager__RemoveWnd_x                                  0x90D4E0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x90DA30

// CDBStr
#define CDBStr__GetString_x                                        0x522730

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B7BD0
#define EQ_Character__Cur_HP_x                                     0x4CDC20
#define EQ_Character__Cur_Mana_x                                   0x4D50E0
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BAAE0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AE9C0
#define EQ_Character__GetFocusRangeModifier_x                      0x4AEB10
#define EQ_Character__GetHPRegen_x                                 0x4DAA90
#define EQ_Character__GetEnduranceRegen_x                          0x4DB0A0
#define EQ_Character__GetManaRegen_x                               0x4DB4E0
#define EQ_Character__Max_Endurance_x                              0x624F70
#define EQ_Character__Max_HP_x                                     0x4CDA50
#define EQ_Character__Max_Mana_x                                   0x624D70
#define EQ_Character__doCombatAbility_x                            0x627120
#define EQ_Character__UseSkill_x                                   0x4DD2F0
#define EQ_Character__GetConLevel_x                                0x61E5F0
#define EQ_Character__IsExpansionFlag_x                            0x585170
#define EQ_Character__TotalEffect_x                                0x4C1160
#define EQ_Character__GetPCSpellAffect_x                           0x4BB6D0
#define EQ_Character__SpellDuration_x                              0x4BB200
#define EQ_Character__FindItemByRecord_x                           0x4D3230
#define EQ_Character__GetAdjustedSkill_x                           0x4D0960
#define EQ_Character__GetBaseSkill_x                               0x4D1900
#define EQ_Character__CanUseItem_x                                 0x4D53F0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8ABD60

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x63AE50

//PcClient
#define PcClient__PcClient_x                                       0x61BEC0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B5980
#define CCharacterListWnd__EnterWorld_x                            0x4B53C0
#define CCharacterListWnd__Quit_x                                  0x4B50D0
#define CCharacterListWnd__UpdateList_x                            0x4B5550

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x600510
#define EQ_Item__CreateItemTagString_x                             0x886AE0
#define EQ_Item__IsStackable_x                                     0x88B0C0
#define EQ_Item__GetImageNum_x                                     0x8883F0
#define EQ_Item__CreateItemClient_x                                0x5FF6E0
#define EQ_Item__GetItemValue_x                                    0x889490
#define EQ_Item__ValueSellMerchant_x                               0x88C790
#define EQ_Item__IsKeyRingItem_x                                   0x88AA10
#define EQ_Item__CanGoInBag_x                                      0x600630
#define EQ_Item__GetMaxItemCount_x                                 0x8897B0
#define EQ_Item__GetHeldItem_x                                     0x8882C0
#define EQ_Item__GetAugmentFitBySlot_x                             0x886520

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x5409E0
#define EQ_LoadingS__Array_x                                       0xBDD2D0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x6258D0
#define EQ_PC__GetAlternateAbilityId_x                             0x8959B0
#define EQ_PC__GetCombatAbility_x                                  0x896020
#define EQ_PC__GetCombatAbilityTimer_x                             0x896090
#define EQ_PC__GetItemRecastTimer_x                                0x6276A0
#define EQ_PC__HasLoreItem_x                                       0x61ED60
#define EQ_PC__AlertInventoryChanged_x                             0x61E0C0
#define EQ_PC__GetPcZoneClient_x                                   0x6495A0
#define EQ_PC__RemoveMyAffect_x                                    0x62A7D0
#define EQ_PC__GetKeyRingItems_x                                   0x896930
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8966B0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x896C20

// EQItemList 
#define EQItemList__EQItemList_x                                   0x58B5F0
#define EQItemList__add_object_x                                   0x5B6FA0
#define EQItemList__add_item_x                                     0x58BC00
#define EQItemList__delete_item_x                                  0x58BC50
#define EQItemList__FreeItemList_x                                 0x58BB50

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x51FDA0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x63C6D0
#define EQPlayer__dEQPlayer_x                                      0x62FDE0
#define EQPlayer__DoAttack_x                                       0x644280
#define EQPlayer__EQPlayer_x                                       0x630490
#define EQPlayer__SetNameSpriteState_x                             0x634700
#define EQPlayer__SetNameSpriteTint_x                              0x6355D0
#define PlayerBase__HasProperty_j_x                                0x96CF10
#define EQPlayer__IsTargetable_x                                   0x96D3B0
#define EQPlayer__CanSee_x                                         0x96D210
#define EQPlayer__CanSee1_x                                        0x96D2E0
#define PlayerBase__GetVisibilityLineSegment_x                     0x96CFD0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x647050
#define PlayerZoneClient__GetLevel_x                               0x6495E0
#define PlayerZoneClient__IsValidTeleport_x                        0x5B80F0
#define PlayerZoneClient__LegalPlayerRace_x                        0x539E20

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x63F3C0
#define EQPlayerManager__GetSpawnByName_x                          0x63F3E0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x63F470

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x603EB0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x603EF0
#define KeypressHandler__ClearCommandStateArray_x                  0x6052E0
#define KeypressHandler__HandleKeyDown_x                           0x605300
#define KeypressHandler__HandleKeyUp_x                             0x6053A0
#define KeypressHandler__SaveKeymapping_x                          0x605780

// MapViewMap 
#define MapViewMap__Clear_x                                        0x75C3E0
#define MapViewMap__SaveEx_x                                       0x75F780
#define MapViewMap__SetZoom_x                                      0x763E50

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8A9C40

// StringTable 
#define StringTable__getString_x                                   0x8A4BC0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x62A440
#define PcZoneClient__RemovePetEffect_x                            0x62AA70
#define PcZoneClient__HasAlternateAbility_x                        0x624BB0
#define PcZoneClient__GetCurrentMod_x                              0x4E0260
#define PcZoneClient__GetModCap_x                                  0x4E0160
#define PcZoneClient__CanEquipItem_x                               0x625260
#define PcZoneClient__GetItemByID_x                                0x627B10
#define PcZoneClient__GetItemByItemClass_x                         0x627BA0
#define PcZoneClient__RemoveBuffEffect_x                           0x62AA90
#define PcZoneClient__BandolierSwap_x                              0x625E90

//Doors
#define EQSwitch__UseSwitch_x                                      0x5BCCC0

//IconCache
#define IconCache__GetIcon_x                                       0x6FC720

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6F4200
#define CContainerMgr__CloseContainer_x                            0x6F44D0
#define CContainerMgr__OpenExperimentContainer_x                   0x6F4F50

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7B7520

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5F8750

//CLootWnd
#define CLootWnd__LootAll_x                                        0x752800
#define CLootWnd__RequestLootSlot_x                                0x751BB0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x558DB0
#define EQ_Spell__SpellAffects_x                                   0x559220
#define EQ_Spell__SpellAffectBase_x                                0x558FE0
#define EQ_Spell__IsStackable_x                                    0x4C5910
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C5790
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B2EF0
#define EQ_Spell__IsSPAStacking_x                                  0x55A050
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x559570
#define EQ_Spell__IsNoRemove_x                                     0x4C58F0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x55A060
#define __IsResEffectSpell_x                                       0x4C4CA0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4A9770

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8B4310

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7FCBF0
#define CTargetWnd__WndNotification_x                              0x7FC480
#define CTargetWnd__RefreshTargetBuffs_x                           0x7FC750
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x7FB5E0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x8012D0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x554350
#define EqSoundManager__PlayScriptMp3_x                            0x5544B0
#define EqSoundManager__SoundAssistPlay_x                          0x661F10
#define EqSoundManager__WaveInstancePlay_x                         0x661480

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x511730

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x9261B0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x548660
#define CAltAbilityData__GetMercMaxRank_x                          0x548600
#define CAltAbilityData__GetMaxRank_x                              0x53DBF0

//CTargetRing
#define CTargetRing__Cast_x                                        0x5F6860

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C5770
#define CharacterBase__CreateItemGlobalIndex_x                     0x4F7B60
#define CharacterBase__CreateItemIndex_x                           0x5FE940
#define CharacterBase__GetItemPossession_x                         0x4B2DA0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8BC9B0
#define CharacterBase__GetEffectId_x                               0x4C5720

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6DC220
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6DCA40

//messages
#define msg_spell_worn_off_x                                       0x57D780
#define msg_new_text_x                                             0x572910
#define __msgTokenTextParam_x                                      0x57FDD0
#define msgTokenText_x                                             0x580020

//SpellManager
#define SpellManager__vftable_x                                    0xAA7838
#define SpellManager__SpellManager_x                               0x665240
#define Spellmanager__LoadTextSpells_x                             0x665B10
#define SpellManager__GetSpellByGroupAndRank_x                     0x665410

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x970F00

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4F8210
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5837F0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x617720
#define ItemGlobalIndex__IsValidIndex_x                            0x4F8270

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8B4C50
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8B4ED0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x74B1C0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6F8970
#define CCursorAttachment__Deactivate_x                            0x6F9950

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x938040
#define CEQSuiteTextureLoader__GetTexture_x                        0x937D00

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4F5210

//IString
#define IString__Append_x                                          0x4E9790

//Camera
#define CDisplay__cameraType_x                                     0xDAB15C
#define EverQuest__Cameras_x                                       0xE6E400

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x4FD8E0
#define LootFiltersManager__GetItemFilterData_x                    0x4FD1D0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x4FD200
#define LootFiltersManager__SetItemLootFilter_x                    0x4FD420

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7A54F0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x976BE0
#define CResolutionHandler__GetWindowedStyle_x                     0x65CD10

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6F0F10

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8C6E20

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x711210
#define CGroupWnd__UpdateDisplay_x                                 0x710570

//ItemBase
#define ItemBase__IsLore_x                                         0x88AA70

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";

