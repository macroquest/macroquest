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
#define __ExpectedVersionDate                                     "Mar 14 2019"
#define __ExpectedVersionTime                                     "16:05:23"
#define __ActualVersionDate_x                                      0xAD4424
#define __ActualVersionTime_x                                      0xAD4418

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x619660
#define __MemChecker1_x                                            0x8EDFC0
#define __MemChecker2_x                                            0x6A8730
#define __MemChecker3_x                                            0x6A8680
#define __MemChecker4_x                                            0x845650
#define __EncryptPad0_x                                            0xC089B0
#define __EncryptPad1_x                                            0xC66C38
#define __EncryptPad2_x                                            0xC19530
#define __EncryptPad3_x                                            0xC19130
#define __EncryptPad4_x                                            0xC574A8
#define __EncryptPad5_x                                            0xF2E5A8
#define __AC1_x                                                    0x802306
#define __AC2_x                                                    0x5D3B2F
#define __AC3_x                                                    0x5DB23F
#define __AC4_x                                                    0x5DF080
#define __AC5_x                                                    0x5E52F0
#define __AC6_x                                                    0x5E98B6
#define __AC7_x                                                    0x5D35A0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1EC57C

// Direct Input
#define DI8__Main_x                                                0xF2E5CC
#define DI8__Keyboard_x                                            0xF2E5D0
#define DI8__Mouse_x                                               0xF2DB88
#define DI8__Mouse_Copy_x                                          0xE8B8C4
#define DI8__Mouse_Check_x                                         0xF2EA00
#define __AutoSkillArray_x                                         0xE8C7DC
#define __Attack_x                                                 0xF2A5F3
#define __Autofire_x                                               0xF2A5F4
#define __BindList_x                                               0xBF73F0
#define g_eqCommandStates_x                                        0xBF8168
#define __Clicks_x                                                 0xE8B97C
#define __CommandList_x                                            0xBF8D28
#define __CurrentMapLabel_x                                        0x104018C
#define __CurrentSocial_x                                          0xBE1730
#define __DoAbilityList_x                                          0xEC2114
#define __do_loot_x                                                0x5A04C0
#define __DrawHandler_x                                            0x16BCB80
#define __GroupCount_x                                             0xE7BB82
#define __Guilds_x                                                 0xE820D0
#define __gWorld_x                                                 0xE7E40C
#define __HWnd_x                                                   0xF2DB8C
#define __heqmain_x                                                0x1038D44
#define __InChatMode_x                                             0xE8B8AC
#define __LastTell_x                                               0xE8D810
#define __LMouseHeldTime_x                                         0xE8B9E8
#define __Mouse_x                                                  0xF2E5B4
#define __MouseLook_x                                              0xE8B942
#define __MouseEventTime_x                                         0xF2B0A8
#define __gpbCommandEvent_x                                        0xE7DE9C
#define __NetStatusToggle_x                                        0xE8B945
#define __PCNames_x                                                0xE8CDC0
#define __RangeAttackReady_x                                       0xE8CAC0
#define __RMouseHeldTime_x                                         0xE8B9E4
#define __RunWalkState_x                                           0xE8B8B0
#define __ScreenMode_x                                             0xDCA420
#define __ScreenX_x                                                0xE8B864
#define __ScreenY_x                                                0xE8B860
#define __ScreenXMax_x                                             0xE8B868
#define __ScreenYMax_x                                             0xE8B86C
#define __ServerHost_x                                             0xE7E0DB
#define __ServerName_x                                             0xEC20D4
#define __ShiftKeyDown_x                                           0xE8BF3C
#define __ShowNames_x                                              0xE8CC7C
#define __Socials_x                                                0xEC21D4
#define __SubscriptionType_x                                       0x1081CDC
#define __TargetAggroHolder_x                                      0x1042B48
#define __ZoneType_x                                               0xE8BD40
#define __GroupAggro_x                                             0x1042B88
#define __LoginName_x                                              0xF2E24C
#define __Inviter_x                                                0xF2A570
#define __AttackOnAssist_x                                         0xE8CC38
#define __UseTellWindows_x                                         0xE8CF5C
#define __gfMaxZoomCameraDistance_x                                0xAC98D0
#define __gfMaxCameraDistance_x                                    0xAF6D78
#define __pulAutoRun_x                                             0xE8B960
#define __pulForward_x                                             0xE8CF94
#define __pulBackward_x                                            0xE8CF98
#define __pulTurnRight_x                                           0xE8CF9C
#define __pulTurnLeft_x                                            0xE8CFA0
#define __pulStrafeLeft_x                                          0xE8CFA4
#define __pulStrafeRight_x                                         0xE8CFA8

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE7E468
#define instEQZoneInfo_x                                           0xE8BB38
#define instKeypressHandler_x                                      0xF2B058
#define pinstActiveBanker_x                                        0xE7DF40
#define pinstActiveCorpse_x                                        0xE7DF38
#define pinstActiveGMaster_x                                       0xE7DF3C
#define pinstActiveMerchant_x                                      0xE7DF34
#define pinstAggroInfo_x                                           0xC7D478
#define pinstAltAdvManager_x                                       0xDCAE10
#define pinstAuraMgr_x                                             0xC990A0
#define pinstBandageTarget_x                                       0xE7DF50
#define pinstCamActor_x                                            0xDCA410
#define pinstCDBStr_x                                              0xDC9B3C
#define pinstCDisplay_x                                            0xE7E458
#define pinstCEverQuest_x                                          0x1037D30
#define pinstEverQuestInfo_x                                       0xE8B858
#define pinstCharData_x                                            0xE7BB5C
#define pinstCharSpawn_x                                           0xE7DF88
#define pinstControlledMissile_x                                   0xE7E460
#define pinstControlledPlayer_x                                    0xE7DF88
#define pinstCResolutionHandler_x                                  0x16BCDB0
#define pinstCSidlManager_x                                        0x16BBC34
#define pinstCXWndManager_x                                        0x16BBC28
#define instDynamicZone_x                                          0xE81FA8
#define pinstDZMember_x                                            0xE820B8
#define pinstDZTimerInfo_x                                         0xE820BC
#define pinstEQItemList_x                                          0xE7A658
#define pinstEQObjectList_x                                        0xE7B848
#define instEQMisc_x                                               0xDC9A80
#define pinstEQSoundManager_x                                      0xDCB670
#define pinstEQSpellStrings_x                                      0xC8B5B0
#define instExpeditionLeader_x                                     0xE81FF2
#define instExpeditionName_x                                       0xE82032
#define pinstGroup_x                                               0xE7BB7E
#define pinstImeManager_x                                          0x16BBC2C
#define pinstLocalPlayer_x                                         0xE7DF30
#define pinstMercenaryData_x                                       0xF2B848
#define pinstMercenaryStats_x                                      0x1042C94
#define pinstMercAltAbilities_x                                    0xDCB3E0
#define pinstModelPlayer_x                                         0xE7DF48
#define pinstPCData_x                                              0xE7BB5C
#define pinstRealEstateItems_x                                     0xF2CD48
#define pinstSkillMgr_x                                            0xF2CE18
#define pinstSpawnManager_x                                        0xF2C408
#define pinstSpellManager_x                                        0xF2CFF0
#define pinstSpellSets_x                                           0xF2321C
#define pinstStringTable_x                                         0xE7DD74
#define pinstSwitchManager_x                                       0xE7BA08
#define pinstTarget_x                                              0xE7DF84
#define pinstTargetObject_x                                        0xE7DF90
#define pinstTargetSwitch_x                                        0xE7BB60
#define pinstTaskMember_x                                          0xDC9914
#define pinstTrackTarget_x                                         0xE7DF8C
#define pinstTradeTarget_x                                         0xE7DF44
#define instTributeActive_x                                        0xDC9AA1
#define pinstViewActor_x                                           0xDCA40C
#define pinstWorldData_x                                           0xE7DE8C
#define pinstZoneAddr_x                                            0xE8BDD8
#define pinstPlayerPath_x                                          0xF2C4A0
#define pinstTargetIndicator_x                                     0xF2D258
#define pinstCTargetManager_x                                      0xF2D2F0
#define EQObject_Top_x                                             0xE7DEAC
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDCA45C
#define pinstCAchievementsWnd_x                                    0xDCA44C
#define pinstCActionsWnd_x                                         0xDC9E34
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDCA2E4
#define pinstCAdvancedLootWnd_x                                    0xDC9E2C
#define pinstCAdventureLeaderboardWnd_x                            0x1039960
#define pinstCAdventureRequestWnd_x                                0x1039A10
#define pinstCAdventureStatsWnd_x                                  0x1039AC0
#define pinstCAggroMeterWnd_x                                      0xDCA344
#define pinstCAlarmWnd_x                                           0xDCA39C
#define pinstCAlertHistoryWnd_x                                    0xDCA3F0
#define pinstCAlertStackWnd_x                                      0xDCA354
#define pinstCAlertWnd_x                                           0xDCA364
#define pinstCAltStorageWnd_x                                      0x1039E20
#define pinstCAudioTriggersWindow_x                                0xC7D908
#define pinstCAuraWnd_x                                            0xDCA33C
#define pinstCAvaZoneWnd_x                                         0xDCA3F4
#define pinstCBandolierWnd_x                                       0xDCA36C
#define pinstCBankWnd_x                                            0xDCA3E0
#define pinstCBarterMerchantWnd_x                                  0x103B060
#define pinstCBarterSearchWnd_x                                    0x103B110
#define pinstCBarterWnd_x                                          0x103B1C0
#define pinstCBazaarConfirmationWnd_x                              0xDCA350
#define pinstCBazaarSearchWnd_x                                    0xDC9ECC
#define pinstCBazaarWnd_x                                          0xDCA37C
#define pinstCBlockedBuffWnd_x                                     0xDCA3C8
#define pinstCBlockedPetBuffWnd_x                                  0xDCA3FC
#define pinstCBodyTintWnd_x                                        0xDCA328
#define pinstCBookWnd_x                                            0xDCA384
#define pinstCBreathWnd_x                                          0xDCA468
#define pinstCBuffWindowNORMAL_x                                   0xDCA3A4
#define pinstCBuffWindowSHORT_x                                    0xDCA3AC
#define pinstCBugReportWnd_x                                       0xDCA464
#define pinstCButtonWnd_x                                          0x16BBEA0
#define pinstCCastingWnd_x                                         0xDCA454
#define pinstCCastSpellWnd_x                                       0xDCA2DC
//#define pinstCCharacterCreationWnd_x                               0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDCA46C
#define pinstCChatWindowManager_x                                  0x103BC80
#define pinstCClaimWnd_x                                           0x103BDD8
#define pinstCColorPickerWnd_x                                     0xDC9C14
#define pinstCCombatAbilityWnd_x                                   0xDCA340
#define pinstCCombatSkillsSelectWnd_x                              0xDC9E38
#define pinstCCompassWnd_x                                         0xDCA314
#define pinstCConfirmationDialog_x                                 0x1040CD8
#define pinstCContainerMgr_x                                       0xDCA458
#define pinstCContextMenuManager_x                                 0x16BBBE8
#define pinstCCursorAttachment_x                                   0xDCA444
#define pinstCDistillerInfo_x                                      0x103F6E4
#define pinstCDynamicZoneWnd_x                                     0x103C3A0
#define pinstCEditLabelWnd_x                                       0xDCA394
#define pinstCEQMainWnd_x                                          0x103C5E8
#define pinstCEventCalendarWnd_x                                   0xDC9BFC
#define pinstCExtendedTargetWnd_x                                  0xDCA330
#define pinstCFacePick_x                                           0xDC9C0C
#define pinstCFactionWnd_x                                         0xDCA450
#define pinstCFellowshipWnd_x                                      0x103C7E8
#define pinstCFileSelectionWnd_x                                   0xDC9C24
#define pinstCFindItemWnd_x                                        0xDCA390
#define pinstCFindLocationWnd_x                                    0x103C940
#define pinstCFriendsWnd_x                                         0xDC9E4C
#define pinstCGemsGameWnd_x                                        0xDCA370
#define pinstCGiveWnd_x                                            0xDCA398
#define pinstCGroupSearchFiltersWnd_x                              0xDCA358
#define pinstCGroupSearchWnd_x                                     0x103CD38
#define pinstCGroupWnd_x                                           0x103CDE8
#define pinstCGuildBankWnd_x                                       0xE8CC1C
#define pinstCGuildCreationWnd_x                                   0x103CF48
#define pinstCGuildMgmtWnd_x                                       0x103CFF8
#define pinstCharacterCreation_x                                   0xDCA348
#define pinstCHelpWnd_x                                            0xDCA30C
#define pinstCHeritageSelectionWnd_x                               0xDC9C20
#define pinstCHotButtonWnd_x                                       0x103F150
#define pinstCHotButtonWnd1_x                                      0x103F150
#define pinstCHotButtonWnd2_x                                      0x103F154
#define pinstCHotButtonWnd3_x                                      0x103F158
#define pinstCHotButtonWnd4_x                                      0x103F15C
#define pinstCIconSelectionWnd_x                                   0xDCA41C
#define pinstCInspectWnd_x                                         0xDCA434
#define pinstCInventoryWnd_x                                       0xDCA368
#define pinstCInvSlotMgr_x                                         0xDCA3E8
#define pinstCItemDisplayManager_x                                 0x103F6E0
#define pinstCItemExpTransferWnd_x                                 0x103F814
#define pinstCItemOverflowWnd_x                                    0xDCA2D4
#define pinstCJournalCatWnd_x                                      0xDC9E44
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDC9C00
#define pinstCKeyRingWnd_x                                         0xDCA3BC
#define pinstCLargeDialogWnd_x                                     0x1041958
#define pinstCLayoutCopyWnd_x                                      0x103FB60
#define pinstCLFGuildWnd_x                                         0x103FC10
#define pinstCLoadskinWnd_x                                        0xDCA380
#define pinstCLootFiltersCopyWnd_x                                 0xC999D8
#define pinstCLootFiltersWnd_x                                     0xDCA388
#define pinstCLootSettingsWnd_x                                    0xDCA3A8
#define pinstCLootWnd_x                                            0xDC9BF0
#define pinstCMailAddressBookWnd_x                                 0xDCA404
#define pinstCMailCompositionWnd_x                                 0xDCA3D8
#define pinstCMailIgnoreListWnd_x                                  0xDCA408
#define pinstCMailWnd_x                                            0xDCA3B4
#define pinstCManageLootWnd_x                                      0xDCB288
#define pinstCMapToolbarWnd_x                                      0xDCA374
#define pinstCMapViewWnd_x                                         0xDCA360
#define pinstCMarketplaceWnd_x                                     0xDC9C08
#define pinstCMerchantWnd_x                                        0xDC9E40
#define pinstCMIZoneSelectWnd_x                                    0x1040448
#define pinstCMusicPlayerWnd_x                                     0xDCA3C0
#define pinstCNameChangeMercWnd_x                                  0xDCA31C
#define pinstCNameChangePetWnd_x                                   0xDCA2F8
#define pinstCNameChangeWnd_x                                      0xDC9BE0
#define pinstCNoteWnd_x                                            0xDCA2E0
#define pinstCObjectPreviewWnd_x                                   0xDC9E30
#define pinstCOptionsWnd_x                                         0xDCA378
#define pinstCPetInfoWnd_x                                         0xDCA3DC
#define pinstCPetitionQWnd_x                                       0xDC9E50
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDCA324
#define pinstCPlayerWnd_x                                          0xDCA38C
#define pinstCPopupWndManager_x                                    0x1040CD8
#define pinstCProgressionSelectionWnd_x                            0x1040D88
#define pinstCPurchaseGroupWnd_x                                   0xDC9E64
#define pinstCPurchaseWnd_x                                        0xDC9E3C
#define pinstCPvPLeaderboardWnd_x                                  0x1040E38
#define pinstCPvPStatsWnd_x                                        0x1040EE8
#define pinstCQuantityWnd_x                                        0xDCA42C
#define pinstCRaceChangeWnd_x                                      0xDC9C10
#define pinstCRaidOptionsWnd_x                                     0xDCA35C
#define pinstCRaidWnd_x                                            0xDCA438
#define pinstCRealEstateItemsWnd_x                                 0xDCA460
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDC9BF8
#define pinstCRealEstateManageWnd_x                                0xDCA3B8
#define pinstCRealEstateNeighborhoodWnd_x                          0xDCA3D0
#define pinstCRealEstatePlotSearchWnd_x                            0xDCA3F8
#define pinstCRealEstatePurchaseWnd_x                              0xDCA43C
#define pinstCRespawnWnd_x                                         0xDCA34C
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDCA334
#define pinstCSendMoneyWnd_x                                       0xDCA3B0
#define pinstCServerListWnd_x                                      0xDCA3EC
#define pinstCSkillsSelectWnd_x                                    0xDC9C18
#define pinstCSkillsWnd_x                                          0xDC9BF4
#define pinstCSocialEditWnd_x                                      0xDCA448
#define pinstCSocialWnd_x                                          0xDCA338
#define pinstCSpellBookWnd_x                                       0xDCA32C
#define pinstCStoryWnd_x                                           0xDCA2EC
#define pinstCTargetOfTargetWnd_x                                  0x1042D18
#define pinstCTargetWnd_x                                          0xDCA3CC
#define pinstCTaskOverlayWnd_x                                     0xDCA400
#define pinstCTaskSelectWnd_x                                      0x1042E70
#define pinstCTaskManager_x                                        0xC9A1D8
#define pinstCTaskTemplateSelectWnd_x                              0x1042F20
#define pinstCTaskWnd_x                                            0x1042FD0
#define pinstCTextEntryWnd_x                                       0xDCA318
#define pinstCTextOverlay_x                                        0xC7DC18
#define pinstCTimeLeftWnd_x                                        0xDC9E28
#define pinstCTipWndCONTEXT_x                                      0x10431D4
#define pinstCTipWndOFDAY_x                                        0x10431D0
#define pinstCTitleWnd_x                                           0x1043280
#define pinstCTrackingWnd_x                                        0xDCA3E4
#define pinstCTradeskillWnd_x                                      0x10433E8
#define pinstCTradeWnd_x                                           0xDCA320
#define pinstCTrainWnd_x                                           0xDCA430
#define pinstCTributeBenefitWnd_x                                  0x10435E8
#define pinstCTributeMasterWnd_x                                   0x1043698
#define pinstCTributeTrophyWnd_x                                   0x1043748
#define pinstCVideoModesWnd_x                                      0xDC9BD8
#define pinstCVoiceMacroWnd_x                                      0xF2D820
#define pinstCVoteResultsWnd_x                                     0xDCA2D8
#define pinstCVoteWnd_x                                            0xDC9E48
#define pinstCWebManager_x                                         0xF2D984
#define pinstCZoneGuideWnd_x                                       0xDCA3C4
#define pinstCZonePathWnd_x                                        0xDCA3D4

