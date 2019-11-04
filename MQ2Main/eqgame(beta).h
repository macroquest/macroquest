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
#define __ExpectedVersionDate                                     "Nov  4 2019"
#define __ExpectedVersionTime                                     "04:21:37"
#define __ActualVersionDate_x                                      0xB03F20
#define __ActualVersionTime_x                                      0xB03F14
#define __ActualVersionBuild_x                                     0xAEFBEC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x62A8D0
#define __MemChecker1_x                                            0x8FD2B0
#define __MemChecker2_x                                            0x6B8F30
#define __MemChecker3_x                                            0x6B8E80
#define __MemChecker4_x                                            0x854720
#define __EncryptPad0_x                                            0xC3A3E0
#define __EncryptPad1_x                                            0xC985A0
#define __EncryptPad2_x                                            0xC4AC78
#define __EncryptPad3_x                                            0xC4A878
#define __EncryptPad4_x                                            0xC88BF8
#define __EncryptPad5_x                                            0xF61CDC
#define __AC1_x                                                    0x8114A6
#define __AC2_x                                                    0x5E477F
#define __AC3_x                                                    0x5EBE7F
#define __AC4_x                                                    0x5EFE50
#define __AC5_x                                                    0x5F615F
#define __AC6_x                                                    0x5FA776
#define __AC7_x                                                    0x5E41F0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x192718

