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
#define __ExpectedVersionDate                                     "Dec 14 2020"
#define __ExpectedVersionTime                                     "10:19:52"
#define __ActualVersionDate_x                                      0xAF7560
#define __ActualVersionTime_x                                      0xAF7554
#define __ActualVersionBuild_x                                     0xAE5584

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x644D10
#define __MemChecker1_x                                            0x8F83C0
#define __MemChecker2_x                                            0x6B5480
#define __MemChecker3_x                                            0x6B53D0
#define __MemChecker4_x                                            0x84E8B0
#define __EncryptPad0_x                                            0xC2D9C8
#define __EncryptPad1_x                                            0xC8B210
#define __EncryptPad2_x                                            0xC3DD90
#define __EncryptPad3_x                                            0xC3D990
#define __EncryptPad4_x                                            0xC7B7A0
#define __EncryptPad5_x                                            0xF4E0F0
#define __AC1_x                                                    0x80D1C6
#define __AC2_x                                                    0x5FE38F
#define __AC3_x                                                    0x6059E0
#define __AC4_x                                                    0x609990
#define __AC5_x                                                    0x60FC8F
#define __AC6_x                                                    0x614146
#define __AC7_x                                                    0x5FDE00
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1932E0

// Direct Input
#define DI8__Main_x                                                0xF4E118
#define DI8__Keyboard_x                                            0xF4E11C
#define DI8__Mouse_x                                               0xF4E0FC
#define DI8__Mouse_Copy_x                                          0xEA69E4
#define DI8__Mouse_Check_x                                         0xF4BC44
#define __AutoSkillArray_x                                         0xEA7900
#define __Attack_x                                                 0xF4572F
#define __Autofire_x                                               0xF45730
#define __BindList_x                                               0xC1C400
#define g_eqCommandStates_x                                        0xC1D180
#define __Clicks_x                                                 0xEA6A9C
#define __CommandList_x                                            0xC1DD40
#define __CurrentMapLabel_x                                        0xF5E14C
#define __CurrentSocial_x                                          0xC057D4
#define __DoAbilityList_x                                          0xEDD250
#define __do_loot_x                                                0x5C9E20
#define __DrawHandler_x                                            0x15DD140
#define __GroupCount_x                                             0xE9F502
#define __Guilds_x                                                 0xEA5920
#define __gWorld_x                                                 0xE9FC98
#define __HWnd_x                                                   0xF4E100
#define __heqmain_x                                                0xF4E0D8
#define __InChatMode_x                                             0xEA69CC
#define __LastTell_x                                               0xEA894C
#define __LMouseHeldTime_x                                         0xEA6B08
#define __Mouse_x                                                  0xF4E104
#define __MouseLook_x                                              0xEA6A62
#define __MouseEventTime_x                                         0xF46214
#define __gpbCommandEvent_x                                        0xE9F758
#define __NetStatusToggle_x                                        0xEA6A65
#define __PCNames_x                                                0xEA7EFC
#define __RangeAttackReady_x                                       0xEA7BE4
#define __RMouseHeldTime_x                                         0xEA6B04
#define __RunWalkState_x                                           0xEA69D0
#define __ScreenMode_x                                             0xDED4B0
#define __ScreenX_x                                                0xEA6984
#define __ScreenY_x                                                0xEA6980
#define __ScreenXMax_x                                             0xEA6988
#define __ScreenYMax_x                                             0xEA698C
#define __ServerHost_x                                             0xE9F92B
#define __ServerName_x                                             0xEDD210
#define __ShiftKeyDown_x                                           0xEA7060
#define __ShowNames_x                                              0xEA7DA0
#define EverQuestInfo__bSocialChanged_x                            0xEDD298
#define __Socials_x                                                0xEDD310
#define __SubscriptionType_x                                       0xFA2410
#define __TargetAggroHolder_x                                      0xF60B00
#define __ZoneType_x                                               0xEA6E60
#define __GroupAggro_x                                             0xF60B40
#define __LoginName_x                                              0xF4B8D4
#define __Inviter_x                                                0xF456AC
#define __AttackOnAssist_x                                         0xEA7D5C
#define __UseTellWindows_x                                         0xEA8094
#define __gfMaxZoomCameraDistance_x                                0xAEF180
#define __gfMaxCameraDistance_x                                    0xB17E00
#define __pulAutoRun_x                                             0xEA6A80
#define __pulForward_x                                             0xEA80CC
#define __pulBackward_x                                            0xEA80D0
#define __pulTurnRight_x                                           0xEA80D4
#define __pulTurnLeft_x                                            0xEA80D8
#define __pulStrafeLeft_x                                          0xEA80DC
#define __pulStrafeRight_x                                         0xEA80E0

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEA1CB8
#define instEQZoneInfo_x                                           0xEA6C58
#define pinstActiveBanker_x                                        0xE9FC44
#define pinstActiveCorpse_x                                        0xE9FC3C
#define pinstActiveGMaster_x                                       0xE9FC40
#define pinstActiveMerchant_x                                      0xE9FA34
#define pinstAltAdvManager_x                                       0xDEDEF0
#define pinstBandageTarget_x                                       0xE9FC54
#define pinstCamActor_x                                            0xDED4A4
#define pinstCDBStr_x                                              0xDECC0C
#define pinstCDisplay_x                                            0xE9FCA4
#define pinstCEverQuest_x                                          0xF4B19C
#define pinstEverQuestInfo_x                                       0xEA6978
#define pinstCharData_x                                            0xE9F744
#define pinstCharSpawn_x                                           0xE9FC8C
#define pinstControlledMissile_x                                   0xE9FCA0
#define pinstControlledPlayer_x                                    0xE9FC8C
#define pinstCResolutionHandler_x                                  0x15DD370
#define pinstCSidlManager_x                                        0x15DC308
#define pinstCXWndManager_x                                        0x15DC304
#define instDynamicZone_x                                          0xEA57F8
#define pinstDZMember_x                                            0xEA5908
#define pinstDZTimerInfo_x                                         0xEA590C
#define pinstEqLogin_x                                             0xF4B220
#define instEQMisc_x                                               0xDECB50
#define pinstEQSoundManager_x                                      0xDEEEC0
#define pinstEQSpellStrings_x                                      0xCAF448
#define instExpeditionLeader_x                                     0xEA5842
#define instExpeditionName_x                                       0xEA5882
#define pinstGroup_x                                               0xE9F4FE
#define pinstImeManager_x                                          0x15DC300
#define pinstLocalPlayer_x                                         0xE9F824
#define pinstMercenaryData_x                                       0xF47D0C
#define pinstMercenaryStats_x                                      0xF60BCC
#define pinstModelPlayer_x                                         0xE9FC4C
#define pinstPCData_x                                              0xE9F744
#define pinstSkillMgr_x                                            0xF49E68
#define pinstSpawnManager_x                                        0xF48910
#define pinstSpellManager_x                                        0xF4A0A8
#define pinstSpellSets_x                                           0xF3E358
#define pinstStringTable_x                                         0xE9F74C
#define pinstSwitchManager_x                                       0xE9F258
#define pinstTarget_x                                              0xE9FC88
#define pinstTargetObject_x                                        0xE9FC94
#define pinstTargetSwitch_x                                        0xE9FCAC
#define pinstTaskMember_x                                          0xDEC9E0
#define pinstTrackTarget_x                                         0xE9FC90
#define pinstTradeTarget_x                                         0xE9FC48
#define instTributeActive_x                                        0xDECB71
#define pinstViewActor_x                                           0xDED4A0
#define pinstWorldData_x                                           0xE9F3A8
#define pinstZoneAddr_x                                            0xEA6EF8
#define pinstPlayerPath_x                                          0xF489A8
#define pinstTargetIndicator_x                                     0xF4A310
#define EQObject_Top_x                                             0xE9F820
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDECF44
#define pinstCAchievementsWnd_x                                    0xDED45C
#define pinstCActionsWnd_x                                         0xDECF80
#define pinstCAdvancedDisplayOptionsWindow_x                       0xDED51C
#define pinstCAdvancedLootWnd_x                                    0xDED4CC
#define pinstCAdventureLeaderboardWnd_x                            0xF57920
#define pinstCAdventureRequestWnd_x                                0xF579D0
#define pinstCAdventureStatsWnd_x                                  0xF57A80
#define pinstCAggroMeterWnd_x                                      0xDED500
#define pinstCAlarmWnd_x                                           0xDED488
#define pinstCAlertHistoryWnd_x                                    0xDECEF4
#define pinstCAlertStackWnd_x                                      0xDED4E8
#define pinstCAlertWnd_x                                           0xDED4FC
#define pinstCAltStorageWnd_x                                      0xF57DE0
#define pinstCAudioTriggersWindow_x                                0xCA1778
#define pinstCAuraWnd_x                                            0xDED4D0
#define pinstCAvaZoneWnd_x                                         0xDECEF8
#define pinstCBandolierWnd_x                                       0xDED514
#define pinstCBankWnd_x                                            0xDECCB8
#define pinstCBarterMerchantWnd_x                                  0xF59020
#define pinstCBarterSearchWnd_x                                    0xF590D0
#define pinstCBarterWnd_x                                          0xF59180
#define pinstCBazaarConfirmationWnd_x                              0xDED498
#define pinstCBazaarSearchWnd_x                                    0xDECF48
#define pinstCBazaarWnd_x                                          0xDED464
#define pinstCBlockedBuffWnd_x                                     0xDED4DC
#define pinstCBlockedPetBuffWnd_x                                  0xDED504
#define pinstCBodyTintWnd_x                                        0xDED40C
#define pinstCBookWnd_x                                            0xDECCAC
#define pinstCBreathWnd_x                                          0xDECF58
#define pinstCBuffWindowNORMAL_x                                   0xDED4C4
#define pinstCBuffWindowSHORT_x                                    0xDED4C8
#define pinstCBugReportWnd_x                                       0xDECCB4
#define pinstCButtonWnd_x                                          0x15DC570
#define pinstCCastingWnd_x                                         0xDED540
#define pinstCCastSpellWnd_x                                       0xDECF54
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDED418
#define pinstCChatWindowManager_x                                  0xF59C40
#define pinstCClaimWnd_x                                           0xF59D98
#define pinstCColorPickerWnd_x                                     0xDECF0C
#define pinstCCombatAbilityWnd_x                                   0xDED478
#define pinstCCombatSkillsSelectWnd_x                              0xDED42C
#define pinstCCompassWnd_x                                         0xDECF84
#define pinstCConfirmationDialog_x                                 0xF5EC98
#define pinstCContainerMgr_x                                       0xDED408
#define pinstCContextMenuManager_x                                 0x15DC2C0
#define pinstCCursorAttachment_x                                   0xDED534
#define pinstCDynamicZoneWnd_x                                     0xF5A360
#define pinstCEditLabelWnd_x                                       0xDED4C0
#define pinstCEQMainWnd_x                                          0xF5A5A8
#define pinstCEventCalendarWnd_x                                   0xDECF4C
#define pinstCExtendedTargetWnd_x                                  0xDED4E0
#define pinstCPlayerCustomizationWnd_x                             0xDED430
#define pinstCFactionWnd_x                                         0xDED450
#define pinstCFellowshipWnd_x                                      0xF5A7A8
#define pinstCFileSelectionWnd_x                                   0xDECF08
#define pinstCFindItemWnd_x                                        0xDED444
#define pinstCFindLocationWnd_x                                    0xF5A900
#define pinstCFriendsWnd_x                                         0xDED440
#define pinstCGemsGameWnd_x                                        0xDED44C
#define pinstCGiveWnd_x                                            0xDED48C
#define pinstCGroupSearchFiltersWnd_x                              0xDED518
#define pinstCGroupSearchWnd_x                                     0xF5ACF8
#define pinstCGroupWnd_x                                           0xF5ADA8
#define pinstCGuildBankWnd_x                                       0xF5AE58
#define pinstCGuildCreationWnd_x                                   0xF5AF08
#define pinstCGuildMgmtWnd_x                                       0xF5AFB8
#define pinstCharacterCreation_x                                   0xDED438
#define pinstCHelpWnd_x                                            0xDED484
#define pinstCHeritageSelectionWnd_x                               0xDED43C
#define pinstCHotButtonWnd_x                                       0xF5D110
#define pinstCHotButtonWnd1_x                                      0xF5D110
#define pinstCHotButtonWnd2_x                                      0xF5D114
#define pinstCHotButtonWnd3_x                                      0xF5D118
#define pinstCHotButtonWnd4_x                                      0xF5D11C
#define pinstCIconSelectionWnd_x                                   0xDED528
#define pinstCInspectWnd_x                                         0xDED508
#define pinstCInventoryWnd_x                                       0xDED4D4
#define pinstCInvSlotMgr_x                                         0xDECF38
#define pinstCItemDisplayManager_x                                 0xF5D6A0
#define pinstCItemExpTransferWnd_x                                 0xF5D7D0
#define pinstCItemOverflowWnd_x                                    0xDECF50
#define pinstCJournalCatWnd_x                                      0xDECF24
#define pinstCJournalNPCWnd_x                                      0xDECEE4
#define pinstCJournalTextWnd_x                                     0xDECEE4
#define pinstCKeyRingWnd_x                                         0xDED53C
#define pinstCLargeDialogWnd_x                                     0xF5F918
#define pinstCLayoutCopyWnd_x                                      0xF5DB20
#define pinstCLFGuildWnd_x                                         0xF5DBD0
#define pinstCLoadskinWnd_x                                        0xDED468
#define pinstCLootFiltersCopyWnd_x                                 0xCBDEE8
#define pinstCLootFiltersWnd_x                                     0xDED4EC
#define pinstCLootSettingsWnd_x                                    0xDED510
#define pinstCLootWnd_x                                            0xDECF28
#define pinstCMailAddressBookWnd_x                                 0xDECF3C
#define pinstCMailCompositionWnd_x                                 0xDECF14
#define pinstCMailIgnoreListWnd_x                                  0xDECF40
#define pinstCMailWnd_x                                            0xDECF00
#define pinstCManageLootWnd_x                                      0xDEE3A0
#define pinstCMapToolbarWnd_x                                      0xDED490
#define pinstCMapViewWnd_x                                         0xDED458
#define pinstCMarketplaceWnd_x                                     0xDED4F0
#define pinstCMerchantWnd_x                                        0xDECF34
#define pinstCMIZoneSelectWnd_x                                    0xF5E408
#define pinstCMusicPlayerWnd_x                                     0xDECED4
#define pinstCNameChangeMercWnd_x                                  0xDED494
#define pinstCNameChangePetWnd_x                                   0xDED460
#define pinstCNameChangeWnd_x                                      0xDED4BC
#define pinstCNoteWnd_x                                            0xDED470
#define pinstCObjectPreviewWnd_x                                   0xDED50C
#define pinstCOptionsWnd_x                                         0xDED47C
#define pinstCPetInfoWnd_x                                         0xDECEFC
#define pinstCPetitionQWnd_x                                       0xDED428
#define pinstCPlayerNotesWnd_x                                     0xDED410
#define pinstCPlayerWnd_x                                          0xDECEF0
#define pinstCPopupWndManager_x                                    0xF5EC98
#define pinstCProgressionSelectionWnd_x                            0xF5ED48
#define pinstCPurchaseGroupWnd_x                                   0xDECCC8
#define pinstCPurchaseWnd_x                                        0xDED544
#define pinstCPvPLeaderboardWnd_x                                  0xF5EDF8
#define pinstCPvPStatsWnd_x                                        0xF5EEA8
#define pinstCQuantityWnd_x                                        0xDECEE0
#define pinstCRaceChangeWnd_x                                      0xDED4D8
#define pinstCRaidOptionsWnd_x                                     0xDED520
#define pinstCRaidWnd_x                                            0xDECF30
#define pinstCRealEstateItemsWnd_x                                 0xDED454
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDED000
#define pinstCRealEstateManageWnd_x                                0xDECED0
#define pinstCRealEstateNeighborhoodWnd_x                          0xDECEEC
#define pinstCRealEstatePlotSearchWnd_x                            0xDECF04
#define pinstCRealEstatePurchaseWnd_x                              0xDECF20
#define pinstCRespawnWnd_x                                         0xDED4F8
#define pinstCRewardSelectionWnd_x                                 0xF5F5F0
#define pinstCSelectorWnd_x                                        0xDED424
#define pinstCSendMoneyWnd_x                                       0xDED49C
#define pinstCServerListWnd_x                                      0xDECF2C
#define pinstCSkillsSelectWnd_x                                    0xDED420
#define pinstCSkillsWnd_x                                          0xDECFFC
#define pinstCSocialEditWnd_x                                      0xDED538
#define pinstCSocialWnd_x                                          0xDED480
#define pinstCSpellBookWnd_x                                       0xDED474
#define pinstCStoryWnd_x                                           0xDECF7C
#define pinstCTargetOfTargetWnd_x                                  0xF60C50
#define pinstCTargetWnd_x                                          0xDED4F4
#define pinstCTaskOverlayWnd_x                                     0xDECCC0
#define pinstCTaskSelectWnd_x                                      0xF60DA8
#define pinstCTaskManager_x                                        0xCBE828
#define pinstCTaskTemplateSelectWnd_x                              0xF60E58
#define pinstCTaskWnd_x                                            0xF60F08
#define pinstCTextEntryWnd_x                                       0xDECCA8
#define pinstCTimeLeftWnd_x                                        0xDED41C
#define pinstCTipWndCONTEXT_x                                      0xF6110C
#define pinstCTipWndOFDAY_x                                        0xF61108
#define pinstCTitleWnd_x                                           0xF611B8
#define pinstCTrackingWnd_x                                        0xDED4E4
#define pinstCTradeskillWnd_x                                      0xF61320
#define pinstCTradeWnd_x                                           0xDED414
#define pinstCTrainWnd_x                                           0xDECF18
#define pinstCTributeBenefitWnd_x                                  0xF61520
#define pinstCTributeMasterWnd_x                                   0xF615D0
#define pinstCTributeTrophyWnd_x                                   0xF61680
#define pinstCVideoModesWnd_x                                      0xDECCBC
#define pinstCVoiceMacroWnd_x                                      0xF4A8C8
#define pinstCVoteResultsWnd_x                                     0xDED448
#define pinstCVoteWnd_x                                            0xDED434
#define pinstCWebManager_x                                         0xF4AF44
#define pinstCZoneGuideWnd_x                                       0xDECCC4
#define pinstCZonePathWnd_x                                        0xDECEDC

