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
#define __ExpectedVersionDate                                     "Jun 21 2019"
#define __ExpectedVersionTime                                     "12:32:16"
#define __ActualVersionDate_x                                      0xAD644C
#define __ActualVersionTime_x                                      0xAD6440
#define __ActualVersionBuild_x                                     0xAD6EE4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x61A5D0
#define __MemChecker1_x                                            0x8F0850
#define __MemChecker2_x                                            0x6A9BD0
#define __MemChecker3_x                                            0x6A9B20
#define __MemChecker4_x                                            0x847850
#define __EncryptPad0_x                                            0xC0B998
#define __EncryptPad1_x                                            0xC69998
#define __EncryptPad2_x                                            0xC1C210
#define __EncryptPad3_x                                            0xC1BE10
#define __EncryptPad4_x                                            0xC5A188
#define __EncryptPad5_x                                            0xF34410
#define __AC1_x                                                    0x8040C6
#define __AC2_x                                                    0x5D40DF
#define __AC3_x                                                    0x5DB7EF
#define __AC4_x                                                    0x5DF6D0
#define __AC5_x                                                    0x5E5940
#define __AC6_x                                                    0x5E9FD6
#define __AC7_x                                                    0x5D3B50
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1F1CCC

// Direct Input
#define DI8__Main_x                                                0xF34430
#define DI8__Keyboard_x                                            0xF34434
#define DI8__Mouse_x                                               0xF339F0
#define DI8__Mouse_Copy_x                                          0xE8F0CC
#define DI8__Mouse_Check_x                                         0xF34764
#define __AutoSkillArray_x                                         0xE8FFE4
#define __Attack_x                                                 0xF2DDFB
#define __Autofire_x                                               0xF2DDFC
#define __BindList_x                                               0xBFA3F0
#define g_eqCommandStates_x                                        0xBFB168
#define __Clicks_x                                                 0xE8F184
#define __CommandList_x                                            0xBFBD28
#define __CurrentMapLabel_x                                        0x104EEA4
#define __CurrentSocial_x                                          0xBE4730
#define __DoAbilityList_x                                          0xEC591C
#define __do_loot_x                                                0x5A07B0
#define __DrawHandler_x                                            0x16CB870
#define __GroupCount_x                                             0xE81942
#define __Guilds_x                                                 0xE858D8
#define __gWorld_x                                                 0xE81B60
#define __HWnd_x                                                   0xF339F4
#define __heqmain_x                                                0x103EA4C
#define __InChatMode_x                                             0xE8F0B4
#define __LastTell_x                                               0xE91018
#define __LMouseHeldTime_x                                         0xE8F1F0
#define __Mouse_x                                                  0xF3441C
#define __MouseLook_x                                              0xE8F14A
#define __MouseEventTime_x                                         0xF2E8DC
#define __gpbCommandEvent_x                                        0xE7F368
#define __NetStatusToggle_x                                        0xE8F14D
#define __PCNames_x                                                0xE905C8
#define __RangeAttackReady_x                                       0xE902C8
#define __RMouseHeldTime_x                                         0xE8F1EC
#define __RunWalkState_x                                           0xE8F0B8
#define __ScreenMode_x                                             0xDCD4F8
#define __ScreenX_x                                                0xE8F06C
#define __ScreenY_x                                                0xE8F068
#define __ScreenXMax_x                                             0xE8F070
#define __ScreenYMax_x                                             0xE8F074
#define __ServerHost_x                                             0xE7F59B
#define __ServerName_x                                             0xEC58DC
#define __ShiftKeyDown_x                                           0xE8F744
#define __ShowNames_x                                              0xE90484
#define __Socials_x                                                0xEC59DC
#define __SubscriptionType_x                                       0x1090A38
#define __TargetAggroHolder_x                                      0x1051858
#define __ZoneType_x                                               0xE8F548
#define __GroupAggro_x                                             0x1051898
#define __LoginName_x                                              0xF340B4
#define __Inviter_x                                                0xF2DD78
#define __AttackOnAssist_x                                         0xE90440
#define __UseTellWindows_x                                         0xE90764
#define __gfMaxZoomCameraDistance_x                                0xACB8D0
#define __gfMaxCameraDistance_x                                    0xAF8DE8
#define __pulAutoRun_x                                             0xE8F168
#define __pulForward_x                                             0xE9079C
#define __pulBackward_x                                            0xE907A0
#define __pulTurnRight_x                                           0xE907A4
#define __pulTurnLeft_x                                            0xE907A8
#define __pulStrafeLeft_x                                          0xE907AC
#define __pulStrafeRight_x                                         0xE907B0

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE81C70
#define instEQZoneInfo_x                                           0xE8F340
#define pinstActiveBanker_x                                        0xE7F400
#define pinstActiveCorpse_x                                        0xE7F3F8
#define pinstActiveGMaster_x                                       0xE7F3FC
#define pinstActiveMerchant_x                                      0xE7F3F4
#define pinstAltAdvManager_x                                       0xDCDF40
#define pinstBandageTarget_x                                       0xE7F410
#define pinstCamActor_x                                            0xDCD4EC
#define pinstCDBStr_x                                              0xDCCC6C
#define pinstCDisplay_x                                            0xE81B64
#define pinstCEverQuest_x                                          0x103DA3C
#define pinstEverQuestInfo_x                                       0xE8F060
#define pinstCharData_x                                            0xE7F920
#define pinstCharSpawn_x                                           0xE7F448
#define pinstControlledMissile_x                                   0xE7F914
#define pinstControlledPlayer_x                                    0xE7F448
#define pinstCResolutionHandler_x                                  0x16CBAA0
#define pinstCSidlManager_x                                        0x16CAA3C
#define pinstCXWndManager_x                                        0x16CAA30
#define instDynamicZone_x                                          0xE857B0
#define pinstDZMember_x                                            0xE858C0
#define pinstDZTimerInfo_x                                         0xE858C4
#define pinstEqLogin_x                                             0xF33A00
#define instEQMisc_x                                               0xDCCBB0
#define pinstEQSoundManager_x                                      0xDCEE68
#define pinstEQSpellStrings_x                                      0xC8E3C0
#define instExpeditionLeader_x                                     0xE857FA
#define instExpeditionName_x                                       0xE8583A
#define pinstGroup_x                                               0xE8193E
#define pinstImeManager_x                                          0x16CAA34
#define pinstLocalPlayer_x                                         0xE7F3F0
#define pinstMercenaryData_x                                       0xF303CC
#define pinstMercenaryStats_x                                      0x10519A4
#define pinstModelPlayer_x                                         0xE7F408
#define pinstPCData_x                                              0xE7F920
#define pinstSkillMgr_x                                            0xF32540
#define pinstSpawnManager_x                                        0xF30FE8
#define pinstSpellManager_x                                        0xF32760
#define pinstSpellSets_x                                           0xF26A24
#define pinstStringTable_x                                         0xE81B68
#define pinstSwitchManager_x                                       0xE7F210
#define pinstTarget_x                                              0xE7F444
#define pinstTargetObject_x                                        0xE7F494
#define pinstTargetSwitch_x                                        0xE7F91C
#define pinstTaskMember_x                                          0xDCCA44
#define pinstTrackTarget_x                                         0xE7F44C
#define pinstTradeTarget_x                                         0xE7F404
#define instTributeActive_x                                        0xDCCBD1
#define pinstViewActor_x                                           0xDCD4E8
#define pinstWorldData_x                                           0xE81B54
#define pinstZoneAddr_x                                            0xE8F5E0
#define pinstPlayerPath_x                                          0xF31080
#define pinstTargetIndicator_x                                     0xF329C8
#define EQObject_Top_x                                             0xE7F36C
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDCCFA4
#define pinstCAchievementsWnd_x                                    0xDCCF88
#define pinstCActionsWnd_x                                         0xDCD008
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDCD4D0
#define pinstCAdvancedLootWnd_x                                    0xDCCFFC
#define pinstCAdventureLeaderboardWnd_x                            0x1048678
#define pinstCAdventureRequestWnd_x                                0x1048728
#define pinstCAdventureStatsWnd_x                                  0x10487D8
#define pinstCAggroMeterWnd_x                                      0xDCD52C
#define pinstCAlarmWnd_x                                           0xDCCD0C
#define pinstCAlertHistoryWnd_x                                    0xDCCF34
#define pinstCAlertStackWnd_x                                      0xDCD528
#define pinstCAlertWnd_x                                           0xDCD538
#define pinstCAltStorageWnd_x                                      0x1048B38
#define pinstCAudioTriggersWindow_x                                0xC806F0
#define pinstCAuraWnd_x                                            0xDCD520
#define pinstCAvaZoneWnd_x                                         0xDCCF38
#define pinstCBandolierWnd_x                                       0xDCD550
#define pinstCBankWnd_x                                            0xDCCF54
#define pinstCBarterMerchantWnd_x                                  0x1049D78
#define pinstCBarterSearchWnd_x                                    0x1049E28
#define pinstCBarterWnd_x                                          0x1049ED8
#define pinstCBazaarConfirmationWnd_x                              0xDCD524
#define pinstCBazaarSearchWnd_x                                    0xDCD4A0
#define pinstCBazaarWnd_x                                          0xDCD574
#define pinstCBlockedBuffWnd_x                                     0xDCCF3C
#define pinstCBlockedPetBuffWnd_x                                  0xDCCF60
#define pinstCBodyTintWnd_x                                        0xDCD50C
#define pinstCBookWnd_x                                            0xDCD578
#define pinstCBreathWnd_x                                          0xDCCFB4
#define pinstCBuffWindowNORMAL_x                                   0xDCCF10
#define pinstCBuffWindowSHORT_x                                    0xDCCF14
#define pinstCBugReportWnd_x                                       0xDCCFA8
#define pinstCButtonWnd_x                                          0x16CACA0
#define pinstCCastingWnd_x                                         0xDCCF9C
#define pinstCCastSpellWnd_x                                       0xDCD4BC
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDCCFB8
#define pinstCChatWindowManager_x                                  0x104A998
#define pinstCClaimWnd_x                                           0x104AAF0
#define pinstCColorPickerWnd_x                                     0xDCCFE0
#define pinstCCombatAbilityWnd_x                                   0xDCD530
#define pinstCCombatSkillsSelectWnd_x                              0xDCD000
#define pinstCCompassWnd_x                                         0xDCD4E0
#define pinstCConfirmationDialog_x                                 0x104F9F0
#define pinstCContainerMgr_x                                       0xDCCFA0
#define pinstCContextMenuManager_x                                 0x16CA9F0
#define pinstCCursorAttachment_x                                   0xDCCF90
#define pinstCDynamicZoneWnd_x                                     0x104B0B8
#define pinstCEditLabelWnd_x                                       0xDCD58C
#define pinstCEQMainWnd_x                                          0x104B300
#define pinstCEventCalendarWnd_x                                   0xDCCFC0
#define pinstCExtendedTargetWnd_x                                  0xDCD518
#define pinstCFacePick_x                                           0xDCCFD8
#define pinstCFactionWnd_x                                         0xDCCF98
#define pinstCFellowshipWnd_x                                      0x104B500
#define pinstCFileSelectionWnd_x                                   0xDCCFEC
#define pinstCFindItemWnd_x                                        0xDCD594
#define pinstCFindLocationWnd_x                                    0x104B658
#define pinstCFriendsWnd_x                                         0xDCD494
#define pinstCGemsGameWnd_x                                        0xDCD570
#define pinstCGiveWnd_x                                            0xDCD598
#define pinstCGroupSearchFiltersWnd_x                              0xDCD540
#define pinstCGroupSearchWnd_x                                     0x104BA50
#define pinstCGroupWnd_x                                           0x104BB00
#define pinstCGuildBankWnd_x                                       0xE90424
#define pinstCGuildCreationWnd_x                                   0x104BC60
#define pinstCGuildMgmtWnd_x                                       0x104BD10
#define pinstCharacterCreation_x                                   0xDCD534
#define pinstCHelpWnd_x                                            0xDCD4D8
#define pinstCHeritageSelectionWnd_x                               0xDCCFE8
#define pinstCHotButtonWnd_x                                       0x104DE68
#define pinstCHotButtonWnd1_x                                      0x104DE68
#define pinstCHotButtonWnd2_x                                      0x104DE6C
#define pinstCHotButtonWnd3_x                                      0x104DE70
#define pinstCHotButtonWnd4_x                                      0x104DE74
#define pinstCIconSelectionWnd_x                                   0xDCCF74
#define pinstCInspectWnd_x                                         0xDCCF80
#define pinstCInventoryWnd_x                                       0xDCD560
#define pinstCInvSlotMgr_x                                         0xDCCF58
#define pinstCItemDisplayManager_x                                 0x104E3F8
#define pinstCItemExpTransferWnd_x                                 0x104E52C
#define pinstCItemOverflowWnd_x                                    0xDCD4A8
#define pinstCJournalCatWnd_x                                      0xDCD084
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDCCFD4
#define pinstCKeyRingWnd_x                                         0xDCCF2C
#define pinstCLargeDialogWnd_x                                     0x1050670
#define pinstCLayoutCopyWnd_x                                      0x104E878
#define pinstCLFGuildWnd_x                                         0x104E928
#define pinstCLoadskinWnd_x                                        0xDCD580
#define pinstCLootFiltersCopyWnd_x                                 0xC9C9B8
#define pinstCLootFiltersWnd_x                                     0xDCD564
#define pinstCLootSettingsWnd_x                                    0xDCD588
#define pinstCLootWnd_x                                            0xDCCFCC
#define pinstCMailAddressBookWnd_x                                 0xDCCF64
#define pinstCMailCompositionWnd_x                                 0xDCCF44
#define pinstCMailIgnoreListWnd_x                                  0xDCCF68
#define pinstCMailWnd_x                                            0xDCCF18
#define pinstCManageLootWnd_x                                      0xDCE3F0
#define pinstCMapToolbarWnd_x                                      0xDCD568
#define pinstCMapViewWnd_x                                         0xDCD548
#define pinstCMarketplaceWnd_x                                     0xDCCFC4
#define pinstCMerchantWnd_x                                        0xDCD07C
#define pinstCMIZoneSelectWnd_x                                    0x104F160
#define pinstCMusicPlayerWnd_x                                     0xDCCF20
#define pinstCNameChangeMercWnd_x                                  0xDCD4D4
#define pinstCNameChangePetWnd_x                                   0xDCD4C4
#define pinstCNameChangeWnd_x                                      0xDCCFB0
#define pinstCNoteWnd_x                                            0xDCD4CC
#define pinstCObjectPreviewWnd_x                                   0xDCCFE4
#define pinstCOptionsWnd_x                                         0xDCD56C
#define pinstCPetInfoWnd_x                                         0xDCCF48
#define pinstCPetitionQWnd_x                                       0xDCD498
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDCD508
#define pinstCPlayerWnd_x                                          0xDCD584
#define pinstCPopupWndManager_x                                    0x104F9F0
#define pinstCProgressionSelectionWnd_x                            0x104FAA0
#define pinstCPurchaseGroupWnd_x                                   0xDCD48C
#define pinstCPurchaseWnd_x                                        0xDCCFF0
#define pinstCPvPLeaderboardWnd_x                                  0x104FB50
#define pinstCPvPStatsWnd_x                                        0x104FC00
#define pinstCQuantityWnd_x                                        0xDCCF7C
#define pinstCRaceChangeWnd_x                                      0xDCCFD0
#define pinstCRaidOptionsWnd_x                                     0xDCD544
#define pinstCRaidWnd_x                                            0xDCCF84
#define pinstCRealEstateItemsWnd_x                                 0xDCCF8C
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDCCFBC
#define pinstCRealEstateManageWnd_x                                0xDCD590
#define pinstCRealEstateNeighborhoodWnd_x                          0xDCCF24
#define pinstCRealEstatePlotSearchWnd_x                            0xDCCF4C
#define pinstCRealEstatePurchaseWnd_x                              0xDCCF6C
#define pinstCRespawnWnd_x                                         0xDCD53C
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDCD51C
#define pinstCSendMoneyWnd_x                                       0xDCCF1C
#define pinstCServerListWnd_x                                      0xDCCF30
#define pinstCSkillsSelectWnd_x                                    0xDCCFDC
#define pinstCSkillsWnd_x                                          0xDCCFC8
#define pinstCSocialEditWnd_x                                      0xDCCF94
#define pinstCSocialWnd_x                                          0xDCD510
#define pinstCSpellBookWnd_x                                       0xDCD514
#define pinstCStoryWnd_x                                           0xDCD4DC
#define pinstCTargetOfTargetWnd_x                                  0x1051A28
#define pinstCTargetWnd_x                                          0xDCCF40
#define pinstCTaskOverlayWnd_x                                     0xDCCF50
#define pinstCTaskSelectWnd_x                                      0x1051B80
#define pinstCTaskManager_x                                        0xC9D308
#define pinstCTaskTemplateSelectWnd_x                              0x1051C30
#define pinstCTaskWnd_x                                            0x1051CE0
#define pinstCTextEntryWnd_x                                       0xDCD4E4
#define pinstCTimeLeftWnd_x                                        0xDCCFF4
#define pinstCTipWndCONTEXT_x                                      0x1051EE4
#define pinstCTipWndOFDAY_x                                        0x1051EE0
#define pinstCTitleWnd_x                                           0x1051F90
#define pinstCTrackingWnd_x                                        0xDCCF5C
#define pinstCTradeskillWnd_x                                      0x10520F8
#define pinstCTradeWnd_x                                           0xDCD504
#define pinstCTrainWnd_x                                           0xDCCF78
#define pinstCTributeBenefitWnd_x                                  0x10522F8
#define pinstCTributeMasterWnd_x                                   0x10523A8
#define pinstCTributeTrophyWnd_x                                   0x1052458
#define pinstCVideoModesWnd_x                                      0xDCD54C
#define pinstCVoiceMacroWnd_x                                      0xF33130
#define pinstCVoteResultsWnd_x                                     0xDCD490
#define pinstCVoteWnd_x                                            0xDCCFF8
#define pinstCWebManager_x                                         0xF337AC
#define pinstCZoneGuideWnd_x                                       0xDCD59C
#define pinstCZonePathWnd_x                                        0xDCCF28

