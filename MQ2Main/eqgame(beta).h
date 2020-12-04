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
#define __ExpectedVersionDate                                     "Nov 26 2020"
#define __ExpectedVersionTime                                     "04:20:25"
#define __ActualVersionDate_x                                      0xAF7560
#define __ActualVersionTime_x                                      0xAF7554
#define __ActualVersionBuild_x                                     0xAE556C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x6457A0
#define __MemChecker1_x                                            0x8F8D40
#define __MemChecker2_x                                            0x6B5AA0
#define __MemChecker3_x                                            0x6B59F0
#define __MemChecker4_x                                            0x84F230
#define __EncryptPad0_x                                            0xC2D9C8
#define __EncryptPad1_x                                            0xC8B210
#define __EncryptPad2_x                                            0xC3DD90
#define __EncryptPad3_x                                            0xC3D990
#define __EncryptPad4_x                                            0xC7B7A0
#define __EncryptPad5_x                                            0xF4E0F0
#define __AC1_x                                                    0x80D916
#define __AC2_x                                                    0x5FEDFF
#define __AC3_x                                                    0x606450
#define __AC4_x                                                    0x60A400
#define __AC5_x                                                    0x6106FF
#define __AC6_x                                                    0x614BB6
#define __AC7_x                                                    0x5FE870
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1932E0

