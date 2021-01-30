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
#define __ExpectedVersionDate                                     "Dec  7 2020"
#define __ExpectedVersionTime                                     "04:17:16"
#define __ActualVersionDate_x                                      0xAF7564
#define __ActualVersionTime_x                                      0xAF7558
#define __ActualVersionBuild_x                                     0xAE557C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x644750
#define __MemChecker1_x                                            0x8F8220
#define __MemChecker2_x                                            0x6B5320
#define __MemChecker3_x                                            0x6B5270
#define __MemChecker4_x                                            0x84E450
#define __EncryptPad0_x                                            0xC2D9C8
#define __EncryptPad1_x                                            0xC8B210
#define __EncryptPad2_x                                            0xC3DD90
#define __EncryptPad3_x                                            0xC3D990
#define __EncryptPad4_x                                            0xC7B7A0
#define __EncryptPad5_x                                            0xF4E108
#define __AC1_x                                                    0x80CFE6
#define __AC2_x                                                    0x5FDD5F
#define __AC3_x                                                    0x6053B0
#define __AC4_x                                                    0x609360
#define __AC5_x                                                    0x60F65F
#define __AC6_x                                                    0x613B16
#define __AC7_x                                                    0x5FD7D0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x193310

// Direct Input
#define DI8__Main_x                                                0xF4B190
#define DI8__Keyboard_x                                            0xF4B194
#define DI8__Mouse_x                                               0xF4E0F4
#define DI8__Mouse_Copy_x                                          0xEA69EC
#define DI8__Mouse_Check_x                                         0xF4BC54
#define __AutoSkillArray_x                                         0xEA7908
#define __Attack_x                                                 0xF45737
#define __Autofire_x                                               0xF45738
#define __BindList_x                                               0xC1C400
#define g_eqCommandStates_x                                        0xC1D180
#define __Clicks_x                                                 0xEA6AA4
#define __CommandList_x                                            0xC1DD40
#define __CurrentMapLabel_x                                        0xF5E154
#define __CurrentSocial_x                                          0xC057D4
#define __DoAbilityList_x                                          0xEDD258
#define __do_loot_x                                                0x5C9770
#define __DrawHandler_x                                            0x15DD148
#define __GroupCount_x                                             0xEA1512
#define __Guilds_x                                                 0xEA5928
#define __gWorld_x                                                 0xEA1CA8
#define __HWnd_x                                                   0xF4E0F8
#define __heqmain_x                                                0xF4E0E8
#define __InChatMode_x                                             0xEA69D4
#define __LastTell_x                                               0xEA8954
#define __LMouseHeldTime_x                                         0xEA6B10
#define __Mouse_x                                                  0xF4E114
#define __MouseLook_x                                              0xEA6A6A
#define __MouseEventTime_x                                         0xF4621C
#define __gpbCommandEvent_x                                        0xEA1768
#define __NetStatusToggle_x                                        0xEA6A6D
#define __PCNames_x                                                0xEA7F04
#define __RangeAttackReady_x                                       0xEA7BEC
#define __RMouseHeldTime_x                                         0xEA6B0C
#define __RunWalkState_x                                           0xEA69D8
#define __ScreenMode_x                                             0xDED4E8
#define __ScreenX_x                                                0xEA698C
#define __ScreenY_x                                                0xEA6988
#define __ScreenXMax_x                                             0xEA6990
#define __ScreenYMax_x                                             0xEA6994
#define __ServerHost_x                                             0xEA1933
#define __ServerName_x                                             0xEDD218
#define __ShiftKeyDown_x                                           0xEA7068
#define __ShowNames_x                                              0xEA7DA8
#define EverQuestInfo__bSocialChanged_x                            0xEDD2A0
#define __Socials_x                                                0xEDD318
#define __SubscriptionType_x                                       0xFA2418
#define __TargetAggroHolder_x                                      0xF60B08
#define __ZoneType_x                                               0xEA6E68
#define __GroupAggro_x                                             0xF60B48
#define __LoginName_x                                              0xF4B8E4
#define __Inviter_x                                                0xF456B4
#define __AttackOnAssist_x                                         0xEA7D64
#define __UseTellWindows_x                                         0xEA809C
#define __gfMaxZoomCameraDistance_x                                0xAEF178
#define __gfMaxCameraDistance_x                                    0xB17DF8
#define __pulAutoRun_x                                             0xEA6A88
#define __pulForward_x                                             0xEA80D4
#define __pulBackward_x                                            0xEA80D8
#define __pulTurnRight_x                                           0xEA80DC
#define __pulTurnLeft_x                                            0xEA80E0
#define __pulStrafeLeft_x                                          0xEA80E4
#define __pulStrafeRight_x                                         0xEA80E8

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEA1CC0
#define instEQZoneInfo_x                                           0xEA6C60
#define pinstActiveBanker_x                                        0xEA1C54
#define pinstActiveCorpse_x                                        0xEA1C4C
#define pinstActiveGMaster_x                                       0xEA1C50
#define pinstActiveMerchant_x                                      0xEA1C48
#define pinstAltAdvManager_x                                       0xDEDEF0
#define pinstBandageTarget_x                                       0xEA1C64
#define pinstCamActor_x                                            0xDED4D4
#define pinstCDBStr_x                                              0xDECC0C
#define pinstCDisplay_x                                            0xEA1CB4
#define pinstCEverQuest_x                                          0xF4B1AC
#define pinstEverQuestInfo_x                                       0xEA6980
#define pinstCharData_x                                            0xEA1754
#define pinstCharSpawn_x                                           0xEA1C9C
#define pinstControlledMissile_x                                   0xEA1CB0
#define pinstControlledPlayer_x                                    0xEA1C9C
#define pinstCResolutionHandler_x                                  0x15DD378
#define pinstCSidlManager_x                                        0x15DC310
#define pinstCXWndManager_x                                        0x15DC30C
#define instDynamicZone_x                                          0xEA5800
#define pinstDZMember_x                                            0xEA5910
#define pinstDZTimerInfo_x                                         0xEA5914
#define pinstEqLogin_x                                             0xF4B230
#define instEQMisc_x                                               0xDECB50
#define pinstEQSoundManager_x                                      0xDEEEC0
#define pinstEQSpellStrings_x                                      0xCAF448
#define instExpeditionLeader_x                                     0xEA584A
#define instExpeditionName_x                                       0xEA588A
#define pinstGroup_x                                               0xEA150E
#define pinstImeManager_x                                          0x15DC308
#define pinstLocalPlayer_x                                         0xEA1C44
#define pinstMercenaryData_x                                       0xF47D14
#define pinstMercenaryStats_x                                      0xF60BD4
#define pinstModelPlayer_x                                         0xEA1C5C
#define pinstPCData_x                                              0xEA1754
#define pinstSkillMgr_x                                            0xF49E70
#define pinstSpawnManager_x                                        0xF48918
#define pinstSpellManager_x                                        0xF4A0B0
#define pinstSpellSets_x                                           0xF3E360
#define pinstStringTable_x                                         0xEA1758
#define pinstSwitchManager_x                                       0xE9F260
#define pinstTarget_x                                              0xEA1C98
#define pinstTargetObject_x                                        0xEA1CA4
#define pinstTargetSwitch_x                                        0xEA13B0
#define pinstTaskMember_x                                          0xDEC9E0
#define pinstTrackTarget_x                                         0xEA1CA0
#define pinstTradeTarget_x                                         0xEA1C58
#define instTributeActive_x                                        0xDECB71
#define pinstViewActor_x                                           0xDED4D0
#define pinstWorldData_x                                           0xEA13B8
#define pinstZoneAddr_x                                            0xEA6F00
#define pinstPlayerPath_x                                          0xF489B0
#define pinstTargetIndicator_x                                     0xF4A318
#define EQObject_Top_x                                             0xEA1A3C
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDECF74
#define pinstCAchievementsWnd_x                                    0xDED48C
#define pinstCActionsWnd_x                                         0xDECFB0
#define pinstCAdvancedDisplayOptionsWindow_x                       0xDECCAC
#define pinstCAdvancedLootWnd_x                                    0xDED4FC
#define pinstCAdventureLeaderboardWnd_x                            0xF57928
#define pinstCAdventureRequestWnd_x                                0xF579D8
#define pinstCAdventureStatsWnd_x                                  0xF57A88
#define pinstCAggroMeterWnd_x                                      0xDED530
#define pinstCAlarmWnd_x                                           0xDED4B8
#define pinstCAlertHistoryWnd_x                                    0xDECF24
#define pinstCAlertStackWnd_x                                      0xDED518
#define pinstCAlertWnd_x                                           0xDED52C
#define pinstCAltStorageWnd_x                                      0xF57DE8
#define pinstCAudioTriggersWindow_x                                0xCA1778
#define pinstCAuraWnd_x                                            0xDED500
#define pinstCAvaZoneWnd_x                                         0xDECF28
#define pinstCBandolierWnd_x                                       0xDED544
#define pinstCBankWnd_x                                            0xDECCE8
#define pinstCBarterMerchantWnd_x                                  0xF59028
#define pinstCBarterSearchWnd_x                                    0xF590D8
#define pinstCBarterWnd_x                                          0xF59188
#define pinstCBazaarConfirmationWnd_x                              0xDED4C8
#define pinstCBazaarSearchWnd_x                                    0xDECF78
#define pinstCBazaarWnd_x                                          0xDED494
#define pinstCBlockedBuffWnd_x                                     0xDED50C
#define pinstCBlockedPetBuffWnd_x                                  0xDED534
#define pinstCBodyTintWnd_x                                        0xDED43C
#define pinstCBookWnd_x                                            0xDECCDC
#define pinstCBreathWnd_x                                          0xDECF88
#define pinstCBuffWindowNORMAL_x                                   0xDED4F4
#define pinstCBuffWindowSHORT_x                                    0xDED4F8
#define pinstCBugReportWnd_x                                       0xDECCE4
#define pinstCButtonWnd_x                                          0x15DC578
#define pinstCCastingWnd_x                                         0xDECCD0
#define pinstCCastSpellWnd_x                                       0xDECF84
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDED448
#define pinstCChatWindowManager_x                                  0xF59C48
#define pinstCClaimWnd_x                                           0xF59DA0
#define pinstCColorPickerWnd_x                                     0xDECF3C
#define pinstCCombatAbilityWnd_x                                   0xDED4A4
#define pinstCCombatSkillsSelectWnd_x                              0xDED45C
#define pinstCCompassWnd_x                                         0xDECFB4
#define pinstCConfirmationDialog_x                                 0xF5ECA0
#define pinstCContainerMgr_x                                       0xDED438
#define pinstCContextMenuManager_x                                 0x15DC2C8
#define pinstCCursorAttachment_x                                   0xDECCB8
#define pinstCDynamicZoneWnd_x                                     0xF5A368
#define pinstCEditLabelWnd_x                                       0xDED4E0
#define pinstCEQMainWnd_x                                          0xF5A5B0
#define pinstCEventCalendarWnd_x                                   0xDECF7C
#define pinstCExtendedTargetWnd_x                                  0xDED510
#define pinstCPlayerCustomizationWnd_x                             0xDED460
#define pinstCFactionWnd_x                                         0xDED480
#define pinstCFellowshipWnd_x                                      0xF5A7B0
#define pinstCFileSelectionWnd_x                                   0xDECF38
#define pinstCFindItemWnd_x                                        0xDED474
#define pinstCFindLocationWnd_x                                    0xF5A908
#define pinstCFriendsWnd_x                                         0xDED470
#define pinstCGemsGameWnd_x                                        0xDED47C
#define pinstCGiveWnd_x                                            0xDED4BC
#define pinstCGroupSearchFiltersWnd_x                              0xDECCA8
#define pinstCGroupSearchWnd_x                                     0xF5AD00
#define pinstCGroupWnd_x                                           0xF5ADB0
#define pinstCGuildBankWnd_x                                       0xF5AE60
#define pinstCGuildCreationWnd_x                                   0xF5AF10
#define pinstCGuildMgmtWnd_x                                       0xF5AFC0
#define pinstCharacterCreation_x                                   0xDED468
#define pinstCHelpWnd_x                                            0xDED4B4
#define pinstCHeritageSelectionWnd_x                               0xDED46C
#define pinstCHotButtonWnd_x                                       0xF5D118
#define pinstCHotButtonWnd1_x                                      0xF5D118
#define pinstCHotButtonWnd2_x                                      0xF5D11C
#define pinstCHotButtonWnd3_x                                      0xF5D120
#define pinstCHotButtonWnd4_x                                      0xF5D124
#define pinstCIconSelectionWnd_x                                   0xDECCB4
#define pinstCInspectWnd_x                                         0xDED538
#define pinstCInventoryWnd_x                                       0xDED504
#define pinstCInvSlotMgr_x                                         0xDECF68
#define pinstCItemDisplayManager_x                                 0xF5D6A8
#define pinstCItemExpTransferWnd_x                                 0xF5D7D8
#define pinstCItemOverflowWnd_x                                    0xDECF80
#define pinstCJournalCatWnd_x                                      0xDECF54
#define pinstCJournalNPCWnd_x                                      0xDECF14
#define pinstCJournalTextWnd_x                                     0xDECF14
#define pinstCKeyRingWnd_x                                         0xDECCCC
#define pinstCLargeDialogWnd_x                                     0xF5F920
#define pinstCLayoutCopyWnd_x                                      0xF5DB28
#define pinstCLFGuildWnd_x                                         0xF5DBD8
#define pinstCLoadskinWnd_x                                        0xDED498
#define pinstCLootFiltersCopyWnd_x                                 0xCBDEE8
#define pinstCLootFiltersWnd_x                                     0xDED51C
#define pinstCLootSettingsWnd_x                                    0xDED540
#define pinstCLootWnd_x                                            0xDECF58
#define pinstCMailAddressBookWnd_x                                 0xDECF6C
#define pinstCMailCompositionWnd_x                                 0xDECF44
#define pinstCMailIgnoreListWnd_x                                  0xDECF70
#define pinstCMailWnd_x                                            0xDECF30
#define pinstCManageLootWnd_x                                      0xDEE3A0
#define pinstCMapToolbarWnd_x                                      0xDED4C0
#define pinstCMapViewWnd_x                                         0xDED488
#define pinstCMarketplaceWnd_x                                     0xDED520
#define pinstCMerchantWnd_x                                        0xDECF64
#define pinstCMIZoneSelectWnd_x                                    0xF5E410
#define pinstCMusicPlayerWnd_x                                     0xDECD04
#define pinstCNameChangeMercWnd_x                                  0xDED4C4
#define pinstCNameChangePetWnd_x                                   0xDED490
#define pinstCNameChangeWnd_x                                      0xDED4D8
#define pinstCNoteWnd_x                                            0xDED49C
#define pinstCObjectPreviewWnd_x                                   0xDED53C
#define pinstCOptionsWnd_x                                         0xDED4AC
#define pinstCPetInfoWnd_x                                         0xDECF2C
#define pinstCPetitionQWnd_x                                       0xDED458
#define pinstCPlayerNotesWnd_x                                     0xDED440
#define pinstCPlayerWnd_x                                          0xDECF20
#define pinstCPopupWndManager_x                                    0xF5ECA0
#define pinstCProgressionSelectionWnd_x                            0xF5ED50
#define pinstCPurchaseGroupWnd_x                                   0xDECCF8
#define pinstCPurchaseWnd_x                                        0xDECCD4
#define pinstCPvPLeaderboardWnd_x                                  0xF5EE00
#define pinstCPvPStatsWnd_x                                        0xF5EEB0
#define pinstCQuantityWnd_x                                        0xDECF10
#define pinstCRaceChangeWnd_x                                      0xDED508
#define pinstCRaidOptionsWnd_x                                     0xDECCB0
#define pinstCRaidWnd_x                                            0xDECF60
#define pinstCRealEstateItemsWnd_x                                 0xDED484
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDED030
#define pinstCRealEstateManageWnd_x                                0xDECCFC
#define pinstCRealEstateNeighborhoodWnd_x                          0xDECF1C
#define pinstCRealEstatePlotSearchWnd_x                            0xDECF34
#define pinstCRealEstatePurchaseWnd_x                              0xDECF50
#define pinstCRespawnWnd_x                                         0xDED528
#define pinstCRewardSelectionWnd_x                                 0xF5F5F8
#define pinstCSelectorWnd_x                                        0xDED454
#define pinstCSendMoneyWnd_x                                       0xDED4CC
#define pinstCServerListWnd_x                                      0xDECF5C
#define pinstCSkillsSelectWnd_x                                    0xDED450
#define pinstCSkillsWnd_x                                          0xDED02C
#define pinstCSocialEditWnd_x                                      0xDECCC4
#define pinstCSocialWnd_x                                          0xDED4B0
#define pinstCSpellBookWnd_x                                       0xDED4A0
#define pinstCStoryWnd_x                                           0xDECFAC
#define pinstCTargetOfTargetWnd_x                                  0xF60C58
#define pinstCTargetWnd_x                                          0xDED524
#define pinstCTaskOverlayWnd_x                                     0xDECCEC
#define pinstCTaskSelectWnd_x                                      0xF60DB0
#define pinstCTaskManager_x                                        0xCBE828
#define pinstCTaskTemplateSelectWnd_x                              0xF60E60
#define pinstCTaskWnd_x                                            0xF60F10
#define pinstCTextEntryWnd_x                                       0xDECCD8
#define pinstCTimeLeftWnd_x                                        0xDED44C
#define pinstCTipWndCONTEXT_x                                      0xF61114
#define pinstCTipWndOFDAY_x                                        0xF61110
#define pinstCTitleWnd_x                                           0xF611C0
#define pinstCTrackingWnd_x                                        0xDED514
#define pinstCTradeskillWnd_x                                      0xF61328
#define pinstCTradeWnd_x                                           0xDED444
#define pinstCTrainWnd_x                                           0xDECF48
#define pinstCTributeBenefitWnd_x                                  0xF61528
#define pinstCTributeMasterWnd_x                                   0xF615D8
#define pinstCTributeTrophyWnd_x                                   0xF61688
#define pinstCVideoModesWnd_x                                      0xDECCF0
#define pinstCVoiceMacroWnd_x                                      0xF4A8D0
#define pinstCVoteResultsWnd_x                                     0xDED478
#define pinstCVoteWnd_x                                            0xDED464
#define pinstCWebManager_x                                         0xF4AF4C
#define pinstCZoneGuideWnd_x                                       0xDECCF4
#define pinstCZonePathWnd_x                                        0xDECF08