#define pinstEQSuiteTextureLoader_x                                0xC8BB30
#define pinstItemIconCache_x                                       0xF5A560
#define pinstLootFiltersManager_x                                  0xCBDF98
#define pinstRewardSelectionWnd_x                                  0xF5F5F0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5C5510
#define __CastRay2_x                                               0x5C5560
#define __ConvertItemTags_x                                        0x5E1230
#define __CleanItemTags_x                                          0x47D190
#define __DoesFileExist_x                                          0x8FB4A0
#define __EQGetTime_x                                              0x8F7FF0
#define __ExecuteCmd_x                                             0x5BDEA0
#define __FixHeading_x                                             0x98D880
#define __FlushDxKeyboard_x                                        0x6B1320
#define __GameLoop_x                                               0x6B4650
#define __get_bearing_x                                            0x5C5070
#define __get_melee_range_x                                        0x5C5750
#define __GetAnimationCache_x                                      0x719AC0
#define __GetGaugeValueFromEQ_x                                    0x80B670
#define __GetLabelFromEQ_x                                         0x80D150
#define __GetXTargetType_x                                         0x98F260
#define __HandleMouseWheel_x                                       0x6B5530
#define __HeadingDiff_x                                            0x98D8F0
#define __HelpPath_x                                               0xF45E04
#define __LoadFrontEnd_x                                           0x6B1960
#define __NewUIINI_x                                               0x80B340
#define __ProcessGameEvents_x                                      0x626020
#define __ProcessMouseEvent_x                                      0x6257B0
#define __SaveColors_x                                             0x55DB50
#define __STMLToText_x                                             0x930C90
#define __ToggleKeyRingItem_x                                      0x51C370
#define CMemoryMappedFile__SetFile_x                               0xA7CB80
#define CrashDetected_x                                            0x6B3410
#define DrawNetStatus_x                                            0x6522B0
#define Expansion_HoT_x                                            0xEA7D48
#define Teleport_Table_Size_x                                      0xE9F7E0
#define Teleport_Table_x                                           0xE9FCB0
#define Util__FastTime_x                                           0x8F7BC0
#define __CopyLayout_x                                             0x640420
#define __WndProc_x                                                0x6B3910
#define __ProcessKeyboardEvent_x                                   0x6B2EB0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490400
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4993F0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4991C0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x4939A0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492DF0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x565DC0
#define AltAdvManager__IsAbilityReady_x                            0x564B60
#define AltAdvManager__GetAAById_x                                 0x564EF0
#define AltAdvManager__CanTrainAbility_x                           0x564F60
#define AltAdvManager__CanSeeAbility_x                             0x5652C0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CAED0
#define CharacterZoneClient__HasSkill_x                            0x4D5D50
#define CharacterZoneClient__MakeMeVisible_x                       0x4D7470
#define CharacterZoneClient__IsStackBlocked_x                      0x4C26D0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBB60
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9E20
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9F00
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9FE0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C47C0
#define CharacterZoneClient__BardCastBard_x                        0x4C71F0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF570
#define CharacterZoneClient__GetEffect_x                           0x4BBAA0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C5830
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C5900
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C5950
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5AA0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5C80
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3AC0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D83D0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7E50

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6DB230
#define CBankWnd__WndNotification_x                                0x6DB000

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E8D90

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x92E450
#define CButtonWnd__CButtonWnd_x                                   0x92D030

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x708C60
#define CChatManager__InitContextMenu_x                            0x701D90
#define CChatManager__FreeChatWindow_x                             0x7077A0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9900
#define CChatManager__SetLockedActiveChatWindow_x                  0x7088E0
#define CChatManager__CreateChatWindow_x                           0x707DE0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9A10

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x941610
#define CContextMenu__dCContextMenu_x                              0x941850
#define CContextMenu__AddMenuItem_x                                0x941860
#define CContextMenu__RemoveMenuItem_x                             0x941B70
#define CContextMenu__RemoveAllMenuItems_x                         0x941B90
#define CContextMenu__CheckMenuItem_x                              0x941C10
#define CContextMenu__SetMenuItem_x                                0x941A90
#define CContextMenu__AddSeparator_x                               0x9419F0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x9421B0
#define CContextMenuManager__RemoveMenu_x                          0x942220
#define CContextMenuManager__PopupMenu_x                           0x9422E0
#define CContextMenuManager__Flush_x                               0x942150
#define CContextMenuManager__GetMenu_x                             0x49B690
#define CContextMenuManager__CreateDefaultMenu_x                   0x714420

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D2D30
#define CChatService__GetFriendName_x                              0x8D2D40

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x709490
#define CChatWindow__Clear_x                                       0x70A760
#define CChatWindow__WndNotification_x                             0x70AEF0
#define CChatWindow__AddHistory_x                                  0x70A020

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93EA70
#define CComboWnd__Draw_x                                          0x93DF60
#define CComboWnd__GetCurChoice_x                                  0x93E8B0
#define CComboWnd__GetListRect_x                                   0x93E410
#define CComboWnd__GetTextRect_x                                   0x93EAE0
#define CComboWnd__InsertChoice_x                                  0x93E5A0
#define CComboWnd__SetColors_x                                     0x93E570
#define CComboWnd__SetChoice_x                                     0x93E880
#define CComboWnd__GetItemCount_x                                  0x93E8C0
#define CComboWnd__GetCurChoiceText_x                              0x93E900
#define CComboWnd__GetChoiceText_x                                 0x93E8D0
#define CComboWnd__InsertChoiceAtIndex_x                           0x93E640

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x711E50
#define CContainerWnd__vftable_x                                   0xB0075C
#define CContainerWnd__SetContainer_x                              0x7133A0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x5584B0
#define CDisplay__PreZoneMainUI_x                                  0x5584C0
#define CDisplay__CleanGameUI_x                                    0x55D910
#define CDisplay__GetClickedActor_x                                0x550910
#define CDisplay__GetUserDefinedColor_x                            0x548F80
#define CDisplay__GetWorldFilePath_x                               0x552380
#define CDisplay__is3dON_x                                         0x54D570
#define CDisplay__ReloadUI_x                                       0x5579C0
#define CDisplay__WriteTextHD2_x                                   0x54D360
#define CDisplay__TrueDistance_x                                   0x554040
#define CDisplay__SetViewActor_x                                   0x550230
#define CDisplay__GetFloorHeight_x                                 0x54D630
#define CDisplay__SetRenderWindow_x                                0x54BFB0
#define CDisplay__ToggleScreenshotMode_x                           0x54FD00

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x961380

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x944B00
#define CEditWnd__EnsureCaretVisible_x                             0x946CD0
#define CEditWnd__GetCaretPt_x                                     0x945C80
#define CEditWnd__GetCharIndexPt_x                                 0x945A30
#define CEditWnd__GetDisplayString_x                               0x9458D0
#define CEditWnd__GetHorzOffset_x                                  0x9441A0
#define CEditWnd__GetLineForPrintableChar_x                        0x946BD0
#define CEditWnd__GetSelStartPt_x                                  0x945CE0
#define CEditWnd__GetSTMLSafeText_x                                0x9456F0
#define CEditWnd__PointFromPrintableChar_x                         0x946800
#define CEditWnd__SelectableCharFromPoint_x                        0x946970
#define CEditWnd__SetEditable_x                                    0x945DB0
#define CEditWnd__SetWindowTextA_x                                 0x945470
#define CEditWnd__ReplaceSelection_x                               0x946470
#define CEditWnd__ReplaceSelection1_x                              0x9463F0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x613620
#define CEverQuest__ClickedPlayer_x                                0x6057C0
#define CEverQuest__CreateTargetIndicator_x                        0x623190
#define CEverQuest__DeleteTargetIndicator_x                        0x623220
#define CEverQuest__DoTellWindow_x                                 0x4E9AF0
#define CEverQuest__OutputTextToLog_x                              0x4E9DC0
#define CEverQuest__DropHeldItemOnGround_x                         0x5FA920
#define CEverQuest__dsp_chat_x                                     0x4EA150
#define CEverQuest__trimName_x                                     0x61F340
#define CEverQuest__Emote_x                                        0x613E80
#define CEverQuest__EnterZone_x                                    0x60DF80
#define CEverQuest__GetBodyTypeDesc_x                              0x6188D0
#define CEverQuest__GetClassDesc_x                                 0x618F10
#define CEverQuest__GetClassThreeLetterCode_x                      0x619510
#define CEverQuest__GetDeityDesc_x                                 0x6219E0
#define CEverQuest__GetLangDesc_x                                  0x6196D0
#define CEverQuest__GetRaceDesc_x                                  0x618EF0
#define CEverQuest__InterpretCmd_x                                 0x621FB0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FEAB0
#define CEverQuest__LMouseUp_x                                     0x5FCE40
#define CEverQuest__RightClickedOnPlayer_x                         0x5FF390
#define CEverQuest__RMouseUp_x                                     0x5FDDC0
#define CEverQuest__SetGameState_x                                 0x5FA6B0
#define CEverQuest__UPCNotificationFlush_x                         0x61F240
#define CEverQuest__IssuePetCommand_x                              0x61AAE0
#define CEverQuest__ReportSuccessfulHit_x                          0x6151D0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x723B50
#define CGaugeWnd__CalcLinesFillRect_x                             0x723BB0
#define CGaugeWnd__Draw_x                                          0x7231D0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AFDC0
#define CGuild__GetGuildName_x                                     0x4AE870
#define CGuild__GetGuildIndex_x                                    0x4AEE70

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73D7B0

