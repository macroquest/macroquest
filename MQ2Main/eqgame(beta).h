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
#define __ExpectedVersionDate                                     "Nov  1 2019"
#define __ExpectedVersionTime                                     "04:22:37"
#define __ActualVersionDate_x                                      0xB05F08
#define __ActualVersionTime_x                                      0xB05EFC
#define __ActualVersionBuild_x                                     0xAF1BE4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x62B270
#define __MemChecker1_x                                            0x8FDEC0
#define __MemChecker2_x                                            0x6B9D80
#define __MemChecker3_x                                            0x6B9CD0
#define __MemChecker4_x                                            0x855850
#define __EncryptPad0_x                                            0xC3C3E0
#define __EncryptPad1_x                                            0xC9A5A0
#define __EncryptPad2_x                                            0xC4CC78
#define __EncryptPad3_x                                            0xC4C878
#define __EncryptPad4_x                                            0xC8ABF8
#define __EncryptPad5_x                                            0xF63CDC
#define __AC1_x                                                    0x8123B6
#define __AC2_x                                                    0x5E526F
#define __AC3_x                                                    0x5EC96F
#define __AC4_x                                                    0x5F0940
#define __AC5_x                                                    0x5F6C4F
#define __AC6_x                                                    0x5FB266
#define __AC7_x                                                    0x5E4CE0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x196718