#define pinstEQSuiteTextureLoader_x                                0xC8BB30
#define pinstItemIconCache_x                                       0xF5A568
#define pinstLootFiltersManager_x                                  0xCBDF98
#define pinstRewardSelectionWnd_x                                  0xF5F5F8

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5C4E60
#define __CastRay2_x                                               0x5C4EB0
#define __ConvertItemTags_x                                        0x5E0B80
#define __CleanItemTags_x                                          0x47D330
#define __DoesFileExist_x                                          0x8FB300
#define __EQGetTime_x                                              0x8F7E50
#define __ExecuteCmd_x                                             0x5BD7C0
#define __FixHeading_x                                             0x98D380
#define __FlushDxKeyboard_x                                        0x6B11C0
#define __GameLoop_x                                               0x6B44F0
#define __get_bearing_x                                            0x5C49C0
#define __get_melee_range_x                                        0x5C50A0
#define __GetAnimationCache_x                                      0x719930
#define __GetGaugeValueFromEQ_x                                    0x80B490
#define __GetLabelFromEQ_x                                         0x80CF70
#define __GetXTargetType_x                                         0x98EE40
#define __HandleMouseWheel_x                                       0x6B53D0
#define __HeadingDiff_x                                            0x98D3F0
#define __HelpPath_x                                               0xF45E0C
#define __LoadFrontEnd_x                                           0x6B1800
#define __NewUIINI_x                                               0x80B160
#define __ProcessGameEvents_x                                      0x6259F0
#define __ProcessMouseEvent_x                                      0x625180
#define __SaveColors_x                                             0x55DBD0
#define __STMLToText_x                                             0x930850
#define __ToggleKeyRingItem_x                                      0x51C370
#define CMemoryMappedFile__SetFile_x                               0xA7C6B0
#define CrashDetected_x                                            0x6B32B0
#define DrawNetStatus_x                                            0x651DE0
#define Expansion_HoT_x                                            0xEA7D50
#define Teleport_Table_Size_x                                      0xEA17F0
#define Teleport_Table_x                                           0xE9F3B0
#define Util__FastTime_x                                           0x8F7A20
#define __CopyLayout_x                                             0x63FE10
#define __WndProc_x                                                0x6B37B0
#define __ProcessKeyboardEvent_x                                   0x6B2D50

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490650
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499640
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499410
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493BE0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x493030

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x565E30
#define AltAdvManager__IsAbilityReady_x                            0x564BD0
#define AltAdvManager__GetAAById_x                                 0x564F60
#define AltAdvManager__CanTrainAbility_x                           0x564FD0
#define AltAdvManager__CanSeeAbility_x                             0x565330

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CB2B0
#define CharacterZoneClient__HasSkill_x                            0x4D6130
#define CharacterZoneClient__MakeMeVisible_x                       0x4D7860
#define CharacterZoneClient__IsStackBlocked_x                      0x4C29E0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBE70
#define CharacterZoneClient__GetItemCountWorn_x                    0x4DA220
#define CharacterZoneClient__GetItemCountInInventory_x             0x4DA300
#define CharacterZoneClient__GetCursorItemCount_x                  0x4DA3E0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C4AD0
#define CharacterZoneClient__BardCastBard_x                        0x4C7500
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF880
#define CharacterZoneClient__GetEffect_x                           0x4BBDB0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C5B40
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C5C10
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C5C60
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5DB0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5F90
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3D70
#define CharacterZoneClient__FindItemByGuid_x                      0x4D87C0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D8240

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6DAFD0
#define CBankWnd__WndNotification_x                                0x6DADA0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E87F0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x92E030
#define CButtonWnd__CButtonWnd_x                                   0x92CC10

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x708AE0
#define CChatManager__InitContextMenu_x                            0x701C10
#define CChatManager__FreeChatWindow_x                             0x707620
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9CE0
#define CChatManager__SetLockedActiveChatWindow_x                  0x708760
#define CChatManager__CreateChatWindow_x                           0x707C60

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9DF0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x9411C0
#define CContextMenu__dCContextMenu_x                              0x941400
#define CContextMenu__AddMenuItem_x                                0x941410
#define CContextMenu__RemoveMenuItem_x                             0x941720
#define CContextMenu__RemoveAllMenuItems_x                         0x941740
#define CContextMenu__CheckMenuItem_x                              0x9417C0
#define CContextMenu__SetMenuItem_x                                0x941640
#define CContextMenu__AddSeparator_x                               0x9415A0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x941D60
#define CContextMenuManager__RemoveMenu_x                          0x941DD0
#define CContextMenuManager__PopupMenu_x                           0x941E90
#define CContextMenuManager__Flush_x                               0x941D00
#define CContextMenuManager__GetMenu_x                             0x49B840
#define CContextMenuManager__CreateDefaultMenu_x                   0x714280

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D2CF0
#define CChatService__GetFriendName_x                              0x8D2D00

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x709360
#define CChatWindow__Clear_x                                       0x70A630
#define CChatWindow__WndNotification_x                             0x70ADC0
#define CChatWindow__AddHistory_x                                  0x709EF0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93E620
#define CComboWnd__Draw_x                                          0x93DB00
#define CComboWnd__GetCurChoice_x                                  0x93E460
#define CComboWnd__GetListRect_x                                   0x93DFC0
#define CComboWnd__GetTextRect_x                                   0x93E690
#define CComboWnd__InsertChoice_x                                  0x93E150
#define CComboWnd__SetColors_x                                     0x93E120
#define CComboWnd__SetChoice_x                                     0x93E430
#define CComboWnd__GetItemCount_x                                  0x93E470
#define CComboWnd__GetCurChoiceText_x                              0x93E4B0
#define CComboWnd__GetChoiceText_x                                 0x93E480
#define CComboWnd__InsertChoiceAtIndex_x                           0x93E1F0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x711C90
#define CContainerWnd__vftable_x                                   0xB00764
#define CContainerWnd__SetContainer_x                              0x7131E0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x558530
#define CDisplay__PreZoneMainUI_x                                  0x558540
#define CDisplay__CleanGameUI_x                                    0x55D990
#define CDisplay__GetClickedActor_x                                0x550990
#define CDisplay__GetUserDefinedColor_x                            0x549000
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
#define CEditBaseWnd__SetSel_x                                     0x961020

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x9446D0
#define CEditWnd__EnsureCaretVisible_x                             0x9468A0
#define CEditWnd__GetCaretPt_x                                     0x945850
#define CEditWnd__GetCharIndexPt_x                                 0x945600
#define CEditWnd__GetDisplayString_x                               0x9454A0
#define CEditWnd__GetHorzOffset_x                                  0x943D70
#define CEditWnd__GetLineForPrintableChar_x                        0x9467A0
#define CEditWnd__GetSelStartPt_x                                  0x9458B0
#define CEditWnd__GetSTMLSafeText_x                                0x9452C0
#define CEditWnd__PointFromPrintableChar_x                         0x9463D0
#define CEditWnd__SelectableCharFromPoint_x                        0x946540
#define CEditWnd__SetEditable_x                                    0x945980
#define CEditWnd__SetWindowTextA_x                                 0x945040
#define CEditWnd__ReplaceSelection_x                               0x946040
#define CEditWnd__ReplaceSelection1_x                              0x945FC0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x612FF0
#define CEverQuest__ClickedPlayer_x                                0x605190
#define CEverQuest__CreateTargetIndicator_x                        0x622B60
#define CEverQuest__DeleteTargetIndicator_x                        0x622BF0
#define CEverQuest__DoTellWindow_x                                 0x4E9ED0
#define CEverQuest__OutputTextToLog_x                              0x4EA1A0
#define CEverQuest__DropHeldItemOnGround_x                         0x5FA2E0
#define CEverQuest__dsp_chat_x                                     0x4EA530
#define CEverQuest__trimName_x                                     0x61ED10
#define CEverQuest__Emote_x                                        0x613850
#define CEverQuest__EnterZone_x                                    0x60D950
#define CEverQuest__GetBodyTypeDesc_x                              0x6182A0
#define CEverQuest__GetClassDesc_x                                 0x6188E0
#define CEverQuest__GetClassThreeLetterCode_x                      0x618EE0
#define CEverQuest__GetDeityDesc_x                                 0x6213B0
#define CEverQuest__GetLangDesc_x                                  0x6190A0
#define CEverQuest__GetRaceDesc_x                                  0x6188C0
#define CEverQuest__InterpretCmd_x                                 0x621980
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FE480
#define CEverQuest__LMouseUp_x                                     0x5FC800
#define CEverQuest__RightClickedOnPlayer_x                         0x5FED60
#define CEverQuest__RMouseUp_x                                     0x5FD790
#define CEverQuest__SetGameState_x                                 0x5FA070
#define CEverQuest__UPCNotificationFlush_x                         0x61EC10
#define CEverQuest__IssuePetCommand_x                              0x61A4B0
#define CEverQuest__ReportSuccessfulHit_x                          0x614BA0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x723A40
#define CGaugeWnd__CalcLinesFillRect_x                             0x723AA0
#define CGaugeWnd__Draw_x                                          0x7230C0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4B0050
#define CGuild__GetGuildName_x                                     0x4AEB00
#define CGuild__GetGuildIndex_x                                    0x4AF100

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73D6D0

