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
#define __ExpectedVersionDate                                     "Oct 22 2019"
#define __ExpectedVersionTime                                     "10:09:59"
#define __ActualVersionDate_x                                      0xADD3B4
#define __ActualVersionTime_x                                      0xADD3A8
#define __ActualVersionBuild_x                                     0xAC8BA4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x61B900
#define __MemChecker1_x                                            0x8EE450
#define __MemChecker2_x                                            0x6AA180
#define __MemChecker3_x                                            0x6AA0D0
#define __MemChecker4_x                                            0x845CC0
#define __EncryptPad0_x                                            0xC0EA28
#define __EncryptPad1_x                                            0xC6CAA8
#define __EncryptPad2_x                                            0xC1F2A8
#define __EncryptPad3_x                                            0xC1EEA8
#define __EncryptPad4_x                                            0xC5D1C8
#define __EncryptPad5_x                                            0xF3633C
#define __AC1_x                                                    0x802716
#define __AC2_x                                                    0x5D560F
#define __AC3_x                                                    0x5DCD0F
#define __AC4_x                                                    0x5E0BC0
#define __AC5_x                                                    0x5E6ECF
#define __AC6_x                                                    0x5EB4E6
#define __AC7_x                                                    0x5D5080
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1F1734

// Direct Input
#define DI8__Main_x                                                0xF35530
#define DI8__Keyboard_x                                            0xF35534
#define DI8__Mouse_x                                               0xF35FD8
#define DI8__Mouse_Copy_x                                          0xE90BF4
#define DI8__Mouse_Check_x                                         0xF36300
#define __AutoSkillArray_x                                         0xE91B0C
#define __Attack_x                                                 0xF2F927
#define __Autofire_x                                               0xF2F928
#define __BindList_x                                               0xBFD480
#define g_eqCommandStates_x                                        0xBFE1F8
#define __Clicks_x                                                 0xE90CAC
#define __CommandList_x                                            0xBFEDB8
#define __CurrentMapLabel_x                                        0x10509C4
#define __CurrentSocial_x                                          0xBE77CC
#define __DoAbilityList_x                                          0xEC7448
#define __do_loot_x                                                0x5A1A70
#define __DrawHandler_x                                            0x16CD360
#define __GroupCount_x                                             0xE81042
#define __Guilds_x                                                 0xE87400
#define __gWorld_x                                                 0xE81230
#define __HWnd_x                                                   0xF35FDC
#define __heqmain_x                                                0xF35510
#define __InChatMode_x                                             0xE90BDC
#define __LastTell_x                                               0xE92B44
#define __LMouseHeldTime_x                                         0xE90D18
#define __Mouse_x                                                  0xF3551C
#define __MouseLook_x                                              0xE90C72
#define __MouseEventTime_x                                         0xF3040C
#define __gpbCommandEvent_x                                        0xE8123C
#define __NetStatusToggle_x                                        0xE90C75
#define __PCNames_x                                                0xE920F4
#define __RangeAttackReady_x                                       0xE91DF0
#define __RMouseHeldTime_x                                         0xE90D14
#define __RunWalkState_x                                           0xE90BE0
#define __ScreenMode_x                                             0xDCE874
#define __ScreenX_x                                                0xE90B94
#define __ScreenY_x                                                0xE90B90
#define __ScreenXMax_x                                             0xE90B98
#define __ScreenYMax_x                                             0xE90B9C
#define __ServerHost_x                                             0xE81473
#define __ServerName_x                                             0xEC7408
#define __ShiftKeyDown_x                                           0xE9126C
#define __ShowNames_x                                              0xE91FAC
#define __Socials_x                                                0xEC7508
#define __SubscriptionType_x                                       0x1092548
#define __TargetAggroHolder_x                                      0x1053378
#define __ZoneType_x                                               0xE91070
#define __GroupAggro_x                                             0x10533B8
#define __LoginName_x                                              0xF35C84
#define __Inviter_x                                                0xF2F8A4
#define __AttackOnAssist_x                                         0xE91F68
#define __UseTellWindows_x                                         0xE92290
#define __gfMaxZoomCameraDistance_x                                0xAD28E0
#define __gfMaxCameraDistance_x                                    0xAFF2B0
#define __pulAutoRun_x                                             0xE90C90
#define __pulForward_x                                             0xE922C8
#define __pulBackward_x                                            0xE922CC
#define __pulTurnRight_x                                           0xE922D0
#define __pulTurnLeft_x                                            0xE922D4
#define __pulStrafeLeft_x                                          0xE922D8
#define __pulStrafeRight_x                                         0xE922DC

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE83798
#define instEQZoneInfo_x                                           0xE90E68
#define pinstActiveBanker_x                                        0xE81254
#define pinstActiveCorpse_x                                        0xE8124C
#define pinstActiveGMaster_x                                       0xE81250
#define pinstActiveMerchant_x                                      0xE81248
#define pinstAltAdvManager_x                                       0xDCFA78
#define pinstBandageTarget_x                                       0xE81264
#define pinstCamActor_x                                            0xDCE860
#define pinstCDBStr_x                                              0xDCE7A4
#define pinstCDisplay_x                                            0xE81024
#define pinstCEverQuest_x                                          0xF3554C
#define pinstEverQuestInfo_x                                       0xE90B88
#define pinstCharData_x                                            0xE81020
#define pinstCharSpawn_x                                           0xE8131C
#define pinstControlledMissile_x                                   0xE8157C
#define pinstControlledPlayer_x                                    0xE8131C
#define pinstCResolutionHandler_x                                  0x16CD590
#define pinstCSidlManager_x                                        0x16CC528
#define pinstCXWndManager_x                                        0x16CC524
#define instDynamicZone_x                                          0xE872D8
#define pinstDZMember_x                                            0xE873E8
#define pinstDZTimerInfo_x                                         0xE873EC
#define pinstEqLogin_x                                             0xF355D0
#define instEQMisc_x                                               0xDCE6E8
#define pinstEQSoundManager_x                                      0xDD09A0
#define pinstEQSpellStrings_x                                      0xC91478
#define instExpeditionLeader_x                                     0xE87322
#define instExpeditionName_x                                       0xE87362
#define pinstGroup_x                                               0xE8103E
#define pinstImeManager_x                                          0x16CC520
#define pinstLocalPlayer_x                                         0xE81244
#define pinstMercenaryData_x                                       0xF31EFC
#define pinstMercenaryStats_x                                      0x10534C4
#define pinstModelPlayer_x                                         0xE8125C
#define pinstPCData_x                                              0xE81020
#define pinstSkillMgr_x                                            0xF34060
#define pinstSpawnManager_x                                        0xF32B08
#define pinstSpellManager_x                                        0xF34280
#define pinstSpellSets_x                                           0xF28550
#define pinstStringTable_x                                         0xE81028
#define pinstSwitchManager_x                                       0xE80D38
#define pinstTarget_x                                              0xE81318
#define pinstTargetObject_x                                        0xE81324
#define pinstTargetSwitch_x                                        0xE83788
#define pinstTaskMember_x                                          0xDCE578
#define pinstTrackTarget_x                                         0xE81320
#define pinstTradeTarget_x                                         0xE81258
#define instTributeActive_x                                        0xDCE709
#define pinstViewActor_x                                           0xDCE85C
#define pinstWorldData_x                                           0xE80E88
#define pinstZoneAddr_x                                            0xE91108
#define pinstPlayerPath_x                                          0xF32BA0
#define pinstTargetIndicator_x                                     0xF344E8
#define EQObject_Top_x                                             0xE81240
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDCE8C0
#define pinstCAchievementsWnd_x                                    0xDCF0A4
#define pinstCActionsWnd_x                                         0xDCE868
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDCF030
#define pinstCAdvancedLootWnd_x                                    0xDCF000
#define pinstCAdventureLeaderboardWnd_x                            0x104A198
#define pinstCAdventureRequestWnd_x                                0x104A248
#define pinstCAdventureStatsWnd_x                                  0x104A2F8
#define pinstCAggroMeterWnd_x                                      0xDCF090
#define pinstCAlarmWnd_x                                           0xDCE964
#define pinstCAlertHistoryWnd_x                                    0xDCE928
#define pinstCAlertStackWnd_x                                      0xDCE880
#define pinstCAlertWnd_x                                           0xDCE89C
#define pinstCAltStorageWnd_x                                      0x104A658
#define pinstCAudioTriggersWindow_x                                0xC837A8
#define pinstCAuraWnd_x                                            0xDCF058
#define pinstCAvaZoneWnd_x                                         0xDCE8B8
#define pinstCBandolierWnd_x                                       0xDCF088
#define pinstCBankWnd_x                                            0xDCF054
#define pinstCBarterMerchantWnd_x                                  0x104B898
#define pinstCBarterSearchWnd_x                                    0x104B948
#define pinstCBarterWnd_x                                          0x104B9F8
#define pinstCBazaarConfirmationWnd_x                              0xDCF0D0
#define pinstCBazaarSearchWnd_x                                    0xDCE840
#define pinstCBazaarWnd_x                                          0xDCE920
#define pinstCBlockedBuffWnd_x                                     0xDCF05C
#define pinstCBlockedPetBuffWnd_x                                  0xDCF07C
#define pinstCBodyTintWnd_x                                        0xDCE894
#define pinstCBookWnd_x                                            0xDCF0B4
#define pinstCBreathWnd_x                                          0xDCE8D8
#define pinstCBuffWindowNORMAL_x                                   0xDCF044
#define pinstCBuffWindowSHORT_x                                    0xDCF048
#define pinstCBugReportWnd_x                                       0xDCF050
#define pinstCButtonWnd_x                                          0x16CC790
#define pinstCCastingWnd_x                                         0xDCF0A0
#define pinstCCastSpellWnd_x                                       0xDCE8D4
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDCE92C
#define pinstCChatWindowManager_x                                  0x104C4B8
#define pinstCClaimWnd_x                                           0x104C610
#define pinstCColorPickerWnd_x                                     0xDCE88C
#define pinstCCombatAbilityWnd_x                                   0xDCE958
#define pinstCCombatSkillsSelectWnd_x                              0xDCEB74
#define pinstCCompassWnd_x                                         0xDCE884
#define pinstCConfirmationDialog_x                                 0x1051510
#define pinstCContainerMgr_x                                       0xDCE924
#define pinstCContextMenuManager_x                                 0x16CC4E0
#define pinstCCursorAttachment_x                                   0xDCF094
#define pinstCDynamicZoneWnd_x                                     0x104CBD8
#define pinstCEditLabelWnd_x                                       0xDCF040
#define pinstCEQMainWnd_x                                          0x104CE20
#define pinstCEventCalendarWnd_x                                   0xDCF014
#define pinstCExtendedTargetWnd_x                                  0xDCF074
#define pinstCFacePick_x                                           0xDCEBF4
#define pinstCFactionWnd_x                                         0xDCE90C
#define pinstCFellowshipWnd_x                                      0x104D020
#define pinstCFileSelectionWnd_x                                   0xDCF09C
#define pinstCFindItemWnd_x                                        0xDCE8F4
#define pinstCFindLocationWnd_x                                    0x104D178
#define pinstCFriendsWnd_x                                         0xDCEFFC
#define pinstCGemsGameWnd_x                                        0xDCE904
#define pinstCGiveWnd_x                                            0xDCEB6C
#define pinstCGroupSearchFiltersWnd_x                              0xDCF0AC
#define pinstCGroupSearchWnd_x                                     0x104D570
#define pinstCGroupWnd_x                                           0x104D620
#define pinstCGuildBankWnd_x                                       0xE91F4C
#define pinstCGuildCreationWnd_x                                   0x104D780
#define pinstCGuildMgmtWnd_x                                       0x104D830
#define pinstCharacterCreation_x                                   0xDCEB80
#define pinstCHelpWnd_x                                            0xDCF028
#define pinstCHeritageSelectionWnd_x                               0xDCF004
#define pinstCHotButtonWnd_x                                       0x104F988
#define pinstCHotButtonWnd1_x                                      0x104F988
#define pinstCHotButtonWnd2_x                                      0x104F98C
#define pinstCHotButtonWnd3_x                                      0x104F990
#define pinstCHotButtonWnd4_x                                      0x104F994
#define pinstCIconSelectionWnd_x                                   0xDCF08C
#define pinstCInspectWnd_x                                         0xDCF024
#define pinstCInventoryWnd_x                                       0xDCF008
#define pinstCInvSlotMgr_x                                         0xDCE8BC
#define pinstCItemDisplayManager_x                                 0x104FF18
#define pinstCItemExpTransferWnd_x                                 0x105004C
#define pinstCItemOverflowWnd_x                                    0xDCE844
#define pinstCJournalCatWnd_x                                      0xDCF0BC
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDCF070
#define pinstCKeyRingWnd_x                                         0xDCF03C
#define pinstCLargeDialogWnd_x                                     0x1052190
#define pinstCLayoutCopyWnd_x                                      0x1050398
#define pinstCLFGuildWnd_x                                         0x1050448
#define pinstCLoadskinWnd_x                                        0xDCE91C
#define pinstCLootFiltersCopyWnd_x                                 0xC9FA70
#define pinstCLootFiltersWnd_x                                     0xDCE888
#define pinstCLootSettingsWnd_x                                    0xDCE8B0
#define pinstCLootWnd_x                                            0xDCF0C0
#define pinstCMailAddressBookWnd_x                                 0xDCE8C4
#define pinstCMailCompositionWnd_x                                 0xDCE8AC
#define pinstCMailIgnoreListWnd_x                                  0xDCE8C8
#define pinstCMailWnd_x                                            0xDCE870
#define pinstCManageLootWnd_x                                      0xDCFF28
#define pinstCMapToolbarWnd_x                                      0xDCF02C
#define pinstCMapViewWnd_x                                         0xDCF018
#define pinstCMarketplaceWnd_x                                     0xDCE890
#define pinstCMerchantWnd_x                                        0xDCF0C8
#define pinstCMIZoneSelectWnd_x                                    0x1050C80
#define pinstCMusicPlayerWnd_x                                     0xDCF0CC
#define pinstCNameChangeMercWnd_x                                  0xDCF0C4
#define pinstCNameChangePetWnd_x                                   0xDCF0A8
#define pinstCNameChangeWnd_x                                      0xDCF0D4
#define pinstCNoteWnd_x                                            0xDCF01C
#define pinstCObjectPreviewWnd_x                                   0xDCE8A8
#define pinstCOptionsWnd_x                                         0xDCF020
#define pinstCPetInfoWnd_x                                         0xDCE84C
#define pinstCPetitionQWnd_x                                       0xDCF084
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDCE898
#define pinstCPlayerWnd_x                                          0xDCE850
#define pinstCPopupWndManager_x                                    0x1051510
#define pinstCProgressionSelectionWnd_x                            0x10515C0
#define pinstCPurchaseGroupWnd_x                                   0xDCE8E0
#define pinstCPurchaseWnd_x                                        0xDCE8D0
#define pinstCPvPLeaderboardWnd_x                                  0x1051670
#define pinstCPvPStatsWnd_x                                        0x1051720
#define pinstCQuantityWnd_x                                        0xDCF078
#define pinstCRaceChangeWnd_x                                      0xDCE858
#define pinstCRaidOptionsWnd_x                                     0xDCF0B0
#define pinstCRaidWnd_x                                            0xDCE8B4
#define pinstCRealEstateItemsWnd_x                                 0xDCF098
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDCF034
#define pinstCRealEstateManageWnd_x                                0xDCE8F8
#define pinstCRealEstateNeighborhoodWnd_x                          0xDCE918
#define pinstCRealEstatePlotSearchWnd_x                            0xDCEB68
#define pinstCRealEstatePurchaseWnd_x                              0xDCEB8C
#define pinstCRespawnWnd_x                                         0xDCF068
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDCE8CC
#define pinstCSendMoneyWnd_x                                       0xDCEB70
#define pinstCServerListWnd_x                                      0xDCF00C
#define pinstCSkillsSelectWnd_x                                    0xDCE93C
#define pinstCSkillsWnd_x                                          0xDCE900
#define pinstCSocialEditWnd_x                                      0xDCF038
#define pinstCSocialWnd_x                                          0xDCF0B8
#define pinstCSpellBookWnd_x                                       0xDCE938
#define pinstCStoryWnd_x                                           0xDCE854
#define pinstCTargetOfTargetWnd_x                                  0x1053548
#define pinstCTargetWnd_x                                          0xDCF064
#define pinstCTaskOverlayWnd_x                                     0xDCE8DC
#define pinstCTaskSelectWnd_x                                      0x10536A0
#define pinstCTaskManager_x                                        0xCA03C0
#define pinstCTaskTemplateSelectWnd_x                              0x1053750
#define pinstCTaskWnd_x                                            0x1053800
#define pinstCTextEntryWnd_x                                       0xDCF04C
#define pinstCTimeLeftWnd_x                                        0xDCF060
#define pinstCTipWndCONTEXT_x                                      0x1053A04
#define pinstCTipWndOFDAY_x                                        0x1053A00
#define pinstCTitleWnd_x                                           0x1053AB0
#define pinstCTrackingWnd_x                                        0xDCF010
#define pinstCTradeskillWnd_x                                      0x1053C18
#define pinstCTradeWnd_x                                           0xDCE8A4
#define pinstCTrainWnd_x                                           0xDCE8A0
#define pinstCTributeBenefitWnd_x                                  0x1053E18
#define pinstCTributeMasterWnd_x                                   0x1053EC8
#define pinstCTributeTrophyWnd_x                                   0x1053F78
#define pinstCVideoModesWnd_x                                      0xDCE95C
#define pinstCVoiceMacroWnd_x                                      0xF34C50
#define pinstCVoteResultsWnd_x                                     0xDCF080
#define pinstCVoteWnd_x                                            0xDCF06C
#define pinstCWebManager_x                                         0xF352CC
#define pinstCZoneGuideWnd_x                                       0xDCE8E4
#define pinstCZonePathWnd_x                                        0xDCE908

