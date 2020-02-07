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
#define __ExpectedVersionDate                                     "Feb  6 2020"
#define __ExpectedVersionTime                                     "11:06:11"
#define __ActualVersionDate_x                                      0xB16CD8
#define __ActualVersionTime_x                                      0xB16CCC
#define __ActualVersionBuild_x                                     0xB029F4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x63B920
#define __MemChecker1_x                                            0x90E990
#define __MemChecker2_x                                            0x6CA0A0
#define __MemChecker3_x                                            0x6C9FF0
#define __MemChecker4_x                                            0x865520
#define __EncryptPad0_x                                            0xC4E3F0
#define __EncryptPad1_x                                            0xCAC658
#define __EncryptPad2_x                                            0xC5EC88
#define __EncryptPad3_x                                            0xC5E888
#define __EncryptPad4_x                                            0xC9CC08
#define __EncryptPad5_x                                            0xF6D81C
#define __AC1_x                                                    0x821E46
#define __AC2_x                                                    0x5F577F
#define __AC3_x                                                    0x5FCE7F
#define __AC4_x                                                    0x600E50
#define __AC5_x                                                    0x60715F
#define __AC6_x                                                    0x60B656
#define __AC7_x                                                    0x5F51F0
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
#define __do_loot_x                                                0x5C1180
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
#define __gfMaxZoomCameraDistance_x                                0xB0C638
#define __gfMaxCameraDistance_x                                    0xB389F4
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
#define __CastRay_x                                                0x5BC5E0
#define __CastRay2_x                                               0x5BC630
#define __ConvertItemTags_x                                        0x5D8190
#define __CleanItemTags_x                                          0x47D0B0
#define __DoesFileExist_x                                          0x911A70
#define __EQGetTime_x                                              0x90E460
#define __ExecuteCmd_x                                             0x5B4E40
#define __FixHeading_x                                             0x9A7FF0
#define __GameLoop_x                                               0x6C9270
#define __get_bearing_x                                            0x5BC150
#define __get_melee_range_x                                        0x5BC820
#define __GetAnimationCache_x                                      0x72E8E0
#define __GetGaugeValueFromEQ_x                                    0x8202F0
#define __GetLabelFromEQ_x                                         0x821DD0
#define __GetXTargetType_x                                         0x9A99D0
#define __HandleMouseWheel_x                                       0x6CA150
#define __HeadingDiff_x                                            0x9A8060
#define __HelpPath_x                                               0xF682D4
#define __LoadFrontEnd_x                                           0x6C6590
#define __NewUIINI_x                                               0x81FFC0
#define __ProcessGameEvents_x                                      0x61CEF0
#define __ProcessMouseEvent_x                                      0x61C6B0
#define __SaveColors_x                                             0x5596C0
#define __STMLToText_x                                             0x94B5A0
#define __ToggleKeyRingItem_x                                      0x51A370
#define CMemoryMappedFile__SetFile_x                               0xA97330
#define CrashDetected_x                                            0x6C8030
#define DrawNetStatus_x                                            0x648AC0
#define Expansion_HoT_x                                            0xECA224
#define Teleport_Table_Size_x                                      0xEC3CBC
#define Teleport_Table_x                                           0xEC1878
#define Util__FastTime_x                                           0x90E030

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490290
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4991A0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x498F70
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493830
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492C80

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x561350
#define AltAdvManager__IsAbilityReady_x                            0x5600F0
#define AltAdvManager__GetAAById_x                                 0x560480
#define AltAdvManager__CanTrainAbility_x                           0x5604F0
#define AltAdvManager__CanSeeAbility_x                             0x560850

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C9B80
#define CharacterZoneClient__HasSkill_x                            0x4D4A00
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6120
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE280
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BA8B0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8AB0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D8B90
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D8C70
#define CharacterZoneClient__FindAffectSlot_x                      0x4C2980
#define CharacterZoneClient__BardCastBard_x                        0x4C54E0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BA980
#define CharacterZoneClient__GetEffect_x                           0x4BA7F0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C39D0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C3AA0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C3AF0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C3C40
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C3E10
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2730
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7080
#define CharacterZoneClient__FindItemByRecord_x                    0x4D6B00

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6EFD40
#define CBankWnd__WndNotification_x                                0x6EFB20

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6FD320

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x62B600
#define CButtonWnd__CButtonWnd_x                                   0x9479C0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x71D940
#define CChatManager__InitContextMenu_x                            0x716A70
#define CChatManager__FreeChatWindow_x                             0x71C480
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8030
#define CChatManager__SetLockedActiveChatWindow_x                  0x71D5C0
#define CChatManager__CreateChatWindow_x                           0x71CAC0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8140

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x95C060
#define CContextMenu__dCContextMenu_x                              0x95C290
#define CContextMenu__AddMenuItem_x                                0x95C2A0
#define CContextMenu__RemoveMenuItem_x                             0x95C5A0
#define CContextMenu__RemoveAllMenuItems_x                         0x95C5C0
#define CContextMenu__CheckMenuItem_x                              0x95C640
#define CContextMenu__SetMenuItem_x                                0x95C4D0
#define CContextMenu__AddSeparator_x                               0x95C430

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x95CBE0
#define CContextMenuManager__RemoveMenu_x                          0x95CC50
#define CContextMenuManager__PopupMenu_x                           0x95CD10
#define CContextMenuManager__Flush_x                               0x95CB80
#define CContextMenuManager__GetMenu_x                             0x49B260
#define CContextMenuManager__CreateDefaultMenu_x                   0x7290E0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8E97B0
#define CChatService__GetFriendName_x                              0x8E97C0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x71E1B0
#define CChatWindow__Clear_x                                       0x71F480
#define CChatWindow__WndNotification_x                             0x71FC10
#define CChatWindow__AddHistory_x                                  0x71ED40

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x9594C0
#define CComboWnd__Draw_x                                          0x9589C0
#define CComboWnd__GetCurChoice_x                                  0x959300
#define CComboWnd__GetListRect_x                                   0x958E70
#define CComboWnd__GetTextRect_x                                   0x959520
#define CComboWnd__InsertChoice_x                                  0x959000
#define CComboWnd__SetColors_x                                     0x958FD0
#define CComboWnd__SetChoice_x                                     0x9592D0
#define CComboWnd__GetItemCount_x                                  0x959310
#define CComboWnd__GetCurChoiceText_x                              0x959350
#define CComboWnd__GetChoiceText_x                                 0x959320
#define CComboWnd__InsertChoiceAtIndex_x                           0x959090

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x726AD0
#define CContainerWnd__vftable_x                                   0xB1FECC
#define CContainerWnd__SetContainer_x                              0x728030

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x554090
#define CDisplay__PreZoneMainUI_x                                  0x5540A0
#define CDisplay__CleanGameUI_x                                    0x559480
#define CDisplay__GetClickedActor_x                                0x54C390
#define CDisplay__GetUserDefinedColor_x                            0x5449F0
#define CDisplay__GetWorldFilePath_x                               0x54DE00
#define CDisplay__is3dON_x                                         0x548FF0
#define CDisplay__ReloadUI_x                                       0x553510
#define CDisplay__WriteTextHD2_x                                   0x548DE0
#define CDisplay__TrueDistance_x                                   0x54FAC0
#define CDisplay__SetViewActor_x                                   0x54BCB0
#define CDisplay__GetFloorHeight_x                                 0x5490B0
#define CDisplay__SetRenderWindow_x                                0x547A10
#define CDisplay__ToggleScreenshotMode_x                           0x54B780

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x97BCE0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x95F5D0
#define CEditWnd__EnsureCaretVisible_x                             0x961780
#define CEditWnd__GetCaretPt_x                                     0x960730
#define CEditWnd__GetCharIndexPt_x                                 0x9604F0
#define CEditWnd__GetDisplayString_x                               0x960390
#define CEditWnd__GetHorzOffset_x                                  0x95EC00
#define CEditWnd__GetLineForPrintableChar_x                        0x961680
#define CEditWnd__GetSelStartPt_x                                  0x960790
#define CEditWnd__GetSTMLSafeText_x                                0x9601B0
#define CEditWnd__PointFromPrintableChar_x                         0x9612B0
#define CEditWnd__SelectableCharFromPoint_x                        0x961420
#define CEditWnd__SetEditable_x                                    0x960860
#define CEditWnd__SetWindowTextA_x                                 0x95FF30
#define CEditWnd__ReplaceSelection_x                               0x960F20
#define CEditWnd__ReplaceSelection1_x                              0x960EA0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x60AB30
#define CEverQuest__ClickedPlayer_x                                0x5FCC60
#define CEverQuest__CreateTargetIndicator_x                        0x61A190
#define CEverQuest__DeleteTargetIndicator_x                        0x61A220
#define CEverQuest__DoTellWindow_x                                 0x4E8220
#define CEverQuest__OutputTextToLog_x                              0x4E84F0
#define CEverQuest__DropHeldItemOnGround_x                         0x5F1CA0
#define CEverQuest__dsp_chat_x                                     0x4E8880
#define CEverQuest__trimName_x                                     0x616390
#define CEverQuest__Emote_x                                        0x60B390
#define CEverQuest__EnterZone_x                                    0x605430
#define CEverQuest__GetBodyTypeDesc_x                              0x60FC50
#define CEverQuest__GetClassDesc_x                                 0x610290
#define CEverQuest__GetClassThreeLetterCode_x                      0x610890
#define CEverQuest__GetDeityDesc_x                                 0x6189E0
#define CEverQuest__GetLangDesc_x                                  0x610A50
#define CEverQuest__GetRaceDesc_x                                  0x610270
#define CEverQuest__InterpretCmd_x                                 0x618FB0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5F5EA0
#define CEverQuest__LMouseUp_x                                     0x5F4230
#define CEverQuest__RightClickedOnPlayer_x                         0x5F6780
#define CEverQuest__RMouseUp_x                                     0x5F51B0
#define CEverQuest__SetGameState_x                                 0x5F1A30
#define CEverQuest__UPCNotificationFlush_x                         0x616290
#define CEverQuest__IssuePetCommand_x                              0x611E50
#define CEverQuest__ReportSuccessfulHit_x                          0x60C6E0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x738990
#define CGaugeWnd__CalcLinesFillRect_x                             0x7389F0
#define CGaugeWnd__Draw_x                                          0x738020

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF200
#define CGuild__GetGuildName_x                                     0x4AE230
#define CGuild__GetGuildIndex_x                                    0x4AE670

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x752BB0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x62B9C0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x75FB70
#define CInvSlotMgr__MoveItem_x                                    0x75E8E0
#define CInvSlotMgr__SelectSlot_x                                  0x75FC40

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x75D160
#define CInvSlot__SliderComplete_x                                 0x75AEB0
#define CInvSlot__GetItemBase_x                                    0x75A850
#define CInvSlot__UpdateItem_x                                     0x75A9C0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7616C0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x760860
#define CInvSlotWnd__HandleLButtonUp_x                             0x761240

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x81B660
#define CItemDisplayWnd__UpdateStrings_x                           0x76FDA0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x769A90
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x769FB0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x7703B0
#define CItemDisplayWnd__AboutToShow_x                             0x76F9F0
#define CItemDisplayWnd__WndNotification_x                         0x771490
#define CItemDisplayWnd__RequestConvertItem_x                      0x770F50
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x76EA50
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x76F810

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x854180

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x7759E0

