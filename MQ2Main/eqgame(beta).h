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
#define __ExpectedVersionDate                                     "Nov  9 2020"
#define __ExpectedVersionTime                                     "04:19:29"
#define __ActualVersionDate_x                                      0xAF454C
#define __ActualVersionTime_x                                      0xAF4540
#define __ActualVersionBuild_x                                     0xAE2554

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x642D70
#define __MemChecker1_x                                            0x8F5E00
#define __MemChecker2_x                                            0x6B31A0
#define __MemChecker3_x                                            0x6B30F0
#define __MemChecker4_x                                            0x84BF10
#define __EncryptPad0_x                                            0xC2A9C8
#define __EncryptPad1_x                                            0xC88210
#define __EncryptPad2_x                                            0xC3AD90
#define __EncryptPad3_x                                            0xC3A990
#define __EncryptPad4_x                                            0xC787A0
#define __EncryptPad5_x                                            0xF4A650
#define __AC1_x                                                    0x80AB36
#define __AC2_x                                                    0x5FC59F
#define __AC3_x                                                    0x603BF0
#define __AC4_x                                                    0x607BA0
#define __AC5_x                                                    0x60DE9F
#define __AC6_x                                                    0x612356
#define __AC7_x                                                    0x5FC010
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
#define __do_loot_x                                                0x5C8050
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
#define __gfMaxZoomCameraDistance_x                                0xAEC170
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
#define __CastRay_x                                                0x5C3740
#define __CastRay2_x                                               0x5C3790
#define __ConvertItemTags_x                                        0x5DF460
#define __CleanItemTags_x                                          0x47D1A0
#define __DoesFileExist_x                                          0x8F8EE0
#define __EQGetTime_x                                              0x8F5A30
#define __ExecuteCmd_x                                             0x5BC060
#define __FixHeading_x                                             0x98A930
#define __FlushDxKeyboard_x                                        0x6AF040
#define __GameLoop_x                                               0x6B2370
#define __get_bearing_x                                            0x5C32A0
#define __get_melee_range_x                                        0x5C3980
#define __GetAnimationCache_x                                      0x717750
#define __GetGaugeValueFromEQ_x                                    0x808FE0
#define __GetLabelFromEQ_x                                         0x80AAC0
#define __GetXTargetType_x                                         0x98C3F0
#define __HandleMouseWheel_x                                       0x6B3250
#define __HeadingDiff_x                                            0x98A9A0
#define __HelpPath_x                                               0xF42DFC
#define __LoadFrontEnd_x                                           0x6AF680
#define __NewUIINI_x                                               0x808CB0
#define __ProcessGameEvents_x                                      0x624230
#define __ProcessMouseEvent_x                                      0x6239C0
#define __SaveColors_x                                             0x55CC70
#define __STMLToText_x                                             0x92DE30
#define __ToggleKeyRingItem_x                                      0x51B3D0
#define CMemoryMappedFile__SetFile_x                               0xA79DE0
#define CrashDetected_x                                            0x6B1130
#define DrawNetStatus_x                                            0x650100
#define Expansion_HoT_x                                            0xEA4D40
#define Teleport_Table_Size_x                                      0xE9C44C
#define Teleport_Table_x                                           0xE9C918
#define Util__FastTime_x                                           0x8F5600
#define __CopyLayout_x                                             0x63E490
#define __WndProc_x                                                0x6B1630
#define __ProcessKeyboardEvent_x                                   0x6B0BD0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4904F0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4994E0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4992B0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493A80
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492ED0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x564E50
#define AltAdvManager__IsAbilityReady_x                            0x563BF0
#define AltAdvManager__GetAAById_x                                 0x563F80
#define AltAdvManager__CanTrainAbility_x                           0x563FF0
#define AltAdvManager__CanSeeAbility_x                             0x564350

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CB160
#define CharacterZoneClient__HasSkill_x                            0x4D5FE0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D7700
#define CharacterZoneClient__IsStackBlocked_x                      0x4C2900
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBD90
#define CharacterZoneClient__GetItemCountWorn_x                    0x4DA090
#define CharacterZoneClient__GetItemCountInInventory_x             0x4DA170
#define CharacterZoneClient__GetCursorItemCount_x                  0x4DA250
#define CharacterZoneClient__FindAffectSlot_x                      0x4C49F0
#define CharacterZoneClient__BardCastBard_x                        0x4C7420
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF7A0
#define CharacterZoneClient__GetEffect_x                           0x4BBCD0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C5A60
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C5B30
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C5B80
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5CD0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5EB0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3CB0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D8660
#define CharacterZoneClient__FindItemByRecord_x                    0x4D80E0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D8D80
#define CBankWnd__WndNotification_x                                0x6D8B60

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E66A0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x92B610
#define CButtonWnd__CButtonWnd_x                                   0x92A240

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x706870
#define CChatManager__InitContextMenu_x                            0x6FF9A0
#define CChatManager__FreeChatWindow_x                             0x7053B0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9A20
#define CChatManager__SetLockedActiveChatWindow_x                  0x7064F0
#define CChatManager__CreateChatWindow_x                           0x7059F0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9B30

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x93E880
#define CContextMenu__dCContextMenu_x                              0x93EAB0
#define CContextMenu__AddMenuItem_x                                0x93EAC0
#define CContextMenu__RemoveMenuItem_x                             0x93EDD0
#define CContextMenu__RemoveAllMenuItems_x                         0x93EDF0
#define CContextMenu__CheckMenuItem_x                              0x93EE70
#define CContextMenu__SetMenuItem_x                                0x93ECF0
#define CContextMenu__AddSeparator_x                               0x93EC50

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x93F410
#define CContextMenuManager__RemoveMenu_x                          0x93F480
#define CContextMenuManager__PopupMenu_x                           0x93F540
#define CContextMenuManager__Flush_x                               0x93F3B0
#define CContextMenuManager__GetMenu_x                             0x49B780
#define CContextMenuManager__CreateDefaultMenu_x                   0x712090

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D0880
#define CChatService__GetFriendName_x                              0x8D0890

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x7070E0
#define CChatWindow__Clear_x                                       0x7083A0
#define CChatWindow__WndNotification_x                             0x708B30
#define CChatWindow__AddHistory_x                                  0x707C60

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93BCC0
#define CComboWnd__Draw_x                                          0x93B1C0
#define CComboWnd__GetCurChoice_x                                  0x93BB00
#define CComboWnd__GetListRect_x                                   0x93B670
#define CComboWnd__GetTextRect_x                                   0x93BD30
#define CComboWnd__InsertChoice_x                                  0x93B800
#define CComboWnd__SetColors_x                                     0x93B7D0
#define CComboWnd__SetChoice_x                                     0x93BAD0
#define CComboWnd__GetItemCount_x                                  0x93BB10
#define CComboWnd__GetCurChoiceText_x                              0x93BB50
#define CComboWnd__GetChoiceText_x                                 0x93BB20
#define CComboWnd__InsertChoiceAtIndex_x                           0x93B890

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x70FAA0
#define CContainerWnd__vftable_x                                   0xAFD744
#define CContainerWnd__SetContainer_x                              0x710FF0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x5575D0
#define CDisplay__PreZoneMainUI_x                                  0x5575E0
#define CDisplay__CleanGameUI_x                                    0x55CA30
#define CDisplay__GetClickedActor_x                                0x54FA30
#define CDisplay__GetUserDefinedColor_x                            0x5480A0
#define CDisplay__GetWorldFilePath_x                               0x5514A0
#define CDisplay__is3dON_x                                         0x54C690
#define CDisplay__ReloadUI_x                                       0x556AE0
#define CDisplay__WriteTextHD2_x                                   0x54C480
#define CDisplay__TrueDistance_x                                   0x553160
#define CDisplay__SetViewActor_x                                   0x54F350
#define CDisplay__GetFloorHeight_x                                 0x54C750
#define CDisplay__SetRenderWindow_x                                0x54B0D0
#define CDisplay__ToggleScreenshotMode_x                           0x54EE20

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x95E5B0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x941D50
#define CEditWnd__EnsureCaretVisible_x                             0x943EE0
#define CEditWnd__GetCaretPt_x                                     0x942EC0
#define CEditWnd__GetCharIndexPt_x                                 0x942C70
#define CEditWnd__GetDisplayString_x                               0x942B20
#define CEditWnd__GetHorzOffset_x                                  0x941410
#define CEditWnd__GetLineForPrintableChar_x                        0x943DE0
#define CEditWnd__GetSelStartPt_x                                  0x942F20
#define CEditWnd__GetSTMLSafeText_x                                0x942940
#define CEditWnd__PointFromPrintableChar_x                         0x943A20
#define CEditWnd__SelectableCharFromPoint_x                        0x943B90
#define CEditWnd__SetEditable_x                                    0x942FE0
#define CEditWnd__SetWindowTextA_x                                 0x9426C0
#define CEditWnd__ReplaceSelection_x                               0x9436A0
#define CEditWnd__ReplaceSelection1_x                              0x943620

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x611830
#define CEverQuest__ClickedPlayer_x                                0x6039D0
#define CEverQuest__CreateTargetIndicator_x                        0x6213A0
#define CEverQuest__DeleteTargetIndicator_x                        0x621430
#define CEverQuest__DoTellWindow_x                                 0x4E9C10
#define CEverQuest__OutputTextToLog_x                              0x4E9EE0
#define CEverQuest__DropHeldItemOnGround_x                         0x5F8B30
#define CEverQuest__dsp_chat_x                                     0x4EA270
#define CEverQuest__trimName_x                                     0x61D550
#define CEverQuest__Emote_x                                        0x612090
#define CEverQuest__EnterZone_x                                    0x60C190
#define CEverQuest__GetBodyTypeDesc_x                              0x616AE0
#define CEverQuest__GetClassDesc_x                                 0x617120
#define CEverQuest__GetClassThreeLetterCode_x                      0x617720
#define CEverQuest__GetDeityDesc_x                                 0x61FBF0
#define CEverQuest__GetLangDesc_x                                  0x6178E0
#define CEverQuest__GetRaceDesc_x                                  0x617100
#define CEverQuest__InterpretCmd_x                                 0x6201C0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FCCC0
#define CEverQuest__LMouseUp_x                                     0x5FB050
#define CEverQuest__RightClickedOnPlayer_x                         0x5FD5A0
#define CEverQuest__RMouseUp_x                                     0x5FBFD0
#define CEverQuest__SetGameState_x                                 0x5F88C0
#define CEverQuest__UPCNotificationFlush_x                         0x61D450
#define CEverQuest__IssuePetCommand_x                              0x618CF0
#define CEverQuest__ReportSuccessfulHit_x                          0x6133E0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x721750
#define CGaugeWnd__CalcLinesFillRect_x                             0x7217B0
#define CGaugeWnd__Draw_x                                          0x720DD0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AFF80
#define CGuild__GetGuildName_x                                     0x4AEA30
#define CGuild__GetGuildIndex_x                                    0x4AF030

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73B390

