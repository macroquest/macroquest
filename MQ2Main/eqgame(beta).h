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
#define __ExpectedVersionDate                                     "Nov  3 2020"
#define __ExpectedVersionTime                                     "04:20:17"
#define __ActualVersionDate_x                                      0xAF555C
#define __ActualVersionTime_x                                      0xAF5550
#define __ActualVersionBuild_x                                     0xAE355C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x642E10
#define __MemChecker1_x                                            0x8F5A40
#define __MemChecker2_x                                            0x6B3580
#define __MemChecker3_x                                            0x6B34D0
#define __MemChecker4_x                                            0x84C2B0
#define __EncryptPad0_x                                            0xC2A9D0
#define __EncryptPad1_x                                            0xC88218
#define __EncryptPad2_x                                            0xC3AD98
#define __EncryptPad3_x                                            0xC3A998
#define __EncryptPad4_x                                            0xC787A8
#define __EncryptPad5_x                                            0xF4A658
#define __AC1_x                                                    0x80AE46
#define __AC2_x                                                    0x5FC4CF
#define __AC3_x                                                    0x603B20
#define __AC4_x                                                    0x607AD0
#define __AC5_x                                                    0x60DDCF
#define __AC6_x                                                    0x612286
#define __AC7_x                                                    0x5FBF40
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x190448

