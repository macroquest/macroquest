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
#define __ExpectedVersionDate                                     "Nov  6 2019"
#define __ExpectedVersionTime                                     "11:12:52"
#define __ActualVersionDate_x                                      0xB0810C
#define __ActualVersionTime_x                                      0xB08100
#define __ActualVersionBuild_x                                     0xAF3DF4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x62D1C0
#define __MemChecker1_x                                            0x900130
#define __MemChecker2_x                                            0x6BBA80
#define __MemChecker3_x                                            0x6BB9D0
#define __MemChecker4_x                                            0x857690
#define __EncryptPad0_x                                            0xC3E3E8
#define __EncryptPad1_x                                            0xC9C5A8
#define __EncryptPad2_x                                            0xC4EC80
#define __EncryptPad3_x                                            0xC4E880
#define __EncryptPad4_x                                            0xC8CC00
#define __EncryptPad5_x                                            0xF65D54
#define __AC1_x                                                    0x814226
#define __AC2_x                                                    0x5E718F
#define __AC3_x                                                    0x5EE88F
#define __AC4_x                                                    0x5F2860
#define __AC5_x                                                    0x5F8B6F
#define __AC6_x                                                    0x5FD186
#define __AC7_x                                                    0x5E6C00
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x192168

// Direct Input
#define DI8__Main_x                                                0xF68238
#define DI8__Keyboard_x                                            0xF6823C
#define DI8__Mouse_x                                               0xF671F0
#define DI8__Mouse_Copy_x                                          0xEC141C
#define DI8__Mouse_Check_x                                         0xF65D7C
#define __AutoSkillArray_x                                         0xEC2334
#define __Attack_x                                                 0xF6015B
#define __Autofire_x                                               0xF6015C
#define __BindList_x                                               0xC2CE20
#define g_eqCommandStates_x                                        0xC2DBA0
#define __Clicks_x                                                 0xEC14D4
#define __CommandList_x                                            0xC2E760
#define __CurrentMapLabel_x                                        0xF78BDC
#define __CurrentSocial_x                                          0xC167CC
#define __DoAbilityList_x                                          0xEF7C7C
#define __do_loot_x                                                0x5B3470
#define __DrawHandler_x                                            0x15F7F50
#define __GroupCount_x                                             0xEB3DD2
#define __Guilds_x                                                 0xEB7C28
#define __gWorld_x                                                 0xEB3C88
#define __HWnd_x                                                   0xF671F8
#define __heqmain_x                                                0xF6822C
#define __InChatMode_x                                             0xEC1404
#define __LastTell_x                                               0xEC3378
#define __LMouseHeldTime_x                                         0xEC1540
#define __Mouse_x                                                  0xF68218
#define __MouseLook_x                                              0xEC149A
#define __MouseEventTime_x                                         0xF60C3C
#define __gpbCommandEvent_x                                        0xEB16C0
#define __NetStatusToggle_x                                        0xEC149D
#define __PCNames_x                                                0xEC2924
#define __RangeAttackReady_x                                       0xEC2618
#define __RMouseHeldTime_x                                         0xEC153C
#define __RunWalkState_x                                           0xEC1408
#define __ScreenMode_x                                             0xDFF090
#define __ScreenX_x                                                0xEC13BC
#define __ScreenY_x                                                0xEC13B8
#define __ScreenXMax_x                                             0xEC13C0
#define __ScreenYMax_x                                             0xEC13C4
#define __ServerHost_x                                             0xEB18F3
#define __ServerName_x                                             0xEF7C3C
#define __ShiftKeyDown_x                                           0xEC1A94
#define __ShowNames_x                                              0xEC27D4
#define __Socials_x                                                0xEF7D3C
#define __SubscriptionType_x                                       0xFBD0E0
#define __TargetAggroHolder_x                                      0xF7B590
#define __ZoneType_x                                               0xEC1898
#define __GroupAggro_x                                             0xF7B5D0
#define __LoginName_x                                              0xF6898C
#define __Inviter_x                                                0xF600D8
#define __AttackOnAssist_x                                         0xEC2790
#define __UseTellWindows_x                                         0xEC2AC0
#define __gfMaxZoomCameraDistance_x                                0xAFDA70
#define __gfMaxCameraDistance_x                                    0xB29FCC
#define __pulAutoRun_x                                             0xEC14B8
#define __pulForward_x                                             0xEC2AF8
#define __pulBackward_x                                            0xEC2AFC
#define __pulTurnRight_x                                           0xEC2B00
#define __pulTurnLeft_x                                            0xEC2B04
#define __pulStrafeLeft_x                                          0xEC2B08
#define __pulStrafeRight_x                                         0xEC2B0C

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEB3FC8
#define instEQZoneInfo_x                                           0xEC1690
#define pinstActiveBanker_x                                        0xEB16D8
#define pinstActiveCorpse_x                                        0xEB16D0
#define pinstActiveGMaster_x                                       0xEB16D4
#define pinstActiveMerchant_x                                      0xEB16CC
#define pinstAltAdvManager_x                                       0xE00200
#define pinstBandageTarget_x                                       0xEB16E8
#define pinstCamActor_x                                            0xDFF084
#define pinstCDBStr_x                                              0xDFEF1C
#define pinstCDisplay_x                                            0xEB3C84
#define pinstCEverQuest_x                                          0xF68250
#define pinstEverQuestInfo_x                                       0xEC13B0
#define pinstCharData_x                                            0xEB3DB4
#define pinstCharSpawn_x                                           0xEB17A0
#define pinstControlledMissile_x                                   0xEB1C0C
#define pinstControlledPlayer_x                                    0xEB17A0
#define pinstCResolutionHandler_x                                  0x15F8180
#define pinstCSidlManager_x                                        0x15F7118
#define pinstCXWndManager_x                                        0x15F7114
#define instDynamicZone_x                                          0xEB7B00
#define pinstDZMember_x                                            0xEB7C10
#define pinstDZTimerInfo_x                                         0xEB7C14
#define pinstEqLogin_x                                             0xF682D8
#define instEQMisc_x                                               0xDFEE60
#define pinstEQSoundManager_x                                      0xE011D0
#define pinstEQSpellStrings_x                                      0xCC18D8
#define instExpeditionLeader_x                                     0xEB7B4A
#define instExpeditionName_x                                       0xEB7B8A
#define pinstGroup_x                                               0xEB3DCE
#define pinstImeManager_x                                          0x15F7110
#define pinstLocalPlayer_x                                         0xEB16C8
#define pinstMercenaryData_x                                       0xF6272C
#define pinstMercenaryStats_x                                      0xF7B6DC
#define pinstModelPlayer_x                                         0xEB16E0
#define pinstPCData_x                                              0xEB3DB4
#define pinstSkillMgr_x                                            0xF64898
#define pinstSpawnManager_x                                        0xF63340
#define pinstSpellManager_x                                        0xF64AB8
#define pinstSpellSets_x                                           0xF58D84
#define pinstStringTable_x                                         0xEB3DB8
#define pinstSwitchManager_x                                       0xEB1568
#define pinstTarget_x                                              0xEB171C
#define pinstTargetObject_x                                        0xEB17A8
#define pinstTargetSwitch_x                                        0xEB3C38
#define pinstTaskMember_x                                          0xDFECF0
#define pinstTrackTarget_x                                         0xEB17A4
#define pinstTradeTarget_x                                         0xEB16DC
#define instTributeActive_x                                        0xDFEE81
#define pinstViewActor_x                                           0xDFF080
#define pinstWorldData_x                                           0xEB1C08
#define pinstZoneAddr_x                                            0xEC1930
#define pinstPlayerPath_x                                          0xF633D8
#define pinstTargetIndicator_x                                     0xF64D20
#define EQObject_Top_x                                             0xEB16C4
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDFF7E4
#define pinstCAchievementsWnd_x                                    0xDFF7D4
#define pinstCActionsWnd_x                                         0xDFF7A4
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDFF020
#define pinstCAdvancedLootWnd_x                                    0xDFEFD4
#define pinstCAdventureLeaderboardWnd_x                            0xF723B0
#define pinstCAdventureRequestWnd_x                                0xF72460
#define pinstCAdventureStatsWnd_x                                  0xF72510
#define pinstCAggroMeterWnd_x                                      0xDFF538
#define pinstCAlarmWnd_x                                           0xDFF848
#define pinstCAlertHistoryWnd_x                                    0xDFF01C
#define pinstCAlertStackWnd_x                                      0xDFF828
#define pinstCAlertWnd_x                                           0xDFF844
#define pinstCAltStorageWnd_x                                      0xF72870
#define pinstCAudioTriggersWindow_x                                0xCB3C08
#define pinstCAuraWnd_x                                            0xDFF054
#define pinstCAvaZoneWnd_x                                         0xDFEFE4
#define pinstCBandolierWnd_x                                       0xDFF0CC
#define pinstCBankWnd_x                                            0xDFF050
#define pinstCBarterMerchantWnd_x                                  0xF73AB0
#define pinstCBarterSearchWnd_x                                    0xF73B60
#define pinstCBarterWnd_x                                          0xF73C10
#define pinstCBazaarConfirmationWnd_x                              0xDFF800
#define pinstCBazaarSearchWnd_x                                    0xDFF57C
#define pinstCBazaarWnd_x                                          0xDFF824
#define pinstCBlockedBuffWnd_x                                     0xDFF07C
#define pinstCBlockedPetBuffWnd_x                                  0xDFF0B4
#define pinstCBodyTintWnd_x                                        0xDFF7B8
#define pinstCBookWnd_x                                            0xDFF554
#define pinstCBreathWnd_x                                          0xDFF7FC
#define pinstCBuffWindowNORMAL_x                                   0xDFF03C
#define pinstCBuffWindowSHORT_x                                    0xDFF040
#define pinstCBugReportWnd_x                                       0xDFF04C
#define pinstCButtonWnd_x                                          0x15F7380
#define pinstCCastingWnd_x                                         0xDFF548
#define pinstCCastSpellWnd_x                                       0xDFF7F8
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDFF830
#define pinstCChatWindowManager_x                                  0xF746D0
#define pinstCClaimWnd_x                                           0xF74828
#define pinstCColorPickerWnd_x                                     0xDFF7B0
#define pinstCCombatAbilityWnd_x                                   0xDFF840
#define pinstCCombatSkillsSelectWnd_x                              0xDFEFC0
#define pinstCCompassWnd_x                                         0xDFF7A8
#define pinstCConfirmationDialog_x                                 0xF79728
#define pinstCContainerMgr_x                                       0xDFF81C
#define pinstCContextMenuManager_x                                 0x15F70D0
#define pinstCCursorAttachment_x                                   0xDFF540
#define pinstCDynamicZoneWnd_x                                     0xF74DF0
#define pinstCEditLabelWnd_x                                       0xDFF030
#define pinstCEQMainWnd_x                                          0xF75038
#define pinstCEventCalendarWnd_x                                   0xDFF0B8
#define pinstCExtendedTargetWnd_x                                  0xDFF0A4
#define pinstCFacePick_x                                           0xDFEFC8
#define pinstCFactionWnd_x                                         0xDFF814
#define pinstCFellowshipWnd_x                                      0xF75238
#define pinstCFileSelectionWnd_x                                   0xDFF544
#define pinstCFindItemWnd_x                                        0xDFF808
#define pinstCFindLocationWnd_x                                    0xF75390
#define pinstCFriendsWnd_x                                         0xDFEFD0
#define pinstCGemsGameWnd_x                                        0xDFF810
#define pinstCGiveWnd_x                                            0xDFF84C
#define pinstCGroupSearchFiltersWnd_x                              0xDFF54C
#define pinstCGroupSearchWnd_x                                     0xF75788
#define pinstCGroupWnd_x                                           0xF75838
#define pinstCGuildBankWnd_x                                       0xEC2774
#define pinstCGuildCreationWnd_x                                   0xF75998
#define pinstCGuildMgmtWnd_x                                       0xF75A48
#define pinstCharacterCreation_x                                   0xDFEFC4
#define pinstCHelpWnd_x                                            0xDFF00C
#define pinstCHeritageSelectionWnd_x                               0xDFEFD8
#define pinstCHotButtonWnd_x                                       0xF77BA0
#define pinstCHotButtonWnd1_x                                      0xF77BA0
#define pinstCHotButtonWnd2_x                                      0xF77BA4
#define pinstCHotButtonWnd3_x                                      0xF77BA8
#define pinstCHotButtonWnd4_x                                      0xF77BAC
#define pinstCIconSelectionWnd_x                                   0xDFF53C
#define pinstCInspectWnd_x                                         0xDFF008
#define pinstCInventoryWnd_x                                       0xDFEFDC
#define pinstCInvSlotMgr_x                                         0xDFF7DC
#define pinstCItemDisplayManager_x                                 0xF78130
#define pinstCItemExpTransferWnd_x                                 0xF78260
#define pinstCItemOverflowWnd_x                                    0xDFF580
#define pinstCJournalCatWnd_x                                      0xDFF55C
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDFF0A8
#define pinstCKeyRingWnd_x                                         0xDFF02C
#define pinstCLargeDialogWnd_x                                     0xF7A3A8
#define pinstCLayoutCopyWnd_x                                      0xF785B0
#define pinstCLFGuildWnd_x                                         0xF78660
#define pinstCLoadskinWnd_x                                        0xDFF820
#define pinstCLootFiltersCopyWnd_x                                 0xCD01F8
#define pinstCLootFiltersWnd_x                                     0xDFF82C
#define pinstCLootSettingsWnd_x                                    0xDFEFB8
#define pinstCLootWnd_x                                            0xDFF560
#define pinstCMailAddressBookWnd_x                                 0xDFF7E8
#define pinstCMailCompositionWnd_x                                 0xDFF7CC
#define pinstCMailIgnoreListWnd_x                                  0xDFF7EC
#define pinstCMailWnd_x                                            0xDFF7A0
#define pinstCManageLootWnd_x                                      0xE006B0
#define pinstCMapToolbarWnd_x                                      0xDFF014
#define pinstCMapViewWnd_x                                         0xDFEFF4
#define pinstCMarketplaceWnd_x                                     0xDFF83C
#define pinstCMerchantWnd_x                                        0xDFF570
#define pinstCMIZoneSelectWnd_x                                    0xF78E98
#define pinstCMusicPlayerWnd_x                                     0xDFF574
#define pinstCNameChangeMercWnd_x                                  0xDFF7F0
#define pinstCNameChangePetWnd_x                                   0xDFF7D8
#define pinstCNameChangeWnd_x                                      0xDFF804
#define pinstCNoteWnd_x                                            0xDFEFFC
#define pinstCObjectPreviewWnd_x                                   0xDFF850
#define pinstCOptionsWnd_x                                         0xDFF000
#define pinstCPetInfoWnd_x                                         0xDFF58C
#define pinstCPetitionQWnd_x                                       0xDFF7B4
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDFF7BC
#define pinstCPlayerWnd_x                                          0xDFF590
#define pinstCPopupWndManager_x                                    0xF79728
#define pinstCProgressionSelectionWnd_x                            0xF797D8
#define pinstCPurchaseGroupWnd_x                                   0xDFEFEC
#define pinstCPurchaseWnd_x                                        0xDFEFCC
#define pinstCPvPLeaderboardWnd_x                                  0xF79888
#define pinstCPvPStatsWnd_x                                        0xF79938
#define pinstCQuantityWnd_x                                        0xDFF0AC
#define pinstCRaceChangeWnd_x                                      0xDFF818
#define pinstCRaidOptionsWnd_x                                     0xDFF550
#define pinstCRaidWnd_x                                            0xDFF7D0
#define pinstCRealEstateItemsWnd_x                                 0xDFF7C8
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDFF558
#define pinstCRealEstateManageWnd_x                                0xDFEFF8
#define pinstCRealEstateNeighborhoodWnd_x                          0xDFF018
#define pinstCRealEstatePlotSearchWnd_x                            0xDFF034
#define pinstCRealEstatePurchaseWnd_x                              0xDFF068
#define pinstCRespawnWnd_x                                         0xDFF0A0
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDFF7F4
#define pinstCSendMoneyWnd_x                                       0xDFEFBC
#define pinstCServerListWnd_x                                      0xDFF0B0
#define pinstCSkillsSelectWnd_x                                    0xDFF834
#define pinstCSkillsWnd_x                                          0xDFF80C
#define pinstCSocialEditWnd_x                                      0xDFF028
#define pinstCSocialWnd_x                                          0xDFF7E0
#define pinstCSpellBookWnd_x                                       0xDFF838
#define pinstCStoryWnd_x                                           0xDFF798
#define pinstCTargetOfTargetWnd_x                                  0xF7B760
#define pinstCTargetWnd_x                                          0xDFF09C
#define pinstCTaskOverlayWnd_x                                     0xDFEFE8
#define pinstCTaskSelectWnd_x                                      0xF7B8B8
#define pinstCTaskManager_x                                        0xCD0B38
#define pinstCTaskTemplateSelectWnd_x                              0xF7B968
#define pinstCTaskWnd_x                                            0xF7BA18
#define pinstCTextEntryWnd_x                                       0xDFF044
#define pinstCTimeLeftWnd_x                                        0xDFF584
#define pinstCTipWndCONTEXT_x                                      0xF7BC1C
#define pinstCTipWndOFDAY_x                                        0xF7BC18
#define pinstCTitleWnd_x                                           0xF7BCC8
#define pinstCTrackingWnd_x                                        0xDFEFE0
#define pinstCTradeskillWnd_x                                      0xF7BE30
#define pinstCTradeWnd_x                                           0xDFF7C4
#define pinstCTrainWnd_x                                           0xDFF7C0
#define pinstCTributeBenefitWnd_x                                  0xF7C030
#define pinstCTributeMasterWnd_x                                   0xF7C0E0
#define pinstCTributeTrophyWnd_x                                   0xF7C190
#define pinstCVideoModesWnd_x                                      0xDFF588
#define pinstCVoiceMacroWnd_x                                      0xF65488
#define pinstCVoteResultsWnd_x                                     0xDFF7AC
#define pinstCVoteWnd_x                                            0xDFF79C
#define pinstCWebManager_x                                         0xF65B04
#define pinstCZoneGuideWnd_x                                       0xDFEFF0
#define pinstCZonePathWnd_x                                        0xDFF004

