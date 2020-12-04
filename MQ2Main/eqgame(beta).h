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
#define __ExpectedVersionDate                                     "Nov 28 2020"
#define __ExpectedVersionTime                                     "04:19:58"
#define __ActualVersionDate_x                                      0xAF7558
#define __ActualVersionTime_x                                      0xAF754C
#define __ActualVersionBuild_x                                     0xAE5584

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x643E60
#define __MemChecker1_x                                            0x8F75B0
#define __MemChecker2_x                                            0x6B49F0
#define __MemChecker3_x                                            0x6B4940
#define __MemChecker4_x                                            0x84D780
#define __EncryptPad0_x                                            0xC2D9C8
#define __EncryptPad1_x                                            0xC8B210
#define __EncryptPad2_x                                            0xC3DD90
#define __EncryptPad3_x                                            0xC3D990
#define __EncryptPad4_x                                            0xC7B7A0
#define __EncryptPad5_x                                            0xF4E0E0
#define __AC1_x                                                    0x80C376
#define __AC2_x                                                    0x5FD39F
#define __AC3_x                                                    0x6049F0
#define __AC4_x                                                    0x6089A0
#define __AC5_x                                                    0x60EC9F
#define __AC6_x                                                    0x613146
#define __AC7_x                                                    0x5FCE10
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1932F0