// Direct Input
#define DI8__Main_x                                                0xF4A678
#define DI8__Keyboard_x                                            0xF4A67C
#define DI8__Mouse_x                                               0xF4A690
#define DI8__Mouse_Copy_x                                          0xEA39EC
#define DI8__Mouse_Check_x                                         0xF481AC
#define __AutoSkillArray_x                                         0xEA4908
#define __Attack_x                                                 0xF4272F
#define __Autofire_x                                               0xF42730
#define __BindList_x                                               0xC19400
#define g_eqCommandStates_x                                        0xC1A180
#define __Clicks_x                                                 0xEA3AA4
#define __CommandList_x                                            0xC1AD40
#define __CurrentMapLabel_x                                        0xF5B154
#define __CurrentSocial_x                                          0xC027C8
#define __DoAbilityList_x                                          0xEDA250
#define __do_loot_x                                                0x5C7FB0
#define __DrawHandler_x                                            0x15DA148
#define __GroupCount_x                                             0xE9EA7A
#define __Guilds_x                                                 0xEA2928
#define __gWorld_x                                                 0xE9E920
#define __HWnd_x                                                   0xF4A694
#define __heqmain_x                                                0xF4A640
#define __InChatMode_x                                             0xEA39D4
#define __LastTell_x                                               0xEA594C
#define __LMouseHeldTime_x                                         0xEA3B10
#define __Mouse_x                                                  0xF4A664
#define __MouseLook_x                                              0xEA3A6A
#define __MouseEventTime_x                                         0xF43214
#define __gpbCommandEvent_x                                        0xE9C3C8
#define __NetStatusToggle_x                                        0xEA3A6D
#define __PCNames_x                                                0xEA4EF8
#define __RangeAttackReady_x                                       0xEA4BEC
#define __RMouseHeldTime_x                                         0xEA3B0C
#define __RunWalkState_x                                           0xEA39D8
#define __ScreenMode_x                                             0xDEA1E8
#define __ScreenX_x                                                0xEA398C
#define __ScreenY_x                                                0xEA3988
#define __ScreenXMax_x                                             0xEA3990
#define __ScreenYMax_x                                             0xEA3994
#define __ServerHost_x                                             0xE9C593
#define __ServerName_x                                             0xEDA210
#define __ShiftKeyDown_x                                           0xEA4068
#define __ShowNames_x                                              0xEA4DA8
#define EverQuestInfo__bSocialChanged_x                            0xEDA298
#define __Socials_x                                                0xEDA310
#define __SubscriptionType_x                                       0xF9F418
#define __TargetAggroHolder_x                                      0xF5DB08
#define __ZoneType_x                                               0xEA3E68
#define __GroupAggro_x                                             0xF5DB48
#define __LoginName_x                                              0xF4ADD4
#define __Inviter_x                                                0xF426AC
#define __AttackOnAssist_x                                         0xEA4D64
#define __UseTellWindows_x                                         0xEA5090
#define __gfMaxZoomCameraDistance_x                                0xAED178
#define __gfMaxCameraDistance_x                                    0xB15DF8
#define __pulAutoRun_x                                             0xEA3A88
#define __pulForward_x                                             0xEA50C8
#define __pulBackward_x                                            0xEA50CC
#define __pulTurnRight_x                                           0xEA50D0
#define __pulTurnLeft_x                                            0xEA50D4
#define __pulStrafeLeft_x                                          0xEA50D8
#define __pulStrafeRight_x                                         0xEA50DC

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE9ECC0
#define instEQZoneInfo_x                                           0xEA3C60
#define pinstActiveBanker_x                                        0xE9C8B4
#define pinstActiveCorpse_x                                        0xE9C8AC
#define pinstActiveGMaster_x                                       0xE9C8B0
#define pinstActiveMerchant_x                                      0xE9C8A8
#define pinstAltAdvManager_x                                       0xDEAEF0
#define pinstBandageTarget_x                                       0xE9C8C4
#define pinstCamActor_x                                            0xDEA1DC
#define pinstCDBStr_x                                              0xDE9C0C
#define pinstCDisplay_x                                            0xE9C914
#define pinstCEverQuest_x                                          0xF4A698
#define pinstEverQuestInfo_x                                       0xEA3980
#define pinstCharData_x                                            0xE9C3B0
#define pinstCharSpawn_x                                           0xE9C8FC
#define pinstControlledMissile_x                                   0xE9C90C
#define pinstControlledPlayer_x                                    0xE9C8FC
#define pinstCResolutionHandler_x                                  0x15DA378
#define pinstCSidlManager_x                                        0x15D9310
#define pinstCXWndManager_x                                        0x15D930C
#define instDynamicZone_x                                          0xEA2800
#define pinstDZMember_x                                            0xEA2910
#define pinstDZTimerInfo_x                                         0xEA2914
#define pinstEqLogin_x                                             0xF4A720
#define instEQMisc_x                                               0xDE9B50
#define pinstEQSoundManager_x                                      0xDEBEC0
#define pinstEQSpellStrings_x                                      0xCAC458
#define instExpeditionLeader_x                                     0xEA284A
#define instExpeditionName_x                                       0xEA288A
#define pinstGroup_x                                               0xE9EA76
#define pinstImeManager_x                                          0x15D9308
#define pinstLocalPlayer_x                                         0xE9C8A4
#define pinstMercenaryData_x                                       0xF44D08
#define pinstMercenaryStats_x                                      0xF5DBD4
#define pinstModelPlayer_x                                         0xE9C8BC
#define pinstPCData_x                                              0xE9C3B0
#define pinstSkillMgr_x                                            0xF46E70
#define pinstSpawnManager_x                                        0xF45918
#define pinstSpellManager_x                                        0xF470B0
#define pinstSpellSets_x                                           0xF3B358
#define pinstStringTable_x                                         0xE9C3BC
#define pinstSwitchManager_x                                       0xE9C260
#define pinstTarget_x                                              0xE9C8F8
#define pinstTargetObject_x                                        0xE9C904
#define pinstTargetSwitch_x                                        0xE9E918
#define pinstTaskMember_x                                          0xDE99E0
#define pinstTrackTarget_x                                         0xE9C900
#define pinstTradeTarget_x                                         0xE9C8B8
#define instTributeActive_x                                        0xDE9B71
#define pinstViewActor_x                                           0xDEA1D8
#define pinstWorldData_x                                           0xE9C3B8
#define pinstZoneAddr_x                                            0xEA3F00
#define pinstPlayerPath_x                                          0xF459B0
#define pinstTargetIndicator_x                                     0xF47318
#define EQObject_Top_x                                             0xE9C69C
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDEA50C
#define pinstCAchievementsWnd_x                                    0xDEA180
#define pinstCActionsWnd_x                                         0xDE9CA8
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDEA240
#define pinstCAdvancedLootWnd_x                                    0xDEA1F4
#define pinstCAdventureLeaderboardWnd_x                            0xF54928
#define pinstCAdventureRequestWnd_x                                0xF549D8
#define pinstCAdventureStatsWnd_x                                  0xF54A88
#define pinstCAggroMeterWnd_x                                      0xDEA228
#define pinstCAlarmWnd_x                                           0xDEA1A8
#define pinstCAlertHistoryWnd_x                                    0xDEA4C0
#define pinstCAlertStackWnd_x                                      0xDEA210
#define pinstCAlertWnd_x                                           0xDEA224
#define pinstCAltStorageWnd_x                                      0xF54DE8
#define pinstCAudioTriggersWindow_x                                0xC9E788
#define pinstCAuraWnd_x                                            0xDEA1F8
#define pinstCAvaZoneWnd_x                                         0xDEA4BC
#define pinstCBandolierWnd_x                                       0xDEA23C
#define pinstCBankWnd_x                                            0xDEA27C
#define pinstCBarterMerchantWnd_x                                  0xF56028
#define pinstCBarterSearchWnd_x                                    0xF560D8
#define pinstCBarterWnd_x                                          0xF56188
#define pinstCBazaarConfirmationWnd_x                              0xDEA1C0
#define pinstCBazaarSearchWnd_x                                    0xDEA510
#define pinstCBazaarWnd_x                                          0xDEA18C
#define pinstCBlockedBuffWnd_x                                     0xDEA204
#define pinstCBlockedPetBuffWnd_x                                  0xDEA22C
#define pinstCBodyTintWnd_x                                        0xDEA134
#define pinstCBookWnd_x                                            0xDEA274
#define pinstCBreathWnd_x                                          0xDEA520
#define pinstCBuffWindowNORMAL_x                                   0xDEA1D0
#define pinstCBuffWindowSHORT_x                                    0xDEA1D4
#define pinstCBugReportWnd_x                                       0xDEA278
#define pinstCButtonWnd_x                                          0x15D9578
#define pinstCCastingWnd_x                                         0xDEA25C
#define pinstCCastSpellWnd_x                                       0xDEA51C
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDEA140
#define pinstCChatWindowManager_x                                  0xF56C48
#define pinstCClaimWnd_x                                           0xF56DA0
#define pinstCColorPickerWnd_x                                     0xDEA4D4
#define pinstCCombatAbilityWnd_x                                   0xDEA19C
#define pinstCCombatSkillsSelectWnd_x                              0xDEA154
#define pinstCCompassWnd_x                                         0xDE9CBC
#define pinstCConfirmationDialog_x                                 0xF5BCA0
#define pinstCContainerMgr_x                                       0xDEA130
#define pinstCContextMenuManager_x                                 0x15D92C8
#define pinstCCursorAttachment_x                                   0xDEA250
#define pinstCDynamicZoneWnd_x                                     0xF57368
#define pinstCEditLabelWnd_x                                       0xDEA1CC
#define pinstCEQMainWnd_x                                          0xF575B0
#define pinstCEventCalendarWnd_x                                   0xDEA514
#define pinstCExtendedTargetWnd_x                                  0xDEA20C
#define pinstCFacePick_x                                           0xDEA158
#define pinstCFactionWnd_x                                         0xDEA178
#define pinstCFellowshipWnd_x                                      0xF577B0
#define pinstCFileSelectionWnd_x                                   0xDEA4D0
#define pinstCFindItemWnd_x                                        0xDEA168
#define pinstCFindLocationWnd_x                                    0xF57908
#define pinstCFriendsWnd_x                                         0xDEA16C
#define pinstCGemsGameWnd_x                                        0xDEA174
#define pinstCGiveWnd_x                                            0xDEA1AC
#define pinstCGroupSearchFiltersWnd_x                              0xDEA244
#define pinstCGroupSearchWnd_x                                     0xF57D00
#define pinstCGroupWnd_x                                           0xF57DB0
#define pinstCGuildBankWnd_x                                       0xEA4D48
#define pinstCGuildCreationWnd_x                                   0xF57F10
#define pinstCGuildMgmtWnd_x                                       0xF57FC0
#define pinstCharacterCreation_x                                   0xDEA160
#define pinstCHelpWnd_x                                            0xDEA1B0
#define pinstCHeritageSelectionWnd_x                               0xDEA164
#define pinstCHotButtonWnd_x                                       0xF5A118
#define pinstCHotButtonWnd1_x                                      0xF5A118
#define pinstCHotButtonWnd2_x                                      0xF5A11C
#define pinstCHotButtonWnd3_x                                      0xF5A120
#define pinstCHotButtonWnd4_x                                      0xF5A124
#define pinstCIconSelectionWnd_x                                   0xDEA24C
#define pinstCInspectWnd_x                                         0xDEA230
#define pinstCInventoryWnd_x                                       0xDEA1FC
#define pinstCInvSlotMgr_x                                         0xDEA500
#define pinstCItemDisplayManager_x                                 0xF5A6A8
#define pinstCItemExpTransferWnd_x                                 0xF5A7DC
#define pinstCItemOverflowWnd_x                                    0xDEA518
#define pinstCJournalCatWnd_x                                      0xDEA4EC
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDEA4AC
#define pinstCKeyRingWnd_x                                         0xDEA258
#define pinstCLargeDialogWnd_x                                     0xF5C920
#define pinstCLayoutCopyWnd_x                                      0xF5AB28
#define pinstCLFGuildWnd_x                                         0xF5ABD8
#define pinstCLoadskinWnd_x                                        0xDEA190
#define pinstCLootFiltersCopyWnd_x                                 0xCBAEE8
#define pinstCLootFiltersWnd_x                                     0xDEA214
#define pinstCLootSettingsWnd_x                                    0xDEA238
#define pinstCLootWnd_x                                            0xDEA4F0
#define pinstCMailAddressBookWnd_x                                 0xDEA504
#define pinstCMailCompositionWnd_x                                 0xDEA4DC
#define pinstCMailIgnoreListWnd_x                                  0xDEA508
#define pinstCMailWnd_x                                            0xDEA4E0
#define pinstCManageLootWnd_x                                      0xDEB3A0
#define pinstCMapToolbarWnd_x                                      0xDEA1B8
#define pinstCMapViewWnd_x                                         0xDEA184
#define pinstCMarketplaceWnd_x                                     0xDEA218
#define pinstCMerchantWnd_x                                        0xDEA4FC
#define pinstCMIZoneSelectWnd_x                                    0xF5B410
#define pinstCMusicPlayerWnd_x                                     0xDEA4C8
#define pinstCNameChangeMercWnd_x                                  0xDEA1B4
#define pinstCNameChangePetWnd_x                                   0xDEA188
#define pinstCNameChangeWnd_x                                      0xDEA1C8
#define pinstCNoteWnd_x                                            0xDEA194
#define pinstCObjectPreviewWnd_x                                   0xDEA234
#define pinstCOptionsWnd_x                                         0xDEA1A0
#define pinstCPetInfoWnd_x                                         0xDEA4C4
#define pinstCPetitionQWnd_x                                       0xDEA150
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDEA138
#define pinstCPlayerWnd_x                                          0xDEA4B8
#define pinstCPopupWndManager_x                                    0xF5BCA0
#define pinstCProgressionSelectionWnd_x                            0xF5BD50
#define pinstCPurchaseGroupWnd_x                                   0xDEA288
#define pinstCPurchaseWnd_x                                        0xDEA260
#define pinstCPvPLeaderboardWnd_x                                  0xF5BE00
#define pinstCPvPStatsWnd_x                                        0xF5BEB0
#define pinstCQuantityWnd_x                                        0xDEA4A8
#define pinstCRaceChangeWnd_x                                      0xDEA200
#define pinstCRaidOptionsWnd_x                                     0xDEA248
#define pinstCRaidWnd_x                                            0xDEA4F8
#define pinstCRealEstateItemsWnd_x                                 0xDEA17C
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDE9D24
#define pinstCRealEstateManageWnd_x                                0xDEA290
#define pinstCRealEstateNeighborhoodWnd_x                          0xDEA4B4
#define pinstCRealEstatePlotSearchWnd_x                            0xDEA4CC
#define pinstCRealEstatePurchaseWnd_x                              0xDEA4E8
#define pinstCRespawnWnd_x                                         0xDEA220
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDEA14C
#define pinstCSendMoneyWnd_x                                       0xDEA1C4
#define pinstCServerListWnd_x                                      0xDEA4F4
#define pinstCSkillsSelectWnd_x                                    0xDEA148
#define pinstCSkillsWnd_x                                          0xDE9D28
#define pinstCSocialEditWnd_x                                      0xDEA254
#define pinstCSocialWnd_x                                          0xDEA1A4
#define pinstCSpellBookWnd_x                                       0xDEA198
#define pinstCStoryWnd_x                                           0xDEA544
#define pinstCTargetOfTargetWnd_x                                  0xF5DC58
#define pinstCTargetWnd_x                                          0xDEA21C
#define pinstCTaskOverlayWnd_x                                     0xDEA280
#define pinstCTaskSelectWnd_x                                      0xF5DDB0
#define pinstCTaskManager_x                                        0xCBB828
#define pinstCTaskTemplateSelectWnd_x                              0xF5DE60
#define pinstCTaskWnd_x                                            0xF5DF10
#define pinstCTextEntryWnd_x                                       0xDEA270
#define pinstCTimeLeftWnd_x                                        0xDEA144
#define pinstCTipWndCONTEXT_x                                      0xF5E114
#define pinstCTipWndOFDAY_x                                        0xF5E110
#define pinstCTitleWnd_x                                           0xF5E1C0
#define pinstCTrackingWnd_x                                        0xDEA208
#define pinstCTradeskillWnd_x                                      0xF5E328
#define pinstCTradeWnd_x                                           0xDEA13C
#define pinstCTrainWnd_x                                           0xDEA4E4
#define pinstCTributeBenefitWnd_x                                  0xF5E528
#define pinstCTributeMasterWnd_x                                   0xF5E5D8
#define pinstCTributeTrophyWnd_x                                   0xF5E688
#define pinstCVideoModesWnd_x                                      0xDEA298
#define pinstCVoiceMacroWnd_x                                      0xF478D0
#define pinstCVoteResultsWnd_x                                     0xDEA170
#define pinstCVoteWnd_x                                            0xDEA15C
#define pinstCWebManager_x                                         0xF47F4C
#define pinstCZoneGuideWnd_x                                       0xDEA284
#define pinstCZonePathWnd_x                                        0xDEA2A4

