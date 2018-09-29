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
#define __ExpectedVersionDate                                     "Sep 25 2018"
#define __ExpectedVersionTime                                     "10:17:19"
#define __ActualVersionDate_x                                      0xAC16BC
#define __ActualVersionTime_x                                      0xAC16B0

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x609F30
#define __MemChecker1_x                                            0x8DCB20
#define __MemChecker2_x                                            0x698DE0
#define __MemChecker3_x                                            0x698D30
#define __MemChecker4_x                                            0x8350A0
#define __EncryptPad0_x                                            0xBF34C0
#define __EncryptPad1_x                                            0xC511A0
#define __EncryptPad2_x                                            0xC04048
#define __EncryptPad3_x                                            0xC03C48
#define __EncryptPad4_x                                            0xC41F38
#define __EncryptPad5_x                                            0x1019E3C
#define __AC1_x                                                    0x7F16C6
#define __AC2_x                                                    0x5C5B8F
#define __AC3_x                                                    0x5CCA1F
#define __AC4_x                                                    0x5D0890
#define __AC5_x                                                    0x5D6A4F
#define __AC6_x                                                    0x5DAF86
#define __AC7_x                                                    0x5C5600
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1EBAC48

// Direct Input
#define DI8__Main_x                                                0x1019E5C
#define DI8__Keyboard_x                                            0x1019E60
#define DI8__Mouse_x                                               0xF0ED98
#define DI8__Mouse_Copy_x                                          0xE6CA7C
#define DI8__Mouse_Check_x                                         0xF0FAC8
#define __AutoSkillArray_x                                         0xE6D994
#define __Attack_x                                                 0xF0B793
#define __Autofire_x                                               0xF0B794
#define __BindList_x                                               0xBE20C0
#define g_eqCommandStates_x                                        0xBE2E30
#define __Clicks_x                                                 0xE6CB34
#define __CommandList_x                                            0xBE39E8
#define __CurrentMapLabel_x                                        0x102133C
#define __CurrentSocial_x                                          0xBCD734
#define __DoAbilityList_x                                          0xEA32B4
#define __do_loot_x                                                0x593450
#define __DrawHandler_x                                            0x169C870
#define __GroupCount_x                                             0xE5CDAA
#define __Guilds_x                                                 0xE63288
#define __gWorld_x                                                 0xE5EFA4
#define __HWnd_x                                                   0xF0ED9C
#define __heqmain_x                                                0x1019E24
#define __InChatMode_x                                             0xE6CA64
#define __LastTell_x                                               0xE6E9B0
#define __LMouseHeldTime_x                                         0xE6CBA0
#define __Mouse_x                                                  0x1019E48
#define __MouseLook_x                                              0xE6CAFA
#define __MouseEventTime_x                                         0xF0C248
#define __gpbCommandEvent_x                                        0xE5F1BC
#define __NetStatusToggle_x                                        0xE6CAFD
#define __PCNames_x                                                0xE6DF70
#define __RangeAttackReady_x                                       0xE6DC78
#define __RMouseHeldTime_x                                         0xE6CB9C
#define __RunWalkState_x                                           0xE6CA68
#define __ScreenMode_x                                             0xDAB604
#define __ScreenX_x                                                0xE6CA1C
#define __ScreenY_x                                                0xE6CA18
#define __ScreenXMax_x                                             0xE6CA20
#define __ScreenYMax_x                                             0xE6CA24
#define __ServerHost_x                                             0xE5F30B
#define __ServerName_x                                             0xEA3274
#define __ShiftKeyDown_x                                           0xE6D0F4
#define __ShowNames_x                                              0xE6DE34
#define __Socials_x                                                0xEA3374
#define __SubscriptionType_x                                       0x1062E04
#define __TargetAggroHolder_x                                      0x1023CF4
#define __ZoneType_x                                               0xE6CEF8
#define __GroupAggro_x                                             0x1023D34
#define __LoginName_x                                              0xF0F45C
#define __Inviter_x                                                0xF0B710
#define __AttackOnAssist_x                                         0xE6DDF0
#define __UseTellWindows_x                                         0xE6E108
#define __gfMaxZoomCameraDistance_x                                0xAB6AC8
#define __gfMaxCameraDistance_x                                    0xAE4068
#define __pulAutoRun_x                                             0xE6CB18
#define __pulForward_x                                             0xE6E140
#define __pulBackward_x                                            0xE6E144
#define __pulTurnRight_x                                           0xE6E148
#define __pulTurnLeft_x                                            0xE6E14C
#define __pulStrafeLeft_x                                          0xE6E150
#define __pulStrafeRight_x                                         0xE6E154

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE5F630
#define instEQZoneInfo_x                                           0xE6CCF0
#define instKeypressHandler_x                                      0xF0C1F8
#define pinstActiveBanker_x                                        0xE5CD20
#define pinstActiveCorpse_x                                        0xE5F624
#define pinstActiveGMaster_x                                       0xE5F628
#define pinstActiveMerchant_x                                      0xE5F620
#define pinstAggroInfo_x                                           0xC679B8
#define pinstAltAdvManager_x                                       0xDABFD0
#define pinstAuraMgr_x                                             0xC786A0
#define pinstBandageTarget_x                                       0xE5CD30
#define pinstCamActor_x                                            0xDAB5F8
#define pinstCDBStr_x                                              0xDAAD0C
#define pinstCDisplay_x                                            0xE5CD74
#define pinstCEverQuest_x                                          0x1019F78
#define pinstEverQuestInfo_x                                       0xE6CA10
#define pinstCharData_x                                            0xE5CD7C
#define pinstCharSpawn_x                                           0xE5CD68
#define pinstControlledMissile_x                                   0xE5CD80
#define pinstControlledPlayer_x                                    0xE5CD68
#define pinstCResolutionHandler_x                                  0x169CAA0
#define pinstCSidlManager_x                                        0x169B934
#define pinstCXWndManager_x                                        0x169B928
#define instDynamicZone_x                                          0xE63160
#define pinstDZMember_x                                            0xE63270
#define pinstDZTimerInfo_x                                         0xE63274
#define pinstEQItemList_x                                          0xE5B820
#define pinstEQObjectList_x                                        0xE5CA10
#define instEQMisc_x                                               0xDAAC48
#define pinstEQSoundManager_x                                      0xDAC830
#define pinstEQSpellStrings_x                                      0xC75AF0
#define instExpeditionLeader_x                                     0xE631AA
#define instExpeditionName_x                                       0xE631EA
#define pinstGroup_x                                               0xE5CDA6
#define pinstImeManager_x                                          0x169B92C
#define pinstLocalPlayer_x                                         0xE5F61C
#define pinstMercenaryData_x                                       0xF0C9E8
#define pinstMercenaryStats_x                                      0x1023E40
#define pinstMercAltAbilities_x                                    0xDAC5A0
#define pinstModelPlayer_x                                         0xE5CD28
#define pinstPCData_x                                              0xE5CD7C
#define pinstRealEstateItems_x                                     0xF0DED8
#define pinstSkillMgr_x                                            0xF0DFA8
#define pinstSpawnManager_x                                        0xF0D598
#define pinstSpellManager_x                                        0xF0E180
#define pinstSpellSets_x                                           0xF043BC
#define pinstStringTable_x                                         0xE5F010
#define pinstSwitchManager_x                                       0xE5CBD0
#define pinstTarget_x                                              0xE5CD64
#define pinstTargetObject_x                                        0xE5CD70
#define pinstTargetSwitch_x                                        0xE5CD88
#define pinstTaskMember_x                                          0xDAAAD8
#define pinstTrackTarget_x                                         0xE5CD6C
#define pinstTradeTarget_x                                         0xE5CD24
#define instTributeActive_x                                        0xDAAC6D
#define pinstViewActor_x                                           0xDAB5F4
#define pinstWorldData_x                                           0xE5CD94
#define pinstZoneAddr_x                                            0xE6CF90
#define pinstPlayerPath_x                                          0xF0D630
#define pinstTargetIndicator_x                                     0xF0E3E8
#define pinstCTargetManager_x                                      0xF0E480
#define EQObject_Top_x                                             0xE5F414
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDAB584
#define pinstCAchievementsWnd_x                                    0xDAADB8
#define pinstCActionsWnd_x                                         0xDAB5E4
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDAB570
#define pinstCAdvancedLootWnd_x                                    0xDAB538
#define pinstCAdventureLeaderboardWnd_x                            0x101AB10
#define pinstCAdventureRequestWnd_x                                0x101ABC0
#define pinstCAdventureStatsWnd_x                                  0x101AC70
#define pinstCAggroMeterWnd_x                                      0xDAADF4
#define pinstCAlarmWnd_x                                           0xDAB634
#define pinstCAlertHistoryWnd_x                                    0xDAB624
#define pinstCAlertStackWnd_x                                      0xDAB598
#define pinstCAlertWnd_x                                           0xDAB5A8
#define pinstCAltStorageWnd_x                                      0x101AFD0
#define pinstCAudioTriggersWindow_x                                0xC67E48
#define pinstCAuraWnd_x                                            0xDAADE8
#define pinstCAvaZoneWnd_x                                         0xDAB5E0
#define pinstCBandolierWnd_x                                       0xDAB030
#define pinstCBankWnd_x                                            0xDAB530
#define pinstCBarterMerchantWnd_x                                  0x101C210
#define pinstCBarterSearchWnd_x                                    0x101C2C0
#define pinstCBarterWnd_x                                          0x101C370
#define pinstCBazaarConfirmationWnd_x                              0xDAB590
#define pinstCBazaarSearchWnd_x                                    0xDAB610
#define pinstCBazaarWnd_x                                          0xDAB02C
#define pinstCBlockedBuffWnd_x                                     0xDAB514
#define pinstCBlockedPetBuffWnd_x                                  0xDAB53C
#define pinstCBodyTintWnd_x                                        0xDAB5A4
#define pinstCBookWnd_x                                            0xDAB054
#define pinstCBreathWnd_x                                          0xDAB594
#define pinstCBuffWindowNORMAL_x                                   0xDAB4D8
#define pinstCBuffWindowSHORT_x                                    0xDAB4DC
#define pinstCBugReportWnd_x                                       0xDAB57C
#define pinstCButtonWnd_x                                          0x169BB20
#define pinstCCastingWnd_x                                         0xDAB578
#define pinstCCastSpellWnd_x                                       0xDAB62C
//#define pinstCCharacterCreationWnd_x                               0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDAB5A0
#define pinstCChatWindowManager_x                                  0x101CE30
#define pinstCClaimWnd_x                                           0x101CF88
#define pinstCColorPickerWnd_x                                     0xDAB5BC
#define pinstCCombatAbilityWnd_x                                   0xDAADFC
#define pinstCCombatSkillsSelectWnd_x                              0xDAB5DC
#define pinstCCompassWnd_x                                         0xDAB588
#define pinstCConfirmationDialog_x                                 0x1021E88
#define pinstCContainerMgr_x                                       0xDAB024
#define pinstCContextMenuManager_x                                 0x169B8E8
#define pinstCCursorAttachment_x                                   0xDAB56C
#define pinstCDistillerInfo_x                                      0x1020894
#define pinstCDynamicZoneWnd_x                                     0x101D550
#define pinstCEditLabelWnd_x                                       0xDAB4C4
#define pinstCEQMainWnd_x                                          0x101D798
#define pinstCEventCalendarWnd_x                                   0xDAAE04
#define pinstCExtendedTargetWnd_x                                  0xDAADE4
#define pinstCFacePick_x                                           0xDAB5C4
#define pinstCFellowshipWnd_x                                      0x101D998
#define pinstCFileSelectionWnd_x                                   0xDAB518
#define pinstCFindItemWnd_x                                        0xDAB01C
#define pinstCFindLocationWnd_x                                    0x101DAF0
#define pinstCFriendsWnd_x                                         0xDAB614
#define pinstCGemsGameWnd_x                                        0xDAB5E8
#define pinstCGiveWnd_x                                            0xDAB040
#define pinstCGroupSearchFiltersWnd_x                              0xDAAE10
#define pinstCGroupSearchWnd_x                                     0x101DEE8
#define pinstCGroupWnd_x                                           0x101DF98
#define pinstCGuildBankWnd_x                                       0xE6DDD4
#define pinstCGuildCreationWnd_x                                   0x101E0F8
#define pinstCGuildMgmtWnd_x                                       0x101E1A8
#define pinstCharacterCreation_x                                   0xDAADF8
#define pinstCHelpWnd_x                                            0xDAADAC
#define pinstCHeritageSelectionWnd_x                               0xDAB5CC
#define pinstCHotButtonWnd_x                                       0x1020300
#define pinstCHotButtonWnd1_x                                      0x1020300
#define pinstCHotButtonWnd2_x                                      0x1020304
#define pinstCHotButtonWnd3_x                                      0x1020308
#define pinstCHotButtonWnd4_x                                      0x102030C
#define pinstCIconSelectionWnd_x                                   0xDAB54C
#define pinstCInspectWnd_x                                         0xDAB544
#define pinstCInventoryWnd_x                                       0xDAB034
#define pinstCInvSlotMgr_x                                         0xDAADC0
#define pinstCItemDisplayManager_x                                 0x1020890
#define pinstCItemExpTransferWnd_x                                 0x10209C4
#define pinstCItemOverflowWnd_x                                    0xDAB618
#define pinstCJournalCatWnd_x                                      0xDAB540
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDAB4D4
#define pinstCKeyRingWnd_x                                         0xDAB508
#define pinstCLargeDialogWnd_x                                     0x1022B08
#define pinstCLayoutCopyWnd_x                                      0x1020D10
#define pinstCLFGuildWnd_x                                         0x1020DC0
#define pinstCLoadskinWnd_x                                        0xDAB61C
#define pinstCLootFiltersCopyWnd_x                                 0xC78E80
#define pinstCLootFiltersWnd_x                                     0xDAB5B8
#define pinstCLootSettingsWnd_x                                    0xDAB5C8
#define pinstCLootWnd_x                                            0xDAB5B0
#define pinstCMailAddressBookWnd_x                                 0xDAB550
#define pinstCMailCompositionWnd_x                                 0xDAB534
#define pinstCMailIgnoreListWnd_x                                  0xDAB554
#define pinstCMailWnd_x                                            0xDAB50C
#define pinstCManageLootWnd_x                                      0xDAC448
#define pinstCMapToolbarWnd_x                                      0xDAB038
#define pinstCMapViewWnd_x                                         0xDAB018
#define pinstCMarketplaceWnd_x                                     0xDAB020
#define pinstCMerchantWnd_x                                        0xDAB5D8
#define pinstCMIZoneSelectWnd_x                                    0x10215F8
#define pinstCMusicPlayerWnd_x                                     0xDAB500
#define pinstCNameChangeMercWnd_x                                  0xDAB548
#define pinstCNameChangePetWnd_x                                   0xDAB52C
#define pinstCNameChangeWnd_x                                      0xDAADF0
#define pinstCNoteWnd_x                                            0xDAADA8
#define pinstCObjectPreviewWnd_x                                   0xDAB0BC
#define pinstCOptionsWnd_x                                         0xDAB03C
#define pinstCPetInfoWnd_x                                         0xDAB524
#define pinstCPetitionQWnd_x                                       0xDAB558
//#define pinstCPlayerCustomizationWnd_x                             0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDAB59C
#define pinstCPlayerWnd_x                                          0xDAB620
#define pinstCPopupWndManager_x                                    0x1021E88
#define pinstCProgressionSelectionWnd_x                            0x1021F38
#define pinstCPurchaseGroupWnd_x                                   0xDAB504
#define pinstCPurchaseWnd_x                                        0xDAB4C8
#define pinstCPvPLeaderboardWnd_x                                  0x1021FE8
#define pinstCPvPStatsWnd_x                                        0x1022098
#define pinstCQuantityWnd_x                                        0xDAB560
#define pinstCRaceChangeWnd_x                                      0xDAB028
#define pinstCRaidOptionsWnd_x                                     0xDAAE14
#define pinstCRaidWnd_x                                            0xDAB564
#define pinstCRealEstateItemsWnd_x                                 0xDAADC4
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDAAE00
#define pinstCRealEstateManageWnd_x                                0xDAB5D0
#define pinstCRealEstateNeighborhoodWnd_x                          0xDAB5EC
#define pinstCRealEstatePlotSearchWnd_x                            0xDAB628
#define pinstCRealEstatePurchaseWnd_x                              0xDAADB0
#define pinstCRespawnWnd_x                                         0xDAAE0C
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDAADE0
#define pinstCSendMoneyWnd_x                                       0xDAB4CC
#define pinstCServerListWnd_x                                      0xDAADC8
#define pinstCSkillsSelectWnd_x                                    0xDAB5C0
#define pinstCSkillsWnd_x                                          0xDAB5AC
#define pinstCSocialEditWnd_x                                      0xDAB568
#define pinstCSocialWnd_x                                          0xDAB574
#define pinstCSpellBookWnd_x                                       0xDAADD0
#define pinstCStoryWnd_x                                           0xDAB580
#define pinstCTargetOfTargetWnd_x                                  0x1023EC8
#define pinstCTargetWnd_x                                          0xDAB520
#define pinstCTaskOverlayWnd_x                                     0xDAB630
#define pinstCTaskSelectWnd_x                                      0x1024020
#define pinstCTaskSomething_x                                      0xC79680
#define pinstCTaskTemplateSelectWnd_x                              0x10240D0
#define pinstCTaskWnd_x                                            0x1024180
#define pinstCTextEntryWnd_x                                       0xDAB58C
#define pinstCTextOverlay_x                                        0xC68158
#define pinstCTimeLeftWnd_x                                        0xDAB528
#define pinstCTipWndCONTEXT_x                                      0x1024384
#define pinstCTipWndOFDAY_x                                        0x1024380
#define pinstCTitleWnd_x                                           0x1024430
#define pinstCTrackingWnd_x                                        0xDAB51C
#define pinstCTradeskillWnd_x                                      0x1024598
#define pinstCTradeWnd_x                                           0xDAADB4
#define pinstCTrainWnd_x                                           0xDAB55C
#define pinstCTributeBenefitWnd_x                                  0x1024798
#define pinstCTributeMasterWnd_x                                   0x1024848
#define pinstCTributeTrophyWnd_x                                   0x10248F8
#define pinstCVideoModesWnd_x                                      0xDAADBC
#define pinstCVoiceMacroWnd_x                                      0xF0E9B0
#define pinstCVoteResultsWnd_x                                     0xDAB510
#define pinstCVoteWnd_x                                            0xDAB4D0
#define pinstCWebManager_x                                         0xF0EB14
#define pinstCZoneGuideWnd_x                                       0xDAB5D4
#define pinstCZonePathWnd_x                                        0xDAB5F0