// CLabel 
#define CLabel__Draw_x                                             0x77B3B0

// CListWnd
#define CListWnd__CListWnd_x                                       0x931DC0
#define CListWnd__dCListWnd_x                                      0x9320E0
#define CListWnd__AddColumn_x                                      0x936520
#define CListWnd__AddColumn1_x                                     0x936570
#define CListWnd__AddLine_x                                        0x936900
#define CListWnd__AddString_x                                      0x936700
#define CListWnd__CalculateFirstVisibleLine_x                      0x9362F0
#define CListWnd__CalculateVSBRange_x                              0x9360D0
#define CListWnd__ClearSel_x                                       0x9370E0
#define CListWnd__ClearAllSel_x                                    0x937140
#define CListWnd__CloseAndUpdateEditWindow_x                       0x937B30
#define CListWnd__Compare_x                                        0x935A00
#define CListWnd__Draw_x                                           0x932210
#define CListWnd__DrawColumnSeparators_x                           0x9349F0
#define CListWnd__DrawHeader_x                                     0x934E50
#define CListWnd__DrawItem_x                                       0x935340
#define CListWnd__DrawLine_x                                       0x934B50
#define CListWnd__DrawSeparator_x                                  0x934A90
#define CListWnd__EnableLine_x                                     0x9342D0
#define CListWnd__EnsureVisible_x                                  0x937A70
#define CListWnd__ExtendSel_x                                      0x937010
#define CListWnd__GetColumnTooltip_x                               0x933E10
#define CListWnd__GetColumnMinWidth_x                              0x933E80
#define CListWnd__GetColumnWidth_x                                 0x933D80
#define CListWnd__GetCurSel_x                                      0x933710
#define CListWnd__GetItemAtPoint_x                                 0x934540
#define CListWnd__GetItemAtPoint1_x                                0x9345B0
#define CListWnd__GetItemData_x                                    0x933790
#define CListWnd__GetItemHeight_x                                  0x933B50
#define CListWnd__GetItemIcon_x                                    0x933920
#define CListWnd__GetItemRect_x                                    0x9343C0
#define CListWnd__GetItemText_x                                    0x9337D0
#define CListWnd__GetSelList_x                                     0x937190
#define CListWnd__GetSeparatorRect_x                               0x9347F0
#define CListWnd__InsertLine_x                                     0x936CF0
#define CListWnd__RemoveLine_x                                     0x936E40
#define CListWnd__SetColors_x                                      0x9360A0
#define CListWnd__SetColumnJustification_x                         0x935DD0
#define CListWnd__SetColumnLabel_x                                 0x9366A0
#define CListWnd__SetColumnWidth_x                                 0x935CF0
#define CListWnd__SetCurSel_x                                      0x936F50
#define CListWnd__SetItemColor_x                                   0x937730
#define CListWnd__SetItemData_x                                    0x9376F0
#define CListWnd__SetItemText_x                                    0x937300
#define CListWnd__ShiftColumnSeparator_x                           0x935E90
#define CListWnd__Sort_x                                           0x935B80
#define CListWnd__ToggleSel_x                                      0x936F80
#define CListWnd__SetColumnsSizable_x                              0x935F40
#define CListWnd__SetItemWnd_x                                     0x9375B0
#define CListWnd__GetItemWnd_x                                     0x933970
#define CListWnd__SetItemIcon_x                                    0x937380
#define CListWnd__CalculateCustomWindowPositions_x                 0x9363E0
#define CListWnd__SetVScrollPos_x                                  0x935CD0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x790B70
#define CMapViewWnd__GetWorldCoordinates_x                         0x78F280
#define CMapViewWnd__HandleLButtonDown_x                           0x78C2C0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7B0E80
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7B1760
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7B1C90
#define CMerchantWnd__SelectRecoverySlot_x                         0x7B4C10
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7AF9F0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7BA7B0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7B0A90

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8B7710
#define CPacketScrambler__hton_x                                   0x8B7700

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x950BB0
#define CSidlManager__FindScreenPieceTemplate_x                    0x950FC0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x950DB0
#define CSidlManager__CreateLabel_x                                0x812930
#define CSidlManager__CreateXWndFromTemplate_x                     0x953F20
#define CSidlManager__CreateXWndFromTemplate1_x                    0x954100
#define CSidlManager__CreateXWnd_x                                 0x812860
#define CSidlManager__CreateHotButtonWnd_x                         0x812E30

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x94D6B0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x94D5B0
#define CSidlScreenWnd__ConvertToRes_x                             0x9767C0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x94D040
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x94CD30
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x94CE00
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x94CED0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x94DB40
#define CSidlScreenWnd__EnableIniStorage_x                         0x94E010
#define CSidlScreenWnd__GetSidlPiece_x                             0x94DD30
#define CSidlScreenWnd__Init1_x                                    0x94C930
#define CSidlScreenWnd__LoadIniInfo_x                              0x94E060
#define CSidlScreenWnd__LoadIniListWnd_x                           0x94EB90
#define CSidlScreenWnd__LoadSidlScreen_x                           0x94BD50
#define CSidlScreenWnd__StoreIniInfo_x                             0x94E710
#define CSidlScreenWnd__StoreIniVis_x                              0x94EA70
#define CSidlScreenWnd__WndNotification_x                          0x94DA50
#define CSidlScreenWnd__GetChildItem_x                             0x94DF90
#define CSidlScreenWnd__HandleLButtonUp_x                          0x93D8A0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15FEA98

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x690390
#define CSkillMgr__GetSkillCap_x                                   0x690570
#define CSkillMgr__GetNameToken_x                                  0x68FB10
#define CSkillMgr__IsActivatedSkill_x                              0x68FC50
#define CSkillMgr__IsCombatSkill_x                                 0x68FB90

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x95D9E0
#define CSliderWnd__SetValue_x                                     0x95D850
#define CSliderWnd__SetNumTicks_x                                  0x95D8B0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x818A30

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x9661D0
#define CStmlWnd__ParseSTML_x                                      0x967550
#define CStmlWnd__CalculateHSBRange_x                              0x967330
#define CStmlWnd__CalculateVSBRange_x                              0x9672B0
#define CStmlWnd__CanBreakAtCharacter_x                            0x96B670
#define CStmlWnd__FastForwardToEndOfTag_x                          0x96C300
#define CStmlWnd__ForceParseNow_x                                  0x966810
#define CStmlWnd__GetNextTagPiece_x                                0x96B5D0
#define CStmlWnd__GetSTMLText_x                                    0x509C70
#define CStmlWnd__GetVisibleText_x                                 0x966830
#define CStmlWnd__InitializeWindowVariables_x                      0x96C150
#define CStmlWnd__MakeStmlColorTag_x                               0x965840
#define CStmlWnd__MakeWndNotificationTag_x                         0x9658B0
#define CStmlWnd__SetSTMLText_x                                    0x9648F0
#define CStmlWnd__StripFirstSTMLLines_x                            0x96D3C0
#define CStmlWnd__UpdateHistoryString_x                            0x96C510