#define pinstEQSuiteTextureLoader_x                                0xC68720
#define pinstItemIconCache_x                                       0x103C5A0
#define pinstLootFiltersManager_x                                  0xC99A88
#define pinstRewardSelectionWnd_x                                  0x1041630

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC19124
#define __CastRay_x                                                0x59B9E0
#define __CastRay2_x                                               0x59BA30
#define __ConvertItemTags_x                                        0x5B70A0
#define __CrashHandler_x                                           0x84EFA0
#define __EQGetTime_x                                              0x8EDAA0
#define __ExecuteCmd_x                                             0x5942E0
#define __FixHeading_x                                             0x97E110
#define __GameLoop_x                                               0x6A7B30
#define __get_bearing_x                                            0x59B530
#define __get_melee_range_x                                        0x59BC20
#define __GetAnimationCache_x                                      0x70C640
#define __GetGaugeValueFromEQ_x                                    0x800B10
#define __GetLabelFromEQ_x                                         0x802290
#define __GetXTargetType_x                                         0x97FB70
#define __HandleMouseWheel_x                                       0x6A87E0
#define __HeadingDiff_x                                            0x97E180
#define __HelpPath_x                                               0xF2ACC4
#define __LoadFrontEnd_x                                           0x6A4610
#define __NewUIINI_x                                               0x8007E0
#define __pCrashHandler_x                                          0x1060B38
#define __ProcessGameEvents_x                                      0x5FACB0
#define __ProcessMouseEvent_x                                      0x5FA470
#define __SaveColors_x                                             0x5450A0
#define __STMLToText_x                                             0x921120
#define __ToggleKeyRingItem_x                                      0x508190
#define CrashDetected_x                                            0x6A6080
#define DrawNetStatus_x                                            0x626B70
#define Expansion_HoT_x                                            0xE8CC24
#define Teleport_Table_Size_x                                      0xE7DF98
#define Teleport_Table_x                                           0xE7BD70
#define Util__FastTime_x                                           0x8ED660
#define wwsCrashReportCheckForUploader_x                           0x84FDB0
#define wwsCrashReportPlatformLaunchUploader_x                     0x852490

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48B8F0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x494770
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x494530

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x54CB70
#define AltAdvManager__IsAbilityReady_x                            0x54BAC0
#define AltAdvManager__GetAAById_x                                 0x54BCC0
#define AltAdvManager__CanTrainAbility_x                           0x54BD30
#define AltAdvManager__CanSeeAbility_x                             0x54C090

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C7550
#define CharacterZoneClient__HasSkill_x                            0x4D2420
#define CharacterZoneClient__MakeMeVisible_x                       0x4D3B40
#define CharacterZoneClient__IsStackBlocked_x                      0x4BBA40
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B8190
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D64F0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D65D0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D66B0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C0530
#define CharacterZoneClient__BardCastBard_x                        0x4C31A0
#define CharacterZoneClient__GetMaxEffects_x                       0x4B8260
#define CharacterZoneClient__GetEffect_x                           0x4B80D0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C1530
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C1600
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C1650
#define CharacterZoneClient__CalcAffectChange_x                    0x4C17A0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C1970
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4AFF40
#define CharacterZoneClient__FindItemByGuid_x                      0x4D4AB0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D4520

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6CE310
#define CBankWnd__WndNotification_x                                0x6CE0F0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6DBB10

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x609420
#define CButtonWnd__CButtonWnd_x                                   0x91D520

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6FB820
#define CChatManager__InitContextMenu_x                            0x6F4CD0
#define CChatManager__FreeChatWindow_x                             0x6FA3F0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E5A30
#define CChatManager__SetLockedActiveChatWindow_x                  0x6FB4A0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x931B00
#define CContextMenu__dCContextMenu_x                              0x931D30
#define CContextMenu__AddMenuItem_x                                0x931D40
#define CContextMenu__RemoveMenuItem_x                             0x932050
#define CContextMenu__RemoveAllMenuItems_x                         0x932070
#define CContextMenu__CheckMenuItem_x                              0x9320F0
#define CContextMenu__SetMenuItem_x                                0x931F70
#define CContextMenu__AddSeparator_x                               0x931ED0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x932690
#define CContextMenuManager__RemoveMenu_x                          0x932700
#define CContextMenuManager__PopupMenu_x                           0x9327C0
#define CContextMenuManager__Flush_x                               0x932630
#define CContextMenuManager__GetMenu_x                             0x496930
#define CContextMenuManager__CreateDefaultMenu_x                   0x706E20

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8CE670
#define CChatService__GetFriendName_x                              0x8CE680

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6FC080
#define CChatWindow__Clear_x                                       0x6FD310
#define CChatWindow__WndNotification_x                             0x6FDA30

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x92EFA0
#define CComboWnd__Draw_x                                          0x92E4A0
#define CComboWnd__GetCurChoice_x                                  0x92EDE0
#define CComboWnd__GetListRect_x                                   0x92E950
#define CComboWnd__GetTextRect_x                                   0x92F010
#define CComboWnd__InsertChoice_x                                  0x92EAE0
#define CComboWnd__SetColors_x                                     0x92EAB0
#define CComboWnd__SetChoice_x                                     0x92EDB0
#define CComboWnd__GetItemCount_x                                  0x92EDF0
#define CComboWnd__GetCurChoiceText_x                              0x92EE30

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x704810
#define CContainerWnd__vftable_x                                   0xADD688
#define CContainerWnd__SetContainer_x                              0x705D80

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x544E60
#define CDisplay__GetClickedActor_x                                0x537E00
#define CDisplay__GetUserDefinedColor_x                            0x5304E0
#define CDisplay__GetWorldFilePath_x                               0x539850
#define CDisplay__is3dON_x                                         0x534AD0
#define CDisplay__ReloadUI_x                                       0x53EF70
#define CDisplay__WriteTextHD2_x                                   0x5348B0
#define CDisplay__TrueDistance_x                                   0x53B4B0
#define CDisplay__SetViewActor_x                                   0x537750
#define CDisplay__GetFloorHeight_x                                 0x534B90
#define CDisplay__SetRenderWindow_x                                0x5334C0
#define CDisplay__ToggleScreenshotMode_x                           0x537220

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x9518C0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x936200
#define CEditWnd__GetCharIndexPt_x                                 0x937100
#define CEditWnd__GetDisplayString_x                               0x936FA0
#define CEditWnd__GetHorzOffset_x                                  0x935830
#define CEditWnd__GetLineForPrintableChar_x                        0x938300
#define CEditWnd__GetSelStartPt_x                                  0x9373B0
#define CEditWnd__GetSTMLSafeText_x                                0x936DC0
#define CEditWnd__PointFromPrintableChar_x                         0x937F30
#define CEditWnd__SelectableCharFromPoint_x                        0x9380A0
#define CEditWnd__SetEditable_x                                    0x937480

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5E8DE0
#define CEverQuest__ClickedPlayer_x                                0x5DB020
#define CEverQuest__CreateTargetIndicator_x                        0x5F7F60
#define CEverQuest__DeleteTargetIndicator_x                        0x5F7FF0
#define CEverQuest__DoTellWindow_x                                 0x4E5B60
#define CEverQuest__OutputTextToLog_x                              0x4E5D90
#define CEverQuest__DropHeldItemOnGround_x                         0x5D0060
#define CEverQuest__dsp_chat_x                                     0x4E6120
#define CEverQuest__trimName_x                                     0x5F4240
#define CEverQuest__Emote_x                                        0x5E95F0
#define CEverQuest__EnterZone_x                                    0x5E36A0
#define CEverQuest__GetBodyTypeDesc_x                              0x5EDAE0
#define CEverQuest__GetClassDesc_x                                 0x5EE120
#define CEverQuest__GetClassThreeLetterCode_x                      0x5EE720
#define CEverQuest__GetDeityDesc_x                                 0x5F68B0
#define CEverQuest__GetLangDesc_x                                  0x5EE8E0
#define CEverQuest__GetRaceDesc_x                                  0x5EE100
#define CEverQuest__InterpretCmd_x                                 0x5F6E80
#define CEverQuest__LeftClickedOnPlayer_x                          0x5D4250
#define CEverQuest__LMouseUp_x                                     0x5D25D0
#define CEverQuest__RightClickedOnPlayer_x                         0x5D4B30
#define CEverQuest__RMouseUp_x                                     0x5D3560
#define CEverQuest__SetGameState_x                                 0x5CFDF0
#define CEverQuest__UPCNotificationFlush_x                         0x5F4140
#define CEverQuest__IssuePetCommand_x                              0x5EFCE0
#define CEverQuest__ReportSuccessfulHit_x                          0x5EA9F0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7166C0
#define CGaugeWnd__CalcLinesFillRect_x                             0x716720
#define CGaugeWnd__Draw_x                                          0x715DB0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ACCD0
#define CGuild__GetGuildName_x                                     0x4ABDB0
#define CGuild__GetGuildIndex_x                                    0x4AC140

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x731A60

