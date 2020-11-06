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
#define __ExpectedVersionDate                                     "Nov  6 2020"
#define __ExpectedVersionTime                                     "04:19:19"
#define __ActualVersionDate_x                                      0xAF4544
#define __ActualVersionTime_x                                      0xAF4538
#define __ActualVersionBuild_x                                     0xAE2534

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x642630
#define __MemChecker1_x                                            0x8F5D60
#define __MemChecker2_x                                            0x6B3040
#define __MemChecker3_x                                            0x6B2F90
#define __MemChecker4_x                                            0x84BDE0
#define __EncryptPad0_x                                            0xC2A9C8
#define __EncryptPad1_x                                            0xC88210
#define __EncryptPad2_x                                            0xC3AD90
#define __EncryptPad3_x                                            0xC3A990
#define __EncryptPad4_x                                            0xC787A0
#define __EncryptPad5_x                                            0xF4A650
#define __AC1_x                                                    0x80A9C6
#define __AC2_x                                                    0x5FBC5F
#define __AC3_x                                                    0x6032B0
#define __AC4_x                                                    0x607260
#define __AC5_x                                                    0x60D55F
#define __AC6_x                                                    0x611A16
#define __AC7_x                                                    0x5FB6D0
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
#define __do_loot_x                                                0x5C7780
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
#define __gfMaxZoomCameraDistance_x                                0xAEC150
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
#define __CastRay_x                                                0x5C2E70
#define __CastRay2_x                                               0x5C2EC0
#define __ConvertItemTags_x                                        0x5DEB80
#define __CleanItemTags_x                                          0x47D260
#define __DoesFileExist_x                                          0x8F8DE0
#define __EQGetTime_x                                              0x8F5990
#define __ExecuteCmd_x                                             0x5BB780
#define __FixHeading_x                                             0x98A5A0
#define __FlushDxKeyboard_x                                        0x6AEEE0
#define __GameLoop_x                                               0x6B2210
#define __get_bearing_x                                            0x5C29D0
#define __get_melee_range_x                                        0x5C30B0
#define __GetAnimationCache_x                                      0x717650
#define __GetGaugeValueFromEQ_x                                    0x808E70
#define __GetLabelFromEQ_x                                         0x80A950
#define __GetXTargetType_x                                         0x98BF80
#define __HandleMouseWheel_x                                       0x6B30F0
#define __HeadingDiff_x                                            0x98A610
#define __HelpPath_x                                               0xF42DFC
#define __LoadFrontEnd_x                                           0x6AF520
#define __NewUIINI_x                                               0x808B40
#define __ProcessGameEvents_x                                      0x6238F0
#define __ProcessMouseEvent_x                                      0x623080
#define __SaveColors_x                                             0x55C8E0
#define __STMLToText_x                                             0x92D620
#define __ToggleKeyRingItem_x                                      0x51ADE0
#define CMemoryMappedFile__SetFile_x                               0xA79960
#define CrashDetected_x                                            0x6B0FD0
#define DrawNetStatus_x                                            0x64FBA0
#define Expansion_HoT_x                                            0xEA4D40
#define Teleport_Table_Size_x                                      0xE9C44C
#define Teleport_Table_x                                           0xE9C918
#define Util__FastTime_x                                           0x8F5560
#define __CopyLayout_x                                             0x63DCA0
#define __WndProc_x                                                0x6B14D0
#define __ProcessKeyboardEvent_x                                   0x6B0A70

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490630
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499620
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4993F0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493BD0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x493020

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x564A50
#define AltAdvManager__IsAbilityReady_x                            0x5637F0
#define AltAdvManager__GetAAById_x                                 0x563B80
#define AltAdvManager__CanTrainAbility_x                           0x563BF0
#define AltAdvManager__CanSeeAbility_x                             0x563F50

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CB010
#define CharacterZoneClient__HasSkill_x                            0x4D5E90
#define CharacterZoneClient__MakeMeVisible_x                       0x4D75B0
#define CharacterZoneClient__IsStackBlocked_x                      0x4C2740
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBBD0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9F50
#define CharacterZoneClient__GetItemCountInInventory_x             0x4DA030
#define CharacterZoneClient__GetCursorItemCount_x                  0x4DA110
#define CharacterZoneClient__FindAffectSlot_x                      0x4C4830
#define CharacterZoneClient__BardCastBard_x                        0x4C7260
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF5E0
#define CharacterZoneClient__GetEffect_x                           0x4BBB10
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C58A0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C5970
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C59C0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5B10
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5CF0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3B60
#define CharacterZoneClient__FindItemByGuid_x                      0x4D8510
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7F90

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D8C70
#define CBankWnd__WndNotification_x                                0x6D8A50

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E6610

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x92AE00
#define CButtonWnd__CButtonWnd_x                                   0x9299E0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x7067C0
#define CChatManager__InitContextMenu_x                            0x6FF8F0
#define CChatManager__FreeChatWindow_x                             0x705300
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9870
#define CChatManager__SetLockedActiveChatWindow_x                  0x706440
#define CChatManager__CreateChatWindow_x                           0x705940

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9980

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x93E050
#define CContextMenu__dCContextMenu_x                              0x93E280
#define CContextMenu__AddMenuItem_x                                0x93E290
#define CContextMenu__RemoveMenuItem_x                             0x93E5A0
#define CContextMenu__RemoveAllMenuItems_x                         0x93E5C0
#define CContextMenu__CheckMenuItem_x                              0x93E640
#define CContextMenu__SetMenuItem_x                                0x93E4C0
#define CContextMenu__AddSeparator_x                               0x93E420

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x93EBD0
#define CContextMenuManager__RemoveMenu_x                          0x93EC40
#define CContextMenuManager__PopupMenu_x                           0x93ED00
#define CContextMenuManager__Flush_x                               0x93EB70
#define CContextMenuManager__GetMenu_x                             0x49B910
#define CContextMenuManager__CreateDefaultMenu_x                   0x711F80

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D0600
#define CChatService__GetFriendName_x                              0x8D0610

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x707070
#define CChatWindow__Clear_x                                       0x708330
#define CChatWindow__WndNotification_x                             0x708AC0
#define CChatWindow__AddHistory_x                                  0x707BF0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93B4A0
#define CComboWnd__Draw_x                                          0x93A990
#define CComboWnd__GetCurChoice_x                                  0x93B2E0
#define CComboWnd__GetListRect_x                                   0x93AE40
#define CComboWnd__GetTextRect_x                                   0x93B510
#define CComboWnd__InsertChoice_x                                  0x93AFD0
#define CComboWnd__SetColors_x                                     0x93AFA0
#define CComboWnd__SetChoice_x                                     0x93B2B0
#define CComboWnd__GetItemCount_x                                  0x93B2F0
#define CComboWnd__GetCurChoiceText_x                              0x93B330
#define CComboWnd__GetChoiceText_x                                 0x93B300
#define CComboWnd__InsertChoiceAtIndex_x                           0x93B070

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x70F9A0
#define CContainerWnd__vftable_x                                   0xAFD73C
#define CContainerWnd__SetContainer_x                              0x710EF0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x557240
#define CDisplay__PreZoneMainUI_x                                  0x557250
#define CDisplay__CleanGameUI_x                                    0x55C6A0
#define CDisplay__GetClickedActor_x                                0x54F6A0
#define CDisplay__GetUserDefinedColor_x                            0x547D10
#define CDisplay__GetWorldFilePath_x                               0x551110
#define CDisplay__is3dON_x                                         0x54C300
#define CDisplay__ReloadUI_x                                       0x556750
#define CDisplay__WriteTextHD2_x                                   0x54C0F0
#define CDisplay__TrueDistance_x                                   0x552DD0
#define CDisplay__SetViewActor_x                                   0x54EFC0
#define CDisplay__GetFloorHeight_x                                 0x54C3C0
#define CDisplay__SetRenderWindow_x                                0x54AD40
#define CDisplay__ToggleScreenshotMode_x                           0x54EA90

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x95DF80

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x941530
#define CEditWnd__EnsureCaretVisible_x                             0x943700
#define CEditWnd__GetCaretPt_x                                     0x9426B0
#define CEditWnd__GetCharIndexPt_x                                 0x942460
#define CEditWnd__GetDisplayString_x                               0x942300
#define CEditWnd__GetHorzOffset_x                                  0x940BD0
#define CEditWnd__GetLineForPrintableChar_x                        0x943600
#define CEditWnd__GetSelStartPt_x                                  0x942710
#define CEditWnd__GetSTMLSafeText_x                                0x942120
#define CEditWnd__PointFromPrintableChar_x                         0x943230
#define CEditWnd__SelectableCharFromPoint_x                        0x9433A0
#define CEditWnd__SetEditable_x                                    0x9427E0
#define CEditWnd__SetWindowTextA_x                                 0x941EA0
#define CEditWnd__ReplaceSelection_x                               0x942EA0
#define CEditWnd__ReplaceSelection1_x                              0x942E20

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x610EF0
#define CEverQuest__ClickedPlayer_x                                0x603090
#define CEverQuest__CreateTargetIndicator_x                        0x620A60
#define CEverQuest__DeleteTargetIndicator_x                        0x620AF0
#define CEverQuest__DoTellWindow_x                                 0x4E9A60
#define CEverQuest__OutputTextToLog_x                              0x4E9D30
#define CEverQuest__DropHeldItemOnGround_x                         0x5F81E0
#define CEverQuest__dsp_chat_x                                     0x4EA0C0
#define CEverQuest__trimName_x                                     0x61CC10
#define CEverQuest__Emote_x                                        0x611750
#define CEverQuest__EnterZone_x                                    0x60B850
#define CEverQuest__GetBodyTypeDesc_x                              0x6161A0
#define CEverQuest__GetClassDesc_x                                 0x6167E0
#define CEverQuest__GetClassThreeLetterCode_x                      0x616DE0
#define CEverQuest__GetDeityDesc_x                                 0x61F2B0
#define CEverQuest__GetLangDesc_x                                  0x616FA0
#define CEverQuest__GetRaceDesc_x                                  0x6167C0
#define CEverQuest__InterpretCmd_x                                 0x61F880
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FC380
#define CEverQuest__LMouseUp_x                                     0x5FA700
#define CEverQuest__RightClickedOnPlayer_x                         0x5FCC60
#define CEverQuest__RMouseUp_x                                     0x5FB690
#define CEverQuest__SetGameState_x                                 0x5F7F70
#define CEverQuest__UPCNotificationFlush_x                         0x61CB10
#define CEverQuest__IssuePetCommand_x                              0x6183B0
#define CEverQuest__ReportSuccessfulHit_x                          0x612AA0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7216C0
#define CGaugeWnd__CalcLinesFillRect_x                             0x721720
#define CGaugeWnd__Draw_x                                          0x720D40

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AFEC0
#define CGuild__GetGuildName_x                                     0x4AE970
#define CGuild__GetGuildIndex_x                                    0x4AEF70

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73B300

