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
#define __ExpectedVersionDate                                     "Jun 22 2018"
#define __ExpectedVersionTime                                     "10:54:39"
#define __ActualVersionDate_x                                      0xABD2EC
#define __ActualVersionTime_x                                      0xABD2E0

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x607C70
#define __MemChecker1_x                                            0x8D8FB0
#define __MemChecker2_x                                            0x696020
#define __MemChecker3_x                                            0x695F70
#define __MemChecker4_x                                            0x832820
#define __EncryptPad0_x                                            0xBEF490
#define __EncryptPad1_x                                            0xC4D170
#define __EncryptPad2_x                                            0xC00018
#define __EncryptPad3_x                                            0xBFFC18
#define __EncryptPad4_x                                            0xC3DF08
#define __EncryptPad5_x                                            0xF0AB64
#define __AC1_x                                                    0x7EEF76
#define __AC2_x                                                    0x5C35AF
#define __AC3_x                                                    0x5CA42F
#define __AC4_x                                                    0x5CE2B0
#define __AC5_x                                                    0x5D44E0
#define __AC6_x                                                    0x5D8A22
#define __AC7_x                                                    0x5C3020
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x195BC8

// Direct Input
#define DI8__Main_x                                                0xF0AB88
#define DI8__Keyboard_x                                            0xF0AB8C
#define DI8__Mouse_x                                               0xF0AB50
#define DI8__Mouse_Copy_x                                          0xE688DC
#define DI8__Mouse_Check_x                                         0xF0BA50
#define __AutoSkillArray_x                                         0xE697EC
#define __Attack_x                                                 0xF075CB
#define __Autofire_x                                               0xF075CC
#define __BindList_x                                               0xBDE088
#define g_eqCommandStates_x                                        0xBDEDF8
#define __Clicks_x                                                 0xE68994
#define __CommandList_x                                            0xBDF9B0
#define __CurrentMapLabel_x                                        0x101D174
#define __CurrentSocial_x                                          0xBC9710
#define __DoAbilityList_x                                          0xE9F0EC
#define __do_loot_x                                                0x590E00
#define __DrawHandler_x                                            0x1698680
#define __GroupCount_x                                             0xE5B27A
#define __Guilds_x                                                 0xE5F0E8
#define __gWorld_x                                                 0xE590DC
#define __HWnd_x                                                   0xF0AB58
#define __heqmain_x                                                0x1015DAC
#define __InChatMode_x                                             0xE688C4
#define __LastTell_x                                               0xE6A7E8
#define __LMouseHeldTime_x                                         0xE68A00
#define __Mouse_x                                                  0xF0AB70
#define __MouseLook_x                                              0xE6895A
#define __MouseEventTime_x                                         0xF08080
#define __gpbCommandEvent_x                                        0xE58C00
#define __NetStatusToggle_x                                        0xE6895D
#define __PCNames_x                                                0xE69DA8
#define __RangeAttackReady_x                                       0xE69AD0
#define __RMouseHeldTime_x                                         0xE689FC
#define __RunWalkState_x                                           0xE688C8
#define __ScreenMode_x                                             0xDA7440
#define __ScreenX_x                                                0xE6887C
#define __ScreenY_x                                                0xE68878
#define __ScreenXMax_x                                             0xE68880
#define __ScreenYMax_x                                             0xE68884
#define __ServerHost_x                                             0xE58DCB
#define __ServerName_x                                             0xE9F0AC
#define __ShiftKeyDown_x                                           0xE68F54
#define __ShowNames_x                                              0xE69C88
#define __Socials_x                                                0xE9F1AC
#define __SubscriptionType_x                                       0x105EC3C
#define __TargetAggroHolder_x                                      0x101FB2C
#define __ZoneType_x                                               0xE68D58
#define __GroupAggro_x                                             0x101FB6C
#define __LoginName_x                                              0xF0B4E4
#define __Inviter_x                                                0xF07548
#define __AttackOnAssist_x                                         0xE69C44
#define __UseTellWindows_x                                         0xE69F40
#define __gfMaxZoomCameraDistance_x                                0xAB2B10
#define __gfMaxCameraDistance_x                                    0xADFC24
#define __pulAutoRun_x                                             0xE68978
#define __pulForward_x                                             0xE69F78
#define __pulBackward_x                                            0xE69F7C
#define __pulTurnRight_x                                           0xE69F80
#define __pulTurnLeft_x                                            0xE69F84
#define __pulStrafeLeft_x                                          0xE69F88
#define __pulStrafeRight_x                                         0xE69F8C

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE5B490
#define instEQZoneInfo_x                                           0xE68B50
#define instKeypressHandler_x                                      0xF08030
#define pinstActiveBanker_x                                        0xE5B220
#define pinstActiveCorpse_x                                        0xE5B218
#define pinstActiveGMaster_x                                       0xE5B21C
#define pinstActiveMerchant_x                                      0xE5B214
#define pinstAggroInfo_x                                           0xC63838
#define pinstAltAdvManager_x                                       0xDA7E30
#define pinstAuraMgr_x                                             0xC74520
#define pinstBandageTarget_x                                       0xE5B230
#define pinstCamActor_x                                            0xDA742C
#define pinstCDBStr_x                                              0xDA6B8C
#define pinstCDisplay_x                                            0xE5B478
#define pinstCEverQuest_x                                          0xF0ACA8
#define pinstEverQuestInfo_x                                       0xE68870
#define pinstCharData_x                                            0xE5B488
#define pinstCharSpawn_x                                           0xE5B46C
#define pinstControlledMissile_x                                   0xE58B80
#define pinstControlledPlayer_x                                    0xE5B46C
#define pinstCResolutionHandler_x                                  0x16988B0
#define pinstCSidlManager_x                                        0x1697744
#define pinstCXWndManager_x                                        0x1697738
#define instDynamicZone_x                                          0xE5EFC0
#define pinstDZMember_x                                            0xE5F0D0
#define pinstDZTimerInfo_x                                         0xE5F0D4
#define pinstEQItemList_x                                          0xE57680
#define pinstEQObjectList_x                                        0xE58870
#define instEQMisc_x                                               0xDA6AC8
#define pinstEQSoundManager_x                                      0xDA8690
#define pinstEQSpellStrings_x                                      0xC71970
#define instExpeditionLeader_x                                     0xE5F00A
#define instExpeditionName_x                                       0xE5F04A
#define pinstGroup_x                                               0xE5B276
#define pinstImeManager_x                                          0x169773C
#define pinstLocalPlayer_x                                         0xE5B210
#define pinstMercenaryData_x                                       0xF08820
#define pinstMercenaryStats_x                                      0x101FC78
#define pinstMercAltAbilities_x                                    0xDA8400
#define pinstModelPlayer_x                                         0xE5B228
#define pinstPCData_x                                              0xE5B488
#define pinstRealEstateItems_x                                     0xF09D10
#define pinstSkillMgr_x                                            0xF09DE0
#define pinstSpawnManager_x                                        0xF093D0
#define pinstSpellManager_x                                        0xF09FB8
#define pinstSpellSets_x                                           0xF001F4
#define pinstStringTable_x                                         0xE5B0E4
#define pinstSwitchManager_x                                       0xE58A30
#define pinstTarget_x                                              0xE5B468
#define pinstTargetObject_x                                        0xE5B474
#define pinstTargetSwitch_x                                        0xE58B88
#define pinstTaskMember_x                                          0xDA6958
#define pinstTrackTarget_x                                         0xE5B470
#define pinstTradeTarget_x                                         0xE5B224
#define instTributeActive_x                                        0xDA6AED
#define pinstViewActor_x                                           0xDA7428
#define pinstWorldData_x                                           0xE58ED4
#define pinstZoneAddr_x                                            0xE68DF0
#define pinstPlayerPath_x                                          0xF09468
#define pinstTargetIndicator_x                                     0xF0A220
#define pinstCTargetManager_x                                      0xF0A2B8
#define EQObject_Top_x                                             0xE5B20C
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDA6C4C
#define pinstCAchievementsWnd_x                                    0xDA6EF0
#define pinstCActionsWnd_x                                         0xDA6EB0
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDA74B0
#define pinstCAdvancedLootWnd_x                                    0xDA7468
#define pinstCAdventureLeaderboardWnd_x                            0x1016948
#define pinstCAdventureRequestWnd_x                                0x10169F8
#define pinstCAdventureStatsWnd_x                                  0x1016AA8
#define pinstCAggroMeterWnd_x                                      0xDA6F18
#define pinstCAlarmWnd_x                                           0xDA6ED0
#define pinstCAlertHistoryWnd_x                                    0xDA6EA8
#define pinstCAlertStackWnd_x                                      0xDA6C38
#define pinstCAlertWnd_x                                           0xDA6C54
#define pinstCAltStorageWnd_x                                      0x1016E08
#define pinstCAudioTriggersWindow_x                                0xC63CC8
#define pinstCAuraWnd_x                                            0xDA6F14
#define pinstCAvaZoneWnd_x                                         0xDA6E90
#define pinstCBandolierWnd_x                                       0xDA6FC4
#define pinstCBankWnd_x                                            0xDA7474
#define pinstCBarterMerchantWnd_x                                  0x1018048
#define pinstCBarterSearchWnd_x                                    0x10180F8
#define pinstCBarterWnd_x                                          0x10181A8
#define pinstCBazaarConfirmationWnd_x                              0xDA6C28
#define pinstCBazaarSearchWnd_x                                    0xDA6EC0
#define pinstCBazaarWnd_x                                          0xDA6FBC
#define pinstCBlockedBuffWnd_x                                     0xDA7458
#define pinstCBlockedPetBuffWnd_x                                  0xDA7480
#define pinstCBodyTintWnd_x                                        0xDA6C64
#define pinstCBookWnd_x                                            0xDA73E4
#define pinstCBreathWnd_x                                          0xDA6C5C
#define pinstCBuffWindowNORMAL_x                                   0xDA741C
#define pinstCBuffWindowSHORT_x                                    0xDA7420
#define pinstCBugReportWnd_x                                       0xDA6C44
#define pinstCButtonWnd_x                                          0x1697930
#define pinstCCastingWnd_x                                         0xDA6C40
#define pinstCCastSpellWnd_x                                       0xDA6ED8
//#define pinstCCharacterCreationWnd_x                               0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDA6C68
#define pinstCChatWindowManager_x                                  0x1018C68
#define pinstCClaimWnd_x                                           0x1018DC0
#define pinstCColorPickerWnd_x                                     0xDA6E80
#define pinstCCombatAbilityWnd_x                                   0xDA6F20
#define pinstCCombatSkillsSelectWnd_x                              0xDA6EAC
#define pinstCCompassWnd_x                                         0xDA6C48
#define pinstCConfirmationDialog_x                                 0x101DCC0
#define pinstCContainerMgr_x                                       0xDA6FC0
#define pinstCContextMenuManager_x                                 0x16976F8
#define pinstCCursorAttachment_x                                   0xDA74B4
#define pinstCDynamicZoneWnd_x                                     0x1019388
#define pinstCEditLabelWnd_x                                       0xDA740C
#define pinstCEQMainWnd_x                                          0x10195D0
#define pinstCEventCalendarWnd_x                                   0xDA6F0C
#define pinstCExtendedTargetWnd_x                                  0xDA6F08
#define pinstCFacePick_x                                           0xDA6E8C
#define pinstCFellowshipWnd_x                                      0x10197D0
#define pinstCFileSelectionWnd_x                                   0xDA7454
#define pinstCFindItemWnd_x                                        0xDA6F28
#define pinstCFindLocationWnd_x                                    0x1019928
#define pinstCFriendsWnd_x                                         0xDA6EC4
#define pinstCGemsGameWnd_x                                        0xDA6EA4
#define pinstCGiveWnd_x                                            0xDA73D8
#define pinstCGroupSearchFiltersWnd_x                              0xDA6F30
#define pinstCGroupSearchWnd_x                                     0x1019D20
#define pinstCGroupWnd_x                                           0x1019DD0
#define pinstCGuildBankWnd_x                                       0xE69C2C
#define pinstCGuildCreationWnd_x                                   0x1019F30
#define pinstCGuildMgmtWnd_x                                       0x1019FE0
#define pinstCharacterCreation_x                                   0xDA6F1C
#define pinstCHelpWnd_x                                            0xDA6EE4
#define pinstCHeritageSelectionWnd_x                               0xDA6E98
#define pinstCHotButtonWnd_x                                       0x101C138
#define pinstCHotButtonWnd1_x                                      0x101C138
#define pinstCHotButtonWnd2_x                                      0x101C13C
#define pinstCHotButtonWnd3_x                                      0x101C140
#define pinstCHotButtonWnd4_x                                      0x101C144
#define pinstCIconSelectionWnd_x                                   0xDA748C
#define pinstCInspectWnd_x                                         0xDA7484
#define pinstCInventoryWnd_x                                       0xDA73CC
#define pinstCInvSlotMgr_x                                         0xDA6EFC
#define pinstCItemDisplayManager_x                                 0x101C6C8
#define pinstCItemExpTransferWnd_x                                 0x101C7FC
#define pinstCItemOverflowWnd_x                                    0xDA6EC8
#define pinstCJournalCatWnd_x                                      0xDA747C
//#define pinstCJournalNPCWnd_x                                      0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDA7418
#define pinstCKeyRingWnd_x                                         0xDA7438
#define pinstCLargeDialogWnd_x                                     0x101E940
#define pinstCLayoutCopyWnd_x                                      0x101CB48
#define pinstCLFGuildWnd_x                                         0x101CBF8
#define pinstCLoadskinWnd_x                                        0xDA6EBC
#define pinstCLootFiltersCopyWnd_x                                 0xC74D00
#define pinstCLootFiltersWnd_x                                     0xDA6E70
#define pinstCLootSettingsWnd_x                                    0xDA6E7C
#define pinstCLootWnd_x                                            0xDA6E78
#define pinstCMailAddressBookWnd_x                                 0xDA7490
#define pinstCMailCompositionWnd_x                                 0xDA7478
#define pinstCMailIgnoreListWnd_x                                  0xDA7494
#define pinstCMailWnd_x                                            0xDA744C
#define pinstCManageLootWnd_x                                      0xDA82A8
#define pinstCMapToolbarWnd_x                                      0xDA73D0
#define pinstCMapViewWnd_x                                         0xDA6F3C
#define pinstCMarketplaceWnd_x                                     0xDA6F34
#define pinstCMerchantWnd_x                                        0xDA6EA0
#define pinstCMIZoneSelectWnd_x                                    0x101D430
#define pinstCMusicPlayerWnd_x                                     0xDA7430
#define pinstCNameChangeMercWnd_x                                  0xDA7470
#define pinstCNameChangePetWnd_x                                   0xDA7450
#define pinstCNameChangeWnd_x                                      0xDA6F10
#define pinstCNoteWnd_x                                            0xDA6EDC
#define pinstCObjectPreviewWnd_x                                   0xDA73E0
#define pinstCOptionsWnd_x                                         0xDA73D4
#define pinstCPetInfoWnd_x                                         0xDA746C
#define pinstCPetitionQWnd_x                                       0xDA7488
//#define pinstCPlayerCustomizationWnd_x                             0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDA6C60
#define pinstCPlayerWnd_x                                          0xDA6ECC
#define pinstCPopupWndManager_x                                    0x101DCC0
#define pinstCProgressionSelectionWnd_x                            0x101DD70
#define pinstCPurchaseGroupWnd_x                                   0xDA7424
#define pinstCPurchaseWnd_x                                        0xDA7408
#define pinstCPvPLeaderboardWnd_x                                  0x101DE20
#define pinstCPvPStatsWnd_x                                        0x101DED0
#define pinstCQuantityWnd_x                                        0xDA749C
#define pinstCRaceChangeWnd_x                                      0xDA6F40
#define pinstCRaidOptionsWnd_x                                     0xDA6F38
#define pinstCRaidWnd_x                                            0xDA74A4
#define pinstCRealEstateItemsWnd_x                                 0xDA6EF8
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDA6F24
#define pinstCRealEstateManageWnd_x                                0xDA6E94
#define pinstCRealEstateNeighborhoodWnd_x                          0xDA6EB4
#define pinstCRealEstatePlotSearchWnd_x                            0xDA6ED4
#define pinstCRealEstatePurchaseWnd_x                              0xDA6EE0
#define pinstCRespawnWnd_x                                         0xDA6F2C
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDA6F04
#define pinstCSendMoneyWnd_x                                       0xDA7410
#define pinstCServerListWnd_x                                      0xDA6EF4
#define pinstCSkillsSelectWnd_x                                    0xDA6E88
#define pinstCSkillsWnd_x                                          0xDA6E74
#define pinstCSocialEditWnd_x                                      0xDA74A8
#define pinstCSocialWnd_x                                          0xDA74A0
#define pinstCSpellBookWnd_x                                       0xDA6F00
#define pinstCStoryWnd_x                                           0xDA6C3C
#define pinstCTargetOfTargetWnd_x                                  0x101FD00
#define pinstCTargetWnd_x                                          0xDA7464
#define pinstCTaskOverlayWnd_x                                     0xDA6EB8
#define pinstCTaskSelectWnd_x                                      0x101FE58
#define pinstCTaskSomething_x                                      0xC75500
#define pinstCTaskTemplateSelectWnd_x                              0x101FF08
#define pinstCTaskWnd_x                                            0x101FFB8
#define pinstCTextEntryWnd_x                                       0xDA6C50
#define pinstCTextOverlay_x                                        0xC63FD8
#define pinstCTimeLeftWnd_x                                        0xDA745C
#define pinstCTipWndCONTEXT_x                                      0x10201BC
#define pinstCTipWndOFDAY_x                                        0x10201B8
#define pinstCTitleWnd_x                                           0x1020268
#define pinstCTrackingWnd_x                                        0xDA7460
#define pinstCTradeskillWnd_x                                      0x10203D0
#define pinstCTradeWnd_x                                           0xDA6EE8
#define pinstCTrainWnd_x                                           0xDA7498
#define pinstCTributeBenefitWnd_x                                  0x10205D0
#define pinstCTributeMasterWnd_x                                   0x1020680
#define pinstCTributeTrophyWnd_x                                   0x1020730
#define pinstCVideoModesWnd_x                                      0xDA74AC
#define pinstCVoiceMacroWnd_x                                      0xF0A7E8
#define pinstCVoteResultsWnd_x                                     0xDA7414
#define pinstCVoteWnd_x                                            0xDA73DC
#define pinstCWebManager_x                                         0xF0A94C
#define pinstCZoneGuideWnd_x                                       0xDA6E84
#define pinstCZonePathWnd_x                                        0xDA6E9C

