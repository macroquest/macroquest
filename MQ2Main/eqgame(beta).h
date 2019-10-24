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
#define __ExpectedVersionDate                                     "Oct 24 2019"
#define __ExpectedVersionTime                                     "04:21:42"
#define __ActualVersionDate_x                                      0xAFFC48
#define __ActualVersionTime_x                                      0xAFFC3C
#define __ActualVersionBuild_x                                     0xAEB91C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x6276A0
#define __MemChecker1_x                                            0x8F99E0
#define __MemChecker2_x                                            0x6B6030
#define __MemChecker3_x                                            0x6B5F80
#define __MemChecker4_x                                            0x851F70
#define __EncryptPad0_x                                            0xC353F0
#define __EncryptPad1_x                                            0xC935B0
#define __EncryptPad2_x                                            0xC45C88
#define __EncryptPad3_x                                            0xC45888
#define __EncryptPad4_x                                            0xC83C08
#define __EncryptPad5_x                                            0xF5CCD0
#define __AC1_x                                                    0x80EA46
#define __AC2_x                                                    0x5E15BF
#define __AC3_x                                                    0x5E8CBF
#define __AC4_x                                                    0x5ECC80
#define __AC5_x                                                    0x5F2F8F
#define __AC6_x                                                    0x5F75A6
#define __AC7_x                                                    0x5E1030
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1B276C

