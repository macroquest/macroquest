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
#define __ExpectedVersionDate                                     "Nov 22 2018"
#define __ExpectedVersionTime                                     "04:20:42"
#define __ActualVersionDate_x                                      0xACC014
#define __ActualVersionTime_x                                      0xACC008

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x6129C0
#define __MemChecker1_x                                            0x8E6CC0
#define __MemChecker2_x                                            0x6A1A80
#define __MemChecker3_x                                            0x6A19D0
#define __MemChecker4_x                                            0x83E030
#define __EncryptPad0_x                                            0xC00340
#define __EncryptPad1_x                                            0xC5E5D0
#define __EncryptPad2_x                                            0xC10EC8
#define __EncryptPad3_x                                            0xC10AC8
#define __EncryptPad4_x                                            0xC4EE40
#define __EncryptPad5_x                                            0x102F770
#define __AC1_x                                                    0x7FAA56
#define __AC2_x                                                    0x5CDB0F
#define __AC3_x                                                    0x5D499F
#define __AC4_x                                                    0x5D87C0
#define __AC5_x                                                    0x5DE97F
#define __AC6_x                                                    0x5E2EB6
#define __AC7_x                                                    0x5CD580
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1E96EE4

// Direct Input
#define DI8__Main_x                                                0x102F794
#define DI8__Keyboard_x                                            0x102F798
#define DI8__Mouse_x                                               0xF25498
#define DI8__Mouse_Copy_x                                          0xE83194
#define DI8__Mouse_Check_x                                         0x1030658
#define __AutoSkillArray_x                                         0xE840AC
#define __Attack_x                                                 0xF21EB3
#define __Autofire_x                                               0xF21EB4
#define __BindList_x                                               0xBEEF20
#define g_eqCommandStates_x                                        0xBEFC90
#define __Clicks_x                                                 0xE8324C
#define __CommandList_x                                            0xBF0848
#define __CurrentMapLabel_x                                        0x1037A5C
#define __CurrentSocial_x                                          0xBD9730
#define __DoAbilityList_x                                          0xEB99D4
#define __do_loot_x                                                0x59B290
#define __DrawHandler_x                                            0x16B4430
#define __GroupCount_x                                             0xE73442
#define __Guilds_x                                                 0xE799A0
#define __gWorld_x                                                 0xE75D1C
#define __HWnd_x                                                   0xF2549C
#define __heqmain_x                                                0x102F758
#define __InChatMode_x                                             0xE8317C
#define __LastTell_x                                               0xE850D0
#define __LMouseHeldTime_x                                         0xE832B8
#define __Mouse_x                                                  0x102F77C
#define __MouseLook_x                                              0xE83212
#define __MouseEventTime_x                                         0xF22968
#define __gpbCommandEvent_x                                        0xE75760
#define __NetStatusToggle_x                                        0xE83215
#define __PCNames_x                                                0xE8468C
#define __RangeAttackReady_x                                       0xE84390
#define __RMouseHeldTime_x                                         0xE832B4
#define __RunWalkState_x                                           0xE83180
#define __ScreenMode_x                                             0xDC1A68
#define __ScreenX_x                                                0xE83134
#define __ScreenY_x                                                0xE83130
#define __ScreenXMax_x                                             0xE83138
#define __ScreenYMax_x                                             0xE8313C
#define __ServerHost_x                                             0xE759B3
#define __ServerName_x                                             0xEB9994
#define __ShiftKeyDown_x                                           0xE8380C
#define __ShowNames_x                                              0xE8454C
#define __Socials_x                                                0xEB9A94
#define __SubscriptionType_x                                       0x10795AC
#define __TargetAggroHolder_x                                      0x103A418
#define __ZoneType_x                                               0xE83610
#define __GroupAggro_x                                             0x103A458
#define __LoginName_x                                              0x102FFEC
#define __Inviter_x                                                0xF21E30
#define __AttackOnAssist_x                                         0xE84508
#define __UseTellWindows_x                                         0xE84824
#define __gfMaxZoomCameraDistance_x                                0xAC1528
#define __gfMaxCameraDistance_x                                    0xAEE978
#define __pulAutoRun_x                                             0xE83230
#define __pulForward_x                                             0xE8485C
#define __pulBackward_x                                            0xE84860
#define __pulTurnRight_x                                           0xE84864
#define __pulTurnLeft_x                                            0xE84868
#define __pulStrafeLeft_x                                          0xE8486C
#define __pulStrafeRight_x                                         0xE84870
//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE75D38
#define instEQZoneInfo_x                                           0xE83408
#define instKeypressHandler_x                                      0xF22918
#define pinstActiveBanker_x                                        0xE75858
#define pinstActiveCorpse_x                                        0xE75850
#define pinstActiveGMaster_x                                       0xE75854
#define pinstActiveMerchant_x                                      0xE7584C
#define pinstAggroInfo_x                                           0xC74E08
#define pinstAltAdvManager_x                                       0xDC26D8
#define pinstAuraMgr_x                                             0xC90970
#define pinstBandageTarget_x                                       0xE75868
#define pinstCamActor_x                                            0xDC1A5C
#define pinstCDBStr_x                                              0xDC140C
#define pinstCDisplay_x                                            0xE75D14
#define pinstCEverQuest_x                                          0x102F8B0
#define pinstEverQuestInfo_x                                       0xE83128
#define pinstCharData_x                                            0xE75D24
#define pinstCharSpawn_x                                           0xE758A0
#define pinstControlledMissile_x                                   0xE75D20
#define pinstControlledPlayer_x                                    0xE758A0
#define pinstCResolutionHandler_x                                  0x16B4660
#define pinstCSidlManager_x                                        0x16B34F4
#define pinstCXWndManager_x                                        0x16B34E8
#define instDynamicZone_x                                          0xE79878
#define pinstDZMember_x                                            0xE79988
#define pinstDZTimerInfo_x                                         0xE7998C
#define pinstEQItemList_x                                          0xE71F28
#define pinstEQObjectList_x                                        0xE73118
#define instEQMisc_x                                               0xDC1348
#define pinstEQSoundManager_x                                      0xDC2F38
#define pinstEQSpellStrings_x                                      0xC82F40
#define instExpeditionLeader_x                                     0xE798C2
#define instExpeditionName_x                                       0xE79902
#define pinstGroup_x                                               0xE7343E
#define pinstImeManager_x                                          0x16B34EC
#define pinstLocalPlayer_x                                         0xE75848
#define pinstMercenaryData_x                                       0xF23114
#define pinstMercenaryStats_x                                      0x103A564
#define pinstMercAltAbilities_x                                    0xDC2CA8
#define pinstModelPlayer_x                                         0xE75860
#define pinstPCData_x                                              0xE75D24
#define pinstRealEstateItems_x                                     0xF245F8
#define pinstSkillMgr_x                                            0xF246C8
#define pinstSpawnManager_x                                        0xF23CB8
#define pinstSpellManager_x                                        0xF248A0
#define pinstSpellSets_x                                           0xF1AADC
#define pinstStringTable_x                                         0xE75638
#define pinstSwitchManager_x                                       0xE732D8
#define pinstTarget_x                                              0xE7589C
#define pinstTargetObject_x                                        0xE75CC8
#define pinstTargetSwitch_x                                        0xE75D2C
#define pinstTaskMember_x                                          0xDC11DC
#define pinstTrackTarget_x                                         0xE758B0
#define pinstTradeTarget_x                                         0xE7585C
#define instTributeActive_x                                        0xDC136D
#define pinstViewActor_x                                           0xDC1A58
#define pinstWorldData_x                                           0xE75768
#define pinstZoneAddr_x                                            0xE836A8
#define pinstPlayerPath_x                                          0xF23D50
#define pinstTargetIndicator_x                                     0xF24B08
#define pinstCTargetManager_x                                      0xF24BA0
#define EQObject_Top_x                                             0xE75844

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDC1518
#define pinstCAchievementsWnd_x                                    0xDC14CC
#define pinstCActionsWnd_x                                         0xDC19F4
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDC19E4
#define pinstCAdvancedLootWnd_x                                    0xDC1534
#define pinstCAdventureLeaderboardWnd_x                            0x1031230
#define pinstCAdventureRequestWnd_x                                0x10312E0
#define pinstCAdventureStatsWnd_x                                  0x1031390
#define pinstCAggroMeterWnd_x                                      0xDC1A98
#define pinstCAlarmWnd_x                                           0xDC1AB8
#define pinstCAlertHistoryWnd_x                                    0xDC1B1C
#define pinstCAlertStackWnd_x                                      0xDC1A7C
#define pinstCAlertWnd_x                                           0xDC1A8C
#define pinstCAltStorageWnd_x                                      0x10316F0
#define pinstCAudioTriggersWindow_x                                0xC75298
#define pinstCAuraWnd_x                                            0xDC1A94
#define pinstCAvaZoneWnd_x                                         0xDC1D20
#define pinstCBandolierWnd_x                                       0xDC1ADC
#define pinstCBankWnd_x                                            0xDC14C4
#define pinstCBarterMerchantWnd_x                                  0x1032930
#define pinstCBarterSearchWnd_x                                    0x10329E0
#define pinstCBarterWnd_x                                          0x1032A90
#define pinstCBazaarConfirmationWnd_x                              0xDC1A78
#define pinstCBazaarSearchWnd_x                                    0xDC1A30
#define pinstCBazaarWnd_x                                          0xDC1AD4
#define pinstCBlockedBuffWnd_x                                     0xDC14A8
#define pinstCBlockedPetBuffWnd_x                                  0xDC14D0
#define pinstCBodyTintWnd_x                                        0xDC1A3C
#define pinstCBookWnd_x                                            0xDC1B00
#define pinstCBreathWnd_x                                          0xDC1520
#define pinstCBuffWindowNORMAL_x                                   0xDC1D24
#define pinstCBuffWindowSHORT_x                                    0xDC1D28
#define pinstCBugReportWnd_x                                       0xDC1508
#define pinstCButtonWnd_x                                          0x16B3718
#define pinstCCastingWnd_x                                         0xDC1504
#define pinstCCastSpellWnd_x                                       0xDC1A44
//#define pinstCCharacterCreationWnd_x                             0xDAAE5C
#define pinstCCharacterListWnd_x                                   0xDC1524
#define pinstCChatWindowManager_x                                  0x1033550
#define pinstCClaimWnd_x                                           0x10336A8
#define pinstCColorPickerWnd_x                                     0xDC1554
#define pinstCCombatAbilityWnd_x                                   0xDC1AA4
#define pinstCCombatSkillsSelectWnd_x                              0xDC19EC
#define pinstCCompassWnd_x                                         0xDC1A24
#define pinstCConfirmationDialog_x                                 0x10385A8
#define pinstCContainerMgr_x                                       0xDC1AC0
#define pinstCContextMenuManager_x                                 0x16B34A8
#define pinstCCursorAttachment_x                                   0xDC14F8
#define pinstCDistillerInfo_x                                      0x1036FB4
#define pinstCDynamicZoneWnd_x                                     0x1033C70
#define pinstCEditLabelWnd_x                                       0xDC1B0C
#define pinstCEQMainWnd_x                                          0x1033EB8
#define pinstCEventCalendarWnd_x                                   0xDC1514
#define pinstCExtendedTargetWnd_x                                  0xDC1A84
#define pinstCFacePick_x                                           0xDC154C
#define pinstCFellowshipWnd_x                                      0x10340B8
#define pinstCFileSelectionWnd_x                                   0xDC152C
#define pinstCFindItemWnd_x                                        0xDC1AF4
#define pinstCFindLocationWnd_x                                    0x1034210
#define pinstCFriendsWnd_x                                         0xDC1A2C
#define pinstCGemsGameWnd_x                                        0xDC1A90
#define pinstCGiveWnd_x                                            0xDC1AF8
#define pinstCGroupSearchFiltersWnd_x                              0xDC1AB0
#define pinstCGroupSearchWnd_x                                     0x1034608
#define pinstCGroupWnd_x                                           0x10346B8
#define pinstCGuildBankWnd_x                                       0xE844EC
#define pinstCGuildCreationWnd_x                                   0x1034818
#define pinstCGuildMgmtWnd_x                                       0x10348C8
#define pinstCharacterCreation_x                                   0xDC1AA0
#define pinstCHelpWnd_x                                            0xDC1A4C
#define pinstCHeritageSelectionWnd_x                               0xDC15D4
#define pinstCHotButtonWnd_x                                       0x1036A20
#define pinstCHotButtonWnd1_x                                      0x1036A20
#define pinstCHotButtonWnd2_x                                      0x1036A24
#define pinstCHotButtonWnd3_x                                      0x1036A28
#define pinstCHotButtonWnd4_x                                      0x1036A2C
#define pinstCIconSelectionWnd_x                                   0xDC14E0
#define pinstCInspectWnd_x                                         0xDC14D4
#define pinstCInventoryWnd_x                                       0xDC1AE4
#define pinstCInvSlotMgr_x                                         0xDC1A74
#define pinstCItemDisplayManager_x                                 0x1036FB0
#define pinstCItemExpTransferWnd_x                                 0x10370E0
#define pinstCItemOverflowWnd_x                                    0xDC1A34
#define pinstCJournalCatWnd_x                                      0xDC1544
//#define pinstCJournalNPCWnd_x                                    0xDAB354
#define pinstCJournalTextWnd_x                                     0xDC150C
#define pinstCKeyRingWnd_x                                         0xDC1D3C
#define pinstCLargeDialogWnd_x                                     0x1039228
#define pinstCLayoutCopyWnd_x                                      0x1037430
#define pinstCLFGuildWnd_x                                         0x10374E0
#define pinstCLoadskinWnd_x                                        0xDC1A9C
#define pinstCLootFiltersCopyWnd_x                                 0xC912A0
#define pinstCLootFiltersWnd_x                                     0xDC1AA8
#define pinstCLootSettingsWnd_x                                    0xDC1AC8
#define pinstCLootWnd_x                                            0xDC153C
#define pinstCMailAddressBookWnd_x                                 0xDC14D8
#define pinstCMailCompositionWnd_x                                 0xDC14B4
#define pinstCMailIgnoreListWnd_x                                  0xDC14DC
#define pinstCMailWnd_x                                            0xDC1D2C
#define pinstCManageLootWnd_x                                      0xDC2B50
#define pinstCMapToolbarWnd_x                                      0xDC1AE8
#define pinstCMapViewWnd_x                                         0xDC1AC4
#define pinstCMarketplaceWnd_x                                     0xDC151C
#define pinstCMerchantWnd_x                                        0xDC19E8
#define pinstCMIZoneSelectWnd_x                                    0x1037D18
#define pinstCMusicPlayerWnd_x                                     0xDC1D38
#define pinstCNameChangeMercWnd_x                                  0xDC1A40
#define pinstCNameChangePetWnd_x                                   0xDC1A14
#define pinstCNameChangeWnd_x                                      0xDC14FC
#define pinstCNoteWnd_x                                            0xDC1A48
#define pinstCObjectPreviewWnd_x                                   0xDC1540
#define pinstCOptionsWnd_x                                         0xDC1AEC
#define pinstCPetInfoWnd_x                                         0xDC14B8
#define pinstCPetitionQWnd_x                                       0xDC1550
//#define pinstCPlayerCustomizationWnd_x                             0xDAADC4
#define pinstCPlayerNotesWnd_x                                     0xDC1A38
#define pinstCPlayerWnd_x                                          0xDC1A1C
#define pinstCPopupWndManager_x                                    0x10385A8
#define pinstCProgressionSelectionWnd_x                            0x1038658
#define pinstCPurchaseGroupWnd_x                                   0xDC19DC
#define pinstCPurchaseWnd_x                                        0xDC1548
#define pinstCPvPLeaderboardWnd_x                                  0x1038708
#define pinstCPvPStatsWnd_x                                        0x10387B8
#define pinstCQuantityWnd_x                                        0xDC14EC
#define pinstCRaceChangeWnd_x                                      0xDC1528
#define pinstCRaidOptionsWnd_x                                     0xDC1ABC
#define pinstCRaidWnd_x                                            0xDC14F0
#define pinstCRealEstateItemsWnd_x                                 0xDC14E4
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDC1510
#define pinstCRealEstateManageWnd_x                                0xDC1AE0
#define pinstCRealEstateNeighborhoodWnd_x                          0xDC1B04
#define pinstCRealEstatePlotSearchWnd_x                            0xDC1D30
#define pinstCRealEstatePurchaseWnd_x                              0xDC14BC
#define pinstCRespawnWnd_x                                         0xDC1AAC
//#define pinstCRewardSelectionWnd_x                               0x1022600
#define pinstCSelectorWnd_x                                        0xDC1A88
#define pinstCSendMoneyWnd_x                                       0xDC1B10
#define pinstCServerListWnd_x                                      0xDC1B14
#define pinstCSkillsSelectWnd_x                                    0xDC155C
#define pinstCSkillsWnd_x                                          0xDC1538
#define pinstCSocialEditWnd_x                                      0xDC14F4
#define pinstCSocialWnd_x                                          0xDC1A50
#define pinstCSpellBookWnd_x                                       0xDC1A80
#define pinstCStoryWnd_x                                           0xDC19F0
#define pinstCTargetOfTargetWnd_x                                  0x103A5E8
#define pinstCTargetWnd_x                                          0xDC14B0
#define pinstCTaskOverlayWnd_x                                     0xDC1D34
#define pinstCTaskSelectWnd_x                                      0x103A740
#define pinstCTaskManager_x                                        0xC91AA0
#define pinstCTaskTemplateSelectWnd_x                              0x103A7F0
#define pinstCTaskWnd_x                                            0x103A8A0
#define pinstCTextEntryWnd_x                                       0xDC1A28
#define pinstCTextOverlay_x                                        0xC755A8
#define pinstCTimeLeftWnd_x                                        0xDC1530
#define pinstCTipWndCONTEXT_x                                      0x103AAA4
#define pinstCTipWndOFDAY_x                                        0x103AAA0
#define pinstCTitleWnd_x                                           0x103AB50
#define pinstCTrackingWnd_x                                        0xDC14AC
#define pinstCTradeskillWnd_x                                      0x103ACB8
#define pinstCTradeWnd_x                                           0xDC1A54
#define pinstCTrainWnd_x                                           0xDC14E8
#define pinstCTributeBenefitWnd_x                                  0x103AEB8
#define pinstCTributeMasterWnd_x                                   0x103AF68
#define pinstCTributeTrophyWnd_x                                   0x103B018
#define pinstCVideoModesWnd_x                                      0xDC1AB4
#define pinstCVoiceMacroWnd_x                                      0xF250D0
#define pinstCVoteResultsWnd_x                                     0xDC19E0
#define pinstCVoteWnd_x                                            0xDC1558
#define pinstCWebManager_x                                         0xF25234
#define pinstCZoneGuideWnd_x                                       0xDC1AF0
#define pinstCZonePathWnd_x                                        0xDC1B08