#define pinstEQSuiteTextureLoader_x                                0xC6E598
#define pinstItemIconCache_x                                       0x104CDD8
#define pinstLootFiltersManager_x                                  0xC9FB20
#define pinstRewardSelectionWnd_x                                  0x1051E68

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC1EE98
#define __CastRay_x                                                0x59CED0
#define __CastRay2_x                                               0x59CF20
#define __ConvertItemTags_x                                        0x5B8A60
#define __CrashHandler_x                                           0x84F580
#define __CleanItemTags_x                                          0x477780
#define __DoesFileExist_x                                          0x8F14C0
#define __EQGetTime_x                                              0x8EDF20
#define __ExecuteCmd_x                                             0x595870
#define __FixHeading_x                                             0x989130
#define __GameLoop_x                                               0x6A9640
#define __get_bearing_x                                            0x59CA40
#define __get_melee_range_x                                        0x59D110
#define __GetAnimationCache_x                                      0x70E7A0
#define __GetGaugeValueFromEQ_x                                    0x800BC0
#define __GetLabelFromEQ_x                                         0x8026A0
#define __GetXTargetType_x                                         0x98ABF0
#define __HandleMouseWheel_x                                       0x6AA230
#define __HeadingDiff_x                                            0x9891A0
#define __HelpPath_x                                               0xF2FFFC
#define __LoadFrontEnd_x                                           0x6A6110
#define __NewUIINI_x                                               0x800890
#define __pCrashHandler_x                                          0x1071378
#define __ProcessGameEvents_x                                      0x5FCD50
#define __ProcessMouseEvent_x                                      0x5FC510
#define __SaveColors_x                                             0x5461C0
#define __STMLToText_x                                             0x92C570
#define __ToggleKeyRingItem_x                                      0x507D20
#define CMemoryMappedFile__SetFile_x                               0xA63400
#define CrashDetected_x                                            0x6A7B90
#define DrawNetStatus_x                                            0x628CC0
#define Expansion_HoT_x                                            0xE91F54
#define Teleport_Table_Size_x                                      0xE8132C
#define Teleport_Table_x                                           0xE81788
#define Util__FastTime_x                                           0x8EDAF0
#define wwsCrashReportCheckForUploader_x                           0x84FFF0
#define wwsCrashReportPlatformLaunchUploader_x                     0x8526B0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48AA90
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4939A0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x493770
#define CAdvancedLootWnd__AddPlayerToList_x                        0x48E030
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x48D480

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x54DD70
#define AltAdvManager__IsAbilityReady_x                            0x54CCF0
#define AltAdvManager__GetAAById_x                                 0x54CEF0
#define AltAdvManager__CanTrainAbility_x                           0x54CF60
#define AltAdvManager__CanSeeAbility_x                             0x54D2C0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C6A10
#define CharacterZoneClient__HasSkill_x                            0x4D1900
#define CharacterZoneClient__MakeMeVisible_x                       0x4D3020
#define CharacterZoneClient__IsStackBlocked_x                      0x4BAF00
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B7500
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D59C0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D5AA0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D5B80
#define CharacterZoneClient__FindAffectSlot_x                      0x4BFBB0
#define CharacterZoneClient__BardCastBard_x                        0x4C2710
#define CharacterZoneClient__GetMaxEffects_x                       0x4B75D0
#define CharacterZoneClient__GetEffect_x                           0x4B7440
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C0C00
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C0CD0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C0D20
#define CharacterZoneClient__CalcAffectChange_x                    0x4C0E70
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C1040
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4AF3E0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D3F80
#define CharacterZoneClient__FindItemByRecord_x                    0x4D3A00

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6CFE10
#define CBankWnd__WndNotification_x                                0x6CFBF0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6DD6F0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x60B6A0
#define CButtonWnd__CButtonWnd_x                                   0x928920

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6FD940
#define CChatManager__InitContextMenu_x                            0x6F6AD0
#define CChatManager__FreeChatWindow_x                             0x6FC460
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E4ED0
#define CChatManager__SetLockedActiveChatWindow_x                  0x6FD5C0
#define CChatManager__CreateChatWindow_x                           0x6FCAA0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E4FE0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x93D010
#define CContextMenu__dCContextMenu_x                              0x93D240
#define CContextMenu__AddMenuItem_x                                0x93D250
#define CContextMenu__RemoveMenuItem_x                             0x93D560
#define CContextMenu__RemoveAllMenuItems_x                         0x93D580
#define CContextMenu__CheckMenuItem_x                              0x93D600
#define CContextMenu__SetMenuItem_x                                0x93D480
#define CContextMenu__AddSeparator_x                               0x93D3E0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x93DB90
#define CContextMenuManager__RemoveMenu_x                          0x93DC00
#define CContextMenuManager__PopupMenu_x                           0x93DCC0
#define CContextMenuManager__Flush_x                               0x93DB30
#define CContextMenuManager__GetMenu_x                             0x495C90
#define CContextMenuManager__CreateDefaultMenu_x                   0x708FC0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8CEAD0
#define CChatService__GetFriendName_x                              0x8CEAE0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6FE1B0
#define CChatWindow__Clear_x                                       0x6FF480
#define CChatWindow__WndNotification_x                             0x6FFC10
#define CChatWindow__AddHistory_x                                  0x6FED40

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93A460
#define CComboWnd__Draw_x                                          0x939960
#define CComboWnd__GetCurChoice_x                                  0x93A2A0
#define CComboWnd__GetListRect_x                                   0x939E00
#define CComboWnd__GetTextRect_x                                   0x93A4D0
#define CComboWnd__InsertChoice_x                                  0x939F90
#define CComboWnd__SetColors_x                                     0x939F60
#define CComboWnd__SetChoice_x                                     0x93A270
#define CComboWnd__GetItemCount_x                                  0x93A2B0
#define CComboWnd__GetCurChoiceText_x                              0x93A2F0
#define CComboWnd__GetChoiceText_x                                 0x93A2C0
#define CComboWnd__InsertChoiceAtIndex_x                           0x93A030

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x7069A0
#define CContainerWnd__vftable_x                                   0xAE6664
#define CContainerWnd__SetContainer_x                              0x707F10

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x540C60
#define CDisplay__PreZoneMainUI_x                                  0x540C70
#define CDisplay__CleanGameUI_x                                    0x545F80
#define CDisplay__GetClickedActor_x                                0x538F80
#define CDisplay__GetUserDefinedColor_x                            0x531640
#define CDisplay__GetWorldFilePath_x                               0x53A9F0
#define CDisplay__is3dON_x                                         0x535BE0
#define CDisplay__ReloadUI_x                                       0x5400F0
#define CDisplay__WriteTextHD2_x                                   0x5359D0
#define CDisplay__TrueDistance_x                                   0x53C6B0
#define CDisplay__SetViewActor_x                                   0x5388A0
#define CDisplay__GetFloorHeight_x                                 0x535CA0
#define CDisplay__SetRenderWindow_x                                0x534600
#define CDisplay__ToggleScreenshotMode_x                           0x538370

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x95CE60

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x940570
#define CEditWnd__GetCharIndexPt_x                                 0x9414A0
#define CEditWnd__GetDisplayString_x                               0x941340
#define CEditWnd__GetHorzOffset_x                                  0x93FBA0
#define CEditWnd__GetLineForPrintableChar_x                        0x942640
#define CEditWnd__GetSelStartPt_x                                  0x941750
#define CEditWnd__GetSTMLSafeText_x                                0x941160
#define CEditWnd__PointFromPrintableChar_x                         0x942270
#define CEditWnd__SelectableCharFromPoint_x                        0x9423E0
#define CEditWnd__SetEditable_x                                    0x941820
#define CEditWnd__SetWindowTextA_x                                 0x940EE0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5EA9C0
#define CEverQuest__ClickedPlayer_x                                0x5DCAF0
#define CEverQuest__CreateTargetIndicator_x                        0x5F9FF0
#define CEverQuest__DeleteTargetIndicator_x                        0x5FA080
#define CEverQuest__DoTellWindow_x                                 0x4E50C0
#define CEverQuest__OutputTextToLog_x                              0x4E5340
#define CEverQuest__DropHeldItemOnGround_x                         0x5D1B30
#define CEverQuest__dsp_chat_x                                     0x4E56D0
#define CEverQuest__trimName_x                                     0x5F62D0
#define CEverQuest__Emote_x                                        0x5EB220
#define CEverQuest__EnterZone_x                                    0x5E51A0
#define CEverQuest__GetBodyTypeDesc_x                              0x5EFB90
#define CEverQuest__GetClassDesc_x                                 0x5F01D0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5F07D0
#define CEverQuest__GetDeityDesc_x                                 0x5F8930
#define CEverQuest__GetLangDesc_x                                  0x5F0990
#define CEverQuest__GetRaceDesc_x                                  0x5F01B0
#define CEverQuest__InterpretCmd_x                                 0x5F8F00
#define CEverQuest__LeftClickedOnPlayer_x                          0x5D5D30
#define CEverQuest__LMouseUp_x                                     0x5D40C0
#define CEverQuest__RightClickedOnPlayer_x                         0x5D6610
#define CEverQuest__RMouseUp_x                                     0x5D5040
#define CEverQuest__SetGameState_x                                 0x5D18C0
#define CEverQuest__UPCNotificationFlush_x                         0x5F61D0
#define CEverQuest__IssuePetCommand_x                              0x5F1D90
#define CEverQuest__ReportSuccessfulHit_x                          0x5EC610

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x718830
#define CGaugeWnd__CalcLinesFillRect_x                             0x718890
#define CGaugeWnd__Draw_x                                          0x717EB0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ABE10
#define CGuild__GetGuildName_x                                     0x4AAEF0
#define CGuild__GetGuildIndex_x                                    0x4AB280

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x733C80

