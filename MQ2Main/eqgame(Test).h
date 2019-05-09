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
#define __ExpectedVersionDate                                     "May  7 2019"
#define __ExpectedVersionTime                                     "12:23:43"
#define __ActualVersionDate_x                                      0xAD548C
#define __ActualVersionTime_x                                      0xAD5480
#define __ActualVersionBuild_x                                     0xAD5F24

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x61A8A0
#define __MemChecker1_x                                            0x8EF820
#define __MemChecker2_x                                            0x6A9920
#define __MemChecker3_x                                            0x6A9870
#define __MemChecker4_x                                            0x8468F0
#define __EncryptPad0_x                                            0xC0A9B0
#define __EncryptPad1_x                                            0xC68938
#define __EncryptPad2_x                                            0xC1B228
#define __EncryptPad3_x                                            0xC1AE28
#define __EncryptPad4_x                                            0xC591A0
#define __EncryptPad5_x                                            0xF33310
#define __AC1_x                                                    0x8035E6
#define __AC2_x                                                    0x5D435F
#define __AC3_x                                                    0x5DBA6F
#define __AC4_x                                                    0x5DF8F0
#define __AC5_x                                                    0x5E5B60
#define __AC6_x                                                    0x5EA1F6
#define __AC7_x                                                    0x5D3DD0
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
#define __do_loot_x                                                0x5A0C10
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
#define __gfMaxZoomCameraDistance_x                                0xACA920
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
#define pinstCCastSpellWnd_x                                       0xDCC0E8
//#define pinstCCharacterCreationWnd_x                               0xDA8EBC
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
#define pinstCItemOverflowWnd_x                                    0xDCBCE4
#define pinstCJournalCatWnd_x                                      0xDCBC5C
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
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
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
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
//#define pinstCRewardSelectionWnd_x                               0x10205B0
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
#define __CastRay_x                                                0x59C070
#define __CastRay2_x                                               0x59C0C0
#define __ConvertItemTags_x                                        0x5B78E0
#define __CrashHandler_x                                           0x850270
#define __DoesFileExist_x                                          0x8F28C0
#define __EQGetTime_x                                              0x8EF300
#define __ExecuteCmd_x                                             0x594990
#define __FixHeading_x                                             0x97F1B0
#define __GameLoop_x                                               0x6A8DE0
#define __get_bearing_x                                            0x59BBC0
#define __get_melee_range_x                                        0x59C2B0
#define __GetAnimationCache_x                                      0x70DD60
#define __GetGaugeValueFromEQ_x                                    0x801DF0
#define __GetLabelFromEQ_x                                         0x803570
#define __GetXTargetType_x                                         0x980C10
#define __HandleMouseWheel_x                                       0x6A99D0
#define __HeadingDiff_x                                            0x97F220
#define __HelpPath_x                                               0xF2D3CC
#define __LoadFrontEnd_x                                           0x6A58B0
#define __NewUIINI_x                                               0x801AC0
#define __pCrashHandler_x                                          0x106E768
#define __ProcessGameEvents_x                                      0x5FB8B0
#define __ProcessMouseEvent_x                                      0x5FB070
#define __SaveColors_x                                             0x5459D0
#define __STMLToText_x                                             0x922970
#define __ToggleKeyRingItem_x                                      0x508820
#define CMemoryMappedFile__SetFile_x                               0xA594B0
#define CrashDetected_x                                            0x6A7310
#define DrawNetStatus_x                                            0x627A70
#define Expansion_HoT_x                                            0xE8F32C
#define Teleport_Table_Size_x                                      0xE806A8
#define Teleport_Table_x                                           0xE7E478
#define Util__FastTime_x                                           0x8EEEC0
#define wwsCrashReportCheckForUploader_x                           0x851170
#define wwsCrashReportPlatformLaunchUploader_x                     0x853830

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48B8B0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x494750
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x494510
#define CAdvancedLootWnd__AddPlayerToList_x                        0x48EE10
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x48E270

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x54D610
#define AltAdvManager__IsAbilityReady_x                            0x54C560
#define AltAdvManager__GetAAById_x                                 0x54C760
#define AltAdvManager__CanTrainAbility_x                           0x54C7D0
#define AltAdvManager__CanSeeAbility_x                             0x54CB30

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C74E0
#define CharacterZoneClient__HasSkill_x                            0x4D23B0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D3AD0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BB8E0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B8030
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D6470
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D6550
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D6630
#define CharacterZoneClient__FindAffectSlot_x                      0x4C03D0
#define CharacterZoneClient__BardCastBard_x                        0x4C3030
#define CharacterZoneClient__GetMaxEffects_x                       0x4B8100
#define CharacterZoneClient__GetEffect_x                           0x4B7F70
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C13D0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C14A0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C14F0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C1640
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C1810
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4AFE30
#define CharacterZoneClient__FindItemByGuid_x                      0x4D4A40
#define CharacterZoneClient__FindItemByRecord_x                    0x4D44B0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6CF560
#define CBankWnd__WndNotification_x                                0x6CF340

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6DD010

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x60A580
#define CButtonWnd__CButtonWnd_x                                   0x91ED40

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6FCE10
#define CChatManager__InitContextMenu_x                            0x6F6190
#define CChatManager__FreeChatWindow_x                             0x6FB9D0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E5BE0
#define CChatManager__SetLockedActiveChatWindow_x                  0x6FCA90
#define CChatManager__CreateChatWindow_x                           0x6FC000

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E5CF0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x933370
#define CContextMenu__dCContextMenu_x                              0x9335A0
#define CContextMenu__AddMenuItem_x                                0x9335B0
#define CContextMenu__RemoveMenuItem_x                             0x9338C0
#define CContextMenu__RemoveAllMenuItems_x                         0x9338E0
#define CContextMenu__CheckMenuItem_x                              0x933960
#define CContextMenu__SetMenuItem_x                                0x9337E0
#define CContextMenu__AddSeparator_x                               0x933740

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x933F00
#define CContextMenuManager__RemoveMenu_x                          0x933F70
#define CContextMenuManager__PopupMenu_x                           0x934030
#define CContextMenuManager__Flush_x                               0x933EA0
#define CContextMenuManager__GetMenu_x                             0x496910
#define CContextMenuManager__CreateDefaultMenu_x                   0x7084A0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8CFC20
#define CChatService__GetFriendName_x                              0x8CFC30

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6FD6A0
#define CChatWindow__Clear_x                                       0x6FE940
#define CChatWindow__WndNotification_x                             0x6FF0D0
#define CChatWindow__AddHistory_x                                  0x6FE210

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x9307F0
#define CComboWnd__Draw_x                                          0x92FCF0
#define CComboWnd__GetCurChoice_x                                  0x930630
#define CComboWnd__GetListRect_x                                   0x9301A0
#define CComboWnd__GetTextRect_x                                   0x930860
#define CComboWnd__InsertChoice_x                                  0x930330
#define CComboWnd__SetColors_x                                     0x930300
#define CComboWnd__SetChoice_x                                     0x930600
#define CComboWnd__GetItemCount_x                                  0x930640
#define CComboWnd__GetCurChoiceText_x                              0x930680
#define CComboWnd__GetChoiceText_x                                 0x930650
#define CComboWnd__InsertChoiceAtIndex_x                           0x9303C0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x705E90
#define CContainerWnd__vftable_x                                   0xADE6F0
#define CContainerWnd__SetContainer_x                              0x707400

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x545790
#define CDisplay__GetClickedActor_x                                0x538740
#define CDisplay__GetUserDefinedColor_x                            0x530E20
#define CDisplay__GetWorldFilePath_x                               0x53A190
#define CDisplay__is3dON_x                                         0x535410
#define CDisplay__ReloadUI_x                                       0x53F8B0
#define CDisplay__WriteTextHD2_x                                   0x5351F0
#define CDisplay__TrueDistance_x                                   0x53BDF0
#define CDisplay__SetViewActor_x                                   0x538090
#define CDisplay__GetFloorHeight_x                                 0x5354D0
#define CDisplay__SetRenderWindow_x                                0x533E00
#define CDisplay__ToggleScreenshotMode_x                           0x537B60

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x952E10

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x9368F0
#define CEditWnd__GetCharIndexPt_x                                 0x9377F0
#define CEditWnd__GetDisplayString_x                               0x937690
#define CEditWnd__GetHorzOffset_x                                  0x935F30
#define CEditWnd__GetLineForPrintableChar_x                        0x9389F0
#define CEditWnd__GetSelStartPt_x                                  0x937AA0
#define CEditWnd__GetSTMLSafeText_x                                0x9374B0
#define CEditWnd__PointFromPrintableChar_x                         0x938620
#define CEditWnd__SelectableCharFromPoint_x                        0x938790
#define CEditWnd__SetEditable_x                                    0x937B70
#define CEditWnd__SetWindowTextA_x                                 0x937230

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5E9720
#define CEverQuest__ClickedPlayer_x                                0x5DB850
#define CEverQuest__CreateTargetIndicator_x                        0x5F8B60
#define CEverQuest__DeleteTargetIndicator_x                        0x5F8BF0
#define CEverQuest__DoTellWindow_x                                 0x4E5DD0
#define CEverQuest__OutputTextToLog_x                              0x4E6000
#define CEverQuest__DropHeldItemOnGround_x                         0x5D0890
#define CEverQuest__dsp_chat_x                                     0x4E6390
#define CEverQuest__trimName_x                                     0x5F4E40
#define CEverQuest__Emote_x                                        0x5E9F30
#define CEverQuest__EnterZone_x                                    0x5E3F10
#define CEverQuest__GetBodyTypeDesc_x                              0x5EE6E0
#define CEverQuest__GetClassDesc_x                                 0x5EED20
#define CEverQuest__GetClassThreeLetterCode_x                      0x5EF320
#define CEverQuest__GetDeityDesc_x                                 0x5F74B0
#define CEverQuest__GetLangDesc_x                                  0x5EF4E0
#define CEverQuest__GetRaceDesc_x                                  0x5EED00
#define CEverQuest__InterpretCmd_x                                 0x5F7A80
#define CEverQuest__LeftClickedOnPlayer_x                          0x5D4A80
#define CEverQuest__LMouseUp_x                                     0x5D2E00
#define CEverQuest__RightClickedOnPlayer_x                         0x5D5360
#define CEverQuest__RMouseUp_x                                     0x5D3D90
#define CEverQuest__SetGameState_x                                 0x5D0620
#define CEverQuest__UPCNotificationFlush_x                         0x5F4D40
#define CEverQuest__IssuePetCommand_x                              0x5F08E0
#define CEverQuest__ReportSuccessfulHit_x                          0x5EB330

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x717EA0
#define CGaugeWnd__CalcLinesFillRect_x                             0x717F00
#define CGaugeWnd__Draw_x                                          0x7175B0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ACBE0
#define CGuild__GetGuildName_x                                     0x4ABCC0
#define CGuild__GetGuildIndex_x                                    0x4AC050

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x7332B0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x60A940

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x740140
#define CInvSlotMgr__MoveItem_x                                    0x73EEA0
#define CInvSlotMgr__SelectSlot_x                                  0x740210

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x73D750
#define CInvSlot__SliderComplete_x                                 0x73B4B0
#define CInvSlot__GetItemBase_x                                    0x73AE50
#define CInvSlot__UpdateItem_x                                     0x73AFC0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x741C70
#define CInvSlotWnd__CInvSlotWnd_x                                 0x740E20
#define CInvSlotWnd__HandleLButtonUp_x                             0x7417F0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7FE040
#define CItemDisplayWnd__UpdateStrings_x                           0x750050
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x749E80
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x74A380
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x750650
#define CItemDisplayWnd__AboutToShow_x                             0x74FC90
#define CItemDisplayWnd__WndNotification_x                         0x751B50
#define CItemDisplayWnd__RequestConvertItem_x                      0x751610
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x74ECF0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x74FAB0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x835930

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x755C30

