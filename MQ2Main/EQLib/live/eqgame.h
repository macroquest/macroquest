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
#define __ExpectedVersionDate                                     "May 20 2019"
#define __ExpectedVersionTime                                     "12:50:50"
#define __ActualVersionDate_x                                      0xAD5494
#define __ActualVersionTime_x                                      0xAD5488
#define __ActualVersionBuild_x                                     0xAD5F2C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x61A570
#define __MemChecker1_x                                            0x8EF480
#define __MemChecker2_x                                            0x6A91F0
#define __MemChecker3_x                                            0x6A9140
#define __MemChecker4_x                                            0x8464F0
#define __EncryptPad0_x                                            0xC0A9B0
#define __EncryptPad1_x                                            0xC68938
#define __EncryptPad2_x                                            0xC1B228
#define __EncryptPad3_x                                            0xC1AE28
#define __EncryptPad4_x                                            0xC591A0
#define __EncryptPad5_x                                            0xF33310
#define __AC1_x                                                    0x803016
#define __AC2_x                                                    0x5D417F
#define __AC3_x                                                    0x5DB88F
#define __AC4_x                                                    0x5DF710
#define __AC5_x                                                    0x5E5980
#define __AC6_x                                                    0x5EA016
#define __AC7_x                                                    0x5D3BF0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1F74CC

