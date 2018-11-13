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
#define __ExpectedVersionDate                                     "Nov 13 2018"
#define __ExpectedVersionTime                                     "04:20:18"
#define __ActualVersionDate_x                                      0xAC8B3C
#define __ActualVersionTime_x                                      0xAC8B30

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x60E600
#define __MemChecker1_x                                            0x8E3020
#define __MemChecker2_x                                            0x69D470
#define __MemChecker3_x                                            0x69D3C0
#define __MemChecker4_x                                            0x83A160
#define __EncryptPad0_x                                            0xBFB998
#define __EncryptPad1_x                                            0xC59C28
#define __EncryptPad2_x                                            0xC0C520
#define __EncryptPad3_x                                            0xC0C120
#define __EncryptPad4_x                                            0xC4A498
#define __EncryptPad5_x                                            0xF15B2C
#define __AC1_x                                                    0x7F6B06
#define __AC2_x                                                    0x5C954F
#define __AC3_x                                                    0x5D03DF
#define __AC4_x                                                    0x5D4250
#define __AC5_x                                                    0x5DA40F
#define __AC6_x                                                    0x5DE946
#define __AC7_x                                                    0x5C8FC0
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
#define __do_loot_x                                                0x596C60
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
#define __gfMaxCameraDistance_x                                    0xAEB5BC
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
#define __CastRay_x                                                0x592190
#define __CastRay2_x                                               0x5921E0
#define __ConvertItemTags_x                                        0x5ACD70
#define __CrashHandler_x                                           0x843B30
#define __EQGetTime_x                                              0x8E2B10
#define __ExecuteCmd_x                                             0x58AB00
#define __FixHeading_x                                             0x973670
#define __get_bearing_x                                            0x591CE0
#define __get_melee_range_x                                        0x5923D0
#define __GetAnimationCache_x                                      0x7011C0
#define __GetGaugeValueFromEQ_x                                    0x7F5320
#define __GetLabelFromEQ_x                                         0x7F6A90
#define __GetXTargetType_x                                         0x9750D0
#define __HeadingDiff_x                                            0x9736E0
#define __HelpPath_x                                               0xF12C64
#define __LoadFrontEnd_x                                           0x6992D0
#define __NewUIINI_x                                               0x7F4FF0
#define __pCrashHandler_x                                          0x1048AE8
#define __ProcessGameEvents_x                                      0x5EFB60
#define __ProcessMouseEvent_x                                      0x5EF320
#define __SaveColors_x                                             0x53B7A0
#define __STMLToText_x                                             0x916830
#define __ToggleKeyRingItem_x                                      0x4FE490
#define CrashDetected_x                                            0x69ADC0
#define DrawNetStatus_x                                            0x61BAD0
#define Expansion_HoT_x                                            0xE74BD4
#define Teleport_Table_Size_x                                      0xE63D2C
#define Teleport_Table_x                                           0xE64418
#define Util__FastTime_x                                           0x8E26D0
#define wwsCrashReportCheckForUploader_x                           0x8448E0
#define wwsCrashReportPlatformLaunchUploader_x                     0x846FA0
#define __HandleMouseWheel_x                                       0x69D520

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48AFF0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x493E70
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x493C30

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x543110
#define AltAdvManager__IsAbilityReady_x                            0x542190
#define AltAdvManager__GetAAById_x                                 0x542390
#define AltAdvManager__CanTrainAbility_x                           0x542400
#define AltAdvManager__CanSeeAbility_x                             0x542630

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C6B70
#define CharacterZoneClient__HasSkill_x                            0x4D1830
#define CharacterZoneClient__MakeMeVisible_x                       0x4D2F50
#define CharacterZoneClient__IsStackBlocked_x                      0x4BAFA0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B7720
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D5910
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D59F0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D5AD0
#define CharacterZoneClient__FindAffectSlot_x                      0x4BFA80
#define CharacterZoneClient__BardCastBard_x                        0x4C26F0
#define CharacterZoneClient__GetMaxEffects_x                       0x4B77F0
#define CharacterZoneClient__GetEffect_x                           0x4B7660
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C0A80
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C0B50
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C0BA0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C0CF0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C0EC0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6C36C0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6D0F20

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5FE370
#define CButtonWnd__CButtonWnd_x                                   0x912C60

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6EFAF0
#define CChatManager__InitContextMenu_x                            0x6E9B90
#define CChatManager__FreeChatWindow_x                             0x6EEA00
#define CChatManager__GetLockedActiveChatWindow_x                  0x6F33B0
#define CChatManager__SetLockedActiveChatWindow_x                  0x6EF890

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x927470
#define CContextMenu__dCContextMenu_x                              0x9276A0
#define CContextMenu__AddMenuItem_x                                0x9276B0
#define CContextMenu__RemoveMenuItem_x                             0x9279B0
#define CContextMenu__RemoveAllMenuItems_x                         0x9279D0
#define CContextMenu__CheckMenuItem_x                              0x927A50
#define CContextMenu__SetMenuItem_x                                0x9278E0
#define CContextMenu__AddSeparator_x                               0x927840

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x927FE0
#define CContextMenuManager__RemoveMenu_x                          0x928050
#define CContextMenuManager__PopupMenu_x                           0x928110
#define CContextMenuManager__Flush_x                               0x927F80
#define CContextMenuManager__GetMenu_x                             0x495F90

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8C3420
#define CChatService__GetFriendName_x                              0x8C3430

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6F0070
#define CChatWindow__Clear_x                                       0x6F10C0
#define CChatWindow__WndNotification_x                             0x6F1630

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x924910
#define CComboWnd__Draw_x                                          0x923E20
#define CComboWnd__GetCurChoice_x                                  0x924750
#define CComboWnd__GetListRect_x                                   0x9242C0
#define CComboWnd__GetTextRect_x                                   0x924970
#define CComboWnd__InsertChoice_x                                  0x924450
#define CComboWnd__SetColors_x                                     0x924420
#define CComboWnd__SetChoice_x                                     0x924720
#define CComboWnd__GetItemCount_x                                  0x924760
#define CComboWnd__GetCurChoiceText_x                              0x9247A0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6F9360
#define CContainerWnd__vftable_x                                   0xAD1F40
#define CContainerWnd__SetContainer_x                              0x6FA8D0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x53B560
#define CDisplay__GetClickedActor_x                                0x52E560
#define CDisplay__GetUserDefinedColor_x                            0x526C40
#define CDisplay__GetWorldFilePath_x                               0x52FFB0
#define CDisplay__is3dON_x                                         0x52B230
#define CDisplay__ReloadUI_x                                       0x5356D0
#define CDisplay__WriteTextHD2_x                                   0x52B010
#define CDisplay__TrueDistance_x                                   0x531C10
#define CDisplay__SetViewActor_x                                   0x52DEB0
#define CDisplay__GetFloorHeight_x                                 0x52B2F0
#define CDisplay__SetRenderWindow_x                                0x529C20
#define CDisplay__ToggleScreenshotMode_x                           0x52D980

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x946EC0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x92BB40
#define CEditWnd__GetCharIndexPt_x                                 0x92CA30
#define CEditWnd__GetDisplayString_x                               0x92C8D0
#define CEditWnd__GetHorzOffset_x                                  0x92B170
#define CEditWnd__GetLineForPrintableChar_x                        0x92DB70
#define CEditWnd__GetSelStartPt_x                                  0x92CCE0
#define CEditWnd__GetSTMLSafeText_x                                0x92C6F0
#define CEditWnd__PointFromPrintableChar_x                         0x92D7A0
#define CEditWnd__SelectableCharFromPoint_x                        0x92D910
#define CEditWnd__SetEditable_x                                    0x92CDB0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5DDE70
#define CEverQuest__ClickedPlayer_x                                0x5D01C0
#define CEverQuest__CreateTargetIndicator_x                        0x5ECE10
#define CEverQuest__DeleteTargetIndicator_x                        0x5ECEA0
#define CEverQuest__DoTellWindow_x                                 0x4E2B10
#define CEverQuest__OutputTextToLog_x                              0x4E2D40
#define CEverQuest__DropHeldItemOnGround_x                         0x5C5A80
#define CEverQuest__dsp_chat_x                                     0x4E30D0
#define CEverQuest__trimName_x                                     0x5E9380
#define CEverQuest__Emote_x                                        0x5DE680
#define CEverQuest__EnterZone_x                                    0x5D8860
#define CEverQuest__GetBodyTypeDesc_x                              0x5E2C30
#define CEverQuest__GetClassDesc_x                                 0x5E3270
#define CEverQuest__GetClassThreeLetterCode_x                      0x5E3870
#define CEverQuest__GetDeityDesc_x                                 0x5EB760
#define CEverQuest__GetLangDesc_x                                  0x5E3A30
#define CEverQuest__GetRaceDesc_x                                  0x5E3250
#define CEverQuest__InterpretCmd_x                                 0x5EBD30
#define CEverQuest__LeftClickedOnPlayer_x                          0x5C9C70
#define CEverQuest__LMouseUp_x                                     0x5C7FF0
#define CEverQuest__RightClickedOnPlayer_x                         0x5CA550
#define CEverQuest__RMouseUp_x                                     0x5C8F80
#define CEverQuest__SetGameState_x                                 0x5C5810
#define CEverQuest__UPCNotificationFlush_x                         0x5E9280
#define CEverQuest__IssuePetCommand_x                              0x5E4E30
#define CEverQuest__ReportSuccessfulHit_x                          0x5DFA80

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x70B2E0
#define CGaugeWnd__CalcLinesFillRect_x                             0x70B340
#define CGaugeWnd__Draw_x                                          0x70A9E0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AC660
#define CGuild__GetGuildName_x                                     0x4AB740
#define CGuild__GetGuildIndex_x                                    0x4ABAD0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x726690

