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
#define __ExpectedVersionDate                                     "Apr 10 2019"
#define __ExpectedVersionTime                                     "12:18:33"
#define __ActualVersionDate_x                                      0xAD64DC
#define __ActualVersionTime_x                                      0xAD64D0

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x61B680
#define __MemChecker1_x                                            0x8F0BC0
#define __MemChecker2_x                                            0x6AA980
#define __MemChecker3_x                                            0x6AA8D0
#define __MemChecker4_x                                            0x847F60
#define __EncryptPad0_x                                            0xC0B9A8
#define __EncryptPad1_x                                            0xC69928
#define __EncryptPad2_x                                            0xC1C220
#define __EncryptPad3_x                                            0xC1BE20
#define __EncryptPad4_x                                            0xC5A198
#define __EncryptPad5_x                                            0xF34388
#define __AC1_x                                                    0x804816
#define __AC2_x                                                    0x5D53AF
#define __AC3_x                                                    0x5DCABF
#define __AC4_x                                                    0x5E0940
#define __AC5_x                                                    0x5E6BB0
#define __AC6_x                                                    0x5EB246
#define __AC7_x                                                    0x5D4E20
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1F1BDC

// Direct Input
#define DI8__Main_x                                                0xF343A8
#define DI8__Keyboard_x                                            0xF343AC
#define DI8__Mouse_x                                               0xF33968
#define DI8__Mouse_Copy_x                                          0xE8F044
#define DI8__Mouse_Check_x                                         0xF346DC
#define __AutoSkillArray_x                                         0xE8FF5C
#define __Attack_x                                                 0xF2DD73
#define __Autofire_x                                               0xF2DD74
#define __BindList_x                                               0xBFA3E8
#define g_eqCommandStates_x                                        0xBFB160
#define __Clicks_x                                                 0xE8F0FC
#define __CommandList_x                                            0xBFBD20
#define __CurrentMapLabel_x                                        0x104EE1C
#define __CurrentSocial_x                                          0xBE4730
#define __DoAbilityList_x                                          0xEC5894
#define __do_loot_x                                                0x5A1E20
#define __DrawHandler_x                                            0x16CB7F0
#define __GroupCount_x                                             0xE7F2FA
#define __Guilds_x                                                 0xE85850
#define __gWorld_x                                                 0xE81704
#define __HWnd_x                                                   0xF3396C
#define __heqmain_x                                                0x103E9C0
#define __InChatMode_x                                             0xE8F02C
#define __LastTell_x                                               0xE90F90
#define __LMouseHeldTime_x                                         0xE8F168
#define __Mouse_x                                                  0xF34394
#define __MouseLook_x                                              0xE8F0C2
#define __MouseEventTime_x                                         0xF2E854
#define __gpbCommandEvent_x                                        0xE81614
#define __NetStatusToggle_x                                        0xE8F0C5
#define __PCNames_x                                                0xE90540
#define __RangeAttackReady_x                                       0xE90240
#define __RMouseHeldTime_x                                         0xE8F164
#define __RunWalkState_x                                           0xE8F030
#define __ScreenMode_x                                             0xDCD240
#define __ScreenX_x                                                0xE8EFE4
#define __ScreenY_x                                                0xE8EFE0
#define __ScreenXMax_x                                             0xE8EFE8
#define __ScreenYMax_x                                             0xE8EFEC
#define __ServerHost_x                                             0xE81863
#define __ServerName_x                                             0xEC5854
#define __ShiftKeyDown_x                                           0xE8F6BC
#define __ShowNames_x                                              0xE903FC
#define __Socials_x                                                0xEC5954
#define __SubscriptionType_x                                       0x10909B8
#define __TargetAggroHolder_x                                      0x10517D8
#define __ZoneType_x                                               0xE8F4C0
#define __GroupAggro_x                                             0x1051818
#define __LoginName_x                                              0xF3402C
#define __Inviter_x                                                0xF2DCF0
#define __AttackOnAssist_x                                         0xE903B8
#define __UseTellWindows_x                                         0xE906DC
#define __gfMaxZoomCameraDistance_x                                0xACB970
#define __gfMaxCameraDistance_x                                    0xAF8E30
#define __pulAutoRun_x                                             0xE8F0E0
#define __pulForward_x                                             0xE90714
#define __pulBackward_x                                            0xE90718
#define __pulTurnRight_x                                           0xE9071C
#define __pulTurnLeft_x                                            0xE90720
#define __pulStrafeLeft_x                                          0xE90724
#define __pulStrafeRight_x                                         0xE90728

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE81BE8
#define instEQZoneInfo_x                                           0xE8F2B8
#define pinstActiveBanker_x                                        0xE816BC
#define pinstActiveCorpse_x                                        0xE816B4
#define pinstActiveGMaster_x                                       0xE816B8
#define pinstActiveMerchant_x                                      0xE816B0
#define pinstAltAdvManager_x                                       0xDCDEB8
#define pinstBandageTarget_x                                       0xE816CC
#define pinstCamActor_x                                            0xDCD230
#define pinstCDBStr_x                                              0xDCCBE4
#define pinstCDisplay_x                                            0xE81714
#define pinstCEverQuest_x                                          0x103E9CC
#define pinstEverQuestInfo_x                                       0xE8EFD8
#define pinstCharData_x                                            0xE7F2D8
#define pinstCharSpawn_x                                           0xE81708
#define pinstControlledMissile_x                                   0xE81B9C
#define pinstControlledPlayer_x                                    0xE81708
#define pinstCResolutionHandler_x                                  0x16CBA20
#define pinstCSidlManager_x                                        0x16CA9BC
#define pinstCXWndManager_x                                        0x16CA9B0
#define instDynamicZone_x                                          0xE85728
#define pinstDZMember_x                                            0xE85838
#define pinstDZTimerInfo_x                                         0xE8583C
#define pinstEqLogin_x                                             0xF33978
#define instEQMisc_x                                               0xDCCB28
#define pinstEQSoundManager_x                                      0xDCEDE0
#define pinstEQSpellStrings_x                                      0xC8E338
#define instExpeditionLeader_x                                     0xE85772
#define instExpeditionName_x                                       0xE857B2
#define pinstGroup_x                                               0xE7F2F6
#define pinstImeManager_x                                          0x16CA9B4
#define pinstLocalPlayer_x                                         0xE8162C
#define pinstMercenaryData_x                                       0xF30344
#define pinstMercenaryStats_x                                      0x1051924
#define pinstModelPlayer_x                                         0xE816C4
#define pinstPCData_x                                              0xE7F2D8
#define pinstSkillMgr_x                                            0xF324B8
#define pinstSpawnManager_x                                        0xF30F60
#define pinstSpellManager_x                                        0xF326D8
#define pinstSpellSets_x                                           0xF2699C
#define pinstStringTable_x                                         0xE814F4
#define pinstSwitchManager_x                                       0xE7F188
#define pinstTarget_x                                              0xE81700
#define pinstTargetObject_x                                        0xE81710
#define pinstTargetSwitch_x                                        0xE7F2DC
#define pinstTaskMember_x                                          0xDCC9BC
#define pinstTrackTarget_x                                         0xE8170C
#define pinstTradeTarget_x                                         0xE816C0
#define instTributeActive_x                                        0xDCCB49
#define pinstViewActor_x                                           0xDCD22C
#define pinstWorldData_x                                           0xE8161C
#define pinstZoneAddr_x                                            0xE8F558
#define pinstPlayerPath_x                                          0xF30FF8
#define pinstTargetIndicator_x                                     0xF32940
#define EQObject_Top_x                                             0xE81628
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDCD2F8
#define pinstCAchievementsWnd_x                                    0xDCD2E8
#define pinstCActionsWnd_x                                         0xDCCCBC
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDCD16C
#define pinstCAdvancedLootWnd_x                                    0xDCCCB4
#define pinstCAdventureLeaderboardWnd_x                            0x10485F0
#define pinstCAdventureRequestWnd_x                                0x10486A0
#define pinstCAdventureStatsWnd_x                                  0x1048750
#define pinstCAggroMeterWnd_x                                      0xDCD1C8
#define pinstCAlarmWnd_x                                           0xDCD228
#define pinstCAlertHistoryWnd_x                                    0xDCD294
#define pinstCAlertStackWnd_x                                      0xDCD1E0
#define pinstCAlertWnd_x                                           0xDCD1F0
#define pinstCAltStorageWnd_x                                      0x1048AB0
#define pinstCAudioTriggersWindow_x                                0xC80668
#define pinstCAuraWnd_x                                            0xDCD1C0
#define pinstCAvaZoneWnd_x                                         0xDCD298
#define pinstCBandolierWnd_x                                       0xDCD1F4
#define pinstCBankWnd_x                                            0xDCD284
#define pinstCBarterMerchantWnd_x                                  0x1049CF0
#define pinstCBarterSearchWnd_x                                    0x1049DA0
#define pinstCBarterWnd_x                                          0x1049E50
#define pinstCBazaarConfirmationWnd_x                              0xDCD1DC
#define pinstCBazaarSearchWnd_x                                    0xDCCCEC
#define pinstCBazaarWnd_x                                          0xDCD208
#define pinstCBlockedBuffWnd_x                                     0xDCD26C
#define pinstCBlockedPetBuffWnd_x                                  0xDCD29C
#define pinstCBodyTintWnd_x                                        0xDCD1B0
#define pinstCBookWnd_x                                            0xDCD210
#define pinstCBreathWnd_x                                          0xDCD304
#define pinstCBuffWindowNORMAL_x                                   0xDCD238
#define pinstCBuffWindowSHORT_x                                    0xDCD244
#define pinstCBugReportWnd_x                                       0xDCD2FC
#define pinstCButtonWnd_x                                          0x16CAC20
#define pinstCCastingWnd_x                                         0xDCD2EC
#define pinstCCastSpellWnd_x                                       0xDCCD5C
//#define pinstCCharacterCreationWnd_x                               0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDCD30C
#define pinstCChatWindowManager_x                                  0x104A910
#define pinstCClaimWnd_x                                           0x104AA68
#define pinstCColorPickerWnd_x                                     0xDCCC9C
#define pinstCCombatAbilityWnd_x                                   0xDCD1CC
#define pinstCCombatSkillsSelectWnd_x                              0xDCCCC0
#define pinstCCompassWnd_x                                         0xDCD19C
#define pinstCConfirmationDialog_x                                 0x104F968
#define pinstCContainerMgr_x                                       0xDCD2F4
#define pinstCContextMenuManager_x                                 0x16CA970
#define pinstCCursorAttachment_x                                   0xDCD2DC
#define pinstCDynamicZoneWnd_x                                     0x104B030
#define pinstCEditLabelWnd_x                                       0xDCD21C
#define pinstCEQMainWnd_x                                          0x104B278
#define pinstCEventCalendarWnd_x                                   0xDCCC8C
#define pinstCExtendedTargetWnd_x                                  0xDCD1B8
#define pinstCFacePick_x                                           0xDCCC94
#define pinstCFactionWnd_x                                         0xDCD2E4
#define pinstCFellowshipWnd_x                                      0x104B478
#define pinstCFileSelectionWnd_x                                   0xDCCCAC
#define pinstCFindItemWnd_x                                        0xDCD220
#define pinstCFindLocationWnd_x                                    0x104B5D0
#define pinstCFriendsWnd_x                                         0xDCCCD0
#define pinstCGemsGameWnd_x                                        0xDCD200
#define pinstCGiveWnd_x                                            0xDCD224
#define pinstCGroupSearchFiltersWnd_x                              0xDCD1D8
#define pinstCGroupSearchWnd_x                                     0x104B9C8
#define pinstCGroupWnd_x                                           0x104BA78
#define pinstCGuildBankWnd_x                                       0xE9039C
#define pinstCGuildCreationWnd_x                                   0x104BBD8
#define pinstCGuildMgmtWnd_x                                       0x104BC88
#define pinstCharacterCreation_x                                   0xDCD1D0
#define pinstCHelpWnd_x                                            0xDCD178
#define pinstCHeritageSelectionWnd_x                               0xDCCCA8
#define pinstCHotButtonWnd_x                                       0x104DDE0
#define pinstCHotButtonWnd1_x                                      0x104DDE0
#define pinstCHotButtonWnd2_x                                      0x104DDE4
#define pinstCHotButtonWnd3_x                                      0x104DDE8
#define pinstCHotButtonWnd4_x                                      0x104DDEC
#define pinstCIconSelectionWnd_x                                   0xDCD2B0
#define pinstCInspectWnd_x                                         0xDCD2BC
#define pinstCInventoryWnd_x                                       0xDCD1F8
#define pinstCInvSlotMgr_x                                         0xDCD28C
#define pinstCItemDisplayManager_x                                 0x104E370
#define pinstCItemExpTransferWnd_x                                 0x104E4A4
#define pinstCItemOverflowWnd_x                                    0xDCCD54
#define pinstCJournalCatWnd_x                                      0xDCCCCC
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDCCC90
#define pinstCKeyRingWnd_x                                         0xDCD25C
#define pinstCLargeDialogWnd_x                                     0x10505E8
#define pinstCLayoutCopyWnd_x                                      0x104E7F0
#define pinstCLFGuildWnd_x                                         0x104E8A0
#define pinstCLoadskinWnd_x                                        0xDCD20C
#define pinstCLootFiltersCopyWnd_x                                 0xC9C930
#define pinstCLootFiltersWnd_x                                     0xDCD214
#define pinstCLootSettingsWnd_x                                    0xDCD254
#define pinstCLootWnd_x                                            0xDCCC80
#define pinstCMailAddressBookWnd_x                                 0xDCD2A4
#define pinstCMailCompositionWnd_x                                 0xDCD274
#define pinstCMailIgnoreListWnd_x                                  0xDCD2AC
#define pinstCMailWnd_x                                            0xDCD258
#define pinstCManageLootWnd_x                                      0xDCE368
#define pinstCMapToolbarWnd_x                                      0xDCD1FC
#define pinstCMapViewWnd_x                                         0xDCD1EC
#define pinstCMarketplaceWnd_x                                     0xDCCC98
#define pinstCMerchantWnd_x                                        0xDCCCC4
#define pinstCMIZoneSelectWnd_x                                    0x104F0D8
#define pinstCMusicPlayerWnd_x                                     0xDCD264
#define pinstCNameChangeMercWnd_x                                  0xDCD1A4
#define pinstCNameChangePetWnd_x                                   0xDCD188
#define pinstCNameChangeWnd_x                                      0xDCD514
#define pinstCNoteWnd_x                                            0xDCD168
#define pinstCObjectPreviewWnd_x                                   0xDCCCB8
#define pinstCOptionsWnd_x                                         0xDCD204
#define pinstCPetInfoWnd_x                                         0xDCD278
#define pinstCPetitionQWnd_x                                       0xDCCCD8
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDCD1AC
#define pinstCPlayerWnd_x                                          0xDCD218
#define pinstCPopupWndManager_x                                    0x104F968
#define pinstCProgressionSelectionWnd_x                            0x104FA18
#define pinstCPurchaseGroupWnd_x                                   0xDCCD58
#define pinstCPurchaseWnd_x                                        0xDCCCC8
#define pinstCPvPLeaderboardWnd_x                                  0x104FAC8
#define pinstCPvPStatsWnd_x                                        0x104FB78
#define pinstCQuantityWnd_x                                        0xDCD2B4
#define pinstCRaceChangeWnd_x                                      0xDCCCA4
#define pinstCRaidOptionsWnd_x                                     0xDCD1E8
#define pinstCRaidWnd_x                                            0xDCD2C0
#define pinstCRealEstateItemsWnd_x                                 0xDCD300
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDCCC88
#define pinstCRealEstateManageWnd_x                                0xDCD260
#define pinstCRealEstateNeighborhoodWnd_x                          0xDCD27C
#define pinstCRealEstatePlotSearchWnd_x                            0xDCD2A0
#define pinstCRealEstatePurchaseWnd_x                              0xDCD2D4
#define pinstCRespawnWnd_x                                         0xDCD1D4
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDCD1BC
#define pinstCSendMoneyWnd_x                                       0xDCD250
#define pinstCServerListWnd_x                                      0xDCD290
#define pinstCSkillsSelectWnd_x                                    0xDCCCA0
#define pinstCSkillsWnd_x                                          0xDCCC84
#define pinstCSocialEditWnd_x                                      0xDCD2E0
#define pinstCSocialWnd_x                                          0xDCD1C4
#define pinstCSpellBookWnd_x                                       0xDCD1B4
#define pinstCStoryWnd_x                                           0xDCD170
#define pinstCTargetOfTargetWnd_x                                  0x10519A8
#define pinstCTargetWnd_x                                          0xDCD270
#define pinstCTaskOverlayWnd_x                                     0xDCD2A8
#define pinstCTaskSelectWnd_x                                      0x1051B00
#define pinstCTaskManager_x                                        0xC9D280
#define pinstCTaskTemplateSelectWnd_x                              0x1051BB0
#define pinstCTaskWnd_x                                            0x1051C60
#define pinstCTextEntryWnd_x                                       0xDCD1A0
#define pinstCTimeLeftWnd_x                                        0xDCCCB0
#define pinstCTipWndCONTEXT_x                                      0x1051E64
#define pinstCTipWndOFDAY_x                                        0x1051E60
#define pinstCTitleWnd_x                                           0x1051F10
#define pinstCTrackingWnd_x                                        0xDCD288
#define pinstCTradeskillWnd_x                                      0x1052078
#define pinstCTradeWnd_x                                           0xDCD1A8
#define pinstCTrainWnd_x                                           0xDCD2B8
#define pinstCTributeBenefitWnd_x                                  0x1052278
#define pinstCTributeMasterWnd_x                                   0x1052328
#define pinstCTributeTrophyWnd_x                                   0x10523D8
#define pinstCVideoModesWnd_x                                      0xDCD2C4
#define pinstCVoiceMacroWnd_x                                      0xF330A8
#define pinstCVoteResultsWnd_x                                     0xDCD164
#define pinstCVoteWnd_x                                            0xDCCCD4
#define pinstCWebManager_x                                         0xF33724
#define pinstCZoneGuideWnd_x                                       0xDCD268
#define pinstCZonePathWnd_x                                        0xDCD280

