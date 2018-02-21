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
#define __ExpectedVersionDate                                     "Feb 16 2018"
#define __ExpectedVersionTime                                     "11:11:03"
#define __ActualVersionDate_x                                      0xADBC20
#define __ActualVersionTime_x                                      0xADBC14

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x6AABF0
#define __MemChecker1_x                                            0x99D900
#define __MemChecker2_x                                            0x7437D0
#define __MemChecker3_x                                            0x743710
#define __MemChecker4_x                                            0x8F8040
#define __EncryptPad0_x                                            0xC3EF60
#define __EncryptPad1_x                                            0xD159E0
#define __EncryptPad2_x                                            0xC67DF8
#define __EncryptPad3_x                                            0xC679F8
#define __EncryptPad4_x                                            0xD06750
#define __EncryptPad5_x                                            0x10C244C
#define __AC1_x                                                    0x8B3996
#define __AC2_x                                                    0x66494D
#define __AC3_x                                                    0x66B7FD
#define __AC4_x                                                    0x66F70E
#define __AC5_x                                                    0x67596D
#define __AC6_x                                                    0x679E40
#define __AC7_x                                                    0x6643BE
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FA4F70

// Direct Input
#define DI8__Main_x                                                0xFB7290
#define DI8__Keyboard_x                                            0xFB7294
#define DI8__Mouse_x                                               0xFB73AC
#define DI8__Mouse_Copy_x                                          0xF303B4
#define DI8__Mouse_Check_x                                         0xFB76D0
#define __AutoSkillArray_x                                         0xF312C4
#define __Attack_x                                                 0xFB49B7
#define __Autofire_x                                               0xFB49B8
#define __BindList_x                                               0xC1B100
#define g_eqCommandStates_x                                        0xC1BE60
#define __Clicks_x                                                 0xF3046C
#define __CommandList_x                                            0xC1DA28
#define __CurrentMapLabel_x                                        0x10C8380
#define __CurrentSocial_x                                          0xBEB410
#define __DoAbilityList_x                                          0xF66B7C
#define __do_loot_x                                                0x630CB0
#define __DrawHandler_x                                            0x1731F28
#define __GroupCount_x                                             0xF206E2