//CHotButton
#define CHotButton__SetButtonSize_x                                0x5FE730

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x733680
#define CInvSlotMgr__MoveItem_x                                    0x7323A0
#define CInvSlotMgr__SelectSlot_x                                  0x733750

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x730C50
#define CInvSlot__SliderComplete_x                                 0x72E9B0
#define CInvSlot__GetItemBase_x                                    0x72E320
#define CInvSlot__UpdateItem_x                                     0x72E490

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7350A0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x734370
#define CInvSlotWnd__HandleLButtonUp_x                             0x734C20

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7F1510
#define CItemDisplayWnd__UpdateStrings_x                           0x743060
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x73D0B0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x73D5E0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x743640
#define CItemDisplayWnd__AboutToShow_x                             0x742CA0
#define CItemDisplayWnd__WndNotification_x                         0x744B90

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x828F50

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x748CA0

// CLabel 
#define CLabel__Draw_x                                             0x74E720

// CListWnd
#define CListWnd__CListWnd_x                                       0x8FD120
#define CListWnd__dCListWnd_x                                      0x8FD440
#define CListWnd__AddColumn_x                                      0x901750
#define CListWnd__AddColumn1_x                                     0x9017A0
#define CListWnd__AddLine_x                                        0x901B30
#define CListWnd__AddString_x                                      0x901930
#define CListWnd__CalculateFirstVisibleLine_x                      0x901510
#define CListWnd__CalculateVSBRange_x                              0x9012F0
#define CListWnd__ClearSel_x                                       0x902310
#define CListWnd__ClearAllSel_x                                    0x902370
#define CListWnd__CloseAndUpdateEditWindow_x                       0x902D60
#define CListWnd__Compare_x                                        0x900C30
#define CListWnd__Draw_x                                           0x8FD540
#define CListWnd__DrawColumnSeparators_x                           0x8FFD10
#define CListWnd__DrawHeader_x                                     0x900180
#define CListWnd__DrawItem_x                                       0x900570
#define CListWnd__DrawLine_x                                       0x8FFE80
#define CListWnd__DrawSeparator_x                                  0x8FFDB0
#define CListWnd__EnableLine_x                                     0x8FF5F0
#define CListWnd__EnsureVisible_x                                  0x902C90
#define CListWnd__ExtendSel_x                                      0x902240
#define CListWnd__GetColumnMinWidth_x                              0x8FF130
#define CListWnd__GetColumnWidth_x                                 0x8FF0A0
#define CListWnd__GetCurSel_x                                      0x8FEA30
#define CListWnd__GetItemAtPoint_x                                 0x8FF860
#define CListWnd__GetItemAtPoint1_x                                0x8FF8D0
#define CListWnd__GetItemData_x                                    0x8FEAB0
#define CListWnd__GetItemHeight_x                                  0x8FEE70
#define CListWnd__GetItemIcon_x                                    0x8FEC40
#define CListWnd__GetItemRect_x                                    0x8FF6E0
#define CListWnd__GetItemText_x                                    0x8FEAF0
#define CListWnd__GetSelList_x                                     0x9023C0
#define CListWnd__GetSeparatorRect_x                               0x8FFB10
#define CListWnd__InsertLine_x                                     0x901F20
#define CListWnd__RemoveLine_x                                     0x902070
#define CListWnd__SetColors_x                                      0x9012C0
#define CListWnd__SetColumnJustification_x                         0x900FF0
#define CListWnd__SetColumnWidth_x                                 0x900F10
#define CListWnd__SetCurSel_x                                      0x902180
#define CListWnd__SetItemColor_x                                   0x902950
#define CListWnd__SetItemData_x                                    0x902910
#define CListWnd__SetItemText_x                                    0x902540
#define CListWnd__ShiftColumnSeparator_x                           0x9010B0
#define CListWnd__Sort_x                                           0x900DB0
#define CListWnd__ToggleSel_x                                      0x9021B0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x763D10
#define CMapViewWnd__GetWorldCoordinates_x                         0x762420
#define CMapViewWnd__HandleLButtonDown_x                           0x75F480

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x786E70
// CMerchantWnd__RequestBuyItem_x                             
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x787750
// CMerchantWnd__RequestSellItem_x
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x787C90
#define CMerchantWnd__SelectRecoverySlot_x                         0x78AAD0
//CMerchantWnd__SelectBuySellSlot_x before
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x785860
//CMerchantWnd__ActualSelect_x
#define CMerchantWnd__SelectBuySellSlot_x                          0x7906C0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x786AA0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x891170
#define CPacketScrambler__hton_x                                   0x891160

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x91BE30
#define CSidlManager__FindScreenPieceTemplate_x                    0x91C240
#define CSidlManager__FindScreenPieceTemplate1_x                   0x91C030
#define CSidlManager__CreateLabel_x                                0x7E8920
#define CSidlManager__CreateXWndFromTemplate_x                     0x91F310
#define CSidlManager__CreateXWndFromTemplate1_x                    0x91F4F0
#define CSidlManager__CreateXWnd_x                                 0x7E8850
#define CSidlManager__CreateHotButtonWnd_x                         0x7E8E20

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9189B0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9188A0
#define CSidlScreenWnd__ConvertToRes_x                             0x93DD00
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x918330
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x918020
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x9180F0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x9181C0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x918E50
#define CSidlScreenWnd__EnableIniStorage_x                         0x919320
#define CSidlScreenWnd__GetSidlPiece_x                             0x919040
#define CSidlScreenWnd__Init1_x                                    0x917C10
#define CSidlScreenWnd__LoadIniInfo_x                              0x919370
#define CSidlScreenWnd__LoadIniListWnd_x                           0x919E90
#define CSidlScreenWnd__LoadSidlScreen_x                           0x917010
#define CSidlScreenWnd__StoreIniInfo_x                             0x919A10
#define CSidlScreenWnd__StoreIniVis_x                              0x919D70
#define CSidlScreenWnd__WndNotification_x                          0x918D60
#define CSidlScreenWnd__GetChildItem_x                             0x9192A0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x908C20
#define CSidlScreenWnd__m_layoutCopy_x                             0x16A3A58

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6629A0
#define CSkillMgr__GetSkillCap_x                                   0x662B80
#define CSkillMgr__GetNameToken_x                                  0x662130

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x928DD0
#define CSliderWnd__SetValue_x                                     0x928C40
#define CSliderWnd__SetNumTicks_x                                  0x928CA0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7EE740

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x92FA20
#define CStmlWnd__CalculateHSBRange_x                              0x930AB0
#define CStmlWnd__CalculateVSBRange_x                              0x930A20
#define CStmlWnd__CanBreakAtCharacter_x                            0x934DF0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x9359E0
#define CStmlWnd__ForceParseNow_x                                  0x92FFC0
#define CStmlWnd__GetNextTagPiece_x                                0x934D50
#define CStmlWnd__GetSTMLText_x                                    0x4F0EF0
#define CStmlWnd__GetVisibleText_x                                 0x92FFE0
#define CStmlWnd__InitializeWindowVariables_x                      0x935830
#define CStmlWnd__MakeStmlColorTag_x                               0x92F1B0
#define CStmlWnd__MakeWndNotificationTag_x                         0x92F220
#define CStmlWnd__SetSTMLText_x                                    0x92E280
#define CStmlWnd__StripFirstSTMLLines_x                            0x936B40
#define CStmlWnd__UpdateHistoryString_x                            0x935BF0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x93A820
#define CTabWnd__DrawCurrentPage_x                                 0x93AE40
#define CTabWnd__DrawTab_x                                         0x93AC10
#define CTabWnd__GetCurrentPage_x                                  0x93A080
#define CTabWnd__GetPageInnerRect_x                                0x93A2C0
#define CTabWnd__GetTabInnerRect_x                                 0x93A200
#define CTabWnd__GetTabRect_x                                      0x93A0B0
#define CTabWnd__InsertPage_x                                      0x93A4B0
#define CTabWnd__SetPage_x                                         0x93A340
#define CTabWnd__SetPageRect_x                                     0x93A760
#define CTabWnd__UpdatePage_x                                      0x93AAD0
#define CTabWnd__GetPageFromTabIndex_x                             0x93AB50
#define CTabWnd__GetCurrentTabIndex_x                              0x93A070

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x749100
#define CPageWnd__SetTabText_x                                     0x9472D0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A6200

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x905AA0
#define CTextureFont__GetTextExtent_x                              0x905C60

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x696120
#define CHtmlComponentWnd__ValidateUri_x                           0x728080
#define CHtmlWnd__SetClientCallbacks_x                             0x603710
#define CHtmlWnd__AddObserver_x                                    0x603730
#define CHtmlWnd__RemoveObserver_x                                 0x603790
#define Window__getProgress_x                                      0x841790
#define Window__getStatus_x                                        0x8417B0
#define Window__getURI_x                                           0x8417C0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x943850

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8F2940

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4AD900
#define CXStr__CXStr1_x                                            0x9B52C0
#define CXStr__CXStr3_x                                            0x8DEC30
#define CXStr__dCXStr_x                                            0x472880
#define CXStr__operator_equal_x                                    0x8DEE60
#define CXStr__operator_equal1_x                                   0x8DEEA0
#define CXStr__operator_plus_equal1_x                              0x8DF930

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x927090
#define CXWnd__BringToTop_x                                        0x90C2C0
#define CXWnd__Center_x                                            0x90BE40
#define CXWnd__ClrFocus_x                                          0x90BC80
#define CXWnd__Destroy_x                                           0x90BD20
#define CXWnd__DoAllDrawing_x                                      0x9083B0
#define CXWnd__DrawChildren_x                                      0x908380
#define CXWnd__DrawColoredRect_x                                   0x908810
#define CXWnd__DrawTooltip_x                                       0x906EF0
#define CXWnd__DrawTooltipAtPoint_x                                0x906FB0
#define CXWnd__GetBorderFrame_x                                    0x908670
#define CXWnd__GetChildWndAt_x                                     0x90C360
#define CXWnd__GetClientClipRect_x                                 0x90A650
#define CXWnd__GetScreenClipRect_x                                 0x90A720
#define CXWnd__GetScreenRect_x                                     0x90A8C0
#define CXWnd__GetTooltipRect_x                                    0x908860
#define CXWnd__GetWindowTextA_x                                    0x4976F0
#define CXWnd__IsActive_x                                          0x90F1B0
#define CXWnd__IsDescendantOf_x                                    0x90B270
#define CXWnd__IsReallyVisible_x                                   0x90B2A0
#define CXWnd__IsType_x                                            0x90C9E0
#define CXWnd__Move_x                                              0x90B310
#define CXWnd__Move1_x                                             0x90B3C0
#define CXWnd__ProcessTransition_x                                 0x90BDF0
#define CXWnd__Refade_x                                            0x90B660
#define CXWnd__Resize_x                                            0x90B8B0
#define CXWnd__Right_x                                             0x90C080
#define CXWnd__SetFocus_x                                          0x90BC40
#define CXWnd__SetFont_x                                           0x90BCB0
#define CXWnd__SetKeyTooltip_x                                     0x90C7F0
#define CXWnd__SetMouseOver_x                                      0x9097D0
#define CXWnd__StartFade_x                                         0x90B150
#define CXWnd__GetChildItem_x                                      0x90C4D0
#define CXWnd__SetParent_x                                         0x90B010

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x93EDD0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x90F1F0
#define CXWndManager__DrawWindows_x                                0x90F210
#define CXWndManager__GetKeyboardFlags_x                           0x9118D0
#define CXWndManager__HandleKeyboardMsg_x                          0x9114D0
#define CXWndManager__RemoveWnd_x                                  0x911B20
#define CXWndManager__RemovePendingDeletionWnd_x                   0x912080