// Direct Input
#define DI8__Main_x                                                0xF661B8
#define DI8__Keyboard_x                                            0xF661BC
#define DI8__Mouse_x                                               0xF661D0
#define DI8__Mouse_Copy_x                                          0xEBF3A4
#define DI8__Mouse_Check_x                                         0xF63D04
#define __AutoSkillArray_x                                         0xEC02BC
#define __Attack_x                                                 0xF5E0E3
#define __Autofire_x                                               0xF5E0E4
#define __BindList_x                                               0xC2AE18
#define g_eqCommandStates_x                                        0xC2BB98
#define __Clicks_x                                                 0xEBF45C
#define __CommandList_x                                            0xC2C758
#define __CurrentMapLabel_x                                        0xF76B64
#define __CurrentSocial_x                                          0xC147CC
#define __DoAbilityList_x                                          0xEF5C04
#define __do_loot_x                                                0x5B1520
#define __DrawHandler_x                                            0x15F5ED8
#define __GroupCount_x                                             0xEB1C6A
#define __Guilds_x                                                 0xEB5BB0
#define __gWorld_x                                                 0xEB1B34
#define __HWnd_x                                                   0xF661D4
#define __heqmain_x                                                0xF661AC
#define __InChatMode_x                                             0xEBF38C
#define __LastTell_x                                               0xEC1300
#define __LMouseHeldTime_x                                         0xEBF4C8
#define __Mouse_x                                                  0xF66198
#define __MouseLook_x                                              0xEBF422
#define __MouseEventTime_x                                         0xF5EBC4
#define __gpbCommandEvent_x                                        0xEB1E5C
#define __NetStatusToggle_x                                        0xEBF425
#define __PCNames_x                                                0xEC08AC
#define __RangeAttackReady_x                                       0xEC05A0
#define __RMouseHeldTime_x                                         0xEBF4C4
#define __RunWalkState_x                                           0xEBF390
#define __ScreenMode_x                                             0xDFD470
#define __ScreenX_x                                                0xEBF344
#define __ScreenY_x                                                0xEBF340
#define __ScreenXMax_x                                             0xEBF348
#define __ScreenYMax_x                                             0xEBF34C
#define __ServerHost_x                                             0xEAF79B
#define __ServerName_x                                             0xEF5BC4
#define __ShiftKeyDown_x                                           0xEBFA1C
#define __ShowNames_x                                              0xEC075C
#define __Socials_x                                                0xEF5CC4
#define __SubscriptionType_x                                       0xFBB068
#define __TargetAggroHolder_x                                      0xF79518
#define __ZoneType_x                                               0xEBF820
#define __GroupAggro_x                                             0xF79558
#define __LoginName_x                                              0xF66914
#define __Inviter_x                                                0xF5E060
#define __AttackOnAssist_x                                         0xEC0718
#define __UseTellWindows_x                                         0xEC0A48
#define __gfMaxZoomCameraDistance_x                                0xAFB858
#define __gfMaxCameraDistance_x                                    0xB27DB0
#define __pulAutoRun_x                                             0xEBF440
#define __pulForward_x                                             0xEC0A80
#define __pulBackward_x                                            0xEC0A84
#define __pulTurnRight_x                                           0xEC0A88
#define __pulTurnLeft_x                                            0xEC0A8C
#define __pulStrafeLeft_x                                          0xEC0A90
#define __pulStrafeRight_x                                         0xEC0A94

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEB1F48
#define instEQZoneInfo_x                                           0xEBF618
#define pinstActiveBanker_x                                        0xEB1E74
#define pinstActiveCorpse_x                                        0xEB1E6C
#define pinstActiveGMaster_x                                       0xEB1E70
#define pinstActiveMerchant_x                                      0xEB1E68
#define pinstAltAdvManager_x                                       0xDFE180
#define pinstBandageTarget_x                                       0xEB1E84
#define pinstCamActor_x                                            0xDFD460
#define pinstCDBStr_x                                              0xDFCE9C
#define pinstCDisplay_x                                            0xEB1B18
#define pinstCEverQuest_x                                          0xF661D8
#define pinstEverQuestInfo_x                                       0xEBF338
#define pinstCharData_x                                            0xEB1C48
#define pinstCharSpawn_x                                           0xEB1F3C
#define pinstControlledMissile_x                                   0xEAFB00
#define pinstControlledPlayer_x                                    0xEB1F3C
#define pinstCResolutionHandler_x                                  0x15F6108
#define pinstCSidlManager_x                                        0x15F50A0
#define pinstCXWndManager_x                                        0x15F509C
#define instDynamicZone_x                                          0xEB5A88
#define pinstDZMember_x                                            0xEB5B98
#define pinstDZTimerInfo_x                                         0xEB5B9C
#define pinstEqLogin_x                                             0xF66260
#define instEQMisc_x                                               0xDFCDE0
#define pinstEQSoundManager_x                                      0xDFF150
#define pinstEQSpellStrings_x                                      0xCBF858
#define instExpeditionLeader_x                                     0xEB5AD2
#define instExpeditionName_x                                       0xEB5B12
#define pinstGroup_x                                               0xEB1C66
#define pinstImeManager_x                                          0x15F5098
#define pinstLocalPlayer_x                                         0xEB1E64
#define pinstMercenaryData_x                                       0xF606B4
#define pinstMercenaryStats_x                                      0xF79664
#define pinstModelPlayer_x                                         0xEB1E7C
#define pinstPCData_x                                              0xEB1C48
#define pinstSkillMgr_x                                            0xF62820
#define pinstSpawnManager_x                                        0xF612C8
#define pinstSpellManager_x                                        0xF62A40
#define pinstSpellSets_x                                           0xF56D0C
#define pinstStringTable_x                                         0xEB1C4C
#define pinstSwitchManager_x                                       0xEAF4E8
#define pinstTarget_x                                              0xEB1F38
#define pinstTargetObject_x                                        0xEAF638
#define pinstTargetSwitch_x                                        0xEB1B10
#define pinstTaskMember_x                                          0xDFCC70
#define pinstTrackTarget_x                                         0xEB1F40
#define pinstTradeTarget_x                                         0xEB1E78
#define instTributeActive_x                                        0xDFCE01
#define pinstViewActor_x                                           0xDFD45C
#define pinstWorldData_x                                           0xEAFB0C
#define pinstZoneAddr_x                                            0xEBF8B8
#define pinstPlayerPath_x                                          0xF61360
#define pinstTargetIndicator_x                                     0xF62CA8
#define EQObject_Top_x                                             0xEB1E60
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDFD724
#define pinstCAchievementsWnd_x                                    0xDFD4BC
#define pinstCActionsWnd_x                                         0xDFD4E8
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDFCF84
#define pinstCAdvancedLootWnd_x                                    0xDFD7C8
#define pinstCAdventureLeaderboardWnd_x                            0xF70338
#define pinstCAdventureRequestWnd_x                                0xF703E8
#define pinstCAdventureStatsWnd_x                                  0xF70498
#define pinstCAggroMeterWnd_x                                      0xDFD454
#define pinstCAlarmWnd_x                                           0xDFD78C
#define pinstCAlertHistoryWnd_x                                    0xDFD7C0
#define pinstCAlertStackWnd_x                                      0xDFD738
#define pinstCAlertWnd_x                                           0xDFD74C
#define pinstCAltStorageWnd_x                                      0xF707F8
#define pinstCAudioTriggersWindow_x                                0xCB1B88
#define pinstCAuraWnd_x                                            0xDFD428
#define pinstCAvaZoneWnd_x                                         0xDFD788
#define pinstCBandolierWnd_x                                       0xDFD450
#define pinstCBankWnd_x                                            0xDFD424
#define pinstCBarterMerchantWnd_x                                  0xF71A38
#define pinstCBarterSearchWnd_x                                    0xF71AE8
#define pinstCBarterWnd_x                                          0xF71B98
#define pinstCBazaarConfirmationWnd_x                              0xDFD4F8
#define pinstCBazaarSearchWnd_x                                    0xDFD4B0
#define pinstCBazaarWnd_x                                          0xDFD774
#define pinstCBlockedBuffWnd_x                                     0xDFD42C
#define pinstCBlockedPetBuffWnd_x                                  0xDFD44C
#define pinstCBodyTintWnd_x                                        0xDFD4FC
#define pinstCBookWnd_x                                            0xDFD490
#define pinstCBreathWnd_x                                          0xDFD744
#define pinstCBuffWindowNORMAL_x                                   0xDFD010
#define pinstCBuffWindowSHORT_x                                    0xDFD014
#define pinstCBugReportWnd_x                                       0xDFD420
#define pinstCButtonWnd_x                                          0x15F5308
#define pinstCCastingWnd_x                                         0xDFD480
#define pinstCCastSpellWnd_x                                       0xDFD73C
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDFD778
#define pinstCChatWindowManager_x                                  0xF72658
#define pinstCClaimWnd_x                                           0xF727B0
#define pinstCColorPickerWnd_x                                     0xDFD4F0
#define pinstCCombatAbilityWnd_x                                   0xDFD784
#define pinstCCombatSkillsSelectWnd_x                              0xDFD7A8
#define pinstCCompassWnd_x                                         0xDFD4EC
#define pinstCConfirmationDialog_x                                 0xF776B0
#define pinstCContainerMgr_x                                       0xDFD76C
#define pinstCContextMenuManager_x                                 0x15F5058
#define pinstCCursorAttachment_x                                   0xDFD464
#define pinstCDynamicZoneWnd_x                                     0xF72D78
#define pinstCEditLabelWnd_x                                       0xDFCF90
#define pinstCEQMainWnd_x                                          0xF72FC0
#define pinstCEventCalendarWnd_x                                   0xDFD00C
#define pinstCExtendedTargetWnd_x                                  0xDFD440
#define pinstCFacePick_x                                           0xDFD7B8
#define pinstCFactionWnd_x                                         0xDFD764
#define pinstCFellowshipWnd_x                                      0xF731C0
#define pinstCFileSelectionWnd_x                                   0xDFD47C
#define pinstCFindItemWnd_x                                        0xDFD758
#define pinstCFindLocationWnd_x                                    0xF73318
#define pinstCFriendsWnd_x                                         0xDFD7C4
#define pinstCGemsGameWnd_x                                        0xDFD760
#define pinstCGiveWnd_x                                            0xDFD790
#define pinstCGroupSearchFiltersWnd_x                              0xDFD488
#define pinstCGroupSearchWnd_x                                     0xF73710
#define pinstCGroupWnd_x                                           0xF737C0
#define pinstCGuildBankWnd_x                                       0xEC06FC
#define pinstCGuildCreationWnd_x                                   0xF73920
#define pinstCGuildMgmtWnd_x                                       0xF739D0
#define pinstCharacterCreation_x                                   0xDFD7B0
#define pinstCHelpWnd_x                                            0xDFCF7C
#define pinstCHeritageSelectionWnd_x                               0xDFD7D0
#define pinstCHotButtonWnd_x                                       0xF75B28
#define pinstCHotButtonWnd1_x                                      0xF75B28
#define pinstCHotButtonWnd2_x                                      0xF75B2C
#define pinstCHotButtonWnd3_x                                      0xF75B30
#define pinstCHotButtonWnd4_x                                      0xF75B34
#define pinstCIconSelectionWnd_x                                   0xDFD458
#define pinstCInspectWnd_x                                         0xDFCF78
#define pinstCInventoryWnd_x                                       0xDFCF38
#define pinstCInvSlotMgr_x                                         0xDFD720
#define pinstCItemDisplayManager_x                                 0xF760B8
#define pinstCItemExpTransferWnd_x                                 0xF761E8
#define pinstCItemOverflowWnd_x                                    0xDFD4B8
#define pinstCJournalCatWnd_x                                      0xDFD498
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDFD444
#define pinstCKeyRingWnd_x                                         0xDFCF8C
#define pinstCLargeDialogWnd_x                                     0xF78330
#define pinstCLayoutCopyWnd_x                                      0xF76538
#define pinstCLFGuildWnd_x                                         0xF765E8
#define pinstCLoadskinWnd_x                                        0xDFD770
#define pinstCLootFiltersCopyWnd_x                                 0xCCE178
#define pinstCLootFiltersWnd_x                                     0xDFD740
#define pinstCLootSettingsWnd_x                                    0xDFD754
#define pinstCLootWnd_x                                            0xDFD49C
#define pinstCMailAddressBookWnd_x                                 0xDFD72C
#define pinstCMailCompositionWnd_x                                 0xDFD510
#define pinstCMailIgnoreListWnd_x                                  0xDFD730
#define pinstCMailWnd_x                                            0xDFD4E4
#define pinstCManageLootWnd_x                                      0xDFE630
#define pinstCMapToolbarWnd_x                                      0xDFCF80
#define pinstCMapViewWnd_x                                         0xDFCF48
#define pinstCMarketplaceWnd_x                                     0xDFD748
#define pinstCMerchantWnd_x                                        0xDFD4A0
#define pinstCMIZoneSelectWnd_x                                    0xF76E20
#define pinstCMusicPlayerWnd_x                                     0xDFD4A8
#define pinstCNameChangeMercWnd_x                                  0xDFD4E0
#define pinstCNameChangePetWnd_x                                   0xDFD4C0
#define pinstCNameChangeWnd_x                                      0xDFD508
#define pinstCNoteWnd_x                                            0xDFCF4C
#define pinstCObjectPreviewWnd_x                                   0xDFD750
#define pinstCOptionsWnd_x                                         0xDFCF68
#define pinstCPetInfoWnd_x                                         0xDFD4C4
#define pinstCPetitionQWnd_x                                       0xDFD4AC
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDFD500
#define pinstCPlayerWnd_x                                          0xDFD4C8
#define pinstCPopupWndManager_x                                    0xF776B0
#define pinstCProgressionSelectionWnd_x                            0xF77760
#define pinstCPurchaseGroupWnd_x                                   0xDFD798
#define pinstCPurchaseWnd_x                                        0xDFD768
#define pinstCPvPLeaderboardWnd_x                                  0xF77810
#define pinstCPvPStatsWnd_x                                        0xF778C0
#define pinstCQuantityWnd_x                                        0xDFD448
#define pinstCRaceChangeWnd_x                                      0xDFD728
#define pinstCRaidOptionsWnd_x                                     0xDFD48C
#define pinstCRaidWnd_x                                            0xDFD518
#define pinstCRealEstateItemsWnd_x                                 0xDFD4B4
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDFD434
#define pinstCRealEstateManageWnd_x                                0xDFD7A0
#define pinstCRealEstateNeighborhoodWnd_x                          0xDFD7BC
#define pinstCRealEstatePlotSearchWnd_x                            0xDFCF3C
#define pinstCRealEstatePurchaseWnd_x                              0xDFCF74
#define pinstCRespawnWnd_x                                         0xDFD438
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDFD734
#define pinstCSendMoneyWnd_x                                       0xDFD7A4
#define pinstCServerListWnd_x                                      0xDFCFA0
#define pinstCSkillsSelectWnd_x                                    0xDFD77C
#define pinstCSkillsWnd_x                                          0xDFD75C
#define pinstCSocialEditWnd_x                                      0xDFCF88
#define pinstCSocialWnd_x                                          0xDFD4DC
#define pinstCSpellBookWnd_x                                       0xDFD780
#define pinstCStoryWnd_x                                           0xDFD4CC
#define pinstCTargetOfTargetWnd_x                                  0xF796E8
#define pinstCTargetWnd_x                                          0xDFD430
#define pinstCTaskOverlayWnd_x                                     0xDFD794
#define pinstCTaskSelectWnd_x                                      0xF79840
#define pinstCTaskManager_x                                        0xCCEAB8
#define pinstCTaskTemplateSelectWnd_x                              0xF798F0
#define pinstCTaskWnd_x                                            0xF799A0
#define pinstCTextEntryWnd_x                                       0xDFD018
#define pinstCTimeLeftWnd_x                                        0xDFD484
#define pinstCTipWndCONTEXT_x                                      0xF79BA4
#define pinstCTipWndOFDAY_x                                        0xF79BA0
#define pinstCTitleWnd_x                                           0xF79C50
#define pinstCTrackingWnd_x                                        0xDFCF40
#define pinstCTradeskillWnd_x                                      0xF79DB8
#define pinstCTradeWnd_x                                           0xDFD50C
#define pinstCTrainWnd_x                                           0xDFD504
#define pinstCTributeBenefitWnd_x                                  0xF79FB8
#define pinstCTributeMasterWnd_x                                   0xF7A068
#define pinstCTributeTrophyWnd_x                                   0xF7A118
#define pinstCVideoModesWnd_x                                      0xDFD514
#define pinstCVoiceMacroWnd_x                                      0xF63410
#define pinstCVoteResultsWnd_x                                     0xDFD4A4
#define pinstCVoteWnd_x                                            0xDFD494
#define pinstCWebManager_x                                         0xF63A8C
#define pinstCZoneGuideWnd_x                                       0xDFD79C
#define pinstCZonePathWnd_x                                        0xDFD7AC

