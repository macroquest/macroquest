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
#define __ExpectedVersionDate                                     "Nov  9 2018"
#define __ExpectedVersionTime                                     "04:20:54"
#define __ActualVersionDate_x                                      0xAC8AB4
#define __ActualVersionTime_x                                      0xAC8AA8

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x60F140
#define __MemChecker1_x                                            0x8E3BE0
#define __MemChecker2_x                                            0x69E2E0
#define __MemChecker3_x                                            0x69E230
#define __MemChecker4_x                                            0x83AFE0
#define __EncryptPad0_x                                            0xBFB998
#define __EncryptPad1_x                                            0xC59C28
#define __EncryptPad2_x                                            0xC0C520
#define __EncryptPad3_x                                            0xC0C120
#define __EncryptPad4_x                                            0xC4A498
#define __EncryptPad5_x                                            0xF15B2C
#define __AC1_x                                                    0x7F7C46
#define __AC2_x                                                    0x5CA1DF
#define __AC3_x                                                    0x5D106F
#define __AC4_x                                                    0x5D4EF0
#define __AC5_x                                                    0x5DB0AF
#define __AC6_x                                                    0x5DF5E6
#define __AC7_x                                                    0x5C9C50
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1BFB5C

// Direct Input
#define DI8__Main_x                                                0xF15B50
#define DI8__Keyboard_x                                            0xF15B54
#define DI8__Mouse_x                                               0xF15B18
#define DI8__Mouse_Copy_x                                          0xE73874
#define DI8__Mouse_Check_x                                         0xF16A18
#define __AutoSkillArray_x                                         0xE7478C
#define __Attack_x                                                 0xF1258F
#define __Autofire_x                                               0xF12590
#define __BindList_x                                               0xBEA590
#define g_eqCommandStates_x                                        0xBEB300
#define __Clicks_x                                                 0xE7392C
#define __CommandList_x                                            0xBEBEB8
#define __CurrentMapLabel_x                                        0x102813C
#define __CurrentSocial_x                                          0xBD5730
#define __DoAbilityList_x                                          0xEAA0B0
#define __do_loot_x                                                0x597990
#define __DrawHandler_x                                            0x16A4B10
#define __GroupCount_x                                             0xE6421A
#define __Guilds_x                                                 0xE6A080
#define __gWorld_x                                                 0xE64408
#define __HWnd_x                                                   0xF15B1C
#define __heqmain_x                                                0x1020D74
#define __InChatMode_x                                             0xE7385C
#define __LastTell_x                                               0xE757AC
#define __LMouseHeldTime_x                                         0xE73998
#define __Mouse_x                                                  0xF15B38
#define __MouseLook_x                                              0xE738F2
#define __MouseEventTime_x                                         0xF13048
#define __gpbCommandEvent_x                                        0xE63CA0
#define __NetStatusToggle_x                                        0xE738F5
#define __PCNames_x                                                0xE74D6C
#define __RangeAttackReady_x                                       0xE74A70
#define __RMouseHeldTime_x                                         0xE73994
#define __RunWalkState_x                                           0xE73860
#define __ScreenMode_x                                             0xDB1C18
#define __ScreenX_x                                                0xE73814
#define __ScreenY_x                                                0xE73810
#define __ScreenXMax_x                                             0xE73818
#define __ScreenYMax_x                                             0xE7381C
#define __ServerHost_x                                             0xE63ED3
#define __ServerName_x                                             0xEAA070
#define __ShiftKeyDown_x                                           0xE73EEC
#define __ShowNames_x                                              0xE74C2C
#define __Socials_x                                                0xEAA170
#define __SubscriptionType_x                                       0x1069C8C
#define __TargetAggroHolder_x                                      0x102AAF8
#define __ZoneType_x                                               0xE73CF0
#define __GroupAggro_x                                             0x102AB38
#define __LoginName_x                                              0xF163AC
#define __Inviter_x                                                0xF1250C
#define __AttackOnAssist_x                                         0xE74BE8
#define __UseTellWindows_x                                         0xE74F04
#define __gfMaxZoomCameraDistance_x                                0xABDEE8
#define __gfMaxCameraDistance_x                                    0xAEB534
#define __pulAutoRun_x                                             0xE73910
#define __pulForward_x                                             0xE74F3C
#define __pulBackward_x                                            0xE74F40
#define __pulTurnRight_x                                           0xE74F44
#define __pulTurnLeft_x                                            0xE74F48
#define __pulStrafeLeft_x                                          0xE74F4C
#define __pulStrafeRight_x                                         0xE74F50
//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE66418
#define instEQZoneInfo_x                                           0xE73AE8
#define instKeypressHandler_x                                      0xF12FF8
#define pinstActiveBanker_x                                        0xE63D80
#define pinstActiveCorpse_x                                        0xE63D78
#define pinstActiveGMaster_x                                       0xE63D7C
#define pinstActiveMerchant_x                                      0xE63D74
#define pinstAggroInfo_x                                           0xC70418
#define pinstAltAdvManager_x                                       0xDB2DC0
#define pinstAuraMgr_x                                             0xC81100
#define pinstBandageTarget_x                                       0xE63D90
#define pinstCamActor_x                                            0xDB1C0C
#define pinstCDBStr_x                                              0xDB1AF4
#define pinstCDisplay_x                                            0xE641E4
#define pinstCEverQuest_x                                          0xF15C70
#define pinstEverQuestInfo_x                                       0xE73808
#define pinstCharData_x                                            0xE641F0
#define pinstCharSpawn_x                                           0xE63DC8
#define pinstControlledMissile_x                                   0xE641EC
#define pinstControlledPlayer_x                                    0xE63DC8
#define pinstCResolutionHandler_x                                  0x16A4D40
#define pinstCSidlManager_x                                        0x16A3BD4
#define pinstCXWndManager_x                                        0x16A3BC8
#define instDynamicZone_x                                          0xE69F58
#define pinstDZMember_x                                            0xE6A068
#define pinstDZTimerInfo_x                                         0xE6A06C
#define pinstEQItemList_x                                          0xE62608
#define pinstEQObjectList_x                                        0xE637F8
#define instEQMisc_x                                               0xDB1A30
#define pinstEQSoundManager_x                                      0xDB3620
#define pinstEQSpellStrings_x                                      0xC7E550
#define instExpeditionLeader_x                                     0xE69FA2
#define instExpeditionName_x                                       0xE69FE2
#define pinstGroup_x                                               0xE64216
#define pinstImeManager_x                                          0x16A3BCC
#define pinstLocalPlayer_x                                         0xE63D70
#define pinstMercenaryData_x                                       0xF137F4
#define pinstMercenaryStats_x                                      0x102AC44
#define pinstMercAltAbilities_x                                    0xDB3390
#define pinstModelPlayer_x                                         0xE63D88
#define pinstPCData_x                                              0xE641F0
#define pinstRealEstateItems_x                                     0xF14CD8
#define pinstSkillMgr_x                                            0xF14DA8
#define pinstSpawnManager_x                                        0xF14398
#define pinstSpellManager_x                                        0xF14F80
#define pinstSpellSets_x                                           0xF0B1B8
#define pinstStringTable_x                                         0xE63B24
#define pinstSwitchManager_x                                       0xE639B8
#define pinstTarget_x                                              0xE63DC4
#define pinstTargetObject_x                                        0xE63FDC
#define pinstTargetSwitch_x                                        0xE641FC
#define pinstTaskMember_x                                          0xDB18C4
#define pinstTrackTarget_x                                         0xE63DD0
#define pinstTradeTarget_x                                         0xE63D84
#define instTributeActive_x                                        0xDB1A55
#define pinstViewActor_x                                           0xDB1C08
#define pinstWorldData_x                                           0xE641F4
#define pinstZoneAddr_x                                            0xE73D88
#define pinstPlayerPath_x                                          0xF14430
#define pinstTargetIndicator_x                                     0xF151E8
#define pinstCTargetManager_x                                      0xF15280
#define EQObject_Top_x                                             0xE63D6C

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDB23EC
#define pinstCAchievementsWnd_x                                    0xDB1C3C
#define pinstCActionsWnd_x                                         0xDB1BB0
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDB23F4
#define pinstCAdvancedLootWnd_x                                    0xDB23C8
#define pinstCAdventureLeaderboardWnd_x                            0x1021910
#define pinstCAdventureRequestWnd_x                                0x10219C0
#define pinstCAdventureStatsWnd_x                                  0x1021A70
#define pinstCAggroMeterWnd_x                                      0xDB1C44
#define pinstCAlarmWnd_x                                           0xDB1C04
#define pinstCAlertHistoryWnd_x                                    0xDB1BEC
#define pinstCAlertStackWnd_x                                      0xDB2414
#define pinstCAlertWnd_x                                           0xDB1B90
#define pinstCAltStorageWnd_x                                      0x1021DD0
#define pinstCAudioTriggersWindow_x                                0xC708A8
#define pinstCAuraWnd_x                                            0xDB1C40
#define pinstCAvaZoneWnd_x                                         0xDB1BF4
#define pinstCBandolierWnd_x                                       0xDB1C84
#define pinstCBankWnd_x                                            0xDB1F70
#define pinstCBarterMerchantWnd_x                                  0x1023010
#define pinstCBarterSearchWnd_x                                    0x10230C0
#define pinstCBarterWnd_x                                          0x1023170
#define pinstCBazaarConfirmationWnd_x                              0xDB2410
#define pinstCBazaarSearchWnd_x                                    0xDB1BC4
#define pinstCBazaarWnd_x                                          0xDB1C78
#define pinstCBlockedBuffWnd_x                                     0xDB1EE0
#define pinstCBlockedPetBuffWnd_x                                  0xDB2380
#define pinstCBodyTintWnd_x                                        0xDB2420
#define pinstCBookWnd_x                                            0xDB1CAC
#define pinstCBreathWnd_x                                          0xDB23F0
#define pinstCBuffWindowNORMAL_x                                   0xDB1CC4
#define pinstCBuffWindowSHORT_x                                    0xDB1EC8
#define pinstCBugReportWnd_x                                       0xDB23E8
#define pinstCButtonWnd_x                                          0x16A3DF8
#define pinstCCastingWnd_x                                         0xDB23E4
#define pinstCCastSpellWnd_x                                       0xDB1BD4
//#define pinstCCharacterCreationWnd_x                             0xDAAE5C
#define pinstCCharacterListWnd_x                                   0xDB23F8
#define pinstCChatWindowManager_x                                  0x1023C30
#define pinstCClaimWnd_x                                           0x1023D88
#define pinstCColorPickerWnd_x                                     0xDB1B98
#define pinstCCombatAbilityWnd_x                                   0xDB1C54
#define pinstCCombatSkillsSelectWnd_x                              0xDB1BAC
#define pinstCCompassWnd_x                                         0xDB2404
#define pinstCConfirmationDialog_x                                 0x1028C88
#define pinstCContainerMgr_x                                       0xDB1C6C
#define pinstCContextMenuManager_x                                 0x16A3B88
#define pinstCCursorAttachment_x                                   0xDB23D8
#define pinstCDistillerInfo_x                                      0x1027694
#define pinstCDynamicZoneWnd_x                                     0x1024350
#define pinstCEditLabelWnd_x                                       0xDB1CB8
#define pinstCEQMainWnd_x                                          0x1024598
#define pinstCEventCalendarWnd_x                                   0xDB1C98
#define pinstCExtendedTargetWnd_x                                  0xDB1C34
#define pinstCFacePick_x                                           0xDB1B94
#define pinstCFellowshipWnd_x                                      0x1024798
#define pinstCFileSelectionWnd_x                                   0xDB2388
#define pinstCFindItemWnd_x                                        0xDB1CA0
#define pinstCFindLocationWnd_x                                    0x10248F0
#define pinstCFriendsWnd_x                                         0xDB1BC0
#define pinstCGemsGameWnd_x                                        0xDB1BD8
#define pinstCGiveWnd_x                                            0xDB1CA8
#define pinstCGroupSearchFiltersWnd_x                              0xDB1C5C
#define pinstCGroupSearchWnd_x                                     0x1024CE8
#define pinstCGroupWnd_x                                           0x1024D98
#define pinstCGuildBankWnd_x                                       0xE74BCC
#define pinstCGuildCreationWnd_x                                   0x1024EF8
#define pinstCGuildMgmtWnd_x                                       0x1024FA8
#define pinstCharacterCreation_x                                   0xDB1C50
#define pinstCHelpWnd_x                                            0xDB1BF0
#define pinstCHeritageSelectionWnd_x                               0xDB1BA0
#define pinstCHotButtonWnd_x                                       0x1027100
#define pinstCHotButtonWnd1_x                                      0x1027100
#define pinstCHotButtonWnd2_x                                      0x1027104
#define pinstCHotButtonWnd3_x                                      0x1027108
#define pinstCHotButtonWnd4_x                                      0x102710C
#define pinstCIconSelectionWnd_x                                   0xDB238C
#define pinstCInspectWnd_x                                         0xDB2384
#define pinstCInventoryWnd_x                                       0xDB1C8C
#define pinstCInvSlotMgr_x                                         0xDB1C24
#define pinstCItemDisplayManager_x                                 0x1027690
#define pinstCItemExpTransferWnd_x                                 0x10277C0
#define pinstCItemOverflowWnd_x                                    0xDB1BC8
#define pinstCJournalCatWnd_x                                      0xDB23D4
//#define pinstCJournalNPCWnd_x                                    0xDAB354
#define pinstCJournalTextWnd_x                                     0xDB1EF0
#define pinstCKeyRingWnd_x                                         0xDB1ED8
#define pinstCLargeDialogWnd_x                                     0x1029908
#define pinstCLayoutCopyWnd_x                                      0x1027B10
#define pinstCLFGuildWnd_x                                         0x1027BC0
#define pinstCLoadskinWnd_x                                        0xDB1BE8
#define pinstCLootFiltersCopyWnd_x                                 0xC81988
#define pinstCLootFiltersWnd_x                                     0xDB1BA4
#define pinstCLootSettingsWnd_x                                    0xDB1BB8
#define pinstCLootWnd_x                                            0xDB2418
#define pinstCMailAddressBookWnd_x                                 0xDB2390
#define pinstCMailCompositionWnd_x                                 0xDB1F6C
#define pinstCMailIgnoreListWnd_x                                  0xDB2394
#define pinstCMailWnd_x                                            0xDB1ED0
#define pinstCManageLootWnd_x                                      0xDB3238
#define pinstCMapToolbarWnd_x                                      0xDB1C94
#define pinstCMapViewWnd_x                                         0xDB1C68
#define pinstCMarketplaceWnd_x                                     0xDB1CA4
#define pinstCMerchantWnd_x                                        0xDB1BA8
#define pinstCMIZoneSelectWnd_x                                    0x10283F8
#define pinstCMusicPlayerWnd_x                                     0xDB1ED4
#define pinstCNameChangeMercWnd_x                                  0xDB23DC
#define pinstCNameChangePetWnd_x                                   0xDB23C4
#define pinstCNameChangeWnd_x                                      0xDB1C70
#define pinstCNoteWnd_x                                            0xDB1BE4
#define pinstCObjectPreviewWnd_x                                   0xDB1ECC
#define pinstCOptionsWnd_x                                         0xDB1C9C
#define pinstCPetInfoWnd_x                                         0xDB1EF4
#define pinstCPetitionQWnd_x                                       0xDB23E0
//#define pinstCPlayerCustomizationWnd_x                             0xDAADC4
#define pinstCPlayerNotesWnd_x                                     0xDB241C
#define pinstCPlayerWnd_x                                          0xDB1BBC
#define pinstCPopupWndManager_x                                    0x1028C88
#define pinstCProgressionSelectionWnd_x                            0x1028D38
#define pinstCPurchaseGroupWnd_x                                   0xDB2378
#define pinstCPurchaseWnd_x                                        0xDB1EDC
#define pinstCPvPLeaderboardWnd_x                                  0x1028DE8
#define pinstCPvPStatsWnd_x                                        0x1028E98
#define pinstCQuantityWnd_x                                        0xDB23C0
#define pinstCRaceChangeWnd_x                                      0xDB1CB4
#define pinstCRaidOptionsWnd_x                                     0xDB1C60
#define pinstCRaidWnd_x                                            0xDB23CC
#define pinstCRealEstateItemsWnd_x                                 0xDB1C48
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDB1C90
#define pinstCRealEstateManageWnd_x                                0xDB1BCC
#define pinstCRealEstateNeighborhoodWnd_x                          0xDB1BDC
#define pinstCRealEstatePlotSearchWnd_x                            0xDB1BF8
#define pinstCRealEstatePurchaseWnd_x                              0xDB1C28
#define pinstCRespawnWnd_x                                         0xDB1C58
//#define pinstCRewardSelectionWnd_x                               0x1022600
#define pinstCSelectorWnd_x                                        0xDB1C38
#define pinstCSendMoneyWnd_x                                       0xDB1CBC
#define pinstCServerListWnd_x                                      0xDB1C4C
#define pinstCSkillsSelectWnd_x                                    0xDB1B9C
#define pinstCSkillsWnd_x                                          0xDB2408
#define pinstCSocialEditWnd_x                                      0xDB23D0
#define pinstCSocialWnd_x                                          0xDB23FC
#define pinstCSpellBookWnd_x                                       0xDB1C30
#define pinstCStoryWnd_x                                           0xDB2400
#define pinstCTargetOfTargetWnd_x                                  0x102ACC8
#define pinstCTargetWnd_x                                          0xDB1EEC
#define pinstCTaskOverlayWnd_x                                     0xDB1BFC
#define pinstCTaskSelectWnd_x                                      0x102AE20
#define pinstCTaskSomething_x                                      0xC82188
#define pinstCTaskTemplateSelectWnd_x                              0x102AED0
#define pinstCTaskWnd_x                                            0x102AF80
#define pinstCTextEntryWnd_x                                       0xDB240C
#define pinstCTextOverlay_x                                        0xC70BB8
#define pinstCTimeLeftWnd_x                                        0xDB23B0
#define pinstCTipWndCONTEXT_x                                      0x102B184
#define pinstCTipWndOFDAY_x                                        0x102B180
#define pinstCTitleWnd_x                                           0x102B230
#define pinstCTrackingWnd_x                                        0xDB1EE8
#define pinstCTradeskillWnd_x                                      0x102B398
#define pinstCTradeWnd_x                                           0xDB1C00
#define pinstCTrainWnd_x                                           0xDB23BC
#define pinstCTributeBenefitWnd_x                                  0x102B598
#define pinstCTributeMasterWnd_x                                   0x102B648
#define pinstCTributeTrophyWnd_x                                   0x102B6F8
#define pinstCVideoModesWnd_x                                      0xDB1C64
#define pinstCVoiceMacroWnd_x                                      0xF157B0
#define pinstCVoteResultsWnd_x                                     0xDB237C
#define pinstCVoteWnd_x                                            0xDB1EE4
#define pinstCWebManager_x                                         0xF15914
#define pinstCZoneGuideWnd_x                                       0xDB1BD0
#define pinstCZonePathWnd_x                                        0xDB1BE0