#define pinstEQSuiteTextureLoader_x                                0xC6B480
#define pinstItemIconCache_x                                       0x104B2B8
#define pinstLootFiltersManager_x                                  0xC9CA68
#define pinstRewardSelectionWnd_x                                  0x1050348

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC1BE00
#define __CastRay_x                                                0x59BC10
#define __CastRay2_x                                               0x59BC60
#define __ConvertItemTags_x                                        0x5B7480
#define __CrashHandler_x                                           0x851190
#define __CleanItemTags_x                                          0x477AB0
#define __DoesFileExist_x                                          0x8F38F0
#define __EQGetTime_x                                              0x8F0330
#define __ExecuteCmd_x                                             0x5944E0
#define __FixHeading_x                                             0x9801E0
#define __GameLoop_x                                               0x6A9090
#define __get_bearing_x                                            0x59B760
#define __get_melee_range_x                                        0x59BE50
#define __GetAnimationCache_x                                      0x70DFC0
#define __GetGaugeValueFromEQ_x                                    0x802560
#define __GetLabelFromEQ_x                                         0x804050
#define __GetXTargetType_x                                         0x981CB0
#define __HandleMouseWheel_x                                       0x6A9C80
#define __HeadingDiff_x                                            0x980250
#define __HelpPath_x                                               0xF2E4CC
#define __LoadFrontEnd_x                                           0x6A5B60
#define __NewUIINI_x                                               0x802230
#define __pCrashHandler_x                                          0x106F860
#define __ProcessGameEvents_x                                      0x5FB820
#define __ProcessMouseEvent_x                                      0x5FAFE0
#define __SaveColors_x                                             0x5453E0
#define __STMLToText_x                                             0x923440
#define __ToggleKeyRingItem_x                                      0x508980
#define CMemoryMappedFile__SetFile_x                               0xA5A490
#define CrashDetected_x                                            0x6A75C0
#define DrawNetStatus_x                                            0x627AC0
#define Expansion_HoT_x                                            0xE9042C
#define Teleport_Table_Size_x                                      0xE7F454
#define Teleport_Table_x                                           0xE7F928
#define Util__FastTime_x                                           0x8EFEF0
#define wwsCrashReportCheckForUploader_x                           0x851F90
#define wwsCrashReportPlatformLaunchUploader_x                     0x854650

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48B820
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4946E0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4944B0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x48ED90
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x48E1E0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x54CE90
#define AltAdvManager__IsAbilityReady_x                            0x54BDE0
#define AltAdvManager__GetAAById_x                                 0x54BFE0
#define AltAdvManager__CanTrainAbility_x                           0x54C050
#define AltAdvManager__CanSeeAbility_x                             0x54C3B0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C7520
#define CharacterZoneClient__HasSkill_x                            0x4D23F0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D3B10
#define CharacterZoneClient__IsStackBlocked_x                      0x4BBB30
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B8270
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D64A0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D6580
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D6660
#define CharacterZoneClient__FindAffectSlot_x                      0x4C05E0
#define CharacterZoneClient__BardCastBard_x                        0x4C30B0
#define CharacterZoneClient__GetMaxEffects_x                       0x4B8340
#define CharacterZoneClient__GetEffect_x                           0x4B81B0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C1610
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C16E0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C1730
#define CharacterZoneClient__CalcAffectChange_x                    0x4C1880
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C1A60
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B0060
#define CharacterZoneClient__FindItemByGuid_x                      0x4D4A80
#define CharacterZoneClient__FindItemByRecord_x                    0x4D44F0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6CFA10
#define CBankWnd__WndNotification_x                                0x6CF7F0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6DD1E0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x60A320
#define CButtonWnd__CButtonWnd_x                                   0x91F7E0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6FD160
#define CChatManager__InitContextMenu_x                            0x6F64A0
#define CChatManager__FreeChatWindow_x                             0x6FBCE0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E5B40
#define CChatManager__SetLockedActiveChatWindow_x                  0x6FCDE0
#define CChatManager__CreateChatWindow_x                           0x6FC310

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E5C00

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x933FB0
#define CContextMenu__dCContextMenu_x                              0x9341E0
#define CContextMenu__AddMenuItem_x                                0x9341F0
#define CContextMenu__RemoveMenuItem_x                             0x934500
#define CContextMenu__RemoveAllMenuItems_x                         0x934520
#define CContextMenu__CheckMenuItem_x                              0x9345A0
#define CContextMenu__SetMenuItem_x                                0x934420
#define CContextMenu__AddSeparator_x                               0x934380

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x934B40
#define CContextMenuManager__RemoveMenu_x                          0x934BB0
#define CContextMenuManager__PopupMenu_x                           0x934C70
#define CContextMenuManager__Flush_x                               0x934AE0
#define CContextMenuManager__GetMenu_x                             0x496880
#define CContextMenuManager__CreateDefaultMenu_x                   0x7087D0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D0B70
#define CChatService__GetFriendName_x                              0x8D0B80

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6FD9B0
#define CChatWindow__Clear_x                                       0x6FEC50
#define CChatWindow__WndNotification_x                             0x6FF3E0
#define CChatWindow__AddHistory_x                                  0x6FE520

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x931440
#define CComboWnd__Draw_x                                          0x930930
#define CComboWnd__GetCurChoice_x                                  0x931280
#define CComboWnd__GetListRect_x                                   0x930DE0
#define CComboWnd__GetTextRect_x                                   0x9314B0
#define CComboWnd__InsertChoice_x                                  0x930F70
#define CComboWnd__SetColors_x                                     0x930F40
#define CComboWnd__SetChoice_x                                     0x931250
#define CComboWnd__GetItemCount_x                                  0x931290
#define CComboWnd__GetCurChoiceText_x                              0x9312D0
#define CComboWnd__GetChoiceText_x                                 0x9312A0
#define CComboWnd__InsertChoiceAtIndex_x                           0x931010

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x7061B0
#define CContainerWnd__vftable_x                                   0xADF700
#define CContainerWnd__SetContainer_x                              0x707720

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x5451A0
#define CDisplay__GetClickedActor_x                                0x538160
#define CDisplay__GetUserDefinedColor_x                            0x530840
#define CDisplay__GetWorldFilePath_x                               0x539BB0
#define CDisplay__is3dON_x                                         0x534E30
#define CDisplay__ReloadUI_x                                       0x53F2D0
#define CDisplay__WriteTextHD2_x                                   0x534C10
#define CDisplay__TrueDistance_x                                   0x53B810
#define CDisplay__SetViewActor_x                                   0x537AB0
#define CDisplay__GetFloorHeight_x                                 0x534EF0
#define CDisplay__SetRenderWindow_x                                0x533820
#define CDisplay__ToggleScreenshotMode_x                           0x537580

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x9539F0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x937530
#define CEditWnd__GetCharIndexPt_x                                 0x938430
#define CEditWnd__GetDisplayString_x                               0x9382D0
#define CEditWnd__GetHorzOffset_x                                  0x936B60
#define CEditWnd__GetLineForPrintableChar_x                        0x9395E0
#define CEditWnd__GetSelStartPt_x                                  0x9386E0
#define CEditWnd__GetSTMLSafeText_x                                0x9380F0
#define CEditWnd__PointFromPrintableChar_x                         0x939210
#define CEditWnd__SelectableCharFromPoint_x                        0x939380
#define CEditWnd__SetEditable_x                                    0x9387B0
#define CEditWnd__SetWindowTextA_x                                 0x937E70

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5E9500
#define CEverQuest__ClickedPlayer_x                                0x5DB5D0
#define CEverQuest__CreateTargetIndicator_x                        0x5F8AD0
#define CEverQuest__DeleteTargetIndicator_x                        0x5F8B60
#define CEverQuest__DoTellWindow_x                                 0x4E5CE0
#define CEverQuest__OutputTextToLog_x                              0x4E5F10
#define CEverQuest__DropHeldItemOnGround_x                         0x5D0610
#define CEverQuest__dsp_chat_x                                     0x4E62A0
#define CEverQuest__trimName_x                                     0x5F4DB0
#define CEverQuest__Emote_x                                        0x5E9D10
#define CEverQuest__EnterZone_x                                    0x5E3CF0
#define CEverQuest__GetBodyTypeDesc_x                              0x5EE650
#define CEverQuest__GetClassDesc_x                                 0x5EEC90
#define CEverQuest__GetClassThreeLetterCode_x                      0x5EF290
#define CEverQuest__GetDeityDesc_x                                 0x5F7420
#define CEverQuest__GetLangDesc_x                                  0x5EF450
#define CEverQuest__GetRaceDesc_x                                  0x5EEC70
#define CEverQuest__InterpretCmd_x                                 0x5F79F0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5D4800
#define CEverQuest__LMouseUp_x                                     0x5D2B80
#define CEverQuest__RightClickedOnPlayer_x                         0x5D50E0
#define CEverQuest__RMouseUp_x                                     0x5D3B10
#define CEverQuest__SetGameState_x                                 0x5D03A0
#define CEverQuest__UPCNotificationFlush_x                         0x5F4CB0
#define CEverQuest__IssuePetCommand_x                              0x5F0850
#define CEverQuest__ReportSuccessfulHit_x                          0x5EB110

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x718200
#define CGaugeWnd__CalcLinesFillRect_x                             0x718260
#define CGaugeWnd__Draw_x                                          0x717840

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ACD10
#define CGuild__GetGuildName_x                                     0x4ABDF0
#define CGuild__GetGuildIndex_x                                    0x4AC180

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x7335F0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x60A6E0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x7405F0
#define CInvSlotMgr__MoveItem_x                                    0x73F300
#define CInvSlotMgr__SelectSlot_x                                  0x7406C0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x73DBB0
#define CInvSlot__SliderComplete_x                                 0x73B920
#define CInvSlot__GetItemBase_x                                    0x73B2A0
#define CInvSlot__UpdateItem_x                                     0x73B410

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x742100
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7412B0
#define CInvSlotWnd__HandleLButtonUp_x                             0x741C80

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7FE790
#define CItemDisplayWnd__UpdateStrings_x                           0x750680
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x74A3F0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x74A920
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x750C80
#define CItemDisplayWnd__AboutToShow_x                             0x7502E0
#define CItemDisplayWnd__WndNotification_x                         0x752190
#define CItemDisplayWnd__RequestConvertItem_x                      0x751C50
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x74F350
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x750100

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8367D0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x756240

