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
#define __ExpectedVersionDate                                     "Nov 12 2018"
#define __ExpectedVersionTime                                     "04:20:19"
#define __ActualVersionDate_x                                      0xAC8B84
#define __ActualVersionTime_x                                      0xAC8B78

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x60E830
#define __MemChecker1_x                                            0x8E2F40
#define __MemChecker2_x                                            0x69D880
#define __MemChecker3_x                                            0x69D7D0
#define __MemChecker4_x                                            0x83A2B0
#define __EncryptPad0_x                                            0xBFB998
#define __EncryptPad1_x                                            0xC59C28
#define __EncryptPad2_x                                            0xC0C520
#define __EncryptPad3_x                                            0xC0C120
#define __EncryptPad4_x                                            0xC4A498
#define __EncryptPad5_x                                            0xF15B2C
#define __AC1_x                                                    0x7F6DD6
#define __AC2_x                                                    0x5C961F
#define __AC3_x                                                    0x5D04AF
#define __AC4_x                                                    0x5D4320
#define __AC5_x                                                    0x5DA4DF
#define __AC6_x                                                    0x5DEA16
#define __AC7_x                                                    0x5C9090
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
#define __do_loot_x                                                0x596CC0
#define __DrawHandler_x                                            0x16A4B10
#define __GroupCount_x                                             0xE64222
#define __Guilds_x                                                 0xE6A080
#define __gWorld_x                                                 0xE64204
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
#define __ScreenMode_x                                             0xDB1C20
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
#define __gfMaxZoomCameraDistance_x                                0xABDF68
#define __gfMaxCameraDistance_x                                    0xAEB5B4
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
#define pinstCamActor_x                                            0xDB1C14
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
#define pinstGroup_x                                               0xE6421E
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
#define pinstViewActor_x                                           0xDB1C10
#define pinstWorldData_x                                           0xE641F4
#define pinstZoneAddr_x                                            0xE73D88
#define pinstPlayerPath_x                                          0xF14430
#define pinstTargetIndicator_x                                     0xF151E8
#define pinstCTargetManager_x                                      0xF15280
#define EQObject_Top_x                                             0xE63D6C

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDB23F4
#define pinstCAchievementsWnd_x                                    0xDB1C44
#define pinstCActionsWnd_x                                         0xDB1BB8
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDB23FC
#define pinstCAdvancedLootWnd_x                                    0xDB23D0
#define pinstCAdventureLeaderboardWnd_x                            0x1021910
#define pinstCAdventureRequestWnd_x                                0x10219C0
#define pinstCAdventureStatsWnd_x                                  0x1021A70
#define pinstCAggroMeterWnd_x                                      0xDB1C4C
#define pinstCAlarmWnd_x                                           0xDB1C0C
#define pinstCAlertHistoryWnd_x                                    0xDB1BF4
#define pinstCAlertStackWnd_x                                      0xDB241C
#define pinstCAlertWnd_x                                           0xDB1B98
#define pinstCAltStorageWnd_x                                      0x1021DD0
#define pinstCAudioTriggersWindow_x                                0xC708A8
#define pinstCAuraWnd_x                                            0xDB1C48
#define pinstCAvaZoneWnd_x                                         0xDB1BFC
#define pinstCBandolierWnd_x                                       0xDB1C90
#define pinstCBankWnd_x                                            0xDB1F78
#define pinstCBarterMerchantWnd_x                                  0x1023010
#define pinstCBarterSearchWnd_x                                    0x10230C0
#define pinstCBarterWnd_x                                          0x1023170
#define pinstCBazaarConfirmationWnd_x                              0xDB2418
#define pinstCBazaarSearchWnd_x                                    0xDB1BCC
#define pinstCBazaarWnd_x                                          0xDB1C80
#define pinstCBlockedBuffWnd_x                                     0xDB1EE8
#define pinstCBlockedPetBuffWnd_x                                  0xDB2388
#define pinstCBodyTintWnd_x                                        0xDB1B94
#define pinstCBookWnd_x                                            0xDB1CB8
#define pinstCBreathWnd_x                                          0xDB23F8
#define pinstCBuffWindowNORMAL_x                                   0xDB1CCC
#define pinstCBuffWindowSHORT_x                                    0xDB1ED0
#define pinstCBugReportWnd_x                                       0xDB23F0
#define pinstCButtonWnd_x                                          0x16A3DF8
#define pinstCCastingWnd_x                                         0xDB23EC
#define pinstCCastSpellWnd_x                                       0xDB1BDC
//#define pinstCCharacterCreationWnd_x                             0xDAAE5C
#define pinstCCharacterListWnd_x                                   0xDB2400
#define pinstCChatWindowManager_x                                  0x1023C30
#define pinstCClaimWnd_x                                           0x1023D88
#define pinstCColorPickerWnd_x                                     0xDB1BA0
#define pinstCCombatAbilityWnd_x                                   0xDB1C5C
#define pinstCCombatSkillsSelectWnd_x                              0xDB1BB4
#define pinstCCompassWnd_x                                         0xDB240C
#define pinstCConfirmationDialog_x                                 0x1028C88
#define pinstCContainerMgr_x                                       0xDB1C74
#define pinstCContextMenuManager_x                                 0x16A3B88
#define pinstCCursorAttachment_x                                   0xDB23E0
#define pinstCDistillerInfo_x                                      0x1027694
#define pinstCDynamicZoneWnd_x                                     0x1024350
#define pinstCEditLabelWnd_x                                       0xDB1CC0
#define pinstCEQMainWnd_x                                          0x1024598
#define pinstCEventCalendarWnd_x                                   0xDB1CA0
#define pinstCExtendedTargetWnd_x                                  0xDB1C3C
#define pinstCFacePick_x                                           0xDB1B9C
#define pinstCFellowshipWnd_x                                      0x1024798
#define pinstCFileSelectionWnd_x                                   0xDB2390
#define pinstCFindItemWnd_x                                        0xDB1CA8
#define pinstCFindLocationWnd_x                                    0x10248F0
#define pinstCFriendsWnd_x                                         0xDB1BC8
#define pinstCGemsGameWnd_x                                        0xDB1BE0
#define pinstCGiveWnd_x                                            0xDB1CB0
#define pinstCGroupSearchFiltersWnd_x                              0xDB1C64
#define pinstCGroupSearchWnd_x                                     0x1024CE8
#define pinstCGroupWnd_x                                           0x1024D98
#define pinstCGuildBankWnd_x                                       0xE74BCC
#define pinstCGuildCreationWnd_x                                   0x1024EF8
#define pinstCGuildMgmtWnd_x                                       0x1024FA8
#define pinstCharacterCreation_x                                   0xDB1C58
#define pinstCHelpWnd_x                                            0xDB1BF8
#define pinstCHeritageSelectionWnd_x                               0xDB1BA8
#define pinstCHotButtonWnd_x                                       0x1027100
#define pinstCHotButtonWnd1_x                                      0x1027100
#define pinstCHotButtonWnd2_x                                      0x1027104
#define pinstCHotButtonWnd3_x                                      0x1027108
#define pinstCHotButtonWnd4_x                                      0x102710C
#define pinstCIconSelectionWnd_x                                   0xDB2394
#define pinstCInspectWnd_x                                         0xDB238C
#define pinstCInventoryWnd_x                                       0xDB1C94
#define pinstCInvSlotMgr_x                                         0xDB1C2C
#define pinstCItemDisplayManager_x                                 0x1027690
#define pinstCItemExpTransferWnd_x                                 0x10277C0
#define pinstCItemOverflowWnd_x                                    0xDB1BD0
#define pinstCJournalCatWnd_x                                      0xDB23DC
//#define pinstCJournalNPCWnd_x                                    0xDAB354
#define pinstCJournalTextWnd_x                                     0xDB1EF8
#define pinstCKeyRingWnd_x                                         0xDB1EE0
#define pinstCLargeDialogWnd_x                                     0x1029908
#define pinstCLayoutCopyWnd_x                                      0x1027B10
#define pinstCLFGuildWnd_x                                         0x1027BC0
#define pinstCLoadskinWnd_x                                        0xDB1BF0
#define pinstCLootFiltersCopyWnd_x                                 0xC81988
#define pinstCLootFiltersWnd_x                                     0xDB1BAC
#define pinstCLootSettingsWnd_x                                    0xDB1BC0
#define pinstCLootWnd_x                                            0xDB2420
#define pinstCMailAddressBookWnd_x                                 0xDB2398
#define pinstCMailCompositionWnd_x                                 0xDB1F74
#define pinstCMailIgnoreListWnd_x                                  0xDB239C
#define pinstCMailWnd_x                                            0xDB1ED4
#define pinstCManageLootWnd_x                                      0xDB3238
#define pinstCMapToolbarWnd_x                                      0xDB1C9C
#define pinstCMapViewWnd_x                                         0xDB1C70
#define pinstCMarketplaceWnd_x                                     0xDB1CAC
#define pinstCMerchantWnd_x                                        0xDB1BB0
#define pinstCMIZoneSelectWnd_x                                    0x10283F8
#define pinstCMusicPlayerWnd_x                                     0xDB1EDC
#define pinstCNameChangeMercWnd_x                                  0xDB23E4
#define pinstCNameChangePetWnd_x                                   0xDB23CC
#define pinstCNameChangeWnd_x                                      0xDB1C78
#define pinstCNoteWnd_x                                            0xDB1BEC
#define pinstCObjectPreviewWnd_x                                   0xDB1ED8
#define pinstCOptionsWnd_x                                         0xDB1CA4
#define pinstCPetInfoWnd_x                                         0xDB1EFC
#define pinstCPetitionQWnd_x                                       0xDB23E8
//#define pinstCPlayerCustomizationWnd_x                             0xDAADC4
#define pinstCPlayerNotesWnd_x                                     0xDB1B90
#define pinstCPlayerWnd_x                                          0xDB1BC4
#define pinstCPopupWndManager_x                                    0x1028C88
#define pinstCProgressionSelectionWnd_x                            0x1028D38
#define pinstCPurchaseGroupWnd_x                                   0xDB2380
#define pinstCPurchaseWnd_x                                        0xDB1EE4
#define pinstCPvPLeaderboardWnd_x                                  0x1028DE8
#define pinstCPvPStatsWnd_x                                        0x1028E98
#define pinstCQuantityWnd_x                                        0xDB23C8
#define pinstCRaceChangeWnd_x                                      0xDB1CBC
#define pinstCRaidOptionsWnd_x                                     0xDB1C6C
#define pinstCRaidWnd_x                                            0xDB23D4
#define pinstCRealEstateItemsWnd_x                                 0xDB1C50
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDB1C98
#define pinstCRealEstateManageWnd_x                                0xDB1BD4
#define pinstCRealEstateNeighborhoodWnd_x                          0xDB1BE4
#define pinstCRealEstatePlotSearchWnd_x                            0xDB1C00
#define pinstCRealEstatePurchaseWnd_x                              0xDB1C30
#define pinstCRespawnWnd_x                                         0xDB1C60
//#define pinstCRewardSelectionWnd_x                               0x1022600
#define pinstCSelectorWnd_x                                        0xDB1C40
#define pinstCSendMoneyWnd_x                                       0xDB1CC4
#define pinstCServerListWnd_x                                      0xDB1C54
#define pinstCSkillsSelectWnd_x                                    0xDB1BA4
#define pinstCSkillsWnd_x                                          0xDB2410
#define pinstCSocialEditWnd_x                                      0xDB23D8
#define pinstCSocialWnd_x                                          0xDB2404
#define pinstCSpellBookWnd_x                                       0xDB1C38
#define pinstCStoryWnd_x                                           0xDB2408
#define pinstCTargetOfTargetWnd_x                                  0x102ACC8
#define pinstCTargetWnd_x                                          0xDB1EF4
#define pinstCTaskOverlayWnd_x                                     0xDB1C04
#define pinstCTaskSelectWnd_x                                      0x102AE20
#define pinstCTaskSomething_x                                      0xC82188
#define pinstCTaskTemplateSelectWnd_x                              0x102AED0
#define pinstCTaskWnd_x                                            0x102AF80
#define pinstCTextEntryWnd_x                                       0xDB2414
#define pinstCTextOverlay_x                                        0xC70BB8
#define pinstCTimeLeftWnd_x                                        0xDB23B8
#define pinstCTipWndCONTEXT_x                                      0x102B184
#define pinstCTipWndOFDAY_x                                        0x102B180
#define pinstCTitleWnd_x                                           0x102B230
#define pinstCTrackingWnd_x                                        0xDB1EEC
#define pinstCTradeskillWnd_x                                      0x102B398
#define pinstCTradeWnd_x                                           0xDB1C08
#define pinstCTrainWnd_x                                           0xDB23C4
#define pinstCTributeBenefitWnd_x                                  0x102B598
#define pinstCTributeMasterWnd_x                                   0x102B648
#define pinstCTributeTrophyWnd_x                                   0x102B6F8
#define pinstCVideoModesWnd_x                                      0xDB1C68
#define pinstCVoiceMacroWnd_x                                      0xF157B0
#define pinstCVoteResultsWnd_x                                     0xDB2384
#define pinstCVoteWnd_x                                            0xDB1EF0
#define pinstCWebManager_x                                         0xF15914
#define pinstCZoneGuideWnd_x                                       0xDB1BD8
#define pinstCZonePathWnd_x                                        0xDB1BE8