#define pinstEQSuiteTextureLoader_x                                0xC5B6F8
#define pinstItemIconCache_x                                       0x1024550
#define pinstLootFiltersManager_x                                  0xC81A38
#define pinstRewardSelectionWnd_x                                  0x10295E0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC0C114
#define __CastRay_x                                                0x592EB0
#define __CastRay2_x                                               0x592F00
#define __ConvertItemTags_x                                        0x5ADAB0
#define __CrashHandler_x                                           0x844930
#define __EQGetTime_x                                              0x8E36D0
#define __ExecuteCmd_x                                             0x58B820
#define __FixHeading_x                                             0x974250
#define __get_bearing_x                                            0x5929F0
#define __get_melee_range_x                                        0x5930F0
#define __GetAnimationCache_x                                      0x702180
#define __GetGaugeValueFromEQ_x                                    0x7F6460
#define __GetLabelFromEQ_x                                         0x7F7BD0
#define __GetXTargetType_x                                         0x975D20
#define __HeadingDiff_x                                            0x9742C0
#define __HelpPath_x                                               0xF12C64
#define __LoadFrontEnd_x                                           0x69A140
#define __NewUIINI_x                                               0x7F6130
#define __pCrashHandler_x                                          0x1048AE8
#define __ProcessGameEvents_x                                      0x5F06A0
#define __ProcessMouseEvent_x                                      0x5EFE60
#define __SaveColors_x                                             0x53B710
#define __STMLToText_x                                             0x917180
#define __ToggleKeyRingItem_x                                      0x4FE510
#define CrashDetected_x                                            0x69BC30
#define DrawNetStatus_x                                            0x61C8A0
#define Expansion_HoT_x                                            0xE74BD4
#define Teleport_Table_Size_x                                      0xE63D2C
#define Teleport_Table_x                                           0xE64418
#define Util__FastTime_x                                           0x8E3290
#define wwsCrashReportCheckForUploader_x                           0x845830
#define wwsCrashReportPlatformLaunchUploader_x                     0x847EF0
#define __HandleMouseWheel_x                                       0x69E390

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48B170
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x494000
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x493DC0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x543060
#define AltAdvManager__IsAbilityReady_x                            0x5420E0
#define AltAdvManager__GetAAById_x                                 0x5422E0
#define AltAdvManager__CanTrainAbility_x                           0x542350
#define AltAdvManager__CanSeeAbility_x                             0x542580

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C6D30
#define CharacterZoneClient__HasSkill_x                            0x4D19F0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D3110
#define CharacterZoneClient__IsStackBlocked_x                      0x4BB200
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B7970
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D5AD0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D5BB0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D5C90
#define CharacterZoneClient__FindAffectSlot_x                      0x4BFCE0
#define CharacterZoneClient__BardCastBard_x                        0x4C2950
#define CharacterZoneClient__GetMaxEffects_x                       0x4B7A40
#define CharacterZoneClient__GetEffect_x                           0x4B78B0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C0CE0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C0DB0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C0E00
#define CharacterZoneClient__CalcAffectChange_x                    0x4C0F50
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C1120

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6C4650

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6D2160

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5FEE80
#define CButtonWnd__CButtonWnd_x                                   0x913580

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6F0B20
#define CChatManager__InitContextMenu_x                            0x6EABC0
#define CChatManager__FreeChatWindow_x                             0x6EFA30
#define CChatManager__GetLockedActiveChatWindow_x                  0x6F43C0
#define CChatManager__SetLockedActiveChatWindow_x                  0x6F08C0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x927DD0
#define CContextMenu__dCContextMenu_x                              0x927FF0
#define CContextMenu__AddMenuItem_x                                0x928000
#define CContextMenu__RemoveMenuItem_x                             0x928310
#define CContextMenu__RemoveAllMenuItems_x                         0x928330
#define CContextMenu__CheckMenuItem_x                              0x9283B0
#define CContextMenu__SetMenuItem_x                                0x928230
#define CContextMenu__AddSeparator_x                               0x928190

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x928940
#define CContextMenuManager__RemoveMenu_x                          0x9289B0
#define CContextMenuManager__PopupMenu_x                           0x928A70
#define CContextMenuManager__Flush_x                               0x9288E0
#define CContextMenuManager__GetMenu_x                             0x496120

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x88ECE0
#define CChatService__GetFriendName_x                              0x8C4270

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6F1090
#define CChatWindow__Clear_x                                       0x6F20E0
#define CChatWindow__WndNotification_x                             0x6F2640

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x925270
#define CComboWnd__Draw_x                                          0x924770
#define CComboWnd__GetCurChoice_x                                  0x9250B0
#define CComboWnd__GetListRect_x                                   0x924C20
#define CComboWnd__GetTextRect_x                                   0x9252E0
#define CComboWnd__InsertChoice_x                                  0x924DB0
#define CComboWnd__SetColors_x                                     0x924D80
#define CComboWnd__SetChoice_x                                     0x925080
#define CComboWnd__GetItemCount_x                                  0x9250C0
#define CComboWnd__GetCurChoiceText_x                              0x925100

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6FA370
#define CContainerWnd__vftable_x                                   0xAD1EC0
#define CContainerWnd__SetContainer_x                              0x6FB8E0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x53B4D0
#define CDisplay__GetClickedActor_x                                0x52E4D0
#define CDisplay__GetUserDefinedColor_x                            0x526BB0
#define CDisplay__GetWorldFilePath_x                               0x52FF20
#define CDisplay__is3dON_x                                         0x52B1A0
#define CDisplay__ReloadUI_x                                       0x535640
#define CDisplay__WriteTextHD2_x                                   0x52AF80
#define CDisplay__TrueDistance_x                                   0x531B80
#define CDisplay__SetViewActor_x                                   0x52DE20
#define CDisplay__GetFloorHeight_x                                 0x52B260
#define CDisplay__SetRenderWindow_x                                0x529B90
#define CDisplay__ToggleScreenshotMode_x                           0x52D8F0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x947910

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x92C4C0
#define CEditWnd__GetCharIndexPt_x                                 0x92D3B0
#define CEditWnd__GetDisplayString_x                               0x92D250
#define CEditWnd__GetHorzOffset_x                                  0x92BAF0
#define CEditWnd__GetLineForPrintableChar_x                        0x92E4C0
#define CEditWnd__GetSelStartPt_x                                  0x92D660
#define CEditWnd__GetSTMLSafeText_x                                0x92D070
#define CEditWnd__PointFromPrintableChar_x                         0x92E100
#define CEditWnd__SelectableCharFromPoint_x                        0x92E270
#define CEditWnd__SetEditable_x                                    0x92D720

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5DEB10
#define CEverQuest__ClickedPlayer_x                                0x5D0E50
#define CEverQuest__CreateTargetIndicator_x                        0x5ED950
#define CEverQuest__DeleteTargetIndicator_x                        0x5ED9E0
#define CEverQuest__DoTellWindow_x                                 0x4E2D20
#define CEverQuest__OutputTextToLog_x                              0x4E2F50
#define CEverQuest__DropHeldItemOnGround_x                         0x5C6710
#define CEverQuest__dsp_chat_x                                     0x4E32E0
#define CEverQuest__trimName_x                                     0x5E9EC0
#define CEverQuest__Emote_x                                        0x5DF320
#define CEverQuest__EnterZone_x                                    0x5D9500
#define CEverQuest__GetBodyTypeDesc_x                              0x5E3760
#define CEverQuest__GetClassDesc_x                                 0x5E3DA0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5E43A0
#define CEverQuest__GetDeityDesc_x                                 0x5EC2A0
#define CEverQuest__GetLangDesc_x                                  0x5E4560
#define CEverQuest__GetRaceDesc_x                                  0x5E3D80
#define CEverQuest__InterpretCmd_x                                 0x5EC870
#define CEverQuest__LeftClickedOnPlayer_x                          0x5CA900
#define CEverQuest__LMouseUp_x                                     0x5C8C80
#define CEverQuest__RightClickedOnPlayer_x                         0x5CB1E0
#define CEverQuest__RMouseUp_x                                     0x5C9C10
#define CEverQuest__SetGameState_x                                 0x5C64A0
#define CEverQuest__UPCNotificationFlush_x                         0x5E9DC0
#define CEverQuest__IssuePetCommand_x                              0x5E5960
#define CEverQuest__ReportSuccessfulHit_x                          0x5E0640

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x70C3D0
#define CGaugeWnd__CalcLinesFillRect_x                             0x70C430
#define CGaugeWnd__Draw_x                                          0x70BAC0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AC940
#define CGuild__GetGuildName_x                                     0x4ABA30
#define CGuild__GetGuildIndex_x                                    0x4ABDC0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x727790

