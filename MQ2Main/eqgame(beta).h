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
#define __ExpectedVersionDate                                     "Nov 10 2018"
#define __ExpectedVersionTime                                     "04:21:01"
#define __ActualVersionDate_x                                      0xAC8B3C
#define __ActualVersionTime_x                                      0xAC8B30

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x60F510
#define __MemChecker1_x                                            0x8E3AD0
#define __MemChecker2_x                                            0x69E3E0
#define __MemChecker3_x                                            0x69E330
#define __MemChecker4_x                                            0x83B180
#define __EncryptPad0_x                                            0xBFB998
#define __EncryptPad1_x                                            0xC59C28
#define __EncryptPad2_x                                            0xC0C520
#define __EncryptPad3_x                                            0xC0C120
#define __EncryptPad4_x                                            0xC4A498
#define __EncryptPad5_x                                            0xF15B2C
#define __AC1_x                                                    0x7F7716
#define __AC2_x                                                    0x5CA36F
#define __AC3_x                                                    0x5D11FF
#define __AC4_x                                                    0x5D5070
#define __AC5_x                                                    0x5DB22F
#define __AC6_x                                                    0x5DF766
#define __AC7_x                                                    0x5C9DE0
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
#define __do_loot_x                                                0x597C30
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
#define __gfMaxZoomCameraDistance_x                                0xABDF70
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
#define __CastRay_x                                                0x593150
#define __CastRay2_x                                               0x5931A0
#define __ConvertItemTags_x                                        0x5ADD50
#define __CrashHandler_x                                           0x844B00
#define __EQGetTime_x                                              0x8E35C0
#define __ExecuteCmd_x                                             0x58BB20
#define __FixHeading_x                                             0x973F40
#define __get_bearing_x                                            0x592CA0
#define __get_melee_range_x                                        0x593390
#define __GetAnimationCache_x                                      0x702050
#define __GetGaugeValueFromEQ_x                                    0x7F5F30
#define __GetLabelFromEQ_x                                         0x7F76A0
#define __GetXTargetType_x                                         0x9759A0
#define __HeadingDiff_x                                            0x973FB0
#define __HelpPath_x                                               0xF12C64
#define __LoadFrontEnd_x                                           0x69A240
#define __NewUIINI_x                                               0x7F5C00
#define __pCrashHandler_x                                          0x1048AE8
#define __ProcessGameEvents_x                                      0x5F0990
#define __ProcessMouseEvent_x                                      0x5F0150
#define __SaveColors_x                                             0x53B8F0
#define __STMLToText_x                                             0x917370
#define __ToggleKeyRingItem_x                                      0x4FE7F0
#define CrashDetected_x                                            0x69BD30
#define DrawNetStatus_x                                            0x61CA90
#define Expansion_HoT_x                                            0xE74BD4
#define Teleport_Table_Size_x                                      0xE63D2C
#define Teleport_Table_x                                           0xE64418
#define Util__FastTime_x                                           0x8E3180
#define wwsCrashReportCheckForUploader_x                           0x8454C0
#define wwsCrashReportPlatformLaunchUploader_x                     0x847B80
#define __HandleMouseWheel_x                                       0x69E490

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48AF00
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x493D60
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x493B20

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x5432A0
#define AltAdvManager__IsAbilityReady_x                            0x542320
#define AltAdvManager__GetAAById_x                                 0x542520
#define AltAdvManager__CanTrainAbility_x                           0x542590
#define AltAdvManager__CanSeeAbility_x                             0x5427C0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C69E0
#define CharacterZoneClient__HasSkill_x                            0x4D16A0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D2DC0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BAE10
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B7590
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D5770
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D5850
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D5930
#define CharacterZoneClient__FindAffectSlot_x                      0x4BF8F0
#define CharacterZoneClient__BardCastBard_x                        0x4C2560
#define CharacterZoneClient__GetMaxEffects_x                       0x4B7660
#define CharacterZoneClient__GetEffect_x                           0x4B74D0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C08F0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C09C0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C0A10
#define CharacterZoneClient__CalcAffectChange_x                    0x4C0B60
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C0D30

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6C4550

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6D1FA0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5FF2D0
#define CButtonWnd__CButtonWnd_x                                   0x913760

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6F0A60
#define CChatManager__InitContextMenu_x                            0x6EAB00
#define CChatManager__FreeChatWindow_x                             0x6EF970
#define CChatManager__GetLockedActiveChatWindow_x                  0x6F4320
#define CChatManager__SetLockedActiveChatWindow_x                  0x6F0800

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x927FD0
#define CContextMenu__dCContextMenu_x                              0x928200
#define CContextMenu__AddMenuItem_x                                0x928210
#define CContextMenu__RemoveMenuItem_x                             0x928520
#define CContextMenu__RemoveAllMenuItems_x                         0x928540
#define CContextMenu__CheckMenuItem_x                              0x9285C0
#define CContextMenu__SetMenuItem_x                                0x928440
#define CContextMenu__AddSeparator_x                               0x9283A0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x928B60
#define CContextMenuManager__RemoveMenu_x                          0x928BD0
#define CContextMenuManager__PopupMenu_x                           0x928C90
#define CContextMenuManager__Flush_x                               0x928B00
#define CContextMenuManager__GetMenu_x                             0x495E80

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8C3D60
#define CChatService__GetFriendName_x                              0x8C3D70

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6F0FD0
#define CChatWindow__Clear_x                                       0x6F2030
#define CChatWindow__WndNotification_x                             0x6F25A0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x925450
#define CComboWnd__Draw_x                                          0x924940
#define CComboWnd__GetCurChoice_x                                  0x925290
#define CComboWnd__GetListRect_x                                   0x924DF0
#define CComboWnd__GetTextRect_x                                   0x9254C0
#define CComboWnd__InsertChoice_x                                  0x924F80
#define CComboWnd__SetColors_x                                     0x924F50
#define CComboWnd__SetChoice_x                                     0x925260
#define CComboWnd__GetItemCount_x                                  0x9252A0
#define CComboWnd__GetCurChoiceText_x                              0x9252E0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6FA220
#define CContainerWnd__vftable_x                                   0xAD1F40
#define CContainerWnd__SetContainer_x                              0x6FB790

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x53B6B0
#define CDisplay__GetClickedActor_x                                0x52E6C0
#define CDisplay__GetUserDefinedColor_x                            0x526DA0
#define CDisplay__GetWorldFilePath_x                               0x530110
#define CDisplay__is3dON_x                                         0x52B390
#define CDisplay__ReloadUI_x                                       0x535830
#define CDisplay__WriteTextHD2_x                                   0x52B170
#define CDisplay__TrueDistance_x                                   0x531D70
#define CDisplay__SetViewActor_x                                   0x52E010
#define CDisplay__GetFloorHeight_x                                 0x52B450
#define CDisplay__SetRenderWindow_x                                0x529D80
#define CDisplay__ToggleScreenshotMode_x                           0x52DAE0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x9476F0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x92C6D0
#define CEditWnd__GetCharIndexPt_x                                 0x92D5D0
#define CEditWnd__GetDisplayString_x                               0x92D470
#define CEditWnd__GetHorzOffset_x                                  0x92BD00
#define CEditWnd__GetLineForPrintableChar_x                        0x92E710
#define CEditWnd__GetSelStartPt_x                                  0x92D880
#define CEditWnd__GetSTMLSafeText_x                                0x92D290
#define CEditWnd__PointFromPrintableChar_x                         0x92E340
#define CEditWnd__SelectableCharFromPoint_x                        0x92E4B0
#define CEditWnd__SetEditable_x                                    0x92D950

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5DEC90
#define CEverQuest__ClickedPlayer_x                                0x5D0FE0
#define CEverQuest__CreateTargetIndicator_x                        0x5EDC40
#define CEverQuest__DeleteTargetIndicator_x                        0x5EDCD0
#define CEverQuest__DoTellWindow_x                                 0x4E2A50
#define CEverQuest__OutputTextToLog_x                              0x4E2C80
#define CEverQuest__DropHeldItemOnGround_x                         0x5C68A0
#define CEverQuest__dsp_chat_x                                     0x4E3010
#define CEverQuest__trimName_x                                     0x5EA1B0
#define CEverQuest__Emote_x                                        0x5DF4A0
#define CEverQuest__EnterZone_x                                    0x5D9680
#define CEverQuest__GetBodyTypeDesc_x                              0x5E3A50
#define CEverQuest__GetClassDesc_x                                 0x5E4090
#define CEverQuest__GetClassThreeLetterCode_x                      0x5E4690
#define CEverQuest__GetDeityDesc_x                                 0x5EC590
#define CEverQuest__GetLangDesc_x                                  0x5E4850
#define CEverQuest__GetRaceDesc_x                                  0x5E4070
#define CEverQuest__InterpretCmd_x                                 0x5ECB60
#define CEverQuest__LeftClickedOnPlayer_x                          0x5CAA90
#define CEverQuest__LMouseUp_x                                     0x5C8E10
#define CEverQuest__RightClickedOnPlayer_x                         0x5CB370
#define CEverQuest__RMouseUp_x                                     0x5C9DA0
#define CEverQuest__SetGameState_x                                 0x5C6630
#define CEverQuest__UPCNotificationFlush_x                         0x5EA0B0
#define CEverQuest__IssuePetCommand_x                              0x5E5C50
#define CEverQuest__ReportSuccessfulHit_x                          0x5E08A0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x70C1C0
#define CGaugeWnd__CalcLinesFillRect_x                             0x70C220
#define CGaugeWnd__Draw_x                                          0x70B8C0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AC520
#define CGuild__GetGuildName_x                                     0x4AB600
#define CGuild__GetGuildIndex_x                                    0x4AB990

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x727550