// Direct Input
#define DI8__Main_x                                                0xF5F1AC
#define DI8__Keyboard_x                                            0xF5F1B0
#define DI8__Mouse_x                                               0xF5F1C8
#define DI8__Mouse_Copy_x                                          0xEB839C
#define DI8__Mouse_Check_x                                         0xF5CCF8
#define __AutoSkillArray_x                                         0xEB92B4
#define __Attack_x                                                 0xF570DB
#define __Autofire_x                                               0xF570DC
#define __BindList_x                                               0xC23E20
#define g_eqCommandStates_x                                        0xC24BA0
#define __Clicks_x                                                 0xEB8454
#define __CommandList_x                                            0xC25760
#define __CurrentMapLabel_x                                        0xF6FB5C
#define __CurrentSocial_x                                          0xC0D7CC
#define __DoAbilityList_x                                          0xEEEBFC
#define __do_loot_x                                                0x5AD990
#define __DrawHandler_x                                            0x15EEED0
#define __GroupCount_x                                             0xEAA792
#define __Guilds_x                                                 0xEAEBA8
#define __gWorld_x                                                 0xEAA644
#define __HWnd_x                                                   0xF5F1CC
#define __heqmain_x                                                0xF5F1A0
#define __InChatMode_x                                             0xEB8384
#define __LastTell_x                                               0xEBA2F8
#define __LMouseHeldTime_x                                         0xEB84C0
#define __Mouse_x                                                  0xF5F18C
#define __MouseLook_x                                              0xEB841A
#define __MouseEventTime_x                                         0xF57BBC
#define __gpbCommandEvent_x                                        0xEAA9F4
#define __NetStatusToggle_x                                        0xEB841D
#define __PCNames_x                                                0xEB98A4
#define __RangeAttackReady_x                                       0xEB9598
#define __RMouseHeldTime_x                                         0xEB84BC
#define __RunWalkState_x                                           0xEB8388
#define __ScreenMode_x                                             0xDF5F6C
#define __ScreenX_x                                                0xEB833C
#define __ScreenY_x                                                0xEB8338
#define __ScreenXMax_x                                             0xEB8340
#define __ScreenYMax_x                                             0xEB8344
#define __ServerHost_x                                             0xEAAC2B
#define __ServerName_x                                             0xEEEBBC
#define __ShiftKeyDown_x                                           0xEB8A14
#define __ShowNames_x                                              0xEB9754
#define __Socials_x                                                0xEEECBC
#define __SubscriptionType_x                                       0xFB4060
#define __TargetAggroHolder_x                                      0xF72510
#define __ZoneType_x                                               0xEB8818
#define __GroupAggro_x                                             0xF72550
#define __LoginName_x                                              0xF5F904
#define __Inviter_x                                                0xF57058
#define __AttackOnAssist_x                                         0xEB9710
#define __UseTellWindows_x                                         0xEB9A40
#define __gfMaxZoomCameraDistance_x                                0xAF5590
#define __gfMaxCameraDistance_x                                    0xB21B14
#define __pulAutoRun_x                                             0xEB8438
#define __pulForward_x                                             0xEB9A78
#define __pulBackward_x                                            0xEB9A7C
#define __pulTurnRight_x                                           0xEB9A80
#define __pulTurnLeft_x                                            0xEB9A84
#define __pulStrafeLeft_x                                          0xEB9A88
#define __pulStrafeRight_x                                         0xEB9A8C

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEAAF40
#define instEQZoneInfo_x                                           0xEB8610
#define pinstActiveBanker_x                                        0xEAAA0C
#define pinstActiveCorpse_x                                        0xEAAA04
#define pinstActiveGMaster_x                                       0xEAAA08
#define pinstActiveMerchant_x                                      0xEAAA00
#define pinstAltAdvManager_x                                       0xDF7170
#define pinstBandageTarget_x                                       0xEAAA1C
#define pinstCamActor_x                                            0xDF5F60
#define pinstCDBStr_x                                              0xDF5E8C
#define pinstCDisplay_x                                            0xEAA648
#define pinstCEverQuest_x                                          0xF5F1C4
#define pinstEverQuestInfo_x                                       0xEB8330
#define pinstCharData_x                                            0xEAA774
#define pinstCharSpawn_x                                           0xEAAAD4
#define pinstControlledMissile_x                                   0xEAAD34
#define pinstControlledPlayer_x                                    0xEAAAD4
#define pinstCResolutionHandler_x                                  0x15EF100
#define pinstCSidlManager_x                                        0x15EE098
#define pinstCXWndManager_x                                        0x15EE094
#define instDynamicZone_x                                          0xEAEA80
#define pinstDZMember_x                                            0xEAEB90
#define pinstDZTimerInfo_x                                         0xEAEB94
#define pinstEqLogin_x                                             0xF5F250
#define instEQMisc_x                                               0xDF5DD0
#define pinstEQSoundManager_x                                      0xDF8140
#define pinstEQSpellStrings_x                                      0xCB8868
#define instExpeditionLeader_x                                     0xEAEACA
#define instExpeditionName_x                                       0xEAEB0A
#define pinstGroup_x                                               0xEAA78E
#define pinstImeManager_x                                          0x15EE090
#define pinstLocalPlayer_x                                         0xEAA9FC
#define pinstMercenaryData_x                                       0xF596B4
#define pinstMercenaryStats_x                                      0xF7265C
#define pinstModelPlayer_x                                         0xEAAA14
#define pinstPCData_x                                              0xEAA774
#define pinstSkillMgr_x                                            0xF5B818
#define pinstSpawnManager_x                                        0xF5A2C0
#define pinstSpellManager_x                                        0xF5BA38
#define pinstSpellSets_x                                           0xF4FD04
#define pinstStringTable_x                                         0xEAA778
#define pinstSwitchManager_x                                       0xEA84E0
#define pinstTarget_x                                              0xEAAAD0
#define pinstTargetObject_x                                        0xEAAADC
#define pinstTargetSwitch_x                                        0xEA863C
#define pinstTaskMember_x                                          0xDF5C60
#define pinstTrackTarget_x                                         0xEAAAD8
#define pinstTradeTarget_x                                         0xEAAA10
#define instTributeActive_x                                        0xDF5DF1
#define pinstViewActor_x                                           0xDF5F5C
#define pinstWorldData_x                                           0xEA8630
#define pinstZoneAddr_x                                            0xEB88B0
#define pinstPlayerPath_x                                          0xF5A358
#define pinstTargetIndicator_x                                     0xF5BCA0
#define EQObject_Top_x                                             0xEAA9F8
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDF6238
#define pinstCAchievementsWnd_x                                    0xDF5FBC
#define pinstCActionsWnd_x                                         0xDF5FE8
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDF6794
#define pinstCAdvancedLootWnd_x                                    0xDF6764
#define pinstCAdventureLeaderboardWnd_x                            0xF69330
#define pinstCAdventureRequestWnd_x                                0xF693E0
#define pinstCAdventureStatsWnd_x                                  0xF69490
#define pinstCAggroMeterWnd_x                                      0xDF5F50
#define pinstCAlarmWnd_x                                           0xDF6728
#define pinstCAlertHistoryWnd_x                                    0xDF675C
#define pinstCAlertStackWnd_x                                      0xDF6260
#define pinstCAlertWnd_x                                           0xDF6274
#define pinstCAltStorageWnd_x                                      0xF697F0
#define pinstCAudioTriggersWindow_x                                0xCAAB98
#define pinstCAuraWnd_x                                            0xDF67C0
#define pinstCAvaZoneWnd_x                                         0xDF5FB4
#define pinstCBandolierWnd_x                                       0xDF5F4C
#define pinstCBankWnd_x                                            0xDF67BC
#define pinstCBarterMerchantWnd_x                                  0xF6AA30
#define pinstCBarterSearchWnd_x                                    0xF6AAE0
#define pinstCBarterWnd_x                                          0xF6AB90
#define pinstCBazaarConfirmationWnd_x                              0xDF5FF8
#define pinstCBazaarSearchWnd_x                                    0xDF5FAC
#define pinstCBazaarWnd_x                                          0xDF6714
#define pinstCBlockedBuffWnd_x                                     0xDF5F28
#define pinstCBlockedPetBuffWnd_x                                  0xDF5F48
#define pinstCBodyTintWnd_x                                        0xDF6000
#define pinstCBookWnd_x                                            0xDF5F8C
#define pinstCBreathWnd_x                                          0xDF626C
#define pinstCBuffWindowNORMAL_x                                   0xDF67AC
#define pinstCBuffWindowSHORT_x                                    0xDF67B0
#define pinstCBugReportWnd_x                                       0xDF67B8
#define pinstCButtonWnd_x                                          0x15EE300
#define pinstCCastingWnd_x                                         0xDF5F7C
#define pinstCCastSpellWnd_x                                       0xDF6264
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDF6718
#define pinstCChatWindowManager_x                                  0xF6B650
#define pinstCClaimWnd_x                                           0xF6B7A8
#define pinstCColorPickerWnd_x                                     0xDF5FF0
#define pinstCCombatAbilityWnd_x                                   0xDF6724
#define pinstCCombatSkillsSelectWnd_x                              0xDF6744
#define pinstCCompassWnd_x                                         0xDF5FEC
#define pinstCConfirmationDialog_x                                 0xF706A8
#define pinstCContainerMgr_x                                       0xDF670C
#define pinstCContextMenuManager_x                                 0x15EE050
#define pinstCCursorAttachment_x                                   0xDF5F58
#define pinstCDynamicZoneWnd_x                                     0xF6BD70
#define pinstCEditLabelWnd_x                                       0xDF67A0
#define pinstCEQMainWnd_x                                          0xF6BFB8
#define pinstCEventCalendarWnd_x                                   0xDF67A8
#define pinstCExtendedTargetWnd_x                                  0xDF5F3C
#define pinstCFacePick_x                                           0xDF6754
#define pinstCFactionWnd_x                                         0xDF6704
#define pinstCFellowshipWnd_x                                      0xF6C1B8
#define pinstCFileSelectionWnd_x                                   0xDF5F78
#define pinstCFindItemWnd_x                                        0xDF6280
#define pinstCFindLocationWnd_x                                    0xF6C310
#define pinstCFriendsWnd_x                                         0xDF6760
#define pinstCGemsGameWnd_x                                        0xDF6700
#define pinstCGiveWnd_x                                            0xDF672C
#define pinstCGroupSearchFiltersWnd_x                              0xDF5F84
#define pinstCGroupSearchWnd_x                                     0xF6C708
#define pinstCGroupWnd_x                                           0xF6C7B8
#define pinstCGuildBankWnd_x                                       0xEB96F4
#define pinstCGuildCreationWnd_x                                   0xF6C918
#define pinstCGuildMgmtWnd_x                                       0xF6C9C8
#define pinstCharacterCreation_x                                   0xDF674C
#define pinstCHelpWnd_x                                            0xDF678C
#define pinstCHeritageSelectionWnd_x                               0xDF6768
#define pinstCHotButtonWnd_x                                       0xF6EB20
#define pinstCHotButtonWnd1_x                                      0xF6EB20
#define pinstCHotButtonWnd2_x                                      0xF6EB24
#define pinstCHotButtonWnd3_x                                      0xF6EB28
#define pinstCHotButtonWnd4_x                                      0xF6EB2C
#define pinstCIconSelectionWnd_x                                   0xDF5F54
#define pinstCInspectWnd_x                                         0xDF6788
#define pinstCInventoryWnd_x                                       0xDF676C
#define pinstCInvSlotMgr_x                                         0xDF6228
#define pinstCItemDisplayManager_x                                 0xF6F0B0
#define pinstCItemExpTransferWnd_x                                 0xF6F1E4
#define pinstCItemOverflowWnd_x                                    0xDF5FB8
#define pinstCJournalCatWnd_x                                      0xDF5F94
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDF5F40
#define pinstCKeyRingWnd_x                                         0xDF679C
#define pinstCLargeDialogWnd_x                                     0xF71328
#define pinstCLayoutCopyWnd_x                                      0xF6F530
#define pinstCLFGuildWnd_x                                         0xF6F5E0
#define pinstCLoadskinWnd_x                                        0xDF6710
#define pinstCLootFiltersCopyWnd_x                                 0xCC7168
#define pinstCLootFiltersWnd_x                                     0xDF6268
#define pinstCLootSettingsWnd_x                                    0xDF627C
#define pinstCLootWnd_x                                            0xDF5F98
#define pinstCMailAddressBookWnd_x                                 0xDF624C
#define pinstCMailCompositionWnd_x                                 0xDF6014
#define pinstCMailIgnoreListWnd_x                                  0xDF6250
#define pinstCMailWnd_x                                            0xDF5FE4
#define pinstCManageLootWnd_x                                      0xDF7620
#define pinstCMapToolbarWnd_x                                      0xDF6790
#define pinstCMapViewWnd_x                                         0xDF6778
#define pinstCMarketplaceWnd_x                                     0xDF6270
#define pinstCMerchantWnd_x                                        0xDF5F9C
#define pinstCMIZoneSelectWnd_x                                    0xF6FE18
#define pinstCMusicPlayerWnd_x                                     0xDF5FA4
#define pinstCNameChangeMercWnd_x                                  0xDF5FE0
#define pinstCNameChangePetWnd_x                                   0xDF5FC0
#define pinstCNameChangeWnd_x                                      0xDF600C
#define pinstCNoteWnd_x                                            0xDF677C
#define pinstCObjectPreviewWnd_x                                   0xDF6278
#define pinstCOptionsWnd_x                                         0xDF6780
#define pinstCPetInfoWnd_x                                         0xDF5FC4
#define pinstCPetitionQWnd_x                                       0xDF5FA8
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDF6004
#define pinstCPlayerWnd_x                                          0xDF5FC8
#define pinstCPopupWndManager_x                                    0xF706A8
#define pinstCProgressionSelectionWnd_x                            0xF70758
#define pinstCPurchaseGroupWnd_x                                   0xDF6734
#define pinstCPurchaseWnd_x                                        0xDF6708
#define pinstCPvPLeaderboardWnd_x                                  0xF70808
#define pinstCPvPStatsWnd_x                                        0xF708B8
#define pinstCQuantityWnd_x                                        0xDF5F44
#define pinstCRaceChangeWnd_x                                      0xDF6240
#define pinstCRaidOptionsWnd_x                                     0xDF5F88
#define pinstCRaidWnd_x                                            0xDF601C
#define pinstCRealEstateItemsWnd_x                                 0xDF5FB0
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDF5F30
#define pinstCRealEstateManageWnd_x                                0xDF673C
#define pinstCRealEstateNeighborhoodWnd_x                          0xDF6758
#define pinstCRealEstatePlotSearchWnd_x                            0xDF6770
#define pinstCRealEstatePurchaseWnd_x                              0xDF6784
#define pinstCRespawnWnd_x                                         0xDF5F34
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDF625C
#define pinstCSendMoneyWnd_x                                       0xDF6740
#define pinstCServerListWnd_x                                      0xDF67A4
#define pinstCSkillsSelectWnd_x                                    0xDF671C
#define pinstCSkillsWnd_x                                          0xDF6294
#define pinstCSocialEditWnd_x                                      0xDF6798
#define pinstCSocialWnd_x                                          0xDF5FDC
#define pinstCSpellBookWnd_x                                       0xDF6720
#define pinstCStoryWnd_x                                           0xDF5FCC
#define pinstCTargetOfTargetWnd_x                                  0xF726E0
#define pinstCTargetWnd_x                                          0xDF5F2C
#define pinstCTaskOverlayWnd_x                                     0xDF6730
#define pinstCTaskSelectWnd_x                                      0xF72838
#define pinstCTaskManager_x                                        0xCC7AA8
#define pinstCTaskTemplateSelectWnd_x                              0xF728E8
#define pinstCTaskWnd_x                                            0xF72998
#define pinstCTextEntryWnd_x                                       0xDF67B4
#define pinstCTimeLeftWnd_x                                        0xDF5F80
#define pinstCTipWndCONTEXT_x                                      0xF72B9C
#define pinstCTipWndOFDAY_x                                        0xF72B98
#define pinstCTitleWnd_x                                           0xF72C48
#define pinstCTrackingWnd_x                                        0xDF6774
#define pinstCTradeskillWnd_x                                      0xF72DB0
#define pinstCTradeWnd_x                                           0xDF6010
#define pinstCTrainWnd_x                                           0xDF6008
#define pinstCTributeBenefitWnd_x                                  0xF72FB0
#define pinstCTributeMasterWnd_x                                   0xF73060
#define pinstCTributeTrophyWnd_x                                   0xF73110
#define pinstCVideoModesWnd_x                                      0xDF6018
#define pinstCVoiceMacroWnd_x                                      0xF5C408
#define pinstCVoteResultsWnd_x                                     0xDF5FA0
#define pinstCVoteWnd_x                                            0xDF5F90
#define pinstCWebManager_x                                         0xF5CA84
#define pinstCZoneGuideWnd_x                                       0xDF6738
#define pinstCZonePathWnd_x                                        0xDF6748