#define pinstEQSuiteTextureLoader_x                                0xC5B6F8
#define pinstItemIconCache_x                                       0x1024550
#define pinstLootFiltersManager_x                                  0xC81A38
#define pinstRewardSelectionWnd_x                                  0x10295E0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC0C114
#define __CastRay_x                                                0x5921E0
#define __CastRay2_x                                               0x592230
#define __ConvertItemTags_x                                        0x5ACDE0
#define __CrashHandler_x                                           0x843C20
#define __EQGetTime_x                                              0x8E2A30
#define __ExecuteCmd_x                                             0x58AB50
#define __FixHeading_x                                             0x9736D0
#define __get_bearing_x                                            0x591D30
#define __get_melee_range_x                                        0x592420
#define __GetAnimationCache_x                                      0x701650
#define __GetGaugeValueFromEQ_x                                    0x7F55F0
#define __GetLabelFromEQ_x                                         0x7F6D60
#define __GetXTargetType_x                                         0x975130
#define __HeadingDiff_x                                            0x973740
#define __HelpPath_x                                               0xF12C64
#define __LoadFrontEnd_x                                           0x6996E0
#define __NewUIINI_x                                               0x7F52C0
#define __pCrashHandler_x                                          0x1048AE8
#define __ProcessGameEvents_x                                      0x5EFC40
#define __ProcessMouseEvent_x                                      0x5EF400
#define __SaveColors_x                                             0x53B4C0
#define __STMLToText_x                                             0x916690
#define __ToggleKeyRingItem_x                                      0x4FE480
#define CrashDetected_x                                            0x69B1D0
#define DrawNetStatus_x                                            0x61BE60
#define Expansion_HoT_x                                            0xE74BD4
#define Teleport_Table_Size_x                                      0xE63D2C
#define Teleport_Table_x                                           0xE64418
#define Util__FastTime_x                                           0x8E25F0
#define wwsCrashReportCheckForUploader_x                           0x844B20
#define wwsCrashReportPlatformLaunchUploader_x                     0x8471E0
#define __HandleMouseWheel_x                                       0x69D930

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48AF40
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x493DC0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x493B80

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x542E80
#define AltAdvManager__IsAbilityReady_x                            0x541F00
#define AltAdvManager__GetAAById_x                                 0x542100
#define AltAdvManager__CanTrainAbility_x                           0x542170
#define AltAdvManager__CanSeeAbility_x                             0x5423A0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C6B30
#define CharacterZoneClient__HasSkill_x                            0x4D17F0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D2F10
#define CharacterZoneClient__IsStackBlocked_x                      0x4BAF20
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B7690
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D58C0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D59A0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D5A80
#define CharacterZoneClient__FindAffectSlot_x                      0x4BFA00
#define CharacterZoneClient__BardCastBard_x                        0x4C2660
#define CharacterZoneClient__GetMaxEffects_x                       0x4B7760
#define CharacterZoneClient__GetEffect_x                           0x4B75D0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C0A00
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C0AD0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C0B20
#define CharacterZoneClient__CalcAffectChange_x                    0x4C0C70
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C0E40

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6C3A30

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6D1290

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5FE500
#define CButtonWnd__CButtonWnd_x                                   0x912A80

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6F0030
#define CChatManager__InitContextMenu_x                            0x6EA0D0
#define CChatManager__FreeChatWindow_x                             0x6EEF40
#define CChatManager__GetLockedActiveChatWindow_x                  0x6F3900
#define CChatManager__SetLockedActiveChatWindow_x                  0x6EFDD0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x927290
#define CContextMenu__dCContextMenu_x                              0x9274C0
#define CContextMenu__AddMenuItem_x                                0x9274D0
#define CContextMenu__RemoveMenuItem_x                             0x9277E0
#define CContextMenu__RemoveAllMenuItems_x                         0x927800
#define CContextMenu__CheckMenuItem_x                              0x927880
#define CContextMenu__SetMenuItem_x                                0x927700
#define CContextMenu__AddSeparator_x                               0x927660

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x927E20
#define CContextMenuManager__RemoveMenu_x                          0x927E90
#define CContextMenuManager__PopupMenu_x                           0x927F50
#define CContextMenuManager__Flush_x                               0x927DC0
#define CContextMenuManager__GetMenu_x                             0x496040

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8C3340
#define CChatService__GetFriendName_x                              0x8C3350

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6F05B0
#define CChatWindow__Clear_x                                       0x6F1610
#define CChatWindow__WndNotification_x                             0x6F1B80

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x924720
#define CComboWnd__Draw_x                                          0x923C00
#define CComboWnd__GetCurChoice_x                                  0x924560
#define CComboWnd__GetListRect_x                                   0x9240C0
#define CComboWnd__GetTextRect_x                                   0x924790
#define CComboWnd__InsertChoice_x                                  0x924250
#define CComboWnd__SetColors_x                                     0x924220
#define CComboWnd__SetChoice_x                                     0x924530
#define CComboWnd__GetItemCount_x                                  0x924570
#define CComboWnd__GetCurChoiceText_x                              0x9245B0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6F9800
#define CContainerWnd__vftable_x                                   0xAD1F88
#define CContainerWnd__SetContainer_x                              0x6FAD70

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x53B280
#define CDisplay__GetClickedActor_x                                0x52E280
#define CDisplay__GetUserDefinedColor_x                            0x526960
#define CDisplay__GetWorldFilePath_x                               0x52FCD0
#define CDisplay__is3dON_x                                         0x52AF50
#define CDisplay__ReloadUI_x                                       0x5353F0
#define CDisplay__WriteTextHD2_x                                   0x52AD30
#define CDisplay__TrueDistance_x                                   0x531930
#define CDisplay__SetViewActor_x                                   0x52DBD0
#define CDisplay__GetFloorHeight_x                                 0x52B010
#define CDisplay__SetRenderWindow_x                                0x529940
#define CDisplay__ToggleScreenshotMode_x                           0x52D6A0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x946E20

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x92B9B0
#define CEditWnd__GetCharIndexPt_x                                 0x92C8B0
#define CEditWnd__GetDisplayString_x                               0x92C750
#define CEditWnd__GetHorzOffset_x                                  0x92AFE0
#define CEditWnd__GetLineForPrintableChar_x                        0x92D9F0
#define CEditWnd__GetSelStartPt_x                                  0x92CB60
#define CEditWnd__GetSTMLSafeText_x                                0x92C570
#define CEditWnd__PointFromPrintableChar_x                         0x92D620
#define CEditWnd__SelectableCharFromPoint_x                        0x92D790
#define CEditWnd__SetEditable_x                                    0x92CC30

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5DDF40
#define CEverQuest__ClickedPlayer_x                                0x5D0290
#define CEverQuest__CreateTargetIndicator_x                        0x5ECEF0
#define CEverQuest__DeleteTargetIndicator_x                        0x5ECF80
#define CEverQuest__DoTellWindow_x                                 0x4E2AD0
#define CEverQuest__OutputTextToLog_x                              0x4E2D00
#define CEverQuest__DropHeldItemOnGround_x                         0x5C5B50
#define CEverQuest__dsp_chat_x                                     0x4E3090
#define CEverQuest__trimName_x                                     0x5E9460
#define CEverQuest__Emote_x                                        0x5DE750
#define CEverQuest__EnterZone_x                                    0x5D8930
#define CEverQuest__GetBodyTypeDesc_x                              0x5E2D00
#define CEverQuest__GetClassDesc_x                                 0x5E3340
#define CEverQuest__GetClassThreeLetterCode_x                      0x5E3940
#define CEverQuest__GetDeityDesc_x                                 0x5EB840
#define CEverQuest__GetLangDesc_x                                  0x5E3B00
#define CEverQuest__GetRaceDesc_x                                  0x5E3320
#define CEverQuest__InterpretCmd_x                                 0x5EBE10
#define CEverQuest__LeftClickedOnPlayer_x                          0x5C9D40
#define CEverQuest__LMouseUp_x                                     0x5C80C0
#define CEverQuest__RightClickedOnPlayer_x                         0x5CA620
#define CEverQuest__RMouseUp_x                                     0x5C9050
#define CEverQuest__SetGameState_x                                 0x5C58E0
#define CEverQuest__UPCNotificationFlush_x                         0x5E9360
#define CEverQuest__IssuePetCommand_x                              0x5E4F00
#define CEverQuest__ReportSuccessfulHit_x                          0x5DFB50

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x70B650
#define CGaugeWnd__CalcLinesFillRect_x                             0x70B6B0
#define CGaugeWnd__Draw_x                                          0x70AD50

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AC520
#define CGuild__GetGuildName_x                                     0x4AB600
#define CGuild__GetGuildIndex_x                                    0x4AB990

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x726A40