#define pinstEQSuiteTextureLoader_x                                0xC9E080
#define pinstItemIconCache_x                                       0xF74FF0
#define pinstLootFiltersManager_x                                  0xCD02A8
#define pinstRewardSelectionWnd_x                                  0xF7A080

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5AE8D0
#define __CastRay2_x                                               0x5AE920
#define __ConvertItemTags_x                                        0x5CA450
#define __CleanItemTags_x                                          0x47D120
#define __DoesFileExist_x                                          0x903210
#define __EQGetTime_x                                              0x8FFC00
#define __ExecuteCmd_x                                             0x5A7170
#define __FixHeading_x                                             0x99AD40
#define __GameLoop_x                                               0x6BAC70
#define __get_bearing_x                                            0x5AE440
#define __get_melee_range_x                                        0x5AEB10
#define __GetAnimationCache_x                                      0x71FFD0
#define __GetGaugeValueFromEQ_x                                    0x8126D0
#define __GetLabelFromEQ_x                                         0x8141B0
#define __GetXTargetType_x                                         0x99C790
#define __HandleMouseWheel_x                                       0x6BBB30
#define __HeadingDiff_x                                            0x99ADB0
#define __HelpPath_x                                               0xF6082C
#define __LoadFrontEnd_x                                           0x6B7F90
#define __NewUIINI_x                                               0x8123A0
#define __ProcessGameEvents_x                                      0x60E9F0
#define __ProcessMouseEvent_x                                      0x60E1B0
#define __SaveColors_x                                             0x550790
#define __STMLToText_x                                             0x93E1B0
#define __ToggleKeyRingItem_x                                      0x513AE0
#define CMemoryMappedFile__SetFile_x                               0xA8A0E0
#define CrashDetected_x                                            0x6B9A30
#define DrawNetStatus_x                                            0x63A4B0
#define Expansion_HoT_x                                            0xEC277C
#define Teleport_Table_Size_x                                      0xEB17B0
#define Teleport_Table_x                                           0xEB1C30
#define Util__FastTime_x                                           0x8FF7D0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490270
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499170
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x498F40
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493800
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492C50

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x558370
#define AltAdvManager__IsAbilityReady_x                            0x5572A0
#define AltAdvManager__GetAAById_x                                 0x5574A0
#define AltAdvManager__CanTrainAbility_x                           0x557510
#define AltAdvManager__CanSeeAbility_x                             0x557870

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA070
#define CharacterZoneClient__HasSkill_x                            0x4D4F60
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6680
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE300
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BA900
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8FF0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D90D0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D91B0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C30F0
#define CharacterZoneClient__BardCastBard_x                        0x4C5C50
#define CharacterZoneClient__GetMaxEffects_x                       0x4BA9D0
#define CharacterZoneClient__GetEffect_x                           0x4BA840
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C4140
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C4210
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C4260
#define CharacterZoneClient__CalcAffectChange_x                    0x4C43B0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4580
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2770
#define CharacterZoneClient__FindItemByGuid_x                      0x4D75E0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7060

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6E1750
#define CBankWnd__WndNotification_x                                0x6E1530

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6EEFA0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x61D0B0
#define CButtonWnd__CButtonWnd_x                                   0x93A560

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x70F040
#define CChatManager__InitContextMenu_x                            0x708190
#define CChatManager__FreeChatWindow_x                             0x70DB80
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8570
#define CChatManager__SetLockedActiveChatWindow_x                  0x70ECC0
#define CChatManager__CreateChatWindow_x                           0x70E1C0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8680

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x94EC10
#define CContextMenu__dCContextMenu_x                              0x94EE50
#define CContextMenu__AddMenuItem_x                                0x94EE60
#define CContextMenu__RemoveMenuItem_x                             0x94F170
#define CContextMenu__RemoveAllMenuItems_x                         0x94F190
#define CContextMenu__CheckMenuItem_x                              0x94F210
#define CContextMenu__SetMenuItem_x                                0x94F090
#define CContextMenu__AddSeparator_x                               0x94EFF0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x94F7B0
#define CContextMenuManager__RemoveMenu_x                          0x94F820
#define CContextMenuManager__PopupMenu_x                           0x94F8E0
#define CContextMenuManager__Flush_x                               0x94F750
#define CContextMenuManager__GetMenu_x                             0x49B410
#define CContextMenuManager__CreateDefaultMenu_x                   0x71A7D0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8DBC20
#define CChatService__GetFriendName_x                              0x8DBC30

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x70F970
#define CChatWindow__Clear_x                                       0x710C30
#define CChatWindow__WndNotification_x                             0x7113C0
#define CChatWindow__AddHistory_x                                  0x7104F0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x94C060
#define CComboWnd__Draw_x                                          0x94B560
#define CComboWnd__GetCurChoice_x                                  0x94BEA0
#define CComboWnd__GetListRect_x                                   0x94BA10
#define CComboWnd__GetTextRect_x                                   0x94C0D0
#define CComboWnd__InsertChoice_x                                  0x94BBA0
#define CComboWnd__SetColors_x                                     0x94BB70
#define CComboWnd__SetChoice_x                                     0x94BE70
#define CComboWnd__GetItemCount_x                                  0x94BEB0
#define CComboWnd__GetCurChoiceText_x                              0x94BEF0
#define CComboWnd__GetChoiceText_x                                 0x94BEC0
#define CComboWnd__InsertChoiceAtIndex_x                           0x94BC30

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x7181C0
#define CContainerWnd__vftable_x                                   0xB1130C
#define CContainerWnd__SetContainer_x                              0x719720

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54B1D0
#define CDisplay__PreZoneMainUI_x                                  0x54B1E0
#define CDisplay__CleanGameUI_x                                    0x550550
#define CDisplay__GetClickedActor_x                                0x5434F0
#define CDisplay__GetUserDefinedColor_x                            0x53BBB0
#define CDisplay__GetWorldFilePath_x                               0x544F60
#define CDisplay__is3dON_x                                         0x540150
#define CDisplay__ReloadUI_x                                       0x54A660
#define CDisplay__WriteTextHD2_x                                   0x53FF40
#define CDisplay__TrueDistance_x                                   0x546C20
#define CDisplay__SetViewActor_x                                   0x542E10
#define CDisplay__GetFloorHeight_x                                 0x540210
#define CDisplay__SetRenderWindow_x                                0x53EB70
#define CDisplay__ToggleScreenshotMode_x                           0x5428E0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x96E850

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x952180
#define CEditWnd__GetCharIndexPt_x                                 0x9530B0
#define CEditWnd__GetDisplayString_x                               0x952F50
#define CEditWnd__GetHorzOffset_x                                  0x9517C0
#define CEditWnd__GetLineForPrintableChar_x                        0x954250
#define CEditWnd__GetSelStartPt_x                                  0x953360
#define CEditWnd__GetSTMLSafeText_x                                0x952D70
#define CEditWnd__PointFromPrintableChar_x                         0x953E80
#define CEditWnd__SelectableCharFromPoint_x                        0x953FF0
#define CEditWnd__SetEditable_x                                    0x953430
#define CEditWnd__SetWindowTextA_x                                 0x952AF0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5FC660
#define CEverQuest__ClickedPlayer_x                                0x5EE670
#define CEverQuest__CreateTargetIndicator_x                        0x60BC80
#define CEverQuest__DeleteTargetIndicator_x                        0x60BD10
#define CEverQuest__DoTellWindow_x                                 0x4E8760
#define CEverQuest__OutputTextToLog_x                              0x4E89E0
#define CEverQuest__DropHeldItemOnGround_x                         0x5E36B0
#define CEverQuest__dsp_chat_x                                     0x4E8D70
#define CEverQuest__trimName_x                                     0x607F70
#define CEverQuest__Emote_x                                        0x5FCEC0
#define CEverQuest__EnterZone_x                                    0x5F6E40
#define CEverQuest__GetBodyTypeDesc_x                              0x601830
#define CEverQuest__GetClassDesc_x                                 0x601E70
#define CEverQuest__GetClassThreeLetterCode_x                      0x602470
#define CEverQuest__GetDeityDesc_x                                 0x60A5C0
#define CEverQuest__GetLangDesc_x                                  0x602630
#define CEverQuest__GetRaceDesc_x                                  0x601E50
#define CEverQuest__InterpretCmd_x                                 0x60AB90
#define CEverQuest__LeftClickedOnPlayer_x                          0x5E78B0
#define CEverQuest__LMouseUp_x                                     0x5E5C40
#define CEverQuest__RightClickedOnPlayer_x                         0x5E8190
#define CEverQuest__RMouseUp_x                                     0x5E6BC0
#define CEverQuest__SetGameState_x                                 0x5E3440
#define CEverQuest__UPCNotificationFlush_x                         0x607E70
#define CEverQuest__IssuePetCommand_x                              0x603A30
#define CEverQuest__ReportSuccessfulHit_x                          0x5FE2B0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x72A100
#define CGaugeWnd__CalcLinesFillRect_x                             0x72A160
#define CGaugeWnd__Draw_x                                          0x729780

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF1A0
#define CGuild__GetGuildName_x                                     0x4AE280
#define CGuild__GetGuildIndex_x                                    0x4AE610

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x745530