#define pinstEQSuiteTextureLoader_x                                0xC95088
#define pinstItemIconCache_x                                       0xF6BF70
#define pinstLootFiltersManager_x                                  0xCC7218
#define pinstRewardSelectionWnd_x                                  0xF71000

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5A8DF0
#define __CastRay2_x                                               0x5A8E40
#define __ConvertItemTags_x                                        0x5C49A0
#define __CleanItemTags_x                                          0x47D130
#define __DoesFileExist_x                                          0x8FCAC0
#define __EQGetTime_x                                              0x8F94B0
#define __ExecuteCmd_x                                             0x5A16D0
#define __FixHeading_x                                             0x993630
#define __GameLoop_x                                               0x6B5220
#define __get_bearing_x                                            0x5A8960
#define __get_melee_range_x                                        0x5A9030
#define __GetAnimationCache_x                                      0x71A4C0
#define __GetGaugeValueFromEQ_x                                    0x80CEF0
#define __GetLabelFromEQ_x                                         0x80E9D0
#define __GetXTargetType_x                                         0x995080
#define __HandleMouseWheel_x                                       0x6B60E0
#define __HeadingDiff_x                                            0x9936A0
#define __HelpPath_x                                               0xF577AC
#define __LoadFrontEnd_x                                           0x6B2540
#define __NewUIINI_x                                               0x80CBC0
#define __ProcessGameEvents_x                                      0x608E20
#define __ProcessMouseEvent_x                                      0x6085E0
#define __SaveColors_x                                             0x54E650
#define __STMLToText_x                                             0x936B80
#define __ToggleKeyRingItem_x                                      0x511F30
#define CMemoryMappedFile__SetFile_x                               0xA82990
#define CrashDetected_x                                            0x6B3FE0
#define DrawNetStatus_x                                            0x634A00
#define Expansion_HoT_x                                            0xEB96FC
#define Teleport_Table_Size_x                                      0xEAAAE4
#define Teleport_Table_x                                           0xEA8640
#define Util__FastTime_x                                           0x8F9080

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490340
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499250
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499020
#define CAdvancedLootWnd__AddPlayerToList_x                        0x4938E0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492D30

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x556100
#define AltAdvManager__IsAbilityReady_x                            0x555070
#define AltAdvManager__GetAAById_x                                 0x555270
#define AltAdvManager__CanTrainAbility_x                           0x5552E0
#define AltAdvManager__CanSeeAbility_x                             0x555640

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA080
#define CharacterZoneClient__HasSkill_x                            0x4D4F70
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6690
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE370
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BA970
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9020
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9100
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D91E0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C3020
#define CharacterZoneClient__BardCastBard_x                        0x4C5B80
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAA40
#define CharacterZoneClient__GetEffect_x                           0x4BA8B0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C4070
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C4140
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C4190
#define CharacterZoneClient__CalcAffectChange_x                    0x4C42E0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C44B0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2860
#define CharacterZoneClient__FindItemByGuid_x                      0x4D75F0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7070

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6DBBE0
#define CBankWnd__WndNotification_x                                0x6DB9C0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E9580

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x617360
#define CButtonWnd__CButtonWnd_x                                   0x932F60

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x7095E0
#define CChatManager__InitContextMenu_x                            0x702730
#define CChatManager__FreeChatWindow_x                             0x708120
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E85D0
#define CChatManager__SetLockedActiveChatWindow_x                  0x709260
#define CChatManager__CreateChatWindow_x                           0x708760

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E86F0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x9474C0
#define CContextMenu__dCContextMenu_x                              0x9476F0
#define CContextMenu__AddMenuItem_x                                0x947700
#define CContextMenu__RemoveMenuItem_x                             0x947A00
#define CContextMenu__RemoveAllMenuItems_x                         0x947A20
#define CContextMenu__CheckMenuItem_x                              0x947AA0
#define CContextMenu__SetMenuItem_x                                0x947930
#define CContextMenu__AddSeparator_x                               0x947890

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x948040
#define CContextMenuManager__RemoveMenu_x                          0x9480B0
#define CContextMenuManager__PopupMenu_x                           0x948170
#define CContextMenuManager__Flush_x                               0x947FE0
#define CContextMenuManager__GetMenu_x                             0x49B440
#define CContextMenuManager__CreateDefaultMenu_x                   0x714CB0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x89FB60
#define CChatService__GetFriendName_x                              0x8D6340

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x709E90
#define CChatWindow__Clear_x                                       0x70B160
#define CChatWindow__WndNotification_x                             0x70B8F0
#define CChatWindow__AddHistory_x                                  0x70AA20

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x944920
#define CComboWnd__Draw_x                                          0x943E20
#define CComboWnd__GetCurChoice_x                                  0x944760
#define CComboWnd__GetListRect_x                                   0x9442D0
#define CComboWnd__GetTextRect_x                                   0x944980
#define CComboWnd__InsertChoice_x                                  0x944460
#define CComboWnd__SetColors_x                                     0x944430
#define CComboWnd__SetChoice_x                                     0x944730
#define CComboWnd__GetItemCount_x                                  0x944770
#define CComboWnd__GetCurChoiceText_x                              0x9447B0
#define CComboWnd__GetChoiceText_x                                 0x944780
#define CComboWnd__InsertChoiceAtIndex_x                           0x9444F0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x7126A0
#define CContainerWnd__vftable_x                                   0xB08E34
#define CContainerWnd__SetContainer_x                              0x713C00

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x549090
#define CDisplay__PreZoneMainUI_x                                  0x5490A0
#define CDisplay__CleanGameUI_x                                    0x54E410
#define CDisplay__GetClickedActor_x                                0x5413B0
#define CDisplay__GetUserDefinedColor_x                            0x539A70
#define CDisplay__GetWorldFilePath_x                               0x542E20
#define CDisplay__is3dON_x                                         0x53E010
#define CDisplay__ReloadUI_x                                       0x548520
#define CDisplay__WriteTextHD2_x                                   0x53DE00
#define CDisplay__TrueDistance_x                                   0x544AE0
#define CDisplay__SetViewActor_x                                   0x540CD0
#define CDisplay__GetFloorHeight_x                                 0x53E0D0
#define CDisplay__SetRenderWindow_x                                0x53CA30
#define CDisplay__ToggleScreenshotMode_x                           0x5407A0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x9671C0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x94AA20
#define CEditWnd__GetCharIndexPt_x                                 0x94B940
#define CEditWnd__GetDisplayString_x                               0x94B7E0
#define CEditWnd__GetHorzOffset_x                                  0x94A050
#define CEditWnd__GetLineForPrintableChar_x                        0x94CAE0
#define CEditWnd__GetSelStartPt_x                                  0x94BBF0
#define CEditWnd__GetSTMLSafeText_x                                0x94B600
#define CEditWnd__PointFromPrintableChar_x                         0x94C710
#define CEditWnd__SelectableCharFromPoint_x                        0x94C880
#define CEditWnd__SetEditable_x                                    0x94BCC0
#define CEditWnd__SetWindowTextA_x                                 0x94B380

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5F6A80
#define CEverQuest__ClickedPlayer_x                                0x5E8AA0
#define CEverQuest__CreateTargetIndicator_x                        0x6060B0
#define CEverQuest__DeleteTargetIndicator_x                        0x606140
#define CEverQuest__DoTellWindow_x                                 0x4E87D0
#define CEverQuest__OutputTextToLog_x                              0x4E8A50
#define CEverQuest__DropHeldItemOnGround_x                         0x5DDAE0
#define CEverQuest__dsp_chat_x                                     0x4E8DE0
#define CEverQuest__trimName_x                                     0x602390
#define CEverQuest__Emote_x                                        0x5F72E0
#define CEverQuest__EnterZone_x                                    0x5F1260
#define CEverQuest__GetBodyTypeDesc_x                              0x5FBC50
#define CEverQuest__GetClassDesc_x                                 0x5FC290
#define CEverQuest__GetClassThreeLetterCode_x                      0x5FC890
#define CEverQuest__GetDeityDesc_x                                 0x6049F0
#define CEverQuest__GetLangDesc_x                                  0x5FCA50
#define CEverQuest__GetRaceDesc_x                                  0x5FC270
#define CEverQuest__InterpretCmd_x                                 0x604FC0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5E1CE0
#define CEverQuest__LMouseUp_x                                     0x5E0070
#define CEverQuest__RightClickedOnPlayer_x                         0x5E25C0
#define CEverQuest__RMouseUp_x                                     0x5E0FF0
#define CEverQuest__SetGameState_x                                 0x5DD870
#define CEverQuest__UPCNotificationFlush_x                         0x602290
#define CEverQuest__IssuePetCommand_x                              0x5FDE50
#define CEverQuest__ReportSuccessfulHit_x                          0x5F86D0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x724630
#define CGaugeWnd__CalcLinesFillRect_x                             0x724690
#define CGaugeWnd__Draw_x                                          0x723CB0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF260
#define CGuild__GetGuildName_x                                     0x4AE340
#define CGuild__GetGuildIndex_x                                    0x4AE6D0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73FAF0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x617720

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x74CB20
#define CInvSlotMgr__MoveItem_x                                    0x74B830
#define CInvSlotMgr__SelectSlot_x                                  0x74CBF0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x74A0B0
#define CInvSlot__SliderComplete_x                                 0x747E10
#define CInvSlot__GetItemBase_x                                    0x747790
#define CInvSlot__UpdateItem_x                                     0x747900

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x74E660
#define CInvSlotWnd__CInvSlotWnd_x                                 0x74D810
#define CInvSlotWnd__HandleLButtonUp_x                             0x74E1E0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x8081F0
#define CItemDisplayWnd__UpdateStrings_x                           0x75CE00
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x756AF0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x757020
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x75D400
#define CItemDisplayWnd__AboutToShow_x                             0x75CA50
#define CItemDisplayWnd__WndNotification_x                         0x75E4F0
#define CItemDisplayWnd__RequestConvertItem_x                      0x75DFB0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x75BAC0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x75C870

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x840C30

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x7629F0