// CLabel 
#define CLabel__Draw_x                                             0x75B6B0

// CListWnd
#define CListWnd__CListWnd_x                                       0x909190
#define CListWnd__dCListWnd_x                                      0x9094A0
#define CListWnd__AddColumn_x                                      0x90D7B0
#define CListWnd__AddColumn1_x                                     0x90D800
#define CListWnd__AddLine_x                                        0x90DB90
#define CListWnd__AddString_x                                      0x90D990
#define CListWnd__CalculateFirstVisibleLine_x                      0x90D570
#define CListWnd__CalculateVSBRange_x                              0x90D360
#define CListWnd__ClearSel_x                                       0x90E370
#define CListWnd__ClearAllSel_x                                    0x90E3D0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x90EDF0
#define CListWnd__Compare_x                                        0x90CCB0
#define CListWnd__Draw_x                                           0x9095A0
#define CListWnd__DrawColumnSeparators_x                           0x90BD80
#define CListWnd__DrawHeader_x                                     0x90C1F0
#define CListWnd__DrawItem_x                                       0x90C5F0
#define CListWnd__DrawLine_x                                       0x90BEF0
#define CListWnd__DrawSeparator_x                                  0x90BE20
#define CListWnd__EnableLine_x                                     0x90B650
#define CListWnd__EnsureVisible_x                                  0x90ED10
#define CListWnd__ExtendSel_x                                      0x90E2A0
#define CListWnd__GetColumnTooltip_x                               0x90B190
#define CListWnd__GetColumnMinWidth_x                              0x90B200
#define CListWnd__GetColumnWidth_x                                 0x90B100
#define CListWnd__GetCurSel_x                                      0x90AA90
#define CListWnd__GetItemAtPoint_x                                 0x90B8D0
#define CListWnd__GetItemAtPoint1_x                                0x90B940
#define CListWnd__GetItemData_x                                    0x90AB10
#define CListWnd__GetItemHeight_x                                  0x90AED0
#define CListWnd__GetItemIcon_x                                    0x90ACA0
#define CListWnd__GetItemRect_x                                    0x90B740
#define CListWnd__GetItemText_x                                    0x90AB50
#define CListWnd__GetSelList_x                                     0x90E420
#define CListWnd__GetSeparatorRect_x                               0x90BB80
#define CListWnd__InsertLine_x                                     0x90DF80
#define CListWnd__RemoveLine_x                                     0x90E0D0
#define CListWnd__SetColors_x                                      0x90D340
#define CListWnd__SetColumnJustification_x                         0x90D070
#define CListWnd__SetColumnWidth_x                                 0x90CF90
#define CListWnd__SetCurSel_x                                      0x90E1E0
#define CListWnd__SetItemColor_x                                   0x90E9C0
#define CListWnd__SetItemData_x                                    0x90E980
#define CListWnd__SetItemText_x                                    0x90E590
#define CListWnd__ShiftColumnSeparator_x                           0x90D130
#define CListWnd__Sort_x                                           0x90CE30
#define CListWnd__ToggleSel_x                                      0x90E210
#define CListWnd__SetColumnsSizable_x                              0x90D1D0
#define CListWnd__SetItemWnd_x                                     0x90E840
#define CListWnd__GetItemWnd_x                                     0x90ACF0
#define CListWnd__SetItemIcon_x                                    0x90E610
#define CListWnd__CalculateCustomWindowPositions_x                 0x90D670
#define CListWnd__SetVScrollPos_x                                  0x90CF70

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x770B40
#define CMapViewWnd__GetWorldCoordinates_x                         0x76F250
#define CMapViewWnd__HandleLButtonDown_x                           0x76C2B0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x793C60
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x794540
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x794A70
#define CMerchantWnd__SelectRecoverySlot_x                         0x7979E0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7927C0
#define CMerchantWnd__SelectBuySellSlot_x                          0x79D5B0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x793880

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89D730
#define CPacketScrambler__hton_x                                   0x89D720

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x927F40
#define CSidlManager__FindScreenPieceTemplate_x                    0x928350
#define CSidlManager__FindScreenPieceTemplate1_x                   0x928140
#define CSidlManager__CreateLabel_x                                0x7F5460
#define CSidlManager__CreateXWndFromTemplate_x                     0x92B2F0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x92B4C0
#define CSidlManager__CreateXWnd_x                                 0x7F5390
#define CSidlManager__CreateHotButtonWnd_x                         0x7F5950

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x924AC0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9249C0
#define CSidlScreenWnd__ConvertToRes_x                             0x949DF0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x924450
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x924140
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x924210
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x9242E0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x924F60
#define CSidlScreenWnd__EnableIniStorage_x                         0x925430
#define CSidlScreenWnd__GetSidlPiece_x                             0x925150
#define CSidlScreenWnd__Init1_x                                    0x923D40
#define CSidlScreenWnd__LoadIniInfo_x                              0x925480
#define CSidlScreenWnd__LoadIniListWnd_x                           0x925FB0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x923150
#define CSidlScreenWnd__StoreIniInfo_x                             0x925B30
#define CSidlScreenWnd__StoreIniVis_x                              0x925E90
#define CSidlScreenWnd__WndNotification_x                          0x924E70
#define CSidlScreenWnd__GetChildItem_x                             0x9253B0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x914BC0
#define CSidlScreenWnd__m_layoutCopy_x                             0x16C97C8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x66EF90
#define CSkillMgr__GetSkillCap_x                                   0x66F170
#define CSkillMgr__GetNameToken_x                                  0x66E720
#define CSkillMgr__IsActivatedSkill_x                              0x66E860
#define CSkillMgr__IsCombatSkill_x                                 0x66E7A0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x934D00
#define CSliderWnd__SetValue_x                                     0x934B70
#define CSliderWnd__SetNumTicks_x                                  0x934BD0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7FB590

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x93D550
#define CStmlWnd__CalculateHSBRange_x                              0x93E640
#define CStmlWnd__CalculateVSBRange_x                              0x93E5B0
#define CStmlWnd__CanBreakAtCharacter_x                            0x942980
#define CStmlWnd__FastForwardToEndOfTag_x                          0x943610
#define CStmlWnd__ForceParseNow_x                                  0x93DAF0
#define CStmlWnd__GetNextTagPiece_x                                0x9428E0
#define CStmlWnd__GetSTMLText_x                                    0x4F7EF0
#define CStmlWnd__GetVisibleText_x                                 0x93DB10
#define CStmlWnd__InitializeWindowVariables_x                      0x943460
#define CStmlWnd__MakeStmlColorTag_x                               0x93CC30
#define CStmlWnd__MakeWndNotificationTag_x                         0x93CCA0
#define CStmlWnd__SetSTMLText_x                                    0x93BCE0
#define CStmlWnd__StripFirstSTMLLines_x                            0x944710
#define CStmlWnd__UpdateHistoryString_x                            0x943820