#define pinstEQSuiteTextureLoader_x                                0xC52C58
#define pinstItemIconCache_x                                       0x101D750
#define pinstLootFiltersManager_x                                  0xC78F30
#define pinstRewardSelectionWnd_x                                  0x10227E0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC03C3C
#define __CastRay_x                                                0x58E970
#define __CastRay2_x                                               0x58E9C0
#define __ConvertItemTags_x                                        0x5A9550
#define __CrashHandler_x                                           0x83E9C0
#define __EQGetTime_x                                              0x8DC610
#define __ExecuteCmd_x                                             0x5872C0
#define __FixHeading_x                                             0x96D200
#define __get_bearing_x                                            0x58E4B0
#define __get_melee_range_x                                        0x58EBB0
#define __GetAnimationCache_x                                      0x6FC940
#define __GetGaugeValueFromEQ_x                                    0x7EFEE0
#define __GetLabelFromEQ_x                                         0x7F1650
#define __GetXTargetType_x                                         0x96ECD0
#define __HandleMouseWheel_x                                       0x698E90
#define __HeadingDiff_x                                            0x96D270
#define __HelpPath_x                                               0xF0BE64
#define __LoadFrontEnd_x                                           0x694C40
#define __NewUIINI_x                                               0x7EFBB0
#define __pCrashHandler_x                                          0x1041C60
#define __ProcessGameEvents_x                                      0x5EBA50
#define __ProcessMouseEvent_x                                      0x5EB210
#define __SaveColors_x                                             0x537F70
#define __STMLToText_x                                             0x910230
#define __ToggleKeyRingItem_x                                      0x4FB270
#define CrashDetected_x                                            0x696730
#define DrawNetStatus_x                                            0x617620
#define Expansion_HoT_x                                            0xE6DDDC
#define Teleport_Table_Size_x                                      0xE5F1C8
#define Teleport_Table_x                                           0xE5CFA0
#define Util__FastTime_x                                           0x8DC1D0
#define wwsCrashReportCheckForUploader_x                           0x83F380
#define wwsCrashReportPlatformLaunchUploader_x                     0x841A60

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48A7C0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4935B0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x493390

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x53F900
#define AltAdvManager__IsAbilityReady_x                            0x53E980
#define AltAdvManager__GetAAById_x                                 0x53EB80
#define AltAdvManager__CanTrainAbility_x                           0x53EBF0
#define AltAdvManager__CanSeeAbility_x                             0x53EE20

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C62D0
#define CharacterZoneClient__HasSkill_x                            0x4D0E70
#define CharacterZoneClient__MakeMeVisible_x                       0x4D2590
#define CharacterZoneClient__IsStackBlocked_x                      0x4BA5A0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B6C60
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D4CE0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D4DC0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D4EA0
#define CharacterZoneClient__FindAffectSlot_x                      0x4BF1D0
#define CharacterZoneClient__BardCastBard_x                        0x4C1E40
#define CharacterZoneClient__GetMaxEffects_x                       0x4B6D30
#define CharacterZoneClient__GetEffect_x                           0x4B6BA0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C01E0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C02B0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C0300
#define CharacterZoneClient__CalcAffectChange_x                    0x4C0450
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C0620

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6BEEE0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6CCA60

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5F9D80
#define CButtonWnd__CButtonWnd_x                                   0x90C620

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6EB2C0
#define CChatManager__InitContextMenu_x                            0x6E53D0
#define CChatManager__FreeChatWindow_x                             0x6EA1E0
#define CChatManager__GetLockedActiveChatWindow_x                  0x6EEB80
#define CChatManager__SetLockedActiveChatWindow_x                  0x6EB060

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x920E50
#define CContextMenu__dCContextMenu_x                              0x921080
#define CContextMenu__AddMenuItem_x                                0x921090
#define CContextMenu__RemoveMenuItem_x                             0x9213A0
#define CContextMenu__RemoveAllMenuItems_x                         0x9213C0
#define CContextMenu__CheckMenuItem_x                              0x921440
#define CContextMenu__SetMenuItem_x                                0x9212C0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x9219E0
#define CContextMenuManager__RemoveMenu_x                          0x921A50
#define CContextMenuManager__PopupMenu_x                           0x921B10
#define CContextMenuManager__Flush_x                               0x921980
#define CContextMenuManager__GetMenu_x                             0x495680

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8BCEF0
#define CChatService__GetFriendName_x                              0x8BCF00

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6EB840
#define CChatWindow__Clear_x                                       0x6EC8A0
#define CChatWindow__WndNotification_x                             0x6ECE10

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x91E2E0
#define CComboWnd__Draw_x                                          0x91D7C0
#define CComboWnd__GetCurChoice_x                                  0x91E120
#define CComboWnd__GetListRect_x                                   0x91DC80
#define CComboWnd__GetTextRect_x                                   0x91E350
#define CComboWnd__InsertChoice_x                                  0x91DE10
#define CComboWnd__SetColors_x                                     0x91DDE0
#define CComboWnd__SetChoice_x                                     0x91E0F0
#define CComboWnd__GetItemCount_x                                  0x91E130
#define CComboWnd__GetCurChoiceText_x                              0x91E170

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6F4B10
#define CContainerWnd__vftable_x                                   0xACAAB0
#define CContainerWnd__SetContainer_x                              0x6F6080

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x537D30
#define CDisplay__GetClickedActor_x                                0x52AD80
#define CDisplay__GetUserDefinedColor_x                            0x523460
#define CDisplay__GetWorldFilePath_x                               0x52C7D0
#define CDisplay__is3dON_x                                         0x527A50
#define CDisplay__ReloadUI_x                                       0x531EF0
#define CDisplay__WriteTextHD2_x                                   0x527830
#define CDisplay__TrueDistance_x                                   0x52E430
#define CDisplay__SetViewActor_x                                   0x52A6D0
#define CDisplay__SetRenderWindow_x                                0x526440
#define CDisplay__ToggleScreenshotMode_x                           0x52A1A0
// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x9408A0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x925560
#define CEditWnd__GetCharIndexPt_x                                 0x926460
#define CEditWnd__GetDisplayString_x                               0x926300
#define CEditWnd__GetHorzOffset_x                                  0x924B90
#define CEditWnd__GetLineForPrintableChar_x                        0x9275A0
#define CEditWnd__GetSelStartPt_x                                  0x926710
#define CEditWnd__GetSTMLSafeText_x                                0x926120
#define CEditWnd__PointFromPrintableChar_x                         0x9271D0
#define CEditWnd__SelectableCharFromPoint_x                        0x927340
#define CEditWnd__SetEditable_x                                    0x9267E0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5DA4B0
#define CEverQuest__ClickedPlayer_x                                0x5CC800
#define CEverQuest__CreateTargetIndicator_x                        0x5E8D30
#define CEverQuest__DeleteTargetIndicator_x                        0x5E8DC0
#define CEverQuest__DoTellWindow_x                                 0x4E1130
#define CEverQuest__OutputTextToLog_x                              0x4E1360
#define CEverQuest__DropHeldItemOnGround_x                         0x5C20C0
#define CEverQuest__dsp_chat_x                                     0x4E16F0
#define CEverQuest__trimName_x                                     0x5E52F0
#define CEverQuest__Emote_x                                        0x5DACC0
#define CEverQuest__EnterZone_x                                    0x5D4EA0
#define CEverQuest__GetBodyTypeDesc_x                              0x5DEB90
#define CEverQuest__GetClassDesc_x                                 0x5DF1D0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5DF7D0
#define CEverQuest__GetDeityDesc_x                                 0x5E7680
#define CEverQuest__GetLangDesc_x                                  0x5DF990
#define CEverQuest__GetRaceDesc_x                                  0x5DF1B0
#define CEverQuest__InterpretCmd_x                                 0x5E7C50
#define CEverQuest__LeftClickedOnPlayer_x                          0x5C62B0
#define CEverQuest__LMouseUp_x                                     0x5C4630
#define CEverQuest__RightClickedOnPlayer_x                         0x5C6B90
#define CEverQuest__RMouseUp_x                                     0x5C55C0
#define CEverQuest__SetGameState_x                                 0x5C1E50
#define CEverQuest__UPCNotificationFlush_x                         0x5E51F0
#define CEverQuest__IssuePetCommand_x                              0x5E0D90
#define CEverQuest__ReportSuccessfulHit_x                          0x5DB9E0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x706A70
#define CGaugeWnd__CalcLinesFillRect_x                             0x706AD0
#define CGaugeWnd__Draw_x                                          0x706160

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ABC80
#define CGuild__GetGuildName_x                                     0x4AACC0
#define CGuild__GetGuildIndex_x                                    0x4AB050

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x721E10

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x72ECB0
#define CInvSlotMgr__MoveItem_x                                    0x72DA10
#define CInvSlotMgr__SelectSlot_x                                  0x72ED80

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x72C2C0
#define CInvSlot__SliderComplete_x                                 0x72A0E0
#define CInvSlot__GetItemBase_x                                    0x729A70
#define CInvSlot__UpdateItem_x                                     0x729BE0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7306D0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x72F9A0
#define CInvSlotWnd__HandleLButtonUp_x                             0x730250

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7EC090
#define CItemDisplayWnd__UpdateStrings_x                           0x73E460
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x7384B0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x738990
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x73E9F0
#define CItemDisplayWnd__AboutToShow_x                             0x73E0B0
#define CItemDisplayWnd__WndNotification_x                         0x73FD00

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x823B30

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x743D60

