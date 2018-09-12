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
#define __ExpectedVersionDate                                     "Sep 10 2018"
#define __ExpectedVersionTime                                     "19:51:49"
#define __ActualVersionDate_x                                      0xAC0674
#define __ActualVersionTime_x                                      0xAC0668

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x609590
#define __MemChecker1_x                                            0x8DBA10
#define __MemChecker2_x                                            0x697DA0
#define __MemChecker3_x                                            0x697CF0
#define __MemChecker4_x                                            0x833F60
#define __EncryptPad0_x                                            0xBF24C0
#define __EncryptPad1_x                                            0xC501A0
#define __EncryptPad2_x                                            0xC03048
#define __EncryptPad3_x                                            0xC02C48
#define __EncryptPad4_x                                            0xC40F38
#define __EncryptPad5_x                                            0x1018E3C
#define __AC1_x                                                    0x7F0896
#define __AC2_x                                                    0x5C504F
#define __AC3_x                                                    0x5CBEDF
#define __AC4_x                                                    0x5CFD50
#define __AC5_x                                                    0x5D5F0F
#define __AC6_x                                                    0x5DA446
#define __AC7_x                                                    0x5C4AC0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1EBAC48

// Direct Input
#define DI8__Main_x                                                0x1018E5C
#define DI8__Keyboard_x                                            0x1018E60
#define DI8__Mouse_x                                               0xF0DD98
#define DI8__Mouse_Copy_x                                          0xE6BA7C
#define DI8__Mouse_Check_x                                         0xF0EAC8
#define __AutoSkillArray_x                                         0xE6C994
#define __Attack_x                                                 0xF0A793
#define __Autofire_x                                               0xF0A794
#define __BindList_x                                               0xBE10C0
#define g_eqCommandStates_x                                        0xBE1E30
#define __Clicks_x                                                 0xE6BB34
#define __CommandList_x                                            0xBE29E8
#define __CurrentMapLabel_x                                        0x102033C
#define __CurrentSocial_x                                          0xBCC734
#define __DoAbilityList_x                                          0xEA22B4
#define __do_loot_x                                                0x592920
#define __DrawHandler_x                                            0x169B870
#define __GroupCount_x                                             0xE5BDB2
#define __Guilds_x                                                 0xE62288
#define __gWorld_x                                                 0xE5DFAC
#define __HWnd_x                                                   0xF0DD9C
#define __heqmain_x                                                0x1018E24
#define __InChatMode_x                                             0xE6BA64
#define __LastTell_x                                               0xE6D9B0
#define __LMouseHeldTime_x                                         0xE6BBA0
#define __Mouse_x                                                  0x1018E48
#define __MouseLook_x                                              0xE6BAFA
#define __MouseEventTime_x                                         0xF0B248
#define __gpbCommandEvent_x                                        0xE5E1C4
#define __NetStatusToggle_x                                        0xE6BAFD
#define __PCNames_x                                                0xE6CF70
#define __RangeAttackReady_x                                       0xE6CC78
#define __RMouseHeldTime_x                                         0xE6BB9C
#define __RunWalkState_x                                           0xE6BA68
#define __ScreenMode_x                                             0xDAA604
#define __ScreenX_x                                                0xE6BA1C
#define __ScreenY_x                                                0xE6BA18
#define __ScreenXMax_x                                             0xE6BA20
#define __ScreenYMax_x                                             0xE6BA24
#define __ServerHost_x                                             0xE5E313
#define __ServerName_x                                             0xEA2274
#define __ShiftKeyDown_x                                           0xE6C0F4
#define __ShowNames_x                                              0xE6CE34
#define __Socials_x                                                0xEA2374
#define __SubscriptionType_x                                       0x1061E04
#define __TargetAggroHolder_x                                      0x1022CF4
#define __ZoneType_x                                               0xE6BEF8
#define __GroupAggro_x                                             0x1022D34
#define __LoginName_x                                              0xF0E45C
#define __Inviter_x                                                0xF0A710
#define __AttackOnAssist_x                                         0xE6CDF0
#define __UseTellWindows_x                                         0xE6D108
#define __gfMaxZoomCameraDistance_x                                0xAB5AD8
#define __gfMaxCameraDistance_x                                    0xAE3050
#define __pulAutoRun_x                                             0xE6BB18
#define __pulForward_x                                             0xE6D140
#define __pulBackward_x                                            0xE6D144
#define __pulTurnRight_x                                           0xE6D148
#define __pulTurnLeft_x                                            0xE6D14C
#define __pulStrafeLeft_x                                          0xE6D150
#define __pulStrafeRight_x                                         0xE6D154

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE5E630
#define instEQZoneInfo_x                                           0xE6BCF0
#define instKeypressHandler_x                                      0xF0B1F8
#define pinstActiveBanker_x                                        0xE5BD28
#define pinstActiveCorpse_x                                        0xE5BD20
#define pinstActiveGMaster_x                                       0xE5BD24
#define pinstActiveMerchant_x                                      0xE5E628
#define pinstAggroInfo_x                                           0xC669B8
#define pinstAltAdvManager_x                                       0xDAAFD0
#define pinstAuraMgr_x                                             0xC776A0
#define pinstBandageTarget_x                                       0xE5BD38
#define pinstCamActor_x                                            0xDAA5F8
#define pinstCDBStr_x                                              0xDA9D0C
#define pinstCDisplay_x                                            0xE5BD7C
#define pinstCEverQuest_x                                          0x1018F78
#define pinstEverQuestInfo_x                                       0xE6BA10
#define pinstCharData_x                                            0xE5BD84
#define pinstCharSpawn_x                                           0xE5BD70
#define pinstControlledMissile_x                                   0xE5BD88
#define pinstControlledPlayer_x                                    0xE5BD70
#define pinstCResolutionHandler_x                                  0x169BAA0
#define pinstCSidlManager_x                                        0x169A934
#define pinstCXWndManager_x                                        0x169A928
#define instDynamicZone_x                                          0xE62160
#define pinstDZMember_x                                            0xE62270
#define pinstDZTimerInfo_x                                         0xE62274
#define pinstEQItemList_x                                          0xE5A820
#define pinstEQObjectList_x                                        0xE5BA10
#define instEQMisc_x                                               0xDA9C48
#define pinstEQSoundManager_x                                      0xDAB830
#define pinstEQSpellStrings_x                                      0xC74AF0
#define instExpeditionLeader_x                                     0xE621AA
#define instExpeditionName_x                                       0xE621EA
#define pinstGroup_x                                               0xE5BDAE
#define pinstImeManager_x                                          0x169A92C
#define pinstLocalPlayer_x                                         0xE5E624
#define pinstMercenaryData_x                                       0xF0B9E8
#define pinstMercenaryStats_x                                      0x1022E40
#define pinstMercAltAbilities_x                                    0xDAB5A0
#define pinstModelPlayer_x                                         0xE5BD30
#define pinstPCData_x                                              0xE5BD84
#define pinstRealEstateItems_x                                     0xF0CED8
#define pinstSkillMgr_x                                            0xF0CFA8
#define pinstSpawnManager_x                                        0xF0C598
#define pinstSpellManager_x                                        0xF0D180
#define pinstSpellSets_x                                           0xF033BC
#define pinstStringTable_x                                         0xE5E018
#define pinstSwitchManager_x                                       0xE5BBD0
#define pinstTarget_x                                              0xE5BD6C
#define pinstTargetObject_x                                        0xE5BD78
#define pinstTargetSwitch_x                                        0xE5BD90
#define pinstTaskMember_x                                          0xDA9AD8
#define pinstTrackTarget_x                                         0xE5BD74
#define pinstTradeTarget_x                                         0xE5BD2C
#define instTributeActive_x                                        0xDA9C6D
#define pinstViewActor_x                                           0xDAA5F4
#define pinstWorldData_x                                           0xE5BD9C
#define pinstZoneAddr_x                                            0xE6BF90
#define pinstPlayerPath_x                                          0xF0C630
#define pinstTargetIndicator_x                                     0xF0D3E8
#define pinstCTargetManager_x                                      0xF0D480
#define EQObject_Top_x                                             0xE5E41C
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDAA584
#define pinstCAchievementsWnd_x                                    0xDA9DB8
#define pinstCActionsWnd_x                                         0xDAA5E4
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDAA570
#define pinstCAdvancedLootWnd_x                                    0xDAA538
#define pinstCAdventureLeaderboardWnd_x                            0x1019B10
#define pinstCAdventureRequestWnd_x                                0x1019BC0
#define pinstCAdventureStatsWnd_x                                  0x1019C70
#define pinstCAggroMeterWnd_x                                      0xDA9DF4
#define pinstCAlarmWnd_x                                           0xDAA634
#define pinstCAlertHistoryWnd_x                                    0xDAA624
#define pinstCAlertStackWnd_x                                      0xDAA594
#define pinstCAlertWnd_x                                           0xDAA5A8
#define pinstCAltStorageWnd_x                                      0x1019FD0
#define pinstCAudioTriggersWindow_x                                0xC66E48
#define pinstCAuraWnd_x                                            0xDA9DEC
#define pinstCAvaZoneWnd_x                                         0xDAA5E0
#define pinstCBandolierWnd_x                                       0xDAA030
#define pinstCBankWnd_x                                            0xDAA530
#define pinstCBarterMerchantWnd_x                                  0x101B210
#define pinstCBarterSearchWnd_x                                    0x101B2C0
#define pinstCBarterWnd_x                                          0x101B370
#define pinstCBazaarConfirmationWnd_x                              0xDAA590
#define pinstCBazaarSearchWnd_x                                    0xDAA610
#define pinstCBazaarWnd_x                                          0xDAA02C
#define pinstCBlockedBuffWnd_x                                     0xDAA514
#define pinstCBlockedPetBuffWnd_x                                  0xDAA53C
#define pinstCBodyTintWnd_x                                        0xDAA5A4
#define pinstCBookWnd_x                                            0xDAA054
#define pinstCBreathWnd_x                                          0xDAA598
#define pinstCBuffWindowNORMAL_x                                   0xDAA4D8
#define pinstCBuffWindowSHORT_x                                    0xDAA4DC
#define pinstCBugReportWnd_x                                       0xDAA57C
#define pinstCButtonWnd_x                                          0x169AB20
#define pinstCCastingWnd_x                                         0xDAA578
#define pinstCCastSpellWnd_x                                       0xDAA62C
//#define pinstCCharacterCreationWnd_x                               0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDAA5A0
#define pinstCChatWindowManager_x                                  0x101BE30
#define pinstCClaimWnd_x                                           0x101BF88
#define pinstCColorPickerWnd_x                                     0xDAA5BC
#define pinstCCombatAbilityWnd_x                                   0xDA9DFC
#define pinstCCombatSkillsSelectWnd_x                              0xDAA5DC
#define pinstCCompassWnd_x                                         0xDAA588
#define pinstCConfirmationDialog_x                                 0x1020E88
#define pinstCContainerMgr_x                                       0xDAA024
#define pinstCContextMenuManager_x                                 0x169A8E8
#define pinstCCursorAttachment_x                                   0xDAA56C
#define pinstCDistillerInfo_x                                      0x101F894 
#define pinstCDynamicZoneWnd_x                                     0x101C550
#define pinstCEditLabelWnd_x                                       0xDAA4C8
#define pinstCEQMainWnd_x                                          0x101C798
#define pinstCEventCalendarWnd_x                                   0xDA9E04
#define pinstCExtendedTargetWnd_x                                  0xDA9DE4
#define pinstCFacePick_x                                           0xDAA5C4
#define pinstCFellowshipWnd_x                                      0x101C998
#define pinstCFileSelectionWnd_x                                   0xDAA518
#define pinstCFindItemWnd_x                                        0xDAA020
#define pinstCFindLocationWnd_x                                    0x101CAF0
#define pinstCFriendsWnd_x                                         0xDAA614
#define pinstCGemsGameWnd_x                                        0xDAA5E8
#define pinstCGiveWnd_x                                            0xDAA040
#define pinstCGroupSearchFiltersWnd_x                              0xDAA010
#define pinstCGroupSearchWnd_x                                     0x101CEE8
#define pinstCGroupWnd_x                                           0x101CF98
#define pinstCGuildBankWnd_x                                       0xE6CDD4
#define pinstCGuildCreationWnd_x                                   0x101D0F8
#define pinstCGuildMgmtWnd_x                                       0x101D1A8
#define pinstCharacterCreation_x                                   0xDA9DF8
#define pinstCHelpWnd_x                                            0xDA9DAC
#define pinstCHeritageSelectionWnd_x                               0xDAA5CC
#define pinstCHotButtonWnd_x                                       0x101F300
#define pinstCHotButtonWnd1_x                                      0x101F300
#define pinstCHotButtonWnd2_x                                      0x101F304
#define pinstCHotButtonWnd3_x                                      0x101F308
#define pinstCHotButtonWnd4_x                                      0x101F30C
#define pinstCIconSelectionWnd_x                                   0xDAA54C
#define pinstCInspectWnd_x                                         0xDAA544
#define pinstCInventoryWnd_x                                       0xDAA034
#define pinstCInvSlotMgr_x                                         0xDA9DC0
#define pinstCItemDisplayManager_x                                 0x101F890
#define pinstCItemExpTransferWnd_x                                 0x101F9C4
#define pinstCItemOverflowWnd_x                                    0xDAA618
#define pinstCJournalCatWnd_x                                      0xDAA540
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDAA4D4
#define pinstCKeyRingWnd_x                                         0xDAA508
#define pinstCLargeDialogWnd_x                                     0x1021B08
#define pinstCLayoutCopyWnd_x                                      0x101FD10
#define pinstCLFGuildWnd_x                                         0x101FDC0
#define pinstCLoadskinWnd_x                                        0xDAA61C
#define pinstCLootFiltersCopyWnd_x                                 0xC77E80
#define pinstCLootFiltersWnd_x                                     0xDAA5B8
#define pinstCLootSettingsWnd_x                                    0xDAA5C8
#define pinstCLootWnd_x                                            0xDAA5B0
#define pinstCMailAddressBookWnd_x                                 0xDAA550
#define pinstCMailCompositionWnd_x                                 0xDAA534
#define pinstCMailIgnoreListWnd_x                                  0xDAA554
#define pinstCMailWnd_x                                            0xDAA50C
#define pinstCManageLootWnd_x                                      0xDAB448
#define pinstCMapToolbarWnd_x                                      0xDAA038
#define pinstCMapViewWnd_x                                         0xDAA018
#define pinstCMarketplaceWnd_x                                     0xDAA01C
#define pinstCMerchantWnd_x                                        0xDAA5D8
#define pinstCMIZoneSelectWnd_x                                    0x10205F8
#define pinstCMusicPlayerWnd_x                                     0xDAA504
#define pinstCNameChangeMercWnd_x                                  0xDAA548
#define pinstCNameChangePetWnd_x                                   0xDAA52C
#define pinstCNameChangeWnd_x                                      0xDA9DF0
#define pinstCNoteWnd_x                                            0xDA9DA8
#define pinstCObjectPreviewWnd_x                                   0xDAA0BC
#define pinstCOptionsWnd_x                                         0xDAA03C
#define pinstCPetInfoWnd_x                                         0xDAA524
#define pinstCPetitionQWnd_x                                       0xDAA558
//#define pinstCPlayerCustomizationWnd_x                             0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDAA59C
#define pinstCPlayerWnd_x                                          0xDAA620
#define pinstCPopupWndManager_x                                    0x1020E88
#define pinstCProgressionSelectionWnd_x                            0x1020F38
#define pinstCPurchaseGroupWnd_x                                   0xDAA500
#define pinstCPurchaseWnd_x                                        0xDAA4C4
#define pinstCPvPLeaderboardWnd_x                                  0x1020FE8
#define pinstCPvPStatsWnd_x                                        0x1021098
#define pinstCQuantityWnd_x                                        0xDAA560
#define pinstCRaceChangeWnd_x                                      0xDAA028
#define pinstCRaidOptionsWnd_x                                     0xDAA014
#define pinstCRaidWnd_x                                            0xDAA564
#define pinstCRealEstateItemsWnd_x                                 0xDA9DC4
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDA9E00
#define pinstCRealEstateManageWnd_x                                0xDAA5D0
#define pinstCRealEstateNeighborhoodWnd_x                          0xDAA5EC
#define pinstCRealEstatePlotSearchWnd_x                            0xDAA628
#define pinstCRealEstatePurchaseWnd_x                              0xDA9DB0
#define pinstCRespawnWnd_x                                         0xDA9E0C
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDA9DE0
#define pinstCSendMoneyWnd_x                                       0xDAA4CC
#define pinstCServerListWnd_x                                      0xDA9DC8
#define pinstCSkillsSelectWnd_x                                    0xDAA5C0
#define pinstCSkillsWnd_x                                          0xDAA5AC
#define pinstCSocialEditWnd_x                                      0xDAA568
#define pinstCSocialWnd_x                                          0xDAA574
#define pinstCSpellBookWnd_x                                       0xDA9DD8
#define pinstCStoryWnd_x                                           0xDAA580
#define pinstCTargetOfTargetWnd_x                                  0x1022EC8
#define pinstCTargetWnd_x                                          0xDAA520
#define pinstCTaskOverlayWnd_x                                     0xDAA630
#define pinstCTaskSelectWnd_x                                      0x1023020
#define pinstCTaskSomething_x                                      0xC78680
#define pinstCTaskTemplateSelectWnd_x                              0x10230D0
#define pinstCTaskWnd_x                                            0x1023180
#define pinstCTextEntryWnd_x                                       0xDAA58C
#define pinstCTextOverlay_x                                        0xC67158
#define pinstCTimeLeftWnd_x                                        0xDAA528
#define pinstCTipWndCONTEXT_x                                      0x1023384
#define pinstCTipWndOFDAY_x                                        0x1023380
#define pinstCTitleWnd_x                                           0x1023430
#define pinstCTrackingWnd_x                                        0xDAA51C
#define pinstCTradeskillWnd_x                                      0x1023598
#define pinstCTradeWnd_x                                           0xDA9DB4
#define pinstCTrainWnd_x                                           0xDAA55C
#define pinstCTributeBenefitWnd_x                                  0x1023798
#define pinstCTributeMasterWnd_x                                   0x1023848
#define pinstCTributeTrophyWnd_x                                   0x10238F8
#define pinstCVideoModesWnd_x                                      0xDA9DBC
#define pinstCVoiceMacroWnd_x                                      0xF0D9B0
#define pinstCVoteResultsWnd_x                                     0xDAA510
#define pinstCVoteWnd_x                                            0xDAA4D0
#define pinstCWebManager_x                                         0xF0DB14
#define pinstCZoneGuideWnd_x                                       0xDAA5D4
#define pinstCZonePathWnd_x                                        0xDAA5F0

