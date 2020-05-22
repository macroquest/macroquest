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
#define __ExpectedVersionDate                                     "May 21 2020"
#define __ExpectedVersionTime                                     "16:02:04"
#define __ActualVersionDate_x                                      0xB1C480
#define __ActualVersionTime_x                                      0xB1C474
#define __ActualVersionBuild_x                                     0xB08114

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x63EEC0
#define __MemChecker1_x                                            0x9131C0
#define __MemChecker2_x                                            0x6CDD70
#define __MemChecker3_x                                            0x6CDCC0
#define __MemChecker4_x                                            0x869770
#define __EncryptPad0_x                                            0xC54500
#define __EncryptPad1_x                                            0xCB2668
#define __EncryptPad2_x                                            0xC64D98
#define __EncryptPad3_x                                            0xC64998
#define __EncryptPad4_x                                            0xCA2C18
#define __EncryptPad5_x                                            0xF7386C
#define __AC1_x                                                    0x826186
#define __AC2_x                                                    0x5F8A1F
#define __AC3_x                                                    0x60006F
#define __AC4_x                                                    0x604030
#define __AC5_x                                                    0x60A2DF
#define __AC6_x                                                    0x60E7E6
#define __AC7_x                                                    0x5F8490
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x76F58

// Direct Input
#define DI8__Main_x                                                0xF7388C
#define DI8__Keyboard_x                                            0xF73890
#define DI8__Mouse_x                                               0xF738AC
#define DI8__Mouse_Copy_x                                          0xECEF14
#define DI8__Mouse_Check_x                                         0xF74358
#define __AutoSkillArray_x                                         0xECFE2C
#define __Attack_x                                                 0xF6DC53
#define __Autofire_x                                               0xF6DC54
#define __BindList_x                                               0xC42F30
#define g_eqCommandStates_x                                        0xC43CB0
#define __Clicks_x                                                 0xECEFCC
#define __CommandList_x                                            0xC44870
#define __CurrentMapLabel_x                                        0xF8671C
#define __CurrentSocial_x                                          0xC2C7CC
#define __DoAbilityList_x                                          0xF05774
#define __do_loot_x                                                0x5C4340
#define __DrawHandler_x                                            0x1605A98
#define __GroupCount_x                                             0xEC9F1A
#define __Guilds_x                                                 0xECDE50
#define __gWorld_x                                                 0xEC9F04
#define __HWnd_x                                                   0xF73930
#define __heqmain_x                                                0xF767EC
#define __InChatMode_x                                             0xECEEFC
#define __LastTell_x                                               0xED0E70
#define __LMouseHeldTime_x                                         0xECF038
#define __Mouse_x                                                  0xF73878
#define __MouseLook_x                                              0xECEF92
#define __MouseEventTime_x                                         0xF6E734
#define __gpbCommandEvent_x                                        0xECA118
#define __NetStatusToggle_x                                        0xECEF95
#define __PCNames_x                                                0xED041C
#define __RangeAttackReady_x                                       0xED0110
#define __RMouseHeldTime_x                                         0xECF034
#define __RunWalkState_x                                           0xECEF00
#define __ScreenMode_x                                             0xE15254
#define __ScreenX_x                                                0xECEEB4
#define __ScreenY_x                                                0xECEEB0
#define __ScreenXMax_x                                             0xECEEB8
#define __ScreenYMax_x                                             0xECEEBC
#define __ServerHost_x                                             0xEC79FB
#define __ServerName_x                                             0xF05734
#define __ShiftKeyDown_x                                           0xECF58C
#define __ShowNames_x                                              0xED02CC
#define EverQuestInfo__bSocialChanged_x                            0xF057BC
#define __Socials_x                                                0xF05834
#define __SubscriptionType_x                                       0xFCAC28
#define __TargetAggroHolder_x                                      0xF890D0
#define __ZoneType_x                                               0xECF390
#define __GroupAggro_x                                             0xF89110
#define __LoginName_x                                              0xF73FEC
#define __Inviter_x                                                0xF6DBD0
#define __AttackOnAssist_x                                         0xED0288
#define __UseTellWindows_x                                         0xED05B8
#define __gfMaxZoomCameraDistance_x                                0xB11D70
#define __gfMaxCameraDistance_x                                    0xB3E1F4
#define __pulAutoRun_x                                             0xECEFB0
#define __pulForward_x                                             0xED05F0
#define __pulBackward_x                                            0xED05F4
#define __pulTurnRight_x                                           0xED05F8
#define __pulTurnLeft_x                                            0xED05FC
#define __pulStrafeLeft_x                                          0xED0600
#define __pulStrafeRight_x                                         0xED0604

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xECA1E8
#define instEQZoneInfo_x                                           0xECF188
#define pinstActiveBanker_x                                        0xEC78EC
#define pinstActiveCorpse_x                                        0xEC78E4
#define pinstActiveGMaster_x                                       0xEC78E8
#define pinstActiveMerchant_x                                      0xEC78E0
#define pinstAltAdvManager_x                                       0xE16418
#define pinstBandageTarget_x                                       0xEC7D0C
#define pinstCamActor_x                                            0xE15244
#define pinstCDBStr_x                                              0xE15134
#define pinstCDisplay_x                                            0xEC9D68
#define pinstCEverQuest_x                                          0xF738A8
#define pinstEverQuestInfo_x                                       0xECEEA8
#define pinstCharData_x                                            0xECA108
#define pinstCharSpawn_x                                           0xEC7D44
#define pinstControlledMissile_x                                   0xEC7D54
#define pinstControlledPlayer_x                                    0xEC7D44
#define pinstCResolutionHandler_x                                  0x1605CC8
#define pinstCSidlManager_x                                        0x1604C60
#define pinstCXWndManager_x                                        0x1604C5C
#define instDynamicZone_x                                          0xECDD28
#define pinstDZMember_x                                            0xECDE38
#define pinstDZTimerInfo_x                                         0xECDE3C
#define pinstEqLogin_x                                             0xF73938
#define instEQMisc_x                                               0xE15078
#define pinstEQSoundManager_x                                      0xE173E8
#define pinstEQSpellStrings_x                                      0xCD7A90
#define instExpeditionLeader_x                                     0xECDD72
#define instExpeditionName_x                                       0xECDDB2
#define pinstGroup_x                                               0xEC9F16
#define pinstImeManager_x                                          0x1604C58
#define pinstLocalPlayer_x                                         0xEC78DC
#define pinstMercenaryData_x                                       0xF7022C
#define pinstMercenaryStats_x                                      0xF8921C
#define pinstModelPlayer_x                                         0xEC78F4
#define pinstPCData_x                                              0xECA108
#define pinstSkillMgr_x                                            0xF72390
#define pinstSpawnManager_x                                        0xF70E38
#define pinstSpellManager_x                                        0xF725D0
#define pinstSpellSets_x                                           0xF6687C
#define pinstStringTable_x                                         0xECA110
#define pinstSwitchManager_x                                       0xEC7788
#define pinstTarget_x                                              0xEC7D40
#define pinstTargetObject_x                                        0xEC7D4C
#define pinstTargetSwitch_x                                        0xEC9D60
#define pinstTaskMember_x                                          0xE14F08
#define pinstTrackTarget_x                                         0xEC7D48
#define pinstTradeTarget_x                                         0xEC78F0
#define instTributeActive_x                                        0xE15099
#define pinstViewActor_x                                           0xE15240
#define pinstWorldData_x                                           0xEC7D5C
#define pinstZoneAddr_x                                            0xECF428
#define pinstPlayerPath_x                                          0xF70ED0
#define pinstTargetIndicator_x                                     0xF72838
#define EQObject_Top_x                                             0xEC78D8
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xE159BC
#define pinstCAchievementsWnd_x                                    0xE15A34
#define pinstCActionsWnd_x                                         0xE159E4
#define pinstCAdvancedDisplayOptionsWnd_x                          0xE15258
#define pinstCAdvancedLootWnd_x                                    0xE151F8
#define pinstCAdventureLeaderboardWnd_x                            0xF7FEF0
#define pinstCAdventureRequestWnd_x                                0xF7FFA0
#define pinstCAdventureStatsWnd_x                                  0xF80050
#define pinstCAggroMeterWnd_x                                      0xE15264
#define pinstCAlarmWnd_x                                           0xE151D0
#define pinstCAlertHistoryWnd_x                                    0xE152C0
#define pinstCAlertStackWnd_x                                      0xE15200
#define pinstCAlertWnd_x                                           0xE15220
#define pinstCAltStorageWnd_x                                      0xF803B0
#define pinstCAudioTriggersWindow_x                                0xCC9DC0
#define pinstCAuraWnd_x                                            0xE15204
#define pinstCAvaZoneWnd_x                                         0xE1527C
#define pinstCBandolierWnd_x                                       0xE15248
#define pinstCBankWnd_x                                            0xE152A8
#define pinstCBarterMerchantWnd_x                                  0xF815F0
#define pinstCBarterSearchWnd_x                                    0xF816A0
#define pinstCBarterWnd_x                                          0xF81750
#define pinstCBazaarConfirmationWnd_x                              0xE151E0
#define pinstCBazaarSearchWnd_x                                    0xE159C0
#define pinstCBazaarWnd_x                                          0xE15A50
#define pinstCBlockedBuffWnd_x                                     0xE15214
#define pinstCBlockedPetBuffWnd_x                                  0xE15238
#define pinstCBodyTintWnd_x                                        0xE159F0
#define pinstCBookWnd_x                                            0xE15290
#define pinstCBreathWnd_x                                          0xE159D0
#define pinstCBuffWindowNORMAL_x                                   0xE151F0
#define pinstCBuffWindowSHORT_x                                    0xE151F4
#define pinstCBugReportWnd_x                                       0xE152A0
#define pinstCButtonWnd_x                                          0x1604EC8
#define pinstCCastingWnd_x                                         0xE15280
#define pinstCCastSpellWnd_x                                       0xE159C8
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE15A08
#define pinstCChatWindowManager_x                                  0xF82210
#define pinstCClaimWnd_x                                           0xF82368
#define pinstCColorPickerWnd_x                                     0xE15308
#define pinstCCombatAbilityWnd_x                                   0xE15A64
#define pinstCCombatSkillsSelectWnd_x                              0xE15A18
#define pinstCCompassWnd_x                                         0xE159E8
#define pinstCConfirmationDialog_x                                 0xF87268
#define pinstCContainerMgr_x                                       0xE15A04
#define pinstCContextMenuManager_x                                 0x1604C18
#define pinstCCursorAttachment_x                                   0xE15270
#define pinstCDynamicZoneWnd_x                                     0xF82930
#define pinstCEditLabelWnd_x                                       0xE151EC
#define pinstCEQMainWnd_x                                          0xF82B78
#define pinstCEventCalendarWnd_x                                   0xE159B8
#define pinstCExtendedTargetWnd_x                                  0xE15234
#define pinstCFacePick_x                                           0xE15A2C
#define pinstCFactionWnd_x                                         0xE15A40
#define pinstCFellowshipWnd_x                                      0xF82D78
#define pinstCFileSelectionWnd_x                                   0xE152E8
#define pinstCFindItemWnd_x                                        0xE15A24
#define pinstCFindLocationWnd_x                                    0xF82ED0
#define pinstCFriendsWnd_x                                         0xE15A28
#define pinstCGemsGameWnd_x                                        0xE15A38
#define pinstCGiveWnd_x                                            0xE151DC
#define pinstCGroupSearchFiltersWnd_x                              0xE15288
#define pinstCGroupSearchWnd_x                                     0xF832C8
#define pinstCGroupWnd_x                                           0xF83378
#define pinstCGuildBankWnd_x                                       0xED026C
#define pinstCGuildCreationWnd_x                                   0xF834D8
#define pinstCGuildMgmtWnd_x                                       0xF83588
#define pinstCharacterCreation_x                                   0xE15A1C
#define pinstCHelpWnd_x                                            0xE151D4
#define pinstCHeritageSelectionWnd_x                               0xE15A44
#define pinstCHotButtonWnd_x                                       0xF856E0
#define pinstCHotButtonWnd1_x                                      0xF856E0
#define pinstCHotButtonWnd2_x                                      0xF856E4
#define pinstCHotButtonWnd3_x                                      0xF856E8
#define pinstCHotButtonWnd4_x                                      0xF856EC
#define pinstCIconSelectionWnd_x                                   0xE15268
#define pinstCInspectWnd_x                                         0xE1523C
#define pinstCInventoryWnd_x                                       0xE1520C
#define pinstCInvSlotMgr_x                                         0xE159C4
#define pinstCItemDisplayManager_x                                 0xF85C70
#define pinstCItemExpTransferWnd_x                                 0xF85DA0
#define pinstCItemOverflowWnd_x                                    0xE159CC
#define pinstCJournalCatWnd_x                                      0xE1532C
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE152C4
#define pinstCKeyRingWnd_x                                         0xE15278
#define pinstCLargeDialogWnd_x                                     0xF87EE8
#define pinstCLayoutCopyWnd_x                                      0xF860F0
#define pinstCLFGuildWnd_x                                         0xF861A0
#define pinstCLoadskinWnd_x                                        0xE15A4C
#define pinstCLootFiltersCopyWnd_x                                 0xCE6410
#define pinstCLootFiltersWnd_x                                     0xE15208
#define pinstCLootSettingsWnd_x                                    0xE15230
#define pinstCLootWnd_x                                            0xE15540
#define pinstCMailAddressBookWnd_x                                 0xE159D4
#define pinstCMailCompositionWnd_x                                 0xE159B4
#define pinstCMailIgnoreListWnd_x                                  0xE152EC
#define pinstCMailWnd_x                                            0xE15318
#define pinstCManageLootWnd_x                                      0xE168C8
#define pinstCMapToolbarWnd_x                                      0xE151D8
#define pinstCMapViewWnd_x                                         0xE15A48
#define pinstCMarketplaceWnd_x                                     0xE15210
#define pinstCMerchantWnd_x                                        0xE155AC
#define pinstCMIZoneSelectWnd_x                                    0xF869D8
#define pinstCMusicPlayerWnd_x                                     0xE152B4
#define pinstCNameChangeMercWnd_x                                  0xE15A5C
#define pinstCNameChangePetWnd_x                                   0xE15A3C
#define pinstCNameChangeWnd_x                                      0xE151E4
#define pinstCNoteWnd_x                                            0xE15A58
#define pinstCObjectPreviewWnd_x                                   0xE1522C
#define pinstCOptionsWnd_x                                         0xE15A68
#define pinstCPetInfoWnd_x                                         0xE152E0
#define pinstCPetitionQWnd_x                                       0xE15A0C
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE159F4
#define pinstCPlayerWnd_x                                          0xE152E4
#define pinstCPopupWndManager_x                                    0xF87268
#define pinstCProgressionSelectionWnd_x                            0xF87318
#define pinstCPurchaseGroupWnd_x                                   0xE15298
#define pinstCPurchaseWnd_x                                        0xE1526C
#define pinstCPvPLeaderboardWnd_x                                  0xF873C8
#define pinstCPvPStatsWnd_x                                        0xF87478
#define pinstCQuantityWnd_x                                        0xE152C8
#define pinstCRaceChangeWnd_x                                      0xE151FC
#define pinstCRaidOptionsWnd_x                                     0xE1528C
#define pinstCRaidWnd_x                                            0xE15544
#define pinstCRealEstateItemsWnd_x                                 0xE15A30
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE159E0
#define pinstCRealEstateManageWnd_x                                0xE152A4
#define pinstCRealEstateNeighborhoodWnd_x                          0xE152BC
#define pinstCRealEstatePlotSearchWnd_x                            0xE152DC
#define pinstCRealEstatePurchaseWnd_x                              0xE15314
#define pinstCRespawnWnd_x                                         0xE15228
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE15A10
#define pinstCSendMoneyWnd_x                                       0xE151E8
#define pinstCServerListWnd_x                                      0xE15320
#define pinstCSkillsSelectWnd_x                                    0xE15A00
#define pinstCSkillsWnd_x                                          0xE159EC
#define pinstCSocialEditWnd_x                                      0xE15274
#define pinstCSocialWnd_x                                          0xE15A54
#define pinstCSpellBookWnd_x                                       0xE15A60
#define pinstCStoryWnd_x                                           0xE159DC
#define pinstCTargetOfTargetWnd_x                                  0xF892A0
#define pinstCTargetWnd_x                                          0xE15224
#define pinstCTaskOverlayWnd_x                                     0xE15294
#define pinstCTaskSelectWnd_x                                      0xF893F8
#define pinstCTaskManager_x                                        0xCE6D50
#define pinstCTaskTemplateSelectWnd_x                              0xF894A8
#define pinstCTaskWnd_x                                            0xF89558
#define pinstCTextEntryWnd_x                                       0xE15284
#define pinstCTimeLeftWnd_x                                        0xE159F8
#define pinstCTipWndCONTEXT_x                                      0xF8975C
#define pinstCTipWndOFDAY_x                                        0xF89758
#define pinstCTitleWnd_x                                           0xF89808
#define pinstCTrackingWnd_x                                        0xE15218
#define pinstCTradeskillWnd_x                                      0xF89970
#define pinstCTradeWnd_x                                           0xE159FC
#define pinstCTrainWnd_x                                           0xE15324
#define pinstCTributeBenefitWnd_x                                  0xF89B70
#define pinstCTributeMasterWnd_x                                   0xF89C20
#define pinstCTributeTrophyWnd_x                                   0xF89CD0
#define pinstCVideoModesWnd_x                                      0xE1531C
#define pinstCVoiceMacroWnd_x                                      0xF72FA0
#define pinstCVoteResultsWnd_x                                     0xE15A20
#define pinstCVoteWnd_x                                            0xE15A14
#define pinstCWebManager_x                                         0xF7361C
#define pinstCZoneGuideWnd_x                                       0xE1529C
#define pinstCZonePathWnd_x                                        0xE152AC