//CHotButton
#define CHotButton__SetButtonSize_x                                0x60BA60

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x740BD0
#define CInvSlotMgr__MoveItem_x                                    0x73F950
#define CInvSlotMgr__SelectSlot_x                                  0x740CA0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x73E200
#define CInvSlot__SliderComplete_x                                 0x73BF70
#define CInvSlot__GetItemBase_x                                    0x73B910
#define CInvSlot__UpdateItem_x                                     0x73BA80

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x742710
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7418C0
#define CInvSlotWnd__HandleLButtonUp_x                             0x742290

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7FBEF0
#define CItemDisplayWnd__UpdateStrings_x                           0x750D60
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x74AB30
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x74B030
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x751370
#define CItemDisplayWnd__AboutToShow_x                             0x7509B0
#define CItemDisplayWnd__WndNotification_x                         0x752440
#define CItemDisplayWnd__RequestConvertItem_x                      0x751F10
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x74FA10
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x7507D0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8349A0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x756970

// CLabel 
#define CLabel__Draw_x                                             0x75C360

// CListWnd
#define CListWnd__CListWnd_x                                       0x912AE0
#define CListWnd__dCListWnd_x                                      0x912E00
#define CListWnd__AddColumn_x                                      0x917270
#define CListWnd__AddColumn1_x                                     0x9172C0
#define CListWnd__AddLine_x                                        0x917650
#define CListWnd__AddString_x                                      0x917450
#define CListWnd__CalculateFirstVisibleLine_x                      0x917030
#define CListWnd__CalculateVSBRange_x                              0x916E10
#define CListWnd__ClearSel_x                                       0x917E30
#define CListWnd__ClearAllSel_x                                    0x917E90
#define CListWnd__CloseAndUpdateEditWindow_x                       0x9188A0
#define CListWnd__Compare_x                                        0x916750
#define CListWnd__Draw_x                                           0x912F30
#define CListWnd__DrawColumnSeparators_x                           0x915720
#define CListWnd__DrawHeader_x                                     0x915B90
#define CListWnd__DrawItem_x                                       0x916090
#define CListWnd__DrawLine_x                                       0x915890
#define CListWnd__DrawSeparator_x                                  0x9157C0
#define CListWnd__EnableLine_x                                     0x914FF0
#define CListWnd__EnsureVisible_x                                  0x9187C0
#define CListWnd__ExtendSel_x                                      0x917D60
#define CListWnd__GetColumnTooltip_x                               0x914B30
#define CListWnd__GetColumnMinWidth_x                              0x914BA0
#define CListWnd__GetColumnWidth_x                                 0x914AA0
#define CListWnd__GetCurSel_x                                      0x914430
#define CListWnd__GetItemAtPoint_x                                 0x915270
#define CListWnd__GetItemAtPoint1_x                                0x9152E0
#define CListWnd__GetItemData_x                                    0x9144B0
#define CListWnd__GetItemHeight_x                                  0x914870
#define CListWnd__GetItemIcon_x                                    0x914640
#define CListWnd__GetItemRect_x                                    0x9150E0
#define CListWnd__GetItemText_x                                    0x9144F0
#define CListWnd__GetSelList_x                                     0x917EE0
#define CListWnd__GetSeparatorRect_x                               0x915520
#define CListWnd__InsertLine_x                                     0x917A40
#define CListWnd__RemoveLine_x                                     0x917B90
#define CListWnd__SetColors_x                                      0x916DE0
#define CListWnd__SetColumnJustification_x                         0x916B20
#define CListWnd__SetColumnWidth_x                                 0x916A40
#define CListWnd__SetCurSel_x                                      0x917CA0
#define CListWnd__SetItemColor_x                                   0x918470
#define CListWnd__SetItemData_x                                    0x918430
#define CListWnd__SetItemText_x                                    0x918050
#define CListWnd__ShiftColumnSeparator_x                           0x916BE0
#define CListWnd__Sort_x                                           0x9168D0
#define CListWnd__ToggleSel_x                                      0x917CD0
#define CListWnd__SetColumnsSizable_x                              0x916C80
#define CListWnd__SetItemWnd_x                                     0x918300
#define CListWnd__GetItemWnd_x                                     0x914690
#define CListWnd__SetItemIcon_x                                    0x9180D0
#define CListWnd__CalculateCustomWindowPositions_x                 0x917130
#define CListWnd__SetVScrollPos_x                                  0x916A20

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x771B20
#define CMapViewWnd__GetWorldCoordinates_x                         0x770230
#define CMapViewWnd__HandleLButtonDown_x                           0x76D270

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x791A40
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x792320
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x792850
#define CMerchantWnd__SelectRecoverySlot_x                         0x7957D0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7905B0
#define CMerchantWnd__SelectBuySellSlot_x                          0x79B380
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x791660

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89C790
#define CPacketScrambler__hton_x                                   0x89C780

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x931BE0
#define CSidlManager__FindScreenPieceTemplate_x                    0x931FF0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x931DE0
#define CSidlManager__CreateLabel_x                                0x7F3350
#define CSidlManager__CreateXWndFromTemplate_x                     0x934F50
#define CSidlManager__CreateXWndFromTemplate1_x                    0x935130
#define CSidlManager__CreateXWnd_x                                 0x7F3280
#define CSidlManager__CreateHotButtonWnd_x                         0x7F3840

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x92E6A0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x92E5A0
#define CSidlScreenWnd__ConvertToRes_x                             0x953E60
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x92E030
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x92DD20
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x92DDF0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x92DEC0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x92EB40
#define CSidlScreenWnd__EnableIniStorage_x                         0x92F010
#define CSidlScreenWnd__GetSidlPiece_x                             0x92ED30
#define CSidlScreenWnd__Init1_x                                    0x92D920
#define CSidlScreenWnd__LoadIniInfo_x                              0x92F060
#define CSidlScreenWnd__LoadIniListWnd_x                           0x92FBC0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92CD20
#define CSidlScreenWnd__StoreIniInfo_x                             0x92F730
#define CSidlScreenWnd__StoreIniVis_x                              0x92FAA0
#define CSidlScreenWnd__WndNotification_x                          0x92EA50
#define CSidlScreenWnd__GetChildItem_x                             0x92EF90
#define CSidlScreenWnd__HandleLButtonUp_x                          0x91E650
#define CSidlScreenWnd__m_layoutCopy_x                             0x16CC3B0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x670130
#define CSkillMgr__GetSkillCap_x                                   0x670310
#define CSkillMgr__GetNameToken_x                                  0x66F8B0
#define CSkillMgr__IsActivatedSkill_x                              0x66F9F0
#define CSkillMgr__IsCombatSkill_x                                 0x66F930

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x93E980
#define CSliderWnd__SetValue_x                                     0x93E7F0
#define CSliderWnd__SetNumTicks_x                                  0x93E850

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7F9380

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x9471A0
#define CStmlWnd__CalculateHSBRange_x                              0x948280
#define CStmlWnd__CalculateVSBRange_x                              0x9481F0
#define CStmlWnd__CanBreakAtCharacter_x                            0x94C5C0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x94D250
#define CStmlWnd__ForceParseNow_x                                  0x947740
#define CStmlWnd__GetNextTagPiece_x                                0x94C520
#define CStmlWnd__GetSTMLText_x                                    0x4F7950
#define CStmlWnd__GetVisibleText_x                                 0x947760
#define CStmlWnd__InitializeWindowVariables_x                      0x94D0A0
#define CStmlWnd__MakeStmlColorTag_x                               0x946810
#define CStmlWnd__MakeWndNotificationTag_x                         0x946880
#define CStmlWnd__SetSTMLText_x                                    0x9458C0
#define CStmlWnd__StripFirstSTMLLines_x                            0x94E350
#define CStmlWnd__UpdateHistoryString_x                            0x94D460

