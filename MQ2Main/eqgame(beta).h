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
#define __ExpectedVersionDate                                     "Nov  4 2020"
#define __ExpectedVersionTime                                     "04:20:12"
#define __ActualVersionDate_x                                      0xAF454C
#define __ActualVersionTime_x                                      0xAF4540
#define __ActualVersionBuild_x                                     0xAE2544

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x642970
#define __MemChecker1_x                                            0x8F55E0
#define __MemChecker2_x                                            0x6B2FF0
#define __MemChecker3_x                                            0x6B2F40
#define __MemChecker4_x                                            0x84B7F0
#define __EncryptPad0_x                                            0xC2A9D0
#define __EncryptPad1_x                                            0xC88218
#define __EncryptPad2_x                                            0xC3AD98
#define __EncryptPad3_x                                            0xC3A998
#define __EncryptPad4_x                                            0xC787A8
#define __EncryptPad5_x                                            0xF4A658
#define __AC1_x                                                    0x80A4A6
#define __AC2_x                                                    0x5FBF9F
#define __AC3_x                                                    0x6035F0
#define __AC4_x                                                    0x6075A0
#define __AC5_x                                                    0x60D89F
#define __AC6_x                                                    0x611D56
#define __AC7_x                                                    0x5FBA10
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
#define __do_loot_x                                                0x5C79D0
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
#define __gfMaxZoomCameraDistance_x                                0xAEC160
#define __gfMaxCameraDistance_x                                    0xB14DF0
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
#define pinstCPurchaseGroupWnd_x                                   0xDEA28C
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
#define pinstCZoneGuideWnd_x                                       0xDEA288
#define pinstCZonePathWnd_x                                        0xDEA2A4

