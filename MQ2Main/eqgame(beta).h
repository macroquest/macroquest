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
#define __ExpectedVersionDate                                     "Nov  5 2020"
#define __ExpectedVersionTime                                     "04:17:58"
#define __ActualVersionDate_x                                      0xAF4554
#define __ActualVersionTime_x                                      0xAF4548
#define __ActualVersionBuild_x                                     0xAE2544

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x642CA0
#define __MemChecker1_x                                            0x8F5A90
#define __MemChecker2_x                                            0x6B2F20
#define __MemChecker3_x                                            0x6B2E70
#define __MemChecker4_x                                            0x84BEB0
#define __EncryptPad0_x                                            0xC2A9C8
#define __EncryptPad1_x                                            0xC88210
#define __EncryptPad2_x                                            0xC3AD90
#define __EncryptPad3_x                                            0xC3A990
#define __EncryptPad4_x                                            0xC787A0
#define __EncryptPad5_x                                            0xF4A650
#define __AC1_x                                                    0x80A716
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
#define __do_loot_x                                                0x5C7F90
#define __DrawHandler_x                                            0x15DA140
#define __GroupCount_x                                             0xE9EA72
#define __Guilds_x                                                 0xEA2918
#define __gWorld_x                                                 0xE9E91C
#define __HWnd_x                                                   0xF4A68C
#define __heqmain_x                                                0xF4A638
#define __InChatMode_x                                             0xEA39C4
#define __LastTell_x                                               0xEA5948
#define __LMouseHeldTime_x                                         0xEA3B00
#define __Mouse_x                                                  0xF4A65C
#define __MouseLook_x                                              0xEA3A5A
#define __MouseEventTime_x                                         0xF4320C
#define __gpbCommandEvent_x                                        0xE9C3C4
#define __NetStatusToggle_x                                        0xEA3A5D
#define __PCNames_x                                                0xEA4EF4
#define __RangeAttackReady_x                                       0xEA4BDC
#define __RMouseHeldTime_x                                         0xEA3AFC
#define __RunWalkState_x                                           0xEA39C8
#define __ScreenMode_x                                             0xDEA1DC
#define __ScreenX_x                                                0xEA397C
#define __ScreenY_x                                                0xEA3978
#define __ScreenXMax_x                                             0xEA3980
#define __ScreenYMax_x                                             0xEA3984
#define __ServerHost_x                                             0xE9C593
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
#define pinstActiveBanker_x                                        0xE9C8B0
#define pinstActiveCorpse_x                                        0xE9C8A8
#define pinstActiveGMaster_x                                       0xE9C8AC
#define pinstActiveMerchant_x                                      0xE9C8A4
#define pinstAltAdvManager_x                                       0xDEAEE0
#define pinstBandageTarget_x                                       0xE9C8C0
#define pinstCamActor_x                                            0xDEA1C8
#define pinstCDBStr_x                                              0xDE9BFC
#define pinstCDisplay_x                                            0xE9C910
#define pinstCEverQuest_x                                          0xF4A690
#define pinstEverQuestInfo_x                                       0xEA3970
#define pinstCharData_x                                            0xE9C3B0
#define pinstCharSpawn_x                                           0xE9C8F8
#define pinstControlledMissile_x                                   0xE9C908
#define pinstControlledPlayer_x                                    0xE9C8F8
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
#define pinstGroup_x                                               0xE9EA6E
#define pinstImeManager_x                                          0x15D9300
#define pinstLocalPlayer_x                                         0xE9C69C
#define pinstMercenaryData_x                                       0xF44D00
#define pinstMercenaryStats_x                                      0xF5DBCC
#define pinstModelPlayer_x                                         0xE9C8B8
#define pinstPCData_x                                              0xE9C3B0
#define pinstSkillMgr_x                                            0xF46E68
#define pinstSpawnManager_x                                        0xF45910
#define pinstSpellManager_x                                        0xF470A8
#define pinstSpellSets_x                                           0xF3B354
#define pinstStringTable_x                                         0xE9C3B8
#define pinstSwitchManager_x                                       0xE9C250
#define pinstTarget_x                                              0xE9C8F4
#define pinstTargetObject_x                                        0xE9C900
#define pinstTargetSwitch_x                                        0xE9C914
#define pinstTaskMember_x                                          0xDE99D0
#define pinstTrackTarget_x                                         0xE9C8FC
#define pinstTradeTarget_x                                         0xE9C8B4
#define instTributeActive_x                                        0xDE9B61
#define pinstViewActor_x                                           0xDEA1C4
#define pinstWorldData_x                                           0xE9C3AC
#define pinstZoneAddr_x                                            0xEA3EF0
#define pinstPlayerPath_x                                          0xF459A8
#define pinstTargetIndicator_x                                     0xF47310
#define EQObject_Top_x                                             0xE9C48C
 
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
#define pinstCBuffWindowNORMAL_x                                   0xDEA1D0
#define pinstCBuffWindowSHORT_x                                    0xDEA1D8
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
#define __CastRay_x                                                0x5C3680
#define __CastRay2_x                                               0x5C36D0
#define __ConvertItemTags_x                                        0x5DF3A0
#define __CleanItemTags_x                                          0x47D3C0
#define __DoesFileExist_x                                          0x8F8BC0
#define __EQGetTime_x                                              0x8F56C0
#define __ExecuteCmd_x                                             0x5BBFB0
#define __FixHeading_x                                             0x98A8F0
#define __FlushDxKeyboard_x                                        0x6AEDC0
#define __GameLoop_x                                               0x6B20F0
#define __get_bearing_x                                            0x5C31E0
#define __get_melee_range_x                                        0x5C38C0
#define __GetAnimationCache_x                                      0x7175F0
#define __GetGaugeValueFromEQ_x                                    0x808BC0
#define __GetLabelFromEQ_x                                         0x80A6A0
#define __GetXTargetType_x                                         0x98C2D0
#define __HandleMouseWheel_x                                       0x6B2FD0
#define __HeadingDiff_x                                            0x98A960
#define __HelpPath_x                                               0xF42DFC
#define __LoadFrontEnd_x                                           0x6AF400
#define __NewUIINI_x                                               0x808890
#define __ProcessGameEvents_x                                      0x624160
#define __ProcessMouseEvent_x                                      0x6238F0
#define __SaveColors_x                                             0x55CDD0
#define __STMLToText_x                                             0x92DB50
#define __ToggleKeyRingItem_x                                      0x51B4F0
#define CMemoryMappedFile__SetFile_x                               0xA79BA0
#define CrashDetected_x                                            0x6B0EB0
#define DrawNetStatus_x                                            0x64FF40
#define Expansion_HoT_x                                            0xEA4D40
#define Teleport_Table_Size_x                                      0xE9C44C
#define Teleport_Table_x                                           0xE9C918
#define Util__FastTime_x                                           0x8F5290
#define __CopyLayout_x                                             0x63E390
#define __WndProc_x                                                0x6B13B0
#define __ProcessKeyboardEvent_x                                   0x6B0950

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490810
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499810
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4995E0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493DB0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x493200

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x564FA0
#define AltAdvManager__IsAbilityReady_x                            0x563D40
#define AltAdvManager__GetAAById_x                                 0x5640D0
#define AltAdvManager__CanTrainAbility_x                           0x564140
#define AltAdvManager__CanSeeAbility_x                             0x5644A0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CB490
#define CharacterZoneClient__HasSkill_x                            0x4D6310
#define CharacterZoneClient__MakeMeVisible_x                       0x4D7A30
#define CharacterZoneClient__IsStackBlocked_x                      0x4C2B00
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBFA0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4DA3A0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4DA480
#define CharacterZoneClient__GetCursorItemCount_x                  0x4DA560
#define CharacterZoneClient__FindAffectSlot_x                      0x4C4BF0
#define CharacterZoneClient__BardCastBard_x                        0x4C7620
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF9B0
#define CharacterZoneClient__GetEffect_x                           0x4BBEE0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C5C60
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C5D30
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C5D80
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5ED0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C60B0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3F00
#define CharacterZoneClient__FindItemByGuid_x                      0x4D8990
#define CharacterZoneClient__FindItemByRecord_x                    0x4D8410

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D8BE0
#define CBankWnd__WndNotification_x                                0x6D89C0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E65D0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x92B330
#define CButtonWnd__CButtonWnd_x                                   0x929F30

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x706790
#define CChatManager__InitContextMenu_x                            0x6FF8D0
#define CChatManager__FreeChatWindow_x                             0x7052D0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9DC0
#define CChatManager__SetLockedActiveChatWindow_x                  0x706410
#define CChatManager__CreateChatWindow_x                           0x705910

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9ED0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x93E4C0
#define CContextMenu__dCContextMenu_x                              0x93E6F0
#define CContextMenu__AddMenuItem_x                                0x93E700
#define CContextMenu__RemoveMenuItem_x                             0x93EA10
#define CContextMenu__RemoveAllMenuItems_x                         0x93EA30
#define CContextMenu__CheckMenuItem_x                              0x93EAB0
#define CContextMenu__SetMenuItem_x                                0x93E930
#define CContextMenu__AddSeparator_x                               0x93E890

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x93F050
#define CContextMenuManager__RemoveMenu_x                          0x93F0C0
#define CContextMenuManager__PopupMenu_x                           0x93F180
#define CContextMenuManager__Flush_x                               0x93EFF0
#define CContextMenuManager__GetMenu_x                             0x49BA80
#define CContextMenuManager__CreateDefaultMenu_x                   0x711F30

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D03D0
#define CChatService__GetFriendName_x                              0x8D03E0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x706FC0
#define CChatWindow__Clear_x                                       0x708280
#define CChatWindow__WndNotification_x                             0x708A10
#define CChatWindow__AddHistory_x                                  0x707B40

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93B910
#define CComboWnd__Draw_x                                          0x93AE10
#define CComboWnd__GetCurChoice_x                                  0x93B750
#define CComboWnd__GetListRect_x                                   0x93B2C0
#define CComboWnd__GetTextRect_x                                   0x93B980
#define CComboWnd__InsertChoice_x                                  0x93B450
#define CComboWnd__SetColors_x                                     0x93B420
#define CComboWnd__SetChoice_x                                     0x93B720
#define CComboWnd__GetItemCount_x                                  0x93B760
#define CComboWnd__GetCurChoiceText_x                              0x93B7A0
#define CComboWnd__GetChoiceText_x                                 0x93B770
#define CComboWnd__InsertChoiceAtIndex_x                           0x93B4E0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x70F950
#define CContainerWnd__vftable_x                                   0xAFD74C
#define CContainerWnd__SetContainer_x                              0x710EA0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x557730
#define CDisplay__PreZoneMainUI_x                                  0x557740
#define CDisplay__CleanGameUI_x                                    0x55CB90
#define CDisplay__GetClickedActor_x                                0x54FB90
#define CDisplay__GetUserDefinedColor_x                            0x548200
#define CDisplay__GetWorldFilePath_x                               0x551600
#define CDisplay__is3dON_x                                         0x54C7F0
#define CDisplay__ReloadUI_x                                       0x556C40
#define CDisplay__WriteTextHD2_x                                   0x54C5E0
#define CDisplay__TrueDistance_x                                   0x5532C0
#define CDisplay__SetViewActor_x                                   0x54F4B0
#define CDisplay__GetFloorHeight_x                                 0x54C8B0
#define CDisplay__SetRenderWindow_x                                0x54B230
#define CDisplay__ToggleScreenshotMode_x                           0x54EF80

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x95E360

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x941980
#define CEditWnd__EnsureCaretVisible_x                             0x943B10
#define CEditWnd__GetCaretPt_x                                     0x942AF0
#define CEditWnd__GetCharIndexPt_x                                 0x9428A0
#define CEditWnd__GetDisplayString_x                               0x942750
#define CEditWnd__GetHorzOffset_x                                  0x941040
#define CEditWnd__GetLineForPrintableChar_x                        0x943A10
#define CEditWnd__GetSelStartPt_x                                  0x942B50
#define CEditWnd__GetSTMLSafeText_x                                0x942570
#define CEditWnd__PointFromPrintableChar_x                         0x943650
#define CEditWnd__SelectableCharFromPoint_x                        0x9437C0
#define CEditWnd__SetEditable_x                                    0x942C10
#define CEditWnd__SetWindowTextA_x                                 0x9422F0
#define CEditWnd__ReplaceSelection_x                               0x9432D0
#define CEditWnd__ReplaceSelection1_x                              0x943250

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x611760
#define CEverQuest__ClickedPlayer_x                                0x603900
#define CEverQuest__CreateTargetIndicator_x                        0x6212D0
#define CEverQuest__DeleteTargetIndicator_x                        0x621360
#define CEverQuest__DoTellWindow_x                                 0x4E9FB0
#define CEverQuest__OutputTextToLog_x                              0x4EA280
#define CEverQuest__DropHeldItemOnGround_x                         0x5F8A60
#define CEverQuest__dsp_chat_x                                     0x4EA610
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
#define CGaugeWnd__CalcFillRect_x                                  0x721560
#define CGaugeWnd__CalcLinesFillRect_x                             0x7215C0
#define CGaugeWnd__Draw_x                                          0x720BE0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4B01D0
#define CGuild__GetGuildName_x                                     0x4AEC80
#define CGuild__GetGuildIndex_x                                    0x4AF280

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73B1B0