#define pinstEQSuiteTextureLoader_x                                0xC9C078
#define pinstItemIconCache_x                                       0xF72F78
#define pinstLootFiltersManager_x                                  0xCCE228
#define pinstRewardSelectionWnd_x                                  0xF78008

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5AC980
#define __CastRay2_x                                               0x5AC9D0
#define __ConvertItemTags_x                                        0x5C8510
#define __CleanItemTags_x                                          0x47D120
#define __DoesFileExist_x                                          0x900F50
#define __EQGetTime_x                                              0x8FD990
#define __ExecuteCmd_x                                             0x5A51E0
#define __FixHeading_x                                             0x999280
#define __GameLoop_x                                               0x6B8F70
#define __get_bearing_x                                            0x5AC4F0
#define __get_melee_range_x                                        0x5ACBC0
#define __GetAnimationCache_x                                      0x71E0A0
#define __GetGaugeValueFromEQ_x                                    0x810860
#define __GetLabelFromEQ_x                                         0x812340
#define __GetXTargetType_x                                         0x99AC60
#define __HandleMouseWheel_x                                       0x6B9E30
#define __HeadingDiff_x                                            0x9992F0
#define __HelpPath_x                                               0xF5E7B4
#define __LoadFrontEnd_x                                           0x6B6290
#define __NewUIINI_x                                               0x810530
#define __ProcessGameEvents_x                                      0x60CAE0
#define __ProcessMouseEvent_x                                      0x60C2A0
#define __SaveColors_x                                             0x54F570
#define __STMLToText_x                                             0x93C480
#define __ToggleKeyRingItem_x                                      0x512EC0
#define CMemoryMappedFile__SetFile_x                               0xA88440
#define CrashDetected_x                                            0x6B7D30
#define DrawNetStatus_x                                            0x6385C0
#define Expansion_HoT_x                                            0xEC0704
#define Teleport_Table_Size_x                                      0xEAF640
#define Teleport_Table_x                                           0xEAFB10
#define Util__FastTime_x                                           0x8FD560

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490370
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499280
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499050
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493910
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492D60

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x557050
#define AltAdvManager__IsAbilityReady_x                            0x555F80
#define AltAdvManager__GetAAById_x                                 0x556180
#define AltAdvManager__CanTrainAbility_x                           0x5561F0
#define AltAdvManager__CanSeeAbility_x                             0x556550

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA190
#define CharacterZoneClient__HasSkill_x                            0x4D5080
#define CharacterZoneClient__MakeMeVisible_x                       0x4D67A0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE4B0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BAAB0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9140
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9220
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9300
#define CharacterZoneClient__FindAffectSlot_x                      0x4C32A0
#define CharacterZoneClient__BardCastBard_x                        0x4C5E00
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAB80
#define CharacterZoneClient__GetEffect_x                           0x4BA9F0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C42F0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C43C0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C4410
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4560
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4730
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2960
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7700
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7180

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6DF900
#define CBankWnd__WndNotification_x                                0x6DF6E0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6ED0E0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x61B150
#define CButtonWnd__CButtonWnd_x                                   0x938830

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x70D240
#define CChatManager__InitContextMenu_x                            0x7063A0
#define CChatManager__FreeChatWindow_x                             0x70BD80
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E87F0
#define CChatManager__SetLockedActiveChatWindow_x                  0x70CEC0
#define CChatManager__CreateChatWindow_x                           0x70C3C0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8900

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x94CEA0
#define CContextMenu__dCContextMenu_x                              0x94D0D0
#define CContextMenu__AddMenuItem_x                                0x94D0E0
#define CContextMenu__RemoveMenuItem_x                             0x94D3F0
#define CContextMenu__RemoveAllMenuItems_x                         0x94D410
#define CContextMenu__CheckMenuItem_x                              0x94D490
#define CContextMenu__SetMenuItem_x                                0x94D310
#define CContextMenu__AddSeparator_x                               0x94D270

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x94DA30
#define CContextMenuManager__RemoveMenu_x                          0x94DAA0
#define CContextMenuManager__PopupMenu_x                           0x94DB60
#define CContextMenuManager__Flush_x                               0x94D9D0
#define CContextMenuManager__GetMenu_x                             0x49B440
#define CContextMenuManager__CreateDefaultMenu_x                   0x7188A0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D9CB0
#define CChatService__GetFriendName_x                              0x8D9CC0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x70DAC0
#define CChatWindow__Clear_x                                       0x70ED80
#define CChatWindow__WndNotification_x                             0x70F510
#define CChatWindow__AddHistory_x                                  0x70E640

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x94A300
#define CComboWnd__Draw_x                                          0x9497F0
#define CComboWnd__GetCurChoice_x                                  0x94A140
#define CComboWnd__GetListRect_x                                   0x949CB0
#define CComboWnd__GetTextRect_x                                   0x94A370
#define CComboWnd__InsertChoice_x                                  0x949E40
#define CComboWnd__SetColors_x                                     0x949E10
#define CComboWnd__SetChoice_x                                     0x94A110
#define CComboWnd__GetItemCount_x                                  0x94A150
#define CComboWnd__GetCurChoiceText_x                              0x94A190
#define CComboWnd__GetChoiceText_x                                 0x94A160
#define CComboWnd__InsertChoiceAtIndex_x                           0x949ED0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x7162A0
#define CContainerWnd__vftable_x                                   0xB0F0EC
#define CContainerWnd__SetContainer_x                              0x717800

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x549FB0
#define CDisplay__PreZoneMainUI_x                                  0x549FC0
#define CDisplay__CleanGameUI_x                                    0x54F330
#define CDisplay__GetClickedActor_x                                0x5422D0
#define CDisplay__GetUserDefinedColor_x                            0x53A990
#define CDisplay__GetWorldFilePath_x                               0x543D40
#define CDisplay__is3dON_x                                         0x53EF30
#define CDisplay__ReloadUI_x                                       0x549440
#define CDisplay__WriteTextHD2_x                                   0x53ED20
#define CDisplay__TrueDistance_x                                   0x545A00
#define CDisplay__SetViewActor_x                                   0x541BF0
#define CDisplay__GetFloorHeight_x                                 0x53EFF0
#define CDisplay__SetRenderWindow_x                                0x53D950
#define CDisplay__ToggleScreenshotMode_x                           0x5416C0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x96CB50

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x950410
#define CEditWnd__GetCharIndexPt_x                                 0x951340
#define CEditWnd__GetDisplayString_x                               0x9511E0
#define CEditWnd__GetHorzOffset_x                                  0x94FA40
#define CEditWnd__GetLineForPrintableChar_x                        0x9524E0
#define CEditWnd__GetSelStartPt_x                                  0x9515F0
#define CEditWnd__GetSTMLSafeText_x                                0x951000
#define CEditWnd__PointFromPrintableChar_x                         0x952110
#define CEditWnd__SelectableCharFromPoint_x                        0x952280
#define CEditWnd__SetEditable_x                                    0x9516C0
#define CEditWnd__SetWindowTextA_x                                 0x950D80

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5FA740
#define CEverQuest__ClickedPlayer_x                                0x5EC750
#define CEverQuest__CreateTargetIndicator_x                        0x609D70
#define CEverQuest__DeleteTargetIndicator_x                        0x609E00
#define CEverQuest__DoTellWindow_x                                 0x4E89E0
#define CEverQuest__OutputTextToLog_x                              0x4E8C60
#define CEverQuest__DropHeldItemOnGround_x                         0x5E1790
#define CEverQuest__dsp_chat_x                                     0x4E8FF0
#define CEverQuest__trimName_x                                     0x606050
#define CEverQuest__Emote_x                                        0x5FAFA0
#define CEverQuest__EnterZone_x                                    0x5F4F20
#define CEverQuest__GetBodyTypeDesc_x                              0x5FF910
#define CEverQuest__GetClassDesc_x                                 0x5FFF50
#define CEverQuest__GetClassThreeLetterCode_x                      0x600550
#define CEverQuest__GetDeityDesc_x                                 0x6086B0
#define CEverQuest__GetLangDesc_x                                  0x600710
#define CEverQuest__GetRaceDesc_x                                  0x5FFF30
#define CEverQuest__InterpretCmd_x                                 0x608C80
#define CEverQuest__LeftClickedOnPlayer_x                          0x5E5990
#define CEverQuest__LMouseUp_x                                     0x5E3D20
#define CEverQuest__RightClickedOnPlayer_x                         0x5E6270
#define CEverQuest__RMouseUp_x                                     0x5E4CA0
#define CEverQuest__SetGameState_x                                 0x5E1520
#define CEverQuest__UPCNotificationFlush_x                         0x605F50
#define CEverQuest__IssuePetCommand_x                              0x601B10
#define CEverQuest__ReportSuccessfulHit_x                          0x5FC390

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7281F0
#define CGaugeWnd__CalcLinesFillRect_x                             0x728250
#define CGaugeWnd__Draw_x                                          0x727870

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF380
#define CGuild__GetGuildName_x                                     0x4AE460
#define CGuild__GetGuildIndex_x                                    0x4AE7F0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x743620