//CHotButton
#define CHotButton__SetCheck_x                                     0x6342D0
#define CHotButton__SetButtonSize_x                                0x634690

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x74A930
#define CInvSlotMgr__MoveItem_x                                    0x7495F0
#define CInvSlotMgr__SelectSlot_x                                  0x74AA00

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x747E20
#define CInvSlot__SliderComplete_x                                 0x745B50
#define CInvSlot__GetItemBase_x                                    0x7454D0
#define CInvSlot__UpdateItem_x                                     0x745640

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x74C480
#define CInvSlotWnd__CInvSlotWnd_x                                 0x74B620
#define CInvSlotWnd__HandleLButtonUp_x                             0x74C000

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x806830
#define CItemDisplayWnd__UpdateStrings_x                           0x75AC70
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x7548F0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x754E20
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x75B280
#define CItemDisplayWnd__AboutToShow_x                             0x75A8B0
#define CItemDisplayWnd__WndNotification_x                         0x75C500
#define CItemDisplayWnd__RequestConvertItem_x                      0x75BE30
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x759910
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x75A6D0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x837400

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x760A40

// CLabel 
#define CLabel__Draw_x                                             0x766450

// CListWnd
#define CListWnd__CListWnd_x                                       0x916C40
#define CListWnd__dCListWnd_x                                      0x916F60
#define CListWnd__AddColumn_x                                      0x91B3E0
#define CListWnd__AddColumn1_x                                     0x91B430
#define CListWnd__AddLine_x                                        0x91B7C0
#define CListWnd__AddString_x                                      0x91B5C0
#define CListWnd__CalculateFirstVisibleLine_x                      0x91B1A0
#define CListWnd__CalculateVSBRange_x                              0x91AF80
#define CListWnd__ClearSel_x                                       0x91BFA0
#define CListWnd__ClearAllSel_x                                    0x91C000
#define CListWnd__CloseAndUpdateEditWindow_x                       0x91CA20
#define CListWnd__Compare_x                                        0x91A8B0
#define CListWnd__Draw_x                                           0x917090
#define CListWnd__DrawColumnSeparators_x                           0x919880
#define CListWnd__DrawHeader_x                                     0x919CF0
#define CListWnd__DrawItem_x                                       0x91A1F0
#define CListWnd__DrawLine_x                                       0x9199F0
#define CListWnd__DrawSeparator_x                                  0x919920
#define CListWnd__EnableLine_x                                     0x919150
#define CListWnd__EnsureVisible_x                                  0x91C940
#define CListWnd__ExtendSel_x                                      0x91BED0
#define CListWnd__GetColumnTooltip_x                               0x918C90
#define CListWnd__GetColumnMinWidth_x                              0x918D00
#define CListWnd__GetColumnWidth_x                                 0x918C00
#define CListWnd__GetCurSel_x                                      0x918590
#define CListWnd__GetItemAtPoint_x                                 0x9193D0
#define CListWnd__GetItemAtPoint1_x                                0x919440
#define CListWnd__GetItemData_x                                    0x918610
#define CListWnd__GetItemHeight_x                                  0x9189D0
#define CListWnd__GetItemIcon_x                                    0x9187A0
#define CListWnd__GetItemRect_x                                    0x919240
#define CListWnd__GetItemText_x                                    0x918650
#define CListWnd__GetSelList_x                                     0x91C050
#define CListWnd__GetSeparatorRect_x                               0x919680
#define CListWnd__InsertLine_x                                     0x91BBB0
#define CListWnd__RemoveLine_x                                     0x91BD00
#define CListWnd__SetColors_x                                      0x91AF50
#define CListWnd__SetColumnJustification_x                         0x91AC80
#define CListWnd__SetColumnLabel_x                                 0x91B560
#define CListWnd__SetColumnWidth_x                                 0x91ABA0
#define CListWnd__SetCurSel_x                                      0x91BE10
#define CListWnd__SetItemColor_x                                   0x91C5F0
#define CListWnd__SetItemData_x                                    0x91C5B0
#define CListWnd__SetItemText_x                                    0x91C1C0
#define CListWnd__ShiftColumnSeparator_x                           0x91AD40
#define CListWnd__Sort_x                                           0x91AA30
#define CListWnd__ToggleSel_x                                      0x91BE40
#define CListWnd__SetColumnsSizable_x                              0x91ADF0
#define CListWnd__SetItemWnd_x                                     0x91C470
#define CListWnd__GetItemWnd_x                                     0x9187F0
#define CListWnd__SetItemIcon_x                                    0x91C240
#define CListWnd__CalculateCustomWindowPositions_x                 0x91B2A0
#define CListWnd__SetVScrollPos_x                                  0x91AB80

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x77BAB0
#define CMapViewWnd__GetWorldCoordinates_x                         0x77A1C0
#define CMapViewWnd__HandleLButtonDown_x                           0x777200

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x79BD70
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79C650
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79CB80
#define CMerchantWnd__SelectRecoverySlot_x                         0x79FB40
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x79A8D0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A5720
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x79B980

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8A0780
#define CPacketScrambler__hton_x                                   0x8A0770

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x935E40
#define CSidlManager__FindScreenPieceTemplate_x                    0x936250
#define CSidlManager__FindScreenPieceTemplate1_x                   0x936040
#define CSidlManager__CreateLabel_x                                0x7FDAD0
#define CSidlManager__CreateXWndFromTemplate_x                     0x9391B0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x939390
#define CSidlManager__CreateXWnd_x                                 0x7FDA00
#define CSidlManager__CreateHotButtonWnd_x                         0x7FDFC0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x932920
#define CSidlScreenWnd__CalculateVSBRange_x                        0x932820
#define CSidlScreenWnd__ConvertToRes_x                             0x95BB70
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x932310
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x932000
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x9320D0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x9321A0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x932DC0
#define CSidlScreenWnd__EnableIniStorage_x                         0x933290
#define CSidlScreenWnd__GetSidlPiece_x                             0x932FB0
#define CSidlScreenWnd__Init1_x                                    0x931C00
#define CSidlScreenWnd__LoadIniInfo_x                              0x9332E0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x933E20
#define CSidlScreenWnd__LoadSidlScreen_x                           0x931000
#define CSidlScreenWnd__StoreIniInfo_x                             0x9339A0
#define CSidlScreenWnd__StoreIniVis_x                              0x933D00
#define CSidlScreenWnd__WndNotification_x                          0x932CD0
#define CSidlScreenWnd__GetChildItem_x                             0x933210
#define CSidlScreenWnd__HandleLButtonUp_x                          0x922950
#define CSidlScreenWnd__m_layoutCopy_x                             0x15DC198

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x69A240
#define CSkillMgr__GetSkillCap_x                                   0x69A420
#define CSkillMgr__GetNameToken_x                                  0x6999C0
#define CSkillMgr__IsActivatedSkill_x                              0x699B00
#define CSkillMgr__IsCombatSkill_x                                 0x699A40

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x942B40
#define CSliderWnd__SetValue_x                                     0x9429B0
#define CSliderWnd__SetNumTicks_x                                  0x942A10

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x803C00

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x94B4C0
#define CStmlWnd__ParseSTML_x                                      0x94C7D0
#define CStmlWnd__CalculateHSBRange_x                              0x94C5A0
#define CStmlWnd__CalculateVSBRange_x                              0x94C510
#define CStmlWnd__CanBreakAtCharacter_x                            0x9508E0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x951570
#define CStmlWnd__ForceParseNow_x                                  0x94BA60
#define CStmlWnd__GetNextTagPiece_x                                0x950840
#define CStmlWnd__GetSTMLText_x                                    0x50D850
#define CStmlWnd__GetVisibleText_x                                 0x94BA80
#define CStmlWnd__InitializeWindowVariables_x                      0x9513C0
#define CStmlWnd__MakeStmlColorTag_x                               0x94AB30
#define CStmlWnd__MakeWndNotificationTag_x                         0x94ABA0
#define CStmlWnd__SetSTMLText_x                                    0x949BE0
#define CStmlWnd__StripFirstSTMLLines_x                            0x952670
#define CStmlWnd__UpdateHistoryString_x                            0x951780

