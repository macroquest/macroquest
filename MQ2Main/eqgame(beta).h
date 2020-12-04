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
#define __ExpectedVersionDate                                     "Dec  2 2020"
#define __ExpectedVersionTime                                     "04:20:09"
#define __ActualVersionDate_x                                      0xAF6560
#define __ActualVersionTime_x                                      0xAF6554
#define __ActualVersionBuild_x                                     0xAE4584

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x644970
#define __MemChecker1_x                                            0x8F71B0
#define __MemChecker2_x                                            0x6B4D10
#define __MemChecker3_x                                            0x6B4C60
#define __MemChecker4_x                                            0x84D970
#define __EncryptPad0_x                                            0xC2C9C8
#define __EncryptPad1_x                                            0xC8A210
#define __EncryptPad2_x                                            0xC3CD90
#define __EncryptPad3_x                                            0xC3C990
#define __EncryptPad4_x                                            0xC7A7A0
#define __EncryptPad5_x                                            0xF4D0E0
#define __AC1_x                                                    0x80C2C6
#define __AC2_x                                                    0x5FE12F
#define __AC3_x                                                    0x605780
#define __AC4_x                                                    0x609730
#define __AC5_x                                                    0x60FA2F
#define __AC6_x                                                    0x613EE6
#define __AC7_x                                                    0x5FDBA0
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
#define __do_loot_x                                                0x5C9B80
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
#define __gfMaxZoomCameraDistance_x                                0xAEE180
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
#define __CastRay_x                                                0x5C5270
#define __CastRay2_x                                               0x5C52C0
#define __ConvertItemTags_x                                        0x5E0F80
#define __CleanItemTags_x                                          0x47D190
#define __DoesFileExist_x                                          0x8FA1E0
#define __EQGetTime_x                                              0x8F6DD0
#define __ExecuteCmd_x                                             0x5BDC10
#define __FixHeading_x                                             0x98C4F0
#define __FlushDxKeyboard_x                                        0x6B0BB0
#define __GameLoop_x                                               0x6B3EE0
#define __get_bearing_x                                            0x5C4DD0
#define __get_melee_range_x                                        0x5C54B0
#define __GetAnimationCache_x                                      0x719360
#define __GetGaugeValueFromEQ_x                                    0x80A770
#define __GetLabelFromEQ_x                                         0x80C250
#define __GetXTargetType_x                                         0x98DF40
#define __HandleMouseWheel_x                                       0x6B4DC0
#define __HeadingDiff_x                                            0x98C560
#define __HelpPath_x                                               0xF44E04
#define __LoadFrontEnd_x                                           0x6B11F0
#define __NewUIINI_x                                               0x80A440
#define __ProcessGameEvents_x                                      0x625DC0
#define __ProcessMouseEvent_x                                      0x625550
#define __SaveColors_x                                             0x55DBD0
#define __STMLToText_x                                             0x92F6A0
#define __ToggleKeyRingItem_x                                      0x51C320
#define CMemoryMappedFile__SetFile_x                               0xA7B8E0
#define CrashDetected_x                                            0x6B2CA0
#define DrawNetStatus_x                                            0x651BF0
#define Expansion_HoT_x                                            0xEA6D48
#define Teleport_Table_Size_x                                      0xE9E7E0
#define Teleport_Table_x                                           0xE9ECB0
#define Util__FastTime_x                                           0x8F69A0
#define __CopyLayout_x                                             0x640080
#define __WndProc_x                                                0x6B31A0
#define __ProcessKeyboardEvent_x                                   0x6B2740

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490460
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499450
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499220
#define CAdvancedLootWnd__AddPlayerToList_x                        0x4939F0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492E40

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x565DA0
#define AltAdvManager__IsAbilityReady_x                            0x564B40
#define AltAdvManager__GetAAById_x                                 0x564ED0
#define AltAdvManager__CanTrainAbility_x                           0x564F40
#define AltAdvManager__CanSeeAbility_x                             0x5652A0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CB300
#define CharacterZoneClient__HasSkill_x                            0x4D6180
#define CharacterZoneClient__MakeMeVisible_x                       0x4D78B0
#define CharacterZoneClient__IsStackBlocked_x                      0x4C2930
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBDC0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4DA220
#define CharacterZoneClient__GetItemCountInInventory_x             0x4DA300
#define CharacterZoneClient__GetCursorItemCount_x                  0x4DA3E0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C4A20
#define CharacterZoneClient__BardCastBard_x                        0x4C7450
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF7D0
#define CharacterZoneClient__GetEffect_x                           0x4BBD00
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C5A90
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C5B60
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C5BB0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5D00
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5EE0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3D30
#define CharacterZoneClient__FindItemByGuid_x                      0x4D8810
#define CharacterZoneClient__FindItemByRecord_x                    0x4D8290

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6DA9E0
#define CBankWnd__WndNotification_x                                0x6DA7B0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E8220

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x92CE90
#define CButtonWnd__CButtonWnd_x                                   0x92BA80

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x708450
#define CChatManager__InitContextMenu_x                            0x701580
#define CChatManager__FreeChatWindow_x                             0x706F90
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9BD0
#define CChatManager__SetLockedActiveChatWindow_x                  0x7080D0
#define CChatManager__CreateChatWindow_x                           0x7075D0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9CE0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x9400D0
#define CContextMenu__dCContextMenu_x                              0x940310
#define CContextMenu__AddMenuItem_x                                0x940320
#define CContextMenu__RemoveMenuItem_x                             0x940630
#define CContextMenu__RemoveAllMenuItems_x                         0x940650
#define CContextMenu__CheckMenuItem_x                              0x9406D0
#define CContextMenu__SetMenuItem_x                                0x940550
#define CContextMenu__AddSeparator_x                               0x9404B0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x940C70
#define CContextMenuManager__RemoveMenu_x                          0x940CE0
#define CContextMenuManager__PopupMenu_x                           0x940DA0
#define CContextMenuManager__Flush_x                               0x940C10
#define CContextMenuManager__GetMenu_x                             0x49B6E0
#define CContextMenuManager__CreateDefaultMenu_x                   0x713CD0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D1B00
#define CChatService__GetFriendName_x                              0x8D1B10

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x708CC0
#define CChatWindow__Clear_x                                       0x709F80
#define CChatWindow__WndNotification_x                             0x70A710
#define CChatWindow__AddHistory_x                                  0x709840

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93D520
#define CComboWnd__Draw_x                                          0x93CA20
#define CComboWnd__GetCurChoice_x                                  0x93D360
#define CComboWnd__GetListRect_x                                   0x93CED0
#define CComboWnd__GetTextRect_x                                   0x93D590
#define CComboWnd__InsertChoice_x                                  0x93D060
#define CComboWnd__SetColors_x                                     0x93D030
#define CComboWnd__SetChoice_x                                     0x93D330
#define CComboWnd__GetItemCount_x                                  0x93D370
#define CComboWnd__GetCurChoiceText_x                              0x93D3B0
#define CComboWnd__GetChoiceText_x                                 0x93D380
#define CComboWnd__InsertChoiceAtIndex_x                           0x93D0F0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x7116E0
#define CContainerWnd__vftable_x                                   0xAFF75C
#define CContainerWnd__SetContainer_x                              0x712C30

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x558530
#define CDisplay__PreZoneMainUI_x                                  0x558540
#define CDisplay__CleanGameUI_x                                    0x55D990
#define CDisplay__GetClickedActor_x                                0x550990
#define CDisplay__GetUserDefinedColor_x                            0x549010
#define CDisplay__GetWorldFilePath_x                               0x552400
#define CDisplay__is3dON_x                                         0x54D5F0
#define CDisplay__ReloadUI_x                                       0x557A40
#define CDisplay__WriteTextHD2_x                                   0x54D3E0
#define CDisplay__TrueDistance_x                                   0x5540C0
#define CDisplay__SetViewActor_x                                   0x5502B0
#define CDisplay__GetFloorHeight_x                                 0x54D6B0
#define CDisplay__SetRenderWindow_x                                0x54C030
#define CDisplay__ToggleScreenshotMode_x                           0x54FD80

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x960040

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x9435B0
#define CEditWnd__EnsureCaretVisible_x                             0x945740
#define CEditWnd__GetCaretPt_x                                     0x944720
#define CEditWnd__GetCharIndexPt_x                                 0x9444D0
#define CEditWnd__GetDisplayString_x                               0x944380
#define CEditWnd__GetHorzOffset_x                                  0x942C70
#define CEditWnd__GetLineForPrintableChar_x                        0x945640
#define CEditWnd__GetSelStartPt_x                                  0x944780
#define CEditWnd__GetSTMLSafeText_x                                0x9441A0
#define CEditWnd__PointFromPrintableChar_x                         0x945280
#define CEditWnd__SelectableCharFromPoint_x                        0x9453F0
#define CEditWnd__SetEditable_x                                    0x944840
#define CEditWnd__SetWindowTextA_x                                 0x943F20
#define CEditWnd__ReplaceSelection_x                               0x944F00
#define CEditWnd__ReplaceSelection1_x                              0x944E80

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x6133C0
#define CEverQuest__ClickedPlayer_x                                0x605560
#define CEverQuest__CreateTargetIndicator_x                        0x622F30
#define CEverQuest__DeleteTargetIndicator_x                        0x622FC0
#define CEverQuest__DoTellWindow_x                                 0x4E9DC0
#define CEverQuest__OutputTextToLog_x                              0x4EA090
#define CEverQuest__DropHeldItemOnGround_x                         0x5FA6C0
#define CEverQuest__dsp_chat_x                                     0x4EA420
#define CEverQuest__trimName_x                                     0x61F0E0
#define CEverQuest__Emote_x                                        0x613C20
#define CEverQuest__EnterZone_x                                    0x60DD20
#define CEverQuest__GetBodyTypeDesc_x                              0x618670
#define CEverQuest__GetClassDesc_x                                 0x618CB0
#define CEverQuest__GetClassThreeLetterCode_x                      0x6192B0
#define CEverQuest__GetDeityDesc_x                                 0x621780
#define CEverQuest__GetLangDesc_x                                  0x619470
#define CEverQuest__GetRaceDesc_x                                  0x618C90
#define CEverQuest__InterpretCmd_x                                 0x621D50
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FE850
#define CEverQuest__LMouseUp_x                                     0x5FCBE0
#define CEverQuest__RightClickedOnPlayer_x                         0x5FF130
#define CEverQuest__RMouseUp_x                                     0x5FDB60
#define CEverQuest__SetGameState_x                                 0x5FA450
#define CEverQuest__UPCNotificationFlush_x                         0x61EFE0
#define CEverQuest__IssuePetCommand_x                              0x61A880
#define CEverQuest__ReportSuccessfulHit_x                          0x614F70

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7232D0
#define CGaugeWnd__CalcLinesFillRect_x                             0x723330
#define CGaugeWnd__Draw_x                                          0x722960