// Direct Input
#define DI8__Main_x                                                0xF4E108
#define DI8__Keyboard_x                                            0xF4E10C
#define DI8__Mouse_x                                               0xF4E0EC
#define DI8__Mouse_Copy_x                                          0xEA69E4
#define DI8__Mouse_Check_x                                         0xF4BC34
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
#define __do_loot_x                                                0x5C8E20
#define __DrawHandler_x                                            0x15DD140
#define __GroupCount_x                                             0xE9F502
#define __Guilds_x                                                 0xEA5920
#define __gWorld_x                                                 0xE9FC98
#define __HWnd_x                                                   0xF4E0F0
#define __heqmain_x                                                0xF4E0C8
#define __InChatMode_x                                             0xEA69CC
#define __LastTell_x                                               0xEA894C
#define __LMouseHeldTime_x                                         0xEA6B08
#define __Mouse_x                                                  0xF4E0F4
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
#define __ServerHost_x                                             0xE9F923
#define __ServerName_x                                             0xEDD210
#define __ShiftKeyDown_x                                           0xEA7060
#define __ShowNames_x                                              0xEA7DA0
#define EverQuestInfo__bSocialChanged_x                            0xEDD298
#define __Socials_x                                                0xEDD310
#define __SubscriptionType_x                                       0xFA2410
#define __TargetAggroHolder_x                                      0xF60B00
#define __ZoneType_x                                               0xEA6E60
#define __GroupAggro_x                                             0xF60B40
#define __LoginName_x                                              0xF4B8C4
#define __Inviter_x                                                0xF456AC
#define __AttackOnAssist_x                                         0xEA7D5C
#define __UseTellWindows_x                                         0xEA8094
#define __gfMaxZoomCameraDistance_x                                0xAEF180
#define __gfMaxCameraDistance_x                                    0xB17DF0
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
#define pinstActiveMerchant_x                                      0xE9FC38
#define pinstAltAdvManager_x                                       0xDEDEF0
#define pinstBandageTarget_x                                       0xE9FC54
#define pinstCamActor_x                                            0xDED49C
#define pinstCDBStr_x                                              0xDECC0C
#define pinstCDisplay_x                                            0xE9FCA4
#define pinstCEverQuest_x                                          0xF4B188
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
#define pinstEqLogin_x                                             0xF4B210
#define instEQMisc_x                                               0xDECB50
#define pinstEQSoundManager_x                                      0xDEEEC0
#define pinstEQSpellStrings_x                                      0xCAF448
#define instExpeditionLeader_x                                     0xEA5842
#define instExpeditionName_x                                       0xEA5882
#define pinstGroup_x                                               0xE9F4FE
#define pinstImeManager_x                                          0x15DC300
#define pinstLocalPlayer_x                                         0xE9FC34
#define pinstMercenaryData_x                                       0xF47D08
#define pinstMercenaryStats_x                                      0xF60BCC
#define pinstModelPlayer_x                                         0xE9FC4C
#define pinstPCData_x                                              0xE9F744
#define pinstSkillMgr_x                                            0xF49E68
#define pinstSpawnManager_x                                        0xF48910
#define pinstSpellManager_x                                        0xF4A0A8
#define pinstSpellSets_x                                           0xF3E358
#define pinstStringTable_x                                         0xE9F748
#define pinstSwitchManager_x                                       0xE9F258
#define pinstTarget_x                                              0xE9FC88
#define pinstTargetObject_x                                        0xE9FC94
#define pinstTargetSwitch_x                                        0xE9FCAC
#define pinstTaskMember_x                                          0xDEC9E0
#define pinstTrackTarget_x                                         0xE9FC90
#define pinstTradeTarget_x                                         0xE9FC48
#define instTributeActive_x                                        0xDECB71
#define pinstViewActor_x                                           0xDED498
#define pinstWorldData_x                                           0xE9F3A8
#define pinstZoneAddr_x                                            0xEA6EF8
#define pinstPlayerPath_x                                          0xF489A8
#define pinstTargetIndicator_x                                     0xF4A310
#define EQObject_Top_x                                             0xE9FA2C
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDECF3C
#define pinstCAchievementsWnd_x                                    0xDED454
#define pinstCActionsWnd_x                                         0xDECF78
#define pinstCAdvancedDisplayOptionsWindow_x                       0xDED514
#define pinstCAdvancedLootWnd_x                                    0xDED4C4
#define pinstCAdventureLeaderboardWnd_x                            0xF57920
#define pinstCAdventureRequestWnd_x                                0xF579D0
#define pinstCAdventureStatsWnd_x                                  0xF57A80
#define pinstCAggroMeterWnd_x                                      0xDED4F8
#define pinstCAlarmWnd_x                                           0xDED480
#define pinstCAlertHistoryWnd_x                                    0xDECEEC
#define pinstCAlertStackWnd_x                                      0xDED4E0
#define pinstCAlertWnd_x                                           0xDED4F4
#define pinstCAltStorageWnd_x                                      0xF57DE0
#define pinstCAudioTriggersWindow_x                                0xCA1778
#define pinstCAuraWnd_x                                            0xDED4C8
#define pinstCAvaZoneWnd_x                                         0xDECEF0
#define pinstCBandolierWnd_x                                       0xDED50C
#define pinstCBankWnd_x                                            0xDECCB0
#define pinstCBarterMerchantWnd_x                                  0xF59020
#define pinstCBarterSearchWnd_x                                    0xF590D0
#define pinstCBarterWnd_x                                          0xF59180
#define pinstCBazaarConfirmationWnd_x                              0xDED490
#define pinstCBazaarSearchWnd_x                                    0xDECF40
#define pinstCBazaarWnd_x                                          0xDED45C
#define pinstCBlockedBuffWnd_x                                     0xDED4D4
#define pinstCBlockedPetBuffWnd_x                                  0xDED4FC
#define pinstCBodyTintWnd_x                                        0xDED404
#define pinstCBookWnd_x                                            0xDED544
#define pinstCBreathWnd_x                                          0xDECF50
#define pinstCBuffWindowNORMAL_x                                   0xDED4BC
#define pinstCBuffWindowSHORT_x                                    0xDED4C0
#define pinstCBugReportWnd_x                                       0xDECCAC
#define pinstCButtonWnd_x                                          0x15DC570
#define pinstCCastingWnd_x                                         0xDED538
#define pinstCCastSpellWnd_x                                       0xDECF4C
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDED410
#define pinstCChatWindowManager_x                                  0xF59C40
#define pinstCClaimWnd_x                                           0xF59D98
#define pinstCColorPickerWnd_x                                     0xDECF04
#define pinstCCombatAbilityWnd_x                                   0xDED46C
#define pinstCCombatSkillsSelectWnd_x                              0xDED424
#define pinstCCompassWnd_x                                         0xDECF7C
#define pinstCConfirmationDialog_x                                 0xF5EC98
#define pinstCContainerMgr_x                                       0xDED400
#define pinstCContextMenuManager_x                                 0x15DC2C0
#define pinstCCursorAttachment_x                                   0xDED520
#define pinstCDynamicZoneWnd_x                                     0xF5A360
#define pinstCEditLabelWnd_x                                       0xDED4A8
#define pinstCEQMainWnd_x                                          0xF5A5A8
#define pinstCEventCalendarWnd_x                                   0xDECF44
#define pinstCExtendedTargetWnd_x                                  0xDED4D8
#define pinstCPlayerCustomizationWnd_x                             0xDED428
#define pinstCFactionWnd_x                                         0xDED448
#define pinstCFellowshipWnd_x                                      0xF5A7A8
#define pinstCFileSelectionWnd_x                                   0xDECF00
#define pinstCFindItemWnd_x                                        0xDED43C
#define pinstCFindLocationWnd_x                                    0xF5A900
#define pinstCFriendsWnd_x                                         0xDED438
#define pinstCGemsGameWnd_x                                        0xDED444
#define pinstCGiveWnd_x                                            0xDED484
#define pinstCGroupSearchFiltersWnd_x                              0xDED510
#define pinstCGroupSearchWnd_x                                     0xF5ACF8
#define pinstCGroupWnd_x                                           0xF5ADA8
#define pinstCGuildBankWnd_x                                       0xF5AE58
#define pinstCGuildCreationWnd_x                                   0xF5AF08
#define pinstCGuildMgmtWnd_x                                       0xF5AFB8
#define pinstCharacterCreation_x                                   0xDED430
#define pinstCHelpWnd_x                                            0xDED47C
#define pinstCHeritageSelectionWnd_x                               0xDED434
#define pinstCHotButtonWnd_x                                       0xF5D110
#define pinstCHotButtonWnd1_x                                      0xF5D110
#define pinstCHotButtonWnd2_x                                      0xF5D114
#define pinstCHotButtonWnd3_x                                      0xF5D118
#define pinstCHotButtonWnd4_x                                      0xF5D11C
#define pinstCIconSelectionWnd_x                                   0xDED51C
#define pinstCInspectWnd_x                                         0xDED500
#define pinstCInventoryWnd_x                                       0xDED4CC
#define pinstCInvSlotMgr_x                                         0xDECF30
#define pinstCItemDisplayManager_x                                 0xF5D6A0
#define pinstCItemExpTransferWnd_x                                 0xF5D7D0
#define pinstCItemOverflowWnd_x                                    0xDECF48
#define pinstCJournalCatWnd_x                                      0xDECF1C
#define pinstCJournalNPCWnd_x                                      0xDECEDC
#define pinstCJournalTextWnd_x                                     0xDECEDC
#define pinstCKeyRingWnd_x                                         0xDED534
#define pinstCLargeDialogWnd_x                                     0xF5F918
#define pinstCLayoutCopyWnd_x                                      0xF5DB20
#define pinstCLFGuildWnd_x                                         0xF5DBD0
#define pinstCLoadskinWnd_x                                        0xDED460
#define pinstCLootFiltersCopyWnd_x                                 0xCBDEE8
#define pinstCLootFiltersWnd_x                                     0xDED4E4
#define pinstCLootSettingsWnd_x                                    0xDED508
#define pinstCLootWnd_x                                            0xDECF20
#define pinstCMailAddressBookWnd_x                                 0xDECF34
#define pinstCMailCompositionWnd_x                                 0xDECF0C
#define pinstCMailIgnoreListWnd_x                                  0xDECF38
#define pinstCMailWnd_x                                            0xDECEF8
#define pinstCManageLootWnd_x                                      0xDEE3A0
#define pinstCMapToolbarWnd_x                                      0xDED488
#define pinstCMapViewWnd_x                                         0xDED450
#define pinstCMarketplaceWnd_x                                     0xDED4E8
#define pinstCMerchantWnd_x                                        0xDECF2C
#define pinstCMIZoneSelectWnd_x                                    0xF5E408
#define pinstCMusicPlayerWnd_x                                     0xDECCCC
#define pinstCNameChangeMercWnd_x                                  0xDED48C
#define pinstCNameChangePetWnd_x                                   0xDED458
#define pinstCNameChangeWnd_x                                      0xDED4A0
#define pinstCNoteWnd_x                                            0xDED464
#define pinstCObjectPreviewWnd_x                                   0xDED504
#define pinstCOptionsWnd_x                                         0xDED474
#define pinstCPetInfoWnd_x                                         0xDECEF4
#define pinstCPetitionQWnd_x                                       0xDED420
#define pinstCPlayerNotesWnd_x                                     0xDED408
#define pinstCPlayerWnd_x                                          0xDECEE8
#define pinstCPopupWndManager_x                                    0xF5EC98
#define pinstCProgressionSelectionWnd_x                            0xF5ED48
#define pinstCPurchaseGroupWnd_x                                   0xDECCC0
#define pinstCPurchaseWnd_x                                        0xDED53C
#define pinstCPvPLeaderboardWnd_x                                  0xF5EDF8
#define pinstCPvPStatsWnd_x                                        0xF5EEA8
#define pinstCQuantityWnd_x                                        0xDECED8
#define pinstCRaceChangeWnd_x                                      0xDED4D0
#define pinstCRaidOptionsWnd_x                                     0xDED518
#define pinstCRaidWnd_x                                            0xDECF28
#define pinstCRealEstateItemsWnd_x                                 0xDED44C
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDECFF8
#define pinstCRealEstateManageWnd_x                                0xDECCC4
#define pinstCRealEstateNeighborhoodWnd_x                          0xDECEE4
#define pinstCRealEstatePlotSearchWnd_x                            0xDECEFC
#define pinstCRealEstatePurchaseWnd_x                              0xDECF18
#define pinstCRespawnWnd_x                                         0xDED4F0
#define pinstCRewardSelectionWnd_x                                 0xF5F5F0
#define pinstCSelectorWnd_x                                        0xDED41C
#define pinstCSendMoneyWnd_x                                       0xDED494
#define pinstCServerListWnd_x                                      0xDECF24
#define pinstCSkillsSelectWnd_x                                    0xDED418
#define pinstCSkillsWnd_x                                          0xDECFF4
#define pinstCSocialEditWnd_x                                      0xDED52C
#define pinstCSocialWnd_x                                          0xDED478
#define pinstCSpellBookWnd_x                                       0xDED468
#define pinstCStoryWnd_x                                           0xDECF74
#define pinstCTargetOfTargetWnd_x                                  0xF60C50
#define pinstCTargetWnd_x                                          0xDED4EC
#define pinstCTaskOverlayWnd_x                                     0xDECCB4
#define pinstCTaskSelectWnd_x                                      0xF60DA8
#define pinstCTaskManager_x                                        0xCBE828
#define pinstCTaskTemplateSelectWnd_x                              0xF60E58
#define pinstCTaskWnd_x                                            0xF60F08
#define pinstCTextEntryWnd_x                                       0xDED540
#define pinstCTimeLeftWnd_x                                        0xDED414
#define pinstCTipWndCONTEXT_x                                      0xF6110C
#define pinstCTipWndOFDAY_x                                        0xF61108
#define pinstCTitleWnd_x                                           0xF611B8
#define pinstCTrackingWnd_x                                        0xDED4DC
#define pinstCTradeskillWnd_x                                      0xF61320
#define pinstCTradeWnd_x                                           0xDED40C
#define pinstCTrainWnd_x                                           0xDECF10
#define pinstCTributeBenefitWnd_x                                  0xF61520
#define pinstCTributeMasterWnd_x                                   0xF615D0
#define pinstCTributeTrophyWnd_x                                   0xF61680
#define pinstCVideoModesWnd_x                                      0xDECCB8
#define pinstCVoiceMacroWnd_x                                      0xF4A8C8
#define pinstCVoteResultsWnd_x                                     0xDED440
#define pinstCVoteWnd_x                                            0xDED42C
#define pinstCWebManager_x                                         0xF4AF44
#define pinstCZoneGuideWnd_x                                       0xDECCBC
#define pinstCZonePathWnd_x                                        0xDECED0