// CTabWnd 
#define CTabWnd__Draw_x                                            0x93ADD0
#define CTabWnd__DrawCurrentPage_x                                 0x93B4B0
#define CTabWnd__DrawTab_x                                         0x93B1D0
#define CTabWnd__GetCurrentPage_x                                  0x93A5D0
#define CTabWnd__GetPageInnerRect_x                                0x93A810
#define CTabWnd__GetTabInnerRect_x                                 0x93A750
#define CTabWnd__GetTabRect_x                                      0x93A600
#define CTabWnd__InsertPage_x                                      0x93AA20
#define CTabWnd__SetPage_x                                         0x93A890
#define CTabWnd__SetPageRect_x                                     0x93AD10
#define CTabWnd__UpdatePage_x                                      0x93B090
#define CTabWnd__GetPageFromTabIndex_x                             0x93B110
#define CTabWnd__GetCurrentTabIndex_x                              0x93A5C0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x756000
#define CPageWnd__SetTabText_x                                     0x93A110

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A67E0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x911A40
#define CTextureFont__GetTextExtent_x                              0x911C00

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6A2900
#define CHtmlComponentWnd__ValidateUri_x                           0x734CA0
#define CHtmlWnd__SetClientCallbacks_x                             0x60F9B0
#define CHtmlWnd__AddObserver_x                                    0x60F9D0
#define CHtmlWnd__RemoveObserver_x                                 0x60FA30
#define Window__getProgress_x                                      0x84DEE0
#define Window__getStatus_x                                        0x84DF00
#define Window__getURI_x                                           0x84DF10

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x94F800

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8FECA0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4ADE80
#define CXStr__CXStr1_x                                            0x83E950
#define CXStr__CXStr3_x                                            0x8EB430
#define CXStr__dCXStr_x                                            0x473170
#define CXStr__operator_equal_x                                    0x8EB660
#define CXStr__operator_equal1_x                                   0x8EB6A0
#define CXStr__operator_plus_equal1_x                              0x8EC130
#define CXStr__SetString_x                                         0x8EE020
#define CXStr__operator_char_p_x                                   0x8EBB70

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x932F80
#define CXWnd__BringToTop_x                                        0x9182E0
#define CXWnd__Center_x                                            0x917E60
#define CXWnd__ClrFocus_x                                          0x917C90
#define CXWnd__Destroy_x                                           0x917D40
#define CXWnd__DoAllDrawing_x                                      0x914350
#define CXWnd__DrawChildren_x                                      0x914320
#define CXWnd__DrawColoredRect_x                                   0x9147B0
#define CXWnd__DrawTooltip_x                                       0x912E70
#define CXWnd__DrawTooltipAtPoint_x                                0x912F30
#define CXWnd__GetBorderFrame_x                                    0x914610
#define CXWnd__GetChildWndAt_x                                     0x918380
#define CXWnd__GetClientClipRect_x                                 0x916610
#define CXWnd__GetScreenClipRect_x                                 0x9166C0
#define CXWnd__GetScreenRect_x                                     0x916870
#define CXWnd__GetTooltipRect_x                                    0x914800
#define CXWnd__GetWindowTextA_x                                    0x497F50
#define CXWnd__IsActive_x                                          0x914F30
#define CXWnd__IsDescendantOf_x                                    0x917230
#define CXWnd__IsReallyVisible_x                                   0x917260
#define CXWnd__IsType_x                                            0x9189E0
#define CXWnd__Move_x                                              0x9172D0
#define CXWnd__Move1_x                                             0x917380
#define CXWnd__ProcessTransition_x                                 0x917E10
#define CXWnd__Refade_x                                            0x917630
#define CXWnd__Resize_x                                            0x9178C0
#define CXWnd__Right_x                                             0x9180A0
#define CXWnd__SetFocus_x                                          0x917C50
#define CXWnd__SetFont_x                                           0x917CC0
#define CXWnd__SetKeyTooltip_x                                     0x918810
#define CXWnd__SetMouseOver_x                                      0x915770
#define CXWnd__StartFade_x                                         0x917100
#define CXWnd__GetChildItem_x                                      0x9184F0
#define CXWnd__SetParent_x                                         0x916FD0
#define CXWnd__Minimize_x                                          0x917930

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x94AE80

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x91B260
#define CXWndManager__DrawWindows_x                                0x91B280
#define CXWndManager__GetKeyboardFlags_x                           0x91D9E0
#define CXWndManager__HandleKeyboardMsg_x                          0x91D5E0
#define CXWndManager__RemoveWnd_x                                  0x91DC30
#define CXWndManager__RemovePendingDeletionWnd_x                   0x91E190

