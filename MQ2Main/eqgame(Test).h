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
#define __ExpectedVersionDate                                     "Mar  5 2019"
#define __ExpectedVersionTime                                     "15:08:38"
#define __ActualVersionDate_x                                      0xAD4424
#define __ActualVersionTime_x                                      0xAD4418

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x619940
#define __MemChecker1_x                                            0x8EE250
#define __MemChecker2_x                                            0x6A8A80
#define __MemChecker3_x                                            0x6A89D0
#define __MemChecker4_x                                            0x845570
#define __EncryptPad0_x                                            0xC089B0
#define __EncryptPad1_x                                            0xC66C38
#define __EncryptPad2_x                                            0xC19530
#define __EncryptPad3_x                                            0xC19130
#define __EncryptPad4_x                                            0xC574A8
#define __EncryptPad5_x                                            0xF2E5A8
#define __AC1_x                                                    0x802266
#define __AC2_x                                                    0x5D3C7F
#define __AC3_x                                                    0x5DB38F
#define __AC4_x                                                    0x5DF1D0
#define __AC5_x                                                    0x5E5440
#define __AC6_x                                                    0x5E9A06
#define __AC7_x                                                    0x5D36F0
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
#define __do_loot_x                                                0x5A0700
#define __DrawHandler_x                                            0x16BCB80
#define __GroupCount_x                                             0xE7BB82
#define __Guilds_x                                                 0xE820D0
#define __gWorld_x                                                 0xE7E454
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
#define __ScreenMode_x                                             0xDCA42C
#define __ScreenX_x                                                0xE8B864
#define __ScreenY_x                                                0xE8B860
#define __ScreenXMax_x                                             0xE8B868
#define __ScreenYMax_x                                             0xE8B86C
#define __ServerHost_x                                             0xE7E0F3
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
#define pinstCamActor_x                                            0xDCA418
#define pinstCDBStr_x                                              0xDC9B3C
#define pinstCDisplay_x                                            0xE7E45C
#define pinstCEverQuest_x                                          0x1038D40
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
#define pinstViewActor_x                                           0xDCA414
#define pinstWorldData_x                                           0xE7DE8C
#define pinstZoneAddr_x                                            0xE8BDD8
#define pinstPlayerPath_x                                          0xF2C4A0
#define pinstTargetIndicator_x                                     0xF2D258
#define pinstCTargetManager_x                                      0xF2D2F0
#define EQObject_Top_x                                             0xE7DEAC
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDCA458
#define pinstCAchievementsWnd_x                                    0xDCA44C
#define pinstCActionsWnd_x                                         0xDC9E34
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDCA2E4
#define pinstCAdvancedLootWnd_x                                    0xDC9E2C
#define pinstCAdventureLeaderboardWnd_x                            0x1039960
#define pinstCAdventureRequestWnd_x                                0x1039A10
#define pinstCAdventureStatsWnd_x                                  0x1039AC0
#define pinstCAggroMeterWnd_x                                      0xDCA344
#define pinstCAlarmWnd_x                                           0xDCA39C
#define pinstCAlertHistoryWnd_x                                    0xDCA3EC
#define pinstCAlertStackWnd_x                                      0xDCA354
#define pinstCAlertWnd_x                                           0xDCA364
#define pinstCAltStorageWnd_x                                      0x1039E20
#define pinstCAudioTriggersWindow_x                                0xC7D908
#define pinstCAuraWnd_x                                            0xDCA33C
#define pinstCAvaZoneWnd_x                                         0xDCA3F0
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
#define pinstCBuffWindowNORMAL_x                                   0xDCA3A0
#define pinstCBuffWindowSHORT_x                                    0xDCA3A8
#define pinstCBugReportWnd_x                                       0xDCA460
#define pinstCButtonWnd_x                                          0x16BBEA0
#define pinstCCastingWnd_x                                         0xDCA454
#define pinstCCastSpellWnd_x                                       0xDCA2DC
//#define pinstCCharacterCreationWnd_x                               0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDCA46C
#define pinstCChatWindowManager_x                                  0x103BC80
#define pinstCClaimWnd_x                                           0x103BDD8
#define pinstCColorPickerWnd_x                                     0xDC9C10
#define pinstCCombatAbilityWnd_x                                   0xDCA340
#define pinstCCombatSkillsSelectWnd_x                              0xDC9E38
#define pinstCCompassWnd_x                                         0xDCA314
#define pinstCConfirmationDialog_x                                 0x1040CD8
#define pinstCContainerMgr_x                                       0xDCA464
#define pinstCContextMenuManager_x                                 0x16BBBE8
#define pinstCCursorAttachment_x                                   0xDCA444
#define pinstCDistillerInfo_x                                      0x103F6E4
#define pinstCDynamicZoneWnd_x                                     0x103C3A0
#define pinstCEditLabelWnd_x                                       0xDCA390
#define pinstCEQMainWnd_x                                          0x103C5E8
#define pinstCEventCalendarWnd_x                                   0xDC9BFC
#define pinstCExtendedTargetWnd_x                                  0xDCA330
#define pinstCFacePick_x                                           0xDC9C08
#define pinstCFactionWnd_x                                         0xDCA450
#define pinstCFellowshipWnd_x                                      0x103C7E8
#define pinstCFileSelectionWnd_x                                   0xDC9C20
#define pinstCFindItemWnd_x                                        0xDCA38C
#define pinstCFindLocationWnd_x                                    0x103C940
#define pinstCFriendsWnd_x                                         0xDC9E4C
#define pinstCGemsGameWnd_x                                        0xDCA370
#define pinstCGiveWnd_x                                            0xDCA394
#define pinstCGroupSearchFiltersWnd_x                              0xDCA358
#define pinstCGroupSearchWnd_x                                     0x103CD38
#define pinstCGroupWnd_x                                           0x103CDE8
#define pinstCGuildBankWnd_x                                       0xE8CC1C
#define pinstCGuildCreationWnd_x                                   0x103CF48
#define pinstCGuildMgmtWnd_x                                       0x103CFF8
#define pinstCharacterCreation_x                                   0xDCA348
#define pinstCHelpWnd_x                                            0xDCA30C
#define pinstCHeritageSelectionWnd_x                               0xDC9C1C
#define pinstCHotButtonWnd_x                                       0x103F150
#define pinstCHotButtonWnd1_x                                      0x103F150
#define pinstCHotButtonWnd2_x                                      0x103F154
#define pinstCHotButtonWnd3_x                                      0x103F158
#define pinstCHotButtonWnd4_x                                      0x103F15C
#define pinstCIconSelectionWnd_x                                   0xDCA40C
#define pinstCInspectWnd_x                                         0xDCA424
#define pinstCInventoryWnd_x                                       0xDCA368
#define pinstCInvSlotMgr_x                                         0xDCA3F4
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
#define pinstCLootSettingsWnd_x                                    0xDCA3A4
#define pinstCLootWnd_x                                            0xDC9BE4
#define pinstCMailAddressBookWnd_x                                 0xDCA404
#define pinstCMailCompositionWnd_x                                 0xDCA3D8
#define pinstCMailIgnoreListWnd_x                                  0xDCA408
#define pinstCMailWnd_x                                            0xDCA3B4
#define pinstCManageLootWnd_x                                      0xDCB288
#define pinstCMapToolbarWnd_x                                      0xDCA374
#define pinstCMapViewWnd_x                                         0xDCA360
#define pinstCMarketplaceWnd_x                                     0xDC9C04
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
#define pinstCPlayerWnd_x                                          0xDCA398
#define pinstCPopupWndManager_x                                    0x1040CD8
#define pinstCProgressionSelectionWnd_x                            0x1040D88
#define pinstCPurchaseGroupWnd_x                                   0xDC9E64
#define pinstCPurchaseWnd_x                                        0xDC9E3C
#define pinstCPvPLeaderboardWnd_x                                  0x1040E38
#define pinstCPvPStatsWnd_x                                        0x1040EE8
#define pinstCQuantityWnd_x                                        0xDCA410
#define pinstCRaceChangeWnd_x                                      0xDC9C0C
#define pinstCRaidOptionsWnd_x                                     0xDCA35C
#define pinstCRaidWnd_x                                            0xDCA438
#define pinstCRealEstateItemsWnd_x                                 0xDCA45C
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDC9BF8
#define pinstCRealEstateManageWnd_x                                0xDCA3B8
#define pinstCRealEstateNeighborhoodWnd_x                          0xDCA3D0
#define pinstCRealEstatePlotSearchWnd_x                            0xDCA3F8
#define pinstCRealEstatePurchaseWnd_x                              0xDCA43C
#define pinstCRespawnWnd_x                                         0xDCA34C
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDCA334
#define pinstCSendMoneyWnd_x                                       0xDCA3AC
#define pinstCServerListWnd_x                                      0xDCA3E8
#define pinstCSkillsSelectWnd_x                                    0xDC9C18
#define pinstCSkillsWnd_x                                          0xDC9BE8
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
#define pinstCTrainWnd_x                                           0xDCA41C
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
#define __CastRay_x                                                0x59BC20
#define __CastRay2_x                                               0x59BC70
#define __ConvertItemTags_x                                        0x5B72E0
#define __CrashHandler_x                                           0x84EEF0
#define __EQGetTime_x                                              0x8EDD30
#define __ExecuteCmd_x                                             0x594510
#define __FixHeading_x                                             0x97DD70
#define __GameLoop_x                                               0x6A7E80
#define __get_bearing_x                                            0x59B770
#define __get_melee_range_x                                        0x59BE60
#define __GetAnimationCache_x                                      0x70C730
#define __GetGaugeValueFromEQ_x                                    0x800A70
#define __GetLabelFromEQ_x                                         0x8021F0
#define __GetXTargetType_x                                         0x97F7D0
#define __HandleMouseWheel_x                                       0x6A8B30
#define __HeadingDiff_x                                            0x97DDE0
#define __HelpPath_x                                               0xF2ACC4
#define __LoadFrontEnd_x                                           0x6A4960
#define __NewUIINI_x                                               0x800740
#define __pCrashHandler_x                                          0x1060B38
#define __ProcessGameEvents_x                                      0x5FAE00
#define __ProcessMouseEvent_x                                      0x5FA5C0
#define __SaveColors_x                                             0x5455A0
#define __STMLToText_x                                             0x9215A0
#define __ToggleKeyRingItem_x                                      0x508600
#define CrashDetected_x                                            0x6A63D0
#define DrawNetStatus_x                                            0x626E90
#define Expansion_HoT_x                                            0xE8CC24
#define Teleport_Table_Size_x                                      0xE7DF98
#define Teleport_Table_x                                           0xE7BD70
#define Util__FastTime_x                                           0x8ED8F0
#define wwsCrashReportCheckForUploader_x                           0x84FCE0
#define wwsCrashReportPlatformLaunchUploader_x                     0x8523B0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48B8F0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x494770
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x494530

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x54D190
#define AltAdvManager__IsAbilityReady_x                            0x54C0E0
#define AltAdvManager__GetAAById_x                                 0x54C2E0
#define AltAdvManager__CanTrainAbility_x                           0x54C350
#define AltAdvManager__CanSeeAbility_x                             0x54C6B0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C76A0
#define CharacterZoneClient__HasSkill_x                            0x4D2570
#define CharacterZoneClient__MakeMeVisible_x                       0x4D3C90
#define CharacterZoneClient__IsStackBlocked_x                      0x4BBA60
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B81B0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D6640
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D6720
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D6800
#define CharacterZoneClient__FindAffectSlot_x                      0x4C0550
#define CharacterZoneClient__BardCastBard_x                        0x4C31C0
#define CharacterZoneClient__GetMaxEffects_x                       0x4B8280
#define CharacterZoneClient__GetEffect_x                           0x4B80F0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C1550
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C1620
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C1670
#define CharacterZoneClient__CalcAffectChange_x                    0x4C17C0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C1990
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4AFFF0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D4C00
#define CharacterZoneClient__FindItemByRecord_x                    0x4D4670

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6CE6A0
#define CBankWnd__WndNotification_x                                0x6CE480

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6DBE20

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x609730
#define CButtonWnd__CButtonWnd_x                                   0x91D9A0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6FB940
#define CChatManager__InitContextMenu_x                            0x6F4F10
#define CChatManager__FreeChatWindow_x                             0x6FA620
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E5AC0
#define CChatManager__SetLockedActiveChatWindow_x                  0x6FB660

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x932050
#define CContextMenu__dCContextMenu_x                              0x932280
#define CContextMenu__AddMenuItem_x                                0x932290
#define CContextMenu__RemoveMenuItem_x                             0x932590
#define CContextMenu__RemoveAllMenuItems_x                         0x9325B0
#define CContextMenu__CheckMenuItem_x                              0x932630
#define CContextMenu__SetMenuItem_x                                0x9324C0
#define CContextMenu__AddSeparator_x                               0x932420

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x932BD0
#define CContextMenuManager__RemoveMenu_x                          0x932C40
#define CContextMenuManager__PopupMenu_x                           0x932D00
#define CContextMenuManager__Flush_x                               0x932B70
#define CContextMenuManager__GetMenu_x                             0x4968F0
#define CContextMenuManager__CreateDefaultMenu_x                   0x706F10

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8CE8E0
#define CChatService__GetFriendName_x                              0x8CE8F0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6FC1B0
#define CChatWindow__Clear_x                                       0x6FD380
#define CChatWindow__WndNotification_x                             0x6FDAA0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x92F4E0
#define CComboWnd__Draw_x                                          0x92E9E0
#define CComboWnd__GetCurChoice_x                                  0x92F320
#define CComboWnd__GetListRect_x                                   0x92EE90
#define CComboWnd__GetTextRect_x                                   0x92F540
#define CComboWnd__InsertChoice_x                                  0x92F020
#define CComboWnd__SetColors_x                                     0x92EFF0
#define CComboWnd__SetChoice_x                                     0x92F2F0
#define CComboWnd__GetItemCount_x                                  0x92F330
#define CComboWnd__GetCurChoiceText_x                              0x92F370

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x7048F0
#define CContainerWnd__vftable_x                                   0xADD698
#define CContainerWnd__SetContainer_x                              0x705E60

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x545360
#define CDisplay__GetClickedActor_x                                0x538300
#define CDisplay__GetUserDefinedColor_x                            0x5309E0
#define CDisplay__GetWorldFilePath_x                               0x539D50
#define CDisplay__is3dON_x                                         0x534FD0
#define CDisplay__ReloadUI_x                                       0x53F470
#define CDisplay__WriteTextHD2_x                                   0x534DB0
#define CDisplay__TrueDistance_x                                   0x53B9B0
#define CDisplay__SetViewActor_x                                   0x537C50
#define CDisplay__GetFloorHeight_x                                 0x535090
#define CDisplay__SetRenderWindow_x                                0x5339C0
#define CDisplay__ToggleScreenshotMode_x                           0x537720

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x9519E0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x936740
#define CEditWnd__GetCharIndexPt_x                                 0x937630
#define CEditWnd__GetDisplayString_x                               0x9374D0
#define CEditWnd__GetHorzOffset_x                                  0x935D70
#define CEditWnd__GetLineForPrintableChar_x                        0x938820
#define CEditWnd__GetSelStartPt_x                                  0x9378D0
#define CEditWnd__GetSTMLSafeText_x                                0x9372F0
#define CEditWnd__PointFromPrintableChar_x                         0x938450
#define CEditWnd__SelectableCharFromPoint_x                        0x9385C0
#define CEditWnd__SetEditable_x                                    0x9379A0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5E8F30
#define CEverQuest__ClickedPlayer_x                                0x5DB170
#define CEverQuest__CreateTargetIndicator_x                        0x5F80B0
#define CEverQuest__DeleteTargetIndicator_x                        0x5F8140
#define CEverQuest__DoTellWindow_x                                 0x4E5CB0
#define CEverQuest__OutputTextToLog_x                              0x4E5EE0
#define CEverQuest__DropHeldItemOnGround_x                         0x5D01B0
#define CEverQuest__dsp_chat_x                                     0x4E6270
#define CEverQuest__trimName_x                                     0x5F4390
#define CEverQuest__Emote_x                                        0x5E9740
#define CEverQuest__EnterZone_x                                    0x5E37F0
#define CEverQuest__GetBodyTypeDesc_x                              0x5EDC30
#define CEverQuest__GetClassDesc_x                                 0x5EE270
#define CEverQuest__GetClassThreeLetterCode_x                      0x5EE870
#define CEverQuest__GetDeityDesc_x                                 0x5F6A00
#define CEverQuest__GetLangDesc_x                                  0x5EEA30
#define CEverQuest__GetRaceDesc_x                                  0x5EE250
#define CEverQuest__InterpretCmd_x                                 0x5F6FD0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5D43A0
#define CEverQuest__LMouseUp_x                                     0x5D2720
#define CEverQuest__RightClickedOnPlayer_x                         0x5D4C80
#define CEverQuest__RMouseUp_x                                     0x5D36B0
#define CEverQuest__SetGameState_x                                 0x5CFF40
#define CEverQuest__UPCNotificationFlush_x                         0x5F4290
#define CEverQuest__IssuePetCommand_x                              0x5EFE30
#define CEverQuest__ReportSuccessfulHit_x                          0x5EAB40

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x716940
#define CGaugeWnd__CalcLinesFillRect_x                             0x7169A0
#define CGaugeWnd__Draw_x                                          0x716040

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ACCA0
#define CGuild__GetGuildName_x                                     0x4ABD80
#define CGuild__GetGuildIndex_x                                    0x4AC110

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x731CE0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x609AF0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x73EBA0
#define CInvSlotMgr__MoveItem_x                                    0x73D8C0
#define CInvSlotMgr__SelectSlot_x                                  0x73EC70

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x73C170
#define CInvSlot__SliderComplete_x                                 0x739ED0
#define CInvSlot__GetItemBase_x                                    0x739850
#define CInvSlot__UpdateItem_x                                     0x7399C0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7406B0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x73F860
#define CInvSlotWnd__HandleLButtonUp_x                             0x740230

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7FCCB0
#define CItemDisplayWnd__UpdateStrings_x                           0x74EAC0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x7488C0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x748DD0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x74F0D0
#define CItemDisplayWnd__AboutToShow_x                             0x74E720
#define CItemDisplayWnd__WndNotification_x                         0x7505D0
#define CItemDisplayWnd__RequestConvertItem_x                      0x750150
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x74D780
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x74E540

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8345D0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x7546B0

