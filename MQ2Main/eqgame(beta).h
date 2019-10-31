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
#define __ExpectedVersionDate                                     "Oct 31 2019"
#define __ExpectedVersionTime                                     "04:21:45"
#define __ActualVersionDate_x                                      0xB03EC0
#define __ActualVersionTime_x                                      0xB03EB4
#define __ActualVersionBuild_x                                     0xAEFBA4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x62AD10
#define __MemChecker1_x                                            0x8FD680
#define __MemChecker2_x                                            0x6B9420
#define __MemChecker3_x                                            0x6B9370
#define __MemChecker4_x                                            0x854B00
#define __EncryptPad0_x                                            0xC3A3E0
#define __EncryptPad1_x                                            0xC985A0
#define __EncryptPad2_x                                            0xC4AC78
#define __EncryptPad3_x                                            0xC4A878
#define __EncryptPad4_x                                            0xC88BF8
#define __EncryptPad5_x                                            0xF61CDC
#define __AC1_x                                                    0x811956
#define __AC2_x                                                    0x5E4BBF
#define __AC3_x                                                    0x5EC2BF
#define __AC4_x                                                    0x5F0290
#define __AC5_x                                                    0x5F659F
#define __AC6_x                                                    0x5FABB6
#define __AC7_x                                                    0x5E4630
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
#define __do_loot_x                                                0x5B1020
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
#define __gfMaxZoomCameraDistance_x                                0xAF9818
#define __gfMaxCameraDistance_x                                    0xB25D58
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
#define pinstCAdvancedLootWnd_x                                    0xDFB7CC
#define pinstCAdventureLeaderboardWnd_x                            0xF6E338
#define pinstCAdventureRequestWnd_x                                0xF6E3E8
#define pinstCAdventureStatsWnd_x                                  0xF6E498
#define pinstCAggroMeterWnd_x                                      0xDFB454
#define pinstCAlarmWnd_x                                           0xDFB78C
#define pinstCAlertHistoryWnd_x                                    0xDFB7C4
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
#define pinstCBuffWindowSHORT_x                                    0xDFB418
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
#define pinstCEditLabelWnd_x                                       0xDFB004
#define pinstCEQMainWnd_x                                          0xF70FC0
#define pinstCEventCalendarWnd_x                                   0xDFB00C
#define pinstCExtendedTargetWnd_x                                  0xDFB440
#define pinstCFacePick_x                                           0xDFB7B8
#define pinstCFactionWnd_x                                         0xDFB764
#define pinstCFellowshipWnd_x                                      0xF711C0
#define pinstCFileSelectionWnd_x                                   0xDFB47C
#define pinstCFindItemWnd_x                                        0xDFB758
#define pinstCFindLocationWnd_x                                    0xF71318
#define pinstCFriendsWnd_x                                         0xDFB7C8
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
#define pinstCKeyRingWnd_x                                         0xDFAF9C
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
#define pinstCNoteWnd_x                                            0xDFAF50
#define pinstCObjectPreviewWnd_x                                   0xDFB750
#define pinstCOptionsWnd_x                                         0xDFAF70
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
#define pinstCServerListWnd_x                                      0xDFB008
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
#define pinstCTextEntryWnd_x                                       0xDFB41C
#define pinstCTimeLeftWnd_x                                        0xDFB484
#define pinstCTipWndCONTEXT_x                                      0xF77BA4
#define pinstCTipWndOFDAY_x                                        0xF77BA0
#define pinstCTitleWnd_x                                           0xF77C50
#define pinstCTrackingWnd_x                                        0xDFAF44
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
#define __CastRay_x                                                0x5AC480
#define __CastRay2_x                                               0x5AC4D0
#define __ConvertItemTags_x                                        0x5C8020
#define __CleanItemTags_x                                          0x47D2F0
#define __DoesFileExist_x                                          0x900710
#define __EQGetTime_x                                              0x8FD150
#define __ExecuteCmd_x                                             0x5A4D70
#define __FixHeading_x                                             0x997850
#define __GameLoop_x                                               0x6B8610
#define __get_bearing_x                                            0x5ABFF0
#define __get_melee_range_x                                        0x5AC6C0
#define __GetAnimationCache_x                                      0x71D880
#define __GetGaugeValueFromEQ_x                                    0x80FE00
#define __GetLabelFromEQ_x                                         0x8118E0
#define __GetXTargetType_x                                         0x9992A0
#define __HandleMouseWheel_x                                       0x6B94D0
#define __HeadingDiff_x                                            0x9978C0
#define __HelpPath_x                                               0xF5C7B4
#define __LoadFrontEnd_x                                           0x6B5930
#define __NewUIINI_x                                               0x80FAD0
#define __ProcessGameEvents_x                                      0x60C430
#define __ProcessMouseEvent_x                                      0x60BBF0
#define __SaveColors_x                                             0x54FCD0
#define __STMLToText_x                                             0x93AEE0
#define __ToggleKeyRingItem_x                                      0x5134D0
#define CMemoryMappedFile__SetFile_x                               0xA86B60
#define CrashDetected_x                                            0x6B73D0
#define DrawNetStatus_x                                            0x637EE0
#define Expansion_HoT_x                                            0xEBE704
#define Teleport_Table_Size_x                                      0xEAD640
#define Teleport_Table_x                                           0xEADB10
#define Util__FastTime_x                                           0x8FCD20

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490610
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499520
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4992F0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493BB0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x493000

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x557810
#define AltAdvManager__IsAbilityReady_x                            0x556740
#define AltAdvManager__GetAAById_x                                 0x556940
#define AltAdvManager__CanTrainAbility_x                           0x5569B0
#define AltAdvManager__CanSeeAbility_x                             0x556D10

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA4C0
#define CharacterZoneClient__HasSkill_x                            0x4D53B0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6AD0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE5F0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BABF0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9450
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9530
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9610
#define CharacterZoneClient__FindAffectSlot_x                      0x4C33E0
#define CharacterZoneClient__BardCastBard_x                        0x4C5F40
#define CharacterZoneClient__GetMaxEffects_x                       0x4BACC0
#define CharacterZoneClient__GetEffect_x                           0x4BAB30
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C4430
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C4500
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C4550
#define CharacterZoneClient__CalcAffectChange_x                    0x4C46A0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4870
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2B10
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7A30
#define CharacterZoneClient__FindItemByRecord_x                    0x4D74B0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6DEFD0
#define CBankWnd__WndNotification_x                                0x6DEDB0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6EC6C0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x61AAB0
#define CButtonWnd__CButtonWnd_x                                   0x937290

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x70C9C0
#define CChatManager__InitContextMenu_x                            0x705B10
#define CChatManager__FreeChatWindow_x                             0x70B500
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8AE0
#define CChatManager__SetLockedActiveChatWindow_x                  0x70C640
#define CChatManager__CreateChatWindow_x                           0x70BB40

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8BF0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x94B9E0
#define CContextMenu__dCContextMenu_x                              0x94BC20
#define CContextMenu__AddMenuItem_x                                0x94BC30
#define CContextMenu__RemoveMenuItem_x                             0x94BF40
#define CContextMenu__RemoveAllMenuItems_x                         0x94BF60
#define CContextMenu__CheckMenuItem_x                              0x94BFE0
#define CContextMenu__SetMenuItem_x                                0x94BE60
#define CContextMenu__AddSeparator_x                               0x94BDC0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x94C580
#define CContextMenuManager__RemoveMenu_x                          0x94C5F0
#define CContextMenuManager__PopupMenu_x                           0x94C6B0
#define CContextMenuManager__Flush_x                               0x94C520
#define CContextMenuManager__GetMenu_x                             0x49B740
#define CContextMenuManager__CreateDefaultMenu_x                   0x718050

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D9430
#define CChatService__GetFriendName_x                              0x8D9440

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x70D230
#define CChatWindow__Clear_x                                       0x70E500
#define CChatWindow__WndNotification_x                             0x70EC90
#define CChatWindow__AddHistory_x                                  0x70DDC0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x948E40
#define CComboWnd__Draw_x                                          0x948320
#define CComboWnd__GetCurChoice_x                                  0x948C80
#define CComboWnd__GetListRect_x                                   0x9487E0
#define CComboWnd__GetTextRect_x                                   0x948EB0
#define CComboWnd__InsertChoice_x                                  0x948970
#define CComboWnd__SetColors_x                                     0x948940
#define CComboWnd__SetChoice_x                                     0x948C50
#define CComboWnd__GetItemCount_x                                  0x948C90
#define CComboWnd__GetCurChoiceText_x                              0x948CD0
#define CComboWnd__GetChoiceText_x                                 0x948CA0
#define CComboWnd__InsertChoiceAtIndex_x                           0x948A10

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x715A40
#define CContainerWnd__vftable_x                                   0xB0D09C
#define CContainerWnd__SetContainer_x                              0x716FA0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54A710
#define CDisplay__PreZoneMainUI_x                                  0x54A720
#define CDisplay__CleanGameUI_x                                    0x54FA90
#define CDisplay__GetClickedActor_x                                0x542A30
#define CDisplay__GetUserDefinedColor_x                            0x53B0F0
#define CDisplay__GetWorldFilePath_x                               0x5444A0
#define CDisplay__is3dON_x                                         0x53F690
#define CDisplay__ReloadUI_x                                       0x549BA0
#define CDisplay__WriteTextHD2_x                                   0x53F480
#define CDisplay__TrueDistance_x                                   0x546160
#define CDisplay__SetViewActor_x                                   0x542350
#define CDisplay__GetFloorHeight_x                                 0x53F750
#define CDisplay__SetRenderWindow_x                                0x53E0B0
#define CDisplay__ToggleScreenshotMode_x                           0x541E20

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x96B5C0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x94EF50
#define CEditWnd__GetCharIndexPt_x                                 0x94FE80
#define CEditWnd__GetDisplayString_x                               0x94FD20
#define CEditWnd__GetHorzOffset_x                                  0x94E580
#define CEditWnd__GetLineForPrintableChar_x                        0x951020
#define CEditWnd__GetSelStartPt_x                                  0x950130
#define CEditWnd__GetSTMLSafeText_x                                0x94FB40
#define CEditWnd__PointFromPrintableChar_x                         0x950C50
#define CEditWnd__SelectableCharFromPoint_x                        0x950DC0
#define CEditWnd__SetEditable_x                                    0x950200
#define CEditWnd__SetWindowTextA_x                                 0x94F8C0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5FA090
#define CEverQuest__ClickedPlayer_x                                0x5EC0A0
#define CEverQuest__CreateTargetIndicator_x                        0x6096C0
#define CEverQuest__DeleteTargetIndicator_x                        0x609750
#define CEverQuest__DoTellWindow_x                                 0x4E8CD0
#define CEverQuest__OutputTextToLog_x                              0x4E8F50
#define CEverQuest__DropHeldItemOnGround_x                         0x5E10E0
#define CEverQuest__dsp_chat_x                                     0x4E92E0
#define CEverQuest__trimName_x                                     0x6059A0
#define CEverQuest__Emote_x                                        0x5FA8F0
#define CEverQuest__EnterZone_x                                    0x5F4870
#define CEverQuest__GetBodyTypeDesc_x                              0x5FF260
#define CEverQuest__GetClassDesc_x                                 0x5FF8A0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5FFEA0
#define CEverQuest__GetDeityDesc_x                                 0x608000
#define CEverQuest__GetLangDesc_x                                  0x600060
#define CEverQuest__GetRaceDesc_x                                  0x5FF880
#define CEverQuest__InterpretCmd_x                                 0x6085D0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5E52E0
#define CEverQuest__LMouseUp_x                                     0x5E3670
#define CEverQuest__RightClickedOnPlayer_x                         0x5E5BC0
#define CEverQuest__RMouseUp_x                                     0x5E45F0
#define CEverQuest__SetGameState_x                                 0x5E0E70
#define CEverQuest__UPCNotificationFlush_x                         0x6058A0
#define CEverQuest__IssuePetCommand_x                              0x601460
#define CEverQuest__ReportSuccessfulHit_x                          0x5FBCE0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x727910
#define CGaugeWnd__CalcLinesFillRect_x                             0x727970
#define CGaugeWnd__Draw_x                                          0x726F90

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF550
#define CGuild__GetGuildName_x                                     0x4AE630
#define CGuild__GetGuildIndex_x                                    0x4AE9C0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x742D10