//CHotButton
#define CHotButton__SetCheck_x                                     0x634890
#define CHotButton__SetButtonSize_x                                0x634C50

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x74A9F0
#define CInvSlotMgr__MoveItem_x                                    0x7496C0
#define CInvSlotMgr__SelectSlot_x                                  0x74AAC0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x747EF0
#define CInvSlot__SliderComplete_x                                 0x745C30
#define CInvSlot__GetItemBase_x                                    0x7455B0
#define CInvSlot__UpdateItem_x                                     0x745720

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x74C540
#define CInvSlotWnd__CInvSlotWnd_x                                 0x74B6E0
#define CInvSlotWnd__HandleLButtonUp_x                             0x74C0C0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x806A00
#define CItemDisplayWnd__UpdateStrings_x                           0x75AD20
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x7549B0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x754EE0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x75B330
#define CItemDisplayWnd__AboutToShow_x                             0x75A970
#define CItemDisplayWnd__WndNotification_x                         0x75C5B0
#define CItemDisplayWnd__RequestConvertItem_x                      0x75BEE0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x7599D0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x75A790

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x837530

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x760AD0

// CLabel 
#define CLabel__Draw_x                                             0x766500

// CListWnd
#define CListWnd__CListWnd_x                                       0x917100
#define CListWnd__dCListWnd_x                                      0x917420
#define CListWnd__AddColumn_x                                      0x91B890
#define CListWnd__AddColumn1_x                                     0x91B8E0
#define CListWnd__AddLine_x                                        0x91BC70
#define CListWnd__AddString_x                                      0x91BA70
#define CListWnd__CalculateFirstVisibleLine_x                      0x91B650
#define CListWnd__CalculateVSBRange_x                              0x91B430
#define CListWnd__ClearSel_x                                       0x91C450
#define CListWnd__ClearAllSel_x                                    0x91C4B0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x91CED0
#define CListWnd__Compare_x                                        0x91AD60
#define CListWnd__Draw_x                                           0x917550
#define CListWnd__DrawColumnSeparators_x                           0x919D30
#define CListWnd__DrawHeader_x                                     0x91A1A0
#define CListWnd__DrawItem_x                                       0x91A6A0
#define CListWnd__DrawLine_x                                       0x919EA0
#define CListWnd__DrawSeparator_x                                  0x919DD0
#define CListWnd__EnableLine_x                                     0x919610
#define CListWnd__EnsureVisible_x                                  0x91CDF0
#define CListWnd__ExtendSel_x                                      0x91C380
#define CListWnd__GetColumnTooltip_x                               0x919150
#define CListWnd__GetColumnMinWidth_x                              0x9191C0
#define CListWnd__GetColumnWidth_x                                 0x9190C0
#define CListWnd__GetCurSel_x                                      0x918A50
#define CListWnd__GetItemAtPoint_x                                 0x919890
#define CListWnd__GetItemAtPoint1_x                                0x919900
#define CListWnd__GetItemData_x                                    0x918AD0
#define CListWnd__GetItemHeight_x                                  0x918E90
#define CListWnd__GetItemIcon_x                                    0x918C60
#define CListWnd__GetItemRect_x                                    0x919700
#define CListWnd__GetItemText_x                                    0x918B10
#define CListWnd__GetSelList_x                                     0x91C500
#define CListWnd__GetSeparatorRect_x                               0x919B40
#define CListWnd__InsertLine_x                                     0x91C060
#define CListWnd__RemoveLine_x                                     0x91C1B0
#define CListWnd__SetColors_x                                      0x91B400
#define CListWnd__SetColumnJustification_x                         0x91B130
#define CListWnd__SetColumnLabel_x                                 0x91BA10
#define CListWnd__SetColumnWidth_x                                 0x91B050
#define CListWnd__SetCurSel_x                                      0x91C2C0
#define CListWnd__SetItemColor_x                                   0x91CAA0
#define CListWnd__SetItemData_x                                    0x91CA60
#define CListWnd__SetItemText_x                                    0x91C670
#define CListWnd__ShiftColumnSeparator_x                           0x91B1F0
#define CListWnd__Sort_x                                           0x91AEE0
#define CListWnd__ToggleSel_x                                      0x91C2F0
#define CListWnd__SetColumnsSizable_x                              0x91B2A0
#define CListWnd__SetItemWnd_x                                     0x91C920
#define CListWnd__GetItemWnd_x                                     0x918CB0
#define CListWnd__SetItemIcon_x                                    0x91C6F0
#define CListWnd__CalculateCustomWindowPositions_x                 0x91B750
#define CListWnd__SetVScrollPos_x                                  0x91B030

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x77BBE0
#define CMapViewWnd__GetWorldCoordinates_x                         0x77A2F0
#define CMapViewWnd__HandleLButtonDown_x                           0x777330

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x79BF80
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79C860
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79CD90
#define CMerchantWnd__SelectRecoverySlot_x                         0x79FD40
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x79AAF0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A5910
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x79BB90

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8A0880
#define CPacketScrambler__hton_x                                   0x8A0870

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x936250
#define CSidlManager__FindScreenPieceTemplate_x                    0x936660
#define CSidlManager__FindScreenPieceTemplate1_x                   0x936450
#define CSidlManager__CreateLabel_x                                0x7FDBB0
#define CSidlManager__CreateXWndFromTemplate_x                     0x9395C0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x939790
#define CSidlManager__CreateXWnd_x                                 0x7FDAE0
#define CSidlManager__CreateHotButtonWnd_x                         0x7FE0B0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x932D30
#define CSidlScreenWnd__CalculateVSBRange_x                        0x932C30
#define CSidlScreenWnd__ConvertToRes_x                             0x95BEC0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x932720
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x932410
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x9324E0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x9325B0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x9331D0
#define CSidlScreenWnd__EnableIniStorage_x                         0x9336A0
#define CSidlScreenWnd__GetSidlPiece_x                             0x9333C0
#define CSidlScreenWnd__Init1_x                                    0x932030
#define CSidlScreenWnd__LoadIniInfo_x                              0x9336F0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x934230
#define CSidlScreenWnd__LoadSidlScreen_x                           0x931450
#define CSidlScreenWnd__StoreIniInfo_x                             0x933DB0
#define CSidlScreenWnd__StoreIniVis_x                              0x934110
#define CSidlScreenWnd__WndNotification_x                          0x9330E0
#define CSidlScreenWnd__GetChildItem_x                             0x933620
#define CSidlScreenWnd__HandleLButtonUp_x                          0x922DF0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15DC190

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x69A3E0
#define CSkillMgr__GetSkillCap_x                                   0x69A5C0
#define CSkillMgr__GetNameToken_x                                  0x699B60
#define CSkillMgr__IsActivatedSkill_x                              0x699CA0
#define CSkillMgr__IsCombatSkill_x                                 0x699BE0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x942F80
#define CSliderWnd__SetValue_x                                     0x942DF0
#define CSliderWnd__SetNumTicks_x                                  0x942E50

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x803D00

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x94B8D0
#define CStmlWnd__ParseSTML_x                                      0x94CBE0
#define CStmlWnd__CalculateHSBRange_x                              0x94C9B0
#define CStmlWnd__CalculateVSBRange_x                              0x94C920
#define CStmlWnd__CanBreakAtCharacter_x                            0x950CF0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x951980
#define CStmlWnd__ForceParseNow_x                                  0x94BE70
#define CStmlWnd__GetNextTagPiece_x                                0x950C50
#define CStmlWnd__GetSTMLText_x                                    0x50D880
#define CStmlWnd__GetVisibleText_x                                 0x94BE90
#define CStmlWnd__InitializeWindowVariables_x                      0x9517D0
#define CStmlWnd__MakeStmlColorTag_x                               0x94AF40
#define CStmlWnd__MakeWndNotificationTag_x                         0x94AFB0
#define CStmlWnd__SetSTMLText_x                                    0x949FF0
#define CStmlWnd__StripFirstSTMLLines_x                            0x952A80
#define CStmlWnd__UpdateHistoryString_x                            0x951B90

