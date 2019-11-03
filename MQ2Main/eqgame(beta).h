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
#define __ExpectedVersionDate                                     "Nov  3 2019"
#define __ExpectedVersionTime                                     "03:41:53"
#define __ActualVersionDate_x                                      0xB03F10
#define __ActualVersionTime_x                                      0xB03F04
#define __ActualVersionBuild_x                                     0xAEFBEC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x62B500
#define __MemChecker1_x                                            0x8FDCB0
#define __MemChecker2_x                                            0x6B98F0
#define __MemChecker3_x                                            0x6B9840
#define __MemChecker4_x                                            0x855720
#define __EncryptPad0_x                                            0xC3A3E0
#define __EncryptPad1_x                                            0xC985A0
#define __EncryptPad2_x                                            0xC4AC78
#define __EncryptPad3_x                                            0xC4A878
#define __EncryptPad4_x                                            0xC88BF8
#define __EncryptPad5_x                                            0xF61CDC
#define __AC1_x                                                    0x812186
#define __AC2_x                                                    0x5E537F
#define __AC3_x                                                    0x5ECA7F
#define __AC4_x                                                    0x5F0A50
#define __AC5_x                                                    0x5F6D5F
#define __AC6_x                                                    0x5FB376
#define __AC7_x                                                    0x5E4DF0
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
#define __do_loot_x                                                0x5B1620
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
#define __gfMaxCameraDistance_x                                    0xB25DB0
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
#define __CastRay_x                                                0x5ACA80
#define __CastRay2_x                                               0x5ACAD0
#define __ConvertItemTags_x                                        0x5C8620
#define __CleanItemTags_x                                          0x47CF50
#define __DoesFileExist_x                                          0x900D40
#define __EQGetTime_x                                              0x8FD780
#define __ExecuteCmd_x                                             0x5A5330
#define __FixHeading_x                                             0x997BE0
#define __GameLoop_x                                               0x6B8AE0
#define __get_bearing_x                                            0x5AC5F0
#define __get_melee_range_x                                        0x5ACCC0
#define __GetAnimationCache_x                                      0x71DD00
#define __GetGaugeValueFromEQ_x                                    0x810630
#define __GetLabelFromEQ_x                                         0x812110
#define __GetXTargetType_x                                         0x999630
#define __HandleMouseWheel_x                                       0x6B99A0
#define __HeadingDiff_x                                            0x997C50
#define __HelpPath_x                                               0xF5C7B4
#define __LoadFrontEnd_x                                           0x6B5E00
#define __NewUIINI_x                                               0x810300
#define __ProcessGameEvents_x                                      0x60CBF0
#define __ProcessMouseEvent_x                                      0x60C3B0
#define __SaveColors_x                                             0x54FC20
#define __STMLToText_x                                             0x93AF10
#define __ToggleKeyRingItem_x                                      0x512E60
#define CMemoryMappedFile__SetFile_x                               0xA87060
#define CrashDetected_x                                            0x6B78A0
#define DrawNetStatus_x                                            0x638660
#define Expansion_HoT_x                                            0xEBE704
#define Teleport_Table_Size_x                                      0xEAD640
#define Teleport_Table_x                                           0xEADB10
#define Util__FastTime_x                                           0x8FD350

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490190
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499090
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x498E60
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493730
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492B80

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x5578E0
#define AltAdvManager__IsAbilityReady_x                            0x556810
#define AltAdvManager__GetAAById_x                                 0x556A10
#define AltAdvManager__CanTrainAbility_x                           0x556A80
#define AltAdvManager__CanSeeAbility_x                             0x556DE0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA150
#define CharacterZoneClient__HasSkill_x                            0x4D5040
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6760
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE430
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BAA30
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D90F0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D91D0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D92B0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C3220
#define CharacterZoneClient__BardCastBard_x                        0x4C5D80
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAB00
#define CharacterZoneClient__GetEffect_x                           0x4BA970
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C4270
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C4340
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C4390
#define CharacterZoneClient__CalcAffectChange_x                    0x4C44E0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C46B0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2900
#define CharacterZoneClient__FindItemByGuid_x                      0x4D76C0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7140

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6DF4A0
#define CBankWnd__WndNotification_x                                0x6DF280

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6ECB40

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x61B270
#define CButtonWnd__CButtonWnd_x                                   0x937320

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x70CE80
#define CChatManager__InitContextMenu_x                            0x705FD0
#define CChatManager__FreeChatWindow_x                             0x70B9C0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E86B0
#define CChatManager__SetLockedActiveChatWindow_x                  0x70CB00
#define CChatManager__CreateChatWindow_x                           0x70C000

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E87C0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x94B8E0
#define CContextMenu__dCContextMenu_x                              0x94BB20
#define CContextMenu__AddMenuItem_x                                0x94BB30
#define CContextMenu__RemoveMenuItem_x                             0x94BE40
#define CContextMenu__RemoveAllMenuItems_x                         0x94BE60
#define CContextMenu__CheckMenuItem_x                              0x94BEE0
#define CContextMenu__SetMenuItem_x                                0x94BD60
#define CContextMenu__AddSeparator_x                               0x94BCC0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x94C480
#define CContextMenuManager__RemoveMenu_x                          0x94C4F0
#define CContextMenuManager__PopupMenu_x                           0x94C5B0
#define CContextMenuManager__Flush_x                               0x94C420
#define CContextMenuManager__GetMenu_x                             0x49B380
#define CContextMenuManager__CreateDefaultMenu_x                   0x7184F0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D9C60
#define CChatService__GetFriendName_x                              0x8D9C70

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x70D6F0
#define CChatWindow__Clear_x                                       0x70E9C0
#define CChatWindow__WndNotification_x                             0x70F150
#define CChatWindow__AddHistory_x                                  0x70E280

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x948D40
#define CComboWnd__Draw_x                                          0x948230
#define CComboWnd__GetCurChoice_x                                  0x948B80
#define CComboWnd__GetListRect_x                                   0x9486E0
#define CComboWnd__GetTextRect_x                                   0x948DB0
#define CComboWnd__InsertChoice_x                                  0x948870
#define CComboWnd__SetColors_x                                     0x948840
#define CComboWnd__SetChoice_x                                     0x948B50
#define CComboWnd__GetItemCount_x                                  0x948B90
#define CComboWnd__GetCurChoiceText_x                              0x948BD0
#define CComboWnd__GetChoiceText_x                                 0x948BA0
#define CComboWnd__InsertChoiceAtIndex_x                           0x948910

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x715EF0
#define CContainerWnd__vftable_x                                   0xB0D0EC
#define CContainerWnd__SetContainer_x                              0x717450

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54A660
#define CDisplay__PreZoneMainUI_x                                  0x54A670
#define CDisplay__CleanGameUI_x                                    0x54F9E0
#define CDisplay__GetClickedActor_x                                0x542980
#define CDisplay__GetUserDefinedColor_x                            0x53B040
#define CDisplay__GetWorldFilePath_x                               0x5443F0
#define CDisplay__is3dON_x                                         0x53F5E0
#define CDisplay__ReloadUI_x                                       0x549AF0
#define CDisplay__WriteTextHD2_x                                   0x53F3D0
#define CDisplay__TrueDistance_x                                   0x5460B0
#define CDisplay__SetViewActor_x                                   0x5422A0
#define CDisplay__GetFloorHeight_x                                 0x53F6A0
#define CDisplay__SetRenderWindow_x                                0x53E000
#define CDisplay__ToggleScreenshotMode_x                           0x541D70

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x96B5A0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x94EE50
#define CEditWnd__GetCharIndexPt_x                                 0x94FD80
#define CEditWnd__GetDisplayString_x                               0x94FC20
#define CEditWnd__GetHorzOffset_x                                  0x94E480
#define CEditWnd__GetLineForPrintableChar_x                        0x950F20
#define CEditWnd__GetSelStartPt_x                                  0x950030
#define CEditWnd__GetSTMLSafeText_x                                0x94FA40
#define CEditWnd__PointFromPrintableChar_x                         0x950B50
#define CEditWnd__SelectableCharFromPoint_x                        0x950CC0
#define CEditWnd__SetEditable_x                                    0x950100
#define CEditWnd__SetWindowTextA_x                                 0x94F7C0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5FA850
#define CEverQuest__ClickedPlayer_x                                0x5EC860
#define CEverQuest__CreateTargetIndicator_x                        0x609E80
#define CEverQuest__DeleteTargetIndicator_x                        0x609F10
#define CEverQuest__DoTellWindow_x                                 0x4E88A0
#define CEverQuest__OutputTextToLog_x                              0x4E8B20
#define CEverQuest__DropHeldItemOnGround_x                         0x5E18A0
#define CEverQuest__dsp_chat_x                                     0x4E8EB0
#define CEverQuest__trimName_x                                     0x606160
#define CEverQuest__Emote_x                                        0x5FB0B0
#define CEverQuest__EnterZone_x                                    0x5F5030
#define CEverQuest__GetBodyTypeDesc_x                              0x5FFA20
#define CEverQuest__GetClassDesc_x                                 0x600060
#define CEverQuest__GetClassThreeLetterCode_x                      0x600660
#define CEverQuest__GetDeityDesc_x                                 0x6087C0
#define CEverQuest__GetLangDesc_x                                  0x600820
#define CEverQuest__GetRaceDesc_x                                  0x600040
#define CEverQuest__InterpretCmd_x                                 0x608D90
#define CEverQuest__LeftClickedOnPlayer_x                          0x5E5AA0
#define CEverQuest__LMouseUp_x                                     0x5E3E30
#define CEverQuest__RightClickedOnPlayer_x                         0x5E6380
#define CEverQuest__RMouseUp_x                                     0x5E4DB0
#define CEverQuest__SetGameState_x                                 0x5E1630
#define CEverQuest__UPCNotificationFlush_x                         0x606060
#define CEverQuest__IssuePetCommand_x                              0x601C20
#define CEverQuest__ReportSuccessfulHit_x                          0x5FC4A0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x727D70
#define CGaugeWnd__CalcLinesFillRect_x                             0x727DD0
#define CGaugeWnd__Draw_x                                          0x7273F0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF3E0
#define CGuild__GetGuildName_x                                     0x4AE4C0
#define CGuild__GetGuildIndex_x                                    0x4AE850

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x7431D0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x61B630

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x750220
#define CInvSlotMgr__MoveItem_x                                    0x74EF40
#define CInvSlotMgr__SelectSlot_x                                  0x7502F0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x74D7B0
#define CInvSlot__SliderComplete_x                                 0x74B500
#define CInvSlot__GetItemBase_x                                    0x74AE70
#define CInvSlot__UpdateItem_x                                     0x74AFE0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x751D70
#define CInvSlotWnd__CInvSlotWnd_x                                 0x750F10
#define CInvSlotWnd__HandleLButtonUp_x                             0x7518F0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x80B940
#define CItemDisplayWnd__UpdateStrings_x                           0x760500
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75A1D0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x75A700
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x760B10
#define CItemDisplayWnd__AboutToShow_x                             0x760150
#define CItemDisplayWnd__WndNotification_x                         0x761C00
#define CItemDisplayWnd__RequestConvertItem_x                      0x7616C0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x75F1B0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x75FF70

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8443A0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x766140