#define pinstEQSuiteTextureLoader_x                                0xC600A0
#define pinstItemIconCache_x                                       0x1033E70
#define pinstLootFiltersManager_x                                  0xC91350
#define pinstRewardSelectionWnd_x                                  0x1038F00

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC10ABC
#define __CastRay_x                                                0x5967B0
#define __CastRay2_x                                               0x596800
#define __ConvertItemTags_x                                        0x5B13B0
#define __CrashHandler_x                                           0x8479A0
#define __EQGetTime_x                                              0x8E67B0
#define __ExecuteCmd_x                                             0x58F160
#define __FixHeading_x                                             0x976F00
#define __get_bearing_x                                            0x596300
#define __get_melee_range_x                                        0x5969F0
#define __GetAnimationCache_x                                      0x705260
#define __GetGaugeValueFromEQ_x                                    0x7F9270
#define __GetLabelFromEQ_x                                         0x7FA9E0
#define __GetXTargetType_x                                         0x978960
#define __HeadingDiff_x                                            0x976F70
#define __HelpPath_x                                               0xF22584
#define __LoadFrontEnd_x                                           0x69D8E0
#define __NewUIINI_x                                               0x7F8F40
#define __pCrashHandler_x                                          0x1058408
#define __ProcessGameEvents_x                                      0x5F40E0
#define __ProcessMouseEvent_x                                      0x5F38A0
#define __SaveColors_x                                             0x540020
#define __STMLToText_x                                             0x91A3B0
#define __ToggleKeyRingItem_x                                      0x502FA0
#define CrashDetected_x                                            0x69F3D0
#define DrawNetStatus_x                                            0x61FE00
#define Expansion_HoT_x                                            0xE844F4
#define Teleport_Table_Size_x                                      0xE75804
#define Teleport_Table_x                                           0xE73638
#define Util__FastTime_x                                           0x8E6370
#define wwsCrashReportCheckForUploader_x                           0x848740
#define wwsCrashReportPlatformLaunchUploader_x                     0x84AE10
#define __HandleMouseWheel_x                                       0x6A1B30

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48B4C0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x494330
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4940F0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x547AF0
#define AltAdvManager__IsAbilityReady_x                            0x546A40
#define AltAdvManager__GetAAById_x                                 0x546C40
#define AltAdvManager__CanTrainAbility_x                           0x546CB0
#define AltAdvManager__CanSeeAbility_x                             0x547010

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C7170
#define CharacterZoneClient__HasSkill_x                            0x4D1E30
#define CharacterZoneClient__MakeMeVisible_x                       0x4D3550
#define CharacterZoneClient__IsStackBlocked_x                      0x4BB550
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B7CD0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D5F10
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D5FF0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D60D0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C0030
#define CharacterZoneClient__BardCastBard_x                        0x4C2C90
#define CharacterZoneClient__GetMaxEffects_x                       0x4B7DA0
#define CharacterZoneClient__GetEffect_x                           0x4B7C10
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C1030
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C1100
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C1150
#define CharacterZoneClient__CalcAffectChange_x                    0x4C12A0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C1470

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6C7740

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6D4FA0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x6027A0
#define CButtonWnd__CButtonWnd_x                                   0x9167D0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6F3CB0
#define CChatManager__InitContextMenu_x                            0x6EDD50
#define CChatManager__FreeChatWindow_x                             0x6F2BC0
#define CChatManager__GetLockedActiveChatWindow_x                  0x6F7560
#define CChatManager__SetLockedActiveChatWindow_x                  0x6F3A50

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x92AF70
#define CContextMenu__dCContextMenu_x                              0x92B1A0
#define CContextMenu__AddMenuItem_x                                0x92B1B0
#define CContextMenu__RemoveMenuItem_x                             0x92B4B0
#define CContextMenu__RemoveAllMenuItems_x                         0x92B4D0
#define CContextMenu__CheckMenuItem_x                              0x92B550
#define CContextMenu__SetMenuItem_x                                0x92B3E0
#define CContextMenu__AddSeparator_x                               0x92B340

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x92BAF0
#define CContextMenuManager__RemoveMenu_x                          0x92BB60
#define CContextMenuManager__PopupMenu_x                           0x92BC20
#define CContextMenuManager__Flush_x                               0x92BA90
#define CContextMenuManager__GetMenu_x                             0x496550

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8C7170
#define CChatService__GetFriendName_x                              0x8C7180

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6F4220
#define CChatWindow__Clear_x                                       0x6F5270
#define CChatWindow__WndNotification_x                             0x6F57E0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x928410
#define CComboWnd__Draw_x                                          0x927920
#define CComboWnd__GetCurChoice_x                                  0x928250
#define CComboWnd__GetListRect_x                                   0x927DC0
#define CComboWnd__GetTextRect_x                                   0x928470
#define CComboWnd__InsertChoice_x                                  0x927F50
#define CComboWnd__SetColors_x                                     0x927F20
#define CComboWnd__SetChoice_x                                     0x928220
#define CComboWnd__GetItemCount_x                                  0x928260
#define CComboWnd__GetCurChoiceText_x                              0x9282A0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6FD440
#define CContainerWnd__vftable_x                                   0xAD52C0
#define CContainerWnd__SetContainer_x                              0x6FE9B0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x53FDE0
#define CDisplay__GetClickedActor_x                                0x532DA0
#define CDisplay__GetUserDefinedColor_x                            0x52B480
#define CDisplay__GetWorldFilePath_x                               0x5347F0
#define CDisplay__is3dON_x                                         0x52FA70
#define CDisplay__ReloadUI_x                                       0x539F10
#define CDisplay__WriteTextHD2_x                                   0x52F850
#define CDisplay__TrueDistance_x                                   0x536450
#define CDisplay__SetViewActor_x                                   0x5326F0
#define CDisplay__GetFloorHeight_x                                 0x52FB30
#define CDisplay__SetRenderWindow_x                                0x52E460
#define CDisplay__ToggleScreenshotMode_x                           0x5321C0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x94A540

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x92F620
#define CEditWnd__GetCharIndexPt_x                                 0x930510
#define CEditWnd__GetDisplayString_x                               0x9303B0
#define CEditWnd__GetHorzOffset_x                                  0x92EC60
#define CEditWnd__GetLineForPrintableChar_x                        0x931640
#define CEditWnd__GetSelStartPt_x                                  0x9307B0
#define CEditWnd__GetSTMLSafeText_x                                0x9301D0
#define CEditWnd__PointFromPrintableChar_x                         0x931270
#define CEditWnd__SelectableCharFromPoint_x                        0x9313E0
#define CEditWnd__SetEditable_x                                    0x930880

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5E23E0
#define CEverQuest__ClickedPlayer_x                                0x5D4780
#define CEverQuest__CreateTargetIndicator_x                        0x5F1390
#define CEverQuest__DeleteTargetIndicator_x                        0x5F1420
#define CEverQuest__DoTellWindow_x                                 0x4E3060
#define CEverQuest__OutputTextToLog_x                              0x4E3290
#define CEverQuest__DropHeldItemOnGround_x                         0x5CA040
#define CEverQuest__dsp_chat_x                                     0x4E3620
#define CEverQuest__trimName_x                                     0x5ED900
#define CEverQuest__Emote_x                                        0x5E2BF0
#define CEverQuest__EnterZone_x                                    0x5DCDD0
#define CEverQuest__GetBodyTypeDesc_x                              0x5E71A0
#define CEverQuest__GetClassDesc_x                                 0x5E77E0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5E7DE0
#define CEverQuest__GetDeityDesc_x                                 0x5EFCE0
#define CEverQuest__GetLangDesc_x                                  0x5E7FA0
#define CEverQuest__GetRaceDesc_x                                  0x5E77C0
#define CEverQuest__InterpretCmd_x                                 0x5F02B0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5CE230
#define CEverQuest__LMouseUp_x                                     0x5CC5B0
#define CEverQuest__RightClickedOnPlayer_x                         0x5CEB10
#define CEverQuest__RMouseUp_x                                     0x5CD540
#define CEverQuest__SetGameState_x                                 0x5C9DD0
#define CEverQuest__UPCNotificationFlush_x                         0x5ED800
#define CEverQuest__IssuePetCommand_x                              0x5E93A0
#define CEverQuest__ReportSuccessfulHit_x                          0x5E3FF0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x70F400
#define CGaugeWnd__CalcLinesFillRect_x                             0x70F460
#define CGaugeWnd__Draw_x                                          0x70EAF0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AC900
#define CGuild__GetGuildName_x                                     0x4AB9E0
#define CGuild__GetGuildIndex_x                                    0x4ABD70

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x72A7B0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x602B60

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x737700
#define CInvSlotMgr__MoveItem_x                                    0x736460
#define CInvSlotMgr__SelectSlot_x                                  0x7377D0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x734D10
#define CInvSlot__SliderComplete_x                                 0x732A70
#define CInvSlot__GetItemBase_x                                    0x732400
#define CInvSlot__UpdateItem_x                                     0x732570

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x739100
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7383D0
#define CInvSlotWnd__HandleLButtonUp_x                             0x738C80

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7F5460
#define CItemDisplayWnd__UpdateStrings_x                           0x747260
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x741220
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x741740
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x747870
#define CItemDisplayWnd__AboutToShow_x                             0x746EC0
#define CItemDisplayWnd__WndNotification_x                         0x748DA0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x82CE60

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x74CF00