// CTabWnd 
#define CTabWnd__Draw_x                                            0x944A10
#define CTabWnd__DrawCurrentPage_x                                 0x945140
#define CTabWnd__DrawTab_x                                         0x944E60
#define CTabWnd__GetCurrentPage_x                                  0x944210
#define CTabWnd__GetPageInnerRect_x                                0x944450
#define CTabWnd__GetTabInnerRect_x                                 0x944390
#define CTabWnd__GetTabRect_x                                      0x944240
#define CTabWnd__InsertPage_x                                      0x944660
#define CTabWnd__SetPage_x                                         0x9444D0
#define CTabWnd__SetPageRect_x                                     0x944950
#define CTabWnd__UpdatePage_x                                      0x944D20
#define CTabWnd__GetPageFromTabIndex_x                             0x944DA0
#define CTabWnd__GetCurrentTabIndex_x                              0x944200

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x756D40
#define CPageWnd__SetTabText_x                                     0x943D50

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A5AE0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91B4F0
#define CTextureFont__GetTextExtent_x                              0x91B6B0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6A3020
#define CHtmlComponentWnd__ValidateUri_x                           0x735670
#define CHtmlWnd__SetClientCallbacks_x                             0x610AE0
#define CHtmlWnd__AddObserver_x                                    0x610B00
#define CHtmlWnd__RemoveObserver_x                                 0x610B60
#define Window__getProgress_x                                      0x84D290
#define Window__getStatus_x                                        0x84D2B0
#define Window__getURI_x                                           0x84D2C0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9598F0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x908680

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E4DC0
#define CXStr__CXStr1_x                                            0x47BC60
#define CXStr__CXStr3_x                                            0x8EA060
#define CXStr__dCXStr_x                                            0x472E20
#define CXStr__operator_equal_x                                    0x8EA290
#define CXStr__operator_equal1_x                                   0x8EA2D0
#define CXStr__operator_plus_equal1_x                              0x8EAD60
#define CXStr__SetString_x                                         0x8ECC50
#define CXStr__operator_char_p_x                                   0x8EA7D0
#define CXStr__GetChar_x                                           0x8EC5A0
#define CXStr__Delete_x                                            0x8EBE50
#define CXStr__GetUnicode_x                                        0x8EC610
#define CXStr__GetLength_x                                         0x4A5890
#define CXStr__Mid_x                                               0x477B30
#define CXStr__Insert_x                                            0x8EC670
#define CXStr__FindNext_x                                          0x8EC2C0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93CC20
#define CXWnd__BringToTop_x                                        0x921DB0
#define CXWnd__Center_x                                            0x921930
#define CXWnd__ClrFocus_x                                          0x921750
#define CXWnd__Destroy_x                                           0x9217F0
#define CXWnd__DoAllDrawing_x                                      0x91DDE0
#define CXWnd__DrawChildren_x                                      0x91DDB0
#define CXWnd__DrawColoredRect_x                                   0x91E240
#define CXWnd__DrawTooltip_x                                       0x91C910
#define CXWnd__DrawTooltipAtPoint_x                                0x91C9D0
#define CXWnd__GetBorderFrame_x                                    0x91E0A0
#define CXWnd__GetChildWndAt_x                                     0x921E50
#define CXWnd__GetClientClipRect_x                                 0x920090
#define CXWnd__GetScreenClipRect_x                                 0x920130
#define CXWnd__GetScreenRect_x                                     0x9202B0
#define CXWnd__GetTooltipRect_x                                    0x91E290
#define CXWnd__GetWindowTextA_x                                    0x497420
#define CXWnd__IsActive_x                                          0x91E9D0
#define CXWnd__IsDescendantOf_x                                    0x920C90
#define CXWnd__IsReallyVisible_x                                   0x920CC0
#define CXWnd__IsType_x                                            0x9224C0
#define CXWnd__Move_x                                              0x920D30
#define CXWnd__Move1_x                                             0x920DE0
#define CXWnd__ProcessTransition_x                                 0x9218E0
#define CXWnd__Refade_x                                            0x9210C0
#define CXWnd__Resize_x                                            0x921360
#define CXWnd__Right_x                                             0x921B70
#define CXWnd__SetFocus_x                                          0x921710
#define CXWnd__SetFont_x                                           0x921780
#define CXWnd__SetKeyTooltip_x                                     0x9222E0
#define CXWnd__SetMouseOver_x                                      0x91F210
#define CXWnd__StartFade_x                                         0x920B70
#define CXWnd__GetChildItem_x                                      0x921FC0
#define CXWnd__SetParent_x                                         0x920A60
#define CXWnd__Minimize_x                                          0x9213D0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x954EE0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x924D80
#define CXWndManager__DrawWindows_x                                0x924DA0
#define CXWndManager__GetKeyboardFlags_x                           0x9275A0
#define CXWndManager__HandleKeyboardMsg_x                          0x927150
#define CXWndManager__RemoveWnd_x                                  0x9277F0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x927D40