// CLabel 
#define CLabel__Draw_x                                             0x76BB90

// CListWnd
#define CListWnd__CListWnd_x                                       0x921570
#define CListWnd__dCListWnd_x                                      0x921890
#define CListWnd__AddColumn_x                                      0x925CE0
#define CListWnd__AddColumn1_x                                     0x925D30
#define CListWnd__AddLine_x                                        0x9260C0
#define CListWnd__AddString_x                                      0x925EC0
#define CListWnd__CalculateFirstVisibleLine_x                      0x925AA0
#define CListWnd__CalculateVSBRange_x                              0x925880
#define CListWnd__ClearSel_x                                       0x9268A0
#define CListWnd__ClearAllSel_x                                    0x926900
#define CListWnd__CloseAndUpdateEditWindow_x                       0x927320
#define CListWnd__Compare_x                                        0x9251B0
#define CListWnd__Draw_x                                           0x9219C0
#define CListWnd__DrawColumnSeparators_x                           0x924190
#define CListWnd__DrawHeader_x                                     0x9245F0
#define CListWnd__DrawItem_x                                       0x924AF0
#define CListWnd__DrawLine_x                                       0x9242F0
#define CListWnd__DrawSeparator_x                                  0x924230
#define CListWnd__EnableLine_x                                     0x923A80
#define CListWnd__EnsureVisible_x                                  0x927240
#define CListWnd__ExtendSel_x                                      0x9267D0
#define CListWnd__GetColumnTooltip_x                               0x9235C0
#define CListWnd__GetColumnMinWidth_x                              0x923630
#define CListWnd__GetColumnWidth_x                                 0x923530
#define CListWnd__GetCurSel_x                                      0x922EC0
#define CListWnd__GetItemAtPoint_x                                 0x923CF0
#define CListWnd__GetItemAtPoint1_x                                0x923D60
#define CListWnd__GetItemData_x                                    0x922F40
#define CListWnd__GetItemHeight_x                                  0x923300
#define CListWnd__GetItemIcon_x                                    0x9230D0
#define CListWnd__GetItemRect_x                                    0x923B70
#define CListWnd__GetItemText_x                                    0x922F80
#define CListWnd__GetSelList_x                                     0x926950
#define CListWnd__GetSeparatorRect_x                               0x923FA0
#define CListWnd__InsertLine_x                                     0x9264B0
#define CListWnd__RemoveLine_x                                     0x926600
#define CListWnd__SetColors_x                                      0x925850
#define CListWnd__SetColumnJustification_x                         0x925580
#define CListWnd__SetColumnWidth_x                                 0x9254A0
#define CListWnd__SetCurSel_x                                      0x926710
#define CListWnd__SetItemColor_x                                   0x926EF0
#define CListWnd__SetItemData_x                                    0x926EB0
#define CListWnd__SetItemText_x                                    0x926AC0
#define CListWnd__ShiftColumnSeparator_x                           0x925640
#define CListWnd__Sort_x                                           0x925330
#define CListWnd__ToggleSel_x                                      0x926740
#define CListWnd__SetColumnsSizable_x                              0x9256F0
#define CListWnd__SetItemWnd_x                                     0x926D70
#define CListWnd__GetItemWnd_x                                     0x923120
#define CListWnd__SetItemIcon_x                                    0x926B40
#define CListWnd__CalculateCustomWindowPositions_x                 0x925BA0
#define CListWnd__SetVScrollPos_x                                  0x925480

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x781250
#define CMapViewWnd__GetWorldCoordinates_x                         0x77F960
#define CMapViewWnd__HandleLButtonDown_x                           0x77C9A0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A13F0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A1CD0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A2200
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A5180
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x79FF60
#define CMerchantWnd__SelectBuySellSlot_x                          0x7AAD30
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A1000

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8A74E0
#define CPacketScrambler__hton_x                                   0x8A74D0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x940510
#define CSidlManager__FindScreenPieceTemplate_x                    0x940920
#define CSidlManager__FindScreenPieceTemplate1_x                   0x940710
#define CSidlManager__CreateLabel_x                                0x802D80
#define CSidlManager__CreateXWndFromTemplate_x                     0x943880
#define CSidlManager__CreateXWndFromTemplate1_x                    0x943A60
#define CSidlManager__CreateXWnd_x                                 0x802CB0
#define CSidlManager__CreateHotButtonWnd_x                         0x803270

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x93D010
#define CSidlScreenWnd__CalculateVSBRange_x                        0x93CF10
#define CSidlScreenWnd__ConvertToRes_x                             0x9625F0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x93C9A0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x93C690
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x93C760
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x93C830
#define CSidlScreenWnd__DrawSidlPiece_x                            0x93D490
#define CSidlScreenWnd__EnableIniStorage_x                         0x93D960
#define CSidlScreenWnd__GetSidlPiece_x                             0x93D680
#define CSidlScreenWnd__Init1_x                                    0x93C2B0
#define CSidlScreenWnd__LoadIniInfo_x                              0x93D9B0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x93E4F0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x93B6C0
#define CSidlScreenWnd__StoreIniInfo_x                             0x93E070
#define CSidlScreenWnd__StoreIniVis_x                              0x93E3D0
#define CSidlScreenWnd__WndNotification_x                          0x93D3A0
#define CSidlScreenWnd__GetChildItem_x                             0x93D8E0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x92D0E0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15F2F28

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x67FC10
#define CSkillMgr__GetSkillCap_x                                   0x67FDF0
#define CSkillMgr__GetNameToken_x                                  0x67F390
#define CSkillMgr__IsActivatedSkill_x                              0x67F4D0
#define CSkillMgr__IsCombatSkill_x                                 0x67F410

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x94D260
#define CSliderWnd__SetValue_x                                     0x94D0D0
#define CSliderWnd__SetNumTicks_x                                  0x94D130

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x808DD0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x955A80
#define CStmlWnd__CalculateHSBRange_x                              0x956BA0
#define CStmlWnd__CalculateVSBRange_x                              0x956B10
#define CStmlWnd__CanBreakAtCharacter_x                            0x95AED0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x95BB60
#define CStmlWnd__ForceParseNow_x                                  0x956070
#define CStmlWnd__GetNextTagPiece_x                                0x95AE30
#define CStmlWnd__GetSTMLText_x                                    0x5027A0
#define CStmlWnd__GetVisibleText_x                                 0x956090
#define CStmlWnd__InitializeWindowVariables_x                      0x95B9B0
#define CStmlWnd__MakeStmlColorTag_x                               0x9550F0
#define CStmlWnd__MakeWndNotificationTag_x                         0x955160
#define CStmlWnd__SetSTMLText_x                                    0x9541A0
#define CStmlWnd__StripFirstSTMLLines_x                            0x95CC30
#define CStmlWnd__UpdateHistoryString_x                            0x95BD70

