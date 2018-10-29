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
#define __ExpectedVersionDate                                     "Oct 26 2018"
#define __ExpectedVersionTime                                     "04:19:49"
#define __ActualVersionDate_x                                      0xAC6E64
#define __ActualVersionTime_x                                      0xAC6E58

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x60E1E0
#define __MemChecker1_x                                            0x8E1390
#define __MemChecker2_x                                            0x69C880
#define __MemChecker3_x                                            0x69C7D0
#define __MemChecker4_x                                            0x838F60
#define __EncryptPad0_x                                            0xBF9990
#define __EncryptPad1_x                                            0xC57C20
#define __EncryptPad2_x                                            0xC0A518
#define __EncryptPad3_x                                            0xC0A118
#define __EncryptPad4_x                                            0xC48490
#define __EncryptPad5_x                                            0x1020A84
#define __AC1_x                                                    0x7F57C6
#define __AC2_x                                                    0x5C929F
#define __AC3_x                                                    0x5D012F
#define __AC4_x                                                    0x5D3FB0
#define __AC5_x                                                    0x5DA16F
#define __AC6_x                                                    0x5DE6A6
#define __AC7_x                                                    0x5C8D10
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1E89700

// Direct Input
#define DI8__Main_x                                                0xF15848
#define DI8__Keyboard_x                                            0xF1584C
#define DI8__Mouse_x                                               0xF15828
#define DI8__Mouse_Copy_x                                          0xE73584
#define DI8__Mouse_Check_x                                         0xF16710
#define __AutoSkillArray_x                                         0xE7449C
#define __Attack_x                                                 0xF122A3
#define __Autofire_x                                               0xF122A4
#define __BindList_x                                               0xBE8588
#define g_eqCommandStates_x                                        0xBE92F8
#define __Clicks_x                                                 0xE7363C
#define __CommandList_x                                            0xBE9EB0
#define __CurrentMapLabel_x                                        0x1027E4C
#define __CurrentSocial_x                                          0xBD3728
#define __DoAbilityList_x                                          0xEA9DC4
#define __do_loot_x                                                0x596B90
#define __DrawHandler_x                                            0x16A4820
#define __GroupCount_x                                             0xE63F2A
#define __Guilds_x                                                 0xE69D90
#define __gWorld_x                                                 0xE64118
#define __HWnd_x                                                   0xF1582C
#define __heqmain_x                                                0x1020A6C
#define __InChatMode_x                                             0xE7356C
#define __LastTell_x                                               0xE754C0
#define __LMouseHeldTime_x                                         0xE736A8
#define __Mouse_x                                                  0xF15830
#define __MouseLook_x                                              0xE73602
#define __MouseEventTime_x                                         0xF12D58
#define __gpbCommandEvent_x                                        0xE639D8
#define __NetStatusToggle_x                                        0xE73605
#define __PCNames_x                                                0xE74A7C
#define __RangeAttackReady_x                                       0xE74780
#define __RMouseHeldTime_x                                         0xE736A4
#define __RunWalkState_x                                           0xE73570
#define __ScreenMode_x                                             0xDB18E0
#define __ScreenX_x                                                0xE73524
#define __ScreenY_x                                                0xE73520
#define __ScreenXMax_x                                             0xE73528
#define __ScreenYMax_x                                             0xE7352C
#define __ServerHost_x                                             0xE63B83
#define __ServerName_x                                             0xEA9D84
#define __ShiftKeyDown_x                                           0xE73BFC
#define __ShowNames_x                                              0xE7493C
#define __Socials_x                                                0xEA9E84
#define __SubscriptionType_x                                       0x106999C
#define __TargetAggroHolder_x                                      0x102A808
#define __ZoneType_x                                               0xE73A00
#define __GroupAggro_x                                             0x102A848
#define __LoginName_x                                              0xF160A4
#define __Inviter_x                                                0xF12220
#define __AttackOnAssist_x                                         0xE748F8
#define __UseTellWindows_x                                         0xE74C14
#define __gfMaxZoomCameraDistance_x                                0xABC298
#define __gfMaxCameraDistance_x                                    0xAE98C4
#define __pulAutoRun_x                                             0xE73620
#define __pulForward_x                                             0xE74C4C
#define __pulBackward_x                                            0xE74C50
#define __pulTurnRight_x                                           0xE74C54
#define __pulTurnLeft_x                                            0xE74C58
#define __pulStrafeLeft_x                                          0xE74C5C
#define __pulStrafeRight_x                                         0xE74C60
//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE66128
#define instEQZoneInfo_x                                           0xE737F8
#define instKeypressHandler_x                                      0xF12D08
#define pinstActiveBanker_x                                        0xE63E9C
#define pinstActiveCorpse_x                                        0xE63E94
#define pinstActiveGMaster_x                                       0xE63E98
#define pinstActiveMerchant_x                                      0xE63C8C
#define pinstAggroInfo_x                                           0xC6E400
#define pinstAltAdvManager_x                                       0xDB2AC8
#define pinstAuraMgr_x                                             0xC7F0E8
#define pinstBandageTarget_x                                       0xE63EAC
#define pinstCamActor_x                                            0xDB18D0
#define pinstCDBStr_x                                              0xDB17FC
#define pinstCDisplay_x                                            0xE63EF0
#define pinstCEverQuest_x                                          0xF15968
#define pinstEverQuestInfo_x                                       0xE73518
#define pinstCharData_x                                            0xE63EF8
#define pinstCharSpawn_x                                           0xE63EE4
#define pinstControlledMissile_x                                   0xE63EFC
#define pinstControlledPlayer_x                                    0xE63EE4
#define pinstCResolutionHandler_x                                  0x16A4A50
#define pinstCSidlManager_x                                        0x16A38E4
#define pinstCXWndManager_x                                        0x16A38D8
#define instDynamicZone_x                                          0xE69C68
#define pinstDZMember_x                                            0xE69D78
#define pinstDZTimerInfo_x                                         0xE69D7C
#define pinstEQItemList_x                                          0xE62318
#define pinstEQObjectList_x                                        0xE63508
#define instEQMisc_x                                               0xDB1738
#define pinstEQSoundManager_x                                      0xDB3328
#define pinstEQSpellStrings_x                                      0xC7C538
#define instExpeditionLeader_x                                     0xE69CB2
#define instExpeditionName_x                                       0xE69CF2
#define pinstGroup_x                                               0xE63F26
#define pinstImeManager_x                                          0x16A38DC
#define pinstLocalPlayer_x                                         0xE63A7C
#define pinstMercenaryData_x                                       0xF13500
#define pinstMercenaryStats_x                                      0x102A954
#define pinstMercAltAbilities_x                                    0xDB3098
#define pinstModelPlayer_x                                         0xE63EA4
#define pinstPCData_x                                              0xE63EF8
#define pinstRealEstateItems_x                                     0xF149E8
#define pinstSkillMgr_x                                            0xF14AB8
#define pinstSpawnManager_x                                        0xF140A8
#define pinstSpellManager_x                                        0xF14C90
#define pinstSpellSets_x                                           0xF0AECC
#define pinstStringTable_x                                         0xE63818
#define pinstSwitchManager_x                                       0xE636C8
#define pinstTarget_x                                              0xE63EE0
#define pinstTargetObject_x                                        0xE63EEC
#define pinstTargetSwitch_x                                        0xE63F04
#define pinstTaskMember_x                                          0xDB15C8
#define pinstTrackTarget_x                                         0xE63EE8
#define pinstTradeTarget_x                                         0xE63EA0
#define instTributeActive_x                                        0xDB175D
#define pinstViewActor_x                                           0xDB18CC
#define pinstWorldData_x                                           0xE63F0C
#define pinstZoneAddr_x                                            0xE73A98
#define pinstPlayerPath_x                                          0xF14140
#define pinstTargetIndicator_x                                     0xF14EF8
#define pinstCTargetManager_x                                      0xF14F90
#define EQObject_Top_x                                             0xE63A78

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDB2110
#define pinstCAchievementsWnd_x                                    0xDB1954
#define pinstCActionsWnd_x                                         0xDB18F4
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDB20FC
#define pinstCAdvancedLootWnd_x                                    0xDB20C4
#define pinstCAdventureLeaderboardWnd_x                            0x1021620
#define pinstCAdventureRequestWnd_x                                0x10216D0
#define pinstCAdventureStatsWnd_x                                  0x1021780
#define pinstCAggroMeterWnd_x                                      0xDB197C
#define pinstCAlarmWnd_x                                           0xDB192C
#define pinstCAlertHistoryWnd_x                                    0xDB1918
#define pinstCAlertStackWnd_x                                      0xDB2124
#define pinstCAlertWnd_x                                           0xDB18A4
#define pinstCAltStorageWnd_x                                      0x1021AE0
#define pinstCAudioTriggersWindow_x                                0xC6E890
#define pinstCAuraWnd_x                                            0xDB1978
#define pinstCAvaZoneWnd_x                                         0xDB191C
#define pinstCBandolierWnd_x                                       0xDB1BBC
#define pinstCBankWnd_x                                            0xDB20BC
#define pinstCBarterMerchantWnd_x                                  0x1022D20
#define pinstCBarterSearchWnd_x                                    0x1022DD0
#define pinstCBarterWnd_x                                          0x1022E80
#define pinstCBazaarConfirmationWnd_x                              0xDB211C
#define pinstCBazaarSearchWnd_x                                    0xDB190C
#define pinstCBazaarWnd_x                                          0xDB1BB8
#define pinstCBlockedBuffWnd_x                                     0xDB2080
#define pinstCBlockedPetBuffWnd_x                                  0xDB20C8
#define pinstCBodyTintWnd_x                                        0xDB189C
#define pinstCBookWnd_x                                            0xDB1BD0
#define pinstCBreathWnd_x                                          0xDB2120
#define pinstCBuffWindowNORMAL_x                                   0xDB1BEC
#define pinstCBuffWindowSHORT_x                                    0xDB1BF0
#define pinstCBugReportWnd_x                                       0xDB2108
#define pinstCButtonWnd_x                                          0x16A3B08
#define pinstCCastingWnd_x                                         0xDB2104
#define pinstCCastSpellWnd_x                                       0xDB1924
//#define pinstCCharacterCreationWnd_x                             0xDAAE5C
#define pinstCCharacterListWnd_x                                   0xDB2128
#define pinstCChatWindowManager_x                                  0x1023940
#define pinstCClaimWnd_x                                           0x1023A98
#define pinstCColorPickerWnd_x                                     0xDB18B8
#define pinstCCombatAbilityWnd_x                                   0xDB1B8C
#define pinstCCombatSkillsSelectWnd_x                              0xDB18F0
#define pinstCCompassWnd_x                                         0xDB2114
#define pinstCConfirmationDialog_x                                 0x1028998
#define pinstCContainerMgr_x                                       0xDB1BB0
#define pinstCContextMenuManager_x                                 0x16A3898
#define pinstCCursorAttachment_x                                   0xDB20F8
#define pinstCDistillerInfo_x                                      0x10273A4
#define pinstCDynamicZoneWnd_x                                     0x1024060
#define pinstCEditLabelWnd_x                                       0xDB1BD8
#define pinstCEQMainWnd_x                                          0x10242A8
#define pinstCEventCalendarWnd_x                                   0xDB1B94
#define pinstCExtendedTargetWnd_x                                  0xDB196C
#define pinstCFacePick_x                                           0xDB18B4
#define pinstCFellowshipWnd_x                                      0x10244A8
#define pinstCFileSelectionWnd_x                                   0xDB2084
#define pinstCFindItemWnd_x                                        0xDB1BA8
#define pinstCFindLocationWnd_x                                    0x1024600
#define pinstCFriendsWnd_x                                         0xDB1908
#define pinstCGemsGameWnd_x                                        0xDB18F8
#define pinstCGiveWnd_x                                            0xDB1BCC
#define pinstCGroupSearchFiltersWnd_x                              0xDB1B9C
#define pinstCGroupSearchWnd_x                                     0x10249F8
#define pinstCGroupWnd_x                                           0x1024AA8
#define pinstCGuildBankWnd_x                                       0xE748DC
#define pinstCGuildCreationWnd_x                                   0x1024C08
#define pinstCGuildMgmtWnd_x                                       0x1024CB8
#define pinstCharacterCreation_x                                   0xDB1B88
#define pinstCHelpWnd_x                                            0xDB1934
#define pinstCHeritageSelectionWnd_x                               0xDB18C0
#define pinstCHotButtonWnd_x                                       0x1026E10
#define pinstCHotButtonWnd1_x                                      0x1026E10
#define pinstCHotButtonWnd2_x                                      0x1026E14
#define pinstCHotButtonWnd3_x                                      0x1026E18
#define pinstCHotButtonWnd4_x                                      0x1026E1C
#define pinstCIconSelectionWnd_x                                   0xDB20DC
#define pinstCInspectWnd_x                                         0xDB20D0
#define pinstCInventoryWnd_x                                       0xDB1BC0
#define pinstCInvSlotMgr_x                                         0xDB1958
#define pinstCItemDisplayManager_x                                 0x10273A0
#define pinstCItemExpTransferWnd_x                                 0x10274D4
#define pinstCItemOverflowWnd_x                                    0xDB1910
#define pinstCJournalCatWnd_x                                      0xDB20CC
//#define pinstCJournalNPCWnd_x                                    0xDAB354
#define pinstCJournalTextWnd_x                                     0xDB1BE8
#define pinstCKeyRingWnd_x                                         0xDB2078
#define pinstCLargeDialogWnd_x                                     0x1029618
#define pinstCLayoutCopyWnd_x                                      0x1027820
#define pinstCLFGuildWnd_x                                         0x10278D0
#define pinstCLoadskinWnd_x                                        0xDB1914
#define pinstCLootFiltersCopyWnd_x                                 0xC7F970
#define pinstCLootFiltersWnd_x                                     0xDB18B0
#define pinstCLootSettingsWnd_x                                    0xDB18C4
#define pinstCLootWnd_x                                            0xDB18AC
#define pinstCMailAddressBookWnd_x                                 0xDB20D8
#define pinstCMailCompositionWnd_x                                 0xDB20B0
#define pinstCMailIgnoreListWnd_x                                  0xDB20E0
#define pinstCMailWnd_x                                            0xDB1C04
#define pinstCManageLootWnd_x                                      0xDB2F40
#define pinstCMapToolbarWnd_x                                      0xDB1BC4
#define pinstCMapViewWnd_x                                         0xDB1BA4
#define pinstCMarketplaceWnd_x                                     0xDB1BAC
#define pinstCMerchantWnd_x                                        0xDB18EC
#define pinstCMIZoneSelectWnd_x                                    0x1028108
#define pinstCMusicPlayerWnd_x                                     0xDB2070
#define pinstCNameChangeMercWnd_x                                  0xDB20D4
#define pinstCNameChangePetWnd_x                                   0xDB20C0
#define pinstCNameChangeWnd_x                                      0xDB1B84
#define pinstCNoteWnd_x                                            0xDB1930
#define pinstCObjectPreviewWnd_x                                   0xDB1BD4
#define pinstCOptionsWnd_x                                         0xDB1BC8
#define pinstCPetInfoWnd_x                                         0xDB2090
#define pinstCPetitionQWnd_x                                       0xDB20E4
//#define pinstCPlayerCustomizationWnd_x                             0xDAADC4
#define pinstCPlayerNotesWnd_x                                     0xDB1898
#define pinstCPlayerWnd_x                                          0xDB1904
#define pinstCPopupWndManager_x                                    0x1028998
#define pinstCProgressionSelectionWnd_x                            0x1028A48
#define pinstCPurchaseGroupWnd_x                                   0xDB2074
#define pinstCPurchaseWnd_x                                        0xDB1BDC
#define pinstCPvPLeaderboardWnd_x                                  0x1028AF8
#define pinstCPvPStatsWnd_x                                        0x1028BA8
#define pinstCQuantityWnd_x                                        0xDB20EC
#define pinstCRaceChangeWnd_x                                      0xDB1BB4
#define pinstCRaidOptionsWnd_x                                     0xDB1BA0
#define pinstCRaidWnd_x                                            0xDB20F0
#define pinstCRealEstateItemsWnd_x                                 0xDB195C
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDB1B90
#define pinstCRealEstateManageWnd_x                                0xDB18C8
#define pinstCRealEstateNeighborhoodWnd_x                          0xDB18FC
#define pinstCRealEstatePlotSearchWnd_x                            0xDB1920
#define pinstCRealEstatePurchaseWnd_x                              0xDB1940
#define pinstCRespawnWnd_x                                         0xDB1B98
//#define pinstCRewardSelectionWnd_x                               0x1022600
#define pinstCSelectorWnd_x                                        0xDB1970
#define pinstCSendMoneyWnd_x                                       0xDB1BE0
#define pinstCServerListWnd_x                                      0xDB1960
#define pinstCSkillsSelectWnd_x                                    0xDB18BC
#define pinstCSkillsWnd_x                                          0xDB18A8
#define pinstCSocialEditWnd_x                                      0xDB20F4
#define pinstCSocialWnd_x                                          0xDB2100
#define pinstCSpellBookWnd_x                                       0xDB1964
#define pinstCStoryWnd_x                                           0xDB210C
#define pinstCTargetOfTargetWnd_x                                  0x102A9D8
#define pinstCTargetWnd_x                                          0xDB208C
#define pinstCTaskOverlayWnd_x                                     0xDB1928
#define pinstCTaskSelectWnd_x                                      0x102AB30
#define pinstCTaskSomething_x                                      0xC80170
#define pinstCTaskTemplateSelectWnd_x                              0x102ABE0
#define pinstCTaskWnd_x                                            0x102AC90
#define pinstCTextEntryWnd_x                                       0xDB2118
#define pinstCTextOverlay_x                                        0xC6EBA0
#define pinstCTimeLeftWnd_x                                        0xDB20B8
#define pinstCTipWndCONTEXT_x                                      0x102AE94
#define pinstCTipWndOFDAY_x                                        0x102AE90
#define pinstCTitleWnd_x                                           0x102AF40
#define pinstCTrackingWnd_x                                        0xDB2088
#define pinstCTradeskillWnd_x                                      0x102B0A8
#define pinstCTradeWnd_x                                           0xDB1944
#define pinstCTrainWnd_x                                           0xDB20E8
#define pinstCTributeBenefitWnd_x                                  0x102B2A8
#define pinstCTributeMasterWnd_x                                   0x102B358
#define pinstCTributeTrophyWnd_x                                   0x102B408
#define pinstCVideoModesWnd_x                                      0xDB1938
#define pinstCVoiceMacroWnd_x                                      0xF154C0
#define pinstCVoteResultsWnd_x                                     0xDB207C
#define pinstCVoteWnd_x                                            0xDB1BE4
#define pinstCWebManager_x                                         0xF15624
#define pinstCZoneGuideWnd_x                                       0xDB18D4
#define pinstCZonePathWnd_x                                        0xDB1900

