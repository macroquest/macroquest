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
#define __ExpectedVersionDate                                     "Nov 30 2020"
#define __ExpectedVersionTime                                     "15:28:10"
#define __ActualVersionDate_x                                      0xAF6570
#define __ActualVersionTime_x                                      0xAF6564
#define __ActualVersionBuild_x                                     0xAE458C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x643970
#define __MemChecker1_x                                            0x8F71B0
#define __MemChecker2_x                                            0x6B4090
#define __MemChecker3_x                                            0x6B3FE0
#define __MemChecker4_x                                            0x84D350
#define __EncryptPad0_x                                            0xC2C9C8
#define __EncryptPad1_x                                            0xC8A210
#define __EncryptPad2_x                                            0xC3CD90
#define __EncryptPad3_x                                            0xC3C990
#define __EncryptPad4_x                                            0xC7A7A0
#define __EncryptPad5_x                                            0xF4D0F0
#define __AC1_x                                                    0x80BD96
#define __AC2_x                                                    0x5FD02F
#define __AC3_x                                                    0x604680
#define __AC4_x                                                    0x608630
#define __AC5_x                                                    0x60E92F
#define __AC6_x                                                    0x612DE6
#define __AC7_x                                                    0x5FCAA0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1912E0

// Direct Input
#define DI8__Main_x                                                0xF4D118
#define DI8__Keyboard_x                                            0xF4D11C
#define DI8__Mouse_x                                               0xF4D0FC
#define DI8__Mouse_Copy_x                                          0xEA59E4
#define DI8__Mouse_Check_x                                         0xF4AC44
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
#define __do_loot_x                                                0x5C8B00
#define __DrawHandler_x                                            0x15DC140
#define __GroupCount_x                                             0xE9E502
#define __Guilds_x                                                 0xEA4920
#define __gWorld_x                                                 0xE9EC98
#define __HWnd_x                                                   0xF4D100
#define __heqmain_x                                                0xF4D0D8
#define __InChatMode_x                                             0xEA59CC
#define __LastTell_x                                               0xEA794C
#define __LMouseHeldTime_x                                         0xEA5B08
#define __Mouse_x                                                  0xF4D104
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
#define __ServerHost_x                                             0xE9E92B
#define __ServerName_x                                             0xEDC210
#define __ShiftKeyDown_x                                           0xEA6060
#define __ShowNames_x                                              0xEA6DA0
#define EverQuestInfo__bSocialChanged_x                            0xEDC298
#define __Socials_x                                                0xEDC310
#define __SubscriptionType_x                                       0xFA1410
#define __TargetAggroHolder_x                                      0xF5FB00
#define __ZoneType_x                                               0xEA5E60
#define __GroupAggro_x                                             0xF5FB40
#define __LoginName_x                                              0xF4A8D4
#define __Inviter_x                                                0xF446AC
#define __AttackOnAssist_x                                         0xEA6D5C
#define __UseTellWindows_x                                         0xEA7094
#define __gfMaxZoomCameraDistance_x                                0xAEE188
#define __gfMaxCameraDistance_x                                    0xB16E08
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
#define pinstActiveMerchant_x                                      0xE9EA34
#define pinstAltAdvManager_x                                       0xDECEF0
#define pinstBandageTarget_x                                       0xE9EC54
#define pinstCamActor_x                                            0xDEC4A4
#define pinstCDBStr_x                                              0xDEBC0C
#define pinstCDisplay_x                                            0xE9ECA4
#define pinstCEverQuest_x                                          0xF4A19C
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
#define pinstEqLogin_x                                             0xF4A220
#define instEQMisc_x                                               0xDEBB50
#define pinstEQSoundManager_x                                      0xDEDEC0
#define pinstEQSpellStrings_x                                      0xCAE448
#define instExpeditionLeader_x                                     0xEA4842
#define instExpeditionName_x                                       0xEA4882
#define pinstGroup_x                                               0xE9E4FE
#define pinstImeManager_x                                          0x15DB300
#define pinstLocalPlayer_x                                         0xE9E824
#define pinstMercenaryData_x                                       0xF46D08
#define pinstMercenaryStats_x                                      0xF5FBCC
#define pinstModelPlayer_x                                         0xE9EC4C
#define pinstPCData_x                                              0xE9E744
#define pinstSkillMgr_x                                            0xF48E68
#define pinstSpawnManager_x                                        0xF47910
#define pinstSpellManager_x                                        0xF490A8
#define pinstSpellSets_x                                           0xF3D358
#define pinstStringTable_x                                         0xE9E74C
#define pinstSwitchManager_x                                       0xE9E258
#define pinstTarget_x                                              0xE9EC88
#define pinstTargetObject_x                                        0xE9EC94
#define pinstTargetSwitch_x                                        0xE9ECAC
#define pinstTaskMember_x                                          0xDEB9E0
#define pinstTrackTarget_x                                         0xE9EC90
#define pinstTradeTarget_x                                         0xE9EC48
#define instTributeActive_x                                        0xDEBB71
#define pinstViewActor_x                                           0xDEC4A0
#define pinstWorldData_x                                           0xE9E3A8
#define pinstZoneAddr_x                                            0xEA5EF8
#define pinstPlayerPath_x                                          0xF479A8
#define pinstTargetIndicator_x                                     0xF49310
#define EQObject_Top_x                                             0xE9E820
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDEBF44
#define pinstCAchievementsWnd_x                                    0xDEC45C
#define pinstCActionsWnd_x                                         0xDEBF80
#define pinstCAdvancedDisplayOptionsWindow_x                       0xDEC51C
#define pinstCAdvancedLootWnd_x                                    0xDEC4CC
#define pinstCAdventureLeaderboardWnd_x                            0xF56920
#define pinstCAdventureRequestWnd_x                                0xF569D0
#define pinstCAdventureStatsWnd_x                                  0xF56A80
#define pinstCAggroMeterWnd_x                                      0xDEC500
#define pinstCAlarmWnd_x                                           0xDEC488
#define pinstCAlertHistoryWnd_x                                    0xDEBEF4
#define pinstCAlertStackWnd_x                                      0xDEC4E8
#define pinstCAlertWnd_x                                           0xDEC4FC
#define pinstCAltStorageWnd_x                                      0xF56DE0
#define pinstCAudioTriggersWindow_x                                0xCA0778
#define pinstCAuraWnd_x                                            0xDEC4D0
#define pinstCAvaZoneWnd_x                                         0xDEBEF8
#define pinstCBandolierWnd_x                                       0xDEC514
#define pinstCBankWnd_x                                            0xDEBCB8
#define pinstCBarterMerchantWnd_x                                  0xF58020
#define pinstCBarterSearchWnd_x                                    0xF580D0
#define pinstCBarterWnd_x                                          0xF58180
#define pinstCBazaarConfirmationWnd_x                              0xDEC498
#define pinstCBazaarSearchWnd_x                                    0xDEBF48
#define pinstCBazaarWnd_x                                          0xDEC464
#define pinstCBlockedBuffWnd_x                                     0xDEC4DC
#define pinstCBlockedPetBuffWnd_x                                  0xDEC504
#define pinstCBodyTintWnd_x                                        0xDEC40C
#define pinstCBookWnd_x                                            0xDEBCAC
#define pinstCBreathWnd_x                                          0xDEBF58
#define pinstCBuffWindowNORMAL_x                                   0xDEC4C4
#define pinstCBuffWindowSHORT_x                                    0xDEC4C8
#define pinstCBugReportWnd_x                                       0xDEBCB4
#define pinstCButtonWnd_x                                          0x15DB570
#define pinstCCastingWnd_x                                         0xDEC540
#define pinstCCastSpellWnd_x                                       0xDEBF54
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDEC418
#define pinstCChatWindowManager_x                                  0xF58C40
#define pinstCClaimWnd_x                                           0xF58D98
#define pinstCColorPickerWnd_x                                     0xDEBF0C
#define pinstCCombatAbilityWnd_x                                   0xDEC478
#define pinstCCombatSkillsSelectWnd_x                              0xDEC42C
#define pinstCCompassWnd_x                                         0xDEBF84
#define pinstCConfirmationDialog_x                                 0xF5DC98
#define pinstCContainerMgr_x                                       0xDEC408
#define pinstCContextMenuManager_x                                 0x15DB2C0
#define pinstCCursorAttachment_x                                   0xDEC534
#define pinstCDynamicZoneWnd_x                                     0xF59360
#define pinstCEditLabelWnd_x                                       0xDEC4C0
#define pinstCEQMainWnd_x                                          0xF595A8
#define pinstCEventCalendarWnd_x                                   0xDEBF4C
#define pinstCExtendedTargetWnd_x                                  0xDEC4E0
#define pinstCPlayerCustomizationWnd_x                             0xDEC430
#define pinstCFactionWnd_x                                         0xDEC450
#define pinstCFellowshipWnd_x                                      0xF597A8
#define pinstCFileSelectionWnd_x                                   0xDEBF08
#define pinstCFindItemWnd_x                                        0xDEC444
#define pinstCFindLocationWnd_x                                    0xF59900
#define pinstCFriendsWnd_x                                         0xDEC440
#define pinstCGemsGameWnd_x                                        0xDEC44C
#define pinstCGiveWnd_x                                            0xDEC48C
#define pinstCGroupSearchFiltersWnd_x                              0xDEC518
#define pinstCGroupSearchWnd_x                                     0xF59CF8
#define pinstCGroupWnd_x                                           0xF59DA8
#define pinstCGuildBankWnd_x                                       0xF59E58
#define pinstCGuildCreationWnd_x                                   0xF59F08
#define pinstCGuildMgmtWnd_x                                       0xF59FB8
#define pinstCharacterCreation_x                                   0xDEC438
#define pinstCHelpWnd_x                                            0xDEC484
#define pinstCHeritageSelectionWnd_x                               0xDEC43C
#define pinstCHotButtonWnd_x                                       0xF5C110
#define pinstCHotButtonWnd1_x                                      0xF5C110
#define pinstCHotButtonWnd2_x                                      0xF5C114
#define pinstCHotButtonWnd3_x                                      0xF5C118
#define pinstCHotButtonWnd4_x                                      0xF5C11C
#define pinstCIconSelectionWnd_x                                   0xDEC528
#define pinstCInspectWnd_x                                         0xDEC508
#define pinstCInventoryWnd_x                                       0xDEC4D4
#define pinstCInvSlotMgr_x                                         0xDEBF38
#define pinstCItemDisplayManager_x                                 0xF5C6A0
#define pinstCItemExpTransferWnd_x                                 0xF5C7D0
#define pinstCItemOverflowWnd_x                                    0xDEBF50
#define pinstCJournalCatWnd_x                                      0xDEBF24
#define pinstCJournalNPCWnd_x                                      0xDEBEE4
#define pinstCJournalTextWnd_x                                     0xDEBEE4
#define pinstCKeyRingWnd_x                                         0xDEC53C
#define pinstCLargeDialogWnd_x                                     0xF5E918
#define pinstCLayoutCopyWnd_x                                      0xF5CB20
#define pinstCLFGuildWnd_x                                         0xF5CBD0
#define pinstCLoadskinWnd_x                                        0xDEC468
#define pinstCLootFiltersCopyWnd_x                                 0xCBCEE8
#define pinstCLootFiltersWnd_x                                     0xDEC4EC
#define pinstCLootSettingsWnd_x                                    0xDEC510
#define pinstCLootWnd_x                                            0xDEBF28
#define pinstCMailAddressBookWnd_x                                 0xDEBF3C
#define pinstCMailCompositionWnd_x                                 0xDEBF14
#define pinstCMailIgnoreListWnd_x                                  0xDEBF40
#define pinstCMailWnd_x                                            0xDEBF00
#define pinstCManageLootWnd_x                                      0xDED3A0
#define pinstCMapToolbarWnd_x                                      0xDEC490
#define pinstCMapViewWnd_x                                         0xDEC458
#define pinstCMarketplaceWnd_x                                     0xDEC4F0
#define pinstCMerchantWnd_x                                        0xDEBF34
#define pinstCMIZoneSelectWnd_x                                    0xF5D408
#define pinstCMusicPlayerWnd_x                                     0xDEBED4
#define pinstCNameChangeMercWnd_x                                  0xDEC494
#define pinstCNameChangePetWnd_x                                   0xDEC460
#define pinstCNameChangeWnd_x                                      0xDEC4BC
#define pinstCNoteWnd_x                                            0xDEC470
#define pinstCObjectPreviewWnd_x                                   0xDEC50C
#define pinstCOptionsWnd_x                                         0xDEC47C
#define pinstCPetInfoWnd_x                                         0xDEBEFC
#define pinstCPetitionQWnd_x                                       0xDEC428
#define pinstCPlayerNotesWnd_x                                     0xDEC410
#define pinstCPlayerWnd_x                                          0xDEBEF0
#define pinstCPopupWndManager_x                                    0xF5DC98
#define pinstCProgressionSelectionWnd_x                            0xF5DD48
#define pinstCPurchaseGroupWnd_x                                   0xDEBCC8
#define pinstCPurchaseWnd_x                                        0xDEC544
#define pinstCPvPLeaderboardWnd_x                                  0xF5DDF8
#define pinstCPvPStatsWnd_x                                        0xF5DEA8
#define pinstCQuantityWnd_x                                        0xDEBEE0
#define pinstCRaceChangeWnd_x                                      0xDEC4D8
#define pinstCRaidOptionsWnd_x                                     0xDEC520
#define pinstCRaidWnd_x                                            0xDEBF30
#define pinstCRealEstateItemsWnd_x                                 0xDEC454
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDEC000
#define pinstCRealEstateManageWnd_x                                0xDEBED0
#define pinstCRealEstateNeighborhoodWnd_x                          0xDEBEEC
#define pinstCRealEstatePlotSearchWnd_x                            0xDEBF04
#define pinstCRealEstatePurchaseWnd_x                              0xDEBF20
#define pinstCRespawnWnd_x                                         0xDEC4F8
#define pinstCRewardSelectionWnd_x                                 0xF5E5F0
#define pinstCSelectorWnd_x                                        0xDEC424
#define pinstCSendMoneyWnd_x                                       0xDEC49C
#define pinstCServerListWnd_x                                      0xDEBF2C
#define pinstCSkillsSelectWnd_x                                    0xDEC420
#define pinstCSkillsWnd_x                                          0xDEBFFC
#define pinstCSocialEditWnd_x                                      0xDEC538
#define pinstCSocialWnd_x                                          0xDEC480
#define pinstCSpellBookWnd_x                                       0xDEC474
#define pinstCStoryWnd_x                                           0xDEBF7C
#define pinstCTargetOfTargetWnd_x                                  0xF5FC50
#define pinstCTargetWnd_x                                          0xDEC4F4
#define pinstCTaskOverlayWnd_x                                     0xDEBCC0
#define pinstCTaskSelectWnd_x                                      0xF5FDA8
#define pinstCTaskManager_x                                        0xCBD828
#define pinstCTaskTemplateSelectWnd_x                              0xF5FE58
#define pinstCTaskWnd_x                                            0xF5FF08
#define pinstCTextEntryWnd_x                                       0xDEBCA8
#define pinstCTimeLeftWnd_x                                        0xDEC41C
#define pinstCTipWndCONTEXT_x                                      0xF6010C
#define pinstCTipWndOFDAY_x                                        0xF60108
#define pinstCTitleWnd_x                                           0xF601B8
#define pinstCTrackingWnd_x                                        0xDEC4E4
#define pinstCTradeskillWnd_x                                      0xF60320
#define pinstCTradeWnd_x                                           0xDEC414
#define pinstCTrainWnd_x                                           0xDEBF18
#define pinstCTributeBenefitWnd_x                                  0xF60520
#define pinstCTributeMasterWnd_x                                   0xF605D0
#define pinstCTributeTrophyWnd_x                                   0xF60680
#define pinstCVideoModesWnd_x                                      0xDEBCBC
#define pinstCVoiceMacroWnd_x                                      0xF498C8
#define pinstCVoteResultsWnd_x                                     0xDEC448
#define pinstCVoteWnd_x                                            0xDEC434
#define pinstCWebManager_x                                         0xF49F44
#define pinstCZoneGuideWnd_x                                       0xDEBCC4
#define pinstCZonePathWnd_x                                        0xDEBEDC