//CHotButton
#define CHotButton__SetButtonSize_x                                0x61D470

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x752570
#define CInvSlotMgr__MoveItem_x                                    0x751290
#define CInvSlotMgr__SelectSlot_x                                  0x752640

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x74FB00
#define CInvSlot__SliderComplete_x                                 0x74D870
#define CInvSlot__GetItemBase_x                                    0x74D200
#define CInvSlot__UpdateItem_x                                     0x74D370

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7540C0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x753260
#define CInvSlotWnd__HandleLButtonUp_x                             0x753C40

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x80DA10
#define CItemDisplayWnd__UpdateStrings_x                           0x7626C0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75C430
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x75C940
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x762CC0
#define CItemDisplayWnd__AboutToShow_x                             0x762300
#define CItemDisplayWnd__WndNotification_x                         0x763DB0
#define CItemDisplayWnd__RequestConvertItem_x                      0x763870
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x761370
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x762120

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x846480

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x7682B0

// CLabel 
#define CLabel__Draw_x                                             0x76DCF0

// CListWnd
#define CListWnd__CListWnd_x                                       0x9246D0
#define CListWnd__dCListWnd_x                                      0x9249F0
#define CListWnd__AddColumn_x                                      0x928E50
#define CListWnd__AddColumn1_x                                     0x928EA0
#define CListWnd__AddLine_x                                        0x929230
#define CListWnd__AddString_x                                      0x929030
#define CListWnd__CalculateFirstVisibleLine_x                      0x928C10
#define CListWnd__CalculateVSBRange_x                              0x928A00
#define CListWnd__ClearSel_x                                       0x929A10
#define CListWnd__ClearAllSel_x                                    0x929A70
#define CListWnd__CloseAndUpdateEditWindow_x                       0x92A490
#define CListWnd__Compare_x                                        0x928340
#define CListWnd__Draw_x                                           0x924B20
#define CListWnd__DrawColumnSeparators_x                           0x927310
#define CListWnd__DrawHeader_x                                     0x927780
#define CListWnd__DrawItem_x                                       0x927C80
#define CListWnd__DrawLine_x                                       0x927480
#define CListWnd__DrawSeparator_x                                  0x9273B0
#define CListWnd__EnableLine_x                                     0x926BE0
#define CListWnd__EnsureVisible_x                                  0x92A3B0
#define CListWnd__ExtendSel_x                                      0x929940
#define CListWnd__GetColumnTooltip_x                               0x926720
#define CListWnd__GetColumnMinWidth_x                              0x926790
#define CListWnd__GetColumnWidth_x                                 0x926690
#define CListWnd__GetCurSel_x                                      0x926020
#define CListWnd__GetItemAtPoint_x                                 0x926E60
#define CListWnd__GetItemAtPoint1_x                                0x926ED0
#define CListWnd__GetItemData_x                                    0x9260A0
#define CListWnd__GetItemHeight_x                                  0x926460
#define CListWnd__GetItemIcon_x                                    0x926230
#define CListWnd__GetItemRect_x                                    0x926CD0
#define CListWnd__GetItemText_x                                    0x9260E0
#define CListWnd__GetSelList_x                                     0x929AC0
#define CListWnd__GetSeparatorRect_x                               0x927110
#define CListWnd__InsertLine_x                                     0x929620
#define CListWnd__RemoveLine_x                                     0x929770
#define CListWnd__SetColors_x                                      0x9289E0
#define CListWnd__SetColumnJustification_x                         0x928710
#define CListWnd__SetColumnWidth_x                                 0x928630
#define CListWnd__SetCurSel_x                                      0x929880
#define CListWnd__SetItemColor_x                                   0x92A060
#define CListWnd__SetItemData_x                                    0x92A020
#define CListWnd__SetItemText_x                                    0x929C30
#define CListWnd__ShiftColumnSeparator_x                           0x9287D0
#define CListWnd__Sort_x                                           0x9284C0
#define CListWnd__ToggleSel_x                                      0x9298B0
#define CListWnd__SetColumnsSizable_x                              0x928880
#define CListWnd__SetItemWnd_x                                     0x929EE0
#define CListWnd__GetItemWnd_x                                     0x926280
#define CListWnd__SetItemIcon_x                                    0x929CB0
#define CListWnd__CalculateCustomWindowPositions_x                 0x928D10
#define CListWnd__SetVScrollPos_x                                  0x928610

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x783570
#define CMapViewWnd__GetWorldCoordinates_x                         0x781C80
#define CMapViewWnd__HandleLButtonDown_x                           0x77ECC0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A35B0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A3E90
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A43B0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A7320
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A2130
#define CMerchantWnd__SelectBuySellSlot_x                          0x7ACED0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A31D0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8A96F0
#define CPacketScrambler__hton_x                                   0x8A96E0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x943800
#define CSidlManager__FindScreenPieceTemplate_x                    0x943C10
#define CSidlManager__FindScreenPieceTemplate1_x                   0x943A00
#define CSidlManager__CreateLabel_x                                0x804E70
#define CSidlManager__CreateXWndFromTemplate_x                     0x946B70
#define CSidlManager__CreateXWndFromTemplate1_x                    0x946D50
#define CSidlManager__CreateXWnd_x                                 0x804DA0
#define CSidlManager__CreateHotButtonWnd_x                         0x805360

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9402E0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9401E0
#define CSidlScreenWnd__ConvertToRes_x                             0x965840
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x93FC70
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x93F960
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x93FA30
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x93FB00
#define CSidlScreenWnd__DrawSidlPiece_x                            0x940780
#define CSidlScreenWnd__EnableIniStorage_x                         0x940C50
#define CSidlScreenWnd__GetSidlPiece_x                             0x940970
#define CSidlScreenWnd__Init1_x                                    0x93F560
#define CSidlScreenWnd__LoadIniInfo_x                              0x940CA0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9417E0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x93E960
#define CSidlScreenWnd__StoreIniInfo_x                             0x941360
#define CSidlScreenWnd__StoreIniVis_x                              0x9416C0
#define CSidlScreenWnd__WndNotification_x                          0x940690
#define CSidlScreenWnd__GetChildItem_x                             0x940BD0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9302F0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15F6FA0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x681D80
#define CSkillMgr__GetSkillCap_x                                   0x681F60
#define CSkillMgr__GetNameToken_x                                  0x681500
#define CSkillMgr__IsActivatedSkill_x                              0x681640
#define CSkillMgr__IsCombatSkill_x                                 0x681580

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9505A0
#define CSliderWnd__SetValue_x                                     0x950410
#define CSliderWnd__SetNumTicks_x                                  0x950470

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x80AEA0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x958DB0
#define CStmlWnd__CalculateHSBRange_x                              0x959EE0
#define CStmlWnd__CalculateVSBRange_x                              0x959E50
#define CStmlWnd__CanBreakAtCharacter_x                            0x95E210
#define CStmlWnd__FastForwardToEndOfTag_x                          0x95EEA0
#define CStmlWnd__ForceParseNow_x                                  0x9593A0
#define CStmlWnd__GetNextTagPiece_x                                0x95E170
#define CStmlWnd__GetSTMLText_x                                    0x503460
#define CStmlWnd__GetVisibleText_x                                 0x9593C0
#define CStmlWnd__InitializeWindowVariables_x                      0x95ECF0
#define CStmlWnd__MakeStmlColorTag_x                               0x958420
#define CStmlWnd__MakeWndNotificationTag_x                         0x958490
#define CStmlWnd__SetSTMLText_x                                    0x9574D0
#define CStmlWnd__StripFirstSTMLLines_x                            0x95FFA0
#define CStmlWnd__UpdateHistoryString_x                            0x95F0B0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x956620
#define CTabWnd__DrawCurrentPage_x                                 0x956D50
#define CTabWnd__DrawTab_x                                         0x956A70
#define CTabWnd__GetCurrentPage_x                                  0x955E20
#define CTabWnd__GetPageInnerRect_x                                0x956060
#define CTabWnd__GetTabInnerRect_x                                 0x955FA0
#define CTabWnd__GetTabRect_x                                      0x955E50
#define CTabWnd__InsertPage_x                                      0x956270
#define CTabWnd__SetPage_x                                         0x9560E0
#define CTabWnd__SetPageRect_x                                     0x956560
#define CTabWnd__UpdatePage_x                                      0x956930
#define CTabWnd__GetPageFromTabIndex_x                             0x9569B0
#define CTabWnd__GetCurrentTabIndex_x                              0x955E10

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x768680
#define CPageWnd__SetTabText_x                                     0x955960

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8EB0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x92D150
#define CTextureFont__GetTextExtent_x                              0x92D310

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B4B60
#define CHtmlComponentWnd__ValidateUri_x                           0x746F20
#define CHtmlWnd__SetClientCallbacks_x                             0x6224C0
#define CHtmlWnd__AddObserver_x                                    0x6224E0
#define CHtmlWnd__RemoveObserver_x                                 0x622540
#define Window__getProgress_x                                      0x85ECC0
#define Window__getStatus_x                                        0x85ECE0
#define Window__getURI_x                                           0x85ECF0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x96B2E0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x91A1E0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E83B0
#define CXStr__CXStr1_x                                            0x481610
#define CXStr__CXStr3_x                                            0x8FBD00
#define CXStr__dCXStr_x                                            0x478740
#define CXStr__operator_equal_x                                    0x8FBF30
#define CXStr__operator_equal1_x                                   0x8FBF70
#define CXStr__operator_plus_equal1_x                              0x8FCA00
#define CXStr__SetString_x                                         0x8FE8F0
#define CXStr__operator_char_p_x                                   0x8FC440
#define CXStr__GetChar_x                                           0x8FE240
#define CXStr__Delete_x                                            0x8FDAF0
#define CXStr__GetUnicode_x                                        0x8FE2B0
#define CXStr__GetLength_x                                         0x47D4D0
#define CXStr__Mid_x                                               0x47D4E0
#define CXStr__Insert_x                                            0x8FE310
#define CXStr__FindNext_x                                          0x8FDF60

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x94E820
#define CXWnd__BringToTop_x                                        0x933A60
#define CXWnd__Center_x                                            0x9335E0
#define CXWnd__ClrFocus_x                                          0x9333F0
#define CXWnd__Destroy_x                                           0x9334A0
#define CXWnd__DoAllDrawing_x                                      0x92FA80
#define CXWnd__DrawChildren_x                                      0x92FA50
#define CXWnd__DrawColoredRect_x                                   0x92FEE0
#define CXWnd__DrawTooltip_x                                       0x92E580
#define CXWnd__DrawTooltipAtPoint_x                                0x92E640
#define CXWnd__GetBorderFrame_x                                    0x92FD40
#define CXWnd__GetChildWndAt_x                                     0x933B00
#define CXWnd__GetClientClipRect_x                                 0x931D30
#define CXWnd__GetScreenClipRect_x                                 0x931E00
#define CXWnd__GetScreenRect_x                                     0x931FD0
#define CXWnd__GetTooltipRect_x                                    0x92FF30
#define CXWnd__GetWindowTextA_x                                    0x49CAF0
#define CXWnd__IsActive_x                                          0x930670
#define CXWnd__IsDescendantOf_x                                    0x932990
#define CXWnd__IsReallyVisible_x                                   0x9329C0
#define CXWnd__IsType_x                                            0x934170
#define CXWnd__Move_x                                              0x932A30
#define CXWnd__Move1_x                                             0x932AE0
#define CXWnd__ProcessTransition_x                                 0x933590
#define CXWnd__Refade_x                                            0x932DC0
#define CXWnd__Resize_x                                            0x933050
#define CXWnd__Right_x                                             0x933820
#define CXWnd__SetFocus_x                                          0x9333B0
#define CXWnd__SetFont_x                                           0x933420
#define CXWnd__SetKeyTooltip_x                                     0x933F90
#define CXWnd__SetMouseOver_x                                      0x930EA0
#define CXWnd__StartFade_x                                         0x932880
#define CXWnd__GetChildItem_x                                      0x933C70
#define CXWnd__SetParent_x                                         0x932780
#define CXWnd__Minimize_x                                          0x9330B0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x9668C0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9369C0
#define CXWndManager__DrawWindows_x                                0x9369E0
#define CXWndManager__GetKeyboardFlags_x                           0x9391D0
#define CXWndManager__HandleKeyboardMsg_x                          0x938D80
#define CXWndManager__RemoveWnd_x                                  0x939420
#define CXWndManager__RemovePendingDeletionWnd_x                   0x939980