// CTabWnd 
#define CTabWnd__Draw_x                                            0x948D10
#define CTabWnd__DrawCurrentPage_x                                 0x949440
#define CTabWnd__DrawTab_x                                         0x949160
#define CTabWnd__GetCurrentPage_x                                  0x948510
#define CTabWnd__GetPageInnerRect_x                                0x948750
#define CTabWnd__GetTabInnerRect_x                                 0x948690
#define CTabWnd__GetTabRect_x                                      0x948540
#define CTabWnd__InsertPage_x                                      0x948960
#define CTabWnd__RemovePage_x                                      0x948AD0
#define CTabWnd__SetPage_x                                         0x9487D0
#define CTabWnd__SetPageRect_x                                     0x948C50
#define CTabWnd__UpdatePage_x                                      0x949020
#define CTabWnd__GetPageFromTabIndex_x                             0x9490A0
#define CTabWnd__GetCurrentTabIndex_x                              0x948500

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x760E50
#define CPageWnd__SetTabText_x                                     0x948050
#define CPageWnd__FlashTab_x                                       0x9480B0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9340

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91F7C0
#define CTextureFont__GetTextExtent_x                              0x91F980

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AE390
#define CHtmlComponentWnd__ValidateUri_x                           0x73F0C0
#define CHtmlWnd__SetClientCallbacks_x                             0x639730
#define CHtmlWnd__AddObserver_x                                    0x639750
#define CHtmlWnd__RemoveObserver_x                                 0x6397B0
#define Window__getProgress_x                                      0x8559F0
#define Window__getStatus_x                                        0x855A10
#define Window__getURI_x                                           0x855A20

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x958980

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x90C820

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9BD0
#define CXStr__CXStr1_x                                            0x508B10
#define CXStr__CXStr3_x                                            0x8F3DD0
#define CXStr__dCXStr_x                                            0x4783C0
#define CXStr__operator_equal_x                                    0x8F4000
#define CXStr__operator_equal1_x                                   0x8F4040
#define CXStr__operator_plus_equal1_x                              0x8F4AD0
#define CXStr__SetString_x                                         0x8F69C0
#define CXStr__operator_char_p_x                                   0x8F4510
#define CXStr__GetChar_x                                           0x8F62F0
#define CXStr__Delete_x                                            0x8F5BC0
#define CXStr__GetUnicode_x                                        0x8F6360
#define CXStr__GetLength_x                                         0x4A90F0
#define CXStr__Mid_x                                               0x47D6E0
#define CXStr__Insert_x                                            0x8F63C0
#define CXStr__FindNext_x                                          0x8F6030

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x940DE0
#define CXWnd__BringToTop_x                                        0x926100
#define CXWnd__Center_x                                            0x925C80
#define CXWnd__ClrFocus_x                                          0x925AA0
#define CXWnd__Destroy_x                                           0x925B40
#define CXWnd__DoAllDrawing_x                                      0x9220E0
#define CXWnd__DrawChildren_x                                      0x9220B0
#define CXWnd__DrawColoredRect_x                                   0x922540
#define CXWnd__DrawTooltip_x                                       0x920BE0
#define CXWnd__DrawTooltipAtPoint_x                                0x920CA0
#define CXWnd__GetBorderFrame_x                                    0x9223A0
#define CXWnd__GetChildWndAt_x                                     0x9261A0
#define CXWnd__GetClientClipRect_x                                 0x9243B0
#define CXWnd__GetScreenClipRect_x                                 0x924460
#define CXWnd__GetScreenRect_x                                     0x9245E0
#define CXWnd__GetRelativeRect_x                                   0x9246B0
#define CXWnd__GetTooltipRect_x                                    0x922590
#define CXWnd__GetWindowTextA_x                                    0x49CF40
#define CXWnd__IsActive_x                                          0x922CD0
#define CXWnd__IsDescendantOf_x                                    0x925010
#define CXWnd__IsReallyVisible_x                                   0x925040
#define CXWnd__IsType_x                                            0x926810
#define CXWnd__Move_x                                              0x9250B0
#define CXWnd__Move1_x                                             0x925170
#define CXWnd__ProcessTransition_x                                 0x925C30
#define CXWnd__Refade_x                                            0x925450
#define CXWnd__Resize_x                                            0x9256F0
#define CXWnd__Right_x                                             0x925EC0
#define CXWnd__SetFocus_x                                          0x925A60
#define CXWnd__SetFont_x                                           0x925AD0
#define CXWnd__SetKeyTooltip_x                                     0x926630
#define CXWnd__SetMouseOver_x                                      0x923510
#define CXWnd__StartFade_x                                         0x924EF0
#define CXWnd__GetChildItem_x                                      0x926310
#define CXWnd__SetParent_x                                         0x924DA0
#define CXWnd__Minimize_x                                          0x925750

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x95CBF0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x929060
#define CXWndManager__DrawWindows_x                                0x929080
#define CXWndManager__GetKeyboardFlags_x                           0x92B880
#define CXWndManager__HandleKeyboardMsg_x                          0x92B430
#define CXWndManager__RemoveWnd_x                                  0x92BAB0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x92C030