//CHotButton
#define CHotButton__SetCheck_x                                     0x6321F0
#define CHotButton__SetButtonSize_x                                0x6325B0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x7483C0
#define CInvSlotMgr__MoveItem_x                                    0x747090
#define CInvSlotMgr__SelectSlot_x                                  0x748490

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7458C0
#define CInvSlot__SliderComplete_x                                 0x743600
#define CInvSlot__GetItemBase_x                                    0x742F80
#define CInvSlot__UpdateItem_x                                     0x7430F0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x749F10
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7490B0
#define CInvSlotWnd__HandleLButtonUp_x                             0x749A90

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x8041D0
#define CItemDisplayWnd__UpdateStrings_x                           0x758650
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x752370
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x752880
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x758C60
#define CItemDisplayWnd__AboutToShow_x                             0x758290
#define CItemDisplayWnd__WndNotification_x                         0x759ED0
#define CItemDisplayWnd__RequestConvertItem_x                      0x759810
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x757300
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x7580B0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x834CA0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75E400

// CLabel 
#define CLabel__Draw_x                                             0x763E10

// CListWnd
#define CListWnd__CListWnd_x                                       0x913C50
#define CListWnd__dCListWnd_x                                      0x913F70
#define CListWnd__AddColumn_x                                      0x9183B0
#define CListWnd__AddColumn1_x                                     0x918400
#define CListWnd__AddLine_x                                        0x918790
#define CListWnd__AddString_x                                      0x918590
#define CListWnd__CalculateFirstVisibleLine_x                      0x918170
#define CListWnd__CalculateVSBRange_x                              0x917F70
#define CListWnd__ClearSel_x                                       0x918F70
#define CListWnd__ClearAllSel_x                                    0x918FD0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x9199F0
#define CListWnd__Compare_x                                        0x9178A0
#define CListWnd__Draw_x                                           0x9140A0
#define CListWnd__DrawColumnSeparators_x                           0x916880
#define CListWnd__DrawHeader_x                                     0x916CE0
#define CListWnd__DrawItem_x                                       0x9171E0
#define CListWnd__DrawLine_x                                       0x9169E0
#define CListWnd__DrawSeparator_x                                  0x916920
#define CListWnd__EnableLine_x                                     0x916160
#define CListWnd__EnsureVisible_x                                  0x919910
#define CListWnd__ExtendSel_x                                      0x918EA0
#define CListWnd__GetColumnTooltip_x                               0x915CA0
#define CListWnd__GetColumnMinWidth_x                              0x915D10
#define CListWnd__GetColumnWidth_x                                 0x915C10
#define CListWnd__GetCurSel_x                                      0x9155A0
#define CListWnd__GetItemAtPoint_x                                 0x9163D0
#define CListWnd__GetItemAtPoint1_x                                0x916440
#define CListWnd__GetItemData_x                                    0x915620
#define CListWnd__GetItemHeight_x                                  0x9159E0
#define CListWnd__GetItemIcon_x                                    0x9157B0
#define CListWnd__GetItemRect_x                                    0x916250
#define CListWnd__GetItemText_x                                    0x915660
#define CListWnd__GetSelList_x                                     0x919020
#define CListWnd__GetSeparatorRect_x                               0x916680
#define CListWnd__InsertLine_x                                     0x918B80
#define CListWnd__RemoveLine_x                                     0x918CD0
#define CListWnd__SetColors_x                                      0x917F40
#define CListWnd__SetColumnJustification_x                         0x917C70
#define CListWnd__SetColumnLabel_x                                 0x918530
#define CListWnd__SetColumnWidth_x                                 0x917B90
#define CListWnd__SetCurSel_x                                      0x918DE0
#define CListWnd__SetItemColor_x                                   0x9195C0
#define CListWnd__SetItemData_x                                    0x919580
#define CListWnd__SetItemText_x                                    0x919190
#define CListWnd__ShiftColumnSeparator_x                           0x917D30
#define CListWnd__Sort_x                                           0x917A20
#define CListWnd__ToggleSel_x                                      0x918E10
#define CListWnd__SetColumnsSizable_x                              0x917DE0
#define CListWnd__SetItemWnd_x                                     0x919440
#define CListWnd__GetItemWnd_x                                     0x915800
#define CListWnd__SetItemIcon_x                                    0x919210
#define CListWnd__CalculateCustomWindowPositions_x                 0x918270
#define CListWnd__SetVScrollPos_x                                  0x917B70

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x779480
#define CMapViewWnd__GetWorldCoordinates_x                         0x777B90
#define CMapViewWnd__HandleLButtonDown_x                           0x774BD0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x799890
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79A170
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79A6A0
#define CMerchantWnd__SelectRecoverySlot_x                         0x79D640
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x798410
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A3200
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7994B0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89E060
#define CPacketScrambler__hton_x                                   0x89E050

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x932BE0
#define CSidlManager__FindScreenPieceTemplate_x                    0x932FF0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x932DE0
#define CSidlManager__CreateLabel_x                                0x7FB340
#define CSidlManager__CreateXWndFromTemplate_x                     0x935F50
#define CSidlManager__CreateXWndFromTemplate1_x                    0x936130
#define CSidlManager__CreateXWnd_x                                 0x7FB270
#define CSidlManager__CreateHotButtonWnd_x                         0x7FB840

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x92F6D0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x92F5D0
#define CSidlScreenWnd__ConvertToRes_x                             0x958AC0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x92F0C0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x92EDB0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x92EE80
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x92EF50
#define CSidlScreenWnd__DrawSidlPiece_x                            0x92FB60
#define CSidlScreenWnd__EnableIniStorage_x                         0x930030
#define CSidlScreenWnd__GetSidlPiece_x                             0x92FD50
#define CSidlScreenWnd__Init1_x                                    0x92E9D0
#define CSidlScreenWnd__LoadIniInfo_x                              0x930080
#define CSidlScreenWnd__LoadIniListWnd_x                           0x930BC0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92DDD0
#define CSidlScreenWnd__StoreIniInfo_x                             0x930740
#define CSidlScreenWnd__StoreIniVis_x                              0x930AA0
#define CSidlScreenWnd__WndNotification_x                          0x92FA70
#define CSidlScreenWnd__GetChildItem_x                             0x92FFB0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x91F810
#define CSidlScreenWnd__m_layoutCopy_x                             0x15D9190

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x697E60
#define CSkillMgr__GetSkillCap_x                                   0x698040
#define CSkillMgr__GetNameToken_x                                  0x6975E0
#define CSkillMgr__IsActivatedSkill_x                              0x697720
#define CSkillMgr__IsCombatSkill_x                                 0x697660

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x93F9B0
#define CSliderWnd__SetValue_x                                     0x93F820
#define CSliderWnd__SetNumTicks_x                                  0x93F880

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x801510

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x948300
#define CStmlWnd__ParseSTML_x                                      0x949670
#define CStmlWnd__CalculateHSBRange_x                              0x949450
#define CStmlWnd__CalculateVSBRange_x                              0x9493D0
#define CStmlWnd__CanBreakAtCharacter_x                            0x94D780
#define CStmlWnd__FastForwardToEndOfTag_x                          0x94E410
#define CStmlWnd__ForceParseNow_x                                  0x948930
#define CStmlWnd__GetNextTagPiece_x                                0x94D6E0
#define CStmlWnd__GetSTMLText_x                                    0x50C690
#define CStmlWnd__GetVisibleText_x                                 0x948950
#define CStmlWnd__InitializeWindowVariables_x                      0x94E260
#define CStmlWnd__MakeStmlColorTag_x                               0x947970
#define CStmlWnd__MakeWndNotificationTag_x                         0x9479E0
#define CStmlWnd__SetSTMLText_x                                    0x946A20
#define CStmlWnd__StripFirstSTMLLines_x                            0x94F4E0
#define CStmlWnd__UpdateHistoryString_x                            0x94E620