// Direct Input
#define DI8__Main_x                                                0xF33330
#define DI8__Keyboard_x                                            0xF33334
#define DI8__Mouse_x                                               0xF328F0
#define DI8__Mouse_Copy_x                                          0xE8DFCC
#define DI8__Mouse_Check_x                                         0xF33664
#define __AutoSkillArray_x                                         0xE8EEE4
#define __Attack_x                                                 0xF2CCFB
#define __Autofire_x                                               0xF2CCFC
#define __BindList_x                                               0xBF93F0
#define g_eqCommandStates_x                                        0xBFA168
#define __Clicks_x                                                 0xE8E084
#define __CommandList_x                                            0xBFAD28
#define __CurrentMapLabel_x                                        0x104DDA4
#define __CurrentSocial_x                                          0xBE3730
#define __DoAbilityList_x                                          0xEC481C
#define __do_loot_x                                                0x5A0840
#define __DrawHandler_x                                            0x16CA778
#define __GroupCount_x                                             0xE7E28A
#define __Guilds_x                                                 0xE847D8
#define __gWorld_x                                                 0xE805B8
#define __HWnd_x                                                   0xF328F4
#define __heqmain_x                                                0x103D94C
#define __InChatMode_x                                             0xE8DFB4
#define __LastTell_x                                               0xE8FF18
#define __LMouseHeldTime_x                                         0xE8E0F0
#define __Mouse_x                                                  0xF3331C
#define __MouseLook_x                                              0xE8E04A
#define __MouseEventTime_x                                         0xF2D7DC
#define __gpbCommandEvent_x                                        0xE805B0
#define __NetStatusToggle_x                                        0xE8E04D
#define __PCNames_x                                                0xE8F4C8
#define __RangeAttackReady_x                                       0xE8F1C8
#define __RMouseHeldTime_x                                         0xE8E0EC
#define __RunWalkState_x                                           0xE8DFB8
#define __ScreenMode_x                                             0xDCC1D0
#define __ScreenX_x                                                0xE8DF6C
#define __ScreenY_x                                                0xE8DF68
#define __ScreenXMax_x                                             0xE8DF70
#define __ScreenYMax_x                                             0xE8DF74
#define __ServerHost_x                                             0xE807EB
#define __ServerName_x                                             0xEC47DC
#define __ShiftKeyDown_x                                           0xE8E644
#define __ShowNames_x                                              0xE8F384
#define __Socials_x                                                0xEC48DC
#define __SubscriptionType_x                                       0x108F940
#define __TargetAggroHolder_x                                      0x1050760
#define __ZoneType_x                                               0xE8E448
#define __GroupAggro_x                                             0x10507A0
#define __LoginName_x                                              0xF32FB4
#define __Inviter_x                                                0xF2CC78
#define __AttackOnAssist_x                                         0xE8F340
#define __UseTellWindows_x                                         0xE8F664
#define __gfMaxZoomCameraDistance_x                                0xACA928
#define __gfMaxCameraDistance_x                                    0xAF7DD8
#define __pulAutoRun_x                                             0xE8E068
#define __pulForward_x                                             0xE8F69C
#define __pulBackward_x                                            0xE8F6A0
#define __pulTurnRight_x                                           0xE8F6A4
#define __pulTurnLeft_x                                            0xE8F6A8
#define __pulStrafeLeft_x                                          0xE8F6AC
#define __pulStrafeRight_x                                         0xE8F6B0
//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE80B70
#define instEQZoneInfo_x                                           0xE8E240
#define pinstActiveBanker_x                                        0xE8064C
#define pinstActiveCorpse_x                                        0xE80644
#define pinstActiveGMaster_x                                       0xE80648
#define pinstActiveMerchant_x                                      0xE80640
#define pinstAltAdvManager_x                                       0xDCCE40
#define pinstBandageTarget_x                                       0xE8065C
#define pinstCamActor_x                                            0xDCC1C0
#define pinstCDBStr_x                                              0xDCBB6C
#define pinstCDisplay_x                                            0xE806A0
#define pinstCEverQuest_x                                          0x103D948
#define pinstEverQuestInfo_x                                       0xE8DF60
#define pinstCharData_x                                            0xE7E264
#define pinstCharSpawn_x                                           0xE80694
#define pinstControlledMissile_x                                   0xE80B28
#define pinstControlledPlayer_x                                    0xE80694
#define pinstCResolutionHandler_x                                  0x16CA9A8
#define pinstCSidlManager_x                                        0x16C9944
#define pinstCXWndManager_x                                        0x16C9938
#define instDynamicZone_x                                          0xE846B0
#define pinstDZMember_x                                            0xE847C0
#define pinstDZTimerInfo_x                                         0xE847C4
#define pinstEqLogin_x                                             0xF32900
#define instEQMisc_x                                               0xDCBAB0
#define pinstEQSoundManager_x                                      0xDCDD68
#define pinstEQSpellStrings_x                                      0xC8D2C0
#define instExpeditionLeader_x                                     0xE846FA
#define instExpeditionName_x                                       0xE8473A
#define pinstGroup_x                                               0xE7E286
#define pinstImeManager_x                                          0x16C993C
#define pinstLocalPlayer_x                                         0xE805BC
#define pinstMercenaryData_x                                       0xF2F2CC
#define pinstMercenaryStats_x                                      0x10508AC
#define pinstModelPlayer_x                                         0xE80654
#define pinstPCData_x                                              0xE7E264
#define pinstSkillMgr_x                                            0xF31440
#define pinstSpawnManager_x                                        0xF2FEE8
#define pinstSpellManager_x                                        0xF31660
#define pinstSpellSets_x                                           0xF25924
#define pinstStringTable_x                                         0xE80480
#define pinstSwitchManager_x                                       0xE7E110
#define pinstTarget_x                                              0xE80690
#define pinstTargetObject_x                                        0xE8069C
#define pinstTargetSwitch_x                                        0xE7E268
#define pinstTaskMember_x                                          0xDCB944
#define pinstTrackTarget_x                                         0xE80698
#define pinstTradeTarget_x                                         0xE80650
#define instTributeActive_x                                        0xDCBAD1
#define pinstViewActor_x                                           0xDCC1BC
#define pinstWorldData_x                                           0xE805A8
#define pinstZoneAddr_x                                            0xE8E4E0
#define pinstPlayerPath_x                                          0xF2FF80
#define pinstTargetIndicator_x                                     0xF318C8
#define EQObject_Top_x                                             0xE805B4

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDCC288
#define pinstCAchievementsWnd_x                                    0xDCC278
#define pinstCActionsWnd_x                                         0xDCBC4C
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDCC0FC
#define pinstCAdvancedLootWnd_x                                    0xDCBC44
#define pinstCAdventureLeaderboardWnd_x                            0x1047578
#define pinstCAdventureRequestWnd_x                                0x1047628
#define pinstCAdventureStatsWnd_x                                  0x10476D8
#define pinstCAggroMeterWnd_x                                      0xDCC158
#define pinstCAlarmWnd_x                                           0xDCC1B8
#define pinstCAlertHistoryWnd_x                                    0xDCC224
#define pinstCAlertStackWnd_x                                      0xDCC170
#define pinstCAlertWnd_x                                           0xDCC180
#define pinstCAltStorageWnd_x                                      0x1047A38
#define pinstCAudioTriggersWindow_x                                0xC7F5F0
#define pinstCAuraWnd_x                                            0xDCC150
#define pinstCAvaZoneWnd_x                                         0xDCC228
#define pinstCBandolierWnd_x                                       0xDCC184
#define pinstCBankWnd_x                                            0xDCC214
#define pinstCBarterMerchantWnd_x                                  0x1048C78
#define pinstCBarterSearchWnd_x                                    0x1048D28
#define pinstCBarterWnd_x                                          0x1048DD8
#define pinstCBazaarConfirmationWnd_x                              0xDCC16C
#define pinstCBazaarSearchWnd_x                                    0xDCBC7C
#define pinstCBazaarWnd_x                                          0xDCC198
#define pinstCBlockedBuffWnd_x                                     0xDCC1FC
#define pinstCBlockedPetBuffWnd_x                                  0xDCC22C
#define pinstCBodyTintWnd_x                                        0xDCC140
#define pinstCBookWnd_x                                            0xDCC1A0
#define pinstCBreathWnd_x                                          0xDCC294
#define pinstCBuffWindowNORMAL_x                                   0xDCC1CC
#define pinstCBuffWindowSHORT_x                                    0xDCC1D4
#define pinstCBugReportWnd_x                                       0xDCC28C
#define pinstCButtonWnd_x                                          0x16C9BA8
#define pinstCCastingWnd_x                                         0xDCC27C
#define pinstCCastSpellWnd_x                                       0xDCC0EC
//#define pinstCCharacterCreationWnd_x                             0xDAAE5C
#define pinstCCharacterListWnd_x                                   0xDCC29C
#define pinstCChatWindowManager_x                                  0x1049898
#define pinstCClaimWnd_x                                           0x10499F0
#define pinstCColorPickerWnd_x                                     0xDCBC2C
#define pinstCCombatAbilityWnd_x                                   0xDCC15C
#define pinstCCombatSkillsSelectWnd_x                              0xDCBC50
#define pinstCCompassWnd_x                                         0xDCC12C
#define pinstCConfirmationDialog_x                                 0x104E8F0
#define pinstCContainerMgr_x                                       0xDCC284
#define pinstCContextMenuManager_x                                 0x16C98F8
#define pinstCCursorAttachment_x                                   0xDCC26C
#define pinstCDynamicZoneWnd_x                                     0x1049FB8
#define pinstCEditLabelWnd_x                                       0xDCC1AC
#define pinstCEQMainWnd_x                                          0x104A200
#define pinstCEventCalendarWnd_x                                   0xDCBC1C
#define pinstCExtendedTargetWnd_x                                  0xDCC148
#define pinstCFacePick_x                                           0xDCBC24
#define pinstCFactionWnd_x                                         0xDCC274
#define pinstCFellowshipWnd_x                                      0x104A400
#define pinstCFileSelectionWnd_x                                   0xDCBC3C
#define pinstCFindItemWnd_x                                        0xDCC1B0
#define pinstCFindLocationWnd_x                                    0x104A558
#define pinstCFriendsWnd_x                                         0xDCBC60
#define pinstCGemsGameWnd_x                                        0xDCC194
#define pinstCGiveWnd_x                                            0xDCC1B4
#define pinstCGroupSearchFiltersWnd_x                              0xDCC168
#define pinstCGroupSearchWnd_x                                     0x104A950
#define pinstCGroupWnd_x                                           0x104AA00
#define pinstCGuildBankWnd_x                                       0xE8F324
#define pinstCGuildCreationWnd_x                                   0x104AB60
#define pinstCGuildMgmtWnd_x                                       0x104AC10
#define pinstCharacterCreation_x                                   0xDCC160
#define pinstCHelpWnd_x                                            0xDCC104
#define pinstCHeritageSelectionWnd_x                               0xDCBC38
#define pinstCHotButtonWnd_x                                       0x104CD68
#define pinstCHotButtonWnd1_x                                      0x104CD68
#define pinstCHotButtonWnd2_x                                      0x104CD6C
#define pinstCHotButtonWnd3_x                                      0x104CD70
#define pinstCHotButtonWnd4_x                                      0x104CD74
#define pinstCIconSelectionWnd_x                                   0xDCC240
#define pinstCInspectWnd_x                                         0xDCC24C
#define pinstCInventoryWnd_x                                       0xDCC188
#define pinstCInvSlotMgr_x                                         0xDCC21C
#define pinstCItemDisplayManager_x                                 0x104D2F8
#define pinstCItemExpTransferWnd_x                                 0x104D42C
#define pinstCItemFuseWnd_x                                        0xDCC268
#define pinstCItemOverflowWnd_x                                    0xDCBCE4
#define pinstCJournalCatWnd_x                                      0xDCBC5C
//#define pinstCJournalNPCWnd_x                                    0xDAB354
#define pinstCJournalTextWnd_x                                     0xDCBC20
#define pinstCKeyRingWnd_x                                         0xDCC1EC
#define pinstCLargeDialogWnd_x                                     0x104F570
#define pinstCLayoutCopyWnd_x                                      0x104D778
#define pinstCLFGuildWnd_x                                         0x104D828
#define pinstCLoadskinWnd_x                                        0xDCC19C
#define pinstCLootFiltersCopyWnd_x                                 0xC9B8B8
#define pinstCLootFiltersWnd_x                                     0xDCC1A8
#define pinstCLootSettingsWnd_x                                    0xDCC1E8
#define pinstCLootWnd_x                                            0xDCBC14
#define pinstCMailAddressBookWnd_x                                 0xDCC234
#define pinstCMailCompositionWnd_x                                 0xDCC204
#define pinstCMailIgnoreListWnd_x                                  0xDCC238
#define pinstCMailWnd_x                                            0xDCC1E4
#define pinstCManageLootWnd_x                                      0xDCD2F0
#define pinstCMapToolbarWnd_x                                      0xDCC18C
#define pinstCMapViewWnd_x                                         0xDCC17C
#define pinstCMarketplaceWnd_x                                     0xDCBC28
#define pinstCMerchantWnd_x                                        0xDCBC54
#define pinstCMIZoneSelectWnd_x                                    0x104E060
#define pinstCMusicPlayerWnd_x                                     0xDCC1F0
#define pinstCNameChangeMercWnd_x                                  0xDCC134
#define pinstCNameChangePetWnd_x                                   0xDCC124
#define pinstCNameChangeWnd_x                                      0xDCBC0C
#define pinstCNoteWnd_x                                            0xDCC0F8
#define pinstCObjectPreviewWnd_x                                   0xDCBC48
#define pinstCOptionsWnd_x                                         0xDCC190
#define pinstCPetInfoWnd_x                                         0xDCC208
#define pinstCPetitionQWnd_x                                       0xDCBC68
//#define pinstCPlayerCustomizationWnd_x                           0xDAADC4
#define pinstCPlayerNotesWnd_x                                     0xDCC13C
#define pinstCPlayerWnd_x                                          0xDCC1A4
#define pinstCPopupWndManager_x                                    0x104E8F0
#define pinstCProgressionSelectionWnd_x                            0x104E9A0
#define pinstCPurchaseGroupWnd_x                                   0xDCC0F0
#define pinstCPurchaseWnd_x                                        0xDCBC58
#define pinstCPvPLeaderboardWnd_x                                  0x104EA50
#define pinstCPvPStatsWnd_x                                        0x104EB00
#define pinstCQuantityWnd_x                                        0xDCC244
#define pinstCRaceChangeWnd_x                                      0xDCBC34
#define pinstCRaidOptionsWnd_x                                     0xDCC178
#define pinstCRaidWnd_x                                            0xDCC250
#define pinstCRealEstateItemsWnd_x                                 0xDCC290
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDCBC18
#define pinstCRealEstateManageWnd_x                                0xDCC1F4
#define pinstCRealEstateNeighborhoodWnd_x                          0xDCC20C
#define pinstCRealEstatePlotSearchWnd_x                            0xDCC230
#define pinstCRealEstatePurchaseWnd_x                              0xDCC264
#define pinstCRespawnWnd_x                                         0xDCC164
//#define pinstCRewardSelectionWnd_x                               0x1022600
#define pinstCSelectorWnd_x                                        0xDCC14C
#define pinstCSendMoneyWnd_x                                       0xDCC1E0
#define pinstCServerListWnd_x                                      0xDCC220
#define pinstCSkillsSelectWnd_x                                    0xDCBC30
#define pinstCSkillsWnd_x                                          0xDCBC10
#define pinstCSocialEditWnd_x                                      0xDCC270
#define pinstCSocialWnd_x                                          0xDCC154
#define pinstCSpellBookWnd_x                                       0xDCC144
#define pinstCStoryWnd_x                                           0xDCC10C
#define pinstCTargetOfTargetWnd_x                                  0x1050930
#define pinstCTargetWnd_x                                          0xDCC200
#define pinstCTaskOverlayWnd_x                                     0xDCC23C
#define pinstCTaskSelectWnd_x                                      0x1050A88
#define pinstCTaskManager_x                                        0xC9C208
#define pinstCTaskTemplateSelectWnd_x                              0x1050B38
#define pinstCTaskWnd_x                                            0x1050BE8
#define pinstCTextEntryWnd_x                                       0xDCC130
#define pinstCTimeLeftWnd_x                                        0xDCBC40
#define pinstCTipWndCONTEXT_x                                      0x1050DEC
#define pinstCTipWndOFDAY_x                                        0x1050DE8
#define pinstCTitleWnd_x                                           0x1050E98
#define pinstCTrackingWnd_x                                        0xDCC218
#define pinstCTradeskillWnd_x                                      0x1051000
#define pinstCTradeWnd_x                                           0xDCC138
#define pinstCTrainWnd_x                                           0xDCC248
#define pinstCTributeBenefitWnd_x                                  0x1051200
#define pinstCTributeMasterWnd_x                                   0x10512B0
#define pinstCTributeTrophyWnd_x                                   0x1051360
#define pinstCVideoModesWnd_x                                      0xDCC254
#define pinstCVoiceMacroWnd_x                                      0xF32030
#define pinstCVoteResultsWnd_x                                     0xDCC0F4
#define pinstCVoteWnd_x                                            0xDCBC64
#define pinstCWebManager_x                                         0xF326AC
#define pinstCZoneGuideWnd_x                                       0xDCC1F8
#define pinstCZonePathWnd_x                                        0xDCC210