// CGuild
#define CGuild__FindMemberByName_x                                 0x4B00A0
#define CGuild__GetGuildName_x                                     0x4AEB50
#define CGuild__GetGuildIndex_x                                    0x4AF150

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73CEE0

//CHotButton
#define CHotButton__SetCheck_x                                     0x634670
#define CHotButton__SetButtonSize_x                                0x634A30

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x74A140
#define CInvSlotMgr__MoveItem_x                                    0x748E30
#define CInvSlotMgr__SelectSlot_x                                  0x74A210

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x747620
#define CInvSlot__SliderComplete_x                                 0x745370
#define CInvSlot__GetItemBase_x                                    0x744D00
#define CInvSlot__UpdateItem_x                                     0x744E70

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x74BC80
#define CInvSlotWnd__CInvSlotWnd_x                                 0x74AE10
#define CInvSlotWnd__HandleLButtonUp_x                             0x74B800

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x805B10
#define CItemDisplayWnd__UpdateStrings_x                           0x75A320
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x753FE0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x754500
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x75A910
#define CItemDisplayWnd__AboutToShow_x                             0x759F90
#define CItemDisplayWnd__WndNotification_x                         0x75BB70
#define CItemDisplayWnd__RequestConvertItem_x                      0x75B4C0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x758FF0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x759DB0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8364B0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x760070

