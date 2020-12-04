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
#define __ExpectedVersionDate                                     "Dec  4 2020"
#define __ExpectedVersionTime                                     "04:18:30"
#define __ActualVersionDate_x                                      0xAF7540
#define __ActualVersionTime_x                                      0xAF7534
#define __ActualVersionBuild_x                                     0xAE5574

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x644D10
#define __MemChecker1_x                                            0x8F8500
#define __MemChecker2_x                                            0x6B5370
#define __MemChecker3_x                                            0x6B52C0
#define __MemChecker4_x                                            0x84E8C0
#define __EncryptPad0_x                                            0xC2D9C8
#define __EncryptPad1_x                                            0xC8B210
#define __EncryptPad2_x                                            0xC3DD90
#define __EncryptPad3_x                                            0xC3D990
#define __EncryptPad4_x                                            0xC7B7A0
#define __EncryptPad5_x                                            0xF4E108
#define __AC1_x                                                    0x80D186
#define __AC2_x                                                    0x5FE4AF
#define __AC3_x                                                    0x605B00
#define __AC4_x                                                    0x609AB0
#define __AC5_x                                                    0x60FDAF
#define __AC6_x                                                    0x614266
#define __AC7_x                                                    0x5FDF20
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
#define __do_loot_x                                                0x5C9E90
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
#define __gfMaxZoomCameraDistance_x                                0xAEF170
#define __gfMaxCameraDistance_x                                    0xB17DE8
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
#define __CastRay_x                                                0x5C5580
#define __CastRay2_x                                               0x5C55D0
#define __ConvertItemTags_x                                        0x5E12A0
#define __CleanItemTags_x                                          0x47D200
#define __DoesFileExist_x                                          0x8FB530
#define __EQGetTime_x                                              0x8F8130
#define __ExecuteCmd_x                                             0x5BDF00
#define __FixHeading_x                                             0x98D610
#define __FlushDxKeyboard_x                                        0x6B1210
#define __GameLoop_x                                               0x6B4540
#define __get_bearing_x                                            0x5C50E0
#define __get_melee_range_x                                        0x5C57C0
#define __GetAnimationCache_x                                      0x7199F0
#define __GetGaugeValueFromEQ_x                                    0x80B630
#define __GetLabelFromEQ_x                                         0x80D110
#define __GetXTargetType_x                                         0x98EFF0
#define __HandleMouseWheel_x                                       0x6B5420
#define __HeadingDiff_x                                            0x98D680
#define __HelpPath_x                                               0xF45E0C
#define __LoadFrontEnd_x                                           0x6B1850
#define __NewUIINI_x                                               0x80B300
#define __ProcessGameEvents_x                                      0x626140
#define __ProcessMouseEvent_x                                      0x6258D0
#define __SaveColors_x                                             0x55DE10
#define __STMLToText_x                                             0x930A40
#define __ToggleKeyRingItem_x                                      0x51C5A0
#define CMemoryMappedFile__SetFile_x                               0xA7C980
#define CrashDetected_x                                            0x6B3300
#define DrawNetStatus_x                                            0x652220
#define Expansion_HoT_x                                            0xEA7D50
#define Teleport_Table_Size_x                                      0xEA17F0
#define Teleport_Table_x                                           0xE9F3B0
#define Util__FastTime_x                                           0x8F7D00
#define __CopyLayout_x                                             0x6404D0
#define __WndProc_x                                                0x6B3800
#define __ProcessKeyboardEvent_x                                   0x6B2DA0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490640
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499630
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499400
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493BD0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x493020

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x565F50
#define AltAdvManager__IsAbilityReady_x                            0x564CF0
#define AltAdvManager__GetAAById_x                                 0x565080
#define AltAdvManager__CanTrainAbility_x                           0x5650F0
#define AltAdvManager__CanSeeAbility_x                             0x565450

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CB180
#define CharacterZoneClient__HasSkill_x                            0x4D6000
#define CharacterZoneClient__MakeMeVisible_x                       0x4D7730
#define CharacterZoneClient__IsStackBlocked_x                      0x4C28D0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBD60
#define CharacterZoneClient__GetItemCountWorn_x                    0x4DA0F0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4DA1D0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4DA2B0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C49C0
#define CharacterZoneClient__BardCastBard_x                        0x4C73F0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF770
#define CharacterZoneClient__GetEffect_x                           0x4BBCA0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C5A30
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C5B00
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C5B50
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5CA0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5E80
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3C20
#define CharacterZoneClient__FindItemByGuid_x                      0x4D8690
#define CharacterZoneClient__FindItemByRecord_x                    0x4D8110

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6DB130
#define CBankWnd__WndNotification_x                                0x6DAF00

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E89C0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x92E220
#define CButtonWnd__CButtonWnd_x                                   0x92CDF0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x708BD0
#define CChatManager__InitContextMenu_x                            0x701D00
#define CChatManager__FreeChatWindow_x                             0x707710
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9AB0
#define CChatManager__SetLockedActiveChatWindow_x                  0x708850
#define CChatManager__CreateChatWindow_x                           0x707D50

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9BC0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x941410
#define CContextMenu__dCContextMenu_x                              0x941650
#define CContextMenu__AddMenuItem_x                                0x941660
#define CContextMenu__RemoveMenuItem_x                             0x941970
#define CContextMenu__RemoveAllMenuItems_x                         0x941990
#define CContextMenu__CheckMenuItem_x                              0x941A10
#define CContextMenu__SetMenuItem_x                                0x941890
#define CContextMenu__AddSeparator_x                               0x9417F0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x941FB0
#define CContextMenuManager__RemoveMenu_x                          0x942020
#define CContextMenuManager__PopupMenu_x                           0x9420E0
#define CContextMenuManager__Flush_x                               0x941F50
#define CContextMenuManager__GetMenu_x                             0x49B7D0
#define CContextMenuManager__CreateDefaultMenu_x                   0x714350

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D2DD0
#define CChatService__GetFriendName_x                              0x8D2DE0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x709400
#define CChatWindow__Clear_x                                       0x70A6C0
#define CChatWindow__WndNotification_x                             0x70AE50
#define CChatWindow__AddHistory_x                                  0x709F80

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93E860
#define CComboWnd__Draw_x                                          0x93DD40
#define CComboWnd__GetCurChoice_x                                  0x93E6A0
#define CComboWnd__GetListRect_x                                   0x93E200
#define CComboWnd__GetTextRect_x                                   0x93E8D0
#define CComboWnd__InsertChoice_x                                  0x93E390
#define CComboWnd__SetColors_x                                     0x93E360
#define CComboWnd__SetChoice_x                                     0x93E670
#define CComboWnd__GetItemCount_x                                  0x93E6B0
#define CComboWnd__GetCurChoiceText_x                              0x93E6F0
#define CComboWnd__GetChoiceText_x                                 0x93E6C0
#define CComboWnd__InsertChoiceAtIndex_x                           0x93E430

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x711D50
#define CContainerWnd__vftable_x                                   0xB0073C
#define CContainerWnd__SetContainer_x                              0x7132B0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x558770
#define CDisplay__PreZoneMainUI_x                                  0x558780
#define CDisplay__CleanGameUI_x                                    0x55DBD0
#define CDisplay__GetClickedActor_x                                0x550BD0
#define CDisplay__GetUserDefinedColor_x                            0x549240
#define CDisplay__GetWorldFilePath_x                               0x552640
#define CDisplay__is3dON_x                                         0x54D830
#define CDisplay__ReloadUI_x                                       0x557C80
#define CDisplay__WriteTextHD2_x                                   0x54D620
#define CDisplay__TrueDistance_x                                   0x554300
#define CDisplay__SetViewActor_x                                   0x5504F0
#define CDisplay__GetFloorHeight_x                                 0x54D8F0
#define CDisplay__SetRenderWindow_x                                0x54C270
#define CDisplay__ToggleScreenshotMode_x                           0x54FFC0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x961220

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x944920
#define CEditWnd__EnsureCaretVisible_x                             0x946AF0
#define CEditWnd__GetCaretPt_x                                     0x945AA0
#define CEditWnd__GetCharIndexPt_x                                 0x945850
#define CEditWnd__GetDisplayString_x                               0x9456F0
#define CEditWnd__GetHorzOffset_x                                  0x943FC0
#define CEditWnd__GetLineForPrintableChar_x                        0x9469F0
#define CEditWnd__GetSelStartPt_x                                  0x945B00
#define CEditWnd__GetSTMLSafeText_x                                0x945510
#define CEditWnd__PointFromPrintableChar_x                         0x946620
#define CEditWnd__SelectableCharFromPoint_x                        0x946790
#define CEditWnd__SetEditable_x                                    0x945BD0
#define CEditWnd__SetWindowTextA_x                                 0x945290
#define CEditWnd__ReplaceSelection_x                               0x946290
#define CEditWnd__ReplaceSelection1_x                              0x946210

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x613740
#define CEverQuest__ClickedPlayer_x                                0x6058E0
#define CEverQuest__CreateTargetIndicator_x                        0x6232B0
#define CEverQuest__DeleteTargetIndicator_x                        0x623340
#define CEverQuest__DoTellWindow_x                                 0x4E9CA0
#define CEverQuest__OutputTextToLog_x                              0x4E9F70
#define CEverQuest__DropHeldItemOnGround_x                         0x5FAA30
#define CEverQuest__dsp_chat_x                                     0x4EA300
#define CEverQuest__trimName_x                                     0x61F460
#define CEverQuest__Emote_x                                        0x613FA0
#define CEverQuest__EnterZone_x                                    0x60E0A0
#define CEverQuest__GetBodyTypeDesc_x                              0x6189F0
#define CEverQuest__GetClassDesc_x                                 0x619030
#define CEverQuest__GetClassThreeLetterCode_x                      0x619630
#define CEverQuest__GetDeityDesc_x                                 0x621B00
#define CEverQuest__GetLangDesc_x                                  0x6197F0
#define CEverQuest__GetRaceDesc_x                                  0x619010
#define CEverQuest__InterpretCmd_x                                 0x6220D0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FEBD0
#define CEverQuest__LMouseUp_x                                     0x5FCF50
#define CEverQuest__RightClickedOnPlayer_x                         0x5FF4B0
#define CEverQuest__RMouseUp_x                                     0x5FDEE0
#define CEverQuest__SetGameState_x                                 0x5FA7C0
#define CEverQuest__UPCNotificationFlush_x                         0x61F360
#define CEverQuest__IssuePetCommand_x                              0x61AC00
#define CEverQuest__ReportSuccessfulHit_x                          0x6152F0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7239D0
#define CGaugeWnd__CalcLinesFillRect_x                             0x723A30
#define CGaugeWnd__Draw_x                                          0x723050

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AFF40
#define CGuild__GetGuildName_x                                     0x4AE9F0
#define CGuild__GetGuildIndex_x                                    0x4AEFF0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73D680

