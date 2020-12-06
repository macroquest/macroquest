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
#define __ExpectedVersionDate                                     "Dec  6 2020"
#define __ExpectedVersionTime                                     "04:16:42"
#define __ActualVersionDate_x                                      0xAF6560
#define __ActualVersionTime_x                                      0xAF6554
#define __ActualVersionBuild_x                                     0xAE458C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x643B90
#define __MemChecker1_x                                            0x8F7490
#define __MemChecker2_x                                            0x6B4510
#define __MemChecker3_x                                            0x6B4460
#define __MemChecker4_x                                            0x84D8E0
#define __EncryptPad0_x                                            0xC2C9C8
#define __EncryptPad1_x                                            0xC8A210
#define __EncryptPad2_x                                            0xC3CD90
#define __EncryptPad3_x                                            0xC3C990
#define __EncryptPad4_x                                            0xC7A7A0
#define __EncryptPad5_x                                            0xF4D108
#define __AC1_x                                                    0x80C126
#define __AC2_x                                                    0x5FD32F
#define __AC3_x                                                    0x604980
#define __AC4_x                                                    0x608930
#define __AC5_x                                                    0x60EC2F
#define __AC6_x                                                    0x6130E6
#define __AC7_x                                                    0x5FCDA0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x191310

// Direct Input
#define DI8__Main_x                                                0xF4A190
#define DI8__Keyboard_x                                            0xF4A194
#define DI8__Mouse_x                                               0xF4D0F4
#define DI8__Mouse_Copy_x                                          0xEA59EC
#define DI8__Mouse_Check_x                                         0xF4AC54
#define __AutoSkillArray_x                                         0xEA6908
#define __Attack_x                                                 0xF44737
#define __Autofire_x                                               0xF44738
#define __BindList_x                                               0xC1B400
#define g_eqCommandStates_x                                        0xC1C180
#define __Clicks_x                                                 0xEA5AA4
#define __CommandList_x                                            0xC1CD40
#define __CurrentMapLabel_x                                        0xF5D154
#define __CurrentSocial_x                                          0xC047D4
#define __DoAbilityList_x                                          0xEDC258
#define __do_loot_x                                                0x5C8D50
#define __DrawHandler_x                                            0x15DC148
#define __GroupCount_x                                             0xEA0512
#define __Guilds_x                                                 0xEA4928
#define __gWorld_x                                                 0xEA0CA8
#define __HWnd_x                                                   0xF4D0F8
#define __heqmain_x                                                0xF4D0E8
#define __InChatMode_x                                             0xEA59D4
#define __LastTell_x                                               0xEA7954
#define __LMouseHeldTime_x                                         0xEA5B10
#define __Mouse_x                                                  0xF4D114
#define __MouseLook_x                                              0xEA5A6A
#define __MouseEventTime_x                                         0xF4521C
#define __gpbCommandEvent_x                                        0xEA0768
#define __NetStatusToggle_x                                        0xEA5A6D
#define __PCNames_x                                                0xEA6F04
#define __RangeAttackReady_x                                       0xEA6BEC
#define __RMouseHeldTime_x                                         0xEA5B0C
#define __RunWalkState_x                                           0xEA59D8
#define __ScreenMode_x                                             0xDEC4E8
#define __ScreenX_x                                                0xEA598C
#define __ScreenY_x                                                0xEA5988
#define __ScreenXMax_x                                             0xEA5990
#define __ScreenYMax_x                                             0xEA5994
#define __ServerHost_x                                             0xEA0933
#define __ServerName_x                                             0xEDC218
#define __ShiftKeyDown_x                                           0xEA6068
#define __ShowNames_x                                              0xEA6DA8
#define EverQuestInfo__bSocialChanged_x                            0xEDC2A0
#define __Socials_x                                                0xEDC318
#define __SubscriptionType_x                                       0xFA1418
#define __TargetAggroHolder_x                                      0xF5FB08
#define __ZoneType_x                                               0xEA5E68
#define __GroupAggro_x                                             0xF5FB48
#define __LoginName_x                                              0xF4A8E4
#define __Inviter_x                                                0xF446B4
#define __AttackOnAssist_x                                         0xEA6D64
#define __UseTellWindows_x                                         0xEA709C
#define __gfMaxZoomCameraDistance_x                                0xAEE188
#define __gfMaxCameraDistance_x                                    0xB16DF0
#define __pulAutoRun_x                                             0xEA5A88
#define __pulForward_x                                             0xEA70D4
#define __pulBackward_x                                            0xEA70D8
#define __pulTurnRight_x                                           0xEA70DC
#define __pulTurnLeft_x                                            0xEA70E0
#define __pulStrafeLeft_x                                          0xEA70E4
#define __pulStrafeRight_x                                         0xEA70E8

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEA0CC0
#define instEQZoneInfo_x                                           0xEA5C60
#define pinstActiveBanker_x                                        0xEA0C54
#define pinstActiveCorpse_x                                        0xEA0C4C
#define pinstActiveGMaster_x                                       0xEA0C50
#define pinstActiveMerchant_x                                      0xEA0C48
#define pinstAltAdvManager_x                                       0xDECEF0
#define pinstBandageTarget_x                                       0xEA0C64
#define pinstCamActor_x                                            0xDEC4D4
#define pinstCDBStr_x                                              0xDEBC0C
#define pinstCDisplay_x                                            0xEA0CB4
#define pinstCEverQuest_x                                          0xF4A1AC
#define pinstEverQuestInfo_x                                       0xEA5980
#define pinstCharData_x                                            0xEA0754
#define pinstCharSpawn_x                                           0xEA0C9C
#define pinstControlledMissile_x                                   0xEA0CB0
#define pinstControlledPlayer_x                                    0xEA0C9C
#define pinstCResolutionHandler_x                                  0x15DC378
#define pinstCSidlManager_x                                        0x15DB310
#define pinstCXWndManager_x                                        0x15DB30C
#define instDynamicZone_x                                          0xEA4800
#define pinstDZMember_x                                            0xEA4910
#define pinstDZTimerInfo_x                                         0xEA4914
#define pinstEqLogin_x                                             0xF4A230
#define instEQMisc_x                                               0xDEBB50
#define pinstEQSoundManager_x                                      0xDEDEC0
#define pinstEQSpellStrings_x                                      0xCAE448
#define instExpeditionLeader_x                                     0xEA484A
#define instExpeditionName_x                                       0xEA488A
#define pinstGroup_x                                               0xEA050E
#define pinstImeManager_x                                          0x15DB308
#define pinstLocalPlayer_x                                         0xEA0C44
#define pinstMercenaryData_x                                       0xF46D14
#define pinstMercenaryStats_x                                      0xF5FBD4
#define pinstModelPlayer_x                                         0xEA0C5C
#define pinstPCData_x                                              0xEA0754
#define pinstSkillMgr_x                                            0xF48E70
#define pinstSpawnManager_x                                        0xF47918
#define pinstSpellManager_x                                        0xF490B0
#define pinstSpellSets_x                                           0xF3D360
#define pinstStringTable_x                                         0xEA0758
#define pinstSwitchManager_x                                       0xE9E260
#define pinstTarget_x                                              0xEA0C98
#define pinstTargetObject_x                                        0xEA0CA4
#define pinstTargetSwitch_x                                        0xEA03B0
#define pinstTaskMember_x                                          0xDEB9E0
#define pinstTrackTarget_x                                         0xEA0CA0
#define pinstTradeTarget_x                                         0xEA0C58
#define instTributeActive_x                                        0xDEBB71
#define pinstViewActor_x                                           0xDEC4D0
#define pinstWorldData_x                                           0xEA03B8
#define pinstZoneAddr_x                                            0xEA5F00
#define pinstPlayerPath_x                                          0xF479B0
#define pinstTargetIndicator_x                                     0xF49318
#define EQObject_Top_x                                             0xEA0A3C
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDEBF74
#define pinstCAchievementsWnd_x                                    0xDEC48C
#define pinstCActionsWnd_x                                         0xDEBFB0
#define pinstCAdvancedDisplayOptionsWindow_x                       0xDEBCAC
#define pinstCAdvancedLootWnd_x                                    0xDEC4FC
#define pinstCAdventureLeaderboardWnd_x                            0xF56928
#define pinstCAdventureRequestWnd_x                                0xF569D8
#define pinstCAdventureStatsWnd_x                                  0xF56A88
#define pinstCAggroMeterWnd_x                                      0xDEC530
#define pinstCAlarmWnd_x                                           0xDEC4B8
#define pinstCAlertHistoryWnd_x                                    0xDEBF24
#define pinstCAlertStackWnd_x                                      0xDEC518
#define pinstCAlertWnd_x                                           0xDEC52C
#define pinstCAltStorageWnd_x                                      0xF56DE8
#define pinstCAudioTriggersWindow_x                                0xCA0778
#define pinstCAuraWnd_x                                            0xDEC500
#define pinstCAvaZoneWnd_x                                         0xDEBF28
#define pinstCBandolierWnd_x                                       0xDEC544
#define pinstCBankWnd_x                                            0xDEBCE8
#define pinstCBarterMerchantWnd_x                                  0xF58028
#define pinstCBarterSearchWnd_x                                    0xF580D8
#define pinstCBarterWnd_x                                          0xF58188
#define pinstCBazaarConfirmationWnd_x                              0xDEC4C8
#define pinstCBazaarSearchWnd_x                                    0xDEBF78
#define pinstCBazaarWnd_x                                          0xDEC494
#define pinstCBlockedBuffWnd_x                                     0xDEC50C
#define pinstCBlockedPetBuffWnd_x                                  0xDEC534
#define pinstCBodyTintWnd_x                                        0xDEC43C
#define pinstCBookWnd_x                                            0xDEBCDC
#define pinstCBreathWnd_x                                          0xDEBF88
#define pinstCBuffWindowNORMAL_x                                   0xDEC4F4
#define pinstCBuffWindowSHORT_x                                    0xDEC4F8
#define pinstCBugReportWnd_x                                       0xDEBCE4
#define pinstCButtonWnd_x                                          0x15DB578
#define pinstCCastingWnd_x                                         0xDEBCD0
#define pinstCCastSpellWnd_x                                       0xDEBF84
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDEC448
#define pinstCChatWindowManager_x                                  0xF58C48
#define pinstCClaimWnd_x                                           0xF58DA0
#define pinstCColorPickerWnd_x                                     0xDEBF3C
#define pinstCCombatAbilityWnd_x                                   0xDEC4A4
#define pinstCCombatSkillsSelectWnd_x                              0xDEC45C
#define pinstCCompassWnd_x                                         0xDEBFB4
#define pinstCConfirmationDialog_x                                 0xF5DCA0
#define pinstCContainerMgr_x                                       0xDEC438
#define pinstCContextMenuManager_x                                 0x15DB2C8
#define pinstCCursorAttachment_x                                   0xDEBCB8
#define pinstCDynamicZoneWnd_x                                     0xF59368
#define pinstCEditLabelWnd_x                                       0xDEC4E0
#define pinstCEQMainWnd_x                                          0xF595B0
#define pinstCEventCalendarWnd_x                                   0xDEBF7C
#define pinstCExtendedTargetWnd_x                                  0xDEC510
#define pinstCPlayerCustomizationWnd_x                             0xDEC460
#define pinstCFactionWnd_x                                         0xDEC480
#define pinstCFellowshipWnd_x                                      0xF597B0
#define pinstCFileSelectionWnd_x                                   0xDEBF38
#define pinstCFindItemWnd_x                                        0xDEC474
#define pinstCFindLocationWnd_x                                    0xF59908
#define pinstCFriendsWnd_x                                         0xDEC470
#define pinstCGemsGameWnd_x                                        0xDEC47C
#define pinstCGiveWnd_x                                            0xDEC4BC
#define pinstCGroupSearchFiltersWnd_x                              0xDEBCA8
#define pinstCGroupSearchWnd_x                                     0xF59D00
#define pinstCGroupWnd_x                                           0xF59DB0
#define pinstCGuildBankWnd_x                                       0xF59E60
#define pinstCGuildCreationWnd_x                                   0xF59F10
#define pinstCGuildMgmtWnd_x                                       0xF59FC0
#define pinstCharacterCreation_x                                   0xDEC468
#define pinstCHelpWnd_x                                            0xDEC4B4
#define pinstCHeritageSelectionWnd_x                               0xDEC46C
#define pinstCHotButtonWnd_x                                       0xF5C118
#define pinstCHotButtonWnd1_x                                      0xF5C118
#define pinstCHotButtonWnd2_x                                      0xF5C11C
#define pinstCHotButtonWnd3_x                                      0xF5C120
#define pinstCHotButtonWnd4_x                                      0xF5C124
#define pinstCIconSelectionWnd_x                                   0xDEBCB4
#define pinstCInspectWnd_x                                         0xDEC538
#define pinstCInventoryWnd_x                                       0xDEC504
#define pinstCInvSlotMgr_x                                         0xDEBF68
#define pinstCItemDisplayManager_x                                 0xF5C6A8
#define pinstCItemExpTransferWnd_x                                 0xF5C7D8
#define pinstCItemOverflowWnd_x                                    0xDEBF80
#define pinstCJournalCatWnd_x                                      0xDEBF54
#define pinstCJournalNPCWnd_x                                      0xDEBF14
#define pinstCJournalTextWnd_x                                     0xDEBF14
#define pinstCKeyRingWnd_x                                         0xDEBCCC
#define pinstCLargeDialogWnd_x                                     0xF5E920
#define pinstCLayoutCopyWnd_x                                      0xF5CB28
#define pinstCLFGuildWnd_x                                         0xF5CBD8
#define pinstCLoadskinWnd_x                                        0xDEC498
#define pinstCLootFiltersCopyWnd_x                                 0xCBCEE8
#define pinstCLootFiltersWnd_x                                     0xDEC51C
#define pinstCLootSettingsWnd_x                                    0xDEC540
#define pinstCLootWnd_x                                            0xDEBF58
#define pinstCMailAddressBookWnd_x                                 0xDEBF6C
#define pinstCMailCompositionWnd_x                                 0xDEBF44
#define pinstCMailIgnoreListWnd_x                                  0xDEBF70
#define pinstCMailWnd_x                                            0xDEBF30
#define pinstCManageLootWnd_x                                      0xDED3A0
#define pinstCMapToolbarWnd_x                                      0xDEC4C0
#define pinstCMapViewWnd_x                                         0xDEC488
#define pinstCMarketplaceWnd_x                                     0xDEC520
#define pinstCMerchantWnd_x                                        0xDEBF64
#define pinstCMIZoneSelectWnd_x                                    0xF5D410
#define pinstCMusicPlayerWnd_x                                     0xDEBD04
#define pinstCNameChangeMercWnd_x                                  0xDEC4C4
#define pinstCNameChangePetWnd_x                                   0xDEC490
#define pinstCNameChangeWnd_x                                      0xDEC4D8
#define pinstCNoteWnd_x                                            0xDEC49C
#define pinstCObjectPreviewWnd_x                                   0xDEC53C
#define pinstCOptionsWnd_x                                         0xDEC4AC
#define pinstCPetInfoWnd_x                                         0xDEBF2C
#define pinstCPetitionQWnd_x                                       0xDEC458
#define pinstCPlayerNotesWnd_x                                     0xDEC440
#define pinstCPlayerWnd_x                                          0xDEBF20
#define pinstCPopupWndManager_x                                    0xF5DCA0
#define pinstCProgressionSelectionWnd_x                            0xF5DD50
#define pinstCPurchaseGroupWnd_x                                   0xDEBCF8
#define pinstCPurchaseWnd_x                                        0xDEBCD4
#define pinstCPvPLeaderboardWnd_x                                  0xF5DE00
#define pinstCPvPStatsWnd_x                                        0xF5DEB0
#define pinstCQuantityWnd_x                                        0xDEBF10
#define pinstCRaceChangeWnd_x                                      0xDEC508
#define pinstCRaidOptionsWnd_x                                     0xDEBCB0
#define pinstCRaidWnd_x                                            0xDEBF60
#define pinstCRealEstateItemsWnd_x                                 0xDEC484
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDEC030
#define pinstCRealEstateManageWnd_x                                0xDEBCFC
#define pinstCRealEstateNeighborhoodWnd_x                          0xDEBF1C
#define pinstCRealEstatePlotSearchWnd_x                            0xDEBF34
#define pinstCRealEstatePurchaseWnd_x                              0xDEBF50
#define pinstCRespawnWnd_x                                         0xDEC528
#define pinstCRewardSelectionWnd_x                                 0xF5E5F8
#define pinstCSelectorWnd_x                                        0xDEC454
#define pinstCSendMoneyWnd_x                                       0xDEC4CC
#define pinstCServerListWnd_x                                      0xDEBF5C
#define pinstCSkillsSelectWnd_x                                    0xDEC450
#define pinstCSkillsWnd_x                                          0xDEC02C
#define pinstCSocialEditWnd_x                                      0xDEBCC4
#define pinstCSocialWnd_x                                          0xDEC4B0
#define pinstCSpellBookWnd_x                                       0xDEC4A0
#define pinstCStoryWnd_x                                           0xDEBFAC
#define pinstCTargetOfTargetWnd_x                                  0xF5FC58
#define pinstCTargetWnd_x                                          0xDEC524
#define pinstCTaskOverlayWnd_x                                     0xDEBCEC
#define pinstCTaskSelectWnd_x                                      0xF5FDB0
#define pinstCTaskManager_x                                        0xCBD828
#define pinstCTaskTemplateSelectWnd_x                              0xF5FE60
#define pinstCTaskWnd_x                                            0xF5FF10
#define pinstCTextEntryWnd_x                                       0xDEBCD8
#define pinstCTimeLeftWnd_x                                        0xDEC44C
#define pinstCTipWndCONTEXT_x                                      0xF60114
#define pinstCTipWndOFDAY_x                                        0xF60110
#define pinstCTitleWnd_x                                           0xF601C0
#define pinstCTrackingWnd_x                                        0xDEC514
#define pinstCTradeskillWnd_x                                      0xF60328
#define pinstCTradeWnd_x                                           0xDEC444
#define pinstCTrainWnd_x                                           0xDEBF48
#define pinstCTributeBenefitWnd_x                                  0xF60528
#define pinstCTributeMasterWnd_x                                   0xF605D8
#define pinstCTributeTrophyWnd_x                                   0xF60688
#define pinstCVideoModesWnd_x                                      0xDEBCF0
#define pinstCVoiceMacroWnd_x                                      0xF498D0
#define pinstCVoteResultsWnd_x                                     0xDEC478
#define pinstCVoteWnd_x                                            0xDEC464
#define pinstCWebManager_x                                         0xF49F4C
#define pinstCZoneGuideWnd_x                                       0xDEBCF4
#define pinstCZonePathWnd_x                                        0xDEBF08