// CDBStr
#define CDBStr__GetString_x                                        0x52FDF0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B9010
#define EQ_Character__Cur_HP_x                                     0x4CF390
#define EQ_Character__Cur_Mana_x                                   0x4D6B30
#define EQ_Character__GetCastingTimeModifier_x                     0x4BBF30
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AFA70
#define EQ_Character__GetFocusRangeModifier_x                      0x4AFBC0
#define EQ_Character__GetHPRegen_x                                 0x4DCA40
#define EQ_Character__GetEnduranceRegen_x                          0x4DD050
#define EQ_Character__GetManaRegen_x                               0x4DD490
#define EQ_Character__Max_Endurance_x                              0x635560
#define EQ_Character__Max_HP_x                                     0x4CF1C0
#define EQ_Character__Max_Mana_x                                   0x635360
#define EQ_Character__doCombatAbility_x                            0x637A20
#define EQ_Character__UseSkill_x                                   0x4DF280
#define EQ_Character__GetConLevel_x                                0x62EA70
#define EQ_Character__IsExpansionFlag_x                            0x593160
#define EQ_Character__TotalEffect_x                                0x4C2590
#define EQ_Character__GetPCSpellAffect_x                           0x4BCB20
#define EQ_Character__SpellDuration_x                              0x4BC650
#define EQ_Character__GetAdjustedSkill_x                           0x4D2170
#define EQ_Character__GetBaseSkill_x                               0x4D3110
#define EQ_Character__CanUseItem_x                                 0x4D6E40

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BCA10

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x64BBB0

