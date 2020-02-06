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
#define __ExpectedVersionDate                                     "Feb  4 2020"
#define __ExpectedVersionTime                                     "09:38:07"
#define __ActualVersionDate_x                                      0xB16CD4
#define __ActualVersionTime_x                                      0xB16CC8
#define __ActualVersionBuild_x                                     0xB029DC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x63B460
#define __MemChecker1_x                                            0x90E520
#define __MemChecker2_x                                            0x6C9C90
#define __MemChecker3_x                                            0x6C9BE0
#define __MemChecker4_x                                            0x864E80
#define __EncryptPad0_x                                            0xC4E3F0
#define __EncryptPad1_x                                            0xCAC658
#define __EncryptPad2_x                                            0xC5EC88
#define __EncryptPad3_x                                            0xC5E888
#define __EncryptPad4_x                                            0xC9CC08
#define __EncryptPad5_x                                            0xF6D81C
#define __AC1_x                                                    0x821836
#define __AC2_x                                                    0x5F52DF
#define __AC3_x                                                    0x5FC9DF
#define __AC4_x                                                    0x6009B0
#define __AC5_x                                                    0x606CBF
#define __AC6_x                                                    0x60B1B6
#define __AC7_x                                                    0x5F4D50
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x192EF8

// Direct Input
#define DI8__Main_x                                                0xF6D83C
#define DI8__Keyboard_x                                            0xF6D840
#define DI8__Mouse_x                                               0xF6D85C
#define DI8__Mouse_Copy_x                                          0xEC8EC4
#define DI8__Mouse_Check_x                                         0xF6E308
#define __AutoSkillArray_x                                         0xEC9DDC
#define __Attack_x                                                 0xF67C03
#define __Autofire_x                                               0xF67C04
#define __BindList_x                                               0xC3CE20
#define g_eqCommandStates_x                                        0xC3DBA0
#define __Clicks_x                                                 0xEC8F7C
#define __CommandList_x                                            0xC3E760
#define __CurrentMapLabel_x                                        0xF806CC
#define __CurrentSocial_x                                          0xC267CC
#define __DoAbilityList_x                                          0xEFF724
#define __do_loot_x                                                0x5C0C90
#define __DrawHandler_x                                            0x15FFA48
#define __GroupCount_x                                             0xEC39DA
#define __Guilds_x                                                 0xEC7DE0
#define __gWorld_x                                                 0xEC3C28
#define __HWnd_x                                                   0xF6E2E8
#define __heqmain_x                                                0xF7079C
#define __InChatMode_x                                             0xEC8EAC
#define __LastTell_x                                               0xECAE20
#define __LMouseHeldTime_x                                         0xEC8FE8
#define __Mouse_x                                                  0xF6D828
#define __MouseLook_x                                              0xEC8F42
#define __MouseEventTime_x                                         0xF686E4
#define __gpbCommandEvent_x                                        0xEC3C30
#define __NetStatusToggle_x                                        0xEC8F45
#define __PCNames_x                                                0xECA3CC
#define __RangeAttackReady_x                                       0xECA0C0
#define __RMouseHeldTime_x                                         0xEC8FE4
#define __RunWalkState_x                                           0xEC8EB0
#define __ScreenMode_x                                             0xE0F1A8
#define __ScreenX_x                                                0xEC8E64
#define __ScreenY_x                                                0xEC8E60
#define __ScreenXMax_x                                             0xEC8E68
#define __ScreenYMax_x                                             0xEC8E6C
#define __ServerHost_x                                             0xEC3E63
#define __ServerName_x                                             0xEFF6E4
#define __ShiftKeyDown_x                                           0xEC953C
#define __ShowNames_x                                              0xECA27C
#define __Socials_x                                                0xEFF7E4
#define __SubscriptionType_x                                       0xFC4BD8
#define __TargetAggroHolder_x                                      0xF83080
#define __ZoneType_x                                               0xEC9340
#define __GroupAggro_x                                             0xF830C0
#define __LoginName_x                                              0xF6DF94
#define __Inviter_x                                                0xF67B80
#define __AttackOnAssist_x                                         0xECA238
#define __UseTellWindows_x                                         0xECA568
#define __gfMaxZoomCameraDistance_x                                0xB0C620
#define __gfMaxCameraDistance_x                                    0xB389E4
#define __pulAutoRun_x                                             0xEC8F60
#define __pulForward_x                                             0xECA5A0
#define __pulBackward_x                                            0xECA5A4
#define __pulTurnRight_x                                           0xECA5A8
#define __pulTurnLeft_x                                            0xECA5AC
#define __pulStrafeLeft_x                                          0xECA5B0
#define __pulStrafeRight_x                                         0xECA5B4

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEC4178
#define instEQZoneInfo_x                                           0xEC9138
#define pinstActiveBanker_x                                        0xEC3D10
#define pinstActiveCorpse_x                                        0xEC3D08
#define pinstActiveGMaster_x                                       0xEC3D0C
#define pinstActiveMerchant_x                                      0xEC3D04
#define pinstAltAdvManager_x                                       0xE103A8
#define pinstBandageTarget_x                                       0xEC3D20
#define pinstCamActor_x                                            0xE0F198
#define pinstCDBStr_x                                              0xE0F0C4
#define pinstCDisplay_x                                            0xEC387C
#define pinstCEverQuest_x                                          0xF6D858
#define pinstEverQuestInfo_x                                       0xEC8E58
#define pinstCharData_x                                            0xEC3C1C
#define pinstCharSpawn_x                                           0xEC3D58
#define pinstControlledMissile_x                                   0xEC186C
#define pinstControlledPlayer_x                                    0xEC3D58
#define pinstCResolutionHandler_x                                  0x15FFC78
#define pinstCSidlManager_x                                        0x15FEC10
#define pinstCXWndManager_x                                        0x15FEC0C
#define instDynamicZone_x                                          0xEC7CB8
#define pinstDZMember_x                                            0xEC7DC8
#define pinstDZTimerInfo_x                                         0xEC7DCC
#define pinstEqLogin_x                                             0xF6D8E0
#define instEQMisc_x                                               0xE0F008
#define pinstEQSoundManager_x                                      0xE11378
#define pinstEQSpellStrings_x                                      0xCD19E8
#define instExpeditionLeader_x                                     0xEC7D02
#define instExpeditionName_x                                       0xEC7D42
#define pinstGroup_x                                               0xEC39D6
#define pinstImeManager_x                                          0x15FEC08
#define pinstLocalPlayer_x                                         0xEC3D00
#define pinstMercenaryData_x                                       0xF6A1DC
#define pinstMercenaryStats_x                                      0xF831CC
#define pinstModelPlayer_x                                         0xEC3D18
#define pinstPCData_x                                              0xEC3C1C
#define pinstSkillMgr_x                                            0xF6C340
#define pinstSpawnManager_x                                        0xF6ADE8
#define pinstSpellManager_x                                        0xF6C580
#define pinstSpellSets_x                                           0xF6082C
#define pinstStringTable_x                                         0xEC3C24
#define pinstSwitchManager_x                                       0xEC1718
#define pinstTarget_x                                              0xEC3D54
#define pinstTargetObject_x                                        0xEC3F6C
#define pinstTargetSwitch_x                                        0xEC1874
#define pinstTaskMember_x                                          0xE0EE98
#define pinstTrackTarget_x                                         0xEC3D5C
#define pinstTradeTarget_x                                         0xEC3D14
#define instTributeActive_x                                        0xE0F029
#define pinstViewActor_x                                           0xE0F194
#define pinstWorldData_x                                           0xEC3880
#define pinstZoneAddr_x                                            0xEC93D8
#define pinstPlayerPath_x                                          0xF6AE80
#define pinstTargetIndicator_x                                     0xF6C7E8
#define EQObject_Top_x                                             0xEC3CFC
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xE0F464
#define pinstCAchievementsWnd_x                                    0xE0F4D0
#define pinstCActionsWnd_x                                         0xE0F48C
#define pinstCAdvancedDisplayOptionsWnd_x                          0xE0F1A0
#define pinstCAdvancedLootWnd_x                                    0xE0F9F4
#define pinstCAdventureLeaderboardWnd_x                            0xF79EA0
#define pinstCAdventureRequestWnd_x                                0xF79F50
#define pinstCAdventureStatsWnd_x                                  0xF7A000
#define pinstCAggroMeterWnd_x                                      0xE0F1C0
#define pinstCAlarmWnd_x                                           0xE0F52C
#define pinstCAlertHistoryWnd_x                                    0xE0F1FC
#define pinstCAlertStackWnd_x                                      0xE0F560
#define pinstCAlertWnd_x                                           0xE0F5EC
#define pinstCAltStorageWnd_x                                      0xF7A360
#define pinstCAudioTriggersWindow_x                                0xCC3D18
#define pinstCAuraWnd_x                                            0xE0F164
#define pinstCAvaZoneWnd_x                                         0xE0F4C0
#define pinstCBandolierWnd_x                                       0xE0F190
#define pinstCBankWnd_x                                            0xE0F200
#define pinstCBarterMerchantWnd_x                                  0xF7B5A0
#define pinstCBarterSearchWnd_x                                    0xF7B650
#define pinstCBarterWnd_x                                          0xF7B700
#define pinstCBazaarConfirmationWnd_x                              0xE0F504
#define pinstCBazaarSearchWnd_x                                    0xE0F468
#define pinstCBazaarWnd_x                                          0xE0F510
#define pinstCBlockedBuffWnd_x                                     0xE0F16C
#define pinstCBlockedPetBuffWnd_x                                  0xE0F188
#define pinstCBodyTintWnd_x                                        0xE0F498
#define pinstCBookWnd_x                                            0xE0F1EC
#define pinstCBreathWnd_x                                          0xE0F47C
#define pinstCBuffWindowNORMAL_x                                   0xE0F570
#define pinstCBuffWindowSHORT_x                                    0xE0F574
#define pinstCBugReportWnd_x                                       0xE0F1F8
#define pinstCButtonWnd_x                                          0x15FEE78
#define pinstCCastingWnd_x                                         0xE0F1D8
#define pinstCCastSpellWnd_x                                       0xE0F470
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE0F4B4
#define pinstCChatWindowManager_x                                  0xF7C1C0
#define pinstCClaimWnd_x                                           0xF7C318
#define pinstCColorPickerWnd_x                                     0xE0F234
#define pinstCCombatAbilityWnd_x                                   0xE0F520
#define pinstCCombatSkillsSelectWnd_x                              0xE0F4CC
#define pinstCCompassWnd_x                                         0xE0F490
#define pinstCConfirmationDialog_x                                 0xF81218
#define pinstCContainerMgr_x                                       0xE0F4B0
#define pinstCContextMenuManager_x                                 0x15FEBC8
#define pinstCCursorAttachment_x                                   0xE0F1C8
#define pinstCDynamicZoneWnd_x                                     0xF7C8E0
#define pinstCEditLabelWnd_x                                       0xE0F564
#define pinstCEQMainWnd_x                                          0xF7CB28
#define pinstCEventCalendarWnd_x                                   0xE0F240
#define pinstCExtendedTargetWnd_x                                  0xE0F184
#define pinstCFacePick_x                                           0xE0F4E8
#define pinstCFactionWnd_x                                         0xE0F4F8
#define pinstCFellowshipWnd_x                                      0xF7CD28
#define pinstCFileSelectionWnd_x                                   0xE0F22C
#define pinstCFindItemWnd_x                                        0xE0F4E0
#define pinstCFindLocationWnd_x                                    0xF7CE80
#define pinstCFriendsWnd_x                                         0xE0F4DC
#define pinstCGemsGameWnd_x                                        0xE0F4F4
#define pinstCGiveWnd_x                                            0xE0F534
#define pinstCGroupSearchFiltersWnd_x                              0xE0F1DC
#define pinstCGroupSearchWnd_x                                     0xF7D278
#define pinstCGroupWnd_x                                           0xF7D328
#define pinstCGuildBankWnd_x                                       0xECA21C
#define pinstCGuildCreationWnd_x                                   0xF7D488
#define pinstCGuildMgmtWnd_x                                       0xF7D538
#define pinstCharacterCreation_x                                   0xE0F4D4
#define pinstCHelpWnd_x                                            0xE0F528
#define pinstCHeritageSelectionWnd_x                               0xE0F4FC
#define pinstCHotButtonWnd_x                                       0xF7F690
#define pinstCHotButtonWnd1_x                                      0xF7F690
#define pinstCHotButtonWnd2_x                                      0xF7F694
#define pinstCHotButtonWnd3_x                                      0xF7F698
#define pinstCHotButtonWnd4_x                                      0xF7F69C
#define pinstCIconSelectionWnd_x                                   0xE0F1C4
#define pinstCInspectWnd_x                                         0xE0F18C
#define pinstCInventoryWnd_x                                       0xE0F168
#define pinstCInvSlotMgr_x                                         0xE0F478
#define pinstCItemDisplayManager_x                                 0xF7FC20
#define pinstCItemExpTransferWnd_x                                 0xF7FD50
#define pinstCItemOverflowWnd_x                                    0xE0F474
#define pinstCJournalCatWnd_x                                      0xE0F250
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE0F20C
#define pinstCKeyRingWnd_x                                         0xE0F1D4
#define pinstCLargeDialogWnd_x                                     0xF81E98
#define pinstCLayoutCopyWnd_x                                      0xF800A0
#define pinstCLFGuildWnd_x                                         0xF80150
#define pinstCLoadskinWnd_x                                        0xE0F508
#define pinstCLootFiltersCopyWnd_x                                 0xCE03A0
#define pinstCLootFiltersWnd_x                                     0xE0F568
#define pinstCLootSettingsWnd_x                                    0xE0F160
#define pinstCLootWnd_x                                            0xE0F254
#define pinstCMailAddressBookWnd_x                                 0xE0F480
#define pinstCMailCompositionWnd_x                                 0xE0F460
#define pinstCMailIgnoreListWnd_x                                  0xE0F484
#define pinstCMailWnd_x                                            0xE0F23C
#define pinstCManageLootWnd_x                                      0xE10858
#define pinstCMapToolbarWnd_x                                      0xE0F530
#define pinstCMapViewWnd_x                                         0xE0F500
#define pinstCMarketplaceWnd_x                                     0xE0F56C
#define pinstCMerchantWnd_x                                        0xE0F45C
#define pinstCMIZoneSelectWnd_x                                    0xF80988
#define pinstCMusicPlayerWnd_x                                     0xE0F204
#define pinstCNameChangeMercWnd_x                                  0xE0F4EC
#define pinstCNameChangePetWnd_x                                   0xE0F4D8
#define pinstCNameChangeWnd_x                                      0xE0F514
#define pinstCNoteWnd_x                                            0xE0F518
#define pinstCObjectPreviewWnd_x                                   0xE0F9F8
#define pinstCOptionsWnd_x                                         0xE0F524
#define pinstCPetInfoWnd_x                                         0xE0F214
#define pinstCPetitionQWnd_x                                       0xE0F4B8
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE0F4A0
#define pinstCPlayerWnd_x                                          0xE0F228
#define pinstCPopupWndManager_x                                    0xF81218
#define pinstCProgressionSelectionWnd_x                            0xF812C8
#define pinstCPurchaseGroupWnd_x                                   0xE0F1B8
#define pinstCPurchaseWnd_x                                        0xE0F180
#define pinstCPvPLeaderboardWnd_x                                  0xF81378
#define pinstCPvPStatsWnd_x                                        0xF81428
#define pinstCQuantityWnd_x                                        0xE0F210
#define pinstCRaceChangeWnd_x                                      0xE0F558
#define pinstCRaidOptionsWnd_x                                     0xE0F1E8
#define pinstCRaidWnd_x                                            0xE0F458
#define pinstCRealEstateItemsWnd_x                                 0xE0F4C8
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE0F46C
#define pinstCRealEstateManageWnd_x                                0xE0F1CC
#define pinstCRealEstateNeighborhoodWnd_x                          0xE0F1F4
#define pinstCRealEstatePlotSearchWnd_x                            0xE0F208
#define pinstCRealEstatePurchaseWnd_x                              0xE0F224
#define pinstCRespawnWnd_x                                         0xE0F17C
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE0F4C4
#define pinstCSendMoneyWnd_x                                       0xE0F55C
#define pinstCServerListWnd_x                                      0xE0F238
#define pinstCSkillsSelectWnd_x                                    0xE0F4AC
#define pinstCSkillsWnd_x                                          0xE0F494
#define pinstCSocialEditWnd_x                                      0xE0F1D0
#define pinstCSocialWnd_x                                          0xE0F4E4
#define pinstCSpellBookWnd_x                                       0xE0F51C
#define pinstCStoryWnd_x                                           0xE0F488
#define pinstCTargetOfTargetWnd_x                                  0xF83250
#define pinstCTargetWnd_x                                          0xE0F178
#define pinstCTaskOverlayWnd_x                                     0xE0F1B4
#define pinstCTaskSelectWnd_x                                      0xF833A8
#define pinstCTaskManager_x                                        0xCE0CE0
#define pinstCTaskTemplateSelectWnd_x                              0xF83458
#define pinstCTaskWnd_x                                            0xF83508
#define pinstCTextEntryWnd_x                                       0xE0F1E0
#define pinstCTimeLeftWnd_x                                        0xE0F49C
#define pinstCTipWndCONTEXT_x                                      0xF8370C
#define pinstCTipWndOFDAY_x                                        0xF83708
#define pinstCTitleWnd_x                                           0xF837B8
#define pinstCTrackingWnd_x                                        0xE0F170
#define pinstCTradeskillWnd_x                                      0xF83920
#define pinstCTradeWnd_x                                           0xE0F4A4
#define pinstCTrainWnd_x                                           0xE0F248
#define pinstCTributeBenefitWnd_x                                  0xF83B20
#define pinstCTributeMasterWnd_x                                   0xF83BD0
#define pinstCTributeTrophyWnd_x                                   0xF83C80
#define pinstCVideoModesWnd_x                                      0xE0F244
#define pinstCVoiceMacroWnd_x                                      0xF6CF50
#define pinstCVoteResultsWnd_x                                     0xE0F4BC
#define pinstCVoteWnd_x                                            0xE0F4A8
#define pinstCWebManager_x                                         0xF6D5CC
#define pinstCZoneGuideWnd_x                                       0xE0F1BC
#define pinstCZonePathWnd_x                                        0xE0F1E4