#define pinstEQSuiteTextureLoader_x                                0xC8AB30
#define pinstItemIconCache_x                                       0xF59568
#define pinstLootFiltersManager_x                                  0xCBCF98
#define pinstRewardSelectionWnd_x                                  0xF5E5F8

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5C4440
#define __CastRay2_x                                               0x5C4490
#define __ConvertItemTags_x                                        0x5E0160
#define __CleanItemTags_x                                          0x47D240
#define __DoesFileExist_x                                          0x8FA4C0
#define __EQGetTime_x                                              0x8F70C0
#define __ExecuteCmd_x                                             0x5BCDD0
#define __FixHeading_x                                             0x98CC20
#define __FlushDxKeyboard_x                                        0x6B03B0
#define __GameLoop_x                                               0x6B36E0
#define __get_bearing_x                                            0x5C3FA0
#define __get_melee_range_x                                        0x5C4680
#define __GetAnimationCache_x                                      0x718C70
#define __GetGaugeValueFromEQ_x                                    0x80A5D0
#define __GetLabelFromEQ_x                                         0x80C0B0
#define __GetXTargetType_x                                         0x98E670
#define __HandleMouseWheel_x                                       0x6B45C0
#define __HeadingDiff_x                                            0x98CC90
#define __HelpPath_x                                               0xF44E0C
#define __LoadFrontEnd_x                                           0x6B09F0
#define __NewUIINI_x                                               0x80A2A0
#define __ProcessGameEvents_x                                      0x624FC0
#define __ProcessMouseEvent_x                                      0x624750
#define __SaveColors_x                                             0x55D9B0
#define __STMLToText_x                                             0x92FEE0
#define __ToggleKeyRingItem_x                                      0x51C1F0
#define CMemoryMappedFile__SetFile_x                               0xA7C030
#define CrashDetected_x                                            0x6B24A0
#define DrawNetStatus_x                                            0x6511A0
#define Expansion_HoT_x                                            0xEA6D50
#define Teleport_Table_Size_x                                      0xEA07F0
#define Teleport_Table_x                                           0xE9E3B0
#define Util__FastTime_x                                           0x8F6C90
#define __CopyLayout_x                                             0x63F240
#define __WndProc_x                                                0x6B29A0
#define __ProcessKeyboardEvent_x                                   0x6B1F40

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490550
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499550
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499320
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493AF0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492F40

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x565BC0
#define AltAdvManager__IsAbilityReady_x                            0x564960
#define AltAdvManager__GetAAById_x                                 0x564CF0
#define AltAdvManager__CanTrainAbility_x                           0x564D60
#define AltAdvManager__CanSeeAbility_x                             0x5650C0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CB190
#define CharacterZoneClient__HasSkill_x                            0x4D6010
#define CharacterZoneClient__MakeMeVisible_x                       0x4D7740
#define CharacterZoneClient__IsStackBlocked_x                      0x4C2880
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBD10
#define CharacterZoneClient__GetItemCountWorn_x                    0x4DA0D0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4DA1B0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4DA290
#define CharacterZoneClient__FindAffectSlot_x                      0x4C4970
#define CharacterZoneClient__BardCastBard_x                        0x4C73A0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF720
#define CharacterZoneClient__GetEffect_x                           0x4BBC50
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C59E0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C5AB0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C5B00
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5C50
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5E30
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3C30
#define CharacterZoneClient__FindItemByGuid_x                      0x4D86A0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D8120

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6DA200
#define CBankWnd__WndNotification_x                                0x6D9FD0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E7B10

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x92D6C0
#define CButtonWnd__CButtonWnd_x                                   0x92C2C0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x707D50
#define CChatManager__InitContextMenu_x                            0x700E80
#define CChatManager__FreeChatWindow_x                             0x706890
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9BD0
#define CChatManager__SetLockedActiveChatWindow_x                  0x7079D0
#define CChatManager__CreateChatWindow_x                           0x706ED0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9CE0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x9408E0
#define CContextMenu__dCContextMenu_x                              0x940B20
#define CContextMenu__AddMenuItem_x                                0x940B30
#define CContextMenu__RemoveMenuItem_x                             0x940E40
#define CContextMenu__RemoveAllMenuItems_x                         0x940E60
#define CContextMenu__CheckMenuItem_x                              0x940EE0
#define CContextMenu__SetMenuItem_x                                0x940D60
#define CContextMenu__AddSeparator_x                               0x940CC0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x941480
#define CContextMenuManager__RemoveMenu_x                          0x9414F0
#define CContextMenuManager__PopupMenu_x                           0x9415B0
#define CContextMenuManager__Flush_x                               0x941420
#define CContextMenuManager__GetMenu_x                             0x49B7D0
#define CContextMenuManager__CreateDefaultMenu_x                   0x713520

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D1E30
#define CChatService__GetFriendName_x                              0x8D1E40

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x708580
#define CChatWindow__Clear_x                                       0x709850
#define CChatWindow__WndNotification_x                             0x709FE0
#define CChatWindow__AddHistory_x                                  0x709110

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93DD40
#define CComboWnd__Draw_x                                          0x93D230
#define CComboWnd__GetCurChoice_x                                  0x93DB80
#define CComboWnd__GetListRect_x                                   0x93D6E0
#define CComboWnd__GetTextRect_x                                   0x93DDB0
#define CComboWnd__InsertChoice_x                                  0x93D870
#define CComboWnd__SetColors_x                                     0x93D840
#define CComboWnd__SetChoice_x                                     0x93DB50
#define CComboWnd__GetItemCount_x                                  0x93DB90
#define CComboWnd__GetCurChoiceText_x                              0x93DBD0
#define CComboWnd__GetChoiceText_x                                 0x93DBA0
#define CComboWnd__InsertChoiceAtIndex_x                           0x93D910

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x710F30
#define CContainerWnd__vftable_x                                   0xAFF754
#define CContainerWnd__SetContainer_x                              0x712480

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x558310
#define CDisplay__PreZoneMainUI_x                                  0x558320
#define CDisplay__CleanGameUI_x                                    0x55D770
#define CDisplay__GetClickedActor_x                                0x550770
#define CDisplay__GetUserDefinedColor_x                            0x548DE0
#define CDisplay__GetWorldFilePath_x                               0x5521E0
#define CDisplay__is3dON_x                                         0x54D3D0
#define CDisplay__ReloadUI_x                                       0x557820
#define CDisplay__WriteTextHD2_x                                   0x54D1C0
#define CDisplay__TrueDistance_x                                   0x553EA0
#define CDisplay__SetViewActor_x                                   0x550090
#define CDisplay__GetFloorHeight_x                                 0x54D490
#define CDisplay__SetRenderWindow_x                                0x54BE10
#define CDisplay__ToggleScreenshotMode_x                           0x54FB60

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x960840

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x943DE0
#define CEditWnd__EnsureCaretVisible_x                             0x945FB0
#define CEditWnd__GetCaretPt_x                                     0x944F60
#define CEditWnd__GetCharIndexPt_x                                 0x944D10
#define CEditWnd__GetDisplayString_x                               0x944BB0
#define CEditWnd__GetHorzOffset_x                                  0x943480
#define CEditWnd__GetLineForPrintableChar_x                        0x945EB0
#define CEditWnd__GetSelStartPt_x                                  0x944FC0
#define CEditWnd__GetSTMLSafeText_x                                0x9449D0
#define CEditWnd__PointFromPrintableChar_x                         0x945AE0
#define CEditWnd__SelectableCharFromPoint_x                        0x945C50
#define CEditWnd__SetEditable_x                                    0x945090
#define CEditWnd__SetWindowTextA_x                                 0x944750
#define CEditWnd__ReplaceSelection_x                               0x945750
#define CEditWnd__ReplaceSelection1_x                              0x9456D0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x6125C0
#define CEverQuest__ClickedPlayer_x                                0x604760
#define CEverQuest__CreateTargetIndicator_x                        0x622130
#define CEverQuest__DeleteTargetIndicator_x                        0x6221C0
#define CEverQuest__DoTellWindow_x                                 0x4E9DC0
#define CEverQuest__OutputTextToLog_x                              0x4EA090
#define CEverQuest__DropHeldItemOnGround_x                         0x5F98B0
#define CEverQuest__dsp_chat_x                                     0x4EA420
#define CEverQuest__trimName_x                                     0x61E2E0
#define CEverQuest__Emote_x                                        0x612E20
#define CEverQuest__EnterZone_x                                    0x60CF20
#define CEverQuest__GetBodyTypeDesc_x                              0x617870
#define CEverQuest__GetClassDesc_x                                 0x617EB0
#define CEverQuest__GetClassThreeLetterCode_x                      0x6184B0
#define CEverQuest__GetDeityDesc_x                                 0x620980
#define CEverQuest__GetLangDesc_x                                  0x618670
#define CEverQuest__GetRaceDesc_x                                  0x617E90
#define CEverQuest__InterpretCmd_x                                 0x620F50
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FDA50
#define CEverQuest__LMouseUp_x                                     0x5FBDD0
#define CEverQuest__RightClickedOnPlayer_x                         0x5FE330
#define CEverQuest__RMouseUp_x                                     0x5FCD60
#define CEverQuest__SetGameState_x                                 0x5F9640
#define CEverQuest__UPCNotificationFlush_x                         0x61E1E0
#define CEverQuest__IssuePetCommand_x                              0x619A80
#define CEverQuest__ReportSuccessfulHit_x                          0x614170

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x722BC0
#define CGaugeWnd__CalcLinesFillRect_x                             0x722C20
#define CGaugeWnd__Draw_x                                          0x722240

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AFFA0
#define CGuild__GetGuildName_x                                     0x4AEA50
#define CGuild__GetGuildIndex_x                                    0x4AF050

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73C840