// Direct Input
#define DI8__Main_x                                                0xF641B8
#define DI8__Keyboard_x                                            0xF641BC
#define DI8__Mouse_x                                               0xF641D0
#define DI8__Mouse_Copy_x                                          0xEBD3A4
#define DI8__Mouse_Check_x                                         0xF61D04
#define __AutoSkillArray_x                                         0xEBE2BC
#define __Attack_x                                                 0xF5C0E3
#define __Autofire_x                                               0xF5C0E4
#define __BindList_x                                               0xC28E18
#define g_eqCommandStates_x                                        0xC29B98
#define __Clicks_x                                                 0xEBD45C
#define __CommandList_x                                            0xC2A758
#define __CurrentMapLabel_x                                        0xF74B64
#define __CurrentSocial_x                                          0xC127CC
#define __DoAbilityList_x                                          0xEF3C04
#define __do_loot_x                                                0x5B0A70
#define __DrawHandler_x                                            0x15F3ED8
#define __GroupCount_x                                             0xEAFC6A
#define __Guilds_x                                                 0xEB3BB0
#define __gWorld_x                                                 0xEAFB34
#define __HWnd_x                                                   0xF641D4
#define __heqmain_x                                                0xF641AC
#define __InChatMode_x                                             0xEBD38C
#define __LastTell_x                                               0xEBF300
#define __LMouseHeldTime_x                                         0xEBD4C8
#define __Mouse_x                                                  0xF64198
#define __MouseLook_x                                              0xEBD422
#define __MouseEventTime_x                                         0xF5CBC4
#define __gpbCommandEvent_x                                        0xEAFE5C
#define __NetStatusToggle_x                                        0xEBD425
#define __PCNames_x                                                0xEBE8AC
#define __RangeAttackReady_x                                       0xEBE5A0
#define __RMouseHeldTime_x                                         0xEBD4C4
#define __RunWalkState_x                                           0xEBD390
#define __ScreenMode_x                                             0xDFB470
#define __ScreenX_x                                                0xEBD344
#define __ScreenY_x                                                0xEBD340
#define __ScreenXMax_x                                             0xEBD348
#define __ScreenYMax_x                                             0xEBD34C
#define __ServerHost_x                                             0xEAD79B
#define __ServerName_x                                             0xEF3BC4
#define __ShiftKeyDown_x                                           0xEBDA1C
#define __ShowNames_x                                              0xEBE75C
#define __Socials_x                                                0xEF3CC4
#define __SubscriptionType_x                                       0xFB9068
#define __TargetAggroHolder_x                                      0xF77518
#define __ZoneType_x                                               0xEBD820
#define __GroupAggro_x                                             0xF77558
#define __LoginName_x                                              0xF64914
#define __Inviter_x                                                0xF5C060
#define __AttackOnAssist_x                                         0xEBE718
#define __UseTellWindows_x                                         0xEBEA48
#define __gfMaxZoomCameraDistance_x                                0xAF9860
#define __gfMaxCameraDistance_x                                    0xB25DB8
#define __pulAutoRun_x                                             0xEBD440
#define __pulForward_x                                             0xEBEA80
#define __pulBackward_x                                            0xEBEA84
#define __pulTurnRight_x                                           0xEBEA88
#define __pulTurnLeft_x                                            0xEBEA8C
#define __pulStrafeLeft_x                                          0xEBEA90
#define __pulStrafeRight_x                                         0xEBEA94

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEAFF48
#define instEQZoneInfo_x                                           0xEBD618
#define pinstActiveBanker_x                                        0xEAFE74
#define pinstActiveCorpse_x                                        0xEAFE6C
#define pinstActiveGMaster_x                                       0xEAFE70
#define pinstActiveMerchant_x                                      0xEAFE68
#define pinstAltAdvManager_x                                       0xDFC180
#define pinstBandageTarget_x                                       0xEAFE84
#define pinstCamActor_x                                            0xDFB460
#define pinstCDBStr_x                                              0xDFAE9C
#define pinstCDisplay_x                                            0xEAFB18
#define pinstCEverQuest_x                                          0xF641D8
#define pinstEverQuestInfo_x                                       0xEBD338
#define pinstCharData_x                                            0xEAFC48
#define pinstCharSpawn_x                                           0xEAFF3C
#define pinstControlledMissile_x                                   0xEADB00
#define pinstControlledPlayer_x                                    0xEAFF3C
#define pinstCResolutionHandler_x                                  0x15F4108
#define pinstCSidlManager_x                                        0x15F30A0
#define pinstCXWndManager_x                                        0x15F309C
#define instDynamicZone_x                                          0xEB3A88
#define pinstDZMember_x                                            0xEB3B98
#define pinstDZTimerInfo_x                                         0xEB3B9C
#define pinstEqLogin_x                                             0xF64260
#define instEQMisc_x                                               0xDFADE0
#define pinstEQSoundManager_x                                      0xDFD150
#define pinstEQSpellStrings_x                                      0xCBD858
#define instExpeditionLeader_x                                     0xEB3AD2
#define instExpeditionName_x                                       0xEB3B12
#define pinstGroup_x                                               0xEAFC66
#define pinstImeManager_x                                          0x15F3098
#define pinstLocalPlayer_x                                         0xEAFE64
#define pinstMercenaryData_x                                       0xF5E6B4
#define pinstMercenaryStats_x                                      0xF77664
#define pinstModelPlayer_x                                         0xEAFE7C
#define pinstPCData_x                                              0xEAFC48
#define pinstSkillMgr_x                                            0xF60820
#define pinstSpawnManager_x                                        0xF5F2C8
#define pinstSpellManager_x                                        0xF60A40
#define pinstSpellSets_x                                           0xF54D0C
#define pinstStringTable_x                                         0xEAFC4C
#define pinstSwitchManager_x                                       0xEAD4E8
#define pinstTarget_x                                              0xEAFF38
#define pinstTargetObject_x                                        0xEAD638
#define pinstTargetSwitch_x                                        0xEAFB10
#define pinstTaskMember_x                                          0xDFAC70
#define pinstTrackTarget_x                                         0xEAFF40
#define pinstTradeTarget_x                                         0xEAFE78
#define instTributeActive_x                                        0xDFAE01
#define pinstViewActor_x                                           0xDFB45C
#define pinstWorldData_x                                           0xEADB0C
#define pinstZoneAddr_x                                            0xEBD8B8
#define pinstPlayerPath_x                                          0xF5F360
#define pinstTargetIndicator_x                                     0xF60CA8
#define EQObject_Top_x                                             0xEAFE60
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDFB724
#define pinstCAchievementsWnd_x                                    0xDFB4BC
#define pinstCActionsWnd_x                                         0xDFB4E8
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDFAF84
#define pinstCAdvancedLootWnd_x                                    0xDFB7C8
#define pinstCAdventureLeaderboardWnd_x                            0xF6E338
#define pinstCAdventureRequestWnd_x                                0xF6E3E8
#define pinstCAdventureStatsWnd_x                                  0xF6E498
#define pinstCAggroMeterWnd_x                                      0xDFB454
#define pinstCAlarmWnd_x                                           0xDFB78C
#define pinstCAlertHistoryWnd_x                                    0xDFB7C0
#define pinstCAlertStackWnd_x                                      0xDFB738
#define pinstCAlertWnd_x                                           0xDFB74C
#define pinstCAltStorageWnd_x                                      0xF6E7F8
#define pinstCAudioTriggersWindow_x                                0xCAFB88
#define pinstCAuraWnd_x                                            0xDFB428
#define pinstCAvaZoneWnd_x                                         0xDFB788
#define pinstCBandolierWnd_x                                       0xDFB450
#define pinstCBankWnd_x                                            0xDFB424
#define pinstCBarterMerchantWnd_x                                  0xF6FA38
#define pinstCBarterSearchWnd_x                                    0xF6FAE8
#define pinstCBarterWnd_x                                          0xF6FB98
#define pinstCBazaarConfirmationWnd_x                              0xDFB4F8
#define pinstCBazaarSearchWnd_x                                    0xDFB4B0
#define pinstCBazaarWnd_x                                          0xDFB774
#define pinstCBlockedBuffWnd_x                                     0xDFB42C
#define pinstCBlockedPetBuffWnd_x                                  0xDFB44C
#define pinstCBodyTintWnd_x                                        0xDFB4FC
#define pinstCBookWnd_x                                            0xDFB490
#define pinstCBreathWnd_x                                          0xDFB744
#define pinstCBuffWindowNORMAL_x                                   0xDFB010
#define pinstCBuffWindowSHORT_x                                    0xDFB014
#define pinstCBugReportWnd_x                                       0xDFB420
#define pinstCButtonWnd_x                                          0x15F3308
#define pinstCCastingWnd_x                                         0xDFB480
#define pinstCCastSpellWnd_x                                       0xDFB73C
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDFB778
#define pinstCChatWindowManager_x                                  0xF70658
#define pinstCClaimWnd_x                                           0xF707B0
#define pinstCColorPickerWnd_x                                     0xDFB4F0
#define pinstCCombatAbilityWnd_x                                   0xDFB784
#define pinstCCombatSkillsSelectWnd_x                              0xDFB7A8
#define pinstCCompassWnd_x                                         0xDFB4EC
#define pinstCConfirmationDialog_x                                 0xF756B0
#define pinstCContainerMgr_x                                       0xDFB76C
#define pinstCContextMenuManager_x                                 0x15F3058
#define pinstCCursorAttachment_x                                   0xDFB464
#define pinstCDynamicZoneWnd_x                                     0xF70D78
#define pinstCEditLabelWnd_x                                       0xDFAF90
#define pinstCEQMainWnd_x                                          0xF70FC0
#define pinstCEventCalendarWnd_x                                   0xDFB00C
#define pinstCExtendedTargetWnd_x                                  0xDFB440
#define pinstCFacePick_x                                           0xDFB7B8
#define pinstCFactionWnd_x                                         0xDFB764
#define pinstCFellowshipWnd_x                                      0xF711C0
#define pinstCFileSelectionWnd_x                                   0xDFB47C
#define pinstCFindItemWnd_x                                        0xDFB758
#define pinstCFindLocationWnd_x                                    0xF71318
#define pinstCFriendsWnd_x                                         0xDFB7C4
#define pinstCGemsGameWnd_x                                        0xDFB760
#define pinstCGiveWnd_x                                            0xDFB790
#define pinstCGroupSearchFiltersWnd_x                              0xDFB488
#define pinstCGroupSearchWnd_x                                     0xF71710
#define pinstCGroupWnd_x                                           0xF717C0
#define pinstCGuildBankWnd_x                                       0xEBE6FC
#define pinstCGuildCreationWnd_x                                   0xF71920
#define pinstCGuildMgmtWnd_x                                       0xF719D0
#define pinstCharacterCreation_x                                   0xDFB7B0
#define pinstCHelpWnd_x                                            0xDFAF7C
#define pinstCHeritageSelectionWnd_x                               0xDFB7D0
#define pinstCHotButtonWnd_x                                       0xF73B28
#define pinstCHotButtonWnd1_x                                      0xF73B28
#define pinstCHotButtonWnd2_x                                      0xF73B2C
#define pinstCHotButtonWnd3_x                                      0xF73B30
#define pinstCHotButtonWnd4_x                                      0xF73B34
#define pinstCIconSelectionWnd_x                                   0xDFB458
#define pinstCInspectWnd_x                                         0xDFAF78
#define pinstCInventoryWnd_x                                       0xDFAF38
#define pinstCInvSlotMgr_x                                         0xDFB720
#define pinstCItemDisplayManager_x                                 0xF740B8
#define pinstCItemExpTransferWnd_x                                 0xF741E8
#define pinstCItemOverflowWnd_x                                    0xDFB4B8
#define pinstCJournalCatWnd_x                                      0xDFB498
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDFB444
#define pinstCKeyRingWnd_x                                         0xDFAF8C
#define pinstCLargeDialogWnd_x                                     0xF76330
#define pinstCLayoutCopyWnd_x                                      0xF74538
#define pinstCLFGuildWnd_x                                         0xF745E8
#define pinstCLoadskinWnd_x                                        0xDFB770
#define pinstCLootFiltersCopyWnd_x                                 0xCCC178
#define pinstCLootFiltersWnd_x                                     0xDFB740
#define pinstCLootSettingsWnd_x                                    0xDFB754
#define pinstCLootWnd_x                                            0xDFB49C
#define pinstCMailAddressBookWnd_x                                 0xDFB72C
#define pinstCMailCompositionWnd_x                                 0xDFB510
#define pinstCMailIgnoreListWnd_x                                  0xDFB730
#define pinstCMailWnd_x                                            0xDFB4E4
#define pinstCManageLootWnd_x                                      0xDFC630
#define pinstCMapToolbarWnd_x                                      0xDFAF80
#define pinstCMapViewWnd_x                                         0xDFAF48
#define pinstCMarketplaceWnd_x                                     0xDFB748
#define pinstCMerchantWnd_x                                        0xDFB4A0
#define pinstCMIZoneSelectWnd_x                                    0xF74E20
#define pinstCMusicPlayerWnd_x                                     0xDFB4A8
#define pinstCNameChangeMercWnd_x                                  0xDFB4E0
#define pinstCNameChangePetWnd_x                                   0xDFB4C0
#define pinstCNameChangeWnd_x                                      0xDFB508
#define pinstCNoteWnd_x                                            0xDFAF4C
#define pinstCObjectPreviewWnd_x                                   0xDFB750
#define pinstCOptionsWnd_x                                         0xDFAF60
#define pinstCPetInfoWnd_x                                         0xDFB4C4
#define pinstCPetitionQWnd_x                                       0xDFB4AC
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDFB500
#define pinstCPlayerWnd_x                                          0xDFB4C8
#define pinstCPopupWndManager_x                                    0xF756B0
#define pinstCProgressionSelectionWnd_x                            0xF75760
#define pinstCPurchaseGroupWnd_x                                   0xDFB798
#define pinstCPurchaseWnd_x                                        0xDFB768
#define pinstCPvPLeaderboardWnd_x                                  0xF75810
#define pinstCPvPStatsWnd_x                                        0xF758C0
#define pinstCQuantityWnd_x                                        0xDFB448
#define pinstCRaceChangeWnd_x                                      0xDFB728
#define pinstCRaidOptionsWnd_x                                     0xDFB48C
#define pinstCRaidWnd_x                                            0xDFB518
#define pinstCRealEstateItemsWnd_x                                 0xDFB4B4
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDFB434
#define pinstCRealEstateManageWnd_x                                0xDFB7A0
#define pinstCRealEstateNeighborhoodWnd_x                          0xDFB7BC
#define pinstCRealEstatePlotSearchWnd_x                            0xDFAF3C
#define pinstCRealEstatePurchaseWnd_x                              0xDFAF74
#define pinstCRespawnWnd_x                                         0xDFB438
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDFB734
#define pinstCSendMoneyWnd_x                                       0xDFB7A4
#define pinstCServerListWnd_x                                      0xDFAF9C
#define pinstCSkillsSelectWnd_x                                    0xDFB77C
#define pinstCSkillsWnd_x                                          0xDFB75C
#define pinstCSocialEditWnd_x                                      0xDFAF88
#define pinstCSocialWnd_x                                          0xDFB4DC
#define pinstCSpellBookWnd_x                                       0xDFB780
#define pinstCStoryWnd_x                                           0xDFB4CC
#define pinstCTargetOfTargetWnd_x                                  0xF776E8
#define pinstCTargetWnd_x                                          0xDFB430
#define pinstCTaskOverlayWnd_x                                     0xDFB794
#define pinstCTaskSelectWnd_x                                      0xF77840
#define pinstCTaskManager_x                                        0xCCCAB8
#define pinstCTaskTemplateSelectWnd_x                              0xF778F0
#define pinstCTaskWnd_x                                            0xF779A0
#define pinstCTextEntryWnd_x                                       0xDFB018
#define pinstCTimeLeftWnd_x                                        0xDFB484
#define pinstCTipWndCONTEXT_x                                      0xF77BA4
#define pinstCTipWndOFDAY_x                                        0xF77BA0
#define pinstCTitleWnd_x                                           0xF77C50
#define pinstCTrackingWnd_x                                        0xDFAF40
#define pinstCTradeskillWnd_x                                      0xF77DB8
#define pinstCTradeWnd_x                                           0xDFB50C
#define pinstCTrainWnd_x                                           0xDFB504
#define pinstCTributeBenefitWnd_x                                  0xF77FB8
#define pinstCTributeMasterWnd_x                                   0xF78068
#define pinstCTributeTrophyWnd_x                                   0xF78118
#define pinstCVideoModesWnd_x                                      0xDFB514
#define pinstCVoiceMacroWnd_x                                      0xF61410
#define pinstCVoteResultsWnd_x                                     0xDFB4A4
#define pinstCVoteWnd_x                                            0xDFB494
#define pinstCWebManager_x                                         0xF61A8C
#define pinstCZoneGuideWnd_x                                       0xDFB79C
#define pinstCZonePathWnd_x                                        0xDFB7AC

