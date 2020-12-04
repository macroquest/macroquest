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
#define __ExpectedVersionDate                                     "Nov 27 2020"
#define __ExpectedVersionTime                                     "04:20:03"
#define __ActualVersionDate_x                                      0xAF6554
#define __ActualVersionTime_x                                      0xAF6548
#define __ActualVersionBuild_x                                     0xAE4574

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x643DF0
#define __MemChecker1_x                                            0x8F7800
#define __MemChecker2_x                                            0x6B4540
#define __MemChecker3_x                                            0x6B4490
#define __MemChecker4_x                                            0x84DB90
#define __EncryptPad0_x                                            0xC2C9C8
#define __EncryptPad1_x                                            0xC8A210
#define __EncryptPad2_x                                            0xC3CD90
#define __EncryptPad3_x                                            0xC3C990
#define __EncryptPad4_x                                            0xC7A7A0
#define __EncryptPad5_x                                            0xF4D0E0
#define __AC1_x                                                    0x80C436
#define __AC2_x                                                    0x5FD53F
#define __AC3_x                                                    0x604B90
#define __AC4_x                                                    0x608B40
#define __AC5_x                                                    0x60EE3F
#define __AC6_x                                                    0x6132F6
#define __AC7_x                                                    0x5FCFB0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1912F0