#define pinstEQSuiteTextureLoader_x                                0xC596F0
#define pinstItemIconCache_x                                       0x1024260
#define pinstLootFiltersManager_x                                  0xC7FA20
#define pinstRewardSelectionWnd_x                                  0x10292F0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC0A10C
#define __CastRay_x                                                0x5920B0
#define __CastRay2_x                                               0x592100
#define __ConvertItemTags_x                                        0x5ACC90
#define __CrashHandler_x                                           0x8428A0
#define __EQGetTime_x                                              0x8E0E80
#define __ExecuteCmd_x                                             0x58AA60
#define __FixHeading_x                                             0x971B10
#define __get_bearing_x                                            0x591BF0
#define __get_melee_range_x                                        0x5922F0
#define __GetAnimationCache_x                                      0x7005E0
#define __GetGaugeValueFromEQ_x                                    0x7F3FE0
#define __GetLabelFromEQ_x                                         0x7F5750
#define __GetXTargetType_x                                         0x973570
#define __HeadingDiff_x                                            0x971B80
#define __HelpPath_x                                               0xF12974
#define __LoadFrontEnd_x                                           0x6986E0
#define __NewUIINI_x                                               0x7F3CB0
#define __pCrashHandler_x                                          0x10487F8
#define __ProcessGameEvents_x                                      0x5EF6E0
#define __ProcessMouseEvent_x                                      0x5EEEA0
#define __SaveColors_x                                             0x53ACB0
#define __STMLToText_x                                             0x914B70
#define __ToggleKeyRingItem_x                                      0x4FDCB0
#define CrashDetected_x                                            0x69A1D0
#define DrawNetStatus_x                                            0x61B680
#define Expansion_HoT_x                                            0xE748E4
#define Teleport_Table_Size_x                                      0xE639E4
#define Teleport_Table_x                                           0xE64120
#define Util__FastTime_x                                           0x8E0A40
#define wwsCrashReportCheckForUploader_x                           0x843750
#define wwsCrashReportPlatformLaunchUploader_x                     0x845E10
#define __HandleMouseWheel_x                                       0x69C930

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48AEF0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x493CE0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x493AC0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x5425C0
#define AltAdvManager__IsAbilityReady_x                            0x541640
#define AltAdvManager__GetAAById_x                                 0x541840
#define AltAdvManager__CanTrainAbility_x                           0x5418B0
#define AltAdvManager__CanSeeAbility_x                             0x541AE0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C6860
#define CharacterZoneClient__HasSkill_x                            0x4D1520
#define CharacterZoneClient__MakeMeVisible_x                       0x4D2C40
#define CharacterZoneClient__IsStackBlocked_x                      0x4BAD10
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B7480
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D5600
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D56E0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D57C0
#define CharacterZoneClient__FindAffectSlot_x                      0x4BF7F0
#define CharacterZoneClient__BardCastBard_x                        0x4C2460
#define CharacterZoneClient__GetMaxEffects_x                       0x4B7550
#define CharacterZoneClient__GetEffect_x                           0x4B73C0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C07F0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C08C0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C0910
#define CharacterZoneClient__CalcAffectChange_x                    0x4C0A60
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C0C30

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6C2C10

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6D0540

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5FDF00
#define CButtonWnd__CButtonWnd_x                                   0x910F70

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6EEFF0
#define CChatManager__InitContextMenu_x                            0x6E9090
#define CChatManager__FreeChatWindow_x                             0x6EDF00
#define CChatManager__GetLockedActiveChatWindow_x                  0x6F28A0
#define CChatManager__SetLockedActiveChatWindow_x                  0x6EED90

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x925810
#define CContextMenu__dCContextMenu_x                              0x925A40
#define CContextMenu__AddMenuItem_x                                0x925A50
#define CContextMenu__RemoveMenuItem_x                             0x925D60
#define CContextMenu__RemoveAllMenuItems_x                         0x925D80
#define CContextMenu__CheckMenuItem_x                              0x925E00
#define CContextMenu__SetMenuItem_x                                0x925C80
#define CContextMenu__AddSeparator_x                               0x925BE0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x9263A0
#define CContextMenuManager__RemoveMenu_x                          0x926410
#define CContextMenuManager__PopupMenu_x                           0x9264D0
#define CContextMenuManager__Flush_x                               0x926340
#define CContextMenuManager__GetMenu_x                             0x495DA0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8C1A40
#define CChatService__GetFriendName_x                              0x8C1A50

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6EF560
#define CChatWindow__Clear_x                                       0x6F05C0
#define CChatWindow__WndNotification_x                             0x6F0B30

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x922CA0
#define CComboWnd__Draw_x                                          0x922190
#define CComboWnd__GetCurChoice_x                                  0x922AE0
#define CComboWnd__GetListRect_x                                   0x922640
#define CComboWnd__GetTextRect_x                                   0x922D10
#define CComboWnd__InsertChoice_x                                  0x9227D0
#define CComboWnd__SetColors_x                                     0x9227A0
#define CComboWnd__SetChoice_x                                     0x922AB0
#define CComboWnd__GetItemCount_x                                  0x922AF0
#define CComboWnd__GetCurChoiceText_x                              0x922B30

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6F87A0
#define CContainerWnd__vftable_x                                   0xAD0268
#define CContainerWnd__SetContainer_x                              0x6F9D10

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x53AA70
#define CDisplay__GetClickedActor_x                                0x52DA80
#define CDisplay__GetUserDefinedColor_x                            0x526160
#define CDisplay__GetWorldFilePath_x                               0x52F4D0
#define CDisplay__is3dON_x                                         0x52A750
#define CDisplay__ReloadUI_x                                       0x534BF0
#define CDisplay__WriteTextHD2_x                                   0x52A530
#define CDisplay__TrueDistance_x                                   0x531130
#define CDisplay__SetViewActor_x                                   0x52D3D0
#define CDisplay__GetFloorHeight_x                                 0x52A810
#define CDisplay__SetRenderWindow_x                                0x529140
#define CDisplay__ToggleScreenshotMode_x                           0x52CEA0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x945200

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x929F20
#define CEditWnd__GetCharIndexPt_x                                 0x92AE20
#define CEditWnd__GetDisplayString_x                               0x92ACC0
#define CEditWnd__GetHorzOffset_x                                  0x929550
#define CEditWnd__GetLineForPrintableChar_x                        0x92BF60
#define CEditWnd__GetSelStartPt_x                                  0x92B0D0
#define CEditWnd__GetSTMLSafeText_x                                0x92AAE0
#define CEditWnd__PointFromPrintableChar_x                         0x92BB90
#define CEditWnd__SelectableCharFromPoint_x                        0x92BD00
#define CEditWnd__SetEditable_x                                    0x92B1A0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5DDBD0
#define CEverQuest__ClickedPlayer_x                                0x5CFF10
#define CEverQuest__CreateTargetIndicator_x                        0x5EC990
#define CEverQuest__DeleteTargetIndicator_x                        0x5ECA20
#define CEverQuest__DoTellWindow_x                                 0x4E23D0
#define CEverQuest__OutputTextToLog_x                              0x4E2600
#define CEverQuest__DropHeldItemOnGround_x                         0x5C57D0
#define CEverQuest__dsp_chat_x                                     0x4E2990
#define CEverQuest__trimName_x                                     0x5E8F40
#define CEverQuest__Emote_x                                        0x5DE3E0
#define CEverQuest__EnterZone_x                                    0x5D85C0
#define CEverQuest__GetBodyTypeDesc_x                              0x5E27E0
#define CEverQuest__GetClassDesc_x                                 0x5E2E20
#define CEverQuest__GetClassThreeLetterCode_x                      0x5E3420
#define CEverQuest__GetDeityDesc_x                                 0x5EB2E0
#define CEverQuest__GetLangDesc_x                                  0x5E35E0
#define CEverQuest__GetRaceDesc_x                                  0x5E2E00
#define CEverQuest__InterpretCmd_x                                 0x5EB8B0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5C99C0
#define CEverQuest__LMouseUp_x                                     0x5C7D40
#define CEverQuest__RightClickedOnPlayer_x                         0x5CA2A0
#define CEverQuest__RMouseUp_x                                     0x5C8CD0
#define CEverQuest__SetGameState_x                                 0x5C5560
#define CEverQuest__UPCNotificationFlush_x                         0x5E8E40
#define CEverQuest__IssuePetCommand_x                              0x5E49E0
#define CEverQuest__ReportSuccessfulHit_x                          0x5DF6C0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x70A840
#define CGaugeWnd__CalcLinesFillRect_x                             0x70A8A0
#define CGaugeWnd__Draw_x                                          0x709F30

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AC350
#define CGuild__GetGuildName_x                                     0x4AB390
#define CGuild__GetGuildIndex_x                                    0x4AB720

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x725BB0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x5FE2C0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x732AB0
#define CInvSlotMgr__MoveItem_x                                    0x7317D0
#define CInvSlotMgr__SelectSlot_x                                  0x732B80

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x730080
#define CInvSlot__SliderComplete_x                                 0x72DEA0
#define CInvSlot__GetItemBase_x                                    0x72D810
#define CInvSlot__UpdateItem_x                                     0x72D980

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7344B0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x733780
#define CInvSlotWnd__HandleLButtonUp_x                             0x734030

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7F01E0
#define CItemDisplayWnd__UpdateStrings_x                           0x742550
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x73C510
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x73C9E0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x742B30
#define CItemDisplayWnd__AboutToShow_x                             0x7421A0
#define CItemDisplayWnd__WndNotification_x                         0x743E50

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x827BB0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x747F00