// CLabel 
#define CLabel__Draw_x                                             0x75A170

// CListWnd
#define CListWnd__CListWnd_x                                       0x907D40
#define CListWnd__dCListWnd_x                                      0x908050
#define CListWnd__AddColumn_x                                      0x90C350
#define CListWnd__AddColumn1_x                                     0x90C3A0
#define CListWnd__AddLine_x                                        0x90C730
#define CListWnd__AddString_x                                      0x90C530
#define CListWnd__CalculateFirstVisibleLine_x                      0x90C120
#define CListWnd__CalculateVSBRange_x                              0x90BF00
#define CListWnd__ClearSel_x                                       0x90CF10
#define CListWnd__ClearAllSel_x                                    0x90CF70
#define CListWnd__CloseAndUpdateEditWindow_x                       0x90D960
#define CListWnd__Compare_x                                        0x90B840
#define CListWnd__Draw_x                                           0x908150
#define CListWnd__DrawColumnSeparators_x                           0x90A920
#define CListWnd__DrawHeader_x                                     0x90AD90
#define CListWnd__DrawItem_x                                       0x90B180
#define CListWnd__DrawLine_x                                       0x90AA90
#define CListWnd__DrawSeparator_x                                  0x90A9C0
#define CListWnd__EnableLine_x                                     0x90A200
#define CListWnd__EnsureVisible_x                                  0x90D8A0
#define CListWnd__ExtendSel_x                                      0x90CE40
#define CListWnd__GetColumnTooltip_x                               0x909D40
#define CListWnd__GetColumnMinWidth_x                              0x909DB0
#define CListWnd__GetColumnWidth_x                                 0x909CB0
#define CListWnd__GetCurSel_x                                      0x909640
#define CListWnd__GetItemAtPoint_x                                 0x90A470
#define CListWnd__GetItemAtPoint1_x                                0x90A4E0
#define CListWnd__GetItemData_x                                    0x9096C0
#define CListWnd__GetItemHeight_x                                  0x909A80
#define CListWnd__GetItemIcon_x                                    0x909850
#define CListWnd__GetItemRect_x                                    0x90A2F0
#define CListWnd__GetItemText_x                                    0x909700
#define CListWnd__GetSelList_x                                     0x90CFC0
#define CListWnd__GetSeparatorRect_x                               0x90A720
#define CListWnd__InsertLine_x                                     0x90CB20
#define CListWnd__RemoveLine_x                                     0x90CC70
#define CListWnd__SetColors_x                                      0x90BED0
#define CListWnd__SetColumnJustification_x                         0x90BC00
#define CListWnd__SetColumnWidth_x                                 0x90BB20
#define CListWnd__SetCurSel_x                                      0x90CD80
#define CListWnd__SetItemColor_x                                   0x90D560
#define CListWnd__SetItemData_x                                    0x90D520
#define CListWnd__SetItemText_x                                    0x90D130
#define CListWnd__ShiftColumnSeparator_x                           0x90BCC0
#define CListWnd__Sort_x                                           0x90B9C0
#define CListWnd__ToggleSel_x                                      0x90CDB0
#define CListWnd__SetColumnsSizable_x                              0x90BD60
#define CListWnd__SetItemWnd_x                                     0x90D3E0
#define CListWnd__GetItemWnd_x                                     0x9098A0
#define CListWnd__SetItemIcon_x                                    0x90D1B0
#define CListWnd__CalculateCustomWindowPositions_x                 0x90C210

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x76F630
#define CMapViewWnd__GetWorldCoordinates_x                         0x76DD40
#define CMapViewWnd__HandleLButtonDown_x                           0x76ADA0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7926C0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x792FA0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7934D0
#define CMerchantWnd__SelectRecoverySlot_x                         0x796450
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x791210
#define CMerchantWnd__SelectBuySellSlot_x                          0x79C010
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7922E0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89C640
#define CPacketScrambler__hton_x                                   0x89C630

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x926B70
#define CSidlManager__FindScreenPieceTemplate_x                    0x926F80
#define CSidlManager__FindScreenPieceTemplate1_x                   0x926D70
#define CSidlManager__CreateLabel_x                                0x7F4110
#define CSidlManager__CreateXWndFromTemplate_x                     0x929F20
#define CSidlManager__CreateXWndFromTemplate1_x                    0x92A100
#define CSidlManager__CreateXWnd_x                                 0x7F4040
#define CSidlManager__CreateHotButtonWnd_x                         0x7F4600

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9236F0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9235F0
#define CSidlScreenWnd__ConvertToRes_x                             0x9488F0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x923080
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x922D70
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x922E40
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x922F10
#define CSidlScreenWnd__DrawSidlPiece_x                            0x923B80
#define CSidlScreenWnd__EnableIniStorage_x                         0x924050
#define CSidlScreenWnd__GetSidlPiece_x                             0x923D70
#define CSidlScreenWnd__Init1_x                                    0x922970
#define CSidlScreenWnd__LoadIniInfo_x                              0x9240A0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x924BE0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x921D80
#define CSidlScreenWnd__StoreIniInfo_x                             0x924760
#define CSidlScreenWnd__StoreIniVis_x                              0x924AC0
#define CSidlScreenWnd__WndNotification_x                          0x923A90
#define CSidlScreenWnd__GetChildItem_x                             0x923FD0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9137D0
#define CSidlScreenWnd__m_layoutCopy_x                             0x16BBAB8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x66DFB0
#define CSkillMgr__GetSkillCap_x                                   0x66E190
#define CSkillMgr__GetNameToken_x                                  0x66D740
#define CSkillMgr__IsActivatedSkill_x                              0x66D880
#define CSkillMgr__IsCombatSkill_x                                 0x66D7C0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9339D0
#define CSliderWnd__SetValue_x                                     0x933840
#define CSliderWnd__SetNumTicks_x                                  0x9338A0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7FA200

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x93C130
#define CStmlWnd__CalculateHSBRange_x                              0x93D200
#define CStmlWnd__CalculateVSBRange_x                              0x93D170
#define CStmlWnd__CanBreakAtCharacter_x                            0x941550
#define CStmlWnd__FastForwardToEndOfTag_x                          0x9421E0
#define CStmlWnd__ForceParseNow_x                                  0x93C6D0
#define CStmlWnd__GetNextTagPiece_x                                0x9414B0
#define CStmlWnd__GetSTMLText_x                                    0x4F7C60
#define CStmlWnd__GetVisibleText_x                                 0x93C6F0
#define CStmlWnd__InitializeWindowVariables_x                      0x942030
#define CStmlWnd__MakeStmlColorTag_x                               0x93B810
#define CStmlWnd__MakeWndNotificationTag_x                         0x93B880
#define CStmlWnd__SetSTMLText_x                                    0x93A8C0
#define CStmlWnd__StripFirstSTMLLines_x                            0x9432D0
#define CStmlWnd__UpdateHistoryString_x                            0x9423F0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x939A60
#define CTabWnd__DrawCurrentPage_x                                 0x93A140
#define CTabWnd__DrawTab_x                                         0x939E60
#define CTabWnd__GetCurrentPage_x                                  0x939260
#define CTabWnd__GetPageInnerRect_x                                0x9394A0
#define CTabWnd__GetTabInnerRect_x                                 0x9393E0
#define CTabWnd__GetTabRect_x                                      0x939290
#define CTabWnd__InsertPage_x                                      0x9396B0
#define CTabWnd__SetPage_x                                         0x939520
#define CTabWnd__SetPageRect_x                                     0x9399A0
#define CTabWnd__UpdatePage_x                                      0x939D20
#define CTabWnd__GetPageFromTabIndex_x                             0x939DA0
#define CTabWnd__GetCurrentTabIndex_x                              0x939250

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x754A80
#define CPageWnd__SetTabText_x                                     0x938DB0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A68D0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x910640
#define CTextureFont__GetTextExtent_x                              0x910800

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6A18E0
#define CHtmlComponentWnd__ValidateUri_x                           0x7336D0
#define CHtmlWnd__SetClientCallbacks_x                             0x60EAB0
#define CHtmlWnd__AddObserver_x                                    0x60EAD0
#define CHtmlWnd__RemoveObserver_x                                 0x60EB30
#define Window__getProgress_x                                      0x84CB60
#define Window__getStatus_x                                        0x84CB80
#define Window__getURI_x                                           0x84CB90

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x94E410

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8FD8B0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4AE000
#define CXStr__CXStr1_x                                            0x9BF770
#define CXStr__CXStr3_x                                            0x8E9E20
#define CXStr__dCXStr_x                                            0x473200
#define CXStr__operator_equal_x                                    0x8EA050
#define CXStr__operator_equal1_x                                   0x8EA090
#define CXStr__operator_plus_equal1_x                              0x8EAB20
#define CXStr__SetString_x                                         0x8ECA10

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x931C60
#define CXWnd__BringToTop_x                                        0x916FB0
#define CXWnd__Center_x                                            0x916B30
#define CXWnd__ClrFocus_x                                          0x916970
#define CXWnd__Destroy_x                                           0x916A10
#define CXWnd__DoAllDrawing_x                                      0x912F80
#define CXWnd__DrawChildren_x                                      0x912F50
#define CXWnd__DrawColoredRect_x                                   0x9133E0
#define CXWnd__DrawTooltip_x                                       0x911AA0
#define CXWnd__DrawTooltipAtPoint_x                                0x911B60
#define CXWnd__GetBorderFrame_x                                    0x913240
#define CXWnd__GetChildWndAt_x                                     0x917050
#define CXWnd__GetClientClipRect_x                                 0x915240
#define CXWnd__GetScreenClipRect_x                                 0x915310
#define CXWnd__GetScreenRect_x                                     0x9154B0
#define CXWnd__GetTooltipRect_x                                    0x913430
#define CXWnd__GetWindowTextA_x                                    0x497F90
#define CXWnd__IsActive_x                                          0x919F50
#define CXWnd__IsDescendantOf_x                                    0x915EB0
#define CXWnd__IsReallyVisible_x                                   0x915EE0
#define CXWnd__IsType_x                                            0x9176C0
#define CXWnd__Move_x                                              0x915F60
#define CXWnd__Move1_x                                             0x916020
#define CXWnd__ProcessTransition_x                                 0x916AE0
#define CXWnd__Refade_x                                            0x9162F0
#define CXWnd__Resize_x                                            0x916580
#define CXWnd__Right_x                                             0x916D70
#define CXWnd__SetFocus_x                                          0x916930
#define CXWnd__SetFont_x                                           0x9169A0
#define CXWnd__SetKeyTooltip_x                                     0x9174E0
#define CXWnd__SetMouseOver_x                                      0x914390
#define CXWnd__StartFade_x                                         0x915D80
#define CXWnd__GetChildItem_x                                      0x9171C0
#define CXWnd__SetParent_x                                         0x915C50

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x949980

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x919F90
#define CXWndManager__DrawWindows_x                                0x919FB0
#define CXWndManager__GetKeyboardFlags_x                           0x91C670
#define CXWndManager__HandleKeyboardMsg_x                          0x91C270
#define CXWndManager__RemoveWnd_x                                  0x91C8C0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x91CE10