#define __Guilds_x                                                 0xF26620
#define __gWorld_x                                                 0xF20F20
#define __HotkeyPage_x                                             0xFAD57C
#define __HWnd_x                                                   0xFB73B0
#define __InChatMode_x                                             0xF3039C
#define __LastTell_x                                               0xF32278
#define __LMouseHeldTime_x                                         0xF304D8
#define __Mouse_x                                                  0xFB7278
#define __MouseLook_x                                              0xF30432
#define __MouseEventTime_x                                         0xFB5170
#define __gpbCommandEvent_x                                        0xF208D4
#define __NetStatusToggle_x                                        0xF30435
#define __PCNames_x                                                0xF31880
#define __RangeAttackReady_x                                       0xF315A8
#define __RMouseHeldTime_x                                         0xF304D4
#define __RunWalkState_x                                           0xF303A0
#define __ScreenMode_x                                             0xE6F6A4
#define __ScreenX_x                                                0xF30354
#define __ScreenY_x                                                0xF30350
#define __ScreenXMax_x                                             0xF30358
#define __ScreenYMax_x                                             0xF3035C
#define __ServerHost_x                                             0xF20B4B
#define __ServerName_x                                             0xF66B3C
#define __ShiftKeyDown_x                                           0xF30A2C
#define __ShowNames_x                                              0xF31760
#define __Socials_x                                                0xF66C3C
#define __SubscriptionType_x                                       0x10F8C4C
#define __TargetAggroHolder_x                                      0x10CA5BC
#define __ZoneType_x                                               0xF30830
#define __GroupAggro_x                                             0x10CA5FC
#define __LoginName_x                                              0x10C20EC
#define __Inviter_x                                                0xFB4934
#define __AttackOnAssist_x                                         0xF3171C
#define __UseTellWindows_x                                         0xF31A18

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF22FB0
#define instEQZoneInfo_x                                           0xF30628
#define instKeypressHandler_x                                      0xFB5150
#define pinstActiveBanker_x                                        0xF22F3C
#define pinstActiveCorpse_x                                        0xF22F34
#define pinstActiveGMaster_x                                       0xF22F38
#define pinstActiveMerchant_x                                      0xF22F30
#define pinstAggroInfo_x                                           0xD2C488
#define pinstAltAdvManager_x                                       0xE70000
#define pinstAuraMgr_x                                             0xD3CC50
#define pinstBandageTarget_x                                       0xF22F4C
#define pinstCamActor_x                                            0xE6F698
#define pinstCDBStr_x                                              0xE6EE28
#define pinstCDisplay_x                                            0xF20698
#define pinstCEverQuest_x                                          0xFB71F0
#define pinstEverQuestInfo_x                                       0xF30348
#define pinstCharData_x                                            0xF206BC
#define pinstCharSpawn_x                                           0xF22F88
#define pinstControlledMissile_x                                   0xF20690
#define pinstControlledPlayer_x                                    0xF22F88
#define pinstCSidlManager_x                                        0x1731178
#define pinstCXWndManager_x                                        0x1731174
#define instDynamicZone_x                                          0xF301E8
#define pinstDZMember_x                                            0xF302F8
#define pinstDZTimerInfo_x                                         0xF302FC
#define pinstEQItemList_x                                          0xF1F430
#define pinstEQObjectList_x                                        0xF20468
#define instEQMisc_x                                               0xE6ED88
#define pinstEQSoundManager_x                                      0xE705F0
#define pinstEQSpellStrings_x                                      0xD3A2D0 
#define instExpeditionLeader_x                                     0xF30232
#define instExpeditionName_x                                       0xF30272
#define pinstGroup_x                                               0xF206DE
#define pinstImeManager_x                                          0x1731170
#define pinstLocalPlayer_x                                         0xF20F2C
#define pinstMercenaryData_x                                       0xFB57C4
#define pinstMercenaryStats_x                                      0x10CA708
#define pinstMercAltAbilities_x                                    0xE70420
#define pinstModelPlayer_x                                         0xF22F44
#define pinstPCData_x                                              0xF206BC
#define pinstSkillMgr_x                                            0xFB6818
#define pinstSpawnManager_x                                        0xFB6040
#define pinstSpellManager_x                                        0xFB6968
#define pinstSpellSets_x                                           0xFAD5E0
#define pinstStringTable_x                                         0xF20E1C
#define pinstSwitchManager_x                                       0xF20598
#define pinstTarget_x                                              0xF22F80
#define pinstTargetObject_x                                        0xF22F84
#define pinstTargetSwitch_x                                        0xF206C0
#define pinstTaskMember_x                                          0xE6EC48
#define pinstTrackTarget_x                                         0xF22F8C
#define pinstTradeTarget_x                                         0xF22F40
#define instTributeActive_x                                        0xE6EDAD
#define pinstViewActor_x                                           0xE6F694
#define pinstWorldData_x                                           0xF208D8
#define pinstZoneAddr_x                                            0xF308C8
#define pinstPlayerPath_x                                          0xFB60A8
#define pinstTargetIndicator_x                                     0xFB6B10
#define pinstCTargetManager_x                                      0xFB6B78
#define EQObject_Top_x                                             0xF20F28
#define pinstRealEstateItems_x                                     0xFB6770
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xE6F6B8
#define pinstCAchievementsWnd_x                                    0xE6F70C
#define pinstCActionsWnd_x                                         0xE6F614
#define pinstCAdvancedDisplayOptionsWnd_x                          0xE6F550
#define pinstCAdvancedLootWnd_x                                    0xE6EE98
#define pinstCAdventureLeaderboardWnd_x                            0x10C2E10
#define pinstCAdventureRequestWnd_x                                0x10C2E90
#define pinstCAdventureStatsWnd_x                                  0x10C2F10
#define pinstCAggroMeterWnd_x                                      0xE6F5EC
#define pinstCAlarmWnd_x                                           0xE6F5F4
#define pinstCAlertHistoryWnd_x                                    0xE6F5E8
#define pinstCAlertStackWnd_x                                      0xE6F134
#define pinstCAlertWnd_x                                           0xE6F558
#define pinstCAltStorageWnd_x                                      0x10C3180
#define pinstCAudioTriggersWindow_x                                0xD2C7B0
#define pinstCAuraWnd_x                                            0xE6F5BC
#define pinstCAvaZoneWnd_x                                         0xE6F6E8
#define pinstCBandolierWnd_x                                       0xE6F5F8
#define pinstCBankWnd_x                                            0xE6F54C
#define pinstCBarterMerchantWnd_x                                  0x10C3ED0
#define pinstCBarterSearchWnd_x                                    0x10C3F50
#define pinstCBarterWnd_x                                          0x10C3FD0
#define pinstCBazaarConfirmationWnd_x                              0xE6F674
#define pinstCBazaarSearchWnd_x                                    0xE6F588
#define pinstCBazaarWnd_x                                          0xE6F648
#define pinstCBlockedBuffWnd_x                                     0xE6F5B8
#define pinstCBlockedPetBuffWnd_x                                  0xE6F5E0
#define pinstCBodyTintWnd_x                                        0xE6F544
#define pinstCBookWnd_x                                            0xE6F61C
#define pinstCBreathWnd_x                                          0xE6F6D0
#define pinstCBuffWindowNORMAL_x                                   0xE6F594
#define pinstCBuffWindowSHORT_x                                    0xE6F598
#define pinstCBugReportWnd_x                                       0xE6F700
#define pinstCCastingWnd_x                                         0xE6F5A8
#define pinstCCastSpellWnd_x                                       0xE6F658
#define pinstCCharacterListWnd_x                                   0xE6EE9C
#define pinstCChatWindowManager_x                                  0x10C47F0
#define pinstCClaimWnd_x                                           0x10C48E8
#define pinstCColorPickerWnd_x                                     0xE6F670
#define pinstCCombatAbilityWnd_x                                   0xE6F690
#define pinstCCombatSkillsSelectWnd_x                              0xE6EEA8
#define pinstCCompassWnd_x                                         0xE6F53C
#define pinstCConfirmationDialog_x                                 0x10C8C30
#define pinstCContainerMgr_x                                       0xE6F65C
#define pinstCContextMenuManager_x                                 0x1731128
#define pinstCCursorAttachment_x                                   0xE6F5A4
#define pinstCDynamicZoneWnd_x                                     0x10C4D30
#define pinstCEditLabelWnd_x                                       0xE6F59C
#define pinstCEQMainWnd_x                                          0x10C4EF8
#define pinstCEventCalendarWnd_x                                   0xE6F5B0
#define pinstCFacePick_x                                           0xE6F540
#define pinstCFeedbackWnd_x                                        0xE6F6EC
#define pinstCFellowshipWnd_x                                      0x10C50E0
#define pinstCFileSelectionWnd_x                                   0xE6F6F4
#define pinstCFindItemWnd_x                                        0xE6F714
#define pinstCFindLocationWnd_x                                    0x10C51D8
#define pinstCFriendsWnd_x                                         0xE6EEBC
#define pinstCGemsGameWnd_x                                        0xE6F5CC
#define pinstCGiveWnd_x                                            0xE6F650
#define pinstCGroupSearchFiltersWnd_x                              0xE6F610
#define pinstCGroupSearchWnd_x                                     0x10C54B0
#define pinstCGroupWnd_x                                           0x10C5530
#define pinstCGuildBankWnd_x                                       0x10C55B0
#define pinstCGuildCreationWnd_x                                   0x10C5630
#define pinstCGuildMgmtWnd_x                                       0x10C56B4
#define pinstCharacterCreation_x                                   0xE6EEA4
#define pinstCHelpWnd_x                                            0xE6F570
#define pinstCHeritageSelectionWnd_x                               0xE6F56C
#define pinstCHotButtonWnd_x                                       0x10C77AC
#define pinstCHotButtonWnd1_x                                      0x10C77AC
#define pinstCHotButtonWnd2_x                                      0x10C77B0
#define pinstCHotButtonWnd3_x                                      0x10C77B4
#define pinstCHotButtonWnd4_x                                      0x10C77D8
#define pinstCIconSelectionWnd_x                                   0xE6F604
#define pinstCInspectWnd_x                                         0xE6F6B4
#define pinstCInventoryWnd_x                                       0xE6F708
#define pinstCInvSlotMgr_x                                         0xE6F618
#define pinstCItemDisplayManager_x                                 0x10C7C38
#define pinstCItemExpTransferWnd_x                                 0x10C7D38
#define pinstCItemOverflowWnd_x                                    0xE6F590
#define pinstCJournalCatWnd_x                                      0xE6F710
#define pinstCJournalTextWnd_x                                     0xE6F6C8
#define pinstCKeyRingWnd_x                                         0xE6EEB4
#define pinstCLargeDialogWnd_x                                     0x10C95C8
#define pinstCLayoutCopyWnd_x                                      0x10C7F98
#define pinstCLFGuildWnd_x                                         0x10C8018
#define pinstCLoadskinWnd_x                                        0xE6F5E4
#define pinstCLootFiltersCopyWnd_x                                 0xD3D228
#define pinstCLootFiltersWnd_x                                     0xE6F6C0
#define pinstCLootSettingsWnd_x                                    0xE6F6DC
#define pinstCLootWnd_x                                            0xE6F5C0
#define pinstCMailAddressBookWnd_x                                 0xE6F6E0
#define pinstCMailCompositionWnd_x                                 0xE6F6BC
#define pinstCMailIgnoreListWnd_x                                  0xE6F6E4
#define pinstCMailWnd_x                                            0xE6F68C
#define pinstCManageLootWnd_x                                      0xE70328
#define pinstCMapToolbarWnd_x                                      0xE6F584
#define pinstCMapViewWnd_x                                         0xE6F55C
#define pinstCMarketplaceWnd_x                                     0xE6F564
#define pinstCMerchantWnd_x                                        0xE6F578
#define pinstCMIZoneSelectWnd_x                                    0x10C8610
#define pinstCMusicPlayerWnd_x                                     0xE6F64C
#define pinstCNameChangeMercWnd_x                                  0xE6F71C
#define pinstCNameChangePetWnd_x                                   0xE6F6F8
#define pinstCNameChangeWnd_x                                      0xE6EEAC
#define pinstCNoteWnd_x                                            0xE6F568
#define pinstCObjectPreviewWnd_x                                   0xE6F580
#define pinstCOptionsWnd_x                                         0xE6F554
#define pinstCPetInfoWnd_x                                         0xE6F654
#define pinstCPetitionQWnd_x                                       0xE6F680
#define pinstCPlayerNotesWnd_x                                     0xE6F560
#define pinstCPlayerWnd_x                                          0xE6F5AC
#define pinstCPopupWndManager_x                                    0x10C8C30
#define pinstCPotionBeltWnd_x                                      0xE6F60C
#define pinstCProgressionSelectionWnd_x                            0x10C8D28
#define pinstCPurchaseGroupWnd_x                                   0xE6F5C4
#define pinstCPurchaseWnd_x                                        0xE6F5A0
#define pinstCPvPLeaderboardWnd_x                                  0x10C8DA8
#define pinstCPvPStatsWnd_x                                        0x10C8E28
#define pinstCQuantityWnd_x                                        0xE6F57C
#define pinstCRaceChangeWnd_x                                      0xE6F548
#define pinstCRaidOptionsWnd_x                                     0xE6F600
#define pinstCRaidWnd_x                                            0xE6F688
#define pinstCRealEstateItemsWnd_x                                 0xE6F6FC
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE6F67C
#define pinstCRealEstateManageWnd_x                                0xE6F5F0
#define pinstCRealEstateNeighborhoodWnd_x                          0xE6F608
#define pinstCRealEstatePlotSearchWnd_x                            0xE6F620
#define pinstCRealEstatePurchaseWnd_x                              0xE6F644
#define pinstCRespawnWnd_x                                         0xE6F5D8
#define pinstCSelectorWnd_x                                        0xE6F5FC
#define pinstCSendMoneyWnd_x                                       0xE6F668
#define pinstCServerListWnd_x                                      0xE6F58C
#define pinstCSkillsSelectWnd_x                                    0xE6F718
#define pinstCSkillsWnd_x                                          0xE6F6F0
#define pinstCSocialEditWnd_x                                      0xE6F6D4
#define pinstCSocialWnd_x                                          0xE6F660
#define pinstCSpellBookWnd_x                                       0xE6F6A8
#define pinstCStoryWnd_x                                           0xE6EEB0
#define pinstCTargetOfTargetWnd_x                                  0x10CA790
#define pinstCTargetWnd_x                                          0xE6F5DC
#define pinstCTaskOverlayWnd_x                                     0xE6F72C
#define pinstCTaskSelectWnd_x                                      0x10CA888
#define pinstCTaskSomething_x                                      0xD3D7F0
#define pinstCTaskTemplateSelectWnd_x                              0x10CA908
#define pinstCTaskWnd_x                                            0x10CA988
#define pinstCTextEntryWnd_x                                       0xE6F574
#define pinstCTextOverlay_x                                        0xD2C9C8
#define pinstCTimeLeftWnd_x                                        0xE6F66C
#define pinstCTipWndCONTEXT_x                                      0x10CAAFC
#define pinstCTipWndOFDAY_x                                        0x10CAAF8
#define pinstCTitleWnd_x                                           0x10CAB78
#define pinstCTrackingWnd_x                                        0xE6F684
#define pinstCTradeskillWnd_x                                      0x10CAC80
#define pinstCTradeWnd_x                                           0xE6F5D4
#define pinstCTrainWnd_x                                           0xE6F678
#define pinstCTributeBenefitWnd_x                                  0x10CADF0
#define pinstCTributeMasterWnd_x                                   0x10CAE70
#define pinstCTributeTrophyWnd_x                                   0x10CAEF0
#define pinstCVideoModesWnd_x                                      0xE6F664
#define pinstCVoiceMacroWnd_x                                      0xFB6F78
#define pinstCVoteResultsWnd_x                                     0xE6F6D8
#define pinstCVoteWnd_x                                            0xE6F6CC
#define pinstCWebManager_x                                         0xFB707C
#define pinstCZoneGuideWnd_x                                       0xE6F5B4
#define pinstCZonePathWnd_x                                        0xE6F5D0
#define pinstEQSuiteTextureLoader_x                                0xD17274
#define pinstItemIconCache_x                                       0x10C4EA0
#define pinstRewardSelectionWnd_x                                  0x10C9360

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC679E8
#define __CastRay_x                                                0x62C020
#define __CastRay2_x                                               0x62C070
#define __ConvertItemTags_x                                        0x6470B0
#define __CrashHandler_x                                           0x901D40
#define __EQGetTime_x                                              0x99D240
#define __ExecuteCmd_x                                             0x624800
#define __FixHeading_x                                             0xA2C7C0
#define __get_bearing_x                                            0x62BB60
#define __get_melee_range_x                                        0x62C2A0
#define __GetAnimationCache_x                                      0x7AF420
#define __GetGaugeValueFromEQ_x                                    0x8B2190
#define __GetLabelFromEQ_x                                         0x8B3920
#define __GetXTargetType_x                                         0xA2E230
#define __HeadingDiff_x                                            0xA2C830
#define __HelpPath_x                                               0xFB4ECC
#define __LoadFrontEnd_x                                           0x73F0F0
#define __NewUIINI_x                                               0x8B1E60
#define __pCrashHandler_x                                          0x10D7BA0
#define __ProcessGameEvents_x                                      0x68AA10
#define __ProcessMouseEvent_x                                      0x68A1E0
#define __STMLToText_x                                             0x9D0FC0
#define __ToggleKeyRingItem_x                                      0x594D90
#define CrashDetected_x                                            0x740D80
#define DrawNetStatus_x                                            0x6BA2F0
#define Expansion_HoT_x                                            0xF3170C
#define Teleport_Table_Size_x                                      0xF20974
#define Teleport_Table_x                                           0xF20F30
#define Util__FastTime_x                                           0x99CE30
#define wwsCrashReportCheckForUploader_x                           0x9027F0
#define wwsCrashReportPlatformLaunchUploader_x                     0x904E50

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x51EEF0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x527EF0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x527CD0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x5DC7B0
#define AltAdvManager__IsAbilityReady_x                            0x5DB820
#define AltAdvManager__GetAAById_x                                 0x5DBA20
#define AltAdvManager__CanTrainAbility_x                           0x5DBA90
#define AltAdvManager__CanSeeAbility_x                             0x5DBCC0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x55CEA0
#define CharacterZoneClient__HasSkill_x                            0x5686E0
#define CharacterZoneClient__MakeMeVisible_x                       0x569E30
#define CharacterZoneClient__IsStackBlocked_x                      0x550A30
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x54CFE0
#define CharacterZoneClient__GetItemCountWorn_x                    0x56C5C0
#define CharacterZoneClient__GetItemCountInInventory_x             0x56C6A0
#define CharacterZoneClient__GetCursorItemCount_x                  0x56C780
#define CharacterZoneClient__FindAffectSlot_x                      0x555760
#define CharacterZoneClient__BardCastBard_x                        0x558730
#define CharacterZoneClient__GetMaxEffects_x                       0x54D0B0
#define CharacterZoneClient__GetEffect_x                           0x54CF20
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x5567E0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x5568B0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x556900

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x76E180

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x77C660

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x699B60
#define CButtonWnd__CButtonWnd_x                                   0x9CD3A0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x79C900
#define CChatManager__InitContextMenu_x                            0x796CB0
#define CChatManager__FreeChatWindow_x                             0x79B820
#define CChatManager__GetLockedActiveChatWindow_x                  0x7A0500
#define CChatManager__SetLockedActiveChatWindow_x                  0x79C690

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x9E1A40
#define CContextMenu__dCContextMenu_x                              0x9E1C80
#define CContextMenu__AddMenuItem_x                                0x9E1C90
#define CContextMenu__RemoveMenuItem_x                             0x9E1F90
#define CContextMenu__RemoveAllMenuItems_x                         0x9E1FB0
#define CContextMenu__CheckMenuItem_x                              0x9E2030
#define CContextMenu__SetMenuItem_x                                0x9E1EB0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x9E2600
#define CContextMenuManager__RemoveMenu_x                          0x9E2670
#define CContextMenuManager__PopupMenu_x                           0x9E2730
#define CContextMenuManager__Flush_x                               0x9E25A0
#define CContextMenuManager__GetMenu_x                             0x529F00

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x980C70
#define CChatService__GetFriendName_x                              0x980C80

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x79CE90
#define CChatWindow__Clear_x                                       0x79DF60
#define CChatWindow__WndNotification_x                             0x79E4C0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x9DEFD0
#define CComboWnd__Draw_x                                          0x9DE490
#define CComboWnd__GetCurChoice_x                                  0x9DEE10
#define CComboWnd__GetListRect_x                                   0x9DE960
#define CComboWnd__GetTextRect_x                                   0x9DF040
#define CComboWnd__InsertChoice_x                                  0x9DEB00
#define CComboWnd__SetColors_x                                     0x9DEAD0
#define CComboWnd__SetChoice_x                                     0x9DEDE0
#define CComboWnd__GetItemCount_x                                  0x9DEE20
#define CComboWnd__GetCurChoiceText_x                              0x9DEE60

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x7A6F60
#define CContainerWnd__vftable_x                                   0xAE5738

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x5D3DA0
#define CDisplay__GetClickedActor_x                                0x5C6860
#define CDisplay__GetUserDefinedColor_x                            0x5BEC90
#define CDisplay__GetWorldFilePath_x                               0x5C82B0
#define CDisplay__is3dON_x                                         0x5C34B0
#define CDisplay__ReloadUI_x                                       0x5CD910
#define CDisplay__WriteTextHD2_x                                   0x5C3280
#define CDisplay__TrueDistance_x                                   0x5C9F10

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x9F7EC0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x9E5530
#define CEditWnd__GetCharIndexPt_x                                 0x9E64D0
#define CEditWnd__GetDisplayString_x                               0x9E6350
#define CEditWnd__GetHorzOffset_x                                  0x9E4B10
#define CEditWnd__GetLineForPrintableChar_x                        0x9E7630
#define CEditWnd__GetSelStartPt_x                                  0x9E67B0
#define CEditWnd__GetSTMLSafeText_x                                0x9E6160
#define CEditWnd__PointFromPrintableChar_x                         0x9E7250
#define CEditWnd__SelectableCharFromPoint_x                        0x9E73C0
#define CEditWnd__SetEditable_x                                    0x9E6880

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x679370
#define CEverQuest__ClickedPlayer_x                                0x66B5E0
#define CEverQuest__CreateTargetIndicator_x                        0x687CB0
#define CEverQuest__DeleteTargetIndicator_x                        0x687D40
#define CEverQuest__DoTellWindow_x                                 0x5791E0
#define CEverQuest__OutputTextToLog_x                              0x579440
#define CEverQuest__DropHeldItemOnGround_x                         0x6610C0
#define CEverQuest__dsp_chat_x                                     0x579830
#define CEverQuest__trimName_x                                     0x684250
#define CEverQuest__Emote_x                                        0x679B70
#define CEverQuest__EnterZone_x                                    0x673D10
#define CEverQuest__GetBodyTypeDesc_x                              0x67D9A0
#define CEverQuest__GetClassDesc_x                                 0x67DFA0
#define CEverQuest__GetClassThreeLetterCode_x                      0x67E5A0
#define CEverQuest__GetDeityDesc_x                                 0x686670
#define CEverQuest__GetLangDesc_x                                  0x67E760
#define CEverQuest__GetRaceDesc_x                                  0x67DF80
#define CEverQuest__InterpretCmd_x                                 0x686CA0
#define CEverQuest__LeftClickedOnPlayer_x                          0x665050
#define CEverQuest__LMouseUp_x                                     0x663370
#define CEverQuest__RightClickedOnPlayer_x                         0x665960
#define CEverQuest__RMouseUp_x                                     0x664380
#define CEverQuest__SetGameState_x                                 0x660E60
#define CEverQuest__UPCNotificationFlush_x                         0x684150
#define CEverQuest__IssuePetCommand_x                              0x67FB70
#define CEverQuest__ReportSuccessfulHit_x                          0x67A820

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7BAA70
#define CGaugeWnd__CalcLinesFillRect_x                             0x7BAAD0
#define CGaugeWnd__Draw_x                                          0x7BA0E0