// CLabel 
#define CLabel__Draw_x                                             0x7529E0

// CListWnd
#define CListWnd__CListWnd_x                                       0x900CA0
#define CListWnd__dCListWnd_x                                      0x900FB0
#define CListWnd__AddColumn_x                                      0x9052A0
#define CListWnd__AddColumn1_x                                     0x9052F0
#define CListWnd__AddLine_x                                        0x905680
#define CListWnd__AddString_x                                      0x905480
#define CListWnd__CalculateFirstVisibleLine_x                      0x905070
#define CListWnd__CalculateVSBRange_x                              0x904E50
#define CListWnd__ClearSel_x                                       0x905E60
#define CListWnd__ClearAllSel_x                                    0x905EC0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x9068A0
#define CListWnd__Compare_x                                        0x9047A0
#define CListWnd__Draw_x                                           0x9010B0
#define CListWnd__DrawColumnSeparators_x                           0x903880
#define CListWnd__DrawHeader_x                                     0x903CF0
#define CListWnd__DrawItem_x                                       0x9040E0
#define CListWnd__DrawLine_x                                       0x9039F0
#define CListWnd__DrawSeparator_x                                  0x903920
#define CListWnd__EnableLine_x                                     0x903160
#define CListWnd__EnsureVisible_x                                  0x9067E0
#define CListWnd__ExtendSel_x                                      0x905D90
#define CListWnd__GetColumnMinWidth_x                              0x902CA0
#define CListWnd__GetColumnWidth_x                                 0x902C10
#define CListWnd__GetCurSel_x                                      0x9025A0
#define CListWnd__GetItemAtPoint_x                                 0x9033D0
#define CListWnd__GetItemAtPoint1_x                                0x903440
#define CListWnd__GetItemData_x                                    0x902620
#define CListWnd__GetItemHeight_x                                  0x9029E0
#define CListWnd__GetItemIcon_x                                    0x9027B0
#define CListWnd__GetItemRect_x                                    0x903250
#define CListWnd__GetItemText_x                                    0x902660
#define CListWnd__GetSelList_x                                     0x905F10
#define CListWnd__GetSeparatorRect_x                               0x903680
#define CListWnd__InsertLine_x                                     0x905A70
#define CListWnd__RemoveLine_x                                     0x905BC0
#define CListWnd__SetColors_x                                      0x904E30
#define CListWnd__SetColumnJustification_x                         0x904B60
#define CListWnd__SetColumnWidth_x                                 0x904A80
#define CListWnd__SetCurSel_x                                      0x905CD0
#define CListWnd__SetItemColor_x                                   0x9064A0
#define CListWnd__SetItemData_x                                    0x906460
#define CListWnd__SetItemText_x                                    0x906090
#define CListWnd__ShiftColumnSeparator_x                           0x904C20
#define CListWnd__Sort_x                                           0x904920
#define CListWnd__ToggleSel_x                                      0x905D00

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x767F30
#define CMapViewWnd__GetWorldCoordinates_x                         0x766640
#define CMapViewWnd__HandleLButtonDown_x                           0x7636A0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x78B080
// CMerchantWnd__RequestBuyItem_x                             
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x78B960
// CMerchantWnd__RequestSellItem_x
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x78BE90
#define CMerchantWnd__SelectRecoverySlot_x                         0x78ECC0
//CMerchantWnd__SelectBuySellSlot_x before
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x789A60
//CMerchantWnd__ActualSelect_x
#define CMerchantWnd__SelectBuySellSlot_x                          0x7948C0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x78ACB0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x894F20
#define CPacketScrambler__hton_x                                   0x894F10

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x91F960
#define CSidlManager__FindScreenPieceTemplate_x                    0x91FD70
#define CSidlManager__FindScreenPieceTemplate1_x                   0x91FB60
#define CSidlManager__CreateLabel_x                                0x7EC890
#define CSidlManager__CreateXWndFromTemplate_x                     0x922E40
#define CSidlManager__CreateXWndFromTemplate1_x                    0x923020
#define CSidlManager__CreateXWnd_x                                 0x7EC7C0
#define CSidlManager__CreateHotButtonWnd_x                         0x7ECD90

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x91C510
#define CSidlScreenWnd__CalculateVSBRange_x                        0x91C410
#define CSidlScreenWnd__ConvertToRes_x                             0x941340
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x91BEA0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x91BB90
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x91BC60
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x91BD30
#define CSidlScreenWnd__DrawSidlPiece_x                            0x91C9A0
#define CSidlScreenWnd__EnableIniStorage_x                         0x91CE70
#define CSidlScreenWnd__GetSidlPiece_x                             0x91CB90
#define CSidlScreenWnd__Init1_x                                    0x91B780
#define CSidlScreenWnd__LoadIniInfo_x                              0x91CEC0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x91D9D0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x91AB90
#define CSidlScreenWnd__StoreIniInfo_x                             0x91D560
#define CSidlScreenWnd__StoreIniVis_x                              0x91D8B0
#define CSidlScreenWnd__WndNotification_x                          0x91C8B0
#define CSidlScreenWnd__GetChildItem_x                             0x91CDF0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x90C630
#define CSidlScreenWnd__m_layoutCopy_x                             0x16B3378

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x666AF0
#define CSkillMgr__GetSkillCap_x                                   0x666CD0
#define CSkillMgr__GetNameToken_x                                  0x666280

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x92C8C0
#define CSliderWnd__SetValue_x                                     0x92C730
#define CSliderWnd__SetNumTicks_x                                  0x92C790

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7F26D0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x9334E0
#define CStmlWnd__CalculateHSBRange_x                              0x934550
#define CStmlWnd__CalculateVSBRange_x                              0x9344C0
#define CStmlWnd__CanBreakAtCharacter_x                            0x938890
#define CStmlWnd__FastForwardToEndOfTag_x                          0x939480
#define CStmlWnd__ForceParseNow_x                                  0x933A80
#define CStmlWnd__GetNextTagPiece_x                                0x9387F0
#define CStmlWnd__GetSTMLText_x                                    0x4F4800
#define CStmlWnd__GetVisibleText_x                                 0x933AA0
#define CStmlWnd__InitializeWindowVariables_x                      0x9392D0
#define CStmlWnd__MakeStmlColorTag_x                               0x932C70
#define CStmlWnd__MakeWndNotificationTag_x                         0x932CE0
#define CStmlWnd__SetSTMLText_x                                    0x931D40
#define CStmlWnd__StripFirstSTMLLines_x                            0x93A5D0
#define CStmlWnd__UpdateHistoryString_x                            0x939690