// CLabel 
#define CLabel__Draw_x                                             0x749890

// CListWnd
#define CListWnd__CListWnd_x                                       0x8F6A00
#define CListWnd__dCListWnd_x                                      0x8F6D20
#define CListWnd__AddColumn_x                                      0x8FB040
#define CListWnd__AddColumn1_x                                     0x8FB090
#define CListWnd__AddLine_x                                        0x8FB420
#define CListWnd__AddString_x                                      0x8FB220
#define CListWnd__CalculateFirstVisibleLine_x                      0x8FAE10
#define CListWnd__CalculateVSBRange_x                              0x8FABF0
#define CListWnd__ClearSel_x                                       0x8FBC00
#define CListWnd__ClearAllSel_x                                    0x8FBC60
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8FC650
#define CListWnd__Compare_x                                        0x8FA530
#define CListWnd__Draw_x                                           0x8F6E20
#define CListWnd__DrawColumnSeparators_x                           0x8F9600
#define CListWnd__DrawHeader_x                                     0x8F9A70
#define CListWnd__DrawItem_x                                       0x8F9E70
#define CListWnd__DrawLine_x                                       0x8F9770
#define CListWnd__DrawSeparator_x                                  0x8F96A0
#define CListWnd__EnableLine_x                                     0x8F8EE0
#define CListWnd__EnsureVisible_x                                  0x8FC580
#define CListWnd__ExtendSel_x                                      0x8FBB30
#define CListWnd__GetColumnMinWidth_x                              0x8F8A20
#define CListWnd__GetColumnWidth_x                                 0x8F8990
#define CListWnd__GetCurSel_x                                      0x8F8320
#define CListWnd__GetItemAtPoint_x                                 0x8F9150
#define CListWnd__GetItemAtPoint1_x                                0x8F91C0
#define CListWnd__GetItemData_x                                    0x8F83A0
#define CListWnd__GetItemHeight_x                                  0x8F8760
#define CListWnd__GetItemIcon_x                                    0x8F8530
#define CListWnd__GetItemRect_x                                    0x8F8FD0
#define CListWnd__GetItemText_x                                    0x8F83E0
#define CListWnd__GetSelList_x                                     0x8FBCB0
#define CListWnd__GetSeparatorRect_x                               0x8F9400
#define CListWnd__InsertLine_x                                     0x8FB810
#define CListWnd__RemoveLine_x                                     0x8FB960
#define CListWnd__SetColors_x                                      0x8FABC0
#define CListWnd__SetColumnJustification_x                         0x8FA8F0
#define CListWnd__SetColumnWidth_x                                 0x8FA810
#define CListWnd__SetCurSel_x                                      0x8FBA70
#define CListWnd__SetItemColor_x                                   0x8FC240
#define CListWnd__SetItemData_x                                    0x8FC200
#define CListWnd__SetItemText_x                                    0x8FBE30
#define CListWnd__ShiftColumnSeparator_x                           0x8FA9B0
#define CListWnd__Sort_x                                           0x8FA6B0
#define CListWnd__ToggleSel_x                                      0x8FBAA0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x75ED40

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x781F50
#define CMerchantWnd__RequestBuyItem_x                             0x782830
#define CMerchantWnd__RequestSellItem_x                            0x782D70
#define CMerchantWnd__SelectRecoverySlot_x                         0x785BA0
//did this get another arg?
#define CMerchantWnd__SelectBuySellSlot_x                          0x7825B0
#define CMerchantWnd__ActualSelect_x                               0x78B730

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x88AF10
#define CPacketScrambler__hton_x                                   0x88AF00

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x915830
#define CSidlManager__FindScreenPieceTemplate_x                    0x915C40
#define CSidlManager__FindScreenPieceTemplate1_x                   0x915A30
#define CSidlManager__CreateLabel_x                                0x7E3480
#define CSidlManager__CreateXWndFromTemplate_x                     0x918D10
#define CSidlManager__CreateXWndFromTemplate1_x                    0x918EF0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9123A0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9122A0
#define CSidlScreenWnd__ConvertToRes_x                             0x937130
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x911D30
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x911A20
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x911AF0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x911BC0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x912840
#define CSidlScreenWnd__EnableIniStorage_x                         0x912D10
#define CSidlScreenWnd__GetSidlPiece_x                             0x912A30
#define CSidlScreenWnd__Init1_x                                    0x911610
#define CSidlScreenWnd__LoadIniInfo_x                              0x912D60
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9138A0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x910A10
#define CSidlScreenWnd__StoreIniInfo_x                             0x913420
#define CSidlScreenWnd__StoreIniVis_x                              0x913780
#define CSidlScreenWnd__WndNotification_x                          0x912750
#define CSidlScreenWnd__GetChildItem_x                             0x912C90
#define CSidlScreenWnd__HandleLButtonUp_x                          0x902450
#define CSidlScreenWnd__m_layoutCopy_x                             0x169B7B8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x65E100
#define CSkillMgr__GetSkillCap_x                                   0x65E2E0
#define CSkillMgr__GetNameToken_x                                  0x65D890

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9227D0
#define CSliderWnd__SetValue_x                                     0x922640
#define CSliderWnd__SetNumTicks_x                                  0x9226A0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7E9300

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x929440
#define CStmlWnd__CalculateHSBRange_x                              0x92A4B0
#define CStmlWnd__CalculateVSBRange_x                              0x92A420
#define CStmlWnd__CanBreakAtCharacter_x                            0x92E7F0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x92F3E0
#define CStmlWnd__ForceParseNow_x                                  0x9299E0
#define CStmlWnd__GetNextTagPiece_x                                0x92E750
#define CStmlWnd__GetSTMLText_x                                    0x4EF580
#define CStmlWnd__GetVisibleText_x                                 0x929A00
#define CStmlWnd__InitializeWindowVariables_x                      0x92F230
#define CStmlWnd__MakeStmlColorTag_x                               0x928BD0
#define CStmlWnd__MakeWndNotificationTag_x                         0x928C40
#define CStmlWnd__SetSTMLText_x                                    0x927CA0
#define CStmlWnd__StripFirstSTMLLines_x                            0x930530
#define CStmlWnd__UpdateHistoryString_x                            0x92F5F0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x933C30
#define CTabWnd__DrawCurrentPage_x                                 0x934250
#define CTabWnd__DrawTab_x                                         0x934020
#define CTabWnd__GetCurrentPage_x                                  0x933490
#define CTabWnd__GetPageInnerRect_x                                0x9336D0
#define CTabWnd__GetTabInnerRect_x                                 0x933610
#define CTabWnd__GetTabRect_x                                      0x9334C0
#define CTabWnd__InsertPage_x                                      0x9338C0
#define CTabWnd__SetPage_x                                         0x933750
#define CTabWnd__SetPageRect_x                                     0x933B70
#define CTabWnd__UpdatePage_x                                      0x933EE0
#define CTabWnd__GetPageFromTabIndex_x                             0x933F60
#define CTabWnd__GetCurrentTabIndex_x                              0x933480

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x7441D0
#define CPageWnd__SetTabText_x                                     0x940CB0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A5720

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8FF290
#define CTextureFont__GetTextExtent_x                              0x8FF450

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x691A90
#define CHtmlComponentWnd__ValidateUri_x                           0x723800
#define CHtmlWnd__SetClientCallbacks_x                             0x5FF130
#define CHtmlWnd__AddObserver_x                                    0x5FF150
#define CHtmlWnd__RemoveObserver_x                                 0x5FF1B0
#define Window__getProgress_x                                      0x83C630
#define Window__getStatus_x                                        0x83C650
#define Window__getURI_x                                           0x83C660

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x93D230

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8EC370

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4ACEE0
#define CXStr__CXStr1_x                                            0x82CA60
#define CXStr__CXStr3_x                                            0x8D8700
#define CXStr__dCXStr_x                                            0x472270
#define CXStr__operator_equal_x                                    0x8D8930
#define CXStr__operator_equal1_x                                   0x8D8970
#define CXStr__operator_plus_equal1_x                              0x8D9400

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x920A70
#define CXWnd__BringToTop_x                                        0x905C80
#define CXWnd__Center_x                                            0x905800
#define CXWnd__ClrFocus_x                                          0x905630
#define CXWnd__Destroy_x                                           0x9056E0
#define CXWnd__DoAllDrawing_x                                      0x901BE0
#define CXWnd__DrawChildren_x                                      0x901BB0
#define CXWnd__DrawColoredRect_x                                   0x902040
#define CXWnd__DrawTooltip_x                                       0x9006F0
#define CXWnd__DrawTooltipAtPoint_x                                0x9007B0
#define CXWnd__GetBorderFrame_x                                    0x901EA0
#define CXWnd__GetChildWndAt_x                                     0x905D20
#define CXWnd__GetClientClipRect_x                                 0x903ED0
#define CXWnd__GetScreenClipRect_x                                 0x903FA0
#define CXWnd__GetScreenRect_x                                     0x904170
#define CXWnd__GetTooltipRect_x                                    0x902090
#define CXWnd__GetWindowTextA_x                                    0x496D60
#define CXWnd__IsActive_x                                          0x908B90
#define CXWnd__IsDescendantOf_x                                    0x904B90
#define CXWnd__IsReallyVisible_x                                   0x904BC0
#define CXWnd__IsType_x                                            0x906390
#define CXWnd__Move_x                                              0x904C30
#define CXWnd__Move1_x                                             0x904CF0
#define CXWnd__ProcessTransition_x                                 0x9057B0
#define CXWnd__Refade_x                                            0x904FD0
#define CXWnd__Resize_x                                            0x905290
#define CXWnd__Right_x                                             0x905A40
#define CXWnd__SetFocus_x                                          0x9055F0
#define CXWnd__SetFont_x                                           0x905660
#define CXWnd__SetKeyTooltip_x                                     0x9061B0
#define CXWnd__SetMouseOver_x                                      0x903020
#define CXWnd__StartFade_x                                         0x904A60
#define CXWnd__GetChildItem_x                                      0x905E90
#define CXWnd__SetParent_x                                         0x904920

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x938200

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x908BD0
#define CXWndManager__DrawWindows_x                                0x908BF0
#define CXWndManager__GetKeyboardFlags_x                           0x90B2B0
#define CXWndManager__HandleKeyboardMsg_x                          0x90AEB0
#define CXWndManager__RemoveWnd_x                                  0x90B500
#define CXWndManager__RemovePendingDeletionWnd_x                   0x90BA40