// CLabel 
#define CLabel__Draw_x                                             0x765B70

// CListWnd
#define CListWnd__CListWnd_x                                       0x915D00
#define CListWnd__dCListWnd_x                                      0x916020
#define CListWnd__AddColumn_x                                      0x91A470
#define CListWnd__AddColumn1_x                                     0x91A4C0
#define CListWnd__AddLine_x                                        0x91A850
#define CListWnd__AddString_x                                      0x91A650
#define CListWnd__CalculateFirstVisibleLine_x                      0x91A240
#define CListWnd__CalculateVSBRange_x                              0x91A020
#define CListWnd__ClearSel_x                                       0x91B030
#define CListWnd__ClearAllSel_x                                    0x91B090
#define CListWnd__CloseAndUpdateEditWindow_x                       0x91BA80
#define CListWnd__Compare_x                                        0x919960
#define CListWnd__Draw_x                                           0x916150
#define CListWnd__DrawColumnSeparators_x                           0x918930
#define CListWnd__DrawHeader_x                                     0x918DA0
#define CListWnd__DrawItem_x                                       0x9192A0
#define CListWnd__DrawLine_x                                       0x918AA0
#define CListWnd__DrawSeparator_x                                  0x9189D0
#define CListWnd__EnableLine_x                                     0x918210
#define CListWnd__EnsureVisible_x                                  0x91B9B0
#define CListWnd__ExtendSel_x                                      0x91AF60
#define CListWnd__GetColumnTooltip_x                               0x917D50
#define CListWnd__GetColumnMinWidth_x                              0x917DC0
#define CListWnd__GetColumnWidth_x                                 0x917CC0
#define CListWnd__GetCurSel_x                                      0x917650
#define CListWnd__GetItemAtPoint_x                                 0x918480
#define CListWnd__GetItemAtPoint1_x                                0x9184F0
#define CListWnd__GetItemData_x                                    0x9176D0
#define CListWnd__GetItemHeight_x                                  0x917A90
#define CListWnd__GetItemIcon_x                                    0x917860
#define CListWnd__GetItemRect_x                                    0x918300
#define CListWnd__GetItemText_x                                    0x917710
#define CListWnd__GetSelList_x                                     0x91B0E0
#define CListWnd__GetSeparatorRect_x                               0x918730
#define CListWnd__InsertLine_x                                     0x91AC40
#define CListWnd__RemoveLine_x                                     0x91AD90
#define CListWnd__SetColors_x                                      0x91A000
#define CListWnd__SetColumnJustification_x                         0x919D30
#define CListWnd__SetColumnLabel_x                                 0x91A5F0
#define CListWnd__SetColumnWidth_x                                 0x919C50
#define CListWnd__SetCurSel_x                                      0x91AEA0
#define CListWnd__SetItemColor_x                                   0x91B670
#define CListWnd__SetItemData_x                                    0x91B630
#define CListWnd__SetItemText_x                                    0x91B250
#define CListWnd__ShiftColumnSeparator_x                           0x919DF0
#define CListWnd__Sort_x                                           0x919AE0
#define CListWnd__ToggleSel_x                                      0x91AED0
#define CListWnd__SetColumnsSizable_x                              0x919EA0
#define CListWnd__SetItemWnd_x                                     0x91B500
#define CListWnd__GetItemWnd_x                                     0x9178B0
#define CListWnd__SetItemIcon_x                                    0x91B2D0
#define CListWnd__CalculateCustomWindowPositions_x                 0x91A330
#define CListWnd__SetVScrollPos_x                                  0x919C30

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x77B1F0
#define CMapViewWnd__GetWorldCoordinates_x                         0x779900
#define CMapViewWnd__HandleLButtonDown_x                           0x776940

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x79B490
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79BD70
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79C2A0
#define CMerchantWnd__SelectRecoverySlot_x                         0x79F250
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x79A010
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A4E10
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x79B0B0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89F640
#define CPacketScrambler__hton_x                                   0x89F630

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x934C90
#define CSidlManager__FindScreenPieceTemplate_x                    0x9350A0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x934E90
#define CSidlManager__CreateLabel_x                                0x7FCD80
#define CSidlManager__CreateXWndFromTemplate_x                     0x938000
#define CSidlManager__CreateXWndFromTemplate1_x                    0x9381D0
#define CSidlManager__CreateXWnd_x                                 0x7FCCB0
#define CSidlManager__CreateHotButtonWnd_x                         0x7FD280

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x931770
#define CSidlScreenWnd__CalculateVSBRange_x                        0x931670
#define CSidlScreenWnd__ConvertToRes_x                             0x95AB60
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x931160
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x930E50
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x930F20
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x930FF0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x931C00
#define CSidlScreenWnd__EnableIniStorage_x                         0x9320D0
#define CSidlScreenWnd__GetSidlPiece_x                             0x931DF0
#define CSidlScreenWnd__Init1_x                                    0x930A50
#define CSidlScreenWnd__LoadIniInfo_x                              0x932120
#define CSidlScreenWnd__LoadIniListWnd_x                           0x932C50
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92FE50
#define CSidlScreenWnd__StoreIniInfo_x                             0x9327D0
#define CSidlScreenWnd__StoreIniVis_x                              0x932B30
#define CSidlScreenWnd__WndNotification_x                          0x931B10
#define CSidlScreenWnd__GetChildItem_x                             0x932050
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9218B0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15DB190

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x699D80
#define CSkillMgr__GetSkillCap_x                                   0x699F60
#define CSkillMgr__GetNameToken_x                                  0x699500
#define CSkillMgr__IsActivatedSkill_x                              0x699640
#define CSkillMgr__IsCombatSkill_x                                 0x699580

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x941A50
#define CSliderWnd__SetValue_x                                     0x9418C0
#define CSliderWnd__SetNumTicks_x                                  0x941920

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x802EE0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x94A320
#define CStmlWnd__ParseSTML_x                                      0x94B660
#define CStmlWnd__CalculateHSBRange_x                              0x94B430
#define CStmlWnd__CalculateVSBRange_x                              0x94B3B0
#define CStmlWnd__CanBreakAtCharacter_x                            0x94F770
#define CStmlWnd__FastForwardToEndOfTag_x                          0x950400
#define CStmlWnd__ForceParseNow_x                                  0x94A910
#define CStmlWnd__GetNextTagPiece_x                                0x94F6D0
#define CStmlWnd__GetSTMLText_x                                    0x50D8C0
#define CStmlWnd__GetVisibleText_x                                 0x94A930
#define CStmlWnd__InitializeWindowVariables_x                      0x950250
#define CStmlWnd__MakeStmlColorTag_x                               0x949990
#define CStmlWnd__MakeWndNotificationTag_x                         0x949A00
#define CStmlWnd__SetSTMLText_x                                    0x948A40
#define CStmlWnd__StripFirstSTMLLines_x                            0x9514F0
#define CStmlWnd__UpdateHistoryString_x                            0x950610