#define pinstEQSuiteTextureLoader_x                                0xC88B38
#define pinstItemIconCache_x                                       0xF57568
#define pinstLootFiltersManager_x                                  0xCBAF98
#define pinstRewardSelectionWnd_x                                  0xF5C5F8

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5C30C0
#define __CastRay2_x                                               0x5C3110
#define __ConvertItemTags_x                                        0x5DEDD0
#define __CleanItemTags_x                                          0x47D270
#define __DoesFileExist_x                                          0x8F8660
#define __EQGetTime_x                                              0x8F5210
#define __ExecuteCmd_x                                             0x5BB9E0
#define __FixHeading_x                                             0x98AA00
#define __FlushDxKeyboard_x                                        0x6AEE90
#define __GameLoop_x                                               0x6B21C0
#define __get_bearing_x                                            0x5C2C20
#define __get_melee_range_x                                        0x5C3300
#define __GetAnimationCache_x                                      0x7174C0
#define __GetGaugeValueFromEQ_x                                    0x808950
#define __GetLabelFromEQ_x                                         0x80A430
#define __GetXTargetType_x                                         0x98C3E0
#define __HandleMouseWheel_x                                       0x6B30A0
#define __HeadingDiff_x                                            0x98AA70
#define __HelpPath_x                                               0xF42E04
#define __LoadFrontEnd_x                                           0x6AF4D0
#define __NewUIINI_x                                               0x808620
#define __ProcessGameEvents_x                                      0x623C30
#define __ProcessMouseEvent_x                                      0x6233C0
#define __SaveColors_x                                             0x55CD80
#define __STMLToText_x                                             0x92DE80
#define __ToggleKeyRingItem_x                                      0x51B460
#define CMemoryMappedFile__SetFile_x                               0xA79DD0
#define CrashDetected_x                                            0x6B0F80
#define DrawNetStatus_x                                            0x64FDA0
#define Expansion_HoT_x                                            0xEA4D50
#define Teleport_Table_Size_x                                      0xE9C450
#define Teleport_Table_x                                           0xE9C918
#define Util__FastTime_x                                           0x8F4DE0
#define __CopyLayout_x                                             0x63E020
#define __WndProc_x                                                0x6B1480
#define __ProcessKeyboardEvent_x                                   0x6B0A20

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4905E0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4995D0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4993A0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493B70
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492FC0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x564FD0
#define AltAdvManager__IsAbilityReady_x                            0x563D70
#define AltAdvManager__GetAAById_x                                 0x564100
#define AltAdvManager__CanTrainAbility_x                           0x564170
#define AltAdvManager__CanSeeAbility_x                             0x5644D0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CB160
#define CharacterZoneClient__HasSkill_x                            0x4D5FE0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D7700
#define CharacterZoneClient__IsStackBlocked_x                      0x4C28D0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBD60
#define CharacterZoneClient__GetItemCountWorn_x                    0x4DA060
#define CharacterZoneClient__GetItemCountInInventory_x             0x4DA140
#define CharacterZoneClient__GetCursorItemCount_x                  0x4DA220
#define CharacterZoneClient__FindAffectSlot_x                      0x4C49C0
#define CharacterZoneClient__BardCastBard_x                        0x4C73F0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF770
#define CharacterZoneClient__GetEffect_x                           0x4BBCA0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C5A30
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C5B00
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C5B50
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5CA0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5E80
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3CD0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D8660
#define CharacterZoneClient__FindItemByRecord_x                    0x4D80E0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D8D60
#define CBankWnd__WndNotification_x                                0x6D8B40

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E65D0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x92B660
#define CButtonWnd__CButtonWnd_x                                   0x92A240

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x7066F0
#define CChatManager__InitContextMenu_x                            0x6FF820
#define CChatManager__FreeChatWindow_x                             0x705230
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9A40
#define CChatManager__SetLockedActiveChatWindow_x                  0x706370
#define CChatManager__CreateChatWindow_x                           0x705870

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9B50

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x93E850
#define CContextMenu__dCContextMenu_x                              0x93EA80
#define CContextMenu__AddMenuItem_x                                0x93EA90
#define CContextMenu__RemoveMenuItem_x                             0x93ED90
#define CContextMenu__RemoveAllMenuItems_x                         0x93EDB0
#define CContextMenu__CheckMenuItem_x                              0x93EE30
#define CContextMenu__SetMenuItem_x                                0x93ECC0
#define CContextMenu__AddSeparator_x                               0x93EC20

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x93F3D0
#define CContextMenuManager__RemoveMenu_x                          0x93F440
#define CContextMenuManager__PopupMenu_x                           0x93F500
#define CContextMenuManager__Flush_x                               0x93F370
#define CContextMenuManager__GetMenu_x                             0x49B870
#define CContextMenuManager__CreateDefaultMenu_x                   0x711E40

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D00B0
#define CChatService__GetFriendName_x                              0x8D00C0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x706F20
#define CChatWindow__Clear_x                                       0x7081F0
#define CChatWindow__WndNotification_x                             0x708980
#define CChatWindow__AddHistory_x                                  0x707AB0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93BCB0
#define CComboWnd__Draw_x                                          0x93B1B0
#define CComboWnd__GetCurChoice_x                                  0x93BAF0
#define CComboWnd__GetListRect_x                                   0x93B660
#define CComboWnd__GetTextRect_x                                   0x93BD10
#define CComboWnd__InsertChoice_x                                  0x93B7F0
#define CComboWnd__SetColors_x                                     0x93B7C0
#define CComboWnd__SetChoice_x                                     0x93BAC0
#define CComboWnd__GetItemCount_x                                  0x93BB00
#define CComboWnd__GetCurChoiceText_x                              0x93BB40
#define CComboWnd__GetChoiceText_x                                 0x93BB10
#define CComboWnd__InsertChoiceAtIndex_x                           0x93B880

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x70F840
#define CContainerWnd__vftable_x                                   0xAFD744
#define CContainerWnd__SetContainer_x                              0x710DA0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x5576E0
#define CDisplay__PreZoneMainUI_x                                  0x5576F0
#define CDisplay__CleanGameUI_x                                    0x55CB40
#define CDisplay__GetClickedActor_x                                0x54FB40
#define CDisplay__GetUserDefinedColor_x                            0x5481C0
#define CDisplay__GetWorldFilePath_x                               0x5515B0
#define CDisplay__is3dON_x                                         0x54C7A0
#define CDisplay__ReloadUI_x                                       0x556BF0
#define CDisplay__WriteTextHD2_x                                   0x54C590
#define CDisplay__TrueDistance_x                                   0x553270
#define CDisplay__SetViewActor_x                                   0x54F460
#define CDisplay__GetFloorHeight_x                                 0x54C860
#define CDisplay__SetRenderWindow_x                                0x54B1E0
#define CDisplay__ToggleScreenshotMode_x                           0x54EF30

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x95E780

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x941D30
#define CEditWnd__EnsureCaretVisible_x                             0x943EE0
#define CEditWnd__GetCaretPt_x                                     0x942E90
#define CEditWnd__GetCharIndexPt_x                                 0x942C50
#define CEditWnd__GetDisplayString_x                               0x942AF0
#define CEditWnd__GetHorzOffset_x                                  0x9413D0
#define CEditWnd__GetLineForPrintableChar_x                        0x943DE0
#define CEditWnd__GetSelStartPt_x                                  0x942EF0
#define CEditWnd__GetSTMLSafeText_x                                0x942910
#define CEditWnd__PointFromPrintableChar_x                         0x943A10
#define CEditWnd__SelectableCharFromPoint_x                        0x943B80
#define CEditWnd__SetEditable_x                                    0x942FC0
#define CEditWnd__SetWindowTextA_x                                 0x942690
#define CEditWnd__ReplaceSelection_x                               0x943680
#define CEditWnd__ReplaceSelection1_x                              0x943600

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x611230
#define CEverQuest__ClickedPlayer_x                                0x6033D0
#define CEverQuest__CreateTargetIndicator_x                        0x620DA0
#define CEverQuest__DeleteTargetIndicator_x                        0x620E30
#define CEverQuest__DoTellWindow_x                                 0x4E9C30
#define CEverQuest__OutputTextToLog_x                              0x4E9F00
#define CEverQuest__DropHeldItemOnGround_x                         0x5F8530
#define CEverQuest__dsp_chat_x                                     0x4EA290
#define CEverQuest__trimName_x                                     0x61CF50
#define CEverQuest__Emote_x                                        0x611A90
#define CEverQuest__EnterZone_x                                    0x60BB90
#define CEverQuest__GetBodyTypeDesc_x                              0x6164E0
#define CEverQuest__GetClassDesc_x                                 0x616B20
#define CEverQuest__GetClassThreeLetterCode_x                      0x617120
#define CEverQuest__GetDeityDesc_x                                 0x61F5F0
#define CEverQuest__GetLangDesc_x                                  0x6172E0
#define CEverQuest__GetRaceDesc_x                                  0x616B00
#define CEverQuest__InterpretCmd_x                                 0x61FBC0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FC6C0
#define CEverQuest__LMouseUp_x                                     0x5FAA50
#define CEverQuest__RightClickedOnPlayer_x                         0x5FCFA0
#define CEverQuest__RMouseUp_x                                     0x5FB9D0
#define CEverQuest__SetGameState_x                                 0x5F82C0
#define CEverQuest__UPCNotificationFlush_x                         0x61CE50
#define CEverQuest__IssuePetCommand_x                              0x6186F0
#define CEverQuest__ReportSuccessfulHit_x                          0x612DE0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7214C0
#define CGaugeWnd__CalcLinesFillRect_x                             0x721520
#define CGaugeWnd__Draw_x                                          0x720B40