#define pinstEQSuiteTextureLoader_x                                0xCB4140
#define pinstItemIconCache_x                                       0xF82B30
#define pinstLootFiltersManager_x                                  0xCE64C0
#define pinstRewardSelectionWnd_x                                  0xF87BC0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5BF710
#define __CastRay2_x                                               0x5BF760
#define __ConvertItemTags_x                                        0x5DB5A0
#define __CleanItemTags_x                                          0x47CFD0
#define __DoesFileExist_x                                          0x9161F0
#define __EQGetTime_x                                              0x912C90
#define __ExecuteCmd_x                                             0x5B7FA0
#define __FixHeading_x                                             0x9AE130
#define __GameLoop_x                                               0x6CCF40
#define __get_bearing_x                                            0x5BF280
#define __get_melee_range_x                                        0x5BF950
#define __GetAnimationCache_x                                      0x7323B0
#define __GetGaugeValueFromEQ_x                                    0x824630
#define __GetLabelFromEQ_x                                         0x826110
#define __GetXTargetType_x                                         0x9AFBF0
#define __HandleMouseWheel_x                                       0x6CDE20
#define __HeadingDiff_x                                            0x9AE1A0
#define __HelpPath_x                                               0xF6E324
#define __LoadFrontEnd_x                                           0x6CA260
#define __NewUIINI_x                                               0x824300
#define __ProcessGameEvents_x                                      0x620380
#define __ProcessMouseEvent_x                                      0x61FB40
#define __SaveColors_x                                             0x5598A0
#define __STMLToText_x                                             0x951730
#define __ToggleKeyRingItem_x                                      0x51A300
#define CMemoryMappedFile__SetFile_x                               0xA9D560
#define CrashDetected_x                                            0x6CBD00
#define DrawNetStatus_x                                            0x64C310
#define Expansion_HoT_x                                            0xED0274
#define Teleport_Table_Size_x                                      0xECA1A4
#define Teleport_Table_x                                           0xEC7D60
#define Util__FastTime_x                                           0x912860

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490190
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4990A0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x498E70
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493730
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492B80

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x561B10
#define AltAdvManager__IsAbilityReady_x                            0x5608B0
#define AltAdvManager__GetAAById_x                                 0x560C40
#define AltAdvManager__CanTrainAbility_x                           0x560CB0
#define AltAdvManager__CanSeeAbility_x                             0x561010

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CAB90
#define CharacterZoneClient__HasSkill_x                            0x4D5A10
#define CharacterZoneClient__MakeMeVisible_x                       0x4D7130
#define CharacterZoneClient__IsStackBlocked_x                      0x4BF340
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BB970
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9AA0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9B80
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9C60
#define CharacterZoneClient__FindAffectSlot_x                      0x4C3A40
#define CharacterZoneClient__BardCastBard_x                        0x4C65C0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BBA40
#define CharacterZoneClient__GetEffect_x                           0x4BB8B0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C4A90
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C4B60
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C4BB0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4D00
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4ED0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B36A0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D8090
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7B10

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6F39A0
#define CBankWnd__WndNotification_x                                0x6F3780

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x700F00

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x62EB80
#define CButtonWnd__CButtonWnd_x                                   0x94DB00

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x721420
#define CChatManager__InitContextMenu_x                            0x71A550
#define CChatManager__FreeChatWindow_x                             0x71FF60
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E90A0
#define CChatManager__SetLockedActiveChatWindow_x                  0x7210A0
#define CChatManager__CreateChatWindow_x                           0x7205A0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E91B0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x962110
#define CContextMenu__dCContextMenu_x                              0x962340
#define CContextMenu__AddMenuItem_x                                0x962350
#define CContextMenu__RemoveMenuItem_x                             0x962650
#define CContextMenu__RemoveAllMenuItems_x                         0x962670
#define CContextMenu__CheckMenuItem_x                              0x9626F0
#define CContextMenu__SetMenuItem_x                                0x962580
#define CContextMenu__AddSeparator_x                               0x9624E0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x962C90
#define CContextMenuManager__RemoveMenu_x                          0x962D00
#define CContextMenuManager__PopupMenu_x                           0x962DC0
#define CContextMenuManager__Flush_x                               0x962C30
#define CContextMenuManager__GetMenu_x                             0x49B1C0
#define CContextMenuManager__CreateDefaultMenu_x                   0x72CBC0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8EDFE0
#define CChatService__GetFriendName_x                              0x8EDFF0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x721C50
#define CChatWindow__Clear_x                                       0x722F10
#define CChatWindow__WndNotification_x                             0x7236A0
#define CChatWindow__AddHistory_x                                  0x7227D0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x95F560
#define CComboWnd__Draw_x                                          0x95EA60
#define CComboWnd__GetCurChoice_x                                  0x95F3A0
#define CComboWnd__GetListRect_x                                   0x95EF10
#define CComboWnd__GetTextRect_x                                   0x95F5C0
#define CComboWnd__InsertChoice_x                                  0x95F0A0
#define CComboWnd__SetColors_x                                     0x95F070
#define CComboWnd__SetChoice_x                                     0x95F370
#define CComboWnd__GetItemCount_x                                  0x95F3B0
#define CComboWnd__GetCurChoiceText_x                              0x95F3F0
#define CComboWnd__GetChoiceText_x                                 0x95F3C0
#define CComboWnd__InsertChoiceAtIndex_x                           0x95F130

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x72A5D0
#define CContainerWnd__vftable_x                                   0xB2566C
#define CContainerWnd__SetContainer_x                              0x72BB30

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x554250
#define CDisplay__PreZoneMainUI_x                                  0x554260
#define CDisplay__CleanGameUI_x                                    0x559660
#define CDisplay__GetClickedActor_x                                0x54C610
#define CDisplay__GetUserDefinedColor_x                            0x544C70
#define CDisplay__GetWorldFilePath_x                               0x54E080
#define CDisplay__is3dON_x                                         0x549270
#define CDisplay__ReloadUI_x                                       0x5536D0
#define CDisplay__WriteTextHD2_x                                   0x549060
#define CDisplay__TrueDistance_x                                   0x54FD40
#define CDisplay__SetViewActor_x                                   0x54BF30
#define CDisplay__GetFloorHeight_x                                 0x549330
#define CDisplay__SetRenderWindow_x                                0x547C90
#define CDisplay__ToggleScreenshotMode_x                           0x54BA00

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x981D90

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x965650
#define CEditWnd__EnsureCaretVisible_x                             0x9677C0
#define CEditWnd__GetCaretPt_x                                     0x9667A0
#define CEditWnd__GetCharIndexPt_x                                 0x966560
#define CEditWnd__GetDisplayString_x                               0x966410
#define CEditWnd__GetHorzOffset_x                                  0x964CA0
#define CEditWnd__GetLineForPrintableChar_x                        0x9676C0
#define CEditWnd__GetSelStartPt_x                                  0x966800
#define CEditWnd__GetSTMLSafeText_x                                0x966230
#define CEditWnd__PointFromPrintableChar_x                         0x967300
#define CEditWnd__SelectableCharFromPoint_x                        0x967470
#define CEditWnd__SetEditable_x                                    0x9668C0
#define CEditWnd__SetWindowTextA_x                                 0x965FB0
#define CEditWnd__ReplaceSelection_x                               0x966F80
#define CEditWnd__ReplaceSelection1_x                              0x966F00

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x60DCC0
#define CEverQuest__ClickedPlayer_x                                0x5FFE50
#define CEverQuest__CreateTargetIndicator_x                        0x61D620
#define CEverQuest__DeleteTargetIndicator_x                        0x61D6B0
#define CEverQuest__DoTellWindow_x                                 0x4E9290
#define CEverQuest__OutputTextToLog_x                              0x4E9560
#define CEverQuest__DropHeldItemOnGround_x                         0x5F4FB0
#define CEverQuest__dsp_chat_x                                     0x4E98F0
#define CEverQuest__trimName_x                                     0x619830
#define CEverQuest__Emote_x                                        0x60E520
#define CEverQuest__EnterZone_x                                    0x6085B0
#define CEverQuest__GetBodyTypeDesc_x                              0x612DE0
#define CEverQuest__GetClassDesc_x                                 0x613420
#define CEverQuest__GetClassThreeLetterCode_x                      0x613A20
#define CEverQuest__GetDeityDesc_x                                 0x61BE70
#define CEverQuest__GetLangDesc_x                                  0x613BE0
#define CEverQuest__GetRaceDesc_x                                  0x613400
#define CEverQuest__InterpretCmd_x                                 0x61C440
#define CEverQuest__LeftClickedOnPlayer_x                          0x5F9140
#define CEverQuest__LMouseUp_x                                     0x5F74D0
#define CEverQuest__RightClickedOnPlayer_x                         0x5F9A20
#define CEverQuest__RMouseUp_x                                     0x5F8450
#define CEverQuest__SetGameState_x                                 0x5F4D40
#define CEverQuest__UPCNotificationFlush_x                         0x619730
#define CEverQuest__IssuePetCommand_x                              0x614FE0
#define CEverQuest__ReportSuccessfulHit_x                          0x60F870

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x73C560
#define CGaugeWnd__CalcLinesFillRect_x                             0x73C5C0
#define CGaugeWnd__Draw_x                                          0x73BBE0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF920
#define CGuild__GetGuildName_x                                     0x4AE3D0
#define CGuild__GetGuildIndex_x                                    0x4AE9D0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x7566F0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x62EF40

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x7636F0
#define CInvSlotMgr__MoveItem_x                                    0x762450
#define CInvSlotMgr__SelectSlot_x                                  0x7637C0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x760C90
#define CInvSlot__SliderComplete_x                                 0x75E9F0
#define CInvSlot__GetItemBase_x                                    0x75E370
#define CInvSlot__UpdateItem_x                                     0x75E4E0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x765250
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7643E0
#define CInvSlotWnd__HandleLButtonUp_x                             0x764DD0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x81F9D0
#define CItemDisplayWnd__UpdateStrings_x                           0x773950
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x76D600
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x76DB20
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x773F40
#define CItemDisplayWnd__AboutToShow_x                             0x773590
#define CItemDisplayWnd__WndNotification_x                         0x775060
#define CItemDisplayWnd__RequestConvertItem_x                      0x774AE0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x7725F0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x7733B0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x858770

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x779560