// CGuild
#define CGuild__FindMemberByName_x                                 0x541800
#define CGuild__GetGuildName_x                                     0x540850
#define CGuild__GetGuildIndex_x                                    0x540BD0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x7D72C0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x7E4FD0
#define CInvSlotMgr__MoveItem_x                                    0x7E3B30
#define CInvSlotMgr__SelectSlot_x                                  0x7E50A0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7E2170
#define CInvSlot__SliderComplete_x                                 0x7DFC20
#define CInvSlot__GetItemBase_x                                    0x7DF5F0
#define CInvSlot__UpdateItem_x                                     0x7DF760

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7E68F0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7E5C10

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x8ADD80
#define CItemDisplayWnd__UpdateStrings_x                           0x7F5530
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x7EF010
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x7EF530
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x7F5890
#define CItemDisplayWnd__AboutToShow_x                             0x7F5170
#define CItemDisplayWnd__WndNotification_x                         0x7F6850

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8E87C0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x7FAC80

// CLabel 
#define CLabel__Draw_x                                             0x801040

// CListWnd
#define CListWnd__CListWnd_x                                       0x9B76A0
#define CListWnd__dCListWnd_x                                      0x9B79D0
#define CListWnd__AddColumn_x                                      0x9BBED0
#define CListWnd__AddColumn1_x                                     0x9BBF20
#define CListWnd__AddLine_x                                        0x9BC300
#define CListWnd__AddString_x                                      0x9BC0F0
#define CListWnd__CalculateFirstVisibleLine_x                      0x9BBC80
#define CListWnd__CalculateVSBRange_x                              0x9BBA40
#define CListWnd__ClearSel_x                                       0x9BCAD0
#define CListWnd__ClearAllSel_x                                    0x9BCB30
#define CListWnd__CloseAndUpdateEditWindow_x                       0x9BD560
#define CListWnd__Compare_x                                        0x9BB340
#define CListWnd__Draw_x                                           0x9B7AE0
#define CListWnd__DrawColumnSeparators_x                           0x9BA310
#define CListWnd__DrawHeader_x                                     0x9BA770
#define CListWnd__DrawItem_x                                       0x9BABC0
#define CListWnd__DrawLine_x                                       0x9BA470
#define CListWnd__DrawSeparator_x                                  0x9BA3B0
#define CListWnd__EnableLine_x                                     0x9B9BF0
#define CListWnd__EnsureVisible_x                                  0x9BD480
#define CListWnd__ExtendSel_x                                      0x9BCA00
#define CListWnd__GetColumnMinWidth_x                              0x9B9740
#define CListWnd__GetColumnWidth_x                                 0x9B96B0
#define CListWnd__GetCurSel_x                                      0x9B9010
#define CListWnd__GetItemAtPoint_x                                 0x9B9E60
#define CListWnd__GetItemAtPoint1_x                                0x9B9ED0
#define CListWnd__GetItemData_x                                    0x9B9090
#define CListWnd__GetItemHeight_x                                  0x9B9470
#define CListWnd__GetItemIcon_x                                    0x9B9230
#define CListWnd__GetItemRect_x                                    0x9B9CE0
#define CListWnd__GetItemText_x                                    0x9B90D0
#define CListWnd__GetSelList_x                                     0x9BCB80
#define CListWnd__GetSeparatorRect_x                               0x9BA110
#define CListWnd__InsertLine_x                                     0x9BC6E0
#define CListWnd__RemoveLine_x                                     0x9BC830
#define CListWnd__SetColors_x                                      0x9BBA10
#define CListWnd__SetColumnJustification_x                         0x9BB730
#define CListWnd__SetColumnWidth_x                                 0x9BB640
#define CListWnd__SetCurSel_x                                      0x9BC940
#define CListWnd__SetItemColor_x                                   0x9BD130
#define CListWnd__SetItemData_x                                    0x9BD0F0
#define CListWnd__SetItemText_x                                    0x9BCD00
#define CListWnd__ShiftColumnSeparator_x                           0x9BB7F0
#define CListWnd__Sort_x                                           0x9BB4E0
#define CListWnd__ToggleSel_x                                      0x9BC970

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x817C70

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x83C7B0
#define CMerchantWnd__RequestBuyItem_x                             0x83D050
#define CMerchantWnd__RequestSellItem_x                            0x83D580
#define CMerchantWnd__SelectRecoverySlot_x                         0x840720
//did this get another arg?
#define CMerchantWnd__SelectBuySellSlot_x                          0x83CDD0
#define CMerchantWnd__ActualSelect_x                               0x8463E0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x94D700
#define CPacketScrambler__hton_x                                   0x94D6F0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x9D6B40
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9D6930
#define CSidlManager__CreateLabel_x                                0x8A44B0
#define CSidlManager__CreateXWndFromTemplate_x                     0x9D9D10
#define CSidlManager__CreateXWndFromTemplate1_x                    0x9D9EF0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9D3120
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9D3010
#define CSidlScreenWnd__ConvertToRes_x                             0x9F7D80
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x9D2B00
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x9D27E0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x9D28B0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x9D2980
#define CSidlScreenWnd__DrawSidlPiece_x                            0x9D35C0
#define CSidlScreenWnd__EnableIniStorage_x                         0x9D3A90
#define CSidlScreenWnd__GetSidlPiece_x                             0x9D37B0
#define CSidlScreenWnd__Init1_x                                    0x9D23D0
#define CSidlScreenWnd__LoadIniInfo_x                              0x9D3AE0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9D4620
#define CSidlScreenWnd__LoadSidlScreen_x                           0x9D17E0
#define CSidlScreenWnd__StoreIniInfo_x                             0x9D41A0
#define CSidlScreenWnd__StoreIniVis_x                              0x9D4500
#define CSidlScreenWnd__WndNotification_x                          0x9D34D0
#define CSidlScreenWnd__GetChildItem_x                             0x9D3A10
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9C31A0
#define CSidlScreenWnd__m_layoutCopy_x                             0x1730FB8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x7052E0
#define CSkillMgr__GetSkillCap_x                                   0x7054C0
#define CSkillMgr__GetNameToken_x                                  0x704A60

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9F7450
#define CSliderWnd__SetValue_x                                     0x9F72C0
#define CSliderWnd__SetNumTicks_x                                  0x9F7320

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x8AAB60

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x9E9580
#define CStmlWnd__CalculateHSBRange_x                              0x9EA6D0
#define CStmlWnd__CalculateVSBRange_x                              0x9EA640
#define CStmlWnd__CanBreakAtCharacter_x                            0x9EF5D0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x9F0180
#define CStmlWnd__ForceParseNow_x                                  0x9E9B80
#define CStmlWnd__GetNextTagPiece_x                                0x9EF530
#define CStmlWnd__GetSTMLText_x                                    0x588340
#define CStmlWnd__GetVisibleText_x                                 0x9E9BA0
#define CStmlWnd__InitializeWindowVariables_x                      0x9EFFD0
#define CStmlWnd__MakeStmlColorTag_x                               0x9E8CA0
#define CStmlWnd__MakeWndNotificationTag_x                         0x9E8D10
#define CStmlWnd__SetSTMLText_x                                    0x9E7D30
#define CStmlWnd__StripFirstSTMLLines_x                            0x9F1430
#define CStmlWnd__UpdateHistoryString_x                            0x9F0390