// CDBStr
#define CDBStr__GetString_x                                        0x525B10

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B86D0
#define EQ_Character__Cur_HP_x                                     0x4CE8B0
#define EQ_Character__Cur_Mana_x                                   0x4D5FD0
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BB5E0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AF520
#define EQ_Character__GetFocusRangeModifier_x                      0x4AF670
#define EQ_Character__GetHPRegen_x                                 0x4DBF50
#define EQ_Character__GetEnduranceRegen_x                          0x4DC560
#define EQ_Character__GetManaRegen_x                               0x4DC9A0
#define EQ_Character__Max_Endurance_x                              0x6293F0
#define EQ_Character__Max_HP_x                                     0x4CE6E0
#define EQ_Character__Max_Mana_x                                   0x6291F0
#define EQ_Character__doCombatAbility_x                            0x62B8C0
#define EQ_Character__UseSkill_x                                   0x4DE790
#define EQ_Character__GetConLevel_x                                0x622800
#define EQ_Character__IsExpansionFlag_x                            0x589180
#define EQ_Character__TotalEffect_x                                0x4C1C70
#define EQ_Character__GetPCSpellAffect_x                           0x4BC1D0
#define EQ_Character__SpellDuration_x                              0x4BBD00
#define EQ_Character__FindItemByRecord_x                           0x4D3EC0
#define EQ_Character__GetAdjustedSkill_x                           0x4D15F0
#define EQ_Character__GetBaseSkill_x                               0x4D2590
#define EQ_Character__CanUseItem_x                                 0x4D62E0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8B03E0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x63F6A0