#define pinstEQSuiteTextureLoader_x                                0xCAE130
#define pinstItemIconCache_x                                       0xF7CAE0
#define pinstLootFiltersManager_x                                  0xCE0450
#define pinstRewardSelectionWnd_x                                  0xF81B70

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5BC0F0
#define __CastRay2_x                                               0x5BC140
#define __ConvertItemTags_x                                        0x5D7CA0
#define __CleanItemTags_x                                          0x47D200
#define __DoesFileExist_x                                          0x9115A0
#define __EQGetTime_x                                              0x90DFE0
#define __ExecuteCmd_x                                             0x5B4920
#define __FixHeading_x                                             0x9A8BF0
#define __GameLoop_x                                               0x6C8E60
#define __get_bearing_x                                            0x5BBC60
#define __get_melee_range_x                                        0x5BC330
#define __GetAnimationCache_x                                      0x72E250
#define __GetGaugeValueFromEQ_x                                    0x81FCE0
#define __GetLabelFromEQ_x                                         0x8217C0
#define __GetXTargetType_x                                         0x9AA640
#define __HandleMouseWheel_x                                       0x6C9D40
#define __HeadingDiff_x                                            0x9A8C60
#define __HelpPath_x                                               0xF682D4
#define __LoadFrontEnd_x                                           0x6C6180
#define __NewUIINI_x                                               0x81F9B0
#define __ProcessGameEvents_x                                      0x61CA60
#define __ProcessMouseEvent_x                                      0x61C220
#define __SaveColors_x                                             0x559410
#define __STMLToText_x                                             0x94C000
#define __ToggleKeyRingItem_x                                      0x51A070
#define CMemoryMappedFile__SetFile_x                               0xA97EF0
#define CrashDetected_x                                            0x6C7C20
#define DrawNetStatus_x                                            0x6488D0
#define Expansion_HoT_x                                            0xECA224
#define Teleport_Table_Size_x                                      0xEC3CBC
#define Teleport_Table_x                                           0xEC1878
#define Util__FastTime_x                                           0x90DBB0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4903E0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4992F0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4990C0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493980
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492DD0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x5611A0
#define AltAdvManager__IsAbilityReady_x                            0x55FF40
#define AltAdvManager__GetAAById_x                                 0x5602D0
#define AltAdvManager__CanTrainAbility_x                           0x560340
#define AltAdvManager__CanSeeAbility_x                             0x5606A0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C9CA0
#define CharacterZoneClient__HasSkill_x                            0x4D4B20
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6240
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE4B0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BAAE0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8BA0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D8C80
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D8D60
#define CharacterZoneClient__FindAffectSlot_x                      0x4C2BB0
#define CharacterZoneClient__BardCastBard_x                        0x4C5710
#define CharacterZoneClient__GetMaxEffects_x                       0x4BABB0
#define CharacterZoneClient__GetEffect_x                           0x4BAA20
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C3C00
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C3CD0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C3D20
#define CharacterZoneClient__CalcAffectChange_x                    0x4C3E70
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4040
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2930
#define CharacterZoneClient__FindItemByGuid_x                      0x4D71A0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D6C20

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6EF930
#define CBankWnd__WndNotification_x                                0x6EF710

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6FD330

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x62B1A0
#define CButtonWnd__CButtonWnd_x                                   0x9483D0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x71D240
#define CChatManager__InitContextMenu_x                            0x716370
#define CChatManager__FreeChatWindow_x                             0x71BD80
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8140
#define CChatManager__SetLockedActiveChatWindow_x                  0x71CEC0
#define CChatManager__CreateChatWindow_x                           0x71C3C0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8250

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x95CA80
#define CContextMenu__dCContextMenu_x                              0x95CCB0
#define CContextMenu__AddMenuItem_x                                0x95CCC0
#define CContextMenu__RemoveMenuItem_x                             0x95CFD0
#define CContextMenu__RemoveAllMenuItems_x                         0x95CFF0
#define CContextMenu__CheckMenuItem_x                              0x95D070
#define CContextMenu__SetMenuItem_x                                0x95CEF0
#define CContextMenu__AddSeparator_x                               0x95CE50

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x95D600
#define CContextMenuManager__RemoveMenu_x                          0x95D670
#define CContextMenuManager__PopupMenu_x                           0x95D730
#define CContextMenuManager__Flush_x                               0x95D5A0
#define CContextMenuManager__GetMenu_x                             0x49B490
#define CContextMenuManager__CreateDefaultMenu_x                   0x728A60

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8E9210
#define CChatService__GetFriendName_x                              0x8E9220

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x71DAB0
#define CChatWindow__Clear_x                                       0x71ED80
#define CChatWindow__WndNotification_x                             0x71F510
#define CChatWindow__AddHistory_x                                  0x71E640

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x959ED0
#define CComboWnd__Draw_x                                          0x9593C0
#define CComboWnd__GetCurChoice_x                                  0x959D10
#define CComboWnd__GetListRect_x                                   0x959870
#define CComboWnd__GetTextRect_x                                   0x959F40
#define CComboWnd__InsertChoice_x                                  0x959A00
#define CComboWnd__SetColors_x                                     0x9599D0
#define CComboWnd__SetChoice_x                                     0x959CE0
#define CComboWnd__GetItemCount_x                                  0x959D20
#define CComboWnd__GetCurChoiceText_x                              0x959D60
#define CComboWnd__GetChoiceText_x                                 0x959D30
#define CComboWnd__InsertChoiceAtIndex_x                           0x959AA0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x726450
#define CContainerWnd__vftable_x                                   0xB1FEC4
#define CContainerWnd__SetContainer_x                              0x7279B0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x553DE0
#define CDisplay__PreZoneMainUI_x                                  0x553DF0
#define CDisplay__CleanGameUI_x                                    0x5591D0
#define CDisplay__GetClickedActor_x                                0x54C0E0
#define CDisplay__GetUserDefinedColor_x                            0x544740
#define CDisplay__GetWorldFilePath_x                               0x54DB50
#define CDisplay__is3dON_x                                         0x548D40
#define CDisplay__ReloadUI_x                                       0x553260
#define CDisplay__WriteTextHD2_x                                   0x548B30
#define CDisplay__TrueDistance_x                                   0x54F810
#define CDisplay__SetViewActor_x                                   0x54BA00
#define CDisplay__GetFloorHeight_x                                 0x548E00
#define CDisplay__SetRenderWindow_x                                0x547760
#define CDisplay__ToggleScreenshotMode_x                           0x54B4D0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x97C7F0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x95FFD0
#define CEditWnd__EnsureCaretVisible_x                             0x962160
#define CEditWnd__GetCaretPt_x                                     0x961140
#define CEditWnd__GetCharIndexPt_x                                 0x960EF0
#define CEditWnd__GetDisplayString_x                               0x960DA0
#define CEditWnd__GetHorzOffset_x                                  0x95F610
#define CEditWnd__GetLineForPrintableChar_x                        0x962060
#define CEditWnd__GetSelStartPt_x                                  0x9611A0
#define CEditWnd__GetSTMLSafeText_x                                0x960BC0
#define CEditWnd__PointFromPrintableChar_x                         0x961CA0
#define CEditWnd__SelectableCharFromPoint_x                        0x961E10
#define CEditWnd__SetEditable_x                                    0x961260
#define CEditWnd__SetWindowTextA_x                                 0x960940
#define CEditWnd__ReplaceSelection_x                               0x961920
#define CEditWnd__ReplaceSelection1_x                              0x9618A0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x60A690
#define CEverQuest__ClickedPlayer_x                                0x5FC7C0
#define CEverQuest__CreateTargetIndicator_x                        0x619CF0
#define CEverQuest__DeleteTargetIndicator_x                        0x619D80
#define CEverQuest__DoTellWindow_x                                 0x4E8330
#define CEverQuest__OutputTextToLog_x                              0x4E8600
#define CEverQuest__DropHeldItemOnGround_x                         0x5F1800
#define CEverQuest__dsp_chat_x                                     0x4E8990
#define CEverQuest__trimName_x                                     0x615EF0
#define CEverQuest__Emote_x                                        0x60AEF0
#define CEverQuest__EnterZone_x                                    0x604F90
#define CEverQuest__GetBodyTypeDesc_x                              0x60F7B0
#define CEverQuest__GetClassDesc_x                                 0x60FDF0
#define CEverQuest__GetClassThreeLetterCode_x                      0x6103F0
#define CEverQuest__GetDeityDesc_x                                 0x618540
#define CEverQuest__GetLangDesc_x                                  0x6105B0
#define CEverQuest__GetRaceDesc_x                                  0x60FDD0
#define CEverQuest__InterpretCmd_x                                 0x618B10
#define CEverQuest__LeftClickedOnPlayer_x                          0x5F5A00
#define CEverQuest__LMouseUp_x                                     0x5F3D90
#define CEverQuest__RightClickedOnPlayer_x                         0x5F62E0
#define CEverQuest__RMouseUp_x                                     0x5F4D10
#define CEverQuest__SetGameState_x                                 0x5F1590
#define CEverQuest__UPCNotificationFlush_x                         0x615DF0
#define CEverQuest__IssuePetCommand_x                              0x6119B0
#define CEverQuest__ReportSuccessfulHit_x                          0x60C240

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7383E0
#define CGaugeWnd__CalcLinesFillRect_x                             0x738440
#define CGaugeWnd__Draw_x                                          0x737A60

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF3D0
#define CGuild__GetGuildName_x                                     0x4AE400
#define CGuild__GetGuildIndex_x                                    0x4AE840

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x7525E0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x62B560

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x75F640
#define CInvSlotMgr__MoveItem_x                                    0x75E360
#define CInvSlotMgr__SelectSlot_x                                  0x75F710

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x75CBA0
#define CInvSlot__SliderComplete_x                                 0x75A900
#define CInvSlot__GetItemBase_x                                    0x75A270
#define CInvSlot__UpdateItem_x                                     0x75A3E0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7611A0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x760330
#define CInvSlotWnd__HandleLButtonUp_x                             0x760D20

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x81B040
#define CItemDisplayWnd__UpdateStrings_x                           0x76F940
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x769610
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x769B20
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x76FF40
#define CItemDisplayWnd__AboutToShow_x                             0x76F580
#define CItemDisplayWnd__WndNotification_x                         0x771030
#define CItemDisplayWnd__RequestConvertItem_x                      0x770AF0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x76E5F0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x76F3A0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x853B50

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x775530