// CTabWnd 
#define CTabWnd__Draw_x                                            0x9532E0
#define CTabWnd__DrawCurrentPage_x                                 0x953A10
#define CTabWnd__DrawTab_x                                         0x953730
#define CTabWnd__GetCurrentPage_x                                  0x952AE0
#define CTabWnd__GetPageInnerRect_x                                0x952D20
#define CTabWnd__GetTabInnerRect_x                                 0x952C60
#define CTabWnd__GetTabRect_x                                      0x952B10
#define CTabWnd__InsertPage_x                                      0x952F30
#define CTabWnd__SetPage_x                                         0x952DA0
#define CTabWnd__SetPageRect_x                                     0x953220
#define CTabWnd__UpdatePage_x                                      0x9535F0
#define CTabWnd__GetPageFromTabIndex_x                             0x953670
#define CTabWnd__GetCurrentTabIndex_x                              0x952AD0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x766510
#define CPageWnd__SetTabText_x                                     0x952630

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A90D0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x929F70
#define CTextureFont__GetTextExtent_x                              0x92A130

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B29E0
#define CHtmlComponentWnd__ValidateUri_x                           0x744BC0
#define CHtmlWnd__SetClientCallbacks_x                             0x6206C0
#define CHtmlWnd__AddObserver_x                                    0x6206E0
#define CHtmlWnd__RemoveObserver_x                                 0x620740
#define Window__getProgress_x                                      0x85CD80
#define Window__getStatus_x                                        0x85CDA0
#define Window__getURI_x                                           0x85CDB0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x968030

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x9172F0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E84F0
#define CXStr__CXStr1_x                                            0x481430
#define CXStr__CXStr3_x                                            0x8F98C0
#define CXStr__dCXStr_x                                            0x478680
#define CXStr__operator_equal_x                                    0x8F9AF0
#define CXStr__operator_equal1_x                                   0x8F9B30
#define CXStr__operator_plus_equal1_x                              0x8FA5C0
#define CXStr__SetString_x                                         0x8FC4B0
#define CXStr__operator_char_p_x                                   0x8FA030
#define CXStr__GetChar_x                                           0x8FBE00
#define CXStr__Delete_x                                            0x8FB6B0
#define CXStr__GetUnicode_x                                        0x8FBE70
#define CXStr__GetLength_x                                         0x4A8E80
#define CXStr__Mid_x                                               0x47D300
#define CXStr__Insert_x                                            0x8FBED0
#define CXStr__FindNext_x                                          0x8FBB20

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x94B500
#define CXWnd__BringToTop_x                                        0x930810
#define CXWnd__Center_x                                            0x930390
#define CXWnd__ClrFocus_x                                          0x9301B0
#define CXWnd__Destroy_x                                           0x930250
#define CXWnd__DoAllDrawing_x                                      0x92C870
#define CXWnd__DrawChildren_x                                      0x92C840
#define CXWnd__DrawColoredRect_x                                   0x92CCD0
#define CXWnd__DrawTooltip_x                                       0x92B380
#define CXWnd__DrawTooltipAtPoint_x                                0x92B440
#define CXWnd__GetBorderFrame_x                                    0x92CB30
#define CXWnd__GetChildWndAt_x                                     0x9308B0
#define CXWnd__GetClientClipRect_x                                 0x92EA90
#define CXWnd__GetScreenClipRect_x                                 0x92EB60
#define CXWnd__GetScreenRect_x                                     0x92ED20
#define CXWnd__GetTooltipRect_x                                    0x92CD20
#define CXWnd__GetWindowTextA_x                                    0x49CB30
#define CXWnd__IsActive_x                                          0x92D450
#define CXWnd__IsDescendantOf_x                                    0x92F6F0
#define CXWnd__IsReallyVisible_x                                   0x92F720
#define CXWnd__IsType_x                                            0x930F30
#define CXWnd__Move_x                                              0x92F780
#define CXWnd__Move1_x                                             0x92F830
#define CXWnd__ProcessTransition_x                                 0x930340
#define CXWnd__Refade_x                                            0x92FB10
#define CXWnd__Resize_x                                            0x92FDE0
#define CXWnd__Right_x                                             0x9305D0
#define CXWnd__SetFocus_x                                          0x930170
#define CXWnd__SetFont_x                                           0x9301E0
#define CXWnd__SetKeyTooltip_x                                     0x930D40
#define CXWnd__SetMouseOver_x                                      0x92DC60
#define CXWnd__StartFade_x                                         0x92F5D0
#define CXWnd__GetChildItem_x                                      0x930A20
#define CXWnd__SetParent_x                                         0x92F4D0
#define CXWnd__Minimize_x                                          0x92FE50

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x963670

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9337A0
#define CXWndManager__DrawWindows_x                                0x9337C0
#define CXWndManager__GetKeyboardFlags_x                           0x935FB0
#define CXWndManager__HandleKeyboardMsg_x                          0x935B60
#define CXWndManager__RemoveWnd_x                                  0x936200
#define CXWndManager__RemovePendingDeletionWnd_x                   0x936760