#define pinstEQSuiteTextureLoader_x                                0xC8AB30
#define pinstItemIconCache_x                                       0xF59560
#define pinstLootFiltersManager_x                                  0xCBCF98
#define pinstRewardSelectionWnd_x                                  0xF5E5F0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5C41F0
#define __CastRay2_x                                               0x5C4240
#define __ConvertItemTags_x                                        0x5DFF00
#define __CleanItemTags_x                                          0x47D2F0
#define __DoesFileExist_x                                          0x8FA230
#define __EQGetTime_x                                              0x8F6DE0
#define __ExecuteCmd_x                                             0x5BCB80
#define __FixHeading_x                                             0x98C8C0
#define __FlushDxKeyboard_x                                        0x6AFF30
#define __GameLoop_x                                               0x6B3260
#define __get_bearing_x                                            0x5C3D50
#define __get_melee_range_x                                        0x5C4430
#define __GetAnimationCache_x                                      0x718640
#define __GetGaugeValueFromEQ_x                                    0x80A240
#define __GetLabelFromEQ_x                                         0x80BD20
#define __GetXTargetType_x                                         0x98E380
#define __HandleMouseWheel_x                                       0x6B4140
#define __HeadingDiff_x                                            0x98C930
#define __HelpPath_x                                               0xF44E04
#define __LoadFrontEnd_x                                           0x6B0570
#define __NewUIINI_x                                               0x809F10
#define __ProcessGameEvents_x                                      0x624CC0
#define __ProcessMouseEvent_x                                      0x624450
#define __SaveColors_x                                             0x55DA80
#define __STMLToText_x                                             0x92FF50
#define __ToggleKeyRingItem_x                                      0x51C430
#define CMemoryMappedFile__SetFile_x                               0xA7BC00
#define CrashDetected_x                                            0x6B2020
#define DrawNetStatus_x                                            0x650F80
#define Expansion_HoT_x                                            0xEA6D48
#define Teleport_Table_Size_x                                      0xE9E7E0
#define Teleport_Table_x                                           0xE9ECB0
#define Util__FastTime_x                                           0x8F69B0
#define __CopyLayout_x                                             0x63F060
#define __WndProc_x                                                0x6B2520
#define __ProcessKeyboardEvent_x                                   0x6B1AC0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490560
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499550
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499320
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493B00
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492F50

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x565B60
#define AltAdvManager__IsAbilityReady_x                            0x564900
#define AltAdvManager__GetAAById_x                                 0x564C90
#define AltAdvManager__CanTrainAbility_x                           0x564D00
#define AltAdvManager__CanSeeAbility_x                             0x565060

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CB330
#define CharacterZoneClient__HasSkill_x                            0x4D61B0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D78D0
#define CharacterZoneClient__IsStackBlocked_x                      0x4C29F0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBE80
#define CharacterZoneClient__GetItemCountWorn_x                    0x4DA260
#define CharacterZoneClient__GetItemCountInInventory_x             0x4DA340
#define CharacterZoneClient__GetCursorItemCount_x                  0x4DA420
#define CharacterZoneClient__FindAffectSlot_x                      0x4C4AE0
#define CharacterZoneClient__BardCastBard_x                        0x4C7510
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF890
#define CharacterZoneClient__GetEffect_x                           0x4BBDC0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C5B50
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C5C20
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C5C70
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5DC0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5FA0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3D90
#define CharacterZoneClient__FindItemByGuid_x                      0x4D8830
#define CharacterZoneClient__FindItemByRecord_x                    0x4D82B0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D9CF0
#define CBankWnd__WndNotification_x                                0x6D9AC0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E75F0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x92D740
#define CButtonWnd__CButtonWnd_x                                   0x92C330

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x707800
#define CChatManager__InitContextMenu_x                            0x700940
#define CChatManager__FreeChatWindow_x                             0x706340
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9D00
#define CChatManager__SetLockedActiveChatWindow_x                  0x707480
#define CChatManager__CreateChatWindow_x                           0x706980

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9E10

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x940850
#define CContextMenu__dCContextMenu_x                              0x940A80
#define CContextMenu__AddMenuItem_x                                0x940A90
#define CContextMenu__RemoveMenuItem_x                             0x940DA0
#define CContextMenu__RemoveAllMenuItems_x                         0x940DC0
#define CContextMenu__CheckMenuItem_x                              0x940E40
#define CContextMenu__SetMenuItem_x                                0x940CC0
#define CContextMenu__AddSeparator_x                               0x940C20

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x9413D0
#define CContextMenuManager__RemoveMenu_x                          0x941440
#define CContextMenuManager__PopupMenu_x                           0x941500
#define CContextMenuManager__Flush_x                               0x941370
#define CContextMenuManager__GetMenu_x                             0x49B750
#define CContextMenuManager__CreateDefaultMenu_x                   0x712FB0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D1A20
#define CChatService__GetFriendName_x                              0x8D1A30

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x708030
#define CChatWindow__Clear_x                                       0x7092F0
#define CChatWindow__WndNotification_x                             0x709A80
#define CChatWindow__AddHistory_x                                  0x708BB0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93DCC0
#define CComboWnd__Draw_x                                          0x93D1C0
#define CComboWnd__GetCurChoice_x                                  0x93DB00
#define CComboWnd__GetListRect_x                                   0x93D670
#define CComboWnd__GetTextRect_x                                   0x93DD30
#define CComboWnd__InsertChoice_x                                  0x93D800
#define CComboWnd__SetColors_x                                     0x93D7D0
#define CComboWnd__SetChoice_x                                     0x93DAD0
#define CComboWnd__GetItemCount_x                                  0x93DB10
#define CComboWnd__GetCurChoiceText_x                              0x93DB50
#define CComboWnd__GetChoiceText_x                                 0x93DB20
#define CComboWnd__InsertChoiceAtIndex_x                           0x93D890

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x7109D0
#define CContainerWnd__vftable_x                                   0xAFF774
#define CContainerWnd__SetContainer_x                              0x711F30

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
#define CEditBaseWnd__SetSel_x                                     0x9605B0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x943D40
#define CEditWnd__EnsureCaretVisible_x                             0x945ED0
#define CEditWnd__GetCaretPt_x                                     0x944EB0
#define CEditWnd__GetCharIndexPt_x                                 0x944C60
#define CEditWnd__GetDisplayString_x                               0x944B10
#define CEditWnd__GetHorzOffset_x                                  0x9433F0
#define CEditWnd__GetLineForPrintableChar_x                        0x945DD0
#define CEditWnd__GetSelStartPt_x                                  0x944F10
#define CEditWnd__GetSTMLSafeText_x                                0x944930
#define CEditWnd__PointFromPrintableChar_x                         0x945A10
#define CEditWnd__SelectableCharFromPoint_x                        0x945B80
#define CEditWnd__SetEditable_x                                    0x944FD0
#define CEditWnd__SetWindowTextA_x                                 0x9446B0
#define CEditWnd__ReplaceSelection_x                               0x945690
#define CEditWnd__ReplaceSelection1_x                              0x945610

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x6122C0
#define CEverQuest__ClickedPlayer_x                                0x604460
#define CEverQuest__CreateTargetIndicator_x                        0x621E30
#define CEverQuest__DeleteTargetIndicator_x                        0x621EC0
#define CEverQuest__DoTellWindow_x                                 0x4E9EF0
#define CEverQuest__OutputTextToLog_x                              0x4EA1C0
#define CEverQuest__DropHeldItemOnGround_x                         0x5F95C0
#define CEverQuest__dsp_chat_x                                     0x4EA550
#define CEverQuest__trimName_x                                     0x61DFE0
#define CEverQuest__Emote_x                                        0x612B20
#define CEverQuest__EnterZone_x                                    0x60CC20
#define CEverQuest__GetBodyTypeDesc_x                              0x617570
#define CEverQuest__GetClassDesc_x                                 0x617BB0
#define CEverQuest__GetClassThreeLetterCode_x                      0x6181B0
#define CEverQuest__GetDeityDesc_x                                 0x620680
#define CEverQuest__GetLangDesc_x                                  0x618370
#define CEverQuest__GetRaceDesc_x                                  0x617B90
#define CEverQuest__InterpretCmd_x                                 0x620C50
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FD750
#define CEverQuest__LMouseUp_x                                     0x5FBAE0
#define CEverQuest__RightClickedOnPlayer_x                         0x5FE030
#define CEverQuest__RMouseUp_x                                     0x5FCA60
#define CEverQuest__SetGameState_x                                 0x5F9350
#define CEverQuest__UPCNotificationFlush_x                         0x61DEE0
#define CEverQuest__IssuePetCommand_x                              0x619780
#define CEverQuest__ReportSuccessfulHit_x                          0x613E70

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x722680
#define CGaugeWnd__CalcLinesFillRect_x                             0x7226E0
#define CGaugeWnd__Draw_x                                          0x721D10