//PcClient
#define PcClient__PcClient_x                                       0x6200E0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6490
#define CCharacterListWnd__EnterWorld_x                            0x4B5ED0
#define CCharacterListWnd__Quit_x                                  0x4B5BE0
#define CCharacterListWnd__UpdateList_x                            0x4B6060

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x604940
#define EQ_Item__CreateItemTagString_x                             0x88AAE0
#define EQ_Item__IsStackable_x                                     0x88F550
#define EQ_Item__GetImageNum_x                                     0x88C530
#define EQ_Item__CreateItemClient_x                                0x603AF0
#define EQ_Item__GetItemValue_x                                    0x88D7B0
#define EQ_Item__ValueSellMerchant_x                               0x890D10
#define EQ_Item__IsKeyRingItem_x                                   0x88EEB0
#define EQ_Item__CanGoInBag_x                                      0x604A60
#define EQ_Item__GetMaxItemCount_x                                 0x88DB70
#define EQ_Item__GetHeldItem_x                                     0x88C400
#define EQ_Item__GetAugmentFitBySlot_x                             0x88A430

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x543E70
#define EQ_LoadingS__Array_x                                       0xBE37A0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x629D50
#define EQ_PC__GetAlternateAbilityId_x                             0x899EE0
#define EQ_PC__GetCombatAbility_x                                  0x89A550
#define EQ_PC__GetCombatAbilityTimer_x                             0x89A5C0
#define EQ_PC__GetItemRecastTimer_x                                0x62BE40
#define EQ_PC__HasLoreItem_x                                       0x622FD0
#define EQ_PC__AlertInventoryChanged_x                             0x6222E0
#define EQ_PC__GetPcZoneClient_x                                   0x64DE90
#define EQ_PC__RemoveMyAffect_x                                    0x62F030
#define EQ_PC__GetKeyRingItems_x                                   0x89AE60
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x89ABE0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x89B150