// CTabWnd 
#define CTabWnd__Draw_x                                            0x9F4610
#define CTabWnd__DrawCurrentPage_x                                 0x9F4C60
#define CTabWnd__DrawTab_x                                         0x9F4A10
#define CTabWnd__GetCurrentPage_x                                  0x9F3E70
#define CTabWnd__GetPageInnerRect_x                                0x9F40B0
#define CTabWnd__GetTabInnerRect_x                                 0x9F3FF0
#define CTabWnd__GetTabRect_x                                      0x9F3EA0
#define CTabWnd__InsertPage_x                                      0x9F42A0
#define CTabWnd__SetPage_x                                         0x9F4130
#define CTabWnd__SetPageRect_x                                     0x9F4550
#define CTabWnd__UpdatePage_x                                      0x9F48D0
#define CTabWnd__GetPageFromTabIndex_x                             0x9F4950
#define CTabWnd__GetCurrentTabIndex_x                              0x9F3E60

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x7FB210
#define CPageWnd__SetTabText_x                                     0xA01280

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x53AC00

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x9BFFE0
#define CTextureFont__GetTextExtent_x                              0x9C01C0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x73B6C0
#define CHtmlComponentWnd__ValidateUri_x                           0x7D8B80
#define CHtmlWnd__SetClientCallbacks_x                             0x69E760
#define CHtmlWnd__AddObserver_x                                    0x69E780
#define CHtmlWnd__RemoveObserver_x                                 0x69E7E0
#define Window__getProgress_x                                      0x8FF710
#define Window__getStatus_x                                        0x8FF730
#define Window__getURI_x                                           0x8FF740

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9FD9F0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x9ACEF0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x506370
#define CXStr__CXStr1_x                                            0x9B5930
#define CXStr__CXStr3_x                                            0x999390
#define CXStr__dCXStr_x                                            0x9FC130
#define CXStr__operator_equal_x                                    0x9995C0
#define CXStr__operator_equal1_x                                   0x999600
#define CXStr__operator_plus_equal1_x                              0x99A090

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x9E1680
#define CXWnd__BringToTop_x                                        0x9C6A50
#define CXWnd__Center_x                                            0x9C65D0