//CHotButton
#define CHotButton__SetButtonSize_x                                0x5FF240

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x734790
#define CInvSlotMgr__MoveItem_x                                    0x7334A0
#define CInvSlotMgr__SelectSlot_x                                  0x734860

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x731D50
#define CInvSlot__SliderComplete_x                                 0x72FAB0
#define CInvSlot__GetItemBase_x                                    0x72F420
#define CInvSlot__UpdateItem_x                                     0x72F590

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7361B0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x735480
#define CInvSlotWnd__HandleLButtonUp_x                             0x735D30

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7F2660
#define CItemDisplayWnd__UpdateStrings_x                           0x744150
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x73E1B0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x73E6E0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x744730
#define CItemDisplayWnd__AboutToShow_x                             0x743D90
#define CItemDisplayWnd__WndNotification_x                         0x745C80

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x829F00

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x749DA0

// CLabel 
#define CLabel__Draw_x                                             0x74F820

// CListWnd
#define CListWnd__CListWnd_x                                       0x8FDA40
#define CListWnd__dCListWnd_x                                      0x8FDD60
#define CListWnd__AddColumn_x                                      0x9020A0
#define CListWnd__AddColumn1_x                                     0x9020F0
#define CListWnd__AddLine_x                                        0x902480
#define CListWnd__AddString_x                                      0x902280
#define CListWnd__CalculateFirstVisibleLine_x                      0x901E60
#define CListWnd__CalculateVSBRange_x                              0x901C40
#define CListWnd__ClearSel_x                                       0x902C60
#define CListWnd__ClearAllSel_x                                    0x902CC0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x9036D0
#define CListWnd__Compare_x                                        0x901580
#define CListWnd__Draw_x                                           0x8FDE60
#define CListWnd__DrawColumnSeparators_x                           0x900650
#define CListWnd__DrawHeader_x                                     0x900AC0
#define CListWnd__DrawItem_x                                       0x900EC0
#define CListWnd__DrawLine_x                                       0x9007C0
#define CListWnd__DrawSeparator_x                                  0x9006F0
#define CListWnd__EnableLine_x                                     0x8FFF20
#define CListWnd__EnsureVisible_x                                  0x9035F0
#define CListWnd__ExtendSel_x                                      0x902B90
#define CListWnd__GetColumnMinWidth_x                              0x8FFA60
#define CListWnd__GetColumnWidth_x                                 0x8FF9D0
#define CListWnd__GetCurSel_x                                      0x8FF360
#define CListWnd__GetItemAtPoint_x                                 0x9001A0
#define CListWnd__GetItemAtPoint1_x                                0x900210
#define CListWnd__GetItemData_x                                    0x8FF3E0
#define CListWnd__GetItemHeight_x                                  0x8FF7A0
#define CListWnd__GetItemIcon_x                                    0x8FF570
#define CListWnd__GetItemRect_x                                    0x900010
#define CListWnd__GetItemText_x                                    0x8FF420
#define CListWnd__GetSelList_x                                     0x902D10
#define CListWnd__GetSeparatorRect_x                               0x900450
#define CListWnd__InsertLine_x                                     0x902870
#define CListWnd__RemoveLine_x                                     0x9029C0
#define CListWnd__SetColors_x                                      0x901C10
#define CListWnd__SetColumnJustification_x                         0x901940
#define CListWnd__SetColumnWidth_x                                 0x901860
#define CListWnd__SetCurSel_x                                      0x902AD0
#define CListWnd__SetItemColor_x                                   0x9032A0
#define CListWnd__SetItemData_x                                    0x903260
#define CListWnd__SetItemText_x                                    0x902E90
#define CListWnd__ShiftColumnSeparator_x                           0x901A00
#define CListWnd__Sort_x                                           0x901700
#define CListWnd__ToggleSel_x                                      0x902B00

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x764D30
#define CMapViewWnd__GetWorldCoordinates_x                         0x763440
#define CMapViewWnd__HandleLButtonDown_x                           0x7604A0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7881A0
// CMerchantWnd__RequestBuyItem_x                             
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x788A80
// CMerchantWnd__RequestSellItem_x
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x788FB0
#define CMerchantWnd__SelectRecoverySlot_x                         0x78BDF0
//CMerchantWnd__SelectBuySellSlot_x before
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x786B80
//CMerchantWnd__ActualSelect_x
#define CMerchantWnd__SelectBuySellSlot_x                          0x7919E0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x787DD0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x891F50
#define CPacketScrambler__hton_x                                   0x891F40

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x91C790
#define CSidlManager__FindScreenPieceTemplate_x                    0x91CBA0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x91C990
#define CSidlManager__CreateLabel_x                                0x7E9B20
#define CSidlManager__CreateXWndFromTemplate_x                     0x91FC70
#define CSidlManager__CreateXWndFromTemplate1_x                    0x91FE50
#define CSidlManager__CreateXWnd_x                                 0x7E9A50
#define CSidlManager__CreateHotButtonWnd_x                         0x7EA010

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9192E0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9191E0
#define CSidlScreenWnd__ConvertToRes_x                             0x93E750
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x918C80
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x918970
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x918A40
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x918B10
#define CSidlScreenWnd__DrawSidlPiece_x                            0x919780
#define CSidlScreenWnd__EnableIniStorage_x                         0x919C50
#define CSidlScreenWnd__GetSidlPiece_x                             0x919970
#define CSidlScreenWnd__Init1_x                                    0x918560
#define CSidlScreenWnd__LoadIniInfo_x                              0x919CA0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x91A800
#define CSidlScreenWnd__LoadSidlScreen_x                           0x917960
#define CSidlScreenWnd__StoreIniInfo_x                             0x91A370
#define CSidlScreenWnd__StoreIniVis_x                              0x91A6E0
#define CSidlScreenWnd__WndNotification_x                          0x919690
#define CSidlScreenWnd__GetChildItem_x                             0x919BD0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x909490
#define CSidlScreenWnd__m_layoutCopy_x                             0x16A3A58

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x663430
#define CSkillMgr__GetSkillCap_x                                   0x663610
#define CSkillMgr__GetNameToken_x                                  0x662BC0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x929740
#define CSliderWnd__SetValue_x                                     0x9295B0
#define CSliderWnd__SetNumTicks_x                                  0x929610

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7EF8E0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x930370
#define CStmlWnd__CalculateHSBRange_x                              0x931400
#define CStmlWnd__CalculateVSBRange_x                              0x931370
#define CStmlWnd__CanBreakAtCharacter_x                            0x935730
#define CStmlWnd__FastForwardToEndOfTag_x                          0x936320
#define CStmlWnd__ForceParseNow_x                                  0x930910
#define CStmlWnd__GetNextTagPiece_x                                0x935690
#define CStmlWnd__GetSTMLText_x                                    0x4F1160
#define CStmlWnd__GetVisibleText_x                                 0x930930
#define CStmlWnd__InitializeWindowVariables_x                      0x936170
#define CStmlWnd__MakeStmlColorTag_x                               0x92FB00
#define CStmlWnd__MakeWndNotificationTag_x                         0x92FB70
#define CStmlWnd__SetSTMLText_x                                    0x92EBD0
#define CStmlWnd__StripFirstSTMLLines_x                            0x937480
#define CStmlWnd__UpdateHistoryString_x                            0x936530