//CHotButton
#define CHotButton__SetButtonSize_x                                0x5FE8C0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x7339C0
#define CInvSlotMgr__MoveItem_x                                    0x732720
#define CInvSlotMgr__SelectSlot_x                                  0x733A90

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x730FD0
#define CInvSlot__SliderComplete_x                                 0x72ED30
#define CInvSlot__GetItemBase_x                                    0x72E6D0
#define CInvSlot__UpdateItem_x                                     0x72E840

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7353E0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7346B0
#define CInvSlotWnd__HandleLButtonUp_x                             0x734F60

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7F17D0
#define CItemDisplayWnd__UpdateStrings_x                           0x743340
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x73D460
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x73D960
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x743920
#define CItemDisplayWnd__AboutToShow_x                             0x742F80
#define CItemDisplayWnd__WndNotification_x                         0x744E50

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x829090

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x748F60

// CLabel 
#define CLabel__Draw_x                                             0x74EA20

// CListWnd
#define CListWnd__CListWnd_x                                       0x8FCD70
#define CListWnd__dCListWnd_x                                      0x8FD090
#define CListWnd__AddColumn_x                                      0x9013D0
#define CListWnd__AddColumn1_x                                     0x901420
#define CListWnd__AddLine_x                                        0x9017B0
#define CListWnd__AddString_x                                      0x9015B0
#define CListWnd__CalculateFirstVisibleLine_x                      0x901190
#define CListWnd__CalculateVSBRange_x                              0x900F70
#define CListWnd__ClearSel_x                                       0x901F90
#define CListWnd__ClearAllSel_x                                    0x901FF0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x902A00
#define CListWnd__Compare_x                                        0x9008B0
#define CListWnd__Draw_x                                           0x8FD190
#define CListWnd__DrawColumnSeparators_x                           0x8FF980
#define CListWnd__DrawHeader_x                                     0x8FFDF0
#define CListWnd__DrawItem_x                                       0x9001F0
#define CListWnd__DrawLine_x                                       0x8FFAF0
#define CListWnd__DrawSeparator_x                                  0x8FFA20
#define CListWnd__EnableLine_x                                     0x8FF250
#define CListWnd__EnsureVisible_x                                  0x902920
#define CListWnd__ExtendSel_x                                      0x901EC0
#define CListWnd__GetColumnMinWidth_x                              0x8FED90
#define CListWnd__GetColumnWidth_x                                 0x8FED00
#define CListWnd__GetCurSel_x                                      0x8FE690
#define CListWnd__GetItemAtPoint_x                                 0x8FF4D0
#define CListWnd__GetItemAtPoint1_x                                0x8FF540
#define CListWnd__GetItemData_x                                    0x8FE710
#define CListWnd__GetItemHeight_x                                  0x8FEAD0
#define CListWnd__GetItemIcon_x                                    0x8FE8A0
#define CListWnd__GetItemRect_x                                    0x8FF340
#define CListWnd__GetItemText_x                                    0x8FE750
#define CListWnd__GetSelList_x                                     0x902040
#define CListWnd__GetSeparatorRect_x                               0x8FF780
#define CListWnd__InsertLine_x                                     0x901BA0
#define CListWnd__RemoveLine_x                                     0x901CF0
#define CListWnd__SetColors_x                                      0x900F40
#define CListWnd__SetColumnJustification_x                         0x900C70
#define CListWnd__SetColumnWidth_x                                 0x900B90
#define CListWnd__SetCurSel_x                                      0x901E00
#define CListWnd__SetItemColor_x                                   0x9025D0
#define CListWnd__SetItemData_x                                    0x902590
#define CListWnd__SetItemText_x                                    0x9021C0
#define CListWnd__ShiftColumnSeparator_x                           0x900D30
#define CListWnd__Sort_x                                           0x900A30
#define CListWnd__ToggleSel_x                                      0x901E30

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x764100
#define CMapViewWnd__GetWorldCoordinates_x                         0x762810
#define CMapViewWnd__HandleLButtonDown_x                           0x75F870

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7872F0
// CMerchantWnd__RequestBuyItem_x                             
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x787BD0
// CMerchantWnd__RequestSellItem_x
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x788100
#define CMerchantWnd__SelectRecoverySlot_x                         0x78AF20
//CMerchantWnd__SelectBuySellSlot_x before
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x785CE0
//CMerchantWnd__ActualSelect_x
#define CMerchantWnd__SelectBuySellSlot_x                          0x790B00
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x786F30

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x891170
#define CPacketScrambler__hton_x                                   0x891160

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x91BC90
#define CSidlManager__FindScreenPieceTemplate_x                    0x91C0A0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x91BE90
#define CSidlManager__CreateLabel_x                                0x7E8BE0
#define CSidlManager__CreateXWndFromTemplate_x                     0x91F170
#define CSidlManager__CreateXWndFromTemplate1_x                    0x91F350
#define CSidlManager__CreateXWnd_x                                 0x7E8B10
#define CSidlManager__CreateHotButtonWnd_x                         0x7E90C0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x918810
#define CSidlScreenWnd__CalculateVSBRange_x                        0x918700
#define CSidlScreenWnd__ConvertToRes_x                             0x93DC70
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x918190
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x917E80
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x917F50
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x918020
#define CSidlScreenWnd__DrawSidlPiece_x                            0x918CB0
#define CSidlScreenWnd__EnableIniStorage_x                         0x919180
#define CSidlScreenWnd__GetSidlPiece_x                             0x918EA0
#define CSidlScreenWnd__Init1_x                                    0x917A70
#define CSidlScreenWnd__LoadIniInfo_x                              0x9191D0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x919D00
#define CSidlScreenWnd__LoadSidlScreen_x                           0x916E70
#define CSidlScreenWnd__StoreIniInfo_x                             0x919880
#define CSidlScreenWnd__StoreIniVis_x                              0x919BE0
#define CSidlScreenWnd__WndNotification_x                          0x918BC0
#define CSidlScreenWnd__GetChildItem_x                             0x919100
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9088F0
#define CSidlScreenWnd__m_layoutCopy_x                             0x16A3A58

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x662CC0
#define CSkillMgr__GetSkillCap_x                                   0x662EA0
#define CSkillMgr__GetNameToken_x                                  0x662450

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x928C30
#define CSliderWnd__SetValue_x                                     0x928AA0
#define CSliderWnd__SetNumTicks_x                                  0x928B00

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7EEA40

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x92F8A0
#define CStmlWnd__CalculateHSBRange_x                              0x930930
#define CStmlWnd__CalculateVSBRange_x                              0x9308A0
#define CStmlWnd__CanBreakAtCharacter_x                            0x934C70
#define CStmlWnd__FastForwardToEndOfTag_x                          0x935860
#define CStmlWnd__ForceParseNow_x                                  0x92FE40
#define CStmlWnd__GetNextTagPiece_x                                0x934BD0
#define CStmlWnd__GetSTMLText_x                                    0x4F0E70
#define CStmlWnd__GetVisibleText_x                                 0x92FE60
#define CStmlWnd__InitializeWindowVariables_x                      0x9356B0
#define CStmlWnd__MakeStmlColorTag_x                               0x92F030
#define CStmlWnd__MakeWndNotificationTag_x                         0x92F0A0
#define CStmlWnd__SetSTMLText_x                                    0x92E100
#define CStmlWnd__StripFirstSTMLLines_x                            0x9369C0
#define CStmlWnd__UpdateHistoryString_x                            0x935A70