//CHotButton
#define CHotButton__SetCheck_x                                     0x634A50
#define CHotButton__SetButtonSize_x                                0x634E10

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x74A950
#define CInvSlotMgr__MoveItem_x                                    0x749610
#define CInvSlotMgr__SelectSlot_x                                  0x74AA20

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x747E00
#define CInvSlot__SliderComplete_x                                 0x745B30
#define CInvSlot__GetItemBase_x                                    0x7454A0
#define CInvSlot__UpdateItem_x                                     0x745610

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x74C4B0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x74B640
#define CInvSlotWnd__HandleLButtonUp_x                             0x74C030

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x8069C0
#define CItemDisplayWnd__UpdateStrings_x                           0x75ACE0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x7549A0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x754EB0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x75B2F0
#define CItemDisplayWnd__AboutToShow_x                             0x75A920
#define CItemDisplayWnd__WndNotification_x                         0x75C570
#define CItemDisplayWnd__RequestConvertItem_x                      0x75BEA0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x759980
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x75A740

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x837520

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x760AB0

// CLabel 
#define CLabel__Draw_x                                             0x7664C0

// CListWnd
#define CListWnd__CListWnd_x                                       0x916EF0
#define CListWnd__dCListWnd_x                                      0x917210
#define CListWnd__AddColumn_x                                      0x91B6A0
#define CListWnd__AddColumn1_x                                     0x91B6F0
#define CListWnd__AddLine_x                                        0x91BA80
#define CListWnd__AddString_x                                      0x91B880
#define CListWnd__CalculateFirstVisibleLine_x                      0x91B460
#define CListWnd__CalculateVSBRange_x                              0x91B240
#define CListWnd__ClearSel_x                                       0x91C260
#define CListWnd__ClearAllSel_x                                    0x91C2C0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x91CCE0
#define CListWnd__Compare_x                                        0x91AB70
#define CListWnd__Draw_x                                           0x917340
#define CListWnd__DrawColumnSeparators_x                           0x919B40
#define CListWnd__DrawHeader_x                                     0x919FB0
#define CListWnd__DrawItem_x                                       0x91A4B0
#define CListWnd__DrawLine_x                                       0x919CB0
#define CListWnd__DrawSeparator_x                                  0x919BE0
#define CListWnd__EnableLine_x                                     0x919410
#define CListWnd__EnsureVisible_x                                  0x91CC00
#define CListWnd__ExtendSel_x                                      0x91C190
#define CListWnd__GetColumnTooltip_x                               0x918F50
#define CListWnd__GetColumnMinWidth_x                              0x918FC0
#define CListWnd__GetColumnWidth_x                                 0x918EC0
#define CListWnd__GetCurSel_x                                      0x918850
#define CListWnd__GetItemAtPoint_x                                 0x919690
#define CListWnd__GetItemAtPoint1_x                                0x919700
#define CListWnd__GetItemData_x                                    0x9188D0
#define CListWnd__GetItemHeight_x                                  0x918C90
#define CListWnd__GetItemIcon_x                                    0x918A60
#define CListWnd__GetItemRect_x                                    0x919500
#define CListWnd__GetItemText_x                                    0x918910
#define CListWnd__GetSelList_x                                     0x91C310
#define CListWnd__GetSeparatorRect_x                               0x919940
#define CListWnd__InsertLine_x                                     0x91BE70
#define CListWnd__RemoveLine_x                                     0x91BFC0
#define CListWnd__SetColors_x                                      0x91B210
#define CListWnd__SetColumnJustification_x                         0x91AF40
#define CListWnd__SetColumnLabel_x                                 0x91B820
#define CListWnd__SetColumnWidth_x                                 0x91AE60
#define CListWnd__SetCurSel_x                                      0x91C0D0
#define CListWnd__SetItemColor_x                                   0x91C8B0
#define CListWnd__SetItemData_x                                    0x91C870
#define CListWnd__SetItemText_x                                    0x91C480
#define CListWnd__ShiftColumnSeparator_x                           0x91B000
#define CListWnd__Sort_x                                           0x91ACF0
#define CListWnd__ToggleSel_x                                      0x91C100
#define CListWnd__SetColumnsSizable_x                              0x91B0B0
#define CListWnd__SetItemWnd_x                                     0x91C730
#define CListWnd__GetItemWnd_x                                     0x918AB0
#define CListWnd__SetItemIcon_x                                    0x91C500
#define CListWnd__CalculateCustomWindowPositions_x                 0x91B560
#define CListWnd__SetVScrollPos_x                                  0x91AE40

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x77BBC0
#define CMapViewWnd__GetWorldCoordinates_x                         0x77A2D0
#define CMapViewWnd__HandleLButtonDown_x                           0x777310

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x79BF00
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79C7E0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79CD10
#define CMerchantWnd__SelectRecoverySlot_x                         0x79FCD0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x79AA60
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A58A0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x79BB10

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8A0810
#define CPacketScrambler__hton_x                                   0x8A0800

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x936040
#define CSidlManager__FindScreenPieceTemplate_x                    0x936450
#define CSidlManager__FindScreenPieceTemplate1_x                   0x936240
#define CSidlManager__CreateLabel_x                                0x7FDAE0
#define CSidlManager__CreateXWndFromTemplate_x                     0x9393B0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x939590
#define CSidlManager__CreateXWnd_x                                 0x7FDA10
#define CSidlManager__CreateHotButtonWnd_x                         0x7FDFE0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x932B10
#define CSidlScreenWnd__CalculateVSBRange_x                        0x932A10
#define CSidlScreenWnd__ConvertToRes_x                             0x95BC60
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x932500
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x9321F0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x9322C0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x932390
#define CSidlScreenWnd__DrawSidlPiece_x                            0x932FB0
#define CSidlScreenWnd__EnableIniStorage_x                         0x933480
#define CSidlScreenWnd__GetSidlPiece_x                             0x9331A0
#define CSidlScreenWnd__Init1_x                                    0x931DF0
#define CSidlScreenWnd__LoadIniInfo_x                              0x9334D0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x934020
#define CSidlScreenWnd__LoadSidlScreen_x                           0x9311F0
#define CSidlScreenWnd__StoreIniInfo_x                             0x933BA0
#define CSidlScreenWnd__StoreIniVis_x                              0x933F00
#define CSidlScreenWnd__WndNotification_x                          0x932EC0
#define CSidlScreenWnd__GetChildItem_x                             0x933400
#define CSidlScreenWnd__HandleLButtonUp_x                          0x922B70
#define CSidlScreenWnd__m_layoutCopy_x                             0x15DC198

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x69A410
#define CSkillMgr__GetSkillCap_x                                   0x69A5F0
#define CSkillMgr__GetNameToken_x                                  0x699B90
#define CSkillMgr__IsActivatedSkill_x                              0x699CD0
#define CSkillMgr__IsCombatSkill_x                                 0x699C10

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x942DA0
#define CSliderWnd__SetValue_x                                     0x942C10
#define CSliderWnd__SetNumTicks_x                                  0x942C70

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x803CB0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x94B700
#define CStmlWnd__ParseSTML_x                                      0x94CA10
#define CStmlWnd__CalculateHSBRange_x                              0x94C7E0
#define CStmlWnd__CalculateVSBRange_x                              0x94C750
#define CStmlWnd__CanBreakAtCharacter_x                            0x950B20
#define CStmlWnd__FastForwardToEndOfTag_x                          0x9517B0
#define CStmlWnd__ForceParseNow_x                                  0x94BCA0
#define CStmlWnd__GetNextTagPiece_x                                0x950A80
#define CStmlWnd__GetSTMLText_x                                    0x50DB40
#define CStmlWnd__GetVisibleText_x                                 0x94BCC0
#define CStmlWnd__InitializeWindowVariables_x                      0x951600
#define CStmlWnd__MakeStmlColorTag_x                               0x94AD70
#define CStmlWnd__MakeWndNotificationTag_x                         0x94ADE0
#define CStmlWnd__SetSTMLText_x                                    0x949E20
#define CStmlWnd__StripFirstSTMLLines_x                            0x9528B0
#define CStmlWnd__UpdateHistoryString_x                            0x9519C0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x948F60
#define CTabWnd__DrawCurrentPage_x                                 0x949690
#define CTabWnd__DrawTab_x                                         0x9493B0
#define CTabWnd__GetCurrentPage_x                                  0x948760
#define CTabWnd__GetPageInnerRect_x                                0x9489A0
#define CTabWnd__GetTabInnerRect_x                                 0x9488E0
#define CTabWnd__GetTabRect_x                                      0x948790
#define CTabWnd__InsertPage_x                                      0x948BB0
#define CTabWnd__RemovePage_x                                      0x948D20
#define CTabWnd__SetPage_x                                         0x948A20
#define CTabWnd__SetPageRect_x                                     0x948EA0
#define CTabWnd__UpdatePage_x                                      0x949270
#define CTabWnd__GetPageFromTabIndex_x                             0x9492F0
#define CTabWnd__GetCurrentTabIndex_x                              0x948750

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x760EC0
#define CPageWnd__SetTabText_x                                     0x9482A0
#define CPageWnd__FlashTab_x                                       0x948300

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9230

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91F9D0
#define CTextureFont__GetTextExtent_x                              0x91FB90

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AE6C0
#define CHtmlComponentWnd__ValidateUri_x                           0x73F070
#define CHtmlWnd__SetClientCallbacks_x                             0x639EC0
#define CHtmlWnd__AddObserver_x                                    0x639EE0
#define CHtmlWnd__RemoveObserver_x                                 0x639F40
#define Window__getProgress_x                                      0x855E90
#define Window__getStatus_x                                        0x855EB0
#define Window__getURI_x                                           0x855EC0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x958A70

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x90C930

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E99A0
#define CXStr__CXStr1_x                                            0x846670
#define CXStr__CXStr3_x                                            0x8F40B0
#define CXStr__dCXStr_x                                            0x4783F0
#define CXStr__operator_equal_x                                    0x8F42E0
#define CXStr__operator_equal1_x                                   0x8F4320
#define CXStr__operator_plus_equal1_x                              0x8F4DB0
#define CXStr__SetString_x                                         0x8F6CA0
#define CXStr__operator_char_p_x                                   0x8F4820
#define CXStr__GetChar_x                                           0x8F65F0
#define CXStr__Delete_x                                            0x8F5EA0
#define CXStr__GetUnicode_x                                        0x8F6660
#define CXStr__GetLength_x                                         0x47D5B0
#define CXStr__Mid_x                                               0x47D5C0
#define CXStr__Insert_x                                            0x8F66C0
#define CXStr__FindNext_x                                          0x8F6310

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x941020
#define CXWnd__BringToTop_x                                        0x926310
#define CXWnd__Center_x                                            0x925E90
#define CXWnd__ClrFocus_x                                          0x925CA0
#define CXWnd__Destroy_x                                           0x925D50
#define CXWnd__DoAllDrawing_x                                      0x922300
#define CXWnd__DrawChildren_x                                      0x9222D0
#define CXWnd__DrawColoredRect_x                                   0x922760
#define CXWnd__DrawTooltip_x                                       0x920E00
#define CXWnd__DrawTooltipAtPoint_x                                0x920EC0
#define CXWnd__GetBorderFrame_x                                    0x9225C0
#define CXWnd__GetChildWndAt_x                                     0x9263B0
#define CXWnd__GetClientClipRect_x                                 0x9245D0
#define CXWnd__GetScreenClipRect_x                                 0x924680
#define CXWnd__GetScreenRect_x                                     0x924830
#define CXWnd__GetRelativeRect_x                                   0x924900
#define CXWnd__GetTooltipRect_x                                    0x9227B0
#define CXWnd__GetWindowTextA_x                                    0x49CEB0
#define CXWnd__IsActive_x                                          0x922EF0
#define CXWnd__IsDescendantOf_x                                    0x925230
#define CXWnd__IsReallyVisible_x                                   0x925260
#define CXWnd__IsType_x                                            0x926A30
#define CXWnd__Move_x                                              0x9252D0
#define CXWnd__Move1_x                                             0x925390
#define CXWnd__ProcessTransition_x                                 0x925E40
#define CXWnd__Refade_x                                            0x925670
#define CXWnd__Resize_x                                            0x925900
#define CXWnd__Right_x                                             0x9260D0
#define CXWnd__SetFocus_x                                          0x925C60
#define CXWnd__SetFont_x                                           0x925CD0
#define CXWnd__SetKeyTooltip_x                                     0x926840
#define CXWnd__SetMouseOver_x                                      0x923720
#define CXWnd__StartFade_x                                         0x925110
#define CXWnd__GetChildItem_x                                      0x926520
#define CXWnd__SetParent_x                                         0x924FE0
#define CXWnd__Minimize_x                                          0x925960

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x95CCE0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x929260
#define CXWndManager__DrawWindows_x                                0x929280
#define CXWndManager__GetKeyboardFlags_x                           0x92BA80
#define CXWndManager__HandleKeyboardMsg_x                          0x92B630
#define CXWndManager__RemoveWnd_x                                  0x92BCA0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x92C210