// CTabWnd 
#define CTabWnd__Draw_x                                            0x947B90
#define CTabWnd__DrawCurrentPage_x                                 0x9482C0
#define CTabWnd__DrawTab_x                                         0x947FE0
#define CTabWnd__GetCurrentPage_x                                  0x947390
#define CTabWnd__GetPageInnerRect_x                                0x9475D0
#define CTabWnd__GetTabInnerRect_x                                 0x947510
#define CTabWnd__GetTabRect_x                                      0x9473C0
#define CTabWnd__InsertPage_x                                      0x9477E0
#define CTabWnd__RemovePage_x                                      0x947950
#define CTabWnd__SetPage_x                                         0x947650
#define CTabWnd__SetPageRect_x                                     0x947AD0
#define CTabWnd__UpdatePage_x                                      0x947EA0
#define CTabWnd__GetPageFromTabIndex_x                             0x947F20
#define CTabWnd__GetCurrentTabIndex_x                              0x947380

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x760490
#define CPageWnd__SetTabText_x                                     0x946ED0
#define CPageWnd__FlashTab_x                                       0x946F30

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9420

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91E760
#define CTextureFont__GetTextExtent_x                              0x91E920

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AE080
#define CHtmlComponentWnd__ValidateUri_x                           0x73E8F0
#define CHtmlWnd__SetClientCallbacks_x                             0x639A90
#define CHtmlWnd__AddObserver_x                                    0x639AB0
#define CHtmlWnd__RemoveObserver_x                                 0x639B10
#define Window__getProgress_x                                      0x854F90
#define Window__getStatus_x                                        0x854FB0
#define Window__getURI_x                                           0x854FC0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x957970

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x90B8F0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9A10
#define CXStr__CXStr1_x                                            0x8456B0
#define CXStr__CXStr3_x                                            0x8F2D90
#define CXStr__dCXStr_x                                            0x4783C0
#define CXStr__operator_equal_x                                    0x8F2FC0
#define CXStr__operator_equal1_x                                   0x8F3000
#define CXStr__operator_plus_equal1_x                              0x8F3A90
#define CXStr__SetString_x                                         0x8F5980
#define CXStr__operator_char_p_x                                   0x8F34D0
#define CXStr__GetChar_x                                           0x8F52B0
#define CXStr__Delete_x                                            0x8F4B80
#define CXStr__GetUnicode_x                                        0x8F5320
#define CXStr__GetLength_x                                         0x4A91D0
#define CXStr__Mid_x                                               0x47D540
#define CXStr__Insert_x                                            0x8F5380
#define CXStr__FindNext_x                                          0x8F4FF0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93FCE0
#define CXWnd__BringToTop_x                                        0x925040
#define CXWnd__Center_x                                            0x924BC0
#define CXWnd__ClrFocus_x                                          0x9249D0
#define CXWnd__Destroy_x                                           0x924A80
#define CXWnd__DoAllDrawing_x                                      0x921040
#define CXWnd__DrawChildren_x                                      0x921010
#define CXWnd__DrawColoredRect_x                                   0x9214A0
#define CXWnd__DrawTooltip_x                                       0x91FB60
#define CXWnd__DrawTooltipAtPoint_x                                0x91FC20
#define CXWnd__GetBorderFrame_x                                    0x921300
#define CXWnd__GetChildWndAt_x                                     0x9250E0
#define CXWnd__GetClientClipRect_x                                 0x9232F0
#define CXWnd__GetScreenClipRect_x                                 0x9233C0
#define CXWnd__GetScreenRect_x                                     0x923580
#define CXWnd__GetRelativeRect_x                                   0x923630
#define CXWnd__GetTooltipRect_x                                    0x9214F0
#define CXWnd__GetWindowTextA_x                                    0x49CE90
#define CXWnd__IsActive_x                                          0x921C30
#define CXWnd__IsDescendantOf_x                                    0x923F50
#define CXWnd__IsReallyVisible_x                                   0x923F80
#define CXWnd__IsType_x                                            0x925750
#define CXWnd__Move_x                                              0x924000
#define CXWnd__Move1_x                                             0x9240B0
#define CXWnd__ProcessTransition_x                                 0x924B70
#define CXWnd__Refade_x                                            0x924360
#define CXWnd__Resize_x                                            0x924600
#define CXWnd__Right_x                                             0x924E00
#define CXWnd__SetFocus_x                                          0x924990
#define CXWnd__SetFont_x                                           0x924A00
#define CXWnd__SetKeyTooltip_x                                     0x925570
#define CXWnd__SetMouseOver_x                                      0x922460
#define CXWnd__StartFade_x                                         0x923E30
#define CXWnd__GetChildItem_x                                      0x925250
#define CXWnd__SetParent_x                                         0x923CE0
#define CXWnd__Minimize_x                                          0x924670

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x95BBE0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x927F20
#define CXWndManager__DrawWindows_x                                0x927F40
#define CXWndManager__GetKeyboardFlags_x                           0x92A720
#define CXWndManager__HandleKeyboardMsg_x                          0x92A2D0
#define CXWndManager__RemoveWnd_x                                  0x92A940
#define CXWndManager__RemovePendingDeletionWnd_x                   0x92AEA0