// CTabWnd 
#define CTabWnd__Draw_x                                            0x949130
#define CTabWnd__DrawCurrentPage_x                                 0x949860
#define CTabWnd__DrawTab_x                                         0x949580
#define CTabWnd__GetCurrentPage_x                                  0x948930
#define CTabWnd__GetPageInnerRect_x                                0x948B70
#define CTabWnd__GetTabInnerRect_x                                 0x948AB0
#define CTabWnd__GetTabRect_x                                      0x948960
#define CTabWnd__InsertPage_x                                      0x948D80
#define CTabWnd__RemovePage_x                                      0x948EF0
#define CTabWnd__SetPage_x                                         0x948BF0
#define CTabWnd__SetPageRect_x                                     0x949070
#define CTabWnd__UpdatePage_x                                      0x949440
#define CTabWnd__GetPageFromTabIndex_x                             0x9494C0
#define CTabWnd__GetCurrentTabIndex_x                              0x948920

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x760F00
#define CPageWnd__SetTabText_x                                     0x948480
#define CPageWnd__FlashTab_x                                       0x9484E0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A90A0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91FCA0
#define CTextureFont__GetTextExtent_x                              0x91FE60

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AE4F0
#define CHtmlComponentWnd__ValidateUri_x                           0x73F1A0
#define CHtmlWnd__SetClientCallbacks_x                             0x639CD0
#define CHtmlWnd__AddObserver_x                                    0x639CF0
#define CHtmlWnd__RemoveObserver_x                                 0x639D50
#define Window__getProgress_x                                      0x855E70
#define Window__getStatus_x                                        0x855E90
#define Window__getURI_x                                           0x855EA0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x958CD0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x90CD80

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9640
#define CXStr__CXStr1_x                                            0x915790
#define CXStr__CXStr3_x                                            0x8F3F70
#define CXStr__dCXStr_x                                            0x4783D0
#define CXStr__operator_equal_x                                    0x8F41A0
#define CXStr__operator_equal1_x                                   0x8F41E0
#define CXStr__operator_plus_equal1_x                              0x8F4C70
#define CXStr__SetString_x                                         0x8F6B60
#define CXStr__operator_char_p_x                                   0x8F46B0
#define CXStr__GetChar_x                                           0x8F6490
#define CXStr__Delete_x                                            0x8F5D60
#define CXStr__GetUnicode_x                                        0x8F6500
#define CXStr__GetLength_x                                         0x4A8E50
#define CXStr__Mid_x                                               0x47D540
#define CXStr__Insert_x                                            0x8F6560
#define CXStr__FindNext_x                                          0x8F61D0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x941230
#define CXWnd__BringToTop_x                                        0x926600
#define CXWnd__Center_x                                            0x926180
#define CXWnd__ClrFocus_x                                          0x925FA0
#define CXWnd__Destroy_x                                           0x926040
#define CXWnd__DoAllDrawing_x                                      0x922580
#define CXWnd__DrawChildren_x                                      0x922550
#define CXWnd__DrawColoredRect_x                                   0x9229E0
#define CXWnd__DrawTooltip_x                                       0x921090
#define CXWnd__DrawTooltipAtPoint_x                                0x921150
#define CXWnd__GetBorderFrame_x                                    0x922840
#define CXWnd__GetChildWndAt_x                                     0x9266A0
#define CXWnd__GetClientClipRect_x                                 0x924820
#define CXWnd__GetScreenClipRect_x                                 0x9248F0
#define CXWnd__GetScreenRect_x                                     0x924AC0
#define CXWnd__GetRelativeRect_x                                   0x924B90
#define CXWnd__GetTooltipRect_x                                    0x922A30
#define CXWnd__GetWindowTextA_x                                    0x49CDB0
#define CXWnd__IsActive_x                                          0x923170
#define CXWnd__IsDescendantOf_x                                    0x9254E0
#define CXWnd__IsReallyVisible_x                                   0x925510
#define CXWnd__IsType_x                                            0x926D10
#define CXWnd__Move_x                                              0x925570
#define CXWnd__Move1_x                                             0x925630
#define CXWnd__ProcessTransition_x                                 0x926130
#define CXWnd__Refade_x                                            0x925910
#define CXWnd__Resize_x                                            0x925BB0
#define CXWnd__Right_x                                             0x9263C0
#define CXWnd__SetFocus_x                                          0x925F60
#define CXWnd__SetFont_x                                           0x925FD0
#define CXWnd__SetKeyTooltip_x                                     0x926B30
#define CXWnd__SetMouseOver_x                                      0x9239B0
#define CXWnd__StartFade_x                                         0x9253C0
#define CXWnd__GetChildItem_x                                      0x926810
#define CXWnd__SetParent_x                                         0x925270
#define CXWnd__Minimize_x                                          0x925C20

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x95CF40

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9295A0
#define CXWndManager__DrawWindows_x                                0x9295C0
#define CXWndManager__GetKeyboardFlags_x                           0x92BCE0
#define CXWndManager__HandleKeyboardMsg_x                          0x92B890
#define CXWndManager__RemoveWnd_x                                  0x92BF10
#define CXWndManager__RemovePendingDeletionWnd_x                   0x92C470