// CDBStr
#define CDBStr__GetString_x                                        0x52F9B0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B9190
#define EQ_Character__Cur_HP_x                                     0x4CF550
#define EQ_Character__Cur_Mana_x                                   0x4D6D00
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BC0B0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AFC30
#define EQ_Character__GetFocusRangeModifier_x                      0x4AFD80
#define EQ_Character__GetHPRegen_x                                 0x4DCCA0
#define EQ_Character__GetEnduranceRegen_x                          0x4DD2B0
#define EQ_Character__GetManaRegen_x                               0x4DD6F0
#define EQ_Character__Max_Endurance_x                              0x6346A0
#define EQ_Character__Max_HP_x                                     0x4CF380
#define EQ_Character__Max_Mana_x                                   0x6344A0
#define EQ_Character__doCombatAbility_x                            0x636B60
#define EQ_Character__UseSkill_x                                   0x4DF500
#define EQ_Character__GetConLevel_x                                0x62DDC0
#define EQ_Character__IsExpansionFlag_x                            0x592CC0
#define EQ_Character__TotalEffect_x                                0x4C2720
#define EQ_Character__GetPCSpellAffect_x                           0x4BCCA0
#define EQ_Character__SpellDuration_x                              0x4BC7D0
#define EQ_Character__GetAdjustedSkill_x                           0x4D2330
#define EQ_Character__GetBaseSkill_x                               0x4D32D0
#define EQ_Character__CanUseItem_x                                 0x4D7010

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BB870

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x64AB50