// Direct Input
#define DI8__Main_x                                                0xF4D108
#define DI8__Keyboard_x                                            0xF4D10C
#define DI8__Mouse_x                                               0xF4D0EC
#define DI8__Mouse_Copy_x                                          0xEA59E4
#define DI8__Mouse_Check_x                                         0xF4AC34
#define __AutoSkillArray_x                                         0xEA6900
#define __Attack_x                                                 0xF4472F
#define __Autofire_x                                               0xF44730
#define __BindList_x                                               0xC1B400
#define g_eqCommandStates_x                                        0xC1C180
#define __Clicks_x                                                 0xEA5A9C
#define __CommandList_x                                            0xC1CD40
#define __CurrentMapLabel_x                                        0xF5D14C
#define __CurrentSocial_x                                          0xC047D4
#define __DoAbilityList_x                                          0xEDC250
#define __do_loot_x                                                0x5C8F90
#define __DrawHandler_x                                            0x15DC140
#define __GroupCount_x                                             0xE9E502
#define __Guilds_x                                                 0xEA4920
#define __gWorld_x                                                 0xE9EC98
#define __HWnd_x                                                   0xF4D0F0
#define __heqmain_x                                                0xF4D0C8
#define __InChatMode_x                                             0xEA59CC
#define __LastTell_x                                               0xEA794C
#define __LMouseHeldTime_x                                         0xEA5B08
#define __Mouse_x                                                  0xF4D0F4
#define __MouseLook_x                                              0xEA5A62
#define __MouseEventTime_x                                         0xF45214
#define __gpbCommandEvent_x                                        0xE9E758
#define __NetStatusToggle_x                                        0xEA5A65
#define __PCNames_x                                                0xEA6EFC
#define __RangeAttackReady_x                                       0xEA6BE4
#define __RMouseHeldTime_x                                         0xEA5B04
#define __RunWalkState_x                                           0xEA59D0
#define __ScreenMode_x                                             0xDEC4B0
#define __ScreenX_x                                                0xEA5984
#define __ScreenY_x                                                0xEA5980
#define __ScreenXMax_x                                             0xEA5988
#define __ScreenYMax_x                                             0xEA598C
#define __ServerHost_x                                             0xE9E923
#define __ServerName_x                                             0xEDC210
#define __ShiftKeyDown_x                                           0xEA6060
#define __ShowNames_x                                              0xEA6DA0
#define EverQuestInfo__bSocialChanged_x                            0xEDC298
#define __Socials_x                                                0xEDC310
#define __SubscriptionType_x                                       0xFA1410
#define __TargetAggroHolder_x                                      0xF5FB00
#define __ZoneType_x                                               0xEA5E60
#define __GroupAggro_x                                             0xF5FB40
#define __LoginName_x                                              0xF4A8C4
#define __Inviter_x                                                0xF446AC
#define __AttackOnAssist_x                                         0xEA6D5C
#define __UseTellWindows_x                                         0xEA7094
#define __gfMaxZoomCameraDistance_x                                0xAEE170
#define __gfMaxCameraDistance_x                                    0xB16DF0
#define __pulAutoRun_x                                             0xEA5A80
#define __pulForward_x                                             0xEA70CC
#define __pulBackward_x                                            0xEA70D0
#define __pulTurnRight_x                                           0xEA70D4
#define __pulTurnLeft_x                                            0xEA70D8
#define __pulStrafeLeft_x                                          0xEA70DC
#define __pulStrafeRight_x                                         0xEA70E0

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEA0CB8
#define instEQZoneInfo_x                                           0xEA5C58
#define pinstActiveBanker_x                                        0xE9EC44
#define pinstActiveCorpse_x                                        0xE9EC3C
#define pinstActiveGMaster_x                                       0xE9EC40
#define pinstActiveMerchant_x                                      0xE9EC38
#define pinstAltAdvManager_x                                       0xDECEF0
#define pinstBandageTarget_x                                       0xE9EC54
#define pinstCamActor_x                                            0xDEC49C
#define pinstCDBStr_x                                              0xDEBC0C
#define pinstCDisplay_x                                            0xE9ECA4
#define pinstCEverQuest_x                                          0xF4A188
#define pinstEverQuestInfo_x                                       0xEA5978
#define pinstCharData_x                                            0xE9E744
#define pinstCharSpawn_x                                           0xE9EC8C
#define pinstControlledMissile_x                                   0xE9ECA0
#define pinstControlledPlayer_x                                    0xE9EC8C
#define pinstCResolutionHandler_x                                  0x15DC370
#define pinstCSidlManager_x                                        0x15DB308
#define pinstCXWndManager_x                                        0x15DB304
#define instDynamicZone_x                                          0xEA47F8
#define pinstDZMember_x                                            0xEA4908
#define pinstDZTimerInfo_x                                         0xEA490C
#define pinstEqLogin_x                                             0xF4A210
#define instEQMisc_x                                               0xDEBB50
#define pinstEQSoundManager_x                                      0xDEDEC0
#define pinstEQSpellStrings_x                                      0xCAE448
#define instExpeditionLeader_x                                     0xEA4842
#define instExpeditionName_x                                       0xEA4882
#define pinstGroup_x                                               0xE9E4FE
#define pinstImeManager_x                                          0x15DB300
#define pinstLocalPlayer_x                                         0xE9EC34
#define pinstMercenaryData_x                                       0xF46D08
#define pinstMercenaryStats_x                                      0xF5FBCC
#define pinstModelPlayer_x                                         0xE9EC4C
#define pinstPCData_x                                              0xE9E744
#define pinstSkillMgr_x                                            0xF48E68
#define pinstSpawnManager_x                                        0xF47910
#define pinstSpellManager_x                                        0xF490A8
#define pinstSpellSets_x                                           0xF3D358
#define pinstStringTable_x                                         0xE9E748
#define pinstSwitchManager_x                                       0xE9E258
#define pinstTarget_x                                              0xE9EC88
#define pinstTargetObject_x                                        0xE9EC94
#define pinstTargetSwitch_x                                        0xE9ECAC
#define pinstTaskMember_x                                          0xDEB9E0
#define pinstTrackTarget_x                                         0xE9EC90
#define pinstTradeTarget_x                                         0xE9EC48
#define instTributeActive_x                                        0xDEBB71
#define pinstViewActor_x                                           0xDEC498
#define pinstWorldData_x                                           0xE9E3A8
#define pinstZoneAddr_x                                            0xEA5EF8
#define pinstPlayerPath_x                                          0xF479A8
#define pinstTargetIndicator_x                                     0xF49310
#define EQObject_Top_x                                             0xE9EA2C
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDEBF3C
#define pinstCAchievementsWnd_x                                    0xDEC454
#define pinstCActionsWnd_x                                         0xDEBF78
#define pinstCAdvancedDisplayOptionsWindow_x                       0xDEC514
#define pinstCAdvancedLootWnd_x                                    0xDEC4C4
#define pinstCAdventureLeaderboardWnd_x                            0xF56920
#define pinstCAdventureRequestWnd_x                                0xF569D0
#define pinstCAdventureStatsWnd_x                                  0xF56A80
#define pinstCAggroMeterWnd_x                                      0xDEC4F8
#define pinstCAlarmWnd_x                                           0xDEC480
#define pinstCAlertHistoryWnd_x                                    0xDEBEEC
#define pinstCAlertStackWnd_x                                      0xDEC4E0
#define pinstCAlertWnd_x                                           0xDEC4F4
#define pinstCAltStorageWnd_x                                      0xF56DE0
#define pinstCAudioTriggersWindow_x                                0xCA0778
#define pinstCAuraWnd_x                                            0xDEC4C8
#define pinstCAvaZoneWnd_x                                         0xDEBEF0
#define pinstCBandolierWnd_x                                       0xDEC50C
#define pinstCBankWnd_x                                            0xDEBCB0
#define pinstCBarterMerchantWnd_x                                  0xF58020
#define pinstCBarterSearchWnd_x                                    0xF580D0
#define pinstCBarterWnd_x                                          0xF58180
#define pinstCBazaarConfirmationWnd_x                              0xDEC490
#define pinstCBazaarSearchWnd_x                                    0xDEBF40
#define pinstCBazaarWnd_x                                          0xDEC45C
#define pinstCBlockedBuffWnd_x                                     0xDEC4D4
#define pinstCBlockedPetBuffWnd_x                                  0xDEC4FC
#define pinstCBodyTintWnd_x                                        0xDEC404
#define pinstCBookWnd_x                                            0xDEC544
#define pinstCBreathWnd_x                                          0xDEBF50
#define pinstCBuffWindowNORMAL_x                                   0xDEC4BC
#define pinstCBuffWindowSHORT_x                                    0xDEC4C0
#define pinstCBugReportWnd_x                                       0xDEBCAC
#define pinstCButtonWnd_x                                          0x15DB570
#define pinstCCastingWnd_x                                         0xDEC538
#define pinstCCastSpellWnd_x                                       0xDEBF4C
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDEC410
#define pinstCChatWindowManager_x                                  0xF58C40
#define pinstCClaimWnd_x                                           0xF58D98
#define pinstCColorPickerWnd_x                                     0xDEBF04
#define pinstCCombatAbilityWnd_x                                   0xDEC46C
#define pinstCCombatSkillsSelectWnd_x                              0xDEC424
#define pinstCCompassWnd_x                                         0xDEBF7C
#define pinstCConfirmationDialog_x                                 0xF5DC98
#define pinstCContainerMgr_x                                       0xDEC400
#define pinstCContextMenuManager_x                                 0x15DB2C0
#define pinstCCursorAttachment_x                                   0xDEC520
#define pinstCDynamicZoneWnd_x                                     0xF59360
#define pinstCEditLabelWnd_x                                       0xDEC4A8
#define pinstCEQMainWnd_x                                          0xF595A8
#define pinstCEventCalendarWnd_x                                   0xDEBF44
#define pinstCExtendedTargetWnd_x                                  0xDEC4D8
#define pinstCPlayerCustomizationWnd_x                             0xDEC428
#define pinstCFactionWnd_x                                         0xDEC448
#define pinstCFellowshipWnd_x                                      0xF597A8
#define pinstCFileSelectionWnd_x                                   0xDEBF00
#define pinstCFindItemWnd_x                                        0xDEC43C
#define pinstCFindLocationWnd_x                                    0xF59900
#define pinstCFriendsWnd_x                                         0xDEC438
#define pinstCGemsGameWnd_x                                        0xDEC444
#define pinstCGiveWnd_x                                            0xDEC484
#define pinstCGroupSearchFiltersWnd_x                              0xDEC510
#define pinstCGroupSearchWnd_x                                     0xF59CF8
#define pinstCGroupWnd_x                                           0xF59DA8
#define pinstCGuildBankWnd_x                                       0xF59E58
#define pinstCGuildCreationWnd_x                                   0xF59F08
#define pinstCGuildMgmtWnd_x                                       0xF59FB8
#define pinstCharacterCreation_x                                   0xDEC430
#define pinstCHelpWnd_x                                            0xDEC47C
#define pinstCHeritageSelectionWnd_x                               0xDEC434
#define pinstCHotButtonWnd_x                                       0xF5C110
#define pinstCHotButtonWnd1_x                                      0xF5C110
#define pinstCHotButtonWnd2_x                                      0xF5C114
#define pinstCHotButtonWnd3_x                                      0xF5C118
#define pinstCHotButtonWnd4_x                                      0xF5C11C
#define pinstCIconSelectionWnd_x                                   0xDEC51C
#define pinstCInspectWnd_x                                         0xDEC500
#define pinstCInventoryWnd_x                                       0xDEC4CC
#define pinstCInvSlotMgr_x                                         0xDEBF30
#define pinstCItemDisplayManager_x                                 0xF5C6A0
#define pinstCItemExpTransferWnd_x                                 0xF5C7D0
#define pinstCItemOverflowWnd_x                                    0xDEBF48
#define pinstCJournalCatWnd_x                                      0xDEBF1C
#define pinstCJournalNPCWnd_x                                      0xDEBEDC
#define pinstCJournalTextWnd_x                                     0xDEBEDC
#define pinstCKeyRingWnd_x                                         0xDEC534
#define pinstCLargeDialogWnd_x                                     0xF5E918
#define pinstCLayoutCopyWnd_x                                      0xF5CB20
#define pinstCLFGuildWnd_x                                         0xF5CBD0
#define pinstCLoadskinWnd_x                                        0xDEC460
#define pinstCLootFiltersCopyWnd_x                                 0xCBCEE8
#define pinstCLootFiltersWnd_x                                     0xDEC4E4
#define pinstCLootSettingsWnd_x                                    0xDEC508
#define pinstCLootWnd_x                                            0xDEBF20
#define pinstCMailAddressBookWnd_x                                 0xDEBF34
#define pinstCMailCompositionWnd_x                                 0xDEBF0C
#define pinstCMailIgnoreListWnd_x                                  0xDEBF38
#define pinstCMailWnd_x                                            0xDEBEF8
#define pinstCManageLootWnd_x                                      0xDED3A0
#define pinstCMapToolbarWnd_x                                      0xDEC488
#define pinstCMapViewWnd_x                                         0xDEC450
#define pinstCMarketplaceWnd_x                                     0xDEC4E8
#define pinstCMerchantWnd_x                                        0xDEBF2C
#define pinstCMIZoneSelectWnd_x                                    0xF5D408
#define pinstCMusicPlayerWnd_x                                     0xDEBCCC
#define pinstCNameChangeMercWnd_x                                  0xDEC48C
#define pinstCNameChangePetWnd_x                                   0xDEC458
#define pinstCNameChangeWnd_x                                      0xDEC4A0
#define pinstCNoteWnd_x                                            0xDEC464
#define pinstCObjectPreviewWnd_x                                   0xDEC504
#define pinstCOptionsWnd_x                                         0xDEC474
#define pinstCPetInfoWnd_x                                         0xDEBEF4
#define pinstCPetitionQWnd_x                                       0xDEC420
#define pinstCPlayerNotesWnd_x                                     0xDEC408
#define pinstCPlayerWnd_x                                          0xDEBEE8
#define pinstCPopupWndManager_x                                    0xF5DC98
#define pinstCProgressionSelectionWnd_x                            0xF5DD48
#define pinstCPurchaseGroupWnd_x                                   0xDEBCC0
#define pinstCPurchaseWnd_x                                        0xDEC53C
#define pinstCPvPLeaderboardWnd_x                                  0xF5DDF8
#define pinstCPvPStatsWnd_x                                        0xF5DEA8
#define pinstCQuantityWnd_x                                        0xDEBED8
#define pinstCRaceChangeWnd_x                                      0xDEC4D0
#define pinstCRaidOptionsWnd_x                                     0xDEC518
#define pinstCRaidWnd_x                                            0xDEBF28
#define pinstCRealEstateItemsWnd_x                                 0xDEC44C
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDEBFF8
#define pinstCRealEstateManageWnd_x                                0xDEBCC4
#define pinstCRealEstateNeighborhoodWnd_x                          0xDEBEE4
#define pinstCRealEstatePlotSearchWnd_x                            0xDEBEFC
#define pinstCRealEstatePurchaseWnd_x                              0xDEBF18
#define pinstCRespawnWnd_x                                         0xDEC4F0
#define pinstCRewardSelectionWnd_x                                 0xF5E5F0
#define pinstCSelectorWnd_x                                        0xDEC41C
#define pinstCSendMoneyWnd_x                                       0xDEC494
#define pinstCServerListWnd_x                                      0xDEBF24
#define pinstCSkillsSelectWnd_x                                    0xDEC418
#define pinstCSkillsWnd_x                                          0xDEBFF4
#define pinstCSocialEditWnd_x                                      0xDEC52C
#define pinstCSocialWnd_x                                          0xDEC478
#define pinstCSpellBookWnd_x                                       0xDEC468
#define pinstCStoryWnd_x                                           0xDEBF74
#define pinstCTargetOfTargetWnd_x                                  0xF5FC50
#define pinstCTargetWnd_x                                          0xDEC4EC
#define pinstCTaskOverlayWnd_x                                     0xDEBCB4
#define pinstCTaskSelectWnd_x                                      0xF5FDA8
#define pinstCTaskManager_x                                        0xCBD828
#define pinstCTaskTemplateSelectWnd_x                              0xF5FE58
#define pinstCTaskWnd_x                                            0xF5FF08
#define pinstCTextEntryWnd_x                                       0xDEC540
#define pinstCTimeLeftWnd_x                                        0xDEC414
#define pinstCTipWndCONTEXT_x                                      0xF6010C
#define pinstCTipWndOFDAY_x                                        0xF60108
#define pinstCTitleWnd_x                                           0xF601B8
#define pinstCTrackingWnd_x                                        0xDEC4DC
#define pinstCTradeskillWnd_x                                      0xF60320
#define pinstCTradeWnd_x                                           0xDEC40C
#define pinstCTrainWnd_x                                           0xDEBF10
#define pinstCTributeBenefitWnd_x                                  0xF60520
#define pinstCTributeMasterWnd_x                                   0xF605D0
#define pinstCTributeTrophyWnd_x                                   0xF60680
#define pinstCVideoModesWnd_x                                      0xDEBCB8
#define pinstCVoiceMacroWnd_x                                      0xF498C8
#define pinstCVoteResultsWnd_x                                     0xDEC440
#define pinstCVoteWnd_x                                            0xDEC42C
#define pinstCWebManager_x                                         0xF49F44
#define pinstCZoneGuideWnd_x                                       0xDEBCBC
#define pinstCZonePathWnd_x                                        0xDEBED0