//CHotButton
#define CHotButton__SetCheck_x                                     0x632A30
#define CHotButton__SetButtonSize_x                                0x632DF0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x7484B0
#define CInvSlotMgr__MoveItem_x                                    0x747170
#define CInvSlotMgr__SelectSlot_x                                  0x748580

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x745960
#define CInvSlot__SliderComplete_x                                 0x7436A0
#define CInvSlot__GetItemBase_x                                    0x743010
#define CInvSlot__UpdateItem_x                                     0x743180

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x74A010
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7491A0
#define CInvSlotWnd__HandleLButtonUp_x                             0x749B90

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x804380
#define CItemDisplayWnd__UpdateStrings_x                           0x7586C0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x752330
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x752860
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x758CC0
#define CItemDisplayWnd__AboutToShow_x                             0x758320
#define CItemDisplayWnd__WndNotification_x                         0x759F40
#define CItemDisplayWnd__RequestConvertItem_x                      0x759870
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x757380
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x758140

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x834EB0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75E440

// CLabel 
#define CLabel__Draw_x                                             0x763F30

// CListWnd
#define CListWnd__CListWnd_x                                       0x9145D0
#define CListWnd__dCListWnd_x                                      0x9148F0
#define CListWnd__AddColumn_x                                      0x918D40
#define CListWnd__AddColumn1_x                                     0x918D90
#define CListWnd__AddLine_x                                        0x919120
#define CListWnd__AddString_x                                      0x918F20
#define CListWnd__CalculateFirstVisibleLine_x                      0x918B00
#define CListWnd__CalculateVSBRange_x                              0x9188F0
#define CListWnd__ClearSel_x                                       0x919900
#define CListWnd__ClearAllSel_x                                    0x919960
#define CListWnd__CloseAndUpdateEditWindow_x                       0x91A370
#define CListWnd__Compare_x                                        0x918230
#define CListWnd__Draw_x                                           0x914A20
#define CListWnd__DrawColumnSeparators_x                           0x917200
#define CListWnd__DrawHeader_x                                     0x917670
#define CListWnd__DrawItem_x                                       0x917B70
#define CListWnd__DrawLine_x                                       0x917370
#define CListWnd__DrawSeparator_x                                  0x9172A0
#define CListWnd__EnableLine_x                                     0x916AE0
#define CListWnd__EnsureVisible_x                                  0x91A290
#define CListWnd__ExtendSel_x                                      0x919830
#define CListWnd__GetColumnTooltip_x                               0x916620
#define CListWnd__GetColumnMinWidth_x                              0x916690
#define CListWnd__GetColumnWidth_x                                 0x916590
#define CListWnd__GetCurSel_x                                      0x915F20
#define CListWnd__GetItemAtPoint_x                                 0x916D60
#define CListWnd__GetItemAtPoint1_x                                0x916DD0
#define CListWnd__GetItemData_x                                    0x915FA0
#define CListWnd__GetItemHeight_x                                  0x916360
#define CListWnd__GetItemIcon_x                                    0x916130
#define CListWnd__GetItemRect_x                                    0x916BD0
#define CListWnd__GetItemText_x                                    0x915FE0
#define CListWnd__GetSelList_x                                     0x9199B0
#define CListWnd__GetSeparatorRect_x                               0x917010
#define CListWnd__InsertLine_x                                     0x919510
#define CListWnd__RemoveLine_x                                     0x919660
#define CListWnd__SetColors_x                                      0x9188D0
#define CListWnd__SetColumnJustification_x                         0x918600
#define CListWnd__SetColumnLabel_x                                 0x918EC0
#define CListWnd__SetColumnWidth_x                                 0x918520
#define CListWnd__SetCurSel_x                                      0x919770
#define CListWnd__SetItemColor_x                                   0x919F40
#define CListWnd__SetItemData_x                                    0x919F00
#define CListWnd__SetItemText_x                                    0x919B20
#define CListWnd__ShiftColumnSeparator_x                           0x9186C0
#define CListWnd__Sort_x                                           0x9183B0
#define CListWnd__ToggleSel_x                                      0x9197A0
#define CListWnd__SetColumnsSizable_x                              0x918770
#define CListWnd__SetItemWnd_x                                     0x919DD0
#define CListWnd__GetItemWnd_x                                     0x916180
#define CListWnd__SetItemIcon_x                                    0x919BA0
#define CListWnd__CalculateCustomWindowPositions_x                 0x918C00
#define CListWnd__SetVScrollPos_x                                  0x918500

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x779650
#define CMapViewWnd__GetWorldCoordinates_x                         0x777D60
#define CMapViewWnd__HandleLButtonDown_x                           0x774DA0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x799970
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79A250
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79A780
#define CMerchantWnd__SelectRecoverySlot_x                         0x79D740
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7984D0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A3320
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x799580

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89E200
#define CPacketScrambler__hton_x                                   0x89E1F0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x933410
#define CSidlManager__FindScreenPieceTemplate_x                    0x933820
#define CSidlManager__FindScreenPieceTemplate1_x                   0x933610
#define CSidlManager__CreateLabel_x                                0x7FB600
#define CSidlManager__CreateXWndFromTemplate_x                     0x936780
#define CSidlManager__CreateXWndFromTemplate1_x                    0x936950
#define CSidlManager__CreateXWnd_x                                 0x7FB530
#define CSidlManager__CreateHotButtonWnd_x                         0x7FBAF0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x92FF00
#define CSidlScreenWnd__CalculateVSBRange_x                        0x92FE00
#define CSidlScreenWnd__ConvertToRes_x                             0x9590A0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x92F8F0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x92F5E0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x92F6B0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x92F780
#define CSidlScreenWnd__DrawSidlPiece_x                            0x9303A0
#define CSidlScreenWnd__EnableIniStorage_x                         0x930870
#define CSidlScreenWnd__GetSidlPiece_x                             0x930590
#define CSidlScreenWnd__Init1_x                                    0x92F1E0
#define CSidlScreenWnd__LoadIniInfo_x                              0x9308C0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9313F0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92E5F0
#define CSidlScreenWnd__StoreIniInfo_x                             0x930F70
#define CSidlScreenWnd__StoreIniVis_x                              0x9312D0
#define CSidlScreenWnd__WndNotification_x                          0x9302B0
#define CSidlScreenWnd__GetChildItem_x                             0x9307F0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9201C0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15D9190

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6983A0
#define CSkillMgr__GetSkillCap_x                                   0x698580
#define CSkillMgr__GetNameToken_x                                  0x697B20
#define CSkillMgr__IsActivatedSkill_x                              0x697C60
#define CSkillMgr__IsCombatSkill_x                                 0x697BA0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9401F0
#define CSliderWnd__SetValue_x                                     0x940060
#define CSliderWnd__SetNumTicks_x                                  0x9400C0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x801710

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x948AE0
#define CStmlWnd__ParseSTML_x                                      0x949E30
#define CStmlWnd__CalculateHSBRange_x                              0x949C10
#define CStmlWnd__CalculateVSBRange_x                              0x949B80
#define CStmlWnd__CanBreakAtCharacter_x                            0x94DF40
#define CStmlWnd__FastForwardToEndOfTag_x                          0x94EBD0
#define CStmlWnd__ForceParseNow_x                                  0x9490D0
#define CStmlWnd__GetNextTagPiece_x                                0x94DEA0
#define CStmlWnd__GetSTMLText_x                                    0x50C7B0
#define CStmlWnd__GetVisibleText_x                                 0x9490F0
#define CStmlWnd__InitializeWindowVariables_x                      0x94EA20
#define CStmlWnd__MakeStmlColorTag_x                               0x948150
#define CStmlWnd__MakeWndNotificationTag_x                         0x9481C0
#define CStmlWnd__SetSTMLText_x                                    0x947200
#define CStmlWnd__StripFirstSTMLLines_x                            0x94FCD0
#define CStmlWnd__UpdateHistoryString_x                            0x94EDE0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x946350
#define CTabWnd__DrawCurrentPage_x                                 0x946A80
#define CTabWnd__DrawTab_x                                         0x9467A0
#define CTabWnd__GetCurrentPage_x                                  0x945B50
#define CTabWnd__GetPageInnerRect_x                                0x945D90
#define CTabWnd__GetTabInnerRect_x                                 0x945CD0
#define CTabWnd__GetTabRect_x                                      0x945B80
#define CTabWnd__InsertPage_x                                      0x945FA0
#define CTabWnd__RemovePage_x                                      0x946110
#define CTabWnd__SetPage_x                                         0x945E10
#define CTabWnd__SetPageRect_x                                     0x946290
#define CTabWnd__UpdatePage_x                                      0x946660
#define CTabWnd__GetPageFromTabIndex_x                             0x9466E0
#define CTabWnd__GetCurrentTabIndex_x                              0x945B40

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x75E890
#define CPageWnd__SetTabText_x                                     0x945690
#define CPageWnd__FlashTab_x                                       0x9456F0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9280

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91D0B0
#define CTextureFont__GetTextExtent_x                              0x91D270

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AC500
#define CHtmlComponentWnd__ValidateUri_x                           0x73CD80
#define CHtmlWnd__SetClientCallbacks_x                             0x637E70
#define CHtmlWnd__AddObserver_x                                    0x637E90
#define CHtmlWnd__RemoveObserver_x                                 0x637EF0
#define Window__getProgress_x                                      0x853540
#define Window__getStatus_x                                        0x853560
#define Window__getURI_x                                           0x853570

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x955EB0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x90A0B0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E98E0
#define CXStr__CXStr1_x                                            0x4B7520
#define CXStr__CXStr3_x                                            0x8F19F0
#define CXStr__dCXStr_x                                            0x478400
#define CXStr__operator_equal_x                                    0x8F1C20
#define CXStr__operator_equal1_x                                   0x8F1C60
#define CXStr__operator_plus_equal1_x                              0x8F26F0
#define CXStr__SetString_x                                         0x8F45E0
#define CXStr__operator_char_p_x                                   0x8F2130
#define CXStr__GetChar_x                                           0x8F3F10
#define CXStr__Delete_x                                            0x8F37E0
#define CXStr__GetUnicode_x                                        0x8F3F80
#define CXStr__GetLength_x                                         0x4A9030
#define CXStr__Mid_x                                               0x47D550
#define CXStr__Insert_x                                            0x8F3FE0
#define CXStr__FindNext_x                                          0x8F3C50

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93E480
#define CXWnd__BringToTop_x                                        0x9238E0
#define CXWnd__Center_x                                            0x923460
#define CXWnd__ClrFocus_x                                          0x923270
#define CXWnd__Destroy_x                                           0x923320
#define CXWnd__DoAllDrawing_x                                      0x91F980
#define CXWnd__DrawChildren_x                                      0x91F950
#define CXWnd__DrawColoredRect_x                                   0x91FDD0
#define CXWnd__DrawTooltip_x                                       0x91E490
#define CXWnd__DrawTooltipAtPoint_x                                0x91E550
#define CXWnd__GetBorderFrame_x                                    0x91FC30
#define CXWnd__GetChildWndAt_x                                     0x923980
#define CXWnd__GetClientClipRect_x                                 0x921B60
#define CXWnd__GetScreenClipRect_x                                 0x921C30
#define CXWnd__GetScreenRect_x                                     0x921DF0
#define CXWnd__GetRelativeRect_x                                   0x921EC0
#define CXWnd__GetTooltipRect_x                                    0x91FE20
#define CXWnd__GetWindowTextA_x                                    0x49CE70
#define CXWnd__IsActive_x                                          0x920540
#define CXWnd__IsDescendantOf_x                                    0x9227F0
#define CXWnd__IsReallyVisible_x                                   0x922820
#define CXWnd__IsType_x                                            0x923FE0
#define CXWnd__Move_x                                              0x922880
#define CXWnd__Move1_x                                             0x922930
#define CXWnd__ProcessTransition_x                                 0x923410
#define CXWnd__Refade_x                                            0x922C10
#define CXWnd__Resize_x                                            0x922EE0
#define CXWnd__Right_x                                             0x9236A0
#define CXWnd__SetFocus_x                                          0x923230
#define CXWnd__SetFont_x                                           0x9232A0
#define CXWnd__SetKeyTooltip_x                                     0x923E00
#define CXWnd__SetMouseOver_x                                      0x920D30
#define CXWnd__StartFade_x                                         0x9226E0
#define CXWnd__GetChildItem_x                                      0x923AF0
#define CXWnd__SetParent_x                                         0x9225B0
#define CXWnd__Minimize_x                                          0x922F40

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x95A120

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9267B0
#define CXWndManager__DrawWindows_x                                0x9267D0
#define CXWndManager__GetKeyboardFlags_x                           0x928EE0
#define CXWndManager__HandleKeyboardMsg_x                          0x928A90
#define CXWndManager__RemoveWnd_x                                  0x929100
#define CXWndManager__RemovePendingDeletionWnd_x                   0x929650