#define pinstEQSuiteTextureLoader_x                                0xC51C58
#define pinstItemIconCache_x                                       0x101C750
#define pinstLootFiltersManager_x                                  0xC77F30
#define pinstRewardSelectionWnd_x                                  0x10217E0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC02C3C
#define __CastRay_x                                                0x58DE40
#define __CastRay2_x                                               0x58DE90
#define __ConvertItemTags_x                                        0x5A8A20
#define __CrashHandler_x                                           0x83D8B0
#define __EQGetTime_x                                              0x8DB500
#define __ExecuteCmd_x                                             0x5867E0
#define __FixHeading_x                                             0x96BF50
#define __get_bearing_x                                            0x58D980
#define __get_melee_range_x                                        0x58E080
#define __GetAnimationCache_x                                      0x6FBAA0
#define __GetGaugeValueFromEQ_x                                    0x7EF0B0
#define __GetLabelFromEQ_x                                         0x7F0820
#define __GetXTargetType_x                                         0x96DA20
#define __HandleMouseWheel_x                                       0x697E50
#define __HeadingDiff_x                                            0x96BFC0
#define __HelpPath_x                                               0xF0AE64
#define __LoadFrontEnd_x                                           0x693C00
#define __NewUIINI_x                                               0x7EED80
#define __pCrashHandler_x                                          0x1040C60
#define __ProcessGameEvents_x                                      0x5EAF10
#define __ProcessMouseEvent_x                                      0x5EA6D0
#define __SaveColors_x                                             0x5384A0
#define __STMLToText_x                                             0x90F3D0
#define __ToggleKeyRingItem_x                                      0x4FB580
#define CrashDetected_x                                            0x6956F0
#define DrawNetStatus_x                                            0x616BC0
#define Expansion_HoT_x                                            0xE6CDDC
#define Teleport_Table_Size_x                                      0xE5E1D0
#define Teleport_Table_x                                           0xE5BFA8
#define Util__FastTime_x                                           0x8DB0C0
#define wwsCrashReportCheckForUploader_x                           0x83E350
#define wwsCrashReportPlatformLaunchUploader_x                     0x840A30

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48A8C0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4936C0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4934A0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x53FD50
#define AltAdvManager__IsAbilityReady_x                            0x53EDD0
#define AltAdvManager__GetAAById_x                                 0x53EFD0
#define AltAdvManager__CanTrainAbility_x                           0x53F040
#define AltAdvManager__CanSeeAbility_x                             0x53F270

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C66B0
#define CharacterZoneClient__HasSkill_x                            0x4D1250
#define CharacterZoneClient__MakeMeVisible_x                       0x4D2970
#define CharacterZoneClient__IsStackBlocked_x                      0x4BA9F0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B70B0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D50B0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D5190
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D5270
#define CharacterZoneClient__FindAffectSlot_x                      0x4BF620
#define CharacterZoneClient__BardCastBard_x                        0x4C22A0
#define CharacterZoneClient__GetMaxEffects_x                       0x4B7180
#define CharacterZoneClient__GetEffect_x                           0x4B6FF0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C0630
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C0700
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C0750
#define CharacterZoneClient__CalcAffectChange_x                    0x4C08A0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C0A70

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6BDFC0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6CB6E0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5F9290
#define CButtonWnd__CButtonWnd_x                                   0x90B7F0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6EA410
#define CChatManager__InitContextMenu_x                            0x6E4520
#define CChatManager__FreeChatWindow_x                             0x6E9330
#define CChatManager__GetLockedActiveChatWindow_x                  0x6EDCC0
#define CChatManager__SetLockedActiveChatWindow_x                  0x6EA1B0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x91FFD0
#define CContextMenu__dCContextMenu_x                              0x920200
#define CContextMenu__AddMenuItem_x                                0x920210
#define CContextMenu__RemoveMenuItem_x                             0x920520
#define CContextMenu__RemoveAllMenuItems_x                         0x920540
#define CContextMenu__CheckMenuItem_x                              0x9205C0
#define CContextMenu__SetMenuItem_x                                0x920440

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x920B60
#define CContextMenuManager__RemoveMenu_x                          0x920BD0
#define CContextMenuManager__PopupMenu_x                           0x920C90
#define CContextMenuManager__Flush_x                               0x920B00
#define CContextMenuManager__GetMenu_x                             0x495840

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8BBDC0
#define CChatService__GetFriendName_x                              0x8BBDD0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6EA980
#define CChatWindow__Clear_x                                       0x6EB9E0
#define CChatWindow__WndNotification_x                             0x6EBF50

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x91D450
#define CComboWnd__Draw_x                                          0x91C930
#define CComboWnd__GetCurChoice_x                                  0x91D290
#define CComboWnd__GetListRect_x                                   0x91CDF0
#define CComboWnd__GetTextRect_x                                   0x91D4C0
#define CComboWnd__InsertChoice_x                                  0x91CF80
#define CComboWnd__SetColors_x                                     0x91CF50
#define CComboWnd__SetChoice_x                                     0x91D260
#define CComboWnd__GetItemCount_x                                  0x91D2A0
#define CComboWnd__GetCurChoiceText_x                              0x91D2E0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6F3C50
#define CContainerWnd__vftable_x                                   0xAC9A60
#define CContainerWnd__SetContainer_x                              0x6F51C0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x538260
#define CDisplay__GetClickedActor_x                                0x52B2B0
#define CDisplay__GetUserDefinedColor_x                            0x523990
#define CDisplay__GetWorldFilePath_x                               0x52CD00
#define CDisplay__is3dON_x                                         0x527F80
#define CDisplay__ReloadUI_x                                       0x532420
#define CDisplay__WriteTextHD2_x                                   0x527D60
#define CDisplay__TrueDistance_x                                   0x52E960
#define CDisplay__SetViewActor_x                                   0x52AC00

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x93F990

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x9246E0
#define CEditWnd__GetCharIndexPt_x                                 0x9255E0
#define CEditWnd__GetDisplayString_x                               0x925480
#define CEditWnd__GetHorzOffset_x                                  0x923D10
#define CEditWnd__GetLineForPrintableChar_x                        0x926720
#define CEditWnd__GetSelStartPt_x                                  0x925890
#define CEditWnd__GetSTMLSafeText_x                                0x9252A0
#define CEditWnd__PointFromPrintableChar_x                         0x926350
#define CEditWnd__SelectableCharFromPoint_x                        0x9264C0
#define CEditWnd__SetEditable_x                                    0x925960

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5D9970
#define CEverQuest__ClickedPlayer_x                                0x5CBCC0
#define CEverQuest__CreateTargetIndicator_x                        0x5E81F0
#define CEverQuest__DeleteTargetIndicator_x                        0x5E8280
#define CEverQuest__DoTellWindow_x                                 0x4E1510
#define CEverQuest__OutputTextToLog_x                              0x4E1740
#define CEverQuest__DropHeldItemOnGround_x                         0x5C1580
#define CEverQuest__dsp_chat_x                                     0x4E1AD0
#define CEverQuest__trimName_x                                     0x5E47B0
#define CEverQuest__Emote_x                                        0x5DA180
#define CEverQuest__EnterZone_x                                    0x5D4360
#define CEverQuest__GetBodyTypeDesc_x                              0x5DE050
#define CEverQuest__GetClassDesc_x                                 0x5DE690
#define CEverQuest__GetClassThreeLetterCode_x                      0x5DEC90
#define CEverQuest__GetDeityDesc_x                                 0x5E6B40
#define CEverQuest__GetLangDesc_x                                  0x5DEE50
#define CEverQuest__GetRaceDesc_x                                  0x5DE670
#define CEverQuest__InterpretCmd_x                                 0x5E7110
#define CEverQuest__LeftClickedOnPlayer_x                          0x5C5770
#define CEverQuest__LMouseUp_x                                     0x5C3AF0
#define CEverQuest__RightClickedOnPlayer_x                         0x5C6050
#define CEverQuest__RMouseUp_x                                     0x5C4A80
#define CEverQuest__SetGameState_x                                 0x5C1310
#define CEverQuest__UPCNotificationFlush_x                         0x5E46B0
#define CEverQuest__IssuePetCommand_x                              0x5E0250
#define CEverQuest__ReportSuccessfulHit_x                          0x5DAEA0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x705CA0
#define CGaugeWnd__CalcLinesFillRect_x                             0x705D00
#define CGaugeWnd__Draw_x                                          0x7053A0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ABEE0
#define CGuild__GetGuildName_x                                     0x4AAF20
#define CGuild__GetGuildIndex_x                                    0x4AB2B0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x721000

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x72DF00
#define CInvSlotMgr__MoveItem_x                                    0x72CC20
#define CInvSlotMgr__SelectSlot_x                                  0x72DFD0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x72B4D0
#define CInvSlot__SliderComplete_x                                 0x729300
#define CInvSlot__GetItemBase_x                                    0x728C70
#define CInvSlot__UpdateItem_x                                     0x728DE0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x72F920
#define CInvSlotWnd__CInvSlotWnd_x                                 0x72EBF0
#define CInvSlotWnd__HandleLButtonUp_x                             0x72F4A0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7EB2B0
#define CItemDisplayWnd__UpdateStrings_x                           0x73D730
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x737720
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x737C10
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x73DCC0
#define CItemDisplayWnd__AboutToShow_x                             0x73D390
#define CItemDisplayWnd__WndNotification_x                         0x73EFE0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x822A80

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x743000