//CHotButton
#define CHotButton__SetButtonSize_x                                0x61B510

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x750640
#define CInvSlotMgr__MoveItem_x                                    0x74F360
#define CInvSlotMgr__SelectSlot_x                                  0x750710

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x74DBC0
#define CInvSlot__SliderComplete_x                                 0x74B920
#define CInvSlot__GetItemBase_x                                    0x74B2A0
#define CInvSlot__UpdateItem_x                                     0x74B410

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x752190
#define CInvSlotWnd__CInvSlotWnd_x                                 0x751330
#define CInvSlotWnd__HandleLButtonUp_x                             0x751D10

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x80BB80
#define CItemDisplayWnd__UpdateStrings_x                           0x760870
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75A540
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x75AA70
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x760E80
#define CItemDisplayWnd__AboutToShow_x                             0x7604B0
#define CItemDisplayWnd__WndNotification_x                         0x761F70
#define CItemDisplayWnd__RequestConvertItem_x                      0x761A30
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x75F510
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x7602D0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x844540

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x7664B0

// CLabel 
#define CLabel__Draw_x                                             0x76BF00

// CListWnd
#define CListWnd__CListWnd_x                                       0x922A50
#define CListWnd__dCListWnd_x                                      0x922D70
#define CListWnd__AddColumn_x                                      0x9271F0
#define CListWnd__AddColumn1_x                                     0x927240
#define CListWnd__AddLine_x                                        0x9275D0
#define CListWnd__AddString_x                                      0x9273D0
#define CListWnd__CalculateFirstVisibleLine_x                      0x926FB0
#define CListWnd__CalculateVSBRange_x                              0x926DA0
#define CListWnd__ClearSel_x                                       0x927DB0
#define CListWnd__ClearAllSel_x                                    0x927E10
#define CListWnd__CloseAndUpdateEditWindow_x                       0x928830
#define CListWnd__Compare_x                                        0x9266D0
#define CListWnd__Draw_x                                           0x922EA0
#define CListWnd__DrawColumnSeparators_x                           0x9256A0
#define CListWnd__DrawHeader_x                                     0x925B10
#define CListWnd__DrawItem_x                                       0x926010
#define CListWnd__DrawLine_x                                       0x925810
#define CListWnd__DrawSeparator_x                                  0x925740
#define CListWnd__EnableLine_x                                     0x924F70
#define CListWnd__EnsureVisible_x                                  0x928750
#define CListWnd__ExtendSel_x                                      0x927CE0
#define CListWnd__GetColumnTooltip_x                               0x924AB0
#define CListWnd__GetColumnMinWidth_x                              0x924B20
#define CListWnd__GetColumnWidth_x                                 0x924A20
#define CListWnd__GetCurSel_x                                      0x9243B0
#define CListWnd__GetItemAtPoint_x                                 0x9251F0
#define CListWnd__GetItemAtPoint1_x                                0x925260
#define CListWnd__GetItemData_x                                    0x924430
#define CListWnd__GetItemHeight_x                                  0x9247F0
#define CListWnd__GetItemIcon_x                                    0x9245C0
#define CListWnd__GetItemRect_x                                    0x925060
#define CListWnd__GetItemText_x                                    0x924470
#define CListWnd__GetSelList_x                                     0x927E60
#define CListWnd__GetSeparatorRect_x                               0x9254A0
#define CListWnd__InsertLine_x                                     0x9279C0
#define CListWnd__RemoveLine_x                                     0x927B10
#define CListWnd__SetColors_x                                      0x926D70
#define CListWnd__SetColumnJustification_x                         0x926AA0
#define CListWnd__SetColumnWidth_x                                 0x9269C0
#define CListWnd__SetCurSel_x                                      0x927C20
#define CListWnd__SetItemColor_x                                   0x928400
#define CListWnd__SetItemData_x                                    0x9283C0
#define CListWnd__SetItemText_x                                    0x927FD0
#define CListWnd__ShiftColumnSeparator_x                           0x926B60
#define CListWnd__Sort_x                                           0x926850
#define CListWnd__ToggleSel_x                                      0x927C50
#define CListWnd__SetColumnsSizable_x                              0x926C10
#define CListWnd__SetItemWnd_x                                     0x928280
#define CListWnd__GetItemWnd_x                                     0x924610
#define CListWnd__SetItemIcon_x                                    0x928050
#define CListWnd__CalculateCustomWindowPositions_x                 0x9270B0
#define CListWnd__SetVScrollPos_x                                  0x9269A0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x781680
#define CMapViewWnd__GetWorldCoordinates_x                         0x77FD90
#define CMapViewWnd__HandleLButtonDown_x                           0x77CDD0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A1750
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A2030
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A2560
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A54E0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A02D0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7AB090
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A1370

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8A7650
#define CPacketScrambler__hton_x                                   0x8A7640

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x941AD0
#define CSidlManager__FindScreenPieceTemplate_x                    0x941EE0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x941CD0
#define CSidlManager__CreateLabel_x                                0x803060
#define CSidlManager__CreateXWndFromTemplate_x                     0x944E40
#define CSidlManager__CreateXWndFromTemplate1_x                    0x945010
#define CSidlManager__CreateXWnd_x                                 0x802F90
#define CSidlManager__CreateHotButtonWnd_x                         0x803530

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x93E590
#define CSidlScreenWnd__CalculateVSBRange_x                        0x93E490
#define CSidlScreenWnd__ConvertToRes_x                             0x963B00
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x93DF30
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x93DC20
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x93DCF0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x93DDC0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x93EA30
#define CSidlScreenWnd__EnableIniStorage_x                         0x93EF00
#define CSidlScreenWnd__GetSidlPiece_x                             0x93EC20
#define CSidlScreenWnd__Init1_x                                    0x93D820
#define CSidlScreenWnd__LoadIniInfo_x                              0x93EF50
#define CSidlScreenWnd__LoadIniListWnd_x                           0x93FAB0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x93CC30
#define CSidlScreenWnd__StoreIniInfo_x                             0x93F620
#define CSidlScreenWnd__StoreIniVis_x                              0x93F990
#define CSidlScreenWnd__WndNotification_x                          0x93E940
#define CSidlScreenWnd__GetChildItem_x                             0x93EE80
#define CSidlScreenWnd__HandleLButtonUp_x                          0x92E5E0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15F4F28

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x67FD10
#define CSkillMgr__GetSkillCap_x                                   0x67FEF0
#define CSkillMgr__GetNameToken_x                                  0x67F490
#define CSkillMgr__IsActivatedSkill_x                              0x67F5D0
#define CSkillMgr__IsCombatSkill_x                                 0x67F510

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x94E820
#define CSliderWnd__SetValue_x                                     0x94E690
#define CSliderWnd__SetNumTicks_x                                  0x94E6F0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x809010

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x957020
#define CStmlWnd__CalculateHSBRange_x                              0x958150
#define CStmlWnd__CalculateVSBRange_x                              0x9580C0
#define CStmlWnd__CanBreakAtCharacter_x                            0x95C470
#define CStmlWnd__FastForwardToEndOfTag_x                          0x95D100
#define CStmlWnd__ForceParseNow_x                                  0x957610
#define CStmlWnd__GetNextTagPiece_x                                0x95C3D0
#define CStmlWnd__GetSTMLText_x                                    0x502520
#define CStmlWnd__GetVisibleText_x                                 0x957630
#define CStmlWnd__InitializeWindowVariables_x                      0x95CF50
#define CStmlWnd__MakeStmlColorTag_x                               0x956690
#define CStmlWnd__MakeWndNotificationTag_x                         0x956700
#define CStmlWnd__SetSTMLText_x                                    0x955740
#define CStmlWnd__StripFirstSTMLLines_x                            0x95E200
#define CStmlWnd__UpdateHistoryString_x                            0x95D310