// CDBStr
#define CDBStr__GetString_x                                        0x547030

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BFF00
#define EQ_Character__Cur_HP_x                                     0x4D3020
#define EQ_Character__Cur_Mana_x                                   0x4DA750
#define EQ_Character__GetCastingTimeModifier_x                     0x4C2F70
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B38F0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3A40
#define EQ_Character__GetHPRegen_x                                 0x4E0620
#define EQ_Character__GetEnduranceRegen_x                          0x4E0C20
#define EQ_Character__GetManaRegen_x                               0x4E1060
#define EQ_Character__Max_Endurance_x                              0x65E9A0
#define EQ_Character__Max_HP_x                                     0x4D2E50
#define EQ_Character__Max_Mana_x                                   0x65E7A0
#define EQ_Character__doCombatAbility_x                            0x660D90
#define EQ_Character__UseSkill_x                                   0x4E2E70
#define EQ_Character__GetConLevel_x                                0x657070
#define EQ_Character__IsExpansionFlag_x                            0x5BA7B0
#define EQ_Character__TotalEffect_x                                0x4C6D10
#define EQ_Character__GetPCSpellAffect_x                           0x4C3CC0
#define EQ_Character__SpellDuration_x                              0x4C37F0
#define EQ_Character__MySpellDuration_x                            0x4B2220
#define EQ_Character__GetAdjustedSkill_x                           0x4D5DA0
#define EQ_Character__GetBaseSkill_x                               0x4D6D40
#define EQ_Character__CanUseItem_x                                 0x4DAA60

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BD840

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x674CD0