// CDBStr
#define CDBStr__GetString_x                                        0x522410

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B7C10
#define EQ_Character__Cur_HP_x                                     0x4CDEF0
#define EQ_Character__Cur_Mana_x                                   0x4D53A0
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BAD30
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AEAE0
#define EQ_Character__GetFocusRangeModifier_x                      0x4AEC30
#define EQ_Character__GetHPRegen_x                                 0x4DAA80
#define EQ_Character__GetEnduranceRegen_x                          0x4DB090
#define EQ_Character__GetManaRegen_x                               0x4DB4D0
#define EQ_Character__Max_Endurance_x                              0x624EE0
#define EQ_Character__Max_HP_x                                     0x4CDD20
#define EQ_Character__Max_Mana_x                                   0x624CE0
#define EQ_Character__doCombatAbility_x                            0x627090
#define EQ_Character__UseSkill_x                                   0x4DD2C0
#define EQ_Character__GetConLevel_x                                0x61E350
#define EQ_Character__IsExpansionFlag_x                            0x585BD0
#define EQ_Character__TotalEffect_x                                0x4C13C0
#define EQ_Character__GetPCSpellAffect_x                           0x4BB920
#define EQ_Character__SpellDuration_x                              0x4BB450
#define EQ_Character__FindItemByRecord_x                           0x4D3500
#define EQ_Character__GetAdjustedSkill_x                           0x4D0C30
#define EQ_Character__GetBaseSkill_x                               0x4D1BD0
#define EQ_Character__CanUseItem_x                                 0x4D56B0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8AA070

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x63B280