// CLabel 
#define CLabel__Draw_x                                             0x77EF60

// CListWnd
#define CListWnd__CListWnd_x                                       0x937C50
#define CListWnd__dCListWnd_x                                      0x937F70
#define CListWnd__AddColumn_x                                      0x93C3D0
#define CListWnd__AddColumn1_x                                     0x93C420
#define CListWnd__AddLine_x                                        0x93C7B0
#define CListWnd__AddString_x                                      0x93C5B0
#define CListWnd__CalculateFirstVisibleLine_x                      0x93C190
#define CListWnd__CalculateVSBRange_x                              0x93BF70
#define CListWnd__ClearSel_x                                       0x93CF90
#define CListWnd__ClearAllSel_x                                    0x93CFF0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x93D9F0
#define CListWnd__Compare_x                                        0x93B8B0
#define CListWnd__Draw_x                                           0x9380A0
#define CListWnd__DrawColumnSeparators_x                           0x93A880
#define CListWnd__DrawHeader_x                                     0x93ACF0
#define CListWnd__DrawItem_x                                       0x93B1F0
#define CListWnd__DrawLine_x                                       0x93A9F0
#define CListWnd__DrawSeparator_x                                  0x93A920
#define CListWnd__EnableLine_x                                     0x93A160
#define CListWnd__EnsureVisible_x                                  0x93D920
#define CListWnd__ExtendSel_x                                      0x93CEC0
#define CListWnd__GetColumnTooltip_x                               0x939CA0
#define CListWnd__GetColumnMinWidth_x                              0x939D10
#define CListWnd__GetColumnWidth_x                                 0x939C10
#define CListWnd__GetCurSel_x                                      0x9395A0
#define CListWnd__GetItemAtPoint_x                                 0x93A3D0
#define CListWnd__GetItemAtPoint1_x                                0x93A440
#define CListWnd__GetItemData_x                                    0x939620
#define CListWnd__GetItemHeight_x                                  0x9399E0
#define CListWnd__GetItemIcon_x                                    0x9397B0
#define CListWnd__GetItemRect_x                                    0x93A250
#define CListWnd__GetItemText_x                                    0x939660
#define CListWnd__GetSelList_x                                     0x93D040
#define CListWnd__GetSeparatorRect_x                               0x93A680
#define CListWnd__InsertLine_x                                     0x93CBA0
#define CListWnd__RemoveLine_x                                     0x93CCF0
#define CListWnd__SetColors_x                                      0x93BF50
#define CListWnd__SetColumnJustification_x                         0x93BC80
#define CListWnd__SetColumnLabel_x                                 0x93C550
#define CListWnd__SetColumnWidth_x                                 0x93BBA0
#define CListWnd__SetCurSel_x                                      0x93CE00
#define CListWnd__SetItemColor_x                                   0x93D5E0
#define CListWnd__SetItemData_x                                    0x93D5A0
#define CListWnd__SetItemText_x                                    0x93D1B0
#define CListWnd__ShiftColumnSeparator_x                           0x93BD40
#define CListWnd__Sort_x                                           0x93BA30
#define CListWnd__ToggleSel_x                                      0x93CE30
#define CListWnd__SetColumnsSizable_x                              0x93BDF0
#define CListWnd__SetItemWnd_x                                     0x93D460
#define CListWnd__GetItemWnd_x                                     0x939800
#define CListWnd__SetItemIcon_x                                    0x93D230
#define CListWnd__CalculateCustomWindowPositions_x                 0x93C290
#define CListWnd__SetVScrollPos_x                                  0x93BB80

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7947C0
#define CMapViewWnd__GetWorldCoordinates_x                         0x792ED0
#define CMapViewWnd__HandleLButtonDown_x                           0x78FF10

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7B4A50
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7B5330
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7B5860
#define CMerchantWnd__SelectRecoverySlot_x                         0x7B87E0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7B35C0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7BE3A0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7B4670

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8BBC30
#define CPacketScrambler__hton_x                                   0x8BBC20

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x956D70
#define CSidlManager__FindScreenPieceTemplate_x                    0x957180
#define CSidlManager__FindScreenPieceTemplate1_x                   0x956F70
#define CSidlManager__CreateLabel_x                                0x816B60
#define CSidlManager__CreateXWndFromTemplate_x                     0x95A0E0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x95A2B0
#define CSidlManager__CreateXWnd_x                                 0x816A90
#define CSidlManager__CreateHotButtonWnd_x                         0x817060

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x953850
#define CSidlScreenWnd__CalculateVSBRange_x                        0x953750
#define CSidlScreenWnd__ConvertToRes_x                             0x97C8D0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x9531E0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x952ED0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x952FA0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x953070
#define CSidlScreenWnd__DrawSidlPiece_x                            0x953CF0
#define CSidlScreenWnd__EnableIniStorage_x                         0x9541C0
#define CSidlScreenWnd__GetSidlPiece_x                             0x953EE0
#define CSidlScreenWnd__Init1_x                                    0x952AD0
#define CSidlScreenWnd__LoadIniInfo_x                              0x954210
#define CSidlScreenWnd__LoadIniListWnd_x                           0x954D50
#define CSidlScreenWnd__LoadSidlScreen_x                           0x951EE0
#define CSidlScreenWnd__StoreIniInfo_x                             0x9548D0
#define CSidlScreenWnd__StoreIniVis_x                              0x954C30
#define CSidlScreenWnd__WndNotification_x                          0x953C00
#define CSidlScreenWnd__GetChildItem_x                             0x954140
#define CSidlScreenWnd__HandleLButtonUp_x                          0x943760
#define CSidlScreenWnd__m_layoutCopy_x                             0x1604AE8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x693CC0
#define CSkillMgr__GetSkillCap_x                                   0x693EA0
#define CSkillMgr__GetNameToken_x                                  0x693440
#define CSkillMgr__IsActivatedSkill_x                              0x693580
#define CSkillMgr__IsCombatSkill_x                                 0x6934C0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x963A80
#define CSliderWnd__SetValue_x                                     0x9638F0
#define CSliderWnd__SetNumTicks_x                                  0x963950

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x81CD60

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x96C220
#define CStmlWnd__ParseSTML_x                                      0x96D570
#define CStmlWnd__CalculateHSBRange_x                              0x96D340
#define CStmlWnd__CalculateVSBRange_x                              0x96D2C0
#define CStmlWnd__CanBreakAtCharacter_x                            0x971690
#define CStmlWnd__FastForwardToEndOfTag_x                          0x972320
#define CStmlWnd__ForceParseNow_x                                  0x96C810
#define CStmlWnd__GetNextTagPiece_x                                0x9715F0
#define CStmlWnd__GetSTMLText_x                                    0x509B30
#define CStmlWnd__GetVisibleText_x                                 0x96C830
#define CStmlWnd__InitializeWindowVariables_x                      0x972170
#define CStmlWnd__MakeStmlColorTag_x                               0x96B890
#define CStmlWnd__MakeWndNotificationTag_x                         0x96B900
#define CStmlWnd__SetSTMLText_x                                    0x96A940
#define CStmlWnd__StripFirstSTMLLines_x                            0x973420
#define CStmlWnd__UpdateHistoryString_x                            0x972530