// CGuild
#define CGuild__FindMemberByName_x                                 0x4B00F0
#define CGuild__GetGuildName_x                                     0x4AEBA0
#define CGuild__GetGuildIndex_x                                    0x4AF1A0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73C2B0

//CHotButton
#define CHotButton__SetCheck_x                                     0x633580
#define CHotButton__SetButtonSize_x                                0x633940

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x749540
#define CInvSlotMgr__MoveItem_x                                    0x748200
#define CInvSlotMgr__SelectSlot_x                                  0x749610

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7469F0
#define CInvSlot__SliderComplete_x                                 0x744730
#define CInvSlot__GetItemBase_x                                    0x7440A0
#define CInvSlot__UpdateItem_x                                     0x744210

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x74B0A0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x74A230
#define CInvSlotWnd__HandleLButtonUp_x                             0x74AC20

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x8055F0
#define CItemDisplayWnd__UpdateStrings_x                           0x759850
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x7534A0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x7539D0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x759E50
#define CItemDisplayWnd__AboutToShow_x                             0x7594B0
#define CItemDisplayWnd__WndNotification_x                         0x75B0C0
#define CItemDisplayWnd__RequestConvertItem_x                      0x75AA00
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x758510
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x7592D0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8361F0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75F5F0

// CLabel 
#define CLabel__Draw_x                                             0x765010