#define pinstEQSuiteTextureLoader_x                                0xC6A420
#define pinstItemIconCache_x                                       0x104A1B8
#define pinstLootFiltersManager_x                                  0xC9B968
#define pinstRewardSelectionWnd_x                                  0x104F248

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC1AE18
#define __CastRay_x                                                0x59BCA0
#define __CastRay2_x                                               0x59BCF0
#define __ConvertItemTags_x                                        0x5B7500
#define __CleanItemTags_x                                          0x477930
#define __CrashHandler_x                                           0x84FE90
#define __DoesFileExist_x                                          0x8F2600
#define __EQGetTime_x                                              0x8EEF60
#define __ExecuteCmd_x                                             0x5945C0
#define __FixHeading_x                                             0x97EE50
#define __GameLoop_x                                               0x6A86B0
#define __get_bearing_x                                            0x59B7F0
#define __get_melee_range_x                                        0x59BEE0
#define __GetAnimationCache_x                                      0x70D470
#define __GetGaugeValueFromEQ_x                                    0x801820
#define __GetLabelFromEQ_x                                         0x802FA0
#define __GetXTargetType_x                                         0x980970
#define __HandleMouseWheel_x                                       0x6A92A0
#define __HeadingDiff_x                                            0x97EEC0
#define __HelpPath_x                                               0xF2D3CC
#define __LoadFrontEnd_x                                           0x6A5180
#define __NewUIINI_x                                               0x8014F0
#define __pCrashHandler_x                                          0x106E768
#define __ProcessGameEvents_x                                      0x5FB6C0
#define __ProcessMouseEvent_x                                      0x5FAE80
#define __SaveColors_x                                             0x545890
#define __STMLToText_x                                             0x922690
#define __ToggleKeyRingItem_x                                      0x508790
#define CMemoryMappedFile__SetFile_x                               0xA590C0
#define CrashDetected_x                                            0x6A6BE0
#define DrawNetStatus_x                                            0x6279B0
#define Expansion_HoT_x                                            0xE8F32C
#define Teleport_Table_Size_x                                      0xE806A8
#define Teleport_Table_x                                           0xE7E478
#define Util__FastTime_x                                           0x8EEB20
#define wwsCrashReportCheckForUploader_x                           0x850D90
#define wwsCrashReportPlatformLaunchUploader_x                     0x853450

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48B5C0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x494460
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x494220
#define CAdvancedLootWnd__AddPlayerToList_x                        0x48EB20
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x48DF80

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x54D4A0
#define AltAdvManager__IsAbilityReady_x                            0x54C3F0
#define AltAdvManager__GetAAById_x                                 0x54C5F0
#define AltAdvManager__CanTrainAbility_x                           0x54C660
#define AltAdvManager__CanSeeAbility_x                             0x54C9C0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C72A0
#define CharacterZoneClient__HasSkill_x                            0x4D2170
#define CharacterZoneClient__MakeMeVisible_x                       0x4D3890
#define CharacterZoneClient__IsStackBlocked_x                      0x4BB750
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B7E90
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D6240
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D6320
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D6400
#define CharacterZoneClient__FindAffectSlot_x                      0x4C0240
#define CharacterZoneClient__BardCastBard_x                        0x4C2EB0
#define CharacterZoneClient__GetMaxEffects_x                       0x4B7F60
#define CharacterZoneClient__GetEffect_x                           0x4B7DD0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C1240
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C1310
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C1360
#define CharacterZoneClient__CalcAffectChange_x                    0x4C14B0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C1680
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4AFC40
#define CharacterZoneClient__FindItemByGuid_x                      0x4D4800
#define CharacterZoneClient__FindItemByRecord_x                    0x4D4270

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6CEDB0
#define CBankWnd__WndNotification_x                                0x6CEB90

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6DC480

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x60A280
#define CButtonWnd__CButtonWnd_x                                   0x91EA40

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6FC5A0
#define CChatManager__InitContextMenu_x                            0x6F5920
#define CChatManager__FreeChatWindow_x                             0x6FB160
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E5A80
#define CChatManager__SetLockedActiveChatWindow_x                  0x6FC220
#define CChatManager__CreateChatWindow_x                           0x6FB790

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E5B40

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x9331C0
#define CContextMenu__dCContextMenu_x                              0x9333F0
#define CContextMenu__AddMenuItem_x                                0x933400
#define CContextMenu__RemoveMenuItem_x                             0x933710
#define CContextMenu__RemoveAllMenuItems_x                         0x933730
#define CContextMenu__CheckMenuItem_x                              0x9337B0
#define CContextMenu__SetMenuItem_x                                0x933630
#define CContextMenu__AddSeparator_x                               0x933590

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x933D50
#define CContextMenuManager__RemoveMenu_x                          0x933DC0
#define CContextMenuManager__PopupMenu_x                           0x933E80
#define CContextMenuManager__Flush_x                               0x933CF0
#define CContextMenuManager__GetMenu_x                             0x496580
#define CContextMenuManager__CreateDefaultMenu_x                   0x707C70

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8CF8E0
#define CChatService__GetFriendName_x                              0x8CF8F0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6FCE00
#define CChatWindow__Clear_x                                       0x6FE0A0
#define CChatWindow__WndNotification_x                             0x6FE820
#define CChatWindow__AddHistory_x                                  0x6FD970

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x930650
#define CComboWnd__Draw_x                                          0x92FB50
#define CComboWnd__GetCurChoice_x                                  0x930490
#define CComboWnd__GetListRect_x                                   0x930000
#define CComboWnd__GetTextRect_x                                   0x9306C0
#define CComboWnd__InsertChoice_x                                  0x930190
#define CComboWnd__SetColors_x                                     0x930160
#define CComboWnd__SetChoice_x                                     0x930460
#define CComboWnd__GetItemCount_x                                  0x9304A0
#define CComboWnd__GetCurChoiceText_x                              0x9304E0
#define CComboWnd__GetChoiceText_x                                 0x9304B0
#define CComboWnd__InsertChoiceAtIndex_x                           0x930220

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x705670
#define CContainerWnd__vftable_x                                   0xADE6F0
#define CContainerWnd__SetContainer_x                              0x706BE0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x545650
#define CDisplay__GetClickedActor_x                                0x538600
#define CDisplay__GetUserDefinedColor_x                            0x530CE0
#define CDisplay__GetWorldFilePath_x                               0x53A050
#define CDisplay__is3dON_x                                         0x5352D0
#define CDisplay__ReloadUI_x                                       0x53F770
#define CDisplay__WriteTextHD2_x                                   0x5350B0
#define CDisplay__TrueDistance_x                                   0x53BCB0
#define CDisplay__SetViewActor_x                                   0x537F50
#define CDisplay__GetFloorHeight_x                                 0x535390
#define CDisplay__SetRenderWindow_x                                0x533CC0
#define CDisplay__ToggleScreenshotMode_x                           0x537A20

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x952AF0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x936720
#define CEditWnd__GetCharIndexPt_x                                 0x937620
#define CEditWnd__GetDisplayString_x                               0x9374C0
#define CEditWnd__GetHorzOffset_x                                  0x935D50
#define CEditWnd__GetLineForPrintableChar_x                        0x938820
#define CEditWnd__GetSelStartPt_x                                  0x9378D0
#define CEditWnd__GetSTMLSafeText_x                                0x9372E0
#define CEditWnd__PointFromPrintableChar_x                         0x938450
#define CEditWnd__SelectableCharFromPoint_x                        0x9385C0
#define CEditWnd__SetEditable_x                                    0x9379A0
#define CEditWnd__SetWindowTextA_x                                 0x937060

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5E9540
#define CEverQuest__ClickedPlayer_x                                0x5DB670
#define CEverQuest__CreateTargetIndicator_x                        0x5F8970
#define CEverQuest__DeleteTargetIndicator_x                        0x5F8A00
#define CEverQuest__DoTellWindow_x                                 0x4E5C20
#define CEverQuest__OutputTextToLog_x                              0x4E5E50
#define CEverQuest__DropHeldItemOnGround_x                         0x5D06B0
#define CEverQuest__dsp_chat_x                                     0x4E61E0
#define CEverQuest__trimName_x                                     0x5F4C50
#define CEverQuest__Emote_x                                        0x5E9D50
#define CEverQuest__EnterZone_x                                    0x5E3D30
#define CEverQuest__GetBodyTypeDesc_x                              0x5EE500
#define CEverQuest__GetClassDesc_x                                 0x5EEB40
#define CEverQuest__GetClassThreeLetterCode_x                      0x5EF140
#define CEverQuest__GetDeityDesc_x                                 0x5F72C0
#define CEverQuest__GetLangDesc_x                                  0x5EF300
#define CEverQuest__GetRaceDesc_x                                  0x5EEB20
#define CEverQuest__InterpretCmd_x                                 0x5F7890
#define CEverQuest__LeftClickedOnPlayer_x                          0x5D48A0
#define CEverQuest__LMouseUp_x                                     0x5D2C20
#define CEverQuest__RightClickedOnPlayer_x                         0x5D5180
#define CEverQuest__RMouseUp_x                                     0x5D3BB0
#define CEverQuest__SetGameState_x                                 0x5D0440
#define CEverQuest__UPCNotificationFlush_x                         0x5F4B50
#define CEverQuest__IssuePetCommand_x                              0x5F0700
#define CEverQuest__ReportSuccessfulHit_x                          0x5EB150

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x717660
#define CGaugeWnd__CalcLinesFillRect_x                             0x7176C0
#define CGaugeWnd__Draw_x                                          0x716D60

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AC8D0
#define CGuild__GetGuildName_x                                     0x4AB9B0
#define CGuild__GetGuildIndex_x                                    0x4ABD40

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x7329F0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x60A640

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x73F8D0
#define CInvSlotMgr__MoveItem_x                                    0x73E5F0
#define CInvSlotMgr__SelectSlot_x                                  0x73F9A0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x73CE90
#define CInvSlot__SliderComplete_x                                 0x73AC00
#define CInvSlot__GetItemBase_x                                    0x73A580
#define CInvSlot__UpdateItem_x                                     0x73A6F0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x741410
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7405C0
#define CInvSlotWnd__HandleLButtonUp_x                             0x740F90

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7FDA50
#define CItemDisplayWnd__UpdateStrings_x                           0x74F850
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x749650
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x749B60
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x74FE50
#define CItemDisplayWnd__AboutToShow_x                             0x74F4A0
#define CItemDisplayWnd__WndNotification_x                         0x751360
#define CItemDisplayWnd__RequestConvertItem_x                      0x750E20
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x74E500
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x74F2C0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x835470

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x755410