// CDBStr
#define CDBStr__GetString_x                                        0x547FA0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BFFE0
#define EQ_Character__Cur_HP_x                                     0x4D3170
#define EQ_Character__Cur_Mana_x                                   0x4DA8E0
#define EQ_Character__GetCastingTimeModifier_x                     0x4C3050
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B39B0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3B00
#define EQ_Character__GetHPRegen_x                                 0x4E07E0
#define EQ_Character__GetEnduranceRegen_x                          0x4E0DE0
#define EQ_Character__GetManaRegen_x                               0x4E1220
#define EQ_Character__Max_Endurance_x                              0x6607C0
#define EQ_Character__Max_HP_x                                     0x4D2FA0
#define EQ_Character__Max_Mana_x                                   0x6605C0
#define EQ_Character__doCombatAbility_x                            0x662BB0
#define EQ_Character__UseSkill_x                                   0x4E3030
#define EQ_Character__GetConLevel_x                                0x658DB0
#define EQ_Character__IsExpansionFlag_x                            0x5BBFB0
#define EQ_Character__TotalEffect_x                                0x4C6DF0
#define EQ_Character__GetPCSpellAffect_x                           0x4C3DA0
#define EQ_Character__SpellDuration_x                              0x4C38D0
#define EQ_Character__MySpellDuration_x                            0x4B22E0
#define EQ_Character__GetAdjustedSkill_x                           0x4D5EF0
#define EQ_Character__GetBaseSkill_x                               0x4D6E90
#define EQ_Character__CanUseItem_x                                 0x4DABF0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BFD10

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x676B70