// CListWnd
#define CListWnd__CListWnd_x                                       0x9166E0
#define CListWnd__dCListWnd_x                                      0x916A00
#define CListWnd__AddColumn_x                                      0x91AE50
#define CListWnd__AddColumn1_x                                     0x91AEA0
#define CListWnd__AddLine_x                                        0x91B230
#define CListWnd__AddString_x                                      0x91B030
#define CListWnd__CalculateFirstVisibleLine_x                      0x91AC20
#define CListWnd__CalculateVSBRange_x                              0x91AA10
#define CListWnd__ClearSel_x                                       0x91BA10
#define CListWnd__ClearAllSel_x                                    0x91BA70
#define CListWnd__CloseAndUpdateEditWindow_x                       0x91C470
#define CListWnd__Compare_x                                        0x91A340
#define CListWnd__Draw_x                                           0x916B30
#define CListWnd__DrawColumnSeparators_x                           0x919310
#define CListWnd__DrawHeader_x                                     0x919780
#define CListWnd__DrawItem_x                                       0x919C80
#define CListWnd__DrawLine_x                                       0x919480
#define CListWnd__DrawSeparator_x                                  0x9193B0
#define CListWnd__EnableLine_x                                     0x918BF0
#define CListWnd__EnsureVisible_x                                  0x91C3A0
#define CListWnd__ExtendSel_x                                      0x91B940
#define CListWnd__GetColumnTooltip_x                               0x918730
#define CListWnd__GetColumnMinWidth_x                              0x9187A0
#define CListWnd__GetColumnWidth_x                                 0x9186A0
#define CListWnd__GetCurSel_x                                      0x918030
#define CListWnd__GetItemAtPoint_x                                 0x918E60
#define CListWnd__GetItemAtPoint1_x                                0x918ED0
#define CListWnd__GetItemData_x                                    0x9180B0
#define CListWnd__GetItemHeight_x                                  0x918470
#define CListWnd__GetItemIcon_x                                    0x918240
#define CListWnd__GetItemRect_x                                    0x918CE0
#define CListWnd__GetItemText_x                                    0x9180F0
#define CListWnd__GetSelList_x                                     0x91BAC0
#define CListWnd__GetSeparatorRect_x                               0x919110
#define CListWnd__InsertLine_x                                     0x91B620
#define CListWnd__RemoveLine_x                                     0x91B770
#define CListWnd__SetColors_x                                      0x91A9E0
#define CListWnd__SetColumnJustification_x                         0x91A710
#define CListWnd__SetColumnLabel_x                                 0x91AFD0
#define CListWnd__SetColumnWidth_x                                 0x91A630
#define CListWnd__SetCurSel_x                                      0x91B880
#define CListWnd__SetItemColor_x                                   0x91C060
#define CListWnd__SetItemData_x                                    0x91C020
#define CListWnd__SetItemText_x                                    0x91BC30
#define CListWnd__ShiftColumnSeparator_x                           0x91A7D0
#define CListWnd__Sort_x                                           0x91A4C0
#define CListWnd__ToggleSel_x                                      0x91B8B0
#define CListWnd__SetColumnsSizable_x                              0x91A880
#define CListWnd__SetItemWnd_x                                     0x91BEE0
#define CListWnd__GetItemWnd_x                                     0x918290
#define CListWnd__SetItemIcon_x                                    0x91BCB0
#define CListWnd__CalculateCustomWindowPositions_x                 0x91AD10
#define CListWnd__SetVScrollPos_x                                  0x91A610

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x77A6E0
#define CMapViewWnd__GetWorldCoordinates_x                         0x778DF0
#define CMapViewWnd__HandleLButtonDown_x                           0x775E30

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x79A9C0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79B2A0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79B7D0
#define CMerchantWnd__SelectRecoverySlot_x                         0x79E790
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x799530
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A4350
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x79A5E0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89F440
#define CPacketScrambler__hton_x                                   0x89F430

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x9354F0
#define CSidlManager__FindScreenPieceTemplate_x                    0x935900
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9356F0
#define CSidlManager__CreateLabel_x                                0x7FC7F0
#define CSidlManager__CreateXWndFromTemplate_x                     0x938860
#define CSidlManager__CreateXWndFromTemplate1_x                    0x938A30
#define CSidlManager__CreateXWnd_x                                 0x7FC720
#define CSidlManager__CreateHotButtonWnd_x                         0x7FCCE0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x931FF0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x931EF0
#define CSidlScreenWnd__ConvertToRes_x                             0x95B0A0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x9319F0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x9316E0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x9317B0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x931880
#define CSidlScreenWnd__DrawSidlPiece_x                            0x932480
#define CSidlScreenWnd__EnableIniStorage_x                         0x932950
#define CSidlScreenWnd__GetSidlPiece_x                             0x932670
#define CSidlScreenWnd__Init1_x                                    0x931300
#define CSidlScreenWnd__LoadIniInfo_x                              0x9329A0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9334D0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x930710
#define CSidlScreenWnd__StoreIniInfo_x                             0x933050
#define CSidlScreenWnd__StoreIniVis_x                              0x9333B0
#define CSidlScreenWnd__WndNotification_x                          0x932390
#define CSidlScreenWnd__GetChildItem_x                             0x9328D0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x922220
#define CSidlScreenWnd__m_layoutCopy_x                             0x15DB190

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x699160
#define CSkillMgr__GetSkillCap_x                                   0x699340
#define CSkillMgr__GetNameToken_x                                  0x6988E0
#define CSkillMgr__IsActivatedSkill_x                              0x698A20
#define CSkillMgr__IsCombatSkill_x                                 0x698960

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9421C0
#define CSliderWnd__SetValue_x                                     0x942030
#define CSliderWnd__SetNumTicks_x                                  0x942090

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x8029C0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x94AA90
#define CStmlWnd__ParseSTML_x                                      0x94BE00
#define CStmlWnd__CalculateHSBRange_x                              0x94BBF0
#define CStmlWnd__CalculateVSBRange_x                              0x94BB70
#define CStmlWnd__CanBreakAtCharacter_x                            0x94FF10
#define CStmlWnd__FastForwardToEndOfTag_x                          0x950BA0
#define CStmlWnd__ForceParseNow_x                                  0x94B0D0
#define CStmlWnd__GetNextTagPiece_x                                0x94FE70
#define CStmlWnd__GetSTMLText_x                                    0x50D910
#define CStmlWnd__GetVisibleText_x                                 0x94B0F0
#define CStmlWnd__InitializeWindowVariables_x                      0x9509F0
#define CStmlWnd__MakeStmlColorTag_x                               0x94A100
#define CStmlWnd__MakeWndNotificationTag_x                         0x94A170
#define CStmlWnd__SetSTMLText_x                                    0x9491B0
#define CStmlWnd__StripFirstSTMLLines_x                            0x951C90
#define CStmlWnd__UpdateHistoryString_x                            0x950DB0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x948300
#define CTabWnd__DrawCurrentPage_x                                 0x948A30
#define CTabWnd__DrawTab_x                                         0x948750
#define CTabWnd__GetCurrentPage_x                                  0x947B10
#define CTabWnd__GetPageInnerRect_x                                0x947D50
#define CTabWnd__GetTabInnerRect_x                                 0x947C90
#define CTabWnd__GetTabRect_x                                      0x947B40
#define CTabWnd__InsertPage_x                                      0x947F60
#define CTabWnd__RemovePage_x                                      0x9480D0
#define CTabWnd__SetPage_x                                         0x947DD0
#define CTabWnd__SetPageRect_x                                     0x948240
#define CTabWnd__UpdatePage_x                                      0x948610
#define CTabWnd__GetPageFromTabIndex_x                             0x948690
#define CTabWnd__GetCurrentTabIndex_x                              0x947B00

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x75FA00
#define CPageWnd__SetTabText_x                                     0x947660
#define CPageWnd__FlashTab_x                                       0x9476C0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9390

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91F160
#define CTextureFont__GetTextExtent_x                              0x91F320

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AD3E0
#define CHtmlComponentWnd__ValidateUri_x                           0x73DCA0
#define CHtmlWnd__SetClientCallbacks_x                             0x6389D0
#define CHtmlWnd__AddObserver_x                                    0x6389F0
#define CHtmlWnd__RemoveObserver_x                                 0x638A50
#define Window__getProgress_x                                      0x854920
#define Window__getStatus_x                                        0x854940
#define Window__getURI_x                                           0x854950

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x957EB0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x90C1A0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9B40
#define CXStr__CXStr1_x                                            0x508AF0
#define CXStr__CXStr3_x                                            0x8F2D60
#define CXStr__dCXStr_x                                            0x4784D0
#define CXStr__operator_equal_x                                    0x8F2F90
#define CXStr__operator_equal1_x                                   0x8F2FD0
#define CXStr__operator_plus_equal1_x                              0x8F3A60
#define CXStr__SetString_x                                         0x8F5950
#define CXStr__operator_char_p_x                                   0x8F34A0
#define CXStr__GetChar_x                                           0x8F52A0
#define CXStr__Delete_x                                            0x8F4B50
#define CXStr__GetUnicode_x                                        0x8F5310
#define CXStr__GetLength_x                                         0x47D6A0
#define CXStr__Mid_x                                               0x47D6B0
#define CXStr__Insert_x                                            0x8F5370
#define CXStr__FindNext_x                                          0x8F4FC0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x940470
#define CXWnd__BringToTop_x                                        0x9258D0
#define CXWnd__Center_x                                            0x925450
#define CXWnd__ClrFocus_x                                          0x925260
#define CXWnd__Destroy_x                                           0x925310
#define CXWnd__DoAllDrawing_x                                      0x9219F0
#define CXWnd__DrawChildren_x                                      0x9219C0
#define CXWnd__DrawColoredRect_x                                   0x921E10
#define CXWnd__DrawTooltip_x                                       0x920530
#define CXWnd__DrawTooltipAtPoint_x                                0x9205F0
#define CXWnd__GetBorderFrame_x                                    0x921C80
#define CXWnd__GetChildWndAt_x                                     0x925970
#define CXWnd__GetClientClipRect_x                                 0x923C10
#define CXWnd__GetScreenClipRect_x                                 0x923CC0
#define CXWnd__GetScreenRect_x                                     0x923E70
#define CXWnd__GetRelativeRect_x                                   0x923F20
#define CXWnd__GetTooltipRect_x                                    0x921E60
#define CXWnd__GetWindowTextA_x                                    0x49CE60
#define CXWnd__IsActive_x                                          0x922590
#define CXWnd__IsDescendantOf_x                                    0x924810
#define CXWnd__IsReallyVisible_x                                   0x924840
#define CXWnd__IsType_x                                            0x925FE0
#define CXWnd__Move_x                                              0x9248B0
#define CXWnd__Move1_x                                             0x924960
#define CXWnd__ProcessTransition_x                                 0x925400
#define CXWnd__Refade_x                                            0x924C00
#define CXWnd__Resize_x                                            0x924E90
#define CXWnd__Right_x                                             0x925690
#define CXWnd__SetFocus_x                                          0x925220
#define CXWnd__SetFont_x                                           0x925290
#define CXWnd__SetKeyTooltip_x                                     0x925E00
#define CXWnd__SetMouseOver_x                                      0x922DC0
#define CXWnd__StartFade_x                                         0x924700
#define CXWnd__GetChildItem_x                                      0x925AE0
#define CXWnd__SetParent_x                                         0x9245C0
#define CXWnd__Minimize_x                                          0x924F00

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x95C120

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9287D0
#define CXWndManager__DrawWindows_x                                0x9287F0
#define CXWndManager__GetKeyboardFlags_x                           0x92AFD0
#define CXWndManager__HandleKeyboardMsg_x                          0x92AB90
#define CXWndManager__RemoveWnd_x                                  0x92B1F0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x92B760