// CDBStr
#define CDBStr__GetString_x                                        0x548210

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BFED0
#define EQ_Character__Cur_HP_x                                     0x4D3040
#define EQ_Character__Cur_Mana_x                                   0x4DA7B0
#define EQ_Character__GetCastingTimeModifier_x                     0x4C2F40
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B3860
#define EQ_Character__GetFocusRangeModifier_x                      0x4B39B0
#define EQ_Character__GetHPRegen_x                                 0x4E06B0
#define EQ_Character__GetEnduranceRegen_x                          0x4E0CB0
#define EQ_Character__GetManaRegen_x                               0x4E10F0
#define EQ_Character__Max_Endurance_x                              0x660610
#define EQ_Character__Max_HP_x                                     0x4D2E70
#define EQ_Character__Max_Mana_x                                   0x660410
#define EQ_Character__doCombatAbility_x                            0x662A00
#define EQ_Character__UseSkill_x                                   0x4E2F00
#define EQ_Character__GetConLevel_x                                0x659180
#define EQ_Character__IsExpansionFlag_x                            0x5BC6A0
#define EQ_Character__TotalEffect_x                                0x4C6CE0
#define EQ_Character__GetPCSpellAffect_x                           0x4C3C90
#define EQ_Character__SpellDuration_x                              0x4C37C0
#define EQ_Character__MySpellDuration_x                            0x4B2190
#define EQ_Character__GetAdjustedSkill_x                           0x4D5DC0
#define EQ_Character__GetBaseSkill_x                               0x4D6D60
#define EQ_Character__CanUseItem_x                                 0x4DAAC0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BFD40

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x6768E0