#define pinstEQSuiteTextureLoader_x                                0xC9A078
#define pinstItemIconCache_x                                       0xF70F78
#define pinstLootFiltersManager_x                                  0xCCC228
#define pinstRewardSelectionWnd_x                                  0xF76008

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5ABED0
#define __CastRay2_x                                               0x5ABF20
#define __ConvertItemTags_x                                        0x5C7A60
#define __CleanItemTags_x                                          0x47D0E0
#define __DoesFileExist_x                                          0x9003F0
#define __EQGetTime_x                                              0x8FCD80
#define __ExecuteCmd_x                                             0x5A4790
#define __FixHeading_x                                             0x9979B0
#define __GameLoop_x                                               0x6B8120
#define __get_bearing_x                                            0x5ABA40
#define __get_melee_range_x                                        0x5AC110
#define __GetAnimationCache_x                                      0x71D300
#define __GetGaugeValueFromEQ_x                                    0x80F950
#define __GetLabelFromEQ_x                                         0x811430
#define __GetXTargetType_x                                         0x999470
#define __HandleMouseWheel_x                                       0x6B8FE0
#define __HeadingDiff_x                                            0x997A20
#define __HelpPath_x                                               0xF5C7B4
#define __LoadFrontEnd_x                                           0x6B5440
#define __NewUIINI_x                                               0x80F620
#define __ProcessGameEvents_x                                      0x60BFE0
#define __ProcessMouseEvent_x                                      0x60B7A0
#define __SaveColors_x                                             0x54F4A0
#define __STMLToText_x                                             0x93ACC0
#define __ToggleKeyRingItem_x                                      0x512CD0
#define CMemoryMappedFile__SetFile_x                               0xA86D10
#define CrashDetected_x                                            0x6B6EE0
#define DrawNetStatus_x                                            0x637BB0
#define Expansion_HoT_x                                            0xEBE704
#define Teleport_Table_Size_x                                      0xEAD640
#define Teleport_Table_x                                           0xEADB10
#define Util__FastTime_x                                           0x8FC950

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490290
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4991A0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x498F70
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493830
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492C80

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x557060
#define AltAdvManager__IsAbilityReady_x                            0x555F90
#define AltAdvManager__GetAAById_x                                 0x556190
#define AltAdvManager__CanTrainAbility_x                           0x556200
#define AltAdvManager__CanSeeAbility_x                             0x556560

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA0D0
#define CharacterZoneClient__HasSkill_x                            0x4D4FC0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D66E0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE300
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BA900
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D90A0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9180
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9260
#define CharacterZoneClient__FindAffectSlot_x                      0x4C30F0
#define CharacterZoneClient__BardCastBard_x                        0x4C5C50
#define CharacterZoneClient__GetMaxEffects_x                       0x4BA9D0
#define CharacterZoneClient__GetEffect_x                           0x4BA840
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C4140
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C4210
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C4260
#define CharacterZoneClient__CalcAffectChange_x                    0x4C43B0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4580
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B27F0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7640
#define CharacterZoneClient__FindItemByRecord_x                    0x4D70C0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6DEAD0
#define CBankWnd__WndNotification_x                                0x6DE8B0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6EC570

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x61A6B0
#define CButtonWnd__CButtonWnd_x                                   0x9370B0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x70C440
#define CChatManager__InitContextMenu_x                            0x7055A0
#define CChatManager__FreeChatWindow_x                             0x70AF80
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8790
#define CChatManager__SetLockedActiveChatWindow_x                  0x70C0C0
#define CChatManager__CreateChatWindow_x                           0x70B5C0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E88A0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x94B650
#define CContextMenu__dCContextMenu_x                              0x94B880
#define CContextMenu__AddMenuItem_x                                0x94B890
#define CContextMenu__RemoveMenuItem_x                             0x94BBA0
#define CContextMenu__RemoveAllMenuItems_x                         0x94BBC0
#define CContextMenu__CheckMenuItem_x                              0x94BC40
#define CContextMenu__SetMenuItem_x                                0x94BAC0
#define CContextMenu__AddSeparator_x                               0x94BA20

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x94C1E0
#define CContextMenuManager__RemoveMenu_x                          0x94C250
#define CContextMenuManager__PopupMenu_x                           0x94C310
#define CContextMenuManager__Flush_x                               0x94C180
#define CContextMenuManager__GetMenu_x                             0x49B380
#define CContextMenuManager__CreateDefaultMenu_x                   0x717B10

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D9090
#define CChatService__GetFriendName_x                              0x8D90A0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x70CCB0
#define CChatWindow__Clear_x                                       0x70DF70
#define CChatWindow__WndNotification_x                             0x70E700
#define CChatWindow__AddHistory_x                                  0x70D830

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x948AB0
#define CComboWnd__Draw_x                                          0x947FB0
#define CComboWnd__GetCurChoice_x                                  0x9488F0
#define CComboWnd__GetListRect_x                                   0x948460
#define CComboWnd__GetTextRect_x                                   0x948B20
#define CComboWnd__InsertChoice_x                                  0x9485F0
#define CComboWnd__SetColors_x                                     0x9485C0
#define CComboWnd__SetChoice_x                                     0x9488C0
#define CComboWnd__GetItemCount_x                                  0x948900
#define CComboWnd__GetCurChoiceText_x                              0x948940
#define CComboWnd__GetChoiceText_x                                 0x948910
#define CComboWnd__InsertChoiceAtIndex_x                           0x948680

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x715510
#define CContainerWnd__vftable_x                                   0xB0D0FC
#define CContainerWnd__SetContainer_x                              0x716A70

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x549EE0
#define CDisplay__PreZoneMainUI_x                                  0x549EF0
#define CDisplay__CleanGameUI_x                                    0x54F260
#define CDisplay__GetClickedActor_x                                0x542200
#define CDisplay__GetUserDefinedColor_x                            0x53A8C0
#define CDisplay__GetWorldFilePath_x                               0x543C70
#define CDisplay__is3dON_x                                         0x53EE60
#define CDisplay__ReloadUI_x                                       0x549370
#define CDisplay__WriteTextHD2_x                                   0x53EC50
#define CDisplay__TrueDistance_x                                   0x545930
#define CDisplay__SetViewActor_x                                   0x541B20
#define CDisplay__GetFloorHeight_x                                 0x53EF20
#define CDisplay__SetRenderWindow_x                                0x53D880
#define CDisplay__ToggleScreenshotMode_x                           0x5415F0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x96B400

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x94EB90
#define CEditWnd__GetCharIndexPt_x                                 0x94FAB0
#define CEditWnd__GetDisplayString_x                               0x94F960
#define CEditWnd__GetHorzOffset_x                                  0x94E1D0
#define CEditWnd__GetLineForPrintableChar_x                        0x950C20
#define CEditWnd__GetSelStartPt_x                                  0x94FD60
#define CEditWnd__GetSTMLSafeText_x                                0x94F780
#define CEditWnd__PointFromPrintableChar_x                         0x950860
#define CEditWnd__SelectableCharFromPoint_x                        0x9509D0
#define CEditWnd__SetEditable_x                                    0x94FE20
#define CEditWnd__SetWindowTextA_x                                 0x94F500

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5F9C50
#define CEverQuest__ClickedPlayer_x                                0x5EBC60
#define CEverQuest__CreateTargetIndicator_x                        0x609280
#define CEverQuest__DeleteTargetIndicator_x                        0x609310
#define CEverQuest__DoTellWindow_x                                 0x4E8980
#define CEverQuest__OutputTextToLog_x                              0x4E8C00
#define CEverQuest__DropHeldItemOnGround_x                         0x5E0CA0
#define CEverQuest__dsp_chat_x                                     0x4E8F90
#define CEverQuest__trimName_x                                     0x605560
#define CEverQuest__Emote_x                                        0x5FA4B0
#define CEverQuest__EnterZone_x                                    0x5F4430
#define CEverQuest__GetBodyTypeDesc_x                              0x5FEE20
#define CEverQuest__GetClassDesc_x                                 0x5FF460
#define CEverQuest__GetClassThreeLetterCode_x                      0x5FFA60
#define CEverQuest__GetDeityDesc_x                                 0x607BC0
#define CEverQuest__GetLangDesc_x                                  0x5FFC20
#define CEverQuest__GetRaceDesc_x                                  0x5FF440
#define CEverQuest__InterpretCmd_x                                 0x608190
#define CEverQuest__LeftClickedOnPlayer_x                          0x5E4EA0
#define CEverQuest__LMouseUp_x                                     0x5E3230
#define CEverQuest__RightClickedOnPlayer_x                         0x5E5780
#define CEverQuest__RMouseUp_x                                     0x5E41B0
#define CEverQuest__SetGameState_x                                 0x5E0A30
#define CEverQuest__UPCNotificationFlush_x                         0x605460
#define CEverQuest__IssuePetCommand_x                              0x601020
#define CEverQuest__ReportSuccessfulHit_x                          0x5FB8A0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x727450
#define CGaugeWnd__CalcLinesFillRect_x                             0x7274B0
#define CGaugeWnd__Draw_x                                          0x726AD0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF300
#define CGuild__GetGuildName_x                                     0x4AE3E0
#define CGuild__GetGuildIndex_x                                    0x4AE770

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x7428A0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x61AA70

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x74F880
#define CInvSlotMgr__MoveItem_x                                    0x74E5E0
#define CInvSlotMgr__SelectSlot_x                                  0x74F950

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x74CE50
#define CInvSlot__SliderComplete_x                                 0x74ABA0
#define CInvSlot__GetItemBase_x                                    0x74A540
#define CInvSlot__UpdateItem_x                                     0x74A6B0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7513D0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x750570
#define CInvSlotWnd__HandleLButtonUp_x                             0x750F50

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x80AC80
#define CItemDisplayWnd__UpdateStrings_x                           0x75FA50
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x759840
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x759D40
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x760060
#define CItemDisplayWnd__AboutToShow_x                             0x75F6A0
#define CItemDisplayWnd__WndNotification_x                         0x761140
#define CItemDisplayWnd__RequestConvertItem_x                      0x760C00
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x75E700
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x75F4C0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x843850

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x765670