// Direct Input
#define DI8__Main_x                                                0xF4E118
#define DI8__Keyboard_x                                            0xF4E11C
#define DI8__Mouse_x                                               0xF4E0FC
#define DI8__Mouse_Copy_x                                          0xEA69E4
#define DI8__Mouse_Check_x                                         0xF4BC44
#define __AutoSkillArray_x                                         0xEA7900
#define __Attack_x                                                 0xF4572F
#define __Autofire_x                                               0xF45730
#define __BindList_x                                               0xC1C400
#define g_eqCommandStates_x                                        0xC1D180
#define __Clicks_x                                                 0xEA6A9C
#define __CommandList_x                                            0xC1DD40
#define __CurrentMapLabel_x                                        0xF5E14C
#define __CurrentSocial_x                                          0xC057D4
#define __DoAbilityList_x                                          0xEDD250
#define __do_loot_x                                                0x5CA8D0
#define __DrawHandler_x                                            0x15DD140
#define __GroupCount_x                                             0xE9F502
#define __Guilds_x                                                 0xEA5920
#define __gWorld_x                                                 0xE9FC98
#define __HWnd_x                                                   0xF4E100
#define __heqmain_x                                                0xF4E0D8
#define __InChatMode_x                                             0xEA69CC
#define __LastTell_x                                               0xEA894C
#define __LMouseHeldTime_x                                         0xEA6B08
#define __Mouse_x                                                  0xF4E104
#define __MouseLook_x                                              0xEA6A62
#define __MouseEventTime_x                                         0xF46214
#define __gpbCommandEvent_x                                        0xE9F758
#define __NetStatusToggle_x                                        0xEA6A65
#define __PCNames_x                                                0xEA7EFC
#define __RangeAttackReady_x                                       0xEA7BE4
#define __RMouseHeldTime_x                                         0xEA6B04
#define __RunWalkState_x                                           0xEA69D0
#define __ScreenMode_x                                             0xDED4B0
#define __ScreenX_x                                                0xEA6984
#define __ScreenY_x                                                0xEA6980
#define __ScreenXMax_x                                             0xEA6988
#define __ScreenYMax_x                                             0xEA698C
#define __ServerHost_x                                             0xE9F92B
#define __ServerName_x                                             0xEDD210
#define __ShiftKeyDown_x                                           0xEA7060
#define __ShowNames_x                                              0xEA7DA0
#define EverQuestInfo__bSocialChanged_x                            0xEDD298
#define __Socials_x                                                0xEDD310
#define __SubscriptionType_x                                       0xFA2410
#define __TargetAggroHolder_x                                      0xF60B00
#define __ZoneType_x                                               0xEA6E60
#define __GroupAggro_x                                             0xF60B40
#define __LoginName_x                                              0xF4B8D4
#define __Inviter_x                                                0xF456AC
#define __AttackOnAssist_x                                         0xEA7D5C
#define __UseTellWindows_x                                         0xEA8094
#define __gfMaxZoomCameraDistance_x                                0xAEF168
#define __gfMaxCameraDistance_x                                    0xB17E08
#define __pulAutoRun_x                                             0xEA6A80
#define __pulForward_x                                             0xEA80CC
#define __pulBackward_x                                            0xEA80D0
#define __pulTurnRight_x                                           0xEA80D4
#define __pulTurnLeft_x                                            0xEA80D8
#define __pulStrafeLeft_x                                          0xEA80DC
#define __pulStrafeRight_x                                         0xEA80E0

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEA1CB8
#define instEQZoneInfo_x                                           0xEA6C58
#define pinstActiveBanker_x                                        0xE9FC44
#define pinstActiveCorpse_x                                        0xE9FC3C
#define pinstActiveGMaster_x                                       0xE9FC40
#define pinstActiveMerchant_x                                      0xE9FA34
#define pinstAltAdvManager_x                                       0xDEDEF0
#define pinstBandageTarget_x                                       0xE9FC54
#define pinstCamActor_x                                            0xDED4A4
#define pinstCDBStr_x                                              0xDECC0C
#define pinstCDisplay_x                                            0xE9FCA4
#define pinstCEverQuest_x                                          0xF4B19C
#define pinstEverQuestInfo_x                                       0xEA6978
#define pinstCharData_x                                            0xE9F744
#define pinstCharSpawn_x                                           0xE9FC8C
#define pinstControlledMissile_x                                   0xE9FCA0
#define pinstControlledPlayer_x                                    0xE9FC8C
#define pinstCResolutionHandler_x                                  0x15DD370
#define pinstCSidlManager_x                                        0x15DC308
#define pinstCXWndManager_x                                        0x15DC304
#define instDynamicZone_x                                          0xEA57F8
#define pinstDZMember_x                                            0xEA5908
#define pinstDZTimerInfo_x                                         0xEA590C
#define pinstEqLogin_x                                             0xF4B220
#define instEQMisc_x                                               0xDECB50
#define pinstEQSoundManager_x                                      0xDEEEC0
#define pinstEQSpellStrings_x                                      0xCAF448
#define instExpeditionLeader_x                                     0xEA5842
#define instExpeditionName_x                                       0xEA5882
#define pinstGroup_x                                               0xE9F4FE
#define pinstImeManager_x                                          0x15DC300
#define pinstLocalPlayer_x                                         0xE9F824
#define pinstMercenaryData_x                                       0xF47D08
#define pinstMercenaryStats_x                                      0xF60BCC
#define pinstModelPlayer_x                                         0xE9FC4C
#define pinstPCData_x                                              0xE9F744
#define pinstSkillMgr_x                                            0xF49E68
#define pinstSpawnManager_x                                        0xF48910
#define pinstSpellManager_x                                        0xF4A0A8
#define pinstSpellSets_x                                           0xF3E358
#define pinstStringTable_x                                         0xE9F74C
#define pinstSwitchManager_x                                       0xE9F258
#define pinstTarget_x                                              0xE9FC88
#define pinstTargetObject_x                                        0xE9FC94
#define pinstTargetSwitch_x                                        0xE9FCAC
#define pinstTaskMember_x                                          0xDEC9E0
#define pinstTrackTarget_x                                         0xE9FC90
#define pinstTradeTarget_x                                         0xE9FC48
#define instTributeActive_x                                        0xDECB71
#define pinstViewActor_x                                           0xDED4A0
#define pinstWorldData_x                                           0xE9F3A8
#define pinstZoneAddr_x                                            0xEA6EF8
#define pinstPlayerPath_x                                          0xF489A8
#define pinstTargetIndicator_x                                     0xF4A310
#define EQObject_Top_x                                             0xE9F820
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDECF44
#define pinstCAchievementsWnd_x                                    0xDED45C
#define pinstCActionsWnd_x                                         0xDECF80
#define pinstCAdvancedDisplayOptionsWindow_x                       0xDED51C
#define pinstCAdvancedLootWnd_x                                    0xDED4CC
#define pinstCAdventureLeaderboardWnd_x                            0xF57920
#define pinstCAdventureRequestWnd_x                                0xF579D0
#define pinstCAdventureStatsWnd_x                                  0xF57A80
#define pinstCAggroMeterWnd_x                                      0xDED500
#define pinstCAlarmWnd_x                                           0xDED488
#define pinstCAlertHistoryWnd_x                                    0xDECEF4
#define pinstCAlertStackWnd_x                                      0xDED4E8
#define pinstCAlertWnd_x                                           0xDED4FC
#define pinstCAltStorageWnd_x                                      0xF57DE0
#define pinstCAudioTriggersWindow_x                                0xCA1778
#define pinstCAuraWnd_x                                            0xDED4D0
#define pinstCAvaZoneWnd_x                                         0xDECEF8
#define pinstCBandolierWnd_x                                       0xDED514
#define pinstCBankWnd_x                                            0xDECCB8
#define pinstCBarterMerchantWnd_x                                  0xF59020
#define pinstCBarterSearchWnd_x                                    0xF590D0
#define pinstCBarterWnd_x                                          0xF59180
#define pinstCBazaarConfirmationWnd_x                              0xDED498
#define pinstCBazaarSearchWnd_x                                    0xDECF48
#define pinstCBazaarWnd_x                                          0xDED464
#define pinstCBlockedBuffWnd_x                                     0xDED4DC
#define pinstCBlockedPetBuffWnd_x                                  0xDED504
#define pinstCBodyTintWnd_x                                        0xDED40C
#define pinstCBookWnd_x                                            0xDECCAC
#define pinstCBreathWnd_x                                          0xDECF58
#define pinstCBuffWindowNORMAL_x                                   0xDED4C4
#define pinstCBuffWindowSHORT_x                                    0xDED4C8
#define pinstCBugReportWnd_x                                       0xDECCB4
#define pinstCButtonWnd_x                                          0x15DC570
#define pinstCCastingWnd_x                                         0xDED540
#define pinstCCastSpellWnd_x                                       0xDECF54
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDED418
#define pinstCChatWindowManager_x                                  0xF59C40
#define pinstCClaimWnd_x                                           0xF59D98
#define pinstCColorPickerWnd_x                                     0xDECF0C
#define pinstCCombatAbilityWnd_x                                   0xDED478
#define pinstCCombatSkillsSelectWnd_x                              0xDED42C
#define pinstCCompassWnd_x                                         0xDECF84
#define pinstCConfirmationDialog_x                                 0xF5EC98
#define pinstCContainerMgr_x                                       0xDED408
#define pinstCContextMenuManager_x                                 0x15DC2C0
#define pinstCCursorAttachment_x                                   0xDED534
#define pinstCDynamicZoneWnd_x                                     0xF5A360
#define pinstCEditLabelWnd_x                                       0xDED4C0
#define pinstCEQMainWnd_x                                          0xF5A5A8
#define pinstCEventCalendarWnd_x                                   0xDECF4C
#define pinstCExtendedTargetWnd_x                                  0xDED4E0
#define pinstCPlayerCustomizationWnd_x                             0xDED430
#define pinstCFactionWnd_x                                         0xDED450
#define pinstCFellowshipWnd_x                                      0xF5A7A8
#define pinstCFileSelectionWnd_x                                   0xDECF08
#define pinstCFindItemWnd_x                                        0xDED444
#define pinstCFindLocationWnd_x                                    0xF5A900
#define pinstCFriendsWnd_x                                         0xDED440
#define pinstCGemsGameWnd_x                                        0xDED44C
#define pinstCGiveWnd_x                                            0xDED48C
#define pinstCGroupSearchFiltersWnd_x                              0xDED518
#define pinstCGroupSearchWnd_x                                     0xF5ACF8
#define pinstCGroupWnd_x                                           0xF5ADA8
#define pinstCGuildBankWnd_x                                       0xF5AE58
#define pinstCGuildCreationWnd_x                                   0xF5AF08
#define pinstCGuildMgmtWnd_x                                       0xF5AFB8
#define pinstCharacterCreation_x                                   0xDED438
#define pinstCHelpWnd_x                                            0xDED484
#define pinstCHeritageSelectionWnd_x                               0xDED43C
#define pinstCHotButtonWnd_x                                       0xF5D110
#define pinstCHotButtonWnd1_x                                      0xF5D110
#define pinstCHotButtonWnd2_x                                      0xF5D114
#define pinstCHotButtonWnd3_x                                      0xF5D118
#define pinstCHotButtonWnd4_x                                      0xF5D11C
#define pinstCIconSelectionWnd_x                                   0xDED528
#define pinstCInspectWnd_x                                         0xDED508
#define pinstCInventoryWnd_x                                       0xDED4D4
#define pinstCInvSlotMgr_x                                         0xDECF38
#define pinstCItemDisplayManager_x                                 0xF5D6A0
#define pinstCItemExpTransferWnd_x                                 0xF5D7D0
#define pinstCItemOverflowWnd_x                                    0xDECF50
#define pinstCJournalCatWnd_x                                      0xDECF24
#define pinstCJournalNPCWnd_x                                      0xDECEE4
#define pinstCJournalTextWnd_x                                     0xDECEE4
#define pinstCKeyRingWnd_x                                         0xDED53C
#define pinstCLargeDialogWnd_x                                     0xF5F918
#define pinstCLayoutCopyWnd_x                                      0xF5DB20
#define pinstCLFGuildWnd_x                                         0xF5DBD0
#define pinstCLoadskinWnd_x                                        0xDED468
#define pinstCLootFiltersCopyWnd_x                                 0xCBDEE8
#define pinstCLootFiltersWnd_x                                     0xDED4EC
#define pinstCLootSettingsWnd_x                                    0xDED510
#define pinstCLootWnd_x                                            0xDECF28
#define pinstCMailAddressBookWnd_x                                 0xDECF3C
#define pinstCMailCompositionWnd_x                                 0xDECF14
#define pinstCMailIgnoreListWnd_x                                  0xDECF40
#define pinstCMailWnd_x                                            0xDECF00
#define pinstCManageLootWnd_x                                      0xDEE3A0
#define pinstCMapToolbarWnd_x                                      0xDED490
#define pinstCMapViewWnd_x                                         0xDED458
#define pinstCMarketplaceWnd_x                                     0xDED4F0
#define pinstCMerchantWnd_x                                        0xDECF34
#define pinstCMIZoneSelectWnd_x                                    0xF5E408
#define pinstCMusicPlayerWnd_x                                     0xDECED4
#define pinstCNameChangeMercWnd_x                                  0xDED494
#define pinstCNameChangePetWnd_x                                   0xDED460
#define pinstCNameChangeWnd_x                                      0xDED4BC
#define pinstCNoteWnd_x                                            0xDED470
#define pinstCObjectPreviewWnd_x                                   0xDED50C
#define pinstCOptionsWnd_x                                         0xDED47C
#define pinstCPetInfoWnd_x                                         0xDECEFC
#define pinstCPetitionQWnd_x                                       0xDED428
#define pinstCPlayerNotesWnd_x                                     0xDED410
#define pinstCPlayerWnd_x                                          0xDECEF0
#define pinstCPopupWndManager_x                                    0xF5EC98
#define pinstCProgressionSelectionWnd_x                            0xF5ED48
#define pinstCPurchaseGroupWnd_x                                   0xDECCC8
#define pinstCPurchaseWnd_x                                        0xDED544
#define pinstCPvPLeaderboardWnd_x                                  0xF5EDF8
#define pinstCPvPStatsWnd_x                                        0xF5EEA8
#define pinstCQuantityWnd_x                                        0xDECEE0
#define pinstCRaceChangeWnd_x                                      0xDED4D8
#define pinstCRaidOptionsWnd_x                                     0xDED520
#define pinstCRaidWnd_x                                            0xDECF30
#define pinstCRealEstateItemsWnd_x                                 0xDED454
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDED000
#define pinstCRealEstateManageWnd_x                                0xDECED0
#define pinstCRealEstateNeighborhoodWnd_x                          0xDECEEC
#define pinstCRealEstatePlotSearchWnd_x                            0xDECF04
#define pinstCRealEstatePurchaseWnd_x                              0xDECF20
#define pinstCRespawnWnd_x                                         0xDED4F8
#define pinstCRewardSelectionWnd_x                                 0xF5F5F0
#define pinstCSelectorWnd_x                                        0xDED424
#define pinstCSendMoneyWnd_x                                       0xDED49C
#define pinstCServerListWnd_x                                      0xDECF2C
#define pinstCSkillsSelectWnd_x                                    0xDED420
#define pinstCSkillsWnd_x                                          0xDECFFC
#define pinstCSocialEditWnd_x                                      0xDED538
#define pinstCSocialWnd_x                                          0xDED480
#define pinstCSpellBookWnd_x                                       0xDED474
#define pinstCStoryWnd_x                                           0xDECF7C
#define pinstCTargetOfTargetWnd_x                                  0xF60C50
#define pinstCTargetWnd_x                                          0xDED4F4
#define pinstCTaskOverlayWnd_x                                     0xDECCC0
#define pinstCTaskSelectWnd_x                                      0xF60DA8
#define pinstCTaskManager_x                                        0xCBE828
#define pinstCTaskTemplateSelectWnd_x                              0xF60E58
#define pinstCTaskWnd_x                                            0xF60F08
#define pinstCTextEntryWnd_x                                       0xDECCA8
#define pinstCTimeLeftWnd_x                                        0xDED41C
#define pinstCTipWndCONTEXT_x                                      0xF6110C
#define pinstCTipWndOFDAY_x                                        0xF61108
#define pinstCTitleWnd_x                                           0xF611B8
#define pinstCTrackingWnd_x                                        0xDED4E4
#define pinstCTradeskillWnd_x                                      0xF61320
#define pinstCTradeWnd_x                                           0xDED414
#define pinstCTrainWnd_x                                           0xDECF18
#define pinstCTributeBenefitWnd_x                                  0xF61520
#define pinstCTributeMasterWnd_x                                   0xF615D0
#define pinstCTributeTrophyWnd_x                                   0xF61680
#define pinstCVideoModesWnd_x                                      0xDECCBC
#define pinstCVoiceMacroWnd_x                                      0xF4A8C8
#define pinstCVoteResultsWnd_x                                     0xDED448
#define pinstCVoteWnd_x                                            0xDED434
#define pinstCWebManager_x                                         0xF4AF44
#define pinstCZoneGuideWnd_x                                       0xDECCC4
#define pinstCZonePathWnd_x                                        0xDECEDC