// CTabWnd 
#define CTabWnd__Draw_x                                            0x93B210
#define CTabWnd__DrawCurrentPage_x                                 0x93B830
#define CTabWnd__DrawTab_x                                         0x93B600
#define CTabWnd__GetCurrentPage_x                                  0x93AA70
#define CTabWnd__GetPageInnerRect_x                                0x93ACB0
#define CTabWnd__GetTabInnerRect_x                                 0x93ABF0
#define CTabWnd__GetTabRect_x                                      0x93AAA0
#define CTabWnd__InsertPage_x                                      0x93AEA0
#define CTabWnd__SetPage_x                                         0x93AD30
#define CTabWnd__SetPageRect_x                                     0x93B150
#define CTabWnd__UpdatePage_x                                      0x93B4C0
#define CTabWnd__GetPageFromTabIndex_x                             0x93B540
#define CTabWnd__GetCurrentTabIndex_x                              0x93AA60

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x74A200
#define CPageWnd__SetTabText_x                                     0x947D20

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A63A0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x906390
#define CTextureFont__GetTextExtent_x                              0x906550

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x696F50
#define CHtmlComponentWnd__ValidateUri_x                           0x729180
#define CHtmlWnd__SetClientCallbacks_x                             0x604200
#define CHtmlWnd__AddObserver_x                                    0x604220
#define CHtmlWnd__RemoveObserver_x                                 0x604280
#define Window__getProgress_x                                      0x8425A0
#define Window__getStatus_x                                        0x8425C0
#define Window__getURI_x                                           0x8425D0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9442A0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8F3370

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4ADBD0
#define CXStr__CXStr1_x                                            0x9B5D90
#define CXStr__CXStr3_x                                            0x8DF7C0
#define CXStr__dCXStr_x                                            0x472960
#define CXStr__operator_equal_x                                    0x8DF9F0
#define CXStr__operator_equal1_x                                   0x8DFA30
#define CXStr__operator_plus_equal1_x                              0x8E04C0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x9279F0
#define CXWnd__BringToTop_x                                        0x90CC10
#define CXWnd__Center_x                                            0x90C790
#define CXWnd__ClrFocus_x                                          0x90C5C0
#define CXWnd__Destroy_x                                           0x90C670
#define CXWnd__DoAllDrawing_x                                      0x908C70
#define CXWnd__DrawChildren_x                                      0x908C40
#define CXWnd__DrawColoredRect_x                                   0x9090A0
#define CXWnd__DrawTooltip_x                                       0x9077C0
#define CXWnd__DrawTooltipAtPoint_x                                0x907880
#define CXWnd__GetBorderFrame_x                                    0x908F10
#define CXWnd__GetChildWndAt_x                                     0x90CCB0
#define CXWnd__GetClientClipRect_x                                 0x90AE90
#define CXWnd__GetScreenClipRect_x                                 0x90AF60
#define CXWnd__GetScreenRect_x                                     0x90B130
#define CXWnd__GetTooltipRect_x                                    0x9090F0
#define CXWnd__GetWindowTextA_x                                    0x4978C0
#define CXWnd__IsActive_x                                          0x90FB50
#define CXWnd__IsDescendantOf_x                                    0x90BB30
#define CXWnd__IsReallyVisible_x                                   0x90BB60
#define CXWnd__IsType_x                                            0x90D320
#define CXWnd__Move_x                                              0x90BBD0
#define CXWnd__Move1_x                                             0x90BC80
#define CXWnd__ProcessTransition_x                                 0x90C740
#define CXWnd__Refade_x                                            0x90BF40
#define CXWnd__Resize_x                                            0x90C1D0
#define CXWnd__Right_x                                             0x90C9D0
#define CXWnd__SetFocus_x                                          0x90C580
#define CXWnd__SetFont_x                                           0x90C5F0
#define CXWnd__SetKeyTooltip_x                                     0x90D130
#define CXWnd__SetMouseOver_x                                      0x90A050
#define CXWnd__StartFade_x                                         0x90BA00
#define CXWnd__GetChildItem_x                                      0x90CE20
#define CXWnd__SetParent_x                                         0x90B8D0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x93F820

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x90FB90
#define CXWndManager__DrawWindows_x                                0x90FBB0
#define CXWndManager__GetKeyboardFlags_x                           0x912260
#define CXWndManager__HandleKeyboardMsg_x                          0x911E70
#define CXWndManager__RemoveWnd_x                                  0x9124B0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x912A00