// CTabWnd 
#define CTabWnd__Draw_x                                            0x954890
#define CTabWnd__DrawCurrentPage_x                                 0x954FC0
#define CTabWnd__DrawTab_x                                         0x954CE0
#define CTabWnd__GetCurrentPage_x                                  0x9540A0
#define CTabWnd__GetPageInnerRect_x                                0x9542E0
#define CTabWnd__GetTabInnerRect_x                                 0x954220
#define CTabWnd__GetTabRect_x                                      0x9540D0
#define CTabWnd__InsertPage_x                                      0x9544F0
#define CTabWnd__SetPage_x                                         0x954360
#define CTabWnd__SetPageRect_x                                     0x9547D0
#define CTabWnd__UpdatePage_x                                      0x954BA0
#define CTabWnd__GetPageFromTabIndex_x                             0x954C20
#define CTabWnd__GetCurrentTabIndex_x                              0x954090

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x766880
#define CPageWnd__SetTabText_x                                     0x953BF0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9070

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x92B4A0
#define CTextureFont__GetTextExtent_x                              0x92B660

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B3160
#define CHtmlComponentWnd__ValidateUri_x                           0x745010
#define CHtmlWnd__SetClientCallbacks_x                             0x620580
#define CHtmlWnd__AddObserver_x                                    0x6205A0
#define CHtmlWnd__RemoveObserver_x                                 0x620600
#define Window__getProgress_x                                      0x85CE40
#define Window__getStatus_x                                        0x85CE60
#define Window__getURI_x                                           0x85CE70

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9695A0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x918620

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8530
#define CXStr__CXStr1_x                                            0x4FD6B0
#define CXStr__CXStr3_x                                            0x8F9A90
#define CXStr__dCXStr_x                                            0x478780
#define CXStr__operator_equal_x                                    0x8F9CC0
#define CXStr__operator_equal1_x                                   0x8F9D00
#define CXStr__operator_plus_equal1_x                              0x8FA790
#define CXStr__SetString_x                                         0x8FC680
#define CXStr__operator_char_p_x                                   0x8FA200
#define CXStr__GetChar_x                                           0x8FBFB0
#define CXStr__Delete_x                                            0x8FB880
#define CXStr__GetUnicode_x                                        0x8FC020
#define CXStr__GetLength_x                                         0x47D4D0
#define CXStr__Mid_x                                               0x47D4E0
#define CXStr__Insert_x                                            0x8FC080
#define CXStr__FindNext_x                                          0x8FBCF0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x94CAB0
#define CXWnd__BringToTop_x                                        0x931D40
#define CXWnd__Center_x                                            0x9318C0
#define CXWnd__ClrFocus_x                                          0x9316D0
#define CXWnd__Destroy_x                                           0x931780
#define CXWnd__DoAllDrawing_x                                      0x92DD80
#define CXWnd__DrawChildren_x                                      0x92DD50
#define CXWnd__DrawColoredRect_x                                   0x92E1D0
#define CXWnd__DrawTooltip_x                                       0x92C8A0
#define CXWnd__DrawTooltipAtPoint_x                                0x92C960
#define CXWnd__GetBorderFrame_x                                    0x92E030
#define CXWnd__GetChildWndAt_x                                     0x931DE0
#define CXWnd__GetClientClipRect_x                                 0x92FFE0
#define CXWnd__GetScreenClipRect_x                                 0x9300B0
#define CXWnd__GetScreenRect_x                                     0x930280
#define CXWnd__GetTooltipRect_x                                    0x92E220
#define CXWnd__GetWindowTextA_x                                    0x49CB20
#define CXWnd__IsActive_x                                          0x92E950
#define CXWnd__IsDescendantOf_x                                    0x930C30
#define CXWnd__IsReallyVisible_x                                   0x930C60
#define CXWnd__IsType_x                                            0x932440
#define CXWnd__Move_x                                              0x930CD0
#define CXWnd__Move1_x                                             0x930D80
#define CXWnd__ProcessTransition_x                                 0x931870
#define CXWnd__Refade_x                                            0x931050
#define CXWnd__Resize_x                                            0x9312E0
#define CXWnd__Right_x                                             0x931B00
#define CXWnd__SetFocus_x                                          0x931690
#define CXWnd__SetFont_x                                           0x931700
#define CXWnd__SetKeyTooltip_x                                     0x932270
#define CXWnd__SetMouseOver_x                                      0x92F180
#define CXWnd__StartFade_x                                         0x930B10
#define CXWnd__GetChildItem_x                                      0x931F50
#define CXWnd__SetParent_x                                         0x930A10
#define CXWnd__Minimize_x                                          0x931350

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x964B80

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x934CF0
#define CXWndManager__DrawWindows_x                                0x934D10
#define CXWndManager__GetKeyboardFlags_x                           0x9374C0
#define CXWndManager__HandleKeyboardMsg_x                          0x937080
#define CXWndManager__RemoveWnd_x                                  0x937710
#define CXWndManager__RemovePendingDeletionWnd_x                   0x937C60