// CDBStr
#define CDBStr__GetString_x                                        0x547FE0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BFF30
#define EQ_Character__Cur_HP_x                                     0x4D31C0
#define EQ_Character__Cur_Mana_x                                   0x4DA8E0
#define EQ_Character__GetCastingTimeModifier_x                     0x4C2FA0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B3970
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3AC0
#define EQ_Character__GetHPRegen_x                                 0x4E07B0
#define EQ_Character__GetEnduranceRegen_x                          0x4E0DB0
#define EQ_Character__GetManaRegen_x                               0x4E11F0
#define EQ_Character__Max_Endurance_x                              0x660230
#define EQ_Character__Max_HP_x                                     0x4D2FF0
#define EQ_Character__Max_Mana_x                                   0x660030
#define EQ_Character__doCombatAbility_x                            0x662620
#define EQ_Character__UseSkill_x                                   0x4E2FF0
#define EQ_Character__GetConLevel_x                                0x658B20
#define EQ_Character__IsExpansionFlag_x                            0x5BC3E0
#define EQ_Character__TotalEffect_x                                0x4C6D40
#define EQ_Character__GetPCSpellAffect_x                           0x4C3CF0
#define EQ_Character__SpellDuration_x                              0x4C3820
#define EQ_Character__MySpellDuration_x                            0x4B22A0
#define EQ_Character__GetAdjustedSkill_x                           0x4D5F40
#define EQ_Character__GetBaseSkill_x                               0x4D6EE0
#define EQ_Character__CanUseItem_x                                 0x4DABF0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BEAF0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x676580