// CLabel 
#define CLabel__Draw_x                                             0x75BD30

// CListWnd
#define CListWnd__CListWnd_x                                       0x909BF0
#define CListWnd__dCListWnd_x                                      0x909F00
#define CListWnd__AddColumn_x                                      0x90E210
#define CListWnd__AddColumn1_x                                     0x90E260
#define CListWnd__AddLine_x                                        0x90E5F0
#define CListWnd__AddString_x                                      0x90E3F0
#define CListWnd__CalculateFirstVisibleLine_x                      0x90DFD0
#define CListWnd__CalculateVSBRange_x                              0x90DDC0
#define CListWnd__ClearSel_x                                       0x90EDD0
#define CListWnd__ClearAllSel_x                                    0x90EE30
#define CListWnd__CloseAndUpdateEditWindow_x                       0x90F850
#define CListWnd__Compare_x                                        0x90D700
#define CListWnd__Draw_x                                           0x90A000
#define CListWnd__DrawColumnSeparators_x                           0x90C7D0
#define CListWnd__DrawHeader_x                                     0x90CC40
#define CListWnd__DrawItem_x                                       0x90D040
#define CListWnd__DrawLine_x                                       0x90C940
#define CListWnd__DrawSeparator_x                                  0x90C870
#define CListWnd__EnableLine_x                                     0x90C0B0
#define CListWnd__EnsureVisible_x                                  0x90F770
#define CListWnd__ExtendSel_x                                      0x90ED00
#define CListWnd__GetColumnTooltip_x                               0x90BBF0
#define CListWnd__GetColumnMinWidth_x                              0x90BC60
#define CListWnd__GetColumnWidth_x                                 0x90BB60
#define CListWnd__GetCurSel_x                                      0x90B4F0
#define CListWnd__GetItemAtPoint_x                                 0x90C330
#define CListWnd__GetItemAtPoint1_x                                0x90C3A0
#define CListWnd__GetItemData_x                                    0x90B570
#define CListWnd__GetItemHeight_x                                  0x90B930
#define CListWnd__GetItemIcon_x                                    0x90B700
#define CListWnd__GetItemRect_x                                    0x90C1A0
#define CListWnd__GetItemText_x                                    0x90B5B0
#define CListWnd__GetSelList_x                                     0x90EE80
#define CListWnd__GetSeparatorRect_x                               0x90C5E0
#define CListWnd__InsertLine_x                                     0x90E9E0
#define CListWnd__RemoveLine_x                                     0x90EB30
#define CListWnd__SetColors_x                                      0x90DD90
#define CListWnd__SetColumnJustification_x                         0x90DAC0
#define CListWnd__SetColumnWidth_x                                 0x90D9E0
#define CListWnd__SetCurSel_x                                      0x90EC40
#define CListWnd__SetItemColor_x                                   0x90F420
#define CListWnd__SetItemData_x                                    0x90F3E0
#define CListWnd__SetItemText_x                                    0x90EFF0
#define CListWnd__ShiftColumnSeparator_x                           0x90DB80
#define CListWnd__Sort_x                                           0x90D880
#define CListWnd__ToggleSel_x                                      0x90EC70
#define CListWnd__SetColumnsSizable_x                              0x90DC20
#define CListWnd__SetItemWnd_x                                     0x90F2A0
#define CListWnd__GetItemWnd_x                                     0x90B750
#define CListWnd__SetItemIcon_x                                    0x90F070
#define CListWnd__CalculateCustomWindowPositions_x                 0x90E0D0
#define CListWnd__SetVScrollPos_x                                  0x90D9C0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7713C0
#define CMapViewWnd__GetWorldCoordinates_x                         0x76FAD0
#define CMapViewWnd__HandleLButtonDown_x                           0x76CB30

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7943F0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x794CD0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x795200
#define CMerchantWnd__SelectRecoverySlot_x                         0x798190
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x792F30
#define CMerchantWnd__SelectBuySellSlot_x                          0x79DD70
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x794000

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89E700
#define CPacketScrambler__hton_x                                   0x89E6F0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x928A10
#define CSidlManager__FindScreenPieceTemplate_x                    0x928E20
#define CSidlManager__FindScreenPieceTemplate1_x                   0x928C10
#define CSidlManager__CreateLabel_x                                0x7F5C60
#define CSidlManager__CreateXWndFromTemplate_x                     0x92BDC0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x92BFA0
#define CSidlManager__CreateXWnd_x                                 0x7F5B90
#define CSidlManager__CreateHotButtonWnd_x                         0x7F6160

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x925590
#define CSidlScreenWnd__CalculateVSBRange_x                        0x925490
#define CSidlScreenWnd__ConvertToRes_x                             0x94A9B0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x924F20
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x924C10
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x924CE0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x924DB0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x925A20
#define CSidlScreenWnd__EnableIniStorage_x                         0x925EF0
#define CSidlScreenWnd__GetSidlPiece_x                             0x925C10
#define CSidlScreenWnd__Init1_x                                    0x924810
#define CSidlScreenWnd__LoadIniInfo_x                              0x925F40
#define CSidlScreenWnd__LoadIniListWnd_x                           0x926A80
#define CSidlScreenWnd__LoadSidlScreen_x                           0x923C20
#define CSidlScreenWnd__StoreIniInfo_x                             0x926600
#define CSidlScreenWnd__StoreIniVis_x                              0x926960
#define CSidlScreenWnd__WndNotification_x                          0x925930
#define CSidlScreenWnd__GetChildItem_x                             0x925E70
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9156C0
#define CSidlScreenWnd__m_layoutCopy_x                             0x16CA8C0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x66F380
#define CSkillMgr__GetSkillCap_x                                   0x66F560
#define CSkillMgr__GetNameToken_x                                  0x66EB10
#define CSkillMgr__IsActivatedSkill_x                              0x66EC50
#define CSkillMgr__IsCombatSkill_x                                 0x66EB90

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x935930
#define CSliderWnd__SetValue_x                                     0x9357A0
#define CSliderWnd__SetNumTicks_x                                  0x935800

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7FBCF0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x93E080
#define CStmlWnd__CalculateHSBRange_x                              0x93F170
#define CStmlWnd__CalculateVSBRange_x                              0x93F0E0
#define CStmlWnd__CanBreakAtCharacter_x                            0x9434B0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x944140
#define CStmlWnd__ForceParseNow_x                                  0x93E620
#define CStmlWnd__GetNextTagPiece_x                                0x943410
#define CStmlWnd__GetSTMLText_x                                    0x4F8010
#define CStmlWnd__GetVisibleText_x                                 0x93E640
#define CStmlWnd__InitializeWindowVariables_x                      0x943F90
#define CStmlWnd__MakeStmlColorTag_x                               0x93D760
#define CStmlWnd__MakeWndNotificationTag_x                         0x93D7D0
#define CStmlWnd__SetSTMLText_x                                    0x93C810
#define CStmlWnd__StripFirstSTMLLines_x                            0x945240
#define CStmlWnd__UpdateHistoryString_x                            0x944350