//CHotButton
#define CHotButton__SetCheck_x                                     0x632960
#define CHotButton__SetButtonSize_x                                0x632D20

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x748270
#define CInvSlotMgr__MoveItem_x                                    0x746F80
#define CInvSlotMgr__SelectSlot_x                                  0x748340

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x745770
#define CInvSlot__SliderComplete_x                                 0x7434B0
#define CInvSlot__GetItemBase_x                                    0x742E30
#define CInvSlot__UpdateItem_x                                     0x742FA0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x749DD0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x748F60
#define CInvSlotWnd__HandleLButtonUp_x                             0x749950

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x803F50
#define CItemDisplayWnd__UpdateStrings_x                           0x758450
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x752190
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x752690
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x758A40
#define CItemDisplayWnd__AboutToShow_x                             0x7580A0
#define CItemDisplayWnd__WndNotification_x                         0x759CA0
#define CItemDisplayWnd__RequestConvertItem_x                      0x7595E0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x757100
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x757EC0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x834A50

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75E1A0

// CLabel 
#define CLabel__Draw_x                                             0x763CB0

// CListWnd
#define CListWnd__CListWnd_x                                       0x914150
#define CListWnd__dCListWnd_x                                      0x914470
#define CListWnd__AddColumn_x                                      0x9188D0
#define CListWnd__AddColumn1_x                                     0x918920
#define CListWnd__AddLine_x                                        0x918CB0
#define CListWnd__AddString_x                                      0x918AB0
#define CListWnd__CalculateFirstVisibleLine_x                      0x918690
#define CListWnd__CalculateVSBRange_x                              0x918480
#define CListWnd__ClearSel_x                                       0x919490
#define CListWnd__ClearAllSel_x                                    0x9194F0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x919F00
#define CListWnd__Compare_x                                        0x917DC0
#define CListWnd__Draw_x                                           0x9145A0
#define CListWnd__DrawColumnSeparators_x                           0x916D90
#define CListWnd__DrawHeader_x                                     0x917200
#define CListWnd__DrawItem_x                                       0x917700
#define CListWnd__DrawLine_x                                       0x916F00
#define CListWnd__DrawSeparator_x                                  0x916E30
#define CListWnd__EnableLine_x                                     0x916660
#define CListWnd__EnsureVisible_x                                  0x919E20
#define CListWnd__ExtendSel_x                                      0x9193C0
#define CListWnd__GetColumnTooltip_x                               0x9161A0
#define CListWnd__GetColumnMinWidth_x                              0x916210
#define CListWnd__GetColumnWidth_x                                 0x916110
#define CListWnd__GetCurSel_x                                      0x915AA0
#define CListWnd__GetItemAtPoint_x                                 0x9168E0
#define CListWnd__GetItemAtPoint1_x                                0x916950
#define CListWnd__GetItemData_x                                    0x915B20
#define CListWnd__GetItemHeight_x                                  0x915EE0
#define CListWnd__GetItemIcon_x                                    0x915CB0
#define CListWnd__GetItemRect_x                                    0x916750
#define CListWnd__GetItemText_x                                    0x915B60
#define CListWnd__GetSelList_x                                     0x919540
#define CListWnd__GetSeparatorRect_x                               0x916B90
#define CListWnd__InsertLine_x                                     0x9190A0
#define CListWnd__RemoveLine_x                                     0x9191F0
#define CListWnd__SetColors_x                                      0x918460
#define CListWnd__SetColumnJustification_x                         0x918190
#define CListWnd__SetColumnLabel_x                                 0x918A50
#define CListWnd__SetColumnWidth_x                                 0x9180B0
#define CListWnd__SetCurSel_x                                      0x919300
#define CListWnd__SetItemColor_x                                   0x919AD0
#define CListWnd__SetItemData_x                                    0x919A90
#define CListWnd__SetItemText_x                                    0x9196B0
#define CListWnd__ShiftColumnSeparator_x                           0x918250
#define CListWnd__Sort_x                                           0x917F40
#define CListWnd__ToggleSel_x                                      0x919330
#define CListWnd__SetColumnsSizable_x                              0x918300
#define CListWnd__SetItemWnd_x                                     0x919960
#define CListWnd__GetItemWnd_x                                     0x915D00
#define CListWnd__SetItemIcon_x                                    0x919730
#define CListWnd__CalculateCustomWindowPositions_x                 0x918790
#define CListWnd__SetVScrollPos_x                                  0x918090

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7793F0
#define CMapViewWnd__GetWorldCoordinates_x                         0x777B00
#define CMapViewWnd__HandleLButtonDown_x                           0x774B40

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x799860
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79A140
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79A670
#define CMerchantWnd__SelectRecoverySlot_x                         0x79D620
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7983C0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A31F0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x799470

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89DDE0
#define CPacketScrambler__hton_x                                   0x89DDD0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x933140
#define CSidlManager__FindScreenPieceTemplate_x                    0x933550
#define CSidlManager__FindScreenPieceTemplate1_x                   0x933340
#define CSidlManager__CreateLabel_x                                0x7FB240
#define CSidlManager__CreateXWndFromTemplate_x                     0x9364B0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x936680
#define CSidlManager__CreateXWnd_x                                 0x7FB170
#define CSidlManager__CreateHotButtonWnd_x                         0x7FB730

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x92FC10
#define CSidlScreenWnd__CalculateVSBRange_x                        0x92FB10
#define CSidlScreenWnd__ConvertToRes_x                             0x958EB0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x92F610
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x92F300
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x92F3D0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x92F4A0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x9300B0
#define CSidlScreenWnd__EnableIniStorage_x                         0x930580
#define CSidlScreenWnd__GetSidlPiece_x                             0x9302A0
#define CSidlScreenWnd__Init1_x                                    0x92EF00
#define CSidlScreenWnd__LoadIniInfo_x                              0x9305D0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x931110
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92E310
#define CSidlScreenWnd__StoreIniInfo_x                             0x930C90
#define CSidlScreenWnd__StoreIniVis_x                              0x930FF0
#define CSidlScreenWnd__WndNotification_x                          0x92FFC0
#define CSidlScreenWnd__GetChildItem_x                             0x930500
#define CSidlScreenWnd__HandleLButtonUp_x                          0x91FD40
#define CSidlScreenWnd__m_layoutCopy_x                             0x15D9190

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x698110
#define CSkillMgr__GetSkillCap_x                                   0x6982F0
#define CSkillMgr__GetNameToken_x                                  0x697890
#define CSkillMgr__IsActivatedSkill_x                              0x6979D0
#define CSkillMgr__IsCombatSkill_x                                 0x697910

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x93FE20
#define CSliderWnd__SetValue_x                                     0x93FC90
#define CSliderWnd__SetNumTicks_x                                  0x93FCF0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x801320

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x948710
#define CStmlWnd__ParseSTML_x                                      0x949A10
#define CStmlWnd__CalculateHSBRange_x                              0x9497F0
#define CStmlWnd__CalculateVSBRange_x                              0x949760
#define CStmlWnd__CanBreakAtCharacter_x                            0x94DB20
#define CStmlWnd__FastForwardToEndOfTag_x                          0x94E7B0
#define CStmlWnd__ForceParseNow_x                                  0x948CB0
#define CStmlWnd__GetNextTagPiece_x                                0x94DA80
#define CStmlWnd__GetSTMLText_x                                    0x50CBF0
#define CStmlWnd__GetVisibleText_x                                 0x948CD0
#define CStmlWnd__InitializeWindowVariables_x                      0x94E600
#define CStmlWnd__MakeStmlColorTag_x                               0x947D80
#define CStmlWnd__MakeWndNotificationTag_x                         0x947DF0
#define CStmlWnd__SetSTMLText_x                                    0x946E30
#define CStmlWnd__StripFirstSTMLLines_x                            0x94F8B0
#define CStmlWnd__UpdateHistoryString_x                            0x94E9C0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x945F70
#define CTabWnd__DrawCurrentPage_x                                 0x9466A0
#define CTabWnd__DrawTab_x                                         0x9463C0
#define CTabWnd__GetCurrentPage_x                                  0x945780
#define CTabWnd__GetPageInnerRect_x                                0x9459C0
#define CTabWnd__GetTabInnerRect_x                                 0x945900
#define CTabWnd__GetTabRect_x                                      0x9457B0
#define CTabWnd__InsertPage_x                                      0x945BD0
#define CTabWnd__RemovePage_x                                      0x945D40
#define CTabWnd__SetPage_x                                         0x945A40
#define CTabWnd__SetPageRect_x                                     0x945EB0
#define CTabWnd__UpdatePage_x                                      0x946280
#define CTabWnd__GetPageFromTabIndex_x                             0x946300
#define CTabWnd__GetCurrentTabIndex_x                              0x945770

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x75E630
#define CPageWnd__SetTabText_x                                     0x9452C0
#define CPageWnd__FlashTab_x                                       0x945320

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A94E0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91CBF0
#define CTextureFont__GetTextExtent_x                              0x91CDB0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AC280
#define CHtmlComponentWnd__ValidateUri_x                           0x73CBA0
#define CHtmlWnd__SetClientCallbacks_x                             0x637DA0
#define CHtmlWnd__AddObserver_x                                    0x637DC0
#define CHtmlWnd__RemoveObserver_x                                 0x637E20
#define Window__getProgress_x                                      0x853460
#define Window__getStatus_x                                        0x853480
#define Window__getURI_x                                           0x853490

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x955CC0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x909D40

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9CB0
#define CXStr__CXStr1_x                                            0x912750
#define CXStr__CXStr3_x                                            0x8F1640
#define CXStr__dCXStr_x                                            0x478490
#define CXStr__operator_equal_x                                    0x8F1870
#define CXStr__operator_equal1_x                                   0x8F18B0
#define CXStr__operator_plus_equal1_x                              0x8F2340
#define CXStr__SetString_x                                         0x8F4230
#define CXStr__operator_char_p_x                                   0x8F1DB0
#define CXStr__GetChar_x                                           0x8F3B80
#define CXStr__Delete_x                                            0x8F3430
#define CXStr__GetUnicode_x                                        0x8F3BF0
#define CXStr__GetLength_x                                         0x47D770
#define CXStr__Mid_x                                               0x47D780
#define CXStr__Insert_x                                            0x8F3C50
#define CXStr__FindNext_x                                          0x8F38A0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93E0D0
#define CXWnd__BringToTop_x                                        0x923480
#define CXWnd__Center_x                                            0x923000
#define CXWnd__ClrFocus_x                                          0x922E20
#define CXWnd__Destroy_x                                           0x922EC0
#define CXWnd__DoAllDrawing_x                                      0x91F4E0
#define CXWnd__DrawChildren_x                                      0x91F4B0
#define CXWnd__DrawColoredRect_x                                   0x91F930
#define CXWnd__DrawTooltip_x                                       0x91E000
#define CXWnd__DrawTooltipAtPoint_x                                0x91E0C0
#define CXWnd__GetBorderFrame_x                                    0x91F790
#define CXWnd__GetChildWndAt_x                                     0x923520
#define CXWnd__GetClientClipRect_x                                 0x921750
#define CXWnd__GetScreenClipRect_x                                 0x921800
#define CXWnd__GetScreenRect_x                                     0x9219B0
#define CXWnd__GetRelativeRect_x                                   0x921A70
#define CXWnd__GetTooltipRect_x                                    0x91F980
#define CXWnd__GetWindowTextA_x                                    0x49D170
#define CXWnd__IsActive_x                                          0x9200B0
#define CXWnd__IsDescendantOf_x                                    0x9223A0
#define CXWnd__IsReallyVisible_x                                   0x9223D0
#define CXWnd__IsType_x                                            0x923B90
#define CXWnd__Move_x                                              0x922440
#define CXWnd__Move1_x                                             0x9224F0
#define CXWnd__ProcessTransition_x                                 0x922FB0
#define CXWnd__Refade_x                                            0x9227B0
#define CXWnd__Resize_x                                            0x922A30
#define CXWnd__Right_x                                             0x923240
#define CXWnd__SetFocus_x                                          0x922DE0
#define CXWnd__SetFont_x                                           0x922E50
#define CXWnd__SetKeyTooltip_x                                     0x9239B0
#define CXWnd__SetMouseOver_x                                      0x9208F0
#define CXWnd__StartFade_x                                         0x922280
#define CXWnd__GetChildItem_x                                      0x923690
#define CXWnd__SetParent_x                                         0x922140
#define CXWnd__Minimize_x                                          0x922AA0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x959F30

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9263D0
#define CXWndManager__DrawWindows_x                                0x9263F0
#define CXWndManager__GetKeyboardFlags_x                           0x928BD0
#define CXWndManager__HandleKeyboardMsg_x                          0x928790
#define CXWndManager__RemoveWnd_x                                  0x928E00
#define CXWndManager__RemovePendingDeletionWnd_x                   0x929360