//PcClient
#define PcClient__PcClient_x                                       0x62C1A0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6C50
#define CCharacterListWnd__EnterWorld_x                            0x4B6690
#define CCharacterListWnd__Quit_x                                  0x4B63A0
#define CCharacterListWnd__UpdateList_x                            0x4B6820

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x610BD0
#define EQ_Item__CreateItemTagString_x                             0x897020
#define EQ_Item__IsStackable_x                                     0x89BA70
#define EQ_Item__GetImageNum_x                                     0x898A40
#define EQ_Item__CreateItemClient_x                                0x60FD90
#define EQ_Item__GetItemValue_x                                    0x899CB0
#define EQ_Item__ValueSellMerchant_x                               0x89D2C0
#define EQ_Item__IsKeyRingItem_x                                   0x89B3C0
#define EQ_Item__CanGoInBag_x                                      0x610CF0
#define EQ_Item__IsEmpty_x                                         0x89AEF0
#define EQ_Item__GetMaxItemCount_x                                 0x89A080
#define EQ_Item__GetHeldItem_x                                     0x898910
#define EQ_Item__GetAugmentFitBySlot_x                             0x896950

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x54E350
#define EQ_LoadingS__Array_x                                       0xBF2600

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x635EC0
#define EQ_PC__GetAlternateAbilityId_x                             0x8A64C0
#define EQ_PC__GetCombatAbility_x                                  0x8A6B30
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A6BA0
#define EQ_PC__GetItemRecastTimer_x                                0x637FA0
#define EQ_PC__HasLoreItem_x                                       0x62F1E0
#define EQ_PC__AlertInventoryChanged_x                             0x62E3A0
#define EQ_PC__GetPcZoneClient_x                                   0x65A3C0
#define EQ_PC__RemoveMyAffect_x                                    0x63B1C0
#define EQ_PC__GetKeyRingItems_x                                   0x8A7440
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A71C0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A7730

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5996B0
#define EQItemList__add_object_x                                   0x5C60C0
#define EQItemList__add_item_x                                     0x599C00
#define EQItemList__delete_item_x                                  0x599C50
#define EQItemList__FreeItemList_x                                 0x599B50

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x52D400

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x64D430
#define EQPlayer__dEQPlayer_x                                      0x640740
#define EQPlayer__DoAttack_x                                       0x6550A0
#define EQPlayer__EQPlayer_x                                       0x640DF0
#define EQPlayer__SetNameSpriteState_x                             0x6450B0
#define EQPlayer__SetNameSpriteTint_x                              0x645F80
#define PlayerBase__HasProperty_j_x                                0x97D540
#define EQPlayer__IsTargetable_x                                   0x97D9E0
#define EQPlayer__CanSee_x                                         0x97D840
#define EQPlayer__CanSee1_x                                        0x97D910
#define PlayerBase__GetVisibilityLineSegment_x                     0x97D600

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x657E70
#define PlayerZoneClient__GetLevel_x                               0x65A400
#define PlayerZoneClient__IsValidTeleport_x                        0x5C7230
#define PlayerZoneClient__LegalPlayerRace_x                        0x547670

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x650260
#define EQPlayerManager__GetSpawnByName_x                          0x650280
#define EQPlayerManager__GetPlayerFromPartialName_x                0x650310

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x614300
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x614380
#define KeypressHandler__AttachKeyToEqCommand_x                    0x6143C0
#define KeypressHandler__ClearCommandStateArray_x                  0x6157D0
#define KeypressHandler__HandleKeyDown_x                           0x6157F0
#define KeypressHandler__HandleKeyUp_x                             0x615890
#define KeypressHandler__SaveKeymapping_x                          0x615CC0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x76C9D0
#define MapViewMap__SaveEx_x                                       0x76FD70
#define MapViewMap__SetZoom_x                                      0x774440

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BA900

