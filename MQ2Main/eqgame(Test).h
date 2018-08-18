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
#define __ExpectedVersionDate                                     "Aug 16 2018"
#define __ExpectedVersionTime                                     "15:46:58"
#define __ActualVersionDate_x                                      0xABF73C
#define __ActualVersionTime_x                                      0xABF730

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x60A130
#define __MemChecker1_x                                            0x8DAB90
#define __MemChecker2_x                                            0x698810
#define __MemChecker3_x                                            0x698760
#define __MemChecker4_x                                            0x834330
#define __EncryptPad0_x                                            0xBF14B0
#define __EncryptPad1_x                                            0xC4F190
#define __EncryptPad2_x                                            0xC02038
#define __EncryptPad3_x                                            0xC01C38
#define __EncryptPad4_x                                            0xC3FF28
#define __EncryptPad5_x                                            0xF0CBC8
#define __AC1_x                                                    0x7F0ED6
#define __AC2_x                                                    0x5C5D0F
#define __AC3_x                                                    0x5CCB9F
#define __AC4_x                                                    0x5D0A10
#define __AC5_x                                                    0x5D6C30
#define __AC6_x                                                    0x5DB172
#define __AC7_x                                                    0x5C5780
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1ADAC4

// Direct Input
#define DI8__Main_x                                                0xF0CBEC
#define DI8__Keyboard_x                                            0xF0CBF0
#define DI8__Mouse_x                                               0xF0CBB0
#define DI8__Mouse_Copy_x                                          0xE6A91C
#define DI8__Mouse_Check_x                                         0xF0DAB0
#define __AutoSkillArray_x                                         0xE6B82C
#define __Attack_x                                                 0xF0962B
#define __Autofire_x                                               0xF0962C
#define __BindList_x                                               0xBE00A0
#define g_eqCommandStates_x                                        0xBE0E10
#define __Clicks_x                                                 0xE6A9D4
#define __CommandList_x                                            0xBE19C8
#define __CurrentMapLabel_x                                        0x101F1D4
#define __CurrentSocial_x                                          0xBCB710
#define __DoAbilityList_x                                          0xEA114C
#define __do_loot_x                                                0x593210
#define __DrawHandler_x                                            0x169A6E8
#define __GroupCount_x                                             0xE5ABE2
#define __Guilds_x                                                 0xE61128
#define __gWorld_x                                                 0xE5B13C
#define __HWnd_x                                                   0xF0CBB4
#define __heqmain_x                                                0x1017E0C
#define __InChatMode_x                                             0xE6A904
#define __LastTell_x                                               0xE6C848
#define __LMouseHeldTime_x                                         0xE6AA40
#define __Mouse_x                                                  0xF0CBD4
#define __MouseLook_x                                              0xE6A99A
#define __MouseEventTime_x                                         0xF0A0E0
#define __gpbCommandEvent_x                                        0xE5AE68
#define __NetStatusToggle_x                                        0xE6A99D
#define __PCNames_x                                                0xE6BE08
#define __RangeAttackReady_x                                       0xE6BB10
#define __RMouseHeldTime_x                                         0xE6AA3C
#define __RunWalkState_x                                           0xE6A908
#define __ScreenMode_x                                             0xDA948C
#define __ScreenX_x                                                0xE6A8BC
#define __ScreenY_x                                                0xE6A8B8
#define __ScreenXMax_x                                             0xE6A8C0
#define __ScreenYMax_x                                             0xE6A8C4
#define __ServerHost_x                                             0xE5B033
#define __ServerName_x                                             0xEA110C
#define __ShiftKeyDown_x                                           0xE6AF94
#define __ShowNames_x                                              0xE6BCCC
#define __Socials_x                                                0xEA120C
#define __SubscriptionType_x                                       0x1060C9C
#define __TargetAggroHolder_x                                      0x1021B8C
#define __ZoneType_x                                               0xE6AD98
#define __GroupAggro_x                                             0x1021BCC
#define __LoginName_x                                              0xF0D444
#define __Inviter_x                                                0xF095A8
#define __AttackOnAssist_x                                         0xE6BC88
#define __UseTellWindows_x                                         0xE6BFA0
#define __gfMaxZoomCameraDistance_x                                0xAB4B50
#define __gfMaxCameraDistance_x                                    0xAE20D8
#define __pulAutoRun_x                                             0xE6A9B8
#define __pulForward_x                                             0xE6BFD8
#define __pulBackward_x                                            0xE6BFDC
#define __pulTurnRight_x                                           0xE6BFE0
#define __pulTurnLeft_x                                            0xE6BFE4
#define __pulStrafeLeft_x                                          0xE6BFE8
#define __pulStrafeRight_x                                         0xE6BFEC

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE5D4D0
#define instEQZoneInfo_x                                           0xE6AB90
#define instKeypressHandler_x                                      0xF0A090
#define pinstActiveBanker_x                                        0xE5D484
#define pinstActiveCorpse_x                                        0xE5D47C
#define pinstActiveGMaster_x                                       0xE5D480
#define pinstActiveMerchant_x                                      0xE5D478
#define pinstAggroInfo_x                                           0xC65858
#define pinstAltAdvManager_x                                       0xDA9E70
#define pinstAuraMgr_x                                             0xC76540
#define pinstBandageTarget_x                                       0xE5D494
#define pinstCamActor_x                                            0xDA9480
#define pinstCDBStr_x                                              0xDA8BAC
#define pinstCDisplay_x                                            0xE5ADD0
#define pinstCEverQuest_x                                          0xF0CD08
#define pinstEverQuestInfo_x                                       0xE6A8B0
#define pinstCharData_x                                            0xE5ADE0
#define pinstCharSpawn_x                                           0xE5ABC0
#define pinstControlledMissile_x                                   0xE5ADE4
#define pinstControlledPlayer_x                                    0xE5ABC0
#define pinstCResolutionHandler_x                                  0x169A918
#define pinstCSidlManager_x                                        0x16997AC
#define pinstCXWndManager_x                                        0x16997A0
#define instDynamicZone_x                                          0xE61000
#define pinstDZMember_x                                            0xE61110
#define pinstDZTimerInfo_x                                         0xE61114
#define pinstEQItemList_x                                          0xE596C0
#define pinstEQObjectList_x                                        0xE5A8B0
#define instEQMisc_x                                               0xDA8AE8
#define pinstEQSoundManager_x                                      0xDAA6D0
#define pinstEQSpellStrings_x                                      0xC73990
#define instExpeditionLeader_x                                     0xE6104A
#define instExpeditionName_x                                       0xE6108A
#define pinstGroup_x                                               0xE5ABDE
#define pinstImeManager_x                                          0x16997A4
#define pinstLocalPlayer_x                                         0xE5D474
#define pinstMercenaryData_x                                       0xF0A880
#define pinstMercenaryStats_x                                      0x1021CD8
#define pinstMercAltAbilities_x                                    0xDAA440
#define pinstModelPlayer_x                                         0xE5D48C
#define pinstPCData_x                                              0xE5ADE0
#define pinstRealEstateItems_x                                     0xF0BD70
#define pinstSkillMgr_x                                            0xF0BE40
#define pinstSpawnManager_x                                        0xF0B430
#define pinstSpellManager_x                                        0xF0C018
#define pinstSpellSets_x                                           0xF02254
#define pinstStringTable_x                                         0xE5D348
#define pinstSwitchManager_x                                       0xE5AA70
#define pinstTarget_x                                              0xE5D4C8
#define pinstTargetObject_x                                        0xE5ABC8
#define pinstTargetSwitch_x                                        0xE5ADEC
#define pinstTaskMember_x                                          0xDA8978
#define pinstTrackTarget_x                                         0xE5ABC4
#define pinstTradeTarget_x                                         0xE5D488
#define instTributeActive_x                                        0xDA8B0D
#define pinstViewActor_x                                           0xDA947C
#define pinstWorldData_x                                           0xE5AE20
#define pinstZoneAddr_x                                            0xE6AE30
#define pinstPlayerPath_x                                          0xF0B4C8
#define pinstTargetIndicator_x                                     0xF0C280
#define pinstCTargetManager_x                                      0xF0C318
#define EQObject_Top_x                                             0xE5D470
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDA8EEC
#define pinstCAchievementsWnd_x                                    0xDA8F8C
#define pinstCActionsWnd_x                                         0xDA8F44
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDA8CD0
#define pinstCAdvancedLootWnd_x                                    0xDA8C80
#define pinstCAdventureLeaderboardWnd_x                            0x10189A8
#define pinstCAdventureRequestWnd_x                                0x1018A58
#define pinstCAdventureStatsWnd_x                                  0x1018B08
#define pinstCAggroMeterWnd_x                                      0xDA8FB4
#define pinstCAlarmWnd_x                                           0xDA8F70
#define pinstCAlertHistoryWnd_x                                    0xDA8F4C
#define pinstCAlertStackWnd_x                                      0xDA8EE8
#define pinstCAlertWnd_x                                           0xDA8EFC
#define pinstCAltStorageWnd_x                                      0x1018E68
#define pinstCAudioTriggersWindow_x                                0xC65CE8
#define pinstCAuraWnd_x                                            0xDA8FAC
#define pinstCAvaZoneWnd_x                                         0xDA8F30
#define pinstCBandolierWnd_x                                       0xDA8FEC
#define pinstCBankWnd_x                                            0xDA8C78
#define pinstCBarterMerchantWnd_x                                  0x101A0A8
#define pinstCBarterSearchWnd_x                                    0x101A158
#define pinstCBarterWnd_x                                          0x101A208
#define pinstCBazaarConfirmationWnd_x                              0xDA8EE0
#define pinstCBazaarSearchWnd_x                                    0xDA8F54
#define pinstCBazaarWnd_x                                          0xDA8FE4
#define pinstCBlockedBuffWnd_x                                     0xDA8C60
#define pinstCBlockedPetBuffWnd_x                                  0xDA8C8C
#define pinstCBodyTintWnd_x                                        0xDA8F08
#define pinstCBookWnd_x                                            0xDA9478
#define pinstCBreathWnd_x                                          0xDA8EF8
#define pinstCBuffWindowNORMAL_x                                   0xDA94D4
#define pinstCBuffWindowSHORT_x                                    0xDA8C48
#define pinstCBugReportWnd_x                                       0xDA8CD8
#define pinstCButtonWnd_x                                          0x1699998
#define pinstCCastingWnd_x                                         0xDA8CD4
#define pinstCCastSpellWnd_x                                       0xDA8F6C
//#define pinstCCharacterCreationWnd_x                               0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDA8F04
#define pinstCChatWindowManager_x                                  0x101ACC8
#define pinstCClaimWnd_x                                           0x101AE20
#define pinstCColorPickerWnd_x                                     0xDA8F1C
#define pinstCCombatAbilityWnd_x                                   0xDA8FBC
#define pinstCCombatSkillsSelectWnd_x                              0xDA8F40
#define pinstCCompassWnd_x                                         0xDA8EF0
#define pinstCConfirmationDialog_x                                 0x101FD20
#define pinstCContainerMgr_x                                       0xDA8FE0
#define pinstCContextMenuManager_x                                 0x1699760
#define pinstCCursorAttachment_x                                   0xDA8CCC
#define pinstCDynamicZoneWnd_x                                     0x101B3E8
#define pinstCEditLabelWnd_x                                       0xDA94A0
#define pinstCEQMainWnd_x                                          0x101B630
#define pinstCEventCalendarWnd_x                                   0xDA8FB0
#define pinstCExtendedTargetWnd_x                                  0xDA8FA4
#define pinstCFacePick_x                                           0xDA8F24
#define pinstCFellowshipWnd_x                                      0x101B830
#define pinstCFileSelectionWnd_x                                   0xDA8C64
#define pinstCFindItemWnd_x                                        0xDA8FD8
#define pinstCFindLocationWnd_x                                    0x101B988
#define pinstCFriendsWnd_x                                         0xDA8F58
#define pinstCGemsGameWnd_x                                        0xDA8F48
#define pinstCGiveWnd_x                                            0xDA9474
#define pinstCGroupSearchFiltersWnd_x                              0xDA8FC8
#define pinstCGroupSearchWnd_x                                     0x101BD80
#define pinstCGroupWnd_x                                           0x101BE30
#define pinstCGuildBankWnd_x                                       0xE6BC6C
#define pinstCGuildCreationWnd_x                                   0x101BF90
#define pinstCGuildMgmtWnd_x                                       0x101C040
#define pinstCharacterCreation_x                                   0xDA8FB8
#define pinstCHelpWnd_x                                            0xDA8F7C
#define pinstCHeritageSelectionWnd_x                               0xDA8F2C
#define pinstCHotButtonWnd_x                                       0x101E198
#define pinstCHotButtonWnd1_x                                      0x101E198
#define pinstCHotButtonWnd2_x                                      0x101E19C
#define pinstCHotButtonWnd3_x                                      0x101E1A0
#define pinstCHotButtonWnd4_x                                      0x101E1A4
#define pinstCIconSelectionWnd_x                                   0xDA8CA4
#define pinstCInspectWnd_x                                         0xDA8C94
#define pinstCInventoryWnd_x                                       0xDA8FFC
#define pinstCInvSlotMgr_x                                         0xDA8F90
#define pinstCItemDisplayManager_x                                 0x101E728
#define pinstCItemExpTransferWnd_x                                 0x101E858
#define pinstCItemOverflowWnd_x                                    0xDA8F5C
#define pinstCJournalCatWnd_x                                      0xDA8C90
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDA94CC
#define pinstCKeyRingWnd_x                                         0xDA8C50
#define pinstCLargeDialogWnd_x                                     0x10209A0
#define pinstCLayoutCopyWnd_x                                      0x101EBA8
#define pinstCLFGuildWnd_x                                         0x101EC58
#define pinstCLoadskinWnd_x                                        0xDA8F64
#define pinstCLootFiltersCopyWnd_x                                 0xC76D20
#define pinstCLootFiltersWnd_x                                     0xDA8F10
#define pinstCLootSettingsWnd_x                                    0xDA8F18
#define pinstCLootWnd_x                                            0xDA8F14
#define pinstCMailAddressBookWnd_x                                 0xDA8CA8
#define pinstCMailCompositionWnd_x                                 0xDA8C7C
#define pinstCMailIgnoreListWnd_x                                  0xDA8CAC
#define pinstCMailWnd_x                                            0xDA8C54
#define pinstCManageLootWnd_x                                      0xDAA2E8
#define pinstCMapToolbarWnd_x                                      0xDA9004
#define pinstCMapViewWnd_x                                         0xDA8FD4
#define pinstCMarketplaceWnd_x                                     0xDA8FDC
#define pinstCMerchantWnd_x                                        0xDA8F3C
#define pinstCMIZoneSelectWnd_x                                    0x101F490
#define pinstCMusicPlayerWnd_x                                     0xDA8C4C
#define pinstCNameChangeMercWnd_x                                  0xDA8C88
#define pinstCNameChangePetWnd_x                                   0xDA8C5C
#define pinstCNameChangeWnd_x                                      0xDA8FC0
#define pinstCNoteWnd_x                                            0xDA8F78
#define pinstCObjectPreviewWnd_x                                   0xDA949C
#define pinstCOptionsWnd_x                                         0xDA906C
#define pinstCPetInfoWnd_x                                         0xDA8C70
#define pinstCPetitionQWnd_x                                       0xDA8CB0
//#define pinstCPlayerCustomizationWnd_x                             0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDA8F00
#define pinstCPlayerWnd_x                                          0xDA8F68
#define pinstCPopupWndManager_x                                    0x101FD20
#define pinstCProgressionSelectionWnd_x                            0x101FDD0
#define pinstCPurchaseGroupWnd_x                                   0xDA8C58
#define pinstCPurchaseWnd_x                                        0xDA94C8
#define pinstCPvPLeaderboardWnd_x                                  0x101FE80
#define pinstCPvPStatsWnd_x                                        0x101FF30
#define pinstCQuantityWnd_x                                        0xDA8CB8
#define pinstCRaceChangeWnd_x                                      0xDA8FE8
#define pinstCRaidOptionsWnd_x                                     0xDA8FD0
#define pinstCRaidWnd_x                                            0xDA8CBC
#define pinstCRealEstateItemsWnd_x                                 0xDA8F9C
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDA8FCC
#define pinstCRealEstateManageWnd_x                                0xDA8F34
#define pinstCRealEstateNeighborhoodWnd_x                          0xDA8F50
#define pinstCRealEstatePlotSearchWnd_x                            0xDA8F74
#define pinstCRealEstatePurchaseWnd_x                              0xDA8F84
#define pinstCRespawnWnd_x                                         0xDA8FC4
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDA8FA0
#define pinstCSendMoneyWnd_x                                       0xDA94BC
#define pinstCServerListWnd_x                                      0xDA8F94
#define pinstCSkillsSelectWnd_x                                    0xDA8F20
#define pinstCSkillsWnd_x                                          0xDA8F0C
#define pinstCSocialEditWnd_x                                      0xDA8CC0
#define pinstCSocialWnd_x                                          0xDA8CC8
#define pinstCSpellBookWnd_x                                       0xDA8F98
#define pinstCStoryWnd_x                                           0xDA8EE4
#define pinstCTargetOfTargetWnd_x                                  0x1021D60
#define pinstCTargetWnd_x                                          0xDA8C6C
#define pinstCTaskOverlayWnd_x                                     0xDA8F60
#define pinstCTaskSelectWnd_x                                      0x1021EB8
#define pinstCTaskSomething_x                                      0xC77520
#define pinstCTaskTemplateSelectWnd_x                              0x1021F68
#define pinstCTaskWnd_x                                            0x1022018
#define pinstCTextEntryWnd_x                                       0xDA8EF4
#define pinstCTextOverlay_x                                        0xC65FF8
#define pinstCTimeLeftWnd_x                                        0xDA8C74
#define pinstCTipWndCONTEXT_x                                      0x102221C
#define pinstCTipWndOFDAY_x                                        0x1022218
#define pinstCTitleWnd_x                                           0x10222C8
#define pinstCTrackingWnd_x                                        0xDA8C68
#define pinstCTradeskillWnd_x                                      0x1022430
#define pinstCTradeWnd_x                                           0xDA8F80
#define pinstCTrainWnd_x                                           0xDA8CB4
#define pinstCTributeBenefitWnd_x                                  0x1022630
#define pinstCTributeMasterWnd_x                                   0x10226E0
#define pinstCTributeTrophyWnd_x                                   0x1022790
#define pinstCVideoModesWnd_x                                      0xDA8C84
#define pinstCVoiceMacroWnd_x                                      0xF0C848
#define pinstCVoteResultsWnd_x                                     0xDA94D0
#define pinstCVoteWnd_x                                            0xDA9498
#define pinstCWebManager_x                                         0xF0C9AC
#define pinstCZoneGuideWnd_x                                       0xDA8F28
#define pinstCZonePathWnd_x                                        0xDA8F38