// CTabWnd 
#define CTabWnd__Draw_x                                            0x93E290
#define CTabWnd__DrawCurrentPage_x                                 0x93E8B0
#define CTabWnd__DrawTab_x                                         0x93E680
#define CTabWnd__GetCurrentPage_x                                  0x93DAF0
#define CTabWnd__GetPageInnerRect_x                                0x93DD30
#define CTabWnd__GetTabInnerRect_x                                 0x93DC70
#define CTabWnd__GetTabRect_x                                      0x93DB20
#define CTabWnd__InsertPage_x                                      0x93DF20
#define CTabWnd__SetPage_x                                         0x93DDB0
#define CTabWnd__SetPageRect_x                                     0x93E1D0
#define CTabWnd__UpdatePage_x                                      0x93E540
#define CTabWnd__GetPageFromTabIndex_x                             0x93E5C0
#define CTabWnd__GetCurrentTabIndex_x                              0x93DAE0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x74D360
#define CPageWnd__SetTabText_x                                     0x94A950

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A64B0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x9094B0
#define CTextureFont__GetTextExtent_x                              0x909670

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x69A720
#define CHtmlComponentWnd__ValidateUri_x                           0x72C1A0
#define CHtmlWnd__SetClientCallbacks_x                             0x607B50
#define CHtmlWnd__AddObserver_x                                    0x607B70
#define CHtmlWnd__RemoveObserver_x                                 0x607BD0
#define Window__getProgress_x                                      0x845610
#define Window__getStatus_x                                        0x845630
#define Window__getURI_x                                           0x845640

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x946ED0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8F6470

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4ADBA0
#define CXStr__CXStr1_x                                            0x8FEF60
#define CXStr__CXStr3_x                                            0x8E28E0
#define CXStr__dCXStr_x                                            0x472E00
#define CXStr__operator_equal_x                                    0x8E2B10
#define CXStr__operator_equal1_x                                   0x8E2B50
#define CXStr__operator_plus_equal1_x                              0x8E35E0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x92AB90
#define CXWnd__BringToTop_x                                        0x90FDA0
#define CXWnd__Center_x                                            0x90F920
#define CXWnd__ClrFocus_x                                          0x90F760
#define CXWnd__Destroy_x                                           0x90F800
#define CXWnd__DoAllDrawing_x                                      0x90BDE0
#define CXWnd__DrawChildren_x                                      0x90BDB0
#define CXWnd__DrawColoredRect_x                                   0x90C240
#define CXWnd__DrawTooltip_x                                       0x90A910
#define CXWnd__DrawTooltipAtPoint_x                                0x90A9D0
#define CXWnd__GetBorderFrame_x                                    0x90C0A0
#define CXWnd__GetChildWndAt_x                                     0x90FE40
#define CXWnd__GetClientClipRect_x                                 0x90E040
#define CXWnd__GetScreenClipRect_x                                 0x90E110
#define CXWnd__GetScreenRect_x                                     0x90E2E0
#define CXWnd__GetTooltipRect_x                                    0x90C290
#define CXWnd__GetWindowTextA_x                                    0x497CD0
#define CXWnd__IsActive_x                                          0x912CE0
#define CXWnd__IsDescendantOf_x                                    0x90ECD0
#define CXWnd__IsReallyVisible_x                                   0x90ED00
#define CXWnd__IsType_x                                            0x9104C0
#define CXWnd__Move_x                                              0x90ED80
#define CXWnd__Move1_x                                             0x90EE30
#define CXWnd__ProcessTransition_x                                 0x90F8D0
#define CXWnd__Refade_x                                            0x90F100
#define CXWnd__Resize_x                                            0x90F380
#define CXWnd__Right_x                                             0x90FB60
#define CXWnd__SetFocus_x                                          0x90F720
#define CXWnd__SetFont_x                                           0x90F790
#define CXWnd__SetKeyTooltip_x                                     0x9102D0
#define CXWnd__SetMouseOver_x                                      0x90D1B0
#define CXWnd__StartFade_x                                         0x90EBB0
#define CXWnd__GetChildItem_x                                      0x90FFB0
#define CXWnd__SetParent_x                                         0x90EA80

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x942410

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x912D20
#define CXWndManager__DrawWindows_x                                0x912D40
#define CXWndManager__GetKeyboardFlags_x                           0x915450
#define CXWndManager__HandleKeyboardMsg_x                          0x915050
#define CXWndManager__RemoveWnd_x                                  0x9156A0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x915BF0