#define pinstEQSuiteTextureLoader_x                                0xC8BB30
#define pinstItemIconCache_x                                       0xF5A560
#define pinstLootFiltersManager_x                                  0xCBDF98
#define pinstRewardSelectionWnd_x                                  0xF5F5F0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5C4510
#define __CastRay2_x                                               0x5C4560
#define __ConvertItemTags_x                                        0x5E0230
#define __CleanItemTags_x                                          0x47D2A0
#define __DoesFileExist_x                                          0x8FA6E0
#define __EQGetTime_x                                              0x8F71E0
#define __ExecuteCmd_x                                             0x5BCE90
#define __FixHeading_x                                             0x98D2F0
#define __FlushDxKeyboard_x                                        0x6B0890
#define __GameLoop_x                                               0x6B3BC0
#define __get_bearing_x                                            0x5C4070
#define __get_melee_range_x                                        0x5C4750
#define __GetAnimationCache_x                                      0x718E40
#define __GetGaugeValueFromEQ_x                                    0x80A820
#define __GetLabelFromEQ_x                                         0x80C300
#define __GetXTargetType_x                                         0x98ED40
#define __HandleMouseWheel_x                                       0x6B4AA0
#define __HeadingDiff_x                                            0x98D360
#define __HelpPath_x                                               0xF45E04
#define __LoadFrontEnd_x                                           0x6B0ED0
#define __NewUIINI_x                                               0x80A4F0
#define __ProcessGameEvents_x                                      0x625020
#define __ProcessMouseEvent_x                                      0x6247B0
#define __SaveColors_x                                             0x55D730
#define __STMLToText_x                                             0x9307D0
#define __ToggleKeyRingItem_x                                      0x51C040
#define CMemoryMappedFile__SetFile_x                               0xA7C7E0
#define CrashDetected_x                                            0x6B2980
#define DrawNetStatus_x                                            0x651550
#define Expansion_HoT_x                                            0xEA7D48
#define Teleport_Table_Size_x                                      0xE9F7E0
#define Teleport_Table_x                                           0xE9FCB0
#define Util__FastTime_x                                           0x8F6DB0
#define __CopyLayout_x                                             0x63F4D0
#define __WndProc_x                                                0x6B2E80
#define __ProcessKeyboardEvent_x                                   0x6B2420

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4904F0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4994E0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4992B0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493A90
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492EE0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x565950
#define AltAdvManager__IsAbilityReady_x                            0x5646F0
#define AltAdvManager__GetAAById_x                                 0x564A80
#define AltAdvManager__CanTrainAbility_x                           0x564AF0
#define AltAdvManager__CanSeeAbility_x                             0x564E50

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CAF40
#define CharacterZoneClient__HasSkill_x                            0x4D5DC0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D74F0
#define CharacterZoneClient__IsStackBlocked_x                      0x4C2640
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBAD0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9E80
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9F60
#define CharacterZoneClient__GetCursorItemCount_x                  0x4DA040
#define CharacterZoneClient__FindAffectSlot_x                      0x4C4730
#define CharacterZoneClient__BardCastBard_x                        0x4C7160
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF4E0
#define CharacterZoneClient__GetEffect_x                           0x4BBA10
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C57A0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C5870
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C58C0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5A10
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5BF0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3A50
#define CharacterZoneClient__FindItemByGuid_x                      0x4D8450
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7ED0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6DA5B0
#define CBankWnd__WndNotification_x                                0x6DA380

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E7DB0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x92DFB0
#define CButtonWnd__CButtonWnd_x                                   0x92CB80

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x708040
#define CChatManager__InitContextMenu_x                            0x701170
#define CChatManager__FreeChatWindow_x                             0x706B80
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E98B0
#define CChatManager__SetLockedActiveChatWindow_x                  0x707CC0
#define CChatManager__CreateChatWindow_x                           0x7071C0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E99C0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x941120
#define CContextMenu__dCContextMenu_x                              0x941360
#define CContextMenu__AddMenuItem_x                                0x941370
#define CContextMenu__RemoveMenuItem_x                             0x941680
#define CContextMenu__RemoveAllMenuItems_x                         0x9416A0
#define CContextMenu__CheckMenuItem_x                              0x941720
#define CContextMenu__SetMenuItem_x                                0x9415A0
#define CContextMenu__AddSeparator_x                               0x941500

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x941CC0
#define CContextMenuManager__RemoveMenu_x                          0x941D30
#define CContextMenuManager__PopupMenu_x                           0x941DF0
#define CContextMenuManager__Flush_x                               0x941C60
#define CContextMenuManager__GetMenu_x                             0x49B6B0
#define CContextMenuManager__CreateDefaultMenu_x                   0x7137A0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D2000
#define CChatService__GetFriendName_x                              0x8D2010

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x7088B0
#define CChatWindow__Clear_x                                       0x709B70
#define CChatWindow__WndNotification_x                             0x70A300
#define CChatWindow__AddHistory_x                                  0x709430

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93E580
#define CComboWnd__Draw_x                                          0x93DA80
#define CComboWnd__GetCurChoice_x                                  0x93E3C0
#define CComboWnd__GetListRect_x                                   0x93DF30
#define CComboWnd__GetTextRect_x                                   0x93E5F0
#define CComboWnd__InsertChoice_x                                  0x93E0C0
#define CComboWnd__SetColors_x                                     0x93E090
#define CComboWnd__SetChoice_x                                     0x93E390
#define CComboWnd__GetItemCount_x                                  0x93E3D0
#define CComboWnd__GetCurChoiceText_x                              0x93E410
#define CComboWnd__GetChoiceText_x                                 0x93E3E0
#define CComboWnd__InsertChoiceAtIndex_x                           0x93E150

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x7111C0
#define CContainerWnd__vftable_x                                   0xB0075C
#define CContainerWnd__SetContainer_x                              0x712710

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x558090
#define CDisplay__PreZoneMainUI_x                                  0x5580A0
#define CDisplay__CleanGameUI_x                                    0x55D4F0
#define CDisplay__GetClickedActor_x                                0x5504F0
#define CDisplay__GetUserDefinedColor_x                            0x548B60
#define CDisplay__GetWorldFilePath_x                               0x551F60
#define CDisplay__is3dON_x                                         0x54D150
#define CDisplay__ReloadUI_x                                       0x5575A0
#define CDisplay__WriteTextHD2_x                                   0x54CF40
#define CDisplay__TrueDistance_x                                   0x553C20
#define CDisplay__SetViewActor_x                                   0x54FE10
#define CDisplay__GetFloorHeight_x                                 0x54D210
#define CDisplay__SetRenderWindow_x                                0x54BB90
#define CDisplay__ToggleScreenshotMode_x                           0x54F8E0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x960FF0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x944610
#define CEditWnd__EnsureCaretVisible_x                             0x9467E0
#define CEditWnd__GetCaretPt_x                                     0x945790
#define CEditWnd__GetCharIndexPt_x                                 0x945540
#define CEditWnd__GetDisplayString_x                               0x9453E0
#define CEditWnd__GetHorzOffset_x                                  0x943CC0
#define CEditWnd__GetLineForPrintableChar_x                        0x9466E0
#define CEditWnd__GetSelStartPt_x                                  0x9457F0
#define CEditWnd__GetSTMLSafeText_x                                0x945200
#define CEditWnd__PointFromPrintableChar_x                         0x946310
#define CEditWnd__SelectableCharFromPoint_x                        0x946480
#define CEditWnd__SetEditable_x                                    0x9458C0
#define CEditWnd__SetWindowTextA_x                                 0x944F80
#define CEditWnd__ReplaceSelection_x                               0x945F80
#define CEditWnd__ReplaceSelection1_x                              0x945F00

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x612620
#define CEverQuest__ClickedPlayer_x                                0x6047D0
#define CEverQuest__CreateTargetIndicator_x                        0x622190
#define CEverQuest__DeleteTargetIndicator_x                        0x622220
#define CEverQuest__DoTellWindow_x                                 0x4E9AA0
#define CEverQuest__OutputTextToLog_x                              0x4E9D70
#define CEverQuest__DropHeldItemOnGround_x                         0x5F9930
#define CEverQuest__dsp_chat_x                                     0x4EA100
#define CEverQuest__trimName_x                                     0x61E340
#define CEverQuest__Emote_x                                        0x612E80
#define CEverQuest__EnterZone_x                                    0x60CF90
#define CEverQuest__GetBodyTypeDesc_x                              0x6178D0
#define CEverQuest__GetClassDesc_x                                 0x617F10
#define CEverQuest__GetClassThreeLetterCode_x                      0x618510
#define CEverQuest__GetDeityDesc_x                                 0x6209E0
#define CEverQuest__GetLangDesc_x                                  0x6186D0
#define CEverQuest__GetRaceDesc_x                                  0x617EF0
#define CEverQuest__InterpretCmd_x                                 0x620FB0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FDAC0
#define CEverQuest__LMouseUp_x                                     0x5FBE50
#define CEverQuest__RightClickedOnPlayer_x                         0x5FE3A0
#define CEverQuest__RMouseUp_x                                     0x5FCDD0
#define CEverQuest__SetGameState_x                                 0x5F96C0
#define CEverQuest__UPCNotificationFlush_x                         0x61E240
#define CEverQuest__IssuePetCommand_x                              0x619AE0
#define CEverQuest__ReportSuccessfulHit_x                          0x6141D0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x722DF0
#define CGaugeWnd__CalcLinesFillRect_x                             0x722E50
#define CGaugeWnd__Draw_x                                          0x722470

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AFDD0
#define CGuild__GetGuildName_x                                     0x4AE880
#define CGuild__GetGuildIndex_x                                    0x4AEE80

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73CA20