//CHotButton
#define CHotButton__SetButtonSize_x                                0x61AE70

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x74FD40
#define CInvSlotMgr__MoveItem_x                                    0x74EA60
#define CInvSlotMgr__SelectSlot_x                                  0x74FE10

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x74D2D0
#define CInvSlot__SliderComplete_x                                 0x74B030
#define CInvSlot__GetItemBase_x                                    0x74A9A0
#define CInvSlot__UpdateItem_x                                     0x74AB10

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x751890
#define CInvSlotWnd__CInvSlotWnd_x                                 0x750A30
#define CInvSlotWnd__HandleLButtonUp_x                             0x751410

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x80B0D0
#define CItemDisplayWnd__UpdateStrings_x                           0x75FFE0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x759CD0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x75A200
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x7605E0
#define CItemDisplayWnd__AboutToShow_x                             0x75FC30
#define CItemDisplayWnd__WndNotification_x                         0x7616D0
#define CItemDisplayWnd__RequestConvertItem_x                      0x761190
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x75ECA0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x75FA50

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x843BB0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x765BD0

// CLabel 
#define CLabel__Draw_x                                             0x76B620

// CListWnd
#define CListWnd__CListWnd_x                                       0x9213C0
#define CListWnd__dCListWnd_x                                      0x9216E0
#define CListWnd__AddColumn_x                                      0x925B50
#define CListWnd__AddColumn1_x                                     0x925BA0
#define CListWnd__AddLine_x                                        0x925F30
#define CListWnd__AddString_x                                      0x925D30
#define CListWnd__CalculateFirstVisibleLine_x                      0x925910
#define CListWnd__CalculateVSBRange_x                              0x9256F0
#define CListWnd__ClearSel_x                                       0x926710
#define CListWnd__ClearAllSel_x                                    0x926770
#define CListWnd__CloseAndUpdateEditWindow_x                       0x927180
#define CListWnd__Compare_x                                        0x925020
#define CListWnd__Draw_x                                           0x921810
#define CListWnd__DrawColumnSeparators_x                           0x924000
#define CListWnd__DrawHeader_x                                     0x924460
#define CListWnd__DrawItem_x                                       0x924960
#define CListWnd__DrawLine_x                                       0x924160
#define CListWnd__DrawSeparator_x                                  0x9240A0
#define CListWnd__EnableLine_x                                     0x9238E0
#define CListWnd__EnsureVisible_x                                  0x9270A0
#define CListWnd__ExtendSel_x                                      0x926640
#define CListWnd__GetColumnTooltip_x                               0x923420
#define CListWnd__GetColumnMinWidth_x                              0x923490
#define CListWnd__GetColumnWidth_x                                 0x923390
#define CListWnd__GetCurSel_x                                      0x922D20
#define CListWnd__GetItemAtPoint_x                                 0x923B50
#define CListWnd__GetItemAtPoint1_x                                0x923BC0
#define CListWnd__GetItemData_x                                    0x922DA0
#define CListWnd__GetItemHeight_x                                  0x923160
#define CListWnd__GetItemIcon_x                                    0x922F30
#define CListWnd__GetItemRect_x                                    0x9239D0
#define CListWnd__GetItemText_x                                    0x922DE0
#define CListWnd__GetSelList_x                                     0x9267C0
#define CListWnd__GetSeparatorRect_x                               0x923E00
#define CListWnd__InsertLine_x                                     0x926320
#define CListWnd__RemoveLine_x                                     0x926470
#define CListWnd__SetColors_x                                      0x9256C0
#define CListWnd__SetColumnJustification_x                         0x9253F0
#define CListWnd__SetColumnWidth_x                                 0x925310
#define CListWnd__SetCurSel_x                                      0x926580
#define CListWnd__SetItemColor_x                                   0x926D50
#define CListWnd__SetItemData_x                                    0x926D10
#define CListWnd__SetItemText_x                                    0x926930
#define CListWnd__ShiftColumnSeparator_x                           0x9254B0
#define CListWnd__Sort_x                                           0x9251A0
#define CListWnd__ToggleSel_x                                      0x9265B0
#define CListWnd__SetColumnsSizable_x                              0x925560
#define CListWnd__SetItemWnd_x                                     0x926BE0
#define CListWnd__GetItemWnd_x                                     0x922F80
#define CListWnd__SetItemIcon_x                                    0x9269B0
#define CListWnd__CalculateCustomWindowPositions_x                 0x925A10
#define CListWnd__SetVScrollPos_x                                  0x9252F0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x780EE0
#define CMapViewWnd__GetWorldCoordinates_x                         0x77F5F0
#define CMapViewWnd__HandleLButtonDown_x                           0x77C630

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A0EB0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A1790
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A1CC0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A4C40
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x79FA20
#define CMerchantWnd__SelectBuySellSlot_x                          0x7AA7F0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A0AC0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8A6DF0
#define CPacketScrambler__hton_x                                   0x8A6DE0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x940540
#define CSidlManager__FindScreenPieceTemplate_x                    0x940950
#define CSidlManager__FindScreenPieceTemplate1_x                   0x940740
#define CSidlManager__CreateLabel_x                                0x802570
#define CSidlManager__CreateXWndFromTemplate_x                     0x9438B0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x943A90
#define CSidlManager__CreateXWnd_x                                 0x8024A0
#define CSidlManager__CreateHotButtonWnd_x                         0x802A60

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x93D010
#define CSidlScreenWnd__CalculateVSBRange_x                        0x93CF10
#define CSidlScreenWnd__ConvertToRes_x                             0x962610
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x93C9A0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x93C690
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x93C760
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x93C830
#define CSidlScreenWnd__DrawSidlPiece_x                            0x93D4B0
#define CSidlScreenWnd__EnableIniStorage_x                         0x93D980
#define CSidlScreenWnd__GetSidlPiece_x                             0x93D6A0
#define CSidlScreenWnd__Init1_x                                    0x93C290
#define CSidlScreenWnd__LoadIniInfo_x                              0x93D9D0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x93E520
#define CSidlScreenWnd__LoadSidlScreen_x                           0x93B690
#define CSidlScreenWnd__StoreIniInfo_x                             0x93E090
#define CSidlScreenWnd__StoreIniVis_x                              0x93E400
#define CSidlScreenWnd__WndNotification_x                          0x93D3C0
#define CSidlScreenWnd__GetChildItem_x                             0x93D900
#define CSidlScreenWnd__HandleLButtonUp_x                          0x92CFD0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15F2F28

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x67F400
#define CSkillMgr__GetSkillCap_x                                   0x67F5E0
#define CSkillMgr__GetNameToken_x                                  0x67EB80
#define CSkillMgr__IsActivatedSkill_x                              0x67ECC0
#define CSkillMgr__IsCombatSkill_x                                 0x67EC00

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x94D360
#define CSliderWnd__SetValue_x                                     0x94D1D0
#define CSliderWnd__SetNumTicks_x                                  0x94D230

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x808560

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x955B80
#define CStmlWnd__CalculateHSBRange_x                              0x956CE0
#define CStmlWnd__CalculateVSBRange_x                              0x956C60
#define CStmlWnd__CanBreakAtCharacter_x                            0x95B010
#define CStmlWnd__FastForwardToEndOfTag_x                          0x95BCA0
#define CStmlWnd__ForceParseNow_x                                  0x9561C0
#define CStmlWnd__GetNextTagPiece_x                                0x95AF70
#define CStmlWnd__GetSTMLText_x                                    0x502D20
#define CStmlWnd__GetVisibleText_x                                 0x9561E0
#define CStmlWnd__InitializeWindowVariables_x                      0x95BAF0
#define CStmlWnd__MakeStmlColorTag_x                               0x9551F0
#define CStmlWnd__MakeWndNotificationTag_x                         0x955260
#define CStmlWnd__SetSTMLText_x                                    0x9542A0
#define CStmlWnd__StripFirstSTMLLines_x                            0x95CD70
#define CStmlWnd__UpdateHistoryString_x                            0x95BEB0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x9533F0
#define CTabWnd__DrawCurrentPage_x                                 0x953B20
#define CTabWnd__DrawTab_x                                         0x953840
#define CTabWnd__GetCurrentPage_x                                  0x952BF0
#define CTabWnd__GetPageInnerRect_x                                0x952E30
#define CTabWnd__GetTabInnerRect_x                                 0x952D70
#define CTabWnd__GetTabRect_x                                      0x952C20
#define CTabWnd__InsertPage_x                                      0x953040
#define CTabWnd__SetPage_x                                         0x952EB0
#define CTabWnd__SetPageRect_x                                     0x953330
#define CTabWnd__UpdatePage_x                                      0x953700
#define CTabWnd__GetPageFromTabIndex_x                             0x953780
#define CTabWnd__GetCurrentTabIndex_x                              0x952BE0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x765FA0
#define CPageWnd__SetTabText_x                                     0x952730

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9220

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x929E70
#define CTextureFont__GetTextExtent_x                              0x92A030

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B27F0
#define CHtmlComponentWnd__ValidateUri_x                           0x744700
#define CHtmlWnd__SetClientCallbacks_x                             0x61FEE0
#define CHtmlWnd__AddObserver_x                                    0x61FF00
#define CHtmlWnd__RemoveObserver_x                                 0x61FF60
#define Window__getProgress_x                                      0x85C0B0
#define Window__getStatus_x                                        0x85C0D0
#define Window__getURI_x                                           0x85C0E0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x968050

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x916F30

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8920
#define CXStr__CXStr1_x                                            0x4FDC90
#define CXStr__CXStr3_x                                            0x8F9250
#define CXStr__dCXStr_x                                            0x478780
#define CXStr__operator_equal_x                                    0x8F9480
#define CXStr__operator_equal1_x                                   0x8F94C0
#define CXStr__operator_plus_equal1_x                              0x8F9F50
#define CXStr__SetString_x                                         0x8FBE40
#define CXStr__operator_char_p_x                                   0x8F99C0
#define CXStr__GetChar_x                                           0x8FB790
#define CXStr__Delete_x                                            0x8FB040
#define CXStr__GetUnicode_x                                        0x8FB800
#define CXStr__GetLength_x                                         0x4A8FD0
#define CXStr__Mid_x                                               0x47D6A0
#define CXStr__Insert_x                                            0x8FB860
#define CXStr__FindNext_x                                          0x8FB4B0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x94B600
#define CXWnd__BringToTop_x                                        0x930720
#define CXWnd__Center_x                                            0x9302A0
#define CXWnd__ClrFocus_x                                          0x9300B0
#define CXWnd__Destroy_x                                           0x930160
#define CXWnd__DoAllDrawing_x                                      0x92C760
#define CXWnd__DrawChildren_x                                      0x92C730
#define CXWnd__DrawColoredRect_x                                   0x92CBC0
#define CXWnd__DrawTooltip_x                                       0x92B280
#define CXWnd__DrawTooltipAtPoint_x                                0x92B340
#define CXWnd__GetBorderFrame_x                                    0x92CA20
#define CXWnd__GetChildWndAt_x                                     0x9307C0
#define CXWnd__GetClientClipRect_x                                 0x92EA00
#define CXWnd__GetScreenClipRect_x                                 0x92EAD0
#define CXWnd__GetScreenRect_x                                     0x92EC70
#define CXWnd__GetTooltipRect_x                                    0x92CC10
#define CXWnd__GetWindowTextA_x                                    0x49CE20
#define CXWnd__IsActive_x                                          0x92D330
#define CXWnd__IsDescendantOf_x                                    0x92F630
#define CXWnd__IsReallyVisible_x                                   0x92F660
#define CXWnd__IsType_x                                            0x930E30
#define CXWnd__Move_x                                              0x92F6C0
#define CXWnd__Move1_x                                             0x92F770
#define CXWnd__ProcessTransition_x                                 0x930250
#define CXWnd__Refade_x                                            0x92FA40
#define CXWnd__Resize_x                                            0x92FCC0
#define CXWnd__Right_x                                             0x9304E0
#define CXWnd__SetFocus_x                                          0x930070
#define CXWnd__SetFont_x                                           0x9300E0
#define CXWnd__SetKeyTooltip_x                                     0x930C40
#define CXWnd__SetMouseOver_x                                      0x92DB70
#define CXWnd__StartFade_x                                         0x92F510
#define CXWnd__GetChildItem_x                                      0x930930
#define CXWnd__SetParent_x                                         0x92F410
#define CXWnd__Minimize_x                                          0x92FD30

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x963690

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9336F0
#define CXWndManager__DrawWindows_x                                0x933710
#define CXWndManager__GetKeyboardFlags_x                           0x935F00
#define CXWndManager__HandleKeyboardMsg_x                          0x935AB0
#define CXWndManager__RemoveWnd_x                                  0x936150
#define CXWndManager__RemovePendingDeletionWnd_x                   0x9366B0