//CHotButton
#define CHotButton__SetButtonSize_x                                0x6097E0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x73E900
#define CInvSlotMgr__MoveItem_x                                    0x73D620
#define CInvSlotMgr__SelectSlot_x                                  0x73E9D0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x73BED0
#define CInvSlot__SliderComplete_x                                 0x739C30
#define CInvSlot__GetItemBase_x                                    0x7395B0
#define CInvSlot__UpdateItem_x                                     0x739720

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x740410
#define CInvSlotWnd__CInvSlotWnd_x                                 0x73F5C0
#define CInvSlotWnd__HandleLButtonUp_x                             0x73FF90

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7FCD70
#define CItemDisplayWnd__UpdateStrings_x                           0x74E820
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x748610
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x748B20
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x74EE30
#define CItemDisplayWnd__AboutToShow_x                             0x74E470
#define CItemDisplayWnd__WndNotification_x                         0x750330
#define CItemDisplayWnd__RequestConvertItem_x                      0x74FEB0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x74D4D0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x74E290

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8345F0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x754420

// CLabel 
#define CLabel__Draw_x                                             0x759EC0

// CListWnd
#define CListWnd__CListWnd_x                                       0x907990
#define CListWnd__dCListWnd_x                                      0x907CA0
#define CListWnd__AddColumn_x                                      0x90BF90
#define CListWnd__AddColumn1_x                                     0x90BFE0
#define CListWnd__AddLine_x                                        0x90C370
#define CListWnd__AddString_x                                      0x90C170
#define CListWnd__CalculateFirstVisibleLine_x                      0x90BD50
#define CListWnd__CalculateVSBRange_x                              0x90BB50
#define CListWnd__ClearSel_x                                       0x90CB50
#define CListWnd__ClearAllSel_x                                    0x90CBB0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x90D5D0
#define CListWnd__Compare_x                                        0x90B490
#define CListWnd__Draw_x                                           0x907DA0
#define CListWnd__DrawColumnSeparators_x                           0x90A570
#define CListWnd__DrawHeader_x                                     0x90A9D0
#define CListWnd__DrawItem_x                                       0x90ADD0
#define CListWnd__DrawLine_x                                       0x90A6D0
#define CListWnd__DrawSeparator_x                                  0x90A610
#define CListWnd__EnableLine_x                                     0x909E50
#define CListWnd__EnsureVisible_x                                  0x90D4F0
#define CListWnd__ExtendSel_x                                      0x90CA80
#define CListWnd__GetColumnTooltip_x                               0x909990
#define CListWnd__GetColumnMinWidth_x                              0x909A00
#define CListWnd__GetColumnWidth_x                                 0x909900
#define CListWnd__GetCurSel_x                                      0x909290
#define CListWnd__GetItemAtPoint_x                                 0x90A0C0
#define CListWnd__GetItemAtPoint1_x                                0x90A130
#define CListWnd__GetItemData_x                                    0x909310
#define CListWnd__GetItemHeight_x                                  0x9096D0
#define CListWnd__GetItemIcon_x                                    0x9094A0
#define CListWnd__GetItemRect_x                                    0x909F40
#define CListWnd__GetItemText_x                                    0x909350
#define CListWnd__GetSelList_x                                     0x90CC00
#define CListWnd__GetSeparatorRect_x                               0x90A370
#define CListWnd__InsertLine_x                                     0x90C760
#define CListWnd__RemoveLine_x                                     0x90C8B0
#define CListWnd__SetColors_x                                      0x90BB20
#define CListWnd__SetColumnJustification_x                         0x90B850
#define CListWnd__SetColumnWidth_x                                 0x90B770
#define CListWnd__SetCurSel_x                                      0x90C9C0
#define CListWnd__SetItemColor_x                                   0x90D1A0
#define CListWnd__SetItemData_x                                    0x90D160
#define CListWnd__SetItemText_x                                    0x90CD70
#define CListWnd__ShiftColumnSeparator_x                           0x90B910
#define CListWnd__Sort_x                                           0x90B610
#define CListWnd__ToggleSel_x                                      0x90C9F0
#define CListWnd__SetColumnsSizable_x                              0x90B9B0
#define CListWnd__SetItemWnd_x                                     0x90D020
#define CListWnd__GetItemWnd_x                                     0x9094F0
#define CListWnd__SetItemIcon_x                                    0x90CDF0
#define CListWnd__CalculateCustomWindowPositions_x                 0x90BE50

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x76F580
#define CMapViewWnd__GetWorldCoordinates_x                         0x76DC90
#define CMapViewWnd__HandleLButtonDown_x                           0x76ACF0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x792660
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x792F40
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x793470
#define CMerchantWnd__SelectRecoverySlot_x                         0x7963E0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7911C0
#define CMerchantWnd__SelectBuySellSlot_x                          0x79BFB0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x792280

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89C650
#define CPacketScrambler__hton_x                                   0x89C640

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x9266B0
#define CSidlManager__FindScreenPieceTemplate_x                    0x926AC0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9268B0
#define CSidlManager__CreateLabel_x                                0x7F4210
#define CSidlManager__CreateXWndFromTemplate_x                     0x929A60
#define CSidlManager__CreateXWndFromTemplate1_x                    0x929C30
#define CSidlManager__CreateXWnd_x                                 0x7F4140
#define CSidlManager__CreateHotButtonWnd_x                         0x7F4700

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x923240
#define CSidlScreenWnd__CalculateVSBRange_x                        0x923140
#define CSidlScreenWnd__ConvertToRes_x                             0x948880
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x922BE0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x9228D0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x9229A0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x922A70
#define CSidlScreenWnd__DrawSidlPiece_x                            0x9236C0
#define CSidlScreenWnd__EnableIniStorage_x                         0x923B90
#define CSidlScreenWnd__GetSidlPiece_x                             0x9238B0
#define CSidlScreenWnd__Init1_x                                    0x9224E0
#define CSidlScreenWnd__LoadIniInfo_x                              0x923BE0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x924720
#define CSidlScreenWnd__LoadSidlScreen_x                           0x921900
#define CSidlScreenWnd__StoreIniInfo_x                             0x9242A0
#define CSidlScreenWnd__StoreIniVis_x                              0x924600
#define CSidlScreenWnd__WndNotification_x                          0x9235D0
#define CSidlScreenWnd__GetChildItem_x                             0x923B10
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9133C0
#define CSidlScreenWnd__m_layoutCopy_x                             0x16BBAB8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x66DB00
#define CSkillMgr__GetSkillCap_x                                   0x66DCE0
#define CSkillMgr__GetNameToken_x                                  0x66D290
#define CSkillMgr__IsActivatedSkill_x                              0x66D3D0
#define CSkillMgr__IsCombatSkill_x                                 0x66D310

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x933490
#define CSliderWnd__SetValue_x                                     0x933300
#define CSliderWnd__SetNumTicks_x                                  0x933360

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7FA290

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x93BCD0
#define CStmlWnd__CalculateHSBRange_x                              0x93CE00
#define CStmlWnd__CalculateVSBRange_x                              0x93CD70
#define CStmlWnd__CanBreakAtCharacter_x                            0x941120
#define CStmlWnd__FastForwardToEndOfTag_x                          0x941DB0
#define CStmlWnd__ForceParseNow_x                                  0x93C2C0
#define CStmlWnd__GetNextTagPiece_x                                0x941080
#define CStmlWnd__GetSTMLText_x                                    0x4F79A0
#define CStmlWnd__GetVisibleText_x                                 0x93C2E0
#define CStmlWnd__InitializeWindowVariables_x                      0x941C00
#define CStmlWnd__MakeStmlColorTag_x                               0x93B3B0
#define CStmlWnd__MakeWndNotificationTag_x                         0x93B420
#define CStmlWnd__SetSTMLText_x                                    0x93A460
#define CStmlWnd__StripFirstSTMLLines_x                            0x942E80
#define CStmlWnd__UpdateHistoryString_x                            0x941FC0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x939550
#define CTabWnd__DrawCurrentPage_x                                 0x939C30
#define CTabWnd__DrawTab_x                                         0x939950
#define CTabWnd__GetCurrentPage_x                                  0x938D60
#define CTabWnd__GetPageInnerRect_x                                0x938FA0
#define CTabWnd__GetTabInnerRect_x                                 0x938EE0
#define CTabWnd__GetTabRect_x                                      0x938D90
#define CTabWnd__InsertPage_x                                      0x9391B0
#define CTabWnd__SetPage_x                                         0x939020
#define CTabWnd__SetPageRect_x                                     0x939490
#define CTabWnd__UpdatePage_x                                      0x939810
#define CTabWnd__GetPageFromTabIndex_x                             0x939890
#define CTabWnd__GetCurrentTabIndex_x                              0x938D50

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x754800
#define CPageWnd__SetTabText_x                                     0x9388B0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A6940

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x910250
#define CTextureFont__GetTextExtent_x                              0x910410

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6A1590
#define CHtmlComponentWnd__ValidateUri_x                           0x733460
#define CHtmlWnd__SetClientCallbacks_x                             0x60E780
#define CHtmlWnd__AddObserver_x                                    0x60E7A0
#define CHtmlWnd__RemoveObserver_x                                 0x60E800
#define Window__getProgress_x                                      0x84CC00
#define Window__getStatus_x                                        0x84CC20
#define Window__getURI_x                                           0x84CC30

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x94E2F0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8FD660

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4ADF70
#define CXStr__CXStr1_x                                            0x906080
#define CXStr__CXStr3_x                                            0x8E9B90
#define CXStr__dCXStr_x                                            0x4732D0
#define CXStr__operator_equal_x                                    0x8E9DC0
#define CXStr__operator_equal1_x                                   0x8E9E00
#define CXStr__operator_plus_equal1_x                              0x8EA890
#define CXStr__SetString_x                                         0x8EC780

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x931720
#define CXWnd__BringToTop_x                                        0x916B30
#define CXWnd__Center_x                                            0x9166B0
#define CXWnd__ClrFocus_x                                          0x9164E0
#define CXWnd__Destroy_x                                           0x916590
#define CXWnd__DoAllDrawing_x                                      0x912B60
#define CXWnd__DrawChildren_x                                      0x912B30
#define CXWnd__DrawColoredRect_x                                   0x912FB0
#define CXWnd__DrawTooltip_x                                       0x911680
#define CXWnd__DrawTooltipAtPoint_x                                0x911740
#define CXWnd__GetBorderFrame_x                                    0x912E10
#define CXWnd__GetChildWndAt_x                                     0x916BD0
#define CXWnd__GetClientClipRect_x                                 0x914DC0
#define CXWnd__GetScreenClipRect_x                                 0x914E70
#define CXWnd__GetScreenRect_x                                     0x915020
#define CXWnd__GetTooltipRect_x                                    0x913000
#define CXWnd__GetWindowTextA_x                                    0x4980A0
#define CXWnd__IsActive_x                                          0x919A10
#define CXWnd__IsDescendantOf_x                                    0x915A30
#define CXWnd__IsReallyVisible_x                                   0x915A60
#define CXWnd__IsType_x                                            0x917220
#define CXWnd__Move_x                                              0x915AE0
#define CXWnd__Move1_x                                             0x915B90
#define CXWnd__ProcessTransition_x                                 0x916660
#define CXWnd__Refade_x                                            0x915E60
#define CXWnd__Resize_x                                            0x916130
#define CXWnd__Right_x                                             0x9168F0
#define CXWnd__SetFocus_x                                          0x9164A0
#define CXWnd__SetFont_x                                           0x916510
#define CXWnd__SetKeyTooltip_x                                     0x917040
#define CXWnd__SetMouseOver_x                                      0x913F40
#define CXWnd__StartFade_x                                         0x915900
#define CXWnd__GetChildItem_x                                      0x916D30
#define CXWnd__SetParent_x                                         0x9157C0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x949910

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x919A50
#define CXWndManager__DrawWindows_x                                0x919A70
#define CXWndManager__GetKeyboardFlags_x                           0x91C1C0
#define CXWndManager__HandleKeyboardMsg_x                          0x91BDD0
#define CXWndManager__RemoveWnd_x                                  0x91C410
#define CXWndManager__RemovePendingDeletionWnd_x                   0x91C960