//CHotButton
#define CHotButton__SetButtonSize_x                                0x5FF690

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x734510
#define CInvSlotMgr__MoveItem_x                                    0x733220
#define CInvSlotMgr__SelectSlot_x                                  0x7345E0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x731AC0
#define CInvSlot__SliderComplete_x                                 0x72F820
#define CInvSlot__GetItemBase_x                                    0x72F1A0
#define CInvSlot__UpdateItem_x                                     0x72F310

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x735F10
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7351E0
#define CInvSlotWnd__HandleLButtonUp_x                             0x735A90

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7F2120
#define CItemDisplayWnd__UpdateStrings_x                           0x743F40
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x73DF90
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x73E4C0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x744520
#define CItemDisplayWnd__AboutToShow_x                             0x743B90
#define CItemDisplayWnd__WndNotification_x                         0x745A70

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x829A80

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x749B80

// CLabel 
#define CLabel__Draw_x                                             0x74F5F0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8FDBC0
#define CListWnd__dCListWnd_x                                      0x8FDEE0
#define CListWnd__AddColumn_x                                      0x902220
#define CListWnd__AddColumn1_x                                     0x902270
#define CListWnd__AddLine_x                                        0x902600
#define CListWnd__AddString_x                                      0x902400
#define CListWnd__CalculateFirstVisibleLine_x                      0x901FE0
#define CListWnd__CalculateVSBRange_x                              0x901DB0
#define CListWnd__ClearSel_x                                       0x902DE0
#define CListWnd__ClearAllSel_x                                    0x902E40
#define CListWnd__CloseAndUpdateEditWindow_x                       0x903850
#define CListWnd__Compare_x                                        0x9016F0
#define CListWnd__Draw_x                                           0x8FDFE0
#define CListWnd__DrawColumnSeparators_x                           0x9007C0
#define CListWnd__DrawHeader_x                                     0x900C30
#define CListWnd__DrawItem_x                                       0x901030
#define CListWnd__DrawLine_x                                       0x900930
#define CListWnd__DrawSeparator_x                                  0x900860
#define CListWnd__EnableLine_x                                     0x900090
#define CListWnd__EnsureVisible_x                                  0x903770
#define CListWnd__ExtendSel_x                                      0x902D10
#define CListWnd__GetColumnMinWidth_x                              0x8FFBD0
#define CListWnd__GetColumnWidth_x                                 0x8FFB40
#define CListWnd__GetCurSel_x                                      0x8FF4D0
#define CListWnd__GetItemAtPoint_x                                 0x900310
#define CListWnd__GetItemAtPoint1_x                                0x900380
#define CListWnd__GetItemData_x                                    0x8FF550
#define CListWnd__GetItemHeight_x                                  0x8FF910
#define CListWnd__GetItemIcon_x                                    0x8FF6E0
#define CListWnd__GetItemRect_x                                    0x900180
#define CListWnd__GetItemText_x                                    0x8FF590
#define CListWnd__GetSelList_x                                     0x902E90
#define CListWnd__GetSeparatorRect_x                               0x9005C0
#define CListWnd__InsertLine_x                                     0x9029F0
#define CListWnd__RemoveLine_x                                     0x902B40
#define CListWnd__SetColors_x                                      0x901D80
#define CListWnd__SetColumnJustification_x                         0x901AB0
#define CListWnd__SetColumnWidth_x                                 0x9019D0
#define CListWnd__SetCurSel_x                                      0x902C50
#define CListWnd__SetItemColor_x                                   0x903420
#define CListWnd__SetItemData_x                                    0x9033E0
#define CListWnd__SetItemText_x                                    0x903010
#define CListWnd__ShiftColumnSeparator_x                           0x901B70
#define CListWnd__Sort_x                                           0x901870
#define CListWnd__ToggleSel_x                                      0x902C80

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x764A00
#define CMapViewWnd__GetWorldCoordinates_x                         0x763110
#define CMapViewWnd__HandleLButtonDown_x                           0x760170

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x787C50
// CMerchantWnd__RequestBuyItem_x                             
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x788530
// CMerchantWnd__RequestSellItem_x
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x788A60
#define CMerchantWnd__SelectRecoverySlot_x                         0x78B8A0
//CMerchantWnd__SelectBuySellSlot_x before
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x786630
//CMerchantWnd__ActualSelect_x
#define CMerchantWnd__SelectBuySellSlot_x                          0x791490
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x787880

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x891B80
#define CPacketScrambler__hton_x                                   0x891B70

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x91C960
#define CSidlManager__FindScreenPieceTemplate_x                    0x91CD70
#define CSidlManager__FindScreenPieceTemplate1_x                   0x91CB60
#define CSidlManager__CreateLabel_x                                0x7E9560
#define CSidlManager__CreateXWndFromTemplate_x                     0x91FE40
#define CSidlManager__CreateXWndFromTemplate1_x                    0x920020
#define CSidlManager__CreateXWnd_x                                 0x7E9490
#define CSidlManager__CreateHotButtonWnd_x                         0x7E9A50

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9194D0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9193D0
#define CSidlScreenWnd__ConvertToRes_x                             0x93E520
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x918E60
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x918B50
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x918C20
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x918CF0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x919970
#define CSidlScreenWnd__EnableIniStorage_x                         0x919E40
#define CSidlScreenWnd__GetSidlPiece_x                             0x919B60
#define CSidlScreenWnd__Init1_x                                    0x918760
#define CSidlScreenWnd__LoadIniInfo_x                              0x919E90
#define CSidlScreenWnd__LoadIniListWnd_x                           0x91A9D0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x917B60
#define CSidlScreenWnd__StoreIniInfo_x                             0x91A550
#define CSidlScreenWnd__StoreIniVis_x                              0x91A8B0
#define CSidlScreenWnd__WndNotification_x                          0x919880
#define CSidlScreenWnd__GetChildItem_x                             0x919DC0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9096B0
#define CSidlScreenWnd__m_layoutCopy_x                             0x16A3A58

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x663760
#define CSkillMgr__GetSkillCap_x                                   0x663940
#define CSkillMgr__GetNameToken_x                                  0x662EF0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x929950
#define CSliderWnd__SetValue_x                                     0x9297C0
#define CSliderWnd__SetNumTicks_x                                  0x929820

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7EF390

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x9305C0
#define CStmlWnd__CalculateHSBRange_x                              0x931650
#define CStmlWnd__CalculateVSBRange_x                              0x9315C0
#define CStmlWnd__CanBreakAtCharacter_x                            0x935990
#define CStmlWnd__FastForwardToEndOfTag_x                          0x936580
#define CStmlWnd__ForceParseNow_x                                  0x930B60
#define CStmlWnd__GetNextTagPiece_x                                0x9358F0
#define CStmlWnd__GetSTMLText_x                                    0x4F0E10
#define CStmlWnd__GetVisibleText_x                                 0x930B80
#define CStmlWnd__InitializeWindowVariables_x                      0x9363D0
#define CStmlWnd__MakeStmlColorTag_x                               0x92FD50
#define CStmlWnd__MakeWndNotificationTag_x                         0x92FDC0
#define CStmlWnd__SetSTMLText_x                                    0x92EE20
#define CStmlWnd__StripFirstSTMLLines_x                            0x9376E0
#define CStmlWnd__UpdateHistoryString_x                            0x936790