// CLabel 
#define CLabel__Draw_x                                             0x748AE0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8F5B40
#define CListWnd__dCListWnd_x                                      0x8F5E60
#define CListWnd__AddColumn_x                                      0x8FA180
#define CListWnd__AddColumn1_x                                     0x8FA1D0
#define CListWnd__AddLine_x                                        0x8FA560
#define CListWnd__AddString_x                                      0x8FA360
#define CListWnd__CalculateFirstVisibleLine_x                      0x8F9F40
#define CListWnd__CalculateVSBRange_x                              0x8F9D10
#define CListWnd__ClearSel_x                                       0x8FAD40
#define CListWnd__ClearAllSel_x                                    0x8FADA0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8FB7B0
#define CListWnd__Compare_x                                        0x8F9650
#define CListWnd__Draw_x                                           0x8F5F60
#define CListWnd__DrawColumnSeparators_x                           0x8F8730
#define CListWnd__DrawHeader_x                                     0x8F8B90
#define CListWnd__DrawItem_x                                       0x8F8F90
#define CListWnd__DrawLine_x                                       0x8F8890
#define CListWnd__DrawSeparator_x                                  0x8F87D0
#define CListWnd__EnableLine_x                                     0x8F8020
#define CListWnd__EnsureVisible_x                                  0x8FB6D0
#define CListWnd__ExtendSel_x                                      0x8FAC70
#define CListWnd__GetColumnMinWidth_x                              0x8F7B60
#define CListWnd__GetColumnWidth_x                                 0x8F7AD0
#define CListWnd__GetCurSel_x                                      0x8F7460
#define CListWnd__GetItemAtPoint_x                                 0x8F8290
#define CListWnd__GetItemAtPoint1_x                                0x8F8300
#define CListWnd__GetItemData_x                                    0x8F74E0
#define CListWnd__GetItemHeight_x                                  0x8F78A0
#define CListWnd__GetItemIcon_x                                    0x8F7670
#define CListWnd__GetItemRect_x                                    0x8F8110
#define CListWnd__GetItemText_x                                    0x8F7520
#define CListWnd__GetSelList_x                                     0x8FADF0
#define CListWnd__GetSeparatorRect_x                               0x8F8540
#define CListWnd__InsertLine_x                                     0x8FA950
#define CListWnd__RemoveLine_x                                     0x8FAAA0
#define CListWnd__SetColors_x                                      0x8F9CE0
#define CListWnd__SetColumnJustification_x                         0x8F9A10
#define CListWnd__SetColumnWidth_x                                 0x8F9930
#define CListWnd__SetCurSel_x                                      0x8FABB0
#define CListWnd__SetItemColor_x                                   0x8FB380
#define CListWnd__SetItemData_x                                    0x8FB340
#define CListWnd__SetItemText_x                                    0x8FAF70
#define CListWnd__ShiftColumnSeparator_x                           0x8F9AD0
#define CListWnd__Sort_x                                           0x8F97D0
#define CListWnd__ToggleSel_x                                      0x8FABE0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x75DF90

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7812E0
#define CMerchantWnd__RequestBuyItem_x                             0x781BC0
#define CMerchantWnd__RequestSellItem_x                            0x7820F0
#define CMerchantWnd__SelectRecoverySlot_x                         0x784F30
//did this get another arg?
#define CMerchantWnd__SelectBuySellSlot_x                          0x781940
#define CMerchantWnd__ActualSelect_x                               0x78AAA0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x889D60
#define CPacketScrambler__hton_x                                   0x889D50

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x9149C0
#define CSidlManager__FindScreenPieceTemplate_x                    0x914DD0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x914BC0
#define CSidlManager__CreateLabel_x                                0x7E26A0
#define CSidlManager__CreateXWndFromTemplate_x                     0x917EA0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x918080

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x911530
#define CSidlScreenWnd__CalculateVSBRange_x                        0x911430
#define CSidlScreenWnd__ConvertToRes_x                             0x9361C0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x910EC0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x910BB0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x910C80
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x910D50
#define CSidlScreenWnd__DrawSidlPiece_x                            0x9119C0
#define CSidlScreenWnd__EnableIniStorage_x                         0x911E90
#define CSidlScreenWnd__GetSidlPiece_x                             0x911BB0
#define CSidlScreenWnd__Init1_x                                    0x9107A0
#define CSidlScreenWnd__LoadIniInfo_x                              0x911EE0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x912A20
#define CSidlScreenWnd__LoadSidlScreen_x                           0x90FBB0
#define CSidlScreenWnd__StoreIniInfo_x                             0x912590
#define CSidlScreenWnd__StoreIniVis_x                              0x912900
#define CSidlScreenWnd__WndNotification_x                          0x9118D0
#define CSidlScreenWnd__GetChildItem_x                             0x911E10
#define CSidlScreenWnd__HandleLButtonUp_x                          0x901690
#define CSidlScreenWnd__m_layoutCopy_x                             0x169A7B8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x65D710
#define CSkillMgr__GetSkillCap_x                                   0x65D8F0
#define CSkillMgr__GetNameToken_x                                  0x65CEA0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x921960
#define CSliderWnd__SetValue_x                                     0x9217D0
#define CSliderWnd__SetNumTicks_x                                  0x921830

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7E8520

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x9285C0
#define CStmlWnd__CalculateHSBRange_x                              0x929630
#define CStmlWnd__CalculateVSBRange_x                              0x9295A0
#define CStmlWnd__CanBreakAtCharacter_x                            0x92D970
#define CStmlWnd__FastForwardToEndOfTag_x                          0x92E560
#define CStmlWnd__ForceParseNow_x                                  0x928B60
#define CStmlWnd__GetNextTagPiece_x                                0x92D8D0
#define CStmlWnd__GetSTMLText_x                                    0x4EF940
#define CStmlWnd__GetVisibleText_x                                 0x928B80
#define CStmlWnd__InitializeWindowVariables_x                      0x92E3B0
#define CStmlWnd__MakeStmlColorTag_x                               0x927D50
#define CStmlWnd__MakeWndNotificationTag_x                         0x927DC0
#define CStmlWnd__SetSTMLText_x                                    0x926E20
#define CStmlWnd__StripFirstSTMLLines_x                            0x92F6C0
#define CStmlWnd__UpdateHistoryString_x                            0x92E770

