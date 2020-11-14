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
#define __ExpectedVersionDate                                     "Nov 14 2020"
#define __ExpectedVersionTime                                     "04:17:13"
#define __ActualVersionDate_x                                      0xAF4544
#define __ActualVersionTime_x                                      0xAF4538
#define __ActualVersionBuild_x                                     0xAE2544

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x642DF0
#define __MemChecker1_x                                            0x8F6680
#define __MemChecker2_x                                            0x6B3590
#define __MemChecker3_x                                            0x6B34E0
#define __MemChecker4_x                                            0x84CA80
#define __EncryptPad0_x                                            0xC2A9C8
#define __EncryptPad1_x                                            0xC88210
#define __EncryptPad2_x                                            0xC3AD90
#define __EncryptPad3_x                                            0xC3A990
#define __EncryptPad4_x                                            0xC787A0
#define __EncryptPad5_x                                            0xF4A650
#define __AC1_x                                                    0x80B466
#define __AC2_x                                                    0x5FC4CF
#define __AC3_x                                                    0x603B20
#define __AC4_x                                                    0x607AD0
#define __AC5_x                                                    0x60DDCF
#define __AC6_x                                                    0x612286
#define __AC7_x                                                    0x5FBF40
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x19045C

// Direct Input
#define DI8__Main_x                                                0xF4A670
#define DI8__Keyboard_x                                            0xF4A674
#define DI8__Mouse_x                                               0xF4A688
#define DI8__Mouse_Copy_x                                          0xEA39DC
#define DI8__Mouse_Check_x                                         0xF481A4
#define __AutoSkillArray_x                                         0xEA48F8
#define __Attack_x                                                 0xF4272B
#define __Autofire_x                                               0xF4272C
#define __BindList_x                                               0xC193F8
#define g_eqCommandStates_x                                        0xC1A178
#define __Clicks_x                                                 0xEA3A94
#define __CommandList_x                                            0xC1AD38
#define __CurrentMapLabel_x                                        0xF5B14C
#define __CurrentSocial_x                                          0xC027C8
#define __DoAbilityList_x                                          0xEDA24C
#define __do_loot_x                                                0x5C8000
#define __DrawHandler_x                                            0x15DA140
#define __GroupCount_x                                             0xE9EA7A
#define __Guilds_x                                                 0xEA2918
#define __gWorld_x                                                 0xE9E924
#define __HWnd_x                                                   0xF4A68C
#define __heqmain_x                                                0xF4A638
#define __InChatMode_x                                             0xEA39C4
#define __LastTell_x                                               0xEA5948
#define __LMouseHeldTime_x                                         0xEA3B00
#define __Mouse_x                                                  0xF4A65C
#define __MouseLook_x                                              0xEA3A5A
#define __MouseEventTime_x                                         0xF4320C
#define __gpbCommandEvent_x                                        0xE9C3CC
#define __NetStatusToggle_x                                        0xEA3A5D
#define __PCNames_x                                                0xEA4EF4
#define __RangeAttackReady_x                                       0xEA4BDC
#define __RMouseHeldTime_x                                         0xEA3AFC
#define __RunWalkState_x                                           0xEA39C8
#define __ScreenMode_x                                             0xDEA1D8
#define __ScreenX_x                                                0xEA397C
#define __ScreenY_x                                                0xEA3978
#define __ScreenXMax_x                                             0xEA3980
#define __ScreenYMax_x                                             0xEA3984
#define __ServerHost_x                                             0xE9C59B
#define __ServerName_x                                             0xEDA20C
#define __ShiftKeyDown_x                                           0xEA4058
#define __ShowNames_x                                              0xEA4D98
#define EverQuestInfo__bSocialChanged_x                            0xEDA294
#define __Socials_x                                                0xEDA30C
#define __SubscriptionType_x                                       0xF9F410
#define __TargetAggroHolder_x                                      0xF5DB00
#define __ZoneType_x                                               0xEA3E58
#define __GroupAggro_x                                             0xF5DB40
#define __LoginName_x                                              0xF4ADCC
#define __Inviter_x                                                0xF426A8
#define __AttackOnAssist_x                                         0xEA4D54
#define __UseTellWindows_x                                         0xEA508C
#define __gfMaxZoomCameraDistance_x                                0xAEC160
#define __gfMaxCameraDistance_x                                    0xB14DF0
#define __pulAutoRun_x                                             0xEA3A78
#define __pulForward_x                                             0xEA50C4
#define __pulBackward_x                                            0xEA50C8
#define __pulTurnRight_x                                           0xEA50CC
#define __pulTurnLeft_x                                            0xEA50D0
#define __pulStrafeLeft_x                                          0xEA50D4
#define __pulStrafeRight_x                                         0xEA50D8

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE9ECB0
#define instEQZoneInfo_x                                           0xEA3C50
#define pinstActiveBanker_x                                        0xE9C8B8
#define pinstActiveCorpse_x                                        0xE9C8B0
#define pinstActiveGMaster_x                                       0xE9C8B4
#define pinstActiveMerchant_x                                      0xE9C8AC
#define pinstAltAdvManager_x                                       0xDEAEE0
#define pinstBandageTarget_x                                       0xE9C8C8
#define pinstCamActor_x                                            0xDEA1C8
#define pinstCDBStr_x                                              0xDE9BFC
#define pinstCDisplay_x                                            0xE9C914
#define pinstCEverQuest_x                                          0xF4A690
#define pinstEverQuestInfo_x                                       0xEA3970
#define pinstCharData_x                                            0xE9C3B8
#define pinstCharSpawn_x                                           0xE9C900
#define pinstControlledMissile_x                                   0xE9C910
#define pinstControlledPlayer_x                                    0xE9C900
#define pinstCResolutionHandler_x                                  0x15DA370
#define pinstCSidlManager_x                                        0x15D9308
#define pinstCXWndManager_x                                        0x15D9304
#define instDynamicZone_x                                          0xEA27F0
#define pinstDZMember_x                                            0xEA2900
#define pinstDZTimerInfo_x                                         0xEA2904
#define pinstEqLogin_x                                             0xF4A718
#define instEQMisc_x                                               0xDE9B40
#define pinstEQSoundManager_x                                      0xDEBEB0
#define pinstEQSpellStrings_x                                      0xCAC448
#define instExpeditionLeader_x                                     0xEA283A
#define instExpeditionName_x                                       0xEA287A
#define pinstGroup_x                                               0xE9EA76
#define pinstImeManager_x                                          0x15D9300
#define pinstLocalPlayer_x                                         0xE9C6A4
#define pinstMercenaryData_x                                       0xF44D00
#define pinstMercenaryStats_x                                      0xF5DBCC
#define pinstModelPlayer_x                                         0xE9C8C0
#define pinstPCData_x                                              0xE9C3B8
#define pinstSkillMgr_x                                            0xF46E68
#define pinstSpawnManager_x                                        0xF45910
#define pinstSpellManager_x                                        0xF470A8
#define pinstSpellSets_x                                           0xF3B354
#define pinstStringTable_x                                         0xE9C3C0
#define pinstSwitchManager_x                                       0xE9C250
#define pinstTarget_x                                              0xE9C8FC
#define pinstTargetObject_x                                        0xE9C908
#define pinstTargetSwitch_x                                        0xE9C91C
#define pinstTaskMember_x                                          0xDE99D0
#define pinstTrackTarget_x                                         0xE9C904
#define pinstTradeTarget_x                                         0xE9C8BC
#define instTributeActive_x                                        0xDE9B61
#define pinstViewActor_x                                           0xDEA1C4
#define pinstWorldData_x                                           0xE9C3B4
#define pinstZoneAddr_x                                            0xEA3EF0
#define pinstPlayerPath_x                                          0xF459A8
#define pinstTargetIndicator_x                                     0xF47310
#define EQObject_Top_x                                             0xE9C494
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDEA500
#define pinstCAchievementsWnd_x                                    0xDEA174
#define pinstCActionsWnd_x                                         0xDE9C9C
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDEA234
#define pinstCAdvancedLootWnd_x                                    0xDEA1E8
#define pinstCAdventureLeaderboardWnd_x                            0xF54920
#define pinstCAdventureRequestWnd_x                                0xF549D0
#define pinstCAdventureStatsWnd_x                                  0xF54A80
#define pinstCAggroMeterWnd_x                                      0xDEA21C
#define pinstCAlarmWnd_x                                           0xDEA1A0
#define pinstCAlertHistoryWnd_x                                    0xDEA4B4
#define pinstCAlertStackWnd_x                                      0xDEA204
#define pinstCAlertWnd_x                                           0xDEA218
#define pinstCAltStorageWnd_x                                      0xF54DE0
#define pinstCAudioTriggersWindow_x                                0xC9E778
#define pinstCAuraWnd_x                                            0xDEA1EC
#define pinstCAvaZoneWnd_x                                         0xDEA4B0
#define pinstCBandolierWnd_x                                       0xDEA230
#define pinstCBankWnd_x                                            0xDEA274
#define pinstCBarterMerchantWnd_x                                  0xF56020
#define pinstCBarterSearchWnd_x                                    0xF560D0
#define pinstCBarterWnd_x                                          0xF56180
#define pinstCBazaarConfirmationWnd_x                              0xDEA1B4
#define pinstCBazaarSearchWnd_x                                    0xDEA504
#define pinstCBazaarWnd_x                                          0xDEA180
#define pinstCBlockedBuffWnd_x                                     0xDEA1F8
#define pinstCBlockedPetBuffWnd_x                                  0xDEA220
#define pinstCBodyTintWnd_x                                        0xDEA128
#define pinstCBookWnd_x                                            0xDEA268
#define pinstCBreathWnd_x                                          0xDEA514
#define pinstCBuffWindowNORMAL_x                                   0xDEA1D4
#define pinstCBuffWindowSHORT_x                                    0xDEA1DC
#define pinstCBugReportWnd_x                                       0xDEA26C
#define pinstCButtonWnd_x                                          0x15D9570
#define pinstCCastingWnd_x                                         0xDEA25C
#define pinstCCastSpellWnd_x                                       0xDEA510
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDEA134
#define pinstCChatWindowManager_x                                  0xF56C40
#define pinstCClaimWnd_x                                           0xF56D98
#define pinstCColorPickerWnd_x                                     0xDEA4C8
#define pinstCCombatAbilityWnd_x                                   0xDEA190
#define pinstCCombatSkillsSelectWnd_x                              0xDEA148
#define pinstCCompassWnd_x                                         0xDE9D14
#define pinstCConfirmationDialog_x                                 0xF5BC98
#define pinstCContainerMgr_x                                       0xDEA124
#define pinstCContextMenuManager_x                                 0x15D92C0
#define pinstCCursorAttachment_x                                   0xDEA244
#define pinstCDynamicZoneWnd_x                                     0xF57360
#define pinstCEditLabelWnd_x                                       0xDEA1C0
#define pinstCEQMainWnd_x                                          0xF575A8
#define pinstCEventCalendarWnd_x                                   0xDEA508
#define pinstCExtendedTargetWnd_x                                  0xDEA200
#define pinstCFacePick_x                                           0xDEA14C
#define pinstCFactionWnd_x                                         0xDEA16C
#define pinstCFellowshipWnd_x                                      0xF577A8
#define pinstCFileSelectionWnd_x                                   0xDEA4C4
#define pinstCFindItemWnd_x                                        0xDEA15C
#define pinstCFindLocationWnd_x                                    0xF57900
#define pinstCFriendsWnd_x                                         0xDEA160
#define pinstCGemsGameWnd_x                                        0xDEA168
#define pinstCGiveWnd_x                                            0xDEA1A4
#define pinstCGroupSearchFiltersWnd_x                              0xDEA238
#define pinstCGroupSearchWnd_x                                     0xF57CF8
#define pinstCGroupWnd_x                                           0xF57DA8
#define pinstCGuildBankWnd_x                                       0xEA4D38
#define pinstCGuildCreationWnd_x                                   0xF57F08
#define pinstCGuildMgmtWnd_x                                       0xF57FB8
#define pinstCharacterCreation_x                                   0xDEA154
#define pinstCHelpWnd_x                                            0xDEA1A8
#define pinstCHeritageSelectionWnd_x                               0xDEA158
#define pinstCHotButtonWnd_x                                       0xF5A110
#define pinstCHotButtonWnd1_x                                      0xF5A110
#define pinstCHotButtonWnd2_x                                      0xF5A114
#define pinstCHotButtonWnd3_x                                      0xF5A118
#define pinstCHotButtonWnd4_x                                      0xF5A11C
#define pinstCIconSelectionWnd_x                                   0xDEA240
#define pinstCInspectWnd_x                                         0xDEA224
#define pinstCInventoryWnd_x                                       0xDEA1F0
#define pinstCInvSlotMgr_x                                         0xDEA4F4
#define pinstCItemDisplayManager_x                                 0xF5A6A0
#define pinstCItemExpTransferWnd_x                                 0xF5A7D4
#define pinstCItemOverflowWnd_x                                    0xDEA50C
#define pinstCJournalCatWnd_x                                      0xDEA4E0
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDEA4A0
#define pinstCKeyRingWnd_x                                         0xDEA24C
#define pinstCLargeDialogWnd_x                                     0xF5C918
#define pinstCLayoutCopyWnd_x                                      0xF5AB20
#define pinstCLFGuildWnd_x                                         0xF5ABD0
#define pinstCLoadskinWnd_x                                        0xDEA184
#define pinstCLootFiltersCopyWnd_x                                 0xCBAED8
#define pinstCLootFiltersWnd_x                                     0xDEA208
#define pinstCLootSettingsWnd_x                                    0xDEA22C
#define pinstCLootWnd_x                                            0xDEA4E4
#define pinstCMailAddressBookWnd_x                                 0xDEA4F8
#define pinstCMailCompositionWnd_x                                 0xDEA4D0
#define pinstCMailIgnoreListWnd_x                                  0xDEA4FC
#define pinstCMailWnd_x                                            0xDEA4D4
#define pinstCManageLootWnd_x                                      0xDEB390
#define pinstCMapToolbarWnd_x                                      0xDEA1B0
#define pinstCMapViewWnd_x                                         0xDEA178
#define pinstCMarketplaceWnd_x                                     0xDEA20C
#define pinstCMerchantWnd_x                                        0xDEA4F0
#define pinstCMIZoneSelectWnd_x                                    0xF5B408
#define pinstCMusicPlayerWnd_x                                     0xDEA4BC
#define pinstCNameChangeMercWnd_x                                  0xDEA1AC
#define pinstCNameChangePetWnd_x                                   0xDEA17C
#define pinstCNameChangeWnd_x                                      0xDEA1BC
#define pinstCNoteWnd_x                                            0xDEA188
#define pinstCObjectPreviewWnd_x                                   0xDEA228
#define pinstCOptionsWnd_x                                         0xDEA194
#define pinstCPetInfoWnd_x                                         0xDEA4B8
#define pinstCPetitionQWnd_x                                       0xDEA144
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDEA12C
#define pinstCPlayerWnd_x                                          0xDEA4AC
#define pinstCPopupWndManager_x                                    0xF5BC98
#define pinstCProgressionSelectionWnd_x                            0xF5BD48
#define pinstCPurchaseGroupWnd_x                                   0xDEA280
#define pinstCPurchaseWnd_x                                        0xDEA260
#define pinstCPvPLeaderboardWnd_x                                  0xF5BDF8
#define pinstCPvPStatsWnd_x                                        0xF5BEA8
#define pinstCQuantityWnd_x                                        0xDEA49C
#define pinstCRaceChangeWnd_x                                      0xDEA1F4
#define pinstCRaidOptionsWnd_x                                     0xDEA23C
#define pinstCRaidWnd_x                                            0xDEA4EC
#define pinstCRealEstateItemsWnd_x                                 0xDEA170
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDE9D18
#define pinstCRealEstateManageWnd_x                                0xDEA284
#define pinstCRealEstateNeighborhoodWnd_x                          0xDEA4A8
#define pinstCRealEstatePlotSearchWnd_x                            0xDEA4C0
#define pinstCRealEstatePurchaseWnd_x                              0xDEA4DC
#define pinstCRespawnWnd_x                                         0xDEA214
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDEA140
#define pinstCSendMoneyWnd_x                                       0xDEA1B8
#define pinstCServerListWnd_x                                      0xDEA4E8
#define pinstCSkillsSelectWnd_x                                    0xDEA13C
#define pinstCSkillsWnd_x                                          0xDE9D1C
#define pinstCSocialEditWnd_x                                      0xDEA248
#define pinstCSocialWnd_x                                          0xDEA198
#define pinstCSpellBookWnd_x                                       0xDEA18C
#define pinstCStoryWnd_x                                           0xDE9C98
#define pinstCTargetOfTargetWnd_x                                  0xF5DC50
#define pinstCTargetWnd_x                                          0xDEA210
#define pinstCTaskOverlayWnd_x                                     0xDEA278
#define pinstCTaskSelectWnd_x                                      0xF5DDA8
#define pinstCTaskManager_x                                        0xCBB818
#define pinstCTaskTemplateSelectWnd_x                              0xF5DE58
#define pinstCTaskWnd_x                                            0xF5DF08
#define pinstCTextEntryWnd_x                                       0xDEA264
#define pinstCTimeLeftWnd_x                                        0xDEA138
#define pinstCTipWndCONTEXT_x                                      0xF5E10C
#define pinstCTipWndOFDAY_x                                        0xF5E108
#define pinstCTitleWnd_x                                           0xF5E1B8
#define pinstCTrackingWnd_x                                        0xDEA1FC
#define pinstCTradeskillWnd_x                                      0xF5E320
#define pinstCTradeWnd_x                                           0xDEA130
#define pinstCTrainWnd_x                                           0xDEA4D8
#define pinstCTributeBenefitWnd_x                                  0xF5E520
#define pinstCTributeMasterWnd_x                                   0xF5E5D0
#define pinstCTributeTrophyWnd_x                                   0xF5E680
#define pinstCVideoModesWnd_x                                      0xDEA288
#define pinstCVoiceMacroWnd_x                                      0xF478C8
#define pinstCVoteResultsWnd_x                                     0xDEA164
#define pinstCVoteWnd_x                                            0xDEA150
#define pinstCWebManager_x                                         0xF47F44
#define pinstCZoneGuideWnd_x                                       0xDEA27C
#define pinstCZonePathWnd_x                                        0xDEA498