#define pinstEQSuiteTextureLoader_x                                0xC8BB30
#define pinstItemIconCache_x                                       0xF5A560
#define pinstLootFiltersManager_x                                  0xCBDF98
#define pinstRewardSelectionWnd_x                                  0xF5F5F0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5C5FC0
#define __CastRay2_x                                               0x5C6010
#define __ConvertItemTags_x                                        0x5E1CE0
#define __CleanItemTags_x                                          0x47D250
#define __DoesFileExist_x                                          0x8FBDC0
#define __EQGetTime_x                                              0x8F8970
#define __ExecuteCmd_x                                             0x5BE930
#define __FixHeading_x                                             0x98DC80
#define __FlushDxKeyboard_x                                        0x6B1940
#define __GameLoop_x                                               0x6B4C70
#define __get_bearing_x                                            0x5C5B20
#define __get_melee_range_x                                        0x5C6200
#define __GetAnimationCache_x                                      0x71A070
#define __GetGaugeValueFromEQ_x                                    0x80BDC0
#define __GetLabelFromEQ_x                                         0x80D8A0
#define __GetXTargetType_x                                         0x98F730
#define __HandleMouseWheel_x                                       0x6B5B50
#define __HeadingDiff_x                                            0x98DCF0
#define __HelpPath_x                                               0xF45E04
#define __LoadFrontEnd_x                                           0x6B1F80
#define __NewUIINI_x                                               0x80BA90
#define __ProcessGameEvents_x                                      0x626A90
#define __ProcessMouseEvent_x                                      0x626220
#define __SaveColors_x                                             0x55DEC0
#define __STMLToText_x                                             0x931090
#define __ToggleKeyRingItem_x                                      0x51C690
#define CMemoryMappedFile__SetFile_x                               0xA7CF30
#define CrashDetected_x                                            0x6B3A30
#define DrawNetStatus_x                                            0x652AB0
#define Expansion_HoT_x                                            0xEA7D48
#define Teleport_Table_Size_x                                      0xE9F7E0
#define Teleport_Table_x                                           0xE9FCB0
#define Util__FastTime_x                                           0x8F8540
#define __CopyLayout_x                                             0x640DE0
#define __WndProc_x                                                0x6B3F30
#define __ProcessKeyboardEvent_x                                   0x6B34D0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4905D0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4995C0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499390
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493B60
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492FB0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x565FD0
#define AltAdvManager__IsAbilityReady_x                            0x564D70
#define AltAdvManager__GetAAById_x                                 0x565100
#define AltAdvManager__CanTrainAbility_x                           0x565170
#define AltAdvManager__CanSeeAbility_x                             0x5654D0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CB320
#define CharacterZoneClient__HasSkill_x                            0x4D61A0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D78D0
#define CharacterZoneClient__IsStackBlocked_x                      0x4C29D0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBE60
#define CharacterZoneClient__GetItemCountWorn_x                    0x4DA250
#define CharacterZoneClient__GetItemCountInInventory_x             0x4DA330
#define CharacterZoneClient__GetCursorItemCount_x                  0x4DA410
#define CharacterZoneClient__FindAffectSlot_x                      0x4C4AC0
#define CharacterZoneClient__BardCastBard_x                        0x4C74F0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF870
#define CharacterZoneClient__GetEffect_x                           0x4BBDA0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C5B30
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C5C00
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C5C50
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5DA0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5F80
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3E00
#define CharacterZoneClient__FindItemByGuid_x                      0x4D8830
#define CharacterZoneClient__FindItemByRecord_x                    0x4D82B0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6DB7E0
#define CBankWnd__WndNotification_x                                0x6DB5B0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E9020

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x92E880
#define CButtonWnd__CButtonWnd_x                                   0x92D470

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x709270
#define CChatManager__InitContextMenu_x                            0x7023A0
#define CChatManager__FreeChatWindow_x                             0x707DB0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9C40
#define CChatManager__SetLockedActiveChatWindow_x                  0x708EF0
#define CChatManager__CreateChatWindow_x                           0x7083F0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9D50

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x941AA0
#define CContextMenu__dCContextMenu_x                              0x941CE0
#define CContextMenu__AddMenuItem_x                                0x941CF0
#define CContextMenu__RemoveMenuItem_x                             0x942000
#define CContextMenu__RemoveAllMenuItems_x                         0x942020
#define CContextMenu__CheckMenuItem_x                              0x9420A0
#define CContextMenu__SetMenuItem_x                                0x941F20
#define CContextMenu__AddSeparator_x                               0x941E80

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x942640
#define CContextMenuManager__RemoveMenu_x                          0x9426B0
#define CContextMenuManager__PopupMenu_x                           0x942770
#define CContextMenuManager__Flush_x                               0x9425E0
#define CContextMenuManager__GetMenu_x                             0x49B890
#define CContextMenuManager__CreateDefaultMenu_x                   0x7149B0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D37C0
#define CChatService__GetFriendName_x                              0x8D37D0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x709AA0
#define CChatWindow__Clear_x                                       0x70AD70
#define CChatWindow__WndNotification_x                             0x70B500
#define CChatWindow__AddHistory_x                                  0x70A630

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93EEE0
#define CComboWnd__Draw_x                                          0x93E3C0
#define CComboWnd__GetCurChoice_x                                  0x93ED20
#define CComboWnd__GetListRect_x                                   0x93E880
#define CComboWnd__GetTextRect_x                                   0x93EF50
#define CComboWnd__InsertChoice_x                                  0x93EA10
#define CComboWnd__SetColors_x                                     0x93E9E0
#define CComboWnd__SetChoice_x                                     0x93ECF0
#define CComboWnd__GetItemCount_x                                  0x93ED30
#define CComboWnd__GetCurChoiceText_x                              0x93ED70
#define CComboWnd__GetChoiceText_x                                 0x93ED40
#define CComboWnd__InsertChoiceAtIndex_x                           0x93EAB0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x7123E0
#define CContainerWnd__vftable_x                                   0xB00764
#define CContainerWnd__SetContainer_x                              0x713920

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x558820
#define CDisplay__PreZoneMainUI_x                                  0x558830
#define CDisplay__CleanGameUI_x                                    0x55DC80
#define CDisplay__GetClickedActor_x                                0x550C80
#define CDisplay__GetUserDefinedColor_x                            0x5492F0
#define CDisplay__GetWorldFilePath_x                               0x5526F0
#define CDisplay__is3dON_x                                         0x54D8E0
#define CDisplay__ReloadUI_x                                       0x557D30
#define CDisplay__WriteTextHD2_x                                   0x54D6D0
#define CDisplay__TrueDistance_x                                   0x5543B0
#define CDisplay__SetViewActor_x                                   0x5505A0
#define CDisplay__GetFloorHeight_x                                 0x54D9A0
#define CDisplay__SetRenderWindow_x                                0x54C320
#define CDisplay__ToggleScreenshotMode_x                           0x550070

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x961860

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x944FA0
#define CEditWnd__EnsureCaretVisible_x                             0x947170
#define CEditWnd__GetCaretPt_x                                     0x946120
#define CEditWnd__GetCharIndexPt_x                                 0x945ED0
#define CEditWnd__GetDisplayString_x                               0x945D70
#define CEditWnd__GetHorzOffset_x                                  0x944640
#define CEditWnd__GetLineForPrintableChar_x                        0x947070
#define CEditWnd__GetSelStartPt_x                                  0x946180
#define CEditWnd__GetSTMLSafeText_x                                0x945B90
#define CEditWnd__PointFromPrintableChar_x                         0x946CA0
#define CEditWnd__SelectableCharFromPoint_x                        0x946E10
#define CEditWnd__SetEditable_x                                    0x946250
#define CEditWnd__SetWindowTextA_x                                 0x945910
#define CEditWnd__ReplaceSelection_x                               0x946910
#define CEditWnd__ReplaceSelection1_x                              0x946890

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x614090
#define CEverQuest__ClickedPlayer_x                                0x606230
#define CEverQuest__CreateTargetIndicator_x                        0x623C00
#define CEverQuest__DeleteTargetIndicator_x                        0x623C90
#define CEverQuest__DoTellWindow_x                                 0x4E9E30
#define CEverQuest__OutputTextToLog_x                              0x4EA100
#define CEverQuest__DropHeldItemOnGround_x                         0x5FB390
#define CEverQuest__dsp_chat_x                                     0x4EA490
#define CEverQuest__trimName_x                                     0x61FDB0
#define CEverQuest__Emote_x                                        0x6148F0
#define CEverQuest__EnterZone_x                                    0x60E9F0
#define CEverQuest__GetBodyTypeDesc_x                              0x619340
#define CEverQuest__GetClassDesc_x                                 0x619980
#define CEverQuest__GetClassThreeLetterCode_x                      0x619F80
#define CEverQuest__GetDeityDesc_x                                 0x622450
#define CEverQuest__GetLangDesc_x                                  0x61A140
#define CEverQuest__GetRaceDesc_x                                  0x619960
#define CEverQuest__InterpretCmd_x                                 0x622A20
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FF520
#define CEverQuest__LMouseUp_x                                     0x5FD8B0
#define CEverQuest__RightClickedOnPlayer_x                         0x5FFE00
#define CEverQuest__RMouseUp_x                                     0x5FE830
#define CEverQuest__SetGameState_x                                 0x5FB120
#define CEverQuest__UPCNotificationFlush_x                         0x61FCB0
#define CEverQuest__IssuePetCommand_x                              0x61B550
#define CEverQuest__ReportSuccessfulHit_x                          0x615C40

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x724140
#define CGaugeWnd__CalcLinesFillRect_x                             0x7241A0
#define CGaugeWnd__Draw_x                                          0x7237D0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4B00C0
#define CGuild__GetGuildName_x                                     0x4AEB70
#define CGuild__GetGuildIndex_x                                    0x4AF170

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73DE30