//CHotButton
#define CHotButton__SetCheck_x                                     0x6337A0
#define CHotButton__SetButtonSize_x                                0x633B60

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x749A10
#define CInvSlotMgr__MoveItem_x                                    0x748730
#define CInvSlotMgr__SelectSlot_x                                  0x749AE0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x746F60
#define CInvSlot__SliderComplete_x                                 0x744CA0
#define CInvSlot__GetItemBase_x                                    0x744640
#define CInvSlot__UpdateItem_x                                     0x7447B0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x74B560
#define CInvSlotWnd__CInvSlotWnd_x                                 0x74A700
#define CInvSlotWnd__HandleLButtonUp_x                             0x74B0E0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x805940
#define CItemDisplayWnd__UpdateStrings_x                           0x759C40
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x7539B0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x753EB0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x75A250
#define CItemDisplayWnd__AboutToShow_x                             0x759880
#define CItemDisplayWnd__WndNotification_x                         0x75B4B0
#define CItemDisplayWnd__RequestConvertItem_x                      0x75ADF0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x7588E0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x7596A0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8363D0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75F9E0

// CLabel 
#define CLabel__Draw_x                                             0x765410

// CListWnd
#define CListWnd__CListWnd_x                                       0x916530
#define CListWnd__dCListWnd_x                                      0x916850
#define CListWnd__AddColumn_x                                      0x91ACE0
#define CListWnd__AddColumn1_x                                     0x91AD30
#define CListWnd__AddLine_x                                        0x91B0C0
#define CListWnd__AddString_x                                      0x91AEC0
#define CListWnd__CalculateFirstVisibleLine_x                      0x91AAA0
#define CListWnd__CalculateVSBRange_x                              0x91A880
#define CListWnd__ClearSel_x                                       0x91B8A0
#define CListWnd__ClearAllSel_x                                    0x91B900
#define CListWnd__CloseAndUpdateEditWindow_x                       0x91C320
#define CListWnd__Compare_x                                        0x91A1B0
#define CListWnd__Draw_x                                           0x916980
#define CListWnd__DrawColumnSeparators_x                           0x919180
#define CListWnd__DrawHeader_x                                     0x9195F0
#define CListWnd__DrawItem_x                                       0x919AF0
#define CListWnd__DrawLine_x                                       0x9192F0
#define CListWnd__DrawSeparator_x                                  0x919220
#define CListWnd__EnableLine_x                                     0x918A50
#define CListWnd__EnsureVisible_x                                  0x91C240
#define CListWnd__ExtendSel_x                                      0x91B7D0
#define CListWnd__GetColumnTooltip_x                               0x918590
#define CListWnd__GetColumnMinWidth_x                              0x918600
#define CListWnd__GetColumnWidth_x                                 0x918500
#define CListWnd__GetCurSel_x                                      0x917E90
#define CListWnd__GetItemAtPoint_x                                 0x918CD0
#define CListWnd__GetItemAtPoint1_x                                0x918D40
#define CListWnd__GetItemData_x                                    0x917F10
#define CListWnd__GetItemHeight_x                                  0x9182D0
#define CListWnd__GetItemIcon_x                                    0x9180A0
#define CListWnd__GetItemRect_x                                    0x918B40
#define CListWnd__GetItemText_x                                    0x917F50
#define CListWnd__GetSelList_x                                     0x91B950
#define CListWnd__GetSeparatorRect_x                               0x918F80
#define CListWnd__InsertLine_x                                     0x91B4B0
#define CListWnd__RemoveLine_x                                     0x91B600
#define CListWnd__SetColors_x                                      0x91A850
#define CListWnd__SetColumnJustification_x                         0x91A580
#define CListWnd__SetColumnLabel_x                                 0x91AE60
#define CListWnd__SetColumnWidth_x                                 0x91A4A0
#define CListWnd__SetCurSel_x                                      0x91B710
#define CListWnd__SetItemColor_x                                   0x91BEF0
#define CListWnd__SetItemData_x                                    0x91BEB0
#define CListWnd__SetItemText_x                                    0x91BAC0
#define CListWnd__ShiftColumnSeparator_x                           0x91A640
#define CListWnd__Sort_x                                           0x91A330
#define CListWnd__ToggleSel_x                                      0x91B740
#define CListWnd__SetColumnsSizable_x                              0x91A6F0
#define CListWnd__SetItemWnd_x                                     0x91BD70
#define CListWnd__GetItemWnd_x                                     0x9180F0
#define CListWnd__SetItemIcon_x                                    0x91BB40
#define CListWnd__CalculateCustomWindowPositions_x                 0x91ABA0
#define CListWnd__SetVScrollPos_x                                  0x91A480

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x77ABA0
#define CMapViewWnd__GetWorldCoordinates_x                         0x7792B0
#define CMapViewWnd__HandleLButtonDown_x                           0x7762F0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x79B060
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79B940
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79BE70
#define CMerchantWnd__SelectRecoverySlot_x                         0x79EE10
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x799BD0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A49E0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x79AC70

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89F730
#define CPacketScrambler__hton_x                                   0x89F720

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x9354D0
#define CSidlManager__FindScreenPieceTemplate_x                    0x9358E0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9356D0
#define CSidlManager__CreateLabel_x                                0x7FCB80
#define CSidlManager__CreateXWndFromTemplate_x                     0x938840
#define CSidlManager__CreateXWndFromTemplate1_x                    0x938A20
#define CSidlManager__CreateXWnd_x                                 0x7FCAB0
#define CSidlManager__CreateHotButtonWnd_x                         0x7FD080

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x931FB0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x931EB0
#define CSidlScreenWnd__ConvertToRes_x                             0x95B390
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x9319A0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x931690
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x931760
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x931830
#define CSidlScreenWnd__DrawSidlPiece_x                            0x932450
#define CSidlScreenWnd__EnableIniStorage_x                         0x932920
#define CSidlScreenWnd__GetSidlPiece_x                             0x932640
#define CSidlScreenWnd__Init1_x                                    0x931290
#define CSidlScreenWnd__LoadIniInfo_x                              0x932970
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9334B0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x930690
#define CSidlScreenWnd__StoreIniInfo_x                             0x933030
#define CSidlScreenWnd__StoreIniVis_x                              0x933390
#define CSidlScreenWnd__WndNotification_x                          0x932360
#define CSidlScreenWnd__GetChildItem_x                             0x9328A0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9220F0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15DB198

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6993E0
#define CSkillMgr__GetSkillCap_x                                   0x6995C0
#define CSkillMgr__GetNameToken_x                                  0x698B60
#define CSkillMgr__IsActivatedSkill_x                              0x698CA0
#define CSkillMgr__IsCombatSkill_x                                 0x698BE0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x942250
#define CSliderWnd__SetValue_x                                     0x9420C0
#define CSliderWnd__SetNumTicks_x                                  0x942120

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x802CD0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x94ABA0
#define CStmlWnd__ParseSTML_x                                      0x94BEB0
#define CStmlWnd__CalculateHSBRange_x                              0x94BC80
#define CStmlWnd__CalculateVSBRange_x                              0x94BBF0
#define CStmlWnd__CanBreakAtCharacter_x                            0x94FFC0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x950C50
#define CStmlWnd__ForceParseNow_x                                  0x94B140
#define CStmlWnd__GetNextTagPiece_x                                0x94FF20
#define CStmlWnd__GetSTMLText_x                                    0x50D810
#define CStmlWnd__GetVisibleText_x                                 0x94B160
#define CStmlWnd__InitializeWindowVariables_x                      0x950AA0
#define CStmlWnd__MakeStmlColorTag_x                               0x94A210
#define CStmlWnd__MakeWndNotificationTag_x                         0x94A280
#define CStmlWnd__SetSTMLText_x                                    0x9492C0
#define CStmlWnd__StripFirstSTMLLines_x                            0x951D50
#define CStmlWnd__UpdateHistoryString_x                            0x950E60