#define pinstEQSuiteTextureLoader_x                                0xC6B410
#define pinstItemIconCache_x                                       0x104B230
#define pinstLootFiltersManager_x                                  0xC9C9E0
#define pinstRewardSelectionWnd_x                                  0x10502C0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC1BE10
#define __CastRay_x                                                0x59D280
#define __CastRay2_x                                               0x59D2D0
#define __ConvertItemTags_x                                        0x5B8A00
#define __CrashHandler_x                                           0x8518A0
#define __EQGetTime_x                                              0x8F06A0
#define __ExecuteCmd_x                                             0x595BC0
#define __FixHeading_x                                             0x9804D0
#define __GameLoop_x                                               0x6A9E40
#define __get_bearing_x                                            0x59CDD0
#define __get_melee_range_x                                        0x59D4C0
#define __GetAnimationCache_x                                      0x70ED50
#define __GetGaugeValueFromEQ_x                                    0x803020
#define __GetLabelFromEQ_x                                         0x8047A0
#define __GetXTargetType_x                                         0x981FA0
#define __HandleMouseWheel_x                                       0x6AAA30
#define __HeadingDiff_x                                            0x980540
#define __HelpPath_x                                               0xF2E444
#define __LoadFrontEnd_x                                           0x6A6930
#define __NewUIINI_x                                               0x802CF0
#define __pCrashHandler_x                                          0x106F7E0
#define __ProcessGameEvents_x                                      0x5FC900
#define __ProcessMouseEvent_x                                      0x5FC0C0
#define __SaveColors_x                                             0x545840
#define __STMLToText_x                                             0x923DE0
#define __ToggleKeyRingItem_x                                      0x508870
#define CrashDetected_x                                            0x6A8390
#define DrawNetStatus_x                                            0x628C60
#define Expansion_HoT_x                                            0xE903A4
#define Teleport_Table_Size_x                                      0xE8171C
#define Teleport_Table_x                                           0xE7F4E8
#define Util__FastTime_x                                           0x8F0260
#define wwsCrashReportCheckForUploader_x                           0x852300
#define wwsCrashReportPlatformLaunchUploader_x                     0x8549E0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48B820
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4946B0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x494470

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x54D330
#define AltAdvManager__IsAbilityReady_x                            0x54C280
#define AltAdvManager__GetAAById_x                                 0x54C480
#define AltAdvManager__CanTrainAbility_x                           0x54C4F0
#define AltAdvManager__CanSeeAbility_x                             0x54C850

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C75A0
#define CharacterZoneClient__HasSkill_x                            0x4D2470
#define CharacterZoneClient__MakeMeVisible_x                       0x4D3B90
#define CharacterZoneClient__IsStackBlocked_x                      0x4BBA00
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B8150
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D6510
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D65F0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D66D0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C04F0
#define CharacterZoneClient__BardCastBard_x                        0x4C3160
#define CharacterZoneClient__GetMaxEffects_x                       0x4B8220
#define CharacterZoneClient__GetEffect_x                           0x4B8090
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C14F0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C15C0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C1610
#define CharacterZoneClient__CalcAffectChange_x                    0x4C1760
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C1930
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4AFF20
#define CharacterZoneClient__FindItemByGuid_x                      0x4D4B00
#define CharacterZoneClient__FindItemByRecord_x                    0x4D4570

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D0700
#define CBankWnd__WndNotification_x                                0x6D04E0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6DDE50

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x60B560
#define CButtonWnd__CButtonWnd_x                                   0x9201F0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6FDE40
#define CChatManager__InitContextMenu_x                            0x6F71C0
#define CChatManager__FreeChatWindow_x                             0x6FCA00
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E5C80
#define CChatManager__SetLockedActiveChatWindow_x                  0x6FDAC0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x934930
#define CContextMenu__dCContextMenu_x                              0x934B60
#define CContextMenu__AddMenuItem_x                                0x934B70
#define CContextMenu__RemoveMenuItem_x                             0x934E80
#define CContextMenu__RemoveAllMenuItems_x                         0x934EA0
#define CContextMenu__CheckMenuItem_x                              0x934F20
#define CContextMenu__SetMenuItem_x                                0x934DA0
#define CContextMenu__AddSeparator_x                               0x934D00

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x9354C0
#define CContextMenuManager__RemoveMenu_x                          0x935530
#define CContextMenuManager__PopupMenu_x                           0x9355F0
#define CContextMenuManager__Flush_x                               0x935460
#define CContextMenuManager__GetMenu_x                             0x496940
#define CContextMenuManager__CreateDefaultMenu_x                   0x709540

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D1020
#define CChatService__GetFriendName_x                              0x8D1030

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6FE720
#define CChatWindow__Clear_x                                       0x6FF9D0
#define CChatWindow__WndNotification_x                             0x700160

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x931DC0
#define CComboWnd__Draw_x                                          0x9312B0
#define CComboWnd__GetCurChoice_x                                  0x931C00
#define CComboWnd__GetListRect_x                                   0x931760
#define CComboWnd__GetTextRect_x                                   0x931E30
#define CComboWnd__InsertChoice_x                                  0x9318F0
#define CComboWnd__SetColors_x                                     0x9318C0
#define CComboWnd__SetChoice_x                                     0x931BD0
#define CComboWnd__GetItemCount_x                                  0x931C10
#define CComboWnd__GetCurChoiceText_x                              0x931C50

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x706F30
#define CContainerWnd__vftable_x                                   0xADF748
#define CContainerWnd__SetContainer_x                              0x7084A0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x545600
#define CDisplay__GetClickedActor_x                                0x5385A0
#define CDisplay__GetUserDefinedColor_x                            0x530C80
#define CDisplay__GetWorldFilePath_x                               0x539FF0
#define CDisplay__is3dON_x                                         0x535270
#define CDisplay__ReloadUI_x                                       0x53F710
#define CDisplay__WriteTextHD2_x                                   0x535050
#define CDisplay__TrueDistance_x                                   0x53BC50
#define CDisplay__SetViewActor_x                                   0x537EF0
#define CDisplay__GetFloorHeight_x                                 0x535330
#define CDisplay__SetRenderWindow_x                                0x533C60
#define CDisplay__ToggleScreenshotMode_x                           0x5379C0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x954230

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x937EA0
#define CEditWnd__GetCharIndexPt_x                                 0x938D90
#define CEditWnd__GetDisplayString_x                               0x938C30
#define CEditWnd__GetHorzOffset_x                                  0x9374E0
#define CEditWnd__GetLineForPrintableChar_x                        0x939F60
#define CEditWnd__GetSelStartPt_x                                  0x939040
#define CEditWnd__GetSTMLSafeText_x                                0x938A50
#define CEditWnd__PointFromPrintableChar_x                         0x939BA0
#define CEditWnd__SelectableCharFromPoint_x                        0x939D10
#define CEditWnd__SetEditable_x                                    0x939100

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5EA770
#define CEverQuest__ClickedPlayer_x                                0x5DC8A0
#define CEverQuest__CreateTargetIndicator_x                        0x5F9BB0
#define CEverQuest__DeleteTargetIndicator_x                        0x5F9C40
#define CEverQuest__DoTellWindow_x                                 0x4E5E00
#define CEverQuest__OutputTextToLog_x                              0x4E6030
#define CEverQuest__DropHeldItemOnGround_x                         0x5D18E0
#define CEverQuest__dsp_chat_x                                     0x4E63C0
#define CEverQuest__trimName_x                                     0x5F5E90
#define CEverQuest__Emote_x                                        0x5EAF80
#define CEverQuest__EnterZone_x                                    0x5E4F60
#define CEverQuest__GetBodyTypeDesc_x                              0x5EF730
#define CEverQuest__GetClassDesc_x                                 0x5EFD70
#define CEverQuest__GetClassThreeLetterCode_x                      0x5F0370
#define CEverQuest__GetDeityDesc_x                                 0x5F8500
#define CEverQuest__GetLangDesc_x                                  0x5F0530
#define CEverQuest__GetRaceDesc_x                                  0x5EFD50
#define CEverQuest__InterpretCmd_x                                 0x5F8AD0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5D5AD0
#define CEverQuest__LMouseUp_x                                     0x5D3E50
#define CEverQuest__RightClickedOnPlayer_x                         0x5D63B0
#define CEverQuest__RMouseUp_x                                     0x5D4DE0
#define CEverQuest__SetGameState_x                                 0x5D1670
#define CEverQuest__UPCNotificationFlush_x                         0x5F5D90
#define CEverQuest__IssuePetCommand_x                              0x5F1930
#define CEverQuest__ReportSuccessfulHit_x                          0x5EC380

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x718EE0
#define CGaugeWnd__CalcLinesFillRect_x                             0x718F40
#define CGaugeWnd__Draw_x                                          0x7185D0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ACCA0
#define CGuild__GetGuildName_x                                     0x4ABD80
#define CGuild__GetGuildIndex_x                                    0x4AC110

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x7342F0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x60B920

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x7411B0
#define CInvSlotMgr__MoveItem_x                                    0x73FED0
#define CInvSlotMgr__SelectSlot_x                                  0x741280

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x73E780
#define CInvSlot__SliderComplete_x                                 0x73C4F0
#define CInvSlot__GetItemBase_x                                    0x73BE70
#define CInvSlot__UpdateItem_x                                     0x73BFE0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x742CC0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x741E70
#define CInvSlotWnd__HandleLButtonUp_x                             0x742840

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7FF270
#define CItemDisplayWnd__UpdateStrings_x                           0x751160
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x74AED0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x74B400
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x751760
#define CItemDisplayWnd__AboutToShow_x                             0x750DC0
#define CItemDisplayWnd__WndNotification_x                         0x752C60
#define CItemDisplayWnd__RequestConvertItem_x                      0x7527E0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x74FE30
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x750BE0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x836CA0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x756D10