//CHotButton
#define CHotButton__SetCheck_x                                     0x6352B0
#define CHotButton__SetButtonSize_x                                0x635670

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x74B0F0
#define CInvSlotMgr__MoveItem_x                                    0x749DC0
#define CInvSlotMgr__SelectSlot_x                                  0x74B1C0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7485B0
#define CInvSlot__SliderComplete_x                                 0x746300
#define CInvSlot__GetItemBase_x                                    0x745C70
#define CInvSlot__UpdateItem_x                                     0x745DE0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x74CC50
#define CInvSlotWnd__CInvSlotWnd_x                                 0x74BDE0
#define CInvSlotWnd__HandleLButtonUp_x                             0x74C7D0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x807170
#define CItemDisplayWnd__UpdateStrings_x                           0x75B460
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x7550C0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x7555F0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x75BA60
#define CItemDisplayWnd__AboutToShow_x                             0x75B0B0
#define CItemDisplayWnd__WndNotification_x                         0x75CCE0
#define CItemDisplayWnd__RequestConvertItem_x                      0x75C610
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x75A110
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x75AED0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x837D50

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x7611E0

// CLabel 
#define CLabel__Draw_x                                             0x766C70

// CListWnd
#define CListWnd__CListWnd_x                                       0x917780
#define CListWnd__dCListWnd_x                                      0x917AA0
#define CListWnd__AddColumn_x                                      0x91BF20
#define CListWnd__AddColumn1_x                                     0x91BF70
#define CListWnd__AddLine_x                                        0x91C300
#define CListWnd__AddString_x                                      0x91C100
#define CListWnd__CalculateFirstVisibleLine_x                      0x91BCE0
#define CListWnd__CalculateVSBRange_x                              0x91BAC0
#define CListWnd__ClearSel_x                                       0x91CAE0
#define CListWnd__ClearAllSel_x                                    0x91CB40
#define CListWnd__CloseAndUpdateEditWindow_x                       0x91D560
#define CListWnd__Compare_x                                        0x91B3F0
#define CListWnd__Draw_x                                           0x917BD0
#define CListWnd__DrawColumnSeparators_x                           0x91A3C0
#define CListWnd__DrawHeader_x                                     0x91A830
#define CListWnd__DrawItem_x                                       0x91AD30
#define CListWnd__DrawLine_x                                       0x91A530
#define CListWnd__DrawSeparator_x                                  0x91A460
#define CListWnd__EnableLine_x                                     0x919CA0
#define CListWnd__EnsureVisible_x                                  0x91D480
#define CListWnd__ExtendSel_x                                      0x91CA10
#define CListWnd__GetColumnTooltip_x                               0x9197E0
#define CListWnd__GetColumnMinWidth_x                              0x919850
#define CListWnd__GetColumnWidth_x                                 0x919750
#define CListWnd__GetCurSel_x                                      0x9190E0
#define CListWnd__GetItemAtPoint_x                                 0x919F20
#define CListWnd__GetItemAtPoint1_x                                0x919F90
#define CListWnd__GetItemData_x                                    0x919160
#define CListWnd__GetItemHeight_x                                  0x919520
#define CListWnd__GetItemIcon_x                                    0x9192F0
#define CListWnd__GetItemRect_x                                    0x919D90
#define CListWnd__GetItemText_x                                    0x9191A0
#define CListWnd__GetSelList_x                                     0x91CB90
#define CListWnd__GetSeparatorRect_x                               0x91A1D0
#define CListWnd__InsertLine_x                                     0x91C6F0
#define CListWnd__RemoveLine_x                                     0x91C840
#define CListWnd__SetColors_x                                      0x91BA90
#define CListWnd__SetColumnJustification_x                         0x91B7C0
#define CListWnd__SetColumnLabel_x                                 0x91C0A0
#define CListWnd__SetColumnWidth_x                                 0x91B6E0
#define CListWnd__SetCurSel_x                                      0x91C950
#define CListWnd__SetItemColor_x                                   0x91D130
#define CListWnd__SetItemData_x                                    0x91D0F0
#define CListWnd__SetItemText_x                                    0x91CD00
#define CListWnd__ShiftColumnSeparator_x                           0x91B880
#define CListWnd__Sort_x                                           0x91B570
#define CListWnd__ToggleSel_x                                      0x91C980
#define CListWnd__SetColumnsSizable_x                              0x91B930
#define CListWnd__SetItemWnd_x                                     0x91CFB0
#define CListWnd__GetItemWnd_x                                     0x919340
#define CListWnd__SetItemIcon_x                                    0x91CD80
#define CListWnd__CalculateCustomWindowPositions_x                 0x91BDE0
#define CListWnd__SetVScrollPos_x                                  0x91B6C0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x77C2F0
#define CMapViewWnd__GetWorldCoordinates_x                         0x77AA00
#define CMapViewWnd__HandleLButtonDown_x                           0x777A40

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x79C6C0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79CFA0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79D4D0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A0480
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x79B230
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A6050
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x79C2D0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8A1120
#define CPacketScrambler__hton_x                                   0x8A1110

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x936660
#define CSidlManager__FindScreenPieceTemplate_x                    0x936A70
#define CSidlManager__FindScreenPieceTemplate1_x                   0x936860
#define CSidlManager__CreateLabel_x                                0x7FE290
#define CSidlManager__CreateXWndFromTemplate_x                     0x9399D0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x939BB0
#define CSidlManager__CreateXWnd_x                                 0x7FE1C0
#define CSidlManager__CreateHotButtonWnd_x                         0x7FE790

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x933150
#define CSidlScreenWnd__CalculateVSBRange_x                        0x933050
#define CSidlScreenWnd__ConvertToRes_x                             0x95C350
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x932B40
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x932830
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x932900
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x9329D0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x9335F0
#define CSidlScreenWnd__EnableIniStorage_x                         0x933AC0
#define CSidlScreenWnd__GetSidlPiece_x                             0x9337E0
#define CSidlScreenWnd__Init1_x                                    0x932430
#define CSidlScreenWnd__LoadIniInfo_x                              0x933B10
#define CSidlScreenWnd__LoadIniListWnd_x                           0x934640
#define CSidlScreenWnd__LoadSidlScreen_x                           0x931840
#define CSidlScreenWnd__StoreIniInfo_x                             0x9341C0
#define CSidlScreenWnd__StoreIniVis_x                              0x934520
#define CSidlScreenWnd__WndNotification_x                          0x933500
#define CSidlScreenWnd__GetChildItem_x                             0x933A40
#define CSidlScreenWnd__HandleLButtonUp_x                          0x923350
#define CSidlScreenWnd__m_layoutCopy_x                             0x15DC190

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x69AC80
#define CSkillMgr__GetSkillCap_x                                   0x69AE60
#define CSkillMgr__GetNameToken_x                                  0x69A400
#define CSkillMgr__IsActivatedSkill_x                              0x69A540
#define CSkillMgr__IsCombatSkill_x                                 0x69A480

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x943420
#define CSliderWnd__SetValue_x                                     0x943290
#define CSliderWnd__SetNumTicks_x                                  0x9432F0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x804440

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x94BD60
#define CStmlWnd__ParseSTML_x                                      0x94D070
#define CStmlWnd__CalculateHSBRange_x                              0x94CE40
#define CStmlWnd__CalculateVSBRange_x                              0x94CDB0
#define CStmlWnd__CanBreakAtCharacter_x                            0x951180
#define CStmlWnd__FastForwardToEndOfTag_x                          0x951E10
#define CStmlWnd__ForceParseNow_x                                  0x94C300
#define CStmlWnd__GetNextTagPiece_x                                0x9510E0
#define CStmlWnd__GetSTMLText_x                                    0x50D850
#define CStmlWnd__GetVisibleText_x                                 0x94C320
#define CStmlWnd__InitializeWindowVariables_x                      0x951C60
#define CStmlWnd__MakeStmlColorTag_x                               0x94B3D0
#define CStmlWnd__MakeWndNotificationTag_x                         0x94B440
#define CStmlWnd__SetSTMLText_x                                    0x94A480
#define CStmlWnd__StripFirstSTMLLines_x                            0x952F10
#define CStmlWnd__UpdateHistoryString_x                            0x952020