#define pinstEQSuiteTextureLoader_x                                0xC88B38
#define pinstItemIconCache_x                                       0xF57568
#define pinstLootFiltersManager_x                                  0xCBAF98
#define pinstRewardSelectionWnd_x                                  0xF5C5F8

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5C36A0
#define __CastRay2_x                                               0x5C36F0
#define __ConvertItemTags_x                                        0x5DF3B0
#define __CleanItemTags_x                                          0x47D280
#define __DoesFileExist_x                                          0x8F8A70
#define __EQGetTime_x                                              0x8F5670
#define __ExecuteCmd_x                                             0x5BBFC0
#define __FixHeading_x                                             0x98AF50
#define __FlushDxKeyboard_x                                        0x6AF420
#define __GameLoop_x                                               0x6B2750
#define __get_bearing_x                                            0x5C3200
#define __get_melee_range_x                                        0x5C38E0
#define __GetAnimationCache_x                                      0x717B20
#define __GetGaugeValueFromEQ_x                                    0x8092F0
#define __GetLabelFromEQ_x                                         0x80ADD0
#define __GetXTargetType_x                                         0x98C9A0
#define __HandleMouseWheel_x                                       0x6B3630
#define __HeadingDiff_x                                            0x98AFC0
#define __HelpPath_x                                               0xF42E04
#define __LoadFrontEnd_x                                           0x6AFA60
#define __NewUIINI_x                                               0x808FC0
#define __ProcessGameEvents_x                                      0x624160
#define __ProcessMouseEvent_x                                      0x6238F0
#define __SaveColors_x                                             0x55CFA0
#define __STMLToText_x                                             0x92E4F0
#define __ToggleKeyRingItem_x                                      0x51B710
#define CMemoryMappedFile__SetFile_x                               0xA7A350
#define CrashDetected_x                                            0x6B1510
#define DrawNetStatus_x                                            0x650240
#define Expansion_HoT_x                                            0xEA4D50
#define Teleport_Table_Size_x                                      0xE9C450
#define Teleport_Table_x                                           0xE9C918
#define Util__FastTime_x                                           0x8F5240
#define __CopyLayout_x                                             0x63E460
#define __WndProc_x                                                0x6B1A10
#define __ProcessKeyboardEvent_x                                   0x6B0FB0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490550
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499540
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499310
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493AF0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492F40

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x5652D0
#define AltAdvManager__IsAbilityReady_x                            0x564070
#define AltAdvManager__GetAAById_x                                 0x564400
#define AltAdvManager__CanTrainAbility_x                           0x564470
#define AltAdvManager__CanSeeAbility_x                             0x5647D0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CB250
#define CharacterZoneClient__HasSkill_x                            0x4D60D0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D77F0
#define CharacterZoneClient__IsStackBlocked_x                      0x4C2930
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBDC0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4DA170
#define CharacterZoneClient__GetItemCountInInventory_x             0x4DA250
#define CharacterZoneClient__GetCursorItemCount_x                  0x4DA330
#define CharacterZoneClient__FindAffectSlot_x                      0x4C4A20
#define CharacterZoneClient__BardCastBard_x                        0x4C7450
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF7D0
#define CharacterZoneClient__GetEffect_x                           0x4BBD00
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C5A90
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C5B60
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C5BB0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5D00
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5EE0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3D00
#define CharacterZoneClient__FindItemByGuid_x                      0x4D8750
#define CharacterZoneClient__FindItemByRecord_x                    0x4D81D0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D9230
#define CBankWnd__WndNotification_x                                0x6D9010

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E6D40

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x92BCD0
#define CButtonWnd__CButtonWnd_x                                   0x92A8A0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x706D50
#define CChatManager__InitContextMenu_x                            0x6FFE80
#define CChatManager__FreeChatWindow_x                             0x705890
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9C00
#define CChatManager__SetLockedActiveChatWindow_x                  0x7069D0
#define CChatManager__CreateChatWindow_x                           0x705ED0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9D10

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x93EEC0
#define CContextMenu__dCContextMenu_x                              0x93F0F0
#define CContextMenu__AddMenuItem_x                                0x93F100
#define CContextMenu__RemoveMenuItem_x                             0x93F400
#define CContextMenu__RemoveAllMenuItems_x                         0x93F420
#define CContextMenu__CheckMenuItem_x                              0x93F4A0
#define CContextMenu__SetMenuItem_x                                0x93F330
#define CContextMenu__AddSeparator_x                               0x93F290

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x93FA40
#define CContextMenuManager__RemoveMenu_x                          0x93FAB0
#define CContextMenuManager__PopupMenu_x                           0x93FB70
#define CContextMenuManager__Flush_x                               0x93F9E0
#define CContextMenuManager__GetMenu_x                             0x49B6F0
#define CContextMenuManager__CreateDefaultMenu_x                   0x712480

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D0400
#define CChatService__GetFriendName_x                              0x8D0410

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x707580
#define CChatWindow__Clear_x                                       0x708840
#define CChatWindow__WndNotification_x                             0x708FD0
#define CChatWindow__AddHistory_x                                  0x708100

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93C320
#define CComboWnd__Draw_x                                          0x93B820
#define CComboWnd__GetCurChoice_x                                  0x93C160
#define CComboWnd__GetListRect_x                                   0x93BCD0
#define CComboWnd__GetTextRect_x                                   0x93C380
#define CComboWnd__InsertChoice_x                                  0x93BE60
#define CComboWnd__SetColors_x                                     0x93BE30
#define CComboWnd__SetChoice_x                                     0x93C130
#define CComboWnd__GetItemCount_x                                  0x93C170
#define CComboWnd__GetCurChoiceText_x                              0x93C1B0
#define CComboWnd__GetChoiceText_x                                 0x93C180
#define CComboWnd__InsertChoiceAtIndex_x                           0x93BEF0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x70FEB0
#define CContainerWnd__vftable_x                                   0xAFE74C
#define CContainerWnd__SetContainer_x                              0x711400

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x557900
#define CDisplay__PreZoneMainUI_x                                  0x557910
#define CDisplay__CleanGameUI_x                                    0x55CD60
#define CDisplay__GetClickedActor_x                                0x54FD60
#define CDisplay__GetUserDefinedColor_x                            0x5483D0
#define CDisplay__GetWorldFilePath_x                               0x5517D0
#define CDisplay__is3dON_x                                         0x54C9C0
#define CDisplay__ReloadUI_x                                       0x556E10
#define CDisplay__WriteTextHD2_x                                   0x54C7B0
#define CDisplay__TrueDistance_x                                   0x553490
#define CDisplay__SetViewActor_x                                   0x54F680
#define CDisplay__GetFloorHeight_x                                 0x54CA80
#define CDisplay__SetRenderWindow_x                                0x54B400
#define CDisplay__ToggleScreenshotMode_x                           0x54F150

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x95EBD0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x9423A0
#define CEditWnd__EnsureCaretVisible_x                             0x944560
#define CEditWnd__GetCaretPt_x                                     0x943510
#define CEditWnd__GetCharIndexPt_x                                 0x9432C0
#define CEditWnd__GetDisplayString_x                               0x943160
#define CEditWnd__GetHorzOffset_x                                  0x941A40
#define CEditWnd__GetLineForPrintableChar_x                        0x944460
#define CEditWnd__GetSelStartPt_x                                  0x943570
#define CEditWnd__GetSTMLSafeText_x                                0x942F80
#define CEditWnd__PointFromPrintableChar_x                         0x944090
#define CEditWnd__SelectableCharFromPoint_x                        0x944200
#define CEditWnd__SetEditable_x                                    0x943640
#define CEditWnd__SetWindowTextA_x                                 0x942D00
#define CEditWnd__ReplaceSelection_x                               0x943D00
#define CEditWnd__ReplaceSelection1_x                              0x943C80

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x611760
#define CEverQuest__ClickedPlayer_x                                0x603900
#define CEverQuest__CreateTargetIndicator_x                        0x6212D0
#define CEverQuest__DeleteTargetIndicator_x                        0x621360
#define CEverQuest__DoTellWindow_x                                 0x4E9DF0
#define CEverQuest__OutputTextToLog_x                              0x4EA0C0
#define CEverQuest__DropHeldItemOnGround_x                         0x5F8A60
#define CEverQuest__dsp_chat_x                                     0x4EA450
#define CEverQuest__trimName_x                                     0x61D480
#define CEverQuest__Emote_x                                        0x611FC0
#define CEverQuest__EnterZone_x                                    0x60C0C0
#define CEverQuest__GetBodyTypeDesc_x                              0x616A10
#define CEverQuest__GetClassDesc_x                                 0x617050
#define CEverQuest__GetClassThreeLetterCode_x                      0x617650
#define CEverQuest__GetDeityDesc_x                                 0x61FB20
#define CEverQuest__GetLangDesc_x                                  0x617810
#define CEverQuest__GetRaceDesc_x                                  0x617030
#define CEverQuest__InterpretCmd_x                                 0x6200F0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FCBF0
#define CEverQuest__LMouseUp_x                                     0x5FAF80
#define CEverQuest__RightClickedOnPlayer_x                         0x5FD4D0
#define CEverQuest__RMouseUp_x                                     0x5FBF00
#define CEverQuest__SetGameState_x                                 0x5F87F0
#define CEverQuest__UPCNotificationFlush_x                         0x61D380
#define CEverQuest__IssuePetCommand_x                              0x618C20
#define CEverQuest__ReportSuccessfulHit_x                          0x613310

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x721BB0
#define CGaugeWnd__CalcLinesFillRect_x                             0x721C10
#define CGaugeWnd__Draw_x                                          0x721230

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AFFC0
#define CGuild__GetGuildName_x                                     0x4AEA70
#define CGuild__GetGuildIndex_x                                    0x4AF070

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73B7D0