//PcClient
#define PcClient__PcClient_x                                       0x61BC10

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B59F0
#define CCharacterListWnd__EnterWorld_x                            0x4B5430
#define CCharacterListWnd__Quit_x                                  0x4B5140
#define CCharacterListWnd__UpdateList_x                            0x4B55C0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x600340
#define EQ_Item__CreateItemTagString_x                             0x885270
#define EQ_Item__IsStackable_x                                     0x8893D0
#define EQ_Item__GetImageNum_x                                     0x8869F0
#define EQ_Item__CreateItemClient_x                                0x5FF510
#define EQ_Item__GetItemValue_x                                    0x887AA0
#define EQ_Item__ValueSellMerchant_x                               0x88AAA0
#define EQ_Item__IsKeyRingItem_x                                   0x888D90
#define EQ_Item__CanGoInBag_x                                      0x600460
#define EQ_Item__GetMaxItemCount_x                                 0x887BA0
#define EQ_Item__GetHeldItem_x                                     0x8868C0
#define EQ_Item__GetAugmentFitBySlot_x                             0x884DB0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x5405F0
#define EQ_LoadingS__Array_x                                       0xBDB2D0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x625840
#define EQ_PC__GetAlternateAbilityId_x                             0x893CD0
#define EQ_PC__GetCombatAbility_x                                  0x894340
#define EQ_PC__GetCombatAbilityTimer_x                             0x8943B0
#define EQ_PC__GetItemRecastTimer_x                                0x627610
#define EQ_PC__HasLoreItem_x                                       0x61EAC0
#define EQ_PC__AlertInventoryChanged_x                             0x61DE20
#define EQ_PC__GetPcZoneClient_x                                   0x6499B0
#define EQ_PC__RemoveMyAffect_x                                    0x62A750
#define EQ_PC__GetKeyRingItems_x                                   0x894C50
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8949D0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x894F40