// CTabWnd 
#define CTabWnd__Draw_x                                            0x9495D0
#define CTabWnd__DrawCurrentPage_x                                 0x949D00
#define CTabWnd__DrawTab_x                                         0x949A20
#define CTabWnd__GetCurrentPage_x                                  0x948DD0
#define CTabWnd__GetPageInnerRect_x                                0x949010
#define CTabWnd__GetTabInnerRect_x                                 0x948F50
#define CTabWnd__GetTabRect_x                                      0x948E00
#define CTabWnd__InsertPage_x                                      0x949220
#define CTabWnd__RemovePage_x                                      0x949390
#define CTabWnd__SetPage_x                                         0x949090
#define CTabWnd__SetPageRect_x                                     0x949510
#define CTabWnd__UpdatePage_x                                      0x9498E0
#define CTabWnd__GetPageFromTabIndex_x                             0x949960
#define CTabWnd__GetCurrentTabIndex_x                              0x948DC0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x761660
#define CPageWnd__SetTabText_x                                     0x948920
#define CPageWnd__FlashTab_x                                       0x948980

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9410

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x9201E0
#define CTextureFont__GetTextExtent_x                              0x9203A0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AEDD0
#define CHtmlComponentWnd__ValidateUri_x                           0x73F820
#define CHtmlWnd__SetClientCallbacks_x                             0x63A6F0
#define CHtmlWnd__AddObserver_x                                    0x63A710
#define CHtmlWnd__RemoveObserver_x                                 0x63A770
#define Window__getProgress_x                                      0x856800
#define Window__getStatus_x                                        0x856820
#define Window__getURI_x                                           0x856830

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x959150

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x90D2E0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9A80
#define CXStr__CXStr1_x                                            0x508BA0
#define CXStr__CXStr3_x                                            0x8F4930
#define CXStr__dCXStr_x                                            0x478420
#define CXStr__operator_equal_x                                    0x8F4B60
#define CXStr__operator_equal1_x                                   0x8F4BA0
#define CXStr__operator_plus_equal1_x                              0x8F5630
#define CXStr__SetString_x                                         0x8F7520
#define CXStr__operator_char_p_x                                   0x8F50A0
#define CXStr__GetChar_x                                           0x8F6E50
#define CXStr__Delete_x                                            0x8F6720
#define CXStr__GetUnicode_x                                        0x8F6EC0
#define CXStr__GetLength_x                                         0x47D600
#define CXStr__Mid_x                                               0x47D610
#define CXStr__Insert_x                                            0x8F6F20
#define CXStr__FindNext_x                                          0x8F6B90

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x9416A0
#define CXWnd__BringToTop_x                                        0x926A20
#define CXWnd__Center_x                                            0x9265A0
#define CXWnd__ClrFocus_x                                          0x9263C0
#define CXWnd__Destroy_x                                           0x926460
#define CXWnd__DoAllDrawing_x                                      0x922AE0
#define CXWnd__DrawChildren_x                                      0x922AB0
#define CXWnd__DrawColoredRect_x                                   0x922F40
#define CXWnd__DrawTooltip_x                                       0x9215E0
#define CXWnd__DrawTooltipAtPoint_x                                0x9216A0
#define CXWnd__GetBorderFrame_x                                    0x922DA0
#define CXWnd__GetChildWndAt_x                                     0x926AC0
#define CXWnd__GetClientClipRect_x                                 0x924D40
#define CXWnd__GetScreenClipRect_x                                 0x924E10
#define CXWnd__GetScreenRect_x                                     0x924FE0
#define CXWnd__GetRelativeRect_x                                   0x9250A0
#define CXWnd__GetTooltipRect_x                                    0x922F90
#define CXWnd__GetWindowTextA_x                                    0x49CF70
#define CXWnd__IsActive_x                                          0x9236D0
#define CXWnd__IsDescendantOf_x                                    0x9259C0
#define CXWnd__IsReallyVisible_x                                   0x9259F0
#define CXWnd__IsType_x                                            0x927140
#define CXWnd__Move_x                                              0x925A50
#define CXWnd__Move1_x                                             0x925B00
#define CXWnd__ProcessTransition_x                                 0x926550
#define CXWnd__Refade_x                                            0x925DB0
#define CXWnd__Resize_x                                            0x926040
#define CXWnd__Right_x                                             0x9267E0
#define CXWnd__SetFocus_x                                          0x926380
#define CXWnd__SetFont_x                                           0x9263F0
#define CXWnd__SetKeyTooltip_x                                     0x926F50
#define CXWnd__SetMouseOver_x                                      0x923EE0
#define CXWnd__StartFade_x                                         0x9258A0
#define CXWnd__GetChildItem_x                                      0x926C30
#define CXWnd__SetParent_x                                         0x925750
#define CXWnd__Minimize_x                                          0x9260A0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x95D3D0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9298E0
#define CXWndManager__DrawWindows_x                                0x929900
#define CXWndManager__GetKeyboardFlags_x                           0x92C100
#define CXWndManager__HandleKeyboardMsg_x                          0x92BCB0
#define CXWndManager__RemoveWnd_x                                  0x92C330
#define CXWndManager__RemovePendingDeletionWnd_x                   0x92C8B0