// CLabel 
#define CLabel__Draw_x                                             0x74D9E0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8FB300
#define CListWnd__dCListWnd_x                                      0x8FB620
#define CListWnd__AddColumn_x                                      0x8FF950
#define CListWnd__AddColumn1_x                                     0x8FF9A0
#define CListWnd__AddLine_x                                        0x8FFD30
#define CListWnd__AddString_x                                      0x8FFB30
#define CListWnd__CalculateFirstVisibleLine_x                      0x8FF710
#define CListWnd__CalculateVSBRange_x                              0x8FF4F0
#define CListWnd__ClearSel_x                                       0x900510
#define CListWnd__ClearAllSel_x                                    0x900570
#define CListWnd__CloseAndUpdateEditWindow_x                       0x900F70
#define CListWnd__Compare_x                                        0x8FEE30
#define CListWnd__Draw_x                                           0x8FB720
#define CListWnd__DrawColumnSeparators_x                           0x8FDF00
#define CListWnd__DrawHeader_x                                     0x8FE370
#define CListWnd__DrawItem_x                                       0x8FE770
#define CListWnd__DrawLine_x                                       0x8FE070
#define CListWnd__DrawSeparator_x                                  0x8FDFA0
#define CListWnd__EnableLine_x                                     0x8FD7E0
#define CListWnd__EnsureVisible_x                                  0x900E90
#define CListWnd__ExtendSel_x                                      0x900440
#define CListWnd__GetColumnMinWidth_x                              0x8FD320
#define CListWnd__GetColumnWidth_x                                 0x8FD290
#define CListWnd__GetCurSel_x                                      0x8FCC20
#define CListWnd__GetItemAtPoint_x                                 0x8FDA60
#define CListWnd__GetItemAtPoint1_x                                0x8FDAD0
#define CListWnd__GetItemData_x                                    0x8FCCA0
#define CListWnd__GetItemHeight_x                                  0x8FD060
#define CListWnd__GetItemIcon_x                                    0x8FCE30
#define CListWnd__GetItemRect_x                                    0x8FD8D0
#define CListWnd__GetItemText_x                                    0x8FCCE0
#define CListWnd__GetSelList_x                                     0x9005C0
#define CListWnd__GetSeparatorRect_x                               0x8FDD10
#define CListWnd__InsertLine_x                                     0x900120
#define CListWnd__RemoveLine_x                                     0x900270
#define CListWnd__SetColors_x                                      0x8FF4C0
#define CListWnd__SetColumnJustification_x                         0x8FF1F0
#define CListWnd__SetColumnWidth_x                                 0x8FF110
#define CListWnd__SetCurSel_x                                      0x900380
#define CListWnd__SetItemColor_x                                   0x900B40
#define CListWnd__SetItemData_x                                    0x900B00
#define CListWnd__SetItemText_x                                    0x900740
#define CListWnd__ShiftColumnSeparator_x                           0x8FF2B0
#define CListWnd__Sort_x                                           0x8FEFB0
#define CListWnd__ToggleSel_x                                      0x9003B0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x763080
#define CMapViewWnd__GetWorldCoordinates_x                         0x761790
#define CMapViewWnd__HandleLButtonDown_x                           0x75E7F0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x786150
// CMerchantWnd__RequestBuyItem_x                             
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x786A30
// CMerchantWnd__RequestSellItem_x
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x786F60
#define CMerchantWnd__SelectRecoverySlot_x                         0x789D90
//CMerchantWnd__SelectBuySellSlot_x before
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x784B40
//CMerchantWnd__ActualSelect_x
#define CMerchantWnd__SelectBuySellSlot_x                          0x78F920
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x785D90

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x88F860
#define CPacketScrambler__hton_x                                   0x88F850

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x91A170
#define CSidlManager__FindScreenPieceTemplate_x                    0x91A580
#define CSidlManager__FindScreenPieceTemplate1_x                   0x91A370
#define CSidlManager__CreateLabel_x                                0x7E7660
#define CSidlManager__CreateXWndFromTemplate_x                     0x91D650
#define CSidlManager__CreateXWndFromTemplate1_x                    0x91D830
#define CSidlManager__CreateXWnd_x                                 0x7E7590
#define CSidlManager__CreateHotButtonWnd_x                         0x7E7B60

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x916CC0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x916BC0
#define CSidlScreenWnd__ConvertToRes_x                             0x93C080
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x916650
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x916340
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x916410
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x9164E0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x917160
#define CSidlScreenWnd__EnableIniStorage_x                         0x917630
#define CSidlScreenWnd__GetSidlPiece_x                             0x917350
#define CSidlScreenWnd__Init1_x                                    0x915F30
#define CSidlScreenWnd__LoadIniInfo_x                              0x917680
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9181E0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x915350
#define CSidlScreenWnd__StoreIniInfo_x                             0x917D50
#define CSidlScreenWnd__StoreIniVis_x                              0x9180C0
#define CSidlScreenWnd__WndNotification_x                          0x917070
#define CSidlScreenWnd__GetChildItem_x                             0x9175B0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x906DD0
#define CSidlScreenWnd__m_layoutCopy_x                             0x16A3768

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x661C20
#define CSkillMgr__GetSkillCap_x                                   0x661E00
#define CSkillMgr__GetNameToken_x                                  0x6613B0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9271A0
#define CSliderWnd__SetValue_x                                     0x927010
#define CSliderWnd__SetNumTicks_x                                  0x927070

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7ED460

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x92DE00
#define CStmlWnd__CalculateHSBRange_x                              0x92EE90
#define CStmlWnd__CalculateVSBRange_x                              0x92EE00
#define CStmlWnd__CanBreakAtCharacter_x                            0x9331D0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x933DC0
#define CStmlWnd__ForceParseNow_x                                  0x92E3A0
#define CStmlWnd__GetNextTagPiece_x                                0x933130
#define CStmlWnd__GetSTMLText_x                                    0x4F08F0
#define CStmlWnd__GetVisibleText_x                                 0x92E3C0
#define CStmlWnd__InitializeWindowVariables_x                      0x933C10
#define CStmlWnd__MakeStmlColorTag_x                               0x92D590
#define CStmlWnd__MakeWndNotificationTag_x                         0x92D600
#define CStmlWnd__SetSTMLText_x                                    0x92C660
#define CStmlWnd__StripFirstSTMLLines_x                            0x934F20
#define CStmlWnd__UpdateHistoryString_x                            0x933FD0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x938BF0
#define CTabWnd__DrawCurrentPage_x                                 0x939210
#define CTabWnd__DrawTab_x                                         0x938FE0
#define CTabWnd__GetCurrentPage_x                                  0x938450
#define CTabWnd__GetPageInnerRect_x                                0x938690
#define CTabWnd__GetTabInnerRect_x                                 0x9385D0
#define CTabWnd__GetTabRect_x                                      0x938480
#define CTabWnd__InsertPage_x                                      0x938880
#define CTabWnd__SetPage_x                                         0x938710
#define CTabWnd__SetPageRect_x                                     0x938B30
#define CTabWnd__UpdatePage_x                                      0x938EA0
#define CTabWnd__GetPageFromTabIndex_x                             0x938F20
#define CTabWnd__GetCurrentTabIndex_x                              0x938440

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x748360
#define CPageWnd__SetTabText_x                                     0x945610

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A5E10

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x903C30
#define CTextureFont__GetTextExtent_x                              0x903DF0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x695520
#define CHtmlComponentWnd__ValidateUri_x                           0x7275A0
#define CHtmlWnd__SetClientCallbacks_x                             0x603280
#define CHtmlWnd__AddObserver_x                                    0x6032A0
#define CHtmlWnd__RemoveObserver_x                                 0x603300
#define Window__getProgress_x                                      0x840510
#define Window__getStatus_x                                        0x840530
#define Window__getURI_x                                           0x840540

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x941B90

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8F0B90

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4AD670
#define CXStr__CXStr1_x                                            0x8F9680
#define CXStr__CXStr3_x                                            0x8DCFB0
#define CXStr__dCXStr_x                                            0x472850
#define CXStr__operator_equal_x                                    0x8DD1E0
#define CXStr__operator_equal1_x                                   0x8DD220
#define CXStr__operator_plus_equal1_x                              0x8DDCB0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x925430
#define CXWnd__BringToTop_x                                        0x90A580
#define CXWnd__Center_x                                            0x90A100
#define CXWnd__ClrFocus_x                                          0x909F30
#define CXWnd__Destroy_x                                           0x909FE0
#define CXWnd__DoAllDrawing_x                                      0x906560
#define CXWnd__DrawChildren_x                                      0x906530
#define CXWnd__DrawColoredRect_x                                   0x9069C0
#define CXWnd__DrawTooltip_x                                       0x905090
#define CXWnd__DrawTooltipAtPoint_x                                0x905150
#define CXWnd__GetBorderFrame_x                                    0x906820
#define CXWnd__GetChildWndAt_x                                     0x90A620
#define CXWnd__GetClientClipRect_x                                 0x9087E0
#define CXWnd__GetScreenClipRect_x                                 0x9088B0
#define CXWnd__GetScreenRect_x                                     0x908A70
#define CXWnd__GetTooltipRect_x                                    0x906A10
#define CXWnd__GetWindowTextA_x                                    0x497430
#define CXWnd__IsActive_x                                          0x90D4D0
#define CXWnd__IsDescendantOf_x                                    0x909490
#define CXWnd__IsReallyVisible_x                                   0x9094C0
#define CXWnd__IsType_x                                            0x90AC90
#define CXWnd__Move_x                                              0x909530
#define CXWnd__Move1_x                                             0x9095F0
#define CXWnd__ProcessTransition_x                                 0x90A0B0
#define CXWnd__Refade_x                                            0x9098C0
#define CXWnd__Resize_x                                            0x909B50
#define CXWnd__Right_x                                             0x90A340
#define CXWnd__SetFocus_x                                          0x909EF0
#define CXWnd__SetFont_x                                           0x909F60
#define CXWnd__SetKeyTooltip_x                                     0x90AAA0
#define CXWnd__SetMouseOver_x                                      0x907980
#define CXWnd__StartFade_x                                         0x909360
#define CXWnd__GetChildItem_x                                      0x90A790
#define CXWnd__SetParent_x                                         0x909220

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x93D150

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x90D510
#define CXWndManager__DrawWindows_x                                0x90D530
#define CXWndManager__GetKeyboardFlags_x                           0x90FC90
#define CXWndManager__HandleKeyboardMsg_x                          0x90F890
#define CXWndManager__RemoveWnd_x                                  0x90FED0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x910400