// CDBStr
#define CDBStr__GetString_x                                        0x530600

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B84E0
#define EQ_Character__Cur_HP_x                                     0x4CE940
#define EQ_Character__Cur_Mana_x                                   0x4D6080
#define EQ_Character__GetCastingTimeModifier_x                     0x4BB550
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AF020
#define EQ_Character__GetFocusRangeModifier_x                      0x4AF170
#define EQ_Character__GetHPRegen_x                                 0x4DBE50
#define EQ_Character__GetEnduranceRegen_x                          0x4DC450
#define EQ_Character__GetManaRegen_x                               0x4DC890
#define EQ_Character__Max_Endurance_x                              0x636A20
#define EQ_Character__Max_HP_x                                     0x4CE770
#define EQ_Character__Max_Mana_x                                   0x636820
#define EQ_Character__doCombatAbility_x                            0x638E70
#define EQ_Character__UseSkill_x                                   0x4DE670
#define EQ_Character__GetConLevel_x                                0x62FC30
#define EQ_Character__IsExpansionFlag_x                            0x594040
#define EQ_Character__TotalEffect_x                                0x4C1E50
#define EQ_Character__GetPCSpellAffect_x                           0x4BC160
#define EQ_Character__SpellDuration_x                              0x4BBC90
#define EQ_Character__GetAdjustedSkill_x                           0x4D16C0
#define EQ_Character__GetBaseSkill_x                               0x4D2660
#define EQ_Character__CanUseItem_x                                 0x4D6390

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BB8F0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x64CF90