// CTabWnd 
#define CTabWnd__Draw_x                                            0x969A70
#define CTabWnd__DrawCurrentPage_x                                 0x96A1A0
#define CTabWnd__DrawTab_x                                         0x969EC0
#define CTabWnd__GetCurrentPage_x                                  0x969270
#define CTabWnd__GetPageInnerRect_x                                0x9694B0
#define CTabWnd__GetTabInnerRect_x                                 0x9693F0
#define CTabWnd__GetTabRect_x                                      0x9692A0
#define CTabWnd__InsertPage_x                                      0x9696C0
#define CTabWnd__RemovePage_x                                      0x969830
#define CTabWnd__SetPage_x                                         0x969530
#define CTabWnd__SetPageRect_x                                     0x9699B0
#define CTabWnd__UpdatePage_x                                      0x969D80
#define CTabWnd__GetPageFromTabIndex_x                             0x969E00
#define CTabWnd__GetCurrentTabIndex_x                              0x969260

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x779950
#define CPageWnd__SetTabText_x                                     0x968DC0
#define CPageWnd__FlashTab_x                                       0x968E20

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8BF0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x940610
#define CTextureFont__GetTextExtent_x                              0x9407D0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6C70F0
#define CHtmlComponentWnd__ValidateUri_x                           0x7580E0
#define CHtmlWnd__SetClientCallbacks_x                             0x633FC0
#define CHtmlWnd__AddObserver_x                                    0x633FE0
#define CHtmlWnd__RemoveObserver_x                                 0x634040
#define Window__getProgress_x                                      0x870D60
#define Window__getStatus_x                                        0x870D80
#define Window__getURI_x                                           0x870D90

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9796E0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x92D780

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8F90
#define CXStr__CXStr1_x                                            0x8617D0
#define CXStr__CXStr3_x                                            0x90EDF0
#define CXStr__dCXStr_x                                            0x4786D0
#define CXStr__operator_equal_x                                    0x90F020
#define CXStr__operator_equal1_x                                   0x90F060
#define CXStr__operator_plus_equal1_x                              0x90FAF0
#define CXStr__SetString_x                                         0x9119E0
#define CXStr__operator_char_p_x                                   0x90F530
#define CXStr__GetChar_x                                           0x911330
#define CXStr__Delete_x                                            0x910BE0
#define CXStr__GetUnicode_x                                        0x9113A0
#define CXStr__GetLength_x                                         0x4A89A0
#define CXStr__Mid_x                                               0x47D380
#define CXStr__Insert_x                                            0x911400
#define CXStr__FindNext_x                                          0x911050

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x961D10
#define CXWnd__BringToTop_x                                        0x946F40
#define CXWnd__Center_x                                            0x946AC0
#define CXWnd__ClrFocus_x                                          0x9468E0
#define CXWnd__Destroy_x                                           0x946980
#define CXWnd__DoAllDrawing_x                                      0x942EF0
#define CXWnd__DrawChildren_x                                      0x942EC0
#define CXWnd__DrawColoredRect_x                                   0x943350
#define CXWnd__DrawTooltip_x                                       0x941A10
#define CXWnd__DrawTooltipAtPoint_x                                0x941AD0
#define CXWnd__GetBorderFrame_x                                    0x9431B0
#define CXWnd__GetChildWndAt_x                                     0x946FE0
#define CXWnd__GetClientClipRect_x                                 0x9451A0
#define CXWnd__GetScreenClipRect_x                                 0x945270
#define CXWnd__GetScreenRect_x                                     0x945440
#define CXWnd__GetRelativeRect_x                                   0x945510
#define CXWnd__GetTooltipRect_x                                    0x9433A0
#define CXWnd__GetWindowTextA_x                                    0x49C940
#define CXWnd__IsActive_x                                          0x943AD0
#define CXWnd__IsDescendantOf_x                                    0x945E30
#define CXWnd__IsReallyVisible_x                                   0x945E60
#define CXWnd__IsType_x                                            0x947650
#define CXWnd__Move_x                                              0x945ED0
#define CXWnd__Move1_x                                             0x945F90
#define CXWnd__ProcessTransition_x                                 0x946A70
#define CXWnd__Refade_x                                            0x946270
#define CXWnd__Resize_x                                            0x946500
#define CXWnd__Right_x                                             0x946D00
#define CXWnd__SetFocus_x                                          0x9468A0
#define CXWnd__SetFont_x                                           0x946910
#define CXWnd__SetKeyTooltip_x                                     0x947470
#define CXWnd__SetMouseOver_x                                      0x9442F0
#define CXWnd__StartFade_x                                         0x945D20
#define CXWnd__GetChildItem_x                                      0x947150
#define CXWnd__SetParent_x                                         0x945BF0
#define CXWnd__Minimize_x                                          0x946570

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x97D950

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x949EC0
#define CXWndManager__DrawWindows_x                                0x949EE0
#define CXWndManager__GetKeyboardFlags_x                           0x94C6E0
#define CXWndManager__HandleKeyboardMsg_x                          0x94C290
#define CXWndManager__RemoveWnd_x                                  0x94C900
#define CXWndManager__RemovePendingDeletionWnd_x                   0x94CE70