//CHotButton
#define CHotButton__SetCheck_x                                     0x632990
#define CHotButton__SetButtonSize_x                                0x632D50

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x748920
#define CInvSlotMgr__MoveItem_x                                    0x7475E0
#define CInvSlotMgr__SelectSlot_x                                  0x7489F0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x745DD0
#define CInvSlot__SliderComplete_x                                 0x743B20
#define CInvSlot__GetItemBase_x                                    0x743490
#define CInvSlot__UpdateItem_x                                     0x743600

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x74A480
#define CInvSlotWnd__CInvSlotWnd_x                                 0x749610
#define CInvSlotWnd__HandleLButtonUp_x                             0x74A000

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x804670
#define CItemDisplayWnd__UpdateStrings_x                           0x758B90
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x752880
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x752D90
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x759190
#define CItemDisplayWnd__AboutToShow_x                             0x7587E0
#define CItemDisplayWnd__WndNotification_x                         0x75A400
#define CItemDisplayWnd__RequestConvertItem_x                      0x759D40
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x757840
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x758600

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8350A0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75E8F0

// CLabel 
#define CLabel__Draw_x                                             0x764300

// CListWnd
#define CListWnd__CListWnd_x                                       0x914B20
#define CListWnd__dCListWnd_x                                      0x914E40
#define CListWnd__AddColumn_x                                      0x919280
#define CListWnd__AddColumn1_x                                     0x9192D0
#define CListWnd__AddLine_x                                        0x919660
#define CListWnd__AddString_x                                      0x919460
#define CListWnd__CalculateFirstVisibleLine_x                      0x919040
#define CListWnd__CalculateVSBRange_x                              0x918E20
#define CListWnd__ClearSel_x                                       0x919E40
#define CListWnd__ClearAllSel_x                                    0x919EA0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x91A890
#define CListWnd__Compare_x                                        0x918750
#define CListWnd__Draw_x                                           0x914F70
#define CListWnd__DrawColumnSeparators_x                           0x917740
#define CListWnd__DrawHeader_x                                     0x917BA0
#define CListWnd__DrawItem_x                                       0x918090
#define CListWnd__DrawLine_x                                       0x9178A0
#define CListWnd__DrawSeparator_x                                  0x9177E0
#define CListWnd__EnableLine_x                                     0x917020
#define CListWnd__EnsureVisible_x                                  0x91A7C0
#define CListWnd__ExtendSel_x                                      0x919D70
#define CListWnd__GetColumnTooltip_x                               0x916B60
#define CListWnd__GetColumnMinWidth_x                              0x916BD0
#define CListWnd__GetColumnWidth_x                                 0x916AD0
#define CListWnd__GetCurSel_x                                      0x916460
#define CListWnd__GetItemAtPoint_x                                 0x917290
#define CListWnd__GetItemAtPoint1_x                                0x917300
#define CListWnd__GetItemData_x                                    0x9164E0
#define CListWnd__GetItemHeight_x                                  0x9168A0
#define CListWnd__GetItemIcon_x                                    0x916670
#define CListWnd__GetItemRect_x                                    0x917110
#define CListWnd__GetItemText_x                                    0x916520
#define CListWnd__GetSelList_x                                     0x919EF0
#define CListWnd__GetSeparatorRect_x                               0x917540
#define CListWnd__InsertLine_x                                     0x919A50
#define CListWnd__RemoveLine_x                                     0x919BA0
#define CListWnd__SetColors_x                                      0x918DF0
#define CListWnd__SetColumnJustification_x                         0x918B20
#define CListWnd__SetColumnLabel_x                                 0x919400
#define CListWnd__SetColumnWidth_x                                 0x918A40
#define CListWnd__SetCurSel_x                                      0x919CB0
#define CListWnd__SetItemColor_x                                   0x91A480
#define CListWnd__SetItemData_x                                    0x91A440
#define CListWnd__SetItemText_x                                    0x91A060
#define CListWnd__ShiftColumnSeparator_x                           0x918BE0
#define CListWnd__Sort_x                                           0x9188D0
#define CListWnd__ToggleSel_x                                      0x919CE0
#define CListWnd__SetColumnsSizable_x                              0x918C90
#define CListWnd__SetItemWnd_x                                     0x91A310
#define CListWnd__GetItemWnd_x                                     0x9166C0
#define CListWnd__SetItemIcon_x                                    0x91A0E0
#define CListWnd__CalculateCustomWindowPositions_x                 0x919140
#define CListWnd__SetVScrollPos_x                                  0x918A20

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x779A90
#define CMapViewWnd__GetWorldCoordinates_x                         0x7781A0
#define CMapViewWnd__HandleLButtonDown_x                           0x7751E0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x799E80
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79A760
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79AC90
#define CMerchantWnd__SelectRecoverySlot_x                         0x79DC50
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7989F0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A3810
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x799AA0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89E2B0
#define CPacketScrambler__hton_x                                   0x89E2A0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x933AC0
#define CSidlManager__FindScreenPieceTemplate_x                    0x933ED0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x933CC0
#define CSidlManager__CreateLabel_x                                0x7FB8A0
#define CSidlManager__CreateXWndFromTemplate_x                     0x936E30
#define CSidlManager__CreateXWndFromTemplate1_x                    0x937010
#define CSidlManager__CreateXWnd_x                                 0x7FB7D0
#define CSidlManager__CreateHotButtonWnd_x                         0x7FBD90

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9305A0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9304A0
#define CSidlScreenWnd__ConvertToRes_x                             0x959720
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x92FF90
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x92FC80
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x92FD50
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x92FE20
#define CSidlScreenWnd__DrawSidlPiece_x                            0x930A40
#define CSidlScreenWnd__EnableIniStorage_x                         0x930F10
#define CSidlScreenWnd__GetSidlPiece_x                             0x930C30
#define CSidlScreenWnd__Init1_x                                    0x92F8A0
#define CSidlScreenWnd__LoadIniInfo_x                              0x930F60
#define CSidlScreenWnd__LoadIniListWnd_x                           0x931AA0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92ECA0
#define CSidlScreenWnd__StoreIniInfo_x                             0x931620
#define CSidlScreenWnd__StoreIniVis_x                              0x931980
#define CSidlScreenWnd__WndNotification_x                          0x930950
#define CSidlScreenWnd__GetChildItem_x                             0x930E90
#define CSidlScreenWnd__HandleLButtonUp_x                          0x920610
#define CSidlScreenWnd__m_layoutCopy_x                             0x15D9198

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6983C0
#define CSkillMgr__GetSkillCap_x                                   0x6985A0
#define CSkillMgr__GetNameToken_x                                  0x697B40
#define CSkillMgr__IsActivatedSkill_x                              0x697C80
#define CSkillMgr__IsCombatSkill_x                                 0x697BC0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x940820
#define CSliderWnd__SetValue_x                                     0x940690
#define CSliderWnd__SetNumTicks_x                                  0x9406F0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x801A00

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x949150
#define CStmlWnd__ParseSTML_x                                      0x94A490
#define CStmlWnd__CalculateHSBRange_x                              0x94A270
#define CStmlWnd__CalculateVSBRange_x                              0x94A1E0
#define CStmlWnd__CanBreakAtCharacter_x                            0x94E5B0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x94F240
#define CStmlWnd__ForceParseNow_x                                  0x949740
#define CStmlWnd__GetNextTagPiece_x                                0x94E510
#define CStmlWnd__GetSTMLText_x                                    0x50CC10
#define CStmlWnd__GetVisibleText_x                                 0x949760
#define CStmlWnd__InitializeWindowVariables_x                      0x94F090
#define CStmlWnd__MakeStmlColorTag_x                               0x9487C0
#define CStmlWnd__MakeWndNotificationTag_x                         0x948830
#define CStmlWnd__SetSTMLText_x                                    0x947870
#define CStmlWnd__StripFirstSTMLLines_x                            0x950310
#define CStmlWnd__UpdateHistoryString_x                            0x94F450