// CTabWnd 
#define CTabWnd__Draw_x                                            0x93B9B0
#define CTabWnd__DrawCurrentPage_x                                 0x93C090
#define CTabWnd__DrawTab_x                                         0x93BDB0
#define CTabWnd__GetCurrentPage_x                                  0x93B1B0
#define CTabWnd__GetPageInnerRect_x                                0x93B3F0
#define CTabWnd__GetTabInnerRect_x                                 0x93B330
#define CTabWnd__GetTabRect_x                                      0x93B1E0
#define CTabWnd__InsertPage_x                                      0x93B600
#define CTabWnd__SetPage_x                                         0x93B470
#define CTabWnd__SetPageRect_x                                     0x93B8F0
#define CTabWnd__UpdatePage_x                                      0x93BC70
#define CTabWnd__GetPageFromTabIndex_x                             0x93BCF0
#define CTabWnd__GetCurrentTabIndex_x                              0x93B1A0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x756650
#define CPageWnd__SetTabText_x                                     0x93AD00

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A69C0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x912540
#define CTextureFont__GetTextExtent_x                              0x912700

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6A2B90
#define CHtmlComponentWnd__ValidateUri_x                           0x734FE0
#define CHtmlWnd__SetClientCallbacks_x                             0x60F750
#define CHtmlWnd__AddObserver_x                                    0x60F770
#define CHtmlWnd__RemoveObserver_x                                 0x60F7D0
#define Window__getProgress_x                                      0x84EE00
#define Window__getStatus_x                                        0x84EE20
#define Window__getURI_x                                           0x84EE30

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x950420

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8FF770

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E5A30
#define CXStr__CXStr1_x                                            0x9C1CB0
#define CXStr__CXStr3_x                                            0x8EC460
#define CXStr__dCXStr_x                                            0x472FE0
#define CXStr__operator_equal_x                                    0x8EC690
#define CXStr__operator_equal1_x                                   0x8EC6D0
#define CXStr__operator_plus_equal1_x                              0x8ED160
#define CXStr__SetString_x                                         0x8EF050
#define CXStr__operator_char_p_x                                   0x8ECBA0
#define CXStr__GetChar_x                                           0x8EE980
#define CXStr__Delete_x                                            0x8EE250
#define CXStr__GetUnicode_x                                        0x8EE9F0
#define CXStr__GetLength_x                                         0x4A6770
#define CXStr__Mid_x                                               0x477DD0
#define CXStr__Insert_x                                            0x8EEA50
#define CXStr__FindNext_x                                          0x8EE6C0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x933BD0
#define CXWnd__BringToTop_x                                        0x918DA0
#define CXWnd__Center_x                                            0x918920
#define CXWnd__ClrFocus_x                                          0x918770
#define CXWnd__Destroy_x                                           0x918810
#define CXWnd__DoAllDrawing_x                                      0x914E50
#define CXWnd__DrawChildren_x                                      0x914E20
#define CXWnd__DrawColoredRect_x                                   0x9152B0
#define CXWnd__DrawTooltip_x                                       0x913980
#define CXWnd__DrawTooltipAtPoint_x                                0x913A40
#define CXWnd__GetBorderFrame_x                                    0x915110
#define CXWnd__GetChildWndAt_x                                     0x918E40
#define CXWnd__GetClientClipRect_x                                 0x917090
#define CXWnd__GetScreenClipRect_x                                 0x917160
#define CXWnd__GetScreenRect_x                                     0x9172F0
#define CXWnd__GetTooltipRect_x                                    0x915300
#define CXWnd__GetWindowTextA_x                                    0x497F30
#define CXWnd__IsActive_x                                          0x915A40
#define CXWnd__IsDescendantOf_x                                    0x917CF0
#define CXWnd__IsReallyVisible_x                                   0x917D20
#define CXWnd__IsType_x                                            0x9194B0
#define CXWnd__Move_x                                              0x917D80
#define CXWnd__Move1_x                                             0x917E30
#define CXWnd__ProcessTransition_x                                 0x9188D0
#define CXWnd__Refade_x                                            0x918100
#define CXWnd__Resize_x                                            0x918390
#define CXWnd__Right_x                                             0x918B60
#define CXWnd__SetFocus_x                                          0x918730
#define CXWnd__SetFont_x                                           0x9187A0
#define CXWnd__SetKeyTooltip_x                                     0x9192C0
#define CXWnd__SetMouseOver_x                                      0x916240
#define CXWnd__StartFade_x                                         0x917BC0
#define CXWnd__GetChildItem_x                                      0x918FB0
#define CXWnd__SetParent_x                                         0x917A90
#define CXWnd__Minimize_x                                          0x918400

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x94BA40

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x91BD10
#define CXWndManager__DrawWindows_x                                0x91BD30
#define CXWndManager__GetKeyboardFlags_x                           0x91E4A0
#define CXWndManager__HandleKeyboardMsg_x                          0x91E0A0
#define CXWndManager__RemoveWnd_x                                  0x91E6F0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x91EC50