// CLabel 
#define CLabel__Draw_x                                             0x768430

// CListWnd
#define CListWnd__CListWnd_x                                       0x91D150
#define CListWnd__dCListWnd_x                                      0x91D470
#define CListWnd__AddColumn_x                                      0x9218B0
#define CListWnd__AddColumn1_x                                     0x921900
#define CListWnd__AddLine_x                                        0x921C90
#define CListWnd__AddString_x                                      0x921A90
#define CListWnd__CalculateFirstVisibleLine_x                      0x921670
#define CListWnd__CalculateVSBRange_x                              0x921450
#define CListWnd__ClearSel_x                                       0x922470
#define CListWnd__ClearAllSel_x                                    0x9224D0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x922ED0
#define CListWnd__Compare_x                                        0x920D80
#define CListWnd__Draw_x                                           0x91D5A0
#define CListWnd__DrawColumnSeparators_x                           0x91FD70
#define CListWnd__DrawHeader_x                                     0x9201D0
#define CListWnd__DrawItem_x                                       0x9206C0
#define CListWnd__DrawLine_x                                       0x91FED0
#define CListWnd__DrawSeparator_x                                  0x91FE10
#define CListWnd__EnableLine_x                                     0x91F660
#define CListWnd__EnsureVisible_x                                  0x922E00
#define CListWnd__ExtendSel_x                                      0x9223A0
#define CListWnd__GetColumnTooltip_x                               0x91F1A0
#define CListWnd__GetColumnMinWidth_x                              0x91F210
#define CListWnd__GetColumnWidth_x                                 0x91F110
#define CListWnd__GetCurSel_x                                      0x91EAA0
#define CListWnd__GetItemAtPoint_x                                 0x91F8D0
#define CListWnd__GetItemAtPoint1_x                                0x91F940
#define CListWnd__GetItemData_x                                    0x91EB20
#define CListWnd__GetItemHeight_x                                  0x91EEE0
#define CListWnd__GetItemIcon_x                                    0x91ECB0
#define CListWnd__GetItemRect_x                                    0x91F750
#define CListWnd__GetItemText_x                                    0x91EB60
#define CListWnd__GetSelList_x                                     0x922520
#define CListWnd__GetSeparatorRect_x                               0x91FB80
#define CListWnd__InsertLine_x                                     0x922080
#define CListWnd__RemoveLine_x                                     0x9221D0
#define CListWnd__SetColors_x                                      0x921420
#define CListWnd__SetColumnJustification_x                         0x921150
#define CListWnd__SetColumnWidth_x                                 0x921070
#define CListWnd__SetCurSel_x                                      0x9222E0
#define CListWnd__SetItemColor_x                                   0x922AC0
#define CListWnd__SetItemData_x                                    0x922A80
#define CListWnd__SetItemText_x                                    0x922690
#define CListWnd__ShiftColumnSeparator_x                           0x921210
#define CListWnd__Sort_x                                           0x920F00
#define CListWnd__ToggleSel_x                                      0x922310
#define CListWnd__SetColumnsSizable_x                              0x9212C0
#define CListWnd__SetItemWnd_x                                     0x922940
#define CListWnd__GetItemWnd_x                                     0x91ED00
#define CListWnd__SetItemIcon_x                                    0x922710
#define CListWnd__CalculateCustomWindowPositions_x                 0x921770
#define CListWnd__SetVScrollPos_x                                  0x921050

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x77DBA0
#define CMapViewWnd__GetWorldCoordinates_x                         0x77C2B0
#define CMapViewWnd__HandleLButtonDown_x                           0x7792F0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x79DBA0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79E480
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79E9B0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A1940
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x79C700
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A7500
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x79D7B0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8A3C70
#define CPacketScrambler__hton_x                                   0x8A3C60

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x93C1A0
#define CSidlManager__FindScreenPieceTemplate_x                    0x93C5B0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x93C3A0
#define CSidlManager__CreateLabel_x                                0x7FF630
#define CSidlManager__CreateXWndFromTemplate_x                     0x93F510
#define CSidlManager__CreateXWndFromTemplate1_x                    0x93F6F0
#define CSidlManager__CreateXWnd_x                                 0x7FF560
#define CSidlManager__CreateHotButtonWnd_x                         0x7FFB20

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x938CA0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x938BA0
#define CSidlScreenWnd__ConvertToRes_x                             0x95E1A0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x938630
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x938320
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x9383F0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x9384C0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x939120
#define CSidlScreenWnd__EnableIniStorage_x                         0x9395F0
#define CSidlScreenWnd__GetSidlPiece_x                             0x939310
#define CSidlScreenWnd__Init1_x                                    0x937F20
#define CSidlScreenWnd__LoadIniInfo_x                              0x939640
#define CSidlScreenWnd__LoadIniListWnd_x                           0x93A180
#define CSidlScreenWnd__LoadSidlScreen_x                           0x937330
#define CSidlScreenWnd__StoreIniInfo_x                             0x939D00
#define CSidlScreenWnd__StoreIniVis_x                              0x93A060
#define CSidlScreenWnd__WndNotification_x                          0x939030
#define CSidlScreenWnd__GetChildItem_x                             0x939570
#define CSidlScreenWnd__HandleLButtonUp_x                          0x928D30
#define CSidlScreenWnd__m_layoutCopy_x                             0x15EDF20

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x67BF50
#define CSkillMgr__GetSkillCap_x                                   0x67C130
#define CSkillMgr__GetNameToken_x                                  0x67B6D0
#define CSkillMgr__IsActivatedSkill_x                              0x67B810
#define CSkillMgr__IsCombatSkill_x                                 0x67B750

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x948E30
#define CSliderWnd__SetValue_x                                     0x948CA0
#define CSliderWnd__SetNumTicks_x                                  0x948D00

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x805680

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x951700
#define CStmlWnd__CalculateHSBRange_x                              0x952820
#define CStmlWnd__CalculateVSBRange_x                              0x952790
#define CStmlWnd__CanBreakAtCharacter_x                            0x956B60
#define CStmlWnd__FastForwardToEndOfTag_x                          0x9577F0
#define CStmlWnd__ForceParseNow_x                                  0x951CF0
#define CStmlWnd__GetNextTagPiece_x                                0x956AC0
#define CStmlWnd__GetSTMLText_x                                    0x5014B0
#define CStmlWnd__GetVisibleText_x                                 0x951D10
#define CStmlWnd__InitializeWindowVariables_x                      0x957640
#define CStmlWnd__MakeStmlColorTag_x                               0x950D70
#define CStmlWnd__MakeWndNotificationTag_x                         0x950DE0
#define CStmlWnd__SetSTMLText_x                                    0x94FE20
#define CStmlWnd__StripFirstSTMLLines_x                            0x9588C0
#define CStmlWnd__UpdateHistoryString_x                            0x957A00