//PcClient
#define PcClient__vftable_x                                        0xAF31DC
#define PcClient__PcClient_x                                       0x656290

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA970
#define CCharacterListWnd__EnterWorld_x                            0x4BA340
#define CCharacterListWnd__Quit_x                                  0x4BA090
#define CCharacterListWnd__UpdateList_x                            0x4BA530

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x63AC60
#define EQ_Item__CreateItemTagString_x                             0x898B40
#define EQ_Item__IsStackable_x                                     0x89D840
#define EQ_Item__GetImageNum_x                                     0x89A6A0
#define EQ_Item__CreateItemClient_x                                0x639E90
#define EQ_Item__GetItemValue_x                                    0x89B9A0
#define EQ_Item__ValueSellMerchant_x                               0x89F220
#define EQ_Item__IsKeyRingItem_x                                   0x89D0F0
#define EQ_Item__CanGoInBag_x                                      0x63AD80
#define EQ_Item__IsEmpty_x                                         0x89CC40
#define EQ_Item__GetMaxItemCount_x                                 0x89BDB0
#define EQ_Item__GetHeldItem_x                                     0x89A570
#define EQ_Item__GetAugmentFitBySlot_x                             0x8983B0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x566AA0
#define EQ_LoadingS__Array_x                                       0xC14130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x660B30
#define EQ_PC__GetAlternateAbilityId_x                             0x8A8510
#define EQ_PC__GetCombatAbility_x                                  0x8A8B80
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A8BF0
#define EQ_PC__GetItemRecastTimer_x                                0x662BA0
#define EQ_PC__HasLoreItem_x                                       0x659390
#define EQ_PC__AlertInventoryChanged_x                             0x658460
#define EQ_PC__GetPcZoneClient_x                                   0x685620
#define EQ_PC__RemoveMyAffect_x                                    0x665DC0
#define EQ_PC__GetKeyRingItems_x                                   0x8A94C0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A9240
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A97C0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5C27E0
#define EQItemList__add_object_x                                   0x5EFE50
#define EQItemList__add_item_x                                     0x5C2D40
#define EQItemList__delete_item_x                                  0x5C2D90
#define EQItemList__FreeItemList_x                                 0x5C2C90

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x544A70

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x677E80
#define EQPlayer__dEQPlayer_x                                      0x66B200
#define EQPlayer__DoAttack_x                                       0x67FDC0
#define EQPlayer__EQPlayer_x                                       0x66B8C0
#define EQPlayer__SetNameSpriteState_x                             0x66FB90
#define EQPlayer__SetNameSpriteTint_x                              0x670A70
#define PlayerBase__HasProperty_j_x                                0x98A900
#define EQPlayer__IsTargetable_x                                   0x98ADA0
#define EQPlayer__CanSee_x                                         0x98AC00
#define EQPlayer__CanSee1_x                                        0x98ACD0
#define PlayerBase__GetVisibilityLineSegment_x                     0x98A9C0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x6830C0
#define PlayerZoneClient__GetLevel_x                               0x685660
#define PlayerZoneClient__IsValidTeleport_x                        0x5F0FC0
#define PlayerZoneClient__LegalPlayerRace_x                        0x55F850

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x67ACE0
#define EQPlayerManager__GetSpawnByName_x                          0x67AD90
#define EQPlayerManager__GetPlayerFromPartialName_x                0x67AE20

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63E2E0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63E360
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63E3A0
#define KeypressHandler__ClearCommandStateArray_x                  0x63F790
#define KeypressHandler__HandleKeyDown_x                           0x63F7B0
#define KeypressHandler__HandleKeyUp_x                             0x63F850
#define KeypressHandler__SaveKeymapping_x                          0x63FCA0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x777060
#define MapViewMap__SaveEx_x                                       0x77A420
#define MapViewMap__SetZoom_x                                      0x77EAE0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BCB50

