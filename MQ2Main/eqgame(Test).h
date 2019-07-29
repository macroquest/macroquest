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
#define __ExpectedVersionDate                                     "Jul 12 2019"
#define __ExpectedVersionTime                                     "11:24:59"
#define __ActualVersionDate_x                                      0xAE448C
#define __ActualVersionTime_x                                      0xAE4480
#define __ActualVersionBuild_x                                     0xAE4F24

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x61B560
#define __MemChecker1_x                                            0x8F2600
#define __MemChecker2_x                                            0x6AAF60
#define __MemChecker3_x                                            0x6AAEB0
#define __MemChecker4_x                                            0x849540
#define __EncryptPad0_x                                            0xC1A998
#define __EncryptPad1_x                                            0xC789C0
#define __EncryptPad2_x                                            0xC2B210
#define __EncryptPad3_x                                            0xC2AE10
#define __EncryptPad4_x                                            0xC69188
#define __EncryptPad5_x                                            0xF41B70
#define __AC1_x                                                    0x805C36
#define __AC2_x                                                    0x5D4F9F
#define __AC3_x                                                    0x5DC6AF
#define __AC4_x                                                    0x5E0590
#define __AC5_x                                                    0x5E68E0
#define __AC6_x                                                    0x5EAEA6
#define __AC7_x                                                    0x5D4A10
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x192B4C