// CTabWnd 
#define CTabWnd__Draw_x                                            0x963A20
#define CTabWnd__DrawCurrentPage_x                                 0x964150
#define CTabWnd__DrawTab_x                                         0x963E70
#define CTabWnd__GetCurrentPage_x                                  0x963220
#define CTabWnd__GetPageInnerRect_x                                0x963460
#define CTabWnd__GetTabInnerRect_x                                 0x9633A0
#define CTabWnd__GetTabRect_x                                      0x963250
#define CTabWnd__InsertPage_x                                      0x963670
#define CTabWnd__SetPage_x                                         0x9634E0
#define CTabWnd__SetPageRect_x                                     0x963960
#define CTabWnd__UpdatePage_x                                      0x963D30
#define CTabWnd__GetPageFromTabIndex_x                             0x963DB0
#define CTabWnd__GetCurrentTabIndex_x                              0x963210

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x775DB0
#define CPageWnd__SetTabText_x                                     0x962D70

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8CB0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x93A770
#define CTextureFont__GetTextExtent_x                              0x93A930

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6C3440
#define CHtmlComponentWnd__ValidateUri_x                           0x7545A0
#define CHtmlWnd__SetClientCallbacks_x                             0x630A50
#define CHtmlWnd__AddObserver_x                                    0x630A70
#define CHtmlWnd__RemoveObserver_x                                 0x630AD0
#define Window__getProgress_x                                      0x86CAF0
#define Window__getStatus_x                                        0x86CB10
#define Window__getURI_x                                           0x86CB20

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x973590

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x927A90

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E7E70
#define CXStr__CXStr1_x                                            0x4815B0
#define CXStr__CXStr3_x                                            0x90A5C0
#define CXStr__dCXStr_x                                            0x478710
#define CXStr__operator_equal_x                                    0x90A7F0
#define CXStr__operator_equal1_x                                   0x90A830
#define CXStr__operator_plus_equal1_x                              0x90B2C0
#define CXStr__SetString_x                                         0x90D1B0
#define CXStr__operator_char_p_x                                   0x90AD30
#define CXStr__GetChar_x                                           0x90CB00
#define CXStr__Delete_x                                            0x90C3B0
#define CXStr__GetUnicode_x                                        0x90CB70
#define CXStr__GetLength_x                                         0x4A8A60
#define CXStr__Mid_x                                               0x47D460
#define CXStr__Insert_x                                            0x90CBD0
#define CXStr__FindNext_x                                          0x90C820

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x95BC70
#define CXWnd__BringToTop_x                                        0x941000
#define CXWnd__Center_x                                            0x940B80
#define CXWnd__ClrFocus_x                                          0x9409A0
#define CXWnd__Destroy_x                                           0x940A40
#define CXWnd__DoAllDrawing_x                                      0x93D050
#define CXWnd__DrawChildren_x                                      0x93D020
#define CXWnd__DrawColoredRect_x                                   0x93D4B0
#define CXWnd__DrawTooltip_x                                       0x93BB80
#define CXWnd__DrawTooltipAtPoint_x                                0x93BC40
#define CXWnd__GetBorderFrame_x                                    0x93D310
#define CXWnd__GetChildWndAt_x                                     0x9410A0
#define CXWnd__GetClientClipRect_x                                 0x93F2D0
#define CXWnd__GetScreenClipRect_x                                 0x93F3A0
#define CXWnd__GetScreenRect_x                                     0x93F570
#define CXWnd__GetRelativeRect_x                                   0x93F620
#define CXWnd__GetTooltipRect_x                                    0x93D500
#define CXWnd__GetWindowTextA_x                                    0x49C930
#define CXWnd__IsActive_x                                          0x93DC20
#define CXWnd__IsDescendantOf_x                                    0x93FF40
#define CXWnd__IsReallyVisible_x                                   0x93FF70
#define CXWnd__IsType_x                                            0x9416F0
#define CXWnd__Move_x                                              0x93FFE0
#define CXWnd__Move1_x                                             0x940090
#define CXWnd__ProcessTransition_x                                 0x940B30
#define CXWnd__Refade_x                                            0x940340
#define CXWnd__Resize_x                                            0x9405E0
#define CXWnd__Right_x                                             0x940DC0
#define CXWnd__SetFocus_x                                          0x940960
#define CXWnd__SetFont_x                                           0x9409D0
#define CXWnd__SetKeyTooltip_x                                     0x941510
#define CXWnd__SetMouseOver_x                                      0x93E430
#define CXWnd__StartFade_x                                         0x93FE20
#define CXWnd__GetChildItem_x                                      0x941210
#define CXWnd__SetParent_x                                         0x93FCD0
#define CXWnd__Minimize_x                                          0x940650

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x977850

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x943EC0
#define CXWndManager__DrawWindows_x                                0x943EE0
#define CXWndManager__GetKeyboardFlags_x                           0x9465E0
#define CXWndManager__HandleKeyboardMsg_x                          0x946190
#define CXWndManager__RemoveWnd_x                                  0x946810
#define CXWndManager__RemovePendingDeletionWnd_x                   0x946D90