// CTabWnd 
#define CTabWnd__Draw_x                                            0x948410
#define CTabWnd__DrawCurrentPage_x                                 0x948B40
#define CTabWnd__DrawTab_x                                         0x948860
#define CTabWnd__GetCurrentPage_x                                  0x947C10
#define CTabWnd__GetPageInnerRect_x                                0x947E50
#define CTabWnd__GetTabInnerRect_x                                 0x947D90
#define CTabWnd__GetTabRect_x                                      0x947C40
#define CTabWnd__InsertPage_x                                      0x948060
#define CTabWnd__RemovePage_x                                      0x9481D0
#define CTabWnd__SetPage_x                                         0x947ED0
#define CTabWnd__SetPageRect_x                                     0x948350
#define CTabWnd__UpdatePage_x                                      0x948720
#define CTabWnd__GetPageFromTabIndex_x                             0x9487A0
#define CTabWnd__GetCurrentTabIndex_x                              0x947C00

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x75FE10
#define CPageWnd__SetTabText_x                                     0x947760
#define CPageWnd__FlashTab_x                                       0x9477C0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A92F0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91EF70
#define CTextureFont__GetTextExtent_x                              0x91F130

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AD550
#define CHtmlComponentWnd__ValidateUri_x                           0x73E230
#define CHtmlWnd__SetClientCallbacks_x                             0x638C00
#define CHtmlWnd__AddObserver_x                                    0x638C20
#define CHtmlWnd__RemoveObserver_x                                 0x638C80
#define Window__getProgress_x                                      0x854F10
#define Window__getStatus_x                                        0x854F30
#define Window__getURI_x                                           0x854F40

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9581A0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x90C000

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9A10
#define CXStr__CXStr1_x                                            0x481740
#define CXStr__CXStr3_x                                            0x8F3030
#define CXStr__dCXStr_x                                            0x478390
#define CXStr__operator_equal_x                                    0x8F3260
#define CXStr__operator_equal1_x                                   0x8F32A0
#define CXStr__operator_plus_equal1_x                              0x8F3D30
#define CXStr__SetString_x                                         0x8F5C30
#define CXStr__operator_char_p_x                                   0x8F37A0
#define CXStr__GetChar_x                                           0x8F5580
#define CXStr__Delete_x                                            0x8F4E30
#define CXStr__GetUnicode_x                                        0x8F55F0
#define CXStr__GetLength_x                                         0x4A90A0
#define CXStr__Mid_x                                               0x47D5F0
#define CXStr__Insert_x                                            0x8F5650
#define CXStr__FindNext_x                                          0x8F52A0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x940500
#define CXWnd__BringToTop_x                                        0x925900
#define CXWnd__Center_x                                            0x925480
#define CXWnd__ClrFocus_x                                          0x9252A0
#define CXWnd__Destroy_x                                           0x925340
#define CXWnd__DoAllDrawing_x                                      0x921880
#define CXWnd__DrawChildren_x                                      0x921850
#define CXWnd__DrawColoredRect_x                                   0x921CE0
#define CXWnd__DrawTooltip_x                                       0x920390
#define CXWnd__DrawTooltipAtPoint_x                                0x920450
#define CXWnd__GetBorderFrame_x                                    0x921B40
#define CXWnd__GetChildWndAt_x                                     0x9259A0
#define CXWnd__GetClientClipRect_x                                 0x923B20
#define CXWnd__GetScreenClipRect_x                                 0x923BF0
#define CXWnd__GetScreenRect_x                                     0x923DA0
#define CXWnd__GetRelativeRect_x                                   0x923E70
#define CXWnd__GetTooltipRect_x                                    0x921D30
#define CXWnd__GetWindowTextA_x                                    0x49CEC0
#define CXWnd__IsActive_x                                          0x922470
#define CXWnd__IsDescendantOf_x                                    0x9247C0
#define CXWnd__IsReallyVisible_x                                   0x9247F0
#define CXWnd__IsType_x                                            0x926020
#define CXWnd__Move_x                                              0x924860
#define CXWnd__Move1_x                                             0x924910
#define CXWnd__ProcessTransition_x                                 0x925430
#define CXWnd__Refade_x                                            0x924BF0
#define CXWnd__Resize_x                                            0x924EC0
#define CXWnd__Right_x                                             0x9256C0
#define CXWnd__SetFocus_x                                          0x925260
#define CXWnd__SetFont_x                                           0x9252D0
#define CXWnd__SetKeyTooltip_x                                     0x925E30
#define CXWnd__SetMouseOver_x                                      0x922CA0
#define CXWnd__StartFade_x                                         0x9246A0
#define CXWnd__GetChildItem_x                                      0x925B10
#define CXWnd__SetParent_x                                         0x924560
#define CXWnd__Minimize_x                                          0x924F30

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x95C410

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x928830
#define CXWndManager__DrawWindows_x                                0x928850
#define CXWndManager__GetKeyboardFlags_x                           0x92AF70
#define CXWndManager__HandleKeyboardMsg_x                          0x92AB20
#define CXWndManager__RemoveWnd_x                                  0x92B190
#define CXWndManager__RemovePendingDeletionWnd_x                   0x92B700