// Direct Input
#define DI8__Main_x                                                0xF41B90
#define DI8__Keyboard_x                                            0xF41B94
#define DI8__Mouse_x                                               0xF41150
#define DI8__Mouse_Copy_x                                          0xE9C82C
#define DI8__Mouse_Check_x                                         0xF41EC4
#define __AutoSkillArray_x                                         0xE9D744
#define __Attack_x                                                 0xF3B55B
#define __Autofire_x                                               0xF3B55C
#define __BindList_x                                               0xC093F0
#define g_eqCommandStates_x                                        0xC0A168
#define __Clicks_x                                                 0xE9C8E4
#define __CommandList_x                                            0xC0AD28
#define __CurrentMapLabel_x                                        0x105C604
#define __CurrentSocial_x                                          0xBF3730
#define __DoAbilityList_x                                          0xED307C
#define __do_loot_x                                                0x5A0E20
#define __DrawHandler_x                                            0x16D8FD8
#define __GroupCount_x                                             0xE8F1CA
#define __Guilds_x                                                 0xE93038
#define __gWorld_x                                                 0xE8F1B4
#define __HWnd_x                                                   0xF41154
#define __heqmain_x                                                0x104C1AC
#define __InChatMode_x                                             0xE9C814
#define __LastTell_x                                               0xE9E778
#define __LMouseHeldTime_x                                         0xE9C950
#define __Mouse_x                                                  0xF41B7C
#define __MouseLook_x                                              0xE9C8AA
#define __MouseEventTime_x                                         0xF3C03C
#define __gpbCommandEvent_x                                        0xE8CBC8
#define __NetStatusToggle_x                                        0xE9C8AD
#define __PCNames_x                                                0xE9DD28
#define __RangeAttackReady_x                                       0xE9DA28
#define __RMouseHeldTime_x                                         0xE9C94C
#define __RunWalkState_x                                           0xE9C818
#define __ScreenMode_x                                             0xDDAA3C
#define __ScreenX_x                                                0xE9C7CC
#define __ScreenY_x                                                0xE9C7C8
#define __ScreenXMax_x                                             0xE9C7D0
#define __ScreenYMax_x                                             0xE9C7D4
#define __ServerHost_x                                             0xE8CDFB
#define __ServerName_x                                             0xED303C
#define __ShiftKeyDown_x                                           0xE9CEA4
#define __ShowNames_x                                              0xE9DBE4
#define __Socials_x                                                0xED313C
#define __SubscriptionType_x                                       0x109E198
#define __TargetAggroHolder_x                                      0x105EFB8
#define __ZoneType_x                                               0xE9CCA8
#define __GroupAggro_x                                             0x105EFF8
#define __LoginName_x                                              0xF41814
#define __Inviter_x                                                0xF3B4D8
#define __AttackOnAssist_x                                         0xE9DBA0
#define __UseTellWindows_x                                         0xE9DEC4
#define __gfMaxZoomCameraDistance_x                                0xAD9918
#define __gfMaxCameraDistance_x                                    0xB06E18
#define __pulAutoRun_x                                             0xE9C8C8
#define __pulForward_x                                             0xE9DEFC
#define __pulBackward_x                                            0xE9DF00
#define __pulTurnRight_x                                           0xE9DF04
#define __pulTurnLeft_x                                            0xE9DF08
#define __pulStrafeLeft_x                                          0xE9DF0C
#define __pulStrafeRight_x                                         0xE9DF10

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE8F3D0
#define instEQZoneInfo_x                                           0xE9CAA0
#define pinstActiveBanker_x                                        0xE8CC60
#define pinstActiveCorpse_x                                        0xE8CC58
#define pinstActiveGMaster_x                                       0xE8CC5C
#define pinstActiveMerchant_x                                      0xE8CC54
#define pinstAltAdvManager_x                                       0xDDB6A0
#define pinstBandageTarget_x                                       0xE8CC70
#define pinstCamActor_x                                            0xDDAA30
#define pinstCDBStr_x                                              0xDDA3CC
#define pinstCDisplay_x                                            0xE8F3BC
#define pinstCEverQuest_x                                          0x104B19C
#define pinstEverQuestInfo_x                                       0xE9C7C0
#define pinstCharData_x                                            0xE8F11C
#define pinstCharSpawn_x                                           0xE8CCA8
#define pinstControlledMissile_x                                   0xE8D10C
#define pinstControlledPlayer_x                                    0xE8CCA8
#define pinstCResolutionHandler_x                                  0x16D9208
#define pinstCSidlManager_x                                        0x16D81A4
#define pinstCXWndManager_x                                        0x16D8198
#define instDynamicZone_x                                          0xE92F10
#define pinstDZMember_x                                            0xE93020
#define pinstDZTimerInfo_x                                         0xE93024
#define pinstEqLogin_x                                             0xF41160
#define instEQMisc_x                                               0xDDA310
#define pinstEQSoundManager_x                                      0xDDC5C8
#define pinstEQSpellStrings_x                                      0xC9D5B0
#define instExpeditionLeader_x                                     0xE92F5A
#define instExpeditionName_x                                       0xE92F9A
#define pinstGroup_x                                               0xE8F1C6
#define pinstImeManager_x                                          0x16D819C
#define pinstLocalPlayer_x                                         0xE8CC50
#define pinstMercenaryData_x                                       0xF3DB2C
#define pinstMercenaryStats_x                                      0x105F104
#define pinstModelPlayer_x                                         0xE8CC68
#define pinstPCData_x                                              0xE8F11C
#define pinstSkillMgr_x                                            0xF3FCA0
#define pinstSpawnManager_x                                        0xF3E748
#define pinstSpellManager_x                                        0xF3FEC0
#define pinstSpellSets_x                                           0xF34184
#define pinstStringTable_x                                         0xE8F3C8
#define pinstSwitchManager_x                                       0xE8C970
#define pinstTarget_x                                              0xE8CCA4
#define pinstTargetObject_x                                        0xE8CCF0
#define pinstTargetSwitch_x                                        0xE8F118
#define pinstTaskMember_x                                          0xDDA1A0
#define pinstTrackTarget_x                                         0xE8CCAC
#define pinstTradeTarget_x                                         0xE8CC64
#define instTributeActive_x                                        0xDDA331
#define pinstViewActor_x                                           0xDDAA2C
#define pinstWorldData_x                                           0xE8F3B8
#define pinstZoneAddr_x                                            0xE9CD40
#define pinstPlayerPath_x                                          0xF3E7E0
#define pinstTargetIndicator_x                                     0xF40128
#define EQObject_Top_x                                             0xE8CBCC
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDDA534
#define pinstCAchievementsWnd_x                                    0xDDA518
#define pinstCActionsWnd_x                                         0xDDA59C
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDDAA7C
#define pinstCAdvancedLootWnd_x                                    0xDDA590
#define pinstCAdventureLeaderboardWnd_x                            0x1055DD8
#define pinstCAdventureRequestWnd_x                                0x1055E88
#define pinstCAdventureStatsWnd_x                                  0x1055F38
#define pinstCAggroMeterWnd_x                                      0xDDAACC
#define pinstCAlarmWnd_x                                           0xDDA49C
#define pinstCAlertHistoryWnd_x                                    0xDDA4C4
#define pinstCAlertStackWnd_x                                      0xDDAAC8
#define pinstCAlertWnd_x                                           0xDDAADC
#define pinstCAltStorageWnd_x                                      0x1056298
#define pinstCAudioTriggersWindow_x                                0xC8F8E0
#define pinstCAuraWnd_x                                            0xDDAAC0
#define pinstCAvaZoneWnd_x                                         0xDDA4C8
#define pinstCBandolierWnd_x                                       0xDDAAF4
#define pinstCBankWnd_x                                            0xDDA4E4
#define pinstCBarterMerchantWnd_x                                  0x10574D8
#define pinstCBarterSearchWnd_x                                    0x1057588
#define pinstCBarterWnd_x                                          0x1057638
#define pinstCBazaarConfirmationWnd_x                              0xDDAAC4
#define pinstCBazaarSearchWnd_x                                    0xDDAA4C
#define pinstCBazaarWnd_x                                          0xDDA474
#define pinstCBlockedBuffWnd_x                                     0xDDA4CC
#define pinstCBlockedPetBuffWnd_x                                  0xDDA4F0
#define pinstCBodyTintWnd_x                                        0xDDAA9C
#define pinstCBookWnd_x                                            0xDDA478
#define pinstCBreathWnd_x                                          0xDDA544
#define pinstCBuffWindowNORMAL_x                                   0xDDA4A0
#define pinstCBuffWindowSHORT_x                                    0xDDA4A4
#define pinstCBugReportWnd_x                                       0xDDA538
#define pinstCButtonWnd_x                                          0x16D8408
#define pinstCCastingWnd_x                                         0xDDA52C
#define pinstCCastSpellWnd_x                                       0xDDAA68
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDDA548
#define pinstCChatWindowManager_x                                  0x10580F8
#define pinstCClaimWnd_x                                           0x1058250
#define pinstCColorPickerWnd_x                                     0xDDA574
#define pinstCCombatAbilityWnd_x                                   0xDDAAD0
#define pinstCCombatSkillsSelectWnd_x                              0xDDA594
#define pinstCCompassWnd_x                                         0xDDAA8C
#define pinstCConfirmationDialog_x                                 0x105D150
#define pinstCContainerMgr_x                                       0xDDA530
#define pinstCContextMenuManager_x                                 0x16D8158
#define pinstCCursorAttachment_x                                   0xDDA520
#define pinstCDynamicZoneWnd_x                                     0x1058818
#define pinstCEditLabelWnd_x                                       0xDDA488
#define pinstCEQMainWnd_x                                          0x1058A60
#define pinstCEventCalendarWnd_x                                   0xDDA550
#define pinstCExtendedTargetWnd_x                                  0xDDAAA8
#define pinstCFacePick_x                                           0xDDA56C
#define pinstCFactionWnd_x                                         0xDDA528
#define pinstCFellowshipWnd_x                                      0x1058C60
#define pinstCFileSelectionWnd_x                                   0xDDA580
#define pinstCFindItemWnd_x                                        0xDDA490
#define pinstCFindLocationWnd_x                                    0x1058DB8
#define pinstCFriendsWnd_x                                         0xDDAA24
#define pinstCGemsGameWnd_x                                        0xDDA470
#define pinstCGiveWnd_x                                            0xDDA494
#define pinstCGroupSearchFiltersWnd_x                              0xDDAAE4
#define pinstCGroupSearchWnd_x                                     0x10591B0
#define pinstCGroupWnd_x                                           0x1059260
#define pinstCGuildBankWnd_x                                       0xE9DB84
#define pinstCGuildCreationWnd_x                                   0x10593C0
#define pinstCGuildMgmtWnd_x                                       0x1059470
#define pinstCharacterCreation_x                                   0xDDAAD4
#define pinstCHelpWnd_x                                            0xDDAA84
#define pinstCHeritageSelectionWnd_x                               0xDDA57C
#define pinstCHotButtonWnd_x                                       0x105B5C8
#define pinstCHotButtonWnd1_x                                      0x105B5C8
#define pinstCHotButtonWnd2_x                                      0x105B5CC
#define pinstCHotButtonWnd3_x                                      0x105B5D0
#define pinstCHotButtonWnd4_x                                      0x105B5D4
#define pinstCIconSelectionWnd_x                                   0xDDA504
#define pinstCInspectWnd_x                                         0xDDA510
#define pinstCInventoryWnd_x                                       0xDDACF8
#define pinstCInvSlotMgr_x                                         0xDDA4E8
#define pinstCItemDisplayManager_x                                 0x105BB58
#define pinstCItemExpTransferWnd_x                                 0x105BC8C
#define pinstCItemOverflowWnd_x                                    0xDDAA54
#define pinstCJournalCatWnd_x                                      0xDDA614
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDDA564
#define pinstCKeyRingWnd_x                                         0xDDA4BC
#define pinstCLargeDialogWnd_x                                     0x105DDD0
#define pinstCLayoutCopyWnd_x                                      0x105BFD8
#define pinstCLFGuildWnd_x                                         0x105C088
#define pinstCLoadskinWnd_x                                        0xDDA47C
#define pinstCLootFiltersCopyWnd_x                                 0xCABBA8
#define pinstCLootFiltersWnd_x                                     0xDDACFC
#define pinstCLootSettingsWnd_x                                    0xDDA484
#define pinstCLootWnd_x                                            0xDDA55C
#define pinstCMailAddressBookWnd_x                                 0xDDA4F4
#define pinstCMailCompositionWnd_x                                 0xDDA4DC
#define pinstCMailIgnoreListWnd_x                                  0xDDA4F8
#define pinstCMailWnd_x                                            0xDDA4A8
#define pinstCManageLootWnd_x                                      0xDDBB50
#define pinstCMapToolbarWnd_x                                      0xDDA468
#define pinstCMapViewWnd_x                                         0xDDAAEC
#define pinstCMarketplaceWnd_x                                     0xDDA554
#define pinstCMerchantWnd_x                                        0xDDA5AC
#define pinstCMIZoneSelectWnd_x                                    0x105C8C0
#define pinstCMusicPlayerWnd_x                                     0xDDA4B0
#define pinstCNameChangeMercWnd_x                                  0xDDAA80
#define pinstCNameChangePetWnd_x                                   0xDDAA70
#define pinstCNameChangeWnd_x                                      0xDDA540
#define pinstCNoteWnd_x                                            0xDDAA78
#define pinstCObjectPreviewWnd_x                                   0xDDA578
#define pinstCOptionsWnd_x                                         0xDDA46C
#define pinstCPetInfoWnd_x                                         0xDDA4D4
#define pinstCPetitionQWnd_x                                       0xDDAA28
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDDAA98
#define pinstCPlayerWnd_x                                          0xDDA480
#define pinstCPopupWndManager_x                                    0x105D150
#define pinstCProgressionSelectionWnd_x                            0x105D200
#define pinstCPurchaseGroupWnd_x                                   0xDDAA1C
#define pinstCPurchaseWnd_x                                        0xDDA584
#define pinstCPvPLeaderboardWnd_x                                  0x105D2B0
#define pinstCPvPStatsWnd_x                                        0x105D360
#define pinstCQuantityWnd_x                                        0xDDA50C
#define pinstCRaceChangeWnd_x                                      0xDDA560
#define pinstCRaidOptionsWnd_x                                     0xDDAAE8
#define pinstCRaidWnd_x                                            0xDDA514
#define pinstCRealEstateItemsWnd_x                                 0xDDA51C
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDDA54C
#define pinstCRealEstateManageWnd_x                                0xDDA48C
#define pinstCRealEstateNeighborhoodWnd_x                          0xDDA4B4
#define pinstCRealEstatePlotSearchWnd_x                            0xDDA4D8
#define pinstCRealEstatePurchaseWnd_x                              0xDDA4FC
#define pinstCRespawnWnd_x                                         0xDDAAE0
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDDAABC
#define pinstCSendMoneyWnd_x                                       0xDDA4AC
#define pinstCServerListWnd_x                                      0xDDA4C0
#define pinstCSkillsSelectWnd_x                                    0xDDA570
#define pinstCSkillsWnd_x                                          0xDDA558
#define pinstCSocialEditWnd_x                                      0xDDA524
#define pinstCSocialWnd_x                                          0xDDAAA0
#define pinstCSpellBookWnd_x                                       0xDDAAA4
#define pinstCStoryWnd_x                                           0xDDAA88
#define pinstCTargetOfTargetWnd_x                                  0x105F188
#define pinstCTargetWnd_x                                          0xDDA4D0
#define pinstCTaskOverlayWnd_x                                     0xDDA4E0
#define pinstCTaskSelectWnd_x                                      0x105F2E0
#define pinstCTaskManager_x                                        0xCAC4F8
#define pinstCTaskTemplateSelectWnd_x                              0x105F390
#define pinstCTaskWnd_x                                            0x105F440
#define pinstCTextEntryWnd_x                                       0xDDAA90
#define pinstCTimeLeftWnd_x                                        0xDDA588
#define pinstCTipWndCONTEXT_x                                      0x105F644
#define pinstCTipWndOFDAY_x                                        0x105F640
#define pinstCTitleWnd_x                                           0x105F6F0
#define pinstCTrackingWnd_x                                        0xDDA4EC
#define pinstCTradeskillWnd_x                                      0x105F858
#define pinstCTradeWnd_x                                           0xDDAA94
#define pinstCTrainWnd_x                                           0xDDA508
#define pinstCTributeBenefitWnd_x                                  0x105FA58
#define pinstCTributeMasterWnd_x                                   0x105FB08
#define pinstCTributeTrophyWnd_x                                   0x105FBB8
#define pinstCVideoModesWnd_x                                      0xDDAAAC
#define pinstCVoiceMacroWnd_x                                      0xF40890
#define pinstCVoteResultsWnd_x                                     0xDDAA20
#define pinstCVoteWnd_x                                            0xDDA58C
#define pinstCWebManager_x                                         0xF40F0C
#define pinstCZoneGuideWnd_x                                       0xDDA498
#define pinstCZonePathWnd_x                                        0xDDA4B8