//PcClient
#define PcClient__PcClient_x                                       0x62D360

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6140
#define CCharacterListWnd__EnterWorld_x                            0x4B5B80
#define CCharacterListWnd__Quit_x                                  0x4B58D0
#define CCharacterListWnd__UpdateList_x                            0x4B5D10

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x611D30
#define EQ_Item__CreateItemTagString_x                             0x896020
#define EQ_Item__IsStackable_x                                     0x89AB50
#define EQ_Item__GetImageNum_x                                     0x897AB0
#define EQ_Item__CreateItemClient_x                                0x610F00
#define EQ_Item__GetItemValue_x                                    0x898DC0
#define EQ_Item__ValueSellMerchant_x                               0x89C360
#define EQ_Item__IsKeyRingItem_x                                   0x89A4A0
#define EQ_Item__CanGoInBag_x                                      0x611E50
#define EQ_Item__IsEmpty_x                                         0x899FF0
#define EQ_Item__GetMaxItemCount_x                                 0x8991E0
#define EQ_Item__GetHeldItem_x                                     0x897980
#define EQ_Item__GetAugmentFitBySlot_x                             0x895980

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x54EA70
#define EQ_LoadingS__Array_x                                       0xBF6688

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x637370
#define EQ_PC__GetAlternateAbilityId_x                             0x8A55A0
#define EQ_PC__GetCombatAbility_x                                  0x8A5C10
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A5C80
#define EQ_PC__GetItemRecastTimer_x                                0x6393F0
#define EQ_PC__HasLoreItem_x                                       0x6303F0
#define EQ_PC__AlertInventoryChanged_x                             0x62F560
#define EQ_PC__GetPcZoneClient_x                                   0x65BB60
#define EQ_PC__RemoveMyAffect_x                                    0x63C620
#define EQ_PC__GetKeyRingItems_x                                   0x8A64E0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A62A0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A67D0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x59A520
#define EQItemList__add_object_x                                   0x5C7390
#define EQItemList__add_item_x                                     0x59AA80
#define EQItemList__delete_item_x                                  0x59AAD0
#define EQItemList__FreeItemList_x                                 0x59A9D0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x52D120

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x64E810
#define EQPlayer__dEQPlayer_x                                      0x641B50
#define EQPlayer__DoAttack_x                                       0x656820
#define EQPlayer__EQPlayer_x                                       0x642210
#define EQPlayer__SetNameSpriteState_x                             0x6464F0
#define EQPlayer__SetNameSpriteTint_x                              0x6473C0
#define PlayerBase__HasProperty_j_x                                0x987510
#define EQPlayer__IsTargetable_x                                   0x9879B0
#define EQPlayer__CanSee_x                                         0x987810
#define EQPlayer__CanSee1_x                                        0x9878E0
#define PlayerBase__GetVisibilityLineSegment_x                     0x9875D0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x6595F0
#define PlayerZoneClient__GetLevel_x                               0x65BBA0
#define PlayerZoneClient__IsValidTeleport_x                        0x5C8500
#define PlayerZoneClient__LegalPlayerRace_x                        0x547DB0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x651680
#define EQPlayerManager__GetSpawnByName_x                          0x651730
#define EQPlayerManager__GetPlayerFromPartialName_x                0x6517C0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x615450
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x6154D0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x615510
#define KeypressHandler__ClearCommandStateArray_x                  0x616920
#define KeypressHandler__HandleKeyDown_x                           0x616940
#define KeypressHandler__HandleKeyUp_x                             0x6169E0
#define KeypressHandler__SaveKeymapping_x                          0x616E20