//CHotButton
#define CHotButton__SetCheck_x                                     0x6339A0
#define CHotButton__SetButtonSize_x                                0x633D60

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x749C60
#define CInvSlotMgr__MoveItem_x                                    0x748970
#define CInvSlotMgr__SelectSlot_x                                  0x749D30

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x747160
#define CInvSlot__SliderComplete_x                                 0x744EA0
#define CInvSlot__GetItemBase_x                                    0x744820
#define CInvSlot__UpdateItem_x                                     0x744990

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x74B7C0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x74A950
#define CInvSlotWnd__HandleLButtonUp_x                             0x74B340

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x805BC0
#define CItemDisplayWnd__UpdateStrings_x                           0x759DD0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x753B00
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x754000
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x75A3C0
#define CItemDisplayWnd__AboutToShow_x                             0x759A10
#define CItemDisplayWnd__WndNotification_x                         0x75B620
#define CItemDisplayWnd__RequestConvertItem_x                      0x75AF60
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x758A70
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x759830

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x836670

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75FB10

// CLabel 
#define CLabel__Draw_x                                             0x7655B0

// CListWnd
#define CListWnd__CListWnd_x                                       0x916BB0
#define CListWnd__dCListWnd_x                                      0x916ED0
#define CListWnd__AddColumn_x                                      0x91B340
#define CListWnd__AddColumn1_x                                     0x91B390
#define CListWnd__AddLine_x                                        0x91B720
#define CListWnd__AddString_x                                      0x91B520
#define CListWnd__CalculateFirstVisibleLine_x                      0x91B100
#define CListWnd__CalculateVSBRange_x                              0x91AEE0
#define CListWnd__ClearSel_x                                       0x91BF00
#define CListWnd__ClearAllSel_x                                    0x91BF60
#define CListWnd__CloseAndUpdateEditWindow_x                       0x91C980
#define CListWnd__Compare_x                                        0x91A820
#define CListWnd__Draw_x                                           0x917000
#define CListWnd__DrawColumnSeparators_x                           0x9197F0
#define CListWnd__DrawHeader_x                                     0x919C60
#define CListWnd__DrawItem_x                                       0x91A160
#define CListWnd__DrawLine_x                                       0x919960
#define CListWnd__DrawSeparator_x                                  0x919890
#define CListWnd__EnableLine_x                                     0x9190C0
#define CListWnd__EnsureVisible_x                                  0x91C8A0
#define CListWnd__ExtendSel_x                                      0x91BE30
#define CListWnd__GetColumnTooltip_x                               0x918C00
#define CListWnd__GetColumnMinWidth_x                              0x918C70
#define CListWnd__GetColumnWidth_x                                 0x918B70
#define CListWnd__GetCurSel_x                                      0x918500
#define CListWnd__GetItemAtPoint_x                                 0x919340
#define CListWnd__GetItemAtPoint1_x                                0x9193B0
#define CListWnd__GetItemData_x                                    0x918580
#define CListWnd__GetItemHeight_x                                  0x918940
#define CListWnd__GetItemIcon_x                                    0x918710
#define CListWnd__GetItemRect_x                                    0x9191B0
#define CListWnd__GetItemText_x                                    0x9185C0
#define CListWnd__GetSelList_x                                     0x91BFB0
#define CListWnd__GetSeparatorRect_x                               0x9195F0
#define CListWnd__InsertLine_x                                     0x91BB10
#define CListWnd__RemoveLine_x                                     0x91BC60
#define CListWnd__SetColors_x                                      0x91AEC0
#define CListWnd__SetColumnJustification_x                         0x91ABF0
#define CListWnd__SetColumnLabel_x                                 0x91B4C0
#define CListWnd__SetColumnWidth_x                                 0x91AB10
#define CListWnd__SetCurSel_x                                      0x91BD70
#define CListWnd__SetItemColor_x                                   0x91C550
#define CListWnd__SetItemData_x                                    0x91C510
#define CListWnd__SetItemText_x                                    0x91C120
#define CListWnd__ShiftColumnSeparator_x                           0x91ACB0
#define CListWnd__Sort_x                                           0x91A9A0
#define CListWnd__ToggleSel_x                                      0x91BDA0
#define CListWnd__SetColumnsSizable_x                              0x91AD60
#define CListWnd__SetItemWnd_x                                     0x91C3D0
#define CListWnd__GetItemWnd_x                                     0x918760
#define CListWnd__SetItemIcon_x                                    0x91C1A0
#define CListWnd__CalculateCustomWindowPositions_x                 0x91B200
#define CListWnd__SetVScrollPos_x                                  0x91AAF0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x77AE00
#define CMapViewWnd__GetWorldCoordinates_x                         0x779510
#define CMapViewWnd__HandleLButtonDown_x                           0x776550

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x79B100
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79B9E0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79BF10
#define CMerchantWnd__SelectRecoverySlot_x                         0x79EEC0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x799C60
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A4A90
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x79AD10

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89F950
#define CPacketScrambler__hton_x                                   0x89F940

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x935DA0
#define CSidlManager__FindScreenPieceTemplate_x                    0x9361B0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x935FA0
#define CSidlManager__CreateLabel_x                                0x7FCE00
#define CSidlManager__CreateXWndFromTemplate_x                     0x939110
#define CSidlManager__CreateXWndFromTemplate1_x                    0x9392E0
#define CSidlManager__CreateXWnd_x                                 0x7FCD30
#define CSidlManager__CreateHotButtonWnd_x                         0x7FD300

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x932870
#define CSidlScreenWnd__CalculateVSBRange_x                        0x932770
#define CSidlScreenWnd__ConvertToRes_x                             0x95BB30
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x932260
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x931F50
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x932020
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x9320F0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x932D10
#define CSidlScreenWnd__EnableIniStorage_x                         0x9331E0
#define CSidlScreenWnd__GetSidlPiece_x                             0x932F00
#define CSidlScreenWnd__Init1_x                                    0x931B70
#define CSidlScreenWnd__LoadIniInfo_x                              0x933230
#define CSidlScreenWnd__LoadIniListWnd_x                           0x933D80
#define CSidlScreenWnd__LoadSidlScreen_x                           0x930F80
#define CSidlScreenWnd__StoreIniInfo_x                             0x9338F0
#define CSidlScreenWnd__StoreIniVis_x                              0x933C60
#define CSidlScreenWnd__WndNotification_x                          0x932C20
#define CSidlScreenWnd__GetChildItem_x                             0x933160
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9228C0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15DC190

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x699890
#define CSkillMgr__GetSkillCap_x                                   0x699A70
#define CSkillMgr__GetNameToken_x                                  0x699010
#define CSkillMgr__IsActivatedSkill_x                              0x699150
#define CSkillMgr__IsCombatSkill_x                                 0x699090

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x942AA0
#define CSliderWnd__SetValue_x                                     0x942910
#define CSliderWnd__SetNumTicks_x                                  0x942970

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x802F50

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x94B3E0
#define CStmlWnd__ParseSTML_x                                      0x94C6F0
#define CStmlWnd__CalculateHSBRange_x                              0x94C4C0
#define CStmlWnd__CalculateVSBRange_x                              0x94C430
#define CStmlWnd__CanBreakAtCharacter_x                            0x950800
#define CStmlWnd__FastForwardToEndOfTag_x                          0x951490
#define CStmlWnd__ForceParseNow_x                                  0x94B980
#define CStmlWnd__GetNextTagPiece_x                                0x950760
#define CStmlWnd__GetSTMLText_x                                    0x50D4E0
#define CStmlWnd__GetVisibleText_x                                 0x94B9A0
#define CStmlWnd__InitializeWindowVariables_x                      0x9512E0
#define CStmlWnd__MakeStmlColorTag_x                               0x94AA50
#define CStmlWnd__MakeWndNotificationTag_x                         0x94AAC0
#define CStmlWnd__SetSTMLText_x                                    0x949B00
#define CStmlWnd__StripFirstSTMLLines_x                            0x952590
#define CStmlWnd__UpdateHistoryString_x                            0x9516A0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x948C50
#define CTabWnd__DrawCurrentPage_x                                 0x949380
#define CTabWnd__DrawTab_x                                         0x9490A0
#define CTabWnd__GetCurrentPage_x                                  0x948450
#define CTabWnd__GetPageInnerRect_x                                0x948690
#define CTabWnd__GetTabInnerRect_x                                 0x9485D0
#define CTabWnd__GetTabRect_x                                      0x948480
#define CTabWnd__InsertPage_x                                      0x9488A0
#define CTabWnd__RemovePage_x                                      0x948A10
#define CTabWnd__SetPage_x                                         0x948710
#define CTabWnd__SetPageRect_x                                     0x948B90
#define CTabWnd__UpdatePage_x                                      0x948F60
#define CTabWnd__GetPageFromTabIndex_x                             0x948FE0
#define CTabWnd__GetCurrentTabIndex_x                              0x948440

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x75FF20
#define CPageWnd__SetTabText_x                                     0x947F90
#define CPageWnd__FlashTab_x                                       0x947FF0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9150

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91F740
#define CTextureFont__GetTextExtent_x                              0x91F900

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6ADA60
#define CHtmlComponentWnd__ValidateUri_x                           0x73E410
#define CHtmlWnd__SetClientCallbacks_x                             0x638DF0
#define CHtmlWnd__AddObserver_x                                    0x638E10
#define CHtmlWnd__RemoveObserver_x                                 0x638E70
#define Window__getProgress_x                                      0x854DA0
#define Window__getStatus_x                                        0x854DC0
#define Window__getURI_x                                           0x854DD0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x958940

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x90C840

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E97A0
#define CXStr__CXStr1_x                                            0x9E3B20
#define CXStr__CXStr3_x                                            0x8F3160
#define CXStr__dCXStr_x                                            0x4783A0
#define CXStr__operator_equal_x                                    0x8F3390
#define CXStr__operator_equal1_x                                   0x8F33D0
#define CXStr__operator_plus_equal1_x                              0x8F3E60
#define CXStr__SetString_x                                         0x8F5D50
#define CXStr__operator_char_p_x                                   0x8F38D0
#define CXStr__GetChar_x                                           0x8F5680
#define CXStr__Delete_x                                            0x8F4F50
#define CXStr__GetUnicode_x                                        0x8F56F0
#define CXStr__GetLength_x                                         0x4A8F00
#define CXStr__Mid_x                                               0x47D650
#define CXStr__Insert_x                                            0x8F5750
#define CXStr__FindNext_x                                          0x8F53C0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x940D40
#define CXWnd__BringToTop_x                                        0x9260F0
#define CXWnd__Center_x                                            0x925C70
#define CXWnd__ClrFocus_x                                          0x925A80
#define CXWnd__Destroy_x                                           0x925B30
#define CXWnd__DoAllDrawing_x                                      0x922070
#define CXWnd__DrawChildren_x                                      0x922040
#define CXWnd__DrawColoredRect_x                                   0x9224D0
#define CXWnd__DrawTooltip_x                                       0x920B70
#define CXWnd__DrawTooltipAtPoint_x                                0x920C30
#define CXWnd__GetBorderFrame_x                                    0x922330
#define CXWnd__GetChildWndAt_x                                     0x926190
#define CXWnd__GetClientClipRect_x                                 0x924320
#define CXWnd__GetScreenClipRect_x                                 0x9243F0
#define CXWnd__GetScreenRect_x                                     0x924590
#define CXWnd__GetRelativeRect_x                                   0x924660
#define CXWnd__GetTooltipRect_x                                    0x922520
#define CXWnd__GetWindowTextA_x                                    0x49CDB0
#define CXWnd__IsActive_x                                          0x922C40
#define CXWnd__IsDescendantOf_x                                    0x924FC0
#define CXWnd__IsReallyVisible_x                                   0x924FF0
#define CXWnd__IsType_x                                            0x926800
#define CXWnd__Move_x                                              0x925060
#define CXWnd__Move1_x                                             0x925120
#define CXWnd__ProcessTransition_x                                 0x925C20
#define CXWnd__Refade_x                                            0x925400
#define CXWnd__Resize_x                                            0x9256A0
#define CXWnd__Right_x                                             0x925EB0
#define CXWnd__SetFocus_x                                          0x925A40
#define CXWnd__SetFont_x                                           0x925AB0
#define CXWnd__SetKeyTooltip_x                                     0x926620
#define CXWnd__SetMouseOver_x                                      0x923490
#define CXWnd__StartFade_x                                         0x924EA0
#define CXWnd__GetChildItem_x                                      0x926300
#define CXWnd__SetParent_x                                         0x924D50
#define CXWnd__Minimize_x                                          0x925710

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x95CBB0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x929070
#define CXWndManager__DrawWindows_x                                0x929090
#define CXWndManager__GetKeyboardFlags_x                           0x92B7B0
#define CXWndManager__HandleKeyboardMsg_x                          0x92B360
#define CXWndManager__RemoveWnd_x                                  0x92B9E0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x92BF50