// CLabel 
#define CLabel__Draw_x                                             0x77AF70

// CListWnd
#define CListWnd__CListWnd_x                                       0x932530
#define CListWnd__dCListWnd_x                                      0x932850
#define CListWnd__AddColumn_x                                      0x936CE0
#define CListWnd__AddColumn1_x                                     0x936D30
#define CListWnd__AddLine_x                                        0x9370C0
#define CListWnd__AddString_x                                      0x936EC0
#define CListWnd__CalculateFirstVisibleLine_x                      0x936AA0
#define CListWnd__CalculateVSBRange_x                              0x936880
#define CListWnd__ClearSel_x                                       0x9378A0
#define CListWnd__ClearAllSel_x                                    0x937900
#define CListWnd__CloseAndUpdateEditWindow_x                       0x938320
#define CListWnd__Compare_x                                        0x9361B0
#define CListWnd__Draw_x                                           0x932980
#define CListWnd__DrawColumnSeparators_x                           0x935180
#define CListWnd__DrawHeader_x                                     0x9355F0
#define CListWnd__DrawItem_x                                       0x935AF0
#define CListWnd__DrawLine_x                                       0x9352F0
#define CListWnd__DrawSeparator_x                                  0x935220
#define CListWnd__EnableLine_x                                     0x934A50
#define CListWnd__EnsureVisible_x                                  0x938240
#define CListWnd__ExtendSel_x                                      0x9377D0
#define CListWnd__GetColumnTooltip_x                               0x934590
#define CListWnd__GetColumnMinWidth_x                              0x934600
#define CListWnd__GetColumnWidth_x                                 0x934500
#define CListWnd__GetCurSel_x                                      0x933E90
#define CListWnd__GetItemAtPoint_x                                 0x934CD0
#define CListWnd__GetItemAtPoint1_x                                0x934D40
#define CListWnd__GetItemData_x                                    0x933F10
#define CListWnd__GetItemHeight_x                                  0x9342D0
#define CListWnd__GetItemIcon_x                                    0x9340A0
#define CListWnd__GetItemRect_x                                    0x934B40
#define CListWnd__GetItemText_x                                    0x933F50
#define CListWnd__GetSelList_x                                     0x937950
#define CListWnd__GetSeparatorRect_x                               0x934F80
#define CListWnd__InsertLine_x                                     0x9374B0
#define CListWnd__RemoveLine_x                                     0x937600
#define CListWnd__SetColors_x                                      0x936850
#define CListWnd__SetColumnJustification_x                         0x936580
#define CListWnd__SetColumnLabel_x                                 0x936E60
#define CListWnd__SetColumnWidth_x                                 0x9364A0
#define CListWnd__SetCurSel_x                                      0x937710
#define CListWnd__SetItemColor_x                                   0x937EF0
#define CListWnd__SetItemData_x                                    0x937EB0
#define CListWnd__SetItemText_x                                    0x937AC0
#define CListWnd__ShiftColumnSeparator_x                           0x936640
#define CListWnd__Sort_x                                           0x936330
#define CListWnd__ToggleSel_x                                      0x937740
#define CListWnd__SetColumnsSizable_x                              0x9366F0
#define CListWnd__SetItemWnd_x                                     0x937D70
#define CListWnd__GetItemWnd_x                                     0x9340F0
#define CListWnd__SetItemIcon_x                                    0x937B40
#define CListWnd__CalculateCustomWindowPositions_x                 0x936BA0
#define CListWnd__SetVScrollPos_x                                  0x936480

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7906B0
#define CMapViewWnd__GetWorldCoordinates_x                         0x78EDC0
#define CMapViewWnd__HandleLButtonDown_x                           0x78BE00

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7B07A0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7B1080
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7B15B0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7B4520
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7AF310
#define CMerchantWnd__SelectBuySellSlot_x                          0x7BA0C0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7B03B0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8B6F50
#define CPacketScrambler__hton_x                                   0x8B6F40

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x951650
#define CSidlManager__FindScreenPieceTemplate_x                    0x951A60
#define CSidlManager__FindScreenPieceTemplate1_x                   0x951850
#define CSidlManager__CreateLabel_x                                0x812250
#define CSidlManager__CreateXWndFromTemplate_x                     0x9549C0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x954BA0
#define CSidlManager__CreateXWnd_x                                 0x812180
#define CSidlManager__CreateHotButtonWnd_x                         0x812750

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x94E130
#define CSidlScreenWnd__CalculateVSBRange_x                        0x94E030
#define CSidlScreenWnd__ConvertToRes_x                             0x977290
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x94DAC0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x94D7B0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x94D880
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x94D950
#define CSidlScreenWnd__DrawSidlPiece_x                            0x94E5D0
#define CSidlScreenWnd__EnableIniStorage_x                         0x94EAA0
#define CSidlScreenWnd__GetSidlPiece_x                             0x94E7C0
#define CSidlScreenWnd__Init1_x                                    0x94D3B0
#define CSidlScreenWnd__LoadIniInfo_x                              0x94EAF0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x94F630
#define CSidlScreenWnd__LoadSidlScreen_x                           0x94C7B0
#define CSidlScreenWnd__StoreIniInfo_x                             0x94F1B0
#define CSidlScreenWnd__StoreIniVis_x                              0x94F510
#define CSidlScreenWnd__WndNotification_x                          0x94E4E0
#define CSidlScreenWnd__GetChildItem_x                             0x94EA20
#define CSidlScreenWnd__HandleLButtonUp_x                          0x93E100
#define CSidlScreenWnd__m_layoutCopy_x                             0x15FEA98

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6902C0
#define CSkillMgr__GetSkillCap_x                                   0x6904A0
#define CSkillMgr__GetNameToken_x                                  0x68FA40
#define CSkillMgr__IsActivatedSkill_x                              0x68FB80
#define CSkillMgr__IsCombatSkill_x                                 0x68FAC0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x95E3F0
#define CSliderWnd__SetValue_x                                     0x95E260
#define CSliderWnd__SetNumTicks_x                                  0x95E2C0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x818410

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x966BE0
#define CStmlWnd__ParseSTML_x                                      0x967F30
#define CStmlWnd__CalculateHSBRange_x                              0x967D00
#define CStmlWnd__CalculateVSBRange_x                              0x967C80
#define CStmlWnd__CanBreakAtCharacter_x                            0x96C040
#define CStmlWnd__FastForwardToEndOfTag_x                          0x96CCD0
#define CStmlWnd__ForceParseNow_x                                  0x9671D0
#define CStmlWnd__GetNextTagPiece_x                                0x96BFA0
#define CStmlWnd__GetSTMLText_x                                    0x509A60
#define CStmlWnd__GetVisibleText_x                                 0x9671F0
#define CStmlWnd__InitializeWindowVariables_x                      0x96CB20
#define CStmlWnd__MakeStmlColorTag_x                               0x966250
#define CStmlWnd__MakeWndNotificationTag_x                         0x9662C0
#define CStmlWnd__SetSTMLText_x                                    0x965300
#define CStmlWnd__StripFirstSTMLLines_x                            0x96DDD0
#define CStmlWnd__UpdateHistoryString_x                            0x96CEE0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x964430
#define CTabWnd__DrawCurrentPage_x                                 0x964B60
#define CTabWnd__DrawTab_x                                         0x964880
#define CTabWnd__GetCurrentPage_x                                  0x963C30
#define CTabWnd__GetPageInnerRect_x                                0x963E70
#define CTabWnd__GetTabInnerRect_x                                 0x963DB0
#define CTabWnd__GetTabRect_x                                      0x963C60
#define CTabWnd__InsertPage_x                                      0x964080
#define CTabWnd__SetPage_x                                         0x963EF0
#define CTabWnd__SetPageRect_x                                     0x964370
#define CTabWnd__UpdatePage_x                                      0x964740
#define CTabWnd__GetPageFromTabIndex_x                             0x9647C0
#define CTabWnd__GetCurrentTabIndex_x                              0x963C20

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x775900
#define CPageWnd__SetTabText_x                                     0x963770

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8F30

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x93AFE0
#define CTextureFont__GetTextExtent_x                              0x93B1A0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6C3010
#define CHtmlComponentWnd__ValidateUri_x                           0x753FD0
#define CHtmlWnd__SetClientCallbacks_x                             0x6305F0
#define CHtmlWnd__AddObserver_x                                    0x630610
#define CHtmlWnd__RemoveObserver_x                                 0x630670
#define Window__getProgress_x                                      0x86C440
#define Window__getStatus_x                                        0x86C460
#define Window__getURI_x                                           0x86C470

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9740A0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x928180

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E7F80
#define CXStr__CXStr1_x                                            0x504BD0
#define CXStr__CXStr3_x                                            0x90A180
#define CXStr__dCXStr_x                                            0x478790
#define CXStr__operator_equal_x                                    0x90A3B0
#define CXStr__operator_equal1_x                                   0x90A3F0
#define CXStr__operator_plus_equal1_x                              0x90AE80
#define CXStr__SetString_x                                         0x90CD70
#define CXStr__operator_char_p_x                                   0x90A8C0
#define CXStr__GetChar_x                                           0x90C6A0
#define CXStr__Delete_x                                            0x90BF70
#define CXStr__GetUnicode_x                                        0x90C710
#define CXStr__GetLength_x                                         0x4A8CE0
#define CXStr__Mid_x                                               0x47D5B0
#define CXStr__Insert_x                                            0x90C770
#define CXStr__FindNext_x                                          0x90C3E0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x95C690
#define CXWnd__BringToTop_x                                        0x9418D0
#define CXWnd__Center_x                                            0x941450
#define CXWnd__ClrFocus_x                                          0x941270
#define CXWnd__Destroy_x                                           0x941310
#define CXWnd__DoAllDrawing_x                                      0x93D890
#define CXWnd__DrawChildren_x                                      0x93D860
#define CXWnd__DrawColoredRect_x                                   0x93DCF0
#define CXWnd__DrawTooltip_x                                       0x93C3E0
#define CXWnd__DrawTooltipAtPoint_x                                0x93C4A0
#define CXWnd__GetBorderFrame_x                                    0x93DB50
#define CXWnd__GetChildWndAt_x                                     0x941970
#define CXWnd__GetClientClipRect_x                                 0x93FB10
#define CXWnd__GetScreenClipRect_x                                 0x93FBE0
#define CXWnd__GetScreenRect_x                                     0x93FDB0
#define CXWnd__GetRelativeRect_x                                   0x93FE80
#define CXWnd__GetTooltipRect_x                                    0x93DD40
#define CXWnd__GetWindowTextA_x                                    0x49CBB0
#define CXWnd__IsActive_x                                          0x93E470
#define CXWnd__IsDescendantOf_x                                    0x9407C0
#define CXWnd__IsReallyVisible_x                                   0x9407F0
#define CXWnd__IsType_x                                            0x941FF0
#define CXWnd__Move_x                                              0x940860
#define CXWnd__Move1_x                                             0x940910
#define CXWnd__ProcessTransition_x                                 0x941400
#define CXWnd__Refade_x                                            0x940BF0
#define CXWnd__Resize_x                                            0x940E80
#define CXWnd__Right_x                                             0x941690
#define CXWnd__SetFocus_x                                          0x941230
#define CXWnd__SetFont_x                                           0x9412A0
#define CXWnd__SetKeyTooltip_x                                     0x941E00
#define CXWnd__SetMouseOver_x                                      0x93ECA0
#define CXWnd__StartFade_x                                         0x9406A0
#define CXWnd__GetChildItem_x                                      0x941AE0
#define CXWnd__SetParent_x                                         0x940560
#define CXWnd__Minimize_x                                          0x940EF0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x978310

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x944830
#define CXWndManager__DrawWindows_x                                0x944850
#define CXWndManager__GetKeyboardFlags_x                           0x947040
#define CXWndManager__HandleKeyboardMsg_x                          0x946BF0
#define CXWndManager__RemoveWnd_x                                  0x947270
#define CXWndManager__RemovePendingDeletionWnd_x                   0x9477F0