// CDBStr
#define CDBStr__GetString_x                                        0x525120

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B8430
#define EQ_Character__Cur_HP_x                                     0x4CE5A0
#define EQ_Character__Cur_Mana_x                                   0x4D5CC0
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BB350
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AF290
#define EQ_Character__GetFocusRangeModifier_x                      0x4AF3E0
#define EQ_Character__GetHPRegen_x                                 0x4DB9D0
#define EQ_Character__GetEnduranceRegen_x                          0x4DBFE0
#define EQ_Character__GetManaRegen_x                               0x4DC420
#define EQ_Character__Max_Endurance_x                              0x629080
#define EQ_Character__Max_HP_x                                     0x4CE3D0
#define EQ_Character__Max_Mana_x                                   0x628E80
#define EQ_Character__doCombatAbility_x                            0x62B230
#define EQ_Character__UseSkill_x                                   0x4DE210
#define EQ_Character__GetConLevel_x                                0x6223C0
#define EQ_Character__IsExpansionFlag_x                            0x5891B0
#define EQ_Character__TotalEffect_x                                0x4C19E0
#define EQ_Character__GetPCSpellAffect_x                           0x4BBF40
#define EQ_Character__SpellDuration_x                              0x4BBA70
#define EQ_Character__FindItemByRecord_x                           0x4D3BB0
#define EQ_Character__GetAdjustedSkill_x                           0x4D12E0
#define EQ_Character__GetBaseSkill_x                               0x4D2280
#define EQ_Character__CanUseItem_x                                 0x4D5FD0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8AEB80

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x63F0A0