#define pinstEQSuiteTextureLoader_x                                0xC4EC28
#define pinstItemIconCache_x                                       0x1019588
#define pinstLootFiltersManager_x                                  0xC74DB0
#define pinstRewardSelectionWnd_x                                  0x101E618

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xBFFC0C
#define __CastRay_x                                                0x58C320
#define __CastRay2_x                                               0x58C370
#define __ConvertItemTags_x                                        0x5A6F50
#define __CrashHandler_x                                           0x83C160
#define __EQGetTime_x                                              0x8D88E0
#define __ExecuteCmd_x                                             0x584C70
#define __FixHeading_x                                             0x969520
#define __get_bearing_x                                            0x58BE60
#define __get_melee_range_x                                        0x58C560
#define __GetAnimationCache_x                                      0x6F9750
#define __GetGaugeValueFromEQ_x                                    0x7ED790
#define __GetLabelFromEQ_x                                         0x7EEF00
#define __GetXTargetType_x                                         0x96B060
#define __HeadingDiff_x                                            0x969590
#define __HelpPath_x                                               0xF07C9C
#define __LoadFrontEnd_x                                           0x691E80
#define __NewUIINI_x                                               0x7ED460
#define __pCrashHandler_x                                          0x103DA98
#define __ProcessGameEvents_x                                      0x5E93C0
#define __ProcessMouseEvent_x                                      0x5E8B80
#define __SaveColors_x                                             0x537450
#define __STMLToText_x                                             0x90C910
#define __ToggleKeyRingItem_x                                      0x4FA8F0
#define CrashDetected_x                                            0x693970
#define DrawNetStatus_x                                            0x615300
#define Expansion_HoT_x                                            0xE69C34
#define Teleport_Table_Size_x                                      0xE58C88
#define Teleport_Table_x                                           0xE590E0
#define Util__FastTime_x                                           0x8D84A0
#define wwsCrashReportCheckForUploader_x                           0x83CC60
#define wwsCrashReportPlatformLaunchUploader_x                     0x83F340
#define __SaveColors_x                                             0x537450

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48A870
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x493650
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x493430

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x53EB20
#define AltAdvManager__IsAbilityReady_x                            0x53DBE0
#define AltAdvManager__GetAAById_x                                 0x53DDE0
#define AltAdvManager__CanTrainAbility_x                           0x53DE50
#define AltAdvManager__CanSeeAbility_x                             0x53E080

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C5CA0
#define CharacterZoneClient__HasSkill_x                            0x4D0770
#define CharacterZoneClient__MakeMeVisible_x                       0x4D1E90
#define CharacterZoneClient__IsStackBlocked_x                      0x4BA0D0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B67A0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D45D0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D46B0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D4790
#define CharacterZoneClient__FindAffectSlot_x                      0x4BEBC0
#define CharacterZoneClient__BardCastBard_x                        0x4C1830
#define CharacterZoneClient__GetMaxEffects_x                       0x4B6870
#define CharacterZoneClient__GetEffect_x                           0x4B66E0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4BFBD0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4BFCA0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4BFCF0
#define CharacterZoneClient__CalcAffectChange_x                    0x4BFE40
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C0010

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6BC0A0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6C9A20

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5F7860
#define CButtonWnd__CButtonWnd_x                                   0x908D10

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6E81A0
#define CChatManager__InitContextMenu_x                            0x6E25F0
#define CChatManager__FreeChatWindow_x                             0x6E7130
#define CChatManager__GetLockedActiveChatWindow_x                  0x6EBA50
#define CChatManager__SetLockedActiveChatWindow_x                  0x6E7F40

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x91D530
#define CContextMenu__dCContextMenu_x                              0x91D760
#define CContextMenu__AddMenuItem_x                                0x91D770
#define CContextMenu__RemoveMenuItem_x                             0x91DA70
#define CContextMenu__RemoveAllMenuItems_x                         0x91DA90
#define CContextMenu__CheckMenuItem_x                              0x91DB10
#define CContextMenu__SetMenuItem_x                                0x91D9A0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x91E0A0
#define CContextMenuManager__RemoveMenu_x                          0x91E110
#define CContextMenuManager__PopupMenu_x                           0x91E1D0
#define CContextMenuManager__Flush_x                               0x91E040
#define CContextMenuManager__GetMenu_x                             0x495810

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8BAB10
#define CChatService__GetFriendName_x                              0x8BAB20

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6E8710
#define CChatWindow__Clear_x                                       0x6E9770
#define CChatWindow__WndNotification_x                             0x6E9CE0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x91A9D0
#define CComboWnd__Draw_x                                          0x919EE0
#define CComboWnd__GetCurChoice_x                                  0x91A810
#define CComboWnd__GetListRect_x                                   0x91A380
#define CComboWnd__GetTextRect_x                                   0x91AA30
#define CComboWnd__InsertChoice_x                                  0x91A510
#define CComboWnd__SetColors_x                                     0x91A4E0
#define CComboWnd__SetChoice_x                                     0x91A7E0
#define CComboWnd__GetItemCount_x                                  0x91A820
#define CComboWnd__GetCurChoiceText_x                              0x91A860

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6F1940
#define CContainerWnd__vftable_x                                   0xAC66E8
#define CContainerWnd__SetContainer_x                              0x6F2EB0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x537210
#define CDisplay__GetClickedActor_x                                0x52A260
#define CDisplay__GetUserDefinedColor_x                            0x522960
#define CDisplay__GetWorldFilePath_x                               0x52BCB0
#define CDisplay__is3dON_x                                         0x526F50
#define CDisplay__ReloadUI_x                                       0x5313D0
#define CDisplay__WriteTextHD2_x                                   0x526D30
#define CDisplay__TrueDistance_x                                   0x52D910
#define CDisplay__SetViewActor_x                                   0x529BB0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x93CED0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x921C00
#define CEditWnd__GetCharIndexPt_x                                 0x922AE0
#define CEditWnd__GetDisplayString_x                               0x922980
#define CEditWnd__GetHorzOffset_x                                  0x921240
#define CEditWnd__GetLineForPrintableChar_x                        0x923BD0
#define CEditWnd__GetSelStartPt_x                                  0x922D80
#define CEditWnd__GetSTMLSafeText_x                                0x9227A0
#define CEditWnd__PointFromPrintableChar_x                         0x923820
#define CEditWnd__SelectableCharFromPoint_x                        0x923980
#define CEditWnd__SetEditable_x                                    0x922E40

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5D7F50
#define CEverQuest__ClickedPlayer_x                                0x5CA210
#define CEverQuest__CreateTargetIndicator_x                        0x5E66A0
#define CEverQuest__DeleteTargetIndicator_x                        0x5E6730
#define CEverQuest__DoTellWindow_x                                 0x4E0930
#define CEverQuest__OutputTextToLog_x                              0x4E0B60
#define CEverQuest__DropHeldItemOnGround_x                         0x5BFAE0
#define CEverQuest__dsp_chat_x                                     0x4E0EF0
#define CEverQuest__trimName_x                                     0x5E2C60
#define CEverQuest__Emote_x                                        0x5D8760
#define CEverQuest__EnterZone_x                                    0x5D28D0
#define CEverQuest__GetBodyTypeDesc_x                              0x5DC500
#define CEverQuest__GetClassDesc_x                                 0x5DCB40
#define CEverQuest__GetClassThreeLetterCode_x                      0x5DD140
#define CEverQuest__GetDeityDesc_x                                 0x5E4FF0
#define CEverQuest__GetLangDesc_x                                  0x5DD300
#define CEverQuest__GetRaceDesc_x                                  0x5DCB20
#define CEverQuest__InterpretCmd_x                                 0x5E55C0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5C3CD0
#define CEverQuest__LMouseUp_x                                     0x5C2050
#define CEverQuest__RightClickedOnPlayer_x                         0x5C45B0
#define CEverQuest__RMouseUp_x                                     0x5C2FE0
#define CEverQuest__SetGameState_x                                 0x5BF870
#define CEverQuest__UPCNotificationFlush_x                         0x5E2B60
#define CEverQuest__IssuePetCommand_x                              0x5DE700
#define CEverQuest__ReportSuccessfulHit_x                          0x5D9400

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7037D0
#define CGaugeWnd__CalcLinesFillRect_x                             0x703830
#define CGaugeWnd__Draw_x                                          0x702EC0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ABDA0
#define CGuild__GetGuildName_x                                     0x4AADE0
#define CGuild__GetGuildIndex_x                                    0x4AB170

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x71EB50

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x72BA20
#define CInvSlotMgr__MoveItem_x                                    0x72A780
#define CInvSlotMgr__SelectSlot_x                                  0x72BAF0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x729030
#define CInvSlot__SliderComplete_x                                 0x726E50
#define CInvSlot__GetItemBase_x                                    0x7267E0
#define CInvSlot__UpdateItem_x                                     0x726950

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x72D440
#define CInvSlotWnd__CInvSlotWnd_x                                 0x72C710
#define CInvSlotWnd__HandleLButtonUp_x                             0x72CFC0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7E9990
#define CItemDisplayWnd__UpdateStrings_x                           0x73BF20
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x736090
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x736570
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x73C4B0
#define CItemDisplayWnd__AboutToShow_x                             0x73BB80
#define CItemDisplayWnd__WndNotification_x                         0x73D7A0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x821320

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x7417F0