// CLabel 
#define CLabel__Draw_x                                             0x76B040

// CListWnd
#define CListWnd__CListWnd_x                                       0x921340
#define CListWnd__dCListWnd_x                                      0x921660
#define CListWnd__AddColumn_x                                      0x925AD0
#define CListWnd__AddColumn1_x                                     0x925B20
#define CListWnd__AddLine_x                                        0x925EB0
#define CListWnd__AddString_x                                      0x925CB0
#define CListWnd__CalculateFirstVisibleLine_x                      0x925890
#define CListWnd__CalculateVSBRange_x                              0x925680
#define CListWnd__ClearSel_x                                       0x926690
#define CListWnd__ClearAllSel_x                                    0x9266F0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x927110
#define CListWnd__Compare_x                                        0x924FB0
#define CListWnd__Draw_x                                           0x921790
#define CListWnd__DrawColumnSeparators_x                           0x923F80
#define CListWnd__DrawHeader_x                                     0x9243F0
#define CListWnd__DrawItem_x                                       0x9248F0
#define CListWnd__DrawLine_x                                       0x9240F0
#define CListWnd__DrawSeparator_x                                  0x924020
#define CListWnd__EnableLine_x                                     0x923850
#define CListWnd__EnsureVisible_x                                  0x927030
#define CListWnd__ExtendSel_x                                      0x9265C0
#define CListWnd__GetColumnTooltip_x                               0x923390
#define CListWnd__GetColumnMinWidth_x                              0x923400
#define CListWnd__GetColumnWidth_x                                 0x923300
#define CListWnd__GetCurSel_x                                      0x922C90
#define CListWnd__GetItemAtPoint_x                                 0x923AD0
#define CListWnd__GetItemAtPoint1_x                                0x923B40
#define CListWnd__GetItemData_x                                    0x922D10
#define CListWnd__GetItemHeight_x                                  0x9230D0
#define CListWnd__GetItemIcon_x                                    0x922EA0
#define CListWnd__GetItemRect_x                                    0x923940
#define CListWnd__GetItemText_x                                    0x922D50
#define CListWnd__GetSelList_x                                     0x926740
#define CListWnd__GetSeparatorRect_x                               0x923D80
#define CListWnd__InsertLine_x                                     0x9262A0
#define CListWnd__RemoveLine_x                                     0x9263F0
#define CListWnd__SetColors_x                                      0x925650
#define CListWnd__SetColumnJustification_x                         0x925380
#define CListWnd__SetColumnWidth_x                                 0x9252A0
#define CListWnd__SetCurSel_x                                      0x926500
#define CListWnd__SetItemColor_x                                   0x926CE0
#define CListWnd__SetItemData_x                                    0x926CA0
#define CListWnd__SetItemText_x                                    0x9268B0
#define CListWnd__ShiftColumnSeparator_x                           0x925440
#define CListWnd__Sort_x                                           0x925130
#define CListWnd__ToggleSel_x                                      0x926530
#define CListWnd__SetColumnsSizable_x                              0x9254F0
#define CListWnd__SetItemWnd_x                                     0x926B60
#define CListWnd__GetItemWnd_x                                     0x922EF0
#define CListWnd__SetItemIcon_x                                    0x926930
#define CListWnd__CalculateCustomWindowPositions_x                 0x925990
#define CListWnd__SetVScrollPos_x                                  0x925280

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x780820
#define CMapViewWnd__GetWorldCoordinates_x                         0x77EF30
#define CMapViewWnd__HandleLButtonDown_x                           0x77BF70

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A0740
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A1020
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A1550
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A44D0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x79F2A0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7AA080
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A0350

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8A6A20
#define CPacketScrambler__hton_x                                   0x8A6A10

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x940300
#define CSidlManager__FindScreenPieceTemplate_x                    0x940710
#define CSidlManager__FindScreenPieceTemplate1_x                   0x940500
#define CSidlManager__CreateLabel_x                                0x8020B0
#define CSidlManager__CreateXWndFromTemplate_x                     0x943670
#define CSidlManager__CreateXWndFromTemplate1_x                    0x943840
#define CSidlManager__CreateXWnd_x                                 0x801FE0
#define CSidlManager__CreateHotButtonWnd_x                         0x802580

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x93CDE0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x93CCE0
#define CSidlScreenWnd__ConvertToRes_x                             0x9623A0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x93C780
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x93C470
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x93C540
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x93C610
#define CSidlScreenWnd__DrawSidlPiece_x                            0x93D280
#define CSidlScreenWnd__EnableIniStorage_x                         0x93D750
#define CSidlScreenWnd__GetSidlPiece_x                             0x93D470
#define CSidlScreenWnd__Init1_x                                    0x93C070
#define CSidlScreenWnd__LoadIniInfo_x                              0x93D7A0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x93E2E0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x93B480
#define CSidlScreenWnd__StoreIniInfo_x                             0x93DE60
#define CSidlScreenWnd__StoreIniVis_x                              0x93E1C0
#define CSidlScreenWnd__WndNotification_x                          0x93D190
#define CSidlScreenWnd__GetChildItem_x                             0x93D6D0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x92CF00
#define CSidlScreenWnd__m_layoutCopy_x                             0x15F2F28

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x67F080
#define CSkillMgr__GetSkillCap_x                                   0x67F260
#define CSkillMgr__GetNameToken_x                                  0x67E800
#define CSkillMgr__IsActivatedSkill_x                              0x67E940
#define CSkillMgr__IsCombatSkill_x                                 0x67E880

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x94CFB0
#define CSliderWnd__SetValue_x                                     0x94CE20
#define CSliderWnd__SetNumTicks_x                                  0x94CE80

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x8080D0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x955760
#define CStmlWnd__CalculateHSBRange_x                              0x956840
#define CStmlWnd__CalculateVSBRange_x                              0x9567B0
#define CStmlWnd__CanBreakAtCharacter_x                            0x95AB70
#define CStmlWnd__FastForwardToEndOfTag_x                          0x95B800
#define CStmlWnd__ForceParseNow_x                                  0x955D00
#define CStmlWnd__GetNextTagPiece_x                                0x95AAD0
#define CStmlWnd__GetSTMLText_x                                    0x502750
#define CStmlWnd__GetVisibleText_x                                 0x955D20
#define CStmlWnd__InitializeWindowVariables_x                      0x95B650
#define CStmlWnd__MakeStmlColorTag_x                               0x954DD0
#define CStmlWnd__MakeWndNotificationTag_x                         0x954E40
#define CStmlWnd__SetSTMLText_x                                    0x953E80
#define CStmlWnd__StripFirstSTMLLines_x                            0x95C900
#define CStmlWnd__UpdateHistoryString_x                            0x95BA10