// CLabel 
#define CLabel__Draw_x                                             0x75C780

// CListWnd
#define CListWnd__CListWnd_x                                       0x90A3D0
#define CListWnd__dCListWnd_x                                      0x90A6F0
#define CListWnd__AddColumn_x                                      0x90EA30
#define CListWnd__AddColumn1_x                                     0x90EA80
#define CListWnd__AddLine_x                                        0x90EE10
#define CListWnd__AddString_x                                      0x90EC10
#define CListWnd__CalculateFirstVisibleLine_x                      0x90E7F0
#define CListWnd__CalculateVSBRange_x                              0x90E5D0
#define CListWnd__ClearSel_x                                       0x90F5F0
#define CListWnd__ClearAllSel_x                                    0x90F650
#define CListWnd__CloseAndUpdateEditWindow_x                       0x910070
#define CListWnd__Compare_x                                        0x90DF10
#define CListWnd__Draw_x                                           0x90A7F0
#define CListWnd__DrawColumnSeparators_x                           0x90CFE0
#define CListWnd__DrawHeader_x                                     0x90D450
#define CListWnd__DrawItem_x                                       0x90D850
#define CListWnd__DrawLine_x                                       0x90D150
#define CListWnd__DrawSeparator_x                                  0x90D080
#define CListWnd__EnableLine_x                                     0x90C8B0
#define CListWnd__EnsureVisible_x                                  0x90FF90
#define CListWnd__ExtendSel_x                                      0x90F520
#define CListWnd__GetColumnTooltip_x                               0x90C3F0
#define CListWnd__GetColumnMinWidth_x                              0x90C460
#define CListWnd__GetColumnWidth_x                                 0x90C360
#define CListWnd__GetCurSel_x                                      0x90BCF0
#define CListWnd__GetItemAtPoint_x                                 0x90CB30
#define CListWnd__GetItemAtPoint1_x                                0x90CBA0
#define CListWnd__GetItemData_x                                    0x90BD70
#define CListWnd__GetItemHeight_x                                  0x90C130
#define CListWnd__GetItemIcon_x                                    0x90BF00
#define CListWnd__GetItemRect_x                                    0x90C9A0
#define CListWnd__GetItemText_x                                    0x90BDB0
#define CListWnd__GetSelList_x                                     0x90F6A0
#define CListWnd__GetSeparatorRect_x                               0x90CDE0
#define CListWnd__InsertLine_x                                     0x90F200
#define CListWnd__RemoveLine_x                                     0x90F350
#define CListWnd__SetColors_x                                      0x90E5A0
#define CListWnd__SetColumnJustification_x                         0x90E2D0
#define CListWnd__SetColumnWidth_x                                 0x90E1F0
#define CListWnd__SetCurSel_x                                      0x90F460
#define CListWnd__SetItemColor_x                                   0x90FC40
#define CListWnd__SetItemData_x                                    0x90FC00
#define CListWnd__SetItemText_x                                    0x90F810
#define CListWnd__ShiftColumnSeparator_x                           0x90E390
#define CListWnd__Sort_x                                           0x90E090
#define CListWnd__ToggleSel_x                                      0x90F490
#define CListWnd__SetColumnsSizable_x                              0x90E430
#define CListWnd__SetItemWnd_x                                     0x90FAC0
#define CListWnd__GetItemWnd_x                                     0x90BF50
#define CListWnd__SetItemIcon_x                                    0x90F890
#define CListWnd__CalculateCustomWindowPositions_x                 0x90E8F0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x771E70
#define CMapViewWnd__GetWorldCoordinates_x                         0x770580
#define CMapViewWnd__HandleLButtonDown_x                           0x76D5E0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x794DD0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7956B0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x795BE0
#define CMerchantWnd__SelectRecoverySlot_x                         0x798B70
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x793910
#define CMerchantWnd__SelectBuySellSlot_x                          0x79E740
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7949E0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89EB50
#define CPacketScrambler__hton_x                                   0x89EB40

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x9293D0
#define CSidlManager__FindScreenPieceTemplate_x                    0x9297E0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9295D0
#define CSidlManager__CreateLabel_x                                0x7F6700
#define CSidlManager__CreateXWndFromTemplate_x                     0x92C780
#define CSidlManager__CreateXWndFromTemplate1_x                    0x92C960
#define CSidlManager__CreateXWnd_x                                 0x7F6630
#define CSidlManager__CreateHotButtonWnd_x                         0x7F6C00

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x925F40
#define CSidlScreenWnd__CalculateVSBRange_x                        0x925E40
#define CSidlScreenWnd__ConvertToRes_x                             0x94B1F0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x9258D0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x9255C0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x925690
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x925760
#define CSidlScreenWnd__DrawSidlPiece_x                            0x9263E0
#define CSidlScreenWnd__EnableIniStorage_x                         0x9268B0
#define CSidlScreenWnd__GetSidlPiece_x                             0x9265D0
#define CSidlScreenWnd__Init1_x                                    0x9251C0
#define CSidlScreenWnd__LoadIniInfo_x                              0x926900
#define CSidlScreenWnd__LoadIniListWnd_x                           0x927440
#define CSidlScreenWnd__LoadSidlScreen_x                           0x9245C0
#define CSidlScreenWnd__StoreIniInfo_x                             0x926FC0
#define CSidlScreenWnd__StoreIniVis_x                              0x927320
#define CSidlScreenWnd__WndNotification_x                          0x9262F0
#define CSidlScreenWnd__GetChildItem_x                             0x926830
#define CSidlScreenWnd__HandleLButtonUp_x                          0x915F00
#define CSidlScreenWnd__m_layoutCopy_x                             0x16CA840

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x66FF60
#define CSkillMgr__GetSkillCap_x                                   0x670140
#define CSkillMgr__GetNameToken_x                                  0x66F6F0
#define CSkillMgr__IsActivatedSkill_x                              0x66F830
#define CSkillMgr__IsCombatSkill_x                                 0x66F770

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9362B0
#define CSliderWnd__SetValue_x                                     0x936120
#define CSliderWnd__SetNumTicks_x                                  0x936180

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7FC7B0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x93EA10
#define CStmlWnd__CalculateHSBRange_x                              0x93FB00
#define CStmlWnd__CalculateVSBRange_x                              0x93FA70
#define CStmlWnd__CanBreakAtCharacter_x                            0x943E40
#define CStmlWnd__FastForwardToEndOfTag_x                          0x944AD0
#define CStmlWnd__ForceParseNow_x                                  0x93EFB0
#define CStmlWnd__GetNextTagPiece_x                                0x943DA0
#define CStmlWnd__GetSTMLText_x                                    0x4F7F90
#define CStmlWnd__GetVisibleText_x                                 0x93EFD0
#define CStmlWnd__InitializeWindowVariables_x                      0x944920
#define CStmlWnd__MakeStmlColorTag_x                               0x93E0F0
#define CStmlWnd__MakeWndNotificationTag_x                         0x93E160
#define CStmlWnd__SetSTMLText_x                                    0x93D1A0
#define CStmlWnd__StripFirstSTMLLines_x                            0x945BD0
#define CStmlWnd__UpdateHistoryString_x                            0x944CE0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x93C340
#define CTabWnd__DrawCurrentPage_x                                 0x93CA20
#define CTabWnd__DrawTab_x                                         0x93C740
#define CTabWnd__GetCurrentPage_x                                  0x93BB40
#define CTabWnd__GetPageInnerRect_x                                0x93BD80
#define CTabWnd__GetTabInnerRect_x                                 0x93BCC0
#define CTabWnd__GetTabRect_x                                      0x93BB70
#define CTabWnd__InsertPage_x                                      0x93BF90
#define CTabWnd__SetPage_x                                         0x93BE00
#define CTabWnd__SetPageRect_x                                     0x93C280
#define CTabWnd__UpdatePage_x                                      0x93C600
#define CTabWnd__GetPageFromTabIndex_x                             0x93C680
#define CTabWnd__GetCurrentTabIndex_x                              0x93BB30

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x7570E0
#define CPageWnd__SetTabText_x                                     0x93B680

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A6880

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x912D60
#define CTextureFont__GetTextExtent_x                              0x912F20

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6A3980
#define CHtmlComponentWnd__ValidateUri_x                           0x735CE0
#define CHtmlWnd__SetClientCallbacks_x                             0x6107F0
#define CHtmlWnd__AddObserver_x                                    0x610810
#define CHtmlWnd__RemoveObserver_x                                 0x610870
#define Window__getProgress_x                                      0x84F500
#define Window__getStatus_x                                        0x84F520
#define Window__getURI_x                                           0x84F530

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x950C60

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8FFF90

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4ADF40
#define CXStr__CXStr1_x                                            0x47BF10
#define CXStr__CXStr3_x                                            0x8EC7D0
#define CXStr__dCXStr_x                                            0x473060
#define CXStr__operator_equal_x                                    0x8ECA00
#define CXStr__operator_equal1_x                                   0x8ECA40
#define CXStr__operator_plus_equal1_x                              0x8ED4D0
#define CXStr__SetString_x                                         0x8EF3C0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x934550
#define CXWnd__BringToTop_x                                        0x9196F0
#define CXWnd__Center_x                                            0x919270
#define CXWnd__ClrFocus_x                                          0x9190A0
#define CXWnd__Destroy_x                                           0x919150
#define CXWnd__DoAllDrawing_x                                      0x915690
#define CXWnd__DrawChildren_x                                      0x915660
#define CXWnd__DrawColoredRect_x                                   0x915AF0
#define CXWnd__DrawTooltip_x                                       0x9141C0
#define CXWnd__DrawTooltipAtPoint_x                                0x914280
#define CXWnd__GetBorderFrame_x                                    0x915950
#define CXWnd__GetChildWndAt_x                                     0x919790
#define CXWnd__GetClientClipRect_x                                 0x917950
#define CXWnd__GetScreenClipRect_x                                 0x917A00
#define CXWnd__GetScreenRect_x                                     0x917BB0
#define CXWnd__GetTooltipRect_x                                    0x915B40
#define CXWnd__GetWindowTextA_x                                    0x497FF0
#define CXWnd__IsActive_x                                          0x91C660
#define CXWnd__IsDescendantOf_x                                    0x9185D0
#define CXWnd__IsReallyVisible_x                                   0x918600
#define CXWnd__IsType_x                                            0x919E10
#define CXWnd__Move_x                                              0x918680
#define CXWnd__Move1_x                                             0x918740
#define CXWnd__ProcessTransition_x                                 0x919220
#define CXWnd__Refade_x                                            0x918A10
#define CXWnd__Resize_x                                            0x918CB0
#define CXWnd__Right_x                                             0x9194B0
#define CXWnd__SetFocus_x                                          0x919060
#define CXWnd__SetFont_x                                           0x9190D0
#define CXWnd__SetKeyTooltip_x                                     0x919C20
#define CXWnd__SetMouseOver_x                                      0x916AA0
#define CXWnd__StartFade_x                                         0x9184A0
#define CXWnd__GetChildItem_x                                      0x919900
#define CXWnd__SetParent_x                                         0x918370

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x94C280

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x91C6A0
#define CXWndManager__DrawWindows_x                                0x91C6C0
#define CXWndManager__GetKeyboardFlags_x                           0x91EE30
#define CXWndManager__HandleKeyboardMsg_x                          0x91EA30
#define CXWndManager__RemoveWnd_x                                  0x91F080
#define CXWndManager__RemovePendingDeletionWnd_x                   0x91F5C0