// CDBStr
#define CDBStr__GetString_x                                        0x547F40

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BFCD0
#define EQ_Character__Cur_HP_x                                     0x4D2D90
#define EQ_Character__Cur_Mana_x                                   0x4DA4E0
#define EQ_Character__GetCastingTimeModifier_x                     0x4C2D40
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B3700
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3850
#define EQ_Character__GetHPRegen_x                                 0x4E03D0
#define EQ_Character__GetEnduranceRegen_x                          0x4E09D0
#define EQ_Character__GetManaRegen_x                               0x4E0E10
#define EQ_Character__Max_Endurance_x                              0x660680
#define EQ_Character__Max_HP_x                                     0x4D2BC0
#define EQ_Character__Max_Mana_x                                   0x660480
#define EQ_Character__doCombatAbility_x                            0x662A60
#define EQ_Character__UseSkill_x                                   0x4E2C10
#define EQ_Character__GetConLevel_x                                0x659250
#define EQ_Character__IsExpansionFlag_x                            0x5BC690
#define EQ_Character__TotalEffect_x                                0x4C6AE0
#define EQ_Character__GetPCSpellAffect_x                           0x4C3A90
#define EQ_Character__SpellDuration_x                              0x4C35C0
#define EQ_Character__MySpellDuration_x                            0x4B2030
#define EQ_Character__GetAdjustedSkill_x                           0x4D5B10
#define EQ_Character__GetBaseSkill_x                               0x4D6AB0
#define EQ_Character__CanUseItem_x                                 0x4DA7F0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BFD40

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x676970