// CDBStr
#define CDBStr__GetString_x                                        0x53AB60

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BB8E0
#define EQ_Character__Cur_HP_x                                     0x4D1FA0
#define EQ_Character__Cur_Mana_x                                   0x4D96A0
#define EQ_Character__GetCastingTimeModifier_x                     0x4BE950
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B23B0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B2500
#define EQ_Character__GetHPRegen_x                                 0x4DF440
#define EQ_Character__GetEnduranceRegen_x                          0x4DFA40
#define EQ_Character__GetManaRegen_x                               0x4DFE80
#define EQ_Character__Max_Endurance_x                              0x648340
#define EQ_Character__Max_HP_x                                     0x4D1DD0
#define EQ_Character__Max_Mana_x                                   0x648140
#define EQ_Character__doCombatAbility_x                            0x64A790
#define EQ_Character__UseSkill_x                                   0x4E1C50
#define EQ_Character__GetConLevel_x                                0x641430
#define EQ_Character__IsExpansionFlag_x                            0x5A5900
#define EQ_Character__TotalEffect_x                                0x4C5390
#define EQ_Character__GetPCSpellAffect_x                           0x4BF6A0
#define EQ_Character__SpellDuration_x                              0x4BF1D0
#define EQ_Character__GetAdjustedSkill_x                           0x4D4D20
#define EQ_Character__GetBaseSkill_x                               0x4D5CC0
#define EQ_Character__CanUseItem_x                                 0x4D99B0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8C8AC0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x65EC60