#define pinstEQSuiteTextureLoader_x                                0xC7A4B0
#define pinstItemIconCache_x                                       0x1058A18
#define pinstLootFiltersManager_x                                  0xCABC58
#define pinstRewardSelectionWnd_x                                  0x105DAA8

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC2AE00
#define __CastRay_x                                                0x59C280
#define __CastRay2_x                                               0x59C2D0
#define __ConvertItemTags_x                                        0x5B7E10
#define __CrashHandler_x                                           0x852EE0
#define __CleanItemTags_x                                          0x477A70
#define __DoesFileExist_x                                          0x8F56D0
#define __EQGetTime_x                                              0x8F20E0
#define __ExecuteCmd_x                                             0x594B50
#define __FixHeading_x                                             0x98D010
#define __GameLoop_x                                               0x6AA420
#define __get_bearing_x                                            0x59BDD0
#define __get_melee_range_x                                        0x59C4C0
#define __GetAnimationCache_x                                      0x70F4F0
#define __GetGaugeValueFromEQ_x                                    0x8040D0
#define __GetLabelFromEQ_x                                         0x805BC0
#define __GetXTargetType_x                                         0x98EA70
#define __HandleMouseWheel_x                                       0x6AB010
#define __HeadingDiff_x                                            0x98D080
#define __HelpPath_x                                               0xF3BC2C
#define __LoadFrontEnd_x                                           0x6A6EF0
#define __NewUIINI_x                                               0x803DA0
#define __pCrashHandler_x                                          0x107CFC0
#define __ProcessGameEvents_x                                      0x5FC700
#define __ProcessMouseEvent_x                                      0x5FBEC0
#define __SaveColors_x                                             0x5454E0
#define __STMLToText_x                                             0x930440
#define __ToggleKeyRingItem_x                                      0x508B30
#define CMemoryMappedFile__SetFile_x                               0xA674A0
#define CrashDetected_x                                            0x6A8950
#define DrawNetStatus_x                                            0x6289F0
#define Expansion_HoT_x                                            0xE9DB8C
#define Teleport_Table_Size_x                                      0xE8CCB4
#define Teleport_Table_x                                           0xE8D110
#define Util__FastTime_x                                           0x8F1CA0
#define wwsCrashReportCheckForUploader_x                           0x853950
#define wwsCrashReportPlatformLaunchUploader_x                     0x856030

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48B910
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x494800
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4945D0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x48EEA0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x48E2F0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x54D100
#define AltAdvManager__IsAbilityReady_x                            0x54C050
#define AltAdvManager__GetAAById_x                                 0x54C250
#define AltAdvManager__CanTrainAbility_x                           0x54C2C0
#define AltAdvManager__CanSeeAbility_x                             0x54C620

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C7530
#define CharacterZoneClient__HasSkill_x                            0x4D2400
#define CharacterZoneClient__MakeMeVisible_x                       0x4D3B20
#define CharacterZoneClient__IsStackBlocked_x                      0x4BBC40
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B8390
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D64F0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D65D0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D66B0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C0710
#define CharacterZoneClient__BardCastBard_x                        0x4C31E0
#define CharacterZoneClient__GetMaxEffects_x                       0x4B8460
#define CharacterZoneClient__GetEffect_x                           0x4B82D0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C1740
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C1810
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C1860
#define CharacterZoneClient__CalcAffectChange_x                    0x4C19B0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C1B90
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B0120
#define CharacterZoneClient__FindItemByGuid_x                      0x4D4A90
#define CharacterZoneClient__FindItemByRecord_x                    0x4D4500

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D0C20
#define CBankWnd__WndNotification_x                                0x6D0A00

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6DE290

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x60B200
#define CButtonWnd__CButtonWnd_x                                   0x92C7F0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6FE570
#define CChatManager__InitContextMenu_x                            0x6F77F0
#define CChatManager__FreeChatWindow_x                             0x6FD090
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E5C50
#define CChatManager__SetLockedActiveChatWindow_x                  0x6FE1F0
#define CChatManager__CreateChatWindow_x                           0x6FD6D0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E5D60

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x941000
#define CContextMenu__dCContextMenu_x                              0x941230
#define CContextMenu__AddMenuItem_x                                0x941240
#define CContextMenu__RemoveMenuItem_x                             0x941540
#define CContextMenu__RemoveAllMenuItems_x                         0x941560
#define CContextMenu__CheckMenuItem_x                              0x9415E0
#define CContextMenu__SetMenuItem_x                                0x941470
#define CContextMenu__AddSeparator_x                               0x9413D0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x941B80
#define CContextMenuManager__RemoveMenu_x                          0x941BF0
#define CContextMenuManager__PopupMenu_x                           0x941CB0
#define CContextMenuManager__Flush_x                               0x941B20
#define CContextMenuManager__GetMenu_x                             0x496A20
#define CContextMenuManager__CreateDefaultMenu_x                   0x709CD0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x89D260
#define CChatService__GetFriendName_x                              0x8D2580

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6FEEA0
#define CChatWindow__Clear_x                                       0x700140
#define CChatWindow__WndNotification_x                             0x7008D0
#define CChatWindow__AddHistory_x                                  0x6FFA10

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93E490
#define CComboWnd__Draw_x                                          0x93D990
#define CComboWnd__GetCurChoice_x                                  0x93E2D0
#define CComboWnd__GetListRect_x                                   0x93DE40
#define CComboWnd__GetTextRect_x                                   0x93E4F0
#define CComboWnd__InsertChoice_x                                  0x93DFD0
#define CComboWnd__SetColors_x                                     0x93DFA0
#define CComboWnd__SetChoice_x                                     0x93E2A0
#define CComboWnd__GetItemCount_x                                  0x93E2E0
#define CComboWnd__GetCurChoiceText_x                              0x93E320
#define CComboWnd__GetChoiceText_x                                 0x93E2F0
#define CComboWnd__InsertChoiceAtIndex_x                           0x93E060

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x7076C0
#define CContainerWnd__vftable_x                                   0xAED728
#define CContainerWnd__SetContainer_x                              0x708C30

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x53FF40
#define CDisplay__PreZoneMainUI_x                                  0x53FF50
#define CDisplay__CleanGameUI_x                                    0x5452A0
#define CDisplay__GetClickedActor_x                                0x538260
#define CDisplay__GetUserDefinedColor_x                            0x530940
#define CDisplay__GetWorldFilePath_x                               0x539CB0
#define CDisplay__is3dON_x                                         0x534F30
#define CDisplay__ReloadUI_x                                       0x53F3D0
#define CDisplay__WriteTextHD2_x                                   0x534D10
#define CDisplay__TrueDistance_x                                   0x53B910
#define CDisplay__SetViewActor_x                                   0x537BB0
#define CDisplay__GetFloorHeight_x                                 0x534FF0
#define CDisplay__SetRenderWindow_x                                0x533920
#define CDisplay__ToggleScreenshotMode_x                           0x537680

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x960A90

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x944580
#define CEditWnd__GetCharIndexPt_x                                 0x945470
#define CEditWnd__GetDisplayString_x                               0x945310
#define CEditWnd__GetHorzOffset_x                                  0x943BB0
#define CEditWnd__GetLineForPrintableChar_x                        0x946620
#define CEditWnd__GetSelStartPt_x                                  0x945720
#define CEditWnd__GetSTMLSafeText_x                                0x945130
#define CEditWnd__PointFromPrintableChar_x                         0x946250
#define CEditWnd__SelectableCharFromPoint_x                        0x9463C0
#define CEditWnd__SetEditable_x                                    0x9457F0
#define CEditWnd__SetWindowTextA_x                                 0x944EB0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5EA3D0
#define CEverQuest__ClickedPlayer_x                                0x5DC490
#define CEverQuest__CreateTargetIndicator_x                        0x5F99B0
#define CEverQuest__DeleteTargetIndicator_x                        0x5F9A40
#define CEverQuest__DoTellWindow_x                                 0x4E5E40
#define CEverQuest__OutputTextToLog_x                              0x4E6070
#define CEverQuest__DropHeldItemOnGround_x                         0x5D14D0
#define CEverQuest__dsp_chat_x                                     0x4E6400
#define CEverQuest__trimName_x                                     0x5F5C90
#define CEverQuest__Emote_x                                        0x5EABE0
#define CEverQuest__EnterZone_x                                    0x5E4BC0
#define CEverQuest__GetBodyTypeDesc_x                              0x5EF520
#define CEverQuest__GetClassDesc_x                                 0x5EFB60
#define CEverQuest__GetClassThreeLetterCode_x                      0x5F0160
#define CEverQuest__GetDeityDesc_x                                 0x5F8300
#define CEverQuest__GetLangDesc_x                                  0x5F0320
#define CEverQuest__GetRaceDesc_x                                  0x5EFB40
#define CEverQuest__InterpretCmd_x                                 0x5F88D0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5D56C0
#define CEverQuest__LMouseUp_x                                     0x5D3A40
#define CEverQuest__RightClickedOnPlayer_x                         0x5D5FA0
#define CEverQuest__RMouseUp_x                                     0x5D49D0
#define CEverQuest__SetGameState_x                                 0x5D1260
#define CEverQuest__UPCNotificationFlush_x                         0x5F5B90
#define CEverQuest__IssuePetCommand_x                              0x5F1730
#define CEverQuest__ReportSuccessfulHit_x                          0x5EBFE0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x719850
#define CGaugeWnd__CalcLinesFillRect_x                             0x7198B0
#define CGaugeWnd__Draw_x                                          0x718E90

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ACDA0
#define CGuild__GetGuildName_x                                     0x4ABE80
#define CGuild__GetGuildIndex_x                                    0x4AC210

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x734C60