// CGuild
#define CGuild__FindMemberByName_x                                 0x4B0050
#define CGuild__GetGuildName_x                                     0x4AEB00
#define CGuild__GetGuildIndex_x                                    0x4AF100

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73B140

//CHotButton
#define CHotButton__SetCheck_x                                     0x632460
#define CHotButton__SetButtonSize_x                                0x632820

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x7481D0
#define CInvSlotMgr__MoveItem_x                                    0x746EA0
#define CInvSlotMgr__SelectSlot_x                                  0x7482A0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7456D0
#define CInvSlot__SliderComplete_x                                 0x743420
#define CInvSlot__GetItemBase_x                                    0x742DA0
#define CInvSlot__UpdateItem_x                                     0x742F10

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x749D00
#define CInvSlotWnd__CInvSlotWnd_x                                 0x748EA0
#define CInvSlotWnd__HandleLButtonUp_x                             0x749880

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x803CE0
#define CItemDisplayWnd__UpdateStrings_x                           0x7584C0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x752150
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x752680
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x758AC0
#define CItemDisplayWnd__AboutToShow_x                             0x758130
#define CItemDisplayWnd__WndNotification_x                         0x759D30
#define CItemDisplayWnd__RequestConvertItem_x                      0x759670
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x757190
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x757F50

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x834640

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75E240

// CLabel 
#define CLabel__Draw_x                                             0x763C50