// EQItemList 
#define EQItemList__EQItemList_x                                   0x58F710
#define EQItemList__add_object_x                                   0x5BB100
#define EQItemList__add_item_x                                     0x58FD20
#define EQItemList__delete_item_x                                  0x58FD70
#define EQItemList__FreeItemList_x                                 0x58FC70

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x523160

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x640F20
#define EQPlayer__dEQPlayer_x                                      0x634640
#define EQPlayer__DoAttack_x                                       0x648B90
#define EQPlayer__EQPlayer_x                                       0x634CF0
#define EQPlayer__SetNameSpriteState_x                             0x638F50
#define EQPlayer__SetNameSpriteTint_x                              0x639E20
#define PlayerBase__HasProperty_j_x                                0x971A50
#define EQPlayer__IsTargetable_x                                   0x971EF0
#define EQPlayer__CanSee_x                                         0x971D50
#define EQPlayer__CanSee1_x                                        0x971E20
#define PlayerBase__GetVisibilityLineSegment_x                     0x971B10

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x64B960
#define PlayerZoneClient__GetLevel_x                               0x64DED0
#define PlayerZoneClient__IsValidTeleport_x                        0x5BC260
#define PlayerZoneClient__LegalPlayerRace_x                        0x53D2E0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x643CB0
#define EQPlayerManager__GetSpawnByName_x                          0x643CD0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x643D60

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x6081F0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x608230
#define KeypressHandler__ClearCommandStateArray_x                  0x609620
#define KeypressHandler__HandleKeyDown_x                           0x609640
#define KeypressHandler__HandleKeyUp_x                             0x6096E0
#define KeypressHandler__SaveKeymapping_x                          0x609AC0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x75FBA0
#define MapViewMap__SaveEx_x                                       0x762F40
#define MapViewMap__SetZoom_x                                      0x767610

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8AE2D0

