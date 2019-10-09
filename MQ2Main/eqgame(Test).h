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
#define __ExpectedVersionDate                                     "Oct  7 2019"
#define __ExpectedVersionTime                                     "19:45:36"
#define __ActualVersionDate_x                                      0xADE3AC
#define __ActualVersionTime_x                                      0xADE3A0
#define __ActualVersionBuild_x                                     0xADEE44

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x61B380
#define __MemChecker1_x                                            0x8EE5D0
#define __MemChecker2_x                                            0x6A9F60
#define __MemChecker3_x                                            0x6A9EB0
#define __MemChecker4_x                                            0x845AD0
#define __EncryptPad0_x                                            0xC0FA28
#define __EncryptPad1_x                                            0xC6DA20
#define __EncryptPad2_x                                            0xC202A8
#define __EncryptPad3_x                                            0xC1FEA8
#define __EncryptPad4_x                                            0xC5E1C8
#define __EncryptPad5_x                                            0xF372BC
#define __AC1_x                                                    0x802716
#define __AC2_x                                                    0x5D501F
#define __AC3_x                                                    0x5DC71F
#define __AC4_x                                                    0x5E05D0
#define __AC5_x                                                    0x5E68DF
#define __AC6_x                                                    0x5EAEF6
#define __AC7_x                                                    0x5D4A90
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FF134