// CTabWnd 
#define CTabWnd__Draw_x                                            0x945B70
#define CTabWnd__DrawCurrentPage_x                                 0x9462A0
#define CTabWnd__DrawTab_x                                         0x945FC0
#define CTabWnd__GetCurrentPage_x                                  0x945370
#define CTabWnd__GetPageInnerRect_x                                0x9455B0
#define CTabWnd__GetTabInnerRect_x                                 0x9454F0
#define CTabWnd__GetTabRect_x                                      0x9453A0
#define CTabWnd__InsertPage_x                                      0x9457C0
#define CTabWnd__RemovePage_x                                      0x945930
#define CTabWnd__SetPage_x                                         0x945630
#define CTabWnd__SetPageRect_x                                     0x945AB0
#define CTabWnd__UpdatePage_x                                      0x945E80
#define CTabWnd__GetPageFromTabIndex_x                             0x945F00
#define CTabWnd__GetCurrentTabIndex_x                              0x945360

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x75E810
#define CPageWnd__SetTabText_x                                     0x944EB0
#define CPageWnd__FlashTab_x                                       0x944F10

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A91A0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91C6C0
#define CTextureFont__GetTextExtent_x                              0x91C880

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AC090
#define CHtmlComponentWnd__ValidateUri_x                           0x73CCF0
#define CHtmlWnd__SetClientCallbacks_x                             0x637640
#define CHtmlWnd__AddObserver_x                                    0x637660
#define CHtmlWnd__RemoveObserver_x                                 0x6376C0
#define Window__getProgress_x                                      0x853440
#define Window__getStatus_x                                        0x853460
#define Window__getURI_x                                           0x853470

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x955890

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x9097C0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9760
#define CXStr__CXStr1_x                                            0x507A00
#define CXStr__CXStr3_x                                            0x8F1910
#define CXStr__dCXStr_x                                            0x4783E0
#define CXStr__operator_equal_x                                    0x8F1B40
#define CXStr__operator_equal1_x                                   0x8F1B80
#define CXStr__operator_plus_equal1_x                              0x8F2610
#define CXStr__SetString_x                                         0x8F4500
#define CXStr__operator_char_p_x                                   0x8F2080
#define CXStr__GetChar_x                                           0x8F3E50
#define CXStr__Delete_x                                            0x8F3700
#define CXStr__GetUnicode_x                                        0x8F3EC0
#define CXStr__GetLength_x                                         0x4A8F50
#define CXStr__Mid_x                                               0x47D610
#define CXStr__Insert_x                                            0x8F3F20
#define CXStr__FindNext_x                                          0x8F3B70

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93DC60
#define CXWnd__BringToTop_x                                        0x922F70
#define CXWnd__Center_x                                            0x922AF0
#define CXWnd__ClrFocus_x                                          0x922900
#define CXWnd__Destroy_x                                           0x9229B0
#define CXWnd__DoAllDrawing_x                                      0x91EFA0
#define CXWnd__DrawChildren_x                                      0x91EF70
#define CXWnd__DrawColoredRect_x                                   0x91F400
#define CXWnd__DrawTooltip_x                                       0x91DAC0
#define CXWnd__DrawTooltipAtPoint_x                                0x91DB80
#define CXWnd__GetBorderFrame_x                                    0x91F260
#define CXWnd__GetChildWndAt_x                                     0x923010
#define CXWnd__GetClientClipRect_x                                 0x921200
#define CXWnd__GetScreenClipRect_x                                 0x9212D0
#define CXWnd__GetScreenRect_x                                     0x9214A0
#define CXWnd__GetRelativeRect_x                                   0x921560
#define CXWnd__GetTooltipRect_x                                    0x91F450
#define CXWnd__GetWindowTextA_x                                    0x49D000
#define CXWnd__IsActive_x                                          0x91FB80
#define CXWnd__IsDescendantOf_x                                    0x921EA0
#define CXWnd__IsReallyVisible_x                                   0x921ED0
#define CXWnd__IsType_x                                            0x923670
#define CXWnd__Move_x                                              0x921F40
#define CXWnd__Move1_x                                             0x921FF0
#define CXWnd__ProcessTransition_x                                 0x922AA0
#define CXWnd__Refade_x                                            0x9222C0
#define CXWnd__Resize_x                                            0x922520
#define CXWnd__Right_x                                             0x922D30
#define CXWnd__SetFocus_x                                          0x9228C0
#define CXWnd__SetFont_x                                           0x922930
#define CXWnd__SetKeyTooltip_x                                     0x923480
#define CXWnd__SetMouseOver_x                                      0x9203A0
#define CXWnd__StartFade_x                                         0x921D80
#define CXWnd__GetChildItem_x                                      0x923180
#define CXWnd__SetParent_x                                         0x921C40
#define CXWnd__Minimize_x                                          0x922590

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x959B40

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x925E80
#define CXWndManager__DrawWindows_x                                0x925EA0
#define CXWndManager__GetKeyboardFlags_x                           0x928660
#define CXWndManager__HandleKeyboardMsg_x                          0x928210
#define CXWndManager__RemoveWnd_x                                  0x928890
#define CXWndManager__RemovePendingDeletionWnd_x                   0x928E00