// CDBStr
#define CDBStr__GetString_x                                        0x52F4A0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B9170
#define EQ_Character__Cur_HP_x                                     0x4CF400
#define EQ_Character__Cur_Mana_x                                   0x4D6BB0
#define EQ_Character__GetCastingTimeModifier_x                     0x4BC090
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AFB80
#define EQ_Character__GetFocusRangeModifier_x                      0x4AFCD0
#define EQ_Character__GetHPRegen_x                                 0x4DCB30
#define EQ_Character__GetEnduranceRegen_x                          0x4DD140
#define EQ_Character__GetManaRegen_x                               0x4DD580
#define EQ_Character__Max_Endurance_x                              0x634540
#define EQ_Character__Max_HP_x                                     0x4CF230
#define EQ_Character__Max_Mana_x                                   0x634340
#define EQ_Character__doCombatAbility_x                            0x636A00
#define EQ_Character__UseSkill_x                                   0x4DF370
#define EQ_Character__GetConLevel_x                                0x62DA80
#define EQ_Character__IsExpansionFlag_x                            0x592A80
#define EQ_Character__TotalEffect_x                                0x4C2700
#define EQ_Character__GetPCSpellAffect_x                           0x4BCC80
#define EQ_Character__SpellDuration_x                              0x4BC7B0
#define EQ_Character__GetAdjustedSkill_x                           0x4D21E0
#define EQ_Character__GetBaseSkill_x                               0x4D3180
#define EQ_Character__CanUseItem_x                                 0x4D6EC0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BB5B0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x64AA00