#define pinstEQSuiteTextureLoader_x                                0xC88B30
#define pinstItemIconCache_x                                       0xF57560
#define pinstLootFiltersManager_x                                  0xCBAF88
#define pinstRewardSelectionWnd_x                                  0xF5C5F0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5C36F0
#define __CastRay2_x                                               0x5C3740
#define __ConvertItemTags_x                                        0x5DF400
#define __CleanItemTags_x                                          0x47D290
#define __DoesFileExist_x                                          0x8F9760
#define __EQGetTime_x                                              0x8F62B0
#define __ExecuteCmd_x                                             0x5BC010
#define __FixHeading_x                                             0x98ABA0
#define __FlushDxKeyboard_x                                        0x6AF430
#define __GameLoop_x                                               0x6B2760
#define __get_bearing_x                                            0x5C3250
#define __get_melee_range_x                                        0x5C3930
#define __GetAnimationCache_x                                      0x717B90
#define __GetGaugeValueFromEQ_x                                    0x809910
#define __GetLabelFromEQ_x                                         0x80B3F0
#define __GetXTargetType_x                                         0x98C5F0
#define __HandleMouseWheel_x                                       0x6B3640
#define __HeadingDiff_x                                            0x98AC10
#define __HelpPath_x                                               0xF42DFC
#define __LoadFrontEnd_x                                           0x6AFA70
#define __NewUIINI_x                                               0x8095E0
#define __ProcessGameEvents_x                                      0x624160
#define __ProcessMouseEvent_x                                      0x6238F0
#define __SaveColors_x                                             0x55C960
#define __STMLToText_x                                             0x92DFE0
#define __ToggleKeyRingItem_x                                      0x51B120
#define CMemoryMappedFile__SetFile_x                               0xA79FA0
#define CrashDetected_x                                            0x6B1520
#define DrawNetStatus_x                                            0x6501C0
#define Expansion_HoT_x                                            0xEA4D40
#define Teleport_Table_Size_x                                      0xE9C454
#define Teleport_Table_x                                           0xE9C920
#define Util__FastTime_x                                           0x8F5E80
#define __CopyLayout_x                                             0x63E490
#define __WndProc_x                                                0x6B1A20
#define __ProcessKeyboardEvent_x                                   0x6B0FC0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490610
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499610
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4993E0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493BB0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x493000

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x564AC0
#define AltAdvManager__IsAbilityReady_x                            0x563860
#define AltAdvManager__GetAAById_x                                 0x563BF0
#define AltAdvManager__CanTrainAbility_x                           0x563C60
#define AltAdvManager__CanSeeAbility_x                             0x563FC0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CB280
#define CharacterZoneClient__HasSkill_x                            0x4D6100
#define CharacterZoneClient__MakeMeVisible_x                       0x4D7820
#define CharacterZoneClient__IsStackBlocked_x                      0x4C2A10
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBEA0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4DA1B0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4DA290
#define CharacterZoneClient__GetCursorItemCount_x                  0x4DA370
#define CharacterZoneClient__FindAffectSlot_x                      0x4C4B00
#define CharacterZoneClient__BardCastBard_x                        0x4C7530
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF8B0
#define CharacterZoneClient__GetEffect_x                           0x4BBDE0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C5B70
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C5C40
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C5C90
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5DE0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5FC0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3DD0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D8780
#define CharacterZoneClient__FindItemByRecord_x                    0x4D8200

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D92B0
#define CBankWnd__WndNotification_x                                0x6D9090

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E6CD0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x92B7C0
#define CButtonWnd__CButtonWnd_x                                   0x92A390

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x706D50
#define CChatManager__InitContextMenu_x                            0x6FFE80
#define CChatManager__FreeChatWindow_x                             0x705890
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9B10
#define CChatManager__SetLockedActiveChatWindow_x                  0x7069D0
#define CChatManager__CreateChatWindow_x                           0x705ED0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9C20

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x93E920
#define CContextMenu__dCContextMenu_x                              0x93EB60
#define CContextMenu__AddMenuItem_x                                0x93EB70
#define CContextMenu__RemoveMenuItem_x                             0x93EE80
#define CContextMenu__RemoveAllMenuItems_x                         0x93EEA0
#define CContextMenu__CheckMenuItem_x                              0x93EF20
#define CContextMenu__SetMenuItem_x                                0x93EDA0
#define CContextMenu__AddSeparator_x                               0x93ED00

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x93F4B0
#define CContextMenuManager__RemoveMenu_x                          0x93F520
#define CContextMenuManager__PopupMenu_x                           0x93F5E0
#define CContextMenuManager__Flush_x                               0x93F450
#define CContextMenuManager__GetMenu_x                             0x49B970
#define CContextMenuManager__CreateDefaultMenu_x                   0x7124E0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D1120
#define CChatService__GetFriendName_x                              0x8D1130

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x7075C0
#define CChatWindow__Clear_x                                       0x708890
#define CChatWindow__WndNotification_x                             0x709020
#define CChatWindow__AddHistory_x                                  0x708150

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93BD70
#define CComboWnd__Draw_x                                          0x93B260
#define CComboWnd__GetCurChoice_x                                  0x93BBB0
#define CComboWnd__GetListRect_x                                   0x93B710
#define CComboWnd__GetTextRect_x                                   0x93BDE0
#define CComboWnd__InsertChoice_x                                  0x93B8A0
#define CComboWnd__SetColors_x                                     0x93B870
#define CComboWnd__SetChoice_x                                     0x93BB80
#define CComboWnd__GetItemCount_x                                  0x93BBC0
#define CComboWnd__GetCurChoiceText_x                              0x93BC00
#define CComboWnd__GetChoiceText_x                                 0x93BBD0
#define CComboWnd__InsertChoiceAtIndex_x                           0x93B940

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x70FEF0
#define CContainerWnd__vftable_x                                   0xAFD73C
#define CContainerWnd__SetContainer_x                              0x711440

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x5572C0
#define CDisplay__PreZoneMainUI_x                                  0x5572D0
#define CDisplay__CleanGameUI_x                                    0x55C720
#define CDisplay__GetClickedActor_x                                0x54F720
#define CDisplay__GetUserDefinedColor_x                            0x547D90
#define CDisplay__GetWorldFilePath_x                               0x551190
#define CDisplay__is3dON_x                                         0x54C380
#define CDisplay__ReloadUI_x                                       0x5567D0
#define CDisplay__WriteTextHD2_x                                   0x54C170
#define CDisplay__TrueDistance_x                                   0x552E50
#define CDisplay__SetViewActor_x                                   0x54F040
#define CDisplay__GetFloorHeight_x                                 0x54C440
#define CDisplay__SetRenderWindow_x                                0x54ADC0
#define CDisplay__ToggleScreenshotMode_x                           0x54EB10

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x95E7B0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x941E10
#define CEditWnd__EnsureCaretVisible_x                             0x943FE0
#define CEditWnd__GetCaretPt_x                                     0x942F90
#define CEditWnd__GetCharIndexPt_x                                 0x942D40
#define CEditWnd__GetDisplayString_x                               0x942BE0
#define CEditWnd__GetHorzOffset_x                                  0x9414B0
#define CEditWnd__GetLineForPrintableChar_x                        0x943EE0
#define CEditWnd__GetSelStartPt_x                                  0x942FF0
#define CEditWnd__GetSTMLSafeText_x                                0x942A00
#define CEditWnd__PointFromPrintableChar_x                         0x943B10
#define CEditWnd__SelectableCharFromPoint_x                        0x943C80
#define CEditWnd__SetEditable_x                                    0x9430C0
#define CEditWnd__SetWindowTextA_x                                 0x942780
#define CEditWnd__ReplaceSelection_x                               0x943780
#define CEditWnd__ReplaceSelection1_x                              0x943700

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x611760
#define CEverQuest__ClickedPlayer_x                                0x603900
#define CEverQuest__CreateTargetIndicator_x                        0x6212D0
#define CEverQuest__DeleteTargetIndicator_x                        0x621360
#define CEverQuest__DoTellWindow_x                                 0x4E9D00
#define CEverQuest__OutputTextToLog_x                              0x4E9FD0
#define CEverQuest__DropHeldItemOnGround_x                         0x5F8A60
#define CEverQuest__dsp_chat_x                                     0x4EA360
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
#define CGaugeWnd__CalcFillRect_x                                  0x721E50
#define CGaugeWnd__CalcLinesFillRect_x                             0x721EB0
#define CGaugeWnd__Draw_x                                          0x7214D0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4B0150
#define CGuild__GetGuildName_x                                     0x4AEC00
#define CGuild__GetGuildIndex_x                                    0x4AF200

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73BAF0