#define pinstEQSuiteTextureLoader_x                                0xC8AB30
#define pinstItemIconCache_x                                       0xF59560
#define pinstLootFiltersManager_x                                  0xCBCF98
#define pinstRewardSelectionWnd_x                                  0xF5E5F0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5C4680
#define __CastRay2_x                                               0x5C46D0
#define __ConvertItemTags_x                                        0x5E03A0
#define __CleanItemTags_x                                          0x47D340
#define __DoesFileExist_x                                          0x8FA830
#define __EQGetTime_x                                              0x8F7430
#define __ExecuteCmd_x                                             0x5BCFD0
#define __FixHeading_x                                             0x98C550
#define __FlushDxKeyboard_x                                        0x6B03E0
#define __GameLoop_x                                               0x6B3710
#define __get_bearing_x                                            0x5C41E0
#define __get_melee_range_x                                        0x5C48C0
#define __GetAnimationCache_x                                      0x718CC0
#define __GetGaugeValueFromEQ_x                                    0x80A8E0
#define __GetLabelFromEQ_x                                         0x80C3C0
#define __GetXTargetType_x                                         0x98DF30
#define __HandleMouseWheel_x                                       0x6B45F0
#define __HeadingDiff_x                                            0x98C5C0
#define __HelpPath_x                                               0xF44E04
#define __LoadFrontEnd_x                                           0x6B0A20
#define __NewUIINI_x                                               0x80A5B0
#define __ProcessGameEvents_x                                      0x6251D0
#define __ProcessMouseEvent_x                                      0x624960
#define __SaveColors_x                                             0x55DA80
#define __STMLToText_x                                             0x92F9C0
#define __ToggleKeyRingItem_x                                      0x51C130
#define CMemoryMappedFile__SetFile_x                               0xA7B7F0
#define CrashDetected_x                                            0x6B24D0
#define DrawNetStatus_x                                            0x6511E0
#define Expansion_HoT_x                                            0xEA6D48
#define Teleport_Table_Size_x                                      0xE9E7E0
#define Teleport_Table_x                                           0xE9ECB0
#define Util__FastTime_x                                           0x8F7000
#define __CopyLayout_x                                             0x63F4A0
#define __WndProc_x                                                0x6B29D0
#define __ProcessKeyboardEvent_x                                   0x6B1F70

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490780
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499770
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499540
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493D10
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x493160

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x565BF0
#define AltAdvManager__IsAbilityReady_x                            0x564990
#define AltAdvManager__GetAAById_x                                 0x564D20
#define AltAdvManager__CanTrainAbility_x                           0x564D90
#define AltAdvManager__CanSeeAbility_x                             0x5650F0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CB190
#define CharacterZoneClient__HasSkill_x                            0x4D6010
#define CharacterZoneClient__MakeMeVisible_x                       0x4D7740
#define CharacterZoneClient__IsStackBlocked_x                      0x4C29D0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBE60
#define CharacterZoneClient__GetItemCountWorn_x                    0x4DA0D0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4DA1B0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4DA290
#define CharacterZoneClient__FindAffectSlot_x                      0x4C4AC0
#define CharacterZoneClient__BardCastBard_x                        0x4C74F0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF870
#define CharacterZoneClient__GetEffect_x                           0x4BBDA0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C5B30
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C5C00
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C5C50
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5DA0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5F80
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3D70
#define CharacterZoneClient__FindItemByGuid_x                      0x4D86A0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D8120

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6DA3E0
#define CBankWnd__WndNotification_x                                0x6DA1B0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E7EE0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x92D1A0
#define CButtonWnd__CButtonWnd_x                                   0x92BDB0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x707EA0
#define CChatManager__InitContextMenu_x                            0x700FD0
#define CChatManager__FreeChatWindow_x                             0x7069E0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9A70
#define CChatManager__SetLockedActiveChatWindow_x                  0x707B20
#define CChatManager__CreateChatWindow_x                           0x707020

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9BA0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x9403D0
#define CContextMenu__dCContextMenu_x                              0x940610
#define CContextMenu__AddMenuItem_x                                0x940620
#define CContextMenu__RemoveMenuItem_x                             0x940930
#define CContextMenu__RemoveAllMenuItems_x                         0x940950
#define CContextMenu__CheckMenuItem_x                              0x9409D0
#define CContextMenu__SetMenuItem_x                                0x940850
#define CContextMenu__AddSeparator_x                               0x9407B0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x940F70
#define CContextMenuManager__RemoveMenu_x                          0x940FE0
#define CContextMenuManager__PopupMenu_x                           0x9410A0
#define CContextMenuManager__Flush_x                               0x940F10
#define CContextMenuManager__GetMenu_x                             0x49BA70
#define CContextMenuManager__CreateDefaultMenu_x                   0x713630

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D2250
#define CChatService__GetFriendName_x                              0x8D2260

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x708710
#define CChatWindow__Clear_x                                       0x7099E0
#define CChatWindow__WndNotification_x                             0x70A170
#define CChatWindow__AddHistory_x                                  0x7092A0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93D830
#define CComboWnd__Draw_x                                          0x93CD20
#define CComboWnd__GetCurChoice_x                                  0x93D670
#define CComboWnd__GetListRect_x                                   0x93D1D0
#define CComboWnd__GetTextRect_x                                   0x93D8A0
#define CComboWnd__InsertChoice_x                                  0x93D360
#define CComboWnd__SetColors_x                                     0x93D330
#define CComboWnd__SetChoice_x                                     0x93D640
#define CComboWnd__GetItemCount_x                                  0x93D680
#define CComboWnd__GetCurChoiceText_x                              0x93D6C0
#define CComboWnd__GetChoiceText_x                                 0x93D690
#define CComboWnd__InsertChoiceAtIndex_x                           0x93D400

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x711050
#define CContainerWnd__vftable_x                                   0xAFF754
#define CContainerWnd__SetContainer_x                              0x7125A0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x5583E0
#define CDisplay__PreZoneMainUI_x                                  0x5583F0
#define CDisplay__CleanGameUI_x                                    0x55D840
#define CDisplay__GetClickedActor_x                                0x550840
#define CDisplay__GetUserDefinedColor_x                            0x548EB0
#define CDisplay__GetWorldFilePath_x                               0x5522B0
#define CDisplay__is3dON_x                                         0x54D4A0
#define CDisplay__ReloadUI_x                                       0x5578F0
#define CDisplay__WriteTextHD2_x                                   0x54D290
#define CDisplay__TrueDistance_x                                   0x553F70
#define CDisplay__SetViewActor_x                                   0x550160
#define CDisplay__GetFloorHeight_x                                 0x54D560
#define CDisplay__SetRenderWindow_x                                0x54BEE0
#define CDisplay__ToggleScreenshotMode_x                           0x54FC30

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x960280

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x9438C0
#define CEditWnd__EnsureCaretVisible_x                             0x945A50
#define CEditWnd__GetCaretPt_x                                     0x944A30
#define CEditWnd__GetCharIndexPt_x                                 0x9447E0
#define CEditWnd__GetDisplayString_x                               0x944690
#define CEditWnd__GetHorzOffset_x                                  0x942F70
#define CEditWnd__GetLineForPrintableChar_x                        0x945950
#define CEditWnd__GetSelStartPt_x                                  0x944A90
#define CEditWnd__GetSTMLSafeText_x                                0x9444B0
#define CEditWnd__PointFromPrintableChar_x                         0x945590
#define CEditWnd__SelectableCharFromPoint_x                        0x945700
#define CEditWnd__SetEditable_x                                    0x944B50
#define CEditWnd__SetWindowTextA_x                                 0x944230
#define CEditWnd__ReplaceSelection_x                               0x945210
#define CEditWnd__ReplaceSelection1_x                              0x945190

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x6127D0
#define CEverQuest__ClickedPlayer_x                                0x604970
#define CEverQuest__CreateTargetIndicator_x                        0x622340
#define CEverQuest__DeleteTargetIndicator_x                        0x6223D0
#define CEverQuest__DoTellWindow_x                                 0x4E9C80
#define CEverQuest__OutputTextToLog_x                              0x4E9F50
#define CEverQuest__DropHeldItemOnGround_x                         0x5F9AC0
#define CEverQuest__dsp_chat_x                                     0x4EA2E0
#define CEverQuest__trimName_x                                     0x61E4F0
#define CEverQuest__Emote_x                                        0x613030
#define CEverQuest__EnterZone_x                                    0x60D130
#define CEverQuest__GetBodyTypeDesc_x                              0x617A80
#define CEverQuest__GetClassDesc_x                                 0x6180C0
#define CEverQuest__GetClassThreeLetterCode_x                      0x6186C0
#define CEverQuest__GetDeityDesc_x                                 0x620B90
#define CEverQuest__GetLangDesc_x                                  0x618880
#define CEverQuest__GetRaceDesc_x                                  0x6180A0
#define CEverQuest__InterpretCmd_x                                 0x621160
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FDC60
#define CEverQuest__LMouseUp_x                                     0x5FBFE0
#define CEverQuest__RightClickedOnPlayer_x                         0x5FE540
#define CEverQuest__RMouseUp_x                                     0x5FCF70
#define CEverQuest__SetGameState_x                                 0x5F9850
#define CEverQuest__UPCNotificationFlush_x                         0x61E3F0
#define CEverQuest__IssuePetCommand_x                              0x619C90
#define CEverQuest__ReportSuccessfulHit_x                          0x614380

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x722C90
#define CGaugeWnd__CalcLinesFillRect_x                             0x722CF0
#define CGaugeWnd__Draw_x                                          0x722320