// CDBStr
#define CDBStr__GetString_x                                        0x547B30

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BFC40
#define EQ_Character__Cur_HP_x                                     0x4D2E00
#define EQ_Character__Cur_Mana_x                                   0x4DA540
#define EQ_Character__GetCastingTimeModifier_x                     0x4C2CB0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B3690
#define EQ_Character__GetFocusRangeModifier_x                      0x4B37E0
#define EQ_Character__GetHPRegen_x                                 0x4E0410
#define EQ_Character__GetEnduranceRegen_x                          0x4E0A10
#define EQ_Character__GetManaRegen_x                               0x4E0E50
#define EQ_Character__Max_Endurance_x                              0x65FD50
#define EQ_Character__Max_HP_x                                     0x4D2C30
#define EQ_Character__Max_Mana_x                                   0x65FB50
#define EQ_Character__doCombatAbility_x                            0x662140
#define EQ_Character__UseSkill_x                                   0x4E2C60
#define EQ_Character__GetConLevel_x                                0x6584F0
#define EQ_Character__IsExpansionFlag_x                            0x5BB650
#define EQ_Character__TotalEffect_x                                0x4C6A50
#define EQ_Character__GetPCSpellAffect_x                           0x4C3A00
#define EQ_Character__SpellDuration_x                              0x4C3530
#define EQ_Character__MySpellDuration_x                            0x4B1FC0
#define EQ_Character__GetAdjustedSkill_x                           0x4D5B80
#define EQ_Character__GetBaseSkill_x                               0x4D6B20
#define EQ_Character__CanUseItem_x                                 0x4DA850

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BEFB0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x676080