// CDBStr
#define CDBStr__GetString_x                                        0x547E70

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BFFF0
#define EQ_Character__Cur_HP_x                                     0x4D31F0
#define EQ_Character__Cur_Mana_x                                   0x4DA920
#define EQ_Character__GetCastingTimeModifier_x                     0x4C3060
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B39D0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3B20
#define EQ_Character__GetHPRegen_x                                 0x4E0810
#define EQ_Character__GetEnduranceRegen_x                          0x4E0E10
#define EQ_Character__GetManaRegen_x                               0x4E1250
#define EQ_Character__Max_Endurance_x                              0x65F5B0
#define EQ_Character__Max_HP_x                                     0x4D3020
#define EQ_Character__Max_Mana_x                                   0x65F3B0
#define EQ_Character__doCombatAbility_x                            0x6619A0
#define EQ_Character__UseSkill_x                                   0x4E3060
#define EQ_Character__GetConLevel_x                                0x657EB0
#define EQ_Character__IsExpansionFlag_x                            0x5BB380
#define EQ_Character__TotalEffect_x                                0x4C6E00
#define EQ_Character__GetPCSpellAffect_x                           0x4C3DB0
#define EQ_Character__SpellDuration_x                              0x4C38E0
#define EQ_Character__MySpellDuration_x                            0x4B2300
#define EQ_Character__GetAdjustedSkill_x                           0x4D5F70
#define EQ_Character__GetBaseSkill_x                               0x4D6F10
#define EQ_Character__CanUseItem_x                                 0x4DAC30

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BE930

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x675940