//PcClient
#define PcClient__PcClient_x                                       0x62B1B0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6D90
#define CCharacterListWnd__EnterWorld_x                            0x4B67D0
#define CCharacterListWnd__Quit_x                                  0x4B64E0
#define CCharacterListWnd__UpdateList_x                            0x4B6960

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x60F9B0
#define EQ_Item__CreateItemTagString_x                             0x895EE0
#define EQ_Item__IsStackable_x                                     0x89A990
#define EQ_Item__GetImageNum_x                                     0x897940
#define EQ_Item__CreateItemClient_x                                0x60EB80
#define EQ_Item__GetItemValue_x                                    0x898BB0
#define EQ_Item__ValueSellMerchant_x                               0x89C1E0
#define EQ_Item__IsKeyRingItem_x                                   0x89A2E0
#define EQ_Item__CanGoInBag_x                                      0x60FAD0
#define EQ_Item__IsEmpty_x                                         0x899E10
#define EQ_Item__GetMaxItemCount_x                                 0x898F80
#define EQ_Item__GetHeldItem_x                                     0x897810
#define EQ_Item__GetAugmentFitBySlot_x                             0x895820

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x54D8A0
#define EQ_LoadingS__Array_x                                       0xBF0600

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x634EA0
#define EQ_PC__GetAlternateAbilityId_x                             0x8A5260
#define EQ_PC__GetCombatAbility_x                                  0x8A58D0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A5940
#define EQ_PC__GetItemRecastTimer_x                                0x636F80
#define EQ_PC__HasLoreItem_x                                       0x62E240
#define EQ_PC__AlertInventoryChanged_x                             0x62D3B0
#define EQ_PC__GetPcZoneClient_x                                   0x6591F0
#define EQ_PC__RemoveMyAffect_x                                    0x63A1B0
#define EQ_PC__GetKeyRingItems_x                                   0x8A61E0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A5F60
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A64D0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x598FB0
#define EQItemList__add_object_x                                   0x5C57E0
#define EQItemList__add_item_x                                     0x5995C0
#define EQItemList__delete_item_x                                  0x599610
#define EQItemList__FreeItemList_x                                 0x599510

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x52CB30

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x64C280
#define EQPlayer__dEQPlayer_x                                      0x63F840
#define EQPlayer__DoAttack_x                                       0x653EC0
#define EQPlayer__EQPlayer_x                                       0x63FEF0
#define EQPlayer__SetNameSpriteState_x                             0x644180
#define EQPlayer__SetNameSpriteTint_x                              0x645040
#define PlayerBase__HasProperty_j_x                                0x97C4E0
#define EQPlayer__IsTargetable_x                                   0x97C980
#define EQPlayer__CanSee_x                                         0x97C7E0
#define EQPlayer__CanSee1_x                                        0x97C8B0
#define PlayerBase__GetVisibilityLineSegment_x                     0x97C5A0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x656CA0
#define PlayerZoneClient__GetLevel_x                               0x659230
#define PlayerZoneClient__IsValidTeleport_x                        0x5C6930
#define PlayerZoneClient__LegalPlayerRace_x                        0x546CB0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x64F000
#define EQPlayerManager__GetSpawnByName_x                          0x64F020
#define EQPlayerManager__GetPlayerFromPartialName_x                0x64F0B0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x613250
#define KeypressHandler__AttachKeyToEqCommand_x                    0x613290
#define KeypressHandler__ClearCommandStateArray_x                  0x6146A0
#define KeypressHandler__HandleKeyDown_x                           0x6146C0
#define KeypressHandler__HandleKeyUp_x                             0x614760
#define KeypressHandler__SaveKeymapping_x                          0x614B40