// CDBStr
#define CDBStr__GetString_x                                        0x543C30

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BC950
#define EQ_Character__Cur_HP_x                                     0x4D2A50
#define EQ_Character__Cur_Mana_x                                   0x4DA160
#define EQ_Character__GetCastingTimeModifier_x                     0x4BF990
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B32E0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3430
#define EQ_Character__GetHPRegen_x                                 0x4DFF00
#define EQ_Character__GetEnduranceRegen_x                          0x4E0500
#define EQ_Character__GetManaRegen_x                               0x4E0940
#define EQ_Character__Max_Endurance_x                              0x65A990
#define EQ_Character__Max_HP_x                                     0x4D2880
#define EQ_Character__Max_Mana_x                                   0x65A790
#define EQ_Character__doCombatAbility_x                            0x65CDC0
#define EQ_Character__UseSkill_x                                   0x4E2730
#define EQ_Character__GetConLevel_x                                0x653240
#define EQ_Character__IsExpansionFlag_x                            0x5B67D0
#define EQ_Character__TotalEffect_x                                0x4C5D00
#define EQ_Character__GetPCSpellAffect_x                           0x4C06E0
#define EQ_Character__SpellDuration_x                              0x4C0210
#define EQ_Character__MySpellDuration_x                            0x4B1C10
#define EQ_Character__GetAdjustedSkill_x                           0x4D57D0
#define EQ_Character__GetBaseSkill_x                               0x4D6770
#define EQ_Character__CanUseItem_x                                 0x4DA470

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8DB030

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x670D30