//PcClient
#define PcClient__vftable_x                                        0xAF41C4
#define PcClient__PcClient_x                                       0x6568E0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA910
#define CCharacterListWnd__EnterWorld_x                            0x4BA2E0
#define CCharacterListWnd__Quit_x                                  0x4BA030
#define CCharacterListWnd__UpdateList_x                            0x4BA4D0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x63B0B0
#define EQ_Item__CreateItemTagString_x                             0x899CE0
#define EQ_Item__IsStackable_x                                     0x89E9E0
#define EQ_Item__GetImageNum_x                                     0x89B8B0
#define EQ_Item__CreateItemClient_x                                0x63A2E0
#define EQ_Item__GetItemValue_x                                    0x89CB80
#define EQ_Item__ValueSellMerchant_x                               0x8A03F0
#define EQ_Item__IsKeyRingItem_x                                   0x89E270
#define EQ_Item__CanGoInBag_x                                      0x63B1D0
#define EQ_Item__IsEmpty_x                                         0x89DDD0
#define EQ_Item__GetMaxItemCount_x                                 0x89CFA0
#define EQ_Item__GetHeldItem_x                                     0x89B780
#define EQ_Item__GetAugmentFitBySlot_x                             0x899520

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x566C50
#define EQ_LoadingS__Array_x                                       0xC15130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x660F10
#define EQ_PC__GetAlternateAbilityId_x                             0x8A97D0
#define EQ_PC__GetCombatAbility_x                                  0x8A9E40
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A9EB0
#define EQ_PC__GetItemRecastTimer_x                                0x662F80
#define EQ_PC__HasLoreItem_x                                       0x6599A0
#define EQ_PC__AlertInventoryChanged_x                             0x658AB0
#define EQ_PC__GetPcZoneClient_x                                   0x6858F0
#define EQ_PC__RemoveMyAffect_x                                    0x6661A0
#define EQ_PC__GetKeyRingItems_x                                   0x8AA780
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8AA500
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8AAA80

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5C2B00
#define EQItemList__add_object_x                                   0x5F0210
#define EQItemList__add_item_x                                     0x5C3060
#define EQItemList__delete_item_x                                  0x5C30B0
#define EQItemList__FreeItemList_x                                 0x5C2FB0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x544DD0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x6781E0
#define EQPlayer__dEQPlayer_x                                      0x66B560
#define EQPlayer__DoAttack_x                                       0x680080
#define EQPlayer__EQPlayer_x                                       0x66BC20
#define EQPlayer__SetNameSpriteState_x                             0x66FEF0
#define EQPlayer__SetNameSpriteTint_x                              0x670DD0
#define PlayerBase__HasProperty_j_x                                0x98BA20
#define EQPlayer__IsTargetable_x                                   0x98BEC0
#define EQPlayer__CanSee_x                                         0x98BD20
#define EQPlayer__CanSee1_x                                        0x98BDF0
#define PlayerBase__GetVisibilityLineSegment_x                     0x98BAE0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x683380
#define PlayerZoneClient__GetLevel_x                               0x685930
#define PlayerZoneClient__IsValidTeleport_x                        0x5F1380
#define PlayerZoneClient__LegalPlayerRace_x                        0x55FA00

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x67AFA0
#define EQPlayerManager__GetSpawnByName_x                          0x67B050
#define EQPlayerManager__GetPlayerFromPartialName_x                0x67B0E0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63E730
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63E7B0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63E7F0
#define KeypressHandler__ClearCommandStateArray_x                  0x63FBE0
#define KeypressHandler__HandleKeyDown_x                           0x63FC00
#define KeypressHandler__HandleKeyUp_x                             0x63FCA0
#define KeypressHandler__SaveKeymapping_x                          0x6400F0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x777A30
#define MapViewMap__SaveEx_x                                       0x77ADF0
#define MapViewMap__SetZoom_x                                      0x77F4B0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BDDA0