// CDBStr
#define CDBStr__GetString_x                                        0x546CB0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BFD40
#define EQ_Character__Cur_HP_x                                     0x4D2ED0
#define EQ_Character__Cur_Mana_x                                   0x4DA610
#define EQ_Character__GetCastingTimeModifier_x                     0x4C2DB0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B37A0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B38F0
#define EQ_Character__GetHPRegen_x                                 0x4E0510
#define EQ_Character__GetEnduranceRegen_x                          0x4E0B10
#define EQ_Character__GetManaRegen_x                               0x4E0F50
#define EQ_Character__Max_Endurance_x                              0x65E330
#define EQ_Character__Max_HP_x                                     0x4D2D00
#define EQ_Character__Max_Mana_x                                   0x65E130
#define EQ_Character__doCombatAbility_x                            0x660720
#define EQ_Character__UseSkill_x                                   0x4E2D50
#define EQ_Character__GetConLevel_x                                0x656B80
#define EQ_Character__IsExpansionFlag_x                            0x5B9F50
#define EQ_Character__TotalEffect_x                                0x4C6B50
#define EQ_Character__GetPCSpellAffect_x                           0x4C3B00
#define EQ_Character__SpellDuration_x                              0x4C3630
#define EQ_Character__MySpellDuration_x                            0x4B20D0
#define EQ_Character__GetAdjustedSkill_x                           0x4D5C50
#define EQ_Character__GetBaseSkill_x                               0x4D6BF0
#define EQ_Character__CanUseItem_x                                 0x4DA920

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BD560

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x6746C0