// CDBStr
#define CDBStr__GetString_x                                        0x5436E0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BBAC0
#define EQ_Character__Cur_HP_x                                     0x4D1B60
#define EQ_Character__Cur_Mana_x                                   0x4D9260
#define EQ_Character__GetCastingTimeModifier_x                     0x4BEB00
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2570
#define EQ_Character__GetFocusRangeModifier_x                      0x4B26C0
#define EQ_Character__GetHPRegen_x                                 0x4DF000
#define EQ_Character__GetEnduranceRegen_x                          0x4DF600
#define EQ_Character__GetManaRegen_x                               0x4DFA40
#define EQ_Character__Max_Endurance_x                              0x6569B0
#define EQ_Character__Max_HP_x                                     0x4D1990
#define EQ_Character__Max_Mana_x                                   0x6567B0
#define EQ_Character__doCombatAbility_x                            0x658E00
#define EQ_Character__UseSkill_x                                   0x4E1810
#define EQ_Character__GetConLevel_x                                0x64F810
#define EQ_Character__IsExpansionFlag_x                            0x5B30D0
#define EQ_Character__TotalEffect_x                                0x4C4E50
#define EQ_Character__GetPCSpellAffect_x                           0x4BF850
#define EQ_Character__SpellDuration_x                              0x4BF380
#define EQ_Character__GetAdjustedSkill_x                           0x4D48E0
#define EQ_Character__GetBaseSkill_x                               0x4D5880
#define EQ_Character__CanUseItem_x                                 0x4D9570

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8D6100

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x66D340