//PcClient
#define PcClient__PcClient_x                                       0x61FC90

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6210
#define CCharacterListWnd__EnterWorld_x                            0x4B5C50
#define CCharacterListWnd__Quit_x                                  0x4B5960
#define CCharacterListWnd__UpdateList_x                            0x4B5DE0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6044C0
#define EQ_Item__CreateItemTagString_x                             0x889710
#define EQ_Item__IsStackable_x                                     0x88DC00
#define EQ_Item__GetImageNum_x                                     0x88AEF0
#define EQ_Item__CreateItemClient_x                                0x603680
#define EQ_Item__GetItemValue_x                                    0x88C150
#define EQ_Item__ValueSellMerchant_x                               0x88F400
#define EQ_Item__IsKeyRingItem_x                                   0x88D5C0
#define EQ_Item__CanGoInBag_x                                      0x6045E0
#define EQ_Item__GetMaxItemCount_x                                 0x88C300
#define EQ_Item__GetHeldItem_x                                     0x88ADC0
#define EQ_Item__GetAugmentFitBySlot_x                             0x889140

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x5432A0
#define EQ_LoadingS__Array_x                                       0xBE1798

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x6299E0
#define EQ_PC__GetAlternateAbilityId_x                             0x898620
#define EQ_PC__GetCombatAbility_x                                  0x898C90
#define EQ_PC__GetCombatAbilityTimer_x                             0x898D00
#define EQ_PC__GetItemRecastTimer_x                                0x62B7B0
#define EQ_PC__HasLoreItem_x                                       0x622BE0
#define EQ_PC__AlertInventoryChanged_x                             0x621E90
#define EQ_PC__GetPcZoneClient_x                                   0x64D870
#define EQ_PC__RemoveMyAffect_x                                    0x62E9B0
#define EQ_PC__GetKeyRingItems_x                                   0x8995A0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x899320
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x899890