// MapViewMap 
#define MapViewMap__Clear_x                                        0x76B410
#define MapViewMap__SaveEx_x                                       0x76E7B0
#define MapViewMap__SetZoom_x                                      0x772E70

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B94A0

// StringTable 
#define StringTable__getString_x                                   0x8B4520

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x639E20
#define PcZoneClient__RemovePetEffect_x                            0x63A450
#define PcZoneClient__HasAlternateAbility_x                        0x634180
#define PcZoneClient__GetCurrentMod_x                              0x4E2450
#define PcZoneClient__GetModCap_x                                  0x4E2350
#define PcZoneClient__CanEquipItem_x                               0x634830
#define PcZoneClient__GetItemByID_x                                0x637400
#define PcZoneClient__GetItemByItemClass_x                         0x637550
#define PcZoneClient__RemoveBuffEffect_x                           0x63A470
#define PcZoneClient__BandolierSwap_x                              0x635460
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x636F20

//Doors
#define EQSwitch__UseSwitch_x                                      0x5CB500

//IconCache
#define IconCache__GetIcon_x                                       0x70BED0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x7039B0
#define CContainerMgr__CloseContainer_x                            0x703C80
#define CContainerMgr__OpenExperimentContainer_x                   0x704700

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7C6730

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x607BF0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x761800
#define CLootWnd__RequestLootSlot_x                                0x760BC0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x565E80
#define EQ_Spell__SpellAffects_x                                   0x5662F0
#define EQ_Spell__SpellAffectBase_x                                0x5660B0
#define EQ_Spell__IsStackable_x                                    0x4C6E70
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C6CF0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B4130
#define EQ_Spell__IsSPAStacking_x                                  0x567120
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x566640
#define EQ_Spell__IsNoRemove_x                                     0x4C6E50
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x567130
#define __IsResEffectSpell_x                                       0x4C6290

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AA9E0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C3A60

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x80C080
#define CTargetWnd__WndNotification_x                              0x80B910
#define CTargetWnd__RefreshTargetBuffs_x                           0x80BBE0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x80AA70

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x810740

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x52A4C0
#define CTaskManager__HandleMessage_x                              0x528C10

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x561410
#define EqSoundManager__PlayScriptMp3_x                            0x561570
#define EqSoundManager__SoundAssistPlay_x                          0x671AF0
#define EqSoundManager__WaveInstancePlay_x                         0x671060

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x51E4D0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x934E70

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x555620
#define CAltAbilityData__GetMercMaxRank_x                          0x5555C0
#define CAltAbilityData__GetMaxRank_x                              0x54A970