// StringTable 
#define StringTable__getString_x                                   0x8B5600

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x63AE30
#define PcZoneClient__RemovePetEffect_x                            0x63B460
#define PcZoneClient__HasAlternateAbility_x                        0x6351A0
#define PcZoneClient__GetCurrentMod_x                              0x4E2370
#define PcZoneClient__GetModCap_x                                  0x4E2270
#define PcZoneClient__CanEquipItem_x                               0x635850
#define PcZoneClient__GetItemByID_x                                0x638410
#define PcZoneClient__GetItemByItemClass_x                         0x638560
#define PcZoneClient__RemoveBuffEffect_x                           0x63B480
#define PcZoneClient__BandolierSwap_x                              0x636480
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x637F40

//Doors
#define EQSwitch__UseSwitch_x                                      0x5CBD80

//IconCache
#define IconCache__GetIcon_x                                       0x70D5F0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x705030
#define CContainerMgr__CloseContainer_x                            0x705300
#define CContainerMgr__OpenExperimentContainer_x                   0x705D80

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7C7BC0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x608D60

//CLootWnd
#define CLootWnd__LootAll_x                                        0x762ED0
#define CLootWnd__RequestLootSlot_x                                0x762290

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x566930
#define EQ_Spell__SpellAffects_x                                   0x566DA0
#define EQ_Spell__SpellAffectBase_x                                0x566B60
#define EQ_Spell__IsStackable_x                                    0x4C6DC0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C6C40
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B3FE0
#define EQ_Spell__IsSPAStacking_x                                  0x567BD0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x5670F0
#define EQ_Spell__IsNoRemove_x                                     0x4C6DA0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x567BE0
#define __IsResEffectSpell_x                                       0x4C6100

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AA8F0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C5040

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x80D360
#define CTargetWnd__WndNotification_x                              0x80CBF0
#define CTargetWnd__RefreshTargetBuffs_x                           0x80CEC0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x80BD40

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x811A30

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x52AD60
#define CTaskManager__HandleMessage_x                              0x5294C0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x561EC0
#define EqSoundManager__PlayScriptMp3_x                            0x562020
#define EqSoundManager__SoundAssistPlay_x                          0x672F00
#define EqSoundManager__WaveInstancePlay_x                         0x672470

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x51ED40

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x939610

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x555D00
#define CAltAbilityData__GetMercMaxRank_x                          0x555CA0
#define CAltAbilityData__GetMaxRank_x                              0x54B410

