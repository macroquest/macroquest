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
#define __ExpectedVersionDate                                     "Dec  1 2020"
#define __ExpectedVersionTime                                     "04:18:45"
#define __ActualVersionDate_x                                      0xAF6548
#define __ActualVersionTime_x                                      0xAF653C
#define __ActualVersionBuild_x                                     0xAE457C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x644180
#define __MemChecker1_x                                            0x8F6D50
#define __MemChecker2_x                                            0x6B4420
#define __MemChecker3_x                                            0x6B4370
#define __MemChecker4_x                                            0x84D260
#define __EncryptPad0_x                                            0xC2C9C8
#define __EncryptPad1_x                                            0xC8A210
#define __EncryptPad2_x                                            0xC3CD90
#define __EncryptPad3_x                                            0xC3C990
#define __EncryptPad4_x                                            0xC7A7A0
#define __EncryptPad5_x                                            0xF4D0E0
#define __AC1_x                                                    0x80BB76
#define __AC2_x                                                    0x5FD99F
#define __AC3_x                                                    0x604FF0
#define __AC4_x                                                    0x608FA0
#define __AC5_x                                                    0x60F29F
#define __AC6_x                                                    0x613756
#define __AC7_x                                                    0x5FD410
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
#define __do_loot_x                                                0x5C9370
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
#define __gfMaxZoomCameraDistance_x                                0xAEE178
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
#define __CastRay_x                                                0x5C4A60
#define __CastRay2_x                                               0x5C4AB0
#define __ConvertItemTags_x                                        0x5E0770
#define __CleanItemTags_x                                          0x47D1F0
#define __DoesFileExist_x                                          0x8F9E00
#define __EQGetTime_x                                              0x8F6980
#define __ExecuteCmd_x                                             0x5BD3E0
#define __FixHeading_x                                             0x98C230
#define __FlushDxKeyboard_x                                        0x6B02C0
#define __GameLoop_x                                               0x6B35F0
#define __get_bearing_x                                            0x5C45C0
#define __get_melee_range_x                                        0x5C4CA0
#define __GetAnimationCache_x                                      0x7189E0
#define __GetGaugeValueFromEQ_x                                    0x80A020
#define __GetLabelFromEQ_x                                         0x80BB00
#define __GetXTargetType_x                                         0x98DC80
#define __HandleMouseWheel_x                                       0x6B44D0
#define __HeadingDiff_x                                            0x98C2A0
#define __HelpPath_x                                               0xF44E04
#define __LoadFrontEnd_x                                           0x6B0900
#define __NewUIINI_x                                               0x809CF0
#define __ProcessGameEvents_x                                      0x625630
#define __ProcessMouseEvent_x                                      0x624DC0
#define __SaveColors_x                                             0x55DDD0
#define __STMLToText_x                                             0x92F6B0
#define __ToggleKeyRingItem_x                                      0x51C630
#define CMemoryMappedFile__SetFile_x                               0xA7B600
#define CrashDetected_x                                            0x6B23B0
#define DrawNetStatus_x                                            0x6513B0
#define Expansion_HoT_x                                            0xEA6D48
#define Teleport_Table_Size_x                                      0xE9E7E0
#define Teleport_Table_x                                           0xE9ECB0
#define Util__FastTime_x                                           0x8F6550
#define __CopyLayout_x                                             0x63F890
#define __WndProc_x                                                0x6B28B0
#define __ProcessKeyboardEvent_x                                   0x6B1E50

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4904F0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4994E0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4992B0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493A80
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492ED0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x566050
#define AltAdvManager__IsAbilityReady_x                            0x564DF0
#define AltAdvManager__GetAAById_x                                 0x565180
#define AltAdvManager__CanTrainAbility_x                           0x5651F0
#define AltAdvManager__CanSeeAbility_x                             0x565550

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CB0D0
#define CharacterZoneClient__HasSkill_x                            0x4D5F50
#define CharacterZoneClient__MakeMeVisible_x                       0x4D7680
#define CharacterZoneClient__IsStackBlocked_x                      0x4C2740
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBBD0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9FF0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4DA0D0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4DA1B0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C4830
#define CharacterZoneClient__BardCastBard_x                        0x4C7260
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF5E0
#define CharacterZoneClient__GetEffect_x                           0x4BBB10
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C58A0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C5970
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C59C0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5B10
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5CF0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3B70
#define CharacterZoneClient__FindItemByGuid_x                      0x4D85E0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D8060

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6DA140
#define CBankWnd__WndNotification_x                                0x6D9F10

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E7A40

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x92CE90
#define CButtonWnd__CButtonWnd_x                                   0x92BA90

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x707C20
#define CChatManager__InitContextMenu_x                            0x700D50
#define CChatManager__FreeChatWindow_x                             0x706760
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9900
#define CChatManager__SetLockedActiveChatWindow_x                  0x7078A0
#define CChatManager__CreateChatWindow_x                           0x706DA0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9A10

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x940080
#define CContextMenu__dCContextMenu_x                              0x9402C0
#define CContextMenu__AddMenuItem_x                                0x9402D0
#define CContextMenu__RemoveMenuItem_x                             0x9405E0
#define CContextMenu__RemoveAllMenuItems_x                         0x940600
#define CContextMenu__CheckMenuItem_x                              0x940680
#define CContextMenu__SetMenuItem_x                                0x940500
#define CContextMenu__AddSeparator_x                               0x940460

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x940C20
#define CContextMenuManager__RemoveMenu_x                          0x940C90
#define CContextMenuManager__PopupMenu_x                           0x940D50
#define CContextMenuManager__Flush_x                               0x940BC0
#define CContextMenuManager__GetMenu_x                             0x49B810
#define CContextMenuManager__CreateDefaultMenu_x                   0x713360

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x899B10
#define CChatService__GetFriendName_x                              0x8D16C0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x708460
#define CChatWindow__Clear_x                                       0x709720
#define CChatWindow__WndNotification_x                             0x709EB0
#define CChatWindow__AddHistory_x                                  0x708FE0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93D4D0
#define CComboWnd__Draw_x                                          0x93C9D0
#define CComboWnd__GetCurChoice_x                                  0x93D310
#define CComboWnd__GetListRect_x                                   0x93CE80
#define CComboWnd__GetTextRect_x                                   0x93D540
#define CComboWnd__InsertChoice_x                                  0x93D010
#define CComboWnd__SetColors_x                                     0x93CFE0
#define CComboWnd__SetChoice_x                                     0x93D2E0
#define CComboWnd__GetItemCount_x                                  0x93D320
#define CComboWnd__GetCurChoiceText_x                              0x93D360
#define CComboWnd__GetChoiceText_x                                 0x93D330
#define CComboWnd__InsertChoiceAtIndex_x                           0x93D0A0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x710D60
#define CContainerWnd__vftable_x                                   0xAFF754
#define CContainerWnd__SetContainer_x                              0x7122C0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x558730
#define CDisplay__PreZoneMainUI_x                                  0x558740
#define CDisplay__CleanGameUI_x                                    0x55DB90
#define CDisplay__GetClickedActor_x                                0x550B90
#define CDisplay__GetUserDefinedColor_x                            0x549210
#define CDisplay__GetWorldFilePath_x                               0x552600
#define CDisplay__is3dON_x                                         0x54D7F0
#define CDisplay__ReloadUI_x                                       0x557C40
#define CDisplay__WriteTextHD2_x                                   0x54D5E0
#define CDisplay__TrueDistance_x                                   0x5542C0
#define CDisplay__SetViewActor_x                                   0x5504B0
#define CDisplay__GetFloorHeight_x                                 0x54D8B0
#define CDisplay__SetRenderWindow_x                                0x54C230
#define CDisplay__ToggleScreenshotMode_x                           0x54FF80

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x95FE90

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x943590
#define CEditWnd__EnsureCaretVisible_x                             0x945760
#define CEditWnd__GetCaretPt_x                                     0x944710
#define CEditWnd__GetCharIndexPt_x                                 0x9444C0
#define CEditWnd__GetDisplayString_x                               0x944360
#define CEditWnd__GetHorzOffset_x                                  0x942C40
#define CEditWnd__GetLineForPrintableChar_x                        0x945660
#define CEditWnd__GetSelStartPt_x                                  0x944770
#define CEditWnd__GetSTMLSafeText_x                                0x944180
#define CEditWnd__PointFromPrintableChar_x                         0x945290
#define CEditWnd__SelectableCharFromPoint_x                        0x945400
#define CEditWnd__SetEditable_x                                    0x944840
#define CEditWnd__SetWindowTextA_x                                 0x943F00
#define CEditWnd__ReplaceSelection_x                               0x944F00
#define CEditWnd__ReplaceSelection1_x                              0x944E80

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x612C30
#define CEverQuest__ClickedPlayer_x                                0x604DD0
#define CEverQuest__CreateTargetIndicator_x                        0x6227A0
#define CEverQuest__DeleteTargetIndicator_x                        0x622830
#define CEverQuest__DoTellWindow_x                                 0x4E9AF0
#define CEverQuest__OutputTextToLog_x                              0x4E9DC0
#define CEverQuest__DropHeldItemOnGround_x                         0x5F9F30
#define CEverQuest__dsp_chat_x                                     0x4EA150
#define CEverQuest__trimName_x                                     0x61E950
#define CEverQuest__Emote_x                                        0x613490
#define CEverQuest__EnterZone_x                                    0x60D590
#define CEverQuest__GetBodyTypeDesc_x                              0x617EE0
#define CEverQuest__GetClassDesc_x                                 0x618520
#define CEverQuest__GetClassThreeLetterCode_x                      0x618B20
#define CEverQuest__GetDeityDesc_x                                 0x620FF0
#define CEverQuest__GetLangDesc_x                                  0x618CE0
#define CEverQuest__GetRaceDesc_x                                  0x618500
#define CEverQuest__InterpretCmd_x                                 0x6215C0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FE0C0
#define CEverQuest__LMouseUp_x                                     0x5FC450
#define CEverQuest__RightClickedOnPlayer_x                         0x5FE9A0
#define CEverQuest__RMouseUp_x                                     0x5FD3D0
#define CEverQuest__SetGameState_x                                 0x5F9CC0
#define CEverQuest__UPCNotificationFlush_x                         0x61E850
#define CEverQuest__IssuePetCommand_x                              0x61A0F0
#define CEverQuest__ReportSuccessfulHit_x                          0x6147E0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x722910
#define CGaugeWnd__CalcLinesFillRect_x                             0x722970
#define CGaugeWnd__Draw_x                                          0x721F90

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AFEF0
#define CGuild__GetGuildName_x                                     0x4AE9A0
#define CGuild__GetGuildIndex_x                                    0x4AEFA0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73C600