//PcClient
#define PcClient__PcClient_x                                       0x63EB60

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B9550
#define CCharacterListWnd__EnterWorld_x                            0x4B8F90
#define CCharacterListWnd__Quit_x                                  0x4B8CE0
#define CCharacterListWnd__UpdateList_x                            0x4B9120

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x623710
#define EQ_Item__CreateItemTagString_x                             0x8A2F00
#define EQ_Item__IsStackable_x                                     0x8A7A80
#define EQ_Item__GetImageNum_x                                     0x8A4950
#define EQ_Item__CreateItemClient_x                                0x6228E0
#define EQ_Item__GetItemValue_x                                    0x8A5C50
#define EQ_Item__ValueSellMerchant_x                               0x8A92C0
#define EQ_Item__IsKeyRingItem_x                                   0x8A7380
#define EQ_Item__CanGoInBag_x                                      0x623830
#define EQ_Item__IsEmpty_x                                         0x8A6EE0
#define EQ_Item__GetMaxItemCount_x                                 0x8A6070
#define EQ_Item__GetHeldItem_x                                     0x8A4820
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A2870

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x559050
#define EQ_LoadingS__Array_x                                       0xC25B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x648CA0
#define EQ_PC__GetAlternateAbilityId_x                             0x8B2510
#define EQ_PC__GetCombatAbility_x                                  0x8B2B80
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B2BF0
#define EQ_PC__GetItemRecastTimer_x                                0x64AD10
#define EQ_PC__HasLoreItem_x                                       0x641C40
#define EQ_PC__AlertInventoryChanged_x                             0x640D60
#define EQ_PC__GetPcZoneClient_x                                   0x66D710
#define EQ_PC__RemoveMyAffect_x                                    0x64DF50
#define EQ_PC__GetKeyRingItems_x                                   0x8B3480
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B3210
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B3780

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5ABEA0
#define EQItemList__add_object_x                                   0x5D8D60
#define EQItemList__add_item_x                                     0x5AC400
#define EQItemList__delete_item_x                                  0x5AC450
#define EQItemList__FreeItemList_x                                 0x5AC350

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x537690

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x6604E0
#define EQPlayer__dEQPlayer_x                                      0x653400
#define EQPlayer__DoAttack_x                                       0x6683D0
#define EQPlayer__EQPlayer_x                                       0x653AC0
#define EQPlayer__SetNameSpriteState_x                             0x6581C0
#define EQPlayer__SetNameSpriteTint_x                              0x659090
#define PlayerBase__HasProperty_j_x                                0x999110
#define EQPlayer__IsTargetable_x                                   0x9995B0
#define EQPlayer__CanSee_x                                         0x999410
#define EQPlayer__CanSee1_x                                        0x9994E0
#define PlayerBase__GetVisibilityLineSegment_x                     0x9991D0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x66B1B0
#define PlayerZoneClient__GetLevel_x                               0x66D750
#define PlayerZoneClient__IsValidTeleport_x                        0x5D9ED0
#define PlayerZoneClient__LegalPlayerRace_x                        0x5523B0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x6632A0
#define EQPlayerManager__GetSpawnByName_x                          0x663350
#define EQPlayerManager__GetPlayerFromPartialName_x                0x6633E0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x626D20
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x626DA0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x626DE0
#define KeypressHandler__ClearCommandStateArray_x                  0x6281F0
#define KeypressHandler__HandleKeyDown_x                           0x628210
#define KeypressHandler__HandleKeyUp_x                             0x6282B0
#define KeypressHandler__SaveKeymapping_x                          0x628700