// StringTable 
#define StringTable__getString_x                                   0x8B7940

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x665A30
#define PcZoneClient__RemovePetEffect_x                            0x666060
#define PcZoneClient__HasAlternateAbility_x                        0x65FE60
#define PcZoneClient__GetCurrentMod_x                              0x4E6100
#define PcZoneClient__GetModCap_x                                  0x4E6000
#define PcZoneClient__CanEquipItem_x                               0x660510
#define PcZoneClient__GetItemByID_x                                0x663010
#define PcZoneClient__GetItemByItemClass_x                         0x663160
#define PcZoneClient__RemoveBuffEffect_x                           0x666080
#define PcZoneClient__BandolierSwap_x                              0x6610F0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x662B40

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F5B30

//IconCache
#define IconCache__GetIcon_x                                       0x718D60

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x710880
#define CContainerMgr__CloseContainer_x                            0x710B50
#define CContainerMgr__OpenExperimentContainer_x                   0x7115D0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CF590

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x632E60

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76D600
#define CLootWnd__RequestLootSlot_x                                0x76C8E0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58E4B0
#define EQ_Spell__SpellAffects_x                                   0x58E920
#define EQ_Spell__SpellAffectBase_x                                0x58E6E0
#define EQ_Spell__IsStackable_x                                    0x4CAC10
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CAA30
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7C30
#define EQ_Spell__IsSPAStacking_x                                  0x58F770
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58EC80
#define EQ_Spell__IsNoRemove_x                                     0x4CABF0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58F780
#define __IsResEffectSpell_x                                       0x4C9D80

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD5D0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C7120

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x816240
#define CTargetWnd__WndNotification_x                              0x815A80
#define CTargetWnd__RefreshTargetBuffs_x                           0x815D50
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x814BE0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x81A8A0
#define CTaskWnd__ConfirmAbandonTask_x                             0x81D4D0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x5424A0
#define CTaskManager__HandleMessage_x                              0x540900
#define CTaskManager__GetTaskStatus_x                              0x542550
#define CTaskManager__GetElementDescription_x                      0x5425D0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x589600
#define EqSoundManager__PlayScriptMp3_x                            0x5898C0
#define EqSoundManager__SoundAssistPlay_x                          0x69DCF0
#define EqSoundManager__WaveInstancePlay_x                         0x69D260

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x533870

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x9463E0
#define CTextureAnimation__Draw_x                                  0x9465E0

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x9423B0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56E550
#define CAltAbilityData__GetMercMaxRank_x                          0x56E4E0
#define CAltAbilityData__GetMaxRank_x                              0x5639C0