// StringTable 
#define StringTable__getString_x                                   0x8A91C0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x62ECA0
#define PcZoneClient__RemovePetEffect_x                            0x62F2D0
#define PcZoneClient__HasAlternateAbility_x                        0x629030
#define PcZoneClient__GetCurrentMod_x                              0x4E1890
#define PcZoneClient__GetModCap_x                                  0x4E1790
#define PcZoneClient__CanEquipItem_x                               0x6296E0
#define PcZoneClient__GetItemByID_x                                0x62C2B0
#define PcZoneClient__GetItemByItemClass_x                         0x62C400
#define PcZoneClient__RemoveBuffEffect_x                           0x62F2F0
#define PcZoneClient__BandolierSwap_x                              0x62A310

//Doors
#define EQSwitch__UseSwitch_x                                      0x5C0EB0

//IconCache
#define IconCache__GetIcon_x                                       0x700A50

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6F8500
#define CContainerMgr__CloseContainer_x                            0x6F87D0
#define CContainerMgr__OpenExperimentContainer_x                   0x6F9250

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7BAE20

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5FCB40

//CLootWnd
#define CLootWnd__LootAll_x                                        0x756050
#define CLootWnd__RequestLootSlot_x                                0x755410

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x55C330
#define EQ_Spell__SpellAffects_x                                   0x55C7A0
#define EQ_Spell__SpellAffectBase_x                                0x55C560
#define EQ_Spell__IsStackable_x                                    0x4C6470
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C6320
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B3A30
#define EQ_Spell__IsSPAStacking_x                                  0x55D5D0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x55CAF0
#define EQ_Spell__IsNoRemove_x                                     0x4C6450
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x55D5E0
#define __IsResEffectSpell_x                                       0x4C57D0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AA360

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8B8870

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x800890
#define CTargetWnd__WndNotification_x                              0x800120
#define CTargetWnd__RefreshTargetBuffs_x                           0x8003F0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x7FF270

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x804F70

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5578D0
#define EqSoundManager__PlayScriptMp3_x                            0x557A30
#define EqSoundManager__SoundAssistPlay_x                          0x6667E0
#define EqSoundManager__WaveInstancePlay_x                         0x665D50

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x5149E0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x92A7B0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x54BB20
#define CAltAbilityData__GetMercMaxRank_x                          0x54BAC0
#define CAltAbilityData__GetMaxRank_x                              0x541040