// EQItemList 
#define EQItemList__EQItemList_x                                   0x58F660
#define EQItemList__add_object_x                                   0x5BAF90
#define EQItemList__add_item_x                                     0x58FC70
#define EQItemList__delete_item_x                                  0x58FCC0
#define EQItemList__FreeItemList_x                                 0x58FBC0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x522750

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x640920
#define EQPlayer__dEQPlayer_x                                      0x634030
#define EQPlayer__DoAttack_x                                       0x648570
#define EQPlayer__EQPlayer_x                                       0x6346E0
#define EQPlayer__SetNameSpriteState_x                             0x638960
#define EQPlayer__SetNameSpriteTint_x                              0x639820
#define PlayerBase__HasProperty_j_x                                0x96FEF0
#define EQPlayer__IsTargetable_x                                   0x970390
#define EQPlayer__CanSee_x                                         0x9701F0
#define EQPlayer__CanSee1_x                                        0x9702C0
#define PlayerBase__GetVisibilityLineSegment_x                     0x96FFB0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x64B340
#define PlayerZoneClient__GetLevel_x                               0x64D8B0
#define PlayerZoneClient__IsValidTeleport_x                        0x5BC0E0
#define PlayerZoneClient__LegalPlayerRace_x                        0x53C850

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x6436B0
#define EQPlayerManager__GetSpawnByName_x                          0x6436D0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x643760

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x607D70
#define KeypressHandler__AttachKeyToEqCommand_x                    0x607DB0
#define KeypressHandler__ClearCommandStateArray_x                  0x6091A0
#define KeypressHandler__HandleKeyDown_x                           0x6091C0
#define KeypressHandler__HandleKeyUp_x                             0x609260
#define KeypressHandler__SaveKeymapping_x                          0x609640