//CHotButton
#define CHotButton__SetCheck_x                                     0x633D90
#define CHotButton__SetButtonSize_x                                0x634150

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x7497E0
#define CInvSlotMgr__MoveItem_x                                    0x748500
#define CInvSlotMgr__SelectSlot_x                                  0x7498B0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x746CF0
#define CInvSlot__SliderComplete_x                                 0x744A40
#define CInvSlot__GetItemBase_x                                    0x7443D0
#define CInvSlot__UpdateItem_x                                     0x744540

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x74B320
#define CInvSlotWnd__CInvSlotWnd_x                                 0x74A4B0
#define CInvSlotWnd__HandleLButtonUp_x                             0x74AEA0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x805360
#define CItemDisplayWnd__UpdateStrings_x                           0x759960
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x753620
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x753B30
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x759F50
#define CItemDisplayWnd__AboutToShow_x                             0x7595B0
#define CItemDisplayWnd__WndNotification_x                         0x75B1A0
#define CItemDisplayWnd__RequestConvertItem_x                      0x75AAF0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x758610
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x7593D0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x835E60

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75F6B0

// CLabel 
#define CLabel__Draw_x                                             0x765160

// CListWnd
#define CListWnd__CListWnd_x                                       0x915E50
#define CListWnd__dCListWnd_x                                      0x916170
#define CListWnd__AddColumn_x                                      0x91A5E0
#define CListWnd__AddColumn1_x                                     0x91A630
#define CListWnd__AddLine_x                                        0x91A9C0
#define CListWnd__AddString_x                                      0x91A7C0
#define CListWnd__CalculateFirstVisibleLine_x                      0x91A3A0
#define CListWnd__CalculateVSBRange_x                              0x91A180
#define CListWnd__ClearSel_x                                       0x91B1A0
#define CListWnd__ClearAllSel_x                                    0x91B200
#define CListWnd__CloseAndUpdateEditWindow_x                       0x91BC20
#define CListWnd__Compare_x                                        0x919AC0
#define CListWnd__Draw_x                                           0x9162A0
#define CListWnd__DrawColumnSeparators_x                           0x918A90
#define CListWnd__DrawHeader_x                                     0x918F00
#define CListWnd__DrawItem_x                                       0x919400
#define CListWnd__DrawLine_x                                       0x918C00
#define CListWnd__DrawSeparator_x                                  0x918B30
#define CListWnd__EnableLine_x                                     0x918360
#define CListWnd__EnsureVisible_x                                  0x91BB40
#define CListWnd__ExtendSel_x                                      0x91B0D0
#define CListWnd__GetColumnTooltip_x                               0x917EA0
#define CListWnd__GetColumnMinWidth_x                              0x917F10
#define CListWnd__GetColumnWidth_x                                 0x917E10
#define CListWnd__GetCurSel_x                                      0x9177A0
#define CListWnd__GetItemAtPoint_x                                 0x9185E0
#define CListWnd__GetItemAtPoint1_x                                0x918650
#define CListWnd__GetItemData_x                                    0x917820
#define CListWnd__GetItemHeight_x                                  0x917BE0
#define CListWnd__GetItemIcon_x                                    0x9179B0
#define CListWnd__GetItemRect_x                                    0x918450
#define CListWnd__GetItemText_x                                    0x917860
#define CListWnd__GetSelList_x                                     0x91B250
#define CListWnd__GetSeparatorRect_x                               0x918890
#define CListWnd__InsertLine_x                                     0x91ADB0
#define CListWnd__RemoveLine_x                                     0x91AF00
#define CListWnd__SetColors_x                                      0x91A160
#define CListWnd__SetColumnJustification_x                         0x919E90
#define CListWnd__SetColumnLabel_x                                 0x91A760
#define CListWnd__SetColumnWidth_x                                 0x919DB0
#define CListWnd__SetCurSel_x                                      0x91B010
#define CListWnd__SetItemColor_x                                   0x91B7F0
#define CListWnd__SetItemData_x                                    0x91B7B0
#define CListWnd__SetItemText_x                                    0x91B3C0
#define CListWnd__ShiftColumnSeparator_x                           0x919F50
#define CListWnd__Sort_x                                           0x919C40
#define CListWnd__ToggleSel_x                                      0x91B040
#define CListWnd__SetColumnsSizable_x                              0x91A000
#define CListWnd__SetItemWnd_x                                     0x91B670
#define CListWnd__GetItemWnd_x                                     0x917A00
#define CListWnd__SetItemIcon_x                                    0x91B440
#define CListWnd__CalculateCustomWindowPositions_x                 0x91A4A0
#define CListWnd__SetVScrollPos_x                                  0x919D90

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x77A7C0
#define CMapViewWnd__GetWorldCoordinates_x                         0x778ED0
#define CMapViewWnd__HandleLButtonDown_x                           0x775F10

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x79AAF0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79B3D0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79B900
#define CMerchantWnd__SelectRecoverySlot_x                         0x79E8B0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x799670
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A4470
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x79A710

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89F250
#define CPacketScrambler__hton_x                                   0x89F240

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x934C90
#define CSidlManager__FindScreenPieceTemplate_x                    0x9350A0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x934E90
#define CSidlManager__CreateLabel_x                                0x7FC5A0
#define CSidlManager__CreateXWndFromTemplate_x                     0x938000
#define CSidlManager__CreateXWndFromTemplate1_x                    0x9381D0
#define CSidlManager__CreateXWnd_x                                 0x7FC4D0
#define CSidlManager__CreateHotButtonWnd_x                         0x7FCA90

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x931760
#define CSidlScreenWnd__CalculateVSBRange_x                        0x931660
#define CSidlScreenWnd__ConvertToRes_x                             0x95A9E0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x931150
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x930E40
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x930F10
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x930FE0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x931C00
#define CSidlScreenWnd__EnableIniStorage_x                         0x9320D0
#define CSidlScreenWnd__GetSidlPiece_x                             0x931DF0
#define CSidlScreenWnd__Init1_x                                    0x930A40
#define CSidlScreenWnd__LoadIniInfo_x                              0x932120
#define CSidlScreenWnd__LoadIniListWnd_x                           0x932C60
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92FE60
#define CSidlScreenWnd__StoreIniInfo_x                             0x9327E0
#define CSidlScreenWnd__StoreIniVis_x                              0x932B40
#define CSidlScreenWnd__WndNotification_x                          0x931B10
#define CSidlScreenWnd__GetChildItem_x                             0x932050
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9219B0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15DB190

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x699650
#define CSkillMgr__GetSkillCap_x                                   0x699830
#define CSkillMgr__GetNameToken_x                                  0x698DD0
#define CSkillMgr__IsActivatedSkill_x                              0x698F10
#define CSkillMgr__IsCombatSkill_x                                 0x698E50

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x941A20
#define CSliderWnd__SetValue_x                                     0x941890
#define CSliderWnd__SetNumTicks_x                                  0x9418F0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x8026E0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x94A360
#define CStmlWnd__ParseSTML_x                                      0x94B670
#define CStmlWnd__CalculateHSBRange_x                              0x94B440
#define CStmlWnd__CalculateVSBRange_x                              0x94B3B0
#define CStmlWnd__CanBreakAtCharacter_x                            0x94F780
#define CStmlWnd__FastForwardToEndOfTag_x                          0x950410
#define CStmlWnd__ForceParseNow_x                                  0x94A900
#define CStmlWnd__GetNextTagPiece_x                                0x94F6E0
#define CStmlWnd__GetSTMLText_x                                    0x50D9D0
#define CStmlWnd__GetVisibleText_x                                 0x94A920
#define CStmlWnd__InitializeWindowVariables_x                      0x950260
#define CStmlWnd__MakeStmlColorTag_x                               0x9499D0
#define CStmlWnd__MakeWndNotificationTag_x                         0x949A40
#define CStmlWnd__SetSTMLText_x                                    0x948A80
#define CStmlWnd__StripFirstSTMLLines_x                            0x951510
#define CStmlWnd__UpdateHistoryString_x                            0x950620