// CDBStr
#define CDBStr__GetString_x                                        0x539FD0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BBA10
#define EQ_Character__Cur_HP_x                                     0x4D2080
#define EQ_Character__Cur_Mana_x                                   0x4D97B0
#define EQ_Character__GetCastingTimeModifier_x                     0x4BEA80
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2540
#define EQ_Character__GetFocusRangeModifier_x                      0x4B2690
#define EQ_Character__GetHPRegen_x                                 0x4DF580
#define EQ_Character__GetEnduranceRegen_x                          0x4DFB80
#define EQ_Character__GetManaRegen_x                               0x4DFFC0
#define EQ_Character__Max_Endurance_x                              0x646300
#define EQ_Character__Max_HP_x                                     0x4D1EB0
#define EQ_Character__Max_Mana_x                                   0x646100
#define EQ_Character__doCombatAbility_x                            0x648750
#define EQ_Character__UseSkill_x                                   0x4E1D90
#define EQ_Character__GetConLevel_x                                0x63F5F0
#define EQ_Character__IsExpansionFlag_x                            0x5A3AC0
#define EQ_Character__TotalEffect_x                                0x4C54C0
#define EQ_Character__GetPCSpellAffect_x                           0x4BF7D0
#define EQ_Character__SpellDuration_x                              0x4BF300
#define EQ_Character__GetAdjustedSkill_x                           0x4D4E00
#define EQ_Character__GetBaseSkill_x                               0x4D5DA0
#define EQ_Character__CanUseItem_x                                 0x4D9AC0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8C6B80

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x65C860