//PcClient
#define PcClient__PcClient_x                                       0x62B4F0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6DE0
#define CCharacterListWnd__EnterWorld_x                            0x4B6820
#define CCharacterListWnd__Quit_x                                  0x4B6530
#define CCharacterListWnd__UpdateList_x                            0x4B69B0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x60FCC0
#define EQ_Item__CreateItemTagString_x                             0x895F30
#define EQ_Item__IsStackable_x                                     0x89A970
#define EQ_Item__GetImageNum_x                                     0x897980
#define EQ_Item__CreateItemClient_x                                0x60EE90
#define EQ_Item__GetItemValue_x                                    0x898BE0
#define EQ_Item__ValueSellMerchant_x                               0x89C1E0
#define EQ_Item__IsKeyRingItem_x                                   0x89A2C0
#define EQ_Item__CanGoInBag_x                                      0x60FDE0
#define EQ_Item__IsEmpty_x                                         0x899DF0
#define EQ_Item__GetMaxItemCount_x                                 0x898FB0
#define EQ_Item__GetHeldItem_x                                     0x897850
#define EQ_Item__GetAugmentFitBySlot_x                             0x895870

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x54DF40
#define EQ_LoadingS__Array_x                                       0xBF0600

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x635000
#define EQ_PC__GetAlternateAbilityId_x                             0x8A5320
#define EQ_PC__GetCombatAbility_x                                  0x8A5990
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A5A00
#define EQ_PC__GetItemRecastTimer_x                                0x6370E0
#define EQ_PC__HasLoreItem_x                                       0x62E530
#define EQ_PC__AlertInventoryChanged_x                             0x62D6F0
#define EQ_PC__GetPcZoneClient_x                                   0x659250
#define EQ_PC__RemoveMyAffect_x                                    0x63A310
#define EQ_PC__GetKeyRingItems_x                                   0x8A62A0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A6020
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A6590

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5991E0
#define EQItemList__add_object_x                                   0x5C5970
#define EQItemList__add_item_x                                     0x5997F0
#define EQItemList__delete_item_x                                  0x599840
#define EQItemList__FreeItemList_x                                 0x599740

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x52CFA0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x64C3D0
#define EQPlayer__dEQPlayer_x                                      0x63F990
#define EQPlayer__DoAttack_x                                       0x653F10
#define EQPlayer__EQPlayer_x                                       0x640040
#define EQPlayer__SetNameSpriteState_x                             0x6442D0
#define EQPlayer__SetNameSpriteTint_x                              0x645190
#define PlayerBase__HasProperty_j_x                                0x97C150
#define EQPlayer__IsTargetable_x                                   0x97C5F0
#define EQPlayer__CanSee_x                                         0x97C450
#define EQPlayer__CanSee1_x                                        0x97C520
#define PlayerBase__GetVisibilityLineSegment_x                     0x97C210

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x656CE0
#define PlayerZoneClient__GetLevel_x                               0x659290
#define PlayerZoneClient__IsValidTeleport_x                        0x5C6AC0
#define PlayerZoneClient__LegalPlayerRace_x                        0x547210

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x64F0E0
#define EQPlayerManager__GetSpawnByName_x                          0x64F100
#define EQPlayerManager__GetPlayerFromPartialName_x                0x64F190

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x613560
#define KeypressHandler__AttachKeyToEqCommand_x                    0x6135A0
#define KeypressHandler__ClearCommandStateArray_x                  0x6149B0
#define KeypressHandler__HandleKeyDown_x                           0x6149D0
#define KeypressHandler__HandleKeyUp_x                             0x614A70
#define KeypressHandler__SaveKeymapping_x                          0x614E50