//PcClient
#define PcClient__vftable_x                                        0xAF41DC
#define PcClient__PcClient_x                                       0x655C60

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA670
#define CCharacterListWnd__EnterWorld_x                            0x4BA040
#define CCharacterListWnd__Quit_x                                  0x4B9D90
#define CCharacterListWnd__UpdateList_x                            0x4BA230

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x639FD0
#define EQ_Item__CreateItemTagString_x                             0x898DE0
#define EQ_Item__IsStackable_x                                     0x89DB10
#define EQ_Item__GetImageNum_x                                     0x89A970
#define EQ_Item__CreateItemClient_x                                0x6391F0
#define EQ_Item__GetItemValue_x                                    0x89BCA0
#define EQ_Item__ValueSellMerchant_x                               0x89F530
#define EQ_Item__IsKeyRingItem_x                                   0x89D3C0
#define EQ_Item__CanGoInBag_x                                      0x63A0F0
#define EQ_Item__IsEmpty_x                                         0x89CF00
#define EQ_Item__GetMaxItemCount_x                                 0x89C0B0
#define EQ_Item__GetHeldItem_x                                     0x89A840
#define EQ_Item__GetAugmentFitBySlot_x                             0x898640

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x566620
#define EQ_LoadingS__Array_x                                       0xC15130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x660650
#define EQ_PC__GetAlternateAbilityId_x                             0x8A8840
#define EQ_PC__GetCombatAbility_x                                  0x8A8EB0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A8F20
#define EQ_PC__GetItemRecastTimer_x                                0x6626C0
#define EQ_PC__HasLoreItem_x                                       0x658D10
#define EQ_PC__AlertInventoryChanged_x                             0x657E30
#define EQ_PC__GetPcZoneClient_x                                   0x6851A0
#define EQ_PC__RemoveMyAffect_x                                    0x6658E0
#define EQ_PC__GetKeyRingItems_x                                   0x8A97F0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A9570
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A9AF0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5C1A90
#define EQItemList__add_object_x                                   0x5EF0E0
#define EQItemList__add_item_x                                     0x5C1FF0
#define EQItemList__delete_item_x                                  0x5C2040
#define EQItemList__FreeItemList_x                                 0x5C1F40

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x5446A0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x677980
#define EQPlayer__dEQPlayer_x                                      0x66AD00
#define EQPlayer__DoAttack_x                                       0x67F930
#define EQPlayer__EQPlayer_x                                       0x66B3C0
#define EQPlayer__SetNameSpriteState_x                             0x66F690
#define EQPlayer__SetNameSpriteTint_x                              0x670570
#define PlayerBase__HasProperty_j_x                                0x98B700
#define EQPlayer__IsTargetable_x                                   0x98BBA0
#define EQPlayer__CanSee_x                                         0x98BA00
#define EQPlayer__CanSee1_x                                        0x98BAD0
#define PlayerBase__GetVisibilityLineSegment_x                     0x98B7C0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x682C30
#define PlayerZoneClient__GetLevel_x                               0x6851E0
#define PlayerZoneClient__IsValidTeleport_x                        0x5F0260
#define PlayerZoneClient__LegalPlayerRace_x                        0x55F3B0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x67A760
#define EQPlayerManager__GetSpawnByName_x                          0x67A810
#define EQPlayerManager__GetPlayerFromPartialName_x                0x67A8A0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63D730
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63D7B0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63D7F0
#define KeypressHandler__ClearCommandStateArray_x                  0x63EBE0
#define KeypressHandler__HandleKeyDown_x                           0x63EC00
#define KeypressHandler__HandleKeyUp_x                             0x63ECA0
#define KeypressHandler__SaveKeymapping_x                          0x63F0F0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x776C70
#define MapViewMap__SaveEx_x                                       0x77A030
#define MapViewMap__SetZoom_x                                      0x77E6F0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BD010