//PcClient
#define PcClient__vftable_x                                        0xAF41D4
#define PcClient__PcClient_x                                       0x656520

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA9F0
#define CCharacterListWnd__EnterWorld_x                            0x4BA3C0
#define CCharacterListWnd__Quit_x                                  0x4BA110
#define CCharacterListWnd__UpdateList_x                            0x4BA5B0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x63A8F0
#define EQ_Item__CreateItemTagString_x                             0x899C40
#define EQ_Item__IsStackable_x                                     0x89E970
#define EQ_Item__GetImageNum_x                                     0x89B800
#define EQ_Item__CreateItemClient_x                                0x639B30
#define EQ_Item__GetItemValue_x                                    0x89CB00
#define EQ_Item__ValueSellMerchant_x                               0x8A0360
#define EQ_Item__IsKeyRingItem_x                                   0x89E220
#define EQ_Item__CanGoInBag_x                                      0x63AA10
#define EQ_Item__IsEmpty_x                                         0x89DD50
#define EQ_Item__GetMaxItemCount_x                                 0x89CF10
#define EQ_Item__GetHeldItem_x                                     0x89B6D0
#define EQ_Item__CanGemFitInSlot_x                                 0x8994A0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x566B50
#define EQ_LoadingS__Array_x                                       0xC15130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x6610C0
#define EQ_PC__GetAlternateAbilityId_x                             0x8A9660
#define EQ_PC__GetCombatAbility_x                                  0x8A9CD0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A9D40
#define EQ_PC__GetItemRecastTimer_x                                0x663130
#define EQ_PC__HasLoreItem_x                                       0x6595D0
#define EQ_PC__AlertInventoryChanged_x                             0x6586F0
#define EQ_PC__GetPcZoneClient_x                                   0x685C80
#define EQ_PC__RemoveMyAffect_x                                    0x666350
#define EQ_PC__GetKeyRingItems_x                                   0x8AA610
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8AA390
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8AA910

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5C23C0
#define EQItemList__add_object_x                                   0x5EFB40
#define EQItemList__add_item_x                                     0x5C2920
#define EQItemList__delete_item_x                                  0x5C2970
#define EQItemList__FreeItemList_x                                 0x5C2870

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x544B90

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x678470
#define EQPlayer__dEQPlayer_x                                      0x66B7F0
#define EQPlayer__DoAttack_x                                       0x680410
#define EQPlayer__EQPlayer_x                                       0x66BEB0
#define EQPlayer__SetNameSpriteState_x                             0x670180
#define EQPlayer__SetNameSpriteTint_x                              0x671060
#define PlayerBase__HasProperty_j_x                                0x98B780
#define EQPlayer__IsTargetable_x                                   0x98BC20
#define EQPlayer__CanSee_x                                         0x98BA80
#define EQPlayer__CanSee1_x                                        0x98BB50
#define PlayerBase__GetVisibilityLineSegment_x                     0x98B840

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x683710
#define PlayerZoneClient__GetLevel_x                               0x685CC0
#define PlayerZoneClient__IsValidTeleport_x                        0x5F0CC0
#define PlayerZoneClient__LegalPlayerRace_x                        0x55F810

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x67B330
#define EQPlayerManager__GetSpawnByName_x                          0x67B3E0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x67B470

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63E070
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63E0F0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63E130
#define KeypressHandler__ClearCommandStateArray_x                  0x63F520
#define KeypressHandler__HandleKeyDown_x                           0x63F540
#define KeypressHandler__HandleKeyUp_x                             0x63F5E0
#define KeypressHandler__SaveKeymapping_x                          0x63FA30