// CLabel 
#define CLabel__Draw_x                                             0x75AEA0

// CListWnd
#define CListWnd__CListWnd_x                                       0x908E70
#define CListWnd__dCListWnd_x                                      0x909180
#define CListWnd__AddColumn_x                                      0x90D490
#define CListWnd__AddColumn1_x                                     0x90D4E0
#define CListWnd__AddLine_x                                        0x90D870
#define CListWnd__AddString_x                                      0x90D670
#define CListWnd__CalculateFirstVisibleLine_x                      0x90D260
#define CListWnd__CalculateVSBRange_x                              0x90D050
#define CListWnd__ClearSel_x                                       0x90E050
#define CListWnd__ClearAllSel_x                                    0x90E0B0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x90EAB0
#define CListWnd__Compare_x                                        0x90C990
#define CListWnd__Draw_x                                           0x909280
#define CListWnd__DrawColumnSeparators_x                           0x90BA60
#define CListWnd__DrawHeader_x                                     0x90BED0
#define CListWnd__DrawItem_x                                       0x90C2D0
#define CListWnd__DrawLine_x                                       0x90BBD0
#define CListWnd__DrawSeparator_x                                  0x90BB00
#define CListWnd__EnableLine_x                                     0x90B340
#define CListWnd__EnsureVisible_x                                  0x90E9E0
#define CListWnd__ExtendSel_x                                      0x90DF80
#define CListWnd__GetColumnTooltip_x                               0x90AE80
#define CListWnd__GetColumnMinWidth_x                              0x90AEF0
#define CListWnd__GetColumnWidth_x                                 0x90ADF0
#define CListWnd__GetCurSel_x                                      0x90A780
#define CListWnd__GetItemAtPoint_x                                 0x90B5B0
#define CListWnd__GetItemAtPoint1_x                                0x90B620
#define CListWnd__GetItemData_x                                    0x90A800
#define CListWnd__GetItemHeight_x                                  0x90ABC0
#define CListWnd__GetItemIcon_x                                    0x90A990
#define CListWnd__GetItemRect_x                                    0x90B430
#define CListWnd__GetItemText_x                                    0x90A840
#define CListWnd__GetSelList_x                                     0x90E100
#define CListWnd__GetSeparatorRect_x                               0x90B860
#define CListWnd__InsertLine_x                                     0x90DC60
#define CListWnd__RemoveLine_x                                     0x90DDB0
#define CListWnd__SetColors_x                                      0x90D020
#define CListWnd__SetColumnJustification_x                         0x90CD50
#define CListWnd__SetColumnWidth_x                                 0x90CC70
#define CListWnd__SetCurSel_x                                      0x90DEC0
#define CListWnd__SetItemColor_x                                   0x90E6A0
#define CListWnd__SetItemData_x                                    0x90E660
#define CListWnd__SetItemText_x                                    0x90E270
#define CListWnd__ShiftColumnSeparator_x                           0x90CE10
#define CListWnd__Sort_x                                           0x90CB10
#define CListWnd__ToggleSel_x                                      0x90DEF0
#define CListWnd__SetColumnsSizable_x                              0x90CEB0
#define CListWnd__SetItemWnd_x                                     0x90E520
#define CListWnd__GetItemWnd_x                                     0x90A9E0
#define CListWnd__SetItemIcon_x                                    0x90E2F0
#define CListWnd__CalculateCustomWindowPositions_x                 0x90D350
#define CListWnd__SetVScrollPos_x                                  0x90CC50

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7704E0
#define CMapViewWnd__GetWorldCoordinates_x                         0x76EBF0
#define CMapViewWnd__HandleLButtonDown_x                           0x76BC50

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x793520
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x793E00
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x794330
#define CMerchantWnd__SelectRecoverySlot_x                         0x7972A0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x792080
#define CMerchantWnd__SelectBuySellSlot_x                          0x79CE70
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x793140

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89D4F0
#define CPacketScrambler__hton_x                                   0x89D4E0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x927C40
#define CSidlManager__FindScreenPieceTemplate_x                    0x928050
#define CSidlManager__FindScreenPieceTemplate1_x                   0x927E40
#define CSidlManager__CreateLabel_x                                0x7F4F50
#define CSidlManager__CreateXWndFromTemplate_x                     0x92AFF0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x92B1D0
#define CSidlManager__CreateXWnd_x                                 0x7F4E80
#define CSidlManager__CreateHotButtonWnd_x                         0x7F5430

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9247C0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9246C0
#define CSidlScreenWnd__ConvertToRes_x                             0x949AB0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x924160
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x923E50
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x923F20
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x923FF0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x924C50
#define CSidlScreenWnd__EnableIniStorage_x                         0x925120
#define CSidlScreenWnd__GetSidlPiece_x                             0x924E40
#define CSidlScreenWnd__Init1_x                                    0x923A60
#define CSidlScreenWnd__LoadIniInfo_x                              0x925170
#define CSidlScreenWnd__LoadIniListWnd_x                           0x925CB0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x922E70
#define CSidlScreenWnd__StoreIniInfo_x                             0x925830
#define CSidlScreenWnd__StoreIniVis_x                              0x925B90
#define CSidlScreenWnd__WndNotification_x                          0x924B60
#define CSidlScreenWnd__GetChildItem_x                             0x9250A0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x914830
#define CSidlScreenWnd__m_layoutCopy_x                             0x16C97C8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x66EAC0
#define CSkillMgr__GetSkillCap_x                                   0x66ECA0
#define CSkillMgr__GetNameToken_x                                  0x66E250
#define CSkillMgr__IsActivatedSkill_x                              0x66E390
#define CSkillMgr__IsCombatSkill_x                                 0x66E2D0


// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x934B20
#define CSliderWnd__SetValue_x                                     0x934990
#define CSliderWnd__SetNumTicks_x                                  0x9349F0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7FAFB0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x93D2C0
#define CStmlWnd__CalculateHSBRange_x                              0x93E390
#define CStmlWnd__CalculateVSBRange_x                              0x93E300
#define CStmlWnd__CanBreakAtCharacter_x                            0x9426C0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x943350
#define CStmlWnd__ForceParseNow_x                                  0x93D860
#define CStmlWnd__GetNextTagPiece_x                                0x942620
#define CStmlWnd__GetSTMLText_x                                    0x4F7CD0
#define CStmlWnd__GetVisibleText_x                                 0x93D880
#define CStmlWnd__InitializeWindowVariables_x                      0x9431A0
#define CStmlWnd__MakeStmlColorTag_x                               0x93C9A0
#define CStmlWnd__MakeWndNotificationTag_x                         0x93CA10
#define CStmlWnd__SetSTMLText_x                                    0x93BA50
#define CStmlWnd__StripFirstSTMLLines_x                            0x944440
#define CStmlWnd__UpdateHistoryString_x                            0x943560

// CTabWnd 
#define CTabWnd__Draw_x                                            0x93ABD0
#define CTabWnd__DrawCurrentPage_x                                 0x93B2B0
#define CTabWnd__DrawTab_x                                         0x93AFD0
#define CTabWnd__GetCurrentPage_x                                  0x93A3E0
#define CTabWnd__GetPageInnerRect_x                                0x93A620
#define CTabWnd__GetTabInnerRect_x                                 0x93A560
#define CTabWnd__GetTabRect_x                                      0x93A410
#define CTabWnd__InsertPage_x                                      0x93A830
#define CTabWnd__SetPage_x                                         0x93A6A0
#define CTabWnd__SetPageRect_x                                     0x93AB10
#define CTabWnd__UpdatePage_x                                      0x93AE90
#define CTabWnd__GetPageFromTabIndex_x                             0x93AF10
#define CTabWnd__GetCurrentTabIndex_x                              0x93A3D0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x755870
#define CPageWnd__SetTabText_x                                     0x939F30

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A64D0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x9116C0
#define CTextureFont__GetTextExtent_x                              0x911880

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6A21D0
#define CHtmlComponentWnd__ValidateUri_x                           0x7343E0
#define CHtmlWnd__SetClientCallbacks_x                             0x60F6A0
#define CHtmlWnd__AddObserver_x                                    0x60F6C0
#define CHtmlWnd__RemoveObserver_x                                 0x60F720
#define Window__getProgress_x                                      0x84DAF0
#define Window__getStatus_x                                        0x84DB10
#define Window__getURI_x                                           0x84DB20

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x94F4D0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8FE8C0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4ADC30
#define CXStr__CXStr1_x                                            0x9C0A40
#define CXStr__CXStr3_x                                            0x8EB050
#define CXStr__dCXStr_x                                            0x473060
#define CXStr__operator_equal_x                                    0x8EB280
#define CXStr__operator_equal1_x                                   0x8EB2C0
#define CXStr__operator_plus_equal1_x                              0x8EBD50
#define CXStr__SetString_x                                         0x8EDC40
#define CXStr__operator_char_p_x                                   0x8EB790
#define CXStr__GetChar_x                                           0x8ED570
#define CXStr__Delete_x                                            0x8ECE40
#define CXStr__GetUnicode_x                                        0x8ED5E0
#define CXStr__GetLength_x                                         0x4A6280
#define CXStr__Mid_x                                               0x477C50
#define CXStr__Insert_x                                            0x8ED640
#define CXStr__FindNext_x                                          0x8ED2B0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x932DD0
#define CXWnd__BringToTop_x                                        0x917FE0
#define CXWnd__Center_x                                            0x917B60
#define CXWnd__ClrFocus_x                                          0x9179A0
#define CXWnd__Destroy_x                                           0x917A40
#define CXWnd__DoAllDrawing_x                                      0x913FD0
#define CXWnd__DrawChildren_x                                      0x913FA0
#define CXWnd__DrawColoredRect_x                                   0x914420
#define CXWnd__DrawTooltip_x                                       0x912AF0
#define CXWnd__DrawTooltipAtPoint_x                                0x912BB0
#define CXWnd__GetBorderFrame_x                                    0x914280
#define CXWnd__GetChildWndAt_x                                     0x918080
#define CXWnd__GetClientClipRect_x                                 0x916270
#define CXWnd__GetScreenClipRect_x                                 0x916340
#define CXWnd__GetScreenRect_x                                     0x916500
#define CXWnd__GetTooltipRect_x                                    0x914470
#define CXWnd__GetWindowTextA_x                                    0x497C40
#define CXWnd__IsActive_x                                          0x914BA0
#define CXWnd__IsDescendantOf_x                                    0x916F00
#define CXWnd__IsReallyVisible_x                                   0x916F30
#define CXWnd__IsType_x                                            0x9186E0
#define CXWnd__Move_x                                              0x916FA0
#define CXWnd__Move1_x                                             0x917050
#define CXWnd__ProcessTransition_x                                 0x917B10
#define CXWnd__Refade_x                                            0x917310
#define CXWnd__Resize_x                                            0x9175B0
#define CXWnd__Right_x                                             0x917DA0
#define CXWnd__SetFocus_x                                          0x917960
#define CXWnd__SetFont_x                                           0x9179D0
#define CXWnd__SetKeyTooltip_x                                     0x918500
#define CXWnd__SetMouseOver_x                                      0x9153E0
#define CXWnd__StartFade_x                                         0x916DD0
#define CXWnd__GetChildItem_x                                      0x9181F0
#define CXWnd__SetParent_x                                         0x916CA0
#define CXWnd__Minimize_x                                          0x917620

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x94AB40

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x91AFA0
#define CXWndManager__DrawWindows_x                                0x91AFC0
#define CXWndManager__GetKeyboardFlags_x                           0x91D710
#define CXWndManager__HandleKeyboardMsg_x                          0x91D320
#define CXWndManager__RemoveWnd_x                                  0x91D960
#define CXWndManager__RemovePendingDeletionWnd_x                   0x91DEC0