// CTabWnd 
#define CTabWnd__Draw_x                                            0x93A6E0
#define CTabWnd__DrawCurrentPage_x                                 0x93AD00
#define CTabWnd__DrawTab_x                                         0x93AAD0
#define CTabWnd__GetCurrentPage_x                                  0x939F40
#define CTabWnd__GetPageInnerRect_x                                0x93A180
#define CTabWnd__GetTabInnerRect_x                                 0x93A0C0
#define CTabWnd__GetTabRect_x                                      0x939F70
#define CTabWnd__InsertPage_x                                      0x93A370
#define CTabWnd__SetPage_x                                         0x93A200
#define CTabWnd__SetPageRect_x                                     0x93A620
#define CTabWnd__UpdatePage_x                                      0x93A990
#define CTabWnd__GetPageFromTabIndex_x                             0x93AA10
#define CTabWnd__GetCurrentTabIndex_x                              0x939F30

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x7493C0
#define CPageWnd__SetTabText_x                                     0x947240

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A6130

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x905740
#define CTextureFont__GetTextExtent_x                              0x905900

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x696520
#define CHtmlComponentWnd__ValidateUri_x                           0x728430
#define CHtmlWnd__SetClientCallbacks_x                             0x603860
#define CHtmlWnd__AddObserver_x                                    0x603880
#define CHtmlWnd__RemoveObserver_x                                 0x6038E0
#define Window__getProgress_x                                      0x841880
#define Window__getStatus_x                                        0x8418A0
#define Window__getURI_x                                           0x8418B0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9437B0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8F2690

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4AD880
#define CXStr__CXStr1_x                                            0x47B690
#define CXStr__CXStr3_x                                            0x8DEB20
#define CXStr__dCXStr_x                                            0x472920
#define CXStr__operator_equal_x                                    0x8DED50
#define CXStr__operator_equal1_x                                   0x8DED90
#define CXStr__operator_plus_equal1_x                              0x8DF820

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x926EB0
#define CXWnd__BringToTop_x                                        0x90C050
#define CXWnd__Center_x                                            0x90BBD0
#define CXWnd__ClrFocus_x                                          0x90BA10
#define CXWnd__Destroy_x                                           0x90BAC0
#define CXWnd__DoAllDrawing_x                                      0x908080
#define CXWnd__DrawChildren_x                                      0x908050
#define CXWnd__DrawColoredRect_x                                   0x9084E0
#define CXWnd__DrawTooltip_x                                       0x906BA0
#define CXWnd__DrawTooltipAtPoint_x                                0x906C60
#define CXWnd__GetBorderFrame_x                                    0x908340
#define CXWnd__GetChildWndAt_x                                     0x90C0F0
#define CXWnd__GetClientClipRect_x                                 0x90A350
#define CXWnd__GetScreenClipRect_x                                 0x90A420
#define CXWnd__GetScreenRect_x                                     0x90A5E0
#define CXWnd__GetTooltipRect_x                                    0x908530
#define CXWnd__GetWindowTextA_x                                    0x4977B0
#define CXWnd__IsActive_x                                          0x90EF30
#define CXWnd__IsDescendantOf_x                                    0x90AFD0
#define CXWnd__IsReallyVisible_x                                   0x90B000
#define CXWnd__IsType_x                                            0x90C750
#define CXWnd__Move_x                                              0x90B060
#define CXWnd__Move1_x                                             0x90B110
#define CXWnd__ProcessTransition_x                                 0x90BB80
#define CXWnd__Refade_x                                            0x90B3E0
#define CXWnd__Resize_x                                            0x90B670
#define CXWnd__Right_x                                             0x90BE10
#define CXWnd__SetFocus_x                                          0x90B9D0
#define CXWnd__SetFont_x                                           0x90BA40
#define CXWnd__SetKeyTooltip_x                                     0x90C580
#define CXWnd__SetMouseOver_x                                      0x9094A0
#define CXWnd__StartFade_x                                         0x90AEA0
#define CXWnd__GetChildItem_x                                      0x90C260
#define CXWnd__SetParent_x                                         0x90AD80

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x93ED40

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x90EF70
#define CXWndManager__DrawWindows_x                                0x90EF90
#define CXWndManager__GetKeyboardFlags_x                           0x911700
#define CXWndManager__HandleKeyboardMsg_x                          0x911300
#define CXWndManager__RemoveWnd_x                                  0x911950
#define CXWndManager__RemovePendingDeletionWnd_x                   0x911EA0