//CHotButton
#define CHotButton__SetButtonSize_x                                0x60B5C0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x741C80
#define CInvSlotMgr__MoveItem_x                                    0x7409A0
#define CInvSlotMgr__SelectSlot_x                                  0x741D50

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x73F250
#define CInvSlot__SliderComplete_x                                 0x73CFB0
#define CInvSlot__GetItemBase_x                                    0x73C920
#define CInvSlot__UpdateItem_x                                     0x73CA90

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7437B0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x742960
#define CInvSlotWnd__HandleLButtonUp_x                             0x743330

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x8002E0
#define CItemDisplayWnd__UpdateStrings_x                           0x751E90
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x74BC80
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x74C190
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x7524A0
#define CItemDisplayWnd__AboutToShow_x                             0x751AD0
#define CItemDisplayWnd__WndNotification_x                         0x753590
#define CItemDisplayWnd__RequestConvertItem_x                      0x753050
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x750B40
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x7518F0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x838170

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x757750

// CLabel 
#define CLabel__Draw_x                                             0x75D1F0

// CListWnd
#define CListWnd__CListWnd_x                                       0x916B00
#define CListWnd__dCListWnd_x                                      0x916E10
#define CListWnd__AddColumn_x                                      0x91B110
#define CListWnd__AddColumn1_x                                     0x91B160
#define CListWnd__AddLine_x                                        0x91B4F0
#define CListWnd__AddString_x                                      0x91B2F0
#define CListWnd__CalculateFirstVisibleLine_x                      0x91AED0
#define CListWnd__CalculateVSBRange_x                              0x91ACB0
#define CListWnd__ClearSel_x                                       0x91BCD0
#define CListWnd__ClearAllSel_x                                    0x91BD30
#define CListWnd__CloseAndUpdateEditWindow_x                       0x91C730
#define CListWnd__Compare_x                                        0x91A5F0
#define CListWnd__Draw_x                                           0x916F10
#define CListWnd__DrawColumnSeparators_x                           0x9196D0
#define CListWnd__DrawHeader_x                                     0x919B40
#define CListWnd__DrawItem_x                                       0x919F30
#define CListWnd__DrawLine_x                                       0x919840
#define CListWnd__DrawSeparator_x                                  0x919770
#define CListWnd__EnableLine_x                                     0x918FB0
#define CListWnd__EnsureVisible_x                                  0x91C660
#define CListWnd__ExtendSel_x                                      0x91BC00
#define CListWnd__GetColumnTooltip_x                               0x918AF0
#define CListWnd__GetColumnMinWidth_x                              0x918B60
#define CListWnd__GetColumnWidth_x                                 0x918A60
#define CListWnd__GetCurSel_x                                      0x9183F0
#define CListWnd__GetItemAtPoint_x                                 0x919220
#define CListWnd__GetItemAtPoint1_x                                0x919290
#define CListWnd__GetItemData_x                                    0x918470
#define CListWnd__GetItemHeight_x                                  0x918830
#define CListWnd__GetItemIcon_x                                    0x918600
#define CListWnd__GetItemRect_x                                    0x9190A0
#define CListWnd__GetItemText_x                                    0x9184B0
#define CListWnd__GetSelList_x                                     0x91BD80
#define CListWnd__GetSeparatorRect_x                               0x9194D0
#define CListWnd__InsertLine_x                                     0x91B8E0
#define CListWnd__RemoveLine_x                                     0x91BA30
#define CListWnd__SetColors_x                                      0x91AC80
#define CListWnd__SetColumnJustification_x                         0x91A9B0
#define CListWnd__SetColumnWidth_x                                 0x91A8D0
#define CListWnd__SetCurSel_x                                      0x91BB40
#define CListWnd__SetItemColor_x                                   0x91C320
#define CListWnd__SetItemData_x                                    0x91C2E0
#define CListWnd__SetItemText_x                                    0x91BEF0
#define CListWnd__ShiftColumnSeparator_x                           0x91AA70
#define CListWnd__Sort_x                                           0x91A770
#define CListWnd__ToggleSel_x                                      0x91BB70
#define CListWnd__SetColumnsSizable_x                              0x91AB10
#define CListWnd__SetItemWnd_x                                     0x91C1A0
#define CListWnd__GetItemWnd_x                                     0x918650
#define CListWnd__SetItemIcon_x                                    0x91BF70
#define CListWnd__CalculateCustomWindowPositions_x                 0x91AFD0
#define CListWnd__SetVScrollPos_x                                  0x91A8B0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7729A0
#define CMapViewWnd__GetWorldCoordinates_x                         0x7710B0
#define CMapViewWnd__HandleLButtonDown_x                           0x76E110

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x795BB0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x796490
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7969C0
#define CMerchantWnd__SelectRecoverySlot_x                         0x799950
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x794700
#define CMerchantWnd__SelectBuySellSlot_x                          0x79F520
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7957D0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8A0190
#define CPacketScrambler__hton_x                                   0x8A0180

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x935A20
#define CSidlManager__FindScreenPieceTemplate_x                    0x935E30
#define CSidlManager__FindScreenPieceTemplate1_x                   0x935C20
#define CSidlManager__CreateLabel_x                                0x7F7760
#define CSidlManager__CreateXWndFromTemplate_x                     0x938DD0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x938FB0
#define CSidlManager__CreateXWnd_x                                 0x7F7690
#define CSidlManager__CreateHotButtonWnd_x                         0x7F7C60

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x932590
#define CSidlScreenWnd__CalculateVSBRange_x                        0x932480
#define CSidlScreenWnd__ConvertToRes_x                             0x957AB0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x931F10
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x931C00
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x931CD0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x931DA0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x932A30
#define CSidlScreenWnd__EnableIniStorage_x                         0x932F00
#define CSidlScreenWnd__GetSidlPiece_x                             0x932C20
#define CSidlScreenWnd__Init1_x                                    0x931820
#define CSidlScreenWnd__LoadIniInfo_x                              0x932F50
#define CSidlScreenWnd__LoadIniListWnd_x                           0x933A90
#define CSidlScreenWnd__LoadSidlScreen_x                           0x930C20
#define CSidlScreenWnd__StoreIniInfo_x                             0x933610
#define CSidlScreenWnd__StoreIniVis_x                              0x933970
#define CSidlScreenWnd__WndNotification_x                          0x932940
#define CSidlScreenWnd__GetChildItem_x                             0x932E80
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9225C0
#define CSidlScreenWnd__m_layoutCopy_x                             0x16D8028

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6701B0
#define CSkillMgr__GetSkillCap_x                                   0x670390
#define CSkillMgr__GetNameToken_x                                  0x66F940
#define CSkillMgr__IsActivatedSkill_x                              0x66FA80
#define CSkillMgr__IsCombatSkill_x                                 0x66F9C0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x942980
#define CSliderWnd__SetValue_x                                     0x9427F0
#define CSliderWnd__SetNumTicks_x                                  0x942850

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7FD7B0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x94B130
#define CStmlWnd__CalculateHSBRange_x                              0x94C220
#define CStmlWnd__CalculateVSBRange_x                              0x94C190
#define CStmlWnd__CanBreakAtCharacter_x                            0x950570
#define CStmlWnd__FastForwardToEndOfTag_x                          0x951200
#define CStmlWnd__ForceParseNow_x                                  0x94B6D0
#define CStmlWnd__GetNextTagPiece_x                                0x9504D0
#define CStmlWnd__GetSTMLText_x                                    0x4F7D70
#define CStmlWnd__GetVisibleText_x                                 0x94B6F0
#define CStmlWnd__InitializeWindowVariables_x                      0x951050
#define CStmlWnd__MakeStmlColorTag_x                               0x94A7A0
#define CStmlWnd__MakeWndNotificationTag_x                         0x94A810
#define CStmlWnd__SetSTMLText_x                                    0x949850
#define CStmlWnd__StripFirstSTMLLines_x                            0x952300
#define CStmlWnd__UpdateHistoryString_x                            0x951410