// Direct Input
#define DI8__Main_x                                                0xF364B0
#define DI8__Keyboard_x                                            0xF364B4
#define DI8__Mouse_x                                               0xF36F58
#define DI8__Mouse_Copy_x                                          0xE91B74
#define DI8__Mouse_Check_x                                         0xF37280
#define __AutoSkillArray_x                                         0xE92A8C
#define __Attack_x                                                 0xF308A7
#define __Autofire_x                                               0xF308A8
#define __BindList_x                                               0xBFE480
#define g_eqCommandStates_x                                        0xBFF1F8
#define __Clicks_x                                                 0xE91C2C
#define __CommandList_x                                            0xBFFDB8
#define __CurrentMapLabel_x                                        0x1051944
#define __CurrentSocial_x                                          0xBE87CC
#define __DoAbilityList_x                                          0xEC83C8
#define __do_loot_x                                                0x5A1440
#define __DrawHandler_x                                            0x16CE2E0
#define __GroupCount_x                                             0xE81FC2
#define __Guilds_x                                                 0xE88380
#define __gWorld_x                                                 0xE821B0
#define __HWnd_x                                                   0xF36F5C
#define __heqmain_x                                                0xF36490
#define __InChatMode_x                                             0xE91B5C
#define __LastTell_x                                               0xE93AC4
#define __LMouseHeldTime_x                                         0xE91C98
#define __Mouse_x                                                  0xF3649C
#define __MouseLook_x                                              0xE91BF2
#define __MouseEventTime_x                                         0xF3138C
#define __gpbCommandEvent_x                                        0xE821BC
#define __NetStatusToggle_x                                        0xE91BF5
#define __PCNames_x                                                0xE93074
#define __RangeAttackReady_x                                       0xE92D70
#define __RMouseHeldTime_x                                         0xE91C94
#define __RunWalkState_x                                           0xE91B60
#define __ScreenMode_x                                             0xDCF7F4
#define __ScreenX_x                                                0xE91B14
#define __ScreenY_x                                                0xE91B10
#define __ScreenXMax_x                                             0xE91B18
#define __ScreenYMax_x                                             0xE91B1C
#define __ServerHost_x                                             0xE823F3
#define __ServerName_x                                             0xEC8388
#define __ShiftKeyDown_x                                           0xE921EC
#define __ShowNames_x                                              0xE92F2C
#define __Socials_x                                                0xEC8488
#define __SubscriptionType_x                                       0x10934C8
#define __TargetAggroHolder_x                                      0x10542F8
#define __ZoneType_x                                               0xE91FF0
#define __GroupAggro_x                                             0x1054338
#define __LoginName_x                                              0xF36C04
#define __Inviter_x                                                0xF30824
#define __AttackOnAssist_x                                         0xE92EE8
#define __UseTellWindows_x                                         0xE93210
#define __gfMaxZoomCameraDistance_x                                0xAD38D8
#define __gfMaxCameraDistance_x                                    0xB002B8
#define __pulAutoRun_x                                             0xE91C10
#define __pulForward_x                                             0xE93248
#define __pulBackward_x                                            0xE9324C
#define __pulTurnRight_x                                           0xE93250
#define __pulTurnLeft_x                                            0xE93254
#define __pulStrafeLeft_x                                          0xE93258
#define __pulStrafeRight_x                                         0xE9325C

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE84718
#define instEQZoneInfo_x                                           0xE91DE8
#define pinstActiveBanker_x                                        0xE821D4
#define pinstActiveCorpse_x                                        0xE821CC
#define pinstActiveGMaster_x                                       0xE821D0
#define pinstActiveMerchant_x                                      0xE821C8
#define pinstAltAdvManager_x                                       0xDD09F8
#define pinstBandageTarget_x                                       0xE821E4
#define pinstCamActor_x                                            0xDCF7E0
#define pinstCDBStr_x                                              0xDCF724
#define pinstCDisplay_x                                            0xE81FA4
#define pinstCEverQuest_x                                          0xF364CC
#define pinstEverQuestInfo_x                                       0xE91B08
#define pinstCharData_x                                            0xE81FA0
#define pinstCharSpawn_x                                           0xE8229C
#define pinstControlledMissile_x                                   0xE824FC
#define pinstControlledPlayer_x                                    0xE8229C
#define pinstCResolutionHandler_x                                  0x16CE510
#define pinstCSidlManager_x                                        0x16CD4A8
#define pinstCXWndManager_x                                        0x16CD4A4
#define instDynamicZone_x                                          0xE88258
#define pinstDZMember_x                                            0xE88368
#define pinstDZTimerInfo_x                                         0xE8836C
#define pinstEqLogin_x                                             0xF36550
#define instEQMisc_x                                               0xDCF668
#define pinstEQSoundManager_x                                      0xDD1920
#define pinstEQSpellStrings_x                                      0xC923F8
#define instExpeditionLeader_x                                     0xE882A2
#define instExpeditionName_x                                       0xE882E2
#define pinstGroup_x                                               0xE81FBE
#define pinstImeManager_x                                          0x16CD4A0
#define pinstLocalPlayer_x                                         0xE821C4
#define pinstMercenaryData_x                                       0xF32E7C
#define pinstMercenaryStats_x                                      0x1054444
#define pinstModelPlayer_x                                         0xE821DC
#define pinstPCData_x                                              0xE81FA0
#define pinstSkillMgr_x                                            0xF34FE0
#define pinstSpawnManager_x                                        0xF33A88
#define pinstSpellManager_x                                        0xF35200
#define pinstSpellSets_x                                           0xF294D0
#define pinstStringTable_x                                         0xE81FA8
#define pinstSwitchManager_x                                       0xE81CB8
#define pinstTarget_x                                              0xE82298
#define pinstTargetObject_x                                        0xE822A4
#define pinstTargetSwitch_x                                        0xE84708
#define pinstTaskMember_x                                          0xDCF4F8
#define pinstTrackTarget_x                                         0xE822A0
#define pinstTradeTarget_x                                         0xE821D8
#define instTributeActive_x                                        0xDCF689
#define pinstViewActor_x                                           0xDCF7DC
#define pinstWorldData_x                                           0xE81E08
#define pinstZoneAddr_x                                            0xE92088
#define pinstPlayerPath_x                                          0xF33B20
#define pinstTargetIndicator_x                                     0xF35468
#define EQObject_Top_x                                             0xE821C0
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDCF840
#define pinstCAchievementsWnd_x                                    0xDD0024
#define pinstCActionsWnd_x                                         0xDCF7E8
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDCFFB0
#define pinstCAdvancedLootWnd_x                                    0xDCFF80
#define pinstCAdventureLeaderboardWnd_x                            0x104B118
#define pinstCAdventureRequestWnd_x                                0x104B1C8
#define pinstCAdventureStatsWnd_x                                  0x104B278
#define pinstCAggroMeterWnd_x                                      0xDD0010
#define pinstCAlarmWnd_x                                           0xDCF8E4
#define pinstCAlertHistoryWnd_x                                    0xDCF8A8
#define pinstCAlertStackWnd_x                                      0xDCF800
#define pinstCAlertWnd_x                                           0xDCF81C
#define pinstCAltStorageWnd_x                                      0x104B5D8
#define pinstCAudioTriggersWindow_x                                0xC84728
#define pinstCAuraWnd_x                                            0xDCFFD8
#define pinstCAvaZoneWnd_x                                         0xDCF838
#define pinstCBandolierWnd_x                                       0xDD0008
#define pinstCBankWnd_x                                            0xDCFFD4
#define pinstCBarterMerchantWnd_x                                  0x104C818
#define pinstCBarterSearchWnd_x                                    0x104C8C8
#define pinstCBarterWnd_x                                          0x104C978
#define pinstCBazaarConfirmationWnd_x                              0xDD0050
#define pinstCBazaarSearchWnd_x                                    0xDCF7C0
#define pinstCBazaarWnd_x                                          0xDCF8A0
#define pinstCBlockedBuffWnd_x                                     0xDCFFDC
#define pinstCBlockedPetBuffWnd_x                                  0xDCFFFC
#define pinstCBodyTintWnd_x                                        0xDCF814
#define pinstCBookWnd_x                                            0xDD0034
#define pinstCBreathWnd_x                                          0xDCF858
#define pinstCBuffWindowNORMAL_x                                   0xDCFFC4
#define pinstCBuffWindowSHORT_x                                    0xDCFFC8
#define pinstCBugReportWnd_x                                       0xDCFFD0
#define pinstCButtonWnd_x                                          0x16CD710
#define pinstCCastingWnd_x                                         0xDD0020
#define pinstCCastSpellWnd_x                                       0xDCF854
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDCF8AC
#define pinstCChatWindowManager_x                                  0x104D438
#define pinstCClaimWnd_x                                           0x104D590
#define pinstCColorPickerWnd_x                                     0xDCF80C
#define pinstCCombatAbilityWnd_x                                   0xDCF8D8
#define pinstCCombatSkillsSelectWnd_x                              0xDCFAF4
#define pinstCCompassWnd_x                                         0xDCF804
#define pinstCConfirmationDialog_x                                 0x1052490
#define pinstCContainerMgr_x                                       0xDCF8A4
#define pinstCContextMenuManager_x                                 0x16CD460
#define pinstCCursorAttachment_x                                   0xDD0014
#define pinstCDynamicZoneWnd_x                                     0x104DB58
#define pinstCEditLabelWnd_x                                       0xDCFFC0
#define pinstCEQMainWnd_x                                          0x104DDA0
#define pinstCEventCalendarWnd_x                                   0xDCFF94
#define pinstCExtendedTargetWnd_x                                  0xDCFFF4
#define pinstCFacePick_x                                           0xDCFB74
#define pinstCFactionWnd_x                                         0xDCF88C
#define pinstCFellowshipWnd_x                                      0x104DFA0
#define pinstCFileSelectionWnd_x                                   0xDD001C
#define pinstCFindItemWnd_x                                        0xDCF874
#define pinstCFindLocationWnd_x                                    0x104E0F8
#define pinstCFriendsWnd_x                                         0xDCFF7C
#define pinstCGemsGameWnd_x                                        0xDCF884
#define pinstCGiveWnd_x                                            0xDCFAEC
#define pinstCGroupSearchFiltersWnd_x                              0xDD002C
#define pinstCGroupSearchWnd_x                                     0x104E4F0
#define pinstCGroupWnd_x                                           0x104E5A0
#define pinstCGuildBankWnd_x                                       0xE92ECC
#define pinstCGuildCreationWnd_x                                   0x104E700
#define pinstCGuildMgmtWnd_x                                       0x104E7B0
#define pinstCharacterCreation_x                                   0xDCFB00
#define pinstCHelpWnd_x                                            0xDCFFA8
#define pinstCHeritageSelectionWnd_x                               0xDCFF84
#define pinstCHotButtonWnd_x                                       0x1050908
#define pinstCHotButtonWnd1_x                                      0x1050908
#define pinstCHotButtonWnd2_x                                      0x105090C
#define pinstCHotButtonWnd3_x                                      0x1050910
#define pinstCHotButtonWnd4_x                                      0x1050914
#define pinstCIconSelectionWnd_x                                   0xDD000C
#define pinstCInspectWnd_x                                         0xDCFFA4
#define pinstCInventoryWnd_x                                       0xDCFF88
#define pinstCInvSlotMgr_x                                         0xDCF83C
#define pinstCItemDisplayManager_x                                 0x1050E98
#define pinstCItemExpTransferWnd_x                                 0x1050FCC
#define pinstCItemOverflowWnd_x                                    0xDCF7C4
#define pinstCJournalCatWnd_x                                      0xDD003C
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDCFFF0
#define pinstCKeyRingWnd_x                                         0xDCFFBC
#define pinstCLargeDialogWnd_x                                     0x1053110
#define pinstCLayoutCopyWnd_x                                      0x1051318
#define pinstCLFGuildWnd_x                                         0x10513C8
#define pinstCLoadskinWnd_x                                        0xDCF89C
#define pinstCLootFiltersCopyWnd_x                                 0xCA09F0
#define pinstCLootFiltersWnd_x                                     0xDCF808
#define pinstCLootSettingsWnd_x                                    0xDCF830
#define pinstCLootWnd_x                                            0xDD0040
#define pinstCMailAddressBookWnd_x                                 0xDCF844
#define pinstCMailCompositionWnd_x                                 0xDCF82C
#define pinstCMailIgnoreListWnd_x                                  0xDCF848
#define pinstCMailWnd_x                                            0xDCF7F0
#define pinstCManageLootWnd_x                                      0xDD0EA8
#define pinstCMapToolbarWnd_x                                      0xDCFFAC
#define pinstCMapViewWnd_x                                         0xDCFF98
#define pinstCMarketplaceWnd_x                                     0xDCF810
#define pinstCMerchantWnd_x                                        0xDD0048
#define pinstCMIZoneSelectWnd_x                                    0x1051C00
#define pinstCMusicPlayerWnd_x                                     0xDD004C
#define pinstCNameChangeMercWnd_x                                  0xDD0044
#define pinstCNameChangePetWnd_x                                   0xDD0028
#define pinstCNameChangeWnd_x                                      0xDD0054
#define pinstCNoteWnd_x                                            0xDCFF9C
#define pinstCObjectPreviewWnd_x                                   0xDCF828
#define pinstCOptionsWnd_x                                         0xDCFFA0
#define pinstCPetInfoWnd_x                                         0xDCF7CC
#define pinstCPetitionQWnd_x                                       0xDD0004
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDCF818
#define pinstCPlayerWnd_x                                          0xDCF7D0
#define pinstCPopupWndManager_x                                    0x1052490
#define pinstCProgressionSelectionWnd_x                            0x1052540
#define pinstCPurchaseGroupWnd_x                                   0xDCF860
#define pinstCPurchaseWnd_x                                        0xDCF850
#define pinstCPvPLeaderboardWnd_x                                  0x10525F0
#define pinstCPvPStatsWnd_x                                        0x10526A0
#define pinstCQuantityWnd_x                                        0xDCFFF8
#define pinstCRaceChangeWnd_x                                      0xDCF7D8
#define pinstCRaidOptionsWnd_x                                     0xDD0030
#define pinstCRaidWnd_x                                            0xDCF834
#define pinstCRealEstateItemsWnd_x                                 0xDD0018
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDCFFB4
#define pinstCRealEstateManageWnd_x                                0xDCF878
#define pinstCRealEstateNeighborhoodWnd_x                          0xDCF898
#define pinstCRealEstatePlotSearchWnd_x                            0xDCFAE8
#define pinstCRealEstatePurchaseWnd_x                              0xDCFB0C
#define pinstCRespawnWnd_x                                         0xDCFFE8
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDCF84C
#define pinstCSendMoneyWnd_x                                       0xDCFAF0
#define pinstCServerListWnd_x                                      0xDCFF8C
#define pinstCSkillsSelectWnd_x                                    0xDCF8BC
#define pinstCSkillsWnd_x                                          0xDCF880
#define pinstCSocialEditWnd_x                                      0xDCFFB8
#define pinstCSocialWnd_x                                          0xDD0038
#define pinstCSpellBookWnd_x                                       0xDCF8B8
#define pinstCStoryWnd_x                                           0xDCF7D4
#define pinstCTargetOfTargetWnd_x                                  0x10544C8
#define pinstCTargetWnd_x                                          0xDCFFE4
#define pinstCTaskOverlayWnd_x                                     0xDCF85C
#define pinstCTaskSelectWnd_x                                      0x1054620
#define pinstCTaskManager_x                                        0xCA1340
#define pinstCTaskTemplateSelectWnd_x                              0x10546D0
#define pinstCTaskWnd_x                                            0x1054780
#define pinstCTextEntryWnd_x                                       0xDCFFCC
#define pinstCTimeLeftWnd_x                                        0xDCFFE0
#define pinstCTipWndCONTEXT_x                                      0x1054984
#define pinstCTipWndOFDAY_x                                        0x1054980
#define pinstCTitleWnd_x                                           0x1054A30
#define pinstCTrackingWnd_x                                        0xDCFF90
#define pinstCTradeskillWnd_x                                      0x1054B98
#define pinstCTradeWnd_x                                           0xDCF824
#define pinstCTrainWnd_x                                           0xDCF820
#define pinstCTributeBenefitWnd_x                                  0x1054D98
#define pinstCTributeMasterWnd_x                                   0x1054E48
#define pinstCTributeTrophyWnd_x                                   0x1054EF8
#define pinstCVideoModesWnd_x                                      0xDCF8DC
#define pinstCVoiceMacroWnd_x                                      0xF35BD0
#define pinstCVoteResultsWnd_x                                     0xDD0000
#define pinstCVoteWnd_x                                            0xDCFFEC
#define pinstCWebManager_x                                         0xF3624C
#define pinstCZoneGuideWnd_x                                       0xDCF864
#define pinstCZonePathWnd_x                                        0xDCF888