// CTabWnd 
#define CTabWnd__Draw_x                                            0x932D50
#define CTabWnd__DrawCurrentPage_x                                 0x933370
#define CTabWnd__DrawTab_x                                         0x933140
#define CTabWnd__GetCurrentPage_x                                  0x9325B0
#define CTabWnd__GetPageInnerRect_x                                0x9327F0
#define CTabWnd__GetTabInnerRect_x                                 0x932730
#define CTabWnd__GetTabRect_x                                      0x9325E0
#define CTabWnd__InsertPage_x                                      0x9329E0
#define CTabWnd__SetPage_x                                         0x932870
#define CTabWnd__SetPageRect_x                                     0x932C90
#define CTabWnd__UpdatePage_x                                      0x933000
#define CTabWnd__GetPageFromTabIndex_x                             0x933080
#define CTabWnd__GetCurrentTabIndex_x                              0x9325A0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x743460
#define CPageWnd__SetTabText_x                                     0x93FDA0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A5A40

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8FE4A0
#define CTextureFont__GetTextExtent_x                              0x8FE660

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x690A30
#define CHtmlComponentWnd__ValidateUri_x                           0x7229F0
#define CHtmlWnd__SetClientCallbacks_x                             0x5FE630
#define CHtmlWnd__AddObserver_x                                    0x5FE650
#define CHtmlWnd__RemoveObserver_x                                 0x5FE6B0
#define Window__getProgress_x                                      0x83B520
#define Window__getStatus_x                                        0x83B540
#define Window__getURI_x                                           0x83B550

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x93C320

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8EB360

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4AD200
#define CXStr__CXStr1_x                                            0x9ADC20
#define CXStr__CXStr3_x                                            0x8D75F0
#define CXStr__dCXStr_x                                            0x472340
#define CXStr__operator_equal_x                                    0x8D7820
#define CXStr__operator_equal1_x                                   0x8D7860
#define CXStr__operator_plus_equal1_x                              0x8D82F0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x91FBE0
#define CXWnd__BringToTop_x                                        0x904D70
#define CXWnd__Center_x                                            0x9048F0
#define CXWnd__ClrFocus_x                                          0x904720
#define CXWnd__Destroy_x                                           0x9047D0
#define CXWnd__DoAllDrawing_x                                      0x900E20
#define CXWnd__DrawChildren_x                                      0x900DF0
#define CXWnd__DrawColoredRect_x                                   0x901280
#define CXWnd__DrawTooltip_x                                       0x8FF930
#define CXWnd__DrawTooltipAtPoint_x                                0x8FF9F0
#define CXWnd__GetBorderFrame_x                                    0x9010E0
#define CXWnd__GetChildWndAt_x                                     0x904E10
#define CXWnd__GetClientClipRect_x                                 0x903070
#define CXWnd__GetScreenClipRect_x                                 0x903140
#define CXWnd__GetScreenRect_x                                     0x9032E0
#define CXWnd__GetTooltipRect_x                                    0x9012D0
#define CXWnd__GetWindowTextA_x                                    0x496F00
#define CXWnd__IsActive_x                                          0x907C80
#define CXWnd__IsDescendantOf_x                                    0x903CB0
#define CXWnd__IsReallyVisible_x                                   0x903CE0
#define CXWnd__IsType_x                                            0x905490
#define CXWnd__Move_x                                              0x903D40
#define CXWnd__Move1_x                                             0x903DF0
#define CXWnd__ProcessTransition_x                                 0x9048A0
#define CXWnd__Refade_x                                            0x9040A0
#define CXWnd__Resize_x                                            0x904370
#define CXWnd__Right_x                                             0x904B30
#define CXWnd__SetFocus_x                                          0x9046E0
#define CXWnd__SetFont_x                                           0x904750
#define CXWnd__SetKeyTooltip_x                                     0x9052A0
#define CXWnd__SetMouseOver_x                                      0x902220
#define CXWnd__StartFade_x                                         0x903B80
#define CXWnd__GetChildItem_x                                      0x904F80
#define CXWnd__SetParent_x                                         0x903A40

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x937290

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x907CC0
#define CXWndManager__DrawWindows_x                                0x907CE0
#define CXWndManager__GetKeyboardFlags_x                           0x90A460
#define CXWndManager__HandleKeyboardMsg_x                          0x90A060
#define CXWndManager__RemoveWnd_x                                  0x90A6A0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x90ABD0