// CDBStr
#define CDBStr__GetString_x                                        0x52A450

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B8C80
#define EQ_Character__Cur_HP_x                                     0x4CEEB0
#define EQ_Character__Cur_Mana_x                                   0x4D65D0
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BBB90
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AF790
#define EQ_Character__GetFocusRangeModifier_x                      0x4AF8E0
#define EQ_Character__GetHPRegen_x                                 0x4DC530
#define EQ_Character__GetEnduranceRegen_x                          0x4DCB40
#define EQ_Character__GetManaRegen_x                               0x4DCF80
#define EQ_Character__Max_Endurance_x                              0x62D570
#define EQ_Character__Max_HP_x                                     0x4CECE0
#define EQ_Character__Max_Mana_x                                   0x62D370
#define EQ_Character__doCombatAbility_x                            0x62FA40
#define EQ_Character__UseSkill_x                                   0x4DED90
#define EQ_Character__GetConLevel_x                                0x626B60
#define EQ_Character__IsExpansionFlag_x                            0x58D920
#define EQ_Character__TotalEffect_x                                0x4C2210
#define EQ_Character__GetPCSpellAffect_x                           0x4BC780
#define EQ_Character__SpellDuration_x                              0x4BC2B0
#define EQ_Character__FindItemByRecord_x                           0x4D44C0
#define EQ_Character__GetAdjustedSkill_x                           0x4D1BF0
#define EQ_Character__GetBaseSkill_x                               0x4D2B90
#define EQ_Character__CanUseItem_x                                 0x4D68E0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8B4060

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x643810