#define pinstEQSuiteTextureLoader_x                                0xC6F510
#define pinstItemIconCache_x                                       0x104DD58
#define pinstLootFiltersManager_x                                  0xCA0AA0
#define pinstRewardSelectionWnd_x                                  0x1052DE8

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC1FE98
#define __CastRay_x                                                0x59C8A0
#define __CastRay2_x                                               0x59C8F0
#define __ConvertItemTags_x                                        0x5B8430
#define __CrashHandler_x                                           0x84F410
#define __CleanItemTags_x                                          0x477880
#define __DoesFileExist_x                                          0x8F1660
#define __EQGetTime_x                                              0x8EE0A0
#define __ExecuteCmd_x                                             0x595260
#define __FixHeading_x                                             0x989520
#define __GameLoop_x                                               0x6A9420
#define __get_bearing_x                                            0x59C410
#define __get_melee_range_x                                        0x59CAE0
#define __GetAnimationCache_x                                      0x70E6D0
#define __GetGaugeValueFromEQ_x                                    0x800BC0
#define __GetLabelFromEQ_x                                         0x8026A0
#define __GetXTargetType_x                                         0x98AFF0
#define __HandleMouseWheel_x                                       0x6AA010
#define __HeadingDiff_x                                            0x989590
#define __HelpPath_x                                               0xF30F7C
#define __LoadFrontEnd_x                                           0x6A5EF0
#define __NewUIINI_x                                               0x800890
#define __pCrashHandler_x                                          0x10722F8
#define __ProcessGameEvents_x                                      0x5FC760
#define __ProcessMouseEvent_x                                      0x5FBF20
#define __SaveColors_x                                             0x545D20
#define __STMLToText_x                                             0x92C950
#define __ToggleKeyRingItem_x                                      0x507D90
#define CMemoryMappedFile__SetFile_x                               0xA63720
#define CrashDetected_x                                            0x6A7970
#define DrawNetStatus_x                                            0x628600
#define Expansion_HoT_x                                            0xE92ED4
#define Teleport_Table_Size_x                                      0xE822AC
#define Teleport_Table_x                                           0xE82708
#define Util__FastTime_x                                           0x8EDC70
#define wwsCrashReportCheckForUploader_x                           0x850200
#define wwsCrashReportPlatformLaunchUploader_x                     0x8528E0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48ABA0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x493AB0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x493880
#define CAdvancedLootWnd__AddPlayerToList_x                        0x48E140
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x48D590

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x54D870
#define AltAdvManager__IsAbilityReady_x                            0x54C7F0
#define AltAdvManager__GetAAById_x                                 0x54C9F0
#define AltAdvManager__CanTrainAbility_x                           0x54CA60
#define AltAdvManager__CanSeeAbility_x                             0x54CDC0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C6AC0
#define CharacterZoneClient__HasSkill_x                            0x4D19B0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D30D0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BAF50
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B7550
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D5A70
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D5B50
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D5C30
#define CharacterZoneClient__FindAffectSlot_x                      0x4BFC00
#define CharacterZoneClient__BardCastBard_x                        0x4C2760
#define CharacterZoneClient__GetMaxEffects_x                       0x4B7620
#define CharacterZoneClient__GetEffect_x                           0x4B7490
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C0C50
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C0D20
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C0D70
#define CharacterZoneClient__CalcAffectChange_x                    0x4C0EC0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C1090
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4AF400
#define CharacterZoneClient__FindItemByGuid_x                      0x4D4030
#define CharacterZoneClient__FindItemByRecord_x                    0x4D3AB0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6CFDC0
#define CBankWnd__WndNotification_x                                0x6CFBA0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6DD570

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x60B170
#define CButtonWnd__CButtonWnd_x                                   0x928D00

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6FD780
#define CChatManager__InitContextMenu_x                            0x6F6910
#define CChatManager__FreeChatWindow_x                             0x6FC2A0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E5070
#define CChatManager__SetLockedActiveChatWindow_x                  0x6FD400
#define CChatManager__CreateChatWindow_x                           0x6FC8E0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E5180

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x93D3C0
#define CContextMenu__dCContextMenu_x                              0x93D5F0
#define CContextMenu__AddMenuItem_x                                0x93D600
#define CContextMenu__RemoveMenuItem_x                             0x93D910
#define CContextMenu__RemoveAllMenuItems_x                         0x93D930
#define CContextMenu__CheckMenuItem_x                              0x93D9B0
#define CContextMenu__SetMenuItem_x                                0x93D830
#define CContextMenu__AddSeparator_x                               0x93D790

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x93DF40
#define CContextMenuManager__RemoveMenu_x                          0x93DFB0
#define CContextMenuManager__PopupMenu_x                           0x93E070
#define CContextMenuManager__Flush_x                               0x93DEE0
#define CContextMenuManager__GetMenu_x                             0x495D40
#define CContextMenuManager__CreateDefaultMenu_x                   0x708EC0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8CEBE0
#define CChatService__GetFriendName_x                              0x8CEBF0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6FDFF0
#define CChatWindow__Clear_x                                       0x6FF2C0
#define CChatWindow__WndNotification_x                             0x6FFA50
#define CChatWindow__AddHistory_x                                  0x6FEB80

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93A820
#define CComboWnd__Draw_x                                          0x939D20
#define CComboWnd__GetCurChoice_x                                  0x93A660
#define CComboWnd__GetListRect_x                                   0x93A1C0
#define CComboWnd__GetTextRect_x                                   0x93A890
#define CComboWnd__InsertChoice_x                                  0x93A350
#define CComboWnd__SetColors_x                                     0x93A320
#define CComboWnd__SetChoice_x                                     0x93A630
#define CComboWnd__GetItemCount_x                                  0x93A670
#define CComboWnd__GetCurChoiceText_x                              0x93A6B0
#define CComboWnd__GetChoiceText_x                                 0x93A680
#define CComboWnd__InsertChoiceAtIndex_x                           0x93A3F0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x7068A0
#define CContainerWnd__vftable_x                                   0xAE765C
#define CContainerWnd__SetContainer_x                              0x707E10

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x5407C0
#define CDisplay__PreZoneMainUI_x                                  0x5407D0
#define CDisplay__CleanGameUI_x                                    0x545AE0
#define CDisplay__GetClickedActor_x                                0x538AE0
#define CDisplay__GetUserDefinedColor_x                            0x5311A0
#define CDisplay__GetWorldFilePath_x                               0x53A550
#define CDisplay__is3dON_x                                         0x535740
#define CDisplay__ReloadUI_x                                       0x53FC50
#define CDisplay__WriteTextHD2_x                                   0x535530
#define CDisplay__TrueDistance_x                                   0x53C210
#define CDisplay__SetViewActor_x                                   0x538400
#define CDisplay__GetFloorHeight_x                                 0x535800
#define CDisplay__SetRenderWindow_x                                0x534160
#define CDisplay__ToggleScreenshotMode_x                           0x537ED0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x95D280

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x940930
#define CEditWnd__GetCharIndexPt_x                                 0x941860
#define CEditWnd__GetDisplayString_x                               0x941700
#define CEditWnd__GetHorzOffset_x                                  0x93FF60
#define CEditWnd__GetLineForPrintableChar_x                        0x942A00
#define CEditWnd__GetSelStartPt_x                                  0x941B10
#define CEditWnd__GetSTMLSafeText_x                                0x941520
#define CEditWnd__PointFromPrintableChar_x                         0x942630
#define CEditWnd__SelectableCharFromPoint_x                        0x9427A0
#define CEditWnd__SetEditable_x                                    0x941BE0
#define CEditWnd__SetWindowTextA_x                                 0x9412A0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5EA3D0
#define CEverQuest__ClickedPlayer_x                                0x5DC500
#define CEverQuest__CreateTargetIndicator_x                        0x5F9A00
#define CEverQuest__DeleteTargetIndicator_x                        0x5F9A90
#define CEverQuest__DoTellWindow_x                                 0x4E5260
#define CEverQuest__OutputTextToLog_x                              0x4E54E0
#define CEverQuest__DropHeldItemOnGround_x                         0x5D1540
#define CEverQuest__dsp_chat_x                                     0x4E5870
#define CEverQuest__trimName_x                                     0x5F5CE0
#define CEverQuest__Emote_x                                        0x5EAC30
#define CEverQuest__EnterZone_x                                    0x5E4BB0
#define CEverQuest__GetBodyTypeDesc_x                              0x5EF5A0
#define CEverQuest__GetClassDesc_x                                 0x5EFBE0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5F01E0
#define CEverQuest__GetDeityDesc_x                                 0x5F8340
#define CEverQuest__GetLangDesc_x                                  0x5F03A0
#define CEverQuest__GetRaceDesc_x                                  0x5EFBC0
#define CEverQuest__InterpretCmd_x                                 0x5F8910
#define CEverQuest__LeftClickedOnPlayer_x                          0x5D5740
#define CEverQuest__LMouseUp_x                                     0x5D3AD0
#define CEverQuest__RightClickedOnPlayer_x                         0x5D6020
#define CEverQuest__RMouseUp_x                                     0x5D4A50
#define CEverQuest__SetGameState_x                                 0x5D12D0
#define CEverQuest__UPCNotificationFlush_x                         0x5F5BE0
#define CEverQuest__IssuePetCommand_x                              0x5F17A0
#define CEverQuest__ReportSuccessfulHit_x                          0x5EC020

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7187C0
#define CGaugeWnd__CalcLinesFillRect_x                             0x718820
#define CGaugeWnd__Draw_x                                          0x717E40

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ABE60
#define CGuild__GetGuildName_x                                     0x4AAF40
#define CGuild__GetGuildIndex_x                                    0x4AB2D0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x733C40