#define pinstEQSuiteTextureLoader_x                                0xC50C48
#define pinstItemIconCache_x                                       0x101B5E8
#define pinstLootFiltersManager_x                                  0xC76DD0
#define pinstRewardSelectionWnd_x                                  0x1020678

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC01C2C
#define __CastRay_x                                                0x58E730
#define __CastRay2_x                                               0x58E780
#define __ConvertItemTags_x                                        0x5A94A0
#define __CrashHandler_x                                           0x83DC80
#define __EQGetTime_x                                              0x8DA4C0
#define __ExecuteCmd_x                                             0x5870D0
#define __FixHeading_x                                             0x96B250
#define __get_bearing_x                                            0x58E270
#define __get_melee_range_x                                        0x58E970
#define __GetAnimationCache_x                                      0x6FC3A0
#define __GetGaugeValueFromEQ_x                                    0x7EF6F0
#define __GetLabelFromEQ_x                                         0x7F0E60
#define __GetXTargetType_x                                         0x96CD80
#define __HeadingDiff_x                                            0x96B2C0
#define __HelpPath_x                                               0xF09CFC
#define __LoadFrontEnd_x                                           0x694670
#define __NewUIINI_x                                               0x7EF3C0
#define __pCrashHandler_x                                          0x103FAF8
#define __ProcessGameEvents_x                                      0x5EBBB0
#define __ProcessMouseEvent_x                                      0x5EB370
#define __SaveColors_x                                             0x538080
#define __STMLToText_x                                             0x90E360
#define __ToggleKeyRingItem_x                                      0x4FB580
#define CrashDetected_x                                            0x696160
#define DrawNetStatus_x                                            0x617680
#define Expansion_HoT_x                                            0xE6BC74
#define Teleport_Table_Size_x                                      0xE5AEF0
#define Teleport_Table_x                                           0xE5B348
#define Util__FastTime_x                                           0x8DA080
#define wwsCrashReportCheckForUploader_x                           0x83E940
#define wwsCrashReportPlatformLaunchUploader_x                     0x841000
#define __HandleMouseWheel_x                                       0x6988C0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48AA90
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x493880
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x493660

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x53FAC0
#define AltAdvManager__IsAbilityReady_x                            0x53EB40
#define AltAdvManager__GetAAById_x                                 0x53ED40
#define AltAdvManager__CanTrainAbility_x                           0x53EDB0
#define AltAdvManager__CanSeeAbility_x                             0x53EFE0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C6670
#define CharacterZoneClient__HasSkill_x                            0x4D1210
#define CharacterZoneClient__MakeMeVisible_x                       0x4D2930
#define CharacterZoneClient__IsStackBlocked_x                      0x4BA860
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B6ED0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D5070
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D5150
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D5230
#define CharacterZoneClient__FindAffectSlot_x                      0x4BF490
#define CharacterZoneClient__BardCastBard_x                        0x4C2110
#define CharacterZoneClient__GetMaxEffects_x                       0x4B6FA0
#define CharacterZoneClient__GetEffect_x                           0x4B6E10
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C04A0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C0570
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C05C0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C0710
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C08E0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6BE9D0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6CC270

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5F9F40
#define CButtonWnd__CButtonWnd_x                                   0x90A7C0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6EADD0
#define CChatManager__InitContextMenu_x                            0x6E4EE0
#define CChatManager__FreeChatWindow_x                             0x6E9CF0
#define CChatManager__GetLockedActiveChatWindow_x                  0x6EE680
#define CChatManager__SetLockedActiveChatWindow_x                  0x6EAB70

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x91EFD0
#define CContextMenu__dCContextMenu_x                              0x91F200
#define CContextMenu__AddMenuItem_x                                0x91F210
#define CContextMenu__RemoveMenuItem_x                             0x91F520
#define CContextMenu__RemoveAllMenuItems_x                         0x91F540
#define CContextMenu__CheckMenuItem_x                              0x91F5C0
#define CContextMenu__SetMenuItem_x                                0x91F440

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x91FB60
#define CContextMenuManager__RemoveMenu_x                          0x91FBD0
#define CContextMenuManager__PopupMenu_x                           0x91FC90
#define CContextMenuManager__Flush_x                               0x91FB00
#define CContextMenuManager__GetMenu_x                             0x495A00

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8BC330
#define CChatService__GetFriendName_x                              0x8BC340

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6EB340
#define CChatWindow__Clear_x                                       0x6EC3A0
#define CChatWindow__WndNotification_x                             0x6EC910

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x91C460
#define CComboWnd__Draw_x                                          0x91B950
#define CComboWnd__GetCurChoice_x                                  0x91C2A0
#define CComboWnd__GetListRect_x                                   0x91BE00
#define CComboWnd__GetTextRect_x                                   0x91C4D0
#define CComboWnd__InsertChoice_x                                  0x91BF90
#define CComboWnd__SetColors_x                                     0x91BF60
#define CComboWnd__SetChoice_x                                     0x91C270
#define CComboWnd__GetItemCount_x                                  0x91C2B0
#define CComboWnd__GetCurChoiceText_x                              0x91C2F0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6F4590
#define CContainerWnd__vftable_x                                   0xAC8B28
#define CContainerWnd__SetContainer_x                              0x6F5B00

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x537E40
#define CDisplay__GetClickedActor_x                                0x52AE90
#define CDisplay__GetUserDefinedColor_x                            0x523570
#define CDisplay__GetWorldFilePath_x                               0x52C8E0
#define CDisplay__is3dON_x                                         0x527B60
#define CDisplay__ReloadUI_x                                       0x532000
#define CDisplay__WriteTextHD2_x                                   0x527940
#define CDisplay__TrueDistance_x                                   0x52E540
#define CDisplay__SetViewActor_x                                   0x52A7E0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x93EA50

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x9236D0
#define CEditWnd__GetCharIndexPt_x                                 0x9245C0
#define CEditWnd__GetDisplayString_x                               0x924460
#define CEditWnd__GetHorzOffset_x                                  0x922D00
#define CEditWnd__GetLineForPrintableChar_x                        0x9256D0
#define CEditWnd__GetSelStartPt_x                                  0x924870
#define CEditWnd__GetSTMLSafeText_x                                0x924280
#define CEditWnd__PointFromPrintableChar_x                         0x925310
#define CEditWnd__SelectableCharFromPoint_x                        0x925480
#define CEditWnd__SetEditable_x                                    0x924930

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5DA6A0
#define CEverQuest__ClickedPlayer_x                                0x5CC980
#define CEverQuest__CreateTargetIndicator_x                        0x5E8E90
#define CEverQuest__DeleteTargetIndicator_x                        0x5E8F20
#define CEverQuest__DoTellWindow_x                                 0x4E14B0
#define CEverQuest__OutputTextToLog_x                              0x4E16E0
#define CEverQuest__DropHeldItemOnGround_x                         0x5C2240
#define CEverQuest__dsp_chat_x                                     0x4E1A70
#define CEverQuest__trimName_x                                     0x5E5450
#define CEverQuest__Emote_x                                        0x5DAEB0
#define CEverQuest__EnterZone_x                                    0x5D5020
#define CEverQuest__GetBodyTypeDesc_x                              0x5DECF0
#define CEverQuest__GetClassDesc_x                                 0x5DF330
#define CEverQuest__GetClassThreeLetterCode_x                      0x5DF930
#define CEverQuest__GetDeityDesc_x                                 0x5E77E0
#define CEverQuest__GetLangDesc_x                                  0x5DFAF0
#define CEverQuest__GetRaceDesc_x                                  0x5DF310
#define CEverQuest__InterpretCmd_x                                 0x5E7DB0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5C6430
#define CEverQuest__LMouseUp_x                                     0x5C47B0
#define CEverQuest__RightClickedOnPlayer_x                         0x5C6D10
#define CEverQuest__RMouseUp_x                                     0x5C5740
#define CEverQuest__SetGameState_x                                 0x5C1FD0
#define CEverQuest__UPCNotificationFlush_x                         0x5E5350
#define CEverQuest__IssuePetCommand_x                              0x5E0EF0
#define CEverQuest__ReportSuccessfulHit_x                          0x5DBB50

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x706590
#define CGaugeWnd__CalcLinesFillRect_x                             0x7065F0
#define CGaugeWnd__Draw_x                                          0x705C90

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ABF10
#define CGuild__GetGuildName_x                                     0x4AAF50
#define CGuild__GetGuildIndex_x                                    0x4AB2E0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x721960

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x72E850
#define CInvSlotMgr__MoveItem_x                                    0x72D570
#define CInvSlotMgr__SelectSlot_x                                  0x72E920

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x72BE20
#define CInvSlot__SliderComplete_x                                 0x729C40
#define CInvSlot__GetItemBase_x                                    0x7295C0
#define CInvSlot__UpdateItem_x                                     0x729730

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x730270
#define CInvSlotWnd__CInvSlotWnd_x                                 0x72F540
#define CInvSlotWnd__HandleLButtonUp_x                             0x72FDF0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7EB8E0
#define CItemDisplayWnd__UpdateStrings_x                           0x73DFF0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x738040
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x738510
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x73E580
#define CItemDisplayWnd__AboutToShow_x                             0x73DC40
#define CItemDisplayWnd__WndNotification_x                         0x73F8A0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8230B0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x7438F0