//PcClient
#define PcClient__vftable_x                                        0xAF41DC
#define PcClient__PcClient_x                                       0x6569C0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA710
#define CCharacterListWnd__EnterWorld_x                            0x4BA0E0
#define CCharacterListWnd__Quit_x                                  0x4B9E30
#define CCharacterListWnd__UpdateList_x                            0x4BA2D0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x63AE90
#define EQ_Item__CreateItemTagString_x                             0x899D20
#define EQ_Item__IsStackable_x                                     0x89EA70
#define EQ_Item__GetImageNum_x                                     0x89B8B0
#define EQ_Item__CreateItemClient_x                                0x63A0D0
#define EQ_Item__GetItemValue_x                                    0x89CBB0
#define EQ_Item__ValueSellMerchant_x                               0x8A0460
#define EQ_Item__IsKeyRingItem_x                                   0x89E320
#define EQ_Item__CanGoInBag_x                                      0x63AFB0
#define EQ_Item__IsEmpty_x                                         0x89DE60
#define EQ_Item__GetMaxItemCount_x                                 0x89CFC0
#define EQ_Item__GetHeldItem_x                                     0x89B780
#define EQ_Item__GetAugmentFitBySlot_x                             0x899590

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x566B60
#define EQ_LoadingS__Array_x                                       0xC15130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x660F80
#define EQ_PC__GetAlternateAbilityId_x                             0x8A9760
#define EQ_PC__GetCombatAbility_x                                  0x8A9DD0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A9E40
#define EQ_PC__GetItemRecastTimer_x                                0x662FE0
#define EQ_PC__HasLoreItem_x                                       0x659AC0
#define EQ_PC__AlertInventoryChanged_x                             0x658B90
#define EQ_PC__GetPcZoneClient_x                                   0x685A80
#define EQ_PC__RemoveMyAffect_x                                    0x666210
#define EQ_PC__GetKeyRingItems_x                                   0x8AA710
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8AA490
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8AAA10

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5C2AA0
#define EQItemList__add_object_x                                   0x5F00C0
#define EQItemList__add_item_x                                     0x5C3000
#define EQItemList__delete_item_x                                  0x5C3050
#define EQItemList__FreeItemList_x                                 0x5C2F50

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x544A40

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x678270
#define EQPlayer__dEQPlayer_x                                      0x66B5E0
#define EQPlayer__DoAttack_x                                       0x680220
#define EQPlayer__EQPlayer_x                                       0x66BCA0
#define EQPlayer__SetNameSpriteState_x                             0x66FF80
#define EQPlayer__SetNameSpriteTint_x                              0x670E60
#define PlayerBase__HasProperty_j_x                                0x98BC90
#define EQPlayer__IsTargetable_x                                   0x98C130
#define EQPlayer__CanSee_x                                         0x98BF90
#define EQPlayer__CanSee1_x                                        0x98C060
#define PlayerBase__GetVisibilityLineSegment_x                     0x98BD50

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x683520
#define PlayerZoneClient__GetLevel_x                               0x685AC0
#define PlayerZoneClient__IsValidTeleport_x                        0x5F1230
#define PlayerZoneClient__LegalPlayerRace_x                        0x55F7D0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x67B0E0
#define EQPlayerManager__GetSpawnByName_x                          0x67B190
#define EQPlayerManager__GetPlayerFromPartialName_x                0x67B220

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63E670
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63E6F0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63E730
#define KeypressHandler__ClearCommandStateArray_x                  0x63FB20
#define KeypressHandler__HandleKeyDown_x                           0x63FB40
#define KeypressHandler__HandleKeyUp_x                             0x63FBE0
#define KeypressHandler__SaveKeymapping_x                          0x640030