// MapViewMap 
#define MapViewMap__Clear_x                                        0x75EF10
#define MapViewMap__SaveEx_x                                       0x7622B0
#define MapViewMap__SetZoom_x                                      0x766980

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8AC9C0

// StringTable 
#define StringTable__getString_x                                   0x8A7950

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x62E620
#define PcZoneClient__RemovePetEffect_x                            0x62EC50
#define PcZoneClient__HasAlternateAbility_x                        0x628CC0
#define PcZoneClient__GetCurrentMod_x                              0x4E1300
#define PcZoneClient__GetModCap_x                                  0x4E1200
#define PcZoneClient__CanEquipItem_x                               0x629370
#define PcZoneClient__GetItemByID_x                                0x62BC30
#define PcZoneClient__GetItemByItemClass_x                         0x62BD80
#define PcZoneClient__RemoveBuffEffect_x                           0x62EC70
#define PcZoneClient__BandolierSwap_x                              0x629FA0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5C0CB0

//IconCache
#define IconCache__GetIcon_x                                       0x6FFE70

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6F7940
#define CContainerMgr__CloseContainer_x                            0x6F7C10
#define CContainerMgr__OpenExperimentContainer_x                   0x6F8690

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7B9F30

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5FC6D0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x7552D0
#define CLootWnd__RequestLootSlot_x                                0x754690

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x55B9F0
#define EQ_Spell__SpellAffects_x                                   0x55BE60
#define EQ_Spell__SpellAffectBase_x                                0x55BC20
#define EQ_Spell__IsStackable_x                                    0x4C6180
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C6000
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B37E0
#define EQ_Spell__IsSPAStacking_x                                  0x55CC90
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x55C1B0
#define EQ_Spell__IsNoRemove_x                                     0x4C6160
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x55CCA0
#define __IsResEffectSpell_x                                       0x4C5540

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4A9FE0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8B6FF0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7FF530
#define CTargetWnd__WndNotification_x                              0x7FEDC0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7FF090
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x7FDF20

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x803BF0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x556F80
#define EqSoundManager__PlayScriptMp3_x                            0x5570E0
#define EqSoundManager__SoundAssistPlay_x                          0x665AF0
#define EqSoundManager__WaveInstancePlay_x                         0x665060

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x513FA0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x928B80

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x54B040
#define CAltAbilityData__GetMercMaxRank_x                          0x54AFE0
#define CAltAbilityData__GetMaxRank_x                              0x5404F0