//PcClient
#define PcClient__vftable_x                                        0xAF11D0
#define PcClient__PcClient_x                                       0x6547E0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA960
#define CCharacterListWnd__EnterWorld_x                            0x4BA330
#define CCharacterListWnd__Quit_x                                  0x4BA080
#define CCharacterListWnd__UpdateList_x                            0x4BA520

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x639060
#define EQ_Item__CreateItemTagString_x                             0x8977C0
#define EQ_Item__IsStackable_x                                     0x89C450
#define EQ_Item__GetImageNum_x                                     0x899330
#define EQ_Item__CreateItemClient_x                                0x638290
#define EQ_Item__GetItemValue_x                                    0x89A640
#define EQ_Item__ValueSellMerchant_x                               0x89DDE0
#define EQ_Item__IsKeyRingItem_x                                   0x89BD70
#define EQ_Item__CanGoInBag_x                                      0x639180
#define EQ_Item__IsEmpty_x                                         0x89B8C0
#define EQ_Item__GetMaxItemCount_x                                 0x89AA50
#define EQ_Item__GetHeldItem_x                                     0x899200
#define EQ_Item__GetAugmentFitBySlot_x                             0x897020

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x565B20
#define EQ_LoadingS__Array_x                                       0xC12128

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65F2A0
#define EQ_PC__GetAlternateAbilityId_x                             0x8A7240
#define EQ_PC__GetCombatAbility_x                                  0x8A78B0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A7920
#define EQ_PC__GetItemRecastTimer_x                                0x661310
#define EQ_PC__HasLoreItem_x                                       0x6578E0
#define EQ_PC__AlertInventoryChanged_x                             0x6569B0
#define EQ_PC__GetPcZoneClient_x                                   0x683E90
#define EQ_PC__RemoveMyAffect_x                                    0x664540
#define EQ_PC__GetKeyRingItems_x                                   0x8A81F0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A7F70
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A84F0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5C0CC0
#define EQItemList__add_object_x                                   0x5EE310
#define EQItemList__add_item_x                                     0x5C1220
#define EQItemList__delete_item_x                                  0x5C1270
#define EQItemList__FreeItemList_x                                 0x5C1170

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x543BE0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x6765D0
#define EQPlayer__dEQPlayer_x                                      0x669950
#define EQPlayer__DoAttack_x                                       0x67E620
#define EQPlayer__EQPlayer_x                                       0x66A010
#define EQPlayer__SetNameSpriteState_x                             0x66E2E0
#define EQPlayer__SetNameSpriteTint_x                              0x66F1C0
#define PlayerBase__HasProperty_j_x                                0x988D30
#define EQPlayer__IsTargetable_x                                   0x9891D0
#define EQPlayer__CanSee_x                                         0x989030
#define EQPlayer__CanSee1_x                                        0x989100
#define PlayerBase__GetVisibilityLineSegment_x                     0x988DF0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x681920
#define PlayerZoneClient__GetLevel_x                               0x683ED0
#define PlayerZoneClient__IsValidTeleport_x                        0x5EF480
#define PlayerZoneClient__LegalPlayerRace_x                        0x55E860

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x6794C0
#define EQPlayerManager__GetSpawnByName_x                          0x679570
#define EQPlayerManager__GetPlayerFromPartialName_x                0x679600

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63C6F0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63C770
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63C7B0
#define KeypressHandler__ClearCommandStateArray_x                  0x63DBA0
#define KeypressHandler__HandleKeyDown_x                           0x63DBC0
#define KeypressHandler__HandleKeyUp_x                             0x63DC60
#define KeypressHandler__SaveKeymapping_x                          0x63E0B0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7754C0
#define MapViewMap__SaveEx_x                                       0x778880
#define MapViewMap__SetZoom_x                                      0x77CF40

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BB8B0