// CTabWnd 
#define CTabWnd__Draw_x                                            0x952FD0
#define CTabWnd__DrawCurrentPage_x                                 0x953700
#define CTabWnd__DrawTab_x                                         0x953420
#define CTabWnd__GetCurrentPage_x                                  0x9527E0
#define CTabWnd__GetPageInnerRect_x                                0x952A20
#define CTabWnd__GetTabInnerRect_x                                 0x952960
#define CTabWnd__GetTabRect_x                                      0x952810
#define CTabWnd__InsertPage_x                                      0x952C30
#define CTabWnd__SetPage_x                                         0x952AA0
#define CTabWnd__SetPageRect_x                                     0x952F10
#define CTabWnd__UpdatePage_x                                      0x9532E0
#define CTabWnd__GetPageFromTabIndex_x                             0x953360
#define CTabWnd__GetCurrentTabIndex_x                              0x9527D0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x765A40
#define CPageWnd__SetTabText_x                                     0x952330

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8FB0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x929DE0
#define CTextureFont__GetTextExtent_x                              0x929FA0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B22D0
#define CHtmlComponentWnd__ValidateUri_x                           0x744290
#define CHtmlWnd__SetClientCallbacks_x                             0x61FAE0
#define CHtmlWnd__AddObserver_x                                    0x61FB00
#define CHtmlWnd__RemoveObserver_x                                 0x61FB60
#define Window__getProgress_x                                      0x85BD20
#define Window__getStatus_x                                        0x85BD40
#define Window__getURI_x                                           0x85BD50

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x967E90

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x916FA0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E85D0
#define CXStr__CXStr1_x                                            0x9EE250
#define CXStr__CXStr3_x                                            0x8F8EC0
#define CXStr__dCXStr_x                                            0x4786B0
#define CXStr__operator_equal_x                                    0x8F90F0
#define CXStr__operator_equal1_x                                   0x8F9130
#define CXStr__operator_plus_equal1_x                              0x8F9BC0
#define CXStr__SetString_x                                         0x8FBAB0
#define CXStr__operator_char_p_x                                   0x8F9600
#define CXStr__GetChar_x                                           0x8FB400
#define CXStr__Delete_x                                            0x8FACB0
#define CXStr__GetUnicode_x                                        0x8FB470
#define CXStr__GetLength_x                                         0x4A8D60
#define CXStr__Mid_x                                               0x47D490
#define CXStr__Insert_x                                            0x8FB4D0
#define CXStr__FindNext_x                                          0x8FB120

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x94B260
#define CXWnd__BringToTop_x                                        0x9306A0
#define CXWnd__Center_x                                            0x930220
#define CXWnd__ClrFocus_x                                          0x930040
#define CXWnd__Destroy_x                                           0x9300E0
#define CXWnd__DoAllDrawing_x                                      0x92C6D0
#define CXWnd__DrawChildren_x                                      0x92C6A0
#define CXWnd__DrawColoredRect_x                                   0x92CB10
#define CXWnd__DrawTooltip_x                                       0x92B1F0
#define CXWnd__DrawTooltipAtPoint_x                                0x92B2B0
#define CXWnd__GetBorderFrame_x                                    0x92C970
#define CXWnd__GetChildWndAt_x                                     0x930740
#define CXWnd__GetClientClipRect_x                                 0x92E940
#define CXWnd__GetScreenClipRect_x                                 0x92EA10
#define CXWnd__GetScreenRect_x                                     0x92EBE0
#define CXWnd__GetTooltipRect_x                                    0x92CB60
#define CXWnd__GetWindowTextA_x                                    0x9479B0
#define CXWnd__IsActive_x                                          0x92D270
#define CXWnd__IsDescendantOf_x                                    0x92F5A0
#define CXWnd__IsReallyVisible_x                                   0x92F5D0
#define CXWnd__IsType_x                                            0x930DA0
#define CXWnd__Move_x                                              0x92F640
#define CXWnd__Move1_x                                             0x92F6F0
#define CXWnd__ProcessTransition_x                                 0x9301D0
#define CXWnd__Refade_x                                            0x92F9C0
#define CXWnd__Resize_x                                            0x92FC50
#define CXWnd__Right_x                                             0x930460
#define CXWnd__SetFocus_x                                          0x930000
#define CXWnd__SetFont_x                                           0x930070
#define CXWnd__SetKeyTooltip_x                                     0x930BD0
#define CXWnd__SetMouseOver_x                                      0x92DAC0
#define CXWnd__StartFade_x                                         0x92F480
#define CXWnd__GetChildItem_x                                      0x9308B0
#define CXWnd__SetParent_x                                         0x92F380
#define CXWnd__Minimize_x                                          0x92FCC0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x963420

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x933660
#define CXWndManager__DrawWindows_x                                0x933680
#define CXWndManager__GetKeyboardFlags_x                           0x935D60
#define CXWndManager__HandleKeyboardMsg_x                          0x935920
#define CXWndManager__RemoveWnd_x                                  0x935FB0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x9364E0