//PcClient
#define PcClient__PcClient_x                                       0x63CD30

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B9670
#define CCharacterListWnd__EnterWorld_x                            0x4B90B0
#define CCharacterListWnd__Quit_x                                  0x4B8E00
#define CCharacterListWnd__UpdateList_x                            0x4B9240

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6218F0
#define EQ_Item__CreateItemTagString_x                             0x8A0D30
#define EQ_Item__IsStackable_x                                     0x8A58B0
#define EQ_Item__GetImageNum_x                                     0x8A27B0
#define EQ_Item__CreateItemClient_x                                0x620AC0
#define EQ_Item__GetItemValue_x                                    0x8A3AB0
#define EQ_Item__ValueSellMerchant_x                               0x8A70C0
#define EQ_Item__IsKeyRingItem_x                                   0x8A51E0
#define EQ_Item__CanGoInBag_x                                      0x621A10
#define EQ_Item__IsEmpty_x                                         0x8A4D10
#define EQ_Item__GetMaxItemCount_x                                 0x8A3EC0
#define EQ_Item__GetHeldItem_x                                     0x8A2680
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A06B0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x5585B0
#define EQ_LoadingS__Array_x                                       0xC21B58

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x646C60
#define EQ_PC__GetAlternateAbilityId_x                             0x8B0390
#define EQ_PC__GetCombatAbility_x                                  0x8B0A00
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B0A70
#define EQ_PC__GetItemRecastTimer_x                                0x648CD0
#define EQ_PC__HasLoreItem_x                                       0x63FDB0
#define EQ_PC__AlertInventoryChanged_x                             0x63EF30
#define EQ_PC__GetPcZoneClient_x                                   0x66B360
#define EQ_PC__RemoveMyAffect_x                                    0x64BF00
#define EQ_PC__GetKeyRingItems_x                                   0x8B1300
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B1090
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B1600

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5AA060
#define EQItemList__add_object_x                                   0x5D7020
#define EQItemList__add_item_x                                     0x5AA5C0
#define EQItemList__delete_item_x                                  0x5AA610
#define EQItemList__FreeItemList_x                                 0x5AA510

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x536AE0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x65E0E0
#define EQPlayer__dEQPlayer_x                                      0x651440
#define EQPlayer__DoAttack_x                                       0x666020
#define EQPlayer__EQPlayer_x                                       0x651B00
#define EQPlayer__SetNameSpriteState_x                             0x655DC0
#define EQPlayer__SetNameSpriteTint_x                              0x656C90
#define PlayerBase__HasProperty_j_x                                0x995FC0
#define EQPlayer__IsTargetable_x                                   0x996460
#define EQPlayer__CanSee_x                                         0x9962C0
#define EQPlayer__CanSee1_x                                        0x996390
#define PlayerBase__GetVisibilityLineSegment_x                     0x996080

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x668E00
#define PlayerZoneClient__GetLevel_x                               0x66B3A0
#define PlayerZoneClient__IsValidTeleport_x                        0x5D8190
#define PlayerZoneClient__LegalPlayerRace_x                        0x5518D0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x660F30
#define EQPlayerManager__GetSpawnByName_x                          0x660FE0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x661070

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x625010
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x625090
#define KeypressHandler__AttachKeyToEqCommand_x                    0x6250D0
#define KeypressHandler__ClearCommandStateArray_x                  0x6264E0
#define KeypressHandler__HandleKeyDown_x                           0x626500
#define KeypressHandler__HandleKeyUp_x                             0x6265A0
#define KeypressHandler__SaveKeymapping_x                          0x6269F0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x77D0C0
#define MapViewMap__SaveEx_x                                       0x780480
#define MapViewMap__SetZoom_x                                      0x784B40

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C4AA0