// EQItemList 
#define EQItemList__EQItemList_x                                   0x58BED0
#define EQItemList__add_object_x                                   0x5B7810
#define EQItemList__add_item_x                                     0x58C4E0
#define EQItemList__delete_item_x                                  0x58C530
#define EQItemList__FreeItemList_x                                 0x58C430

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x51FA30

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x63CB00
#define EQPlayer__dEQPlayer_x                                      0x62FDD0
#define EQPlayer__DoAttack_x                                       0x6446D0
#define EQPlayer__EQPlayer_x                                       0x630480
#define EQPlayer__SetNameSpriteState_x                             0x634B30
#define EQPlayer__SetNameSpriteTint_x                              0x635A00
#define PlayerBase__HasProperty_j_x                                0x96B5E0
#define EQPlayer__IsTargetable_x                                   0x96BA80
#define EQPlayer__CanSee_x                                         0x96B8E0
#define EQPlayer__CanSee1_x                                        0x96B9B0
#define PlayerBase__GetVisibilityLineSegment_x                     0x96B6A0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x6474A0
#define PlayerZoneClient__GetLevel_x                               0x6499F0
#define PlayerZoneClient__IsValidTeleport_x                        0x5B8960
#define PlayerZoneClient__LegalPlayerRace_x                        0x539B10

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x63F7F0
#define EQPlayerManager__GetSpawnByName_x                          0x63F810
#define EQPlayerManager__GetPlayerFromPartialName_x                0x63F8A0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x603BB0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x603BF0
#define KeypressHandler__ClearCommandStateArray_x                  0x604FE0
#define KeypressHandler__HandleKeyDown_x                           0x605000
#define KeypressHandler__HandleKeyUp_x                             0x6050A0
#define KeypressHandler__SaveKeymapping_x                          0x605480