// CTabWnd 
#define CTabWnd__Draw_x                                            0x93B410
#define CTabWnd__DrawCurrentPage_x                                 0x93BA30
#define CTabWnd__DrawTab_x                                         0x93B800
#define CTabWnd__GetCurrentPage_x                                  0x93AC70
#define CTabWnd__GetPageInnerRect_x                                0x93AEB0
#define CTabWnd__GetTabInnerRect_x                                 0x93ADF0
#define CTabWnd__GetTabRect_x                                      0x93ACA0
#define CTabWnd__InsertPage_x                                      0x93B0A0
#define CTabWnd__SetPage_x                                         0x93AF30
#define CTabWnd__SetPageRect_x                                     0x93B350
#define CTabWnd__UpdatePage_x                                      0x93B6C0
#define CTabWnd__GetPageFromTabIndex_x                             0x93B740
#define CTabWnd__GetCurrentTabIndex_x                              0x93AC60

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x749FE0
#define CPageWnd__SetTabText_x                                     0x947B00

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A60F0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x9064F0
#define CTextureFont__GetTextExtent_x                              0x9066B0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x697090
#define CHtmlComponentWnd__ValidateUri_x                           0x728F40
#define CHtmlWnd__SetClientCallbacks_x                             0x604640
#define CHtmlWnd__AddObserver_x                                    0x604660
#define CHtmlWnd__RemoveObserver_x                                 0x6046C0
#define Window__getProgress_x                                      0x842760
#define Window__getStatus_x                                        0x842780
#define Window__getURI_x                                           0x842790

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x944080

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8F3470

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4AD7C0
#define CXStr__CXStr1_x                                            0x4EBDB0
#define CXStr__CXStr3_x                                            0x8DF6B0
#define CXStr__dCXStr_x                                            0x472890
#define CXStr__operator_equal_x                                    0x8DF8E0
#define CXStr__operator_equal1_x                                   0x8DF920
#define CXStr__operator_plus_equal1_x                              0x8E03B0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x927BE0
#define CXWnd__BringToTop_x                                        0x90CDF0
#define CXWnd__Center_x                                            0x90C970
#define CXWnd__ClrFocus_x                                          0x90C7B0
#define CXWnd__Destroy_x                                           0x90C860
#define CXWnd__DoAllDrawing_x                                      0x908E40
#define CXWnd__DrawChildren_x                                      0x908E10
#define CXWnd__DrawColoredRect_x                                   0x9092A0
#define CXWnd__DrawTooltip_x                                       0x907960
#define CXWnd__DrawTooltipAtPoint_x                                0x907A20
#define CXWnd__GetBorderFrame_x                                    0x909100
#define CXWnd__GetChildWndAt_x                                     0x90CE90
#define CXWnd__GetClientClipRect_x                                 0x90B0D0
#define CXWnd__GetScreenClipRect_x                                 0x90B1A0
#define CXWnd__GetScreenRect_x                                     0x90B330
#define CXWnd__GetTooltipRect_x                                    0x9092F0
#define CXWnd__GetWindowTextA_x                                    0x4975F0
#define CXWnd__IsActive_x                                          0x90FD00
#define CXWnd__IsDescendantOf_x                                    0x90BD30
#define CXWnd__IsReallyVisible_x                                   0x90BD60
#define CXWnd__IsType_x                                            0x90D4F0
#define CXWnd__Move_x                                              0x90BDD0
#define CXWnd__Move1_x                                             0x90BE80
#define CXWnd__ProcessTransition_x                                 0x90C920
#define CXWnd__Refade_x                                            0x90C150
#define CXWnd__Resize_x                                            0x90C3D0
#define CXWnd__Right_x                                             0x90CBB0
#define CXWnd__SetFocus_x                                          0x90C770
#define CXWnd__SetFont_x                                           0x90C7E0
#define CXWnd__SetKeyTooltip_x                                     0x90D320
#define CXWnd__SetMouseOver_x                                      0x90A240
#define CXWnd__StartFade_x                                         0x90BC00
#define CXWnd__GetChildItem_x                                      0x90D000
#define CXWnd__SetParent_x                                         0x90BAD0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x93F5F0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x90FD40
#define CXWndManager__DrawWindows_x                                0x90FD60
#define CXWndManager__GetKeyboardFlags_x                           0x912420
#define CXWndManager__HandleKeyboardMsg_x                          0x912020
#define CXWndManager__RemoveWnd_x                                  0x912670
#define CXWndManager__RemovePendingDeletionWnd_x                   0x912BD0