//PcClient
#define PcClient__vftable_x                                        0xAF11B8
#define PcClient__PcClient_x                                       0x6542E0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA780
#define CCharacterListWnd__EnterWorld_x                            0x4BA150
#define CCharacterListWnd__Quit_x                                  0x4B9EA0
#define CCharacterListWnd__UpdateList_x                            0x4BA340

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6387F0
#define EQ_Item__CreateItemTagString_x                             0x8975F0
#define EQ_Item__IsStackable_x                                     0x89C2D0
#define EQ_Item__GetImageNum_x                                     0x899170
#define EQ_Item__CreateItemClient_x                                0x637A40
#define EQ_Item__GetItemValue_x                                    0x89A470
#define EQ_Item__ValueSellMerchant_x                               0x89DC40
#define EQ_Item__IsKeyRingItem_x                                   0x89BBF0
#define EQ_Item__CanGoInBag_x                                      0x638910
#define EQ_Item__IsEmpty_x                                         0x89B720
#define EQ_Item__GetMaxItemCount_x                                 0x89A880
#define EQ_Item__GetHeldItem_x                                     0x899040
#define EQ_Item__GetAugmentFitBySlot_x                             0x896E40

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x565720
#define EQ_LoadingS__Array_x                                       0xC12128

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65EC30
#define EQ_PC__GetAlternateAbilityId_x                             0x8A70A0
#define EQ_PC__GetCombatAbility_x                                  0x8A7710
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A7780
#define EQ_PC__GetItemRecastTimer_x                                0x660CA0
#define EQ_PC__HasLoreItem_x                                       0x6573F0
#define EQ_PC__AlertInventoryChanged_x                             0x6564B0
#define EQ_PC__GetPcZoneClient_x                                   0x6836E0
#define EQ_PC__RemoveMyAffect_x                                    0x663ED0
#define EQ_PC__GetKeyRingItems_x                                   0x8A8050
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A7DD0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A8350

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5C03E0
#define EQItemList__add_object_x                                   0x5EDA20
#define EQItemList__add_item_x                                     0x5C0940
#define EQItemList__delete_item_x                                  0x5C0990
#define EQItemList__FreeItemList_x                                 0x5C0890

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x543820

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x675FC0
#define EQPlayer__dEQPlayer_x                                      0x669340
#define EQPlayer__DoAttack_x                                       0x67DE80
#define EQPlayer__EQPlayer_x                                       0x669A00
#define EQPlayer__SetNameSpriteState_x                             0x66DCD0
#define EQPlayer__SetNameSpriteTint_x                              0x66EBB0
#define PlayerBase__HasProperty_j_x                                0x9889B0
#define EQPlayer__IsTargetable_x                                   0x988E50
#define EQPlayer__CanSee_x                                         0x988CB0
#define EQPlayer__CanSee1_x                                        0x988D80
#define PlayerBase__GetVisibilityLineSegment_x                     0x988A70

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x681180
#define PlayerZoneClient__GetLevel_x                               0x683720
#define PlayerZoneClient__IsValidTeleport_x                        0x5EEB90
#define PlayerZoneClient__LegalPlayerRace_x                        0x55E560

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x678D80
#define EQPlayerManager__GetSpawnByName_x                          0x678E30
#define EQPlayerManager__GetPlayerFromPartialName_x                0x678EC0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63BF00
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63BF80
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63BFC0
#define KeypressHandler__ClearCommandStateArray_x                  0x63D3B0
#define KeypressHandler__HandleKeyDown_x                           0x63D3D0
#define KeypressHandler__HandleKeyUp_x                             0x63D470
#define KeypressHandler__SaveKeymapping_x                          0x63D8C0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7752F0
#define MapViewMap__SaveEx_x                                       0x7786B0
#define MapViewMap__SetZoom_x                                      0x77CD70

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BB520