// CLabel 
#define CLabel__Draw_x                                             0x749340

// CListWnd
#define CListWnd__CListWnd_x                                       0x8F4A90
#define CListWnd__dCListWnd_x                                      0x8F4DB0
#define CListWnd__AddColumn_x                                      0x8F9100
#define CListWnd__AddColumn1_x                                     0x8F9150
#define CListWnd__AddLine_x                                        0x8F94E0
#define CListWnd__AddString_x                                      0x8F92E0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8F8EC0
#define CListWnd__CalculateVSBRange_x                              0x8F8C90
#define CListWnd__ClearSel_x                                       0x8F9CC0
#define CListWnd__ClearAllSel_x                                    0x8F9D20
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8FA730
#define CListWnd__Compare_x                                        0x8F85D0
#define CListWnd__Draw_x                                           0x8F4EB0
#define CListWnd__DrawColumnSeparators_x                           0x8F76A0
#define CListWnd__DrawHeader_x                                     0x8F7B10
#define CListWnd__DrawItem_x                                       0x8F7F10
#define CListWnd__DrawLine_x                                       0x8F7810
#define CListWnd__DrawSeparator_x                                  0x8F7740
#define CListWnd__EnableLine_x                                     0x8F6F70
#define CListWnd__EnsureVisible_x                                  0x8FA650
#define CListWnd__ExtendSel_x                                      0x8F9BF0
#define CListWnd__GetColumnMinWidth_x                              0x8F6AB0
#define CListWnd__GetColumnWidth_x                                 0x8F6A20
#define CListWnd__GetCurSel_x                                      0x8F63B0
#define CListWnd__GetItemAtPoint_x                                 0x8F71F0
#define CListWnd__GetItemAtPoint1_x                                0x8F7260
#define CListWnd__GetItemData_x                                    0x8F6430
#define CListWnd__GetItemHeight_x                                  0x8F67F0
#define CListWnd__GetItemIcon_x                                    0x8F65C0
#define CListWnd__GetItemRect_x                                    0x8F7060
#define CListWnd__GetItemText_x                                    0x8F6470
#define CListWnd__GetSelList_x                                     0x8F9D70
#define CListWnd__GetSeparatorRect_x                               0x8F74A0
#define CListWnd__InsertLine_x                                     0x8F98D0
#define CListWnd__RemoveLine_x                                     0x8F9A20
#define CListWnd__SetColors_x                                      0x8F8C60
#define CListWnd__SetColumnJustification_x                         0x8F8990
#define CListWnd__SetColumnWidth_x                                 0x8F88B0
#define CListWnd__SetCurSel_x                                      0x8F9B30
#define CListWnd__SetItemColor_x                                   0x8FA300
#define CListWnd__SetItemData_x                                    0x8FA2C0
#define CListWnd__SetItemText_x                                    0x8F9EF0
#define CListWnd__ShiftColumnSeparator_x                           0x8F8A50
#define CListWnd__Sort_x                                           0x8F8750
#define CListWnd__ToggleSel_x                                      0x8F9B60

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x75E930

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x781990
#define CMerchantWnd__RequestBuyItem_x                             0x782270
#define CMerchantWnd__RequestSellItem_x                            0x7827A0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7855D0
//did this get another arg?
#define CMerchantWnd__SelectBuySellSlot_x                          0x781FF0
#define CMerchantWnd__ActualSelect_x                               0x78B130

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x88A340
#define CPacketScrambler__hton_x                                   0x88A330

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x913980
#define CSidlManager__FindScreenPieceTemplate_x                    0x913D90
#define CSidlManager__FindScreenPieceTemplate1_x                   0x913B80
#define CSidlManager__CreateLabel_x                                0x7E2DA0
#define CSidlManager__CreateXWndFromTemplate_x                     0x916E60
#define CSidlManager__CreateXWndFromTemplate1_x                    0x917040

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9104E0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9103D0
#define CSidlScreenWnd__ConvertToRes_x                             0x935250
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x90FE60
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x90FB50
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x90FC20
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x90FCF0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x910980
#define CSidlScreenWnd__EnableIniStorage_x                         0x910E50
#define CSidlScreenWnd__GetSidlPiece_x                             0x910B70
#define CSidlScreenWnd__Init1_x                                    0x90F740
#define CSidlScreenWnd__LoadIniInfo_x                              0x910EA0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9119F0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x90EB40
#define CSidlScreenWnd__StoreIniInfo_x                             0x911570
#define CSidlScreenWnd__StoreIniVis_x                              0x9118D0
#define CSidlScreenWnd__WndNotification_x                          0x910890
#define CSidlScreenWnd__GetChildItem_x                             0x910DD0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x900630
#define CSidlScreenWnd__m_layoutCopy_x                             0x1699630

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x65DC60
#define CSkillMgr__GetSkillCap_x                                   0x65DE40
#define CSkillMgr__GetNameToken_x                                  0x65D3F0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x920950
#define CSliderWnd__SetValue_x                                     0x9207C0
#define CSliderWnd__SetNumTicks_x                                  0x920820

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7E8B20

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x927570
#define CStmlWnd__CalculateHSBRange_x                              0x928600
#define CStmlWnd__CalculateVSBRange_x                              0x928570
#define CStmlWnd__CanBreakAtCharacter_x                            0x92C940
#define CStmlWnd__FastForwardToEndOfTag_x                          0x92D530
#define CStmlWnd__ForceParseNow_x                                  0x927B10
#define CStmlWnd__GetNextTagPiece_x                                0x92C8A0
#define CStmlWnd__GetSTMLText_x                                    0x4EF890
#define CStmlWnd__GetVisibleText_x                                 0x927B30
#define CStmlWnd__InitializeWindowVariables_x                      0x92D380
#define CStmlWnd__MakeStmlColorTag_x                               0x926D00
#define CStmlWnd__MakeWndNotificationTag_x                         0x926D70
#define CStmlWnd__SetSTMLText_x                                    0x925DD0
#define CStmlWnd__StripFirstSTMLLines_x                            0x92E690
#define CStmlWnd__UpdateHistoryString_x                            0x92D740