// CDBStr
#define CDBStr__GetString_x                                        0x543990

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BB890
#define EQ_Character__Cur_HP_x                                     0x4D1A40
#define EQ_Character__Cur_Mana_x                                   0x4D9170
#define EQ_Character__GetCastingTimeModifier_x                     0x4BE8D0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2370
#define EQ_Character__GetFocusRangeModifier_x                      0x4B24C0
#define EQ_Character__GetHPRegen_x                                 0x4DEF40
#define EQ_Character__GetEnduranceRegen_x                          0x4DF540
#define EQ_Character__GetManaRegen_x                               0x4DF980
#define EQ_Character__Max_Endurance_x                              0x656A00
#define EQ_Character__Max_HP_x                                     0x4D1870
#define EQ_Character__Max_Mana_x                                   0x656800
#define EQ_Character__doCombatAbility_x                            0x658E30
#define EQ_Character__UseSkill_x                                   0x4E1750
#define EQ_Character__GetConLevel_x                                0x64FA20
#define EQ_Character__IsExpansionFlag_x                            0x5B3620
#define EQ_Character__TotalEffect_x                                0x4C4C20
#define EQ_Character__GetPCSpellAffect_x                           0x4BF620
#define EQ_Character__SpellDuration_x                              0x4BF150
#define EQ_Character__GetAdjustedSkill_x                           0x4D47C0
#define EQ_Character__GetBaseSkill_x                               0x4D5760
#define EQ_Character__CanUseItem_x                                 0x4D9480

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8D67D0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x66D370