// CDBStr
#define CDBStr__GetString_x                                        0x547DA0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BFE80
#define EQ_Character__Cur_HP_x                                     0x4D3050
#define EQ_Character__Cur_Mana_x                                   0x4DA790
#define EQ_Character__GetCastingTimeModifier_x                     0x4C2EF0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B3870
#define EQ_Character__GetFocusRangeModifier_x                      0x4B39C0
#define EQ_Character__GetHPRegen_x                                 0x4E0690
#define EQ_Character__GetEnduranceRegen_x                          0x4E0C90
#define EQ_Character__GetManaRegen_x                               0x4E10D0
#define EQ_Character__Max_Endurance_x                              0x65F900
#define EQ_Character__Max_HP_x                                     0x4D2E80
#define EQ_Character__Max_Mana_x                                   0x65F700
#define EQ_Character__doCombatAbility_x                            0x661CF0
#define EQ_Character__UseSkill_x                                   0x4E2ED0
#define EQ_Character__GetConLevel_x                                0x658100
#define EQ_Character__IsExpansionFlag_x                            0x5BB580
#define EQ_Character__TotalEffect_x                                0x4C6C90
#define EQ_Character__GetPCSpellAffect_x                           0x4C3C40
#define EQ_Character__SpellDuration_x                              0x4C3770
#define EQ_Character__MySpellDuration_x                            0x4B21A0
#define EQ_Character__GetAdjustedSkill_x                           0x4D5DD0
#define EQ_Character__GetBaseSkill_x                               0x4D6D70
#define EQ_Character__CanUseItem_x                                 0x4DAAA0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BEC70

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x675C40