// CTabWnd 
#define CTabWnd__Draw_x                                            0x931D60
#define CTabWnd__DrawCurrentPage_x                                 0x932380
#define CTabWnd__DrawTab_x                                         0x932150
#define CTabWnd__GetCurrentPage_x                                  0x9315C0
#define CTabWnd__GetPageInnerRect_x                                0x931800
#define CTabWnd__GetTabInnerRect_x                                 0x931740
#define CTabWnd__GetTabRect_x                                      0x9315F0
#define CTabWnd__InsertPage_x                                      0x9319F0
#define CTabWnd__SetPage_x                                         0x931880
#define CTabWnd__SetPageRect_x                                     0x931CA0
#define CTabWnd__UpdatePage_x                                      0x932010
#define CTabWnd__GetPageFromTabIndex_x                             0x932090
#define CTabWnd__GetCurrentTabIndex_x                              0x9315B0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x743D50
#define CPageWnd__SetTabText_x                                     0x93EE60

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A5A70

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8FD450
#define CTextureFont__GetTextExtent_x                              0x8FD610

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x691400
#define CHtmlComponentWnd__ValidateUri_x                           0x723350
#define CHtmlWnd__SetClientCallbacks_x                             0x5FF280
#define CHtmlWnd__AddObserver_x                                    0x5FF2A0
#define CHtmlWnd__RemoveObserver_x                                 0x5FF300
#define Window__getProgress_x                                      0x83B8F0
#define Window__getStatus_x                                        0x83B910
#define Window__getURI_x                                           0x83B920

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x93B3E0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8EA480

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4AD170
#define CXStr__CXStr1_x                                            0x9AD160
#define CXStr__CXStr3_x                                            0x8D65F0
#define CXStr__dCXStr_x                                            0x4721D0
#define CXStr__operator_equal_x                                    0x8D6820
#define CXStr__operator_equal1_x                                   0x8D6860
#define CXStr__operator_plus_equal1_x                              0x8D72F0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x91EBF0
#define CXWnd__BringToTop_x                                        0x903E30
#define CXWnd__Center_x                                            0x9039B0
#define CXWnd__ClrFocus_x                                          0x9037E0
#define CXWnd__Destroy_x                                           0x903890
#define CXWnd__DoAllDrawing_x                                      0x8FFDC0
#define CXWnd__DrawChildren_x                                      0x8FFD90
#define CXWnd__DrawColoredRect_x                                   0x900220
#define CXWnd__DrawTooltip_x                                       0x8FE8C0
#define CXWnd__DrawTooltipAtPoint_x                                0x8FE980
#define CXWnd__GetBorderFrame_x                                    0x900080
#define CXWnd__GetChildWndAt_x                                     0x903ED0
#define CXWnd__GetClientClipRect_x                                 0x9020A0
#define CXWnd__GetScreenClipRect_x                                 0x902170
#define CXWnd__GetScreenRect_x                                     0x902340
#define CXWnd__GetTooltipRect_x                                    0x900270
#define CXWnd__GetWindowTextA_x                                    0x497090
#define CXWnd__IsActive_x                                          0x906D70
#define CXWnd__IsDescendantOf_x                                    0x902D60
#define CXWnd__IsReallyVisible_x                                   0x902D90
#define CXWnd__IsType_x                                            0x904540
#define CXWnd__Move_x                                              0x902E00
#define CXWnd__Move1_x                                             0x902EC0
#define CXWnd__ProcessTransition_x                                 0x903960
#define CXWnd__Refade_x                                            0x903190
#define CXWnd__Resize_x                                            0x903430
#define CXWnd__Right_x                                             0x903BF0
#define CXWnd__SetFocus_x                                          0x9037A0
#define CXWnd__SetFont_x                                           0x903810
#define CXWnd__SetKeyTooltip_x                                     0x904360
#define CXWnd__SetMouseOver_x                                      0x901200
#define CXWnd__StartFade_x                                         0x902C30
#define CXWnd__GetChildItem_x                                      0x904040
#define CXWnd__SetParent_x                                         0x902AF0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x936320

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x906DB0
#define CXWndManager__DrawWindows_x                                0x906DD0
#define CXWndManager__GetKeyboardFlags_x                           0x909490
#define CXWndManager__HandleKeyboardMsg_x                          0x909090
#define CXWndManager__RemoveWnd_x                                  0x9096D0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x909C20