//PcClient
#define PcClient__PcClient_x                                       0x624430

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6900
#define CCharacterListWnd__EnterWorld_x                            0x4B6340
#define CCharacterListWnd__Quit_x                                  0x4B6050
#define CCharacterListWnd__UpdateList_x                            0x4B64D0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x608D70
#define EQ_Item__CreateItemTagString_x                             0x88E8B0
#define EQ_Item__IsStackable_x                                     0x8932F0
#define EQ_Item__GetImageNum_x                                     0x890300
#define EQ_Item__CreateItemClient_x                                0x607F30
#define EQ_Item__GetItemValue_x                                    0x891570
#define EQ_Item__ValueSellMerchant_x                               0x894AC0
#define EQ_Item__IsKeyRingItem_x                                   0x892C50
#define EQ_Item__CanGoInBag_x                                      0x608E90
#define EQ_Item__GetMaxItemCount_x                                 0x891930
#define EQ_Item__GetHeldItem_x                                     0x8901D0
#define EQ_Item__GetAugmentFitBySlot_x                             0x88E210

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x5487D0
#define EQ_LoadingS__Array_x                                       0xBE8130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x62DED0
#define EQ_PC__GetAlternateAbilityId_x                             0x89DD90
#define EQ_PC__GetCombatAbility_x                                  0x89E400
#define EQ_PC__GetCombatAbilityTimer_x                             0x89E470
#define EQ_PC__GetItemRecastTimer_x                                0x62FFC0
#define EQ_PC__HasLoreItem_x                                       0x627330
#define EQ_PC__AlertInventoryChanged_x                             0x626630
#define EQ_PC__GetPcZoneClient_x                                   0x652080
#define EQ_PC__RemoveMyAffect_x                                    0x6331B0
#define EQ_PC__GetKeyRingItems_x                                   0x89ED10
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x89EA90
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x89F000