// MapViewMap 
#define MapViewMap__Clear_x                                        0x76B4C0
#define MapViewMap__SaveEx_x                                       0x76E860
#define MapViewMap__SetZoom_x                                      0x772F30

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B9760

// StringTable 
#define StringTable__getString_x                                   0x8B4600

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x639F80
#define PcZoneClient__RemovePetEffect_x                            0x63A5B0
#define PcZoneClient__HasAlternateAbility_x                        0x6342E0
#define PcZoneClient__GetCurrentMod_x                              0x4E25E0
#define PcZoneClient__GetModCap_x                                  0x4E24E0
#define PcZoneClient__CanEquipItem_x                               0x634990
#define PcZoneClient__GetItemByID_x                                0x637560
#define PcZoneClient__GetItemByItemClass_x                         0x6376B0
#define PcZoneClient__RemoveBuffEffect_x                           0x63A5D0
#define PcZoneClient__BandolierSwap_x                              0x6355C0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x637080

//Doors
#define EQSwitch__UseSwitch_x                                      0x5CB690

//IconCache
#define IconCache__GetIcon_x                                       0x70BFC0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x703AA0
#define CContainerMgr__CloseContainer_x                            0x703D70
#define CContainerMgr__OpenExperimentContainer_x                   0x7047E0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7C6810

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x607F10