//PcClient
#define PcClient__PcClient_x                                       0x64D160

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B9500
#define CCharacterListWnd__EnterWorld_x                            0x4B8F40
#define CCharacterListWnd__Quit_x                                  0x4B8C90
#define CCharacterListWnd__UpdateList_x                            0x4B90D0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x631C00
#define EQ_Item__CreateItemTagString_x                             0x8B0D00
#define EQ_Item__IsStackable_x                                     0x8B5980
#define EQ_Item__GetImageNum_x                                     0x8B27B0
#define EQ_Item__CreateItemClient_x                                0x630E70
#define EQ_Item__GetItemValue_x                                    0x8B3B50
#define EQ_Item__ValueSellMerchant_x                               0x8B72F0
#define EQ_Item__IsKeyRingItem_x                                   0x8B5280
#define EQ_Item__CanGoInBag_x                                      0x631D20
#define EQ_Item__IsEmpty_x                                         0x8B4DE0
#define EQ_Item__GetMaxItemCount_x                                 0x8B3F70
#define EQ_Item__GetHeldItem_x                                     0x8B2680
#define EQ_Item__GetAugmentFitBySlot_x                             0x8B0630

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x562060
#define EQ_LoadingS__Array_x                                       0xC35B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x657340
#define EQ_PC__GetAlternateAbilityId_x                             0x8C04E0
#define EQ_PC__GetCombatAbility_x                                  0x8C0B50
#define EQ_PC__GetCombatAbilityTimer_x                             0x8C0BC0
#define EQ_PC__GetItemRecastTimer_x                                0x6593B0
#define EQ_PC__HasLoreItem_x                                       0x650230
#define EQ_PC__AlertInventoryChanged_x                             0x64F350
#define EQ_PC__GetPcZoneClient_x                                   0x67BE50
#define EQ_PC__RemoveMyAffect_x                                    0x65C5E0
#define EQ_PC__GetKeyRingItems_x                                   0x8C1450
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8C11E0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8C1750

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5B9B70
#define EQItemList__add_object_x                                   0x5E7420
#define EQItemList__add_item_x                                     0x5BA0D0
#define EQItemList__delete_item_x                                  0x5BA120
#define EQItemList__FreeItemList_x                                 0x5BA020

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x540520

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x66EBF0
#define EQPlayer__dEQPlayer_x                                      0x661B10
#define EQPlayer__DoAttack_x                                       0x676AF0
#define EQPlayer__EQPlayer_x                                       0x6621D0
#define EQPlayer__SetNameSpriteState_x                             0x6668D0
#define EQPlayer__SetNameSpriteTint_x                              0x6677A0
#define PlayerBase__HasProperty_j_x                                0x9A6400
#define EQPlayer__IsTargetable_x                                   0x9A68A0
#define EQPlayer__CanSee_x                                         0x9A6700
#define EQPlayer__CanSee1_x                                        0x9A67D0
#define PlayerBase__GetVisibilityLineSegment_x                     0x9A64C0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x6798F0
#define PlayerZoneClient__GetLevel_x                               0x67BE90
#define PlayerZoneClient__IsValidTeleport_x                        0x5E8590
#define PlayerZoneClient__LegalPlayerRace_x                        0x55B2E0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x6719D0
#define EQPlayerManager__GetSpawnByName_x                          0x671A80
#define EQPlayerManager__GetPlayerFromPartialName_x                0x671B10

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x6352B0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x635330
#define KeypressHandler__AttachKeyToEqCommand_x                    0x635370
#define KeypressHandler__ClearCommandStateArray_x                  0x636780
#define KeypressHandler__HandleKeyDown_x                           0x6367A0
#define KeypressHandler__HandleKeyUp_x                             0x636840
#define KeypressHandler__SaveKeymapping_x                          0x636C90