//PcClient
#define PcClient__vftable_x                                        0xAF31E8
#define PcClient__PcClient_x                                       0x655620

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BAA30
#define CCharacterListWnd__EnterWorld_x                            0x4BA400
#define CCharacterListWnd__Quit_x                                  0x4BA150
#define CCharacterListWnd__UpdateList_x                            0x4BA5F0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x639BC0
#define EQ_Item__CreateItemTagString_x                             0x8988C0
#define EQ_Item__IsStackable_x                                     0x89D630
#define EQ_Item__GetImageNum_x                                     0x89A4B0
#define EQ_Item__CreateItemClient_x                                0x638DF0
#define EQ_Item__GetItemValue_x                                    0x89B7A0
#define EQ_Item__ValueSellMerchant_x                               0x89F010
#define EQ_Item__IsKeyRingItem_x                                   0x89CEC0
#define EQ_Item__CanGoInBag_x                                      0x639CE0
#define EQ_Item__IsEmpty_x                                         0x89CA20
#define EQ_Item__GetMaxItemCount_x                                 0x89BBC0
#define EQ_Item__GetHeldItem_x                                     0x89A380
#define EQ_Item__GetAugmentFitBySlot_x                             0x898100

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x566830
#define EQ_LoadingS__Array_x                                       0xC14130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65FEB0
#define EQ_PC__GetAlternateAbilityId_x                             0x8A82F0
#define EQ_PC__GetCombatAbility_x                                  0x8A8960
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A89D0
#define EQ_PC__GetItemRecastTimer_x                                0x661F20
#define EQ_PC__HasLoreItem_x                                       0x658720
#define EQ_PC__AlertInventoryChanged_x                             0x6577F0
#define EQ_PC__GetPcZoneClient_x                                   0x684AB0
#define EQ_PC__RemoveMyAffect_x                                    0x665150
#define EQ_PC__GetKeyRingItems_x                                   0x8A92A0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A9020
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A95A0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5C1780
#define EQItemList__add_object_x                                   0x5EED90
#define EQItemList__add_item_x                                     0x5C1CE0
#define EQItemList__delete_item_x                                  0x5C1D30
#define EQItemList__FreeItemList_x                                 0x5C1C30

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x544A20

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x677240
#define EQPlayer__dEQPlayer_x                                      0x66A5B0
#define EQPlayer__DoAttack_x                                       0x67F240
#define EQPlayer__EQPlayer_x                                       0x66AC70
#define EQPlayer__SetNameSpriteState_x                             0x66EF50
#define EQPlayer__SetNameSpriteTint_x                              0x66FE30
#define PlayerBase__HasProperty_j_x                                0x98ACD0
#define EQPlayer__IsTargetable_x                                   0x98B170
#define EQPlayer__CanSee_x                                         0x98AFD0
#define EQPlayer__CanSee1_x                                        0x98B0A0
#define PlayerBase__GetVisibilityLineSegment_x                     0x98AD90

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x682540
#define PlayerZoneClient__GetLevel_x                               0x684AF0
#define PlayerZoneClient__IsValidTeleport_x                        0x5EFF10
#define PlayerZoneClient__LegalPlayerRace_x                        0x55F670

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x67A160
#define EQPlayerManager__GetSpawnByName_x                          0x67A210
#define EQPlayerManager__GetPlayerFromPartialName_x                0x67A2A0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63D2C0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63D340
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63D380
#define KeypressHandler__ClearCommandStateArray_x                  0x63E770
#define KeypressHandler__HandleKeyDown_x                           0x63E790
#define KeypressHandler__HandleKeyUp_x                             0x63E830
#define KeypressHandler__SaveKeymapping_x                          0x63EC80