// CDBStr
#define CDBStr__GetString_x                                        0x52FC20

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B9130
#define EQ_Character__Cur_HP_x                                     0x4CF450
#define EQ_Character__Cur_Mana_x                                   0x4D6BD0
#define EQ_Character__GetCastingTimeModifier_x                     0x4BC050
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AFB60
#define EQ_Character__GetFocusRangeModifier_x                      0x4AFCB0
#define EQ_Character__GetHPRegen_x                                 0x4DCB30
#define EQ_Character__GetEnduranceRegen_x                          0x4DD140
#define EQ_Character__GetManaRegen_x                               0x4DD580
#define EQ_Character__Max_Endurance_x                              0x636900
#define EQ_Character__Max_HP_x                                     0x4CF280
#define EQ_Character__Max_Mana_x                                   0x636700
#define EQ_Character__doCombatAbility_x                            0x638DC0
#define EQ_Character__UseSkill_x                                   0x4DF390
#define EQ_Character__GetConLevel_x                                0x62FC70
#define EQ_Character__IsExpansionFlag_x                            0x594380
#define EQ_Character__TotalEffect_x                                0x4C26C0
#define EQ_Character__GetPCSpellAffect_x                           0x4BCC40
#define EQ_Character__SpellDuration_x                              0x4BC770
#define EQ_Character__GetAdjustedSkill_x                           0x4D2230
#define EQ_Character__GetBaseSkill_x                               0x4D31D0
#define EQ_Character__CanUseItem_x                                 0x4D6EE0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BDDE0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x64CF00