// CDBStr
#define CDBStr__GetString_x                                        0x525D70

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B8540
#define EQ_Character__Cur_HP_x                                     0x4CE720
#define EQ_Character__Cur_Mana_x                                   0x4D5E30
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BB450
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AF3F0
#define EQ_Character__GetFocusRangeModifier_x                      0x4AF540
#define EQ_Character__GetHPRegen_x                                 0x4DBD90
#define EQ_Character__GetEnduranceRegen_x                          0x4DC3A0
#define EQ_Character__GetManaRegen_x                               0x4DC7E0
#define EQ_Character__Max_Endurance_x                              0x62A550
#define EQ_Character__Max_HP_x                                     0x4CE550
#define EQ_Character__Max_Mana_x                                   0x62A350
#define EQ_Character__doCombatAbility_x                            0x62CA20
#define EQ_Character__UseSkill_x                                   0x4DE5F0
#define EQ_Character__GetConLevel_x                                0x623820
#define EQ_Character__IsExpansionFlag_x                            0x58A1A0
#define EQ_Character__TotalEffect_x                                0x4C1AE0
#define EQ_Character__GetPCSpellAffect_x                           0x4BC040
#define EQ_Character__SpellDuration_x                              0x4BBB70
#define EQ_Character__FindItemByRecord_x                           0x4D3D30
#define EQ_Character__GetAdjustedSkill_x                           0x4D1460
#define EQ_Character__GetBaseSkill_x                               0x4D2400
#define EQ_Character__CanUseItem_x                                 0x4D6140

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8B0CF0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x640800