// CDBStr
#define CDBStr__GetString_x                                        0x53A0A0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BBBD0
#define EQ_Character__Cur_HP_x                                     0x4D23F0
#define EQ_Character__Cur_Mana_x                                   0x4D9B10
#define EQ_Character__GetCastingTimeModifier_x                     0x4BEC40
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2750
#define EQ_Character__GetFocusRangeModifier_x                      0x4B28A0
#define EQ_Character__GetHPRegen_x                                 0x4DF8B0
#define EQ_Character__GetEnduranceRegen_x                          0x4DFEB0
#define EQ_Character__GetManaRegen_x                               0x4E02F0
#define EQ_Character__Max_Endurance_x                              0x645F50
#define EQ_Character__Max_HP_x                                     0x4D2220
#define EQ_Character__Max_Mana_x                                   0x645D50
#define EQ_Character__doCombatAbility_x                            0x6483A0
#define EQ_Character__UseSkill_x                                   0x4E20C0
#define EQ_Character__GetConLevel_x                                0x63EE70
#define EQ_Character__IsExpansionFlag_x                            0x5A3500
#define EQ_Character__TotalEffect_x                                0x4C5680
#define EQ_Character__GetPCSpellAffect_x                           0x4BF990
#define EQ_Character__SpellDuration_x                              0x4BF4C0
#define EQ_Character__GetAdjustedSkill_x                           0x4D5170
#define EQ_Character__GetBaseSkill_x                               0x4D6110
#define EQ_Character__CanUseItem_x                                 0x4D9E20

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8C6360

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x65C460