// StringTable 
#define StringTable__getString_x                                   0x8B7E10

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x665550
#define PcZoneClient__RemovePetEffect_x                            0x665B80
#define PcZoneClient__HasAlternateAbility_x                        0x65F980
#define PcZoneClient__GetCurrentMod_x                              0x4E5D80
#define PcZoneClient__GetModCap_x                                  0x4E5C80
#define PcZoneClient__CanEquipItem_x                               0x660030
#define PcZoneClient__GetItemByID_x                                0x662B30
#define PcZoneClient__GetItemByItemClass_x                         0x662C80
#define PcZoneClient__RemoveBuffEffect_x                           0x665BA0
#define PcZoneClient__BandolierSwap_x                              0x660C10
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x662660

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F4DD0

//IconCache
#define IconCache__GetIcon_x                                       0x718840

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x710360
#define CContainerMgr__CloseContainer_x                            0x710630
#define CContainerMgr__OpenExperimentContainer_x                   0x7110B0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CF3F0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x632180

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76D0B0
#define CLootWnd__RequestLootSlot_x                                0x76C380

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58DEE0
#define EQ_Spell__SpellAffects_x                                   0x58E350
#define EQ_Spell__SpellAffectBase_x                                0x58E110
#define EQ_Spell__IsStackable_x                                    0x4CA820
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CA610
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7950
#define EQ_Spell__IsSPAStacking_x                                  0x58F1A0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58E6B0
#define EQ_Spell__IsNoRemove_x                                     0x4CA800
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58F1B0
#define __IsResEffectSpell_x                                       0x4C9A80

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD340

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C7650

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x8162F0
#define CTargetWnd__WndNotification_x                              0x815B30
#define CTargetWnd__RefreshTargetBuffs_x                           0x815E00
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x814C90

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x81A960
#define CTaskWnd__ConfirmAbandonTask_x                             0x81D5A0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x5420C0
#define CTaskManager__HandleMessage_x                              0x540530
#define CTaskManager__GetTaskStatus_x                              0x542170
#define CTaskManager__GetElementDescription_x                      0x5421F0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x589000
#define EqSoundManager__PlayScriptMp3_x                            0x5892C0
#define EqSoundManager__SoundAssistPlay_x                          0x69D800
#define EqSoundManager__WaveInstancePlay_x                         0x69CD70

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x5334E0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x9474A0
#define CTextureAnimation__Draw_x                                  0x9476A0

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x943400

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56E120
#define CAltAbilityData__GetMercMaxRank_x                          0x56E0B0
#define CAltAbilityData__GetMaxRank_x                              0x563570