//CHotButton
#define CHotButton__SetCheck_x                                     0x632920
#define CHotButton__SetButtonSize_x                                0x632CE0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x748BC0
#define CInvSlotMgr__MoveItem_x                                    0x7478D0
#define CInvSlotMgr__SelectSlot_x                                  0x748C90

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7460C0
#define CInvSlot__SliderComplete_x                                 0x743E00
#define CInvSlot__GetItemBase_x                                    0x743780
#define CInvSlot__UpdateItem_x                                     0x7438F0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x74A720
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7498B0
#define CInvSlotWnd__HandleLButtonUp_x                             0x74A2A0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x804C80
#define CItemDisplayWnd__UpdateStrings_x                           0x758ED0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x752B90
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x7530B0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x7594D0
#define CItemDisplayWnd__AboutToShow_x                             0x758B10
#define CItemDisplayWnd__WndNotification_x                         0x75A720
#define CItemDisplayWnd__RequestConvertItem_x                      0x75A070
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x757B70
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x758930

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8356C0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75EC30

// CLabel 
#define CLabel__Draw_x                                             0x7646C0

// CListWnd
#define CListWnd__CListWnd_x                                       0x914550
#define CListWnd__dCListWnd_x                                      0x914870
#define CListWnd__AddColumn_x                                      0x918D00
#define CListWnd__AddColumn1_x                                     0x918D50
#define CListWnd__AddLine_x                                        0x9190E0
#define CListWnd__AddString_x                                      0x918EE0
#define CListWnd__CalculateFirstVisibleLine_x                      0x918AC0
#define CListWnd__CalculateVSBRange_x                              0x9188A0
#define CListWnd__ClearSel_x                                       0x9198C0
#define CListWnd__ClearAllSel_x                                    0x919920
#define CListWnd__CloseAndUpdateEditWindow_x                       0x91A340
#define CListWnd__Compare_x                                        0x9181D0
#define CListWnd__Draw_x                                           0x9149A0
#define CListWnd__DrawColumnSeparators_x                           0x9171A0
#define CListWnd__DrawHeader_x                                     0x917610
#define CListWnd__DrawItem_x                                       0x917B10
#define CListWnd__DrawLine_x                                       0x917310
#define CListWnd__DrawSeparator_x                                  0x917240
#define CListWnd__EnableLine_x                                     0x916A70
#define CListWnd__EnsureVisible_x                                  0x91A260
#define CListWnd__ExtendSel_x                                      0x9197F0
#define CListWnd__GetColumnTooltip_x                               0x9165B0
#define CListWnd__GetColumnMinWidth_x                              0x916620
#define CListWnd__GetColumnWidth_x                                 0x916520
#define CListWnd__GetCurSel_x                                      0x915EB0
#define CListWnd__GetItemAtPoint_x                                 0x916CF0
#define CListWnd__GetItemAtPoint1_x                                0x916D60
#define CListWnd__GetItemData_x                                    0x915F30
#define CListWnd__GetItemHeight_x                                  0x9162F0
#define CListWnd__GetItemIcon_x                                    0x9160C0
#define CListWnd__GetItemRect_x                                    0x916B60
#define CListWnd__GetItemText_x                                    0x915F70
#define CListWnd__GetSelList_x                                     0x919970
#define CListWnd__GetSeparatorRect_x                               0x916FA0
#define CListWnd__InsertLine_x                                     0x9194D0
#define CListWnd__RemoveLine_x                                     0x919620
#define CListWnd__SetColors_x                                      0x918870
#define CListWnd__SetColumnJustification_x                         0x9185A0
#define CListWnd__SetColumnLabel_x                                 0x918E80
#define CListWnd__SetColumnWidth_x                                 0x9184C0
#define CListWnd__SetCurSel_x                                      0x919730
#define CListWnd__SetItemColor_x                                   0x919F10
#define CListWnd__SetItemData_x                                    0x919ED0
#define CListWnd__SetItemText_x                                    0x919AE0
#define CListWnd__ShiftColumnSeparator_x                           0x918660
#define CListWnd__Sort_x                                           0x918350
#define CListWnd__ToggleSel_x                                      0x919760
#define CListWnd__SetColumnsSizable_x                              0x918710
#define CListWnd__SetItemWnd_x                                     0x919D90
#define CListWnd__GetItemWnd_x                                     0x916110
#define CListWnd__SetItemIcon_x                                    0x919B60
#define CListWnd__CalculateCustomWindowPositions_x                 0x918BC0
#define CListWnd__SetVScrollPos_x                                  0x9184A0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x779DB0
#define CMapViewWnd__GetWorldCoordinates_x                         0x7784C0
#define CMapViewWnd__HandleLButtonDown_x                           0x775500

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x79A2C0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79ABA0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79B0D0
#define CMerchantWnd__SelectRecoverySlot_x                         0x79E080
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x798E30
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A3C50
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x799EE0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89EA10
#define CPacketScrambler__hton_x                                   0x89EA00

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x9335C0
#define CSidlManager__FindScreenPieceTemplate_x                    0x9339D0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9337C0
#define CSidlManager__CreateLabel_x                                0x7FBDE0
#define CSidlManager__CreateXWndFromTemplate_x                     0x936930
#define CSidlManager__CreateXWndFromTemplate1_x                    0x936B10
#define CSidlManager__CreateXWnd_x                                 0x7FBD10
#define CSidlManager__CreateHotButtonWnd_x                         0x7FC2E0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9300A0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x92FFA0
#define CSidlScreenWnd__ConvertToRes_x                             0x959250
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x92FA90
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x92F780
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x92F850
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x92F920
#define CSidlScreenWnd__DrawSidlPiece_x                            0x930540
#define CSidlScreenWnd__EnableIniStorage_x                         0x930A10
#define CSidlScreenWnd__GetSidlPiece_x                             0x930730
#define CSidlScreenWnd__Init1_x                                    0x92F380
#define CSidlScreenWnd__LoadIniInfo_x                              0x930A60
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9315A0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92E790
#define CSidlScreenWnd__StoreIniInfo_x                             0x931120
#define CSidlScreenWnd__StoreIniVis_x                              0x931480
#define CSidlScreenWnd__WndNotification_x                          0x930450
#define CSidlScreenWnd__GetChildItem_x                             0x930990
#define CSidlScreenWnd__HandleLButtonUp_x                          0x920180
#define CSidlScreenWnd__m_layoutCopy_x                             0x15D9190

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6984E0
#define CSkillMgr__GetSkillCap_x                                   0x6986C0
#define CSkillMgr__GetNameToken_x                                  0x697C60
#define CSkillMgr__IsActivatedSkill_x                              0x697DA0
#define CSkillMgr__IsCombatSkill_x                                 0x697CE0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x940290
#define CSliderWnd__SetValue_x                                     0x940100
#define CSliderWnd__SetNumTicks_x                                  0x940160

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x801FC0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x948BE0
#define CStmlWnd__ParseSTML_x                                      0x949EF0
#define CStmlWnd__CalculateHSBRange_x                              0x949CC0
#define CStmlWnd__CalculateVSBRange_x                              0x949C30
#define CStmlWnd__CanBreakAtCharacter_x                            0x94E000
#define CStmlWnd__FastForwardToEndOfTag_x                          0x94EC90
#define CStmlWnd__ForceParseNow_x                                  0x949180
#define CStmlWnd__GetNextTagPiece_x                                0x94DF60
#define CStmlWnd__GetSTMLText_x                                    0x50C950
#define CStmlWnd__GetVisibleText_x                                 0x9491A0
#define CStmlWnd__InitializeWindowVariables_x                      0x94EAE0
#define CStmlWnd__MakeStmlColorTag_x                               0x948250
#define CStmlWnd__MakeWndNotificationTag_x                         0x9482C0
#define CStmlWnd__SetSTMLText_x                                    0x947300
#define CStmlWnd__StripFirstSTMLLines_x                            0x94FD90
#define CStmlWnd__UpdateHistoryString_x                            0x94EEA0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x946450
#define CTabWnd__DrawCurrentPage_x                                 0x946B80
#define CTabWnd__DrawTab_x                                         0x9468A0
#define CTabWnd__GetCurrentPage_x                                  0x945C50
#define CTabWnd__GetPageInnerRect_x                                0x945E90
#define CTabWnd__GetTabInnerRect_x                                 0x945DD0
#define CTabWnd__GetTabRect_x                                      0x945C80
#define CTabWnd__InsertPage_x                                      0x9460A0
#define CTabWnd__RemovePage_x                                      0x946210
#define CTabWnd__SetPage_x                                         0x945F10
#define CTabWnd__SetPageRect_x                                     0x946390
#define CTabWnd__UpdatePage_x                                      0x946760
#define CTabWnd__GetPageFromTabIndex_x                             0x9467E0
#define CTabWnd__GetCurrentTabIndex_x                              0x945C40

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x75F040
#define CPageWnd__SetTabText_x                                     0x945790
#define CPageWnd__FlashTab_x                                       0x9457F0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9410

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91D040
#define CTextureFont__GetTextExtent_x                              0x91D200

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AC610
#define CHtmlComponentWnd__ValidateUri_x                           0x73D4E0
#define CHtmlWnd__SetClientCallbacks_x                             0x637D70
#define CHtmlWnd__AddObserver_x                                    0x637D90
#define CHtmlWnd__RemoveObserver_x                                 0x637DF0
#define Window__getProgress_x                                      0x854050
#define Window__getStatus_x                                        0x854070
#define Window__getURI_x                                           0x854080

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x956060

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x90A140

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9A00
#define CXStr__CXStr1_x                                            0x9E13B0
#define CXStr__CXStr3_x                                            0x8F2270
#define CXStr__dCXStr_x                                            0x4784C0
#define CXStr__operator_equal_x                                    0x8F24A0
#define CXStr__operator_equal1_x                                   0x8F24E0
#define CXStr__operator_plus_equal1_x                              0x8F2F70
#define CXStr__SetString_x                                         0x8F4E60
#define CXStr__operator_char_p_x                                   0x8F29E0
#define CXStr__GetChar_x                                           0x8F4790
#define CXStr__Delete_x                                            0x8F4060
#define CXStr__GetUnicode_x                                        0x8F4800
#define CXStr__GetLength_x                                         0x4A91C0
#define CXStr__Mid_x                                               0x47D640
#define CXStr__Insert_x                                            0x8F4860
#define CXStr__FindNext_x                                          0x8F44D0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93E530
#define CXWnd__BringToTop_x                                        0x923990
#define CXWnd__Center_x                                            0x923510
#define CXWnd__ClrFocus_x                                          0x923320
#define CXWnd__Destroy_x                                           0x9233D0
#define CXWnd__DoAllDrawing_x                                      0x91F910
#define CXWnd__DrawChildren_x                                      0x91F8E0
#define CXWnd__DrawColoredRect_x                                   0x91FD70
#define CXWnd__DrawTooltip_x                                       0x91E450
#define CXWnd__DrawTooltipAtPoint_x                                0x91E510
#define CXWnd__GetBorderFrame_x                                    0x91FBD0
#define CXWnd__GetChildWndAt_x                                     0x923A30
#define CXWnd__GetClientClipRect_x                                 0x921BA0
#define CXWnd__GetScreenClipRect_x                                 0x921C50
#define CXWnd__GetScreenRect_x                                     0x921E00
#define CXWnd__GetRelativeRect_x                                   0x921ED0
#define CXWnd__GetTooltipRect_x                                    0x91FDC0
#define CXWnd__GetWindowTextA_x                                    0x49D070
#define CXWnd__IsActive_x                                          0x920500
#define CXWnd__IsDescendantOf_x                                    0x922830
#define CXWnd__IsReallyVisible_x                                   0x922860
#define CXWnd__IsType_x                                            0x9240B0
#define CXWnd__Move_x                                              0x9228D0
#define CXWnd__Move1_x                                             0x922990
#define CXWnd__ProcessTransition_x                                 0x9234C0
#define CXWnd__Refade_x                                            0x922C70
#define CXWnd__Resize_x                                            0x922F40
#define CXWnd__Right_x                                             0x923750
#define CXWnd__SetFocus_x                                          0x9232E0
#define CXWnd__SetFont_x                                           0x923350
#define CXWnd__SetKeyTooltip_x                                     0x923EC0
#define CXWnd__SetMouseOver_x                                      0x920D40
#define CXWnd__StartFade_x                                         0x922710
#define CXWnd__GetChildItem_x                                      0x923BA0
#define CXWnd__SetParent_x                                         0x9225C0
#define CXWnd__Minimize_x                                          0x922FB0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x95A2D0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9268F0
#define CXWndManager__DrawWindows_x                                0x926910
#define CXWndManager__GetKeyboardFlags_x                           0x929010
#define CXWndManager__HandleKeyboardMsg_x                          0x928BC0
#define CXWndManager__RemoveWnd_x                                  0x929240
#define CXWndManager__RemovePendingDeletionWnd_x                   0x9297B0