// CListWnd
#define CListWnd__CListWnd_x                                       0x9144A0
#define CListWnd__dCListWnd_x                                      0x9147C0
#define CListWnd__AddColumn_x                                      0x918C10
#define CListWnd__AddColumn1_x                                     0x918C60
#define CListWnd__AddLine_x                                        0x918FF0
#define CListWnd__AddString_x                                      0x918DF0
#define CListWnd__CalculateFirstVisibleLine_x                      0x9189E0
#define CListWnd__CalculateVSBRange_x                              0x9187C0
#define CListWnd__ClearSel_x                                       0x9197D0
#define CListWnd__ClearAllSel_x                                    0x919830
#define CListWnd__CloseAndUpdateEditWindow_x                       0x91A220
#define CListWnd__Compare_x                                        0x9180F0
#define CListWnd__Draw_x                                           0x9148F0
#define CListWnd__DrawColumnSeparators_x                           0x9170C0
#define CListWnd__DrawHeader_x                                     0x917530
#define CListWnd__DrawItem_x                                       0x917A30
#define CListWnd__DrawLine_x                                       0x917230
#define CListWnd__DrawSeparator_x                                  0x917160
#define CListWnd__EnableLine_x                                     0x9169B0
#define CListWnd__EnsureVisible_x                                  0x91A160
#define CListWnd__ExtendSel_x                                      0x919700
#define CListWnd__GetColumnTooltip_x                               0x9164F0
#define CListWnd__GetColumnMinWidth_x                              0x916560
#define CListWnd__GetColumnWidth_x                                 0x916460
#define CListWnd__GetCurSel_x                                      0x915DF0
#define CListWnd__GetItemAtPoint_x                                 0x916C20
#define CListWnd__GetItemAtPoint1_x                                0x916C90
#define CListWnd__GetItemData_x                                    0x915E70
#define CListWnd__GetItemHeight_x                                  0x916230
#define CListWnd__GetItemIcon_x                                    0x916000
#define CListWnd__GetItemRect_x                                    0x916AA0
#define CListWnd__GetItemText_x                                    0x915EB0
#define CListWnd__GetSelList_x                                     0x919880
#define CListWnd__GetSeparatorRect_x                               0x916ED0
#define CListWnd__InsertLine_x                                     0x9193E0
#define CListWnd__RemoveLine_x                                     0x919530
#define CListWnd__SetColors_x                                      0x918790
#define CListWnd__SetColumnJustification_x                         0x9184C0
#define CListWnd__SetColumnLabel_x                                 0x918D90
#define CListWnd__SetColumnWidth_x                                 0x9183E0
#define CListWnd__SetCurSel_x                                      0x919640
#define CListWnd__SetItemColor_x                                   0x919E20
#define CListWnd__SetItemData_x                                    0x919DE0
#define CListWnd__SetItemText_x                                    0x9199F0
#define CListWnd__ShiftColumnSeparator_x                           0x918580
#define CListWnd__Sort_x                                           0x918270
#define CListWnd__ToggleSel_x                                      0x919670
#define CListWnd__SetColumnsSizable_x                              0x918630
#define CListWnd__SetItemWnd_x                                     0x919CA0
#define CListWnd__GetItemWnd_x                                     0x916050
#define CListWnd__SetItemIcon_x                                    0x919A70
#define CListWnd__CalculateCustomWindowPositions_x                 0x918AD0
#define CListWnd__SetVScrollPos_x                                  0x9183C0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x779360
#define CMapViewWnd__GetWorldCoordinates_x                         0x777A70
#define CMapViewWnd__HandleLButtonDown_x                           0x774AB0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x799620
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x799F00
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79A430
#define CMerchantWnd__SelectRecoverySlot_x                         0x79D3E0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7981A0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A2FA0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x799240

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89D910
#define CPacketScrambler__hton_x                                   0x89D900

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x933430
#define CSidlManager__FindScreenPieceTemplate_x                    0x933840
#define CSidlManager__FindScreenPieceTemplate1_x                   0x933630
#define CSidlManager__CreateLabel_x                                0x7FAF70
#define CSidlManager__CreateXWndFromTemplate_x                     0x9367A0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x936970
#define CSidlManager__CreateXWnd_x                                 0x7FAEA0
#define CSidlManager__CreateHotButtonWnd_x                         0x7FB470

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x92FF30
#define CSidlScreenWnd__CalculateVSBRange_x                        0x92FE30
#define CSidlScreenWnd__ConvertToRes_x                             0x959220
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x92F920
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x92F610
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x92F6E0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x92F7B0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x9303C0
#define CSidlScreenWnd__EnableIniStorage_x                         0x930890
#define CSidlScreenWnd__GetSidlPiece_x                             0x9305B0
#define CSidlScreenWnd__Init1_x                                    0x92F210
#define CSidlScreenWnd__LoadIniInfo_x                              0x9308E0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x931410
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92E630
#define CSidlScreenWnd__StoreIniInfo_x                             0x930F90
#define CSidlScreenWnd__StoreIniVis_x                              0x9312F0
#define CSidlScreenWnd__WndNotification_x                          0x9302D0
#define CSidlScreenWnd__GetChildItem_x                             0x930810
#define CSidlScreenWnd__HandleLButtonUp_x                          0x920050
#define CSidlScreenWnd__m_layoutCopy_x                             0x15D9198

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x698180
#define CSkillMgr__GetSkillCap_x                                   0x698360
#define CSkillMgr__GetNameToken_x                                  0x697900
#define CSkillMgr__IsActivatedSkill_x                              0x697A40
#define CSkillMgr__IsCombatSkill_x                                 0x697980

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9401B0
#define CSliderWnd__SetValue_x                                     0x940020
#define CSliderWnd__SetNumTicks_x                                  0x940080

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x801060

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x948B60
#define CStmlWnd__ParseSTML_x                                      0x949EA0
#define CStmlWnd__CalculateHSBRange_x                              0x949C70
#define CStmlWnd__CalculateVSBRange_x                              0x949BF0
#define CStmlWnd__CanBreakAtCharacter_x                            0x94DFC0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x94EC50
#define CStmlWnd__ForceParseNow_x                                  0x949150
#define CStmlWnd__GetNextTagPiece_x                                0x94DF20
#define CStmlWnd__GetSTMLText_x                                    0x50CB80
#define CStmlWnd__GetVisibleText_x                                 0x949170
#define CStmlWnd__InitializeWindowVariables_x                      0x94EAA0
#define CStmlWnd__MakeStmlColorTag_x                               0x9481D0
#define CStmlWnd__MakeWndNotificationTag_x                         0x948240
#define CStmlWnd__SetSTMLText_x                                    0x947280
#define CStmlWnd__StripFirstSTMLLines_x                            0x94FD40
#define CStmlWnd__UpdateHistoryString_x                            0x94EE60