// CTabWnd 
#define CTabWnd__Draw_x                                            0x947BD0
#define CTabWnd__DrawCurrentPage_x                                 0x948300
#define CTabWnd__DrawTab_x                                         0x948020
#define CTabWnd__GetCurrentPage_x                                  0x9473D0
#define CTabWnd__GetPageInnerRect_x                                0x947610
#define CTabWnd__GetTabInnerRect_x                                 0x947550
#define CTabWnd__GetTabRect_x                                      0x947400
#define CTabWnd__InsertPage_x                                      0x947820
#define CTabWnd__RemovePage_x                                      0x947990
#define CTabWnd__SetPage_x                                         0x947690
#define CTabWnd__SetPageRect_x                                     0x947B10
#define CTabWnd__UpdatePage_x                                      0x947EE0
#define CTabWnd__GetPageFromTabIndex_x                             0x947F60
#define CTabWnd__GetCurrentTabIndex_x                              0x9473C0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x75FB50
#define CPageWnd__SetTabText_x                                     0x946F10
#define CPageWnd__FlashTab_x                                       0x946F70

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A92A0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91E8A0
#define CTextureFont__GetTextExtent_x                              0x91EA60

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AD760
#define CHtmlComponentWnd__ValidateUri_x                           0x73DFF0
#define CHtmlWnd__SetClientCallbacks_x                             0x6391B0
#define CHtmlWnd__AddObserver_x                                    0x6391D0
#define CHtmlWnd__RemoveObserver_x                                 0x639230
#define Window__getProgress_x                                      0x854820
#define Window__getStatus_x                                        0x854840
#define Window__getURI_x                                           0x854850

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9577F0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x90B930

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E97F0
#define CXStr__CXStr1_x                                            0x9E2A60
#define CXStr__CXStr3_x                                            0x8F2900
#define CXStr__dCXStr_x                                            0x478390
#define CXStr__operator_equal_x                                    0x8F2B30
#define CXStr__operator_equal1_x                                   0x8F2B70
#define CXStr__operator_plus_equal1_x                              0x8F3600
#define CXStr__SetString_x                                         0x8F54F0
#define CXStr__operator_char_p_x                                   0x8F3070
#define CXStr__GetChar_x                                           0x8F4E20
#define CXStr__Delete_x                                            0x8F46F0
#define CXStr__GetUnicode_x                                        0x8F4E90
#define CXStr__GetLength_x                                         0x4A9050
#define CXStr__Mid_x                                               0x47D5A0
#define CXStr__Insert_x                                            0x8F4EF0
#define CXStr__FindNext_x                                          0x8F4B60

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93FC90
#define CXWnd__BringToTop_x                                        0x925140
#define CXWnd__Center_x                                            0x924CC0
#define CXWnd__ClrFocus_x                                          0x924AE0
#define CXWnd__Destroy_x                                           0x924B80
#define CXWnd__DoAllDrawing_x                                      0x921170
#define CXWnd__DrawChildren_x                                      0x921140
#define CXWnd__DrawColoredRect_x                                   0x9215C0
#define CXWnd__DrawTooltip_x                                       0x91FC90
#define CXWnd__DrawTooltipAtPoint_x                                0x91FD50
#define CXWnd__GetBorderFrame_x                                    0x921420
#define CXWnd__GetChildWndAt_x                                     0x9251E0
#define CXWnd__GetClientClipRect_x                                 0x9233F0
#define CXWnd__GetScreenClipRect_x                                 0x9234C0
#define CXWnd__GetScreenRect_x                                     0x923680
#define CXWnd__GetRelativeRect_x                                   0x923740
#define CXWnd__GetTooltipRect_x                                    0x921610
#define CXWnd__GetWindowTextA_x                                    0x49CEF0
#define CXWnd__IsActive_x                                          0x921D30
#define CXWnd__IsDescendantOf_x                                    0x924070
#define CXWnd__IsReallyVisible_x                                   0x9240A0
#define CXWnd__IsType_x                                            0x925850
#define CXWnd__Move_x                                              0x924110
#define CXWnd__Move1_x                                             0x9241C0
#define CXWnd__ProcessTransition_x                                 0x924C70
#define CXWnd__Refade_x                                            0x924490
#define CXWnd__Resize_x                                            0x924710
#define CXWnd__Right_x                                             0x924F00
#define CXWnd__SetFocus_x                                          0x924AA0
#define CXWnd__SetFont_x                                           0x924B10
#define CXWnd__SetKeyTooltip_x                                     0x925670
#define CXWnd__SetMouseOver_x                                      0x922540
#define CXWnd__StartFade_x                                         0x923F60
#define CXWnd__GetChildItem_x                                      0x925350
#define CXWnd__SetParent_x                                         0x923E20
#define CXWnd__Minimize_x                                          0x924780

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x95BA60

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x928040
#define CXWndManager__DrawWindows_x                                0x928060
#define CXWndManager__GetKeyboardFlags_x                           0x92A730
#define CXWndManager__HandleKeyboardMsg_x                          0x92A2E0
#define CXWndManager__RemoveWnd_x                                  0x92A960
#define CXWndManager__RemovePendingDeletionWnd_x                   0x92AEB0