// MapViewMap 
#define MapViewMap__Clear_x                                        0x77F3E0
#define MapViewMap__SaveEx_x                                       0x7827A0
#define MapViewMap__SetZoom_x                                      0x786E60

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C69E0

// StringTable 
#define StringTable__getString_x                                   0x8C1640

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x64DBC0
#define PcZoneClient__RemovePetEffect_x                            0x64E1F0
#define PcZoneClient__HasAlternateAbility_x                        0x647F70
#define PcZoneClient__GetCurrentMod_x                              0x4E4D00
#define PcZoneClient__GetModCap_x                                  0x4E4C00
#define PcZoneClient__CanEquipItem_x                               0x648640
#define PcZoneClient__GetItemByID_x                                0x64B190
#define PcZoneClient__GetItemByItemClass_x                         0x64B2E0
#define PcZoneClient__RemoveBuffEffect_x                           0x64E210
#define PcZoneClient__BandolierSwap_x                              0x649250
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64ACB0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5DEA50

//IconCache
#define IconCache__GetIcon_x                                       0x71F870

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x717360
#define CContainerMgr__CloseContainer_x                            0x717630
#define CContainerMgr__OpenExperimentContainer_x                   0x7180B0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D7450

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x61B8A0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x7757F0
#define CLootWnd__RequestLootSlot_x                                0x774A20

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x578AE0
#define EQ_Spell__SpellAffects_x                                   0x578F50
#define EQ_Spell__SpellAffectBase_x                                0x578D10
#define EQ_Spell__IsStackable_x                                    0x4C99D0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9880
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B68A0
#define EQ_Spell__IsSPAStacking_x                                  0x579DA0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x5792B0
#define EQ_Spell__IsNoRemove_x                                     0x4C99B0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x579DB0
#define __IsResEffectSpell_x                                       0x4C8DD0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4ACEF0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D1110

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x81E150
#define CTargetWnd__WndNotification_x                              0x81D9E0
#define CTargetWnd__RefreshTargetBuffs_x                           0x81DCB0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x81CB50

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x822750

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x5350E0
#define CTaskManager__HandleMessage_x                              0x533570
#define CTaskManager__GetTaskStatus_x                              0x535190
#define CTaskManager__GetElementDescription_x                      0x535210

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x574020
#define EqSoundManager__PlayScriptMp3_x                            0x574180
#define EqSoundManager__SoundAssistPlay_x                          0x685CE0
#define EqSoundManager__WaveInstancePlay_x                         0x685250

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x528E20

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x954E70

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x560A50
#define CAltAbilityData__GetMercMaxRank_x                          0x5609E0
#define CAltAbilityData__GetMaxRank_x                              0x556120