// CTabWnd 
#define CTabWnd__Draw_x                                            0x946320
#define CTabWnd__DrawCurrentPage_x                                 0x946A50
#define CTabWnd__DrawTab_x                                         0x946770
#define CTabWnd__GetCurrentPage_x                                  0x945B20
#define CTabWnd__GetPageInnerRect_x                                0x945D60
#define CTabWnd__GetTabInnerRect_x                                 0x945CA0
#define CTabWnd__GetTabRect_x                                      0x945B50
#define CTabWnd__InsertPage_x                                      0x945F70
#define CTabWnd__RemovePage_x                                      0x9460E0
#define CTabWnd__SetPage_x                                         0x945DE0
#define CTabWnd__SetPageRect_x                                     0x946260
#define CTabWnd__UpdatePage_x                                      0x946630
#define CTabWnd__GetPageFromTabIndex_x                             0x9466B0
#define CTabWnd__GetCurrentTabIndex_x                              0x945B10

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x75E650
#define CPageWnd__SetTabText_x                                     0x945670
#define CPageWnd__FlashTab_x                                       0x9456D0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A92A0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91CF20
#define CTextureFont__GetTextExtent_x                              0x91D0E0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AC320
#define CHtmlComponentWnd__ValidateUri_x                           0x73CB30
#define CHtmlWnd__SetClientCallbacks_x                             0x637880
#define CHtmlWnd__AddObserver_x                                    0x6378A0
#define CHtmlWnd__RemoveObserver_x                                 0x637900
#define Window__getProgress_x                                      0x852DB0
#define Window__getStatus_x                                        0x852DD0
#define Window__getURI_x                                           0x852DE0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x956030

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x909EE0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9880
#define CXStr__CXStr1_x                                            0x507C60
#define CXStr__CXStr3_x                                            0x8F11D0
#define CXStr__dCXStr_x                                            0x478440
#define CXStr__operator_equal_x                                    0x8F1400
#define CXStr__operator_equal1_x                                   0x8F1440
#define CXStr__operator_plus_equal1_x                              0x8F1ED0
#define CXStr__SetString_x                                         0x8F3DC0
#define CXStr__operator_char_p_x                                   0x8F1910
#define CXStr__GetChar_x                                           0x8F3710
#define CXStr__Delete_x                                            0x8F2FC0
#define CXStr__GetUnicode_x                                        0x8F3780
#define CXStr__GetLength_x                                         0x4A9050
#define CXStr__Mid_x                                               0x47D620
#define CXStr__Insert_x                                            0x8F37E0
#define CXStr__FindNext_x                                          0x8F3430

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93E460
#define CXWnd__BringToTop_x                                        0x923810
#define CXWnd__Center_x                                            0x923390
#define CXWnd__ClrFocus_x                                          0x9231B0
#define CXWnd__Destroy_x                                           0x923250
#define CXWnd__DoAllDrawing_x                                      0x91F810
#define CXWnd__DrawChildren_x                                      0x91F7E0
#define CXWnd__DrawColoredRect_x                                   0x91FC60
#define CXWnd__DrawTooltip_x                                       0x91E330
#define CXWnd__DrawTooltipAtPoint_x                                0x91E3F0
#define CXWnd__GetBorderFrame_x                                    0x91FAC0
#define CXWnd__GetChildWndAt_x                                     0x9238B0
#define CXWnd__GetClientClipRect_x                                 0x921A60
#define CXWnd__GetScreenClipRect_x                                 0x921B30
#define CXWnd__GetScreenRect_x                                     0x921D00
#define CXWnd__GetRelativeRect_x                                   0x921DC0
#define CXWnd__GetTooltipRect_x                                    0x91FCB0
#define CXWnd__GetWindowTextA_x                                    0x49CF60
#define CXWnd__IsActive_x                                          0x9203D0
#define CXWnd__IsDescendantOf_x                                    0x922700
#define CXWnd__IsReallyVisible_x                                   0x922730
#define CXWnd__IsType_x                                            0x923F20
#define CXWnd__Move_x                                              0x9227A0
#define CXWnd__Move1_x                                             0x922850
#define CXWnd__ProcessTransition_x                                 0x923340
#define CXWnd__Refade_x                                            0x922B30
#define CXWnd__Resize_x                                            0x922DD0
#define CXWnd__Right_x                                             0x9235D0
#define CXWnd__SetFocus_x                                          0x923170
#define CXWnd__SetFont_x                                           0x9231E0
#define CXWnd__SetKeyTooltip_x                                     0x923D40
#define CXWnd__SetMouseOver_x                                      0x920C20
#define CXWnd__StartFade_x                                         0x9225F0
#define CXWnd__GetChildItem_x                                      0x923A20
#define CXWnd__SetParent_x                                         0x9224A0
#define CXWnd__Minimize_x                                          0x922E40

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x95A2A0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x926730
#define CXWndManager__DrawWindows_x                                0x926750
#define CXWndManager__GetKeyboardFlags_x                           0x928E60
#define CXWndManager__HandleKeyboardMsg_x                          0x928A10
#define CXWndManager__RemoveWnd_x                                  0x929090
#define CXWndManager__RemovePendingDeletionWnd_x                   0x929610