// CDBStr
#define CDBStr__GetString_x                                        0x5481A0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BFD40
#define EQ_Character__Cur_HP_x                                     0x4D2F90
#define EQ_Character__Cur_Mana_x                                   0x4DA6B0
#define EQ_Character__GetCastingTimeModifier_x                     0x4C2DB0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B37B0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3900
#define EQ_Character__GetHPRegen_x                                 0x4E0580
#define EQ_Character__GetEnduranceRegen_x                          0x4E0B80
#define EQ_Character__GetManaRegen_x                               0x4E0FC0
#define EQ_Character__Max_Endurance_x                              0x65FC50
#define EQ_Character__Max_HP_x                                     0x4D2DC0
#define EQ_Character__Max_Mana_x                                   0x65FA50
#define EQ_Character__doCombatAbility_x                            0x662040
#define EQ_Character__UseSkill_x                                   0x4E2DC0
#define EQ_Character__GetConLevel_x                                0x6582A0
#define EQ_Character__IsExpansionFlag_x                            0x5BBBF0
#define EQ_Character__TotalEffect_x                                0x4C6B50
#define EQ_Character__GetPCSpellAffect_x                           0x4C3B00
#define EQ_Character__SpellDuration_x                              0x4C3630
#define EQ_Character__MySpellDuration_x                            0x4B20E0
#define EQ_Character__GetAdjustedSkill_x                           0x4D5D10
#define EQ_Character__GetBaseSkill_x                               0x4D6CB0
#define EQ_Character__CanUseItem_x                                 0x4DA9C0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BE6A0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x675F90