// CDBStr
#define CDBStr__GetString_x                                        0x525B60

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B8920
#define EQ_Character__Cur_HP_x                                     0x4CEA70
#define EQ_Character__Cur_Mana_x                                   0x4D6190
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BB840
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AF790
#define EQ_Character__GetFocusRangeModifier_x                      0x4AF8E0
#define EQ_Character__GetHPRegen_x                                 0x4DC100
#define EQ_Character__GetEnduranceRegen_x                          0x4DC710
#define EQ_Character__GetManaRegen_x                               0x4DCB50
#define EQ_Character__Max_Endurance_x                              0x62A390
#define EQ_Character__Max_HP_x                                     0x4CE8A0
#define EQ_Character__Max_Mana_x                                   0x62A190
#define EQ_Character__doCombatAbility_x                            0x62C860
#define EQ_Character__UseSkill_x                                   0x4DE960
#define EQ_Character__GetConLevel_x                                0x623590
#define EQ_Character__IsExpansionFlag_x                            0x589EA0
#define EQ_Character__TotalEffect_x                                0x4C1ED0
#define EQ_Character__GetPCSpellAffect_x                           0x4BC430
#define EQ_Character__SpellDuration_x                              0x4BBF60
#define EQ_Character__FindItemByRecord_x                           0x4D4080
#define EQ_Character__GetAdjustedSkill_x                           0x4D17B0
#define EQ_Character__GetBaseSkill_x                               0x4D2750
#define EQ_Character__CanUseItem_x                                 0x4D64A0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8B11A0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x6406E0