// CDBStr
#define CDBStr__GetString_x                                        0x548290

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BFFD0
#define EQ_Character__Cur_HP_x                                     0x4D31E0
#define EQ_Character__Cur_Mana_x                                   0x4DA910
#define EQ_Character__GetCastingTimeModifier_x                     0x4C3040
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B3A40
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3B90
#define EQ_Character__GetHPRegen_x                                 0x4E07E0
#define EQ_Character__GetEnduranceRegen_x                          0x4E0DE0
#define EQ_Character__GetManaRegen_x                               0x4E1220
#define EQ_Character__Max_Endurance_x                              0x6611E0
#define EQ_Character__Max_HP_x                                     0x4D3010
#define EQ_Character__Max_Mana_x                                   0x660FE0
#define EQ_Character__doCombatAbility_x                            0x6635D0
#define EQ_Character__UseSkill_x                                   0x4E3020
#define EQ_Character__GetConLevel_x                                0x659A50
#define EQ_Character__IsExpansionFlag_x                            0x5BD090
#define EQ_Character__TotalEffect_x                                0x4C6DE0
#define EQ_Character__GetPCSpellAffect_x                           0x4C3D90
#define EQ_Character__SpellDuration_x                              0x4C38C0
#define EQ_Character__MySpellDuration_x                            0x4B2370
#define EQ_Character__GetAdjustedSkill_x                           0x4D5F60
#define EQ_Character__GetBaseSkill_x                               0x4D6F00
#define EQ_Character__CanUseItem_x                                 0x4DAC20

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8C07C0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x677580