//PcClient
#define PcClient__vftable_x                                        0xB16DDC
#define PcClient__PcClient_x                                       0x6509B0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA520
#define CCharacterListWnd__EnterWorld_x                            0x4B9F00
#define CCharacterListWnd__Quit_x                                  0x4B9C50
#define CCharacterListWnd__UpdateList_x                            0x4BA0F0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x635190
#define EQ_Item__CreateItemTagString_x                             0x8B5260
#define EQ_Item__IsStackable_x                                     0x8B9EA0
#define EQ_Item__GetImageNum_x                                     0x8B6DE0
#define EQ_Item__CreateItemClient_x                                0x6343C0
#define EQ_Item__GetItemValue_x                                    0x8B80F0
#define EQ_Item__ValueSellMerchant_x                               0x8BB810
#define EQ_Item__IsKeyRingItem_x                                   0x8B97C0
#define EQ_Item__CanGoInBag_x                                      0x6352B0
#define EQ_Item__IsEmpty_x                                         0x8B9320
#define EQ_Item__GetMaxItemCount_x                                 0x8B8500
#define EQ_Item__GetHeldItem_x                                     0x8B6CB0
#define EQ_Item__GetAugmentFitBySlot_x                             0x8B4BB0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x562810
#define EQ_LoadingS__Array_x                                       0xC3BC60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65B2D0
#define EQ_PC__GetAlternateAbilityId_x                             0x8C4CA0
#define EQ_PC__GetCombatAbility_x                                  0x8C5310
#define EQ_PC__GetCombatAbilityTimer_x                             0x8C5380
#define EQ_PC__GetItemRecastTimer_x                                0x65D340
#define EQ_PC__HasLoreItem_x                                       0x653A00
#define EQ_PC__AlertInventoryChanged_x                             0x652B80
#define EQ_PC__GetPcZoneClient_x                                   0x67F820
#define EQ_PC__RemoveMyAffect_x                                    0x660570
#define EQ_PC__GetKeyRingItems_x                                   0x8C5C10
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8C59A0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8C5F10

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5BCCA0
#define EQItemList__add_object_x                                   0x5EA8A0
#define EQItemList__add_item_x                                     0x5BD200
#define EQItemList__delete_item_x                                  0x5BD250
#define EQItemList__FreeItemList_x                                 0x5BD150

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x5407B0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x6725B0
#define EQPlayer__dEQPlayer_x                                      0x665A70
#define EQPlayer__DoAttack_x                                       0x67A4D0
#define EQPlayer__EQPlayer_x                                       0x666130
#define EQPlayer__SetNameSpriteState_x                             0x66A3B0
#define EQPlayer__SetNameSpriteTint_x                              0x66B290
#define PlayerBase__HasProperty_j_x                                0x9AC540
#define EQPlayer__IsTargetable_x                                   0x9AC9E0
#define EQPlayer__CanSee_x                                         0x9AC840
#define EQPlayer__CanSee1_x                                        0x9AC910
#define PlayerBase__GetVisibilityLineSegment_x                     0x9AC600

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x67D2B0
#define PlayerZoneClient__GetLevel_x                               0x67F860
#define PlayerZoneClient__IsValidTeleport_x                        0x5EBA10
#define PlayerZoneClient__LegalPlayerRace_x                        0x55B550

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x6753F0
#define EQPlayerManager__GetSpawnByName_x                          0x6754A0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x675530

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x638880
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x638900
#define KeypressHandler__AttachKeyToEqCommand_x                    0x638940
#define KeypressHandler__ClearCommandStateArray_x                  0x639D50
#define KeypressHandler__HandleKeyDown_x                           0x639D70
#define KeypressHandler__HandleKeyUp_x                             0x639E10
#define KeypressHandler__SaveKeymapping_x                          0x63A260