// MapViewMap 
#define MapViewMap__Clear_x                                        0x78C9E0
#define MapViewMap__SaveEx_x                                       0x78FDA0
#define MapViewMap__SetZoom_x                                      0x794460

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8D48D0

// StringTable 
#define StringTable__getString_x                                   0x8CF8A0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x65C250
#define PcZoneClient__RemovePetEffect_x                            0x65C880
#define PcZoneClient__HasAlternateAbility_x                        0x656630
#define PcZoneClient__GetCurrentMod_x                              0x4E4810
#define PcZoneClient__GetModCap_x                                  0x4E4710
#define PcZoneClient__CanEquipItem_x                               0x656CE0
#define PcZoneClient__GetItemByID_x                                0x659820
#define PcZoneClient__GetItemByItemClass_x                         0x659970
#define PcZoneClient__RemoveBuffEffect_x                           0x65C8A0
#define PcZoneClient__BandolierSwap_x                              0x6578F0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x659350

//Doors
#define EQSwitch__UseSwitch_x                                      0x5ED110

//IconCache
#define IconCache__GetIcon_x                                       0x72E180

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x725C70
#define CContainerMgr__CloseContainer_x                            0x725F40
#define CContainerMgr__OpenExperimentContainer_x                   0x7269C0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7E4D10

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x629DC0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x782E80
#define CLootWnd__RequestLootSlot_x                                0x7820B0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x586C20
#define EQ_Spell__SpellAffects_x                                   0x587090
#define EQ_Spell__SpellAffectBase_x                                0x586E50
#define EQ_Spell__IsStackable_x                                    0x4C9470
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C92C0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6840
#define EQ_Spell__IsSPAStacking_x                                  0x587EE0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x5873F0
#define EQ_Spell__IsNoRemove_x                                     0x4C9450
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x587EF0
#define __IsResEffectSpell_x                                       0x4C8640

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4ACDA0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8DED60

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x82BE20
#define CTargetWnd__WndNotification_x                              0x82B660
#define CTargetWnd__RefreshTargetBuffs_x                           0x82B930
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x82A7D0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x830430

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x53DF90
#define CTaskManager__HandleMessage_x                              0x53C420
#define CTaskManager__GetTaskStatus_x                              0x53E040
#define CTaskManager__GetElementDescription_x                      0x53E0C0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x581DF0
#define EqSoundManager__PlayScriptMp3_x                            0x5820B0
#define EqSoundManager__SoundAssistPlay_x                          0x6942C0
#define EqSoundManager__WaveInstancePlay_x                         0x693830

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52F6E0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x962280

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x569C30
#define CAltAbilityData__GetMercMaxRank_x                          0x569BC0
#define CAltAbilityData__GetMaxRank_x                              0x55EF70