//PcClient
#define PcClient__PcClient_x                                       0x620E70

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B66F0
#define CCharacterListWnd__EnterWorld_x                            0x4B6130
#define CCharacterListWnd__Quit_x                                  0x4B5E40
#define CCharacterListWnd__UpdateList_x                            0x4B62C0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x605430
#define EQ_Item__CreateItemTagString_x                             0x88B910
#define EQ_Item__IsStackable_x                                     0x890320
#define EQ_Item__GetImageNum_x                                     0x88D330
#define EQ_Item__CreateItemClient_x                                0x6045E0
#define EQ_Item__GetItemValue_x                                    0x88E5B0
#define EQ_Item__ValueSellMerchant_x                               0x891AF0
#define EQ_Item__IsKeyRingItem_x                                   0x88FC80
#define EQ_Item__CanGoInBag_x                                      0x605550
#define EQ_Item__GetMaxItemCount_x                                 0x88E970
#define EQ_Item__GetHeldItem_x                                     0x88D200
#define EQ_Item__GetAugmentFitBySlot_x                             0x88B270

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x543D70
#define EQ_LoadingS__Array_x                                       0xBE37A0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x62ACF0
#define EQ_PC__GetAlternateAbilityId_x                             0x89AD70
#define EQ_PC__GetCombatAbility_x                                  0x89B3E0
#define EQ_PC__GetCombatAbilityTimer_x                             0x89B450
#define EQ_PC__GetItemRecastTimer_x                                0x62CDE0
#define EQ_PC__HasLoreItem_x                                       0x623D60
#define EQ_PC__AlertInventoryChanged_x                             0x623070
#define EQ_PC__GetPcZoneClient_x                                   0x64EE30
#define EQ_PC__RemoveMyAffect_x                                    0x62FFD0
#define EQ_PC__GetKeyRingItems_x                                   0x89BCF0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x89BA70
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x89BFE0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x590430
#define EQItemList__add_object_x                                   0x5BBDF0
#define EQItemList__add_item_x                                     0x590A40
#define EQItemList__delete_item_x                                  0x590A90
#define EQItemList__FreeItemList_x                                 0x590990

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x5231E0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x641F60
#define EQPlayer__dEQPlayer_x                                      0x635640
#define EQPlayer__DoAttack_x                                       0x649B10
#define EQPlayer__EQPlayer_x                                       0x635CF0
#define EQPlayer__SetNameSpriteState_x                             0x639F90
#define EQPlayer__SetNameSpriteTint_x                              0x63AE60
#define PlayerBase__HasProperty_j_x                                0x972630
#define EQPlayer__IsTargetable_x                                   0x972AD0
#define EQPlayer__CanSee_x                                         0x972930
#define EQPlayer__CanSee1_x                                        0x972A00
#define PlayerBase__GetVisibilityLineSegment_x                     0x9726F0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x64C8E0
#define PlayerZoneClient__GetLevel_x                               0x64EE70
#define PlayerZoneClient__IsValidTeleport_x                        0x5BCF40
#define PlayerZoneClient__LegalPlayerRace_x                        0x53D2B0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x644C50
#define EQPlayerManager__GetSpawnByName_x                          0x644C70
#define EQPlayerManager__GetPlayerFromPartialName_x                0x644D00

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x608D90
#define KeypressHandler__AttachKeyToEqCommand_x                    0x608DD0
#define KeypressHandler__ClearCommandStateArray_x                  0x60A1C0
#define KeypressHandler__HandleKeyDown_x                           0x60A1E0
#define KeypressHandler__HandleKeyUp_x                             0x60A280
#define KeypressHandler__SaveKeymapping_x                          0x60A660