// CDBStr
#define CDBStr__GetString_x                                        0x546D30

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4C0010
#define EQ_Character__Cur_HP_x                                     0x4D3140
#define EQ_Character__Cur_Mana_x                                   0x4DA870
#define EQ_Character__GetCastingTimeModifier_x                     0x4C3080
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B3A10
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3B60
#define EQ_Character__GetHPRegen_x                                 0x4E0750
#define EQ_Character__GetEnduranceRegen_x                          0x4E0D50
#define EQ_Character__GetManaRegen_x                               0x4E1190
#define EQ_Character__Max_Endurance_x                              0x65EAD0
#define EQ_Character__Max_HP_x                                     0x4D2F70
#define EQ_Character__Max_Mana_x                                   0x65E8D0
#define EQ_Character__doCombatAbility_x                            0x660EC0
#define EQ_Character__UseSkill_x                                   0x4E2FA0
#define EQ_Character__GetConLevel_x                                0x6570C0
#define EQ_Character__IsExpansionFlag_x                            0x5BA7C0
#define EQ_Character__TotalEffect_x                                0x4C6E20
#define EQ_Character__GetPCSpellAffect_x                           0x4C3DD0
#define EQ_Character__SpellDuration_x                              0x4C3900
#define EQ_Character__MySpellDuration_x                            0x4B2340
#define EQ_Character__GetAdjustedSkill_x                           0x4D5EC0
#define EQ_Character__GetBaseSkill_x                               0x4D6E60
#define EQ_Character__CanUseItem_x                                 0x4DAB80

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BE100

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x674D80