// StringTable 
#define StringTable__getString_x                                   0x8B6410

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x663B40
#define PcZoneClient__RemovePetEffect_x                            0x664170
#define PcZoneClient__HasAlternateAbility_x                        0x65DF60
#define PcZoneClient__GetCurrentMod_x                              0x4E5E70
#define PcZoneClient__GetModCap_x                                  0x4E5D70
#define PcZoneClient__CanEquipItem_x                               0x65E610
#define PcZoneClient__GetItemByID_x                                0x661110
#define PcZoneClient__GetItemByItemClass_x                         0x661260
#define PcZoneClient__RemoveBuffEffect_x                           0x664190
#define PcZoneClient__BandolierSwap_x                              0x65F1F0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x660C40

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F3700

//IconCache
#define IconCache__GetIcon_x                                       0x717050

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x70EB30
#define CContainerMgr__CloseContainer_x                            0x70EE00
#define CContainerMgr__OpenExperimentContainer_x                   0x70F880

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CDB20

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x6309B0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76B8B0
#define CLootWnd__RequestLootSlot_x                                0x76AB90

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58D0E0
#define EQ_Spell__SpellAffects_x                                   0x58D550
#define EQ_Spell__SpellAffectBase_x                                0x58D310
#define EQ_Spell__IsStackable_x                                    0x4CA920
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CA710
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7A60
#define EQ_Spell__IsSPAStacking_x                                  0x58E3A0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58D8B0
#define EQ_Spell__IsNoRemove_x                                     0x4CA900
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58E3B0
#define __IsResEffectSpell_x                                       0x4C9BA0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD3F0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C5CB0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x8148C0
#define CTargetWnd__WndNotification_x                              0x814100
#define CTargetWnd__RefreshTargetBuffs_x                           0x8143D0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x813270

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x818F30
#define CTaskWnd__ConfirmAbandonTask_x                             0x81BB70

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x541200
#define CTaskManager__HandleMessage_x                              0x53F660
#define CTaskManager__GetTaskStatus_x                              0x5412B0
#define CTaskManager__GetElementDescription_x                      0x541330

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x588210
#define EqSoundManager__PlayScriptMp3_x                            0x5884D0
#define EqSoundManager__SoundAssistPlay_x                          0x69BDA0
#define EqSoundManager__WaveInstancePlay_x                         0x69B310

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x532500

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x9443C0
#define CTextureAnimation__Draw_x                                  0x9445C0

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x940310

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56D2B0
#define CAltAbilityData__GetMercMaxRank_x                          0x56D240
#define CAltAbilityData__GetMaxRank_x                              0x562670