// CDBStr
#define CDBStr__GetString_x                                        0x522910

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B8060
#define EQ_Character__Cur_HP_x                                     0x4CE2D0
#define EQ_Character__Cur_Mana_x                                   0x4D5770
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BB180
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AEE20
#define EQ_Character__GetFocusRangeModifier_x                      0x4AEF70
#define EQ_Character__GetHPRegen_x                                 0x4DAE50
#define EQ_Character__GetEnduranceRegen_x                          0x4DB460
#define EQ_Character__GetManaRegen_x                               0x4DB8A0
#define EQ_Character__Max_Endurance_x                              0x624410
#define EQ_Character__Max_HP_x                                     0x4CE100
#define EQ_Character__Max_Mana_x                                   0x624210
#define EQ_Character__doCombatAbility_x                            0x6265C0
#define EQ_Character__UseSkill_x                                   0x4DD690
#define EQ_Character__GetConLevel_x                                0x61D8D0
#define EQ_Character__IsExpansionFlag_x                            0x5850B0
#define EQ_Character__TotalEffect_x                                0x4C1820
#define EQ_Character__GetPCSpellAffect_x                           0x4BBD70
#define EQ_Character__SpellDuration_x                              0x4BB8A0
#define EQ_Character__FindItemByRecord_x                           0x4D38E0
#define EQ_Character__GetAdjustedSkill_x                           0x4D1010
#define EQ_Character__GetBaseSkill_x                               0x4D1FB0
#define EQ_Character__CanUseItem_x                                 0x4D5A80

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8A8E80

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x63A780