//CHotButton
#define CHotButton__SetButtonSize_x                                0x60B530

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x740B90
#define CInvSlotMgr__MoveItem_x                                    0x73F910
#define CInvSlotMgr__SelectSlot_x                                  0x740C60

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x73E1C0
#define CInvSlot__SliderComplete_x                                 0x73BF30
#define CInvSlot__GetItemBase_x                                    0x73B8D0
#define CInvSlot__UpdateItem_x                                     0x73BA40

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7426D0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x741880
#define CInvSlotWnd__HandleLButtonUp_x                             0x742250

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7FBF10
#define CItemDisplayWnd__UpdateStrings_x                           0x750D20
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x74AAF0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x74AFF0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x751330
#define CItemDisplayWnd__AboutToShow_x                             0x750970
#define CItemDisplayWnd__WndNotification_x                         0x752400
#define CItemDisplayWnd__RequestConvertItem_x                      0x751ED0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x74F9D0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x750790

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x834AB0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x756930

// CLabel 
#define CLabel__Draw_x                                             0x75C300

// CListWnd
#define CListWnd__CListWnd_x                                       0x912E10
#define CListWnd__dCListWnd_x                                      0x913130
#define CListWnd__AddColumn_x                                      0x9175A0
#define CListWnd__AddColumn1_x                                     0x9175F0
#define CListWnd__AddLine_x                                        0x917980
#define CListWnd__AddString_x                                      0x917780
#define CListWnd__CalculateFirstVisibleLine_x                      0x917360
#define CListWnd__CalculateVSBRange_x                              0x917140
#define CListWnd__ClearSel_x                                       0x918160
#define CListWnd__ClearAllSel_x                                    0x9181C0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x918BD0
#define CListWnd__Compare_x                                        0x916A80
#define CListWnd__Draw_x                                           0x913260
#define CListWnd__DrawColumnSeparators_x                           0x915A50
#define CListWnd__DrawHeader_x                                     0x915EC0
#define CListWnd__DrawItem_x                                       0x9163C0
#define CListWnd__DrawLine_x                                       0x915BC0
#define CListWnd__DrawSeparator_x                                  0x915AF0
#define CListWnd__EnableLine_x                                     0x915320
#define CListWnd__EnsureVisible_x                                  0x918AF0
#define CListWnd__ExtendSel_x                                      0x918090
#define CListWnd__GetColumnTooltip_x                               0x914E60
#define CListWnd__GetColumnMinWidth_x                              0x914ED0
#define CListWnd__GetColumnWidth_x                                 0x914DD0
#define CListWnd__GetCurSel_x                                      0x914760
#define CListWnd__GetItemAtPoint_x                                 0x9155A0
#define CListWnd__GetItemAtPoint1_x                                0x915610
#define CListWnd__GetItemData_x                                    0x9147E0
#define CListWnd__GetItemHeight_x                                  0x914BA0
#define CListWnd__GetItemIcon_x                                    0x914970
#define CListWnd__GetItemRect_x                                    0x915410
#define CListWnd__GetItemText_x                                    0x914820
#define CListWnd__GetSelList_x                                     0x918210
#define CListWnd__GetSeparatorRect_x                               0x915850
#define CListWnd__InsertLine_x                                     0x917D70
#define CListWnd__RemoveLine_x                                     0x917EC0
#define CListWnd__SetColors_x                                      0x917110
#define CListWnd__SetColumnJustification_x                         0x916E50
#define CListWnd__SetColumnWidth_x                                 0x916D70
#define CListWnd__SetCurSel_x                                      0x917FD0
#define CListWnd__SetItemColor_x                                   0x9187A0
#define CListWnd__SetItemData_x                                    0x918760
#define CListWnd__SetItemText_x                                    0x918380
#define CListWnd__ShiftColumnSeparator_x                           0x916F10
#define CListWnd__Sort_x                                           0x916C00
#define CListWnd__ToggleSel_x                                      0x918000
#define CListWnd__SetColumnsSizable_x                              0x916FB0
#define CListWnd__SetItemWnd_x                                     0x918630
#define CListWnd__GetItemWnd_x                                     0x9149C0
#define CListWnd__SetItemIcon_x                                    0x918400
#define CListWnd__CalculateCustomWindowPositions_x                 0x917460
#define CListWnd__SetVScrollPos_x                                  0x916D50

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x771C10
#define CMapViewWnd__GetWorldCoordinates_x                         0x770320
#define CMapViewWnd__HandleLButtonDown_x                           0x76D360

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x791D10
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7925F0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x792B20
#define CMerchantWnd__SelectRecoverySlot_x                         0x795AA0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x790880
#define CMerchantWnd__SelectBuySellSlot_x                          0x79B650
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x791930

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89C880
#define CPacketScrambler__hton_x                                   0x89C870

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x931FD0
#define CSidlManager__FindScreenPieceTemplate_x                    0x9323E0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9321D0
#define CSidlManager__CreateLabel_x                                0x7F33C0
#define CSidlManager__CreateXWndFromTemplate_x                     0x935340
#define CSidlManager__CreateXWndFromTemplate1_x                    0x935520
#define CSidlManager__CreateXWnd_x                                 0x7F32F0
#define CSidlManager__CreateHotButtonWnd_x                         0x7F38B0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x92EA90
#define CSidlScreenWnd__CalculateVSBRange_x                        0x92E990
#define CSidlScreenWnd__ConvertToRes_x                             0x954280
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x92E420
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x92E110
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x92E1E0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x92E2B0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x92EF30
#define CSidlScreenWnd__EnableIniStorage_x                         0x92F400
#define CSidlScreenWnd__GetSidlPiece_x                             0x92F120
#define CSidlScreenWnd__Init1_x                                    0x92DD10
#define CSidlScreenWnd__LoadIniInfo_x                              0x92F450
#define CSidlScreenWnd__LoadIniListWnd_x                           0x92FFB0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92D110
#define CSidlScreenWnd__StoreIniInfo_x                             0x92FB20
#define CSidlScreenWnd__StoreIniVis_x                              0x92FE90
#define CSidlScreenWnd__WndNotification_x                          0x92EE40
#define CSidlScreenWnd__GetChildItem_x                             0x92F380
#define CSidlScreenWnd__HandleLButtonUp_x                          0x91EA70
#define CSidlScreenWnd__m_layoutCopy_x                             0x16CD330

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x66F8A0
#define CSkillMgr__GetSkillCap_x                                   0x66FA80
#define CSkillMgr__GetNameToken_x                                  0x66F020
#define CSkillMgr__IsActivatedSkill_x                              0x66F160
#define CSkillMgr__IsCombatSkill_x                                 0x66F0A0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x93ED30
#define CSliderWnd__SetValue_x                                     0x93EBA0
#define CSliderWnd__SetNumTicks_x                                  0x93EC00

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7F9390

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x947570
#define CStmlWnd__CalculateHSBRange_x                              0x948650
#define CStmlWnd__CalculateVSBRange_x                              0x9485C0
#define CStmlWnd__CanBreakAtCharacter_x                            0x94C990
#define CStmlWnd__FastForwardToEndOfTag_x                          0x94D620
#define CStmlWnd__ForceParseNow_x                                  0x947B10
#define CStmlWnd__GetNextTagPiece_x                                0x94C8F0
#define CStmlWnd__GetSTMLText_x                                    0x4F7960
#define CStmlWnd__GetVisibleText_x                                 0x947B30
#define CStmlWnd__InitializeWindowVariables_x                      0x94D470
#define CStmlWnd__MakeStmlColorTag_x                               0x946BE0
#define CStmlWnd__MakeWndNotificationTag_x                         0x946C50
#define CStmlWnd__SetSTMLText_x                                    0x945C90
#define CStmlWnd__StripFirstSTMLLines_x                            0x94E720
#define CStmlWnd__UpdateHistoryString_x                            0x94D830