//CTargetRing
#define CTargetRing__Cast_x                                        0x62EAD0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA6F0
#define CharacterBase__CreateItemGlobalIndex_x                     0x518FC0
#define CharacterBase__CreateItemIndex_x                           0x636BF0
#define CharacterBase__GetItemPossession_x                         0x5052A0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CE2F0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CE350
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F5AB0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F62E0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F6390

//messages
#define msg_spell_worn_off_x                                       0x5B1F60
#define msg_new_text_x                                             0x5A68E0
#define __msgTokenTextParam_x                                      0x5B41F0
#define msgTokenText_x                                             0x5B4440

//SpellManager
#define SpellManager__vftable_x                                    0xAD9544
#define SpellManager__SpellManager_x                               0x69F0D0
#define Spellmanager__LoadTextSpells_x                             0x69F9C0
#define SpellManager__GetSpellByGroupAndRank_x                     0x69F2A0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98C870

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x519640
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B83C0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x64FA00
#define ItemGlobalIndex__IsValidIndex_x                            0x5196D0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C6650
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C68D0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x764150

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x713220
#define CCursorAttachment__AttachToCursor1_x                       0x713260
#define CCursorAttachment__Deactivate_x                            0x714250

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x936F90
#define CSidlManagerBase__CreatePageWnd_x                          0x936780
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x932A00
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x932990

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x954440
#define CEQSuiteTextureLoader__GetTexture_x                        0x954100

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x516540
#define CFindItemWnd__WndNotification_x                            0x517020
#define CFindItemWnd__Update_x                                     0x517B90
#define CFindItemWnd__PickupSelectedItem_x                         0x515D70