//CTargetRing
#define CTargetRing__Cast_x                                        0x606E50

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C6C20
#define CharacterBase__CreateItemGlobalIndex_x                     0x504B20
#define CharacterBase__CreateItemIndex_x                           0x60EF70
#define CharacterBase__GetItemPossession_x                         0x4F0A80
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CD690
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CD6F0
#define CharacterBase__GetEffectId_x                               0x4C6BD0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6EC3E0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6ECC10

//messages
#define msg_spell_worn_off_x                                       0x58B2D0
#define msg_new_text_x                                             0x580130
#define __msgTokenTextParam_x                                      0x58D7F0
#define msgTokenText_x                                             0x58DA40

//SpellManager
#define SpellManager__vftable_x                                    0xAB8C68
#define SpellManager__SpellManager_x                               0x676230
#define Spellmanager__LoadTextSpells_x                             0x676B00
#define SpellManager__GetSpellByGroupAndRank_x                     0x676400

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x981500

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x505210
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x591600
#define ItemGlobalIndex__IsEquippedLocation_x                      0x6278D0
#define ItemGlobalIndex__IsValidIndex_x                            0x505270

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C5980
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C5C00

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x75B9F0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x709750
#define CCursorAttachment__AttachToCursor1_x                       0x709790
#define CCursorAttachment__Deactivate_x                            0x70A770

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x92C2F0
#define CSidlManagerBase__CreatePageWnd_x                          0x92BB00
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x927D60
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x927CF0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x949340
#define CEQSuiteTextureLoader__GetTexture_x                        0x949000

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x5020F0
#define CFindItemWnd__WndNotification_x                            0x502BD0
#define CFindItemWnd__Update_x                                     0x503710
#define CFindItemWnd__PickupSelectedItem_x                         0x501960