//PcClient
#define PcClient__PcClient_x                                       0x61B1A0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B5E30
#define CCharacterListWnd__EnterWorld_x                            0x4B5870
#define CCharacterListWnd__Quit_x                                  0x4B5580
#define CCharacterListWnd__UpdateList_x                            0x4B5A00

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x5FF850
#define EQ_Item__CreateItemTagString_x                             0x8840B0
#define EQ_Item__IsStackable_x                                     0x888250
#define EQ_Item__GetImageNum_x                                     0x885870
#define EQ_Item__CreateItemClient_x                                0x5FEA30
#define EQ_Item__GetItemValue_x                                    0x886920
#define EQ_Item__ValueSellMerchant_x                               0x889900
#define EQ_Item__IsKeyRingItem_x                                   0x887C10
#define EQ_Item__CanGoInBag_x                                      0x5FF970
#define EQ_Item__GetMaxItemCount_x                                 0x886A20
#define EQ_Item__GetHeldItem_x                                     0x885740
#define EQ_Item__GetAugmentFitBySlot_x                             0x883BF0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x540A70
#define EQ_LoadingS__Array_x                                       0xBDA2D0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x624D70
#define EQ_PC__GetAlternateAbilityId_x                             0x892B20
#define EQ_PC__GetCombatAbility_x                                  0x893190
#define EQ_PC__GetCombatAbilityTimer_x                             0x893200
#define EQ_PC__GetItemRecastTimer_x                                0x626B40
#define EQ_PC__HasLoreItem_x                                       0x61E090
#define EQ_PC__AlertInventoryChanged_x                             0x61D3B0
#define EQ_PC__GetPcZoneClient_x                                   0x648F60
#define EQ_PC__RemoveMyAffect_x                                    0x629C70
#define EQ_PC__GetKeyRingItems_x                                   0x893AA0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x893820
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x893D90