// CDBStr
#define CDBStr__GetString_x                                        0x522500

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B7E80
#define EQ_Character__Cur_HP_x                                     0x4CE290
#define EQ_Character__Cur_Mana_x                                   0x4D5730
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BAFF0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AED90
#define EQ_Character__GetFocusRangeModifier_x                      0x4AEEE0
#define EQ_Character__GetHPRegen_x                                 0x4DADF0
#define EQ_Character__GetEnduranceRegen_x                          0x4DB400
#define EQ_Character__GetManaRegen_x                               0x4DB840
#define EQ_Character__Max_Endurance_x                              0x624ED0
#define EQ_Character__Max_HP_x                                     0x4CE0C0
#define EQ_Character__Max_Mana_x                                   0x624CD0
#define EQ_Character__doCombatAbility_x                            0x627080
#define EQ_Character__UseSkill_x                                   0x4DD630
#define EQ_Character__GetConLevel_x                                0x61E3D0
#define EQ_Character__IsExpansionFlag_x                            0x585AA0
#define EQ_Character__TotalEffect_x                                0x4C1690
#define EQ_Character__GetPCSpellAffect_x                           0x4BBBE0
#define EQ_Character__SpellDuration_x                              0x4BB710
#define EQ_Character__FindItemByRecord_x                           0x4D38A0
#define EQ_Character__GetAdjustedSkill_x                           0x4D0FD0
#define EQ_Character__GetBaseSkill_x                               0x4D1F70
#define EQ_Character__CanUseItem_x                                 0x4D5A40

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8A95D0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x63ADE0