//PcClient
#define PcClient__vftable_x                                        0xAF31DC
#define PcClient__PcClient_x                                       0x655870

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA8F0
#define CCharacterListWnd__EnterWorld_x                            0x4BA2C0
#define CCharacterListWnd__Quit_x                                  0x4BA010
#define CCharacterListWnd__UpdateList_x                            0x4BA4B0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x639DC0
#define EQ_Item__CreateItemTagString_x                             0x898BE0
#define EQ_Item__IsStackable_x                                     0x89D930
#define EQ_Item__GetImageNum_x                                     0x89A780
#define EQ_Item__CreateItemClient_x                                0x639000
#define EQ_Item__GetItemValue_x                                    0x89BA90
#define EQ_Item__ValueSellMerchant_x                               0x89F310
#define EQ_Item__IsKeyRingItem_x                                   0x89D1E0
#define EQ_Item__CanGoInBag_x                                      0x639EE0
#define EQ_Item__IsEmpty_x                                         0x89CD20
#define EQ_Item__GetMaxItemCount_x                                 0x89BEA0
#define EQ_Item__GetHeldItem_x                                     0x89A650
#define EQ_Item__GetAugmentFitBySlot_x                             0x898430

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x566890
#define EQ_LoadingS__Array_x                                       0xC14130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x660200
#define EQ_PC__GetAlternateAbilityId_x                             0x8A8610
#define EQ_PC__GetCombatAbility_x                                  0x8A8C80
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A8CF0
#define EQ_PC__GetItemRecastTimer_x                                0x662270
#define EQ_PC__HasLoreItem_x                                       0x658970
#define EQ_PC__AlertInventoryChanged_x                             0x657A40
#define EQ_PC__GetPcZoneClient_x                                   0x684BF0
#define EQ_PC__RemoveMyAffect_x                                    0x665490
#define EQ_PC__GetKeyRingItems_x                                   0x8A95C0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A9340
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A98C0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5C19D0
#define EQItemList__add_object_x                                   0x5EF060
#define EQItemList__add_item_x                                     0x5C1F30
#define EQItemList__delete_item_x                                  0x5C1F80
#define EQItemList__FreeItemList_x                                 0x5C1E80

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x544960

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x677540
#define EQPlayer__dEQPlayer_x                                      0x66A8C0
#define EQPlayer__DoAttack_x                                       0x67F390
#define EQPlayer__EQPlayer_x                                       0x66AF80
#define EQPlayer__SetNameSpriteState_x                             0x66F250
#define EQPlayer__SetNameSpriteTint_x                              0x670130
#define PlayerBase__HasProperty_j_x                                0x98B030
#define EQPlayer__IsTargetable_x                                   0x98B4D0
#define EQPlayer__CanSee_x                                         0x98B330
#define EQPlayer__CanSee1_x                                        0x98B400
#define PlayerBase__GetVisibilityLineSegment_x                     0x98B0F0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x682690
#define PlayerZoneClient__GetLevel_x                               0x684C30
#define PlayerZoneClient__IsValidTeleport_x                        0x5F01D0
#define PlayerZoneClient__LegalPlayerRace_x                        0x55F600

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x67A290
#define EQPlayerManager__GetSpawnByName_x                          0x67A340
#define EQPlayerManager__GetPlayerFromPartialName_x                0x67A3D0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63D4A0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63D520
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63D560
#define KeypressHandler__ClearCommandStateArray_x                  0x63E950
#define KeypressHandler__HandleKeyDown_x                           0x63E970
#define KeypressHandler__HandleKeyUp_x                             0x63EA10
#define KeypressHandler__SaveKeymapping_x                          0x63EE60