// MapViewMap 
#define MapViewMap__Clear_x                                        0x790630
#define MapViewMap__SaveEx_x                                       0x7939F0
#define MapViewMap__SetZoom_x                                      0x7980B0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8D8FB0

// StringTable 
#define StringTable__getString_x                                   0x8D3EB0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x6601E0
#define PcZoneClient__RemovePetEffect_x                            0x660810
#define PcZoneClient__HasAlternateAbility_x                        0x65A5C0
#define PcZoneClient__GetCurrentMod_x                              0x4E57F0
#define PcZoneClient__GetModCap_x                                  0x4E56F0
#define PcZoneClient__CanEquipItem_x                               0x65AC70
#define PcZoneClient__GetItemByID_x                                0x65D7B0
#define PcZoneClient__GetItemByItemClass_x                         0x65D900
#define PcZoneClient__RemoveBuffEffect_x                           0x660830
#define PcZoneClient__BandolierSwap_x                              0x65B890
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x65D2E0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F04C0

//IconCache
#define IconCache__GetIcon_x                                       0x731C50

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x729770
#define CContainerMgr__CloseContainer_x                            0x729A40
#define CContainerMgr__OpenExperimentContainer_x                   0x72A4C0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7E8D00

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x62D360

//CLootWnd
#define CLootWnd__LootAll_x                                        0x786AA0
#define CLootWnd__RequestLootSlot_x                                0x785CD0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x5894C0
#define EQ_Spell__SpellAffects_x                                   0x589930
#define EQ_Spell__SpellAffectBase_x                                0x5896F0
#define EQ_Spell__IsStackable_x                                    0x4CA4A0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CA2F0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B77B0
#define EQ_Spell__IsSPAStacking_x                                  0x58A780
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x589C90
#define EQ_Spell__IsNoRemove_x                                     0x4CA480
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58A790
#define __IsResEffectSpell_x                                       0x4C9760

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4ACE30

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8E3610

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x830100
#define CTargetWnd__WndNotification_x                              0x82F940
#define CTargetWnd__RefreshTargetBuffs_x                           0x82FC10
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x82EAB0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x834740
#define CTaskWnd__ConfirmAbandonTask_x                             0x837380

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x53E1C0
#define CTaskManager__HandleMessage_x                              0x53C650
#define CTaskManager__GetTaskStatus_x                              0x53E270
#define CTaskManager__GetElementDescription_x                      0x53E2F0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5846C0
#define EqSoundManager__PlayScriptMp3_x                            0x584980
#define EqSoundManager__SoundAssistPlay_x                          0x697C90
#define EqSoundManager__WaveInstancePlay_x                         0x697200

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52F770

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x9682D0
#define CTextureAnimation__Draw_x                                  0x9684D0

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x9643E0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56A3C0
#define CAltAbilityData__GetMercMaxRank_x                          0x56A350
#define CAltAbilityData__GetMaxRank_x                              0x55F730