//PcClient
#define PcClient__PcClient_x                                       0x63C5A0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B9840
#define CCharacterListWnd__EnterWorld_x                            0x4B9280
#define CCharacterListWnd__Quit_x                                  0x4B8FD0
#define CCharacterListWnd__UpdateList_x                            0x4B9410

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x621100
#define EQ_Item__CreateItemTagString_x                             0x8A05F0
#define EQ_Item__IsStackable_x                                     0x8A51B0
#define EQ_Item__GetImageNum_x                                     0x8A2080
#define EQ_Item__CreateItemClient_x                                0x6202E0
#define EQ_Item__GetItemValue_x                                    0x8A33B0
#define EQ_Item__ValueSellMerchant_x                               0x8A69D0
#define EQ_Item__IsKeyRingItem_x                                   0x8A4AE0
#define EQ_Item__CanGoInBag_x                                      0x621220
#define EQ_Item__IsEmpty_x                                         0x8A4620
#define EQ_Item__GetMaxItemCount_x                                 0x8A37C0
#define EQ_Item__GetHeldItem_x                                     0x8A1F50
#define EQ_Item__GetAugmentFitBySlot_x                             0x89FF60

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x558530
#define EQ_LoadingS__Array_x                                       0xC21B58

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x6468B0
#define EQ_PC__GetAlternateAbilityId_x                             0x8AFC10
#define EQ_PC__GetCombatAbility_x                                  0x8B0280
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B02F0
#define EQ_PC__GetItemRecastTimer_x                                0x648920
#define EQ_PC__HasLoreItem_x                                       0x63F630
#define EQ_PC__AlertInventoryChanged_x                             0x63E7A0
#define EQ_PC__GetPcZoneClient_x                                   0x66AF40
#define EQ_PC__RemoveMyAffect_x                                    0x64BB60
#define EQ_PC__GetKeyRingItems_x                                   0x8B0B80
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B0910
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B0E80

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5A9AA0
#define EQItemList__add_object_x                                   0x5D69D0
#define EQItemList__add_item_x                                     0x5AA000
#define EQItemList__delete_item_x                                  0x5AA050
#define EQItemList__FreeItemList_x                                 0x5A9F50

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x536BA0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x65DCE0
#define EQPlayer__dEQPlayer_x                                      0x651020
#define EQPlayer__DoAttack_x                                       0x665C00
#define EQPlayer__EQPlayer_x                                       0x6516E0
#define EQPlayer__SetNameSpriteState_x                             0x6559C0
#define EQPlayer__SetNameSpriteTint_x                              0x656890
#define PlayerBase__HasProperty_j_x                                0x995C30
#define EQPlayer__IsTargetable_x                                   0x9960D0
#define EQPlayer__CanSee_x                                         0x995F30
#define EQPlayer__CanSee1_x                                        0x996000
#define PlayerBase__GetVisibilityLineSegment_x                     0x995CF0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x6689E0
#define PlayerZoneClient__GetLevel_x                               0x66AF80
#define PlayerZoneClient__IsValidTeleport_x                        0x5D7B40
#define PlayerZoneClient__LegalPlayerRace_x                        0x551920

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x660AE0
#define EQPlayerManager__GetSpawnByName_x                          0x660B90
#define EQPlayerManager__GetPlayerFromPartialName_x                0x660C20

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x624880
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x624900
#define KeypressHandler__AttachKeyToEqCommand_x                    0x624940
#define KeypressHandler__ClearCommandStateArray_x                  0x625D50
#define KeypressHandler__HandleKeyDown_x                           0x625D70
#define KeypressHandler__HandleKeyUp_x                             0x625E10
#define KeypressHandler__SaveKeymapping_x                          0x626260