// CDBStr
#define CDBStr__GetString_x                                        0x547190

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BFED0
#define EQ_Character__Cur_HP_x                                     0x4D3020
#define EQ_Character__Cur_Mana_x                                   0x4DA720
#define EQ_Character__GetCastingTimeModifier_x                     0x4C2F40
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B3910
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3A60
#define EQ_Character__GetHPRegen_x                                 0x4E05F0
#define EQ_Character__GetEnduranceRegen_x                          0x4E0BF0
#define EQ_Character__GetManaRegen_x                               0x4E1030
#define EQ_Character__Max_Endurance_x                              0x65E650
#define EQ_Character__Max_HP_x                                     0x4D2E50
#define EQ_Character__Max_Mana_x                                   0x65E450
#define EQ_Character__doCombatAbility_x                            0x660A40
#define EQ_Character__UseSkill_x                                   0x4E2E30
#define EQ_Character__GetConLevel_x                                0x656D30
#define EQ_Character__IsExpansionFlag_x                            0x5BA1A0
#define EQ_Character__TotalEffect_x                                0x4C6CE0
#define EQ_Character__GetPCSpellAffect_x                           0x4C3C90
#define EQ_Character__SpellDuration_x                              0x4C37C0
#define EQ_Character__MySpellDuration_x                            0x4B2240
#define EQ_Character__GetAdjustedSkill_x                           0x4D5DA0
#define EQ_Character__GetBaseSkill_x                               0x4D6D40
#define EQ_Character__CanUseItem_x                                 0x4DAA30

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BD090

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x6749D0