//CTargetRing
#define CTargetRing__Cast_x                                        0x62B480

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA2D0
#define CharacterBase__CreateItemGlobalIndex_x                     0x5168B0
#define CharacterBase__CreateItemIndex_x                           0x633570
#define CharacterBase__GetItemPossession_x                         0x502580
#define CharacterBase__GetItemByGlobalIndex_x                      0x8EBCB0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8EBD10
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x710820
#define CCastSpellWnd__IsBardSongPlaying_x                         0x711050
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x711100

//messages
#define msg_spell_worn_off_x                                       0x5AE7F0
#define msg_new_text_x                                             0x5A31F0
#define __msgTokenTextParam_x                                      0x5B0A90
#define msgTokenText_x                                             0x5B0CE0

//SpellManager
#define SpellManager__vftable_x                                    0xAFF178
#define SpellManager__SpellManager_x                               0x69AFB0
#define Spellmanager__LoadTextSpells_x                             0x69B8A0
#define SpellManager__GetSpellByGroupAndRank_x                     0x69B180

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9B04E0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x516F00
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B4C20
#define ItemGlobalIndex__IsEquippedLocation_x                      0x64C170
#define ItemGlobalIndex__IsValidIndex_x                            0x516F60

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8E3FB0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8E4230

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x77F2A0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x72DE60
#define CCursorAttachment__AttachToCursor1_x                       0x72DEA0
#define CCursorAttachment__Deactivate_x                            0x72EE80

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x95B110
#define CSidlManagerBase__CreatePageWnd_x                          0x95A900
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x956B90
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x956B20

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x977EC0
#define CEQSuiteTextureLoader__GetTexture_x                        0x977B80

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x513E80
#define CFindItemWnd__WndNotification_x                            0x514960
#define CFindItemWnd__Update_x                                     0x5154D0
#define CFindItemWnd__PickupSelectedItem_x                         0x5136C0

//IString
#define IString__Append_x                                          0x503E20

//Camera
#define CDisplay__cameraType_x                                     0xE15328
#define EverQuest__Cameras_x                                       0xED05C4

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51C690
#define LootFiltersManager__GetItemFilterData_x                    0x51BFA0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51BFD0
#define LootFiltersManager__SetItemLootFilter_x                    0x51C1F0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7D6AB0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9B6070
#define CResolutionHandler__GetWindowedStyle_x                     0x692780

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x7263B0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8F9490
#define CDistillerInfo__Instance_x                                 0x8F9430

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x7454C0
#define CGroupWnd__UpdateDisplay_x                                 0x744820

//ItemBase
#define ItemBase__IsLore_x                                         0x8B9870
#define ItemBase__IsLoreEquipped_x                                 0x8B98E0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EA800
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EA940
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EA9A0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x687F30
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x68B8A0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50A1C0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F6650
#define FactionManagerClient__HandleFactionMessage_x               0x4F6CC0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F72C0
#define FactionManagerClient__GetMaxFaction_x                      0x4F72DF
#define FactionManagerClient__GetMinFaction_x                      0x4F7290

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x502550

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x93F660

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BC50

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x502830

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x569870

//CTargetManager
#define CTargetManager__Get_x                                      0x69E800

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x687F30

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A89B0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5BD0F0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF6DC58

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6DA140
#define CAAWnd__UpdateSelected_x                                   0x6D69B0
#define CAAWnd__Update_x                                           0x6D9460

//CXRect
#define CXRect__operator_and_x                                     0x73C620

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