// CGuild
#define CGuild__FindMemberByName_x                                 0x4B0110
#define CGuild__GetGuildName_x                                     0x4AEBC0
#define CGuild__GetGuildIndex_x                                    0x4AF1C0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73C950

//CHotButton
#define CHotButton__SetCheck_x                                     0x6339C0
#define CHotButton__SetButtonSize_x                                0x633D80

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x749BA0
#define CInvSlotMgr__MoveItem_x                                    0x748870
#define CInvSlotMgr__SelectSlot_x                                  0x749C70

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7470A0
#define CInvSlot__SliderComplete_x                                 0x744DE0
#define CInvSlot__GetItemBase_x                                    0x744760
#define CInvSlot__UpdateItem_x                                     0x7448D0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x74B6F0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x74A890
#define CInvSlotWnd__HandleLButtonUp_x                             0x74B270

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x805C60
#define CItemDisplayWnd__UpdateStrings_x                           0x759E70
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x753B90
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x7540A0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x75A480
#define CItemDisplayWnd__AboutToShow_x                             0x759AC0
#define CItemDisplayWnd__WndNotification_x                         0x75B700
#define CItemDisplayWnd__RequestConvertItem_x                      0x75B030
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x758B30
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x7598E0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x836760

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75FC30

// CLabel 
#define CLabel__Draw_x                                             0x765660