//PcClient
#define PcClient__PcClient_x                                       0x61BC90

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B5C50
#define CCharacterListWnd__EnterWorld_x                            0x4B5690
#define CCharacterListWnd__Quit_x                                  0x4B53A0
#define CCharacterListWnd__UpdateList_x                            0x4B5820

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x600480
#define EQ_Item__CreateItemTagString_x                             0x8846E0
#define EQ_Item__IsStackable_x                                     0x888850
#define EQ_Item__GetImageNum_x                                     0x885E90
#define EQ_Item__CreateItemClient_x                                0x5FF660
#define EQ_Item__GetItemValue_x                                    0x886F30
#define EQ_Item__ValueSellMerchant_x                               0x889EE0
#define EQ_Item__IsKeyRingItem_x                                   0x888210
#define EQ_Item__CanGoInBag_x                                      0x6005A0
#define EQ_Item__GetMaxItemCount_x                                 0x887030
#define EQ_Item__GetHeldItem_x                                     0x885D60
#define EQ_Item__GetAugmentFitBySlot_x                             0x884220

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x5407E0
#define EQ_LoadingS__Array_x                                       0xBD92B0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x625830
#define EQ_PC__GetAlternateAbilityId_x                             0x893180
#define EQ_PC__GetCombatAbility_x                                  0x8937F0
#define EQ_PC__GetCombatAbilityTimer_x                             0x893860
#define EQ_PC__GetItemRecastTimer_x                                0x627600
#define EQ_PC__HasLoreItem_x                                       0x61EB90
#define EQ_PC__AlertInventoryChanged_x                             0x61DEA0
#define EQ_PC__GetPcZoneClient_x                                   0x649610
#define EQ_PC__RemoveMyAffect_x                                    0x62A740
#define EQ_PC__GetKeyRingItems_x                                   0x894100
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x893E80
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8943F0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x58BCE0
#define EQItemList__add_object_x                                   0x5B78C0
#define EQItemList__add_item_x                                     0x58C2F0
#define EQItemList__delete_item_x                                  0x58C340
#define EQItemList__FreeItemList_x                                 0x58C240

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x51FB10

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x63C660
#define EQPlayer__dEQPlayer_x                                      0x62FD90
#define EQPlayer__DoAttack_x                                       0x644340
#define EQPlayer__EQPlayer_x                                       0x630440
#define EQPlayer__SetNameSpriteState_x                             0x6346D0
#define EQPlayer__SetNameSpriteTint_x                              0x635560
#define PlayerBase__HasProperty_j_x                                0x969630
#define EQPlayer__IsTargetable_x                                   0x969AD0
#define EQPlayer__CanSee_x                                         0x969930
#define EQPlayer__CanSee1_x                                        0x969A00
#define PlayerBase__GetVisibilityLineSegment_x                     0x9696F0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x647100
#define PlayerZoneClient__GetLevel_x                               0x649650
#define PlayerZoneClient__IsValidTeleport_x                        0x5B8A10
#define PlayerZoneClient__LegalPlayerRace_x                        0x539C50

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x63F480
#define EQPlayerManager__GetSpawnByName_x                          0x63F4A0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x63F530

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x603D30
#define KeypressHandler__AttachKeyToEqCommand_x                    0x603D70
#define KeypressHandler__ClearCommandStateArray_x                  0x605160
#define KeypressHandler__HandleKeyDown_x                           0x605180
#define KeypressHandler__HandleKeyUp_x                             0x605220
#define KeypressHandler__SaveKeymapping_x                          0x605600