// StringTable 
#define StringTable__getString_x                                   0x8BF700

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x64BB70
#define PcZoneClient__RemovePetEffect_x                            0x64C1A0
#define PcZoneClient__HasAlternateAbility_x                        0x645F30
#define PcZoneClient__GetCurrentMod_x                              0x4E4E50
#define PcZoneClient__GetModCap_x                                  0x4E4D50
#define PcZoneClient__CanEquipItem_x                               0x646600
#define PcZoneClient__GetItemByID_x                                0x649140
#define PcZoneClient__GetItemByItemClass_x                         0x649290
#define PcZoneClient__RemoveBuffEffect_x                           0x64C1C0
#define PcZoneClient__BandolierSwap_x                              0x647210
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x648C70

//Doors
#define EQSwitch__UseSwitch_x                                      0x5DCD10

//IconCache
#define IconCache__GetIcon_x                                       0x71D5A0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x715090
#define CContainerMgr__CloseContainer_x                            0x715360
#define CContainerMgr__OpenExperimentContainer_x                   0x715DE0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D5280

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x619A40

//CLootWnd
#define CLootWnd__LootAll_x                                        0x773660
#define CLootWnd__RequestLootSlot_x                                0x772890

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x577530
#define EQ_Spell__SpellAffects_x                                   0x5779A0
#define EQ_Spell__SpellAffectBase_x                                0x577760
#define EQ_Spell__IsStackable_x                                    0x4C9AA0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C98F0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6A10
#define EQ_Spell__IsSPAStacking_x                                  0x5787F0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x577D00
#define EQ_Spell__IsNoRemove_x                                     0x4C9A80
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x578800
#define __IsResEffectSpell_x                                       0x4C8F00

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD100

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8CF0F0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x81C140
#define CTargetWnd__WndNotification_x                              0x81B9D0
#define CTargetWnd__RefreshTargetBuffs_x                           0x81BCA0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x81AB40

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x820750

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x534530
#define CTaskManager__HandleMessage_x                              0x5329C0
#define CTaskManager__GetTaskStatus_x                              0x5345E0
#define CTaskManager__GetElementDescription_x                      0x534660

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x572A80
#define EqSoundManager__PlayScriptMp3_x                            0x572BE0
#define EqSoundManager__SoundAssistPlay_x                          0x683B30
#define EqSoundManager__WaveInstancePlay_x                         0x6830A0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x5282B0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x951B40

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x55FF30
#define CAltAbilityData__GetMercMaxRank_x                          0x55FEC0
#define CAltAbilityData__GetMaxRank_x                              0x555690