//PcClient
#define PcClient__vftable_x                                        0xAF11C8
#define PcClient__PcClient_x                                       0x654830

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BAA70
#define CCharacterListWnd__EnterWorld_x                            0x4BA440
#define CCharacterListWnd__Quit_x                                  0x4BA190
#define CCharacterListWnd__UpdateList_x                            0x4BA630

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x638F60
#define EQ_Item__CreateItemTagString_x                             0x897F90
#define EQ_Item__IsStackable_x                                     0x89CC40
#define EQ_Item__GetImageNum_x                                     0x899B30
#define EQ_Item__CreateItemClient_x                                0x638190
#define EQ_Item__GetItemValue_x                                    0x89AE40
#define EQ_Item__ValueSellMerchant_x                               0x89E5F0
#define EQ_Item__IsKeyRingItem_x                                   0x89C560
#define EQ_Item__CanGoInBag_x                                      0x639080
#define EQ_Item__IsEmpty_x                                         0x89C0A0
#define EQ_Item__GetMaxItemCount_x                                 0x89B250
#define EQ_Item__GetHeldItem_x                                     0x899A00
#define EQ_Item__GetAugmentFitBySlot_x                             0x897800

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x565810
#define EQ_LoadingS__Array_x                                       0xC12128

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65F3D0
#define EQ_PC__GetAlternateAbilityId_x                             0x8A7A70
#define EQ_PC__GetCombatAbility_x                                  0x8A80E0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A8150
#define EQ_PC__GetItemRecastTimer_x                                0x661440
#define EQ_PC__HasLoreItem_x                                       0x6578E0
#define EQ_PC__AlertInventoryChanged_x                             0x656A00
#define EQ_PC__GetPcZoneClient_x                                   0x683E60
#define EQ_PC__RemoveMyAffect_x                                    0x664670
#define EQ_PC__GetKeyRingItems_x                                   0x8A8A20
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A87A0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A8D20

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5C0C70
#define EQItemList__add_object_x                                   0x5EE2A0
#define EQItemList__add_item_x                                     0x5C11D0
#define EQItemList__delete_item_x                                  0x5C1220
#define EQItemList__FreeItemList_x                                 0x5C1120

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x5438F0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x676680
#define EQPlayer__dEQPlayer_x                                      0x669A10
#define EQPlayer__DoAttack_x                                       0x67E5F0
#define EQPlayer__EQPlayer_x                                       0x66A0D0
#define EQPlayer__SetNameSpriteState_x                             0x66E390
#define EQPlayer__SetNameSpriteTint_x                              0x66F270
#define PlayerBase__HasProperty_j_x                                0x988F60
#define EQPlayer__IsTargetable_x                                   0x989400
#define EQPlayer__CanSee_x                                         0x989260
#define EQPlayer__CanSee1_x                                        0x989330
#define PlayerBase__GetVisibilityLineSegment_x                     0x989020

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x6818F0
#define PlayerZoneClient__GetLevel_x                               0x683EA0
#define PlayerZoneClient__IsValidTeleport_x                        0x5EF420
#define PlayerZoneClient__LegalPlayerRace_x                        0x55E590

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x6794F0
#define EQPlayerManager__GetSpawnByName_x                          0x6795A0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x679630

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63C6F0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63C770
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63C7B0
#define KeypressHandler__ClearCommandStateArray_x                  0x63DBA0
#define KeypressHandler__HandleKeyDown_x                           0x63DBC0
#define KeypressHandler__HandleKeyUp_x                             0x63DC60
#define KeypressHandler__SaveKeymapping_x                          0x63E0B0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x775C20
#define MapViewMap__SaveEx_x                                       0x778FE0
#define MapViewMap__SetZoom_x                                      0x77D6A0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BC160