// MapViewMap 
#define MapViewMap__Clear_x                                        0x760BC0
#define MapViewMap__SaveEx_x                                       0x763F60
#define MapViewMap__SetZoom_x                                      0x768630

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8AF060

// StringTable 
#define StringTable__getString_x                                   0x8A9FF0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x62FC40
#define PcZoneClient__RemovePetEffect_x                            0x630270
#define PcZoneClient__HasAlternateAbility_x                        0x629FD0
#define PcZoneClient__GetCurrentMod_x                              0x4E1A60
#define PcZoneClient__GetModCap_x                                  0x4E1960
#define PcZoneClient__CanEquipItem_x                               0x62A680
#define PcZoneClient__GetItemByID_x                                0x62D250
#define PcZoneClient__GetItemByItemClass_x                         0x62D3A0
#define PcZoneClient__RemoveBuffEffect_x                           0x630290
#define PcZoneClient__BandolierSwap_x                              0x62B2B0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5C1BE0

//IconCache
#define IconCache__GetIcon_x                                       0x701A10

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6F9510
#define CContainerMgr__CloseContainer_x                            0x6F97E0
#define CContainerMgr__OpenExperimentContainer_x                   0x6FA260

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7BC040

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5FD660

//CLootWnd
#define CLootWnd__LootAll_x                                        0x757060
#define CLootWnd__RequestLootSlot_x                                0x756410

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x55C1A0
#define EQ_Spell__SpellAffects_x                                   0x55C610
#define EQ_Spell__SpellAffectBase_x                                0x55C3D0
#define EQ_Spell__IsStackable_x                                    0x4C6660
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C64E0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B3CC0
#define EQ_Spell__IsSPAStacking_x                                  0x55D440
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x55C960
#define EQ_Spell__IsNoRemove_x                                     0x4C6640
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x55D450
#define __IsResEffectSpell_x                                       0x4C5A30

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AA5B0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8B9610

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x8019F0
#define CTargetWnd__WndNotification_x                              0x801280
#define CTargetWnd__RefreshTargetBuffs_x                           0x801550
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x8003E0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x8060C0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x557720
#define EqSoundManager__PlayScriptMp3_x                            0x557880
#define EqSoundManager__SoundAssistPlay_x                          0x667350
#define EqSoundManager__WaveInstancePlay_x                         0x6668C0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x514AF0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x92B120

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x54BA20
#define CAltAbilityData__GetMercMaxRank_x                          0x54B9C0
#define CAltAbilityData__GetMaxRank_x                              0x540F90