// CTabWnd 
#define CTabWnd__Draw_x                                            0x94EEA0
#define CTabWnd__DrawCurrentPage_x                                 0x94F5D0
#define CTabWnd__DrawTab_x                                         0x94F2F0
#define CTabWnd__GetCurrentPage_x                                  0x94E6A0
#define CTabWnd__GetPageInnerRect_x                                0x94E8E0
#define CTabWnd__GetTabInnerRect_x                                 0x94E820
#define CTabWnd__GetTabRect_x                                      0x94E6D0
#define CTabWnd__InsertPage_x                                      0x94EAF0
#define CTabWnd__SetPage_x                                         0x94E960
#define CTabWnd__SetPageRect_x                                     0x94EDE0
#define CTabWnd__UpdatePage_x                                      0x94F1B0
#define CTabWnd__GetPageFromTabIndex_x                             0x94F230
#define CTabWnd__GetCurrentTabIndex_x                              0x94E690

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x762DC0
#define CPageWnd__SetTabText_x                                     0x94E1F0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8E80

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x925BF0
#define CTextureFont__GetTextExtent_x                              0x925DB0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AF410
#define CHtmlComponentWnd__ValidateUri_x                           0x7414E0
#define CHtmlWnd__SetClientCallbacks_x                             0x61C7A0
#define CHtmlWnd__AddObserver_x                                    0x61C7C0
#define CHtmlWnd__RemoveObserver_x                                 0x61C820
#define Window__getProgress_x                                      0x8595A0
#define Window__getStatus_x                                        0x8595C0
#define Window__getURI_x                                           0x8595D0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x963C40

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x912C40

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8410
#define CXStr__CXStr1_x                                            0x4FC5A0
#define CXStr__CXStr3_x                                            0x8F55F0
#define CXStr__dCXStr_x                                            0x4787D0
#define CXStr__operator_equal_x                                    0x8F5820
#define CXStr__operator_equal1_x                                   0x8F5860
#define CXStr__operator_plus_equal1_x                              0x8F62F0
#define CXStr__SetString_x                                         0x8F81E0
#define CXStr__operator_char_p_x                                   0x8F5D30
#define CXStr__GetChar_x                                           0x8F7B30
#define CXStr__Delete_x                                            0x8F73E0
#define CXStr__GetUnicode_x                                        0x8F7BA0
#define CXStr__GetLength_x                                         0x4A8C20
#define CXStr__Mid_x                                               0x47D4E0
#define CXStr__Insert_x                                            0x8F7C00
#define CXStr__FindNext_x                                          0x8F7850

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x9470E0
#define CXWnd__BringToTop_x                                        0x92C420
#define CXWnd__Center_x                                            0x92BFA0
#define CXWnd__ClrFocus_x                                          0x92BDC0
#define CXWnd__Destroy_x                                           0x92BE60
#define CXWnd__DoAllDrawing_x                                      0x9284C0
#define CXWnd__DrawChildren_x                                      0x928490
#define CXWnd__DrawColoredRect_x                                   0x928920
#define CXWnd__DrawTooltip_x                                       0x926FF0
#define CXWnd__DrawTooltipAtPoint_x                                0x9270B0
#define CXWnd__GetBorderFrame_x                                    0x928780
#define CXWnd__GetChildWndAt_x                                     0x92C4C0
#define CXWnd__GetClientClipRect_x                                 0x92A700
#define CXWnd__GetScreenClipRect_x                                 0x92A7D0
#define CXWnd__GetScreenRect_x                                     0x92A990
#define CXWnd__GetTooltipRect_x                                    0x928970
#define CXWnd__GetWindowTextA_x                                    0x49CB20
#define CXWnd__IsActive_x                                          0x9290B0
#define CXWnd__IsDescendantOf_x                                    0x92B350
#define CXWnd__IsReallyVisible_x                                   0x92B380
#define CXWnd__IsType_x                                            0x92CB30
#define CXWnd__Move_x                                              0x92B3E0
#define CXWnd__Move1_x                                             0x92B490
#define CXWnd__ProcessTransition_x                                 0x92BF50
#define CXWnd__Refade_x                                            0x92B760
#define CXWnd__Resize_x                                            0x92B9F0
#define CXWnd__Right_x                                             0x92C1E0
#define CXWnd__SetFocus_x                                          0x92BD80
#define CXWnd__SetFont_x                                           0x92BDF0
#define CXWnd__SetKeyTooltip_x                                     0x92C940
#define CXWnd__SetMouseOver_x                                      0x9298C0
#define CXWnd__StartFade_x                                         0x92B230
#define CXWnd__GetChildItem_x                                      0x92C630
#define CXWnd__SetParent_x                                         0x92B130
#define CXWnd__Minimize_x                                          0x92BA60

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x95F220

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x92F3C0
#define CXWndManager__DrawWindows_x                                0x92F3E0
#define CXWndManager__GetKeyboardFlags_x                           0x931BD0
#define CXWndManager__HandleKeyboardMsg_x                          0x931780
#define CXWndManager__RemoveWnd_x                                  0x931E20
#define CXWndManager__RemovePendingDeletionWnd_x                   0x932380