// StringTable 
#define StringTable__getString_x                                   0x8B8C90

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x665E10
#define PcZoneClient__RemovePetEffect_x                            0x666440
#define PcZoneClient__HasAlternateAbility_x                        0x660240
#define PcZoneClient__GetCurrentMod_x                              0x4E6020
#define PcZoneClient__GetModCap_x                                  0x4E5F20
#define PcZoneClient__CanEquipItem_x                               0x6608F0
#define PcZoneClient__GetItemByID_x                                0x6633F0
#define PcZoneClient__GetItemByItemClass_x                         0x663540
#define PcZoneClient__RemoveBuffEffect_x                           0x666460
#define PcZoneClient__BandolierSwap_x                              0x6614D0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x662F20

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F5F40

//IconCache
#define IconCache__GetIcon_x                                       0x7193F0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x710EC0
#define CContainerMgr__CloseContainer_x                            0x711190
#define CContainerMgr__OpenExperimentContainer_x                   0x711C10

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D0000

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x633210

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76DF90
#define CLootWnd__RequestLootSlot_x                                0x76D260

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58E9D0
#define EQ_Spell__SpellAffects_x                                   0x58EE40
#define EQ_Spell__SpellAffectBase_x                                0x58EC00
#define EQ_Spell__IsStackable_x                                    0x4CAAA0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CA8F0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7B40
#define EQ_Spell__IsSPAStacking_x                                  0x58FC90
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58F1A0
#define EQ_Spell__IsNoRemove_x                                     0x4CAA80
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58FCA0
#define __IsResEffectSpell_x                                       0x4C9D30

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD4D0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C8430

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x8170E0
#define CTargetWnd__WndNotification_x                              0x816920
#define CTargetWnd__RefreshTargetBuffs_x                           0x816BF0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x815A80

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x81B750
#define CTaskWnd__ConfirmAbandonTask_x                             0x81E390

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x5427C0
#define CTaskManager__HandleMessage_x                              0x540C20
#define CTaskManager__GetTaskStatus_x                              0x542870
#define CTaskManager__GetElementDescription_x                      0x5428F0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x589940
#define EqSoundManager__PlayScriptMp3_x                            0x589C00
#define EqSoundManager__SoundAssistPlay_x                          0x69E3F0
#define EqSoundManager__WaveInstancePlay_x                         0x69D960

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x533B90

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x9477B0
#define CTextureAnimation__Draw_x                                  0x9479B0

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x943700

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56E7E0
#define CAltAbilityData__GetMercMaxRank_x                          0x56E770
#define CAltAbilityData__GetMaxRank_x                              0x563B70