// EQItemList 
#define EQItemList__EQItemList_x                                   0x593D80
#define EQItemList__add_object_x                                   0x5BF6D0
#define EQItemList__add_item_x                                     0x594390
#define EQItemList__delete_item_x                                  0x5943E0
#define EQItemList__FreeItemList_x                                 0x5942E0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x527980

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x645090
#define EQPlayer__dEQPlayer_x                                      0x6387C0
#define EQPlayer__DoAttack_x                                       0x64CD60
#define EQPlayer__EQPlayer_x                                       0x638E70
#define EQPlayer__SetNameSpriteState_x                             0x63D0D0
#define EQPlayer__SetNameSpriteTint_x                              0x63DF90
#define PlayerBase__HasProperty_j_x                                0x975290
#define EQPlayer__IsTargetable_x                                   0x975730
#define EQPlayer__CanSee_x                                         0x975590
#define EQPlayer__CanSee1_x                                        0x975660
#define PlayerBase__GetVisibilityLineSegment_x                     0x975350

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x64FB30
#define PlayerZoneClient__GetLevel_x                               0x6520C0
#define PlayerZoneClient__IsValidTeleport_x                        0x5C0820
#define PlayerZoneClient__LegalPlayerRace_x                        0x541B60

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x647EA0
#define EQPlayerManager__GetSpawnByName_x                          0x647EC0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x647F50

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x60C600
#define KeypressHandler__AttachKeyToEqCommand_x                    0x60C640
#define KeypressHandler__ClearCommandStateArray_x                  0x60DA30
#define KeypressHandler__HandleKeyDown_x                           0x60DA50
#define KeypressHandler__HandleKeyUp_x                             0x60DAF0
#define KeypressHandler__SaveKeymapping_x                          0x60DED0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x763DC0
#define MapViewMap__SaveEx_x                                       0x767160
#define MapViewMap__SetZoom_x                                      0x76B830

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B1F50