// EQItemList 
#define EQItemList__EQItemList_x                                   0x58B3F0
#define EQItemList__add_object_x                                   0x5B6CF0
#define EQItemList__add_item_x                                     0x58BA00
#define EQItemList__delete_item_x                                  0x58BA50
#define EQItemList__FreeItemList_x                                 0x58B950

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x51FE60

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x63C000
#define EQPlayer__dEQPlayer_x                                      0x62F2D0
#define EQPlayer__DoAttack_x                                       0x643C80
#define EQPlayer__EQPlayer_x                                       0x62F980
#define EQPlayer__SetNameSpriteState_x                             0x634030
#define EQPlayer__SetNameSpriteTint_x                              0x634F00
#define PlayerBase__HasProperty_j_x                                0x96A320
#define EQPlayer__IsTargetable_x                                   0x96A7C0
#define EQPlayer__CanSee_x                                         0x96A620
#define EQPlayer__CanSee1_x                                        0x96A6F0
#define PlayerBase__GetVisibilityLineSegment_x                     0x96A3E0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x646A50
#define PlayerZoneClient__GetLevel_x                               0x648FA0
#define PlayerZoneClient__IsValidTeleport_x                        0x5B7E40
#define PlayerZoneClient__LegalPlayerRace_x                        0x539FD0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x63ED80
#define EQPlayerManager__GetSpawnByName_x                          0x63EDA0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x63EE30

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x6030E0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x603120
#define KeypressHandler__ClearCommandStateArray_x                  0x604510
#define KeypressHandler__HandleKeyDown_x                           0x604530
#define KeypressHandler__HandleKeyUp_x                             0x6045D0
#define KeypressHandler__SaveKeymapping_x                          0x6049B0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x759E20
#define MapViewMap__SaveEx_x                                       0x75D1C0
#define MapViewMap__SetZoom_x                                      0x761890

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8A6D70