// CDBStr
#define CDBStr__GetString_x                                        0x538A10

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BB950
#define EQ_Character__Cur_HP_x                                     0x4D1FB0
#define EQ_Character__Cur_Mana_x                                   0x4D96E0
#define EQ_Character__GetCastingTimeModifier_x                     0x4BE9C0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B24A0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B25F0
#define EQ_Character__GetHPRegen_x                                 0x4DF480
#define EQ_Character__GetEnduranceRegen_x                          0x4DFA80
#define EQ_Character__GetManaRegen_x                               0x4DFEC0
#define EQ_Character__Max_Endurance_x                              0x642B70
#define EQ_Character__Max_HP_x                                     0x4D1DE0
#define EQ_Character__Max_Mana_x                                   0x642970
#define EQ_Character__doCombatAbility_x                            0x644FD0
#define EQ_Character__UseSkill_x                                   0x4E1CA0
#define EQ_Character__GetConLevel_x                                0x63B9B0
#define EQ_Character__IsExpansionFlag_x                            0x59FEA0
#define EQ_Character__TotalEffect_x                                0x4C52C0
#define EQ_Character__GetPCSpellAffect_x                           0x4BF5D0
#define EQ_Character__SpellDuration_x                              0x4BF100
#define EQ_Character__GetAdjustedSkill_x                           0x4D4D30
#define EQ_Character__GetBaseSkill_x                               0x4D5CD0
#define EQ_Character__CanUseItem_x                                 0x4D99F0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8C31A0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x659130