//PcClient
#define PcClient__vftable_x                                        0xAF31CC
#define PcClient__PcClient_x                                       0x655A10

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA7B0
#define CCharacterListWnd__EnterWorld_x                            0x4BA180
#define CCharacterListWnd__Quit_x                                  0x4B9ED0
#define CCharacterListWnd__UpdateList_x                            0x4BA370

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x63A3B0
#define EQ_Item__CreateItemTagString_x                             0x898760
#define EQ_Item__IsStackable_x                                     0x89D450
#define EQ_Item__GetImageNum_x                                     0x89A2A0
#define EQ_Item__CreateItemClient_x                                0x6395D0
#define EQ_Item__GetItemValue_x                                    0x89B590
#define EQ_Item__ValueSellMerchant_x                               0x89EE30
#define EQ_Item__IsKeyRingItem_x                                   0x89CCE0
#define EQ_Item__CanGoInBag_x                                      0x63A4D0
#define EQ_Item__IsEmpty_x                                         0x89C840
#define EQ_Item__GetMaxItemCount_x                                 0x89B9B0
#define EQ_Item__GetHeldItem_x                                     0x89A170
#define EQ_Item__GetAugmentFitBySlot_x                             0x897FC0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x566D20
#define EQ_LoadingS__Array_x                                       0xC14130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x660550
#define EQ_PC__GetAlternateAbilityId_x                             0x8A8110
#define EQ_PC__GetCombatAbility_x                                  0x8A8780
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A87F0
#define EQ_PC__GetItemRecastTimer_x                                0x6625C0
#define EQ_PC__HasLoreItem_x                                       0x658AC0
#define EQ_PC__AlertInventoryChanged_x                             0x657BE0
#define EQ_PC__GetPcZoneClient_x                                   0x685060
#define EQ_PC__RemoveMyAffect_x                                    0x6657F0
#define EQ_PC__GetKeyRingItems_x                                   0x8A90C0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A8E40
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A93C0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5C1FC0
#define EQItemList__add_object_x                                   0x5EF620
#define EQItemList__add_item_x                                     0x5C2520
#define EQItemList__delete_item_x                                  0x5C2570
#define EQItemList__FreeItemList_x                                 0x5C2470

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x544D00

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x677890
#define EQPlayer__dEQPlayer_x                                      0x66AC20
#define EQPlayer__DoAttack_x                                       0x67F800
#define EQPlayer__EQPlayer_x                                       0x66B2E0
#define EQPlayer__SetNameSpriteState_x                             0x66F5A0
#define EQPlayer__SetNameSpriteTint_x                              0x670480
#define PlayerBase__HasProperty_j_x                                0x98A640
#define EQPlayer__IsTargetable_x                                   0x98AAE0
#define EQPlayer__CanSee_x                                         0x98A940
#define EQPlayer__CanSee1_x                                        0x98AA10
#define PlayerBase__GetVisibilityLineSegment_x                     0x98A700

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x682B00
#define PlayerZoneClient__GetLevel_x                               0x6850A0
#define PlayerZoneClient__IsValidTeleport_x                        0x5F0790
#define PlayerZoneClient__LegalPlayerRace_x                        0x55FA20

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x67A6F0
#define EQPlayerManager__GetSpawnByName_x                          0x67A7A0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x67A830

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63DAF0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63DB70
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63DBB0
#define KeypressHandler__ClearCommandStateArray_x                  0x63EFA0
#define KeypressHandler__HandleKeyDown_x                           0x63EFC0
#define KeypressHandler__HandleKeyUp_x                             0x63F060
#define KeypressHandler__SaveKeymapping_x                          0x63F4B0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x776630
#define MapViewMap__SaveEx_x                                       0x7799F0
#define MapViewMap__SetZoom_x                                      0x77E0B0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BC710