// CTabWnd 
#define CTabWnd__Draw_x                                            0x9489F0
#define CTabWnd__DrawCurrentPage_x                                 0x9490D0
#define CTabWnd__DrawTab_x                                         0x948DF0
#define CTabWnd__GetCurrentPage_x                                  0x9481F0
#define CTabWnd__GetPageInnerRect_x                                0x948430
#define CTabWnd__GetTabInnerRect_x                                 0x948370
#define CTabWnd__GetTabRect_x                                      0x948220
#define CTabWnd__InsertPage_x                                      0x948640
#define CTabWnd__SetPage_x                                         0x9484B0
#define CTabWnd__SetPageRect_x                                     0x948930
#define CTabWnd__UpdatePage_x                                      0x948CB0
#define CTabWnd__GetPageFromTabIndex_x                             0x948D30
#define CTabWnd__GetCurrentTabIndex_x                              0x9481E0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x757B20
#define CPageWnd__SetTabText_x                                     0x947D40

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A6A60

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91F410
#define CTextureFont__GetTextExtent_x                              0x91F5D0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6A3F10
#define CHtmlComponentWnd__ValidateUri_x                           0x736650
#define CHtmlWnd__SetClientCallbacks_x                             0x610660
#define CHtmlWnd__AddObserver_x                                    0x610680
#define CHtmlWnd__RemoveObserver_x                                 0x6106E0
#define Window__getProgress_x                                      0x850B50
#define Window__getStatus_x                                        0x850B70
#define Window__getURI_x                                           0x850B80

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x95D4C0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x90C870

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E5B40
#define CXStr__CXStr1_x                                            0x8411F0
#define CXStr__CXStr3_x                                            0x8EE1D0
#define CXStr__dCXStr_x                                            0x473050
#define CXStr__operator_equal_x                                    0x8EE400
#define CXStr__operator_equal1_x                                   0x8EE440
#define CXStr__operator_plus_equal1_x                              0x8EEED0
#define CXStr__SetString_x                                         0x8F0DC0
#define CXStr__operator_char_p_x                                   0x8EE910
#define CXStr__GetChar_x                                           0x8F0710
#define CXStr__Delete_x                                            0x8EFFC0
#define CXStr__GetUnicode_x                                        0x8F0780
#define CXStr__GetLength_x                                         0x4A6810
#define CXStr__Mid_x                                               0x477E20
#define CXStr__Insert_x                                            0x8F07E0
#define CXStr__FindNext_x                                          0x8F0430

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x940C10
#define CXWnd__BringToTop_x                                        0x925D60
#define CXWnd__Center_x                                            0x9258E0
#define CXWnd__ClrFocus_x                                          0x925720
#define CXWnd__Destroy_x                                           0x9257C0
#define CXWnd__DoAllDrawing_x                                      0x921D50
#define CXWnd__DrawChildren_x                                      0x921D20
#define CXWnd__DrawColoredRect_x                                   0x9221B0
#define CXWnd__DrawTooltip_x                                       0x920870
#define CXWnd__DrawTooltipAtPoint_x                                0x920930
#define CXWnd__GetBorderFrame_x                                    0x922010
#define CXWnd__GetChildWndAt_x                                     0x925E00
#define CXWnd__GetClientClipRect_x                                 0x923FE0
#define CXWnd__GetScreenClipRect_x                                 0x9240B0
#define CXWnd__GetScreenRect_x                                     0x924280
#define CXWnd__GetTooltipRect_x                                    0x922200
#define CXWnd__GetWindowTextA_x                                    0x498120
#define CXWnd__IsActive_x                                          0x922940
#define CXWnd__IsDescendantOf_x                                    0x924CA0
#define CXWnd__IsReallyVisible_x                                   0x924CD0
#define CXWnd__IsType_x                                            0x926480
#define CXWnd__Move_x                                              0x924D40
#define CXWnd__Move1_x                                             0x924E00
#define CXWnd__ProcessTransition_x                                 0x925890
#define CXWnd__Refade_x                                            0x9250D0
#define CXWnd__Resize_x                                            0x925370
#define CXWnd__Right_x                                             0x925B20
#define CXWnd__SetFocus_x                                          0x9256E0
#define CXWnd__SetFont_x                                           0x925750
#define CXWnd__SetKeyTooltip_x                                     0x926290
#define CXWnd__SetMouseOver_x                                      0x923160
#define CXWnd__StartFade_x                                         0x924B70
#define CXWnd__GetChildItem_x                                      0x925F70
#define CXWnd__SetParent_x                                         0x924A40
#define CXWnd__Minimize_x                                          0x9253D0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x958B40

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x928CE0
#define CXWndManager__DrawWindows_x                                0x928D00
#define CXWndManager__GetKeyboardFlags_x                           0x92B480
#define CXWndManager__HandleKeyboardMsg_x                          0x92B080
#define CXWndManager__RemoveWnd_x                                  0x92B6D0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x92BC30