//CLootWnd
#define CLootWnd__LootAll_x                                        0x761920
#define CLootWnd__RequestLootSlot_x                                0x760CC0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x566320
#define EQ_Spell__SpellAffects_x                                   0x566790
#define EQ_Spell__SpellAffectBase_x                                0x566550
#define EQ_Spell__IsStackable_x                                    0x4C6FB0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C6E00
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B41C0
#define EQ_Spell__IsSPAStacking_x                                  0x5675C0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x566AE0
#define EQ_Spell__IsNoRemove_x                                     0x4C6F90
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x5675D0
#define __IsResEffectSpell_x                                       0x4C62B0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AA9B0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C3D70

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x80C010
#define CTargetWnd__WndNotification_x                              0x80B8A0
#define CTargetWnd__RefreshTargetBuffs_x                           0x80BB70
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x80A9F0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x8106D0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x52A910
#define CTaskManager__HandleMessage_x                              0x529080

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5618D0
#define EqSoundManager__PlayScriptMp3_x                            0x561A30
#define EqSoundManager__SoundAssistPlay_x                          0x671FC0
#define EqSoundManager__WaveInstancePlay_x                         0x671530

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x51E920

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x9353B0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x555B80
#define CAltAbilityData__GetMercMaxRank_x                          0x555B20
#define CAltAbilityData__GetMaxRank_x                              0x54AF90