// StringTable 
#define StringTable__getString_x                                   0x8B66D0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x6641B0
#define PcZoneClient__RemovePetEffect_x                            0x6647E0
#define PcZoneClient__HasAlternateAbility_x                        0x65E5D0
#define PcZoneClient__GetCurrentMod_x                              0x4E5F90
#define PcZoneClient__GetModCap_x                                  0x4E5E90
#define PcZoneClient__CanEquipItem_x                               0x65EC80
#define PcZoneClient__GetItemByID_x                                0x661780
#define PcZoneClient__GetItemByItemClass_x                         0x6618D0
#define PcZoneClient__RemoveBuffEffect_x                           0x664800
#define PcZoneClient__BandolierSwap_x                              0x65F860
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x6612B0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F3FF0

//IconCache
#define IconCache__GetIcon_x                                       0x717150

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x70EC40
#define CContainerMgr__CloseContainer_x                            0x70EF10
#define CContainerMgr__OpenExperimentContainer_x                   0x70F990

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CDCD0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x631220

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76B9C0
#define CLootWnd__RequestLootSlot_x                                0x76AC90

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58D550
#define EQ_Spell__SpellAffects_x                                   0x58D9C0
#define EQ_Spell__SpellAffectBase_x                                0x58D780
#define EQ_Spell__IsStackable_x                                    0x4CAA30
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CA880
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7BE0
#define EQ_Spell__IsSPAStacking_x                                  0x58E810
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58DD20
#define EQ_Spell__IsNoRemove_x                                     0x4CAA10
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58E820
#define __IsResEffectSpell_x                                       0x4C9D60

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD4E0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C5EC0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x814A70
#define CTargetWnd__WndNotification_x                              0x8142B0
#define CTargetWnd__RefreshTargetBuffs_x                           0x814580
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x813420

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x8190E0
#define CTaskWnd__ConfirmAbandonTask_x                             0x81BD20

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x5415F0
#define CTaskManager__HandleMessage_x                              0x53FA60
#define CTaskManager__GetTaskStatus_x                              0x5416A0
#define CTaskManager__GetElementDescription_x                      0x541720

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5886C0
#define EqSoundManager__PlayScriptMp3_x                            0x588980
#define EqSoundManager__SoundAssistPlay_x                          0x69C2E0
#define EqSoundManager__WaveInstancePlay_x                         0x69B850

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x532A00

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x944BA0
#define CTextureAnimation__Draw_x                                  0x944DA0

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x940B50

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56D610
#define CAltAbilityData__GetMercMaxRank_x                          0x56D5A0
#define CAltAbilityData__GetMaxRank_x                              0x562A70