//CTargetRing
#define CTargetRing__Cast_x                                        0x5FA7E0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C5FE0
#define CharacterBase__CreateItemGlobalIndex_x                     0x4FA170
#define CharacterBase__CreateItemIndex_x                           0x6028C0
#define CharacterBase__GetItemPossession_x                         0x4B3690
#define CharacterBase__GetItemByGlobalIndex_x                      0x8BF530
#define CharacterBase__GetEffectId_x                               0x4C5F90

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6DFB80
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6E03A0

//messages
#define msg_spell_worn_off_x                                       0x5815D0
#define msg_new_text_x                                             0x576530
#define __msgTokenTextParam_x                                      0x583C20
#define msgTokenText_x                                             0x583E70

//SpellManager
#define SpellManager__vftable_x                                    0xAAA880
#define SpellManager__SpellManager_x                               0x668E10
#define Spellmanager__LoadTextSpells_x                             0x6696E0
#define SpellManager__GetSpellByGroupAndRank_x                     0x668FE0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x973E60

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4FA820
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5877F0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x589190
#define ItemGlobalIndex__IsValidIndex_x                            0x4FA880

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8B7930
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8B7BB0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x74DD30

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6FC0A0
#define CCursorAttachment__Deactivate_x                            0x6FD080

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x93B660
#define CEQSuiteTextureLoader__GetTexture_x                        0x93B320

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4F77F0

//IString
#define IString__Append_x                                          0x4EA870

//Camera
#define CDisplay__cameraType_x                                     0xDB1974
#define EverQuest__Cameras_x                                       0xE74C20

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x4FFF30
#define LootFiltersManager__GetItemFilterData_x                    0x4FF820
#define LootFiltersManager__RemoveItemLootFilter_x                 0x4FF850
#define LootFiltersManager__SetItemLootFilter_x                    0x4FFA70

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7A7F30

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x979BF0
#define CResolutionHandler__GetWindowedStyle_x                     0x660730

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6F4710

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8C9D90

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x7149B0
#define CGroupWnd__UpdateDisplay_x                                 0x713D10

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
#if defined(ROF2EMU) || defined(UFEMU)
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\xFD\xFF\xFF\x8B\xCE\x5E\xE9\x00\x00\xFF\xFF\xC7\x01";
static char lpMask[] = "xxxx?xxxxxxx??xxxx";
#else
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
#endif