//PcClient
#define PcClient__PcClient_x                                       0x62D3A0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6D70
#define CCharacterListWnd__EnterWorld_x                            0x4B67B0
#define CCharacterListWnd__Quit_x                                  0x4B64C0
#define CCharacterListWnd__UpdateList_x                            0x4B6940

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6119E0
#define EQ_Item__CreateItemTagString_x                             0x8984A0
#define EQ_Item__IsStackable_x                                     0x89CEA0
#define EQ_Item__GetImageNum_x                                     0x899ED0
#define EQ_Item__CreateItemClient_x                                0x610BD0
#define EQ_Item__GetItemValue_x                                    0x89B140
#define EQ_Item__ValueSellMerchant_x                               0x89E6F0
#define EQ_Item__IsKeyRingItem_x                                   0x89C7F0
#define EQ_Item__CanGoInBag_x                                      0x611B00
#define EQ_Item__IsEmpty_x                                         0x89C350
#define EQ_Item__GetMaxItemCount_x                                 0x89B510
#define EQ_Item__GetHeldItem_x                                     0x899DA0
#define EQ_Item__GetAugmentFitBySlot_x                             0x897DF0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x54E060
#define EQ_LoadingS__Array_x                                       0xBF35F8

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x637260
#define EQ_PC__GetAlternateAbilityId_x                             0x8A78F0
#define EQ_PC__GetCombatAbility_x                                  0x8A7F60
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A7FD0
#define EQ_PC__GetItemRecastTimer_x                                0x639340
#define EQ_PC__HasLoreItem_x                                       0x630430
#define EQ_PC__AlertInventoryChanged_x                             0x62F5A0
#define EQ_PC__GetPcZoneClient_x                                   0x65B670
#define EQ_PC__RemoveMyAffect_x                                    0x63C570
#define EQ_PC__GetKeyRingItems_x                                   0x8A8870
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A85F0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A8B60