// CTabWnd 
#define CTabWnd__Draw_x                                            0x944DE0
#define CTabWnd__DrawCurrentPage_x                                 0x945510
#define CTabWnd__DrawTab_x                                         0x945230
#define CTabWnd__GetCurrentPage_x                                  0x9445E0
#define CTabWnd__GetPageInnerRect_x                                0x944820
#define CTabWnd__GetTabInnerRect_x                                 0x944760
#define CTabWnd__GetTabRect_x                                      0x944610
#define CTabWnd__InsertPage_x                                      0x944A30
#define CTabWnd__SetPage_x                                         0x9448A0
#define CTabWnd__SetPageRect_x                                     0x944D20
#define CTabWnd__UpdatePage_x                                      0x9450F0
#define CTabWnd__GetPageFromTabIndex_x                             0x945170
#define CTabWnd__GetCurrentTabIndex_x                              0x9445D0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x756D00
#define CPageWnd__SetTabText_x                                     0x944120

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A5AA0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91B910
#define CTextureFont__GetTextExtent_x                              0x91BAD0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6A2E00
#define CHtmlComponentWnd__ValidateUri_x                           0x735630
#define CHtmlWnd__SetClientCallbacks_x                             0x6105B0
#define CHtmlWnd__AddObserver_x                                    0x6105D0
#define CHtmlWnd__RemoveObserver_x                                 0x610630
#define Window__getProgress_x                                      0x84D110
#define Window__getStatus_x                                        0x84D130
#define Window__getURI_x                                           0x84D140

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x959D10

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x908A50

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E4EB0
#define CXStr__CXStr1_x                                            0x4F2B40
#define CXStr__CXStr3_x                                            0x8EA190
#define CXStr__dCXStr_x                                            0x472EE0
#define CXStr__operator_equal_x                                    0x8EA3C0
#define CXStr__operator_equal1_x                                   0x8EA400
#define CXStr__operator_plus_equal1_x                              0x8EAE90
#define CXStr__SetString_x                                         0x8ECD90
#define CXStr__operator_char_p_x                                   0x8EA8D0
#define CXStr__GetChar_x                                           0x8EC6C0
#define CXStr__Delete_x                                            0x8EBF90
#define CXStr__GetUnicode_x                                        0x8EC730
#define CXStr__GetLength_x                                         0x477C30
#define CXStr__Mid_x                                               0x477C40
#define CXStr__Insert_x                                            0x8EC790
#define CXStr__FindNext_x                                          0x8EC400

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93CFE0
#define CXWnd__BringToTop_x                                        0x9221D0
#define CXWnd__Center_x                                            0x921D50
#define CXWnd__ClrFocus_x                                          0x921B70
#define CXWnd__Destroy_x                                           0x921C10
#define CXWnd__DoAllDrawing_x                                      0x91E200
#define CXWnd__DrawChildren_x                                      0x91E1D0
#define CXWnd__DrawColoredRect_x                                   0x91E660
#define CXWnd__DrawTooltip_x                                       0x91CD30
#define CXWnd__DrawTooltipAtPoint_x                                0x91CDF0
#define CXWnd__GetBorderFrame_x                                    0x91E4C0
#define CXWnd__GetChildWndAt_x                                     0x922270
#define CXWnd__GetClientClipRect_x                                 0x9204B0
#define CXWnd__GetScreenClipRect_x                                 0x920550
#define CXWnd__GetScreenRect_x                                     0x9206D0
#define CXWnd__GetTooltipRect_x                                    0x91E6B0
#define CXWnd__GetWindowTextA_x                                    0x4974B0
#define CXWnd__IsActive_x                                          0x91EDF0
#define CXWnd__IsDescendantOf_x                                    0x9210B0
#define CXWnd__IsReallyVisible_x                                   0x9210E0
#define CXWnd__IsType_x                                            0x9228E0
#define CXWnd__Move_x                                              0x921150
#define CXWnd__Move1_x                                             0x921200
#define CXWnd__ProcessTransition_x                                 0x921D00
#define CXWnd__Refade_x                                            0x9214E0
#define CXWnd__Resize_x                                            0x921780
#define CXWnd__Right_x                                             0x921F90
#define CXWnd__SetFocus_x                                          0x921B30
#define CXWnd__SetFont_x                                           0x921BA0
#define CXWnd__SetKeyTooltip_x                                     0x922700
#define CXWnd__SetMouseOver_x                                      0x91F630
#define CXWnd__StartFade_x                                         0x920F90
#define CXWnd__GetChildItem_x                                      0x9223E0
#define CXWnd__SetParent_x                                         0x920E80
#define CXWnd__Minimize_x                                          0x9217F0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x955300

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x925150
#define CXWndManager__DrawWindows_x                                0x925170
#define CXWndManager__GetKeyboardFlags_x                           0x927970
#define CXWndManager__HandleKeyboardMsg_x                          0x927520
#define CXWndManager__RemoveWnd_x                                  0x927BC0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x928110