// CTabWnd 
#define CTabWnd__Draw_x                                            0x9469C0
#define CTabWnd__DrawCurrentPage_x                                 0x9470F0
#define CTabWnd__DrawTab_x                                         0x946E10
#define CTabWnd__GetCurrentPage_x                                  0x9461C0
#define CTabWnd__GetPageInnerRect_x                                0x946400
#define CTabWnd__GetTabInnerRect_x                                 0x946340
#define CTabWnd__GetTabRect_x                                      0x9461F0
#define CTabWnd__InsertPage_x                                      0x946610
#define CTabWnd__RemovePage_x                                      0x946780
#define CTabWnd__SetPage_x                                         0x946480
#define CTabWnd__SetPageRect_x                                     0x946900
#define CTabWnd__UpdatePage_x                                      0x946CD0
#define CTabWnd__GetPageFromTabIndex_x                             0x946D50
#define CTabWnd__GetCurrentTabIndex_x                              0x9461B0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x75ED00
#define CPageWnd__SetTabText_x                                     0x945D10
#define CPageWnd__FlashTab_x                                       0x945D70

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9270

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91D4E0
#define CTextureFont__GetTextExtent_x                              0x91D6A0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AC5F0
#define CHtmlComponentWnd__ValidateUri_x                           0x73D1C0
#define CHtmlWnd__SetClientCallbacks_x                             0x637DD0
#define CHtmlWnd__AddObserver_x                                    0x637DF0
#define CHtmlWnd__RemoveObserver_x                                 0x637E50
#define Window__getProgress_x                                      0x853860
#define Window__getStatus_x                                        0x853880
#define Window__getURI_x                                           0x853890

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x956530

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x90A540

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9940
#define CXStr__CXStr1_x                                            0x912F60
#define CXStr__CXStr3_x                                            0x8F1630
#define CXStr__dCXStr_x                                            0x4783E0
#define CXStr__operator_equal_x                                    0x8F1860
#define CXStr__operator_equal1_x                                   0x8F18A0
#define CXStr__operator_plus_equal1_x                              0x8F2330
#define CXStr__SetString_x                                         0x8F4220
#define CXStr__operator_char_p_x                                   0x8F1DA0
#define CXStr__GetChar_x                                           0x8F3B50
#define CXStr__Delete_x                                            0x8F3420
#define CXStr__GetUnicode_x                                        0x8F3BC0
#define CXStr__GetLength_x                                         0x47D630
#define CXStr__Mid_x                                               0x47D640
#define CXStr__Insert_x                                            0x8F3C20
#define CXStr__FindNext_x                                          0x8F3890

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93EAD0
#define CXWnd__BringToTop_x                                        0x923DA0
#define CXWnd__Center_x                                            0x923920
#define CXWnd__ClrFocus_x                                          0x923740
#define CXWnd__Destroy_x                                           0x9237E0
#define CXWnd__DoAllDrawing_x                                      0x91FDB0
#define CXWnd__DrawChildren_x                                      0x91FD80
#define CXWnd__DrawColoredRect_x                                   0x920200
#define CXWnd__DrawTooltip_x                                       0x91E8D0
#define CXWnd__DrawTooltipAtPoint_x                                0x91E990
#define CXWnd__GetBorderFrame_x                                    0x920060
#define CXWnd__GetChildWndAt_x                                     0x923E40
#define CXWnd__GetClientClipRect_x                                 0x922030
#define CXWnd__GetScreenClipRect_x                                 0x922100
#define CXWnd__GetScreenRect_x                                     0x9222B0
#define CXWnd__GetRelativeRect_x                                   0x922370
#define CXWnd__GetTooltipRect_x                                    0x920250
#define CXWnd__GetWindowTextA_x                                    0x49CE80
#define CXWnd__IsActive_x                                          0x920980
#define CXWnd__IsDescendantOf_x                                    0x922CB0
#define CXWnd__IsReallyVisible_x                                   0x922CE0
#define CXWnd__IsType_x                                            0x924490
#define CXWnd__Move_x                                              0x922D40
#define CXWnd__Move1_x                                             0x922DF0
#define CXWnd__ProcessTransition_x                                 0x9238D0
#define CXWnd__Refade_x                                            0x9230C0
#define CXWnd__Resize_x                                            0x923360
#define CXWnd__Right_x                                             0x923B60
#define CXWnd__SetFocus_x                                          0x923700
#define CXWnd__SetFont_x                                           0x923770
#define CXWnd__SetKeyTooltip_x                                     0x9242B0
#define CXWnd__SetMouseOver_x                                      0x9211A0
#define CXWnd__StartFade_x                                         0x922B90
#define CXWnd__GetChildItem_x                                      0x923FB0
#define CXWnd__SetParent_x                                         0x922A50
#define CXWnd__Minimize_x                                          0x9233D0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x95A7A0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x926CD0
#define CXWndManager__DrawWindows_x                                0x926CF0
#define CXWndManager__GetKeyboardFlags_x                           0x9294E0
#define CXWndManager__HandleKeyboardMsg_x                          0x929090
#define CXWndManager__RemoveWnd_x                                  0x929710
#define CXWndManager__RemovePendingDeletionWnd_x                   0x929C70