// CLabel 
#define CLabel__Draw_x                                             0x747300

// CListWnd
#define CListWnd__CListWnd_x                                       0x8F3160
#define CListWnd__dCListWnd_x                                      0x8F3480
#define CListWnd__AddColumn_x                                      0x8F7770
#define CListWnd__AddColumn1_x                                     0x8F77C0
#define CListWnd__AddLine_x                                        0x8F7B50
#define CListWnd__AddString_x                                      0x8F7950
#define CListWnd__CalculateFirstVisibleLine_x                      0x8F7540
#define CListWnd__CalculateVSBRange_x                              0x8F7320
#define CListWnd__ClearSel_x                                       0x8F8330
#define CListWnd__ClearAllSel_x                                    0x8F8390
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8F8D60
#define CListWnd__Compare_x                                        0x8F6C60
#define CListWnd__Draw_x                                           0x8F3580
#define CListWnd__DrawColumnSeparators_x                           0x8F5D40
#define CListWnd__DrawHeader_x                                     0x8F61B0
#define CListWnd__DrawItem_x                                       0x8F65A0
#define CListWnd__DrawLine_x                                       0x8F5EB0
#define CListWnd__DrawSeparator_x                                  0x8F5DE0
#define CListWnd__EnableLine_x                                     0x8F5620
#define CListWnd__EnsureVisible_x                                  0x8F8CA0
#define CListWnd__ExtendSel_x                                      0x8F8260
#define CListWnd__GetColumnMinWidth_x                              0x8F5160
#define CListWnd__GetColumnWidth_x                                 0x8F50D0
#define CListWnd__GetCurSel_x                                      0x8F4A60
#define CListWnd__GetItemAtPoint_x                                 0x8F5890
#define CListWnd__GetItemAtPoint1_x                                0x8F5900
#define CListWnd__GetItemData_x                                    0x8F4AE0
#define CListWnd__GetItemHeight_x                                  0x8F4EA0
#define CListWnd__GetItemIcon_x                                    0x8F4C70
#define CListWnd__GetItemRect_x                                    0x8F5710
#define CListWnd__GetItemText_x                                    0x8F4B20
#define CListWnd__GetSelList_x                                     0x8F83E0
#define CListWnd__GetSeparatorRect_x                               0x8F5B40
#define CListWnd__InsertLine_x                                     0x8F7F40
#define CListWnd__RemoveLine_x                                     0x8F8090
#define CListWnd__SetColors_x                                      0x8F72F0
#define CListWnd__SetColumnJustification_x                         0x8F7020
#define CListWnd__SetColumnWidth_x                                 0x8F6F40
#define CListWnd__SetCurSel_x                                      0x8F81A0
#define CListWnd__SetItemColor_x                                   0x8F8960
#define CListWnd__SetItemData_x                                    0x8F8920
#define CListWnd__SetItemText_x                                    0x8F8560
#define CListWnd__ShiftColumnSeparator_x                           0x8F70E0
#define CListWnd__Sort_x                                           0x8F6DE0
#define CListWnd__ToggleSel_x                                      0x8F81D0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x75C750

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x77FA80
#define CMerchantWnd__RequestBuyItem_x                             0x780360
#define CMerchantWnd__RequestSellItem_x                            0x7808A0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7836E0
//did this get another arg?
#define CMerchantWnd__SelectBuySellSlot_x                          0x7800E0
#define CMerchantWnd__ActualSelect_x                               0x789250

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8886E0
#define CPacketScrambler__hton_x                                   0x8886D0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x911EF0
#define CSidlManager__FindScreenPieceTemplate_x                    0x912300
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9120F0
#define CSidlManager__CreateLabel_x                                0x7E0DF0
#define CSidlManager__CreateXWndFromTemplate_x                     0x9153D0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x9155B0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x90EA60
#define CSidlScreenWnd__CalculateVSBRange_x                        0x90E960
#define CSidlScreenWnd__ConvertToRes_x                             0x9336C0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x90E3F0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x90E0E0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x90E1B0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x90E280
#define CSidlScreenWnd__DrawSidlPiece_x                            0x90EF00
#define CSidlScreenWnd__EnableIniStorage_x                         0x90F3D0
#define CSidlScreenWnd__GetSidlPiece_x                             0x90F0F0
#define CSidlScreenWnd__Init1_x                                    0x90DCF0
#define CSidlScreenWnd__LoadIniInfo_x                              0x90F420
#define CSidlScreenWnd__LoadIniListWnd_x                           0x90FF60
#define CSidlScreenWnd__LoadSidlScreen_x                           0x90D0F0
#define CSidlScreenWnd__StoreIniInfo_x                             0x90FAE0
#define CSidlScreenWnd__StoreIniVis_x                              0x90FE40
#define CSidlScreenWnd__WndNotification_x                          0x90EE10
#define CSidlScreenWnd__GetChildItem_x                             0x90F350
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8FEB30
#define CSidlScreenWnd__m_layoutCopy_x                             0x16975C8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x65B7F0
#define CSkillMgr__GetSkillCap_x                                   0x65B9D0
#define CSkillMgr__GetNameToken_x                                  0x65AF80

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x91EEA0
#define CSliderWnd__SetValue_x                                     0x91ED10
#define CSliderWnd__SetNumTicks_x                                  0x91ED70

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7E6C00

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x925A70
#define CStmlWnd__CalculateHSBRange_x                              0x926AE0
#define CStmlWnd__CalculateVSBRange_x                              0x926A50
#define CStmlWnd__CanBreakAtCharacter_x                            0x92AE20
#define CStmlWnd__FastForwardToEndOfTag_x                          0x92BA10
#define CStmlWnd__ForceParseNow_x                                  0x926010
#define CStmlWnd__GetNextTagPiece_x                                0x92AD80
#define CStmlWnd__GetSTMLText_x                                    0x4EECE0
#define CStmlWnd__GetVisibleText_x                                 0x926030
#define CStmlWnd__InitializeWindowVariables_x                      0x92B860
#define CStmlWnd__MakeStmlColorTag_x                               0x925200
#define CStmlWnd__MakeWndNotificationTag_x                         0x925270
#define CStmlWnd__SetSTMLText_x                                    0x9242D0
#define CStmlWnd__StripFirstSTMLLines_x                            0x92CB60
#define CStmlWnd__UpdateHistoryString_x                            0x92BC20