//CTargetRing
#define CTargetRing__Cast_x                                        0x5FB770

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C64C0
#define CharacterBase__CreateItemGlobalIndex_x                     0x4FA9E0
#define CharacterBase__CreateItemIndex_x                           0x603840
#define CharacterBase__GetItemPossession_x                         0x4B3B70
#define CharacterBase__GetItemByGlobalIndex_x                      0x8C1CC0
#define CharacterBase__GetEffectId_x                               0x4C6470

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6E16D0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6E1EF0

//messages
#define msg_spell_worn_off_x                                       0x581E30
#define msg_new_text_x                                             0x576D10
#define __msgTokenTextParam_x                                      0x584480
#define msgTokenText_x                                             0x5846D0

//SpellManager
#define SpellManager__vftable_x                                    0xAAC890
#define SpellManager__SpellManager_x                               0x66A680
#define Spellmanager__LoadTextSpells_x                             0x66AF50
#define SpellManager__GetSpellByGroupAndRank_x                     0x66A850

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x976610

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4FB090
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5882D0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x589E80
#define ItemGlobalIndex__IsValidIndex_x                            0x4FB0F0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8B9F50
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8BA1D0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x74FB70

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6FDC60
#define CCursorAttachment__Deactivate_x                            0x6FEC30

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x93D880
#define CEQSuiteTextureLoader__GetTexture_x                        0x93D540

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4F8060

//IString
#define IString__Append_x                                          0x4EB160

//Camera
#define CDisplay__cameraType_x                                     0xDB1CC0
#define EverQuest__Cameras_x                                       0xE74F10

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x500790
#define LootFiltersManager__GetItemFilterData_x                    0x500090
#define LootFiltersManager__RemoveItemLootFilter_x                 0x5000C0
#define LootFiltersManager__SetItemLootFilter_x                    0x5002E0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7AA040

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x97C2E0
#define CResolutionHandler__GetWindowedStyle_x                     0x662030

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6F6250

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8CC5D0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x716520
#define CGroupWnd__UpdateDisplay_x                                 0x715890

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