//IString
#define IString__Append_x                                          0x4F2040

//Camera
#define CDisplay__cameraType_x                                     0xDCC298
#define EverQuest__Cameras_x                                       0xE8F670

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x50AB10
#define LootFiltersManager__GetItemFilterData_x                    0x50A400
#define LootFiltersManager__RemoveItemLootFilter_x                 0x50A430
#define LootFiltersManager__SetItemLootFilter_x                    0x50A650

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B5BE0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9871A0
#define CResolutionHandler__GetWindowedStyle_x                     0x66D860

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x701DF0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D8260
#define CDistillerInfo__Instance_x                                 0x8D8200

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x722040
#define CGroupWnd__UpdateDisplay_x                                 0x7213A0

//ItemBase
#define ItemBase__IsLore_x                                         0x89B420
#define ItemBase__IsLoreEquipped_x                                 0x89B490

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5C6020
#define EQPlacedItemManager__GetItemByGuid_x                       0x5C6160
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5C61C0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x662F00
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x6668A0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x4F8590

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4E7710
#define FactionManagerClient__HandleFactionMessage_x               0x4E7D80
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4E8370
#define FactionManagerClient__GetMaxFaction_x                      0x4E83C0
#define FactionManagerClient__GetMinFaction_x                      0x4E8340

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4F0A50

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x910AA0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x497270

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4F0C90

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x5551E0

//CTargetManager
#define CTargetManager__Get_x                                      0x679AB0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x662F00

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A65A0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x599AF0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF2CD00

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