// CDBStr
#define CDBStr__GetString_x                                        0x530150

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B8530
#define EQ_Character__Cur_HP_x                                     0x4CE9F0
#define EQ_Character__Cur_Mana_x                                   0x4D6130
#define EQ_Character__GetCastingTimeModifier_x                     0x4BB5A0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AF040
#define EQ_Character__GetFocusRangeModifier_x                      0x4AF190
#define EQ_Character__GetHPRegen_x                                 0x4DBF00
#define EQ_Character__GetEnduranceRegen_x                          0x4DC500
#define EQ_Character__GetManaRegen_x                               0x4DC940
#define EQ_Character__Max_Endurance_x                              0x636360
#define EQ_Character__Max_HP_x                                     0x4CE820
#define EQ_Character__Max_Mana_x                                   0x636160
#define EQ_Character__doCombatAbility_x                            0x6387B0
#define EQ_Character__UseSkill_x                                   0x4DE720
#define EQ_Character__GetConLevel_x                                0x62F570
#define EQ_Character__IsExpansionFlag_x                            0x593A40
#define EQ_Character__TotalEffect_x                                0x4C1EA0
#define EQ_Character__GetPCSpellAffect_x                           0x4BC1B0
#define EQ_Character__SpellDuration_x                              0x4BBCE0
#define EQ_Character__GetAdjustedSkill_x                           0x4D1770
#define EQ_Character__GetBaseSkill_x                               0x4D2710
#define EQ_Character__CanUseItem_x                                 0x4D6440

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BBA50

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x64C950