// MapViewMap 
#define MapViewMap__Clear_x                                        0x77CD50
#define MapViewMap__SaveEx_x                                       0x780110
#define MapViewMap__SetZoom_x                                      0x7847D0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C4280

// StringTable 
#define StringTable__getString_x                                   0x8BEFA0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x64B7D0
#define PcZoneClient__RemovePetEffect_x                            0x64BE00
#define PcZoneClient__HasAlternateAbility_x                        0x645B80
#define PcZoneClient__GetCurrentMod_x                              0x4E5180
#define PcZoneClient__GetModCap_x                                  0x4E5080
#define PcZoneClient__CanEquipItem_x                               0x646250
#define PcZoneClient__GetItemByID_x                                0x648DA0
#define PcZoneClient__GetItemByItemClass_x                         0x648EF0
#define PcZoneClient__RemoveBuffEffect_x                           0x64BE20
#define PcZoneClient__BandolierSwap_x                              0x646E60
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x6488C0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5DC5F0

//IconCache
#define IconCache__GetIcon_x                                       0x71D120

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x714BD0
#define CContainerMgr__CloseContainer_x                            0x714EA0
#define CContainerMgr__OpenExperimentContainer_x                   0x715920

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D4CF0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x6192A0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x773100
#define CLootWnd__RequestLootSlot_x                                0x772330

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x576D10
#define EQ_Spell__SpellAffects_x                                   0x577180
#define EQ_Spell__SpellAffectBase_x                                0x576F40
#define EQ_Spell__IsStackable_x                                    0x4C9E00
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9C20
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6C20
#define EQ_Spell__IsSPAStacking_x                                  0x577FD0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x5774E0
#define EQ_Spell__IsNoRemove_x                                     0x4C9DE0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x577FE0
#define __IsResEffectSpell_x                                       0x4C90C0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD2E0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8CE910

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x81B900
#define CTargetWnd__WndNotification_x                              0x81B190
#define CTargetWnd__RefreshTargetBuffs_x                           0x81B460
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x81A300

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x81FF00

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x5345C0
#define CTaskManager__HandleMessage_x                              0x532A60
#define CTaskManager__GetTaskStatus_x                              0x534670
#define CTaskManager__GetElementDescription_x                      0x5346F0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x572280
#define EqSoundManager__PlayScriptMp3_x                            0x5723E0
#define EqSoundManager__SoundAssistPlay_x                          0x683380
#define EqSoundManager__WaveInstancePlay_x                         0x6828F0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x528320

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x951C40

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x55FF20
#define CAltAbilityData__GetMercMaxRank_x                          0x55FEB0
#define CAltAbilityData__GetMaxRank_x                              0x5555C0