// CDBStr
#define CDBStr__GetString_x                                        0x5258F0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B8640
#define EQ_Character__Cur_HP_x                                     0x4CE870
#define EQ_Character__Cur_Mana_x                                   0x4D5F80
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BB560
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AF470
#define EQ_Character__GetFocusRangeModifier_x                      0x4AF5C0
#define EQ_Character__GetHPRegen_x                                 0x4DBEE0
#define EQ_Character__GetEnduranceRegen_x                          0x4DC4F0
#define EQ_Character__GetManaRegen_x                               0x4DC930
#define EQ_Character__Max_Endurance_x                              0x629410
#define EQ_Character__Max_HP_x                                     0x4CE6A0
#define EQ_Character__Max_Mana_x                                   0x629210
#define EQ_Character__doCombatAbility_x                            0x62B8D0
#define EQ_Character__UseSkill_x                                   0x4DE720
#define EQ_Character__GetConLevel_x                                0x622BF0
#define EQ_Character__IsExpansionFlag_x                            0x5891F0
#define EQ_Character__TotalEffect_x                                0x4C1BE0
#define EQ_Character__GetPCSpellAffect_x                           0x4BC150
#define EQ_Character__SpellDuration_x                              0x4BBC80
#define EQ_Character__FindItemByRecord_x                           0x4D3E80
#define EQ_Character__GetAdjustedSkill_x                           0x4D15B0
#define EQ_Character__GetBaseSkill_x                               0x4D2550
#define EQ_Character__CanUseItem_x                                 0x4D6290

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8B0270

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x63F700