//PcClient
#define PcClient__PcClient_x                                       0x6390E0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B95B0
#define CCharacterListWnd__EnterWorld_x                            0x4B8FF0
#define CCharacterListWnd__Quit_x                                  0x4B8D40
#define CCharacterListWnd__UpdateList_x                            0x4B9180

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x61D9F0
#define EQ_Item__CreateItemTagString_x                             0x89D4F0
#define EQ_Item__IsStackable_x                                     0x8A2030
#define EQ_Item__GetImageNum_x                                     0x89EF60
#define EQ_Item__CreateItemClient_x                                0x61CBC0
#define EQ_Item__GetItemValue_x                                    0x8A0270
#define EQ_Item__ValueSellMerchant_x                               0x8A3850
#define EQ_Item__IsKeyRingItem_x                                   0x8A1960
#define EQ_Item__CanGoInBag_x                                      0x61DB10
#define EQ_Item__IsEmpty_x                                         0x8A14A0
#define EQ_Item__GetMaxItemCount_x                                 0x8A0680
#define EQ_Item__GetHeldItem_x                                     0x89EE30
#define EQ_Item__GetAugmentFitBySlot_x                             0x89CE70

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x556DD0
#define EQ_LoadingS__Array_x                                       0xC1CB60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x6434D0
#define EQ_PC__GetAlternateAbilityId_x                             0x8ACA70
#define EQ_PC__GetCombatAbility_x                                  0x8AD0E0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8AD150
#define EQ_PC__GetItemRecastTimer_x                                0x645550
#define EQ_PC__HasLoreItem_x                                       0x63C170
#define EQ_PC__AlertInventoryChanged_x                             0x63B2E0
#define EQ_PC__GetPcZoneClient_x                                   0x667C50
#define EQ_PC__RemoveMyAffect_x                                    0x648780
#define EQ_PC__GetKeyRingItems_x                                   0x8AD9E0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8AD770
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8ADCE0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5A6400
#define EQItemList__add_object_x                                   0x5D33C0
#define EQItemList__add_item_x                                     0x5A6960
#define EQItemList__delete_item_x                                  0x5A69B0
#define EQItemList__FreeItemList_x                                 0x5A68B0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x5354D0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x65A9B0
#define EQPlayer__dEQPlayer_x                                      0x64DD00
#define EQPlayer__DoAttack_x                                       0x662910
#define EQPlayer__EQPlayer_x                                       0x64E3C0
#define EQPlayer__SetNameSpriteState_x                             0x652690
#define EQPlayer__SetNameSpriteTint_x                              0x653560
#define PlayerBase__HasProperty_j_x                                0x991A10
#define EQPlayer__IsTargetable_x                                   0x991EB0
#define EQPlayer__CanSee_x                                         0x991D10
#define EQPlayer__CanSee1_x                                        0x991DE0
#define PlayerBase__GetVisibilityLineSegment_x                     0x991AD0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x6656E0
#define PlayerZoneClient__GetLevel_x                               0x667C90
#define PlayerZoneClient__IsValidTeleport_x                        0x5D4530
#define PlayerZoneClient__LegalPlayerRace_x                        0x550240

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x65D820
#define EQPlayerManager__GetSpawnByName_x                          0x65D8D0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x65D960

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x621150
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x6211D0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x621210
#define KeypressHandler__ClearCommandStateArray_x                  0x622620
#define KeypressHandler__HandleKeyDown_x                           0x622640
#define KeypressHandler__HandleKeyUp_x                             0x6226E0
#define KeypressHandler__SaveKeymapping_x                          0x622B30