// CDBStr
#define CDBStr__GetString_x                                        0x52F8F0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B9370
#define EQ_Character__Cur_HP_x                                     0x4CF3E0
#define EQ_Character__Cur_Mana_x                                   0x4D6BB0
#define EQ_Character__GetCastingTimeModifier_x                     0x4BC290
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AFD60
#define EQ_Character__GetFocusRangeModifier_x                      0x4AFEB0
#define EQ_Character__GetHPRegen_x                                 0x4DC9E0
#define EQ_Character__GetEnduranceRegen_x                          0x4DCFF0
#define EQ_Character__GetManaRegen_x                               0x4DD430
#define EQ_Character__Max_Endurance_x                              0x6367F0
#define EQ_Character__Max_HP_x                                     0x4CF210
#define EQ_Character__Max_Mana_x                                   0x6365F0
#define EQ_Character__doCombatAbility_x                            0x638CB0
#define EQ_Character__UseSkill_x                                   0x4DF240
#define EQ_Character__GetConLevel_x                                0x62F9C0
#define EQ_Character__IsExpansionFlag_x                            0x593310
#define EQ_Character__TotalEffect_x                                0x4C2920
#define EQ_Character__GetPCSpellAffect_x                           0x4BCE90
#define EQ_Character__SpellDuration_x                              0x4BC9C0
#define EQ_Character__GetAdjustedSkill_x                           0x4D21C0
#define EQ_Character__GetBaseSkill_x                               0x4D3160
#define EQ_Character__CanUseItem_x                                 0x4D6EC0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BF360

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x64CE50