//PcClient
#define PcClient__PcClient_x                                       0x6204C0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6400
#define CCharacterListWnd__EnterWorld_x                            0x4B5E40
#define CCharacterListWnd__Quit_x                                  0x4B5B50
#define CCharacterListWnd__UpdateList_x                            0x4B5FD0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x604A80
#define EQ_Item__CreateItemTagString_x                             0x88AAD0
#define EQ_Item__IsStackable_x                                     0x88F510
#define EQ_Item__GetImageNum_x                                     0x88C4E0
#define EQ_Item__CreateItemClient_x                                0x603C40
#define EQ_Item__GetItemValue_x                                    0x88D760
#define EQ_Item__ValueSellMerchant_x                               0x890D00
#define EQ_Item__IsKeyRingItem_x                                   0x88EE60
#define EQ_Item__CanGoInBag_x                                      0x604BA0
#define EQ_Item__GetMaxItemCount_x                                 0x88DB30
#define EQ_Item__GetHeldItem_x                                     0x88C3B0
#define EQ_Item__GetAugmentFitBySlot_x                             0x88A420

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x543B60
#define EQ_LoadingS__Array_x                                       0xBE37A0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x629D70
#define EQ_PC__GetAlternateAbilityId_x                             0x899E90
#define EQ_PC__GetCombatAbility_x                                  0x89A500
#define EQ_PC__GetCombatAbilityTimer_x                             0x89A570
#define EQ_PC__GetItemRecastTimer_x                                0x62BE50
#define EQ_PC__HasLoreItem_x                                       0x6233C0
#define EQ_PC__AlertInventoryChanged_x                             0x6226C0
#define EQ_PC__GetPcZoneClient_x                                   0x64DEB0
#define EQ_PC__RemoveMyAffect_x                                    0x62F040
#define EQ_PC__GetKeyRingItems_x                                   0x89AE10
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x89AB90
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x89B100