// CTabWnd 
#define CTabWnd__Draw_x                                            0x9301D0
#define CTabWnd__DrawCurrentPage_x                                 0x9307F0
#define CTabWnd__DrawTab_x                                         0x9305C0
#define CTabWnd__GetCurrentPage_x                                  0x92FA30
#define CTabWnd__GetPageInnerRect_x                                0x92FC70
#define CTabWnd__GetTabInnerRect_x                                 0x92FBB0
#define CTabWnd__GetTabRect_x                                      0x92FA60
#define CTabWnd__InsertPage_x                                      0x92FE60
#define CTabWnd__SetPage_x                                         0x92FCF0
#define CTabWnd__SetPageRect_x                                     0x930110
#define CTabWnd__UpdatePage_x                                      0x930480
#define CTabWnd__GetPageFromTabIndex_x                             0x930500
#define CTabWnd__GetCurrentTabIndex_x                              0x92FA20

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x741CE0
#define CPageWnd__SetTabText_x                                     0x93D2E0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A5890

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8FB9D0
#define CTextureFont__GetTextExtent_x                              0x8FBB90

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x68EC20
#define CHtmlComponentWnd__ValidateUri_x                           0x720540
#define CHtmlWnd__SetClientCallbacks_x                             0x5FCBD0
#define CHtmlWnd__AddObserver_x                                    0x5FCBF0
#define CHtmlWnd__RemoveObserver_x                                 0x5FCC50
#define Window__getProgress_x                                      0x839DD0
#define Window__getStatus_x                                        0x839DF0
#define Window__getURI_x                                           0x839E00

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x939810

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8E88D0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4AD000
#define CXStr__CXStr1_x                                            0x82A290
#define CXStr__CXStr3_x                                            0x8D4A10
#define CXStr__dCXStr_x                                            0x4722A0
#define CXStr__operator_equal_x                                    0x8D4C40
#define CXStr__operator_equal1_x                                   0x8D4C80
#define CXStr__operator_plus_equal1_x                              0x8D5710

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x91D150
#define CXWnd__BringToTop_x                                        0x902290
#define CXWnd__Center_x                                            0x901E10
#define CXWnd__ClrFocus_x                                          0x901C50
#define CXWnd__Destroy_x                                           0x901CF0
#define CXWnd__DoAllDrawing_x                                      0x8FE2C0
#define CXWnd__DrawChildren_x                                      0x8FE290
#define CXWnd__DrawColoredRect_x                                   0x8FE720
#define CXWnd__DrawTooltip_x                                       0x8FCE10
#define CXWnd__DrawTooltipAtPoint_x                                0x8FCED0
#define CXWnd__GetBorderFrame_x                                    0x8FE580
#define CXWnd__GetChildWndAt_x                                     0x902330
#define CXWnd__GetClientClipRect_x                                 0x900560
#define CXWnd__GetScreenClipRect_x                                 0x900600
#define CXWnd__GetScreenRect_x                                     0x9007B0
#define CXWnd__GetTooltipRect_x                                    0x8FE770
#define CXWnd__GetWindowTextA_x                                    0x496EA0
#define CXWnd__IsActive_x                                          0x9051F0
#define CXWnd__IsDescendantOf_x                                    0x9011B0
#define CXWnd__IsReallyVisible_x                                   0x9011E0
#define CXWnd__IsType_x                                            0x9029A0
#define CXWnd__Move_x                                              0x901250
#define CXWnd__Move1_x                                             0x901310
#define CXWnd__ProcessTransition_x                                 0x901DC0
#define CXWnd__Refade_x                                            0x9015E0
#define CXWnd__Resize_x                                            0x901870
#define CXWnd__Right_x                                             0x902050
#define CXWnd__SetFocus_x                                          0x901C10
#define CXWnd__SetFont_x                                           0x901C80
#define CXWnd__SetKeyTooltip_x                                     0x9027B0
#define CXWnd__SetMouseOver_x                                      0x8FF6F0
#define CXWnd__StartFade_x                                         0x901090
#define CXWnd__GetChildItem_x                                      0x9024A0
#define CXWnd__SetParent_x                                         0x900F50

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x934790

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x905230
#define CXWndManager__DrawWindows_x                                0x905250
#define CXWndManager__GetKeyboardFlags_x                           0x9079D0
#define CXWndManager__HandleKeyboardMsg_x                          0x9075D0
#define CXWndManager__RemoveWnd_x                                  0x907C20
#define CXWndManager__RemovePendingDeletionWnd_x                   0x908170