// MapViewMap 
#define MapViewMap__Clear_x                                        0x75ABD0
#define MapViewMap__SaveEx_x                                       0x75DF70
#define MapViewMap__SetZoom_x                                      0x762640

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8A7F60

// StringTable 
#define StringTable__getString_x                                   0x8A2E40

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x62A3C0
#define PcZoneClient__RemovePetEffect_x                            0x62A9F0
#define PcZoneClient__HasAlternateAbility_x                        0x624B20
#define PcZoneClient__GetCurrentMod_x                              0x4E0230
#define PcZoneClient__GetModCap_x                                  0x4E0130
#define PcZoneClient__CanEquipItem_x                               0x6251D0
#define PcZoneClient__GetItemByID_x                                0x627A90
#define PcZoneClient__GetItemByItemClass_x                         0x627B20
#define PcZoneClient__RemoveBuffEffect_x                           0x62AA10

//Doors
#define EQSwitch__UseSwitch_x                                      0x5BD5B0

//IconCache
#define IconCache__GetIcon_x                                       0x6FC1D0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6F3CB0
#define CContainerMgr__CloseContainer_x                            0x6F3F80
#define CContainerMgr__OpenExperimentContainer_x                   0x6F4A00

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7B5E20

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5F8560

//CLootWnd
#define CLootWnd__LootAll_x                                        0x751050
#define CLootWnd__RequestLootSlot_x                                0x750410

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x558B10
#define EQ_Spell__SpellAffects_x                                   0x558F80
#define EQ_Spell__SpellAffectBase_x                                0x558D40
#define EQ_Spell__IsStackable_x                                    0x4C5BC0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C5A10
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B2FF0
#define EQ_Spell__IsSPAStacking_x                                  0x559DB0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x5592D0
#define EQ_Spell__IsNoRemove_x                                     0x4C5BA0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x559DC0
#define __IsResEffectSpell_x                                       0x4C4F00

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4A9920

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8B24E0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7FB420
#define CTargetWnd__WndNotification_x                              0x7FACB0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7FAF80
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x7F9E00

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7FFAF0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5540B0
#define EqSoundManager__PlayScriptMp3_x                            0x554210
#define EqSoundManager__SoundAssistPlay_x                          0x661C60
#define EqSoundManager__WaveInstancePlay_x                         0x6611D0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x5113C0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x9241C0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x548360
#define CAltAbilityData__GetMercMaxRank_x                          0x548300
#define CAltAbilityData__GetMaxRank_x                              0x53D830