// CDBStr
#define CDBStr__GetString_x                                        0x52F710

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B9250
#define EQ_Character__Cur_HP_x                                     0x4CF3D0
#define EQ_Character__Cur_Mana_x                                   0x4D6B60
#define EQ_Character__GetCastingTimeModifier_x                     0x4BC180
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AFCA0
#define EQ_Character__GetFocusRangeModifier_x                      0x4AFDF0
#define EQ_Character__GetHPRegen_x                                 0x4DC950
#define EQ_Character__GetEnduranceRegen_x                          0x4DCF60
#define EQ_Character__GetManaRegen_x                               0x4DD3A0
#define EQ_Character__Max_Endurance_x                              0x635B70
#define EQ_Character__Max_HP_x                                     0x4CF200
#define EQ_Character__Max_Mana_x                                   0x635970
#define EQ_Character__doCombatAbility_x                            0x638030
#define EQ_Character__UseSkill_x                                   0x4DF1B0
#define EQ_Character__GetConLevel_x                                0x62EA70
#define EQ_Character__IsExpansionFlag_x                            0x592C70
#define EQ_Character__TotalEffect_x                                0x4C27F0
#define EQ_Character__GetPCSpellAffect_x                           0x4BCD70
#define EQ_Character__SpellDuration_x                              0x4BC8A0
#define EQ_Character__GetAdjustedSkill_x                           0x4D21B0
#define EQ_Character__GetBaseSkill_x                               0x4D3150
#define EQ_Character__CanUseItem_x                                 0x4D6E70

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BD8B0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x64C1E0