// StringTable 
#define StringTable__getString_x                                   0x8B6F80

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x6642E0
#define PcZoneClient__RemovePetEffect_x                            0x664910
#define PcZoneClient__HasAlternateAbility_x                        0x65E700
#define PcZoneClient__GetCurrentMod_x                              0x4E60C0
#define PcZoneClient__GetModCap_x                                  0x4E5FC0
#define PcZoneClient__CanEquipItem_x                               0x65EDB0
#define PcZoneClient__GetItemByID_x                                0x6618B0
#define PcZoneClient__GetItemByItemClass_x                         0x661A00
#define PcZoneClient__RemoveBuffEffect_x                           0x664930
#define PcZoneClient__BandolierSwap_x                              0x65F990
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x6613E0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F3FB0

//IconCache
#define IconCache__GetIcon_x                                       0x717590

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x70F090
#define CContainerMgr__CloseContainer_x                            0x70F360
#define CContainerMgr__OpenExperimentContainer_x                   0x70FDE0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CE5B0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x631100

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76C150
#define CLootWnd__RequestLootSlot_x                                0x76B420

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58D410
#define EQ_Spell__SpellAffects_x                                   0x58D880
#define EQ_Spell__SpellAffectBase_x                                0x58D640
#define EQ_Spell__IsStackable_x                                    0x4CAB70
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CA990
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7CD0
#define EQ_Spell__IsSPAStacking_x                                  0x58E6D0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58DBE0
#define EQ_Spell__IsNoRemove_x                                     0x4CAB50
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58E6E0
#define __IsResEffectSpell_x                                       0x4C9E50

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD690

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C6740

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x815390
#define CTargetWnd__WndNotification_x                              0x814BD0
#define CTargetWnd__RefreshTargetBuffs_x                           0x814EA0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x813D40

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x819A00
#define CTaskWnd__ConfirmAbandonTask_x                             0x81C640

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x5412B0
#define CTaskManager__HandleMessage_x                              0x53F720
#define CTaskManager__GetTaskStatus_x                              0x541360
#define CTaskManager__GetElementDescription_x                      0x5413E0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x588430
#define EqSoundManager__PlayScriptMp3_x                            0x5886F0
#define EqSoundManager__SoundAssistPlay_x                          0x69C3D0
#define EqSoundManager__WaveInstancePlay_x                         0x69B940

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x5326B0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x944CA0
#define CTextureAnimation__Draw_x                                  0x944EA0

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x940BF0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56D330
#define CAltAbilityData__GetMercMaxRank_x                          0x56D2C0
#define CAltAbilityData__GetMaxRank_x                              0x5626E0