// MapViewMap 
#define MapViewMap__Clear_x                                        0x776550
#define MapViewMap__SaveEx_x                                       0x779910
#define MapViewMap__SetZoom_x                                      0x77DFD0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BC9A0

// StringTable 
#define StringTable__getString_x                                   0x8B77B0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x664DC0
#define PcZoneClient__RemovePetEffect_x                            0x6653F0
#define PcZoneClient__HasAlternateAbility_x                        0x65F1E0
#define PcZoneClient__GetCurrentMod_x                              0x4E6180
#define PcZoneClient__GetModCap_x                                  0x4E6080
#define PcZoneClient__CanEquipItem_x                               0x65F890
#define PcZoneClient__GetItemByID_x                                0x662390
#define PcZoneClient__GetItemByItemClass_x                         0x6624E0
#define PcZoneClient__RemoveBuffEffect_x                           0x665410
#define PcZoneClient__BandolierSwap_x                              0x660470
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x661EC0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F4AF0

//IconCache
#define IconCache__GetIcon_x                                       0x718040

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x70FB70
#define CContainerMgr__CloseContainer_x                            0x70FE40
#define CContainerMgr__OpenExperimentContainer_x                   0x7108C0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CECA0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x631D70

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76CB10
#define CLootWnd__RequestLootSlot_x                                0x76BDE0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58E4C0
#define EQ_Spell__SpellAffects_x                                   0x58E930
#define EQ_Spell__SpellAffectBase_x                                0x58E6F0
#define EQ_Spell__IsStackable_x                                    0x4CAC50
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CAAA0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7CB0
#define EQ_Spell__IsSPAStacking_x                                  0x58F780
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58EC90
#define EQ_Spell__IsNoRemove_x                                     0x4CAC30
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58F790
#define __IsResEffectSpell_x                                       0x4C9E50

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD610

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C7070

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x815CD0
#define CTargetWnd__WndNotification_x                              0x815510
#define CTargetWnd__RefreshTargetBuffs_x                           0x8157E0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x814680

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x81A360
#define CTaskWnd__ConfirmAbandonTask_x                             0x81CFA0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x5424C0
#define CTaskManager__HandleMessage_x                              0x540920
#define CTaskManager__GetTaskStatus_x                              0x542570
#define CTaskManager__GetElementDescription_x                      0x5425F0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5895F0
#define EqSoundManager__PlayScriptMp3_x                            0x5898B0
#define EqSoundManager__SoundAssistPlay_x                          0x69D130
#define EqSoundManager__WaveInstancePlay_x                         0x69C6A0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x533880

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x946B70
#define CTextureAnimation__Draw_x                                  0x946D70

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x942B30

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56E380
#define CAltAbilityData__GetMercMaxRank_x                          0x56E310
#define CAltAbilityData__GetMaxRank_x                              0x563780