//CTargetRing
#define CTargetRing__Cast_x                                        0x627EF0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C92A0
#define CharacterBase__CreateItemGlobalIndex_x                     0x5168D0
#define CharacterBase__CreateItemIndex_x                           0x630000
#define CharacterBase__GetItemPossession_x                         0x5026D0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8E73A0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8E7400
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x70CAA0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x70D2D0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x70D380

//messages
#define msg_spell_worn_off_x                                       0x5AB7B0
#define msg_new_text_x                                             0x5A0550
#define __msgTokenTextParam_x                                      0x5ADCE0
#define msgTokenText_x                                             0x5ADF30

//SpellManager
#define SpellManager__vftable_x                                    0xAF97D8
#define SpellManager__SpellManager_x                               0x6975F0
#define Spellmanager__LoadTextSpells_x                             0x697EE0
#define SpellManager__GetSpellByGroupAndRank_x                     0x6977C0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9AA2D0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x516F50
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B1A90
#define ItemGlobalIndex__IsEquippedLocation_x                      0x648920
#define ItemGlobalIndex__IsValidIndex_x                            0x516FB0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8DF700
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8DF980

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x77B6F0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x72A380
#define CCursorAttachment__AttachToCursor1_x                       0x72A3C0
#define CCursorAttachment__Deactivate_x                            0x72B3B0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x954F60
#define CSidlManagerBase__CreatePageWnd_x                          0x954750
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x9509D0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x950960

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x971EF0
#define CEQSuiteTextureLoader__GetTexture_x                        0x971BB0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x513F70
#define CFindItemWnd__WndNotification_x                            0x514A50
#define CFindItemWnd__Update_x                                     0x5155C0
#define CFindItemWnd__PickupSelectedItem_x                         0x5137B0