//PcClient
#define PcClient__PcClient_x                                       0x62D100

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6FE0
#define CCharacterListWnd__EnterWorld_x                            0x4B6A20
#define CCharacterListWnd__Quit_x                                  0x4B6730
#define CCharacterListWnd__UpdateList_x                            0x4B6BB0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x611890
#define EQ_Item__CreateItemTagString_x                             0x8999E0
#define EQ_Item__IsStackable_x                                     0x89E500
#define EQ_Item__GetImageNum_x                                     0x89B420
#define EQ_Item__CreateItemClient_x                                0x610A60
#define EQ_Item__GetItemValue_x                                    0x89C730
#define EQ_Item__ValueSellMerchant_x                               0x89FD30
#define EQ_Item__IsKeyRingItem_x                                   0x89DE60
#define EQ_Item__CanGoInBag_x                                      0x6119B0
#define EQ_Item__IsEmpty_x                                         0x89D970
#define EQ_Item__GetMaxItemCount_x                                 0x89CB60
#define EQ_Item__GetHeldItem_x                                     0x89B2F0
#define EQ_Item__GetAugmentFitBySlot_x                             0x899330

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x54DDF0
#define EQ_LoadingS__Array_x                                       0xC02600

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x637150
#define EQ_PC__GetAlternateAbilityId_x                             0x8A8EB0
#define EQ_PC__GetCombatAbility_x                                  0x8A9520
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A9590
#define EQ_PC__GetItemRecastTimer_x                                0x639230
#define EQ_PC__HasLoreItem_x                                       0x6301D0
#define EQ_PC__AlertInventoryChanged_x                             0x62F300
#define EQ_PC__GetPcZoneClient_x                                   0x65B850
#define EQ_PC__RemoveMyAffect_x                                    0x63C450
#define EQ_PC__GetKeyRingItems_x                                   0x8A9E30
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A9BB0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8AA120

// EQItemList 
#define EQItemList__EQItemList_x                                   0x599870
#define EQItemList__add_object_x                                   0x5C6B10
#define EQItemList__add_item_x                                     0x599DC0
#define EQItemList__delete_item_x                                  0x599E10
#define EQItemList__FreeItemList_x                                 0x599D10

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x52D410

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x64E6D0
#define EQPlayer__dEQPlayer_x                                      0x6419C0
#define EQPlayer__DoAttack_x                                       0x6564E0
#define EQPlayer__EQPlayer_x                                       0x642080
#define EQPlayer__SetNameSpriteState_x                             0x646330
#define EQPlayer__SetNameSpriteTint_x                              0x647200
#define PlayerBase__HasProperty_j_x                                0x98B3F0
#define EQPlayer__IsTargetable_x                                   0x98B890
#define EQPlayer__CanSee_x                                         0x98B6F0
#define EQPlayer__CanSee1_x                                        0x98B7C0
#define PlayerBase__GetVisibilityLineSegment_x                     0x98B4B0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x6592E0
#define PlayerZoneClient__GetLevel_x                               0x65B890
#define PlayerZoneClient__IsValidTeleport_x                        0x5C7C80
#define PlayerZoneClient__LegalPlayerRace_x                        0x547180

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x651420
#define EQPlayerManager__GetSpawnByName_x                          0x6514D0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x651560

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x6150C0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x615140
#define KeypressHandler__AttachKeyToEqCommand_x                    0x615180
#define KeypressHandler__ClearCommandStateArray_x                  0x616590
#define KeypressHandler__HandleKeyDown_x                           0x6165B0
#define KeypressHandler__HandleKeyUp_x                             0x616650
#define KeypressHandler__SaveKeymapping_x                          0x616A80