//PcClient
#define PcClient__vftable_x                                        0xAF41C8
#define PcClient__PcClient_x                                       0x6571B0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BAA20
#define CCharacterListWnd__EnterWorld_x                            0x4BA3F0
#define CCharacterListWnd__Quit_x                                  0x4BA140
#define CCharacterListWnd__UpdateList_x                            0x4BA5E0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x63B8C0
#define EQ_Item__CreateItemTagString_x                             0x89A5F0
#define EQ_Item__IsStackable_x                                     0x89F2F0
#define EQ_Item__GetImageNum_x                                     0x89C150
#define EQ_Item__CreateItemClient_x                                0x63AAF0
#define EQ_Item__GetItemValue_x                                    0x89D450
#define EQ_Item__ValueSellMerchant_x                               0x8A0D00
#define EQ_Item__IsKeyRingItem_x                                   0x89EBA0
#define EQ_Item__CanGoInBag_x                                      0x63B9E0
#define EQ_Item__IsEmpty_x                                         0x89E6E0
#define EQ_Item__GetMaxItemCount_x                                 0x89D860
#define EQ_Item__GetHeldItem_x                                     0x89C020
#define EQ_Item__GetAugmentFitBySlot_x                             0x899E60

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x566CA0
#define EQ_LoadingS__Array_x                                       0xC15130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x661AE0
#define EQ_PC__GetAlternateAbilityId_x                             0x8AA010
#define EQ_PC__GetCombatAbility_x                                  0x8AA680
#define EQ_PC__GetCombatAbilityTimer_x                             0x8AA6F0
#define EQ_PC__GetItemRecastTimer_x                                0x663B50
#define EQ_PC__HasLoreItem_x                                       0x65A2C0
#define EQ_PC__AlertInventoryChanged_x                             0x659380
#define EQ_PC__GetPcZoneClient_x                                   0x686690
#define EQ_PC__RemoveMyAffect_x                                    0x666D80
#define EQ_PC__GetKeyRingItems_x                                   0x8AAFC0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8AAD40
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8AB2C0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5C3530
#define EQItemList__add_object_x                                   0x5F0B20
#define EQItemList__add_item_x                                     0x5C3A90
#define EQItemList__delete_item_x                                  0x5C3AE0
#define EQItemList__FreeItemList_x                                 0x5C39E0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x544DD0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x678E80
#define EQPlayer__dEQPlayer_x                                      0x66C210
#define EQPlayer__DoAttack_x                                       0x680E30
#define EQPlayer__EQPlayer_x                                       0x66C8D0
#define EQPlayer__SetNameSpriteState_x                             0x670B90
#define EQPlayer__SetNameSpriteTint_x                              0x671A70
#define PlayerBase__HasProperty_j_x                                0x98C070
#define EQPlayer__IsTargetable_x                                   0x98C510
#define EQPlayer__CanSee_x                                         0x98C370
#define EQPlayer__CanSee1_x                                        0x98C440
#define PlayerBase__GetVisibilityLineSegment_x                     0x98C130

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x684130
#define PlayerZoneClient__GetLevel_x                               0x6866D0
#define PlayerZoneClient__IsValidTeleport_x                        0x5F1C90
#define PlayerZoneClient__LegalPlayerRace_x                        0x55FAB0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x67BCD0
#define EQPlayerManager__GetSpawnByName_x                          0x67BD80
#define EQPlayerManager__GetPlayerFromPartialName_x                0x67BE10

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63F040
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63F0C0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63F100
#define KeypressHandler__ClearCommandStateArray_x                  0x6404F0
#define KeypressHandler__HandleKeyDown_x                           0x640510
#define KeypressHandler__HandleKeyUp_x                             0x6405B0
#define KeypressHandler__SaveKeymapping_x                          0x640A00