// CDBStr
#define CDBStr__GetString_x                                        0x539850

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BB8E0
#define EQ_Character__Cur_HP_x                                     0x4D2000
#define EQ_Character__Cur_Mana_x                                   0x4D9760
#define EQ_Character__GetCastingTimeModifier_x                     0x4BE950
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2430
#define EQ_Character__GetFocusRangeModifier_x                      0x4B2580
#define EQ_Character__GetHPRegen_x                                 0x4DF530
#define EQ_Character__GetEnduranceRegen_x                          0x4DFB30
#define EQ_Character__GetManaRegen_x                               0x4DFF70
#define EQ_Character__Max_Endurance_x                              0x645DF0
#define EQ_Character__Max_HP_x                                     0x4D1E30
#define EQ_Character__Max_Mana_x                                   0x645BF0
#define EQ_Character__doCombatAbility_x                            0x648250
#define EQ_Character__UseSkill_x                                   0x4E1D50
#define EQ_Character__GetConLevel_x                                0x63EB10
#define EQ_Character__IsExpansionFlag_x                            0x5A2F50
#define EQ_Character__TotalEffect_x                                0x4C5390
#define EQ_Character__GetPCSpellAffect_x                           0x4BF6A0
#define EQ_Character__SpellDuration_x                              0x4BF1D0
#define EQ_Character__GetAdjustedSkill_x                           0x4D4D80
#define EQ_Character__GetBaseSkill_x                               0x4D5D20
#define EQ_Character__CanUseItem_x                                 0x4D9A70

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8C5F70

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x65C370