//PcClient
#define PcClient__PcClient_x                                       0x64CF60

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B9730
#define CCharacterListWnd__EnterWorld_x                            0x4B9170
#define CCharacterListWnd__Quit_x                                  0x4B8EC0
#define CCharacterListWnd__UpdateList_x                            0x4B9300

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6317A0
#define EQ_Item__CreateItemTagString_x                             0x8B0520
#define EQ_Item__IsStackable_x                                     0x8B51A0
#define EQ_Item__GetImageNum_x                                     0x8B1FA0
#define EQ_Item__CreateItemClient_x                                0x6309F0
#define EQ_Item__GetItemValue_x                                    0x8B3380
#define EQ_Item__ValueSellMerchant_x                               0x8B6B20
#define EQ_Item__IsKeyRingItem_x                                   0x8B4AA0
#define EQ_Item__CanGoInBag_x                                      0x6318C0
#define EQ_Item__IsEmpty_x                                         0x8B4610
#define EQ_Item__GetMaxItemCount_x                                 0x8B37A0
#define EQ_Item__GetHeldItem_x                                     0x8B1E70
#define EQ_Item__GetAugmentFitBySlot_x                             0x8AFE40

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x561EC0
#define EQ_LoadingS__Array_x                                       0xC35B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x657310
#define EQ_PC__GetAlternateAbilityId_x                             0x8BFD80
#define EQ_PC__GetCombatAbility_x                                  0x8C03F0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8C0460
#define EQ_PC__GetItemRecastTimer_x                                0x659380
#define EQ_PC__HasLoreItem_x                                       0x650020
#define EQ_PC__AlertInventoryChanged_x                             0x64F150
#define EQ_PC__GetPcZoneClient_x                                   0x67BDD0
#define EQ_PC__RemoveMyAffect_x                                    0x65C5B0
#define EQ_PC__GetKeyRingItems_x                                   0x8C0CF0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8C0A80
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8C0FF0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5B9650
#define EQItemList__add_object_x                                   0x5E6F20
#define EQItemList__add_item_x                                     0x5B9BB0
#define EQItemList__delete_item_x                                  0x5B9C00
#define EQItemList__FreeItemList_x                                 0x5B9B00

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x540270

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x66EBC0
#define EQPlayer__dEQPlayer_x                                      0x661AD0
#define EQPlayer__DoAttack_x                                       0x676A70
#define EQPlayer__EQPlayer_x                                       0x662190
#define EQPlayer__SetNameSpriteState_x                             0x6668A0
#define EQPlayer__SetNameSpriteTint_x                              0x667770
#define PlayerBase__HasProperty_j_x                                0x9A7000
#define EQPlayer__IsTargetable_x                                   0x9A74A0
#define EQPlayer__CanSee_x                                         0x9A7300
#define EQPlayer__CanSee1_x                                        0x9A73D0
#define PlayerBase__GetVisibilityLineSegment_x                     0x9A70C0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x679870
#define PlayerZoneClient__GetLevel_x                               0x67BE10
#define PlayerZoneClient__IsValidTeleport_x                        0x5E8090
#define PlayerZoneClient__LegalPlayerRace_x                        0x55B060

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x671970
#define EQPlayerManager__GetSpawnByName_x                          0x671A20
#define EQPlayerManager__GetPlayerFromPartialName_x                0x671AB0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x634E00
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x634E80
#define KeypressHandler__AttachKeyToEqCommand_x                    0x634EC0
#define KeypressHandler__ClearCommandStateArray_x                  0x6362D0
#define KeypressHandler__HandleKeyDown_x                           0x6362F0
#define KeypressHandler__HandleKeyUp_x                             0x636390
#define KeypressHandler__SaveKeymapping_x                          0x6367E0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x78C520
#define MapViewMap__SaveEx_x                                       0x78F8E0
#define MapViewMap__SetZoom_x                                      0x793FA0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8D4200