// EQItemList 
#define EQItemList__EQItemList_x                                   0x59A8B0
#define EQItemList__add_object_x                                   0x5C7090
#define EQItemList__add_item_x                                     0x59AE00
#define EQItemList__delete_item_x                                  0x59AE50
#define EQItemList__FreeItemList_x                                 0x59AD50

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x52D1E0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x64E780
#define EQPlayer__dEQPlayer_x                                      0x641AD0
#define EQPlayer__DoAttack_x                                       0x656320
#define EQPlayer__EQPlayer_x                                       0x642180
#define EQPlayer__SetNameSpriteState_x                             0x646410
#define EQPlayer__SetNameSpriteTint_x                              0x6472D0
#define PlayerBase__HasProperty_j_x                                0x97E8B0
#define EQPlayer__IsTargetable_x                                   0x97ED50
#define EQPlayer__CanSee_x                                         0x97EBB0
#define EQPlayer__CanSee1_x                                        0x97EC80
#define PlayerBase__GetVisibilityLineSegment_x                     0x97E970

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x659100
#define PlayerZoneClient__GetLevel_x                               0x65B6B0
#define PlayerZoneClient__IsValidTeleport_x                        0x5C8200
#define PlayerZoneClient__LegalPlayerRace_x                        0x547480

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x651470
#define EQPlayerManager__GetSpawnByName_x                          0x651490
#define EQPlayerManager__GetPlayerFromPartialName_x                0x651520

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x6150E0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x615160
#define KeypressHandler__AttachKeyToEqCommand_x                    0x6151A0
#define KeypressHandler__ClearCommandStateArray_x                  0x6165B0
#define KeypressHandler__HandleKeyDown_x                           0x6165D0
#define KeypressHandler__HandleKeyUp_x                             0x616670
#define KeypressHandler__SaveKeymapping_x                          0x616AA0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x76DD00
#define MapViewMap__SaveEx_x                                       0x7710A0
#define MapViewMap__SetZoom_x                                      0x775770

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BBCD0