//CTargetRing
#define CTargetRing__Cast_x                                        0x6173C0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9C00
#define CharacterBase__CreateItemGlobalIndex_x                     0x50FA40
#define CharacterBase__CreateItemIndex_x                           0x61F490
#define CharacterBase__GetItemPossession_x                         0x4FB530
#define CharacterBase__GetItemByGlobalIndex_x                      0x8D6F00
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8D6F60
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6FBD00
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6FC530
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6FC5E0

//messages
#define msg_spell_worn_off_x                                       0x59B770
#define msg_new_text_x                                             0x590510
#define __msgTokenTextParam_x                                      0x59DCA0
#define msgTokenText_x                                             0x59DEF0

//SpellManager
#define SpellManager__vftable_x                                    0xAE7234
#define SpellManager__SpellManager_x                               0x6866B0
#define Spellmanager__LoadTextSpells_x                             0x686FA0
#define SpellManager__GetSpellByGroupAndRank_x                     0x686880

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x999B90

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x5100C0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A1A70
#define ItemGlobalIndex__IsEquippedLocation_x                      0x637D40
#define ItemGlobalIndex__IsValidIndex_x                            0x510120

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8CF2B0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8CF530

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x76B960

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x7192F0
#define CCursorAttachment__AttachToCursor1_x                       0x719330
#define CCursorAttachment__Deactivate_x                            0x71A320

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x9448E0
#define CSidlManagerBase__CreatePageWnd_x                          0x9440E0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x940360
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x9402F0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9619D0
#define CEQSuiteTextureLoader__GetTexture_x                        0x961690

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50CFE0
#define CFindItemWnd__WndNotification_x                            0x50DAC0
#define CFindItemWnd__Update_x                                     0x50E630
#define CFindItemWnd__PickupSelectedItem_x                         0x50C820