// CDBStr
#define CDBStr__GetString_x                                        0x539950

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BBA90
#define EQ_Character__Cur_HP_x                                     0x4D20C0
#define EQ_Character__Cur_Mana_x                                   0x4D9800
#define EQ_Character__GetCastingTimeModifier_x                     0x4BEB00
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B25A0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B26F0
#define EQ_Character__GetHPRegen_x                                 0x4DF5D0
#define EQ_Character__GetEnduranceRegen_x                          0x4DFBD0
#define EQ_Character__GetManaRegen_x                               0x4E0010
#define EQ_Character__Max_Endurance_x                              0x646820
#define EQ_Character__Max_HP_x                                     0x4D1EF0
#define EQ_Character__Max_Mana_x                                   0x646620
#define EQ_Character__doCombatAbility_x                            0x648C70
#define EQ_Character__UseSkill_x                                   0x4E1DE0
#define EQ_Character__GetConLevel_x                                0x63F550
#define EQ_Character__IsExpansionFlag_x                            0x5A39B0
#define EQ_Character__TotalEffect_x                                0x4C5540
#define EQ_Character__GetPCSpellAffect_x                           0x4BF850
#define EQ_Character__SpellDuration_x                              0x4BF380
#define EQ_Character__GetAdjustedSkill_x                           0x4D4E40
#define EQ_Character__GetBaseSkill_x                               0x4D5DE0
#define EQ_Character__CanUseItem_x                                 0x4D9B10

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8C6C30

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x65CD90