//CTargetRing
#define CTargetRing__Cast_x                                        0x631330

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA8D0
#define CharacterBase__CreateItemGlobalIndex_x                     0x51A750
#define CharacterBase__CreateItemIndex_x                           0x639470
#define CharacterBase__GetItemPossession_x                         0x506570
#define CharacterBase__GetItemByGlobalIndex_x                      0x8D0AC0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8D0B20
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F7F40
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F8770
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F8820

//messages
#define msg_spell_worn_off_x                                       0x5B46B0
#define msg_new_text_x                                             0x5A9010
#define __msgTokenTextParam_x                                      0x5B6940
#define msgTokenText_x                                             0x5B6B90

//SpellManager
#define SpellManager__vftable_x                                    0xADC534
#define SpellManager__SpellManager_x                               0x6A1720
#define Spellmanager__LoadTextSpells_x                             0x6A2010
#define SpellManager__GetSpellByGroupAndRank_x                     0x6A18F0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98F8E0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x51AE00
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5BABC0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x652080
#define ItemGlobalIndex__IsValidIndex_x                            0x51AE90

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C8DF0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C8F80

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x766800

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x7155F0
#define CCursorAttachment__AttachToCursor1_x                       0x715630
#define CCursorAttachment__Deactivate_x                            0x716620

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x93A3F0
#define CSidlManagerBase__CreatePageWnd_x                          0x939BE0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x935E60
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x935DF0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x957760
#define CEQSuiteTextureLoader__GetTexture_x                        0x957420

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x517A10
#define CFindItemWnd__WndNotification_x                            0x518650
#define CFindItemWnd__Update_x                                     0x5191C0
#define CFindItemWnd__PickupSelectedItem_x                         0x517240