//PcClient
#define PcClient__vftable_x                                        0xAF11C0
#define PcClient__PcClient_x                                       0x654490

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA900
#define CCharacterListWnd__EnterWorld_x                            0x4BA2D0
#define CCharacterListWnd__Quit_x                                  0x4BA020
#define CCharacterListWnd__UpdateList_x                            0x4BA4C0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x638A60
#define EQ_Item__CreateItemTagString_x                             0x896EF0
#define EQ_Item__IsStackable_x                                     0x89BB70
#define EQ_Item__GetImageNum_x                                     0x898A30
#define EQ_Item__CreateItemClient_x                                0x637CA0
#define EQ_Item__GetItemValue_x                                    0x899D30
#define EQ_Item__ValueSellMerchant_x                               0x89D4F0
#define EQ_Item__IsKeyRingItem_x                                   0x89B470
#define EQ_Item__CanGoInBag_x                                      0x638B80
#define EQ_Item__IsEmpty_x                                         0x89AFF0
#define EQ_Item__GetMaxItemCount_x                                 0x89A150
#define EQ_Item__GetHeldItem_x                                     0x898900
#define EQ_Item__GetAugmentFitBySlot_x                             0x896740

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x565CA0
#define EQ_LoadingS__Array_x                                       0xC12130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65EF50
#define EQ_PC__GetAlternateAbilityId_x                             0x8A6A00
#define EQ_PC__GetCombatAbility_x                                  0x8A7070
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A70E0
#define EQ_PC__GetItemRecastTimer_x                                0x660FC0
#define EQ_PC__HasLoreItem_x                                       0x6574F0
#define EQ_PC__AlertInventoryChanged_x                             0x656660
#define EQ_PC__GetPcZoneClient_x                                   0x683A10
#define EQ_PC__RemoveMyAffect_x                                    0x6641F0
#define EQ_PC__GetKeyRingItems_x                                   0x8A79B0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A7730
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A7CB0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5C0620
#define EQItemList__add_object_x                                   0x5EDDA0
#define EQItemList__add_item_x                                     0x5C0B80
#define EQItemList__delete_item_x                                  0x5C0BD0
#define EQItemList__FreeItemList_x                                 0x5C0AD0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x543CB0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x6762D0
#define EQPlayer__dEQPlayer_x                                      0x669650
#define EQPlayer__DoAttack_x                                       0x67E1B0
#define EQPlayer__EQPlayer_x                                       0x669D10
#define EQPlayer__SetNameSpriteState_x                             0x66DFE0
#define EQPlayer__SetNameSpriteTint_x                              0x66EEC0
#define PlayerBase__HasProperty_j_x                                0x988E10
#define EQPlayer__IsTargetable_x                                   0x9892B0
#define EQPlayer__CanSee_x                                         0x989110
#define EQPlayer__CanSee1_x                                        0x9891E0
#define PlayerBase__GetVisibilityLineSegment_x                     0x988ED0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x6814B0
#define PlayerZoneClient__GetLevel_x                               0x683A50
#define PlayerZoneClient__IsValidTeleport_x                        0x5EEF10
#define PlayerZoneClient__LegalPlayerRace_x                        0x55E970

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x6790B0
#define EQPlayerManager__GetSpawnByName_x                          0x679160
#define EQPlayerManager__GetPlayerFromPartialName_x                0x6791F0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63C280
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63C300
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63C340
#define KeypressHandler__ClearCommandStateArray_x                  0x63D730
#define KeypressHandler__HandleKeyDown_x                           0x63D750
#define KeypressHandler__HandleKeyUp_x                             0x63D7F0
#define KeypressHandler__SaveKeymapping_x                          0x63DC40

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7751D0
#define MapViewMap__SaveEx_x                                       0x778590
#define MapViewMap__SetZoom_x                                      0x77CC50

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BB100

// StringTable 
#define StringTable__getString_x                                   0x8B5F20

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x663E60
#define PcZoneClient__RemovePetEffect_x                            0x664490
#define PcZoneClient__HasAlternateAbility_x                        0x65E280
#define PcZoneClient__GetCurrentMod_x                              0x4E5F40
#define PcZoneClient__GetModCap_x                                  0x4E5E40
#define PcZoneClient__CanEquipItem_x                               0x65E930
#define PcZoneClient__GetItemByID_x                                0x661430
#define PcZoneClient__GetItemByItemClass_x                         0x661580
#define PcZoneClient__RemoveBuffEffect_x                           0x6644B0
#define PcZoneClient__BandolierSwap_x                              0x65F510
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x660F60

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F3A80