// StringTable 
#define StringTable__getString_x                                   0x8CF000

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x65C220
#define PcZoneClient__RemovePetEffect_x                            0x65C850
#define PcZoneClient__HasAlternateAbility_x                        0x6565E0
#define PcZoneClient__GetCurrentMod_x                              0x4E48D0
#define PcZoneClient__GetModCap_x                                  0x4E47D0
#define PcZoneClient__CanEquipItem_x                               0x656CB0
#define PcZoneClient__GetItemByID_x                                0x6597F0
#define PcZoneClient__GetItemByItemClass_x                         0x659940
#define PcZoneClient__RemoveBuffEffect_x                           0x65C870
#define PcZoneClient__BandolierSwap_x                              0x6578C0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x659320

//Doors
#define EQSwitch__UseSwitch_x                                      0x5ECC60

//IconCache
#define IconCache__GetIcon_x                                       0x72DAF0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x7255F0
#define CContainerMgr__CloseContainer_x                            0x7258C0
#define CContainerMgr__OpenExperimentContainer_x                   0x726340

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7E4670

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x629980

//CLootWnd
#define CLootWnd__LootAll_x                                        0x782A40
#define CLootWnd__RequestLootSlot_x                                0x781C70

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x586980
#define EQ_Spell__SpellAffects_x                                   0x586DF0
#define EQ_Spell__SpellAffectBase_x                                0x586BB0
#define EQ_Spell__IsStackable_x                                    0x4C95A0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C93F0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6A80
#define EQ_Spell__IsSPAStacking_x                                  0x587C40
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x587150
#define EQ_Spell__IsNoRemove_x                                     0x4C9580
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x587C50
#define __IsResEffectSpell_x                                       0x4C8890

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4ACF60

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8DE790

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x82B850
#define CTargetWnd__WndNotification_x                              0x82B090
#define CTargetWnd__RefreshTargetBuffs_x                           0x82B360
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x82A210

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x82FE70

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x53DCB0
#define CTaskManager__HandleMessage_x                              0x53C150
#define CTaskManager__GetTaskStatus_x                              0x53DD60
#define CTaskManager__GetElementDescription_x                      0x53DDE0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x581B40
#define EqSoundManager__PlayScriptMp3_x                            0x581E00
#define EqSoundManager__SoundAssistPlay_x                          0x694230
#define EqSoundManager__WaveInstancePlay_x                         0x6937A0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52F460

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x962C80

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x569940
#define CAltAbilityData__GetMercMaxRank_x                          0x5698D0
#define CAltAbilityData__GetMaxRank_x                              0x55EDC0