// MapViewMap 
#define MapViewMap__Clear_x                                        0x777A50
#define MapViewMap__SaveEx_x                                       0x77AE10
#define MapViewMap__SetZoom_x                                      0x77F4D0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BDDB0

// StringTable 
#define StringTable__getString_x                                   0x8B8BD0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x665E80
#define PcZoneClient__RemovePetEffect_x                            0x6664B0
#define PcZoneClient__HasAlternateAbility_x                        0x6602B0
#define PcZoneClient__GetCurrentMod_x                              0x4E5D30
#define PcZoneClient__GetModCap_x                                  0x4E5C30
#define PcZoneClient__CanEquipItem_x                               0x660960
#define PcZoneClient__GetItemByID_x                                0x663450
#define PcZoneClient__GetItemByItemClass_x                         0x6635A0
#define PcZoneClient__RemoveBuffEffect_x                           0x6664D0
#define PcZoneClient__BandolierSwap_x                              0x661540
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x662F80

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F5E70

//IconCache
#define IconCache__GetIcon_x                                       0x7194C0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x710FF0
#define CContainerMgr__CloseContainer_x                            0x7112C0
#define CContainerMgr__OpenExperimentContainer_x                   0x711D40

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D0220

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x633060

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76DF80
#define CLootWnd__RequestLootSlot_x                                0x76D260

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58E6A0
#define EQ_Spell__SpellAffects_x                                   0x58EB10
#define EQ_Spell__SpellAffectBase_x                                0x58E8D0
#define EQ_Spell__IsStackable_x                                    0x4CA7E0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CA600
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B79C0
#define EQ_Spell__IsSPAStacking_x                                  0x58F960
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58EE70
#define EQ_Spell__IsNoRemove_x                                     0x4CA7C0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58F970
#define __IsResEffectSpell_x                                       0x4C9B30

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD2F0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C83B0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x817120
#define CTargetWnd__WndNotification_x                              0x816960
#define CTargetWnd__RefreshTargetBuffs_x                           0x816C30
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x815AC0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x81B790
#define CTaskWnd__ConfirmAbandonTask_x                             0x81E3D0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x542420
#define CTaskManager__HandleMessage_x                              0x540880
#define CTaskManager__GetTaskStatus_x                              0x5424D0
#define CTaskManager__GetElementDescription_x                      0x542550

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x589780
#define EqSoundManager__PlayScriptMp3_x                            0x589A40
#define EqSoundManager__SoundAssistPlay_x                          0x69E310
#define EqSoundManager__WaveInstancePlay_x                         0x69D880

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x5337F0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x947990
#define CTextureAnimation__Draw_x                                  0x947B90

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x9438E0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56E620
#define CAltAbilityData__GetMercMaxRank_x                          0x56E5B0
#define CAltAbilityData__GetMaxRank_x                              0x5639E0