//IconCache
#define IconCache__GetIcon_x                                       0x716EC0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x70E9E0
#define CContainerMgr__CloseContainer_x                            0x70ECB0
#define CContainerMgr__OpenExperimentContainer_x                   0x70F730

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CD6D0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x630C20

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76B6C0
#define CLootWnd__RequestLootSlot_x                                0x76A9A0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58D3C0
#define EQ_Spell__SpellAffects_x                                   0x58D830
#define EQ_Spell__SpellAffectBase_x                                0x58D5F0
#define EQ_Spell__IsStackable_x                                    0x4CAA80
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CA870
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7BF0
#define EQ_Spell__IsSPAStacking_x                                  0x58E680
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58DB90
#define EQ_Spell__IsNoRemove_x                                     0x4CAA60
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58E690
#define __IsResEffectSpell_x                                       0x4C9D30

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD4E0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C5700

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x814400
#define CTargetWnd__WndNotification_x                              0x813C40
#define CTargetWnd__RefreshTargetBuffs_x                           0x813F10
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x812DB0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x818A70
#define CTaskWnd__ConfirmAbandonTask_x                             0x81B6A0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x541700
#define CTaskManager__HandleMessage_x                              0x53FB60
#define CTaskManager__GetTaskStatus_x                              0x5417B0
#define CTaskManager__GetElementDescription_x                      0x541830

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5884F0
#define EqSoundManager__PlayScriptMp3_x                            0x5887B0
#define EqSoundManager__SoundAssistPlay_x                          0x69C070
#define EqSoundManager__WaveInstancePlay_x                         0x69B5E0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x532AE0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x944B80
#define CTextureAnimation__Draw_x                                  0x944D80

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x940B10

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56D790
#define CAltAbilityData__GetMercMaxRank_x                          0x56D720
#define CAltAbilityData__GetMaxRank_x                              0x562BF0

//CTargetRing
#define CTargetRing__Cast_x                                        0x62ED40

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA850
#define CharacterBase__CreateItemGlobalIndex_x                     0x519670
#define CharacterBase__CreateItemIndex_x                           0x636E30
#define CharacterBase__GetItemPossession_x                         0x5054F0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CDD60
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CDDC0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F5AA0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F62D0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F6380

//messages
#define msg_spell_worn_off_x                                       0x5B21B0
#define msg_new_text_x                                             0x5A6B30
#define __msgTokenTextParam_x                                      0x5B4450
#define msgTokenText_x                                             0x5B46A0

//SpellManager
#define SpellManager__vftable_x                                    0xAD955C
#define SpellManager__SpellManager_x                               0x69F3A0
#define Spellmanager__LoadTextSpells_x                             0x69FC90
#define SpellManager__GetSpellByGroupAndRank_x                     0x69F570

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98CCD0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x519CC0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B8640
#define ItemGlobalIndex__IsEquippedLocation_x                      0x64FC00
#define ItemGlobalIndex__IsValidIndex_x                            0x519D50

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C60A0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C6320

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x763F90

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x7130D0
#define CCursorAttachment__AttachToCursor1_x                       0x713110
#define CCursorAttachment__Deactivate_x                            0x714100

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x9377D0
#define CSidlManagerBase__CreatePageWnd_x                          0x936FC0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x933250
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x9331E0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x954970
#define CEQSuiteTextureLoader__GetTexture_x                        0x954630

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x516BC0
#define CFindItemWnd__WndNotification_x                            0x5176A0
#define CFindItemWnd__Update_x                                     0x518210
#define CFindItemWnd__PickupSelectedItem_x                         0x5163F0

//IString
#define IString__Append_x                                          0x506D70

//Camera
#define CDisplay__cameraType_x                                     0xDEA2A0
#define EverQuest__Cameras_x                                       0xEA509C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51F5D0
#define LootFiltersManager__GetItemFilterData_x                    0x51EEE0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51EF10
#define LootFiltersManager__SetItemLootFilter_x                    0x51F130

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BB540

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x992940
#define CResolutionHandler__GetWindowedStyle_x                     0x696A70

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70B6A0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8DB670
#define CDistillerInfo__Instance_x                                 0x8DB610

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72A4A0
#define CGroupWnd__UpdateDisplay_x                                 0x7297F0

//ItemBase
#define ItemBase__IsLore_x                                         0x89B520
#define ItemBase__IsLoreEquipped_x                                 0x89B5A0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EDD00
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EDE40
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EDEA0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68C110
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x68FA80

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50D240

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F96A0
#define FactionManagerClient__HandleFactionMessage_x               0x4F9D10
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4FA310
#define FactionManagerClient__GetMaxFaction_x                      0x4FA32F
#define FactionManagerClient__GetMinFaction_x                      0x4FA2E0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x5054C0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91BEE0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C270

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x505780

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56CC20

//CTargetManager
#define CTargetManager__Get_x                                      0x6A2C00

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68C110

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A9060

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5C0A70

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF42734

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6BF420
#define CAAWnd__UpdateSelected_x                                   0x6BBCA0
#define CAAWnd__Update_x                                           0x6BE750

//CXRect
#define CXRect__operator_and_x                                     0x721580

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x483270

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