#define CXWnd__ClrFocus_x                                          0x9C6400
#define CXWnd__Destroy_x                                           0x9C64B0
#define CXWnd__DoAllDrawing_x                                      0x9C2930
#define CXWnd__DrawChildren_x                                      0x9C2900
#define CXWnd__DrawColoredRect_x                                   0x9C2D90
#define CXWnd__DrawTooltip_x                                       0x9C1400
#define CXWnd__DrawTooltipAtPoint_x                                0x9C14D0
#define CXWnd__GetBorderFrame_x                                    0x9C2BF0
#define CXWnd__GetChildWndAt_x                                     0x9C6AF0
#define CXWnd__GetClientClipRect_x                                 0x9C4D60
#define CXWnd__GetScreenClipRect_x                                 0x9C4E30
#define CXWnd__GetScreenRect_x                                     0x9C4FF0
#define CXWnd__GetTooltipRect_x                                    0x9C2DE0
#define CXWnd__GetWindowTextA_x                                    0x52B930
#define CXWnd__IsActive_x                                          0x9C9930
#define CXWnd__IsDescendantOf_x                                    0x9C59D0
#define CXWnd__IsReallyVisible_x                                   0x9C5A00
#define CXWnd__IsType_x                                            0x9C7160
#define CScreenPieceTemplate__IsType_x                             0x9F8E50
#define CXWnd__Move_x                                              0x9C5A60
#define CXWnd__Move1_x                                             0x9C5B10
#define CXWnd__ProcessTransition_x                                 0x9C6580
#define CXWnd__Refade_x                                            0x9C5DD0
#define CXWnd__Resize_x                                            0x9C6020
#define CXWnd__Right_x                                             0x9C6810
#define CXWnd__SetFocus_x                                          0x9C63C0
#define CXWnd__SetFont_x                                           0x9C6430
#define CXWnd__SetKeyTooltip_x                                     0x9C6F70
#define CXWnd__SetMouseOver_x                                      0x9C3D00
#define CXWnd__StartFade_x                                         0x9C58B0
#define CXWnd__GetChildItem_x                                      0x9C6C60
#define CXWnd__SetParent_x                                         0x9C5780

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9C9970
#define CXWndManager__DrawWindows_x                                0x9C9990
#define CXWndManager__GetKeyboardFlags_x                           0x9CC170
#define CXWndManager__HandleKeyboardMsg_x                          0x9CBD70
#define CXWndManager__RemoveWnd_x                                  0x9CC3C0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x9CC900