//PcClient
#define PcClient__PcClient_x                                       0x6210F0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6320
#define CCharacterListWnd__EnterWorld_x                            0x4B5D60
#define CCharacterListWnd__Quit_x                                  0x4B5A70
#define CCharacterListWnd__UpdateList_x                            0x4B5EF0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x605870
#define EQ_Item__CreateItemTagString_x                             0x88B530
#define EQ_Item__IsStackable_x                                     0x88FF40
#define EQ_Item__GetImageNum_x                                     0x88CF70
#define EQ_Item__CreateItemClient_x                                0x604A20
#define EQ_Item__GetItemValue_x                                    0x88E1E0
#define EQ_Item__ValueSellMerchant_x                               0x891720
#define EQ_Item__IsKeyRingItem_x                                   0x88F8A0
#define EQ_Item__CanGoInBag_x                                      0x605990
#define EQ_Item__GetMaxItemCount_x                                 0x88E5A0
#define EQ_Item__GetHeldItem_x                                     0x88CE40
#define EQ_Item__GetAugmentFitBySlot_x                             0x88AE90

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x543FC0
#define EQ_LoadingS__Array_x                                       0xBE37A0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x62AEB0
#define EQ_PC__GetAlternateAbilityId_x                             0x89A930
#define EQ_PC__GetCombatAbility_x                                  0x89AFA0
#define EQ_PC__GetCombatAbilityTimer_x                             0x89B010
#define EQ_PC__GetItemRecastTimer_x                                0x62CFA0
#define EQ_PC__HasLoreItem_x                                       0x623FF0
#define EQ_PC__AlertInventoryChanged_x                             0x6232F0
#define EQ_PC__GetPcZoneClient_x                                   0x64F040
#define EQ_PC__RemoveMyAffect_x                                    0x630190
#define EQ_PC__GetKeyRingItems_x                                   0x89B8B0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x89B630
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x89BBA0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x590700
#define EQItemList__add_object_x                                   0x5BC030
#define EQItemList__add_item_x                                     0x590D10
#define EQItemList__delete_item_x                                  0x590D60
#define EQItemList__FreeItemList_x                                 0x590C60

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x523350

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x642080
#define EQPlayer__dEQPlayer_x                                      0x6357A0
#define EQPlayer__DoAttack_x                                       0x649D20
#define EQPlayer__EQPlayer_x                                       0x635E50
#define EQPlayer__SetNameSpriteState_x                             0x63A0C0
#define EQPlayer__SetNameSpriteTint_x                              0x63AF80
#define PlayerBase__HasProperty_j_x                                0x9722D0
#define EQPlayer__IsTargetable_x                                   0x972770
#define EQPlayer__CanSee_x                                         0x9725D0
#define EQPlayer__CanSee1_x                                        0x9726A0
#define PlayerBase__GetVisibilityLineSegment_x                     0x972390

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x64CAF0
#define PlayerZoneClient__GetLevel_x                               0x64F080
#define PlayerZoneClient__IsValidTeleport_x                        0x5BD190
#define PlayerZoneClient__LegalPlayerRace_x                        0x53D450

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x644E00
#define EQPlayerManager__GetSpawnByName_x                          0x644E20
#define EQPlayerManager__GetPlayerFromPartialName_x                0x644EB0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x609130
#define KeypressHandler__AttachKeyToEqCommand_x                    0x609170
#define KeypressHandler__ClearCommandStateArray_x                  0x60A560
#define KeypressHandler__HandleKeyDown_x                           0x60A580
#define KeypressHandler__HandleKeyUp_x                             0x60A620
#define KeypressHandler__SaveKeymapping_x                          0x60AA00