// CDBStr
#define CDBStr__GetString_x                                        0x547380

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BFF30
#define EQ_Character__Cur_HP_x                                     0x4D3110
#define EQ_Character__Cur_Mana_x                                   0x4DA830
#define EQ_Character__GetCastingTimeModifier_x                     0x4C2FA0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B3940
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3A90
#define EQ_Character__GetHPRegen_x                                 0x4E0700
#define EQ_Character__GetEnduranceRegen_x                          0x4E0D00
#define EQ_Character__GetManaRegen_x                               0x4E1140
#define EQ_Character__Max_Endurance_x                              0x65E560
#define EQ_Character__Max_HP_x                                     0x4D2F40
#define EQ_Character__Max_Mana_x                                   0x65E360
#define EQ_Character__doCombatAbility_x                            0x660950
#define EQ_Character__UseSkill_x                                   0x4E2F50
#define EQ_Character__GetConLevel_x                                0x6571D0
#define EQ_Character__IsExpansionFlag_x                            0x5BA7D0
#define EQ_Character__TotalEffect_x                                0x4C6D40
#define EQ_Character__GetPCSpellAffect_x                           0x4C3CF0
#define EQ_Character__SpellDuration_x                              0x4C3820
#define EQ_Character__MySpellDuration_x                            0x4B2270
#define EQ_Character__GetAdjustedSkill_x                           0x4D5E90
#define EQ_Character__GetBaseSkill_x                               0x4D6E30
#define EQ_Character__CanUseItem_x                                 0x4DAB40

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BD2F0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x674890