//PcClient
#define PcClient__PcClient_x                                       0x63C240

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B9550
#define CCharacterListWnd__EnterWorld_x                            0x4B8F90
#define CCharacterListWnd__Quit_x                                  0x4B8CE0
#define CCharacterListWnd__UpdateList_x                            0x4B9120

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x620D20
#define EQ_Item__CreateItemTagString_x                             0x8A0270
#define EQ_Item__IsStackable_x                                     0x8A4DF0
#define EQ_Item__GetImageNum_x                                     0x8A1D10
#define EQ_Item__CreateItemClient_x                                0x61FF00
#define EQ_Item__GetItemValue_x                                    0x8A3020
#define EQ_Item__ValueSellMerchant_x                               0x8A6600
#define EQ_Item__IsKeyRingItem_x                                   0x8A4720
#define EQ_Item__CanGoInBag_x                                      0x620E40
#define EQ_Item__IsEmpty_x                                         0x8A4250
#define EQ_Item__GetMaxItemCount_x                                 0x8A3430
#define EQ_Item__GetHeldItem_x                                     0x8A1BE0
#define EQ_Item__GetAugmentFitBySlot_x                             0x89FBF0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x557D30
#define EQ_LoadingS__Array_x                                       0xC21B58

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x646750
#define EQ_PC__GetAlternateAbilityId_x                             0x8AF7F0
#define EQ_PC__GetCombatAbility_x                                  0x8AFE60
#define EQ_PC__GetCombatAbilityTimer_x                             0x8AFED0
#define EQ_PC__GetItemRecastTimer_x                                0x6487D0
#define EQ_PC__HasLoreItem_x                                       0x63F2D0
#define EQ_PC__AlertInventoryChanged_x                             0x63E440
#define EQ_PC__GetPcZoneClient_x                                   0x66AD70
#define EQ_PC__RemoveMyAffect_x                                    0x64BA00
#define EQ_PC__GetKeyRingItems_x                                   0x8B0760
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B04F0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B0A60

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5A94C0
#define EQItemList__add_object_x                                   0x5D6430
#define EQItemList__add_item_x                                     0x5A9A20
#define EQItemList__delete_item_x                                  0x5A9A70
#define EQItemList__FreeItemList_x                                 0x5A9970

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x5362D0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x65DBF0
#define EQPlayer__dEQPlayer_x                                      0x650F40
#define EQPlayer__DoAttack_x                                       0x665A20
#define EQPlayer__EQPlayer_x                                       0x651600
#define EQPlayer__SetNameSpriteState_x                             0x6558D0
#define EQPlayer__SetNameSpriteTint_x                              0x6567A0
#define PlayerBase__HasProperty_j_x                                0x995D90
#define EQPlayer__IsTargetable_x                                   0x996230
#define EQPlayer__CanSee_x                                         0x996090
#define EQPlayer__CanSee1_x                                        0x996160
#define PlayerBase__GetVisibilityLineSegment_x                     0x995E50

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x668800
#define PlayerZoneClient__GetLevel_x                               0x66ADB0
#define PlayerZoneClient__IsValidTeleport_x                        0x5D75A0
#define PlayerZoneClient__LegalPlayerRace_x                        0x551120

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x660930
#define EQPlayerManager__GetSpawnByName_x                          0x6609E0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x660A70

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x624410
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x624490
#define KeypressHandler__AttachKeyToEqCommand_x                    0x6244D0
#define KeypressHandler__ClearCommandStateArray_x                  0x6258E0
#define KeypressHandler__HandleKeyDown_x                           0x625900
#define KeypressHandler__HandleKeyUp_x                             0x6259A0
#define KeypressHandler__SaveKeymapping_x                          0x625DF0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x77C690
#define MapViewMap__SaveEx_x                                       0x77FA50
#define MapViewMap__SetZoom_x                                      0x784100

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C3E90