// MapViewMap 
#define MapViewMap__Clear_x                                        0x760890
#define MapViewMap__SaveEx_x                                       0x763C30
#define MapViewMap__SetZoom_x                                      0x768300

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8AEBF0

// StringTable 
#define StringTable__getString_x                                   0x8A9B80

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x62FE00
#define PcZoneClient__RemovePetEffect_x                            0x630430
#define PcZoneClient__HasAlternateAbility_x                        0x62A190
#define PcZoneClient__GetCurrentMod_x                              0x4E16E0
#define PcZoneClient__GetModCap_x                                  0x4E15E0
#define PcZoneClient__CanEquipItem_x                               0x62A840
#define PcZoneClient__GetItemByID_x                                0x62D410
#define PcZoneClient__GetItemByItemClass_x                         0x62D560
#define PcZoneClient__RemoveBuffEffect_x                           0x630450
#define PcZoneClient__BandolierSwap_x                              0x62B470

//Doors
#define EQSwitch__UseSwitch_x                                      0x5C1D10

//IconCache
#define IconCache__GetIcon_x                                       0x7018E0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6F93C0
#define CContainerMgr__CloseContainer_x                            0x6F9690
#define CContainerMgr__OpenExperimentContainer_x                   0x6FA110

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7BBAC0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5FDAB0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x756D60
#define CLootWnd__RequestLootSlot_x                                0x756110

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x55C540
#define EQ_Spell__SpellAffects_x                                   0x55C9B0
#define EQ_Spell__SpellAffectBase_x                                0x55C770
#define EQ_Spell__IsStackable_x                                    0x4C6300
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C6180
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B3900
#define EQ_Spell__IsSPAStacking_x                                  0x55D7E0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x55CD00
#define EQ_Spell__IsNoRemove_x                                     0x4C62E0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x55D7F0
#define __IsResEffectSpell_x                                       0x4C5640

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AA230

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8B91E0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x8014C0
#define CTargetWnd__WndNotification_x                              0x800D50
#define CTargetWnd__RefreshTargetBuffs_x                           0x801020
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x7FFEA0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x805B80

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x557AC0
#define EqSoundManager__PlayScriptMp3_x                            0x557C20
#define EqSoundManager__SoundAssistPlay_x                          0x6675D0
#define EqSoundManager__WaveInstancePlay_x                         0x666B40

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x514D00

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x92B330

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x54BC10
#define CAltAbilityData__GetMercMaxRank_x                          0x54BBB0
#define CAltAbilityData__GetMaxRank_x                              0x5411D0