// CDBStr
#define CDBStr__GetString_x                                        0x52FC80

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B8E70
#define EQ_Character__Cur_HP_x                                     0x4CF150
#define EQ_Character__Cur_Mana_x                                   0x4D6900
#define EQ_Character__GetCastingTimeModifier_x                     0x4BBDA0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AF880
#define EQ_Character__GetFocusRangeModifier_x                      0x4AF9D0
#define EQ_Character__GetHPRegen_x                                 0x4DC800
#define EQ_Character__GetEnduranceRegen_x                          0x4DCE10
#define EQ_Character__GetManaRegen_x                               0x4DD250
#define EQ_Character__Max_Endurance_x                              0x6351E0
#define EQ_Character__Max_HP_x                                     0x4CEF80
#define EQ_Character__Max_Mana_x                                   0x634FE0
#define EQ_Character__doCombatAbility_x                            0x6376A0
#define EQ_Character__UseSkill_x                                   0x4DF040
#define EQ_Character__GetConLevel_x                                0x62E930
#define EQ_Character__IsExpansionFlag_x                            0x592D80
#define EQ_Character__TotalEffect_x                                0x4C2410
#define EQ_Character__GetPCSpellAffect_x                           0x4BC990
#define EQ_Character__SpellDuration_x                              0x4BC4C0
#define EQ_Character__GetAdjustedSkill_x                           0x4D1F30
#define EQ_Character__GetBaseSkill_x                               0x4D2ED0
#define EQ_Character__CanUseItem_x                                 0x4D6C10

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BC690

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x64B820