// CListWnd
#define CListWnd__CListWnd_x                                       0x916140
#define CListWnd__dCListWnd_x                                      0x916460
#define CListWnd__AddColumn_x                                      0x91A8E0
#define CListWnd__AddColumn1_x                                     0x91A930
#define CListWnd__AddLine_x                                        0x91ACC0
#define CListWnd__AddString_x                                      0x91AAC0
#define CListWnd__CalculateFirstVisibleLine_x                      0x91A6A0
#define CListWnd__CalculateVSBRange_x                              0x91A480
#define CListWnd__ClearSel_x                                       0x91B4A0
#define CListWnd__ClearAllSel_x                                    0x91B500
#define CListWnd__CloseAndUpdateEditWindow_x                       0x91BF20
#define CListWnd__Compare_x                                        0x919DB0
#define CListWnd__Draw_x                                           0x916590
#define CListWnd__DrawColumnSeparators_x                           0x918D80
#define CListWnd__DrawHeader_x                                     0x9191F0
#define CListWnd__DrawItem_x                                       0x9196F0
#define CListWnd__DrawLine_x                                       0x918EF0
#define CListWnd__DrawSeparator_x                                  0x918E20
#define CListWnd__EnableLine_x                                     0x918660
#define CListWnd__EnsureVisible_x                                  0x91BE40
#define CListWnd__ExtendSel_x                                      0x91B3D0
#define CListWnd__GetColumnTooltip_x                               0x9181A0
#define CListWnd__GetColumnMinWidth_x                              0x918210
#define CListWnd__GetColumnWidth_x                                 0x918110
#define CListWnd__GetCurSel_x                                      0x917AA0
#define CListWnd__GetItemAtPoint_x                                 0x9188E0
#define CListWnd__GetItemAtPoint1_x                                0x918950
#define CListWnd__GetItemData_x                                    0x917B20
#define CListWnd__GetItemHeight_x                                  0x917EE0
#define CListWnd__GetItemIcon_x                                    0x917CB0
#define CListWnd__GetItemRect_x                                    0x918750
#define CListWnd__GetItemText_x                                    0x917B60
#define CListWnd__GetSelList_x                                     0x91B550
#define CListWnd__GetSeparatorRect_x                               0x918B90
#define CListWnd__InsertLine_x                                     0x91B0B0
#define CListWnd__RemoveLine_x                                     0x91B200
#define CListWnd__SetColors_x                                      0x91A450
#define CListWnd__SetColumnJustification_x                         0x91A180
#define CListWnd__SetColumnLabel_x                                 0x91AA60
#define CListWnd__SetColumnWidth_x                                 0x91A0A0
#define CListWnd__SetCurSel_x                                      0x91B310
#define CListWnd__SetItemColor_x                                   0x91BAF0
#define CListWnd__SetItemData_x                                    0x91BAB0
#define CListWnd__SetItemText_x                                    0x91B6C0
#define CListWnd__ShiftColumnSeparator_x                           0x91A240
#define CListWnd__Sort_x                                           0x919F30
#define CListWnd__ToggleSel_x                                      0x91B340
#define CListWnd__SetColumnsSizable_x                              0x91A2F0
#define CListWnd__SetItemWnd_x                                     0x91B970
#define CListWnd__GetItemWnd_x                                     0x917D00
#define CListWnd__SetItemIcon_x                                    0x91B740
#define CListWnd__CalculateCustomWindowPositions_x                 0x91A7A0
#define CListWnd__SetVScrollPos_x                                  0x91A080

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x77AD30
#define CMapViewWnd__GetWorldCoordinates_x                         0x779440
#define CMapViewWnd__HandleLButtonDown_x                           0x776480

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x79B0C0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79B9A0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79BED0
#define CMerchantWnd__SelectRecoverySlot_x                         0x79EE70
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x799C30
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A4A40
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x79ACD0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89FC70
#define CPacketScrambler__hton_x                                   0x89FC60

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x934FA0
#define CSidlManager__FindScreenPieceTemplate_x                    0x9353B0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9351A0
#define CSidlManager__CreateLabel_x                                0x7FCE30
#define CSidlManager__CreateXWndFromTemplate_x                     0x938310
#define CSidlManager__CreateXWndFromTemplate1_x                    0x9384F0
#define CSidlManager__CreateXWnd_x                                 0x7FCD60
#define CSidlManager__CreateHotButtonWnd_x                         0x7FD330

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x931A90
#define CSidlScreenWnd__CalculateVSBRange_x                        0x931990
#define CSidlScreenWnd__ConvertToRes_x                             0x95ADC0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x931480
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x931170
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x931240
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x931310
#define CSidlScreenWnd__DrawSidlPiece_x                            0x931F30
#define CSidlScreenWnd__EnableIniStorage_x                         0x932400
#define CSidlScreenWnd__GetSidlPiece_x                             0x932120
#define CSidlScreenWnd__Init1_x                                    0x930D70
#define CSidlScreenWnd__LoadIniInfo_x                              0x932450
#define CSidlScreenWnd__LoadIniListWnd_x                           0x932F80
#define CSidlScreenWnd__LoadSidlScreen_x                           0x930180
#define CSidlScreenWnd__StoreIniInfo_x                             0x932B00
#define CSidlScreenWnd__StoreIniVis_x                              0x932E60
#define CSidlScreenWnd__WndNotification_x                          0x931E40
#define CSidlScreenWnd__GetChildItem_x                             0x932380
#define CSidlScreenWnd__HandleLButtonUp_x                          0x921D10
#define CSidlScreenWnd__m_layoutCopy_x                             0x15DB190

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x699720
#define CSkillMgr__GetSkillCap_x                                   0x699900
#define CSkillMgr__GetNameToken_x                                  0x698EA0
#define CSkillMgr__IsActivatedSkill_x                              0x698FE0
#define CSkillMgr__IsCombatSkill_x                                 0x698F20

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x941D50
#define CSliderWnd__SetValue_x                                     0x941BC0
#define CSliderWnd__SetNumTicks_x                                  0x941C20

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x802FF0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x94A660
#define CStmlWnd__ParseSTML_x                                      0x94B970
#define CStmlWnd__CalculateHSBRange_x                              0x94B740
#define CStmlWnd__CalculateVSBRange_x                              0x94B6B0
#define CStmlWnd__CanBreakAtCharacter_x                            0x94FA80
#define CStmlWnd__FastForwardToEndOfTag_x                          0x950710
#define CStmlWnd__ForceParseNow_x                                  0x94AC00
#define CStmlWnd__GetNextTagPiece_x                                0x94F9E0
#define CStmlWnd__GetSTMLText_x                                    0x50D5D0
#define CStmlWnd__GetVisibleText_x                                 0x94AC20
#define CStmlWnd__InitializeWindowVariables_x                      0x950560
#define CStmlWnd__MakeStmlColorTag_x                               0x949CD0
#define CStmlWnd__MakeWndNotificationTag_x                         0x949D40
#define CStmlWnd__SetSTMLText_x                                    0x948D80
#define CStmlWnd__StripFirstSTMLLines_x                            0x951810
#define CStmlWnd__UpdateHistoryString_x                            0x950920