//PcClient
#define PcClient__vftable_x                                        0xAF21D8
#define PcClient__PcClient_x                                       0x654940

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA970
#define CCharacterListWnd__EnterWorld_x                            0x4BA340
#define CCharacterListWnd__Quit_x                                  0x4BA090
#define CCharacterListWnd__UpdateList_x                            0x4BA530

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x638FC0
#define EQ_Item__CreateItemTagString_x                             0x897850
#define EQ_Item__IsStackable_x                                     0x89C4F0
#define EQ_Item__GetImageNum_x                                     0x8993C0
#define EQ_Item__CreateItemClient_x                                0x6381F0
#define EQ_Item__GetItemValue_x                                    0x89A6E0
#define EQ_Item__ValueSellMerchant_x                               0x89DE90
#define EQ_Item__IsKeyRingItem_x                                   0x89BE10
#define EQ_Item__CanGoInBag_x                                      0x6390E0
#define EQ_Item__IsEmpty_x                                         0x89B950
#define EQ_Item__GetMaxItemCount_x                                 0x89AAF0
#define EQ_Item__GetHeldItem_x                                     0x899290
#define EQ_Item__GetAugmentFitBySlot_x                             0x8970B0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x565FE0
#define EQ_LoadingS__Array_x                                       0xC12130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65EE60
#define EQ_PC__GetAlternateAbilityId_x                             0x8A6F20
#define EQ_PC__GetCombatAbility_x                                  0x8A7590
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A7600
#define EQ_PC__GetItemRecastTimer_x                                0x660ED0
#define EQ_PC__HasLoreItem_x                                       0x6579E0
#define EQ_PC__AlertInventoryChanged_x                             0x656B10
#define EQ_PC__GetPcZoneClient_x                                   0x683940
#define EQ_PC__RemoveMyAffect_x                                    0x664100
#define EQ_PC__GetKeyRingItems_x                                   0x8A7E90
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A7C20
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A8190

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5C0C20
#define EQItemList__add_object_x                                   0x5EE230
#define EQItemList__add_item_x                                     0x5C1180
#define EQItemList__delete_item_x                                  0x5C11D0
#define EQItemList__FreeItemList_x                                 0x5C10D0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x543F30

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x676190
#define EQPlayer__dEQPlayer_x                                      0x669510
#define EQPlayer__DoAttack_x                                       0x67E0D0
#define EQPlayer__EQPlayer_x                                       0x669BD0
#define EQPlayer__SetNameSpriteState_x                             0x66DEA0
#define EQPlayer__SetNameSpriteTint_x                              0x66ED80
#define PlayerBase__HasProperty_j_x                                0x989360
#define EQPlayer__IsTargetable_x                                   0x989800
#define EQPlayer__CanSee_x                                         0x989660
#define EQPlayer__CanSee1_x                                        0x989730
#define PlayerBase__GetVisibilityLineSegment_x                     0x989420

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x6813D0
#define PlayerZoneClient__GetLevel_x                               0x683980
#define PlayerZoneClient__IsValidTeleport_x                        0x5EF3A0
#define PlayerZoneClient__LegalPlayerRace_x                        0x55EC20

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x678F80
#define EQPlayerManager__GetSpawnByName_x                          0x679030
#define EQPlayerManager__GetPlayerFromPartialName_x                0x6790C0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63C6C0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63C740
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63C780
#define KeypressHandler__ClearCommandStateArray_x                  0x63DB70
#define KeypressHandler__HandleKeyDown_x                           0x63DB90
#define KeypressHandler__HandleKeyUp_x                             0x63DC30
#define KeypressHandler__SaveKeymapping_x                          0x63E080