//CTargetRing
#define CTargetRing__Cast_x                                        0x605CF0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C6CD0
#define CharacterBase__CreateItemGlobalIndex_x                     0x5046A0
#define CharacterBase__CreateItemIndex_x                           0x60DDC0
#define CharacterBase__GetItemPossession_x                         0x4F03E0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CC070
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CC0D0
#define CharacterBase__GetEffectId_x                               0x4C6C80

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6EB190
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6EB9B0

//messages
#define msg_spell_worn_off_x                                       0x58AC80
#define msg_new_text_x                                             0x57FAF0
#define __msgTokenTextParam_x                                      0x58D1A0
#define msgTokenText_x                                             0x58D3F0

//SpellManager
#define SpellManager__vftable_x                                    0xAB7C20
#define SpellManager__SpellManager_x                               0x674E20
#define Spellmanager__LoadTextSpells_x                             0x6756F0
#define SpellManager__GetSpellByGroupAndRank_x                     0x674FF0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x980460

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x504D50
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x590FF0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x6269D0
#define ItemGlobalIndex__IsValidIndex_x                            0x504DB0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C43A0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C4620

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x75A210

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x7080C0
#define CCursorAttachment__AttachToCursor1_x                       0x708100
#define CCursorAttachment__Deactivate_x                            0x7090E0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x92AA70
#define CSidlManagerBase__CreatePageWnd_x                          0x92A280
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x9264D0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x926460

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x947A80
#define CEQSuiteTextureLoader__GetTexture_x                        0x947740

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x501C40
#define CFindItemWnd__WndNotification_x                            0x502720
#define CFindItemWnd__Update_x                                     0x503290
#define CFindItemWnd__PickupSelectedItem_x                         0x5014B0

//IString
#define IString__Append_x                                          0x4F1B00

//Camera
#define CDisplay__cameraType_x                                     0xDC9C1C
#define EverQuest__Cameras_x                                       0xE8CF68

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x50A410
#define LootFiltersManager__GetItemFilterData_x                    0x509D10
#define LootFiltersManager__RemoveItemLootFilter_x                 0x509D40
#define LootFiltersManager__SetItemLootFilter_x                    0x509F60

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B4760

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9861B0
#define CResolutionHandler__GetWindowedStyle_x                     0x66C620

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x700760

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D6C40

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x720810
#define CGroupWnd__UpdateDisplay_x                                 0x71FB80

//ItemBase
#define ItemBase__IsLore_x                                         0x89A340
#define ItemBase__IsLoreEquipped_x                                 0x89A3B0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5C56D0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5C5880
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5C58E0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x661D10
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x6659C0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x4F7FA0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4E74A0
#define FactionManagerClient__HandleFactionMessage_x               0x4E7B20
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4E8140
#define FactionManagerClient__GetMaxFaction_x                      0x4E8190
#define FactionManagerClient__GetMinFaction_x                      0x4E8110

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4F03B0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x90F280

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