//IString
#define IString__Append_x                                          0x4FCD20

//Camera
#define CDisplay__cameraType_x                                     0xDFB51C
#define EverQuest__Cameras_x                                       0xEBEA54

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x515870
#define LootFiltersManager__GetItemFilterData_x                    0x515170
#define LootFiltersManager__RemoveItemLootFilter_x                 0x5151A0
#define LootFiltersManager__SetItemLootFilter_x                    0x5153C0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C2C90

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x99F6A0
#define CResolutionHandler__GetWindowedStyle_x                     0x67DE60

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x7119A0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E37E0
#define CDistillerInfo__Instance_x                                 0x8E3780

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x731AF0
#define CGroupWnd__UpdateDisplay_x                                 0x730E40

//ItemBase
#define ItemBase__IsLore_x                                         0x8A4B80
#define ItemBase__IsLoreEquipped_x                                 0x8A4BF0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5D6930
#define EQPlacedItemManager__GetItemByGuid_x                       0x5D6A70
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5D6AD0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x673650
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x676FE0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x503360

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F1D50
#define FactionManagerClient__HandleFactionMessage_x               0x4F23C0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F2980
#define FactionManagerClient__GetMaxFaction_x                      0x4F299F
#define FactionManagerClient__GetMinFaction_x                      0x4F2950

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FB500

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x928E20

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C130

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FB730

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x55F3C0

//CTargetManager
#define CTargetManager__Get_x                                      0x689F30

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x673650

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8FE0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5A9EF0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF5C0E8

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