//CTargetRing
#define CTargetRing__Cast_x                                        0x606010

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C6DE0
#define CharacterBase__CreateItemGlobalIndex_x                     0x5049F0
#define CharacterBase__CreateItemIndex_x                           0x60E0F0
#define CharacterBase__GetItemPossession_x                         0x4F0840
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CC3A0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CC400
#define CharacterBase__GetEffectId_x                               0x4C6D90

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6EB490
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6EBCB0

//messages
#define msg_spell_worn_off_x                                       0x58AF80
#define msg_new_text_x                                             0x57FDE0
#define __msgTokenTextParam_x                                      0x58D4A0
#define msgTokenText_x                                             0x58D6F0

//SpellManager
#define SpellManager__vftable_x                                    0xAB7C20
#define SpellManager__SpellManager_x                               0x6752F0
#define Spellmanager__LoadTextSpells_x                             0x675BC0
#define SpellManager__GetSpellByGroupAndRank_x                     0x6754C0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9800C0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x5050E0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5912C0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x626CF0
#define ItemGlobalIndex__IsValidIndex_x                            0x505140

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C46B0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C4930

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x75A4B0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x7081B0
#define CCursorAttachment__AttachToCursor1_x                       0x7081F0
#define CCursorAttachment__Deactivate_x                            0x7091D0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x92AF40
#define CSidlManagerBase__CreatePageWnd_x                          0x92A750
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x926990
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x926920

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x947E70
#define CEQSuiteTextureLoader__GetTexture_x                        0x947B30

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x501FC0
#define CFindItemWnd__WndNotification_x                            0x502AA0
#define CFindItemWnd__Update_x                                     0x5035E0
#define CFindItemWnd__PickupSelectedItem_x                         0x501830