// MapViewMap 
#define MapViewMap__Clear_x                                        0x776A10
#define MapViewMap__SaveEx_x                                       0x779DD0
#define MapViewMap__SetZoom_x                                      0x77E490

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BCC20

// StringTable 
#define StringTable__getString_x                                   0x8B7AD0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x665100
#define PcZoneClient__RemovePetEffect_x                            0x665730
#define PcZoneClient__HasAlternateAbility_x                        0x65F530
#define PcZoneClient__GetCurrentMod_x                              0x4E5FF0
#define PcZoneClient__GetModCap_x                                  0x4E5EF0
#define PcZoneClient__CanEquipItem_x                               0x65FBE0
#define PcZoneClient__GetItemByID_x                                0x6626E0
#define PcZoneClient__GetItemByItemClass_x                         0x662830
#define PcZoneClient__RemoveBuffEffect_x                           0x665750
#define PcZoneClient__BandolierSwap_x                              0x6607C0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x662210

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F4D40

//IconCache
#define IconCache__GetIcon_x                                       0x718670

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x7100D0
#define CContainerMgr__CloseContainer_x                            0x7103A0
#define CContainerMgr__OpenExperimentContainer_x                   0x710E20

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CF2B0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x631F60

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76CEA0
#define CLootWnd__RequestLootSlot_x                                0x76C180

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58E350
#define EQ_Spell__SpellAffects_x                                   0x58E7C0
#define EQ_Spell__SpellAffectBase_x                                0x58E580
#define EQ_Spell__IsStackable_x                                    0x4CAAA0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CA8C0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7B50
#define EQ_Spell__IsSPAStacking_x                                  0x58F610
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58EB20
#define EQ_Spell__IsNoRemove_x                                     0x4CAA80
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58F620
#define __IsResEffectSpell_x                                       0x4C9CC0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD4C0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C73C0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x816060
#define CTargetWnd__WndNotification_x                              0x8158A0
#define CTargetWnd__RefreshTargetBuffs_x                           0x815B70
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x814A00

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x81A6F0
#define CTaskWnd__ConfirmAbandonTask_x                             0x81D330

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x542350
#define CTaskManager__HandleMessage_x                              0x5407C0
#define CTaskManager__GetTaskStatus_x                              0x542400
#define CTaskManager__GetElementDescription_x                      0x542480

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x589430
#define EqSoundManager__PlayScriptMp3_x                            0x5896F0
#define EqSoundManager__SoundAssistPlay_x                          0x69D2D0
#define EqSoundManager__WaveInstancePlay_x                         0x69C840

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x533730

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x946C70
#define CTextureAnimation__Draw_x                                  0x946E70

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x942BC0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56E3C0
#define CAltAbilityData__GetMercMaxRank_x                          0x56E350
#define CAltAbilityData__GetMaxRank_x                              0x5637E0