// MapViewMap 
#define MapViewMap__Clear_x                                        0x75A7C0
#define MapViewMap__SaveEx_x                                       0x75DB60
#define MapViewMap__SetZoom_x                                      0x762230

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8A74C0

// StringTable 
#define StringTable__getString_x                                   0x8A2450

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x62A3B0
#define PcZoneClient__RemovePetEffect_x                            0x62A9E0
#define PcZoneClient__HasAlternateAbility_x                        0x624B10
#define PcZoneClient__GetCurrentMod_x                              0x4E05A0
#define PcZoneClient__GetModCap_x                                  0x4E04A0
#define PcZoneClient__CanEquipItem_x                               0x6251C0
#define PcZoneClient__GetItemByID_x                                0x627A80
#define PcZoneClient__GetItemByItemClass_x                         0x627B10
#define PcZoneClient__RemoveBuffEffect_x                           0x62AA00

//Doors
#define EQSwitch__UseSwitch_x                                      0x5BD6C0

//IconCache
#define IconCache__GetIcon_x                                       0x6FBC30

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6F3730
#define CContainerMgr__CloseContainer_x                            0x6F3A00
#define CContainerMgr__OpenExperimentContainer_x                   0x6F4480

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7B5730

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5F8720

//CLootWnd
#define CLootWnd__LootAll_x                                        0x750CB0
#define CLootWnd__RequestLootSlot_x                                0x750070

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x558B80
#define EQ_Spell__SpellAffects_x                                   0x558FF0
#define EQ_Spell__SpellAffectBase_x                                0x558DB0
#define EQ_Spell__IsStackable_x                                    0x4C5F50
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C5D70
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B32B0
#define EQ_Spell__IsSPAStacking_x                                  0x559D90
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x559340
#define EQ_Spell__IsNoRemove_x                                     0x4C5F30
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x559DA0
#define __IsResEffectSpell_x                                       0x4C51F0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4A9BD0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8B1820

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7FAC10
#define CTargetWnd__WndNotification_x                              0x7FA4A0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7FA770
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x7F95F0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7FF300

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5540E0
#define EqSoundManager__PlayScriptMp3_x                            0x554240
#define EqSoundManager__SoundAssistPlay_x                          0x661760
#define EqSoundManager__WaveInstancePlay_x                         0x660CB0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x511480

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x922330

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x548370
#define CAltAbilityData__GetMercMaxRank_x                          0x548310
#define CAltAbilityData__GetMaxRank_x                              0x53D9F0