//CTargetRing
#define CTargetRing__Cast_x                                        0x5FBBC0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C6160
#define CharacterBase__CreateItemGlobalIndex_x                     0x4FACA0
#define CharacterBase__CreateItemIndex_x                           0x603C80
#define CharacterBase__GetItemPossession_x                         0x4B37B0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8C1880
#define CharacterBase__GetEffectId_x                               0x4C6110

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6E1490
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6E1CB0

//messages
#define msg_spell_worn_off_x                                       0x582120
#define msg_new_text_x                                             0x577000
#define __msgTokenTextParam_x                                      0x584770
#define msgTokenText_x                                             0x5849C0

//SpellManager
#define SpellManager__vftable_x                                    0xAAC8A8
#define SpellManager__SpellManager_x                               0x66A900
#define Spellmanager__LoadTextSpells_x                             0x66B1D0
#define SpellManager__GetSpellByGroupAndRank_x                     0x66AAD0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x976290

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4FB390
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5885D0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x58A180
#define ItemGlobalIndex__IsValidIndex_x                            0x4FB3F0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8B9B20
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8B9DA0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x74F930

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6FDB10
#define CCursorAttachment__Deactivate_x                            0x6FEAF0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x93D8F0
#define CEQSuiteTextureLoader__GetTexture_x                        0x93D5B0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4F8340

//IString
#define IString__Append_x                                          0x4EAEF0

//Camera
#define CDisplay__cameraType_x                                     0xDB1CC8
#define EverQuest__Cameras_x                                       0xE74F10

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x500A60
#define LootFiltersManager__GetItemFilterData_x                    0x500360
#define LootFiltersManager__RemoveItemLootFilter_x                 0x500390
#define LootFiltersManager__SetItemLootFilter_x                    0x5005B0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7A9AD0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x97C030
#define CResolutionHandler__GetWindowedStyle_x                     0x6622D0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6F6180

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8CC370

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x716310
#define CGroupWnd__UpdateDisplay_x                                 0x715670

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