// CDBStr
#define CDBStr__GetString_x                                        0x5BDB10

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x54DF50
#define EQ_Character__Cur_HP_x                                     0x5655F0
#define EQ_Character__Cur_Mana_x                                   0x56CBF0
#define EQ_Character__GetAACastingTimeModifier_x                   0x551000
#define EQ_Character__GetFocusCastingTimeModifier_x                0x544720
#define EQ_Character__GetFocusRangeModifier_x                      0x544890
#define EQ_Character__GetHPRegen_x                                 0x572510
#define EQ_Character__GetEnduranceRegen_x                          0x572B50
#define EQ_Character__GetManaRegen_x                               0x572FA0
#define EQ_Character__Max_Endurance_x                              0x6C80C0
#define EQ_Character__Max_HP_x                                     0x565420
#define EQ_Character__Max_Mana_x                                   0x6C7F40
#define EQ_Character__doCombatAbility_x                            0x6CAAF0
#define EQ_Character__UseSkill_x                                   0x574EE0
#define EQ_Character__GetConLevel_x                                0x6C1610
#define EQ_Character__IsExpansionFlag_x                            0x5BDA30
#define EQ_Character__TotalEffect_x                                0x557CB0
#define EQ_Character__GetPCSpellAffect_x                           0x551C20
#define EQ_Character__SpellDuration_x                              0x551730
#define EQ_Character__FindItemByRecord_x                           0x56AE40
#define EQ_Character__GetAdjustedSkill_x                           0x5684A0
#define EQ_Character__GetBaseSkill_x                               0x569440
#define EQ_Character__CanUseItem_x                                 0x56CF20

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x96C370

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x6DF010