//CTargetRing
#define CTargetRing__Cast_x                                        0x630F80

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CAA10
#define CharacterBase__CreateItemGlobalIndex_x                     0x51A500
#define CharacterBase__CreateItemIndex_x                           0x639040
#define CharacterBase__GetItemPossession_x                         0x5062F0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CF7B0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CF810
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F7780
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F7FB0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F8060

//messages
#define msg_spell_worn_off_x                                       0x5B4300
#define msg_new_text_x                                             0x5A8C90
#define __msgTokenTextParam_x                                      0x5B65A0
#define msgTokenText_x                                             0x5B67F0

//SpellManager
#define SpellManager__vftable_x                                    0xADB54C
#define SpellManager__SpellManager_x                               0x6A1010
#define Spellmanager__LoadTextSpells_x                             0x6A1900
#define SpellManager__GetSpellByGroupAndRank_x                     0x6A11E0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98E830

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x51AB80
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5BA800
#define ItemGlobalIndex__IsEquippedLocation_x                      0x651A50
#define ItemGlobalIndex__IsValidIndex_x                            0x51AC10

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C7AE0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C7C70

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x765EB0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x714F70
#define CCursorAttachment__AttachToCursor1_x                       0x714FB0
#define CCursorAttachment__Deactivate_x                            0x715F90

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x939030
#define CSidlManagerBase__CreatePageWnd_x                          0x938820
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x934AB0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x934A40

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9565C0
#define CEQSuiteTextureLoader__GetTexture_x                        0x956280

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x517820
#define CFindItemWnd__WndNotification_x                            0x518450
#define CFindItemWnd__Update_x                                     0x518FA0
#define CFindItemWnd__PickupSelectedItem_x                         0x517050

//IString
#define IString__Append_x                                          0x507B40

//Camera
#define CDisplay__cameraType_x                                     0xDEBCC8
#define EverQuest__Cameras_x                                       0xEA70A0

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x520460
#define LootFiltersManager__GetItemFilterData_x                    0x51FD70
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51FDA0
#define LootFiltersManager__SetItemLootFilter_x                    0x51FFC0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BD430

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9943B0
#define CResolutionHandler__GetWindowedStyle_x                     0x6987B0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70D420

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D3590
#define CDistillerInfo__Instance_x                                 0x8D3530

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72C290
#define CGroupWnd__UpdateDisplay_x                                 0x72B5F0

//ItemBase
#define ItemBase__IsLore_x                                         0x89D1A0
#define ItemBase__IsLoreEquipped_x                                 0x89D210

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EFDB0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EFEF0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EFF50

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68DD30
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x6916B0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50DF70

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4FA2E0
#define FactionManagerClient__HandleFactionMessage_x               0x4FA950
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4FAF50
#define FactionManagerClient__GetMaxFaction_x                      0x4FAF6F
#define FactionManagerClient__GetMinFaction_x                      0x4FAF20

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x5062C0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91D720

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C170

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x506550

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56DA00

//CTargetManager
#define CTargetManager__Get_x                                      0x6A4890

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68DD30

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A91E0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5C2C30

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF44734

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6C1090
#define CAAWnd__UpdateSelected_x                                   0x6BD910
#define CAAWnd__Update_x                                           0x6C03C0

//CXRect
#define CXRect__operator_and_x                                     0x723390

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x483190

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