//CTargetRing
#define CTargetRing__Cast_x                                        0x5F6660

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C59F0
#define CharacterBase__CreateItemGlobalIndex_x                     0x4F7720
#define CharacterBase__CreateItemIndex_x                           0x5FE740
#define CharacterBase__GetItemPossession_x                         0x4B2EA0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8BAA30
#define CharacterBase__GetEffectId_x                               0x4C59A0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6DBEE0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6DC700

//messages
#define msg_spell_worn_off_x                                       0x57E2D0
#define msg_new_text_x                                             0x5734A0
#define __msgTokenTextParam_x                                      0x580920
#define msgTokenText_x                                             0x580B70

//SpellManager
#define SpellManager__vftable_x                                    0xAA5818
#define SpellManager__SpellManager_x                               0x664F80
#define Spellmanager__LoadTextSpells_x                             0x665850
#define SpellManager__GetSpellByGroupAndRank_x                     0x665150

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x96F5C0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4F7E00
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x584110
#define ItemGlobalIndex__IsEquippedLocation_x                      0x617480
#define ItemGlobalIndex__IsValidIndex_x                            0x4F7E60

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8B2E20
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8B30A0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x749BE0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6F8420
#define CCursorAttachment__Deactivate_x                            0x6F9400

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9365B0
#define CEQSuiteTextureLoader__GetTexture_x                        0x936270

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4F4DD0

//IString
#define IString__Append_x                                          0x4E9570

//Camera
#define CDisplay__cameraType_x                                     0xDAAE08
#define EverQuest__Cameras_x                                       0xE6E114

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x4FD4F0
#define LootFiltersManager__GetItemFilterData_x                    0x4FCDE0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x4FCE10
#define LootFiltersManager__SetItemLootFilter_x                    0x4FD030

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7A3E20

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9752F0
#define CResolutionHandler__GetWindowedStyle_x                     0x65CC30

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6F09F0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8C4E60

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