//CTargetRing
#define CTargetRing__Cast_x                                        0x5FAC50

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C6300
#define CharacterBase__CreateItemGlobalIndex_x                     0x4FA860
#define CharacterBase__CreateItemIndex_x                           0x602D20
#define CharacterBase__GetItemPossession_x                         0x4B38E0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8C0EF0
#define CharacterBase__GetEffectId_x                               0x4C62B0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6E06A0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6E0EC0

//messages
#define msg_spell_worn_off_x                                       0x5811A0
#define msg_new_text_x                                             0x576080
#define __msgTokenTextParam_x                                      0x5837F0
#define msgTokenText_x                                             0x583A40

//SpellManager
#define SpellManager__vftable_x                                    0xAAC8A0
#define SpellManager__SpellManager_x                               0x669B00
#define Spellmanager__LoadTextSpells_x                             0x66A3D0
#define SpellManager__GetSpellByGroupAndRank_x                     0x669CD0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9759C0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4FAF40
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x587670
#define ItemGlobalIndex__IsEquippedLocation_x                      0x589160
#define ItemGlobalIndex__IsValidIndex_x                            0x4FAFA0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8B91B0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8B9430

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x74EA70

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6FCC70
#define CCursorAttachment__Deactivate_x                            0x6FDC50

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x93CD40
#define CEQSuiteTextureLoader__GetTexture_x                        0x93CA00

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4F7F10

//IString
#define IString__Append_x                                          0x4EAF40

//Camera
#define CDisplay__cameraType_x                                     0xDB1CC8
#define EverQuest__Cameras_x                                       0xE74F10

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x500710
#define LootFiltersManager__GetItemFilterData_x                    0x500000
#define LootFiltersManager__RemoveItemLootFilter_x                 0x500030
#define LootFiltersManager__SetItemLootFilter_x                    0x500250

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7A8E10

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x97B770
#define CResolutionHandler__GetWindowedStyle_x                     0x661580

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6F5210

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8CB9C0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x715470
#define CGroupWnd__UpdateDisplay_x                                 0x7147D0

//ItemBase
#define ItemBase__IsLore_x                                         0x88EF10
#define ItemBase__IsLoreEquipped_x                                 0x88EF80

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