// CDBStr
#define CDBStr__GetString_x                                        0x547190

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4C0110
#define EQ_Character__Cur_HP_x                                     0x4D3350
#define EQ_Character__Cur_Mana_x                                   0x4DAA60
#define EQ_Character__GetCastingTimeModifier_x                     0x4C3170
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B3B40
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3C90
#define EQ_Character__GetHPRegen_x                                 0x4E0930
#define EQ_Character__GetEnduranceRegen_x                          0x4E0F30
#define EQ_Character__GetManaRegen_x                               0x4E1370
#define EQ_Character__Max_Endurance_x                              0x65E4D0
#define EQ_Character__Max_HP_x                                     0x4D3180
#define EQ_Character__Max_Mana_x                                   0x65E2D0
#define EQ_Character__doCombatAbility_x                            0x6608C0
#define EQ_Character__UseSkill_x                                   0x4E3180
#define EQ_Character__GetConLevel_x                                0x656F00
#define EQ_Character__IsExpansionFlag_x                            0x5BA740
#define EQ_Character__TotalEffect_x                                0x4C6F10
#define EQ_Character__GetPCSpellAffect_x                           0x4C3EC0
#define EQ_Character__SpellDuration_x                              0x4C39F0
#define EQ_Character__MySpellDuration_x                            0x4B2470
#define EQ_Character__GetAdjustedSkill_x                           0x4D60D0
#define EQ_Character__GetBaseSkill_x                               0x4D7070
#define EQ_Character__CanUseItem_x                                 0x4DAD70

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BD3A0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x674850