//PcClient
#define PcClient__PcClient_x                                       0x62C070

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6AB0
#define CCharacterListWnd__EnterWorld_x                            0x4B64F0
#define CCharacterListWnd__Quit_x                                  0x4B6200
#define CCharacterListWnd__UpdateList_x                            0x4B6680

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6108B0
#define EQ_Item__CreateItemTagString_x                             0x896E40
#define EQ_Item__IsStackable_x                                     0x89B860
#define EQ_Item__GetImageNum_x                                     0x898860
#define EQ_Item__CreateItemClient_x                                0x60FA80
#define EQ_Item__GetItemValue_x                                    0x899AE0
#define EQ_Item__ValueSellMerchant_x                               0x89D090
#define EQ_Item__IsKeyRingItem_x                                   0x89B1C0
#define EQ_Item__CanGoInBag_x                                      0x6109D0
#define EQ_Item__IsEmpty_x                                         0x89ACD0
#define EQ_Item__GetMaxItemCount_x                                 0x899EA0
#define EQ_Item__GetHeldItem_x                                     0x898730
#define EQ_Item__GetAugmentFitBySlot_x                             0x896790

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x54E190
#define EQ_LoadingS__Array_x                                       0xBF2600

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x635B40
#define EQ_PC__GetAlternateAbilityId_x                             0x8A61F0
#define EQ_PC__GetCombatAbility_x                                  0x8A6860
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A68D0
#define EQ_PC__GetItemRecastTimer_x                                0x637C20
#define EQ_PC__HasLoreItem_x                                       0x62F150
#define EQ_PC__AlertInventoryChanged_x                             0x62E270
#define EQ_PC__GetPcZoneClient_x                                   0x659EF0
#define EQ_PC__RemoveMyAffect_x                                    0x63AE40
#define EQ_PC__GetKeyRingItems_x                                   0x8A7170
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A6EF0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A7460

// EQItemList
#define EQItemList__EQItemList_x                                   0x5992E0
#define EQItemList__add_object_x                                   0x5C5DC0
#define EQItemList__add_item_x                                     0x599830
#define EQItemList__delete_item_x                                  0x599880
#define EQItemList__FreeItemList_x                                 0x599780

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x52D290