//IString
#define IString__Append_x                                          0x4F1ED0

//Camera
#define CDisplay__cameraType_x                                     0xDC9C24
#define EverQuest__Cameras_x                                       0xE8CF68

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x50A880
#define LootFiltersManager__GetItemFilterData_x                    0x50A170
#define LootFiltersManager__RemoveItemLootFilter_x                 0x50A1A0
#define LootFiltersManager__SetItemLootFilter_x                    0x50A3C0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B4840

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x985D30
#define CResolutionHandler__GetWindowedStyle_x                     0x66C9B0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x7007B0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D6E40

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x720AE0
#define CGroupWnd__UpdateDisplay_x                                 0x71FE40

//ItemBase
#define ItemBase__IsLore_x                                         0x89A320
#define ItemBase__IsLoreEquipped_x                                 0x89A390

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5C5860
#define EQPlacedItemManager__GetItemByGuid_x                       0x5C5A10
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5C5A70

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x661D60
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x6659D0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x4F82D0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4E75F0
#define FactionManagerClient__HandleFactionMessage_x               0x4E7C70
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4E8290
#define FactionManagerClient__GetMaxFaction_x                      0x4E82E0
#define FactionManagerClient__GetMinFaction_x                      0x4E8260

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4F0810

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x90F5E0

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