// StringTable 
#define StringTable__getString_x                                   0x8B75A0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x665460
#define PcZoneClient__RemovePetEffect_x                            0x665A90
#define PcZoneClient__HasAlternateAbility_x                        0x65F880
#define PcZoneClient__GetCurrentMod_x                              0x4E5ED0
#define PcZoneClient__GetModCap_x                                  0x4E5DD0
#define PcZoneClient__CanEquipItem_x                               0x65FF30
#define PcZoneClient__GetItemByID_x                                0x662A40
#define PcZoneClient__GetItemByItemClass_x                         0x662B90
#define PcZoneClient__RemoveBuffEffect_x                           0x665AB0
#define PcZoneClient__BandolierSwap_x                              0x660B10
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x662560

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F53C0

//IconCache
#define IconCache__GetIcon_x                                       0x7183E0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x70FF00
#define CContainerMgr__CloseContainer_x                            0x7101D0
#define CContainerMgr__OpenExperimentContainer_x                   0x710C50

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CEBB0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x632560

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76CBE0
#define CLootWnd__RequestLootSlot_x                                0x76BEC0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58E910
#define EQ_Spell__SpellAffects_x                                   0x58ED80
#define EQ_Spell__SpellAffectBase_x                                0x58EB40
#define EQ_Spell__IsStackable_x                                    0x4CA9E0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CA800
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7A70
#define EQ_Spell__IsSPAStacking_x                                  0x58FBD0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58F0E0
#define EQ_Spell__IsNoRemove_x                                     0x4CA9C0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58FBE0
#define __IsResEffectSpell_x                                       0x4C9B80

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD450

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C6D20

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x815AD0
#define CTargetWnd__WndNotification_x                              0x815310
#define CTargetWnd__RefreshTargetBuffs_x                           0x8155E0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x814470

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x81A140
#define CTaskWnd__ConfirmAbandonTask_x                             0x81CD70

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x542730
#define CTaskManager__HandleMessage_x                              0x540B90
#define CTaskManager__GetTaskStatus_x                              0x5427E0
#define CTaskManager__GetElementDescription_x                      0x542860

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x589AB0
#define EqSoundManager__PlayScriptMp3_x                            0x589D70
#define EqSoundManager__SoundAssistPlay_x                          0x69D5A0
#define EqSoundManager__WaveInstancePlay_x                         0x69CB10

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x533AD0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x946420
#define CTextureAnimation__Draw_x                                  0x946620

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x942380

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56E7E0
#define CAltAbilityData__GetMercMaxRank_x                          0x56E770
#define CAltAbilityData__GetMaxRank_x                              0x563C60