//CTargetRing
#define CTargetRing__Cast_x                                        0x617B60

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C98D0
#define CharacterBase__CreateItemGlobalIndex_x                     0x50F470
#define CharacterBase__CreateItemIndex_x                           0x61FC70
#define CharacterBase__GetItemPossession_x                         0x4FB060
#define CharacterBase__GetItemByGlobalIndex_x                      0x8D76F0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8D7750
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6FC1F0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6FCA20
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6FCAD0

//messages
#define msg_spell_worn_off_x                                       0x59BC10
#define msg_new_text_x                                             0x5909D0
#define __msgTokenTextParam_x                                      0x59E140
#define msgTokenText_x                                             0x59E390

//SpellManager
#define SpellManager__vftable_x                                    0xAE722C
#define SpellManager__SpellManager_x                               0x686E60
#define Spellmanager__LoadTextSpells_x                             0x687750
#define SpellManager__GetSpellByGroupAndRank_x                     0x687030

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x999F20

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x50FB30
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A1F10
#define ItemGlobalIndex__IsEquippedLocation_x                      0x6384C0
#define ItemGlobalIndex__IsValidIndex_x                            0x50FB90

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8CFA90
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8CFD10

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x76BED0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x719790
#define CCursorAttachment__AttachToCursor1_x                       0x7197D0
#define CCursorAttachment__Deactivate_x                            0x71A7C0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x9448B0
#define CSidlManagerBase__CreatePageWnd_x                          0x9440B0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x940330
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x9402C0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x961B20
#define CEQSuiteTextureLoader__GetTexture_x                        0x9617E0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50C9E0
#define CFindItemWnd__WndNotification_x                            0x50D4C0
#define CFindItemWnd__Update_x                                     0x50E030
#define CFindItemWnd__PickupSelectedItem_x                         0x50C220