// MapViewMap 
#define MapViewMap__Clear_x                                        0x777920
#define MapViewMap__SaveEx_x                                       0x77ACE0
#define MapViewMap__SetZoom_x                                      0x77F3A0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BDD70

// StringTable 
#define StringTable__getString_x                                   0x8B8B90

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x665FC0
#define PcZoneClient__RemovePetEffect_x                            0x6665F0
#define PcZoneClient__HasAlternateAbility_x                        0x6603F0
#define PcZoneClient__GetCurrentMod_x                              0x4E6150
#define PcZoneClient__GetModCap_x                                  0x4E6050
#define PcZoneClient__CanEquipItem_x                               0x660AA0
#define PcZoneClient__GetItemByID_x                                0x6635A0
#define PcZoneClient__GetItemByItemClass_x                         0x6636F0
#define PcZoneClient__RemoveBuffEffect_x                           0x666610
#define PcZoneClient__BandolierSwap_x                              0x661680
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x6630D0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F5830

//IconCache
#define IconCache__GetIcon_x                                       0x719330

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x710E30
#define CContainerMgr__CloseContainer_x                            0x711100
#define CContainerMgr__OpenExperimentContainer_x                   0x711B80

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D00C0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x632A90

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76DEE0
#define CLootWnd__RequestLootSlot_x                                0x76D1B0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58E550
#define EQ_Spell__SpellAffects_x                                   0x58E9C0
#define EQ_Spell__SpellAffectBase_x                                0x58E780
#define EQ_Spell__IsStackable_x                                    0x4CABA0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CA9F0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7C70
#define EQ_Spell__IsSPAStacking_x                                  0x58F810
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58ED20
#define EQ_Spell__IsNoRemove_x                                     0x4CAB80
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58F820
#define __IsResEffectSpell_x                                       0x4C9E40

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD590

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C8340

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x816F30
#define CTargetWnd__WndNotification_x                              0x816770
#define CTargetWnd__RefreshTargetBuffs_x                           0x816A40
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x8158D0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x81B5C0
#define CTaskWnd__ConfirmAbandonTask_x                             0x81E200

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x542580
#define CTaskManager__HandleMessage_x                              0x5409D0
#define CTaskManager__GetTaskStatus_x                              0x542630
#define CTaskManager__GetElementDescription_x                      0x5426B0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x589630
#define EqSoundManager__PlayScriptMp3_x                            0x5898F0
#define EqSoundManager__SoundAssistPlay_x                          0x69E100
#define EqSoundManager__WaveInstancePlay_x                         0x69D670

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x533940

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x947560
#define CTextureAnimation__Draw_x                                  0x947760

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x9434B0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56E660
#define CAltAbilityData__GetMercMaxRank_x                          0x56E5F0
#define CAltAbilityData__GetMaxRank_x                              0x563A50