// EQItemList 
#define EQItemList__EQItemList_x                                   0x58F760
#define EQItemList__add_object_x                                   0x5BB1A0
#define EQItemList__add_item_x                                     0x58FD70
#define EQItemList__delete_item_x                                  0x58FDC0
#define EQItemList__FreeItemList_x                                 0x58FCC0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x522F20

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x640F80
#define EQPlayer__dEQPlayer_x                                      0x634660
#define EQPlayer__DoAttack_x                                       0x648BB0
#define EQPlayer__EQPlayer_x                                       0x634D10
#define EQPlayer__SetNameSpriteState_x                             0x638FB0
#define EQPlayer__SetNameSpriteTint_x                              0x639E80
#define PlayerBase__HasProperty_j_x                                0x971AB0
#define EQPlayer__IsTargetable_x                                   0x971F50
#define EQPlayer__CanSee_x                                         0x971DB0
#define EQPlayer__CanSee1_x                                        0x971E80
#define PlayerBase__GetVisibilityLineSegment_x                     0x971B70

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x64B980
#define PlayerZoneClient__GetLevel_x                               0x64DEF0
#define PlayerZoneClient__IsValidTeleport_x                        0x5BC2F0
#define PlayerZoneClient__LegalPlayerRace_x                        0x53D080

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x643CF0
#define EQPlayerManager__GetSpawnByName_x                          0x643D10
#define EQPlayerManager__GetPlayerFromPartialName_x                0x643DA0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x608400
#define KeypressHandler__AttachKeyToEqCommand_x                    0x608440
#define KeypressHandler__ClearCommandStateArray_x                  0x609830
#define KeypressHandler__HandleKeyDown_x                           0x609850
#define KeypressHandler__HandleKeyUp_x                             0x6098F0
#define KeypressHandler__SaveKeymapping_x                          0x609CD0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x75FF90
#define MapViewMap__SaveEx_x                                       0x763330
#define MapViewMap__SetZoom_x                                      0x767A10

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8AE0B0