//PcClient
#define PcClient__PcClient_x                                       0x62C1B0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6E90
#define CCharacterListWnd__EnterWorld_x                            0x4B68D0
#define CCharacterListWnd__Quit_x                                  0x4B65E0
#define CCharacterListWnd__UpdateList_x                            0x4B6A60

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x610970
#define EQ_Item__CreateItemTagString_x                             0x898090
#define EQ_Item__IsStackable_x                                     0x89CA70
#define EQ_Item__GetImageNum_x                                     0x899AC0
#define EQ_Item__CreateItemClient_x                                0x60FB50
#define EQ_Item__GetItemValue_x                                    0x89AD10
#define EQ_Item__ValueSellMerchant_x                               0x89E290
#define EQ_Item__IsKeyRingItem_x                                   0x89C3C0
#define EQ_Item__CanGoInBag_x                                      0x610A90
#define EQ_Item__IsEmpty_x                                         0x89BF00
#define EQ_Item__GetMaxItemCount_x                                 0x89B0E0
#define EQ_Item__GetHeldItem_x                                     0x899990
#define EQ_Item__GetAugmentFitBySlot_x                             0x8979D0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x54DC00
#define EQ_LoadingS__Array_x                                       0xBF3600

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x6364D0
#define EQ_PC__GetAlternateAbilityId_x                             0x8A7370
#define EQ_PC__GetCombatAbility_x                                  0x8A79E0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A7A50
#define EQ_PC__GetItemRecastTimer_x                                0x6385B0
#define EQ_PC__HasLoreItem_x                                       0x62F280
#define EQ_PC__AlertInventoryChanged_x                             0x62E3B0
#define EQ_PC__GetPcZoneClient_x                                   0x65AB10
#define EQ_PC__RemoveMyAffect_x                                    0x63B7D0
#define EQ_PC__GetKeyRingItems_x                                   0x8A82F0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A8070
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A85E0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5991D0
#define EQItemList__add_object_x                                   0x5C5D50
#define EQItemList__add_item_x                                     0x599720
#define EQItemList__delete_item_x                                  0x599770
#define EQItemList__FreeItemList_x                                 0x599670

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x52D1D0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x64DA60
#define EQPlayer__dEQPlayer_x                                      0x640D30
#define EQPlayer__DoAttack_x                                       0x6557C0
#define EQPlayer__EQPlayer_x                                       0x6413F0
#define EQPlayer__SetNameSpriteState_x                             0x6456F0
#define EQPlayer__SetNameSpriteTint_x                              0x6465B0
#define PlayerBase__HasProperty_j_x                                0x97E5B0
#define EQPlayer__IsTargetable_x                                   0x97EA50
#define EQPlayer__CanSee_x                                         0x97E8B0
#define EQPlayer__CanSee1_x                                        0x97E980
#define PlayerBase__GetVisibilityLineSegment_x                     0x97E670

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x6585A0
#define PlayerZoneClient__GetLevel_x                               0x65AB50
#define PlayerZoneClient__IsValidTeleport_x                        0x5C6EC0
#define PlayerZoneClient__LegalPlayerRace_x                        0x546FF0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x650820
#define EQPlayerManager__GetSpawnByName_x                          0x6508D0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x650960

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x6140B0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x614130
#define KeypressHandler__AttachKeyToEqCommand_x                    0x614170
#define KeypressHandler__ClearCommandStateArray_x                  0x615580
#define KeypressHandler__HandleKeyDown_x                           0x6155A0
#define KeypressHandler__HandleKeyUp_x                             0x615640
#define KeypressHandler__SaveKeymapping_x                          0x615A70