// CTabWnd 
#define CTabWnd__Draw_x                                            0x947ED0
#define CTabWnd__DrawCurrentPage_x                                 0x948600
#define CTabWnd__DrawTab_x                                         0x948320
#define CTabWnd__GetCurrentPage_x                                  0x9476D0
#define CTabWnd__GetPageInnerRect_x                                0x947910
#define CTabWnd__GetTabInnerRect_x                                 0x947850
#define CTabWnd__GetTabRect_x                                      0x947700
#define CTabWnd__InsertPage_x                                      0x947B20
#define CTabWnd__RemovePage_x                                      0x947C90
#define CTabWnd__SetPage_x                                         0x947990
#define CTabWnd__SetPageRect_x                                     0x947E10
#define CTabWnd__UpdatePage_x                                      0x9481E0
#define CTabWnd__GetPageFromTabIndex_x                             0x948260
#define CTabWnd__GetCurrentTabIndex_x                              0x9476C0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x760060
#define CPageWnd__SetTabText_x                                     0x947210
#define CPageWnd__FlashTab_x                                       0x947270

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A94C0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91EC10
#define CTextureFont__GetTextExtent_x                              0x91EDD0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AD8A0
#define CHtmlComponentWnd__ValidateUri_x                           0x73E340
#define CHtmlWnd__SetClientCallbacks_x                             0x638E20
#define CHtmlWnd__AddObserver_x                                    0x638E40
#define CHtmlWnd__RemoveObserver_x                                 0x638EA0
#define Window__getProgress_x                                      0x8551A0
#define Window__getStatus_x                                        0x8551C0
#define Window__getURI_x                                           0x8551D0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x957BD0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x90BB80

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9960
#define CXStr__CXStr1_x                                            0x508630
#define CXStr__CXStr3_x                                            0x8F33F0
#define CXStr__dCXStr_x                                            0x478490
#define CXStr__operator_equal_x                                    0x8F3620
#define CXStr__operator_equal1_x                                   0x8F3660
#define CXStr__operator_plus_equal1_x                              0x8F40F0
#define CXStr__SetString_x                                         0x8F5FE0
#define CXStr__operator_char_p_x                                   0x8F3B30
#define CXStr__GetChar_x                                           0x8F5910
#define CXStr__Delete_x                                            0x8F51E0
#define CXStr__GetUnicode_x                                        0x8F5980
#define CXStr__GetLength_x                                         0x47D6F0
#define CXStr__Mid_x                                               0x47D700
#define CXStr__Insert_x                                            0x8F59E0
#define CXStr__FindNext_x                                          0x8F5650

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93FFF0
#define CXWnd__BringToTop_x                                        0x925430
#define CXWnd__Center_x                                            0x924FB0
#define CXWnd__ClrFocus_x                                          0x924DC0
#define CXWnd__Destroy_x                                           0x924E70
#define CXWnd__DoAllDrawing_x                                      0x9214C0
#define CXWnd__DrawChildren_x                                      0x921490
#define CXWnd__DrawColoredRect_x                                   0x921920
#define CXWnd__DrawTooltip_x                                       0x91FFE0
#define CXWnd__DrawTooltipAtPoint_x                                0x9200A0
#define CXWnd__GetBorderFrame_x                                    0x921780
#define CXWnd__GetChildWndAt_x                                     0x9254D0
#define CXWnd__GetClientClipRect_x                                 0x923720
#define CXWnd__GetScreenClipRect_x                                 0x9237F0
#define CXWnd__GetScreenRect_x                                     0x9239C0
#define CXWnd__GetRelativeRect_x                                   0x923A80
#define CXWnd__GetTooltipRect_x                                    0x921970
#define CXWnd__GetWindowTextA_x                                    0x93C6B0
#define CXWnd__IsActive_x                                          0x922090
#define CXWnd__IsDescendantOf_x                                    0x924390
#define CXWnd__IsReallyVisible_x                                   0x9243C0
#define CXWnd__IsType_x                                            0x925B40
#define CXWnd__Move_x                                              0x924420
#define CXWnd__Move1_x                                             0x9244D0
#define CXWnd__ProcessTransition_x                                 0x924F60
#define CXWnd__Refade_x                                            0x924790
#define CXWnd__Resize_x                                            0x924A30
#define CXWnd__Right_x                                             0x9251F0
#define CXWnd__SetFocus_x                                          0x924D80
#define CXWnd__SetFont_x                                           0x924DF0
#define CXWnd__SetKeyTooltip_x                                     0x925960
#define CXWnd__SetMouseOver_x                                      0x9228B0
#define CXWnd__StartFade_x                                         0x924270
#define CXWnd__GetChildItem_x                                      0x925640
#define CXWnd__SetParent_x                                         0x924120
#define CXWnd__Minimize_x                                          0x924A90

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x95BE40

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9282E0
#define CXWndManager__DrawWindows_x                                0x928300
#define CXWndManager__GetKeyboardFlags_x                           0x92AA20
#define CXWndManager__HandleKeyboardMsg_x                          0x92A5D0
#define CXWndManager__RemoveWnd_x                                  0x92AC50
#define CXWndManager__RemovePendingDeletionWnd_x                   0x92B1D0