//IString
#define IString__Append_x                                          0x507DA0

//Camera
#define CDisplay__cameraType_x                                     0xDECD00
#define EverQuest__Cameras_x                                       0xEA80A8

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x520710
#define LootFiltersManager__GetItemFilterData_x                    0x520010
#define LootFiltersManager__RemoveItemLootFilter_x                 0x520040
#define LootFiltersManager__SetItemLootFilter_x                    0x520260

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BDE20

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9954E0
#define CResolutionHandler__GetWindowedStyle_x                     0x698FD0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70DB70

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D4870
#define CDistillerInfo__Instance_x                                 0x8D4810

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72C9B0
#define CGroupWnd__UpdateDisplay_x                                 0x72BD00

//ItemBase
#define ItemBase__IsLore_x                                         0x89E320
#define ItemBase__IsLoreEquipped_x                                 0x89E3A0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5F0170
#define EQPlacedItemManager__GetItemByGuid_x                       0x5F02B0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5F0310

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68E0E0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x691A70

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50E170

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4FA370
#define FactionManagerClient__HandleFactionMessage_x               0x4FA9E0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4FAFA0
#define FactionManagerClient__GetMaxFaction_x                      0x4FAFBF
#define FactionManagerClient__GetMinFaction_x                      0x4FAF70

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x506540

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91E980

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C1C0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x5067B0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56DC90

//CTargetManager
#define CTargetManager__Get_x                                      0x6A4F50

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68E0E0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8FF0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5C2F50

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF4573C

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6C17A0
#define CAAWnd__UpdateSelected_x                                   0x6BE010
#define CAAWnd__Update_x                                           0x6C0AC0

//CXRect
#define CXRect__operator_and_x                                     0x723A90

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x483270

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