// StringTable 
#define StringTable__getString_x                                   0x8B6B10

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x63C1E0
#define PcZoneClient__RemovePetEffect_x                            0x63C810
#define PcZoneClient__HasAlternateAbility_x                        0x636540
#define PcZoneClient__GetCurrentMod_x                              0x4E2470
#define PcZoneClient__GetModCap_x                                  0x4E2370
#define PcZoneClient__CanEquipItem_x                               0x636BF0
#define PcZoneClient__GetItemByID_x                                0x6397C0
#define PcZoneClient__GetItemByItemClass_x                         0x639910
#define PcZoneClient__RemoveBuffEffect_x                           0x63C830
#define PcZoneClient__BandolierSwap_x                              0x637820
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x6392E0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5CCD90

//IconCache
#define IconCache__GetIcon_x                                       0x70E5E0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x7060D0
#define CContainerMgr__CloseContainer_x                            0x7063A0
#define CContainerMgr__OpenExperimentContainer_x                   0x706E20

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7C8E00

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x609D50

//CLootWnd
#define CLootWnd__LootAll_x                                        0x764140
#define CLootWnd__RequestLootSlot_x                                0x7634E0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x5665D0
#define EQ_Spell__SpellAffects_x                                   0x566A40
#define EQ_Spell__SpellAffectBase_x                                0x566800
#define EQ_Spell__IsStackable_x                                    0x4C6ED0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C6D20
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B40F0
#define EQ_Spell__IsSPAStacking_x                                  0x567870
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x566D90
#define EQ_Spell__IsNoRemove_x                                     0x4C6EB0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x567880
#define __IsResEffectSpell_x                                       0x4C6250

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AA9B0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C6460

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x80E5A0
#define CTargetWnd__WndNotification_x                              0x80DE30
#define CTargetWnd__RefreshTargetBuffs_x                           0x80E100
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x80CF90

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x812C60

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x52ABD0
#define CTaskManager__HandleMessage_x                              0x529320

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x561B60
#define EqSoundManager__PlayScriptMp3_x                            0x561CC0
#define EqSoundManager__SoundAssistPlay_x                          0x673E40
#define EqSoundManager__WaveInstancePlay_x                         0x6733B0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x51EBA0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x93AB80

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x555AE0
#define CAltAbilityData__GetMercMaxRank_x                          0x555A80
#define CAltAbilityData__GetMaxRank_x                              0x54B130