//PcClient
#define PcClient__PcClient_x                                       0x6BEF20

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x54BA50
#define CCharacterListWnd__EnterWorld_x                            0x54B470
#define CCharacterListWnd__Quit_x                                  0x54B180
#define CCharacterListWnd__UpdateList_x                            0x54B610

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x69FB30
#define EQ_Item__CreateItemTagString_x                             0x947740
#define EQ_Item__IsStackable_x                                     0x94BAE0
#define EQ_Item__GetImageNum_x                                     0x948F80
#define EQ_Item__CreateItemClient_x                                0x69ED90
#define EQ_Item__GetItemValue_x                                    0x94A030
#define EQ_Item__ValueSellMerchant_x                               0x94D2E0
#define EQ_Item__IsKeyRingItem_x                                   0x94B420
#define EQ_Item__CanGoInBag_x                                      0x69FC50
#define EQ_Item__GetMaxItemCount_x                                 0x94A130
#define EQ_Item__GetHeldItem_x                                     0x948D90
#define EQ_Item__GetAugmentFitBySlot_x                             0x947270

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x5DD6B0
#define EQ_LoadingS__Array_x                                       0xC0B240

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x6C8A60
#define EQ_PC__GetAlternateAbilityId_x                             0x9562C0
#define EQ_PC__GetCombatAbility_x                                  0x956940
#define EQ_PC__GetCombatAbilityTimer_x                             0x9569B0
#define EQ_PC__GetItemRecastTimer_x                                0x6CB080
#define EQ_PC__HasLoreItem_x                                       0x6C1D90
#define EQ_PC__AlertInventoryChanged_x                             0x6C1100
#define EQ_PC__GetPcZoneClient_x                                   0x6EE050
#define EQ_PC__RemoveMyAffect_x                                    0x6CE430
#define EQ_PC__GetKeyRingItems_x                                   0x957250
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x956FD0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x957540