//CTargetRing
#define CTargetRing__Cast_x                                        0x630680

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA7E0
#define CharacterBase__CreateItemGlobalIndex_x                     0x51A700
#define CharacterBase__CreateItemIndex_x                           0x638760
#define CharacterBase__GetItemPossession_x                         0x506300
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CF3B0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CF410
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F6E30
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F7660
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F7710

//messages
#define msg_spell_worn_off_x                                       0x5B3B40
#define msg_new_text_x                                             0x5A84D0
#define __msgTokenTextParam_x                                      0x5B5DE0
#define msgTokenText_x                                             0x5B6030

//SpellManager
#define SpellManager__vftable_x                                    0xADB55C
#define SpellManager__SpellManager_x                               0x6A08C0
#define Spellmanager__LoadTextSpells_x                             0x6A11B0
#define SpellManager__GetSpellByGroupAndRank_x                     0x6A0A90

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98E570

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x51AD80
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5BA040
#define ItemGlobalIndex__IsEquippedLocation_x                      0x651210
#define ItemGlobalIndex__IsValidIndex_x                            0x51AE10

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C76E0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C7870

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x7654A0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x7145F0
#define CCursorAttachment__AttachToCursor1_x                       0x714630
#define CCursorAttachment__Deactivate_x                            0x715620

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x939010
#define CSidlManagerBase__CreatePageWnd_x                          0x938810
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x934AB0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x934A40

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x956310
#define CEQSuiteTextureLoader__GetTexture_x                        0x955FD0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x517A30
#define CFindItemWnd__WndNotification_x                            0x518660
#define CFindItemWnd__Update_x                                     0x5191D0
#define CFindItemWnd__PickupSelectedItem_x                         0x517260