// MapViewMap 
#define MapViewMap__Clear_x                                        0x76D990
#define MapViewMap__SaveEx_x                                       0x770D50
#define MapViewMap__SetZoom_x                                      0x775410

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B9810

// StringTable 
#define StringTable__getString_x                                   0x8B4680

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x63C290
#define PcZoneClient__RemovePetEffect_x                            0x63C8C0
#define PcZoneClient__HasAlternateAbility_x                        0x636650
#define PcZoneClient__GetCurrentMod_x                              0x4E1730
#define PcZoneClient__GetModCap_x                                  0x4E1630
#define PcZoneClient__CanEquipItem_x                               0x636D10
#define PcZoneClient__GetItemByID_x                                0x639860
#define PcZoneClient__GetItemByItemClass_x                         0x6399B0
#define PcZoneClient__RemoveBuffEffect_x                           0x63C8E0
#define PcZoneClient__BandolierSwap_x                              0x637930
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x639390

//Doors
#define EQSwitch__UseSwitch_x                                      0x5CCFB0

//IconCache
#define IconCache__GetIcon_x                                       0x70E040

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x705B40
#define CContainerMgr__CloseContainer_x                            0x705E10
#define CContainerMgr__OpenExperimentContainer_x                   0x706890

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7C5980

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x609E80