//PcClient
#define PcClient__vftable_x                                        0xAF11C4
#define PcClient__PcClient_x                                       0x654670

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BAB40
#define CCharacterListWnd__EnterWorld_x                            0x4BA510
#define CCharacterListWnd__Quit_x                                  0x4BA260
#define CCharacterListWnd__UpdateList_x                            0x4BA700

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x638F70
#define EQ_Item__CreateItemTagString_x                             0x897350
#define EQ_Item__IsStackable_x                                     0x89C000
#define EQ_Item__GetImageNum_x                                     0x898EF0
#define EQ_Item__CreateItemClient_x                                0x6381A0
#define EQ_Item__GetItemValue_x                                    0x89A1E0
#define EQ_Item__ValueSellMerchant_x                               0x89D9C0
#define EQ_Item__IsKeyRingItem_x                                   0x89B900
#define EQ_Item__CanGoInBag_x                                      0x639090
#define EQ_Item__IsEmpty_x                                         0x89B470
#define EQ_Item__GetMaxItemCount_x                                 0x89A600
#define EQ_Item__GetHeldItem_x                                     0x898DC0
#define EQ_Item__GetAugmentFitBySlot_x                             0x896BA0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x565C70
#define EQ_LoadingS__Array_x                                       0xC12128

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65EDD0
#define EQ_PC__GetAlternateAbilityId_x                             0x8A6DF0
#define EQ_PC__GetCombatAbility_x                                  0x8A7460
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A74D0
#define EQ_PC__GetItemRecastTimer_x                                0x660E40
#define EQ_PC__HasLoreItem_x                                       0x657770
#define EQ_PC__AlertInventoryChanged_x                             0x656840
#define EQ_PC__GetPcZoneClient_x                                   0x683880
#define EQ_PC__RemoveMyAffect_x                                    0x664070
#define EQ_PC__GetKeyRingItems_x                                   0x8A7DA0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A7B20
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A80A0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5C0C10
#define EQItemList__add_object_x                                   0x5EE240
#define EQItemList__add_item_x                                     0x5C1170
#define EQItemList__delete_item_x                                  0x5C11C0
#define EQItemList__FreeItemList_x                                 0x5C10C0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x543D00

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x676150
#define EQPlayer__dEQPlayer_x                                      0x669490
#define EQPlayer__DoAttack_x                                       0x67E010
#define EQPlayer__EQPlayer_x                                       0x669B50
#define EQPlayer__SetNameSpriteState_x                             0x66DE60
#define EQPlayer__SetNameSpriteTint_x                              0x66ED40
#define PlayerBase__HasProperty_j_x                                0x988D00
#define EQPlayer__IsTargetable_x                                   0x9891A0
#define EQPlayer__CanSee_x                                         0x989000
#define EQPlayer__CanSee1_x                                        0x9890D0
#define PlayerBase__GetVisibilityLineSegment_x                     0x988DC0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x681310
#define PlayerZoneClient__GetLevel_x                               0x6838C0
#define PlayerZoneClient__IsValidTeleport_x                        0x5EF3B0
#define PlayerZoneClient__LegalPlayerRace_x                        0x55EA20

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x678F30
#define EQPlayerManager__GetSpawnByName_x                          0x678FE0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x679070

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63C5F0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63C670
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63C6B0
#define KeypressHandler__ClearCommandStateArray_x                  0x63DAA0
#define KeypressHandler__HandleKeyDown_x                           0x63DAC0
#define KeypressHandler__HandleKeyUp_x                             0x63DB60
#define KeypressHandler__SaveKeymapping_x                          0x63DFB0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x775260
#define MapViewMap__SaveEx_x                                       0x778620
#define MapViewMap__SetZoom_x                                      0x77CCE0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BB400