//CTargetRing
#define CTargetRing__Cast_x                                        0x607E30

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C6D00
#define CharacterBase__CreateItemGlobalIndex_x                     0x504D40
#define CharacterBase__CreateItemIndex_x                           0x60FE30
#define CharacterBase__GetItemPossession_x                         0x4F0D90
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CEAA0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CEB00
#define CharacterBase__GetEffectId_x                               0x4C6CB0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6ED550
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6EDD80

//messages
#define msg_spell_worn_off_x                                       0x58C4F0
#define msg_new_text_x                                             0x581330
#define __msgTokenTextParam_x                                      0x58EA20
#define msgTokenText_x                                             0x58EC70

//SpellManager
#define SpellManager__vftable_x                                    0xAB9C70
#define SpellManager__SpellManager_x                               0x677170
#define Spellmanager__LoadTextSpells_x                             0x677A40
#define SpellManager__GetSpellByGroupAndRank_x                     0x677340

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x982890

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x505420
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x592850
#define ItemGlobalIndex__IsEquippedLocation_x                      0x628AC0
#define ItemGlobalIndex__IsValidIndex_x                            0x505480

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C6DA0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C7020

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x75CAD0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x70A7E0
#define CCursorAttachment__AttachToCursor1_x                       0x70A820
#define CCursorAttachment__Deactivate_x                            0x70B7F0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x92D7B0
#define CSidlManagerBase__CreatePageWnd_x                          0x92CFB0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x9291F0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x929180

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x94A700
#define CEQSuiteTextureLoader__GetTexture_x                        0x94A3C0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x5022E0
#define CFindItemWnd__WndNotification_x                            0x502DC0
#define CFindItemWnd__Update_x                                     0x503930
#define CFindItemWnd__PickupSelectedItem_x                         0x501B40

//IString
#define IString__Append_x                                          0x4F2330

//Camera
#define CDisplay__cameraType_x                                     0xDCD308
#define EverQuest__Cameras_x                                       0xE906E8

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x50AAE0
#define LootFiltersManager__GetItemFilterData_x                    0x50A3E0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x50A410
#define LootFiltersManager__SetItemLootFilter_x                    0x50A630

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B6E10

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x988590
#define CResolutionHandler__GetWindowedStyle_x                     0x66EA00

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x702E90

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D9690
#define CDistillerInfo__Instance_x                                 0x8D9630

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x723080
#define CGroupWnd__UpdateDisplay_x                                 0x7223E0

//ItemBase
#define ItemBase__IsLore_x                                         0x89C850
#define ItemBase__IsLoreEquipped_x                                 0x89C8C0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5C6FF0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5C7130
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5C7190

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x664140
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x667AF0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x4F85E0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4E7760
#define FactionManagerClient__HandleFactionMessage_x               0x4E7DD0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4E83C0
#define FactionManagerClient__GetMaxFaction_x                      0x4E8410
#define FactionManagerClient__GetMinFaction_x                      0x4E8390

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4F0D60

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x911D20

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x497310

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4F0F80

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x554FD0

//CTargetManager
#define CTargetManager__Get_x                                      0x67AAC0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x664140

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A6640

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x59ACF0

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