//IString
#define IString__Append_x                                          0x4FC930

//Camera
#define CDisplay__cameraType_x                                     0xDFB51C
#define EverQuest__Cameras_x                                       0xEBEA54

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x515200
#define LootFiltersManager__GetItemFilterData_x                    0x514B00
#define LootFiltersManager__RemoveItemLootFilter_x                 0x514B30
#define LootFiltersManager__SetItemLootFilter_x                    0x514D50

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C3240

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x99FA90
#define CResolutionHandler__GetWindowedStyle_x                     0x67E670

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x711E60

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E3F70
#define CDistillerInfo__Instance_x                                 0x8E3F10

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x731FA0
#define CGroupWnd__UpdateDisplay_x                                 0x7312F0

//ItemBase
#define ItemBase__IsLore_x                                         0x8A5280
#define ItemBase__IsLoreEquipped_x                                 0x8A52F0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5D6F80
#define EQPlacedItemManager__GetItemByGuid_x                       0x5D70C0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5D7120

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x673A80
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x677400

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x502DF0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F16F0
#define FactionManagerClient__HandleFactionMessage_x               0x4F1D60
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F2320
#define FactionManagerClient__GetMaxFaction_x                      0x4F233F
#define FactionManagerClient__GetMinFaction_x                      0x4F22F0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FB030

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x928FC0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BE10

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FB340

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x55F3F0

//CTargetManager
#define CTargetManager__Get_x                                      0x68A6D0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x673A80

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8E90

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5AA4B0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF5C0E8

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