// CDBStr
#define CDBStr__GetString_x                                        0x547E70

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BFFD0
#define EQ_Character__Cur_HP_x                                     0x4D3050
#define EQ_Character__Cur_Mana_x                                   0x4DA790
#define EQ_Character__GetCastingTimeModifier_x                     0x4C3040
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B39B0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3B00
#define EQ_Character__GetHPRegen_x                                 0x4E0690
#define EQ_Character__GetEnduranceRegen_x                          0x4E0C90
#define EQ_Character__GetManaRegen_x                               0x4E10D0
#define EQ_Character__Max_Endurance_x                              0x65F8A0
#define EQ_Character__Max_HP_x                                     0x4D2E80
#define EQ_Character__Max_Mana_x                                   0x65F6A0
#define EQ_Character__doCombatAbility_x                            0x661C90
#define EQ_Character__UseSkill_x                                   0x4E2ED0
#define EQ_Character__GetConLevel_x                                0x6581B0
#define EQ_Character__IsExpansionFlag_x                            0x5BB7E0
#define EQ_Character__TotalEffect_x                                0x4C6DE0
#define EQ_Character__GetPCSpellAffect_x                           0x4C3D90
#define EQ_Character__SpellDuration_x                              0x4C38C0
#define EQ_Character__MySpellDuration_x                            0x4B22E0
#define EQ_Character__GetAdjustedSkill_x                           0x4D5DD0
#define EQ_Character__GetBaseSkill_x                               0x4D6D70
#define EQ_Character__CanUseItem_x                                 0x4DAAA0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BF250

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x675BF0

//PcClient
#define PcClient__vftable_x                                        0xAF31C0
#define PcClient__PcClient_x                                       0x655920

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BAA10
#define CCharacterListWnd__EnterWorld_x                            0x4BA3E0
#define CCharacterListWnd__Quit_x                                  0x4BA130
#define CCharacterListWnd__UpdateList_x                            0x4BA5D0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x639FE0
#define EQ_Item__CreateItemTagString_x                             0x899150
#define EQ_Item__IsStackable_x                                     0x89DEA0
#define EQ_Item__GetImageNum_x                                     0x89AD00
#define EQ_Item__CreateItemClient_x                                0x639220
#define EQ_Item__GetItemValue_x                                    0x89C010
#define EQ_Item__ValueSellMerchant_x                               0x89F850
#define EQ_Item__IsKeyRingItem_x                                   0x89D750
#define EQ_Item__CanGoInBag_x                                      0x63A100
#define EQ_Item__IsEmpty_x                                         0x89D290
#define EQ_Item__GetMaxItemCount_x                                 0x89C420
#define EQ_Item__GetHeldItem_x                                     0x89ABD0
#define EQ_Item__GetAugmentFitBySlot_x                             0x8989B0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x5668C0
#define EQ_LoadingS__Array_x                                       0xC14130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x6601A0
#define EQ_PC__GetAlternateAbilityId_x                             0x8A8B40
#define EQ_PC__GetCombatAbility_x                                  0x8A91B0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A9220
#define EQ_PC__GetItemRecastTimer_x                                0x662210
#define EQ_PC__HasLoreItem_x                                       0x6589D0
#define EQ_PC__AlertInventoryChanged_x                             0x657AF0
#define EQ_PC__GetPcZoneClient_x                                   0x684D40
#define EQ_PC__RemoveMyAffect_x                                    0x665430
#define EQ_PC__GetKeyRingItems_x                                   0x8A9AF0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A9870
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A9DF0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5C1BD0
#define EQItemList__add_object_x                                   0x5EF1F0
#define EQItemList__add_item_x                                     0x5C2130
#define EQItemList__delete_item_x                                  0x5C2180
#define EQItemList__FreeItemList_x                                 0x5C2080

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x5449F0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x6774F0
#define EQPlayer__dEQPlayer_x                                      0x66A860
#define EQPlayer__DoAttack_x                                       0x67F4E0
#define EQPlayer__EQPlayer_x                                       0x66AF20
#define EQPlayer__SetNameSpriteState_x                             0x66F200
#define EQPlayer__SetNameSpriteTint_x                              0x6700E0
#define PlayerBase__HasProperty_j_x                                0x98A960
#define EQPlayer__IsTargetable_x                                   0x98AE00
#define EQPlayer__CanSee_x                                         0x98AC60
#define EQPlayer__CanSee1_x                                        0x98AD30
#define PlayerBase__GetVisibilityLineSegment_x                     0x98AA20

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x6827E0
#define PlayerZoneClient__GetLevel_x                               0x684D80
#define PlayerZoneClient__IsValidTeleport_x                        0x5F0360
#define PlayerZoneClient__LegalPlayerRace_x                        0x55F6D0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x67A3E0
#define EQPlayerManager__GetSpawnByName_x                          0x67A490
#define EQPlayerManager__GetPlayerFromPartialName_x                0x67A520

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63D700
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63D780
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63D7C0
#define KeypressHandler__ClearCommandStateArray_x                  0x63EBB0
#define KeypressHandler__HandleKeyDown_x                           0x63EBD0
#define KeypressHandler__HandleKeyUp_x                             0x63EC70
#define KeypressHandler__SaveKeymapping_x                          0x63F0C0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x776BA0
#define MapViewMap__SaveEx_x                                       0x779F60
#define MapViewMap__SetZoom_x                                      0x77E620

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BD2B0