//IString
#define IString__Append_x                                          0x506AC0

//Camera
#define CDisplay__cameraType_x                                     0xDEA290
#define EverQuest__Cameras_x                                       0xEA5098

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51EF40
#define LootFiltersManager__GetItemFilterData_x                    0x51E850
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51E880
#define LootFiltersManager__SetItemLootFilter_x                    0x51EAA0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BB8B0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x992500
#define CResolutionHandler__GetWindowedStyle_x                     0x696660

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70B7E0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8DBD00
#define CDistillerInfo__Instance_x                                 0x8DBCA0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72A6B0
#define CGroupWnd__UpdateDisplay_x                                 0x729A00

//ItemBase
#define ItemBase__IsLore_x                                         0x89BCA0
#define ItemBase__IsLoreEquipped_x                                 0x89BD10

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5ED980
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EDAC0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EDB20

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68BE20
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x68F780

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50CC90

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F90C0
#define FactionManagerClient__HandleFactionMessage_x               0x4F9730
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F9CF0
#define FactionManagerClient__GetMaxFaction_x                      0x4F9D0F
#define FactionManagerClient__GetMinFaction_x                      0x4F9CC0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x505270

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91B6E0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C310

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x5054D0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56C750

//CTargetManager
#define CTargetManager__Get_x                                      0x6A2900

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68BE20

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8F60

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5C0830

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF42730

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6BF430
#define CAAWnd__UpdateSelected_x                                   0x6BBCA0
#define CAAWnd__Update_x                                           0x6BE750

//CXRect
#define CXRect__operator_and_x                                     0x721780

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x4831F0

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