// StringTable 
#define StringTable__getString_x                                   0x8B62B0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x663CE0
#define PcZoneClient__RemovePetEffect_x                            0x664310
#define PcZoneClient__HasAlternateAbility_x                        0x65E100
#define PcZoneClient__GetCurrentMod_x                              0x4E62A0
#define PcZoneClient__GetModCap_x                                  0x4E61A0
#define PcZoneClient__CanEquipItem_x                               0x65E7B0
#define PcZoneClient__GetItemByID_x                                0x6612B0
#define PcZoneClient__GetItemByItemClass_x                         0x661400
#define PcZoneClient__RemoveBuffEffect_x                           0x664330
#define PcZoneClient__BandolierSwap_x                              0x65F390
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x660DE0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F3FB0

//IconCache
#define IconCache__GetIcon_x                                       0x716FF0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x70EAF0
#define CContainerMgr__CloseContainer_x                            0x70EDC0
#define CContainerMgr__OpenExperimentContainer_x                   0x70F840

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CDAA0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x631160

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76B760
#define CLootWnd__RequestLootSlot_x                                0x76AA30

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58D740
#define EQ_Spell__SpellAffects_x                                   0x58DBB0
#define EQ_Spell__SpellAffectBase_x                                0x58D970
#define EQ_Spell__IsStackable_x                                    0x4CAD60
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CAB50
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7E20
#define EQ_Spell__IsSPAStacking_x                                  0x58EA00
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58DF10
#define EQ_Spell__IsNoRemove_x                                     0x4CAD40
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58EA10
#define __IsResEffectSpell_x                                       0x4C9F40

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD730

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C5A60

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x814630
#define CTargetWnd__WndNotification_x                              0x813E70
#define CTargetWnd__RefreshTargetBuffs_x                           0x814140
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x812FE0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x818CA0
#define CTaskWnd__ConfirmAbandonTask_x                             0x81B8E0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x541710
#define CTaskManager__HandleMessage_x                              0x53FB90
#define CTaskManager__GetTaskStatus_x                              0x5417C0
#define CTaskManager__GetElementDescription_x                      0x541840

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x588870
#define EqSoundManager__PlayScriptMp3_x                            0x588B30
#define EqSoundManager__SoundAssistPlay_x                          0x69BFD0
#define EqSoundManager__WaveInstancePlay_x                         0x69B540

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x532B10

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x9447D0
#define CTextureAnimation__Draw_x                                  0x9449D0

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x940780

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56D850
#define CAltAbilityData__GetMercMaxRank_x                          0x56D7E0
#define CAltAbilityData__GetMaxRank_x                              0x562BC0