// StringTable 
#define StringTable__getString_x                                   0x8ACFE0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x632E20
#define PcZoneClient__RemovePetEffect_x                            0x633450
#define PcZoneClient__HasAlternateAbility_x                        0x62D1B0
#define PcZoneClient__GetCurrentMod_x                              0x4E1E80
#define PcZoneClient__GetModCap_x                                  0x4E1D80
#define PcZoneClient__CanEquipItem_x                               0x62D860
#define PcZoneClient__GetItemByID_x                                0x630430
#define PcZoneClient__GetItemByItemClass_x                         0x630580
#define PcZoneClient__RemoveBuffEffect_x                           0x633470
#define PcZoneClient__BandolierSwap_x                              0x62E490

//Doors
#define EQSwitch__UseSwitch_x                                      0x5C5490

//IconCache
#define IconCache__GetIcon_x                                       0x704AF0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6FC5E0
#define CContainerMgr__CloseContainer_x                            0x6FC8B0
#define CContainerMgr__OpenExperimentContainer_x                   0x6FD330

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7BF020

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x600F80

//CLootWnd
#define CLootWnd__LootAll_x                                        0x75A2F0
#define CLootWnd__RequestLootSlot_x                                0x7596A0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x560E70
#define EQ_Spell__SpellAffects_x                                   0x5612E0
#define EQ_Spell__SpellAffectBase_x                                0x5610A0
#define EQ_Spell__IsStackable_x                                    0x4C6A70
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C68F0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B3CA0
#define EQ_Spell__IsSPAStacking_x                                  0x562110
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x561630
#define EQ_Spell__IsNoRemove_x                                     0x4C6A50
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x562120
#define __IsResEffectSpell_x                                       0x4C5D50

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AA600

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8BC4E0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x804800
#define CTargetWnd__WndNotification_x                              0x804090
#define CTargetWnd__RefreshTargetBuffs_x                           0x804360
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x8031E0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x808EC0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x5253A0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x55C410
#define EqSoundManager__PlayScriptMp3_x                            0x55C570
#define EqSoundManager__SoundAssistPlay_x                          0x66A960
#define EqSoundManager__WaveInstancePlay_x                         0x669ED0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x519370

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x92E2A0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x5504D0
#define CAltAbilityData__GetMercMaxRank_x                          0x550470
#define CAltAbilityData__GetMaxRank_x                              0x5458F0

//CTargetRing
#define CTargetRing__Cast_x                                        0x5FF090

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C68D0
#define CharacterBase__CreateItemGlobalIndex_x                     0x4FF470
#define CharacterBase__CreateItemIndex_x                           0x607160
#define CharacterBase__GetItemPossession_x                         0x4B3B50
#define CharacterBase__GetItemByGlobalIndex_x                      0x8C4B80
#define CharacterBase__GetEffectId_x                               0x4C6880

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6E46A0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6E4EC0

//messages
#define msg_spell_worn_off_x                                       0x585A50
#define msg_new_text_x                                             0x57A920
#define __msgTokenTextParam_x                                      0x5880A0
#define msgTokenText_x                                             0x5882F0

//SpellManager
#define SpellManager__vftable_x                                    0xAAFA18
#define SpellManager__SpellManager_x                               0x66DC90
#define Spellmanager__LoadTextSpells_x                             0x66E560
#define SpellManager__GetSpellByGroupAndRank_x                     0x66DE60

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x979250

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4FFB50
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x58BEA0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x61FC60
#define ItemGlobalIndex__IsValidIndex_x                            0x4FFBB0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8BCE20
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8BD0A0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x752D20

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x700D20
#define CCursorAttachment__Deactivate_x                            0x701D00

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x940850
#define CEQSuiteTextureLoader__GetTexture_x                        0x940510

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4FCC00

//IString
#define IString__Append_x                                          0x4EEB90

//Camera
#define CDisplay__cameraType_x                                     0xDC1B18
#define EverQuest__Cameras_x                                       0xE84830

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x505210
#define LootFiltersManager__GetItemFilterData_x                    0x504B10
#define LootFiltersManager__RemoveItemLootFilter_x                 0x504B40
#define LootFiltersManager__SetItemLootFilter_x                    0x504D60

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7AD070

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x97EFF0
#define CResolutionHandler__GetWindowedStyle_x                     0x6655E0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6F93C0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8CF690

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x719580
#define CGroupWnd__UpdateDisplay_x                                 0x7188E0

//ItemBase
#define ItemBase__IsLore_x                                         0x892CB0
#define ItemBase__IsLoreEquipped_x                                 0x892D20

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