// MapViewMap 
#define MapViewMap__Clear_x                                        0x76E830
#define MapViewMap__SaveEx_x                                       0x771BD0
#define MapViewMap__SetZoom_x                                      0x7762A0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BD250

// StringTable 
#define StringTable__getString_x                                   0x8B8180

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x63C0C0
#define PcZoneClient__RemovePetEffect_x                            0x63C6F0
#define PcZoneClient__HasAlternateAbility_x                        0x636430
#define PcZoneClient__GetCurrentMod_x                              0x4E2330
#define PcZoneClient__GetModCap_x                                  0x4E2230
#define PcZoneClient__CanEquipItem_x                               0x636AE0
#define PcZoneClient__GetItemByID_x                                0x6396A0
#define PcZoneClient__GetItemByItemClass_x                         0x6397F0
#define PcZoneClient__RemoveBuffEffect_x                           0x63C710
#define PcZoneClient__BandolierSwap_x                              0x637710
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x6391D0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5CC8F0

//IconCache
#define IconCache__GetIcon_x                                       0x70ED80

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x706860
#define CContainerMgr__CloseContainer_x                            0x706B30
#define CContainerMgr__OpenExperimentContainer_x                   0x7075B0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7C9CB0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x6099E0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x764B60
#define CLootWnd__RequestLootSlot_x                                0x763D60

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x5660A0
#define EQ_Spell__SpellAffects_x                                   0x566510
#define EQ_Spell__SpellAffectBase_x                                0x5662D0
#define EQ_Spell__IsStackable_x                                    0x4C6EA0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C6D20
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B4350
#define EQ_Spell__IsSPAStacking_x                                  0x567340
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x566860
#define EQ_Spell__IsNoRemove_x                                     0x4C6E80
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x567350
#define __IsResEffectSpell_x                                       0x4C62D0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AAB00

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C7990

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x80FBC0
#define CTargetWnd__WndNotification_x                              0x80F450
#define CTargetWnd__RefreshTargetBuffs_x                           0x80F720
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x80E5B0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x814190

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x52AF20
#define CTaskManager__HandleMessage_x                              0x529630

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x561650
#define EqSoundManager__PlayScriptMp3_x                            0x5617B0
#define EqSoundManager__SoundAssistPlay_x                          0x674150
#define EqSoundManager__WaveInstancePlay_x                         0x6736C0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x51F060

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x947240

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x555760
#define CAltAbilityData__GetMercMaxRank_x                          0x555700
#define CAltAbilityData__GetMaxRank_x                              0x54AF00

//CTargetRing
#define CTargetRing__Cast_x                                        0x607AF0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C6D00
#define CharacterBase__CreateItemGlobalIndex_x                     0x504E20
#define CharacterBase__CreateItemIndex_x                           0x60FC20
#define CharacterBase__GetItemPossession_x                         0x4F0A50
#define CharacterBase__GetItemByGlobalIndex_x                      0x8D0020
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8D0080
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6EDB00
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6EE330
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6EE3E0

//messages
#define msg_spell_worn_off_x                                       0x58B610
#define msg_new_text_x                                             0x580420
#define __msgTokenTextParam_x                                      0x58DB40
#define msgTokenText_x                                             0x58DD90

//SpellManager
#define SpellManager__vftable_x                                    0xAC7CB8
#define SpellManager__SpellManager_x                               0x677480
#define Spellmanager__LoadTextSpells_x                             0x677D80
#define SpellManager__GetSpellByGroupAndRank_x                     0x677650

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98F360

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x5054D0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x591920
#define ItemGlobalIndex__IsEquippedLocation_x                      0x628850
#define ItemGlobalIndex__IsValidIndex_x                            0x505530

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C8330
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C85B0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x75D540

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x70AF90
#define CCursorAttachment__AttachToCursor1_x                       0x70AFD0
#define CCursorAttachment__Deactivate_x                            0x70BFB0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x939E00
#define CSidlManagerBase__CreatePageWnd_x                          0x939600
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x935840
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x9357D0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x956F20
#define CEQSuiteTextureLoader__GetTexture_x                        0x956BE0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x502390
#define CFindItemWnd__WndNotification_x                            0x502E70
#define CFindItemWnd__Update_x                                     0x5039E0
#define CFindItemWnd__PickupSelectedItem_x                         0x501C00

//IString
#define IString__Append_x                                          0x4F2000

//Camera
#define CDisplay__cameraType_x                                     0xDDAAF0
#define EverQuest__Cameras_x                                       0xE9DED0

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x50AE20
#define LootFiltersManager__GetItemFilterData_x                    0x50A710
#define LootFiltersManager__RemoveItemLootFilter_x                 0x50A740
#define LootFiltersManager__SetItemLootFilter_x                    0x50A960

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B7C90

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x995000
#define CResolutionHandler__GetWindowedStyle_x                     0x66ED80

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x703600

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8DACB0
#define CDistillerInfo__Instance_x                                 0x8DAC50

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x7239E0
#define CGroupWnd__UpdateDisplay_x                                 0x722D40

//ItemBase
#define ItemBase__IsLore_x                                         0x89DEC0
#define ItemBase__IsLoreEquipped_x                                 0x89DF30

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5C6A70
#define EQPlacedItemManager__GetItemByGuid_x                       0x5C6BB0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5C6C10

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6643A0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x667D50

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x4F8730

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4E77E0
#define FactionManagerClient__HandleFactionMessage_x               0x4E7E50
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4E8480
#define FactionManagerClient__GetMaxFaction_x                      0x4E84D0
#define FactionManagerClient__GetMinFaction_x                      0x4E8450

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4F0A20

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91E440

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x497410

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4F0C40

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x554C40

//CTargetManager
#define CTargetManager__Get_x                                      0x67ADE0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6643A0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A6820

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x599CB0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF3B560

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