// StringTable 
#define StringTable__getString_x                                   0x8B8150

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x6650A0
#define PcZoneClient__RemovePetEffect_x                            0x6656D0
#define PcZoneClient__HasAlternateAbility_x                        0x65F4D0
#define PcZoneClient__GetCurrentMod_x                              0x4E5FF0
#define PcZoneClient__GetModCap_x                                  0x4E5EF0
#define PcZoneClient__CanEquipItem_x                               0x65FB80
#define PcZoneClient__GetItemByID_x                                0x662680
#define PcZoneClient__GetItemByItemClass_x                         0x6627D0
#define PcZoneClient__RemoveBuffEffect_x                           0x6656F0
#define PcZoneClient__BandolierSwap_x                              0x660760
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x6621B0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F4EE0

//IconCache
#define IconCache__GetIcon_x                                       0x7186C0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x7101F0
#define CContainerMgr__CloseContainer_x                            0x7104C0
#define CContainerMgr__OpenExperimentContainer_x                   0x710F40

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CF4E0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x632180

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76D0E0
#define CLootWnd__RequestLootSlot_x                                0x76C3C0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58E3E0
#define EQ_Spell__SpellAffects_x                                   0x58E850
#define EQ_Spell__SpellAffectBase_x                                0x58E610
#define EQ_Spell__IsStackable_x                                    0x4CAAA0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CA8F0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7C90
#define EQ_Spell__IsSPAStacking_x                                  0x58F6A0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58EBB0
#define EQ_Spell__IsNoRemove_x                                     0x4CAA80
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58F6B0
#define __IsResEffectSpell_x                                       0x4C9E30

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD680

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C7880

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x816340
#define CTargetWnd__WndNotification_x                              0x815B80
#define CTargetWnd__RefreshTargetBuffs_x                           0x815E50
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x814CF0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x81A9B0
#define CTaskWnd__ConfirmAbandonTask_x                             0x81D5F0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x5423E0
#define CTaskManager__HandleMessage_x                              0x540850
#define CTaskManager__GetTaskStatus_x                              0x542490
#define CTaskManager__GetElementDescription_x                      0x542510

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x589450
#define EqSoundManager__PlayScriptMp3_x                            0x589710
#define EqSoundManager__SoundAssistPlay_x                          0x69D680
#define EqSoundManager__WaveInstancePlay_x                         0x69CBF0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x5337B0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x946710
#define CTextureAnimation__Draw_x                                  0x946910

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x9426B0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56E3C0
#define CAltAbilityData__GetMercMaxRank_x                          0x56E350
#define CAltAbilityData__GetMaxRank_x                              0x563810

//CTargetRing
#define CTargetRing__Cast_x                                        0x6302A0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA8D0
#define CharacterBase__CreateItemGlobalIndex_x                     0x51A1E0
#define CharacterBase__CreateItemIndex_x                           0x6383D0
#define CharacterBase__GetItemPossession_x                         0x505F20
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CFF00
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CFF60
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F71C0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F79F0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F7AA0

//messages
#define msg_spell_worn_off_x                                       0x5B3810
#define msg_new_text_x                                             0x5A81A0
#define __msgTokenTextParam_x                                      0x5B5AA0
#define msgTokenText_x                                             0x5B5CF0

//SpellManager
#define SpellManager__vftable_x                                    0xADB534
#define SpellManager__SpellManager_x                               0x6A09A0
#define Spellmanager__LoadTextSpells_x                             0x6A1290
#define SpellManager__GetSpellByGroupAndRank_x                     0x6A0B70

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98E820

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x51A890
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B9D10
#define ItemGlobalIndex__IsEquippedLocation_x                      0x651040
#define ItemGlobalIndex__IsValidIndex_x                            0x51A920

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C8240
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C83D0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x7659A0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x7148D0
#define CCursorAttachment__AttachToCursor1_x                       0x714910
#define CCursorAttachment__Deactivate_x                            0x7158F0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x939350
#define CSidlManagerBase__CreatePageWnd_x                          0x938B40
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x934DC0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x934D50

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9564D0
#define CEQSuiteTextureLoader__GetTexture_x                        0x956190

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x5174D0
#define CFindItemWnd__WndNotification_x                            0x518110
#define CFindItemWnd__Update_x                                     0x518C80
#define CFindItemWnd__PickupSelectedItem_x                         0x516D00

//IString
#define IString__Append_x                                          0x507740

//Camera
#define CDisplay__cameraType_x                                     0xDEBCC8
#define EverQuest__Cameras_x                                       0xEA70A0

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x520290
#define LootFiltersManager__GetItemFilterData_x                    0x51FB90
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51FBC0
#define LootFiltersManager__SetItemLootFilter_x                    0x51FDE0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BD2F0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9944E0
#define CResolutionHandler__GetWindowedStyle_x                     0x698060

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70CE90

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D3D10
#define CDistillerInfo__Instance_x                                 0x8D3CB0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72BC70
#define CGroupWnd__UpdateDisplay_x                                 0x72AFC0

//ItemBase
#define ItemBase__IsLore_x                                         0x89D800
#define ItemBase__IsLoreEquipped_x                                 0x89D870

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EF150
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EF290
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EF2F0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68D470
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x690E10

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50DBF0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4FA080
#define FactionManagerClient__HandleFactionMessage_x               0x4FA6F0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4FACF0
#define FactionManagerClient__GetMaxFaction_x                      0x4FAD0F
#define FactionManagerClient__GetMinFaction_x                      0x4FACC0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x505EF0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91DBC0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C470

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x506150

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56D860

//CTargetManager
#define CTargetManager__Get_x                                      0x6A41F0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68D470

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A9280

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5C2020

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF44734

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6C0910
#define CAAWnd__UpdateSelected_x                                   0x6BD180
#define CAAWnd__Update_x                                           0x6BFC30

//CXRect
#define CXRect__operator_and_x                                     0x722D50

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x483410

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