// CDBStr
#define CDBStr__GetString_x                                        0x521900

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B7750
#define EQ_Character__Cur_HP_x                                     0x4CD850
#define EQ_Character__Cur_Mana_x                                   0x4D4C90
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BA6C0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AEA90
#define EQ_Character__GetFocusRangeModifier_x                      0x4AEBE0
#define EQ_Character__GetHPRegen_x                                 0x4DA280
#define EQ_Character__GetEnduranceRegen_x                          0x4DA890
#define EQ_Character__GetManaRegen_x                               0x4DACD0
#define EQ_Character__Max_Endurance_x                              0x622750
#define EQ_Character__Max_HP_x                                     0x4CD680
#define EQ_Character__Max_Mana_x                                   0x6225D0
#define EQ_Character__doCombatAbility_x                            0x6248A0
#define EQ_Character__UseSkill_x                                   0x4DCAD0
#define EQ_Character__GetConLevel_x                                0x61BFD0
#define EQ_Character__IsExpansionFlag_x                            0x583620
#define EQ_Character__TotalEffect_x                                0x4C0DB0
#define EQ_Character__GetPCSpellAffect_x                           0x4BB2B0
#define EQ_Character__SpellDuration_x                              0x4BADE0
#define EQ_Character__FindItemByRecord_x                           0x4D2E00
#define EQ_Character__GetAdjustedSkill_x                           0x4D0530
#define EQ_Character__GetBaseSkill_x                               0x4D14D0
#define EQ_Character__CanUseItem_x                                 0x4D4FA0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8A7690

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x6385F0