//PcClient
#define PcClient__PcClient_x                                       0x62CCA0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6160
#define CCharacterListWnd__EnterWorld_x                            0x4B5BA0
#define CCharacterListWnd__Quit_x                                  0x4B58F0
#define CCharacterListWnd__UpdateList_x                            0x4B5D30

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x611800
#define EQ_Item__CreateItemTagString_x                             0x896120
#define EQ_Item__IsStackable_x                                     0x89AC40
#define EQ_Item__GetImageNum_x                                     0x897BB0
#define EQ_Item__CreateItemClient_x                                0x6109D0
#define EQ_Item__GetItemValue_x                                    0x898EB0
#define EQ_Item__ValueSellMerchant_x                               0x89C450
#define EQ_Item__IsKeyRingItem_x                                   0x89A590
#define EQ_Item__CanGoInBag_x                                      0x611920
#define EQ_Item__IsEmpty_x                                         0x89A0E0
#define EQ_Item__GetMaxItemCount_x                                 0x8992D0
#define EQ_Item__GetHeldItem_x                                     0x897A80
#define EQ_Item__GetAugmentFitBySlot_x                             0x895A80

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x54E540
#define EQ_LoadingS__Array_x                                       0xBF7688

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x636CB0
#define EQ_PC__GetAlternateAbilityId_x                             0x8A55D0
#define EQ_PC__GetCombatAbility_x                                  0x8A5C40
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A5CB0
#define EQ_PC__GetItemRecastTimer_x                                0x638D30
#define EQ_PC__HasLoreItem_x                                       0x62FD30
#define EQ_PC__AlertInventoryChanged_x                             0x62EEA0
#define EQ_PC__GetPcZoneClient_x                                   0x65B380
#define EQ_PC__RemoveMyAffect_x                                    0x63BF60
#define EQ_PC__GetKeyRingItems_x                                   0x8A6510
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A62D0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A6800

// EQItemList 
#define EQItemList__EQItemList_x                                   0x599F10
#define EQItemList__add_object_x                                   0x5C6D10
#define EQItemList__add_item_x                                     0x59A470
#define EQItemList__delete_item_x                                  0x59A4C0
#define EQItemList__FreeItemList_x                                 0x59A3C0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x52CC70

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x64E1D0
#define EQPlayer__dEQPlayer_x                                      0x641510
#define EQPlayer__DoAttack_x                                       0x656040
#define EQPlayer__EQPlayer_x                                       0x641BD0
#define EQPlayer__SetNameSpriteState_x                             0x645EB0
#define EQPlayer__SetNameSpriteTint_x                              0x646D80
#define PlayerBase__HasProperty_j_x                                0x9878F0
#define EQPlayer__IsTargetable_x                                   0x987D90
#define EQPlayer__CanSee_x                                         0x987BF0
#define EQPlayer__CanSee1_x                                        0x987CC0
#define PlayerBase__GetVisibilityLineSegment_x                     0x9879B0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x658E10
#define PlayerZoneClient__GetLevel_x                               0x65B3C0
#define PlayerZoneClient__IsValidTeleport_x                        0x5C7E80
#define PlayerZoneClient__LegalPlayerRace_x                        0x547910

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x650F30
#define EQPlayerManager__GetSpawnByName_x                          0x650FE0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x651070

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x614F20
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x614FA0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x614FE0
#define KeypressHandler__ClearCommandStateArray_x                  0x6163F0
#define KeypressHandler__HandleKeyDown_x                           0x616410
#define KeypressHandler__HandleKeyUp_x                             0x6164B0
#define KeypressHandler__SaveKeymapping_x                          0x6168F0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x76DA80
#define MapViewMap__SaveEx_x                                       0x770E40
#define MapViewMap__SetZoom_x                                      0x775500

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B9970