//CLootWnd
#define CLootWnd__LootAll_x                                        0x763E50
#define CLootWnd__RequestLootSlot_x                                0x763080

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x567050
#define EQ_Spell__SpellAffects_x                                   0x5674C0
#define EQ_Spell__SpellAffectBase_x                                0x567280
#define EQ_Spell__IsStackable_x                                    0x4C6370
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C61C0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B34F0
#define EQ_Spell__IsSPAStacking_x                                  0x568310
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x567820
#define EQ_Spell__IsNoRemove_x                                     0x4C6350
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x568320
#define __IsResEffectSpell_x                                       0x4C57D0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4A9B40

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C3F70

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x80C6A0
#define CTargetWnd__WndNotification_x                              0x80BF30
#define CTargetWnd__RefreshTargetBuffs_x                           0x80C200
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x80B090

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x810CA0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x52AB30
#define CTaskManager__HandleMessage_x                              0x528FE0
#define CTaskManager__GetTaskStatus_x                              0x52ABE0
#define CTaskManager__GetElementDescription_x                      0x52AC60

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5625A0
#define EqSoundManager__PlayScriptMp3_x                            0x562700
#define EqSoundManager__SoundAssistPlay_x                          0x6740E0
#define EqSoundManager__WaveInstancePlay_x                         0x673650

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x51E960

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x943260

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x556420
#define CAltAbilityData__GetMercMaxRank_x                          0x5563B0
#define CAltAbilityData__GetMaxRank_x                              0x54BBB0

//CTargetRing
#define CTargetRing__Cast_x                                        0x607F90

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C61A0
#define CharacterBase__CreateItemGlobalIndex_x                     0x5045A0
#define CharacterBase__CreateItemIndex_x                           0x610090
#define CharacterBase__GetItemPossession_x                         0x4F0370
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CC570
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CC5D0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6ECBB0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6ED3E0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6ED490

//messages
#define msg_spell_worn_off_x                                       0x58C290
#define msg_new_text_x                                             0x581040
#define __msgTokenTextParam_x                                      0x58E7C0
#define msgTokenText_x                                             0x58EA10

//SpellManager
#define SpellManager__vftable_x                                    0xAC0C0C
#define SpellManager__SpellManager_x                               0x677410
#define Spellmanager__LoadTextSpells_x                             0x677D00
#define SpellManager__GetSpellByGroupAndRank_x                     0x6775E0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98B4E0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x504C50
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x592560
#define ItemGlobalIndex__IsEquippedLocation_x                      0x628B20
#define ItemGlobalIndex__IsValidIndex_x                            0x504CB0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C4910
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C4B90

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x75C6A0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x70A260
#define CCursorAttachment__AttachToCursor1_x                       0x70A2A0
#define CCursorAttachment__Deactivate_x                            0x70B270

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x935F70
#define CSidlManagerBase__CreatePageWnd_x                          0x935780
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x931A00
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x931990

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x953070
#define CEQSuiteTextureLoader__GetTexture_x                        0x952D30

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x501B30
#define CFindItemWnd__WndNotification_x                            0x502610
#define CFindItemWnd__Update_x                                     0x503150
#define CFindItemWnd__PickupSelectedItem_x                         0x5013A0

//IString
#define IString__Append_x                                          0x4F1B70

//Camera
#define CDisplay__cameraType_x                                     0xDCE94C
#define EverQuest__Cameras_x                                       0xE9229C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x509FE0
#define LootFiltersManager__GetItemFilterData_x                    0x5098F0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x509920
#define LootFiltersManager__SetItemLootFilter_x                    0x509B40

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B3960

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9910E0
#define CResolutionHandler__GetWindowedStyle_x                     0x66EC40

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x702910

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D72A0
#define CDistillerInfo__Instance_x                                 0x8D7240

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x722A60
#define CGroupWnd__UpdateDisplay_x                                 0x721DB0

//ItemBase
#define ItemBase__IsLore_x                                         0x89A500
#define ItemBase__IsLoreEquipped_x                                 0x89A580

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5C72F0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5C7430
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5C7490

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x664260
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x667BC0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x4F7FD0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4E6A50
#define FactionManagerClient__HandleFactionMessage_x               0x4E70C0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4E76C0
#define FactionManagerClient__GetMaxFaction_x                      0x4E76DF
#define FactionManagerClient__GetMinFaction_x                      0x4E7690

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4F0340

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91A540

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x496730

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4F05A0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x5558E0

//CTargetManager
#define CTargetManager__Get_x                                      0x67AC70

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x664260

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A58A0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x59A970

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF2F92C

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