//PcClient
#define PcClient__PcClient_x                                       0x63CC90

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B9700
#define CCharacterListWnd__EnterWorld_x                            0x4B9140
#define CCharacterListWnd__Quit_x                                  0x4B8E90
#define CCharacterListWnd__UpdateList_x                            0x4B92D0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6217B0
#define EQ_Item__CreateItemTagString_x                             0x8A0E70
#define EQ_Item__IsStackable_x                                     0x8A5A20
#define EQ_Item__GetImageNum_x                                     0x8A28F0
#define EQ_Item__CreateItemClient_x                                0x620980
#define EQ_Item__GetItemValue_x                                    0x8A3C10
#define EQ_Item__ValueSellMerchant_x                               0x8A7230
#define EQ_Item__IsKeyRingItem_x                                   0x8A5350
#define EQ_Item__CanGoInBag_x                                      0x6218D0
#define EQ_Item__IsEmpty_x                                         0x8A4E80
#define EQ_Item__GetMaxItemCount_x                                 0x8A4020
#define EQ_Item__GetHeldItem_x                                     0x8A27C0
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A07E0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x557D60
#define EQ_LoadingS__Array_x                                       0xC23B58

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x647180
#define EQ_PC__GetAlternateAbilityId_x                             0x8B0400
#define EQ_PC__GetCombatAbility_x                                  0x8B0A70
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B0AE0
#define EQ_PC__GetItemRecastTimer_x                                0x6491F0
#define EQ_PC__HasLoreItem_x                                       0x63FD60
#define EQ_PC__AlertInventoryChanged_x                             0x63EE90
#define EQ_PC__GetPcZoneClient_x                                   0x66B940
#define EQ_PC__RemoveMyAffect_x                                    0x64C420
#define EQ_PC__GetKeyRingItems_x                                   0x8B1370
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B1100
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B1670

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5A9F10
#define EQItemList__add_object_x                                   0x5D6F60
#define EQItemList__add_item_x                                     0x5AA470
#define EQItemList__delete_item_x                                  0x5AA4C0
#define EQItemList__FreeItemList_x                                 0x5AA3C0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x536470

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x65E610
#define EQPlayer__dEQPlayer_x                                      0x651950
#define EQPlayer__DoAttack_x                                       0x666600
#define EQPlayer__EQPlayer_x                                       0x652010
#define EQPlayer__SetNameSpriteState_x                             0x6562F0
#define EQPlayer__SetNameSpriteTint_x                              0x6571C0
#define PlayerBase__HasProperty_j_x                                0x997600
#define EQPlayer__IsTargetable_x                                   0x997AA0
#define EQPlayer__CanSee_x                                         0x997900
#define EQPlayer__CanSee1_x                                        0x9979D0
#define PlayerBase__GetVisibilityLineSegment_x                     0x9976C0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x6693E0
#define PlayerZoneClient__GetLevel_x                               0x66B980
#define PlayerZoneClient__IsValidTeleport_x                        0x5D80D0
#define PlayerZoneClient__LegalPlayerRace_x                        0x551160

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x661400
#define EQPlayerManager__GetSpawnByName_x                          0x6614B0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x661540

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x624DE0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x624E60
#define KeypressHandler__AttachKeyToEqCommand_x                    0x624EA0
#define KeypressHandler__ClearCommandStateArray_x                  0x6262B0
#define KeypressHandler__HandleKeyDown_x                           0x6262D0
#define KeypressHandler__HandleKeyUp_x                             0x626370
#define KeypressHandler__SaveKeymapping_x                          0x6267C0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x77D4F0
#define MapViewMap__SaveEx_x                                       0x7808B0
#define MapViewMap__SetZoom_x                                      0x784F70

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C4AA0