// StringTable 
#define StringTable__getString_x                                   0x8B46F0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x63BBD0
#define PcZoneClient__RemovePetEffect_x                            0x63C200
#define PcZoneClient__HasAlternateAbility_x                        0x635F90
#define PcZoneClient__GetCurrentMod_x                              0x4E17E0
#define PcZoneClient__GetModCap_x                                  0x4E16E0
#define PcZoneClient__CanEquipItem_x                               0x636650
#define PcZoneClient__GetItemByID_x                                0x6391A0
#define PcZoneClient__GetItemByItemClass_x                         0x6392F0
#define PcZoneClient__RemoveBuffEffect_x                           0x63C220
#define PcZoneClient__BandolierSwap_x                              0x637270
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x638CD0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5CC980

//IconCache
#define IconCache__GetIcon_x                                       0x70DF70

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x705A40
#define CContainerMgr__CloseContainer_x                            0x705D10
#define CContainerMgr__OpenExperimentContainer_x                   0x706790

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7C5B30

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x609950

//CLootWnd
#define CLootWnd__LootAll_x                                        0x763DE0
#define CLootWnd__RequestLootSlot_x                                0x763010

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x566A70
#define EQ_Spell__SpellAffects_x                                   0x566EE0
#define EQ_Spell__SpellAffectBase_x                                0x566CA0
#define EQ_Spell__IsStackable_x                                    0x4C6420
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C6270
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B3510
#define EQ_Spell__IsSPAStacking_x                                  0x567D30
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x567240
#define EQ_Spell__IsNoRemove_x                                     0x4C6400
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x567D40
#define __IsResEffectSpell_x                                       0x4C5820

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4A9B90

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C40C0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x80C650
#define CTargetWnd__WndNotification_x                              0x80BEE0
#define CTargetWnd__RefreshTargetBuffs_x                           0x80C1B0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x80B040

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x810C50

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x52A6B0
#define CTaskManager__HandleMessage_x                              0x528B60
#define CTaskManager__GetTaskStatus_x                              0x52A760
#define CTaskManager__GetElementDescription_x                      0x52A7E0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x561FA0
#define EqSoundManager__PlayScriptMp3_x                            0x562100
#define EqSoundManager__SoundAssistPlay_x                          0x6737F0
#define EqSoundManager__WaveInstancePlay_x                         0x672D60

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x51E470

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x943630

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x555EA0
#define CAltAbilityData__GetMercMaxRank_x                          0x555E30
#define CAltAbilityData__GetMaxRank_x                              0x54B6B0

//CTargetRing
#define CTargetRing__Cast_x                                        0x607A70

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C6250
#define CharacterBase__CreateItemGlobalIndex_x                     0x5045E0
#define CharacterBase__CreateItemIndex_x                           0x60FB60
#define CharacterBase__GetItemPossession_x                         0x4F0410
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CC6C0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CC720
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6ECAF0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6ED320
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6ED3D0

//messages
#define msg_spell_worn_off_x                                       0x58BCC0
#define msg_new_text_x                                             0x580A70
#define __msgTokenTextParam_x                                      0x58E1F0
#define msgTokenText_x                                             0x58E440

//SpellManager
#define SpellManager__vftable_x                                    0xAC1BFC
#define SpellManager__SpellManager_x                               0x676B20
#define Spellmanager__LoadTextSpells_x                             0x677410
#define SpellManager__GetSpellByGroupAndRank_x                     0x676CF0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98B8E0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x504D00
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x591FC0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x628460
#define ItemGlobalIndex__IsValidIndex_x                            0x504D60

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C4A60
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C4CE0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x75C640

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x70A160
#define CCursorAttachment__AttachToCursor1_x                       0x70A1A0
#define CCursorAttachment__Deactivate_x                            0x70B170

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x936360
#define CSidlManagerBase__CreatePageWnd_x                          0x935B70
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x931DF0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x931D80

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x953770
#define CEQSuiteTextureLoader__GetTexture_x                        0x953430

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x501B80
#define CFindItemWnd__WndNotification_x                            0x502660
#define CFindItemWnd__Update_x                                     0x5031A0
#define CFindItemWnd__PickupSelectedItem_x                         0x5013F0

//IString
#define IString__Append_x                                          0x4F1C50

//Camera
#define CDisplay__cameraType_x                                     0xDCF8CC
#define EverQuest__Cameras_x                                       0xE9321C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x50A050
#define LootFiltersManager__GetItemFilterData_x                    0x509960
#define LootFiltersManager__RemoveItemLootFilter_x                 0x509990
#define LootFiltersManager__SetItemLootFilter_x                    0x509BB0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B3B10

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x991570
#define CResolutionHandler__GetWindowedStyle_x                     0x66E2B0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x702750

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D7410
#define CDistillerInfo__Instance_x                                 0x8D73B0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x722A40
#define CGroupWnd__UpdateDisplay_x                                 0x721D90

//ItemBase
#define ItemBase__IsLore_x                                         0x89A5F0
#define ItemBase__IsLoreEquipped_x                                 0x89A670

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5C6C70
#define EQPlacedItemManager__GetItemByGuid_x                       0x5C6DB0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5C6E10

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x663AF0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x667450

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x4F7F70

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4E6BF0
#define FactionManagerClient__HandleFactionMessage_x               0x4E7260
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4E7860
#define FactionManagerClient__GetMaxFaction_x                      0x4E787F
#define FactionManagerClient__GetMinFaction_x                      0x4E7830

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4F03E0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91A8C0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x4967C0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4F0680

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x555360

//CTargetManager
#define CTargetManager__Get_x                                      0x67A370

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x663AF0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A5860

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x59A360

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF308AC

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