//CTargetRing
#define CTargetRing__Cast_x                                        0x62F280

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CAB30
#define CharacterBase__CreateItemGlobalIndex_x                     0x5196C0
#define CharacterBase__CreateItemIndex_x                           0x637360
#define CharacterBase__GetItemPossession_x                         0x505490
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CE0C0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CE120
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F5A10
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F6240
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F62F0

//messages
#define msg_spell_worn_off_x                                       0x5B2770
#define msg_new_text_x                                             0x5A7100
#define __msgTokenTextParam_x                                      0x5B4A00
#define msgTokenText_x                                             0x5B4C50

//SpellManager
#define SpellManager__vftable_x                                    0xAD954C
#define SpellManager__SpellManager_x                               0x69F300
#define Spellmanager__LoadTextSpells_x                             0x69FBF0
#define SpellManager__GetSpellByGroupAndRank_x                     0x69F4D0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98CBC0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x519D50
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B8BE0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x64FDA0
#define ItemGlobalIndex__IsValidIndex_x                            0x519DE0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C6400
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C6680

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x763FF0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x7131D0
#define CCursorAttachment__AttachToCursor1_x                       0x713210
#define CCursorAttachment__Deactivate_x                            0x7141F0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x9374C0
#define CSidlManagerBase__CreatePageWnd_x                          0x936CC0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x932F60
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x932EF0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9544D0
#define CEQSuiteTextureLoader__GetTexture_x                        0x954190

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x516C10
#define CFindItemWnd__WndNotification_x                            0x5176F0
#define CFindItemWnd__Update_x                                     0x518260
#define CFindItemWnd__PickupSelectedItem_x                         0x516440