//CTargetRing
#define CTargetRing__Cast_x                                        0x6199C0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9860
#define CharacterBase__CreateItemGlobalIndex_x                     0x510190
#define CharacterBase__CreateItemIndex_x                           0x621A70
#define CharacterBase__GetItemPossession_x                         0x4FBE20
#define CharacterBase__GetItemByGlobalIndex_x                      0x8D96F0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8D9750
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6FE3F0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6FEC20
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6FECD0

//messages
#define msg_spell_worn_off_x                                       0x59DB10
#define msg_new_text_x                                             0x5928B0
#define __msgTokenTextParam_x                                      0x5A0040
#define msgTokenText_x                                             0x5A0290

//SpellManager
#define SpellManager__vftable_x                                    0xAEB398
#define SpellManager__SpellManager_x                               0x689010
#define Spellmanager__LoadTextSpells_x                             0x689900
#define SpellManager__GetSpellByGroupAndRank_x                     0x6891E0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x99D080

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x5107E0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A3E00
#define ItemGlobalIndex__IsEquippedLocation_x                      0x63A310
#define ItemGlobalIndex__IsValidIndex_x                            0x510840

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D1AB0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D1D30

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x76E030

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x71BA70
#define CCursorAttachment__AttachToCursor1_x                       0x71BAB0
#define CCursorAttachment__Deactivate_x                            0x71CAA0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x947B90
#define CSidlManagerBase__CreatePageWnd_x                          0x947390
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x943620
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x9435B0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x964CD0
#define CEQSuiteTextureLoader__GetTexture_x                        0x964990

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50D760
#define CFindItemWnd__WndNotification_x                            0x50E240
#define CFindItemWnd__Update_x                                     0x50ED80
#define CFindItemWnd__PickupSelectedItem_x                         0x50CFB0