//CTargetRing
#define CTargetRing__Cast_x                                        0x5F6820

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C5D50
#define CharacterBase__CreateItemGlobalIndex_x                     0x4F7970
#define CharacterBase__CreateItemIndex_x                           0x5FE890
#define CharacterBase__GetItemPossession_x                         0x4B3160
#define CharacterBase__GetItemByGlobalIndex_x                      0x8B9D60
#define CharacterBase__GetEffectId_x                               0x4C5D00

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6DB990
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6DC1B0

//messages
#define msg_spell_worn_off_x                                       0x57E390
#define msg_new_text_x                                             0x573590
#define __msgTokenTextParam_x                                      0x5809E0
#define msgTokenText_x                                             0x580C30

//SpellManager
#define SpellManager__vftable_x                                    0xAA3818
#define SpellManager__SpellManager_x                               0x664A90
#define Spellmanager__LoadTextSpells_x                             0x6652F0
#define SpellManager__GetSpellByGroupAndRank_x                     0x664C60

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x96D670

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4F8060
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x584140
#define ItemGlobalIndex__IsEquippedLocation_x                      0x6174E0
#define ItemGlobalIndex__IsValidIndex_x                            0x4F80C0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8B2160
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8B23E0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x749680

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6F7E90
#define CCursorAttachment__Deactivate_x                            0x6F8E60

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x934370
#define CEQSuiteTextureLoader__GetTexture_x                        0x934030

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4F5010

//IString
#define IString__Append_x                                          0x4E98E0

//Camera
#define CDisplay__cameraType_x                                     0xDA8CDC
#define EverQuest__Cameras_x                                       0xE6BFAC

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x4FD7F0
#define LootFiltersManager__GetItemFilterData_x                    0x4FD0F0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x4FD120
#define LootFiltersManager__SetItemLootFilter_x                    0x4FD340

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7A3740

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x973400
#define CResolutionHandler__GetWindowedStyle_x                     0x65C6F0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6F04F0

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
#ifdef EMU
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\xFD\xFF\xFF\x8B\xCE\x5E\xE9\x00\x00\xFF\xFF\xC7\x01";
static char lpMask[] = "xxxx?xxxxxxx??xxxx";
#else
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
#endif