// MapViewMap 
#define MapViewMap__Clear_x                                        0x76D250
#define MapViewMap__SaveEx_x                                       0x7705F0
#define MapViewMap__SetZoom_x                                      0x774CC0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BB6F0

// StringTable 
#define StringTable__getString_x                                   0x8B65F0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x63B440
#define PcZoneClient__RemovePetEffect_x                            0x63BA70
#define PcZoneClient__HasAlternateAbility_x                        0x6357B0
#define PcZoneClient__GetCurrentMod_x                              0x4E2290
#define PcZoneClient__GetModCap_x                                  0x4E2190
#define PcZoneClient__CanEquipItem_x                               0x635E60
#define PcZoneClient__GetItemByID_x                                0x638A20
#define PcZoneClient__GetItemByItemClass_x                         0x638B70
#define PcZoneClient__RemoveBuffEffect_x                           0x63BA90
#define PcZoneClient__BandolierSwap_x                              0x636A90
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x638550

//Doors
#define EQSwitch__UseSwitch_x                                      0x5CBA40

//IconCache
#define IconCache__GetIcon_x                                       0x70D850

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x705350
#define CContainerMgr__CloseContainer_x                            0x705620
#define CContainerMgr__OpenExperimentContainer_x                   0x7060A0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7C83A0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x608B10