//CTargetRing
#define CTargetRing__Cast_x                                        0x62F330

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA860
#define CharacterBase__CreateItemGlobalIndex_x                     0x519510
#define CharacterBase__CreateItemIndex_x                           0x637420
#define CharacterBase__GetItemPossession_x                         0x505300
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CE530
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CE590
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F5BD0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F6400
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F64B0

//messages
#define msg_spell_worn_off_x                                       0x5B28A0
#define msg_new_text_x                                             0x5A71F0
#define __msgTokenTextParam_x                                      0x5B4B40
#define msgTokenText_x                                             0x5B4D90

//SpellManager
#define SpellManager__vftable_x                                    0xAD953C
#define SpellManager__SpellManager_x                               0x69F610
#define Spellmanager__LoadTextSpells_x                             0x69FF00
#define SpellManager__GetSpellByGroupAndRank_x                     0x69F7E0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98CCE0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x519B60
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B8D40
#define ItemGlobalIndex__IsEquippedLocation_x                      0x64FF60
#define ItemGlobalIndex__IsValidIndex_x                            0x519BF0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C6860
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C6AE0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x764270

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x713330
#define CCursorAttachment__AttachToCursor1_x                       0x713370
#define CCursorAttachment__Deactivate_x                            0x714350

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x937790
#define CSidlManagerBase__CreatePageWnd_x                          0x936F90
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x933230
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x9331C0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9548A0
#define CEQSuiteTextureLoader__GetTexture_x                        0x954560

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x516AF0
#define CFindItemWnd__WndNotification_x                            0x5175D0
#define CFindItemWnd__Update_x                                     0x518110
#define CFindItemWnd__PickupSelectedItem_x                         0x516320