//CTargetRing
#define CTargetRing__Cast_x                                        0x62F210

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA970
#define CharacterBase__CreateItemGlobalIndex_x                     0x5192A0
#define CharacterBase__CreateItemIndex_x                           0x637320
#define CharacterBase__GetItemPossession_x                         0x5053D0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CEDB0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CEE10
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F6090
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F68C0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F6970

//messages
#define msg_spell_worn_off_x                                       0x5B2760
#define msg_new_text_x                                             0x5A70E0
#define __msgTokenTextParam_x                                      0x5B4A00
#define msgTokenText_x                                             0x5B4C50

//SpellManager
#define SpellManager__vftable_x                                    0xAD9534
#define SpellManager__SpellManager_x                               0x69F700
#define Spellmanager__LoadTextSpells_x                             0x69FFF0
#define SpellManager__GetSpellByGroupAndRank_x                     0x69F8D0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98CEE0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x519930
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B8BE0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x650020
#define ItemGlobalIndex__IsValidIndex_x                            0x5199C0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C70E0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C7360

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x764A00

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x713780
#define CCursorAttachment__AttachToCursor1_x                       0x7137C0
#define CCursorAttachment__Deactivate_x                            0x7147B0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x937970
#define CSidlManagerBase__CreatePageWnd_x                          0x937160
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x9333E0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x933370

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9549C0
#define CEQSuiteTextureLoader__GetTexture_x                        0x954680

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x516820
#define CFindItemWnd__WndNotification_x                            0x517300
#define CFindItemWnd__Update_x                                     0x517E70
#define CFindItemWnd__PickupSelectedItem_x                         0x516050