//CTargetRing
#define CTargetRing__Cast_x                                        0x630BB0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA9D0
#define CharacterBase__CreateItemGlobalIndex_x                     0x51A4E0
#define CharacterBase__CreateItemIndex_x                           0x638CE0
#define CharacterBase__GetItemPossession_x                         0x5063F0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8D09E0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8D0A40
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F7DD0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F8600
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F86B0

//messages
#define msg_spell_worn_off_x                                       0x5B3FA0
#define msg_new_text_x                                             0x5A88E0
#define __msgTokenTextParam_x                                      0x5B6240
#define msgTokenText_x                                             0x5B6490

//SpellManager
#define SpellManager__vftable_x                                    0xADC554
#define SpellManager__SpellManager_x                               0x6A1430
#define Spellmanager__LoadTextSpells_x                             0x6A1D20
#define SpellManager__GetSpellByGroupAndRank_x                     0x6A1600

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98F730

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x51ABD0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5BA4C0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x651C40
#define ItemGlobalIndex__IsValidIndex_x                            0x51AC60

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C8D00
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C8E90

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x766790

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x715520
#define CCursorAttachment__AttachToCursor1_x                       0x715560
#define CCursorAttachment__Deactivate_x                            0x716550

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x93A1E0
#define CSidlManagerBase__CreatePageWnd_x                          0x9399E0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x935C60
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x935BF0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9574C0
#define CEQSuiteTextureLoader__GetTexture_x                        0x957180

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x5177F0
#define CFindItemWnd__WndNotification_x                            0x518430
#define CFindItemWnd__Update_x                                     0x518F80
#define CFindItemWnd__PickupSelectedItem_x                         0x517010

//IString
#define IString__Append_x                                          0x507C20

//Camera
#define CDisplay__cameraType_x                                     0xDECD00
#define EverQuest__Cameras_x                                       0xEA80A8

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x5204E0
#define LootFiltersManager__GetItemFilterData_x                    0x51FDE0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51FE10
#define LootFiltersManager__SetItemLootFilter_x                    0x520030

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BDF00

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x995330
#define CResolutionHandler__GetWindowedStyle_x                     0x698AF0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70DAD0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D4780
#define CDistillerInfo__Instance_x                                 0x8D4720

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72CA30
#define CGroupWnd__UpdateDisplay_x                                 0x72BD80

//ItemBase
#define ItemBase__IsLore_x                                         0x89E2D0
#define ItemBase__IsLoreEquipped_x                                 0x89E340

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EFAA0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EFBE0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EFC40

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68E420
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x691DB0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50DE50

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4FA290
#define FactionManagerClient__HandleFactionMessage_x               0x4FA900
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4FAF00
#define FactionManagerClient__GetMaxFaction_x                      0x4FAF1F
#define FactionManagerClient__GetMinFaction_x                      0x4FAED0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x5063C0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91E6C0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C250

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x506630

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56DAF0

//CTargetManager
#define CTargetManager__Get_x                                      0x6A4CB0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68E420

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A9100

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5C2810

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF4573C

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6C1730
#define CAAWnd__UpdateSelected_x                                   0x6BDFA0
#define CAAWnd__Update_x                                           0x6C0A50

//CXRect
#define CXRect__operator_and_x                                     0x723B00

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x4832B0

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