//CTargetRing
#define CTargetRing__Cast_x                                        0x62FE70

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CAA80
#define CharacterBase__CreateItemGlobalIndex_x                     0x51A540
#define CharacterBase__CreateItemIndex_x                           0x637F80
#define CharacterBase__GetItemPossession_x                         0x506350
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CF710
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CF770
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F6AA0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F72D0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F7380

//messages
#define msg_spell_worn_off_x                                       0x5B3390
#define msg_new_text_x                                             0x5A7CE0
#define __msgTokenTextParam_x                                      0x5B5630
#define msgTokenText_x                                             0x5B5880

//SpellManager
#define SpellManager__vftable_x                                    0xADB56C
#define SpellManager__SpellManager_x                               0x6A0460
#define Spellmanager__LoadTextSpells_x                             0x6A0D50
#define SpellManager__GetSpellByGroupAndRank_x                     0x6A0630

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98EC70

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x51ABC0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B98D0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x650DE0
#define ItemGlobalIndex__IsValidIndex_x                            0x51AC50

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C7A30
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C7BC0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x765350

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x714250
#define CCursorAttachment__AttachToCursor1_x                       0x714290
#define CCursorAttachment__Deactivate_x                            0x715270

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x939880
#define CSidlManagerBase__CreatePageWnd_x                          0x939080
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x935310
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x9352A0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9568A0
#define CEQSuiteTextureLoader__GetTexture_x                        0x956560

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x517830
#define CFindItemWnd__WndNotification_x                            0x518470
#define CFindItemWnd__Update_x                                     0x518FE0
#define CFindItemWnd__PickupSelectedItem_x                         0x517060

//IString
#define IString__Append_x                                          0x507B80

//Camera
#define CDisplay__cameraType_x                                     0xDEBCCC
#define EverQuest__Cameras_x                                       0xEA70A0

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x520560
#define LootFiltersManager__GetItemFilterData_x                    0x51FE70
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51FEA0
#define LootFiltersManager__SetItemLootFilter_x                    0x5200C0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BCAD0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x994890
#define CResolutionHandler__GetWindowedStyle_x                     0x697C40

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70C7A0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D34C0
#define CDistillerInfo__Instance_x                                 0x8D3460

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72B630
#define CGroupWnd__UpdateDisplay_x                                 0x72A990

//ItemBase
#define ItemBase__IsLore_x                                         0x89CF70
#define ItemBase__IsLoreEquipped_x                                 0x89CFF0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EECF0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EEE30
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EEE90

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68D1D0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x690B50

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50DF10

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4FA370
#define FactionManagerClient__HandleFactionMessage_x               0x4FA9E0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4FAFA0
#define FactionManagerClient__GetMaxFaction_x                      0x4FAFBF
#define FactionManagerClient__GetMinFaction_x                      0x4FAF70

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x506320

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91E110

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C140

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x506590

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56D810

//CTargetManager
#define CTargetManager__Get_x                                      0x6A3CC0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68D1D0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A9150

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5C1BD0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF44734

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6C0480
#define CAAWnd__UpdateSelected_x                                   0x6BCCF0
#define CAAWnd__Update_x                                           0x6BF7A0

//CXRect
#define CXRect__operator_and_x                                     0x722740

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x483260

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