// StringTable 
#define StringTable__getString_x                                   0x8A1C60

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x6298E0
#define PcZoneClient__RemovePetEffect_x                            0x629F10
#define PcZoneClient__HasAlternateAbility_x                        0x624050
#define PcZoneClient__GetCurrentMod_x                              0x4E0600
#define PcZoneClient__GetModCap_x                                  0x4E0500
#define PcZoneClient__CanEquipItem_x                               0x624700
#define PcZoneClient__GetItemByID_x                                0x626FB0
#define PcZoneClient__GetItemByItemClass_x                         0x627040
#define PcZoneClient__RemoveBuffEffect_x                           0x629F30

//Doors
#define EQSwitch__UseSwitch_x                                      0x5BC9D0

//IconCache
#define IconCache__GetIcon_x                                       0x6FB330

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6F2DF0
#define CContainerMgr__CloseContainer_x                            0x6F30C0
#define CContainerMgr__OpenExperimentContainer_x                   0x6F3B40

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7B50D0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5F7A80

//CLootWnd
#define CLootWnd__LootAll_x                                        0x750210
#define CLootWnd__RequestLootSlot_x                                0x74F5D0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x558ED0
#define EQ_Spell__SpellAffects_x                                   0x559340
#define EQ_Spell__SpellAffectBase_x                                0x559100
#define EQ_Spell__IsStackable_x                                    0x4C5FD0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C5EB0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B3350
#define EQ_Spell__IsSPAStacking_x                                  0x55A170
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x559690
#define EQ_Spell__IsNoRemove_x                                     0x4C5FB0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x55A180
#define __IsResEffectSpell_x                                       0x4C5380

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4A9B80

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8B13B0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7FA5F0
#define CTargetWnd__WndNotification_x                              0x7F9E80
#define CTargetWnd__RefreshTargetBuffs_x                           0x7FA150
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x7F8FD0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7FECC0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x554450
#define EqSoundManager__PlayScriptMp3_x                            0x5545B0
#define EqSoundManager__SoundAssistPlay_x                          0x661230
#define EqSoundManager__WaveInstancePlay_x                         0x6607A0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x511820

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x923340

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x5486F0
#define CAltAbilityData__GetMercMaxRank_x                          0x548690
#define CAltAbilityData__GetMaxRank_x                              0x53DC80

//CTargetRing
#define CTargetRing__Cast_x                                        0x5F5B90

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C5E90
#define CharacterBase__CreateItemGlobalIndex_x                     0x4F7A50
#define CharacterBase__CreateItemIndex_x                           0x5FDC40
#define CharacterBase__GetItemPossession_x                         0x4B3200
#define CharacterBase__GetItemByGlobalIndex_x                      0x8B9900
#define CharacterBase__GetEffectId_x                               0x4C5E40

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6DAF90
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6DB7B0

//messages
#define msg_spell_worn_off_x                                       0x57D7D0
#define msg_new_text_x                                             0x572990
#define __msgTokenTextParam_x                                      0x57FE20
#define msgTokenText_x                                             0x580070

//SpellManager
#define SpellManager__vftable_x                                    0xAA4828
#define SpellManager__SpellManager_x                               0x664560
#define Spellmanager__LoadTextSpells_x                             0x664E30
#define SpellManager__GetSpellByGroupAndRank_x                     0x664730

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x96E310

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4F8130
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x583620
#define ItemGlobalIndex__IsEquippedLocation_x                      0x616A20
#define ItemGlobalIndex__IsValidIndex_x                            0x4F8190

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8B1CF0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8B1F70

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x748E30

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6F7550
#define CCursorAttachment__Deactivate_x                            0x6F8530

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9352C0
#define CEQSuiteTextureLoader__GetTexture_x                        0x934F80

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4F50D0

//IString
#define IString__Append_x                                          0x4E9980

//Camera
#define CDisplay__cameraType_x                                     0xDA9E08
#define EverQuest__Cameras_x                                       0xE6D114

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x4FD800
#define LootFiltersManager__GetItemFilterData_x                    0x4FD0F0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x4FD120
#define LootFiltersManager__SetItemLootFilter_x                    0x4FD340

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7A30D0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x974040
#define CResolutionHandler__GetWindowedStyle_x                     0x65C160

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6EFB30

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8C3CE0

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
#ifdef EMU
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\xFD\xFF\xFF\x8B\xCE\x5E\xE9\x00\x00\xFF\xFF\xC7\x01";
static char lpMask[] = "xxxx?xxxxxxx??xxxx";
#else
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
#endif