// StringTable 
#define StringTable__getString_x                                   0x8BF6A0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x64C090
#define PcZoneClient__RemovePetEffect_x                            0x64C6C0
#define PcZoneClient__HasAlternateAbility_x                        0x646450
#define PcZoneClient__GetCurrentMod_x                              0x4E4EA0
#define PcZoneClient__GetModCap_x                                  0x4E4DA0
#define PcZoneClient__CanEquipItem_x                               0x646B20
#define PcZoneClient__GetItemByID_x                                0x649660
#define PcZoneClient__GetItemByItemClass_x                         0x6497B0
#define PcZoneClient__RemoveBuffEffect_x                           0x64C6E0
#define PcZoneClient__BandolierSwap_x                              0x647730
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x649190

//Doors
#define EQSwitch__UseSwitch_x                                      0x5DCBF0

//IconCache
#define IconCache__GetIcon_x                                       0x71D940

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x715440
#define CContainerMgr__CloseContainer_x                            0x715710
#define CContainerMgr__OpenExperimentContainer_x                   0x716190

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D5570

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x619920

//CLootWnd
#define CLootWnd__LootAll_x                                        0x773A00
#define CLootWnd__RequestLootSlot_x                                0x772C30

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x576B50
#define EQ_Spell__SpellAffects_x                                   0x576FC0
#define EQ_Spell__SpellAffectBase_x                                0x576D80
#define EQ_Spell__IsStackable_x                                    0x4C9AF0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C99A0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6A50
#define EQ_Spell__IsSPAStacking_x                                  0x577E10
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x577320
#define EQ_Spell__IsNoRemove_x                                     0x4C9AD0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x577E20
#define __IsResEffectSpell_x                                       0x4C8F80

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD0C0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8CF190

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x81C2D0
#define CTargetWnd__WndNotification_x                              0x81BB60
#define CTargetWnd__RefreshTargetBuffs_x                           0x81BE30
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x81ACD0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x8208E0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x533E80
#define CTaskManager__HandleMessage_x                              0x532330
#define CTaskManager__GetTaskStatus_x                              0x533F30
#define CTaskManager__GetElementDescription_x                      0x533FB0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5720B0
#define EqSoundManager__PlayScriptMp3_x                            0x572210
#define EqSoundManager__SoundAssistPlay_x                          0x683C30
#define EqSoundManager__WaveInstancePlay_x                         0x6831A0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x527BF0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x953100

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x55F7A0
#define CAltAbilityData__GetMercMaxRank_x                          0x55F730
#define CAltAbilityData__GetMaxRank_x                              0x554E00

//CTargetRing
#define CTargetRing__Cast_x                                        0x617A40

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9980
#define CharacterBase__CreateItemGlobalIndex_x                     0x50F570
#define CharacterBase__CreateItemIndex_x                           0x61FB30
#define CharacterBase__GetItemPossession_x                         0x4FAFD0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8D7780
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8D77E0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6FC630
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6FCE60
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6FCF10

//messages
#define msg_spell_worn_off_x                                       0x59BB80
#define msg_new_text_x                                             0x590910
#define __msgTokenTextParam_x                                      0x59E0B0
#define msgTokenText_x                                             0x59E300

//SpellManager
#define SpellManager__vftable_x                                    0xAE921C
#define SpellManager__SpellManager_x                               0x686F60
#define Spellmanager__LoadTextSpells_x                             0x687850
#define SpellManager__GetSpellByGroupAndRank_x                     0x687130

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x99B550

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x50FBC0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A1E90
#define ItemGlobalIndex__IsEquippedLocation_x                      0x638420
#define ItemGlobalIndex__IsValidIndex_x                            0x50FC20

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8CFB30
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8CFDB0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x76C240

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x719B40
#define CCursorAttachment__AttachToCursor1_x                       0x719B80
#define CCursorAttachment__Deactivate_x                            0x71AB70

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x945E20
#define CSidlManagerBase__CreatePageWnd_x                          0x945640
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x9418F0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x941880

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x962E00
#define CEQSuiteTextureLoader__GetTexture_x                        0x962AC0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50CB30
#define CFindItemWnd__WndNotification_x                            0x50D610
#define CFindItemWnd__Update_x                                     0x50E150
#define CFindItemWnd__PickupSelectedItem_x                         0x50C370

//IString
#define IString__Append_x                                          0x4FC7C0

//Camera
#define CDisplay__cameraType_x                                     0xDFD51C
#define EverQuest__Cameras_x                                       0xEC0A54

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x515250
#define LootFiltersManager__GetItemFilterData_x                    0x514B60
#define LootFiltersManager__RemoveItemLootFilter_x                 0x514B90
#define LootFiltersManager__SetItemLootFilter_x                    0x514DB0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C3510

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A1090
#define CResolutionHandler__GetWindowedStyle_x                     0x67E7D0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x712210

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E3EC0
#define CDistillerInfo__Instance_x                                 0x8E3E60

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x732430
#define CGroupWnd__UpdateDisplay_x                                 0x731790

//ItemBase
#define ItemBase__IsLore_x                                         0x8A53F0
#define ItemBase__IsLoreEquipped_x                                 0x8A5460

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5D6EC0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5D7000
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5D7060

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6740F0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x677A50

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x502ED0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F1880
#define FactionManagerClient__HandleFactionMessage_x               0x4F1EF0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F24F0
#define FactionManagerClient__GetMaxFaction_x                      0x4F250F
#define FactionManagerClient__GetMinFaction_x                      0x4F24C0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FAFA0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x92A4F0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BE30

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FB1D0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x55EC40

//CTargetManager
#define CTargetManager__Get_x                                      0x68A7B0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6740F0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8E30

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5AA360

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF5E0E8

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