// MapViewMap 
#define MapViewMap__Clear_x                                        0x775900
#define MapViewMap__SaveEx_x                                       0x778CC0
#define MapViewMap__SetZoom_x                                      0x77D380

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BB360

// StringTable 
#define StringTable__getString_x                                   0x8B60C0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x663D70
#define PcZoneClient__RemovePetEffect_x                            0x6643A0
#define PcZoneClient__HasAlternateAbility_x                        0x65E190
#define PcZoneClient__GetCurrentMod_x                              0x4E6070
#define PcZoneClient__GetModCap_x                                  0x4E5F70
#define PcZoneClient__CanEquipItem_x                               0x65E840
#define PcZoneClient__GetItemByID_x                                0x661340
#define PcZoneClient__GetItemByItemClass_x                         0x661490
#define PcZoneClient__RemoveBuffEffect_x                           0x6643C0
#define PcZoneClient__BandolierSwap_x                              0x65F420
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x660E70

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F3F20

//IconCache
#define IconCache__GetIcon_x                                       0x717520

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x70F040
#define CContainerMgr__CloseContainer_x                            0x70F310
#define CContainerMgr__OpenExperimentContainer_x                   0x70FD90

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CE070

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x631180

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76BDB0
#define CLootWnd__RequestLootSlot_x                                0x76B080

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58D9A0
#define EQ_Spell__SpellAffects_x                                   0x58DE10
#define EQ_Spell__SpellAffectBase_x                                0x58DBD0
#define EQ_Spell__IsStackable_x                                    0x4CAB40
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CA930
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7C00
#define EQ_Spell__IsSPAStacking_x                                  0x58EC60
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58E170
#define EQ_Spell__IsNoRemove_x                                     0x4CAB20
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58EC70
#define __IsResEffectSpell_x                                       0x4C9D90

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD520

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C5A50

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x814D50
#define CTargetWnd__WndNotification_x                              0x814590
#define CTargetWnd__RefreshTargetBuffs_x                           0x814860
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x813700

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x8193C0
#define CTaskWnd__ConfirmAbandonTask_x                             0x81C000

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x5418E0
#define CTaskManager__HandleMessage_x                              0x53FD50
#define CTaskManager__GetTaskStatus_x                              0x541990
#define CTaskManager__GetElementDescription_x                      0x541A10

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x588AB0
#define EqSoundManager__PlayScriptMp3_x                            0x588D70
#define EqSoundManager__SoundAssistPlay_x                          0x69C330
#define EqSoundManager__WaveInstancePlay_x                         0x69B8A0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x532CC0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x945220
#define CTextureAnimation__Draw_x                                  0x945420

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x941180

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56DAD0
#define CAltAbilityData__GetMercMaxRank_x                          0x56DA60
#define CAltAbilityData__GetMaxRank_x                              0x562EF0

//CTargetRing
#define CTargetRing__Cast_x                                        0x62F2A0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA910
#define CharacterBase__CreateItemGlobalIndex_x                     0x519850
#define CharacterBase__CreateItemIndex_x                           0x637380
#define CharacterBase__GetItemPossession_x                         0x505710
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CE0B0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CE110
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F60A0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F68D0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F6980

//messages
#define msg_spell_worn_off_x                                       0x5B27A0
#define msg_new_text_x                                             0x5A7120
#define __msgTokenTextParam_x                                      0x5B4A30
#define msgTokenText_x                                             0x5B4C80

//SpellManager
#define SpellManager__vftable_x                                    0xADA574
#define SpellManager__SpellManager_x                               0x69F660
#define Spellmanager__LoadTextSpells_x                             0x69FF50
#define SpellManager__GetSpellByGroupAndRank_x                     0x69F830

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98D290

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x519EA0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B8C10
#define ItemGlobalIndex__IsEquippedLocation_x                      0x6500A0
#define ItemGlobalIndex__IsValidIndex_x                            0x519F30

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C63F0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C6670

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x764640

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x713720
#define CCursorAttachment__AttachToCursor1_x                       0x713760
#define CCursorAttachment__Deactivate_x                            0x714750

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x937E60
#define CSidlManagerBase__CreatePageWnd_x                          0x937660
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x9338E0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x933870

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x954F30
#define CEQSuiteTextureLoader__GetTexture_x                        0x954BF0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x516E00
#define CFindItemWnd__WndNotification_x                            0x5178E0
#define CFindItemWnd__Update_x                                     0x518450
#define CFindItemWnd__PickupSelectedItem_x                         0x516630

//IString
#define IString__Append_x                                          0x506FB0

//Camera
#define CDisplay__cameraType_x                                     0xDEA2A0
#define EverQuest__Cameras_x                                       0xEA509C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51F880
#define LootFiltersManager__GetItemFilterData_x                    0x51F190
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51F1C0
#define LootFiltersManager__SetItemLootFilter_x                    0x51F3E0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BBE70

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x992E60
#define CResolutionHandler__GetWindowedStyle_x                     0x696E20

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70BCF0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8DB980
#define CDistillerInfo__Instance_x                                 0x8DB920

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72AB70
#define CGroupWnd__UpdateDisplay_x                                 0x729EC0

//ItemBase
#define ItemBase__IsLore_x                                         0x89BEC0
#define ItemBase__IsLoreEquipped_x                                 0x89BF30

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EE190
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EE2D0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EE330

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68C080
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x68F9F0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50D560

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F9890
#define FactionManagerClient__HandleFactionMessage_x               0x4F9F00
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4FA500
#define FactionManagerClient__GetMaxFaction_x                      0x4FA51F
#define FactionManagerClient__GetMinFaction_x                      0x4FA4D0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x5056E0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91C530

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C190

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x5059C0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56CF70

//CTargetManager
#define CTargetManager__Get_x                                      0x6A2E80

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68C080

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A9030

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5C1070

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF42734

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6BF9C0
#define CAAWnd__UpdateSelected_x                                   0x6BC230
#define CAAWnd__Update_x                                           0x6BECE0

//CXRect
#define CXRect__operator_and_x                                     0x721C70

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x4832F0

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