// MapViewMap 
#define MapViewMap__Clear_x                                        0x779A10
#define MapViewMap__SaveEx_x                                       0x77CDD0
#define MapViewMap__SetZoom_x                                      0x781490

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C10C0

// StringTable 
#define StringTable__getString_x                                   0x8BBC90

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x6483F0
#define PcZoneClient__RemovePetEffect_x                            0x648A20
#define PcZoneClient__HasAlternateAbility_x                        0x6427A0
#define PcZoneClient__GetCurrentMod_x                              0x4E4D60
#define PcZoneClient__GetModCap_x                                  0x4E4C60
#define PcZoneClient__CanEquipItem_x                               0x642E70
#define PcZoneClient__GetItemByID_x                                0x6459C0
#define PcZoneClient__GetItemByItemClass_x                         0x645B10
#define PcZoneClient__RemoveBuffEffect_x                           0x648A40
#define PcZoneClient__BandolierSwap_x                              0x643A90
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x6454F0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5D8FE0

//IconCache
#define IconCache__GetIcon_x                                       0x719D60

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x711840
#define CContainerMgr__CloseContainer_x                            0x711B10
#define CContainerMgr__OpenExperimentContainer_x                   0x712590

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D1BA0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x615B30

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76FF00
#define CLootWnd__RequestLootSlot_x                                0x76F130

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x573E00
#define EQ_Spell__SpellAffects_x                                   0x574270
#define EQ_Spell__SpellAffectBase_x                                0x574030
#define EQ_Spell__IsStackable_x                                    0x4C99D0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9820
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6950
#define EQ_Spell__IsSPAStacking_x                                  0x5750C0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x5745D0
#define EQ_Spell__IsNoRemove_x                                     0x4C99B0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x5750D0
#define __IsResEffectSpell_x                                       0x4C8D00

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4ACF70

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8CB7C0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x8189B0
#define CTargetWnd__WndNotification_x                              0x818240
#define CTargetWnd__RefreshTargetBuffs_x                           0x818510
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x8173C0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x81CFB0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x532F50
#define CTaskManager__HandleMessage_x                              0x5313E0
#define CTaskManager__GetTaskStatus_x                              0x533000
#define CTaskManager__GetElementDescription_x                      0x533080

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x56F370
#define EqSoundManager__PlayScriptMp3_x                            0x56F4D0
#define EqSoundManager__SoundAssistPlay_x                          0x67FE90
#define EqSoundManager__WaveInstancePlay_x                         0x67F400

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x526CC0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x94D700

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x55E870
#define CAltAbilityData__GetMercMaxRank_x                          0x55E800
#define CAltAbilityData__GetMaxRank_x                              0x553F30

//CTargetRing
#define CTargetRing__Cast_x                                        0x613C50

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9800
#define CharacterBase__CreateItemGlobalIndex_x                     0x50E5A0
#define CharacterBase__CreateItemIndex_x                           0x61BD50
#define CharacterBase__GetItemPossession_x                         0x4F9E70
#define CharacterBase__GetItemByGlobalIndex_x                      0x8D3DD0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8D3E30
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F8960
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F9190
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F9240

//messages
#define msg_spell_worn_off_x                                       0x598010
#define msg_new_text_x                                             0x58CD80
#define __msgTokenTextParam_x                                      0x59A540
#define msgTokenText_x                                             0x59A790

//SpellManager
#define SpellManager__vftable_x                                    0xAE3094
#define SpellManager__SpellManager_x                               0x6831B0
#define Spellmanager__LoadTextSpells_x                             0x683AA0
#define SpellManager__GetSpellByGroupAndRank_x                     0x683380

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x995970

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x50EBF0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x59E310
#define ItemGlobalIndex__IsEquippedLocation_x                      0x634860
#define ItemGlobalIndex__IsValidIndex_x                            0x50EC50

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8CC160
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8CC3E0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x768770

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x715F60
#define CCursorAttachment__AttachToCursor1_x                       0x715FA0
#define CCursorAttachment__Deactivate_x                            0x716F90

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x940540
#define CSidlManagerBase__CreatePageWnd_x                          0x93FD40
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x93BFC0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x93BF50

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x95D750
#define CEQSuiteTextureLoader__GetTexture_x                        0x95D410

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50BAE0
#define CFindItemWnd__WndNotification_x                            0x50C5C0
#define CFindItemWnd__Update_x                                     0x50D130
#define CFindItemWnd__PickupSelectedItem_x                         0x50B320

//IString
#define IString__Append_x                                          0x4FB660

//Camera
#define CDisplay__cameraType_x                                     0xDF6020
#define EverQuest__Cameras_x                                       0xEB9A4C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x5142D0
#define LootFiltersManager__GetItemFilterData_x                    0x513BD0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x513C00
#define LootFiltersManager__SetItemLootFilter_x                    0x513E20

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BFB40

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x99B530
#define CResolutionHandler__GetWindowedStyle_x                     0x67AB30

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70E600

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8DFCE0
#define CDistillerInfo__Instance_x                                 0x8DFC80

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72E870
#define CGroupWnd__UpdateDisplay_x                                 0x72DBC0

//ItemBase
#define ItemBase__IsLore_x                                         0x8A1A00
#define ItemBase__IsLoreEquipped_x                                 0x8A1A70

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5D3320
#define EQPlacedItemManager__GetItemByGuid_x                       0x5D3460
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5D34C0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x670360
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x673CC0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x501E50

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F06D0
#define FactionManagerClient__HandleFactionMessage_x               0x4F0D40
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F1340
#define FactionManagerClient__GetMaxFaction_x                      0x4F135F
#define FactionManagerClient__GetMinFaction_x                      0x4F1310

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4F9E40

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x924B70

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BE30

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FA070

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x55DD10

//CTargetManager
#define CTargetManager__Get_x                                      0x686A40

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x670360

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8C40

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5A6850

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF570E0

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