//PcClient
#define PcClient__PcClient_x                                       0x6198A0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B5520
#define CCharacterListWnd__EnterWorld_x                            0x4B4F60
#define CCharacterListWnd__Quit_x                                  0x4B4C70
#define CCharacterListWnd__UpdateList_x                            0x4B50F0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x5FDDF0
#define EQ_Item__CreateItemTagString_x                             0x882A80
#define EQ_Item__IsStackable_x                                     0x886BD0
#define EQ_Item__GetImageNum_x                                     0x884250
#define EQ_Item__CreateItemClient_x                                0x5FCFD0
#define EQ_Item__GetItemValue_x                                    0x8852F0
#define EQ_Item__ValueSellMerchant_x                               0x888280
#define EQ_Item__IsKeyRingItem_x                                   0x886590
#define EQ_Item__CanGoInBag_x                                      0x5FDF10
#define EQ_Item__GetMaxItemCount_x                                 0x8853F0
#define EQ_Item__GetHeldItem_x                                     0x884120
#define EQ_Item__GetAugmentFitBySlot_x                             0x8825D0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x53F800
#define EQ_LoadingS__Array_x                                       0xBD7298

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x623050
#define EQ_PC__GetAlternateAbilityId_x                             0x8912D0
#define EQ_PC__GetCombatAbility_x                                  0x891940
#define EQ_PC__GetCombatAbilityTimer_x                             0x8919B0
#define EQ_PC__GetItemRecastTimer_x                                0x624E20
#define EQ_PC__HasLoreItem_x                                       0x61C790
#define EQ_PC__AlertInventoryChanged_x                             0x61BAB0
#define EQ_PC__GetPcZoneClient_x                                   0x646D60
#define EQ_PC__RemoveMyAffect_x                                    0x627F60
#define EQ_PC__GetKeyRingItems_x                                   0x892250
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x891FD0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x892540