// EQPlayer
#define EQPlayer__ChangeBoneStringSprite_x                         0x64D0A0
#define EQPlayer__dEQPlayer_x                                      0x6403D0
#define EQPlayer__DoAttack_x                                       0x654BC0
#define EQPlayer__EQPlayer_x                                       0x640A80
#define EQPlayer__SetNameSpriteState_x                             0x644D30
#define EQPlayer__SetNameSpriteTint_x                              0x645C00
#define PlayerBase__HasProperty_j_x                                0x97D1D0
#define EQPlayer__IsTargetable_x                                   0x97D670
#define EQPlayer__CanSee_x                                         0x97D4D0
#define EQPlayer__CanSee1_x                                        0x97D5A0
#define PlayerBase__GetVisibilityLineSegment_x                     0x97D290

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x6579A0
#define PlayerZoneClient__GetLevel_x                               0x659F30
#define PlayerZoneClient__IsValidTeleport_x                        0x5C6F30
#define PlayerZoneClient__LegalPlayerRace_x                        0x547500

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x64FD90
#define EQPlayerManager__GetSpawnByName_x                          0x64FDB0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x64FE40

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x614030
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x6140B0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x6140F0
#define KeypressHandler__ClearCommandStateArray_x                  0x615500
#define KeypressHandler__HandleKeyDown_x                           0x615520
#define KeypressHandler__HandleKeyUp_x                             0x6155C0
#define KeypressHandler__SaveKeymapping_x                          0x6159F0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x76C370
#define MapViewMap__SaveEx_x                                       0x76F710
#define MapViewMap__SetZoom_x                                      0x773DD0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BA580

// StringTable 
#define StringTable__getString_x                                   0x8B5330

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x63AAB0
#define PcZoneClient__RemovePetEffect_x                            0x63B0E0
#define PcZoneClient__HasAlternateAbility_x                        0x634E20
#define PcZoneClient__GetCurrentMod_x                              0x4E2130
#define PcZoneClient__GetModCap_x                                  0x4E2030
#define PcZoneClient__CanEquipItem_x                               0x6354D0
#define PcZoneClient__GetItemByID_x                                0x638090
#define PcZoneClient__GetItemByItemClass_x                         0x6381E0
#define PcZoneClient__RemoveBuffEffect_x                           0x63B100
#define PcZoneClient__BandolierSwap_x                              0x636100
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x637BC0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5CBB70

//IconCache
#define IconCache__GetIcon_x                                       0x70CD00

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x704810
#define CContainerMgr__CloseContainer_x                            0x704AE0
#define CContainerMgr__OpenExperimentContainer_x                   0x705560

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7C75D0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x608A70

//CLootWnd
#define CLootWnd__LootAll_x                                        0x7626A0
#define CLootWnd__RequestLootSlot_x                                0x761A60

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x566470
#define EQ_Spell__SpellAffects_x                                   0x5668E0
#define EQ_Spell__SpellAffectBase_x                                0x5666A0
#define EQ_Spell__IsStackable_x                                    0x4C6BB0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C6A60
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B3E10
#define EQ_Spell__IsSPAStacking_x                                  0x567710
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x566C30
#define EQ_Spell__IsNoRemove_x                                     0x4C6B90
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x567720
#define __IsResEffectSpell_x                                       0x4C5FA0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AA5F0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C4D60

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x80CDD0
#define CTargetWnd__WndNotification_x                              0x80C660
#define CTargetWnd__RefreshTargetBuffs_x                           0x80C930
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x80B7C0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x8114C0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x52AC20
#define CTaskManager__HandleMessage_x                              0x529360

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x561A20
#define EqSoundManager__PlayScriptMp3_x                            0x561B80
#define EqSoundManager__SoundAssistPlay_x                          0x672A00
#define EqSoundManager__WaveInstancePlay_x                         0x671F70

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x51EBF0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x939430

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x555B20
#define CAltAbilityData__GetMercMaxRank_x                          0x555AC0
#define CAltAbilityData__GetMaxRank_x                              0x54B2A0

//CTargetRing
#define CTargetRing__Cast_x                                        0x606B70

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C6A40
#define CharacterBase__CreateItemGlobalIndex_x                     0x504A40
#define CharacterBase__CreateItemIndex_x                           0x60EC60
#define CharacterBase__GetItemPossession_x                         0x4F0910
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CD3B0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CD410
#define CharacterBase__GetEffectId_x                               0x4C69F0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6EBBB0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6EC3E0

//messages
#define msg_spell_worn_off_x                                       0x58AF60
#define msg_new_text_x                                             0x57FDA0
#define __msgTokenTextParam_x                                      0x58D480
#define msgTokenText_x                                             0x58D6D0

//SpellManager
#define SpellManager__vftable_x                                    0xAB8C68
#define SpellManager__SpellManager_x                               0x675D30
#define Spellmanager__LoadTextSpells_x                             0x676600
#define SpellManager__GetSpellByGroupAndRank_x                     0x675F00

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x505130
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5912B0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x627810
#define ItemGlobalIndex__IsValidIndex_x                            0x505190

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C56A0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C5920

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x75B1E0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x708F10
#define CCursorAttachment__AttachToCursor1_x                       0x708F50
#define CCursorAttachment__Deactivate_x                            0x709F30

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x92BFE0
#define CSidlManagerBase__CreatePageWnd_x                          0x92B800
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x927A60
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x9279F0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x948F20
#define CEQSuiteTextureLoader__GetTexture_x                        0x948BE0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x502010
#define CFindItemWnd__WndNotification_x                            0x502AF0
#define CFindItemWnd__Update_x                                     0x503630
#define CFindItemWnd__PickupSelectedItem_x                         0x501880

//IString
#define IString__Append_x                                          0x4F1EF0

//Camera
#define CDisplay__cameraType_x                                     0xDCC298
#define EverQuest__Cameras_x                                       0xE8F670

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x50AA80
#define LootFiltersManager__GetItemFilterData_x                    0x50A370
#define LootFiltersManager__RemoveItemLootFilter_x                 0x50A3A0
#define LootFiltersManager__SetItemLootFilter_x                    0x50A5C0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B5560

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x986F50
#define CResolutionHandler__GetWindowedStyle_x                     0x66D610

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x701540

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D7F30
#define CDistillerInfo__Instance_x                                 0x8D7ED0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x7217B0
#define CGroupWnd__UpdateDisplay_x                                 0x720B20

//ItemBase
#define ItemBase__IsLore_x                                         0x89B220
#define ItemBase__IsLoreEquipped_x                                 0x89B290

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5C5D20
#define EQPlacedItemManager__GetItemByGuid_x                       0x5C5E60
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5C5EC0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x662A20
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x6663C0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x4F8430

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4E7560
#define FactionManagerClient__HandleFactionMessage_x               0x4E7BD0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4E81C0
#define FactionManagerClient__GetMaxFaction_x                      0x4E8210
#define FactionManagerClient__GetMinFaction_x                      0x4E8190

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4F08E0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x910730

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x496F30

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4F0B40

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x555000

//CTargetManager
#define CTargetManager__Get_x                                      0x6795A0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x662A20

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A6290

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x599720

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF2CD00

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