//CTargetRing
#define CTargetRing__Cast_x                                        0x627AA0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C93D0
#define CharacterBase__CreateItemGlobalIndex_x                     0x5166F0
#define CharacterBase__CreateItemIndex_x                           0x62FB90
#define CharacterBase__GetItemPossession_x                         0x502410
#define CharacterBase__GetItemByGlobalIndex_x                      0x8E6DC0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8E6E20
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x70C600
#define CCastSpellWnd__IsBardSongPlaying_x                         0x70CE30
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x70CEE0

//messages
#define msg_spell_worn_off_x                                       0x5AB260
#define msg_new_text_x                                             0x59FFF0
#define __msgTokenTextParam_x                                      0x5AD790
#define msgTokenText_x                                             0x5AD9E0

//SpellManager
#define SpellManager__vftable_x                                    0xAF97D8
#define SpellManager__SpellManager_x                               0x697560
#define Spellmanager__LoadTextSpells_x                             0x697E50
#define SpellManager__GetSpellByGroupAndRank_x                     0x697730

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9AAF30

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x516D40
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B1560
#define ItemGlobalIndex__IsEquippedLocation_x                      0x648730
#define ItemGlobalIndex__IsValidIndex_x                            0x516DA0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8DF130
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8DF3B0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x77B2B0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x729D00
#define CCursorAttachment__AttachToCursor1_x                       0x729D40
#define CCursorAttachment__Deactivate_x                            0x72AD20

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x955A00
#define CSidlManagerBase__CreatePageWnd_x                          0x9551F0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x951470
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x951400

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x972DC0
#define CEQSuiteTextureLoader__GetTexture_x                        0x972A80

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x513D30
#define CFindItemWnd__WndNotification_x                            0x514810
#define CFindItemWnd__Update_x                                     0x515380
#define CFindItemWnd__PickupSelectedItem_x                         0x513580