// EQItemList 
#define EQItemList__EQItemList_x                                   0x589880
#define EQItemList__add_object_x                                   0x5B52D0
#define EQItemList__add_item_x                                     0x589E90
#define EQItemList__delete_item_x                                  0x589EE0
#define EQItemList__FreeItemList_x                                 0x589DE0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x51EE00

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x639E70
#define EQPlayer__dEQPlayer_x                                      0x62D560
#define EQPlayer__DoAttack_x                                       0x641A70
#define EQPlayer__EQPlayer_x                                       0x62DC10
#define EQPlayer__SetNameSpriteState_x                             0x631EE0
#define EQPlayer__SetNameSpriteTint_x                              0x632D70
#define PlayerBase__HasProperty_j_x                                0x9678F0
#define EQPlayer__IsTargetable_x                                   0x967D90
#define EQPlayer__CanSee_x                                         0x967BF0
#define EQPlayer__CanSee1_x                                        0x967CC0
#define PlayerBase__GetVisibilityLineSegment_x                     0x9679B0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x644830
#define PlayerZoneClient__GetLevel_x                               0x646DA0
#define PlayerZoneClient__IsValidTeleport_x                        0x5B6420
#define PlayerZoneClient__LegalPlayerRace_x                        0x538FF0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x63CB50
#define EQPlayerManager__GetSpawnByName_x                          0x63CB70
#define EQPlayerManager__GetPlayerFromPartialName_x                0x63CC00

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x601830
#define KeypressHandler__AttachKeyToEqCommand_x                    0x601870
#define KeypressHandler__ClearCommandStateArray_x                  0x602C60
#define KeypressHandler__HandleKeyDown_x                           0x602C80
#define KeypressHandler__HandleKeyUp_x                             0x602D20
#define KeypressHandler__SaveKeymapping_x                          0x603100

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7585E0
#define MapViewMap__SaveEx_x                                       0x75B980
#define MapViewMap__SetZoom_x                                      0x760060

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8A5580