// MapViewMap 
#define MapViewMap__Clear_x                                        0x778160
#define MapViewMap__SaveEx_x                                       0x77B520
#define MapViewMap__SetZoom_x                                      0x77FBE0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BE820

// StringTable 
#define StringTable__getString_x                                   0x8B9610

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x6669F0
#define PcZoneClient__RemovePetEffect_x                            0x667020
#define PcZoneClient__HasAlternateAbility_x                        0x660E10
#define PcZoneClient__GetCurrentMod_x                              0x4E6140
#define PcZoneClient__GetModCap_x                                  0x4E6040
#define PcZoneClient__CanEquipItem_x                               0x6614C0
#define PcZoneClient__GetItemByID_x                                0x663FC0
#define PcZoneClient__GetItemByItemClass_x                         0x664110
#define PcZoneClient__RemoveBuffEffect_x                           0x667040
#define PcZoneClient__BandolierSwap_x                              0x6620A0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x663AF0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F6810

//IconCache
#define IconCache__GetIcon_x                                       0x719A70

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x711570
#define CContainerMgr__CloseContainer_x                            0x711840
#define CContainerMgr__OpenExperimentContainer_x                   0x7122C0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D0A60

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x633A90

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76E710
#define CLootWnd__RequestLootSlot_x                                0x76D9F0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58EC10
#define EQ_Spell__SpellAffects_x                                   0x58F080
#define EQ_Spell__SpellAffectBase_x                                0x58EE40
#define EQ_Spell__IsStackable_x                                    0x4CAC30
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CAA20
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7D00
#define EQ_Spell__IsSPAStacking_x                                  0x58FED0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58F3E0
#define EQ_Spell__IsNoRemove_x                                     0x4CAC10
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58FEE0
#define __IsResEffectSpell_x                                       0x4C9E30

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD5D0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C8DE0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x817820
#define CTargetWnd__WndNotification_x                              0x817060
#define CTargetWnd__RefreshTargetBuffs_x                           0x817330
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x8161C0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x81BEA0
#define CTaskWnd__ConfirmAbandonTask_x                             0x81EAE0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x542820
#define CTaskManager__HandleMessage_x                              0x540C80
#define CTaskManager__GetTaskStatus_x                              0x5428D0
#define CTaskManager__GetElementDescription_x                      0x542950

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x589D90
#define EqSoundManager__PlayScriptMp3_x                            0x58A050
#define EqSoundManager__SoundAssistPlay_x                          0x69EB90
#define EqSoundManager__WaveInstancePlay_x                         0x69E100

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x533BD0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x947E30
#define CTextureAnimation__Draw_x                                  0x948030

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x943D80

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56E8C0
#define CAltAbilityData__GetMercMaxRank_x                          0x56E850
#define CAltAbilityData__GetMaxRank_x                              0x563BF0

//CTargetRing
#define CTargetRing__Cast_x                                        0x631BB0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CAA00
#define CharacterBase__CreateItemGlobalIndex_x                     0x51A790
#define CharacterBase__CreateItemIndex_x                           0x639CA0
#define CharacterBase__GetItemPossession_x                         0x506400
#define CharacterBase__GetItemByGlobalIndex_x                      0x8D1470
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8D14D0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F8570
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F8DA0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F8E50

//messages
#define msg_spell_worn_off_x                                       0x5B50B0
#define msg_new_text_x                                             0x5A9A30
#define __msgTokenTextParam_x                                      0x5B7350
#define msgTokenText_x                                             0x5B75A0

//SpellManager
#define SpellManager__vftable_x                                    0xADC544
#define SpellManager__SpellManager_x                               0x6A1EC0
#define Spellmanager__LoadTextSpells_x                             0x6A27B0
#define SpellManager__GetSpellByGroupAndRank_x                     0x6A2090

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x990020

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x51AE10
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5BB5C0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x652910
#define ItemGlobalIndex__IsValidIndex_x                            0x51AEA0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C97A0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C9930

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x766FB0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x715C50
#define CCursorAttachment__AttachToCursor1_x                       0x715C90
#define CCursorAttachment__Deactivate_x                            0x716C80

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x93AA10
#define CSidlManagerBase__CreatePageWnd_x                          0x93A200
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x936480
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x936410

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x957C60
#define CEQSuiteTextureLoader__GetTexture_x                        0x957920

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x517A80
#define CFindItemWnd__WndNotification_x                            0x5186C0
#define CFindItemWnd__Update_x                                     0x519230
#define CFindItemWnd__PickupSelectedItem_x                         0x5172B0

//IString
#define IString__Append_x                                          0x507CB0

//Camera
#define CDisplay__cameraType_x                                     0xDECCCC
#define EverQuest__Cameras_x                                       0xEA80A0

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x5207F0
#define LootFiltersManager__GetItemFilterData_x                    0x5200F0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x520120
#define LootFiltersManager__SetItemLootFilter_x                    0x520340

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BE860

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x995C40
#define CResolutionHandler__GetWindowedStyle_x                     0x699670

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70E220

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D5290
#define CDistillerInfo__Instance_x                                 0x8D5230

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72D130
#define CGroupWnd__UpdateDisplay_x                                 0x72C480

//ItemBase
#define ItemBase__IsLore_x                                         0x89EC50
#define ItemBase__IsLoreEquipped_x                                 0x89ECC0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5F0A80
#define EQPlacedItemManager__GetItemByGuid_x                       0x5F0BC0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5F0C20

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68EE20
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x692780

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50E070

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4FA1E0
#define FactionManagerClient__HandleFactionMessage_x               0x4FA850
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4FAE50
#define FactionManagerClient__GetMaxFaction_x                      0x4FAE6F
#define FactionManagerClient__GetMinFaction_x                      0x4FAE20

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x5063D0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91F200

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C280

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x5066C0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56DD50

//CTargetManager
#define CTargetManager__Get_x                                      0x6A56F0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68EE20

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A91D0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5C3980

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF45734

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6C1DF0
#define CAAWnd__UpdateSelected_x                                   0x6BE660
#define CAAWnd__Update_x                                           0x6C1110

//CXRect
#define CXRect__operator_and_x                                     0x724200

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x4832C0

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";

//__eqgraphics_fopen
//Jan 09 2020 EQGraphicsDX9.dll
//IDA Style Sig: E8 ? ? ? ? 83 C4 08 89 45 A0
//#define __eqgraphics_fopen_x                                       0x101473C8
static PBYTE efPattern = (PBYTE)"\xE8\x00\x00\x00\x00\x83\xC4\x08\x89\x45\xA0";
static char efMask[] = "x????xxxxxx";