//IString
#define IString__Append_x                                          0x506B50

//Camera
#define CDisplay__cameraType_x                                     0xDEA290
#define EverQuest__Cameras_x                                       0xEA5098

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51F570
#define LootFiltersManager__GetItemFilterData_x                    0x51EE70
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51EEA0
#define LootFiltersManager__SetItemLootFilter_x                    0x51F0C0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BBB30

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x992930
#define CResolutionHandler__GetWindowedStyle_x                     0x696EE0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70B850

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8DBE30
#define CDistillerInfo__Instance_x                                 0x8DBDD0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72A720
#define CGroupWnd__UpdateDisplay_x                                 0x729A80

//ItemBase
#define ItemBase__IsLore_x                                         0x89BE20
#define ItemBase__IsLoreEquipped_x                                 0x89BE90

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EE270
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EE3B0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EE410

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68C5B0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x68FF10

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50D150

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F9430
#define FactionManagerClient__HandleFactionMessage_x               0x4F9AA0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4FA060
#define FactionManagerClient__GetMaxFaction_x                      0x4FA07F
#define FactionManagerClient__GetMinFaction_x                      0x4FA030

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x5052D0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91C030

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C180

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x505560

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56CAA0

//CTargetManager
#define CTargetManager__Get_x                                      0x6A2E50

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68C5B0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A9040

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5C1110

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF42730

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6BF510
#define CAAWnd__UpdateSelected_x                                   0x6BBD80
#define CAAWnd__Update_x                                           0x6BE830

//CXRect
#define CXRect__operator_and_x                                     0x721810

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x483170

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