//IString
#define IString__Append_x                                          0x4F3A30

//Camera
#define CDisplay__cameraType_x                                     0xE0F24C
#define EverQuest__Cameras_x                                       0xECA574

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51C410
#define LootFiltersManager__GetItemFilterData_x                    0x51BD10
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51BD40
#define LootFiltersManager__SetItemLootFilter_x                    0x51BF60

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7D25A0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9B0AE0
#define CResolutionHandler__GetWindowedStyle_x                     0x68ED60

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x722220

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8F45D0
#define CDistillerInfo__Instance_x                                 0x8F4570

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x7413B0
#define CGroupWnd__UpdateDisplay_x                                 0x740700

//ItemBase
#define ItemBase__IsLore_x                                         0x8B4B50
#define ItemBase__IsLoreEquipped_x                                 0x8B4BD0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5E6E80
#define EQPlacedItemManager__GetItemByGuid_x                       0x5E6FC0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5E7020

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6844E0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x687E70

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50A0A0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F66F0
#define FactionManagerClient__HandleFactionMessage_x               0x4F6D60
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F7320
#define FactionManagerClient__GetMaxFaction_x                      0x4F733F
#define FactionManagerClient__GetMinFaction_x                      0x4F72F0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x5023E0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x939F90

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BE90

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x502790

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x568DF0

//CTargetManager
#define CTargetManager__Get_x                                      0x69ADE0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6844E0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8CF0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5B9AA0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF67C08

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