// StringTable 
#define StringTable__getString_x                                   0x8BEB50

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x64B670
#define PcZoneClient__RemovePetEffect_x                            0x64BCA0
#define PcZoneClient__HasAlternateAbility_x                        0x645A20
#define PcZoneClient__GetCurrentMod_x                              0x4E4E10
#define PcZoneClient__GetModCap_x                                  0x4E4D10
#define PcZoneClient__CanEquipItem_x                               0x6460F0
#define PcZoneClient__GetItemByID_x                                0x648C40
#define PcZoneClient__GetItemByItemClass_x                         0x648D90
#define PcZoneClient__RemoveBuffEffect_x                           0x64BCC0
#define PcZoneClient__BandolierSwap_x                              0x646D10
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x648770

//Doors
#define EQSwitch__UseSwitch_x                                      0x5DC120

//IconCache
#define IconCache__GetIcon_x                                       0x71CBA0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x7146B0
#define CContainerMgr__CloseContainer_x                            0x714980
#define CContainerMgr__OpenExperimentContainer_x                   0x715400

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D4620

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x618E80

//CLootWnd
#define CLootWnd__LootAll_x                                        0x772B10
#define CLootWnd__RequestLootSlot_x                                0x771D40

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x576C20
#define EQ_Spell__SpellAffects_x                                   0x577090
#define EQ_Spell__SpellAffectBase_x                                0x576E50
#define EQ_Spell__IsStackable_x                                    0x4C9A30
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9880
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6900
#define EQ_Spell__IsSPAStacking_x                                  0x577EE0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x5773F0
#define EQ_Spell__IsNoRemove_x                                     0x4C9A10
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x577EF0
#define __IsResEffectSpell_x                                       0x4C8DB0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD080

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8CE520

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x81B380
#define CTargetWnd__WndNotification_x                              0x81AC10
#define CTargetWnd__RefreshTargetBuffs_x                           0x81AEE0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x819D80

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x81F980

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x533D10
#define CTaskManager__HandleMessage_x                              0x5321B0
#define CTaskManager__GetTaskStatus_x                              0x533DC0
#define CTaskManager__GetElementDescription_x                      0x533E40

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x572190
#define EqSoundManager__PlayScriptMp3_x                            0x5722F0
#define EqSoundManager__SoundAssistPlay_x                          0x682F70
#define EqSoundManager__WaveInstancePlay_x                         0x6824E0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x527A70

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x951840

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x55F6F0
#define CAltAbilityData__GetMercMaxRank_x                          0x55F680
#define CAltAbilityData__GetMaxRank_x                              0x554E10

//CTargetRing
#define CTargetRing__Cast_x                                        0x616FA0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9860
#define CharacterBase__CreateItemGlobalIndex_x                     0x50F330
#define CharacterBase__CreateItemIndex_x                           0x61F0A0
#define CharacterBase__GetItemPossession_x                         0x4FB1D0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8D6B20
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8D6B80
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6FB840
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6FC070
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6FC120

//messages
#define msg_spell_worn_off_x                                       0x59B260
#define msg_new_text_x                                             0x590000
#define __msgTokenTextParam_x                                      0x59D780
#define msgTokenText_x                                             0x59D9D0

//SpellManager
#define SpellManager__vftable_x                                    0xAE721C
#define SpellManager__SpellManager_x                               0x6862A0
#define Spellmanager__LoadTextSpells_x                             0x686B90
#define SpellManager__GetSpellByGroupAndRank_x                     0x686470

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x999D60

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x50F9B0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A1520
#define ItemGlobalIndex__IsEquippedLocation_x                      0x637A10
#define ItemGlobalIndex__IsValidIndex_x                            0x50FA10

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8CEEC0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8CF140

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x76B380

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x718DB0
#define CCursorAttachment__AttachToCursor1_x                       0x718DF0
#define CCursorAttachment__Deactivate_x                            0x719DD0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x944650
#define CSidlManagerBase__CreatePageWnd_x                          0x943E70
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x940120
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x9400B0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9616F0
#define CEQSuiteTextureLoader__GetTexture_x                        0x9613B0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50C900
#define CFindItemWnd__WndNotification_x                            0x50D3E0
#define CFindItemWnd__Update_x                                     0x50DF20
#define CFindItemWnd__PickupSelectedItem_x                         0x50C150

//IString
#define IString__Append_x                                          0x4FCA40

//Camera
#define CDisplay__cameraType_x                                     0xDFB51C
#define EverQuest__Cameras_x                                       0xEBEA54

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x515070
#define LootFiltersManager__GetItemFilterData_x                    0x514970
#define LootFiltersManager__RemoveItemLootFilter_x                 0x5149A0
#define LootFiltersManager__SetItemLootFilter_x                    0x514BC0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C2630

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x99F9D0
#define CResolutionHandler__GetWindowedStyle_x                     0x67DA80

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x711400

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E33C0
#define CDistillerInfo__Instance_x                                 0x8E3360

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x731660
#define CGroupWnd__UpdateDisplay_x                                 0x7309C0

//ItemBase
#define ItemBase__IsLore_x                                         0x8A47C0
#define ItemBase__IsLoreEquipped_x                                 0x8A4830

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5D6390
#define EQPlacedItemManager__GetItemByGuid_x                       0x5D64D0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5D6530

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x673480
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x676DF0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x502D50

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F18B0
#define FactionManagerClient__HandleFactionMessage_x               0x4F1F20
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F24E0
#define FactionManagerClient__GetMaxFaction_x                      0x4F24FF
#define FactionManagerClient__GetMinFaction_x                      0x4F24B0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FB1A0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x928E00

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BE10

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FB450

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x55EB90

//CTargetManager
#define CTargetManager__Get_x                                      0x689B20

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x673480

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8D70

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5A9910

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF5C0E8

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