// EQItemList 
#define EQItemList__EQItemList_x                                   0x6293E0
#define EQItemList__add_object_x                                   0x656170
#define EQItemList__add_item_x                                     0x6299D0
#define EQItemList__delete_item_x                                  0x629A20
#define EQItemList__FreeItemList_x                                 0x629920

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x5BB080

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x6E08A0
#define EQPlayer__dEQPlayer_x                                      0x6D3E10
#define EQPlayer__DoAttack_x                                       0x6E8A30
#define EQPlayer__EQPlayer_x                                       0x6D4510
#define EQPlayer__SetNameSpriteState_x                             0x6D8750
#define EQPlayer__SetNameSpriteTint_x                              0x6D95E0
#define PlayerBase__HasProperty_j_x                                0xA2AA90
#define EQPlayer__IsTargetable_x                                   0xA2AFB0
#define EQPlayer__CanSee_x                                         0xA2ADD0
#define PlayerZoneClient__ChangeHeight_x                           0x6EBAD0
#define EQPlayer__CanSee1_x                                        0xA2AEC0
#define PlayerBase__GetVisibilityLineSegment_x                     0xA2AB50

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x6EE090
#define PlayerZoneClient__IsValidTeleport_x                        0x6574A0
#define PlayerZoneClient__LegalPlayerRace_x                        0x5D5DC0


//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x6E3770
#define EQPlayerManager__GetSpawnByName_x                          0x6E3790
#define EQPlayerManager__GetPlayerFromPartialName_x                0x6E3820

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x6A3B40
#define KeypressHandler__AttachKeyToEqCommand_x                    0x6A3B80
#define KeypressHandler__ClearCommandStateArray_x                  0x6A4F80
#define KeypressHandler__HandleKeyDown_x                           0x6A4FA0
#define KeypressHandler__HandleKeyUp_x                             0x6A5040
#define KeypressHandler__SaveKeymapping_x                          0x6A54D0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x8137C0
#define MapViewMap__SaveEx_x                                       0x816DF0
#define MapViewMap__SetZoom_x                                      0x81BC10

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x96A2D0

// StringTable 
#define StringTable__getString_x                                   0x9651E0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x6CE090
#define PcZoneClient__RemovePetEffect_x                            0x6CE6D0
#define PcZoneClient__HasAlternateAbility_x                        0x6C7D50
#define PcZoneClient__GetCurrentMod_x                              0x577DE0
#define PcZoneClient__GetModCap_x                                  0x577CE0
#define PcZoneClient__CanEquipItem_x                               0x6C8350
#define PcZoneClient__GetItemByID_x                                0x6CB5A0
#define PcZoneClient__GetItemByItemClass_x                         0x6CB630
#define PcZoneClient__RemoveBuffEffect_x                           0x6CE6F0

//Doors
#define EQSwitch__UseSwitch_x                                      0x65C160

//IconCache
#define IconCache__GetIcon_x                                       0x7AEC90

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x7A5EE0
#define CContainerMgr__CloseContainer_x                            0x7A61D0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x874390

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x698120

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x5F7730
#define EQ_Spell__SpellAffects_x                                   0x5F7BC0
#define EQ_Spell__SpellAffectBase_x                                0x5F7960
#define CharacterZoneClient__CalcAffectChange_x                    0x556A50
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x556C20
#define CLootWnd__LootAll_x                                        0x8091C0
#define CLootWnd__RequestLootSlot_x                                0x8084E0
#define EQ_Spell__IsStackable_x                                    0x55C530
#define EQ_Spell__GetSpellAffectBySlot_x                           0x55C2A0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x548EE0
#define EQ_Spell__IsSPAStacking_x                                  0x556113
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x5F7F20
#define EQ_Spell__IsNoRemove_x                                     0x53A950
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x5F87C0

#define __IsResEffectSpell_x                                       0x55BA40

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x53F180

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x976160

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x8BDAC0
#define CTargetWnd__WndNotification_x                              0x8BD340
#define CTargetWnd__RefreshTargetBuffs_x                           0x8BD610
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x8BC3A0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x8C27F0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5F2700
#define EqSoundManager__PlayScriptMp3_x                            0x5F2810

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x5AC030

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x9E4210
#define CSidlManager__FindAnimation1_x                             0x9D6730

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x5E60B0
#define CAltAbilityData__GetMercMaxRank_x                          0x5E6050
#define CAltAbilityData__GetMaxRank_x                              0x5DA580

//CTargetRing
#define CTargetRing__Cast_x                                        0x6959E0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x55C250
#define CharacterBase__CreateItemGlobalIndex_x                     0x578520
#define CharacterBase__CreateItemIndex_x                           0x622EA0
#define CharacterBase__GetItemPossession_x                         0x548D30
#define CharacterBase__GetItemByGlobalIndex_x                      0x97E7B0
#define CharacterBase__GetEffectId_x                               0x55C1D0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x78D640
#define CCastSpellWnd__IsBardSongPlaying_x                         0x78DE60

//messages
#define msg_spell_worn_off_x                                       0x61C0B0
#define msg_new_text_x                                             0x610DD0
#define __msgTokenTextParam_x                                      0x61E9E0
#define msgTokenText_x                                             0x61E9E0

//SpellManager
#define SpellManager__vftable_x                                    0xAC1260
#define SpellManager__SpellManager_x                               0x580DD0
#define Spellmanager__LoadTextSpells_x                             0x70C7E0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0xA2EBA0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x591B10
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5487C0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x55C4F0
#define ItemGlobalIndex__IsValidIndex_x                            0x55C630

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x976A80
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x976D10

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x8013B0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x7AAB80
#define CCursorAttachment__Deactivate_x                            0x7ABB40

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9F6A10
#define CEQSuiteTextureLoader__GetTexture_x                        0x9F66A0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x58E660

//IString
#define IString__Append_x                                          0x581AE0

//Camera
#define CDisplay__cameraType_x                                     0xE6EEB8
#define EverQuest__Cameras_x                                       0xF31A24

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x597140
#define pinstLootFiltersManager_x                                  0xD3D2A8
#define LootFiltersManager__GetItemFilterData_x                    0x596A10
#define LootFiltersManager__RemoveItemLootFilter_x                 0x596A40
#define LootFiltersManager__SetItemLootFilter_x                    0x596C70