//IString
#define IString__Append_x                                          0x507C10

//Camera
#define CDisplay__cameraType_x                                     0xDEBCC8
#define EverQuest__Cameras_x                                       0xEA70A0

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x520770
#define LootFiltersManager__GetItemFilterData_x                    0x520080
#define LootFiltersManager__RemoveItemLootFilter_x                 0x5200B0
#define LootFiltersManager__SetItemLootFilter_x                    0x5202D0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BCA00

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9941D0
#define CResolutionHandler__GetWindowedStyle_x                     0x6981A0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70CBD0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D3140
#define CDistillerInfo__Instance_x                                 0x8D30E0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72B8D0
#define CGroupWnd__UpdateDisplay_x                                 0x72AC30

//ItemBase
#define ItemBase__IsLore_x                                         0x89CD90
#define ItemBase__IsLoreEquipped_x                                 0x89CE10

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EF580
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EF6C0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EF720

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68D7D0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x691150

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50E1F0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4FA600
#define FactionManagerClient__HandleFactionMessage_x               0x4FAC70
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4FB270
#define FactionManagerClient__GetMaxFaction_x                      0x4FB28F
#define FactionManagerClient__GetMinFaction_x                      0x4FB240

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x5062D0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91D8C0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C200

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x506620

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56DC90

//CTargetManager
#define CTargetManager__Get_x                                      0x6A4110

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68D7D0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A9060

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5C2410

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF44734

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6C0780
#define CAAWnd__UpdateSelected_x                                   0x6BCFF0
#define CAAWnd__Update_x                                           0x6BFAA0

//CXRect
#define CXRect__operator_and_x                                     0x7229D0

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x483170

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