//CTargetRing
#define CTargetRing__Cast_x                                        0x6302A0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA5F0
#define CharacterBase__CreateItemGlobalIndex_x                     0x51A1B0
#define CharacterBase__CreateItemIndex_x                           0x6383A0
#define CharacterBase__GetItemPossession_x                         0x506040
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CFCF0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CFD50
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F7380
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F7BB0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F7C60

//messages
#define msg_spell_worn_off_x                                       0x5B3500
#define msg_new_text_x                                             0x5A7E60
#define __msgTokenTextParam_x                                      0x5B5790
#define msgTokenText_x                                             0x5B59E0

//SpellManager
#define SpellManager__vftable_x                                    0xADC554
#define SpellManager__SpellManager_x                               0x6A0B30
#define Spellmanager__LoadTextSpells_x                             0x6A1420
#define SpellManager__GetSpellByGroupAndRank_x                     0x6A0D00

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98F630

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x51A8A0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B99E0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x6513B0
#define ItemGlobalIndex__IsValidIndex_x                            0x51A930

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C8010
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C81A0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x7658F0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x714A40
#define CCursorAttachment__AttachToCursor1_x                       0x714A80
#define CCursorAttachment__Deactivate_x                            0x715A70

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x93A140
#define CSidlManagerBase__CreatePageWnd_x                          0x939930
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x935BC0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x935B50

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x957110
#define CEQSuiteTextureLoader__GetTexture_x                        0x956DD0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x5174D0
#define CFindItemWnd__WndNotification_x                            0x518110
#define CFindItemWnd__Update_x                                     0x518C80
#define CFindItemWnd__PickupSelectedItem_x                         0x516D00

//IString
#define IString__Append_x                                          0x507860

//Camera
#define CDisplay__cameraType_x                                     0xDECCC8
#define EverQuest__Cameras_x                                       0xEA80A0

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x520190
#define LootFiltersManager__GetItemFilterData_x                    0x51FA90
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51FAC0
#define LootFiltersManager__SetItemLootFilter_x                    0x51FCE0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BD230

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x995230
#define CResolutionHandler__GetWindowedStyle_x                     0x6983F0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70D020

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D3A90
#define CDistillerInfo__Instance_x                                 0x8D3A30

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72BDB0
#define CGroupWnd__UpdateDisplay_x                                 0x72B110

//ItemBase
#define ItemBase__IsLore_x                                         0x89D470
#define ItemBase__IsLoreEquipped_x                                 0x89D4E0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EF040
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EF180
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EF1E0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68D970
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x691300

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50DB10

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F9F20
#define FactionManagerClient__HandleFactionMessage_x               0x4FA590
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4FAB50
#define FactionManagerClient__GetMaxFaction_x                      0x4FAB6F
#define FactionManagerClient__GetMinFaction_x                      0x4FAB20

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x506010

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91E640

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C0C0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x506270

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56D5B0

//CTargetManager
#define CTargetManager__Get_x                                      0x6A4380

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68D970

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8F10

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5C1EE0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF45734

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6C0D20
#define CAAWnd__UpdateSelected_x                                   0x6BD590
#define CAAWnd__Update_x                                           0x6C0040

//CXRect
#define CXRect__operator_and_x                                     0x722EB0

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x483240

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