//IString
#define IString__Append_x                                          0x4F3960

//Camera
#define CDisplay__cameraType_x                                     0xE0F24C
#define EverQuest__Cameras_x                                       0xECA574

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51C710
#define LootFiltersManager__GetItemFilterData_x                    0x51C010
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51C040
#define LootFiltersManager__SetItemLootFilter_x                    0x51C260

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7D2CC0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9AFEB0
#define CResolutionHandler__GetWindowedStyle_x                     0x68EF40

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x722920

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8F4BC0
#define CDistillerInfo__Instance_x                                 0x8F4B60

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x7419B0
#define CGroupWnd__UpdateDisplay_x                                 0x740D00

//ItemBase
#define ItemBase__IsLore_x                                         0x8B5330
#define ItemBase__IsLoreEquipped_x                                 0x8B53B0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5E7380
#define EQPlacedItemManager__GetItemByGuid_x                       0x5E74C0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5E7520

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6845D0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x687F60

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50A270

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F66A0
#define FactionManagerClient__HandleFactionMessage_x               0x4F6D10
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F72D0
#define FactionManagerClient__GetMaxFaction_x                      0x4F72EF
#define FactionManagerClient__GetMinFaction_x                      0x4F72A0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x5026A0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x9397A0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BC40

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x502950

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x5690E0

//CTargetManager
#define CTargetManager__Get_x                                      0x69AE50

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6845D0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8A70

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5B9FC0

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