// StringTable 
#define StringTable__getString_x                                   0x8A0540

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x627BD0
#define PcZoneClient__RemovePetEffect_x                            0x628200
#define PcZoneClient__HasAlternateAbility_x                        0x622410
#define PcZoneClient__GetCurrentMod_x                              0x4DFA20
#define PcZoneClient__GetModCap_x                                  0x4DF920
#define PcZoneClient__CanEquipItem_x                               0x6229E0
#define PcZoneClient__GetItemByID_x                                0x6252A0
#define PcZoneClient__GetItemByItemClass_x                         0x625330
#define PcZoneClient__RemoveBuffEffect_x                           0x628220

//Doors
#define EQSwitch__UseSwitch_x                                      0x5BAFF0

//IconCache
#define IconCache__GetIcon_x                                       0x6F8FE0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6F0AE0
#define CContainerMgr__CloseContainer_x                            0x6F0DB0
#define CContainerMgr__OpenExperimentContainer_x                   0x6F1830

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7B35F0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5F6040

//CLootWnd
#define CLootWnd__LootAll_x                                        0x74EAC0
#define CLootWnd__RequestLootSlot_x                                0x74DE70

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x557D80
#define EQ_Spell__SpellAffects_x                                   0x5581F0
#define EQ_Spell__SpellAffectBase_x                                0x557FB0
#define EQ_Spell__IsStackable_x                                    0x4C55C0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C5440
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B2B50
#define EQ_Spell__IsSPAStacking_x                                  0x558E30
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x558540
#define EQ_Spell__IsNoRemove_x                                     0x4C55A0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x558E40
#define __IsResEffectSpell_x                                       0x4C4900

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4A9A70

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8AFDE0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7F8CB0
#define CTargetWnd__WndNotification_x                              0x7F8540
#define CTargetWnd__RefreshTargetBuffs_x                           0x7F8810
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x7F7690

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7FD390

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5532D0
#define EqSoundManager__PlayScriptMp3_x                            0x553430
#define EqSoundManager__SoundAssistPlay_x                          0x65F320
#define EqSoundManager__WaveInstancePlay_x                         0x65E7D0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x510810

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x920880

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x5473D0
#define CAltAbilityData__GetMercMaxRank_x                          0x547370
#define CAltAbilityData__GetMaxRank_x                              0x53CCD0

//CTargetRing
#define CTargetRing__Cast_x                                        0x5F4150

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C5420
#define CharacterBase__CreateItemGlobalIndex_x                     0x4F6DF0
#define CharacterBase__CreateItemIndex_x                           0x5FC1E0
#define CharacterBase__GetItemPossession_x                         0x4B2A00
#define CharacterBase__GetItemByGlobalIndex_x                      0x8B8600
#define CharacterBase__GetEffectId_x                               0x4C53D0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6D9080
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6D98A0

//messages
#define msg_spell_worn_off_x                                       0x57BF90
#define msg_new_text_x                                             0x571230
#define __msgTokenTextParam_x                                      0x57E5E0
#define msgTokenText_x                                             0x57E830

//SpellManager
#define SpellManager__vftable_x                                    0xAA1818
#define SpellManager__SpellManager_x                               0x662610
#define Spellmanager__LoadTextSpells_x                             0x662990
#define SpellManager__GetSpellByGroupAndRank_x                     0x6627E0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x96B950

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4F74A0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x581D30
#define ItemGlobalIndex__IsEquippedLocation_x                      0x615160
#define ItemGlobalIndex__IsValidIndex_x                            0x4F7500

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8B07C0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8B0A40

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x747650

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6F5240
#define CCursorAttachment__Deactivate_x                            0x6F6210

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x932780
#define CEQSuiteTextureLoader__GetTexture_x                        0x932440

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4F44A0

//IString
#define IString__Append_x                                          0x4E8D20

//Camera
#define CDisplay__cameraType_x                                     0xDA6C6C
#define EverQuest__Cameras_x                                       0xE69F4C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x4FCB70
#define LootFiltersManager__GetItemFilterData_x                    0x4FC460
#define LootFiltersManager__RemoveItemLootFilter_x                 0x4FC490
#define LootFiltersManager__SetItemLootFilter_x                    0x4FC6B0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7A1570

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x971610
#define CResolutionHandler__GetWindowedStyle_x                     0x65A480

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6ED8A0

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