//IString
#define IString__Append_x                                          0x4FD710

//Camera
#define CDisplay__cameraType_x                                     0xDFF594
#define EverQuest__Cameras_x                                       0xEC2ACC

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x515E80
#define LootFiltersManager__GetItemFilterData_x                    0x515790
#define LootFiltersManager__RemoveItemLootFilter_x                 0x5157C0
#define LootFiltersManager__SetItemLootFilter_x                    0x5159E0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C5440

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A2C40
#define CResolutionHandler__GetWindowedStyle_x                     0x680770

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x7140C0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E61F0
#define CDistillerInfo__Instance_x                                 0x8E6190

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x734320
#define CGroupWnd__UpdateDisplay_x                                 0x733680

//ItemBase
#define ItemBase__IsLore_x                                         0x8A7430
#define ItemBase__IsLoreEquipped_x                                 0x8A74B0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5D8CC0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5D8E00
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5D8E60

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x675E90
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x679830

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x503BD0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F15E0
#define FactionManagerClient__HandleFactionMessage_x               0x4F1C50
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F2210
#define FactionManagerClient__GetMaxFaction_x                      0x4F222F
#define FactionManagerClient__GetMinFaction_x                      0x4F21E0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FBDF0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x92C100

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BE00

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FC120

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x55FF20

//CTargetManager
#define CTargetManager__Get_x                                      0x68C850

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x675E90

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8C70

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5AC2F0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF60160

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