// StringTable 
#define StringTable__getString_x                                   0x8A8F90

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x62ECB0
#define PcZoneClient__RemovePetEffect_x                            0x62F2E0
#define PcZoneClient__HasAlternateAbility_x                        0x629050
#define PcZoneClient__GetCurrentMod_x                              0x4E1820
#define PcZoneClient__GetModCap_x                                  0x4E1720
#define PcZoneClient__CanEquipItem_x                               0x629700
#define PcZoneClient__GetItemByID_x                                0x62C2C0
#define PcZoneClient__GetItemByItemClass_x                         0x62C410
#define PcZoneClient__RemoveBuffEffect_x                           0x62F300
#define PcZoneClient__BandolierSwap_x                              0x62A330

//Doors
#define EQSwitch__UseSwitch_x                                      0x5C0F50

//IconCache
#define IconCache__GetIcon_x                                       0x700EE0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6F89A0
#define CContainerMgr__CloseContainer_x                            0x6F8C70
#define CContainerMgr__OpenExperimentContainer_x                   0x6F96F0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7BB140

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5FCCE0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x7563B0
#define CLootWnd__RequestLootSlot_x                                0x755770

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x55C110
#define EQ_Spell__SpellAffects_x                                   0x55C580
#define EQ_Spell__SpellAffectBase_x                                0x55C340
#define EQ_Spell__IsStackable_x                                    0x4C6450
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C6300
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B39A0
#define EQ_Spell__IsSPAStacking_x                                  0x55D3B0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x55C8D0
#define EQ_Spell__IsNoRemove_x                                     0x4C6430
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x55D3C0
#define __IsResEffectSpell_x                                       0x4C5720

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AA270

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8B8800

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x800B60
#define CTargetWnd__WndNotification_x                              0x8003F0
#define CTargetWnd__RefreshTargetBuffs_x                           0x8006C0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x7FF550

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x805230

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5576B0
#define EqSoundManager__PlayScriptMp3_x                            0x557810
#define EqSoundManager__SoundAssistPlay_x                          0x666B70
#define EqSoundManager__WaveInstancePlay_x                         0x6660E0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x514800

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x92A610

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x54B990
#define CAltAbilityData__GetMercMaxRank_x                          0x54B930
#define CAltAbilityData__GetMaxRank_x                              0x540DB0

//CTargetRing
#define CTargetRing__Cast_x                                        0x5FADE0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C62E0
#define CharacterBase__CreateItemGlobalIndex_x                     0x4FA870
#define CharacterBase__CreateItemIndex_x                           0x602EA0
#define CharacterBase__GetItemPossession_x                         0x4B3850
#define CharacterBase__GetItemByGlobalIndex_x                      0x8C0E70
#define CharacterBase__GetEffectId_x                               0x4C6290

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6E0A30
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6E1250

//messages
#define msg_spell_worn_off_x                                       0x5811A0
#define msg_new_text_x                                             0x5760A0
#define __msgTokenTextParam_x                                      0x5837F0
#define msgTokenText_x                                             0x583A40

//SpellManager
#define SpellManager__vftable_x                                    0xAAC8B0
#define SpellManager__SpellManager_x                               0x669EA0
#define Spellmanager__LoadTextSpells_x                             0x66A770
#define SpellManager__GetSpellByGroupAndRank_x                     0x66A070

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x975A20

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4FAF60
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x587640
#define ItemGlobalIndex__IsEquippedLocation_x                      0x5891D0
#define ItemGlobalIndex__IsValidIndex_x                            0x4FAFC0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8B9140
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8B93C0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x74ED60

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6FD100
#define CCursorAttachment__Deactivate_x                            0x6FE0E0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x93D200
#define CEQSuiteTextureLoader__GetTexture_x                        0x93CEC0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4F7F10

//IString
#define IString__Append_x                                          0x4EAEF0

//Camera
#define CDisplay__cameraType_x                                     0xDB1CC8
#define EverQuest__Cameras_x                                       0xE74F10

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x5006F0
#define LootFiltersManager__GetItemFilterData_x                    0x4FFFF0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x500020
#define LootFiltersManager__SetItemLootFilter_x                    0x500240

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7A9130

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x97B7B0
#define CResolutionHandler__GetWindowedStyle_x                     0x6616E0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6F5760

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8CB840

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x7157C0
#define CGroupWnd__UpdateDisplay_x                                 0x714B20

//ItemBase
#define ItemBase__IsLore_x                                         0x88EEC0
#define ItemBase__IsLoreEquipped_x                                 0x88EF30

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