//CTargetRing
#define CTargetRing__Cast_x                                        0x630080

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA8A0
#define CharacterBase__CreateItemGlobalIndex_x                     0x51A3D0
#define CharacterBase__CreateItemIndex_x                           0x6381B0
#define CharacterBase__GetItemPossession_x                         0x5062C0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CFA50
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CFAB0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F6FB0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F77E0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F7890

//messages
#define msg_spell_worn_off_x                                       0x5B34D0
#define msg_new_text_x                                             0x5A7E70
#define __msgTokenTextParam_x                                      0x5B5760
#define msgTokenText_x                                             0x5B59B0

//SpellManager
#define SpellManager__vftable_x                                    0xADB564
#define SpellManager__SpellManager_x                               0x6A0600
#define Spellmanager__LoadTextSpells_x                             0x6A0EF0
#define SpellManager__GetSpellByGroupAndRank_x                     0x6A07D0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98EF60

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x51AA50
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B99B0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x651000
#define ItemGlobalIndex__IsValidIndex_x                            0x51AAE0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C7D80
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C7F10

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x765760

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x7147C0
#define CCursorAttachment__AttachToCursor1_x                       0x714800
#define CCursorAttachment__Deactivate_x                            0x7157F0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x939880
#define CSidlManagerBase__CreatePageWnd_x                          0x939070
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x9352F0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x935280

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x956E70
#define CEQSuiteTextureLoader__GetTexture_x                        0x956B30

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x5176F0
#define CFindItemWnd__WndNotification_x                            0x518330
#define CFindItemWnd__Update_x                                     0x518EA0
#define CFindItemWnd__PickupSelectedItem_x                         0x516F20

//IString
#define IString__Append_x                                          0x507AF0

//Camera
#define CDisplay__cameraType_x                                     0xDEBD00
#define EverQuest__Cameras_x                                       0xEA70A8

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x520360
#define LootFiltersManager__GetItemFilterData_x                    0x51FC60
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51FC90
#define LootFiltersManager__SetItemLootFilter_x                    0x51FEB0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BD0F0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x994B80
#define CResolutionHandler__GetWindowedStyle_x                     0x697DE0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70CD00

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D38D0
#define CDistillerInfo__Instance_x                                 0x8D3870

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72BBC0
#define CGroupWnd__UpdateDisplay_x                                 0x72AF10

//ItemBase
#define ItemBase__IsLore_x                                         0x89D290
#define ItemBase__IsLoreEquipped_x                                 0x89D300

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EEFC0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EF100
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EF160

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68D310
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x690C90

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50DE20

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4FA210
#define FactionManagerClient__HandleFactionMessage_x               0x4FA880
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4FAE40
#define FactionManagerClient__GetMaxFaction_x                      0x4FAE5F
#define FactionManagerClient__GetMinFaction_x                      0x4FAE10

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x506290

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91DF90

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C1D0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x506500

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56D850

//CTargetManager
#define CTargetManager__Get_x                                      0x6A3E70

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68D310

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A90B0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5C1E20

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF4473C

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6C0850
#define CAAWnd__UpdateSelected_x                                   0x6BD0C0
#define CAAWnd__Update_x                                           0x6BFB70

//CXRect
#define CXRect__operator_and_x                                     0x722C80

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