//IString
#define IString__Append_x                                          0x506BF0

//Camera
#define CDisplay__cameraType_x                                     0xDEA290
#define EverQuest__Cameras_x                                       0xEA5098

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51F290
#define LootFiltersManager__GetItemFilterData_x                    0x51EBA0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51EBD0
#define LootFiltersManager__SetItemLootFilter_x                    0x51EDF0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BC3C0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x992B80
#define CResolutionHandler__GetWindowedStyle_x                     0x696DC0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70BD40

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8DC6E0
#define CDistillerInfo__Instance_x                                 0x8DC680

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72AE30
#define CGroupWnd__UpdateDisplay_x                                 0x72A180

//ItemBase
#define ItemBase__IsLore_x                                         0x89C610
#define ItemBase__IsLoreEquipped_x                                 0x89C680

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EE200
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EE340
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EE3A0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68C590
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x68FF10

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50CFC0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F9280
#define FactionManagerClient__HandleFactionMessage_x               0x4F98F0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F9EB0
#define FactionManagerClient__GetMaxFaction_x                      0x4F9ECF
#define FactionManagerClient__GetMinFaction_x                      0x4F9E80

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x5053A0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91BFE0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C380

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x505600

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56C7B0

//CTargetManager
#define CTargetManager__Get_x                                      0x6A2F30

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68C590

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A91D0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5C10C0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF42730

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6BF990
#define CAAWnd__UpdateSelected_x                                   0x6BC200
#define CAAWnd__Update_x                                           0x6BECB0

//CXRect
#define CXRect__operator_and_x                                     0x721F10

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x4832A0

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