//CTargetRing
#define CTargetRing__Cast_x                                        0x631180

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA5E0
#define CharacterBase__CreateItemGlobalIndex_x                     0x51A4E0
#define CharacterBase__CreateItemIndex_x                           0x639280
#define CharacterBase__GetItemPossession_x                         0x506100
#define CharacterBase__GetItemByGlobalIndex_x                      0x8D0A20
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8D0A80
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F8000
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F8830
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F88E0

//messages
#define msg_spell_worn_off_x                                       0x5B45C0
#define msg_new_text_x                                             0x5A8F20
#define __msgTokenTextParam_x                                      0x5B6860
#define msgTokenText_x                                             0x5B6AB0

//SpellManager
#define SpellManager__vftable_x                                    0xADC544
#define SpellManager__SpellManager_x                               0x6A1640
#define Spellmanager__LoadTextSpells_x                             0x6A1F30
#define SpellManager__GetSpellByGroupAndRank_x                     0x6A1810

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98FB50

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x51AB60
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5BAAF0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x652110
#define ItemGlobalIndex__IsValidIndex_x                            0x51ABF0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C8D70
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C8F00

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x766840

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x7156C0
#define CCursorAttachment__AttachToCursor1_x                       0x715700
#define CCursorAttachment__Deactivate_x                            0x7166F0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x93A5F0
#define CSidlManagerBase__CreatePageWnd_x                          0x939DE0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x936070
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x936000

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x957A40
#define CEQSuiteTextureLoader__GetTexture_x                        0x957700

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x517800
#define CFindItemWnd__WndNotification_x                            0x518440
#define CFindItemWnd__Update_x                                     0x518FB0
#define CFindItemWnd__PickupSelectedItem_x                         0x517030

//IString
#define IString__Append_x                                          0x507950

//Camera
#define CDisplay__cameraType_x                                     0xDECCCC
#define EverQuest__Cameras_x                                       0xEA80A0

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x5204C0
#define LootFiltersManager__GetItemFilterData_x                    0x51FDC0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51FDF0
#define LootFiltersManager__SetItemLootFilter_x                    0x520010

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BE020

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9957E0
#define CResolutionHandler__GetWindowedStyle_x                     0x698EC0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70DC10

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D47F0
#define CDistillerInfo__Instance_x                                 0x8D4790

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72CB30
#define CGroupWnd__UpdateDisplay_x                                 0x72BE80

//ItemBase
#define ItemBase__IsLore_x                                         0x89E3D0
#define ItemBase__IsLoreEquipped_x                                 0x89E440

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5F0020
#define EQPlacedItemManager__GetItemByGuid_x                       0x5F0160
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5F01C0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68E200
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x691B90

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50DEC0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4FA020
#define FactionManagerClient__HandleFactionMessage_x               0x4FA690
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4FAC90
#define FactionManagerClient__GetMaxFaction_x                      0x4FACAF
#define FactionManagerClient__GetMinFaction_x                      0x4FAC60

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x5060D0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91EB70

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C090

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x506360

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56DAC0

//CTargetManager
#define CTargetManager__Get_x                                      0x6A4E80

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68E200

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8E60

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5C2EF0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF45734

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6C18C0
#define CAAWnd__UpdateSelected_x                                   0x6BE130
#define CAAWnd__Update_x                                           0x6C0BE0

//CXRect
#define CXRect__operator_and_x                                     0x723C10

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x4830F0

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