//IString
#define IString__Append_x                                          0x506DD0

//Camera
#define CDisplay__cameraType_x                                     0xDEA290
#define EverQuest__Cameras_x                                       0xEA5098

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51F670
#define LootFiltersManager__GetItemFilterData_x                    0x51EF70
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51EFA0
#define LootFiltersManager__SetItemLootFilter_x                    0x51F1C0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BB8F0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x992760
#define CResolutionHandler__GetWindowedStyle_x                     0x696AD0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70B730

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8DB9C0
#define CDistillerInfo__Instance_x                                 0x8DB960

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72A510
#define CGroupWnd__UpdateDisplay_x                                 0x729880

//ItemBase
#define ItemBase__IsLore_x                                         0x89B9B0
#define ItemBase__IsLoreEquipped_x                                 0x89BA30

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EE1A0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EE2E0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EE340

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68BFA0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x68F8F0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50D2A0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F9540
#define FactionManagerClient__HandleFactionMessage_x               0x4F9BB0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4FA170
#define FactionManagerClient__GetMaxFaction_x                      0x4FA18F
#define FactionManagerClient__GetMinFaction_x                      0x4FA140

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x505460

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91BBA0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C480

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x5057E0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56CCE0

//CTargetManager
#define CTargetManager__Get_x                                      0x6A2B40

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68BFA0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A92A0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5C1060

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF42730

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6BF240
#define CAAWnd__UpdateSelected_x                                   0x6BBAB0
#define CAAWnd__Update_x                                           0x6BE560

//CXRect
#define CXRect__operator_and_x                                     0x721620

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x4833C0

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