//CLootWnd
#define CLootWnd__LootAll_x                                        0x763750
#define CLootWnd__RequestLootSlot_x                                0x762AB0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x565FF0
#define EQ_Spell__SpellAffects_x                                   0x566460
#define EQ_Spell__SpellAffectBase_x                                0x566220
#define EQ_Spell__IsStackable_x                                    0x4C6E80
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C6CA0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B4270
#define EQ_Spell__IsSPAStacking_x                                  0x567290
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x5667B0
#define EQ_Spell__IsNoRemove_x                                     0x4C6E60
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x5672A0
#define __IsResEffectSpell_x                                       0x4C61A0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AAA60

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C5EE0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x80E030
#define CTargetWnd__WndNotification_x                              0x80D8C0
#define CTargetWnd__RefreshTargetBuffs_x                           0x80DB90
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x80CA20

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x8126F0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x52AD00
#define CTaskManager__HandleMessage_x                              0x529440

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5615A0
#define EqSoundManager__PlayScriptMp3_x                            0x561700
#define EqSoundManager__SoundAssistPlay_x                          0x6732D0
#define EqSoundManager__WaveInstancePlay_x                         0x672840

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x51EDD0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x93A200

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x5555D0
#define CAltAbilityData__GetMercMaxRank_x                          0x555570
#define CAltAbilityData__GetMaxRank_x                              0x54AC90

//CTargetRing
#define CTargetRing__Cast_x                                        0x606C10

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C6C80
#define CharacterBase__CreateItemGlobalIndex_x                     0x504C80
#define CharacterBase__CreateItemIndex_x                           0x60ED10
#define CharacterBase__GetItemPossession_x                         0x4F0C10
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CE520
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CE580
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6EC830
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6ED060
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6ED110

//messages
#define msg_spell_worn_off_x                                       0x58AE90
#define msg_new_text_x                                             0x57FC90
#define __msgTokenTextParam_x                                      0x58D3C0
#define msgTokenText_x                                             0x58D610

//SpellManager
#define SpellManager__vftable_x                                    0xAB9C58
#define SpellManager__SpellManager_x                               0x676600
#define Spellmanager__LoadTextSpells_x                             0x676ED0
#define SpellManager__GetSpellByGroupAndRank_x                     0x6767D0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9825A0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x505360
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x591180
#define ItemGlobalIndex__IsEquippedLocation_x                      0x627920
#define ItemGlobalIndex__IsValidIndex_x                            0x5053C0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C6820
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C6AA0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x75C080

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x709A70
#define CCursorAttachment__AttachToCursor1_x                       0x709AB0
#define CCursorAttachment__Deactivate_x                            0x70AA90

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x92CDF0
#define CSidlManagerBase__CreatePageWnd_x                          0x92C5F0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x928830
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x9287C0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x949F50
#define CEQSuiteTextureLoader__GetTexture_x                        0x949C10

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x502220
#define CFindItemWnd__WndNotification_x                            0x502D00
#define CFindItemWnd__Update_x                                     0x503870
#define CFindItemWnd__PickupSelectedItem_x                         0x501A80

//IString
#define IString__Append_x                                          0x4F2200

//Camera
#define CDisplay__cameraType_x                                     0xDCCD08
#define EverQuest__Cameras_x                                       0xE90770

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x50AC60
#define LootFiltersManager__GetItemFilterData_x                    0x50A560
#define LootFiltersManager__RemoveItemLootFilter_x                 0x50A590
#define LootFiltersManager__SetItemLootFilter_x                    0x50A7B0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B63A0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9881E0
#define CResolutionHandler__GetWindowedStyle_x                     0x66DDA0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x702100

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D9160
#define CDistillerInfo__Instance_x                                 0x8D9100

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x722370
#define CGroupWnd__UpdateDisplay_x                                 0x7216D0

//ItemBase
#define ItemBase__IsLore_x                                         0x89C420
#define ItemBase__IsLoreEquipped_x                                 0x89C490

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5C5CB0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5C5DF0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5C5E50

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x663620
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x667020

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x4F8610

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4E7670
#define FactionManagerClient__HandleFactionMessage_x               0x4E7CE0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4E82D0
#define FactionManagerClient__GetMaxFaction_x                      0x4E8320
#define FactionManagerClient__GetMinFaction_x                      0x4E82A0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4F0BE0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x911500

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x497250

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4F0E50

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x554A90

//CTargetManager
#define CTargetManager__Get_x                                      0x679EA0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x663620

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A6780

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x599610

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF2DE00

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
